#!/usr/bin/env python3
# tools/r142_splice.py - R142 the sample dungeon round: the
# DMG's own sample delve (pp.94-96, the MONASTERY CELLARS &
# SECRET CRYPTS) walks as pure data - three keyed rooms, the
# book's two d4 wandering tables, and the keyed texts.
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/sampledungeon.h: NEW header-only pure data + builder
#    (kSampleSeed, buildSampleDungeon, sampleWandering,
#    sampleRoomText)
#  - game/appstate.h: the include
#  - game/state_core.cpp: newDungeon builds the keyed map at
#    the sample seed; the delve log names it
#  - game/state_dungeon.cpp: populateRooms stands the keyed
#    rooms down from generated dressing; the entry chamber
#    lairs the book's large spider; awardVictory pays the
#    book's own hoards (skull garnet + yellow mold sack)
#  - game/state_town.cpp: describeRoom speaks the keyed text
#  - game/state_combat.cpp: the wander roll uses the book's
#    halls table
#  - adnd1.cpp: the M key in the delve summons the sample
#  - regtest.cpp: the R142 sample dungeon audit (census 60)
#  - tools/dmg_gap_report.md: the R142 box
# This file contains ZERO backslash characters (the
# R133b lesson); the audit printf assembles its
# escaped newline from chr(92).
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BS = chr(92)   # one backslash
NL = chr(10)   # one newline
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

def newfile(p, text, tag):
    full = os.path.join(ROOT, p)
    if os.path.exists(full):
        already.append(tag)
        return
    with open(full, "w", encoding="ascii") as f:
        f.write(text)
    applied.append(tag)

sampledungeon_h = NL.join([
"// ============================================================================",
"// Adnd1 - dm/sampledungeon.h",
"// R142: DMG pp.94-96 - the SAMPLE DUNGEON (the MONASTERY",
"// CELLARS & SECRET CRYPTS), the book's own teaching delve:",
"// three keyed rooms and two d4 wandering tables, pinned",
"// as pure data (the appendixgh.h pattern: inline accessors,",
"// no dice - the caller rolls). The book keys rooms 1-3 in",
"// detail, then says only '4. (Etc.)' - so the crypts behind",
"// the seventh knob, the crypt wandering column, and the",
"// crypt-cleric row ride the future-crypts debt: data now,",
"// delve later.",
"// ============================================================================",
"",
"#pragma once",
"",
'#include "dungeon.h"',
"#include <cstdint>",
"#include <vector>",
"",
"namespace dm {",
"namespace sampledungeon {",
"",
"// The seed that summons the keyed delve. Any other seed",
"// (including the default new-dungeon seed 1) walks the",
"// generated dungeon exactly as before.",
"const uint64_t kSampleSeed = 0x53414D50ULL;   // 'SAMP'",
"",
"// One wandering-table row: a monster key and its count",
"// range. Both of the book's tables are a single d4.",
"struct SampleWanderingRow {",
"    const char* key;",
"    int lo;",
"    int hi;",
"};",
"",
"// The book's two d4 wandering columns (p.96). crypt=false:",
"// the monastery halls; crypt=true: the crypt column (data",
"// for the future crypts - nothing wires it yet). Crypt row",
"// two is '1 third-level evil cleric and 2 hobgoblins': the",
"// cleric needs a spell-caster encounter hook and rides",
"// the debt; the row carries the hobgoblins.",
"inline SampleWanderingRow sampleWandering(bool crypt,",
"                                          int roll) {",
"    static const SampleWanderingRow halls[4] = {",
'        { "goblin",      3, 12 },',
'        { "bandit",      2,  5 },',
'        { "giant_rat",   7, 12 },',
'        { "fire_beetle", 1,  2 },',
"    };",
"    static const SampleWanderingRow crypts[4] = {",
'        { "ghoul",       1,  2 },',
'        { "hobgoblin",   2,  2 },',
'        { "giant_rat",   7, 12 },',
'        { "skeleton",    2,  5 },',
"    };",
"    if (roll < 1) roll = 1;",
"    if (roll > 4) roll = 4;",
"    return crypt ? crypts[roll - 1] : halls[roll - 1];",
"}",
"",
"// The keyed room texts (room 1-3 of the book = indices",
"// 0-2 here). Pure ASCII, pure data; the engine logs them",
"// as the first-sight flavor of the keyed rooms.",
"inline const char* sampleRoomText(int i) {",
"    static const char* texts[3] = {",
'        "Cobwebs curtain this 30 foot square entry '
'chamber; a goblin skull sits against the wall and ten '
'rotting sacks slump nearby. When the wind gusts through '
'the old oak door, it groans - and any torch flame '
'gutters low.",',
'        "A stream slips north to south through this '
'chamber, feeding a limed-over pool. Beside the water '
'rests a skeleton in abbot robes, one hand folded around '
'a curious key - and an ivory tube lies half in the '
'stream, its vellum map water-ruined save for the first '
'few chambers.",',
'        "A dome some 25 feet across crowns this '
'ceremonial chamber. A 9 foot platform rises at the far '
'end, seven stone knobs set above empty socket holes - '
'the seventh, the book says, opens the south crypt '
'door."',
"    };",
"    if (i < 0) i = 0;",
"    if (i > 2) i = 2;",
"    return texts[i];",
"}",
"",
"// Build the keyed delve: three chambers joined by a",
"// straight passage. Room 0 is the book's exact 30 foot",
"// square entry chamber (3x3 tiles at 10 feet); rooms 1-2",
"// follow the text's shape at the engine's conventions",
"// (the book gives no tile measures for them). The entry",
"// stair lands at the chamber's center; the oak door of",
"// the text is the door tile at its east jamb.",
"inline DungeonResult buildSampleDungeon() {",
"    DungeonResult res;",
"    world::Map& m = res.map;",
"    for (int y = 0; y < world::MAP_TILES_Y; ++y)",
"        for (int x = 0; x < world::MAP_TILES_X; ++x)",
"            m.set(x, y, world::TILE_VOID);",
"",
"    GeneratedRoom r0;   // the entry chamber, 30 square",
"    r0.x = 30; r0.y = 30; r0.w = 3; r0.h = 3;",
"    GeneratedRoom r1;   // the water room (convention)",
"    r1.x = 38; r1.y = 28; r1.w = 4; r1.h = 5;",
"    GeneratedRoom r2;   // the ceremonial dome",
"    r2.x = 46; r2.y = 30; r2.w = 4; r2.h = 4;",
"",
"    const GeneratedRoom* rs[3] = { &r0, &r1, &r2 };",
"    for (int i = 0; i < 3; ++i) {",
"        const GeneratedRoom& r = *rs[i];",
"        for (int yy = 0; yy < r.h; ++yy)",
"            for (int xx = 0; xx < r.w; ++xx)",
"                m.set(r.x + xx, r.y + yy, world::TILE_FLOOR);",
"    }",
"    // the joining passage along the chambers mid-line,",
"    // with the book oak doors at the first two jambs",
"    for (int x = 33; x <= 45; ++x) {",
"        int t = (x == 33 || x == 42) ? world::TILE_DOOR",
"                                    : world::TILE_CORR;",
"        m.set(x, 31, t);",
"    }",
"",
"    res.rooms.push_back(r0);",
"    res.rooms.push_back(r1);",
"    res.rooms.push_back(r2);",
"    res.entryX = 31;   // the chamber center",
"    res.entryY = 31;",
"    return res;",
"}",
"",
"} // namespace sampledungeon",
"} // namespace dm",
"",
])
newfile("dm/sampledungeon.h", sampledungeon_h,
        "sampledungeon.h: new header")

patch("game/appstate.h",
"""#include "../dm/appendixgh.h"  // R125: pp.216-217 trap/trick lists
""",
"""#include "../dm/appendixgh.h"  // R125: pp.216-217 trap/trick lists
#include "../dm/sampledungeon.h"  // R142: pp.94-96 the DMG sample dungeon
""",
      "appstate.h: sampledungeon include",
      marker="dm/sampledungeon.h")

patch("game/state_core.cpp",
"""        seed = s;
        dungeon = dm::generateDungeon(s);
        map = dungeon.map;
""",
"""        seed = s;
        // R142: the sample dungeon - the DMG's own keyed
        // delve (pp.94-96, the MONASTERY CELLARS). Any
        // other seed walks the generated dungeon as before.
        if (s == dm::sampledungeon::kSampleSeed) {
            dungeon = dm::sampledungeon::buildSampleDungeon();
        } else {
            dungeon = dm::generateDungeon(s);
        }
        map = dungeon.map;
""",
      "state_core.cpp: newDungeon sample branch",
      marker="if (s == dm::sampledungeon::kSampleSeed) {")

patch("game/state_core.cpp",
"""                 dungeonLevel, (int)dungeon.rooms.size(),
                 countOccupied());
        log.add(buf);
    }
""",
"""                 dungeonLevel, (int)dungeon.rooms.size(),
                 countOccupied());
        log.add(buf);
        // R142: name the delve when it is the book's own
        if (seed == dm::sampledungeon::kSampleSeed) {
            log.add("The Monastery Cellars - the DMG's own "
                    "sample dungeon (pp.94-96), keyed, not "
                    "generated. The M key walks you back "
                    "out.");
        }
    }
""",
      "state_core.cpp: sample delve log line",
      marker="The Monastery Cellars - the DMG's own ")

patch("game/state_dungeon.cpp",
"""void AppState::populateRooms(){
""",
"""void AppState::populateRooms(){
        // R142: the sample dungeon - the DMG's own keyed
        // delve (pp.94-96). The book keys its rooms
        // exactly, so the generated dressing (dart traps,
        // Appendix H curiosities, random lairs) stands down
        // for the whole delve; the entry chamber lairs the
        // book's large spider (the nine young of 1 hp are
        // flavor - one adult is the convention, the book
        // gives no fight mechanics for the brood).
        if (seed == dm::sampledungeon::kSampleSeed) {
            for (auto& room : occupancy.rooms) {
                room.monsterKey.clear();
                room.count = 0;
                room.looted = false;
                room.trap = 0;
                room.trapKind = -1;
                room.trickFeature = -1;
                room.trickAttribute = -1;
                room.trickDone = false;
                room.flavorSeen = false;
                room.parleyed = false;
                room.headsLo = room.headsHi = 0;
                room.ageLo = room.ageHi = 0;
            }
            if (!occupancy.rooms.empty()) {
                occupancy.rooms[0].monsterKey = "large_spider";
                occupancy.rooms[0].count = 1;
            }
            return;
        }
""",
      "state_dungeon.cpp: populateRooms sample branch",
      marker="the nine young of 1 hp are")
patch("game/state_town.cpp",
"""        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.flavorSeen) return;
        room.flavorSeen = true;
""",
"""        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.flavorSeen) return;
        room.flavorSeen = true;
        // R142: the sample dungeon - the keyed rooms speak
        // the book's own text (pure data in
        // dm/sampledungeon.h), one first sight each
        if (seed == dm::sampledungeon::kSampleSeed &&
            roomIndex < 3) {
            log.add(dm::sampledungeon::sampleRoomText(
                roomIndex));
            return;
        }
""",
      "state_town.cpp: describeRoom sample text",
      marker="the keyed rooms speak")

patch("game/state_dungeon.cpp",
"""        if (combatRoomIndex >= 0 && !mmLair) {
            RoomOccupant& room = occupancy.rooms[combatRoomIndex];
            if (!room.monsterKey.empty()) {
""",
"""        if (combatRoomIndex >= 0 && !mmLair) {
            RoomOccupant& room = occupancy.rooms[combatRoomIndex];
            // R142: the sample dungeon - the book's own
            // hoards ride the keyed rooms; the generated
            // treasure roll stands down for them (the take
            // earns no gold xp - a museum piece, not a
            // guarded hoard; documented convention)
            if (seed == dm::sampledungeon::kSampleSeed &&
                combatRoomIndex < 3) {
                if (combatRoomIndex == 0 && !room.looted) {
                    // the goblin skull: 19 sp folded at 10:1
                    // (2 gp, rounded) plus a 50 gp garnet
                    int take = 52;
                    party.gold += take;
                    party.delveGold += take;
                    log.add("In the goblin skull: 19 silver "
                            "pieces and a garnet - 52 gp "
                            "all told.");
                    // a quarter of the ten rotting sacks
                    // hide yellow mold (the book: save vs
                    // poison or die)
                    if ((int)rng.below(100) < 25) {
                        log.add("One of the rotting sacks "
                                "puffs YELLOW MOLD!");
                        for (auto& c : party.members) {
                            if (c.hp <= 0) continue;
                            int target = rules::saveTarget(
                                c.classIndex, c.level,
                                rules::SAVE_DEATH_POISON);
                            if (rules::attemptSave(
                                    dice, target, 0)) {
                                log.add(c.name + " breathes "
                                        "shallow - safe.");
                            } else {
                                c.hp = 0;
                                log.add(c.name + " inhales "
                                        "the spores and "
                                        "dies.");
                            }
                        }
                        if (!party.alive())
                            log.add("GAME OVER - press N to "
                                    "roll a new party.");
                    }
                } else if (combatRoomIndex == 1 &&
                           !room.looted) {
                    log.add("The ivory tube holds a vellum "
                            "map, water-ruined - only the "
                            "first few chambers stay "
                            "legible. The abbot's key fits "
                            "nothing here: the crypts it "
                            "opened ride a future round.");
                } else if (combatRoomIndex == 2 &&
                           !room.looted) {
                    log.add("Seven stone knobs over empty "
                            "socket holes - the seventh "
                            "opens the south crypt door, "
                            "but the book keys no crypt: "
                            "the door stays shut (a future "
                            "round).");
                }
                room.monsterKey.clear();
                room.count = 0;
                room.looted = true;
            }
            if (!room.monsterKey.empty()) {
""",
      "state_dungeon.cpp: awardVictory sample hoards",
      marker="In the goblin skull:")

patch("game/state_combat.cpp",
"""        // An empty key is NO ENCOUNTER (or an R53 re-roll row).
        dm::DungeonEncounter e = rollDmEncounter();
""",
"""        // An empty key is NO ENCOUNTER (or an R53 re-roll row).
        // R142: the sample dungeon - the book's own wandering
        // table (p.96): a d4 pick from the monastery halls
        // column, count rolled inside the printed range. The
        // crypt column stays data until the crypts exist.
        dm::DungeonEncounter e;
        if (seed == dm::sampledungeon::kSampleSeed) {
            dm::sampledungeon::SampleWanderingRow w =
                dm::sampledungeon::sampleWandering(
                    false, 1 + (int)rng.below(4));
            e.key = w.key;
            e.count = w.lo + (int)rng.below(
                (uint32_t)(w.hi - w.lo + 1));
        } else {
            e = rollDmEncounter();
        }
""",
      "state_combat.cpp: sample wandering table",
      marker="the monastery halls")

patch("adnd1.cpp",
"""                    case 'X':
                    case 'x':
                        g_app.engageTrick();
                        break;

                    case VK_ESCAPE:
""",
"""                    case 'X':
                    case 'x':
                        g_app.engageTrick();
                        break;

                    // R142: the sample dungeon - the DMG's
                    // own keyed delve (pp.94-96), summoned
                    // whole; any delve-N or stair walk
                    // returns to the generated dungeon
                    case 'M':
                    case 'm':
                        g_app.newDungeon(
                            dm::sampledungeon::kSampleSeed);
                        break;

                    case VK_ESCAPE:
""",
      "adnd1.cpp: M summons the sample dungeon",
      marker="dm::sampledungeon::kSampleSeed);")

patch("regtest.cpp",
"""#include "dm/appendixgh.h"  // R125: pp.216-217 Appendix G/H lists
""",
"""#include "dm/appendixgh.h"  // R125: pp.216-217 Appendix G/H lists
#include "dm/sampledungeon.h"  // R142: pp.94-96 the DMG sample dungeon
""",
      "regtest.cpp: sampledungeon include",
      marker="dm/sampledungeon.h")
r142_lines = [
"    // ---- R142: sample dungeon audit ----",
"    // The DMG's own sample delve (pp.94-96, the MONASTERY",
"    // CELLARS) is keyed as pure data: three rooms (room 0",
"    // exactly the book 30 foot square entry chamber = 3x3",
"    // tiles at 10 feet), the two d4 wandering tables, and",
"    // the keyed texts. The crypt column, the crypt-cleric",
"    // row, and the crypts behind the seventh knob ride the",
"    // future-crypts debt (data now, delve later).",
"    {",
"        int bad = 0;",
"        // the sample seed is not the default delve seed",
"        if (dm::sampledungeon::kSampleSeed == 1) ++bad;",
"        dm::DungeonResult d =",
"            dm::sampledungeon::buildSampleDungeon();",
"        // three rooms, the keyed shapes",
"        if (d.rooms.size() != 3) {",
"            ++bad;",
"        } else {",
"            if (d.rooms[0].x != 30 || d.rooms[0].y != 30) ++bad;",
"            if (d.rooms[0].w != 3 || d.rooms[0].h != 3) ++bad;",
"            if (d.rooms[1].w != 4 || d.rooms[1].h != 5) ++bad;",
"            if (d.rooms[2].w != 4 || d.rooms[2].h != 4) ++bad;",
"        }",
"        // the entry stair lands at the chamber center",
"        if (d.entryX != 31 || d.entryY != 31) ++bad;",
"        if (!d.map.walkable(d.entryX, d.entryY)) ++bad;",
"        // every room tile is walkable",
"        for (int i = 0; i < (int)d.rooms.size(); ++i) {",
"            const dm::GeneratedRoom& r = d.rooms[i];",
"            if (r.w <= 0 || r.h <= 0) { ++bad; continue; }",
"            for (int yy = 0; yy < r.h; ++yy)",
"                for (int xx = 0; xx < r.w; ++xx)",
"                    if (!d.map.walkable(r.x + xx, r.y + yy))",
"                        ++bad;",
"        }",
"        // the passage knits the three chambers together",
"        for (int x = 33; x <= 45; ++x)",
"            if (!d.map.walkable(x, 31)) ++bad;",
"        // determinism: two builds agree tile for tile",
"        {",
"            dm::DungeonResult d2 =",
"                dm::sampledungeon::buildSampleDungeon();",
"            for (int y = 0; y < world::MAP_TILES_Y; ++y)",
"                for (int x = 0; x < world::MAP_TILES_X; ++x)",
"                    if (d.map.at(x, y) != d2.map.at(x, y)) ++bad;",
"            if (d2.entryX != d.entryX ||",
"                d2.entryY != d.entryY) ++bad;",
"        }",
"        // the halls table, row for row (p.96)",
"        {",
"            dm::sampledungeon::SampleWanderingRow w;",
"            w = dm::sampledungeon::sampleWandering(false, 1);",
"            if (std::string(w.key) != " + chr(34) + "goblin"
+ chr(34) + " ||",
"                w.lo != 3 || w.hi != 12) ++bad;",
"            w = dm::sampledungeon::sampleWandering(false, 2);",
"            if (std::string(w.key) != " + chr(34) + "bandit"
+ chr(34) + " ||",
"                w.lo != 2 || w.hi != 5) ++bad;",
"            w = dm::sampledungeon::sampleWandering(false, 3);",
"            if (std::string(w.key) != " + chr(34) + "giant_rat"
+ chr(34) + " ||",
"                w.lo != 7 || w.hi != 12) ++bad;",
"            w = dm::sampledungeon::sampleWandering(false, 4);",
"            if (std::string(w.key) != " + chr(34) + "fire_beetle"
+ chr(34) + " ||",
"                w.lo != 1 || w.hi != 2) ++bad;",
"        }",
"        // the crypt column, row for row (future data)",
"        {",
"            dm::sampledungeon::SampleWanderingRow w;",
"            w = dm::sampledungeon::sampleWandering(true, 1);",
"            if (std::string(w.key) != " + chr(34) + "ghoul"
+ chr(34) + " ||",
"                w.lo != 1 || w.hi != 2) ++bad;",
"            w = dm::sampledungeon::sampleWandering(true, 2);",
"            if (std::string(w.key) != " + chr(34) + "hobgoblin"
+ chr(34) + " ||",
"                w.lo != 2 || w.hi != 2) ++bad;",
"            w = dm::sampledungeon::sampleWandering(true, 3);",
"            if (std::string(w.key) != " + chr(34) + "giant_rat"
+ chr(34) + " ||",
"                w.lo != 7 || w.hi != 12) ++bad;",
"            w = dm::sampledungeon::sampleWandering(true, 4);",
"            if (std::string(w.key) != " + chr(34) + "skeleton"
+ chr(34) + " ||",
"                w.lo != 2 || w.hi != 5) ++bad;",
"        }",
"        // the three keyed texts: nonempty, pure ASCII",
"        for (int i = 0; i < 3; ++i) {",
"            const char* t =",
"                dm::sampledungeon::sampleRoomText(i);",
"            if (!t || !t[0]) { ++bad; continue; }",
"            for (const char* p = t; *p; ++p)",
"                if ((unsigned char)*p > 127) ++bad;",
"        }",
"        printf(" + chr(34) + "R142 sample dungeon audit: bad %d"
+ BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
"",
]
r142_audit = NL.join(r142_lines)
old_r141_head = "    // ---- R141: engagement geometry audit ----"
patch("regtest.cpp", old_r141_head + NL,
      r142_audit + old_r141_head + NL,
      "regtest.cpp: R142 audit",
      marker="R142 sample dungeon audit")

patch("tools/dmg_gap_report.md",
"""      engagement geometry audit; census 59.

## Out of scope by design
""",
"""      engagement geometry audit; census 59.
- [x] **The sample dungeon (DMG pp.94-96)** - CLOSED R142:
      the MONASTERY CELLARS & SECRET CRYPTS, the book's own
      teaching delve, walk as pure data
      (dm/sampledungeon.h): the three keyed rooms - the 30
      foot square entry chamber (exactly 3x3 tiles at 10
      feet; the large spider lairs per the text, and the
      goblin skull holds 19 sp and a 50 gp garnet, with
      the book's 25 percent yellow-mold sack: save vs
      poison or die), the water room (the stream, the
      ivory tube with its water-ruined vellum map, the
      abbot's curious key), and the ceremonial dome (the 9
      foot platform, the seven stone knobs over empty
      socket holes) - plus the book's two d4 wandering
      tables (the halls column wired to the wander roll;
      the crypt column is data for the future crypts, as
      are the crypt-cleric row and the crypts behind the
      seventh knob). The M key in the delve summons the
      keyed map at kSampleSeed; every other seed walks the
      generated dungeon exactly as before. Pinned by the
      R142 sample dungeon audit; census 60.

## Out of scope by design
""",
      "gap report: R142 box",
      marker="CLOSED R142:")

# ---- R142 fails/tail ----
if fails:
    print("R142 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R142 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R142 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
