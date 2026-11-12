// R-refactor: split from potions.h - definitions
#include "rules/dmg/potions.h"

int Potions::potionRowCount() {
    // Animal Control through Water Breathing
    return 35;
}

int Potions::potionRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 4, 7, 10, 13, 16, 19, 21, 24, 27,
        30, 33, 35, 37, 40, 42, 48, 50, 52, 55,
        58, 61, 64, 67, 70, 73, 76, 79, 82, 85,
        88, 91, 94, 97, 98,
    };
    return t[i];
}

int Potions::potionRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        3, 6, 9, 12, 15, 18, 20, 23, 26, 29,
        32, 34, 36, 39, 41, 47, 49, 51, 54, 57,
        60, 63, 66, 69, 72, 75, 78, 81, 84, 87,
        90, 93, 96, 97, 100,
    };
    return t[i];
}

int Potions::potionIsControl(int i) {
    // effectiveness on the type of creature
    // controlled must be determined by die
    // roll; consult the item explanation
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 1, 1, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0,
    };
    return t[i];
}

int Potions::potionControlCount() {
    return 6;
}

int Potions::potionIsMislead(int i) {
    // the DM must mislead the holder so as
    // to convince him the potion is not
    // harmful; see the item descriptions
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0,
    };
    return t[i];
}

int Potions::potionMisleadCount() {
    return 2;
}

int Potions::potionIsFighterOnly(int i) {
    // fighters only may use
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
    };
    return t[i];
}

int Potions::potionFighterOnlyCount() {
    return 4;
}
