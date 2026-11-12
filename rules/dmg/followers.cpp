// R-refactor: split from followers.h - definitions
#include "rules/dmg/followers.h"

int Followers::folClericCategoryCount() { return 7; }

const FollowerClericUnit& Followers::folClericUnit(int i) {
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

bool Followers::folClericRollForEachCategory() {
    return true;
}

bool Followers::folClericAllZeroLevel() { return true; }

bool Followers::folPoleArmRandomOrAssigned() {
    return true;
}

int Followers::folFighterLeaderBandCount() { return 4; }

const FollowerFighterLeader& Followers::folFighterLeader( int i) {
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

int Followers::folFighterLeaderForD100(int d100) {
    for (int i = 3; i >= 0; --i)
        if (d100 >= folFighterLeader(i).lo) return i;
    return 0;
}

int Followers::folFighterTroopsBandCount() { return 4; }

const FollowerFighterTroops& Followers::folFighterTroops( int i) {
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

int Followers::folFighterTroopsForD100(int d100) {
    for (int i = 3; i >= 0; --i)
        if (d100 >= folFighterTroops(i).lo) return i;
    return 0;
}

bool Followers::folFighterRollOnceLeaderOnceTroops() {
    return true;
}

int Followers::folRangerAdjustBandCount() { return 9; }

const FollowerRangerAdjust& Followers::folRangerAdjust( int i) {
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

int Followers::folRangerAdjustFor2d12(int roll) {
    for (int i = 0; i < 9; ++i)
        if (roll >= folRangerAdjust(i).lo
                && roll <= folRangerAdjust(i).hi)
            return folRangerAdjust(i).adj;
    return 0;
}

bool Followers::folRangerAdjustFirstRollOnly(int roll) {
    for (int i = 0; i < 9; ++i)
        if (roll >= folRangerAdjust(i).lo
                && roll <= folRangerAdjust(i).hi)
            return folRangerAdjust(i).firstOnly != 0;
    return false;
}

bool Followers::folRangerRerollImpermissibleOrUnder01() {
    return true;
}

int Followers::folRangerSpecialThreshold() { return 70; }

bool Followers::folRangerOneGroupPerCategory() {
    return true;
}

int Followers::folRangerCountDice() { return 2; }

int Followers::folRangerCountDieSides() { return 12; }

int Followers::folThiefLevelAdjustBandCount() { return 6; }

const FollowerThiefLevelAdjust& Followers::folThiefLevelAdjust(int i) {
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

int Followers::folThiefLevelAdjustFor4d6(int roll) {
    for (int i = 0; i < 6; ++i)
        if (roll >= folThiefLevelAdjust(i).lo
                && roll <= folThiefLevelAdjust(i).hi)
            return folThiefLevelAdjust(i).adj;
    return 0;
}

int Followers::folThiefCountDice() { return 4; }

int Followers::folThiefCountDieSides() { return 6; }

int Followers::folThiefCategoryForD100(int d100) {
    if (d100 <= 50) return 1;
    if (d100 <= 70) return 2;
    if (d100 <= 80) return 3;
    if (d100 <= 90) return 4;
    if (d100 <= 95) return 5;
    return 6;
}

int Followers::folThiefRaceBandCount() { return 7; }

const FollowerThiefRace& Followers::folThiefRace(int i) {
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

int Followers::folThiefRaceForD100(int d100) {
    for (int i = 6; i >= 0; --i)
        if (d100 >= folThiefRace(i).lo) return i;
    return 0;
}

int Followers::folThiefLevelBandCount() { return 7; }

const FollowerThiefLevel& Followers::folThiefLevelBand( int i) {
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

int Followers::folThiefLevelForD100(int d100) {
    for (int i = 6; i >= 0; --i)
        if (d100 >= folThiefLevelBand(i).lo) return i;
    return 0;
}

int Followers::folHumanClassBandCount() { return 5; }

const FollowerHumanClass& Followers::folHumanClass( int i) {
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

int Followers::folDemiHumanBandCount() { return 12; }

const FollowerDemiHuman& Followers::folDemiHuman( int i) {
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

const char* Followers::folThiefOtherProfession( int raceIdx, int d6) {
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

bool Followers::folThiefFollowersAlwaysNeutralGood() {
    return true;
}

int Followers::folAnimalBandCount() { return 5; }

const FollowerCreature& Followers::folAnimal(int i) {
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

int Followers::folMountBandCount() { return 3; }

const FollowerCreature& Followers::folMount(int i) {
    static const FollowerCreature k[3] = {
        { 1, 35, "centaur", 1, 3, 0 },
        { 36, 75, "hippogriff", 1, 1, 0 },
        { 76, 100, "pegasus", 1, 1, 0 }
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

int Followers::folCreatureBandCount() { return 5; }

const FollowerCreature& Followers::folCreature(int i) {
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

int Followers::folSpecialBandCount() { return 5; }

const FollowerCreature& Followers::folSpecial(int i) {
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

int Followers::folAssassinCountDice() { return 7; }

int Followers::folAssassinCountDieSides() { return 4; }

bool Followers::folAssassinAdjustForPopulation() {
    return true;
}

int Followers::folAssassinDesertChance() { return 75; }

bool Followers::folAssassinNewcomersFirstLevel() {
    return true;
}

int Followers::folAssassinRaceBandCount() { return 6; }

const FollowerThiefRace& Followers::folAssassinRace( int i) {
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

int Followers::folAssassinRaceForD100(int d100) {
    for (int i = 5; i >= 0; --i)
        if (d100 >= folAssassinRace(i).lo) return i;
    return 0;
}

int Followers::folAssassinLevelBandCount() { return 8; }

const FollowerAssassinLevel& Followers::folAssassinLevelBand(int i) {
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

int Followers::folAssassinLevelForD100(int d100) {
    for (int i = 7; i >= 0; --i)
        if (d100 >= folAssassinLevelBand(i).lo) return i;
    return 0;
}

int Followers::folAssassinMultiClassChance() {
    return 25;
}

const char* Followers::folAssassinOtherProfession( int raceIdx, int d6) {
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

int Followers::folGrandfatherCountAt(int i) {
    return i + 1;
}

int Followers::folGrandfatherLevelAt(int i) {
    return 8 - i;
}

int Followers::folGrandfatherTotalMidLevel() {
    return 28;
}

int Followers::folGrandfatherFirstLevelMin() {
    return 4;
}

int Followers::folGrandfatherFirstLevelMax() {
    return 16;
}

int Followers::folGrandfatherDisplacedLeaveChance() {
    return 75;
}

int Followers::folGrandfatherNewLeaderMax() { return 44; }

int Followers::folArrivalTensAdjust(int d6) {
    if (d6 <= 2) return 0;
    if (d6 <= 4) return 10;
    return 20;
}

int Followers::folArrivalDayMax() { return 30; }

int Followers::folArrivalIntervalDaysMin() { return 1; }

int Followers::folArrivalIntervalDaysMax() { return 8; }

int Followers::folArrivalWaitDaysMin() { return 1; }

int Followers::folArrivalWaitDaysMax() { return 4; }

bool Followers::folArrivalUnreceivedGoneForever() {
    return true;
}

bool Followers::folHenchmanOrServantMayReceive() {
    return true;
}

int Followers::folPaladinWarhorseMinLevel() { return 4; }

int Followers::folPaladinJourneyMaxDaysRide() { return 7; }

int Followers::folPaladinTaskWeeksMin() { return 2; }

int Followers::folPaladinWarhorseServiceYears() {
    return 10;
}

bool Followers::folPaladinWarhorseMayBeWild() {
    return true;
}

bool Followers::folPaladinGuardedByEvilFighterSameLevel() {
    return true;
}
