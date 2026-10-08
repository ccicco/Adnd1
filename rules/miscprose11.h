// ====================================================================
// Adnd1 - rules/miscprose11.h
// R267: the III.E misc magic explanation prose part 11
// (DMG p.136-137) - Flask of Curses through the Girdle
// of Giant Strength, part2 lines 481-530 (global =
// 11065 + part2 line). ONE page header strips (493,
// the TREASURE page) cutting the Gem of Brightness
// paragraph mid-sentence (one seam, restored). 63
// accessors: 49 scalars + 14 array walkers (the giant
// strength and rock hurling tables), no name
// collisions with miscprose1.h through miscprose10.h.
// The slice pins kMisc3 rows 1-9, the (C, F, T) marks
// riding rows 4, 5, 8 and 9. Pure data + helpers,
// header-only (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpFlaskCurseOnFirstOpen() {
    // first unstoppering visits a curse nearby
    return 1;
}

inline int mmpFlaskHarmlessAfterUse() {
    // subsequently the flask is harmless
    return 1;
}

inline int mmpGauntDexBoostLow() {
    // +4 dexterity if at 6 or less
    return 4;
}

inline int mmpGauntDexBoostMid() {
    // +2 dexterity if at 7-13
    return 2;
}

inline int mmpGauntDexBoostHigh() {
    // +1 dexterity if at 14 or higher
    return 1;
}

inline int mmpGauntDexThiefLevel() {
    // non-thieves act as a 4th level thief
    return 4;
}

inline int mmpGauntDexThiefBonusPct() {
    // thieves gain +10 percent for their level
    return 10;
}

inline int mmpGauntFumbDropPct() {
    // 50 percent each round of dropping held items
    return 50;
}

inline int mmpGauntFumbDexPenalty() {
    // lowers overall dexterity by 2 points
    return 2;
}

inline int mmpGauntFumbRemoveCurseOnly() {
    // only remove curse or a wish takes them off
    return 1;
}

inline int mmpGauntOgreStrength() {
    // 18/00 strength in hands, arms and shoulders
    return 18;
}

inline int mmpGauntOgreStrengthPercentile() {
    // the 18/00 exceptional percentile
    return 0;
}

inline int mmpGauntOgreHitBonus() {
    // +3 to hit probability
    return 3;
}

inline int mmpGauntOgreDmgBonus() {
    // +6 to damage inflicted
    return 6;
}

inline int mmpGauntSwimUnderwaterInches() {
    // swims as a triton: 15 inches under water
    return 15;
}

inline int mmpGauntSwimSurfaceInches() {
    // swims as a merman: 18 inches on the surface
    return 18;
}

inline int mmpGauntSwimClimbSuccessPct() {
    // 95 percent of not slipping while climbing
    return 95;
}

inline int mmpGauntSwimThiefSuccessTenthPct() {
    // a thief climbs at 99.5 percent (tenths)
    return 995;
}

inline int mmpGemBrightLightSorts() {
    // the gem emits bright light of 3 sorts
    return 3;
}

inline int mmpGemBrightConeLengthFeet() {
    // the pale light cone is 10 feet long
    return 10;
}

inline int mmpGemBrightConeRadiusHalfFeet() {
    // cone radius 2.5 feet at the beam end
    return 5;
}

inline int mmpGemBrightRayDiameterFeet() {
    // the bright ray is 1 feet diameter
    return 1;
}

inline int mmpGemBrightRayLengthFeet() {
    // the bright ray is 50 feet long
    return 50;
}

inline int mmpGemBrightDazzleMinRounds() {
    // dazzled 1-4 rounds
    return 1;
}

inline int mmpGemBrightDazzleMaxRounds() {
    // dazzled 1-4 rounds
    return 4;
}

inline int mmpGemBrightRayCharges() {
    // the ray use expends 1 energy charge
    return 1;
}

inline int mmpGemBrightFlashLengthFeet() {
    // the blinding flash cone is 30 feet long
    return 30;
}

inline int mmpGemBrightFlashRadiusFeet() {
    // flash cone radius 5 feet at its terminus
    return 5;
}

inline int mmpGemBrightBlindMinRounds() {
    // blinded 1-4 rounds
    return 1;
}

inline int mmpGemBrightBlindMaxRounds() {
    // blinded 1-4 rounds
    return 4;
}

inline int mmpGemBrightEyePenaltyMin() {
    // permanent eye damage: -1 at least
    return 1;
}

inline int mmpGemBrightEyePenaltyMax() {
    // permanent eye damage: up to -4
    return 4;
}

inline int mmpGemBrightFlashCharges() {
    // the flash use expends 5 charges
    return 5;
}

inline int mmpGemBrightTotalCharges() {
    // 50 charges, cannot be recharged
    return 50;
}

inline int mmpGemBrightDarknessDrainCharges() {
    // a darkness spell drains 1 charge
    return 1;
}

inline int mmpGemBrightDarknessRoundUseless() {
    // or makes the gem useless for 1 round
    return 1;
}

inline int mmpGemBrightDarknessDayUseless() {
    // continual darkness: useless for 1 day
    return 1;
}

inline int mmpGemBrightDarknessExpelCharges() {
    // or the owner expends 5 charges
    return 5;
}

inline int mmpGemSeeCursoryRangeInches() {
    // cursory scan range 30 inches
    return 30;
}

inline int mmpGemSeeCarefulRangeInches() {
    // small things: 10 inches
    return 10;
}

inline int mmpGemSeeCursoryAreaFeet() {
    // 1 round scans a 200 feet square
    return 200;
}

inline int mmpGemSeeCursoryRounds() {
    // the cursory scan takes 1 round
    return 1;
}

inline int mmpGemSeeCarefulAreaFeet() {
    // 2 rounds view a 100 feet square
    return 100;
}

inline int mmpGemSeeCarefulRounds() {
    // the careful view takes 2 rounds
    return 2;
}

inline int mmpGemSeeHallucinationPct() {
    // 5 percent chance of an hallucination
    return 5;
}

inline int mmpGirdleSexWishRestorePct() {
    // a wish restores the sex: 50 percent
    return 50;
}

inline int mmpGirdleSexSexlessPct() {
    // 10 percent of these remove all sex
    return 10;
}

inline int mmpGirdleGiantTypeCount() {
    // the six giant strength types
    return 6;
}

inline int mmpGirdleGiantRockDmgMin() {
    // every type hurls rocks from 1 die
    return 1;
}

inline int mmpGirdleGiantDiceLo(int i) {
    // the type dice band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 31, 51, 71, 86, 96,
    };
    return t[i];
}

inline int mmpGirdleGiantDiceHi(int i) {
    // the type dice band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        30, 50, 70, 85, 95, 100,
    };
    return t[i];
}

inline int mmpGirdleGiantStrength(int i) {
    // the strength and rating column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        19, 20, 21, 22, 23, 24,
    };
    return t[i];
}

inline int mmpGirdleGiantHitBonus(int i) {
    // the to hit column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 4, 4, 5, 6,
    };
    return t[i];
}

inline int mmpGirdleGiantDmgBonus(int i) {
    // the damage column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 8, 9, 10, 11, 12,
    };
    return t[i];
}

inline int mmpGirdleGiantOpenDoorsTop(int i) {
    // open doors numerator (7 in 8); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 7, 9, 11, 11, 19,
    };
    return t[i];
}

inline int mmpGirdleGiantOpenDoorsBottom(int i) {
    // open doors denominator (in 8); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        8, 8, 10, 12, 12, 20,
    };
    return t[i];
}

inline int mmpGirdleGiantOpenChances(int i) {
    // the parenthesized chances (3 of 6); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 4, 4, 5, 7,
    };
    return t[i];
}

inline int mmpGirdleGiantOpenOutOf(int i) {
    // chances out of 6 (8 for storm); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 6, 6, 6, 6, 8,
    };
    return t[i];
}

inline int mmpGirdleGiantWeightAllowance(int i) {
    // the weight allowance column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4500, 5000, 6000, 7500, 9000, 12000,
    };
    return t[i];
}

inline int mmpGirdleGiantRangeInches(int i) {
    // the rock range column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        8, 16, 10, 12, 14, 16,
    };
    return t[i];
}

inline int mmpGirdleGiantRockDmgMax(int i) {
    // the rock base damage top die; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 12, 8, 8, 10, 12,
    };
    return t[i];
}

inline int mmpGirdleGiantRockWeight(int i) {
    // the approximate average missile weight; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        140, 198, 156, 170, 184, 212,
    };
    return t[i];
}

inline int mmpGirdleGiantBendBarsPct(int i) {
    // bend bars and lift gates percent; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        50, 60, 70, 80, 90, 100,
    };
    return t[i];
}

}  // namespace rules