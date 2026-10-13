#!/usr/bin/env python3
# R411: the UA Appendix S MOVE
# values - the 23 deity
# block movement rates (pp.
# 110-120) pin, the fifth
# data round riding the R406
# stat-block precedent and
# the LAST numeric remainder
# in Appendix S (the
# pantheon prose alone stays
# open after this round). The
# clean djvu scan carries all
# 23 lines; the systematic
# OCR reads resolve (the
# label colon dot, the quote
# forms rendering as
# apostrophes, back-ticks and
# dashes - MOVE: 12', 18',
# 12-, 6" - all read the
# printed inch mark; the
# parentheticals 48/24/36/
# 36/12 are all multiples of
# 12). The Shargaas line
# garbles ("MOVE: 78-") with
# NO independent
# confirmation - it records
# as the hole sentinel, never
# a guess.
#
# 1. rules/uamoves.h (NEW,
#    prefix umv, 6 inline
#    functions): the 23 base
#    rates, the 5 parenthetical
#    alternates (Dumathoin 48,
#    Sheela 24, Urdlen 36,
#    Segojan 36, Luthic 12),
#    the Aerdrie flight-only
#    flag, the Shargaas hole
#    sentinel, the sanity
#    ladders (every clean base
#    a multiple of 3; every
#    alternate a multiple of
#    12).
# 2. regtest.cpp: the
#    include rides the R410
#    include; the R411 audit
#    lands before the R227
#    anchor - all 23 base
#    cells and the 5
#    alternates pin, the
#    flight-only flag pins,
#    the hole sentinel pins,
#    the sanity ladders run
#    live; census 337 -> 338.
# 3. tools/ua_gap_report.md:
#    the Appendix S box and
#    the section tail take
#    AMENDED R411 notes - the
#    MOVE values land, the
#    pantheon prose alone
#    stays open.
# 4. The seed takes the R410
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
        'R411 splice ABORT: ' + msg)


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
# (base, alt, flight-only); base -1 =
# the Shargaas hole; alt 0 = the line
# prints no parenthetical.
ROWS = [
    (12, 0, False),   # CLANGGEDIN
    (18, 0, False),   # VERGADAIN
    (9, 48, False),   # DUMATHOIN
    (12, 0, False),   # ABBATHOR
    (12, 0, False),   # BERRONAR
    (48, 0, True),    # AERDRIE
    (18, 0, False),   # EREVAN
    (15, 0, False),   # SOLONOR
    (12, 0, False),   # HANALI
    (12, 0, False),   # LABELAS
    (9, 24, False),   # SHEELA
    (12, 0, False),   # ARVOREEN
    (12, 0, False),   # CYRROLLALEE
    (12, 0, False),   # BRANDOBARIS
    (15, 0, False),   # BAERVAN
    (12, 36, False),  # URDLEN
    (9, 36, False),   # SEGOJAN
    (6, 0, False),    # FLANDAL
    (9, 0, False),    # BAHGTRU
    (-1, 0, False),   # SHARGAAS (hole)
    (12, 0, False),   # ILNEVAL
    (6, 0, False),    # YURTRUS
    (15, 12, False),  # LUTHIC
]

if len(ROWS) != 23:
    raise SystemExit('the row count')
ALT_N = sum(1 for r in ROWS if r[1])
HOLE_N = sum(1 for r in ROWS if r[0] == -1)
FLIGHT_N = sum(1 for r in ROWS if r[2])
BASE_SUM = sum(
    r[0] for r in ROWS if r[0] > 0)
if (ALT_N, HOLE_N, FLIGHT_N) != \
        (5, 1, 1):
    raise SystemExit('the census')

TABLE = []
for i, (b, a, fl) in enumerate(ROWS):
    TABLE.append(
        '        { %d, %d, %s },'
        % (b, a,
           'true' if fl else 'false'))

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R410 landed 2026-10-13:',
    '  commit e98c880 (census 337,',
    '  preflight GREEN), the UA',
    '  Appendix S class lines -',
    '  rules/uasclasslines.h (prefix',
    '  uascl) - the 23 blocks x 6',
    '  printed lines, the Nil',
    '  census 29, the psionic lines',
    '  cross-checking the R406',
    '  rating codes live (the',
    '  Brandobaris missing line the',
    '  recorded sentinel). The md5',
    '  diverged for the eighteenth',
    '  round running - benign; the',
    '  md5 stays advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R410 landed 2026-10-13' in s:
    already.append('seed: the R410 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R410 record')
s = rd(SD)
if s.count('R410 landed 2026-10-13') != 1:
    die('the R410 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uamoves.h =========
MV = 'rules/uamoves.h'

COMMENT = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uamoves.h',
    '// The UA APPENDIX S MOVE values',
    '// (pp. 110-120), R411: the 23',
    '// deity block movement rates -',
    '// the last numeric remainder in',
    '// Appendix S (the pantheon prose',
    '// alone stays open). The clean',
    '// djvu scan carries all 23 lines;',
    '// the systematic OCR reads',
    '// resolve: the label colon dot',
    '// ("MOVE;" reads "MOVE:"), the',
    '// quote forms rendering as',
    '// apostrophes, back-ticks and',
    '// dashes (MOVE: 12\', 18\', 12-',
    '// all read the printed inch',
    '// mark; the parentheticals',
    '// 48/24/36/36/12 are all',
    '// multiples of 12.',
    '//',
    '// The hole: the Shargaas line',
    '// garbles ("MOVE: 78-") with no',
    '// independent confirmation - the',
    '// value records as the hole',
    '// sentinel, never a guess.',
    '//',
    '// The sanity ladders: every',
    '// clean base is a multiple of 3;',
    '// every printed alternate is a',
    '// multiple of 12.')

HDR = E(
    COMMENT,
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The Shargaas hole sentinel.',
    'const int UMV_MOVE_HOLE = -1;',
    '',
    '// One MOVE line: the base rate,',
    '// the parenthetical alternate (0',
    '// = the line prints no',
    '// parenthetical) and the',
    '// flight-only flag.',
    'struct UmvMove {',
    '    int base;',
    '    int alt;',
    '    bool flightOnly;',
    '};',
    '',
    '// The 23 MOVE lines, in the R406',
    '// roster order.',
    'inline const UmvMove& umvMove(int i) {',
    '    static const UmvMove T[23] = {',
    *TABLE,
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 22) i = 22;',
    '    return T[i];',
    '}',
    '',
    'inline int umvMoveCount()',
    '    { return 23; }',
    '',
    '// The alternate census (the lines',
    '// printing a parenthetical): 5 -',
    '// Dumathoin 48, Sheela 24,',
    '// Urdlen 36, Segojan 36,',
    '// Luthic 12.',
    'inline int umvAltCount() {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        if (umvMove(i).alt > 0) ++n;',
    '    return n;',
    '}',
    '',
    '// The base sum over the clean',
    '// rows (the hole excluded): a',
    '// drift in ANY clean base cell',
    '// moves it.',
    'inline int umvBaseSum() {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i) {',
    '        const UmvMove& m = umvMove(i);',
    '        if (m.base != UMV_MOVE_HOLE)',
    '            n += m.base;',
    '    }',
    '    return n;',
    '}',
    '',
    '// True when every clean base is a',
    '// multiple of 3 (the sanity',
    '// ladder; the hole excluded).',
    'inline bool umvBasesAreMultiplesOf3() {',
    '    for (int i = 0; i < 23; ++i) {',
    '        const UmvMove& m = umvMove(i);',
    '        if (m.base == UMV_MOVE_HOLE)',
    '            continue;',
    '        if (m.base <= 0 || m.base % 3)',
    '            return false;',
    '    }',
    '    return true;',
    '}',
    '',
    '// True when every printed',
    '// alternate is a multiple of 12',
    '// (the sanity ladder).',
    'inline bool umvAltsAreMultiplesOf12() {',
    '    for (int i = 0; i < 23; ++i) {',
    '        const UmvMove& m = umvMove(i);',
    '        if (m.alt > 0 && m.alt % 12)',
    '            return false;',
    '    }',
    '    return true;',
    '}',
    '',
    '// The flight-only flag: the',
    '// Aerdrie 48 reads flight only.',
    'inline bool umvAerdrieFlightOnly()',
    '    { return umvMove(5).flightOnly;',
    '    }',
    '',
    '}   // namespace rules',
    '')

newfile(MV, HDR + NL,
        'the Appendix S MOVE header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uasclasslines.h"  '
     '// R410: the UA Appendix S class'
     ' lines',
     E(
    '#include "rules/uasclasslines.h"  '
    '// R410: the UA Appendix S class'
    ' lines',
    '#include "rules/uamoves.h"  '
    '// R411: the UA Appendix S MOVE'
    ' values'),
     'regtest: the MOVE include')


def cond(l, r):
    b, a, fl = r
    parts = [l % 'umvMove(%d).base != %d']
    return parts


AUD = E(
    '    // ---- R411: the UA Appendix S',
    '    // MOVE values pin audit ----',
    '    // The 23 movement rates pin;',
    '    // the five parenthetical',
    '    // alternates pin (Dumathoin',
    '    // 48, Sheela 24, Urdlen 36,',
    '    // Segojan 36, Luthic 12); the',
    '    // Aerdrie flight-only flag',
    '    // pins; the Shargaas garble',
    '    // records as the hole sentinel',
    '    // ("MOVE: 78-", no independent',
    '    // confirmation); the sanity',
    '    // ladders run live (every clean',
    '    // base a multiple of 3, every',
    '    // alternate a multiple of 12);',
    '    // the base sum catches a drift',
    '    // in ANY clean cell; census',
    '    // 337 -> 338.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (umvMoveCount() != 23)',
    '            ++bad;',
    '        if (umvAltCount() != 5) ++bad;',
    '        if (umvBaseSum() != %d) ++bad;'
    % BASE_SUM,
    '        if (!umvBasesAreMultiplesOf3())',
    '            ++bad;',
    '        if (!umvAltsAreMultiplesOf12())',
    '            ++bad;',
    '        if (!umvAerdrieFlightOnly())',
    '            ++bad;',
    '        // the flight flag rides the',
    '        // Aerdrie row ALONE',
    '        if (umvMove(0).flightOnly',
    '                || umvMove(2).flightOnly',
    '                || umvMove(14).flightOnly',
    '                || umvMove(19).flightOnly',
    '                || umvMove(22).flightOnly)',
    '            ++bad;',
    '        if (umvMove(19).base'
    ' != UMV_MOVE_HOLE) ++bad;')

for i, (b, a, fl) in enumerate(ROWS):
    if b == -1:
        continue
    AUD += NL + E(
        '        if (umvMove(%d).base'
        ' != %d' % (i, b),
        '                || umvMove(%d)'
        '.alt != %d) ++bad;' % (i, a))

AUD += NL + E(
    '        printf("R411 UA appendix S'
    ' MOVE values pin audit: bad %d'
    + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R411 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
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
    E(
    '      - AMENDED R410: the class',
    '        lines land (rules/',
    '        uasclasslines.h) - the six',
    '        printed lines per block pin',
    '        with the psionic lines',
    '        cross-checking the R406',
    '        rating codes live (the',
    '        Brandobaris missing line the',
    '        recorded sentinel); MOVE and',
    '        the pantheon prose stay open.',
    '      - AMENDED R411: the MOVE',
    '        values land (rules/uamoves.h)',
    '        - the 23 rates and the five',
    '        alternates pin with the',
    '        sanity ladders live; the',
    '        Shargaas garble records as',
    '        the hole sentinel; the',
    '        pantheon prose ALONE stays',
    '        open in Appendix S.'),
    'gap: the Appendix S box takes R411')

pair(GP, E(
    '  - AMENDED R410: the class lines',
    '    land (rules/uasclasslines.h) -',
    '    MOVE and the pantheon prose',
    '    stay open.'),
    E(
    '  - AMENDED R410: the class lines',
    '    land (rules/uasclasslines.h) -',
    '    MOVE and the pantheon prose',
    '    stay open.',
    '  - AMENDED R411: the MOVE values',
    '    land (rules/uamoves.h) - the',
    '    pantheon prose alone stays',
    '    open.'),
    'gap: the section tail takes R411')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 338:
    die('the census %d' % s.count('audit: bad'))
if s.count('R411 UA appendix S MOVE'
           ' values pin audit') != 1:
    die('the R411 audit label')
if s.count('umvMove') < 40:
    die('the umvMove call count %d'
        % s.count('umvMove'))

p = rd(MV)
if p.count("inline") != 7:
    die('the MOVE inline count %d'
        % p.count('inline'))
if not p.endswith(NL):
    die('the MOVE trailing newline')

g = rd(GP)
if g.count('AMENDED R411') != 2:
    die('the gap amended count %d'
        % g.count('AMENDED R411'))

for path, mark in (
        (MV, 'umvAltCount'),
        (RT, 'umvBaseSum'),
        (SD, 'R410 landed')):
    if mark not in rd(path):
        die('%s carries no R411 round' % path)

# the contract: no engine caller
import re as _re
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bumv', rd(path)):
        die('%s calls the pins early'
            % path)

print('R411 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the Appendix S MOVE values')
print('  pin - the 23 rates, the five')
print('  alternates, the Aerdrie')
print('  flight-only flag; the Shargaas')
print('  garble records as the hole')
print('  sentinel; the sanity ladders run')
print('  live; the pantheon prose ALONE')
print('  stays open in Appendix S; census')
print('  337 -> 338')
print('commit: R411: the UA Appendix S'
      ' MOVE values (census 338)')

