// ====================================================================
// Adnd1 - rules/miscmagic5.h
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

namespace rules {

inline int m5RowCount() {
    // the Archmagi through the Wings of Flying
    return 35;
}

inline int m5RowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 2, 9, 10, 11, 12, 20, 26, 28, 32,
        33, 34, 35, 36, 39, 41, 47, 48, 49, 51,
        53, 55, 58, 59, 61, 67, 68, 69, 70, 77,
        79, 84, 86, 88, 91,
    };
    return t[i];
}

inline int m5RowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 8, 9, 10, 11, 19, 25, 27, 31, 32,
        33, 34, 35, 38, 40, 46, 47, 48, 50, 52,
        54, 57, 58, 60, 66, 67, 68, 69, 76, 78,
        83, 85, 87, 90, 100,
    };
    return t[i];
}

inline int m5UsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 0, 1, 0,
        1, 0, 0, 0, 0,
    };
    return t[i];
}

inline int m5UsableByFighter(int i) {
    // the (F) mark; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 0, 0, 0, 0,
    };
    return t[i];
}

inline int m5UsableByMagicUser(int i) {
    // the (M) mark; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 0, 1, 1, 1, 1, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int m5UsableByThief(int i) {
    // the (T) mark; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        1, 0, 0, 0, 0,
    };
    return t[i];
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
