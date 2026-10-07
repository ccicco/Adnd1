#!/usr/bin/env python3
# R248 splice: the III.D wand of wonder effect table pins.
#
# DMG p.145, upload lines ~10867-10947 - the fifth and
# final prose round of the III.D EXPLANATIONS arc for
# RODS, STAVES, and WANDS: the wand of wonder effect
# table. The 19 die bands 01-10 through 98-00 tile
# 01-100 with no gaps or overlaps: slow creature
# pointed at for 1 turn (01-10); delude the wielder
# for 1 round into believing a second die roll
# (11-18); gust of wind at double force (19-25);
# stinking cloud at 3" range (26-30); heavy rain
# 1 round in a 6" radius (31-33); summon rhino 1-25,
# elephant 26-50, mouse 51-00 (34-36); lightning bolt
# 7" x 0.5" as wand (37-46); 600 large butterflies
# fluttering 2 rounds, blinding everyone including
# the wielder (47-49); enlarge within 6" (50-53);
# darkness in a 3" diameter hemisphere at 3" center
# distance (54-58); grass in a 16" square or grows to
# 10 times normal size (59-62); vanish non-living up
# to 1,000 pounds mass and 30 cubic feet (63-65);
# diminish the wielder to 1" height (66-69); fireball
# as wand (70-79); invisibility covers the wielder
# (80-84); leaves grow within 6" (85-87); 10-40 gems
# of 1 g.p. base value in a 3" stream, each causing
# 1 h.p., roll 5d4 for the number of hits (88-90);
# shimmering colors over 4" x 3", blinded 1-6 rounds
# (91-97); flesh to stone or reverse within 6"
# (98-00). The wand uses 1 charge per function and
# may not be recharged. The 0.5" bolt width is pinned
# as 1 half-inch, continuing the R247 half-inch
# workaround. The wonder is the engine III.D table
# row 30 (dm/treasure.cpp kRods, bands 95-100) -
# cross-checked against the R224 rodswands.h pins in
# the audit.
# Patches: 4 (new rules/wonder.h, the regtest include,
# the audit block, the dmg-gap-report log entry).
# Census 166 -> 167.
#
# commit: R248: the III.D wand of wonder effect table pins pinned - DMG p.145, the 19 bands and the effect facts (census 167)

import sys

WD   = 'rules/wonder.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 166 and t.count('audit: bad ') != 167:
    print('R248 FAIL: regtest census is neither 166 nor 167')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/wonder.h',
    '// R248: the III.D wand of wonder effect',
    '// table pins (DMG p.145) - the 19 die',
    '// bands 01-10 through 98-00 and the',
    '// effect numeric facts (upload lines',
    '// ~10867-10947):',
    '//   - the table bands: slow creature',
    '//     pointed at for 1 turn (01-10);',
    '//     delude the wielder 1 round, a',
    '//     second die roll (11-18); gust of',
    '//     wind at double force (19-25);',
    '//     stinking cloud at 3" range',
    '//     (26-30); heavy rain 1 round in a',
    '//     6" radius (31-33); summon rhino',
    '//     1-25, elephant 26-50, mouse',
    '//     51-00 (34-36); lightning bolt',
    '//     7" x 0.5" as wand - the width',
    '//     pinned as 1 half-inch, continuing',
    '//     the R247 half-inch workaround',
    '//     (37-46); 600 large butterflies 2',
    '//     rounds blinding everyone',
    '//     including the wielder (47-49);',
    '//     enlarge within 6" (50-53);',
    '//     darkness in a 3" diameter',
    '//     hemisphere at 3" center distance',
    '//     (54-58); grass in a 16" square',
    '//     or grows to 10 times normal size',
    '//     (59-62); vanish non-living up to',
    '//     1,000 pounds mass and 30 cubic',
    '//     feet (63-65); diminish the',
    '//     wielder to 1" height (66-69);',
    '//     fireball as wand (70-79);',
    '//     invisibility covers the wielder',
    '//     (80-84); leaves grow within 6"',
    '//     (85-87); 10-40 gems of 1 g.p.',
    '//     base value in a 3" stream, each',
    '//     causing 1 h.p., roll 5d4 for the',
    '//     number of hits (88-90);',
    '//     shimmering colors over 4" x 3",',
    '//     blinded 1-6 rounds (91-97);',
    '//     flesh to stone or reverse within',
    '//     6" (98-00).',
    '//   - the wand uses 1 charge per',
    '//     function and may not be',
    '//     recharged.',
    '// The bands tile 01-100 with no gaps',
    '// or overlaps. The wonder is the',
    '// engine III.D table row 30',
    '// (dm/treasure.cpp kRods, bands',
    '// 95-100) - cross-checked against',
    '// the R224 rodswands.h pins in the',
    '// audit.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int wonderRowCount() {',
    '    // the 19 die bands of the effect table',
    '    return 19;',
    '}',
    '',
    'inline int wonderRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 18) i = 18;',
    '    static const int t[19] = {',
    '        1, 11, 19, 26, 31, 34, 37, 47, 50, 54,',
    '        59, 63, 66, 70, 80, 85, 88, 91, 98,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int wonderRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 18) i = 18;',
    '    static const int t[19] = {',
    '        10, 18, 25, 30, 33, 36, 46, 49, 53, 58,',
    '        62, 65, 69, 79, 84, 87, 90, 97, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int wonderChargesPerFunction() {',
    '    // the wand uses 1 charge per function',
    '    return 1;',
    '}',
    '',
    'inline int wonderRechargeable() {',
    '    // it may not be recharged',
    '    return 0;',
    '}',
    '',
    'inline int wonderSlowTurns() {',
    '    // band 01-10: slow creature pointed at',
    '    // for 1 turn',
    '    return 1;',
    '}',
    '',
    'inline int wonderDeludeRounds() {',
    '    // band 11-18: deludes the wielder for',
    '    // 1 round into believing the wand',
    '    // functions as indicated by a second',
    '    // die roll',
    '    return 1;',
    '}',
    '',
    'inline int wonderGustForceMultiplier() {',
    '    // band 19-25: gust of wind, double',
    '    // force of the spell',
    '    return 2;',
    '}',
    '',
    'inline int wonderStinkingRangeInches() {',
    '    // band 26-30: stinking cloud at 3"',
    '    // range',
    '    return 3;',
    '}',
    '',
    'inline int wonderRainRounds() {',
    '    // band 31-33: heavy rain falls for',
    '    // 1 round',
    '    return 1;',
    '}',
    '',
    'inline int wonderRainRadiusInches() {',
    '    // in a 6" radius of the wand wielder',
    '    return 6;',
    '}',
    '',
    'inline int wonderSummonRhinoLo() {',
    '    // band 34-36: summon rhino on 1-25',
    '    return 1;',
    '}',
    '',
    'inline int wonderSummonRhinoHi() {',
    '    return 25;',
    '}',
    '',
    'inline int wonderSummonElephantLo() {',
    '    // elephant on 26-50',
    '    return 26;',
    '}',
    '',
    'inline int wonderSummonElephantHi() {',
    '    return 50;',
    '}',
    '',
    'inline int wonderSummonMouseLo() {',
    '    // mouse on 51-00',
    '    return 51;',
    '}',
    '',
    'inline int wonderSummonMouseHi() {',
    '    return 100;',
    '}',
    '',
    'inline int wonderBoltLengthInches() {',
    '    // band 37-46: lightning bolt 7" long',
    '    return 7;',
    '}',
    '',
    'inline int wonderBoltWidthHalfInches() {',
    '    // the bolt is 0.5" wide - pinned as',
    '    // 1 half-inch, continuing the R247',
    '    // half-inch workaround',
    '    return 1;',
    '}',
    '',
    'inline int wonderButterflyCount() {',
    '    // band 47-49: a stream of 600 large',
    '    // butterflies pour forth',
    '    return 600;',
    '}',
    '',
    'inline int wonderButterflyRounds() {',
    '    // they flutter around for 2 rounds,',
    '    // blinding everyone including the',
    '    // wielder',
    '    return 2;',
    '}',
    '',
    'inline int wonderEnlargeRangeInches() {',
    '    // band 50-53: enlarge the target if',
    '    // in 6" of the wand',
    '    return 6;',
    '}',
    '',
    'inline int wonderDarknessDiameterInches() {',
    '    // band 54-58: darkness in a 3"',
    '    // diameter hemisphere',
    '    return 3;',
    '}',
    '',
    'inline int wonderDarknessCenterDistanceInches() {',
    '    // at 3" center distance from the wand',
    '    return 3;',
    '}',
    '',
    'inline int wonderGrassAreaInches() {',
    '    // band 59-62: grass grows in an area',
    '    // of 16" square before the wand',
    '    return 16;',
    '}',
    '',
    'inline int wonderGrassGrowthFactor() {',
    '    // or grass there grows to 10 times',
    '    // normal size',
    '    return 10;',
    '}',
    '',
    'inline int wonderVanishMassPounds() {',
    '    // band 63-65: vanish any non-living',
    '    // object of up to 1,000 pounds mass',
    '    return 1000;',
    '}',
    '',
    'inline int wonderVanishVolumeCubicFeet() {',
    '    // and up to 30 cubic feet in size',
    '    return 30;',
    '}',
    '',
    'inline int wonderDiminishHeightInches() {',
    '    // band 66-69: diminish the wielder',
    '    // to 1" height',
    '    return 1;',
    '}',
    '',
    'inline int wonderLeavesRangeInches() {',
    '    // band 85-87: leaves grow from the',
    '    // target if in 6" of the wand',
    '    return 6;',
    '}',
    '',
    'inline int wonderGemCountLo() {',
    '    // band 88-90: 10-40 gems shoot forth',
    '    return 10;',
    '}',
    '',
    'inline int wonderGemCountHi() {',
    '    return 40;',
    '}',
    '',
    'inline int wonderGemBaseValueGp() {',
    '    // each gem has a 1 g.p. base value',
    '    return 1;',
    '}',
    '',
    'inline int wonderGemStreamLengthInches() {',
    '    // they shoot forth in a 3" long',
    '    // stream',
    '    return 3;',
    '}',
    '',
    'inline int wonderGemDamageHp() {',
    '    // each causing 1 h.p. of damage to',
    '    // any creature in path',
    '    return 1;',
    '}',
    '',
    'inline int wonderGemHitDice() {',
    '    // roll 5d4 for the number of hits',
    '    return 5;',
    '}',
    '',
    'inline int wonderGemHitFaces() {',
    '    return 4;',
    '}',
    '',
    'inline int wonderColorAreaWidthInches() {',
    '    // band 91-97: shimmering colors',
    '    // dance over a 4" x 3" area',
    '    return 4;',
    '}',
    '',
    'inline int wonderColorAreaHeightInches() {',
    '    return 3;',
    '}',
    '',
    'inline int wonderColorBlindLo() {',
    '    // creatures therein are blinded',
    '    // for 1-6 rounds',
    '    return 1;',
    '}',
    '',
    'inline int wonderColorBlindHi() {',
    '    return 6;',
    '}',
    '',
    'inline int wonderFleshRangeInches() {',
    '    // band 98-00: flesh to stone or the',
    '    // reverse if the target is within 6"',
    '    return 6;',
    '}',
    '',
    '}  // namespace rules',
    '',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/wandsprose2.h"  // R247: pp.144-145 the III.D wands prose part 2 pins',
]
inc_new = [
    '#include "rules/wandsprose2.h"  // R247: pp.144-145 the III.D wands prose part 2 pins',
    '#include "rules/wonder.h"  // R248: p.145 the III.D wand of wonder effect table pins',
]

# ---- the regtest audit block ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R248: the III.D wand of wonder effect table pins audit ----',
    '    // DMG p.145: the 19 die bands and the',
    '    // effect numeric facts - the round that',
    '    // closes the III.D wands arc.',
    '    {',
    '        int bad = 0;',
    '        // the table identity: the 19 bands tile 01-100',
    '        if (rules::wonderRowCount() != 19) ++bad;',
    '        static const int kLo[19] = {',
    '            1, 11, 19, 26, 31, 34, 37, 47, 50, 54,',
    '            59, 63, 66, 70, 80, 85, 88, 91, 98,',
    '        };',
    '        static const int kHi[19] = {',
    '            10, 18, 25, 30, 33, 36, 46, 49, 53, 58,',
    '            62, 65, 69, 79, 84, 87, 90, 97, 100,',
    '        };',
    '        for (int i = 0; i < 19; ++i)',
    '            if (rules::wonderRowLo(i) != kLo[i] ||',
    '                rules::wonderRowHi(i) != kHi[i]) ++bad;',
    '        for (int i = 1; i < 19; ++i)',
    '            if (rules::wonderRowLo(i) !=',
    '                rules::wonderRowHi(i - 1) + 1) ++bad;',
    '        if (rules::wonderRowLo(-5) != 1 ||',
    '            rules::wonderRowHi(99) != 100) ++bad;',
    '        // the engine cross-check: the wonder is',
    '        // kRods row 30, bands 95-100 (the R224 pins)',
    '        if (rules::rswRowLo(29) != 95 ||',
    '            rules::rswRowHi(29) != 100) ++bad;',
    '        // the global facts',
    '        if (rules::wonderChargesPerFunction() != 1 ||',
    '            rules::wonderRechargeable() != 0) ++bad;',
    '        // bands 01-25: slow, delude, gust',
    '        if (rules::wonderSlowTurns() != 1 ||',
    '            rules::wonderDeludeRounds() != 1 ||',
    '            rules::wonderGustForceMultiplier() != 2) ++bad;',
    '        // bands 26-33: stinking cloud, heavy rain',
    '        if (rules::wonderStinkingRangeInches() != 3 ||',
    '            rules::wonderRainRounds() != 1 ||',
    '            rules::wonderRainRadiusInches() != 6) ++bad;',
    '        // band 34-36: the summon subtable',
    '        if (rules::wonderSummonRhinoLo() != 1 ||',
    '            rules::wonderSummonRhinoHi() != 25 ||',
    '            rules::wonderSummonElephantLo() != 26 ||',
    '            rules::wonderSummonElephantHi() != 50 ||',
    '            rules::wonderSummonMouseLo() != 51 ||',
    '            rules::wonderSummonMouseHi() != 100) ++bad;',
    '        // bands 37-49: the bolt, the butterflies',
    '        if (rules::wonderBoltLengthInches() != 7 ||',
    '            rules::wonderBoltWidthHalfInches() != 1 ||',
    '            rules::wonderButterflyCount() != 600 ||',
    '            rules::wonderButterflyRounds() != 2) ++bad;',
    '        // bands 50-58: enlarge, darkness',
    '        if (rules::wonderEnlargeRangeInches() != 6 ||',
    '            rules::wonderDarknessDiameterInches() != 3 ||',
    '            rules::wonderDarknessCenterDistanceInches() != 3) ++bad;',
    '        // bands 59-65: grass, vanish',
    '        if (rules::wonderGrassAreaInches() != 16 ||',
    '            rules::wonderGrassGrowthFactor() != 10 ||',
    '            rules::wonderVanishMassPounds() != 1000 ||',
    '            rules::wonderVanishVolumeCubicFeet() != 30) ++bad;',
    '        // band 66-69: diminish',
    '        if (rules::wonderDiminishHeightInches() != 1) ++bad;',
    '        // bands 70-84: fireball as wand, invisibility',
    '        // band 85-87: leaves',
    '        if (rules::wonderLeavesRangeInches() != 6) ++bad;',
    '        // band 88-90: the gem stream',
    '        if (rules::wonderGemCountLo() != 10 ||',
    '            rules::wonderGemCountHi() != 40 ||',
    '            rules::wonderGemBaseValueGp() != 1 ||',
    '            rules::wonderGemStreamLengthInches() != 3 ||',
    '            rules::wonderGemDamageHp() != 1 ||',
    '            rules::wonderGemHitDice() != 5 ||',
    '            rules::wonderGemHitFaces() != 4) ++bad;',
    '        // band 91-97: shimmering colors',
    '        if (rules::wonderColorAreaWidthInches() != 4 ||',
    '            rules::wonderColorAreaHeightInches() != 3 ||',
    '            rules::wonderColorBlindLo() != 1 ||',
    '            rules::wonderColorBlindHi() != 6) ++bad;',
    '        // band 98-00: flesh to stone',
    '        if (rules::wonderFleshRangeInches() != 6) ++bad;',
    '        printf("R248 wand of wonder effect table pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'the misc magic item explanations',
    '(~10949+) remain open after that.',
]
gap_new = [
    'the misc magic item explanations',
    '(~10949+) remain open after that.',
    '',
    'R248 landed the III.D wand of wonder',
    'effect table pins (DMG p.145, upload',
    'lines ~10867-10947) - the round that',
    'CLOSES the III.D wands arc (rods',
    'R244, staves R245, wands R246-R247,',
    'wonder R248). rules/wonder.h (the',
    'grenade.h pattern, wonder prefix, 42',
    'accessors - the 19-band table plus',
    '39 scalar effect facts, the first',
    'array header since R224): the bands',
    'tile 01-100 with no gaps or overlaps',
    '- 01-10 slow creature 1 turn, 11-18',
    'delude wielder 1 round (a second die',
    'roll), 19-25 gust of wind double',
    'force, 26-30 stinking cloud 3" range,',
    '31-33 heavy rain 1 round 6" radius,',
    '34-36 summon rhino 1-25 elephant',
    '26-50 mouse 51-00, 37-46 lightning',
    'bolt 7" x 0.5" as wand (the width',
    'pinned as 1 half-inch, continuing the',
    'R247 half-inch workaround), 47-49',
    '600 large butterflies 2 rounds',
    'blinding everyone including the',
    'wielder, 50-53 enlarge within 6",',
    '54-58 darkness 3" diameter',
    'hemisphere at 3" center distance,',
    '59-62 grass 16" square or 10 times',
    'normal size, 63-65 vanish non-living',
    'up to 1,000 pounds and 30 cubic',
    'feet, 66-69 diminish wielder to 1"',
    'height, 70-79 fireball as wand,',
    '80-84 invisibility covers the',
    'wielder, 85-87 leaves grow within',
    '6", 88-90 10-40 gems of 1 g.p. base',
    'value in a 3" stream each 1 h.p.',
    'with 5d4 for the number of hits',
    '(note: 5d4 gives 5-20 hits, not',
    '10-40 - the gem count and the hit',
    'roll are separate facts), 91-97',
    'shimmering colors 4" x 3" blinded',
    '1-6 rounds, 98-00 flesh to stone or',
    'reverse within 6". The wand uses 1',
    'charge per function and may not be',
    'recharged. The wonder is the engine',
    'kRods row 30, bands 95-100',
    '(cross-checked against the R224',
    'rodswands.h pins in the audit). New',
    'R248 battery audit; census 167. The',
    'III.D explanation prose is now fully',
    'pinned. The remaining open seams:',
    'the potions/scrolls/rings explanation',
    'prose (upload ~9998-10561) and the',
    'misc magic item explanations',
    '(~10949+).',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson; the marker MUST be contiguous in
# the header text - the R247 lesson)
marker = 'R248: the III.D wand of wonder effect'
try:
    t = open(WD).read()
    if marker in t:
        already += 1
    else:
        print('R248 FAIL: rules/wonder.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(WD, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R248 audit', audit_old, audit_new),
    (GAP, 'the R248 log entry', gap_old, gap_new),
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
        print('R248 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 167:
        print('R248 FAIL: census is not 167')
        sys.exit(1)
    if t.count('R248 wand of wonder effect table pins audit') != 1:
        print('R248 FAIL: the R248 audit line must appear once')
        sys.exit(1)
    if t.count('rules/wonder.h') != 1:
        print('R248 FAIL: the wonder include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R248 landed the III.D wand of') != 1:
        print('R248 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(WD).read()
    if 'namespace rules' not in h or h.count('inline int wonder') != 42:
        print('R248 FAIL: the header shape is wrong')
        sys.exit(1)

print('R248 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R248 note: 4 patches; the III.D wand of wonder effect table pins -')
print('the 19 bands and the effect facts; the III.D wands arc closes; census 167.')
print('commit: R248: the III.D wand of wonder effect table pins pinned - DMG p.145, the 19 bands and the effect facts (census 167)')

