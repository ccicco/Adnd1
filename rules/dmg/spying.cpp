// R-refactor: split from spying.h - definitions
#include "rules/dmg/spying.h"

const char* Spying::spyCategoryName(SpyCategory c) {
    static const char* const n[SPY_CATEGORY_COUNT] = {
        "simple", "difficult", "extraordinary"
    };
    if (c < SPY_SIMPLE) c = SPY_SIMPLE;
    if (c >= SPY_CATEGORY_COUNT) c = SPY_EXTRAORDINARY;
    return n[c];
}

int Spying::spySuccessChance(int level, SpyCategory c) {
    static const int k[17][SPY_CATEGORY_COUNT] = {
        { 50, 30, 10 },
        { 55, 35, 15 },
        { 60, 35, 15 },
        { 65, 40, 20 },
        { 70, 45, 25 },
        { 75, 50, 25 },
        { 80, 55, 30 },
        { 85, 60, 35 },
        { 85, 60, 40 },
        { 90, 65, 45 },
        { 90, 65, 50 },
        { 95, 65, 50 },
        { 95, 70, 50 },
        { 95, 70, 50 },
        { 95, 75, 50 },
        { 95, 75, 55 },
        { 95, 75, 60 },
    };
    if (level < 1) level = 1;
    if (level > 17) level = 17;
    if (c < SPY_SIMPLE) c = SPY_SIMPLE;
    if (c >= SPY_CATEGORY_COUNT) c = SPY_EXTRAORDINARY;
    return k[level - 1][c];
}

int Spying::spyHiredLevelCap() { return 8; }

void Spying::spyMissionDays(SpyCategory c, int& lo, int& hi) {
    if (c == SPY_SIMPLE) { lo = 1; hi = 8; return; }
    if (c == SPY_DIFFICULT) { lo = 5; hi = 40; return; }
    lo = 0; hi = 0;
}

int Spying::spyModifiedDiscoveryChance(int daysSpent, int spyLevel) {
    int base = daysSpent;
    if (base > 10) base = 10;
    if (base < 0) base = 0;
    int chance = base - spyLevel;
    if (chance < 1) chance = 1;
    return chance;
}

int Spying::spyPrecautionChecksPerWeek(SpyPrecautions p) {
    static const int k[4] = { 1, 1, 2, 2 };
    if (p < SPYP_NONE) p = SPYP_NONE;
    if (p > SPYP_STRONG) p = SPYP_STRONG;
    return k[p];
}

int Spying::spyDiscoveryCheckPercent(SpyPrecautions p, int modifiedPercent) {
    if (p < SPYP_NONE) p = SPYP_NONE;
    if (p > SPYP_STRONG) p = SPYP_STRONG;
    if (p == SPYP_NONE) return 1;   // flat, per the print
    if (p == SPYP_STRONG) return 2 * modifiedPercent;
    return modifiedPercent;
}

int Spying::spyPostCaptureWindowLo() { return 20; }

int Spying::spyPostCaptureWindowHi() { return 50; }

int Spying::spyPostCaptureChanceMultiple() { return 10; }

SpyFailureResult Spying::spyFailureResult(int d100) {
    if (d100 < 36) return SPYF_RETRY;
    if (d100 < 61) return SPYF_COMPROMISED_90;
    if (d100 < 81) return SPYF_IMPRISONED_SILENT;
    if (d100 < 96) return SPYF_CAUGHT_TORTURED;
    return SPYF_KILLED_OR_TURNED;
}

int Spying::spyFailureScoreAdj(SpyCategory c, bool discovered) {
    int adj = 0;
    if (c == SPY_DIFFICULT) adj += 10;
    if (c == SPY_EXTRAORDINARY) adj -= 5;
    if (discovered) adj += 25;
    return adj;
}

SpyTortureOutcome Spying::spyTortureOutcome(int d6) {
    if (d6 <= 2) return SPYT_DEAD;
    if (d6 <= 4) return SPYT_REVEALED;
    return SPYT_TURNCOAT;
}

int Spying::spyCompromisedFailChance() { return 90; }

bool Spying::spyFanaticalNeverDoubleAgent() { return true; }

bool Spying::spyFanaticalSuicided(int diceTotal) {
    return diceTotal > 60;
}
