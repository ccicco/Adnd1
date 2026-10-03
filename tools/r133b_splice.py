#!/usr/bin/env python3
# tools/r133b_splice.py - R133 repair: the terminal ate
# one backslash in the r133 paste, so the R133 audit's
# printf line reached regtest.cpp with a REAL line
# break inside the C string and the build went RED.
# This splice repairs that one line in regtest.cpp and
# the matching line inside tools/r133_splice.py (so the
# tree stays consistent for posterity). It contains no
# backslash characters anywhere - the escaped newline is
# assembled from chr(92), which nothing can eat.
# Idempotent: safe to run twice.
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

# the good C line: the printf with a proper escaped
# newline, all on one line
good_c = ('        printf("R133 third-effects slice audit: '
          'bad %d' + BS + 'n", bad);' + NL)
# the mangled C text: the string broke across a real
# newline (what the compiler choked on)
bad_c = ('        printf("R133 third-effects slice audit: '
         'bad %d' + NL + '", bad);' + NL)

patch("regtest.cpp", bad_c, good_c,
      "regtest.cpp: R133 printf repaired",
      marker=good_c.rstrip(NL))

# repair r133_splice.py's own emitted printf: its double
# backslash arrived as a single one, so the emitted C
# string broke; restore the doubled escape
splice_bad = ('printf("R133 third-effects slice audit: bad '
              '%d' + BS + 'n", bad);' + NL)
splice_good = ('printf("R133 third-effects slice audit: bad '
               '%d' + BS + BS + 'n", bad);' + NL)
patch("tools/r133_splice.py", splice_bad, splice_good,
      "r133_splice.py: source printf repaired",
      marker=splice_good.rstrip(NL))

# ---- R133b fails/tail ----
if fails:
    print("R133b splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R133b splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R133b splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
