// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.h"

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteFirstReadHpMin() {
    // non-casters suffer 5-20 hit points
    return 5;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteFirstReadHpMax() {
    // the top of the first-read damage
    return 20;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteFirstReadStunTurnsMin() {
    // and are stunned 5-20 turns
    return 5;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteFirstReadStunTurnsMax() {
    // the top of the stun range
    return 20;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfinitePageMin() {
    // contains from 23-30 pages
    return 23;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfinitePageMax() {
    // the top of the page range
    return 30;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfinitePageBase() {
    // 22 + d8 pages
    return 22;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfinitePageDieSides() {
    // the d8 on the page count
    return 8;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfinitePageRowCount() {
    // the 5-row page table
    return 5;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfinitePageLo(int i) {
    // the d100 page-band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 31, 51, 61, 96,
    };
    return t[i];
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfinitePageHi(int i) {
    // the d100 page-band upper edges (00 = 100)
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        30, 50, 60, 95, 100,
    };
    return t[i];
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteLevelDieSides() {
    // roll d10 for spell level, all but magic-user
    return 10;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteMuLevelDieSides() {
    // the magic-user level die is a d12
    return 12;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteLevelRerollLo() {
    // results 8-10 reroll to d6
    return 8;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteLevelRerollHi() {
    // the top of the 8-10 reroll band
    return 10;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteMuLevelRerollLo() {
    // magic-user 10-12 reroll to d8
    return 10;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteMuLevelRerollHi() {
    // the top of the 10-12 reroll band
    return 12;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteRerollDieSides() {
    // the reroll die
    return 6;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteMuRerollDieSides() {
    // the magic-user reroll die
    return 8;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteVanishesAtLastPage() {
    // the last page turned, the book vanishes
    return 1;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteCastPerDay() {
    // cast the open page once per day
    return 1;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteCastPerDayIfKnown() {
    // 4 per day if already castable by class
    return 4;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteTurnPctUsable() {
    // page turns: usable by class and level
    return 10;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteTurnPctForeign() {
    // foreign to class and/or level
    return 20;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteTurnPctNonCasterCleric() {
    // non-caster using a cleric spell
    return 25;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpInfiniteTurnPctNonCasterMu() {
    // non-caster using a magic-user spell
    return 30;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileReadingWeeks() {
    // full consumption requires 1 week
    return 1;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileWisdomGain() {
    // the evil cleric gains 1 wisdom
    return 1;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileHalfwayPct() {
    // XP to exactly half way into next level
    return 50;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileNeutralXpLossMin() {
    // neutral clerics lose 30,000-120,000 XP
    return 30000;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileNeutralXpLossMax() {
    // or become evil, 50% for either
    return 120000;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileNeutralSplitPct() {
    // the either-or chance
    return 50;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileGoodSaveCount() {
    // good clerics: poison or die, then magic or
    // become permanently insane - two saves
    return 2;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileGoodXpLossBase() {
    // the good cleric XP loss base
    return 250000;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileGoodXpLossPerWis() {
    // less 10,000 per wisdom point
    return 10000;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileGoodHandlingHpMin() {
    // other good characters take 5-30 hp
    return 5;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileGoodHandlingHpMax() {
    // the top of the good handling damage
    return 30;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileNightHagPct() {
    // 80% a night hag comes if they look inside
    return 80;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileNeutralHandlingHpMin() {
    // non-evil neutral handling: 5-20 hp
    return 5;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpVileNeutralHandlingHpMax() {
    // the top of the neutral handling damage
    return 20;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpDancingDisguisedBootTypeCount() {
    // masquerade as one of the other 4 useful
    // types until melee combat
    return 4;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpDancingTriggerCaseCount() {
    // in melee, or fleeing from the actuality
    return 2;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpDancingAcPenalty() {
    // the armor class penalty
    return 4;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpDancingRemovalSpellCount() {
    // only a remove curse spell frees the wearer
    return 1;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpElvenkindSilencePctWorst() {
    // 95% chance of silence in the worst conditions
    return 95;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpElvenkindSilencePctBest() {
    // 100% in the best
    return 100;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpLevitationSpeedInchesPerRound() {
    // the ascent/descent speed per round (the 102
    // seam fact, completed across the page header)
    return 20;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpLevitationWeightIncrementPounds() {
    // d20 in 14 pound increments
    return 14;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpLevitationWeightDieSides() {
    // the d20 on the weight capacity
    return 20;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpLevitationWeightBasePounds() {
    // added to a base of 280 pounds
    return 280;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpLevitationWeightMinPounds() {
    // 294 pounds at the minimum roll
    return 294;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpLevitationWeightMaxPounds() {
    // 560 pounds at the maximum roll
    return 560;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedBaseMovementInches() {
    // the speed of a fast horse, 24 inches base
    return 24;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedSlowPoundsPerInch() {
    // 1 inch slower per 10 pounds over 200
    return 10;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedFreeWeightPounds() {
    // the 200 pound free allowance
    return 200;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedExampleHumanPounds() {
    // the example: a 180 pound human
    return 180;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedExampleGearPounds() {
    // with 60 pounds of gear
    return 60;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedExampleRateInches() {
    // moves at 20 inches base rate
    return 20;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedSackCoins() {
    // the extra sack of 500 gold pieces
    return 500;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedSackSlowInches() {
    // slows the rate yet another 5 inches
    return 5;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedRestHoursPerMoveHour() {
    // 1 rest hour per hour of fast movement
    return 1;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedMaxContinuousHours() {
    // no more than 8 hours continuous
    return 8;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpSpeedAcBonus() {
    // +2 to armor class value in combat
    return 2;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingBaseMovementInches() {
    // base movement rate of 12 inches regardless
    return 12;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingMaxHoursPerDay() {
    // tirelessly for up to 12 hours per day
    return 12;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingRechargeHours() {
    // then no function for 12 hours (recharge)
    return 12;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingNormalPaceFeet() {
    // normal paces are 3 feet long
    return 3;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingForwardJumpFeet() {
    // forward jumps of up to 30 feet
    return 30;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingBackwardLeapFeet() {
    // backward leaps of 9 feet
    return 9;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingVerticalSpringFeet() {
    // vertical springs of 15 feet
    return 15;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingStumbleBasePct() {
    // base 20% stumble chance
    return 20;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingStumbleDexAdjPct() {
    // less 3% per point of dexterity above 12
    return 3;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingStumbleDexThreshold() {
    // the dexterity threshold
    return 12;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingStumbleRowCount() {
    // the dex ladder rows, 13 through 18
    return 6;
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingStumblePctByDex(int i) {
    // row i = dexterity - 13; the stumble chance;
    // i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        17, 14, 11, 8, 5, 2,
    };
    return t[i];
}

int Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing::mmpStridingAcBonus() {
    // increases armor class value by 1
    return 1;
}
