// ====================================================================
// Adnd1 - rules/dmg/mweapons.h
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

// R-refactor: namespace rules -> class Mweapons (instance methods)
class Mweapons {
public:
    int mwRowCount();
    int mwRowLo(int i);
    int mwRowHi(int i);
    int mwXpValue(int i);
    int mwSaleGp(int i);
    int mwQtyLo(int i);
    int mwQtyHi(int i);
    int mwQtyRangeCount();
    int mwNoXpCount();
    int mwDuplicateNameCount();
};
