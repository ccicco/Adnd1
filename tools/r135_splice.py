#!/usr/bin/env python3
# tools/r135_splice.py - R135 Appendix H room-geometry
# slice: five positional attributes wired (the
# mechanical set grows 19 -> 24; 41 stay dressing).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/appendixgh.h: trickIsMechanical grows to
#    twenty-four - one-way, pivots, spinning, shifting,
#    sliding (all positional conventions - the print
#    gives no mechanics; each moves or commits the
#    company within the room rect)
#  - game/state_dungeon.cpp: applyTrick gains the five
#    geometry branches (the seal, the quarter-turn, the
#    half-turn, the mirror, the edge-shove)
#  - regtest.cpp: the four audits' mechanical count pins
#    update (19 -> 24), three audit comments update, and
#    the new R135 audit pins the set (census 53)
#  - tools/dmg_gap_report.md: the R128/R132/R133/R134
#    boxes' dressing counts drop to 41; the R135 box
#    closes
# This file contains ZERO backslash characters - the
# audit printf's escaped newline is assembled from
# chr(92), which nothing can eat (the R133b lesson).
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

patch("dm/appendixgh.h",
"""// print gives no figures. The remaining 46 stay
// dressing; their effects ride future rounds.
inline bool trickIsMechanical(int a) {
""",
"""// print gives no figures. R135 wires the
// room-geometry slice: one-way (the way back seals -
// the company is committed to the room), pivots and
// spinning (the room turns - the company's position
// rotates about the room center, clamped inside),
// shifting (the position mirrors across the center
// line), sliding (the company is shoved to a random
// room edge). All five are positional conventions -
// the print gives no mechanics. The remaining 41 stay
// dressing; their effects ride future rounds.
inline bool trickIsMechanical(int a) {
""",
      "appendixgh.h: geometry comment",
      marker="R135 wires the")

patch("dm/appendixgh.h",
"""           a == TA_COLLAPSING || a == TA_WISH ||
           a == TA_GRAVITY_GREATER || a == TA_POLYMORPH;
}
""",
"""           a == TA_COLLAPSING || a == TA_WISH ||
           a == TA_GRAVITY_GREATER || a == TA_POLYMORPH ||
           a == TA_ONE_WAY || a == TA_PIVOTS ||
           a == TA_SPINNING || a == TA_SHIFTING ||
           a == TA_SLIDING;
}
""",
      "appendixgh.h: mechanical set 24",
      marker="a == TA_SLIDING;")

patch("game/state_dungeon.cpp",
"""        // greater (1d6 crush, everyone, no save),
        // polymorph (save or 3d4 reshape).
""",
"""        // greater (1d6 crush, everyone, no save),
        // polymorph (save or 3d4 reshape). R135: the
        // room-geometry slice - one-way (the way
        // seals), pivots/spinning (the room turns),
        // shifting (the walls flex), sliding (the
        // floor tilts).
""",
      "state_dungeon.cpp: applyTrick doc",
      marker="R135: the")

patch("game/state_dungeon.cpp",
"""        } else if (a == dm::appendixh::TA_SHOOTS ||
""",
"""        } else if (a == dm::appendixh::TA_ONE_WAY) {
            // R135: the way back seals - the company is
            // committed to this room (a convention; the
            // print gives no mechanics)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            party.x = gr.x + gr.w / 2;
            party.y = gr.y + gr.h / 2;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s thuds - the way back seals!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_PIVOTS) {
            // R135: the room turns a quarter - the
            // company's position rotates 90 degrees about
            // the room center, clamped inside (the
            // print gives no mechanics; a convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            int cx = gr.x + gr.w / 2;
            int cy = gr.y + gr.h / 2;
            int nx = cx - (party.y - cy);
            int ny = cy + (party.x - cx);
            if (nx < gr.x) nx = gr.x;
            if (nx > gr.x + gr.w - 1) nx = gr.x + gr.w - 1;
            if (ny < gr.y) ny = gr.y;
            if (ny > gr.y + gr.h - 1) ny = gr.y + gr.h - 1;
            party.x = nx;
            party.y = ny;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s pivots - the walls swing!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SPINNING) {
            // R135: a full half-turn - the company's
            // position rotates 180 degrees about the
            // room center, clamped inside (a convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            int cx = gr.x + gr.w / 2;
            int cy = gr.y + gr.h / 2;
            int nx = 2 * cx - party.x;
            int ny = 2 * cy - party.y;
            if (nx < gr.x) nx = gr.x;
            if (nx > gr.x + gr.w - 1) nx = gr.x + gr.w - 1;
            if (ny < gr.y) ny = gr.y;
            if (ny > gr.y + gr.h - 1) ny = gr.y + gr.h - 1;
            party.x = nx;
            party.y = ny;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s spins - the room whirls!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SHIFTING) {
            // R135: the walls flex - the company's
            // position mirrors across the room's center
            // line (a convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            int cx = gr.x + gr.w / 2;
            party.x = 2 * cx - party.x;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s shifts - the walls flex!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SLIDING) {
            // R135: the floor tilts - the company is
            // shoved to a random edge tile of the room
            // (a convention; the print gives no mechanics)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            int side = (int)rng.below((uint32_t)4);
            int nx = 0, ny = 0;
            if (side == 0) {
                nx = gr.x;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 1) {
                nx = gr.x + gr.w - 1;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 2) {
                ny = gr.y;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            } else {
                ny = gr.y + gr.h - 1;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            }
            party.x = nx;
            party.y = ny;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s tilts - the company slides!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SHOOTS ||
""",
      "state_dungeon.cpp: five geometry branches",
      marker="TA_ONE_WAY) {")

# R135-CHUNK-1-END (code patches above)

patch("regtest.cpp",
"""        // the slices: exactly nineteen mechanical (R132
        // 5 -> 11, R133 11 -> 16, R134 16 -> 19)
""",
"""        // the slices: exactly twenty-four mechanical
        // (R132 5 -> 11, R133 11 -> 16, R134 16 -> 19,
        // R135 19 -> 24)
""",
      "regtest.cpp: R128 audit comment",
      marker="R135 19 -> 24)")

patch("regtest.cpp",
"""            if (mech != 19) ++bad;
""",
"""            if (mech != 24) ++bad;
""",
      "regtest.cpp: all four mech counts 24",
      expect=4,
      marker="mech != 24")

r135_lines = [
"    // ---- R135: room-geometry slice audit ----",
"    // The Appendix H mechanical set grows to",
"    // twenty-four: the R134 nineteen plus one-way,",
"    // pivots, spinning, shifting, and sliding (all",
"    // positional conventions - the print gives no",
"    // mechanics; each moves or commits the company",
"    // within the room rect).",
"    {",
"        int bad = 0;",
"        // exactly twenty-four mechanical of 65",
"        {",
"            int mech = 0;",
"            for (int a = 0;",
"                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)",
"                if (dm::appendixh::trickIsMechanical(a)) ++mech;",
"            if (mech != 24) ++bad;",
"        }",
"        // the R135 five are mechanical",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_ONE_WAY)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_PIVOTS)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_SPINNING)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_SHIFTING)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_SLIDING)) ++bad;",
"        // the unwired geometry stays dressing",
"        if (dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_SLOPING)) ++bad;",
"        if (dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_MOVES)) ++bad;",
"        printf(" + chr(34) + "R135 room-geometry slice audit: bad %d"
        + BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
""]
r135_audit = NL.join(r135_lines)
old_r134_head = "    // ---- R134: deep-effects slice audit ----"
patch("regtest.cpp", old_r134_head + NL,
      r135_audit + NL + old_r134_head + NL,
      "regtest.cpp: R135 audit",
      marker="R135 room-geometry slice audit")

patch("regtest.cpp",
"""        // exactly nineteen mechanical of 65
""",
"""        // exactly twenty-four mechanical of 65 (R135
        // grew it)
""",
      "regtest.cpp: R134 comment 24",
      marker="mechanical of 65 (R135" + NL
             + "        // grew it)")

patch("regtest.cpp",
"""        // exactly nineteen mechanical of 65 (R134
        // grew it)
""",
"""        // exactly twenty-four mechanical of 65
        // (R135 grew it)
""",
      "regtest.cpp: R133 comment 24",
      marker="of 65" + NL + "        // (R135 grew it)")

patch("regtest.cpp",
"""        // exactly nineteen mechanical of 65 (R134 grew it)
""",
"""        // exactly twenty-four mechanical of 65 (R135 grew it)
""",
      "regtest.cpp: R132 comment 24",
      marker="of 65 (R135 grew it)")

patch("tools/dmg_gap_report.md",
"""      2d6). R132's second-effects slice wires six more
      (the R132 box), R133's five more (the R133 box),
      R134's three deep (the R134 box). The other 46
      attributes stay dressing - documented; their
      effects ride future rounds.
""",
"""      2d6). R132's second-effects slice wires six more
      (the R132 box), R133's five more (the R133 box),
      R134's three deep (the R134 box), R135's five
      geometry (the R135 box). The other 41
      attributes stay dressing - documented; their
      effects ride future rounds.
""",
      "gap report: R128 box 41",
      marker="R135's five" + NL + "      geometry")

patch("tools/dmg_gap_report.md",
"""      The R133 slice wires five more (the R133 box),
      R134's three deep waters (the R134 box). The
      remaining 46 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
""",
"""      The R133 slice wires five more (the R133 box),
      R134's three deep waters (the R134 box), R135's
      five geometry (the R135 box). The
      remaining 41 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
""",
      "gap report: R132 box 41",
      marker="R135's" + NL + "      five geometry")

patch("tools/dmg_gap_report.md",
"""      documented. The R134 slice wires the three deep
      waters (the R134 box). The remaining 46
      attributes stay dressing; their effects ride
      future rounds.
      Pinned by the R133 battery audit; census 51.
""",
"""      documented. The R134 slice wires the three deep
      waters (the R134 box), R135's five geometry
      (the R135 box). The remaining 41
      attributes stay dressing; their effects ride
      future rounds.
      Pinned by the R133 battery audit; census 51.
""",
      "gap report: R133 box 41",
      marker="R135's five geometry")

patch("tools/dmg_gap_report.md",
"""      effects ride future rounds. Pinned by the R134
      battery audit; census 52.

## Out of scope by design
""",
"""      effects ride future rounds. Pinned by the R134
      battery audit; census 52.
- [x] **Appendix H room-geometry slice (the
      positional five)** - CLOSED R135: the mechanical
      set grows 19 -> 24. One-way: the way back seals
      - the company is committed to the room's center.
      Pivots: the room turns a quarter - the company's
      position rotates 90 degrees about the room
      center, clamped inside. Spinning: a full
      half-turn - the position rotates 180 degrees.
      Shifting: the walls flex - the position mirrors
      across the room's center line. Sliding: the floor
      tilts - the company is shoved to a random room
      edge. All five are positional conventions (the
      print gives no mechanics); documented. The
      remaining 41 attributes stay dressing; their
      effects ride future rounds. Pinned by the R135
      battery audit; census 53.

## Out of scope by design
""",
      "gap report: R135 box",
      marker="CLOSED R135: the")

# ---- R135 fails/tail ----
if fails:
    print("R135 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R135 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R135 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
