// ===========================================================================
// Adnd1 - rules/ua/uaweapontable.h
// The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) pins
// (R337).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the roster: 67 rows in the printed order. The OCR merges
//     and garbles several rows; every row is attributed by data,
//     not guesswork: the 50 PHB weapons (the R189 chart,
//     rules/phb/weapontables.h) match cell for cell -
//     uawtPhbSeamIndex maps each row to its chart row. The
//     merged Jo Stick/Javelin, Long/Short Sword and Lance
//     (heavy)/Lasso rows split by seam.
//   - the hyphen-loss pattern: the OCR drops hyphens in many
//     damage cells (1-6 prints 16, 2-12 prints 212), dots or
//     colons in others (2.5 = 2-5, 2:8 = 2-8). The pattern is
//     proven against the R189 seam on every PHB row it touches
//     (the arrow 16, dagger 14, bo stick 13, halberd 212, the
//     heavy quarrel 2.5/2.7). The new-weapon cells decoded by
//     the same pattern pin as pattern-decoded.
//   - attributed rows: the Military Fork and Glaive-Guisarme
//     data rows print nameless (OCR-displaced); each matches
//     exactly one R189 row - attributed by unique seam match.
//     The pick rows print garbled names; the data assigns them.
//     The row between Ranseur and Scimitar (10, 1-2, 1-2)
//     attributes to the Sap - the roster's named new weapon
//     otherwise absent, in its alphabetical place.
//   - the Garrot row prints a stray 3 beside the weight column;
//     the weight 1 pins (the weight-column cell). The Lance
//     (heavy)/Lasso merged row prints 150 20 - the 150 is the
//     lance (seam), the 20 pins as the lasso weight.
//   - the horseman flail S/M cell prints empty in the UA
//     extract - it closes via the R189 seam (2-5, the PHB
//     print), the R333 seam-closure convention; the L cell
//     2.5 decodes by the dot pattern to the same value.
//   - flat damage cells pin as printed (the blowgun 1/1, the
//     caltrop 1, the whip L 1).
//
// R392 (the clean PDF read): every hole closes. The atlatl
// weight reads 30, the harpoon 50-60, the falchion 60-80,
// the lasso damage cells print the dash (0 damage, the
// print flagged uawtDamagePrintsDash), and the garbled
// quarrel row reads in full (Quarrel (or Bolt), hand - 1
// gp, 1-3, 1-2 - the 68th row, appended at the roster
// end, its printed position between the pike and the
// light quarrel). One misdecode reconciles: the garrot
// L damage reads 1-6, not the hyphen-loss 1-8. The p.
// 26 footnotes read in full (the six numbered notes -
// uawtNote1 through uawtNote6).
// ===========================================================================

#pragma once

// R1058 applied
#include "rules/seams/weaponsreg.h"

namespace rules {

// The row count (68 = the 50 PHB rows
// plus 18 new-weapon rows; the R392
// clean read adds the hand-crossbow
// quarrel row the garbled extract
// dropped).
inline int uawtRowCount()
    { return 68; }

// The PHB rows verified cell for cell
// against the R189 chart seam.
inline int uawtSeamVerifiedCount()
    { return 50; }

// The UA-new weapon rows (not in the
// PHB chart): the aklys, atlatl,
// blowgun, caltrop, garrot, harpoon,
// hook fauchard, knife, lasso, man
// catcher, sap, spiked buckler, staff
// sling (two rows), falchion, khopesh,
// whip and the hand-crossbow quarrels
// (the R392 clean read).
inline int uawtNewWeaponCount()
    { return 18; }

// The row name (printed, or the
// attribution judgment).
inline const char* uawtName(int i) {
    const auto& rows = wRows("wt");
    if (rows.empty())
        return "";
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if ((int)rows.size() <= (i))
        return "";
    return rows[i].name.c_str();
}

// True when the row is a UA-new weapon.
inline bool uawtIsNewWeapon(int i) {
    const auto* g = wTable(
        "wt", "is_new");
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if (!g) return 1;
    return (int)(*g)[i];
}

// The R189 chart row (rules/
// weapontables.h) each PHB row verifies
// against; -1 = a new weapon.
inline int uawtPhbSeamIndex(int i) {
    const auto* g = wTable(
        "wt", "phb_seam");
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if (!g) return -1;
    return (int)(*g)[i];
}

// The approximate weight in gold pieces;
// -1 = the weight cell is OCR-lost.
inline int uawtWeightMin(int i) {
    const auto* g = wTable(
        "wt", "weight_min");
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if (!g) return 35;
    return (int)(*g)[i];
}

// The weight maximum - equal to the
// minimum except the printed ranges
// (caltrop, spear, whip).
inline int uawtWeightMax(int i) {
    const auto* g = wTable(
        "wt", "weight_max");
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if (!g) return 35;
    return (int)(*g)[i];
}

// The damage vs. size S or M: the
// minimum; -1 = OCR-lost.
inline int uawtDamageSMMin(int i) {
    const auto* g = wTable(
        "wt", "sm_min");
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if (!g) return 1;
    return (int)(*g)[i];
}

// The damage vs. size S or M: the
// maximum.
inline int uawtDamageSMMax(int i) {
    const auto* g = wTable(
        "wt", "sm_max");
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if (!g) return 6;
    return (int)(*g)[i];
}

// The damage vs. size L: the minimum;
// -1 = OCR-lost.
inline int uawtDamageLMin(int i) {
    const auto* g = wTable(
        "wt", "l_min");
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if (!g) return 1;
    return (int)(*g)[i];
}

// The damage vs. size L: the maximum.
inline int uawtDamageLMax(int i) {
    const auto* g = wTable(
        "wt", "l_max");
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    if (!g) return 3;
    return (int)(*g)[i];
}

// True when the row's damage cells print the dash (the
// lasso - the dash reads 0 damage).
inline bool uawtDamagePrintsDash(int i)
    { return i == 35; }

// ---- the printed notes (the p. 26 facing page) ----
// Note 1: these weapons do twice the indicated damage
// against creatures of any size when employed by an
// attacker riding a charging mount (the lance rows).
inline bool uawtNote1ChargingMountDouble()
    { return true; }

// Note 2: this weapon does twice the damage indicated
// to any opponent when the weapon is set to receive
// their charge.
inline bool uawtNote2SetDoubleVsCharge()
    { return true; }

// Note 3: this weapon class includes all pointed
// cutting and thrusting weapons with blade length
// between 15 and 24 inches.
inline int uawtNote3BladeClassLowInches()
    { return 15; }

inline int uawtNote3BladeClassHighInches()
    { return 24; }

// Note 4: these weapons are capable of disarming an
// opponent on a score required to hit AC 8.
inline int uawtNote4DisarmOnAcEightHit()
    { return 8; }

// Note 5: treat this weapon as a long sword if it is
// used one-handed.
inline bool uawtNote5BastardAsLongSword()
    { return true; }

// Note 6: minor variations of these weapons, with
// different names, may exist in the campaign. See
// Players Handbook for particulars.
inline bool uawtNote6VariantsSeePhb()
    { return true; }

}   // namespace rules