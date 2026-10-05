// ============================================================================
// Adnd1 - rules/saves.h
// Saving throws.
//
// Source: Dungeon Masters Guide (Premium reprint) pp.79-80, saving
// throw matrices I and II - the banded per-class tables, the natural-1
// rule, and the monster HD-to-level rule. (The earlier PHB-derived
// linear rows were replaced by R110; the printed DMG table wins.)
// ============================================================================

#pragma once

#include "dice.h"

#include <cstdint>

namespace rules {

// ----------------------------------------------------------------------------
// The five saving throw categories (PHB convention):
//   1. Death, Poison (death/poison/poison spray etc.)
//   2. Wands (paralysis/rod/staff/wand category - named for the rod/
//      staff/wand column; includes paralysis effects per PHB note)
//   3. Petrification, Polymorph (paralysis-or-petrification-or-polymorph)
//   4. Breath Weapon (dragon breath, gas, area effects)
//   5. Spells, Staves (spell, staff-spell effects)
// ----------------------------------------------------------------------------
enum SaveCategory : int {
    SAVE_DEATH_POISON = 0,
    SAVE_WANDS,
    SAVE_PETRIFY_POLY,
    SAVE_BREATH,
    SAVE_SPELLS,
    SAVE_COUNT
};

const char* saveCategoryName(SaveCategory s);

// Save target number for a class/level (classIndex: 0 fighter, 1 MU,
// 2 cleric, 3 thief - matches CharClass). d20 >= target succeeds.
// Lower is better; targets improve (drop) with level.
int saveTarget(int classIndex, int level, SaveCategory cat);

// ----------------------------------------------------------------------------
// Modifiers assembled by the caller:
//   WIS magical defense adjustment (rules/character wisMagDefAdj,
//   the printed Wisdom Table I ladder R194 -3..+4; applies
//   only to mental attack forms involving will force:
//   beguiling, charming, fear, hypnosis, illusion, magic
//   jarring, mass charming, phantasmal forces, possession,
//   rulership, suggestion, telepathic attack - the save
//   rolls do not call it; the caller assembles the modifier)
//   CON poison save adjustment (vs. SAVE_DEATH_POISON)
//   DEX reaction adj (vs. breath/AoE - DMG guidance)
//   item/save bonuses (items layer later)
// attemptSave rolls d20 + modifier >= target. A natural 1 is ALWAYS
// failure (DMG p.80), regardless of magical protections or modifiers.
// ----------------------------------------------------------------------------
bool attemptSave(Dice& dice, int target, int modifier);

// ----------------------------------------------------------------------------
// Monster saves (DMG p.80 matrix II): monsters save on the character
// matrices - most as fighters. Hit dice equate to experience level,
// with hit-point pluses stepping the creature up one die level per
// 4 points (1+1..1+4 -> 2, 2+1..2+4 -> 3, ...).
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// R155: DMG p.80 matrix II.C - classed monsters. A monster whose
// write-up gives it class abilities saves on its MOST FAVORABLE
// matrix (footnotes 1-2: the best class score, or the matrix of
// its area of ability). The Lua saveAs key parses into these class
// bits with per-class levels (couatl: MU 5 AND cleric 7).
// ----------------------------------------------------------------------------
const int SAVE_AS_FIGHTER     = 1;
const int SAVE_AS_MAGIC_USER  = 2;
const int SAVE_AS_CLERIC      = 4;
const int SAVE_AS_THIEF       = 8;

// R155: the min target over the classes in the mask (each at its
// own level, levels[classIndex]) vs the base class/level target -
// the II.B fighter-matrix convention stays in the min. mask 0 (or
// no usable bits) returns the plain base target.
int mostFavorableSaveTarget(int classMask, const int* levels,
                            int baseClass, int baseLevel,
                            SaveCategory cat);

int monsterSaveLevel(float hitDice);

bool attemptMonsterSave(Dice& dice, float hitDice, SaveCategory cat,
                        int modifier = 0);

// ----------------------------------------------------------------------------
// Magic resistance hook (wired by the monsters layer): percent chance
// to outright resist, checked BEFORE any save. MR from monster Lua
// data (magicResist key). A natural-effect roll of d100 <= MR resists.
// ----------------------------------------------------------------------------
bool magicResistanceBlocks(Dice& dice, int magicResistPct);

} // namespace rules