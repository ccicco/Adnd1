// ============================================================================
// Adnd1 - spelleffects/spelleffects.h
// Spell resolution engine. Works on target DESCRIPTORS (hp, save
// bonuses, MR) so both characters and monsters plug in - no actor
// types here.
//
// Depends: rules/saves (R6), rules/dice (R1), spells/ (R13).
// ============================================================================

#pragma once

#include "../rules/dice.h"
#include "../rules/saves.h"
#include "../spells/spells.h"

#include <vector>

namespace spelleffects {

using rules::Dice;

// ----------------------------------------------------------------------------
// Status effects (data, cleared on save / expiry by caller's tick)
// ----------------------------------------------------------------------------
enum StatusKind : int {
    STATUS_NONE = 0,
    STATUS_SLEEP,
    STATUS_CHARMED,
    STATUS_HASTED,
    STATUS_SLOWED,
    STATUS_SILENCED,
    STATUS_HELD,
    STATUS_INVISIBLE,
    STATUS_PROT_EVIL,
    STATUS_SHIELDED,     // mage shield spell
    STATUS_FIRESHIELD,   // R81: Fire Shield - melee reflect
    STATUS_ANTIVENOM,    // R81: Slow/Neutralize Poison - save bonus
    STATUS_POLYMORPHED,  // R82: Polymorph Other - held-like
    STATUS_COUNT
};

struct StatusEffect {
    StatusKind kind = STATUS_NONE;
    int        roundsRemaining = 0;
    int        magnitude = 0;    // e.g. shield AC bonus
};

// R82: Death Spell HD budget (PHB L6 MU): the spell snuffs out
// up to 4 x caster level hit dice of creatures.
inline int deathSpellBudget(int casterLevel) {
    if (casterLevel < 1) casterLevel = 1;
    return casterLevel * 4;
}

// R81: Fire Shield reflect - the melee attacker takes half the
// damage dealt, rounded up, minimum 1
inline int fireShieldDamage(int dmg) {
    int r = dmg / 2 + (dmg % 2 ? 1 : 0);
    return r < 1 ? 1 : r;
}

const char* statusName(StatusKind s);

// ----------------------------------------------------------------------------
// Target descriptor: what the engine needs to resolve against.
//   hp / maxHp        current and max hit points
//   saveClass         0-3 (fighter/MU/cleric/thief matrix for target)
//   saveLevel         target's class level for the save table
//   saveBonus         flat modifier (WIS magic adj, rings, etc.)
//   saveDwarfBonus    R147 dwarf CON magic-save bonus (PHB p.16)
//   saveNonIntelligent  R147 matrix II.D half-level flag
//   magicResistPct    MR checked before anything else
//   isUndead          charm person etc. don't affect undead
//   isLarge           some effects differ vs large targets
// ----------------------------------------------------------------------------
struct TargetDesc {
    int hp = 10;
    int maxHp = 10;
    float hitDice = 1.0f;   // R82: Death Spell HD budgeting
    int saveClass   = 0;
    int saveLevel   = 1;
    int saveBonus   = 0;
    // R147: dwarf CON magic-save bonus (0 for everyone but
    // NPC-foe dwarves) and the matrix II.D non-intelligence
    // flag - applied by trySave / the ai save helper.
    int saveDwarfBonus = 0;
    bool saveNonIntelligent = false;
    int magicResistPct = 0;
    bool isUndead = false;
    bool isLarge  = false;
};

// R147: DMG p.80 matrix II footnote D - a creature of
// non-intelligence saves at half its (II.B-stepped)
// level, rounded up, except vs. death magic/poison where
// the footnote grants no relief. Consumed by trySave and
// the ai trySaveVs helper.
inline int effectiveSaveLevel(int level, bool nonIntelligent,
                              int saveCategory) {
    if (level < 1) level = 1;
    if (nonIntelligent &&
        saveCategory != (int)rules::SAVE_DEATH_POISON)
        return (level + 1) / 2;
    return level;
}

// Per-target outcome of one spell.
struct TargetResult {
    bool   affected   = false;   // spell touched this target at all
    bool   saveMade   = false;
    bool   resisted   = false;   // magic resistance blocked it
    int    damage     = 0;       // hp lost (negative for healing)
    StatusEffect status;
    char   note[64] = "";        // human-readable line for the log
};

struct SpellCastResult {
    std::vector<TargetResult> perTarget;
};

// ----------------------------------------------------------------------------
// Resolve a spell cast at casterLevel against the given targets.
// The caller decides who is in the area / multi-target set - this
// engine only resolves per target.
// ----------------------------------------------------------------------------
SpellCastResult resolveSpell(Dice& dice, spells::SpellId id,
                             int casterLevel,
                             const std::vector<TargetDesc>& targets);

// ----------------------------------------------------------------------------
// Damage dice helper: 1d6 per caster level for fireball/lightning,
// capped at 10 dice (PHB). Cure spells: 1d8 + 1/level, capped 8.
// ----------------------------------------------------------------------------
int rollDamage(Dice& dice, const spells::SpellDef& s, int casterLevel);
int rollHealing(Dice& dice, const spells::SpellDef& s, int casterLevel);

// ----------------------------------------------------------------------------
// Status tick: caller applies each round; decrements and expires.
// Returns true while the status is still active.
// ----------------------------------------------------------------------------
bool tickStatus(StatusEffect& st);

} // namespace spelleffects