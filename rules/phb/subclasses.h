// ============================================================================
// Adnd1 - rules/phb/subclasses.h
// The subclass registry (R179, the arc foundations).
//
// The six PHB subclasses pinned from the printed class
// tables: paladin and ranger (the fighter group), druid
// (the cleric group), illusionist (the magic-user group),
// assassin (the thief group), and the monk - its own
// class, no base. Convention: the XP to ATTAIN a level is
// the printed band lower bound - 1 (the R176 convention).
//
// JUDGMENTs:
//   - the ranger and the monk first level carries TWO hit
//     dice (the printed accumulated column reads 2 at
//     level 1); the hit-die rolling wiring lands with the
//     later arc rounds.
//   - the druid, assassin and monk tables print no adder
//     past the top row - pinned as adder 0; the printed
//     top level is the ceiling (the druid hierarchy, the
//     assassin and monk tables end there).
//   - the ranger primes are strength, intelligence and
//     wisdom (all three, the print); the def returns the
//     primary. The monk likewise strength, wisdom and
//     dexterity. The druid double-primes wisdom and
//     charisma.
//   - the paladin and ranger join the fighter CON bonus
//     group (CON 17 +3, 18 +4 - the print includes the
//     fighter subclasses).
//   - the caps are the fixed-hp levels: the printed gain
//     X hp per level past the cap (paladin 3 past the
//     9th, ranger 2 past the 10th, druid 2 past the 9th,
//     illusionist 1 past the 10th, assassin 2 past the
//     10th; the monk rolls through its 17 printed
//     levels - hpBeyond 0).
//
// DATA-DRIVEN (the standing scope): a future class from
// a later sourcebook lands as ONE appended row - a def
// block, a bump of SUB_COUNT, and its battery rows.
//
// R1044: the xp-title ladders are registry-native
// (content/tables/class_ladders/, the seam below);
// the printed arrays are gone from this header and
// the accessors read registry views. The subclass
// scalars (base, group, caps, dice, adder, prime)
// are constants, not tables, and stay in-file.
// ============================================================================

#pragma once

#include <cstdint>

#include "items/MiscItemRegistry.h"   // R1044: the class ladders ride the registry

namespace rules {

// ---- the R1044 registry seam ----------------------------------------
// The seven PHB class xp-title ladders (the six
// subclass arrays and the bard ladder) ride
// items::MiscItemRegistry from
// content/tables/class_ladders/ (def keys = the
// SubclassDef name fields, plus "bard_ladder").
// Row encoding: band = { level, level } the printed
// level, gp the XP to attain it, name the printed
// title; the rest zero. This seam is header-only
// (the R1040-R1043 idiom); every accessor signature
// is unchanged (the r179/r186/r327 audits and the
// engine pin them); the clamp semantics stay
// verbatim. The subclass scalars (base, group,
// caps, dice, adder, prime) are constants, not
// tables, and stay in the struct below.

inline items::MiscItemRegistry& ladderReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/class_ladders");
    }
    return reg;
}

// the registry-backed per-view cache (the
// R1032-R1043 idiom; function-local statics in
// inline functions are shared across TUs)
inline const std::vector<items::MiscItemRow>& scLadder(
        const char* name) {
    static std::map<std::string,
        std::vector<items::MiscItemRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end()) {
        const items::MiscItemDef* d = ladderReg().find(name);
        it = cache.emplace(
            name, d ? d->rows
                   : std::vector<items::MiscItemRow>()).first;
    }
    return it->second;
}

// ---- the R1047 grid registry seam ----------------------------------
// The PHB class grids (the bard college
// column, the bard druid slots grid, the
// druid slots grid) ride
// items::MiscItemRegistry from
// content/tables/class_grids/ (def keys
// bard_colleges, bard_druid_slots,
// druid_slots). The slots defs encode the
// grid as tables[1] name "grid", values
// flat row-major (RowCount x ColCount pins);
// the colleges def encodes rows (name the
// college, band { level, level }). This seam
// is header-only (the R1040-R1044 idiom);
// every accessor signature is unchanged (the
// r186/r228/r235a audits and the engine pin
// them); the clamp semantics stay verbatim.

inline items::MiscItemRegistry& gridReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/class_grids");
    }
    return reg;
}

// the registry-backed per-view caches (the
// R1032-R1044 idiom; function-local statics in
// inline functions are shared across TUs)
inline const std::vector<items::MiscItemRow>&
gridRows(const char* name) {
    static std::map<std::string,
        std::vector<items::MiscItemRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end()) {
        const items::MiscItemDef* d =
            gridReg().find(name);
        it = cache.emplace(
            name, d ? d->rows
                   : std::vector<items::MiscItemRow>()).first;
    }
    return it->second;
}

inline const std::vector<long long>&
gridValues(const char* name) {
    static std::map<std::string,
        std::vector<long long>> cache;
    auto it = cache.find(name);
    if (it == cache.end()) {
        std::vector<long long> v;
        const items::MiscItemDef* d =
            gridReg().find(name);
        if (d && d->tables.size() == 1
            && d->tables[0].name == "grid")
            v = d->tables[0].values;
        it = cache.emplace(name, v).first;
    }
    return it->second;
}


// The subclass indices (stable; append only)
enum Subclass : int {
    SUB_PALADIN = 0,
    SUB_RANGER = 1,
    SUB_DRUID = 2,
    SUB_ILLUSIONIST = 3,
    SUB_ASSASSIN = 4,
    SUB_MONK = 5,
    SUB_COUNT = 6
};

// One registry row. xpRows[i] is the XP to attain
// level i+1 (the printed band lower bound - 1).
struct SubclassDef {
    const char* name;
    int base;           // the base CharClass, or -1 (monk)
    int group;          // the ClassGroup from classes.h
    int levelCap;       // past this level, fixed hp
    int hpBeyondCap;    // the fixed hp per level past the cap
    int hitDie;         // 4 / 6 / 8 / 10
    int twoDiceFirstLevel;  // 1 if level 1 carries two dice
    int xpRowCount;    // == the registry ladder rows
    int xpAdder;       // per level past the printed rows
    int titleCount;    // == xpRowCount (the ladder)
    int prime;         // the primary prime requisite
};

// ---- the printed rows (PHB pp.21-31, the class sections) ----

// Paladin: 0-2750 ... 1,050,001-1,400,000 (11th);
// 350,000 per level above the 11th; 3 hp past the 9th.

// Ranger: 0-2250 ... 975,001-1,300,000 (12th);
// 325,000 per level above the 12th; 2 hp past the
// 10th; level 1 carries two d8.

// Druid: 0-2000 ... 1,500,001 (the 14th, the Great
// Druid); no printed adder - the hierarchy ceiling;
// 2 hp past the 9th.

// Illusionist: 0-2250 ... 660,001-880,000 (12th);
// 220,000 per level beyond the 12th; 1 hp past the
// 10th.

// Assassin: 0-1500 ... 1,500,001 and over (the 15th,
// the Grandfather of Assassins); no printed adder;
// 2 hp past the 10th.

// Monk: 0-2250 ... 3,250,001 and up (the 17th, the
// Grand Master of Flowers); no printed adder;
// level 1 carries two d4; hp rolls through all 17.

// ---- the registry (append a row per new class) ----

static const SubclassDef SUB_DEFS[SUB_COUNT] = {
    // paladin: fighter base, fighter group,
    // 3 hp past the 9th, d10, STR prime
    { "paladin", 0, 0, 9, 3, 10, 0,
      11, 350000,
      11, 0 },
    // ranger: fighter base, fighter group,
    // 2 hp past the 10th, d8, two dice at level 1,
    // STR prime (with INT and WIS - the print)
    { "ranger", 0, 0, 10, 2, 8, 1,
      12, 325000,
      12, 0 },
    // druid: cleric base, priest group,
    // 2 hp past the 9th, d8, WIS prime (with CHA)
    { "druid", 2, 1, 14, 2, 8, 0,
      14, 0,
      14, 2 },
    // illusionist: magic-user base, wizard group,
    // 1 hp past the 10th, d4, INT prime
    { "illusionist", 1, 2, 10, 1, 4, 0,
      12, 220000,
      12, 1 },
    // assassin: thief base, rogue group,
    // 2 hp past the 10th, d6, DEX prime
    { "assassin", 3, 3, 10, 2, 6, 0,
      15, 0,
      15, 3 },
    // monk: no base class (its own), fighter-ish
    // group pending the specials round, d4, two
    // dice at level 1, STR prime (with WIS and DEX)
    { "monk", -1, 3, 17, 0, 4, 1,
      17, 0,
      17, 0 },
};

// ---- accessors ----

inline int subclassCount() { return SUB_COUNT; }

inline const SubclassDef& subclassDef(int i) {
    if (i < 0) i = 0;
    if (i >= SUB_COUNT) i = SUB_COUNT - 1;
    return SUB_DEFS[i];
}

// The XP to ATTAIN the given level (the R176
// convention). Past the printed rows, the adder
// applies (adder 0: the printed top is the
// ceiling, the top row repeats). The ladder
// rows ride the R1044 registry seam.
inline int subclassXpFor(int i, int level) {
    const SubclassDef& d = subclassDef(i);
    if (level <= 1) return 0;
    const auto& rows = scLadder(d.name);
    if (rows.empty()) return 0;   // defensive: unloaded view
    const int n = (int)rows.size();
    if (level <= n) return rows[level - 1].gp;
    return rows[n - 1].gp + (level - n) * d.xpAdder;
}

// The printed title for the level (clamped).
// The ladder rows ride the R1044 registry seam.
inline const char* subclassTitle(int i, int level) {
    const SubclassDef& d = subclassDef(i);
    const auto& rows = scLadder(d.name);
    if (rows.empty()) return "";   // defensive: unloaded
    if (level < 1) level = 1;
    if (level > (int)rows.size()) level = (int)rows.size();
    return rows[level - 1].name.c_str();
}

} // namespace rules