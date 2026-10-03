#!/usr/bin/env python3
# tools/r143_splice.py - R143 the crypt wing round: the
# DMG sample dungeon's SECRET CRYPTS (pp.94-96) are
# delved at last - three crypt chambers off a spine south
# of the dome, SEALED behind the seventh knob's door until
# the X key turns it, laired per the book's own crypt-
# column area hints, and the crypt wandering column wired,
# evil cleric row included.
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. The
# R142 lesson: an assert follows EVERY patch, so a
# dropped chunk seam fails loudly here.
#  - dm/sampledungeon.h: the crypt constants (kCryptDoor,
#    openCryptDoor, cryptDoorOpen, inCrypts), the crypt
#    geometry in buildSampleDungeon, three crypt texts
#  - game/state_dungeon.cpp: engageTrick turns the knob;
#    populateRooms lairs the crypts; awardVictory pays
#    the crypt flavor
#  - game/state_town.cpp: describeRoom speaks the crypts
#  - game/state_combat.cpp: the wander roll picks the
#    crypt column south of the knob, cleric row built
#  - regtest.cpp: the R142 audit widens to six rooms; the
#    R143 crypt wing audit (census 61)
#  - tools/dmg_gap_report.md: the R143 box
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

patch("dm/sampledungeon.h",
"""// crypt-cleric row ride the future-crypts debt: data now,
// delve later.
""",
"""// crypt-cleric row ride the future-crypts debt: data now,
// delve later.
// R143: the crypts are DELVED - three crypt chambers off
// a spine south of the dome, sealed behind the seventh
// knob's door; the crypt wandering column is wired, the
// evil cleric row included (the X key opens them in play).
""",
      "sampledungeon.h: intro R143 note",
      marker="R143: the crypts are DELVED")
assert len(applied) + len(already) == 1

patch("dm/sampledungeon.h",
"""// The book's two d4 wandering columns (p.96). crypt=false:
// the monastery halls; crypt=true: the crypt column (data
// for the future crypts - nothing wires it yet). Crypt row
// two is '1 third-level evil cleric and 2 hobgoblins': the
// cleric needs a spell-caster encounter hook and rides
// the debt; the row carries the hobgoblins.
""",
"""// The book's two d4 wandering columns (p.96). crypt=false:
// the monastery halls; crypt=true: the crypt column (the
// R143 wing - wired to the wander roll south of the knob
// door). Crypt row two is '1 third-level evil cleric and
// 2 hobgoblins': the caller builds the cleric as a
// Character foe beside the hobgoblins (R143,
// game/state_combat.cpp).
""",
      "sampledungeon.h: wandering comment R143",
      marker="R143 wing - wired to the wander roll")
assert len(applied) + len(already) == 2

patch("dm/sampledungeon.h",
"""// The keyed room texts (room 1-3 of the book = indices
// 0-2 here). Pure ASCII, pure data; the engine logs them
// as the first-sight flavor of the keyed rooms.
inline const char* sampleRoomText(int i) {
    static const char* texts[3] = {
""",
"""// The keyed room texts (room 1-3 of the book and the
// three crypt chambers = indices 0-5 here). Pure ASCII,
// pure data; the engine logs them as the first-sight
// flavor of the keyed rooms.
inline const char* sampleRoomText(int i) {
    static const char* texts[6] = {
""",
      "sampledungeon.h: texts[6]",
      marker="static const char* texts[6] = {")
assert len(applied) + len(already) == 3

patch("dm/sampledungeon.h",
"""south crypt door."
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
""",
"""south crypt door.",
        "Cold niches line this crypt, and the bones within are gnawed - the ghoul larder of the book's area 24.",
        "Sunken biers rest in rows down this crypt - the faithful of the monastery stood them here (area 27).",
        "A defaced altar and torn vestments foul this crypt - the evil cleric keeps it (areas 35-37)."
    };
    if (i < 0) i = 0;
    if (i > 5) i = 5;
""",
      "sampledungeon.h: crypt texts + clamp",
      marker="A defaced altar and torn vestments")
assert len(applied) + len(already) == 4

patch("dm/sampledungeon.h",
"""// Build the keyed delve: three chambers joined by a
""",
"""// R143: the crypt door - the seventh knob opens it.
// Sealed = the tile is rock (TILE_VOID); openCryptDoor
// swings it to a door tile. inCrypts() bounds the crypt
// wing for the crypt wandering column.
const int kCryptDoorX = 47;
const int kCryptDoorY = 34;
inline void openCryptDoor(world::Map& m) {
    m.set(kCryptDoorX, kCryptDoorY, world::TILE_DOOR);
}
inline bool cryptDoorOpen(const world::Map& m) {
    return m.at(kCryptDoorX, kCryptDoorY) ==
           world::TILE_DOOR;
}
inline bool inCrypts(int x, int y) {
    return y >= kCryptDoorY;
}

// Build the keyed delve: three chambers joined by a
""",
      "sampledungeon.h: crypt door constants",
      marker="inline void openCryptDoor(world::Map& m)")
assert len(applied) + len(already) == 5

patch("dm/sampledungeon.h",
"""    res.rooms.push_back(r0);
    res.rooms.push_back(r1);
    res.rooms.push_back(r2);
    res.entryX = 31;   // the chamber center
""",
"""    // R143: the SECRET CRYPTS wing - the book keys no
    // crypt, but its crypt wandering column names three
    // lairs (area 24 ghouls, area 27 skeletons, areas
    // 35-37 the cleric's hobgoblins), so three crypt
    // chambers hang off a spine south of the dome. The
    // knob door tile stays rock until the X key turns
    // the seventh knob (openCryptDoor) - the wing is
    // carved but SEALED.
    GeneratedRoom r3;   // the ghoul crypt (area 24)
    r3.x = 40; r3.y = 38; r3.w = 4; r3.h = 3;
    GeneratedRoom r4;   // the skeleton crypt (area 27)
    r4.x = 46; r4.y = 38; r4.w = 4; r4.h = 3;
    GeneratedRoom r5;   // the cleric's crypt (35-37)
    r5.x = 52; r5.y = 38; r5.w = 4; r5.h = 3;
    const GeneratedRoom* crs[3] = { &r3, &r4, &r5 };
    for (int i = 0; i < 3; ++i) {
        const GeneratedRoom& r = *crs[i];
        for (int yy = 0; yy < r.h; ++yy)
            for (int xx = 0; xx < r.w; ++xx)
                m.set(r.x + xx, r.y + yy, world::TILE_FLOOR);
    }
    // the crypt descent from the dome's south jamb:
    // corridor down, then the spine under the three
    // chambers (the knob door tile itself is NOT carved)
    for (int y = 35; y <= 36; ++y)
        m.set(47, y, world::TILE_CORR);
    for (int x = 40; x <= 55; ++x)
        m.set(x, 37, world::TILE_CORR);

    res.rooms.push_back(r0);
    res.rooms.push_back(r1);
    res.rooms.push_back(r2);
    res.rooms.push_back(r3);
    res.rooms.push_back(r4);
    res.rooms.push_back(r5);
    res.entryX = 31;   // the chamber center
""",
      "sampledungeon.h: crypt geometry",
      marker="r5.x = 52; r5.y = 38;")
assert len(applied) + len(already) == 6

patch("game/state_dungeon.cpp",
"""        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.trickFeature < 0 ||
            !room.monsterKey.empty() || room.trickDone) {
            log.add("Nothing here begs engaging.");
""",
"""        RoomOccupant& room = occupancy.rooms[roomIndex];
        // R143: the seventh knob - in the book's own sample
        // dungeon, the ceremonial dome's seventh stone knob
        // opens the south crypt door. The X key turns it
        // (a second turn only says the door stands open).
        if (seed == dm::sampledungeon::kSampleSeed &&
            roomIndex == 2) {
            if (dm::sampledungeon::cryptDoorOpen(map)) {
                log.add("The crypt door already stands "
                        "open to the south.");
            } else {
                dm::sampledungeon::openCryptDoor(map);
                log.add("The SEVENTH KNOB turns - stone "
                        "grinds, and a door swings open "
                        "to the south. The Secret Crypts "
                        "lie beyond.");
            }
            return;
        }
        if (room.trickFeature < 0 ||
            !room.monsterKey.empty() || room.trickDone) {
            log.add("Nothing here begs engaging.");
""",
      "state_dungeon.cpp: engageTrick turns the knob",
      marker="The SEVENTH KNOB turns")
assert len(applied) + len(already) == 7

patch("game/state_dungeon.cpp",
"""            if (!occupancy.rooms.empty()) {
                occupancy.rooms[0].monsterKey = "large_spider";
                occupancy.rooms[0].count = 1;
            }
            return;
""",
"""            if (!occupancy.rooms.empty()) {
                occupancy.rooms[0].monsterKey = "large_spider";
                occupancy.rooms[0].count = 1;
            }
            // R143: the crypt wing lairs per the book's own
            // crypt-column area hints - area 24 ghouls,
            // area 27 skeletons, areas 35-37 the cleric's
            // hobgoblins (lair counts are the convention;
            // the book keys no crypt rooms)
            if (occupancy.rooms.size() >= 6) {
                occupancy.rooms[3].monsterKey = "ghoul";
                occupancy.rooms[3].count = 2;
                occupancy.rooms[4].monsterKey = "skeleton";
                occupancy.rooms[4].count = 4;
                occupancy.rooms[5].monsterKey = "hobgoblin";
                occupancy.rooms[5].count = 2;
            }
            return;
""",
      "state_dungeon.cpp: populateRooms crypt lairs",
      marker="occupancy.rooms[3].monsterKey = " + chr(34)
      + "ghoul" + chr(34) + ";")
assert len(applied) + len(already) == 8

patch("game/state_town.cpp",
"""        if (seed == dm::sampledungeon::kSampleSeed &&
            roomIndex < 3) {
""",
"""        if (seed == dm::sampledungeon::kSampleSeed &&
            roomIndex < 6) {
""",
      "state_town.cpp: describeRoom six rooms",
      marker="            roomIndex < 6) {")
assert len(applied) + len(already) == 9

patch("game/state_dungeon.cpp",
"""            if (seed == dm::sampledungeon::kSampleSeed &&
                combatRoomIndex < 3) {
""",
"""            if (seed == dm::sampledungeon::kSampleSeed &&
                combatRoomIndex < 6) {
""",
      "state_dungeon.cpp: awardVictory six rooms",
      marker="                combatRoomIndex < 6) {")
assert len(applied) + len(already) == 10

patch("game/state_dungeon.cpp",
"""                } else if (combatRoomIndex == 1 &&
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
""",
"""                } else if (combatRoomIndex == 1 &&
                           !room.looted) {
                    log.add("The ivory tube holds a vellum "
                            "map, water-ruined - only the "
                            "first few chambers stay "
                            "legible. The abbot's key is "
                            "the crypts' own: beyond the "
                            "seventh knob.");
                } else if (combatRoomIndex == 2 &&
                           !room.looted) {
                    log.add("Seven stone knobs over empty "
                            "socket holes - the seventh "
                            "opens the south crypt door. "
                            "Turn it with the X key.");
                } else if (combatRoomIndex == 3 &&
                           !room.looted) {
                    log.add("Gnawed bones stack the crypt's "
                            "niches - ghouls kept this "
                            "larder (area 24). The abbot's "
                            "key fits the old crypt locks.");
                } else if (combatRoomIndex == 4 &&
                           !room.looted) {
                    log.add("Rows of sunken biers - the "
                            "faithful of the monastery "
                            "rested here (area 27). The "
                            "abbot's key fits the old "
                            "crypt locks.");
                } else if (combatRoomIndex == 5 &&
                           !room.looted) {
                    log.add("A defaced altar and torn "
                            "vestments - the evil cleric "
                            "kept this crypt (areas "
                            "35-37).");
                }
""",
      "state_dungeon.cpp: awardVictory crypt flavor",
      marker="Rows of sunken biers")
assert len(applied) + len(already) == 11

patch("game/state_combat.cpp",
"""        // R142: the sample dungeon - the book's own wandering
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
"""        // R142: the sample dungeon - the book's own wandering
        // table (p.96): a d4 pick from the right column -
        // the monastery halls, or the crypts when the
        // company walks the crypt wing - count rolled
        // inside the printed range. R143: crypt row two is
        // the book's evil 3rd-level cleric and his 2
        // hobgoblins: the cleric is built as a Character
        // foe (the engine's NPC kit) beside them; the book
        // gives the crypt column as straight encounters,
        // so no reaction gate on this row (documented).
        dm::DungeonEncounter e;
        if (seed == dm::sampledungeon::kSampleSeed) {
            bool crypt = dm::sampledungeon::inCrypts(
                party.x, party.y);
            int roll = 1 + (int)rng.below(4);
            if (crypt && roll == 2) {
                dm::CharacterParty cp;
                dm::PartyMember cm;
                cm.classIndex = rules::CLASS_CLERIC;
                cm.level = 3;
                cp.members.push_back(cm);
                std::vector<ai::Actor> foes =
                    buildFoesFromParty(cp);
                dm::DungeonEncounter hg;
                hg.key = "hobgoblin";
                hg.count = 2;
                std::vector<ai::Actor> guards =
                    buildFoesFromDm(hg);
                foes.insert(foes.end(),
                            guards.begin(), guards.end());
                if (foes.empty()) return;
                log.add("An evil cleric and 2 hobgoblins "
                        "stalk the crypts!");
                beginCombat(std::move(foes), -1,
                           "hobgoblin");
                return;
            }
            dm::sampledungeon::SampleWanderingRow w =
                dm::sampledungeon::sampleWandering(
                    crypt, roll);
            e.key = w.key;
            e.count = w.lo + (int)rng.below(
                (uint32_t)(w.hi - w.lo + 1));
        } else {
            e = rollDmEncounter();
        }
""",
      "state_combat.cpp: crypt wander column + cleric row",
      marker="stalk the crypts!")
assert len(applied) + len(already) == 12

patch("regtest.cpp",
"""        // three rooms, the keyed shapes
        if (d.rooms.size() != 3) {
""",
"""        // six rooms: the three keyed chambers plus the
        // three crypt chambers of the R143 crypt wing
        if (d.rooms.size() != 6) {
""",
      "regtest.cpp: R142 audit six rooms",
      marker="d.rooms.size() != 6) {")
assert len(applied) + len(already) == 13

patch("regtest.cpp",
"""        // the three keyed texts: nonempty, pure ASCII
        for (int i = 0; i < 3; ++i) {
""",
"""        // the six keyed texts: nonempty, pure ASCII
        for (int i = 0; i < 6; ++i) {
""",
      "regtest.cpp: R142 audit six texts",
      marker="the six keyed texts: nonempty, pure ASCII")
assert len(applied) + len(already) == 14

r143_lines = [
"    // ---- R143: crypt wing audit ----",
"    // The sample dungeon's crypts are delved at last:",
"    // three crypt chambers off a spine south of the",
"    // dome, SEALED behind the seventh knob's door (rock",
"    // until openCryptDoor turns it), laired per the",
"    // book's crypt-column area hints, and the crypt",
"    // wandering column wired - the evil cleric row rides",
"    // the Character-foe path in the engine (no audit",
"    // hook; the row's hobgoblins are pinned in R142).",
"    {",
"        int bad = 0;",
"        dm::DungeonResult d =",
"            dm::sampledungeon::buildSampleDungeon();",
"        // the crypt wing hangs south of the dome",
"        if (d.rooms.size() < 6) {",
"            ++bad;",
"        } else {",
"            if (d.rooms[3].x != 40 || d.rooms[3].y != 38 ||",
"                d.rooms[3].w != 4 || d.rooms[3].h != 3) ++bad;",
"            if (d.rooms[4].x != 46 || d.rooms[4].y != 38 ||",
"                d.rooms[4].w != 4 || d.rooms[4].h != 3) ++bad;",
"            if (d.rooms[5].x != 52 || d.rooms[5].y != 38 ||",
"                d.rooms[5].w != 4 || d.rooms[5].h != 3) ++bad;",
"        }",
"        // the crypt chambers are carved walkable",
"        for (int i = 3; i < 6 && i < (int)d.rooms.size();",
"             ++i) {",
"            const dm::GeneratedRoom& r = d.rooms[i];",
"            for (int yy = 0; yy < r.h; ++yy)",
"                for (int xx = 0; xx < r.w; ++xx)",
"                    if (!d.map.walkable(r.x + xx, r.y + yy))",
"                        ++bad;",
"        }",
"        // the descent and the spine",
"        if (!d.map.walkable(47, 35) ||",
"            !d.map.walkable(47, 36)) ++bad;",
"        for (int x = 40; x <= 55; ++x)",
"            if (!d.map.walkable(x, 37)) ++bad;",
"        // the knob door is SEALED rock until turned",
"        if (d.map.walkable(dm::sampledungeon::kCryptDoorX,",
"                          dm::sampledungeon::kCryptDoorY))",
"            ++bad;",
"        if (dm::sampledungeon::cryptDoorOpen(d.map)) ++bad;",
"        dm::sampledungeon::openCryptDoor(d.map);",
"        if (!dm::sampledungeon::cryptDoorOpen(d.map)) ++bad;",
"        if (d.map.at(dm::sampledungeon::kCryptDoorX,",
"                     dm::sampledungeon::kCryptDoorY) !=",
"            world::TILE_DOOR) ++bad;",
"        // the wing's boundary: the halls sit above the",
"        // knob, the crypts below it",
"        if (dm::sampledungeon::inCrypts(31, 31)) ++bad;",
"        if (!dm::sampledungeon::inCrypts(47, 37)) ++bad;",
"        if (!dm::sampledungeon::inCrypts(53, 40)) ++bad;",
"        // the crypt texts: nonempty, pure ASCII",
"        for (int i = 3; i < 6; ++i) {",
"            const char* t =",
"                dm::sampledungeon::sampleRoomText(i);",
"            if (!t || !t[0]) { ++bad; continue; }",
"            for (const char* p = t; *p; ++p)",
"                if ((unsigned char)*p > 127) ++bad;",
"        }",
"        printf(" + chr(34) + "R143 crypt wing audit: bad %d"
+ BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
"",
]
r143_audit = NL.join(r143_lines)
old_r142_head = "    // ---- R142: sample dungeon audit ----"
patch("regtest.cpp", old_r142_head + NL,
      r143_audit + old_r142_head + NL,
      "regtest.cpp: R143 audit",
      marker="R143 crypt wing audit")
assert len(applied) + len(already) == 15

patch("tools/dmg_gap_report.md",
"""      R142 sample dungeon audit; census 60.

## Out of scope by design
""",
"""      R142 sample dungeon audit; census 60.
- [x] **The sample dungeon's crypts (the future-crypts
      debt)** - CLOSED R143: the SECRET CRYPTS are delved.
      Three crypt chambers (the book's own crypt wandering
      column names their lairs - area 24 ghouls, area 27
      skeletons, areas 35-37 the cleric's hobgoblins; the
      book itself keys no crypt rooms, so the chambers and
      lair counts are conventions) hang off a spine south
      of the ceremonial dome, SEALED behind the seventh
      knob's door - rock until the X key turns the knob in
      the dome. South of that door the wander roll switches
      to the book's crypt column, and its second row walks
      at last: the evil 3rd-level cleric, built as a
      Character foe beside his 2 hobgoblins (the book
      gives the crypt column as straight encounters - no
      reaction gate on that row, documented). The crypt
      texts speak on first sight; the abbot's key is
      flavor (the book's secret door 28-29 is a crypt
      lock here by convention). Pinned by the R143 crypt
      wing audit; census 61.

## Out of scope by design
""",
      "gap report: R143 box",
      marker="CLOSED R143:")
assert len(applied) + len(already) == 16

# ---- R143 fails/tail ----
if fails:
    print("R143 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 16:
    print("R143 splice: FAIL - expected 16 patches, "
          "counted " + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R143 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R143 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
