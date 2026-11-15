// ====================================================================
// Adnd1 - rules/dmg/miscmagic_table2_footnotes.h
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

// R1059 applied
#include "rules/seams/miscreg.h"

namespace rules {

inline int m2RowCount() {
    // Candle through Eyes of Petrification
    return 30;
}

inline int m2RowLo(int i) {
    const auto* g = mTable(
        "misc_m2", "row_lo");
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int m2RowHi(int i) {
    const auto* g = mTable(
        "misc_m2", "row_hi");
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    if (!g) return 6;
    return (int)(*g)[i];
}

inline int m2UsableByCleric(int i) {
    const auto* g = mTable(
        "misc_m2", "usable_by_cleric");
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int m2UsableByMagicUser(int i) {
    const auto* g = mTable(
        "misc_m2", "usable_by_mu");
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m2IsPerPlusValued(int i) {
    const auto* g = mTable(
        "misc_m2", "is_per_plus_valued");
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m2HasFeatureAsterisk(int i) {
    const auto* g = mTable(
        "misc_m2", "has_feature_asterisk");
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m2IsTripleStar(int i) {
    const auto* g = mTable(
        "misc_m2", "is_triple_star");
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    if (!g) return 0;
    return (int)(*g)[i];
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

