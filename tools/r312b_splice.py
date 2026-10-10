#!/usr/bin/env python3
# tools/r312b_splice.py - R312b: the
# missing underwater include (the R312
# preflight RED fix, BEFORE any push - no
# recovery ritual needed, the land is
# untouched).
#
# The one compile error: game/state_dungeon.cpp
# calls rules::uwSurfaceDrownPct (the R311
# drown pin) inside enterWater, but the TU
# includes only rules/swimcross.h - appstate.h
# does NOT carry underwater.h transitively.
# LESSON (the R179/R180b rule, generalized):
# every rules:: accessor the new code calls
# needs its header in the TU being edited;
# grep the include chain, never assume
# transitivity. The fix: ONE include line.
#
# One patch; idempotent; the tail ALWAYS
# prints; ZERO literal backslash bytes; no
# apostrophe inside single-quoted content.
# The R312 census is unchanged (237) and
# rules/swimcross.h is untouched (md5
# 8b07825b2ff60746f5bd0fe1d3688ea0 still the
# real gate). Commit rides the R312 commit:
# "R312: the flooded crossing wired
# (census 237)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit):
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln
        assert Q not in ln, 'apostrophe in content'

# ---- the include line ----
SD_OLD = NL.join([
    '#include "rules/swimcross.h"  // R312: the flooded crossing',
])
SD_NEW = NL.join([
    '#include "rules/swimcross.h"  // R312: the flooded crossing',
    '#include "rules/underwater.h"  // R311: the drown percent',
])
clean(SD_OLD, 78)
clean(SD_NEW, 78)

p = 'game/state_dungeon.cpp'
s = rd(p)
if '#include "rules/underwater.h"' in s:
    already.append('state_dungeon.cpp: the include')
else:
    assert s.count(SD_OLD) == 1, 'include anchor not unique'
    assert 'underwater.h' not in s, 'include marker collision'
    s = s.replace(SD_OLD, SD_NEW)
    wr(p, s)
    applied.append('state_dungeon.cpp: the include')

s = rd(p)
assert s.count('#include "rules/underwater.h"') == 1, 'b include'
assert s.count('#include "rules/swimcross.h"') == 1, 'b swimcross'
assert s.count('#include "rules/doorforce.h"') == 1, 'b anchor'
assert s.count('uwSurfaceDrownPct') == 1, 'b the call site'
assert s.count('AppState::enterWater') == 1, 'b site intact'
assert s.count('{') == s.count('}'), 'b brace balance'
assert s.count('(') == s.count(')'), 'b paren balance'
assert len(applied) + len(already) == 1, 'patch count wrong'

# ---- R312b fails/tail ----
if fails:
    print('R312b splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 1:
    print('R312b splice: FAIL - expected 1 patch, counted '
          + str(len(applied) + len(already)))
    sys.exit(1)
print('R312b splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R312b note: 1 patch; the underwater')
print('include added - the drown pin call')
print('now compiles; census unchanged 237')
print('commit rides: R312: the flooded')
print('crossing wired (census 237)')

