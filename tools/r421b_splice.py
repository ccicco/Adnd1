#!/usr/bin/env python3
# r421b_splice: the IL cantrip
# cast-times REPAIR - the b-route
# follow-up for the RED R421
# (commit d20e300, the push
# aborted). The defect: the R421
# audit printf was emitted with
# its string literal split across
# two lines - the first line never
# closed its quote ("expected
# expression" at regtest.cpp:45626)
# and the battery never built, so
# preflight cascaded into hundreds
# of phantom CENSUS FAILs (the
# R418/R418b pattern, the R392
# lesson repeated).
#
# The repair: ONE patch - the
# broken two-line printf heals to
# the one-line form (the R418/
# R419 printf precedent). Census
# STAYS 347 (the R421 patches all
# landed; the build is the test);
# no seed record; the R421 splice
# file is NOT touched (it is the
# committed historical record -
# the R418b convention).
#
# The repair also lands TWO
# standing checks (the R418b
# lesson applied one round late):
# 1. no code line in any audit
#    block may carry an
#    unterminated string literal
#    (comment lines may hold lone
#    quotes - the 1" cube);
# 2. every audit printf label is
#    unique and the census holds.
#
# Double-run: 1/0 then 0/1 exact
# (a clean or repaired tree is
# all-already; a tree with the
# R421 audit block missing dies -
# the repair never fabricates the
# round it repairs).
import io
import re as _re

NL = chr(10)

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def die(msg):
    raise SystemExit(
        'R421b splice ABORT: %s' % msg)


RT = 'regtest.cpp'
GP = 'tools/ua_gap_report.md'
ILC = 'rules/uailcantrips.h'
UAS2 = 'rules/uaspelltables2.h'

# ---- the one repair patch ----

FIXED = ('        printf("R421 UA IL cantrip'
         ' cast-times pin audit: bad'
         ' %d' + chr(92) + 'n", bad);')
BROKEN = ('        printf("R421 UA IL cantrip'
          ' cast-times pin' + NL +
          '            " audit: bad'
          ' %d' + chr(92) + 'n", bad);')

s = rd(RT)
if FIXED in s:
    already.append('the R421 audit printf')
elif s.count(BROKEN) == 1:
    wr(RT, s.replace(BROKEN, FIXED))
    applied.append('the R421 audit printf')
else:
    die('the R421 audit printf count'
        ' %d (want exactly one broken'
        ' or fixed)'
        % s.count(BROKEN))

# ======== the verify pass ========

s = rd(RT)

# the R421 round actually landed
# (the repair repairs; it never
# fabricates)
if s.count('R421 UA IL cantrip cast-times'
           ' pin') != 1:
    die('the R421 audit label')
if s.count('audit: bad') != 347:
    die('the census %d (347 stays)'
        % s.count('audit: bad'))

# the standing R418b-lesson check,
# one round late: no CODE line in
# the R421 audit block may carry
# an unterminated string literal
# (comment lines may hold lone
# quotes - the 1" cube reads)
_a = '// ---- R421: the IL cantrip'
_b = '// ---- R227: the wis mental'
i = s.find(_a)
j = s.find(_b)
if i < 0 or j < i:
    die('the R421 audit block bounds')
for ln in s[i:j].split(NL):
    c = ln.lstrip()
    if (c and not c.startswith('//')
            and ln.count(chr(34)) % 2):
        die('the R421 audit block has'
            ' an unterminated string'
            ' literal: %r' % ln[:50])

# the R421 per-row mirror pins are
# in place (the repair heals the
# printer, not the pins)
for pin in ('uailcCastTimeDen(0) != 2',
            'uailcCastTimeDen(6) != 3',
            'uailcCastTimeDen(7) != 8',
            'uailcCastTimeDenCount(2)'
            ' != 4'):
    if pin not in s:
        die('the %s pin' % pin)

# the hole flags stay gone
for flag in (
        'uailcLightsCastingCellGarbled',
        'uailcMirageCastingNumeralLost',
        'uailcTwodCastingCellGarbled',
        'uas2IlCantripListLost'):
    if s.count(flag) or flag in rd(ILC) \
            or flag in rd(UAS2):
        die('the %s flag survives'
            % flag)

# the gap box stays flipped
g = rd(GP)
if ('- [x] **The illusionist'
    ' cantrips**') not in g:
    die('the IL box still open')

print('R421b splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the R421 audit printf'
      ' repair - the broken two-line')
print('  string literal heals to the'
      ' one-line form; census STAYS'
      ' 347 (the R421 patches all'
      ' landed); the R421 splice file')
print('  is untouched (the committed'
      ' record). Standing check'
      ' added: no audit code line')
print('  may carry an unterminated'
      ' string literal.')
print('commit: R421b: the IL cantrip'
      ' cast-times repair')

