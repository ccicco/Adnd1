#!/usr/bin/env python3
# R123 splice: OUTDOOR MOVEMENT (DMG pp.58-59).
# The book's daily movement rates, in
# miles/day. WIRED: the afoot table
# (light/average/heavy burden x normal/
# rugged/very-rugged terrain: 30/20/10,
# 20/10/5, 10/5/2) - the company marches
# at its slowest walker's pace (the book's
# burden classes from the true loads, the
# hire at his fixed kit), each march day
# logs its true miles and tracks
# milesOut; the coaster sails the book's
# small-merchant sea rate (the book's
# printed 50 miles/day) and tracks her
# miles from port.
# PINNED AS DATA (no mounts or other
# vessels in play yet): the mounted table
# (light 60/25/5, medium 40/20/5, heavy
# 30/15/5, draft 30/15/5, cart 25/15/
# road-only, wagon 25/10/road-only - the
# book's dash is 0) and both afloat
# tables (oared and sailed, 8 vessels x 5
# waters; the sailed bands keep lo/hi).
# Burden thresholds are the book's
# absolute lbs of gear (<=25 / 26-60 /
# 61-90, beyond stays heavy); the
# strength/race adjustment lives in the
# dungeon encumbrance bands (PHB p.76) -
# documented split. Terrain classes map
# the 8 route terrains: plains/scrub/
# desert normal, forest/rough/hills
# rugged, mountains/marsh very rugged
# (documented campaign mapping).
# New header-only dm/outdoormove.h (the
# battery reads the tables with no
# build-list changes); companyFootMilesPerDay
# joins party.h; OverlandState/SeaState
# gain milesOut (transient - travel state
# is never saved); overlandTravel/
# Homeward and seaTravel/Homeward log
# the day's miles. The book's d4
# long-voyage reduction applies to
# voyages of weeks, which the day
# cadence does not model - documented.
# Battery census becomes 41. Idempotent
# (marker checks per patch): run twice -
# the second run must print every patch
# already applied. ASCII-only. Refuses
# non-unique anchors, all-or-nothing.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii") as f:
        f.write(text)


def replace_exact(text, old, new, label):
    n = text.count(old)
    if n != 1:
        print("REFUSED " + label + ": anchor not unique or missing (count %d)" % n)
        return text, False
    return text.replace(old, new, 1), True


# ---- patch bodies ----------------------------------------------------------

HDR_TEXT = """// ============================================================================
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

#pragma once

#include "encounters.h"   // dm::OutdoorTerrain

namespace dm {

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
    static const int k[FB_COUNT][TC_COUNT] = {
        { 30, 20, 10 },   // light
        { 20, 10,  5 },   // average
        { 10,  5,  2 },   // heavy
    };
    return k[b][tc];
}

// MOVEMENT MOUNTED IN MILES/DAY (p.58-59) - pinned data;
// carts and wagons are road/track/open-terrain only (the
// book's dash prints as 0)
enum MountKind {
    MOUNT_LIGHT = 0, MOUNT_MEDIUM, MOUNT_HEAVY, MOUNT_DRAFT,
    MOUNT_CART, MOUNT_WAGON, MOUNT_COUNT
};

inline int mountedMilesPerDay(MountKind m, TerrainClass tc) {
    static const int k[MOUNT_COUNT][TC_COUNT] = {
        { 60, 25,  5 },   // light
        { 40, 20,  5 },   // medium
        { 30, 15,  5 },   // heavy
        { 30, 15,  5 },   // draft
        { 25, 15,  0 },   // cart*
        { 25, 10,  0 },   // wagon*
    };
    return k[m][tc];
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
    static const int k[VESSEL_COUNT][WATER_COUNT] = {
        { 15,  5, 15,  0, 10 },   // raft
        { 30, 15, 35,  0, 25 },   // boat, small
        { 20,  5, 20,  0,  0 },   // barge
        { 40,  5, 40, 30,  0 },   // galley, small
        { 30,  0, 30, 30,  0 },   // galley, large
        { 10,  0, 15, 20,  0 },   // merchant, small
        { 10,  0, 10, 15,  0 },   // merchant, large
        { 10,  0, 10, 20,  0 },   // warship
    };
    return k[v][w];
}

// the sailed table prints bands for the larger vessels
// (galley small 70-80 at lake, etc.); lo/hi are the band's
// bounds, equal where the book prints one number
inline int sailedMilesLo(VesselKind v, WaterKind w) {
    static const int k[VESSEL_COUNT][WATER_COUNT] = {
        { 30, 10, 30,  0, 15 },   // raft
        { 80, 20, 60,  0, 40 },   // boat, small
        { 50, 10, 40,  0,  0 },   // barge
        { 70,  0, 60, 50,  0 },   // galley, small
        { 50,  0, 50, 50,  0 },   // galley, large
        { 50,  0, 50, 50,  0 },   // merchant, small
        { 25,  0, 35, 35,  0 },   // merchant, large
        { 40,  0, 40, 50,  0 },   // warship
    };
    return k[v][w];
}

inline int sailedMilesHi(VesselKind v, WaterKind w) {
    static const int k[VESSEL_COUNT][WATER_COUNT] = {
        { 30, 10, 30,  0, 15 },
        { 80, 20, 60,  0, 40 },
        { 50, 10, 40,  0,  0 },
        { 80,  0, 60, 50,  0 },
        { 60,  0, 50, 50,  0 },
        { 60,  0, 50, 50,  0 },
        { 35,  0, 35, 35,  0 },
        { 50,  0, 40, 50,  0 },
    };
    return k[v][w];
}

} // namespace dm
"""

PI_OLD = '#include "../dm/dm.h"'

PI_NEW = """#include "../dm/dm.h"
#include "../dm/outdoormove.h"   // R123: pp.58-59 daily rates"""

PH_OLD = """inline int memberLoad(const Party& p, const Character& c) {
    return carriedWeight(c) + coinWeightShare(p);
}"""

PH_NEW = """inline int memberLoad(const Party& p, const Character& c) {
    return carriedWeight(c) + coinWeightShare(p);
}

// R123: the company's afoot miles/day (DMG pp.58-59) - the
// slowest walker sets the pace: each living member's book
// burden class comes from his true load (kit, cargo, coin
// share), the hire's from his fixed kit. 0 when nobody
// walks (an empty or fallen company - the callers guard)
inline int companyFootMilesPerDay(const Party& p,
                                  dm::TerrainClass tc) {
    int worst = 0;
    for (const auto& c : p.members) {
        if (c.hp <= 0) continue;   // the fallen are carried
        int m = dm::footMilesPerDay(
            dm::footBurdenFor(memberLoad(p, c)), tc);
        if (worst == 0 || m < worst) worst = m;
    }
    if (p.henchmanPresent) {
        int m = dm::footMilesPerDay(
            dm::footBurdenFor(henchmanCarryWeight(p)), tc);
        if (worst == 0 || m < worst) worst = m;
    }
    return worst;
}"""

OL_OLD = """struct OverlandState {
    int           day = 0;        // days on the trail
    int           daysOut = 0;    // 0 = in town; 1+ = leagues out
    bool          homeward = false;"""

OL_NEW = """struct OverlandState {
    int           day = 0;        // days on the trail
    int           daysOut = 0;    // 0 = in town; 1+ = days afield
    int           milesOut = 0;   // R123: true miles from town
    bool          homeward = false;"""

SS_OLD = """struct SeaState {
    int day = 0;        // days on the water
    int daysOut = 0;    // 0 = in port; 1+ = at sea
    bool homeward = false;
};"""

SS_NEW = """struct SeaState {
    int day = 0;        // days on the water
    int daysOut = 0;    // 0 = in port; 1+ = at sea
    int milesOut = 0;   // R123: true miles from port
    bool homeward = false;
};"""

OD_OLD = """    // [T] - a day's march outward
    void overlandTravel();"""

OD_NEW = """    // R123: the day's true miles (DMG pp.58-59 afoot table -
    // the slowest walker's pace, the route's terrain class)
    int overlandMilesPerDay() const;

    // [T] - a day's march outward
    void overlandTravel();"""

SD_OLD = """    // [T] - a day's sail outward
    void seaTravel();"""

SD_NEW = """    // R123: the day's true miles at sea (DMG pp.58-59
    // sailed table - the coaster's small-merchant sea
    // rate, the book's printed 50; rolled lo..hi so a
    // banded vessel would work too)
    int seaMilesPerDay();

    // [T] - a day's sail outward
    void seaTravel();"""

OM_OLD = """dm::OutdoorClime AppState::overlandClime() const{
        return overlandInhabited()
            ? dm::OC_TEMPERATE_INHABITED   // p.182: inhabited set
            : dm::OC_TEMPERATE_WILD;       // p.182: wilderness set
    }

// ---- overlandStep ----"""

OM_NEW = """dm::OutdoorClime AppState::overlandClime() const{
        return overlandInhabited()
            ? dm::OC_TEMPERATE_INHABITED   // p.182: inhabited set
            : dm::OC_TEMPERATE_WILD;       // p.182: wilderness set
}

// ---- overlandMilesPerDay ----
// R123: the DMG pp.58-59 afoot rate - the company moves at
// the slowest walker's pace (the true loads decide the book's
// burden classes; the terrain class is the route's)
int AppState::overlandMilesPerDay() const{
        if (mode != MODE_OVERLAND) return 0;
        return companyFootMilesPerDay(
            party, dm::terrainClass(
                       (dm::OutdoorTerrain)overland.terrain));
    }

// ---- overlandStep ----"""

OT_OLD = """        overland.homeward = false;
        ++overland.day;
        ++overland.daysOut;
        ++party.careerDays;   // R95: the trail counts
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d - the %s.",
                 overland.day, overlandTerrainName(overland.terrain));
        log.add(buf);"""

OT_NEW = """        overland.homeward = false;
        ++overland.day;
        ++overland.daysOut;
        ++party.careerDays;   // R95: the trail counts
        int miles = overlandMilesPerDay();   // R123: p.58-59
        overland.milesOut += miles;
        char buf[112];
        snprintf(buf, sizeof buf,
                 "Day %d - the %s. The company covers %d "
                 "miles (%d from town).",
                 overland.day,
                 overlandTerrainName(overland.terrain),
                 miles, overland.milesOut);
        log.add(buf);"""

OH_OLD = """        overland.homeward = true;
        ++overland.day;
        --overland.daysOut;
        ++party.careerDays;   // R95: the trail counts
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d - the road home, the %s.",
                 overland.day, overlandTerrainName(overland.terrain));
        log.add(buf);"""

OH_NEW = """        overland.homeward = true;
        ++overland.day;
        --overland.daysOut;
        ++party.careerDays;   // R95: the trail counts
        int miles = overlandMilesPerDay();   // R123: p.58-59
        overland.milesOut -= miles;
        if (overland.milesOut < 0) overland.milesOut = 0;
        char buf[112];
        snprintf(buf, sizeof buf,
                 "Day %d - the road home, the %s. The company "
                 "covers %d miles (%d from town).",
                 overland.day,
                 overlandTerrainName(overland.terrain),
                 miles, overland.milesOut);
        log.add(buf);"""

SM_OLD = """dm::WaterDepth AppState::seaDepth() const{
        return (sea.daysOut < kSeaCoastalDays)
            ? dm::WaterDepth::SHALLOW : dm::WaterDepth::DEEP;
    }

// ---- seaStep ----"""

SM_NEW = """dm::WaterDepth AppState::seaDepth() const{
        return (sea.daysOut < kSeaCoastalDays)
            ? dm::WaterDepth::SHALLOW : dm::WaterDepth::DEEP;
}

// ---- seaMilesPerDay ----
// R123: the DMG pp.58-59 sailed table - the coaster is a
// small merchant; her sea column prints one number, 50
// miles/day (the 50-60 band is the lake column). The roll
// stays generic lo..hi so a banded vessel would work too;
// the book's d4 long-voyage reduction applies to voyages
// of weeks, which this day cadence does not model -
// documented
int AppState::seaMilesPerDay(){
        int lo = dm::sailedMilesLo(dm::VESSEL_MERCHANT_SMALL,
                                   dm::WATER_SEA);
        int hi = dm::sailedMilesHi(dm::VESSEL_MERCHANT_SMALL,
                                   dm::WATER_SEA);
        return (int)dice.roll(1, hi - lo + 1, lo - 1);
    }

// ---- seaStep ----"""

ST_OLD = """        sea.homeward = false;
        ++sea.day;
        ++sea.daysOut;
        ++party.careerDays;   // R95: the sea counts
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d at sea - the %s.",
                 sea.day,
                 sea.daysOut < kSeaCoastalDays
                     ? "coastal waters" : "open sea");
        log.add(buf);"""

ST_NEW = """        sea.homeward = false;
        ++sea.day;
        ++sea.daysOut;
        ++party.careerDays;   // R95: the sea counts
        int miles = seaMilesPerDay();   // R123: 50
        sea.milesOut += miles;
        char buf[112];
        snprintf(buf, sizeof buf,
                 "Day %d at sea - the %s. The coaster runs "
                 "%d miles (%d from port).",
                 sea.day,
                 sea.daysOut < kSeaCoastalDays
                     ? "coastal waters" : "open sea",
                 miles, sea.milesOut);
        log.add(buf);"""

SH_OLD = """        sea.homeward = true;
        ++sea.day;
        --sea.daysOut;
        ++party.careerDays;   // R95: the sea road counts
        char buf[96];
        snprintf(buf, sizeof buf, "Day %d - the sea road home.",
                 sea.day);
        log.add(buf);"""

SH_NEW = """        sea.homeward = true;
        ++sea.day;
        --sea.daysOut;
        ++party.careerDays;   // R95: the sea road counts
        int miles = seaMilesPerDay();   // R123: 50
        sea.milesOut -= miles;
        if (sea.milesOut < 0) sea.milesOut = 0;
        char buf[112];
        snprintf(buf, sizeof buf,
                 "Day %d - the sea road home. The coaster "
                 "logs %d miles (%d from port).",
                 sea.day, miles, sea.milesOut);
        log.add(buf);"""

RI_OLD = '#include "dm/encounters.h"'

RI_NEW = """#include "dm/encounters.h"
#include "dm/outdoormove.h"   // R123: pp.58-59 daily rates"""

RT_OLD = """        printf("R122 treasure line-diff audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

RT_NEW = """        printf("R122 treasure line-diff audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R123: outdoor movement audit ---------------------------------
    // The DMG pp.58-59 daily rates, pinned: the afoot table
    // (burden x terrain class, all nine cells), the burden
    // thresholds, the route-terrain mapping, the mounted and
    // afloat tables, and the company pace (the slowest
    // walker's rate from the true loads, the hire at his
    // kit, the fallen skipped).
    {
        int bad = 0;
        // the afoot table, all nine cells
        static const int kFoot[3][3] = {
            { 30, 20, 10 }, { 20, 10, 5 }, { 10, 5, 2 } };
        for (int b = 0; b < 3; ++b)
            for (int t = 0; t < 3; ++t)
                if (dm::footMilesPerDay(
                        (dm::FootBurden)b, (dm::TerrainClass)t)
                    != kFoot[b][t]) ++bad;
        // the burden thresholds (p.58-59)
        if (dm::footBurdenFor(0)  != dm::FB_LIGHT)   ++bad;
        if (dm::footBurdenFor(25) != dm::FB_LIGHT)   ++bad;
        if (dm::footBurdenFor(26) != dm::FB_AVERAGE) ++bad;
        if (dm::footBurdenFor(60) != dm::FB_AVERAGE) ++bad;
        if (dm::footBurdenFor(61) != dm::FB_HEAVY)   ++bad;
        if (dm::footBurdenFor(90) != dm::FB_HEAVY)   ++bad;
        if (dm::footBurdenFor(91) != dm::FB_HEAVY)   ++bad;
        // the route-terrain mapping (the 8 routes)
        if (dm::terrainClass(dm::T_PLAIN) != dm::TC_NORMAL) ++bad;
        if (dm::terrainClass(dm::T_SCRUB) != dm::TC_NORMAL) ++bad;
        if (dm::terrainClass(dm::T_DESERT) != dm::TC_NORMAL) ++bad;
        if (dm::terrainClass(dm::T_FOREST) != dm::TC_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_ROUGH) != dm::TC_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_HILLS) != dm::TC_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_MOUNTAINS)
            != dm::TC_VERY_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_MARSH)
            != dm::TC_VERY_RUGGED) ++bad;
        // mounted (p.58-59): the four mounts and the
        // road-only carts (the book's dash is 0)
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_NORMAL) != 60) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_RUGGED) != 25) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_VERY_RUGGED) != 5) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_MEDIUM, dm::TC_NORMAL) != 40) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_HEAVY, dm::TC_NORMAL) != 30) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_DRAFT, dm::TC_RUGGED) != 15) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_CART, dm::TC_NORMAL) != 25) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_CART, dm::TC_VERY_RUGGED) != 0) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_WAGON, dm::TC_RUGGED) != 10) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_WAGON, dm::TC_VERY_RUGGED) != 0) ++bad;
        // afloat, oared: raft, boat, galley, merchant, warship
        if (dm::oaredMilesPerDay(
                dm::VESSEL_RAFT, dm::WATER_LAKE) != 15) ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_RAFT, dm::WATER_SEA) != 0) ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_BOAT_SMALL, dm::WATER_RIVER) != 35)
            ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_GALLEY_SMALL, dm::WATER_SEA) != 30)
            ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_SEA) != 20)
            ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_WARSHIP, dm::WATER_SEA) != 20) ++bad;
        // afloat, sailed: the coaster's sea rate, the lake
        // bands, and the printed ranges (equal lo/hi where
        // the book prints one number)
        if (dm::sailedMilesLo(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_SEA) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_SEA) != 50)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_LAKE) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_LAKE) != 60)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_BOAT_SMALL, dm::WATER_LAKE) != 80 ||
            dm::sailedMilesHi(
                dm::VESSEL_BOAT_SMALL, dm::WATER_LAKE) != 80)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_GALLEY_SMALL, dm::WATER_LAKE) != 70 ||
            dm::sailedMilesHi(
                dm::VESSEL_GALLEY_SMALL, dm::WATER_LAKE) != 80)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_GALLEY_LARGE, dm::WATER_LAKE) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_GALLEY_LARGE, dm::WATER_LAKE) != 60)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_MERCHANT_LARGE,
                dm::WATER_LAKE) != 25 ||
            dm::sailedMilesHi(
                dm::VESSEL_MERCHANT_LARGE,
                dm::WATER_LAKE) != 35) ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_WARSHIP, dm::WATER_SEA) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_WARSHIP, dm::WATER_SEA) != 50) ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_WARSHIP, dm::WATER_LAKE) != 40 ||
            dm::sailedMilesHi(
                dm::VESSEL_WARSHIP, dm::WATER_LAKE) != 50) ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_RAFT, dm::WATER_SEA) != 0) ++bad;
        // the company pace: the slowest walker sets it, the
        // fallen are skipped, the hire counts at his kit
        {
            Party p;
            Character a; a.hp = 10; a.name = "Strider";
            p.members.push_back(a);
            if (companyFootMilesPerDay(p, dm::TC_NORMAL) != 30)
                ++bad;
            if (companyFootMilesPerDay(p, dm::TC_VERY_RUGGED)
                != 10) ++bad;
            Character b; b.hp = 10; b.name = "Plate";
            b.armor.id = items::ARMOR_PLATE;
            p.members.push_back(b);   // 450 gp wt: heavy
            if (companyFootMilesPerDay(p, dm::TC_NORMAL) != 10)
                ++bad;
            if (companyFootMilesPerDay(p, dm::TC_RUGGED) != 5)
                ++bad;
            p.members[1].hp = 0;   // the laden one falls
            if (companyFootMilesPerDay(p, dm::TC_NORMAL) != 30)
                ++bad;
            Party q;
            q.henchmanPresent = true;   // 625 gp wt: heavy
            if (companyFootMilesPerDay(q, dm::TC_NORMAL) != 10)
                ++bad;
            if (companyFootMilesPerDay(q, dm::TC_VERY_RUGGED)
                != 2) ++bad;
        }
        printf("R123 outdoor movement audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

GH_OLD = """R122 CLOSED the treasure line-diff
(pp.120-125) - every implemented table
diffed row-by-row against the book:
383 rows, dice bands, xp and gp values,
bundle quantities, no divergence. The
tables are now pinned, not just rolled."""

GH_NEW = """R122 CLOSED the treasure line-diff
(pp.120-125) - every implemented table
diffed row-by-row against the book:
383 rows, dice bands, xp and gp values,
bundle quantities, no divergence. The
tables are now pinned, not just rolled.
R123 CLOSED outdoor movement (pp.58-59)
- the daily rates wired: afoot by
burden and terrain (the company at its
slowest walker's pace, true miles
tracked and logged), the coaster on
the book's sailed sea rate (50/day),
the mounted and afloat tables pinned
as data. Census 41."""

GB_OLD = """- [ ] **Outdoor movement (p.58-59)** - daily
      movement rates by terrain."""

GB_NEW = """- [x] **Outdoor movement (p.58-59)** - CLOSED
      R123: the book's daily rates wired -
      the afoot table (light/average/heavy
      burden x normal/rugged/very-rugged
      terrain: 30/20/10, 20/10/5, 10/5/2
      miles/day) with the burden classes
      from the true loads (<=25 / 26-60 /
      61-90 lbs of gear; the strength/race
      adjustment lives in the dungeon bands,
      PHB p.76 - documented), the terrain
      classes mapped to the 8 routes
      (plains/scrub/desert normal,
      forest/rough/hills rugged,
      mountains/marsh very rugged), and the
      company pace = the slowest walker
      (hire included, the fallen skipped);
      each march day logs its true miles and
      tracks milesOut. The coaster sails
      the book's small-merchant sea rate
      (50 miles/day - the 50-60 band is
      the lake column; the roll stays
      generic lo..hi). The mounted
      table (60/25/5, 40/20/5, 30/15/5,
      draft 30/15/5, cart 25/15 and wagon
      25/10 road-only) and both afloat
      tables (oared and sailed, 8 vessels x
      5 waters) are pinned as data - no
      mounts or other vessels are in play
      yet. The d4 long-voyage reduction is
      a weeks-scale rule this day cadence
      does not model - documented. Pinned
      by the R123 battery audit."""


# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("dm/outdoormove.h", "NEWFILE", "", HDR_TEXT,
     "dm/outdoormove.h the pp.58-59 tables"),
    ("game/party.h", '#include "../dm/outdoormove.h"',
     PI_OLD, PI_NEW, "party.h outdoormove include"),
    ("game/party.h", "inline int companyFootMilesPerDay(const Party& p,",
     PH_OLD, PH_NEW, "party.h company pace helper"),
    ("game/appstate.h", "int           milesOut = 0;   // R123: true miles from town",
     OL_OLD, OL_NEW, "appstate.h OverlandState milesOut"),
    ("game/appstate.h", "int milesOut = 0;   // R123: true miles from port",
     SS_OLD, SS_NEW, "appstate.h SeaState milesOut"),
    ("game/appstate.h", "int overlandMilesPerDay() const;",
     OD_OLD, OD_NEW, "appstate.h overland miles decl"),
    ("game/appstate.h", "int seaMilesPerDay();",
     SD_OLD, SD_NEW, "appstate.h sea miles decl"),
    ("game/state_overland.cpp", "int AppState::overlandMilesPerDay() const{",
     OM_OLD, OM_NEW, "state_overland miles helper"),
    ("game/state_overland.cpp", "The company covers %d ",
     OT_OLD, OT_NEW, "state_overland travel miles"),
    ("game/state_overland.cpp", "the road home, the %s. The company ",
     OH_OLD, OH_NEW, "state_overland homeward miles"),
    ("game/state_sea.cpp", "int AppState::seaMilesPerDay(){",
     SM_OLD, SM_NEW, "state_sea miles helper"),
    ("game/state_sea.cpp", "The coaster runs ",
     ST_OLD, ST_NEW, "state_sea travel miles"),
    ("game/state_sea.cpp", "logs %d miles (%d from port).",
     SH_OLD, SH_NEW, "state_sea homeward miles"),
    ("regtest.cpp", '#include "dm/outdoormove.h"',
     RI_OLD, RI_NEW, "regtest outdoormove include"),
    ("regtest.cpp", "R123 outdoor movement audit",
     RT_OLD, RT_NEW, "regtest R123 audit"),
    ("tools/dmg_gap_report.md", "R123 CLOSED outdoor movement",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "R123: the book's daily rates wired -",
     GB_OLD, GB_NEW, "gap report outdoor movement box"),
]


def main():
    # all-or-nothing: compute every patch, write only if
    # every patch applied or was already applied
    texts = {}
    newfiles = []
    applied = 0
    already = 0
    failed = []
    for rel, marker, old, new, label in PATCHES:
        if marker == "NEWFILE":
            if os.path.exists(os.path.join(ROOT, rel)):
                print("already applied: " + label)
                already += 1
            else:
                newfiles.append((rel, new))
                applied += 1
            continue
        if rel not in texts:
            texts[rel] = read(rel)
        t = texts[rel]
        if marker in t:
            print("already applied: " + label)
            already += 1
        else:
            t2, did = replace_exact(t, old, new, label)
            if not did:
                failed.append(label)
            else:
                texts[rel] = t2
                applied += 1
    if failed:
        print("R123 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel, text in newfiles:
        write(rel, text)
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R123 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R123 splice: nothing to do (already applied)")
    else:
        print("R123 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
