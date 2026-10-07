// ====================================================================
// Adnd1 - rules/specart.h
// R240: the III.E Special artifacts pins
// (DMG p.130-131) - the g.p. sale value
// table that closes the III.E magic item
// block, TABLE (III.E.) Special.:
//   - 29 artifact rows, the Axe of the
//     Dwarvish Lords 01 through the Wand
//     of Orcus 00 (the 00 band pins as
//     100, the R122 convention).
//   - the printed sale values: 26
//     single-value rows (the Axe 55,000,
//     the Baba Yaga Hut 90,000, the
//     Jacinth of Inestimable Beauty
//     100,000, the Mighty Servant of
//     Leuk-O 185,000, the Sceptre of
//     Might 150,000, the Sword of Kas
//     97,000).
//   - the Orb of the Dragonkind 41-47
//     prints a RANGE, 10-80,000 (read
//     10,000 through 80,000): a uniform
//     roll between the bounds (the R225
//     dual-value analog, count 1).
//   - the Teeth of Dahlver-Nar 93-98
//     print 5,000/tooth - the per-tooth
//     convention (count 1).
//   - the Throne of the Gods 99 prints
//     NO sale value (priceless) - pinned
//     as 0 g.p. (count 1).
//   - the no-x.p. convention: the table
//     footnote reads These items bring no
//     experience points. - every row of
//     the table (all 29).
// The row identity is the 29 die bands of
// the engine Special artifacts table
// (dm/treasure.cpp kArtifacts order).
// The row NAMES were pinned by the R122
// line-diff audit; this header pins the
// sale values, band edges and the value
// conventions.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int saRowCount() {
    // the Axe through the Wand of Orcus
    return 29;
}

inline int saRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        1, 2, 3, 5, 21, 22, 23, 25, 26, 27,
        28, 30, 32, 33, 34, 36, 38, 39, 41, 48,
        64, 65, 67, 69, 75, 92, 93, 99, 100,
    };
    return t[i];
}

inline int saRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        1, 2, 4, 20, 21, 22, 24, 25, 26, 27,
        29, 31, 32, 33, 35, 37, 38, 40, 47, 63,
        64, 66, 68, 74, 91, 92, 98, 99, 100,
    };
    return t[i];
}

inline int saSaleGp(int i) {
    // the printed g.p. sale values; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        55000, 90000, 62500, 50000, 75000, 85000, 35000, 60000,
        25000, 20000, 47500, 50000, 100000, 40000, 27500, 35000,
        72500, 185000, 10000, 100000, 112500, 80000, 17500, 25000,
        150000, 97000, 5000, 0, 10000,
    };
    return t[i];
}

inline int saSaleGpHi(int i) {
    // the range upper bound (the Orb only); i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 80000, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int saXpValue(int i) {
    // the no-x.p. convention - all rows zero; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int saNoXpRowCount() {
    // every row brings no experience points
    return 29;
}

inline int saDualRangeCount() {
    // the Orb of the Dragonkind 10-80,000
    return 1;
}

inline int saNoSaleRowCount() {
    // the Throne of the Gods prints no sale value
    return 1;
}

inline int saPerToothRowCount() {
    // the Teeth of Dahlver-Nar 5,000/tooth
    return 1;
}

}  // namespace rules
