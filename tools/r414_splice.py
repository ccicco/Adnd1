#!/usr/bin/env python3
# R414: the UA LEGERDEMAIN
# CANTRIP DESCRIPTIONS
# (pp. 48-49) - the third of the
# six MU cantrip description
# rounds; the R363/R412/R413
# precedents ride (the
# descriptions pin; the
# casting-time fraction cells
# garble in the scan and record
# as holes pending the PDF
# read). The clean djvu scan
# carries all 6 legerdemain
# blocks; the systematic OCR
# reads resolve with
# independent confirmation: the
# school tags print clean (the
# census: Alteration 3 - Change,
# Mute, Present; Enchantment 1
# - Distract; Illusion 2 - Hide,
# Palm; Evocation 0; Abjuration
# 0 - Illusion a NEW school code
# this round), the area lines
# print clean for ALL 6 blocks -
# the one-object three
# (Change, Hide, Mute), the
# Distract Special, the Palm/
# Present one small item pair
# (a NEW area kind code) -
# ZERO area holes; ALL 6
# casting-time cells print
# fraction garbles - the whole
# family records as holes
# pending the PDF read - never
# guesses. The mechanics pin
# clean: the Change 50% size
# band with the base 1 turn,
# the radical 1 round and the
# slight 1+ day durations, the
# Distract 10-foot range + 1
# segment duration, the Hide
# duration ladder (the base 1
# turn at 2 cubic yards or
# less, minus 1 round per
# additional 2 cubic yards to
# the 1-round floor at 20,
# then minus 1 segment per 2
# additional cubic yards from
# the 9 segments at 22 down to
# 1 segment at 38, over 38
# momentary - the ladder
# cross-checks by derivation:
# 22 + 2*8 = 38 and 9 - 8 = 1),
# the Mute 1 round, the Palm 1
# segment, the Present 2-foot
# radius + the dozen-coin
# capacity + the tankard
# exhaustion.

# 1. rules/uacantrips3.h (NEW,
#    prefix ucl - verified no
#    collision): the 6
#    legerdemain cantrips in
#    R341/R401 roster order,
#    the struct + 23 inline
#    functions.
# 2. regtest.cpp: the include
#    rides the R413 include;
#    the R414 audit block lands
#    before the R227 anchor -
#    the 6 names cross-check
#    the R341/R401 roster
#    (uastCantripName(2, i))
#    live name for name, the
#    count cross-checks
#    uastCantripCount(2), the
#    schools/areas pin per
#    row, the censuses count,
#    the mechanics pin with
#    the hide ladder
#    cross-checking itself by
#    derivation; census
#    340 -> 341.
# 3. tools/ua_gap_report.md:
#    the MU cantrips box takes
#    AMENDED R414 - the
#    legerdemain descriptions
#    land; the
#    person-affecting, personal
#    and haunting-sound
#    descriptions stay open.
# 4. The seed takes the R413
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
        'R414 splice ABORT: ' + msg)


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


def newfile(path, body, label):
    if os.path.exists(path):
        already.append(label)
        return
    wr(path, body)
    applied.append(label)


# ---- the codes ----
# schools: 0 Evocation, 1
# Abjuration, 2 Alteration, 3
# Enchantment, 4 Illusion (NEW
# this round).
# area kinds: 0 one object, 3
# special, 7 one small item
# (NEW this round); -1 the
# hole sentinel (none this
# round).
S_EVO, S_ABJ = 0, 1
S_ALT, S_ENCH = 2, 3
S_ILL = 4
A_HOLE, A_OBJ = -1, 0
A_SPEC = 3
A_SMALL = 7

# The 6 legerdemain cantrips,
# in the R341/R401 roster
# order: the name, the school,
# the area kind, the area
# value.
ROWS = [
    ('Change', S_ALT, A_OBJ, 0),
    ('Distract', S_ENCH, A_SPEC, 0),
    ('Hide', S_ILL, A_OBJ, 0),
    ('Mute', S_ALT, A_OBJ, 0),
    ('Palm', S_ILL, A_SMALL, 0),
    ('Present', S_ALT, A_SMALL, 0),
]

SCHOOL_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[1] == s)
    for s in (0, 1, 2, 3, 4))
AREA_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[2] == a)
    for a in (A_OBJ, A_SPEC,
              A_SMALL, A_HOLE))

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R413 landed 2026-10-13:',
    '  commit a3f059f (census 340,',
    '  preflight GREEN), the UA',
    '  REVERSED CANTRIP',
    '  DESCRIPTIONS (pp. 47-48) -',
    '  the second of the six MU',
    '  cantrip description rounds;',
    '  the R363/R412 precedents',
    '  ride; the casting-time family',
    '  records as holes pending the',
    '  PDF read. rules/',
    '  uacantrips2.h (prefix ucr):',
    '  the 12 reversed cantrips in',
    '  roster order, the school',
    '  census 3/0/7/2, ALL 12 areas',
    '  clean (ZERO area holes - the',
    '  Dirty 4 sq. yds. cross-checks',
    "  the Clean, the Dusty 10'",
    '  radius, the Ravel Special,',
    '  the Spill one container),',
    '  the mechanics pin (the hairy',
    '  growth pair, the knot and',
    '  tangle ranges, the sour pint,',
    '  the spill gallon, the',
    '  tarnish/shine live pair).',
    '  The R412b guards rode their',
    '  first round clean (the',
    '  line-classification lint, the',
    '  ucr identifier-resolution',
    '  check). First-try GREEN. The',
    '  md5 diverged for the',
    '  TWENTY-SECOND round running',
    '  - benign; the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R413 landed 2026-10-13' in s:
    already.append('seed: the R413 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R413 record')
s = rd(SD)
if s.count('R413 landed 2026-10-13') != 1:
    die('the R413 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uacantrips3.h =========
UC = 'rules/uacantrips3.h'

HDR = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uacantrips3.h',
    '// The UA MAGIC-USER CANTRIP',
    '// DESCRIPTIONS, part 3 (R414):',
    '// the LEGERDEMAIN category',
    '// (pp. 48-49), 6 cantrips. The',
    '// R363/R412/R413 precedents',
    '// ride: the descriptions pin;',
    '// the casting-time fraction',
    '// cells garble in the scan (the',
    '// whole family) and record as',
    '// holes pending the PDF read -',
    '// never guesses.',
    '//',
    '// The school tags print clean:',
    '// Alteration 3 (Change, Mute,',
    '// Present), Enchantment 1',
    '// (Distract), Illusion 2 (Hide,',
    '// Palm), Evocation 0,',
    '// Abjuration 0 - Illusion a NEW',
    '// school code this round.',
    '//',
    '// The area lines print clean',
    '// for ALL 6 blocks - ZERO area',
    '// holes: the one-object three',
    '// (Change, Hide, Mute), the',
    '// Distract Special, the Palm/',
    '// Present one small item pair',
    '// (a NEW area kind code).',
    '//',
    '// The mechanics pin clean: the',
    '// Change 50% size band with',
    '// the base 1 turn, the radical',
    '// 1 round and the slight 1+',
    '// day durations, the Distract',
    "// 10-foot range + 1 segment",
    '// duration, the Hide duration',
    '// ladder (the base 1 turn at',
    '// 2 cubic yards or less,',
    '// minus 1 round per additional',
    '// 2 cubic yards to the 1-round',
    '// floor at 20, then minus 1',
    '// segment per 2 additional',
    '// cubic yards from the 9',
    '// segments at 22 down to 1',
    '// segment at 38, over 38',
    '// momentary - the ladder',
    '// cross-checks by derivation:',
    '// 22 + 2*8 = 38 and 9 - 8 = 1),',
    '// the Mute 1 round, the Palm 1',
    '// segment, the Present 2-foot',
    '// radius + the dozen-coin',
    '// capacity + the tankard',
    '// exhaustion.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The school codes (Illusion',
    '// NEW this round).',
    'const int UCL_EVO = 0;',
    'const int UCL_ABJ = 1;',
    'const int UCL_ALT = 2;',
    'const int UCL_ENCH = 3;',
    'const int UCL_ILL = 4;',
    '',
    '// The area kind codes (one',
    '// small item NEW this round).',
    'const int UCL_AREA_HOLE = -1;',
    'const int UCL_AREA_OBJECT = 0;',
    'const int UCL_AREA_SPECIAL = 3;',
    'const int UCL_AREA_SMALLITEM = 7;',
    '',
    '// One legerdemain cantrip:',
    '// the name, the school, the',
    '// area kind and the area value',
    '// (0 when the kind carries no',
    '// number).',
    'struct UclCantrip {',
    '    const char* name;',
    '    int school;',
    '    int areaKind;',
    '    int areaVal;',
    '};',
    '',
    '// The 6 legerdemain cantrips,',
    '// in the R341/R401 roster',
    '// order.',
    'inline const UclCantrip&'
    ' uclLegerdemain(int i) {',
    '    static const UclCantrip'
    ' T[6] = {')

for nm, sc, ak, av in ROWS:
    HDR += NL + E(
        '        { "%s", %d, %d, %d },'
        % (nm, sc, ak, av))

HDR += NL + E(
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    return T[i];',
    '}',
    '',
    '// The count.',
    'inline int uclLegerdemainCount()',
    '    { return 6; }',
    '',
    '// The school census helper.',
    'inline int uclSchoolCount(int s)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 6; ++i)',
    '        if (uclLegerdemain(i)'
    '.school == s)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The area kind census helper.',
    'inline int uclAreaKindCount(int a)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 6; ++i)',
    '        if (uclLegerdemain(i)'
    '.areaKind == a)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The casting-time hole family:',
    '// ALL 6 casting-time cells print',
    '// fraction garbles in the scan -',
    '// the whole family records as',
    '// holes pending the PDF read (the',
    '// R363/R412/R413 posture).',
    'inline bool uclCastTimesAreHoles()',
    '    { return true; }',
    '',
    '// ---- the mechanics pins ----',
    '',
    '// The Change size band: no more',
    '// than a 50% increase or',
    '// decrease in size/volume.',
    'inline int uclChangeSizePctMax()',
    '    { return 50; }',
    '',
    '// The Change base duration: 1',
    '// turn.',
    'inline int uclChangeBaseTurns()',
    '    { return 1; }',
    '',
    '// The Change radical duration:',
    '// a radical change lasts only',
    '// 1 round.',
    'inline int uclChangeRadicalRounds()',
    '    { return 1; }',
    '',
    '// The Change slight duration: a',
    '// very slight alteration lasts',
    '// 1 or more days.',
    'inline int uclChangeSlightDays()',
    '    { return 1; }',
    '',
    '// The Distract range: the',
    '// distraction must be within',
    '// 10 feet of the caster.',
    'inline int uclDistractRangeFt()',
    '    { return 10; }',
    '',
    '// The Distract duration: only',
    '// 1 segment.',
    'inline int'
    ' uclDistractDurationSegments()',
    '    { return 1; }',
    '',
    '// The Hide ladder base: 1 turn',
    '// on an object of 2 cubic yards',
    '// or less in volume.',
    'inline int uclHideBaseCubicYds()',
    '    { return 2; }',
    '',
    'inline int uclHideBaseTurns()',
    '    { return 1; }',
    '',
    '// The Hide ladder round floor:',
    '// reduced by 1 round per',
    '// additional 2 cubic yards',
    '// until, at 20 cubic yards,',
    '// the duration is 1 round.',
    'inline int uclHideRoundCubicYds()',
    '    { return 20; }',
    '',
    '// The Hide ladder segment tail:',
    '// over 20 cubic yards the',
    '// duration drops 1 segment per',
    '// 2 additional cubic yards - 9',
    '// segments at 22 cubic yards.',
    'inline int'
    ' uclHideSegStartCubicYds()',
    '    { return 22; }',
    '',
    'inline int'
    ' uclHideSegStartSegments()',
    '    { return 9; }',
    '',
    '// The Hide ladder segment step:',
    '// 2 cubic yards per segment.',
    'inline int uclHideSegStepCubicYds()',
    '    { return 2; }',
    '',
    '// The Hide ladder floor: 1',
    '// segment at 38 cubic yards;',
    '// anything over 38 at best',
    '// momentarily disappears.',
    'inline int uclHideMinCubicYds()',
    '    { return 38; }',
    '',
    'inline int uclHideMinSegments()',
    '    { return 1; }',
    '',
    '// The Mute duration: but',
    '// 1 round.',
    'inline int uclMuteDurationRounds()',
    '    { return 1; }',
    '',
    '// The Palm duration: the',
    '// illusory duplicate lasts but',
    '// 1 segment.',
    'inline int'
    ' uclPalmDurationSegments()',
    '    { return 1; }',
    '',
    '// The Present radius: within',
    '// 2 feet of the caster.',
    'inline int uclPresentRadiusFt()',
    '    { return 2; }',
    '',
    '// The Present capacity: as many',
    '// as a dozen coins before the',
    '// dweomer fails (a tankard',
    '// exhausts it).',
    'inline int uclPresentMaxCoins()',
    '    { return 12; }',
    '',
    '}   // namespace rules',
    '')

newfile(UC, HDR + NL,
        'the legerdemain cantrips'
        ' header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uacantrips2.h"  '
     '// R413: the UA reversed'
     ' cantrips',
     E(
    '#include "rules/uacantrips2.h"  '
    '// R413: the UA reversed'
    ' cantrips',
    '#include "rules/uacantrips3.h"  '
    '// R414: the UA legerdemain'
    ' cantrips'),
     'regtest: the legerdemain'
     ' cantrips include')

AUD = E(
    '    // ---- R414: the UA',
    '    // legerdemain cantrips pin',
    '    // audit ----',
    '    // The 6 legerdemain',
    '    // descriptions pin: the names',
    '    // cross-check the R341/R401',
    '    // roster live, the schools and',
    '    // areas pin per row (ZERO',
    '    // area holes; Illusion a NEW',
    '    // school code, one small item',
    '    // a NEW area kind), the school',
    '    // census counts (0/0/3/1/2),',
    '    // the casting-time family',
    '    // stays the hole family, the',
    '    // mechanics pin with the hide',
    '    // ladder cross-checking',
    '    // itself by derivation; census',
    '    // 340 -> 341.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (uclLegerdemainCount()'
    ' != 6)',
    '            ++bad;',
    '        if (uastCantripCount(2)'
    ' != 6)',
    '            ++bad;',
    '        // ---- the school census ----',
    '        if (uclSchoolCount(UCL_ALT)'
    ' != 3',
    '                || uclSchoolCount'
    '(UCL_ENCH) != 1',
    '                || uclSchoolCount'
    '(UCL_ILL) != 2',
    '                || uclSchoolCount'
    '(UCL_EVO) != 0',
    '                || uclSchoolCount'
    '(UCL_ABJ) != 0) ++bad;',
    '        // ---- the area census ----',
    '        if (uclAreaKindCount'
    '(UCL_AREA_OBJECT) != 3',
    '                || uclAreaKindCount'
    '(UCL_AREA_SPECIAL) != 1',
    '                || uclAreaKindCount'
    '(UCL_AREA_SMALLITEM) != 2',
    '                || uclAreaKindCount'
    '(UCL_AREA_HOLE) != 0) ++bad;')

# the per-row pins: name (cross-
# checked against the R341/R401
# roster live), school, area
for i, (nm, sc, ak, av) in \
        enumerate(ROWS):
    AUD += NL + E(
        '        if (strcmp'
        '(uclLegerdemain(%d).name,' % i,
        '                   '
        'uastCantripName(2, %d)) != 0'
        % i,
        '                ||'
        ' uclLegerdemain(%d)' % i,
        '                   .school'
        ' != %d' % sc,
        '                ||'
        ' uclLegerdemain(%d)' % i,
        '                   .areaKind'
        ' != %d' % ak,
        '                ||'
        ' uclLegerdemain(%d)' % i,
        '                   .areaVal'
        ' != %d) ++bad;' % av)

AUD += NL + E(
    '        // ---- the hole family ----',
    '        if (!uclCastTimesAreHoles())',
    '            ++bad;',
    '        // ---- the mechanics ----',
    '        if (uclChangeSizePctMax()'
    ' != 50',
    '                || uclChangeBase'
    'Turns() != 1',
    '                || uclChange'
    'RadicalRounds() != 1',
    '                || uclChange'
    'SlightDays() != 1) ++bad;',
    '        if (uclDistractRangeFt()'
    ' != 10',
    '                || uclDistract'
    'DurationSegments() != 1)',
    '            ++bad;',
    '        // ---- the hide ladder ----',
    '        if (uclHideBaseCubicYds()'
    ' != 2',
    '                || uclHideBase'
    'Turns() != 1',
    '                || uclHideRound'
    'CubicYds() != 20) ++bad;',
    '        // The derivation: the',
    '        // segment span (38-22)/2 = 8',
    '        // equals 9 - 1, and the',
    '        // span divides the step.',
    '        if (uclHideSegStart'
    'CubicYds() != 22',
    '                || uclHideSegStart'
    'Segments() != 9',
    '                || uclHideSegStep'
    'CubicYds() != 2',
    '                || uclHideMin'
    'CubicYds() != 38',
    '                || uclHideMin'
    'Segments() != 1) ++bad;',
    '        if ((uclHideMin'
    'CubicYds()',
    '                - uclHideSegStart'
    'CubicYds())',
    '                / uclHideSegStep'
    'CubicYds()',
    '                != uclHideSegStart'
    'Segments()',
    '                - uclHideMin'
    'Segments()',
    '                || (uclHideMin'
    'CubicYds()',
    '                   - uclHideSegStart'
    'CubicYds())',
    '                   % uclHideSegStep'
    'CubicYds() != 0)',
    '            ++bad;',
    '        if (uclMuteDuration'
    'Rounds() != 1',
    '                || uclPalm'
    'DurationSegments() != 1)',
    '            ++bad;',
    '        if (uclPresentRadiusFt()'
    ' != 2',
    '                || uclPresent'
    'MaxCoins() != 12) ++bad;',
    '        printf("R414 UA'
    ' legerdemain cantrips pin'
    ' audit: bad %d'
    + chr(92) + 'n\", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R414 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '      - AMENDED R413: the reversed',
    '        category descriptions land',
    '        (rules/uacantrips2.h) - the',
    '        12 blocks pin schools (the',
    '        3/0/7/2 census), ALL 12',
    '        areas print clean (ZERO',
    '        area holes - the Dirty 4',
    '        sq. yds. cross-checks the',
    "        Clean, the Dusty 10'",
    '        radius, the Ravel Special,',
    '        the Spill one container),',
    '        the whole casting-time',
    '        family the recorded holes',
    '        pending the PDF read (the',
    '        R363/R412 posture), the',
    '        mechanics pin (the hairy',
    '        growth pair, the knot and',
    '        tangle round ranges, the',
    '        sour pint, the spill',
    '        gallon, the tarnish/shine',
    '        live pair); the',
    '        legerdemain, person-',
    '        affecting, personal and',
    '        haunting-sound descriptions',
    '        stay open.'),
    E(
    '      - AMENDED R414: the',
    '        legerdemain descriptions',
    '        land (rules/uacantrips3.h)',
    '        - the 6 blocks pin schools',
    '        (the 0/0/3/1/2 census -',
    '        Illusion a NEW school',
    '        code), ALL 6 areas clean',
    '        (ZERO area holes - the',
    '        one-object three, the',
    '        Distract Special, the',
    '        Palm/Present one small',
    '        item pair, a NEW area',
    '        kind), the whole',
    '        casting-time family the',
    '        recorded holes pending',
    '        the PDF read (the',
    '        R363/R412/R413 posture),',
    '        the mechanics pin (the',
    '        change 50% size band +',
    '        the turn/round/day',
    '        durations, the distract',
    '        10-foot range + segment,',
    '        the HIDE DURATION LADDER',
    '        (1 turn at 2 cubic yards',
    '        to 1 segment at 38,',
    '        cross-checking itself by',
    '        derivation), the mute',
    '        round, the palm segment,',
    '        the present 2-foot radius',
    '        + dozen coins); the',
    '        person-affecting, personal',
    '        and haunting-sound',
    '        descriptions stay open.',
    '      - AMENDED R413: the reversed',
    '        category descriptions land',
    '        (rules/uacantrips2.h) - the',
    '        12 blocks pin schools (the',
    '        3/0/7/2 census), ALL 12',
    '        areas print clean (ZERO',
    '        area holes - the Dirty 4',
    '        sq. yds. cross-checks the',
    "        Clean, the Dusty 10'",
    '        radius, the Ravel Special,',
    '        the Spill one container),',
    '        the whole casting-time',
    '        family the recorded holes',
    '        pending the PDF read (the',
    '        R363/R412 posture), the',
    '        mechanics pin (the hairy',
    '        growth pair, the knot and',
    '        tangle round ranges, the',
    '        sour pint, the spill',
    '        gallon, the tarnish/shine',
    '        live pair); the',
    '        legerdemain, person-',
    '        affecting, personal and',
    '        haunting-sound descriptions',
    '        stay open.'),
    'gap: the MU cantrips box takes'
    ' R414')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 341:
    die('the census %d' % s.count('audit: bad'))
if s.count('R414 UA legerdemain'
           ' cantrips pin audit') != 1:
    die('the R414 audit label')
if s.count('uclLegerdemain') != \
        4 * len(ROWS) + 1:
    die('the uclLegerdemain call count'
        ' %d' % s.count('uclLegerdemain'))

# the R412b resolution guard:
# every ucl symbol the audit
# calls must be defined in the
# emitted header.
_used = set(_re.findall(r'\bucl\w+', s))
_def = set(_re.findall(r'\bucl\w+',
                       rd(UC)))
if _used - _def:
    die('undefined ucl calls %s'
        % sorted(_used - _def))

p = rd(UC)
if p.count('inline') != 23:
    die('the legerdemain cantrips'
        ' inline count %d'
        % p.count('inline'))
if not p.endswith(NL):
    die('the legerdemain cantrips'
        ' trailing newline')

# the R412b class guard: every
# emitted header line must be a
# comment, a preprocessor line,
# or classifiable C++ code (no
# bare prose survives this).
for ln in p.split(NL):
    if ln and not ln.startswith((
            '//', '#', 'namespace',
            'inline', 'const', 'struct',
            '{', '}', '    ',
            '        ',
            '            ')):
        die('a non-code header line'
            ' %r' % ln[:44])

g = rd(GP)
if g.count('AMENDED R414') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R414'))

for path, mark in (
        (UC, 'uclPresentMaxCoins'),
        (RT, 'uclLegerdemainCount'),
        (SD, 'R413 landed')):
    if mark not in rd(path):
        die('%s carries no R414 round' % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bucl', rd(path)):
        die('%s calls the pins early'
            % path)

print('R414 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the legerdemain cantrip')
print('  descriptions pin - the 6')
print('  blocks, the names cross-check')
print('  the R341/R401 roster live, the')
print('  school census 0/0/3/1/2')
print('  (Illusion new), ALL 6 areas')
print('  clean (zero area holes), the')
print('  hide duration ladder pins +')
print('  cross-checks itself, the')
print('  casting-time family the')
print('  recorded holes pending the')
print('  PDF read; census 340 -> 341')
print('commit: R414: the UA'
      ' legerdemain cantrips'
      ' (census 341)')

