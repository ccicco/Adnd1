// ============================================================================
// Adnd1 — ai/actor.h
// The unified entity layer: one Actor type for characters and
// monsters, plus the encounter driver that runs whole fights on the
// R7 scheduler with R5/R6/R8/R14 resolution.
//
// R18: specials (poison/paralysis/energy drain/breath) + drainLevel.
// R21: player command hook (target choice + flee) wired into the
//      driver — see Encounter::setPlayerTargetHook / requestFlee.
// R24: multi-member parties — pickFoeForPartyActor now receives the
//      attacking actor so the app's target hook is consulted PER
//      MEMBER (each character can hold its own target selection).
// ============================================================================

#pragma once

#include "../rules/dice.h"
#include "../rules/combat.h"
#include "../rules/saves.h"
#include "../rules/turn.h"
#include "../spelleffects/spelleffects.h"
#include "../items/items.h"
#include "../dm/dm.h"

#include <functional>
#include <string>
#include <vector>

namespace ai {

using rules::Dice;

// ----------------------------------------------------------------------------
// Special attack carried by an Actor (mirrors monsters::SpecialAttack
// without the dependency; the registry converts on toActor()).
// Type values: 1 poison, 2 paralysis, 3 energy drain, 4 breath weapon.
// ----------------------------------------------------------------------------
struct ActorSpecial {
    int  type = 0;
    std::string name;
    int  saveCategory = 0;  // rules/SaveCategory
    int  savePenalty = 0;   // modifier on the save target
    int  diceCount = 0;
    int  diceSides = 0;
    int  drainLevels = 1;
};

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

    // R18: special attacks (copied from MonsterDef by the registry)
    std::vector<ActorSpecial> specials;

    // ---- derived values ----------------------------------------------------
    int armorClass() const;        // R12 effectiveAc (chars) / 10-HD base (mon)
    int toHit(const Actor& defender) const;   // full attack number
    int hitAdjustment(const Actor& defender) const;  // STR+plus+wvsAC
    int attacksPerRound() const;   // R7 meleeAttacks / monster routines

    // R14 target descriptor view of this actor
    spelleffects::TargetDesc asTarget() const;

    // status helpers
    bool hasStatus(spelleffects::StatusKind k) const;
    void addStatus(const spelleffects::StatusEffect& st);
    void tickStatuses();           // called each round

    bool alive() const { return hp > 0; }
    bool canAct() const;           // alive + not asleep/held/etc.

    // R18: energy drain bookkeeping
    void drainLevel(int levels = 1) {
        for (int i = 0; i < levels; ++i) {
            if (isCharacter) {
                if (level <= 1) {
                    // drained to level 0: the actor falls
                    hp = 0;
                    return;
                }
                --level;
                // proportional hp loss (average die per level)
                int lost = (classIndex == 0) ? 5 : 4;
                maxHp -= lost;
                if (maxHp < 1) maxHp = 1;
                hp -= lost;
                if (hp < 1) hp = 1;   // drain never kills outright
            } else {
                // monsters: lose a hit die
                if (hitDice <= 1.0f) { hp = 0; return; }
                hitDice -= 1.0f;
                maxHp -= 4;
                if (maxHp < 1) maxHp = 1;
                if (hp > maxHp) hp = maxHp;
            }
        }
    }
};

// ----------------------------------------------------------------------------
// Encounter: two teams, run on the scheduler.
//
// R21: the app can install a target hook — called when a PARTY actor
// is about to strike, it returns the index (into the monster list)
// of the foe to attack. Returning a dead foe's index falls back to
// front-most. requestFlee() flags the party to break off at the
// start of the next round: monsters get free swings, then the fight
// ends with result 2 (party fled).
//
// R24: the hook is consulted for EVERY party actor's attack and
// receives that actor, so a multi-member party can hold one target
// selection per member (the app keys off the attacker — e.g. by
// name — to look up that member's chosen foe).
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
    std::vector<Actor>& monstersMutable() { return m_monsters; }

    // single-round step (interactive combat drives this)
    int stepRound();

    // R18: resolve a special attack that landed.
    void resolveSpecial(Actor& attacker, Actor& defender,
                        const ActorSpecial& sp);

    // ---- R21: player command surface --------------------------------------
    // Called when a party actor attacks: returns foe index to strike.
    // nullptr = auto (front-most living).
    void setPlayerTargetHook(
        std::function<int(const Actor& attacker,
                          const std::vector<Actor>& foes)> hook) {
        m_targetHook = std::move(hook);
    }

    // Party breaks off next round: monsters swing freely, fight ends.
    void requestFlee() { m_fleeRequested = true; }

    // R21: free swing by a monster against a party member (used by
    // the flee sequence; resolved through the normal melee path).
    int partingSwing(Actor& attacker, Actor& defender);

private:
    std::vector<Actor> m_party;
    std::vector<Actor> m_monsters;
    rules::Rng  m_rng;
    rules::Dice m_dice;
    std::vector<EncounterLogLine> m_log;
    int m_round = 0;

    std::function<int(const Actor&, const std::vector<Actor>&)>
        m_targetHook;                       // R21
    bool m_fleeRequested = false;           // R21

    void logLine(const std::string& s);
    int  teamAlive(int team) const;
    bool teamCanAct(int team) const;
    bool checkTeamMorale(std::vector<Actor>& team, int otherTeamAlive);
    // resolve one melee attack, returns damage dealt (0 = miss)
    int  resolveMelee(Actor& attacker, Actor& defender);
    // pick the target for a party actor (hook-aware, R21; per-actor
    // since R24 — the hook receives the attacking member)
    Actor* pickFoeForPartyActor(const Actor& attacker);
};

} // namespace ai
