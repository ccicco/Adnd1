// ============================================================================
// Adnd1 — game/appstate.h
// The simulation core: room occupancy, treasure, camera, game
// modes, creation state, combat state, and AppState itself.
// Moved verbatim from adnd1.cpp, R31 — no windows.h here; the
// shell (adnd1.cpp) owns the Renderer.
// R33: spellbook wiring — MU starting spell at creation, the
// castable list filters by known spells, and saveGame/loadGame
// grow an optional per-MU "spells" line (v1 saves still load).
// R34: per-day slots — Character::slotsByLevel persists across
// encounters (endCombat sync), [R] rest restores slots + natural
// healing with a wandering-encounter interrupt risk; descend and
// load also refill the pool.
// R35: ammo counting — Character::missileAmmo is the live quiver
// (20 missiles at creation / bow find / load; not persisted in
// v1 saves); each shot spends one (endCombat sync), and a dry
// quiver blocks the shoot command and falls back to melee.
// R36: throw command — combatThrow() has the active member hurl
// their melee weapon (dagger/hand axe/spear): one shot from the
// weapon's own dice/plus, then unarmed 1d2 fists for the rest of
// the encounter (the weapon is recovered afterward — Actor state
// only, nothing persisted).
// R37: monster missile attacks — beginCombat marks missile-armed
// monsters from the monster key (goblin/kobold, MM convention:
// goblins short bow, kobolds sling; key list is verification
// debt — the Lua data files carry no ranged flag); they fire an
// opening volley in round 1, then close to melee.
// R38: arrow restocking — quivers refill wherever slots do:
// a completed rest (restExplore) renews both, and descending
// (descend) restocks at the same time it refills slots. Load
// already refills. Ammo stays a physical resource otherwise —
// wandering-encounter-interrupted rests restore nothing.
// R39: ammo as treasure — victorious room loot can include a
// bundle of arrows (20): added to the quiver of the first living
// missile-armed member, or stockpiled on the least-supplied one
// when everyone is armed. Bows (R28) and arrows now both drop.
// R40: thrown-weapon loot — victorious room loot can include a
// +1 dagger: claimed by the first living member whose melee
// weapon is throwable (dagger/hand axe/spear) or weaker; it can
// be hurled with [t] (R36) at +1 to hit and damage.
// R41: town hub — a new MODE_TOWN screen reached with [B] from
// the dungeon. The temple sells healing potions (50 gp), the
// fletcher sells 20-arrow bundles (30 gp). [B]/Esc returns to
// the dungeon at the same depth. Buying arrows needs a missile-
// armed member (first below 20, else least-supplied — R39
// convention). Saves are not possible in town (mode resets to
// EXPLORE on load).
// R42 (three features): (1) town expansion — the inn sells a
// safe night's rest (10 gp: full slots, quivers, and 1 hp/level
// healing, NO wander check), the temple heals the most-wounded
// member to full (100 gp), the smith sells +1 long swords
// (500 gp, first living fighter); (2) movement + range bands —
// missile fire is bounded by the weapon's short range
// (rangeTens*10 feet, PHB p.39); the round-1 volley lasts
// rangeBandsOf() rounds before melee closes (1 band = 10' range
// factor);(3) dungeon scaling — monster lair sizes and treasure
// gold now scale with depth (cap 2+level/2, gold multiplier
// 100%+25%/level above 1).
// R43 (three features): (1) DMG training — level-ups queue
// (Party::pendingTraining) until the member trains at the town
// hall ([6], 1500 gp x new level); promotion logic moved from
// gainXp to Party::trainNext (hit die + R33 MU spell study);
// queue persists in saves via an optional "training" line
// (v1-compatible); (2) party-side range — the encounter carries
// an abstract distance (5 bands, closes 1/round); [x] shoot is
// refused once the range closes (thrown weapons exempt);
// (3) town stock — [7] chain mail (75 gp, first armored-eligible
// member in worse), [8] spell scroll (200 gp, one random unknown
// L1 MU spell added to the first MU's book).
// R44 (five features): (1) stronghold — a name-level member
// (level == class cap) builds a keep ([0], 10,000 gp); rents
// (200 gp) collect on every return to town and training is
// halved while it stands; (2) identify scrolls — treasure can
// yield scrolls and UNIDENTIFIED magic items (plus rolled but
// hidden); the scribe sells scrolls ([9], 100 gp) and [I] reads
// one over the first pending item, applying weapon or armor
// enchant; (3) henchman — [H] posts a 100 gp offer (DMG p.36
// simplified); on acceptance a level-1 fighter joins as an
// extra party actor (chain + shield kit), upkeep 100 gp/level
// bills each return to town, loyalty (50 + best Cha reaction
// adj) is checked on descending — a failed roll loses the hire;
// (4) monster roster expansion — six new Lua bestiary files
// (bandit, wolf, hobgoblin, gnoll, lizard man, bugbear) and
// hobgoblin joins the missile-armed key list; (5) town hub
// polish — a company status panel (roster, henchman, keep,
// scrolls) beside the shop menu.
// R45 (five features): (1) henchman advancement and shares —
// the hire earns a half share of combat XP, levels (hit die
// d10+1) at fighter thresholds, and takes a THIRD of each
// delve's gold (accumulated in delveGold, paid into his
// purse on every return to town); (2) sage and spy consults —
// [S] 200 gp lists what lairs at this depth (the registry
// roster, an in-game MM reference), [Y] 500 gp reveals the
// CURRENT occupied rooms and their monster keys (simple
// recon, DMG p.35 spying simplified); (3) the peddler [M] —
// 500 gp for one random identified magic item (weapon +1,
// armor +1, three potions, two identify scrolls, or a spell
// scroll); (4) traps and secret doors — unoccupied rooms may
// hide a dart trap (save vs death or 2d6; a thief in the
// company may spot and disarm it first), walls hide secret
// doors found with [F] search (1-in-6, thief 3-in-6; found
// doors become ordinary doors); (5) MM reference — the sage
// consult doubles as the bestiary lore service (true book
// verification still awaits the re-uploaded MM PDF).
// ============================================================================

#pragma once

#include "../world/map.h"
#include "../rules/dice.h"
#include "../rules/character.h"
#include "../rules/classes.h"
#include "../rules/saves.h"   // R45: trap saves
#include "../dm/dm.h"
#include "../dm/dungeon.h"
#include "../ai/actor.h"
#include "../monsters/MonsterRegistry.h"
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
};

// R45: a secret door hides in a wall tile until found
struct SecretDoor {
    int  x = 0, y = 0;
    bool found = false;
};

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
};

// ----------------------------------------------------------------------------
// R24: Creation state — ROLL -> CLASS -> NAME, per member.
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
            for (int lv = 1; lv <= 3; ++lv)
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
// Combat state — interactive, commands wired to the driver (R21).
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
        // unique — creation enforces it)
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

    // R27: spells the ACTIVE member can cast right now — right
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
    int         combatRoomIndex = -1;
    std::string combatMonsterKey;

    // R23: stairs down — placed in the room farthest from entry
    int stairsX = -1, stairsY = -1;

    // R45: the level's hidden doors
    std::vector<SecretDoor> secretDoors;

    void newDungeon(uint64_t s) {
        seed = s;
        dungeon = dm::generateDungeon(s);
        map = dungeon.map;
        occupancy.init(dungeon);
        // R24: no formDefault — the roster comes from creation
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

    // R24: creation is finished — the delve begins
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

    // R24: full reset after a wipe — back to creation, career gone
    void resetToCreation() {
        party = Party{};
        creation = CreationState{};
        creation.rollFresh();
        dungeonLevel = 1;
        mode = MODE_CREATE;
        log.add("The party is no more. Roll a new company.");
    }

    // ----------------------------------------------------------------
    // R29: save/load. Plain-text career file "adnd1.sav" in the
    // working directory. The COMPANY is saved, not the floor: no
    // dungeon layout, occupancy, or combat state persists — loading
    // regenerates a fresh dungeon at the saved depth (the
    // deterministic newDungeon pipeline). Format: one token stream,
    // version-tagged; unknown/short files are rejected cleanly.
    // ----------------------------------------------------------------
    static const char* SAVE_FILE() { return "adnd1.sav"; }

    bool saveGame() const {
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
        // R43: the training queue (v1 saves lack this line — the
        // loader treats it as optional)
        fprintf(f, "training %d",
                (int)party.pendingTraining.size());
        for (int i : party.pendingTraining)
            fprintf(f, " %d", i);
        fprintf(f, "\n");
        // R44: career extras (optional lines, v1-compatible —
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
            // R33: the MU spellbook (one line per MU; other
            // classes write nothing — v1 saves stay readable)
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
        // R33: one-token pushback — holds a tag read past the
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
        // R44: generalized optional-tag chain — any number of
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
                    // R45: the hire's career records —
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

            // R33: optional spellbook line (MUs in new saves).
            // If the next tag is not "spells", push it back for
            // the next member iteration (v1 save compat).
            if (fscanf(f, "%15s", tag) == 1) {
                if (strcmp(tag, "spells") == 0) {
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
                }
            }
            p.members.push_back(c);
        }
        fclose(f);

        // R33: v1 saves predate the spellbook — grant each MU a
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
        restoreSlots();   // R34: slots are not persisted — full pool on load
        // R35: quivers are not persisted either — full 20 on load
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
    // entry point. The tile itself stays floor — the marker and
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

    // R23: descend. Career (hp/xp/gold/equipment/level) persists —
    // depth scales monsters and treasure.
    void descend() {
        ++dungeonLevel;
        log.add("You descend the worn stairs...");
        newDungeon(seed + 1000 + dungeonLevel);
        // R34: the descent takes hours — slots return with the
        // new level (keeps a descended company from being stuck
        // dry with no rest opportunity)
        restoreSlots();
        // R38: quivers restock on the descent too — the trek to a
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
            for (int lv = 1; lv <= 3; ++lv)
                c.slotsByLevel[lv - 1] =
                    spells::spellSlots(sc, c.level, lv);
        }
    }

    // R34: rest — restore slots and natural healing (1 hp per
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

    // [B] from the dungeon — retire to town for supplies
    void enterTown() {
        if (mode != MODE_EXPLORE) return;
        mode = MODE_TOWN;
        log.add("You return to the town above.");
        // R44: the keep pays its rents on every return (the
        // delve cadence stands in for the month — simplified
        // stronghold economics)
        if (party.strongholdBuilt) {
            party.gold += 200;
            log.add("The keep's steward delivers 200 gp in "
                    "rents.");
        }
        // R44: henchman upkeep — 100 gp/level billed on each
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
                        " — he takes note.");
            }
            if (party.henchmanLoyalty < 25) {
                log.add(party.henchmanName +
                        " packs his kit and quits the company.");
                party.henchmanPresent = false;
            }
        }
        // R45: the hire's THIRD of the take (DMG p.36 — a
        // stated share; this campaign promised a half share
        // = a third of the delve's gold), paid at the exit
        // into his purse
        if (party.henchmanPresent && party.delveGold > 0) {
            int cut = party.delveGold / 3;
            party.henchmanPurse += cut;
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%s is paid his share: %d gp (purse %d).",
                     party.henchmanName.c_str(), cut,
                     party.henchmanPurse);
            log.add(buf);
        }
        party.delveGold = 0;
    }

    // [B]/Esc in town — dive back in at the same depth
    void leaveTown() {
        if (mode != MODE_TOWN) return;
        // R44: the loyalty check that gates each delve (DMG
        // p.37 — a disloyal hire refuses the descent; the roll
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
            log.add("The priest shakes his head — 50 gp.");
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

    // the fletcher sells 20-arrow bundles (30 gp) — taker follows
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
            log.add("The fletcher shrugs — no one carries a bow.");
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

    // R42: the inn — a safe night's rest (10 gp). Full slots
    // (restoreSlots), full quivers (restockAmmo), 1 hp/level
    // natural healing each — and NO wander check: that is what
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
        // R44: the henchman bunks with the company — same 1
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

    // R42: the temple — heal the most-wounded living member to
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

    // R42: the smith — a +1 long sword (500 gp), claimed by the
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

    // R43: the training hall — promote the first queued member
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
            // R34: a trained caster's slot pool may have grown —
            // restore so the new slots are usable
            restoreSlots();
        }
    }

    // R43: the armorer — chain mail (75 gp, PHB list price) for
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

    // R43: the scribe — a spell scroll (200 gp): one random
    // unknown L1 MU spell is copied into the first MU's book
    // (chance-to-learn deferred to level-ups — buying knowledge
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

    // R44: the keep — a name-level member raises a stronghold.
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
                " raises a keep — rents will follow.");
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

    // R44: [I] — read an identify scroll over the first
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
            // magic weapon — the first living fighter (then
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
                log.add("The scroll reveals a long sword — "
                        "but no one can better his blade. It "
                        "is sold for 200 gp.");
                party.gold += 200;
            }
        } else {
            // enchanted armor — the first living fighter or
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
                log.add("The scroll reveals enchanted armor — "
                        "but no one can better his mail. It "
                        "is sold for 200 gp.");
                party.gold += 200;
            }
        }
    }

    // R44: [H] — post a henchman offer (DMG p.36 simplified:
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
        // hire — a simplification vs the book's rolled men)
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
                    "too well known — he declines.");
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

    // R45: [S] the sage — 200 gp for lore on what lairs at
    // this depth (the registry's level roster — an in-game
    // Monster Manual reference; MM exact values remain
    // verification debt until the book is re-uploaded)
    void townSage() {
        if (mode != MODE_TOWN) return;
        if (party.gold < 200) {
            log.add("The sage wants 200 gp for his lore.");
            return;
        }
        auto keys = registry.keysForLevel(dungeonLevel);
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
            snprintf(buf, sizeof buf,
                     "Of %s: HD %d, AC %d, worth %d xp.",
                     def->name, def->hd, def->ac, def->xpValue);
            log.add(buf);
        }
    }

    // R45: [Y] the spy — 500 gp for simple recon (DMG p.35
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

    // R45: [M] the peddler — 500 gp for one random
    // IDENTIFIED magic item (no scroll needed — the peddler
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
                    log.add("The peddler is out of swords — "
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
                    log.add("The peddler is out of armor — "
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
                // a spell scroll — one random unknown L1 MU
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
                    log.add("No scrolls your sages can use — "
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
        // R38: a completed rest renews arrows too — fletching and
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
        auto candidates = registry.keysForLevel(dungeonLevel);
        if (candidates.empty()) return;

        for (auto& room : occupancy.rooms) {
            room.monsterKey.clear();
            room.count = 0;
            room.looted = false;
            room.trap = 0;
            if (rng.below(100) >= 50) {
                // R45: an unoccupied room may hide a dart trap
                if (rng.below(100) < 15) room.trap = 1;
                continue;
            }
            room.monsterKey =
                candidates[(size_t)rng.below((uint32_t)candidates.size())];
            room.count = 1 + (int)rng.below((uint32_t)roomCountCap());
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
    // find/remove-trades instinct — simplified); otherwise a
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
                     "A dart whistles past %s — saved!",
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
                     "A trap! Darts strike %s for %d — %s "
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

    // R45: place secret doors — wall tiles that border floor
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

    // R45: [F] search — one turn spent feeling the walls.
    // Each adjacent unfound secret door rolls 1-in-6 (a
    // thief in the company raises it to 3-in-6 — his keen
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
        // R42: gold scales up with depth — 25% more per level
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
        int perMonster = def ? def->xpValue : 10;
        int survivors = 0;
        for (const auto& a : combat.encounter->party())
            if (a.alive()) ++survivors;
        if (survivors < 1) survivors = 1;

        int slain = 0;
        for (const auto& m : combat.encounter->monsters())
            if (!m.alive()) ++slain;

        if (slain > 0) {
            int totalXp = perMonster * slain;
            int share = totalXp / survivors;
            party.kills += slain;
            char buf[96];
            snprintf(buf, sizeof buf,
                     "%d slain, %d xp each.", slain, share);
            log.add(buf);
            party.gainXp(share, dice, log);
            // R45: the hire earns a half share (DMG p.86 —
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
                    // R26: treasure XP — 1 gp = 1 xp, split among
                    // living members like combat XP (victory only;
                    // fleeing leaves loot AND xp behind)
                    int goldShare = t.gold / survivors;
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
                // R40: +1 dagger — throwable loot. Claimed by the
                // first living member whose melee weapon is either
                // already throwable (an upgrade in plus — dagger
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
                // R28: short bow — claimed by the first living
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
                // R39: a bundle of arrows — given to the first
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
                // R44: an unidentified magic item — the enchant
                // is rolled now but hidden until a scroll is
                // read over it ([I] in town)
                if (t.unidentifiedItem) {
                    Party::PendingItem it;
                    it.kind = (int)rng.below(2);
                    it.plus = 1 +
                        (rng.below(100) < 10 ? 1 : 0);
                    party.unidentified.push_back(it);
                    log.add("You find an unidentified magic "
                            "item — a scribe's scroll would "
                            "serve.");
                }
                room.monsterKey.clear();
                room.count = 0;
                room.looted = true;
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

    // R25: shared combat entry — starts the encounter and arms the
    // quaff hook (the hook owns the potion pool and the heal, so
    // the driver stays inventory-free)
    void beginCombat(std::vector<ai::Actor> foes, int roomIndex,
                     const std::string& monsterKey) {
        // R37: mark missile-armed monsters (MM convention: goblins
        // short bow, kobolds sling). The Lua registry data carries
        // no ranged flag, so the app owns this list — verification
        // debt if the Lua keys ever change.
        // R42: also seed rangedRounds from the weapon's short
        // range band (PHB p.39: short bow 50' = 5 bands, sling
        // 50' = 5 bands) — volley rounds before melee closes.
        for (auto& m : foes) {
            if (!m.isCharacter &&
                if (!m.isCharacter &&
                    (monsterKey == "goblin" ||
                     monsterKey == "kobold" ||
                     monsterKey == "hobgoblin")) {   // R44: MM bows
                m.monsterRanged = true;
                m.rangedRounds = 5;   // 50' short range, 10' bands
            }
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
        combatRoomIndex = roomIndex;
        combatMonsterKey = monsterKey;
        mode = MODE_COMBAT;
    }

    // R25: explore-mode quaff — heals the most-wounded living
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

    // R25: combat quaff — the ACTIVE member drinks this round
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

    // R28: the ACTIVE member fires missiles this round — requires
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
        // R43: the range must still be open — once the foes have
        // closed, only melee (or a hurled weapon) serves
        if (!combat.encounter->rangeOpen()) {
            log.add("The foes are upon you — no time for "
                    "missiles!");
            return;
        }
        // R35: dry quiver — nothing left to loose
        if (partyActors[combat.activeMember].missileAmmo <= 0) {
            log.add("That member's quiver is empty.");
            return;
        }
        combat.encounter->requestShoot(combat.activeMember);
        log.add("Missiles readied — [space] to resolve the round.");
    }

    // R36: the ACTIVE member hurls their melee weapon this round
    // (dagger/hand axe/spear) — one shot from the weapon's own
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
        log.add("Weapon readied to hurl — [space] to resolve the round.");
    }

    void spawnRoomEncounter(int roomIndex) {
        if (mode == MODE_COMBAT) return;
        if (!party.alive()) return;
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.monsterKey.empty()) return;

        std::vector<ai::Actor> foes;
        for (int i = 0; i < room.count; ++i)
            foes.push_back(registry.toActor(room.monsterKey, dice));

        const monsters::MonsterDef* def = registry.find(room.monsterKey);
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

        auto candidates = registry.keysForLevel(dungeonLevel);
        if (candidates.empty()) return;
        std::string key =
            candidates[(size_t)rng.below((uint32_t)candidates.size())];

        int count = 1 + (int)rng.below((uint32_t)roomCountCap());
        std::vector<ai::Actor> foes;
        for (int i = 0; i < count; ++i)
            foes.push_back(registry.toActor(key, dice));

        char buf[96];
        snprintf(buf, sizeof buf, "%d wandering %s attack!",
                 count, key.c_str());
        log.add(buf);

        beginCombat(std::move(foes), -1, key);
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
            // (hp, level — energy drain can strip levels)
            for (const auto& a : combat.encounter->party()) {
                for (auto& c : party.members) {
                    if (c.name != a.name) continue;
                    c.hp = a.hp;
                    c.maxHp = a.maxHp;
                    c.level = a.level;
                    // R34: spent slots persist (per-day tracking)
                    for (int lv = 0; lv < 3; ++lv)
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
        mode = MODE_EXPLORE;
    }
};
