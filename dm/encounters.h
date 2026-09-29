// ============================================================================
// Adnd1 — dm/encounters.h
// R74: random encounter generator — the consumer of the full bestiary
// (R72) and the treasure system (R71/73).
//
//   rollEncounter()  → pick a monster weighted by MM FREQUENCY, roll
//                      NO. APPEARING, roll LAIR %, and — if in the lair —
//                      roll the monster's lair treasure letters, plus
//                      individual treasure for the appearing count.
//
// Weights follow the spirit of DMG Appendix C (common meets you most).
// They are a house convention, deliberately exposed in one table:
// adjust dm::encounters::frequencyWeight() to taste.
// ============================================================================

#pragma once

#include "../monsters/MonsterRegistry.h"
#include "treasure.h"
#include "../rules/dice.h"

#include <string>

namespace dm {
namespace encounters {

// MM FREQUENCY string → selection weight. Higher = met more often.
// Unknown/blank strings weight as "uncommon" (defensive: new data
// must not crash the picker).
int frequencyWeight(const std::string& frequency);

struct Encounter {
    const monsters::MonsterDef* def = nullptr; // picked monster (owned by
                                               // the registry — do not free)
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
                                 // goblins say "40-400" — a 400-orc spawn
                                 // on one screen is a designer problem)
    bool allowUnique = false;    // Tiamat, Bahamut & friends stay out of
                                 // random rotation unless asked for
    bool rollTreasure = true;    // fill lairHoard/carried
    std::string alignmentFilter; // "" = any; else alignment prefix,
                                 // e.g. "chaotic", "lawful_good"
};

// Roll one random encounter from everything the registry loaded.
// Returns false (out.def == nullptr) if no eligible monster exists.
bool rollEncounter(const monsters::MonsterRegistry& reg,
                   rules::Dice& dice,
                   const EncounterOptions& opt,
                   Encounter& out);

} // namespace encounters
} // namespace dm
