// ===========================================================================
// Adnd1 - rules/uamissile.h
// The UA HURLED WEAPON AND MISSILE TYPES, GENERAL DATA, AND
// "TO HIT" ADJUSTMENTS table (p. 28) pins (R338).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the range column: the extract prints one number per row
//     (two leading cells OCR-lost). The number reads as the
//     LONG range in tens of feet - PHB-seam-verified: the short
//     bow 15 (150'), the long bow 21 (210'), the light crossbow
//     18 (180'), the sling stone 16 (160'), the javelin 6 (60'),
//     the hand crossbow 6 (60'), the dagger and hand axe 3 (30').
//     The composite long bow prints 21 - the long bow's value;
//     the PHB composite prints 24 - pinned as printed, the
//     doubt noted pending the PDF.
//   - the minus-loss decode: unsigned magnitude tokens between
//     signed neighbors of a monotone ladder read as negative
//     (the aklys -8,7,-6... reads -8,-7,-6...). The pattern is
//     seam-proven on the R145 engine rows: the bow short prints
//     <7,6,5,-4,-1,0,0 and the PHB row reads -7,-6,-5,-4,-1,0,0;
//     the bow long prints 2,-1,-1,0 (PHB -2,-1,-1,0); the light
//     crossbow -3,2,-2,-1,0,0 (PHB -3,-2,-2,-1,0,0); the sling
//     bullet -3,-3,2 (PHB -3,-3,-2).
//   - attributions: the garbled "Bow," row attributes to the
//     long bow (range 21, the AC cells match the PHB row); the
//     composite rows differ from it, so the match is unique.
//     The lasso's "#7" reads as +7 - the only sign consistent
//     with the printed descending +9,+8 ladder. The dart's
//     "=7" and trailing '"1' read as -7 and -1 (the row's
//     ladder matches the dagger's exactly). The bow short's
//     "<7" seam-closes to -7. The staff sling rows read their
//     merged leading cells as the rate garbage and the range 9
//     (both rows print 9).
//   - the AC columns are AC 0 through 6, the adjustment applied
//     at SHORT range (the printed note); medium range adjusts
//     -2, long -5 - the R116 convention, seam-cross-checked.
//   - the dagger and dart rows read -7 through -1 - the UA
//     hurled rows, NOT the PHB p.38 melee rows (the R145
//     dagger row is the melee chart; the hurled chart carries
//     its own row).
//
// OCR holes (the item stays open pending the PDF read): the
// ENTIRE rate-of-fire column (every row prints empty or
// garbage - "ODN", "||"), the two leading range cells of every
// row (the S/M ranges), the aklys and dart range cells, and
// the tail AC cells of the short rows (the hole sentinel is
// 100): the club AC2, the hammer AC0/AC5, the atlatl AC5/AC6
// (the merged "0 4"), the hand crossbow AC6 (the "0 i Wf"),
// the heavy crossbow AC1 (the printed dash), the light
// crossbow AC6 (the PHB row reads +1 - noted, not pinned),
// the sling stone AC0 (the "=r") and the bow long AC4-AC6.
// ===========================================================================

#pragma once

namespace rules {

// The row count (24 = the 16 standard weapons plus 8 new).
inline int uamtRowCount()
    { return 24; }

inline int uamtNewWeaponCount()
    { return 8; }

inline int uamtStandardWeaponCount()
    { return 16; }

// The row name (printed, or the attribution judgment -
// the "AKlys" caps slip normalized, the garbled "Bow,"
// row attributed to the long bow).
inline const char* uamtName(int i) {
    static const char* const k[24] = {
        "Aklys (hurled)", "Atlatl (javelin)", "Axe, Hand",
        "Blowgun Needle", "Bow, Composite, Long",
        "Bow, Composite, Short", "Bow, Long", "Bow, Short",
        "Club", "Crossbow, Hand", "Crossbow, Heavy",
        "Crossbow, Light", "Dagger", "Dart", "Hammer", "Harpoon",
        "Javelin", "Knife", "Lasso", "Sling (bullet)",
        "Sling (stone)", "Spear", "Staff Sling (bullet)",
        "Staff Sling (stone)",
    };
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    return k[i];
}

// True when the row is a UA-new weapon (the
// aklys, atlatl, blowgun, harpoon, knife,
// lasso and the two staff sling rows).
inline bool uamtIsNewWeapon(int i) {
    static const bool k[24] = {
        1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1,
        0, 0, 0, 1, 1,
    };
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    return k[i];
}

// The printed range number - the long range in
// tens of feet (the JUDGMENT above); -1 = the
// cell is OCR-lost (the aklys, the dart).
inline int uamtRangePrinted(int i) {
    static const int k[24] = {
        -1, 9, 3, 3, 21, 18, 21, 15, 3, 6, 24, 18, 3, -1, 3, 3, 6,
        3, 3, 20, 16, 3, 9, 9,
    };
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    return k[i];
}

// The AC adjustment by AC 0..6, applied at
// short range; 100 = the cell is OCR-lost.
inline int uamtAcAdjustment(int i, int ac) {
    static const int k[24][7] = {
        { -8, -7, -6, -5, -4, -3, -2 },
        { -6, -5, -4, -3, -2, 100, 100 },
        { -6, -5, -4, -3, -2, -1, -1 },
        { -14, -12, -10, -8, -6, -4, -2 },
        { -4, -3, -2, -1, 0, 0, 1 },
        { -4, -4, -3, -3, -1, 0, 1 },
        { -2, -1, -1, 0, 100, 100, 100 },
        { -7, -6, -5, -4, -1, 0, 0 },
        { -9, -8, 100, -5, -3, -2, -1 },
        { -6, -4, -2, -1, 0, 0, 100 },
        { -2, 100, -1, 0, 1, 2, 3 },
        { -3, -2, -2, -1, 0, 0, 100 },
        { -7, -6, -5, -4, -3, -2, -1 },
        { -7, -6, -5, -4, -3, -2, -1 },
        { 100, -3, -2, -1, 0, 100, 0 },
        { -6, -5, -4, 100, 100, 100, 100 },
        { -7, -6, -5, 100, 100, 100, 100 },
        { -8, -7, -6, 100, 100, 100, 100 },
        { 9, 8, 7, 100, 100, 100, 100 },
        { -3, -3, -2, 100, 100, 100, 100 },
        { 100, -6, -5, 100, 100, 100, 100 },
        { -4, -4, -3, 100, 100, 100, 100 },
        { -5, -4, -3, 100, 100, 100, 100 },
        { -6, -5, -4, 100, 100, 100, 100 },
    };
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if (ac < 0) ac = 0;
    if (ac > 6) ac = 6;
    return k[i][ac];
}

// ---- the printed notes (p. 28) ----
// Rate of fire is based on the turn (for table-top
// miniatures) or the melee round. The AC adjustment
// applies at short range; the range labels are S =
// Short, M = Medium, L = Long.
inline bool uamtRateOfFireTurnOrRound()
    { return true; }

inline bool uamtAcAdjustmentAtShortRange()
    { return true; }

// The medium-range adjustment: -2 (the R116 seam).
inline int uamtMediumRangeAdjustment()
    { return -2; }

// The long-range adjustment: -5 (the R116 seam).
inline int uamtLongRangeAdjustment()
    { return -5; }

}   // namespace rules