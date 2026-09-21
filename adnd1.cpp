// ============================================================================
// Adnd1 — a 2D tile-based CRPG implementing AD&D 1st Edition rules
// Rebuild tranche R34: per-day spell slots — casters keep a live slot
// tally that only refills on rest (new [R] rest command in explore
// mode), on descending a level, or on loading a save; interrupted
// rest (wandering encounter) restores nothing. Slot state lives in
// Character::slotsByLevel (game/party.h) and is managed by
// AppState::restoreSlots / restExplore (game/appstate.h).
// Rebuild tranche R36: throw command — in combat, [t] has the
// active member hurl their melee weapon (dagger/hand axe/spear):
// one shot from the weapon's own dice/plus, then unarmed 1d2
// fists for the rest of the encounter (recovered afterward).
// Wired to AppState::combatThrow (game/appstate.h), resolved by
// Encounter::requestThrow / resolveMissile (ai/actor.*).
// Rebuild tranche R41: town hub — [B] from the dungeon opens the
// town screen (MODE_TOWN): [1] buys a healing potion (50 gp),
// [2] buys 20 arrows (30 gp), [B]/Esc returns to the dungeon at
// the same depth. Wired to AppState::enterTown / leaveTown /
// townBuyPotion / townBuyArrows (game/appstate.h).
// Rebuild tranche R42: town services + scaling — town gains
// [3] inn (safe rest, 10 gp), [4] temple heal (100 gp), [5]
// smith (+1 long sword, 500 gp); treasure gold and lair sizes
// scale with dungeon depth. Missile range bands are NOT in this
// tranche (driver work — split out to keep this one shell-only).
// Rebuild tranche R43: training + range + stock — town gains
// [6] training hall (1500 gp x level, promotes queued level-ups),
// [7] armorer (chain mail, 75 gp), [8] scribe (spell scroll,
// 200 gp); [x] shoot in combat is refused once the range closes
// (5 rounds). Wired to AppState::townTrain / townBuyChain /
// townBuyScroll / combatShoot gate (game/appstate.h).
// Rebuild tranche R44: five features — [0] keep (name level,
// 10,000 gp; rents + half-price training), [9] identify scroll
// (100 gp) and [I] to read one over pending magic loot, [H] the
// henchman offer (100 gp; an NPC fighter joins the fights, upkeep
// on return, loyalty gates descending), six new Lua bestiary
// files, and a town status panel (roster, hire, keep, scrolls).
// Wired to AppState::townBuildStronghold / townBuyIdentify /
// useIdentifyScroll / townHireHenchman (game/appstate.h).
// R31 heritage: file split — adnd1.cpp is now the Win32/GDI
// shell only (renderer, drawing, window proc, input); the game
// simulation moved verbatim to game/ headers:
//   game/messagelog.h  — MessageLog
//   game/party.h       — Character, Party, roster constants
//   game/appstate.h    — Occupancy, Treasure, Camera, GameMode,
//                        CreationState, CombatState, AppState
// The Renderer moved out of AppState to a shell-owned global
// (g_rend) so game/ never includes windows.h. No behavior change.
// Earlier tranches R24-R30: party creation, potions, treasure XP,
// spells in combat, ranged weapons, save/load, prime-requisite
// XP adjustment — see the git history for details.
//
// Build (MinGW, Lua 5.4) — game/ headers are header-only, no new
// translation units:
//   g++ -std=c++17 -I. -Ilua/include adnd1.cpp rules/dice.cpp rules/character.cpp rules/combat.cpp rules/saves.cpp rules/turn.cpp rules/classes.cpp spells/spells.cpp spelleffects/spelleffects.cpp items/items.cpp dm/dm.cpp dm/dungeon.cpp ai/actor.cpp monsters/MonsterRegistry.cpp lua/src/liblua.a -o adnd1.exe -mwindows
// ============================================================================

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "game/appstate.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstring>

using namespace world;

// ----------------------------------------------------------------------------
// View / HUD geometry
// ----------------------------------------------------------------------------

static const int VIEW_W = TILE_W * VIEW_TILES_X;   // 800
static const int VIEW_H = TILE_H * VIEW_TILES_Y;   // 608
static const int HUD_H  = 96;
static const int WINDOW_W = VIEW_W;
static const int WINDOW_H = VIEW_H + HUD_H;

static const char* CLASS_NAMES[4] = {
    "Fighter", "Magic-User", "Cleric", "Thief"
};
static const char CLASS_INITIALS[4] = { 'F', 'M', 'C', 'T' };

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

static AppState g_app;
static Renderer g_rend;   // R31: shell-owned (was AppState::rend)

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
             "[c] spells  [x] shoot  [t] hurl  "
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

    // R27: spell menu overlay — the active member's castable list
    if (cs.spellMenuOpen && cs.encounter && !cs.over &&
        cs.activeMember >= 0 &&
        cs.activeMember < (int)cs.encounter->party().size()) {
        auto list = cs.castableSpells();
        const ai::Actor& a =
            cs.encounter->party()[cs.activeMember];

        int panelH = 60 + (int)list.size() * 24 + 10;
        RECT panel = { 140, 140, VIEW_W - 140, 140 + panelH };
        HBRUSH back = CreateSolidBrush(RGB(16, 14, 10));
        FillRect(dc, &panel, back);
        DeleteObject(back);
        HPEN pen = CreatePen(PS_SOLID, 2, RGB(200, 180, 120));
        HPEN oldPen = (HPEN)SelectObject(dc, pen);
        MoveToEx(dc, panel.left, panel.top, nullptr);
        LineTo(dc, panel.right, panel.top);
        LineTo(dc, panel.right, panel.bottom);
        LineTo(dc, panel.left, panel.bottom);
        LineTo(dc, panel.left, panel.top);
        SelectObject(dc, oldPen);
        DeleteObject(pen);

        SetTextColor(dc, RGB(230, 210, 160));
        char head[96];
        snprintf(head, sizeof head,
                 "%s — SPELLS  ([1-9] cast, [c/esc] close)",
                 a.name.c_str());
        TextOutA(dc, 156, 152, head, (int)strlen(head));

        int sy = 180;
        for (size_t i = 0; i < list.size() && i < 9; ++i) {
            const spells::SpellDef& s = spells::spell(list[i]);
            char row[96];
            snprintf(row, sizeof row,
                     "  [%d] %-20s L%d  ct%d seg  (%d slots)",
                     (int)i + 1, s.name, s.level, s.castingTime,
                     a.slotsByLevel[s.level - 1]);
            SetTextColor(dc, RGB(210, 195, 165));
            TextOutA(dc, 166, sy, row, (int)strlen(row));
            sy += 24;
        }
        if (list.empty()) {
            SetTextColor(dc, RGB(150, 140, 120));
            TextOutA(dc, 166, sy, "  (no spells available)", 23);
        }
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
                     "[R] reroll   [Enter] accept roll   [L] load save",
                     46);
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

// R41: town screen — the shops between dives
static void drawTown(HDC dc, const AppState& s) {
    RECT vr = { 0, 0, VIEW_W, VIEW_H };
    HBRUSH black = CreateSolidBrush(RGB(8, 6, 4));
    FillRect(dc, &vr, black);
    DeleteObject(black);

    SetBkColor(dc, RGB(8, 6, 4));
    SetTextColor(dc, RGB(220, 200, 160));
    char line[160];

    snprintf(line, sizeof line, "THE TOWN");
    TextOutA(dc, 20, 14, line, (int)strlen(line));

    SetTextColor(dc, RGB(200, 190, 160));
    snprintf(line, sizeof line,
             "The company rests above ground. "
             "Purse: %d gp  Potions: %d",
             s.party.gold, s.party.potions);
    TextOutA(dc, 20, 48, line, (int)strlen(line));

    SetTextColor(dc, RGB(200, 190, 160));
    snprintf(line, sizeof line, "[1] Temple — potion of healing, 50 gp");
    TextOutA(dc, 20, 96, line, (int)strlen(line));
    snprintf(line, sizeof line, "[2] Fletcher — 20 arrows, 30 gp");
    TextOutA(dc, 20, 120, line, (int)strlen(line));

    // R42: the expanded services
    snprintf(line, sizeof line, "[3] Inn — safe night's rest, 10 gp");
    TextOutA(dc, 20, 144, line, (int)strlen(line));
    snprintf(line, sizeof line, "[4] Temple — full heal (one member), 100 gp");
    TextOutA(dc, 20, 168, line, (int)strlen(line));
    snprintf(line, sizeof line, "[5] Smith — +1 long sword, 500 gp");
    TextOutA(dc, 20, 192, line, (int)strlen(line));

    // R43: training and stock
    snprintf(line, sizeof line, "[6] Training hall — next level, 1500 gp x level");
    TextOutA(dc, 20, 216, line, (int)strlen(line));
    snprintf(line, sizeof line, "[7] Armorer — chain mail, 75 gp");
    TextOutA(dc, 20, 240, line, (int)strlen(line));
    snprintf(line, sizeof line, "[8] Scribe — spell scroll, 200 gp");
    TextOutA(dc, 20, 264, line, (int)strlen(line));

    // R44: the new services
    snprintf(line, sizeof line, "[9] Scribe — identify scroll, 100 gp");
    TextOutA(dc, 20, 288, line, (int)strlen(line));
    snprintf(line, sizeof line, "[0] Masons — build a keep, 10,000 gp (name level)");
    TextOutA(dc, 20, 312, line, (int)strlen(line));
    snprintf(line, sizeof line, "[H] Crier — post a henchman offer, 100 gp");
    TextOutA(dc, 20, 336, line, (int)strlen(line));
    snprintf(line, sizeof line, "[I] Read an identify scroll");
    TextOutA(dc, 20, 360, line, (int)strlen(line));

    SetTextColor(dc, RGB(160, 150, 120));
    snprintf(line, sizeof line, "[B]/[Esc] return to the dungeon");
    TextOutA(dc, 20, 384, line, (int)strlen(line));

    // quiver summary so arrow buys are informed
    SetTextColor(dc, RGB(200, 190, 160));
    int y = 420;
    for (const auto& c : s.party.members) {
        if (!items::weapon(c.rangedWeapon.id).missile) continue;
        char nm[9];
        strncpy(nm, c.name.c_str(), 8);
        nm[8] = 0;
        snprintf(line, sizeof line, "%s — quiver %d",
                 nm, c.missileAmmo);
        TextOutA(dc, 20, y, line, (int)strlen(line));
        y += 22;
    }

    // R44: company status panel — roster, hire, keep, scrolls
    SetTextColor(dc, RGB(220, 200, 160));
    snprintf(line, sizeof line, "THE COMPANY");
    TextOutA(dc, 430, 96, line, (int)strlen(line));
    SetTextColor(dc, RGB(200, 190, 160));
    static const char* CLASS_LETTER = "FMCT";
    int sy = 120;
    for (const auto& c : s.party.members) {
        char nm[9];
        strncpy(nm, c.name.c_str(), 8);
        nm[8] = 0;
        if (c.hp <= 0) {
            snprintf(line, sizeof line, "%s  fallen", nm);
        } else {
            snprintf(line, sizeof line, "%s  %c%d  %d/%d",
                     nm, CLASS_LETTER[c.classIndex & 3],
                     c.level, c.hp, c.maxHp);
        }
        TextOutA(dc, 430, sy, line, (int)strlen(line));
        sy += 22;
    }
    if (sy < 200) sy = 200;   // clear of a short roster
    if (s.party.henchmanPresent) {
        char nm[17];
        strncpy(nm, s.party.henchmanName.c_str(), 16);
        nm[16] = 0;
        snprintf(line, sizeof line,
                 "%s (hire) F%d  %d/%d  loy %d%%",
                 nm, s.party.henchmanLevel, s.party.henchmanHp,
                 s.party.henchmanMaxHp, s.party.henchmanLoyalty);
        TextOutA(dc, 430, sy, line, (int)strlen(line));
        sy += 22;
    }
    if (s.party.strongholdBuilt &&
        s.party.strongholdOwner >= 0 &&
        s.party.strongholdOwner <
            (int)s.party.members.size()) {
        char nm[9];
        strncpy(nm,
            s.party.members[s.party.strongholdOwner]
                .name.c_str(),
            8);
        nm[8] = 0;
        snprintf(line, sizeof line, "The keep of %s stands.",
                 nm);
        TextOutA(dc, 430, sy, line, (int)strlen(line));
        sy += 22;
    }
    snprintf(line, sizeof line,
             "Identify scrolls: %d  (unidentified: %d)",
             s.party.identifyScrolls,
             (int)s.party.unidentified.size());
    TextOutA(dc, 430, sy, line, (int)strlen(line));
}

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
                 c.hp > 0 ? "" : "â ",
                 nm, CLASS_INITIALS[c.classIndex],
                 c.level, c.hp, c.maxHp);
        strcat(line, tok);
        len = strlen(line);
    }
    TextOutA(dc, 12, VIEW_H + 8, line, (int)strlen(line));

    snprintf(line, sizeof line,
             "Dungeon Lvl %d  Rooms: %d (%d lairs)  %d gp  Potions %d  "
             "Kills %d  Turn %d  Seed %llu  [P] quaff  "
             "[K] save  [L] load  [R] rest  [B] town",
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
            g_rend.resize(dc, WINDOW_W, WINDOW_H);
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
                // R29: [L] resumes a saved company from the
                // creation screen (before any dice are rolled);
                // any other key falls through to creation flow
                if (wp == 'L' || wp == 'l') {
                    g_app.loadGame();   // stays in CREATE on fail
                } else {
                    creationKeyDown(wp);
                }
                // Enter in the NAME stage confirms the member
                // (creationKeyDown only moves between stages)
                if (wp == VK_RETURN &&
                    g_app.creation.stage == CR_NAME &&
                    g_app.mode == MODE_CREATE) {
                    creationConfirmName();
                }
            } else if (g_app.mode == MODE_TOWN) {
                // R41: town keys — shops and the way back down
                switch (wp) {
                    case '1':
                        g_app.townBuyPotion();
                        break;

                    case '2':
                        g_app.townBuyArrows();
                        break;

                    // R42: the expanded services
                    case '3':
                        g_app.townInnRest();
                        break;

                    case '4':
                        g_app.townTempleHeal();
                        break;

                    case '5':
                        g_app.townBuySword();
                        break;

                    // R43: training and stock
                    case '6':
                        g_app.townTrain();
                        break;

                    case '7':
                        g_app.townBuyChain();
                        break;

                    case '8':
                        g_app.townBuyScroll();
                        break;

                    // R44: keep, scrolls, and the hire
                    case '9':
                        g_app.townBuyIdentify();
                        break;

                    case '0':
                        g_app.townBuildStronghold();
                        break;

                    case 'H':
                    case 'h':
                        g_app.townHireHenchman();
                        break;

                    case 'I':
                    case 'i':
                        g_app.useIdentifyScroll();
                        break;

                    case 'B':
                    case 'b':
                    case VK_ESCAPE:
                        g_app.leaveTown();
                        break;
                }
            } else if (g_app.mode == MODE_COMBAT) {
                // R27: while the spell menu is open it owns the keys
                if (g_app.combat.spellMenuOpen) {
                    if (wp == 'C' || wp == 'c' || wp == VK_ESCAPE) {
                        g_app.combat.spellMenuOpen = false;
                    } else if (wp >= '1' && wp <= '9') {
                        int pick = (int)(wp - '1');
                        auto list = g_app.combat.castableSpells();
                        if (pick < (int)list.size()) {
                            g_app.combat.encounter->requestCast(
                                g_app.combat.activeMember, list[pick]);
                            g_app.combat.spellMenuOpen = false;
                            g_app.log.add(
                                "Spell readied — [space] to resolve "
                                "the round.");
                        }
                    }
                } else switch (wp) {
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

                    // R28: active member fires missiles this round
                    case 'X':
                    case 'x':
                        g_app.combatShoot();
                        break;

                    // R36: active member hurls their melee weapon
                    case 'T':
                    case 't':
                        g_app.combatThrow();
                        break;

                    // R27: open the active member's spell menu
                    case 'C':
                    case 'c':
                        if (!g_app.combat.castableSpells().empty())
                            g_app.combat.spellMenuOpen = true;
                        else
                            g_app.log.add(
                                "That member cannot cast spells.");
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

                    // R34: rest — restore spell slots and heal
                    case 'R':
                    case 'r':
                        g_app.restExplore();
                        break;

                    // R41: retreat to town
                    case 'B':
                    case 'b':
                        g_app.enterTown();
                        break;

                    // R29: save the company / load a saved one
                    case 'K':
                    case 'k':
                        if (g_app.party.alive())
                            g_app.saveGame();
                        else
                            g_app.log.add(
                                "The dead leave no records.");
                        break;

                    case 'L':
                    case 'l':
                        g_app.loadGame();
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
            if (g_rend.memDC) {
                if (g_app.mode == MODE_CREATE) {
                    drawCreate(g_rend.memDC, g_app);
                } else if (g_app.mode == MODE_COMBAT) {
                    drawCombat(g_rend.memDC, g_app.combat);
                    drawHud(g_rend.memDC, g_app);
                } else if (g_app.mode == MODE_TOWN) {
                    drawTown(g_rend.memDC, g_app);
                    drawHud(g_rend.memDC, g_app);
                } else {
                    drawView(g_rend.memDC, g_app);
                    drawHud(g_rend.memDC, g_app);
                }
                BitBlt(wndDC, 0, 0, WINDOW_W, WINDOW_H,
                       g_rend.memDC, 0, 0, SRCCOPY);
            }
            EndPaint(hwnd, &ps);
            return 0;
        }

        case WM_ERASEBKGND:
            return 1;

        case WM_DESTROY:
            g_rend.destroy();
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
