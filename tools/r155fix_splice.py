# tools/r155fix_splice.py - R155 fix, 1 patch: the R155
# audit read t.saveAsBonus, but TargetDesc has no such
# member - the monster die bonus rides the existing
# saveBonus (what asTarget sets for monsters). The
# preflight compile caught it; this pins the audit line.
# Idempotent; the tail ALWAYS prints. ZERO backslashes;
# no apostrophe in any content string.
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="latin-1") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="latin-1") as f:
        f.write(s)

old = "t.saveAsBonus != 2 || t.saveAsLevels[0] != 12)"
new = "t.saveBonus != 2 || t.saveAsLevels[0] != 12)"
p = "regtest.cpp"
s = rd(p)
if "saveBonus != 2 || t.saveAsLevels[0] != 12)" in s:
    already.append("regtest.cpp: audit saveBonus fix")
else:
    n = s.count(old)
    if n != 1:
        fails.append("regtest.cpp: anchor count " + str(n)
                     + " (expected 1)")
    else:
        wr(p, s.replace(old, new))
        applied.append("regtest.cpp: audit saveBonus fix")
assert len(applied) + len(already) == 1
if fails:
    print("R155fix splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R155fix splice: ALL OK (applied 0, already 1)")
else:
    print("R155fix splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R155fix note: run preflight again, then the census-73")
print("commit")
