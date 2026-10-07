#!/usr/bin/env python3
# R242 splice: the III.G swords pins.
#
# DMG p.131, upload lines ~9906-9947 (the RIGHT column
# of the two-column print) - the magic swords table:
# 26 rows in kSwords order, Sword +1 01-25 through
# Sword, Cursed Berserking 96-00 (band 100); the x.p.
# point values and g.p. sale values of every row; the
# THREE cursed swords print --- g.p. sale values
# (Sword +1 Cursed, Sword -2 Cursed, Cursed Berserking
# - pinned as 0); the sword SIZE note: 70% longswords,
# 20% broadswords, 5% short (small) swords, 4% bastard
# swords, 1% two-handed (sum 100); and the TWO
# tiered-bonus wrapped rows: the Flame Tongue +2 vs.
# regenerating, +3 vs. cold-using/inflammable/avian, +4
# vs. undead, and the Frost Brand +6 vs. fire
# using/dwelling. NO class marks or asterisks ride
# this table. The row NAMES were already pinned by the
# R122 line-diff audit; this round pins the values,
# band edges, the size note and the tiered bonuses.
# Patches: 4 (new rules/swords.h, the regtest
# include, the audit block, the dmg-gap-report log
# entry). Census 160 -> 161.
#
# commit: R242: the III.G swords pins pinned - DMG p.131, the values, the size note and the tiered bonuses (census 161)

import sys

SW   = 'rules/swords.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 160 and t.count('audit: bad ') != 161:
    print('R242 FAIL: regtest census is neither 160 nor 161')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/swords.h',
    '// R242: the III.G swords pins',
    '// (DMG p.131) - the magic swords table (the',
    '// RIGHT column of the two-column print):',
    '//   - 26 rows, Sword +1 01-25 through',
    '//     Sword, Cursed Berserking 96-00 (the',
    '//     00 band pins as 100).',
    '//   - the x.p. point values and the g.p.',
    '//     sale values of every row.',
    '//   - the THREE cursed swords print --- g.p.',
    '//     sale values: Sword +1 Cursed 86-90,',
    '//     Sword -2 Cursed 91-95 and Sword,',
    '//     Cursed Berserking 96-00 (pinned as 0',
    '//     g.p.).',
    '//   - the sword SIZE note: 70% of swords are',
    '//     longswords, 20% broadswords, 5% short',
    '//     (small) swords, 4% bastard swords, 1%',
    '//     two-handed swords (sum 100).',
    '//   - the TWO tiered-bonus wrapped rows: the',
    '//     Flame Tongue 46-49 is +2 vs.',
    '//     regenerating, +3 vs. cold-using,',
    '//     inflammable or avian, +4 vs. undead;',
    '//     the Frost Brand 72-74 is +6 vs. fire',
    '//     using/dwelling.',
    '// NO class marks or asterisks ride this',
    '// table (the no-x.p. footnote after the',
    '// table belongs to the III.E Special table,',
    '// pinned R240).',
    '// The row identity is the 26 die bands of',
    '// the engine III.G table (dm/treasure.cpp',
    '// kSwords order). The row NAMES were pinned',
    '// by the R122 line-diff audit; this header',
    '// pins the values, band edges, the size',
    '// note and the tiered bonuses.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int swRowCount() {',
    '    // Sword +1 through the Cursed Berserking',
    '    return 26;',
    '}',
    '',
    'inline int swRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 25) i = 25;',
    '    static const int t[26] = {',
    '        1, 26, 31, 36, 41, 46, 50, 51, 59,',
    '        63, 67, 68, 72, 75, 77, 78, 79, 80,',
    '        81, 82, 83, 84, 85, 86, 91, 96,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int swRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 25) i = 25;',
    '    static const int t[26] = {',
    '        25, 30, 35, 40, 45, 49, 50, 58, 62,',
    '        66, 67, 71, 74, 76, 77, 78, 79, 80,',
    '        81, 82, 83, 84, 85, 90, 95, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int swXpValue(int i) {',
    '    // the x.p. point values; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 25) i = 25;',
    '    static const int t[26] = {',
    '        400, 600, 700, 800, 800, 900, 1000, 800, 900,',
    '        900, 1600, 1400, 1600, 2000, 3000, 3000, 3600, 4000,',
    '        4400, 4400, 5000, 7000, 10000, 400, 600, 900,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int swSaleGp(int i) {',
    '    // the g.p. sale values; the cursed rows are 0; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 25) i = 25;',
    '    static const int t[26] = {',
    '        2000, 3000, 3500, 4000, 4000, 4500, 5000, 4000, 4500,',
    '        4500, 8000, 7000, 8000, 10000, 15000, 15000, 18000, 20000,',
    '        22000, 22000, 25000, 35000, 50000, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int swNoSaleCount() {',
    '    // the three cursed swords print --- g.p.',
    '    return 3;',
    '}',
    '',
    'inline int swLongswordPct() {',
    '    // 70% of swords are longswords',
    '    return 70;',
    '}',
    '',
    'inline int swBroadswordPct() {',
    '    // 20% are broadswords',
    '    return 20;',
    '}',
    '',
    'inline int swShortswordPct() {',
    '    // 5% are short (small) swords',
    '    return 5;',
    '}',
    '',
    'inline int swBastardPct() {',
    '    // 4% are bastard swords',
    '    return 4;',
    '}',
    '',
    'inline int swTwoHandedPct() {',
    '    // 1% are two-handed swords',
    '    return 1;',
    '}',
    '',
    'inline int swFlameVsRegenBonus() {',
    '    // Flame Tongue: +2 vs. regenerating creatures',
    '    return 2;',
    '}',
    '',
    'inline int swFlameVsColdAvianBonus() {',
    '    // Flame Tongue: +3 vs. cold-using, inflammable or avian',
    '    return 3;',
    '}',
    '',
    'inline int swFlameVsUndeadBonus() {',
    '    // Flame Tongue: +4 vs. undead',
    '    return 4;',
    '}',
    '',
    'inline int swFrostVsFireBonus() {',
    '    // Frost Brand: +6 vs. fire using/dwelling creatures',
    '    return 6;',
    '}',
    '',
    '}  // namespace rules',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/armorshield.h"  // R241: p.129-130 the III.F armor and shield pins',
]
inc_new = [
    '#include "rules/armorshield.h"  // R241: p.129-130 the III.F armor and shield pins',
    '#include "rules/swords.h"  // R242: p.131 the III.G swords pins',
]

# ---- the R242 audit block ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R242: the III.G swords pins audit ----',
    '    // DMG p.131: the magic swords table - the 26',
    '    // rows, the three cursed no-sale rows, the',
    '    // size note and the tiered bonuses.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 26 die bands',
    '        if (rules::swRowCount() != 26) ++bad;',
    '        static const int kLo[26] = {',
    '            1, 26, 31, 36, 41, 46, 50, 51, 59,',
    '            63, 67, 68, 72, 75, 77, 78, 79, 80,',
    '            81, 82, 83, 84, 85, 86, 91, 96,',
    '        };',
    '        static const int kHi[26] = {',
    '            25, 30, 35, 40, 45, 49, 50, 58, 62,',
    '            66, 67, 71, 74, 76, 77, 78, 79, 80,',
    '            81, 82, 83, 84, 85, 90, 95, 100,',
    '        };',
    '        static const int kXp[26] = {',
    '            400, 600, 700, 800, 800, 900, 1000, 800, 900,',
    '            900, 1600, 1400, 1600, 2000, 3000, 3000, 3600, 4000,',
    '            4400, 4400, 5000, 7000, 10000, 400, 600, 900,',
    '        };',
    '        static const int kGp[26] = {',
    '            2000, 3000, 3500, 4000, 4000, 4500, 5000, 4000, 4500,',
    '            4500, 8000, 7000, 8000, 10000, 15000, 15000, 18000, 20000,',
    '            22000, 22000, 25000, 35000, 50000, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 26; ++i)',
    '            if (rules::swRowLo(i) != kLo[i] ||',
    '                rules::swRowHi(i) != kHi[i] ||',
    '                rules::swXpValue(i) != kXp[i] ||',
    '                rules::swSaleGp(i) != kGp[i])',
    '                ++bad;',
    '        for (int i = 1; i < 26; ++i)',
    '            if (rules::swRowLo(i) !=',
    '                rules::swRowHi(i - 1) + 1) ++bad;',
    '        if (rules::swRowLo(-5) != 1 ||',
    '            rules::swRowHi(99) != 100) ++bad;',
    '        // the printed values: Sword +1, Luck',
    '        // Blade, Nine Lives Stealer, Holy',
    '        // Avenger and the Vorpal Weapon',
    '        if (rules::swXpValue(0) != 400 ||',
    '            rules::swSaleGp(0) != 2000) ++bad;',
    '        if (rules::swXpValue(6) != 1000 ||',
    '            rules::swSaleGp(6) != 5000) ++bad;',
    '        if (rules::swXpValue(10) != 1600 ||',
    '            rules::swSaleGp(10) != 8000) ++bad;',
    '        if (rules::swXpValue(17) != 4000 ||',
    '            rules::swSaleGp(17) != 20000) ++bad;',
    '        if (rules::swXpValue(22) != 10000 ||',
    '            rules::swSaleGp(22) != 50000) ++bad;',
    '        // the THREE cursed swords print --- g.p.',
    '        // sale values: +1 Cursed, -2 Cursed and',
    '        // the Berserking (rows 23, 24, 25)',
    '        if (rules::swXpValue(23) != 400 ||',
    '            rules::swSaleGp(23) != 0 ||',
    '            rules::swXpValue(24) != 600 ||',
    '            rules::swSaleGp(24) != 0 ||',
    '            rules::swXpValue(25) != 900 ||',
    '            rules::swSaleGp(25) != 0 ||',
    '            rules::swNoSaleCount() != 3) ++bad;',
    '        // the Berserking rides the 96-00 band -',
    '        // pinned as 96 through 100',
    '        if (rules::swRowLo(25) != 96 ||',
    '            rules::swRowHi(25) != 100) ++bad;',
    '        // the sword SIZE note: 70/20/5/4/1 sums',
    '        // to 100',
    '        if (rules::swLongswordPct() != 70 ||',
    '            rules::swBroadswordPct() != 20 ||',
    '            rules::swShortswordPct() != 5 ||',
    '            rules::swBastardPct() != 4 ||',
    '            rules::swTwoHandedPct() != 1) ++bad;',
    '        if (rules::swLongswordPct() +',
    '            rules::swBroadswordPct() +',
    '            rules::swShortswordPct() +',
    '            rules::swBastardPct() +',
    '            rules::swTwoHandedPct() != 100) ++bad;',
    '        // the tiered bonuses: the Flame Tongue',
    '        // ladder 2/3/4 and the Frost Brand +6',
    '        if (rules::swFlameVsRegenBonus() != 2 ||',
    '            rules::swFlameVsColdAvianBonus() != 3 ||',
    '            rules::swFlameVsUndeadBonus() != 4 ||',
    '            rules::swFrostVsFireBonus() != 6) ++bad;',
    '        if (rules::swFlameVsRegenBonus() *',
    '            rules::swFlameVsColdAvianBonus() -',
    '            rules::swFlameVsRegenBonus() !=',
    '            rules::swFlameVsUndeadBonus()) ++bad;',
    '        // clamped reads land on Sword +1 below',
    '        // and the Cursed Berserking above',
    '        if (rules::swSaleGp(-99) != 2000 ||',
    '            rules::swSaleGp(99) != 0 ||',
    '            rules::swXpValue(-99) != 400 ||',
    '            rules::swXpValue(99) != 900) ++bad;',
    '        printf("R242 swords pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'sale values, upload lines ~9917+), or',
    'the next un-pinned III.A-H',
    'surrounding prose seam.',
]
gap_new = [
    'sale values, upload lines ~9917+), or',
    'the next un-pinned III.A-H',
    'surrounding prose seam.',
    '',
    'R242 landed the III.G swords pins (DMG',
    'p.131, upload lines ~9906-9947, the',
    'RIGHT column of the two-column print).',
    'rules/swords.h (the grenade.h pattern,',
    'sw prefix): 26 rows in kSwords order,',
    'Sword +1 01-25 through Sword, Cursed',
    'Berserking 96-00 (band 100) - the x.p.',
    'point values and g.p. sale values of',
    'every row (swXpValue, swSaleGp); the',
    'THREE cursed swords print --- g.p.',
    'sale values (Sword +1 Cursed 86-90,',
    'Sword -2 Cursed 91-95, Sword, Cursed',
    'Berserking 96-00 - swNoSaleCount 3,',
    'pinned as 0 g.p.); the sword SIZE',
    'note: 70% longswords, 20% broadswords,',
    '5% short (small) swords, 4% bastard',
    'swords, 1% two-handed (swLongswordPct',
    'etc., sum 100); and the TWO',
    'tiered-bonus wrapped rows: the Flame',
    'Tongue +2 vs. regenerating, +3 vs.',
    'cold-using/inflammable/avian, +4 vs.',
    'undead, the Frost Brand +6 vs. fire',
    'using/dwelling (swFlameVsRegenBonus',
    'etc.). NO class marks or asterisks',
    'ride this table; the no-x.p. footnote',
    'after it belongs to the III.E Special',
    'table (pinned R240). The row NAMES',
    'were already pinned by the R122',
    'line-diff audit; this round pins the',
    'values, band edges, the size note and',
    'the tiered bonuses. New R242 battery',
    'audit; census 161. Next: R243 - the',
    'III.H misc weapons table pins (DMG',
    'p.131-132; the quantity ranges ride',
    'the arrow/bolt rows, upload lines',
    '~9949+), or the next un-pinned III.A-H',
    'surrounding prose seam.',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson)
marker = 'R242: the III.G swords pins'
try:
    t = open(SW).read()
    if marker in t:
        already += 1
    else:
        print('R242 FAIL: rules/swords.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(SW, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R242 audit', audit_old, audit_new),
    (GAP, 'the R242 log entry', gap_old, gap_new),
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
        print('R242 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 161:
        print('R242 FAIL: census is not 161')
        sys.exit(1)
    if t.count('R242 swords pins audit') != 1:
        print('R242 FAIL: the R242 audit line must appear once')
        sys.exit(1)
    if t.count('rules/swords.h') != 1:
        print('R242 FAIL: the swords include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R242 landed the III.G swords pins') != 1:
        print('R242 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(SW).read()
    if 'namespace rules' not in h or h.count('inline int sw') != 15:
        print('R242 FAIL: the header shape is wrong')
        sys.exit(1)

print('R242 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R242 note: 4 patches; the III.G swords pins landed -')
print('the values, the size note and the tiered bonuses; census 161.')
print('commit: R242: the III.G swords pins pinned - DMG p.131, the values, the size note and the tiered bonuses (census 161)')

