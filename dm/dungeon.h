// ============================================================================
// Adnd1 — dm/dungeon.h
// Walking dungeon generator on the Appendix A tables (dm/dm.h R8).
// Deterministic per seed. Produces a world::Map plus a room list with
// contents tags for the later monster/treasure placement layers.
// ============================================================================

#pragma once

#include "dm.h"
#include "../world/map.h"

#include <vector>

namespace dm {

// A generated room: interior floor rect + contents tag.
struct GeneratedRoom {
    int x = 0, y = 0;         // interior top-left (tile coords)
    int w = 0, h = 0;         // interior size in tiles
    RoomContents contents = ROOM_EMPTY;
};

struct DungeonResult {
    world::Map map;
    std::vector<GeneratedRoom> rooms;
    int entryX = 0, entryY = 0;   // first carved tile (stair location)
};

// Generate a dungeon level. seed drives every roll (deterministic).
// tileBudget caps total carved tiles (passage + room interiors) so
// maps never overflow the 64x64 grid regardless of table luck.
// maxRooms caps room count; 0 = default (12).
DungeonResult generateDungeon(uint64_t seed,
                              int tileBudget = 1400,
                              int maxRooms = 12);

} // namespace dm