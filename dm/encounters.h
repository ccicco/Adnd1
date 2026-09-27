// ============================================================================
// Adnd1 — dm/encounters.h
// R52: DMG Appendix C dungeon encounter tables (Premium reprint
// p.174-179; OCR-verified against the uploaded DMG).
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
// party out to nine members.
CharacterParty rollCharacterParty(rules::Dice& dice,
                                  int dungeonLevel, int monsterLevel);

} // namespace dm
