// R-refactor: split from humanoid_preferences.h - definitions
#include "rules/dmg/humanoid_preferences.h"

int Humanoid_preferences::humRPrefRaceCount() { return 9; }

const char* Humanoid_preferences::humRPrefRaceName(int i) {
    static const char* const k[9] = {
        "bugbear",
        "gnoll",
        "goblin",
        "hill giant",
        "hobgoblin",
        "kobold",
        "ogre",
        "orc",
        "troll"
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

bool Humanoid_preferences::humStrEq(const char* a, const char* b) {
    int i = 0;
    while (a[i] != 0 && b[i] != 0) {
        if (a[i] != b[i]) return false;
        ++i;
    }
    return a[i] == b[i];
}

int Humanoid_preferences::humRPrefRaceIndex(const char* name) {
    for (int i = 0; i < 9; ++i)
        if (humStrEq(humRPrefRaceName(i), name))
            return i;
    return -1;
}

HumRPrefCode Humanoid_preferences::humRPrefCode(int row, int col) {
    static const HumRPrefCode k[9][9] = {
        // bugbear
        { HPREF_P, HPREF_T, HPREF_G, HPREF_T,
          HPREF_A, HPREF_A, HPREF_T, HPREF_A,
          HPREF_N },
        // gnoll
        { HPREF_T, HPREF_P, HPREF_A, HPREF_T,
          HPREF_N, HPREF_A, HPREF_G, HPREF_T,
          HPREF_N },
        // goblin
        { HPREF_G, HPREF_A, HPREF_P, HPREF_N,
          HPREF_T, HPREF_G, HPREF_H, HPREF_N,
          HPREF_A },
        // hill giant
        { HPREF_G, HPREF_G, HPREF_A, HPREF_P,
          HPREF_A, HPREF_A, HPREF_G, HPREF_N,
          HPREF_T },
        // hobgoblin
        { HPREF_T, HPREF_N, HPREF_N, HPREF_N,
          HPREF_H, HPREF_A, HPREF_A, HPREF_T,
          HPREF_H },
        // kobold
        { HPREF_A, HPREF_H, HPREF_G, HPREF_A,
          HPREF_A, HPREF_P, HPREF_H, HPREF_A,
          HPREF_T },
        // ogre
        { HPREF_T, HPREF_T, HPREF_A, HPREF_G,
          HPREF_A, HPREF_A, HPREF_P, HPREF_T,
          HPREF_T },
        // orc
        { HPREF_A, HPREF_N, HPREF_T, HPREF_A,
          HPREF_N, HPREF_A, HPREF_G, HPREF_H,
          HPREF_H },
        // troll
        { HPREF_A, HPREF_N, HPREF_A, HPREF_T,
          HPREF_H, HPREF_T, HPREF_N, HPREF_A,
          HPREF_N }
    };
    if (row < 0) row = 0;
    if (row > 8) row = 8;
    if (col < 0) col = 0;
    if (col > 8) col = 8;
    return k[row][col];
}

int Humanoid_preferences::humRPrefStars(int row, int col) {
    static const int k[9][9] = {
        { 0, 1, 0, 0, 1, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 1, 0, 2, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 0, 1, 1, 0, 1, 0 },
        { 0, 0, 1, 0, 0, 1, 0, 2, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 2 }
    };
    if (row < 0) row = 0;
    if (row > 8) row = 8;
    if (col < 0) col = 0;
    if (col > 8) col = 8;
    return k[row][col];
}

bool Humanoid_preferences::humRPrefBullyMark(int row, int col) {
    return humRPrefStars(row, col) == 1;
}

bool Humanoid_preferences::humRPrefRivalTribe(int row, int col) {
    return humRPrefStars(row, col) == 2;
}

const char* Humanoid_preferences::humRPrefCodeName(HumRPrefCode c) {
    static const char* const k[6] = {
        "preference",
        "goodwill",
        "tolerate",
        "neutral negative",
        "antipathy",
        "hatred"
    };
    if (c < HPREF_P) c = HPREF_P;
    if (c > HPREF_H) c = HPREF_H;
    return k[c];
}

char Humanoid_preferences::humRPrefCodeLetter(HumRPrefCode c) {
    static const char k[6] = {
        'P', 'G', 'T',
        'N', 'A', 'H'
    };
    if (c < HPREF_P) c = HPREF_P;
    if (c > HPREF_H) c = HPREF_H;
    return k[c];
}

bool Humanoid_preferences::humCodeAllowsCoOperation(HumRPrefCode c) {
    return c == HPREF_P || c == HPREF_G;
}

bool Humanoid_preferences::humCodeNoHostilityLikely(HumRPrefCode c) {
    return c == HPREF_T;
}

bool Humanoid_preferences::humCodeNoAidIfIllBefalls(HumRPrefCode c) {
    return c == HPREF_N;
}

bool Humanoid_preferences::humAntipathyDesertIfLeadersWeak() {
    return true;
}

bool Humanoid_preferences::humHatredBreaksOutAtFirstOpportunity() {
    return true;
}

bool Humanoid_preferences::humHatredDesertsNearStrongHatedBody() {
    return true;
}

int Humanoid_preferences::humSideBySideVisibilityRangeInches() {
    return 12;
}

bool Humanoid_preferences::humInterveningTroopsOrScreenBlocks() {
    return true;
}

bool Humanoid_preferences::humDemihumanCompatibilityFromPHBTable() {
    return true;
}

bool Humanoid_preferences::humLizardMenHatedByAllHumanoidsSaveKobolds() {
    return true;
}

bool Humanoid_preferences::humKoboldsSuspiciousOfLizardMen() {
    return true;
}

bool Humanoid_preferences::humHumanTroopsSuspiciousOfLizardMen() {
    return true;
}
