# tools/r167b_splice.py - R167b, 1 patch: the R167
# audit fix. The R167 splice shipped a WRONG
# expectation row in its own audit: the d100 probe
# table kWantRow listed 5/6/7/8 for the probes
# 13/19/41/43, but the disease.h row mapping is
# correct - 13 reads eyes (row 6), 19 gastro (row 7),
# 41 generative organs (row 8), 43 joints (row 9).
# Exactly the reported bad 4; the header data is
# right and this patch corrects only the audit
# expectation line. The R160b precedent.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R167: PC disease and parasitic infestation
# pinned - the pp.13-14 contraction, occurrence and
# severity tables (census 85)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
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

p1_old = NL.join(['        static const int kWantRow[12] = {', '            0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 15'])
p1_new = NL.join(['        static const int kWantRow[12] = {', '            0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 12, 15'])
patch("regtest.cpp", p1_old, p1_new,
      "regtest.cpp: R167 audit probe row corrected",
      marker='0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 12, 15')
assert len(applied) + len(already) == 1

# ---- R167b fails/tail ----
if fails:
    print("R167b splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 1:
    print("R167b splice: FAIL - expected 1 patch, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R167b splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R167b splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R167b note: 1 patch; the R167 audit expectation row corrected; then preflight - expect R167 disease and infestation audit: bad 0 and AUDIT CENSUS: 85")
