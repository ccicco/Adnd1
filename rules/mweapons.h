// ====================================================================
// Adnd1 - rules/mweapons.h
// R243: the III.H misc weapons pins
// (DMG p.131-132) - the miscellaneous
// weapons table, the LAST of the III.A-H
// magic item tables:
//   - 36 rows, Arrow +1 01-08 through
//     Trident (Military Fork) +3 00 (the
//     00 band pins as 100).
//   - the x.p. point values and the g.p.
//     sale values of every row.
//   - the FOUR ammo quantity ranges,
//     printed as the ", N-M in number"
//     suffixes: Arrow +1 2-24, Arrow +2
//     2-16, Arrow +3 2-12, Bolt +2 2-20
//     (a 0/0 cell means a single item).
//   - the TWO duplicate Hammer +2 rows:
//     57-60 prints 300 x.p./2,500 g.p. and
//     61-62 prints 650 x.p./6,000 g.p. -
//     both printed verbatim in the book
//     (Curtiss-verified against p.125).
//   - the cursed Spear, Cursed Backbiter
//     98-99 prints --- x.p. (pinned as 0).
// NO class marks or asterisks ride this
// table.
// The row identity is the 36 die bands of
// the engine III.H table (dm/treasure.cpp
// kWeapons order). The row NAMES were
// pinned by the R122 line-diff audit; this
// header pins the values, band edges and
// the quantity ranges.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mwRowCount() {
    // Arrow +1 through the Trident (Military Fork)
    return 36;
}

inline int mwRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        1, 9, 13, 15, 16, 21, 23, 24, 25, 28, 33, 36,
        37, 38, 39, 47, 51, 52, 57, 61, 63, 64, 65, 68,
        73, 76, 77, 78, 81, 84, 89, 90, 95, 97, 98, 100,
    };
    return t[i];
}

inline int mwRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        8, 12, 14, 15, 20, 22, 23, 24, 27, 32, 35, 36,
        37, 38, 46, 50, 51, 56, 60, 62, 63, 64, 67, 72,
        75, 76, 77, 80, 83, 88, 89, 94, 96, 97, 99, 100,
    };
    return t[i];
}

inline int mwXpValue(int i) {
    // the x.p. point values; the Backbiter is 0; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        20, 50, 75, 250, 300, 600, 750, 1000, 400, 50, 500, 2000,
        1500, 1500, 100, 250, 350, 450, 300, 650, 1500, 2500, 750, 350,
        700, 1750, 1500, 350, 400, 750, 700, 500, 1000, 1750, 0, 1500,
    };
    return t[i];
}

inline int mwSaleGp(int i) {
    // the g.p. sale values; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        120, 300, 450, 2500, 1750, 3750, 4500, 7000, 2500, 300, 3500, 12000,
        7500, 7500, 750, 2000, 3000, 4000, 2500, 6000, 15000, 25000, 5000, 3000,
        4500, 17500, 15000, 2500, 3000, 6000, 7000, 3000, 6500, 15000, 1000, 12500,
    };
    return t[i];
}

inline int mwQtyLo(int i) {
    // the ammo quantity lower bounds; 0 = a single item; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int mwQtyHi(int i) {
    // the ammo quantity upper bounds; 0 = a single item; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        24, 16, 12, 0, 0, 0, 0, 0, 0, 20, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int mwQtyRangeCount() {
    // the three Arrows and the Bolt
    return 4;
}

inline int mwNoXpCount() {
    // the cursed Backbiter prints --- x.p.
    return 1;
}

inline int mwDuplicateNameCount() {
    // the two Hammer +2 rows (Curtiss-verified p.125)
    return 2;
}

}  // namespace rules
