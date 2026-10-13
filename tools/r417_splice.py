# R417: the UA HAUNTING-SOUND
# CANTRIP DESCRIPTIONS
# (pp. 50-51) - the LAST of
# the six MU cantrip
# description rounds; the
# R363/R412/R413/R414/R415/
# R416 precedents ride (the
# descriptions pin; the
# casting-time fraction cells
# garble in the scan and
# record as holes pending the
# PDF read). The clean djvu
# scan carries all 8
# haunting-sound blocks in
# roster order (Creak,
# Footfall, Groan, Moan,
# Rattle, Tap, Thump,
# Whistle); the school tags
# print clean - NO new school
# codes this round (Evocation
# 3: Creak, Tap, Whistle;
# Illusion 5: Footfall,
# Groan, Moan, Rattle,
# Thump; both ride existing
# codes). The area lines
# print clean for ALL 8
# blocks - ZERO area holes:
# the Special seven and the
# Tap 1 sq. ft. (a NEW area
# kind code). ALL 8
# casting-time cells garble -
# the whole family records as
# holes. The range family:
# five blocks print the
# numerals clean (the near 1,
# the footfall far 2) but the
# foot/inch glyphs garble -
# the numerals pin, the unit
# family records as holes;
# the creak traverse prints
# an ambiguous "1 0" - the
# value records as a hole
# (never a guess); the
# whistle pair prints CLEAN -
# the faint 10 feet and the
# loud 30 feet pin with the
# loud == faint*3 derivation.
# The mechanics pin clean:
# the creak latter half
# segment (the former 1/3
# garbles - a hole), the
# moan two flavors, the
# rattle 2 seconds, the tap
# once/twice/thrice 1..3
# band, the whistle pair.

# 1. rules/uacantrips6.h (NEW,
#    prefix uch - verified no
#    collision): the 8
#    haunting-sound cantrips in
#    R341/R401 roster order, the
#    struct + 17 inline
#    functions.
# 2. regtest.cpp: the include
#    rides the R416 include;
#    the R417 audit block lands
#    before the R227 anchor -
#    the 8 names cross-check
#    the R341/R401 roster
#    (uastCantripName(5, i))
#    live name for name, the
#    count cross-checks
#    uastCantripCount(5), the
#    schools/areas pin per
#    row, the censuses count,
#    the mechanics pin with
#    the band derivations
#    cross-checking
#    themselves; census
#    343 -> 344.
# 3. tools/ua_gap_report.md:
#    the MU cantrips box takes
#    AMENDED R417 - the
#    haunting-sound
#    descriptions land; ALL
#    SIX description rounds
#    now stand - the item
#    stays open ONLY on the
#    recorded holes pending
#    the PDF read.
# 4. The seed takes the R416
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
        'R417 splice ABORT: ' + msg)


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
# schools: 0 Evocation, 4
# Illusion - both EXISTING
# codes (the R414/R415
# precedents); no NEW school
# codes this round.
# area kinds: 3 Special (the
# R412/R413 kind), 13 one
# square foot (NEW this
# round - the Tap block);
# -1 the hole sentinel (none
# this round).
S_EVO, S_ILL = 0, 4
A_HOLE = -1
A_SPECIAL = 3
A_SQFT = 13

# The 8 haunting-sound
# cantrips, in the R341/R401
# roster order: the name, the
# school, the area kind, the
# area value.
ROWS = [
    ('Creak', S_EVO, A_SPECIAL, 0),
    ('Footfall', S_ILL, A_SPECIAL, 0),
    ('Groan', S_ILL, A_SPECIAL, 0),
    ('Moan', S_ILL, A_SPECIAL, 0),
    ('Rattle', S_ILL, A_SPECIAL, 0),
    ('Tap', S_EVO, A_SQFT, 1),
    ('Thump', S_ILL, A_SPECIAL, 0),
    ('Whistle', S_EVO, A_SPECIAL, 0),
]

SCHOOL_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[1] == s)
    for s in (0, 1, 2, 3, 4, 5,
              6, 7))
AREA_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[2] == a)
    for a in (A_SPECIAL, A_SQFT,
              A_HOLE))

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R416 landed 2026-10-13:',
    '  commit 51da28c (census 343,',
    '  preflight GREEN), the UA',
    '  PERSONAL CANTRIP',
    '  DESCRIPTIONS (pp. 49-50) -',
    '  the fifth of the six MU',
    '  cantrip description rounds;',
    '  the precedents ride. rules/',
    '  uacantrips5.h (prefix uco):',
    '  the 10 personal cantrips in',
    '  roster order, the school',
    '  census 1/0/1/0/0/0/5/3',
    '  (Summoning and Conjuration',
    '  AS PRINTED, NEW school',
    '  codes; the scan\'s',
    '  "Flrefinger" resolves as',
    '  Firefinger via the live',
    '  roster), the areas pin',
    '  EIGHT clean with TWO area',
    '  holes (the bluelight sphere',
    '  and the firefinger line),',
    '  the spider poison read +',
    '  the band derivations, the',
    '  casting-time, range-unit and',
    '  slow-poison-defer families',
    '  the recorded holes pending',
    '  the PDF read. One pre-publish',
    '  catch: a comma between',
    '  adjacent string literals split',
    '  the accessor line - the',
    '  R412b class guard caught it.',
    '  First-try GREEN on the user',
    '  side. The md5 diverged for',
    '  the SEVENTEENTH round running',
    '  - benign; the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R416 landed 2026-10-13' in s:
    already.append('seed: the R416 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R416 record')
s = rd(SD)
if s.count('R416 landed 2026-10-13') != 1:
    die('the R416 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uacantrips6.h =========
UC = 'rules/uacantrips6.h'

HDR = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uacantrips6.h',
    '// The UA MAGIC-USER CANTRIP',
    '// DESCRIPTIONS, part 6 (R417):',
    '// the HAUNTING-SOUND category',
    '// (pp. 50-51), 8 cantrips - the',
    '// LAST of the six MU cantrip',
    '// description rounds. The',
    '// R363/R412/R413/R414/R415/R416',
    '// precedents ride: the',
    '// descriptions pin; the',
    '// casting-time fraction cells',
    '// garble in the scan (the',
    '// whole family) and record',
    '// as holes pending the PDF',
    '// read - never guesses.',
    '//',
    '// The school tags print clean:',
    '// NO new school codes this',
    '// round. The census: Evocation',
    '// 3 (Creak, Tap, Whistle),',
    '// Illusion 5 (Footfall, Groan,',
    '// Moan, Rattle, Thump).',
    '//',
    '// The area lines print clean',
    '// for ALL 8 blocks - ZERO area',
    '// holes: the Special seven and',
    '// the Tap 1 sq. ft. (a NEW area',
    '// kind code).',
    '//',
    '// The range family: five',
    '// blocks print the numerals',
    '// clean (the near 1, the',
    '// footfall far 2) but the',
    '// foot/inch glyphs garble -',
    '// the numerals pin, the unit',
    '// family records as holes',
    '// pending the PDF read. The',
    '// creak traverse prints an',
    '// ambiguous "1 0" - the value',
    '// records as a hole (never a',
    '// guess). The whistle pair',
    '// prints CLEAN: the faint 10',
    '// feet and the loud 30 feet pin',
    '// with the loud == faint*3',
    '// derivation.',
    '//',
    '// The mechanics pin clean: the',
    '// creak latter half segment',
    '// (the former 1/3 garbles - a',
    '// hole), the moan two flavors,',
    '// the rattle 2 seconds, the tap',
    '// once/twice/thrice 1..3 band,',
    '// and the whistle pair.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The school codes (NO new',
    '// codes this round; Evocation',
    '// and Illusion ride the',
    '// standing codes).',
    'const int UCH_EVO = 0;',
    'const int UCH_ILL = 4;',
    '',
    '// The area kind codes (the one',
    '// square foot NEW this round;',
    '// the Special rides the',
    '// R412/R413 kind).',
    'const int UCH_AREA_HOLE = -1;',
    'const int UCH_AREA_SPECIAL = 3;',
    'const int UCH_AREA_SQFT = 13;',
    '',
    '// One haunting-sound cantrip:',
    '// the name, the school, the',
    '// area kind and the area value',
    '// (0 when the kind carries no',
    '// number).',
    'struct UchCantrip {',
    '    const char* name;',
    '    int school;',
    '    int areaKind;',
    '    int areaVal;',
    '};',
    '',
    '// The 8 haunting-sound',
    '// cantrips, in the R341/R401',
    '// roster order.',
    'inline const UchCantrip&'
    ' uchHauntingSound(int i) {',
    '    static const UchCantrip'
    ' T[8] = {')

for nm, sc, ak, av in ROWS:
    HDR += NL + E(
        '        { "%s", %d, %d, %d },'
        % (nm, sc, ak, av))

HDR += NL + E(
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 7) i = 7;',
    '    return T[i];',
    '}',
    '',
    '// The count.',
    'inline int uchHauntingSoundCount()',
    '    { return 8; }',
    '',
    '// The school census helper.',
    'inline int uchSchoolCount(int s)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 8; ++i)',
    '        if (uchHauntingSound(i)'
    '.school == s)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The area kind census helper.',
    'inline int uchAreaKindCount(int a)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 8; ++i)',
    '        if (uchHauntingSound(i)'
    '.areaKind == a)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The casting-time hole family:',
    '// ALL 8 casting-time cells print',
    '// fraction garbles in the scan -',
    '// the whole family records as',
    '// holes pending the PDF read (the',
    '// R363/R412/R413/R414/R415/R416',
    '// posture).',
    'inline bool uchCastTimesAreHoles()',
    '    { return true; }',
    '',
    '// The range unit hole family:',
    '// five blocks print the numerals',
    '// clean but the foot/inch',
    '// glyphs garble - the numerals',
    '// pin, the unit family records',
    '// as holes pending the PDF',
    '// read.',
    'inline bool uchRangeUnitsAreHoles()',
    '    { return true; }',
    '',
    '// The near range numeral (the',
    '// groan, rattle, tap and thump',
    '// blocks all print 1).',
    'inline int uchRangeNearVal()',
    '    { return 1; }',
    '',
    '// The footfall far numeral (the',
    '// footfalls may move away up to',
    '// 2).',
    'inline int uchFootfallFarVal()',
    '    { return 2; }',
    '',
    '// ---- the mechanics pins ----',
    '',
    '// The creak read: the former',
    '// sound (corroded-hinge door)',
    '// prints a garbled 1/3 segment -',
    '// a hole; the latter noise',
    '// (squeaking floorboards) lasts',
    '// half a segment (in halves).',
    'inline bool uchCreakFormerIsHole()',
    '    { return true; }',
    '',
    'inline int uchCreakLatterHalfSegs()',
    '    { return 1; }',
    '',
    '// The creak traverse: the scan',
    '// prints an ambiguous "1 0" for',
    '// the traversal distance - the',
    '// value records as a hole',
    '// pending the PDF read (never a',
    '// guess).',
    'inline bool uchCreakTraverseIsHole()',
    '    { return true; }',
    '',
    '// The moan read: the sound is',
    '// either a low-pitched haunting',
    '// moan or a high-pitched',
    '// pitiful one - two flavors.',
    'inline int uchMoanFlavors()',
    '    { return 2; }',
    '',
    '// The rattle read: the chain',
    '// rattle lasts for up to 2',
    '// seconds.',
    'inline int uchRattleSeconds()',
    '    { return 2; }',
    '',
    '// The tap read: the sound occurs',
    '// once, twice, or thrice,',
    '// according to the number of',
    '// fingers extended by the',
    '// caster.',
    'inline int uchTapCountMin()',
    '    { return 1; }',
    '',
    'inline int uchTapCountMax()',
    '    { return 3; }',
    '',
    '// The whistle read: a faint',
    '// whistling can be heard within',
    '// 10 feet, a loud one within 30',
    '// feet (the pair prints clean).',
    'inline int uchWhistleFaintFeet()',
    '    { return 10; }',
    '',
    'inline int uchWhistleLoudFeet()',
    '    { return 30; }',
    '',
    '}   // namespace rules',
    '')

newfile(UC, HDR + NL,
        'the haunting-sound'
        ' cantrips header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uacantrips5.h"  '
     '// R416: the UA personal'
     ' cantrips',
     E(
    '#include "rules/uacantrips5.h"  '
    '// R416: the UA personal'
    ' cantrips',
    '#include "rules/uacantrips6.h"  '
    '// R417: the UA haunting-'
    'sound cantrips'),
     'regtest: the haunting-sound'
     ' cantrips include')

AUD = E(
    '    // ---- R417: the UA',
    '    // haunting-sound cantrips',
    '    // pin audit ----',
    '    // The 8 haunting-sound',
    '    // descriptions pin - the LAST',
    '    // of the six description',
    '    // rounds: the names cross-',
    '    // check the R341/R401 roster',
    '    // live, the schools pin per',
    '    // row (NO new codes - the',
    '    // Evocation 3 / Illusion 5',
    '    // census), the areas pin per',
    '    // row (ZERO area holes - the',
    '    // Special seven and the Tap',
    '    // one square foot, a NEW area',
    '    // kind), the censuses count,',
    '    // the mechanics pin with the',
    '    // band derivations cross-',
    '    // checking themselves (the',
    '    // whistle loud == faint*3);',
    '    // census 343 -> 344.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (uchHauntingSoundCount()'
    ' != 8)',
    '            ++bad;',
    '        if (uastCantripCount(5) != 8)',
    '            ++bad;',
    '        // ---- the school census ----',
    '        if (uchSchoolCount(UCH_EVO)'
    ' != 3',
    '                || uchSchoolCount'
    '(UCH_ILL) != 5',
    '                || uchSchoolCount'
    '(1) != 0',
    '                || uchSchoolCount'
    '(2) != 0',
    '                || uchSchoolCount'
    '(3) != 0',
    '                || uchSchoolCount'
    '(5) != 0',
    '                || uchSchoolCount'
    '(6) != 0',
    '                || uchSchoolCount'
    '(7) != 0) ++bad;',
    '        // ---- the area census ----',
    '        if (uchAreaKindCount'
    '(UCH_AREA_SPECIAL) != 7',
    '                || uchAreaKindCount'
    '(UCH_AREA_SQFT) != 1',
    '                || uchAreaKindCount'
    '(UCH_AREA_HOLE) != 0) ++bad;')

# the per-row pins: name (cross-
# checked against the R341/R401
# roster live), school, area
for i, (nm, sc, ak, av) in \
        enumerate(ROWS):
    AUD += NL + E(
        '        if (strcmp'
        '(uchHauntingSound(%d)'
        '.name,' % i,
        '                   '
        'uastCantripName(5, %d)) != 0'
        % i,
        '                ||'
        ' uchHauntingSound(%d)' % i,
        '                   .school'
        ' != %d' % sc,
        '                ||'
        ' uchHauntingSound(%d)' % i,
        '                   .areaKind'
        ' != %d' % ak,
        '                ||'
        ' uchHauntingSound(%d)' % i,
        '                   .areaVal'
        ' != %d) ++bad;' % av)

AUD += NL + E(
    '        // ---- the hole families ----',
    '        if (!uchCastTimesAreHoles()',
    '                || !uchRangeUnits'
    'AreHoles()',
    '                || !uchCreakFormer'
    'IsHole()',
    '                || !uchCreakTraverse'
    'IsHole())',
    '            ++bad;',
    '        // ---- the mechanics ----',
    '        if (uchRangeNearVal() != 1',
    '                || uchFootfall'
    'FarVal() != 2',
    '                || uchMoanFlavors()'
    ' != 2',
    '                || uchRattleSeconds()'
    ' != 2) ++bad;',
    '        if (uchCreakLatterHalfSegs()'
    ' != 1',
    '                || uchTapCountMin()'
    ' != 1',
    '                || uchTapCountMax()'
    ' != 3) ++bad;',
    '        if (uchWhistleFaintFeet()'
    ' != 10',
    '                || uchWhistle'
    'LoudFeet() != 30) ++bad;',
    '        // The band derivations: the',
    '        // tap once/twice/thrice opens',
    '        // below its close and the',
    '        // whistle loud radius rides',
    '        // three times the faint one',
    '        // - both cross-check by',
    '        // derivation (quiet on the',
    '        // healthy values - the R391',
    '        // lesson).',
    '        if (uchTapCountMin()',
    '                >= uchTapCountMax()',
    '                || uchWhistleLoudFeet()',
    '                   != uchWhistle'
    'FaintFeet() * 3) ++bad;',
    '        printf("R417 UA haunting-'
    'sound cantrips pin'
    ' audit: bad %d'
    + chr(92) + 'n\", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R417 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

GP_R417 = E(
    '      - AMENDED R417: the',
    '        haunting-sound',
    '        descriptions land (rules/',
    '        uacantrips6.h) - the 8',
    '        blocks pin schools (the',
    '        3/0/0/0/5/0/0/0 census -',
    '        NO new school codes; both',
    '        ride the standing codes),',
    '        ALL 8 areas clean (ZERO',
    '        area holes - the Special',
    '        seven and the Tap 1 sq. ft.,',
    '        a NEW area kind), the whole',
    '        casting-time family the',
    '        recorded holes, the range',
    '        unit family the recorded',
    '        holes (the near 1 and the',
    '        footfall far 2 numerals',
    '        pin), the creak traverse',
    '        an ambiguous garble',
    '        recorded as a hole, the',
    '        mechanics pin (the creak',
    '        latter half segment - the',
    '        former 1/3 a garbled hole;',
    '        the moan two flavors, the',
    '        rattle 2 seconds, the tap',
    '        once/twice/thrice 1..3',
    '        band, and the WHISTLE PAIR',
    '        - the faint 10 feet and the',
    '        loud 30 feet printing clean,',
    '        the loud == faint*3',
    '        derivation cross-checking',
    '        itself). ALL SIX MU cantrip',
    '        description rounds now',
    '        stand; the item stays open',
    '        ONLY on the recorded holes',
    '        pending the PDF read.',
    '    ')

GP_R416 = E(
    '      - AMENDED R416: the',
    '        personal descriptions land',
    '        (rules/uacantrips5.h) - the',
    '        10 blocks pin schools (the',
    '        1/0/1/0/0/0/5/3 census -',
    '        Summoning and Conjuration',
    '        AS PRINTED, NEW school',
    '        codes; the scan\'s',
    '        "Flrefinger" resolves as',
    '        Firefinger via the live',
    '        roster), the areas pin',
    '        EIGHT clean (the one',
    '        summoned animal four, the',
    '        Gnats cubic foot, the',
    '        Smokepuff 1-foot cloud, the',
    '        Tweak creature, the Unlock',
    '        lock - NEW area kinds; the',
    '        Bluelight sphere and the',
    '        Firefinger line record as',
    '        the TWO area holes pending',
    '        the PDF read), the whole',
    '        casting-time family the',
    '        recorded holes, the range',
    '        unit family the recorded',
    '        holes (the numeral 1 pins),',
    '        the mechanics pin (the bee',
    '        90% sting, the bluelight',
    '        3-inch sphere + 5-foot',
    '        radius, the firefinger',
    '        one-half-foot jet + segment,',
    '        the gnats 1-4 segment',
    '        distraction, the smokepuff',
    '        six colors, the SPIDER',
    '        POISON READ - the 5% venom',
    '        chance, the 1-2 inch size,',
    '        the 1-segment bite, the +4',
    '        save, the 1/2 damage pair,',
    '        the 1-4 day sickness, the',
    '        slow-poison defer a garbled',
    '        numeral recorded as a hole',
    '        - and the tweak seven',
    '        portions + 1-segment',
    '        distraction + INT 7',
    '        threshold + 3d6, the band',
    '        derivations cross-checking',
    '        themselves); only the',
    '        haunting-sound descriptions',
    '        stay open.',
    )

GP_R416X = E(
    '      - AMENDED R416: the',
    '        personal descriptions land',
    '        (rules/uacantrips5.h) - the',
    '        10 blocks pin schools (the',
    '        1/0/1/0/0/0/5/3 census -',
    '        Summoning and Conjuration',
    '        AS PRINTED, NEW school',
    '        codes; the scan\'s',
    '        "Flrefinger" resolves as',
    '        Firefinger via the live',
    '        roster), the areas pin',
    '        EIGHT clean (the one',
    '        summoned animal four, the',
    '        Gnats cubic foot, the',
    '        Smokepuff 1-foot cloud, the',
    '        Tweak creature, the Unlock',
    '        lock - NEW area kinds; the',
    '        Bluelight sphere and the',
    '        Firefinger line record as',
    '        the TWO area holes pending',
    '        the PDF read), the whole',
    '        casting-time family the',
    '        recorded holes, the range',
    '        unit family the recorded',
    '        holes (the numeral 1 pins),',
    '        the mechanics pin (the bee',
    '        90% sting, the bluelight',
    '        3-inch sphere + 5-foot',
    '        radius, the firefinger',
    '        one-half-foot jet + segment,',
    '        the gnats 1-4 segment',
    '        distraction, the smokepuff',
    '        six colors, the SPIDER',
    '        POISON READ - the 5% venom',
    '        chance, the 1-2 inch size,',
    '        the 1-segment bite, the +4',
    '        save, the 1/2 damage pair,',
    '        the 1-4 day sickness, the',
    '        slow-poison defer a garbled',
    '        numeral recorded as a hole',
    '        - and the tweak seven',
    '        portions + 1-segment',
    '        distraction + INT 7',
    '        threshold + 3d6, the band',
    '        derivations cross-checking',
    '        themselves); only the',
    '        haunting-sound descriptions',
    '        stay open.',
    )

pair(GP, GP_R416, GP_R417 + GP_R416X,
     'gap: the MU cantrips box takes'
     ' R417')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 344:
    die('the census %d' % s.count('audit: bad'))
if s.count('R417 UA haunting-'
           'sound cantrips pin'
           ' audit') != 1:
    die('the R417 audit label')
if s.count('uchHauntingSound') != \
        4 * len(ROWS) + 1:
    die('the uchHauntingSound call'
        ' count %d'
        % s.count('uchHauntingSound'))

# the R412b resolution guard:
# every uch symbol the audit
# calls must be defined in the
# emitted header.
_used = set(_re.findall(r'\buch\w+', s))
_def = set(_re.findall(r'\buch\w+',
                       rd(UC)))
if _used - _def:
    die('undefined uch calls %s'
        % sorted(_used - _def))

p = rd(UC)
if p.count('inline') != 17:
    die('the haunting-sound cantrips'
        ' inline count %d'
        % p.count('inline'))
if not p.endswith(NL):
    die('the haunting-sound cantrips'
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
if g.count('AMENDED R417') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R417'))

for path, mark in (
        (UC, 'uchWhistleLoudFeet'),
        (RT, 'uchHauntingSoundCount'),
        (SD, 'R416 landed')):
    if mark not in rd(path):
        die('%s carries no R417 round' % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\buch', rd(path)):
        die('%s calls the pins early'
            % path)

print('R417 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the haunting-sound')
print('  cantrip descriptions pin -')
print('  the 8 blocks, the names')
print('  cross-check the R341/R401')
print('  roster live, the school')
print('  census 3/0/0/0/5 (no new')
print('  codes), ALL 8 areas clean')
print('  (the Special seven + the')
print('  Tap square foot, new), the')
print('  whistle pair pins clean')
print('  (faint 10, loud 30, the')
print('  loud == faint*3 derivation),')
print('  the tap 1..3 band, the')
print('  casting-time and range-unit')
print('  families the recorded holes')
print('  pending the PDF read;')
print('  census 343 -> 344')
print('commit: R417: the UA haunting-'
      'sound cantrips'
      ' (census 344)')

