// ====================================================================
// Adnd1 - rules/dmg/rodswands.h
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

// R-refactor: namespace rules -> class Rodswands (instance methods)
class Rodswands {
public:
    int rswRowCount();
    int rswRowLo(int i);
    int rswRowHi(int i);
    int rswUsableByCleric(int i);
    int rswUsableByMagicUser(int i);
    int rswUsableByFighter(int i);
    int rswUsableByThief(int i);
    int rswAnyClass(int i);
    int rswFullChargesAssumed();
};
