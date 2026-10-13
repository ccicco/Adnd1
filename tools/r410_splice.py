#!/usr/bin/env python3
# R410: the UA Appendix S
# CLASS/LEVEL LINES - the six
# printed lines per deity
# block (pp. 110-120) pin:
# CLERIC/DRUID, FIGHTER,
# MAGIC-USER/
# ILLUSIONIST, THIEF/
# ASSASSIN, MONK/BARD and
# PSIONIC ABILITY - the
# fourth data round riding
# the R406 stat-block
# precedent. The clean djvu
# scan carries all 23
# blocks; the systematic
# OCR reads resolve (the
# dropped slash in the
# Berronar label, the
# "IOth"/"1 Oth" letter-O
# reads, the "tighter"
# fighter read, the label
# colon dot) and every
# resolved value carries
# the level-ladder sanity
# (all printed levels sit
# at 20 or below). The
# PSIONIC ABILITY line
# pins here as printed and
# cross-checks the R406
# rating codes LIVE - the
# Brandobaris block prints
# NO line, the recorded
# R406 unrecorded sentinel.
#
# 1. rules/uasclasslines.h
#    (NEW, prefix uascl, 5
#    inline functions + the
#    UasClassLine struct):
#    the 23 blocks x 6
#    lines, the kind codes
#    (Nil, single, dual,
#    each, special, monster,
#    see below) with the
#    printed read strings,
#    the psionic kind codes
#    matching the R406
#    rating codes by design,
#    the Nil census (29) and
#    the psionic census
#    (VI 10, III 5, IV 1,
#    Nil 6, missing 1).
# 2. regtest.cpp: the
#    include rides the R409
#    include; the R410 audit
#    lands before the R227
#    anchor - the spot cells
#    pin (the duals, the
#    monster reads, the
#    each-rows), the Nil
#    census counts, and all
#    23 psionic lines
#    cross-check the R406
#    rating codes live;
#    census 336 -> 337.
# 3. tools/ua_gap_report.md:
#    the Appendix S box and
#    the section tail take
#    AMENDED R410 notes -
#    the class lines land,
#    MOVE and the pantheon
#    prose stay open.
# 4. The seed takes the
#    R409 record.

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
        'R410 splice ABORT: ' + msg)


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
# per block: (cd, f, mu, ta, mb, psn) where
# each entry = (kind, a, b, read).
# kinds: 0 Nil, 1 single(a), 2 dual(a,b),
# 3 each(a), 4 special(a), 5 monster(a),
# 6 see below.
# psn kinds: the R406 rating codes by
# design - 0 VI, 1 III, 2 IV, 3 Nil,
# -1 the missing line (Brandobaris).
K_NIL, K_ONE, K_DUAL, K_EACH = 0, 1, 2, 3
K_SPEC, K_MON, K_SEE = 4, 5, 6

BLOCKS = [
    # CLANGGEDIN SILVERBEARD
    ((K_ONE, 12, 0, "12th level druid"),
     (K_ONE, 17, 0, "17th level ranger"),
     (K_ONE, 10, 0, "10th level magic-user"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 6, 0, "6th level bard"),
     (0, 0, 0, "VI")),
    # VERGADAIN
    ((K_ONE, 12, 0, "12th level druid"),
     (K_ONE, 12, 0, "12th level ranger"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 18, 0, "18th level thief"),
     (K_ONE, 15, 0, "15th level bard"),
     (1, 0, 0, "III")),
    # DUMATHOIN
    ((K_DUAL, 15, 14,
      "15th level cleric/14th level druid"),
     (K_ONE, 16, 0, "16th level fighter"),
     (K_SPEC, 14, 0,
      "Special/14th level illusionist"),
     (K_ONE, 12, 0, "12th level thief"),
     (K_NIL, 0, 0, "Nil"),
     (0, 0, 0, "VI")),
    # ABBATHOR
    ((K_NIL, 0, 0, "Nil"),
     (K_ONE, 14, 0, "14th level fighter"),
     (K_ONE, 11, 0, "11th level illusionist"),
     (K_DUAL, 20, 15,
      "20th level thief/15th level assassin"),
     (K_NIL, 0, 0, "Nil"),
     (1, 0, 0, "III")),
    # BERRONAR
    ((K_DUAL, 15, 12,
      "15th level cleric/12th level druid"),
     (K_ONE, 14, 0, "14th level paladin"),
     (K_ONE, 16, 0, "16th level magic-user"),
     (K_NIL, 0, 0, "Nil"),
     (K_NIL, 0, 0, "Nil"),
     (1, 0, 0, "III")),
    # AERDRIE FAENYA
    ((K_ONE, 14, 0, "14th level druid"),
     (K_ONE, 10, 0, "10th level fighter"),
     (K_SPEC, 0, 0, "Special/Nil"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 10, 0, "10th level bard"),
     (0, 0, 0, "VI")),
    # EREVAN ILESERE
    ((K_ONE, 8, 0, "8th level druid"),
     (K_ONE, 7, 0, "7th level ranger"),
     (K_ONE, 18, 0, "18th level illusionist"),
     (K_ONE, 20, 0, "20th level thief"),
     (K_ONE, 10, 0, "10th level bard"),
     (1, 0, 0, "III")),
    # SOLONOR THELANDIRA
    ((K_ONE, 12, 0, "12th level druid"),
     (K_ONE, 17, 0, "17th level ranger"),
     (K_ONE, 10, 0, "10th level magic-user"),
     (K_ONE, 12, 0, "12th level thief"),
     (K_ONE, 8, 0, "8th level bard"),
     (0, 0, 0, "VI")),
    # HANALI CELANIL
    ((K_DUAL, 14, 10,
      "14th level cleric/10th level druid"),
     (K_NIL, 0, 0, "Nil"),
     (K_DUAL, 16, 15,
      "16th level m-u/15th level illusionist"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 12, 0, "12th level bard"),
     (0, 0, 0, "VI")),
    # LABELAS ENORETH
    ((K_DUAL, 14, 12,
      "14th level cleric/12th level druid"),
     (K_NIL, 0, 0, "Nil"),
     (K_DUAL, 18, 16,
      "18th level m-u/16th level illusionist"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 12, 0, "12th level bard"),
     (0, 0, 0, "VI")),
    # SHEELA PERYROYL
    ((K_ONE, 14, 0, "14th level druid"),
     (K_ONE, 7, 0, "7th level ranger"),
     (K_ONE, 14, 0, "14th level magic-user"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 10, 0, "10th level bard"),
     (3, 0, 0, "Nil")),
    # ARVOREEN
    ((K_ONE, 8, 0, "8th level cleric"),
     (K_ONE, 12, 0, "12th level ranger"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 10, 0, "10th level thief"),
     (K_ONE, 8, 0, "8th level monk"),
     (3, 0, 0, "Nil")),
    # CYRROLLALEE
    ((K_ONE, 10, 0, "10th level cleric"),
     (K_ONE, 10, 0, "10th level paladin"),
     (K_EACH, 8, 0, "8th level in each"),
     (K_NIL, 0, 0, "Nil"),
     (K_NIL, 0, 0, "Nil"),
     (3, 0, 0, "Nil")),
    # BRANDOBARIS
    ((K_ONE, 6, 0, "6th level druid"),
     (K_ONE, 7, 0, "7th level ranger"),
     (K_EACH, 6, 0, "6th level in each"),
     (K_ONE, 19, 0, "19th level thief"),
     (K_ONE, 6, 0, "6th level monk"),
     (-1, 0, 0, "none")),
    # BAERVAN WILDWANDERER
    ((K_ONE, 12, 0, "12th level druid"),
     (K_ONE, 8, 0, "8th level ranger"),
     (K_ONE, 13, 0, "13th level illusionist"),
     (K_ONE, 20, 0, "20th level thief"),
     (K_NIL, 0, 0, "Nil"),
     (1, 0, 0, "III")),
    # URDLEN
    ((K_ONE, 8, 0, "8th level cleric"),
     (K_ONE, 10, 0, "10th level fighter"),
     (K_ONE, 13, 0, "13th level illusionist"),
     (K_ONE, 12, 0, "12th level assassin"),
     (K_NIL, 0, 0, "Nil"),
     (0, 0, 0, "VI")),
    # SEGOJAN EARTHCALLER
    ((K_ONE, 14, 0, "14th level druid"),
     (K_ONE, 6, 0, "6th level fighter"),
     (K_EACH, 16, 0, "16th level in each"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 4, 0, "4th level bard"),
     (0, 0, 0, "VI")),
    # FLANDAL STEELSKIN
    ((K_EACH, 8, 0, "8th level in each"),
     (K_ONE, 10, 0, "10th level fighter"),
     (K_ONE, 15, 0, "15th level magic-user"),
     (K_NIL, 0, 0, "Nil"),
     (K_NIL, 0, 0, "Nil"),
     (0, 0, 0, "VI")),
    # BAHGTRU
    ((K_NIL, 0, 0, "Nil"),
     (K_MON, 16, 0, "As 16-HD monster"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 6, 0, "6th level assassin"),
     (K_NIL, 0, 0, "Nil"),
     (3, 0, 0, "Nil")),
    # SHARGAAS
    ((K_NIL, 0, 0, "Nil"),
     (K_MON, 10, 0, "As 10 HD monster"),
     (K_ONE, 7, 0, "7th level illusionist"),
     (K_DUAL, 16, 15,
      "16th level thief/15th level assassin"),
     (K_ONE, 10, 0, "10th level monk"),
     (2, 0, 0, "IV")),
    # ILNEVAL
    ((K_ONE, 8, 0, "8th level cleric"),
     (K_MON, 15, 0, "As 15 HD monster"),
     (K_NIL, 0, 0, "Nil"),
     (K_ONE, 14, 0, "14th level assassin"),
     (K_NIL, 0, 0, "Nil"),
     (3, 0, 0, "Nil")),
    # YURTRUS
    ((K_ONE, 15, 0,
      "15th level cleric (destructive"
      " spells only)"),
     (K_MON, 13, 0, "As 13 HD monster"),
     (K_SEE, 0, 0, "See below/Nil"),
     (K_ONE, 15, 0, "15th level assassin"),
     (K_NIL, 0, 0, "Nil"),
     (0, 0, 0, "VI")),
    # LUTHIC
    ((K_ONE, 15, 0, "15th level cleric"),
     (K_MON, 12, 0, "As 12 HD monster"),
     (K_EACH, 12, 0, "12th level in each"),
     (K_EACH, 6, 0, "6th level in each"),
     (K_NIL, 0, 0, "Nil"),
     (3, 0, 0, "Nil")),
]

FLDNAMES = ('cd', 'f', 'mu', 'ta', 'mb', 'psn')

if len(BLOCKS) != 23:
    raise SystemExit('the block count')

# the Nil census across the five
# class lines (psn excluded)
NILS = sum(
    1 for b in BLOCKS for e in b[:5]
    if e[0] == K_NIL)
if NILS != 29:
    raise SystemExit('the Nil census %d'
                     % NILS)


def entry_lines(e):
    k, a, b, read = e
    return E(
        '        { %d, %d, %d, "%s" },'
        % (k, a, b, read))


def block_lines(i):
    b = BLOCKS[i]
    out = ['        {  // %d' % i]
    for e in b:
        out.append(entry_lines(e))
    out.append('        },')
    return out


TABLE = []
for i in range(23):
    TABLE.extend(block_lines(i))

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R409 landed 2026-10-13:',
    '  commit bac456b (census 336,',
    '  preflight GREEN), the UA',
    '  Appendix S stat lines -',
    '  rules/uasstatlines.h (prefix',
    '  usl) - the 23',
    '  S/I/W/D/C/CH/CM rows, the',
    '  R153/R322 cross-checks live,',
    '  the Cyrrollalee plus pair the',
    '  recorded hole, the Bahgtru',
    '  damage divergence recorded. The',
    '  md5 diverged for the',
    '  seventeenth round running -',
    '  benign; the md5 stays'
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R409 landed 2026-10-13' in s:
    already.append('seed: the R409 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R409 record')
s = rd(SD)
if s.count('R409 landed 2026-10-13') != 1:
    die('the R409 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uasclasslines.h =========
CL = 'rules/uasclasslines.h'

COMMENT = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uasclasslines.h',
    '// The UA APPENDIX S CLASS/LINES',
    '// (pp. 110-120), R410: the six',
    '// printed lines per deity block -',
    '// CLERIC/DRUID, FIGHTER,',
    '// MAGIC-USER/ILLUSIONIST,',
    '// THIEF/ASSASSIN, MONK/BARD and',
    '// PSIONIC ABILITY. The clean djvu',
    '// scan carries all 23 blocks; the',
    '// systematic OCR reads resolve',
    '// (the dropped slash in the Berronar',
    '// label, the "IOth"/"1 Oth"',
    '// letter-O reads, the "tighter"',
    '// fighter read, the label colon dot)',
    '// with the level-ladder sanity -',
    '// every printed level sits at 20 or',
    '// below.',
    '//',
    '// The PSIONIC ABILITY line pins',
    '// here as printed and cross-checks',
    '// the R406 rating codes LIVE: the',
    '// psn kind codes ARE the R406',
    '// rating codes (0 VI, 1 III, 2 IV,',
    '// 3 Nil) and the Brandobaris block',
    '// prints NO line - kind -1, the',
    '// recorded R406 unrecorded',
    '// sentinel.',
    '//',
    '// The kind codes: 0 Nil, 1 single',
    '// (a = the level), 2 dual (a, b),',
    '// 3 each (a), 4 special (a = the',
    '// second read level, 0 when the',
    '// second reads Nil), 5 monster (a',
    '// = the hit dice), 6 see below.')

HDR = E(
    COMMENT,
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The class-line kind codes.',
    'const int UASCL_NIL = 0;',
    'const int UASCL_SINGLE = 1;',
    'const int UASCL_DUAL = 2;',
    'const int UASCL_EACH = 3;',
    'const int UASCL_SPECIAL = 4;',
    'const int UASCL_MONSTER = 5;',
    'const int UASCL_SEEBELOW = 6;',
    '',
    '// The psionic kind codes - the',
    '// R406 rating codes by design.',
    'const int UASCL_PSN_VI = 0;',
    'const int UASCL_PSN_III = 1;',
    'const int UASCL_PSN_IV = 2;',
    'const int UASCL_PSN_NILRC = 3;',
    'const int UASCL_PSN_MISSING = -1;',
    '',
    '// One class/level line: the kind,',
    '// the numeric reads and the printed',
    '// read string (resolved OCR).',
    'struct UasClassLine {',
    '    int kind;',
    '    int a;',
    '    int b;',
    '    const char* read;',
    '};',
    '',
    '// The six lines of one block.',
    'struct UasClassLines {',
    '    UasClassLine cd, f, mu, ta, mb;',
    '    UasClassLine psn;',
    '};',
    '',
    '// The 23 blocks, in the R406',
    '// roster order.',
    'inline const UasClassLines&'
    ' uasclLines(int i) {',
    '    static const UasClassLines T[23]'
    ' = {',
    *TABLE,
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 22) i = 22;',
    '    return T[i];',
    '}',
    '',
    'inline int uasclBlockCount()',
    '    { return 23; }',
    '',
    '// The Nil census across the five',
    '// class lines (the psionic line',
    '// excluded): 29.',
    'inline int uasclNilCount() {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i) {',
    '        const UasClassLines& b =',
    '            uasclLines(i);',
    '        if (b.cd.kind == UASCL_NIL) ++n;',
    '        if (b.f.kind == UASCL_NIL) ++n;',
    '        if (b.mu.kind == UASCL_NIL) ++n;',
    '        if (b.ta.kind == UASCL_NIL) ++n;',
    '        if (b.mb.kind == UASCL_NIL) ++n;',
    '    }',
    '    return n;',
    '}',
    '',
    '// The psionic census (the R406',
    '// rating census re-derived from',
    '// the printed lines): VI 10,',
    '// III 5, IV 1, Nil 6, missing 1.',
    'inline int uasclPsnCount(int code) {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        if (uasclLines(i).psn.kind'
    ' == code) ++n;',
    '    return n;',
    '}',
    '',
    '}   // namespace rules',
    '')

newfile(CL, HDR + NL,
        'the Appendix S class lines header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uasstatlines.h"  '
     '// R409: the UA Appendix S stat'
     ' lines',
     E(
    '#include "rules/uasstatlines.h"  '
    '// R409: the UA Appendix S stat'
    ' lines',
    '#include "rules/uasclasslines.h"  '
    '// R410: the UA Appendix S class'
    ' lines'),
     'regtest: the class lines include')


def cell_cond(i, fld, e, label):
    k, a, b, read = e
    parts = ['        if (uasclLines(%d)'
             '.%s.kind != %d' % (i, fld, k)]
    if k in (K_ONE, K_EACH, K_SPEC,
             K_MON):
        parts.append(
            '                || uasclLines'
            '(%d).%s.a != %d' % (i, fld, a))
    if k == K_DUAL:
        parts.append(
            '                || uasclLines'
            '(%d).%s.a != %d' % (i, fld, a))
        parts.append(
            '                || uasclLines'
            '(%d).%s.b != %d' % (i, fld, b))
    if k != K_NIL:
        parts.append(
            '                || strcmp'
            '(uasclLines(%d).%s.read,'
            % (i, fld))
        parts.append(
            '                   "%s") != 0)'
            % read)
    parts[-1] += ' ++bad;'
    return NL.join(parts)


# the spot pins: the duals, the
# monster reads, the each-rows,
# the OCR resolutions, the
# sentinels
SPOTS = [
    (0, 'cd', BLOCKS[0][0]),
    (2, 'cd', BLOCKS[2][0]),
    (2, 'mu', BLOCKS[2][2]),
    (3, 'ta', BLOCKS[3][3]),
    (4, 'cd', BLOCKS[4][0]),
    (5, 'f', BLOCKS[5][1]),
    (5, 'mu', BLOCKS[5][2]),
    (8, 'cd', BLOCKS[8][0]),
    (8, 'mu', BLOCKS[8][2]),
    (9, 'mu', BLOCKS[9][2]),
    (12, 'f', BLOCKS[12][1]),
    (12, 'mu', BLOCKS[12][2]),
    (15, 'f', BLOCKS[15][1]),
    (16, 'mu', BLOCKS[16][2]),
    (17, 'cd', BLOCKS[17][0]),
    (18, 'f', BLOCKS[18][1]),
    (19, 'f', BLOCKS[19][1]),
    (19, 'ta', BLOCKS[19][3]),
    (20, 'f', BLOCKS[20][1]),
    (21, 'cd', BLOCKS[21][0]),
    (21, 'mu', BLOCKS[21][2]),
    (22, 'mu', BLOCKS[22][2]),
    (22, 'ta', BLOCKS[22][3]),
]

PSN_LIT = {0: '"VI"', 1: '"III"',
           2: '"IV"', 3: '"Nil"',
           -1: '"none"'}


def psn_cond(i):
    k, a, b, read = BLOCKS[i][5]
    lit = PSN_LIT[k]
    return E(
        '        if (strcmp(uasclLines(%d)'
        '.psn.read,' % i,
        '                   %s) != 0' % lit,
        '                || uasclLines(%d)'
        '.psn.kind != %d' % (i, k),
        '                || uasStat(%d)'
        '.rating != %d) ++bad;' % (i, k))

AUD = E(
    '    // ---- R410: the UA Appendix S',
    '    // class lines pin audit ----',
    '    // The 23 blocks x 6 lines pin;',
    '    // the Nil census counts (29);',
    '    // the psionic census re-derives',
    '    // the R406 rating census; all',
    '    // 23 psionic lines cross-check',
    '    // the R406 rating codes live',
    '    // (the Brandobaris missing line',
    '    // the recorded sentinel); census',
    '    // 336 -> 337.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (uasclBlockCount() != 23)',
    '            ++bad;',
    '        if (uasclNilCount() != 29) ++bad;',
    '        if (uasclPsnCount(UASCL_PSN_VI)'
    ' != 10',
    '                || uasclPsnCount'
    '(UASCL_PSN_III) != 5',
    '                || uasclPsnCount'
    '(UASCL_PSN_IV) != 1',
    '                || uasclPsnCount'
    '(UASCL_PSN_NILRC) != 6',
    '                || uasclPsnCount'
    '(UASCL_PSN_MISSING) != 1) ++bad;')

for i, fld, e in SPOTS:
    AUD += NL + cell_cond(i, fld, e,
                          'spot')

AUD += NL + E(
    '        // ---- the psionic',
    '        // cross-checks (R406 live) ----')

for i in range(23):
    AUD += NL + psn_cond(i)

AUD += NL + E(
    '        printf("R410 UA appendix S'
    ' class lines pin audit: bad %d'
    + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R410 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
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
    E(
    '      - AMENDED R409: the stat lines',
    '        land (rules/uasstatlines.h) -',
    '        the 23 S/I/W/D/C/CH/CM rows',
    '        pin with the R153/R322',
    '        cross-checks live, the',
    '        Cyrrollalee plus pair the',
    '        recorded hole, the Bahgtru',
    '        damage divergence recorded;',
    '        the class lines, MOVE and the',
    '        pantheon prose stay open.',
    '      - AMENDED R410: the class',
    '        lines land (rules/',
    '        uasclasslines.h) - the six',
    '        printed lines per block pin',
    '        with the psionic lines',
    '        cross-checking the R406',
    '        rating codes live (the',
    '        Brandobaris missing line the',
    '        recorded sentinel); MOVE and',
    '        the pantheon prose stay open.'),
    'gap: the Appendix S box takes R410')

pair(GP, E(
    '  - AMENDED R409: the stat lines',
    '    land (rules/uasstatlines.h) - the',
    '    class lines, MOVE and the',
    '    pantheon prose stay open.'),
    E(
    '  - AMENDED R409: the stat lines',
    '    land (rules/uasstatlines.h) - the',
    '    class lines, MOVE and the',
    '    pantheon prose stay open.',
    '  - AMENDED R410: the class lines',
    '    land (rules/uasclasslines.h) -',
    '    MOVE and the pantheon prose',
    '    stay open.'),
    'gap: the section tail takes R410')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 337:
    die('the census %d' % s.count('audit: bad'))
if s.count('R410 UA appendix S class'
           ' lines pin audit') != 1:
    die('the R410 audit label')
if s.count('uasclLines') < 100:
    die('the uasclLines call count %d'
        % s.count('uasclLines'))

p = rd(CL)
if p.count('inline') != 4:
    die('the class lines inline count %d'
        % p.count('inline'))
if not p.endswith(NL):
    die('the class lines trailing newline')

g = rd(GP)
if g.count('AMENDED R410') != 2:
    die('the gap amended count %d'
        % g.count('AMENDED R410'))

for path, mark in (
        (CL, 'uasclPsnCount'),
        (RT, 'uasclNilCount'),
        (SD, 'R409 landed')):
    if mark not in rd(path):
        die('%s carries no R410 round' % path)

# the contract: no engine caller
import re as _re
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\\buascl', rd(path)):
        die('%s calls the pins early'
            % path)

print('R410 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the Appendix S class lines')
print('  pin - the 23 blocks x 6 lines,')
print('  the Nil census 29, the psionic')
print('  census re-derives the R406')
print('  rating census and all 23 lines')
print('  cross-check the R406 rating')
print('  codes live; the Brandobaris')
print('  missing line the recorded')
print('  sentinel; MOVE and the pantheon')
print('  prose stay open; census 336 ->')
print('  337')
print('commit: R410: the UA Appendix S'
      ' class lines (census 337)')

