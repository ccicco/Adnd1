#!/usr/bin/env python3
# R419: the CANTRIP CASTING-TIME
# RESOLUTION, part 2 - the PDF
# read completes. The OCR pages
# (book pp. 49-51) print every
# remaining casting-time cell
# CLEAN. The whole hole families
# the R415 (person-affecting, 10
# cells), R416 (personal, 10) and
# R417 (haunting-sound, 8) rounds
# recorded - 28 cells - now
# resolve: every cell is a clean
# unit fraction, one segment over
# the denominator. The read (book
# pp. 49-51, in roster order):
# PERSON-AFFECTING - Belch Blink
# Nod Wink at 1/10, Cough Giggle
# Twitch at 1/3, Scratch Yawn at
# 1/8, Sneeze at 1/2 (the census
# 1/3/2/4 at 1/2, 1/3, 1/8,
# 1/10). PERSONAL - Bee Bluelight
# Bug Gnats Mouse Spider Unlock at
# 1/2, Firefinger Smokepuff Tweak
# at 1/3 (7/3/0/0). HAUNTING-SOUND
# - Creak Footfall Groan Tap
# Whistle at 1/6, Moan Rattle
# Thump at 1/10 (0/0/5/3 - the
# 1/6 lands INSIDE the 2..10
# denominator band the p. 45
# header prints; the band
# cross-check holds).
#
# The read also resolves the
# OTHER recorded holes:
# - the two R416 areas: the
#   Bluelight "1/4' diam. sphere"
#   and the Firefinger "1/2'
#   line" - the sphere and the
#   line become NEW area kind
#   codes, and the values
#   cross-derive against the
#   standing mechanics pins (the
#   3-inch sphere, the 6-inch
#   jet - 1/4 foot == 3 inches,
#   1/2 foot == 6 inches).
# - the range unit families: the
#   glyphs are the AD&D 1"
#   notation (one inch of range,
#   the ten-foot indoor scale) -
#   the unit pins as inch in
#   both families.
# - the slow-poison defer: a
#   slow poison defers the
#   sickness for 1 day.
# - the creak reads: the former
#   sound lasts 1/3 segment (the
#   denominator 3); the latter
#   noise traverses up to 10
#   feet.
# The hole flags come OFF (the
# flags and their audit
# assertions amend away).
#
# 1. rules/uacantrips4.h,
#    uacantrips5.h,
#    uacantrips6.h: the hole-
#    family blocks amend to the
#    resolved denominator
#    accessors + the denominator
#    census helpers; the resolved
#    reads pin (the area kinds,
#    the unit flags, the defer,
#    the creak pair).
# 2. regtest.cpp: the three
#    hole-family assertions amend
#    to per-row denominator pins
#    (EVERY chain opens with
#    'if (' - the R418b lesson);
#    the R416 area census and the
#    Bluelight/Firefinger row
#    pins amend to the resolved
#    kinds; the R419 audit block
#    lands before the R227
#    anchor - the denominator
#    censuses count, the
#    per-family totals cross-
#    check the roster counts, the
#    2..10 norm band loops, the
#    area values cross-derive
#    against the mechanics pins;
#    census 345 -> 346.
# 3. tools/ua_gap_report.md:
#    the MU cantrips box takes
#    AMENDED R419.
# 4. The seed takes the R418
#    record.

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


def E(*lines):
    return NL.join(lines)


def die(msg):
    raise SystemExit(
        'R419 splice ABORT: ' + msg)


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
# denominators in roster order)
FAM = [
    ('ucp', 'rules/uacantrips4.h', 10,
     [10, 10, 3, 3, 10, 8, 2, 3,
      10, 8]),
    ('uco', 'rules/uacantrips5.h', 10,
     [2, 2, 2, 3, 2, 2, 3, 2, 3,
      2]),
    ('uch', 'rules/uacantrips6.h', 8,
     [6, 6, 6, 10, 10, 6, 10, 6]),
]

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R418 landed 2026-10-13:',
    '  commits ade93bd + the R418b',
    '  repair 21a7031 (census 345,',
    '  preflight GREEN), the UA',
    '  CANTRIP CASTING-TIME',
    '  RESOLUTION PART 1 (book pp.',
    '  45-48) - the PDF read resolves',
    '  the useful (20), reversed (12)',
    '  and legerdemain (6) casting-',
    '  time families: 38 cells, ALL',
    '  clean unit fractions AS',
    '  PRINTED; the hole blocks amend',
    '  to uXXCastTimeDen accessors over',
    '  D[] arrays plus DenCount census',
    '  helpers; censuses 17/0/2/1,',
    '  4/1/5/2 and 0/1/1/4; the 2..10',
    '  norm band cross-checks. The',
    '  R418 body shipped RED (the',
    '  orphaned || pin chains - the',
    '  per-row emitter opened only the',
    '  FIRST chain with if ( - three',
    '  expected-expression compile',
    '  errors, the battery never',
    '  built, preflight cascaded into',
    '  hundreds of phantom CENSUS',
    '  FAILs); landed via the b-route',
    '  (the R392/R392b precedent). The',
    '  R418b repair added the standing',
    '  gates: NO chain may begin with',
    '  ||, and every regtest pin is',
    '  mirror-evaled against the',
    '  header D[] arrays. The ./nn',
    '  save hash diverged twice -',
    '  benign; the md5 stays advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R418 landed 2026-10-13' in s:
    already.append('seed: the R418 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R418 record')

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
    'ucp': E(
        '// order: Sneeze at 1/2,',
        '// Cough, Giggle and Twitch',
        '// at 1/3, Scratch and Yawn',
        '// at 1/8, Belch, Blink, Nod',
        '// and Wink at 1/10.'),
    'uco': E(
        '// order: Bee, Bluelight,',
        '// Bug, Gnats, Mouse, Spider',
        '// and Unlock at 1/2,',
        '// Firefinger, Smokepuff and',
        '// Tweak at 1/3.'),
    'uch': E(
        '// order: Creak, Footfall,',
        '// Groan, Tap and Whistle at',
        '// 1/6, Moan, Rattle and',
        '// Thump at 1/10 - the 1/6',
        '// lands inside the 2..10',
        '// band the p. 45 header',
        '// prints.'),
}

CAST_OLD = {
    'ucp': E(
        '// The casting-time hole'
        ' family:',
        '// ALL 10 casting-time cells'
        ' print',
        '// fraction garbles in the'
        ' scan -',
        '// the whole family records'
        ' as',
        '// holes pending the PDF'
        ' read (the',
        '// R363/R412/R413/R414'
        ' posture).',
        'inline bool'
        ' ucpCastTimesAreHoles()',
        '    { return true; }'),
    'uco': E(
        '// The casting-time hole'
        ' family:',
        '// ALL 10 casting-time cells'
        ' print',
        '// fraction garbles in the'
        ' scan -',
        '// the whole family records'
        ' as',
        '// holes pending the PDF'
        ' read (the',
        '// R363/R412/R413/R414/R415',
        '// posture).',
        'inline bool'
        ' ucoCastTimesAreHoles()',
        '    { return true; }'),
    'uch': E(
        '// The casting-time hole'
        ' family:',
        '// ALL 8 casting-time cells'
        ' print',
        '// fraction garbles in the'
        ' scan -',
        '// the whole family records'
        ' as',
        '// holes pending the PDF'
        ' read (the',
        '// R363/R412/R413/R414/R415/'
        'R416',
        '// posture).',
        'inline bool'
        ' uchCastTimesAreHoles()',
        '    { return true; }'),
}

for pfx, path, n, dens in FAM:
    cap = {'ucp': 'Person-'
                  'affecting',
           'uco': 'Personal',
           'uch': 'Haunting-'
                  'sound'}[pfx]
    new = E(
        '// The casting times: the',
        '// PDF read resolves the',
        '// whole family (R419) - the',
        '// real UA PDF prints every',
        '// cell clean, a unit',
        '// fraction, one segment',
        '// over the denominator. The',
        '// denominators, in roster',
        '// order:',
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
    pair(path, CAST_OLD[pfx], new,
         'the %s casting times' % cap)

# ---- the uco resolved reads ----
UCO = 'rules/uacantrips5.h'

pair(UCO,
     E('const int UCO_AREA_LOCK = 12;'),
     E('const int UCO_AREA_LOCK = 12;',
       '// The sphere and the line NEW',
       '// this round (R419 - the PDF',
       '// read resolves the two area',
       '// holes).',
       'const int UCO_AREA_SPHERE = 13;',
       'const int UCO_AREA_LINE = 14;'),
     'uco: the area kind codes')

pair(UCO,
     E('        { "Bluelight", 7,'
       ' -1, 0 },'),
     E('        { "Bluelight", 7,',
       '            UCO_AREA_SPHERE,'
       ' 3 },'),
     'uco: the Bluelight area row')

pair(UCO,
     E('        { "Firefinger", 2,'
       ' -1, 0 },'),
     E('        { "Firefinger", 2,',
       '            UCO_AREA_LINE,'
       ' 6 },'),
     'uco: the Firefinger area row')

pair(UCO,
     E('// The range hole family:'
       ' the',
       '// seven ranged blocks print'
       ' the',
       '// numeral 1 clean but the',
       '// foot/inch glyphs garble -'
       ' the',
       '// numeral pins, the unit'
       ' family',
       '// records as holes pending'
       ' the',
       '// PDF read.',
       'inline bool'
       ' ucoRangeUnitsAreHoles()',
       '    { return true; }'),
     E('// The range units: the PDF'
       ' read',
       '// resolves the glyphs (R419) -'
       ' the',
       '// seven ranged blocks print'
       ' the',
       '// AD&D 1" notation (one inch'
       ' of',
       '// range, the ten-foot indoor',
       '// scale). The unit pins as'
       ' inch;',
       '// the numeral 1 rides the',
       '// standing ucoRangeVal()'
       ' pin.',
       'inline bool'
       ' ucoRangeUnitIsInch()',
       '    { return true; }'),
     'uco: the range unit')

pair(UCO,
     E('// The slow poison defer:'
       ' the',
       '// scan prints a garbled'
       ' numeral',
       '// for the deferral - the'
       ' value',
       '// records as a hole pending'
       ' the',
       '// PDF read (never a guess).',
       'inline bool'
       ' ucoSlowPoisonDeferIsHole()',
       '    { return true; }'),
     E('// The slow poison defer:'
       ' the PDF',
       '// read resolves the garble'
       ' (R419)',
       '// - a slow poison defers the',
       '// sickness for 1 day.',
       'inline int'
       ' ucoSlowPoisonDeferDays()',
       '    { return 1; }'),
     'uco: the slow poison defer')

# ---- the uch resolved reads ----
UCH = 'rules/uacantrips6.h'

pair(UCH,
     E('// The range unit hole'
       ' family:',
       '// five blocks print the'
       ' numerals',
       '// clean but the foot/inch',
       '// glyphs garble - the'
       ' numerals',
       '// pin, the unit family'
       ' records',
       '// as holes pending the PDF',
       '// read.',
       'inline bool'
       ' uchRangeUnitsAreHoles()',
       '    { return true; }'),
     E('// The range units: the PDF'
       ' read',
       '// resolves the glyphs (R419) -'
       ' the',
       '// ranged blocks print the',
       '// AD&D 1" notation (one inch'
       ' of',
       '// range, the ten-foot indoor',
       '// scale). The unit pins as'
       ' inch;',
       '// the numerals ride the',
       '// standing uchRangeNearVal()'
       ' and',
       '// uchFootfallFarVal() pins.',
       'inline bool'
       ' uchRangeUnitIsInch()',
       '    { return true; }'),
     'uch: the range unit')

pair(UCH,
     E('// The creak read: the'
       ' former',
       '// sound (corroded-hinge'
       ' door)',
       '// prints a garbled 1/3'
       ' segment -',
       '// a hole; the latter noise',
       '// (squeaking floorboards)'
       ' lasts',
       '// half a segment (in'
       ' halves).',
       'inline bool'
       ' uchCreakFormerIsHole()',
       '    { return true; }'),
     E('// The creak read (the PDF'
       ' read',
       '// resolves the garble - R419):',
       '// the former sound (corroded-',
       '// hinge door) lasts 1/3',
       '// segment (the denominator',
       '// 3); the latter noise',
       '// (squeaking floorboards)'
       ' lasts',
       '// half a segment (in'
       ' halves).',
       'inline int'
       ' uchCreakFormerDen()',
       '    { return 3; }'),
     'uch: the creak former')

pair(UCH,
     E('// The creak traverse: the'
       ' scan',
       '// prints an ambiguous "1 0"'
       ' for',
       '// the traversal distance -'
       ' the',
       '// value records as a hole',
       '// pending the PDF read (never'
       ' a',
       '// guess).',
       'inline bool'
       ' uchCreakTraverseIsHole()',
       '    { return true; }'),
     E('// The creak traverse: the'
       ' PDF',
       '// read resolves the ambiguity',
       '// (R419) - the latter noise',
       '// seems to traverse up to 10',
       '// feet distance.',
       'inline int'
       ' uchCreakTraverseFeet()',
       '    { return 10; }'),
     'uch: the creak traverse')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'


def den_pins(pfx, dens, per=8):
    # the per-row denominator pins -
    # EVERY chain opens with an
    # 'if (' (the R418b lesson)
    fn = '%sCastTimeDen' % pfx
    blocks = []
    for k in range(0, len(dens), per):
        chunk = dens[k:k+per]
        ls = []
        for j, d in enumerate(chunk):
            i = k + j
            c = '%s(%d) != %d' % (fn, i, d)
            if j == 0:
                ls.append('        if (' + c)
            else:
                ls.append('                '
                          '|| ' + c)
        ls[-1] += ') ++bad;'
        blocks.append(E(*ls))
    return (NL + NL).join(blocks)


# ---- the R415 block ----
old = E('        // ---- the hole'
        ' family ----',
        '        if (!ucpCastTimes'
        'AreHoles())',
        '            ++bad;')
new = E('        // ---- the casting'
        ' times ----',
        '        // (the PDF read'
        ' resolves the',
        '        // family - R419)')
new += NL + NL + den_pins('ucp',
                          FAM[0][3])
pair(RT, old, new,
     'regtest: the person-'
     'affecting casting times')

# ---- the R416 block ----
old = E('        // ---- the hole'
        ' families ----',
        '        if (!ucoCastTimes'
        'AreHoles()',
        '                || !ucoRange'
        'UnitsAreHoles()',
        '                || !ucoSlow'
        'PoisonDeferIsHole())',
        '            ++bad;')
new = E('        // ---- the casting'
        ' times ----',
        '        // (the PDF read'
        ' resolves the',
        '        // family - R419)')
new += NL + NL + den_pins('uco',
                          FAM[1][3])
new += NL + NL + E(
    '        // ---- the resolved'
    ' reads (the PDF read - R419)',
    '        if (!ucoRangeUnit'
    'IsInch()',
    '                || ucoSlow'
    'PoisonDeferDays()',
    '                != 1) ++bad;')
pair(RT, old, new,
     'regtest: the personal'
     ' casting times')

# ---- the R417 block ----
old = E('        // ---- the hole'
        ' families ----',
        '        if (!uchCastTimes'
        'AreHoles()',
        '                || !uchRange'
        'UnitsAreHoles()',
        '                || !uchCreak'
        'FormerIsHole()',
        '                || !uchCreak'
        'TraverseIsHole())',
        '            ++bad;')
new = E('        // ---- the casting'
        ' times ----',
        '        // (the PDF read'
        ' resolves the',
        '        // family - R419)')
new += NL + NL + den_pins('uch',
                          FAM[2][3])
new += NL + NL + E(
    '        // ---- the resolved'
    ' reads (the PDF read - R419)',
    '        if (!uchRangeUnit'
    'IsInch()',
    '                || uchCreak'
    'FormerDen()',
    '                != 3',
    '                || uchCreak'
    'TraverseFeet()',
    '                != 10) ++bad;')
pair(RT, old, new,
     'regtest: the haunting-'
     'sound casting times')

# ---- the R416 area census ----
old = E('                || ucoArea'
        'KindCount(UCO_AREA_HOLE)'
        ' != 2) ++bad;')
new = E('                || ucoArea'
        'KindCount(UCO_AREA_SPHERE)',
        '                != 1',
        '                || ucoArea'
        'KindCount(UCO_AREA_LINE)',
        '                != 1',
        '                || ucoArea'
        'KindCount(UCO_AREA_HOLE)',
        '                != 0) ++bad;')
pair(RT, old, new,
     'regtest: the personal area'
     ' census')

# ---- the Bluelight row pins ----
old = E('                || uco'
        'Personal(1)',
        '                   .areaKind'
        ' != -1',
        '                || uco'
        'Personal(1)',
        '                   .areaVal'
        ' != 0) ++bad;')
new = E('                || uco'
        'Personal(1)',
        '                   .areaKind',
        '                   != UCO'
        '_AREA_SPHERE',
        '                || uco'
        'Personal(1)',
        '                   .areaVal'
        ' != 3) ++bad;')
pair(RT, old, new,
     'regtest: the Bluelight'
     ' area row')

# ---- the Firefinger row pins ----
old = E('                || uco'
        'Personal(3)',
        '                   .areaKind'
        ' != -1',
        '                || uco'
        'Personal(3)',
        '                   .areaVal'
        ' != 0) ++bad;')
new = E('                || uco'
        'Personal(3)',
        '                   .areaKind',
        '                   != UCO'
        '_AREA_LINE',
        '                || uco'
        'Personal(3)',
        '                   .areaVal'
        ' != 6) ++bad;')
pair(RT, old, new,
     'regtest: the Firefinger'
     ' area row')

# ---- the R419 audit block ----
AUD = E(
    '    // ---- R419: the cantrip',
    '    // casting-time resolution',
    '    // part 2 pin audit ----',
    '    // The PDF read completes the',
    '    // resolution: the R415',
    '    // (person-affecting), R416',
    '    // (personal) and R417',
    '    // (haunting-sound) casting-',
    '    // time hole families resolve',
    '    // - 28 cells, all clean unit',
    '    // fractions one segment over',
    '    // the denominator. The',
    '    // denominator censuses count',
    '    // (the person-affecting 1/3/2/4',
    '    // at 1/2, 1/3, 1/8, 1/10; the',
    '    // personal 7/3/0/0; the',
    '    // haunting-sound 0/0/5/3 - the',
    '    // 1/6 lands inside the 2..10',
    '    // band the p. 45 header prints),',
    '    // each family census totals its',
    '    // roster count, and every',
    '    // denominator sits in the band.',
    '    // The read also resolves the two',
    '    // R416 areas (the sphere and the',
    '    // line - the values cross-derive',
    '    // against the mechanics pins: 3',
    '    // inches == the 1/4 foot sphere,',
    '    // 6 inches == the 1/2 foot line),',
    '    // the range units (the AD&D 1"',
    '    // notation), the slow-poison defer',
    '    // (1 day) and the creak reads',
    '    // (the former 1/3 segment, the',
    '    // traverse 10 feet); census',
    '    // 345 -> 346.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        if (ucpCastTimeDenCount(2)'
    ' != 1',
    '                || ucpCastTime'
    'DenCount(3) != 3',
    '                || ucpCastTime'
    'DenCount(8) != 2',
    '                || ucpCastTime'
    'DenCount(10) != 4)',
    '            ++bad;',
    '        if (ucoCastTimeDenCount(2)'
    ' != 7',
    '                || ucoCastTime'
    'DenCount(3) != 3',
    '                || ucoCastTime'
    'DenCount(8) != 0',
    '                || ucoCastTime'
    'DenCount(10) != 0)',
    '            ++bad;',
    '        if (uchCastTimeDenCount(2)'
    ' != 0',
    '                || uchCastTime'
    'DenCount(3) != 0',
    '                || uchCastTime'
    'DenCount(6) != 5',
    '                || uchCastTime'
    'DenCount(10) != 3)',
    '            ++bad;',
    '        if (ucpCastTimeDenCount(2)',
    '                + ucpCastTime'
    'DenCount(3)',
    '                + ucpCastTime'
    'DenCount(8)',
    '                + ucpCastTime'
    'DenCount(10)',
    '                != 10) ++bad;',
    '        if (ucoCastTimeDenCount(2)',
    '                + ucoCastTime'
    'DenCount(3)',
    '                + ucoCastTime'
    'DenCount(8)',
    '                + ucoCastTime'
    'DenCount(10)',
    '                != 10) ++bad;',
    '        if (uchCastTimeDenCount(2)',
    '                + uchCastTime'
    'DenCount(3)',
    '                + uchCastTime'
    'DenCount(6)',
    '                + uchCastTime'
    'DenCount(10)',
    '                != 8) ++bad;',
    '        // the 2..10 norm band',
    '        for (int i = 0; i < 10;',
    ' ++i)',
    '            if (ucpCastTimeDen(i)'
    ' < 2',
    '                || ucpCastTimeDen(i)'
    ' > 10)',
    '                ++bad;',
    '        for (int i = 0; i < 10;',
    ' ++i)',
    '            if (ucoCastTimeDen(i)'
    ' < 2',
    '                || ucoCastTimeDen(i)'
    ' > 10)',
    '                ++bad;',
    '        for (int i = 0; i < 8;',
    ' ++i)',
    '            if (uchCastTimeDen(i)'
    ' < 2',
    '                || uchCastTimeDen(i)'
    ' > 10)',
    '                ++bad;',
    '        // the resolved areas cross-',
    '        // derive against the',
    '        // standing mechanics pins',
    '        if (ucoPersonal(1).areaVal',
    '                != ucoBluelight'
    'SphereInches()',
    '                || ucoPersonal(3)'
    '.areaVal',
    '                != ucoFirefinger'
    'JetInches())',
    '            ++bad;',
    '        // the per-row denominator',
    '        // pins - fail on any wrong',
    '        // cell (the mirror eval)',
    )
AUD += NL + den_pins('ucp', FAM[0][3]) \
     + NL + NL + den_pins('uco', FAM[1][3]) \
     + NL + NL + den_pins('uch', FAM[2][3])
AUD += NL + E(
    '        printf("R419 UA cantrip'
    ' cast-'
    'times part 2 pin'
    ' audit: bad %d'
    + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R419 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '      - AMENDED R418: the PDF'),
    E(
    '      - AMENDED R419: the PDF',
    '        read completes - the',
    '        casting-time hole',
    '        families of the person-',
    '        affecting (R415),',
    '        personal (R416) and',
    '        haunting-sound (R417)',
    '        descriptions resolve: 28',
    '        cells, every one a clean',
    '        unit fraction one segment',
    '        over the denominator (the',
    '        person-affecting 1/3/2/4,',
    '        the personal 7/3/0/0, the',
    '        haunting-sound 0/0/5/3 -',
    '        the 1/6 lands inside the',
    '        2..10 band the p. 45',
    '        header prints); the two',
    '        R416 areas resolve (the',
    '        Bluelight 1/4 foot sphere',
    '        and the Firefinger 1/2',
    '        foot line - NEW area',
    '        kinds, the values',
    '        cross-deriving against',
    '        the mechanics pins), the',
    '        range units resolve (the',
    '        AD&D 1" notation), the',
    '        slow-poison defer pins (1',
    '        day) and the creak reads',
    '        pin (the former 1/3',
    '        segment, the traverse 10',
    '        feet); the hole flags come',
    '        off - the MU cantrip',
    '        descriptions now stand',
    '        hole-free.',
    '      - AMENDED R418: the PDF'),
    'gap: the MU cantrips box takes'
    ' R419')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 346:
    die('the census %d' % s.count('audit: bad'))
if s.count('R419 UA cantrip cast-'
           'times part 2 pin'
           ' audit') != 1:
    die('the R419 audit label')

# the hole flags are gone
for flag in ('ucpCastTimesAreHoles',
             'ucoCastTimesAreHoles',
             'uchCastTimesAreHoles',
             'ucoRangeUnitsAreHoles',
             'uchRangeUnitsAreHoles',
             'ucoSlowPoisonDeferIsHole',
             'uchCreakFormerIsHole',
             'uchCreakTraverseIsHole'):
    if s.count(flag) != 0:
        die('the %s flag survives' % flag)
    for pfx, path, n, dens in FAM:
        if flag in rd(path):
            die('the %s header flag'
                ' survives' % flag)

# the no-bare-|| gate (the R418b
# lesson): a pin chain line is
# legal only when the line before
# it is still the chain
prev = ''
for n, ln in enumerate(s.split(NL), 1):
    if _re.match(
            r'^ +\|\| \w+CastTimeDen\(',
            ln) and 'CastTimeDen' not in prev:
        die('an orphaned pin chain at'
            ' regtest:%d' % n)
    prev = ln

# the mirror eval (the R418b gate,
# now standing): every regtest pin
# holds against the header D[] -
# ALL six families (the R418 part-1
# rows ride uacantrips1/2/3.h)
DENS = {}
DENSRC = [('ucn', 'rules/uacantrips1.h',
           20),
          ('ucr', 'rules/uacantrips2.h',
           12),
          ('ucl', 'rules/uacantrips3.h',
           6)] + [(f[0], f[1], f[2])
                 for f in FAM]
for dpfx, dpath, dn in DENSRC:
    code = rd(dpath)
    m = _re.search(
        r'static const int D\[(\d+)\]'
        r' = \{(.*?)\};', code, _re.S)
    if not m:
        die('no D[] array in %s' % dpath)
    D = [int(x) for x in
         _re.findall(r'\d+', m.group(2))]
    if len(D) != dn:
        die('the D[] roster count in %s'
            % dpath)
    DENS[dpfx] = D
for pfx, path, n, dens in FAM:
    if DENS[pfx] != dens:
        die('the D[] read mismatch in'
            ' %s' % path)

PIN = _re.compile(
    r'(\w+)CastTimeDen\((\d+)\)'
    r' != (\d+)')
for n, ln in enumerate(s.split(NL), 1):
    for m in PIN.finditer(ln):
        pfx, i, d = (m.group(1),
                     int(m.group(2)),
                     int(m.group(3)))
        if pfx not in DENS:
            die('an unknown pin prefix'
                ' at regtest:%d' % n)
        if i >= len(DENS[pfx]):
            die('a pin index past the'
                ' roster at regtest:%d'
                % n)
        if DENS[pfx][i] != d:
            die('a wrong pin at'
                ' regtest:%d' % n)

# the R412b resolution guard: every
# symbol the audits call is defined
for pfx, path, n, dens in FAM:
    _used = set(_re.findall(
        r'\b%s\w+' % pfx, s))
    _def = set(_re.findall(
        r'\b%s\w+' % pfx, rd(path)))
    if _used - _def:
        die('undefined %s calls %s'
            % (pfx, sorted(_used - _def)))

# the inline counts
for pfx, path, n, dens in FAM:
    p = rd(path)
    want = {'ucp': 19, 'uco': 29,
            'uch': 18}[pfx]
    if p.count('inline') != want:
        die('the %s inline count %d'
            % (pfx, p.count('inline')))
    if not p.endswith(NL):
        die('the %s header trailing'
            ' newline' % pfx)

# the R412b class guard on each
# amended header
for pfx, path, n, dens in FAM:
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
if g.count('AMENDED R419') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R419'))

for path, mark in (
        ('rules/uacantrips4.h',
         'ucpCastTimeDenCount'),
        ('rules/uacantrips5.h',
         'ucoRangeUnitIsInch'),
        ('rules/uacantrips6.h',
         'uchCreakTraverseFeet'),
        (RT, 'R419 UA cantrip cast-'),
        (SD, 'R418 landed')):
    if mark not in rd(path):
        die('%s carries no R419 round'
            % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    for pfx in ('ucp', 'uco', 'uch'):
        if _re.search(r'\b%s\w' % pfx,
                      rd(path)):
            die('%s calls the %s pins'
                ' early' % (path, pfx))

print('R419 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the cantrip casting-')
print('  time resolution part 2 -')
print('  the PDF read resolves the')
print('  person-affecting, personal')
print('  and haunting-sound families')
print('  (28 cells, all clean unit')
print('  fractions; the 1/6 sits in')
print('  the band), the two R416')
print('  areas, the range units, the')
print('  slow-poison defer and the')
print('  creak reads; the hole flags')
print('  come off - the MU cantrip')
print('  descriptions now stand')
print('  hole-free; census 345 -> 346')
print('commit: R419: the cantrip'
      ' casting-time resolution'
      ' part 2 (census 346)')

