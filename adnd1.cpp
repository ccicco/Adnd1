// ============================================================================
// Adnd1 — a 2D tile-based CRPG implementing AD&D 1st Edition rules
// Rebuild tranche R21: commands bite. Target selection drives who
// Rolf strikes; flee runs through the encounter driver.
//
// Build (MinGW, Lua 5.4):
//   g++ -std=c++17 -I. -Ilua/include adnd1.cpp rules/dice.cpp rules/character.cpp rules/combat.cpp rules/saves.cpp rules/turn.cpp spells/spells.cpp spelleffects/spelleffects.cpp items/items.cpp dm/dm.cpp dm/dungeon.cpp ai/actor.cpp monsters/MonsterRegistry.cpp lua/src/liblua.a -o adnd1.exe -mwindows
// ============================================================================

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "world/map.h"
#include "rules/dice.h"
#include "rules/combat.h"
#include "dm/dm.h"
#include "dm/dungeon.h"
#include "ai/actor.h"
#include "monsters/MonsterRegistry.h"
#include "items/items.h"

#include <algorithm>
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
// Party / camera
// ----------------------------------------------------------------------------

struct Party {
    int x = 0, y = 0;
    ai::Actor fighter;
    bool formed = false;

    void formDefault() {
        fighter.name = "Rolf";
        fighter.isCharacter = true;
        fighter.classIndex = 0;   // fighter
        fighter.level = 1;
        fighter.str = 14; fighter.dex = 12; fighter.con = 12;
        fighter.intel = 9; fighter.wis = 10; fighter.cha = 10;
        fighter.weapon.id = items::WPN_LONG_SWORD;
        fighter.armor.id = items::ARMOR_CHAIN_MAIL;
        fighter.shield = true;
        fighter.hp = fighter.maxHp = 9;
        fighter.morale = dm::MORALE_FANATIC;
        formed = true;
    }
    bool alive() const { return formed && fighter.alive(); }
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
    MODE_EXPLORE = 0,
    MODE_COMBAT,
};

// ----------------------------------------------------------------------------
// Combat state — interactive, with commands WIRED to the driver (R21)
// ----------------------------------------------------------------------------

struct CombatState {
    std::unique_ptr<ai::Encounter> encounter;
    int  lastResult = -1;
    bool over = false;

    int  selectedTarget = 0;    // roster index the player chose

    void start(std::vector<ai::Actor> party, std::vector<ai::Actor> foes,
               uint64_t seed) {
        encounter = std::make_unique<ai::Encounter>(
            std::move(party), std::move(foes), seed);
        lastResult = -1;
        over = false;
        selectedTarget = 0;

        // R21: the hook answers "who does the party strike?" —
        // the driver consults it every time a party actor attacks
        encounter->setPlayerTargetHook(
            [this](const ai::Actor&, const std::vector<ai::Actor>& foes) {
                if (selectedTarget >= 0 &&
                    selectedTarget < (int)foes.size() &&
                    foes[selectedTarget].alive())
                    return selectedTarget;
                // selection invalid: front-most living (driver
                // fallback handles it too, but be explicit)
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

    int cycleTarget(int dir) {
        if (!encounter) return selectedTarget;
        const auto& mons = encounter->monsters();
        int n = (int)mons.size();
        if (n == 0) return selectedTarget;
        for (int hop = 1; hop <= n; ++hop) {
            int cand = (selectedTarget + dir * hop + n * 8) % n;
            if (mons[cand].alive()) {
                selectedTarget = cand;
                break;
            }
        }
        return selectedTarget;
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

    // combat
    GameMode    mode = MODE_EXPLORE;
    CombatState combat;
    int         combatRoomIndex = -1;

    void newDungeon(uint64_t s) {
        seed = s;
        dungeon = dm::generateDungeon(s);
        map = dungeon.map;
        occupancy.init(dungeon);
        if (!party.formed) party.formDefault();
        party.x = dungeon.entryX;
        party.y = dungeon.entryY;
        cam.follow(party);
        turnCount = 0;
        rng.seed(s * 7919 + 13);

        populateRooms();

        char buf[96];
        snprintf(buf, sizeof buf,
                 "You descend... seed %llu, %d rooms, %d occupied.",
                 (unsigned long long)s, (int)dungeon.rooms.size(),
                 countOccupied());
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

        combat.start({party.fighter}, foes, rng.below(0x7FFFFFFF));
        combatRoomIndex = roomIndex;
        mode = MODE_COMBAT;
    }

    void spawnWanderingEncounter() {
        if (mode == MODE_COMBAT) return;
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

        combatRoomIndex = -1;
        combat.start({party.fighter}, foes, rng.below(0x7FFFFFFF));
        mode = MODE_COMBAT;
    }

    // R21: flee is now a request to the driver — free swings and
    // the dex check resolve inside stepRound()
    void playerFlee() {
        if (mode != MODE_COMBAT || !combat.encounter || combat.over)
            return;
        combat.requestFlee();
        combat.step();               // resolves the break-off
        if (combat.over) endCombat();
    }

    void endCombat() {
        if (combat.encounter) {
            if (!combat.encounter->party().empty())
                party.fighter = combat.encounter->party()[0];

            const char* outcome = "?";
            switch (combat.lastResult) {
                case 0: outcome = "Victory!"; break;
                case 1: outcome = "The party has fallen..."; break;
                case 2: outcome = "You fled."; break;
                case 3: outcome = "The monsters fled."; break;
                default: outcome = "The fight ends."; break;
            }
            log.add(outcome);

            if (combat.lastResult == 0 && combatRoomIndex >= 0) {
                RoomOccupant& room = occupancy.rooms[combatRoomIndex];
                if (!room.monsterKey.empty()) {
                    room.monsterKey.clear();
                    room.count = 0;
                }
            }
            if (combat.lastResult == 1) {
                log.add("GAME OVER - press N for a new dungeon.");
            }
        }
        combat.encounter.reset();
        mode = MODE_EXPLORE;
    }
};

static AppState g_app;

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

    if (!party.alive()) return;
    int ppx = (party.x - cam.x) * TILE_W + TILE_W / 2;
    int ppy = (party.y - cam.y) * TILE_H + TILE_H / 2;
    HBRUSH partyBr  = CreateSolidBrush(RGB(220, 40, 40));
    HPEN   partyPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    HPEN   oldPen = (HPEN)SelectObject(dc, partyPen);
    HBRUSH oldBr  = (HBRUSH)SelectObject(dc, partyBr);
    Ellipse(dc, ppx - 10, ppy - 10, ppx + 10, ppy + 10);
    SelectObject(dc, oldPen);
    SelectObject(dc, oldBr);
    DeleteObject(partyPen);
    DeleteObject(partyBr);
}

// ----------------------------------------------------------------------------
// Drawing: combat view — rosters with selection highlight
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
             "COMBAT!  [tab/1-9] target  [space] attack+round  "
             "[f] flee  [esc] auto-resolve");
    TextOutA(dc, 20, 14, line, (int)strlen(line));

    if (!cs.encounter) return;
    const auto& party = cs.encounter->party();
    const auto& mons  = cs.encounter->monsters();

    SetTextColor(dc, RGB(140, 210, 140));
    TextOutA(dc, 20, 48, "PARTY", 5);
    int y = 70;
    for (const auto& a : party) {
        drawCombatantRow(dc, 20, y, VIEW_W / 2 - 40, a, true, false);
        y += 26;
    }

    SetTextColor(dc, RGB(230, 130, 110));
    TextOutA(dc, VIEW_W / 2 + 20, 48, "MONSTERS", 8);
    y = 70;
    for (size_t i = 0; i < mons.size(); ++i) {
        bool sel = ((int)i == cs.selectedTarget) && mons[i].alive();
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

static void drawHud(HDC dc, const AppState& s) {
    const Party& party = s.party;
    RECT hr = { 0, VIEW_H, WINDOW_W, WINDOW_H };
    HBRUSH panel = CreateSolidBrush(RGB(25, 22, 18));
    FillRect(dc, &hr, panel);
    DeleteObject(panel);

    SetBkColor(dc, RGB(25, 22, 18));
    SetTextColor(dc, RGB(200, 190, 160));

    char line[192];
    snprintf(line, sizeof line,
             "Rolf HP %d/%d   Turn: %d   Seed: %llu   Rooms: %d (%d lairs)   Lvl %d",
             party.fighter.hp, party.fighter.maxHp, s.turnCount,
             (unsigned long long)s.seed,
             (int)s.dungeon.rooms.size(), s.countOccupied(),
             s.dungeonLevel);
    TextOutA(dc, 12, VIEW_H + 8, line, (int)strlen(line));

    snprintf(line, sizeof line,
             "[arrows/WASD] move  [N] new dungeon  [E] wander encounter  "
             "[F] plant wight  [esc] quit");
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

        case WM_KEYDOWN:
            if (g_app.mode == MODE_COMBAT) {
                // ---- combat keys (R21: all wired to the driver) ----
                switch (wp) {
                    case VK_TAB:
                        g_app.combat.cycleTarget(
                            (GetKeyState(VK_SHIFT) & 0x8000) ? -1 : 1);
                        break;

                    case VK_SPACE:
                        // attack the selected target + advance round
                        if (g_app.combat.step())
                            g_app.endCombat();
                        break;

                    case 'F':
                    case 'f':
                        g_app.playerFlee();
                        break;

                    case VK_ESCAPE:
                        while (!g_app.combat.step()) {}
                        g_app.endCombat();
                        break;

                    default:
                        // number keys 1-9 select targets directly
                        if (wp >= '1' && wp <= '9') {
                            int idx = (int)(wp - '1');
                            if (g_app.combat.encounter &&
                                idx < (int)g_app.combat.encounter
                                         ->monsters().size() &&
                                g_app.combat.encounter
                                        ->monsters()[idx].alive()) {
                                g_app.combat.selectedTarget = idx;
                            }
                        }
                        break;
                }
            } else {
                // ---- explore keys ----
                switch (wp) {
                    case VK_LEFT:  case 'A': onPartyMove(-1,  0); break;
                    case VK_RIGHT: case 'D': onPartyMove( 1,  0); break;
                    case VK_UP:    case 'W': onPartyMove( 0, -1); break;
                    case VK_DOWN:  case 'S': onPartyMove( 0,  1); break;

                    case 'N':
                        g_app.newDungeon(g_app.seed + 1);
                        break;

                    case 'E':
                        if (g_app.party.alive())
                            g_app.spawnWanderingEncounter();
                        break;

                    case 'F': {  // plant a wight in the nearest room
                        if (!g_app.party.alive()) break;
                        int best = -1;
                        long bestDist = -1;
                        for (auto& room : g_app.occupancy.rooms) {
                            if (!room.monsterKey.empty()) continue;
                            long dx = room.denX - g_app.party.x;
                            long dy = room.denY - g_app.party.y;
                            long dist = dx * dx + dy * dy;
                            if (bestDist < 0 || dist < bestDist) {
                                bestDist = dist;
                                best = room.roomIndex;
                            }
                        }
                        if (best >= 0) {
                            g_app.occupancy.rooms[best].monsterKey = "wight";
                            g_app.occupancy.rooms[best].count = 1;
                            g_app.log.add("A cold presence settles nearby...");
                        }
                        break;
                    }

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
                if (g_app.mode == MODE_COMBAT) {
                    drawCombat(g_app.rend.memDC, g_app.combat);
                } else {
                    drawView(g_app.rend.memDC, g_app);
                }
                drawHud(g_app.rend.memDC, g_app);
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

    g_app.newDungeon(1);

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
