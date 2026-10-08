// ====================================================================
// Adnd1 - rules/miscprose2.h
// R258: the III.E misc magic explanation prose part 2
// pins - part2 lines 5-66, Bag of Holding through
// Book of Exalted Deeds (global line = 11065 +
// part2 line; no page headers inside the slice).
//   - Bag of Holding: the 4-row quality table
//     (01-30: 15/250/30; 31-70: 15/500/70;
//     71-90: 35/1000/150; 91-00: 60/1500/250);
//     overload or a sharp pierce ruptures it,
//     contents lost forever in nilspace.
//   - Bag of Transmuting: appears as one of
//     the 4 quality types; 2-5 proper uses;
//     precious metals and gems to no worth;
//     magic items (except artifacts and
//     relics) to lead, glass or wood, no save.
//   - Bag of Tricks: tossed 1-20 feet; d10
//     type (1-5 / 6-8 / 9-0), 8 animals each;
//     the animal stat columns are mangled in
//     the upload - bands and counts pinned,
//     stats not (the R256 lesson); 1 drawn at
//     a time, slain or 1 turn then ordered
//     back, 10 per week.
//   - Beaker of Plentiful Potions: 2-5 doses
//     of 2-5 potions; d4+1 count; 1 round per
//     pour of 1 dose; delusion and poison
//     possible; 2 potions: 1/day 3/week,
//     3: 1/day 2/week, 4-5: 1/week; 1 potion
//     type lost per month.
//   - Boat, Folding: box 1 x half x half foot
//     (12/6/6 inches); boat 10 x 4 x 2, ship
//     24 x 8 x 6; 1 pair of oars vs 5 sets;
//     3-4 vs 15 persons; 3 command words.
//   - Book of Exalted Deeds: 1 week perusal;
//     good cleric +1 wisdom, halfway XP;
//     neutral 20,000-80,000; evil -1 level
//     plus 50% for 2-5 adventures; MU -1 int
//     or 2,000-20,000; thief 5-30 hp, -1 dex,
//     10-60% conversion at wisdom 15; assassin
//     5-40 hp; vanishes after perusal, one
//     benefit per character.
// The six items are the engine kMisc1 rows
// 10-15 (the R225 m1 band pins) - cross-checked
// in the audit, with the Exalted (C) class mark
// at row 15. Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpHoldingSackShortSideFeet() {
    // a common cloth sack about 2 feet by 4
    return 2;
}

inline int mmpHoldingSackLongSideFeet() {
    // the long side of the 2 by 4 sack
    return 4;
}

inline int mmpHoldingRowCount() {
    // the 4 quality rows
    return 4;
}

inline int mmpHoldingRuptureCauseCount() {
    // overloaded, or pierced by sharp objects
    return 2;
}

inline int mmpHoldingRowLo(int i) {
    // the d100 band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 31, 71, 91,
    };
    return t[i];
}

inline int mmpHoldingRowHi(int i) {
    // the d100 band upper edges (00 = 100)
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        30, 70, 90, 100,
    };
    return t[i];
}

inline int mmpHoldingRowWeightPounds(int i) {
    // the fixed bag weight by quality; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        15, 15, 35, 60,
    };
    return t[i];
}

inline int mmpHoldingRowWeightLimitPounds(int i) {
    // the contents weight limit by quality; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        250, 500, 1000, 1500,
    };
    return t[i];
}

inline int mmpHoldingRowVolumeLimitCubicFeet(int i) {
    // the volume limit by quality; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        30, 70, 150, 250,
    };
    return t[i];
}

inline int mmpTransmutingDisguiseQualityCount() {
    // appears as one of the 4 quality types
    return 4;
}

inline int mmpTransmutingProperUsesMin() {
    // performs properly for 2-5 uses
    return 2;
}

inline int mmpTransmutingProperUsesMax() {
    // the top of the 2-5 use range
    return 5;
}

inline int mmpTransmutingTransmuteKindCount() {
    // precious metals and gems to no worth
    return 2;
}

inline int mmpTransmutingItemBaseMaterialCount() {
    // magic items to lead, glass or wood
    return 3;
}

inline int mmpTransmutingExemptKindCount() {
    // artifacts and relics exempt
    return 2;
}

inline int mmpTricksTossMinFeet() {
    // withdrawn and tossed 1 to 20 feet away
    return 1;
}

inline int mmpTricksTossMaxFeet() {
    // the top of the 1-20 foot toss
    return 20;
}

inline int mmpTricksTypeDieSides() {
    // roll d10 to determine the bag type
    return 10;
}

inline int mmpTricksTypeCount() {
    // three type tables
    return 3;
}

inline int mmpTricksAnimalsPerType() {
    // 8 animals per type table, die 1-8
    return 8;
}

inline int mmpTricksAnimalDieMin() {
    // the animal die low edge
    return 1;
}

inline int mmpTricksAnimalDieMax() {
    // the animal die high edge
    return 8;
}

inline int mmpTricksDrawnAtOnceMax() {
    // only 1 creature drawn forth at a time
    return 1;
}

inline int mmpTricksDurationTurns() {
    // exists until slain or 1 turn elapsed
    return 1;
}

inline int mmpTricksEndConditionCount() {
    // slain, or ordered back after the turn
    return 2;
}

inline int mmpTricksTypeRollCount() {
    // one roll only for the bag type
    return 1;
}

inline int mmpTricksWeeklyDrawMax() {
    // up to 10 creatures per week
    return 10;
}

inline int mmpTricksTypeLo(int i) {
    // the d10 type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 6, 9,
    };
    return t[i];
}

inline int mmpTricksTypeHi(int i) {
    // the d10 type band upper edges (0 = 10)
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        5, 8, 100,
    };
    return t[i];
}

inline int mmpBeakerDoseMin() {
    // compounds from 2-5 doses
    return 2;
}

inline int mmpBeakerDoseMax() {
    // the top of the 2-5 dose range
    return 5;
}

inline int mmpBeakerPotionCountMin() {
    // of from 2-5 potions
    return 2;
}

inline int mmpBeakerPotionCountMax() {
    // the top of the 2-5 potion range
    return 5;
}

inline int mmpBeakerCountDieSides() {
    // roll d4 plus 1 for the potion count
    return 4;
}

inline int mmpBeakerCountDiePlus() {
    // the +1 on the count die
    return 1;
}

inline int mmpBeakerPourRounds() {
    // each pouring takes 1 round
    return 1;
}

inline int mmpBeakerPourDoses() {
    // spills forth 1 dose of 1 potion type
    return 1;
}

inline int mmpBeakerBadTypeCount() {
    // delusion and poison are possible
    return 2;
}

inline int mmpBeakerMonthlyTypeLoss() {
    // one potion type lost per month, permanent
    return 1;
}

inline int mmpBeakerDispenseRowMin() {
    // dispensing rows keyed by potions held
    return 2;
}

inline int mmpBeakerDispenseRowMax() {
    // the top row key (5 potions)
    return 5;
}

inline int mmpBeakerPerDayByCount(int i) {
    // row i = potions held - 2; per-day rate,
    // 0 for the 4-5 potion rows; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 1, 0, 0,
    };
    return t[i];
}

inline int mmpBeakerPerWeekByCount(int i) {
    // row i = potions held - 2; per-week rate;
    // i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        3, 2, 1, 1,
    };
    return t[i];
}

inline int mmpBoatBoxLengthInches() {
    // the box: 1 foot long
    return 12;
}

inline int mmpBoatBoxWidthInches() {
    // the box: half a foot wide
    return 6;
}

inline int mmpBoatBoxDepthInches() {
    // the box: half a foot deep
    return 6;
}

inline int mmpBoatLengthFeet() {
    // first word: the boat, 10 feet long
    return 10;
}

inline int mmpBoatWidthFeet() {
    // the boat, 4 feet wide
    return 4;
}

inline int mmpBoatDepthFeet() {
    // the boat, 2 feet deep
    return 2;
}

inline int mmpBoatShipLengthFeet() {
    // second word: the ship, 24 feet long
    return 24;
}

inline int mmpBoatShipWidthFeet() {
    // the ship, 8 feet wide
    return 8;
}

inline int mmpBoatShipDepthFeet() {
    // the ship, 6 feet deep
    return 6;
}

inline int mmpBoatOarPairs() {
    // the boat: 1 pair of oars
    return 1;
}

inline int mmpBoatComponentCount() {
    // oars, anchor, mast, lateen sail
    return 4;
}

inline int mmpBoatShipOarSets() {
    // the ship: 5 sets of oars
    return 5;
}

inline int mmpBoatShipComponentCount() {
    // rowing seats, oar sets, steering oar,
    // anchor, deck cabin, mast, square sail
    return 7;
}

inline int mmpBoatPersonsMin() {
    // the boat holds 3 or 4 persons
    return 3;
}

inline int mmpBoatPersonsMax() {
    // the comfortable top
    return 4;
}

inline int mmpBoatShipPersons() {
    // the ship carries 15 persons
    return 15;
}

inline int mmpBoatCommandWordCount() {
    // third word folds it to a box again
    return 3;
}

inline int mmpExaltedReadingWeeks() {
    // reading requires 1 week
    return 1;
}

inline int mmpExaltedWisdomGain() {
    // the good cleric gains 1 wisdom
    return 1;
}

inline int mmpExaltedHalfwayPct() {
    // XP to exactly half way into next level
    return 50;
}

inline int mmpExaltedNeutralXpLossMin() {
    // neutral clerics lose 20,000-80,000 XP
    return 20000;
}

inline int mmpExaltedNeutralXpLossMax() {
    // the top of the neutral loss
    return 80000;
}

inline int mmpExaltedLevelFloor() {
    // negative XP possible, never below 1st
    return 1;
}

inline int mmpExaltedEvilLevelLoss() {
    // evil clerics lose 1 full level
    return 1;
}

inline int mmpExaltedAtonementPct() {
    // or offer up 50% of everything gained
    return 50;
}

inline int mmpExaltedAtonementAdventuresMin() {
    // for 2-5 adventures
    return 2;
}

inline int mmpExaltedAtonementAdventuresMax() {
    // the top of the 2-5 adventures
    return 5;
}

inline int mmpExaltedMuIntLoss() {
    // magic-users lose 1 intelligence,
    // unless they save versus magic
    return 1;
}

inline int mmpExaltedMuSaveXpLossMin() {
    // on a save they lose 2,000-20,000 XP
    return 2000;
}

inline int mmpExaltedMuSaveXpLossMax() {
    // the top of the save loss
    return 20000;
}

inline int mmpExaltedThiefHpMin() {
    // the thief takes 5-30 hit points
    return 5;
}

inline int mmpExaltedThiefHpMax() {
    // the top of the thief damage
    return 30;
}

inline int mmpExaltedThiefDexLoss() {
    // save or lose 1 dexterity
    return 1;
}

inline int mmpExaltedThiefConvertPctMin() {
    // 10%-60% chance to become a good cleric
    return 10;
}

inline int mmpExaltedThiefConvertPctMax() {
    // the top of the conversion range
    return 60;
}

inline int mmpExaltedThiefConvertWisReq() {
    // if wisdom is 15 or higher
    return 15;
}

inline int mmpExaltedAssassinHpMin() {
    // the assassin takes 5-40 hit points
    return 5;
}

inline int mmpExaltedAssassinHpMax() {
    // the top of the assassin damage
    return 40;
}

inline int mmpExaltedVanishesAfterPerusal() {
    // once perused the book vanishes
    return 1;
}

inline int mmpExaltedMaxBenefitTimes() {
    // never a second benefit, same character
    return 1;
}

}  // namespace rules

