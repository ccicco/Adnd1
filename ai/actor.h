// ============================================================================
// Adnd1 â ai/actor.h
// The unified entity layer: one Actor type for characters and
// monsters, plus the encounter driver that runs whole fights on the
// R7 scheduler with R5/R6/R8/R14 resolution.
//
// R18: specials (poison/paralysis/energy drain/breath) + drainLevel.
// R21: player command hook (target choice + flee) wired into the
//      driver â see Encounter::setPlayerTargetHook / requestFlee.
// R24: multi-member parties â pickFoeForPartyActor now receives the
//      attacking actor so the app's target hook is consulted PER
//      MEMBER (each character can hold its own target selection).
// R25: quaff command â requestDrink(memberIndex) makes that member
//      drink a potion instead of attacking this round (ACTION_DRINK
//      on the segment scheduler, end of round per R7); the quaff
//      hook applies the effect and owns the potion inventory.
// R27: cast command â requestCast(memberIndex, SpellId) makes that
//      member cast a spell instead of attacking this round
//      (ACTION_SPELL at initiative segment + casting time, per
//      R7/R13). The driver resolves the effect engine-
//      authoritatively via spelleffects::resolveSpell; spell slots
//      live on the Actor (slotsByLevel, app-initialized).
// R28: shoot command â requestShoot(memberIndex) makes that member
//      fire missiles this round instead of melee (ACTION_MISSILE
//      events at the initiative segment, +5 per follow-up shot, R7
//      rate-of-fire convention). Uses the Actor's rangedWeapon slot
//      (a second WeaponInstance â PHB characters carry melee AND
//      missile weapons); STR does not add to missile attacks (PHB).
// R33: spellbook â Actor carries the MU's known spell ids
//      (knownSpells, copied from Character by toActor); the app's
//      castable list filters on it. Clerics cast freely (prayers,
//      PHB â no book), so the filter is MU-only.
// R35: ammo counting â Actor::missileAmmo tracks shots left in
//      the quiver (Characters only, synced from/to the roster);
//      each resolveMissile shot spends one, and a dry quiver
//      means no ACTION_MISSILE events (the member melees).
// R36: throw command â requestThrow(memberIndex) makes that member
//      HURL their melee weapon (dagger/hand axe/spear, PHB p.38):
//      one ACTION_MISSILE shot whose dice/plus come from the melee
//      weapon; the weapon is spent for the encounter (unarmed
//      1d2 fists afterwards) and recovered after the fight.
// R37: monster missile attacks â Actor::monsterRanged marks a
//      missile-armed monster; such monsters fire an opening
//      volley (one ACTION_MISSILE per attack routine) in the
//      FIRST round only, then close to melee for the rest of the
//      fight (no range/movement system yet â logged
//      simplification). resolveMissile's monster path (own damage
//      dice, no quiver) resolves the shots.
// R42: range bands â missile fire is bounded by the weapon's
//      short range (rangeTens * 10 feet, PHB p.39). The R37
//      round-1 volley now lasts as many rounds as the weapon has
//      range bands (short bow 5 â 5 rounds), tracked on the
//      Actor (rangedRounds). Party shooters are unaffected
//      (their fire is command-driven); once the bands close, the
//      monsters melee.
// R43: party-side range â the encounter carries an abstract
//      distance (m_distance, 5 bands = 50' engagement range).
//      It closes one band per round; party missile fire ([x])
//      requires an open range. Thrown weapons are exempt (they
//      can be hurled into melee â PHB simplification).
// ============================================================================

#pragma once

#include "../rules/dice.h"
#include "../rules/combat.h"
#include "../rules/saves.h"
#include "../rules/turn.h"
#include "../spells/spells.h"
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
    // R28: missile weapon slot (bow/crossbow/sling). Empty when the
    // character carries none â id WPN_DAGGER with a false missile
    // flag in the registry, so check hasRangedWeapon() instead.
    items::WeaponInstance rangedWeapon;
    // R35: shots remaining in the quiver (characters only; the
    // Character roster owns the durable count, synced on combat
    // start/end). Monsters fire freely (no tracked ammo).
    int missileAmmo = 0;
    // R36: thrown-weapon state. "throwing" marks a hurl request
    // pending this round; "weaponThrown" marks the melee weapon
    // as spent for the rest of the encounter (hurled into the
    // fray â recovered afterward, PHB missile-retrieval
    // convention). Both reset per encounter (the Actor is built
    // from the Character roster fresh each fight).
    bool throwing = false;
    bool weaponThrown = false;
    items::ArmorInstance  armor;
    bool shield = false;

    // monster path
    float hitDice = 1.0f;
    int   monsterAttacks = 1;      // attack routines per round
    int   monsterDamageCount = 1, monsterDamageSides = 6;
    // R37: missile-armed monster â fires an opening volley in
    // round 1, then melees. Set by the app from the monster key
    // (the Lua registry data carries no ranged flag).
    bool  monsterRanged = false;
    // R42: rounds of missile fire left before the range closes.
    // Set from the monster key's implied weapon when the app
    // marks monsterRanged; each volley round decrements it, and
    // at zero the monster closes to melee.
    int   rangedRounds = 0;
    int   magicResistPct = 0;

    // R46: psionics hook — a psionic monster (flagged by the
    // app from the monster key, the R37 monsterRanged pattern)
    // opens with a mind blast once per encounter: one living
    // party member saves vs spells or is stunned for the round
    bool  psionic = false;
    bool  psionicBlastUsed = false;
    bool  psionicStunned = false;   // cleared at end of round
    bool  undead = false;

    // shared state
    int  hp = 1, maxHp = 1;
    int  requiredPlusToHit = 0;    // gating: needs +N weapon (R5)
    int  morale = dm::MORALE_AVERAGE;
    bool isLeader = false;

    std::vector<spelleffects::StatusEffect> statuses;

    // R18: special attacks (copied from MonsterDef by the registry)
    std::vector<ActorSpecial> specials;

    // R27: spell slots by level (index 0 = spell level 1).
    // Characters only â the app initializes these from
    // spells::spellSlots when the encounter party is built
    // (Character::toActor); the driver decrements them when a
    // cast resolves. Refreshed each encounter (per-day slot
    // tracking is deferred â logged simplification).
    int  slotsByLevel[6] = {0, 0, 0, 0, 0, 0};   // R46: 6 levels

    // R33: MU spellbook â known spell ids (spells::SpellId).
    // Empty for non-MUs (they cast freely).
    std::vector<int> knownSpells;

    bool knowsSpell(int id) const {
        for (int s : knownSpells)
            if (s == id) return true;
        return false;
    }

    bool isCaster() const {
        return isCharacter &&
               (classIndex == 1 || classIndex == 2);   // MU / cleric
    }

    // R28: true when the ranged slot holds a real missile weapon
    bool hasRangedWeapon() const {
        const items::WeaponDef& w = items::weapon(rangedWeapon.id);
        return w.missile;
    }

    // R36: the melee weapon can be hurled (dagger/hand axe/spear,
    // PHB p.38) and hasn't been thrown already this encounter
    bool meleeThrowable() const {
        return isCharacter && !weaponThrown &&
               (weapon.id == items::WPN_DAGGER ||
                weapon.id == items::WPN_HAND_AXE ||
                weapon.id == items::WPN_SPEAR);
    }

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
// R21: the app can install a target hook â called when a PARTY actor
// is about to strike, it returns the index (into the monster list)
// of the foe to attack. Returning a dead foe's index falls back to
// front-most. requestFlee() flags the party to break off at the
// start of the next round: monsters get free swings, then the fight
// ends with result 2 (party fled).
//
// R24: the hook is consulted for EVERY party actor's attack and
// receives that actor, so a multi-member party can hold one target
// selection per member (the app keys off the attacker â e.g. by
// name â to look up that member's chosen foe).
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

    // ---- R25: quaff command -----------------------------------------------
    // Request that the given party member (index into the party
    // vector) drink a healing potion THIS round instead of
    // attacking: their action becomes ACTION_DRINK scheduled at
    // the end of the round (R7 drink convention). The effect is
    // applied by the quaff hook when the scheduler reaches the
    // event â the hook owns the potion inventory and the heal, so
    // the driver stays inventory-free. If the member cannot act
    // when the event comes up (held, asleep, down), the hook is
    // NOT called and no potion is consumed. A new request
    // overwrites a pending one; a flee-interrupted round drops it.
    void requestDrink(int memberIndex) { m_drinkMember = memberIndex; }

    void setQuaffHook(std::function<void(Actor& drinker)> hook) {
        m_quaffHook = std::move(hook);
    }

    // ---- R27: cast command -------------------------------------------------
    // Request that the given party member (index into the party
    // vector) cast a spell THIS round instead of attacking: their
    // action becomes ACTION_SPELL, resolving at the side's
    // initiative segment + the spell's casting time (R7 scheduler,
    // R13 casting times). The driver resolves the effect engine-
    // authoritatively via spelleffects::resolveSpell â targeting by
    // the SpellDef's shape: single-target spells use the member's
    // own foe selection (the R21/R24 target hook), area/multi-
    // target spells hit every living foe, cure spells heal the
    // most-wounded living ally, TARGET_SELF affects the caster.
    // Slot accounting lives on the Actor (slotsByLevel, consumed
    // only when the cast actually resolves; a silenced or slotless
    // cast consumes nothing and the round is still spent). A new
    // request overwrites a pending one; a flee-interrupted round
    // drops it.
    void requestCast(int memberIndex, spells::SpellId id) {
        m_castMember = memberIndex;
        m_castSpell  = id;
    }

    // ---- R28: shoot command -------------------------------------------------
    // Request that the given party member (index into the party
    // vector) fire their missile weapon THIS round instead of
    // melee: their action becomes ACTION_MISSILE events â one per
    // shot at the weapon's rate of fire, first at the side's
    // initiative segment, follow-ups +5 segments (R7 convention).
    // Requires the ranged slot to hold a missile weapon (checked
    // by the app before calling; a member without one just melees).
    // Targeting uses the member's own foe selection (R21/R24 hook).
    // STR does not modify missile to-hit or damage (PHB); DEX
    // missile adjustment is deferred (logged). R35: ammunition is
    // counted â each shot spends one from Actor::missileAmmo, and
    // a dry quiver means the member melees instead (the app also
    // gates the command; the engine check is authoritative).
    // A new request overwrites a pending one; a flee-interrupted
    // round drops it.
    void requestShoot(int memberIndex) {
        m_shootMember = memberIndex;
    }

    // R36: throw command â requestThrow(memberIndex) makes that
    // member HURL their melee weapon this round: one shot at the
    // side's initiative segment (rate of fire 1). Dice, plus and
    // the +N gating all come from the melee weapon; DEX reaction
    // adjustment applies (R32 convention), STR does not (PHB).
    // The weapon is spent for the encounter (unarmed 1d2 fists
    // afterwards) and recovered after the fight. The app gates on
    // meleeThrowable() before calling; a new request overwrites a
    // pending one; a flee-interrupted round drops it.
    void requestThrow(int memberIndex) {
        m_throwMember = memberIndex;
    }

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

    int  m_drinkMember = -1;                // R25 (-1 = none)
    std::function<void(Actor&)> m_quaffHook;   // R25

    int  m_castMember = -1;                             // R27
    spells::SpellId m_castSpell = spells::MU_SLEEP;    // R27

    int  m_shootMember = -1;                // R28 (-1 = none)

    int  m_throwMember = -1;                // R36 (-1 = none)

    int  m_distance = 5;   // R43: engagement range in 10' bands

    void logLine(const std::string& s);
    int  teamAlive(int team) const;
    bool teamCanAct(int team) const;
    bool checkTeamMorale(std::vector<Actor>& team, int otherTeamAlive);
    // resolve one melee attack, returns damage dealt (0 = miss)
    int  resolveMelee(Actor& attacker, Actor& defender);
    // pick the target for a party actor (hook-aware, R21; per-actor
    // since R24 â the hook receives the attacking member)
    Actor* pickFoeForPartyActor(const Actor& attacker);

    // R27: resolve a party member's cast through spelleffects and
    // apply the per-target results (hp, statuses, notes) back to
    // the affected actors
    void resolveCast(Actor& caster, spells::SpellId id);

    // R28: resolve one missile shot (no STR mods; missile dice)
    void resolveMissile(Actor& attacker, Actor& defender);

    // R43: true while the engagement range is still open (the
    // foes have not closed to melee). Party missile fire gates
    // on this; monster volleys use their own rangedRounds.
    bool rangeOpen() const { return m_distance > 0; }
};

} // namespace ai
