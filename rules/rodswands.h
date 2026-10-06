// ====================================================================
// Adnd1 - rules/rodswands.h
// R224: the III.D rods/staves/wands
// footnote pins (DMG pp.127-128) - the
// class-usable marks and the
// full-charges asterisk that frame the
// III.D RODS, STAVES, & WANDS table:
//   - (C) usable by the cleric class
//     only; (M) magic-user only; (F)
//     fighter only; (T) thief only;
//     (any) usable by any class unless
//     otherwise prohibited.
//   - The column-header asterisk: both
//     the x.p. and g.p. values assume
//     FULL charges are in the item.
// The row identity is the 30 die bands
// of the engine III.D table
// (dm/treasure.cpp kRods order, Rod of
// Absorption 01-03 through Wand of
// Wonder 95-00). The row VALUES were
// pinned by the R122 line-diff audit;
// this header pins the class marks
// and the band edges. JUDGMENT, named
// in place: the (any) rows carry no
// individual class marks - the any flag
// and the four class flags are
// mutually exclusive per row.
// Pure data + helpers, header-only
// (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int rswRowCount() {
    // Absorption through Wand of Wonder
    return 30;
}

inline int rswRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        1, 4, 5, 15, 17, 18, 19, 20, 21, 23,
        24, 25, 28, 32, 34, 35, 39, 42, 45, 48,
        53, 57, 60, 69, 74, 79, 87, 90, 93, 95,
    };
    return t[i];
}

inline int rswRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        3, 4, 14, 16, 17, 18, 19, 20, 22, 23,
        24, 27, 31, 33, 34, 38, 41, 44, 47, 52,
        56, 59, 68, 73, 78, 86, 89, 92, 94, 100,
    };
    return t[i];
}

inline int rswUsableByCleric(int i) {
    // the (C) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        1, 1, 0, 0, 1, 0, 1, 1, 1, 0,
        0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int rswUsableByMagicUser(int i) {
    // the (M) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        1, 1, 0, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 1, 1, 0,
        1, 1, 0, 0, 0, 0, 1, 1, 0, 0,
    };
    return t[i];
}

inline int rswUsableByFighter(int i) {
    // the (F) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int rswUsableByThief(int i) {
    // the (T) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int rswAnyClass(int i) {
    // the (any) mark; i clamps
    if (i < 0) i = 0;
    if (i > 29) i = 29;
    static const int t[30] = {
        0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
        0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
    };
    return t[i];
}

inline int rswFullChargesAssumed() {
    // the column-header asterisk: the
    // x.p. and g.p. values assume full
    // charges are in the item
    return 1;
}

}  // namespace rules

