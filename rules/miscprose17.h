// ====================================================================
// Adnd1 - rules/miscprose17.h
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
// ====================================================================

#pragma once

namespace rules {

inline int mmpLibramStudyWeeks() {
    // a full week of cloistered study
    return 1;
}

inline int mmpLibramMisuseDamageMin() {
    // a non-neutral reader takes 5-20 damage
    return 5;
}

inline int mmpLibramMisuseDamageMax() {
    // the upper edge of the 5-20 damage
    return 20;
}

inline int mmpLibramUnconsciousTurnsMin() {
    // unconscious a like number of turns
    return 5;
}

inline int mmpLibramUnconsciousTurnsMax() {
    // the upper edge of the like-number turns
    return 20;
}

inline int mmpLibramInsanityRestMonths() {
    // the insane reader rests 1 month
    return 1;
}

inline int mmpLibramDamnationLevelLoss() {
    // a non-evil look inside loses 1 level
    return 1;
}

inline int mmpLyreNegateKindCount() {
    // horn of blasting, disintegrate, elemental
    return 3;
}

inline int mmpLyreNegateRounds() {
    // negates 6 rounds of earth elemental attack
    return 6;
}

inline int mmpLyreNegatePerDay() {
    // the negatory chords play once per day
    return 1;
}

inline int mmpLyreBuildPerWeek() {
    // the building chords strum once per week
    return 1;
}

inline int mmpLyreBuildTurns() {
    // 3 turns of such playing
    return 3;
}

inline int mmpLyreBuildMen() {
    // equal to the work of 100 men
    return 100;
}

inline int mmpLyreBuildDays() {
    // 100 men laboring for 3 days
    return 3;
}

inline int mmpLyreFalseChordPct() {
    // a false chord negates 20 percent likely
    return 20;
}

inline int mmpLyreFalseChordKnownPct() {
    // only 5 percent once the proper ones known
    return 5;
}

inline int mmpLyreFalseChordDisturbedPct() {
    // disturbed while playing rises to 50 percent
    return 50;
}

inline int mmpHealthReadHours() {
    // the read takes 24 hours of time
    return 24;
}

inline int mmpHealthReadDaysMin() {
    // over 3-5 days
    return 3;
}

inline int mmpHealthReadDaysMax() {
    // the upper edge of the 3-5 days
    return 5;
}

inline int mmpHealthConGain() {
    // the regimen raises constitution by 1 point
    return 1;
}

inline int mmpHealthRegimenMonths() {
    // the diet and breathing run 1 month
    return 1;
}

inline int mmpHealthForgetMonths() {
    // the secrets fade in 3 months
    return 3;
}

inline int mmpExerciseStrGain() {
    // the course adds 1 point of strength
    return 1;
}

inline int mmpGolemKindCount() {
    // 4 sorts of golems
    return 4;
}

inline int mmpGolemMinUserLevel() {
    // the maker assumed 10th or higher
    return 10;
}

inline int mmpGolemFailurePctPerLevel() {
    // cumulative 10 percent per level under 10th
    return 10;
}

inline int mmpGolemFailureWindowTurns() {
    // falls to pieces within 1 turn of completion
    return 1;
}

inline int mmpGolemClericXpLossMin() {
    // a cleric reading loses 10,000 xp
    return 10000;
}

inline int mmpGolemClericXpLossMax() {
    // up to 60,000 xp lost
    return 60000;
}

inline int mmpGolemMuLevelLoss() {
    // a magic-user reading loses 1 level
    return 1;
}

inline int mmpGolemOtherDamageMin() {
    // any other class suffers 6-36 damage
    return 6;
}

inline int mmpGolemOtherDamageMax() {
    // the upper edge of the 6-36 damage
    return 36;
}

inline int mmpGolemDieLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 6, 18, 19,
    };
    return t[i];
}

inline int mmpGolemDieHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        5, 17, 18, 20,
    };
    return t[i];
}

inline int mmpGolemMonths(int i) {
    // the construction months per golem sort; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 4, 3,
    };
    return t[i];
}

inline int mmpGolemCostGp(int i) {
    // the construction cost per golem sort; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        65000, 50000, 100000, 80000,
    };
    return t[i];
}

inline int mmpPuissantPracticeMonths() {
    // the fighter practices 1 month
    return 1;
}

inline int mmpPuissantForgetMonths() {
    // the knowledge fades within 3 months
    return 3;
}

inline int mmpPuissantStunTurnsMin() {
    // a scanning magic-user is stunned 1-6 turns
    return 1;
}

inline int mmpPuissantStunTurnsMax() {
    // the upper edge of the 1-6 turn stun
    return 6;
}

inline int mmpPuissantXpLossMin() {
    // the scanning magic-user loses 10,000 xp
    return 10000;
}

inline int mmpPuissantXpLossMax() {
    // up to 60,000 xp lost
    return 60000;
}

inline int mmpQuicknessStudyDays() {
    // 3 days of uninterrupted study
    return 3;
}

inline int mmpQuicknessPracticeMonths() {
    // the skills practiced 1 month
    return 1;
}

inline int mmpQuicknessDexGain() {
    // the practice gains 1 point of dexterity
    return 1;
}

inline int mmpQuicknessRememberMonths() {
    // the contents remembered 3 months
    return 3;
}

}  // namespace rules