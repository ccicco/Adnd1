// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/miscmagic_flask_of_curses_to_girdle_of_giant_strength.h"

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpFlaskCurseOnFirstOpen() {
    // first unstoppering visits a curse nearby
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpFlaskHarmlessAfterUse() {
    // subsequently the flask is harmless
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntDexBoostLow() {
    // +4 dexterity if at 6 or less
    return 4;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntDexBoostMid() {
    // +2 dexterity if at 7-13
    return 2;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntDexBoostHigh() {
    // +1 dexterity if at 14 or higher
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntDexThiefLevel() {
    // non-thieves act as a 4th level thief
    return 4;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntDexThiefBonusPct() {
    // thieves gain +10 percent for their level
    return 10;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntFumbDropPct() {
    // 50 percent each round of dropping held items
    return 50;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntFumbDexPenalty() {
    // lowers overall dexterity by 2 points
    return 2;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntFumbRemoveCurseOnly() {
    // only remove curse or a wish takes them off
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntOgreStrength() {
    // 18/00 strength in hands, arms and shoulders
    return 18;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntOgreStrengthPercentile() {
    // the 18/00 exceptional percentile
    return 0;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntOgreHitBonus() {
    // +3 to hit probability
    return 3;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntOgreDmgBonus() {
    // +6 to damage inflicted
    return 6;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntSwimUnderwaterInches() {
    // swims as a triton: 15 inches under water
    return 15;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntSwimSurfaceInches() {
    // swims as a merman: 18 inches on the surface
    return 18;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntSwimClimbSuccessPct() {
    // 95 percent of not slipping while climbing
    return 95;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGauntSwimThiefSuccessTenthPct() {
    // a thief climbs at 99.5 percent (tenths)
    return 995;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightLightSorts() {
    // the gem emits bright light of 3 sorts
    return 3;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightConeLengthFeet() {
    // the pale light cone is 10 feet long
    return 10;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightConeRadiusHalfFeet() {
    // cone radius 2.5 feet at the beam end
    return 5;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightRayDiameterFeet() {
    // the bright ray is 1 feet diameter
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightRayLengthFeet() {
    // the bright ray is 50 feet long
    return 50;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightDazzleMinRounds() {
    // dazzled 1-4 rounds
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightDazzleMaxRounds() {
    // dazzled 1-4 rounds
    return 4;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightRayCharges() {
    // the ray use expends 1 energy charge
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightFlashLengthFeet() {
    // the blinding flash cone is 30 feet long
    return 30;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightFlashRadiusFeet() {
    // flash cone radius 5 feet at its terminus
    return 5;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightBlindMinRounds() {
    // blinded 1-4 rounds
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightBlindMaxRounds() {
    // blinded 1-4 rounds
    return 4;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightEyePenaltyMin() {
    // permanent eye damage: -1 at least
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightEyePenaltyMax() {
    // permanent eye damage: up to -4
    return 4;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightFlashCharges() {
    // the flash use expends 5 charges
    return 5;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightTotalCharges() {
    // 50 charges, cannot be recharged
    return 50;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightDarknessDrainCharges() {
    // a darkness spell drains 1 charge
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightDarknessRoundUseless() {
    // or makes the gem useless for 1 round
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightDarknessDayUseless() {
    // continual darkness: useless for 1 day
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemBrightDarknessExpelCharges() {
    // or the owner expends 5 charges
    return 5;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemSeeCursoryRangeInches() {
    // cursory scan range 30 inches
    return 30;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemSeeCarefulRangeInches() {
    // small things: 10 inches
    return 10;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemSeeCursoryAreaFeet() {
    // 1 round scans a 200 feet square
    return 200;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemSeeCursoryRounds() {
    // the cursory scan takes 1 round
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemSeeCarefulAreaFeet() {
    // 2 rounds view a 100 feet square
    return 100;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemSeeCarefulRounds() {
    // the careful view takes 2 rounds
    return 2;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGemSeeHallucinationPct() {
    // 5 percent chance of an hallucination
    return 5;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleSexWishRestorePct() {
    // a wish restores the sex: 50 percent
    return 50;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleSexSexlessPct() {
    // 10 percent of these remove all sex
    return 10;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantTypeCount() {
    // the six giant strength types
    return 6;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantRockDmgMin() {
    // every type hurls rocks from 1 die
    return 1;
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantDiceLo(int i) {
    // the type dice band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        1, 31, 51, 71, 86, 96,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantDiceHi(int i) {
    // the type dice band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        30, 50, 70, 85, 95, 100,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantStrength(int i) {
    // the strength and rating column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        19, 20, 21, 22, 23, 24,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantHitBonus(int i) {
    // the to hit column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 4, 4, 5, 6,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantDmgBonus(int i) {
    // the damage column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 8, 9, 10, 11, 12,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantOpenDoorsTop(int i) {
    // open doors numerator (7 in 8); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        7, 7, 9, 11, 11, 19,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantOpenDoorsBottom(int i) {
    // open doors denominator (in 8); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        8, 8, 10, 12, 12, 20,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantOpenChances(int i) {
    // the parenthesized chances (3 of 6); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        3, 3, 4, 4, 5, 7,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantOpenOutOf(int i) {
    // chances out of 6 (8 for storm); i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 6, 6, 6, 6, 8,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantWeightAllowance(int i) {
    // the weight allowance column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        4500, 5000, 6000, 7500, 9000, 12000,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantRangeInches(int i) {
    // the rock range column; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        8, 16, 10, 12, 14, 16,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantRockDmgMax(int i) {
    // the rock base damage top die; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        6, 12, 8, 8, 10, 12,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantRockWeight(int i) {
    // the approximate average missile weight; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        140, 198, 156, 170, 184, 212,
    };
    return t[i];
}

int Miscmagic_flask_of_curses_to_girdle_of_giant_strength::mmpGirdleGiantBendBarsPct(int i) {
    // bend bars and lift gates percent; i clamps
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    static const int t[6] = {
        50, 60, 70, 80, 90, 100,
    };
    return t[i];
}
