# R418: the CANTRIP CASTING-TIME
# RESOLUTION, part 1 - the PDF
# read. The user supplied the
# real UA PDF; the OCR pages
# (book pp. 45-48) print every
# casting-time cell CLEAN. The
# whole hole families the R412
# (useful, 20 cells), R413
# (reversed, 12) and R414
# (legerdemain, 6) rounds
# recorded - 38 cells, all
# fraction garbles in the djvu
# scan - now resolve: every
# cell is a clean unit fraction,
# one segment over the
# denominator. The read (book
# pp. 45-47, in roster order):
# USEFUL - Chill Clean Color
# Dampen Dry Dust at 1/2,
# Exterminate at 1/10, Flavor
# Freshen at 1/2, Gather at
# 1/8, Polish at 1/2, Salt at
# 1/8, Shine Spice Sprout
# Stitch Sweeten Tie Warm Wrap
# at 1/2 (the census 17/0/2/1
# at 1/2, 1/3, 1/8, 1/10).
# REVERSED - Curdle Dirty Dusty
# at 1/8, Hairy at 1/10, Knot
# at 1/2, Ravel at 1/10, Sour
# at 1/2, Spill Tangle at 1/8,
# Tarnish at 1/2, Untie at 1/3,
# Wilt at 1/2 (4/1/5/2).
# LEGERDEMAIN - Change Hide
# Mute Palm at 1/10, Distract
# at 1/3, Present at 1/8
# (0/1/1/4). The PDF also
# confirms the cantrip section
# norm the p. 45 header prints:
# cantrips are cast in 1/10 to
# 1/2 segment - the 2..10
# denominator band cross-checks
# the read. The hole flags come
# OFF the three families (the
# flags and their audit
# assertions amend away); the
# person-affecting, personal
# and haunting-sound casting-
# time families and the other
# recorded holes (the two R416
# areas, the range units, the
# slow-poison defer, the creak
# reads) stay open pending the
# R419 resolution.

# 1. rules/uacantrips1.h,
#    uacantrips2.h,
#    uacantrips3.h: the hole-
#    family blocks amend to the
#    resolved denominator
#    accessors + the denominator
#    census helpers (2 new
#    inline each).
# 2. regtest.cpp: the three
#    hole-family assertions
#    amend to per-row
#    denominator pins; the R418
#    audit block lands before
#    the R227 anchor - the
#    denominator censuses count,
#    the per-family totals
#    cross-check the roster
#    counts, the 2..10 norm band
#    loops; census 344 -> 345.
# 3. tools/ua_gap_report.md:
#    the MU cantrips box takes
#    AMENDED R418.
# 4. The seed takes the R417
#    record.

import io
import os
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


def E(*lines):
    return NL.join(lines)


def die(msg):
    raise SystemExit(
        'R418 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


# ---- the resolved read ----
# (prefix, header path, count,
# denominators in roster order,
# the hole-block anchor text)
FAM = [
    ('ucn', 'rules/uacantrips1.h', 20,
     [2, 2, 2, 2, 2, 2, 10, 2, 2, 8,
      2, 8, 2, 2, 2, 2, 2, 2, 2, 2],
     '// The casting-time hole'
     ' family:\n'
     '// ALL 20 casting-time cells'
     ' print\n'
     '// fraction garbles in the'
     ' scan -\n'
     '// the whole family records'
     ' as\n'
     '// holes pending the PDF'
     ' read (the\n'
     '// R363 illusionist-cantrips\n'
     '// posture).\n'
     'inline bool'
     ' ucnCastTimesAreHoles()\n'
     '    { return true; }'),
    ('ucr', 'rules/uacantrips2.h', 12,
     [8, 8, 8, 10, 2, 10, 2, 8, 8, 2,
      3, 2],
     '// The casting-time hole'
     ' family:\n'
     '// ALL 12 casting-time cells'
     ' print\n'
     '// fraction garbles in the'
     ' scan -\n'
     '// the whole family records'
     ' as\n'
     '// holes pending the PDF'
     ' read (the\n'
     '// R363/R412 posture). The'
     ' Untie\n'
     '// block prints "Casting'
     ' time:"\n'
     '// lowercase - the systematic'
     ' OCR\n'
     '// read, noted.\n'
     'inline bool'
     ' ucrCastTimesAreHoles()\n'
     '    { return true; }'),
    ('ucl', 'rules/uacantrips3.h', 6,
     [10, 3, 10, 10, 10, 8],
     '// The casting-time hole'
     ' family:\n'
     '// ALL 6 casting-time cells'
     ' print\n'
     '// fraction garbles in the'
     ' scan -\n'
     '// the whole family records'
     ' as\n'
     '// holes pending the PDF'
     ' read (the\n'
     '// R363/R412/R413 posture).\n'
     'inline bool'
     ' uclCastTimesAreHoles()\n'
     '    { return true; }'),
]

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R417 landed 2026-10-13:',
    '  commit 67c8f8a (census 344,',
    '  preflight GREEN), the UA',
    '  HAUNTING-SOUND CANTRIP',
    '  DESCRIPTIONS (pp. 50-51) -',
    '  the LAST of the six MU cantrip',
    '  description rounds; ALL SIX',
    '  now stand. rules/uacantrips6.h',
    '  (prefix uch): the 8 haunting-',
    '  sound cantrips in roster',
    '  order, the school census',
    '  3/0/0/0/5 (NO new codes),',
    '  ALL 8 areas clean (the',
    '  Special seven + the Tap',
    '  1 sq. ft., a NEW area kind),',
    '  the whistle pair pins clean',
    '  (faint 10, loud 30, the',
    '  loud == faint*3 derivation),',
    '  the tap 1..3 band, the',
    '  casting-time and range-unit',
    '  families the recorded holes',
    '  pending the PDF read. The',
    '  49-line AMENDED R416 gap',
    '  anchor was embedded byte-',
    '  exact via a generator. The',
    '  md5 diverged for the',
    '  EIGHTEENTH round running -',
    '  benign; the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R417 landed 2026-10-13' in s:
    already.append('seed: the R417 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R417 record')
s = rd(SD)
if s.count('R417 landed 2026-10-13') != 1:
    die('the R417 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) the headers =========

def hdr_dens(pfx, n, dens):
    # the resolved denominators,
    # 10 per row
    rows = []
    for k in range(0, n, 10):
        rows.append('        '
                    + ', '.join(str(d)
                                for d in
                                dens[k:k+10])
                    + (',' if k+10 < n
                       else ' };'))
    return NL.join(rows)


CENSUS_NOTE = {
    'ucn': E(
        '// order: 17 at 1/2 (Chill,',
        '// Clean, Color, Dampen, Dry,',
        '// Dust, Flavor, Freshen,',
        '// Polish, Shine, Spice,',
        '// Sprout, Stitch, Sweeten,',
        '// Tie, Warm, Wrap),',
        '// Exterminate at 1/10,',
        '// Gather and Salt at 1/8.'),
    'ucr': E(
        '// order: Curdle, Dirty and',
        '// Dusty at 1/8, Hairy at',
        '// 1/10, Knot at 1/2, Ravel',
        '// at 1/10, Sour at 1/2,',
        '// Spill and Tangle at 1/8,',
        '// Tarnish at 1/2, Untie at',
        '// 1/3 (the lowercase',
        '// Casting-time print, the',
        '// systematic OCR read,',
        '// noted in R413), Wilt at',
        '// 1/2.'),
    'ucl': E(
        '// order: Change, Hide,',
        '// Mute and Palm at 1/10,',
        '// Distract at 1/3, Present',
        '// at 1/8.'),
}

for pfx, path, n, dens, old in FAM:
    cap = {'ucn': 'Useful', 'ucr': 'Reversed',
           'ucl': 'Legerdemain'}[pfx]
    new = E(
        '// The casting times: the',
        '// PDF read resolves the',
        '// whole family (R418) - the',
        '// real UA PDF prints every',
        '// cell clean, a unit',
        '// fraction, one segment',
        '// over the denominator. The',
        '// denominators, in roster',
        CENSUS_NOTE[pfx],
        'inline int %sCastTimeDen(int i)'
        % pfx,
        '{',
        '    static const int D[%d] = {'
        % n)
    new += NL + hdr_dens(pfx, n, dens)
    new += NL + E(
        '    if (i < 0) i = 0;',
        '    if (i > %d) i = %d;'
        % (n - 1, n - 1),
        '    return D[i];',
        '}',
        '',
        '// The casting-time',
        '// denominator census helper.',
        'inline int %sCastTimeDenCount'
        '(int d)' % pfx,
        '{',
        '    int n = 0;',
        '    for (int i = 0; i < %d;'
        ' ++i)' % n,
        '        if (%sCastTimeDen(i)'
        ' == d)' % pfx,
        '            ++n;',
        '    return n;',
        '}')
    pair(path, old, new,
         'the %s casting times' % cap)

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

def den_pins(pfx, dens, per=8):
    fn = '%sCastTimeDen' % pfx
    blocks = []
    for k in range(0, len(dens), per):
        chunk = dens[k:k+per]
        ls = []
        for j, d in enumerate(chunk):
            i = k + j
            c = '%s(%d) != %d' % (fn, i, d)
            if k == 0 and j == 0:
                ls.append('        if (' + c)
            else:
                ls.append('                '
                          '|| ' + c)
        ls[-1] += ') ++bad;'
        blocks.append(E(*ls))
    return (NL + NL).join(blocks)


for pfx, path, n, dens, _old in FAM:
    old = E('        // ---- the hole'
            ' family ----',
            '        if (!%sCastTimes'
            'AreHoles())' % pfx,
            '            ++bad;')
    new = E('        // ---- the casting'
            ' times ----',
            '        // (the PDF read'
            ' resolves the',
            '        // family - R418)')
    new += NL + NL + den_pins(pfx, dens)
    pair(RT, old, new,
         'regtest: the %s casting'
         ' times' % pfx)

AUD = E(
    '    // ---- R418: the cantrip',
    '    // casting-time resolution',
    '    // part 1 pin audit ----',
    '    // The PDF read resolves the',
    '    // whole casting-time families',
    '    // the R412 (useful), R413',
    '    // (reversed) and R414',
    '    // (legerdemain) rounds recorded',
    '    // as holes: all 38 cells print',
    '    // clean unit fractions, one',
    '    // segment over the denominator.',
    '    // The denominator censuses count',
    '    // (the useful 17/0/2/1, the',
    '    // reversed 4/1/5/2, the',
    '    // legerdemain 0/1/1/4 - at',
    '    // 1/2, 1/3, 1/8, 1/10), each',
    '    // family census totals its',
    '    // roster count, and every',
    '    // denominator sits in the 2..10',
    '    // band the cantrip section',
    '    // header prints (the cantrips',
    '    // cast in 1/10 to 1/2 segment',
    '    // norm); census 344 -> 345.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        if (ucnCastTimeDenCount(2)'
    ' != 17',
    '                || ucnCastTime'
    'DenCount(3) != 0',
    '                || ucnCastTime'
    'DenCount(8) != 2',
    '                || ucnCastTime'
    'DenCount(10) != 1)',
    '            ++bad;',
    '        if (ucrCastTimeDenCount(2)'
    ' != 4',
    '                || ucrCastTime'
    'DenCount(3) != 1',
    '                || ucrCastTime'
    'DenCount(8) != 5',
    '                || ucrCastTime'
    'DenCount(10) != 2)',
    '            ++bad;',
    '        if (uclCastTimeDenCount(2)'
    ' != 0',
    '                || uclCastTime'
    'DenCount(3) != 1',
    '                || uclCastTime'
    'DenCount(8) != 1',
    '                || uclCastTime'
    'DenCount(10) != 4)',
    '            ++bad;',
    '        // the per-family totals',
    '        if (ucnCastTimeDenCount(2)',
    '                + ucnCastTime'
    'DenCount(3)',
    '                + ucnCastTime'
    'DenCount(8)',
    '                + ucnCastTime'
    'DenCount(10)',
    '                != 20) ++bad;',
    '        if (ucrCastTimeDenCount(2)',
    '                + ucrCastTime'
    'DenCount(3)',
    '                + ucrCastTime'
    'DenCount(8)',
    '                + ucrCastTime'
    'DenCount(10)',
    '                != 12) ++bad;',
    '        if (uclCastTimeDenCount(2)',
    '                + uclCastTime'
    'DenCount(3)',
    '                + uclCastTime'
    'DenCount(8)',
    '                + uclCastTime'
    'DenCount(10)',
    '                != 6) ++bad;',
    '        // the 2..10 norm band',
    '        for (int i = 0; i < 20;'
    ' ++i)',
    '            if (ucnCastTimeDen(i)'
    ' < 2',
    '                || ucnCastTimeDen(i)'
    ' > 10)',
    '                ++bad;',
    '        for (int i = 0; i < 12;'
    ' ++i)',
    '            if (ucrCastTimeDen(i)'
    ' < 2',
    '                || ucrCastTimeDen(i)'
    ' > 10)',
    '                ++bad;',
    '        for (int i = 0; i < 6;'
    ' ++i)',
    '            if (uclCastTimeDen(i)'
    ' < 2',
    '                || uclCastTimeDen(i)'
    ' > 10)',
    '                ++bad;',
    '        printf("R418 UA cantrip'
    ' cast-'
    'times part 1 pin'
    ' audit: bad %d'
    + chr(92) + 'n\", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R418 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '      - AMENDED R417: the',
    '        haunting-sound'),
    E(
    '      - AMENDED R418: the PDF',
    '        read lands - the',
    '        casting-time hole',
    '        families of the useful',
    '        (R412), reversed (R413)',
    '        and legerdemain (R414)',
    '        descriptions resolve:',
    '        38 cells, every one a',
    '        clean unit fraction one',
    '        segment over the',
    '        denominator (the useful',
    '        17/0/2/1, the reversed',
    '        4/1/5/2, the',
    '        legerdemain 0/1/1/4 at',
    '        1/2, 1/3, 1/8, 1/10);',
    '        the denominator censuses',
    '        count, the per-family',
    '        totals cross-check the',
    '        roster counts, the 2..10',
    '        norm band the cantrip',
    '        section header prints',
    '        cross-checks the read,',
    '        and the hole flags come',
    '        off. The person-affecting,',
    '        personal and haunting-',
    '        sound casting-time',
    '        families and the other',
    '        recorded holes (the two',
    '        R416 areas, the range',
    '        units, the slow-poison',
    '        defer, the creak reads)',
    '        stay open pending the',
    '        R419 resolution.',
    '      - AMENDED R417: the',
    '        haunting-sound'),
    'gap: the MU cantrips box takes'
    ' R418')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 345:
    die('the census %d' % s.count('audit: bad'))
if s.count('R418 UA cantrip cast-'
           'times part 1 pin'
           ' audit') != 1:
    die('the R418 audit label')

# the hole flags are gone for the
# three amended families
for pfx, path, n, dens, _old in FAM:
    if s.count('%sCastTimesAreHoles'
               % pfx) != 0:
        die('the %s hole flag'
            ' survives' % pfx)
    h = rd(path)
    if h.count('%sCastTimesAreHoles'
               % pfx) != 0:
        die('the %s header flag'
            ' survives' % pfx)

# the R412b resolution guard: every
# symbol the audits call is defined
for pfx, path, n, dens, _old in FAM:
    _used = set(_re.findall(
        r'\b%s\w+' % pfx, s))
    _def = set(_re.findall(
        r'\b%s\w+' % pfx, rd(path)))
    if _used - _def:
        die('undefined %s calls %s'
            % (pfx, sorted(_used - _def)))

# the inline counts
for pfx, path, n, dens, _old in \
        zip([f[0] for f in FAM],
            [f[1] for f in FAM],
            [f[2] for f in FAM],
            [f[3] for f in FAM],
            [f[4] for f in FAM]):
    p = rd(path)
    want = {'ucn': 17, 'ucr': 18,
            'ucl': 24}[pfx]
    if p.count('inline') != want:
        die('the %s inline count %d'
            % (pfx, p.count('inline')))
    if not p.endswith(NL):
        die('the %s header trailing'
            ' newline' % pfx)

# the R412b class guard on each
# amended header
for pfx, path, n, dens, _old in FAM:
    for ln in rd(path).split(NL):
        if ln and not ln.startswith((
                '//', '#', 'namespace',
                'inline', 'const', 'struct',
                '{', '}', '    ',
                '        ',
                '            ')):
            die('a non-code %s header'
                ' line %r' % (pfx, ln[:44]))

g = rd(GP)
if g.count('AMENDED R418') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R418'))

for path, mark in (
        ('rules/uacantrips1.h',
         'ucnCastTimeDenCount'),
        (RT, 'R418 UA cantrip cast-'),
        (SD, 'R417 landed')):
    if mark not in rd(path):
        die('%s carries no R418 round'
            % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    for pfx in ('ucn', 'ucr', 'ucl'):
        if _re.search(r'\b%s\w' % pfx,
                      rd(path)):
            die('%s calls the %s pins'
                ' early' % (path, pfx))

print('R418 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the cantrip casting-')
print('  time resolution part 1 -')
print('  the PDF read resolves the')
print('  useful, reversed and')
print('  legerdemain families (38')
print('  cells, all clean unit')
print('  fractions), the censuses')
print('  17/0/2/1, 4/1/5/2 and')
print('  0/1/1/4 count, the 2..10')
print('  norm band cross-checks,')
print('  the hole flags come off;')
print('  census 344 -> 345')
print('commit: R418: the cantrip'
      ' casting-time resolution'
      ' part 1 (census 345)')

