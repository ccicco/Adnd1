// ====================================================================
// Adnd1 - rules/assassinate.h
// R164: the assassination table (DMG p.75) - the
// odds matrix for assassination attempts.
//
// Pure data, header-only (the grenade.h pattern: the
// caller rolls the percentile dice and owns the
// plan-vs-precautions adjustments). The p.19-20
// spying rules stay as wired (the spy).
//
// The p.75 print:
//   - The table: assassin level 1-15 (rows) against
//     the intended victim level band 0-1, 2-3, 4-5,
//     6-7, 8-9, 10-11, 12-13, 14-15, 16-17, 18+
//     (columns). The printed dash reads -1 here: no
//     chance at all.
//   - JUDGMENT: an attacker below level 1 reads row
//     1, and above level 15 reads row 15.
//   - Footnote: the table also governs attacks on
//     helpless opponents by ANY character class
//     (the COMBAT section note on automatically slain
//     sleeping or held opponents).
//   - The percentages are for success (instant death)
//     under NEAR OPTIMUM conditions: adjust slightly
//     upwards for perfect conditions (absolute
//     trust, asleep and unguarded, very drunk and
//     unguarded) and deduct for a wary, prepared or
//     guarded victim - caller-side.
//   - Weapon damage always occurs and may kill the
//     victim even when the assassination roll fails
//     - caller-side.
// ====================================================================

#pragma once

namespace rules {

// The intended victim level band: 0 = levels 0-1,
// 1 = 2-3, ... 9 = 18 and beyond.
inline int assassinationVictimBand(int victimLevel) {
    if (victimLevel < 0) victimLevel = 0;
    int band = victimLevel / 2;
    if (band > 9) band = 9;
    return band;
}

// The p.75 matrix: percent chance of success
// (instant death), -1 where the print shows a dash.
// Row index = assassin level - 1; column index = the
// victim band.
inline int assassinationChance(
        int assassinLevel, int victimLevel) {
    static const int kTable[15][10] = {
        { 50, 45, 35, 25, 10,  1, -1, -1, -1, -1 },
        { 55, 50, 40, 30, 15,  2, -1, -1, -1, -1 },
        { 60, 55, 45, 35, 20,  5, -1, -1, -1, -1 },
        { 65, 60, 50, 40, 25, 10,  1, -1, -1, -1 },
        { 70, 65, 55, 45, 30, 15,  5, -1, -1, -1 },
        { 75, 70, 60, 50, 35, 20, 10,  1, -1, -1 },
        { 80, 75, 65, 55, 40, 25, 15,  5, -1, -1 },
        { 85, 80, 70, 60, 45, 30, 20, 10,  2, -1 },
        { 95, 90, 80, 70, 55, 40, 30, 20,  5, -1 },
        { 99, 95, 85, 75, 60, 45, 35, 25, 10,  1 },
        { 100, 99, 90, 80, 65, 50, 40, 30, 15,  5 },
        { 100, 100, 95, 85, 70, 55, 45, 35, 20, 10 },
        { 100, 100, 99, 95, 80, 65, 50, 40, 25, 15 },
        { 100, 100, 100, 99, 90, 75, 60, 50, 35, 25 },
        { 100, 100, 100, 100, 99, 85, 70, 60, 40, 30 }
    };
    if (assassinLevel < 1) assassinLevel = 1;
    if (assassinLevel > 15) assassinLevel = 15;
    return kTable[assassinLevel - 1]
        [assassinationVictimBand(victimLevel)];
}

// The footnote: the same table governs attacks on
// helpless opponents by ANY character class, not
// assassins alone.
inline bool assassinationTableCoversHelpless() {
    return true;
}

} // namespace rules
