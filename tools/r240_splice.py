#!/usr/bin/env python3
# R240 splice: the III.E Special artifacts pins.
#
# DMG p.130-131, upload lines ~9917-9946 - the
# artifact g.p. sale value table that closes
# the III.E magic item block, TABLE (III.E.)
# Special.: 29 rows in kArtifacts order (the
# Axe of the Dwarvish Lords 01 through the Wand
# of Orcus 00 - band 100); 26 single-value rows;
# the Orb of the Dragonkind 41-47 uniform range
# 10-80,000 (read 10,000 through 80,000); the
# Teeth of Dahlver-Nar 93-98 at 5,000/tooth;
# the Throne of the Gods 99 with NO printed sale
# value; and the table footnote: These items
# bring no experience points. (every row).
# The row NAMES were already pinned by the R122
# line-diff audit; this round pins the sale
# values, band edges and the value conventions.
# Patches: 4 (new rules/specart.h, the regtest
# include, the audit block, the dmg-gap-report
# log entry). Census 158 -> 159.
#
# commit: R240: the III.E Special artifacts pins pinned - DMG p.130-131, the sale values and the no-x.p. convention (census 159)

import sys

SA   = 'rules/specart.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 158 and t.count('audit: bad ') != 159:
    print('R240 FAIL: regtest census is neither 158 nor 159')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/specart.h',
    '// R240: the III.E Special artifacts pins',
    '// (DMG p.130-131) - the g.p. sale value',
    '// table that closes the III.E magic item',
    '// block, TABLE (III.E.) Special.:',
    '//   - 29 artifact rows, the Axe of the',
    '//     Dwarvish Lords 01 through the Wand',
    '//     of Orcus 00 (the 00 band pins as',
    '//     100, the R122 convention).',
    '//   - the printed sale values: 26',
    '//     single-value rows (the Axe 55,000,',
    '//     the Baba Yaga Hut 90,000, the',
    '//     Jacinth of Inestimable Beauty',
    '//     100,000, the Mighty Servant of',
    '//     Leuk-O 185,000, the Sceptre of',
    '//     Might 150,000, the Sword of Kas',
    '//     97,000).',
    '//   - the Orb of the Dragonkind 41-47',
    '//     prints a RANGE, 10-80,000 (read',
    '//     10,000 through 80,000): a uniform',
    '//     roll between the bounds (the R225',
    '//     dual-value analog, count 1).',
    '//   - the Teeth of Dahlver-Nar 93-98',
    '//     print 5,000/tooth - the per-tooth',
    '//     convention (count 1).',
    '//   - the Throne of the Gods 99 prints',
    '//     NO sale value (priceless) - pinned',
    '//     as 0 g.p. (count 1).',
    '//   - the no-x.p. convention: the table',
    '//     footnote reads These items bring no',
    '//     experience points. - every row of',
    '//     the table (all 29).',
    '// The row identity is the 29 die bands of',
    '// the engine Special artifacts table',
    '// (dm/treasure.cpp kArtifacts order).',
    '// The row NAMES were pinned by the R122',
    '// line-diff audit; this header pins the',
    '// sale values, band edges and the value',
    '// conventions.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int saRowCount() {',
    '    // the Axe through the Wand of Orcus',
    '    return 29;',
    '}',
    '',
    'inline int saRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 28) i = 28;',
    '    static const int t[29] = {',
    '        1, 2, 3, 5, 21, 22, 23, 25, 26, 27,',
    '        28, 30, 32, 33, 34, 36, 38, 39, 41, 48,',
    '        64, 65, 67, 69, 75, 92, 93, 99, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int saRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 28) i = 28;',
    '    static const int t[29] = {',
    '        1, 2, 4, 20, 21, 22, 24, 25, 26, 27,',
    '        29, 31, 32, 33, 35, 37, 38, 40, 47, 63,',
    '        64, 66, 68, 74, 91, 92, 98, 99, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int saSaleGp(int i) {',
    '    // the printed g.p. sale values; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 28) i = 28;',
    '    static const int t[29] = {',
    '        55000, 90000, 62500, 50000, 75000, 85000, 35000, 60000,',
    '        25000, 20000, 47500, 50000, 100000, 40000, 27500, 35000,',
    '        72500, 185000, 10000, 100000, 112500, 80000, 17500, 25000,',
    '        150000, 97000, 5000, 0, 10000,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int saSaleGpHi(int i) {',
    '    // the range upper bound (the Orb only); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 28) i = 28;',
    '    static const int t[29] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 80000, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int saXpValue(int i) {',
    '    // the no-x.p. convention - all rows zero; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 28) i = 28;',
    '    static const int t[29] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int saNoXpRowCount() {',
    '    // every row brings no experience points',
    '    return 29;',
    '}',
    '',
    'inline int saDualRangeCount() {',
    '    // the Orb of the Dragonkind 10-80,000',
    '    return 1;',
    '}',
    '',
    'inline int saNoSaleRowCount() {',
    '    // the Throne of the Gods prints no sale value',
    '    return 1;',
    '}',
    '',
    'inline int saPerToothRowCount() {',
    '    // the Teeth of Dahlver-Nar 5,000/tooth',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/miscmagic5.h"  // R239: p.130 the misc table 5 pins',
]
inc_new = [
    '#include "rules/miscmagic5.h"  // R239: p.130 the misc table 5 pins',
    '#include "rules/specart.h"  // R240: p.130-131 the III.E Special artifacts pins',
]

# ---- the R240 audit block ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R240: the III.E Special artifacts pins audit ----',
    '    // DMG p.130-131: the artifact g.p. sale',
    '    // value table - the 29 rows, the value',
    '    // conventions and the no-x.p. footnote.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 29 die bands',
    '        if (rules::saRowCount() != 29) ++bad;',
    '        static const int kLo[29] = {',
    '            1, 2, 3, 5, 21, 22, 23, 25, 26, 27,',
    '            28, 30, 32, 33, 34, 36, 38, 39, 41, 48,',
    '            64, 65, 67, 69, 75, 92, 93, 99, 100,',
    '        };',
    '        static const int kHi[29] = {',
    '            1, 2, 4, 20, 21, 22, 24, 25, 26, 27,',
    '            29, 31, 32, 33, 35, 37, 38, 40, 47, 63,',
    '            64, 66, 68, 74, 91, 92, 98, 99, 100,',
    '        };',
    '        static const int kGp[29] = {',
    '            55000, 90000, 62500, 50000, 75000, 85000, 35000, 60000,',
    '            25000, 20000, 47500, 50000, 100000, 40000, 27500, 35000,',
    '            72500, 185000, 10000, 100000, 112500, 80000, 17500, 25000,',
    '            150000, 97000, 5000, 0, 10000,',
    '        };',
    '        static const int kGpHi[29] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 80000, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kXp[29] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 29; ++i)',
    '            if (rules::saRowLo(i) != kLo[i] ||',
    '                rules::saRowHi(i) != kHi[i] ||',
    '                rules::saSaleGp(i) != kGp[i] ||',
    '                rules::saSaleGpHi(i) != kGpHi[i] ||',
    '                rules::saXpValue(i) != kXp[i])',
    '                ++bad;',
    '        for (int i = 1; i < 29; ++i)',
    '            if (rules::saRowLo(i) !=',
    '                rules::saRowHi(i - 1) + 1) ++bad;',
    '        if (rules::saRowLo(-5) != 1 ||',
    '            rules::saRowHi(99) != 100) ++bad;',
    '        // the printed sale values: the Axe of',
    '        // the Dwarvish Lords, the Jacinth of',
    '        // Inestimable Beauty, the Mighty',
    '        // Servant of Leuk-O, the Marvelous',
    '        // Nightingale, the Sceptre of Might',
    '        // and the Sword of Kas',
    '        if (rules::saSaleGp(0) != 55000 ||',
    '            rules::saSaleGp(12) != 100000 ||',
    '            rules::saSaleGp(17) != 185000 ||',
    '            rules::saSaleGp(20) != 112500 ||',
    '            rules::saSaleGp(24) != 150000 ||',
    '            rules::saSaleGp(25) != 97000) ++bad;',
    '        // the Orb of the Dragonkind uniform',
    '        // range 10,000-80,000 (count 1)',
    '        if (rules::saSaleGp(18) != 10000 ||',
    '            rules::saSaleGpHi(18) != 80000 ||',
    '            rules::saDualRangeCount() != 1) ++bad;',
    '        // the Teeth of Dahlver-Nar at 5,000',
    '        // per tooth (count 1)',
    '        if (rules::saSaleGp(26) != 5000 ||',
    '            rules::saSaleGpHi(26) != 0 ||',
    '            rules::saPerToothRowCount() != 1) ++bad;',
    '        // the Throne of the Gods prints NO',
    '        // sale value (count 1)',
    '        if (rules::saSaleGp(27) != 0 ||',
    '            rules::saSaleGpHi(27) != 0 ||',
    '            rules::saNoSaleRowCount() != 1) ++bad;',
    '        // the Wand of Orcus rides the 00',
    '        // band - pinned as 100',
    '        if (rules::saRowLo(28) != 100 ||',
    '            rules::saSaleGp(28) != 10000) ++bad;',
    '        // the no-x.p. convention: every row',
    '        if (rules::saNoXpRowCount() != 29) ++bad;',
    '        // clamped reads land on the Axe below',
    '        // and the Wand of Orcus above',
    '        if (rules::saSaleGp(-99) != 55000 ||',
    '            rules::saSaleGp(99) != 10000 ||',
    '            rules::saXpValue(-99) != 0 ||',
    '            rules::saXpValue(99) != 0) ++bad;',
    '        printf("R240 special artifacts pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'upload lines ~9917+), or the next',
    'un-pinned III.A-H surrounding prose seam.',
]
gap_new = [
    'upload lines ~9917+), or the next',
    'un-pinned III.A-H surrounding prose seam.',
    '',
    'R240 landed the III.E Special artifacts',
    'pins (DMG p.130-131, upload lines ~9917-',
    '9946) - the artifact g.p. sale value',
    'table that closes the III.E magic item',
    'block, TABLE (III.E.) Special.: 29 rows',
    'in kArtifacts order, the Axe of the',
    'Dwarvish Lords 01 through the Wand of',
    'Orcus 00 (band 100). rules/specart.h',
    '(the grenade.h pattern): the printed',
    'sale values (26 single-value rows,',
    'saSaleGp); the Orb of the Dragonkind',
    '41-47 uniform range 10-80,000 (read',
    '10,000 through 80,000 - saSaleGpHi,',
    'the R225 dual-value analog, count 1);',
    'the Teeth of Dahlver-Nar 93-98 at',
    '5,000 PER TOOTH (count 1); the Throne',
    'of the Gods 99 prints NO sale value',
    '(0 g.p., count 1); and the no-x.p.',
    'convention - the table footnote reads',
    'These items bring no experience points.',
    '(saXpValue, all 29 rows zero). The row',
    'NAMES were already pinned by the R122',
    'line-diff audit; this round pins the',
    'sale values, band edges and the value',
    'conventions. New R240 battery audit;',
    'census 159. Next: R241 - the III.F',
    'armor and shield table pins (DMG',
    'p.129-130; the armor size footnote:',
    '65% of all armor is man-sized, 20% is',
    'elf-sized, 10% is dwarf-sized, and but',
    '5% gnome or halfling sized, upload',
    'lines ~9902+), or the next un-pinned',
    'III.A-H surrounding prose seam.',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson)
marker = 'R240: the III.E Special artifacts pins'
try:
    t = open(SA).read()
    if marker in t:
        already += 1
    else:
        print('R240 FAIL: rules/specart.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(SA, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R240 audit', audit_old, audit_new),
    (GAP, 'the R240 log entry', gap_old, gap_new),
]:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    # the idempotence signal is the NEW text (the R233
    # lesson: append-style patches leave the old text
    # inside the new)
    if new_s in text:
        already += 1
        continue
    if text.count(old_s) == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    else:
        print('R240 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 159:
        print('R240 FAIL: census is not 159')
        sys.exit(1)
    if t.count('R240 special artifacts pins audit') != 1:
        print('R240 FAIL: the R240 audit line must appear once')
        sys.exit(1)
    if t.count('rules/specart.h') != 1:
        print('R240 FAIL: the specart include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R240 landed the III.E Special artifacts') != 1:
        print('R240 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(SA).read()
    if 'namespace rules' not in h or h.count('inline int sa') != 10:
        print('R240 FAIL: the header shape is wrong')
        sys.exit(1)

print('R240 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R240 note: 4 patches; the III.E Special artifacts pins landed -')
print('the sale values and the no-x.p. convention; the III.E magic item')
print('block is complete; census 159.')
print('commit: R240: the III.E Special artifacts pins pinned - DMG p.130-131, the sale values and the no-x.p. convention (census 159)')

