// ============================================================================
// Adnd1 — dm/encounters.h
// R52: DMG Appendix C dungeon encounter tables (Premium reprint
// p.174-179; OCR-verified against the uploaded DMG).
//
// R58: reaction rolls for Character Subtable parties (DMG p.63
// Encounter Reactions + p.176 Confrontation).
//
// Roll chain (initial dice passed in for determinism):
//   d20 -> Determination Matrix -> Monster Level I-X
//   percentile -> level table row
//   2nd percentile -> subtable resolution (Human / Dragon / elemental)
//
// Unimplemented rows re-roll per the DMG's own advice: Character
// Subtable parties (classed NPCs = R53), mezzodaemon / nycadaemon.
// ============================================================================

#pragma once

#include "../monsters/MonsterRegistry.h"
#include "../rules/classes.h"
#include "../rules/dice.h"

#include <string>
#include <vector>

namespace dm {

// R53: one member of a Character Subtable party (DMG p.176).
// The engine carries four classes; unsupported professions map
// per the DMG's "closest approximation" advice (druid->cleric,
// paladin/ranger->fighter, illusionist->magic-user, assassin->
// thief, monk/bard-> fighter or thief). level 0 = man-at-arms.
struct PartyMember {
    int  classIndex = -1;   // rules::CharClass
    int  level      = 0;    // 0 = 0-level man-at-arms
    bool henchman   = false;   // classed follower (Dungeon L4+)
    bool manAtArms  = false;   // 0-level retainer (Dungeon L1-3)
    // R55: DMG p.176-177 party magic items. Only the outcomes the
    // engine models are carried; potions/scrolls/rings and other
    // unmodeled devices roll as no mechanical effect (the item
    // exists in the fiction but does not touch combat here).
    int  wpnPlus = 0;    // melee weapon enchantment
    int  rngPlus = 0;    // missile enchantment (arrows/bolts)
    int  armPlus = 0;    // armor enchantment
    int  shdPlus = 0;    // shield enchantment
};

struct CharacterParty {
    std::vector<PartyMember> members;   // characters, then followers
    bool empty() const { return members.empty(); }
    int  size()  const { return (int)members.size(); }
};

struct DungeonEncounter {
    std::string key;     // empty = no encounter
    int count = 0;
    int headsLo = 0, headsHi = 0;  // hydra: roll per specimen
    int ageLo = 0, ageHi = 0;      // dragon age bracket 1-8, per specimen
    // R53: Character Subtable party (Human Subtable 46-00 and the
    // level tables' "Character" rows). count is the party size.
    bool isParty = false;
    CharacterParty party;
};

int monsterLevelFor(int dungeonLevel, int d20);

DungeonEncounter rollDungeonEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int d20, int pctile, int pctile2, int dungeonLevel);

std::vector<std::string> encounterKeys(
    const monsters::MonsterRegistry& reg, int dungeonLevel);

// R53: roll a Character Subtable party per DMG p.176: d4+1
// characters (profession by subtable, contradictions and
// per-profession maxima ignored per the book), levels from the
// dungeon/monster level (through 4th) or d6+6 adjusted toward
// the dungeon level, then men-at-arms (levels 1-3) or classed
// henchmen at 1/3 the master's level (levels 4+) rounding the
// party out to nine members. R55: each character and henchman
// then rolls magic items on the DMG p.176-177 level-chance
// ladder (Table I-IV; implementable pluses only).
CharacterParty rollCharacterParty(rules::Dice& dice,
                                  int dungeonLevel, int monsterLevel);

// R58: DMG p.63 Encounter Reactions applied to a Character
// Subtable party per the p.176 Confrontation paragraph — the
// strangers react before steel is drawn. chaAdj is the spokesman's
// Charisma reaction adjustment (the engine's best-living-Cha
// convention, same as henchman hiring); npcWeaker shifts the score
// up 10 — "a character party feeling itself weak ... will
// certainly attempt to avoid, negotiate, or ... bluff their way
// out of actual combat" (p.176).
enum class PartyReaction {
    ViolentlyHostile,   // 01 or less-05: immediate attack
    Hostile,            // 06-25: hostile, immediate action
    UncertainNegative,  // 26-45: 55% prone toward negative
    Neutral,            // 46-55: uninterested
    UncertainPositive,  // 56-75: 55% prone toward positive
    Friendly,          // 76-95: friendly, immediate action
    Enthusiastic        // 96-00: enthusiastic acceptance
};

PartyReaction rollPartyReaction(rules::Dice& dice, int chaAdj,
                                bool npcWeaker);

// R60: DMG Appendix C underwater encounter tables (Premium
// reprint p.179-181; OCR-verified against the uploaded DMG).
// Fresh water (shallow to 50' / deep below 50'), large bodies of
// salt water (shallow to 100' / deep below 100'), plus the
// Dinosaur Subtable. The DMG prints no number columns — "The
// numbers of monsters encountered are those shown in MONSTER
// MANUAL" — so counts come from the registry's noAppearing
// fields. Footnotes (* cool only / ** warm only; dinichthys deep
// only) re-roll per the book's own "otherwise roll again".
enum class WaterBody  { FRESH, SALT };
enum class WaterDepth { SHALLOW, DEEP };
enum class WaterClime { COOL, WARM };

DungeonEncounter rollWaterEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2,
    WaterBody body, WaterDepth depth, WaterClime clime);

// Every registry key the table (in both climes) can produce —
// the regtest-style companion of rollWaterEncounter.
std::vector<std::string> waterEncounterKeys(
    const monsters::MonsterRegistry& reg,
    WaterBody body, WaterDepth depth);

} // namespace dm
