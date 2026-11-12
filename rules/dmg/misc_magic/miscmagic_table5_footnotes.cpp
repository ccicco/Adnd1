// R-refactor: split from miscmagic_table5_footnotes.h - definitions
#include "rules/dmg/misc_magic/miscmagic_table5_footnotes.h"

int Miscmagic_table5_footnotes::m5RowCount() {
    // the Archmagi through the Wings of Flying
    return 35;
}

int Miscmagic_table5_footnotes::m5RowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 2, 9, 10, 11, 12, 20, 26, 28, 32,
        33, 34, 35, 36, 39, 41, 47, 48, 49, 51,
        53, 55, 58, 59, 61, 67, 68, 69, 70, 77,
        79, 84, 86, 88, 91,
    };
    return t[i];
}

int Miscmagic_table5_footnotes::m5RowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 8, 9, 10, 11, 19, 25, 27, 31, 32,
        33, 34, 35, 38, 40, 46, 47, 48, 50, 52,
        54, 57, 58, 60, 66, 67, 68, 69, 76, 78,
        83, 85, 87, 90, 100,
    };
    return t[i];
}

int Miscmagic_table5_footnotes::m5UsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 0, 1, 0,
        1, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table5_footnotes::m5UsableByFighter(int i) {
    // the (F) mark; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table5_footnotes::m5UsableByMagicUser(int i) {
    // the (M) mark; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 0, 1, 1, 1, 1, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table5_footnotes::m5UsableByThief(int i) {
    // the (T) mark; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        1, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table5_footnotes::m5ClericCount() {
    return 5;
}

int Miscmagic_table5_footnotes::m5FighterCount() {
    return 5;
}

int Miscmagic_table5_footnotes::m5MagicUserCount() {
    return 8;
}

int Miscmagic_table5_footnotes::m5ThiefCount() {
    return 2;
}
