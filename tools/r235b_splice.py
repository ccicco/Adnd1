#!/usr/bin/env python3
# R235b splice: the bard XP award (the R235 fix).
#
# The Termux battery caught it: the R235 gainXp bard
# branch queued the promotion but never AWARDED the
# experience - the continue skipped the award line
# below, so a bard earned nothing and the R235 engine
# audit read bad 4 (the exact cascade: xp 0, the
# stale queue entry, no promotion, no die). The fix
# is the award itself, flat (the Table I ladder
# counts bard XP only; no prime-requisite
# adjustment - the R186 pin), then the queue.
#
# Run AFTER r235_splice.py (the tree must carry the
# R235 patches; this splice pre-checks).
#
# commit: R235: the bard engine - the Appendix II career playable, the Table I ladder and dice, the druid slots (census 154)

import sys

PAR = 'game/party.h'

NL = chr(10)

# pre-checks: the tree must already carry R235
t = open(PAR).read()
if t.count('int bcap = 23;') != 1:
    print('R235b FAIL: the R235 bard gainXp block is missing')
    sys.exit(1)

# ---- the fix: the award, then the queue ----
fix_old = [
    '            if (c.bard) {',
    '                int bcap = 23;',
]
fix_new = [
    '            if (c.bard) {',
    '                // R235b: the award itself (the flat bard',
    '                // XP - the Table I ladder counts bard XP',
    '                // only; no prime-requisite adjustment,',
    '                // the R186 pin); the R235 block queued',
    '                // but never awarded',
    '                c.xp += amount;',
    '                int bcap = 23;',
]

PATCHES = [
    (PAR, 'R235b: the award itself', fix_old, fix_new),
]

applied = 0
already = 0
for path, marker, old, new in PATCHES:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    if text.count(new_s) >= 1:
        already += 1
        continue
    if text.count(old_s) == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    elif text.count(old_s) == 0:
        print('R235b FAIL: marker missing post-patch: ' + marker)
        sys.exit(1)
    else:
        print('R235b FAIL: marker appears ' +
              str(text.count(old_s)) + ' times: ' + marker)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions
t = open(PAR).read()
if t.count('R235b: the award itself') != 1:
    print('R235b FAIL: the fix line must appear exactly once')
    sys.exit(1)
if t.count('c.xp += amount;') < 1:
    print('R235b FAIL: the award line is missing')
    sys.exit(1)

print('R235b splice: ALL OK (applied ' + str(applied) +
      ', already ' + str(already) + ')')
print('R235b note: the bard XP award - the R235 engine audit')
print('reads bad 0; commit with the R235 message.')

