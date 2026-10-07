// ============================================================================
// Adnd1 - game/appstate.h
// The simulation core: room occupancy, treasure, camera, game
// modes, creation state, combat state, and AppState itself.
// Moved verbatim from adnd1.cpp, R31 - no windows.h here; the
// shell (adnd1.cpp) owns the Renderer.
// R33: spellbook wiring - MU starting spell at creation, the
// castable list filters by known spells, and saveGame/loadGame
// grow an optional per-MU "spells" line (v1 saves still load).
// R34: per-day slots - Character::slotsByLevel persists across
// encounters (endCombat sync), [R] rest restores slots + natural
// healing with a wandering-encounter interrupt risk; descend and
// load also refill the pool.
// R35: ammo counting - Character::missileAmmo is the live quiver
// (20 missiles at creation / bow find / load; not persisted in
// v1 saves); each shot spends one (endCombat sync), and a dry
// quiver blocks the shoot command and falls back to melee.
// R36: throw command - combatThrow() has the active member hurl
// their melee weapon (dagger/hand axe/spear): one shot from the
// weapon's own dice/plus, then unarmed 1d2 fists for the rest of
// the encounter (the weapon is recovered afterward - Actor state
// only, nothing persisted).
// R37: monster missile attacks - beginCombat marks missile-armed
// monsters from the monster key (goblin/kobold, MM convention:
// goblins short bow, kobolds sling; key list is verification
// debt - the Lua data files carry no ranged flag); they fire an
// opening volley in round 1, then close to melee.
// R38: arrow restocking - quivers refill wherever slots do:
// a completed rest (restExplore) renews both, and descending
// (descend) restocks at the same time it refills slots. Load
// already refills. Ammo stays a physical resource otherwise -
// wandering-encounter-interrupted rests restore nothing.
// R39: ammo as treasure - victorious room loot can include a
// bundle of arrows (20): added to the quiver of the first living
// missile-armed member, or stockpiled on the least-supplied one
// when everyone is armed. Bows (R28) and arrows now both drop.
// R40: thrown-weapon loot - victorious room loot can include a
// +1 dagger: claimed by the first living member whose melee
// weapon is throwable (dagger/hand axe/spear) or weaker; it can
// be hurled with [t] (R36) at +1 to hit and damage.
// R41: town hub - a new MODE_TOWN screen reached with [B] from
// the dungeon. The temple sells healing potions (50 gp), the
// fletcher sells 20-arrow bundles (30 gp). [B]/Esc returns to
// the dungeon at the same depth. Buying arrows needs a missile-
// armed member (first below 20, else least-supplied - R39
// convention). Saves are not possible in town (mode resets to
// EXPLORE on load).
// R42 (three features): (1) town expansion - the inn sells a
// safe night's rest (10 gp: full slots, quivers, and 1 hp/level
// healing, NO wander check), the temple heals the most-wounded
// member to full (100 gp), the smith sells +1 long swords
// (500 gp, first living fighter); (2) movement + range bands -
// missile fire is bounded by the weapon's short range
// (rangeTens*10 feet, PHB p.39); the round-1 volley lasts
// rangeBandsOf() rounds before melee closes (1 band = 10' range
// factor);(3) dungeon scaling - monster lair sizes and treasure
// gold now scale with depth (cap 2+level/2, gold multiplier
// 100%+25%/level above 1).
// R43 (three features): (1) DMG training - level-ups queue
// (Party::pendingTraining) until the member trains at the town
// hall ([6], 1500 gp x new level); promotion logic moved from
// gainXp to Party::trainNext (hit die + R33 MU spell study);
// queue persists in saves via an optional "training" line
// (v1-compatible); (2) party-side range - the encounter carries
// an abstract distance (5 bands, closes 1/round); [x] shoot is
// refused once the range closes (thrown weapons exempt);
// (3) town stock - [7] chain mail (75 gp, first armored-eligible
// member in worse), [8] spell scroll (200 gp, one random unknown
// L1 MU spell added to the first MU's book).
// R44 (five features): (1) stronghold - a name-level member
// (level == class cap) builds a keep ([0], 10,000 gp); rents
// (200 gp) collect on every return to town and training is
// halved while it stands; (2) identify scrolls - treasure can
// yield scrolls and UNIDENTIFIED magic items (plus rolled but
// hidden); the scribe sells scrolls ([9], 100 gp) and [I] reads
// one over the first pending item, applying weapon or armor
// enchant; (3) henchman - [H] posts a 100 gp offer (DMG p.36
// simplified); on acceptance a level-1 fighter joins as an
// extra party actor (chain + shield kit), upkeep 100 gp/level
// bills each return to town, loyalty (50 + best Cha reaction
// adj) is checked on descending - a failed roll loses the hire;
// (4) monster roster expansion - six new Lua bestiary files
// (bandit, wolf, hobgoblin, gnoll, lizard man, bugbear) and
// hobgoblin joins the missile-armed key list; (5) town hub
// polish - a company status panel (roster, henchman, keep,
// scrolls) beside the shop menu.
// R45 (five features): (1) henchman advancement and shares -
// the hire earns a half share of combat XP, levels (hit die
// d10+1) at fighter thresholds, and takes a THIRD of each
// delve's gold (accumulated in delveGold, paid into his
// purse on every return to town); (2) sage and spy consults -
// [S] 200 gp lists what lairs at this depth (the registry
// roster, an in-game MM reference), [Y] 500 gp reveals the
// CURRENT occupied rooms and their monster keys (simple
// recon, DMG p.35 spying simplified); (3) the peddler [M] -
// 500 gp for one random identified magic item (weapon +1,
// armor +1, three potions, two identify scrolls, or a spell
// scroll); (4) traps and secret doors - unoccupied rooms may
// hide a dart trap (save vs death or 2d6; a thief in the
// company may spot and disarm it first), walls hide secret
// doors found with [F] search (1-in-6, thief 3-in-6; found
// doors become ordinary doors); (5) MM reference - the sage
// consult doubles as the bestiary lore service (true book
// verification still awaits the re-uploaded MM PDF).
// R46 (six features): (1) NPC dialogue - [T] in town talks
// with the locals (state-aware tavern chatter: hints about
// pending training, unidentified loot, the hire, the keep,
// and depth rumors); (2) psionics hook - Actor::psionic
// (app-flagged by monster key, R37 pattern): a once-per-
// encounter mind blast stuns a party member unless they
// save vs spells; the mind flayer (new Lua file) carries
// it; (3) henchman kit - [J] upgrades the hire to plate
// (100 gp from HIS purse, not the company's gold); (4)
// ship crew - [C] hires a 20-sailor coaster's company
// (200 gp down); upkeep 300 gp each return (20 sailors plus
// a captain, a lieutenant and two mates, DMG p.35), and the
// company takes 37% of every delve's take at the exit
// (captain 25, lieutenant 5, mates 2, crew 5); (5) room
// flavor - entering a room the first time describes it
// (state-aware: occupied/trapped/looted/swept variants);
// (6) L4+ spell slots - all slot arrays widened to 6
// levels (the spells:: tables carry the columns; the L4-6
// spell DATA pass is next - it needs the current spells/
// files read back).
// R52: the real DMG Appendix C dungeon tables - dm/encounters.
// {h,cpp} carry the Determination Matrix, Monster Level Tables
// I-X, per-level Dragon Subtables (the Age Category column is
// hit points per die), and the Human Subtable, OCR-verified
// against the uploaded DMG (Premium reprint p.174-179). Room
// lairs and wandering encounters roll from the tables; hydra
// groups and dragon pairs keep the DMG head/age ranges per
// specimen; the sage reads the table roster (dm::encounterKeys).
// Character Subtable parties (classed NPCs) are R53.
// R53: the Character Subtable (DMG p.176) - party members are
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
// combat - hostile bands attack, uncertain ones dice it,
// friendly ones pass by or share word of the dungeon (never
// joining, per p.176). A party that feels weak gets +10 to avoid
// or bluff (p.176). Also fixes a leftover placeholder glitch in
// the R57 header note.
// R57: PERSONAE-grade NPC abilities (DMG p.87 + p.176): 3d6
// per score, race (p.176 table) and class (p.87 table) ability
// adjustments, exceptional strength for fighters at STR 18, and
// hp by the canonical per-level rollHitPoints with the rolled
// Con adjustment (men-at-arms: the p.87 Mercenary row -
// STR +1, CON +3, 4 minimum hp). The R53 average-10 convention
// is retired.
// R55: NPC parties roll magic items (DMG p.176-177 Tables I-IV
// level-chance ladder): weapon/armor/shield pluses land on the
// equipped Actor gear; unmodeled devices are fiction-only.
// R56: the gear is LOOTABLE - victory over a wandering NPC
// party strips the best enchanted weapon/armor/shield from the
// slain (claim conventions: same-weapon first, then equal-or-
// better damage; armor by class weight rules; shields by
// shieldAllowed) and a coin purse with treasure xp. The magic
// shield persists: Character::shieldPlus (optional save line,
// v1 compatible).
// R54: NPC spellcasters CAST - one foe caster per round,
// side-aware targeting, cleric heal-first AI, MU sleep opener
// then fireball at 3rd-level slots (ai/actor.cpp foeSpellChoice).
// ============================================================================================================================================

// R68: overland travel - the DMG Appendix C outdoor play loop
// (p.182-183, wired to the R63/R67 builders). From town, [O] sets
// out; each day is a march ([T] outward, [H] homeward) across a
// player-chosen terrain, with a night camp ([C]) that heals if
// undisturbed. The DMG leaves the check cadence to the DM
// ("whenever an encounter is indicated") - this campaign checks
// once per march day and once per night camp (documented
// fiction). The first three days from town are the INHABITED
// band (OC_TEMPERATE_INHABITED tables, patrols 5 in 20,
// DMG p.182); beyond it the WILDS (OC_TEMPERATE_WILD - the
// campaign's fixed clime is temperate, the other climate sets
// are the R63 module's for other campaigns, documented). In the
// wilds 1 in 20 encounters discover a STRONGHOLD (p.182):
// Castle Table I -> awareness (the p.183 surprise die; an
// unaware party chooses [A]pproach or [P]ass, an aware one is
// met) -> Table II -> totally deserted (a safe night's shelter,
// fiction), deserted (the p.183 "roll the OUTDOOR ENCOUNTER
// TABLE, ignoring men" monster - the Men Subtable keys are the
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
// sail [T]/[H] rolls the R60 salt-water tables - coastal
// waters (SHALLOW, the first kSeaCoastalDays) then the open
// sea (DEEP), clime COOL (temperate waters, campaign fiction)
// - with [C] anchoring for the night (the R34/R38 rest). A
// landfall bills the town visit like any return. [W] from
// town walks the streets: MODE_CITY, [1] a daytime excursion
// and [2] a nighttime one, each a single roll on the R64
// city matrix - classed/service parties meet by the p.176
// Confrontation (the R68 meeting builder), registry monsters
// fight, civilians are flavor (R64 fiction rows, printed
// counts, no stats - documented). The R41+ "every return to
// town" billing (rents, upkeep, shares, wages) is extracted
// to billTownVisit() and now bills EVERY arrival - the R68
// overland return previously bypassed it (documented fix).
#pragma once

#include "../world/map.h"
#include "../rules/dice.h"
#include "../rules/character.h"
#include "../rules/classes.h"
#include "../rules/subclasses.h"  // R230: the subclass registry
#include "../rules/subclassgates.h"  // R230: the creation gates
#include "../rules/races.h"   // R154: Race Tables I-III
#include "../rules/saves.h"   // R45: trap saves
#include "../rules/combat.h"   // R61: monsterEffectiveLevel (p.86 guard rule)
#include "../dm/dm.h"
#include "../dm/dungeon.h"
#include "../dm/encounters.h"   // R52: Appendix C tables
#include "../dm/treasure.h"    // R71: MM treasure types
#include "../dm/appendixgh.h"  // R125: pp.216-217 trap/trick lists
#include "../dm/sampledungeon.h"  // R142: pp.94-96 the DMG sample dungeon
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
    // R125: the Appendix G name rolled at arming (-1 none);
    // transient - rooms re-populate on load
    int trapKind = -1;
    bool flavorSeen = false;   // R46: first-entry description
    // R120: a non-hostile parley bought peace - the room's
    // monsters no longer leap at the company (a deliberate-
    // engage hook is a future round)
    bool parleyed = false;
    // R52: DMG Appendix C ranges - hydra heads per specimen,
    // dragon age bracket (hp/die) per specimen
    int headsLo = 0, headsHi = 0;
    int ageLo = 0, ageHi = 0;
    // R128: Appendix H special rooms - the rolled trick
    // (feature + attribute) for an unoccupied, untrapped
    // room; transient, re-populated on load like trapKind.
    // trickDone gates the one-shot mechanical effect.
    int trickFeature = -1;
    int trickAttribute = -1;
    bool trickDone = false;
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
// level - the book's own worked example is exactly this
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
    MODE_SEA,          // R70: sea voyage (R127 p.190 waterborne)
    MODE_CITY,         // R70: city streets (R64 matrix)
};

// ----------------------------------------------------------------------------
// R24: Creation state - ROLL -> CLASS -> NAME, per member.
// Uses its own RNG stream so dungeon/sim determinism is untouched.
// ----------------------------------------------------------------------------

enum CreationStage : int {
    CR_ROLL = 0,
    CR_RACE,    // R154: the racial stock stage
    CR_CLASS,
    CR_SUBCLASS,   // R230: the subclass offer stage
    CR_MULTI,   // R233: the multi-class offer stage
    CR_NAME,
};

struct CreationState {
    CreationStage stage = CR_ROLL;

    // R233: the multi-class combo pick (0 = the
    // single-class path; else the R185 combo mask)
    int multiMask = 0;

    rules::Rng  creationRng{1};
    rules::Dice creationDice{creationRng};

    rules::AbilityScores rolled;
    int  racePick = 0;               // R154: highlighted race row
    bool female = false;             // R154: Table III M/F columns
    int  classPick = 0;              // highlighted class row
    int  subPick = -1;               // R230: registry subclass, -1 = plain
    std::string nameBuf;

    int partySizeCap = PARTY_DEFAULT;
    bool done = false;               // finished -> begin delve

    void rollFresh() {
        rolled = rules::rollAbilities(creationDice,
                                      rules::GEN_4D6_DROP);
        stage = CR_ROLL;
        racePick = 0;     // R154
        female = false;   // R154
        classPick = 0;
        subPick = -1;   // R230
        nameBuf.clear();
    }

    // R154: the scores as this race would carry them - the
    // racial adjustment applied, then the Table III maximum
    // clamp (the print: adjusted scores are the actual
    // scores for all game purposes)
    rules::AbilityScores raceAdjusted() const {
        rules::AbilityScores s = rolled;
        rules::applyRacialAdjustments(s,
            (rules::CharRace)racePick, female);
        return s;
    }

    // R154: Table III eligibility - minimums met considering
    // the racial bonuses
    bool raceEligible(int raceIdx) const {
        return rules::raceMeetsMinimums(rolled,
            (rules::CharRace)raceIdx, female);
    }

    // eligibility: prime requisite meets the class minimum,
    // and Race Table I allows the class for the race (R154)
    bool classEligible(int classIndex) const {
        int ab = raceAdjusted().get(
            (rules::Ability)rules::primeRequisite(classIndex));
        if (ab < rules::classMinAbility(classIndex))
            return false;
        return rules::classAllowedForRace(classIndex,
            (rules::CharRace)racePick);
    }

    // finalize the pending member with the chosen class
    Character makeMember(int classIndex) {
        Character c;
        c.race = racePick;              // R154: the chosen stock
        c.abilities = raceAdjusted();   // R154: adjusted is actual
        c.classIndex = classIndex;
        c.level = 1;
        // R97: the gray beard - when the career begins
        c.startAge = rollStartingAge(classIndex, creationDice);

        // exceptional strength: fighter group at STR 18
        // (R154: the ADJUSTED score - a racial STR bonus can
        // carry a male elf or half-orc fighter to 18)
        if (classIndex == rules::CLASS_FIGHTER &&
            c.abilities.str == 18) {
            c.exStr.has = true;
            c.exStr.pct = rules::rollExceptionalStrength(creationDice);
        }

        // level-1 hit points (canonical signature, R4b)
        // R154: the ADJUSTED con (the racial bonus counts)
        int conAdj = rules::conHPAdjustment(
            classIndex, c.abilities.con);
        c.hp = c.maxHp = rules::rollHitPoints(classIndex, 1,
                                              conAdj, creationDice);

        // R34: casters start with their full level-1 slot pool
        if (classIndex == 1 || classIndex == 2) {
            spells::SpellClass sc = classIndex == 1
                ? spells::SPELL_MU : spells::SPELL_CLERIC;
            for (int lv = 1; lv <= 9; ++lv)   // R131: 9 levels
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

    // R230: the subclass offer rows for the chosen base:
    // row 0 the plain base class, then every registry
    // subclass whose runtime base matches (the monk
    // rides the fighter list - the JUDGMENT)
    int subclassOfferCount() const {
        int n = 1;
        for (int i = 0; i < rules::SUB_COUNT; ++i)
            if (rules::subclassRuntimeBase(i) == classPick)
                ++n;
        return n;
    }

    // the registry index for offer row r;
    // -1 = the plain base class (row 0)
    int subclassOfferAt(int row) const {
        if (row <= 0) return -1;
        int n = 1;
        for (int i = 0; i < rules::SUB_COUNT; ++i) {
            if (rules::subclassRuntimeBase(i) == classPick) {
                if (n == row) return i;
                ++n;
            }
        }
        return -1;
    }

    // R230: subclass eligibility - the base class must
    // qualify, then the R180 gates on the ADJUSTED
    // scores (the ability minimums) and Race Table I
    // (player eligibility)
    bool subclassEligible(int sub) const {
        if (!classEligible(rules::subclassRuntimeBase(sub)))
            return false;
        if (!rules::subclassMeetsAbilityMin(sub,
                raceAdjusted())) return false;
        if (rules::subclassPlayerAllowed(sub,
                (rules::CharRace)racePick) != 1)
            return false;
        return true;
    }

    // R230: finalize as a registry subclass (makeMember
    // builds the base member; this overlays the subclass
    // parameters)
    Character makeSubclassMember(int sub) {
        int base = rules::subclassRuntimeBase(sub);
        Character c = makeMember(base);
        c.subclass = sub;

        // the start age reads the subclass band, with
        // the base-class roll (2d8 the magic-user band,
        // 1d4 otherwise - the p.20 convention)
        if (base == rules::CLASS_MAGIC_USER)
            c.startAge = rules::subclassStartAgeBase(sub)
                + creationDice.roll(2, 8, 0);
        else
            c.startAge = rules::subclassStartAgeBase(sub)
                + creationDice.roll(1, 4, 0);

        // hit points: the subclass die; the ranger and
        // monk roll TWO dice at level 1 (each die with
        // its con adjustment - the engine per-die
        // convention, the JUDGMENT; the floor is 1)
        int conAdj = rules::conHPAdjustment(
            rules::subclassConClass(sub), c.abilities.con);
        int die = rules::subclassHitDie(sub);
        int hp = (int)creationDice.roll(
                     1, (uint32_t)die, 0) + conAdj;
        if (rules::subclassTwoDiceFirstLevel(sub))
            hp += (int)creationDice.roll(
                      1, (uint32_t)die, 0) + conAdj;
        if (hp < 1) hp = 1;
        c.hp = c.maxHp = hp;

        // slots: the druid and illusionist read their
        // R228/R229 tables (the base fill is replaced)
        if (sub == rules::SUB_DRUID) {
            for (int lv = 1; lv <= 9; ++lv)   // R131
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(
                        spells::SPELL_DRUID, 1, lv);
        } else if (sub == rules::SUB_ILLUSIONIST) {
            c.knownSpells.clear();   // the MU book out
            for (int lv = 1; lv <= 9; ++lv)   // R131
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(
                        spells::SPELL_ILLUSIONIST, 1, lv);
            // the R33 convention: one random L1 spell
            std::vector<int> l1;
            for (int id = 0; id < spells::SPELL_COUNT;
                 ++id) {
                const spells::SpellDef& s =
                    spells::spell((spells::SpellId)id);
                if (s.sclass == spells::SPELL_ILLUSIONIST
                    && s.level == 1) l1.push_back(id);
            }
            if (!l1.empty()) {
                int pick = (int)creationDice.roll(
                    1, (uint32_t)l1.size(), 0) - 1;
                c.knownSpells.push_back(l1[pick]);
            }
        }

        // the monk kit: quarterstaff, no armor, no
        // shield (the JUDGMENT; the R24 sets stand for
        // the rest)
        if (sub == rules::SUB_MONK) {
            c.weapon.id = items::WPN_QUARTERSTAFF;
            c.armor.id = items::ARMOR_NONE_EQUIPPED;
            c.shield = false;
        }
        return c;
    }

    // R233: the multi-class offer - the race printed
    // combos (the R185 table)
    int multiOfferCount() const {
        return rules::multiClassComboCount(racePick);
    }

    int multiOfferAt(int row) const {
        return rules::multiClassCombo(racePick, row);
    }

    // combo eligibility: every class of the combo
    // passes its own gate (the class minimum on the
    // ADJUSTED prime + Race Table I via classEligible;
    // the subclass bits their R180 minimums and
    // player-eligibility), plus the half-elf
    // multi-class cleric WIS 13 (vs the single 9)
    bool multiEligible(int mask) const {
        if (!rules::multiClassAllowed(racePick, mask))
            return false;
        int n = rules::multiClassCount(mask);
        for (int i = 0; i < n; ++i) {
            int b = rules::multiClassBitAt(mask, i);
            int base = rules::multiClassBaseOfBit(b);
            int sub = rules::multiClassSubOfBit(b);
            if (!classEligible(base)) return false;
            if (sub >= 0 &&
                !rules::subclassMeetsAbilityMin(sub,
                        raceAdjusted()))
                return false;
            if (sub >= 0 &&
                !rules::subclassPlayerAllowed(
                    sub, (rules::CharRace)racePick))
                return false;
        }
        if ((mask & rules::MC_CLERIC) != 0 &&
            racePick == 4 &&
            raceAdjusted().wis <
                rules::halfelfClericWisMin())
            return false;
        return true;
    }

    // R233: finalize as a multi-class combo. The member
    // rides the PRIMARY class - the first set bit (the
    // fighter bit when the combo carries it - the best
    // melee class on the swing - the JUDGMENT); the
    // hit dice roll
    // every class die, each with its con adjustment,
    // and read the quotient (the R185 rule); the kit
    // rides the MOST RESTRICTIVE armor allowance and
    // the all-allow shield gate (the JUDGMENT)
    Character makeMultiMember(int mask) {
        int b0 = rules::multiClassBitAt(mask, 0);
        int base0 = rules::multiClassBaseOfBit(b0);
        int sub0 = rules::multiClassSubOfBit(b0);
        Character c = sub0 >= 0
            ? makeSubclassMember(sub0)
            : makeMember(base0);
        c.multiMask = mask;
        c.subclass = sub0;   // every printed combo
                             // rides a base-class
                             // primary (the subclass
                             // bits sit high); the
                             // branch keeps a future
                             // combo honest

        // hit points: every class die, each with its
        // con adjustment, quotient by the class count
        // (the R185 pin); the per-die floor is 1
        int n = rules::multiClassCount(mask);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int b = rules::multiClassBitAt(mask, i);
            int base = rules::multiClassBaseOfBit(b);
            int sub = rules::multiClassSubOfBit(b);
            int conCls = sub >= 0
                ? rules::subclassConClass(sub) : base;
            int conAdj = rules::conHPAdjustment(
                conCls, c.abilities.con);
            int die = sub >= 0
                ? rules::subclassHitDie(sub)
                : rules::CLASS_HIT_DIE[base];
            int d = (int)creationDice.roll(
                1, (uint32_t)die, 0) + conAdj;
            if (d < 1) d = 1;
            sum += d;
        }
        int hp = rules::multiclassHpQuotient(sum, n);
        if (hp < 1) hp = 1;
        c.hp = c.maxHp = hp;

        // the kit: the most restrictive armor among
        // the combo (none < leather < chain < plate),
        // the shield only when every class allows it
        int w = 3;   // start permissive
        bool sh = true;
        for (int i = 0; i < n; ++i) {
            int base = rules::multiClassBaseOfBit(
                rules::multiClassBitAt(mask, i));
            int bw = 3;
            if (!rules::armorAllowed(base,
                                     rules::ARMOR_PLATE)) {
                if (rules::armorAllowed(base,
                                        rules::ARMOR_CHAIN))
                    bw = 2;
                else if (rules::armorAllowed(
                             base, rules::ARMOR_LEATHER))
                    bw = 1;
                else
                    bw = 0;
            }
            if (bw < w) w = bw;
            if (!rules::shieldAllowed(base)) sh = false;
        }
        c.armor.id = w == 3 ? items::ARMOR_PLATE
                    : w == 2 ? items::ARMOR_CHAIN_MAIL
                    : w == 1 ? items::ARMOR_LEATHER
                             : items::ARMOR_NONE_EQUIPPED;
        c.shield = sh;
        return c;
    }
};

// ----------------------------------------------------------------------------
// Combat state - interactive, commands wired to the driver (R21).
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
        // unique - creation enforces it)
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

    // R27: spells the ACTIVE member can cast right now - right
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
            // R83: the L4-6 ladder is castable - the old 1-3
            // gate left R80/R82's higher spells forever pending
            if (s.level < 1 || s.level > 6) continue;
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
    int           daysOut = 0;    // 0 = in town; 1+ = days afield
    int           milesOut = 0;   // R123: true miles from town
    bool          homeward = false;
    int           terrain = dm::T_PLAIN;   // the route's column
    OverlandCastle castle;
};

// The inhabited band: the first kOverlandInhabitedDays of the
// journey are patrolled civilized lands (documented fiction -
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
// kSeaCoastalDays days out, the open sea (DEEP) beyond -
// DMG p.179 prints salt-water shallow "to 100'", and the
// coastal/open-sea split is this campaign's fiction.
static const int kSeaCoastalDays = 2;

struct SeaState {
    int day = 0;        // days on the water
    int daysOut = 0;    // 0 = in port; 1+ = at sea
    int milesOut = 0;   // R123: true miles from port
    bool homeward = false;
};

// R64 fiction civilians: printed counts, no bestiary stats
// (encounters.cpp documents) - city encounters with these
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
    int           moveDebt   = 0;   // R89: pace tenths owed
    int           turnsSinceRest = 0; // R119: active turns since rest
    bool          restOwed  = false;  // R119: combat owes a turn (p.38)
    bool          mustRest  = false;  // R119: the gate - camp [R] to clear
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

    // R23: stairs down - placed in the room farthest from entry
    int stairsX = -1, stairsY = -1;

    // R45: the level's hidden doors
    std::vector<SecretDoor> secretDoors;

    void newDungeon(uint64_t s);

    // R24: creation is finished - the delve begins
    void beginDelve();

    // R24: full reset after a wipe - back to creation, career gone
    void resetToCreation();

    // ----------------------------------------------------------------
    // R29: save/load. Plain-text career file "adnd1.sav" in the
    // working directory. The COMPANY is saved, not the floor: no
    // dungeon layout, occupancy, or combat state persists - loading
    // regenerates a fresh dungeon at the saved depth (the
    // deterministic newDungeon pipeline). Format: one token stream,
    // version-tagged; unknown/short files are rejected cleanly.
    // ----------------------------------------------------------------
    static const char* SAVE_FILE() { return "adnd1.sav"; }

    bool saveGame();

    bool loadGame();

    // R23: stairs in the room whose center is farthest from the
    // entry point. The tile itself stays floor - the marker and
    // the step check carry the meaning (no map.h changes needed).
    void placeStairs();

    // R23: descend. Career (hp/xp/gold/equipment/level) persists -
    // depth scales monsters and treasure.
    void descend();

    // R34: refill every caster's slots to their class-table pool
    void restoreSlots();

    // R34: rest - restore slots and natural healing (1 hp per
    // level, PHB daily recovery), but the camp may be attacked:
    // a wandering-encounter check first; an interrupted rest
    // restores NOTHING (the party fights on, tired and dry)
    // R38: refill every quiver to 20 (members holding a missile
    // weapon in the ranged slot). Mirrors restoreSlots.
    void restockAmmo();

    // R79: dump the company's kit to the log - per member weapon/
    // ranged/armor/shield (with enchant plus), then the carried
    // totals (potions, scrolls, gold). Engine-side; the Win32 key
    // binding is a later shell diff.
    void dumpEquipment();

    // R81: study the carried scrolls (town) - each scroll is an MU
    // spell scroll; one chance-to-learn roll per scroll, consumed
    // on success or failure (PHB p.10 study convention).
    // R83: bound to the [L] town key.
    void townStudyScrolls();

    // R82: a 7th+ level cleric raises one dead member (1000 gp
    // offering, survival vs CON per PHB, raised at 1 hp).
    // R83: bound to the [R] town key.
    void townRaiseDead();

    // R232: lay on hands - the paladin heals 2 hp per level,
    // once per day (the [F] town key)
    void townLayOnHands();

    // R85: the pack commands - [E] equips the best of every
    // member's pack (old kit returns to the pack as a keepsake),
    // [P] peddles the pack (sale-value items only; keepsakes
    // stay). [D] dumps the kit (the R79 engine method, now
    // key-bound - a standing backlog item).
    void townSwapGear();
    void townSellPack();

    // ---- R41: town hub ------------------------------------------------------

    // [B] from the dungeon - retire to town for supplies
    void enterTown();

    // R70: the R41+ arrival billing - rents, henchman
    // upkeep, shares and crew wages, billed on EVERY
    // return to town (the delve-return, the overland
    // march home, a sea landfall). Extracted verbatim
    // from enterTown in R70.
    void billTownVisit();
    // [B]/Esc in town - dive back in at the same depth
    void leaveTown();

    // the temple sells healing potions (50 gp)
    void townBuyPotion();

    // the fletcher sells 20-arrow bundles (30 gp) - taker follows
    // the R39 loot convention (first armed member below 20, else
    // the least-supplied one)
    void townBuyArrows();

    // R42: the inn - a safe night's rest (10 gp). Full slots
    // (restoreSlots), full quivers (restockAmmo), 1 hp/level
    // natural healing each - and NO wander check: that is what
    // the silver buys (explore [R] rest is free but risky)
    void townInnRest();

    // R42: the temple - heal the most-wounded living member to
    // full (100 gp). Cheaper per-hp than potions at scale, but
    // only in town and one member at a time
    void townTempleHeal();

    // R42: the smith - a +1 long sword (500 gp), claimed by the
    // first living fighter whose blade is not already magic
    void townBuySword();

    // R43: the training hall - promote the first queued member
    // (1500 gp x their next level, DMG p.86 convention
    // simplified). One promotion per visit/key press.
    void townTrain();

    // R234: the guild class-change and the resort stance
    void townChangeClass();
    void townOldClassResort();

    // R43: the armorer - chain mail (75 gp, PHB list price) for
    // the first living armor-eligible member (fighter or cleric)
    // whose current armor is worse than chain
    void townBuyChain();

    // R43: the scribe - a spell scroll (200 gp): one random
    // unknown L1 MU spell is copied into the first MU's book
    // (chance-to-learn deferred to level-ups - buying knowledge
    // is the simplification)
    void townBuyScroll();

    // R44: the keep - a name-level member raises a stronghold.
    // 10,000 gp is a rebuild-scale simplification of the DMG
    // p.83 barony costs (the book's castle economics are far
    // larger than delve treasure supports); name level here is
    // the class level cap (fighter 9, MU 11, cleric 9, thief 10)
    void townBuildStronghold();

    // R44: the scribe also stocks identify scrolls (100 gp)
    void townBuyIdentify();

    // R44: [I] - read an identify scroll over the first
    // pending item. The enchant was rolled at loot time but
    // hidden from the company; identification applies it.
    void useIdentifyScroll();

    // R44: [H] - post a henchman offer (DMG p.36 simplified:
    // 100 gp spent regardless, acceptance d100 vs interest =
    // 25% + the best living member's Cha reaction adj)
    void townHireHenchman();

    // R45: [S] the sage - 200 gp for lore on what lairs at
    // this depth. R52: the roster is the DMG Appendix C
    // Determination Matrix for this dungeon level (the real
    // tables, OCR-verified) - dm::encounterKeys.
    void townSage();

    // R45: [Y] the spy - 500 gp for simple recon (DMG p.35
    // spying simplified): the CURRENT level's occupied rooms
    // and their monster keys
    void townSpy();

    // R45: [M] the peddler - 500 gp for one random
    // IDENTIFIED magic item (no scroll needed - the peddler
    // knows his wares)
    void townPeddler();

    // R46: first-entry room flavor - one atmospheric line,
    // state-aware (occupied, trapped, looted, swept)
    void describeRoom(int roomIndex);

    // R46: [T] talk with the town locals - state-aware
    // tavern chatter (the NPC dialogue system lite)
    void townTalk();

    // R46: [J] upgrade the hire's kit to plate - paid from
    // HIS purse, not the company gold (tranche-124 convention)
    void townGiftHire();      // R103: [G] the 25 gp gift
    void townUpgradeHire();

    // R46: [C] hire a ship's crew - a 20-sailor coaster's
    // company; R121: with officers (DMG p.35) - 200 gp down,
    // 300 gp wages each return, 37% of every take at the
    // exit (captain 25, lieutenant 5, mates 2, crew 5)
    void townHireCrew();

    void restExplore();

    // R119: forced rest (DMG p.38) - one turn in six,
    // plus a turn after combat; when due, explore
    // movement gates until the company camps ([R];
    // the inn clears it too)
    void tickActivity(int turns);

    int countOccupied() const;

    void populateRooms();

    int roomCountCap() const;

    int roomAt(int x, int y) const;

    int occupiedRoomNear(int px, int py, int radius = 2) const;

    // R45: the nearest room with an ARMED trap (the party
    // springs it by walking in)
    int trapRoomNear(int px, int py, int radius = 0) const;

    // R45: spring the dart trap in a room. A thief in the
    // company may spot and disarm it first (1-in-3, the
    // find/remove-trades instinct - simplified); otherwise a
    // random living member saves vs death or eats 2d6.
    void springTrap(int roomIndex);

    // R128: apply a special room's mechanical trick effect
    // (the first-effects slice: releases coins/gems/magic
    // item, shoots, poison - the trap-strike shape).
    void applyTrick(int roomIndex);

    // R137: the deliberate-engage hook - the company
    // chooses to engage the current room's trick (the
    // X key in the dungeon); the first sight no longer
    // springs the feature.
    void engageTrick();

    // R45: place secret doors - wall tiles that border floor
    // (3 per level). Found doors become ordinary doors on
    // the map; hidden ones render as plain wall.
    // R120: [H] listen at doors (DMG p.60) - ear to the
    // nearest portal; the best listener leads (a thief's
    // hear-noise, else the human band); silent creatures
    // (undead) are never heard; the hint is imprecise per
    // the book. Costs a turn.
    void listenExplore();

    void placeSecretDoors();

    // R45: [F] search - one turn spent feeling the walls.
    // Each adjacent unfound secret door rolls 1-in-6 (a
    // thief in the company raises it to 3-in-6 - his keen
    // eyes lead the search). Found doors become TILE_DOOR.
    void searchExplore();

    Treasure rollTreasure(int roomIndex);

    void awardVictory();

    // R24: build the encounter party from the living roster
    std::vector<ai::Actor> partyActors() const;

    // R25: shared combat entry - starts the encounter and arms the
    // quaff hook (the hook owns the potion pool and the heal, so
    // the driver stays inventory-free)
    void beginCombat(std::vector<ai::Actor> foes, int roomIndex,
                     const std::string& monsterKey);

    // R25: explore-mode quaff - heals the most-wounded living
    // member; refuses (without consuming) if everyone is full
    void quaffExplore();

    // R25: combat quaff - the ACTIVE member drinks this round
    // (round consumed via ACTION_DRINK; effect resolves at the
    // end of the round through the quaff hook)
    void combatQuaff();

    // R28: the ACTIVE member fires missiles this round - requires
    // a missile weapon in the ranged slot (falls back to melee
    // otherwise, with a log line so the player knows why)
    void combatShoot();

    // R36: the ACTIVE member hurls their melee weapon this round
    // (dagger/hand axe/spear) - one shot from the weapon's own
    // dice/plus, then bare fists until the fight ends (the weapon
    // is recovered afterward)
    void combatThrow();


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
            const monsters::MonsterDef* def);

    // R51: fixed hp-per-die for the dispatch types that carry it
    // (dragon age bracket 1-8; hydra heads are a full 8 hp each,
    // MM1). Others roll dice in toActor.
    static int hpPerDieFor(const monsters::MonsterDef* def,
                           const monsters::xp::SpawnContext& c);

    // R52: one roll on the DMG Appendix C chain for this depth
    // (d20 -> Determination Matrix -> level table -> subtable)
    dm::DungeonEncounter rollDmEncounter();

    // R52: build the foe roster from a DMG encounter. Each
    // specimen rolls its own context (R51), pinned to the DMG
    // ranges where the table carries them: hydra heads, dragon
    // age bracket (hp/die, the subtable's Age Category column).
    std::vector<ai::Actor> buildFoesFromDm(
            const dm::DungeonEncounter& e);

    // R52: a stored room lair back as a DMG encounter (the
    // ranges survive population)
    dm::DungeonEncounter encFromRoom(const RoomOccupant& r);

    // R53: kit for a classed NPC (DMG p.176 - 1st level
    // scale/chain with standard weapons, 2nd+ plate; men-at-arms
    // studded leather and spear; MUs unarmored with quarterstaff,
    // thieves leather and short sword)
    void kitNpc(ai::Actor& a, const dm::PartyMember& m);

    // R53: name for a party foe (short flavor, level-tagged)
    std::string npcName(const dm::PartyMember& m, int index);

    // R53: build the foe roster from a Character Subtable party.
    // Each member is a real classed combatant (the Actor character
    // path); hp rolls the class hit die per level (fixed hp beyond
    // the name cap, R49 convention), men-at-arms take the 0-level
    // man's 1-6. Foe contexts carry class/level for by_level XP.
    std::vector<ai::Actor> buildFoesFromParty(
            const dm::CharacterParty& party);

    void spawnRoomEncounter(int roomIndex);

    void spawnWanderingEncounter();

    void playerFlee();

    void endCombat();

    // ---- R68: overland travel ---------------------------------------------

    // [O] from town - set out along the wild roads
    void enterOverland();

    // [1-8] - steer the route's terrain column (campaign-map
    // fiction; the castle and encounter rolls both use it)
    void overlandSetTerrain(int t);

    // The p.182 bands: the first days out are the patrolled
    // lands; beyond them, the wilderness
    bool overlandInhabited() const;

    dm::OutdoorClime overlandClime() const;

    // One encounter check - a march day or a night at camp (the
    // cadence is this campaign's documented fiction; the DMG
    // checks "whenever an encounter is indicated").
    void overlandStep();

    // The wilderness itself: one roll on the R63 outdoor tables
    // for the route's clime and terrain column
    void overlandWildEncounter();

    // A patrol of the inhabited lands (R67 rollPatrol; the
    // "ranger, where applicable" leader is area fiction - this
    // campaign's patrols are fighter-led, documented)
    void overlandPatrol();

    // R58 party-reaction meeting (DMG p.63 Encounter Reactions +
    // the p.176 Confrontation paragraph), overland flavor: the
    // best-living-Cha spokesman, the weaker-side adjustment,
    // hostile steel or a peaceful pass. favors: the R62 friendly
    // parting gifts (a potion or a coin pouch); shelter: friendly
    // garrisons take the company in for the night.
    void overlandMeeting(dm::DungeonEncounter& e, const char* noun,
                         bool favors, bool shelter);

    // A completed night's rest on the trail (the R34/R38
    // convention: slots, quivers, 1 hp per level)
    void overlandSafeCamp(const char* why);

    // p.182: the party is within visual range of the
    // stronghold - 1/2 to 5 miles; the R67 builders do the rest
    void overlandDiscoverCastle();

    // [A] - resolve the castle: Table II (the discovery roll's
    // percentile) and the R67 builders
    void overlandApproach();

    // [P] - give the stronghold a wide berth
    void overlandPass();

    // R123: the day's true miles (DMG pp.58-59 afoot table -
    // the slowest walker's pace, the route's terrain class)
    int overlandMilesPerDay() const;

    // [T] - a day's march outward
    void overlandTravel();

    // [H] - a day's march back toward town
    void overlandHomeward();

    // [C] - camp for the night; an interrupted camp restores
    // nothing (the R34 convention)
    void overlandCamp();

    // The homeward march's last league: within sight of the
    // town walls (guarded by mode, so endCombat can call it)
    void checkArrivedHome();

    // R70: any arrival in town - the delve return, the
    // overland march home, a sea landfall - one billing path
    void arriveTown();

    // ---- R70: sea travel ----------------------------------------------

    // [V] from town - set sail with the hired crew (R46)
    void enterSea();

    // coastal waters vs the open sea (documented fiction)
    dm::WaterDepth seaDepth() const;

    // one encounter check - a day's sail or a night at anchor
    // (the R68 cadence convention: the DMG's check timing is
    // the caller's)
    void seaStep();

    // R123: the day's true miles at sea (DMG pp.58-59
    // sailed table - the coaster's small-merchant sea
    // rate, the book's printed 50; rolled lo..hi so a
    // banded vessel would work too)
    int seaMilesPerDay();

    // [T] - a day's sail outward
    void seaTravel();

    // [H] - a day's sail back toward port
    void seaHomeward();

    // [C] - anchor for the night; an interrupted anchorage
    // restores nothing (the R34 convention)
    void seaCamp();

    // the homeward sail's last league: landfall (guarded by
    // mode, so endCombat can complete the arrival too)
    void checkArrivedSea();

    // ---- R70: the city streets ----------------------------------------

    // [W] from town - walk the streets (DMG p.190-192)
    void enterCity();

    void leaveCity();

    // one excursion on the R64 matrix - daytime or nighttime
    // column. Classed and service parties (the p.191-192
    // explanations) meet by the p.176 Confrontation (the R68
    // meeting builder); registry monsters fight; civilians
    // are flavor (R64 fiction rows - printed counts, no
    // stats, documented in encounters.cpp)
    void cityExcursion(dm::CityTime t);
};
