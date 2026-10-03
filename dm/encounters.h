// ============================================================================
// Adnd1 - dm/encounters.h
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
#include "treasure.h"   // R74: Hoard (encounters::rollEncounter)

#include <string>
#include <vector>

namespace dm {

// R62: NPC race fiction - the DMG p.192 race check (printed
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
// Subtable party per the p.176 Confrontation paragraph - the
// strangers react before steel is drawn. chaAdj is the spokesman's
// Charisma reaction adjustment (the engine's best-living-Cha
// convention, same as henchman hiring); npcWeaker shifts the score
// up 10 - "a character party feeling itself weak ... will
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
// Dinosaur Subtable. The DMG prints no number columns - "The
// numbers of monsters encountered are those shown in MONSTER
// MANUAL" - so counts come from the registry's noAppearing
// fields. Footnotes (* cool only / ** warm only; dinichthys deep
// only) re-roll per the book's own "otherwise roll again".
// R70 wired the sea loop here; since R127 the sea travel
// loop rolls the p.190 WATERBORNE tables instead (see the
// R127 block above) - the underwater set stays pinned
// data for the future diving layer.
enum class WaterBody  { FRESH, SALT };
enum class WaterDepth { SHALLOW, DEEP };
enum class WaterClime { COOL, WARM };

DungeonEncounter rollWaterEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2,
    WaterBody body, WaterDepth depth, WaterClime clime);

// Every registry key the table (in both climes) can produce -
// the regtest-style companion of rollWaterEncounter.
std::vector<std::string> waterEncounterKeys(
    const monsters::MonsterRegistry& reg,
    WaterBody body, WaterDepth depth);

// R127: DMG Appendix C WATERBORNE encounter tables (Premium
// reprint p.190; line-diffed against the 1eonline.info
// Appendix C compilation - the surface-travel companion of
// the R60 underwater set, which the compilation omits and
// which stays on its R60 uploaded-DMG verification). Four
// tables: Fresh Water small body / large body, Salt Water
// shallow (coastal) / deep; the fresh-water body size rides
// the depth enum (SHALLOW = small body, DEEP = large body -
// the engine's documented selector). Dinosaur rows resolve
// on the shared p.190 Dinosaur Subtable against the second
// percentile. The same footnote clime gates as R60 (* cool
// only / ** warm only) re-roll per the book's own
// "otherwise roll again"; the fresh-water Dinosaur warm
// gate rides the parent row (the R60 convention). Counts
// come from the registry's noAppearing fields (the book
// prints no number columns for the waterborne tables
// either). Substitutions documented in-row: Koalinth ->
// hobgoblin, Kopoacinth -> gargoyle, Lacedon -> ghoul,
// Elf (aquatic) -> elf (R60 conventions), Pirate ->
// buccaneer and pirate (tribesman with small craft) ->
// caveman (no pirate record; the repo's tribesman
// convention), Mermaid -> merman (the MM Merman entry
// covers mermaids); whales follow the R61 size mapping.
// WIRED SINCE R127 - the sea travel loop rolls the
// salt-water waterborne tables (see game/appstate.h, R70;
// the R60 underwater set is pinned data for the future
// diving layer).
DungeonEncounter rollWaterborneEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2,
    WaterBody body, WaterDepth depth, WaterClime clime);

// Every registry key the waterborne table (in both climes)
// can produce - the regtest-style companion.
std::vector<std::string> waterborneEncounterKeys(
    const monsters::MonsterRegistry& reg,
    WaterBody body, WaterDepth depth);

// R127: the printed band edges behind the waterborne tables
// and the p.190 Dinosaur Subtable (shared with the R60
// underwater set) - the regtest line-diff audit walks them.
// flags carries the footnote gates: 1 = cool waters only,
// 2 = warm waters only, 4 = deep water only.
struct WaterborneBand {
    std::string key;
    int lo;
    int hi;
    int flags;
};
std::vector<WaterborneBand> waterborneBands(
    WaterBody body, WaterDepth depth);
std::vector<WaterborneBand> dinosaurSubBands();

// R63: DMG Appendix C outdoor (wilderness) encounter tables
// (Premium reprint p.182-191; OCR-verified against the uploaded
// DMG). Eight climate tables, each across eight terrain columns,
// with eleven terrain-column subtables resolved on the second
// percentile (plus the tropical single-column Sphinx Subtable
// and the pick-sets documented in encounters.cpp). Counts come
// from the registry's noAppearing fields - the DMG prints no
// number columns for the wilderness tables. The Men Subtable's
// Character row resolves as a wilderness character party of
// levels 7-10 (DMG p.187 special note): rollCharacterParty
// (dice, 8, 8). WIRED SINCE R68 - the overland travel loop
// rolls these tables (see game/appstate.h, R68/R70).
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

// Every registry key the climate/terrain column can produce -
// the regtest-style companion of rollOutdoorEncounter.
std::vector<std::string> outdoorEncounterKeys(
    const monsters::MonsterRegistry& reg,
    OutdoorClime clime, OutdoorTerrain terrain);

// R126: the printed band edges behind outdoorEncounterKeys -
// the regtest line-diff audit walks them (the R122 shape
// applied to the R63 outdoor tables). One OutdoorBand per
// printed band, low-ascending; a climate/terrain column the
// climate does not serve comes back empty (the Arctic serves
// Plain/Rough/Mountains only, etc.). outdoorSubBands takes a
// SUB_* pseudo-key and its terrain column; the tropical
// Sphinx Subtable is the p.189 single-column footnote and
// reports under SUB_SPHINX_T for any terrain.
struct OutdoorBand {
    std::string key;
    int lo;
    int hi;
};
std::vector<OutdoorBand> outdoorBands(
    OutdoorClime clime, OutdoorTerrain terrain);
std::vector<OutdoorBand> outdoorSubBands(
    const std::string& subKey, OutdoorTerrain terrain);


// R64: DMG Appendix C CITY/TOWN ENCOUNTER MATRIX (Premium
// reprint p.190-192; OCR-verified against the uploaded DMG).
// One matrix, two percentile columns (daytime / nighttime).
// Asterisked types roll the p.191 race check (rollNpcRace,
// R62); classed and service encounters resolve as character
// parties built to the p.191-192 explanations with printed
// level ranges; civilian fictions carry printed counts
// (their flavor subtables are fiction the engine models
// only in part: the drunk identity and harlot type tables
// are pinned R146 - cityDrunkKind / cityHarlotKind; the
// rest stay unmodeled, documented in encounters.cpp).
// Numbers are the
// printed city numbers, not the registry's wilderness-scale
// noAppearing. City NPCs of 1st level or higher roll the
// p.192 CHANCE PER LEVEL FOR MAGIC ITEM table. WIRED SINCE
// R70 - the city streets excursion loop rolls this matrix
// (see game/appstate.h, R70).
enum CityTime { CITY_DAY = 0, CITY_NIGHT };

DungeonEncounter rollCityEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2, CityTime time);

// Every result key the matrix can produce - registry keys for
// the monsters, fiction keys for civilians, party-type keys
// for the classed and service encounters. The regtest-style
// companion of rollCityEncounter.
std::vector<std::string> cityEncounterKeys(
    const monsters::MonsterRegistry& reg);

// R146: the two flavor subtables R64 named as unmodeled -
// the p.191 drunk identity table ("the character(s) found
// drunk should be diced for") and the p.192 harlot type
// table - transcribed from the 1eonline.info compilation
// (the repo-trusted source; the DMG re-upload's OCR debt
// stands). Fiction-only descriptors for the city flavor
// strings: 1-100 percentile, 00 reading as 100.
const char* cityDrunkKind(int pctile);
const char* cityHarlotKind(int pctile);


// R65: DMG Appendix C ASTRAL & ETHEREAL encounter tables
// (Premium reprint p.181; OCR-verified against the uploaded
// DMG). Both tables print a Numbers column - counts come
// from the table, not the registry. The (*) footnote
// creatures (basilisk, cockatrice, gorgon, medusa) apply
// only when the encounter allows effect to extend from the
// Prime Material Plane - gated on primeAdjacent, re-rolled
// otherwise. Demon/devil tiers and the AC-variant titans
// resolve as pick-sets on the second percentile; "Human
// traveller" resolves as the (**) modified Human Subtable
// party (rollPlanarTravellerParty, defined in the .cpp).
// The Psychic Wind / Ether Cyclone tables are transcribed
// as verbatim result structs - journey fiction only until
// the engine has planar travel (R60/R63 no-wiring
// precedent).
enum PlanarBody { PB_ASTRAL = 0, PB_ETHEREAL };

DungeonEncounter rollPlanarEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2,
    PlanarBody body, bool primeAdjacent);

// Every result key the table can produce - the regtest-style
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


// R66: DMG Appendix C PSIONIC ENCOUNTER TABLE (Premium reprint
// p.182; OCR-verified against the uploaded DMG). Used when the
// party has employed psionic powers (or spells resembling
// them) - the 1-in-4 gate is the caller's; the printed
// spells list is implemented in spellResemblesPsionicPower.
// Counts come from the printed Numbers column (yellow mold's
// dash -> registry noAppearing). The demon/devil rows pick on
// the second percentile (R65 sets); the Men row resolves as a
// Character Subtable party. No appstate wiring.
DungeonEncounter rollPsionicEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int pctile, int pctile2);

// Every result key the table can produce - the regtest-style
// companion of rollPsionicEncounter.
std::vector<std::string> psionicEncounterKeys(
    const monsters::MonsterRegistry& reg);

// The printed "Spells Resembling Psionic Powers" list
// (p.182): case-insensitive full-name match, with the
// "(any)" families (charm, cure, detect, invisibility,
// polymorph, tele-) matched by leading word.
bool spellResemblesPsionicPower(const std::string& name);


// R67: DMG Appendix C PATROLS and CASTLE/FORTRESS tables
// (Premium reprint p.182-183; OCR-verified against the
// uploaded DMG). Inhabited-area encounters are patrols (5 in
// 20); uninhabited-area encounters can discover strongholds
// (1 in 20) - both gates are the caller's. Castle Table I
// gives size class and type; Table II gives inhabitants per
// size (the deserted-monster case rolls the OUTDOOR
// encounter tables, ignoring men - the R63 caller's tool);
// Sub-Table II.A the human occupants; Sub-Table II.B the
// master's class and level (OCR overlap Assassin/Monk
// corrected to 94-96 / 97-99 / 00, documented). Henchmen
// 2-5, levels and magic items per the Character Subtable
// (R53/R55/R62 conventions). Artillery per fortress type is
// transcribed verbatim (rows grouped, mapping documented).
// Detection maps the standard surprise die (1d6). Garrison
// equipment and reaction fiction are the caller's,
// documented in the .cpp. WIRED SINCE R68 - the stronghold
// discovery flow calls these builders (game/appstate.h).
enum CastleSize { CASTLE_SMALL = 0, CASTLE_MEDIUM, CASTLE_LARGE };

enum CastleInhabitants {
    CASTLE_TOTALLY_DESERTED = 0,
    CASTLE_DESERTED_MONSTER,   // roll the outdoor tables, ignore men
    CASTLE_HUMANS,             // bandits / berserkers / dervishes
    CASTLE_CHARACTER_TYPES    // master + henchmen stronghold
};

struct CastleType {
    CastleSize size;
    const char* type;    // e.g. "tower", "concentric castle"
};

struct CastleArtillery {
    int ballistae;        // ballistae & scorpions
    int lightCatapults;
    int oilCauldrons;
};

enum CastleAwareness {
    CASTLE_UNDETECTED = 0,
    CASTLE_OCCUPANTS_AWARE,      // surprised on 1
    CASTLE_OCCUPANTS_OUTSIDE     // surprised on 2
};

CastleType rollCastleType(int pctile);   // Table I
CastleInhabitants castleInhabitants(int pctile, CastleSize size);   // Table II

// Sub-Table II.A: "bandit", "berserker" or "dervish"
// (brigand -> bandit, the R63 substitution, documented).
const char* castleHumansType(int pctile);

// "Numbers ... are given in the MONSTER MANUAL under the
// heading of MEN" - registry noAppearing (R60 convention).
int castleHumansCount(const monsters::MonsterRegistry& reg,
                      rules::Dice& dice, const char* key);

// Sub-Table II.B: the stronghold's master (R62 race, R55
// magic items).
PartyMember rollCastleMaster(rules::Dice& dice, int pctile);

// 2-5 henchmen, levels per the Character Subtable (R53
// henchmanLevelFor), R55 magic items, R62 race.
CharacterParty rollCastleHenchmen(rules::Dice& dice,
                                  const PartyMember& master);

// Artillery per the printed table; the nine castle types map
// onto the book's eight grouped rows (documented).
CastleArtillery castleArtillery(const CastleType& castle);

// Detection: the standard surprise die (1d6) - 1 = occupants
// aware, 2 = aware and outside, 3+ = undetected.
CastleAwareness castleAwareness(int surpriseDie);

// The p.182 patrol: fighter (or ranger) leader 6-8,
// lieutenant 4-5, sergeant 2-3, 3-4 1st-level men, 13-24
// men-at-arms, cleric 6-7 (40%) / magic-user 5-8 (60%).
CharacterParty rollPatrol(rules::Dice& dice, bool rangerLeader);



// ==== R74: MM-frequency random encounter generator (merged R78) ====
namespace encounters {

// MM FREQUENCY string -> selection weight. Higher = met more often.
// Unknown/blank strings weight as "uncommon" (defensive: new data
// must not crash the picker).
int frequencyWeight(const std::string& frequency);

struct Encounter {
    const monsters::MonsterDef* def = nullptr; // picked monster (owned by
                                               // the registry - do not free)
    int  count = 0;             // creatures actually appearing (after cap)
    int  rawCount = 0;          // NO. APPEARING roll before the cap
    bool clamped = false;       // rawCount exceeded the cap
    bool inLair = false;        // LAIR % roll succeeded

    treasure::Hoard lairHoard;   // lair letters (inLair only)
    treasure::Hoard carried;     // individual letters x appearing count
    int  treasureRolls = 0;      // letters rolled (audit aid)
};

struct EncounterOptions {
    int  countCap = 50;          // clamp on NO. APPEARING (spawn sanity;
                                 // goblins say "40-400" - a 400-orc spawn
                                 // on one screen is a designer problem)
    bool allowUnique = false;    // Tiamat, Bahamut & friends stay out of
                                 // random rotation unless asked for
    bool rollTreasure = true;    // fill lairHoard/carried
    std::string alignmentFilter; // "" = any; else alignment prefix,
                                 // e.g. "chaotic", "lawful_good"
};

bool rollEncounter(const monsters::MonsterRegistry& reg,
                   rules::Dice& dice,
                   const EncounterOptions& opt,
                   Encounter& out);

} // namespace encounters

} // namespace dm
