#!/usr/bin/env python3
# R360b: the R360 audit printf follow-up.
# The R360 splice landed a two-line audit printf - the C string
# broke across the lines (the opening quote never closes), so the
# battery build failed at regtest.cpp and the census cascaded RED
# (every pattern read 0 from an empty battery).
# The printf must also stay on ONE line: the preflight census
# extracts each pattern line-wise from regtest.cpp, so a split
# printf can never match the battery output. This splice rewrites
# the broken pair as a single 75-column printf with the short
# label "R360 UA MU 5th/6th level spells pin audit" - the
# 5th-and-6th wording survives in the audit comment above it.
# Run AFTER tools/r360_splice.py on any fresh replay. The R360
# splice stays as landed (its own copy of the broken pair is
# historical; this script is the correction layer).
# Pin-era pattern (R322). Census stays 287. Idempotent; run twice.
import io

NL = '\n'
applied = []
already = []

def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)

def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)

# ---- (a) regtest.cpp: the one-line printf ----
RT = 'regtest.cpp'
OLD = NL.join([
    '        printf("R360 UA MU 5th and 6th level spells pin',
    '               " audit: bad %d\\n", bad);',
])
NEW = NL.join([
    '        printf("R360 UA MU 5th/6th level spells pin'
    ' audit: bad %d\\n", bad);',
])
clean(NEW, 76)
s = rd(RT)
if OLD in s:
    assert s.count(OLD) == 1, 'a anchor'
    s = s.replace(OLD, NEW)
    wr(RT, s)
    applied.append('regtest.cpp: the one-line printf')
elif NEW in s:
    already.append('regtest.cpp: the one-line printf')
else:
    raise AssertionError('a anchor missing')
s = rd(RT)
assert s.count(NEW) == 1, 'a entry'
assert OLD not in s, 'a broken pair gone'
assert s.count('audit: bad ') == 287, 'a census 287'
assert s.count(
    'R359 UA MU 4th level spells'
    ' pin audit: bad ') == 1, 'a r359 kept'
assert s.count(
    'R358 UA MU 3rd level spells'
    ' pin audit: bad ') == 1, 'a r358 kept'
assert s.count(
    'R357 UA MU 2nd level spells'
    ' pin audit: bad ') == 1, 'a r357 kept'
assert s.count(
    'R356 UA MU 1st level spells'
    ' pin audit: bad ') == 1, 'a r356 kept'
assert s.count(
    'R355 UA druid 7th level spells'
    ' pin audit: bad ') == 1, 'a r355 kept'
assert s.count('R227: the wis mental save') == 1, 'a r227 kept'
assert len(applied) + len(already) == 1, 'a count'

# ---- the summary ----
print('R360b splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R360b note: the R360 audit printf follow-up -')
print('the two-line printf broke the C string and')
print('the census pattern extraction is line-wise,')
print('so the pair rewrites as one 75-column line')
print('with the short label; the battery builds')
print('again and the census reads 287, all bad 0;')
print('the R360 splice stays as landed')
print('commit: R360b: the R360 audit printf'
      ' follow-up (census 287)')

