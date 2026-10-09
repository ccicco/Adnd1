#!/usr/bin/env python3
# R272 splice: the III.E misc magic explanation prose
# part 16 pins - Iron Flask through Keoghtom
# ointment, part2 lines 766-802 (DMG p.148-149) -
# the slice completing the kMisc3 rows 27-32, the
# 33-row III.E.3 table. ONE page header inside the
# slice (792, the TREASURE page) falls inside the
# javelin of lightning paragraph between 1-6 hit
# and points of damage - ONE seam restored this
# round; the page attribution rides the
# 1eonline.info compilation TOC (the jewels,
# magical at p.149). The flask contents table: the
# upload drops the pipe in three rows (82-83
# mezzodaemon, 94-97 water elemental, 98-99 wind
# walker) - the 19-row d100 table pinned with the
# printed 00 row as the d100 100 (the engine kMisc3
# 93-00 precedent).
# 4 patches, marker-based idempotence, assert after
# every patch. ZERO apostrophes and ZERO literal
# backslashes in the content below (the printf newline
# is built via BS = chr(92)).

import os
import re
import sys

HERE = os.path.abspath(os.path.dirname(sys.argv[0]))
ROOT = os.path.abspath(HERE + '/..')
NL = chr(10)
BS = chr(92)

applied = 0
already = 0

def rd(p):
    f = open(os.path.join(ROOT, p), encoding='utf-8')
    s = f.read()
    f.close()
    return s

def wr(p, s):
    f = open(os.path.join(ROOT, p), 'w', encoding='utf-8')
    f.write(s)
    f.close()

HDR = [
    '// ====================================================================',
    '// Adnd1 - rules/miscprose16.h',
    '// R272: the III.E misc magic explanation prose part 16',
    '// (DMG p.148-149) - Iron Flask through Keoghtom',
    '// ointment, part2 lines 766-802 (global = 11065 +',
    '// part2 line). The slice completes the kMisc3 rows',
    '// 27-32, the 33-row III.E.3 table. ONE page header',
    '// inside the slice (792, the TREASURE page) falls',
    '// inside the javelin of lightning paragraph between',
    '// 1-6 hit and points of damage - ONE seam restored',
    '// this round; the page attribution rides the',
    '// 1eonline.info compilation TOC (the jewels,',
    '// magical at p.149). The flask contents table: the',
    '// upload drops the pipe in three rows (82-83',
    '// mezzodaemon, 94-97 water elemental, 98-99 wind',
    '// walker) - the 19-row d100 table pinned with the',
    '// printed 00 row as the d100 100 (the engine kMisc3',
    '// 93-00 precedent). 43 accessors: 41 scalars + 2',
    '// walkers (the flask contents die table), no name',
    '// collisions with miscprose1.h through',
    '// miscprose15.h. Pure data + helpers, header-only',
    '// (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int mmpFlaskRangeInches() {',
    '    // the command range is 6 inches',
    '    return 6;',
    '}',
    '',
    'inline int mmpFlaskMaxCreatures() {',
    '    // only 1 creature at a time can be held',
    '    return 1;',
    '}',
    '',
    'inline int mmpFlaskServiceTurns() {',
    '    // forced service lasts 1 turn',
    '    return 1;',
    '}',
    '',
    'inline int mmpFlaskServiceHours() {',
    '    // a minor service up to 1 hour of time',
    '    return 1;',
    '}',
    '',
    'inline int mmpFlaskRepeatSaveBonus() {',
    '    // a second forcing attempt saves at +2',
    '    return 2;',
    '}',
    '',
    'inline int mmpFlaskContentsRowCount() {',
    '    // 19 bands, empty through xorn',
    '    return 19;',
    '}',
    '',
    'inline int mmpFlaskContentsLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 18) i = 18;',
    '    static const int t[19] = {',
    '        1, 51, 55, 57, 58, 60, 61, 66, 70, 73,',
    '        77, 82, 84, 86, 87, 90, 94, 98, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpFlaskContentsHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 18) i = 18;',
    '    static const int t[19] = {',
    '        50, 54, 56, 57, 59, 60, 65, 69, 72, 76,',
    '        81, 83, 85, 86, 89, 93, 97, 99, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpJavelinLightningPlus() {',
    '    // equal to a +2 magic weapon, no bonuses',
    '    return 2;',
    '}',
    '',
    'inline int mmpJavelinLightningRangeInches() {',
    '    // the range is 9 inches',
    '    return 9;',
    '}',
    '',
    'inline int mmpJavelinLightningStrokeWidthHalfInches() {',
    '    // the stroke is one half inch wide',
    '    return 1;',
    '}',
    '',
    'inline int mmpJavelinLightningStrokeLengthInches() {',
    '    // the stroke is 3 inches long',
    '    return 3;',
    '}',
    '',
    'inline int mmpJavelinLightningDamageMin() {',
    '    // the struck target takes 1-6 hit points',
    '    return 1;',
    '}',
    '',
    'inline int mmpJavelinLightningDamageMax() {',
    '    // the upper edge of the 1-6 damage',
    '    return 6;',
    '}',
    '',
    'inline int mmpJavelinLightningElectricalDamage() {',
    '    // plus 20 hit points of electrical damage',
    '    return 20;',
    '}',
    '',
    'inline int mmpJavelinLightningBackstrokeMin() {',
    '    // the back stroke deals 10 or 20',
    '    return 10;',
    '}',
    '',
    'inline int mmpJavelinLightningBackstrokeMax() {',
    '    // the upper edge of the back stroke',
    '    return 20;',
    '}',
    '',
    'inline int mmpJavelinLightningBackstrokeInches() {',
    '    // drawn 3 inches back toward the hurler',
    '    return 3;',
    '}',
    '',
    'inline int mmpJavelinLightningFoundMin() {',
    '    // from 2-5 will be found',
    '    return 2;',
    '}',
    '',
    'inline int mmpJavelinLightningFoundMax() {',
    '    // the upper edge of the 2-5 find',
    '    return 5;',
    '}',
    '',
    'inline int mmpJavelinPiercingRangeInches() {',
    '    // range 6 inches, all distances short',
    '    return 6;',
    '}',
    '',
    'inline int mmpJavelinPiercingToHitBonus() {',
    '    // +6 to hit',
    '    return 6;',
    '}',
    '',
    'inline int mmpJavelinPiercingDamageMin() {',
    '    // the strike inflicts 7-12 hit points',
    '    return 7;',
    '}',
    '',
    'inline int mmpJavelinPiercingDamageMax() {',
    '    // the upper edge of the 7-12 damage',
    '    return 12;',
    '}',
    '',
    'inline int mmpJavelinPiercingFoundMin() {',
    '    // from 2-8 will be found',
    '    return 2;',
    '}',
    '',
    'inline int mmpJavelinPiercingFoundMax() {',
    '    // the upper edge of the 2-8 find',
    '    return 8;',
    '}',
    '',
    'inline int mmpJavelinPiercingThrows() {',
    '    // the magic is good for only 1 throw',
    '    return 1;',
    '}',
    '',
    'inline int mmpJewelAttacksWanderingPct() {',
    '    // 100 percent more wandering monsters',
    '    return 100;',
    '}',
    '',
    'inline int mmpJewelAttacksPursuitPct() {',
    '    // 100 percent greater pursuit likelihood',
    '    return 100;',
    '}',
    '',
    'inline int mmpJewelFlawlessBoostPct() {',
    '    // the value likelihood rises 100 percent',
    '    return 100;',
    '}',
    '',
    'inline int mmpJewelFlawlessBaseTenths() {',
    '    // 1 in 10 stones rise unboosted',
    '    return 1;',
    '}',
    '',
    'inline int mmpJewelFlawlessBoostedTenths() {',
    '    // 2 in 10 stones rise boosted',
    '    return 2;',
    '}',
    '',
    'inline int mmpJewelFlawlessFacetMin() {',
    '    // the jewel has 10-100 facets',
    '    return 10;',
    '}',
    '',
    'inline int mmpJewelFlawlessFacetMax() {',
    '    // the upper edge of the 10-100 facets',
    '    return 100;',
    '}',
    '',
    'inline int mmpJewelFlawlessTriggerD10() {',
    '    // a roll of 2 on d10 raises a stone',
    '    return 2;',
    '}',
    '',
    'inline int mmpJewelFlawlessFacetsLostPerBoost() {',
    '    // 1 facet disappears per raised stone',
    '    return 1;',
    '}',
    '',
    'inline int mmpOintmentJarDiameterInches() {',
    '    // the jar is three inches in diameter',
    '    return 3;',
    '}',
    '',
    'inline int mmpOintmentJarDepthInches() {',
    '    // the jar is one inch deep',
    '    return 1;',
    '}',
    '',
    'inline int mmpOintmentApplications() {',
    '    // the jar contains 5 applications',
    '    return 5;',
    '}',
    '',
    'inline int mmpOintmentHealMin() {',
    '    // rubbed on it heals 9-12 points',
    '    return 9;',
    '}',
    '',
    'inline int mmpOintmentHealMax() {',
    '    // the upper edge of the 9-12 healing',
    '    return 12;',
    '}',
    '',
    'inline int mmpOintmentFoundMin() {',
    '    // 1-3 jars will commonly be found',
    '    return 1;',
    '}',
    '',
    'inline int mmpOintmentFoundMax() {',
    '    // the upper edge of the 1-3 jars',
    '    return 3;',
    '}',
    '',
    '}  // namespace rules',
]

AUDIT = [
    '    // ---- R272: the III.E misc magic explanation',
    '    // prose part 16 ----',
    '    // Iron Flask through Keoghtom ointment, part2',
    '    // lines 766-802 - the slice completing the',
    '    // kMisc3 rows 27-32 (the 33-row III.E.3 table).',
    '    {',
    '        int bad = 0;',
    '        // the iron flask',
    '        if (rules::mmpFlaskRangeInches() != 6 ||',
    '            rules::mmpFlaskMaxCreatures() != 1 ||',
    '            rules::mmpFlaskServiceTurns() != 1 ||',
    '            rules::mmpFlaskServiceHours() != 1 ||',
    '            rules::mmpFlaskRepeatSaveBonus() != 2) ++bad;',
    '        // the flask contents die table against',
    '        // static twins; the printed 00 row is the',
    '        // d100 100 (the engine kMisc3 93-00',
    '        // precedent)',
    '        static const int kFlo[19] = {',
    '            1, 51, 55, 57, 58, 60, 61, 66, 70, 73,',
    '            77, 82, 84, 86, 87, 90, 94, 98, 100,',
    '        };',
    '        static const int kFhi[19] = {',
    '            50, 54, 56, 57, 59, 60, 65, 69, 72, 76,',
    '            81, 83, 85, 86, 89, 93, 97, 99, 100,',
    '        };',
    '        if (rules::mmpFlaskContentsRowCount() != 19) ++bad;',
    '        for (int i = 0; i < 19; ++i)',
    '            if (rules::mmpFlaskContentsLo(i) != kFlo[i] ||',
    '                rules::mmpFlaskContentsHi(i) != kFhi[i]) ++bad;',
    '        // the d100 bands tile without gaps',
    '        for (int i = 0; i < 18; ++i)',
    '            if (rules::mmpFlaskContentsLo(i + 1) !=',
    '                rules::mmpFlaskContentsHi(i) +',
    '                1) ++bad;',
    '        if (rules::mmpFlaskContentsLo(0) != 1 ||',
    '            rules::mmpFlaskContentsHi(18) != 100) ++bad;',
    '        // the three rows whose pipe the upload drops',
    '        if (rules::mmpFlaskContentsLo(11) != 82 ||',
    '            rules::mmpFlaskContentsHi(11) != 83 ||',
    '            rules::mmpFlaskContentsLo(17) != 98 ||',
    '            rules::mmpFlaskContentsHi(17) != 99) ++bad;',
    '        // the javelin of lightning',
    '        if (rules::mmpJavelinLightningPlus() != 2 ||',
    '            rules::mmpJavelinLightningRangeInches() != 9 ||',
    '            rules::mmpJavelinLightningStrokeWidthHalfInches()',
    '            != 1 ||',
    '            rules::mmpJavelinLightningStrokeLengthInches()',
    '            != 3 ||',
    '            rules::mmpJavelinLightningDamageMin() != 1 ||',
    '            rules::mmpJavelinLightningDamageMax() != 6 ||',
    '            rules::mmpJavelinLightningElectricalDamage()',
    '            != 20 ||',
    '            rules::mmpJavelinLightningBackstrokeMin() != 10 ||',
    '            rules::mmpJavelinLightningBackstrokeMax() != 20 ||',
    '            rules::mmpJavelinLightningBackstrokeInches() !=',
    '            3 ||',
    '            rules::mmpJavelinLightningFoundMin() != 2 ||',
    '            rules::mmpJavelinLightningFoundMax() != 5) ++bad;',
    '        // the javelin of piercing',
    '        if (rules::mmpJavelinPiercingRangeInches() != 6 ||',
    '            rules::mmpJavelinPiercingToHitBonus() != 6 ||',
    '            rules::mmpJavelinPiercingDamageMin() != 7 ||',
    '            rules::mmpJavelinPiercingDamageMax() != 12 ||',
    '            rules::mmpJavelinPiercingFoundMin() != 2 ||',
    '            rules::mmpJavelinPiercingFoundMax() != 8 ||',
    '            rules::mmpJavelinPiercingThrows() != 1) ++bad;',
    '        // the jewel of attacks',
    '        if (rules::mmpJewelAttacksWanderingPct() != 100 ||',
    '            rules::mmpJewelAttacksPursuitPct() != 100) ++bad;',
    '        // the jewel of flawlessness',
    '        if (rules::mmpJewelFlawlessBoostPct() != 100 ||',
    '            rules::mmpJewelFlawlessBaseTenths() != 1 ||',
    '            rules::mmpJewelFlawlessBoostedTenths() != 2 ||',
    '            rules::mmpJewelFlawlessFacetMin() != 10 ||',
    '            rules::mmpJewelFlawlessFacetMax() != 100 ||',
    '            rules::mmpJewelFlawlessTriggerD10() != 2 ||',
    '            rules::mmpJewelFlawlessFacetsLostPerBoost() !=',
    '            1) ++bad;',
    '        // the Keoghtom ointment',
    '        if (rules::mmpOintmentJarDiameterInches() != 3 ||',
    '            rules::mmpOintmentJarDepthInches() != 1 ||',
    '            rules::mmpOintmentApplications() != 5 ||',
    '            rules::mmpOintmentHealMin() != 9 ||',
    '            rules::mmpOintmentHealMax() != 12 ||',
    '            rules::mmpOintmentFoundMin() != 1 ||',
    '            rules::mmpOintmentFoundMax() != 3) ++bad;',
    '        // the engine kMisc3 rows 27-32: band edges,',
    '        // the javelin (F) marks, no asterisks, the',
    '        // flawless per-facet row',
    '        if (rules::m3RowLo(27) != 79 ||',
    '            rules::m3RowHi(27) != 80 ||',
    '            rules::m3RowLo(28) != 81 ||',
    '            rules::m3RowHi(28) != 85 ||',
    '            rules::m3RowLo(29) != 86 ||',
    '            rules::m3RowHi(29) != 90 ||',
    '            rules::m3RowLo(30) != 91 ||',
    '            rules::m3RowHi(30) != 91 ||',
    '            rules::m3RowLo(31) != 92 ||',
    '            rules::m3RowHi(31) != 92 ||',
    '            rules::m3RowLo(32) != 93 ||',
    '            rules::m3RowHi(32) != 100) ++bad;',
    '        if (rules::m3UsableByFighter(27) != 0 ||',
    '            rules::m3UsableByFighter(28) != 1 ||',
    '            rules::m3UsableByFighter(29) != 1 ||',
    '            rules::m3UsableByFighter(30) != 0 ||',
    '            rules::m3UsableByFighter(31) != 0 ||',
    '            rules::m3UsableByFighter(32) != 0) ++bad;',
    '        if (rules::m3StarCount(27) != 0 ||',
    '            rules::m3StarCount(28) != 0 ||',
    '            rules::m3StarCount(29) != 0 ||',
    '            rules::m3StarCount(30) != 0 ||',
    '            rules::m3StarCount(31) != 0 ||',
    '            rules::m3StarCount(32) != 0) ++bad;',
    '        if (rules::m3IsPerFacetValued(31) != 1 ||',
    '            rules::m3JewelPerFacetGp() != 1000) ++bad;',
    '        printf("R272 misc magic prose part 16 pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]

GAP = [
    'R272 landed the III.E misc',
    'magic explanation prose part',
    '16 (part2 lines 766-802;',
    'global = 11065 + part2',
    'line), Iron Flask through',
    'Keoghtom ointment (DMG',
    'p.148-149) - the slice',
    'completing the kMisc3',
    'rows 27-32, the 33-row',
    'III.E.3 table. ONE page',
    'header inside the slice',
    '(792, the TREASURE page)',
    'falls inside the javelin',
    'of lightning paragraph',
    'between 1-6 hit and',
    'points of damage -',
    'ONE seam restored this',
    'round; the page attribution',
    'rides the 1eonline.info',
    'compilation TOC (the',
    'jewels, magical at p.149).',
    'The flask contents table:',
    'the upload drops the pipe',
    'in three rows (82-83',
    'mezzodaemon, 94-97 water',
    'elemental, 98-99 wind',
    'walker) - the 19-row d100',
    'table pinned with the',
    'printed 00 row as the d100',
    '100 (the engine kMisc3',
    '93-00 precedent). The',
    'items: Iron Flask (range 6',
    'inches, one creature at a',
    'time, 1 turn or 1 hour of',
    'minor service, +2 save on',
    'a second attempt), Javelin',
    'of Lightning (+2 weapon,',
    '9 inch range, half-by-3',
    'inch stroke, 1-6 plus 20',
    'electrical, back stroke 20',
    'or 10, from 2-5, consumed),',
    'Javelin of Piercing (6',
    'inch range, +6 to hit, 7-12',
    'damage, from 2-8, one',
    'throw), Jewel of Attacks',
    '(100 percent wandering and',
    '100 percent pursuit, remove',
    'curse or atonement), Jewel',
    'of Flawlessness (100',
    'percent boost, 1 in 10 to',
    '2 in 10, 10-100 facets, a',
    'roll of 2 on d10 burns 1',
    'facet, then a spherical',
    'stone of no value),',
    'Keoghtom ointment (a 3 by 1',
    'inch jar, 5 applications,',
    'heals 9-12, from 1-3',
    'jars). 43 accessors: 41',
    'scalars + 2 walkers (the',
    'flask contents die',
    'table), no name collisions',
    'parts 1-15. New R272',
    'battery audit; census 190.',
    'Next: R273 III.E part 17 -',
    'the Libram of Gainful',
    'Conjuration onward in',
    'part2 from line 806',
    '(global 11871; the librams,',
    'lyre of building and',
    'manuals follow).',
]

# ---- the splice self-asserts ----
HTEXT = NL.join(HDR)
defs = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(]', HTEXT)
assert len(defs) == 43, 'accessor count is not 43'
assert len(set(defs)) == 43, 'accessor names not unique'
scal = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(][)]', HTEXT)
walk = [d for d in defs if d not in scal]
assert len(scal) == 41, 'scalar count is not 41'
assert len(walk) == 2, 'walker count is not 2'
assert set(walk) == {'mmpFlaskContentsLo',
                     'mmpFlaskContentsHi'}, 'wrong walkers'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(mmp[A-Za-z0-9]+)[(]', ATEXT))
assert audited == set(defs), 'audit does not probe every accessor'
for p in range(1, 16):
    pp = os.path.join(ROOT, 'rules/miscprose%d.h' % p)
    if os.path.exists(pp):
        pt = open(pp, encoding='utf-8').read()
        for n in defs:
            assert n not in pt, 'name collision with part %d' % p
for grp in (HDR, AUDIT, GAP):
    for el in grp:
        if isinstance(el, str):
            assert chr(39) not in el, 'apostrophe in content'
            probe = el.replace(chr(92) + 'n', '')
            assert chr(92) not in probe, 'backslash in content'
            assert NL not in el, 'list element spans lines'
assert ATEXT.count('{') == ATEXT.count('}'), 'audit braces unbalanced'
assert ATEXT.count('(') == ATEXT.count(')'), 'audit parens unbalanced'
assert AUDIT[-1] == '    }', 'audit block does not close'
assert HDR[-1] == '}  // namespace rules', 'header does not close'
assert ATEXT.count('R272 misc magic prose part 16 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'

# ---- patch 1: create rules/miscprose16.h ----
p = 'rules/miscprose16.h'
if os.path.exists(os.path.join(ROOT, p)):
    assert rd(p) == HTEXT, 'miscprose16.h exists but differs'
    already += 1
else:
    wr(p, HTEXT)
    applied += 1
assert rd(p) == HTEXT, 'patch 1 failed'

# ---- patch 2: the regtest include ----
p = 'regtest.cpp'
s = rd(p)
inc = '#include "rules/miscprose16.h"  // R272: the III.E misc magic explanation prose part 16 pins'
if inc in s:
    already += 1
else:
    anchor = '#include "rules/miscprose15.h"  // R271: the III.E misc magic explanation prose part 15 pins'
    assert s.count(anchor) == 1, 'include anchor not unique'
    s = s.replace(anchor, anchor + NL + inc, 1)
    wr(p, s)
    applied += 1
assert inc in rd(p), 'patch 2 failed'
assert rd(p).count('#include "rules/miscprose16.h"') == 1, 'patch 2 doubled'

# ---- patch 3: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R272: the III.E misc magic explanation'
if mark in s:
    already += 1
else:
    anchor = '    // ---- R227: the wis mental save wiring audit ----'
    assert s.count(anchor) == 1, 'audit anchor not unique'
    s = s.replace(anchor, ATEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
assert mark in rd(p), 'patch 3 failed'
assert rd(p).count(mark) == 1, 'patch 3 doubled'

# ---- patch 4: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R272 landed the III.E misc'
if mark in s:
    already += 1
else:
    anchor = 'kMisc3 rows 27+ begin).' + NL + NL + 'Categories:'
    assert s.count(anchor) == 1, 'gap anchor not unique'
    s = s.replace(anchor, 'kMisc3 rows 27+ begin).' + NL + NL + NL.join(GAP) + NL + NL + 'Categories:', 1)
    wr(p, s)
    applied += 1
assert mark in rd(p), 'patch 4 failed'
assert rd(p).count(mark) == 1, 'patch 4 doubled'

print('R272 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R272 note: 4 patches; the III.E misc magic')
print('explanation prose part 16 - Iron Flask through')
print('Keoghtom ointment, part2 lines 766-802;')
print('census 190.')
print('commit: R272: the III.E misc magic explanation prose part 16 pinned - Iron Flask through Keoghtom ointment in part2 lines 766-802 (census 190)')

