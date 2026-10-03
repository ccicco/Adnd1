#!/usr/bin/env python3
# tools/r134_splice.py - R134 Appendix H deep-effects
# slice: the three deep waters wired (the mechanical
# set grows 16 -> 19; 46 stay dressing).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/appendixgh.h: trickIsMechanical grows to nineteen
#    - wish, gravity greater, polymorph (all conventions;
#    the print gives no figures; the wish stays
#    benevolent - a boon table)
#  - game/state_dungeon.cpp: applyTrick gains the three
#    deep branches (the boon table, the 1d6 crush, the
#    save-or-3d4 reshape)
#  - regtest.cpp: the R128/R132/R133 audits' mechanical
#    count pins update (16 -> 19), the R133 audit's
#    deep-water dressing pins flip to talk-flavor, and
#    the new R134 audit pins the set (census 52)
#  - tools/dmg_gap_report.md: the R128/R132/R133 boxes'
#    dressing counts drop to 46; the R134 box closes
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
"""// convention). The remaining 49 stay dressing; their
// effects ride future rounds.
inline bool trickIsMechanical(int a) {
""",
"""// convention). R134 wires the deep-effects slice:
// wish (a boon table - heal the company, restore a
// random member, or a gold shower; the print gives no
// table, so the rebuild keeps it benevolent), gravity
// greater (the pull doubles - 1d6 crushing on every
// living member, no save), polymorph (a random living
// member saves vs petrification/polymorph or takes 3d4
// reshaping damage). All three are conventions - the
// print gives no figures. The remaining 46 stay
// dressing; their effects ride future rounds.
inline bool trickIsMechanical(int a) {
""",
      "appendixgh.h: deep comment",
      marker="R134 wires the deep-effects slice")

patch("dm/appendixgh.h",
"""           a == TA_COLLAPSING;
}
""",
"""           a == TA_COLLAPSING || a == TA_WISH ||
           a == TA_GRAVITY_GREATER || a == TA_POLYMORPH;
}
""",
      "appendixgh.h: mechanical set 19",
      marker="a == TA_POLYMORPH;")

patch("game/state_dungeon.cpp",
"""        // purse), teleports (intra-level, a random room
        // center), collapsing (save or 2d6, everyone).
""",
"""        // purse), teleports (intra-level, a random room
        // center), collapsing (save or 2d6, everyone).
        // R134: the deep slice - wish (a boon table:
        // heal all, restore one, or gold), gravity
        // greater (1d6 crush, everyone, no save),
        // polymorph (save or 3d4 reshape).
""",
      "state_dungeon.cpp: applyTrick doc",
      marker="R134: the deep slice")

patch("game/state_dungeon.cpp",
"""        } else if (a == dm::appendixh::TA_SHOOTS ||
""",
"""        } else if (a == dm::appendixh::TA_WISH) {
            // R134: the wish-granting echo - a boon table
            // roll (the print gives no table; the rebuild
            // keeps it benevolent)
            int boon = (int)dice.roll(1, 3, 0);
            char buf[192];
            if (boon == 1) {
                for (auto& c : party.members) {
                    if (c.hp > 0) c.hp = c.maxHp;
                }
                snprintf(buf, sizeof buf,
                         "The %s hums - the company's wounds "
                         "close! A wish spent well.",
                         name.c_str());
            } else if (boon == 2) {
                int vi = victimIndex();
                if (vi >= 0) {
                    party.members[vi].hp =
                        party.members[vi].maxHp;
                    snprintf(buf, sizeof buf,
                             "The %s hums - %s is restored!",
                             name.c_str(),
                             party.members[vi].name.c_str());
                } else {
                    snprintf(buf, sizeof buf,
                             "The %s hums - the echo fades.",
                             name.c_str());
                }
            } else {
                int gp = (int)dice.roll(1, 6, 0) * 100;
                party.gold += gp;
                snprintf(buf, sizeof buf,
                         "The %s hums - a shower of %d gp!",
                         name.c_str(), gp);
            }
            log.add(buf);
        } else if (a == dm::appendixh::TA_GRAVITY_GREATER) {
            // R134: the pull doubles - every living member
            // takes 1d6 crushing, no save (the print gives
            // no figure; the convention)
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s drags - the weight doubles!",
                     name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char b2[160];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(b2, sizeof b2,
                             "The crush fells %s (%d)!",
                             c.name.c_str(), dmg);
                } else {
                    snprintf(b2, sizeof b2,
                             "The crush bruises %s for %d.",
                             c.name.c_str(), dmg);
                }
                log.add(b2);
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_POLYMORPH) {
            // R134: the reshaping radiance - a random living
            // member saves vs petrification/polymorph or
            // takes 3d4 reshaping damage (the print gives
            // no figure; the convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_PETRIFY_POLY);
            char buf[192];
            if (rules::attemptSave(dice, target, 0)) {
                snprintf(buf, sizeof buf,
                         "The %s radiates - %s keeps their "
                         "shape.",
                         name.c_str(), c.name.c_str());
            } else {
                int dmg = (int)dice.roll(3, 4, 0);
                c.hp -= dmg;
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(buf, sizeof buf,
                             "The %s reshapes %s - torn "
                             "apart (%d)!",
                             name.c_str(), c.name.c_str(),
                             dmg);
                } else {
                    snprintf(buf, sizeof buf,
                             "The %s reshapes %s for %d - "
                             "they wobble back, changed.",
                             name.c_str(), c.name.c_str(),
                             dmg);
                }
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_SHOOTS ||
""",
      "state_dungeon.cpp: three deep branches",
      marker="TA_WISH) {")

# R134-CHUNK-1-END (code patches above)

patch("regtest.cpp",
"""        // the slices: exactly sixteen mechanical (R132
        // grew the set 5 -> 11, R133 11 -> 16)
""",
"""        // the slices: exactly nineteen mechanical (R132
        // 5 -> 11, R133 11 -> 16, R134 16 -> 19)
""",
      "regtest.cpp: R128 audit comment",
      marker="R134 16 -> 19)")

patch("regtest.cpp",
"""            if (mech != 16) ++bad;
""",
"""            if (mech != 19) ++bad;
""",
      "regtest.cpp: all three mech counts 19",
      expect=3,
      marker="mech != 19")

r134_lines = [
"    // ---- R134: deep-effects slice audit ----",
"    // The deep waters are wired: the R133 sixteen plus",
"    // wish, gravity greater, and polymorph (all",
"    // conventions - the print gives no figures; the",
"    // wish stays benevolent: heal the company, restore",
"    // a member, or a gold shower).",
"    {",
"        int bad = 0;",
"        // exactly nineteen mechanical of 65",
"        {",
"            int mech = 0;",
"            for (int a = 0;",
"                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)",
"                if (dm::appendixh::trickIsMechanical(a)) ++mech;",
"            if (mech != 19) ++bad;",
"        }",
"        // the R134 three are mechanical",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_WISH)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_GRAVITY_GREATER)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_POLYMORPH)) ++bad;",
"        // the talk-flavor set stays dressing",
"        if (dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_TALKS_SMART)) ++bad;",
"        if (dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_SUGGESTS)) ++bad;",
"        printf(" + chr(34) + "R134 deep-effects slice audit: bad %d"
        + BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
""]
r134_audit = NL.join(r134_lines)
old_r133_head = "    // ---- R133: third-effects slice audit ----"
patch("regtest.cpp", old_r133_head + NL,
      r134_audit + NL + old_r133_head + NL,
      "regtest.cpp: R134 audit",
      marker="R134 deep-effects slice audit")

patch("regtest.cpp",
"""        // the deep waters stay dressing (engine limits)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_WISH)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_GREATER)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POLYMORPH)) ++bad;
""",
"""        // the talk-flavor set stays dressing (R134 wired
        // the deep waters: wish, gravity, polymorph)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_SMART)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SUGGESTS)) ++bad;
""",
      "regtest.cpp: R133 pins flip to flavor",
      marker="R134 wired",
      )

patch("regtest.cpp",
"""        // exactly sixteen mechanical of 65
""",
"""        // exactly nineteen mechanical of 65 (R134
        // grew it)
""",
      "regtest.cpp: R133 comment 19",
      marker="of 65 (R134" + NL + "        // grew it)")

patch("regtest.cpp",
"""        // exactly sixteen mechanical of 65 (R133 grew it)
""",
"""        // exactly nineteen mechanical of 65 (R134 grew it)
""",
      "regtest.cpp: R132 comment 19",
      marker="nineteen mechanical of 65 (R134 grew it)")

patch("tools/dmg_gap_report.md",
"""      2d6). R132's second-effects slice wires six more
      (the R132 box), R133's five more (the R133 box).
      The other 49 attributes stay dressing - documented;
      their effects ride future rounds.
""",
"""      2d6). R132's second-effects slice wires six more
      (the R132 box), R133's five more (the R133 box),
      R134's three deep (the R134 box). The other 46
      attributes stay dressing - documented; their
      effects ride future rounds.
""",
      "gap report: R128 box 46",
      marker="R134's three deep (the R134 box). The other 46")

patch("tools/dmg_gap_report.md",
"""      The R133 slice wires five more (the R133 box).
      The remaining 49 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
""",
"""      The R133 slice wires five more (the R133 box),
      R134's three deep waters (the R134 box). The
      remaining 46 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
""",
      "gap report: R132 box 46",
      marker="R134's three deep waters (the R134 box)")

patch("tools/dmg_gap_report.md",
"""      documented. The remaining 49 attributes stay
      dressing; their effects ride future rounds.
      Pinned by the R133 battery audit; census 51.
""",
"""      documented. The R134 slice wires the three deep
      waters (the R134 box). The remaining 46
      attributes stay dressing; their effects ride
      future rounds.
      Pinned by the R133 battery audit; census 51.
""",
      "gap report: R133 box 46",
      marker="The R134 slice wires the three deep")

patch("tools/dmg_gap_report.md",
"""      Pinned by the R133 battery audit; census 51.

## Out of scope by design
""",
"""      Pinned by the R133 battery audit; census 51.
- [x] **Appendix H deep-effects slice (the deep
      waters)** - CLOSED R134: the mechanical set
      grows 16 -> 19. Wish: a boon table roll - the
      whole company healed, or a random living member
      restored, or a gold shower (1d6 x 100 gp).
      Gravity greater: the pull doubles - every living
      member takes 1d6 crushing, no save. Polymorph:
      a random living member saves vs
      petrification/polymorph or takes 3d4 reshaping
      damage. All three are rebuild conventions (the
      print gives no figures); documented. The
      remaining 46 attributes stay dressing; their
      effects ride future rounds. Pinned by the R134
      battery audit; census 52.

## Out of scope by design
""",
      "gap report: R134 box",
      marker="CLOSED R134: the")

# ---- R134 fails/tail ----
if fails:
    print("R134 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R134 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R134 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
