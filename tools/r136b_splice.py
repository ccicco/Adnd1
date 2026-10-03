#!/usr/bin/env python3
# tools/r136b_splice.py - R136 repair: one patch of the
# R136 batch failed - the doc-comment anchor read
# "floor tilts." but the live line is "floor tilts)."
# (a one-character typo in the authored anchor; the
# splice guard caught it). The other 14 patches landed
# and main is committed - only the applyTrick doc
# comment is missing its R136 line. This splice adds
# it. Idempotent. Zero backslashes.
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, marker):
    s = rd(p)
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != 1:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected 1)")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

patch("game/state_dungeon.cpp",
"""        // shifting (the walls flex), sliding (the
        // floor tilts).
        if (roomIndex < 0 ||
""",
"""        // shifting (the walls flex), sliding (the
        // floor tilts). R136: the odds-and-ends slice
        // - rising (the flood), suspends (the float),
        // appearing (the melt-away), invisible (the
        // unseen strike), gaseous (the gas cloud).
        if (roomIndex < 0 ||
""",
      "state_dungeon.cpp: R136 doc line",
      marker="R136: the odds-and-ends slice")

# ---- R136b fails/tail ----
if fails:
    print("R136b splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R136b splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R136b splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
