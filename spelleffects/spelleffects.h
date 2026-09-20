// ============================================================================
// Adnd1 — spelleffects/spelleffects.h
// Spell resolution engine. Works on target DESCRIPTORS (hp, save
// bonuses, MR) so both characters and monsters plug in — no actor
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
    STATUS_COUNT
};

struct StatusEffect {
    StatusKind kind = STATUS_NONE;
    int        roundsRemaining = 0;
    int        magnitude = 0;    // e.g. shield AC bonus
};

const char* statusName(StatusKind s);

// ----------------------------------------------------------------------------
// Target descriptor: what the engine needs to resolve against.
//   hp / maxHp        current and max hit points
//   saveClass         0-3 (fighter/MU/cleric/thief matrix for target)
//   saveLevel         target's class level for the save table
//   saveBonus         flat modifier (WIS magic adj, rings, etc.)
//   magicResistPct    MR checked before anything else
//   isUndead          charm person etc. don't affect undead
//   isLarge           some effects differ vs large targets
// ----------------------------------------------------------------------------
struct TargetDesc {
    int hp = 10;
    int maxHp = 10;
    int saveClass   = 0;
    int saveLevel   = 1;
    int saveBonus   = 0;
    int magicResistPct = 0;
    bool isUndead = false;
    bool isLarge  = false;
};

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
// The caller decides who is in the area / multi-target set — this
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