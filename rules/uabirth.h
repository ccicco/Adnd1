// ===========================================================================
// Adnd1 - rules/uabirth.h
// The UA CIRCUMSTANCES OF BIRTH (p. 83 print) pins,
// R367: the Birth Table (the 12-child ladder with
// the only-child row), the Parents' Marital Status
// Table and the racial modifiers.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the section intro garbles ("By the nature for
//     of the topic...") - the readable tail pins (the
//     DM decides, the tables are a starting point),
//     the rest is a hole pending the PDF.
//   - the high-elf modifier cell prints a bare "20"
//     with the sign lost (every other cell carries
//     an explicit sign) - the magnitude pins, the
//     sign is a hole pending the PDF.
//   - the marital-status print interleaves the
//     married/unmarried labels across the dice
//     columns (01-80 / 81-00) - the split pins from
//     the readable dice cells.
// ===========================================================================

#pragma once

namespace rules {

// ---- the birth table, 13 rows ----
inline int uabirthRowCount()
    { return 13; }

inline int uabirthRowLow(int i) {
    static const int k[13] = {
        1, 6, 11, 21, 36, 51, 66, 81, 86,
        91, 95, 98, 100,
    };
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    return k[i];
}

inline int uabirthRowHigh(int i) {
    static const int k[13] = {
        5, 10, 20, 35, 50, 65, 80, 85, 90,
        94, 97, 99, 100,
    };
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    return k[i];
}

inline const char* uabirthOrderLabel(int i) {
    static const char* const k[13] = {
        "Only child", "1st child", "2nd child",
        "3rd child", "4th child", "5th child",
        "6th child", "7th child", "8th child",
        "9th child", "10th child", "11th child",
        "12th child",
    };
    if (i < 0) i = 0;
    if (i > 12) i = 12;
    return k[i];
}

// ---- the parents' marital status table ----
inline int uabirthMarriedLow()
    { return 1; }

inline int uabirthMarriedHigh()
    { return 80; }

inline int uabirthUnmarriedLow()
    { return 81; }

inline int uabirthUnmarriedHigh()
    { return 100; }

// The child of unmarried parents is typically one
// social class lower than the social class of the
// father.
inline bool uabirthUnmarriedOneClassBelowFather()
    { return true; }

// ---- the racial modifiers (both tables) ----
inline int uabirthDwarfMod()
    { return -15; }

inline int uabirthElfDrowMod()
    { return -15; }

inline int uabirthElfGrayMod()
    { return -30; }

// The R394 clean read: the high-elf
// cell prints -20 - the sign pins
// negative like every other cell.
inline int uabirthElfHighModMagnitude()
    { return 20; }

inline int uabirthElfHighMod()
    { return -20; }

inline bool uabirthElfHighModSignLost()
    { return false; }

inline int uabirthElfWoodMod()
    { return -10; }

inline int uabirthElfOtherMod()
    { return -15; }

inline int uabirthGnomeMod()
    { return -20; }

inline int uabirthHalfElfMod()
    { return -10; }

inline int uabirthHalflingMod()
    { return -10; }

// The half-orc split: +10 on the Birth Table, +75 on
// the Marital Status Table.
inline int uabirthHalfOrcBirthMod()
    { return 10; }

inline int uabirthHalfOrcMaritalMod()
    { return 75; }

inline bool uabirthHumanNoMods()
    { return true; }

// ---- the intro reads ----
// The R394 clean read: the section
// intro reads clean in the PDF.
inline bool uabirthIntroGarbled()
    { return false; }

inline bool uabirthDmDecidesToMilieu()
    { return true; }

inline bool uabirthTablesAStartingPoint()
    { return true; }

}   // namespace rules

