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

// ----------------------------------------------------------------------------
// R71: parse the Lua `treasure` field (MM TREASURE TYPE line) into
// per-creature and in-lair letter lists. All 104 observed string
// formats parse; the four comma-only strings whose split disagrees
// with the J-N per-individual default are hard-coded from the printed
// TREASURE TYPE lines (Curtiss-verified 2026-09-29):
//   hobgoblin "Individuals J, M, D, Q (x5) in lair" -> ind J,M,D; lair Q x5
//   kobold    "Individuals J, O, Q (x5) in lair"   -> ind J,O;   lair Q x5
//   ettin     "Individual O, C, Y in lair"         -> ind O,C;   lair Y
//   dervish   "Individuals J (L), Z in lair"      -> ind J;     lair L,Z
// As-printed quirks preserved: "none", "See below", and the bare
// digits ("1", "6" — werewolf etc.) parse as empty; the verbatim text
// stays in MonsterDef::treasureText.
// ----------------------------------------------------------------------------
namespace {

struct TToken {
    std::vector<char> letters;   // A-Z, ranges expanded
    int  times      = 1;
    bool magicOnly  = false;
    int  keyword    = 0;   // 1 = "individual(s)", 2 = "lair"
    bool separator  = false; // preceded by ';' or '.' (lair from here)
};

bool tHasWord(const std::string& s, const char* w) {
    return std::string::npos != s.find(w);
}

std::vector<TToken> tTokenize(const std::string& text, bool& certain) {
    std::vector<TToken> toks;
    std::string cur;
    bool sep = false;
    auto push = [&]() {
        if (cur.empty()) return;
        TToken t;
        t.separator = sep;
        sep = false;
        std::string low;
        for (char c : cur) low.push_back((char)std::tolower((unsigned char)c));
        if (tHasWord(low, "in lair")) {
            size_t p = low.find("in lair");
            cur.erase(p, 7);
            low.erase(p, 7);
        }
        if (tHasWord(low, "individual")) {
            t.keyword = 1;
            size_t p = low.find("individual");
            cur.erase(p, 12);   // "individuals" is 12; trims "s" next
            while (p < cur.size() && !std::isalpha((unsigned char)cur[p]))
                cur.erase(p, 1);
        } else if (tHasWord(low, "lair")) {
            t.keyword = 2;
            size_t p = low.find("lair");
            cur.erase(p, 4);
            while (p < cur.size() && !std::isalpha((unsigned char)cur[p]))
                cur.erase(p, 1);
        }
        // "100%" prefix (certainty flag; percentages other than 100
        // are not printed in any MM entry)
        if (low.find("100%") != std::string::npos) {
            certain = true;
            size_t p = cur.find('%');
            cur.erase(0, p + 1);
        }
        // multiplier "(x 10)" / "(x20)" / unicode times
        size_t po = cur.find('(');
        if (po != std::string::npos) {
            std::string in = cur.substr(po + 1);
            size_t pc = in.find(')');
            if (pc != std::string::npos) in = in.substr(0, pc);
            std::string lowin;
            for (char c : in)
                lowin.push_back((char)std::tolower((unsigned char)c));
            if (lowin.find("magic") != std::string::npos)
                t.magicOnly = true;
            else {
                // digits in the parens -> multiplier
                std::string digits;
                for (char c : in)
                    if (std::isdigit((unsigned char)c)) digits.push_back(c);
                if (!digits.empty()) t.times = std::atoi(digits.c_str());
            }
            cur.erase(po);
        }
        // letters: collect capitals; expand "X-Y" ranges
        for (size_t i = 0; i < cur.size(); ++i) {
            char c = cur[i];
            if (c >= 'A' && c <= 'Z') {
                if (i + 2 < cur.size() && cur[i + 1] == '-' &&
                    cur[i + 2] >= 'A' && cur[i + 2] <= 'Z') {
                    for (char k = c; k <= cur[i + 2]; ++k)
                        t.letters.push_back(k);
                    i += 2;
                } else {
                    t.letters.push_back(c);
                }
            }
        }
        if (!t.letters.empty() || t.keyword) toks.push_back(t);
        cur.clear();
    };
    for (char c : text) {
        if (c == ',' || c == ';' || c == '.' || c == '\n') {
            push();
            if (c != ',') sep = true;
        } else {
            cur.push_back(c);
        }
    }
    push();
    return toks;
}

} // namespace

static TreasureSpec parseTreasureText(const std::string& key,
                                      const std::string& text) {
    TreasureSpec spec;
    (void)key;
    std::string t;
    for (char c : text) t.push_back(c);
    // trim
    while (!t.empty() && std::isspace((unsigned char)t.back())) t.pop_back();
    size_t b = 0;
    while (b < t.size() && std::isspace((unsigned char)t[b])) ++b;
    t = t.substr(b);
    if (t.empty()) return spec;
    std::string low;
    for (char c : t)
        low.push_back((char)std::tolower((unsigned char)c));
    if (low == "none" || low == "see below") return spec;
    bool allDigits = !low.empty();
    for (char c : low)
        if (!std::isdigit((unsigned char)c)) { allDigits = false; break; }
    if (allDigits) return spec;   // werewolf "6" etc., printed as-is

    // Book-verified splits where the J-N default rule fails
    struct Ov { const char* key; const char* ind; const char* lair; };
    static const Ov ovs[] = {
        { "hobgoblin", "JMD",  "Q" },
        { "kobold",    "JO",   "Q" },
        { "ettin",     "OC",   "Y"  },
        { "dervish",   "J",    "LZ" },
    };
    for (const auto& o : ovs) {
        if (key != o.key) continue;
        for (char c : std::string(o.ind))
            spec.individual.push_back({c, 1, false});
        // kobold & hobgoblin: lair Q x5 (both print "(x5)")
        bool q5 = key == "kobold" || key == "hobgoblin";
        for (char c : std::string(o.lair))
            spec.lair.push_back({c, q5 ? 5 : 1, false});
        return spec;
    }

    bool certain = false;
    auto toks = tTokenize(t, certain);
    spec.certain = certain;

    // Assignment: a ';'/.'/'Lair' keyword boundary splits the halves;
    // otherwise the leading run of J-N letters (the MM's per-individual
    // band) is individual treasure and everything after is lair.
    bool haveBoundary = false;
    for (const auto& tk : toks)
        if (tk.separator || tk.keyword == 2) haveBoundary = true;

    bool inInd = true, seenNonJN = false;
    bool modeInd = true;
    for (const auto& tk : toks) {
        if (haveBoundary) {
            if (tk.separator || tk.keyword == 2) modeInd = false;
            if (tk.keyword == 1) modeInd = true;
        } else {
            if (!tk.letters.empty()) {
                char c = tk.letters[0];
                bool jn = (c >= 'J' && c <= 'N');
                if (!jn && !seenNonJN) { seenNonJN = true; modeInd = false; }
            }
        }
        for (char c : tk.letters) {
            TreasureEntry e{c, tk.times, tk.magicOnly};
            if (modeInd) spec.individual.push_back(e);
            else         spec.lair.push_back(e);
        }
    }
    (void)inInd;
    return spec;
}


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

    // ---- R71: treasure type letters ----
    def.treasureText = luaGetStr(L, "treasure", "");
    def.treasure = parseTreasureText(def.key, def.treasureText);

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
    if (h == INVALID_HANDLE_VALUE) {
        // R74: "no files" is not an error — POSIX opendir succeeds on an
        // empty dir. Match that contract: only hard path errors are -1.
        return GetLastError() == ERROR_FILE_NOT_FOUND ? 0 : -1;
    }
    int count = 0;
    do {
        std::string fname = fd.cFileName;
        // R74: FindFirstFileA 3-char-extension quirk — "*.lua" can also
        // match e.g. "foo.luax" (8.3 short-name semantics). Guard exactly
        // like the POSIX branch: only genuine .lua files.
        if (fname.size() < 5 ||
            fname.compare(fname.size() - 4, 4, ".lua") != 0)
            continue;
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
