// R257-R279: the III.E misc magic explanation prose parts 1-23 -
// merged from the 23 part files; each part's bodies verbatim.
#include "rules/dmg/miscmagic_alchemy_jug_to_wings_of_flying.h"

// ---- part 1 (R257): miscmagic_alchemy_jug_to_bag_of_devouring ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIntroMaxDuplicates() {
    // improbable to have more than 2 or 3
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIntroBooksExactWishCount() {
    // a second wish determines exact contents
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAlchemyJugRowCount() {
    // 11 pourable liquids
    return 11;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAlchemyJugKindsPerDay() {
    // only 1 kind of liquid on any given day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAlchemyJugPouringsPerDay() {
    // 7 pourings maximum
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAlchemyJugGallonsPerRound() {
    // pours forth 2 gallons per round
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAlchemyJugRoundsPerLargePouring() {
    // 8 rounds for 1 pouring of salt water
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAlchemyJugRowQty(int i) {
    // salt water 16 gallons, fresh 8, beer 4,
    // vinegar 2, wine 1, ammonia 1 quart, oil
    // 1 pint, aqua regia 2 gills, alcohol 1
    // gill, chlorine 8 drams, cyanide 4 drams
    static const int t[11] = {
        16, 8, 4, 2, 1, 1, 1, 2, 1, 8, 4,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAlchemyJugRowUnit(int i) {
    // 0 gallons, 1 quart, 2 pint, 3 gill,
    // 4 drams
    static const int t[11] = {
        0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletLocationMultiplier() {
    // DOUBLES the likelihood and range (a cursed
    // lure disguised as a protection amulet)
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletLifeProtectionDays() {
    // the psyche is protected for 7 full days
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletPlanesRowCount() {
    // the plane table has 17 rows
    return 17;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletPlanesLowDieFaces() {
    // roll d6: 1-3 do not add 12
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletPlanesHighDieFaces() {
    // add 12 to d12 for 1-24 random results
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletPlanesAddOnHigh() {
    // the added 12 of the 4-6 results
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletPlanesResultMax() {
    // 1-24 random results
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletPlanesAltRowCount() {
    // the alternate results: 3 rows
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletPlanesRowLo(int i) {
    // 1-2 Seven Heavens through 21-24 Prime
    // Material Plane
    static const int t[17] = {
        1, 3, 4, 5, 6, 8, 9, 10, 11, 13, 14,
        15, 16, 18, 19, 20, 21,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletPlanesRowHi(int i) {
    static const int t[17] = {
        2, 3, 4, 5, 7, 8, 9, 10, 12, 13, 14,
        15, 17, 18, 19, 20, 24,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletPlanesAltLo(int i) {
    // alternates: 22 Ethereal, 23 Astral,
    // 24 alternate Earth
    static const int t[3] = {
        22, 23, 24,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAmuletProofNoAuraFlag() {
    // no aura is discernible on the wearer
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishLeverCount() {
    // 10 levers inside
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishForwardInches() {
    // moves forward at 3 inches
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishBackwardInches() {
    // backwards at 6 inches
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishPincerReachFeet() {
    // pincers extend forward 4 feet
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishPincerDamageLo() {
    // snap for 2-12 hit points each
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishPincerDamageHi() {
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishPincerHitPct() {
    // 25% chance, no armor reduction
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishMaxDepthFeet() {
    // operates in waters up to 900 feet
    return 900;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishOccupants() {
    // holds 2 human-sized persons
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishAirHoursLo() {
    // air for 2-5 hours at maximum capacity
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishAirHoursHi() {
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishArmorClass() {
    // the apparatus is AC 0
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishLeakHp() {
    // 100 hit points to cause a leak
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpKwalishStaveHp() {
    // 200 to stave in a side
    return 200;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArrowDirectionUsesPerDay() {
    // tossed into the air once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArrowDirectionRepetitions() {
    // the process can be repeated 7 times
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArrowDirectionTurns() {
    // during the next 7 turns
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArrowDirectionRequestKinds() {
    // stairway, sloping passage, dungeon exit
    // or entrance, cave, cavern
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanExplodeDamageLo() {
    // dumped beans explode for 5-20 hit points
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanExplodeDamageHi() {
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanExplodeRadiusFeet() {
    // all creatures within 10 feet save
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanOptimumLo() {
    // 3-12 beans are optimum
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanOptimumHi() {
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanBeneficialMax() {
    // only 1 or 2 will be beneficial
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanEffectRowCount() {
    // the example bean table has 7 rows
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanBerryCountLo() {
    // the raspberry bush: 5-20 berries
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanBerryCountHi() {
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanBerryGemLo() {
    // berries are gems of 100 or 500 g.p.
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanBerryGemHi() {
    return 500;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanSmokeRadiusFeet() {
    // smoke covers 50 feet radius
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanSmokeTurns() {
    // for 5 turns
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanBlindRoundsLo() {
    // blinded for 1-6 rounds even outside
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanBlindRoundsHi() {
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanGasRadiusFeet() {
    // poison gas cloud of 20 feet radius
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeanGasTurns() {
    // persists for 1 turn
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDevouringIgnorePct() {
    // 90% likely to ignore initial intrusions
    return 90;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDevouringClosePct() {
    // 60% likely to close on living human flesh
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDevouringBaseDrawPct() {
    // base 75% chance to draw the victim in
    return 75;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDevouringDrawModPerPlus() {
    // each +1 damage bonus is -5% on the base
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDevouringExampleStr18Pct() {
    // 18 strength (+2 damage): only 65%
    return 65;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDevouringExampleStr5Pct() {
    // 5 strength (-1 damage): 80%
    return 80;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDevouringCapacityCubicFeet() {
    // holds up to 30 cubic feet of matter
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDevouringSwallowPctPerTurn() {
    // 5% cumulative chance per turn - THE SEAM
    // FACT, completed from part2 line 3
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDevouringConsumeSegments() {
    // creatures drawn within are consumed in
    // 7 segments
    return 7;
}

// ---- part 2 (R258): miscmagic_bag_of_holding_to_book_of_exalted_deeds ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoldingSackShortSideFeet() {
    // a common cloth sack about 2 feet by 4
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoldingSackLongSideFeet() {
    // the long side of the 2 by 4 sack
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoldingRowCount() {
    // the 4 quality rows
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoldingRuptureCauseCount() {
    // overloaded, or pierced by sharp objects
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoldingRowLo(int i) {
    // the d100 band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 31, 71, 91,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoldingRowHi(int i) {
    // the d100 band upper edges (00 = 100)
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        30, 70, 90, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoldingRowWeightPounds(int i) {
    // the fixed bag weight by quality; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        15, 15, 35, 60,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoldingRowWeightLimitPounds(int i) {
    // the contents weight limit by quality; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        250, 500, 1000, 1500,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoldingRowVolumeLimitCubicFeet(int i) {
    // the volume limit by quality; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        30, 70, 150, 250,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTransmutingDisguiseQualityCount() {
    // appears as one of the 4 quality types
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTransmutingProperUsesMin() {
    // performs properly for 2-5 uses
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTransmutingProperUsesMax() {
    // the top of the 2-5 use range
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTransmutingTransmuteKindCount() {
    // precious metals and gems to no worth
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTransmutingItemBaseMaterialCount() {
    // magic items to lead, glass or wood
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTransmutingExemptKindCount() {
    // artifacts and relics exempt
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksTossMinFeet() {
    // withdrawn and tossed 1 to 20 feet away
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksTossMaxFeet() {
    // the top of the 1-20 foot toss
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksTypeDieSides() {
    // roll d10 to determine the bag type
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksTypeCount() {
    // three type tables
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksAnimalsPerType() {
    // 8 animals per type table, die 1-8
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksAnimalDieMin() {
    // the animal die low edge
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksAnimalDieMax() {
    // the animal die high edge
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksDrawnAtOnceMax() {
    // only 1 creature drawn forth at a time
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksDurationTurns() {
    // exists until slain or 1 turn elapsed
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksEndConditionCount() {
    // slain, or ordered back after the turn
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksTypeRollCount() {
    // one roll only for the bag type
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksWeeklyDrawMax() {
    // up to 10 creatures per week
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksTypeLo(int i) {
    // the d10 type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 6, 9,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTricksTypeHi(int i) {
    // the d10 type band upper edges (0 = 10)
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        5, 8, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerDoseMin() {
    // compounds from 2-5 doses
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerDoseMax() {
    // the top of the 2-5 dose range
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerPotionCountMin() {
    // of from 2-5 potions
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerPotionCountMax() {
    // the top of the 2-5 potion range
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerCountDieSides() {
    // roll d4 plus 1 for the potion count
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerCountDiePlus() {
    // the +1 on the count die
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerPourRounds() {
    // each pouring takes 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerPourDoses() {
    // spills forth 1 dose of 1 potion type
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerBadTypeCount() {
    // delusion and poison are possible
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerMonthlyTypeLoss() {
    // one potion type lost per month, permanent
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerDispenseRowMin() {
    // dispensing rows keyed by potions held
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerDispenseRowMax() {
    // the top row key (5 potions)
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerPerDayByCount(int i) {
    // row i = potions held - 2; per-day rate,
    // 0 for the 4-5 potion rows; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 1, 0, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeakerPerWeekByCount(int i) {
    // row i = potions held - 2; per-week rate;
    // i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        3, 2, 1, 1,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatBoxLengthInches() {
    // the box: 1 foot long
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatBoxWidthInches() {
    // the box: half a foot wide
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatBoxDepthInches() {
    // the box: half a foot deep
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatLengthFeet() {
    // first word: the boat, 10 feet long
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatWidthFeet() {
    // the boat, 4 feet wide
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatDepthFeet() {
    // the boat, 2 feet deep
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatShipLengthFeet() {
    // second word: the ship, 24 feet long
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatShipWidthFeet() {
    // the ship, 8 feet wide
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatShipDepthFeet() {
    // the ship, 6 feet deep
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatOarPairs() {
    // the boat: 1 pair of oars
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatComponentCount() {
    // oars, anchor, mast, lateen sail
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatShipOarSets() {
    // the ship: 5 sets of oars
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatShipComponentCount() {
    // rowing seats, oar sets, steering oar,
    // anchor, deck cabin, mast, square sail
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatPersonsMin() {
    // the boat holds 3 or 4 persons
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatPersonsMax() {
    // the comfortable top
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatShipPersons() {
    // the ship carries 15 persons
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBoatCommandWordCount() {
    // third word folds it to a box again
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedReadingWeeks() {
    // reading requires 1 week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedWisdomGain() {
    // the good cleric gains 1 wisdom
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedHalfwayPct() {
    // XP to exactly half way into next level
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedNeutralXpLossMin() {
    // neutral clerics lose 20,000-80,000 XP
    return 20000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedNeutralXpLossMax() {
    // the top of the neutral loss
    return 80000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedLevelFloor() {
    // negative XP possible, never below 1st
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedEvilLevelLoss() {
    // evil clerics lose 1 full level
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedAtonementPct() {
    // or offer up 50% of everything gained
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedAtonementAdventuresMin() {
    // for 2-5 adventures
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedAtonementAdventuresMax() {
    // the top of the 2-5 adventures
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedMuIntLoss() {
    // magic-users lose 1 intelligence,
    // unless they save versus magic
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedMuSaveXpLossMin() {
    // on a save they lose 2,000-20,000 XP
    return 2000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedMuSaveXpLossMax() {
    // the top of the save loss
    return 20000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedThiefHpMin() {
    // the thief takes 5-30 hit points
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedThiefHpMax() {
    // the top of the thief damage
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedThiefDexLoss() {
    // save or lose 1 dexterity
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedThiefConvertPctMin() {
    // 10%-60% chance to become a good cleric
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedThiefConvertPctMax() {
    // the top of the conversion range
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedThiefConvertWisReq() {
    // if wisdom is 15 or higher
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedAssassinHpMin() {
    // the assassin takes 5-40 hit points
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedAssassinHpMax() {
    // the top of the assassin damage
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedVanishesAfterPerusal() {
    // once perused the book vanishes
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExaltedMaxBenefitTimes() {
    // never a second benefit, same character
    return 1;
}

// ---- part 3 (R259): miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteFirstReadHpMin() {
    // non-casters suffer 5-20 hit points
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteFirstReadHpMax() {
    // the top of the first-read damage
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteFirstReadStunTurnsMin() {
    // and are stunned 5-20 turns
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteFirstReadStunTurnsMax() {
    // the top of the stun range
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfinitePageMin() {
    // contains from 23-30 pages
    return 23;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfinitePageMax() {
    // the top of the page range
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfinitePageBase() {
    // 22 + d8 pages
    return 22;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfinitePageDieSides() {
    // the d8 on the page count
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfinitePageRowCount() {
    // the 5-row page table
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfinitePageLo(int i) {
    // the d100 page-band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 31, 51, 61, 96,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfinitePageHi(int i) {
    // the d100 page-band upper edges (00 = 100)
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        30, 50, 60, 95, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteLevelDieSides() {
    // roll d10 for spell level, all but magic-user
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteMuLevelDieSides() {
    // the magic-user level die is a d12
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteLevelRerollLo() {
    // results 8-10 reroll to d6
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteLevelRerollHi() {
    // the top of the 8-10 reroll band
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteMuLevelRerollLo() {
    // magic-user 10-12 reroll to d8
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteMuLevelRerollHi() {
    // the top of the 10-12 reroll band
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteRerollDieSides() {
    // the reroll die
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteMuRerollDieSides() {
    // the magic-user reroll die
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteVanishesAtLastPage() {
    // the last page turned, the book vanishes
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteCastPerDay() {
    // cast the open page once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteCastPerDayIfKnown() {
    // 4 per day if already castable by class
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteTurnPctUsable() {
    // page turns: usable by class and level
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteTurnPctForeign() {
    // foreign to class and/or level
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteTurnPctNonCasterCleric() {
    // non-caster using a cleric spell
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInfiniteTurnPctNonCasterMu() {
    // non-caster using a magic-user spell
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileReadingWeeks() {
    // full consumption requires 1 week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileWisdomGain() {
    // the evil cleric gains 1 wisdom
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileHalfwayPct() {
    // XP to exactly half way into next level
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileNeutralXpLossMin() {
    // neutral clerics lose 30,000-120,000 XP
    return 30000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileNeutralXpLossMax() {
    // or become evil, 50% for either
    return 120000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileNeutralSplitPct() {
    // the either-or chance
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileGoodSaveCount() {
    // good clerics: poison or die, then magic or
    // become permanently insane - two saves
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileGoodXpLossBase() {
    // the good cleric XP loss base
    return 250000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileGoodXpLossPerWis() {
    // less 10,000 per wisdom point
    return 10000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileGoodHandlingHpMin() {
    // other good characters take 5-30 hp
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileGoodHandlingHpMax() {
    // the top of the good handling damage
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileNightHagPct() {
    // 80% a night hag comes if they look inside
    return 80;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileNeutralHandlingHpMin() {
    // non-evil neutral handling: 5-20 hp
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVileNeutralHandlingHpMax() {
    // the top of the neutral handling damage
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDancingDisguisedBootTypeCount() {
    // masquerade as one of the other 4 useful
    // types until melee combat
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDancingTriggerCaseCount() {
    // in melee, or fleeing from the actuality
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDancingAcPenalty() {
    // the armor class penalty
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDancingRemovalSpellCount() {
    // only a remove curse spell frees the wearer
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElvenkindSilencePctWorst() {
    // 95% chance of silence in the worst conditions
    return 95;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElvenkindSilencePctBest() {
    // 100% in the best
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLevitationSpeedInchesPerRound() {
    // the ascent/descent speed per round (the 102
    // seam fact, completed across the page header)
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLevitationWeightIncrementPounds() {
    // d20 in 14 pound increments
    return 14;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLevitationWeightDieSides() {
    // the d20 on the weight capacity
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLevitationWeightBasePounds() {
    // added to a base of 280 pounds
    return 280;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLevitationWeightMinPounds() {
    // 294 pounds at the minimum roll
    return 294;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLevitationWeightMaxPounds() {
    // 560 pounds at the maximum roll
    return 560;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedBaseMovementInches() {
    // the speed of a fast horse, 24 inches base
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedSlowPoundsPerInch() {
    // 1 inch slower per 10 pounds over 200
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedFreeWeightPounds() {
    // the 200 pound free allowance
    return 200;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedExampleHumanPounds() {
    // the example: a 180 pound human
    return 180;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedExampleGearPounds() {
    // with 60 pounds of gear
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedExampleRateInches() {
    // moves at 20 inches base rate
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedSackCoins() {
    // the extra sack of 500 gold pieces
    return 500;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedSackSlowInches() {
    // slows the rate yet another 5 inches
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedRestHoursPerMoveHour() {
    // 1 rest hour per hour of fast movement
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedMaxContinuousHours() {
    // no more than 8 hours continuous
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpeedAcBonus() {
    // +2 to armor class value in combat
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingBaseMovementInches() {
    // base movement rate of 12 inches regardless
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingMaxHoursPerDay() {
    // tirelessly for up to 12 hours per day
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingRechargeHours() {
    // then no function for 12 hours (recharge)
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingNormalPaceFeet() {
    // normal paces are 3 feet long
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingForwardJumpFeet() {
    // forward jumps of up to 30 feet
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingBackwardLeapFeet() {
    // backward leaps of 9 feet
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingVerticalSpringFeet() {
    // vertical springs of 15 feet
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingStumbleBasePct() {
    // base 20% stumble chance
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingStumbleDexAdjPct() {
    // less 3% per point of dexterity above 12
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingStumbleDexThreshold() {
    // the dexterity threshold
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingStumbleRowCount() {
    // the dex ladder rows, 13 through 18
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingStumblePctByDex(int i) {
    // row i = dexterity - 13; the stumble chance;
    // i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        17, 14, 11, 8, 5, 2,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStridingAcBonus() {
    // increases armor class value by 1
    return 1;
}

// ---- part 4 (R260): miscmagic_bowl_commanding_water_elementals_to_bucknards_purse ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBowlCmdHd() {
    // the summoned water elemental
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBowlCmdWordsRounds() {
    // the summoning words take 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBowlCmdSaltBonusPerDie() {
    // salt water: +2 per hit die
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBowlCmdSaltMaxHpPerDie() {
    // salt water: max 8 hp per die
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBowlCmdDiameterInches() {
    // about 1 foot across
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBowlCmdDepthInches() {
    // half the diameter
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWateryDeathSaltSavePenalty() {
    // salt water: the save is at minus 2
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWateryDeathDrownMinRounds() {
    // the victim drowns in 3-8 rounds
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWateryDeathDrownMaxRounds() {
    // the victim drowns in 3-8 rounds
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWateryDeathFreeSpellCount() {
    // animal growth, enlarge, wish
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWateryDeathDeathPermanent() {
    // no resurrection, even a wish fails
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWateryDeathSweetWaterAnotherSave() {
    // a sweet water potion: another save
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBracersDefRowCount() {
    // the random AC table rows
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBracersDefAcMin() {
    // the 86-00 row
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBracersDefAcMax() {
    // the 01-05 row
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDefenselessAc() {
    // lowers armor class to 10
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDefenselessNegatesProtections() {
    // all protections and dex bonuses
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDefenselessRemoveCurseOnly() {
    // only remove curse takes them off
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBrazierFireHd() {
    // the summoned fire elemental
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBrazierFireLightRounds() {
    // lighting the fire usually takes 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBrazierFireSulphurBonusPerDie() {
    // sulphur: +1 on each hit die
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBrazierFireSulphurHpMin() {
    // sulphur: 2-9 hp per die
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBrazierFireSulphurHpMax() {
    // sulphur: 2-9 hp per die
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSleepSmokeRadiusInches() {
    // the smoke cloud radius
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSleepSmokeHd() {
    // the fire elemental that appears
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSleepSmokeAwakenSpellCount() {
    // dispel magic or remove curse
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroochPctWithoutGems() {
    // usually without gems inset
    return 90;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroochAbsorbHp() {
    // absorbs magic missile damage, then melts
    return 101;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomAttackDumpMinFeet() {
    // dumps the rider from 6 feet
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomAttackDumpMaxFeet() {
    // dumps the rider up to 9 feet
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomAttackAttacksPerRound() {
    // each attack twice per round
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomAttackAsHd() {
    // attacks as a 4 hit die monster
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomAttackStrawBlindRounds() {
    // the straw end blinds for 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomAttackHandleDmgMin() {
    // the handle end: 1-3 hp
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomAttackHandleDmgMax() {
    // the handle end: 1-3 hp
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomAttackAc() {
    // the broom armor class
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomAttackHpToDestroy() {
    // hit points to destroy
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomFlySpeedInches() {
    // movement speed
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomFlyCapacityPounds() {
    // carries 182 pounds at speed
    return 182;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomFlyPoundsPerInch() {
    // every 14 pounds slows 1 inch
    return 14;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomFlyClimbDiveDegrees() {
    // climb or dive angle
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBroomFlyFetchSpeedInches() {
    // comes to its owner at up to 30
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPurseCoinsPerType() {
    // 26 of each applicable type, next morning
    return 26;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPurseTypeRowCount() {
    // the type bands
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPurseGemsBaseGp() {
    // base gems
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPurseGemsMaxGp() {
    // gems may increase to 100 at most
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPurseAbilitiesNeverChange() {
    // once rolled, the type never changes
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPurseSpiceNote() {
    // the design note: a constant fund source
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBracersDefBandLo(int i) {
    // printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 6, 16, 36, 51, 71, 86,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBracersDefBandHi(int i) {
    // printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        5, 15, 35, 50, 70, 85, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBracersDefAc(int i) {
    // the armor class per band; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        8, 7, 6, 5, 4, 3, 2,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPurseTypeBandLo(int i) {
    // the type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 51, 91,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPurseTypeBandHi(int i) {
    // the type band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        50, 90, 100,
    };
    return t[i];
}

// ---- part 5 (R261): miscmagic_candle_of_invocation_to_cloak_of_protection ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCandleAlignments() {
    // one candle per alignment
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCandleClericLevelBoost() {
    // same-alignment cleric level, while aflame
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCandleBurnHours() {
    // each candle burns for 4 hours
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCandleGateSpell() {
    // any burning allows a gate; taper consumed
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCarpetRowCount() {
    // the random carpet table rows
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCenserAirHd() {
    // the summoned air elemental
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCenserAirMedBonusPerDie() {
    // incense of meditation: +3 per die
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCenserAirWidthInches() {
    // the half-foot-wide vessel
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCenserAirHeightInches() {
    // the 1-foot-high vessel
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCenserAirTurnsIfExtinguished() {
    // extinguished: elemental remains, turns hostile
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCenserHostileMin() {
    // enraged elementals, minimum
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCenserHostileMax() {
    // enraged elementals, maximum
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCenserHostilePerRound() {
    // elementals appear 1 per round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeOpenLengthInches() {
    // the hollow mithral tube
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeOpenWizardLockLevel() {
    // defeats locks cast below 15th level
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeOpenRoundPerFunction() {
    // one function completes per round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeOpenSoundingsMin() {
    // the fully chained and locked chest
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeOpenSoundingsMax() {
    // the fully chained and locked chest
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeOpenChargesMin() {
    // 20-80 charges, 20 + d6 x 10
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeOpenChargesMax() {
    // 20-80 charges, 20 + d6 x 10
    return 80;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeOpenChargesDieSides() {
    // 20 + d6 x 10
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeOpenChargesDieMult() {
    // 20 + d6 x 10
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeHungerRadiusInches() {
    // ravenous hunger radius
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpChimeHungerMinEatRounds() {
    // must eat at least 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDisplacementMinFeet() {
    // apparent offset, minimum
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDisplacementMaxFeet() {
    // apparent offset, maximum
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDisplacementAcBonus() {
    // 2 classes better, after the first attack
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDisplacementSaveBonus() {
    // saving throw dice bonus
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDisplacementHumanoidPct() {
    // sized for humans or elves
    return 75;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDisplacementSmallPct() {
    // sized for 4-foot persons
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElvenkindRowCount() {
    // the invisibility table rows
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElvenkindOutdoorNaturalRows() {
    // heavy growth, light growth, open fields
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElvenkindOutdoorOtherRows() {
    // rocky terrain, buildings, bright room
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElvenkindUndergroundRows() {
    // torch, infravision, light
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElvenkindHumanoidPct() {
    // human to elven sized cloaks
    return 90;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElvenkindSmallPct() {
    // smaller persons, about 4 feet
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMantaRayLikenessPct() {
    // identical to a manta ray in salt water
    return 90;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMantaRayMoveInches() {
    // moves as a manta ray
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMantaRayAc() {
    // armor class of at least 6
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMantaRayTailDmgMin() {
    // tail spine damage
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMantaRayTailDmgMax() {
    // tail spine damage
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMantaRayTailStun() {
    // no chance of stunning
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMantaRaySaltWaterTrigger() {
    // the cloak adheres in salt water
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPoisonCloakRevivalPctPenalty() {
    // raise dead chance penalty
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPoisonCloakRemoveCurseDestroys() {
    // remove curse removes and destroys the magic
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPoisonCloakNeutralizeNoEffect() {
    // neutralize poison does not affect it
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCloakProtRowCount() {
    // the random plus table rows
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCloakProtAcPerPlus() {
    // armor class better per plus
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCloakProtSavePerPlus() {
    // saving throw added per plus
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCloakProtExampleBaseAc() {
    // the +1 example: AC 10 becomes 9
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCarpetBandLo(int i) {
    // the carpet band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 21, 56, 81,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCarpetBandHi(int i) {
    // the carpet band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        20, 55, 80, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCarpetWidthFeet(int i) {
    // the carpet width; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        3, 4, 5, 6,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCarpetLengthFeet(int i) {
    // the carpet length; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        5, 6, 7, 9,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCarpetPersons(int i) {
    // the carpet capacity; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 3, 4,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCarpetSpeedInches(int i) {
    // the carpet speed; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        42, 36, 30, 24,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElvenkindInvisibilityPct(int i) {
    // invisibility per setting; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        100, 99, 95, 98, 90, 50, 95, 90, 50,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCloakProtBandLo(int i) {
    // the plus band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 36, 66, 86, 96,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCloakProtBandHi(int i) {
    // the plus band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        35, 65, 85, 95, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCloakProtPlus(int i) {
    // the cloak plus per band; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 2, 3, 4, 5,
    };
    return t[i];
}

// ---- part 6 (R262): miscmagic_crystal_balls ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallDiameterInches() {
    // a crystal sphere, half a foot across
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingRowCount() {
    // the subject-is table rows
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingWellKnownPct() {
    // personally well known
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingKnownSlightlyPct() {
    // personally known slightly
    return 85;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingPicturedPct() {
    // pictured
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingPartPct() {
    // part of in possession
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingGarmentPct() {
    // garment in possession
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingWellInformedPct() {
    // well informed of
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingSlightlyInformedPct() {
    // slightly informed of
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingOtherPlanePct() {
    // on another plane: a minus
    return -25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallViewingRowCount() {
    // the viewing period table rows
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallOverrunIntLoss() {
    // past the limits, failed save: int down
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallOverrunInsaneUntilHealed() {
    // driven insane until healed
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallImprovingSpellCount() {
    // comprehend languages, read magic,
    // infravision, tongues
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallCastThroughSpellCount() {
    // detect magic, detect evil per good
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallCastThroughChancePerLevelPct() {
    // cast through the ball, per level
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallFeatureRowCount() {
    // the additional powers table rows
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallSpellFunctionLevel() {
    // the spell function operates at
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallNoticeMinInt() {
    // creatures of int 12 or better notice
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallDetectClassCount() {
    // the notice-by-class table entries
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallIntFactorCount() {
    // int 13 through 18, one rung each
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallDetectPerLevelPct() {
    // cumulative chance per level of experience
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallDetectionTablePage() {
    // spell-users: the detection table page
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallDispelDownDays() {
    // dispel magic: ceases functioning for
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallCheckPerRound() {
    // scrying detection checks each round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallSpellUserClassCount() {
    // cleric, druid, magic-user, illusionist
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallClericDevicesAllowed() {
    // the note: clerics and druids may scry
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallKnowledgeNotDistance() {
    // knowledge is the key, not distance
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallTelepathyCommunicationOnly() {
    // the telepathy ball footnote
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHypnosisBallCursed() {
    // the cursed item type
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHypnosisBallRadiatesEvil() {
    // radiates magic, but NOT evil
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHypnosisBallSuggestionImplanted() {
    // hypnotized, telepathic suggestion implanted
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHypnosisBallIndistinguishable() {
    // indistinguishable from a normal ball
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHypnosisBallInfluencerKindCount() {
    // magic-user, lich, other-planar power
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHypnosisBallFateCount() {
    // servant, tool, or possession object
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHypnosisBallRefereePace() {
    // gradual or sudden, referee decides
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallLocatingPct(int i) {
    // the locating chance; i clamps
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    static const int t[8] = {
        100, 85, 50, 50, 25, 25, 20, -25,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallViewingMinutes(int i) {
    // the viewing period, in minutes; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        60, 30, 30, 30, 15, 10,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallViewingTimesPerDay(int i) {
    // the daily frequency; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 2, 1, 1, 1,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallViewingBandHiPct(int i) {
    // the band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        100, 99, 89, 74, 49, 24,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallFeatureBandLo(int i) {
    // the additional powers band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 51, 76, 91,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallFeatureBandHi(int i) {
    // the band upper edges, 91-00 is 100; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        50, 75, 90, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallFeatureCountAt(int i) {
    // the additional feature count per band; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 2, 3,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallDetectBasePct(int i) {
    // Fighter, Thief, Paladin, Assassin, Ranger,
    // Monk, Bard - the printed table order; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        2, 6, 6, 5, 4, 1, 3,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCrystalBallIntFactorPct(int i) {
    // the cumulative int ladder at int 13-18; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 3, 6, 10, 15, 21,
    };
    return t[i];
}

// ---- part 7 (R263): miscmagic_cube_of_force_to_decanter_of_endless_water ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceWallInches() {
    // wall of force, 1 inch per side
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceCharges() {
    // the cube has 36 charges
    return 36;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceRestoreDays() {
    // energy restored each day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceFaceCount() {
    // six faces, one per screen strength
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceSurchargeFormCount() {
    // the attack-form surcharge table entries
    return 14;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceSpellsInOutBlocked() {
    // no casting into or out of the cube
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceMaterialCount() {
    // hard mineral, ivory, bone
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeFrostSideInches() {
    // encloses 1 inch per side
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeFrostTempF() {
    // always 65 degrees F inside
    return 65;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeFrostColdAttackCount() {
    // cone of cold, ice storm, dragon breath
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeFrostCollapseHp() {
    // more than this per turn: collapse
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeFrostTurnRounds() {
    // a turn is 10 rounds
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeFrostRenewHours() {
    // after collapse: no renewal for
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeFrostDestroyHp() {
    // over this in 1 turn: destroyed
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeFrostColdPer10BelowF() {
    // 2 hp of cold per minus 10 degrees
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeFrostAt40BelowHp() {
    // at minus 40 F: withstands only
    return 42;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubicGateSideCount() {
    // the 6 sides, each keyed to a plane
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubicGatePrimeSides() {
    // one side is always Prime Material
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubicGateChosenSides() {
    // the other 5 are chosen
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubicGateNexusChancePct() {
    // per turn, something comes through
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubicGateDrawRadiusFeet() {
    // second press draws all within
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubicGateMaxLinks() {
    // no more than 1 nexial link at once
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernSquareFeet() {
    // the tower footprint, square
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernHeightFeet() {
    // the tower height
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernGroundDepthFeet() {
    // metal extends into the ground
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernCollapseHp() {
    // damage before the tower collapses
    return 200;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernWishRepairHp() {
    // a wish restores this much damage
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernSpringRounds() {
    // springs up in but 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernGrowthDamageMin() {
    // caught by the growth: minimum
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernGrowthDamageMax() {
    // caught by the growth: maximum
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernDoorOwnerOnly() {
    // opens only to the owner command
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernNormalWeaponsAffect() {
    // normal weapons do NOT affect the walls
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDaernDamageCumulative() {
    // sustained damage is cumulative
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDecanterModeCount() {
    // stream, fountain, geyser
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDecanterStreamGallonsPerRound() {
    // stream pours per round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDecanterFountainLengthFeet() {
    // the fountain stream length
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDecanterFountainGallonsPerRound() {
    // fountain pours per round
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDecanterGeyserLengthFeet() {
    // the geyser stream length
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDecanterGeyserGallonsPerRound() {
    // geyser pours per round
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDecanterWaterTypeCount() {
    // fresh or salt, as ordered
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDecanterGeyserKnockover() {
    // geyser back pressure knocks over
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDecanterStopsOnCommand() {
    // the command word ceases the flow
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceCostPerTurn(int i) {
    // the face charge cost; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 2, 3, 4, 6, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceMoveInches(int i) {
    // the face movement rate; 0 is normal; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 8, 6, 4, 3, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCubeForceSurchargeAt(int i) {
    // the attack-form surcharges, row-major
    // print order; i clamps
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    static const int t[14] = {
        1, 3, 2, 4, 6, 8, 3, 3, 6, 5, 3, 7, 3, 2,
    };
    return t[i];
}

// ---- part 8 (R264): miscmagic_deck_of_many_things ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckPlaqueMaterialCount() {
    // plaques of ivory or vellum
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckMinDraws() {
    // announce only 1 draw, or
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckMaxDraws() {
    // opt for 2, 3, or even 4
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckJesterBonusDraws() {
    // the jester: 2 additional cards
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckBasePlaqueCount() {
    // the 13-plaque pack
    return 13;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckFullPlaqueCount() {
    // the 22-plaque pack
    return 22;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckBaseChancePct() {
    // 13 plaques at 75 percent
    return 75;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckFullChancePct() {
    // 22 plaques at 25 percent
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckAsteriskPlaqueCount() {
    // the 22-pack extras, asterisk-marked
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckDiscardPlaqueCount() {
    // jester and fool are discarded
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckBoldFaceStopCount() {
    // The Void and Donjon stop the deck
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckTablePlaqueCount() {
    // the printed plaque table rows
    return 22;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckSunXp() {
    // the Sun: beneficial item and
    return 50000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckMoonWishesMin() {
    // Moon grants 1-4 wishes
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckMoonWishesMax() {
    // Moon grants 1-4 wishes
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckMoonSpellLevel() {
    // same as the ninth level spell
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckStarPoints() {
    // Star: 2 points on the major ability
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckStarMaxScore() {
    // if the 2 points would place the score at
    return 19;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckStarFallbackOrderCount() {
    // con, cha, wis, dex, int, str
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckCometMidpointProgress() {
    // success: mid-point of the next level
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckThroneCharisma() {
    // Throne: charisma of
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckThroneReactionBonusPct() {
    // already-18: still +25 percent reactions
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckKeyMapBonusPct() {
    // Key: treasure map at +20 percent
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckKeyWeaponCount() {
    // Key: a treasure map plus
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckKnightLevel() {
    // Knight: a 4th level fighter
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckKnightBonusPerDie() {
    // the hero: +1 per die
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckKnightAbilityMax() {
    // the hero ability roll caps at
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckGemJewelryCount() {
    // Gem: your choice of 20 jewelry
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckGemGemCount() {
    // Gem: or 50 gems
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckGemGemBaseGp() {
    // the gems: base value
    return 1000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckGemXpLevelCap() {
    // never more than 1 level rise
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckEuryaleSavePenalty() {
    // Euryale: minus 3 on petrification saves
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckRogueHenchmenAlienated() {
    // Rogue: 1 henchman alienated
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckJesterXp() {
    // Jester: gain 10,000 xp instead
    return 10000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckJesterExtraDraws() {
    // Jester: or 2 more draws
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckFoolXp() {
    // Fool: lose 10,000 xp
    return 10000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckIdiotIntLossMin() {
    // Idiot: lose 1-4 int
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckIdiotIntLossMax() {
    // Idiot: lose 1-4 int
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckSkullDeathAc() {
    // the minor Death AC (negative)
    return -4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckSkullDeathHp() {
    // the minor Death hit points
    return 33;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckSkullScytheDmgMin() {
    // the scythe: 2-16 hit points
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckSkullScytheDmgMax() {
    // the scythe: 2-16 hit points
    return 16;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckSkullUndeadForSpells() {
    // treat the Death as undead
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckFatesPartyEndures() {
    // the party must still endure it
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckDonjonGearStripped() {
    // Donjon: all gear and spells stripped
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckPlaqueAsterisk(int i) {
    // the 22-pack extras by row; i clamps
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    static const int t[22] = {
        0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
        0, 0, 0, 1, 0, 1, 1, 1, 1, 1,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckPlaqueBoldFace(int i) {
    // The Void (8) and Donjon (21); i clamps
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    static const int t[22] = {
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeckPlaqueDiscarded(int i) {
    // Jester (16) and Fool (17); i clamps
    if (i < 0) i = 0;
    if (i > 21) i = 21;
    static const int t[22] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
    };
    return t[i];
}

// ---- part 9 (R265): miscmagic_drums_of_deafening_to_eyes_of_petrification ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumDeafDeafRangeInches() {
    // both drums: permanent deafness radius
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumDeafStunRangeInches() {
    // the stun zone radius
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumDeafStunMinRounds() {
    // stunned for from 2-8 rounds
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumDeafStunMaxRounds() {
    // stunned for from 2-8 rounds
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumDeafHemisphereHalfFeet() {
    // each drum: 1.5 feet diameter hemisphere
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumPanicRangeInches() {
    // both drums: the panic radius
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumPanicSafeZoneInches() {
    // the safe zone radius from the drums
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumPanicFleeTurns() {
    // move directly away for 1 full turn
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumPanicRestRoundsPerTurn() {
    // 3 rounds of rest per 1 turn of flight
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumPanicInt2SaveMod() {
    // intelligence of 2 saves at -2
    return -2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumPanicInt1SaveMod() {
    // intelligence of 1 or less saves at -4
    return -4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDrumPanicHemisphereHalfFeet() {
    // each drum: 1.5 feet diameter hemisphere
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustAppearDurationMinTurns() {
    // appearance lasts for 2-20 turns
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustAppearDurationMaxTurns() {
    // appearance lasts for 2-20 turns
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustAppearPacketRadiusFeet() {
    // a packet covers a 10 feet radius
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustAppearTubeStartFeet() {
    // the cone: 1 feet wide at the start
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustAppearTubeEndFeet() {
    // the cone: 15 feet wide at the end
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustAppearTubeLengthFeet() {
    // the cone: 20 feet long
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustAppearContainerMin() {
    // from 5 to 50 containers in one place
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustAppearContainerMax() {
    // from 5 to 50 containers in one place
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustGoneDurationMinTurns() {
    // invisibility lasts 2 to 20 turns
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustGoneDurationMaxTurns() {
    // invisibility lasts 2 to 20 turns
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustGoneSprinkleMinTurns() {
    // carefully sprinkled: 11-20 turns
    return 11;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustGoneSprinkleMaxTurns() {
    // carefully sprinkled: 11-20 turns
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustGoneAcBonusPlaces() {
    // armor class 4 places better
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustChokeRadiusFeet() {
    // the sneezing fits radius
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustChokeDisabledMinRounds() {
    // survivors disabled 5-20 rounds
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDustChokeDisabledMaxRounds() {
    // survivors disabled 5-20 rounds
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEfreetiInsanePct() {
    // 10 percent insane, attacks at once
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEfreetiWishesPct() {
    // 10 percent grants 3 wishes only
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEfreetiServePct() {
    // the other 80 percent serves normally
    return 80;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEfreetiWishCount() {
    // the wishes-only bottle grants 3
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEfreetiReleaseSegments() {
    // issues from the bottle in but 1 segment
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEversmokeFirstRoundCubicFeet() {
    // obscures a 50000 cubic foot area
    return 50000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEversmokePerRoundCubicFeet() {
    // 10000 cubic feet more each round
    return 10000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEversmokeMaxCubicFeet() {
    // until 120000 cubic feet are fogged
    return 120000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesCharmTargetsPerRound() {
    // one person per round can be looked at
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesCharmBothSaveMod() {
    // both lenses: saves at -2
    return -2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesCharmOneSaveMod() {
    // only 1 of a pair: saves at +2
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesEagleVisionFactor() {
    // vision 100 times greater than normal
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesEagleMinDistanceFeet() {
    // at distances of 1 feet or more
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesEagleSeeAtFeet() {
    // sees at 2000 feet
    return 2000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesEagleNormalSeeFeet() {
    // what normal sight does at 20 feet
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesEagleSingleStunRounds() {
    // one cusp: dizzy, stunned, for 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesMinuteVisionFactor() {
    // see 100 times better at 1 feet or less
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesMinuteMaxDistanceFeet() {
    // only within 1 feet
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesPetrifyBasiliskGazePct() {
    // 25 percent work as basilisk gaze
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesMixInsanityMinTurns() {
    // mixing eye types: insanity 2-8 turns
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesMixInsanityMaxTurns() {
    // mixing eye types: insanity 2-8 turns
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesMixInsanityDice() {
    // the insanity lasts 2-8 (2d4) turns
    return 2;
}

// ---- part 10 (R266): miscmagic_figurines_of_wondrous_power ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFigTypeCount() {
    // the printed figurine type table rows
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFigStatuetteInchesHigh() {
    // a statuette of small size, an inch or so
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFigTypeLo(int i) {
    // the printed type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 16, 31, 41, 56, 66, 86,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFigTypeHi(int i) {
    // the printed type band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        15, 30, 40, 55, 65, 85, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlyAc() {
    // the ebony fly armor class
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlyHitDiceBase() {
    // 4 + 4 hit dice: the base
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlyHitDiceExtra() {
    // 4 + 4 hit dice: the plus
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlyAirManeuverClass() {
    // air maneuverability class C, the 3rd letter
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlySpeedUnladenInches() {
    // flies at 48 inches without a rider
    return 48;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlySpeedLadenInches() {
    // 36 inches carrying up to 210 pounds
    return 36;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlySpeedMaxLoadInches() {
    // 24 inches carrying from 211 to 350 pounds
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlyLadenMaxPounds() {
    // the 36 inch band carries up to 210 pounds
    return 210;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlyMaxLoadPounds() {
    // the 24 inch band carries up to 350 pounds
    return 350;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlyUsesPerWeek() {
    // a maximum of 3 times per week
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlyHoursPerDay() {
    // 12 hours per day
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLionCount() {
    // the pair becomes 2 adult male lions
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLionAcFront() {
    // lion armor class 5/6: the front
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLionAcRear() {
    // lion armor class 5/6: the rear
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLionHitDiceBase() {
    // 5 + 2 hit dice: the base
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLionHitDiceExtra() {
    // 5 + 2 hit dice: the plus
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLionSlainReturnWeeks() {
    // slain: no statuette return for 1 full week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLionUseDays() {
    // otherwise usable once every day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatCount() {
    // the trio of statuettes
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatUsesBeforeBurnout() {
    // after 3 uses each goat loses its magic
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelAc() {
    // the travelling mount armor class
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelHp() {
    // the travelling mount hit points
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelAttacks() {
    // 2 attacks, the horns
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelHornDmgMin() {
    // horns for 1-8 each
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelHornDmgMax() {
    // horns for 1-8 each
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelHitDice() {
    // consider as a 4 hit dice monster
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelMoveInches() {
    // moves at 48 inches
    return 48;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelMaxLoadPounds() {
    // bearing 280 pounds or less
    return 280;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelPoundsPerMoveLoss() {
    // minus 1 inch per 14 extra pounds
    return 14;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelHoursPerWeek() {
    // 1 day each week, totalling 24 hours
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravelRestDays() {
    // small form for not less than 1 day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailHoofDmgMin() {
    // sharp hooves 4-10/4-10
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailHoofDmgMax() {
    // sharp hooves 4-10/4-10
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailBiteDmgMin() {
    // the vicious bite 2-8
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailBiteDmgMax() {
    // the vicious bite 2-8
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailHornDmgMin() {
    // the horns 2-12/2-12 (print: 2- 12)
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailHornDmgMax() {
    // the horns 2-12/2-12 (print: 2- 12)
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailChargeBonus() {
    // charging: +6 damage added to each hit
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailChargeHornMin() {
    // charging horns: 8-18 per horn
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailChargeHornMax() {
    // charging horns: 8-18 per horn
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailAc() {
    // armor class 0
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailHp() {
    // 96 hit points
    return 96;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailHitDice() {
    // attacks as a 16 hit dice monster
    return 16;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailUsesPerMonth() {
    // called to life but once per month
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTravailMoveInches() {
    // it moves 24 inches
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTerrorMoveInches() {
    // the destrier-like mount moves 36 inches
    return 36;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTerrorAc() {
    // armor class 2
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTerrorHp() {
    // 48 hit points
    return 48;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTerrorHornSpearBonus() {
    // one horn as a +3 spear (lance)
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTerrorHornSwordBonus() {
    // the other horn as a +6 sword
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTerrorRadiusInches() {
    // radiates terror in a 3 inch radius
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTerrorStrengthLossPct() {
    // save or lose 50 percent of strength
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTerrorHitPenalty() {
    // and at least -3 on to hit dice
    return -3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGoatTerrorIntervalWeeks() {
    // used once every 2 weeks
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElephantTypeLo(int i) {
    // the elephant type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 51, 91, 94,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElephantTypeHi(int i) {
    // the elephant type band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        50, 90, 93, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElephantHoursPerUse() {
    // 24 hours at a time
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpElephantUsesPerMonth() {
    // 4 times per month
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSteadGoodRiderPct() {
    // good rider: 10 percent per use to Hades
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSteadHoursPerUse() {
    // a 24 hour period maximum
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSteadUsesPerWeek() {
    // once per week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogIntMin() {
    // intelligence of 8-10: the low
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogIntMax() {
    // intelligence of 8-10: the high
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogScentFreshPct() {
    // scents a known trail 100 percent if fresh
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogScentFreshHours() {
    // fresh means 1 hour or less old
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogScentDecayPctPerHour() {
    // minus 10 percent per hour thereafter
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogInfravisionFeet() {
    // 90 feet range infravision
    return 90;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogSpotHiddenPct() {
    // spots hidden things 80 percent
    return 80;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogSpotInvisiblePct() {
    // spots invisible things 65 percent
    return 65;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogSpotPhasedPct() {
    // notes astral, ethereal, out-of-phase 50 percent
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogHoursPerUse() {
    // up to 6 continuous hours
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDogUsesPerWeek() {
    // once per week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlAc() {
    // the normal-sized horned owl AC
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlMoveInches() {
    // 24 inch move
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlHpMin() {
    // 2-4 hit points: the low
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlHpMax() {
    // 2-4 hit points: the high
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlDmgMin() {
    // 1-2/1-2 damage: the low
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlDmgMax() {
    // 1-2/1-2 damage: the high
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlGiantUses() {
    // the giant owl form limited to 3 times
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlSilencePct() {
    // the normal form moves with 95 percent silence
    return 95;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlInfravisionFeet() {
    // infravision to 90 feet
    return 90;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlDarkVisionFactor() {
    // sees dark as full light, twice a human
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlHearMouseFeet() {
    // detects a mouse moving at 60 feet
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlCounterStealthPct() {
    // silent movement vs the owl reduced 50 percent
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlIntMin() {
    // low 2-4 intelligence: the low
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOwlIntMax() {
    // low 2-4 intelligence: the high
    return 4;
}

// ---- part 11 (R267): miscmagic_flask_of_curses_to_girdle_of_giant_strength ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskCurseOnFirstOpen() {
    // first unstoppering visits a curse nearby
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskHarmlessAfterUse() {
    // subsequently the flask is harmless
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntDexBoostLow() {
    // +4 dexterity if at 6 or less
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntDexBoostMid() {
    // +2 dexterity if at 7-13
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntDexBoostHigh() {
    // +1 dexterity if at 14 or higher
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntDexThiefLevel() {
    // non-thieves act as a 4th level thief
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntDexThiefBonusPct() {
    // thieves gain +10 percent for their level
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntFumbDropPct() {
    // 50 percent each round of dropping held items
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntFumbDexPenalty() {
    // lowers overall dexterity by 2 points
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntFumbRemoveCurseOnly() {
    // only remove curse or a wish takes them off
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntOgreStrength() {
    // 18/00 strength in hands, arms and shoulders
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntOgreStrengthPercentile() {
    // the 18/00 exceptional percentile
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntOgreHitBonus() {
    // +3 to hit probability
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntOgreDmgBonus() {
    // +6 to damage inflicted
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntSwimUnderwaterInches() {
    // swims as a triton: 15 inches under water
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntSwimSurfaceInches() {
    // swims as a merman: 18 inches on the surface
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntSwimClimbSuccessPct() {
    // 95 percent of not slipping while climbing
    return 95;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGauntSwimThiefSuccessTenthPct() {
    // a thief climbs at 99.5 percent (tenths)
    return 995;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightLightSorts() {
    // the gem emits bright light of 3 sorts
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightConeLengthFeet() {
    // the pale light cone is 10 feet long
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightConeRadiusHalfFeet() {
    // cone radius 2.5 feet at the beam end
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightRayDiameterFeet() {
    // the bright ray is 1 feet diameter
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightRayLengthFeet() {
    // the bright ray is 50 feet long
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightDazzleMinRounds() {
    // dazzled 1-4 rounds
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightDazzleMaxRounds() {
    // dazzled 1-4 rounds
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightRayCharges() {
    // the ray use expends 1 energy charge
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightFlashLengthFeet() {
    // the blinding flash cone is 30 feet long
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightFlashRadiusFeet() {
    // flash cone radius 5 feet at its terminus
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightBlindMinRounds() {
    // blinded 1-4 rounds
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightBlindMaxRounds() {
    // blinded 1-4 rounds
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightEyePenaltyMin() {
    // permanent eye damage: -1 at least
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightEyePenaltyMax() {
    // permanent eye damage: up to -4
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightFlashCharges() {
    // the flash use expends 5 charges
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightTotalCharges() {
    // 50 charges, cannot be recharged
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightDarknessDrainCharges() {
    // a darkness spell drains 1 charge
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightDarknessRoundUseless() {
    // or makes the gem useless for 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightDarknessDayUseless() {
    // continual darkness: useless for 1 day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemBrightDarknessExpelCharges() {
    // or the owner expends 5 charges
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemSeeCursoryRangeInches() {
    // cursory scan range 30 inches
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemSeeCarefulRangeInches() {
    // small things: 10 inches
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemSeeCursoryAreaFeet() {
    // 1 round scans a 200 feet square
    return 200;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemSeeCursoryRounds() {
    // the cursory scan takes 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemSeeCarefulAreaFeet() {
    // 2 rounds view a 100 feet square
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemSeeCarefulRounds() {
    // the careful view takes 2 rounds
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGemSeeHallucinationPct() {
    // 5 percent chance of an hallucination
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleSexWishRestorePct() {
    // a wish restores the sex: 50 percent
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleSexSexlessPct() {
    // 10 percent of these remove all sex
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantTypeCount() {
    // the six giant strength types
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantRockDmgMin() {
    // every type hurls rocks from 1 die
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantDiceLo(int i) {
    // the type dice band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 31, 51, 71, 86, 96,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantDiceHi(int i) {
    // the type dice band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        30, 50, 70, 85, 95, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantStrength(int i) {
    // the strength and rating column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        19, 20, 21, 22, 23, 24,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantHitBonus(int i) {
    // the to hit column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 4, 4, 5, 6,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantDmgBonus(int i) {
    // the damage column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 8, 9, 10, 11, 12,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantOpenDoorsTop(int i) {
    // open doors numerator (7 in 8); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 7, 9, 11, 11, 19,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantOpenDoorsBottom(int i) {
    // open doors denominator (in 8); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        8, 8, 10, 12, 12, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantOpenChances(int i) {
    // the parenthesized chances (3 of 6); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 4, 4, 5, 7,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantOpenOutOf(int i) {
    // chances out of 6 (8 for storm); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 6, 6, 6, 6, 8,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantWeightAllowance(int i) {
    // the weight allowance column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4500, 5000, 6000, 7500, 9000, 12000,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantRangeInches(int i) {
    // the rock range column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        8, 16, 10, 12, 14, 16,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantRockDmgMax(int i) {
    // the rock base damage top die; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 12, 8, 8, 10, 12,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantRockWeight(int i) {
    // the approximate average missile weight; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        140, 198, 156, 170, 184, 212,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGirdleGiantBendBarsPct(int i) {
    // bend bars and lift gates percent; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        50, 60, 70, 80, 90, 100,
    };
    return t[i];
}

// ---- part 12 (R268): miscmagic_helm_of_brilliance_to_horn_of_bubbles ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilCommandWordOnly() {
    // functions only upon the utterance of a
    // special command word
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilTrueNatureVisible() {
    // when empowered the true nature of the helm
    // is visible to all
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilArmorPlus() {
    // the helm is armor of +2 value
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilDiamondCount() {
    // set with 10 diamonds of large size
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilRubyCount() {
    // 20 rubies
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilFireOpalCount() {
    // 30 fire opals
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilOpalCount() {
    // 40 opals
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilScintillatesInBrightLight() {
    // struck by bright light it scintillates and
    // sends reflective rays from the crown-like
    // spikes set with gems
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilJewelUseSegments() {
    // each gem performs its spell-like power in
    // but 1 segment
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilJewelUsableOnce() {
    // each gem is usable only once
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilUsesPerRound() {
    // the helm may be thus used once per round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilSpellLevelDoublingFactor() {
    // the level of the spell is doubled for range,
    // duration and such considerations
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilUndeadGlowRangeFeet() {
    // glows with a bluish light when undead are
    // within 30 feet
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilUndeadPainDmgMin() {
    // the light causes pain and damage to undead
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilUndeadPainDmgMax() {
    // 1-6 points of damage
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilUndeadExemptKinds() {
    // save skeletons and zombies take neither
    // the pain nor the damage
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilFlameSwordEffectRounds() {
    // 1 round of time is required to effect
    // this fire
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilFlameSwordAdditional() {
    // the sword of flame is additional to the
    // other special properties of the sword,
    // if any
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilProduceFlameDruidLevel() {
    // the wearer may produce flame just as if
    // a 5th level druid
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilFireResistRingStrength() {
    // protected just as if a double strength
    // fire resistance ring were worn
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilFireResistAugmentable() {
    // this protection cannot be augmented by
    // further magical means
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilPowderOnExpenditure() {
    // once all jewels lose their magic the helm
    // loses its powers and the gems turn to
    // worthless powder
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilJewelRemovalDestroys() {
    // removing a jewel destroys the gem
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilJewelRemagickable() {
    // the gems may not be re-magicked
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilRetrySaveWithoutMagic() {
    // a failed save versus a magical fire attack
    // demands another saving throw for the
    // helmet without magical additions
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilOverloadDetonatesRemaining() {
    // if the helmet save fails the remaining
    // gems all overload and detonate
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilOverloadEffectsInMultiple() {
    // the detonation causes in multiple
    // whatever effects the gems would
    // normally have
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilJewelRowCount() {
    // the restored jewel functions table rows
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilJewelGemCount(int i) {
    // the stones set per gem row; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        10, 20, 30, 40,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilJewelSpellLevel(int i) {
    // the restored spell levels: 7th, 5th,
    // 3rd, 1st; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        7, 5, 3, 1,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilJewelCasterKind(int i) {
    // 0 illusionist, 1 druid, 2 magic-user,
    // 3 cleric; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 2, 3,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmBrilJewelFunctionKind(int i) {
    // 0 prismatic spray, 1 wall of fire,
    // 2 fireball, 3 light; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 2, 3,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmComprStrangeTonguesPct() {
    // understand 90 percent of strange tongues
    // and writings
    return 90;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmComprMagicalWritingsPct() {
    // 80 percent of magical writings
    return 80;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmComprAllOrNone() {
    // the figures apply to whether all or none
    // of the tongue or inscription is
    // understandable
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmComprImpliesSpellUse() {
    // understanding does not necessarily imply
    // spell use
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmComprHelmetOfAcValue() {
    // equal to a normal helmet of the type
    // accompanying armor class 5
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmOppAlignIndeterminateDweomer() {
    // by test it radiates an indeterminate
    // dweomer
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmOppAlignCurseOnDonning() {
    // once placed upon the head the curse
    // immediately takes place
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmOppAlignAbsoluteKinds() {
    // neutral goes to some absolute
    // commitment: LE, LG, CE or CG
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmOppAlignAlterationDesired() {
    // the alteration, once effected, is
    // desired by the individual the magic
    // changed
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmOppAlignRestoreSpellKinds() {
    // only a wish, or alter reality, can
    // restore the former alignment
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmOppAlignSelfRestoreAttempts() {
    // the affected individual will make no
    // attempt to return to the former
    // alignment
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmOppAlignPaladinQuestAndAtone() {
    // a paladin must undergo a special quest
    // and atone for the curse to be
    // obliterated
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmOppAlignPowersAfterFunctioning() {
    // once functioned the helm loses all of
    // its magical properties
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathyRangeInches() {
    // the thoughts of creatures within a
    // 6 inch range
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathyStoneBarrierFeet() {
    // no more than 3 feet of solid stone
    // between the wearer and the creatures
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathyIronBarrierQuarterFeet() {
    // a quarter foot of iron
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathyLeadGoldSheetBlocks() {
    // any solid sheeting of lead or gold
    // blocks the pick-up entirely
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathyDirectional() {
    // the thought pick-up is directional
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathyConsciousEffort() {
    // conscious effort must be made to pick
    // up thoughts
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathySuggestPctPer2IntAbove() {
    // for every 2 points of intelligence
    // greater than the subject the wearer is
    // 5 percent more likely to implant
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathySuggestPctPer1IntBelow() {
    // for every 1 point lower the probability
    // decreases by 5 percent
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathySavePenaltyPer2IntBelow() {
    // the subject saves versus magic with a
    // minus 1 for every 2 points of
    // intelligence lower than the telepathist
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathySaveBonusPer1IntAbove() {
    // the subject saves with a plus 1 for
    // every 1 point of intelligence higher
    // than the wearer of the helm
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathyEqualIntSaveAdjustment() {
    // if intelligence is equal no adjustment
    // is made
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathyPsionicAttackBonus() {
    // a plus 4 with respect to psionic related
    // attacks
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTelepathyPsionicStrengthBonus() {
    // increases total psionic strength by
    // 40 points
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTeleportPerDay() {
    // the wearer may teleport once per day,
    // exactly as if a magic-user: destination
    // known, a risk involved
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTeleportMuRefreshRepeats() {
    // a magic-user may memorize the spell and
    // use the helm to refresh memory,
    // repeating the spell up to 3 times
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTeleportMuStillPersonalAfterRefresh() {
    // and still be able to personally
    // teleport by means of the helm
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTeleportMuUncastPersonalCount() {
    // while the spell is retained uncast the
    // magic-user can personally teleport up
    // to 6 times before the memory is lost
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmTeleportUsageAfterMemoryLost() {
    // even then a usage of the helm remains
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmUnderwaterSeeAndBreathe() {
    // the possessor is able to both see and
    // breathe under water
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmUnderwaterLensCompartments() {
    // small lenses drawn across the device
    // from compartments on either side
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmUnderwaterVisionFactor() {
    // see 5 times farther than normal water
    // and light conditions allow for normal
    // human vision
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmUnderwaterObstructionsBlock() {
    // weeds, obstructions and such block
    // vision in the usual manner
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHelmUnderwaterAirGlobeUntilRepeat() {
    // the command word creates a globe of air
    // around the head, maintained until the
    // word is again spoken
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingConeLengthInches() {
    // a cone of sound 12 inches long
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingConeBaseWidthInches() {
    // 3 inches wide at the base
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingSaveStunRounds() {
    // those saving versus magic are stunned
    // for 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingSaveDeafRounds() {
    // those saving are deafened for 2
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingFailDmgMin() {
    // those failing the save sustain damage
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingFailDmgMax() {
    // 1-10 hit points of damage
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingFailStunRounds() {
    // those failing are stunned for 2 rounds
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingFailDeafRounds() {
    // those failing are deafened for 4
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingPulseWidthFeet() {
    // a wave of ultrasonic sound, a 1 foot
    // wide pulse
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingPulseLengthInches() {
    // the pulse is 10 inches long
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingCatapultMultiplier() {
    // the weakening of metal, stone and wood
    // equals 3 times a large catapult
    // missile hit
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingCatapultHitDamage() {
    // the large catapult missile hit damage
    // (derived: 18 structural at triple)
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingStructuralPoints() {
    // 18 structural points, sufficient to
    // smash a drawbridge or flatten a normal
    // cottage
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingExplodePctPerExtraUse() {
    // winded magically more than once per
    // day: a 10 percent cumulative chance to
    // explode itself
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingExplodeDmgMin() {
    // the explosion inflicts 5-50 hit points
    // of damage on the person sounding it
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingExplodeDmgMax() {
    // the 5-50 upper edge
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingCharges() {
    // there are no charges upon a horn
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingShiverPctPerUse() {
    // each magical use: a 2 percent
    // cumulative chance of shivering itself
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBlastingShiverWielderDamage() {
    // a shiver inflicts no damage on the
    // character blowing it
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBubblesBlindRoundsMin() {
    // the bubbles surround and blind the
    // individual who blew the horn
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBubblesBlindRoundsMax() {
    // blinded for 2-20 rounds
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBubblesOnlyWhenSlayerSeeks() {
    // the bubbles only appear in the presence
    // of a creature actively seeking to slay
    // the character who winded the horn
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornBubblesAppearanceMayDelay() {
    // the appearance might be delayed for a
    // very short or extremely lengthy period
    return 1;
}

// ---- part 13 (R269): miscmagic_horn_of_collapsing_to_incense_of_meditation ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseMisfirePct() {
    // sounded without the proper rune, or 10
    // percent of the time in any event
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseOutRocksMin() {
    // outside: a rain of fist-sized rocks
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseOutRocksMax() {
    // from 2-12 in number
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseOutRockDmgMin() {
    // each rock causes 1-6 hit points of damage
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseOutRockDmgMax() {
    // the 1-6 upper edge
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseIndoorDmgMin() {
    // indoors: the ceiling collapses on the character
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseIndoorDmgMax() {
    // 3-36 hit points of damage
    return 36;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseUnderDmgMin() {
    // underground: the material above falls
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseUnderDmgMax() {
    // 5-20 hit points base damage
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseUnderHeightFactorFeet() {
    // the base damage is multiplied by 1 factor for
    // each 10 feet of drop height (twice at 20 feet,
    // three times at 30 feet, etc.)
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseAimRangeMinFeet() {
    // proper use: point at the roof overhead from
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseAimRangeMaxFeet() {
    // 30 to 60 feet beyond the user
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseRoofWidthFeet() {
    // collapses a roof section up to 20 feet wide
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseRoofLengthFeet() {
    // and 20 feet long
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseRoofRadiusFeet() {
    // a 10 feet radius from the central aiming point
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornCollapseIndoorsOrUndergroundOnly() {
    // the aimed collapse inflicts damage only if
    // indoors or underground
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonPerDay() {
    // a conch shell horn blown but once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonTritonPerDay() {
    // except by a triton who can sound it 3 times
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonFunctionCount() {
    // any 1 of the following functions
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonCalmRadiusMiles() {
    // calm rough waters in a 1 mile radius
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonCalmDispelKinds() {
    // dispels a water elemental or water weird
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonSummonKindCount() {
    // hippocampi, giant sea horses, sea lions
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonSummonDieLo(int i) {
    // the selection die band lower edges: 1-2 the
    // hippocampi, 3-5 the sea horses, 6 the lions;
    // i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        1, 3, 6,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonSummonDieHi(int i) {
    // the selection die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        2, 5, 6,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonSummonCountMin(int i) {
    // the creatures summoned lower edges: 5-20
    // hippocampi, 5-30 sea horses, 1-10 sea lions;
    // i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        5, 5, 1,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonSummonCountMax(int i) {
    // the summon upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        20, 30, 10,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonPanicAnimalOrLower() {
    // panics marine creatures with animal, or
    // lower, intelligence
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonPanicToHitPenalty() {
    // those who save take a minus 5 on to hit dice
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonPanicTurnsMin() {
    // the penalty lasts 3-18 turns
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonPanicTurnsMax() {
    // the turns upper edge
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonPanicRoundsPerTurn() {
    // 3-18 turns is 30-180 rounds: 10 rounds per
    // turn
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonPanicRoundsMin() {
    // the 30 rounds lower edge
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonPanicRoundsMax() {
    // the 180 rounds upper edge
    return 180;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornTritonHearRadiusLeagues() {
    // any sounding is heard by all tritons within
    // a 1 league radius
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaVarietyCount() {
    // there are 4 varieties of this magical device
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaBlowIntervalDays() {
    // each variety can be blown but once every 7
    // days
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaSummonedAc() {
    // the fighters summoned are armor class 4
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaSummonedHpPerDie() {
    // they have 6 hit points per die
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaSwordSpearPct() {
    // armed with sword and spear 50 percent
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaAxeSpearPct() {
    // or battle axe and spear 50 percent
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaServiceTurns() {
    // they fight until slain or 6 turns have
    // elapsed, whichever occurs first
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaAlignedPct() {
    // fully 50 percent of these horns are aligned
    // and summon only same-alignment fighters
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaBronzeXpMultiplier() {
    // the base 1,000 xp is doubled for a bronze
    // horn - the row 20 double asterisk
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaIronXpMultiplier() {
    // and tripled for an iron horn
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaDiceLo(int i) {
    // the variety dice band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 9, 16, 19,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaDiceHi(int i) {
    // silver 1-8, brass 9-15, bronze 16-18, iron
    // 19-20; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        8, 15, 18, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaCountMin(int i) {
    // berserk fighters summoned lower edges;
    // i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        4, 3, 2, 2,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaCountMax(int i) {
    // the 4-10, 3-9, 2-8, 2-5 upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        10, 9, 8, 5,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaLevel(int i) {
    // the summoned fighter levels: 2nd, 3rd, 4th,
    // 5th; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        2, 3, 4, 5,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaUsableAny(int i) {
    // the silver horn is usable by any class; i
    // clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaUsableCleric(int i) {
    // the (C) employ marks; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 1, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaUsableFighter(int i) {
    // the (F) employ marks; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 1, 1,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHornValhallaUsableThief(int i) {
    // the (T) employ marks; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 0, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesSpeedShoeCount() {
    // 4 normal-appearing iron horse shoes
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesSpeedFullPct() {
    // affixed, they double the animal speed (the
    // 200 percent full rate)
    return 200;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesSpeedDropPct() {
    // a 1 percent chance per 7 leagues travelled
    // that 1 shoe drops off
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesSpeedDropLeagues() {
    // the drop interval in leagues
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesSpeedOneLostPct() {
    // one lost and unnoticed: 150 percent of the
    // normal rate
    return 150;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesSpeedTwoLostPct() {
    // 2 lost: the speed is normal
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesZephyrGroundless() {
    // the horse travels without touching the
    // ground
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesZephyrNoTracks() {
    // water can be passed over and no tracks are
    // made on any sort of ground
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesZephyrNoTireHours() {
    // the horse will not tire for 12 hours of
    // continuous riding
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHorseshoesZephyrPerDay() {
    // per day of continuous riding
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedRecognizeClericLevel() {
    // the smoke is recognizable by any cleric of
    // 5th or higher level
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedPrayHours() {
    // the cleric spends 8 hours praying and
    // meditating nearby
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedCureAlwaysMax() {
    // cure wounds spells are always maximum
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedBroadestArea() {
    // spell effects are of the broadest area
    // possible
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedSavePenalty() {
    // saving throws against the effects are at
    // minus 1
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedNotSurvivingDivisor() {
    // the revived dead reduce their chance of not
    // surviving by one-half (rounded down)
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedPieceCountMin() {
    // discovered with from 2-8 pieces of incense
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedPieceCountMax() {
    // the piece count upper edge
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedBurnHours() {
    // one piece burns for 8 hours
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIncenseMedEffectHours() {
    // the effects remain for 24 hours
    return 24;
}

// ---- part 14 (R270): miscmagic_incense_of_obsession_to_fochlucan_bandore ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpObsessionDurationHours() {
    // the cleric remains obsessed until all spells
    // are cast or 24 hours have elapsed
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpObsessionPiecesMin() {
    // there are 2-8 pieces of this incense normally
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpObsessionPiecesMax() {
    // the upper edge of the normal 2-8 pieces
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpObsessionBurnHours() {
    // each piece burns for 1 hour
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounSortCount() {
    // there are 14 sorts of useful ioun stones
    return 14;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounOwnerRadiusFeet() {
    // the stones must be within 3 feet of their
    // owner to be efficacious
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounOrbitMinFeet() {
    // the circling orbit starts at a 1 foot radius
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounOrbitMaxFeet() {
    // the circling orbit tops at a 3 foot radius
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounFoundMin() {
    // from 1-10 ioun stones will be found
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounFoundMax() {
    // the upper edge of the 1-10 found
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounTableRowCount() {
    // the property table has 15 rows
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounDeadRowLo() {
    // the dull gray dead band starts at roll 15
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounDeadRowHi() {
    // and ends at roll 20
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounStatBonusPoints() {
    // the six stat stones add 1 point to the score
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounStatCap() {
    // with an 18 maximum
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounStatBonusRowCount() {
    // six stones add to a stat score
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounLevelGainLevels() {
    // the pale green prism adds 1 level of
    // experience
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounRegenHpPerTurn() {
    // the pearly white spindle regenerates 1 hit
    // point of damage per turn
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounPurpleStoreMin() {
    // the vibrant purple prism stores 2-12 levels
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounPurpleStoreMax() {
    // the upper edge of the stored 2-12 levels
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounRoseProtectionBonus() {
    // the dusty rose prism gives +1 protection
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounGrayPsionicBonus() {
    // the dead gray stone adds 10 points to the
    // psionic strength total
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounGrayPsionicCap() {
    // the psionic strength total caps at 50 points
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounHpToDestroy() {
    // the stones take 10 hit points of damage to
    // destroy
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounSaveBonus() {
    // they save as if they were of hard metal, +3
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounAttackAc() {
    // exposed to attack they are treated as armor
    // class -4 (the minus rides the comment)
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounRowRollLo(int i) {
    // the printed roll lower edges, rolls 1-14
    // then the dead band; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounRowRollHi(int i) {
    // the printed roll upper edges, the dead band
    // topping at 20; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounRowAddsStat(int i) {
    // the rolls 1-6 stones add to a stat score;
    // i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounRowAbsorbMaxLevel(int i) {
    // the roll 11 and 12 stones absorb spells up
    // to the 4th and 8th level; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        4, 8, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounRowBurnoutMin(int i) {
    // the absorbed spell levels that burn a
    // stone out, the lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        10, 20, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpIounRowBurnoutMax(int i) {
    // the absorbed spell levels that burn a
    // stone out, the upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 14) i = 14;
    static const int t[15] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        40, 80, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBardInstrumentCount() {
    // there are 7 magical instruments
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanStringCount() {
    // the small, 3-stringed bandore
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanLowestFaeriePct() {
    // a 1st level bard or a non-bard: a 50
    // percent chance per round of playing to
    // cast a faerie fire spell
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanLowestReversePct() {
    // a 10 percent chance the musician is
    // limned by the glow instead
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanFaerieBasePct() {
    // a bard of Fochlucan or higher college
    // casts the faerie fire at base 50 percent
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanReverseReductionPerLevelPct() {
    // the reverse effect reduced by 1 percent
    // per level above 1st
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanSongCount() {
    // the bandore has 4 song properties when
    // properly played
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanCharmBonusPct() {
    // adds 10 percent to the bard charm
    // percentage
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanEntanglePerDay() {
    // casts an entangle spell once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanShillelaghPerDay() {
    // casts a shillelagh spell once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanSpeakAnimalsPerDay() {
    // enables the bard to speak with animals
    // once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanLowestSongWorkPct() {
    // a 1st level bard attempts the powers: a
    // 30 percent chance they work
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanLowestSongFailPct() {
    // a 70 percent chance of the mishap
    return 70;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanLowestFailDamageMin() {
    // the mishap deals 2-8 hit points of damage
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFochlucanLowestFailDamageMax() {
    // the upper edge of the 2-8 damage
    return 8;
}

// ---- part 15 (R271): miscmagic_mac_fuirmidh_cittern_to_instrument_type_table ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCitternMisusePct() {
    // 50 percent likely to deliver the damage to any
    // non-bard or bard under 5th level
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCitternDamageMin() {
    // the misuse delivers 3-12 hit points
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCitternDamageMax() {
    // the upper edge of the 3-12 damage
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCitternLevelGate() {
    // a bard of 5th or higher level uses it safely
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCitternCharmBonusPct() {
    // a 15 percent better chance of charming
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCitternSongCount() {
    // three songs once per day
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDossMisusePct() {
    // 60 percent likely, any non-bard or bard under
    // 8th level
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDossDamageMin() {
    // the misuse delivers 4-16 hit points
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDossDamageMax() {
    // the upper edge of the 4-16 damage
    return 16;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDossLevelGate() {
    // an 8th or higher level bard plays the lute
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDossCharmBonusPct() {
    // a 20 percent better chance of charming
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDossSongCount() {
    // three magical songs once per day
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDossProtFireRadiusFeet() {
    // the protection from fire song in a 10 feet
    // radius
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCanaithMisusePct() {
    // 70 percent likely, any non-bard or bard under
    // the 11th level
    return 70;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCanaithDamageMin() {
    // the misuse causes 5-20 hit points
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCanaithDamageMax() {
    // the upper edge of the 5-20 damage
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCanaithLevelGate() {
    // an 11th or higher level bard employs it
    return 11;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCanaithCharmBonusPct() {
    // adds 25 percent to the charming ability
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCanaithSongCount() {
    // three spells once per day
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCanaithProtLightningRadiusFeet() {
    // the protection from lightning song in a 10
    // feet radius
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCliMisusePct() {
    // 80 percent likely, any non-bard or bard of
    // less than the 14th level
    return 80;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCliDamageMin() {
    // the misuse causes 6-24 hit points
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCliDamageMax() {
    // the upper edge of the 6-24 damage
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCliLevelGate() {
    // a 14th or higher level bard plays the lyre
    return 14;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCliCharmBonusPct() {
    // adds 30 percent to charming ability
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpCliSongCount() {
    // three songs once each per day
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAnstruthMisusePct() {
    // 90 percent likely, any non-bard or bard of
    // less than 17th level
    return 90;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAnstruthDamageMin() {
    // the misuse causes 8-32 hit points
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAnstruthDamageMax() {
    // the upper edge of the 8-32 damage
    return 32;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAnstruthLevelGate() {
    // a 17th or higher level bard strums it
    return 17;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAnstruthCharmBonusPct() {
    // adds 35 percent to charming abilities
    return 35;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAnstruthSongCount() {
    // three spells, one each per day
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOllamhDamageMin() {
    // a non-bard or bard under 20th level: it
    // WILL inflict 10-40 hit points (no percent
    // printed, the harm is certain)
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOllamhDamageMax() {
    // the upper edge of the certain 10-40 damage
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOllamhLevelGate() {
    // a bard of 20th or higher level plays it
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOllamhCharmBonusPct() {
    // adds 40 percent to the charming abilities
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOllamhSongCount() {
    // three spells, one each daily
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentAbilityCount() {
    // four abilities: protection from evil,
    // invisibility, levitate, fly
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentAbilityRadiusFeet() {
    // the protection from evil in a 10 feet radius
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentAbilityPerDay() {
    // each ability once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentActivateSegments() {
    // each ability takes 5 segments to activate
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentCompleteRounds() {
    // and not less than 1 full round to complete
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentCollegeTurnsMin() {
    // the abilities last as many turns as the
    // college order, the low edge of 1-7
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentCollegeTurnsMax() {
    // the high edge of the college order turns
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentMagnusTurns() {
    // a magnus alumni sings for 8 turns with any
    // of the 7
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentCharmExcessThresholdPct() {
    // when the charming ability exceeds 100
    // percent with the instrument bonus
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentCharmExcessStepPct() {
    // the saving throw penalty per every 5
    // percent above, 3-4 rounding to the next 5
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentCharmExcessPenaltyPerStep() {
    // the creature saves at -1 for every step
    // above 100 percent
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentKindRowCount() {
    // the type table has 7 rows
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentDieLo(int i) {
    // the type die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 6, 10, 13, 16, 18, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInstrumentDieHi(int i) {
    // the type die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        5, 9, 12, 15, 17, 19, 20,
    };
    return t[i];
}

// ---- part 16 (R272): miscmagic_iron_flask_to_keoghtoms_ointment ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskRangeInches() {
    // the command range is 6 inches
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskMaxCreatures() {
    // only 1 creature at a time can be held
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskServiceTurns() {
    // forced service lasts 1 turn
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskServiceHours() {
    // a minor service up to 1 hour of time
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskRepeatSaveBonus() {
    // a second forcing attempt saves at +2
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskContentsRowCount() {
    // 19 bands, empty through xorn
    return 19;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskContentsLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        1, 51, 55, 57, 58, 60, 61, 66, 70, 73,
        77, 82, 84, 86, 87, 90, 94, 98, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFlaskContentsHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    static const int t[19] = {
        50, 54, 56, 57, 59, 60, 65, 69, 72, 76,
        81, 83, 85, 86, 89, 93, 97, 99, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningPlus() {
    // equal to a +2 magic weapon, no bonuses
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningRangeInches() {
    // the range is 9 inches
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningStrokeWidthHalfInches() {
    // the stroke is one half inch wide
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningStrokeLengthInches() {
    // the stroke is 3 inches long
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningDamageMin() {
    // the struck target takes 1-6 hit points
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningDamageMax() {
    // the upper edge of the 1-6 damage
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningElectricalDamage() {
    // plus 20 hit points of electrical damage
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningBackstrokeMin() {
    // the back stroke deals 10 or 20
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningBackstrokeMax() {
    // the upper edge of the back stroke
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningBackstrokeInches() {
    // drawn 3 inches back toward the hurler
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningFoundMin() {
    // from 2-5 will be found
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinLightningFoundMax() {
    // the upper edge of the 2-5 find
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinPiercingRangeInches() {
    // range 6 inches, all distances short
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinPiercingToHitBonus() {
    // +6 to hit
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinPiercingDamageMin() {
    // the strike inflicts 7-12 hit points
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinPiercingDamageMax() {
    // the upper edge of the 7-12 damage
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinPiercingFoundMin() {
    // from 2-8 will be found
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinPiercingFoundMax() {
    // the upper edge of the 2-8 find
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJavelinPiercingThrows() {
    // the magic is good for only 1 throw
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJewelAttacksWanderingPct() {
    // 100 percent more wandering monsters
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJewelAttacksPursuitPct() {
    // 100 percent greater pursuit likelihood
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJewelFlawlessBoostPct() {
    // the value likelihood rises 100 percent
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJewelFlawlessBaseTenths() {
    // 1 in 10 stones rise unboosted
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJewelFlawlessBoostedTenths() {
    // 2 in 10 stones rise boosted
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJewelFlawlessFacetMin() {
    // the jewel has 10-100 facets
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJewelFlawlessFacetMax() {
    // the upper edge of the 10-100 facets
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJewelFlawlessTriggerD10() {
    // a roll of 2 on d10 raises a stone
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpJewelFlawlessFacetsLostPerBoost() {
    // 1 facet disappears per raised stone
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOintmentJarDiameterInches() {
    // the jar is three inches in diameter
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOintmentJarDepthInches() {
    // the jar is one inch deep
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOintmentApplications() {
    // the jar contains 5 applications
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOintmentHealMin() {
    // rubbed on it heals 9-12 points
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOintmentHealMax() {
    // the upper edge of the 9-12 healing
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOintmentFoundMin() {
    // 1-3 jars will commonly be found
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpOintmentFoundMax() {
    // the upper edge of the 1-3 jars
    return 3;
}

// ---- part 17 (R273): miscmagic_librams_lyre_and_manuals ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLibramStudyWeeks() {
    // a full week of cloistered study
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLibramMisuseDamageMin() {
    // a non-neutral reader takes 5-20 damage
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLibramMisuseDamageMax() {
    // the upper edge of the 5-20 damage
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLibramUnconsciousTurnsMin() {
    // unconscious a like number of turns
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLibramUnconsciousTurnsMax() {
    // the upper edge of the like-number turns
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLibramInsanityRestMonths() {
    // the insane reader rests 1 month
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLibramDamnationLevelLoss() {
    // a non-evil look inside loses 1 level
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreNegateKindCount() {
    // horn of blasting, disintegrate, elemental
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreNegateRounds() {
    // negates 6 rounds of earth elemental attack
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreNegatePerDay() {
    // the negatory chords play once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreBuildPerWeek() {
    // the building chords strum once per week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreBuildTurns() {
    // 3 turns of such playing
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreBuildMen() {
    // equal to the work of 100 men
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreBuildDays() {
    // 100 men laboring for 3 days
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreFalseChordPct() {
    // a false chord negates 20 percent likely
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreFalseChordKnownPct() {
    // only 5 percent once the proper ones known
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLyreFalseChordDisturbedPct() {
    // disturbed while playing rises to 50 percent
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHealthReadHours() {
    // the read takes 24 hours of time
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHealthReadDaysMin() {
    // over 3-5 days
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHealthReadDaysMax() {
    // the upper edge of the 3-5 days
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHealthConGain() {
    // the regimen raises constitution by 1 point
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHealthRegimenMonths() {
    // the diet and breathing run 1 month
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHealthForgetMonths() {
    // the secrets fade in 3 months
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpExerciseStrGain() {
    // the course adds 1 point of strength
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemKindCount() {
    // 4 sorts of golems
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemMinUserLevel() {
    // the maker assumed 10th or higher
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemFailurePctPerLevel() {
    // cumulative 10 percent per level under 10th
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemFailureWindowTurns() {
    // falls to pieces within 1 turn of completion
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemClericXpLossMin() {
    // a cleric reading loses 10,000 xp
    return 10000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemClericXpLossMax() {
    // up to 60,000 xp lost
    return 60000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemMuLevelLoss() {
    // a magic-user reading loses 1 level
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemOtherDamageMin() {
    // any other class suffers 6-36 damage
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemOtherDamageMax() {
    // the upper edge of the 6-36 damage
    return 36;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemDieLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 6, 18, 19,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemDieHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        5, 17, 18, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemMonths(int i) {
    // the construction months per golem sort; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 4, 3,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpGolemCostGp(int i) {
    // the construction cost per golem sort; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        65000, 50000, 100000, 80000,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPuissantPracticeMonths() {
    // the fighter practices 1 month
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPuissantForgetMonths() {
    // the knowledge fades within 3 months
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPuissantStunTurnsMin() {
    // a scanning magic-user is stunned 1-6 turns
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPuissantStunTurnsMax() {
    // the upper edge of the 1-6 turn stun
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPuissantXpLossMin() {
    // the scanning magic-user loses 10,000 xp
    return 10000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPuissantXpLossMax() {
    // up to 60,000 xp lost
    return 60000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpQuicknessStudyDays() {
    // 3 days of uninterrupted study
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpQuicknessPracticeMonths() {
    // the skills practiced 1 month
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpQuicknessDexGain() {
    // the practice gains 1 point of dexterity
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpQuicknessRememberMonths() {
    // the contents remembered 3 months
    return 3;
}

// ---- part 18 (R274): miscmagic_manual_of_stealthy_pilfering_to_necklace_of_missiles ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyPracticeMonths() {
    // the thief practices 1 month thereafter
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyKnowledgeMonths() {
    // the knowledge is retained for 3 months
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyAssassinXp() {
    // an assassin gains but 5,000 additional xp
    return 5000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyAssassinWeeks() {
    // the contents pondered for 1 week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyWrongDamageMin() {
    // a wrong-class reader takes 5-20 damage
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyWrongDamageMax() {
    // the upper edge of the 5-20 damage
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyStunRoundsMin() {
    // stunned a like number of rounds
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyStunRoundsMax() {
    // the upper edge of the like-number rounds
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyXpLossMin() {
    // a failed save loses 5,000-20,000 xp
    return 5000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyXpLossMax() {
    // the upper edge of the 5,000-20,000 xp loss
    return 20000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyAtoneDays() {
    // must atone within 1 day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStealthyWisdomLoss() {
    // or lose 1 point of wisdom
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMattockLengthFeet() {
    // the huge digging tool is 10 feet long
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMattockWeightLb() {
    // and weighs over 100 pounds
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMattockMinStrength() {
    // a giant-sized user of strength 20 or more
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMattockEarthCubicFeet() {
    // loosens earth in a 100 cubic foot area
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMattockRockCubicFeet() {
    // smashes rock in a 20 cubic feet area
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMattockAreaTurns() {
    // either area in 1 turn of work
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMattockHitBonus() {
    // +3 to hit as a weapon
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMattockDamageMin() {
    // does 5-30 damage, strength bonuses aside
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMattockDamageMax() {
    // the upper edge of the 5-30 damage
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulLengthFeet() {
    // the huge mallet is 8 feet long
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulWeightLb() {
    // and weighs over 150 pounds
    return 150;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulMinStrength() {
    // a giant-sized user of strength 21 or greater
    return 21;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulPileDiameterFeet() {
    // drives piles of up to 2 feet diameter
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulPileDepthFeet() {
    // into normal earth at 4 feet per blow
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulBlowsPerRound() {
    // 2 blows per round
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulDoorHeightFeet() {
    // an oaken door of up to 10 feet height
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulDoorWidthFeet() {
    // by 4 feet width
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulDoorThicknessInches() {
    // by 2 inch thickness
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulDoorBlows() {
    // smashed to flinders in 1 blow
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulDoorIronBlows() {
    // 2 blows if heavily bound with iron
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulHitBonus() {
    // +2 to hit as a weapon
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulDamageMin() {
    // inflicts 10-40 damage, strength bonuses aside
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMaulDamageMax() {
    // the upper edge of the 10-40 damage
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspPathWidthFeet() {
    // the path is 1 foot wide at the medallion
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspBroadenFeet() {
    // broadening 2 feet every 10 feet of reach
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspBroadenPerFeet() {
    // every 10 feet from the device
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspMaxWidthFeet() {
    // up to an 11 foot maximum width
    return 11;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspMaxWidthAtFeet() {
    // the maximum reached at 50 feet
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspUseRounds() {
    // a full round to use the device
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspStoneBlockFeet() {
    // stone of over 3 feet thickness blocks
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspMetalBlockSixthsFeet() {
    // metal of over 1/6 foot thickness blocks
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspMalfunctionRoll() {
    // malfunctions on a die roll of 6
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspMalfunctionDieSides() {
    // the roll is on d6, checked each use
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 16, 19, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        15, 18, 19, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspRangeFeet(int i) {
    // the medallion range per type; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        30, 30, 60, 90,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEspEmpathy(int i) {
    // the with-empathy mark per type; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        0, 1, 0, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProjectionWorksRoll() {
    // correct without projecting on a roll of 6
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTrapAreaSquareFeet() {
    // the crystal device about 4 square feet
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTrapCellMin() {
    // from 13 compartments at the fewest
    return 13;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTrapCellMax() {
    // to 18 compartments at the most
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTrapTriggerFeet() {
    // a looker coming within 30 feet
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTrapSeePctUnaware() {
    // 100 percent when unaware of the device
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTrapSeePctAvoiding() {
    // dropping to 50 when actively avoiding
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTrapSeePctAware() {
    // and 20 when aware it traps life
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTrapOverflowFreed() {
    // 1 random victim freed on overflow
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProwessQuestionsPerWeek() {
    // answers one short question per week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProwessWidthFeet() {
    // the typical mirror 5 feet by
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProwessHeightFeet() {
    // 2 feet
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAdaptationAirlessDays() {
    // exists in airless space for up to 7 days
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpMissileRangeInches() {
    // the globes hurled up to 7 inches distance
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpNeckRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 5, 9, 13, 17, 19, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpNeckRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        4, 8, 12, 16, 18, 19, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpNeckDieOf(int i) {
    // the hit dice column ladder; i clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        11, 10, 9, 8, 7, 6, 5, 4, 3, 2,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpNeckCell(int i) {
    // the flattened count table, the row-major
    // index i = row * 10 + column, the columns
    // running the 11-dice through 2-dice ladder;
    // the 9-12 row reads the printed example:
    // one 7-dice, two 5-dice, four 3-dice; clamps
    if (i < 0) i = 0;
    if (i > 69) i = 69;
    static const int t[70] = {
        0, 0, 0, 0, 0, 0, 1, 0, 2, 0,
        0, 0, 0, 0, 0, 1, 0, 2, 0, 2,
        0, 0, 0, 0, 1, 0, 2, 0, 4, 0,
        0, 0, 0, 1, 0, 2, 0, 2, 0, 4,
        0, 0, 1, 0, 2, 0, 2, 0, 2, 0,
        0, 1, 0, 2, 0, 2, 0, 4, 0, 0,
        1, 0, 2, 0, 2, 0, 2, 0, 2, 0,
    };
    return t[i];
}

// ---- part 19 (R275): miscmagic_necklace_of_prayer_beads_to_periapts ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadStoneMin() {
    // the necklace consists of 25-30 stones
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadStoneMax() {
    // the upper edge of the 25-30 stones
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadSemiPreciousPct() {
    // 60 percent semi-precious stones
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadFancyPct() {
    // 40 percent fancy stones
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadPetitionBonusPct() {
    // 25 percent more likely to petition the deity
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadSpecialMin() {
    // 3-6 special beads
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadSpecialMax() {
    // the upper edge of the 3-6 special beads
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadGemBaseGp() {
    // precious stones of 1,000 gp base value
    return 1000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadUsesPerDay() {
    // each special bead once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadKarmaLevels() {
    // the karma bead casts 4 levels higher
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadSummonsPct() {
    // the summons bead calls the deity at 90 percent
    return 90;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 6, 11, 16, 18, 19,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBeadRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        5, 10, 15, 17, 18, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpStrangleDamagePerRound() {
    // 6 hit points of strangulation damage per round
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntrapMinStrength() {
    // defies strength under 20
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntrapCutAc() {
    // equal to AC -10 against cutting blows
    return -10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntrapSizeFeet() {
    // each net is 10 feet square
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntrapMeshQuarterFeet() {
    // with a quarter-foot mesh
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntrapThrowFeet() {
    // it can be thrown 20 feet
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntrapCloseCubeFeet() {
    // stretches to close over a 5 foot cube
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSnareRangeInches() {
    // shoots forth up to 3 inches underwater
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPigPotCubicFeet() {
    // one pot creates a 1,000 cubic foot object
    return 1000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPigDepictSquareFeet() {
    // depicted over a 100 square foot surface
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPigContainersMin() {
    // from 1-4 containers found
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPigContainersMax() {
    // the upper edge of the 1-4 containers
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPigInstrumentFeet() {
    // a single instrument about 1 foot long
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPigDepictTurns() {
    // 1 turn to depict an object
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerRecallPerDay() {
    // once a day the pearl recalls
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerSpellsRecalled() {
    // recalls any 1 spell as desired
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerReverseOneIn() {
    // 1 in 20 of opposite effect
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerDoubleMin() {
    // the 00 row recalls 2 spells
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerDoubleMaxLevel() {
    // of 1st to 6th level
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerDoubleDieSides() {
    // the level picked by d6
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        1, 26, 46, 61, 76, 86, 93, 97, 99, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        25, 45, 60, 75, 85, 92, 96, 98, 99, 100,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerSpellLevel(int i) {
    // the spell level per die band, the 00 row
    // marked 0 for the double-spell special; clamps
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    static const int t[10] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWisdomGain() {
    // the cleric gains 1 point of wisdom
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWisdomMonths() {
    // retained for a 1 month period
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWisdomDays() {
    // the gain at the expiration of 30 days
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWisdomReverseOneIn() {
    // 1 in 20 cursed to work in reverse
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpRotAbilityLossPerWeek() {
    // 1 point per ability per week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpRotStartWeek() {
    // beginning 1 week after claiming
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpRotAbilityCount() {
    // dexterity, constitution and charisma
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpRotDeathScore() {
    // dead when any score reaches 0
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPoisonSavePctPerPlus() {
    // a 10 percent saving throw per plus
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPoisonRowLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 9, 15, 19,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPoisonRowHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        8, 14, 18, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPoisonPlus(int i) {
    // the plus of periapt per die band; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 3, 4,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWoundHealRateMult() {
    // doubles the normal rate of healing
    return 2;
}

// ---- part 20 (R276): miscmagic_phylactery_of_faithfulness_to_feather_token ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLongYearsSlowPct() {
    // slows the aging process by one-quarter
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLongYearsDonAge() {
    // the example cleric dons the device at age 20
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLongYearsMonthsPerYear() {
    // he or she will age 9 months every 12
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLongYearsPhysicalAge() {
    // in 12 chronological years, physically 29
    return 29;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLongYearsChronAge() {
    // rather than the naive 32
    return 32;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLongYearsReverseOneIn() {
    // 1 in 20 cursed to operate in reverse
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpAttentionMinLevel() {
    // at 10th or higher level the deity most
    // powerful enemy interferes directly
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeGiantRatMin() {
    // attracts from 10-60 giant rats
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeGiantRatMax() {
    // the giant rat ceiling
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeGiantRatPct() {
    // giant rats at 80 percent
    return 80;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeNormalRatMin() {
    // or from 30-180 normal rats
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeNormalRatMax() {
    // the normal rat ceiling
    return 180;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeNormalRatPct() {
    // normal rats at 20 percent
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeCallRangeInches() {
    // if either or both are within 40 inches
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeDelayPerInches() {
    // a 1 round delay per each 5 inches traveled
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeObeyPct() {
    // 95 percent likely to obey while the piper plays
    return 95;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeReplayObeyPct() {
    // called again: 70 percent come and obey
    return 70;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeReplayTurnPct() {
    // but 30 percent turn upon the piper
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeTakeoverPctPerRound() {
    // 30 percent per round to take over control
    // from a controlling creature
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPipeKeepPct() {
    // 70 percent chance of maintaining control
    return 70;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoleDiameterFeet() {
    // opened fully, 6 feet in diameter
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoleDepthFeet() {
    // an extra-dimensional hole 10 feet deep
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoleBreathTurns() {
    // breath runs out after about a turn
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpHoleGateRadiusFeet() {
    // creatures within a 10 foot radius are drawn
    // to the plane, both items destroyed
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenUses() {
    // each token is usable but once
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenRowLo(int i) {
    // the printed token band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 5, 8, 11, 14, 19,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenRowHi(int i) {
    // the printed token band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4, 7, 10, 13, 18, 20,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenAnchorDays() {
    // the anchor moors a craft immobile for 1 full day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenBirdDays() {
    // the bird equals a roc of the largest size
    // (1 day duration)
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenFanHours() {
    // the fan works up to eight hours a day
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenSwanSpeedInches() {
    // the swan boat swims at 24 inch speed
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenSwanHorses() {
    // it carries 8 horses and gear
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenSwanMen() {
    // or 32 men
    return 32;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenSwanDays() {
    // duration 1 day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenTreeTrunkFeet() {
    // a great oak with a 6 foot diameter trunk
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenTreeHeightFeet() {
    // 60 foot height
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenTreeTopFeet() {
    // 40 foot top diameter
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenWhipPlus() {
    // a +1 weapon
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenWhipLevel() {
    // 9th level fighter to hit probability
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenWhipDmgMin() {
    // 2-7 hit points damage
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenWhipDmgMax() {
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenWhipBindMin() {
    // save versus magic or be bound fast
    // for 2-7 rounds
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenWhipBindMax() {
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpTokenWhipTurns() {
    // wielded for up to 6 turns
    return 6;
}

// ---- part 21 (R277): miscmagic_robes ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiWhitePct() {
    // white: 45 percent (good alignment)
    return 45;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiGrayPct() {
    // gray: 30 percent (neutral alignment)
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiBlackPct() {
    // black: 25 percent (evil alignment)
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiAcClass() {
    // power 1: serves as armor equal to AC 5
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiMagicResistPct() {
    // power 2: confers a 5 percent magic resistance
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiSaveBonus() {
    // power 3: adds +1 to saving throw scores
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiPenaltyPct() {
    // power 4: worn spells cut foe magic
    // resistance and saves by 20 percent
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiPenaltyMinus() {
    // the saving throw half of the 20 percent cut
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiCharmFamilyCount() {
    // the seven spells of the power 4 list
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiClashDmgMin() {
    // white on evil: take 18-51 hit points
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiClashDmgMax() {
    // the clash damage ceiling
    return 51;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiClashDiceCount() {
    // the clash dice are 11d4
    return 11;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiClashDiceBonus() {
    // the clash dice bonus is +7
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiClashXpMin() {
    // and lose 18,000-51,000 experience points
    return 18000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiClashXpMax() {
    // the clash experience loss ceiling
    return 51000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiGrayDmgMin() {
    // the gray or crossed clash: 6-24 hit points
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiGrayDmgMax() {
    // the gray clash damage ceiling
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiGrayXpMin() {
    // 6,000-24,000 experience points loss
    return 6000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpArchmagiGrayXpMax() {
    // the gray experience loss ceiling
    return 24000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBlendDetectRangeInches() {
    // within 3 inches something amiss is detectable
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBlendDetectPerIntPct() {
    // 1 percent per intelligence point chance
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBlendDetectIntMin() {
    // exceptional (15+) or better intelligence
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBlendLevelDetectIntMin() {
    // low intelligence (5+) or better and
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBlendLevelDetectLevelMin() {
    // 10 or more levels of experience or hit dice
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBlendDetectPerLevelPct() {
    // 1 percent per level or hit die chance
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpBlendExamplePct() {
    // the 18 int / 12th level example: 30 percent
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesInfravisionInches() {
    // infravisual capability to 12 inch range
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesSeeInvisibleInches() {
    // invisible things within a 24 inch
    // normal vision range
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesSeeInfraredInches() {
    // or 12 inches if infravision is used
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesTrackRangerLevel() {
    // tracks as if a 12th level ranger
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesBlindLightMin() {
    // a light spell blinds it for 1-3 rounds
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesBlindLightMax() {
    // the light blindness ceiling
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesBlindContinualMin() {
    // a continual light for 2-8 rounds
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEyesBlindContinualMax() {
    // the continual light blindness ceiling
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerlessIntelligence() {
    // the wearer drops to 3 intelligence
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPowerlessStrength() {
    // and becomes weak as well (3 strength)
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintIntMin() {
    // needs intelligence of 15 or higher
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintWisMin() {
    // and a wisdom of 13 or more
    return 13;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintLightFeet() {
    // sheds light in a 40 foot diameter sphere
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintStartRounds() {
    // a full round to cause the colors to flow
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintTransfixMin() {
    // stand transfixed for 2-5 rounds
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintTransfixMax() {
    // the transfix ceiling
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintHitPctPerRound() {
    // 5 percent harder to hit per round of play
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintHitPctMax() {
    // to a maximum of 25 percent (minus 5)
    return 25;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintHitMaxRounds() {
    // attained after 5 continuous rounds
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintCastRangeInches() {
    // activity within 1 inch of the start point
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintHypnotizeMin() {
    // non-combat hypnosis for 2-5 turns
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpScintHypnotizeMax() {
    // the non-combat hypnosis ceiling
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulDetachRounds() {
    // detach any 1 of the patches in 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulBaseEach() {
    // always 2 each of the base patches
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulBaseCount() {
    // the six base patch kinds (3 table rows)
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulExtraMin() {
    // 4-16 extra items which must be diced for
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulExtraMax() {
    // the extra item ceiling
    return 16;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulGpBag() {
    // bag of 100 gold pieces
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulCofferGp() {
    // the silver coffer: 500 g.p. value
    return 500;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulGemsCount() {
    // gems, 10 of
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulGemValueGp() {
    // 100 gold piece value each
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulLadderFeet() {
    // wooden ladder, 24 feet long
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulPitCubicFeet() {
    // pit, 10 cubic feet, open
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulRowboatFeet() {
    // rowboat, 12 feet long
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulWindowWidthFeet() {
    // window, 2 feet wide
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulWindowHeightFeet() {
    // 4 feet high
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulWindowDepthFeet() {
    // up to 2 feet deep
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulScrollSpells() {
    // scroll of 1 spell
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulWarDogsPair() {
    // war dogs, pair
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulRowLo(int i) {
    // the printed extra item band lower edges
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    static const int t[13] = {
        1, 9, 16, 23, 31, 45, 52,
        60, 69, 76, 84, 91, 97,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUsefulRowHi(int i) {
    // the printed extra item band upper edges
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    static const int t[13] = {
        8, 15, 22, 30, 44, 51, 59,
        68, 75, 83, 90, 96, 100,
    };
    return t[i];
}

// ---- part 22 (R278): miscmagic_rope_of_climbing_to_spade_of_colossal_excavation ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClimbLengthFeet() {
    // a 60 foot long rope of climbing
    return 60;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClimbWeightPounds() {
    // weighs no more than 3 pounds
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClimbSupportPounds() {
    // strong enough to support 3,000 pounds
    return 3000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClimbSpeedFeetPerRound() {
    // moves at 10 feet per round upon command
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClimbKnotIntervalFeet() {
    // large knots appear at 1 foot intervals
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClimbKnottedLengthFeet() {
    // knotting shortens the rope to 50 feet
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpConstrictExtraVictimsMin() {
    // lashes at 1-4 others near the holder
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpConstrictExtraVictimsMax() {
    // the extra victim ceiling
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpConstrictVictimRangeFeet() {
    // the others within 10 feet of the victim
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpConstrictDmgMin() {
    // each round delivers 2-12 hit points
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpConstrictDmgMax() {
    // the constriction damage ceiling
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpConstrictAcClass() {
    // the rope itself is AC -2
    return -2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpConstrictCutHitPoints() {
    // takes 22 hit points to cut through
    return 22;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleLashFeet() {
    // lashes forward 20 feet upon command
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleUpwardFeet() {
    // or upwards 10 feet
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleManSizedMax() {
    // ties fast up to 8 man-sized creatures
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleStrikeSegments() {
    // a single segment to strike
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleEntwineSegments() {
    // another segment to entwine
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleCommandSegments() {
    // the command requires 1 segment
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleWholeSegments() {
    // the whole takes 3 segments to perform
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleAcClass() {
    // the rope is AC -2
    return -2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleCutHitPoints() {
    // takes 22 hit points to cut through
    return 22;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleRepairTurns() {
    // damage under 22 repairs itself in 6 turns
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSmotherRoundsMin() {
    // suffocates its victim in 3-6 rounds
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSmotherRoundsMax() {
    // the suffocation ceiling
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSmotherBlockingSpells() {
    // four spells prevent the smothering: alter
    // reality, animate object, hold plant, wish
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWelcomeFlyWidthFeet() {
    // functions as a carpet of flying (6 x 9
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWelcomeFlyLengthFeet() {
    // size)
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWelcomeBridgeFeet() {
    // stiffens as steel up to 27 feet long
    return 27;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWelcomeBridgeWidthFeet() {
    // at a 2 foot width
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWelcomeAcClass() {
    // the bridge form is AC 0
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWelcomeDestroyHitPoints() {
    // takes 100 hit points to destroy
    return 100;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWelcomeShrinkDivisor() {
    // shrinks to 1/12 size on command
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawLengthFeet() {
    // the notched adamantite blade is 12 feet
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawWidthFeet() {
    // long and over 1 foot wide
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawSoloStrength() {
    // requires 18/00 or greater strength alone
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawTandemStrength() {
    // or 2 persons of 17 or greater strength
    return 17;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawTandemPersons() {
    // working in tandem
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawHardwoodFeet() {
    // a 2 foot thick hardwood tree
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawHardwoodTurns() {
    // sliced through in 1 turn
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawTrunkFeet() {
    // a 4 foot thick trunk
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawTrunkTurns() {
    // sliced through in 3 turns
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawSmallDiameterFeet() {
    // a 1 foot diameter tree
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawSmallRounds() {
    // sliced through in but 3 rounds
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawWorkTurns() {
    // after 6 turns of cutting
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSawRestTurns() {
    // the users must rest for 6 turns
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeathHoldRounds() {
    // changes if held for more than 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeathContainerFeet() {
    // or placed within 1 foot of a warm
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeathContainerTurns() {
    // living body for 1 turn
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpDeathHeartRounds() {
    // reaches the victim heart in a single round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEnrageRadiusInches() {
    // enrages hostiles within a 4 inch radius
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEnrageToHitBonus() {
    // the enraged gain +1 to hit
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEnrageDamageBonus() {
    // and +2 on damage
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEnrageAcPenalty() {
    // and -3 on their own armor class
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEnrageRageMin() {
    // the rage lasts for 7-12 rounds
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEnrageRageMax() {
    // the rage ceiling
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEnrageChargesMin() {
    // contains from 19-24 charges
    return 19;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEnrageChargesMax() {
    // the charge ceiling
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInsanityRadiusInches() {
    // insanity within a 2 inch radius
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInsanitySavePenalty() {
    // the save versus magic at -2
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInsanityMagicResistPenaltyPct() {
    // and -10 percent from magic resistance
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInsanityRoundsMin() {
    // completely insane for 9-12 rounds
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInsanityRoundsMax() {
    // the insanity ceiling
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInsanityChargesMin() {
    // the scarab has 9-16 charges
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpInsanityChargesMax() {
    // the charge ceiling
    return 16;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProtectSaveBonus() {
    // +1 on all saving throws versus magic
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProtectNoSaveBase() {
    // a save of 20 when none is possible
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProtectAbsorbCount() {
    // absorbs up to 12 level drains or death
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProtectReversedOneIn() {
    // 1 in 20 are reversed cursed items
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProtectReversedPenalty() {
    // giving the possessor a -2 on the dice
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProtectFixedOneIn() {
    // 1 in 5 of the cursed items are fixed
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProtectFixedBonus() {
    // actually +2 once the curse is removed
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProtectRemoveClericLevel() {
    // removed by a cleric of 16 or higher level
    return 16;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpProtectRemovedAbsorbCount() {
    // the fixed scarab absorbs 24 rather than 12
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeLengthFeet() {
    // the digging tool is 8 feet long
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeBladeWidthFeet() {
    // with a blade 2 feet wide
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeBladeLengthFeet() {
    // and 3 feet long
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeUserStrength() {
    // any fighter with 18 strength can use it
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeDigYardsPerRound() {
    // 1 cubic yard excavated in 1 round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeWorkRounds() {
    // every 10 rounds of digging
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeRestRounds() {
    // forces a rest of 5 rounds
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeHardPanFactor() {
    // hard pan clay takes twice as long
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeGravelFactor() {
    // as does gravel
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSpadeLooseSoilDivisor() {
    // loose soil takes half as long
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEntangleManUnits(int i) {
    // the man-sized equivalence chain; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    // 1 storm giant or fire giant = 2 frost or stone or
    // hill giants = 3 ogres = 4 bugbears = 6 gnolls = 8 men
    // = 10 elves = 12 dwarves = 16 gnomes or kobolds
    static const int t[9] = {
        1, 2, 3, 4, 6,
        8, 10, 12, 16,
    };
    return t[i];
}

// ---- part 23 (R279): miscmagic_sphere_of_annihilation_to_wings_of_flying ----

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereDiameterFeet() {
    // a ball of nothingness 2 feet in diameter
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereControlRangeFeet() {
    // control range is 40 feet initially
    return 40;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereControlPerLevelInches() {
    // 1 inch per level once control is established
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereBaseMoveFeetPerRound() {
    // basic movement rate is 10 feet per round
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereIntBonusLowPct() {
    // adds 1 percent for each point from 13 to 15
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereIntBonusHighPct() {
    // another 3 percent for each point from 16 to 18
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereIntBonusMaxPct() {
    // a maximum of 12 percent bonus
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereIntBonusLowStat() {
    // the low band runs from intelligence 13
    return 13;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereIntBonusHighStat() {
    // the high band runs from intelligence 16
    return 16;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereIntBonusMaxStat() {
    // the maximum bonus lands at 18 intelligence
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereDriftRoundsMin() {
    // uncontrolled it slides toward the user 1-4 rounds
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereDriftRoundsMax() {
    // the drift ceiling
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereDriftRangeFeet() {
    // it keeps coming if the user stays within 30 feet
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereMultiUserPenaltyPct() {
    // 2 or more users drop the chance 5 percent each
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereGateDestroyPct() {
    // a gate spell destroys it 50 percent of the time
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereGateNothingPct() {
    // the gate does nothing 35 percent
    return 35;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereGateTearPct() {
    // the gate tears a spatial gap 15 percent
    return 15;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereGateTearRadiusInches() {
    // the gap catapults everything within 18 inches
    return 18;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereCancelRadiusInches() {
    // a rod of cancellation explodes within 6 inches
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereCancelDmgMin() {
    // the cancellation blast delivers 30-120 damage
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereCancelDmgMax() {
    // the cancellation damage ceiling
    return 120;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereCtlRows() {
    // the control grid has nine level bands
    return 9;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereCtlLevelLo(int i) {
    // the control grid level band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    // up to 5th, 6th-7th, 8th-9th, 10th-11th, 12th-13th,
    // 14th-15th, 16th-17th, 18th-20th, 21st and above
    static const int t[9] = {
        1, 6, 8, 10, 12, 14, 16, 18, 21,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereCtlLevelHi(int i) {
    // the level band upper edges; i clamps; the open
    // 21st-and-above band prints no ceiling and pins 0
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        5, 7, 9, 11, 13, 15, 17, 20, 0,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereCtlMoveFeet(int i) {
    // the movement per round per band; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        8, 9, 10, 11, 12, 13, 14, 15, 16,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereCtlProbPct(int i) {
    // the control probability per round per band; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        15, 20, 30, 40, 50, 60, 70, 75, 80,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEarthStoneEarthDice() {
    // an earth elemental of 12 hit dice from earth
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEarthStoneRoughDice() {
    // 8 hit dice from rough unhewn stone or sand
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEarthStoneWorkedStoneDice() {
    // none can be summoned from worked stone
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEarthStoneAreaFeet() {
    // the summoning area must be 4 feet square
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEarthStoneVolumeYards() {
    // and hold 4 cubic yards of medium
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEarthStoneRoundsMin() {
    // the elemental appears in 1-4 rounds
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEarthStoneRoundsMax() {
    // the appearance ceiling
    return 4;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpEarthStonePerDay() {
    // one elemental per day by means of the stone
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLuckSaveBonus() {
    // +1 on adverse-happening dice rolls
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLuckSavePctBonus() {
    // +5 percent where applicable
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLuckItemPctMin() {
    // 1 percent on magic item and treasure division rolls
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLuckItemPctMax() {
    // up to 10 percent at owner option
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLoadMoveReductionPct() {
    // a 50 percent reduction in movement when haste is due
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLoadAttackReductionPct() {
    // attacks also reduced to 50 percent normal rate
    return 50;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLoadDispelClears() {
    // a dispel evil makes the item disappear
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPureGoodCharges() {
    // the talisman of pure good has 7 charges
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPureGoodRechargeable() {
    // it cannot be recharged
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPureGoodNeutralDmgMin() {
    // a neutral cleric touching it takes 7-28 damage
    return 7;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPureGoodNeutralDmgMax() {
    // the neutral touch ceiling
    return 28;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPureGoodEvilDmgMin() {
    // an evil cleric touching it takes 12-48 damage
    return 12;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPureGoodEvilDmgMax() {
    // the evil touch ceiling
    return 48;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpPureGoodNonClericDmg() {
    // non-clerics are not affected by the device
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereTaliNonMuDmgMin() {
    // any other class touching it takes 5-30 damage
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereTaliNonMuDmgMax() {
    // the wrong-class touch ceiling
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereTaliLowPctPerPoint() {
    // doubles the bonus: 2 percent per point 13-15
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereTaliHighPctPerPoint() {
    // and 6 percent per point 16-18
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereTaliCheckIntervalRounds() {
    // held, the wielder checks control every other round
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereTaliMaxMoveFeet() {
    // an uncontrolled sphere approaches at 16 feet
    return 16;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereWandNegationOnTalisman() {
    // a wand of negation stops the talisman control
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSphereWandNegationOnSphere() {
    // but has no effect upon the sphere itself
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUltimateEvilCharges() {
    // the exact opposite of pure good; 6 charges
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpZagyHostileDmgMin() {
    // a hostile reaction acts as a stone of weight;
    // discarding or destroying it costs 5-30 damage
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpZagyHostileDmgMax() {
    // the hostile discard ceiling
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpZagyNeutralHoursMin() {
    // a neutral reaction stays 5-30 hours
    return 5;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpZagyNeutralHoursMax() {
    // the neutral stay ceiling
    return 30;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpZagyFriendlyMonthsPerChaPoint() {
    // friendly, it stays one month per charisma point
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpZagyWishChaDivisor() {
    // it grants 1 wish per 6 charisma points
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpZagyTrapRangeFeet() {
    // it grows warm within 20 feet of a trap
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpZagyDiamondGp() {
    // a base 10,000 gp diamond remains behind
    return 10000;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClearThoughtIntGain() {
    // the tome raises intelligence by 1 point
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClearThoughtReadHours() {
    // reading takes 48 hours over 6 days
    return 48;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClearThoughtReadDays() {
    // the six reading days
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClearThoughtStartWeeks() {
    // the exercises must begin within 1 week
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClearThoughtGainMonths() {
    // intelligence goes up after 1 full month
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpClearThoughtRereadGain() {
    // any further perusal is of no benefit
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpLeadershipChaGain() {
    // leadership and influence raises charisma by 1
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpUnderstandingWisGain() {
    // the tome of understanding raises wisdom by 1
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFishCmdRadiusInches() {
    // all fish within a 6 inch radius save versus magic
    return 6;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFishCmdChargeCost() {
    // the command uses one charge
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFishCmdProtectFeet() {
    // commanded fish spare all within 10 feet
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFishCmdApproachFeet() {
    // free fish keep 10 feet off the trident
    return 10;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFishCmdSchoolsAsOne() {
    // schooling fish check as a single entity
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFishCmdChargesMin() {
    // it contains 17-20 charges
    return 17;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFishCmdChargesMax() {
    // the charge ceiling
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpFishCmdMagicBonus() {
    // otherwise a +1 magic weapon
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSubmitMoraleDelayRounds() {
    // a failed save means a morale check the next round
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSubmitHopelessRoundsMin() {
    // the hopelessness lasts 2-8 rounds
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSubmitHopelessRoundsMax() {
    // the hopelessness ceiling
    return 8;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSubmitChargesMin() {
    // it has 17-20 charges
    return 17;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSubmitChargesMax() {
    // the charge ceiling
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpSubmitMagicBonus() {
    // a +1 magic weapon
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWarningRadiusInches() {
    // it scans hostile hungry predators within 24 inches
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWarningScanRounds() {
    // one round scans the 24 inch hemisphere
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWarningChargesMin() {
    // it carries 19-24 charges
    return 19;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWarningChargesMax() {
    // the charge ceiling
    return 24;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWarningChargeRounds() {
    // each charge lasts for 2 rounds of scanning
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWarningMagicBonus() {
    // otherwise a +2 magic weapon
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpYearningMagicPenalty() {
    // a -2 cursed magical weapon
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpYearningFreeingSpells() {
    // freed by water breathing, wish or alter reality
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpYearningGrantsWaterBreathing() {
    // it does not confer the ability to breathe underwater
    return 0;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVacuousSaveCount() {
    // the reader must make 2 saving throws versus magic
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVacuousIntLoss() {
    // the first throw: 1 point of intelligence lost
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVacuousWisLoss() {
    // the second throw: 2 points of wisdom lost
    return 2;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpVacuousBurnAfterRemoveCurse() {
    // it must be burned to be rid of after remove curse
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWellTwoWay() {
    // things come through the opening both ways
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWingsSpanFeet() {
    // gigantic bat wings of 20 foot span
    return 20;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWingsRestHours() {
    // after maximum flight the wearer rests 1 hour
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWingsQuietHours() {
    // shorter flights need only 1 hour of quiet
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWingsNoRestTurns() {
    // flights under 1 turn need no rest at all
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWingsUsesPerDay() {
    // the wings work but once per day
    return 1;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWingsSupportPounds() {
    // they support up to 500 pounds weight
    return 500;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWingsSpeedRows() {
    // the duration list has three entries
    return 3;
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWingsSpeedTurns(int i) {
    // the turns flown per speed entry; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    // 2 turns at 32 inches, 4 at 18, 8 at 12
    static const int t[3] = {
        2, 4, 8,
    };
    return t[i];
}

int Miscmagic_alchemy_jug_to_wings_of_flying::mmpWingsSpeedInches(int i) {
    // the flight speed per entry; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        32, 18, 12,
    };
    return t[i];
}
