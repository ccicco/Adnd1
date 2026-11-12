// R-refactor: split from miscmagic_librams_lyre_and_manuals.h - definitions
#include "rules/dmg/miscmagic_librams_lyre_and_manuals.h"

int Miscmagic_librams_lyre_and_manuals::mmpLibramStudyWeeks() {
    // a full week of cloistered study
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpLibramMisuseDamageMin() {
    // a non-neutral reader takes 5-20 damage
    return 5;
}

int Miscmagic_librams_lyre_and_manuals::mmpLibramMisuseDamageMax() {
    // the upper edge of the 5-20 damage
    return 20;
}

int Miscmagic_librams_lyre_and_manuals::mmpLibramUnconsciousTurnsMin() {
    // unconscious a like number of turns
    return 5;
}

int Miscmagic_librams_lyre_and_manuals::mmpLibramUnconsciousTurnsMax() {
    // the upper edge of the like-number turns
    return 20;
}

int Miscmagic_librams_lyre_and_manuals::mmpLibramInsanityRestMonths() {
    // the insane reader rests 1 month
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpLibramDamnationLevelLoss() {
    // a non-evil look inside loses 1 level
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreNegateKindCount() {
    // horn of blasting, disintegrate, elemental
    return 3;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreNegateRounds() {
    // negates 6 rounds of earth elemental attack
    return 6;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreNegatePerDay() {
    // the negatory chords play once per day
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreBuildPerWeek() {
    // the building chords strum once per week
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreBuildTurns() {
    // 3 turns of such playing
    return 3;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreBuildMen() {
    // equal to the work of 100 men
    return 100;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreBuildDays() {
    // 100 men laboring for 3 days
    return 3;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreFalseChordPct() {
    // a false chord negates 20 percent likely
    return 20;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreFalseChordKnownPct() {
    // only 5 percent once the proper ones known
    return 5;
}

int Miscmagic_librams_lyre_and_manuals::mmpLyreFalseChordDisturbedPct() {
    // disturbed while playing rises to 50 percent
    return 50;
}

int Miscmagic_librams_lyre_and_manuals::mmpHealthReadHours() {
    // the read takes 24 hours of time
    return 24;
}

int Miscmagic_librams_lyre_and_manuals::mmpHealthReadDaysMin() {
    // over 3-5 days
    return 3;
}

int Miscmagic_librams_lyre_and_manuals::mmpHealthReadDaysMax() {
    // the upper edge of the 3-5 days
    return 5;
}

int Miscmagic_librams_lyre_and_manuals::mmpHealthConGain() {
    // the regimen raises constitution by 1 point
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpHealthRegimenMonths() {
    // the diet and breathing run 1 month
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpHealthForgetMonths() {
    // the secrets fade in 3 months
    return 3;
}

int Miscmagic_librams_lyre_and_manuals::mmpExerciseStrGain() {
    // the course adds 1 point of strength
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemKindCount() {
    // 4 sorts of golems
    return 4;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemMinUserLevel() {
    // the maker assumed 10th or higher
    return 10;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemFailurePctPerLevel() {
    // cumulative 10 percent per level under 10th
    return 10;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemFailureWindowTurns() {
    // falls to pieces within 1 turn of completion
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemClericXpLossMin() {
    // a cleric reading loses 10,000 xp
    return 10000;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemClericXpLossMax() {
    // up to 60,000 xp lost
    return 60000;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemMuLevelLoss() {
    // a magic-user reading loses 1 level
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemOtherDamageMin() {
    // any other class suffers 6-36 damage
    return 6;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemOtherDamageMax() {
    // the upper edge of the 6-36 damage
    return 36;
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemDieLo(int i) {
    // the printed die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 6, 18, 19,
    };
    return t[i];
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemDieHi(int i) {
    // the printed die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        5, 17, 18, 20,
    };
    return t[i];
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemMonths(int i) {
    // the construction months per golem sort; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 4, 3,
    };
    return t[i];
}

int Miscmagic_librams_lyre_and_manuals::mmpGolemCostGp(int i) {
    // the construction cost per golem sort; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        65000, 50000, 100000, 80000,
    };
    return t[i];
}

int Miscmagic_librams_lyre_and_manuals::mmpPuissantPracticeMonths() {
    // the fighter practices 1 month
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpPuissantForgetMonths() {
    // the knowledge fades within 3 months
    return 3;
}

int Miscmagic_librams_lyre_and_manuals::mmpPuissantStunTurnsMin() {
    // a scanning magic-user is stunned 1-6 turns
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpPuissantStunTurnsMax() {
    // the upper edge of the 1-6 turn stun
    return 6;
}

int Miscmagic_librams_lyre_and_manuals::mmpPuissantXpLossMin() {
    // the scanning magic-user loses 10,000 xp
    return 10000;
}

int Miscmagic_librams_lyre_and_manuals::mmpPuissantXpLossMax() {
    // up to 60,000 xp lost
    return 60000;
}

int Miscmagic_librams_lyre_and_manuals::mmpQuicknessStudyDays() {
    // 3 days of uninterrupted study
    return 3;
}

int Miscmagic_librams_lyre_and_manuals::mmpQuicknessPracticeMonths() {
    // the skills practiced 1 month
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpQuicknessDexGain() {
    // the practice gains 1 point of dexterity
    return 1;
}

int Miscmagic_librams_lyre_and_manuals::mmpQuicknessRememberMonths() {
    // the contents remembered 3 months
    return 3;
}
