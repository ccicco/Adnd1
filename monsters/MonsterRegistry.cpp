// ============================================================================
// Adnd1 — monsters/MonsterRegistry.cpp
// Lua 5.4 C API loading of monster files.
// ============================================================================

#include "MonsterRegistry.h"

#include <lua.hpp>

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
    def.hitDice = luaGetNum(L, "hd", 1.0f);
    def.hitPointBonus = luaGetInt(L, "hpBonus", 0);
    def.armorClass = luaGetInt(L, "ac", 9);
    def.attacks = luaGetInt(L, "attacks", 1);
    def.damageCount = luaGetInt(L, "damageCount", 1);
    def.damageSides = luaGetInt(L, "damageSides", 6);
    def.morale = luaGetInt(L, "morale", 12);
    def.magicResist = luaGetInt(L, "magicResist", 0);
    def.undead = luaGetBool(L, "undead", false);
    def.requiredPlus = luaGetInt(L, "requiredPlus", 0);
    def.levelTag = luaGetInt(L, "levelTag", 1);
    def.xpValue = luaGetInt(L, "xp", 10);
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
    a.monsterAttacks = def->attacks;
    a.monsterDamageCount = def->damageCount;
    a.monsterDamageSides = def->damageSides;
    a.magicResistPct = def->magicResist;
    a.undead = def->undead;
    a.requiredPlusToHit = def->requiredPlus;
    a.morale = def->morale;
    a.isLeader = def->isLeader;

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