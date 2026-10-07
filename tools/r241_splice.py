#!/usr/bin/env python3
# R241 splice: the III.F armor and shield pins.
#
# DMG p.129-130, upload lines ~9870-9902 (the RIGHT
# column of the two-column print) - the magic armor
# and shield table: 26 rows in kArmor order, Chain
# Mail +1 01-05 through Shield -1 missile attractor
# 98-00 (band 100); the x.p. point values and g.p.
# sale values of every row; the TWO cursed no-x.p.
# rows (Plate Mail of Vulnerability 40-44 and Shield
# -1 missile attractor 98-00 print --- for x.p.); and
# the armor SIZE footnote: 65% of all armor is
# man-sized, 20% elf-sized, 10% dwarf-sized, 5% gnome
# or halfling sized. NO class marks, asterisks or
# dual-value rows ride this table. The row NAMES were
# already pinned by the R122 line-diff audit; this
# round pins the values, band edges and the size
# footnote.
# Patches: 4 (new rules/armorshield.h, the regtest
# include, the audit block, the dmg-gap-report log
# entry). Census 159 -> 160.
#
# commit: R241: the III.F armor and shield pins pinned - DMG p.129-130, the values and the armor size footnote (census 160)

import sys

ASH  = 'rules/armorshield.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 159 and t.count('audit: bad ') != 160:
    print('R241 FAIL: regtest census is neither 159 nor 160')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/armorshield.h',
    '// R241: the III.F armor and shield pins',
    '// (DMG p.129-130) - the magic armor and',
    '// shield table (the RIGHT column of the',
    '// two-column print):',
    '//   - 26 rows, Chain Mail +1 01-05',
    '//     through Shield -1 missile attractor',
    '//     98-00 (the 00 band pins as 100).',
    '//   - the x.p. point values and the g.p.',
    '//     sale values of every row.',
    '//   - the TWO cursed no-x.p. rows: Plate',
    '//     Mail of Vulnerability 40-44 and',
    '//     Shield -1 missile attractor 98-00',
    '//     print --- for x.p. (the R240',
    '//     no-x.p. convention, here on two',
    '//     rows only).',
    '//   - the armor SIZE footnote: 65% of',
    '//     all armor is man-sized, 20%',
    '//     elf-sized, 10% dwarf-sized, 5%',
    '//     gnome or halfling sized (sum 100).',
    '// NO class marks, asterisks or',
    '// dual-value rows ride this table.',
    '// The row identity is the 26 die bands of',
    '// the engine III.F table (dm/treasure.cpp',
    '// kArmor order). The row NAMES were',
    '// pinned by the R122 line-diff audit;',
    '// this header pins the values, band',
    '// edges and the size footnote.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int asRowCount() {',
    '    // Chain Mail +1 through the missile attractor',
    '    return 26;',
    '}',
    '',
    'inline int asRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 25) i = 25;',
    '    static const int t[26] = {',
    '        1, 6, 10, 12, 20, 27, 33, 36, 38,',
    '        39, 40, 45, 51, 56, 60, 64, 67, 69,',
    '        70, 76, 85, 90, 94, 96, 97, 98,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int asRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 25) i = 25;',
    '    static const int t[26] = {',
    '        5, 9, 11, 19, 26, 32, 35, 37, 38,',
    '        39, 44, 50, 55, 59, 63, 66, 68, 69,',
    '        75, 84, 89, 93, 95, 96, 97, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int asXpValue(int i) {',
    '    // the x.p. point values; the cursed rows are 0; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 25) i = 25;',
    '    static const int t[26] = {',
    '        600, 1200, 2000, 300, 800, 1750, 2750, 3500, 4500,',
    '        5000, 0, 400, 500, 1100, 700, 1500, 2250, 3000,',
    '        400, 250, 500, 800, 1200, 1750, 400, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int asSaleGp(int i) {',
    '    // the g.p. sale values; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 25) i = 25;',
    '    static const int t[26] = {',
    '        3500, 7500, 12500, 2000, 5000, 10500, 15500, 20500, 27500,',
    '        30000, 1500, 2500, 3000, 6750, 4000, 8500, 14500, 19000,',
    '        2500, 2500, 5000, 8000, 12000, 17500, 4000, 750,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int asNoXpCount() {',
    '    // the Plate of Vulnerability and the missile attractor',
    '    return 2;',
    '}',
    '',
    'inline int asManSizedPct() {',
    '    // 65% of all armor is man-sized',
    '    return 65;',
    '}',
    '',
    'inline int asElfSizedPct() {',
    '    // 20% is elf-sized',
    '    return 20;',
    '}',
    '',
    'inline int asDwarfSizedPct() {',
    '    // 10% is dwarf-sized',
    '    return 10;',
    '}',
    '',
    'inline int asSmallUserPct() {',
    '    // but 5% gnome or halfling sized',
    '    return 5;',
    '}',
    '',
    '}  // namespace rules',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/specart.h"  // R240: p.130-131 the III.E Special artifacts pins',
]
inc_new = [
    '#include "rules/specart.h"  // R240: p.130-131 the III.E Special artifacts pins',
    '#include "rules/armorshield.h"  // R241: p.129-130 the III.F armor and shield pins',
]

# ---- the R241 audit block ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R241: the III.F armor and shield pins audit ----',
    '    // DMG p.129-130: the magic armor and shield',
    '    // table - the 26 rows, the two cursed',
    '    // no-x.p. rows and the size footnote.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 26 die bands',
    '        if (rules::asRowCount() != 26) ++bad;',
    '        static const int kLo[26] = {',
    '            1, 6, 10, 12, 20, 27, 33, 36, 38,',
    '            39, 40, 45, 51, 56, 60, 64, 67, 69,',
    '            70, 76, 85, 90, 94, 96, 97, 98,',
    '        };',
    '        static const int kHi[26] = {',
    '            5, 9, 11, 19, 26, 32, 35, 37, 38,',
    '            39, 44, 50, 55, 59, 63, 66, 68, 69,',
    '            75, 84, 89, 93, 95, 96, 97, 100,',
    '        };',
    '        static const int kXp[26] = {',
    '            600, 1200, 2000, 300, 800, 1750, 2750, 3500, 4500,',
    '            5000, 0, 400, 500, 1100, 700, 1500, 2250, 3000,',
    '            400, 250, 500, 800, 1200, 1750, 400, 0,',
    '        };',
    '        static const int kGp[26] = {',
    '            3500, 7500, 12500, 2000, 5000, 10500, 15500, 20500, 27500,',
    '            30000, 1500, 2500, 3000, 6750, 4000, 8500, 14500, 19000,',
    '            2500, 2500, 5000, 8000, 12000, 17500, 4000, 750,',
    '        };',
    '        for (int i = 0; i < 26; ++i)',
    '            if (rules::asRowLo(i) != kLo[i] ||',
    '                rules::asRowHi(i) != kHi[i] ||',
    '                rules::asXpValue(i) != kXp[i] ||',
    '                rules::asSaleGp(i) != kGp[i])',
    '                ++bad;',
    '        for (int i = 1; i < 26; ++i)',
    '            if (rules::asRowLo(i) !=',
    '                rules::asRowHi(i - 1) + 1) ++bad;',
    '        if (rules::asRowLo(-5) != 1 ||',
    '            rules::asRowHi(99) != 100) ++bad;',
    '        // the printed values: Chain Mail +1,',
    '        // Leather Armor +1, Plate Mail of',
    '        // Etherealness, Shield +5 and the',
    '        // large missile Shield',
    '        if (rules::asXpValue(0) != 600 ||',
    '            rules::asSaleGp(0) != 3500) ++bad;',
    '        if (rules::asXpValue(3) != 300 ||',
    '            rules::asSaleGp(3) != 2000) ++bad;',
    '        if (rules::asXpValue(9) != 5000 ||',
    '            rules::asSaleGp(9) != 30000) ++bad;',
    '        if (rules::asXpValue(23) != 1750 ||',
    '            rules::asSaleGp(23) != 17500) ++bad;',
    '        if (rules::asXpValue(24) != 400 ||',
    '            rules::asSaleGp(24) != 4000) ++bad;',
    '        // the TWO cursed no-x.p. rows: the',
    '        // Plate Mail of Vulnerability and the',
    '        // Shield -1 missile attractor',
    '        if (rules::asXpValue(10) != 0 ||',
    '            rules::asSaleGp(10) != 1500 ||',
    '            rules::asXpValue(25) != 0 ||',
    '            rules::asSaleGp(25) != 750 ||',
    '            rules::asNoXpCount() != 2) ++bad;',
    '        // the missile attractor rides the 98-00',
    '        // band - pinned as 98 through 100',
    '        if (rules::asRowLo(25) != 98 ||',
    '            rules::asRowHi(25) != 100) ++bad;',
    '        // the armor SIZE footnote: 65/20/10/5',
    '        // sums to 100',
    '        if (rules::asManSizedPct() != 65 ||',
    '            rules::asElfSizedPct() != 20 ||',
    '            rules::asDwarfSizedPct() != 10 ||',
    '            rules::asSmallUserPct() != 5) ++bad;',
    '        if (rules::asManSizedPct() +',
    '            rules::asElfSizedPct() +',
    '            rules::asDwarfSizedPct() +',
    '            rules::asSmallUserPct() != 100) ++bad;',
    '        // clamped reads land on Chain Mail +1',
    '        // below and the missile attractor above',
    '        if (rules::asSaleGp(-99) != 3500 ||',
    '            rules::asSaleGp(99) != 750 ||',
    '            rules::asXpValue(-99) != 600 ||',
    '            rules::asXpValue(99) != 0) ++bad;',
    '        printf("R241 armor and shield pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'lines ~9902+), or the next un-pinned',
    'III.A-H surrounding prose seam.',
]
gap_new = [
    'lines ~9902+), or the next un-pinned',
    'III.A-H surrounding prose seam.',
    '',
    'R241 landed the III.F armor and shield',
    'pins (DMG p.129-130, upload lines',
    '~9870-9902, the RIGHT column of the',
    'two-column layout). rules/armorshield.h',
    '(the grenade.h pattern, as prefix):',
    '26 rows in kArmor order, Chain Mail +1',
    '01-05 through Shield -1 missile',
    'attractor 98-00 (band 100) - the x.p.',
    'point values and the g.p. sale values',
    'of every row (asXpValue, asSaleGp);',
    'the TWO cursed no-x.p. rows - Plate',
    'Mail of Vulnerability 40-44 and Shield',
    '-1 missile attractor 98-00 print ---',
    '(asNoXpCount 2, the R240 no-x.p.',
    'convention on just two rows); and the',
    'armor SIZE footnote: 65% of all armor',
    'is man-sized, 20% elf-sized, 10%',
    'dwarf-sized, 5% gnome or halfling',
    'sized (asManSizedPct, asElfSizedPct,',
    'asDwarfSizedPct, asSmallUserPct - sum',
    '100). NO class marks, asterisks or',
    'dual-value rows ride this table. The',
    'row NAMES were already pinned by the',
    'R122 line-diff audit; this round pins',
    'the values, band edges and the size',
    'footnote. New R241 battery audit;',
    'census 160. Next: R242 - the III.G',
    'swords table pins (DMG p.131; the',
    'sword size note: 70% longswords, 20%',
    'broadswords, 5% short swords, 4%',
    'bastard swords, 1% two-handed; the',
    'three cursed swords print --- g.p.',
    'sale values, upload lines ~9917+), or',
    'the next un-pinned III.A-H',
    'surrounding prose seam.',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson)
marker = 'R241: the III.F armor and shield pins'
try:
    t = open(ASH).read()
    if marker in t:
        already += 1
    else:
        print('R241 FAIL: rules/armorshield.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(ASH, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R241 audit', audit_old, audit_new),
    (GAP, 'the R241 log entry', gap_old, gap_new),
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
        print('R241 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 160:
        print('R241 FAIL: census is not 160')
        sys.exit(1)
    if t.count('R241 armor and shield pins audit') != 1:
        print('R241 FAIL: the R241 audit line must appear once')
        sys.exit(1)
    if t.count('rules/armorshield.h') != 1:
        print('R241 FAIL: the armorshield include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R241 landed the III.F armor and shield') != 1:
        print('R241 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(ASH).read()
    if 'namespace rules' not in h or h.count('inline int as') != 10:
        print('R241 FAIL: the header shape is wrong')
        sys.exit(1)

print('R241 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R241 note: 4 patches; the III.F armor and shield pins landed -')
print('the values and the armor size footnote; census 160.')
print('commit: R241: the III.F armor and shield pins pinned - DMG p.129-130, the values and the armor size footnote (census 160)')

