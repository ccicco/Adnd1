#!/usr/bin/env python3
# R289 splice: the III.E Special artifacts
# explanation prose part 10 pins -
# the Orb of Dragonkind intro and its
# 1st through 5th globes (the Hatchling,
# the Wyrmkin, the Dragonette, the
# Dragon and the Great Serpent), part2
# lines 1518-1556, the first half of the
# 19th of the 29 artifact descriptions.
# The intro: the good deities conspired
# to control evil dragons, demon
# servants changed the magic to include
# all dragonkind and made the Orbs
# inimical; 8 globes of carven white
# jade, 1 per dragon age, smallest 3
# inches, largest about 10, bas
# reliefs of entwined dragons, the
# essence of all dragons within. The
# globes charm very young through
# adult dragons respectively; the
# intelligence and ego ladder is 9/9,
# 10/10, 11/11, 12/12 and 13/13; an
# orb controls its possessor when the
# pair equals or exceeds combined
# intelligence and wisdom; powers
# 3,0,0,0,0,0 (3), 2,1,0,0,0,0 (3),
# 3,1,1,0,0,0 (5), 4,1,1,0,0,0 (6),
# 3,2,1,0,0,1 (7). One break absorbed:
# the extra blank pair at 1555-1556;
# no page seam claimed (no running
# heads between upload lines 1450 and
# 1797). 28 accessors: 23 scalars + 5
# walkers. The audit cross-pins the
# R240 sale row: the Dragonkind band
# 41-47 at 10000 to 80000 - the only
# range row, its high bound carried
# by saSaleGpHi.
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
    'inline int sapOrbGoodDeitiesOrigin() {',
    '    // the good deities conspired to devise it',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbDemonsCorrupted() {',
    '    // demon servants changed the magic',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbGlobeCount() {',
    '    // the globes of carven white jade',
    '    return 8;',
    '}',
    '',
    'inline int sapOrbOnePerAge() {',
    '    // 1 globe for each age of dragon life',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbSmallestInches() {',
    '    // the smallest globe, in inches',
    '    return 3;',
    '}',
    '',
    'inline int sapOrbLargestInches() {',
    '    // the largest globe, in inches',
    '    return 10;',
    '}',
    '',
    'inline int sapOrbBasReliefCovered() {',
    '    // bas reliefs of entwined dragons cover it',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbDragonEssence() {',
    '    // it holds the essence of all dragons',
    '    return 1;',
    '}',
    '',
    'inline int sapOrbHatchlingIntelligence() {',
    '    // the intelligence of the Hatchling',
    '    return 9;',
    '}',
    '',
    'inline int sapOrbHatchlingEgo() {',
    '    // the ego of the Hatchling',
    '    return 9;',
    '}',
    '',
    'inline int sapOrbHatchlingPowerTotal() {',
    '    // 3+0+0+0+0+0 - the total power count',
    '    return 3;',
    '}',
    '',
    'inline int sapOrbHatchlingPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapOrbWyrmkinIntelligence() {',
    '    // the intelligence of the Wyrmkin',
    '    return 10;',
    '}',
    '',
    'inline int sapOrbWyrmkinEgo() {',
    '    // the ego of the Wyrmkin',
    '    return 10;',
    '}',
    '',
    'inline int sapOrbWyrmkinPowerTotal() {',
    '    // 2+1+0+0+0+0 - the total power count',
    '    return 3;',
    '}',
    '',
    'inline int sapOrbWyrmkinPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        2, 1, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapOrbDragonetteIntelligence() {',
    '    // the intelligence of the Dragonette',
    '    return 11;',
    '}',
    '',
    'inline int sapOrbDragonetteEgo() {',
    '    // the ego of the Dragonette',
    '    return 11;',
    '}',
    '',
    'inline int sapOrbDragonettePowerTotal() {',
    '    // 3+1+1+0+0+0 - the total power count',
    '    return 5;',
    '}',
    '',
    'inline int sapOrbDragonettePowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 1, 1, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapOrbDragonIntelligence() {',
    '    // the intelligence of the Dragon',
    '    return 12;',
    '}',
    '',
    'inline int sapOrbDragonEgo() {',
    '    // the ego of the Dragon',
    '    return 12;',
    '}',
    '',
    'inline int sapOrbDragonPowerTotal() {',
    '    // 4+1+1+0+0+0 - the total power count',
    '    return 6;',
    '}',
    '',
    'inline int sapOrbDragonPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        4, 1, 1, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapOrbGreatSerpentIntelligence() {',
    '    // the intelligence of the Great Serpent',
    '    return 13;',
    '}',
    '',
    'inline int sapOrbGreatSerpentEgo() {',
    '    // the ego of the Great Serpent',
    '    return 13;',
    '}',
    '',
    'inline int sapOrbGreatSerpentPowerTotal() {',
    '    // 3+2+1+0+0+1 - the total power count',
    '    return 7;',
    '}',
    '',
    'inline int sapOrbGreatSerpentPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 2, 1, 0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R289: the III.E Special artifacts',
    '    // explanation prose part 10 ----',
    '    // The Orb of Dragonkind, part2 lines',
    '    // 1518-1556 - the intro and the 1st',
    '    // through the 5th of its 8 globes, the',
    '    // first half of the 19th of the 29',
    '    // descriptions. One break absorbed: the',
    '    // extra blank pair at 1555-1556.',
    '    {',
    '        int bad = 0;',
    '        // the Orb intro scalars',
    '        if (rules::sapOrbGoodDeitiesOrigin() != 1 ||',
    '            rules::sapOrbDemonsCorrupted() != 1 ||',
    '            rules::sapOrbGlobeCount() != 8 ||',
    '            rules::sapOrbOnePerAge() != 1 ||',
    '            rules::sapOrbSmallestInches() != 3 ||',
    '            rules::sapOrbLargestInches() != 10 ||',
    '            rules::sapOrbBasReliefCovered() != 1 ||',
    '            rules::sapOrbDragonEssence() != 1) ++bad;',
    '        // the Hatchling scalars and powers',
    '        if (rules::sapOrbHatchlingIntelligence() != 9 ||',
    '            rules::sapOrbHatchlingEgo() != 9 ||',
    '            rules::sapOrbHatchlingPowerTotal() != 3) ++bad;',
    '        static const int kO1[6] = {',
    '            3, 0, 0, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrbHatchlingPowerCount(i) != kO1[i]) ++bad;',
    '        if (rules::sapOrbHatchlingPowerCount(0) +',
    '            rules::sapOrbHatchlingPowerCount(1) +',
    '            rules::sapOrbHatchlingPowerCount(2) +',
    '            rules::sapOrbHatchlingPowerCount(3) +',
    '            rules::sapOrbHatchlingPowerCount(4) +',
    '            rules::sapOrbHatchlingPowerCount(5) !=',
    '            rules::sapOrbHatchlingPowerTotal()) ++bad;',
    '        // the Wyrmkin scalars and powers',
    '        if (rules::sapOrbWyrmkinIntelligence() != 10 ||',
    '            rules::sapOrbWyrmkinEgo() != 10 ||',
    '            rules::sapOrbWyrmkinPowerTotal() != 3) ++bad;',
    '        static const int kO2[6] = {',
    '            2, 1, 0, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrbWyrmkinPowerCount(i) != kO2[i]) ++bad;',
    '        if (rules::sapOrbWyrmkinPowerCount(0) +',
    '            rules::sapOrbWyrmkinPowerCount(1) +',
    '            rules::sapOrbWyrmkinPowerCount(2) +',
    '            rules::sapOrbWyrmkinPowerCount(3) +',
    '            rules::sapOrbWyrmkinPowerCount(4) +',
    '            rules::sapOrbWyrmkinPowerCount(5) !=',
    '            rules::sapOrbWyrmkinPowerTotal()) ++bad;',
    '        // the Dragonette scalars and powers',
    '        if (rules::sapOrbDragonetteIntelligence() != 11 ||',
    '            rules::sapOrbDragonetteEgo() != 11 ||',
    '            rules::sapOrbDragonettePowerTotal() != 5) ++bad;',
    '        static const int kO3[6] = {',
    '            3, 1, 1, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrbDragonettePowerCount(i) != kO3[i]) ++bad;',
    '        if (rules::sapOrbDragonettePowerCount(0) +',
    '            rules::sapOrbDragonettePowerCount(1) +',
    '            rules::sapOrbDragonettePowerCount(2) +',
    '            rules::sapOrbDragonettePowerCount(3) +',
    '            rules::sapOrbDragonettePowerCount(4) +',
    '            rules::sapOrbDragonettePowerCount(5) !=',
    '            rules::sapOrbDragonettePowerTotal()) ++bad;',
    '        // the Dragon scalars and powers',
    '        if (rules::sapOrbDragonIntelligence() != 12 ||',
    '            rules::sapOrbDragonEgo() != 12 ||',
    '            rules::sapOrbDragonPowerTotal() != 6) ++bad;',
    '        static const int kO4[6] = {',
    '            4, 1, 1, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrbDragonPowerCount(i) != kO4[i]) ++bad;',
    '        if (rules::sapOrbDragonPowerCount(0) +',
    '            rules::sapOrbDragonPowerCount(1) +',
    '            rules::sapOrbDragonPowerCount(2) +',
    '            rules::sapOrbDragonPowerCount(3) +',
    '            rules::sapOrbDragonPowerCount(4) +',
    '            rules::sapOrbDragonPowerCount(5) !=',
    '            rules::sapOrbDragonPowerTotal()) ++bad;',
    '        // the Great Serpent scalars and powers',
    '        if (rules::sapOrbGreatSerpentIntelligence() != 13 ||',
    '            rules::sapOrbGreatSerpentEgo() != 13 ||',
    '            rules::sapOrbGreatSerpentPowerTotal() != 7) ++bad;',
    '        static const int kO5[6] = {',
    '            3, 2, 1, 0, 0, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapOrbGreatSerpentPowerCount(i) != kO5[i]) ++bad;',
    '        if (rules::sapOrbGreatSerpentPowerCount(0) +',
    '            rules::sapOrbGreatSerpentPowerCount(1) +',
    '            rules::sapOrbGreatSerpentPowerCount(2) +',
    '            rules::sapOrbGreatSerpentPowerCount(3) +',
    '            rules::sapOrbGreatSerpentPowerCount(4) +',
    '            rules::sapOrbGreatSerpentPowerCount(5) !=',
    '            rules::sapOrbGreatSerpentPowerTotal()) ++bad;',
    '        // the intelligence ladder rises by one',
    '        if (rules::sapOrbWyrmkinIntelligence() !=',
    '            rules::sapOrbHatchlingIntelligence() + 1) ++bad;',
    '        if (rules::sapOrbDragonetteIntelligence() !=',
    '            rules::sapOrbWyrmkinIntelligence() + 1) ++bad;',
    '        if (rules::sapOrbDragonIntelligence() !=',
    '            rules::sapOrbDragonetteIntelligence() + 1) ++bad;',
    '        if (rules::sapOrbGreatSerpentIntelligence() !=',
    '            rules::sapOrbDragonIntelligence() + 1) ++bad;',
    '        // the Hatchling and Wyrmkin totals agree',
    '        if (rules::sapOrbHatchlingPowerTotal() !=',
    '            rules::sapOrbWyrmkinPowerTotal()) ++bad;',
    '        // the cross-pin: the R240 sale table row',
    '        // (the only range row in the table)',
    '        if (rules::saRowLo(18) != 41 ||',
    '            rules::saRowHi(18) != 47 ||',
    '            rules::saSaleGp(18) != 10000 ||',
    '            rules::saSaleGpHi(18) != 80000) ++bad;',
    '        printf("R289 special artifacts prose part 10 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R289 landed the III.E Special',
    'artifacts explanation prose',
    'part 10 (part2 lines 1518-1556;',
    'global = 11065 + part2 line),',
    'the Orb of Dragonkind intro',
    'and its 1st through 5th globes,',
    'the first half of the 19th of',
    'the 29 artifact descriptions.',
    'The intro: certain good',
    'deities conspired to control',
    'the evil dragons plaguing',
    'mankind, demon servants of',
    'evil changed the magic to',
    'include all dragonkind and',
    'gave the Orbs inimical',
    'properties; 8 globes of',
    'carven white jade, 1 for',
    'each age of dragon life;',
    'the smallest but 3 inches',
    'across, the largest about',
    '10; each covered with bas',
    'reliefs of entwined dragons',
    'of incredible hardness,',
    'imprisoning the very',
    'essence of all dragons.',
    'Globe 1, the Hatchling:',
    'charms any very young',
    'dragon, intelligence 9, ego',
    '9, it controls the possessor',
    'when the pair equals or',
    'exceeds combined',
    'intelligence and wisdom;',
    'powers 3,0,0,0,0,0 total 3.',
    'Globe 2, the Wyrmkin: young',
    'dragons, 10 and 10; powers',
    '2,1,0,0,0,0 total 3. Globe',
    '3, the Dragonette: sub-adult',
    'dragons, 11 and 11; powers',
    '3,1,1,0,0,0 total 5. Globe',
    '4, the Dragon: young adult',
    'dragons, 12 and 12; powers',
    '4,1,1,0,0,0 total 6. Globe',
    '5, the Great Serpent: adult',
    'dragons, 13 and 13; powers',
    '3,2,1,0,0,1 total 7. The',
    'intelligence ladder rises',
    'by one, 9 through 13.',
    'One break absorbed: the',
    'extra blank pair at 1555-1556',
    'between globes 5 and 6.',
    'No page seam claimed -',
    'the upload prints no',
    'running heads between',
    'lines 1450 and 1797.',
    'The upload quirks: the',
    'part1 sale row names it',
    'Orb of the Dragonkind,',
    'with a the before',
    'Dragonkind, while part2',
    'drops the the - a',
    'the-quirk; the apostrophe',
    'in dragons prints as the',
    'curly right single quote;',
    'the power lines print N x',
    'table with the true',
    'multiplication sign, 13',
    'of them - all pinned as',
    'plain digits and words,',
    'apostrophe-free here. 28',
    'accessors: 23 scalars + 5',
    'walkers (the hatchling',
    'walker 3,0,0,0,0,0, the',
    'wyrmkin walker 2,1,0,0,0,0,',
    'the dragonette walker',
    '3,1,1,0,0,0, the dragon',
    'walker 4,1,1,0,0,0, the',
    'great serpent walker',
    '3,2,1,0,0,1), no name',
    'collisions with the',
    'miscprose and specart',
    'headers; the audit',
    'cross-pins the R240 sale',
    'row - the Dragonkind band',
    '41-47 at 10000 to 80000,',
    'the only range row, its',
    'high bound carried by',
    'saSaleGpHi (census 207).',
    'Next: R290 III.E Special',
    'part 11 - the Orb of',
    'Dragonkind continues with',
    'its 6th through 8th globes',
    'and the notes, in part2',
    'from line 1557 (global',
    '12622; the Firedrake, the',
    'Elder Wyrm, the Eternal',
    'Grand Dragon and the notes',
    'follow; the III.E Special',
    'prose continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 28, 'accessor count is not 28'
assert len(set(defs)) == 28, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 23, 'scalar count is not 23'
walk = [d for d in defs if d not in scal]
assert len(walk) == 5, 'walker count is not 5'
assert set(walk) == {'sapOrbHatchlingPowerCount',
    'sapOrbWyrmkinPowerCount', 'sapOrbDragonettePowerCount',
    'sapOrbDragonPowerCount', 'sapOrbGreatSerpentPowerCount',
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
assert 'sapServantLumSameMake' in s0, 'specartprose2.h missing the R288 accessors'
assert 'sapQuillMasterThiefBest' in s0, 'specartprose2.h missing the R287 accessors'
assert 'sapFlaskHeavyUrn' in s0, 'specartprose2.h missing the R286 accessors'
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
assert ATEXT.count('R289 special artifacts prose part 10 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 10', 'the Orb of Dragonkind', '1518-1556',
             'One break absorbed', 'blank pair at 1555-1556',
             'census 207', 'R290', 'line 1557', '12622',
             'saSaleGpHi'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 10', 'The Orb of Dragonkind', '1518-1556',
             'One break absorbed'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapOrbGoodDeitiesOrigin() {'
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
assert len(alldefs) == 266, 'accessor count is not 266'
assert len(set(alldefs)) == 266, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R289: the III.E Special artifacts'
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
assert s.count('R289 special artifacts prose part 10 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R289 landed the III.E Special'
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

print('R289 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R289 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 10 - the Orb of Dragonkind intro')
print('and globes 1-5, part2 lines 1518-1556;')
print('census 207.')
print('commit: R289: the III.E Special artifacts explanation prose part 10 pinned - the Orb of Dragonkind intro and globes 1-5 in part2 lines 1518-1556 (census 207)')

