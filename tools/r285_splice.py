#!/usr/bin/env python3
# R285 splice: the III.E Special artifacts
# explanation prose part 6 pins - the
# Mystical Organ of Heward, the Horn of
# Change and the Invulnerable Coat of
# Arnd, part2 lines 1359-1403 (DMG
# p.161-162), the ninth through the 11th
# of the 29 artifact descriptions. The
# Organ: the Fables of Burdock mention a
# large musical instrument; 77 pipes, 13
# ivory stops, 3 foot pedals; the bellows
# worked by a chained air elemental; the
# stops give voices, the keys vary the
# notes; no one knows the pedal purpose;
# despite silenced pipes it still works
# mighty magicks; wrong stops or keys
# summon, unbind or backfire; improper
# playing may change the alignment; powers
# 7,7,3,7,7,3 (total 34); misplaying
# negates, reverses or changes effects.
# The Horn: exactly resembles the common
# horns; 1 wind gives I or III, 2 give II
# or VI, 3 give V or IV; 75/25 power and
# effect split suggested; inappropriate
# results ignored. The Coat: the High
# Priest Arnd of Tdon; a weightless chain
# shirt covering upper arms, torso and
# groin; wearers from 3 to 8 feet;
# invulnerable on covered areas, AC 5
# elsewhere; +5 saves as +5 armor; fire,
# acid, cold and electricity resisted;
# powers 3,2,2,1,1,1 (total 10). No page
# break inside the slice. 33 accessors:
# 29 scalars + 4 walkers. The audit
# cross-pins the R240 sale rows: the
# Organ band 26 at 25000, the Horn band
# 27 at 20000, the Coat band 28-29 at
# 47500.
# 3 patches, marker-based idempotence,
# assert after every patch. ZERO
# apostrophes and ZERO literal backslashes
# in the content below (the printf
# newline is built via BS = chr(92)).

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


PINS = [
    'inline int sapOrganPipeCount() {',
    '    // 77 great and small pipes',
    '    return 77;',
    '}',
    '',
    'inline int sapOrganStopCount() {',
    '    // the console keys beneath 13 ivory stops',
    '    return 13;',
    '}',
    '',
    'inline int sapOrganPedalCount() {',
    '    // 3 great foot pedals',
    '    return 3;',
    '}',
    '',
    'inline int sapOrganBellowsElemental() {',
    '    // the bellows worked by a chained air elemental',
    '    return 1;',
    '}',
    '',
    'inline int sapOrganStopsVaryVoice() {',
    '    // each stop sounds the pipes in a new voice',
    '    return 1;',
    '}',
    '',
    'inline int sapOrganKeysVaryNotes() {',
    '    // the keys vary the notes',
    '    return 1;',
    '}',
    '',
    'inline int sapOrganPedalPurposeUnknown() {',
    '    // no one is certain what the pedals serve',
    '    return 1;',
    '}',
    '',
    'inline int sapOrganStillWorksDespiteTime() {',
    '    // despite silenced pipes it works mighty magicks',
    '    return 1;',
    '}',
    '',
    'inline int sapOrganWrongStopsSummon() {',
    '    // wrong stops summon the undesired or wrong spell',
    '    return 1;',
    '}',
    '',
    'inline int sapOrganWrongKeysBackfire() {',
    '    // wrong keys unbind or the magic backfires',
    '    return 1;',
    '}',
    '',
    'inline int sapOrganMisplayAlignment() {',
    '    // improper playing may change the alignment',
    '    return 1;',
    '}',
    '',
    'inline int sapOrganDmAssignsStopsKeys() {',
    '    // the DM decides the stops and key sequences',
    '    return 1;',
    '}',
    '',
    'inline int sapOrganPowerTotal() {',
    '    // 7+7+3+7+7+3 - the total power count',
    '    return 34;',
    '}',
    '',
    'inline int sapOrganMisplayNegates() {',
    '    // misplaying negates, reverses, changes effects',
    '    return 1;',
    '}',
    '',
    'inline int sapHornResemblesCommonHorns() {',
    '    // exactly resembles horns of blasting, bubbles',
    '    return 1;',
    '}',
    '',
    'inline int sapHornSuggestedPowerPct() {',
    '    // the suggested 75 percent power share',
    '    return 75;',
    '}',
    '',
    'inline int sapHornSuggestedEffectPct() {',
    '    // the suggested 25 percent effect share',
    '    return 25;',
    '}',
    '',
    'inline int sapHornIgnoresInappropriate() {',
    '    // inappropriate results are ignored',
    '    return 1;',
    '}',
    '',
    'inline int sapCoatArndOfTdon() {',
    '    // the High Priest Arnd of Tdon possessed it',
    '    return 1;',
    '}',
    '',
    'inline int sapCoatChainLinksWeightless() {',
    '    // a shimmering shirt of almost weightless links',
    '    return 1;',
    '}',
    '',
    'inline int sapCoatCoveredAreaCount() {',
    '    // covers upper arms, torso and groin',
    '    return 3;',
    '}',
    '',
    'inline int sapCoatMinWearerHeightFt() {',
    '    // the minimum 3 foot human-shaped wearer',
    '    return 3;',
    '}',
    '',
    'inline int sapCoatMaxWearerHeightFt() {',
    '    // the maximum 8 foot human-shaped wearer',
    '    return 8;',
    '}',
    '',
    'inline int sapCoatInvulnerableCovered() {',
    '    // totally invulnerable on covered areas',
    '    return 1;',
    '}',
    '',
    'inline int sapCoatUncoveredAc() {',
    '    // AC 5 protection on all other areas',
    '    return 5;',
    '}',
    '',
    'inline int sapCoatSaveBonus() {',
    '    // +5 to saving throws as +5 magic armor',
    '    return 5;',
    '}',
    '',
    'inline int sapCoatFireResistance() {',
    '    // fire protection as a ring of fire resistance',
    '    return 1;',
    '}',
    '',
    'inline int sapCoatElementalImmunityCount() {',
    '    // acid, cold and electrical attacks: no effect',
    '    return 3;',
    '}',
    '',
    'inline int sapCoatPowerTotal() {',
    '    // 3+2+2+1+1+1 - the total power count',
    '    return 10;',
    '}',
    '',
    'inline int sapOrganPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        7, 7, 3, 7, 7, 3,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapHornBlastPowerTable(int i) {',
    '    // the power table per 1, 2 or 3 blasts; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    static const int t[3] = {',
    '        1, 2, 5,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapHornBlastEffectTable(int i) {',
    '    // the effect table per 1, 2 or 3 blasts; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    static const int t[3] = {',
    '        3, 6, 4,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCoatPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 2, 2, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R285: the III.E Special artifacts',
    '    // explanation prose part 6 ----',
    '    // The Mystical Organ of Heward,',
    '    // The Horn of Change and',
    '    // The Invulnerable Coat of Arnd,',
    '    // part2 lines 1359-1403 (DMG',
    '    // p.161-162), the ninth through',
    '    // the 11th of the 29 artifact',
    '    // descriptions. No page break',
    '    // inside the slice this round.',
    '    {',
    '        int bad = 0;',
    '        // the Organ scalars',
    '        if (rules::sapOrganPipeCount() != 77 ||',
    '            rules::sapOrganStopCount() != 13 ||',
    '            rules::sapOrganPedalCount() != 3 ||',
    '            rules::sapOrganBellowsElemental() != 1 ||',
    '            rules::sapOrganStopsVaryVoice() != 1 ||',
    '            rules::sapOrganKeysVaryNotes() != 1 ||',
    '            rules::sapOrganPedalPurposeUnknown() != 1 ||',
    '            rules::sapOrganStillWorksDespiteTime() != 1) ++bad;',
    '        if (rules::sapOrganWrongStopsSummon() != 1 ||',
    '            rules::sapOrganWrongKeysBackfire() != 1 ||',
    '            rules::sapOrganMisplayAlignment() != 1 ||',
    '            rules::sapOrganDmAssignsStopsKeys() != 1 ||',
    '            rules::sapOrganPowerTotal() != 34 ||',
    '            rules::sapOrganMisplayNegates() != 1) ++bad;',
    '        // the Organ powers per table I-VI',
    '        static const int kOrg[6] = {',
    '            7, 7, 3, 7, 7, 3,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrganPowerCount(i) != kOrg[i]) ++bad;',
    '        if (rules::sapOrganPowerCount(0) +',
    '            rules::sapOrganPowerCount(1) +',
    '            rules::sapOrganPowerCount(2) +',
    '            rules::sapOrganPowerCount(3) +',
    '            rules::sapOrganPowerCount(4) +',
    '            rules::sapOrganPowerCount(5) !=',
    '            rules::sapOrganPowerTotal()) ++bad;',
    '        // the Horn scalars',
    '        if (rules::sapHornResemblesCommonHorns() != 1 ||',
    '            rules::sapHornSuggestedPowerPct() != 75 ||',
    '            rules::sapHornSuggestedEffectPct() != 25 ||',
    '            rules::sapHornIgnoresInappropriate() != 1) ++bad;',
    '        // the Horn blast mappings: 1 wind',
    '        // gives I or III, 2 give II or VI,',
    '        // 3 give V or IV',
    '        static const int kHbp[3] = {',
    '            1, 2, 5,',
    '        };',
    '        static const int kHbe[3] = {',
    '            3, 6, 4,',
    '        };',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::sapHornBlastPowerTable(i) != kHbp[i]) ++bad;',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::sapHornBlastEffectTable(i) != kHbe[i]) ++bad;',
    '        // the suggested split sums to 100',
    '        if (rules::sapHornSuggestedPowerPct() +',
    '            rules::sapHornSuggestedEffectPct() != 100) ++bad;',
    '        // the Coat scalars',
    '        if (rules::sapCoatArndOfTdon() != 1 ||',
    '            rules::sapCoatChainLinksWeightless() != 1 ||',
    '            rules::sapCoatCoveredAreaCount() != 3 ||',
    '            rules::sapCoatMinWearerHeightFt() != 3 ||',
    '            rules::sapCoatMaxWearerHeightFt() != 8 ||',
    '            rules::sapCoatInvulnerableCovered() != 1 ||',
    '            rules::sapCoatUncoveredAc() != 5) ++bad;',
    '        if (rules::sapCoatSaveBonus() != 5 ||',
    '            rules::sapCoatFireResistance() != 1 ||',
    '            rules::sapCoatElementalImmunityCount() != 3 ||',
    '            rules::sapCoatPowerTotal() != 10) ++bad;',
    '        // the Coat powers per table I-VI',
    '        static const int kCoat[6] = {',
    '            3, 2, 2, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapCoatPowerCount(i) != kCoat[i]) ++bad;',
    '        if (rules::sapCoatPowerCount(0) +',
    '            rules::sapCoatPowerCount(1) +',
    '            rules::sapCoatPowerCount(2) +',
    '            rules::sapCoatPowerCount(3) +',
    '            rules::sapCoatPowerCount(4) +',
    '            rules::sapCoatPowerCount(5) !=',
    '            rules::sapCoatPowerTotal()) ++bad;',
    '        // the AC 5 and the save +5 mirror',
    '        if (rules::sapCoatUncoveredAc() !=',
    '            rules::sapCoatSaveBonus()) ++bad;',
    '        // the wearer height range 3 to 8',
    '        if (rules::sapCoatMaxWearerHeightFt() -',
    '            rules::sapCoatMinWearerHeightFt() != 5) ++bad;',
    '        // the cross-pins: the R240 sale table rows',
    '        if (rules::saRowLo(8) != 26 ||',
    '            rules::saRowHi(8) != 26 ||',
    '            rules::saSaleGp(8) != 25000 ||',
    '            rules::saRowLo(9) != 27 ||',
    '            rules::saRowHi(9) != 27 ||',
    '            rules::saSaleGp(9) != 20000 ||',
    '            rules::saRowLo(10) != 28 ||',
    '            rules::saRowHi(10) != 29 ||',
    '            rules::saSaleGp(10) != 47500) ++bad;',
    '        printf("R285 special artifacts prose part 6 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R285 landed the III.E Special',
    'artifacts explanation prose part 6',
    '(part2 lines 1359-1403; global =',
    '11065 + part2 line),',
    'the Mystical Organ of Heward,',
    'the Horn of Change and',
    'the Invulnerable Coat of Arnd (DMG',
    'p.161-162), the ninth through the',
    '11th of the 29 artifact',
    'descriptions. The Organ: the',
    'Fables of Burdock mention a large',
    'musical instrument of such power',
    'the enchantments are only hinted',
    'at; 77 great and small pipes, a',
    'console with keys of black and',
    'white beneath 13 ivory stops, 3',
    'great foot pedals; the bellows',
    'worked by a conjured and chained',
    'air elemental of huge size; each',
    'stop sounds the pipes in a',
    'different voice, the keys vary the',
    'notes; no one is certain what',
    'purpose the foot pedals serve;',
    'despite time-silenced pipes and',
    'abused, unworkable keys and stops',
    'it still works mighty magicks when',
    'properly played; pulling the wrong',
    'stops summons something undesired',
    'or casts the wrong spell; wrong',
    'keys unbind what was called or the',
    'magic backfires; improper playing',
    'may change the alignment of the',
    'caster or manipulator; the DM',
    'decides which stops and key',
    'sequences do what; powers 7 each',
    'of tables I, II, IV and V, 3 each',
    'of III and VI, total 34;',
    'misplaying can negate, reverse or',
    'change the effects. The Horn:',
    'exactly resembles the more common',
    'magical horns, blasting or',
    'bubbles; 1 winding gives a table I',
    'power or a table III effect; 2',
    'soundings give II or VI; 3 blasts',
    'give V or IV; the DM dices the',
    'power-or-effect choice, 75 percent',
    'power and 25 percent effect',
    'suggested; inappropriate results',
    'are ignored. The Coat: the High',
    'Priest Arnd of Tdon the original',
    'possessor; a bright, shimmering',
    'shirt of fine, almost weightless',
    'chain links; covers the upper',
    'arms, torso and groin of any',
    'human-shaped wearer from 3 to 8',
    'feet tall; totally invulnerable to',
    'physical attacks on the covered',
    'areas, AC 5 protection everywhere',
    'else; adds +5 to saving throws as',
    'if +5 magic armor; fire protection',
    'as a ring of fire resistance;',
    'acid, cold and electrical attacks',
    'have no effect; powers 3 of table',
    'I, 2 each of II and III, 1 each of',
    'IV, V and VI, total 10.',
    'No page break falls inside the',
    'slice this round. The upload',
    'quirks: the power lines print the',
    'counts as N x table with the true',
    'multiplication sign, 10 of them;',
    'the 7 x I, 7 x II, 7 x IV and 7 x',
    'V Organ lines each wrap across two',
    'lines; the blank slots print 14',
    'underscores this section; the',
    'tunes paragraph prints curly',
    'double quotes and right single',
    'quotes; the warning dashes print',
    'as em-dashes; the Horn paragraph',
    'wraps across the 1387-1389 pair -',
    'all pinned as plain digits and',
    'words, apostrophe-free here. 33',
    'accessors: 29 scalars + 4 walkers',
    '(the organ power walker',
    '7,7,3,7,7,3, the horn blast',
    'walkers 1,2,5 and 3,6,4, the coat',
    'power walker 3,2,2,1,1,1), no name',
    'collisions with the miscprose and',
    'specart headers; the audit',
    'cross-pins the R240 sale table',
    'rows - the Organ band 26 at 25000,',
    'the Horn band 27 at 20000, the',
    'Coat band 28-29 at 47500',
    '(census 203). Next: R286 III.E',
    'Special part 7 - the Iron Flask of',
    'Tuerny the Merciless onward in',
    'part2 from line 1405 (global',
    '12470; the Jacinth of Inestimable',
    'Beauty, Johydees Mask and the',
    'other descriptions follow; the',
    'III.E Special prose continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 33, 'accessor count is not 33'
assert len(set(defs)) == 33, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 29, 'scalar count is not 29'
walk = [d for d in defs if d not in scal]
assert len(walk) == 4, 'walker count is not 4'
assert set(walk) == {'sapOrganPowerCount', 'sapHornBlastPowerTable',
    'sapHornBlastEffectTable', 'sapCoatPowerCount', }, 'wrong walkers'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(sap[A-Za-z0-9]+)[(]', ATEXT))
assert audited == set(defs), 'audit does not probe every accessor'
for fn in sorted(os.listdir(os.path.join(ROOT, 'rules'))):
    if not fn.endswith('.h') or fn == 'specartprose2.h':
        continue
    pt = open(os.path.join(ROOT, 'rules', fn), encoding='utf-8').read()
    for n in defs:
        assert n not in pt, 'name collision with ' + fn
s0 = rd('rules/specartprose2.h')
assert 'sapEyeVecnaPhantomRoams' in s0, 'specartprose2.h missing the R284 accessors'
assert 'sapCrystalOriginUnknown' in s0, 'specartprose2.h missing the R283 accessors'
assert 'sapCrownRegaliaSetCount' in s0, 'specartprose2.h missing the R282 accessors'
assert s0.count('}  // namespace rules') == 1, 'namespace close not unique'
for grp in (PINS, AUDIT, GAP):
    for el in grp:
        assert chr(39) not in el, 'apostrophe in content'
        probe = el.replace(chr(92) + 'n', '')
        assert chr(92) not in probe, 'backslash in content'
        assert NL not in el, 'list element spans lines'
for el in GAP:
    assert len(el) <= 34, 'gap line too long: ' + el
assert ATEXT.count('{') == ATEXT.count('}'), 'audit braces unbalanced'
assert ATEXT.count('(') == ATEXT.count(')'), 'audit parens unbalanced'
assert AUDIT[-1] == '    }', 'audit block does not close'
assert PINS[-1] == '', 'pins block must end with a blank line'
assert PTEXT.count('{') == PTEXT.count('}'), 'pins braces unbalanced'
assert ATEXT.count('R285 special artifacts prose part 6 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 6', 'the Mystical Organ of Heward', 'the Horn of Change',
             'the Invulnerable Coat of', '1359-1403',
             'census 203', 'R286', 'line 1405', '12470',
             'p.161-162', 'No page break'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 6', 'The Mystical Organ of Heward',
             'The Horn of Change',
             'The Invulnerable Coat of Arnd',
             '1359-1403'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapOrganPipeCount() {'
if mark in s:
    already += 1
else:
    anchor = '}  // namespace rules'
    assert s.count(anchor) == 1, 'namespace anchor not unique'
    s = s.replace(anchor, PTEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 1 failed'
assert s.count('}  // namespace rules') == 1, 'patch 1 broke the close'
assert s.endswith('}  // namespace rules'), 'patch 1 broke the tail'
alldefs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', s)
assert len(alldefs) == 151, 'accessor count is not 151'
assert len(set(alldefs)) == 151, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R285: the III.E Special artifacts'
if mark in s:
    already += 1
else:
    anchor = '    // ---- R227: the wis mental save wiring audit ----'
    assert s.count(anchor) == 1, 'audit anchor not unique'
    s = s.replace(anchor, ATEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 2 failed'
assert s.count('R285 special artifacts prose part 6 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R285 landed the III.E Special'
if mark in s:
    already += 1
else:
    anchor = 'continue).' + NL + NL + 'Categories:'
    assert s.count(anchor) == 1, 'gap anchor not unique'
    s = s.replace(anchor, 'continue).' + NL + NL + NL.join(GAP) + NL + NL + 'Categories:', 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 3 failed'

print('R285 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R285 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 6 - the Mystical Organ of')
print('Heward, the Horn of Change and the')
print('Invulnerable Coat of Arnd, part2')
print('lines 1359-1403; census 203.')
print('commit: R285: the III.E Special artifacts explanation prose part 6 pinned - the Mystical Organ of Heward, the Horn of Change and the Invulnerable Coat of Arnd in part2 lines 1359-1403 (census 203)')

