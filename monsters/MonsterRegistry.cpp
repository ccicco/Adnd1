// ============================================================================
// Adnd1 — monsters/MonsterRegistry.cpp
// Lua 5.4 C API loading of monster files.
// ============================================================================

#include "MonsterRegistry.h"

#include <lua.hpp>

#include <cctype>
#include <cstdio>
#include <cstring>

namespace monsters {

const char* specialAttackTypeName(SpecialAttackType t) {
    switch (t) {
        case SPECIAL_POISON:       return "poison";
        case SPECIAL_PARALYSIS:    return "paralysis";
        case SPECIAL_ENERGY_DRAIN: return "energy drain";
        case SPECIAL_BREATH_WEAPON:return "breath weapon";
        default:                   return "none";
    }
}

// ----------------------------------------------------------------------------
// Lua helpers
// ----------------------------------------------------------------------------

namespace {

bool luaHasValue(lua_State* L, const char* key) {
    lua_getfield(L, -1, key);
    bool has = !lua_isnil(L, -1);
    lua_pop(L, 1);
    return has;
}

int luaGetInt(lua_State* L, const char* key, int def) {
    lua_getfield(L, -1, key);
    int v = def;
    if (lua_isnumber(L, -1)) v = (int)lua_tointeger(L, -1);
    lua_pop(L, 1);
    return v;
}

float luaGetNum(lua_State* L, const char* key, float def) {
    lua_getfield(L, -1, key);
    float v = def;
    if (lua_isnumber(L, -1)) v = (float)lua_tonumber(L, -1);
    lua_pop(L, 1);
    return v;
}

bool luaGetBool(lua_State* L, const char* key, bool def) {
    lua_getfield(L, -1, key);
    bool v = def;
    if (lua_isboolean(L, -1)) v = lua_toboolean(L, -1) != 0;
    lua_pop(L, 1);
    return v;
}

std::string luaGetStr(lua_State* L, const char* key, const char* def) {
    lua_getfield(L, -1, key);
    std::string v = def;
    if (lua_isstring(L, -1)) v = lua_tostring(L, -1);
    lua_pop(L, 1);
    return v;
}

SpecialAttackType parseSpecialType(const std::string& s) {
    if (s == "poison")        return SPECIAL_POISON;
    if (s == "paralysis")     return SPECIAL_PARALYSIS;
    if (s == "energy_drain")  return SPECIAL_ENERGY_DRAIN;
    if (s == "breath_weapon") return SPECIAL_BREATH_WEAPON;
    return SPECIAL_NONE;
}

std::string trim(const std::string& s) {
    size_t start = 0;
    while (start < s.size() &&
           std::isspace((unsigned char)s[start])) ++start;
    size_t end = s.size();
    while (end > start &&
           std::isspace((unsigned char)s[end - 1])) --end;
    return s.substr(start, end - start);
}

bool parseImportedMagicResist(lua_State* L, int& value, std::string& error) {
    lua_getfield(L, -1, "magicResistance");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 1);
        value = 0;
        return true;
    }
    if (lua_isnumber(L, -1)) {
        value = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);
        return true;
    }
    if (!lua_isstring(L, -1)) {
        error = "imported runtime field 'magicResistance' must be a percent string or number";
        lua_pop(L, 1);
        return false;
    }
    std::string text = trim(lua_tostring(L, -1));
    lua_pop(L, 1);
    if (text.empty() || text == "Standard" || text == "Nil") {
        value = 0;
        return true;
    }
    int percent = 0;
    if (std::sscanf(text.c_str(), "%d%%", &percent) == 1) {
        value = percent;
        return true;
    }
    error = "imported runtime field 'magicResistance' must look like '90%' or 'Standard'";
    return false;
}

bool parseFlatDamageRaw(const std::string& raw, int& damage) {
    std::string text = trim(raw);
    if (text.empty()) return false;

    size_t pos = 0;
    while (pos < text.size() &&
           std::isdigit((unsigned char)text[pos])) ++pos;
    if (pos == 0) return false;

    int parsed = std::atoi(text.substr(0, pos).c_str());
    std::string tail = trim(text.substr(pos));
    for (char& ch : tail)
        ch = (char)std::tolower((unsigned char)ch);

    if (tail.empty() || tail == "each") {
        damage = parsed;
        return true;
    }
    return false;
}

bool parseImportedDamage(lua_State* L, MonsterDef& def, std::string& error) {
    lua_getfield(L, -1, "damage");
    if (lua_isnil(L, -1)) {
        error = "imported runtime field 'damage' is required";
        lua_pop(L, 1);
        return false;
    }
    if (!lua_istable(L, -1)) {
        error = "imported runtime field 'damage' must be a table";
        lua_pop(L, 1);
        return false;
    }

    size_t len = lua_rawlen(L, -1);
    if (len == 0) {
        error = "imported runtime field 'damage' must not be empty";
        lua_pop(L, 1);
        return false;
    }

    bool haveProfile = false;
    int resolvedMin = 0;
    int resolvedMax = 0;
    std::string resolvedRaw;

    for (size_t i = 1; i <= len; ++i) {
        lua_geti(L, -1, (lua_Integer)i);
        if (!lua_istable(L, -1)) {
            error = "imported runtime field 'damage[" +
                    std::to_string(i) + "]' must be a table";
            lua_pop(L, 2);
            return false;
        }

        int entryMin = 0;
        int entryMax = 0;
        std::string entryRaw;

        lua_getfield(L, -1, "raw");
        if (lua_isstring(L, -1))
            entryRaw = lua_tostring(L, -1);
        lua_pop(L, 1);

        if (!entryRaw.empty()) {
            int flatDamage = 0;
            if (!parseFlatDamageRaw(entryRaw, flatDamage)) {
                error = "imported runtime field 'damage[" +
                        std::to_string(i) + "].raw' (" + entryRaw +
                        ") cannot be mapped to the current runtime damage model";
                lua_pop(L, 2);
                return false;
            }
            entryMin = flatDamage;
            entryMax = flatDamage;
        } else {
            lua_getfield(L, -1, "min");
            bool hasMin = lua_isnumber(L, -1);
            if (hasMin) entryMin = (int)lua_tointeger(L, -1);
            lua_pop(L, 1);

            lua_getfield(L, -1, "max");
            bool hasMax = lua_isnumber(L, -1);
            if (hasMax) entryMax = (int)lua_tointeger(L, -1);
            lua_pop(L, 1);

            if (!hasMin || !hasMax) {
                error = "imported runtime field 'damage[" +
                        std::to_string(i) + "]' must provide numeric min/max or a raw string";
                lua_pop(L, 2);
                return false;
            }
            if (entryMin < 0 || entryMax < entryMin) {
                error = "imported runtime field 'damage[" +
                        std::to_string(i) + "]' has invalid min/max bounds";
                lua_pop(L, 2);
                return false;
            }
        }

        if (!haveProfile) {
            haveProfile = true;
            resolvedMin = entryMin;
            resolvedMax = entryMax;
            resolvedRaw = entryRaw;
        } else if (resolvedMin != entryMin || resolvedMax != entryMax ||
                   resolvedRaw != entryRaw) {
            error = "imported runtime field 'damage' has multiple attack profiles that cannot be represented by the current runtime model";
            lua_pop(L, 2);
            return false;
        }

        lua_pop(L, 1);
    }

    lua_pop(L, 1);

    def.damageMin = resolvedMin;
    def.damageMax = resolvedMax;
    def.damageRaw = resolvedRaw;
    if (resolvedMin == resolvedMax) {
        def.damageCount = 0;
        def.damageSides = 0;
        def.damageBonus = resolvedMin;
    } else if (resolvedMin == 1) {
        def.damageCount = 1;
        def.damageSides = resolvedMax;
        def.damageBonus = 0;
    } else {
        def.damageCount = 0;
        def.damageSides = 0;
        def.damageBonus = 0;
    }
    return true;
}

} // namespace

// ----------------------------------------------------------------------------
// Loading
// ----------------------------------------------------------------------------

bool MonsterRegistry::loadFile(const std::string& path,
                               const std::string& key) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);   // registry files may use basic math if desired

    if (luaL_dofile(L, path.c_str()) != LUA_OK) {
        char buf[512];
        snprintf(buf, sizeof buf, "%s: %s", key.c_str(),
                 lua_tostring(L, -1));
        m_errors.push_back(buf);
        lua_close(L);
        return false;
    }

    // the file must leave a table on the stack
    if (!lua_istable(L, -1)) {
        m_errors.push_back(key + ": file must return a table");
        lua_close(L);
        return false;
    }

    MonsterDef def;
    def.key = key;
    def.name = luaGetStr(L, "name", key.c_str());

    // Imported runtime aliases take precedence when the record opts
    // into the imported schema with hitDiceNum. Transitional/legacy
    // records that add other imported-looking fields continue to load
    // via the legacy hd/ac/attacks keys until they provide hitDiceNum.
    const bool importedRuntime = luaHasValue(L, "hitDiceNum");

    if (importedRuntime) {
        if (!luaHasValue(L, "hitDiceNum")) {
            m_errors.push_back(key + ": imported runtime field 'hitDiceNum' is required");
            lua_close(L);
            return false;
        }
        if (!luaHasValue(L, "hitDiceBonus")) {
            m_errors.push_back(key + ": imported runtime field 'hitDiceBonus' is required");
            lua_close(L);
            return false;
        }
        if (!luaHasValue(L, "armorClass")) {
            m_errors.push_back(key + ": imported runtime field 'armorClass' is required");
            lua_close(L);
            return false;
        }
        if (!luaHasValue(L, "numAttacks")) {
            m_errors.push_back(key + ": imported runtime field 'numAttacks' is required");
            lua_close(L);
            return false;
        }
        if (!luaHasValue(L, "xpValue")) {
            m_errors.push_back(key + ": imported runtime field 'xpValue' is required");
            lua_close(L);
            return false;
        }

        lua_getfield(L, -1, "hitDiceNum");
        if (!lua_isnumber(L, -1)) {
            m_errors.push_back(key + ": imported runtime field 'hitDiceNum' must be a number");
            lua_close(L);
            return false;
        }
        def.hitDice = (float)lua_tonumber(L, -1);
        lua_pop(L, 1);

        lua_getfield(L, -1, "hitDiceBonus");
        if (!lua_isnumber(L, -1)) {
            m_errors.push_back(key + ": imported runtime field 'hitDiceBonus' must be a number");
            lua_close(L);
            return false;
        }
        def.hitPointBonus = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);

        lua_getfield(L, -1, "armorClass");
        if (!lua_isnumber(L, -1)) {
            m_errors.push_back(key + ": imported runtime field 'armorClass' must be a numeric armor class");
            lua_close(L);
            return false;
        }
        def.armorClass = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);

        lua_getfield(L, -1, "numAttacks");
        if (!lua_isnumber(L, -1)) {
            m_errors.push_back(key + ": imported runtime field 'numAttacks' must be a number");
            lua_close(L);
            return false;
        }
        def.attacks = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);

        lua_getfield(L, -1, "xpValue");
        if (!lua_isnumber(L, -1)) {
            m_errors.push_back(key + ": imported runtime field 'xpValue' must be a number");
            lua_close(L);
            return false;
        }
        def.xpValue = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);

        std::string importedError;
        if (!parseImportedDamage(L, def, importedError)) {
            m_errors.push_back(key + ": " + importedError);
            lua_close(L);
            return false;
        }
        if (!parseImportedMagicResist(L, def.magicResist, importedError)) {
            m_errors.push_back(key + ": " + importedError);
            lua_close(L);
            return false;
        }
    } else {
        def.hitDice = luaGetNum(L, "hd", 1.0f);
        def.hitPointBonus = luaGetInt(L, "hpBonus", 0);
        def.armorClass = luaGetInt(L, "ac", 9);
        def.attacks = luaGetInt(L, "attacks", 1);
        def.damageCount = luaGetInt(L, "damageCount", 1);
        def.damageSides = luaGetInt(L, "damageSides", 6);
        def.damageBonus = 0;
        if (def.damageCount > 0 && def.damageSides > 0) {
            def.damageMin = def.damageCount;
            def.damageMax = def.damageCount * def.damageSides;
        }
        if (luaHasValue(L, "xpValue"))
            def.xpValue = luaGetInt(L, "xpValue", 10);
        else
            def.xpValue = luaGetInt(L, "xp", 10);
    }

    def.morale = luaGetInt(L, "morale", 12);
    if (!importedRuntime)
        def.magicResist = luaGetInt(L, "magicResist", 0);
    def.undead = luaGetBool(L, "undead", false);
    def.requiredPlus = luaGetInt(L, "requiredPlus", 0);
    def.levelTag = luaGetInt(L, "levelTag", 1);
    def.isLeader = luaGetBool(L, "isLeader", false);

    // specialAttacks = { { type="poison", name="...", save=0,
    //                      penalty=0, dice=0, sides=0, drain=1 }, ... }
    lua_getfield(L, -1, "specialAttacks");
    if (lua_istable(L, -1)) {
        size_t len = lua_rawlen(L, -1);
        for (size_t i = 1; i <= len; ++i) {
            lua_geti(L, -1, (lua_Integer)i);
            if (lua_istable(L, -1)) {
                SpecialAttack sp;
                sp.type = parseSpecialType(luaGetStr(L, "type", ""));
                sp.name = luaGetStr(L, "name", specialAttackTypeName(sp.type));
                sp.saveCategory = luaGetInt(L, "save", 0);
                sp.savePenalty = luaGetInt(L, "penalty", 0);
                sp.diceCount = luaGetInt(L, "dice", 0);
                sp.diceSides = luaGetInt(L, "sides", 0);
                sp.drainLevels = luaGetInt(L, "drain", 1);
                if (sp.type != SPECIAL_NONE)
                    def.specials.push_back(sp);
            }
            lua_pop(L, 1);   // the entry
        }
    }
    lua_pop(L, 1);   // specialAttacks

    lua_close(L);
    m_defs[key] = def;
    return true;
}

// ----------------------------------------------------------------------------
// Directory load: platform-scoped. On Win32 uses FindFirstFileA;
// otherwise returns -1 (the test harness writes temp files via a
// directory the game controls — see test).
// ----------------------------------------------------------------------------

#ifdef _WIN32
#include <windows.h>

int MonsterRegistry::loadDirectory(const std::string& dirPath) {
    std::string pattern = dirPath + "\\*.lua";
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern.c_str(), &fd);
    if (h == INVALID_HANDLE_VALUE) return -1;
    int count = 0;
    do {
        std::string fname = fd.cFileName;
        std::string key = fname.substr(0, fname.size() - 4);
        if (loadFile(dirPath + "\\" + fname, key)) ++count;
    } while (FindNextFileA(h, &fd));
    FindClose(h);
    return count;
}

#else   // POSIX fallback for tests/dev on non-Windows
#include <dirent.h>

int MonsterRegistry::loadDirectory(const std::string& dirPath) {
    DIR* d = opendir(dirPath.c_str());
    if (!d) return -1;
    int count = 0;
    struct dirent* e;
    while ((e = readdir(d)) != nullptr) {
        std::string fname = e->d_name;
        if (fname.size() < 5 ||
            fname.compare(fname.size() - 4, 4, ".lua") != 0)
            continue;
        std::string key = fname.substr(0, fname.size() - 4);
        if (loadFile(dirPath + "/" + fname, key)) ++count;
    }
    closedir(d);
    return count;
}
#endif

const MonsterDef* MonsterRegistry::find(const std::string& key) const {
    auto it = m_defs.find(key);
    return it == m_defs.end() ? nullptr : &it->second;
}

ai::Actor MonsterRegistry::toActor(const std::string& key,
                                   rules::Dice& dice, int hp) const {
    ai::Actor a;
    const MonsterDef* def = find(key);
    if (!def) {
        a.name = "Unknown (" + key + ")";
        a.hitDice = 1;
        a.hp = a.maxHp = 1;
        return a;
    }
    a.name = def->name;
    a.isCharacter = false;
    a.team = 1;
    a.hitDice = def->hitDice;
    a.monsterArmorClass = def->armorClass;
    a.hasMonsterArmorClass = true;
    a.monsterAttacks = def->attacks;
    a.monsterDamageCount = def->damageCount;
    a.monsterDamageSides = def->damageSides;
    a.monsterDamageBonus = def->damageBonus;
    a.monsterDamageMin = def->damageMin;
    a.monsterDamageMax = def->damageMax;
    a.monsterDamageRaw = def->damageRaw;
    a.magicResistPct = def->magicResist;
    a.undead = def->undead;
    a.requiredPlusToHit = def->requiredPlus;
    a.morale = def->morale;
    a.isLeader = def->isLeader;
    for (const SpecialAttack& sp : def->specials) {
        ai::ActorSpecial actorSp;
        actorSp.type = (int)sp.type;
        actorSp.name = sp.name;
        actorSp.saveCategory = sp.saveCategory;
        actorSp.savePenalty = sp.savePenalty;
        actorSp.diceCount = sp.diceCount;
        actorSp.diceSides = sp.diceSides;
        actorSp.drainLevels = sp.drainLevels;
        a.specials.push_back(actorSp);
    }

    // hp: roll hit dice + bonus, or use the provided value
    if (hp < 0) {
        int full = (int)def->hitDice;
        float frac = def->hitDice - full;
        int rolled = (int)dice.roll((uint32_t)(full > 0 ? full : 1), 8,
                                    def->hitPointBonus);
        if (frac > 0) rolled += (int)(frac * 8);   // +1 per 1/2 HD approx
        hp = rolled < 1 ? 1 : rolled;
    }
    a.hp = a.maxHp = hp;
    return a;
}

std::vector<std::string> MonsterRegistry::keysForLevel(
    int dungeonLevel) const {
    // monsters tagged at or one below the dungeon level (an
    // Appendix C-shaped filter; exact table wiring later)
    std::vector<std::string> out;
    for (const auto& kv : m_defs)
        if (kv.second.levelTag <= dungeonLevel + 1)
            out.push_back(kv.first);
    return out;
}

} // namespace monsters