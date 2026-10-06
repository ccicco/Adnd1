#!/usr/bin/env python3
# R232d splice: the battery build gains the spelleffects TU.
#
# The R232c round put ai/actor.cpp on the regtest battery
# build line; the link then surfaced actor.cpp's own
# dependency: spelleffects::resolveSpell and
# spelleffects::tickStatus (Actor::tickStatuses, the R227
# wiring), defined in spelleffects/spelleffects.cpp - a
# top-level directory the battery line predates. The game
# binary links it; the battery never did, because no
# regtest block called an ai::Actor member until R232.
# Probe-proven on Termux: rules/dm/monsters/spells/
# abilities/items/ai/spelleffects + regtest links clean
# and the full battery runs green (R232 audit bad 0).
#
# 1 patch (no census change):
#  tools/preflight.sh - the g++ battery line gains
#    spelleffects/spelleffects.cpp after ai/actor.cpp
#
# commit: R232: the subclass specials hooks - backstab, the monk open hand, the giant-class bonus, lay on hands (census 148)

import sys

PF = 'tools/preflight.sh'

NL = chr(10)

# the battery build line: the spelleffects TU joins after
# the engine TU (the R232c addition)
build_old = [
    '  abilities/abilities.cpp items/items.cpp ai/actor.cpp ' + chr(92),
    '  regtest.cpp ' + chr(92),
]
build_new = [
    '  abilities/abilities.cpp items/items.cpp ai/actor.cpp ' + chr(92),
    '  spelleffects/spelleffects.cpp regtest.cpp ' + chr(92),
]

PATCHES = [
    (PF, 'spelleffects/spelleffects.cpp regtest.cpp', build_old, build_new),
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
            print('R232d FAIL: marker missing post-patch: ' + marker)
            sys.exit(1)
        already += 1
    else:
        print('R232d FAIL: marker appears ' + str(count) + ' times: ' + marker)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions
if applied == len(PATCHES):
    with open(PF) as f:
        t = f.read()
    if t.count('spelleffects/spelleffects.cpp') != 1:
        print('R232d FAIL: the spelleffects TU must appear exactly once')
        sys.exit(1)
    if t.count('ai/actor.cpp') != 1:
        print('R232d FAIL: the R232c actor TU must stay exactly once')
        sys.exit(1)
    if 'actor.cpp regtest.cpp' in t:
        print('R232d FAIL: the actor-to-regtest adjacency still present')
        sys.exit(1)

print('R232d splice: ALL OK (applied ' + str(applied) + ', already ' + str(already) + ')')
print('R232d note: 1 patch - the battery build links spelleffects.cpp')
print('(actor.cpp depends on it; probe-proven green on Termux).')
print('commit: R232: the subclass specials hooks - backstab, the monk open hand, the giant-class bonus, lay on hands (census 148)')

