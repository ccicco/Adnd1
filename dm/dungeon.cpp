// ============================================================================
// Adnd1 — dm/dungeon.cpp
// The walking generator: start at an entry, follow Appendix A passage
// tables, carve rooms, place doors. Deterministic per seed.
// ============================================================================

#include "dungeon.h"

#include <cstring>

namespace dm {

using rules::Dice;
using rules::Rng;

namespace {

struct GenState {
    Rng  rng;
    Dice dice;
    world::Map map;
    std::vector<GeneratedRoom> rooms;
    int carved = 0;          // tiles carved this run
    int tileBudget;
    int maxRooms;

    GenState(uint64_t seed, int budget, int maxR)
        : rng(seed), dice(rng), tileBudget(budget), maxRooms(maxR) {
        std::memset(&map, 0, sizeof(map));
    }

    bool overBudget() const { return carved >= tileBudget; }

    // carve a corridor tile (only over void; keep floors)
    void carveCorr(int x, int y) {
        if (!map.inBounds(x, y)) return;
        if (map.tiles[y][x] == TILE_VOID) {
            map.tiles[y][x] = world::TILE_CORR;
            ++carved;
        }
    }

    void setDoor(int x, int y) {
        if (map.inBounds(x, y)) map.tiles[y][x] = world::TILE_DOOR;
    }

    bool carveRoom(int x, int y, int w, int h) {
        // interior must be in-bounds and (mostly) virgin rock
        if (x < 2 || y < 2 || x + w > world::MAP_TILES_X - 2 ||
            y + h > world::MAP_TILES_Y - 2)
            return false;
        int overlap = 0;
        for (int yy = y; yy < y + h; ++yy)
            for (int xx = x; xx < x + w; ++xx)
                if (map.tiles[yy][xx] != world::TILE_VOID) ++overlap;
        // allow slight corridor kiss, reject mostly-used rects
        if (overlap * 4 > w * h) return false;
        if (carved + w * h > tileBudget) return false;

        for (int yy = y; yy < y + h; ++yy)
            for (int xx = x; xx < x + w; ++xx)
                if (map.tiles[yy][xx] == world::TILE_VOID) {
                    map.tiles[yy][xx] = world::TILE_FLOOR;
                    ++carved;
                }

        // surrounding wall ring (walls where rock remains)
        for (int xx = x - 1; xx <= x + w; ++xx) {
            if (map.tiles[y - 1][xx] == world::TILE_VOID)
                map.tiles[y - 1][xx] = world::TILE_WALL;
            if (map.tiles[y + h][xx] == world::TILE_VOID)
                map.tiles[y + h][xx] = world::TILE_WALL;
        }
        for (int yy = y - 1; yy <= y + h; ++yy) {
            if (map.tiles[yy][x - 1] == world::TILE_VOID)
                map.tiles[yy][x - 1] = world::TILE_WALL;
            if (map.tiles[yy][x + w] == world::TILE_VOID)
                map.tiles[yy][x + w] = world::TILE_WALL;
        }
        return true;
    }

    // Walk one passage in direction (dx,dy) from (x,y). Returns the
    // position where the passage feature was rolled. Carves as it
    // goes, width from the table.
    void walkPassage(int& x, int& y, int dx, int dy) {
        int width = rollPassageWidth(dice);
        // march until a feature, an edge approach, or budget
        int steps = 0;
        while (steps < 60) {
            // near edges: stop walking
            if (x + dx * 3 < 2 || x + dx * 3 > world::MAP_TILES_X - 3 ||
                y + dy * 3 < 2 || y + dy * 3 > world::MAP_TILES_Y - 3)
                break;

            // advance one tile
            x += dx; y += dy; ++steps;
            carveCorridorRow(x, y, dx, dy, width);

            if (overBudget()) return;

            // roll a feature every few tiles (Appendix A rolls at
            // intervals; simplified cadence — 1-in-3 per tile)
            if (steps >= 3 && (int)dice.d6() <= 2) {
                PassageFeature f = rollPassageFeature(dice);
                switch (f) {
                    case PASSAGE_STRAIGHT:
                        break;   // keep walking
                    case PASSAGE_TURN: {
                        int t = rollTurnDirection(dice);
                        if (dx != 0) { dy = t;  dx = 0; }
                        else         { dx = t;  dy = 0; }
                        return;   // caller continues in new direction
                    }
                    case PASSAGE_T_JUNCTION: {
                        // carve a short side stub, keep going straight
                        int t = rollTurnDirection(dice);
                        int sx = x, sy = y;
                        int sdx = (dx != 0) ? 0 : t;
                        int sdy = (dy != 0) ? 0 : t;
                        for (int i = 0; i < 4; ++i) {
                            sx += sdx; sy += sdy;
                            if (overBudget()) break;
                            carveCorridorRow(sx, sy, sdx, sdy, 1);
                        }
                        break;
                    }
                    case PASSAGE_CROSS:
                        break;   // treated as straight for now
                    case PASSAGE_CHAMBER:
                        tryRoom(x, y);
                        return;
                    case PASSAGE_DEAD_END:
                        // maybe a door at the end
                        if ((int)dice.d6() <= 3)
                            setDoor(x + dx, y + dy);
                        return;
                    default:
                        break;
                }
            }
        }
        // ran out of steps or hit edge: dead end
    }

    // carve a width-wide corridor row through (x,y) along (dx,dy)
    void carveCorridorRow(int x, int y, int dx, int dy, int width) {
        carveCorr(x, y);
        for (int i = 1; i < width; ++i) {
            if (dx != 0) carveCorr(x, y + (dy >= 0 ? i : -i) * (dx != 0 ? 1 : 1));
            if (dy != 0) carveCorr(x + i, y);
        }
    }

    void tryRoom(int x, int y) {
        if ((int)rooms.size() >= maxRooms) return;
        int w, h;
        rollRoomSize(dice, w, h);
        // center-ish the room on the passage end
        int rx = x - w / 2;
        int ry = y - h / 2;
        if (!carveRoom(rx, ry, w, h)) {
            // try shifted placements before giving up
            if (!carveRoom(rx + 2, ry, w, h) &&
                !carveRoom(rx - 2, ry, w, h) &&
                !carveRoom(rx, ry + 2, w, h))
                return;
        }
        // connect: door between passage head and room interior
        setDoor(x, y);
        GeneratedRoom r;
        r.x = rx; r.y = ry; r.w = w; r.h = h;
        r.contents = rollRoomContents(dice);
        rooms.push_back(r);
    }
};

} // namespace

DungeonResult generateDungeon(uint64_t seed, int tileBudget, int maxRooms) {
    if (maxRooms <= 0) maxRooms = 12;
    GenState g(seed, tileBudget, maxRooms);

    // entry near the center
    int ex = world::MAP_TILES_X / 2 + (int)(g.rng.below(8)) - 4;
    int ey = world::MAP_TILES_Y / 2 + (int)(g.rng.below(8)) - 4;
    g.carveCorr(ex, ey);

    DungeonResult res;
    res.entryX = ex;
    res.entryY = ey;

    // walk several passages from entry in table-chosen directions
    const int kDirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    int passages = 3 + (int)(g.rng.below(3));   // 3-5 main passages
    for (int p = 0; p < passages && !g.overBudget(); ++p) {
        int d = (int)(g.rng.below(4));
        int x = ex, y = ey;
        int dx = kDirs[d][0], dy = kDirs[d][1];
        // walk with turn continuations: each walkPassage return with a
        // turn direction swaps it; chamber/dead-end ends the passage
        for (int hop = 0; hop < 6; ++hop) {
            int px = x, py = y;
            g.walkPassage(x, y, dx, dy);
            // walkPassage may have rotated (dx,dy is local) — detect
            // continuation by proximity: if we stopped near a turn,
            // re-roll direction. Simplified: continue in a new table
            // direction from where we ended.
            if (g.overBudget()) break;
            (void)px; (void)py;
            int nd = (int)(g.rng.below(4));
            dx = kDirs[nd][0]; dy = kDirs[nd][1];
        }
    }

    // ensure at least one room exists: force one near entry if empty
    if (g.rooms.empty()) {
        int w, h;
        rollRoomSize(g.dice, w, h);
        g.carveRoom(ex + 2, ey + 2, w, h);
        GeneratedRoom r;
        r.x = ex + 2; r.y = ey + 2; r.w = w; r.h = h;
        r.contents = rollRoomContents(g.dice);
        g.rooms.push_back(r);
        // connect
        for (int i = 1; i <= 2; ++i) g.carveCorr(ex + i, ey);
        g.setDoor(ex + 1, ey);
    }

    res.map = g.map;
    res.rooms = g.rooms;
    return res;
}

} // namespace dm