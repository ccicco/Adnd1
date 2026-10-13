#!/usr/bin/env python3
# R421: the IL CANTRIP CAST-TIMES
# RESOLUTION - the PDF read
# completes the illusionist
# cantrips. The clean book pp.
# 65-66 print gives every cell:
# the eight casting-time cells
# resolve (colored lights, dim,
# haze and mirage at 1/2 segment;
# rainbow at 1/3; mask, noise and
# the two-d-lusion at 1/8 - the
# census 4/1/3, every denominator
# inside the 2..10 band the p. 45
# header prints), the mirage and
# two-d-lusion school cells print
# (Illusion), the areas pin (the
# mirage 2 sq. inches, the
# two-d-lusion 4 sq. inches), the
# mirage somatic tail reads clean
# (a word or two then a single
# pass, kept by concentration
# alone), the colored-lights
# reflection sentence pins
# (reflections beyond 1 inch,
# detection beyond 3 inches), and
# the haze area decode is
# confirmed (the print reads 1"
# cube clean). The clean p. 31
# read ALSO resolves the R342 IL
# cantrip column (the eight
# names, cross-checking the
# description roster row for
# row). The IL cantrip
# descriptions now stand
# hole-free; the gap-report box
# flips in the SAME commit (the
# R420 convention lesson).
#
# 1. rules/uailcantrips.h: the
#    hole flags amend away; the
#    casting-time family lands
#    (uailcCastTimeDen over a
#    D[8] array + the DenCount
#    census helper); the resolved
#    reads pin.
# 2. rules/uaspelltables2.h:
#    uas2IlCantripListLost amends
#    to the resolved roster
#    (uas2IlCantripCount +
#    uas2IlCantripName).
# 3. regtest.cpp: the R363 block
#    asserts amend to the resolved
#    pins (EVERY chain opens with
#    'if (' - the R418b lesson);
#    the four cantrip-column-lost
#    asserts (R363/R364/R365)
#    amend; the R421 audit block
#    lands before the R227 anchor;
#    census 346 -> 347.
# 4. tools/ua_gap_report.md: the
#    IL cantrips box flips and
#    takes AMENDED R421.
# 5. The seed takes the R419
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
        'R421 splice ABORT: ' + msg)


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


def pair_n(path, old, new, want, label):
    # the same old text at KNOWN
    # many sites - all must amend
    s = rd(path)
    n = s.count(old)
    m = s.count(new)
    if n == 0 and m == want:
        already.append(label)
        return
    if n != want:
        die('%s: old text count %d'
            ' (want %d)' % (label, n, want))
    wr(path, s.replace(old, new))
    applied.append(label)


ILC = 'rules/uailcantrips.h'
UAS2 = 'rules/uaspelltables2.h'
RT = 'regtest.cpp'
GP = 'tools/ua_gap_report.md'
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

# ---- the resolved read ----
DENS = [2, 2, 2, 8, 2, 8, 3, 8]

# ========= (a) the seed record =========
SEED_ENTRY = E(
    '- R419 landed 2026-10-13:',
    '  commit 058a00b (census 346,',
    '  preflight GREEN), the UA',
    '  CANTRIP CASTING-TIME',
    '  RESOLUTION PART 2 (book pp.',
    '  49-51) - the PDF read resolves',
    '  the person-affecting (10),',
    '  personal (10) and haunting-',
    '  sound (8) casting-time',
    '  families: 28 cells, all clean',
    '  unit fractions AS PRINTED; the',
    '  censuses 1/3/2/4, 7/3/0/0 and',
    '  0/0/5/3 (the 1/6 inside the',
    '  2..10 band); the two R416',
    '  areas (the Bluelight sphere,',
    '  the Firefinger line), the range',
    '  units (the AD&D 1" notation),',
    '  the slow-poison defer (1 day)',
    '  and the creak reads (the',
    '  former 1/3 segment, the',
    '  traverse 10 feet) resolve with',
    '  the read; the hole flags come',
    '  off - the MU cantrip',
    '  descriptions stand hole-free.',
    '  The ./nn save hash diverged',
    '  (50f18379 vs the published',
    '  f4de3b1e) - benign (21st',
    '  occurrence); the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R419 landed 2026-10-13' in s:
    already.append('seed: the R419 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R419 record')

# ========= (b) rules/uailcantrips.h =========

# the header judgment bullet
pair(ILC,
     E('//   - the casting-time cells print'
       ' fraction garbles',
       '//     (/z, "2, />, "/s, /s and'
       " '/s segment) - the",
       '//     numerals never print clean;'
       ' holes pending the',
       '//     PDF, not pinned as numeric'
       ' data.'),
     E('//   - the casting-time cells print'
       ' fraction garbles',
       '//     (/z, "2, />, "/s, /s and'
       " '/s segment) - the",
       '//     numerals never print clean;'
       ' RESOLVED (R421):',
       '//     the clean PDF read pins all'
       ' eight cells (the',
       '//     uailcCastTimeDen family'
       ' below).'),
     'ilc: the judgment bullet')

# the R342 cross-reference bullet
pair(ILC,
     E('//   - the R342 IL cantrip column is'
       ' wholly lost',
       '//     (uas2IlCantripListLost) - none of'
       ' the names',
       '//     seam-checks, asserted in the'
       ' audit.'),
     E('//   - the R342 IL cantrip column: the'
       ' scan read',
       '//     it wholly lost - RESOLVED (R421):'
       ' the clean',
       '//     p. 31 read gives the whole'
       ' column (the',
       '//     uas2IlCantrip roster), the'
       ' eight names',
       '//     seam-checking this description'
       ' roster row',
       '//     for row, asserted in the audit.'),
     'ilc: the R342 cross-reference'
     ' bullet')

# the reflection sentence resolves
pair(ILC,
     E('// The reflection sentence garbles;'
       ' the',
       '// visual-capability read pins:'
       ' pale blue or pink',
       '// hues leave the visual'
       ' capabilities undisturbed,',
       '// other hues disturb them -'
       ' flagged pending the PDF.',
       'inline bool'
       ' uailcLightsReflectionSentence'
       'Garbled()',
       '    { return true; }'),
     E('// The reflection sentence: the PDF'
       ' read',
       '// resolves the garble (R421) - the',
       '// illumination from any one globe'
       ' will',
       '// not cast reflections beyond 1'
       ' inch,',
       '// and the light shed cannot be'
       ' detected',
       '// beyond 3 inches. The',
       '// visual-capability read stands:'
       ' pale',
       '// blue or pink hues leave the'
       ' visual',
       '// capabilities undisturbed, other'
       ' hues',
       '// disturb them.',
       'inline int'
       ' uailcLightsReflectionBeyond'
       'Inches()',
       '    { return 1; }',
       '',
       'inline int'
       ' uailcLightsDetectedBeyondInches()',
       '    { return 3; }'),
     'ilc: the lights reflection read')

# the casting-time family lands at
# the lights flag site
pair(ILC,
     E('// The casting-time cell prints a'
       ' fraction garble - a',
       '// hole pending the PDF.',
       'inline bool uailcLightsCastingCell'
       'Garbled()',
       '    { return true; }'),
     E('// The casting times: the PDF read'
       ' (R421 -',
       '// the clean p. 65-66 print)'
       ' resolves the',
       '// whole family - every cell a'
       ' clean unit',
       '// fraction, one segment over the',
       '// denominator. The denominators,'
       ' in roster',
       '// order (colored lights, dim, haze'
       ' and',
       '// mirage at 1/2; rainbow at 1/3;',
       '// mask, noise and the'
       " two-d-lusion at 1/8):",
       'inline int uailcCastTimeDen(int i)',
       '{',
       '    static const int D[8] = { 2,'
       ' 2, 2, 8,',
       '        2, 8, 3, 8 };',
       '    if (i < 0) i = 0;',
       '    if (i > 7) i = 7;',
       '    return D[i];',
       '}',
       '',
       '// The casting-time denominator'
       ' census',
       '// helper.',
       'inline int uailcCastTimeDenCount'
       '(int d)',
       '{',
       '    int n = 0;',
       '    for (int i = 0; i < 8; ++i)',
       '        if (uailcCastTimeDen(i)'
       ' == d)',
       '            ++n;',
       '    return n;',
       '}'),
     'ilc: the casting-time family')

# the seven remaining flag sites
pair(ILC,
     E('inline bool uailcDimCastingCell'
       'Garbled()',
       '    { return true; }'),
     E('// The casting time: 1/2 segment'
       ' (the PDF',
       '// read - R421); rides'
       ' uailcCastTimeDen(1).'),
     'ilc: the dim casting time')

pair(ILC,
     E('inline bool uailcHazeAoeCellGarble'
       'Decoded()',
       '    { return true; }'),
     E('// The area cell: the PDF read'
       ' confirms',
       '// the decode (R421) - the print'
       ' reads',
       '// 1" cube CLEAN; the decode flag'
       ' amends',
       '// away.'),
     'ilc: the haze area decode')

pair(ILC,
     E('inline bool uailcHazeCastingCell'
       'Garbled()',
       '    { return true; }'),
     E('// The casting time: 1/2 segment'
       ' (the PDF',
       '// read - R421); rides'
       ' uailcCastTimeDen(2).'),
     'ilc: the haze casting time')

pair(ILC,
     E('inline bool uailcMaskCastingCell'
       'Garbled()',
       '    { return true; }'),
     E('// The casting time: 1/8 segment'
       ' (the PDF',
       '// read - R421); rides'
       ' uailcCastTimeDen(3).'),
     'ilc: the mask casting time')

pair(ILC,
     E('// The school cell never prints -'
       ' a hole pending the',
       '// PDF.',
       'inline bool uailcMirageSchoolCell'
       'Lost()',
       '    { return true; }'),
     E('// The school cell: the PDF read'
       ' resolves',
       '// the loss (R421) - the header'
       ' prints',
       '// Mirage (Illusion).',
       'inline bool uailcMirageSchoolIs'
       'Illusion()',
       '    { return true; }'),
     'ilc: the mirage school')

pair(ILC,
     E('// The area cell prints a bare 2sq.'
       ' fragment - a hole',
       '// pending the PDF.',
       'inline bool uailcMirageAoeCell'
       'Garbled()',
       '    { return true; }'),
     E('// The area cell: the PDF read'
       ' resolves',
       '// the fragment (R421) - the print',
       '// reads 2 sq. " (two square'
       ' inches).',
       'inline int uailcMirageAoeSquare'
       'Inches()',
       '    { return 2; }'),
     'ilc: the mirage area')

pair(ILC,
     E('// The somatic tail garbles (a'
       ' single pass to cause',
       '// the magic to begin); the'
       ' casting cell prints a',
       '// bare segment fragment - the'
       ' numeral lost - holes',
       '// pending the PDF.',
       'inline bool uailcMirageSomaticTail'
       'Garbled()',
       '    { return true; }',
       '',
       'inline bool uailcMirageCasting'
       'NumeralLost()',
       '    { return true; }'),
     E('// The somatic tail: the PDF read'
       ' resolves',
       '// the garble (R421) - the caster',
       '// speaks a word or two'
       ' descriptive of the',
       '// mirage and then makes a single'
       ' pass',
       '// to cause the magic to begin; it'
       ' is',
       '// maintained by concentration'
       ' alone',
       '// thereafter. The casting cell'
       ' prints 1/2',
       '// segment - rides'
       ' uailcCastTimeDen(4).',
       'inline bool uailcMirageWordOrTwo'
       'ThenSinglePass()',
       '    { return true; }',
       '',
       'inline bool uailcMirageKeptBy'
       'ConcentrationAlone()',
       '    { return true; }'),
     'ilc: the mirage somatic tail')

pair(ILC,
     E('// The casting cell prints a bare s'
       ' fragment - a',
       '// garble, a hole pending the PDF.',
       'inline bool uailcNoiseCastingCell'
       'Garbled()',
       '    { return true; }'),
     E('// The casting time: 1/8 segment'
       ' (the PDF',
       '// read - R421); rides'
       ' uailcCastTimeDen(5).'),
     'ilc: the noise casting time')

pair(ILC,
     E('inline bool uailcRainbowCastingCell'
       'Garbled()',
       '    { return true; }'),
     E('// The casting time: 1/3 segment'
       ' (the PDF',
       '// read - R421); rides'
       ' uailcCastTimeDen(6).'),
     'ilc: the rainbow casting time')

pair(ILC,
     E('// The school cell never prints -'
       ' a hole pending the',
       '// PDF.',
       'inline bool uailcTwodSchoolCell'
       'Lost()',
       '    { return true; }'),
     E('// The school cell: the PDF read'
       ' resolves',
       '// the loss (R421) - the header'
       ' prints',
       "// Two-D'lusion (Illusion).",
       'inline bool uailcTwodSchoolIs'
       'Illusion()',
       '    { return true; }'),
     'ilc: the twod school')

pair(ILC,
     E('// The area-of-effect cell prints'
       ' empty - a hole',
       '// pending the PDF.',
       'inline bool uailcTwodAoeCellLost()',
       '    { return true; }'),
     E('// The area-of-effect cell: the'
       ' PDF read',
       '// resolves the loss (R421) - the'
       ' print',
       '// reads 4 sq. " (four square'
       ' inches).',
       'inline int uailcTwodAoeSquare'
       'Inches()',
       '    { return 4; }'),
     'ilc: the twod area')

pair(ILC,
     E('inline bool uailcTwodCastingCell'
       'Garbled()',
       '    { return true; }'),
     E('// The casting time: 1/8 segment'
       ' (the PDF',
       '// read - R421); rides'
       ' uailcCastTimeDen(7).'),
     'ilc: the twod casting time')

# ========= (c) rules/uaspelltables2.h =========

pair(UAS2,
     E('// the illusionist cantrip column'
       ' and the illusionist 3rd-6th'
       ' columns',
       '// are wholly lost; the'
       ' illusionist 2nd-level'
       ' brace-garbage cell and'),
     E('// the illusionist 3rd-6th columns'
       ' are',
       '// wholly lost (the cantrip column',
       '// RESOLVES - the R421 clean p. 31',
       '// read); the illusionist 2nd-level'
       ' brace-garbage cell and'),
     'uas2: the judgment bullet')

pair(UAS2,
     E('// The illusionist minor-illusion'
       ' cantrip column is wholly lost',
       '// (the cells print garbage; the'
       ' acquisition prose survives).',
       'inline bool uas2IlCantripListLost()',
       '    { return true; }'),
     E('// The illusionist minor-illusion'
       ' cantrip',
       '// column: the PDF read resolves the',
       '// loss (R421) - the clean p. 31',
       '// print gives the whole column, the',
       '// eight names in roster order,',
       '// matching the description roster',
       '// (rules/uailcantrips.h) row for'
       ' row.',
       'inline int uas2IlCantripCount()',
       '    { return 8; }',
       '',
       'inline const char*'
       ' uas2IlCantripName(int i) {',
       '    static const char* const'
       ' k[8] = {',
       '        "Colored Lights", "Dim",'
       ' "Haze", "Mask",',
       '        "Mirage", "Noise",'
       ' "Rainbow",',
       "        \"Two-D'lusion\",",
       '    };',
       '    if (i < 0) i = 0;',
       '    if (i > 7) i = 7;',
       '    return k[i];',
       '}'),
     'uas2: the cantrip column roster')

# ========= (d) regtest.cpp =========

pair(RT,
     '            if (!uailcLights'
     'ReflectionSentenceGarbled())'
     ' ++bad;',
     E('            if (uailcLights'
       'ReflectionBeyondInches()',
       '                != 1',
       '                || uailcLights'
       'DetectedBeyondInches()',
       '                != 3) ++bad;'),
     'regtest: the lights reflection')

pair(RT,
     '            if (!uailcLightsCastingCell'
     'Garbled()) ++bad;',
     '            if (uailcCastTimeDen(0)'
     ' != 2) ++bad;',
     'regtest: the lights casting time')

pair(RT,
     '            if (!uailcDimCastingCell'
     'Garbled()) ++bad;',
     '            if (uailcCastTimeDen(1)'
     ' != 2) ++bad;',
     'regtest: the dim casting time')

pair(RT,
     '            if (!uailcHazeAoeCellGarble'
     'Decoded()) ++bad;',
     E('            // (the PDF read confirms'
       ' the 1-inch',
       '            // cube - the decode flag'
       ' amends',
       '            // away, R421)'),
     'regtest: the haze area decode')

pair(RT,
     '            if (!uailcHazeCastingCell'
     'Garbled()) ++bad;',
     '            if (uailcCastTimeDen(2)'
     ' != 2) ++bad;',
     'regtest: the haze casting time')

pair(RT,
     '            if (!uailcMaskCastingCell'
     'Garbled()) ++bad;',
     '            if (uailcCastTimeDen(3)'
     ' != 8) ++bad;',
     'regtest: the mask casting time')

pair(RT,
     '            if (!uailcMirageSchoolCell'
     'Lost()) ++bad;',
     '            if (!uailcMirageSchoolIs'
     'Illusion()) ++bad;',
     'regtest: the mirage school')

pair(RT,
     '            if (!uailcMirageAoeCell'
     'Garbled()) ++bad;',
     '            if (uailcMirageAoeSquare'
     'Inches() != 2) ++bad;',
     'regtest: the mirage area')

pair(RT,
     '            if (!uailcMirageSomaticTail'
     'Garbled()) ++bad;',
     E('            if (!uailcMirageWordOrTwo'
       'ThenSinglePass())',
       '                ++bad;',
       '            if (!uailcMirageKeptBy'
       'ConcentrationAlone())',
       '                ++bad;'),
     'regtest: the mirage somatic tail')

pair(RT,
     '            if (!uailcMirageCasting'
     'NumeralLost()) ++bad;',
     '            if (uailcCastTimeDen(4)'
     ' != 2) ++bad;',
     'regtest: the mirage casting time')

pair(RT,
     '            if (!uailcNoiseCastingCell'
     'Garbled()) ++bad;',
     '            if (uailcCastTimeDen(5)'
     ' != 8) ++bad;',
     'regtest: the noise casting time')

pair(RT,
     '            if (!uailcRainbowCastingCell'
     'Garbled()) ++bad;',
     '            if (uailcCastTimeDen(6)'
     ' != 3) ++bad;',
     'regtest: the rainbow casting time')

pair(RT,
     '            if (!uailcTwodSchoolCell'
     'Lost()) ++bad;',
     '            if (!uailcTwodSchoolIs'
     'Illusion()) ++bad;',
     'regtest: the twod school')

pair(RT,
     '            if (!uailcTwodAoeCell'
     'Lost()) ++bad;',
     '            if (uailcTwodAoeSquare'
     'Inches() != 4) ++bad;',
     'regtest: the twod area')

pair(RT,
     '            if (!uailcTwodCastingCell'
     'Garbled()) ++bad;',
     '            if (uailcCastTimeDen(7)'
     ' != 8) ++bad;',
     'regtest: the twod casting time')

# the four cantrip-column-lost asserts
# (the R363, R364 and R365 blocks)
pair_n(RT,
       '            if (!uas2IlCantripList'
       'Lost()) ++bad;',
       '            if (uas2IlCantripCount()'
       ' != 8) ++bad;',
       4,
       'regtest: the four cantrip-column'
       ' asserts')

# the two stale comments
pair(RT,
     E('    // the cantrip column is lost.'
       ' The item',
       '    // stays open - the 3rd through'
       ' 7th'),
     E('    // the cantrip column resolves'
       ' (the',
       '    // R421 PDF read). The item',
       '    // stays open - the 3rd through'
       ' 7th'),
     'regtest: the R363 head comment')

pair(RT,
     E('        // names; the cantrip column'
       ' is lost'),
     E('        // names; the cantrip column'
       ' resolves',
       '        // (the R421 PDF read)'),
     'regtest: the seam comment')

# ---- the R421 audit block ----
AUD = E(
    '    // ---- R421: the IL cantrip',
    '    // cast-times pin audit ----',
    '    // The PDF read (book pp. 65-66)',
    '    // resolves the whole IL cantrip hole',
    '    // ledger: the eight casting-time',
    '    // cells print clean, unit fractions',
    '    // one segment over the denominator',
    '    // (colored lights, dim, haze and',
    '    // mirage at 1/2; rainbow at 1/3;',
    '    // mask, noise and the two-d-lusion',
    '    // at 1/8 - the census 4/1/3, every',
    '    // denominator inside the 2..10 band',
    '    // the p. 45 header prints); the',
    '    // mirage and two-d-lusion school',
    '    // cells print (Illusion); the areas',
    '    // pin (the mirage 2 sq. inches, the',
    '    // two-d-lusion 4 sq. inches); the',
    '    // mirage somatic tail reads clean',
    '    // (a word or two then a single pass,',
    '    // kept by concentration alone); the',
    '    // colored-lights reflection sentence',
    '    // pins (reflections beyond 1 inch,',
    '    // detection beyond 3 inches); the',
    '    // haze area decode confirms (the 1"',
    '    // cube prints clean); and the clean',
    '    // p. 31 read resolves the R342 IL',
    '    // cantrip column - the eight names,',
    '    // cross-checking the description',
    '    // roster row for row. The IL cantrip',
    '    // descriptions now stand hole-free;',
    '    // census 346 -> 347.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        if (uailcCastTimeDenCount(2)'
    ' != 4',
    '                || uailcCastTimeDen'
    'Count(3) != 1',
    '                || uailcCastTimeDen'
    'Count(8) != 3)',
    '            ++bad;',
    '        if (uailcCastTimeDenCount(2)',
    '                + uailcCastTimeDen'
    'Count(3)',
    '                + uailcCastTimeDen'
    'Count(8)',
    '                != 8) ++bad;',
    '        // the 2..10 norm band',
    '        for (int i = 0; i < 8; ++i)',
    '            if (uailcCastTimeDen(i)'
    ' < 2',
    '                || uailcCastTimeDen(i)'
    ' > 10)',
    '                ++bad;',
    '        // the resolved reads',
    '        if (uailcLightsReflection'
    'BeyondInches()',
    '                != 1',
    '                || uailcLightsDetected'
    'BeyondInches()',
    '                != 3',
    '                || !uailcMirageSchoolIs'
    'Illusion()',
    '                || uailcMirageAoeSquare'
    'Inches() != 2',
    '                || !uailcMirageWordOrTwo'
    'ThenSinglePass()',
    '                || !uailcMirageKeptBy'
    'ConcentrationAlone()',
    '                || !uailcTwodSchoolIs'
    'Illusion()',
    '                || uailcTwodAoeSquare'
    'Inches() != 4)',
    '            ++bad;',
    '        // the R342 IL cantrip column:',
    '        // the eight names cross-check',
    '        // the description roster row for',
    '        // row (each table name is the',
    '        // prefix of its description',
    '        // name, in order)',
    '        if (uas2IlCantripCount() != 8)',
    '            ++bad;',
    '        if (strncmp(uailcLightsName(),',
    '                    uas2IlCantrip'
    'Name(0),',
    '                    strlen(uas2Il'
    'CantripName(0)))',
    '                != 0',
    '                || strncmp(uailcDim'
    'Name(),',
    '                    uas2IlCantrip'
    'Name(1),',
    '                    strlen(uas2Il'
    'CantripName(1)))',
    '                != 0',
    '                || strncmp(uailcHaze'
    'Name(),',
    '                    uas2IlCantrip'
    'Name(2),',
    '                    strlen(uas2Il'
    'CantripName(2)))',
    '                != 0',
    '                || strncmp(uailcMask'
    'Name(),',
    '                    uas2IlCantrip'
    'Name(3),',
    '                    strlen(uas2Il'
    'CantripName(3)))',
    '                != 0',
    '                || strcmp(uailcMirage'
    'Name(),',
    '                    uas2IlCantrip'
    'Name(4))',
    '                != 0',
    '                || strncmp(uailcNoise'
    'Name(),',
    '                    uas2IlCantrip'
    'Name(5),',
    '                    strlen(uas2Il'
    'CantripName(5)))',
    '                != 0',
    '                || strncmp(uailcRainbow'
    'Name(),',
    '                    uas2IlCantrip'
    'Name(6),',
    '                    strlen(uas2Il'
    'CantripName(6)))',
    '                != 0',
    '                || strcmp(uailcTwod'
    'Name(),',
    '                    uas2IlCantrip'
    'Name(7))',
    '                != 0) ++bad;',
    '        // the per-row denominator pins',
    '        // - fail on any wrong cell (the',
    '        // mirror eval)',
    '        if (uailcCastTimeDen(0) != 2',
    '                || uailcCastTimeDen(1)'
    ' != 2',
    '                || uailcCastTimeDen(2)'
    ' != 2',
    '                || uailcCastTimeDen(3)'
    ' != 8',
    '                || uailcCastTimeDen(4)'
    ' != 2',
    '                || uailcCastTimeDen(5)'
    ' != 8',
    '                || uailcCastTimeDen(6)'
    ' != 3',
    '                || uailcCastTimeDen(7)'
    ' != 8)',
    '            ++bad;',
    '        printf("R421 UA IL cantrip cast-'
    'times pin',
    '            " audit: bad'
    + ' %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R421 audit block')

# ======== (e) tools/ua_gap_report.md ========

pair(GP,
     '- [ ] **The illusionist cantrips**'
     ' (pp.',
     '- [x] **The illusionist cantrips**'
     ' (pp.',
     'gap: the IL cantrips box flips')

pair(GP,
     E('      - AMENDED R401: the cantrip',
       '        tier seam CLOSED',
       '        (rules/cantriptier.h) - the',
       '        tier gate drops; the box',
       '        stays open only on the',
       '        casting-time fraction holes',
       '        pending the PDF read.'),
     E('      - AMENDED R401: the cantrip',
       '        tier seam CLOSED',
       '        (rules/cantriptier.h) - the',
       '        tier gate drops; the box',
       '        stays open only on the',
       '        casting-time fraction holes',
       '        pending the PDF read.',
       '      - AMENDED R421: the PDF read',
       '        resolves the whole ledger -',
       '        the eight casting-time cells',
       '        print clean (colored lights,',
       '        dim, haze and mirage at 1/2;',
       '        rainbow at 1/3; mask, noise',
       '        and the two-d-lusion at 1/8 -',
       '        the census 4/1/3, the band',
       '        holds); the mirage and',
       '        two-d-lusion school cells',
       '        print (Illusion); the areas',
       '        pin (the mirage 2 sq. inches,',
       '        the two-d-lusion 4 sq.',
       '        inches); the mirage somatic',
       '        tail reads clean; the',
       '        colored-lights reflection',
       '        sentence pins (the',
       '        reflections-beyond-1-inch and',
       '        the detected-beyond-3-inches',
       '        reads); and the clean p. 31',
       '        read resolves the R342 IL',
       '        cantrip column (the eight',
       '        names, cross-checking the',
       '        description roster row for',
       '        row). The IL cantrip',
       '        descriptions stand hole-free;',
       '        the box flips in the SAME',
       '        commit (the R420 lesson).'),
     'gap: the IL cantrips box takes R421')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 347:
    die('the census %d' % s.count('audit: bad'))
if s.count('R421 UA IL cantrip cast-times'
           ' pin') != 1:
    die('the R421 audit label')

# the hole flags are gone - everywhere
FLAGS = (
    'uailcLightsCastingCellGarbled',
    'uailcDimCastingCellGarbled',
    'uailcHazeCastingCellGarbled',
    'uailcMaskCastingCellGarbled',
    'uailcMirageCastingNumeralLost',
    'uailcNoiseCastingCellGarbled',
    'uailcRainbowCastingCellGarbled',
    'uailcTwodCastingCellGarbled',
    'uailcLightsReflectionSentence'
    'Garbled',
    'uailcHazeAoeCellGarbleDecoded',
    'uailcMirageSchoolCellLost',
    'uailcMirageAoeCellGarbled',
    'uailcMirageSomaticTailGarbled',
    'uailcTwodSchoolCellLost',
    'uailcTwodAoeCellLost',
    'uas2IlCantripListLost')
for flag in FLAGS:
    if s.count(flag):
        die('the %s flag survives in'
            ' regtest' % flag)
    for p in (ILC, UAS2):
        if flag in rd(p):
            die('the %s flag survives in'
                ' a header' % flag)

# the no-bare-|| gate (the R418b
# lesson): no uailc/uas2 chain may
# BEGIN with '||' - a '||' line is
# legal only inside an open chain
prev = ''
for n, ln in enumerate(s.split(NL), 1):
    if (_re.match(r'^ +\|\| ', ln)
            and ('uailc' in ln
                 or 'uas2' in ln)):
        p = prev.strip()
        if (not p or p.startswith('//')
                or p.endswith(';')):
            die('an orphaned chain at'
                ' regtest:%d' % n)
    prev = ln

# the mirror eval (the standing R418b
# gate): every regtest denominator pin
# holds against the header D[] arrays -
# ALL seven families
DENSRC = [
    ('ucn', 'rules/uacantrips1.h', 20),
    ('ucr', 'rules/uacantrips2.h', 12),
    ('ucl', 'rules/uacantrips3.h', 6),
    ('ucp', 'rules/uacantrips4.h', 10),
    ('uco', 'rules/uacantrips5.h', 10),
    ('uch', 'rules/uacantrips6.h', 8),
    ('uailc', ILC, 8),
]
DD = {}
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
    DD[dpfx] = D
if DD['uailc'] != DENS:
    die('the uailc D[] mismatch')

PIN = _re.compile(
    r'(\w+)CastTimeDen\((\d+)\)'
    r' != (\d+)')
for n, ln in enumerate(s.split(NL), 1):
    for m in PIN.finditer(ln):
        pfx, i, d = (m.group(1),
                     int(m.group(2)),
                     int(m.group(3)))
        if pfx not in DD:
            die('an unknown pin prefix at'
                ' regtest:%d' % n)
        if i >= len(DD[pfx]):
            die('a pin index past the'
                ' roster at regtest:%d' % n)
        if DD[pfx][i] != d:
            die('a wrong pin at'
                ' regtest:%d' % n)

# the resolved numeric pins mirror the
# headers
h = rd(ILC)
for fn, want in (
        ('uailcLightsReflectionBeyond'
         'Inches', 1),
        ('uailcLightsDetectedBeyond'
         'Inches', 3),
        ('uailcMirageAoeSquareInches',
         2),
        ('uailcTwodAoeSquareInches', 4)):
    m = _re.search(
        r'inline int ' + fn
        + r'\(\)\n    \{ return (\d+); \}',
        h)
    if not m or int(m.group(1)) != want:
        die('the %s header pin' % fn)
    if fn + '() ' not in s and (
            fn + '()' not in s):
        die('the %s regtest pin' % fn)
h2 = rd(UAS2)
m = _re.search(
    r'inline int uas2IlCantripCount\(\)'
    r'\n    \{ return (\d+); \}', h2)
if not m or int(m.group(1)) != 8:
    die('the uas2IlCantripCount pin')

# the R342 roster names mirror the
# description names (the order
# cross-check)
names = _re.findall(
    r'"(Colored Lights|Dim|Haze|Mask|'
    r"Mirage|Noise|Rainbow|Two-D'lusion)"
    r'",', h2)
want_names = ['Colored Lights', 'Dim',
              'Haze', 'Mask', 'Mirage',
              'Noise', 'Rainbow',
              "Two-D'lusion"]
if names != want_names:
    die('the uas2 roster order')

# the symbol guard: every symbol the
# audits call is defined
for pfx, pdef in (('uailc', ILC),
                  ('uas2', UAS2)):
    _used = set(_re.findall(
        r'\b%s\w+' % pfx, s))
    _def = set(_re.findall(
        r'\b%s\w+' % pfx, rd(pdef)))
    if _used - _def:
        die('undefined %s calls %s'
            % (pfx, sorted(_used - _def)))

# the inline counts
for p, want in ((ILC, 101), (UAS2, 26)):
    p_txt = rd(p)
    if p_txt.count('inline') != want:
        die('the inline count %d in %s'
            % (p_txt.count('inline'), p))
    if not p_txt.endswith(NL):
        die('the trailing newline in %s' % p)

# the class guard on each amended header
for p in (ILC, UAS2):
    for ln in rd(p).split(NL):
        if ln and not ln.startswith((
                '//', '#', 'namespace',
                'inline', 'const', 'struct',
                '{', '}', '    ',
                '        ',
                '            ')):
            die('a non-code line in %s:'
                ' %r' % (p, ln[:44]))

g = rd(GP)
if g.count('AMENDED R421') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R421'))
if g.count('- [x]') != 99:
    die('the gap closed count %d'
        % g.count('- [x]'))
if ('- [ ] **The illusionist'
        ' cantrips**') in g:
    die('the IL box still open')
opens = [l for l in g.split(NL)
         if l.startswith('- [ ]')]
if len(opens) != 6:
    die('the gap open count %d'
        % len(opens))

if 'R419 landed 2026-10-13' not in rd(SD):
    die('the seed R419 record')

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    for pfx in ('uailc', 'uas2'):
        if _re.search(r'\b%s\w' % pfx,
                      rd(path)):
            die('%s calls the %s pins'
                ' early' % (path, pfx))

print('R421 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the IL cantrip cast-times')
print('  resolution - the PDF read')
print('  resolves the eight casting-time')
print('  cells (the census 4/1/3 at')
print('  1/2, 1/3 and 1/8 - the band')
print('  holds), the mirage and')
print('  two-d-lusion school cells and')
print('  areas, the mirage somatic tail,')
print('  the colored-lights reflection')
print('  sentence and the R342 IL')
print('  cantrip column (the clean p. 31')
print('  read); the IL cantrip')
print('  descriptions now stand')
print('  hole-free and the gap box')
print('  flips; census 346 -> 347')
print('commit: R421: the IL cantrip'
      ' cast-times resolution (census'
      ' 347)')

