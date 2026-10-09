#!/usr/bin/env python3
# R293 splice: the III.E Special
# artifacts explanation prose part
# 14 pins - the Sceptre of Might and
# the Sword of Kas, the 25th and 26th
# of the 29 artifact descriptions,
# part2 lines 1708-1743. The Sceptre:
# 3 of them, sourced to the foregoing
# Crown of Might; ethos die bands
# 1-6 evil, 7-14 good, 15-20
# neutrality - the same bands the
# R290 Orb accessors carry; a
# foreign-ethos touch works the
# Crown effects; bronze inlaid with
# silver and many fine gems, a huge
# precious stone tipping its 2 feet;
# value 150000 or more gold pieces;
# functions as a Rod of Beguiling;
# powers one use each of tables
# I, II and VI (walker 1,1,0,0,0,1,
# total 3). The Sword of Kas: the
# Vecna legend - the bodyguard and
# right hand, the long thin flatchet
# of dull gray metal, the faithful
# service, the hubris, the Sword
# urging him on, the destruction of
# Vecna, the lieutenant doom, the
# brighter world; a +6 defender,
# double damage off-plane, normal
# damage on other planes; a short
# sword, highly evil and chaotic;
# 15 intelligence, 19 ego, and it
# attempts to control its taker;
# powers 5,2,1,2,2,1 (13), printed
# in order I through VI. No break
# absorbed - the round closes on
# the standard blank at 1743; no
# page seam claimed (no running
# heads between upload lines 1450
# and 1797). 45 accessors: 43
# scalars + 2 walkers. The audit
# cross-pins the R240 sale rows 24
# and 25: 75-91 at 150000 and 92
# at 97000 - a range row and a
# fixed single-die row.
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
    'inline int sapSceptreCount() {',
    '    // the 3 Sceptres of Might',
    '    return 3;',
    '}',
    '',
    'inline int sapSceptreSourceCrownOfMight() {',
    '    // the legendary source: the Crown section',
    '    return 1;',
    '}',
    '',
    'inline int sapSceptreEvilBandLo() {',
    '    // the evil ethos band, low die',
    '    return 1;',
    '}',
    '',
    'inline int sapSceptreEvilBandHi() {',
    '    // the evil ethos band, high die',
    '    return 6;',
    '}',
    '',
    'inline int sapSceptreGoodBandLo() {',
    '    // the good ethos band, low die',
    '    return 7;',
    '}',
    '',
    'inline int sapSceptreGoodBandHi() {',
    '    // the good ethos band, high die',
    '    return 14;',
    '}',
    '',
    'inline int sapSceptreNeutralBandLo() {',
    '    // the neutrality ethos band, low die',
    '    return 15;',
    '}',
    '',
    'inline int sapSceptreNeutralBandHi() {',
    '    // the neutrality ethos band, high die',
    '    return 20;',
    '}',
    '',
    'inline int sapSceptreForeignEthosCrownEffects() {',
    '    // a foreign-ethos touch works the Crown effects',
    '    return 1;',
    '}',
    '',
    'inline int sapSceptreBronzeInlaidSilver() {',
    '    // wrought of bronze inlaid with silver',
    '    return 1;',
    '}',
    '',
    'inline int sapSceptreHugeStoneTipping() {',
    '    // a huge precious stone tips it',
    '    return 1;',
    '}',
    '',
    'inline int sapSceptreLengthFeet() {',
    '    // the length, in feet',
    '    return 2;',
    '}',
    '',
    'inline int sapSceptreValueGp() {',
    '    // the open market value, in gold pieces',
    '    return 150000;',
    '}',
    '',
    'inline int sapSceptreRodOfBeguiling() {',
    '    // it functions as a Rod of Beguiling',
    '    return 1;',
    '}',
    '',
    'inline int sapSceptreUseTotal() {',
    '    // 1+1+1 - the use total',
    '    return 3;',
    '}',
    '',
    'inline int sapSceptreCrownOrbComboNote() {',
    '    // combo powers with a same-ethos Crown or Orb',
    '    return 1;',
    '}',
    '',
    'inline int sapSceptreBlankSlotCount() {',
    '    // the DM-fill blanks, 3 rows of 3 runs each',
    '    return 9;',
    '}',
    '',
    'inline int sapSceptreTableUse(int i) {',
    '    // the uses per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        1, 1, 0, 0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapKasOfVecnaTheLich() {',
    '    // recorded of the lich Vecna',
    '    return 1;',
    '}',
    '',
    'inline int sapKasBodyguardRightHand() {',
    '    // the bodyguard and right hand of Vecna',
    '    return 1;',
    '}',
    '',
    'inline int sapKasFlatchetDullGrayMetal() {',
    '    // a long and thin flatchet of dull gray metal',
    '    return 1;',
    '}',
    '',
    'inline int sapKasSharpPointKeenEdges() {',
    '    // sharp point, keen edges, magical properties',
    '    return 1;',
    '}',
    '',
    'inline int sapKasServedFaithfully() {',
    '    // Kas faithfully served the lich',
    '    return 1;',
    '}',
    '',
    'inline int sapKasHubrisGrew() {',
    '    // his power grew and so did his hubris',
    '    return 1;',
    '}',
    '',
    'inline int sapKasSwordUrgedHimOn() {',
    '    // the Sword constantly urged him on',
    '    return 1;',
    '}',
    '',
    'inline int sapKasGreaterThanVecna() {',
    '    // it said Kas was greater than Vecna himself',
    '    return 1;',
    '}',
    '',
    'inline int sapKasCouldRuleInVecnaStead() {',
    '    // with it Kas could rule in Vecna stead',
    '    return 1;',
    '}',
    '',
    'inline int sapKasDestroyedVecna() {',
    '    // legend: Kas and his Sword destroyed Vecna',
    '    return 1;',
    '}',
    '',
    'inline int sapKasDoomWroughtTogether() {',
    '    // Vecna wrought the lieutenant doom too',
    '    return 1;',
    '}',
    '',
    'inline int sapKasWorldBrighter() {',
    '    // the world was made brighter thereby',
    '    return 1;',
    '}',
    '',
    'inline int sapKasPowersOnlyHinted() {',
    '    // the powers and effects are only hinted at',
    '    return 1;',
    '}',
    '',
    'inline int sapKasRenownedSwordsman() {',
    '    // the most renowned swordsman of his age',
    '    return 1;',
    '}',
    '',
    'inline int sapKasPlusBonus() {',
    '    // the enchantment plus of the +6 defender',
    '    return 6;',
    '}',
    '',
    'inline int sapKasDefender() {',
    '    // it is a defender',
    '    return 1;',
    '}',
    '',
    'inline int sapKasDoubleDamageOffPlane() {',
    '    // double damage to off-plane creatures',
    '    return 1;',
    '}',
    '',
    'inline int sapKasNormalDamageOnOtherPlanes() {',
    '    // normal damage when on any other plane',
    '    return 1;',
    '}',
    '',
    'inline int sapKasShortSword() {',
    '    // a short sword',
    '    return 1;',
    '}',
    '',
    'inline int sapKasEvilChaoticAlignment() {',
    '    // highly evil and chaotic in alignment',
    '    return 1;',
    '}',
    '',
    'inline int sapKasIntelligence() {',
    '    // the sword intelligence',
    '    return 15;',
    '}',
    '',
    'inline int sapKasEgo() {',
    '    // the sword ego',
    '    return 19;',
    '}',
    '',
    'inline int sapKasTriesToControl() {',
    '    // it attempts to control whoever takes it',
    '    return 1;',
    '}',
    '',
    'inline int sapKasUseTotal() {',
    '    // 5+2+1+2+2+1 - the use total',
    '    return 13;',
    '}',
    '',
    'inline int sapKasBlankSlotCount() {',
    '    // the DM-fill blanks, one per use',
    '    return 13;',
    '}',
    '',
    'inline int sapKasPrintsInOrder() {',
    '    // the powers print in order I through VI',
    '    return 1;',
    '}',
    '',
    'inline int sapKasTableUse(int i) {',
    '    // the uses per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        5, 2, 1, 2, 2, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R293: the III.E Special artifacts',
    '    // explanation prose part 14 ----',
    '    // The Sceptre of Might and the',
    '    // Sword of Kas, part2 lines',
    '    // 1708-1743. No break absorbed -',
    '    // the round closes on the standard',
    '    // blank at 1743; no page seam claimed',
    '    // (no running heads between lines 1450',
    '    // and 1797).',
    '    {',
    '        int bad = 0;',
    '        // the Sceptre scalars, bands and blanks',
    '        if (rules::sapSceptreCount() != 3 ||',
    '            rules::sapSceptreSourceCrownOfMight() != 1 ||',
    '            rules::sapSceptreEvilBandLo() != 1 ||',
    '            rules::sapSceptreEvilBandHi() != 6 ||',
    '            rules::sapSceptreGoodBandLo() != 7 ||',
    '            rules::sapSceptreGoodBandHi() != 14 ||',
    '            rules::sapSceptreNeutralBandLo() != 15 ||',
    '            rules::sapSceptreNeutralBandHi() != 20 ||',
    '            rules::sapSceptreForeignEthosCrownEffects() != 1 ||',
    '            rules::sapSceptreBronzeInlaidSilver() != 1 ||',
    '            rules::sapSceptreHugeStoneTipping() != 1 ||',
    '            rules::sapSceptreLengthFeet() != 2 ||',
    '            rules::sapSceptreValueGp() != 150000 ||',
    '            rules::sapSceptreRodOfBeguiling() != 1 ||',
    '            rules::sapSceptreCrownOrbComboNote() != 1 ||',
    '            rules::sapSceptreBlankSlotCount() != 9) ++bad;',
    '        static const int kS[6] = {',
    '            1, 1, 0, 0, 0, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapSceptreTableUse(i) != kS[i]) ++bad;',
    '        if (rules::sapSceptreTableUse(0) +',
    '            rules::sapSceptreTableUse(1) +',
    '            rules::sapSceptreTableUse(2) +',
    '            rules::sapSceptreTableUse(3) +',
    '            rules::sapSceptreTableUse(4) +',
    '            rules::sapSceptreTableUse(5) !=',
    '            rules::sapSceptreUseTotal()) ++bad;',
    '        // the Kas legend scalars',
    '        if (rules::sapKasOfVecnaTheLich() != 1 ||',
    '            rules::sapKasBodyguardRightHand() != 1 ||',
    '            rules::sapKasFlatchetDullGrayMetal() != 1 ||',
    '            rules::sapKasSharpPointKeenEdges() != 1 ||',
    '            rules::sapKasServedFaithfully() != 1 ||',
    '            rules::sapKasHubrisGrew() != 1 ||',
    '            rules::sapKasSwordUrgedHimOn() != 1 ||',
    '            rules::sapKasGreaterThanVecna() != 1 ||',
    '            rules::sapKasCouldRuleInVecnaStead() != 1 ||',
    '            rules::sapKasDestroyedVecna() != 1 ||',
    '            rules::sapKasDoomWroughtTogether() != 1 ||',
    '            rules::sapKasWorldBrighter() != 1) ++bad;',
    '        // the blade scalars',
    '        if (rules::sapKasPowersOnlyHinted() != 1 ||',
    '            rules::sapKasRenownedSwordsman() != 1 ||',
    '            rules::sapKasPlusBonus() != 6 ||',
    '            rules::sapKasDefender() != 1 ||',
    '            rules::sapKasDoubleDamageOffPlane() != 1 ||',
    '            rules::sapKasNormalDamageOnOtherPlanes() != 1 ||',
    '            rules::sapKasShortSword() != 1 ||',
    '            rules::sapKasEvilChaoticAlignment() != 1 ||',
    '            rules::sapKasIntelligence() != 15 ||',
    '            rules::sapKasEgo() != 19 ||',
    '            rules::sapKasTriesToControl() != 1 ||',
    '            rules::sapKasPrintsInOrder() != 1) ++bad;',
    '        static const int kK[6] = {',
    '            5, 2, 1, 2, 2, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapKasTableUse(i) != kK[i]) ++bad;',
    '        if (rules::sapKasTableUse(0) +',
    '            rules::sapKasTableUse(1) +',
    '            rules::sapKasTableUse(2) +',
    '            rules::sapKasTableUse(3) +',
    '            rules::sapKasTableUse(4) +',
    '            rules::sapKasTableUse(5) !=',
    '            rules::sapKasUseTotal()) ++bad;',
    '        // each Kas use carries one blank slot',
    '        if (rules::sapKasBlankSlotCount() !=',
    '            rules::sapKasUseTotal()) ++bad;',
    '        // the cross-pins: the R240 sale rows 24 and 25',
    '        // (a range row and a fixed single-die row)',
    '        if (rules::saRowLo(24) != 75 ||',
    '            rules::saRowHi(24) != 91 ||',
    '            rules::saSaleGp(24) != 150000 ||',
    '            rules::saSaleGpHi(24) != 0 ||',
    '            rules::saSaleGp(24) !=',
    '            rules::sapSceptreValueGp()) ++bad;',
    '        if (rules::saRowLo(25) != 92 ||',
    '            rules::saRowHi(25) != 92 ||',
    '            rules::saSaleGp(25) != 97000 ||',
    '            rules::saSaleGpHi(25) != 0) ++bad;',
    '        printf("R293 special artifacts prose part 14 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R293 landed the III.E Special',
    'artifacts explanation prose',
    'part 14 (part2 lines 1708-1743;',
    'global = 11065 + part2 line),',
    'the 25th and 26th of the 29',
    'descriptions: the Sceptre of',
    'Might, and the Sword of Kas.',
    'The Sceptre: 3 of them, the',
    'legendary source the foregoing',
    'Crown of Might section; ethos',
    'bands 1-6 evil, 7-14 good,',
    '15-20 neutrality - the same',
    'die bands the R290 Orb',
    'accessors carry; a foreign',
    'ethos touch works the Crown',
    'effects; bronze inlaid with',
    'silver and many fine gems, a',
    'huge precious stone tipping',
    'its 2 feet length; value',
    '150000 or more gold pieces; it',
    'functions as a Rod of',
    'Beguiling; powers one use each',
    'of tables I, II and VI (walker',
    '1,1,0,0,0,1, total 3);',
    'additional powers in combo',
    'with a Crown or Orb of the',
    'same ethos - see Crown of',
    'Might. No break absorbed - the',
    'round closes on the standard',
    'blank at 1743; no page seam',
    'claimed (no running heads',
    'between lines 1450 and 1797).',
    'The Sword of Kas: recorded of',
    'the lich Vecna - Kas the most',
    'evil and ruthless lieutenant,',
    'bodyguard and right hand; a',
    'long and thin flatchet of dull',
    'gray metal, unsurpassed',
    'hardness, sharp point, keen',
    'edges, magical properties; he',
    'served faithfully, his hubris',
    'grew, the Sword urging him on',
    '- greater than Vecna, he could',
    'rule in Vecna stead; legend:',
    'Kas and his Sword destroyed',
    'Vecna, but Vecna wrought the',
    'lieutenant doom too, the world',
    'made brighter. Its powers',
    'only hinted, yet Kas was the',
    'most renowned swordsman of',
    'his age; a +6 defender, double',
    'damage against creatures from',
    'planes other than the Prime',
    'Material, but only normal',
    'damage when on any plane other',
    'than it; a short sword, highly',
    'evil and chaotic; 15',
    'intelligence, 19 ego, and it',
    'will attempt to control',
    'whoever takes it; powers 5 of',
    'I, 2 of II, 1 of III, 2 of IV,',
    '2 of V, 1 of VI (walker',
    '5,2,1,2,2,1, total 13) -',
    'printed in order I through VI,',
    'unlike the Rod complete list.',
    'The quirks: the Vecna quote',
    'prints inside curly double',
    'quotes, its three curly',
    'apostrophes dropped here',
    '(characters, Vecnas,',
    'lieutenants); the 2 feet mark',
    'prints curly; nine true',
    'multiplication signs; one',
    'plus sign; the Sceptre table',
    'prints its Evil cells empty,',
    'double blanks under Good and',
    'single blanks under Neutrality',
    '- 9 underscore runs of 15; the',
    'Kas slots print 13 runs of 11',
    'underscores; the bands 75-91',
    'at 150000 and 92 at 97000 -',
    'all pinned as plain digits and',
    'words, apostrophe-free and',
    'backslash-free here. 45',
    'accessors: 43 scalars + 2',
    'walkers, no name collisions',
    'with the miscprose and',
    'specart headers; the audit',
    'cross-pins the R240 sale rows',
    '24 and 25 - the Sceptre band',
    '75-91 at 150000, a range row,',
    'its price fixed; the Kas band',
    '92 at 97000, a fixed',
    'single-die row; zero high',
    'bounds carried by saSaleGpHi',
    '(census 211). Next: R294',
    'III.E Special part 15 - the',
    'Teeth of Dahlver-Nar solo in',
    'part2 from line 1744 (global',
    '12809; the Throne of the Gods',
    'and the other descriptions',
    'follow; the III.E',
    'Special prose continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 45, 'accessor count is not 45'
assert len(set(defs)) == 45, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 43, 'scalar count is not 43'
walk = [d for d in defs if d not in scal]
assert len(walk) == 2, 'walker count is not 2'
assert set(walk) == {'sapSceptreTableUse',
    'sapKasTableUse',
    }, 'wrong walkers'
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
assert 'sapRodJointTable' in s0, 'specartprose2.h missing the R292 accessors'
assert 'sapNightingalePowerCount' in s0, 'specartprose2.h missing the R291 accessors'
assert 'sapOrbMightPowerCount' in s0, 'specartprose2.h missing the R290 accessors'
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
assert ATEXT.count('R293 special artifacts prose part 14 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 14', 'Sceptre', 'Sword of Kas',
             '1708-1743', 'No break absorbed', 'census 211',
             'R294', 'line 1744', '12809', 'saSaleGpHi'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 14', 'The Sceptre of Might',
             'Sword of Kas', '1708-1743', 'No break absorbed'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapSceptreCount() {'
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
assert len(alldefs) == 435, 'accessor count is not 435'
assert len(set(alldefs)) == 435, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R293: the III.E Special artifacts'
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
assert s.count('R293 special artifacts prose part 14 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R293 landed the III.E Special'
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

print('R293 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R293 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 14 - the Sceptre of Might and')
print('the Sword of Kas, part2 lines')
print('1708-1743;')
print('census 211.')
print('commit: R293: the III.E Special artifacts explanation prose part 14 pinned - the Sceptre of Might and the Sword of Kas in part2 lines 1708-1743 (census 211)')

