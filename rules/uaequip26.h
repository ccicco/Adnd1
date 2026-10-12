/ ===========================================================================
// ===========================================================================
// Adnd1 - rules/uaequip26.h
// The UA BASIC EQUIPMENT AND SUPPLIES COSTS table (p. 26) pins
// (R392).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the armor roster: four rows in the printed order; the
//     print runs two columns (Bronze Plate 100 gp beside Full
//     Plate 4000 gp), the pairs split in printed order.
//   - the arms roster: 19 rows; "Quarrels for same" pins as
//     printed (the hand-crossbow quarrels); the falchion entry
//     prints across two lines (Sword, falchion, and scabbard) -
//     the split row merges.
//   - the units pin as printed (gp, sp, ep) - uaecArmsUnit
//     names the row unit, the IsSilver/IsElectrum flags carry
//     the same reading.
//
// No holes: the R392 clean PDF read - every cell legible.
// ===========================================================================

#pragma once

namespace rules {

// The armor row count (4).
inline int uaecArmorCount()
    { return 4; }

// The armor row name (printed).
inline const char* uaecArmorName(int i) {
    static const char* const k[4] = {
        "Bronze Plate",
        "Full Plate",
        "Field Plate",
        "Shield, buckler",
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

// The armor cost (printed).
inline int uaecArmorCost(int i) {
    static const int k[4] = {
        100, 4000, 2000, 5,
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

// The armor cost unit (gp, printed).
inline const char* uaecArmorUnit(int i)
    { (void)i; return "gp"; }

// The arms row count (19 = the 16 new weapons plus the
// quarrels, the scabbard knife and the two swords).
inline int uaecArmsCount()
    { return 19; }

// The arms row name (printed; the falchion two-line entry
// merges).
inline const char* uaecArmsName(int i) {
    static const char* const k[19] = {
        "Aklys", "Atlatl", "Blowgun", "Blowgun Needle", "Caltrop",
        "Crossbow, hand", "Quarrels for same", "Garrot", "Harpoon",
        "Hook Fauchard", "Knife & scabbard", "Lasso", "Man Catcher",
        "Sap", "Spiked Buckler", "Staff Sling",
        "Sword, falchion, and scabbard", "Sword, khopesh", "Whip",
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

// The arms cost (printed number).
inline int uaecArmsCost(int i) {
    static const int k[19] = {
        2, 1, 20, 1, 2, 300, 100, 1, 5, 6, 1, 5,
        25, 1, 10, 2, 10, 10, 3,
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

// The arms cost unit ("gp", "sp" or "ep", printed).
inline const char* uaecArmsUnit(int i) {
    static const char* const k[19] = {
        "gp", "gp", "gp", "sp", "sp", "gp", "gp",
        "ep", "gp", "gp", "gp", "sp", "gp", "gp",
        "gp", "gp", "gp", "gp", "gp",
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

// True when the row price prints in silver pieces (the
// blowgun needle, the caltrop, the lasso).
inline bool uaecArmsPriceIsSilver(int i) {
    static const bool k[19] = {
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

// True when the row price prints in electrum pieces (the
// garrot).
inline bool uaecArmsPriceIsElectrum(int i) {
    static const bool k[19] = {
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

}   // namespace rules