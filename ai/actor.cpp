// ============================================================================
// Adnd1 — ai/actor.cpp
// Actor derived values + the encounter driver.
// R18: special attack resolution (poison/paralysis/drain/breath).
// R21: player target hook + flee request processed inside the driver.
// R24: multi-member parties — the target hook is consulted per
//      attacking member (pickFoeForPartyActor receives the actor),
//      and flee parting swings pick a RANDOM living party member
//      instead of always the front-most.
// R25: quaff command — a requested member's melee submissions are
//      replaced by one ACTION_DRINK at segment 10 (end of round,
//      R7 drink convention); the quaff hook applies the effect
//      when the scheduler reaches the event.
// ============================================================================

#include "actor.h"

#include <algorithm>
#include <cstdio>

namespace ai {

// ----------------------------------------------------------------------------
// Actor derived values
// ----------------------------------------------------------------------------

int Actor::armorClass() const {
    if (isCharacter) {
        return items::effectiveAc(armor, shield, 0, dex);
    }
    // monster base: unarmored 9 minus half hit dice (convention;
    // real monster ACs arrive with the Lua registry)
    int ac = 9 - (int)(hitDice / 2);
    if (ac < 1) ac = 1;
    if (hasStatus(spelleffects::STATUS_SHIELDED)) ac -= 2;
    return ac;
}

int Actor::hitAdjustment(const Actor& defender) const {
    if (isCharacter) {
        rules::AcType at = rules::acTypeForAc(defender.armorClass());
        return items::attackAdjustment(weapon, exStr, str, at);
    }
    return 0;   // monsters: flat
}

int Actor::toHit(const Actor& defender) const {
    int ac = defender.armorClass();
    if (isCharacter) {
        return rules::attackNumber(classIndex, level, ac);
    }
    return rules::attackMatrixFighter(
        rules::monsterEffectiveLevel(hitDice), ac);
}

int Actor::attacksPerRound() const {
    if (isCharacter)
        return rules::meleeAttacksPerRound(classIndex, level);
    return monsterAttacks;
}

spelleffects::TargetDesc Actor::asTarget() const {
    spelleffects::TargetDesc t;
    t.hp = hp; t.maxHp = maxHp;
    t.saveClass = isCharacter ? classIndex : 0;   // monsters: fighter
    t.saveLevel = isCharacter ? level
                              : rules::monsterEffectiveLevel(hitDice);
    t.saveBonus = 0;
    t.magicResistPct = isCharacter ? 0 : magicResistPct;
    t.isUndead = undead;
    t.isLarge = hitDice >= 8;
    return t;
}

bool Actor::hasStatus(spelleffects::StatusKind k) const {
    for (const auto& s : statuses)
        if (s.kind == k) return true;
    return false;
}

void Actor::addStatus(const spelleffects::StatusEffect& st) {
    // refresh if present, else append
    for (auto& s : statuses)
        if (s.kind == st.kind) { s = st; return; }
    statuses.push_back(st);
}

void Actor::tickStatuses() {
    for (auto& s : statuses)
        spelleffects::tickStatus(s);
    // drop expired
    statuses.erase(
        std::remove_if(statuses.begin(), statuses.end(),
            [](const spelleffects::StatusEffect& s) {
                return s.kind == spelleffects::STATUS_NONE; }),
        statuses.end());
}

bool Actor::canAct() const {
    if (!alive()) return false;
    if (hasStatus(spelleffects::STATUS_SLEEP)) return false;
    if (hasStatus(spelleffects::STATUS_HELD)) return false;
    return true;
}

// ----------------------------------------------------------------------------
// Encounter driver
// ----------------------------------------------------------------------------

Encounter::Encounter(std::vector<Actor> party, std::vector<Actor> monsters,
                     uint64_t seed)
    : m_party(std::move(party)), m_monsters(std::move(monsters)),
      m_rng(seed), m_dice(m_rng) {}

void Encounter::logLine(const std::string& s) {
    m_log.push_back({s});
}

int Encounter::teamAlive(int team) const {
    const std::vector<Actor>& v = team == 0 ? m_party : m_monsters;
    int n = 0;
    for (const auto& a : v)
        if (a.alive()) ++n;
    return n;
}

bool Encounter::teamCanAct(int team) const {
    const std::vector<Actor>& v = team == 0 ? m_party : m_monsters;
    for (const auto& a : v)
        if (a.canAct()) return true;
    return false;
}

bool Encounter::checkTeamMorale(std::vector<Actor>& team, int otherTeamAlive) {
    // one check per team per round: build a representative state
    dm::MoraleState ms;
    int alive = 0, total = (int)team.size();
    bool leaderDown = false;
    int base = dm::MORALE_AVERAGE;
    for (const auto& a : team) {
        if (a.alive()) { ++alive; base = a.morale; if (a.isLeader) leaderDown = false; }
        else if (a.isLeader) leaderDown = true;
    }
    if (total <= 0) return true;   // gone
    ms.base = base;
    ms.lossesPct = (100 * (total - alive)) / (total > 0 ? total : 1);
    ms.leaderDown = leaderDown;
    ms.outnumbered = alive < otherTeamAlive;
    return dm::moraleCheck(m_dice, ms, dm::MORALE_ON_50PCT_LOSS);
}

int Encounter::resolveMelee(Actor& attacker, Actor& defender) {
    if (!attacker.canAct() || !defender.alive()) return 0;

    // gating: defender requires +N weapon (R5)
    int wpnPlus = attacker.isCharacter ? attacker.weapon.plus : 99;
    if (!rules::weaponSufficient(defender.requiredPlusToHit, wpnPlus)) {
        logLine(attacker.name + "'s weapon cannot harm " + defender.name);
        return 0;
    }

    int toHit = attacker.toHit(defender);
    int adj   = attacker.hitAdjustment(defender);
    if (!rules::attackRollHits(m_dice, toHit, adj)) {
        logLine(attacker.name + " misses " + defender.name);
        return 0;
    }

    // damage
    int dmg;
    if (attacker.isCharacter) {
        const items::WeaponDef& w = items::weapon(attacker.weapon.id);
        bool large = defender.hitDice >= 8 && !defender.isCharacter;
        dmg = (int)m_dice.roll(
            large ? w.lCount : w.smCount,
            large ? w.lSides : w.smSides, 0);
        dmg += attacker.weapon.plus;
    } else {
        dmg = (int)m_dice.roll((uint32_t)attacker.monsterDamageCount,
                               (uint32_t)attacker.monsterDamageSides, 0);
    }
    if (dmg < 1) dmg = 1;

    defender.hp -= dmg;
    logLine(attacker.name + " hits " + defender.name + " for " +
            std::to_string(dmg));

    // sleeping targets wake when struck
    if (defender.hasStatus(spelleffects::STATUS_SLEEP) && defender.alive()) {
        for (auto& s : defender.statuses)
            if (s.kind == spelleffects::STATUS_SLEEP)
                s.kind = spelleffects::STATUS_NONE;
        defender.tickStatuses();
        logLine(defender.name + " wakes up!");
    }

    // R18: special attacks on a hit (monsters)
    if (!attacker.isCharacter) {
        for (const auto& sp : attacker.specials)
            resolveSpecial(attacker, defender, sp);
    }

    if (!defender.alive()) {
        defender.hp = 0;
        logLine(defender.name + " is down!");
    }
    return dmg;
}

// ----------------------------------------------------------------------------
// R18: special attack resolution
// ----------------------------------------------------------------------------

void Encounter::resolveSpecial(Actor& attacker, Actor& defender,
                               const ActorSpecial& sp) {
    (void)attacker;
    auto trySaveVs = [&](int saveCategory, int penalty) {
        int target = rules::saveTarget(
            defender.isCharacter ? defender.classIndex : 0,
            defender.isCharacter ? defender.level
                                 : rules::monsterEffectiveLevel(defender.hitDice),
            (rules::SaveCategory)saveCategory);
        // penalty makes saving HARDER by raising the target
        return rules::attemptSave(m_dice, target + penalty, 0);
    };

    switch (sp.type) {
        case 1: {   // POISON: save or take extra damage
            bool saved = trySaveVs(sp.saveCategory > 0 ? sp.saveCategory
                                                       : rules::SAVE_DEATH_POISON,
                                   sp.savePenalty);
            if (saved) {
                logLine(defender.name + " shrugs off " + sp.name);
            } else {
                int dmg = (int)m_dice.roll(
                    (uint32_t)(sp.diceCount > 0 ? sp.diceCount : 2),
                    (uint32_t)(sp.diceSides > 0 ? sp.diceSides : 6), 0);
                if (dmg < 1) dmg = 1;
                defender.hp -= dmg;
                logLine(defender.name + " suffers " + sp.name +
                        " (" + std::to_string(dmg) + " damage)!");
                if (!defender.alive()) {
                    defender.hp = 0;
                    logLine(defender.name + " is slain by " + sp.name + "!");
                }
            }
            break;
        }
        case 2: {   // PARALYSIS: save or held (ghoul touch)
            bool saved = trySaveVs(sp.saveCategory > 0 ? sp.saveCategory
                                                       : rules::SAVE_PETRIFY_POLY,
                                   sp.savePenalty);
            if (saved) {
                logLine(defender.name + " resists " + sp.name);
            } else if (defender.alive()) {
                spelleffects::StatusEffect st;
                st.kind = spelleffects::STATUS_HELD;   // paralysis = held
                st.roundsRemaining = 6;   // ghoul paralysis lasts hours
                                          // in 1e; combat-scale rounds
                defender.addStatus(st);
                logLine(defender.name + " is paralyzed by " + sp.name + "!");
            }
            break;
        }
        case 3: {   // ENERGY DRAIN: no save in 1e
            if (defender.alive()) {
                defender.drainLevel(sp.drainLevels);
                if (defender.isCharacter)
                    logLine(defender.name + " is DRAINED (" +
                            std::to_string(sp.drainLevels) +
                            " level" + (sp.drainLevels > 1 ? "s" : "") +
                            ")!");
                else
                    logLine(defender.name + " is drained by " + sp.name + "!");
                if (!defender.alive())
                    logLine(defender.name + " withers to nothing!");
            }
            break;
        }
        case 4: {   // BREATH WEAPON: dice damage, save for half
            int dmg = (int)m_dice.roll(
                (uint32_t)(sp.diceCount > 0 ? sp.diceCount : 3),
                (uint32_t)(sp.diceSides > 0 ? sp.diceSides : 6), 0);
            bool saved = trySaveVs(sp.saveCategory > 0 ? sp.saveCategory
                                                       : rules::SAVE_BREATH,
                                   sp.savePenalty);
            if (saved) dmg /= 2;
            if (dmg < 1) dmg = 1;
            defender.hp -= dmg;
            logLine(defender.name + " is caught by " + sp.name +
                    " (" + std::to_string(dmg) + " damage)!");
            if (!defender.alive()) {
                defender.hp = 0;
                logLine(defender.name + " is slain by " + sp.name + "!");
            }
            break;
        }
        default:
            break;
    }
}

// ----------------------------------------------------------------------------
// R21/R24: player command surface
// ----------------------------------------------------------------------------

// Pick the foe a party actor strikes: the hook decides (per-member
// since R24 — the hook receives the attacking actor, so the app can
// key each member's own target selection); falls back to front-most
// living. A hook-chosen foe that is dead also falls back.
Actor* Encounter::pickFoeForPartyActor(const Actor& attacker) {
    // front-most living
    Actor* front = nullptr;
    for (auto& m : m_monsters)
        if (m.alive()) { front = &m; break; }
    if (!front) return nullptr;

    if (!m_targetHook) return front;

    int idx = m_targetHook(attacker, m_monsters);
    if (idx >= 0 && idx < (int)m_monsters.size() &&
        m_monsters[idx].alive())
        return &m_monsters[idx];
    return front;   // invalid/dead choice: fall back
}

// A monster's free swing at a fleeing party member (normal melee
// resolution, no specials — the beast is lunging, not scheming).
int Encounter::partingSwing(Actor& attacker, Actor& defender) {
    if (!attacker.alive() || !defender.alive()) return 0;

    int toHit = attacker.toHit(defender);
    int adj   = attacker.hitAdjustment(defender);
    if (!rules::attackRollHits(m_dice, toHit, adj)) {
        logLine(attacker.name + " misses the fleeing " + defender.name);
        return 0;
    }
    int dmg = (int)m_dice.roll((uint32_t)attacker.monsterDamageCount,
                               (uint32_t)attacker.monsterDamageSides, 0);
    if (dmg < 1) dmg = 1;
    defender.hp -= dmg;
    logLine(attacker.name + " strikes " + defender.name +
            " from behind for " + std::to_string(dmg) + "!");
    if (!defender.alive()) {
        defender.hp = 0;
        logLine(defender.name + " is cut down in flight!");
    }
    return dmg;
}

int Encounter::stepRound() {
    ++m_round;

    // end conditions
    if (teamAlive(0) == 0) return 1;   // monsters win
    if (teamAlive(1) == 0) return 0;   // party wins
    if (!teamCanAct(0) && !teamCanAct(1)) return -1;

    // ---- R21/R24: flee request processed at the start of the round ----
    if (m_fleeRequested) {
        m_fleeRequested = false;
        logLine("The party breaks off!");
        // dex check on the fleeing party: d20 <= best dex = clean
        int bestDex = 3;
        for (const auto& a : m_party)
            if (a.alive() && a.dex > bestDex) bestDex = a.dex;
        int roll = (int)m_dice.roll(1, 20, 0);
        bool clean = roll <= bestDex;
        if (clean) {
            logLine("You slip away cleanly.");
        } else {
            logLine("The monsters strike at your backs!");
            // R24: each monster lunges at a RANDOM living party
            // member, not always the front-most (multi-member fix)
            std::vector<int> livingIdx;
            for (int i = 0; i < (int)m_party.size(); ++i)
                if (m_party[i].alive()) livingIdx.push_back(i);
            for (auto& m : m_monsters) {
                if (!m.alive() || livingIdx.empty()) continue;
                int pick = (int)m_rng.below(
                    (uint32_t)livingIdx.size());
                partingSwing(m, m_party[livingIdx[pick]]);
                if (teamAlive(0) == 0) break;
            }
        }
        if (teamAlive(0) == 0) return 1;   // cut down in flight
        return 2;                          // party fled
    }

    // surprise (first round only): 2d6 both sides (R7)
    int pSurp = 0, mSurp = 0;
    if (m_round == 1) {
        rules::rollSurprise(m_dice, 0, 0, pSurp, mSurp);
        if (pSurp > 0) logLine("The party is surprised (" +
                               std::to_string(pSurp) + " segments)!");
        if (mSurp > 0) logLine("The monsters are surprised (" +
                               std::to_string(mSurp) + " segments)!");
    }

    // initiative: d6 per side (R7)
    int pIni = rules::rollInitiative(m_dice);
    int mIni = rules::rollInitiative(m_dice);
    int winner = rules::initiativeWinner(pIni, mIni);
    if (winner == 0) logLine("Initiative tie — simultaneous!");

    // build the round's action queue (R7 scheduler)
    rules::RoundScheduler sched;
    int baseSegP = rules::initiativeToSegment(pIni) + pSurp;
    int baseSegM = rules::initiativeToSegment(mIni) + mSurp;

    // R25: capture + clear the drink request for this round
    int drinkMember = m_drinkMember;
    m_drinkMember = -1;

    auto submitTeam = [&](std::vector<Actor>& team, int baseSeg,
                          int drinkIdx) {
        for (auto& a : team) {
            if (!a.canAct()) continue;
            int idx = (int)(&a - team.data());
            // R25: the drinking member's round is consumed — one
            // ACTION_DRINK at the end of the round, no melee
            if (idx == drinkIdx) {
                rules::Action act;
                act.type = rules::ACTION_DRINK;
                act.actorId = a.team * 1000 + idx;
                act.segment = 10;               // end of round
                sched.submit(act, 10);
                continue;
            }
            rules::Action act;
            act.type = rules::ACTION_MELEE;
            act.actorId = a.team * 1000 + idx;
            // hasted actors act twice
            int attacks = a.attacksPerRound();
            if (a.hasStatus(spelleffects::STATUS_HASTED)) attacks *= 2;
            for (int i = 0; i < attacks; ++i) {
                rules::Action a2 = act;
                a2.segment = baseSeg + i * 5;   // routines 5 segs apart
                sched.submit(a2, baseSeg + i * 5);
            }
        }
    };
    submitTeam(m_party, baseSegP, drinkMember);
    submitTeam(m_monsters, baseSegM, -1);
    sched.beginRound();

    // resolve in segment order
    rules::TurnEvent ev;
    while (sched.next(ev)) {
        bool isParty = ev.actorId / 1000 == 0;
        int idx = ev.actorId % 1000;
        Actor& attacker = isParty ? m_party[idx] : m_monsters[idx];
        if (!attacker.canAct()) continue;

        // R25: the drink event — the quaff hook applies the potion
        // (the hook owns inventory; if it does nothing, e.g. no
        // potions left, the round is still consumed)
        if (isParty && idx == drinkMember) {
            if (m_quaffHook) m_quaffHook(attacker);
            continue;
        }

        // pick a living enemy
        Actor* target = nullptr;
        if (isParty) {
            // R24: hook-aware, per attacking member
            target = pickFoeForPartyActor(attacker);
        } else {
            for (auto& f : m_party)
                if (f.alive()) { target = &f; break; }
        }
        if (!target) break;

        resolveMelee(attacker, *target);

        if (teamAlive(0) == 0 || teamAlive(1) == 0) break;
    }

    // statuses tick at end of round
    for (auto& a : m_party) a.tickStatuses();
    for (auto& a : m_monsters) a.tickStatuses();

    // morale between rounds (monsters first)
    if (teamAlive(1) > 0 && m_round >= 2) {
        int alive0 = teamAlive(0), alive1 = teamAlive(1);
        if (!checkTeamMorale(m_monsters, alive0)) {
            logLine("The monsters break and flee!");
            return 3;   // monsters fled
        }
        if (!checkTeamMorale(m_party, alive1)) {
            logLine("The party flees!");
            return 2;   // party fled
        }
    }

    return -1;   // fight continues
}

int Encounter::run(int maxRounds) {
    int result = -1;
    for (int r = 0; r < maxRounds && result == -1; ++r)
        result = stepRound();
    return result;
}

} // namespace ai
