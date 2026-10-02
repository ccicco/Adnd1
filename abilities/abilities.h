// ============================================================================
// Adnd1 - abilities/abilities.h
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

// R118: LISTENING AT DOORS (DMG p.60) - the
// book's table is RACIAL d20 chances; R11's d6
// bands are retired. The repo has no race field,
// so callers use LISTEN_HUMAN (R114's human-only
// convention - documented); the full table stays
// pinned so a future race field inherits it
// verified. Keen-eared characters gain 1 or 2 in
// 20 (the DM determines keenness on the first
// listen and the player notes it); the repo keeps
// no per-character state, so the caller passes the
// bonus. Thieves substitute their hear-noise skill
// (PHB), converted to in-20 bands (pct/5 -
// documented derivation; the PHB table's own
// verification-debt NOTE rides). Silent creatures
// (undead, bugbears), sleeping, resting, or
// alerted creatures are never heard - the caller
// must not roll (the book's own rule).
enum ListenRace : int {
    LISTEN_DWARF    = 0,   // 2 in 20 (10%)
    LISTEN_ELF      = 1,   // 3 in 20 (15%)
    LISTEN_GNOME    = 2,   // 4 in 20 (20%)
    LISTEN_HALF_ELF = 3,   // 2 in 20 (10%)
    LISTEN_HALFLING = 4,   // 3 in 20 (15%)
    LISTEN_HALF_ORC = 5,   // 3 in 20 (15%)
    LISTEN_HUMAN    = 6,   // 2 in 20 (10%)
    LISTEN_RACE_COUNT
};

int raceListenIn20(ListenRace race);            // the book's table
int listenChanceIn20(ListenRace race, int keenIn20);
int thiefListenIn20(int thiefLevel, int keenIn20);
bool listenAtDoor(Dice& dice, int chanceIn20);  // d20 <= chance

// R120: the best listener at the door - a thief
// rides his hear-noise skill, otherwise the human
// band (R114's no-race-field convention)
int bestListenIn20(bool hasThief, int thiefLevel);

// Climbing: non-thieves climb at 40% for sheer surfaces (DMG).
int climbChancePct(bool isThief, int thiefLevel);

// Level-gated capabilities.
bool canUseScroll(int classIndex, int level);   // MU: any; thief L10+
bool fighterFollowersAt(int level);             // fighter L9
bool clericStrongholdAt(int level);             // cleric L8+

} // namespace abilities