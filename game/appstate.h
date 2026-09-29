// ============================================================================
// Adnd1 â game/appstate.h
// The simulation core: room occupancy, treasure, camera, game
// modes, creation state, combat state, and AppState itself.
// Moved verbatim from adnd1.cpp, R31 â no windows.h here; the
// shell (adnd1.cpp) owns the Renderer.
// R33: spellbook wiring â MU starting spell at creation, the
// castable list filters by known spells, and saveGame/loadGame
// grow an optional per-MU "spells" line (v1 saves still load).
// R34: per-day slots â Character::slotsByLevel persists across
// encounters (endCombat sync), [R] rest restores slots + natural
// healing with a wandering-encounter interrupt risk; descend and
// load also refill the pool.
// R35: ammo counting â Character::missileAmmo is the live quiver
// (20 missiles at creation / bow find / load; not persisted in
// v1 saves); each shot spends one (endCombat sync), and a dry
// quiver blocks the shoot command and falls back to melee.
// R36: throw command â combatThrow() has the active member hurl
// their melee weapon (dagger/hand axe/spear): one shot from the
// weapon's own dice/plus, then unarmed 1d2 fists for the rest of
// the encounter (the weapon is recovered afterward â Actor state
// only, nothing persisted).
// R37: monster missile attacks â beginCombat marks missile-armed
// monsters from the monster key (goblin/kobold, MM convention:
// goblins short bow, kobolds sling; key list is verification
// debt â the Lua data files carry no ranged flag); they fire an
// opening volley in round 1, then close to melee.
// R38: arrow restocking â quivers refill wherever slots do:
// a completed rest (restExplore) renews both, and descending
// (descend) restocks at the same time it refills slots. Load
// already refills. Ammo stays a physical resource otherwise â
// wandering-encounter-interrupted rests restore nothing.
// R39: ammo as treasure â victorious room loot can include a
// bundle of arrows (20): added to the quiver of the first living
// missile-armed member, or stockpiled on the least-supplied one
// when everyone is armed. Bows (R28) and arrows now both drop.
// R40: thrown-weapon loot â victorious room loot can include a
// +1 dagger: claimed by the first living member whose melee
// weapon is throwable (dagger/hand axe/spear) or weaker; it can
// be hurled with [t] (R36) at +1 to hit and damage.
// R41: town hub â a new MODE_TOWN screen reached with [B] from
// the dungeon. The temple sells healing potions (50 gp), the
// fletcher sells 20-arrow bundles (30 gp). [B]/Esc returns to
// the dungeon at the same depth. Buying arrows needs a missile-
// armed member (first below 20, else least-supplied â R39
// convention). Saves are not possible in town (mode resets to
// EXPLORE on load).
// R42 (three features): (1) town expansion â the inn sells a
// safe night's rest (10 gp: full slots, quivers, and 1 hp/level
// healing, NO wander check), the temple heals the most-wounded
// member to full (100 gp), the smith sells +1 long swords
// (500 gp, first living fighter); (2) movement + range bands â
// missile fire is bounded by the weapon's short range
// (rangeTens*10 feet, PHB p.39); the round-1 volley lasts
// rangeBandsOf() rounds before melee closes (1 band = 10' range
// factor);(3) dungeon scaling â monster lair sizes and treasure
// gold now scale with depth (cap 2+level/2, gold multiplier
// 100%+25%/level above 1).
// R43 (three features): (1) DMG training â level-ups queue
// (Party::pendingTraining) until the member trains at the town
// hall ([6], 1500 gp x new level); promotion logic moved from
// gainXp to Party::trainNext (hit die + R33 MU spell study);
// queue persists in saves via an optional "training" line
// (v1-compatible); (2) party-side range â the encounter carries
// an abstract distance (5 bands, closes 1/round); [x] shoot is
// refused once the range closes (thrown weapons exempt);
// (3) town stock â [7] chain mail (75 gp, first armored-eligible
// member in worse), [8] spell scroll (200 gp, one random unknown
// L1 MU spell added to the first MU's book).
// R44 (five features): (1) stronghold â a name-level member
// (level == class cap) builds a keep ([0], 10,000 gp); rents
// (200 gp) collect on every return to town and training is
// halved while it stands; (2) identify scrolls â treasure can
// yield scrolls and UNIDENTIFIED magic items (plus rolled but
// hidden); the scribe sells scrolls ([9], 100 gp) and [I] reads
// one over the first pending item, applying weapon or armor
// enchant; (3) henchman â [H] posts a 100 gp offer (DMG p.36
// simplified); on acceptance a level-1 fighter joins as an
// extra party actor (chain + shield kit), upkeep 100 gp/level
// bills each return to town, loyalty (50 + best Cha reaction
// adj) is checked on descending â a failed roll loses the hire;
// (4) monster roster expansion â six new Lua bestiary files
// (bandit, wolf, hobgoblin, gnoll, lizard man, bugbear) and
// hobgoblin joins the missile-armed key list; (5) town hub
// polish â a company status panel (roster, henchman, keep,
// scrolls) beside the shop menu.
// R45 (five features): (1) henchman advancement and shares â
// the hire earns a half share of combat XP, levels (hit die
// d10+1) at fighter thresholds, and takes a THIRD of each
// delve's gold (accumulated in delveGold, paid into his
// purse on every return to town); (2) sage and spy consults â
// [S] 200 gp lists what lairs at this depth (the registry
// roster, an in-game MM reference), [Y] 500 gp reveals the
// CURRENT occupied rooms and their monster keys (simple
// recon, DMG p.35 spying simplified); (3) the peddler [M] â
// 500 gp for one random identified magic item (weapon +1,
// armor +1, three potions, two identify scrolls, or a spell
// scroll); (4) traps and secret doors â unoccupied rooms may
// hide a dart trap (save vs death or 2d6; a thief in the
// company may spot and disarm it first), walls hide secret
// doors found with [F] search (1-in-6, thief 3-in-6; found
// doors become ordinary doors); (5) MM reference â the sage
// consult doubles as the bestiary lore service (true book
// verification still awaits the re-uploaded MM PDF).
// R46 (six features): (1) NPC dialogue — [T] in town talks
// with the locals (state-aware tavern chatter: hints about
// pending training, unidentified loot, the hire, the keep,
// and depth rumors); (2) psionics hook — Actor::psionic
// (app-flagged by monster key, R37 pattern): a once-per-
// encounter mind blast stuns a party member unless they
// save vs spells; the mind flayer (new Lua file) carries
// it; (3) henchman kit — [J] upgrades the hire to plate
// (100 gp from HIS purse, not the company's gold); (4)
// ship crew — [C] hires a 20-sailor coaster's company
// (200 gp down); upkeep 40 gp each return, and the crew
// takes 5% of every delve's take at the exit; (5) room
// flavor — entering a room the first time describes it
// (state-aware: occupied/trapped/looted/swept variants);
// (6) L4+ spell slots — all slot arrays widened to 6
// levels (the spells:: tables carry the columns; the L4-6
// spell DATA pass is next — it needs the current spells/
// files read back).
// R52: the real DMG Appendix C dungeon tables — dm/encounters.
// {h,cpp} carry the Determination Matrix, Monster Level Tables
// I-X, per-level Dragon Subtables (the Age Category column is
// hit points per die), and the Human Subtable, OCR-verified
// against the uploaded DMG (Premium reprint p.174-179). Room
// lairs and wandering encounters roll from the tables; hydra
// groups and dragon pairs keep the DMG head/age ranges per
// specimen; the sage reads the table roster (dm::encounterKeys).
// Character Subtable parties (classed NPCs) are R53.
// R53: the Character Subtable (DMG p.176) — party members are
// real classed combatants (the ai::Actor character path: class
// THAC0, armor AC, saves). Professions map to the engine's four
// classes per the DMG's closest-approximation advice (druid ->
// cleric, paladin/ranger -> fighter, illusionist -> magic-user,
// assassin/bard -> thief, monk -> fighter). Levels follow the
// book (dungeon/monster level through 4th, then d6+6 adjusted
// toward the dungeon level); 2-5 characters plus men-at-arms
// (dungeon levels 1-3) or classed henchmen at 1/3 the master's
// level (4+) round the party to nine. NPC parties wander; room
// lairs stay monsters. Party kills pay the by_level XP ladder
// (xp::xpForNpc) with the specimen's actual hp. Simplification:
// average abilities (PERSONAE-grade generation is a later round).
// R58: NPC-party reaction & parley (DMG p.63 Encounter
// Reactions + p.176 Confrontation): wandering Character Subtable
// parties now roll percentile + spokesman-Cha adjustment before
// combat — hostile bands attack, uncertain ones dice it,
// friendly ones pass by or share word of the dungeon (never
// joining, per p.176). A party that feels weak gets +10 to avoid
// or bluff (p.176). Also fixes a leftover placeholder glitch in
// the R57 header note.
// R57: PERSONAE-grade NPC abilities (DMG p.87 + p.176): 3d6
// per score, race (p.176 table) and class (p.87 table) ability
// adjustments, exceptional strength for fighters at STR 18, and
// hp by the canonical per-level rollHitPoints with the rolled
// Con adjustment (men-at-arms: the p.87 Mercenary row —
// STR +1, CON +3, 4 minimum hp). The R53 average-10 convention
// is retired.
// R55: NPC parties roll magic items (DMG p.176-177 Tables I-IV
// level-chance ladder): weapon/armor/shield pluses land on the
// equipped Actor gear; unmodeled devices are fiction-only.
// R56: the gear is LOOTABLE â victory over a wandering NPC
// party strips the best enchanted weapon/armor/shield from the
// slain (claim conventions: same-weapon first, then equal-or-
// better damage; armor by class weight rules; shields by
// shieldAllowed) and a coin purse with treasure xp. The magic
// shield persists: Character::shieldPlus (optional save line,
// v1 compatible).
// R54: NPC spellcasters CAST — one foe caster per round,
// side-aware targeting, cleric heal-first AI, MU sleep opener
// then fireball at 3rd-level slots (ai/actor.cpp foeSpellChoice).
// ============================================================================================================================================

// R68: overland travel — the DMG Appendix C outdoor play loop
// (p.182-183, wired to the R63/R67 builders). From town, [O] sets
// out; each day is a march ([T] outward, [H] homeward) across a
// player-chosen terrain, with a night camp ([C]) that heals if
// undisturbed. The DMG leaves the check cadence to the DM
// ("whenever an encounter is indicated") — this campaign checks
// once per march day and once per night camp (documented
// fiction). The first three days from town are the INHABITED
// band (OC_TEMPERATE_INHABITED tables, patrols 5 in 20,
// DMG p.182); beyond it the WILDS (OC_TEMPERATE_WILD — the
// campaign's fixed clime is temperate, the other climate sets
// are the R63 module's for other campaigns, documented). In the
// wilds 1 in 20 encounters discover a STRONGHOLD (p.182):
// Castle Table I -> awareness (the p.183 surprise die; an
// unaware party chooses [A]pproach or [P]ass, an aware one is
// met) -> Table II -> totally deserted (a safe night's shelter,
// fiction), deserted (the p.183 "roll the OUTDOOR ENCOUNTER
// TABLE, ignoring men" monster — the Men Subtable keys are the
// R63 set), humans (Sub-Table II.A bandits/berserkers/
// dervishes, MM numbers via the registry), or character-types
// (Sub-Table II.B master + 2-5 henchmen, R67 builders). Patrol
// and garrison meetings roll the R58 party reaction (p.176
// Confrontation); peaceful friendly garrisons grant shelter,
// wilderness character parties may part with favors (R62
// convention). Combat returns to the travel mode it began from
// (endCombat restores the pre-combat mode). Saves are not
// possible on the trail (the town convention, R41); load
// returns to the dungeon.
// R70: sea travel + the city streets. [V] from town sets sail
// with the hired crew (R46 crewHired; the coaster of the R46
// ship-crew feature now carries the party): MODE_SEA, a day's
// sail [T]/[H] rolls the R60 salt-water tables — coastal
// waters (SHALLOW, the first kSeaCoastalDays) then the open
// sea (DEEP), clime COOL (temperate waters, campaign fiction)
// — with [C] anchoring for the night (the R34/R38 rest). A
// landfall bills the town visit like any return. [W] from
// town walks the streets: MODE_CITY, [1] a daytime excursion
// and [2] a nighttime one, each a single roll on the R64
// city matrix — classed/service parties meet by the p.176
// Confrontation (the R68 meeting builder), registry monsters
// fight, civilians are flavor (R64 fiction rows, printed
// counts, no stats — documented). The R41+ "every return to
// town" billing (rents, upkeep, shares, wages) is extracted
// to billTownVisit() and now bills EVERY arrival — the R68
// overland return previously bypassed it (documented fix).
#pragma once

#include "../world/map.h"
#include "../rules/dice.h"
#include "../rules/character.h"
#include "../rules/classes.h"
#include "../rules/saves.h"   // R45: trap saves
#include "../rules/combat.h"   // R61: monsterEffectiveLevel (p.86 guard rule)
#include "../dm/dm.h"
#include "../dm/dungeon.h"
#include "../dm/encounters.h"   // R52: Appendix C tables
#include "../ai/actor.h"
#include "../monsters/MonsterRegistry.h"
#include "../monsters/MonsterXp.h"
#include "../items/items.h"
#include "../spells/spells.h"

#include "messagelog.h"
#include "party.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

using namespace world;

// ----------------------------------------------------------------------------
// Room occupancy
// ----------------------------------------------------------------------------

struct RoomOccupant {
    int         roomIndex = -1;
    std::string monsterKey;
    int         count = 0;
    int         denX = 0, denY = 0;
    bool looted = false;
    // R45: 0 = no trap, 1 = armed dart trap, 2 = sprung
    int trap = 0;
    bool flavorSeen = false;   // R46: first-entry description
    // R52: DMG Appendix C ranges — hydra heads per specimen,
    // dragon age bracket (hp/die) per specimen
    int headsLo = 0, headsHi = 0;
    int ageLo = 0, ageHi = 0;
};

// R45: a secret door hides in a wall tile until found
struct SecretDoor {
    int  x = 0, y = 0;
    bool found = false;
};

// R61: DMG p.86 treasure XP guard rule. Gold converts 1 gp =
// 1 xp only when the guardian's relative value equals or
// exceeds the party's; a relatively weaker guardian awards on
// the printed sliding scale (5:4, 3:2, 2:1, 3:1, "4 or more to
// 1"). The book calls the comparison subjective ("must be based
// upon the degree of challenge"); this engine's proxy is
// average party level vs the guardian's average effective
// level — the book's own worked example is exactly this
// arithmetic (a 10th-level magic-user vs half-HD kobolds =
// "about 20 to 1"). An unguarded hoard (no monster key) awards
// 1:1; the delve itself was the challenge.
inline int treasureXpForGold(int gold, double partyAvgLevel,
                              double guardianAvgLevel) {
    if (gold <= 0) return 0;
    double r = (guardianAvgLevel > 0.0)
             ? partyAvgLevel / guardianAvgLevel : 1.0;
    double rate;                       // xp per gp
    if      (r <= 1.0)  rate = 1.0;    // equal or stronger guardian
    else if (r <= 1.25) rate = 4.0 / 5.0;
    else if (r <= 1.5)  rate = 2.0 / 3.0;
    else if (r <= 2.0)  rate = 1.0 / 2.0;
    else if (r <= 3.0)  rate = 1.0 / 3.0;
    else                rate = 1.0 / 4.0;  // "4 or more to 1"
    return (int)(gold * rate + 0.5);
}

struct Occupancy {
    std::vector<RoomOccupant> rooms;

    void init(const dm::DungeonResult& d) {
        rooms.clear();
        rooms.resize(d.rooms.size());
        for (size_t i = 0; i < d.rooms.size(); ++i) {
            rooms[i].roomIndex = (int)i;
            rooms[i].denX = (d.rooms[i].x + d.rooms[i].w / 2);
            rooms[i].denY = (d.rooms[i].y + d.rooms[i].h / 2);
        }
    }
};

// ----------------------------------------------------------------------------
// Treasure
// ----------------------------------------------------------------------------

struct Treasure {
    int  gold = 0;
    bool potionHealing = false;
    bool magicSword = false;
    bool missileWeapon = false;   // R28: short bow find
    bool ammoBundle = false;      // R39: 20 arrows on the ground
    bool thrownDagger = false;    // R40: +1 dagger find
    bool identifyScroll = false;  // R44: scroll of identify
    bool unidentifiedItem = false;   // R44: magic item, unknown

    bool empty() const {
        return gold == 0 && !potionHealing && !magicSword &&
               !missileWeapon && !ammoBundle && !thrownDagger &&
               !identifyScroll && !unidentifiedItem;
    }
};

struct Camera {
    int x = 0, y = 0;
    void follow(const Party& p) {
        x = p.x - VIEW_TILES_X / 2;
        y = p.y - VIEW_TILES_Y / 2;
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x > MAP_TILES_X - VIEW_TILES_X) x = MAP_TILES_X - VIEW_TILES_X;
        if (y > MAP_TILES_Y - VIEW_TILES_Y) y = MAP_TILES_Y - VIEW_TILES_Y;
    }
};

// ----------------------------------------------------------------------------
// Game modes
// ----------------------------------------------------------------------------

enum GameMode : int {
    MODE_CREATE = 0,   // R24: character creation
    MODE_EXPLORE,
    MODE_COMBAT,
    MODE_TOWN,         // R41: shops between dives
    MODE_OVERLAND,     // R68: wilderness travel
    MODE_SEA,          // R70: sea voyage (R60 salt-water tables)
    MODE_CITY,         // R70: city streets (R64 matrix)
};

// ----------------------------------------------------------------------------
// R24: Creation state â ROLL -> CLASS -> NAME, per member.
// Uses its own RNG stream so dungeon/sim determinism is untouched.
// ----------------------------------------------------------------------------

enum CreationStage : int {
    CR_ROLL = 0,
    CR_CLASS,
    CR_NAME,
};

struct CreationState {
    CreationStage stage = CR_ROLL;

    rules::Rng  creationRng{1};
    rules::Dice creationDice{creationRng};

    rules::AbilityScores rolled;
    int  classPick = 0;              // highlighted class row
    std::string nameBuf;

    int partySizeCap = PARTY_DEFAULT;
    bool done = false;               // finished -> begin delve

    void rollFresh() {
        rolled = rules::rollAbilities(creationDice,
                                      rules::GEN_4D6_DROP);
        stage = CR_ROLL;
        classPick = 0;
        nameBuf.clear();
    }

    // eligibility: prime requisite score meets the class minimum
    bool classEligible(int classIndex) const {
        int ab = rolled.get(
            (rules::Ability)rules::primeRequisite(classIndex));
        return ab >= rules::classMinAbility(classIndex);
    }

    // finalize the pending member with the chosen class
    Character makeMember(int classIndex) {
        Character c;
        c.abilities = rolled;
        c.classIndex = classIndex;
        c.level = 1;

        // exceptional strength: fighter group at STR 18
        if (classIndex == rules::CLASS_FIGHTER &&
            rolled.str == 18) {
            c.exStr.has = true;
            c.exStr.pct = rules::rollExceptionalStrength(creationDice);
        }

        // level-1 hit points (canonical signature, R4b)
        int conAdj = rules::conHPAdjustment(classIndex, rolled.con);
        c.hp = c.maxHp = rules::rollHitPoints(classIndex, 1,
                                              conAdj, creationDice);

        // R34: casters start with their full level-1 slot pool
        if (classIndex == 1 || classIndex == 2) {
            spells::SpellClass sc = classIndex == 1
                ? spells::SPELL_MU : spells::SPELL_CLERIC;
            for (int lv = 1; lv <= 6; ++lv)   // R46: 6 levels
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(sc, 1, lv);
        }

        // R33: the MU starts with one random L1 spell in the book
        // (PHB: a beginning magic-user has a single first-level
        // spell; rebuild picks it by lot)
        if (classIndex == 1) {
            std::vector<int> l1;
            for (int id = 0; id < spells::SPELL_COUNT; ++id) {
                const spells::SpellDef& s =
                    spells::spell((spells::SpellId)id);
                if (s.sclass == spells::SPELL_MU && s.level == 1)
                    l1.push_back(id);
            }
            if (!l1.empty()) {
                int pick = (int)creationDice.roll(
                    1, (uint32_t)l1.size(), 0) - 1;
                c.knownSpells.push_back(l1[pick]);
            }
        }

        // default equipment per class (R24 decision; respects
        // classes armorAllowed/shieldAllowed by construction)
        switch (classIndex) {
            case rules::CLASS_FIGHTER:
                c.weapon.id = items::WPN_LONG_SWORD;
                c.armor.id  = items::ARMOR_PLATE;
                c.shield    = true;
                break;
            case rules::CLASS_MAGIC_USER:
                c.weapon.id = items::WPN_DAGGER;
                c.armor.id  = items::ARMOR_NONE_EQUIPPED;
                c.shield    = false;
                break;
            case rules::CLASS_CLERIC:
                c.weapon.id = items::WPN_MACE;
                c.armor.id  = items::ARMOR_CHAIN_MAIL;
                c.shield    = true;
                break;
            case rules::CLASS_THIEF:
                c.weapon.id = items::WPN_SHORT_SWORD;
                c.armor.id  = items::ARMOR_LEATHER;
                c.shield    = false;
                // R28: thieves start with a sling (PHB missile)
                c.rangedWeapon.id = items::WPN_SLING;
                break;
        }
        // R35: everyone starts with a full quiver (20 missiles)
        c.missileAmmo = 20;
        return c;
    }
};

// ----------------------------------------------------------------------------
// Combat state â interactive, commands wired to the driver (R21).
// R24: one target selection PER PARTY MEMBER (keyed by actor name
// in the hook), plus an active-member cursor for command entry.
// ----------------------------------------------------------------------------

struct CombatState {
    std::unique_ptr<ai::Encounter> encounter;
    int  lastResult = -1;
    bool over = false;

    std::vector<int> selectedTargets;   // per party member, foe index
    std::vector<std::string> memberNames;   // snapshot at start
    int  activeMember = 0;

    // R27: spell menu (opened with [C] for the active member)
    bool spellMenuOpen = false;

    void start(std::vector<ai::Actor> party, std::vector<ai::Actor> foes,
               uint64_t seed) {
        memberNames.clear();
        for (const auto& a : party)
            memberNames.push_back(a.name);
        selectedTargets.assign(party.size(), 0);
        activeMember = 0;
        spellMenuOpen = false;

        encounter = std::make_unique<ai::Encounter>(
            std::move(party), std::move(foes), seed);
        lastResult = -1;
        over = false;

        // R24: the hook receives the attacking member; we look up
        // that member's own target selection by name (names are
        // unique â creation enforces it)
        encounter->setPlayerTargetHook(
            [this](const ai::Actor& attacker,
                   const std::vector<ai::Actor>& foes) {
                for (int i = 0; i < (int)memberNames.size(); ++i) {
                    if (memberNames[i] != attacker.name) continue;
                    int t = selectedTargets[i];
                    if (t >= 0 && t < (int)foes.size() &&
                        foes[t].alive())
                        return t;
                    break;   // fall through to front-most
                }
                for (int i = 0; i < (int)foes.size(); ++i)
                    if (foes[i].alive()) return i;
                return 0;
            });
    }

    bool step() {
        if (!encounter || over) return true;
        lastResult = encounter->stepRound();
        if (lastResult != -1) over = true;
        return over;
    }

    void requestFlee() {
        if (encounter && !over)
            encounter->requestFlee();
    }

    int livingPartyCount() const {
        if (!encounter) return 0;
        int n = 0;
        for (const auto& a : encounter->party())
            if (a.alive()) ++n;
        return n;
    }

    // cycle the ACTIVE MEMBER's target among living foes
    int cycleTarget(int dir) {
        if (!encounter) return 0;
        if (activeMember < 0 ||
            activeMember >= (int)selectedTargets.size())
            return 0;
        const auto& mons = encounter->monsters();
        int n = (int)mons.size();
        if (n == 0) return 0;
        int& sel = selectedTargets[activeMember];
        for (int hop = 1; hop <= n; ++hop) {
            int cand = (sel + dir * hop + n * 8) % n;
            if (mons[cand].alive()) {
                sel = cand;
                break;
            }
        }
        return sel;
    }

    // cycle which party member receives commands (Q/E)
    int cycleMember(int dir) {
        if (!encounter) return activeMember;
        const auto& party = encounter->party();
        int n = (int)party.size();
        if (n == 0) return activeMember;
        for (int hop = 1; hop <= n; ++hop) {
            int cand = (activeMember + dir * hop + n * 8) % n;
            if (party[cand].alive()) {
                activeMember = cand;
                break;
            }
        }
        return activeMember;
    }

    // R27: spells the ACTIVE member can cast right now â right
    // class, level gate (MU: INT, cleric: class level), and at
    // least one slot remaining at that spell's level. The MU list
    // is the full registry for now (chance-to-learn is deferred,
    // logged simplification).
    std::vector<spells::SpellId> castableSpells() const {
        std::vector<spells::SpellId> out;
        if (!encounter || over) return out;
        if (activeMember < 0 ||
            activeMember >= (int)memberNames.size())
            return out;
        const ai::Actor& a = encounter->party()[activeMember];
        if (!a.isCaster()) return out;

        int maxLv = 0;
        if (a.classIndex == 1)   // MU: INT gates spell level
            maxLv = spells::maxSpellLevelForInt(a.intel);
        else
            maxLv = spells::maxSpellLevelForClericLevel(a.level);

        bool mu = (a.classIndex == 1);
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)id);
            if (s.sclass != (mu ? spells::SPELL_MU
                                : spells::SPELL_CLERIC))
                continue;
            if (s.level < 1 || s.level > 3) continue;
            if (s.level > maxLv) continue;
            if (a.slotsByLevel[s.level - 1] <= 0) continue;
            // R33: MUs cast only what their book holds (cleric
            // prayers remain free)
            if (mu && !a.knowsSpell(id)) continue;
            out.push_back((spells::SpellId)id);
        }
        return out;
    }
};

// ----------------------------------------------------------------------------
// App state
// ----------------------------------------------------------------------------

// ---- R68: overland travel state -------------------------------------------

// A discovered stronghold awaiting the party's decision. The
// Table II percentile is rolled at discovery and kept for the
// approach, so [A]/[P] resolve the same castle.
struct OverlandCastle {
    bool                  pending = false;
    dm::CastleType        type{};
    dm::CastleAwareness   aware = dm::CASTLE_UNDETECTED;
    int                   pctile = 0;   // Table II roll
};

struct OverlandState {
    int           day = 0;        // days on the trail
    int           daysOut = 0;    // 0 = in town; 1+ = leagues out
    bool          homeward = false;
    int           terrain = dm::T_PLAIN;   // the route's column
    OverlandCastle castle;
};

// The inhabited band: the first kOverlandInhabitedDays of the
// journey are patrolled civilized lands (documented fiction —
// the DMG divides outdoor play into inhabited/patrolled and
// uninhabited/wilderness sets, p.182).
static const int kOverlandInhabitedDays = 3;

// R63 terrain names for the travel screen ([1-8] route choice)
inline const char* overlandTerrainName(int t) {
    switch (t) {
        case dm::T_PLAIN:     return "plains";
        case dm::T_SCRUB:     return "scrub";
        case dm::T_FOREST:    return "forest";
        case dm::T_ROUGH:     return "rough";
        case dm::T_DESERT:    return "desert";
        case dm::T_HILLS:     return "hills";
        case dm::T_MOUNTAINS: return "mountains";
        case dm::T_MARSH:     return "marsh";
    }
    return "plains";
}

// The p.183 deserted-castle rule: "roll on the appropriate
// OUTDOOR ENCOUNTER TABLE, ignoring any rolls which indicate
// men." The men are the R63 Men Subtable keys (encounters.cpp
// kOutMen: bandit, berserker, brigand->bandit, dervish,
// nomad->dervish, merchant, pilgrim, caveman) and its Character
// row (a wilderness character party isParty).
inline bool overlandIndicatesMen(const dm::DungeonEncounter& e) {
    if (e.isParty) return true;   // Men Subtable Character row
    return e.key == "bandit"   || e.key == "berserker" ||
           e.key == "dervish"  || e.key == "merchant" ||
           e.key == "pilgrim"  || e.key == "caveman";
}

// ---- R70: sea + city travel state ----------------------------------------

// The voyage: coastal waters (SHALLOW) for the first
// kSeaCoastalDays days out, the open sea (DEEP) beyond —
// DMG p.179 prints salt-water shallow "to 100'", and the
// coastal/open-sea split is this campaign's fiction.
static const int kSeaCoastalDays = 2;

struct SeaState {
    int day = 0;        // days on the water
    int daysOut = 0;    // 0 = in port; 1+ = at sea
    bool homeward = false;
};

// R64 fiction civilians: printed counts, no bestiary stats
// (encounters.cpp documents) — city encounters with these
// keys are flavor only. One line each; count is unused.
inline const char* cityFlavor(const char* k) {
    if (!k) return "The streets are busy.";
    if (std::string(k) == "beggar")     return "Beggars hold out their hands.";
    if (std::string(k) == "drunk")      return "A drunk sings loud in a doorway.";
    if (std::string(k) == "goodwife")   return "A goodwife hurries past with her basket.";
    if (std::string(k) == "harlot")     return "A woman of the evening waves from a doorway.";
    if (std::string(k) == "laborer")    return "Laborers trudge past with their tools.";
    if (std::string(k) == "peddler")    return "A peddler cries his wares.";
    if (std::string(k) == "gentleman")  return "A gentleman tips his hat.";
    if (std::string(k) == "noble")     return "A noble's palanquin shoulders past.";
    if (std::string(k) == "mercenary")  return "Mercenaries lounge by a tavern door.";
    if (std::string(k) == "merchant")  return "A merchant haggles over a crate of goods.";
    if (std::string(k) == "pilgrim")    return "Pilgrims chant at a shrine.";
    if (std::string(k) == "press_gang") return "Sailors shadow you - a press gang eyes the strong.";
    if (std::string(k) == "ruffian")    return "Ruffians melt into an alley as the watch turns.";
    if (std::string(k) == "tradesman")  return "Tradesmen call from their shopfronts.";
    if (std::string(k) == "bard")       return "A bard strums in the square.";
    return "The streets are busy.";
}

struct AppState {
    // world
    Map           map;
    dm::DungeonResult dungeon;
    Occupancy     occupancy;
    Party         party;
    Camera        cam;
    MessageLog    log;
    int           turnCount = 0;
    uint64_t      seed = 1;
    int           dungeonLevel = 1;
    rules::Rng    rng{1};
    rules::Dice   dice{rng};
    dm::WanderConfig wander;

    // systems
    monsters::MonsterRegistry registry;

    // R24: creation
    CreationState creation;
    GameMode      mode = MODE_CREATE;

    // combat
    CombatState combat;
    // R68: combat returns to the mode it began from (explore or
    // the overland trail); the town precedent keeps saves
    // explore-only, so this is never persisted.
    GameMode combatReturnMode = MODE_EXPLORE;
    // R68: the journey
    OverlandState overland;
    // R70: the voyage
    SeaState sea;
    int         combatRoomIndex = -1;
    std::string combatMonsterKey;
    // R51: one context PER FOE (each dragon rolls its own age);
    // awardVictory indexes by slain-monster position
    std::vector<monsters::xp::SpawnContext> foeCtxs;

    // R23: stairs down â placed in the room farthest from entry
    int stairsX = -1, stairsY = -1;

    // R45: the level's hidden doors
    std::vector<SecretDoor> secretDoors;

    void newDungeon(uint64_t s) {
        seed = s;
        dungeon = dm::generateDungeon(s);
        map = dungeon.map;
        occupancy.init(dungeon);
        // R24: no formDefault â the roster comes from creation
        party.x = dungeon.entryX;
        party.y = dungeon.entryY;
        cam.follow(party);
        turnCount = 0;
        rng.seed(s * 7919 + 13);

        placeStairs();
        populateRooms();
        placeSecretDoors();   // R45

        char buf[96];
        snprintf(buf, sizeof buf,
                 "Level %d: %d rooms, %d occupied.",
                 dungeonLevel, (int)dungeon.rooms.size(),
                 countOccupied());
        log.add(buf);
    }

    // R24: creation is finished â the delve begins
    void beginDelve() {
        party.formed = true;
        creation.done = true;
        mode = MODE_EXPLORE;
        newDungeon(1);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "The party of %d descends into the dungeon.",
                 (int)party.members.size());
        log.add(buf);
    }

    // R24: full reset after a wipe â back to creation, career gone
    void resetToCreation() {
        party = Party{};
        // R69: CreationState is non-copyable (its Dice holds a
        // reference to creationRng) — reset fields explicitly
        // instead of assigning a fresh temporary.
        creation.stage = CR_ROLL;
        creation.classPick = 0;
        creation.nameBuf.clear();
        creation.partySizeCap = PARTY_DEFAULT;
        creation.done = false;
        creation.rollFresh();
        dungeonLevel = 1;
        mode = MODE_CREATE;
        log.add("The party is no more. Roll a new company.");
    }

    // ----------------------------------------------------------------
    // R29: save/load. Plain-text career file "adnd1.sav" in the
    // working directory. The COMPANY is saved, not the floor: no
    // dungeon layout, occupancy, or combat state persists â loading
    // regenerates a fresh dungeon at the saved depth (the
    // deterministic newDungeon pipeline). Format: one token stream,
    // version-tagged; unknown/short files are rejected cleanly.
    // ----------------------------------------------------------------
    static const char* SAVE_FILE() { return "adnd1.sav"; }

    bool saveGame() {
        if (!party.formed || party.members.empty()) {
            log.add("No company to save yet.");
            return false;
        }
        FILE* f = fopen(SAVE_FILE(), "w");
        if (!f) {
            log.add("Cannot open adnd1.sav for writing!");
            return false;
        }
        fprintf(f, "ADND1 %d\n", 1);   // format version
        fprintf(f, "party %d\n",
                (int)party.members.size());
        fprintf(f, "gold %d kills %d potions %d depth %d\n",
                party.gold, party.kills, party.potions,
                dungeonLevel);
        // R43: the training queue (v1 saves lack this line â the
        // loader treats it as optional)
        fprintf(f, "training %d",
                (int)party.pendingTraining.size());
        for (int i : party.pendingTraining)
            fprintf(f, " %d", i);
        fprintf(f, "\n");
        // R44: career extras (optional lines, v1-compatible â
        // the loader's optional-tag chain treats each as absent
        // in older saves)
        fprintf(f, "stronghold %d %d\n",
                party.strongholdBuilt ? 1 : 0,
                party.strongholdOwner);
        if (party.henchmanPresent)
            fprintf(f, "henchman %d %d %d %d %d %d %d %s\n",
                    party.henchmanHp, party.henchmanMaxHp,
                    party.henchmanLevel, party.henchmanLoyalty,
                    party.henchmanXp, party.henchmanPurse,
                    party.delveGold,
                    party.henchmanName.c_str());
        else
            fprintf(f, "henchman 0\n");
        fprintf(f, "idscrolls %d\n", party.identifyScrolls);
        fprintf(f, "items %d",
                (int)party.unidentified.size());
        for (const auto& it : party.unidentified)
            fprintf(f, " %d %d", it.kind, it.plus);
        fprintf(f, "\n");
        for (const auto& c : party.members) {
            fprintf(f,
                "member %s %d %d %d %d %d\n",
                c.name.c_str(), c.classIndex, c.xp, c.level,
                c.hp, c.maxHp);
            fprintf(f, "abil %d %d %d %d %d %d %d %d\n",
                (int)c.abilities.str, (int)c.abilities.int_,
                (int)c.abilities.wis,  (int)c.abilities.dex,
                (int)c.abilities.con,  (int)c.abilities.cha,
                c.exStr.has ? 1 : 0, c.exStr.pct);
            fprintf(f, "gear %d %d %d %d %d %d %d\n",
                (int)c.weapon.id, c.weapon.plus,
                (int)c.rangedWeapon.id, c.rangedWeapon.plus,
                (int)c.armor.id, c.armor.plus,
                c.shield ? 1 : 0);
            // R56: the magic-shield enchant (nonzero only â
            // v1 saves carry no line and load as 0)
            if (c.shieldPlus > 0)
                fprintf(f, "shieldplus %d\n", c.shieldPlus);
            // R33: the MU spellbook (one line per MU; other
            // classes write nothing â v1 saves stay readable)
            if (c.classIndex == 1) {
                fprintf(f, "spells %d",
                        (int)c.knownSpells.size());
                for (int s : c.knownSpells)
                    fprintf(f, " %d", s);
                fprintf(f, "\n");
            }
        }
        fclose(f);
        log.add("The company is recorded (adnd1.sav).");
        return true;
    }

    bool loadGame() {
        FILE* f = fopen(SAVE_FILE(), "r");
        if (!f) {
            log.add("No adnd1.sav found.");
            return false;
        }
        char tag[16];
        // R33: one-token pushback â holds a tag read past the
        // optional spells line so the next member parse reuses it
        char pendingTag[16] = "";
        bool hasPending = false;
        int version = 0;
        if (fscanf(f, "%15s %d", tag, &version) != 2 ||
            strcmp(tag, "ADND1") != 0 || version != 1) {
            fclose(f);
            log.add("adnd1.sav is not a valid save (v1).");
            return false;
        }
        int n = 0;
        if (fscanf(f, "%15s %d", tag, &n) != 2 ||
            strcmp(tag, "party") != 0 || n < 1 || n > PARTY_MAX) {
            fclose(f);
            log.add("adnd1.sav is corrupt (party).");
            return false;
        }
        Party p;
        int gold = 0, kills = 0, potions = 0, depth = 1;
        if (fscanf(f, "%15s %d %15s %d %15s %d %15s %d",
                   tag, &gold, tag, &kills, tag, &potions,
                   tag, &depth) != 8 || depth < 1 ||
            depth > 50) {
            fclose(f);
            log.add("adnd1.sav is corrupt (career).");
            return false;
        }
        // R44: generalized optional-tag chain â any number of
        // party-level optional lines may appear between the
        // career line and the member loop (v1 saves have none,
        // R43 saves have "training"); the first unrecognized
        // tag is pushed back for the member loop (R33 pattern)
        for (;;) {
            if (fscanf(f, "%15s", tag) != 1) break;
            if (strcmp(tag, "training") == 0) {
                int nt = 0;
                if (fscanf(f, "%d", &nt) != 1 || nt < 0 ||
                    nt > PARTY_MAX) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (training).");
                    return false;
                }
                for (int k = 0; k < nt; ++k) {
                    int ti = 0;
                    if (fscanf(f, "%d", &ti) != 1 || ti < 0 ||
                        ti >= n) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (tidx).");
                        return false;
                    }
                    p.pendingTraining.push_back(ti);
                }
            } else if (strcmp(tag, "stronghold") == 0) {
                int b = 0, ow = -1;
                if (fscanf(f, "%d %d", &b, &ow) != 2 ||
                    (b != 0 && b != 1) || ow < -1 || ow >= n) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (keep).");
                    return false;
                }
                p.strongholdBuilt = (b == 1);
                p.strongholdOwner = ow;
            } else if (strcmp(tag, "henchman") == 0) {
                int present = 0;
                if (fscanf(f, "%d", &present) != 1 ||
                    (present != 0 && present != 1)) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (hire).");
                    return false;
                }
                if (present == 1) {
                    int hp = 0, mx = 0, lv = 0, loy = 0;
                    char nm[NAME_MAX_CHARS + 1] = "";
                    if (fscanf(f, "%d %d %d %d %16s",
                               &hp, &mx, &lv, &loy, nm) != 5 ||
                        hp < 1 || mx < 1 || lv < 1 ||
                        loy < 0 || loy > 125) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (hire).");
                        return false;
                    }
                    p.henchmanPresent = true;
                    p.henchmanName = nm;
                    p.henchmanHp = hp;
                    p.henchmanMaxHp = mx;
                    p.henchmanLevel = lv;
                    p.henchmanLoyalty = loy;
                    // R45: the hire's career records â
                    // OPTIONAL trailing ints (R44 saves lack
                    // them; defaults 0 are fine)
                    int hxp = 0, hpu = 0, dgv = 0;
                    int got = fscanf(f, "%d %d %d",
                                     &hxp, &hpu, &dgv);
                    if (got >= 1) p.henchmanXp = hxp;
                    if (got >= 2) p.henchmanPurse = hpu;
                    if (got >= 3) p.delveGold = dgv;
                }
            } else if (strcmp(tag, "idscrolls") == 0) {
                int sc = 0;
                if (fscanf(f, "%d", &sc) != 1 || sc < 0 ||
                    sc > 99) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (scrolls).");
                    return false;
                }
                p.identifyScrolls = sc;
            } else if (strcmp(tag, "items") == 0) {
                int ni = 0;
                if (fscanf(f, "%d", &ni) != 1 || ni < 0 ||
                    ni > 99) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (items).");
                    return false;
                }
                for (int k = 0; k < ni; ++k) {
                    int kd = 0, pl = 0;
                    if (fscanf(f, "%d %d", &kd, &pl) != 2 ||
                        (kd != 0 && kd != 1) || pl < 1 ||
                        pl > 3) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (item).");
                        return false;
                    }
                    Party::PendingItem it;
                    it.kind = kd;
                    it.plus = pl;
                    p.unidentified.push_back(it);
                }
            } else {
                strcpy(pendingTag, tag);
                hasPending = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            Character c;
            char name[64];
            int cl = 0;
            // R33: tag comes from the pushback buffer when the
            // optional spells line was absent (v1 saves)
            if (hasPending) {
                strcpy(tag, pendingTag);
                hasPending = false;
            } else if (fscanf(f, "%15s", tag) != 1) {
                fclose(f);
                log.add("adnd1.sav is corrupt (short).");
                return false;
            }
            if (strcmp(tag, "member") != 0 ||
                fscanf(f, "%63s %d %d %d %d %d",
                       name, &cl, &c.xp, &c.level, &c.hp,
                       &c.maxHp) != 6 || cl < 0 ||
                cl > 3 || c.maxHp < 1) {
                fclose(f);
                log.add("adnd1.sav is corrupt (member).");
                return false;
            }
            c.name = name;
            c.classIndex = cl;
            int str, int_, wis, dex, con, cha, exHas, exPct;
            if (fscanf(f, "%15s %d %d %d %d %d %d %d %d", tag,
                       &str, &int_, &wis, &dex, &con, &cha,
                       &exHas, &exPct) != 9 ||
                strcmp(tag, "abil") != 0) {
                fclose(f);
                log.add("adnd1.sav is corrupt (abilities).");
                return false;
            }
            c.abilities.str  = (uint8_t)str;
            c.abilities.int_ = (uint8_t)int_;
            c.abilities.wis  = (uint8_t)wis;
            c.abilities.dex  = (uint8_t)dex;
            c.abilities.con  = (uint8_t)con;
            c.abilities.cha  = (uint8_t)cha;
            c.exStr.has = (exHas != 0);
            c.exStr.pct = exPct;
            int wid, wpl, rid, rpl, aid, apl, sh;
            if (fscanf(f, "%15s %d %d %d %d %d %d %d", tag,
                       &wid, &wpl, &rid, &rpl, &aid, &apl,
                       &sh) != 8 || strcmp(tag, "gear") != 0) {
                fclose(f);
                log.add("adnd1.sav is corrupt (gear).");
                return false;
            }
            if (wid < 0 || wid >= (int)items::WPN_COUNT ||
                rid < 0 || rid >= (int)items::WPN_COUNT ||
                aid < 0 || aid >= (int)items::ARMOR_COUNT) {
                fclose(f);
                log.add("adnd1.sav is corrupt (gear ids).");
                return false;
            }
            c.weapon.id        = (items::WeaponId)wid;
            c.weapon.plus      = wpl;
            c.rangedWeapon.id  = (items::WeaponId)rid;
            c.rangedWeapon.plus = rpl;
            c.armor.id         = (items::ArmorId)aid;
            c.armor.plus       = apl;
            c.shield           = (sh != 0);

            // R33/R56: optional per-member lines (v1 save
            // compat). Consume "spells" and "shieldplus" in any
            // order; any other tag is pushed back for the next
            // member iteration.
            bool optLoop = true;
            while (optLoop) {
                if (fscanf(f, "%15s", tag) != 1) break;
                if (strcmp(tag, "shieldplus") == 0) {
                    int sp = 0;
                    if (fscanf(f, "%d", &sp) != 1 ||
                        sp < 0 || sp > 5) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (shield).");
                        return false;
                    }
                    c.shieldPlus = sp;
                } else if (strcmp(tag, "spells") == 0) {
                    int ns = 0;
                    if (fscanf(f, "%d", &ns) != 1 || ns < 0 ||
                        ns > spells::SPELL_COUNT) {
                        fclose(f);
                        log.add("adnd1.sav is corrupt (spells).");
                        return false;
                    }
                    for (int k = 0; k < ns; ++k) {
                        int sid = 0;
                        if (fscanf(f, "%d", &sid) != 1 ||
                            sid < 0 ||
                            sid >= spells::SPELL_COUNT) {
                            fclose(f);
                            log.add("adnd1.sav is corrupt (sid).");
                            return false;
                        }
                        c.knownSpells.push_back(sid);
                    }
                } else {
                    strcpy(pendingTag, tag);
                    hasPending = true;
                    optLoop = false;
                }
            }
            p.members.push_back(c);
        }
        fclose(f);

        // R33: v1 saves predate the spellbook â grant each MU a
        // default book (one random L1 spell, creation convention)
        for (auto& c : p.members) {
            if (c.classIndex == 1 && c.knownSpells.empty()) {
                std::vector<int> l1;
                for (int id = 0; id < spells::SPELL_COUNT;
                     ++id) {
                    const spells::SpellDef& s =
                        spells::spell((spells::SpellId)id);
                    if (s.sclass == spells::SPELL_MU &&
                        s.level == 1)
                        l1.push_back(id);
                }
                if (!l1.empty()) {
                    int pick = (int)dice.roll(
                        1, (uint32_t)l1.size(), 0) - 1;
                    c.knownSpells.push_back(l1[pick]);
                }
            }
        }

        // commit: career restored, fresh dungeon at saved depth
        p.formed = true;
        p.gold = gold;
        p.kills = kills;
        p.potions = potions;
        party = p;
        creation.done = true;
        dungeonLevel = depth;
        mode = MODE_EXPLORE;
        restoreSlots();   // R34: slots are not persisted â full pool on load
        // R35: quivers are not persisted either â full 20 on load
        for (auto& c : party.members)
            if (items::weapon(c.rangedWeapon.id).missile)
                c.missileAmmo = 20;
        newDungeon(seed + 1000 + dungeonLevel);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "The company of %d returns (depth %d).",
                 n, dungeonLevel);
        log.add(buf);
        return true;
    }

    // R23: stairs in the room whose center is farthest from the
    // entry point. The tile itself stays floor â the marker and
    // the step check carry the meaning (no map.h changes needed).
    void placeStairs() {
        long bestDist = -1;
        int  bx = -1, by = -1;
        for (const auto& room : occupancy.rooms) {
            long dx = room.denX - dungeon.entryX;
            long dy = room.denY - dungeon.entryY;
            long dist = dx * dx + dy * dy;
            if (dist > bestDist) {
                bestDist = dist;
                bx = room.denX;
                by = room.denY;
            }
        }
        // keep the stairs clear of a monster den: nudge to the
        // room's corner if the den is occupied
        for (auto& room : occupancy.rooms) {
            if (room.denX == bx && room.denY == by) {
                const auto& r = dungeon.rooms[room.roomIndex];
                if (!room.monsterKey.empty() && r.w >= 3 && r.h >= 3) {
                    bx = r.x;      // top-left corner tile
                    by = r.y;
                }
                break;
            }
        }
        stairsX = bx;
        stairsY = by;
    }

    // R23: descend. Career (hp/xp/gold/equipment/level) persists â
    // depth scales monsters and treasure.
    void descend() {
        ++dungeonLevel;
        log.add("You descend the worn stairs...");
        newDungeon(seed + 1000 + dungeonLevel);
        // R34: the descent takes hours â slots return with the
        // new level (keeps a descended company from being stuck
        // dry with no rest opportunity)
        restoreSlots();
        // R38: quivers restock on the descent too â the trek to a
        // new level is rest-like (slots precedent, R34)
        restockAmmo();
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Dungeon level %d. The air grows colder.",
                 dungeonLevel);
        log.add(buf);
    }

    // R34: refill every caster's slots to their class-table pool
    void restoreSlots() {
        for (auto& c : party.members) {
            if (c.classIndex != 1 && c.classIndex != 2) continue;
            spells::SpellClass sc = c.classIndex == 1
                ? spells::SPELL_MU : spells::SPELL_CLERIC;
            for (int lv = 1; lv <= 6; ++lv)   // R46: 6 levels
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(sc, c.level, lv);
        }
    }

    // R34: rest â restore slots and natural healing (1 hp per
    // level, PHB daily recovery), but the camp may be attacked:
    // a wandering-encounter check first; an interrupted rest
    // restores NOTHING (the party fights on, tired and dry)
    // R38: refill every quiver to 20 (members holding a missile
    // weapon in the ranged slot). Mirrors restoreSlots.
    void restockAmmo() {
        for (auto& c : party.members) {
            if (!items::weapon(c.rangedWeapon.id).missile) continue;
            c.missileAmmo = 20;
        }
    }

    // ---- R41: town hub ------------------------------------------------------

    // [B] from the dungeon â retire to town for supplies
    void enterTown() {
        if (mode != MODE_EXPLORE) return;
        mode = MODE_TOWN;
        log.add("You return to the town above.");
        billTownVisit();   // R70: the shared arrival billing
    }

    // R70: the R41+ arrival billing - rents, henchman
    // upkeep, shares and crew wages, billed on EVERY
    // return to town (the delve-return, the overland
    // march home, a sea landfall). Extracted verbatim
    // from enterTown in R70.
    void billTownVisit() {
        // R44: the keep pays its rents on every return (the
        // delve cadence stands in for the month â simplified
        // stronghold economics)
        if (party.strongholdBuilt) {
            party.gold += 200;
            log.add("The keep's steward delivers 200 gp in "
                    "rents.");
        }
        // R44: henchman upkeep â 100 gp/level billed on each
        // return (DMG p.26 monthly support, delve cadence). A
        // short purse dents loyalty; below 25 he walks.
        if (party.henchmanPresent) {
            int upkeep = 100 * party.henchmanLevel;
            if (party.gold >= upkeep) {
                party.gold -= upkeep;
                char buf[96];
                snprintf(buf, sizeof buf,
                         "%s is paid %d gp for his service.",
                         party.henchmanName.c_str(), upkeep);
                log.add(buf);
            } else {
                party.henchmanLoyalty -= 10;
                log.add("The purse is too thin to pay " +
                        party.henchmanName +
                        " â he takes note.");
            }
            if (party.henchmanLoyalty < 25) {
                log.add(party.henchmanName +
                        " packs his kit and quits the company.");
                party.henchmanPresent = false;
            }
        }
        // R45: the hire's THIRD of the take (DMG p.36 â a
        // stated share; this campaign promised a half share
        // = a third of the delve's gold), paid at the exit
        // into his purse
        int crewCut = 0;
        if (party.crewHired && party.delveGold > 0) {
            crewCut = party.delveGold / 20;
            if (crewCut > 0) {
                char cbuf[96];
                snprintf(cbuf, sizeof cbuf,
                         "The crew's share: %d gp.", crewCut);
                log.add(cbuf);
            }
        }
        if (party.henchmanPresent && party.delveGold > 0) {
            int cut = (party.delveGold - crewCut) / 3;
            party.henchmanPurse += cut;
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%s is paid his share: %d gp (purse %d).",
                     party.henchmanName.c_str(), cut,
                     party.henchmanPurse);
            log.add(buf);
        }
        party.delveGold = 0;
        // R46: crew wages — 20 sailors at 2 gp (DMG p.34),
        // billed each return (delve cadence)
        if (party.crewHired) {
            if (party.gold >= 40) {
                party.gold -= 40;
                log.add("The crew is paid 40 gp in wages.");
            } else {
                log.add("The crew grumbles over unpaid "
                        "wages.");
            }
        }
    }
    // [B]/Esc in town â dive back in at the same depth
    void leaveTown() {
        if (mode != MODE_TOWN) return;
        // R44: the loyalty check that gates each delve (DMG
        // p.37 â a disloyal hire refuses the descent; the roll
        // simplified to a single d100 vs loyalty)
        if (party.henchmanPresent) {
            int roll = (int)rng.below(100) + 1;
            if (roll > party.henchmanLoyalty) {
                log.add(party.henchmanName +
                        "'s nerve fails; he quits the company.");
                party.henchmanPresent = false;
            } else {
                log.add(party.henchmanName +
                        " shoulders his pack and follows.");
            }
        }
        mode = MODE_EXPLORE;
        log.add("You descend once more.");
    }

    // the temple sells healing potions (50 gp)
    void townBuyPotion() {
        if (mode != MODE_TOWN) return;
        if (party.gold < 50) {
            log.add("The priest shakes his head â 50 gp.");
            return;
        }
        party.gold -= 50;
        ++party.potions;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Bought a potion of healing (%d carried, %d gp left).",
                 party.potions, party.gold);
        log.add(buf);
    }

    // the fletcher sells 20-arrow bundles (30 gp) â taker follows
    // the R39 loot convention (first armed member below 20, else
    // the least-supplied one)
    void townBuyArrows() {
        if (mode != MODE_TOWN) return;
        Character* taker = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (!items::weapon(c.rangedWeapon.id).missile) continue;
            if (!taker || c.missileAmmo < taker->missileAmmo)
                taker = &c;
            if (taker->missileAmmo < 20) break;
        }
        if (!taker) {
            log.add("The fletcher shrugs â no one carries a bow.");
            return;
        }
        if (party.gold < 30) {
            log.add("The fletcher wants 30 gp.");
            return;
        }
        party.gold -= 30;
        taker->missileAmmo += 20;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Bought 20 arrows (%s carries %d, %d gp left).",
                 taker->name.c_str(), taker->missileAmmo, party.gold);
        log.add(buf);
    }

    // R42: the inn â a safe night's rest (10 gp). Full slots
    // (restoreSlots), full quivers (restockAmmo), 1 hp/level
    // natural healing each â and NO wander check: that is what
    // the silver buys (explore [R] rest is free but risky)
    void townInnRest() {
        if (mode != MODE_TOWN) return;
        if (party.gold < 10) {
            log.add("The innkeeper wants 10 gp for the night.");
            return;
        }
        party.gold -= 10;
        restoreSlots();
        restockAmmo();
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            int heal = c.level;
            if (c.hp + heal > c.maxHp) heal = c.maxHp - c.hp;
            if (heal > 0) c.hp += heal;
        }
        // R44: the henchman bunks with the company â same 1
        // hp/level natural healing
        if (party.henchmanPresent &&
            party.henchmanHp < party.henchmanMaxHp) {
            int heal = party.henchmanLevel;
            if (party.henchmanHp + heal > party.henchmanMaxHp)
                heal = party.henchmanMaxHp - party.henchmanHp;
            party.henchmanHp += heal;
        }
        log.add("A safe night at the inn. Spells, quivers, and "
                "wounds mend.");
    }

    // R42: the temple â heal the most-wounded living member to
    // full (100 gp). Cheaper per-hp than potions at scale, but
    // only in town and one member at a time
    void townTempleHeal() {
        if (mode != MODE_TOWN) return;
        Character* best = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (!best || (c.maxHp - c.hp) > (best->maxHp - best->hp))
                best = &c;
        }
        if (!best || best->hp >= best->maxHp) {
            log.add("The priests see no wounds to mend.");
            return;
        }
        if (party.gold < 100) {
            log.add("The high priest asks 100 gp for a cure.");
            return;
        }
        party.gold -= 100;
        best->hp = best->maxHp;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "%s is restored to %d hp.",
                 best->name.c_str(), best->hp);
        log.add(buf);
    }

    // R42: the smith â a +1 long sword (500 gp), claimed by the
    // first living fighter whose blade is not already magic
    void townBuySword() {
        if (mode != MODE_TOWN) return;
        Character* taker = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (c.classIndex != rules::CLASS_FIGHTER) continue;
            if (c.weapon.id == items::WPN_LONG_SWORD &&
                c.weapon.plus >= 1) continue;
            taker = &c;
            break;
        }
        if (!taker) {
            log.add("No fighter needs a blade today.");
            return;
        }
        if (party.gold < 500) {
            log.add("The smith wants 500 gp for the enchanted "
                    "blade.");
            return;
        }
        party.gold -= 500;
        taker->weapon.id = items::WPN_LONG_SWORD;
        taker->weapon.plus = 1;
        log.add(taker->name + " buys a +1 long sword.");
    }

    // R43: the training hall â promote the first queued member
    // (1500 gp x their next level, DMG p.86 convention
    // simplified). One promotion per visit/key press.
    void townTrain() {
        if (mode != MODE_TOWN) return;
        if (party.pendingTraining.empty()) {
            log.add("No one is due a level.");
            return;
        }
        // peek at the first valid queued member for the price
        int idx = -1;
        for (int i : party.pendingTraining) {
            if (i >= 0 && i < (int)party.members.size() &&
                party.members[i].hp > 0) { idx = i; break; }
        }
        if (idx < 0) {
            log.add("No one is due a level.");
            return;
        }
        Character& c = party.members[idx];
        int cost = 1500 * (c.level + 1);
        // R44: the keep's masters-at-arms instruct their lord's
        // company at half fees
        if (party.strongholdBuilt) cost /= 2;
        if (party.gold < cost) {
            char buf[96];
            snprintf(buf, sizeof buf,
                     "The training master wants %d gp.", cost);
            log.add(buf);
            return;
        }
        party.gold -= cost;
        int trained = party.trainNext(dice, log);
        if (trained >= 0) {
            char buf[96];
            snprintf(buf, sizeof buf,
                     "Training paid (%d gp).", cost);
            log.add(buf);
            // R34: a trained caster's slot pool may have grown â
            // restore so the new slots are usable
            restoreSlots();
        }
    }

    // R43: the armorer â chain mail (75 gp, PHB list price) for
    // the first living armor-eligible member (fighter or cleric)
    // whose current armor is worse than chain
    void townBuyChain() {
        if (mode != MODE_TOWN) return;
        Character* taker = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (c.classIndex != rules::CLASS_FIGHTER &&
                c.classIndex != rules::CLASS_CLERIC)
                continue;
            if ((int)c.armor.id >=
                (int)items::ARMOR_CHAIN_MAIL)
                continue;   // already chain or better
            taker = &c;
            break;
        }
        if (!taker) {
            log.add("No one needs chain mail today.");
            return;
        }
        if (party.gold < 75) {
            log.add("The armorer wants 75 gp.");
            return;
        }
        party.gold -= 75;
        taker->armor.id = items::ARMOR_CHAIN_MAIL;
        log.add(taker->name + " buys chain mail.");
    }

    // R43: the scribe â a spell scroll (200 gp): one random
    // unknown L1 MU spell is copied into the first MU's book
    // (chance-to-learn deferred to level-ups â buying knowledge
    // is the simplification)
    void townBuyScroll() {
        if (mode != MODE_TOWN) return;
        // gather unknown L1 MU spells
        std::vector<int> unknown;
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)id);
            if (s.sclass != spells::SPELL_MU || s.level != 1)
                continue;
            bool knownByAll = true;
            for (auto& c : party.members)
                if (c.classIndex == 1 && !c.knowsSpell(id))
                    knownByAll = false;
            if (!knownByAll) unknown.push_back(id);
        }
        if (unknown.empty()) {
            log.add("The scribe has no scrolls you need.");
            return;
        }
        Character* taker = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0 || c.classIndex != 1) continue;
            for (int id : unknown) {
                if (!c.knowsSpell(id)) { taker = &c; break; }
            }
            if (taker) break;
        }
        if (!taker) {
            log.add("No magic-user can study the scroll.");
            return;
        }
        if (party.gold < 200) {
            log.add("The scribe wants 200 gp.");
            return;
        }
        party.gold -= 200;
        // pick a spell this taker does not know
        std::vector<int> forHim;
        for (int id : unknown)
            if (!taker->knowsSpell(id)) forHim.push_back(id);
        int pick = forHim.empty()
            ? unknown[0]
            : forHim[(size_t)dice.roll(
                  1, (uint32_t)forHim.size(), 0) - 1];
        taker->knownSpells.push_back(pick);
        const spells::SpellDef& s = spells::spell(
            (spells::SpellId)pick);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "%s copies %s into his spellbook.",
                 taker->name.c_str(), s.name);
        log.add(buf);
    }

    // R44: the keep â a name-level member raises a stronghold.
    // 10,000 gp is a rebuild-scale simplification of the DMG
    // p.83 barony costs (the book's castle economics are far
    // larger than delve treasure supports); name level here is
    // the class level cap (fighter 9, MU 11, cleric 9, thief 10)
    void townBuildStronghold() {
        if (mode != MODE_TOWN) return;
        if (party.strongholdBuilt) {
            log.add("The keep already flies your banner.");
            return;
        }
        int owner = -1;
        for (int i = 0; i < (int)party.members.size(); ++i) {
            const Character& c = party.members[i];
            if (c.hp <= 0) continue;
            if (c.level >=
                rules::CLASS_LEVEL_CAP[c.classIndex]) {
                owner = i;
                break;
            }
        }
        if (owner < 0) {
            log.add("Only a member at name level may hold "
                    "land.");
            return;
        }
        if (party.gold < 10000) {
            log.add("The masons want 10,000 gp for the keep.");
            return;
        }
        party.gold -= 10000;
        party.strongholdBuilt = true;
        party.strongholdOwner = owner;
        log.add(party.members[owner].name +
                " raises a keep â rents will follow.");
    }

    // R44: the scribe also stocks identify scrolls (100 gp)
    void townBuyIdentify() {
        if (mode != MODE_TOWN) return;
        if (party.gold < 100) {
            log.add("The scribe wants 100 gp for the scroll.");
            return;
        }
        party.gold -= 100;
        ++party.identifyScrolls;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Bought an identify scroll (%d carried, "
                 "%d gp left).",
                 party.identifyScrolls, party.gold);
        log.add(buf);
    }

    // R44: [I] â read an identify scroll over the first
    // pending item. The enchant was rolled at loot time but
    // hidden from the company; identification applies it.
    void useIdentifyScroll() {
        if (mode != MODE_TOWN) return;
        if (party.identifyScrolls <= 0) {
            log.add("You carry no identify scroll.");
            return;
        }
        if (party.unidentified.empty()) {
            log.add("Nothing in the pack wants identifying.");
            return;
        }
        Party::PendingItem it = party.unidentified.front();
        party.unidentified.erase(
            party.unidentified.begin());
        --party.identifyScrolls;
        if (it.kind == 0) {
            // magic weapon â the first living fighter (then
            // anyone) whose blade is a lesser enchant
            Character* taker = nullptr;
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                if (c.classIndex != rules::CLASS_FIGHTER)
                    continue;
                if (c.weapon.plus < it.plus) { taker = &c; break; }
            }
            if (!taker) {
                for (auto& c : party.members) {
                    if (c.hp <= 0) continue;
                    if (c.weapon.plus < it.plus) {
                        taker = &c;
                        break;
                    }
                }
            }
            if (taker) {
                taker->weapon.id = items::WPN_LONG_SWORD;
                taker->weapon.plus = it.plus;
                char buf[96];
                snprintf(buf, sizeof buf,
                         "The scroll reveals a long sword +%d! "
                         "%s claims it.",
                         it.plus, taker->name.c_str());
                log.add(buf);
            } else {
                log.add("The scroll reveals a long sword â "
                        "but no one can better his blade. It "
                        "is sold for 200 gp.");
                party.gold += 200;
            }
        } else {
            // enchanted armor â the first living fighter or
            // cleric whose armor is a lesser enchant
            Character* taker = nullptr;
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                if (c.classIndex != rules::CLASS_FIGHTER &&
                    c.classIndex != rules::CLASS_CLERIC)
                    continue;
                if (c.armor.plus < it.plus) { taker = &c; break; }
            }
            if (taker) {
                taker->armor.plus = it.plus;
                char buf[96];
                snprintf(buf, sizeof buf,
                         "The scroll reveals enchanted armor "
                         "(+%d)! %s claims it.",
                         it.plus, taker->name.c_str());
                log.add(buf);
            } else {
                log.add("The scroll reveals enchanted armor â "
                        "but no one can better his mail. It "
                        "is sold for 200 gp.");
                party.gold += 200;
            }
        }
    }

    // R44: [H] â post a henchman offer (DMG p.36 simplified:
    // 100 gp spent regardless, acceptance d100 vs interest =
    // 25% + the best living member's Cha reaction adj)
    void townHireHenchman() {
        if (mode != MODE_TOWN) return;
        if (party.henchmanPresent) {
            log.add(party.henchmanName +
                    " already rides with the company.");
            return;
        }
        if (party.gold < 100) {
            log.add("The crier wants 100 gp to post the "
                    "offer.");
            return;
        }
        party.gold -= 100;
        int chaAdj = 0;
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            int adj = rules::chaReactionAdj(c.abilities.cha);
            if (adj > chaAdj) chaAdj = adj;
        }
        int interest = 25 + chaAdj;
        int roll = (int)rng.below(100) + 1;
        if (roll > interest) {
            log.add("No one answers the company's offer.");
            return;
        }
        // a level-1 fighter answers (stats averaged for the
        // hire â a simplification vs the book's rolled men)
        static const char* NAMES[] = {
            "Bors", "Gareth", "Hult", "Marda",
            "Oswin", "Pell", "Roderic", "Sela"
        };
        std::string name;
        for (const char* cand : NAMES) {
            bool taken = false;
            for (const auto& c : party.members)
                if (c.name == cand) taken = true;
            if (!taken) { name = cand; break; }
        }
        if (name.empty()) {
            log.add("A sellsword answers, but the company is "
                    "too well known â he declines.");
            return;
        }
        party.henchmanPresent = true;
        party.henchmanName = name;
        party.henchmanLevel = 1;
        party.henchmanMaxHp =
            (int)dice.roll(1, 10, 0) + 1;   // CON-ish adj
        if (party.henchmanMaxHp < 2) party.henchmanMaxHp = 2;
        party.henchmanHp = party.henchmanMaxHp;
        party.henchmanLoyalty = 50 + chaAdj;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "%s the fighter answers the offer! (loyalty "
                 "%d%%)",
                 party.henchmanName.c_str(),
                 party.henchmanLoyalty);
        log.add(buf);
    }

    // R45: [S] the sage â 200 gp for lore on what lairs at
    // this depth. R52: the roster is the DMG Appendix C
    // Determination Matrix for this dungeon level (the real
    // tables, OCR-verified) â dm::encounterKeys.
    void townSage() {
        if (mode != MODE_TOWN) return;
        if (party.gold < 200) {
            log.add("The sage wants 200 gp for his lore.");
            return;
        }
        auto keys = dm::encounterKeys(registry, dungeonLevel);
        if (keys.empty()) {
            log.add("The sage knows nothing of this depth.");
            return;
        }
        party.gold -= 200;
        std::string lore = "The sage speaks of: ";
        int shown = 0;
        for (const auto& k : keys) {
            if (shown >= 8) { lore += "..."; break; }
            if (shown > 0) lore += ", ";
            lore += k;
            ++shown;
        }
        log.add(lore);
        // one bestiary stat line for flavor (a random entry)
        const monsters::MonsterDef* def =
            registry.find(keys[(size_t)rng.below(
                (uint32_t)keys.size())]);
        if (def) {
            char buf[96];
            // R69: the R49 Lua schema carries hitDiceText (the
            // printed "4 + 3" form) and armorClass — the old
            // hd/ac field names no longer exist
            if (!def->hitDiceText.empty())
                snprintf(buf, sizeof buf,
                         "Of %s: HD %s, AC %d, worth %d xp.",
                         def->name.c_str(),
                         def->hitDiceText.c_str(),
                         def->armorClass, def->xpValue);
            else
                snprintf(buf, sizeof buf,
                         "Of %s: HD %d, AC %d, worth %d xp.",
                         def->name.c_str(), def->hitDiceNum,
                         def->armorClass, def->xpValue);
            log.add(buf);
        }
    }

    // R45: [Y] the spy â 500 gp for simple recon (DMG p.35
    // spying simplified): the CURRENT level's occupied rooms
    // and their monster keys
    void townSpy() {
        if (mode != MODE_TOWN) return;
        int occupied = 0;
        for (const auto& room : occupancy.rooms)
            if (!room.monsterKey.empty()) ++occupied;
        if (occupied == 0) {
            log.add("The spy reports the level is swept "
                    "clean.");
            return;
        }
        if (party.gold < 500) {
            log.add("The spy wants 500 gp for the mission.");
            return;
        }
        party.gold -= 500;
        std::string report = "The spy reports: ";
        int shown = 0;
        for (const auto& room : occupancy.rooms) {
            if (room.monsterKey.empty()) continue;
            if (shown >= 6) { report += "..."; break; }
            if (shown > 0) report += ", ";
            char tok[48];
            snprintf(tok, sizeof tok, "%s x%d",
                     room.monsterKey.c_str(), room.count);
            report += tok;
            ++shown;
        }
        log.add(report);
    }

    // R45: [M] the peddler â 500 gp for one random
    // IDENTIFIED magic item (no scroll needed â the peddler
    // knows his wares)
    void townPeddler() {
        if (mode != MODE_TOWN) return;
        if (party.gold < 500) {
            log.add("The peddler wants 500 gp for the item.");
            return;
        }
        party.gold -= 500;
        int pick = 1 + (int)rng.below(5);
        switch (pick) {
            case 1: {
                // a +1 weapon for the first living member
                // whose blade is a lesser enchant
                Character* taker = nullptr;
                for (auto& c : party.members) {
                    if (c.hp <= 0) continue;
                    if (c.weapon.plus < 1) { taker = &c; break; }
                }
                if (taker) {
                    taker->weapon.id = items::WPN_LONG_SWORD;
                    taker->weapon.plus = 1;
                    log.add("A long sword +1! " +
                            taker->name + " claims it.");
                } else {
                    party.potions += 3;
                    log.add("The peddler is out of swords â "
                            "three potions instead.");
                }
                break;
            }
            case 2: {
                Character* taker = nullptr;
                for (auto& c : party.members) {
                    if (c.hp <= 0) continue;
                    if (c.classIndex != rules::CLASS_FIGHTER &&
                        c.classIndex != rules::CLASS_CLERIC)
                        continue;
                    if (c.armor.plus < 1) { taker = &c; break; }
                }
                if (taker) {
                    taker->armor.plus = 1;
                    log.add("Enchanted armor (+1)! " +
                            taker->name + " claims it.");
                } else {
                    party.potions += 3;
                    log.add("The peddler is out of armor â "
                            "three potions instead.");
                }
                break;
            }
            case 3:
                party.potions += 3;
                log.add("Three potions of healing, wrapped "
                        "in straw.");
                break;
            case 4:
                party.identifyScrolls += 2;
                log.add("Two identify scrolls, freshly "
                        "inked.");
                break;
            default: {
                // a spell scroll â one random unknown L1 MU
                // spell to the first MU who lacks it (the
                // peddler's stock is identified)
                std::vector<int> cands;
                for (int id = 0; id < spells::SPELL_COUNT;
                     ++id) {
                    const spells::SpellDef& s =
                        spells::spell((spells::SpellId)id);
                    if (s.sclass != spells::SPELL_MU ||
                        s.level != 1)
                        continue;
                    for (auto& c : party.members) {
                        if (c.hp <= 0 || c.classIndex != 1)
                            continue;
                        if (!c.knowsSpell(id)) {
                            cands.push_back(id);
                            break;
                        }
                    }
                }
                if (cands.empty()) {
                    party.potions += 3;
                    log.add("No scrolls your sages can use â "
                            "three potions instead.");
                } else {
                    int sid = cands[(size_t)rng.below(
                        (uint32_t)cands.size())];
                    for (auto& c : party.members) {
                        if (c.hp <= 0 || c.classIndex != 1)
                            continue;
                        if (!c.knowsSpell(sid)) {
                            c.knownSpells.push_back(sid);
                            const spells::SpellDef& s =
                                spells::spell(
                                    (spells::SpellId)sid);
                            char buf[96];
                            snprintf(buf, sizeof buf,
                                     "A scroll of %s! %s "
                                     "copies it into his "
                                     "book.",
                                     s.name, c.name.c_str());
                            log.add(buf);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

    // R46: first-entry room flavor — one atmospheric line,
    // state-aware (occupied, trapped, looted, swept)
    void describeRoom(int roomIndex) {
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.flavorSeen) return;
        room.flavorSeen = true;
        const char* line = nullptr;
        if (!room.monsterKey.empty())
            line = "Furs and cracked bones litter the floor â "
                   "something lives here.";
        else if (room.trap == 1)
            line = "The dust lies thick and undisturbed "
                   "here.";
        else if (room.looted)
            line = "Spent torch stubs and old scorch marks â "
                   "someone camped here before you.";
        else if (room.trap == 2)
            line = "Darts jut from the wall at knee height.";
        else
            line = "A cold draft moves through the chamber.";
        log.add(line);
    }

    // R46: [T] talk with the town locals — state-aware
    // tavern chatter (the NPC dialogue system lite)
    void townTalk() {
        if (mode != MODE_TOWN) return;
        std::vector<std::string> lines;
        if (!party.pendingTraining.empty())
            lines.push_back("The training master asks after "
                            "your company, he says.");
        if (!party.unidentified.empty())
            lines.push_back("A scribe's eye could tell you "
                            "what that odd gear of yours "
                            "truly is.");
        if (party.henchmanPresent)
            lines.push_back(party.henchmanName +
                            " nods from his table by the "
                            "fire.");
        if (party.strongholdBuilt)
            lines.push_back("They say the keep up the road "
                            "pays fair rents.");
        if (party.crewHired)
            lines.push_back("Your coaster's crew drinks at "
                            "the harbor inn, loud as gulls.");
        if (dungeonLevel >= 3)
            lines.push_back("The deep levels? Mad, all of "
                            "it. Mind the flayers, they "
                            "say.");
        else
            lines.push_back("Goblins in the cellar, kobolds "
                            "in the sewers same as ever.");
        if (party.gold >= 10000)
            lines.push_back("Masons would raise you a fine "
                            "keep for that purse of yours.");
        if (party.potions == 0)
            lines.push_back("Dungeon-diving without potions? "
                            "Bold. Or foolish.");
        log.add(lines[(size_t)rng.below(
            (uint32_t)lines.size())]);
    }

    // R46: [J] upgrade the hire's kit to plate — paid from
    // HIS purse, not the company gold (tranche-124 convention)
    void townUpgradeHire() {
        if (mode != MODE_TOWN) return;
        if (!party.henchmanPresent) {
            log.add("You have no hire to equip.");
            return;
        }
        if (party.henchmanPlate) {
            log.add(party.henchmanName +
                    " already wears plate.");
            return;
        }
        if (party.henchmanPurse < 100) {
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%s's purse holds only %d gp — the "
                     "armorers want 100.",
                     party.henchmanName.c_str(),
                     party.henchmanPurse);
            log.add(buf);
            return;
        }
        party.henchmanPurse -= 100;
        party.henchmanPlate = true;
        log.add(party.henchmanName +
                " buys plate from his own purse!");
    }

    // R46: [C] hire a ship's crew — a 20-sailor coaster's
    // company (DMG p.34-35 simplified: 200 gp down, 40 gp
    // wages each return, 5% of every take at the exit)
    void townHireCrew() {
        if (mode != MODE_TOWN) return;
        if (party.crewHired) {
            log.add("The coaster's company already sails "
                    "with you.");
            return;
        }
        if (party.gold < 200) {
            log.add("The harbormaster wants 200 gp to sign "
                    "a crew.");
            return;
        }
        party.gold -= 200;
        party.crewHired = true;
        log.add("A coaster's company of twenty signs on. "
                "They will ferry your takings to market.");
    }

    void restExplore() {
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;

        log.add("The party makes camp...");
        if (dm::wanderCheck(dice, wander)) {
            log.add("The rest is interrupted!");
            spawnWanderingEncounter();
            return;
        }

        restoreSlots();
        // R38: a completed rest renews arrows too â fletching and
        // recovery time (interrupted rests restore nothing, as
        // with slots)
        restockAmmo();
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;   // the dead do not heal
            int heal = c.level;
            if (c.hp + heal > c.maxHp) heal = c.maxHp - c.hp;
            if (heal > 0) c.hp += heal;
        }
        log.add("The company rests. Spells and wounds mend.");
    }

    int countOccupied() const {
        int n = 0;
        for (const auto& r : occupancy.rooms)
            if (!r.monsterKey.empty()) ++n;
        return n;
    }

    void populateRooms() {
        // R52: lairs roll from the DMG Appendix C tables —
        // the Determination Matrix for this depth, then the
        // Monster Level Table row (count, hydra heads, dragon
        // hp/die brackets). The R42 depth cap still bounds lair
        // size.
        for (auto& room : occupancy.rooms) {
            room.monsterKey.clear();
            room.count = 0;
            room.looted = false;
            room.trap = 0;
            room.flavorSeen = false;   // R46
            room.headsLo = room.headsHi = 0;
            room.ageLo = room.ageHi = 0;
            if (rng.below(100) >= 50) {
                // R45: an unoccupied room may hide a dart trap
                if (rng.below(100) < 15) room.trap = 1;
                continue;
            }
            dm::DungeonEncounter e = rollDmEncounter();
            if (e.isParty) {
                // R53: NPC parties wander the halls — they do
                // not lair; the room stays unoccupied (trap chance)
                if (rng.below(100) < 15) room.trap = 1;
                continue;
            }
            if (e.key.empty() || e.count <= 0) {
                // NO ENCOUNTER (or an R53 row re-rolled out):
                // the room stays unoccupied (trap chance as above)
                if (rng.below(100) < 15) room.trap = 1;
                continue;
            }
            room.monsterKey = e.key;
            room.count = e.count > roomCountCap()
                ? roomCountCap() : e.count;
            room.headsLo = e.headsLo; room.headsHi = e.headsHi;
            room.ageLo = e.ageLo;     room.ageHi = e.ageHi;
        }
    }

    int roomCountCap() const {
        // R42: lairs grow with depth (2 on level 1, +1 per two
        // levels beyond, capped at 5)
        int cap = 2 + (dungeonLevel - 1) / 2;
        return cap > 5 ? 5 : cap;
    }

    int roomAt(int x, int y) const {
        for (size_t i = 0; i < dungeon.rooms.size(); ++i) {
            const auto& r = dungeon.rooms[i];
            if (x >= r.x && x < r.x + r.w &&
                y >= r.y && y < r.y + r.h)
                return (int)i;
        }
        return -1;
    }

    int occupiedRoomNear(int px, int py, int radius = 2) const {
        for (const auto& room : occupancy.rooms) {
            if (room.monsterKey.empty()) continue;
            const auto& r = dungeon.rooms[room.roomIndex];
            if (px >= r.x - radius && px < r.x + r.w + radius &&
                py >= r.y - radius && py < r.y + r.h + radius)
                return room.roomIndex;
        }
        return -1;
    }

    // R45: the nearest room with an ARMED trap (the party
    // springs it by walking in)
    int trapRoomNear(int px, int py, int radius = 0) const {
        for (const auto& room : occupancy.rooms) {
            if (room.trap != 1) continue;
            const auto& r = dungeon.rooms[room.roomIndex];
            if (px >= r.x - radius && px < r.x + r.w + radius &&
                py >= r.y - radius && py < r.y + r.h + radius)
                return room.roomIndex;
        }
        return -1;
    }

    // R45: spring the dart trap in a room. A thief in the
    // company may spot and disarm it first (1-in-3, the
    // find/remove-trades instinct â simplified); otherwise a
    // random living member saves vs death or eats 2d6.
    void springTrap(int roomIndex) {
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.trap != 1) return;

        for (const auto& c : party.members) {
            if (c.hp <= 0 || c.classIndex != 3) continue;
            if (rng.below(3) == 0) {
                room.trap = 2;
                log.add(c.name + " spots a dart trap and "
                        "disarms it.");
                return;
            }
            break;   // one thief attempt per trap
        }

        room.trap = 2;
        // pick the unlucky one who leads into the room
        int victims[PARTY_MAX];
        int nv = 0;
        for (int i = 0; i < (int)party.members.size(); ++i)
            if (party.members[i].hp > 0)
                victims[nv++] = i;
        if (nv == 0) return;
        int vi = victims[(size_t)rng.below((uint32_t)nv)];
        Character& c = party.members[vi];
        int target = rules::saveTarget(
            c.classIndex, c.level, rules::SAVE_DEATH_POISON);
        if (rules::attemptSave(dice, target, 0)) {
            char buf[96];
            snprintf(buf, sizeof buf,
                     "A dart whistles past %s â saved!",
                     c.name.c_str());
            log.add(buf);
            return;
        }
        int dmg = (int)dice.roll(2, 6, 0);
        c.hp -= dmg;
        char buf[96];
        if (c.hp <= 0) {
            c.hp = 0;
            snprintf(buf, sizeof buf,
                     "A trap! Darts strike %s for %d â %s "
                     "falls!",
                     c.name.c_str(), dmg, c.name.c_str());
        } else {
            snprintf(buf, sizeof buf,
                     "A trap! Darts strike %s for %d.",
                     c.name.c_str(), dmg);
        }
        log.add(buf);
        if (!party.alive()) {
            log.add("GAME OVER - press N to roll a new party.");
        }
    }

    // R45: place secret doors â wall tiles that border floor
    // (3 per level). Found doors become ordinary doors on
    // the map; hidden ones render as plain wall.
    void placeSecretDoors() {
        secretDoors.clear();
        int placed = 0;
        int guard = 0;
        while (placed < 3 && ++guard < 500) {
            int x = 1 + (int)rng.below(MAP_TILES_X - 2);
            int y = 1 + (int)rng.below(MAP_TILES_Y - 2);
            if (map.at(x, y) != TILE_WALL) continue;
            bool bordersFloor = false;
            if (map.at(x + 1, y) == TILE_FLOOR ||
                map.at(x - 1, y) == TILE_FLOOR ||
                map.at(x, y + 1) == TILE_FLOOR ||
                map.at(x, y - 1) == TILE_FLOOR)
                bordersFloor = true;
            if (!bordersFloor) continue;
            bool tooClose = false;
            for (const auto& d : secretDoors)
                if (d.x == x && d.y == y) tooClose = true;
            if (tooClose) continue;
            SecretDoor d;
            d.x = x;
            d.y = y;
            secretDoors.push_back(d);
            ++placed;
        }
    }

    // R45: [F] search â one turn spent feeling the walls.
    // Each adjacent unfound secret door rolls 1-in-6 (a
    // thief in the company raises it to 3-in-6 â his keen
    // eyes lead the search). Found doors become TILE_DOOR.
    void searchExplore() {
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;
        ++turnCount;
        bool hasThief = false;
        for (const auto& c : party.members)
            if (c.hp > 0 && c.classIndex == 3) hasThief = true;
        int chance = hasThief ? 3 : 1;
        bool found = false;
        for (auto& d : secretDoors) {
            if (d.found) continue;
            int dx = d.x - party.x;
            int dy = d.y - party.y;
            if (dx < -1 || dx > 1 || dy < -1 || dy > 1)
                continue;
            if (dx != 0 && dy != 0) continue;   // orthogonal
            if (dx == 0 && dy == 0) continue;
            if ((int)rng.below(6) < chance) {
                d.found = true;
                map.set(d.x, d.y, TILE_DOOR);
                found = true;
            }
        }
        if (found) {
            log.add("Your fingers find the seam of a secret "
                    "door!");
        } else {
            log.add("You search the walls and find nothing.");
        }
        // the turn spent can draw a wanderer
        if (dm::wanderCheck(dice, wander))
            spawnWanderingEncounter();
    }

    Treasure rollTreasure(int roomIndex) {
        Treasure t;
        (void)roomIndex;
        // R42: gold scales up with depth â 25% more per level
        // above the first (the dungeon hoards grow richer)
        int goldMult = 100 + 25 * (dungeonLevel - 1);
        if (goldMult > 200) goldMult = 200;   // cap at +100%
        t.gold = (int)dice.roll(3, 6, 0) * 10 * dungeonLevel;
        t.gold = t.gold * goldMult / 100;
        if (rng.below(100) < 10) t.potionHealing = true;
        if (rng.below(100) < 5) t.magicSword = true;
        if (rng.below(100) < 10) t.missileWeapon = true;   // R28
        if (rng.below(100) < 15) t.ammoBundle = true;      // R39
        if (rng.below(100) < 5) t.thrownDagger = true;     // R40
        if (rng.below(100) < 8) t.identifyScroll = true;   // R44
        if (rng.below(100) < 5) t.unidentifiedItem = true; // R44
        return t;
    }

    void awardVictory() {
        if (!combat.encounter || combat.lastResult != 0) return;

        const monsters::MonsterDef* def = registry.find(combatMonsterKey);
        int survivors = 0;
        for (const auto& a : combat.encounter->party())
            if (a.alive()) ++survivors;
        if (survivors < 1) survivors = 1;

        int slain = 0;
        int totalXp = 0;
        int idx = 0;
        for (const auto& m : combat.encounter->monsters()) {
            monsters::xp::SpawnContext ctx =   // R51: per-foe context
                (idx < (int)foeCtxs.size()) ? foeCtxs[idx]
                                            : monsters::xp::SpawnContext();
            ++idx;
            if (m.alive()) continue;
            ++slain;
            ctx.actualHp = m.maxHp;      // the specimen actually fought
            if (def)
                totalXp += monsters::xp::xpForKill(*def, ctx);
            else if (ctx.level > 0 || ctx.classIndex >= 0)
                // R53: a Character Subtable party member (no lua
                // record) — the def-free by_level ladder
                totalXp += monsters::xp::xpForNpc(ctx);
            else
                totalXp += 10;
        }

        if (slain > 0) {
            int share = totalXp / survivors;
            party.kills += slain;
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%d slain, %d xp each.", slain, share);
            log.add(buf);
            party.gainXp(share, dice, log);
            // R45: the hire earns a half share (DMG p.86 â
            // henchmen take half a member's share)
            if (party.henchmanPresent) {
                party.henchmanXp += share / 2;
                while (party.henchmanLevel <
                           rules::CLASS_LEVEL_CAP[0] &&
                       party.henchmanXp >=
                           rules::xpForLevel(
                               0, party.henchmanLevel + 1)) {
                    ++party.henchmanLevel;
                    int die =
                        (int)dice.roll(1, 10, 0) + 1;
                    party.henchmanMaxHp += die;
                    party.henchmanHp += die;
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "%s attains level %d! (+%d hp, "
                             "now %d/%d)",
                             party.henchmanName.c_str(),
                             party.henchmanLevel, die,
                             party.henchmanHp,
                             party.henchmanMaxHp);
                    log.add(buf);
                }
            }
        }

        if (combatRoomIndex >= 0) {
            RoomOccupant& room = occupancy.rooms[combatRoomIndex];
            if (!room.monsterKey.empty()) {
                Treasure t = rollTreasure(combatRoomIndex);
                if (t.gold > 0) {
                    party.gold += t.gold;
                    party.delveGold += t.gold;   // R45: the take
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You loot %d gp.", t.gold);
                    log.add(buf);
                    // R26 treasure XP, R61: DMG p.86 guard rule.
                    // 1 gp = 1 xp only when the guardian's
                    // relative value equals or exceeds the
                    // party's; weaker guardians award on the
                    // printed sliding scale. Proxy: average
                    // party level vs the hoard monster's
                    // effective level (no key = unguarded
                    // delve, 1:1). Split among living members
                    // like combat XP (victory only; fleeing
                    // leaves loot AND xp behind).
                    double partyAvgLvl = 0.0;
                    for (const auto& c : party.members)
                        if (c.hp > 0) partyAvgLvl += c.level;
                    partyAvgLvl /= (survivors > 0) ? survivors : 1;
                    double guardLvl = 0.0;
                    if (!room.monsterKey.empty()) {
                        const monsters::MonsterDef* gd =
                            registry.find(room.monsterKey);
                        if (gd)
                            guardLvl = rules::monsterEffectiveLevel(
                                gd->hitDice);
                    }
                    int goldShare = treasureXpForGold(
                        t.gold, partyAvgLvl, guardLvl) / survivors;
                    if (goldShare > 0) {
                        snprintf(buf, sizeof buf,
                                 "Treasure worth %d xp each.",
                                 goldShare);
                        log.add(buf);
                        party.gainXp(goldShare, dice, log);
                    }
                }
                if (t.potionHealing) {
                    ++party.potions;
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You find a potion of healing! (%d carried)",
                             party.potions);
                    log.add(buf);
                }
                if (t.magicSword) {
                    log.add("You find a +1 long sword!");
                    // R24: claimed by the first living fighter
                    for (auto& c : party.members) {
                        if (c.hp > 0 &&
                            c.classIndex == rules::CLASS_FIGHTER) {
                            c.weapon.id = items::WPN_LONG_SWORD;
                            c.weapon.plus = 1;
                            log.add(c.name + " claims it.");
                            break;
                        }
                    }
                }
                // R40: +1 dagger â throwable loot. Claimed by the
                // first living member whose melee weapon is either
                // already throwable (an upgrade in plus â dagger
                // over axe/spear swaps hurlability for enchantment)
                // or non-throwable and weaker-armed (dagger damage
                // beats bare fists, matches the 1d4 starter)
                if (t.thrownDagger) {
                    log.add("You find a +1 dagger!");
                    Character* taker = nullptr;
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        bool throwable = (c.weapon.id ==
                                          items::WPN_DAGGER ||
                                          c.weapon.id ==
                                          items::WPN_HAND_AXE ||
                                          c.weapon.id ==
                                          items::WPN_SPEAR);
                        bool upgrade = throwable
                            ? c.weapon.plus < 1
                            : (c.weapon.id == items::WPN_DAGGER ||
                               c.weapon.plus < 1);
                        if (upgrade) { taker = &c; break; }
                    }
                    if (taker) {
                        taker->weapon.id = items::WPN_DAGGER;
                        taker->weapon.plus = 1;
                        log.add(taker->name + " claims it.");
                    } else {
                        log.add("No one can use it; it is left "
                                "behind.");
                    }
                }
                // R28: short bow â claimed by the first living
                // member with an empty ranged slot
                if (t.missileWeapon) {
                    log.add("You find a short bow!");
                    for (auto& c : party.members) {
                        if (c.hp > 0 &&
                            !items::weapon(
                                c.rangedWeapon.id).missile) {
                            c.rangedWeapon.id = items::WPN_SHORT_BOW;
                            // R35: the find includes a quiver
                            c.missileAmmo = 20;
                            log.add(c.name + " takes it.");
                            break;
                        }
                    }
                }
                // R39: a bundle of arrows â given to the first
                // living missile-armed member BELOW the 20 cap,
                // else the least-supplied one (stacking quivers is
                // a simplification: no encumbrance, no cap split)
                if (t.ammoBundle) {
                    Character* taker = nullptr;
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        if (!items::weapon(
                                c.rangedWeapon.id).missile) continue;
                        if (!taker || c.missileAmmo < taker->missileAmmo)
                            taker = &c;
                        if (taker->missileAmmo < 20) break;
                    }
                    if (taker) {
                        taker->missileAmmo += 20;
                        char buf[96];
                        snprintf(buf, sizeof buf,
                                 "You find a bundle of arrows! "
                                 "%s now carries %d.",
                                 taker->name.c_str(),
                                 taker->missileAmmo);
                        log.add(buf);
                    } else {
                        log.add("You find a bundle of arrows, but "
                                "no one can carry more.");
                    }
                }
                // R44: an identify scroll joins the satchel
                if (t.identifyScroll) {
                    ++party.identifyScrolls;
                    log.add("You find a scroll of identify!");
                }
                // R44: an unidentified magic item â the enchant
                // is rolled now but hidden until a scroll is
                // read over it ([I] in town)
                if (t.unidentifiedItem) {
                    Party::PendingItem it;
                    it.kind = (int)rng.below(2);
                    it.plus = 1 +
                        (rng.below(100) < 10 ? 1 : 0);
                    party.unidentified.push_back(it);
                    log.add("You find an unidentified magic "
                            "item â a scribe's scroll would "
                            "serve.");
                }
                room.monsterKey.clear();
                room.count = 0;
                room.looted = true;
            }
        }

        // R56: defeated NPC parties drop their gear. A wandering
        // Character Subtable party (DMG p.176) fights with book-
        // rolled magic items (R55) â the winners strip the
        // fallen: the best enchanted weapon/armor/shield among the
        // SLAIN (survivors keep theirs), plus a coin purse
        // (adventurers carry walking money, not hoards â
        // 2d6 x 10 x dungeon level, the design figure; same
        // 1-gp-1-xp treasure convention as room hoards).
        if (combatRoomIndex < 0 && combat.encounter) {
            int bestWpn = 0, bestArm = 0, bestShd = 0;
            items::WeaponId wpnId = items::WPN_LONG_SWORD;
            items::ArmorId   armId = items::ARMOR_PLATE;
            bool anyFoe = false;
            for (const auto& m : combat.encounter->monsters()) {
                if (!m.isCharacter) continue;
                anyFoe = true;
                if (m.alive()) continue;   // survivors keep gear
                if (m.weapon.plus > bestWpn) {
                    bestWpn = m.weapon.plus;
                    wpnId = m.weapon.id;
                }
                if (m.armor.plus > bestArm) {
                    bestArm = m.armor.plus;
                    armId = m.armor.id;
                }
                if (m.shieldPlus > bestShd)
                    bestShd = m.shieldPlus;
            }
            if (anyFoe) {
                int gp = (int)dice.roll(2, 6, 0) * 10 * dungeonLevel;
                if (gp > 0) {
                    party.gold += gp;
                    party.delveGold += gp;   // R45: the crew's cut
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You strip %d gp from the fallen.",
                             gp);
                    log.add(buf);
                    // R61: DMG p.86 guard rule here too
                    // (the guardian is the NPC party itself;
                    // proxy: average level of the character
                    // foes faced).
                    double partyAvgLvl = 0.0;
                    for (const auto& c : party.members)
                        if (c.hp > 0) partyAvgLvl += c.level;
                    partyAvgLvl /= (survivors > 0) ? survivors : 1;
                    double guardLvl = 0.0;
                    int guardN = 0;
                    for (const auto& m :
                         combat.encounter->monsters()) {
                        if (!m.isCharacter) continue;
                        guardLvl += m.level;
                        ++guardN;
                    }
                    if (guardN > 0) guardLvl /= guardN;
                    int goldShare = treasureXpForGold(
                        gp, partyAvgLvl, guardLvl) / survivors;
                    if (goldShare > 0) {
                        snprintf(buf, sizeof buf,
                                 "Worth %d xp each.", goldShare);
                        log.add(buf);
                        party.gainXp(goldShare, dice, log);
                    }
                }
                if (bestWpn > 0) {
                    const items::WeaponDef& w =
                        items::weapon(wpnId);
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You take a +%d %s from the fallen!",
                             bestWpn, w.name);
                    log.add(buf);
                    int wpnMax = w.smCount * w.smSides + w.smBonus;
                    Character* taker = nullptr;
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        if (c.weapon.plus >= bestWpn) continue;
                        if (c.weapon.id == wpnId) {
                            taker = &c;   // same steel, better steel
                            break;
                        }
                    }
                    if (!taker) {
                        for (auto& c : party.members) {
                            if (c.hp <= 0) continue;
                            if (c.weapon.plus >= bestWpn) continue;
                            const items::WeaponDef& cw =
                                items::weapon(c.weapon.id);
                            if (wpnMax >=
                                cw.smCount * cw.smSides + cw.smBonus)
                                { taker = &c; break; }
                        }
                    }
                    if (taker) {
                        taker->weapon.id = wpnId;
                        taker->weapon.plus = bestWpn;
                        log.add(taker->name + " claims it.");
                    } else {
                        log.add("No one can wield it; it is "
                                "left behind.");
                    }
                }
                if (bestArm > 0) {
                    const items::ArmorDef& a =
                        items::armor(armId);
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You take %s +%d from the fallen!",
                             a.name, bestArm);
                    log.add(buf);
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        if (c.armor.plus >= bestArm) continue;
                        if (!rules::armorAllowed(c.classIndex,
                                                 a.weight))
                            continue;
                        c.armor.id = armId;
                        c.armor.plus = bestArm;
                        log.add(c.name + " claims it.");
                        break;
                    }
                }
                if (bestShd > 0) {
                    char buf[96];
                    snprintf(buf, sizeof buf,
                             "You take a +%d shield from the "
                             "fallen!", bestShd);
                    log.add(buf);
                    for (auto& c : party.members) {
                        if (c.hp <= 0) continue;
                        if (!rules::shieldAllowed(c.classIndex))
                            continue;
                        if (c.shield && c.shieldPlus >= bestShd)
                            continue;
                        c.shield = true;
                        c.shieldPlus = bestShd;
                        log.add(c.name + " claims it.");
                        break;
                    }
                }
            }
        }
    }

    // R24: build the encounter party from the living roster
    std::vector<ai::Actor> partyActors() const {
        std::vector<ai::Actor> v;
        for (const auto& c : party.members)
            if (c.hp > 0)
                v.push_back(c.toActor());
        // R44: the henchman fights alongside the roster
        if (party.henchmanPresent && party.henchmanHp > 0)
            v.push_back(party.henchmanActor());
        return v;
    }

    // R25: shared combat entry â starts the encounter and arms the
    // quaff hook (the hook owns the potion pool and the heal, so
    // the driver stays inventory-free)
    void beginCombat(std::vector<ai::Actor> foes, int roomIndex,
                     const std::string& monsterKey) {
        // R37: mark missile-armed monsters (MM convention: goblins
        // short bow, kobolds sling). The Lua registry data carries
        // no ranged flag, so the app owns this list â verification
        // debt if the Lua keys ever change.
        // R42: also seed rangedRounds from the weapon's short
        // range band (PHB p.39: short bow 50' = 5 bands, sling
        // 50' = 5 bands) â volley rounds before melee closes.
        for (auto& m : foes) {
            if (!m.isCharacter &&
                (monsterKey == "goblin" ||
                     monsterKey == "kobold" ||
                     monsterKey == "hobgoblin")) {   // R44: MM bows
                m.monsterRanged = true;
                m.rangedRounds = 5;   // 50' short range, 10' bands
            }
            // R46: psionic monsters (the registry schema has no
            // psionics field — the app owns the key list, R37
            // pattern)
            if (!m.isCharacter && monsterKey == "mind_flayer")
                m.psionic = true;
        }
        combat.start(partyActors(), std::move(foes),
                     rng.below(0x7FFFFFFF));
        combat.encounter->setQuaffHook(
            [this](ai::Actor& drinker) {
                if (party.potions <= 0) {
                    log.add("The potion satchel is empty!");
                    return;
                }
                int heal = (int)dice.roll(2, 4, 2);
                int before = drinker.hp;
                drinker.hp += heal;
                if (drinker.hp > drinker.maxHp)
                    drinker.hp = drinker.maxHp;   // cap at max HP
                --party.potions;
                char buf[96];
                snprintf(buf, sizeof buf,
                         "%s quaffs a potion (+%d hp, now %d/%d).",
                         drinker.name.c_str(), drinker.hp - before,
                         drinker.hp, drinker.maxHp);
                log.add(buf);
            });
        combatReturnMode = mode;   // R68
        combatRoomIndex = roomIndex;
        combatMonsterKey = monsterKey;
        mode = MODE_COMBAT;
    }

    // R25: explore-mode quaff â heals the most-wounded living
    // member; refuses (without consuming) if everyone is full
    void quaffExplore() {
        if (mode != MODE_EXPLORE) return;
        if (party.potions <= 0) {
            log.add("No potions left.");
            return;
        }
        Character* best = nullptr;
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            if (!best || (c.maxHp - c.hp) > (best->maxHp - best->hp))
                best = &c;
        }
        if (!best) return;
        if (best->hp >= best->maxHp) {
            log.add("No one needs healing.");
            return;
        }
        int heal = (int)dice.roll(2, 4, 2);
        int before = best->hp;
        best->hp += heal;
        if (best->hp > best->maxHp) best->hp = best->maxHp;
        --party.potions;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "%s quaffs a potion (+%d hp, now %d/%d, %d left).",
                 best->name.c_str(), best->hp - before,
                 best->hp, best->maxHp, party.potions);
        log.add(buf);
    }

    // R25: combat quaff â the ACTIVE member drinks this round
    // (round consumed via ACTION_DRINK; effect resolves at the
    // end of the round through the quaff hook)
    void combatQuaff() {
        if (mode != MODE_COMBAT || !combat.encounter || combat.over)
            return;
        if (party.potions <= 0) {
            log.add("No potions left.");
            return;
        }
        combat.encounter->requestDrink(combat.activeMember);
    }

    // R28: the ACTIVE member fires missiles this round â requires
    // a missile weapon in the ranged slot (falls back to melee
    // otherwise, with a log line so the player knows why)
    void combatShoot() {
        if (mode != MODE_COMBAT || !combat.encounter || combat.over)
            return;
        const auto& partyActors = combat.encounter->party();
        if (combat.activeMember < 0 ||
            combat.activeMember >= (int)partyActors.size())
            return;
        if (!partyActors[combat.activeMember].hasRangedWeapon()) {
            log.add("That member has no missile weapon.");
            return;
        }
        // R43: the range must still be open â once the foes have
        // closed, only melee (or a hurled weapon) serves
        if (!combat.encounter->rangeOpen()) {
            log.add("The foes are upon you â no time for "
                    "missiles!");
            return;
        }
        // R35: dry quiver â nothing left to loose
        if (partyActors[combat.activeMember].missileAmmo <= 0) {
            log.add("That member's quiver is empty.");
            return;
        }
        combat.encounter->requestShoot(combat.activeMember);
        log.add("Missiles readied â [space] to resolve the round.");
    }

    // R36: the ACTIVE member hurls their melee weapon this round
    // (dagger/hand axe/spear) â one shot from the weapon's own
    // dice/plus, then bare fists until the fight ends (the weapon
    // is recovered afterward)
    void combatThrow() {
        if (mode != MODE_COMBAT || !combat.encounter || combat.over)
            return;
        const auto& partyActors = combat.encounter->party();
        if (combat.activeMember < 0 ||
            combat.activeMember >= (int)partyActors.size())
            return;
        if (!partyActors[combat.activeMember].meleeThrowable()) {
            log.add("That member has nothing to hurl.");
            return;
        }
        combat.encounter->requestThrow(combat.activeMember);
        log.add("Weapon readied to hurl â [space] to resolve the round.");
    }


    // ------------------------------------------------------------------
    // R50: roll the per-specimen context the XP dispatch needs, at
    // spawn time. Dragons roll age (d8) and HD in their species range
    // ("9-11"); the hydra rolls heads (MM1: 5-12); variable-HD animals
    // roll in their text range ("12-36"). merged_mm1 needs nothing.
    // ------------------------------------------------------------------
    static int rangeLo(const std::string& t) {
        int v = 0; bool any = false;
        for (char c : t) {
            if (isdigit((unsigned char)c)) { v = v*10 + (c-'0'); any = true; }
            else if (any) break;
        }
        return any ? v : 0;
    }
    static int rangeHi(const std::string& t) {   // last int in "12 to 36"
        int last = 0;
        for (size_t i = 0; i < t.size();) {
            if (isdigit((unsigned char)t[i])) {
                int v = 0;
                while (i < t.size() && isdigit((unsigned char)t[i])) {
                    v = v*10 + (t[i]-'0'); ++i;
                }
                last = v;
            } else ++i;
        }
        return last;
    }
    monsters::xp::SpawnContext rollSpawnContext(
            const monsters::MonsterDef* def) {
        monsters::xp::SpawnContext ctx;
        if (!def) return ctx;
        int lo = rangeLo(def->hitDiceText);
        int hi = rangeHi(def->hitDiceText);
        if (lo < 1) lo = def->hitDiceNum;
        if (hi < lo) hi = lo;
        const std::string& src = def->xpSource;
        if (src == "age_bracket") {
            ctx.ageBracket = 1 + (int)dice.roll(1, 8, 0);   // age 1-8
            ctx.hd = lo + (int)rng.below((uint32_t)(hi - lo + 1));
        } else if (src == "by_head_count") {
            ctx.heads = 4 + (int)dice.roll(1, 8, 0);         // 5-12
            ctx.hd = ctx.heads;
        } else if (src == "by_hit_dice") {
            ctx.hd = lo + (int)rng.below((uint32_t)(hi - lo + 1));
        }
        // by_level: 0-level default; the dungeon generator assigns
        // class/levels when it starts placing leaders (R51)
        return ctx;
    }

    // R51: fixed hp-per-die for the dispatch types that carry it
    // (dragon age bracket 1-8; hydra heads are a full 8 hp each,
    // MM1). Others roll dice in toActor.
    static int hpPerDieFor(const monsters::MonsterDef* def,
                           const monsters::xp::SpawnContext& c) {
        if (!def) return 0;
        if (def->xpSource == "age_bracket")  return c.ageBracket;
        if (def->xpSource == "by_head_count") return 8;
        return 0;
    }

    // R52: one roll on the DMG Appendix C chain for this depth
    // (d20 -> Determination Matrix -> level table -> subtable)
    dm::DungeonEncounter rollDmEncounter() {
        return dm::rollDungeonEncounter(registry, dice,
            (int)dice.roll(1, 20, 0),
            (int)dice.roll(1, 100, 0),
            (int)dice.roll(1, 100, 0),
            dungeonLevel);
    }

    // R52: build the foe roster from a DMG encounter. Each
    // specimen rolls its own context (R51), pinned to the DMG
    // ranges where the table carries them: hydra heads, dragon
    // age bracket (hp/die, the subtable's Age Category column).
    std::vector<ai::Actor> buildFoesFromDm(
            const dm::DungeonEncounter& e) {
        std::vector<ai::Actor> foes;
        if (e.key.empty() || e.count <= 0) return foes;
        const monsters::MonsterDef* def = registry.find(e.key);
        if (!def) return foes;
        foeCtxs.clear();
        for (int i = 0; i < e.count; ++i) {
            monsters::xp::SpawnContext ctx = rollSpawnContext(def);
            if (e.headsLo > 0 && e.headsHi >= e.headsLo) {
                ctx.heads = e.headsLo + (int)rng.below(
                    (uint32_t)(e.headsHi - e.headsLo + 1));
                ctx.hd = ctx.heads;   // by_head_count: heads = HD
            }
            if (e.ageLo > 0 && e.ageHi >= e.ageLo) {
                ctx.ageBracket = e.ageLo + (int)rng.below(
                    (uint32_t)(e.ageHi - e.ageLo + 1));
            }
            foeCtxs.push_back(ctx);
            foes.push_back(registry.toActor(e.key, dice, -1,
                                            ctx.hd,
                                            hpPerDieFor(def, ctx)));
        }
        return foes;
    }

    // R52: a stored room lair back as a DMG encounter (the
    // ranges survive population)
    dm::DungeonEncounter encFromRoom(const RoomOccupant& r) {
        dm::DungeonEncounter e;
        e.key = r.monsterKey;
        e.count = r.count;
        e.headsLo = r.headsLo; e.headsHi = r.headsHi;
        e.ageLo = r.ageLo;     e.ageHi = r.ageHi;
        return e;
    }

    // R53: kit for a classed NPC (DMG p.176 — 1st level
    // scale/chain with standard weapons, 2nd+ plate; men-at-arms
    // studded leather and spear; MUs unarmored with quarterstaff,
    // thieves leather and short sword)
    void kitNpc(ai::Actor& a, const dm::PartyMember& m) {
        using namespace items;
        if (m.manAtArms) {
            a.armor.id = ARMOR_STUDDED_LEATHER;
            a.weapon.id = WPN_SPEAR;
            a.shield = false;
            return;
        }
        switch (m.classIndex) {
            case rules::CLASS_MAGIC_USER:
                a.armor.id = ARMOR_NONE_EQUIPPED;
                a.weapon.id = WPN_QUARTERSTAFF;
                a.shield = false;
                break;
            case rules::CLASS_CLERIC:
                a.armor.id = m.level >= 2 ? ARMOR_PLATE
                                          : ARMOR_CHAIN_MAIL;
                a.weapon.id = WPN_MACE;
                a.shield = true;
                break;
            case rules::CLASS_THIEF:
                a.armor.id = ARMOR_LEATHER;
                a.weapon.id = WPN_SHORT_SWORD;
                a.shield = false;
                break;
            default:   // fighter group
                a.armor.id = m.level >= 2 ? ARMOR_PLATE
                                          : ARMOR_CHAIN_MAIL;
                a.weapon.id = WPN_LONG_SWORD;
                a.shield = true;
                break;
        }
    }

    // R53: name for a party foe (short flavor, level-tagged)
    std::string npcName(const dm::PartyMember& m, int index) {
        const char* base = "Adventurer";
        switch (m.classIndex) {
            case rules::CLASS_MAGIC_USER: base = "Conjurer";   break;
            case rules::CLASS_CLERIC:     base = "Acolyte";    break;
            case rules::CLASS_THIEF:      base = "Cutpurse";   break;
            default:                      base = "Sellsword";  break;
        }
        char buf[32];
        if (m.manAtArms)
            snprintf(buf, sizeof buf, "Man-at-arms %d", index);
        else if (m.henchman)
            snprintf(buf, sizeof buf, "Hireling %d", index);
        else
            snprintf(buf, sizeof buf, "%s %d", base, index);
        return buf;
    }

    // R53: build the foe roster from a Character Subtable party.
    // Each member is a real classed combatant (the Actor character
    // path); hp rolls the class hit die per level (fixed hp beyond
    // the name cap, R49 convention), men-at-arms take the 0-level
    // man's 1-6. Foe contexts carry class/level for by_level XP.
    std::vector<ai::Actor> buildFoesFromParty(
            const dm::CharacterParty& party) {
        std::vector<ai::Actor> foes;
        if (party.empty()) return foes;
        foeCtxs.clear();
        int index = 1;
        for (const auto& m : party.members) {
            ai::Actor a;
            a.team = 1;
            a.isCharacter = true;
            a.classIndex = m.classIndex;
            a.level = m.level > 0 ? m.level : 1;   // matrices need 1+
            a.name = npcName(m, index++);
            kitNpc(a, m);
            // R55: DMG p.176-177 magic items â the rolled
            // pluses land on the equipped gear (best-of, per the
            // ladder rolls in dm::rollCharacterParty)
            // DMG p.177: items must be SUITABLE to the individual
            // (the book's own selection rule) â an MU wears
            // no armor/shield, and only shield-allowed classes
            // carry a magic shield (rules::shieldAllowed)
            if (m.wpnPlus > 0) a.weapon.plus = m.wpnPlus;
            if (m.armPlus > 0 &&
                m.classIndex != rules::CLASS_MAGIC_USER)
                a.armor.plus = m.armPlus;
            if (m.shdPlus > 0 &&
                rules::shieldAllowed(m.classIndex)) {
                a.shield = true;      // a +N shield implies a shield
                a.shieldPlus = m.shdPlus;
            }
            // rngPlus: NPC foes carry no ranged slot this round
            // (documented simplification â R28 missile hooks
            // are party-driven); missile pluses re-roll as flavor
            // R57: PERSONAE-grade abilities (DMG p.87 + p.176):
            // 3d6 per score, then race adjustments (race rolled
            // on the p.176 table: 01-25 dwarf, 26-50 elf, 51-60
            // gnome, 61-85 half-elf, 86-95 halfling, 96-00
            // half-orc) and class adjustments per the p.87 table.
            // Multi-class (p.176, ~20% of non-humans) is beyond
            // the engine's four single classes â race
            // adjusts abilities only (documented simplification).
            int ab[6];
            for (int i = 0; i < 6; ++i)
                ab[i] = (int)dice.roll(3, 6, 0);
            enum { S_, I_, W_, D_, C_, H_ };  // str int wis dex con cha
            int raceRoll = (int)dice.roll(1, 100, 0);
            if (raceRoll <= 25) {            // dwarf
                ab[S_] += 1; ab[C_] += 1; ab[H_] -= 1;
            } else if (raceRoll <= 50) {      // elf
                ab[I_] += 1; ab[D_] += 1;
            } else if (raceRoll <= 60) {      // gnome
                ab[W_] += 1; ab[C_] += 1; ab[H_] -= 1;
            } else if (raceRoll <= 95 && raceRoll >= 86) {  // halfling
                ab[D_] += 1; ab[C_] += 1;
            }   // half-elf / half-orc: no printed adjustment
            if (m.level < 1) {
                // p.87 Occupation: Mercenary (level 0) â
                // STR +1, CON +3 (men-at-arms)
                ab[S_] += 1; ab[C_] += 3;
            } else {
                // p.87 Class table (in addition to the PHB note;
                // additive here, the engine has no minimums pass)
                switch (m.classIndex) {
                    case rules::CLASS_CLERIC:
                        ab[W_] += 2; break;
                    case rules::CLASS_MAGIC_USER:
                        ab[I_] += 2; ab[D_] += 1; break;
                    case rules::CLASS_THIEF:
                        ab[D_] += 2; ab[I_] += 1; break;
                    default:   // fighter group (fighter/paladin/
                        ab[S_] += 2; ab[C_] += 1; break;  // ranger)
                }
            }
            for (int i = 0; i < 6; ++i) {
                if (ab[i] > 18) ab[i] = 18;   // normal limits
                if (ab[i] < 3) ab[i] = 3;
            }
            a.str = (uint8_t)ab[S_]; a.intel = (uint8_t)ab[I_];
            a.wis = (uint8_t)ab[W_]; a.dex = (uint8_t)ab[D_];
            a.con = (uint8_t)ab[C_]; a.cha = (uint8_t)ab[H_];
            // exceptional strength: fighter group at STR 18
            if (m.classIndex == rules::CLASS_FIGHTER &&
                a.str == 18) {
                a.exStr.has = true;
                a.exStr.pct = rules::rollExceptionalStrength(dice);
            }
            // hp: the canonical per-level roll (R4b signature)
            // with the PERSONAE Con adjustment per die
            int conAdj = rules::conHPAdjustment(m.classIndex, a.con);
            int hp = 0;
            if (m.level < 1) {
                hp = (int)dice.roll(1, 6, 0);   // 0-level man
            } else {
                for (int lv = 1; lv <= m.level; ++lv)
                    hp += rules::rollHitPoints(m.classIndex, lv,
                                               conAdj, dice);
            }
            if (m.level < 1 && hp < 4) hp = 4;   // p.87: mercenary min
            if (hp < 1) hp = 1;
            a.hp = a.maxHp = hp;
            // DMG p.176: character parties do not check morale —
            // play them as player characters
            a.morale = dm::MORALE_FANATIC;
            // spell slots (R54: the foe AI casts â see
            // ai/actor.cpp foeSpellChoice; slots deplete)
            spells::SpellClass sc = m.classIndex ==
                rules::CLASS_MAGIC_USER ? spells::SPELL_MU
                : m.classIndex == rules::CLASS_CLERIC
                    ? spells::SPELL_CLERIC : spells::SPELL_MU;
            if (m.level > 0 &&
                (m.classIndex == rules::CLASS_MAGIC_USER ||
                 m.classIndex == rules::CLASS_CLERIC)) {
                for (int lv = 0; lv < 6; ++lv)
                    a.slotsByLevel[lv] = spells::spellSlots(
                        sc, a.level, lv + 1);
                if (m.classIndex == rules::CLASS_MAGIC_USER) {
                    a.knownSpells.push_back(spells::MU_MAGIC_MISSILE);
                    a.knownSpells.push_back(spells::MU_SLEEP);
                    a.knownSpells.push_back(spells::MU_SHIELD);
                    // R54: the deep-dungeon conjurer's heavier
                    // artillery (3rd-level slots at MU 5+)
                    a.knownSpells.push_back(spells::MU_FIREBALL);
                    a.knownSpells.push_back(spells::MU_LIGHTNING_BOLT);
                }
            }
            monsters::xp::SpawnContext ctx;   // R53: by_level context
            ctx.classIndex = m.classIndex;
            ctx.level = m.level;   // 0 = the 0-level man ladder
            ctx.conAdj = conAdj;  // R57: real Con, xp parity
            foeCtxs.push_back(ctx);
            foes.push_back(a);
        }
        return foes;
    }

    void spawnRoomEncounter(int roomIndex) {
        if (mode == MODE_COMBAT) return;
        if (!party.alive()) return;
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.monsterKey.empty()) return;

        const monsters::MonsterDef* def = registry.find(room.monsterKey);
        // R52: foes build through the DMG-range path (hydra
        // heads / dragon age brackets, stored at population)
        std::vector<ai::Actor> foes =
            buildFoesFromDm(encFromRoom(room));
        if (foes.empty()) return;
        const char* mname = def ? def->name.c_str() : "monster";
        char buf[96];
        if (room.count == 1)
            snprintf(buf, sizeof buf, "A %s leaps at you!", mname);
        else
            snprintf(buf, sizeof buf, "%d %ss leap at you!",
                     room.count, mname);
        log.add(buf);

        beginCombat(std::move(foes), roomIndex, room.monsterKey);
    }

    void spawnWanderingEncounter() {        if (mode == MODE_COMBAT) return;
        if (!party.alive()) return;

        // R52: the real DMG Appendix C roll — Determination
        // Matrix, level table, subtables (Human/Dragon/etc.).
        // An empty key is NO ENCOUNTER (or an R53 re-roll row).
        dm::DungeonEncounter e = rollDmEncounter();
        if (e.isParty) {
            // R53: a Character Subtable party (DMG p.176)
            std::vector<ai::Actor> foes = buildFoesFromParty(e.party);
            if (foes.empty()) return;
            // R58: DMG p.63 Encounter Reactions + p.176
            // Confrontation — the strangers react before steel
            // is drawn. Charisma adjustment follows the engine's
            // best-living-Cha spokesman convention (henchman
            // hire, R44); the p.63 loyalty adjustment is not
            // modeled (documented simplification). The p.176
            // "never join with adventurers" rule keeps friendly
            // outcomes pass-by; R62 adds small favors — friendly
            // parties sometimes part with a potion or a coin
            // pouch (no printed table: fiction extension). Gift
            // gold earns NO xp — p.86 awards xp for treasure
            // taken from a challenge; a gift is freely given.
            // R62 also colors the meeting with the NPC party's
            // race (DMG p.192 race check, fiction-only).
            int chaAdj = 0;
            for (const auto& c : party.members) {
                if (c.hp <= 0) continue;
                int adj = rules::chaReactionAdj(c.abilities.cha);
                if (adj > chaAdj) chaAdj = adj;
            }
            int partyLevels = 0;
            for (const auto& c : party.members)
                if (c.hp > 0) partyLevels += c.level;
            if (party.henchmanPresent)
                partyLevels += party.henchmanLevel;
            int npcLevels = 0;
            for (const auto& m : e.party.members)
                npcLevels += m.level;
            dm::PartyReaction react = dm::rollPartyReaction(
                dice, chaAdj, npcLevels < partyLevels);
            char buf[96];
            // R62: the NPC party's racial makeup colors the
            // meeting — a wholly single-race party of dwarves
            // reads as "dwarven adventurers" (p.192 fiction)
            const char* racePrefix = "";
            {
                int byRace[7] = {0};
                int total = 0;
                for (const auto& m : e.party.members) {
                    if (m.manAtArms) continue;
                    ++byRace[m.race];
                    ++total;
                }
                for (int r = 1; r < 7; ++r)
                    if (total > 0 && byRace[r] == total) {
                        racePrefix = dm::npcRaceAdjective(r);
                        break;
                    }
            }
            switch (react) {
            case dm::PartyReaction::ViolentlyHostile:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers attack without a "
                         "word!", racePrefix, e.count);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            case dm::PartyReaction::Hostile:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers size you up and "
                         "attack!", racePrefix, e.count);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            case dm::PartyReaction::UncertainNegative:
                // p.63: 55% prone toward negative — they may
                // still strike, or let the party pass
                if ((int)dice.roll(1, 100, 0) <= 55) {
                    snprintf(buf, sizeof buf,
                             "%s%d wary adventurers draw "
                             "steel!", racePrefix, e.count);
                    log.add(buf);
                    beginCombat(std::move(foes), -1, e.key);
                    return;
                }
                log.add("The adventurers eye you warily, "
                        "then let you pass.");
                return;
            case dm::PartyReaction::Neutral:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers pass by, "
                         "uninterested.", racePrefix, e.count);
                log.add(buf);
                return;
            case dm::PartyReaction::UncertainPositive:
                // p.63: 55% prone toward positive — a hail
                // instead of silence
                if ((int)dice.roll(1, 100, 0) <= 55)
                    log.add("The adventurers hail you "
                            "and move on.");
                else
                    log.add("The adventurers nod and pass by.");
                return;
            case dm::PartyReaction::Friendly:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers hail you, share "
                         "word of the dungeon, and depart.",
                         racePrefix, e.count);
                log.add(buf);
                // R62: a friendly party may part with a small
                // favor (d6: 1 potion, 2 coin pouch, else words)
                {
                    int favor = (int)dice.roll(1, 6, 0);
                    if (favor == 1) {
                        ++party.potions;
                        log.add("One presses a potion of "
                                "healing on you before going.");
                    } else if (favor == 2) {
                        int gift = (int)dice.roll(2, 6, 0) * 10
                                 * dungeonLevel;
                        party.gold += gift;
                        party.delveGold += gift;
                        snprintf(buf, sizeof buf,
                                 "They toss a pouch of %d gp "
                                 "to your company!", gift);
                        log.add(buf);
                    }
                }
                return;
            case dm::PartyReaction::Enthusiastic:
                snprintf(buf, sizeof buf,
                         "%s%d adventurers greet you warmly "
                         "and warn of dangers ahead!",
                         racePrefix, e.count);
                log.add(buf);
                // R62: enthusiastic parties favor more often
                // (d6: 1-2 potion, 3 coin pouch, else words)
                {
                    int favor = (int)dice.roll(1, 6, 0);
                    if (favor <= 2) {
                        ++party.potions;
                        log.add("One presses a potion of "
                                "healing on you before going.");
                    } else if (favor == 3) {
                        int gift = (int)dice.roll(2, 6, 0) * 10
                                 * dungeonLevel;
                        party.gold += gift;
                        party.delveGold += gift;
                        snprintf(buf, sizeof buf,
                                 "They toss a pouch of %d gp "
                                 "to your company!", gift);
                        log.add(buf);
                    }
                }
                return;
            }
            return;
        }
        if (e.key.empty() || e.count <= 0) return;
        std::vector<ai::Actor> foes = buildFoesFromDm(e);
        if (foes.empty()) return;

        char buf[96];
        if (e.count == 1)
            snprintf(buf, sizeof buf, "A wandering %s attacks!",
                     e.key.c_str());
        else
            snprintf(buf, sizeof buf, "%d wandering %ss attack!",
                     e.count, e.key.c_str());
        log.add(buf);

        beginCombat(std::move(foes), -1, e.key);
    }

    void playerFlee() {
        if (mode != MODE_COMBAT || !combat.encounter || combat.over)
            return;
        combat.requestFlee();
        combat.step();
        if (combat.over) endCombat();
    }

    void endCombat() {
        if (combat.encounter) {
            // R24: sync fight results back to the roster BY NAME
            // (hp, level â energy drain can strip levels)
            for (const auto& a : combat.encounter->party()) {
                for (auto& c : party.members) {
                    if (c.name != a.name) continue;
                    c.hp = a.hp;
                    c.maxHp = a.maxHp;
                    c.level = a.level;
                    // R34: spent slots persist (per-day tracking)
                    for (int lv = 0; lv < 6; ++lv)   // R46
                        c.slotsByLevel[lv] = a.slotsByLevel[lv];
                    // R35: spent ammo persists (quiver count)
                    c.missileAmmo = a.missileAmmo;
                    break;
                }
                // R44: the henchman syncs back too (hp and any
                // energy-drained levels)
                if (party.henchmanPresent &&
                    a.name == party.henchmanName) {
                    party.henchmanHp = a.hp;
                    party.henchmanMaxHp = a.maxHp;
                    party.henchmanLevel = a.level;
                    if (party.henchmanHp <= 0) {
                        log.add(party.henchmanName +
                                " has fallen in the fight.");
                        party.henchmanPresent = false;
                    }
                }
            }

            awardVictory();

            const char* outcome = "?";
            switch (combat.lastResult) {
                case 0: outcome = "Victory!"; break;
                case 1: outcome = "The party has fallen..."; break;
                case 2: outcome = "You fled."; break;
                case 3: outcome = "The monsters fled."; break;
                default: outcome = "The fight ends."; break;
            }
            log.add(outcome);

            if (combat.lastResult == 1) {
                log.add("GAME OVER - press N to roll a new party.");
            } else if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new party.");
            }
        }
        combat.encounter.reset();
        mode = combatReturnMode;   // R68: back to the trail
        if (mode == MODE_OVERLAND) checkArrivedHome();
    }

    // ---- R68: overland travel ---------------------------------------------

    // [O] from town — set out along the wild roads
    void enterOverland() {
        if (mode != MODE_TOWN) return;
        overland = OverlandState{};
        mode = MODE_OVERLAND;
        log.add("The company sets out along the wild roads.");
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Day 1 — the %s, within sight of town.",
                 overlandTerrainName(overland.terrain));
        log.add(buf);
    }

    // [1-8] — steer the route's terrain column (campaign-map
    // fiction; the castle and encounter rolls both use it)
    void overlandSetTerrain(int t) {
        if (mode != MODE_OVERLAND) return;
        if (t < dm::T_PLAIN || t > dm::T_MARSH) return;
        if (overland.castle.pending) {
            log.add("Decide the castle first — [A]pproach or [P]ass.");
            return;
        }
        if (t == overland.terrain) return;
        overland.terrain = t;
        char buf[96];
        snprintf(buf, sizeof buf, "You steer toward the %s.",
                 overlandTerrainName(t));
        log.add(buf);
    }

    // The p.182 bands: the first days out are the patrolled
    // lands; beyond them, the wilderness
    bool overlandInhabited() const {
        return overland.daysOut < kOverlandInhabitedDays;
    }

    dm::OutdoorClime overlandClime() const {
        return overlandInhabited()
            ? dm::OC_TEMPERATE_INHABITED   // p.182: inhabited set
            : dm::OC_TEMPERATE_WILD;       // p.182: wilderness set
    }

    // One encounter check — a march day or a night at camp (the
    // cadence is this campaign's documented fiction; the DMG
    // checks "whenever an encounter is indicated").
    void overlandStep() {
        if (mode != MODE_OVERLAND || !party.alive()) return;
        if (overland.castle.pending) return;
        int d20 = (int)dice.roll(1, 20, 0);
        if (overlandInhabited()) {
            // p.182: "WHEN AN ENCOUNTER IN SUCH AN AREA IS
            // INDICATED, ROLL d20; 5 IN 20 ARE ENCOUNTERS WITH
            // A PATROL."
            if (d20 <= 5) { overlandPatrol(); return; }
        } else {
            // p.182: "roll d20; 1 in 20 is an encounter which
            // discovers such a stronghold."
            if (d20 == 1) { overlandDiscoverCastle(); return; }
        }
        overlandWildEncounter();
    }

    // The wilderness itself: one roll on the R63 outdoor tables
    // for the route's clime and terrain column
    void overlandWildEncounter() {
        dm::DungeonEncounter e = dm::rollOutdoorEncounter(
            registry, dice,
            (int)dice.roll(1, 100, 0), (int)dice.roll(1, 100, 0),
            overlandClime(),
            (dm::OutdoorTerrain)overland.terrain);
        if (e.isParty) {
            // the Men Subtable Character row — a wilderness
            // character party of levels 7-10 (R63, p.187 note)
            overlandMeeting(e, "adventurers", true, false);
            return;
        }
        if (e.key.empty() || e.count <= 0) {
            log.add("The way passes without incident.");
            return;
        }
        std::vector<ai::Actor> foes = buildFoesFromDm(e);
        if (foes.empty()) return;
        char buf[96];
        if (e.count == 1)
            snprintf(buf, sizeof buf, "A wild %s attacks!",
                     e.key.c_str());
        else
            snprintf(buf, sizeof buf, "%d wild %ss attack!",
                     e.count, e.key.c_str());
        log.add(buf);
        beginCombat(std::move(foes), -1, e.key);
    }

    // A patrol of the inhabited lands (R67 rollPatrol; the
    // "ranger, where applicable" leader is area fiction — this
    // campaign's patrols are fighter-led, documented)
    void overlandPatrol() {
        dm::DungeonEncounter e;
        e.isParty = true;
        e.key = "character_party";
        e.party = dm::rollPatrol(dice, false);
        e.count = (int)e.party.members.size();
        if (e.count <= 0) return;
        log.add("Riders on the road — a patrol!");
        overlandMeeting(e, "patrol", false, false);
    }

    // R58 party-reaction meeting (DMG p.63 Encounter Reactions +
    // the p.176 Confrontation paragraph), overland flavor: the
    // best-living-Cha spokesman, the weaker-side adjustment,
    // hostile steel or a peaceful pass. favors: the R62 friendly
    // parting gifts (a potion or a coin pouch); shelter: friendly
    // garrisons take the company in for the night.
    void overlandMeeting(dm::DungeonEncounter& e, const char* noun,
                         bool favors, bool shelter) {
        std::vector<ai::Actor> foes = buildFoesFromParty(e.party);
        if (foes.empty()) return;
        int chaAdj = 0;
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            int adj = rules::chaReactionAdj(c.abilities.cha);
            if (adj > chaAdj) chaAdj = adj;
        }
        int partyLevels = 0;
        for (const auto& c : party.members)
            if (c.hp > 0) partyLevels += c.level;
        if (party.henchmanPresent)
            partyLevels += party.henchmanLevel;
        int npcLevels = 0;
        for (const auto& m : e.party.members)
            npcLevels += m.level;
        dm::PartyReaction react = dm::rollPartyReaction(
            dice, chaAdj, npcLevels < partyLevels);
        char buf[96];
        switch (react) {
            case dm::PartyReaction::ViolentlyHostile:
                snprintf(buf, sizeof buf,
                         "The %s attacks without a word!", noun);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            case dm::PartyReaction::Hostile:
                snprintf(buf, sizeof buf,
                         "The %s sizes you up and attacks!", noun);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            case dm::PartyReaction::UncertainNegative:
                // p.63: 55% prone toward negative
                if ((int)dice.roll(1, 100, 0) <= 55) {
                    snprintf(buf, sizeof buf,
                             "The %s draws steel!", noun);
                    log.add(buf);
                    beginCombat(std::move(foes), -1, e.key);
                    return;
                }
                snprintf(buf, sizeof buf,
                         "The %s challenges you, then moves along.",
                         noun);
                log.add(buf);
                return;
            case dm::PartyReaction::Neutral:
                snprintf(buf, sizeof buf,
                         "The %s passes by, uninterested.", noun);
                log.add(buf);
                return;
            case dm::PartyReaction::UncertainPositive:
                if ((int)dice.roll(1, 100, 0) <= 55)
                    log.add("They hail you and move on.");
                else
                    log.add("They nod and pass by.");
                if (shelter) overlandSafeCamp(
                    "They point you to shelter by their fire.");
                return;
            case dm::PartyReaction::Friendly:
                snprintf(buf, sizeof buf,
                         "The %s hails you, shares word of the "
                         "trail, and departs.", noun);
                log.add(buf);
                if (shelter) overlandSafeCamp(
                    "You are welcomed to their hall for the night.");
                if (favors) {
                    int favor = (int)dice.roll(1, 6, 0);
                    if (favor == 1) {
                        ++party.potions;
                        log.add("One presses a potion of healing "
                                "on you before going.");
                    } else if (favor == 2) {
                        int gift = (int)dice.roll(2, 6, 0) * 10;
                        party.gold += gift;
                        party.delveGold += gift;
                        snprintf(buf, sizeof buf,
                                 "They toss a pouch of %d gp to "
                                 "your company!", gift);
                        log.add(buf);
                    }
                }
                return;
            case dm::PartyReaction::Enthusiastic:
                snprintf(buf, sizeof buf,
                         "The %s greets you warmly and warns of "
                         "dangers ahead!", noun);
                log.add(buf);
                if (shelter) overlandSafeCamp(
                    "You feast in their hall until morning.");
                if (favors) {
                    int favor = (int)dice.roll(1, 6, 0);
                    if (favor <= 2) {
                        ++party.potions;
                        log.add("One presses a potion of healing "
                                "on you before going.");
                    } else if (favor == 3) {
                        int gift = (int)dice.roll(2, 6, 0) * 10;
                        party.gold += gift;
                        party.delveGold += gift;
                        snprintf(buf, sizeof buf,
                                 "They toss a pouch of %d gp to "
                                 "your company!", gift);
                        log.add(buf);
                    }
                }
                return;
        }
    }

    // A completed night's rest on the trail (the R34/R38
    // convention: slots, quivers, 1 hp per level)
    void overlandSafeCamp(const char* why) {
        restoreSlots();
        restockAmmo();
        for (auto& c : party.members) {
            if (c.hp <= 0) continue;
            int heal = c.level;
            if (c.hp + heal > c.maxHp) heal = c.maxHp - c.hp;
            if (heal > 0) c.hp += heal;
        }
        log.add(why);
        log.add("The company rests. Spells and wounds mend.");
    }

    // p.182: the party is within visual range of the
    // stronghold — 1/2 to 5 miles; the R67 builders do the rest
    void overlandDiscoverCastle() {
        overland.castle.pending = true;
        overland.castle.type =
            dm::rollCastleType((int)dice.roll(1, 100, 0));
        overland.castle.aware =
            dm::castleAwareness((int)dice.roll(1, 6, 0));
        overland.castle.pctile = (int)dice.roll(1, 100, 0);
        dm::CastleArtillery art =
            dm::castleArtillery(overland.castle.type);
        char buf[160];
        snprintf(buf, sizeof buf, "A %s rises in the distance!",
                 overland.castle.type.type);
        log.add(buf);
        snprintf(buf, sizeof buf,
                 "Its walls mount %d ballistae, %d catapults, "
                 "%d cauldrons of oil.",
                 art.ballistae, art.lightCatapults, art.oilCauldrons);
        log.add(buf);
        switch (overland.castle.aware) {
            case dm::CASTLE_OCCUPANTS_AWARE:
                // p.183: surprised on 1 — "the fortress occupants
                // know they are there"
                log.add("Watch fires flare — the occupants know "
                        "you are there!");
                overlandApproach();
                return;
            case dm::CASTLE_OCCUPANTS_OUTSIDE:
                // p.183: surprise 2+ — the occupants are "actually
                // outside the place and within normal surprise
                // distance"
                log.add("Riders from the castle are already "
                        "outside the walls!");
                overlandApproach();
                return;
            default:
                log.add("Its occupants have not marked you — "
                        "[A]pproach or [P]ass by.");
                return;
        }
    }

    // [A] — resolve the castle: Table II (the discovery roll's
    // percentile) and the R67 builders
    void overlandApproach() {
        if (mode != MODE_OVERLAND) return;
        if (!overland.castle.pending) return;
        overland.castle.pending = false;
        dm::CastleType t = overland.castle.type;
        dm::CastleInhabitants inh = dm::castleInhabitants(
            overland.castle.pctile, t.size);
        int pctile2 = (int)dice.roll(1, 100, 0);
        char buf[160];
        switch (inh) {
            case dm::CASTLE_TOTALLY_DESERTED:
                // p.183: "in disrepair and upon close inspection
                // appears empty" — the ruin shelters the company
                // (fiction: a safe night's rest)
                snprintf(buf, sizeof buf,
                         "The %s is long deserted — empty halls "
                         "and rotted gates.", t.type);
                log.add(buf);
                overlandSafeCamp("You shelter in the ruin; the "
                                 "night passes undisturbed.");
                return;
            case dm::CASTLE_DESERTED_MONSTER: {
                // p.183: "appears as totally deserted... but entry
                // into the construction will discover the monster"
                // — the OUTDOOR tables, ignoring men
                snprintf(buf, sizeof buf,
                         "The %s looks deserted — but something "
                         "lairs within!", t.type);
                log.add(buf);
                dm::DungeonEncounter e;
                int guard = 0;
                do {
                    e = dm::rollOutdoorEncounter(
                        registry, dice,
                        (int)dice.roll(1, 100, 0),
                        (int)dice.roll(1, 100, 0),
                        dm::OC_TEMPERATE_WILD,
                        (dm::OutdoorTerrain)overland.terrain);
                } while (guard++ < 24 &&
                         (e.key.empty() || overlandIndicatesMen(e)));
                if (e.key.empty() || e.count <= 0) {
                    log.add("The halls stand silent.");
                    return;
                }
                std::vector<ai::Actor> foes = buildFoesFromDm(e);
                if (foes.empty()) return;
                if (e.count == 1)
                    snprintf(buf, sizeof buf,
                             "The lair's tenant — a wild %s — "
                             "springs its ambush!", e.key.c_str());
                else
                    snprintf(buf, sizeof buf,
                             "The lair's tenants — %d wild %ss — "
                             "spring their ambush!",
                             e.count, e.key.c_str());
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            }
            case dm::CASTLE_HUMANS: {
                // Sub-Table II.A: bandits/berserkers/dervishes;
                // "numbers... are given in the MONSTER MANUAL
                // under the heading of MEN" — the registry
                const char* key =
                    dm::castleHumansType(pctile2);
                int count =
                    dm::castleHumansCount(registry, dice, key);
                if (count <= 0) count = 1;
                dm::DungeonEncounter e;
                e.key = key;
                e.count = count;
                std::vector<ai::Actor> foes = buildFoesFromDm(e);
                if (foes.empty()) {
                    log.add("The brutes are gone into the hills.");
                    return;
                }
                const monsters::MonsterDef* def = registry.find(key);
                snprintf(buf, sizeof buf,
                         "The %s is a den of %ss — %d attack!",
                         t.type,
                         def ? def->name.c_str() : key,
                         count);
                log.add(buf);
                beginCombat(std::move(foes), -1, e.key);
                return;
            }
            case dm::CASTLE_CHARACTER_TYPES: {
                // Sub-Table II.B: the master and 2-5 henchmen
                // (R67 builders), met by the R58 reaction
                dm::PartyMember master =
                    dm::rollCastleMaster(dice, pctile2);
                dm::CharacterParty hench =
                    dm::rollCastleHenchmen(dice, master);
                dm::DungeonEncounter e;
                e.isParty = true;
                e.key = "character_party";
                e.party.members.push_back(master);
                for (const auto& m : hench.members)
                    e.party.members.push_back(m);
                e.count = (int)e.party.members.size();
                if (e.count <= 0) return;
                snprintf(buf, sizeof buf,
                         "A banner flies over the %s — its master "
                         "rides out to meet you.", t.type);
                log.add(buf);
                overlandMeeting(e, "garrison", false, true);
                // falls through to the arrival check (combat
                // started by a hostile meeting is mode-guarded)
            }
        }
        // peaceful resolutions complete a homeward last league
        // (combat paths arrive via endCombat instead)
        checkArrivedHome();
    }

    // [P] — give the stronghold a wide berth
    void overlandPass() {
        if (mode != MODE_OVERLAND) return;
        if (!overland.castle.pending) return;
        overland.castle.pending = false;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "You give the %s a wide berth and press on.",
                 overland.castle.type.type);
        log.add(buf);
        checkArrivedHome();   // a bypassed castle on the last league
    }

    // [T] — a day's march outward
    void overlandTravel() {
        if (mode != MODE_OVERLAND) return;
        if (overland.castle.pending) {
            log.add("Decide the castle first — [A]pproach or [P]ass.");
            return;
        }
        if (!party.alive()) return;
        overland.homeward = false;
        ++overland.day;
        ++overland.daysOut;
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d — the %s.",
                 overland.day, overlandTerrainName(overland.terrain));
        log.add(buf);
        overlandStep();
        checkArrivedHome();   // defensive no-op when daysOut > 0
    }

    // [H] — a day's march back toward town
    void overlandHomeward() {
        if (mode != MODE_OVERLAND) return;
        if (overland.castle.pending) {
            log.add("Decide the castle first — [A]pproach or [P]ass.");
            return;
        }
        if (!party.alive()) return;
        overland.homeward = true;
        ++overland.day;
        --overland.daysOut;
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d — the road home, the %s.",
                 overland.day, overlandTerrainName(overland.terrain));
        log.add(buf);
        overlandStep();
        checkArrivedHome();
    }

    // [C] — camp for the night; an interrupted camp restores
    // nothing (the R34 convention)
    void overlandCamp() {
        if (mode != MODE_OVERLAND) return;
        if (overland.castle.pending) {
            log.add("Decide the castle first — [A]pproach or [P]ass.");
            return;
        }
        if (!party.alive()) return;
        log.add("You make camp for the night...");
        overlandStep();
        if (mode != MODE_OVERLAND) return;   // interrupted by steel
        if (overland.castle.pending) {
            // a discovery in the night abandons the camp
            log.add("The camp is abandoned.");
            return;
        }
        overlandSafeCamp("The night passes undisturbed.");
    }

    // The homeward march's last league: within sight of the
    // town walls (guarded by mode, so endCombat can call it)
    void checkArrivedHome() {
        if (mode != MODE_OVERLAND) return;
        if (overland.daysOut > 0) return;
        if (overland.castle.pending) return;
        if (!party.alive()) return;
        overland.daysOut = 0;
        arriveTown();   // R70: arrival billing too
        log.add("The walls of town rise aheadis over.");
    }

    // R70: any arrival in town - the delve return, the
    // overland march home, a sea landfall - one billing path
    void arriveTown() {
        mode = MODE_TOWN;
        billTownVisit();
        if (mode == MODE_OVERLAND) checkArrivedHome();
        if (mode == MODE_SEA) checkArrivedSea();   // R70
    }

    // ---- R70: sea travel ----------------------------------------------

    // [V] from town - set sail with the hired crew (R46)
    void enterSea() {
        if (mode != MODE_TOWN) return;
        if (!party.alive()) return;
        if (!party.crewHired) {
            log.add("You have no crew - hire them in town "
                    "first ([C] at the wharf).");
            return;
        }
        sea = SeaState{};
        mode = MODE_SEA;
        log.add("The company sets sail aboard the coaster.");
        log.add("Coastal waters - [T] to sail on, [H] for "
                "home.");
    }

    // coastal waters vs the open sea (documented fiction)
    dm::WaterDepth seaDepth() const {
        return (sea.daysOut < kSeaCoastalDays)
            ? dm::WaterDepth::SHALLOW : dm::WaterDepth::DEEP;
    }

    // one encounter check - a day's sail or a night at anchor
    // (the R68 cadence convention: the DMG's check timing is
    // the caller's)
    void seaStep() {
        if (mode != MODE_SEA || !party.alive()) return;
        dm::DungeonEncounter e = dm::rollWaterEncounter(
            registry, dice,
            (int)dice.roll(1, 100, 0), (int)dice.roll(1, 100, 0),
            dm::WaterBody::SALT, seaDepth(),
            dm::WaterClime::COOL);
        if (e.key.empty() || e.count <= 0) {
            log.add("The sea is calm.");
            return;
        }
        std::vector<ai::Actor> foes = buildFoesFromDm(e);
        if (foes.empty()) return;
        char buf[96];
        if (e.count == 1)
            snprintf(buf, sizeof buf,
                     "It rises from the waves - a wild %s "
                     "attacks the ship!", e.key.c_str());
        else
            snprintf(buf, sizeof buf,
                     "%d wild %ss attack the ship!",
                     e.count, e.key.c_str());
        log.add(buf);
        beginCombat(std::move(foes), -1, e.key);
    }

    // [T] - a day's sail outward
    void seaTravel() {
        if (mode != MODE_SEA) return;
        if (!party.alive()) return;
        sea.homeward = false;
        ++sea.day;
        ++sea.daysOut;
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d at sea - the %s.",
                 sea.day,
                 sea.daysOut < kSeaCoastalDays
                     ? "coastal waters" : "open sea");
        log.add(buf);
        seaStep();
        checkArrivedSea();
    }

    // [H] - a day's sail back toward port
    void seaHomeward() {
        if (mode != MODE_SEA) return;
        if (!party.alive()) return;
        sea.homeward = true;
        ++sea.day;
        --sea.daysOut;
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d - the sea road home.",
                 sea.day);
        log.add(buf);
        seaStep();
        checkArrivedSea();
    }

    // [C] - anchor for the night; an interrupted anchorage
    // restores nothing (the R34 convention)
    void seaCamp() {
        if (mode != MODE_SEA) return;
        if (!party.alive()) return;
        log.add("You anchor for the night...");
        seaStep();
        if (mode != MODE_SEA) return;   // interrupted by steel
        overlandSafeCamp("The night passes; the ship rides "
                         "easy.");
    }

    // the homeward sail's last league: landfall (guarded by
    // mode, so endCombat can complete the arrival too)
    void checkArrivedSea() {
        if (mode != MODE_SEA) return;
        if (sea.daysOut > 0) return;
        if (!party.alive()) return;
        log.add("The coaster makes port - landfall at last.");
        arriveTown();
    }

    // ---- R70: the city streets ----------------------------------------

    // [W] from town - walk the streets (DMG p.190-192)
    void enterCity() {
        if (mode != MODE_TOWN) return;
        if (!party.alive()) return;
        mode = MODE_CITY;
        log.add("You walk the streets of the city.");
        log.add("[1] by day  [2] by night  [B] back to town.");
    }

    void leaveCity() {
        if (mode != MODE_CITY) return;
        mode = MODE_TOWN;
        log.add("You return from the streets.");
    }

    // one excursion on the R64 matrix - daytime or nighttime
    // column. Classed and service parties (the p.191-192
    // explanations) meet by the p.176 Confrontation (the R68
    // meeting builder); registry monsters fight; civilians
    // are flavor (R64 fiction rows - printed counts, no
    // stats, documented in encounters.cpp)
    void cityExcursion(dm::CityTime t) {
        if (mode != MODE_CITY) return;
        if (!party.alive()) return;
        log.add(t == dm::CITY_DAY
            ? "You stroll out by daylight..."
            : "You slip into the night streets...");
        dm::DungeonEncounter e = dm::rollCityEncounter(
            registry, dice,
            (int)dice.roll(1, 100, 0), (int)dice.roll(1, 100, 0),
            t);
        if (e.isParty) {
            // noun: the matrix key, underscores as spaces
            std::string noun = e.key;
            for (auto& ch : noun)
                if (ch == '_') ch = ' ';
            overlandMeeting(e, noun.c_str(), false, false);
            return;
        }
        if (e.key.empty()) {
            log.add("Nothing comes of it.");
            return;
        }
        if (registry.find(e.key)) {
            std::vector<ai::Actor> foes = buildFoesFromDm(e);
            if (foes.empty()) return;
            char buf[96];
            if (e.count == 1)
                snprintf(buf, sizeof buf,
                         "A wild %s attacks in the alleys!",
                         e.key.c_str());
            else
                snprintf(buf, sizeof buf,
                         "%d wild %ss attack in the alleys!",
                         e.count, e.key.c_str());
            log.add(buf);
            beginCombat(std::move(foes), -1, e.key);
            return;
        }
        // fiction civilians - flavor only
        log.add(cityFlavor(e.key.c_str()));
    }
};
