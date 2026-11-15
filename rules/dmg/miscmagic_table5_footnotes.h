// ====================================================================
// Adnd1 - rules/dmg/miscmagic_table5_footnotes.h
// R239: the III.E table 5 footnote pins
// (DMG p.130) - the class marks that frame
// TABLE (III.E.) 5 of the miscellaneous
// magic tables (the last sub-table):
//   - the (M) marks: the Robe of the
//     Archmagi, Robe of Eyes, Robe of
//     Powerlessness, Robe of Scintillating
//     Colors (with C), Robe of Useful
//     Items, Rug of Welcome, Sphere of
//     Annihilation and Talisman of the
//     Sphere.
//   - the (C) marks: the Robe of
//     Scintillating Colors (with M), the
//     Talisman of Pure Good, the Talisman
//     of Ultimate Evil and the two
//     command/warning Tridents (with F
//     and T).
//   - the (F) marks: the Saw of Mighty
//     Cutting, the Spade of Colossal
//     Excavation, the Trident of Submission
//     and the two command/warning Tridents.
//   - the (T) marks: the Tridents of Fish
//     Command and Warning.
// NO asterisk rows, dual-value rows or
// footnotes ride this table (verified: the
// print runs straight from the 91-00 Wings
// of Flying row to the TABLE (III.E.)
// Special artifacts table).
// The row identity is the 35 die bands of
// the engine III.E.5 table (dm/treasure.cpp
// kMisc5 order, the Robe of the Archmagi
// 01 through the Wings of Flying 91-00).
// The row VALUES were pinned by the R122
// line-diff audit; this header pins the
// class marks and the band edges.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R1059 applied
#include "rules/seams/miscreg.h"

namespace rules {

inline int m5RowCount() {
    // the Archmagi through the Wings of Flying
    return 35;
}

inline int m5RowLo(int i) {
    const auto* g = mTable(
        "misc_m5", "row_lo");
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int m5RowHi(int i) {
    const auto* g = mTable(
        "misc_m5", "row_hi");
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int m5UsableByCleric(int i) {
    const auto* g = mTable(
        "misc_m5", "usable_by_cleric");
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m5UsableByFighter(int i) {
    const auto* g = mTable(
        "misc_m5", "usable_by_fighter");
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m5UsableByMagicUser(int i) {
    const auto* g = mTable(
        "misc_m5", "usable_by_mu");
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    if (!g) return 1;
    return (int)(*g)[i];
}

inline int m5UsableByThief(int i) {
    const auto* g = mTable(
        "misc_m5", "usable_by_thief");
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    if (!g) return 0;
    return (int)(*g)[i];
}

inline int m5ClericCount() {
    return 5;
}

inline int m5FighterCount() {
    return 5;
}

inline int m5MagicUserCount() {
    return 8;
}

inline int m5ThiefCount() {
    return 2;
}

}  // namespace rules
