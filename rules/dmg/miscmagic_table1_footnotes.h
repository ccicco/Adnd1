// ====================================================================
// Adnd1 - rules/dmg/miscmagic_table1_footnotes.h
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

// R1059 applied
#include "rules/seams/miscreg.h"

namespace rules {

inline int m1RowCount() {
    // Alchemy Jug through the Everfull Purse
    return 33;
}

inline int m1RowLo(int i) {
    const auto* g = mTable(
        "misc_m1", "row_lo");
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int m1RowHi(int i) {
    const auto* g = mTable(
        "misc_m1", "row_hi");
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    if (!g) return 2;
    return (int)(*g)[i];
}

inline int m1UsableByMagicUser(int i) {
    const auto* g = mTable(
        "misc_m1", "usable_by_mu");
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m1UsableByCleric(int i) {
    const auto* g = mTable(
        "misc_m1", "usable_by_cleric");
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m1IsArtifactRelicRow(int i) {
    const auto* g = mTable(
        "misc_m1", "is_artifact_relic");
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m1IsPerAcPointValued(int i) {
    const auto* g = mTable(
        "misc_m1", "is_per_ac_point");
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m1IsTieredPurseRow(int i) {
    const auto* g = mTable(
        "misc_m1", "is_tiered_purse");
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    if (!g) return 0;
    return (int)(*g)[i];
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

