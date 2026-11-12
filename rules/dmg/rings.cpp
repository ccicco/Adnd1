// R-refactor: split from rings.h - definitions
#include "rules/dmg/rings.h"

int Rings::ringRowCount() {
    // Contrariness through X-Ray Vision
    return 24;
}

int Rings::ringRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    static const int t[24] = {
        1, 7, 13, 15, 16, 22, 28, 31, 34, 41,
        44, 45, 61, 62, 64, 66, 70, 76, 78, 80,
        86, 91, 99, 100,
    };
    return t[i];
}

int Rings::ringRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    static const int t[24] = {
        6, 12, 14, 15, 21, 27, 30, 33, 40, 43,
        44, 60, 61, 63, 65, 69, 75, 77, 79, 85,
        90, 98, 99, 100,
    };
    return t[i];
}

int Rings::ringIsMuOnly(int i) {
    // the (M) mark: magic-user use only; i clamps
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    static const int t[24] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0,
    };
    return t[i];
}

int Rings::ringMuOnlyCount() {
    return 1;
}

int Rings::ringIsChargeLimited(int i) {
    // the double-dagger charge-limited rows
    // (the R255 fix: row 9 Mammal Control
    // flagged, row 11 Protection not); i clamps
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    static const int t[24] = {
        0, 0, 1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1, 1, 0,
        0, 0, 1, 0,
    };
    return t[i];
}

int Rings::ringChargeLimitedCount() {
    // Djinni Summoning, Human Influence,
    // Mammal Control, Multiple Wishes,
    // Telekinesis, Three Wishes, Wizardry
    return 7;
}
