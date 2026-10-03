#!/usr/bin/env python3
# tools/r136_splice.py - R136 Appendix H odds-and-ends
# slice: five stragglers wired (the mechanical set
# grows 24 -> 29; 36 stay dressing).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/appendixgh.h: trickIsMechanical grows to
#    twenty-nine - rising, suspends, appearing,
#    invisible, gaseous (all conventions - the print
#    gives no figures)
#  - game/state_dungeon.cpp: applyTrick gains the five
#    branches (the flood, the float, the melt-away,
#    the unseen strike, the gas cloud)
#  - regtest.cpp: the five audits' mechanical count pins
#    update (24 -> 29), four audit comments update, and
#    the new R136 audit pins the set (census 54)
#  - tools/dmg_gap_report.md: the R128/R132/R133/R134
#    boxes' dressing counts drop to 36; the R136 box
#    closes
# Anti-magic STAYS dressing: an honest suppression zone
# needs a magic-use hook the engine does not expose yet;
# the R136 audit pins it as dressing with TA_ENRAGES.
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
"""// room edge). All five are positional conventions -
// the print gives no mechanics. The remaining 41 stay
// dressing; their effects ride future rounds.
inline bool trickIsMechanical(int a) {
""",
"""// room edge). All five are positional conventions -
// the print gives no mechanics. R136 wires the
// odds-and-ends slice: rising (water floods the room -
// every living member saves vs death/poison or takes
// 1d6), suspends (gravity nil - the company floats to
// a random interior tile), appearing (the feature
// manifests, startles, and melts away - the room's
// trick is spent), invisible (an unseen strike - 1d6
// on a random living member, no save), gaseous (a
// poison cloud - every living member saves vs
// death/poison or takes 1d6). All five are
// conventions - the print gives no figures. The
// remaining 36 stay dressing; their effects ride
// future rounds.
inline bool trickIsMechanical(int a) {
""",
      "appendixgh.h: odds comment",
      marker="R136 wires the")

patch("dm/appendixgh.h",
"""           a == TA_SPINNING || a == TA_SHIFTING ||
           a == TA_SLIDING;
}
""",
"""           a == TA_SPINNING || a == TA_SHIFTING ||
           a == TA_SLIDING || a == TA_RISING ||
           a == TA_SUSPENDS || a == TA_APPEARING ||
           a == TA_INVISIBLE || a == TA_GASEOUS;
}
""",
      "appendixgh.h: mechanical set 29",
      marker="a == TA_GASEOUS;")

patch("game/state_dungeon.cpp",
"""        // room-geometry slice - one-way (the way
        // seals), pivots/spinning (the room turns),
        // shifting (the walls flex), sliding (the
        // floor tilts.
""",
"""        // room-geometry slice - one-way (the way
        // seals), pivots/spinning (the room turns),
        // shifting (the walls flex), sliding (the
        // floor tilts). R136: the odds-and-ends slice
        // - rising (the flood), suspends (the float),
        // appearing (the melt-away), invisible (the
        // unseen strike), gaseous (the gas cloud).
""",
      "state_dungeon.cpp: applyTrick doc",
      marker="R136: the odds-and-ends slice")

patch("game/state_dungeon.cpp",
"""        } else if (a == dm::appendixh::TA_ONE_WAY) {
""",
"""        } else if (a == dm::appendixh::TA_RISING) {
            // R136: the water rises - every living
            // member saves vs death/poison or takes 1d6
            // (the print gives no figure; the trap
            // shape)
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s gurgles - water rises fast!",
                     name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int target = rules::saveTarget(
                    c.classIndex, c.level,
                    rules::SAVE_DEATH_POISON);
                if (rules::attemptSave(dice, target, 0)) {
                    char b2[160];
                    snprintf(b2, sizeof b2,
                             "%s keeps their footing.",
                             c.name.c_str());
                    log.add(b2);
                    continue;
                }
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char b2[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(b2, sizeof b2,
                             "The flood drowns %s (%d) - "
                             "%s falls!",
                             c.name.c_str(), dmg,
                             c.name.c_str());
                } else {
                    snprintf(b2, sizeof b2,
                             "The flood batters %s for %d.",
                             c.name.c_str(), dmg);
                }
                log.add(b2);
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_SUSPENDS) {
            // R136: gravity nil - the company floats up
            // and drifts to a random interior tile (the
            // print gives no mechanics; a convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            party.x = gr.x +
                (int)rng.below((uint32_t)gr.w);
            party.y = gr.y +
                (int)rng.below((uint32_t)gr.h);
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s hums - the company floats!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_APPEARING) {
            // R136: the feature manifests before the
            // company - and melts away; the room's trick
            // is spent (a convention; the print gives no
            // mechanics)
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s appears - and melts away. "
                     "The room falls still.",
                     name.c_str());
            log.add(buf);
            room.trickFeature = -1;
        } else if (a == dm::appendixh::TA_INVISIBLE) {
            // R136: an unseen strike - a random living
            // member takes 1d6, no save (the print gives
            // no figure; the convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(1, 6, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "Something unseen strikes %s for "
                         "%d - %s falls!",
                         c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "Something unseen strikes %s for "
                         "%d.",
                         c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_GASEOUS) {
            // R136: a poison cloud fills the room - every
            // living member saves vs death/poison or
            // takes 1d6 (the print gives no figure; the
            // trap shape)
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s hisses - a sickly cloud "
                     "spreads!",
                     name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int target = rules::saveTarget(
                    c.classIndex, c.level,
                    rules::SAVE_DEATH_POISON);
                if (rules::attemptSave(dice, target, 0)) {
                    char b2[160];
                    snprintf(b2, sizeof b2,
                             "%s breathes through it.",
                             c.name.c_str());
                    log.add(b2);
                    continue;
                }
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char b2[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(b2, sizeof b2,
                             "The cloud chokes %s (%d) - "
                             "%s falls!",
                             c.name.c_str(), dmg,
                             c.name.c_str());
                } else {
                    snprintf(b2, sizeof b2,
                             "The cloud burns %s for %d.",
                             c.name.c_str(), dmg);
                }
                log.add(b2);
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_ONE_WAY) {
""",
      "state_dungeon.cpp: five odds branches",
      marker="TA_RISING) {")

# R136-CHUNK-1-END (code patches above)

patch("regtest.cpp",
"""        // the slices: exactly twenty-four mechanical
        // (R132 5 -> 11, R133 11 -> 16, R134 16 -> 19,
        // R135 19 -> 24)
""",
"""        // the slices: exactly twenty-nine mechanical
        // (R132 5 -> 11, R133 11 -> 16, R134 16 -> 19,
        // R135 19 -> 24, R136 24 -> 29)
""",
      "regtest.cpp: R128 audit comment",
      marker="R136 24 -> 29)")

patch("regtest.cpp",
"""            if (mech != 24) ++bad;
""",
"""            if (mech != 29) ++bad;
""",
      "regtest.cpp: all five mech counts 29",
      expect=5,
      marker="mech != 29")

patch("regtest.cpp",
"""        // exactly twenty-four mechanical of 65
        {
""",
"""        // exactly twenty-nine mechanical of 65
        {
""",
      "regtest.cpp: R135 comment 29",
      marker="twenty-nine mechanical of 65" + NL
             + "        {")

patch("regtest.cpp",
"""        // exactly twenty-four mechanical of 65 (R135
        // grew it)
""",
"""        // exactly twenty-nine mechanical of 65 (R135
        // and R136 grew it)
""",
      "regtest.cpp: R134 comment 29",
      marker="of 65 (R135" + NL
             + "        // and R136 grew it)")

patch("regtest.cpp",
"""        // exactly twenty-four mechanical of 65
        // (R135 grew it)
""",
"""        // exactly twenty-nine mechanical of 65
        // (R135 and R136 grew it)
""",
      "regtest.cpp: R133 comment 29",
      marker="// (R135 and R136 grew it)")

patch("regtest.cpp",
"""        // exactly twenty-four mechanical of 65 (R135 grew it)
""",
"""        // exactly twenty-nine mechanical of 65 (R135 and R136 grew it)
""",
      "regtest.cpp: R132 comment 29",
      marker="of 65 (R135 and R136 grew it)")

r136_lines = [
"    // ---- R136: odds-and-ends slice audit ----",
"    // The stragglers are wired: the R135 twenty-four",
"    // plus rising, suspends, appearing, invisible, and",
"    // gaseous (all conventions - the print gives no",
"    // figures). Anti-magic STAYS dressing: an honest",
"    // suppression zone needs a magic-use hook the",
"    // engine does not expose yet.",
"    {",
"        int bad = 0;",
"        // exactly twenty-nine mechanical of 65 (the",
"        // R136 five: rising, suspends, appearing,",
"        // invisible, gaseous)",
"        {",
"            int mech = 0;",
"            for (int a = 0;",
"                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)",
"                if (dm::appendixh::trickIsMechanical(a)) ++mech;",
"            if (mech != 29) ++bad;",
"        }",
"        // the R136 five are mechanical",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_RISING)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_SUSPENDS)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_APPEARING)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_INVISIBLE)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_GASEOUS)) ++bad;",
"        // the unwired deeps stay dressing",
"        if (dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_ANTI_MAGIC)) ++bad;",
"        if (dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_ENRAGES)) ++bad;",
"        printf(" + chr(34) + "R136 odds-and-ends slice audit: bad %d"
        + BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
""]
r136_audit = NL.join(r136_lines)
old_r135_head = "    // ---- R135: room-geometry slice audit ----"
patch("regtest.cpp", old_r135_head + NL,
      r136_audit + NL + old_r135_head + NL,
      "regtest.cpp: R136 audit",
      marker="R136 odds-and-ends slice audit")

patch("tools/dmg_gap_report.md",
"""      2d6). R132's second-effects slice wires six more
      (the R132 box), R133's five more (the R133 box),
      R134's three deep (the R134 box), R135's five
      geometry (the R135 box). The other 41
      attributes stay dressing - documented; their
      effects ride future rounds.
""",
"""      2d6). R132's second-effects slice wires six more
      (the R132 box), R133's five more (the R133 box),
      R134's three deep (the R134 box), R135's five
      geometry (the R135 box), R136's five
      odds-and-ends (the R136 box). The other 36
      attributes stay dressing - documented; their
      effects ride future rounds.
""",
      "gap report: R128 box 36",
      marker="R136's five" + NL + "      odds-and-ends")

patch("tools/dmg_gap_report.md",
"""      The R133 slice wires five more (the R133 box),
      R134's three deep waters (the R134 box), R135's
      five geometry (the R135 box). The
      remaining 41 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
""",
"""      The R133 slice wires five more (the R133 box),
      R134's three deep waters (the R134 box), R135's
      five geometry (the R135 box), R136's five
      odds-and-ends (the R136 box). The
      remaining 36 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
""",
      "gap report: R132 box 36",
      marker="R136's five" + NL + "      odds-and-ends (the R136 box). The")

patch("tools/dmg_gap_report.md",
"""      documented. The R134 slice wires the three deep
      waters (the R134 box), R135's five geometry
      (the R135 box). The remaining 41
      attributes stay dressing; their effects ride
      future rounds.
      Pinned by the R133 battery audit; census 51.
""",
"""      documented. The R134 slice wires the three deep
      waters (the R134 box), R135's five geometry
      (the R135 box), R136's five odds-and-ends
      (the R136 box). The remaining 36
      attributes stay dressing; their effects ride
      future rounds.
      Pinned by the R133 battery audit; census 51.
""",
      "gap report: R133 box 36",
      marker="R136's five odds-and-ends")

patch("tools/dmg_gap_report.md",
"""      effects ride future rounds. Pinned by the R135
      battery audit; census 53.

## Out of scope by design
""",
"""      effects ride future rounds. Pinned by the R135
      battery audit; census 53.
- [x] **Appendix H odds-and-ends slice (the
      stragglers)** - CLOSED R136: the mechanical set
      grows 24 -> 29. Rising: water floods the room -
      every living member saves vs death/poison or
      takes 1d6. Suspends: gravity nil - the company
      floats and drifts to a random interior tile.
      Appearing: the feature manifests, startles, and
      melts away - the room's trick is spent.
      Invisible: an unseen strike - 1d6 on a random
      living member, no save. Gaseous: a poison cloud -
      every living member saves vs death/poison or
      takes 1d6. Anti-magic STAYS dressing (an honest
      suppression zone needs a magic-use hook the
      engine does not expose yet); documented. All five
      wired effects are rebuild conventions (the
      print gives no figures). The remaining 36
      attributes stay dressing; their effects ride
      future rounds. Pinned by the R136 battery audit;
      census 54.

## Out of scope by design
""",
      "gap report: R136 box",
      marker="CLOSED R136: the")

# ---- R136 fails/tail ----
if fails:
    print("R136 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R136 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R136 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
