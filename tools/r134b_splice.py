#!/usr/bin/env python3
# tools/r134b_splice.py - R134 repair: the R132 audit
# pinned the deep waters as dressing (wish and gravity
# greater), but R134 wired exactly those two - so the
# R132 audit read bad 2. This splice flips the R132
# audit's dressing pins to flavor attributes (nonsense,
# poetry, points) that stay dressing, and updates its
# comment. The R134 and R133 audits are untouched.
# Idempotent: safe to run twice. Zero backslashes.
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

patch("regtest.cpp",
"""        // the deep waters stay dressing (engine limits)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_WISH)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_GREATER)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_NONSENSE)) ++bad;
""",
"""        // the flavor set stays dressing (R134 wired the
        // deep waters: wish and gravity are mechanical)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_NONSENSE)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_POETRY)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POINTS)) ++bad;
""",
      "regtest.cpp: R132 pins flip to flavor",
      marker="wish and gravity are mechanical")

# ---- R134b fails/tail ----
if fails:
    print("R134b splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R134b splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R134b splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
