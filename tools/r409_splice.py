#!/usr/bin/env python3
# R409: the UA Appendix S
# STAT LINES - the
# S/I/W/D/C/CH/CM rows for
# the 23 deity blocks (pp.
# 110-120) pin, the third
# data round riding the R406
# stat-block precedent. The
# clean djvu scan carries all
# 23 lines; the systematic
# OCR reads resolve (the
# capital I renders "1:", the
# label dots read colons, the
# asterisk/diamond read
# plus, the dot reads comma)
# and every resolved read
# carries an independent
# confirmation - the
# same-score agreement, the
# R153 percentile bands, or
# the block's own
# DAMAGE/ATTACK print. The
# Cyrrollalee plus pair
# garbles with no independent
# confirmation - it records
# as the hole sentinel, never
# a guess. The Bahgtru
# damage line prints +15
# against the stat line's
# +14 - the print diverges;
# the stat line pins and the
# divergence records.
#
# 1. rules/uasstatlines.h
#    (NEW, prefix usl, 15
#    inline functions): the
#    23 rows x 7 scores plus
#    the exceptional
#    percentiles (18/00 x2,
#    18/01 x1), the S
#    parenthetical plusses,
#    the CH/CM parenthetical
#    forms (the Hanali
#    "(special)" sentinel),
#    the DAMAGE/ATTACK mirror
#    registry and the Bahgtru
#    divergence flag.
# 2. regtest.cpp: the
#    include rides the R406
#    include; the R409 audit
#    lands before the R227
#    anchor - every row pins
#    cell for cell, the R406
#    roster cross-checks
#    name for name, the R153
#    percentile bands
#    cross-check the 18/00
#    and 18/01 plusses live,
#    the mirror cross-checks
#    the damage prints, the
#    R322 band ladder
#    cross-checks the printed
#    CM extremes; census 335
#    -> 336.
# 3. tools/ua_gap_report.md:
#    the Appendix S box and
#    the section tail take
#    AMENDED R409 notes - the
#    stat lines land, the
#    class lines, MOVE and
#    the pantheon prose stay
#    open.
# 4. The seed takes the R408
#    record.

import io
import os

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
        'R409 splice ABORT: ' + msg)


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


# ---- the data (the print, roster order) ----
# name, str, pct, hit, dmg, int, wis,
# dex, con, cha, chaParen, cm, cmParen
ROWS = [
    ("CLANGGEDIN SILVERBEARD",
     25, 0, 7, 14, 20, 19, 20, 25, 16,
     22, 13, 20),
    ("VERGADAIN",
     22, 0, 4, 10, 23, 20, 23, 25, 18,
     24, 18, 24),
    ("DUMATHOIN",
     25, 0, 7, 14, 23, 25, 20, 25, 18,
     24, 13, 16),
    ("ABBATHOR",
     24, 0, 6, 12, 22, 16, 24, 24, 8,
     14, 7, 13),
    ("BERRONAR",
     21, 0, 4, 9, 25, 25, 20, 25, 19,
     25, 20, 25),
    ("AERDRIE FAENYA",
     8, 0, 0, 0, 24, 22, 24, 19, 23,
     0, 25, 0),
    ("EREVAN ILESERE",
     19, 0, 3, 7, 23, 16, 25, 20, 24,
     0, 25, 0),
    ("SOLONOR THELANDIRA",
     21, 0, 4, 9, 22, 21, 25, 21, 23,
     0, 22, 0),
    ("HANALI CELANIL",
     15, 0, 0, 0, 23, 23, 25, 20, 25,
     -2, 30, 0),
    ("LABELAS ENORETH",
     12, 0, 0, 0, 25, 25, 19, 18, 24,
     0, 25, 0),
    ("SHEELA PERYROYL",
     18, 100, 3, 6, 22, 25, 22, 24, 22,
     0, 24, 0),
    ("ARVOREEN",
     20, 0, 3, 8, 21, 23, 24, 23, 21,
     0, 21, 0),
    ("CYRROLLALEE",
     17, 0, -1, -1, 23, 24, 24, 23, 22,
     0, 21, 0),
    ("BRANDOBARIS",
     19, 0, 3, 7, 24, 17, 25, 23, 20,
     0, 19, 0),
    ("BAERVAN WILDWANDERER",
     18, 100, 3, 6, 21, 19, 25, 22, 22,
     0, 16, 0),
    ("URDLEN",
     19, 0, 3, 7, 20, 14, 20, 24, 3,
     0, -14, 0),
    ("SEGOJAN EARTHCALLER",
     18, 1, 1, 3, 22, 23, 18, 24, 20,
     0, 15, 0),
    ("FLANDAL STEELSKIN",
     22, 0, 4, 10, 18, 20, 17, 23, 18,
     0, 16, 0),
    ("BAHGTRU",
     25, 0, 7, 14, 6, 6, 18, 25, 5,
     22, -2, 16),
    ("SHARGAAS",
     20, 0, 3, 8, 19, 15, 24, 19, 7,
     24, 8, 20),
    ("ILNEVAL",
     23, 0, 5, 11, 17, 14, 20, 23, 8,
     25, 5, 24),
    ("YURTRUS",
     18, 0, 1, 2, 18, 11, 10, 17, -4,
     0, -25, 0),
    ("LUTHIC",
     19, 0, 3, 7, 18, 19, 14, 20, 12,
     25, 3, 24),
]

# The DAMAGE/ATTACK line
# parenthetical per block, as
# printed (0 = the line prints
# no parenthetical: the Nil
# reads, "see below", "by
# weapon type", the bare
# ranges). The Bahgtru 15 is
# the recorded divergence
# against the stat line's 14.
MIRROR = [
    14, 10, 14, 12, 9, 0, 7, 0, 0, 0,
    6, 8, 0, 7, 6, 7, 3, 10, 15, 8,
    11, 0, 7,
]

FLD = ('str', 'pct', 'hit', 'dmg',
       'intl', 'wis', 'dex', 'con',
       'cha', 'chaParen', 'cm',
       'cmParen')


def row_lines(i):
    r = ROWS[i]
    head = ('        { "%s",'
            % r[0])
    vals = ('          %d, %d, %d, %d,'
            ' %d, %d, %d, %d, %d,'
            ' %d, %d, %d },'
            % r[1:])
    tail = '    };'
    return [head, vals] if i < 22 \
        else [head, vals]


def row_cond(i):
    r = ROWS[i]
    parts = ['        if (uaslLine(%d)'
             '.str != %d' % (i, r[1])]
    for f, v in zip(FLD[1:], r[2:]):
        parts.append(
            '                || uaslLine(%d)'
            '.%s != %d' % (i, f, v))
    parts[-1] += ') ++bad;'
    return NL.join(parts)


# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R408 landed 2026-10-13:',
    '  commit cee2979 (census 335,',
    '  preflight GREEN), the UA p. 26',
    '  armor class table -',
    '  rules/uaac26.h (prefix uacr)',
    '  - the 11 composite rows, 28',
    '  composites, the',
    '  R191/R371/R392 cross-checks',
    '  live; the two stale duplicate',
    '  boxes close. The md5 diverged',
    '  for the sixteenth round',
    '  running - benign; the md5',
    '  stays advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R408 landed 2026-10-13' in s:
    already.append('seed: the R408 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R408 record')
s = rd(SD)
if s.count('R408 landed 2026-10-13') != 1:
    die('the R408 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uasstatlines.h =========
SL = 'rules/uasstatlines.h'

COMMENT = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uasstatlines.h',
    '// The UA APPENDIX S STAT LINES',
    '// (pp. 110-120), R409: the',
    '// S/I/W/D/C/CH/CM row for each of',
    '// the 23 deity stat blocks the R406',
    '// round pinned. The clean djvu scan',
    '// carries all 23 lines; the',
    '// systematic OCR reads resolve:',
    '// the capital I renders "1:", the',
    '// label dots ("S.", "C.", "CM.")',
    '// read colons, the asterisk and the',
    '// diamond read plus, the dot reads',
    '// comma. Every resolved read carries',
    '// an independent confirmation -',
    '// the same-score agreement (the',
    '// four S:19 rows, the three S:25',
    '// rows, the pairs at 22/21/20, the',
    '// 18/00 pair), the R153 percentile',
    '// bands (18/00 reads +3/+6, 18/01',
    '// reads +1/+3), or the block own',
    '// DAMAGE/ATTACK print.',
    '//',
    '// The hole: the Cyrrollalee plus',
    '// pair prints "( + 1. + 1)" - the',
    '// dot sits inside the value pair',
    '// and the block damage line prints',
    '// "By weapon type" (no',
    '// parenthetical), so no',
    '// independent confirmation exists.',
    '// The pair records as the hole',
    '// sentinel, never a guess.',
    '//',
    '// The divergence: the Bahgtru',
    '// DAMAGE/ATTACK line prints',
    '// 10-60 (+15) against the stat',
    '// line S:25 (+ 7, + 14). Both',
    '// prints are scan-clean; the print',
    '// diverges. The stat line pins and',
    '// the mirror registry records the',
    '// damage line 15 with the',
    '// divergence flag.',
    '//',
    '// The paren codes: 0 = the print',
    '// carries no parenthetical; -2 =',
    '// the Hanali CH:25 "(special)". The',
    '// plus codes: 0 = the plain scores',
    '// carry no parenthetical plusses',
    '// (S:8, S:12, S:15); -1 = the',
    '// Cyrrollalee hole. The percent',
    '// code: 0 = none; 1 and 100 print',
    '// 18/01 and 18/00.')

TABLE = []
for i in range(23):
    TABLE.extend(row_lines(i))
TABLE.append('    };')

HEADER = E(
    COMMENT,
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The plus codes.',
    'const int UASL_PLUS_NONE = 0;',
    'const int UASL_PLUS_HOLE = -1;',
    '',
    '// The paren codes.',
    'const int UASL_PAREN_NONE = 0;',
    'const int UASL_PAREN_SPECIAL = -2;',
    '',
    '// One stat line, as printed:',
    '// the seven scores, the',
    '// exceptional percentile, the S',
    '// parenthetical plusses, and the',
    '// CH/CM parenthetical forms.',
    'struct UaslStatLine {',
    '    const char* name;',
    '    int str;',
    '    int pct;   // 0 none, 1 = 18/01,'
    ' 100 = 18/00',
    '    int hit;   // 0 unprinted, -1 hole',
    '    int dmg;   // 0 unprinted, -1 hole',
    '    int intl;',
    '    int wis;',
    '    int dex;',
    '    int con;',
    '    int cha;',
    '    int chaParen;   // 0 none, -2'
    ' special',
    '    int cm;',
    '    int cmParen;',
    '};',
    '',
    '// The 23 stat lines, in the R406',
    '// roster order.',
    'inline const UaslStatLine&'
    ' uaslLine(int i) {',
    '    static const UaslStatLine T[23]'
    ' = {',
    *TABLE,
    '    if (i < 0) i = 0;',
    '    if (i > 22) i = 22;',
    '    return T[i];',
    '}',
    '',
    'inline int uaslLineCount()',
    '    { return 23; }',
    '',
    '// The DAMAGE/ATTACK line',
    '// parenthetical per block, as',
    '// printed (0 = the line prints no',
    '// parenthetical). The Bahgtru 15',
    '// is the recorded divergence',
    '// against the stat line 14.',
    'inline int uaslDmgLineMirror(int i) {',
    '    static const int k[23] = {',
    '        %s' % ', '.join(
        str(v) for v in MIRROR[:12])
        + ',',
    '        %s' % ', '.join(
        str(v) for v in MIRROR[12:])
        + ',',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 22) i = 22;',
    '    return k[i];',
    '}',
    '',
    '// The Bahgtru print divergence:',
    '// the damage line 15 against the',
    '// stat line 14 - recorded, not',
    '// reconciled.',
    'inline bool uaslBahgtruDmgDiverges()',
    '    { return true; }',
    '',
    '}   // namespace rules',
    '')

newfile(SL, HEADER + NL,
        'the Appendix S stat lines header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uaappends.h"  '
     '// R406: the UA Appendix S stat'
     ' blocks',
     E(
    '#include "rules/uaappends.h"  '
    '// R406: the UA Appendix S stat'
    ' blocks',
    '#include "rules/uasstatlines.h"  '
    '// R409: the UA Appendix S stat'
    ' lines'),
     'regtest: the stat lines include')

AUD = E(
    '    // ---- R409: the UA Appendix S',
    '    // stat lines pin audit ----',
    '    // The 23 S/I/W/D/C/CH/CM rows',
    '    // pin cell for cell; the R406',
    '    // roster cross-checks name for',
    '    // name; the R153 percentile',
    '    // bands cross-check the 18/00',
    '    // and 18/01 plusses live; the',
    '    // DAMAGE/ATTACK mirror',
    '    // cross-checks the damage',
    '    // prints (the Bahgtru +15',
    '    // divergence records); the R322',
    '    // band ladder cross-checks the',
    '    // printed CM extremes; the',
    '    // Cyrrollalee plus pair stays',
    '    // the recorded hole; census',
    '    // 335 -> 336.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (uaslLineCount() != 23) ++bad;',
    '        // the exceptional rows: the',
    '        // 18/00 pair, the 18/01',
    '        if (uaslLine(10).pct != 100',
    '                || uaslLine(14).pct'
    ' != 100',
    '                || uaslLine(16).pct'
    ' != 1) ++bad;',
    '        // the plain rows carry no',
    '        // plusses (S:8, S:12, S:15)',
    '        if (uaslLine(5).hit != 0',
    '                || uaslLine(8).hit != 0',
    '                || uaslLine(9).hit != 0',
    '                || uaslLine(0).hit == 0)',
    '            ++bad;',
    '        // the Cyrrollalee hole',
    '        if (uaslLine(12).hit != -1',
    '                || uaslLine(12).dmg'
    ' != -1) ++bad;')

for i in range(23):
    AUD += NL + row_cond(i)

ROSTER_A = [
    'strcmp(uaslLine(%d).name,'
    ' uasStat(%d).name)' % (i, i)
    for i in range(12)]
ROSTER_B = [
    'strcmp(uaslLine(%d).name,'
    ' uasStat(%d).name)' % (i, i)
    for i in range(12, 23)]

def roster_sum(terms):
    parts = ['        if ('
             + terms[0]]
    for t in terms[1:]:
        parts.append('                + ' + t)
    parts.append('                != 0) ++bad;')
    return NL.join(parts)

AUD += NL + E(
    '        // ---- the R406 roster ----',
    '        // the names cross-check the',
    '        // stat blocks name for name',
    '        ' + roster_sum(ROSTER_A)[8:],
    '        ' + roster_sum(ROSTER_B)[8:],
    '        // ---- the R153 percentile',
    '        // bands (live) ----',
    '        {',
    '            ExceptionalStrength ex;',
    '            ex.has = true;',
    '            ex.pct = 100;',
    '            if (ex.hitAdj()'
    ' != uaslLine(10).hit',
    '                    || ex.dmgAdj()'
    ' != uaslLine(10).dmg',
    '                    || ex.hitAdj()'
    ' != uaslLine(14).hit',
    '                    || ex.dmgAdj()'
    ' != uaslLine(14).dmg) ++bad;',
    '        }',
    '        {',
    '            ExceptionalStrength ex;',
    '            ex.has = true;',
    '            ex.pct = 1;',
    '            if (ex.hitAdj()'
    ' != uaslLine(16).hit',
    '                    || ex.dmgAdj()'
    ' != uaslLine(16).dmg) ++bad;',
    '        }',
    '        // ---- the damage mirror ----',
    '        if (uaslDmgLineMirror(0)'
    ' != uaslLine(0).dmg',
    '                || uaslDmgLineMirror(1)'
    ' != uaslLine(1).dmg',
    '                || uaslDmgLineMirror(2)'
    ' != uaslLine(2).dmg',
    '                || uaslDmgLineMirror(3)'
    ' != uaslLine(3).dmg',
    '                || uaslDmgLineMirror(4)'
    ' != uaslLine(4).dmg) ++bad;',
    '        if (uaslDmgLineMirror(6)'
    ' != uaslLine(6).dmg',
    '                || uaslDmgLineMirror(10)'
    ' != uaslLine(10).dmg',
    '                || uaslDmgLineMirror(11)'
    ' != uaslLine(11).dmg',
    '                || uaslDmgLineMirror(13)'
    ' != uaslLine(13).dmg',
    '                || uaslDmgLineMirror(14)'
    ' != uaslLine(14).dmg',
    '                || uaslDmgLineMirror(15)'
    ' != uaslLine(15).dmg',
    '                || uaslDmgLineMirror(16)'
    ' != uaslLine(16).dmg',
    '                || uaslDmgLineMirror(17)'
    ' != uaslLine(17).dmg',
    '                || uaslDmgLineMirror(19)'
    ' != uaslLine(19).dmg',
    '                || uaslDmgLineMirror(20)'
    ' != uaslLine(20).dmg',
    '                || uaslDmgLineMirror(22)'
    ' != uaslLine(22).dmg) ++bad;',
    '        // the unprinted mirrors: the',
    '        // Nil reads, "see below",',
    '        // "by weapon type", the bare',
    '        // ranges',
    '        if (uaslDmgLineMirror(5) != 0',
    '                || uaslDmgLineMirror(7)'
    ' != 0',
    '                || uaslDmgLineMirror(8)'
    ' != 0',
    '                || uaslDmgLineMirror(9)'
    ' != 0',
    '                || uaslDmgLineMirror(12)'
    ' != 0',
    '                || uaslDmgLineMirror(21)'
    ' != 0) ++bad;',
    '        // the Bahgtru divergence:',
    '        // the damage line 15 against',
    '        // the stat line 14 - the',
    '        // recorded print divergence',
    '        if (uaslDmgLineMirror(18) != 15',
    '                || uaslLine(18).dmg'
    ' != 14',
    '                || !uaslBahgtruDmgDiverges())',
    '            ++bad;',
    '        // ---- the R322 band ladder',
    '        // (live) ----',
    '        // the printed CM extremes sit',
    '        // in the comeliness bands: the',
    '        // Hanali 30 atop unearthly,',
    '        // the Yurtrus -25 repulsed,',
    '        // the Urdlen -14 disgust, the',
    '        // Clanggedin 13 plain',
    '        if (uaComelinessBand('
    'uaslLine(8).cm) != 9',
    '                || uaComelinessBand('
    'uaslLine(15).cm) != 1',
    '                || uaComelinessBand('
    'uaslLine(21).cm) != 0',
    '                || uaComelinessBand('
    'uaslLine(0).cm) != 5) ++bad;',
    '        printf("R409 UA appendix S stat'
    ' lines pin audit: bad %d'
    + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R409 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '      - AMENDED R407: the clerical',
    '        charts land (rules/uascharts.h)',
    '        - CLOSED as their own item; the',
    '        Appendix S box stays open on',
    '        the class lines, MOVE, the stat',
    '        lines and the pantheon prose.'),
    E(
    '      - AMENDED R407: the clerical',
    '        charts land (rules/uascharts.h)',
    '        - CLOSED as their own item; the',
    '        Appendix S box stays open on',
    '        the class lines, MOVE, the stat',
    '        lines and the pantheon prose.',
    '      - AMENDED R409: the stat lines',
    '        land (rules/uasstatlines.h) -',
    '        the 23 S/I/W/D/C/CH/CM rows',
    '        pin with the R153/R322',
    '        cross-checks live, the',
    '        Cyrrollalee plus pair the',
    '        recorded hole, the Bahgtru',
    '        damage divergence recorded;',
    '        the class lines, MOVE and the',
    '        pantheon prose stay open.'),
    'gap: the Appendix S box takes R409')

pair(GP, E(
    '  - AMENDED R407: the charts land',
    '    (rules/uascharts.h) - the class',
    '    lines, MOVE, stat lines and the',
    '    prose stay open.'),
    E(
    '  - AMENDED R407: the charts land',
    '    (rules/uascharts.h) - the class',
    '    lines, MOVE, stat lines and the',
    '    prose stay open.',
    '  - AMENDED R409: the stat lines',
    '    land (rules/uasstatlines.h) - the',
    '    class lines, MOVE and the',
    '    pantheon prose stay open.'),
    'gap: the section tail takes R409')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 336:
    die('the census %d' % s.count('audit: bad'))
if s.count('R409 UA appendix S stat lines'
           ' pin audit') != 1:
    die('the R409 audit label')
if s.count('uaslLine') < 100:
    die('the uaslLine call count %d'
        % s.count('uaslLine'))

p = rd(SL)
if p.count('inline') != 4:
    die('the stat lines inline count %d'
        % p.count('inline'))
if p.count('UASL_PLUS_HOLE') != 1:
    die('the hole constant count')
if not p.endswith(NL):
    die('the stat lines trailing newline')

g = rd(GP)
if g.count('AMENDED R409') != 2:
    die('the gap amended count %d'
        % g.count('AMENDED R409'))

for path, mark in (
        (SL, 'uaslDmgLineMirror'),
        (RT, 'uaslLineCount'),
        (SD, 'R408 landed')):
    if mark not in rd(path):
        die('%s carries no R409 round' % path)

# the contract: no engine caller
import re as _re
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\\busl\\w', rd(path)):
        die('%s calls the pins early'
            % path)

print('R409 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the Appendix S stat lines pin')
print('  - the 23 S/I/W/D/C/CH/CM rows,')
print('  the R153 percentile bands and the')
print('  R322 band ladder cross-check live,')
print('  the Cyrrollalee plus pair the')
print('  recorded hole, the Bahgtru damage')
print('  divergence recorded; the class')
print('  lines, MOVE and the pantheon')
print('  prose stay open; census 335 ->')
print('  336')
print('commit: R409: the UA Appendix S stat'
      ' lines (census 336)')

