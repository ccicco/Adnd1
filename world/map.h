// ============================================================================
// Adnd1 — world/map.h
// Shared map types, extracted from adnd1.cpp (R9 refactor; behavior
// unchanged — adnd1.cpp now includes this header).
// ============================================================================

#pragma once

#include <cstdint>

namespace world {

static const int MAP_TILES_X = 64;   // maps 64x64
static const int MAP_TILES_Y = 64;
static const int TILE_W      = 32;   // tile size, pixels
static const int TILE_H      = 32;
static const int VIEW_TILES_X = 25;  // viewport 25x19 tiles
static const int VIEW_TILES_Y = 19;

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
    void set(int x, int y, uint8_t t) {
        if (inBounds(x, y)) tiles[y][x] = t;
    }
    bool walkable(int x, int y) const {
        uint8_t t = at(x, y);
        return t == TILE_FLOOR || t == TILE_CORR || t == TILE_DOOR;
    }
};

} // namespace world