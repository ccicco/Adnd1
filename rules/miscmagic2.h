// ====================================================================
// Adnd1 - rules/miscmagic2.h
// R226: the III.E table 2 footnote pins
// (DMG p.128) - the class marks and the
// asterisk rows that frame TABLE
// (III.E.) 2 of the miscellaneous magic
// tables:
//   - the (C) mark: Candle of
//     Invocation (cleric only).
//   - the (M) marks: the two Censers,
//     Crystal Ball, Crystal Hypnosis
//     Ball, Eyes of Charming.
//   - the Cloak of Protection asterisk
//     (33-55): the 1,000 x.p. / 10,000
//     g.p. values are PER PLUS of
//     protection.
//   - the Crystal Ball double asterisk
//     (56-60): add 100% for each
//     additional feature (base 1,000
//     x.p. / 5,000 g.p.).
//   - the Eyes of Petrification triple
//     asterisk (00): the print carries
//     ---*** in both value columns.
// The row identity is the 30 die bands
// of the engine III.E.2 table
// (dm/treasure.cpp kMisc2 order,
// Candle of Invocation 01-06 through
// Eyes of Petrification 00). The row
// VALUES were pinned by the R122
// line-diff audit; this header pins the
// class marks, the asterisk rows and the
// band edges.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int m2RowCount() {
    // Candle through Eyes of Petrification
    return 30;
}

inline int m2RowLo(int i) {
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

inline int m2RowHi(int i) {
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

inline int m2UsableByCleric(int i) {
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

inline int m2UsableByMagicUser(int i) {
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

inline int m2IsPerPlusValued(int i) {
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

inline int m2HasFeatureAsterisk(int i) {
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

inline int m2IsTripleStar(int i) {
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

inline int m2ClericCount() {
    return 1;
}

inline int m2MagicUserCount() {
    return 5;
}

inline int m2CloakPerPlusXp() {
    // per plus of protection
    return 1000;
}

inline int m2CloakPerPlusGp() {
    return 10000;
}

inline int m2CrystalBallBaseXp() {
    return 1000;
}

inline int m2CrystalBallBaseGp() {
    return 5000;
}

inline int m2CrystalBallFeatureBonusPct() {
    // add 100% for each additional
    // feature
    return 100;
}

}  // namespace rules

