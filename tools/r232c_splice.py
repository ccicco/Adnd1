#!/usr/bin/env python3
# R232c splice: the battery build gains the engine TU.
#
# The R232 battery audit is the first regtest block to
# call an ai::Actor member (toActor, attacksPerRound).
# The regtest build line in tools/preflight.sh never
# linked ai/actor.cpp - the R232 audit therefore fails
# at LINK (undefined ai::Actor::attacksPerRound), and
# the missing binary cascades into the full census wall.
# The wiring arc (R228-R231 landed, multi/dual-class
# runtime next) keeps needing engine TUs in the battery,
# so the TU joins the build line for good.
#
# 1 patch (no census change):
#  tools/preflight.sh - the g++ battery line gains
#    ai/actor.cpp before regtest.cpp
#
# commit: R232: the subclass specials hooks - backstab, the monk open hand, the giant-class bonus, lay on hands (census 148)

import sys

PF = 'tools/preflight.sh'

NL = chr(10)

# the battery build line: the engine TU joins before regtest
build_old = [
    '  abilities/abilities.cpp items/items.cpp regtest.cpp ' + chr(92),
]
build_new = [
    '  abilities/abilities.cpp items/items.cpp ai/actor.cpp ' + chr(92),
    '  regtest.cpp ' + chr(92),
]

PATCHES = [
    (PF, 'items/items.cpp regtest.cpp', build_old, build_new),
]

applied = 0
already = 0
for path, marker, old, new in PATCHES:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    count = text.count(old_s)
    if count == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    elif count == 0:
        if text.count(new_s) != 1:
            print('R232c FAIL: marker missing post-patch: ' + marker)
            sys.exit(1)
        already += 1
    else:
        print('R232c FAIL: marker appears ' + str(count) + ' times: ' + marker)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions
if applied == len(PATCHES):
    with open(PF) as f:
        t = f.read()
    if t.count('ai/actor.cpp') != 1:
        print('R232c FAIL: ai/actor.cpp must appear exactly once')
        sys.exit(1)
    if 'regtest.cpp ' + chr(92) not in t:
        print('R232c FAIL: regtest.cpp dropped from the build line')
        sys.exit(1)
    if t.count('items.cpp regtest.cpp') != 0:
        print('R232c FAIL: the old adjacency still present')
        sys.exit(1)

print('R232c splice: ALL OK (applied ' + str(applied) + ', already ' + str(already) + ')')
print('R232c note: 1 patch - the regtest battery build links ai/actor.cpp')
print('(the R232 audit is the first block to call an ai::Actor member).')
print('commit: R232: the subclass specials hooks - backstab, the monk open hand, the giant-class bonus, lay on hands (census 148)')

