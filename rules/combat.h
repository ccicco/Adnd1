// ============================================================================
// Adnd1 - rules/combat.h
// Attack matrices, weapon-vs-AC adjustments, undead turning.
//
// Source: Dungeon Masters Guide (2012 Premium reprint).
//   - Fighter attack matrix: DMG p.75 matrix I.B, the book's own
//     banded table (level bands 0, 1-2, ..., 17+ vs AC 10..-10) -
//     transcribed cell for cell by R111, negatives included
//   - Other classes still row-shift into the fighter matrix (an
//     approximation; the book prints separate matrices I.A/I.C/I.D -
//     an open gap-report item)
//   - Monster attacks: DMG p.75-76 matrix II - the book's own HD-banded
//     monster table, transcribed cell for cell by R112 (monsters do
//     NOT attack as fighters)
//   - Weapon vs AC adjustments: DMG p.38 table (weapon type vs armor
//     class type: better/worse by 1-2)
//   - Turning undead: DMG p.75-76 matrix III, 13 undead rows, cleric
//     level columns 1-8/9-13/14+; d20 match-or-exceed, T/D/D*/dash,
//     counts 1-12 (7-12 starred, 1-2 Special)
// Cross-checked against the 1979 TSR scan (values verified identical).
// ============================================================================

#pragma once

#include "dice.h"

#include <cstdint>

namespace rules {

// ----------------------------------------------------------------------------
// Descending AC convention: 10 = unarmored, 0/-1/-2 = best armors.
// Attacks need d20 >= toHitNumber(level, AC). Natural 20 always hits
// (logged convention, matches 1e matrix reading where 20 hits
// everything on the printed tables).
// ----------------------------------------------------------------------------

// Fighter attack matrix (DMG p.75 I.B): to-hit number by level band
// vs AC. Bands: 0, 1-2, 3-4, 5-6, 7-8, 9-10, 11-12, 13-14, 15-16,
// 17+; AC runs 10 down to -10, clamped at either end. Targets may be
// negative (high band vs low AC) or above 20 (low band vs very low
// AC - only a natural 20 can hit, per the attackRollHits convention).
int attackMatrixFighter(int level, int ac);

// Class attack numbers (DMG p.75 I.A/I.C/I.D): the book's own
// tables for cleric (I.A: bands 1-3/4-6/7-9/10-12/13-15/16-18/
// 19+), magic-user (I.C: bands 1-5/6-10/11-15/16-20/21+) and
// thief (I.D: bands 1-4/5-8/9-12/13-16/17-20/21+), each 21 AC
// rows (10 down to -10), transcribed cell for cell by R113. The
// effectiveAttackLevel row-shift approximation is gone. Targets
// may be negative or above 20 (natural 20 / natural 1 convention
// as in attackRollHits).

// Convenience: to-hit number for a class/level vs AC.
// classIndex: 0 fighter (matrix I.B), 1 MU (I.C), 2 cleric (I.A),
// 3 thief (I.D) (matches CharClass).
int attackNumber(int classIndex, int level, int ac);

// Convenience: to-hit number for a class/level vs AC.
// classIndex: 0 fighter, 1 MU, 2 cleric, 3 thief (matches CharClass).
int attackNumber(int classIndex, int level, int ac);

// Monster attack (DMG p.75-76 matrix II): to-hit number by the
// monster's hit-dice band (12 bands, up to 1-1 through 16+) vs AC
// 10 down to -10, clamped at either end. Targets may be negative or
// above 20 (natural 20 / natural 1 convention as in attackRollHits).
int attackMatrixMonster(float hitDice, int ac);

// Monster effective level (DMG p.86 guard rule): hit dice to a level
// for guard strength and similar non-combat uses. NOT used for
// attacks (matrix II) or saves (monsterSaveLevel, rules/saves.h).
int monsterEffectiveLevel(float hitDice);

// Resolve one melee attack roll. Returns true on a hit.
//   d20 roll + hitAdj (STR etc.) >= toHitNumber => hit.
//   Natural 20 always hits; natural 1 always misses (convention).
bool attackRollHits(Dice& dice, int toHitNumber, int hitAdj);

// ----------------------------------------------------------------------------
// Weapon vs AC adjustments (DMG p.38)
//   Weapon class vs armor class type gives -2..+2 on the to-hit number
//   (positive = better). AC types: 0 none, 1 leather, 2 chain, 3 plate
//   (approximation of the DMG weapon-type armor categories: no armor/
//   leather, chain/scale, plate/field plate; shields shift one column).
// ----------------------------------------------------------------------------

enum AcType : int {
    AC_TYPE_NONE = 0,
    AC_TYPE_LEATHER,
    AC_TYPE_CHAIN,
    AC_TYPE_PLATE,
    AC_TYPE_COUNT
};

enum WeaponClass : int {
    WCLASS_BLUDGEONING = 0,   // club, mace, flail, staff
    WCLASS_PIERCING,          // dagger, spear, arrow
    WCLASS_SLASHING,          // sword, axe
    WCLASS_COUNT
};

// To-hit adjustment for weapon class vs AC type (DMG p.38 values):
//   piercing is better vs chain, worse vs plate; bludgeoning is better
//   vs plate, worse vs none/leather; slashing is neutral-biased.
int weaponVsAcAdjustment(WeaponClass wc, AcType ac);

// Derive the AC type from a descending AC number (armor mapping hook -
// the items layer refines this once armor data exists; default mapping
// follows the PHB armor table: 10-8 none/leather, 7-5 chain-scale,
// 4-2 plate/splint, 1-0 field plate/full).
AcType acTypeForAc(int ac);

// ----------------------------------------------------------------------------
// Magic weapon gating hook (wired by the monsters layer later):
// a defender requiring +N to hit ignores attacks whose weapon bonus is
// below N (clang, 0 damage). Spell damage bypasses gating.
// ----------------------------------------------------------------------------

bool weaponSufficient(int requiredPlus, int weaponBonus);

// ----------------------------------------------------------------------------
// R116: missile range modifiers (DMG p.75 - "Missiles:
// -5 at long range, -2 at medium range"). The registry
// stores each missile weapon's SHORT range (items, PHB
// p.38); medium is twice short and long three times -
// the weapon tables' own shape for bows (documented
// derivation; the M/L columns are not in the registry).
// Beyond long range no shot is possible.
// ----------------------------------------------------------------------------

// true while the distance is within the weapon's long
// range (3x short) - a shot at all
bool missileInRange(int distanceFeet, int shortRangeFeet);

// the book's to-hit modifier at that distance:
// 0 at short, -2 at medium, -5 at long
int missileRangeMod(int distanceFeet, int shortRangeFeet);

// ----------------------------------------------------------------------------
// R141: engagement geometry (closing the R43 50' debt)
// ----------------------------------------------------------------------------
// A room fight opens at the chamber's own geometry: the
// longest interior dimension in 10' bands - floored at
// the 50' corridor convention (5 bands) and capped at
// 120' (12 bands, a sling's long range). A big chamber
// therefore opens WIDE, and the R116 long band (-5) is
// finally reachable in play. Wandering and overland
// engagements keep the 50' convention (no room).
inline int engagementBands(int roomW, int roomH) {
    int longest = roomW > roomH ? roomW : roomH;
    if (longest < 5) return 5;
    if (longest > 12) return 12;
    return longest;
}

// ----------------------------------------------------------------------------
// Turning undead (DMG p.75-76 matrix III; procedure p.77). Rows are the
// undead in the book's own order, columns are cleric levels 1-8, 9-13,
// 14+. Result:
//   dash no effect possible, ever - a failed roll cannot be retried
//   T    automatic turning - all presented undead of the type
//   D    automatic destruction - all presented undead of the type
//   D*   automatic destruction of 7-12 (the starred cells)
//   4-20 a d20 target: match or exceed and 1-12 are turned
// Paladins turn as a cleric two levels below (p.75 footnote).
// ----------------------------------------------------------------------------

enum TurnResult : int {
    TURN_NONE = 0,      // dash - cannot affect
    TURN_ALL,           // T - automatic turn
    TURN_DESTROY,      // D - automatic destroy (countKind gives the count)
    TURN_CHANCE,        // a d20 target must be matched or exceeded
};

enum TurnCount : int {
    TURN_COUNT_1_12 = 0,   // d12 affected (the number cells)
    TURN_COUNT_7_12 = 1,   // d6+6 affected (the starred D* cells)
    TURN_COUNT_1_2  = 2,   // d2 affected (the Special row)
};

struct TurnAttempt {
    TurnResult result;
    int        target;     // d20 target when result == TURN_CHANCE
    int        countKind;  // TurnCount: how many are affected on success
};

// undeadKind: 0 skeleton, 1 zombie, 2 ghoul, 3 shadow, 4 wight, 5 ghast,
// 6 wraith, 7 mummy, 8 spectre, 9 vampire, 10 ghost, 11 lich, 12 special
// (the book's own row order, matrix III; paladins subtract two levels).
TurnAttempt turnUndead(int clericLevel, int undeadKind);

// d20 match-or-exceed for TURN_CHANCE. The automatic results resolve
// without a roll (true for TURN_ALL/TURN_DESTROY, false for TURN_NONE).
bool rollTurnSuccess(Dice& dice, const TurnAttempt& t);

// The affected count: d12 (1-12), d6+6 (7-12) for the starred D* cells,
// d2 (1-2) for the Special row. Plain T and D affect all presented
// undead of the type - the caller does not roll a count for them.
int rollTurnCount(Dice& dice, const TurnAttempt& t);

} // namespace rules