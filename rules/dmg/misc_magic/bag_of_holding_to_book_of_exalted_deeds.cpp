// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/bag_of_holding_to_book_of_exalted_deeds.h"

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpHoldingSackShortSideFeet() {
    // a common cloth sack about 2 feet by 4
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpHoldingSackLongSideFeet() {
    // the long side of the 2 by 4 sack
    return 4;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpHoldingRowCount() {
    // the 4 quality rows
    return 4;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpHoldingRuptureCauseCount() {
    // overloaded, or pierced by sharp objects
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpHoldingRowLo(int i) {
    // the d100 band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 31, 71, 91,
    };
    return t[i];
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpHoldingRowHi(int i) {
    // the d100 band upper edges (00 = 100)
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        30, 70, 90, 100,
    };
    return t[i];
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpHoldingRowWeightPounds(int i) {
    // the fixed bag weight by quality; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        15, 15, 35, 60,
    };
    return t[i];
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpHoldingRowWeightLimitPounds(int i) {
    // the contents weight limit by quality; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        250, 500, 1000, 1500,
    };
    return t[i];
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpHoldingRowVolumeLimitCubicFeet(int i) {
    // the volume limit by quality; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        30, 70, 150, 250,
    };
    return t[i];
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTransmutingDisguiseQualityCount() {
    // appears as one of the 4 quality types
    return 4;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTransmutingProperUsesMin() {
    // performs properly for 2-5 uses
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTransmutingProperUsesMax() {
    // the top of the 2-5 use range
    return 5;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTransmutingTransmuteKindCount() {
    // precious metals and gems to no worth
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTransmutingItemBaseMaterialCount() {
    // magic items to lead, glass or wood
    return 3;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTransmutingExemptKindCount() {
    // artifacts and relics exempt
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksTossMinFeet() {
    // withdrawn and tossed 1 to 20 feet away
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksTossMaxFeet() {
    // the top of the 1-20 foot toss
    return 20;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksTypeDieSides() {
    // roll d10 to determine the bag type
    return 10;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksTypeCount() {
    // three type tables
    return 3;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksAnimalsPerType() {
    // 8 animals per type table, die 1-8
    return 8;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksAnimalDieMin() {
    // the animal die low edge
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksAnimalDieMax() {
    // the animal die high edge
    return 8;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksDrawnAtOnceMax() {
    // only 1 creature drawn forth at a time
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksDurationTurns() {
    // exists until slain or 1 turn elapsed
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksEndConditionCount() {
    // slain, or ordered back after the turn
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksTypeRollCount() {
    // one roll only for the bag type
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksWeeklyDrawMax() {
    // up to 10 creatures per week
    return 10;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksTypeLo(int i) {
    // the d10 type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 6, 9,
    };
    return t[i];
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpTricksTypeHi(int i) {
    // the d10 type band upper edges (0 = 10)
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        5, 8, 100,
    };
    return t[i];
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerDoseMin() {
    // compounds from 2-5 doses
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerDoseMax() {
    // the top of the 2-5 dose range
    return 5;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerPotionCountMin() {
    // of from 2-5 potions
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerPotionCountMax() {
    // the top of the 2-5 potion range
    return 5;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerCountDieSides() {
    // roll d4 plus 1 for the potion count
    return 4;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerCountDiePlus() {
    // the +1 on the count die
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerPourRounds() {
    // each pouring takes 1 round
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerPourDoses() {
    // spills forth 1 dose of 1 potion type
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerBadTypeCount() {
    // delusion and poison are possible
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerMonthlyTypeLoss() {
    // one potion type lost per month, permanent
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerDispenseRowMin() {
    // dispensing rows keyed by potions held
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerDispenseRowMax() {
    // the top row key (5 potions)
    return 5;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerPerDayByCount(int i) {
    // row i = potions held - 2; per-day rate,
    // 0 for the 4-5 potion rows; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 1, 0, 0,
    };
    return t[i];
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBeakerPerWeekByCount(int i) {
    // row i = potions held - 2; per-week rate;
    // i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        3, 2, 1, 1,
    };
    return t[i];
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatBoxLengthInches() {
    // the box: 1 foot long
    return 12;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatBoxWidthInches() {
    // the box: half a foot wide
    return 6;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatBoxDepthInches() {
    // the box: half a foot deep
    return 6;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatLengthFeet() {
    // first word: the boat, 10 feet long
    return 10;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatWidthFeet() {
    // the boat, 4 feet wide
    return 4;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatDepthFeet() {
    // the boat, 2 feet deep
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatShipLengthFeet() {
    // second word: the ship, 24 feet long
    return 24;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatShipWidthFeet() {
    // the ship, 8 feet wide
    return 8;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatShipDepthFeet() {
    // the ship, 6 feet deep
    return 6;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatOarPairs() {
    // the boat: 1 pair of oars
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatComponentCount() {
    // oars, anchor, mast, lateen sail
    return 4;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatShipOarSets() {
    // the ship: 5 sets of oars
    return 5;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatShipComponentCount() {
    // rowing seats, oar sets, steering oar,
    // anchor, deck cabin, mast, square sail
    return 7;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatPersonsMin() {
    // the boat holds 3 or 4 persons
    return 3;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatPersonsMax() {
    // the comfortable top
    return 4;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatShipPersons() {
    // the ship carries 15 persons
    return 15;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpBoatCommandWordCount() {
    // third word folds it to a box again
    return 3;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedReadingWeeks() {
    // reading requires 1 week
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedWisdomGain() {
    // the good cleric gains 1 wisdom
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedHalfwayPct() {
    // XP to exactly half way into next level
    return 50;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedNeutralXpLossMin() {
    // neutral clerics lose 20,000-80,000 XP
    return 20000;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedNeutralXpLossMax() {
    // the top of the neutral loss
    return 80000;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedLevelFloor() {
    // negative XP possible, never below 1st
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedEvilLevelLoss() {
    // evil clerics lose 1 full level
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedAtonementPct() {
    // or offer up 50% of everything gained
    return 50;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedAtonementAdventuresMin() {
    // for 2-5 adventures
    return 2;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedAtonementAdventuresMax() {
    // the top of the 2-5 adventures
    return 5;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedMuIntLoss() {
    // magic-users lose 1 intelligence,
    // unless they save versus magic
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedMuSaveXpLossMin() {
    // on a save they lose 2,000-20,000 XP
    return 2000;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedMuSaveXpLossMax() {
    // the top of the save loss
    return 20000;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedThiefHpMin() {
    // the thief takes 5-30 hit points
    return 5;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedThiefHpMax() {
    // the top of the thief damage
    return 30;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedThiefDexLoss() {
    // save or lose 1 dexterity
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedThiefConvertPctMin() {
    // 10%-60% chance to become a good cleric
    return 10;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedThiefConvertPctMax() {
    // the top of the conversion range
    return 60;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedThiefConvertWisReq() {
    // if wisdom is 15 or higher
    return 15;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedAssassinHpMin() {
    // the assassin takes 5-40 hit points
    return 5;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedAssassinHpMax() {
    // the top of the assassin damage
    return 40;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedVanishesAfterPerusal() {
    // once perused the book vanishes
    return 1;
}

int Miscmagic_bag_of_holding_to_book_of_exalted_deeds::mmpExaltedMaxBenefitTimes() {
    // never a second benefit, same character
    return 1;
}
