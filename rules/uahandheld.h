// ===========================================================================
// Adnd1 - rules/uahandheld.h
// The UA HAND HELD WEAPON TYPES, GENERAL DATA, AND "TO HIT"
// ADJUSTMENTS table (p. 27) pins (R392).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the roster: 60 rows in the printed order - the R392 clean
//     PDF read, every cell legible, no holes, no attributions.
//   - the n/a cells (the atlatl, blowgun and caltrop rows) pin
//     -1 in the numeric columns, "n/a" in the string columns.
//   - the half-foot glyphs (c. 1 1/2' and the like) normalize to
//     ASCII; the foot and inch marks print straight.
//   - the aklys speed factor prints "4 (+ 1)" - the 4 pins, the
//     +1 bonus rides uahhAklysSpeedBonus.
//   - the Spear and Trident speed factors print the range 6-8,
//     the Whip 5-8 - the min/max accessors carry the ranges.
//   - the footnotes: * = the set-double note (the spetum, the
//     bastard sword), ** = the dismount note (eight rows) -
//     uahhSetDoubleFlag/uahhDismountFlag; the general note: +2
//     vs the back, +4 vs stunned, prone and motionless.
// ===========================================================================

#pragma once

namespace rules {

// The row count (60).
inline int uahhRowCount()
    { return 60; }

// The row name (printed).
inline const char* uahhName(int i) {
    static const char* const k[60] = {
        "Aklys", "Atlatl", "Axe, Battle", "Axe, Hand", "Bardiche",
        "Bec de Corbin", "Bill-Guisarme", "Blowgun", "Bo Stick",
        "Caltrop", "Club", "Dagger", "Fauchard", "Fauchard-Fork",
        "Fist or Open Hand", "Flail, Footman's", "Flail, Horseman's",
        "Fork, Military", "Garrot", "Glaive", "Glaive-Guisarme",
        "Guisarme", "Guisarme-Voulge", "Halberd", "Harpoon",
        "Hammer, Lucern", "Hammer", "Hook Fauchard", "Jo Stick",
        "Knife", "Lance (light horse)", "Lance (medium horse)",
        "Lance (heavy horse)", "Lasso", "Mace, Footman's",
        "Mace, Horseman's", "Man Catcher", "Morning Star", "Partisan",
        "Pick, Military, Footman's", "Pick, Military, Horseman's",
        "Pike, Awl", "Ranseur", "Sap", "Scimitar", "Spear", "Spetum",
        "Spiked Buckler", "Staff, Quarter", "Staff Sling",
        "Sword, Bastard", "Sword, Broad", "Sword, Falchion",
        "Sword, Khopesh", "Sword, Long", "Sword, Short",
        "Sword, Two-handed", "Trident", "Voulge", "Whip",
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The length (printed; "n/a" = the not-applicable rows).
inline const char* uahhLength(int i) {
    static const char* const k[60] = {
        "c. 2'", "c. 3'", "c. 4'", "c. 1 1/2'", "c. 5'", "c. 6'",
        "8' +", "4'-7'", "c. 5'", "n/a", "c. 3'", "c. 15"", "8' +",
        "8'", "2' +", "c. 4'", "c. 2'", "7' +", "c. 3'", "8' +",
        "8' +", "6' +", "7' +", "5' +", "6'-8'", "5' +", "c. 1 1/2'",
        "8' +", "c. 3'", "c. 1'", "10'", "12'", "c. 14'", "(10'-20')",
        "c. 2 1/2'", "c. 1 1/2'", "8' +", "c. 4'", "7' +", "c. 4'",
        "c. 2'", "18'", "8' +", "1/2'", "c. 3'", "5'-13' +", "8' +",
        "1'", "6'-8'", "5'", "c. 4 1/2'", "c. 3 1/2'", "c. 3 1/2'",
        "c. 3 1/2'", "c. 3 1/2'", "c. 2'", "c. 6'", "4'-8' +", "8' +",
        "8'-20'",
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The space required (printed; "n/a" = the caltrop).
inline const char* uahhSpaceRequired(int i) {
    static const char* const k[60] = {
        "2'", "1'", "4'", "1'", "5'", "6'", "2'", "1'", "3'", "n/a",
        "1'-3'", "1'", "2'", "2'", "n/a", "6'", "4'", "1'", "1 1/2'",
        "1'", "1'", "2'", "2'", "5'", "1 1/2'", "5'", "2'", "2 1/2'",
        "2'", "1'", "1'", "1'", "1'", "8' +", "4'", "2'", "2 1/2'",
        "5'", "3'", "4'", "2'", "1'", "1'", "1'", "2'", "1'", "1'",
        "2'", "3'", "6'", "4' +", "4'", "3 1/2'", "4'", "3'", "1'",
        "6'", "1'", "2'", "8'-20'",
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The speed factor minimum; -1 = the n/a rows (the atlatl,
// the blowgun, the caltrop).
inline int uahhSpeedFactorMin(int i) {
    static const int k[60] = {
        4, -1, 7, 4, 9, 9, 10, -1, 3, -1, 4, 2, 8, 8, 1, 7, 6, 7, 2,
        8, 9, 8, 10, 9, 6, 9, 4, 9, 2, 2, 7, 6, 8, 10, 7, 6, 7, 7, 9,
        7, 5, 13, 8, 2, 4, 6, 8, 4, 4, 11, 6, 5, 5, 9, 5, 3, 10, 6,
        10, 5,
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The speed factor maximum (the Spear and Trident print the
// range 6-8, the Whip 5-8).
inline int uahhSpeedFactorMax(int i) {
    static const int k[60] = {
        4, -1, 7, 4, 9, 9, 10, -1, 3, -1, 4, 2, 8, 8, 1, 7, 6, 7, 2,
        8, 9, 8, 10, 9, 6, 9, 4, 9, 2, 2, 7, 6, 8, 10, 7, 6, 7, 7, 9,
        7, 5, 13, 8, 2, 4, 8, 8, 4, 4, 11, 6, 5, 5, 9, 5, 3, 10, 8,
        10, 8,
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The aklys speed-factor bonus (the print "4 (+ 1)").
inline int uahhAklysSpeedBonus()
    { return 1; }

// The AC adjustment by AC 0..10 (the full printed ladder).
inline int uahhAcAdjustment(int i, int ac) {
    static const int k[60][11] = {
        { -7, -6, -5, -4, -3, -2, -1, -1, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { -5, -4, -3, -2, -1, -1, 0, 0, 1, 1, 2 },
        { -5, -4, -3, -2, -2, -1, 0, 0, 1, 1, 1 },
        { -3, -2, -2, -1, 0, 0, 1, 1, 2, 2, 3 },
        { 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, -1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { -13, -11, -9, -7, -5, -3, -1, 0, 1, 0, 3 },
        { -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2 },
        { -7, -6, -5, -4, -3, -2, -1, -1, 0, 0, 1 },
        { -4, -4, -3, -3, -2, -2, 0, 0, 1, 1, 3 },
        { -3, -3, -2, -2, -1, -1, 0, 0, 0, -1, -1 },
        { -2, -2, -1, -1, -1, 0, 0, 0, 1, 0, 1 },
        { -9, -8, -7, -5, -3, -1, 0, 0, 2, 0, 4 },
        { 3, 3, 2, 2, 1, 2, 1, 1, 1, 1, -1 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
        { -3, -3, -2, -2, -1, 0, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0 },
        { -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0 },
        { -3, -3, -2, -2, -1, -1, 0, 0, 0, -1, -1 },
        { -2, -2, -1, -1, 0, 1, 1, 1, 0, 0, 0 },
        { 0, 1, 1, 1, 1, 2, 2, 2, 1, 1, 0 },
        { -3, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 2, 2, 2, 1, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
        { -3, -3, -2, -2, -1, -1, 0, 0, 0, 0, -1 },
        { -10, -9, -8, -6, -4, -2, -1, 0, 1, 0, 2 },
        { -6, -5, -5, -4, -3, -2, -1, 0, 1, 1, 3 },
        { -3, -3, -2, -2, -1, 0, 0, 0, 0, 0, 0 },
        { -1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
        { 4, 4, 3, 3, 2, 2, 2, 1, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 2, 2, 1, 1, 0, 0, 0, 0, 0, 1, -1 },
        { 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3 },
        { 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 3, 3, 2, 2, 1, 1, 0, -1, -1, -1, -2 },
        { 2, 2, 1, 1, 1, 1, 0, 0, -1, -1, -1 },
        { -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, -2 },
        { -3, -3, -2, -1, -1, 0, 0, 0, 0, 0, 1 },
        { -14, -13, -12, -10, -8, -6, -5, -4, -3, -2, 0 },
        { -4, -3, -3, -2, -2, -1, 0, 0, 1, 1, 3 },
        { -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0 },
        { -2, -2, -2, -1, 0, 0, 0, 0, 0, 1, 2 },
        { -7, -6, -5, -4, -3, -2, -1, 0, 0, 0, 2 },
        { -9, -8, -7, -5, -3, -1, 0, 0, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 },
        { -5, -4, -3, -2, -1, 0, 0, 1, 1, 1, 2 },
        { -3, -2, -2, -1, 0, 1, 1, 1, 1, 0, 0 },
        { -7, -6, -5, -4, -2, -1, 0, 0, 1, 1, 2 },
        { -4, -3, -2, -1, 0, 0, 0, 0, 0, 1, 2 },
        { -5, -4, -3, -2, -1, 0, 0, 0, 1, 0, 2 },
        { 2, 2, 2, 2, 2, 2, 3, 3, 3, 1, 0 },
        { -4, -3, -3, -2, -1, -1, 0, 0, 1, 0, 1 },
        { -2, -2, -1, -1, 0, 1, 1, 1, 0, 0, 0 },
        { -14, -12, -10, -8, -6, -4, -2, -1, 1, 0, 3 },
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if (ac < 0) ac = 0;
    if (ac > 10) ac = 10;
    return k[i][ac];
}

// True when the row carries the * footnote (set to receive
// a charge: double damage - the spetum, the bastard sword).
inline bool uahhSetDoubleFlag(int i) {
    static const bool k[60] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// True when the row carries the ** footnote (the dismount
// capability - eight rows).
inline bool uahhDismountFlag(int i) {
    static const bool k[60] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1,
        1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The general note: any weapon strikes at +2 vs the back.
inline int uahhRearAttackBonus()
    { return 2; }

// The general note: +4 vs stunned, prone and motionless.
inline int uahhStunnedProneBonus()
    { return 4; }

// The * footnote: these weapons do twice the damage
// indicated to size L creatures when set (firmly grounded)
// to receive a charging opponent.
inline bool uahhNoteSetDoubleVsCharge()
    { return true; }

// The ** footnote: these weapons are capable of dismounting
// a rider on a score equal to or greater than the "to hit"
// score.
inline bool uahhNoteDismountOnHit()
    { return true; }

}   // namespace rules