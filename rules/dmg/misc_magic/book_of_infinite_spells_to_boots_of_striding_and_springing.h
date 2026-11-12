// ====================================================================
// Adnd1 - rules/dmg/misc_magic/book_of_infinite_spells_to_boots_of_striding_and_springing.h
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
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing {
public:
    int mmpInfiniteFirstReadHpMin();
    int mmpInfiniteFirstReadHpMax();
    int mmpInfiniteFirstReadStunTurnsMin();
    int mmpInfiniteFirstReadStunTurnsMax();
    int mmpInfinitePageMin();
    int mmpInfinitePageMax();
    int mmpInfinitePageBase();
    int mmpInfinitePageDieSides();
    int mmpInfinitePageRowCount();
    int mmpInfinitePageLo(int i);
    int mmpInfinitePageHi(int i);
    int mmpInfiniteLevelDieSides();
    int mmpInfiniteMuLevelDieSides();
    int mmpInfiniteLevelRerollLo();
    int mmpInfiniteLevelRerollHi();
    int mmpInfiniteMuLevelRerollLo();
    int mmpInfiniteMuLevelRerollHi();
    int mmpInfiniteRerollDieSides();
    int mmpInfiniteMuRerollDieSides();
    int mmpInfiniteVanishesAtLastPage();
    int mmpInfiniteCastPerDay();
    int mmpInfiniteCastPerDayIfKnown();
    int mmpInfiniteTurnPctUsable();
    int mmpInfiniteTurnPctForeign();
    int mmpInfiniteTurnPctNonCasterCleric();
    int mmpInfiniteTurnPctNonCasterMu();
    int mmpVileReadingWeeks();
    int mmpVileWisdomGain();
    int mmpVileHalfwayPct();
    int mmpVileNeutralXpLossMin();
    int mmpVileNeutralXpLossMax();
    int mmpVileNeutralSplitPct();
    int mmpVileGoodSaveCount();
    int mmpVileGoodXpLossBase();
    int mmpVileGoodXpLossPerWis();
    int mmpVileGoodHandlingHpMin();
    int mmpVileGoodHandlingHpMax();
    int mmpVileNightHagPct();
    int mmpVileNeutralHandlingHpMin();
    int mmpVileNeutralHandlingHpMax();
    int mmpDancingDisguisedBootTypeCount();
    int mmpDancingTriggerCaseCount();
    int mmpDancingAcPenalty();
    int mmpDancingRemovalSpellCount();
    int mmpElvenkindSilencePctWorst();
    int mmpElvenkindSilencePctBest();
    int mmpLevitationSpeedInchesPerRound();
    int mmpLevitationWeightIncrementPounds();
    int mmpLevitationWeightDieSides();
    int mmpLevitationWeightBasePounds();
    int mmpLevitationWeightMinPounds();
    int mmpLevitationWeightMaxPounds();
    int mmpSpeedBaseMovementInches();
    int mmpSpeedSlowPoundsPerInch();
    int mmpSpeedFreeWeightPounds();
    int mmpSpeedExampleHumanPounds();
    int mmpSpeedExampleGearPounds();
    int mmpSpeedExampleRateInches();
    int mmpSpeedSackCoins();
    int mmpSpeedSackSlowInches();
    int mmpSpeedRestHoursPerMoveHour();
    int mmpSpeedMaxContinuousHours();
    int mmpSpeedAcBonus();
    int mmpStridingBaseMovementInches();
    int mmpStridingMaxHoursPerDay();
    int mmpStridingRechargeHours();
    int mmpStridingNormalPaceFeet();
    int mmpStridingForwardJumpFeet();
    int mmpStridingBackwardLeapFeet();
    int mmpStridingVerticalSpringFeet();
    int mmpStridingStumbleBasePct();
    int mmpStridingStumbleDexAdjPct();
    int mmpStridingStumbleDexThreshold();
    int mmpStridingStumbleRowCount();
    int mmpStridingStumblePctByDex(int i);
    int mmpStridingAcBonus();
};
