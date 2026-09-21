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
// ============================================================================

#pragma once

#include "../world/map.h"
#include "../rules/dice.h"
#include "../rules/character.h"
#include "../rules/classes.h"
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

    bool empty() const {
        return gold == 0 && !potionHealing && !magicSword &&
               !missileWeapon && !ammoBundle;
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
            if (rng.below(100) >= 50) continue;
            room.monsterKey =
                candidates[(size_t)rng.below((uint32_t)candidates.size())];
            room.count = 1 + (int)rng.below((uint32_t)roomCountCap());
        }
    }

    int roomCountCap() const {
        return dungeonLevel >= 2 ? 3 : 2;
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

    Treasure rollTreasure(int roomIndex) {
        Treasure t;
        (void)roomIndex;
        t.gold = (int)dice.roll(3, 6, 0) * 10 * dungeonLevel;
        if (rng.below(100) < 10) t.potionHealing = true;
        if (rng.below(100) < 5) t.magicSword = true;
        if (rng.below(100) < 10) t.missileWeapon = true;   // R28
        if (rng.below(100) < 15) t.ammoBundle = true;      // R39
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
        }

        if (combatRoomIndex >= 0) {
            RoomOccupant& room = occupancy.rooms[combatRoomIndex];
            if (!room.monsterKey.empty()) {
                Treasure t = rollTreasure(combatRoomIndex);
                if (t.gold > 0) {
                    party.gold += t.gold;
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
        for (auto& m : foes)
            if (!m.isCharacter &&
                (monsterKey == "goblin" || monsterKey == "kobold"))
                m.monsterRanged = true;
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
