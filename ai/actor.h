// ============================================================================
// Adnd1 — ai/actor.h
// The unified entity layer: one Actor type for characters and
// monsters, plus the encounter driver that runs whole fights on the
// R7 scheduler with R5/R6/R8/R14 resolution.
// ============================================================================

#pragma once

#include "../rules/dice.h"
#include "../rules/combat.h"
#include "../rules/saves.h"
#include "../rules/turn.h"
#include "../spelleffects/spelleffects.h"
#include "../items/items.h"
#include "../dm/dm.h"

#include <string>
#include <vector>

namespace ai {

using rules::Dice;

// ----------------------------------------------------------------------------
// Actor: a combatant. Characters fill the character fields; monsters
// fill the monster fields. Resolution paths use whichever is set.
// ----------------------------------------------------------------------------
struct Actor {
    std::string name = "Actor";
    int  team = 0;                 // 0 = party, 1 = monsters

    // identity: character or monster
    bool isCharacter = false;
    // character path
    int  classIndex = 0;           // CharClass index
    int  level      = 1;
    uint8_t str = 10, dex = 10, con = 10, intel = 10, wis = 10, cha = 10;
    rules::ExceptionalStrength exStr{};
    items::WeaponInstance weapon;
    items::ArmorInstance  armor;
    bool shield = false;

    // monster path
    float hitDice = 1.0f;
    int   monsterAttacks = 1;      // attack routines per round
    int   monsterDamageCount = 1, monsterDamageSides = 6;
    int   magicResistPct = 0;
    bool  undead = false;

    // shared state
    int  hp = 1, maxHp = 1;
    int  requiredPlusToHit = 0;    // gating: needs +N weapon (R5)
    int  morale = dm::MORALE_AVERAGE;
    bool isLeader = false;

    std::vector<spelleffects::StatusEffect> statuses;

    // ---- derived values ----------------------------------------------------
    int armorClass() const;        // R12 effectiveAc (chars) / 10-HD base (mon)
    int toHit(const Actor& defender) const;   // full attack number
    int hitAdjustment(const Actor& defender) const;  // STR+plus+wvsAC
    int attacksPerRound() const;   // R7 meleeAttacks / monster routines
    rules::SaveCategory lastSaveCat = rules::SAVE_SPELLS; // unused hook

    // R14 target descriptor view of this actor
    spelleffects::TargetDesc asTarget() const;

    // status helpers
    bool hasStatus(spelleffects::StatusKind k) const;
    void addStatus(const spelleffects::StatusEffect& st);
    void tickStatuses();           // called each round

    bool alive() const { return hp > 0; }
    bool canAct() const;           // alive + not asleep/held/etc.
};

// ----------------------------------------------------------------------------
// Encounter: two teams, run on the scheduler.
// ----------------------------------------------------------------------------
struct EncounterLogLine {
    std::string text;
};

class Encounter {
public:
    Encounter(std::vector<Actor> party, std::vector<Actor> monsters,
              uint64_t seed = 1);

    // Run the whole fight to completion (or until one side flees or
    // dies). Returns 0 = party wins, 1 = monsters win, 2 = party
    // fled, 3 = monsters fled, -1 = still going (round limit).
    int run(int maxRounds = 20);

    const std::vector<EncounterLogLine>& log() const { return m_log; }
    const std::vector<Actor>& party() const { return m_party; }
    const std::vector<Actor>& monsters() const { return m_monsters; }

    // single-round step (for interactive combat later)
    int stepRound();

private:
    std::vector<Actor> m_party;
    std::vector<Actor> m_monsters;
    rules::Rng  m_rng;
    rules::Dice m_dice;
    std::vector<EncounterLogLine> m_log;
    int m_round = 0;

    void logLine(const std::string& s);
    int  teamAlive(int team) const;          // count of living actors
    bool teamCanAct(int team) const;
    bool checkTeamMorale(std::vector<Actor>& team, int otherTeamAlive);
    // resolve one melee attack, returns damage dealt (0 = miss)
    int  resolveMelee(Actor& attacker, Actor& defender);
};

} // namespace ai