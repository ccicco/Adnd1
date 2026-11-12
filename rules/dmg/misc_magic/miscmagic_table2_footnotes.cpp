// R-refactor: split from miscmagic_table2_footnotes.h - definitions
#include "rules/dmg/misc_magic/miscmagic_table2_footnotes.h"

int Miscmagic_table2_footnotes::m2RowCount() {
    // Candle through Eyes of Petrification
    return 30;
}

int Miscmagic_table2_footnotes::m2RowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        1, 7, 9, 11, 12, 14, 15, 19, 28, 31,
        33, 56, 61, 62, 64, 66, 68, 70, 73, 77,
        78, 80, 86, 92, 93, 94, 95, 96, 98, 100,
    };
    return t[i];
}

int Miscmagic_table2_footnotes::m2RowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        6, 8, 10, 11, 13, 14, 18, 27, 30, 32,
        55, 60, 61, 63, 65, 67, 69, 72, 76, 77,
        79, 85, 91, 92, 93, 94, 95, 97, 99, 100,
    };
    return t[i];
}

int Miscmagic_table2_footnotes::m2UsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table2_footnotes::m2UsableByMagicUser(int i) {
    // the (M) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table2_footnotes::m2IsPerPlusValued(int i) {
    // the Cloak of Protection per-plus asterisk row; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table2_footnotes::m2HasFeatureAsterisk(int i) {
    // the Crystal Ball double-asterisk row; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table2_footnotes::m2IsTripleStar(int i) {
    // the Eyes of Petrification triple-asterisk row; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    };
    return t[i];
}

int Miscmagic_table2_footnotes::m2ClericCount() {
    return 1;
}

int Miscmagic_table2_footnotes::m2MagicUserCount() {
    return 5;
}

int Miscmagic_table2_footnotes::m2CloakPerPlusXp() {
    // per plus of protection
    return 1000;
}

int Miscmagic_table2_footnotes::m2CloakPerPlusGp() {
    return 10000;
}

int Miscmagic_table2_footnotes::m2CrystalBallBaseXp() {
    return 1000;
}

int Miscmagic_table2_footnotes::m2CrystalBallBaseGp() {
    return 5000;
}

int Miscmagic_table2_footnotes::m2CrystalBallFeatureBonusPct() {
    // add 100% for each additional
    // feature
    return 100;
}
