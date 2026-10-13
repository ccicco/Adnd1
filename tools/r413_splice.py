#!/usr/bin/env python3
# R413: the UA REVERSED CANTRIP
# DESCRIPTIONS (pp. 47-48) - the
# second of the six MU cantrip
# description rounds; the R363
# illusionist-cantrips and the
# R412 useful-cantrips precedents
# ride (the descriptions pin; the
# casting-time fraction cells
# garble in the scan and record
# as holes pending the PDF
# read). The clean djvu scan
# carries all 12 reversed blocks;
# the systematic OCR reads
# resolve with independent
# confirmation: the school tags
# print clean (the census:
# Evocation 3, Abjuration 0,
# Alteration 7, Enchantment 2),
# the area lines print clean for
# ALL 12 blocks this round - the
# one-object eight, the Dirty 4
# sq. yds. (cross-checks the
# Clean 4 sq. yds. from R412),
# the Dusty 10' radius, the Ravel
# Special, the Spill one
# container - ZERO area holes
# (the R412 six-hole posture
# lifts); ALL 12 casting-time
# cells print fraction garbles -
# the whole family records as
# holes pending the PDF read -
# never guesses. The mechanics
# pin clean: the Hairy 2-12 inch
# growth with the under-1-inch
# short-material read and the
# reversed 2-12 day absence, the
# Knot 2-8 rounds, the Tangle
# 3-12 rounds, the Sour 1-pint
# vinegar max, the Spill
# 1-gallon container limit, the
# Tarnish 1 cubic yard (the
# reverse of the R412 shine
# volume - a live cross-check).

# 1. rules/uacantrips2.h (NEW,
#    prefix ucr - verified no
#    collision): the 12 reversed
#    cantrips in R341/R401 roster
#    order, the struct + 17 inline
#    functions.
# 2. regtest.cpp: the include
#    rides the R412 include; the
#    R413 audit block lands before
#    the R227 anchor - the 12
#    names cross-check the
#    R341/R401 roster
#    (uastCantripName(1, i)) live
#    name for name, the count
#    cross-checks
#    uastCantripCount(1), the
#    schools/areas pin per row,
#    the censuses count, the
#    mechanics pin with the
#    tarnish/shine and the
#    dirty/clean pairs
#    cross-checking each other;
#    census 339 -> 340.
# 3. tools/ua_gap_report.md: the
#    MU cantrips box takes
#    AMENDED R413 - the reversed
#    descriptions land; the
#    legerdemain,
#    person-affecting, personal
#    and haunting-sound
#    descriptions stay open.
# 4. The seed takes the R412
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
        'R413 splice ABORT: ' + msg)


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
# Enchantment.
# area kinds: 0 one object, 3
# special, 4 sq. yds., 5
# radius, 6 one container; -1
# the hole sentinel (none this
# round).
S_EVO, S_ABJ = 0, 1
S_ALT, S_ENCH = 2, 3
A_HOLE, A_OBJ = -1, 0
A_SPEC, A_SQYD = 3, 4
A_RADIUS, A_CONT = 5, 6

# The 12 reversed cantrips, in
# the R341/R401 roster order:
# the name, the school, the
# area kind, the area value.
ROWS = [
    ('Curdle', S_ENCH, A_OBJ, 0),
    ('Dirty', S_EVO, A_SQYD, 4),
    ('Dusty', S_EVO, A_RADIUS, 10),
    ('Hairy', S_ALT, A_OBJ, 0),
    ('Knot', S_ALT, A_OBJ, 0),
    ('Ravel', S_ALT, A_SPEC, 0),
    ('Sour', S_EVO, A_OBJ, 0),
    ('Spill', S_ALT, A_CONT, 0),
    ('Tangle', S_ALT, A_OBJ, 0),
    ('Tarnish', S_ALT, A_OBJ, 0),
    ('Untie', S_ALT, A_OBJ, 0),
    ('Wilt', S_ENCH, A_OBJ, 0),
]

SCHOOL_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[1] == s)
    for s in (0, 1, 2, 3))
AREA_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[2] == a)
    for a in (A_OBJ, A_SQYD,
              A_RADIUS, A_SPEC,
              A_CONT, A_HOLE))

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R412 landed 2026-10-13:',
    '  commit 2927bfd (census 339,',
    '  preflight GREEN), the UA',
    '  USEFUL CANTRIP DESCRIPTIONS',
    '  (pp. 45-47) - the first of the',
    '  six MU cantrip description',
    '  rounds; the R363 precedent',
    '  rides; the casting-time family',
    '  records as holes pending the',
    '  PDF read. rules/uacantrips1.h',
    '  (prefix ucn): the 20 useful',
    '  cantrips in roster order, the',
    '  school census 7/4/7/2, the 14',
    '  clean areas, the six "7"-family',
    '  area garbles the recorded',
    '  holes, the mechanics pin (the',
    '  40 F pair, the 1-4 damage pair,',
    '  the salt limits, the tie range,',
    '  the shine revalue, the color',
    '  renewal, the polish floor).',
    '  FIRST RUN RED: the first body',
    '  emitted seven bare comment',
    '  lines in the mechanics pins',
    '  section - the C++ parse broke',
    '  (the R392 comment-emission',
    '  class); the R412b repair body',
    '  re-prefixed the seven lines in',
    '  place and landed both splice',
    '  bodies (commit 2927bfd); two',
    '  new guards ride since (the',
    '  line-classification lint, the',
    '  ucn identifier-resolution',
    '  check). The md5 diverged for',
    '  the TWENTY-FIRST round running',
    '  - benign; the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R412 landed 2026-10-13' in s:
    already.append('seed: the R412 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R412 record')
s = rd(SD)
if s.count('R412 landed 2026-10-13') != 1:
    die('the R412 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uacantrips2.h =========
UC = 'rules/uacantrips2.h'

HDR = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uacantrips2.h',
    '// The UA MAGIC-USER CANTRIP',
    '// DESCRIPTIONS, part 2 (R413):',
    '// the REVERSED category',
    '// (pp. 47-48), 12 cantrips. The',
    '// R363/R412 precedents ride: the',
    '// descriptions pin; the',
    '// casting-time fraction cells',
    '// garble in the scan (the whole',
    '// family) and record as holes',
    '// pending the PDF read - never',
    '// guesses.',
    '//',
    '// The school tags print clean:',
    '// Evocation 3 (Dirty, Dusty,',
    '// Sour), Abjuration 0,',
    '// Alteration 7 (Hairy, Knot,',
    '// Ravel, Spill, Tangle, Tarnish,',
    '// Untie), Enchantment 2 (Curdle,',
    '// Wilt).',
    '//',
    '// The area lines print clean for',
    '// ALL 12 blocks - ZERO area',
    '// holes this round: the',
    '// one-object eight (Curdle,',
    '// Hairy, Knot, Sour, Tangle,',
    '// Tarnish, Untie, Wilt), the',
    '// Dirty 4 sq. yds. (cross-checks',
    '// the Clean 4 sq. yds. from',
    "// R412), the Dusty 10' radius,",
    '// the Ravel Special, the Spill',
    '// one container.',
    '//',
    '// The mechanics pin clean: the',
    '// Hairy 2-12 inch growth with',
    '// the under-1-inch short-',
    '// material read and the',
    '// reversed 2-12 day absence, the',
    '// Knot 2-8 rounds, the Tangle',
    '// 3-12 rounds, the Sour 1-pint',
    '// vinegar max, the Spill',
    '// 1-gallon container limit, the',
    '// Tarnish 1 cubic yard (the',
    '// reverse of the R412 shine',
    '// volume - a live cross-check).',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The school codes.',
    'const int UCR_EVO = 0;',
    'const int UCR_ABJ = 1;',
    'const int UCR_ALT = 2;',
    'const int UCR_ENCH = 3;',
    '',
    '// The area kind codes.',
    'const int UCR_AREA_HOLE = -1;',
    'const int UCR_AREA_OBJECT = 0;',
    'const int UCR_AREA_SPECIAL = 3;',
    'const int UCR_AREA_SQYDS = 4;',
    'const int UCR_AREA_RADIUS = 5;',
    'const int UCR_AREA_CONTAINER = 6;',
    '',
    '// One reversed cantrip: the',
    '// name, the school, the area kind',
    '// and the area value (the Dirty 4',
    "// sq. yds., the Dusty 10'",
    '// radius; 0 when the kind',
    '// carries no number).',
    'struct UcrCantrip {',
    '    const char* name;',
    '    int school;',
    '    int areaKind;',
    '    int areaVal;',
    '};',
    '',
    '// The 12 reversed cantrips, in',
    '// the R341/R401 roster order.',
    'inline const UcrCantrip&'
    ' ucrReversed(int i) {',
    '    static const UcrCantrip'
    ' T[12] = {')

for nm, sc, ak, av in ROWS:
    HDR += NL + E(
        '        { "%s", %d, %d, %d },'
        % (nm, sc, ak, av))

HDR += NL + E(
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 11) i = 11;',
    '    return T[i];',
    '}',
    '',
    '// The count.',
    'inline int ucrReversedCount()',
    '    { return 12; }',
    '',
    '// The school census helper.',
    'inline int ucrSchoolCount(int s)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 12; ++i)',
    '        if (ucrReversed(i).school'
    ' == s)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The area kind census helper.',
    'inline int ucrAreaKindCount(int a)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 12; ++i)',
    '        if (ucrReversed(i)'
    '.areaKind == a)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The casting-time hole family:',
    '// ALL 12 casting-time cells print',
    '// fraction garbles in the scan -',
    '// the whole family records as',
    '// holes pending the PDF read (the',
    '// R363/R412 posture). The Untie',
    '// block prints "Casting time:"',
    '// lowercase - the systematic OCR',
    '// read, noted.',
    'inline bool ucrCastTimesAreHoles()',
    '    { return true; }',
    '',
    '// ---- the mechanics pins ----',
    '',
    '// The Hairy growth range: the',
    '// subject material increases',
    '// from 2 to 12 inches in length.',
    'inline int ucrHairyGrowthMinIn()',
    '    { return 2; }',
    '',
    'inline int ucrHairyGrowthMaxIn()',
    '    { return 12; }',
    '',
    '// The Hairy short-material',
    '// threshold: material under 1',
    '// inch in length.',
    'inline int ucrHairyShortUnderIn()',
    '    { return 1; }',
    '',
    '// The Hairy reversed read: the',
    '// complete absence of growth for',
    '// 2 to 12 days.',
    'inline int ucrHairyAbsence'
    'MinDays()',
    '    { return 2; }',
    '',
    'inline int ucrHairyAbsence'
    'MaxDays()',
    '    { return 12; }',
    '',
    '// The Knot untie range: from 2',
    '// to 8 rounds, minus the',
    '// dexterity reaction bonus.',
    'inline int ucrKnotUntie'
    'MinRounds()',
    '    { return 2; }',
    '',
    'inline int ucrKnotUntie'
    'MaxRounds()',
    '    { return 8; }',
    '',
    '// The Tangle untangle range: 3',
    '// to 12 rounds unless roughly',
    '// done.',
    'inline int ucrTangleUntangle'
    'MinRounds()',
    '    { return 3; }',
    '',
    'inline int ucrTangleUntangle'
    'MaxRounds()',
    '    { return 12; }',
    '',
    '// The Sour vinegar max: about a',
    '// pint appears over the subject.',
    'inline int ucrSourMaxPints()',
    '    { return 1; }',
    '',
    '// The Spill container limit:',
    '// containers of more than about',
    '// gallon size are unaffected.',
    'inline int ucrSpillMaxGallons()',
    '    { return 1; }',
    '',
    '// The Tarnish volume: the object',
    '// must be about 1 cubic yard or',
    '// less - the reverse of the R412',
    '// shine volume (a live cross-',
    '// check).',
    'inline int ucrTarnishMaxCubicYds()',
    '    { return 1; }',
    '',
    '}   // namespace rules',
    '')

newfile(UC, HDR + NL,
        'the reversed cantrips header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uacantrips1.h"  '
     '// R412: the UA useful cantrips',
     E(
    '#include "rules/uacantrips1.h"  '
    '// R412: the UA useful cantrips',
    '#include "rules/uacantrips2.h"  '
    '// R413: the UA reversed'
    ' cantrips'),
     'regtest: the reversed cantrips'
     ' include')

AUD = E(
    '    // ---- R413: the UA',
    '    // reversed cantrips pin',
    '    // audit ----',
    '    // The 12 reversed-category',
    '    // descriptions pin: the names',
    '    // cross-check the R341/R401',
    '    // roster live, the schools and',
    '    // areas pin per row (ZERO',
    '    // area holes this round), the',
    '    // school census counts (3/0/7/2),',
    '    // the casting-time family stays',
    '    // the hole family, the mechanics',
    '    // pin with the tarnish/shine and',
    '    // dirty/clean pairs cross-',
    '    // checking each other; census',
    '    // 339 -> 340.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (ucrReversedCount() != 12)',
    '            ++bad;',
    '        if (uastCantripCount(1)'
    ' != 12)',
    '            ++bad;',
    '        // ---- the school census ----',
    '        if (ucrSchoolCount(UCR_EVO)'
    ' != 3',
    '                || ucrSchoolCount'
    '(UCR_ABJ) != 0',
    '                || ucrSchoolCount'
    '(UCR_ALT) != 7',
    '                || ucrSchoolCount'
    '(UCR_ENCH) != 2) ++bad;',
    '        // ---- the area census ----',
    '        if (ucrAreaKindCount'
    '(UCR_AREA_OBJECT) != 8',
    '                || ucrAreaKindCount'
    '(UCR_AREA_SQYDS) != 1',
    '                || ucrAreaKindCount'
    '(UCR_AREA_RADIUS) != 1',
    '                || ucrAreaKindCount'
    '(UCR_AREA_SPECIAL) != 1',
    '                || ucrAreaKindCount'
    '(UCR_AREA_CONTAINER) != 1',
    '                || ucrAreaKindCount'
    '(UCR_AREA_HOLE) != 0) ++bad;')

# the per-row pins: name (cross-
# checked against the R341/R401
# roster live), school, area
for i, (nm, sc, ak, av) in \
        enumerate(ROWS):
    AUD += NL + E(
        '        if (strcmp(ucrReversed'
        '(%d).name,' % i,
        '                   '
        'uastCantripName(1, %d)) != 0'
        % i,
        '                || ucrReversed'
        '(%d)' % i,
        '                   .school'
        ' != %d' % sc,
        '                || ucrReversed'
        '(%d)' % i,
        '                   .areaKind'
        ' != %d' % ak,
        '                || ucrReversed'
        '(%d)' % i,
        '                   .areaVal'
        ' != %d) ++bad;' % av)

AUD += NL + E(
    '        // ---- the hole family ----',
    '        if (!ucrCastTimesAreHoles())',
    '            ++bad;',
    '        // ---- the mechanics ----',
    '        if (ucrHairyGrowthMinIn()'
    ' != 2',
    '                || ucrHairyGrowth'
    'MaxIn() != 12',
    '                || ucrHairyShort'
    'UnderIn() != 1) ++bad;',
    '        if (ucrHairyAbsence'
    'MinDays() != 2',
    '                || ucrHairyAbsence'
    'MaxDays() != 12) ++bad;',
    '        if (ucrKnotUntieMinRounds()'
    ' != 2',
    '                || ucrKnotUntie'
    'MaxRounds() != 8) ++bad;',
    '        if (ucrTangleUntangle'
    'MinRounds() != 3',
    '                || ucrTangle'
    'UntangleMaxRounds() != 12)',
    '            ++bad;',
    '        if (ucrSourMaxPints() != 1)',
    '            ++bad;',
    '        if (ucrSpillMaxGallons()'
    ' != 1)',
    '            ++bad;',
    '        // ---- the live pairs ----',
    '        // The tarnish volume is the',
    '        // reverse of the R412 shine',
    '        // volume.',
    '        if (ucrTarnishMaxCubicYds()',
    '                != ucnShineMax'
    'CubicYds()) ++bad;',
    '        // The Dirty 4 sq. yds. is',
    '        // the opposite of the Clean',
    '        // 4 sq. yds. (R412).',
    '        if (ucrReversed(1).areaKind',
    '                != UCR_AREA_SQYDS',
    '                || ucrReversed(1)'
    '.areaVal',
    '                != ucnUseful(1)'
    '.areaVal) ++bad;',
    '        printf("R413 UA reversed'
    ' cantrips pin audit: bad %d'
    + chr(92) + 'n\", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R413 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '      - AMENDED R412: the useful',
    '        category descriptions land',
    '        (rules/uacantrips1.h) - the',
    '        20 blocks pin schools (the',
    '        7/4/7/2 census), the 14',
    '        clean areas, the six',
    '        "7"-family garbles and the',
    '        whole casting-time family',
    '        the recorded holes pending',
    '        the PDF read (the R363',
    '        posture), the mechanics pin',
    '        (the 40 F pair, the 1-4',
    '        damage pair, the salt',
    '        limits, the tie range, the',
    '        shine revalue, the color',
    '        renewal, the polish floor);',
    '        the reversed, legerdemain,',
    '        person-affecting, personal',
    '        and haunting-sound',
    '        descriptions stay open.'),
    E(
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
    '        stay open.',
    '      - AMENDED R412: the useful',
    '        category descriptions land',
    '        (rules/uacantrips1.h) - the',
    '        20 blocks pin schools (the',
    '        7/4/7/2 census), the 14',
    '        clean areas, the six',
    '        "7"-family garbles and the',
    '        whole casting-time family',
    '        the recorded holes pending',
    '        the PDF read (the R363',
    '        posture), the mechanics pin',
    '        (the 40 F pair, the 1-4',
    '        damage pair, the salt',
    '        limits, the tie range, the',
    '        shine revalue, the color',
    '        renewal, the polish floor);',
    '        the reversed, legerdemain,',
    '        person-affecting, personal',
    '        and haunting-sound',
    '        descriptions stay open.'),
    'gap: the MU cantrips box takes'
    ' R413')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 340:
    die('the census %d' % s.count('audit: bad'))
if s.count('R413 UA reversed cantrips'
           ' pin audit') != 1:
    die('the R413 audit label')
if s.count('ucrReversed') != 4 * len(ROWS) + 3:
    die('the ucrReversed call count %d'
        % s.count('ucrReversed'))

# the R412b resolution guard:
# every ucr symbol the audit
# calls must be defined in the
# emitted header.
_used = set(_re.findall(r'\bucr\w+', s))
_def = set(_re.findall(r'\bucr\w+',
                       rd(UC)))
if _used - _def:
    die('undefined ucr calls %s'
        % sorted(_used - _def))

p = rd(UC)
if p.count('inline') != 17:
    die('the reversed cantrips inline'
        ' count %d' % p.count('inline'))
if not p.endswith(NL):
    die('the reversed cantrips trailing'
        ' newline')

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
if g.count('AMENDED R413') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R413'))

for path, mark in (
        (UC, 'ucrTarnishMaxCubicYds'),
        (RT, 'ucrReversedCount'),
        (SD, 'R412 landed')):
    if mark not in rd(path):
        die('%s carries no R413 round' % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bucr', rd(path)):
        die('%s calls the pins early'
            % path)

print('R413 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the reversed cantrip')
print('  descriptions pin - the 12')
print('  blocks, the names cross-check')
print('  the R341/R401 roster live, the')
print('  school census 3/0/7/2, ALL 12')
print('  areas clean (zero area holes),')
print('  the casting-time family the')
print('  recorded holes pending the')
print('  PDF read; census 339 -> 340')
print('commit: R413: the UA reversed'
      ' cantrips (census 340)')

