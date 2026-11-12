// ====================================================================
// Adnd1 - rules/dmg/miscmagic_bag_of_holding_to_book_of_exalted_deeds.h
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

// R-refactor: namespace rules -> class Miscmagic_bag_of_holding_to_book_of_exalted_deeds (instance methods)
class Miscmagic_bag_of_holding_to_book_of_exalted_deeds {
public:
    int mmpHoldingSackShortSideFeet();
    int mmpHoldingSackLongSideFeet();
    int mmpHoldingRowCount();
    int mmpHoldingRuptureCauseCount();
    int mmpHoldingRowLo(int i);
    int mmpHoldingRowHi(int i);
    int mmpHoldingRowWeightPounds(int i);
    int mmpHoldingRowWeightLimitPounds(int i);
    int mmpHoldingRowVolumeLimitCubicFeet(int i);
    int mmpTransmutingDisguiseQualityCount();
    int mmpTransmutingProperUsesMin();
    int mmpTransmutingProperUsesMax();
    int mmpTransmutingTransmuteKindCount();
    int mmpTransmutingItemBaseMaterialCount();
    int mmpTransmutingExemptKindCount();
    int mmpTricksTossMinFeet();
    int mmpTricksTossMaxFeet();
    int mmpTricksTypeDieSides();
    int mmpTricksTypeCount();
    int mmpTricksAnimalsPerType();
    int mmpTricksAnimalDieMin();
    int mmpTricksAnimalDieMax();
    int mmpTricksDrawnAtOnceMax();
    int mmpTricksDurationTurns();
    int mmpTricksEndConditionCount();
    int mmpTricksTypeRollCount();
    int mmpTricksWeeklyDrawMax();
    int mmpTricksTypeLo(int i);
    int mmpTricksTypeHi(int i);
    int mmpBeakerDoseMin();
    int mmpBeakerDoseMax();
    int mmpBeakerPotionCountMin();
    int mmpBeakerPotionCountMax();
    int mmpBeakerCountDieSides();
    int mmpBeakerCountDiePlus();
    int mmpBeakerPourRounds();
    int mmpBeakerPourDoses();
    int mmpBeakerBadTypeCount();
    int mmpBeakerMonthlyTypeLoss();
    int mmpBeakerDispenseRowMin();
    int mmpBeakerDispenseRowMax();
    int mmpBeakerPerDayByCount(int i);
    int mmpBeakerPerWeekByCount(int i);
    int mmpBoatBoxLengthInches();
    int mmpBoatBoxWidthInches();
    int mmpBoatBoxDepthInches();
    int mmpBoatLengthFeet();
    int mmpBoatWidthFeet();
    int mmpBoatDepthFeet();
    int mmpBoatShipLengthFeet();
    int mmpBoatShipWidthFeet();
    int mmpBoatShipDepthFeet();
    int mmpBoatOarPairs();
    int mmpBoatComponentCount();
    int mmpBoatShipOarSets();
    int mmpBoatShipComponentCount();
    int mmpBoatPersonsMin();
    int mmpBoatPersonsMax();
    int mmpBoatShipPersons();
    int mmpBoatCommandWordCount();
    int mmpExaltedReadingWeeks();
    int mmpExaltedWisdomGain();
    int mmpExaltedHalfwayPct();
    int mmpExaltedNeutralXpLossMin();
    int mmpExaltedNeutralXpLossMax();
    int mmpExaltedLevelFloor();
    int mmpExaltedEvilLevelLoss();
    int mmpExaltedAtonementPct();
    int mmpExaltedAtonementAdventuresMin();
    int mmpExaltedAtonementAdventuresMax();
    int mmpExaltedMuIntLoss();
    int mmpExaltedMuSaveXpLossMin();
    int mmpExaltedMuSaveXpLossMax();
    int mmpExaltedThiefHpMin();
    int mmpExaltedThiefHpMax();
    int mmpExaltedThiefDexLoss();
    int mmpExaltedThiefConvertPctMin();
    int mmpExaltedThiefConvertPctMax();
    int mmpExaltedThiefConvertWisReq();
    int mmpExaltedAssassinHpMin();
    int mmpExaltedAssassinHpMax();
    int mmpExaltedVanishesAfterPerusal();
    int mmpExaltedMaxBenefitTimes();
};
