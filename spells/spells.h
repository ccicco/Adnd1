// ============================================================================
// Adnd1 - spells/spells.h
// Spell registry and spell-slot progressions. Data + slots only;
// resolution of effects is spelleffects/ (R14).
//
// Source: Players Handbook (2012 Premium reprint):
//   - MU spell list: Appendix (pp. 44-50 area, list pp. 44+)
//   - Cleric spell list: Appendix (pp. 53-56 area)
//   - Spell slot tables: class tables pp. 20-36
//   - Chance to learn: INT table p.10
// Values follow the PHB as recorded in project notes (verification
// debt - printed tables win when the PDF is re-uploaded).
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
    // --- R80: levels 4-6 (appended AFTER the legacy ids so saved
    //     knownSpells indices stay valid) ---
    MU_POLYMORPH_OTHER,
    MU_ICE_STORM,
    MU_FIRE_SHIELD,
    MU_CHARM_MONSTER,
    MU_CONE_OF_COLD,
    MU_TELEPORT,
    MU_HOLD_MONSTER,
    MU_DEATH_SPELL,
    MU_DISINTEGRATE,
    CL_CURE_CRITICAL_WOUNDS,
    CL_CAUSE_CRITICAL_WOUNDS,
    CL_NEUTRALIZE_POISON,
    CL_RAISE_DEAD,
    CL_INSECT_PLAGUE,
    CL_HEAL,
    // --- R129: the DMG p.14 caster-aging spells (levels
    //     7-9; appended ids keep saved knownSpells indices
    //     valid). TARGET_SELF rows: the aging rider treats
    //     the target as the caster (the book's semantics -
    //     the p.14 years land on the caster).
    MU_LIMITED_WISH,     // MU 7; caster ages 1 (p.14)
    MU_ALTER_REALITY,    // MU 7; caster ages 3 (p.14)
    MU_WISH,             // MU 9; caster ages 3 (p.14)
    MU_GATE,             // MU 9; caster ages 5 (p.14)
    CL_RESTORATION,      // CL 7; caster ages 2 (p.14)
    CL_RESURRECTION,     // CL 7; caster ages 3 (p.14)
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
// a given class level. R130 line-diffed the tables against the
// 1eonline.info PHB compilation (the class Table I and the SPELLS
// USABLE BY CLASS AND LEVEL appendix): MU printed rows run to L20,
// cleric to L29, spell levels 1-9 / 1-7 encoded; the R80 project-
// notes rows 7-12 were corrected to the printed values (rows 1-6
// matched). Beyond the printed rows the final row holds. The
// printed wisdom footnotes wired R192: the wisdom gates ride
// rules/wisdom.h and clericSpellSlotsWithWis (6th: Wis 17;
// 7th: Wis 18 - Wisdom Table I; the bonus spells and spell
// failure ride the same header).
// ----------------------------------------------------------------------------
int spellSlots(SpellClass sc, int classLevel, int spellLevel);

// ----------------------------------------------------------------------------
// R192: the wisdom wiring (Wisdom Tables I and II): cleric
// slots with the cumulative wisdom bonus (entitlement-
// gated), the high-circle wisdom gates, and the low-
// wisdom spell failure roll.
// ----------------------------------------------------------------------------
int clericBonusSpells(uint8_t wis, int spellLevel);
int clericSpellSlotsWithWis(int classLevel, int spellLevel,
                           uint8_t wis);
int clericSpellFailurePct(uint8_t wis);
bool rollClericSpellFailure(Dice& dice, uint8_t wis);

// ----------------------------------------------------------------------------
// Chance to learn a spell (PHB p.10 INT table): percent rolled on
// d100 when an MU first studies a new spell. Min INT 9 to learn any.
//   INT 9-10: 35%, 11-12: 45%, 13-14: 55%, 15: 65%, 16: 70%,
//   17: 85%, 18: 95%
// ----------------------------------------------------------------------------
int chanceToLearnPct(uint8_t int_);
bool rollChanceToLearn(Dice& dice, uint8_t int_);

// ----------------------------------------------------------------------------
// R115: the years a spell steals (DMG p.14 magical aging
// causes): a haste spell costs its recipient 1 year.
// R129: the caster-aged causes are in the registry and
// pinned - limited wish 1, restoration 2, resurrection 3,
// wish 3, alter reality 3, gate 5 - their rows are
// TARGET_SELF, so the aging rider's "target" IS the
// caster (the book's semantics; see ai/actor.cpp). The
// speed potion's 1 year remains the item layer's - found
// potions collapse into the healing stack today
// (documented engine limit, named in the gap report).
// ----------------------------------------------------------------------------
int magicalAgingYears(SpellId id);

// ----------------------------------------------------------------------------
// Maximum spell level castable (MU: INT gates; INT 11 = L2 spells,
// 14 = 4th... PHB p.10 minimums). Clerics cast by class level only.
// ----------------------------------------------------------------------------
int maxSpellLevelForInt(uint8_t int_);
int maxSpellLevelForClericLevel(int classLevel);

} // namespace spells