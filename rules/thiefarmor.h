// ===========================================================================
// Adnd1 - rules/thiefarmor.h
// The UA Thieves Table II (p. 22) pins (R334) - the effects of
// armor on thief functions, plus the paired Attacks Per Melee
// Round Table.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the table columns: the extract header prints the third
//     column as "Studded or / Padded" across two lines - one
//     column, "Studded or Padded". The no-armor column header is
//     OCR-lost but the intro sentence fixes it (bonuses apply if
//     the thief wears no armor) and each row's "+" token carries
//     the no-armor column by sign (armor columns only penalize).
//   - the printed dashes (Read Languages) pin as 0, no modifier -
//     the R184 dash convention.
//   - the attacks table: the band row labels read clean for all
//     five classes; the band-0 rate (1/1 round) is verified twice,
//     the band-1 rate (3/2 rounds) once, the band-3 rate (5/2
//     rounds) twice (cavalier 16th and paladin 19th). The band-2
//     rate cells (fighter 13th up through paladin 12-18) print
//     empty in the extract - a documented hole, 0/0, pending the
//     PDF. The paladin band edges print 7-12 then 12-18 - the
//     printed overlap at 12th pinned as printed.
//
// OCR holes (the item stays open pending the PDF read): the Open
// Locks row's "5% / -" tokens (sign and column assignment lost),
// the no-armor cells that print no token (Open Locks, Find/Remove
// Traps, Hear Noise), the attacks band-2 rate, and the footnote-1
// tail (the bracers/cloak clause survives only as fragments).
// ===========================================================================

#pragma once

namespace rules {

// ---- the armor categories (p. 22) ----
inline int thiefArmorCategoryCount()
    { return 3; }

inline const char* thiefArmorCategoryName(int i) {
    static const char* const k[3] = {
        "No Armor", "Elfin Chain",
        "Studded or Padded"
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

// ---- the thief functions (p. 22) ----
inline int thiefArmorFunctionCount()
    { return 8; }

inline const char* thiefArmorFunctionName(int i) {
    static const char* const k[8] = {
        "Pick Pockets", "Open Locks",
        "Find/Remove Traps", "Move Silently",
        "Hide in Shadows", "Hear Noise",
        "Climb Walls", "Read Languages"
    };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return k[i];
}

// ---- the cells (p. 22) ----
// function 0-7, category 0-2 (0 = no
// armor, 1 = elfin chain, 2 = studded
// or padded). The lost cells read as
// holes below; the printed dashes read
// as 0.
inline bool thiefArmorCellIsHole(
        int function, int category) {
    switch (function) {
        case 1:     // Open Locks
            return category <= 1;
        case 2:     // Find/Remove Traps
        case 5:     // Hear Noise
            return category == 0;
        default:
            return false;
    }
}

inline int thiefArmorModifierKnown(
        int function, int category) {
    static const int k[8][3] = {
        {5, -20, -30},   // Pick Pockets
        {0, 0, -10},     // Open Locks
        {0, -5, -10},    // Find/Remove
        {10, -10, -20},  // Move Silently
        {5, -10, -20},   // Hide in Shadows
        {0, -5, -10},    // Hear Noise
        {10, -20, -30},  // Climb Walls
        {0, 0, 0}        // Read Languages
    };
    if (function < 0) function = 0;
    if (function > 7) function = 7;
    if (category < 0) category = 0;
    if (category > 2) category = 2;
    return k[function][category];
}

// ---- the footnotes (p. 22) ----
// Footnote 2: no dexterity bonuses
// apply to thief functions (though
// penalties do) in armor other than
// simple leather. Footnote 3: the
// armor is assumed covered by another
// garment - elfin chain under normal
// clothing, studded leather only by a
// full body cloak. Footnote 1's tail
// is OCR-lost; the surviving fragments
// (cloak but no large protective
// devices; of defense and/or a) fix
// the no-armor clause as bracers
// and/or cloak - pinned as the
// clause's existence only.
inline bool thiefArmorNoDexBonusInArmor()
    { return true; }

inline bool thiefArmorCoveredByGarmentAssumed()
    { return true; }

inline bool thiefArmorElfinUnderNormalClothing()
    { return true; }

inline bool thiefArmorStuddedNeedsFullBodyCloak()
    { return true; }

inline bool thiefArmorNoArmorBracersOrCloak()
    { return true; }

// ---- the Attacks Per Melee Round
// Table (p. 22) - the classes ----
// For fighters, cavaliers and
// sub-classes thereof. kind 0-4:
// fighter, barbarian, ranger,
// cavalier, paladin.
inline int uaAttacksClassCount()
    { return 5; }

inline const char* uaAttacksClassName(int i) {
    static const char* const k[5] = {
        "Fighter", "Barbarian", "Ranger",
        "Cavalier", "Paladin"
    };
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    return k[i];
}

// ---- the bands (p. 22) ----
// Four bands: 1/1 round, 3/2 rounds,
// the OCR-lost high band, 5/2 rounds
// (cavalier 16th up, paladin 19th
// up). Fighter, barbarian and ranger
// print three bands; cavalier and
// paladin four.
inline int uaAttacksBandCount()
    { return 4; }

inline int uaAttacksBandAttacks(int band) {
    static const int k[4] = {1, 3, 0, 5};
    if (band < 0) band = 0;
    if (band > 3) band = 3;
    return k[band];
}

inline int uaAttacksBandRounds(int band) {
    static const int k[4] = {1, 2, 0, 2};
    if (band < 0) band = 0;
    if (band > 3) band = 3;
    return k[band];
}

inline int uaAttacksBandLow(int kind, int band) {
    static const int k[5][4] = {
        {1, 7, 13, 0},    // fighter
        {1, 6, 11, 0},    // barbarian
        {1, 8, 15, 0},    // ranger
        {1, 6, 11, 16},   // cavalier
        {1, 7, 12, 19}    // paladin
    };
    if (kind < 0) kind = 0;
    if (kind > 4) kind = 4;
    if (band < 0) band = 0;
    if (band > 3) band = 3;
    return k[kind][band];
}

inline int uaAttacksBandHigh(int kind, int band) {
    // 0 = open (and up)
    static const int k[5][4] = {
        {6, 12, 0, 0},    // fighter
        {5, 10, 0, 0},    // barbarian
        {7, 14, 0, 0},    // ranger
        {5, 10, 15, 0},   // cavalier
        {6, 12, 18, 0}    // paladin
    };
    if (kind < 0) kind = 0;
    if (kind > 4) kind = 4;
    if (band < 0) band = 0;
    if (band > 3) band = 3;
    return k[kind][band];
}

inline int uaAttacksBandForLevel(
        int kind, int level) {
    if (kind < 0) kind = 0;
    if (kind > 4) kind = 4;
    if (level < 1) level = 1;
    // first match wins: the paladin's
    // printed bands overlap at 12th
    // (7-12 and 12-18) - the earlier
    // band owns the boundary level
    for (int b = 0; b < 4; ++b) {
        if (uaAttacksBandLow(kind, b) == 0)
            continue;
        if (level < uaAttacksBandLow(kind, b))
            continue;
        int hi = uaAttacksBandHigh(kind, b);
        if (hi == 0 || level <= hi)
            return b;
    }
    return 0;
}

// ---- the asterisk and the notes
// (p. 22) ----
// With any thrusting or striking
// weapon. The figures do not apply to
// melee with monsters of less than one
// hit die (d8) and non-exceptional
// humans and semi-humans - against all
// such creatures the attacks run once
// per round per level. The figures
// also do not apply to fighters and
// rangers using weapons of
// specialization.
inline bool uaAttacksThrustingOrStrikingOnly()
    { return true; }

inline bool uaAttacksSubOneHdOncePerLevel()
    { return true; }

inline bool uaAttacksNotForSpecialized()
    { return true; }

}   // namespace rules