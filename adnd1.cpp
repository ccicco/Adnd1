// ============================================================================
// Adnd1 — a 2D tile-based CRPG implementing AD&D 1st Edition rules
// Rebuild tranche R25: usable potions.
//
//   - Party carries a potion pool (from R22 treasure finds)
//   - [P] quaff in EXPLORE heals the most-wounded living member
//   - [P] quaff in COMBAT: the active member drinks — the round
//     is consumed via ACTION_DRINK on the segment scheduler
//     (end of round, R7), resolved engine-authoritatively
//   - Potion of healing: 2d4+2 hp, capped at max HP
//   - The quaff hook owns inventory + heal; combat healing
//     persists via the endCombat name-sync
//
// Build (MinGW, Lua 5.4):
//   g++ -std=c++17 -I. -Ilua/include adnd1.cpp rules/dice.cpp rules/character.cpp rules/combat.cpp rules/saves.cpp rules/turn.cpp rules/classes.cpp spells/spells.cpp spelleffects/spelleffects.cpp items/items.cpp dm/dm.cpp dm/dungeon.cpp ai/actor.cpp monsters/MonsterRegistry.cpp lua/src/liblua.a -o adnd1.exe -mwindows
// ============================================================================

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "world/map.h"
#include "rules/dice.h"
#include "rules/character.h"
#include "rules/combat.h"
#include "rules/classes.h"
#include "dm/dm.h"
#include "dm/dungeon.h"
#include "ai/actor.h"
#include "monsters/MonsterRegistry.h"
#include "items/items.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

using namespace world;

// ----------------------------------------------------------------------------
// View / HUD geometry
// ----------------------------------------------------------------------------

static const int VIEW_W = TILE_W * VIEW_TILES_X;   // 800
static const int VIEW_H = TILE_H * VIEW_TILES_Y;   // 608
static const int HUD_H  = 96;
static const int WINDOW_W = VIEW_W;
static const int WINDOW_H = VIEW_H + HUD_H;

// ----------------------------------------------------------------------------
// R24: party roster constants
// ----------------------------------------------------------------------------

static const int PARTY_MAX      = 6;   // hard ceiling
static const int PARTY_DEFAULT  = 6;   // starting cap (adjustable 1-6)
static const int NAME_MAX_CHARS = 16;

static const char* CLASS_NAMES[4] = {
    "Fighter", "Magic-User", "Cleric", "Thief"
};
static const char CLASS_INITIALS[4] = { 'F', 'M', 'C', 'T' };

// ----------------------------------------------------------------------------
// Message log
// ----------------------------------------------------------------------------

struct MessageLog {
    static const int MAX_LINES = 4;
    std::string lines[MAX_LINES];
    int head = 0;

    void add(const std::string& s) {
        lines[head] = s;
        head = (head + 1) % MAX_LINES;
    }
    const std::string& get(int i) const {
        int idx = head - 1 - i;
        while (idx < 0) idx += MAX_LINES;
        return lines[idx];
    }
};

// ----------------------------------------------------------------------------
// Renderer — GDI, double-buffered
// ----------------------------------------------------------------------------

struct Renderer {
    HDC     memDC = nullptr;
    HBITMAP memBM = nullptr;
    int     w = 0, h = 0;

    void resize(HDC wndDC, int newW, int newH) {
        if (memBM) { DeleteObject(memBM); memBM = nullptr; }
        if (memDC) { DeleteDC(memDC);     memDC = nullptr; }
        w = newW; h = newH;
        memDC = CreateCompatibleDC(wndDC);
        memBM = CreateCompatibleBitmap(wndDC, w, h);
        SelectObject(memDC, memBM);
    }
    void destroy() {
        if (memBM) DeleteObject(memBM);
        if (memDC) DeleteDC(memDC);
        memBM = nullptr; memDC = nullptr;
    }
};

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

    bool empty() const {
        return gold == 0 && !potionHealing && !magicSword;
    }
};

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
    items::ArmorInstance  armor;
    bool shield = false;

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
        a.armor  = armor;
        a.shield = shield;
        a.hp     = hp;
        a.maxHp  = maxHp;
        a.morale = dm::MORALE_FANATIC;   // player party never breaks
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

    bool alive() const {
        if (!formed) return false;
        for (const auto& c : members)
            if (c.hp > 0) return true;
        return false;
    }

    // per-member XP + level-ups (R22 logic, looped over the roster).
    // NOTE: prime-requisite XP% bonus (R3 primeRequisitePct) is NOT
    // applied yet — deferred to a later tranche (logged).
    void gainXp(int amount, rules::Dice& dice, MessageLog& log) {
        for (auto& c : members) {
            if (c.hp <= 0) continue;   // the dead earn nothing
            c.xp += amount;
            int cap = rules::CLASS_LEVEL_CAP[c.classIndex];
            while (c.level < cap &&
                   c.xp >= rules::xpForLevel(c.classIndex,
                                             c.level + 1)) {
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
            }
        }
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
                break;
        }
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

    void start(std::vector<ai::Actor> party, std::vector<ai::Actor> foes,
               uint64_t seed) {
        memberNames.clear();
        for (const auto& a : party)
            memberNames.push_back(a.name);
        selectedTargets.assign(party.size(), 0);
        activeMember = 0;

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
    Renderer      rend;
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
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Dungeon level %d. The air grows colder.",
                 dungeonLevel);
        log.add(buf);
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

static AppState g_app;

// ----------------------------------------------------------------------------
// Creation input (R24)
// ----------------------------------------------------------------------------

static bool nameTaken(const std::string& n) {
    for (const auto& c : g_app.party.members)
        if (c.name == n) return true;
    return false;
}

static void creationKeyDown(WPARAM wp) {
    CreationState& cr = g_app.creation;
    AppState& s = g_app;

    // party size cap: adjustable at any creation stage
    if (wp == VK_OEM_PLUS || wp == VK_ADD || wp == '=') {
        if (cr.partySizeCap < PARTY_MAX) ++cr.partySizeCap;
        return;
    }
    if (wp == VK_OEM_MINUS || wp == VK_SUBTRACT || wp == '-') {
        if (cr.partySizeCap > 1) --cr.partySizeCap;
        // dropping the cap below the roster size trims the tail
        while ((int)s.party.members.size() > cr.partySizeCap)
            s.party.members.pop_back();
        return;
    }

    switch (cr.stage) {
        case CR_ROLL:
            switch (wp) {
                case 'R':
                    cr.rollFresh();
                    break;
                case VK_RETURN:
                    cr.stage = CR_CLASS;
                    break;
                case 'D':
                    // begin the delve with the roster as-is
                    if (!s.party.members.empty())
                        s.beginDelve();
                    break;
            }
            break;

        case CR_CLASS:
            switch (wp) {
                case '1': case '2': case '3': case '4': {
                    int idx = (int)(wp - '1');
                    if (cr.classEligible(idx)) {
                        cr.classPick = idx;
                        cr.stage = CR_NAME;
                    }
                    break;
                }
                case VK_ESCAPE:
                    cr.stage = CR_ROLL;   // back to reroll
                    break;
            }
            break;

        case CR_NAME:
            if (wp == VK_ESCAPE) {
                cr.stage = CR_CLASS;      // back to class choice
                cr.nameBuf.clear();
            }
            break;
    }
}

static void creationChar(WPARAM ch) {
    CreationState& cr = g_app.creation;
    if (cr.stage != CR_NAME) return;
    if (ch == '\r' || ch == '\n') return;   // Enter handled in KEYDOWN
    if (ch == 8) {                          // backspace
        if (!cr.nameBuf.empty())
            cr.nameBuf.pop_back();
        return;
    }
    if (ch >= 32 && ch < 127 &&
        (int)cr.nameBuf.size() < NAME_MAX_CHARS) {
        cr.nameBuf.push_back((char)ch);
    }
}

// confirm the name and add the member
static void creationConfirmName() {
    CreationState& cr = g_app.creation;
    AppState& s = g_app;

    std::string n = cr.nameBuf;
    if (n.empty()) {
        char buf[32];
        snprintf(buf, sizeof buf, "Hero%d",
                 (int)s.party.members.size() + 1);
        n = buf;
    }
    if (nameTaken(n)) {
        // unique names keep the combat hook keyed by name sound
        int suffix = 2;
        std::string base = n;
        while (nameTaken(n)) {
            char buf[40];
            snprintf(buf, sizeof buf, "%s%d", base.c_str(), suffix++);
            n = buf;
        }
    }

    Character c = cr.makeMember(cr.classPick);
    c.name = n;
    s.party.members.push_back(c);

    char buf[96];
    snprintf(buf, sizeof buf, "%s the %s joins the party.",
             c.name.c_str(), CLASS_NAMES[c.classIndex]);
    s.log.add(buf);

    if ((int)s.party.members.size() >= cr.partySizeCap) {
        s.beginDelve();   // roster full — off we go
    } else {
        cr.rollFresh();   // next member
    }
}

// ----------------------------------------------------------------------------
// Movement (EXPLORE mode)
// ----------------------------------------------------------------------------

static void onPartyMove(int dx, int dy) {
    AppState& s = g_app;
    if (s.mode != MODE_EXPLORE) return;
    if (!s.party.alive()) return;

    int nx = s.party.x + dx;
    int ny = s.party.y + dy;
    if (!s.map.walkable(nx, ny)) return;
    s.party.x = nx;
    s.party.y = ny;
    s.cam.follow(s.party);
    ++s.turnCount;

    // R23: stairs check first — descending is the priority action
    if (s.party.x == s.stairsX && s.party.y == s.stairsY) {
        s.descend();
        return;
    }

    int roomIdx = s.occupiedRoomNear(s.party.x, s.party.y);
    if (roomIdx >= 0) {
        s.spawnRoomEncounter(roomIdx);
        return;
    }

    if (dm::wanderCheck(s.dice, s.wander)) {
        int dist = dm::wanderDistance(s.dice);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Movement in the distance... (%d ft)", dist);
        s.log.add(buf);
        s.spawnWanderingEncounter();
    }
}

// ----------------------------------------------------------------------------
// Drawing: explore view
// ----------------------------------------------------------------------------

static void drawTile(HDC dc, int px, int py, uint8_t t) {
    HBRUSH br;
    switch (t) {
        case TILE_FLOOR: br = CreateSolidBrush(RGB( 60,  50,  40)); break;
        case TILE_CORR:  br = CreateSolidBrush(RGB( 45,  38,  30)); break;
        case TILE_WALL:  br = CreateSolidBrush(RGB(110, 105, 100)); break;
        case TILE_DOOR:  br = CreateSolidBrush(RGB(150, 100,  40)); break;
        default:         br = CreateSolidBrush(RGB(  5,   5,  10)); break;
    }
    RECT r = { px, py, px + TILE_W, py + TILE_H };
    FillRect(dc, &r, br);
    DeleteObject(br);
    if (t != TILE_VOID) {
        HPEN pen = CreatePen(PS_SOLID, 1, RGB(20, 18, 15));
        HPEN old = (HPEN)SelectObject(dc, pen);
        MoveToEx(dc, px, py, nullptr);
        LineTo(dc, px + TILE_W, py);
        LineTo(dc, px + TILE_W, py + TILE_H);
        SelectObject(dc, old);
        DeleteObject(pen);
    }
}

static void drawOccupancyTint(HDC dc, int px, int py) {
    HBRUSH hatch = CreateHatchBrush(HS_DIAGCROSS, RGB(90, 30, 25));
    RECT r = { px, py, px + TILE_W, py + TILE_H };
    FillRect(dc, &r, hatch);
    DeleteObject(hatch);
}

static void drawMonsterMarker(HDC dc, int px, int py, int count) {
    HBRUSH br = CreateSolidBrush(RGB(200, 60, 30));
    HPEN   pen = CreatePen(PS_SOLID, 2, RGB(255, 200, 120));
    HPEN   oldPen = (HPEN)SelectObject(dc, pen);
    HBRUSH oldBr  = (HBRUSH)SelectObject(dc, br);
    Ellipse(dc, px - 8, py - 8, px + 8, py + 8);
    SelectObject(dc, oldPen);
    SelectObject(dc, oldBr);
    DeleteObject(pen);
    DeleteObject(br);

    if (count > 1) {
        char pip[8];
        snprintf(pip, sizeof pip, "%d", count);
        SetBkMode(dc, TRANSPARENT);
        SetTextColor(dc, RGB(255, 230, 180));
        TextOutA(dc, px + 6, py - 6, pip, (int)strlen(pip));
    }
}

// R23: stairs marker — a cool blue ring with a down-chevron
static void drawStairsMarker(HDC dc, int px, int py) {
    HBRUSH br = CreateSolidBrush(RGB(50, 70, 130));
    HPEN   pen = CreatePen(PS_SOLID, 2, RGB(150, 190, 255));
    HPEN   oldPen = (HPEN)SelectObject(dc, pen);
    HBRUSH oldBr  = (HBRUSH)SelectObject(dc, br);
    Ellipse(dc, px - 11, py - 11, px + 11, py + 11);
    SelectObject(dc, oldPen);
    SelectObject(dc, oldBr);
    DeleteObject(pen);
    DeleteObject(br);

    // chevron pointing down
    HPEN cp = CreatePen(PS_SOLID, 3, RGB(220, 235, 255));
    HPEN op = (HPEN)SelectObject(dc, cp);
    MoveToEx(dc, px - 6, py - 3, nullptr);
    LineTo(dc, px, py + 3);
    LineTo(dc, px + 6, py - 3);
    SelectObject(dc, op);
    DeleteObject(cp);
}

// R24: party formation — each member's initial in a cluster on the
// party tile (dead members are not drawn)
static void drawPartyFormation(HDC dc, const Party& party,
                               int cx, int cy) {
    static const int OFFS[6][2] = {
        { -7, -7 }, {  7, -7 }, { -7,  7 }, {  7,  7 },
        {  0, -13 }, {  0,  13 }
    };
    SetBkMode(dc, TRANSPARENT);
    int n = 0;
    for (const auto& c : party.members) {
        if (c.hp <= 0) continue;
        if (n >= 6) break;
        int mx = cx + OFFS[n][0] - 5;
        int my = cy + OFFS[n][1] - 7;
        HBRUSH br = CreateSolidBrush(RGB(220, 40, 40));
        RECT r = { mx, my, mx + 11, my + 13 };
        FillRect(dc, &r, br);
        DeleteObject(br);
        char initial[2] = { (char)toupper((unsigned char)c.name[0]), 0 };
        if (!c.name.empty()) {
            SetTextColor(dc, RGB(255, 255, 255));
            TextOutA(dc, mx + 2, my, initial, 1);
        }
        ++n;
    }
}

static void drawView(HDC dc, const AppState& s) {
    const Map& map = s.map;
    const Camera& cam = s.cam;
    const Party& party = s.party;

    RECT vr = { 0, 0, VIEW_W, VIEW_H };
    HBRUSH black = CreateSolidBrush(RGB(0, 0, 0));
    FillRect(dc, &vr, black);
    DeleteObject(black);

    for (int ty = 0; ty < VIEW_TILES_Y; ++ty) {
        for (int tx = 0; tx < VIEW_TILES_X; ++tx) {
            int wx = cam.x + tx, wy = cam.y + ty;
            uint8_t t = map.at(wx, wy);
            drawTile(dc, tx * TILE_W, ty * TILE_H, t);

            if (t == TILE_FLOOR) {
                int room = s.roomAt(wx, wy);
                if (room >= 0 && !s.occupancy.rooms[room].monsterKey.empty())
                    drawOccupancyTint(dc, tx * TILE_W, ty * TILE_H);
            }
        }
    }

    for (const auto& room : s.occupancy.rooms) {
        if (room.monsterKey.empty()) continue;
        int sx = room.denX - cam.x, sy = room.denY - cam.y;
        if (sx < 0 || sy < 0 || sx >= VIEW_TILES_X || sy >= VIEW_TILES_Y)
            continue;
        drawMonsterMarker(dc, sx * TILE_W + TILE_W / 2,
                          sy * TILE_H + TILE_H / 2, room.count);
    }

    // R23: stairs marker
    if (s.stairsX >= 0) {
        int sx = s.stairsX - cam.x, sy = s.stairsY - cam.y;
        if (sx >= 0 && sy >= 0 && sx < VIEW_TILES_X && sy < VIEW_TILES_Y)
            drawStairsMarker(dc, sx * TILE_W + TILE_W / 2,
                             sy * TILE_H + TILE_H / 2);
    }

    if (!party.alive()) return;
    int ppx = (party.x - cam.x) * TILE_W + TILE_W / 2;
    int ppy = (party.y - cam.y) * TILE_H + TILE_H / 2;
    drawPartyFormation(dc, party, ppx, ppy);
}

// ----------------------------------------------------------------------------
// Drawing: combat view
// ----------------------------------------------------------------------------

static void drawCombatantRow(HDC dc, int x, int y, int w,
                             const ai::Actor& a, bool isParty,
                             bool selected) {
    char line[96];
    snprintf(line, sizeof line, "%s%s", selected ? "> " : "", a.name.c_str());
    SetTextColor(dc, isParty ? RGB(120, 200, 120) : RGB(230, 110, 90));
    if (selected) SetTextColor(dc, RGB(255, 255, 120));
    TextOutA(dc, x, y, line, (int)strlen(line));

    int barW = w - 160;
    RECT bg = { x + 150, y + 4, x + 150 + barW, y + 16 };
    HBRUSH dark = CreateSolidBrush(RGB(40, 20, 20));
    FillRect(dc, &bg, dark);
    DeleteObject(dark);
    int fill = a.maxHp > 0 ? (a.hp * barW) / a.maxHp : 0;
    if (fill < 0) fill = 0;
    RECT fg = { x + 150, y + 4, x + 150 + fill, y + 16 };
    HBRUSH br = CreateSolidBrush(
        a.alive() ? RGB(190, 60, 60) : RGB(70, 70, 70));
    FillRect(dc, &fg, br);
    DeleteObject(br);

    snprintf(line, sizeof line, "%d/%d", a.hp, a.maxHp);
    SetTextColor(dc, RGB(200, 190, 160));
    TextOutA(dc, x + 160 + barW, y, line, (int)strlen(line));

    if (selected) {
        HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 120));
        HPEN old = (HPEN)SelectObject(dc, pen);
        RECT r = { x - 6, y - 4, x + 145, y + 20 };
        MoveToEx(dc, r.left, r.top, nullptr);
        LineTo(dc, r.right, r.top);
        LineTo(dc, r.right, r.bottom);
        LineTo(dc, r.left, r.bottom);
        LineTo(dc, r.left, r.top);
        SelectObject(dc, old);
        DeleteObject(pen);
    }
}

static void drawCombat(HDC dc, const CombatState& cs) {
    RECT vr = { 0, 0, VIEW_W, VIEW_H };
    HBRUSH black = CreateSolidBrush(RGB(8, 6, 4));
    FillRect(dc, &vr, black);
    DeleteObject(black);

    SetBkColor(dc, RGB(8, 6, 4));
    SetTextColor(dc, RGB(220, 200, 160));
    char line[160];
    snprintf(line, sizeof line,
             "COMBAT!  [q/e] member  [tab/1-9] target  [p] quaff  "
             "[space] attack+round  [f] flee  [esc] auto-resolve");
    TextOutA(dc, 20, 14, line, (int)strlen(line));

    if (!cs.encounter) return;
    const auto& party = cs.encounter->party();
    const auto& mons  = cs.encounter->monsters();

    SetTextColor(dc, RGB(140, 210, 140));
    TextOutA(dc, 20, 48, "PARTY", 5);
    int y = 70;
    for (size_t i = 0; i < party.size(); ++i) {
        // active member gets the selection box
        bool sel = ((int)i == cs.activeMember) && party[i].alive();
        drawCombatantRow(dc, 20, y, VIEW_W / 2 - 40, party[i], true, sel);
        y += 26;
    }

    SetTextColor(dc, RGB(230, 130, 110));
    TextOutA(dc, VIEW_W / 2 + 20, 48, "MONSTERS", 8);
    y = 70;
    for (size_t i = 0; i < mons.size(); ++i) {
        // the ACTIVE MEMBER's current target is highlighted
        int tgt = (cs.activeMember < (int)cs.selectedTargets.size())
                      ? cs.selectedTargets[cs.activeMember] : -1;
        bool sel = ((int)i == tgt) && mons[i].alive();
        drawCombatantRow(dc, VIEW_W / 2 + 20, y, VIEW_W / 2 - 40,
                         mons[i], false, sel);
        y += 26;
    }

    const auto& lg = cs.encounter->log();
    SetTextColor(dc, RGB(190, 180, 150));
    int ly = VIEW_H - 24 - (int)std::min<size_t>(lg.size(), 10) * 22;
    size_t first = lg.size() > 10 ? lg.size() - 10 : 0;
    for (size_t i = first; i < lg.size(); ++i) {
        TextOutA(dc, 20, ly, lg[i].text.c_str(),
                 (int)lg[i].text.size());
        ly += 22;
    }
}

// ----------------------------------------------------------------------------
// Drawing: creation view (R24)
// ----------------------------------------------------------------------------

static void drawCreate(HDC dc, const AppState& s) {
    const CreationState& cr = s.creation;

    RECT vr = { 0, 0, WINDOW_W, WINDOW_H };
    HBRUSH back = CreateSolidBrush(RGB(10, 9, 7));
    FillRect(dc, &vr, back);
    DeleteObject(back);
    SetBkMode(dc, TRANSPARENT);

    // title + party size
    SetTextColor(dc, RGB(230, 210, 160));
    char line[160];
    snprintf(line, sizeof line,
             "FORGE YOUR PARTY   members %d/%d   "
             "[+/-] party size (1-%d)",
             (int)s.party.members.size(), cr.partySizeCap, PARTY_MAX);
    TextOutA(dc, 20, 14, line, (int)strlen(line));

    // roster so far
    SetTextColor(dc, RGB(150, 200, 150));
    TextOutA(dc, 20, 44, "THE COMPANY:", 12);
    int y = 66;
    if (s.party.members.empty()) {
        SetTextColor(dc, RGB(120, 110, 95));
        TextOutA(dc, 30, y, "(none yet)", 10);
        y += 22;
    } else {
        for (const auto& c : s.party.members) {
            char row[96];
            snprintf(row, sizeof row, "  %s  %s %d  HP %d/%d  STR %s",
                     c.name.c_str(), CLASS_NAMES[c.classIndex],
                     c.level, c.hp, c.maxHp, c.strDisplay().c_str());
            SetTextColor(dc, c.hp > 0 ? RGB(170, 220, 170)
                                      : RGB(110, 110, 110));
            TextOutA(dc, 30, y, row, (int)strlen(row));
            y += 22;
        }
    }

    // ---- stage panel -------------------------------------------------------
    int py = 260;
    SetTextColor(dc, RGB(220, 200, 160));

    switch (cr.stage) {
        case CR_ROLL: {
            TextOutA(dc, 20, py, "THE DICE DECIDE (4d6, drop lowest)",
                     33);
            py += 30;

            static const char* ABIL[6] = {
                "STR", "INT", "WIS", "DEX", "CON", "CHA"
            };
            const rules::AbilityScores& a = cr.rolled;
            int vals[6] = { a.str, a.int_, a.wis, a.dex, a.con, a.cha };

            for (int i = 0; i < 6; ++i) {
                char row[64];
                snprintf(row, sizeof row, "  %s  %2d",
                         ABIL[i], vals[i]);
                SetTextColor(dc, RGB(210, 195, 165));
                TextOutA(dc, 40, py, row, (int)strlen(row));
                py += 24;
            }

            // derived adjustments
            char der[160];
            snprintf(der, sizeof der,
                     "melee hit %+#d  dmg %+#d   react %+#d  AC %+#d   "
                     "hp/die %+#d",
                     rules::strHitAdj(a.str,
                                      rules::ExceptionalStrength{}),
                     rules::strDmgAdj(a.str,
                                      rules::ExceptionalStrength{}),
                     rules::dexReactionAdj(a.dex),
                     rules::dexDefensiveAdj(a.dex),
                     rules::conHPAdj(a.con));
            SetTextColor(dc, RGB(160, 175, 190));
            TextOutA(dc, 40, py + 8, der, (int)strlen(der));

            SetTextColor(dc, RGB(190, 175, 140));
            TextOutA(dc, 20, VIEW_H - 60,
                     "[R] reroll   [Enter] accept roll",
                     31);
            if (!s.party.members.empty())
                TextOutA(dc, 20, VIEW_H - 38,
                         "[D] begin the delve with this company",
                         38);
            break;
        }

        case CR_CLASS: {
            TextOutA(dc, 20, py, "CHOOSE A CLASS", 15);
            py += 30;
            for (int i = 0; i < 4; ++i) {
                int ab = cr.rolled.get(
                    (rules::Ability)rules::primeRequisite(i));
                int xpPct = rules::primeRequisitePct((uint8_t)ab);
                bool ok = cr.classEligible(i);
                char row[96];
                snprintf(row, sizeof row, "  [%d] %-12s  %s %2d  "
                         "(%+#d%% XP)  %s",
                         i + 1, CLASS_NAMES[i],
                         rules::abilityName(
                             (rules::Ability)rules::primeRequisite(i)),
                         ab, xpPct,
                         ok ? "" : "- requires 9+");
                SetTextColor(dc, ok ? RGB(210, 195, 165)
                                    : RGB(110, 105, 95));
                TextOutA(dc, 40, py, row, (int)strlen(row));
                py += 26;
            }
            SetTextColor(dc, RGB(190, 175, 140));
            TextOutA(dc, 20, VIEW_H - 60,
                     "[1-4] choose class   [esc] back to roll",
                     39);
            break;
        }

        case CR_NAME: {
            TextOutA(dc, 20, py, "NAME THIS CHARACTER", 20);
            py += 30;
            char prompt[96];
            snprintf(prompt, sizeof prompt, "  Name: %s_",
                     cr.nameBuf.c_str());
            SetTextColor(dc, RGB(230, 220, 190));
            TextOutA(dc, 40, py, prompt, (int)strlen(prompt));
            SetTextColor(dc, RGB(190, 175, 140));
            TextOutA(dc, 20, VIEW_H - 60,
                     "[type] name   [Enter] confirm   [esc] back",
                     42);
            break;
        }
    }

    // log tail at the bottom of the HUD area
    SetTextColor(dc, RGB(160, 150, 120));
    TextOutA(dc, 12, VIEW_H + 56, s.log.get(1).c_str(),
             (int)s.log.get(1).size());
    SetTextColor(dc, RGB(230, 220, 180));
    TextOutA(dc, 12, VIEW_H + 76, s.log.get(0).c_str(),
             (int)s.log.get(0).size());
}

// ----------------------------------------------------------------------------
// Drawing: HUD
// ----------------------------------------------------------------------------

static void drawHud(HDC dc, const AppState& s) {
    const Party& party = s.party;
    RECT hr = { 0, VIEW_H, WINDOW_W, WINDOW_H };
    HBRUSH panel = CreateSolidBrush(RGB(25, 22, 18));
    FillRect(dc, &hr, panel);
    DeleteObject(panel);

    SetBkColor(dc, RGB(25, 22, 18));
    SetTextColor(dc, RGB(200, 190, 160));

    // R24: roster line — every member, name truncated to 8 chars
    char line[256];
    line[0] = 0;
    size_t len = 0;
    for (const auto& c : party.members) {
        if (len > sizeof line - 32) break;
        char tok[40];
        char nm[9];
        strncpy(nm, c.name.c_str(), 8);
        nm[8] = 0;
        snprintf(tok, sizeof tok, "%s%s %c%d %d/%d   ",
                 c.hp > 0 ? "" : "†",
                 nm, CLASS_INITIALS[c.classIndex],
                 c.level, c.hp, c.maxHp);
        strcat(line, tok);
        len = strlen(line);
    }
    TextOutA(dc, 12, VIEW_H + 8, line, (int)strlen(line));

    snprintf(line, sizeof line,
             "Dungeon Lvl %d  Rooms: %d (%d lairs)  %d gp  Potions %d  "
             "Kills %d  Turn %d  Seed %llu  [P] quaff",
             s.dungeonLevel, (int)s.dungeon.rooms.size(),
             s.countOccupied(), party.gold, party.potions,
             party.kills, s.turnCount, (unsigned long long)s.seed);
    TextOutA(dc, 12, VIEW_H + 32, line, (int)strlen(line));

    SetTextColor(dc, RGB(160, 150, 120));
    TextOutA(dc, 12, VIEW_H + 56, s.log.get(1).c_str(), (int)s.log.get(1).size());
    SetTextColor(dc, RGB(230, 220, 180));
    TextOutA(dc, 12, VIEW_H + 76, s.log.get(0).c_str(), (int)s.log.get(0).size());
}

// ----------------------------------------------------------------------------
// Window procedure
// ----------------------------------------------------------------------------

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            return 0;

        case WM_SIZE: {
            HDC dc = GetDC(hwnd);
            g_app.rend.resize(dc, WINDOW_W, WINDOW_H);
            ReleaseDC(hwnd, dc);
            InvalidateRect(hwnd, nullptr, FALSE);
            return 0;
        }

        case WM_CHAR:
            if (g_app.mode == MODE_CREATE)
                creationChar(wp);
            InvalidateRect(hwnd, nullptr, FALSE);
            return 0;

        case WM_KEYDOWN:
            if (g_app.mode == MODE_CREATE) {
                creationKeyDown(wp);
                // Enter in the NAME stage confirms the member
                // (creationKeyDown only moves between stages)
                if (wp == VK_RETURN &&
                    g_app.creation.stage == CR_NAME &&
                    g_app.mode == MODE_CREATE) {
                    creationConfirmName();
                }
            } else if (g_app.mode == MODE_COMBAT) {
                switch (wp) {
                    case VK_TAB:
                        g_app.combat.cycleTarget(
                            (GetKeyState(VK_SHIFT) & 0x8000) ? -1 : 1);
                        break;

                    case 'Q':
                        g_app.combat.cycleMember(-1);
                        break;
                    case 'E':
                        g_app.combat.cycleMember(1);
                        break;

                    case VK_SPACE:
                        if (g_app.combat.step())
                            g_app.endCombat();
                        break;

                    case 'F':
                    case 'f':
                        g_app.playerFlee();
                        break;

                    case 'P':
                    case 'p':
                        g_app.combatQuaff();
                        break;

                    case VK_ESCAPE:
                        while (!g_app.combat.step()) {}
                        g_app.endCombat();
                        break;

                    default:
                        if (wp >= '1' && wp <= '9') {
                            int idx = (int)(wp - '1');
                            if (g_app.combat.encounter &&
                                idx < (int)g_app.combat.encounter
                                         ->monsters().size() &&
                                g_app.combat.encounter
                                        ->monsters()[idx].alive() &&
                                g_app.combat.activeMember <
                                    (int)g_app.combat
                                        .selectedTargets.size()) {
                                g_app.combat.selectedTargets
                                    [g_app.combat.activeMember] = idx;
                            }
                        }
                        break;
                }
            } else {
                switch (wp) {
                    case VK_LEFT:  case 'A': onPartyMove(-1,  0); break;
                    case VK_RIGHT: case 'D': onPartyMove( 1,  0); break;
                    case VK_UP:    case 'W': onPartyMove( 0, -1); break;
                    case VK_DOWN:  case 'S': onPartyMove( 0,  1); break;

                    case 'N':
                        if (g_app.party.alive()) {
                            // new dungeon resets depth but KEEPS career
                            g_app.dungeonLevel = 1;
                            g_app.newDungeon(g_app.seed + 1);
                        } else {
                            // wiped: roll a fresh company
                            g_app.resetToCreation();
                        }
                        break;

                    case 'E':
                        if (g_app.party.alive())
                            g_app.spawnWanderingEncounter();
                        break;

                    case 'P':
                    case 'p':
                        g_app.quaffExplore();
                        break;

                    case VK_ESCAPE:
                        PostQuitMessage(0);
                        return 0;
                }
            }
            InvalidateRect(hwnd, nullptr, FALSE);
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC wndDC = BeginPaint(hwnd, &ps);
            if (g_app.rend.memDC) {
                if (g_app.mode == MODE_CREATE) {
                    drawCreate(g_app.rend.memDC, g_app);
                } else if (g_app.mode == MODE_COMBAT) {
                    drawCombat(g_app.rend.memDC, g_app.combat);
                    drawHud(g_app.rend.memDC, g_app);
                } else {
                    drawView(g_app.rend.memDC, g_app);
                    drawHud(g_app.rend.memDC, g_app);
                }
                BitBlt(wndDC, 0, 0, WINDOW_W, WINDOW_H,
                       g_app.rend.memDC, 0, 0, SRCCOPY);
            }
            EndPaint(hwnd, &ps);
            return 0;
        }

        case WM_ERASEBKGND:
            return 1;

        case WM_DESTROY:
            g_app.rend.destroy();
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

// ----------------------------------------------------------------------------
// Entry point
// ----------------------------------------------------------------------------

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, int nCmdShow) {
    int monstersLoaded = g_app.registry.loadDirectory("monsters/monsters");
    if (monstersLoaded <= 0) {
        MessageBoxA(nullptr,
            "Could not load monsters/monsters/*.lua.\n"
            "Run the game from the project root.",
            "Adnd1", MB_OK | MB_ICONWARNING);
    }

    // R24: start at creation — the first roll is on the house
    g_app.creation.rollFresh();

    WNDCLASSW wc = {};
    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInst;
    wc.hCursor       = LoadCursorW(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName = L"Adnd1Wnd";
    RegisterClassW(&wc);

    RECT want = { 0, 0, WINDOW_W, WINDOW_H };
    AdjustWindowRect(&want, WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX), FALSE);

    HWND hwnd = CreateWindowW(
        L"Adnd1Wnd", L"Adnd1",
        WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX),
        CW_USEDEFAULT, CW_USEDEFAULT,
        want.right - want.left, want.bottom - want.top,
        nullptr, nullptr, hInst, nullptr);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return (int)msg.wParam;
}
