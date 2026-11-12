// ====================================================================
// Adnd1 - rules/dmg/assassinate.h
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

// R-refactor: namespace rules -> class Assassinate (instance methods)
class Assassinate {
public:


// The intended victim level band: 0 = levels 0-1,
// 1 = 2-3, ... 9 = 18 and beyond.
    int assassinationVictimBand(int victimLevel);


// The p.75 matrix: percent chance of success
// (instant death), -1 where the print shows a dash.
// Row index = assassin level - 1; column index = the
// victim band.
    int assassinationChance( int assassinLevel, int victimLevel);


// The footnote: the same table governs attacks on
// helpless opponents by ANY character class, not
// assassins alone.
    bool assassinationTableCoversHelpless();
};
