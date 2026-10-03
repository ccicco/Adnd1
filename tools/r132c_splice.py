#!/usr/bin/python3
# tools/r132c_splice.py - R132c: the lambda bracket fix,
# immune to the paste-mangle. Root cause of both REDs:
# the bracket-ampersand-bracket-parens sequence (the
# lambda capture clause) is assembled as a markdown-style
# link by the chat renderer and EATEN on terminal copy -
# it landed as a bare ampersand in the r132 paste AND
# inside the r132b repair itself (the r132b idempotency
# check and post-check contained the same sequence, so
# the mangled splice blessed the mangled line - "applied
# 3, already 1").
# This splice contains NO bracket literal at all: the
# target line is assembled from chr(91) + "&" + chr(93),
# so there is nothing for the renderer to eat.
# Idempotent: safe to run twice; the tail ALWAYS prints.
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

LB = chr(91)    # [
RB = chr(93)    # ]
GOOD = "        auto victimIndex = " + LB + "&" + RB + "() -> int {"
BAD_PREFIX = "auto victimIndex ="

applied, already, fails = [], [], []

p = "game/state_dungeon.cpp"
s = rd(p)
if GOOD in s:
    already.append("state_dungeon.cpp: lambda line")
else:
    lines = s.split("\n")
    hits = [i for i, l in enumerate(lines) if BAD_PREFIX in l]
    if len(hits) != 1:
        fails.append("state_dungeon.cpp: lambda line: found "
                     + str(len(hits)) + " candidate lines"
                     + " (expected 1) - paste me lines 280-286"
                     + " of game/state_dungeon.cpp")
    else:
        lines[hits[0]] = GOOD
        wr(p, "\n".join(lines))
        applied.append("state_dungeon.cpp: lambda line")

# ---- the post-check (assembled, mangle-immune) ----
if GOOD not in rd(p):
    fails.append("POST-CHECK: the lambda line is still not"
                 " the assembled-good form; do NOT commit")

# ---- state verification (prints, non-fatal) ----
reg = rd("regtest.cpp")
print("verify: R132 audit present:",
      "R132 second-effects slice audit" in reg)
print("verify: mech-11 pins:", reg.count("mech != 11"))
gap = rd("tools/dmg_gap_report.md")
print("verify: R132 box present:", "CLOSED R132: the" in gap)
print("verify: R128 box 54:", "R132's second-effects slice"
      " wires six more" in gap)

if fails:
    print("R132c splice: FAIL - " + str(len(fails)) + " item(s):")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R132c splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R132c splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
