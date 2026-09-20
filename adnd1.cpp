// ============================================================================
// Adnd1 — a 2D tile-based CRPG implementing AD&D 1st Edition rules
// Rebuild tranche R10: the game plays a generated dungeon.
//
//   - Win32 window + message pump, GDI double-buffered rendering
//   - world/map.h shared tile map, dm/dungeon.cpp Appendix A generator
//   - Party spawns at the dungeon entry; 'N' regenerates (dev)
//   - Wandering monster check per move (message log only, no combat yet)
//   - HUD: seed, room count, turn count
//
// Build (MinGW):  g++ -std=c++17 -I. adnd1.cpp rules/dice.cpp dm/dm.cpp dm/dungeon.cpp -o adnd1.exe -mwindows
// Build (MSVC):   cl /std:c++17 /I. adnd1.cpp rules/dice.cpp dm/dm.cpp dm/dungeon.cpp user32.lib gdi32.lib
// ============================================================================

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "world/map.h"
#include "rules/dice.h"
#include "dm/dm.h"
#include "dm/dungeon.h"

#include <cstdint>
#include <cstdio>
#include <cstring>
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
// Message log (last few lines shown in the HUD)
// ----------------------------------------------------------------------------

struct MessageLog {
    static const int MAX_LINES = 4;
    std::string lines[MAX_LINES];
    int head = 0;   // index of oldest

    void add(const std::string& s) {
        lines[head] = s;
        head = (head + 1) % MAX_LINES;
    }
    // line i counting from newest (0 = most recent)
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
// Party / camera
// ----------------------------------------------------------------------------

struct Party {
    int x = 0, y = 0;   // tile position of the party-as-unit
    // 1e HOOK: party roster (created core + henchmen hybrid model).
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
// Drawing
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

static void drawView(HDC dc, const Map& map, const Camera& cam, const Party& party) {
    RECT vr = { 0, 0, VIEW_W, VIEW_H };
    HBRUSH black = CreateSolidBrush(RGB(0, 0, 0));
    FillRect(dc, &vr, black);
    DeleteObject(black);

    for (int ty = 0; ty < VIEW_TILES_Y; ++ty)
        for (int tx = 0; tx < VIEW_TILES_X; ++tx)
            drawTile(dc, tx * TILE_W, ty * TILE_H, map.at(cam.x + tx, cam.y + ty));

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

static void drawHud(HDC dc, const Party& party, int turnCount,
                    uint64_t seed, int roomCount, const MessageLog& log) {
    RECT hr = { 0, VIEW_H, WINDOW_W, WINDOW_H };
    HBRUSH panel = CreateSolidBrush(RGB(25, 22, 18));
    FillRect(dc, &hr, panel);
    DeleteObject(panel);

    SetBkColor(dc, RGB(25, 22, 18));
    SetTextColor(dc, RGB(200, 190, 160));

    char line[160];
    snprintf(line, sizeof line,
             "Party: (%d, %d)   Turn: %d   Seed: %llu   Rooms: %d",
             party.x, party.y, turnCount,
             (unsigned long long)seed, roomCount);
    TextOutA(dc, 12, VIEW_H + 8, line, (int)strlen(line));

    snprintf(line, sizeof line,
             "[arrows/WASD] move   [N] new dungeon   [esc] quit");
    TextOutA(dc, 12, VIEW_H + 32, line, (int)strlen(line));

    // message log: most recent two lines
    SetTextColor(dc, RGB(160, 150, 120));
    TextOutA(dc, 12, VIEW_H + 56, log.get(1).c_str(), (int)log.get(1).size());
    SetTextColor(dc, RGB(230, 220, 180));
    TextOutA(dc, 12, VIEW_H + 76, log.get(0).c_str(), (int)log.get(0).size());
}

// ----------------------------------------------------------------------------
// App state
// ----------------------------------------------------------------------------

struct AppState {
    Map           map;
    Party         party;
    Camera        cam;
    Renderer      rend;
    MessageLog    log;
    int           turnCount = 0;
    uint64_t      seed = 1;
    int           roomCount = 0;
    rules::Rng    rng{1};
    rules::Dice   dice{rng};
    dm::WanderConfig wander;

    void newDungeon(uint64_t s) {
        seed = s;
        dm::DungeonResult d = dm::generateDungeon(s);
        map = d.map;
        roomCount = (int)d.rooms.size();
        party.x = d.entryX;
        party.y = d.entryY;
        cam.follow(party);
        turnCount = 0;
        char buf[96];
        snprintf(buf, sizeof buf,
                 "You descend... seed %llu, %d rooms.",
                 (unsigned long long)s, roomCount);
        log.add(buf);
    }
};

static AppState g_app;

// Party movement: 1 turn of dungeon time per move; wandering monster
// check per turn (DMG p.61).
static void onPartyMove(int dx, int dy) {
    AppState& s = g_app;
    int nx = s.party.x + dx;
    int ny = s.party.y + dy;
    if (!s.map.walkable(nx, ny)) return;
    s.party.x = nx;
    s.party.y = ny;
    s.cam.follow(s.party);
    ++s.turnCount;

    if (dm::wanderCheck(s.dice, s.wander)) {
        int dist = dm::wanderDistance(s.dice);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "You hear movement in the distance... (%d ft)", dist);
        s.log.add(buf);
        // 1e HOOK: spawn the actual encounter once the monsters layer
        // exists (Appendix C table by dungeon level, then encounter AI).
    }
}

// ----------------------------------------------------------------------------
// Window procedure + message pump
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
            switch (wp) {
                case VK_LEFT:  case 'A': onPartyMove(-1,  0); break;
                case VK_RIGHT: case 'D': onPartyMove( 1,  0); break;
                case VK_UP:    case 'W': onPartyMove( 0, -1); break;
                case VK_DOWN:  case 'S': onPartyMove( 0,  1); break;
                case 'N': g_app.newDungeon(g_app.seed + 1); break;
                case VK_ESCAPE: PostQuitMessage(0); return 0;
            }
            InvalidateRect(hwnd, nullptr, FALSE);
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC wndDC = BeginPaint(hwnd, &ps);
            if (g_app.rend.memDC) {
                drawView(g_app.rend.memDC, g_app.map, g_app.cam, g_app.party);
                drawHud (g_app.rend.memDC, g_app.party, g_app.turnCount,
                         g_app.seed, g_app.roomCount, g_app.log);
                BitBlt(wndDC, 0, 0, WINDOW_W, WINDOW_H,
                       g_app.rend.memDC, 0, 0, SRCCOPY);
            }
            EndPaint(hwnd, &ps);
            return 0;
        }

        case WM_ERASEBKGND:
            return 1;

        case WM_APP_STEP:
            // 1e HOOK: segment scheduler events in combat.
            return 0;

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
    g_app.newDungeon(1);   // fixed dev seed; new-game options later

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
}static const int   WINDOW_W         = VIEW_W;
static const int   WINDOW_H         = VIEW_H + HUD_H;

static const int   WM_APP_STEP      = WM_APP + 1;  // dungeon-time step tick

// ----------------------------------------------------------------------------
// Tile types (0 = void/rock, 1 = floor, 2 = wall, 3 = door, 4 = corridor)
// ----------------------------------------------------------------------------

enum Tile : uint8_t {
    TILE_VOID     = 0,
    TILE_FLOOR    = 1,
    TILE_WALL     = 2,
    TILE_DOOR     = 3,
    TILE_CORR     = 4,
};

struct Map {
    uint8_t tiles[MAP_TILES_Y][MAP_TILES_X];

    bool inBounds(int x, int y) const {
        return x >= 0 && x < MAP_TILES_X && y >= 0 && y < MAP_TILES_Y;
    }
    uint8_t at(int x, int y) const {
        return inBounds(x, y) ? tiles[y][x] : TILE_VOID;
    }
    bool walkable(int x, int y) const {
        uint8_t t = at(x, y);
        return t == TILE_FLOOR || t == TILE_CORR || t == TILE_DOOR;
    }
};

// ----------------------------------------------------------------------------
// Test map: a few rooms joined by corridors. Real generation arrives with the
// dm/ layer (DMG Appendix A random dungeon generation, p.170-172).
// ----------------------------------------------------------------------------

static Map makeTestMap() {
    Map m = {};
    // Room 1: 4,4 to 14,10
    for (int y = 4; y <= 10; ++y)
        for (int x = 4; x <= 14; ++x)
            m.tiles[y][x] = TILE_FLOOR;
    // Room 2: 24,20 to 38,30
    for (int y = 20; y <= 30; ++y)
        for (int x = 24; x <= 38; ++x)
            m.tiles[y][x] = TILE_FLOOR;
    // Room 3: 50,8 to 58,14
    for (int y = 8; y <= 14; ++y)
        for (int x = 50; x <= 58; ++x)
            m.tiles[y][x] = TILE_FLOOR;
    // Corridor A: room1 -> room2 (vertical at x=9)
    for (int y = 10; y <= 20; ++y) {
        m.tiles[y][9] = TILE_CORR;
        m.tiles[y][10] = TILE_CORR;
    }
    // Corridor B: room2 -> room3 (horizontal at y=25)
    for (int x = 38; x <= 50; ++x) {
        m.tiles[25][x] = TILE_CORR;
        m.tiles[26][x] = TILE_CORR;
    }
    // Doors at corridor junctions
    m.tiles[20][9]  = TILE_DOOR;
    m.tiles[25][38] = TILE_DOOR;
    m.tiles[25][50] = TILE_DOOR;
    return m;
}

// ----------------------------------------------------------------------------
// Party / camera
//
// Party-as-unit movement for exploration (splittable groups arrive later);
// per-character orders belong to the combat domain.
// ----------------------------------------------------------------------------

struct Party {
    int x = 6, y = 7;      // tile position of the party-as-unit
    // 1e HOOK: party roster (created core + henchmen hybrid model),
    // party size as configuration (default 6, 1e module convention).
};

struct Camera {
    int x = 0, y = 0;      // top-left tile of the viewport

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
// Rendering — GDI, double-buffered
// ----------------------------------------------------------------------------

struct Renderer {
    HWND    hwnd  = nullptr;
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
    // tile grid hint
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

static void drawView(HDC dc, const Map& map, const Camera& cam, const Party& party) {
    // viewport background
    RECT vr = { 0, 0, VIEW_W, VIEW_H };
    HBRUSH black = CreateSolidBrush(RGB(0, 0, 0));
    FillRect(dc, &vr, black);
    DeleteObject(black);

    for (int ty = 0; ty < VIEW_TILES_Y; ++ty) {
        for (int tx = 0; tx < VIEW_TILES_X; ++tx) {
            drawTile(dc, tx * TILE_W, ty * TILE_H, map.at(cam.x + tx, cam.y + ty));
        }
    }
    // party marker (center-biased; drawn at party position relative to camera)
    int ppx = (party.x - cam.x) * TILE_W + TILE_W / 2;
    int ppy = (party.y - cam.y) * TILE_H + TILE_H / 2;
    HBRUSH partyBr = CreateSolidBrush(RGB(220, 40, 40));
    HPEN   partyPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    HPEN   oldPen = (HPEN)SelectObject(dc, partyPen);
    HBRUSH oldBr  = (HBRUSH)SelectObject(dc, partyBr);
    Ellipse(dc, ppx - 10, ppy - 10, ppx + 10, ppy + 10);
    SelectObject(dc, oldPen);
    SelectObject(dc, oldBr);
    DeleteObject(partyPen);
    DeleteObject(partyBr);
}

static void drawHud(HDC dc, const Party& party, int turnCount) {
    RECT hr = { 0, VIEW_H, WINDOW_W, WINDOW_H };
    HBRUSH panel = CreateSolidBrush(RGB(25, 22, 18));
    FillRect(dc, &hr, panel);
    DeleteObject(panel);

    SetBkColor(dc, RGB(25, 22, 18));
    SetTextColor(dc, RGB(200, 190, 160));

    char line[128];
    // 1e HOOK: party roster line (name, class/level, hp/ac, spell slots).
    // 1e HOOK: dungeon-time display (turn count); time is action-driven,
    //          never a wall clock — player deliberation never advances it.
    snprintf(line, sizeof line, "Party: (%d, %d)   Turn: %d", party.x, party.y, turnCount);
    TextOutA(dc, 12, VIEW_H + 8, line, (int)strlen(line));

    snprintf(line, sizeof line, "[arrows/WASD] move   [esc] quit");
    TextOutA(dc, 12, VIEW_H + 32, line, (int)strlen(line));

    // 1e HOOK: message log area (event feed for AI-attributed decisions).
    snprintf(line, sizeof line, "Adnd1 rebuild R1 — skeleton online");
    TextOutA(dc, 12, VIEW_H + 56, line, (int)strlen(line));
}

// ----------------------------------------------------------------------------
// App state
// ----------------------------------------------------------------------------

struct AppState {
    Map      map;
    Party    party;
    Camera   cam;
    Renderer rend;
    int      turnCount = 0;   // dungeon turns; each party move = 1 turn
};

static AppState g_app;

// 1e HOOK: this is where wandering monster checks (DMG p.61, Appendix C)
// hook in — one check per turn of dungeon time, dm/ layer decides WHEN.
static void onPartyMove(int dx, int dy) {
    AppState& s = g_app;
    int nx = s.party.x + dx;
    int ny = s.party.y + dy;
    if (!s.map.walkable(nx, ny)) return;
    s.party.x = nx;
    s.party.y = ny;
    s.cam.follow(s.party);
    ++s.turnCount;   // dungeon time is action-driven
}

// ----------------------------------------------------------------------------
// Window procedure + message pump
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
            switch (wp) {
                case VK_LEFT:  case 'A': onPartyMove(-1,  0); break;
                case VK_RIGHT: case 'D': onPartyMove( 1,  0); break;
                case VK_UP:    case 'W': onPartyMove( 0, -1); break;
                case VK_DOWN:  case 'S': onPartyMove( 0,  1); break;
                case VK_ESCAPE: PostQuitMessage(0); return 0;
            }
            InvalidateRect(hwnd, nullptr, FALSE);
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC wndDC = BeginPaint(hwnd, &ps);
            if (g_app.rend.memDC) {
                drawView(g_app.rend.memDC, g_app.map, g_app.cam, g_app.party);
                drawHud (g_app.rend.memDC, g_app.party, g_app.turnCount);
                BitBlt(wndDC, 0, 0, WINDOW_W, WINDOW_H,
                       g_app.rend.memDC, 0, 0, SRCCOPY);
            }
            EndPaint(hwnd, &ps);
            return 0;
        }

        case WM_ERASEBKGND:
            return 1;   // avoid flicker; we paint the whole client area

        case WM_APP_STEP:
            // 1e HOOK: dungeon-time scheduler — noise and alarms schedule
            // future-turn events here (turn/ segment scheduler).
            return 0;

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
    g_app.map  = makeTestMap();
    g_app.cam.follow(g_app.party);

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

// Allow console builds (main) for quick smoke tests on non-Windows CI where
// the file is only compiled for syntax by the simulator harness.
#ifndef _WIN32
int main() { return 0; }
#endif
