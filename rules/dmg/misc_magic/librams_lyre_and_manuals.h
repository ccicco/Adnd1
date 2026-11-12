// ====================================================================
// Adnd1 - rules/dmg/misc_magic/librams_lyre_and_manuals.h
// R273: the III.E misc magic explanation prose part 17
// (DMG p.149-150) - the three Librams, the Lyre of
// Building and the manuals of Bodily Health, Gainful
// Exercise, Golems, Puissant Skill at Arms and
// Quickness of Action, part2 lines 806-841 (global =
// 11065 + part2 line), pinning the kMisc4 rows 0-8 of
// the 36-row III.E.4 table. ONE page header inside
// the slice (839, the TREASURE page) falls inside the
// manual of quickness paragraph between Only after
// and the month of training - ONE seam restored this
// round; the page attribution rides the compilation
// TOC index (the books and manuals at pp.149-150) on
// the R272-established p.149 base. The upload drops
// the pipe in two part1 rows (02 the Ineffable
// Damnation, 08 the Puissant Skill at Arms); the
// bodily health paragraph carries a stray apostrophe
// artifact after the word manual (pinned as the
// upload prints it, apostrophe-free here). 47
// accessors: 43 scalars + 4 walkers (the golem table
// die bands, months and costs), no name collisions
// with miscprose1.h through miscprose16.h. Pure data
// + helpers, header-only (the grenade.h pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_librams_lyre_and_manuals {
public:
    int mmpLibramStudyWeeks();
    int mmpLibramMisuseDamageMin();
    int mmpLibramMisuseDamageMax();
    int mmpLibramUnconsciousTurnsMin();
    int mmpLibramUnconsciousTurnsMax();
    int mmpLibramInsanityRestMonths();
    int mmpLibramDamnationLevelLoss();
    int mmpLyreNegateKindCount();
    int mmpLyreNegateRounds();
    int mmpLyreNegatePerDay();
    int mmpLyreBuildPerWeek();
    int mmpLyreBuildTurns();
    int mmpLyreBuildMen();
    int mmpLyreBuildDays();
    int mmpLyreFalseChordPct();
    int mmpLyreFalseChordKnownPct();
    int mmpLyreFalseChordDisturbedPct();
    int mmpHealthReadHours();
    int mmpHealthReadDaysMin();
    int mmpHealthReadDaysMax();
    int mmpHealthConGain();
    int mmpHealthRegimenMonths();
    int mmpHealthForgetMonths();
    int mmpExerciseStrGain();
    int mmpGolemKindCount();
    int mmpGolemMinUserLevel();
    int mmpGolemFailurePctPerLevel();
    int mmpGolemFailureWindowTurns();
    int mmpGolemClericXpLossMin();
    int mmpGolemClericXpLossMax();
    int mmpGolemMuLevelLoss();
    int mmpGolemOtherDamageMin();
    int mmpGolemOtherDamageMax();
    int mmpGolemDieLo(int i);
    int mmpGolemDieHi(int i);
    int mmpGolemMonths(int i);
    int mmpGolemCostGp(int i);
    int mmpPuissantPracticeMonths();
    int mmpPuissantForgetMonths();
    int mmpPuissantStunTurnsMin();
    int mmpPuissantStunTurnsMax();
    int mmpPuissantXpLossMin();
    int mmpPuissantXpLossMax();
    int mmpQuicknessStudyDays();
    int mmpQuicknessPracticeMonths();
    int mmpQuicknessDexGain();
    int mmpQuicknessRememberMonths();
};
