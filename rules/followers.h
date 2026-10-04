// ====================================================================
// Adnd1 - rules/followers.h
// R170: followers for upper level player characters
// by class (DMG pp.16-18) - the cleric, fighter,
// ranger, thief and assassin recruitment tables,
// the multi-class tables, the Grandfather ladder,
// the arrival timing and the paladin warhorse.
//
// Pure data, header-only (the grenade.h pattern:
// the caller rolls the dice and builds the rosters).
//
// The pp.16-18 print is summarized in the R170
// splice header and the gap report note; the
// JUDGMENTs: (a) the re-upload OCR drops the
// half-orcish 26-50 band of the RACE OF
// ASSASSIN table - pinned as the print runs;
// (b) in the MULTI-CLASSED ASSASSIN table the
// dwarf, elf and half-elf rows each print no
// other class permitted; (c) the printed
// asterisks ride as flags (the OCR shows no
// footnotes for them).
// ====================================================================

#pragma once

namespace rules {

// ----------------------------------------------------------------------------
// Cleric followers (p.16): roll for each category,
// all 0 level men-at-arms
// ----------------------------------------------------------------------------

struct FollowerClericUnit {
    const char* kind;
    const char* armor;
    const char* weapons;
    int nMin;
    int nMax;
};

inline int folClericCategoryCount() { return 7; }

inline const FollowerClericUnit& folClericUnit(int i) {
    static const FollowerClericUnit k[7] = {
        { "heavy cavalry", "plate mail and shield",
          "lance, broad sword, mace", 2, 8 },
        { "medium cavalry", "chain mail and shield",
          "lance, flail, short sword", 3, 12 },
        { "light cavalry",
          "studded leather and shield",
          "light crossbow, pick", 5, 30 },
        { "heavy infantry", "splint mail",
          "battle axe, long sword", 5, 20 },
        { "heavy infantry", "chain mail",
          "pole arm (select randomly or assign), hand axe",
          5, 30 },
        { "heavy infantry", "ring mail",
          "heavy crossbow, short sword", 5, 30 },
        { "light infantry", "padded armor and shield",
          "spear, club", 10, 60 }
    };
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    return k[i];
}

inline bool folClericRollForEachCategory() {
    return true;
}
inline bool folClericAllZeroLevel() { return true; }
inline bool folPoleArmRandomOrAssigned() {
    return true;
}

// ----------------------------------------------------------------------------
// Fighter followers (p.16): roll once for the
// leader, once for the troops
// ----------------------------------------------------------------------------

struct FollowerFighterLeader {
    int lo, hi;
    int level;
    const char* gear;
};

inline int folFighterLeaderBandCount() { return 4; }

inline const FollowerFighterLeader& folFighterLeader(
        int i) {
    static const FollowerFighterLeader k[4] = {
        { 1, 40, 5,
          "plate mail and shield, +2 magic battle axe" },
        { 41, 75, 6,
          "plate mail and +1 shield, +1 magic spear and +1 dagger" },
        { 76, 95, 6,
          "+1 plate mail and shield, arms as above, a 3rd level lieutenant in splint mail and shield with a crossbow of distance" },
        { 96, 100, 7,
          "+1 plate mail and +1 shield, +2 magic sword (no special abilities), rides a heavy warhorse with horseshoes of speed" }
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

inline int folFighterLeaderForD100(int d100) {
    for (int i = 3; i >= 0; --i)
        if (d100 >= folFighterLeader(i).lo) return i;
    return 0;
}

struct FollowerFighterTroops {
    int lo, hi;
    const char* text;
};

inline int folFighterTroopsBandCount() { return 4; }

inline const FollowerFighterTroops& folFighterTroops(
        int i) {
    static const FollowerFighterTroops k[4] = {
        { 1, 50,
          "20 light cavalry, ring mail and shield, 3 javelins, long sword, hand axe; and 100 heavy infantry, scale mail, pole arm (selected randomly or assigned) and club" },
        { 51, 75,
          "80 heavy infantry, 20 with splint mail, 60 with leather armor, 20 with morning star and hand axe, 60 with pike and short sword" },
        { 76, 90,
          "60 crossbowmen, chain mail, 40 with heavy crossbow and short sword, 20 with light crossbow and military fork" },
        { 91, 100,
          "60 cavalry, 10 with banded mail and shield, 20 with scale mail and shield, 30 with studded leather and shield, 10 with lance, bastard sword and mace, 20 with lance, long sword and mace, 30 with lance and flail" }
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

inline int folFighterTroopsForD100(int d100) {
    for (int i = 3; i >= 0; --i)
        if (d100 >= folFighterTroops(i).lo) return i;
    return 0;
}

inline bool folFighterRollOnceLeaderOnceTroops() {
    return true;
}

// ----------------------------------------------------------------------------
// Ranger followers (p.16): 2d12 count and the
// d% adjustment ladder
// ----------------------------------------------------------------------------

struct FollowerRangerAdjust {
    int lo, hi;
    int adj;        // percent, applied to each roll
    int firstOnly;  // nonzero: first roll only
};

inline int folRangerAdjustBandCount() { return 9; }

inline const FollowerRangerAdjust& folRangerAdjust(
        int i) {
    static const FollowerRangerAdjust k[9] = {
        { 2, 2, 25, 0 },
        { 3, 3, 15, 0 },
        { 4, 4, 10, 1 },
        { 5, 6, 5, 1 },
        { 7, 9, 0, 0 },
        { 10, 12, -5, 0 },
        { 13, 16, -10, 0 },
        { 17, 20, -20, 0 },
        { 21, 24, -30, 0 }
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline int folRangerAdjustFor2d12(int roll) {
    for (int i = 0; i < 9; ++i)
        if (roll >= folRangerAdjust(i).lo
                && roll <= folRangerAdjust(i).hi)
            return folRangerAdjust(i).adj;
    return 0;
}

inline bool folRangerAdjustFirstRollOnly(int roll) {
    for (int i = 0; i < 9; ++i)
        if (roll >= folRangerAdjust(i).lo
                && roll <= folRangerAdjust(i).hi)
            return folRangerAdjust(i).firstOnly != 0;
    return false;
}

// Roll again if an adjustment falls within a
// category no longer permissible, or if a
// subtraction results in a score under 01.
inline bool folRangerRerollImpermissibleOrUnder01() {
    return true;
}

// All scores over 70 are special, and the
// ranger attracts one follower/creature group
// only from each category.
inline int folRangerSpecialThreshold() { return 70; }
inline bool folRangerOneGroupPerCategory() {
    return true;
}
inline int folRangerCountDice() { return 2; }
inline int folRangerCountDieSides() { return 12; }

// ----------------------------------------------------------------------------
// Thief followers (pp.16-17): 4d6 count, the
// level modifier, the category bands and the
// race and level tables
// ----------------------------------------------------------------------------

struct FollowerThiefLevelAdjust {
    int lo, hi;
    int adj;
};

inline int folThiefLevelAdjustBandCount() { return 6; }

inline const FollowerThiefLevelAdjust&
folThiefLevelAdjust(int i) {
    static const FollowerThiefLevelAdjust k[6] = {
        { 4, 4, 20 },
        { 5, 6, 15 },
        { 7, 9, 5 },
        { 10, 15, 0 },
        { 16, 20, -5 },
        { 21, 24, -10 }
    };
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

inline int folThiefLevelAdjustFor4d6(int roll) {
    for (int i = 0; i < 6; ++i)
        if (roll >= folThiefLevelAdjust(i).lo
                && roll <= folThiefLevelAdjust(i).hi)
            return folThiefLevelAdjust(i).adj;
    return 0;
}

inline int folThiefCountDice() { return 4; }
inline int folThiefCountDieSides() { return 6; }

// The category bands: which table the d%
// roll selects (I humans through VI special).
inline int folThiefCategoryForD100(int d100) {
    if (d100 <= 50) return 1;
    if (d100 <= 70) return 2;
    if (d100 <= 80) return 3;
    if (d100 <= 90) return 4;
    if (d100 <= 95) return 5;
    return 6;
}

// RACE OF THIEF (7 bands; the star rides as a
// flag - the OCR shows no footnote).
struct FollowerThiefRace {
    int lo, hi;
    const char* name;
    int star;
};

inline int folThiefRaceBandCount() { return 7; }

inline const FollowerThiefRace& folThiefRace(int i) {
    static const FollowerThiefRace k[7] = {
        { 1, 10, "dwarven", 1 },
        { 11, 20, "elven", 1 },
        { 21, 25, "gnomish", 1 },
        { 26, 30, "half-elven", 1 },
        { 31, 35, "halfling", 1 },
        { 36, 55, "half-orcish", 1 },
        { 56, 100, "human", 0 }
    };
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    return k[i];
}

inline int folThiefRaceForD100(int d100) {
    for (int i = 6; i >= 0; --i)
        if (d100 >= folThiefRace(i).lo) return i;
    return 0;
}

// LEVEL OF THIEF (7 bands; the level 1 star
// rides as a flag).
struct FollowerThiefLevel {
    int lo, hi;
    int level;
    int star;
};

inline int folThiefLevelBandCount() { return 7; }

inline const FollowerThiefLevel& folThiefLevelBand(
        int i) {
    static const FollowerThiefLevel k[7] = {
        { 1, 20, 1, 1 },
        { 21, 45, 2, 0 },
        { 46, 65, 3, 0 },
        { 66, 80, 4, 0 },
        { 81, 90, 5, 0 },
        { 91, 95, 6, 0 },
        { 96, 100, 7, 0 }
    };
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    return k[i];
}

inline int folThiefLevelForD100(int d100) {
    for (int i = 6; i >= 0; --i)
        if (d100 >= folThiefLevelBand(i).lo) return i;
    return 0;
}

// HUMANS, TABLE I: class and level range.
struct FollowerHumanClass {
    int lo, hi;
    const char* cls;
    int lvMin, lvMax;
};

inline int folHumanClassBandCount() { return 5; }

inline const FollowerHumanClass& folHumanClass(
        int i) {
    static const FollowerHumanClass k[5] = {
        { 1, 15, "cleric", 1, 4 },
        { 16, 40, "druid", 2, 5 },
        { 41, 85, "fighter", 1, 6 },
        { 86, 95, "ranger", 1, 3 },
        { 96, 100, "magic-user", 1, 3 }
    };
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

// DEMI-HUMANS, TABLE II: race and class, level
// range, number arriving (12 rows).
struct FollowerDemiHuman {
    int lo, hi;
    const char* raceClass;
    int lvMin, lvMax;
    int number;
};

inline int folDemiHumanBandCount() { return 12; }

inline const FollowerDemiHuman& folDemiHuman(
        int i) {
    static const FollowerDemiHuman k[12] = {
        { 1, 15, "dwarf fighter", 1, 4, 2 },
        { 16, 20, "dwarf fighter/thief", 1, 1, 1 },
        { 21, 40, "elf fighter", 2, 5, 2 },
        { 41, 45, "elf fighter/magic-user", 1, 1, 1 },
        { 46, 50, "elf fighter/magic-user/thief",
          1, 1, 1 },
        { 51, 60, "gnome fighter", 1, 3, 3 },
        { 61, 65, "gnome fighter/illusionist", 1, 1, 1 },
        { 66, 75, "half-elf cleric/ranger", 1, 1, 1 },
        { 76, 80, "half-elf cleric/fighter/magic-user",
          1, 1, 1 },
        { 81, 85, "half-elf fighter/thief", 1, 1, 1 },
        { 86, 95, "halfling fighter", 1, 3, 3 },
        { 96, 100, "halfling fighter/thief", 1, 1, 1 }
    };
    if (i < 0) i = 0;
    if (i > 11) i = 11;
    return k[i];
}

// MULTI-CLASS THIEF FOLLOWER TABLE: the other
// profession by d6, per race (0 dwarf, 1 elf,
// 2 gnome, 3 half-elf, 4 halfling,
// 5 half-orc).
inline const char* folThiefOtherProfession(
        int raceIdx, int d6) {
    if (raceIdx == 1 || raceIdx == 3) {  // elf, half-elf
        if (d6 <= 3) return "fighter";
        if (d6 <= 5) return "magic-user";
        return "fighter/magic-user";
    }
    if (raceIdx == 2) {  // gnome
        if (d6 <= 5) return "fighter";
        return "illusionist";
    }
    if (raceIdx == 5) {  // half-orc
        if (d6 <= 3) return "cleric";
        return "fighter";
    }
    // dwarf, halfling: fighter only
    return "fighter";
}

// The printed note: followers with the
// professed class of thief are always neutral
// good.
inline bool folThiefFollowersAlwaysNeutralGood() {
    return true;
}

// ----------------------------------------------------------------------------
// The ranger/thief creature tables (p.17)
// ----------------------------------------------------------------------------

struct FollowerCreature {
    int lo, hi;
    const char* name;
    int nMin, nMax;
    int star;
};

// ANIMALS, TABLE III (one roll only).
inline int folAnimalBandCount() { return 5; }

inline const FollowerCreature& folAnimal(int i) {
    static const FollowerCreature k[5] = {
        { 1, 20, "bear, black", 1, 1, 0 },
        { 21, 55, "bear, brown", 1, 1, 0 },
        { 56, 65, "blink dog", 2, 2, 0 },
        { 66, 80, "lynx, giant", 2, 2, 0 },
        { 81, 100, "owl, giant", 2, 2, 0 }
    };
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

// MOUNTS, TABLE IV (one roll only).
inline int folMountBandCount() { return 3; }

inline const FollowerCreature& folMount(int i) {
    static const FollowerCreature k[3] = {
        { 1, 35, "centaur", 1, 3, 0 },
        { 36, 75, "hippogriff", 1, 1, 0 },
        { 76, 100, "pegasus", 1, 1, 0 }
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

// CREATURES, TABLE V (one roll only).
inline int folCreatureBandCount() { return 5; }

inline const FollowerCreature& folCreature(int i) {
    static const FollowerCreature k[5] = {
        { 1, 50, "brownie", 1, 2, 0 },
        { 51, 75, "pixie", 1, 4, 0 },
        { 76, 80, "pseudo-dragon", 1, 1, 0 },
        { 81, 90, "satyr", 1, 1, 0 },
        { 91, 100, "sprite", 2, 4, 0 }
    };
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

// SPECIAL CREATURES, TABLE VI (one roll only;
// the copper dragon star rides as a flag).
inline int folSpecialBandCount() { return 5; }

inline const FollowerCreature& folSpecial(int i) {
    static const FollowerCreature k[5] = {
        { 1, 5, "copper dragon", 1, 1, 1 },
        { 6, 10, "giant, storm", 1, 1, 0 },
        { 11, 30, "treant", 2, 5, 0 },
        { 31, 75, "werebear", 1, 2, 0 },
        { 76, 100, "weretiger", 1, 2, 0 }
    };
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

// ----------------------------------------------------------------------------
// Assassin followers (p.18)
// ----------------------------------------------------------------------------

inline int folAssassinCountDice() { return 7; }
inline int folAssassinCountDieSides() { return 4; }
inline bool folAssassinAdjustForPopulation() {
    return true;
}
inline int folAssassinDesertChance() { return 75; }
inline bool folAssassinNewcomersFirstLevel() {
    return true;
}

// RACE OF ASSASSIN (6 bands; the half-orcish
// 26-50 band is dropped by the re-upload OCR
// and pinned as the print runs).
inline int folAssassinRaceBandCount() { return 6; }

inline const FollowerThiefRace& folAssassinRace(
        int i) {
    static const FollowerThiefRace k[6] = {
        { 1, 5, "dwarven", 1 },
        { 6, 10, "elven", 1 },
        { 11, 15, "gnomish", 1 },
        { 16, 25, "half-elven", 1 },
        { 26, 50, "half-orcish", 1 },
        { 51, 100, "human", 0 }
    };
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

inline int folAssassinRaceForD100(int d100) {
    for (int i = 5; i >= 0; --i)
        if (d100 >= folAssassinRace(i).lo) return i;
    return 0;
}

// LEVEL OF ASSASSIN (8 bands; the 1st and 2nd
// level stars ride as flags).
struct FollowerAssassinLevel {
    int lo, hi;
    int level;
    int star;
};

inline int folAssassinLevelBandCount() { return 8; }

inline const FollowerAssassinLevel&
folAssassinLevelBand(int i) {
    static const FollowerAssassinLevel k[8] = {
        { 1, 15, 1, 1 },
        { 16, 30, 2, 1 },
        { 31, 45, 3, 0 },
        { 46, 65, 4, 0 },
        { 66, 75, 5, 0 },
        { 76, 85, 6, 0 },
        { 86, 95, 7, 0 },
        { 96, 100, 8, 0 }
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

inline int folAssassinLevelForD100(int d100) {
    for (int i = 7; i >= 0; --i)
        if (d100 >= folAssassinLevelBand(i).lo) return i;
    return 0;
}

// 1st and 2nd level non-human (or part human)
// assassins have a 25 percent chance of being
// multi-classed.
inline int folAssassinMultiClassChance() {
    return 25;
}

// MULTI-CLASSED ASSASSIN TABLE: the other
// profession by d6 (0 dwarf, 1 elf, 2 gnome,
// 3 half-elf, 4 half-orc); the dwarf, elf and
// half-elf rows print no other class
// permitted.
inline const char* folAssassinOtherProfession(
        int raceIdx, int d6) {
    if (raceIdx == 2) {  // gnome
        if (d6 <= 4) return "fighter";
        return "illusionist";
    }
    if (raceIdx == 4) {  // half-orc
        if (d6 <= 2) return "fighter";
        return "cleric";
    }
    return "no other class permitted";
}

// ----------------------------------------------------------------------------
// The Grandfather/Grandmother of Assassins
// ----------------------------------------------------------------------------

// The 28 mid-level followers: at index i
// (0-6) there are i+1 assassins of level 8-i.
inline int folGrandfatherCountAt(int i) {
    return i + 1;
}
inline int folGrandfatherLevelAt(int i) {
    return 8 - i;
}
inline int folGrandfatherTotalMidLevel() {
    return 28;
}
inline int folGrandfatherFirstLevelMin() {
    return 4;
}
inline int folGrandfatherFirstLevelMax() {
    return 16;
}
inline int folGrandfatherDisplacedLeaveChance() {
    return 75;
}
inline int folGrandfatherNewLeaderMax() { return 44; }

// ----------------------------------------------------------------------------
// Arrival timing (p.18)
// ----------------------------------------------------------------------------

// The first follower appears d10 (with d6 tens:
// 1-2 add nothing, 3-4 add 10, 5-6 add 20)
// days after the requirements are met.
inline int folArrivalTensAdjust(int d6) {
    if (d6 <= 2) return 0;
    if (d6 <= 4) return 10;
    return 20;
}
inline int folArrivalDayMax() { return 30; }

// Thereafter followers arrive at intervals of
// 1-8 days; if no one is available to receive
// them they wait 1-4 days and then depart
// forever.
inline int folArrivalIntervalDaysMin() { return 1; }
inline int folArrivalIntervalDaysMax() { return 8; }
inline int folArrivalWaitDaysMin() { return 1; }
inline int folArrivalWaitDaysMax() { return 4; }
inline bool folArrivalUnreceivedGoneForever() {
    return true;
}
inline bool folHenchmanOrServantMayReceive() {
    return true;
}

// ----------------------------------------------------------------------------
// The paladin warhorse (p.18)
// ----------------------------------------------------------------------------

inline int folPaladinWarhorseMinLevel() { return 4; }
inline int folPaladinJourneyMaxDaysRide() { return 7; }
inline int folPaladinTaskWeeksMin() { return 2; }
inline int folPaladinWarhorseServiceYears() {
    return 10;
}
inline bool folPaladinWarhorseMayBeWild() {
    return true;
}
inline bool folPaladinGuardedByEvilFighterSameLevel() {
    return true;
}

} // namespace rules
