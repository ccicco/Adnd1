// ====================================================================
// Adnd1 - rules/dmg/specart.h
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

// R1062 applied
#include "rules/seams/specreg.h"

namespace rules {

inline int saRowCount() {
    // the Axe through the Wand of Orcus
    return 29;
}

inline int saRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    const auto* g = saTable(
        "specart", "row_lo");
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int saRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    const auto* g = saTable(
        "specart", "row_hi");
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int saSaleGp(int i) {
    // the printed g.p. sale values; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    const auto* g = saTable(
        "specart", "sale_gp");
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int saSaleGpHi(int i) {
    // the range upper bound (the Orb only); i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    const auto* g = saTable(
        "specart", "sale_gp_hi");
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int saXpValue(int i) {
    // the no-x.p. convention - all rows zero; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    const auto* g = saTable(
        "specart", "xp_value");
    if (!g) return 0;
    return (int)(*g)[i];
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
