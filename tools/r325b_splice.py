#!/usr/bin/env python3
# R325b: the fix round for the R325 audit walks.
# The U6 live walks passed st.rng (a rules::Rng)
# where gainXp/trainNext take a rules::Dice& -
# the AppState already carries dice{rng}, bound
# by reference, so the walks read st.dice and
# the st.rng.seed(7) lines keep working.
# Idempotent: safe to run twice.

import io
import os

RT = 'regtest.cpp'

def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)

applied = 0
s = rd(RT)
old = 'st.rng, st.log)'
new = 'st.dice, st.log)'
n = s.count(old)
d = s.count(new)
if n == 0 and d == 8:
    print('R325b splice: ALL OK (already applied)')
else:
    assert n == 8, 'R325b: expected 8 rng passes, found %d' % n
    assert d == 0, 'R325b: unexpected dice passes %d' % d
    s = s.replace(old, new)
    wr(RT, s)
    applied = 1
    print('R325b splice: ALL OK (applied 1)')

# read back and assert
s = rd(RT)
assert s.count('st.dice, st.log)') == 8, 'b the dice passes'
assert s.count('st.rng, st.log)') == 0, 'b no rng passes left'
assert s.count('R325 subrace level cap audit: bad ') == 1, 'b audit intact'
assert s.count('audit: bad ') == 252, 'b census intact'
assert applied <= 1
print('R325b note: the U6 walks pass st.dice -')
print('  the AppState Dice bound to st.rng by')
print('  reference (dice{rng}); the seed lines')
print('  ride the reference. census stays 252.')
print('commit: git commit --amend --no-edit (folds into R325)')

