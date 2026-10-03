#!/usr/bin/env python3
# tools/r141_splice.py - R141 the engagement geometry round:
# the R43 50' debt closes - a room fight now OPENS at the
# chamber's own geometry (longest interior dimension in
# 10' bands, floored at the 50' corridor convention,
# capped at 120'), so the R116 long band (-5) is finally
# reachable in play.
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - rules/combat.h: engagementBands(w, h) - the pure
#    helper (floored 5, capped 12)
#  - ai/actor.h: the R141 comment + Encounter::
#    setOpeningBands(bands) (clamped 1-12)
#  - game/state_combat.cpp: beginCombat opens a room
#    fight at the chamber's bands (wandering/overland
#    keep the 50' convention); a wide chamber logs the
#    distance
#  - regtest.cpp: the R141 geometry audit (census 59)
#  - tools/dmg_gap_report.md: the R141 box
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

patch("rules/combat.h",
"""// the book's to-hit modifier at that distance:
// 0 at short, -2 at medium, -5 at long
int missileRangeMod(int distanceFeet, int shortRangeFeet);
""",
"""// the book's to-hit modifier at that distance:
// 0 at short, -2 at medium, -5 at long
int missileRangeMod(int distanceFeet, int shortRangeFeet);

// ----------------------------------------------------------------------------
// R141: engagement geometry (closing the R43 50' debt)
// ----------------------------------------------------------------------------
// A room fight opens at the chamber's own geometry: the
// longest interior dimension in 10' bands - floored at
// the 50' corridor convention (5 bands) and capped at
// 120' (12 bands, a sling's long range). A big chamber
// therefore opens WIDE, and the R116 long band (-5) is
// finally reachable in play. Wandering and overland
// engagements keep the 50' convention (no room).
inline int engagementBands(int roomW, int roomH) {
    int longest = roomW > roomH ? roomW : roomH;
    if (longest < 5) return 5;
    if (longest > 12) return 12;
    return longest;
}
""",
      "combat.h: engagementBands",
      marker="inline int engagementBands(int roomW, int roomH)")

patch("ai/actor.h",
"""// R43: party-side range - the encounter carries an abstract
//      distance (m_distance, 5 bands = 50' engagement range).
//      It closes one band per round; party missile fire ([x])
//      requires an open range. Thrown weapons are exempt (they
//      can be hurled into melee - PHB simplification).
""",
"""// R43: party-side range - the encounter carries an abstract
//      distance (m_distance, 5 bands = 50' engagement range).
//      It closes one band per round; party missile fire ([x])
//      requires an open range. Thrown weapons are exempt (they
//      can be hurled into melee - PHB simplification).
// R141: the opening range is now geometry - a room fight opens
//      at the chamber's longest interior dimension in 10' bands
//      (rules::engagementBands: floored at the 50' corridor
//      convention, capped at 120'); wandering and overland
//      engagements keep the 50' opening.
""",
      "actor.h: R141 comment",
      marker="R141: the opening range is now geometry")

patch("ai/actor.h",
"""    bool rangeOpen() const { return m_distance > 0; }
""",
"""    bool rangeOpen() const { return m_distance > 0; }

    // R141: the opening range is the room's own geometry
    // (rules::engagementBands - a chamber fight opens
    // wider than the 50' corridor convention). Clamped
    // to 1-12 bands.
    void setOpeningBands(int bands) {
        if (bands < 1) bands = 1;
        if (bands > 12) bands = 12;
        m_distance = bands;
    }
""",
      "actor.h: setOpeningBands",
      marker="void setOpeningBands(int bands)")

patch("game/state_combat.cpp",
"""        combat.start(partyActors(), std::move(foes),
                     rng.below(0x7FFFFFFF));
""",
"""        combat.start(partyActors(), std::move(foes),
                     rng.below(0x7FFFFFFF));
        // R141: the opening range is geometry - a room fight
        // opens at the chamber's longest interior dimension
        // (10' bands, floored at the 50' corridor convention,
        // capped at 120'); wandering and overland fights keep
        // the 50' opening (no room to measure)
        if (roomIndex >= 0 &&
            roomIndex < (int)occupancy.rooms.size()) {
            int grIdx = occupancy.rooms[roomIndex].roomIndex;
            if (grIdx >= 0 &&
                grIdx < (int)dungeon.rooms.size()) {
                const dm::GeneratedRoom& gr =
                    dungeon.rooms[grIdx];
                int bands = rules::engagementBands(gr.w,
                                                   gr.h);
                combat.encounter->setOpeningBands(bands);
                if (bands > 5) {
                    char dbuf[96];
                    snprintf(dbuf, sizeof dbuf,
                             "The chamber yawns - the foes "
                             "wait %d' away.", bands * 10);
                    log.add(dbuf);
                }
            }
        }
""",
      "state_combat.cpp: beginCombat geometry opening",
      marker="setOpeningBands(bands);")

r141_lines = [
"    // ---- R141: engagement geometry audit ----",
"    // The R43 50' debt closes: a room fight opens at",
"    // the chamber's longest interior dimension in 10'",
"    // bands (floored at the 50' corridor convention,",
"    // capped at 120') - so the R116 long band (-5) is",
"    // finally reachable in play.",
"    {",
"        int bad = 0;",
"        // the pure helper: floor at 5, cap at 12, the",
"        // longest dimension wins",
"        if (rules::engagementBands(0, 0) != 5) ++bad;",
"        if (rules::engagementBands(2, 3) != 5) ++bad;",
"        if (rules::engagementBands(5, 5) != 5) ++bad;",
"        if (rules::engagementBands(7, 4) != 7) ++bad;",
"        if (rules::engagementBands(4, 9) != 9) ++bad;",
"        if (rules::engagementBands(12, 12) != 12) ++bad;",
"        if (rules::engagementBands(20, 30) != 12) ++bad;",
"        // the long band in play: a 12-tile chamber opens",
"        // at 120' - a sling (40' short) fires its long",
"        // shot at -5, and one band beyond is impossible",
"        int bands = rules::engagementBands(12, 5);",
"        if (bands != 12) ++bad;",
"        if (rules::missileRangeMod(bands * 10, 40) != -5)",
"            ++bad;",
"        if (!rules::missileInRange(bands * 10, 40)) ++bad;",
"        // the corridor convention holds: the old 50'",
"        // opening is the sling's medium band",
"        if (rules::missileRangeMod(50, 40) != -2) ++bad;",
"        if (rules::missileRangeMod(50, 50) != 0) ++bad;",
"        printf(" + chr(34) + "R141 engagement geometry audit: bad %d"
        + BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
""]
r141_audit = NL.join(r141_lines)
old_r140_head = "    // ---- R140: final sweep audit ----"
patch("regtest.cpp", old_r140_head + NL,
      r141_audit + NL + old_r140_head + NL,
      "regtest.cpp: R141 audit",
      marker="R141 engagement geometry audit")

patch("tools/dmg_gap_report.md",
"""      R140 final sweep audit; census 58.

## Out of scope by design
""",
"""      R140 final sweep audit; census 58.
- [x] **Engagement geometry (the R43 50' standing
      debt)** - CLOSED R141: a room fight now OPENS at
      the chamber's own geometry - the longest interior
      dimension in 10' bands (rules::engagementBands,
      floored at the 50' corridor convention, capped at
      120') - and the range closes one band per round as
      before. A wide chamber therefore opens wide, and
      the R116 long-range band (-5, DMG p.75) is finally
      reachable in play: a 12-tile chamber opens at
      120', where a sling's long shot (40' short range)
      is exactly possible at -5. Wandering and overland
      engagements keep the 50' convention (no room to
      measure). The battery pins the helper's floor,
      cap, and longest-dimension rule, and the
      long-band-in-play scenario. Pinned by the R141
      engagement geometry audit; census 59.

## Out of scope by design
""",
      "gap report: R141 box",
      marker="CLOSED R141:")

# ---- R141 fails/tail ----
if fails:
    print("R141 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R141 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R141 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
