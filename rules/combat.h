// ============================================================================
// Adnd1 — rules/combat.h
// Attack matrices, weapon-vs-AC adjustments, undead turning.
//
// Source: Dungeon Masters Guide (2012 Premium reprint).
//   - Attack matrices: DMG p.74-75 (combat tables; fighter matrix is the
//     master, other classes row-shift into it)
//   - Monster attacks: DMG p.80 "Monsters attacking" — attack as fighters
//     at a level derived from hit dice (section II)
//   - Weapon vs AC adjustments: DMG p.38 table (weapon type vs armor class
//     type: better/worse by 1-2)
//   - Turning undead: DMG p.75 cleric turn matrix (rows 1-8+, columns
//     skeleton..vampire; T=turn, D=destroy, number=2d6 turned, dash=no
//     effect, *=auto within 60')
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

// Fighter attack matrix: to-hit number by level (rows) vs AC (columns).
// AC columns run 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1 (12 columns),
// level rows 1..20 (index 0 = level 1).
int attackMatrixFighter(int level, int ac);

// Class attack numbers: cleric/MU/thief attack as fighters at a lower
// effective level (the 1e convention — the DMG prints separate tables
// that are row-shifts of the fighter matrix):
//   cleric: effective level = level (clerics use their own near-fighter
//           progression; encoded as level - 2, min 1)
//   thief:  effective level = level - 4, min 1  ( thieves attack worse
//           than fighters)
//   MU:     effective level = level - 3, min 1  (magic-users attack
//           slightly worse than clerics)
int effectiveAttackLevel(int level, int classIndex);

// Convenience: to-hit number for a class/level vs AC.
// classIndex: 0 fighter, 1 MU, 2 cleric, 3 thief (matches CharClass).
int attackNumber(int classIndex, int level, int ac);

// Monster attack: attack as fighter at effective level per DMG p.80 II.
// HD  up to 1   -> level 1;  then roughly 1 level per HD, capped by the
// matrix (rows to 20+).
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

// Derive the AC type from a descending AC number (armor mapping hook —
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
// Turning undead (DMG p.75). The cleric turn matrix by cleric level
// vs undead type. Result:
//   'T'  turn all presented undead of the type
//   'D'  destroy (skeleton/zombie rows at high level)
//   0-9  number = 2d6 count turned (we return the digit; caller rolls)
//   ' '  dash: no effect possible
//   '*'  automatic success within 60' (treated as T here)
// ----------------------------------------------------------------------------

enum TurnResult : int {
    TURN_NONE = 0,      // dash — cannot affect
    TURN_COUNT,         // number shown: roll 2d6 turned
    TURN_ALL,           // T — all turned
    TURN_DESTROY,       // D — all destroyed
};

struct TurnAttempt {
    TurnResult result;
    int        countDigit;   // valid when result == TURN_COUNT
};

// undeadKind: 0 skeleton, 1 zombie, 2 ghoul, 3 shadow, 4 wight, 5 ghast,
// 6 wraith, 7 mummy, 8 spectre, 9 vampire, 10 lich, 11 "special"
// (ghast/banshee row per original tranche 55; see monsters layer).
TurnAttempt turnUndead(int clericLevel, int undeadKind);

// Roll the 2d6 for a TURN_COUNT attempt.
int rollTurnCount(Dice& dice, int countDigit);

} // namespace rules