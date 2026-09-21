// ============================================================================
// Adnd1 — rules/classes.h
// Character classes: caps, hit dice, XP thresholds, titles, primes.
//
// RE-AUTHORED from the R4 spec after the original upload was lost
// from the repo. NOTE discipline: XP tables and title ladders are
// transcribed from project notes and follow the standard 1e shape;
// when the PHB PDF is re-uploaded, the printed tables win (PHB
// p.20-31) — verify xpForLevel rows and titleFor ladders then.
// ============================================================================

#pragma once

#include "dice.h"
#include "character.h"

namespace rules {

// ----------------------------------------------------------------------------
// Enums
// ----------------------------------------------------------------------------

enum CharClass : int {
    CLASS_FIGHTER = 0,
    CLASS_MAGIC_USER = 1,
    CLASS_CLERIC = 2,
    CLASS_THIEF = 3,
    CLASS_COUNT = 4
};

enum ClassGroup : int {
    GROUP_FIGHTER = 0,   // fighter (paladin/ranger later)
    GROUP_PRIEST = 1,    // cleric (druid later)
    GROUP_WIZARD = 2,    // magic-user (illusionist later)
    GROUP_ROGUE = 3      // thief (assassin later)
};

enum ArmorWeight : int {
    ARMOR_NONE = 0,
    ARMOR_LEATHER = 1,
    ARMOR_CHAIN = 2,
    ARMOR_PLATE = 3
};

// ----------------------------------------------------------------------------
// Class constants (indexed by CharClass)
// ----------------------------------------------------------------------------

// Name (level) caps: fighter 9, magic-user 11, cleric 9, thief 10
extern const int CLASS_LEVEL_CAP[CLASS_COUNT];

// Fixed hp per level beyond the name cap: fighter 3, MU 1, cleric 2,
// thief 2 (the 3/2/2/1-vs-3/1/2/2 convention question is settled
// HERE as 3/1/2/2 in F/MU/C/T order; PHB verification pending)
extern const int HP_BEYOND_CAP[CLASS_COUNT];

// Hit die per class: d10 / d4 / d8 / d6
extern const int CLASS_HIT_DIE[CLASS_COUNT];

// ----------------------------------------------------------------------------
// Functions
// ----------------------------------------------------------------------------

// Total XP required to ATTAIN the given level (level 1 = 0).
// Rows are defined through level 12 (13 entries, index = level-1);
// beyond the table, each level adds the class's linear adder
// (fighter 100k, MU 125k, cleric 112.5k, thief 110k).
int xpForLevel(int classIndex, int level);

// Display title for a class/level (PLACEHOLDER LADDERS — verify vs
// PHB p.20-31 in a later pass).
const char* titleFor(int classIndex, int level);

// Prime requisite ability (returns an Ability enum value from
// character.h: AB_STR / AB_INT / AB_WIS / AB_DEX).
int primeRequisite(int classIndex);

// Minimum score in the prime requisite to enter the class (all 9).
int classMinAbility(int classIndex);

// HP adjustment per hit die for the given CON score.
// Fighter group: CON 17 = +3, 18 = +4; other classes cap at +2.
// Negatives are full for everyone: CON 3 = -2, 4-6 = -1.
int conHPAdjustment(int classIndex, int con);

// Roll ONE level's worth of hit points: 1 hit die + conAdj, with a
// per-die floor of 1. Beyond the class's name cap, the fixed
// HP_BEYOND_CAP value + conAdj is used instead of a die roll.
int rollHitPoints(int classIndex, int level, int conAdj, Dice& dice);

// Average (fixed) hp for one level of the class: (1 + die) / 2.
int averageHitPoints(int classIndex);

// Armor/shield permissions by class:
//   fighter: any armor + shield
//   cleric:  up to chain + shield
//   MU:      none, no shield
//   thief:   up to leather, no shield
bool armorAllowed(int classIndex, ArmorWeight weight);
bool shieldAllowed(int classIndex);

// Exceptional strength percentile (d100), for fighter-group
// characters with STR 18 — the caller gates on those conditions;
// this just rolls 1-100.
int rollExceptionalStrength(Dice& dice);

} // namespace rules
