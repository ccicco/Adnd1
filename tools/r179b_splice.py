#!/usr/bin/env python3
# tools/r179b_splice.py - R179b: the registry
# include - the R179 build fix.
#
# The R179 land compiled the created header fine but
# PREFLIGHT FAILED: regtest.cpp references
# rules::subclassCount() and kin without including
# the new header - 20 errors, and the census failed
# downstream (no binary, no battery output at all).
# The R179 acid test verified the header in
# isolation and never syntax-checked regtest against
# it - the gap is recorded as a lesson.
#
#   (a) regtest.cpp - the include block gains
#       rules/subclasses.h (after the R173 secondary
#       include, the R179 comment).
#   (b) tools/dmg_gap_report.md - the round-note
#       chain gains the R179b note with the lesson.
#
# Census stays 96 (no new audit - the R179 audit
# stands; it was never executable until now).
#
# Idempotent: safe to run twice; a silent run means
# the paste was truncated - this tail ALWAYS prints.
# An assert follows EVERY patch. ZERO backslashes,
# no literal apostrophe in content strings.
# Commit: "R179b: the registry include - the R179
# build fix (census 96)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
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

# ---- (1) the include ----
p1_old = NL.join([
    '#include "rules/secondary.h"  // R173: p.12 secondary skills',
])
p1_new = NL.join([
    '#include "rules/secondary.h"  // R173: p.12 secondary skills',
    '#include "rules/subclasses.h"  // R179: the subclass registry',
])

# ---- (2) the dmg round note ----
p2_old = NL.join([
    '96. The wiring rounds follow (qualification,',
    'attacks, spells, multi-class, the bard).',
])
p2_new = NL.join([
    '96. The wiring rounds follow (qualification,',
    'attacks, spells, multi-class, the bard).',
    'R179b FIXED the R179 build: regtest.cpp now',
    'includes rules/subclasses.h (the R179 audit',
    'referenced the registry without the include -',
    'preflight failed with 20 errors and the census',
    'failed downstream of the missing binary).',
    'LESSON: the acid test must SYNTAX-CHECK the',
    'touched TUs (clang++ -fsyntax-only) whenever a',
    'round adds code that regtest includes - a',
    'header verified in isolation is not a build.',
    'Census stays 96 (no new audit).',
])

# ---- run ----
patch("regtest.cpp", p1_old, p1_new,
      "regtest.cpp: the subclasses include",
      marker='#include "rules/subclasses.h"')
assert len(applied) + len(already) == 1

patch("tools/dmg_gap_report.md", p2_old, p2_new,
      "dmg report: R179b round note",
      marker="R179b FIXED the R179 build")
assert len(applied) + len(already) == 2

# ---- R179b fails/tail ----
if fails:
    print("R179b splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 2:
    print("R179b splice: FAIL - expected 2 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R179b splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R179b splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R179b note: 2 patches; the R179 audit now builds;")
print("census 96 (no new audit).")
print("commit: R179b: the registry include - the R179 build")
print("fix (census 96)")

