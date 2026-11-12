// R-refactor: split from miscmagic_table1_footnotes.h - definitions
#include "rules/dmg/misc_magic/table1_footnotes.h"

int Miscmagic_table1_footnotes::m1RowCount() {
    // Alchemy Jug through the Everfull Purse
    return 33;
}

int Miscmagic_table1_footnotes::m1RowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        1, 3, 5, 6, 8, 12, 14, 17, 18, 21,
        22, 27, 28, 30, 32, 33, 34, 35, 36, 37,
        43, 48, 52, 56, 59, 60, 80, 82, 85, 86,
        93, 94, 99,
    };
    return t[i];
}

int Miscmagic_table1_footnotes::m1RowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        2, 4, 5, 7, 11, 13, 16, 17, 20, 21,
        26, 27, 29, 31, 32, 33, 34, 35, 36, 42,
        47, 51, 55, 58, 59, 79, 81, 84, 85, 92,
        93, 98, 100,
    };
    return t[i];
}

int Miscmagic_table1_footnotes::m1UsableByMagicUser(int i) {
    // the (M) mark; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 0, 0, 1, 1, 0,
        0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table1_footnotes::m1UsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table1_footnotes::m1IsArtifactRelicRow(int i) {
    // the Artifact or Relic row (see the Special table); i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table1_footnotes::m1IsPerAcPointValued(int i) {
    // the Bracers of Defense asterisk row; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table1_footnotes::m1IsTieredPurseRow(int i) {
    // the Bucknard Everfull Purse tiered-values row; i clamps
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    static const int t[33] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1,
    };
    return t[i];
}

int Miscmagic_table1_footnotes::m1MagicUserCount() {
    return 4;
}

int Miscmagic_table1_footnotes::m1ClericCount() {
    return 2;
}

int Miscmagic_table1_footnotes::m1BracersPerAcXp() {
    // per armor class point above 10
    return 500;
}

int Miscmagic_table1_footnotes::m1BracersPerAcGp() {
    return 3000;
}
