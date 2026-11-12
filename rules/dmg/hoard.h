// ====================================================================
// Adnd1 - rules/dmg/hoard.h
// R220: the combined hoard table pins
// (DMG p.123) - the II.C COMBINED HOARD table, the
// R219 companion: the ten percentile bands and their
// monetary and magic trove references.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// dice and the actual hoard assembly; the
// band edges and the row references read
// here).
//
// Conventions and judgments, named in
// place:
//   - The bands: 01-20, 21-40, 41-55, 56-65,
//     66-75, 76-80, 81-85, 86-90, 91-96,
//     97-00 - ten bands.
//   - The row references are die results on
//     the R219 sub-tables, returned here as
//     the R219 band indices: monetary
//     1-2=b0, 3-5=b1, 6-10=b2, 11-12=b3,
//     13-15=b4, 16-17=b5, 20=b8; magic
//     1-5=m0, 6-8=m1, 9-12=m2, 13-14=m3,
//     15-18=m4, 19=m7, 20=m6. The die 18/19
//     monetary rows are re-roll instructions
//     and are never referenced by this
//     table.
//   - On-hand vs map: bands 0-5 hold both
//     monetary and magic on hand; bands 6-7
//     hold the 20 monetary row on hand with a
//     MAP to the magic; bands 8-9 MAP to the
//     monetary with magic held on hand.
//   - Design notes: these are the real finds;
//     a reference means the treasure of that
//     sub-table row; combined hoards should
//     be hidden, trapped and guarded, and
//     located in distant places.
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Hoard (instance methods)
class Hoard {
public:


// -----------------------------------------------------------------------
// The banding.
// -----------------------------------------------------------------------
    int bandCount();
    int bandOfRoll(int roll);


// -----------------------------------------------------------------------
// The on-hand monetary rows.
// -----------------------------------------------------------------------
    int monetaryRowCount(int band);
    int monetaryRow(int band, int i);


// -----------------------------------------------------------------------
// The on-hand magic rows.
// -----------------------------------------------------------------------
    int magicRowCount(int band);
    int magicRow(int band, int i);


// -----------------------------------------------------------------------
// The map-to-monetary references (bands 8-9).
// -----------------------------------------------------------------------
    int mapsToMonetary(int band);
    int mapMonetaryRowCount(int band);
    int mapMonetaryRow(int band, int i);


// -----------------------------------------------------------------------
// The map-to-magic references (bands 6-7).
// -----------------------------------------------------------------------
    int mapsToMagic(int band);
    int mapMagicRowCount(int band);
    int mapMagicRow(int band, int i);


// -----------------------------------------------------------------------
// The design notes.
// -----------------------------------------------------------------------
    int mustBeHiddenTrappedGuarded();
    int distantPlaces();
};
