// ============================================================================
// Adnd1 - game/party.h
// The career layer: Character (one member durable record) and
// Party (the roster). Moved verbatim from adnd1.cpp, R31; the
// file split that keeps adnd1.cpp to the Win32/GDI shell.
// R33: the MU spellbook lives here (Character::knownSpells);
// level-ups roll the chance-to-learn check (spells/ PHB p.10).
// R34: per-day spell slots - Character::slotsByLevel persists
// across encounters; toActor carries the CURRENT pool (not a
// fresh one), and the app restores it on rest (or descend, to
// keep a loaded/descended company from being stuck dry).
// R44: the career extras - the stronghold (name-level keep),
// the henchman (a hired NPC fighter who fights alongside the
// roster), and the identify economy (scrolls + unidentified
// magic items waiting on a scribe's verdict).
// R45: the hire's career - henchmanXp accrues at a half
// share of awards, level-ups roll his hit die in the app;
// delveGold accumulates the take so the hire's THIRD is
// paid into henchmanPurse on each return to town.
// R46: slot arrays widened to SIX spell levels (the spells::
// tables already carry 6 columns - the L4-6 spell DATA pass
// comes next); the hire's kit can be upgraded to plate
// (henchmanPlate, bought from his own purse); a ship's crew
// can be hired (crewHired - upkeep and a cut of the take).
// ============================================================================

#pragma once

#include "../rules/dice.h"
#include "../rules/character.h"
#include "../rules/classes.h"
#include "../items/items.h"
#include "../ai/actor.h"
#include "../dm/dm.h"
#include "messagelog.h"
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

// R79: carried-stack ceilings. Potions/scrolls pool per party; the
// quiver is per member. Caps keep decades of delve counters inside
// sane ranges (nothing can run away toward int overflow).
static const int CARRIED_CAP = 9999;   // party potions/scrolls
static const int QUIVER_CAP  = 999;    // per-member missileAmmo

// ----------------------------------------------------------------------------
// R80: quiver bundles - per-shot enchant tracking. Bands of {plus,
// count}; the front band fires first (mundane before magic, so
// enchanted shots are spent last), same-plus claims merge, and the
// total stays under QUIVER_CAP.
// ----------------------------------------------------------------------------
struct AmmoBundle {
    int plus  = 0;    // enchant (+1..+3 in III.H bundles)
    int count = 0;    // arrows/bolts in the band
};

inline int quiverTotal(const std::vector<AmmoBundle>& q) {
    int n = 0;
    for (const auto& b : q) n += b.count;
    return n;
}

// the plus of the next shot to fire (front band; 0 = mundane)
inline int quiverNextPlus(const std::vector<AmmoBundle>& q) {
    for (const auto& b : q)
        if (b.count > 0) return b.plus;
    return 0;
}

// add a band (same-plus merge); over-cap trims the TAIL bands first
inline void quiverAdd(std::vector<AmmoBundle>& q, int plus,
                      int count, int cap = QUIVER_CAP) {
    if (count <= 0) return;
    for (auto& b : q)
        if (b.plus == plus) { b.count += count; count = 0; break; }
    if (count > 0) {
        AmmoBundle nb;
        nb.plus = plus;
        nb.count = count;
        q.push_back(nb);
    }
    int over = quiverTotal(q) - cap;
    while (over > 0 && !q.empty()) {
        AmmoBundle& tail = q.back();
        int take = tail.count < over ? tail.count : over;
        tail.count -= take;
        over -= take;
        if (tail.count <= 0) q.pop_back();
    }
}

// consume n shots front-first
inline void quiverConsumeShots(std::vector<AmmoBundle>& q, int n) {
    if (n <= 0) return;
    while (n > 0 && !q.empty()) {
        AmmoBundle& front = q.front();
        int take = front.count < n ? front.count : n;
        front.count -= take;
        n -= take;
        if (front.count <= 0) q.erase(q.begin());
    }
}

// refill the mundane band to n (rest convention: 20 shots)
inline void quiverRestock(std::vector<AmmoBundle>& q, int n) {
    for (auto& b : q)
        if (b.plus == 0) { b.count = n; return; }
    quiverAdd(q, 0, n);
}

// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// R24: Character - the durable career record for one party member.
// The combat Actor is built from this at encounter spawn (toActor)
// and synced back by name when the fight ends.
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// R85: the pack - each member's carried gear slots. Found magic
// gear that nobody equips on the spot is carried here (cap 6);
// the town [E] command equips the best of it, [P] peddles it.
// kind: 0 = weapon (id = items::WeaponId), 1 = armor
// (id = items::ArmorId), 2 = shield (id unused). gp is the sale
// value from the hoard's appraisal; swapped-out kit comes back
// into the pack as a gp 0 keepsake (kept, never sold).
// ----------------------------------------------------------------------------
struct PackItem {
    int kind = 0;
    int id   = 0;
    int plus = 0;
    int gp   = 0;
};

static const int PACK_CAP = 6;

struct Character {
    std::string name;
    rules::AbilityScores     abilities;
    rules::ExceptionalStrength exStr;   // fighter group + STR 18 only
    int  classIndex = 0;
    int  xp   = 0;
    int  level = 1;
    int  hp = 0, maxHp = 0;
    // R97: the gray beard - age at leaving the training
    // hall; grows on the R95 career clock (ageYears).
    // 0 = a v1 save member whose youth is unknown.
    int  startAge = 0;

    items::WeaponInstance weapon;
    items::WeaponInstance rangedWeapon;   // R28: missile slot
    int missileAmmo = 0;   // R35: arrows/bolts/stones on hand
    // R80: the quiver's enchant composition - bands of {plus, count},
    // front band fires first (mundane before magic)
    std::vector<AmmoBundle> quiver;
    items::ArmorInstance  armor;
    bool shield = false;
    // R56: the magic-shield enchant (+1..+5), 0 = mundane. Won
    // from defeated NPC parties; saved as an optional per-member
    // line (v1 saves have none and load as 0).
    int shieldPlus = 0;
    // R81: Ring of Protection AC bonus (0 = none worn)
    int ringPlus = 0;

    // R85: the pack - carried gear awaiting equip or sale
    std::vector<PackItem> pack;

    // R33: MU spellbook - known spell ids (spells::SpellId).
    // Empty for non-MUs (clerics cast freely).
    std::vector<int> knownSpells;

    // R34: per-day spell slots by level (index 0 = spell level
    // 1). Persisted across encounters; restored by rest.
    // R46: widened to 6 levels (L4+ data pending; the spells::
    // slot tables already carry the columns).
    int  slotsByLevel[6] = {0, 0, 0, 0, 0, 0};

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
        // R80: per-shot enchant queue - front band first
        a.ammoQueueLen = 0;
        a.ammoQueuePos = 0;
        for (const auto& b : quiver)
            for (int i = 0; i < b.count && a.ammoQueueLen < 64; ++i)
                a.ammoQueue[a.ammoQueueLen++] = b.plus;
        a.armor  = armor;
        a.shield = shield;
        a.shieldPlus = shieldPlus;   // R56
        a.ringPlus = ringPlus;   // R81
        a.hp     = hp;
        a.maxHp  = maxHp;
        a.morale = dm::MORALE_FANATIC;   // player party never breaks
        // R34: slots persist - toActor carries the CURRENT pool
        // (the app restores it on rest, not per encounter)
        for (int lv = 0; lv < 6; ++lv)
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
// R24: Party - a roster of Characters. Gold and kill counts stay
// party-level (split loot, shared glory); XP/HP/level are per member.
// ----------------------------------------------------------------------------

struct Party {
    int x = 0, y = 0;
    std::vector<Character> members;
    bool formed = false;

    int gold = 0;
    int kills = 0;

    // R93: the career ledger - completed delves, the
    // deepest level ever reached, and the gross gold hauled
    // over the company's life (before shares). delveCount
    // increments on the clean-road RETURN only - a company
    // that never comes back was never a delve in the books.
    int  delveCount   = 0;
    int  deepestLevel = 0;
    long totalGold    = 0;

    // R95: the career calendar - total days the company has
    // been at it (dungeon, trail, sea; town days are free -
    // recovery and trade). One clock across all three time
    // models.
    int  careerDays   = 0;
    int potions = 0;   // R25: shared pool of healing potions
    // R77: carried scrolls (III.B finds; spell study/use is a later
    // round - for now they're held, not sold)
    int scrolls = 0;
    // R43: DMG training - level-ups do NOT take effect until the
    // member trains (1500 gp x new level, simplified flat rate
    // from the DMG p.86 "1,500 x level" convention). Pending
    // promotions queue here (member indices); the app charges
    // gold and promotes in town. Simplification: the hit-die
    // roll is deferred too - the whole level-up waits. XP
    // thresholds still gate normally.
    std::vector<int> pendingTraining;   // member indices awaiting training

    // R44: the stronghold - a member at name level (their class
    // level cap) may build a keep (10,000 gp, a rebuild-scale
    // simplification of the DMG p.83 barony costs; the book's
    // stronghold economics are far larger). Once built it pays
    // rents on every return to town and halves training fees
    // (the keep's masters-at-arms instruct their lord's company).
    bool strongholdBuilt = false;
    int  strongholdOwner = -1;   // member index of the lord

    // R44: the henchman - one hired NPC (DMG p.36 simplified:
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
    // R100: the hire's youth - rolled when he answers the
    // call (a young fighter, the yard age). 0 = an older
    // save's hire, unknown youth.
    int  henchmanStartAge = 0;

    // R45: the hire's career records
    int  henchmanXp    = 0;    // half-share awards
    int  henchmanPurse = 0;    // his third of each delve's take
    int  delveGold     = 0;    // take since the last town visit
    bool henchmanPlate = false;   // R46: plate kit upgrade
    // R103: the raise - a one-time 500 gp grant; his
    // upkeep rises by 100 gp a visit forever (the carrot,
    // DMG p.35). Never taken = false.
    bool henchmanRaise = false;
    // R80: the hire's magic kit - a won sword's enchant and a won
    // magic shield's plus (armor stays the R46 plate ladder)
    int  henchmanWeaponPlus = 0;
    int  henchmanShieldPlus = 0;

    // R86: the hire's pack - the mule slot. Gear the members
    // cannot carry (full packs) is shouldered by the henchman
    // and peddled in town with the rest ([P]). His kit stays
    // fixed (R80) - the pack is cargo, never equipped.
    std::vector<PackItem> henchmanPack;
    bool crewHired     = false;   // R46: a coaster's company
    // R105: the crew's nerve - 0..100, hired at 60. Wages
    // mend it, short purses wear it, and below 25 the
    // crew deserts at port. 0 on an older save = unknown,
    // freshened to 60 on its next wage payment.
    int  crewMorale = 0;

    // R44: identify economy - scrolls (found or bought, 100 gp
    // at the scribe) reveal unidentified magic items. kind 0 =
    // magic weapon (long sword), kind 1 = enchanted armor; the
    // plus was rolled at loot time but stays unknown to the
    // COMPANY until a scroll is read over the item.
    int  identifyScrolls = 0;
    struct PendingItem { int kind = 0; int plus = 0; };
    std::vector<PendingItem> unidentified;

    // R44: the henchman's combat actor (a fighter of his level;
    // fixed average stats keep the hire a one-roll affair -
    // simplification vs the book's rolled applicants)
    // R46: the kit ladder - chain + shield at hire, plate +
    // shield after the [J] upgrade (bought from his purse)
    items::ArmorId party_plate_kit() const {
        return henchmanPlate ? items::ARMOR_PLATE
                             : items::ARMOR_CHAIN_MAIL;
    }

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
        a.weapon.plus = henchmanWeaponPlus;   // R80
        a.armor  = items::ArmorInstance();
        a.armor.id = party_plate_kit();   // PHB p.36 kit ladder
        a.shield = true;
        a.shieldPlus = henchmanShieldPlus;   // R80
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
    // applied per member - a high prime requisite earns a bonus
    // (% of the award), a low one a penalty; the creation screen
    // has shown this % since R24, the award pipe now honors it.
    void gainXp(int amount, rules::Dice& dice, MessageLog& log) {
        (void)dice;   // R43: hit dice roll moved to trainNext
        for (auto& c : members) {
            if (c.hp <= 0) continue;   // the dead earn nothing
            // R30: prime-requisite % (PHB p.20 class notes) -
            // e.g. STR 16+ fighter +10%, STR 9 fighter -20%
            int primeAb = c.abilities.get(
                (rules::Ability)rules::primeRequisite(
                    c.classIndex));
            int pct = rules::primeRequisitePct(
                (uint8_t)primeAb);
            int gained = amount + (amount * pct) / 100;
            if (gained < 0) gained = 0;   // penalty floors at 0
            c.xp += gained;
            // R43: DMG training - a level-up does not take effect
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
                         "%s is due a level - training costs %d "
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

    // R43: promote the first valid queued member - hit die, MU
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
                continue;   // stale entry - try the next
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

            // R33: on a level-up an MU studies one new spell -
            // a random unknown MU spell within INT-gated level,
            // learned on a successful chance-to-learn roll
            // (PHB p.10). Failure wastes the opportunity (the
            // same spell may be attempted again at the next
            // level - simplification vs PHB's permanent bar).
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

// R79: the logistics helpers - ammo bundle claims and carried caps.
// ----------------------------------------------------------------------------
// add to a capped counter; the counter never exceeds cap and can
// still decrease (spending is uncapped)
inline int addCapped(int& cur, int add, int cap) {
    cur += add;
    if (cur > cap) cur = cap;
    return cur;
}

// R79: claim an arrow/bolt bundle into a member's quiver - true when
// the bundle matched the member's RANGED weapon and was pocketed.
// Only enchanted bundles claim ("Arrow +2", "Bolt +1"): the singular
// specials (Arrow of Slaying, Arrow of Direction) stay appraised -
// they are single shots, not quiver fodder. The quiver counts SHOTS;
// per-arrow enchant tracking awaits the real-inventory tranche.
inline bool claimAmmoBundle(Character& c, const std::string& name,
                            int qty) {
    if (qty <= 0 || c.hp <= 0) return false;
    bool arrow = name.find("Arrow") != std::string::npos;
    bool bolt  = name.find("Bolt")  != std::string::npos;
    if (!arrow && !bolt) return false;
    bool enchanted =
        name.find("Arrow +") != std::string::npos ||
        name.find("Bolt +")  != std::string::npos;
    if (!enchanted) return false;
    items::WeaponId id = c.rangedWeapon.id;
    bool fits = (arrow && (id == items::WPN_SHORT_BOW ||
                           id == items::WPN_LONG_BOW)) ||
                (bolt  && id == items::WPN_CROSSBOW_LIGHT);
    if (!fits) return false;
    // R80: bundle-aware - a legacy flat count becomes the mundane
    // band, the enchanted band joins behind it (merged by plus),
    // and the derived total keeps the R79 cap
    if (c.quiver.empty() && c.missileAmmo > 0) {
        AmmoBundle b;
        b.count = c.missileAmmo;
        c.quiver.push_back(b);
    }
    int plus = 0;
    size_t p = name.find('+');
    while (p != std::string::npos) {
        if (p + 1 < name.size() && name[p + 1] >= '0' &&
            name[p + 1] <= '9') {
            plus = name[p + 1] - '0';   // bundles print +1..+3
            break;
        }
        p = name.find('+', p + 1);
    }
    quiverAdd(c.quiver, plus, qty);
    c.missileAmmo = quiverTotal(c.quiver);
    return true;
}

// ----------------------------------------------------------------------------
// R85: the pack helpers
// ----------------------------------------------------------------------------
// R87: the weight of one carried item (gp units, item tables;
// PackItem stores no weight - it is derived, never saved)
inline int packItemWeight(const PackItem& p) {
    if (p.kind == 2) return items::shieldWeightGp();
    if (p.kind == 1) {
        if (p.id < 0 || p.id >= (int)items::ARMOR_COUNT) return 0;
        return items::armor((items::ArmorId)p.id).weightGp;
    }
    if (p.id < 0 || p.id >= (int)items::WPN_COUNT) return 0;
    return items::weapon((items::WeaponId)p.id).weightGp;
}

// R87: total load - worn kit plus pack cargo (gp units)
inline int carriedWeight(const Character& c) {
    int wt = items::equippedWeight(c.weapon, c.armor, c.shield);
    for (const auto& q : c.pack) wt += packItemWeight(q);
    return wt;
}

// carry an item; false when the pack is full (the caller
// appraises) or when the carry would push the member into
// the HEAVY encumbrance band (STR-scaled, PHB p.76 - the
// strong shoulder more; the weak stop sooner)
inline bool packAdd(Character& c, const PackItem& p) {
    if ((int)c.pack.size() >= PACK_CAP) return false;
    if (items::encumbranceBand(carriedWeight(c) +
                                   packItemWeight(p),
                               c.abilities.str) ==
        items::ENC_HEAVY)
        return false;
    c.pack.push_back(p);
    return true;
}

// R87: the hire's load - fixed kit (sword, kit-ladder armor,
// shield) plus his mule cargo
inline int henchmanCarryWeight(const Party& p) {
    int wt = items::weapon(items::WPN_LONG_SWORD).weightGp +
             items::armor(p.party_plate_kit()).weightGp +
             items::shieldWeightGp();
    for (const auto& q : p.henchmanPack) wt += packItemWeight(q);
    return wt;
}

// R87: can the hire shoulder one more item without going
// HEAVY? (his STR is the fixed 12 of the henchmanActor kit)
inline bool henchmanCanShoulder(const Party& p, const PackItem& it) {
    return items::encumbranceBand(henchmanCarryWeight(p) +
                                      packItemWeight(it),
                                  12) != items::ENC_HEAVY;
}

// R89: the coin share - 10 gold coins weigh one gp unit
// (PHB p.101, 10 coins to the pound); the pooled purse is
// split evenly across the LIVING members (the hire is paid,
// not a pack mule for coin). Coins are LIQUID: the packAdd
// gear gate excludes them by design - the burden display,
// the [E] warning and the pace tell the truth instead.
inline int coinWeightShare(const Party& p) {
    int living = 0;
    for (const auto& c : p.members)
        if (c.hp > 0) ++living;
    if (living == 0) return 0;
    return p.gold / (10 * living);
}

// R89: a member's true load - worn kit, pack cargo, and his
// share of the company's coin
inline int memberLoad(const Party& p, const Character& c) {
    return carriedWeight(c) + coinWeightShare(p);
}

// R89: the pace cost of one step, tenths of a turn - a 120'
// company pays 10 (one turn per step, as ever); a 30' company
// pays 40 (four turns of dungeon time crawl past while the
// laden company shuffles, and the halls get four bites at
// the wander check)
inline int paceStepTenths(int moveRate) {
    return 1200 / moveRate;
}

// R89/R90: the shared tick math - charge stepTenths onto the
// debt and return how many whole turns ticked. Kept here (not
// in adnd1.cpp) so the clock model is one function, used by
// the move path and pinned by the regtest.
inline int ticksFromDebt(int& moveDebt, int stepTenths) {
    moveDebt += stepTenths;
    int t = 0;
    while (moveDebt >= 10) {
        moveDebt -= 10;
        ++t;
    }
    return t;
}

// R90: what a camp costs the clock - a completed rest is 48
// turns (PHB: a turn is 10 minutes, so 8 hours of sleep at 6
// turns to the hour); one jumped in ambush is 4 turns of
// watch before the halls come calling. Rest is pace-free:
// sleeping is not movement, no matter the load.
inline int restTurns(bool interrupted) {
    return interrupted ? 4 : 48;
}

// R91: what the stairs cost - 36 turns (6 hours of finding,
// clearing and descending the worn way down; R34's
// "the descent takes hours" made literal). Pace-free like
// rest: the trek is route-finding, not open movement. One
// arrival wander check accompanies it (camp parity).
inline int descentTurns() {
    return 36;
}

// R93: the deepest-depth tracker (career; depth 1 counts -
// a first delve is a delve)
inline int deepestOf(int cur, int level) {
    return level > cur ? level : cur;
}

// R94: the hire's loyalty drift. Range 0..125 (the loader's
// existing bounds); clampLoyalty keeps every drift in range.
inline int clampLoyalty(int loy) {
    if (loy < 0) return 0;
    if (loy > 125) return 125;
    return loy;
}

inline int loyaltyDrift(int loy, int delta) {
    return clampLoyalty(loy + delta);
}

// R94: the career events that move him - a NEW deepest
// record costs 2 (the unlit deeps wear), a completed delve
// pays 3 (shared success, and the purse), a frightened
// watch (interrupted camp or a bitten road) costs 1.
inline int loyaltyDriftDeepDescent() { return -2; }
inline int loyaltyDriftDelveDone()   { return  3; }
inline int loyaltyDriftHardWatch()   { return -1; }

// R103: the carrot (DMG p.35 - gifts and raises recover
// morale). A gift is 25 gp into his purse for +5 loyalty
// (a content man, loyalty 100+, takes no gifts); a raise
// is 500 gp once for +100 gp a visit of upkeep forever
// and +10 loyalty.
inline int loyaltyGift() { return  5; }
inline int loyaltyRaise() { return 10; }
inline int henchmanUpkeep(int level, bool hasRaise) {
    return 100 * level + (hasRaise ? 100 : 0);
}

// R104: the town's scales - every shop asks the same
// question of the purse; this is the single asking (the
// maintenance survey found the guard-and-spend pattern
// repeated across eighteen town shops).
inline bool spendGold(Party& p, MessageLog& log, int cost,
                      const std::string& refusal) {
    if (p.gold < cost) {
        log.add(refusal);
        return false;
    }
    p.gold -= cost;
    return true;
}

// R105: the crew's nerve - the drift that moves it (wages
// mend, a short purse wears, a rich delve's share warms)
// and the floor beneath which the crew deserts at port.
inline int clampCrewMorale(int m) {
    if (m < 0)   return 0;
    if (m > 100) return 100;
    return m;
}
inline int crewDriftPaid()   { return  2; }
inline int crewDriftUnpaid() { return -10; }
inline int crewDriftShare()  { return  3; }
inline int crewHireMorale()  { return  60; }
inline int crewDesertBelow() { return 25; }

// R95: the calendar. A dungeon day is 144 turns (the R89-R92
// coherence bound: 120' unencumbered, 6 turns to the hour);
// the trail and the sea count their own days directly.
inline int turnsPerDay() { return 144; }

inline int dungeonDays(int turnCount) {
    return turnCount / turnsPerDay();
}

// R96: the town clock. Training costs days equal to the
// new level - a fair price for a fair mastery (the 2nd
// rank is two days of drills, the 9th is nine).
inline int trainingDays(int newLevel) {
    return newLevel;
}

// R97: the gray beard. Starting age by class (creation
// convention; PHB book-verify pending): fighters leave the
// yard young, magic-users leave the tower late.
inline int startAgeBase(int classIndex) {
    switch (classIndex) {
        case rules::CLASS_FIGHTER:     return 15;
        case rules::CLASS_MAGIC_USER:  return 24;
        case rules::CLASS_CLERIC:      return 18;
        default:                return 18;   // thief
    }
}

inline int rollStartingAge(int classIndex, rules::Dice& d) {
    if (classIndex == rules::CLASS_MAGIC_USER)
        return startAgeBase(classIndex) + d.roll(2, 8, 0);
    return startAgeBase(classIndex) + d.roll(1, 4, 0);
}

// age today: the starting age plus whole years on the
// career clock (365 days to the year)
inline int ageYears(const Character& c, int careerDays) {
    return c.startAge + careerDays / 365;
}

// R100: the hire's age on the same clock (his youth rolled
// at hire; 0 = unknown - an older save's hire)
inline int hireAgeYears(const Party& p) {
    return p.henchmanStartAge + p.careerDays / 365;
}

// R98: the years tell. Brackets (DMG p.11-12 convention,
// book-verify pending): young < 45, middle 45..59,
// old 60..89, venerable 90+.
inline int ageBracket(int age) {
    if (age < 45) return 0;
    if (age < 60) return 1;
    if (age < 90) return 2;
    return 3;
}

// the bend by bracket: STR/CON/DEX fall 1/2/3, INT/WIS
// rise 1/2/3, CHA is untouched (a face is a face)
inline int ageAbilityDelta(int bracket, rules::Ability a) {
    if (bracket <= 0) return 0;
    int mag = bracket;   // 1/2/3
    switch (a) {
        case rules::ABILITY_STR:
        case rules::ABILITY_CON:
        case rules::ABILITY_DEX:
            return -mag;
        case rules::ABILITY_INT:
        case rules::ABILITY_WIS:
            return mag;
        default:
            return 0;
    }
}

// apply the bracket advance to a member (once, at the
// birthday that crosses into it); clamps 3..18
inline void applyAgeBracket(Character& c, int newBracket) {
    const rules::Ability as[5] = {
        rules::ABILITY_STR, rules::ABILITY_INT,
        rules::ABILITY_WIS, rules::ABILITY_DEX,
        rules::ABILITY_CON };
    for (int i = 0; i < 5; ++i) {
        int d = ageAbilityDelta(newBracket, as[i]);
        if (d == 0) continue;
        int v = (int)c.abilities.get(as[i]) + d;
        if (v < 3)  v = 3;
        if (v > 18) v = 18;
        c.abilities.set(as[i], (uint8_t)v);
    }
}

// R92: the road home - 12 turns per dungeon level (2 hours
// of climbing the worn ways back; the ascent skips the
// clearing and searching the descent spends, hence a third
// of descentTurns per level). Pace-free (stairs parity),
// one road wander check - rolled BEFORE the town switch so
// a followed company fights where it stands.
inline int ascentTurns(int dungeonLevel) {
    return 12 * dungeonLevel;
}

// R88: the company's move rate - the slowest living member's
// band sets the pace (the company moves together); a dead or
// empty party is treated as unencumbered
inline int partyMoveRate(const Party& p) {
    int best = items::movementForBand(items::ENC_UNENCUMBERED);
    for (const auto& c : p.members) {
        if (c.hp <= 0) continue;
        int m = items::movementForBand(
            items::encumbranceBand(memberLoad(p, c),
                                   c.abilities.str));
        if (m < best) best = m;
    }
    return best;
}

// the item's display name, reconstructed from the item tables
// (the save stores only kind/id/plus/gp - names are never saved)
inline std::string packItemName(const PackItem& p) {
    char buf[48];
    if (p.kind == 2) {
        if (p.plus > 0) snprintf(buf, sizeof buf,
                                 "Shield +%d", p.plus);
        else snprintf(buf, sizeof buf, "Shield");
    } else if (p.kind == 1) {
        const char* n = items::armor(
            (items::ArmorId)p.id).name;
        if (p.plus > 0) snprintf(buf, sizeof buf,
                                 "%s +%d", n, p.plus);
        else snprintf(buf, sizeof buf, "%s", n);
    } else {
        const char* n = items::weapon(
            (items::WeaponId)p.id).name;
        if (p.plus > 0) snprintf(buf, sizeof buf,
                                 "%s +%d", n, p.plus);
        else snprintf(buf, sizeof buf, "%s", n);
    }
    return buf;
}

// would the pack item improve the member's kit? Weapons compare
// enchant plus in their own slot (missile weapons look at the
// RANGED slot), armor compares effective AC (plus, DEX and
// shield weighed), shields compare enchant. Strict improvement
// only - equals never swap (no loops).
inline bool packImproves(const Character& c, const PackItem& p) {
    if (c.hp <= 0) return false;
    if (p.kind == 2)
        return !c.shield || c.shieldPlus < p.plus;
    if (p.kind == 1) {
        if (p.id < 0 || p.id >= (int)items::ARMOR_COUNT)
            return false;
        items::ArmorInstance cand;
        cand.id = (items::ArmorId)p.id;
        cand.plus = p.plus;
        int oldAc = items::effectiveAc(
            c.armor, c.shield, c.shieldPlus, c.abilities.dex);
        int newAc = items::effectiveAc(
            cand, c.shield, c.shieldPlus, c.abilities.dex);
        return newAc < oldAc;   // lower = better
    }
    if (p.id < 0 || p.id >= (int)items::WPN_COUNT)
        return false;
    const items::WeaponDef& w =
        items::weapon((items::WeaponId)p.id);
    if (w.missile) return c.rangedWeapon.plus < p.plus;
    return c.weapon.plus < p.plus;
}

// ----------------------------------------------------------------------------
// R81: the ring + scroll-study helpers
// ----------------------------------------------------------------------------
// claim a Ring of Protection for a member (the III.C table prints no
// +N in the name; +1 is the convention - documented simplification
// vs the PHB's +1/+2 brackets). One ring per member, first taker
// wins; every other ring/rod/misc stays appraised.
inline bool claimRing(Character& c, const std::string& name,
                      int qty) {
    if (c.hp <= 0 || qty != 1 || c.ringPlus > 0) return false;
    if (name.find("Ring of Protection") == std::string::npos)
        return false;
    c.ringPlus = 1;
    return true;
}

// ----------------------------------------------------------------------------
// R82: revival helper
// ----------------------------------------------------------------------------
// Raise Dead eligibility: a living 7th+ level cleric (PHB p. 46 -
// clerics gain 5th-level spells at 7th, Raise Dead among them).
inline bool canRaiseDead(const Character& c) {
    return c.classIndex == 2 && c.level >= 7 && c.hp > 0;
}

// R81: the next spell a member could study from a scroll - the
// lowest-level unknown spell of his class in id order
// (deterministic; regtest pins it). -1 when the book is complete.
inline int pickStudySpell(const Character& c) {
    int best = -1;
    int bestLv = 99;
    for (int id = 0; id < spells::SPELL_COUNT; ++id) {
        const spells::SpellDef& s =
            spells::spell((spells::SpellId)id);
        if (c.classIndex == 1 && s.sclass != spells::SPELL_MU)
            continue;
        if (c.classIndex == 2 && s.sclass != spells::SPELL_CLERIC)
            continue;
        if (c.knowsSpell(id)) continue;
        if (s.level < bestLv) { bestLv = s.level; best = id; }
    }
    return best;
}
