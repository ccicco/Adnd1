// R-refactor: split from miscmagic_table4_footnotes.h - definitions
#include "rules/dmg/miscmagic_table4_footnotes.h"

int Miscmagic_table4_footnotes::m4RowCount() {
    // the Librams through the Feather Token
    return 36;
}

int Miscmagic_table4_footnotes::m4RowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 16, 18, 19, 20, 21, 24, 28,
        34, 36, 39, 43, 45, 47, 49, 51, 54, 61,
        65, 71, 75, 77, 85, 86,
    };
    return t[i];
}

int Miscmagic_table4_footnotes::m4RowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 15, 17, 18, 19, 20, 23, 27, 33,
        35, 38, 42, 44, 46, 48, 50, 53, 60, 64,
        70, 74, 76, 84, 85, 100,
    };
    return t[i];
}

int Miscmagic_table4_footnotes::m4UsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 1, 1, 0, 0, 1, 0, 0, 0, 0,
        1, 1, 1, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table4_footnotes::m4UsableByFighter(int i) {
    // the (F) mark; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table4_footnotes::m4UsableByMagicUser(int i) {
    // the (M) mark; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        1, 1, 1, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table4_footnotes::m4UsableByThief(int i) {
    // the (T) mark; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table4_footnotes::m4StarCount(int i) {
    // the asterisk ladder: 1 the Necklace of
    // Missiles (per hit die of each missile),
    // 2 the Prayer Beads (per special bead),
    // 3 the Marvelous Pigments (per pot),
    // 4 the Pearl of Power (per level of
    // spell); i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 2,
        0, 0, 0, 3, 4, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Miscmagic_table4_footnotes::m4IsDualValued(int i) {
    // the dual-value rows: the Medallion of
    // ESP (13-15) and the Feather Token
    // (86-00); i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1,
    };
    return t[i];
}

int Miscmagic_table4_footnotes::m4ClericCount() {
    return 8;
}

int Miscmagic_table4_footnotes::m4FighterCount() {
    return 4;
}

int Miscmagic_table4_footnotes::m4MagicUserCount() {
    return 6;
}

int Miscmagic_table4_footnotes::m4ThiefCount() {
    return 3;
}

int Miscmagic_table4_footnotes::m4MissilePerHitDieXp() {
    // per hit die of each missile
    return 50;
}

int Miscmagic_table4_footnotes::m4MissilePerHitDieGp() {
    return 200;
}

int Miscmagic_table4_footnotes::m4BeadPerSpecialXp() {
    // per special bead
    return 500;
}

int Miscmagic_table4_footnotes::m4BeadPerSpecialGp() {
    return 3000;
}

int Miscmagic_table4_footnotes::m4PigmentsPerPotXp() {
    // per pot of pigments
    return 500;
}

int Miscmagic_table4_footnotes::m4PigmentsPerPotGp() {
    return 3000;
}

int Miscmagic_table4_footnotes::m4PearlPerSpellLevelXp() {
    // per level of spell
    return 200;
}

int Miscmagic_table4_footnotes::m4PearlPerSpellLevelGp() {
    return 2000;
}

int Miscmagic_table4_footnotes::m4MedallionEspXpLow() {
    return 1000;
}

int Miscmagic_table4_footnotes::m4MedallionEspXpHigh() {
    return 3000;
}

int Miscmagic_table4_footnotes::m4MedallionEspGpLow() {
    return 10000;
}

int Miscmagic_table4_footnotes::m4MedallionEspGpHigh() {
    return 30000;
}

int Miscmagic_table4_footnotes::m4FeatherTokenXpLow() {
    return 500;
}

int Miscmagic_table4_footnotes::m4FeatherTokenXpHigh() {
    return 1000;
}

int Miscmagic_table4_footnotes::m4FeatherTokenGpLow() {
    return 2000;
}

int Miscmagic_table4_footnotes::m4FeatherTokenGpHigh() {
    return 7000;
}
