// ====================================================================
// Adnd1 - rules/dmg/armorshield.h
// R241: the III.F armor and shield pins
// (DMG p.129-130) - the magic armor and
// shield table (the RIGHT column of the
// two-column print):
//   - 26 rows, Chain Mail +1 01-05
//     through Shield -1 missile attractor
//     98-00 (the 00 band pins as 100).
//   - the x.p. point values and the g.p.
//     sale values of every row.
//   - the TWO cursed no-x.p. rows: Plate
//     Mail of Vulnerability 40-44 and
//     Shield -1 missile attractor 98-00
//     print --- for x.p. (the R240
//     no-x.p. convention, here on two
//     rows only).
//   - the armor SIZE footnote: 65% of
//     all armor is man-sized, 20%
//     elf-sized, 10% dwarf-sized, 5%
//     gnome or halfling sized (sum 100).
// NO class marks, asterisks or
// dual-value rows ride this table.
// The row identity is the 26 die bands of
// the engine III.F table (dm/treasure.cpp
// kArmor order). The row NAMES were
// pinned by the R122 line-diff audit;
// this header pins the values, band
// edges and the size footnote.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Armorshield (instance methods)
class Armorshield {
public:
    int asRowCount();
    int asRowLo(int i);
    int asRowHi(int i);
    int asXpValue(int i);
    int asSaleGp(int i);
    int asNoXpCount();
    int asManSizedPct();
    int asElfSizedPct();
    int asDwarfSizedPct();
    int asSmallUserPct();
};
