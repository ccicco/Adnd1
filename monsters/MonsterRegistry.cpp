// ============================================================================
// Adnd1 — monsters/MonsterRegistry.cpp
// Lua 5.4 C API loading of monster files.
//
// R49: field mapping remapped to the mm2lua.py schema (v2) — see the
// header. All coercers are defensive: the Lua files carry numbers,
// strings, and mixed tables (armorClass = 2 or {2, "underside 4"}),
// and nothing may crash or silently NaN on any of them.
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

bool hasKey(lua_State* L, const char* key) {
    // top of stack: the monster table
    lua_getfield(L, -1, key);
    bool present = !lua_isnoneornil(L, -1);
    lua_pop(L, 1);
    return present;
}

// first integer embedded in a string ("25%" -> 25, "Overall 2" -> 2)
int firstIntIn(const std::string& s, int def) {
    for (size_t i = 0; i < s.size(); ++i) {
        if (isdigit((unsigned char)s[i])) {
            int v = 0;
            size_t j = i;
            while (j < s.size() && isdigit((unsigned char)s[j])) {
                v = v * 10 + (s[j] - '0');
                ++j;
            }
            return v;
        }
    }
    return def;
}

// ----------------------------------------------------------------------------
// armorClass: number | table (first numeric entry) | string
// Lua: armorClass = 2   /   { 2, "underside 4" }   /   "See below"
// ----------------------------------------------------------------------------
int luaGetArmorClass(lua_State* L, int def) {
    lua_getfield(L, -1, "armorClass");
    int v = def;
    if (lua_isnumber(L, -1)) {
        v = (int)lua_tointeger(L, -1);
    } else if (lua_istable(L, -1)) {
        // mixed list: take the first numeric entry, or the first
        // integer embedded in a string entry ("Overall 2" -> 2)
        size_t len = lua_rawlen(L, -1);
        for (size_t i = 1; i <= len && v == def; ++i) {
            lua_geti(L, -1, (lua_Integer)i);
            if (lua_isnumber(L, -1)) v = (int)lua_tointeger(L, -1);
            else if (lua_isstring(L, -1))
                v = firstIntIn(lua_tostring(L, -1), def);
            lua_pop(L, 1);
        }
    } else if (lua_isstring(L, -1)) {
        v = firstIntIn(lua_tostring(L, -1), def);
    }
    lua_pop(L, 1);
    return v;
}

// ----------------------------------------------------------------------------
// numAttacks: number | string.
//   "1 and 1" -> 2 (bite + tail, purple worm)      "2-4" -> 4 (use max)
//   "1-2 or 2-5" style text -> firstIntIn as floor of 1.
// ----------------------------------------------------------------------------
int luaGetNumAttacks(lua_State* L, int def) {
    lua_getfield(L, -1, "numAttacks");
    int v = def;
    if (lua_isnumber(L, -1)) {
        v = (int)lua_tointeger(L, -1);
    } else if (lua_isstring(L, -1)) {
        std::string s = lua_tostring(L, -1);
        // collect all integers
        std::vector<int> nums;
        for (size_t i = 0; i < s.size(); ++i) {
            if (isdigit((unsigned char)s[i])) {
                int n = 0;
                size_t j = i;
                while (j < s.size() && isdigit((unsigned char)s[j])) {
                    n = n * 10 + (s[j] - '0');
                    ++j;
                }
                nums.push_back(n);
                i = j - 1;
            }
        }
        if (!nums.empty()) {
            if (s.find("and") != std::string::npos) {
                // "1 and 1" -> sum
                v = 0;
                for (int n : nums) v += n;
            } else {
                // "2-4" / "2-8 by weapon" -> max
                v = nums[0];
                for (int n : nums) if (n > v) v = n;
            }
        }
    }
    if (v < 1) v = 1;
    if (v > 10) v = 10;   // sanity clamp
    lua_pop(L, 1);
    return v;
}

// ----------------------------------------------------------------------------
// damage: array of { min = a, max = b } (or { raw = "..." } entries).
// Stores the routines; the primary (largest max) is approximated as
// one die of (max-min+1) sides for Actor's single dice pair.
// ----------------------------------------------------------------------------
void luaGetDamage(lua_State* L, MonsterDef& def) {
    lua_getfield(L, -1, "damage");
    if (lua_istable(L, -1)) {
        size_t len = lua_rawlen(L, -1);
        for (size_t i = 1; i <= len; ++i) {
            lua_geti(L, -1, (lua_Integer)i);
            if (lua_istable(L, -1)) {
                DamageRoutine r;
                lua_getfield(L, -1, "min");
                if (lua_isnumber(L, -1)) r.min = (int)lua_tointeger(L, -1);
                lua_pop(L, 1);
                lua_getfield(L, -1, "max");
                if (lua_isnumber(L, -1)) r.max = (int)lua_tointeger(L, -1);
                lua_pop(L, 1);
                if (r.max >= r.min && r.max > 0)
                    def.damageRoutines.push_back(r);
            }
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);

    if (!def.damageRoutines.empty()) {
        // primary routine: largest max damage
        const DamageRoutine* best = &def.damageRoutines[0];
        for (const auto& r : def.damageRoutines)
            if (r.max > best->max) best = &r;
        def.damageCount = 1;
        def.damageSides = best->max - best->min + 1;
        if (def.damageSides < 1) def.damageSides = 1;
        if (def.damageSides > 100) def.damageSides = 100;  // sanity
    }
    // else: keep the 1d6 default (Nil-damage monsters: shrieker etc.)
}

// ----------------------------------------------------------------------------
// magicResistance: number | "25%" | "Standard" | "Nil"
// ----------------------------------------------------------------------------
int luaGetMagicResist(lua_State* L, int def) {
    lua_getfield(L, -1, "magicResistance");
    int v = def;
    if (lua_isnumber(L, -1)) {
        v = (int)lua_tointeger(L, -1);
    } else if (lua_isstring(L, -1)) {
        std::string s = lua_tostring(L, -1);
        // "25%" -> 25; "Standard"/"Nil"/"See below" -> 0 (no innate %)
        v = firstIntIn(s, 0);
    }
    lua_pop(L, 1);
    return v;
}

// ----------------------------------------------------------------------------
// special attacks from the prose field (Lua specialAttacks string).
// Keyword-matched; the R18 typed table form is still honored first.
// ----------------------------------------------------------------------------
SpecialAttackType parseSpecialType(const std::string& s) {
    if (s == "poison")        return SPECIAL_POISON;
    if (s == "paralysis")     return SPECIAL_PARALYSIS;
    if (s == "energy_drain")  return SPECIAL_ENERGY_DRAIN;
    if (s == "breath_weapon") return SPECIAL_BREATH_WEAPON;
    return SPECIAL_NONE;
}

// lowercase contains-helper
bool containsCI(const std::string& hay, const char* needle) {
    std::string h;
    h.reserve(hay.size());
    for (char c : hay) h += (char)tolower((unsigned char)c);
    return h.find(needle) != std::string::npos;
}

void deriveSpecials(MonsterDef& def) {
    // (1) typed table form (R18 legacy / hand-authored files)
    // handled in loadFile; here we derive from the text fields.

    // (2) text keyword derivation
    const std::string& atk = def.specialAttacksText;
    const std::string& dfs = def.specialDefensesText;

    bool haveEnergy = false, havePoison = false,
         haveParalysis = false, haveBreath = false;
    for (const auto& sp : def.specials) {
        if (sp.type == SPECIAL_ENERGY_DRAIN)  haveEnergy = true;
        if (sp.type == SPECIAL_POISON)        havePoison = true;
        if (sp.type == SPECIAL_PARALYSIS)     haveParalysis = true;
        if (sp.type == SPECIAL_BREATH_WEAPON) haveBreath = true;
    }

    if (!haveEnergy && (containsCI(atk, "energy drain") ||
                        containsCI(atk, "drain"))) {
        SpecialAttack sp;
        sp.type = SPECIAL_ENERGY_DRAIN;
        sp.name = "energy drain";
        sp.drainLevels = 1;
        // "2 levels" per hit? (vampire-like) — parse "N level"
        int n = firstIntIn(atk, 1);
        if (atk.find("level") != std::string::npos && n >= 1 && n <= 4)
            sp.drainLevels = n;
        def.specials.push_back(sp);
    }
    if (!havePoison && (containsCI(atk, "poison") ||
                        containsCI(dfs, "poison"))) {
        SpecialAttack sp;
        sp.type = SPECIAL_POISON;
        sp.name = "poison";
        def.specials.push_back(sp);
    }
    if (!haveParalysis && (containsCI(atk, "paralys") ||
                           containsCI(atk, "paralyz"))) {
        SpecialAttack sp;
        sp.type = SPECIAL_PARALYSIS;
        sp.name = "paralysis";
        def.specials.push_back(sp);
    }
    if (!haveBreath && containsCI(atk, "breath")) {
        SpecialAttack sp;
        sp.type = SPECIAL_BREATH_WEAPON;
        sp.name = "breath weapon";
        // dice from the damage routines when they look like breath
        // (second routine for dragons: claws/claw/bite vs breath)
        if (def.damageRoutines.size() >= 2) {
            const DamageRoutine& r = def.damageRoutines[1];
            sp.diceCount = 2;
            sp.diceSides = r.max - r.min + 1;
        }
        def.specials.push_back(sp);
    }
}

// ----------------------------------------------------------------------------
// nested-table int reads: noAppearing = {min=..,max=..}, move = {rate=..}
// ----------------------------------------------------------------------------
int luaGetNestedInt(lua_State* L, const char* table, const char* field,
                    int def) {
    lua_getfield(L, -1, table);
    int v = def;
    if (lua_istable(L, -1)) {
        lua_getfield(L, -1, field);
        if (lua_isnumber(L, -1)) v = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);
    } else if (lua_isnumber(L, -1)) {
        v = (int)lua_tointeger(L, -1);   // tolerate a flat number
    }
    lua_pop(L, 1);
    return v;
}

// ----------------------------------------------------------------------------
// heuristics (explicit Lua fields override where they exist)
// ----------------------------------------------------------------------------
bool looksUndead(const std::string& name) {
    static const char* kw[] = {
        "skeleton", "zombie", "ghoul", "wight", "wraith", "mummy",
        "spectre", "specter", "vampire", "ghost", "lich", "shadow",
        "ghast", nullptr
    };
    for (int i = 0; kw[i]; ++i)
        if (containsCI(name, kw[i])) return true;
    return false;
}

int requiredPlusFromText(const std::string& s) {
    // "+2 or better" -> 2 ; "magic weapon(s)" -> 1
    if (s.find("+2") != std::string::npos) return 2;
    if (s.find("+3") != std::string::npos) return 3;
    if (containsCI(s, "magic weapon")) return 1;
    return 0;
}

int moraleFromIntelligence(const std::string& intel) {
    if (intel.empty()) return 12;
    if (containsCI(intel, "non-") || containsCI(intel, "nil") ||
        containsCI(intel, "none") || containsCI(intel, "semi"))
        return 10;   // mindless/semi: fight on, no cunning retreat
    if (containsCI(intel, "low") || containsCI(intel, "animal"))
        return 9;
    if (containsCI(intel, "average"))
        return 11;
    return 12;   // high/excellent/genius+: confident
}

int levelTagFromHd(float hd) {
    // crude Appendix C-ish banding: depth ~ HD/2
    if (hd <= 2.0f)  return 1;
    if (hd <= 4.0f)  return 2;
    if (hd <= 6.0f)  return 3;
    if (hd <= 9.0f)  return 4;
    if (hd <= 13.0f) return 5;
    return 6;
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

    // ---- hit dice (new schema; fall back to legacy hd/hpBonus) ----
    if (hasKey(L, "hitDiceNum") || hasKey(L, "hitDice")) {
        def.hitDiceNum   = luaGetInt(L, "hitDiceNum", 1);
        def.hitDiceBonus = luaGetInt(L, "hitDiceBonus", 0);
        def.hitDiceText  = luaGetStr(L, "hitDice", "1");
        def.avgHp        = luaGetInt(L, "avgHp", 0);
        if (def.hitDiceNum < 1 && def.avgHp > 0) {
            // flat-hp monster ("50 hp"): equivalent dice from avg hp
            float equiv = def.avgHp / 4.5f;
            def.hitDice = equiv;
        } else {
            def.hitDice = (float)def.hitDiceNum + def.hitDiceBonus / 4.0f;
        }
    } else {
        // legacy: hd / hpBonus
        def.hitDice = luaGetNum(L, "hd", 1.0f);
        def.hitDiceNum = (int)def.hitDice;
        def.hitDiceBonus = luaGetInt(L, "hpBonus", 0);
    }

    // ---- armor class (new: number|string|table; legacy: ac) ----
    if (hasKey(L, "armorClass"))
        def.armorClass = luaGetArmorClass(L, 9);
    else
        def.armorClass = luaGetInt(L, "ac", 9);

    // ---- attacks (new: numAttacks number|string; legacy: attacks) ----
    if (hasKey(L, "numAttacks"))
        def.attacks = luaGetNumAttacks(L, 1);
    else
        def.attacks = luaGetInt(L, "attacks", 1);

    // ---- damage (new: damage array; legacy: damageCount/damageSides) ----
    luaGetDamage(L, def);
    if (def.damageRoutines.empty()) {
        def.damageCount = luaGetInt(L, "damageCount", 1);
        def.damageSides = luaGetInt(L, "damageSides", 6);
    }

    // ---- magic resistance (new: string %; legacy: number) ----
    if (hasKey(L, "magicResistance"))
        def.magicResist = luaGetMagicResist(L, 0);
    else
        def.magicResist = luaGetInt(L, "magicResist", 0);

    // ---- XP (new: xp / xpPerHp / xpValue / xpSource; legacy: xp) ----
    def.xpBase   = luaGetInt(L, "xp", 0);
    def.xpPerHp  = luaGetInt(L, "xpPerHp", 0);
    def.xpSource = luaGetStr(L, "xpSource", "");
    if (hasKey(L, "xpValue")) {
        def.xpValue = luaGetInt(L, "xpValue", 10);
    } else if (def.xpBase > 0) {
        // legacy xp field carried the whole value
        def.xpValue = def.xpBase;
    } else {
        def.xpValue = 10;
    }
    // never award less than the base
    if (def.xpValue < def.xpBase) def.xpValue = def.xpBase;

    // ---- descriptive fields (R49) ----
    def.frequency            = luaGetStr(L, "frequency", "");
    def.noAppearingMin       = luaGetNestedInt(L, "noAppearing", "min", 0);
    def.noAppearingMax       = luaGetNestedInt(L, "noAppearing", "max", 0);
    def.lairPct              = luaGetInt(L, "lairPct", 0);
    def.moveRate             = luaGetNestedInt(L, "move", "rate", 0);
    def.size                 = luaGetStr(L, "size", "");
    def.intelligence         = luaGetStr(L, "intelligence", "");
    def.alignment            = luaGetStr(L, "alignment", "");
    def.specialAttacksText   = luaGetStr(L, "specialAttacks", "");
    def.specialDefensesText  = luaGetStr(L, "specialDefenses", "");
    def.text                 = luaGetStr(L, "text", "");

    // ---- specialAttacks: typed table form first (R18) ----
    lua_getfield(L, -1, "specialAttacks");
    if (lua_istable(L, -1) && lua_rawlen(L, -1) > 0) {
        // array of typed sub-tables { type="poison", ... }
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
        lua_pop(L, 1);   // specialAttacks
    } else {
        lua_pop(L, 1);
        // text form (mm2lua schema): derive from the prose fields
        deriveSpecials(def);
    }

    // ---- heuristics (fields the Lua schema does not carry) ----
    def.morale = luaGetInt(L, "morale",
                           moraleFromIntelligence(def.intelligence));
    def.undead = luaGetBool(L, "undead", looksUndead(def.name));
    def.requiredPlus = luaGetInt(L, "requiredPlus",
                                 requiredPlusFromText(def.specialDefensesText));
    def.levelTag = luaGetInt(L, "levelTag",
                             levelTagFromHd(def.hitDice));
    def.isLeader = luaGetBool(L, "isLeader", false);

    lua_close(L);
    m_defs[key] = def;
    return true;
}

// ----------------------------------------------------------------------------
// Directory load: platform-scoped. On Win32 uses FindFirstFileA;
// otherwise POSIX readdir (tests/dev on non-Windows).
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
                                   rules::Dice& dice, int hp,
                                   int hdOverride, int hpPerDie) const {
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
    if (hdOverride > 0)    // R51: effective HD (attack matrices follow)
        a.hitDice = (float)hdOverride + def->hitDiceBonus / 4.0f;
    a.monsterAttacks = def->attacks;
    a.monsterDamageCount = def->damageCount;
    a.monsterDamageSides = def->damageSides;
    a.magicResistPct = def->magicResist;
    a.undead = def->undead;
    a.requiredPlusToHit = def->requiredPlus;
    a.morale = def->morale;
    a.isLeader = def->isLeader;

    // hp: roll hit dice + bonus, use the provided value, or fall
    // back to the book average for flat-hp monsters
    if (hp < 0) {
        int diceCount = (hdOverride > 0) ? hdOverride : def->hitDiceNum;
        if (hdOverride > 0 && hpPerDie > 0) {
            hp = hdOverride * hpPerDie;   // R51: dragon age / hydra heads
        } else if (diceCount >= 1) {
            hp = (int)dice.roll((uint32_t)diceCount, 8,
                                def->hitDiceBonus);
        } else if (def->avgHp > 0) {
            hp = def->avgHp;               // "199 hp" style monster
        } else {
            hp = 1;                        // "1 hit point" degenerates
        }
        if (hp < 1) hp = 1;
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
