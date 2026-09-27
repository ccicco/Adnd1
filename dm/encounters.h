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
#include "../rules/dice.h"

#include <string>
#include <vector>

namespace dm {

struct DungeonEncounter {
    std::string key;     // empty = no encounter
    int count = 0;
    int headsLo = 0, headsHi = 0;  // hydra: roll per specimen
    int ageLo = 0, ageHi = 0;      // dragon age bracket 1-8, per specimen
};

int monsterLevelFor(int dungeonLevel, int d20);

DungeonEncounter rollDungeonEncounter(
    const monsters::MonsterRegistry& reg, rules::Dice& dice,
    int d20, int pctile, int pctile2, int dungeonLevel);

std::vector<std::string> encounterKeys(
    const monsters::MonsterRegistry& reg, int dungeonLevel);

} // namespace dm
