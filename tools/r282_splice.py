#!/usr/bin/env python3
# R282 splice: the III.E Special artifacts
# explanation prose part 3 pins - the Crown
# of Might, part2 lines 1237-1268 (DMG
# p.160), the fourth of the 29 artifact
# descriptions, the first item of the three
# regalia sets of Might. The Crown: regalia
# for the special servants of the deities
# of each alignment; a crown, an orb and a
# sceptre per champion of the 3 ethic
# alignments (Evil, Good, Neutrality); the
# 3 complete sets scattered and lost over
# the centuries; mere possession benefits a
# same-ethos character; a wrong-ethos touch
# deals 5-30 hit points and demands a save
# versus magic or instant death; the
# alignment table 01-06 Evil, 07-14 Good,
# 15-20 Neutrality; while worn the Crown
# raises the level of experience by 1 and
# confers powers 2 of table I and 1 each of
# tables II and III; an off-ethos Orb or
# Sceptre touch deals the same damage and
# save, a successful save drawing 1
# malevolent power from table IV; a
# same-ethos Orb or Sceptre adds 1 each of
# tables I and II (the 2nd item of the
# set) and 1 each of tables I, II, IV, V
# and VI (the 3rd item); examination
# reveals no difference and detection not
# the ethic alignment; a slender gold
# diadem set with 3 precious stones of
# great size worth 50,000 or more gold
# pieces if openly sold. No seam this
# round: the slice lies wholly on p.160 -
# the p.160-161 break splits the Hand of
# Vecna paragraph (a later round). The
# upload quirks this round: the power
# tables print the counts as N x table
# with the true multiplication sign, 10
# of them, in markdown tables of blank
# fills; the ethic alignment dashes print
# as true em-dashes; the wearer level line
# prints the curly apostrophe - all pinned
# as plain digits and words, apostrophe-free
# here. 21 accessors: 16 scalars + 5
# walkers (the alignment band lo/hi
# walkers, the worn power walker, the set
# 2nd item walker and the set 3rd item
# walker), no name collisions with the
# miscprose and specart headers. The audit
# cross-pins the R240 sale table row: the
# Crown band 05-20 at 50000.
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

CROWN = [
    'inline int sapCrownRegaliaSetCount() {',
    '    // these 3 complete sets bestow great powers',
    '    return 3;',
    '}',
    '',
    'inline int sapCrownItemsPerSet() {',
    '    // a crown, an orb and a sceptre per champion',
    '    return 3;',
    '}',
    '',
    'inline int sapCrownChampionEthosCount() {',
    '    // the champion of each ethic alignment',
    '    return 3;',
    '}',
    '',
    'inline int sapCrownPossessionBenefits() {',
    '    // mere possession benefits a same-ethos character',
    '    return 1;',
    '}',
    '',
    'inline int sapCrownWrongEthosDamageMin() {',
    '    // a wrong-ethos touch deals 5-30 hit points',
    '    return 5;',
    '}',
    '',
    'inline int sapCrownWrongEthosDamageMax() {',
    '    // the upper edge of the 5-30 hit points',
    '    return 30;',
    '}',
    '',
    'inline int sapCrownWrongEthosSaveOrDeath() {',
    '    // save versus magic or be instantly killed',
    '    return 1;',
    '}',
    '',
    'inline int sapCrownWearerLevelBonus() {',
    '    // raises the level of experience by 1 while worn',
    '    return 1;',
    '}',
    '',
    'inline int sapCrownWornPowerTotal() {',
    '    // 2 of table I plus 1 each of tables II-III',
    '    return 4;',
    '}',
    '',
    'inline int sapCrownOffEthosMalevolentCount() {',
    '    // 1 malevolent power on a successful save',
    '    return 1;',
    '}',
    '',
    'inline int sapCrownOffEthosMalevolentTable() {',
    '    // the malevolent power comes from table IV',
    '    return 4;',
    '}',
    '',
    'inline int sapCrownSet2ndPowerTotal() {',
    '    // the same-ethos 2nd item adds 1 each of I-II',
    '    return 2;',
    '}',
    '',
    'inline int sapCrownSet3rdPowerTotal() {',
    '    // the 3rd item adds 1 each of I, II, IV-VI',
    '    return 5;',
    '}',
    '',
    'inline int sapCrownDetectionRevealsAlignment() {',
    '    // detection magically will not reveal the alignment',
    '    return 0;',
    '}',
    '',
    'inline int sapCrownGemCount() {',
    '    // set with 3 precious stones of great size',
    '    return 3;',
    '}',
    '',
    'inline int sapCrownSaleGpMin() {',
    '    // 50,000 or more gold pieces if openly sold',
    '    return 50000;',
    '}',
    '',
    'inline int sapCrownAlignBandLo(int i) {',
    '    // the alignment band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    static const int t[3] = {',
    '        1, 7, 15,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCrownAlignBandHi(int i) {',
    '    // the alignment band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    static const int t[3] = {',
    '        6, 14, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCrownWornPowerCount(int i) {',
    '    // the worn powers per tables I-III; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    static const int t[3] = {',
    '        2, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCrownSet2ndPowerCount(int i) {',
    '    // the 2nd item powers per tables I-II; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 1) i = 1;',
    '    static const int t[2] = {',
    '        1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCrownSet3rdPowerCount(int i) {',
    '    // the 3rd item powers per I, II, IV-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 4) i = 4;',
    '    static const int t[5] = {',
    '        1, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R282: the III.E Special artifacts',
    '    // explanation prose part 3 ----',
    '    // The Crown of Might, part2 lines 1237-1268',
    '    // (DMG p.160) - the fourth of the 29 artifact',
    '    // descriptions, the first item of the regalia',
    '    // sets of Might. No seam this round: the slice',
    '    // lies wholly on p.160.',
    '    {',
    '        int bad = 0;',
    '        // the Crown scalars',
    '        if (rules::sapCrownRegaliaSetCount() != 3 ||',
    '            rules::sapCrownItemsPerSet() != 3 ||',
    '            rules::sapCrownChampionEthosCount() != 3 ||',
    '            rules::sapCrownPossessionBenefits() != 1 ||',
    '            rules::sapCrownWrongEthosDamageMin() != 5 ||',
    '            rules::sapCrownWrongEthosDamageMax() != 30 ||',
    '            rules::sapCrownWrongEthosSaveOrDeath() != 1 ||',
    '            rules::sapCrownWearerLevelBonus() != 1 ||',
    '            rules::sapCrownWornPowerTotal() != 4 ||',
    '            rules::sapCrownOffEthosMalevolentCount() != 1 ||',
    '            rules::sapCrownOffEthosMalevolentTable() != 4 ||',
    '            rules::sapCrownSet2ndPowerTotal() != 2 ||',
    '            rules::sapCrownSet3rdPowerTotal() != 5 ||',
    '            rules::sapCrownDetectionRevealsAlignment() != 0 ||',
    '            rules::sapCrownGemCount() != 3 ||',
    '            rules::sapCrownSaleGpMin() != 50000) ++bad;',
    '        // the alignment bands per ethos',
    '        static const int kCrl[3] = {',
    '            1, 7, 15,',
    '        };',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::sapCrownAlignBandLo(i) != kCrl[i]) ++bad;',
    '        static const int kCrh[3] = {',
    '            6, 14, 20,',
    '        };',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::sapCrownAlignBandHi(i) != kCrh[i]) ++bad;',
    '        // the bands are contiguous and span the d20',
    '        if (rules::sapCrownAlignBandLo(0) != 1) ++bad;',
    '        if (rules::sapCrownAlignBandHi(2) != 20) ++bad;',
    '        if (rules::sapCrownAlignBandHi(0) + 1 !=',
    '            rules::sapCrownAlignBandLo(1)) ++bad;',
    '        if (rules::sapCrownAlignBandHi(1) + 1 !=',
    '            rules::sapCrownAlignBandLo(2)) ++bad;',
    '        // the worn powers per tables I-III',
    '        static const int kCrw[3] = {',
    '            2, 1, 1,',
    '        };',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::sapCrownWornPowerCount(i) != kCrw[i]) ++bad;',
    '        if (rules::sapCrownWornPowerCount(0) +',
    '            rules::sapCrownWornPowerCount(1) +',
    '            rules::sapCrownWornPowerCount(2) !=',
    '            rules::sapCrownWornPowerTotal()) ++bad;',
    '        // the same-ethos 2nd item powers per I-II',
    '        static const int kCs2[2] = {',
    '            1, 1,',
    '        };',
    '        for (int i = 0; i < 2; ++i)',
    '            if (rules::sapCrownSet2ndPowerCount(i) != kCs2[i]) ++bad;',
    '        if (rules::sapCrownSet2ndPowerCount(0) +',
    '            rules::sapCrownSet2ndPowerCount(1) !=',
    '            rules::sapCrownSet2ndPowerTotal()) ++bad;',
    '        // the same-ethos 3rd item powers',
    '        static const int kCs3[5] = {',
    '            1, 1, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 5; ++i)',
    '            if (rules::sapCrownSet3rdPowerCount(i) != kCs3[i]) ++bad;',
    '        if (rules::sapCrownSet3rdPowerCount(0) +',
    '            rules::sapCrownSet3rdPowerCount(1) +',
    '            rules::sapCrownSet3rdPowerCount(2) +',
    '            rules::sapCrownSet3rdPowerCount(3) +',
    '            rules::sapCrownSet3rdPowerCount(4) !=',
    '            rules::sapCrownSet3rdPowerTotal()) ++bad;',
    '        // the complete regalia set of one ethos',
    '        if (rules::sapCrownWornPowerTotal() +',
    '            rules::sapCrownSet2ndPowerTotal() +',
    '            rules::sapCrownSet3rdPowerTotal() != 11) ++bad;',
    '        // the sets and the champions pair one to one',
    '        if (rules::sapCrownRegaliaSetCount() !=',
    '            rules::sapCrownChampionEthosCount()) ++bad;',
    '        // the wrong-ethos damage spread reads 5d6',
    '        if (rules::sapCrownWrongEthosDamageMin() * 6 !=',
    '            rules::sapCrownWrongEthosDamageMax()) ++bad;',
    '        // the cross-pin: the R240 sale table row',
    '        if (rules::saRowLo(3) != 5 ||',
    '            rules::saRowHi(3) != 20 ||',
    '            rules::saSaleGp(3) != 50000) ++bad;',
    '        if (rules::sapCrownSaleGpMin() !=',
    '            rules::saSaleGp(3)) ++bad;',
    '        printf("R282 special artifacts prose part 3 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R282 landed the III.E Special',
    'artifacts and relics explanation',
    'prose part 3 (part2 lines',
    '1237-1268; global = 11065 +',
    'part2 line), the Crown of Might',
    '(DMG p.160) - the fourth of the',
    '29 artifact descriptions, the',
    'first item of the regalia',
    'sets of Might: great regalia',
    'for the special servants of the',
    'deities of each alignment, the',
    'champion of each ethic',
    'alignment - Evil, Good,',
    'Neutrality - given a crown, an',
    'orb and a sceptre, the 3',
    'complete sets scattered and',
    'lost over the centuries, mere',
    'possession benefiting a',
    'same-ethos character, a',
    'wrong-ethos touch dealing',
    '5-30 hit points with a save',
    'versus magic or instant death,',
    'the alignment table 01-06',
    'Evil, 07-14 Good, 15-20',
    'Neutrality, the wearer raised',
    '1 experience level with worn',
    'powers 2 of table I and 1',
    'each of tables II and III, an',
    'off-ethos Orb or Sceptre',
    'touch dealing the same damage',
    'and save with 1 malevolent',
    'power from table IV on a',
    'successful save, the',
    'same-ethos 2nd item of the',
    'set adding 1 each of tables',
    'I and II, the 3rd item',
    'adding 1 each of tables I,',
    'II, IV, V and VI, examination',
    'revealing no difference and',
    'detection not revealing the',
    'ethic alignment, a slender',
    'gold diadem set with 3',
    'precious stones of great',
    'size worth 50,000 or more',
    'gold pieces if openly sold.',
    'No seam this round: the slice',
    'lies wholly on p.160 - the',
    'p.160-161 break splits the',
    'Hand of Vecna paragraph (a',
    'later round). The upload',
    'quirks: the power tables print',
    'the counts as N x table with',
    'the true multiplication',
    'sign, 10 of them, in markdown',
    'tables of blank fills; the',
    'ethic alignment dashes print',
    'as true em-dashes; the wearer',
    'level line prints the curly',
    'apostrophe - all pinned as',
    'plain digits and words,',
    'apostrophe-free here. 21',
    'accessors: 16 scalars + 5',
    'walkers (the alignment band',
    'lo/hi walkers 1,7,15 and',
    '6,14,20, the worn power',
    'walker 2,1,1, the set 2nd',
    'item walker 1,1 and the set',
    '3rd item walker 1,1,1,1,1), no',
    'name collisions with the',
    'miscprose and specart',
    'headers; the audit cross-pins',
    'the R240 sale table row - the',
    'Crown band 05-20 at 50000',
    '(census 200). Next: R283 III.E',
    'Special part 4 - the Crystal',
    'of the Ebon Flame onward in',
    'part2 from line 1270 (global',
    '12335; the Cup and Talisman',
    'of Al Akbar, the Eye and the',
    'Hand of Vecna and the other',
    'descriptions follow; the',
    'III.E Special prose continue).',
]

# ---- the splice self-asserts ----
CTEXT = NL.join(CROWN)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', CTEXT)
assert len(defs) == 21, 'accessor count is not 21'
assert len(set(defs)) == 21, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', CTEXT)
assert len(scal) == 16, 'scalar count is not 16'
walk = [d for d in defs if d not in scal]
assert len(walk) == 5, 'walker count is not 5'
assert set(walk) == {'sapCrownAlignBandLo', 'sapCrownAlignBandHi',
                    'sapCrownWornPowerCount', 'sapCrownSet2ndPowerCount',
                    'sapCrownSet3rdPowerCount', }, 'wrong walkers'
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
assert 'sapCodexPowerCount' in s0, 'specartprose2.h missing the R281 accessors'
assert s0.count('}  // namespace rules') == 1, 'namespace close not unique'
for grp in (CROWN, AUDIT, GAP):
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
assert CROWN[-1] == '', 'crown block must end with a blank line'
assert CTEXT.count('{') == CTEXT.count('}'), 'crown braces unbalanced'
assert ATEXT.count('R282 special artifacts prose part 3 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 3', 'No seam', 'DMG p.160', 'the Crown of Might',
             '1237-1268', 'census 200', 'R283', 'line 1270', '12335'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('Crown of Might', '1237-1268', 'No seam',
             'DMG p.160'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapCrownRegaliaSetCount() {'
if mark in s:
    already += 1
else:
    anchor = '}  // namespace rules'
    assert s.count(anchor) == 1, 'namespace anchor not unique'
    s = s.replace(anchor, CTEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 1 failed'
assert s.count('}  // namespace rules') == 1, 'patch 1 broke the close'
assert s.endswith('}  // namespace rules'), 'patch 1 broke the tail'
alldefs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', s)
assert len(alldefs) == 58, 'accessor count is not 58'
assert len(set(alldefs)) == 58, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R282: the III.E Special artifacts'
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
assert s.count('R282 special artifacts prose part 3 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R282 landed the III.E Special'
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

print('R282 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R282 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 3 - the Crown of Might, part2')
print('lines 1237-1268; census 200.')
print('commit: R282: the III.E Special artifacts explanation prose part 3 pinned - the Crown of Might in part2 lines 1237-1268 (census 200)')

