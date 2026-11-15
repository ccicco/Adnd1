// ===========================================================================
// Adnd1 - rules/ua/uamissile.h
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
// R392 (the clean PDF read): every hole closes. The rate
// column and the S/M/L ranges read in full (the strings pin
// as printed: "1/2" for the half-rate rows, "1*" for the
// aklys, the dash for the staff slings' short range, the
// "1 1/2" and "4 1/2" dart cells, the "3-6" staff-sling
// medium). Every 100 sentinel fills (the light crossbow
// AC6 reads +1, the PHB-seam value the R338 pin could not
// confirm); the AC 7..10 columns pin - the R392
// uamtAcAdjustmentHigh accessor. The aklys range footnote
// reads: 10-foot only, not 10 yards. The composite long
// bow's 21 stays the printed value (the PHB reads 24 - the
// deviation noted, pinned as printed).
// ===========================================================================

#pragma once

// R1058 applied
#include "rules/seams/weaponsreg.h"

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
    const auto& rows = wRows("uamt");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// True when the row is a UA-new weapon (the
// aklys, atlatl, blowgun, harpoon, knife,
// lasso and the two staff sling rows).
inline bool uamtIsNewWeapon(int i) {
    const auto* g = wTable(
        "uamt", "is_new");
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if (!g) return 1;
    return (int)(*g)[i];
}

// The printed range number - the long range in
// tens of feet (the JUDGMENT above); -1 = the
// cell is OCR-lost (the aklys, the dart).
inline int uamtRangePrinted(int i) {
    const auto* g = wTable(
        "uamt", "range_printed");
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if (!g) return -1;
    return (int)(*g)[i];
}

// The AC adjustment by AC 0..6, applied at
// short range (the R392 clean read: every
// cell recovers; no sentinel remains).
inline int uamtAcAdjustment(int i, int ac) {
    const auto* g = wTable(
        "uamt", "ac_adjustment");
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if (ac < 0) ac = 0;
    if (ac > 6) ac = 6;
    if (!g) return -8;
    return (int)(*g)[(i) * 7
        + (ac)];
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

// The AC adjustment by AC 7..10 (the R392 clean read; the
// short-range ladders extend past AC 6).
inline int uamtAcAdjustmentHigh(int i, int ac) {
    const auto* g = wTable(
        "uamt", "ac_adjustment_high");
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if (ac < 0) ac = 0;
    if (ac > 3) ac = 3;
    if (!g) return -1;
    return (int)(*g)[(i) * 4
        + (ac)];
}

// The rate of fire (printed; "1/2" = the half-rate rows:
// the heavy crossbow, the lasso, the two staff slings).
inline const char* uamtRateOfFire(int i) {
    const auto& rows = wRows("uamt_rof");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The short range (printed; "-" = the dash, "1*" = the
// aklys footnote, "1 1/2" = the dart).
inline const char* uamtRangeShort(int i) {
    const auto& rows = wRows("uamt_range_s");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The medium range (printed; "3-6" = the staff slings).
inline const char* uamtRangeMedium(int i) {
    const auto& rows = wRows("uamt_range_m");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The long range (printed).
inline const char* uamtRangeLong(int i) {
    const auto& rows = wRows("uamt_range_l");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// The aklys range footnote: the "1*" reads 10-foot only,
// not 10 yards (the R392 clean read).
inline bool uamtAklysTenFootOnly()
    { return true; }

}   // namespace rules