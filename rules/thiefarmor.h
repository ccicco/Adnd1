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
//     five classes; the R393 clean print fills the band-2 rate
//     (2/1 round) - the band-0 (1/1), band-1 (3/2) and
//     band-3 (5/2) fragment reads seam-agree. The paladin band
//     edges print 7-12 then 12-18 - the printed overlap at 12th
//     pinned as printed.
//
// R393 (the clean PDF read): every OCR hole fills. The Open Locks
// row reads dash / -5% / -10%; the no-armor cells that printed no
// token read as printed dashes (Find/Remove Traps, Hear Noise -
// the R184 dash convention, 0); the attacks band-2 rate reads 2/1 round;
// the footnote-1 tail prints in full (bracers of defense and/or a cloak,
// but no large protective devices). One print anomaly stays
// flagged: the Hide in Shadows row carries a footnote-4 marker
// whose text prints nowhere on the clean
// page - pinned as the orphaned marker.
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

// ---- the cells (p. 22, the R393
// clean read) ----
// function 0-7, category 0-2 (0 = no
// armor, 1 = elfin chain, 2 = studded
// or padded). Every cell reads; the
// printed dashes read as 0 (the R184
// dash convention).
inline bool thiefArmorCellIsHole(
        int function, int category) {
    // R393: every hole fills - no
    // cell is a hole any longer
    (void) function;
    (void) category;
    return false;
}

inline int thiefArmorModifierKnown(
        int function, int category) {
    static const int k[8][3] = {
        {5, -20, -30},   // Pick Pockets
        {0, -5, -10},    // Open Locks
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

// ---- the footnotes (p. 22, the
// R393 clean read) ----
// Footnote 1 prints in full: the
// no-armor category applies when
// wearing bracers of defense
// and/or a cloak, but no large
// protective devices. Footnote 2: no
// dexterity bonuses apply to thief
// functions (though penalties do) in
// armor other than simple leather.
// Footnote 3: the armor is assumed
// covered by another garment - elfin
// chain under normal clothing,
// studded leather only by a full
// body cloak. The Hide in Shadows
// row carries a footnote-4 marker
// whose text prints nowhere - the
// orphaned marker pinned as such.
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

// R393: the footnote-1 tail prints
// in full; the footnote-4 marker
// prints with no text anywhere.
inline bool thiefArmorFootnoteOnePrintsInFull()
    { return true; }

inline bool thiefArmorNoArmorLargeDevicesBarred()
    { return true; }

inline bool thiefArmorFootnoteFourOrphaned()
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

// ---- the bands (p. 22, the R393
// clean read) ----
// Four bands: 1/1 round, 3/2
// rounds, 2/1 round (the clean
// read fills the lost rate), 5/2
// rounds (cavalier 16th up,
// paladin 19th up). Fighter,
// barbarian and ranger print
// three bands; cavalier and
// paladin four.
inline int uaAttacksBandCount()
    { return 4; }

inline int uaAttacksBandAttacks(int band) {
    static const int k[4] = {1, 3, 2, 5};
    if (band < 0) band = 0;
    if (band > 3) band = 3;
    return k[band];
}

inline int uaAttacksBandRounds(int band) {
    static const int k[4] = {1, 2, 1, 2};
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