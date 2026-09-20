// ============================================================================
// Adnd1 — abilities/abilities.h
// Character-facing special abilities: thief skills, class features.
//
// Source: Players Handbook (2012 Premium reprint), pp. 26-28 (thief
// skills table), p. 27 (backstab), p. 26 (listening), DMG p.19
// (climbing). Values follow the PHB thief skill tables by level;
// DEX and armor modifiers per PHB p.38-39 notes (armor penalties).
// ============================================================================

#pragma once

#include "../rules/dice.h"

#include <cstdint>

namespace abilities {

using rules::Dice;

// ----------------------------------------------------------------------------
// Thief skills (PHB p.28 table). Percent chances by thief level.
// ----------------------------------------------------------------------------
enum ThiefSkill : int {
    SKILL_PICK_POCKETS = 0,
    SKILL_OPEN_LOCKS,
    SKILL_FIND_TRAPS,
    SKILL_MOVE_SILENTLY,
    SKILL_HIDE_IN_SHADOWS,
    SKILL_HEAR_NOISE,
    SKILL_CLIMB_WALLS,
    SKILL_READ_LANGUAGES,
    SKILL_COUNT
};

const char* thiefSkillName(ThiefSkill s);

// Base percent for a thief skill at a level (1-12 encoded; level 12
// is the name-level cap of the table, higher levels repeat the L12
// row per PHB).
int thiefSkillBase(ThiefSkill skill, int level);

// Attempt a skill: d100 <= adjusted chance.
//   dexAdj: DEX-based adjustment for the skill (caller computes)
//   armorPenalty: percent subtracted for worn armor (caller computes)
bool attemptThiefSkill(Dice& dice, ThiefSkill skill, int level,
                       int dexAdj, int armorPenalty);

// Backstab (PHB p.27): multiplier by thief level.
//   L1-4: x2, L5-8: x3, L9-12: x4, L13+: x5
int backstabMultiplier(int thiefLevel);

// Listening at doors (PHB p.26, DMG p.19).
bool listenAtDoor(Dice& dice, int chanceIn6);
int listenChanceIn6(bool stoneDoor, bool isThief, int thiefLevel);

// Climbing: non-thieves climb at 40% for sheer surfaces (DMG).
int climbChancePct(bool isThief, int thiefLevel);

// Level-gated capabilities.
bool canUseScroll(int classIndex, int level);   // MU: any; thief L10+
bool fighterFollowersAt(int level);             // fighter L9
bool clericStrongholdAt(int level);             // cleric L8+

} // namespace abilities