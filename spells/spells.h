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
    SPELL_DRUID,   // R228: the druid roster
    SPELL_ILLUSIONIST,   // R229: the illusionist roster
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
    // --- R228: the druid roster joins the registry (77
    //     spells, the printed alphabetical order within
    //     each level - the R182 roster order; appended ids
    //     keep saved knownSpells indices valid) ---
    DR_ANIMAL_FRIENDSHIP,   // druid 1
    DR_DETECT_MAGIC,        // druid 1
    DR_DETECT_SNARES_AND_PITS, // druid 1
    DR_ENTANGLE,            // druid 1
    DR_FAERIE_FIRE,         // druid 1
    DR_INVISIBILITY_TO_ANIMALS, // druid 1
    DR_LOCATE_ANIMALS,      // druid 1
    DR_PASS_WITHOUT_TRACE,  // druid 1
    DR_PREDICT_WEATHER,     // druid 1
    DR_PURIFY_WATER,        // druid 1
    DR_SHILLELAGH,          // druid 1
    DR_SPEAK_WITH_ANIMALS,  // druid 1
    DR_BARKSKIN,            // druid 2
    DR_CHARM_PERSON_OR_MAMMAL, // druid 2
    DR_CREATE_WATER,        // druid 2
    DR_CURE_LIGHT_WOUNDS,   // druid 2
    DR_FEIGN_DEATH,         // druid 2
    DR_FIRE_TRAP,           // druid 2
    DR_HEAT_METAL,          // druid 2
    DR_LOCATE_PLANTS,       // druid 2
    DR_OBSCUREMENT,         // druid 2
    DR_PRODUCE_FLAME,       // druid 2
    DR_TRIP,                // druid 2
    DR_WARP_WOOD,           // druid 2
    DR_CALL_LIGHTNING,      // druid 3
    DR_CURE_DISEASE,        // druid 3
    DR_HOLD_ANIMAL,         // druid 3
    DR_NEUTRALIZE_POISON,   // druid 3
    DR_PLANT_GROWTH,        // druid 3
    DR_PROTECTION_FROM_FIRE, // druid 3
    DR_PYROTECHNICS,        // druid 3
    DR_SNARE,               // druid 3
    DR_STONE_SHAPE,         // druid 3
    DR_SUMMON_INSECTS,      // druid 3
    DR_TREE,                // druid 3
    DR_WATER_BREATHING,     // druid 3
    DR_ANIMAL_SUMMONING_I,  // druid 4
    DR_CALL_WOODLAND_BEINGS, // druid 4
    DR_CONTROL_TEMPERATURE_10_RADIUS, // druid 4
    DR_CURE_SERIOUS_WOUNDS, // druid 4
    DR_DISPEL_MAGIC,        // druid 4
    DR_HALLUCINATORY_FOREST, // druid 4
    DR_HOLD_PLANT,          // druid 4
    DR_PLANT_DOOR,          // druid 4
    DR_PRODUCE_FIRE,        // druid 4
    DR_PROTECTION_FROM_LIGHTNING, // druid 4
    DR_REPEL_INSECTS,       // druid 4
    DR_SPEAK_WITH_PLANTS,   // druid 4
    DR_ANIMAL_GROWTH,       // druid 5
    DR_ANIMAL_SUMMONING_II, // druid 5
    DR_ANTI_PLANT_SHELL,    // druid 5
    DR_COMMUNE_WITH_NATURE, // druid 5
    DR_CONTROL_WINDS,       // druid 5
    DR_INSECT_PLAGUE,       // druid 5
    DR_WALL_OF_FIRE,        // druid 5
    DR_PASS_PLANT,          // druid 5
    DR_ANIMAL_SUMMONING_III, // druid 6
    DR_ANTI_ANIMAL_SHELL,   // druid 6
    DR_STICKS_TO_SNAKES,    // druid 6
    DR_CONJURE_FIRE_ELEMENTAL, // druid 6
    DR_TRANSMUTE_ROCK_TO_MUD, // druid 6
    DR_CURE_CRITICAL_WOUNDS, // druid 6
    DR_FEEBLEMIND,          // druid 6
    DR_TRANSPORT_VIA_PLANTS, // druid 6
    DR_TURN_WOOD,           // druid 6
    DR_WALL_OF_THORNS,      // druid 6
    DR_WEATHER_SUMMONING,   // druid 6
    DR_CONFUSION,           // druid 6
    DR_ANIMATE_ROCK,        // druid 7
    DR_CONJURE_EARTH_ELEMENTAL, // druid 7
    DR_CONTROL_WEATHER,     // druid 7
    DR_CHARIOT_OF_SUSTARRE, // druid 7
    DR_CREEPING_DOOM,       // druid 7
    DR_FINGER_OF_DEATH,     // druid 7
    DR_FIRE_STORM,          // druid 7
    DR_REINCARNATE,         // druid 7
    DR_TRANSMUTE_METAL_TO_WOOD, // druid 7
    IL_AUDIBLE_GLAMER,          // illusionist 1
    IL_DETECT_INVISIBILITY,     // illusionist 1
    IL_CHANGE_SELF,             // illusionist 1
    IL_GAZE_REFLECTION,         // illusionist 1
    IL_HYPNOTISM,               // illusionist 1
    IL_LIGHT,                   // illusionist 1
    IL_PHANTASMAL_FORCE,        // illusionist 1
    IL_WALL_OF_FOG,             // illusionist 1
    IL_BLINDNESS,               // illusionist 2
    IL_BLUR,                    // illusionist 2
    IL_DEAFNESS,                // illusionist 2
    IL_DETECT_MAGIC,            // illusionist 2
    IL_FOG_CLOUD,               // illusionist 2
    IL_HYPNOTIC_PATTERN,        // illusionist 2
    IL_IMPROVED_PHANTASMAL_FORCE, // illusionist 2
    IL_INVISIBILITY,            // illusionist 2
    IL_DISPEL_ILLUSION,         // illusionist 2
    IL_MAGIC_MOUTH,             // illusionist 2
    IL_FEAR,                    // illusionist 2
    IL_MIRROR_IMAGE,            // illusionist 2
    IL_HALLUCINATORY_TERRAIN,   // illusionist 2
    IL_MISDIRECTION,            // illusionist 2
    IL_ILLUSIONARY_SCRIPT,      // illusionist 2
    IL_VENTRILOQUISM,           // illusionist 2
    IL_INVISIBILITY_10_RADIUS,  // illusionist 3
    IL_CONTINUAL_DARKNESS,      // illusionist 3
    IL_CONTINUAL_LIGHT,         // illusionist 3
    IL_NON_DETECTION,           // illusionist 3
    IL_EMOTION,                 // illusionist 3
    IL_PARALYZATION,            // illusionist 3
    IL_ROPE_TRICK,              // illusionist 3
    IL_SPECTRAL_FORCE,          // illusionist 3
    IL_IMPROVED_INVISIBILITY,   // illusionist 3
    IL_SUGGESTION,              // illusionist 3
    IL_MASSMORPH,               // illusionist 3
    IL_CONFUSION,               // illusionist 4
    IL_DISPEL_EXHAUSTION,       // illusionist 4
    IL_MINOR_CREATION,          // illusionist 4
    IL_PHANTASMAL_KILLER,       // illusionist 4
    IL_SHADOW_MONSTERS,         // illusionist 4
    IL_CHAOS,                   // illusionist 5
    IL_DEMI_SHADOW_MONSTERS,    // illusionist 5
    IL_MAJOR_CREATION,          // illusionist 5
    IL_MAZE,                    // illusionist 5
    IL_PROJECTED_IMAGE,         // illusionist 5
    IL_MASS_SUGGESTION,         // illusionist 5
    IL_SHADOW_DOOR,             // illusionist 5
    IL_PERMANENT_ILLUSION,      // illusionist 5
    IL_SHADOW_MAGIC,            // illusionist 5
    IL_PROGRAMMED_ILLUSION,     // illusionist 5
    IL_SUMMON_SHADOW,           // illusionist 5
    IL_SHADES,                  // illusionist 5
    IL_CONJURE_ANIMALS,         // illusionist 6
    IL_TRUE_SIGHT,              // illusionist 6
    IL_DEMI_SHADOW_MAGIC,       // illusionist 6
    IL_VEIL,                    // illusionist 6
    IL_ALTER_REALITY,           // illusionist 7
    IL_ASTRAL_SPELL,            // illusionist 7
    IL_PRISMATIC_SPRAY,         // illusionist 7
    IL_PRISMATIC_WALL,          // illusionist 7
    IL_VISION,                  // illusionist 7
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
// Chance to learn a spell (PHB p.10 INTELLIGENCE TABLE II,
// repinned R196): percent rolled on d100 when an MU first
// studies a new spell. Min INT 9 to learn any.
//   INT 9: 35%, 10-12: 45%, 13-14: 55%, 15-16: 65%,
//   17: 75%, 18: 85%, 19+: 95% (the printed or-more row)
// ----------------------------------------------------------------------------
int chanceToLearnPct(uint8_t int_);
bool rollChanceToLearn(Dice& dice, uint8_t int_);

// ----------------------------------------------------------------------------
// R196: the INTELLIGENCE TABLE II spells-per-level columns -
// which and how many of each group of spells (by level) the
// MU can learn. All pins as -1 (unlimited). The printed
// note: successive level groups are checked only when the
// character reaches a level at which the group is usable.
// ----------------------------------------------------------------------------
int minSpellsPerLevel(uint8_t int_);
int maxSpellsPerLevel(uint8_t int_);

// ----------------------------------------------------------------------------
// R197: the per-spell mental-form flag. The printed Wisdom
// Table I note: the magical defense adjustment applies
// only to mental attack forms involving will force -
// beguiling, charming, fear, hypnosis, illusion, magic
// jarring, mass charming, phantasmal forces, possession,
// rulership, suggestion, telepathic attack.
// spellIsMentalForm is the per-spell engine data;
// spellSaveModWis assembles the WIS magical defense
// adjustment for those spells, 0 on everything else -
// the save rolls stay caller-assembled (rules/saves.h).
// Registry rows flagged: charm person, charm monster.
// ----------------------------------------------------------------------------
bool spellIsMentalForm(SpellId id);
int  spellSaveModWis(SpellId id, uint8_t wis);

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