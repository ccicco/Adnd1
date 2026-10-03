#!/usr/bin/python3
# tools/r130c_splice.py - R130c one-pin repair: the r130b
# audit pinned MU L12 6th-level slot at 4, but the print
# gives 1 (L12 = {4,4,4,4,4,1}); the 4 belongs to the 5th
# column. Idempotent; a silent run means the paste was
# truncated - this tail ALWAYS prints.
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

applied, already, fails = [], [], []

patch_line = ('        if (spells::spellSlots(spells::SPELL_MU, 12, 6)'
              ' != 4) ++bad;')
new_lines = (
    '        if (spells::spellSlots(spells::SPELL_MU, 12, 5)'
    ' != 4) ++bad;\n'
    '        // R130c: the L12 print gives ONE 6th-level slot\n'
    '        // (L12 = 4,4,4,4,4,1) - the r130b pin read the\n'
    '        // 5th column twice\n'
    '        if (spells::spellSlots(spells::SPELL_MU, 12, 6)'
    ' != 1) ++bad;')

s = rd("regtest.cpp")
if "R130c: the L12 print gives ONE" in s:
    already.append("regtest.cpp: L12 6th pin repair")
elif s.count(patch_line) != 1:
    fails.append("regtest.cpp: L12 6th pin repair: anchor count "
                 + str(s.count(patch_line)) + " (expected 1)")
else:
    wr("regtest.cpp", s.replace(patch_line, new_lines))
    applied.append("regtest.cpp: L12 6th pin repair")

if fails:
    print("R130c splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R130c splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R130c splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
