#!/usr/bin/env python3
# r426_splice: the FIRST WSG
# pin round after the arc
# opener, census 351 -> 352.
# The dressing-for-the-
# weather chapter closes
# WHOLE (the WSG printed
# pp. 18-20): the personal
# temperature system, the
# four clothing categories,
# Table 3, the
# protected/unprotected
# rules, the exertion
# regimes and the
# clothing-as-armor option
# pin as rules/wsgdress.h.
#
# The pins (the WSG printed
# pp. 18-20, verified from
# the scan - archive.org
# item pdfy-B3Fz83tZ3TV7zOc8,
# IIIF page = the printed
# page; the Table 3 grid,
# the row set and the
# clothing costs read from
# the IIIF page images
# because the text layer
# drops grid rows and
# mangles the figures; the
# rule prose verified whole
# against the text layer):
#   - the clothing
#     categories (very cold:
#     below 0, encumbers as
#     plate mail bulky 450
#     gp, outfit about
#     15 gp; cold: 0 to 30,
#     ring mail fairly bulky
#     250 gp, about 7 gp;
#     moderate: 31 to 75,
#     none or leather armor
#     non-bulky 150 gp, no
#     more than 3 gp; hot:
#     above 75, no
#     encumbrance, a robe at
#     6 sp). Very cold
#     equals two layers of
#     cold clothing or four
#     layers of moderate.
#   - Table 3 (the 15
#     attire rows x the 4
#     temperature columns -
#     the text layer DROPPED
#     the Splint Mail label
#     and the whole Leather
#     Armor row and garbled
#     the Plate Mail row;
#     the grid re-read from
#     the page image, row
#     set, column reads and
#     the book own examples
#     all agree; entries are
#     CUMULATIVE).
#   - the protected rules
#     (unprotected: very
#     cold clothing above 30
#     effective; cold below
#     0 or above 50; moderate
#     below 30 or above 80;
#     hot below 50; any metal
#     armor - not studded
#     leather - above 80,
#     regardless of
#     clothing).
#   - the exertion regimes
#     (below 0: a protected
#     character +5 per 4
#     consecutive turns, one
#     rest turn holds it,
#     longer rest loses it,
#     max 20 on the 4-on/1-
#     off cycle; 0 to 30:
#     +5 after 6 turns, +10
#     after 12 - the maximum -
#     retained until resting
#     more than 2 turns in a
#     row; 80+: an
#     unprotected character
#     +5 per 3 turns, max 25;
#     resting drops 5 per 3
#     turns, resting AND
#     removing armor drops 10
#     per 3 turns, floored at
#     the non-exerting
#     level).
#   - clothing as armor
#     (very cold clothing may
#     impart armor class 8,
#     cold clothing 9; the
#     optional 10 percent
#     somatic miscast risk).
#
# 5 patches: the seed takes
# the R425 record; the
# gap report flips 8 (the 5
# chapter sub-items + the
# parent chapter box +
# Table 3 + the post-state
# line); the include; the
# audit. Mirrors the R425
# splice structure.

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
        'R426 splice ABORT: ' + msg)


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
HD = 'rules/wsgdress.h'
GR = 'tools/wsg_gap_report.md'
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

# ======== the pinned data ========

# The four clothing
# categories, the book order
# (very cold, cold, moderate,
# hot): (lo, hi, costGp).
# -99 = open low end, 99 =
# open high end.
CAT = [
    (-99, -1, 15),   # very cold
    (0, 30, 7),      # cold
    (31, 75, 3),     # moderate
    (76, 99, 0),     # hot
]

# Table 3: the 15 attire
# rows (the 4 clothing
# categories + the 11
# armor types), the 4
# effective-temperature
# columns (-1 or lower,
# 0 to 30, 31 to 75,
# 76 or higher).
T3 = [
    (30, 40, 50, 60),   # Very Cold
    (20, 30, 40, 50),   # Cold
    (10, 20, 20, 30),   # Moderate
    (0, 0, 0, 0),       # Hot
    (10, 20, 30, 40),   # Full Plate
    (10, 20, 30, 40),   # Field Plate
    (10, 20, 30, 30),   # Plate Mail
    (5, 10, 15, 20),    # Splint Mail
    (5, 10, 15, 20),    # Banded Mail
    (0, 5, 10, 20),     # Chain Mail
    (0, 5, 10, 20),     # Scale Mail
    (0, 5, 10, 15),     # Ring Mail
    (5, 0, 15, 30),   # Studded Leather
    (20, 30, 40, 50),   # Padded Armor
    (10, 5, 10, 20),    # Leather Armor
]

RS = [sum(r) for r in T3]
CS = [sum(r[k] for r in T3)
      for k in range(4)]
ZC = sum(1 for r in T3
         for v in r if v == 0)

# the roster and census
# pre-checks (the censuses
# derive from the tables, the
# R410 lesson)
if len(CAT) != 4 or len(T3) != 15:
    die('the roster sizes')
if RS != [180, 140, 80, 0, 100,
          100, 90, 50, 50, 35, 35,
          30, 50, 140, 45]:
    die('the Table 3 row sums')
if CS != [135, 220, 325, 445]:
    die('the Table 3 column sums')
if ZC != 8:
    die('the Table 3 zero count')
# the book own examples: the
# cumulative subzero example
# (plate mail + very cold
# clothing = +40) and the
# chain mail example (90
# degrees, +20 armor, a
# 15-turn hike at the +25
# maximum = 135 personal)
if T3[0][0] + T3[6][0] != 40:
    die('the cumulative example')
if T3[9][3] != 20 \
        or 90 + T3[9][3] + 25 != 135:
    die('the chain mail example')
# the category ranges and
# costs cross-check against
# the book prose
if (CAT[0][1] != -1
        or CAT[1][0] != 0
        or CAT[1][1] != 30
        or CAT[2][0] != 31
        or CAT[2][1] != 75
        or CAT[3][0] != 76
        or CAT[0][2] != 15
        or CAT[1][2] != 7
        or CAT[2][2] != 3
        or CAT[3][2] != 0):
    die('the category data')

# the prefix collision gate
# (the R411 lesson): the wsd
# prefix must be free - keyed
# on the wsd CALL absence so a
# re-run over a patched tree
# stays GREEN (idempotency)
RT0 = rd(RT)
if ('wsdUnprotected' not in RT0
        and _re.search(r'\bwsd\w*\(',
                       RT0)):
    die('the wsd prefix is not '
        'free in regtest')
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bwsd\w', rd(path)):
        die('the wsd prefix is not '
            'free in %s' % path)

# ======== (a) the seed ========

SEED_ENTRY = E(
    '- R425 landed 2026-10-14:',
    '  commit f313aa1 (census',
    '  351, preflight GREEN on',
    '  the FIRST run, pushed',
    '  8e710fb..f313aa1), the',
    '  WSG ARC OPENER - the',
    '  wilderness proficiencies.',
    '  rules/wsgprof.h (NEW, 33',
    '  inlines, prefix wsg): the',
    '  Proficiency Check system',
    '  (1d20 vs the Appropriate',
    '  Ability, the unmodified',
    '  19/20 auto-fail, the 18',
    '  cap, the 2-in-20 floor,',
    '  the -2 improving step',
    '  from 3rd level, an',
    '  improved 19 succeeds, a',
    '  natural 20 always fails),',
    '  the slot rules (a weapon',
    '  slot may hold a nonweapon',
    '  proficiency, never the',
    '  reverse), the expanding',
    '  optional rule (1st level',
    '  only, a delayed slot is',
    '  lost), the horseman',
    '  footnote, Table 1 (the 14',
    '  class rows, the bard "as',
    '  other classes" sentinel)',
    '  and Table 2 (the 25 rows)',
    '  as switches with the',
    '  censuses and the book own',
    '  denominator arithmetic.',
    '  tools/wsg_gap_report.md',
    '  (NEW): the lossless',
    '  whole-book inventory -',
    '  the 42-table manifest from',
    '  the book own Tables index,',
    '  the 14 chapters, the DM',
    '  section, the weather',
    '  appendix; 5 closed, 181',
    '  open, 42 tables. The',
    '  double-run 5/0 then 0/5;',
    '  the user Termux md5 was',
    '  not captured this round -',
    '  575a6199 stays advisory',
    '  (the compile, the double-',
    '  run and the GREEN',
    '  preflight prove the body).',
    '  Census 350 -> 351.')

ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R425 landed 2026-10-14' in s:
    already.append('seed: the R425 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                 + ANCH)
    wr(SD, s)
    applied.append('seed: the R425 record')

# ======== (b) rules/wsgdress.h ========

# the header: 54 inlines, the
# category pins + the Table 3
# switches + the protected
# rules + the exertion
# regimes + the armor option.
# The opener is the 92-char
# banner - the one allowed
# exception to the 78-col
# bound.

HS = []  # header source lines


def sw_int(name, param, vals,
           comment):
    out = [comment,
           'inline int %s(%s)'
           % (name, param),
           '    {',
           '        switch (%s) {'
           % param.split()[-1]]
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
    '// Adnd1 - rules/wsgdress.h',
    '// The WSG DRESSING FOR',
    '// THE WEATHER, R426: the',
    '// first WSG pin round',
    '// after the arc opener.',
    '// The personal',
    '// temperature system pins',
    '// whole: the four',
    '// clothing categories',
    '// (the temperature',
    '// ranges, the',
    '// encumbrance',
    '// equivalents, the outfit',
    '// costs), Table 3 (the',
    '// 15 attire rows x the 4',
    '// temperature columns,',
    '// cumulative), the',
    '// protected/unprotected',
    '// rules, the exertion',
    '// regimes and the',
    '// clothing-as-armor',
    '// option; census',
    '// 351 -> 352.',
    '//',
    '// Provenance: the WSG',
    '// scan (archive.org item',
    '// pdfy-B3Fz83tZ3TV7zOc8),',
    '// printed pp. 18-20; the',
    '// Table 3 grid, the row',
    '// set and the clothing',
    '// costs read from the',
    '// IIIF page images (the',
    '// text layer drops grid',
    '// rows and mangles the',
    '// figures); the rule',
    '// prose verified whole',
    '// against the text layer.',
    'namespace rules {',
    '',
    '// ---- the clothing',
    '// ---- categories ----',
    '',
    '// The census: 4',
    '// categories, the book',
    '// order (very cold, cold,',
    '// moderate, hot).',
    'inline int '
    'wsdClothingCount()',
    '    { return 4; }',
    '// The category range,',
    '// low end; -99 = the',
    '// range is open at the',
    '// low end (very cold',
    '// clothing suits',
    '// anything below 0).',
    'inline int '
    'wsdCategoryLo(int c)',
    '    {',
    '        switch (c) {',
    '        case 0:',
    '            return -99;',
    '        case 1:',
    '            return 0;',
    '        case 2:',
    '            return 31;',
    '        case 3:',
    '            return 76;',
    '        default:',
    '            return 0;',
    '        }',
    '    }',
    '// The category range,',
    '// high end; 99 = open',
    '// (hot clothing suits',
    '// anything above 75).',
    'inline int '
    'wsdCategoryHi(int c)',
    '    {',
    '        switch (c) {',
    '        case 0:',
    '            return -1;',
    '        case 1:',
    '            return 30;',
    '        case 2:',
    '            return 75;',
    '        case 3:',
    '            return 99;',
    '        default:',
    '            return 0;',
    '        }',
    '    }',
    '// The outfit cost, gold',
    '// pieces (the hot',
    '// category prices in',
    '// silver - below).',
    'inline int '
    'wsdCategoryCostGp(int c)',
    '    {',
    '        switch (c) {',
    '        case 0:',
    '            return 15;',
    '        case 1:',
    '            return 7;',
    '        case 2:',
    '            return 3;',
    '        case 3:',
    '            return 0;',
    '        default:',
    '            return 0;',
    '        }',
    '    }',
    '// The hot-clothing',
    '// outfit cost ceiling: a',
    '// robe at 6 sp.',
    'inline int '
    'wsdHotClothingCostSp()',
    '    { return 6; }',
    '',
    '// ---- the category',
    '// ---- encumbrance ----',
    '',
    '// Very cold clothing',
    '// encumbers as plate mail',
    '// (bulky).',
    'inline bool '
    'wsdVcEncEqPlateMail()',
    '    { return true; }',
    '// The plate mail',
    '// encumbrance weight, in',
    '// gp.',
    'inline int '
    'wsdVcEncWeightGp()',
    '    { return 450; }',
    '// Cold clothing encumbers',
    '// as ring mail (fairly',
    '// bulky).',
    'inline bool '
    'wsdColdEncEqRingMail()',
    '    { return true; }',
    'inline int '
    'wsdColdEncWeightGp()',
    '    { return 250; }',
    '// Moderate clothing has',
    '// no encumbrance value,',
    '// or counts as leather',
    '// armor (non-bulky) if',
    '// heavy.',
    'inline bool '
    'wsdModEncEqLeather()',
    '    { return true; }',
    'inline int '
    'wsdModEncWeightGp()',
    '    { return 150; }',
    '// Hot clothing has no',
    '// encumbrance value.',
    'inline bool '
    'wsdHotEncumbranceNone()',
    '    { return true; }',
    '// Very cold clothing',
    '// equals two layers of',
    '// cold clothing or four',
    '// layers of moderate.',
    'inline int '
    'wsdVcEqColdLayers()',
    '    { return 2; }',
    'inline int '
    'wsdVcEqModLayers()',
    '    { return 4; }',
    '',
    '// ---- the personal ----',
    '// ---- temperature ----',
    '',
    '// The temperatures are',
    '// degrees Fahrenheit.',
    'inline bool '
    'wsdDegreesAreFahrenheit()',
    '    { return true; }',
    '',
    '// ---- Table 3: the 15 ----',
    '// ---- attire rows ----',
    '',
    '// The census: 15 attire',
    '// rows (the 4 clothing',
    '// categories + the 11',
    '// armor types).',
    'inline int wsdAttireCount()',
    '    { return 15; }',
    '// The census: 4',
    '// effective-temperature',
    '// columns.',
    'inline int wsdColCount()',
    '    { return 4; }',
]

HS += sw_int(
    'wsdTempAdjBelow0', 'int a',
    [r[0] for r in T3],
    '// Column 0: the -1 or'
    '\n// lower band (the'
    '\n// value read per'
    '\n// attire row).'.replace(
        '\\n', NL))
HS += sw_int(
    'wsdTempAdjCold', 'int a',
    [r[1] for r in T3],
    '// Column 1: the 0 to 30'
    '\n// band.'.replace(
        '\\n', NL))
HS += sw_int(
    'wsdTempAdjModerate', 'int a',
    [r[2] for r in T3],
    '// Column 2: the 31 to 75'
    '\n// band.'.replace(
        '\\n', NL))
HS += sw_int(
    'wsdTempAdjHot', 'int a',
    [r[3] for r in T3],
    '// Column 3: the 76 or'
    '\n// higher band.'.replace(
        '\\n', NL))

HS += [
    '// The column for an',
    '// effective temperature:',
    '// -1 or lower, 0 to 30,',
    '// 31 to 75, 76 or higher.',
    'inline int '
    'wsdColForTemp(int t)',
    '    { return t < 0 ? 0 : '
    't < 31 ? 1 : t < 76 ? 2 : 3; }',
    '// The Table 3 entry by',
    '// attire and column -',
    '// the dispatch over the',
    '// four column accessors.',
    'inline int '
    'wsdTempAdj(int a, int col)',
    '    {',
    '        switch (col) {',
    '        case 0:',
    '            return '
    'wsdTempAdjBelow0(a);',
    '        case 1:',
    '            return '
    'wsdTempAdjCold(a);',
    '        case 2:',
    '            return '
    'wsdTempAdjModerate(a);',
    '        default:',
    '            return '
    'wsdTempAdjHot(a);',
    '        }',
    '    }',
    '// Table 3 entries are',
    '// cumulative, no matter',
    '// whether armor is worn',
    '// over clothing or vice',
    '// versa.',
    'inline bool '
    'wsdTempAdjCumulative()',
    '    { return true; }',
    '',
    '// ---- protected and ----',
    '// ---- unprotected ----',
    '',
    '// Very cold clothing',
    '// leaves a character',
    '// unprotected above 30',
    '// degrees effective.',
    'inline int '
    'wsdVcUnprotectedAbove()',
    '    { return 30; }',
    '// Cold clothing: below 0',
    '// or above 50.',
    'inline int '
    'wsdColdUnprotBelow()',
    '    { return 0; }',
    'inline int '
    'wsdColdUnprotAbove()',
    '    { return 50; }',
    '// Moderate clothing:',
    '// below 30 or above 80.',
    'inline int '
    'wsdModUnprotBelow()',
    '    { return 30; }',
    'inline int '
    'wsdModUnprotAbove()',
    '    { return 80; }',
    '// Hot clothing: below 50.',
    'inline int '
    'wsdHotUnprotBelow()',
    '    { return 50; }',
    '// Any metal armor (not',
    '// studded leather) works',
    '// above this effective',
    '// temperature, regardless',
    '// of clothing.',
    'inline int wsdMetalHighTemp()',
    '    { return 80; }',
    '// Studded leather is not',
    '// metal armor for this',
    '// rule.',
    'inline bool '
    'wsdStuddedLeatherNotMetal()',
    '    { return true; }',
    '// The clothing rule by',
    '// category.',
    'inline bool '
    'wsdClothingUnprotected(',
    '    int c, int t)',
    '    {',
    '        switch (c) {',
    '        case 0:',
    '            return t > '
    'wsdVcUnprotectedAbove();',
    '        case 1:',
    '            return t < '
    'wsdColdUnprotBelow()',
    '                || t > '
    'wsdColdUnprotAbove();',
    '        case 2:',
    '            return t < '
    'wsdModUnprotBelow()',
    '                || t > '
    'wsdModUnprotAbove();',
    '        case 3:',
    '            return t < '
    'wsdHotUnprotBelow();',
    '        default:',
    '            return false;',
    '        }',
    '    }',
    '// The metal armor rule.',
    'inline bool '
    'wsdMetalUnprotected(',
    '    bool metal, int t)',
    '    { return metal',
    '        && t > '
    'wsdMetalHighTemp(); }',
    '// The combined rule:',
    '// either clause true',
    '// leaves the character',
    '// unprotected.',
    'inline bool wsdUnprotected(',
    '    int c, bool metal, int t)',
    '    { return '
    'wsdClothingUnprotected(c, t)',
    '        || wsdMetalUnprotected'
    '(metal, t); }',
    '',
    '// ---- the exertion ----',
    '// ---- regimes ----',
    '',
    '// Effective temperature',
    '// below 0: a protected',
    '// character gains 5',
    '// degrees per 4',
    '// consecutive turns of',
    '// exertion.',
    'inline int '
    'wsdExertGainBelow0()',
    '    { return 5; }',
    'inline int '
    'wsdExertTurnsBelow0()',
    '    { return 4; }',
    '// One turn of rest holds',
    '// the gain; resting',
    '// longer loses it.',
    'inline int '
    'wsdExertRestHoldBelow0()',
    '    { return 1; }',
    '// The 4-on/1-off cycle',
    '// caps the gain at 20.',
    'inline int '
    'wsdExertMaxBelow0()',
    '    { return 20; }',
    '// Effective temperature',
    '// 0 to 30: a protected',
    '// character gains 5',
    '// degrees after 6',
    '// consecutive turns, 10',
    '// (the maximum) after 12.',
    'inline int '
    'wsdExertGainWarm()',
    '    { return 5; }',
    'inline int '
    'wsdExertTurnsWarm()',
    '    { return 6; }',
    'inline int '
    'wsdExertMaxWarm()',
    '    { return 10; }',
    'inline int '
    'wsdExertTurnsWarmMax()',
    '    { return 12; }',
    '// The gain is retained',
    '// until the character',
    '// rests more than 2 turns',
    '// in a row.',
    'inline int '
    'wsdExertRestLoseWarm()',
    '    { return 2; }',
    '// Effective temperature',
    '// 80 or higher: an',
    '// UNPROTECTED character',
    '// gains 5 degrees per 3',
    '// consecutive turns, up',
    '// to a 25-degree maximum.',
    'inline int '
    'wsdExertGainHot()',
    '    { return 5; }',
    'inline int '
    'wsdExertTurnsHot()',
    '    { return 3; }',
    'inline int wsdExertMaxHot()',
    '    { return 25; }',
    '// Resting drops the gain',
    '// 5 degrees per 3 turns;',
    '// resting AND taking off',
    '// the armor drops 10 per',
    '// 3 turns.',
    'inline int '
    'wsdExertRestDropHot()',
    '    { return 5; }',
    'inline int '
    'wsdExertRestDropHotRelieved()',
    '    { return 10; }',
    '// The drop is floored at',
    '// the non-exerting',
    '// personal temperature.',
    'inline bool '
    'wsdExertDropFloored()',
    '    { return true; }',
    '',
    '// ---- clothing that ----',
    '// ---- functions as armor ----',
    '',
    '// At the DM discretion,',
    '// very cold clothing may',
    '// impart armor class 8;',
    '// cold clothing, armor',
    '// class 9.',
    'inline int '
    'wsdVcArmorClass()',
    '    { return 8; }',
    'inline int '
    'wsdColdArmorClass()',
    '    { return 9; }',
    '// The optional somatic',
    '// miscast risk for',
    '// casting in bulky',
    '// clothing: 10 percent.',
    'inline int '
    'wsdClothingMiscastChance()',
    '    { return 10; }',
    'inline bool '
    'wsdMiscastIsOptional()',
    '    { return true; }',
    '',
    '}   // namespace rules',
]

HEADER = E(*HS) + NL

newfile(HD, HEADER,
        'rules/wsgdress.h')

# the header statics:
# 54 inlines, lines <= 78
# except the 92-char opener,
# brace balance, every line
# classifiable C++ (the
# INCIDENT-2 lesson), no
# bare || / && (the R418b
# lesson)
h = rd(HD)
if h.count('inline ') != 54:
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
    r'|switch |int |bool |\{|\}'
    r'|\|\||&&))')
prev = ''
for i, ln in enumerate(lines):
    c = ln.strip()
    if not c or c.startswith('//'):
        prev = ln
        continue
    if not _CODE.match(ln):
        die('the header line %d is '
            'not classifiable C++ '
            '(%r)'
            % (i, ln[:40]))
    if ((_re.match(r'^ +\|\| ', ln)
         or _re.match(r'^ +&& ', ln))
        and (prev.rstrip().endswith(';')
             or not prev.strip()
             or prev.lstrip()
             .startswith('//'))):
        die('the header line %d is '
            'a bare continuation'
            % i)
    prev = ln

# ======== (c) the gap report
# ======== flips (8) ========

FL = [
    ('- [ ] **Dressing for the '
     'weather** (pp. 18-20)',
     '- [x] **Dressing for the '
     'weather** (pp. 18-20) - '
     'R426: the whole chapter '
     'pins as rules/wsgdress.h'),
    ('  - [ ] Personal '
     'temperature (p. 18)',
     '  - [x] Personal '
     'temperature (p. 18) - '
     'R426: the Fahrenheit '
     'effective/personal '
     'temperature system pins '
     'as rules/wsgdress.h'),
    ('  - [ ] Clothing (p. 18)',
     '  - [x] Clothing (p. 18) '
     '- R426: the four '
     'categories (the ranges, '
     'the encumbrance '
     'equivalents, the costs) '
     'pin as rules/wsgdress.h'),
    ('  - [ ] Protected and '
     'unprotected characters '
     '(p. 19)',
     '  - [x] Protected and '
     'unprotected characters '
     '(p. 19) - R426: the five '
     'unprotected rules pin as '
     'rules/wsgdress.h'),
    ('  - [ ] Clothing that '
     'functions as armor (p. 19)',
     '  - [x] Clothing that '
     'functions as armor '
     '(p. 19) - R426: the AC '
     '8/9 option and the '
     'miscast risk pin as '
     'rules/wsgdress.h'),
    ('  - [ ] Effects of '
     'exertion (p. 20)',
     '  - [x] Effects of '
     'exertion (p. 20) - R426: '
     'the three regimes pin as '
     'rules/wsgdress.h'),
    ('- [ ] **Table 3: effects '
     'of clothing and armor on '
     'personal temperature** '
     '(p. 19)',
     '- [x] **Table 3: effects '
     'of clothing and armor on '
     'personal temperature** '
     '(p. 19) - R426: the 15 '
     'attire rows x the 4 '
     'columns pin as '
     'rules/wsgdress.h'),
    ('Post-state at R425: 5 '
     'closed, 181 open (the '
     'R425 round closes the '
     'Proficiency Check system, '
     'the improving rule, the '
     'expanding optional rule '
     'and the two printed p. 12 '
     'grids - five boxes; the '
     '25 proficiency '
     'descriptions and '
     'everything else stay '
     'open, worked top-down - '
     'data tables first).',
     'Post-state at R426: 12 '
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
     'data tables first).'),
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
if g.count('- [x]') != 12:
    die('the gap closed count %d'
        % g.count('- [x]'))
opens = [l for l in g.split(NL)
         if l.lstrip()
         .startswith('- [ ]')]
if len(opens) != 174:
    die('the gap open count %d'
        % len(opens))
if g.count('**Table ') != 42:
    die('the gap table manifest %d'
        % g.count('**Table '))

# ======== (d) regtest.cpp -
# ======== the include ========

pair(RT,
     '#include "rules/wsgprof.h"  '
     '// R425: the WSG '
     'wilderness proficiencies',
     '#include "rules/wsgprof.h"  '
     '// R425: the WSG '
     'wilderness proficiencies'
     + NL
     + '#include "rules/wsgdress.h"  '
     '// R426: the WSG dressing '
     'for the weather',
     'regtest: the include line')

# ======== (e) regtest.cpp -
# ======== the R426 audit ========

AUD = E(*[l.rstrip() for l in [
    '    // ---- R426: the WSG',
    '    // dressing pin audit ----',
    '    // The first WSG pin round',
    '    // after the arc opener',
    '    // closes the',
    '    // dressing-for-the-weather',
    '    // chapter whole',
    '    // (rules/wsgdress.h,',
    '    // prefix wsd): the four',
    '    // clothing categories (the',
    '    // ranges, the',
    '    // encumbrance equivalents,',
    '    // the outfit costs), the',
    '    // Table 3 grid (the 15',
    '    // attire rows x the 4',
    '    // temperature columns,',
    '    // cumulative) verified',
    '    // cell for cell with the',
    '    // row/column censuses,',
    '    // the',
    '    // protected/unprotected',
    '    // truth table, the three',
    '    // exertion regimes with',
    '    // the book own chain mail',
    '    // example and the',
    '    // clothing-as-armor',
    '    // option; census',
    '    // 351 -> 352.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        if (wsdClothingCount() != 4',
    '                || wsdAttireCount()',
    '                != 15',
    '                || wsdColCount() != 4',
    '                || !wsdDegreesAreFahrenheit()',
    '                || !wsdTempAdjCumulative()',
    '                || !wsdStuddedLeatherNotMetal()',
    '                || !wsdExertDropFloored()',
    '                || !wsdMiscastIsOptional())',
    '            ++bad;',
    '        if (wsdCategoryLo(0)',
    '                != -99',
    '                || wsdCategoryLo(1)',
    '                != 0',
    '                || wsdCategoryLo(2)',
    '                != 31',
    '                || wsdCategoryLo(3)',
    '                != 76',
    '                || wsdCategoryHi(0)',
    '                != -1',
    '                || wsdCategoryHi(1)',
    '                != 30',
    '                || wsdCategoryHi(2)',
    '                != 75',
    '                || wsdCategoryHi(3)',
    '                != 99)',
    '            ++bad;',
    '        if (wsdCategoryCostGp(0)',
    '                != 15',
    '                || wsdCategoryCostGp(1)',
    '                != 7',
    '                || wsdCategoryCostGp(2)',
    '                != 3',
    '                || wsdCategoryCostGp(3)',
    '                != 0',
    '                || wsdHotClothingCostSp() != 6',
    '                || !wsdVcEncEqPlateMail()',
    '                || wsdVcEncWeightGp()',
    '                != 450',
    '                || !wsdColdEncEqRingMail()',
    '                || wsdColdEncWeightGp() != 250',
    '                || !wsdModEncEqLeather()',
    '                || wsdModEncWeightGp() != 150',
    '                || !wsdHotEncumbranceNone()',
    '                || wsdVcEqColdLayers() != 2',
    '                || wsdVcEqModLayers() != 4)',
    '            ++bad;',
    '        // the thresholds',
    '        if (wsdVcUnprotectedAbove() != 30',
    '                || wsdColdUnprotBelow() != 0',
    '                || wsdColdUnprotAbove() != 50',
    '                || wsdModUnprotBelow() != 30',
    '                || wsdModUnprotAbove() != 80',
    '                || wsdHotUnprotBelow() != 50',
    '                || wsdMetalHighTemp()',
    '                != 80)',
    '            ++bad;',
    '        // the Table 3 grid,',
    '        // cell for cell, with',
    '        // the row/column',
    '        // censuses and the',
    '        // zero count',
    '        int C[15][4] = {',
    '            {30,40,50,60},',
    '            {20,30,40,50},',
    '            {10,20,20,30},',
    '            {0,0,0,0},',
    '            {10,20,30,40},',
    '            {10,20,30,40},',
    '            {10,20,30,30},',
    '            {5,10,15,20},',
    '            {5,10,15,20},',
    '            {0,5,10,20},',
    '            {0,5,10,20},',
    '            {0,5,10,15},',
    '            {5,0,15,30},',
    '            {20,30,40,50},',
    '            {10,5,10,20}};',
    '        int rs[15] = {180,140,80,0,',
    '            100,100,90,50,50,35,',
    '            35,30,50,140,45};',
    '        int cs[4] = '
    '{135,220,325,445};',
    '        int zeros = 0;',
    '        for (int a = 0;',
    '             a < wsdAttireCount();',
    '             ++a) {',
    '            int rsum = 0;',
    '            for (int k = 0;',
    '                 k < wsdColCount();',
    '                 ++k) {',
    '                int v =',
    '                    wsdTempAdj'
    '(a, k);',
    '                if (v != C[a][k])',
    '                    ++bad;',
    '                if (v == 0) ++zeros;',
    '                rsum += v;',
    '            }',
    '            if (rsum != rs[a]) ++bad;',
    '        }',
    '        for (int k = 0;',
    '             k < wsdColCount();',
    '             ++k) {',
    '            int csum = 0;',
    '            for (int a = 0;',
    '                 a < wsdAttireCount();',
    '                 ++a)',
    '                csum +=',
    '                    wsdTempAdj'
    '(a, k);',
    '            if (csum != cs[k]) ++bad;',
    '        }',
    '        if (zeros != 8) ++bad;',
    '        // the column mapping',
    '        if (wsdColForTemp(-5) != 0',
    '                || wsdColForTemp(-1)',
    '                != 0',
    '                || wsdColForTemp(0)',
    '                != 1',
    '                || wsdColForTemp(30)',
    '                != 1',
    '                || wsdColForTemp(31)',
    '                != 2',
    '                || wsdColForTemp(75)',
    '                != 2',
    '                || wsdColForTemp(76)',
    '                != 3',
    '                || wsdColForTemp(110)',
    '                != 3)',
    '            ++bad;',
    '        // the book own',
    '        // cumulative example:',
    '        // subzero, plate mail +',
    '        // very cold clothing',
    '        // = +40',
    '        if (wsdTempAdj(0,',
    '                       wsdColForTemp(-5))',
    '                + wsdTempAdj(6,',
    '                             wsdColForTemp(-5))',
    '                != 40)',
    '            ++bad;',
    '        // the protected truth',
    '        // table (the',
    '        // boundaries, both',
    '        // clauses)',
    '        if (!wsdClothingUnprotected(0, 31)',
    '                || wsdClothingUnprotected(0, 30)',
    '                || !wsdClothingUnprotected(1, -1)',
    '                || wsdClothingUnprotected(1, 0)',
    '                || !wsdClothingUnprotected(1, 51)',
    '                || wsdClothingUnprotected(1, 50)',
    '                || !wsdClothingUnprotected(2, 29)',
    '                || wsdClothingUnprotected(2, 30)',
    '                || !wsdClothingUnprotected(2, 81)',
    '                || wsdClothingUnprotected(2, 80)',
    '                || !wsdClothingUnprotected(3, 49)',
    '                || wsdClothingUnprotected(3, 50)',
    '                || !wsdMetalUnprotected(true, 81)',
    '                || wsdMetalUnprotected(true, 80)',
    '                || wsdMetalUnprotected(false, 100)',
    '                || !wsdUnprotected'
    '(2, true, 81)',
    '                || wsdUnprotected'
    '(2, true, 31)',
    '                || wsdUnprotected'
    '(2, false, 31)',
    '                || wsdUnprotected'
    '(3, false, 60)',
    '                || !wsdUnprotected'
    '(3, false, 40))',
    '            ++bad;',
    '        // the exertion pins',
    '        if (wsdExertGainBelow0() != 5',
    '                || wsdExertTurnsBelow0() != 4',
    '                || wsdExertRestHoldBelow0() != 1',
    '                || wsdExertMaxBelow0() != 20',
    '                || wsdExertGainWarm() != 5',
    '                || wsdExertTurnsWarm() != 6',
    '                || wsdExertMaxWarm() != 10',
    '                || wsdExertTurnsWarmMax() != 12',
    '                || wsdExertRestLoseWarm() != 2',
    '                || wsdExertGainHot() != 5',
    '                || wsdExertTurnsHot() != 3',
    '                || wsdExertMaxHot() != 25',
    '                || wsdExertRestDropHot() != 5',
    '                || wsdExertRestDropHotRelieved() != 10)',
    '            ++bad;',
    '        // the book own chain',
    '        // mail example: 90',
    '        // degrees, chain mail',
    '        // (+20), a 15-turn hike',
    '        // (+25) = 135 personal',
    '        if (wsdTempAdj(9, 3) != 20',
    '                || 90 + wsdTempAdj(9, 3)',
    '                != 110',
    '                || 90 + wsdTempAdj(9, 3)',
    '                + wsdExertMaxHot()',
    '                != 135',
    '                || wsdExertRestDropHot() * 3 != 15',
    '                || wsdExertRestDropHotRelieved() * 2',
    '                + wsdExertRestDropHot() != 25)',
    '            ++bad;',
    '        // clothing as armor',
    '        if (wsdVcArmorClass() != 8',
    '                || wsdColdArmorClass() != 9',
    '                || wsdClothingMiscastChance() != 10)',
    '            ++bad;',
    '        printf("R426 WSG dressing '
    'pin audit: bad %d' + chr(92)
    + 'n", bad);',
    '        if (bad) return 1;',
    '    }']])

R227 = ('    // ---- R227: the wis '
        'mental save wiring '
        'audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R426 audit block')

# ======== the verify pass ========

if applied and already:
    die('the mixed applied/already '
        'state (the R420 lesson)')

s = rd(RT)
if s.count('audit: bad') != 352:
    die('the census %d'
        % s.count('audit: bad'))
if s.count('R426 WSG dressing '
           'pin audit') != 1:
    die('the R426 audit label')

# the no-split-identifier gate
# (the R426 lesson): a C++
# identifier must never be
# split across two lines - a
# line ending in an identifier
# character followed by a line
# starting with one is two
# juxtaposed tokens and never
# compiles (the R392 lesson
# class). Applies to the audit
# block and the header, code
# lines only.
_idc = ('_' 'abcdefghijklmnopqrstuvwxyz'
        'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        '0123456789')
for blk, name in ((AUD, 'the R426 audit'),
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
                + name
                + ' (%r|%r)'
                % (pt[-20:], c[:20]))
        prev = ln

# the string-literal parity
# gate (the R421b lesson): no
# CODE line in the R426 audit
# block may carry an
# unterminated string literal
for ln in AUD.split(NL):
    c = ln.lstrip()
    if (c and not c.startswith('//')
            and ln.count(chr(34)) % 2):
        die('the R426 audit block '
            'has an unterminated '
            'string literal')

# the no-bare-|| gate (the
# R418b lesson): no wsd chain
# may BEGIN with '||' - a
# '||' line is legal only
# inside an open chain
prev = ''
for ln in s.split(NL):
    if ('wsd' in ln
            and ln != prev
            and _re.match(r'^ +\|\| ', ln)
            and (prev.rstrip().endswith(';')
                 or not prev.strip()
                 or prev.lstrip()
                 .startswith('//'))):
        die('a bare || wsd line')
    prev = ln

# the wsd identifier
# resolution (the R412b
# lesson): every wsd symbol
# the audit calls must be
# defined in the header
called = set(_re.findall(
    r'\b(wsd\w+)\s*\(', AUD))
defined = set(_re.findall(
    r'\b(wsd\w+)\s*\(', h))
for sym in sorted(called):
    if sym not in defined:
        die('the audit calls %s, '
            'undefined in the '
            'header' % sym)

# the include comment whole
# (the R390 lesson)
if s.count('#include "rules/'
          'wsgdress.h"  // R426: '
          'the WSG dressing for '
          'the weather') != 1:
    die('the wsgdress include line')

# the gap report on disk
g = rd(GR)
if g.count('- [x]') != 12:
    die('the gap closed count %d'
        % g.count('- [x]'))
opens = [l for l in g.split(NL)
         if l.lstrip()
         .startswith('- [ ]')]
if len(opens) != 174:
    die('the gap open count %d'
        % len(opens))
if g.count('**Table ') != 42:
    die('the gap table manifest')

# the seed record
if 'R425 landed 2026-10-14' not in rd(SD):
    die('the seed R425 record')

# the caller contract: no
# engine caller touches the
# wsd pins
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bwsd\w', rd(path)):
        die('%s calls the wsd pins '
            'early' % path)

print('R426 splice: ALL OK '
      '(applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the first WSG pin '
      'round after the opener -')
print('  the dressing-for-the-'
      'weather chapter closes')
print('  whole as rules/wsgdress.h '
      '(54 inlines, prefix')
print('  wsd): the four clothing '
      'categories, Table 3 (the')
print('  15 attire rows, '
      'cumulative), the')
print('  protected/unprotected '
      'rules, the exertion')
print('  regimes and the '
      'clothing-as-armor option;')
print('  the wsg_gap_report.md '
      'flips to 12 closed, 174')
print('  open, 42 tables; census '
      '351 -> 352')
print('commit: R426: the WSG '
      'dressing for the weather '
      '- the personal '
      'temperature system '
      '(census 352)')

