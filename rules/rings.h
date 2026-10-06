// ====================================================================
// Adnd1 - rules/rings.h
// R223: the III.C rings footnote pins
// (DMG p.127) - the two footnotes that
// frame the III.C RINGS table:
//   - the (M) ring: magic-user use
//     only (Ring of Wizardry).
//   - the double-dagger rings: these
//     contain the most powerful magical
//     abilities and may possess only a
//     limited number of magical charges
//     before being depleted, at the DM
//     option (Djinni Summoning, Human
//     Influence, Mammal Control,
//     Multiple Wishes, Telekinesis,
//     Three Wishes, and Wizardry -
//     seven rings).
// The row identity is the 24 die bands
// of the engine III.C table
// (dm/treasure.cpp kRings order,
// Contrariness 01-06 through X-Ray
// Vision 00). The row VALUES were
// pinned by the R122 line-diff audit;
// this header pins the footnote flags
// and the band edges. JUDGMENT, named
// in place: Ring of Wizardry prints
// BOTH the double-dagger and the (M);
// both flags are set.
// Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int ringRowCount() {
    // Contrariness through X-Ray Vision
    return 24;
}

inline int ringRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    static const int t[24] = {
        1, 7, 13, 15, 16, 22, 28, 31, 34, 41,
        44, 45, 61, 62, 64, 66, 70, 76, 78, 80,
        86, 91, 99, 100,
    };
    return t[i];
}

inline int ringRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    static const int t[24] = {
        6, 12, 14, 15, 21, 27, 30, 33, 40, 43,
        44, 60, 61, 63, 65, 69, 75, 77, 79, 85,
        90, 98, 99, 100,
    };
    return t[i];
}

inline int ringIsMuOnly(int i) {
    // the (M) mark: magic-user use only; i clamps
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    static const int t[24] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0,
    };
    return t[i];
}

inline int ringMuOnlyCount() {
    return 1;
}

inline int ringIsChargeLimited(int i) {
    // the double-dagger charge-limited rows; i clamps
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    static const int t[24] = {
        0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 1, 1, 0,
        0, 0, 1, 0,
    };
    return t[i];
}

inline int ringChargeLimitedCount() {
    // Djinni Summoning, Human Influence,
    // Mammal Control, Multiple Wishes,
    // Telekinesis, Three Wishes, Wizardry
    return 7;
}

}  // namespace rules

