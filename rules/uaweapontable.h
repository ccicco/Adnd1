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
// OCR holes (the item stays open pending the PDF read): the
// atlatl, harpoon and falchion weights, the lasso damage
// cells, the stray 30 beside the aklys row, and the
// unattributable garbled quarrel row (Quarrel (or Bolt),
// hand - 13/12 matches no seam row; not pinned).
// ===========================================================================

#pragma once

namespace rules {

// The row count (67 = the 50 PHB rows
// plus 17 new-weapon rows).
inline int uawtRowCount()
    { return 67; }

// The PHB rows verified cell for cell
// against the R189 chart seam.
inline int uawtSeamVerifiedCount()
    { return 50; }

// The UA-new weapon rows (not in the
// PHB chart): the aklys, atlatl,
// blowgun, caltrop, garrot, harpoon,
// hook fauchard, knife, lasso, man
// catcher, sap, spiked buckler, staff
// sling (two rows), falchion, khopesh
// and whip.
inline int uawtNewWeaponCount()
    { return 17; }

// The row name (printed, or the
// attribution judgment).
inline const char* uawtName(int i) {
    static const const char* k[67] = {
        "Aklys", "Atlatl and javelin", "Arrow", "Axe, Battle",
        "Axe, Hand or Throwing", "Bardiche", "Bec de Corbin",
        "Bill-Guisarme", "Blowgun and needle", "Bo Stick",
        "Caltrop", "Club", "Dagger", "Dart", "Fauchard",
        "Fauchard-Fork", "Flail, Footman's", "Flail, Horseman's",
        "Military Fork", "Garrot", "Glaive", "Glaive-Guisarme",
        "Guisarme", "Guisarme-Voulge", "Halberd", "Harpoon",
        "Hammer, Lucern", "Hammer", "Hook Fauchard", "Javelin",
        "Jo Stick", "Knife", "Lance (light horse)",
        "Lance (medium horse)", "Lance (heavy horse)", "Lasso",
        "Mace, Footman's", "Mace, Horseman's", "Man Catcher",
        "Morning Star", "Partisan", "Pick, Footman's",
        "Pick, Horseman's", "Pike, Awl",
        "Quarrel (or Bolt), light", "Quarrel (or Bolt), heavy",
        "Ranseur", "Sap", "Scimitar", "Sling Bullet",
        "Sling Stone", "Spear", "Spetum", "Spiked Buckler",
        "Staff, Quarter", "Staff Sling Bullet",
        "Staff Sling Stone", "Sword, Bastard", "Sword, Broad",
        "Sword, Falchion", "Sword, Khopesh", "Long Sword",
        "Sword, Short", "Sword, Two-handed", "Trident", "Voulge",
        "Whip",
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}

// True when the row is a UA-new weapon.
inline bool uawtIsNewWeapon(int i) {
    static const bool k[67] = {
        1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1,
        0, 0, 1, 1, 0, 0, 0, 0, 0, 1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}

// The R189 chart row (rules/
// weapontables.h) each PHB row verifies
// against; -1 = a new weapon.
inline int uawtPhbSeamIndex(int i) {
    static const int k[67] = {
        -1, -1, 0, 1, 2, 3, 4, 5, -1, 6, -1, 7, 8, 9, 10, 11, 12,
        13, 14, -1, 15, 16, 17, 18, 19, -1, 20, 21, -1, 22, 23,
        -1, 24, 25, 26, -1, 27, 28, -1, 29, 30, 31, 32, 33, 34,
        35, 36, -1, 37, 38, 39, 40, 41, -1, 42, -1, -1, 43, 44,
        -1, -1, 45, 46, 47, 48, 49, -1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}

// The approximate weight in gold pieces;
// -1 = the weight cell is OCR-lost.
inline int uawtWeightMin(int i) {
    static const int k[67] = {
        35, -1, 2, 75, 50, 125, 100, 150, 15, 15, 2, 30, 10, 5,
        60, 80, 150, 35, 75, 1, 75, 100, 80, 150, 175, -1, 150,
        50, 80, 20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80,
        60, 40, 80, 1, 2, 50, 10, 40, 2, 1, 40, 50, 35, 50, 5, 4,
        100, 75, -1, 75, 60, 35, 250, 50, 125, 25,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}

// The weight maximum - equal to the
// minimum except the printed ranges
// (caltrop, spear, whip).
inline int uawtWeightMax(int i) {
    static const int k[67] = {
        35, -1, 2, 75, 50, 125, 100, 150, 15, 15, 4, 30, 10, 5,
        60, 80, 150, 35, 75, 1, 75, 100, 80, 150, 175, -1, 150,
        50, 80, 20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80,
        60, 40, 80, 1, 2, 50, 10, 40, 2, 1, 60, 50, 35, 50, 5, 4,
        100, 75, -1, 75, 60, 35, 250, 50, 125, 35,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}

// The damage vs. size S or M: the
// minimum; -1 = OCR-lost.
inline int uawtDamageSMMin(int i) {
    static const int k[67] = {
        1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1,
        1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 2, 3, -1, 2, 1,
        1, 2, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1,
        2, 2, 2, 2, 1, 1, 1, 2, 2, 1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}

// The damage vs. size S or M: the
// maximum.
inline int uawtDamageSMMax(int i) {
    static const int k[67] = {
        6, 6, 6, 8, 6, 8, 8, 8, 1, 6, 1, 6, 4, 3, 6, 8, 7, 5, 8,
        4, 6, 8, 8, 8, 10, 8, 8, 5, 4, 6, 6, 3, 6, 7, 9, -1, 7, 6,
        2, 8, 6, 7, 5, 6, 4, 5, 8, 2, 8, 5, 4, 6, 7, 4, 6, 8, 8,
        8, 8, 7, 8, 8, 6, 10, 7, 8, 2,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}

// The damage vs. size L: the minimum;
// -1 = OCR-lost.
inline int uawtDamageLMin(int i) {
    static const int k[67] = {
        1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2,
        1, 1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, -1, 1, 1,
        1, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 3, 2,
        2, 2, 2, 1, 1, 1, 3, 3, 2, 1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}

// The damage vs. size L: the maximum.
inline int uawtDamageLMax(int i) {
    static const int k[67] = {
        3, 6, 6, 8, 4, 12, 6, 10, 1, 3, 2, 3, 3, 2, 8, 10, 8, 5,
        8, 8, 10, 12, 8, 8, 12, 12, 6, 4, 4, 6, 4, 2, 8, 12, 18,
        -1, 6, 4, 2, 7, 7, 8, 4, 12, 4, 7, 8, 2, 8, 7, 4, 8, 12,
        3, 6, 9, 8, 16, 7, 8, 6, 12, 8, 18, 12, 8, 1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}

}   // namespace rules