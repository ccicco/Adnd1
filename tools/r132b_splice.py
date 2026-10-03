#!/usr/bin/python3
# tools/r132b_splice.py - R132b repair (three things went
# wrong with the r132 delivery, all recoverable):
#  (1) paste B never landed - the r132 audit and the two
#      gap-report patches ride here
#  (2) paste A's tail print lives in paste B, so the two
#      paste-A-only runs were SILENT (the header promised
#      "this tail ALWAYS prints" - a chunking flaw; the
#      R133 convention: paste A ends with its own tail)
#  (3) the terminal mangled the lambda - line 283 reads
#      "auto victimIndex = & -> int {" where "& -> int {"
#      was written; this rewrites the line whole and then
#      SELF-VERIFIES the brackets (if the paste mangles
#      them again, the post-check FAILS and nothing runs)
# Idempotent: safe to run twice.
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
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

def check(p, needle, expect, tag):
    n = rd(p).count(needle)
    if n != expect:
        fails.append(tag + ": count " + str(n)
                     + " (expected " + str(expect) + ")")

def check_range(p, needle, lo, hi, tag):
    n = rd(p).count(needle)
    if n < lo or n > hi:
        fails.append(tag + ": count " + str(n)
                     + " (expected " + str(lo) + ".." + str(hi)
                     + ")")

# ---- sanity gates on the paste-A state ----
# (ranges, not exact counts: the B2 audit patch adds a
# second "mech != 11" occurrence, so a second run of this
# splice must still pass its own gates)
check("dm/appendixgh.h", "R132 wires the", 1,
      "gate: mechanical set 11")
check("game/state_dungeon.cpp", "TA_AGES) {", 1,
      "gate: six branches")
check("game/state_dungeon.cpp", "victimIndex();", 3,
      "gate: three victim picks")
check("game/state_dungeon.cpp",
      "applyMagicalAging(c, party.careerDays, 10);", 1,
      "gate: aging branch")
check_range("regtest.cpp", "mech != 11", 1, 2,
      "gate: R128/R132 count pins")
check("regtest.cpp", "counterfeit joined the mechanical set", 1,
      "gate: counterfeit flip")
if fails:
    print("R132b splice: FAIL - sanity gates tripped; do NOT")
    print("  commit. Details:")
    for f in fails:
        print("  " + f)
    print("  Paste me this output plus the first 20 and last")
    print("  20 lines of your r132_splice.py.")
    sys.exit(1)

# ---- B1: the mangled lambda line, rewritten whole ----
p = "game/state_dungeon.cpp"
s = rd(p)
lines = s.split("\n")
hits = [i for i, l in enumerate(lines)
        if "auto victimIndex =" in l]
if s.count("& -> int {") >= 1:
    already.append("state_dungeon.cpp: lambda repair")
elif len(hits) != 1:
    fails.append("state_dungeon.cpp: lambda repair: "
                 + str(len(hits)) + " candidate lines (expected 1)")
else:
    lines[hits[0]] = "        auto victimIndex = & -> int {"
    wr(p, "\n".join(lines))
    applied.append("state_dungeon.cpp: lambda repair")

# ---- B2: the R132 audit (paste B's first patch) ----
patch("regtest.cpp",
"""    // ---- R129: caster aging audit ----
""",
"""    // ---- R132: second-effects slice audit ----
    // The Appendix H mechanical set grows to eleven: the
    // R128 five plus ages, flesh to stone, both shocks,
    // counterfeit coins, and takes/steals (print sources:
    // the altar ages 10 years, the face petrifies on a
    // failed save, the pedestal shocks 5-50 hp;
    // counterfeit crumbles worthless; takes/steals is a
    // convention - the print gives no figure).
    {
        int bad = 0;
        // exactly eleven mechanical of 65
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 11) ++bad;
        }
        // the R132 six are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_AGES)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_FLESH_TO_STONE)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHOCK_METAL)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHOCK_MAGIC)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COUNTERFEIT)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TAKES)) ++bad;
        // the deep waters stay dressing (engine limits)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_WISH)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_GREATER)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_NONSENSE)) ++bad;
        printf("R132 second-effects slice audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R129: caster aging audit ----
""",
      "regtest.cpp: R132 audit",
      marker="R132 second-effects slice audit")

# ---- B3: the R128 box 54 (paste B's second patch) ----
patch("tools/dmg_gap_report.md",
"""      2d6). The other 60 attributes stay dressing -
      documented; their effects ride future rounds.
""",
"""      2d6). R132's second-effects slice wires six more
      (the R132 box). The other 54 attributes stay
      dressing - documented; their effects ride future
      rounds.
""",
      "gap report: R128 box 54",
      marker="R132's second-effects slice wires six more")

# ---- B4: the R132 box (paste B's third patch) ----
patch("tools/dmg_gap_report.md",
"""      battery audit; census 49.

## Out of scope by design
""",
"""      battery audit; census 49.
- [x] **Appendix H second-effects slice (the R128
      dressing debt, first six)** - CLOSED R132: the
      mechanical set grows 5 -> 11. Ages: 10 years on
      a random living member (the print's altar
      example, via the R115 magical-aging shape).
      Flesh to stone: save vs petrification or turned
      to stone (the print's face example - save
      versus magic or be transformed). Electrical
      shock, metallic or magical: 5-50 hp on a
      random living member, no save (the print's
      pedestal example prints none). Releases
      counterfeit: a shower of coins that crumbles
      worthless - nothing gained. Takes/steals:
      10-60 gp from the purse (the print gives no
      figure - a rebuild convention, documented).
      The remaining 54 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.

## Out of scope by design
""",
      "gap report: R132 box",
      marker="CLOSED R132: the")

# ---- the bracket post-check (the paste-mangle guard) ----
if "auto victimIndex = & -> int {" not in rd(p):
    fails.append("state_dungeon.cpp: POST-CHECK - the lambda"
                 " line still lacks & - the paste mangled"
                 " it again; do NOT commit")

# ---- R132b fails/tail ----
if fails:
    print("R132b splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R132b splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R132b splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
