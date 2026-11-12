// R-refactor: split from rodswands.h - definitions
#include "rules/dmg/rodswands.h"

int Rodswands::rswRowCount() {
    // Absorption through Wand of Wonder
    return 30;
}

int Rodswands::rswRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        1, 4, 5, 15, 17, 18, 19, 20, 21, 23,
        24, 25, 28, 32, 34, 35, 39, 42, 45, 48,
        53, 57, 60, 69, 74, 79, 87, 90, 93, 95,
    };
    return t[i];
}

int Rodswands::rswRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        3, 4, 14, 16, 17, 18, 19, 20, 22, 23,
        24, 27, 31, 33, 34, 38, 41, 44, 47, 52,
        56, 59, 68, 73, 78, 86, 89, 92, 94, 100,
    };
    return t[i];
}

int Rodswands::rswUsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        1, 1, 0, 0, 1, 0, 1, 1, 1, 0,
        0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Rodswands::rswUsableByMagicUser(int i) {
    // the (M) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        1, 1, 0, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 1, 1, 0,
        1, 1, 0, 0, 0, 0, 1, 1, 0, 0,
    };
    return t[i];
}

int Rodswands::rswUsableByFighter(int i) {
    // the (F) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Rodswands::rswUsableByThief(int i) {
    // the (T) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Rodswands::rswAnyClass(int i) {
    // the (any) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
        0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
    };
    return t[i];
}

int Rodswands::rswFullChargesAssumed() {
    // the column-header asterisk: the
    // x.p. and g.p. values assume full
    // charges are in the item
    return 1;
}
