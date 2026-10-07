#!/usr/bin/env python3
# R237 splice: the III.E table 3 footnote pins.
#
# DMG p.129, upload lines ~9765-9825 - the class
# marks and the asterisk ladder that frame TABLE
# (III.E.) 3: the (C, F, T) Gauntlets and Girdles,
# the (C, F) Horn of the Tritons, the (C)
# Incenses, the (F) Javelins (NO (M) rows ride
# this table); the Figurine of Wondrous Power
# single star (100 x.p. / 1,000 g.p. per hit die
# of the figurine), the Horn of Valhalla double
# star (double for a bronze horn, triple for an
# iron horn), the Ioun Stones triple star (per
# stone), the Instrument of the Bards quadruple
# star (per level of instrument for bards - the
# fourth footnote the book upload DROPS, restored
# from the 1eonline.info compilation, the R175
# precedent), and the Jewel of Flawlessness
# per-facet row. Keyed to the 33 die bands of
# the engine III.E.3 table; the row VALUES were
# already pinned by R122.
# Patches: 4 (new rules/miscmagic3.h, the
# regtest include, the audit block, the
# dmg-gap-report log entry). Census 155 -> 156.
#
# commit: R237: the III.E table 3 footnote pins pinned - DMG p.129, the class marks and the asterisk ladder (census 156)

import sys

MM3  = 'rules/miscmagic3.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson)
t = open(REG).read()
if t.count('audit: bad ') != 155 and t.count('audit: bad ') != 156:
    print('R237 FAIL: regtest census is neither 155 nor 156')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/miscmagic3.h',
    '// R237: the III.E table 3 footnote pins',
    '// (DMG p.129) - the class marks and the',
    '// asterisk ladder that frame TABLE',
    '// (III.E.) 3 of the miscellaneous magic',
    '// tables:',
    '//   - the (C, F, T) marks: the Gauntlets',
    '//     of Ogre Power (21-22), the Gauntlets',
    '//     of Swimming and Climbing (23-25),',
    '//     the Girdle of Femininity/',
    '//     Masculinity (28) and the Girdle of',
    '//     Giant Strength (29).',
    '//   - the (C, F) mark: the Horn of the',
    '//     Tritons (50-53).',
    '//   - the (C) marks: the Incense of',
    '//     Meditation (66-70) and the Incense',
    '//     of Obsession (71).',
    '//   - the (F) marks: the Javelin of',
    '//     Lightning (81-85) and the Javelin',
    '//     of Piercing (86-90).',
    '//   - NO (M) rows ride this table.',
    '//   - the Figurine of Wondrous Power',
    '//     single asterisk (01-15): the 100 x.p.',
    '//     / 1,000 g.p. values are PER HIT DIE',
    '//     of the figurine.',
    '//   - the Horn of Valhalla double',
    '//     asterisk (54-60): double for a',
    '//     bronze horn, triple for an iron horn',
    '//     (base 1,000 x.p. / 15,000 g.p.).',
    '//   - the Ioun Stones triple asterisk',
    '//     (72): per stone (300 x.p. / 5,000',
    '//     g.p.).',
    '//   - the Instrument of the Bards',
    '//     quadruple asterisk (73-78): PER LEVEL',
    '//     OF INSTRUMENT for bards (base 1,000',
    '//     x.p. / 5,000 g.p.) - the fourth',
    '//     footnote the book upload DROPS,',
    '//     restored from the 1eonline.info',
    '//     compilation (the R175 precedent).',
    '//   - the Jewel of Flawlessness (92): no',
    '//     x.p., 1,000 g.p. PER FACET.',
    '// The row identity is the 33 die bands of',
    '// the engine III.E.3 table (dm/treasure.cpp',
    '// kMisc3 order, Figurine of Wondrous Power',
    '// 01-15 through the 93-00 Ointment row).',
    '// The row VALUES were pinned by the R122',
    '// line-diff audit; this header pins the',
    '// class marks, the asterisk ladder and the',
    '// band edges.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int m3RowCount() {',
    '    // Figurine through the 93-00 Ointment',
    '    return 33;',
    '}',
    '',
    'inline int m3RowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        1, 16, 17, 19, 21, 23, 26, 27, 28, 29,',
    '        30, 31, 36, 38, 40, 41, 46, 47, 49, 50,',
    '        54, 61, 64, 66, 71, 72, 73, 79, 81, 86,',
    '        91, 92, 93,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m3RowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        15, 16, 18, 20, 22, 25, 26, 27, 28, 29,',
    '        30, 35, 37, 39, 40, 45, 46, 48, 49, 53,',
    '        60, 63, 65, 70, 71, 72, 78, 80, 85, 90,',
    '        91, 92, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m3UsableByCleric(int i) {',
    '    // the (C) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        0, 0, 0, 0, 1, 1, 0, 0, 1, 1,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '        0, 0, 0, 1, 1, 0, 0, 0, 0, 0,',
    '        0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m3UsableByFighter(int i) {',
    '    // the (F) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        0, 0, 0, 0, 1, 1, 0, 0, 1, 1,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 1, 1,',
    '        0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m3UsableByThief(int i) {',
    '    // the (T) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        0, 0, 0, 0, 1, 1, 0, 0, 1, 1,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m3StarCount(int i) {',
    '    // the asterisk ladder: 1 the Figurine',
    '    // (per hit die), 2 the Horn of Valhalla',
    '    // (bronze/iron), 3 the Ioun Stones (per',
    '    // stone), 4 the Instrument of the Bards',
    '    // (per level of instrument); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        2, 0, 0, 0, 0, 3, 4, 0, 0, 0,',
    '        0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m3IsPerFacetValued(int i) {',
    '    // the Jewel of Flawlessness (92): 1,000',
    '    // g.p. per facet; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 1, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m3ClericCount() {',
    '    return 7;',
    '}',
    '',
    'inline int m3FighterCount() {',
    '    return 7;',
    '}',
    '',
    'inline int m3ThiefCount() {',
    '    return 4;',
    '}',
    '',
    'inline int m3FigurinePerHitDieXp() {',
    '    // per hit die of the figurine',
    '    return 100;',
    '}',
    '',
    'inline int m3FigurinePerHitDieGp() {',
    '    return 1000;',
    '}',
    '',
    'inline int m3ValhallaBaseXp() {',
    '    return 1000;',
    '}',
    '',
    'inline int m3ValhallaBaseGp() {',
    '    return 15000;',
    '}',
    '',
    'inline int m3ValhallaBronzeMult() {',
    '    // double for a bronze horn',
    '    return 2;',
    '}',
    '',
    'inline int m3ValhallaIronMult() {',
    '    // triple for an iron horn',
    '    return 3;',
    '}',
    '',
    'inline int m3IounPerStoneXp() {',
    '    // per stone',
    '    return 300;',
    '}',
    '',
    'inline int m3IounPerStoneGp() {',
    '    return 5000;',
    '}',
    '',
    'inline int m3InstrumentBaseXp() {',
    '    // per level of instrument for bards',
    '    return 1000;',
    '}',
    '',
    'inline int m3InstrumentBaseGp() {',
    '    return 5000;',
    '}',
    '',
    'inline int m3JewelPerFacetGp() {',
    '    // no x.p., 1,000 g.p. per facet',
    '    return 1000;',
    '}',
    '',
    '}  // namespace rules',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/miscmagic2.h"  // R226: p.128 the misc table 2 pins',
]
inc_new = [
    '#include "rules/miscmagic2.h"  // R226: p.128 the misc table 2 pins',
    '#include "rules/miscmagic3.h"  // R237: p.129 the misc table 3 pins',
]

# ---- the R237 audit ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R237: the III.E table 3 pins audit ----',
    '    // DMG p.129: the class marks and the',
    '    // asterisk ladder of TABLE (III.E.) 3.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 33 die bands',
    '        if (rules::m3RowCount() != 33) ++bad;',
    '        static const int kLo[33] = {',
    '            1, 16, 17, 19, 21, 23, 26, 27, 28, 29,',
    '            30, 31, 36, 38, 40, 41, 46, 47, 49, 50,',
    '            54, 61, 64, 66, 71, 72, 73, 79, 81, 86,',
    '            91, 92, 93,',
    '        };',
    '        static const int kHi[33] = {',
    '            15, 16, 18, 20, 22, 25, 26, 27, 28, 29,',
    '            30, 35, 37, 39, 40, 45, 46, 48, 49, 53,',
    '            60, 63, 65, 70, 71, 72, 78, 80, 85, 90,',
    '            91, 92, 100,',
    '        };',
    '        static const int kC[33] = {',
    '            0, 0, 0, 0, 1, 1, 0, 0, 1, 1,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '            0, 0, 0, 1, 1, 0, 0, 0, 0, 0,',
    '            0, 0, 0,',
    '        };',
    '        static const int kF[33] = {',
    '            0, 0, 0, 0, 1, 1, 0, 0, 1, 1,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,',
    '            0, 0, 0,',
    '        };',
    '        static const int kT[33] = {',
    '            0, 0, 0, 0, 1, 1, 0, 0, 1, 1,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0,',
    '        };',
    '        static const int kStar[33] = {',
    '            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            2, 0, 0, 0, 0, 3, 4, 0, 0, 0,',
    '            0, 0, 0,',
    '        };',
    '        static const int kFacet[33] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 1, 0,',
    '        };',
    '        for (int i = 0; i < 33; ++i)',
    '            if (rules::m3RowLo(i) != kLo[i] ||',
    '                rules::m3RowHi(i) != kHi[i] ||',
    '                rules::m3UsableByCleric(i) != kC[i] ||',
    '                rules::m3UsableByFighter(i) != kF[i] ||',
    '                rules::m3UsableByThief(i) != kT[i] ||',
    '                rules::m3StarCount(i) != kStar[i] ||',
    '                rules::m3IsPerFacetValued(i) != kFacet[i])',
    '                ++bad;',
    '        for (int i = 1; i < 33; ++i)',
    '            if (rules::m3RowLo(i) !=',
    '                rules::m3RowHi(i - 1) + 1) ++bad;',
    '        if (rules::m3RowLo(-5) != 1 ||',
    '            rules::m3RowHi(99) != 100) ++bad;',
    '        // the class marks: the two Gauntlets and',
    '        // two Girdles are (C, F, T); the Horn of',
    '        // the Tritons is (C, F); the Incenses are',
    '        // (C); the Javelins are (F); NO (M) rows',
    '        // ride this table',
    '        if (rules::m3ClericCount() != 7 ||',
    '            rules::m3FighterCount() != 7 ||',
    '            rules::m3ThiefCount() != 4) ++bad;',
    '        if (!rules::m3UsableByCleric(4) ||',
    '            !rules::m3UsableByFighter(4) ||',
    '            !rules::m3UsableByThief(4)) ++bad;',
    '        if (rules::m3UsableByCleric(3) ||',
    '            rules::m3UsableByFighter(3) ||',
    '            rules::m3UsableByThief(3)) ++bad;',
    '        if (!rules::m3UsableByCleric(19) ||',
    '            !rules::m3UsableByFighter(19) ||',
    '            rules::m3UsableByThief(19)) ++bad;',
    '        if (!rules::m3UsableByCleric(23) ||',
    '            rules::m3UsableByFighter(23)) ++bad;',
    '        if (!rules::m3UsableByFighter(28) ||',
    '            !rules::m3UsableByFighter(29) ||',
    '            rules::m3UsableByCleric(28)) ++bad;',
    '        // the asterisk ladder: the Figurine',
    '        // 01-15 (1 star, per hit die), the Horn',
    '        // of Valhalla 54-60 (2 stars, double',
    '        // bronze / triple iron), the Ioun Stones',
    '        // 72 (3 stars, per stone), the',
    '        // Instrument of the Bards 73-78 (4',
    '        // stars, per level of instrument for',
    '        // bards - the footnote the book upload',
    '        // drops, restored from the compilation)',
    '        if (rules::m3StarCount(0) != 1 ||',
    '            rules::m3StarCount(20) != 2 ||',
    '            rules::m3StarCount(25) != 3 ||',
    '            rules::m3StarCount(26) != 4 ||',
    '            rules::m3StarCount(1) != 0) ++bad;',
    '        // a 4-hit-die figurine is 400 x.p. /',
    '        // 4,000 g.p.',
    '        if (rules::m3FigurinePerHitDieXp() != 100 ||',
    '            rules::m3FigurinePerHitDieGp() != 1000 ||',
    '            rules::m3FigurinePerHitDieXp() * 4 != 400 ||',
    '            rules::m3FigurinePerHitDieGp() * 4 != 4000)',
    '            ++bad;',
    '        // the bronze horn doubles (2,000 /',
    '        // 30,000), the iron horn triples',
    '        // (3,000 / 45,000)',
    '        if (rules::m3ValhallaBaseXp() != 1000 ||',
    '            rules::m3ValhallaBaseGp() != 15000 ||',
    '            rules::m3ValhallaBronzeMult() != 2 ||',
    '            rules::m3ValhallaIronMult() != 3 ||',
    '            rules::m3ValhallaBaseXp() *',
    '            rules::m3ValhallaBronzeMult() != 2000 ||',
    '            rules::m3ValhallaBaseGp() *',
    '            rules::m3ValhallaBronzeMult() != 30000 ||',
    '            rules::m3ValhallaBaseXp() *',
    '            rules::m3ValhallaIronMult() != 3000 ||',
    '            rules::m3ValhallaBaseGp() *',
    '            rules::m3ValhallaIronMult() != 45000)',
    '            ++bad;',
    '        // per stone: five stones are 1,500 x.p.',
    '        if (rules::m3IounPerStoneXp() != 300 ||',
    '            rules::m3IounPerStoneGp() != 5000 ||',
    '            rules::m3IounPerStoneXp() * 5 != 1500)',
    '            ++bad;',
    '        // the bardic instruments ride the',
    '        // college ladder: the 3rd-college Doss',
    '        // instrument is 3,000 x.p. / 15,000 g.p.',
    '        if (rules::m3InstrumentBaseXp() != 1000 ||',
    '            rules::m3InstrumentBaseGp() != 5000 ||',
    '            rules::m3InstrumentBaseXp() * 3 != 3000 ||',
    '            rules::m3InstrumentBaseGp() * 3 != 15000)',
    '            ++bad;',
    '        // the Jewel of Flawlessness 92: no x.p.,',
    '        // 1,000 g.p. per facet',
    '        if (!rules::m3IsPerFacetValued(31) ||',
    '            rules::m3IsPerFacetValued(30) ||',
    '            rules::m3JewelPerFacetGp() != 1000 ||',
    '            rules::m3JewelPerFacetGp() * 3 != 3000)',
    '            ++bad;',
    '        // clamped reads land on the Figurine',
    '        // (1 star) below and the unmarked',
    '        // 93-00 Ointment above',
    '        if (rules::m3StarCount(-99) != 1 ||',
    '            rules::m3UsableByCleric(99) ||',
    '            rules::m3IsPerFacetValued(99)) ++bad;',
    '        printf("R237 misc table 3 pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'census 142. Next: R227 - the III.E',
    'table 3 footnotes (Figurine per-hit-die',
    'asterisk, DMG p.129, upload lines',
    '~9765+), or the next un-pinned III.A-H',
    'surrounding prose seam.',
]
gap_new = [
    'census 142. Next: R227 - the III.E',
    'table 3 footnotes (Figurine per-hit-die',
    'asterisk, DMG p.129, upload lines',
    '~9765+), or the next un-pinned III.A-H',
    'surrounding prose seam.',
    '',
    'R237 landed the III.E table 3 footnote',
    'pins (DMG p.129, upload lines ~9765-9825)',
    '- the class marks and the asterisk ladder',
    'that frame TABLE (III.E.) 3.',
    'rules/miscmagic3.h (the grenade.h',
    'pattern), keyed to the 33 die bands of',
    'the engine III.E.3 table in kMisc3',
    'order: the (C, F, T) marks (Gauntlets of',
    'Ogre Power 21-22, Gauntlets of Swimming',
    'and Climbing 23-25, Girdle of',
    'Femininity/Masculinity 28, Girdle of',
    'Giant Strength 29); the (C, F) mark',
    '(Horn of the Tritons 50-53); the (C)',
    'marks (Incense of Meditation 66-70,',
    'Incense of Obsession 71); the (F) marks',
    '(Javelin of Lightning 81-85, Javelin of',
    'Piercing 86-90); NO (M) rows ride this',
    'table. The asterisk ladder: the Figurine',
    'of Wondrous Power (01-15) single star -',
    '100 x.p. / 1,000 g.p. PER HIT DIE of',
    'the figurine; the Horn of Valhalla',
    '(54-60) double star - double for a',
    'bronze horn, triple for an iron horn;',
    'the Ioun Stones (72) triple star - per',
    'stone; the Instrument of the Bards',
    '(73-78) QUADRUPLE star - 1,000 x.p. /',
    '5,000 g.p. per level of instrument for',
    'bards (the fourth footnote the book',
    'upload DROPS - restored from the',
    '1eonline.info compilation, the R175',
    'precedent); and the Jewel of',
    'Flawlessness (92) per-facet row (no',
    'x.p., 1,000 g.p. per facet). The row',
    'VALUES were already pinned by the R122',
    'line-diff audit; this round pins the',
    'class marks, the asterisk ladder and',
    'the band edges. New R237 battery audit;',
    'census 156. Next: R238 - the III.E',
    'table 4 footnotes (the Libram and',
    'Manual class marks, the Necklace of',
    'Missiles per-hit-die asterisk, the',
    'Medallion dual values and the Pearl',
    'of Power per-spell-level star, DMG',
    'p.129-130, upload lines ~9827+), or',
    'the next un-pinned III.A-H surrounding',
    'prose seam.',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson)
marker = 'R237: the III.E table 3 footnote pins'
try:
    t = open(MM3).read()
    if marker in t:
        already += 1
    else:
        print('R237 FAIL: rules/miscmagic3.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(MM3, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R237 audit', audit_old, audit_new),
    (GAP, 'the R237 log entry', gap_old, gap_new),
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
        print('R237 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 156:
        print('R237 FAIL: census is not 156')
        sys.exit(1)
    if t.count('R237 misc table 3 pins audit') != 1:
        print('R237 FAIL: the R237 audit line must appear once')
        sys.exit(1)
    if t.count('rules/miscmagic3.h') != 1:
        print('R237 FAIL: the miscmagic3 include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R237 landed the III.E table 3 footnote') != 1:
        print('R237 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(MM3).read()
    if 'namespace rules' not in h or h.count('inline int m3') != 22:
        print('R237 FAIL: the header shape is wrong')
        sys.exit(1)

print('R237 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R237 note: 4 patches; the III.E table 3 footnote pins landed -')
print('the class marks and the asterisk ladder; census 156.')
print('commit: R237: the III.E table 3 footnote pins pinned - DMG p.129, the class marks and the asterisk ladder (census 156)')

