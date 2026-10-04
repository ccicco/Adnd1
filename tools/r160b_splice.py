# tools/r160b_splice.py - R160b, 1 patch: fix the one
# inverted assertion in the R160 weaponless audit (the
# header is correct; the audit flagged the correct
# pummelAutomaticHit behavior as bad, which aborted the
# battery and cascaded the census).
#
# The R160 audit line:
#   if (rules::pummelAutomaticHit(true) ||
#       !rules::pummelAutomaticHit(false)) ++bad;
# is backwards - it counts a prone/helpless opponent
# (automatic hit, the p.72 print) as bad. The corrected
# line inverts both operands. Nothing else changes.
#
# Idempotent: safe to run twice; the tail ALWAYS prints.
# ZERO backslash characters; no literal apostrophes.
# Commit (with the R160 files): "R160: weaponless combat
# pinned - pummel, grapple, overbear: the three tables
# and modifiers (census 78)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="latin-1") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="latin-1") as f:
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

p1_old = NL.join(['        if (rules::pummelAutomaticHit(true) ||', '            !rules::pummelAutomaticHit(false)) ++bad;'])
p1_new = NL.join(['        if (!rules::pummelAutomaticHit(true) ||', '            rules::pummelAutomaticHit(false)) ++bad;'])
patch("regtest.cpp", p1_old, p1_new,
      "regtest.cpp: R160b inverted-assert fix",
      marker='!rules::pummelAutomaticHit(true)')
assert len(applied) + len(already) == 1

# ---- R160b fails/tail ----
if fails:
    print("R160b splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R160b splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R160b splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R160b note: 1 patch; run preflight again, then commit R160 (census 78)")
