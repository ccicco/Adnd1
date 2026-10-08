// ====================================================================
// Adnd1 - rules/miscprose3.h
// R259: the III.E misc magic explanation prose part 3
// pins - part2 lines 67-108, Book of Infinite Spells
// through Boots of Striding and Springing (global line
// = 11065 + part2 line). TWO page headers inside the
// slice, both stripped (the R249 lesson): line 70 splits
// the page table from the Book of Infinite Spells intro;
// line 102 splits the Boots of Levitation paragraph
// mid-sentence - the seam pinned exactly (line 100 ends
// the ascent/descent speed mid-phrase, line 104 continues
// ROUND (MINUTE)).
//   - Book of Infinite Spells: non-casters 5-20 hp and
//     5-20 turns stunned on first read; 23-30 (22 + d8)
//     pages; the 5-row page table; d10 level die (d12 for
//     magic-user), 8-10 / 10-12 reroll to d6 / d8; cast
//     the open page 1/day (4/day if already castable);
//     the page-turn ladder 10/20/25/30%; the last page
//     turned and the book vanishes.
//   - Book of Vile Darkness: 1 week, +1 wisdom, halfway
//     XP; neutral 30,000-120,000 or turn evil, 50% either;
//     good clerics 2 saves (poison or die, magic or
//     insane), then 250,000 XP less 10,000 per wisdom;
//     other good 5-30 hp, 80% night hag if opened;
//     non-evil neutral 5-20 hp handling.
//   - Boots of Dancing: masquerade as one of the other 4
//     useful types until melee or fleeing; AC penalty 4,
//     no saves, no attacks; remove curse only.
//   - Boots of Elvenkind: 95% silence worst, 100% best.
//   - Boots of Levitation: 20 inches per round; d20 in
//     14 pound increments over a 280 pound base, 294
//     to 560 pounds.
//   - Boots of Speed: 24 inch base; 1 inch slower per 10
//     pounds over 200 (the 180/60 example at 20; the 500
//     coin sack at 5 more); 1 rest hour per move hour, 8
//     hours max; AC +2.
//   - Boots of Striding and Springing: 12 inch base, 12
//     hours then 12 recharge; 3 foot paces, 30 forward,
//     9 backward, 15 vertical; 20% stumble less 3% per
//     dex above 12 (the 17/14/11/8/5/2 ladder); AC +1.
// The seven items are the engine kMisc1 rows 16-22 (the
// R225 m1 band pins) - cross-checked in the audit, with
// the Vile (C) class mark at row 17. Pure data +
// helpers, header-only (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpInfiniteFirstReadHpMin() {
    // non-casters suffer 5-20 hit points
    return 5;
}

inline int mmpInfiniteFirstReadHpMax() {
    // the top of the first-read damage
    return 20;
}

inline int mmpInfiniteFirstReadStunTurnsMin() {
    // and are stunned 5-20 turns
    return 5;
}

inline int mmpInfiniteFirstReadStunTurnsMax() {
    // the top of the stun range
    return 20;
}

inline int mmpInfinitePageMin() {
    // contains from 23-30 pages
    return 23;
}

inline int mmpInfinitePageMax() {
    // the top of the page range
    return 30;
}

inline int mmpInfinitePageBase() {
    // 22 + d8 pages
    return 22;
}

inline int mmpInfinitePageDieSides() {
    // the d8 on the page count
    return 8;
}

inline int mmpInfinitePageRowCount() {
    // the 5-row page table
    return 5;
}

inline int mmpInfinitePageLo(int i) {
    // the d100 page-band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 31, 51, 61, 96,
    };
    return t[i];
}

inline int mmpInfinitePageHi(int i) {
    // the d100 page-band upper edges (00 = 100)
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        30, 50, 60, 95, 100,
    };
    return t[i];
}

inline int mmpInfiniteLevelDieSides() {
    // roll d10 for spell level, all but magic-user
    return 10;
}

inline int mmpInfiniteMuLevelDieSides() {
    // the magic-user level die is a d12
    return 12;
}

inline int mmpInfiniteLevelRerollLo() {
    // results 8-10 reroll to d6
    return 8;
}

inline int mmpInfiniteLevelRerollHi() {
    // the top of the 8-10 reroll band
    return 10;
}

inline int mmpInfiniteMuLevelRerollLo() {
    // magic-user 10-12 reroll to d8
    return 10;
}

inline int mmpInfiniteMuLevelRerollHi() {
    // the top of the 10-12 reroll band
    return 12;
}

inline int mmpInfiniteRerollDieSides() {
    // the reroll die
    return 6;
}

inline int mmpInfiniteMuRerollDieSides() {
    // the magic-user reroll die
    return 8;
}

inline int mmpInfiniteVanishesAtLastPage() {
    // the last page turned, the book vanishes
    return 1;
}

inline int mmpInfiniteCastPerDay() {
    // cast the open page once per day
    return 1;
}

inline int mmpInfiniteCastPerDayIfKnown() {
    // 4 per day if already castable by class
    return 4;
}

inline int mmpInfiniteTurnPctUsable() {
    // page turns: usable by class and level
    return 10;
}

inline int mmpInfiniteTurnPctForeign() {
    // foreign to class and/or level
    return 20;
}

inline int mmpInfiniteTurnPctNonCasterCleric() {
    // non-caster using a cleric spell
    return 25;
}

inline int mmpInfiniteTurnPctNonCasterMu() {
    // non-caster using a magic-user spell
    return 30;
}

inline int mmpVileReadingWeeks() {
    // full consumption requires 1 week
    return 1;
}

inline int mmpVileWisdomGain() {
    // the evil cleric gains 1 wisdom
    return 1;
}

inline int mmpVileHalfwayPct() {
    // XP to exactly half way into next level
    return 50;
}

inline int mmpVileNeutralXpLossMin() {
    // neutral clerics lose 30,000-120,000 XP
    return 30000;
}

inline int mmpVileNeutralXpLossMax() {
    // or become evil, 50% for either
    return 120000;
}

inline int mmpVileNeutralSplitPct() {
    // the either-or chance
    return 50;
}

inline int mmpVileGoodSaveCount() {
    // good clerics: poison or die, then magic or
    // become permanently insane - two saves
    return 2;
}

inline int mmpVileGoodXpLossBase() {
    // the good cleric XP loss base
    return 250000;
}

inline int mmpVileGoodXpLossPerWis() {
    // less 10,000 per wisdom point
    return 10000;
}

inline int mmpVileGoodHandlingHpMin() {
    // other good characters take 5-30 hp
    return 5;
}

inline int mmpVileGoodHandlingHpMax() {
    // the top of the good handling damage
    return 30;
}

inline int mmpVileNightHagPct() {
    // 80% a night hag comes if they look inside
    return 80;
}

inline int mmpVileNeutralHandlingHpMin() {
    // non-evil neutral handling: 5-20 hp
    return 5;
}

inline int mmpVileNeutralHandlingHpMax() {
    // the top of the neutral handling damage
    return 20;
}

inline int mmpDancingDisguisedBootTypeCount() {
    // masquerade as one of the other 4 useful
    // types until melee combat
    return 4;
}

inline int mmpDancingTriggerCaseCount() {
    // in melee, or fleeing from the actuality
    return 2;
}

inline int mmpDancingAcPenalty() {
    // the armor class penalty
    return 4;
}

inline int mmpDancingRemovalSpellCount() {
    // only a remove curse spell frees the wearer
    return 1;
}

inline int mmpElvenkindSilencePctWorst() {
    // 95% chance of silence in the worst conditions
    return 95;
}

inline int mmpElvenkindSilencePctBest() {
    // 100% in the best
    return 100;
}

inline int mmpLevitationSpeedInchesPerRound() {
    // the ascent/descent speed per round (the 102
    // seam fact, completed across the page header)
    return 20;
}

inline int mmpLevitationWeightIncrementPounds() {
    // d20 in 14 pound increments
    return 14;
}

inline int mmpLevitationWeightDieSides() {
    // the d20 on the weight capacity
    return 20;
}

inline int mmpLevitationWeightBasePounds() {
    // added to a base of 280 pounds
    return 280;
}

inline int mmpLevitationWeightMinPounds() {
    // 294 pounds at the minimum roll
    return 294;
}

inline int mmpLevitationWeightMaxPounds() {
    // 560 pounds at the maximum roll
    return 560;
}

inline int mmpSpeedBaseMovementInches() {
    // the speed of a fast horse, 24 inches base
    return 24;
}

inline int mmpSpeedSlowPoundsPerInch() {
    // 1 inch slower per 10 pounds over 200
    return 10;
}

inline int mmpSpeedFreeWeightPounds() {
    // the 200 pound free allowance
    return 200;
}

inline int mmpSpeedExampleHumanPounds() {
    // the example: a 180 pound human
    return 180;
}

inline int mmpSpeedExampleGearPounds() {
    // with 60 pounds of gear
    return 60;
}

inline int mmpSpeedExampleRateInches() {
    // moves at 20 inches base rate
    return 20;
}

inline int mmpSpeedSackCoins() {
    // the extra sack of 500 gold pieces
    return 500;
}

inline int mmpSpeedSackSlowInches() {
    // slows the rate yet another 5 inches
    return 5;
}

inline int mmpSpeedRestHoursPerMoveHour() {
    // 1 rest hour per hour of fast movement
    return 1;
}

inline int mmpSpeedMaxContinuousHours() {
    // no more than 8 hours continuous
    return 8;
}

inline int mmpSpeedAcBonus() {
    // +2 to armor class value in combat
    return 2;
}

inline int mmpStridingBaseMovementInches() {
    // base movement rate of 12 inches regardless
    return 12;
}

inline int mmpStridingMaxHoursPerDay() {
    // tirelessly for up to 12 hours per day
    return 12;
}

inline int mmpStridingRechargeHours() {
    // then no function for 12 hours (recharge)
    return 12;
}

inline int mmpStridingNormalPaceFeet() {
    // normal paces are 3 feet long
    return 3;
}

inline int mmpStridingForwardJumpFeet() {
    // forward jumps of up to 30 feet
    return 30;
}

inline int mmpStridingBackwardLeapFeet() {
    // backward leaps of 9 feet
    return 9;
}

inline int mmpStridingVerticalSpringFeet() {
    // vertical springs of 15 feet
    return 15;
}

inline int mmpStridingStumbleBasePct() {
    // base 20% stumble chance
    return 20;
}

inline int mmpStridingStumbleDexAdjPct() {
    // less 3% per point of dexterity above 12
    return 3;
}

inline int mmpStridingStumbleDexThreshold() {
    // the dexterity threshold
    return 12;
}

inline int mmpStridingStumbleRowCount() {
    // the dex ladder rows, 13 through 18
    return 6;
}

inline int mmpStridingStumblePctByDex(int i) {
    // row i = dexterity - 13; the stumble chance;
    // i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        17, 14, 11, 8, 5, 2,
    };
    return t[i];
}

inline int mmpStridingAcBonus() {
    // increases armor class value by 1
    return 1;
}

}  // namespace rules

