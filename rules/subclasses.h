// ============================================================================
// Adnd1 - rules/subclasses.h
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
// ============================================================================

#pragma once

#include <cstdint>

namespace rules {

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
    const int* xpRows;      // the printed attain rows
    int xpRowCount;
    int xpAdder;       // per level past the printed rows
    const char* const* titles;   // the printed ladder
    int titleCount;    // == xpRowCount
    int prime;         // the primary prime requisite
};

// ---- the printed rows (PHB pp.21-31, the class sections) ----

// Paladin: 0-2750 ... 1,050,001-1,400,000 (11th);
// 350,000 per level above the 11th; 3 hp past the 9th.
static const int kXpPaladin[11] = {
        0,   2750,   5500,  12000,  24000,
    45000,  95000, 175000, 350000, 700000,
  1050000
};
static const char* const kTitlePaladin[11] = {
    "Gallant", "Keeper", "Protector", "Defender",
    "Warder", "Guardian", "Chevalier", "Justiciar",
    "Paladin",
    "Paladin (10th level)", "Paladin (11th level)"
};

// Ranger: 0-2250 ... 975,001-1,300,000 (12th);
// 325,000 per level above the 12th; 2 hp past the
// 10th; level 1 carries two d8.
static const int kXpRanger[12] = {
        0,   2250,   4500,  10000,  20000,
    40000,  90000, 150000, 225000, 325000,
   650000,  975000
};
static const char* const kTitleRanger[12] = {
    "Runner", "Strider", "Scout", "Courser",
    "Tracker", "Guide", "Pathfinder", "Ranger",
    "Ranger Knight", "Ranger Lord",
    "Ranger Lord (11th level)", "Ranger Lord (12th level)"
};

// Druid: 0-2000 ... 1,500,001 (the 14th, the Great
// Druid); no printed adder - the hierarchy ceiling;
// 2 hp past the 9th.
static const int kXpDruid[14] = {
        0,   2000,   4000,   7500,  12500,
    20000,  35000,  60000,  90000, 125000,
   200000,  300000,  750000, 1500000
};
static const char* const kTitleDruid[14] = {
    "Aspirant", "Ovate",
    "Initiate of the 1st Circle", "Initiate of the 2nd Circle",
    "Initiate of the 3rd Circle", "Initiate of the 4th Circle",
    "Initiate of the 5th Circle", "Initiate of the 6th Circle",
    "Initiate of the 7th Circle", "Initiate of the 8th Circle",
    "Initiate of the 9th Circle", "Druid",
    "Archdruid", "The Great Druid"
};

// Illusionist: 0-2250 ... 660,001-880,000 (12th);
// 220,000 per level beyond the 12th; 1 hp past the
// 10th.
static const int kXpIllusionist[12] = {
        0,   2250,   4500,   9000,  18000,
    35000,  60000,  95000, 145000, 220000,
   440000,  660000
};
static const char* const kTitleIllusionist[12] = {
    "Prestidigitator", "Minor Trickster", "Trickster",
    "Master Trickster", "Cabalist", "Visionist",
    "Phantasmist", "Apparitionist", "Spellbinder",
    "Illusionist",
    "Illusionist (11th level)", "Illusionist (12th level)"
};

// Assassin: 0-1500 ... 1,500,001 and over (the 15th,
// the Grandfather of Assassins); no printed adder;
// 2 hp past the 10th.
static const int kXpAssassin[15] = {
        0,   1500,   3000,   6000,  12000,
    25000,  50000, 100000, 200000, 300000,
   425000,  575000,  750000, 1000000, 1500000
};
static const char* const kTitleAssassin[15] = {
    "Bravo (Apprentice)", "Rutterkin", "Waghalter",
    "Murderer", "Thug", "Killer", "Cutthroat",
    "Executioner", "Assassin", "Expert Assassin",
    "Senior Assassin", "Chief Assassin",
    "Prime Assassin", "Guildmaster Assassin",
    "Grandfather of Assassins"
};

// Monk: 0-2250 ... 3,250,001 and up (the 17th, the
// Grand Master of Flowers); no printed adder;
// level 1 carries two d4; hp rolls through all 17.
static const int kXpMonk[17] = {
        0,   2250,   4750,  10000,  22500,
    47500,  98000, 200000, 350000, 500000,
   700000,  950000, 1250000, 1750000, 2250000,
  2750000, 3250000
};
static const char* const kTitleMonk[17] = {
    "Novice", "Initiate", "Brother", "Disciple",
    "Immaculate", "Master", "Superior Master",
    "Master of Dragons",
    "Master of the North Wind", "Master of the West Wind",
    "Master of the South Wind", "Master of the East Wind",
    "Master of Winter", "Master of Autumn",
    "Master of Summer", "Master of Spring",
    "Grand Master of Flowers"
};

// ---- the registry (append a row per new class) ----

static const SubclassDef SUB_DEFS[SUB_COUNT] = {
    // paladin: fighter base, fighter group,
    // 3 hp past the 9th, d10, STR prime
    { "paladin", 0, 0, 9, 3, 10, 0,
      kXpPaladin, 11, 350000,
      kTitlePaladin, 11, 0 },
    // ranger: fighter base, fighter group,
    // 2 hp past the 10th, d8, two dice at level 1,
    // STR prime (with INT and WIS - the print)
    { "ranger", 0, 0, 10, 2, 8, 1,
      kXpRanger, 12, 325000,
      kTitleRanger, 12, 0 },
    // druid: cleric base, priest group,
    // 2 hp past the 9th, d8, WIS prime (with CHA)
    { "druid", 2, 1, 14, 2, 8, 0,
      kXpDruid, 14, 0,
      kTitleDruid, 14, 2 },
    // illusionist: magic-user base, wizard group,
    // 1 hp past the 10th, d4, INT prime
    { "illusionist", 1, 2, 10, 1, 4, 0,
      kXpIllusionist, 12, 220000,
      kTitleIllusionist, 12, 1 },
    // assassin: thief base, rogue group,
    // 2 hp past the 10th, d6, DEX prime
    { "assassin", 3, 3, 10, 2, 6, 0,
      kXpAssassin, 15, 0,
      kTitleAssassin, 15, 3 },
    // monk: no base class (its own), fighter-ish
    // group pending the specials round, d4, two
    // dice at level 1, STR prime (with WIS and DEX)
    { "monk", -1, 3, 17, 0, 4, 1,
      kXpMonk, 17, 0,
      kTitleMonk, 17, 0 },
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
// ceiling, the top row repeats).
inline int subclassXpFor(int i, int level) {
    const SubclassDef& d = subclassDef(i);
    if (level <= 1) return 0;
    if (level <= d.xpRowCount)
        return d.xpRows[level - 1];
    return d.xpRows[d.xpRowCount - 1]
         + (level - d.xpRowCount) * d.xpAdder;
}

// The printed title for the level (clamped)
inline const char* subclassTitle(int i, int level) {
    const SubclassDef& d = subclassDef(i);
    if (level < 1) level = 1;
    if (level > d.titleCount) level = d.titleCount;
    return d.titles[level - 1];
}

} // namespace rules