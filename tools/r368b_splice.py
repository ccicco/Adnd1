#!/usr/bin/env python3
# R368b: the R368 title-loop mapping fix.
# The R368 audit landed with an off-by-one in
# the 14-entry title walk: the tn[] array maps
# i=0 to Horseman (level 0), i=1 to Lancer
# (level -1) and i>=2 to the levels 1-12, so
# the level must read i - 1, not i - 2. As
# landed the loop compared uacavtTitle(0..11)
# against Armiger through "Cavalier, 12th" -
# all 12 iterations failed and the battery
# printed bad 12 (the census cascade RED was
# the early return that follows).
# This splice rewrites the mapping line in
# place. Census stays 295; the R368 label and
# every other check are untouched. The R368
# splice stays as landed (historical).
# Pin-era pattern (R322). Idempotent; run twice.
import io

NL = '\n'
RT = 'regtest.cpp'
applied = []
already = []


def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


s = rd(RT)
OLD = ('            for (int i = 0; '
       'i < 14; ++i) {' + NL +
       '                int l = (i == 0) '
       '? 0 : (i == 1 ? -1 : i - 2);')
NEW = ('            for (int i = 0; '
       'i < 14; ++i) {' + NL +
       '                int l = (i == 0) '
       '? 0 : (i == 1 ? -1 : i - 1);')
if '(i == 1 ? -1 : i - 1);' in s:
    already.append('regtest.cpp: the mapping fix')
else:
    assert s.count(OLD) == 1, 'b old anchor'
    s = s.replace(OLD, NEW)
    wr(RT, s)
    applied.append('regtest.cpp: the mapping fix')

# ---- the post asserts ----
s = rd(RT)
assert s.count(
    '(i == 1 ? -1 : i - 1);'
) == 1, 'b fixed line'
assert s.count(
    '(i == 1 ? -1 : i - 2);'
) == 0, 'b old line gone'
assert s.count(
    'R368 UA Cavaliers Table I pin audit: bad '
) == 1, 'b label once'
assert s.count('audit: bad ') == 295, 'b census 295'
assert len(applied) + len(already) == 1, 'b count'

print('R368b splice: ALL OK '
      '(applied %d, already %d)'
      % (len(applied), len(already)))
print('R368b note: the title-loop level maps')
print('i - 1 for i >= 2 - the bad-12 walk')
print('closes; the census stays 295')

