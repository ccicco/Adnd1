# R412b: the useful cantrips
# HEADER REPAIR - the first
# R412 body emitted seven
# bare comment lines in the
# mechanics pins section (the
# comment continuations lost
# their // prefix) and the C++
# parse broke on Termux (the
# R392 comment-emission class);
# this body re-issues the same
# five patches with the header
# fixed, plus an in-place repair
# patch for a tree that already
# ran the broken body (the
# R392b/R400b precedent). The
# audit label stays R412; the
# census stays 339.
# DESCRIPTIONS (pp. 45-47) - the
# first of the six MU cantrip
# description rounds; the
# R363 illusionist-cantrips
# precedent rides (the
# descriptions pin; the
# casting-time fraction cells
# garble in the scan and
# record as holes pending
# the PDF read). The clean
# djvu scan carries all 20
# useful-category blocks;
# the systematic OCR reads
# resolve with independent
# confirmation: the school
# tags print clean (the
# census: Evocation 7,
# Abjuration 4, Alteration
# 7, Enchantment 2), the
# area lines print clean
# for 14 blocks (the
# one-object eight, the
# 1' cube pair, the cubic
# yard pair, the Clean 4
# sq. yds., the Stitch
# Special) while the six
# "7"-family garbles
# (Dampen, Dry, Dust,
# Exterminate, Gather,
# Sprout) record as holes
# pending the PDF read -
# never guesses. The
# mechanics pin clean:
# the Chill/Warm 40 F
# pair, the Freshen/Salt
# 1-4 damage pair, the
# Salt 4 sq. yds./30
# gallons limits, the Tie
# 1' range, the Shine 1
# cubic yard + the DMG
# p. 26 revalue at -1
# once only, the Color 30
# day renewal, the Polish
# 1,000 sq. ft. floor.
#
# 1. rules/uacantrips1.h
#    (NEW, prefix ucn, 16
#    inline functions + the
#    UcnCantrip struct): the
#    20 useful cantrips with
#    the school and area
#    codes, the six area
#    holes, the mechanics
#    pins, the casting-time
#    hole family.
# 2. regtest.cpp: the
#    include rides the R401
#    cantrip tier include;
#    the R412 audit lands
#    before the R227 anchor -
#    the 20 names cross-check
#    the R341/R401 roster
#    (uastCantripName(0, i))
#    live name for name, the
#    count cross-checks
#    uastCantripCount(0) and
#    the R401 census, the
#    schools and areas pin
#    per row, the school and
#    area censuses count, the
#    mechanics pin with the
#    chill/warm and
#    freshen/salt pairs
#    cross-checking each
#    other; census 338 -> 339.
# 3. tools/ua_gap_report.md:
#    the MU cantrips box takes
#    an AMENDED R412 note -
#    the useful-category
#    descriptions land; the
#    five remaining categories
#    (the reversed, the
#    legerdemain, the
#    person-affecting, the
#    personal, the
#    haunting-sound) stay open
#    on their descriptions.
# 4. The seed takes the
#    R411 record.

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
        'R412 splice ABORT: ' + msg)


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
# area kinds: 0 one object,
# 1 the 1' cube, 2 the cubic
# yard, 3 special, 4 the
# Clean sq-yds (value 4),
# -1 the garble hole.
S_EVO, S_ABJ, S_ALT, S_ENCH = \
    0, 1, 2, 3
A_OBJ, A_CUBE, A_CYD, A_SPEC, \
    A_SQYD, A_HOLE = 0, 1, 2, 3, 4, -1

# ---- the data (the print,
# ---- alphabetical roster order)
# (name, school, areaKind,
#  areaVal)
ROWS = [
    ("Chill", S_EVO, A_CUBE, 1),
    ("Clean", S_ABJ, A_SQYD, 4),
    ("Color", S_EVO, A_CYD, 1),
    ("Dampen", S_EVO, A_HOLE, 0),
    ("Dry", S_ABJ, A_HOLE, 0),
    ("Dust", S_ABJ, A_HOLE, 0),
    ("Exterminate", S_ABJ, A_HOLE, 0),
    ("Flavor", S_ENCH, A_OBJ, 0),
    ("Freshen", S_ENCH, A_OBJ, 0),
    ("Gather", S_ALT, A_HOLE, 0),
    ("Polish", S_ALT, A_OBJ, 0),
    ("Salt", S_EVO, A_OBJ, 0),
    ("Shine", S_ALT, A_OBJ, 0),
    ("Spice", S_EVO, A_OBJ, 0),
    ("Sprout", S_ALT, A_HOLE, 0),
    ("Stitch", S_ALT, A_SPEC, 0),
    ("Sweeten", S_EVO, A_OBJ, 0),
    ("Tie", S_ALT, A_OBJ, 0),
    ("Warm", S_EVO, A_CUBE, 1),
    ("Wrap", S_ALT, A_CYD, 1),
]

if len(ROWS) != 20:
    raise SystemExit('the row count')
if sorted(r[0] for r in ROWS) != \
        [r[0] for r in ROWS]:
    raise SystemExit('the roster order')
SCH_N = [sum(1 for r in ROWS
             if r[1] == s)
         for s in range(4)]
if SCH_N != [7, 4, 7, 2]:
    raise SystemExit('the school census'
                     ' %r' % SCH_N)
AREA_N = [sum(1 for r in ROWS
              if r[2] == a)
          for a in (A_OBJ, A_CUBE,
                    A_CYD, A_SPEC,
                    A_SQYD)]
HOLE_N = sum(1 for r in ROWS
             if r[2] == A_HOLE)
if AREA_N != [8, 2, 2, 1, 1] \
        or HOLE_N != 6:
    raise SystemExit('the area census')

TABLE = []
for nm, sc, ak, av in ROWS:
    TABLE.append(
        '        { "%s", %d, %d,'
        ' %d },' % (nm, sc, ak, av))

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R411 landed 2026-10-13:',
    '  commit 94e9302 (census 338,',
    '  preflight GREEN), the UA',
    '  Appendix S MOVE values -',
    '  rules/uamoves.h (prefix umv)',
    '  - the 23 rates, the five',
    '  alternates, the Aerdrie',
    '  flight-only flag; the Shargaas',
    '  garble the recorded hole; the',
    '  sanity ladders live; the',
    '  pantheon prose alone stays open',
    '  in Appendix S. The md5 diverged',
    '  for the nineteenth round',
    '  running - benign; the md5',
    '  stays advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R411 landed 2026-10-13' in s:
    already.append('seed: the R411 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R411 record')
s = rd(SD)
if s.count('R411 landed 2026-10-13') != 1:
    die('the R411 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uacantrips1.h =========
UC = 'rules/uacantrips1.h'

HDR = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uacantrips1.h',
    '// The UA MAGIC-USER CANTRIP',
    '// DESCRIPTIONS, part 1 (R412):',
    '// the USEFUL category (pp. 45-47),',
    '// 20 cantrips. The R363',
    '// illusionist-cantrips precedent',
    '// rides: the descriptions pin; the',
    '// casting-time fraction cells garble',
    '// in the scan ("/? segment", "V?",',
    "// 'h', 'k, Tfe, '/e - the whole",
    '// family) and record as holes',
    '// pending the PDF read - never',
    '// guesses.',
    '//',
    '// The school tags print clean:',
    '// Evocation 7 (Chill, Color,',
    '// Dampen, Salt, Spice, Sweeten,',
    '// Warm), Abjuration 4 (Clean, Dry,',
    '// Dust, Exterminate), Alteration 7',
    '// (Gather, Polish, Shine, Sprout,',
    '// Stitch, Tie, Wrap), Enchantment',
    '// 2 (Flavor, Freshen).',
    '//',
    '// The area lines print clean for',
    '// 14 blocks: the one-object eight',
    '// (Flavor, Freshen, Polish, Salt,',
    '// Shine, Spice, Sweeten, Tie), the',
    "// 1' cube pair (Chill, Warm), the",
    '// cubic yard pair (Color, Wrap),',
    '// the Clean 4 sq. yds., the Stitch',
    '// Special. The six "7"-family',
    '// garbles (Dampen, Dry, Dust',
    "// 70', Exterminate, Gather,",
    '// Sprout) record as area holes',
    '// pending the PDF read.',
    '//',
    '// The mechanics pin clean: the',
    '// Chill/Warm 40 F pair (both',
    '// directions cross-check), the',
    '// Freshen/Salt 1-4 damage pair,',
    '// the Salt 4 sq. yds. and 30',
    '// gallons limits, the Tie 1 range',
    '// with the knot forms, the Shine',
    '// 1 cubic yard with the DMG p. 26',
    '// revalue at -1 once only, the',
    '// Color 30-day renewal, the Polish',
    '// 1,000 sq. ft. floor.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The school codes.',
    'const int UCN_EVO = 0;',
    'const int UCN_ABJ = 1;',
    'const int UCN_ALT = 2;',
    'const int UCN_ENCH = 3;',
    '',
    '// The area kind codes.',
    'const int UCN_AREA_HOLE = -1;',
    'const int UCN_AREA_OBJECT = 0;',
    'const int UCN_AREA_CUBEFoot = 1;',
    'const int UCN_AREA_CUBICyd = 2;',
    'const int UCN_AREA_SPECIAL = 3;',
    'const int UCN_AREA_SQYDS = 4;',
    '',
    '// One useful cantrip: the name,',
    '// the school, the area kind and',
    '// the area value (the Clean 4 sq.',
    '// yds.; 0 when the kind carries',
    '// no number).',
    'struct UcnCantrip {',
    '    const char* name;',
    '    int school;',
    '    int areaKind;',
    '    int areaVal;',
    '};',
    '',
    '// The 20 useful cantrips, in the',
    '// R341/R401 roster order.',
    'inline const UcnCantrip&'
    ' ucnUseful(int i) {',
    '    static const UcnCantrip T[20]'
    ' = {',
    *TABLE,
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 19) i = 19;',
    '    return T[i];',
    '}',
    '',
    'inline int ucnUsefulCount()',
    '    { return 20; }',
    '',
    '// The school census.',
    'inline int ucnSchoolCount(int s) {',
    '    int n = 0;',
    '    for (int i = 0; i < 20; ++i)',
    '        if (ucnUseful(i).school == s)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The area kind census.',
    'inline int ucnAreaKindCount(int a) {',
    '    int n = 0;',
    '    for (int i = 0; i < 20; ++i)',
    '        if (ucnUseful(i).areaKind == a)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The casting-time hole family:',
    '// ALL 20 casting-time cells print',
    '// fraction garbles in the scan -',
    '// the whole family records as',
    '// holes pending the PDF read (the',
    '// R363 illusionist-cantrips',
    '// posture).',
    'inline bool ucnCastTimesAreHoles()',
    '    { return true; }',
    '',
    '// ---- the mechanics pins ----',
    '',
    '// The Chill/Warm temperature delta',
    '// (both about 40 F; the pair',
    '// cross-checks).',
    'inline int ucnTempDeltaF()',
    '    { return 40; }',
    '',
    '// The Freshen damage max (1-4 on',
    '// a creature harmed by purify food',
    '// and drink).',
    'inline int ucnFreshenDmgMax()',
    '    { return 4; }',
    '',
    '// The Salt damage max (1-4 on a',
    '// salt-averse creature; the pair',
    '// cross-checks freshen).',
    'inline int ucnSaltDmgMax()',
    '    { return 4; }',
    '',
    '// The Salt object limits: about 4',
    '// square yards or 30 gallons.',
    'inline int ucnSaltObjectSqYds()',
    '    { return 4; }',
    '',
    'inline int ucnSaltGallons()',
    '    { return 30; }',
    '',
    '// The Tie range: the similar end',
    '// within 1 foot.',
    'inline int ucnTieRangeFt()',
    '    { return 1; }',
    '',
    '// The Shine volume: a single',
    '// object up to about 1 cubic yard.',
    'inline int ucnShineMaxCubicYds()',
    '    { return 1; }',
    '',
    '// The Shine revalue: roll again',
    '// on the DMG p. 26 table with a',
    '// -1 die modifier, once only.',
    'inline int ucnShineRevalueDieMod()',
    '    { return -1; }',
    '',
    'inline bool ucnShineRevalueOnceOnly()',
    '    { return true; }',
    '',
    '// The Color renewal: the effect',
    '// must be renewed every 30 days.',
    'inline int ucnColorRenewDays()',
    '    { return 30; }',
    '',
    '// The Polish floor: up to 1,000',
    '// square feet.',
    'inline int ucnPolishFloorSqFt()',
    '    { return 1000; }',
    '',
    '}   // namespace rules',
    '')

newfile(UC, HDR + NL,
        'the useful cantrips header')

# ==== (b2) the broken-body repair ====
# A tree that ran the first
# R412 body carries the seven
# bare comment lines; the fix
# re-prefixes each in place
# (idempotent: a fixed or a
# fresh-written header carries
# none of the bare forms).
BARE = (
    '(both about 40 F; the pair',
    'square yards or 30 gallons.',
    'within 1 foot.',
    'object up to about 1 cubic'
    ' yard.',
    '-1 die modifier, once only.',
    'must be renewed every 30'
    ' days.',
    'square feet.')
s = rd(UC)
nb = sum(1 for b in BARE
         if NL + b + NL in s)
if nb == 0:
    already.append('the header repair')
elif nb != 7:
    die('the header repair count'
        ' %d (partial body)' % nb)
else:
    for b in BARE:
        s = s.replace(NL + b + NL,
                      NL + '// ' + b + NL)
    wr(UC, s)
    applied.append('the header repair')
s = rd(UC)
for b in BARE:
    if NL + '// ' + b + NL not in s:
        die('the repaired line %r'
            % b[:30])

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/cantriptier.h"  '
     '// R401: the UA cantrip tier',
     E(
    '#include "rules/cantriptier.h"  '
    '// R401: the UA cantrip tier',
    '#include "rules/uacantrips1.h"  '
    '// R412: the UA useful cantrips'),
     'regtest: the useful cantrips'
     ' include')

AUD = E(
    '    // ---- R412: the UA useful',
    '    // cantrips pin audit ----',
    '    // The 20 useful-category',
    '    // descriptions pin: the names',
    '    // cross-check the R341/R401',
    '    // roster live, the schools and',
    '    // areas pin per row, the school',
    '    // census counts (7/4/7/2), the',
    '    // six area garbles record as',
    '    // holes pending the PDF read,',
    '    // the casting-time family stays',
    '    // the hole family, the mechanics',
    '    // pin with the chill/warm and',
    '    // freshen/salt pairs cross-',
    '    // checking each other; census',
    '    // 338 -> 339.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (ucnUsefulCount() != 20)',
    '            ++bad;',
    '        if (uastCantripCount(0) != 20)',
    '            ++bad;',
    '        if (cantMuCategoryCount() != 6)',
    '            ++bad;',
    '        // ---- the school census ----',
    '        if (ucnSchoolCount(UCN_EVO)'
    ' != 7',
    '                || ucnSchoolCount'
    '(UCN_ABJ) != 4',
    '                || ucnSchoolCount'
    '(UCN_ALT) != 7',
    '                || ucnSchoolCount'
    '(UCN_ENCH) != 2) ++bad;',
    '        // ---- the area census ----',
    '        if (ucnAreaKindCount'
    '(UCN_AREA_OBJECT) != 8',
    '                || ucnAreaKindCount'
    '(UCN_AREA_CUBEFoot) != 2',
    '                || ucnAreaKindCount'
    '(UCN_AREA_CUBICyd) != 2',
    '                || ucnAreaKindCount'
    '(UCN_AREA_SPECIAL) != 1',
    '                || ucnAreaKindCount'
    '(UCN_AREA_SQYDS) != 1',
    '                || ucnAreaKindCount'
    '(UCN_AREA_HOLE) != 6) ++bad;')

# the per-row pins: name (cross-
# checked against the R341/R401
# roster live), school, area
for i, (nm, sc, ak, av) in \
        enumerate(ROWS):
    AUD += NL + E(
        '        if (strcmp(ucnUseful(%d)'
        '.name,' % i,
        '                   '
        'uastCantripName(0, %d)) != 0'
        % i,
        '                || ucnUseful(%d)'
        '.school != %d' % (i, sc),
        '                || ucnUseful(%d)'
        '.areaKind != %d' % (i, ak),
        '                || ucnUseful(%d)'
        '.areaVal != %d) ++bad;'
        % (i, av))

AUD += NL + E(
    '        // ---- the hole family ----',
    '        if (!ucnCastTimesAreHoles())',
    '            ++bad;',
    '        // ---- the mechanics ----',
    '        if (ucnTempDeltaF() != 40)',
    '            ++bad;',
    '        if (ucnFreshenDmgMax() != 4',
    '                || ucnSaltDmgMax()'
    ' != ucnFreshenDmgMax()) ++bad;',
    '        if (ucnSaltObjectSqYds() != 4',
    '                || ucnSaltGallons()'
    ' != 30) ++bad;',
    '        if (ucnTieRangeFt() != 1)',
    '            ++bad;',
    '        if (ucnShineMaxCubicYds() != 1',
    '                || ucnShineRevalueDieMod()'
    ' != -1',
    '                || !ucnShineRevalue'
    'OnceOnly()) ++bad;',
    '        if (ucnColorRenewDays() != 30)',
    '            ++bad;',
    '        if (ucnPolishFloorSqFt()'
    ' != 1000)',
    '            ++bad;',
    '        printf("R412 UA useful cantrips'
    ' pin audit: bad %d'
    + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R412 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '      - six categories: useful (20',
    '      named: chill, clean, color,',
    '      dampen, dry, dust, exterminate,',
    '      flavor, freshen, gather, polish,',
    '      salt, shine, spice, sprout,',
    '      stitch, sweeten, tie, warm, wrap;'),
    E(
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
    '        descriptions stay open.',
    '      - six categories: useful (20',
    '      named: chill, clean, color,',
    '      dampen, dry, dust, exterminate,',
    '      flavor, freshen, gather, polish,',
    '      salt, shine, spice, sprout,',
    '      stitch, sweeten, tie, warm, wrap;'),
    'gap: the MU cantrips box takes'
    ' R412')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 339:
    die('the census %d' % s.count('audit: bad'))
if s.count('R412 UA useful cantrips'
           ' pin audit') != 1:
    die('the R412 audit label')
if s.count('ucnUseful') < 80:
    die('the ucnUseful call count %d'
        % s.count('ucnUseful'))

# the R412b resolution guard:
# every ucn symbol the audit
# calls must be defined in the
# emitted header.
_used = set(_re.findall(r'\bucn\w+', s))
_def = set(_re.findall(r'\bucn\w+',
                       rd(UC)))
if _used - _def:
    die('undefined ucn calls %s'
        % sorted(_used - _def))

p = rd(UC)
if p.count("inline") != 16:
    die('the useful cantrips inline'
        ' count %d' % p.count('inline'))
if not p.endswith(NL):
    die('the useful cantrips trailing'
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
if g.count('AMENDED R412') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R412'))

for path, mark in (
        (UC, 'ucnPolishFloorSqFt'),
        (RT, 'ucnUsefulCount'),
        (SD, 'R411 landed')):
    if mark not in rd(path):
        die('%s carries no R412 round' % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bucn', rd(path)):
        die('%s calls the pins early'
            % path)

print('R412b splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the repair round - the')
print('  seven bare comment lines in')
print('  rules/uacantrips1.h take')
print('  their // prefix back (the')
print('  first body broke the C++')
print('  parse; the R392 class); a')
print('  tree that ran the broken')
print('  body reads applied 1,')
print('  already 5; a fresh clone')
print('  reads applied 5, already 1;')
print('  census 339 holds, the audit')
print('  label stays R412')
print('commit: R412b: the useful'
      ' cantrips header repair'
      ' (census 339)')

