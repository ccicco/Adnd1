// ============================================================================
// Adnd1 — spells/spells.h
// Spell registry and spell-slot progressions. Data + slots only;
// resolution of effects is spelleffects/ (R14).
//
// Source: Players Handbook (2012 Premium reprint):
//   - MU spell list: Appendix (pp. 44-50 area, list pp. 44+)
//   - Cleric spell list: Appendix (pp. 53-56 area)
//   - Spell slot tables: class tables pp. 20-36
//   - Chance to learn: INT table p.10
// Values follow the PHB as recorded in project notes (verification
// debt — printed tables win when the PDF is re-uploaded).
// ============================================================================

#pragma once

#include "../rules/dice.h"

#include <cstdint>

namespace spells {

using rules::Dice;

// ----------------------------------------------------------------------------
// Spell identity
// ----------------------------------------------------------------------------
enum SpellClass : int {
    SPELL_MU = 0,
    SPELL_CLERIC,
    SPELL_CLASS_COUNT
};

enum SpellId : int {
    // --- magic-user (levels 1-3 encoded for now; higher levels
    //     arrive when high-level play needs them) ---
    MU_SLEEP = 0,
    MU_MAGIC_MISSILE,
    MU_SHIELD,
    MU_LIGHT,
    MU_DETECT_MAGIC,
    MU_CHARM_PERSON,
    MU_FLOATING_DISC,
    MU_HOLD_PORTAL,
    MU_INVISIBILITY,
    MU_MIRROR_IMAGE,
    MU_WEB,
    MU_STRENGTH,
    MU_INVISIBILITY_10,
    MU_FIREBALL,
    MU_LIGHTNING_BOLT,
    MU_FLY,
    MU_HASTE,
    MU_DISPEL_MAGIC,
    // --- cleric (levels 1-3) ---
    CL_CURE_LIGHT_WOUNDS,
    CL_CAUSE_LIGHT_WOUNDS,
    CL_DETECT_MAGIC,
    CL_LIGHT,
    CL_PROTECTION_FROM_EVIL,
    CL_PURIFY_FOOD,
    CL_RESIST_COLD,
    CL_BLIGHT,
    CL_HOLD_PERSON,
    CL_SILENCE_15,
    CL_SLOW_POISON,
    CL_CURE_SERIOUS_WOUNDS,
    CL_CAUSE_SERIOUS_WOUNDS,
    CL_DISPEL_MAGIC,
    CL_PRAYER,
    SPELL_COUNT
};

// Target shape: what the effect engine needs to aim.
enum SpellTarget : int {
    TARGET_SELF = 0,
    TARGET_CREATURE,      // single creature (with save)
    TARGET_AREA,          // area of effect, many creatures
    TARGET_CREATURES,     // up to N creatures (e.g. sleep)
    TARGET_SPECIAL        // portal/object/etc.
};

struct SpellDef {
    const char*   name;
    SpellClass    sclass;
    int           level;          // spell level 1-3
    int           castingTime;    // segments (feeds R7 scheduler)
    int           rangeTens;      // tens of feet (0 = touch/self)
    int           durationRounds; // rounds; 0 = instantaneous
    int           saveCategory;   // rules/SaveCategory, or -1 none
    SpellTarget   target;
    int           aoeTens;        // radius in tens of ft (area only)
    int           dmgCount;       // damage dice (level-scaled)
    int           dmgSides;
    bool          reversible;     // cleric reversibles
};

const SpellDef& spell(SpellId id);
int spellLevel(SpellId id);
SpellClass spellClass(SpellId id);

// ----------------------------------------------------------------------------
// Spell slots (PHB class tables): usable spells per spell level at
// a given class level. Rows to name level; beyond, max row repeats
// (1e: gained spells stop advancing — followers/strongholds take
// over; rebuild convention: hold at final row).
// ----------------------------------------------------------------------------
int spellSlots(SpellClass sc, int classLevel, int spellLevel);

// ----------------------------------------------------------------------------
// Chance to learn a spell (PHB p.10 INT table): percent rolled on
// d100 when an MU first studies a new spell. Min INT 9 to learn any.
//   INT 9-10: 35%, 11-12: 45%, 13-14: 55%, 15: 65%, 16: 70%,
//   17: 85%, 18: 95%
// ----------------------------------------------------------------------------
int chanceToLearnPct(uint8_t int_);
bool rollChanceToLearn(Dice& dice, uint8_t int_);

// ----------------------------------------------------------------------------
// Maximum spell level castable (MU: INT gates; INT 11 = L2 spells,
// 14 = 4th... PHB p.10 minimums). Clerics cast by class level only.
// ----------------------------------------------------------------------------
int maxSpellLevelForInt(uint8_t int_);
int maxSpellLevelForClericLevel(int classLevel);

} // namespace spells