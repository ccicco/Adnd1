#!/usr/bin/env python3
# r427_splice: the SECOND WSG
# pin round, census 352 -> 353.
# The environment data slice
# (the WSG printed pp. 21-22):
# Table 4 (the 13 temperature
# bands) and Table 5 (the 6
# wind bands) with the
# how-to-use prose and the
# precipitation rules pin as
# rules/wsgenvfx.h.
#
# The pins (the WSG printed
# p. 21-22, verified from the
# scan - archive.org item
# pdfy-B3Fz83tZ3TV7zOc8; the
# Table 4/5 grids read from
# the IIIF page image (the
# text layer mangles the
# fractions and drops the
# 120-or-higher row); the
# prose verified whole
# against the text layer):
#   - Table 4 (13 bands,
#     -40 or lower up to 120
#     or higher; the Str/Dex/
#     Con columns read
#     nonstrenuous/strenuous;
#     the Land Move fraction;
#     the Attack Rolls
#     penalty; 99 = no
#     effect).
#   - the Table 4 rules: the
#     strenuous side applies
#     also within 2 turns of
#     strenuous activity; the
#     exceptional-strength
#     caps 18 (nonstrenuous)
#     and 17 (strenuous); the
#     cavalier/paladin
#     percentile Dex/Con
#     disregarded; fractional
#     movement rounds up
#     (half of 9 is 5); the
#     attack penalty is
#     cumulative with the
#     strength-reduction
#     penalties; damage never
#     drops below 1; the table
#     assumes appropriate
#     attire.
#   - Table 5 (6 bands, 0-10
#     up to 80+; the missile
#     point-blank/short/
#     medium/long adjustments,
#     99 = xx = impossible; the
#     melee penalty; the
#     move-against-wind
#     fraction).
#   - the Table 5 rules: the
#     velocity is the maximum,
#     not a constant; the
#     missile direction makes
#     no difference; the melee
#     penalty is cumulative
#     with the Table 4 attack
#     penalty; moving
#     perpendicular uses the
#     next lower line; the
#     combined reduction is
#     the greater of the two.
#   - the precipitation
#     rules: moderate = one
#     line higher, heavy = two
#     lines, never worse than
#     the bottom (80+) line.
#
# 9 patches: the seed takes
# the R426 record; the gap
# report flips 4 boxes + the
# post-state line; the
# include; the audit. The
# verify pass carries the
# no-split-identifier gate
# (the R426 lesson).

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
        'R427 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d'
            ' (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


def newfile(path, text, label):
    if os.path.exists(path):
        if rd(path) == text:
            already.append(label)
        else:
            die('%s exists, divergent'
                % label)
    else:
        wr(path, text)
        applied.append(label)


RT = 'regtest.cpp'
HD = 'rules/wsgenvfx.h'
GR = 'tools/wsg_gap_report.md'
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

# ======== the pinned data ========

# Table 4: the 13 temperature
# bands, (str_ns, str_s,
# dex_ns, dex_s, con_ns,
# con_s, lm_num, lm_den,
# atk). The slash columns
# read nonstrenuous/strenuous;
# 99 = no effect. The Land
# Move fraction pins as
# num/den (99 = none).
T4 = [
    (-1, -2, -4, -5, -1, -2,
     1, 2, -4),    # -40 or lower
    (-1, -2, -3, -4, -1, -2,
     1, 2, -3),    # -39 to -30
    (0, -1, -2, -3, 0, -1,
     2, 3, -2),    # -29 to -20
    (0, -1, -1, -2, 0, -1,
     2, 3, -1),    # -19 to -10
    (99, 99, -1, -2, 99, 99,
     3, 4, -1),    # -9 to 0
    (99, 99, 0, -1, 99, 99,
     3, 4, 99),    # 1 to 10
    (99, 99, 0, -1, 99, 99,
     99, 99, 99),  # 11 to 20
    (99, 99, 99, 99, 99, 99,
     99, 99, 99),  # 21 to 79
    (99, 99, 99, 99, 0, -1,
     3, 4, 99),    # 80 to 89
    (0, -1, 99, 99, -1, -2,
     3, 4, -1),    # 90 to 99
    (-1, -2, 0, -1, -2, -3,
     2, 3, -2),    # 100 to 109
    (-1, -3, -1, -2, -3, -4,
     1, 2, -3),    # 110 to 119
    (-2, -4, -1, -3, -4, -5,
     1, 2, -4),    # 120 or higher
]

# Table 5: the 6 wind bands,
# (pb, short, medium, long,
# melee, mv_num, mv_den).
# 99 = xx (impossible) in the
# missile columns, no
# reduction in the move
# columns.
T5 = [
    (0, 0, 0, 0, 0, 99, 99),
    # 0 to 10
    (0, -1, -2, -3, 0, 99, 99),
    # 11 to 20
    (-1, -2, -3, 99, -1, 3, 4),
    # 21 to 30
    (-2, -4, 99, 99, -2, 2, 3),
    # 31 to 45
    (-4, -6, 99, 99, -4, 1, 2),
    # 46 to 79
    (99, 99, 99, 99, -8, 1, 4),
    # 80+
]

# the roster and census
# pre-checks (the censuses
# derive from the tables, the
# R410 lesson)
if len(T4) != 13 or len(T5) != 6:
    die('the roster sizes')
# the 99 censuses per Table 4
# column
N99 = [5, 5, 3, 3, 4, 4, 2, 2, 4]
for c in range(9):
    n = sum(1 for r in T4
            if r[c] == 99)
    if n != N99[c]:
        die('the Table 4 99 '
            'census, col %d' % c)
# the Land Move fraction is
# always num / (num + 1)
for r in T4:
    if r[6] == 99:
        if r[7] != 99:
            die('the LM pair')
    elif r[7] != r[6] + 1:
        die('the LM pair')
# the xx census
XX = sum(1 for r in T5
         for v in r[:4] if v == 99)
if XX != 9:
    die('the xx census %d' % XX)
# the book own examples: the
# 105-degree strength example
# (-1 nonstrenuous, -2
# strenuous), the -30 land
# move example (12 -> 6), the
# 35-mph example (melee -2,
# 12 -> 8 against, 9
# perpendicular), the 85/40
# greater-reduction example
# (2/3)
if (T4[10][0] != -1
        or T4[10][1] != -2
        or T4[1][6] != 1
        or T5[3][4] != -2
        or T5[3][5] * 4 != 8
        or T5[2][5] * 3 != 9
        or T4[8][6] * T5[3][6]
        <= T5[3][5] * T4[8][7]):
    die('the book examples')

# the prefix collision gate
# (the R411 lesson): the wse
# prefix must be free - keyed
# on the wse CALL absence so a
# re-run over a patched tree
# stays GREEN (idempotency)
RT0 = rd(RT)
if ('wseTempBandFor' not in RT0
        and _re.search(r'\bwse\w*\(',
                       RT0)):
    die('the wse prefix is not '
        'free in regtest')
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bwse\w', rd(path)):
        die('the wse prefix is not '
            'free in %s' % path)

# ======== (a) the seed ========

SEED_ENTRY = E(
    '- R426 landed 2026-10-14:',
    '  commit 435aaac (census',
    '  352, preflight GREEN,',
    '  pushed f313aa1..435aaac),',
    '  the dressing-for-the-',
    '  weather chapter closes',
    '  WHOLE - the first WSG',
    '  pin round after the arc',
    '  opener.',
    '  rules/wsgdress.h (NEW, 54',
    '  inlines, prefix wsd): the',
    '  four clothing categories',
    '  (very cold below 0, cold',
    '  0-30, moderate 31-75, hot',
    '  76+; the encumbrance',
    '  equivalents - plate mail',
    '  bulky 450 gp, ring mail',
    '  fairly bulky 250 gp,',
    '  leather non-bulky 150 gp,',
    '  none - the outfit costs',
    '  15/7/3 gp and the 6-sp',
    '  robe, the layer',
    '  equivalences 2-cold /',
    '  4-moderate), Table 3 (the',
    '  15 attire rows x the 4',
    '  temperature columns,',
    '  CUMULATIVE - the text',
    '  layer DROPPED the Splint',
    '  Mail label and the whole',
    '  Leather Armor row, the',
    '  grid re-read from the',
    '  page image), the',
    '  protected/unprotected',
    '  rules (the five category',
    '  clauses + the metal-armor',
    '  clause above 80, studded',
    '  leather not metal), the',
    '  three exertion regimes',
    '  and the clothing-as-armor',
    '  option (AC 8/9, the',
    '  10-percent miscast).',
    '  tools/wsg_gap_report.md',
    '  flips 8: 12 closed, 174',
    '  open, 42 tables.',
    '  INCIDENT: the first build',
    '  was committed RED (local',
    '  101082c, never pushed;',
    '  the push was ^C-d on the',
    '  RED preflight) - the',
    '  audit block split C++',
    '  identifiers across lines',
    '  (57 sites) and the column',
    '  switches emitted the',
    '  parameter without its',
    '  type; the reset route',
    '  landed one clean commit.',
    '  NEW GATE (the R426',
    '  lesson): the',
    '  no-split-identifier gate',
    '  in every splice verify',
    '  pass. The landed Termux',
    '  md5 diverged from the',
    '  published value by'
    '  exactly one trailing',
    '  newline - benign, the',
    '  md5 stays advisory.',
    '  Census 351 -> 352.')

ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R426 landed 2026-10-14' in s:
    already.append('seed: the R426 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                 + ANCH)
    wr(SD, s)
    applied.append('seed: the R426 record')

# ======== (b) rules/wsgenvfx.h ========

# the header: 38 inlines, the
# Table 4/5 switches + the
# band-for dispatches + the
# prose pins. The opener is
# the 92-char banner - the one
# allowed exception to the
# 78-col bound.

HS = []  # header source lines


def sw_int(name, vals, comment):
    out = [comment,
           'inline int %s(int b)'
           % name,
           '    {',
           '        switch (b) {']
    for i, v in enumerate(vals):
        out.append('        case %d:'
                   % i)
        out.append('            return '
                   '%d;' % v)
    out += ['        default:',
            '            return 0;',
            '        }',
            '    }',
            '']
    return out


HS += [
    '// ' + '=' * 89,
    '// Adnd1 - rules/wsgenvfx.h',
    '// The WSG ENVIRONMENT',
    '// EFFECTS, R427: the data',
    '// slice of the',
    '// effects-of-the-',
    '// environment chapter -',
    '// Table 4 (the 13',
    '// temperature bands: the',
    '// Str/Dex/Con reductions',
    '// nonstrenuous and',
    '// strenuous, the Land Move',
    '// fraction, the Attack',
    '// Rolls penalty) and',
    '// Table 5 (the 6 wind',
    '// bands: the missile',
    '// adjustments at point',
    '// blank/short/medium/long,',
    '// the melee penalty, the',
    '// move-against-wind',
    '// fraction) with the',
    '// how-to-use prose and the',
    '// precipitation rules;',
    '// census 352 -> 353.',
    '//',
    '// Provenance: the WSG',
    '// scan (archive.org item',
    '// pdfy-B3Fz83tZ3TV7zOc8),',
    '// printed pp. 21-22; the',
    '// grids read from the IIIF',
    '// page image (the text',
    '// layer mangles the',
    '// fractions and drops the',
    '// 120-or-higher row); the',
    '// prose verified whole',
    '// against the text layer.',
    '//',
    '// Sentinel: 99 = no effect',
    '// (a dash cell) and xx =',
    '// impossible (the missile',
    '// columns); the Land Move',
    '// fraction pins as',
    '// num/den, 99 = none.',
    'namespace rules {',
    '',
    '// ---- Table 4: the 13 ----',
    '// ---- temperature bands ----',
    '',
    '// The census: 13 bands,',
    '// -40 or lower up to 120',
    '// or higher.',
    'inline int '
    'wseTempBandCount()',
    '    { return 13; }',
]

HS += sw_int(
    'wseTempStrNonstren',
    [r[0] for r in T4],
    '// The Strength reduction,'
    '\n// nonstrenuous (the left'
    '\n// of the slash).'.replace(
        '\\n', NL))
HS += sw_int(
    'wseTempStrStren',
    [r[1] for r in T4],
    '// The Strength reduction,'
    '\n// strenuous (the right'
    '\n// of the slash).'.replace(
        '\\n', NL))
HS += sw_int(
    'wseTempDexNonstren',
    [r[2] for r in T4],
    '// The Dexterity reduction,'
    '\n// nonstrenuous.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseTempDexStren',
    [r[3] for r in T4],
    '// The Dexterity reduction,'
    '\n// strenuous.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseTempConNonstren',
    [r[4] for r in T4],
    '// The Constitution'
    '\n// reduction,'
    '\n// nonstrenuous.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseTempConStren',
    [r[5] for r in T4],
    '// The Constitution'
    '\n// reduction,'
    '\n// strenuous.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseTempLandMoveNum',
    [r[6] for r in T4],
    '// The Land Move fraction,'
    '\n// numerator; 99 = no'
    '\n// reduction.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseTempLandMoveDen',
    [r[7] for r in T4],
    '// The Land Move fraction,'
    '\n// denominator; 99 = no'
    '\n// reduction.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseTempAttack',
    [r[8] for r in T4],
    '// The Attack Rolls penalty'
    '\n// on to-hit and damage;'
    '\n// 99 = no effect.'.replace(
        '\\n', NL))

HS += [
    '// The band for a personal',
    '// temperature: 0 = -40 or',
    '// lower ... 12 = 120 or',
    '// higher; 7 = the',
    '// tolerable 21-79 range.',
    'inline int '
    'wseTempBandFor(int t)',
    '    {',
    '        if (t <= -40)'
    ' return 0;',
    '        if (t <= -30)'
    ' return 1;',
    '        if (t <= -20)'
    ' return 2;',
    '        if (t <= -10)'
    ' return 3;',
    '        if (t <= 0)'
    ' return 4;',
    '        if (t <= 10)'
    ' return 5;',
    '        if (t <= 20)'
    ' return 6;',
    '        if (t <= 79)'
    ' return 7;',
    '        if (t <= 89)'
    ' return 8;',
    '        if (t <= 99)'
    ' return 9;',
    '        if (t <= 109)'
    ' return 10;',
    '        if (t <= 119)'
    ' return 11;',
    '        return 12;',
    '    }',
    '',
    '// ---- the Table 4 rules ----',
    '',
    '// The strenuous side of a',
    '// slash applies also when',
    '// strenuous activity was',
    '// performed within this',
    '// many turns.',
    'inline int '
    'wseStrenuousWindowTurns()',
    '    { return 2; }',
    '// An exceptional Strength',
    '// score reduces to 18 for',
    '// a nonstrenuous check.',
    'inline int '
    'wseExStrCapNonstren()',
    '    { return 18; }',
    '// ... and to 17 for a',
    '// strenuous one.',
    'inline int '
    'wseExStrCapStren()',
    '    { return 17; }',
    '// The cavalier and paladin',
    '// percentile Dex/Con scores',
    '// are disregarded - only',
    '// the whole number counts.',
    'inline bool '
    'wsePercentileDisregarded()',
    '    { return true; }',
    '// Fractional movement',
    '// results round up: half',
    '// of 9 is 5.',
    'inline bool '
    'wseFractionRoundUp()',
    '    { return true; }',
    '// The Attack Rolls penalty',
    '// is cumulative with any',
    '// penalties from the',
    '// Strength reduction.',
    'inline bool '
    'wseAttackCumulative()',
    '    { return true; }',
    '// A damage roll can never',
    '// be reduced below this',
    '// by these penalties.',
    'inline int wseDamageFloor()',
    '    { return 1; }',
    '// The table entries assume',
    '// the character is',
    '// appropriately attired.',
    'inline bool wseAssumesAttire()',
    '    { return true; }',
    '',
    '// ---- Table 5: the 6 ----',
    '// ---- wind bands ----',
    '',
    '// The census: 6 bands, 0-10',
    '// up to 80+.',
    'inline int '
    'wseWindBandCount()',
    '    { return 6; }',
]

HS += sw_int(
    'wseWindMissilePb',
    [r[0] for r in T5],
    '// The missile adjustment,'
    '\n// point blank; 99 = xx ='
    '\n// impossible.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseWindMissileShort',
    [r[1] for r in T5],
    '// The missile adjustment,'
    '\n// short range.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseWindMissileMed',
    [r[2] for r in T5],
    '// The missile adjustment,'
    '\n// medium range.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseWindMissileLong',
    [r[3] for r in T5],
    '// The missile adjustment,'
    '\n// long range.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseWindMelee',
    [r[4] for r in T5],
    '// The melee combat penalty'
    '\n// on to-hit and'
    '\n// damage.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseWindMoveNum',
    [r[5] for r in T5],
    '// The move-against-wind'
    '\n// fraction, numerator;'
    '\n// 99 = no reduction.'.replace(
        '\\n', NL))
HS += sw_int(
    'wseWindMoveDen',
    [r[6] for r in T5],
    '// The move-against-wind'
    '\n// fraction,'
    '\n// denominator.'.replace(
        '\\n', NL))

HS += [
    '// The band for a wind',
    '// velocity in miles per',
    '// hour: 0 = 0-10 ... 5 =',
    '// 80+.',
    'inline int '
    'wseWindBandFor(int m)',
    '    {',
    '        if (m <= 10)'
    ' return 0;',
    '        if (m <= 20)'
    ' return 1;',
    '        if (m <= 30)'
    ' return 2;',
    '        if (m <= 45)'
    ' return 3;',
    '        if (m <= 79)'
    ' return 4;',
    '        return 5;',
    '    }',
    '',
    '// ---- the Table 5 rules ----',
    '',
    '// The wind velocity is the',
    '// maximum the wind can',
    '// reach, not a constant.',
    'inline bool '
    'wseWindIsMaximum()',
    '    { return true; }',
    '// The direction a missile',
    '// is fired in makes no',
    '// difference.',
    'inline bool '
    'wseMissileDirNoDiff()',
    '    { return true; }',
    '// xx = impossible: under',
    '// normal circumstances the',
    '// target cannot be hit.',
    'inline bool '
    'wseXxIsImpossible()',
    '    { return true; }',
    '// The melee penalty is',
    '// cumulative with the',
    '// Table 4 attack penalty.',
    'inline bool '
    'wseMeleeCumulative()',
    '    { return true; }',
    '// Moving perpendicular to',
    '// the wind uses the next',
    '// lower velocity line.',
    'inline bool '
    'wsePerpNextLower()',
    '    { return true; }',
    '// When both tables reduce',
    '// movement, use the',
    '// greater reduction.',
    'inline bool '
    'wseGreaterOfReductions()',
    '    { return true; }',
    '',
    '// ---- the precipitation ----',
    '// ---- rules ----',
    '',
    '// Moderate precipitation:',
    '// use the next higher wind',
    '// line (0-10 behaves as',
    '// 11-20).',
    'inline int '
    'wsePrecipModerateShift()',
    '    { return 1; }',
    '// Heavy precipitation: two',
    '// lines down (11-20 behaves',
    '// as 31-45).',
    'inline int '
    'wsePrecipHeavyShift()',
    '    { return 2; }',
    '// Conditions can never',
    '// become worse than the',
    '// bottom (80+) line.',
    'inline bool '
    'wsePrecipCapAtBottom()',
    '    { return true; }',
    '',
    '// ---- the ledger ----',
    '',
    '// The census of the xx',
    '// cells in the Table 5',
    '// missile columns.',
    'inline int wseXxCensus()',
    '    { return 9; }',
    '',
    '}   // namespace rules',
]

HEADER = E(*HS) + NL

newfile(HD, HEADER,
        'rules/wsgenvfx.h')

# the header statics:
# 38 inlines, lines <= 78
# except the 92-char opener,
# brace balance, every line
# classifiable C++ (the
# INCIDENT-2 lesson), the
# no-split-identifier gate
# (the R426 lesson)
h = rd(HD)
if h.count('inline ') != 38:
    die('the header inline '
        'count %d'
        % h.count('inline '))
lines = h.split(NL)
for i, ln in enumerate(lines):
    if i == 0:
        if len(ln) != 92:
            die('the header opener '
                'is %d cols'
                % len(ln))
        continue
    if len(ln) > 78:
        die('the header line %d '
            'is %d cols'
            % (i, len(ln)))
if h.count('{') != h.count('}'):
    die('the header brace '
        'balance')
_CODE = _re.compile(
    r'(^(inline |namespace |//)'
    r'|^\} +//'
    r'|^ +(case |default:|return '
    r'|switch |int |bool |if |'
    r'\{|\}))')
for i, ln in enumerate(lines):
    c = ln.strip()
    if not c or c.startswith('//'):
        continue
    if not _CODE.match(ln):
        die('the header line %d is '
            'not classifiable C++ '
            '(%r)'
            % (i, ln[:40]))

# ======== (c) the gap report
# ======== flips (5) ========

FL = [
    ('  - [ ] Temperature and '
     'wind (p. 21)',
     '  - [x] Temperature and '
     'wind (p. 21) - R427: '
     'Tables 4 and 5 with the '
     'how-to-use rules pin as '
     'rules/wsgenvfx.h'),
    ('  - [ ] Precipitation '
     '(p. 22)',
     '  - [x] Precipitation '
     '(p. 22) - R427: the '
     'moderate/heavy wind-line '
     'shifts pin as '
     'rules/wsgenvfx.h'),
    ('- [ ] **Table 4: '
     'temperature effects** '
     '(p. 21)',
     '- [x] **Table 4: '
     'temperature effects** '
     '(p. 21) - R427: the 13 '
     'bands pin as '
     'rules/wsgenvfx.h'),
    ('- [ ] **Table 5: '
     'wind velocity effects** '
     '(p. 21)',
     '- [x] **Table 5: '
     'wind velocity effects** '
     '(p. 21) - R427: the 6 '
     'bands pin as '
     'rules/wsgenvfx.h'),
    ('Post-state at R426: 12 '
     'closed, 174 open (the '
     'R426 round closes the '
     'dressing-for-the-weather '
     'chapter whole - the '
     'personal temperature '
     'system, the four '
     'clothing categories, '
     'Table 3, the '
     'protected/unprotected '
     'rules, the exertion '
     'regimes and the '
     'clothing-as-armor option '
     '- seven boxes; the next '
     'rounds work top-down - '
     'data tables first).',
     'Post-state at R427: 16 '
     'closed, 170 open (the '
     'R427 round closes the '
     'environment data slice - '
     'Table 4 (the 13 '
     'temperature bands), '
     'Table 5 (the 6 wind '
     'bands), the how-to-use '
     'rules and the '
     'precipitation shifts - '
     'four boxes; the special '
     'weather, the heat/cold '
     'damage and the equipment '
     'effects stay open).'),
]
for old, new in FL:
    pair(GR, old, new,
         'gap: the %s box'
         % old[:34].rstrip())

# the gap censuses on the
# patched file: every [x]
# box counted, the opens by
# lstrip, the manifest whole
g = rd(GR)
if g.count('- [x]') != 16:
    die('the gap closed count %d'
        % g.count('- [x]'))
opens = [l for l in g.split(NL)
         if l.lstrip()
         .startswith('- [ ]')]
if len(opens) != 170:
    die('the gap open count %d'
        % len(opens))
if g.count('**Table ') != 42:
    die('the gap table manifest %d'
        % g.count('**Table '))

# ======== (d) regtest.cpp -
# ======== the include ========

pair(RT,
     '#include "rules/wsgdress.h"  '
     '// R426: the WSG dressing '
     'for the weather',
     '#include "rules/wsgdress.h"  '
     '// R426: the WSG dressing '
     'for the weather' + NL
     + '#include "rules/wsgenvfx.h"  '
     '// R427: the WSG '
     'environment effects',
     'regtest: the include line')

# ======== (e) regtest.cpp -
# ======== the R427 audit ========

AUD = E(*[l.rstrip() for l in [
    '    // ---- R427: the WSG',
    '    // environment pin audit ----',
    '    // The environment data',
    '    // slice pins Tables 4 and',
    '    // 5 (rules/wsgenvfx.h,',
    '    // prefix wse): Table 4 (the',
    '    // 13 temperature bands, the',
    '    // Str/Dex/Con reductions',
    '    // nonstrenuous/strenuous,',
    '    // the Land Move fractions,',
    '    // the Attack Rolls penalty)',
    '    // and Table 5 (the 6 wind',
    '    // bands, the missile',
    '    // adjustments with the xx',
    '    // impossible cells, the',
    '    // melee penalty, the',
    '    // move-against-wind',
    '    // fractions) verified cell',
    '    // for cell with the 99',
    '    // censuses, the book own',
    '    // examples (the 105-degree',
    '    // strength, the -30 move,',
    '    // the 35-mph wind, the',
    '    // 85/40 greater',
    '    // reduction) and the',
    '    // precipitation shifts;',
    '    // census 352 -> 353.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        if (wseTempBandCount() != 13',
    '                || wseWindBandCount()',
    '                != 6',
    '                || wseStrenuousWindow'
    'Turns() != 2',
    '                || wseExStrCap'
    'Nonstren() != 18',
    '                || wseExStrCapStren()',
    '                != 17',
    '                || !wsePercentile'
    'Disregarded()',
    '                || !wseFraction'
    'RoundUp()',
    '                || !wseAttack'
    'Cumulative()',
    '                || wseDamageFloor() != 1',
    '                || !wseAssumesAttire()',
    '                || !wseWindIsMaximum()',
    '                || !wseMissileDir'
    'NoDiff()',
    '                || !wseXxIsImpossible()',
    '                || !wseMeleeCumulative()',
    '                || !wsePerpNextLower()',
    '                || !wseGreaterOf'
    'Reductions()',
    '                || wsePrecipModerate'
    'Shift() != 1',
    '                || wsePrecipHeavy'
    'Shift() != 2',
    '                || !wsePrecipCapAt'
    'Bottom()',
    '                || wseXxCensus() != 9)',
    '            ++bad;',
    '        int C4[13][9] = {',
    '            {-1,-2,-4,-5,-1,-2,1,2,-4},',
    '            {-1,-2,-3,-4,-1,-2,1,2,-3},',
    '            {0,-1,-2,-3,0,-1,2,3,-2},',
    '            {0,-1,-1,-2,0,-1,2,3,-1},',
    '            {99,99,-1,-2,99,99,3,4,-1},',
    '            {99,99,0,-1,99,99,3,4,99},',
    '            {99,99,0,-1,99,99,99,99,99},',
    '            {99,99,99,99,99,99,99,99,99},',
    '            {99,99,99,99,0,-1,3,4,99},',
    '            {0,-1,99,99,-1,-2,3,4,-1},',
    '            {-1,-2,0,-1,-2,-3,2,3,-2},',
    '            {-1,-3,-1,-2,-3,-4,1,2,-3},',
    '            {-2,-4,-1,-3,-4,-5,1,2,-4}};',
    '        int n99[9] = '
    '{0,0,0,0,0,0,0,0,0};',
    '        int e99[9] = '
    '{5,5,3,3,4,4,2,2,4};',
    '        for (int b = 0;',
    '             b < wseTempBand'
    'Count();',
    '             ++b) {',
    '            for (int c = 0; c < 9;',
    '                 ++c) {',
    '                int v;',
    '                if (c == 0)',
    '                    v = wseTempStr'
    'Nonstren(b);',
    '                else if (c == 1)',
    '                    v = wseTempStr'
    'Stren(b);',
    '                else if (c == 2)',
    '                    v = wseTempDex'
    'Nonstren(b);',
    '                else if (c == 3)',
    '                    v = wseTempDex'
    'Stren(b);',
    '                else if (c == 4)',
    '                    v = wseTempCon'
    'Nonstren(b);',
    '                else if (c == 5)',
    '                    v = wseTempCon'
    'Stren(b);',
    '                else if (c == 6)',
    '                    v = wseTemp'
    'LandMoveNum(b);',
    '                else if (c == 7)',
    '                    v = wseTemp'
    'LandMoveDen(b);',
    '                else v = '
    'wseTempAttack(b);',
    '                if (v != C4[b][c])',
    '                    ++bad;',
    '                if (v == 99) ++n99[c];',
    '            }',
    '            if (wseTempLandMove'
    'Num(b) == 99',
    '                    != (wseTemp'
    'LandMoveDen(b) == 99)',
    '                || (wseTempLandMove'
    'Num(b) != 99',
    '                    && wseTemp'
    'LandMoveDen(b)',
    '                    != wseTemp'
    'LandMoveNum(b) + 1))',
    '                ++bad;',
    '        }',
    '        for (int c = 0; c < 9; ++c)',
    '            if (n99[c] != e99[c])',
    '                ++bad;',
    '        // the band-for',
    '        // boundaries',
    '        if (wseTempBandFor(-40) != 0',
    '                || wseTempBandFor(-41)',
    '                != 0',
    '                || wseTempBandFor(-39)',
    '                != 1',
    '                || wseTempBandFor(-30)',
    '                != 1',
    '                || wseTempBandFor(-29)',
    '                != 2',
    '                || wseTempBandFor(21)',
    '                != 7',
    '                || wseTempBandFor(79)',
    '                != 7',
    '                || wseTempBandFor(80)',
    '                != 8',
    '                || wseTempBandFor(100)',
    '                != 10',
    '                || wseTempBandFor(119)',
    '                != 11',
    '                || wseTempBandFor(120)',
    '                != 12',
    '                || wseTempBandFor(300)',
    '                != 12)',
    '            ++bad;',
    '        // the book own',
    '        // 105-degree strength',
    '        // example',
    '        if (wseTempBandFor(105) != 10',
    '                || wseTempStr'
    'Nonstren(10) != -1',
    '                || wseTempStrStren(10)',
    '                != -2)',
    '            ++bad;',
    '        // the -30 land move',
    '        // example: 12 -> 6',
    '        if (wseTempBandFor(-30) != 1',
    '                || wseTempLandMove'
    'Num(1) != 1',
    '                || wseTempLandMove'
    'Den(1) != 2',
    '                || (12 * wseTemp'
    'LandMoveNum(1))',
    '                    / wseTemp'
    'LandMoveDen(1) != 6',
    '                || (9 * wseTemp'
    'LandMoveNum(1) + 1)',
    '                    / wseTemp'
    'LandMoveDen(1) != 5)',
    '            ++bad;',
    '        int C5[6][7] = {',
    '            {0,0,0,0,0,99,99},',
    '            {0,-1,-2,-3,0,99,99},',
    '            {-1,-2,-3,99,-1,3,4},',
    '            {-2,-4,99,99,-2,2,3},',
    '            {-4,-6,99,99,-4,1,2},',
    '            {99,99,99,99,-8,1,4}};',
    '        int xx = 0;',
    '        for (int b = 0;',
    '             b < wseWindBand'
    'Count();',
    '             ++b) {',
    '            int vals[7];',
    '            vals[0] = wseWind'
    'MissilePb(b);',
    '            vals[1] = wseWind'
    'MissileShort(b);',
    '            vals[2] = wseWind'
    'MissileMed(b);',
    '            vals[3] = wseWind'
    'MissileLong(b);',
    '            vals[4] = wseWind'
    'Melee(b);',
    '            vals[5] = wseWind'
    'MoveNum(b);',
    '            vals[6] = wseWind'
    'MoveDen(b);',
    '            for (int c = 0; c < 7;',
    '                 ++c) {',
    '                if (vals[c]'
    '                    != C5[b][c])',
    '                    ++bad;',
    '                if (c < 4 && vals[c]',
    '                    == 99)',
    '                    ++xx;',
    '            }',
    '        }',
    '        if (xx != wseXxCensus())',
    '            ++bad;',
    '        // the wind band-for',
    '        // boundaries',
    '        if (wseWindBandFor(0) != 0',
    '                || wseWindBandFor(10)',
    '                != 0',
    '                || wseWindBandFor(11)',
    '                != 1',
    '                || wseWindBandFor(45)',
    '                != 3',
    '                || wseWindBandFor(46)',
    '                != 4',
    '                || wseWindBandFor(79)',
    '                != 4',
    '                || wseWindBandFor(80)',
    '                != 5',
    '                || wseWindBandFor(200)',
    '                != 5)',
    '            ++bad;',
    '        // the book own 35-mph',
    '        // example: melee -2,',
    '        // 12 -> 8 against the',
    '        // wind, 9 perpendicular',
    '        if (wseWindBandFor(35) != 3',
    '                || wseWindMelee(3)',
    '                != -2',
    '                || (12 * wseWind'
    'MoveNum(3))',
    '                    / wseWind'
    'MoveDen(3) != 8',
    '                || (12 * wseWind'
    'MoveNum(2))',
    '                    / wseWind'
    'MoveDen(2) != 9)',
    '            ++bad;',
    '        // the 85/40 example: the',
    '        // greater reduction is',
    '        // 2/3 (temperature 3/4',
    '        // vs wind 2/3)',
    '        if (wseTempBandFor(85) != 8',
    '                || wseWindBandFor(40)',
    '                != 3',
    '                || !(wseWind'
    'MoveNum(3) * wseTemp'
    'LandMoveDen(8)',
    '                    < wseTemp'
    'LandMoveNum(8) * wseWind'
    'MoveDen(3)))',
    '            ++bad;',
    '        // the precipitation',
    '        // examples: moderate',
    '        // rain with 0-10 wind',
    '        // behaves as 11-20;',
    '        // heavy snow with 11-20',
    '        // behaves as 31-45; the',
    '        // raw shift 5 + 2 = 7',
    '        // overshoots the',
    '        // bottom, so the',
    '        // wsePrecipCapAt',
    '        // Bottom pin caps it',
    '        if (wseWindBandFor(5)',
    '                + wsePrecipModerate'
    'Shift() != 1',
    '                || wseWind'
    'MissileShort(1) != -1',
    '                || wseWindBandFor(15)',
    '                + wsePrecipHeavy'
    'Shift() != 3',
    '                || wseWindMelee(3)',
    '                != -2',
    '                || wseWind'
    'BandFor(90) != 5',
    '                || (wseWind'
    'BandFor(90)',
    '                    + wsePrecip'
    'HeavyShift() != 7))',
    '            ++bad;',
    '        printf("R427 WSG '
    'environment pin '
    'audit: bad %d' + chr(92)
    + 'n", bad);',
    '        if (bad) return 1;',
    '    }']])

R227 = ('    // ---- R227: the wis '
        'mental save wiring '
        'audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R427 audit block')

# ======== the verify pass ========

if applied and already:
    die('the mixed applied/already '
        'state (the R420 lesson)')

s = rd(RT)
if s.count('audit: bad') != 353:
    die('the census %d'
        % s.count('audit: bad'))
if s.count('R427 WSG environment '
           'pin audit') != 1:
    die('the R427 audit label')

# the no-split-identifier gate
# (the R426 lesson): a C++
# identifier must never be
# split across two lines - a
# line ending in an identifier
# character followed by a line
# starting with one is two
# juxtaposed tokens and never
# compiles. Applies to the
# audit block and the header,
# code lines only.
_idc = ('_' 'abcdefghijklmnopqrstuvwxyz'
        'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        '0123456789')
for blk, name in ((AUD, 'the R427 audit'),
                  (h, 'the header')):
    prev = ''
    for ln in blk.split(NL):
        c = ln.strip()
        pt = prev.rstrip()
        if (c and not c.startswith('//')
                and pt
                and not pt.lstrip()
                .startswith('//')
                and pt[-1] in _idc
                and c[0] in _idc):
            die('a split identifier in '
                + name + ' (%r|%r)'
                % (pt[-20:], c[:20]))
        prev = ln

# the string-literal parity
# gate (the R421b lesson): no
# CODE line in the R427 audit
# block may carry an
# unterminated string literal
for ln in AUD.split(NL):
    c = ln.lstrip()
    if (c and not c.startswith('//')
            and ln.count(chr(34)) % 2):
        die('the R427 audit block '
            'has an unterminated '
            'string literal')

# the no-bare-|| gate (the
# R418b lesson): no wse chain
# may BEGIN with '||' - a
# '||' line is legal only
# inside an open chain
prev = ''
for ln in s.split(NL):
    if ('wse' in ln
            and ln != prev
            and _re.match(r'^ +\|\| ', ln)
            and (prev.rstrip().endswith(';')
                 or not prev.strip()
                 or prev.lstrip()
                 .startswith('//'))):
        die('a bare || wse line')
    prev = ln

# the wse identifier
# resolution (the R412b
# lesson): every wse symbol
# the audit calls must be
# defined in the header
called = set(_re.findall(
    r'\b(wse\w+)\s*\(', AUD))
defined = set(_re.findall(
    r'\b(wse\w+)\s*\(', h))
for sym in sorted(called):
    if sym not in defined:
        die('the audit calls %s, '
            'undefined in the '
            'header' % sym)

# the include comment whole
# (the R390 lesson)
if s.count('#include "rules/'
          'wsgenvfx.h"  // R427: '
          'the WSG environment '
          'effects') != 1:
    die('the wsgenvfx include line')

# the gap report on disk
g = rd(GR)
if g.count('- [x]') != 16:
    die('the gap closed count %d'
        % g.count('- [x]'))
opens = [l for l in g.split(NL)
         if l.lstrip()
         .startswith('- [ ]')]
if len(opens) != 170:
    die('the gap open count %d'
        % len(opens))
if g.count('**Table ') != 42:
    die('the gap table manifest')

# the seed record
if ('R426 landed 2026-10-14'
        not in rd(SD)):
    die('the seed R426 record')

# the caller contract: no
# engine caller touches the
# wse pins
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bwse\w', rd(path)):
        die('%s calls the wse pins '
            'early' % path)

print('R427 splice: ALL OK '
      '(applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the environment data '
      'slice - Table 4 (the 13')
print('  temperature bands) and '
      'Table 5 (the 6 wind bands)')
print('  pin as rules/wsgenvfx.h '
      '(38 inlines, prefix wse)')
print('  with the how-to-use rules '
      'and the precipitation')
print('  shifts; the '
      'wsg_gap_report.md flips to '
      '16 closed,')
print('  170 open, 42 tables; '
      'census 352 -> 353')
print('commit: R427: the WSG '
      'environment effects - the '
      'temperature and wind '
      'tables (census 353)')

