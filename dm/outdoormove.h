// ============================================================================
// Adnd1 - dm/outdoormove.h
// R123: DMG pp.58-59 OUTDOOR MOVEMENT - the daily movement
// rates in miles/day: afoot (burden x terrain class), mounted
// (pinned data - no mounts in play yet), and afloat (oared and
// sailed; the repo's coaster is a small merchant, her sailed
// sea rate the book's printed 50 the wired consumer).
//
// Burden classes are the book's absolute lbs of gear (p.58-59:
// light <=25, average 26-60, heavy 61-90; beyond 90 stays
// heavy - the book's "adjust all weight assumptions by
// strength and race factors" lives in the dungeon encumbrance
// bands, PHB p.76, items::encumbranceBand; documented split).
//
// Terrain classes (p.58-59): normal = open ground, scrub,
// typical desert, light forest, low hills; rugged = rough
// ground, snow, forests, steep hills, large watercourses;
// very rugged = broken ground, deep snow and ice, heavy
// forests, marshy ground, bogs, bluffs, mountains, broad
// watercourses. The 8 route terrains map: plains, scrub and
// desert normal; forest, rough and hills rugged; mountains
// and marsh very rugged (documented campaign mapping - which
// ground is impassable stays the DM's, as the book says).
//
// Header-only (inline) so the battery reads the tables with
// no build-list changes. Deterministic: any dice use is the
// caller's.
// ============================================================================

// R1050 applied
#pragma once

#include "encounters.h"   // dm::OutdoorTerrain
#include "items/MiscItemRegistry.h"

namespace dm {

// -------------------------------------------------
// the R1050 dm movement registry seam
//
// One registry behind the movement
// reads: content/tables/dm_movement/
// (the five grids). The per-tag grid
// views build on first use - every
// accessor signature and every enum
// stays as the print reads it.
// DO NOT hand-edit:
// tools/r1050_splice.py is the
// only writer.
inline items::MiscItemRegistry&
dmMoveReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/dm_movement");
    }
    return reg;
}

inline const int* dmMoveGrid(
        const char* tag) {
    struct GridCache {
        std::map<std::string,
            std::vector<int>> grids;
    };
    static GridCache cache;
    static bool built = false;
    if (!built) {
        built = true;
        for (const auto& kv :
                 dmMoveReg().all()) {
            const items::
                MiscItemDef* d =
                dmMoveReg().find(
                    kv.first);
            if (!d
                || d->tables.empty()
                || d->tables[0].name
                    != "grid")
                continue;
            cache.grids[kv.first]
                .assign(
                    d->tables[0]
                        .values.begin(),
                    d->tables[0]
                        .values.end());
        }
    }
    auto it = cache.grids.find(tag);
    return it == cache.grids.end()
        ? 0 : it->second.data();
}

enum TerrainClass {
    TC_NORMAL = 0, TC_RUGGED, TC_VERY_RUGGED, TC_COUNT
};

// the route terrains -> the book's terrain classes
inline TerrainClass terrainClass(OutdoorTerrain t) {
    switch (t) {
        case T_PLAIN:
        case T_SCRUB:
        case T_DESERT:   return TC_NORMAL;
        case T_FOREST:
        case T_ROUGH:
        case T_HILLS:    return TC_RUGGED;
        case T_MOUNTAINS:
        case T_MARSH:    return TC_VERY_RUGGED;
    }
    return TC_NORMAL;
}

// the book's burden classes (lbs of gear, p.58-59)
enum FootBurden {
    FB_LIGHT = 0, FB_AVERAGE, FB_HEAVY, FB_COUNT
};

inline FootBurden footBurdenFor(int lbs) {
    if (lbs <= 25) return FB_LIGHT;
    if (lbs <= 60) return FB_AVERAGE;
    return FB_HEAVY;
}

// MOVEMENT AFOOT IN MILES/DAY (p.58-59)
inline int footMilesPerDay(FootBurden b, TerrainClass tc) {
    const int* g = dmMoveGrid("dm_move_foot");
    return g ? g[(int)b * 3 + (int)tc]
               : 0;
}

// MOVEMENT MOUNTED IN MILES/DAY (p.58-59) - pinned data;
// carts and wagons are road/track/open-terrain only (the
// book's dash prints as 0)
enum MountKind {
    MOUNT_LIGHT = 0, MOUNT_MEDIUM, MOUNT_HEAVY, MOUNT_DRAFT,
    MOUNT_CART, MOUNT_WAGON, MOUNT_COUNT
};

inline int mountedMilesPerDay(MountKind m, TerrainClass tc) {
    const int* g = dmMoveGrid("dm_move_mounted");
    return g ? g[(int)m * 3 + (int)tc]
               : 0;
}

// MOVEMENT AFLOAT (p.58-59), oared/sculled and sailed. 0 =
// the book's dash (that water does not carry the vessel).
enum VesselKind {
    VESSEL_RAFT = 0, VESSEL_BOAT_SMALL, VESSEL_BARGE,
    VESSEL_GALLEY_SMALL, VESSEL_GALLEY_LARGE,
    VESSEL_MERCHANT_SMALL, VESSEL_MERCHANT_LARGE,
    VESSEL_WARSHIP, VESSEL_COUNT
};

enum WaterKind {
    WATER_LAKE = 0, WATER_MARSH, WATER_RIVER,
    WATER_SEA, WATER_STREAM, WATER_COUNT
};

inline int oaredMilesPerDay(VesselKind v, WaterKind w) {
    const int* g = dmMoveGrid("dm_move_oared");
    return g ? g[(int)v * 5 + (int)w]
               : 0;
}

// the sailed table prints bands for the larger vessels
// (galley small 70-80 at lake, etc.); lo/hi are the band's
// bounds, equal where the book prints one number
inline int sailedMilesLo(VesselKind v, WaterKind w) {
    const int* g = dmMoveGrid("dm_move_sail_lo");
    return g ? g[(int)v * 5 + (int)w]
               : 0;
}

inline int sailedMilesHi(VesselKind v, WaterKind w) {
    const int* g = dmMoveGrid("dm_move_sail_hi");
    return g ? g[(int)v * 5 + (int)w]
               : 0;
}

// ----------------------------------------------------------------------------
// BECOMING LOST (p.49) - the overland navigation check, keyed to
// the same 8 route terrains. The chance is X in 10, rolled prior
// to the commencement of a day of movement; the direction of
// lost travel is read from the dice clockwise, the intended
// direction of travel as 12 o clock - the book prints NO
// chance of the party ever accidentally moving in the desired
// direction when lost, so the mapping never returns 0.
// Deterministic: any dice use is the callers.
// ----------------------------------------------------------------------------

// the printed direction limitation per terrain
enum DirectionLimit {
    DL_60 = 0,    // 60 degrees left or right
    DL_120,       // 120 degrees left or right (mountains)
    DL_ANY,       // any direction (forest, marsh)
    DL_COUNT
};

inline DirectionLimit directionLimitFor(OutdoorTerrain t) {
    switch (t) {
        case T_FOREST:
        case T_MARSH:     return DL_ANY;
        case T_MOUNTAINS: return DL_120;
        default:          return DL_60;
    }
}

// the printed chance in 10 of becoming lost (p.49)
inline int lostChanceIn10(OutdoorTerrain t) {
    switch (t) {
        case T_PLAIN:     return 1;
        case T_SCRUB:     return 3;
        case T_FOREST:    return 7;
        case T_ROUGH:     return 3;
        case T_DESERT:    return 4;
        case T_HILLS:     return 2;
        case T_MOUNTAINS: return 5;
        case T_MARSH:     return 6;
    }
    return 0;
}

// The heading error in degrees: negative = left of the
// intended direction, positive = right. d6a and d6b are
// d6 rolls, clamped 1-6 (the house fold discipline).
//   - DL_60:  d6a alone, 1-3 = 60 left, 4-6 = 60 right.
//   - DL_120: d6a picks the side, d6b the arc (1-3 = 60,
//     4-6 = 120).
//   - DL_ANY: d6a alone, read clockwise: 1 = right
//     ahead, 2 = right behind, 3-4 = directly behind,
//     5 = left behind, 6 = left ahead.
inline int lostAngleDeg(int d6a, int d6b, DirectionLimit dl) {
    if (d6a < 1) d6a = 1;
    if (d6a > 6) d6a = 6;
    if (d6b < 1) d6b = 1;
    if (d6b > 6) d6b = 6;
    if (dl == DL_60) return (d6a <= 3) ? -60 : 60;
    if (dl == DL_120) {
        int arc = (d6b <= 3) ? 60 : 120;
        return (d6a <= 3) ? -arc : arc;
    }
    if (d6a == 1) return 60;    // right ahead
    if (d6a == 2) return 120;   // right behind
    if (d6a <= 4) return 180;   // directly behind (3-4)
    if (d6a == 5) return -120;  // left behind
    return -60;                 // left ahead
}

} // namespace dm
