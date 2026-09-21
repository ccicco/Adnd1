// ============================================================================
// Adnd1 — game/party.h
// The career layer: Character (one member durable record) and
// Party (the roster). Moved verbatim from adnd1.cpp, R31; the
// file split that keeps adnd1.cpp to the Win32/GDI shell.
// R33: the MU spellbook lives here (Character::knownSpells);
// level-ups roll the chance-to-learn check (spells/ PHB p.10).
// R34: per-day spell slots — Character::slotsByLevel persists
// across encounters; toActor carries the CURRENT pool (not a
// fresh one), and the app restores it on rest (or descend, to
// keep a loaded/descended company from being stuck dry).
// R44: the career extras — the stronghold (name-level keep),
// the henchman (a hired NPC fighter who fights alongside the
// roster), and the identify economy (scrolls + unidentified
// magic items waiting on a scribe's verdict).
// ============================================================================

#pragma once

#include "../rules/dice.h"
#include "../rules/character.h"
#include "../rules/classes.h"
#include "../items/items.h"
#include "../ai/actor.h"
#include "../dm/dm.h"
#include "../spells/spells.h"

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

// ----------------------------------------------------------------------------
// R24: party roster constants
// ----------------------------------------------------------------------------

static const int PARTY_MAX      = 6;   // hard ceiling
static const int PARTY_DEFAULT  = 6;   // starting cap (adjustable 1-6)
static const int NAME_MAX_CHARS = 16;

// ----------------------------------------------------------------------------
// R24: Character — the durable career record for one party member.
// The combat Actor is built from this at encounter spawn (toActor)
// and synced back by name when the fight ends.
// ----------------------------------------------------------------------------

struct Character {
    std::string name;
    rules::AbilityScores     abilities;
    rules::ExceptionalStrength exStr;   // fighter group + STR 18 only
    int  classIndex = 0;
    int  xp   = 0;
    int  level = 1;
    int  hp = 0, maxHp = 0;

    items::WeaponInstance weapon;
    items::WeaponInstance rangedWeapon;   // R28: missile slot
    int missileAmmo = 0;   // R35: arrows/bolts/stones on hand
    items::ArmorInstance  armor;
    bool shield = false;

    // R33: MU spellbook — known spell ids (spells::SpellId).
    // Empty for non-MUs (clerics cast freely).
    std::vector<int> knownSpells;

    // R34: per-day spell slots by level (index 0 = spell level
    // 1). Persisted across encounters; restored by rest.
    int  slotsByLevel[3] = {0, 0, 0};

    bool knowsSpell(int id) const {
        for (int s : knownSpells)
            if (s == id) return true;
        return false;
    }

    ai::Actor toActor() const {
        ai::Actor a;
        a.name        = name;
        a.team        = 0;
        a.isCharacter = true;
        a.classIndex  = classIndex;
        a.level       = level;
        a.str    = abilities.str;
        a.dex    = abilities.dex;
        a.con    = abilities.con;
        a.intel  = abilities.int_;
        a.wis    = abilities.wis;
        a.cha    = abilities.cha;
        a.exStr  = exStr;
        a.weapon = weapon;
        a.rangedWeapon = rangedWeapon;   // R28
        a.missileAmmo = missileAmmo;     // R35: live quiver count
        a.armor  = armor;
        a.shield = shield;
        a.hp     = hp;
        a.maxHp  = maxHp;
        a.morale = dm::MORALE_FANATIC;   // player party never breaks
        // R34: slots persist — toActor carries the CURRENT pool
        // (the app restores it on rest, not per encounter)
        for (int lv = 0; lv < 3; ++lv)
            a.slotsByLevel[lv] = slotsByLevel[lv];
        // R33: the spellbook travels with the actor
        a.knownSpells = knownSpells;
        return a;
    }

    // "18/76" style display for exceptional strength
    std::string strDisplay() const {
        char buf[16];
        if (exStr.has)
            snprintf(buf, sizeof buf, "18/%02d",
                     exStr.pct >= 100 ? 0 : exStr.pct);
        else
            snprintf(buf, sizeof buf, "%d", (int)abilities.str);
        return buf;
    }
};

// ----------------------------------------------------------------------------
// R24: Party — a roster of Characters. Gold and kill counts stay
// party-level (split loot, shared glory); XP/HP/level are per member.
// ----------------------------------------------------------------------------

struct Party {
    int x = 0, y = 0;
    std::vector<Character> members;
    bool formed = false;

    int gold = 0;
    int kills = 0;
    int potions = 0;   // R25: shared pool of healing potions
    // R43: DMG training — level-ups do NOT take effect until the
    // member trains (1500 gp x new level, simplified flat rate
    // from the DMG p.86 "1,500 x level" convention). Pending
    // promotions queue here (member indices); the app charges
    // gold and promotes in town. Simplification: the hit-die
    // roll is deferred too — the whole level-up waits. XP
    // thresholds still gate normally.
    std::vector<int> pendingTraining;   // member indices awaiting training

    // R44: the stronghold — a member at name level (their class
    // level cap) may build a keep (10,000 gp, a rebuild-scale
    // simplification of the DMG p.83 barony costs; the book's
    // stronghold economics are far larger). Once built it pays
    // rents on every return to town and halves training fees
    // (the keep's masters-at-arms instruct their lord's company).
    bool strongholdBuilt = false;
    int  strongholdOwner = -1;   // member index of the lord

    // R44: the henchman — one hired NPC (DMG p.36 simplified:
    // a 100 gp offer, acceptance vs interest, loyalty 50 + Cha
    // reaction adj). A level-1 fighter who fights as an extra
    // party actor; upkeep 100 gp/level is billed on each return
    // to town (delve cadence stands in for the month), and a
    // failed loyalty roll on descending sends him home.
    bool        henchmanPresent = false;
    std::string henchmanName;
    int  henchmanHp = 0, henchmanMaxHp = 0;
    int  henchmanLevel  = 1;
    int  henchmanLoyalty = 50;

    // R44: identify economy — scrolls (found or bought, 100 gp
    // at the scribe) reveal unidentified magic items. kind 0 =
    // magic weapon (long sword), kind 1 = enchanted armor; the
    // plus was rolled at loot time but stays unknown to the
    // COMPANY until a scroll is read over the item.
    int  identifyScrolls = 0;
    struct PendingItem { int kind = 0; int plus = 0; };
    std::vector<PendingItem> unidentified;

    // R44: the henchman's combat actor (a fighter of his level;
    // fixed average stats keep the hire a one-roll affair —
    // simplification vs the book's rolled applicants)
    ai::Actor henchmanActor() const {
        ai::Actor a;
        a.name        = henchmanName;
        a.team        = 0;
        a.isCharacter = true;
        a.classIndex  = 0;   // fighter
        a.level       = henchmanLevel;
        a.str = 12; a.dex = 11; a.con = 12;
        a.intel = 9; a.wis = 10; a.cha = 10;
        a.weapon = items::WeaponInstance();
        a.weapon.id = items::WPN_LONG_SWORD;
        a.armor  = items::ArmorInstance();
        a.armor.id = items::ARMOR_CHAIN_MAIL;   // PHB p.36 kit
        a.shield = true;
        a.hp     = henchmanHp;
        a.maxHp  = henchmanMaxHp;
        a.morale = dm::MORALE_FANATIC;   // loyalty gates delves, not rounds
        return a;
    }

    bool alive() const {
        if (!formed) return false;
        for (const auto& c : members)
            if (c.hp > 0) return true;
        return false;
    }

    // per-member XP + level-ups (R22 logic, looped over the
    // roster). R30: the PHB prime-requisite XP adjustment is
    // applied per member — a high prime requisite earns a bonus
    // (% of the award), a low one a penalty; the creation screen
    // has shown this % since R24, the award pipe now honors it.
    void gainXp(int amount, rules::Dice& dice, MessageLog& log) {
        (void)dice;   // R43: hit dice roll moved to trainNext
        for (auto& c : members) {
            if (c.hp <= 0) continue;   // the dead earn nothing
            // R30: prime-requisite % (PHB p.20 class notes) —
            // e.g. STR 16+ fighter +10%, STR 9 fighter -20%
            int primeAb = c.abilities.get(
                (rules::Ability)rules::primeRequisite(
                    c.classIndex));
            int pct = rules::primeRequisitePct(
                (uint8_t)primeAb);
            int gained = amount + (amount * pct) / 100;
            if (gained < 0) gained = 0;   // penalty floors at 0
            c.xp += gained;
            // R43: DMG training — a level-up does not take effect
            // until the member trains (1500 gp x new level, DMG
            // p.86 convention simplified to a flat rate). The
            // promotion queues here; the app promotes and charges
            // in town. One queued promotion per award; further
            // levels queue on later awards.
            int cap = rules::CLASS_LEVEL_CAP[c.classIndex];
            if (c.level < cap &&
                c.xp >= rules::xpForLevel(c.classIndex,
                                          c.level + 1) &&
                !isQueuedForTraining((int)(&c - members.data()))) {
                pendingTraining.push_back(
                    (int)(&c - members.data()));
                char buf[96];
                snprintf(buf, sizeof buf,
                         "%s is due a level — training costs %d "
                         "gp in town.",
                         c.name.c_str(), 1500 * (c.level + 1));
                log.add(buf);
            }
        }
    }

    // R43: is this member already queued?
    bool isQueuedForTraining(int memberIndex) const {
        for (int i : pendingTraining)
            if (i == memberIndex) return true;
        return false;
    }

    // R43: promote the first valid queued member — hit die, MU
    // spell study and level matrices all happen here (the R22/
    // R33 promotion logic, moved out of gainXp). One promotion
    // per call; stale entries (dead members, roster shifts) are
    // dropped. Returns the trained member's index, or -1.
    int trainNext(rules::Dice& dice, MessageLog& log) {
        while (!pendingTraining.empty()) {
            int i = pendingTraining.front();
            pendingTraining.erase(pendingTraining.begin());
            if (i < 0 || i >= (int)members.size()) continue;
            Character& c = members[i];
            int cap = rules::CLASS_LEVEL_CAP[c.classIndex];
            if (c.hp <= 0 || c.level >= cap ||
                c.xp < rules::xpForLevel(c.classIndex,
                                         c.level + 1))
                continue;   // stale entry — try the next
            ++c.level;
            int conAdj = rules::conHPAdjustment(c.classIndex,
                                                c.abilities.con);
            int die = rules::rollHitPoints(c.classIndex,
                                           c.level, conAdj, dice);
            c.maxHp += die;
            c.hp += die;
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%s attains level %d! (+%d hp, now %d/%d)",
                     c.name.c_str(), c.level, die, c.hp, c.maxHp);
            log.add(buf);

            // R33: on a level-up an MU studies one new spell —
            // a random unknown MU spell within INT-gated level,
            // learned on a successful chance-to-learn roll
            // (PHB p.10). Failure wastes the opportunity (the
            // same spell may be attempted again at the next
            // level — simplification vs PHB's permanent bar).
            if (c.classIndex == 1) {
                int maxLv = spells::maxSpellLevelForInt(
                    c.abilities.int_);
                std::vector<int> cands;
                for (int id = 0; id < spells::SPELL_COUNT;
                     ++id) {
                    const spells::SpellDef& s =
                        spells::spell((spells::SpellId)id);
                    if (s.sclass != spells::SPELL_MU)
                        continue;
                    if (s.level < 1 || s.level > maxLv)
                        continue;
                    if (c.knowsSpell(id)) continue;
                    cands.push_back(id);
                }
                if (!cands.empty()) {
                    int pick = (int)dice.roll(
                        1, (uint32_t)cands.size(), 0) - 1;
                    int sid = cands[pick];
                    const spells::SpellDef& s =
                        spells::spell((spells::SpellId)sid);
                    if (spells::rollChanceToLearn(
                            dice, c.abilities.int_)) {
                        c.knownSpells.push_back(sid);
                        char b2[96];
                        snprintf(b2, sizeof b2,
                                 "%s learns %s!",
                                 c.name.c_str(), s.name);
                        log.add(b2);
                    } else {
                        char b2[96];
                        snprintf(b2, sizeof b2,
                                 "%s fails to comprehend %s.",
                                 c.name.c_str(), s.name);
                        log.add(b2);
                    }
                }
            }
            // XP reaching another level queues the member again
            if (c.level < cap &&
                c.xp >= rules::xpForLevel(c.classIndex,
                                          c.level + 1))
                pendingTraining.push_back(i);
            return i;
        }
        return -1;
    }
};
