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

// R62: NPC race fiction — the DMG p.192 race check (printed
// for city/town asterisked character types; applied here to
// Character Subtable parties as the engine's NPC-race source).
// Fiction-only: no stat adjustments, but class contradictions
// re-roll per the 1e class/race allowances (gnome magic-users
// read as illusionists, the closest-approximation convention).
enum NpcRace { RACE_HUMAN = 0, RACE_DWARF, RACE_ELF, RACE_GNOME,
               RACE_HALF_ELF, RACE_HALFLING, RACE_HALF_ORC };

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
    int  race = RACE_HUMAN;   // R62: NpcRace, fiction-only
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

// R62: the p.192 race-check adjective for fiction strings
// ("" for human / mixed parties): "dwarven ", "elven ", ...
const char* npcRaceAdjective(int race);

// R62: roll one NPC's race per the p.192 bands (01-08 dwarven,
// 09-13 elven, 14-15 gnomish, 16-23 half-elven, 24-25
// halfling, 26-30 half-orc, 31-00 human), re-rolling class
// contradictions (24 attempts, then human).
int rollNpcRace(rules::Dice& dice, int classIndex);

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

// R63: DMG Appendix C outdoor (wilderness) encounter tables
// (Premium reprint p.182-191; OCR-verified against the uploaded
// DMG). Eight climate tables, each across eight terrain columns,
// with eleven terrain-column subtables resolved on the second
// percentile (plus the tropical single-column Sphinx Subtable
// and the pick-sets documented in encounters.cpp). Counts come
// from the registry's noAppearing fields — the DMG prints no
// number columns for the wilderness tables. The Men Subtable's
// Character row resolves as a wilderness character party of
// levels 7-10 (DMG p.187 special note): rollCharacterParty
// (dice, 8, 8). No appstate wiring yet — the game has no
// overland travel — matching the R60 underwater tables.
enum OutdoorTerrain {
    T_PLAIN = 0, T_SCRUB, T_FOREST, T_ROUGH,
    T_DESERT, T_HILLS, T_MOUNTAINS, T_MARSH
};

enum OutdoorClime {
    OC_ARCTIC = 0, OC_SUB_ARCTIC,
    OC_TEMPERATE_WILD, OC_TEMPERATE_INHABITED,
    OC_FAERIE, OC_PLEISTOCENE, OC_DINOSAUR_AGE, OC_TROPICAL
};

DungeonEncounter rollOutdoorEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2,
    OutdoorClime clime, OutdoorTerrain terrain);

// Every registry key the climate/terrain column can produce —
// the regtest-style companion of rollOutdoorEncounter.
std::vector<std::string> outdoorEncounterKeys(
    const monsters::MonsterRegistry& reg,
    OutdoorClime clime, OutdoorTerrain terrain);


// R64: DMG Appendix C CITY/TOWN ENCOUNTER MATRIX (Premium
// reprint p.190-192; OCR-verified against the uploaded DMG).
// One matrix, two percentile columns (daytime / nighttime).
// Asterisked types roll the p.191 race check (rollNpcRace,
// R62); classed and service encounters resolve as character
// parties built to the p.191-192 explanations with printed
// level ranges; civilian fictions carry printed counts
// (their flavor subtables are fiction the engine does not
// model, documented in encounters.cpp). Numbers are the
// printed city numbers, not the registry's wilderness-scale
// noAppearing. City NPCs of 1st level or higher roll the
// p.192 CHANCE PER LEVEL FOR MAGIC ITEM table. No appstate
// wiring — the game has no city/town play yet (R60/R63
// precedent).
enum CityTime { CITY_DAY = 0, CITY_NIGHT };

DungeonEncounter rollCityEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2, CityTime time);

// Every result key the matrix can produce — registry keys for
// the monsters, fiction keys for civilians, party-type keys
// for the classed and service encounters. The regtest-style
// companion of rollCityEncounter.
std::vector<std::string> cityEncounterKeys(
    const monsters::MonsterRegistry& reg);


// R65: DMG Appendix C ASTRAL & ETHEREAL encounter tables
// (Premium reprint p.181; OCR-verified against the uploaded
// DMG). Both tables print a Numbers column — counts come
// from the table, not the registry. The (*) footnote
// creatures (basilisk, cockatrice, gorgon, medusa) apply
// only when the encounter allows effect to extend from the
// Prime Material Plane — gated on primeAdjacent, re-rolled
// otherwise. Demon/devil tiers and the AC-variant titans
// resolve as pick-sets on the second percentile; "Human
// traveller" resolves as the (**) modified Human Subtable
// party (rollPlanarTravellerParty, defined in the .cpp).
// The Psychic Wind / Ether Cyclone tables are transcribed
// as verbatim result structs — journey fiction only until
// the engine has planar travel (R60/R63 no-wiring
// precedent).
enum PlanarBody { PB_ASTRAL = 0, PB_ETHEREAL };

DungeonEncounter rollPlanarEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2,
    PlanarBody body, bool primeAdjacent);

// Every result key the table can produce — the regtest-style
// companion of rollPlanarEncounter.
std::vector<std::string> planarEncounterKeys(
    const monsters::MonsterRegistry& reg, PlanarBody body);

// Psychic Wind (astral): d20 per the p.181 table. saveMade is
// the party's saving throw versus magic, the caller's roll.
enum class PsychicWindEffect {
    Slowed, LostReturn, OffCourse, Storm
};
struct PsychicWindResult {
    PsychicWindEffect effect;
    int days;             // LostReturn / Storm success
    bool cordBroken;      // Storm save failure (death)
};
PsychicWindResult rollPsychicWind(rules::Dice& dice, int d20,
                                  bool saveMade);

// Ether Cyclone (ethereal): d20 per the p.181 table.
enum class EtherCycloneEffect {
    BlownAbout, DifferentPlane, LostNewPlane, StormAstral
};
struct EtherCycloneResult {
    EtherCycloneEffect effect;
    int days;
    bool blownToAstral;   // Storm save failure
};
EtherCycloneResult rollEtherCyclone(rules::Dice& dice, int d20,
                                    bool saveMade);


} // namespace dm
