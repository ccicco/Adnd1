#!/usr/bin/env python3
# R243 splice: the III.H misc weapons pins.
#
# DMG p.131-132, upload lines ~9949-9987 - the
# miscellaneous weapons table, the LAST of the III.A-H
# magic item tables: 36 rows in kWeapons order (Arrow +1
# 01-08 through Trident (Military Fork) +3 00, band
# 100); the x.p. point values and g.p. sale values of
# every row; the FOUR ammo quantity ranges printed as
# the ", N-M in number" suffixes (Arrow +1 2-24, Arrow
# +2 2-16, Arrow +3 2-12, Bolt +2 2-20 - the 0,0 cells
# mean a single item); the TWO duplicate Hammer +2 rows
# (57-60 at 300/2,500 and 61-62 at 650/6,000 - both
# printed verbatim, Curtiss-verified against p.125);
# and the cursed Spear, Cursed Backbiter 98-99 prints
# --- x.p. (pinned as 0). NO class marks or asterisks
# ride this table. The row NAMES were already pinned by
# the R122 line-diff audit; this round pins the values,
# band edges and the quantity ranges.
# Patches: 4 (new rules/mweapons.h, the regtest
# include, the audit block, the dmg-gap-report log
# entry). Census 161 -> 162.
#
# commit: R243: the III.H misc weapons pins pinned - DMG p.131-132, the values and the ammo quantity ranges (census 162)

import sys

MW   = 'rules/mweapons.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 161 and t.count('audit: bad ') != 162:
    print('R243 FAIL: regtest census is neither 161 nor 162')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/mweapons.h',
    '// R243: the III.H misc weapons pins',
    '// (DMG p.131-132) - the miscellaneous',
    '// weapons table, the LAST of the III.A-H',
    '// magic item tables:',
    '//   - 36 rows, Arrow +1 01-08 through',
    '//     Trident (Military Fork) +3 00 (the',
    '//     00 band pins as 100).',
    '//   - the x.p. point values and the g.p.',
    '//     sale values of every row.',
    '//   - the FOUR ammo quantity ranges,',
    '//     printed as the ", N-M in number"',
    '//     suffixes: Arrow +1 2-24, Arrow +2',
    '//     2-16, Arrow +3 2-12, Bolt +2 2-20',
    '//     (a 0/0 cell means a single item).',
    '//   - the TWO duplicate Hammer +2 rows:',
    '//     57-60 prints 300 x.p./2,500 g.p. and',
    '//     61-62 prints 650 x.p./6,000 g.p. -',
    '//     both printed verbatim in the book',
    '//     (Curtiss-verified against p.125).',
    '//   - the cursed Spear, Cursed Backbiter',
    '//     98-99 prints --- x.p. (pinned as 0).',
    '// NO class marks or asterisks ride this',
    '// table.',
    '// The row identity is the 36 die bands of',
    '// the engine III.H table (dm/treasure.cpp',
    '// kWeapons order). The row NAMES were',
    '// pinned by the R122 line-diff audit; this',
    '// header pins the values, band edges and',
    '// the quantity ranges.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int mwRowCount() {',
    '    // Arrow +1 through the Trident (Military Fork)',
    '    return 36;',
    '}',
    '',
    'inline int mwRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        1, 9, 13, 15, 16, 21, 23, 24, 25, 28, 33, 36,',
    '        37, 38, 39, 47, 51, 52, 57, 61, 63, 64, 65, 68,',
    '        73, 76, 77, 78, 81, 84, 89, 90, 95, 97, 98, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mwRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        8, 12, 14, 15, 20, 22, 23, 24, 27, 32, 35, 36,',
    '        37, 38, 46, 50, 51, 56, 60, 62, 63, 64, 67, 72,',
    '        75, 76, 77, 80, 83, 88, 89, 94, 96, 97, 99, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mwXpValue(int i) {',
    '    // the x.p. point values; the Backbiter is 0; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        20, 50, 75, 250, 300, 600, 750, 1000, 400, 50, 500, 2000,',
    '        1500, 1500, 100, 250, 350, 450, 300, 650, 1500, 2500, 750, 350,',
    '        700, 1750, 1500, 350, 400, 750, 700, 500, 1000, 1750, 0, 1500,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mwSaleGp(int i) {',
    '    // the g.p. sale values; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        120, 300, 450, 2500, 1750, 3750, 4500, 7000, 2500, 300, 3500, 12000,',
    '        7500, 7500, 750, 2000, 3000, 4000, 2500, 6000, 15000, 25000, 5000, 3000,',
    '        4500, 17500, 15000, 2500, 3000, 6000, 7000, 3000, 6500, 15000, 1000, 12500,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mwQtyLo(int i) {',
    '    // the ammo quantity lower bounds; 0 = a single item; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mwQtyHi(int i) {',
    '    // the ammo quantity upper bounds; 0 = a single item; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        24, 16, 12, 0, 0, 0, 0, 0, 0, 20, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mwQtyRangeCount() {',
    '    // the three Arrows and the Bolt',
    '    return 4;',
    '}',
    '',
    'inline int mwNoXpCount() {',
    '    // the cursed Backbiter prints --- x.p.',
    '    return 1;',
    '}',
    '',
    'inline int mwDuplicateNameCount() {',
    '    // the two Hammer +2 rows (Curtiss-verified p.125)',
    '    return 2;',
    '}',
    '',
    '}  // namespace rules',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/swords.h"  // R242: p.131 the III.G swords pins',
]
inc_new = [
    '#include "rules/swords.h"  // R242: p.131 the III.G swords pins',
    '#include "rules/mweapons.h"  // R243: p.131-132 the III.H misc weapons pins',
]

# ---- the R243 audit block ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R243: the III.H misc weapons pins audit ----',
    '    // DMG p.131-132: the miscellaneous weapons',
    '    // table - the 36 rows, the ammo quantity',
    '    // ranges and the duplicate Hammer +2 rows.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 36 die bands',
    '        if (rules::mwRowCount() != 36) ++bad;',
    '        static const int kLo[36] = {',
    '            1, 9, 13, 15, 16, 21, 23, 24, 25, 28, 33, 36,',
    '            37, 38, 39, 47, 51, 52, 57, 61, 63, 64, 65, 68,',
    '            73, 76, 77, 78, 81, 84, 89, 90, 95, 97, 98, 100,',
    '        };',
    '        static const int kHi[36] = {',
    '            8, 12, 14, 15, 20, 22, 23, 24, 27, 32, 35, 36,',
    '            37, 38, 46, 50, 51, 56, 60, 62, 63, 64, 67, 72,',
    '            75, 76, 77, 80, 83, 88, 89, 94, 96, 97, 99, 100,',
    '        };',
    '        static const int kXp[36] = {',
    '            20, 50, 75, 250, 300, 600, 750, 1000, 400, 50, 500, 2000,',
    '            1500, 1500, 100, 250, 350, 450, 300, 650, 1500, 2500, 750, 350,',
    '            700, 1750, 1500, 350, 400, 750, 700, 500, 1000, 1750, 0, 1500,',
    '        };',
    '        static const int kGp[36] = {',
    '            120, 300, 450, 2500, 1750, 3750, 4500, 7000, 2500, 300, 3500, 12000,',
    '            7500, 7500, 750, 2000, 3000, 4000, 2500, 6000, 15000, 25000, 5000, 3000,',
    '            4500, 17500, 15000, 2500, 3000, 6000, 7000, 3000, 6500, 15000, 1000, 12500,',
    '        };',
    '        static const int kQlo[36] = {',
    '            2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kQhi[36] = {',
    '            24, 16, 12, 0, 0, 0, 0, 0, 0, 20, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 36; ++i)',
    '            if (rules::mwRowLo(i) != kLo[i] ||',
    '                rules::mwRowHi(i) != kHi[i] ||',
    '                rules::mwXpValue(i) != kXp[i] ||',
    '                rules::mwSaleGp(i) != kGp[i] ||',
    '                rules::mwQtyLo(i) != kQlo[i] ||',
    '                rules::mwQtyHi(i) != kQhi[i])',
    '                ++bad;',
    '        for (int i = 1; i < 36; ++i)',
    '            if (rules::mwRowLo(i) !=',
    '                rules::mwRowHi(i - 1) + 1) ++bad;',
    '        if (rules::mwRowLo(-5) != 1 ||',
    '            rules::mwRowHi(99) != 100) ++bad;',
    '        // the printed values: the Arrow of',
    '        // Slaying, the Crossbow of Speed, the',
    '        // Dagger of Venom, the Hammer of',
    '        // Thunderbolts, the Mace of Disruption',
    '        // and the Trident (Military Fork)',
    '        if (rules::mwXpValue(3) != 250 ||',
    '            rules::mwSaleGp(3) != 2500) ++bad;',
    '        if (rules::mwXpValue(13) != 1500 ||',
    '            rules::mwSaleGp(13) != 7500) ++bad;',
    '        if (rules::mwXpValue(16) != 350 ||',
    '            rules::mwSaleGp(16) != 3000) ++bad;',
    '        if (rules::mwXpValue(21) != 2500 ||',
    '            rules::mwSaleGp(21) != 25000) ++bad;',
    '        if (rules::mwXpValue(25) != 1750 ||',
    '            rules::mwSaleGp(25) != 17500) ++bad;',
    '        if (rules::mwXpValue(35) != 1500 ||',
    '            rules::mwSaleGp(35) != 12500) ++bad;',
    '        // the FOUR ammo quantity ranges: the',
    '        // three Arrows 2-24/2-16/2-12 and the',
    '        // Bolt 2-20 (0/0 means a single item)',
    '        if (rules::mwQtyLo(0) != 2 ||',
    '            rules::mwQtyHi(0) != 24 ||',
    '            rules::mwQtyLo(1) != 2 ||',
    '            rules::mwQtyHi(1) != 16 ||',
    '            rules::mwQtyLo(2) != 2 ||',
    '            rules::mwQtyHi(2) != 12 ||',
    '            rules::mwQtyLo(9) != 2 ||',
    '            rules::mwQtyHi(9) != 20 ||',
    '            rules::mwQtyRangeCount() != 4) ++bad;',
    '        if (rules::mwQtyLo(5) != 0 ||',
    '            rules::mwQtyHi(5) != 0 ||',
    '            rules::mwQtyLo(35) != 0 ||',
    '            rules::mwQtyHi(35) != 0) ++bad;',
    '        // the TWO duplicate Hammer +2 rows: the',
    '        // book prints the name twice with',
    '        // different values (p.125)',
    '        if (rules::mwXpValue(18) != 300 ||',
    '            rules::mwSaleGp(18) != 2500 ||',
    '            rules::mwXpValue(19) != 650 ||',
    '            rules::mwSaleGp(19) != 6000 ||',
    '            rules::mwDuplicateNameCount() != 2) ++bad;',
    '        // the cursed Backbiter prints --- x.p.',
    '        if (rules::mwXpValue(34) != 0 ||',
    '            rules::mwSaleGp(34) != 1000 ||',
    '            rules::mwNoXpCount() != 1) ++bad;',
    '        // the Trident (Military Fork) rides the',
    '        // 00 band - pinned as 100',
    '        if (rules::mwRowLo(35) != 100 ||',
    '            rules::mwRowHi(35) != 100) ++bad;',
    '        // clamped reads land on the Arrow +1',
    '        // below and the Trident above',
    '        if (rules::mwSaleGp(-99) != 120 ||',
    '            rules::mwSaleGp(99) != 12500 ||',
    '            rules::mwQtyLo(-99) != 2 ||',
    '            rules::mwQtyHi(99) != 0) ++bad;',
    '        printf("R243 misc weapons pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'the arrow/bolt rows, upload lines',
    '~9949+), or the next un-pinned III.A-H',
    'surrounding prose seam.',
]
gap_new = [
    'the arrow/bolt rows, upload lines',
    '~9949+), or the next un-pinned III.A-H',
    'surrounding prose seam.',
    '',
    'R243 landed the III.H misc weapons pins',
    '(DMG p.131-132, upload lines ~9949-9987)',
    '- the miscellaneous weapons table, the',
    'LAST of the III.A-H magic item tables.',
    'rules/mweapons.h (the grenade.h pattern,',
    'mw prefix): 36 rows in kWeapons order,',
    'Arrow +1 01-08 through Trident (Military',
    'Fork) +3 00 (band 100) - the x.p. point',
    'values and g.p. sale values of every row',
    '(mwXpValue, mwSaleGp); the FOUR ammo',
    'quantity ranges printed as the N-M in',
    'number suffixes (Arrow +1 2-24, Arrow +2',
    '2-16, Arrow +3 2-12, Bolt +2 2-20 -',
    'mwQtyLo/mwQtyHi, the 0/0 cells mean a',
    'single item, mwQtyRangeCount 4); the TWO',
    'duplicate Hammer +2 rows (57-60 at',
    '300/2,500 and 61-62 at 650/6,000, both',
    'printed verbatim, Curtiss-verified',
    'against p.125 - mwDuplicateNameCount 2);',
    'and the cursed Spear, Cursed Backbiter',
    '98-99 prints --- x.p. (mwNoXpCount 1).',
    'NO class marks or asterisks ride this',
    'table. The row NAMES were already',
    'pinned by the R122 line-diff audit; this',
    'round pins the values, band edges and',
    'the quantity ranges. New R243 battery',
    'audit; census 162. MILESTONE: the whole',
    'III.A-H magic item table block is now',
    'fully pinned (potions, scrolls, rings,',
    'rods/staves/wands, misc tables 1-5, the',
    'Special artifacts, armor and shields,',
    'swords and misc weapons). Next: R244 -',
    'the next un-pinned III.A-H surrounding',
    'prose seam (the EXPLANATIONS AND',
    'DESCRIPTIONS prose that follows the',
    'tables, upload lines ~9995+; the potions',
    'prose was pinned R221, the scrolls prose',
    'R222, the rings footnotes R223 - the',
    'candidate seams are the rods/staves/',
    'wands and misc item explanation prose),',
    'or the next ranked gap.',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson)
marker = 'R243: the III.H misc weapons pins'
try:
    t = open(MW).read()
    if marker in t:
        already += 1
    else:
        print('R243 FAIL: rules/mweapons.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(MW, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R243 audit', audit_old, audit_new),
    (GAP, 'the R243 log entry', gap_old, gap_new),
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
        print('R243 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 162:
        print('R243 FAIL: census is not 162')
        sys.exit(1)
    if t.count('R243 misc weapons pins audit') != 1:
        print('R243 FAIL: the R243 audit line must appear once')
        sys.exit(1)
    if t.count('rules/mweapons.h') != 1:
        print('R243 FAIL: the mweapons include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R243 landed the III.H misc weapons pins') != 1:
        print('R243 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(MW).read()
    if 'namespace rules' not in h or h.count('inline int mw') != 10:
        print('R243 FAIL: the header shape is wrong')
        sys.exit(1)

print('R243 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R243 note: 4 patches; the III.H misc weapons pins landed -')
print('the values and the ammo quantity ranges; the III.A-H magic')
print('item table block is COMPLETE; census 162.')
print('commit: R243: the III.H misc weapons pins pinned - DMG p.131-132, the values and the ammo quantity ranges (census 162)')

