// ====================================================================
// Adnd1 - rules/miscmagic1.h
// R225: the III.E table 1 footnote pins
// (DMG p.128) - the class marks and the
// special-row footnotes that frame the
// TABLE (III.E.) 1 miscellaneous magic
// table:
//   - the (C) and (M) class marks
//     (Book of Exalted Deeds and Book
//     of Vile Darkness are (C); the two
//     Bowls and the two Braziers are
//     (M)).
//   - the Artifact or Relic row (17):
//     no values - see the Special table
//     hereafter.
//   - the Bracers of Defense asterisk
//     (60-79): the x.p. and g.p. values
//     are PER ARMOR CLASS POINT above
//     10 (AC 6 is worth 2,000 x.p.,
//     12,000 g.p. if sold - four
//     points).
//   - Bucknard Everfull Purse (99-00):
//     the printed tiered values
//     (1,500/2,500/4,000 x.p.;
//     15,000/25,000/40,000 g.p.) are
//     carried by the R122-pinned row
//     ranges.
// The row identity is the 33 die bands
// of the engine III.E.1 table
// (dm/treasure.cpp kMisc1 order,
// Alchemy Jug 01-02 through Bucknard
// Everfull Purse 99-00). The row VALUES
// were pinned by the R122 line-diff
// audit; this header pins the class
// marks, the special rows and the band
// edges. JUDGMENT: the R122 row for the
// purse pins xp 1500-4000 / gp
// 15000-40000, matching the printed
// tiers as ranges.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int m1RowCount() {
    // Alchemy Jug through the Everfull Purse
    return 33;
}

inline int m1RowLo(int i) {
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

inline int m1RowHi(int i) {
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

inline int m1UsableByMagicUser(int i) {
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

inline int m1UsableByCleric(int i) {
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

inline int m1IsArtifactRelicRow(int i) {
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

inline int m1IsPerAcPointValued(int i) {
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

inline int m1IsTieredPurseRow(int i) {
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

inline int m1MagicUserCount() {
    return 4;
}

inline int m1ClericCount() {
    return 2;
}

inline int m1BracersPerAcXp() {
    // per armor class point above 10
    return 500;
}

inline int m1BracersPerAcGp() {
    return 3000;
}

}  // namespace rules

