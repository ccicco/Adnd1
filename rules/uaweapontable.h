// ===========================================================================
// Adnd1 - rules/uaweapontable.h
// The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) pins
// (R337).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the roster: 67 rows in the printed order. The OCR merges
//     and garbles several rows; every row is attributed by data,
//     not guesswork: the 50 PHB weapons (the R189 chart,
//     rules/weapontables.h) match cell for cell -
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
    static const char* const k[68] = {
        "Aklys", "Atlatl and javelin", "Arrow", "Axe, Battle",
        "Axe, Hand or Throwing", "Bardiche", "Bec de Corbin",
        "Bill-Guisarme", "Blowgun and needle", "Bo Stick", "Caltrop",
        "Club", "Dagger", "Dart", "Fauchard", "Fauchard-Fork",
        "Flail, Footman's", "Flail, Horseman's", "Military Fork",
        "Garrot", "Glaive", "Glaive-Guisarme", "Guisarme",
        "Guisarme-Voulge", "Halberd", "Harpoon", "Hammer, Lucern",
        "Hammer", "Hook Fauchard", "Javelin", "Jo Stick", "Knife",
        "Lance (light horse)", "Lance (medium horse)",
        "Lance (heavy horse)", "Lasso", "Mace, Footman's",
        "Mace, Horseman's", "Man Catcher", "Morning Star", "Partisan",
        "Pick, Footman's", "Pick, Horseman's", "Pike, Awl",
        "Quarrel (or Bolt), light", "Quarrel (or Bolt), heavy",
        "Ranseur", "Sap", "Scimitar", "Sling Bullet", "Sling Stone",
        "Spear", "Spetum", "Spiked Buckler", "Staff, Quarter",
        "Staff Sling Bullet", "Staff Sling Stone", "Sword, Bastard",
        "Sword, Broad", "Sword, Falchion", "Sword, Khopesh",
        "Long Sword", "Sword, Short", "Sword, Two-handed", "Trident",
        "Voulge", "Whip", "Quarrel (or Bolt), hand",
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}

// True when the row is a UA-new weapon.
inline bool uawtIsNewWeapon(int i) {
    static const bool k[68] = {
        1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}

// The R189 chart row (rules/
// weapontables.h) each PHB row verifies
// against; -1 = a new weapon.
inline int uawtPhbSeamIndex(int i) {
    static const int k[68] = {
        -1, -1, 0, 1, 2, 3, 4, 5, -1, 6, -1, 7, 8, 9, 10, 11, 12,
        13, 14, -1, 15, 16, 17, 18, 19, -1, 20, 21, -1, 22, 23, -1,
        24, 25, 26, -1, 27, 28, -1, 29, 30, 31, 32, 33, 34, 35, 36,
        -1, 37, 38, 39, 40, 41, -1, 42, -1, -1, 43, 44, -1, -1, 45,
        46, 47, 48, 49, -1, -1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}

// The approximate weight in gold pieces;
// -1 = the weight cell is OCR-lost.
inline int uawtWeightMin(int i) {
    static const int k[68] = {
        35, 30, 2, 75, 50, 125, 100, 150, 15, 15, 2, 30, 10, 5, 60,
        80, 150, 35, 75, 1, 75, 100, 80, 150, 175, 50, 150, 50, 80,
        20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80, 60, 40,
        80, 1, 2, 50, 10, 40, 2, 1, 40, 50, 35, 50, 5, 4, 100, 75,
        60, 75, 60, 35, 250, 50, 125, 25, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}

// The weight maximum - equal to the
// minimum except the printed ranges
// (caltrop, spear, whip).
inline int uawtWeightMax(int i) {
    static const int k[68] = {
        35, 30, 2, 75, 50, 125, 100, 150, 15, 15, 4, 30, 10, 5, 60,
        80, 150, 35, 75, 1, 75, 100, 80, 150, 175, 60, 150, 50, 80,
        20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80, 60, 40,
        80, 1, 2, 50, 10, 40, 2, 1, 60, 50, 35, 50, 5, 4, 100, 75,
        80, 75, 60, 35, 250, 50, 125, 35, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}

// The damage vs. size S or M: the
// minimum; -1 = OCR-lost.
inline int uawtDamageSMMin(int i) {
    static const int k[68] = {
        1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1,
        1, 2, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 2, 3, 0, 2, 1, 1, 2,
        1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 2, 2, 2,
        2, 1, 1, 1, 2, 2, 1, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}

// The damage vs. size S or M: the
// maximum.
inline int uawtDamageSMMax(int i) {
    static const int k[68] = {
        6, 6, 6, 8, 6, 8, 8, 8, 1, 6, 1, 6, 4, 3, 6, 8, 7, 5, 8, 4,
        6, 8, 8, 8, 10, 8, 8, 5, 4, 6, 6, 3, 6, 7, 9, 0, 7, 6, 2,
        8, 6, 7, 5, 6, 4, 5, 8, 2, 8, 5, 4, 6, 7, 4, 6, 8, 8, 8, 8,
        7, 8, 8, 6, 10, 7, 8, 2, 3,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}

// The damage vs. size L: the minimum;
// -1 = OCR-lost.
inline int uawtDamageLMin(int i) {
    static const int k[68] = {
        1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1,
        1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, 0, 1, 1, 1, 2,
        2, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 3, 2, 2, 2, 2,
        1, 1, 1, 3, 3, 2, 1, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}

// The damage vs. size L: the maximum.
inline int uawtDamageLMax(int i) {
    static const int k[68] = {
        3, 6, 6, 8, 4, 12, 6, 10, 1, 3, 2, 3, 3, 2, 8, 10, 8, 5, 8,
        6, 10, 12, 8, 8, 12, 12, 6, 4, 4, 6, 4, 2, 8, 12, 18, 0, 6,
        4, 2, 7, 7, 8, 4, 12, 4, 7, 8, 2, 8, 7, 4, 8, 12, 3, 6, 9,
        8, 16, 7, 8, 6, 12, 8, 18, 12, 8, 1, 2,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
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