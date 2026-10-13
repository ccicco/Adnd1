#!/usr/bin/env python3
# R418b: the cantrip cast-times repair -
# the follow-up fix splice for the RED
# R418 commit (ade93bd).
#
# The R418 body shipped one C defect the
# Python audit simulation pass could not
# see (it models the accessors' return
# VALUES, not the emitted C text):
#
# regtest.cpp: the per-row denominator
# pin emitter opened only the FIRST
# 8-cell chain of each family with an
# 'if (' - every chain after it began
# with a bare '||' line. Three chains
# shipped orphaned: the ucn block 2
# (ucnCastTimeDen(8), regtest 44432),
# the ucn block 3 (ucnCastTimeDen(16),
# 44441) and the ucr block 2
# (ucrCastTimeDen(8), 44609) - each an
# 'expected expression' compile error,
# so the battery never built and the
# preflight census cascaded into
# hundreds of phantom CENSUS FAILs
# (the R368 phantom-cascade pattern).
# The ucl family (6 cells) is a single
# chain and is clean; the headers are
# clean; the double-run and statics
# were green - the R368 lesson's
# missing check was structural: no
# chain may begin with '||'.
#
# This splice amends the three chain
# starts in place, idempotently, and
# adds a mirrored per-row pin eval (the
# D[] arrays vs every regtest pin) plus
# an orphan-line gate to its verify
# pass. The census stays 345 (no new
# audit: the R418 audit block itself
# only compiles when the chains are
# right - the build is the test). No
# seed record (a repair, not a round;
# the R418 landed record will name the
# R418b fix - the R392 / R392b
# precedent).
import io
import re

NL = '\n'

RT = 'regtest.cpp'
HDRS = ('rules/uacantrips1.h',
        'rules/uacantrips2.h',
        'rules/uacantrips3.h')

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def abort(label, detail):
    print('R418b ABORT: %s' % label)
    print('  %r' % (detail[:80],))
    raise SystemExit(1)


# ---- the three orphaned chain starts ----
FIXES = [
    ('                || ucnCastTime'
     'Den(8) != 2',
     '        if (ucnCastTime'
     'Den(8) != 2',
     'the ucn block-2 chain start'),
    ('                || ucnCastTime'
     'Den(16) != 2',
     '        if (ucnCastTime'
     'Den(16) != 2',
     'the ucn block-3 chain start'),
    ('                || ucrCastTime'
     'Den(8) != 8',
     '        if (ucrCastTime'
     'Den(8) != 8',
     'the ucr block-2 chain start'),
]

src = rd(RT)
touched = False
for bad, good, label in FIXES:
    if bad in src:
        if src.count(bad) != 1:
            abort('regtest %s count' % label,
                  bad)
        src = src.replace(bad, good)
        applied.append('regtest: %s' % label)
        touched = True
    elif good in src:
        already.append('regtest: %s' % label)
    else:
        abort('the %s not found' % label,
              'neither form present')
if touched:
    wr(RT, src)

# ---- the verify gate (fail on any anomaly) ----

if rd(RT).count('audit: bad ') != 345:
    abort('the census is not 345',
          'run the R418 splice first')

if rd(RT).count('R418 UA cantrip cast-times'
               ' part 1 pin audit') != 1:
    abort('the R418 audit label count', '')

for bad, good, label in FIXES:
    if rd(RT).count(good) != 1:
        abort('the %s did not hold' % label,
              good)

# no chain may begin with a bare '||': a
# pin chain line is legal only when the
# line before it is still the chain (the
# open 'if (' line or a prior '||' pin)
prev = ''
for n, ln in enumerate(rd(RT).split(NL), 1):
    if re.match(r'^ +\|\| \w+CastTimeDen\(',
                ln) and 'CastTimeDen' \
            not in prev:
        abort('an orphaned pin chain at'
              ' regtest:%d' % n, ln)
    prev = ln

# the mirrored per-row pin eval: every
# regtest pin must hold against the
# header D[] arrays (fail-on-wrong,
# the R368 lesson applied to text)
DENS = {}
for h in HDRS:
    code = rd(h)
    m = re.search(r'static const int D\[(\d+)\]'
                  r' = \{(.*?)\};', code, re.S)
    if not m:
        abort('no D[] array in %s' % h, '')
    D = [int(x) for x in
         re.findall(r'\d+', m.group(2))]
    if len(D) != int(m.group(1)):
        abort('the D[] roster count in %s'
              % h, str(len(D)))
    DENS[h] = D

PIN = re.compile(r'(\w+)CastTimeDen\((\d+)\)'
                 r' != (\d+)')
for n, ln in enumerate(rd(RT).split(NL), 1):
    for m in PIN.finditer(ln):
        pfx, i, d = (m.group(1),
                     int(m.group(2)),
                     int(m.group(3)))
        h = {'ucn': HDRS[0], 'ucr': HDRS[1],
             'ucl': HDRS[2]}.get(pfx)
        if h is None:
            abort('an unknown pin prefix'
                  ' at regtest:%d' % n, ln)
        if i >= len(DENS[h]):
            abort('a pin index past the'
                  ' roster at regtest:%d'
                  % n, ln)
        if DENS[h][i] != d:
            abort('a wrong pin at'
                  ' regtest:%d' % n, ln)

# the family roster counts in the R418
# census checks must match the arrays
if len(DENS[HDRS[0]]) != 20:
    abort('the ucn roster is not 20', '')
if len(DENS[HDRS[1]]) != 12:
    abort('the ucr roster is not 12', '')
if len(DENS[HDRS[2]]) != 6:
    abort('the ucl roster is not 6', '')

print('R418b splice: ALL OK (applied %d,'
      ' already %d)'
      % (len(applied), len(already)))
print('R418b note: the cantrip')
print('cast-times repair - the three')
print('orphaned pin chains of the RED')
print('ade93bd (the ucn blocks 2 and 3,')
print('the ucr block 2) open with if (')
print('again; the census stays 345; the')
print('build is the test')
print('commit: R418b: the cantrip'
      ' cast-times repair (census 345)')

