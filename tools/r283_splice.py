#!/usr/bin/env python3
# R283 splice: the III.E Special artifacts
# explanation prose part 4 pins - the Crystal
# of the Ebon Flame and the Cup and Talisman
# of Al Akbar, part2 lines 1270-1316 (DMG
# p.160), the fifth and sixth of the 29
# artifact descriptions. The Crystal: origin
# and whereabouts entirely unknown, a
# diamond-hard mineral the size of a hand,
# touched it sends rays of light with a
# black flame leaping in the jewel heart,
# all creatures within 30 feet save versus
# magic or charmed as if by a fire charm
# spell, the possessor draws powers by
# gazing at the Ebon Flame at its center;
# powers 4 of table I, 2 of II, 1 each of
# III-VI. The Cup and Talisman: a pair of
# holy relics given by the gods of the
# Paynims to their most exalted high priest
# of lawful good alignment in the days
# following the Invoked Devastation (the
# same era the Axe was lost in), lost to
# demi-human raiders, last rumored in the
# Southeastern Bandit Kingdoms; the Cup of
# hammered gold and silver filigree set
# with 12 great gems in electrum settings,
# a jewelry value of 75,000 or more gold
# pieces, not radiating magic, powers 4 of
# table I and 1 of III; the Talisman of
# hammered platinum, a star of 8 points
# with a small gem tipping each point hung
# from a gold and electrum chain of 8
# sets of 3 silver beads, a jewelry value
# of 10,000 or more gold pieces, not
# radiating magic either, powers 2 of
# table II and 1 of IV; a cleric, druid,
# paladin or ranger possessing both may
# fill the cup with holy water, immerse
# the talisman and create a potion once
# per week - the d20 potion table 1-5
# healing, 6-10 extra healing, 11-15
# poison antidote balm, 16-17 cure
# disease salve, 18-19 remove curse
# ointment, 20 raise dead balm - and the
# possessor gains 1 each of tables V and
# VI from both. No seam this round either:
# both descriptions lie wholly on p.160 -
# the p.160-161 break splits the Hand of
# Vecna paragraph (a later round). The
# upload quirks this round: the power
# lines print the counts as N x table with
# the true multiplication sign, 12 of
# them; the 30 feet prime prints as the
# curly right single quote, as does the Al
# Akbar apostrophe; the jewelry value
# dashes print as true em-dashes; the cup
# 1 of III and the talisman 1 of IV power
# lines carry asterisk footnote markers;
# the potion table prints the 1-5 band
# split from its healing word - all
# pinned as plain digits and words,
# apostrophe-free here. 32 accessors:
# 26 scalars + 6 walkers (the crystal
# power walker, the cup, talisman and
# both power walkers and the potion band
# lo/hi walkers), no name collisions with
# the miscprose and specart headers. The
# audit cross-pins the R240 sale table
# rows: the Crystal band 21 at 75000, the
# Cup and Talisman band 22 at 85000 (the
# cup jewelry value 75000 is NOT its
# sale value).
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
    'inline int sapCrystalOriginUnknown() {',
    '    // the origin and whereabouts entirely unknown',
    '    return 1;',
    '}',
    '',
    'inline int sapCrystalDiamondHard() {',
    '    // a diamond-hard mineral the size of a hand',
    '    return 1;',
    '}',
    '',
    'inline int sapCrystalTouchRaysBlackFlame() {',
    '    // touched it sends rays, a black flame leaps',
    '    return 1;',
    '}',
    '',
    'inline int sapCrystalCharmRadiusFeet() {',
    '    // all creatures within 30 feet save versus magic',
    '    return 30;',
    '}',
    '',
    'inline int sapCrystalCharmIsFireCharm() {',
    '    // or charmed as if by a fire charm spell',
    '    return 1;',
    '}',
    '',
    'inline int sapCrystalPowersByGazing() {',
    '    // powers drawn by gazing at the Ebon Flame',
    '    return 1;',
    '}',
    '',
    'inline int sapCrystalPowerTotal() {',
    '    // 4 of table I, 2 of II, 1 each of III-VI',
    '    return 10;',
    '}',
    '',
    'inline int sapCrystalPowerCount(int i) {',
    '    // the powers per table I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        4, 2, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCupTalismanRelicCount() {',
    '    // a pair of holy relics',
    '    return 2;',
    '}',
    '',
    'inline int sapCupTalismanPaynimGift() {',
    '    // given by the gods of the Paynims to the',
    '    // most exalted high priest of lawful good',
    '    return 1;',
    '}',
    '',
    'inline int sapCupTalismanInvokedDevastationEra() {',
    '    // in the days following the Invoked Devastation',
    '    return 1;',
    '}',
    '',
    'inline int sapCupTalismanLostToRaiders() {',
    '    // lost to demi-human raiders, rumored Southeastern',
    '    return 1;',
    '}',
    '',
    'inline int sapCupTalismanPotionClassCount() {',
    '    // a cleric, druid, paladin or ranger possessing both',
    '    return 4;',
    '}',
    '',
    'inline int sapCupTalismanPotionPerWeek() {',
    '    // may create a potion once per week',
    '    return 1;',
    '}',
    '',
    'inline int sapCupGemCount() {',
    '    // set with 12 great gems in electrum settings',
    '    return 12;',
    '}',
    '',
    'inline int sapCupJewelryGpMin() {',
    '    // a jewelry value of 75,000 or more gold pieces',
    '    return 75000;',
    '}',
    '',
    'inline int sapCupRadiatesMagic() {',
    '    // the Cup does not radiate magic',
    '    return 0;',
    '}',
    '',
    'inline int sapCupPowerTotal() {',
    '    // 4 of table I plus 1 of table III',
    '    return 5;',
    '}',
    '',
    'inline int sapCupPowerCount(int i) {',
    '    // the cup powers per tables I-III; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    static const int t[3] = {',
    '        4, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapTalismanPointCount() {',
    '    // a star of 8 points',
    '    return 8;',
    '}',
    '',
    'inline int sapTalismanPointGemCount() {',
    '    // a small gem tipping each point',
    '    return 8;',
    '}',
    '',
    'inline int sapTalismanBeadSetCount() {',
    '    // 8 sets of 3 beads each on the chain',
    '    return 8;',
    '}',
    '',
    'inline int sapTalismanBeadsPerSet() {',
    '    // silver beading, 8 sets of 3 beads each',
    '    return 3;',
    '}',
    '',
    'inline int sapTalismanJewelryGpMin() {',
    '    // a jewelry value of 10,000 or more gold pieces',
    '    return 10000;',
    '}',
    '',
    'inline int sapTalismanRadiatesMagic() {',
    '    // the Talisman does not radiate magic either',
    '    return 0;',
    '}',
    '',
    'inline int sapTalismanPowerTotal() {',
    '    // 2 of table II plus 1 of table IV',
    '    return 3;',
    '}',
    '',
    'inline int sapTalismanPowerCount(int i) {',
    '    // the talisman powers per tables I-IV; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 3) i = 3;',
    '    static const int t[4] = {',
    '        0, 2, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCupTalismanBothPowerTotal() {',
    '    // 1 each of tables V and VI from both',
    '    return 2;',
    '}',
    '',
    'inline int sapCupTalismanBothPowerCount(int i) {',
    '    // the both powers per tables V-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 1) i = 1;',
    '    static const int t[2] = {',
    '        1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCupTalismanPotionBandCount() {',
    '    // the six bands of the potion table',
    '    return 6;',
    '}',
    '',
    'inline int sapCupTalismanPotionBandLo(int i) {',
    '    // the potion band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        1, 6, 11, 16, 18, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCupTalismanPotionBandHi(int i) {',
    '    // the potion band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        5, 10, 15, 17, 19, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R283: the III.E Special artifacts',
    '    // explanation prose part 4 ----',
    '    // The Crystal of the Ebon Flame and the Cup',
    '    // and Talisman of Al Akbar, part2 lines',
    '    // 1270-1316 (DMG p.160) - the fifth and',
    '    // sixth of the 29 artifact descriptions.',
    '    // No seam this round either: both lie',
    '    // wholly on p.160.',
    '    {',
    '        int bad = 0;',
    '        // the Crystal scalars',
    '        if (rules::sapCrystalOriginUnknown() != 1 ||',
    '            rules::sapCrystalDiamondHard() != 1 ||',
    '            rules::sapCrystalTouchRaysBlackFlame() != 1 ||',
    '            rules::sapCrystalCharmRadiusFeet() != 30 ||',
    '            rules::sapCrystalCharmIsFireCharm() != 1 ||',
    '            rules::sapCrystalPowersByGazing() != 1 ||',
    '            rules::sapCrystalPowerTotal() != 10) ++bad;',
    '        // the Cup and Talisman scalars',
    '        if (rules::sapCupTalismanRelicCount() != 2 ||',
    '            rules::sapCupTalismanPaynimGift() != 1 ||',
    '            rules::sapCupTalismanInvokedDevastationEra() != 1 ||',
    '            rules::sapCupTalismanLostToRaiders() != 1 ||',
    '            rules::sapCupTalismanPotionClassCount() != 4 ||',
    '            rules::sapCupTalismanPotionPerWeek() != 1 ||',
    '            rules::sapCupGemCount() != 12 ||',
    '            rules::sapCupJewelryGpMin() != 75000 ||',
    '            rules::sapCupRadiatesMagic() != 0 ||',
    '            rules::sapCupPowerTotal() != 5 ||',
    '            rules::sapTalismanPointCount() != 8 ||',
    '            rules::sapTalismanPointGemCount() != 8 ||',
    '            rules::sapTalismanBeadSetCount() != 8 ||',
    '            rules::sapTalismanBeadsPerSet() != 3 ||',
    '            rules::sapTalismanJewelryGpMin() != 10000 ||',
    '            rules::sapTalismanRadiatesMagic() != 0 ||',
    '            rules::sapTalismanPowerTotal() != 3 ||',
    '            rules::sapCupTalismanBothPowerTotal() != 2 ||',
    '            rules::sapCupTalismanPotionBandCount() != 6) ++bad;',
    '        // the crystal powers per table I-VI',
    '        static const int kCry[6] = {',
    '            4, 2, 1, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapCrystalPowerCount(i) != kCry[i]) ++bad;',
    '        if (rules::sapCrystalPowerCount(0) +',
    '            rules::sapCrystalPowerCount(1) +',
    '            rules::sapCrystalPowerCount(2) +',
    '            rules::sapCrystalPowerCount(3) +',
    '            rules::sapCrystalPowerCount(4) +',
    '            rules::sapCrystalPowerCount(5) !=',
    '            rules::sapCrystalPowerTotal()) ++bad;',
    '        // the cup powers per tables I-III',
    '        static const int kCup[3] = {',
    '            4, 0, 1,',
    '        };',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::sapCupPowerCount(i) != kCup[i]) ++bad;',
    '        if (rules::sapCupPowerCount(1) != 0) ++bad;',
    '        if (rules::sapCupPowerCount(0) +',
    '            rules::sapCupPowerCount(1) +',
    '            rules::sapCupPowerCount(2) !=',
    '            rules::sapCupPowerTotal()) ++bad;',
    '        // the talisman powers per tables I-IV',
    '        static const int kTal[4] = {',
    '            0, 2, 0, 1,',
    '        };',
    '        for (int i = 0; i < 4; ++i)',
    '            if (rules::sapTalismanPowerCount(i) != kTal[i]) ++bad;',
    '        if (rules::sapTalismanPowerCount(0) != 0 ||',
    '            rules::sapTalismanPowerCount(2) != 0) ++bad;',
    '        if (rules::sapTalismanPowerCount(0) +',
    '            rules::sapTalismanPowerCount(1) +',
    '            rules::sapTalismanPowerCount(2) +',
    '            rules::sapTalismanPowerCount(3) !=',
    '            rules::sapTalismanPowerTotal()) ++bad;',
    '        // the both powers per tables V-VI',
    '        static const int kBot[2] = {',
    '            1, 1,',
    '        };',
    '        for (int i = 0; i < 2; ++i)',
    '            if (rules::sapCupTalismanBothPowerCount(i) != kBot[i]) ++bad;',
    '        if (rules::sapCupTalismanBothPowerCount(0) +',
    '            rules::sapCupTalismanBothPowerCount(1) !=',
    '            rules::sapCupTalismanBothPowerTotal()) ++bad;',
    '        // the potion table bands, contiguous over the d20',
    '        static const int kPlo[6] = {',
    '            1, 6, 11, 16, 18, 20,',
    '        };',
    '        static const int kPhi[6] = {',
    '            5, 10, 15, 17, 19, 20,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapCupTalismanPotionBandLo(i) != kPlo[i]) ++bad;',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapCupTalismanPotionBandHi(i) != kPhi[i]) ++bad;',
    '        if (rules::sapCupTalismanPotionBandLo(0) != 1) ++bad;',
    '        if (rules::sapCupTalismanPotionBandHi(5) != 20) ++bad;',
    '        if (rules::sapCupTalismanPotionBandHi(0) + 1 !=',
    '            rules::sapCupTalismanPotionBandLo(1)) ++bad;',
    '        if (rules::sapCupTalismanPotionBandHi(1) + 1 !=',
    '            rules::sapCupTalismanPotionBandLo(2)) ++bad;',
    '        if (rules::sapCupTalismanPotionBandHi(2) + 1 !=',
    '            rules::sapCupTalismanPotionBandLo(3)) ++bad;',
    '        if (rules::sapCupTalismanPotionBandHi(3) + 1 !=',
    '            rules::sapCupTalismanPotionBandLo(4)) ++bad;',
    '        if (rules::sapCupTalismanPotionBandHi(4) + 1 !=',
    '            rules::sapCupTalismanPotionBandLo(5)) ++bad;',
    '        // the talisman beads: 8 sets of 3 beads each',
    '        if (rules::sapTalismanBeadSetCount() *',
    '            rules::sapTalismanBeadsPerSet() != 24) ++bad;',
    '        // a gem tips each of the 8 star points',
    '        if (rules::sapTalismanPointGemCount() !=',
    '            rules::sapTalismanPointCount()) ++bad;',
    '        // the same era the Axe was lost in',
    '        if (rules::sapAxeInvokedDevastationLost() !=',
    '            rules::sapCupTalismanInvokedDevastationEra()) ++bad;',
    '        // the cup jewelry value is NOT its sale value',
    '        if (rules::sapCupJewelryGpMin() ==',
    '            rules::saSaleGp(5)) ++bad;',
    '        // the cross-pins: the R240 sale table rows',
    '        if (rules::saRowLo(4) != 21 ||',
    '            rules::saRowHi(4) != 21 ||',
    '            rules::saSaleGp(4) != 75000 ||',
    '            rules::saRowLo(5) != 22 ||',
    '            rules::saRowHi(5) != 22 ||',
    '            rules::saSaleGp(5) != 85000) ++bad;',
    '        printf("R283 special artifacts prose part 4 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R283 landed the III.E Special',
    'artifacts explanation prose',
    'part 4 (part2 lines 1270-1316;',
    'global = 11065 + part2 line),',
    'the Crystal',
    'of the Ebon Flame and the Cup and',
    'Talisman of Al Akbar (DMG p.160)',
    '- the fifth and sixth of the 29',
    'artifact descriptions. The',
    'Crystal: origin and whereabouts',
    'entirely unknown, a diamond-hard',
    'mineral the size of a hand,',
    'touched it sends rays of light',
    'with a black flame leaping in',
    'the jewel heart, all creatures',
    'within 30 feet save versus magic',
    'or charmed as if by a fire charm',
    'spell, the possessor draws',
    'powers by gazing at the Ebon',
    'Flame at its center; powers 4',
    'of table I, 2 of II, 1 each of',
    'III-VI. The Cup and Talisman: a',
    'pair of holy relics given by the',
    'gods of the Paynims to their most',
    'exalted high priest of lawful',
    'good alignment in the days',
    'following the Invoked',
    'Devastation (the same era the',
    'Axe was lost in), lost to',
    'demi-human raiders, last rumored',
    'in the Southeastern Bandit',
    'Kingdoms; the Cup of hammered',
    'gold and silver filigree set',
    'with 12 great gems in electrum',
    'settings, a jewelry value of',
    '75,000 or more gold pieces, not',
    'radiating magic, powers 4 of',
    'table I and 1 of III; the',
    'Talisman of hammered platinum,',
    'a star of 8 points with a small',
    'gem tipping each point hung',
    'from a gold and electrum chain',
    'of 8 sets of 3 silver beads, a',
    'jewelry value of 10,000 or more',
    'gold pieces, not radiating',
    'magic either, powers 2 of table',
    'II and 1 of IV; a cleric,',
    'druid, paladin or ranger',
    'possessing both may fill the',
    'cup with holy water, immerse',
    'the talisman and create a',
    'potion once per week - the d20',
    'potion table 1-5 healing, 6-10',
    'extra healing, 11-15 poison',
    'antidote balm, 16-17 cure',
    'disease salve, 18-19 remove',
    'curse ointment, 20 raise dead',
    'balm - and the possessor gains',
    '1 each of tables V and VI from',
    'both. No seam this round',
    'either: both descriptions lie',
    'wholly on p.160 - the p.160-161',
    'break splits the Hand of Vecna',
    'paragraph (a later round). The',
    'upload quirks: the power lines',
    'print the counts as N x table',
    'with the true multiplication',
    'sign, 12 of them; the 30 feet',
    'prime prints as the curly right',
    'single quote, as does the Al',
    'Akbar apostrophe; the jewelry',
    'value dashes print as true',
    'em-dashes; the cup 1 of III and',
    'the talisman 1 of IV power',
    'lines carry asterisk footnote',
    'markers; the potion table',
    'prints the 1-5 band split from',
    'its healing word - all pinned as',
    'plain digits and words,',
    'apostrophe-free here. 32',
    'accessors: 26 scalars + 6',
    'walkers (the crystal power',
    'walker, the cup, talisman and',
    'both power walkers and the',
    'potion band lo/hi walkers), no',
    'name collisions with the',
    'miscprose and specart headers;',
    'the audit cross-pins the R240',
    'sale table rows - the Crystal',
    'band 21 at 75000, the Cup and',
    'Talisman band 22 at 85000,',
    'the cup jewelry value 75000',
    'NOT its sale value (census 201).',
    'Next: R284 III.E Special part',
    '5 - the Eye of Vecna onward in',
    'part2 from line 1318 (global',
    '12383; the Hand of Vecna with',
    'the p.160-161 seam and the',
    'other descriptions follow;',
    'the III.E Special prose',
    'continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 32, 'accessor count is not 32'
assert len(set(defs)) == 32, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 26, 'scalar count is not 26'
walk = [d for d in defs if d not in scal]
assert len(walk) == 6, 'walker count is not 6'
assert set(walk) == {'sapCrystalPowerCount', 'sapCupPowerCount',
                    'sapTalismanPowerCount', 'sapCupTalismanBothPowerCount',
                    'sapCupTalismanPotionBandLo',
                    'sapCupTalismanPotionBandHi', }, 'wrong walkers'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(sap[A-Za-z0-9]+)[(]', ATEXT))
assert set(defs) <= audited, 'audit does not probe every accessor'
assert audited - set(defs) == {'sapAxeInvokedDevastationLost', }, 'unexpected extra probes'
for fn in sorted(os.listdir(os.path.join(ROOT, 'rules'))):
    if not fn.endswith('.h') or fn == 'specartprose2.h':
        continue
    pt = open(os.path.join(ROOT, 'rules', fn), encoding='utf-8').read()
    for n in defs:
        assert n not in pt, 'name collision with ' + fn
s0 = rd('rules/specartprose2.h')
assert 'sapCrownRegaliaSetCount' in s0, 'specartprose2.h missing the R282 accessors'
assert 'sapCodexPowerCount' in s0, 'specartprose2.h missing the R281 accessors'
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
assert ATEXT.count('R283 special artifacts prose part 4 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 4', 'the Crystal', 'Talisman of Al Akbar',
             '1270-1316', 'census 201', 'R284', 'line 1318', '12383',
             'DMG p.160', 'No seam'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 4', 'Crystal of the Ebon', 'and Talisman of Al Akbar',
             '1270-1316', 'No seam'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapCrystalOriginUnknown() {'
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
assert len(alldefs) == 90, 'accessor count is not 90'
assert len(set(alldefs)) == 90, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R283: the III.E Special artifacts'
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
assert s.count('R283 special artifacts prose part 4 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R283 landed the III.E Special'
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

print('R283 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R283 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 4 - the Crystal of the Ebon Flame')
print('and the Cup and Talisman of Al Akbar,')
print('part2 lines 1270-1316; census 201.')
print('commit: R283: the III.E Special artifacts explanation prose part 4 pinned - the Crystal of the Ebon Flame and the Cup and Talisman of Al Akbar in part2 lines 1270-1316 (census 201)')


