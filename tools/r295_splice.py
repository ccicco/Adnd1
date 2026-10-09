#!/usr/bin/env python3
# R295 splice: the III.E Special
# artifacts explanation prose part
# 16 pins - the Throne of the
# Gods and the Wand of Orcus, the
# 28th and 29th of the 29 artifact
# descriptions, part2 lines
# 1782-1814 - the last of the
# plan, the set now COMPLETE.
# The Throne: carven from the
# heart of a majestic mountain, a
# massive stone chair inlaid with
# mosaics of ivory and precious
# metals, set about with gems,
# where certain gods actually sat
# when they walked the world;
# within a great cavern of the
# mountain core, immobile and
# immovable; anyone daring to
# seat is subject to the effects;
# certain, per fables, to gain a
# magic item, with a malevolent
# effect too; the item gain
# cannot repeat, but the Throne
# can still affect the seated one
# if the proper words and gestures
# are known and followed - the
# seated one grasps either arm,
# both, or none (3 options) and
# utters a command; powers 3 of
# I, 3 of II, 2 of III, 2 of IV,
# 2 of V, 2 of VI (walker
# 3,3,2,2,2,2, total 14). The
# Wand of Orcus: the ghastly
# weapon, property of the demon
# prince Orcus, at times allowed
# to pass into the Prime Material
# Plane to wreak chaos and evil
# on all living things there; see
# MONSTER MANUAL, Demon, Orcus;
# the wielder lacks the full
# death-dealing power - the
# victim saves versus magic to
# avoid death or annihilation;
# six ranks unaffected at all:
# gods, godlings, demon lords,
# greater devils, saints,
# demi-gods; powers 4 of I, 2 of
# II, 2 of III, 1 of IV, 1 of VI,
# no table V (walker 4,2,2,1,0,1,
# total 10). The quirks: 11 true
# x-signs, 24 blank runs of
# exactly 14 underscores; the
# Throne carries no bullets but
# the Wand prints all 5 table
# lines with leading - bullets;
# the Wand 4 x I line joins runs
# 3 and 4 with a space, not a
# comma - 4 runs, 2 commas; 2
# curly apostrophes (the mountain
# core, the Throne magic), zero
# ASCII apostrophes, zero em
# dashes, all dropped here; the
# page seam absorbed at 1797 (a
# running head inside the round);
# the round closes on the
# standard blank at 1814, the
# head at 1815 sits outside it.
# The audit cross-pins the R240
# sale rows 27 and 28: the
# Throne band 99 priced --- (zero
# gold pieces), the Wand band 00
# - the d100 wraps, row value
# 100 - at 10,000. No break
# absorbed. 51 accessors: 49
# scalars + 2 walkers.
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
    'inline int sapThroneCarvenMountainHeart() {',
    '    // carven from the heart of a majestic mountain',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneMassiveStoneChair() {',
    '    // a massive stone chair',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneMosaicsIvoryMetals() {',
    '    // inlaid with mosaics of ivory and metals',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneSetAboutGems() {',
    '    // set about with gems',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneGodsActuallySat() {',
    '    // certain gods actually sat on it',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneWithinGreatCavern() {',
    '    // supposedly within a great cavern',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneImmobileImmovable() {',
    '    // part of the mountain core, immovable',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneAffectsAnyoneSeated() {',
    '    // anyone daring to seat is subject',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneCertainMagicItem() {',
    '    // certain, per fables, to gain a magic item',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneMalevolentEffectToo() {',
    '    // but subject to malevolent effect too',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneItemGainOnlyOnce() {',
    '    // the same character cannot again gain',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneProperWordsGestures() {',
    '    // the proper words and gestures, followed',
    '    return 1;',
    '}',
    '',
    'inline int sapThroneGraspOptions() {',
    '    // either arm, both, or none',
    '    return 3;',
    '}',
    '',
    'inline int sapThroneUseTotal() {',
    '    // 3+3+2+2+2+2 - the use total',
    '    return 14;',
    '}',
    '',
    'inline int sapThroneTableOneCount() {',
    '    // the uses of table I',
    '    return 3;',
    '}',
    '',
    'inline int sapThroneTableTwoCount() {',
    '    // the uses of table II',
    '    return 3;',
    '}',
    '',
    'inline int sapThroneTableThreeCount() {',
    '    // the uses of table III',
    '    return 2;',
    '}',
    '',
    'inline int sapThroneTableFourCount() {',
    '    // the uses of table IV',
    '    return 2;',
    '}',
    '',
    'inline int sapThroneTableFiveCount() {',
    '    // the uses of table V',
    '    return 2;',
    '}',
    '',
    'inline int sapThroneTableSixCount() {',
    '    // the uses of table VI',
    '    return 2;',
    '}',
    '',
    'inline int sapThroneBlankSlotCount() {',
    '    // the DM-fill blanks, one per use',
    '    return 14;',
    '}',
    '',
    'inline int sapThroneXSignCount() {',
    '    // the true multiplication signs, 6',
    '    return 6;',
    '}',
    '',
    'inline int sapThroneBulletLineCount() {',
    '    // the Throne lines carry no bullets',
    '    return 0;',
    '}',
    '',
    'inline int sapThroneTableUse(int i) {',
    '    // the uses per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 3, 2, 2, 2, 2,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapWandDemonPrinceProperty() {',
    '    // the ghastly weapon of the demon prince',
    '    return 1;',
    '}',
    '',
    'inline int sapWandPassesToPrimeMaterial() {',
    '    // at times allowed to pass to the Prime',
    '    return 1;',
    '}',
    '',
    'inline int sapWandWreakChaosEvil() {',
    '    // to wreak chaos and evil on the living',
    '    return 1;',
    '}',
    '',
    'inline int sapWandMonsterManualRef() {',
    '    // see MONSTER MANUAL, Demon, Orcus',
    '    return 1;',
    '}',
    '',
    'inline int sapWandSavingThrowVersusMagic() {',
    '    // the victim saves versus magic',
    '    return 1;',
    '}',
    '',
    'inline int sapWandAvoidsDeathAnnihilation() {',
    '    // to avoid death or annihilation',
    '    return 1;',
    '}',
    '',
    'inline int sapWandImmuneCount() {',
    '    // gods, godlings, demon lords, greater',
    '    // devils, saints, demi-gods - 6 ranks',
    '    return 6;',
    '}',
    '',
    'inline int sapWandUseTotal() {',
    '    // 4+2+2+1+0+1 - the use total',
    '    return 10;',
    '}',
    '',
    'inline int sapWandTableOneCount() {',
    '    // the uses of table I',
    '    return 4;',
    '}',
    '',
    'inline int sapWandTableTwoCount() {',
    '    // the uses of table II',
    '    return 2;',
    '}',
    '',
    'inline int sapWandTableThreeCount() {',
    '    // the uses of table III',
    '    return 2;',
    '}',
    '',
    'inline int sapWandTableFourCount() {',
    '    // the uses of table IV',
    '    return 1;',
    '}',
    '',
    'inline int sapWandTableFiveCount() {',
    '    // the Wand prints no table V line',
    '    return 0;',
    '}',
    '',
    'inline int sapWandTableSixCount() {',
    '    // the uses of table VI',
    '    return 1;',
    '}',
    '',
    'inline int sapWandBlankSlotCount() {',
    '    // the DM-fill blanks, one per use',
    '    return 10;',
    '}',
    '',
    'inline int sapWandXSignCount() {',
    '    // the true multiplication signs, 5',
    '    return 5;',
    '}',
    '',
    'inline int sapWandBulletLineCount() {',
    '    // all 5 Wand table lines carry bullets',
    '    return 5;',
    '}',
    '',
    'inline int sapWandFourOneSpaceSeparator() {',
    '    // the 4 x I line joins runs 3 and 4',
    '    // with a space, not a comma',
    '    return 1;',
    '}',
    '',
    'inline int sapWandFourOneCommaCount() {',
    '    // only 2 commas on the 4 x I line',
    '    return 2;',
    '}',
    '',
    'inline int sapWandTableUse(int i) {',
    '    // the uses per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        4, 2, 2, 1, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapFinalXSignCount() {',
    '    // the round total of true x-signs',
    '    return 11;',
    '}',
    '',
    'inline int sapFinalBlankRunCount() {',
    '    // the round total of DM-fill blanks',
    '    return 24;',
    '}',
    '',
    'inline int sapFinalUnderscoreRunLen() {',
    '    // every blank is a 14-underscore run',
    '    return 14;',
    '}',
    '',
    'inline int sapFinalCurlyApostropheCount() {',
    '    // the mountain core, the Throne magic',
    '    return 2;',
    '}',
    '',
    'inline int sapFinalEmDashCount() {',
    '    // the section prints no em dashes',
    '    return 0;',
    '}',
    '',
    'inline int sapFinalPageSeamLine() {',
    '    // the absorbed running head, part2 line',
    '    return 1797;',
    '}',
    '',
    'inline int sapFinalSpecialDescriptionCount() {',
    '    // the 29 III.E Special descriptions',
    '    return 29;',
    '}',
    '',
]

AUDIT = [
    '    // ---- R295: the III.E Special artifacts',
    '    // explanation prose part 16 ----',
    '    // The Throne of the Gods and the',
    '    // Wand of Orcus, the 28th and 29th',
    '    // descriptions, part2 lines 1782-1814.',
    '    // No break absorbed - the round closes',
    '    // on the standard blank at 1814; the',
    '    // page seam at 1797 absorbed (a running',
    '    // head inside the round).',
    '    {',
    '        int bad = 0;',
    '        // the Throne prose scalars',
    '        if (rules::sapThroneCarvenMountainHeart() != 1 ||',
    '            rules::sapThroneMassiveStoneChair() != 1 ||',
    '            rules::sapThroneMosaicsIvoryMetals() != 1 ||',
    '            rules::sapThroneSetAboutGems() != 1 ||',
    '            rules::sapThroneGodsActuallySat() != 1 ||',
    '            rules::sapThroneWithinGreatCavern() != 1 ||',
    '            rules::sapThroneImmobileImmovable() != 1 ||',
    '            rules::sapThroneAffectsAnyoneSeated() != 1 ||',
    '            rules::sapThroneCertainMagicItem() != 1 ||',
    '            rules::sapThroneMalevolentEffectToo() != 1 ||',
    '            rules::sapThroneItemGainOnlyOnce() != 1 ||',
    '            rules::sapThroneProperWordsGestures() != 1 ||',
    '            rules::sapThroneGraspOptions() != 3) ++bad;',
    '        // the Throne table scalars',
    '        if (rules::sapThroneUseTotal() != 14 ||',
    '            rules::sapThroneTableOneCount() != 3 ||',
    '            rules::sapThroneTableTwoCount() != 3 ||',
    '            rules::sapThroneTableThreeCount() != 2 ||',
    '            rules::sapThroneTableFourCount() != 2 ||',
    '            rules::sapThroneTableFiveCount() != 2 ||',
    '            rules::sapThroneTableSixCount() != 2 ||',
    '            rules::sapThroneBlankSlotCount() != 14 ||',
    '            rules::sapThroneXSignCount() != 6 ||',
    '            rules::sapThroneBulletLineCount() != 0) ++bad;',
    '        static const int kT[6] = {',
    '            3, 3, 2, 2, 2, 2,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapThroneTableUse(i) != kT[i]) ++bad;',
    '        if (rules::sapThroneTableUse(0) +',
    '            rules::sapThroneTableUse(1) +',
    '            rules::sapThroneTableUse(2) +',
    '            rules::sapThroneTableUse(3) +',
    '            rules::sapThroneTableUse(4) +',
    '            rules::sapThroneTableUse(5) !=',
    '            rules::sapThroneUseTotal()) ++bad;',
    '        // the Wand prose scalars',
    '        if (rules::sapWandDemonPrinceProperty() != 1 ||',
    '            rules::sapWandPassesToPrimeMaterial() != 1 ||',
    '            rules::sapWandWreakChaosEvil() != 1 ||',
    '            rules::sapWandMonsterManualRef() != 1 ||',
    '            rules::sapWandSavingThrowVersusMagic() != 1 ||',
    '            rules::sapWandAvoidsDeathAnnihilation() != 1 ||',
    '            rules::sapWandImmuneCount() != 6) ++bad;',
    '        // the Wand table scalars',
    '        if (rules::sapWandUseTotal() != 10 ||',
    '            rules::sapWandTableOneCount() != 4 ||',
    '            rules::sapWandTableTwoCount() != 2 ||',
    '            rules::sapWandTableThreeCount() != 2 ||',
    '            rules::sapWandTableFourCount() != 1 ||',
    '            rules::sapWandTableFiveCount() != 0 ||',
    '            rules::sapWandTableSixCount() != 1 ||',
    '            rules::sapWandBlankSlotCount() != 10 ||',
    '            rules::sapWandXSignCount() != 5 ||',
    '            rules::sapWandBulletLineCount() != 5 ||',
    '            rules::sapWandFourOneSpaceSeparator() != 1 ||',
    '            rules::sapWandFourOneCommaCount() != 2) ++bad;',
    '        static const int kW[6] = {',
    '            4, 2, 2, 1, 0, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapWandTableUse(i) != kW[i]) ++bad;',
    '        if (rules::sapWandTableUse(0) +',
    '            rules::sapWandTableUse(1) +',
    '            rules::sapWandTableUse(2) +',
    '            rules::sapWandTableUse(3) +',
    '            rules::sapWandTableUse(4) +',
    '            rules::sapWandTableUse(5) !=',
    '            rules::sapWandUseTotal()) ++bad;',
    '        // the finale scalars and identities',
    '        if (rules::sapFinalXSignCount() != 11 ||',
    '            rules::sapFinalBlankRunCount() != 24 ||',
    '            rules::sapFinalUnderscoreRunLen() != 14 ||',
    '            rules::sapFinalCurlyApostropheCount() != 2 ||',
    '            rules::sapFinalEmDashCount() != 0 ||',
    '            rules::sapFinalPageSeamLine() != 1797 ||',
    '            rules::sapFinalSpecialDescriptionCount() != 29 ||',
    '            rules::sapFinalXSignCount() !=',
    '            rules::sapThroneXSignCount() +',
    '            rules::sapWandXSignCount() ||',
    '            rules::sapFinalBlankRunCount() !=',
    '            rules::sapThroneBlankSlotCount() +',
    '            rules::sapWandBlankSlotCount() ||',
    '            rules::sapThroneBlankSlotCount() !=',
    '            rules::sapThroneUseTotal() ||',
    '            rules::sapWandBlankSlotCount() !=',
    '            rules::sapWandUseTotal() ||',
    '            rules::sapWandBulletLineCount() !=',
    '            rules::sapWandXSignCount() ||',
    '            rules::sapWandTableFourCount() !=',
    '            rules::sapWandTableSixCount() ||',
    '            rules::sapWandFourOneCommaCount() !=',
    '            rules::sapWandTableOneCount() - 2) ++bad;',
    '        // the cross-pins: the R240 sale rows 27',
    '        // and 28 (the Throne priced ---, the',
    '        // Wand at 10000)',
    '        if (rules::saRowLo(27) != 99 ||',
    '            rules::saRowHi(27) != 99 ||',
    '            rules::saSaleGp(27) != 0 ||',
    '            rules::saSaleGpHi(27) != 0 ||',
    '            rules::saRowLo(28) != 100 ||',
    '            rules::saRowHi(28) != 100 ||',
    '            rules::saSaleGp(28) != 10000 ||',
    '            rules::saSaleGpHi(28) != 0) ++bad;',
    '        printf("R295 special artifacts prose part 16 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R295 landed the III.E Special',
    'artifacts explanation prose',
    'part 16 (part2 lines 1782-1814;',
    'global = 11065 + part2 line),',
    'the 28th and 29th of the 29',
    'descriptions - the last of the',
    'plan, the set now COMPLETE.',
    'The Throne of the Gods:',
    'carven from the heart of a',
    'majestic mountain, a massive',
    'stone chair inlaid with',
    'mosaics of ivory and precious',
    'metals and set about with',
    'gems, a throne upon which',
    'certain gods actually sat when',
    'they walked the world; within',
    'a great cavern, part of the',
    'mountain core, immobile and',
    'immovable; anyone daring to',
    'seat himself or herself is',
    'subject to the effects;',
    'certain, per fables, to gain a',
    'magic item, but with a',
    'malevolent effect too; the item',
    'gain cannot repeat, but the',
    'Throne can still affect the',
    'seated one if the proper words',
    'and gestures are known and',
    'followed - the seated one',
    'grasps either arm, both, or',
    'none (3 options) and utters a',
    'command; powers 3 of I, 3 of',
    'II, 2 of III, 2 of IV, 2 of V,',
    '2 of VI (walker 3,3,2,2,2,2,',
    'total 14). The Wand of Orcus:',
    'the ghastly weapon, property of',
    'the demon prince Orcus, at',
    'times allowed to pass into the',
    'Prime Material Plane to wreak',
    'chaos and evil on all living',
    'things there; see MONSTER',
    'MANUAL, Demon, Orcus; the',
    'wielder lacks the full',
    'death-dealing power - the',
    'victim saves versus magic to',
    'avoid death or annihilation;',
    'six ranks unaffected at all:',
    'gods, godlings, demon lords,',
    'greater devils, saints,',
    'demi-gods; powers 4 of I, 2',
    'of II, 2 of III, 1 of IV, 1 of',
    'VI, no table V (walker',
    '4,2,2,1,0,1, total 10). The',
    'quirks: 11 true x-signs, 24',
    'blank runs of exactly 14',
    'underscores; the Throne lines',
    'carry no bullets but the Wand',
    'prints all 5 table lines with',
    'leading - bullets; the Wand',
    '4 x I line joins runs 3 and 4',
    'with a space, not a comma - 4',
    'runs, 2 commas; 2 curly',
    'apostrophes (the mountain',
    'core, the Throne magic), zero',
    'ASCII apostrophes, zero em',
    'dashes, all dropped here; the',
    'page seam absorbed at 1797',
    '(a running head inside the',
    'round); the round closes on',
    'the standard blank at 1814 and',
    'the head at 1815 sits outside',
    'it; No break absorbed. The',
    'sale rows 27 and 28',
    'cross-pinned: the Throne band',
    '99 priced --- (zero gold',
    'pieces), the Wand band 00 -',
    'the d100 wraps, row value 100',
    '- at 10,000; zero high bounds',
    'via saSaleGpHi (census 213).',
    '51 accessors: 49 scalars + 2',
    'walkers, no name collisions',
    'with the miscprose and',
    'specart headers; the audit',
    'probes exactly those and the',
    'identities - the blanks equal',
    'the uses for both artifacts,',
    'the final x-signs equal the',
    'two x-counts, the final blanks',
    'equal the two blank counts,',
    'the Wand bullets equal its',
    'x-signs, the Wand commas equal',
    'its I count minus 2, and the',
    'IV and VI Wand counts match.',
    'The 29 III.E Special artifact',
    'descriptions are all landed -',
    'the III.E',
    'Special prose COMPLETE).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 51, 'accessor count is not 51'
assert len(set(defs)) == 51, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 49, 'scalar count is not 49'
walk = [d for d in defs if d not in scal]
assert len(walk) == 2, 'walker count is not 2'
assert set(walk) == {'sapThroneTableUse',
    'sapWandTableUse',
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
assert 'sapToothTableUse' in s0, 'specartprose2.h missing the R294 accessors'
assert 'sapKasTableUse' in s0, 'specartprose2.h missing the R293 accessors'
assert 'sapRodJointTable' in s0, 'specartprose2.h missing the R292 accessors'
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
assert ATEXT.count('R295 special artifacts prose part 16 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 16', 'Throne of the Gods', 'Wand of Orcus',
             '1782-1814', 'No break absorbed', 'census 213',
             '1797', 'saSaleGpHi', 'COMPLETE'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 16', 'The Throne of the Gods',
             'Wand of Orcus', '1782-1814', 'No break absorbed'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapThroneCarvenMountainHeart() {'
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
assert len(alldefs) == 523, 'accessor count is not 523'
assert len(set(alldefs)) == 523, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R295: the III.E Special artifacts'
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
assert s.count('R295 special artifacts prose part 16 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R295 landed the III.E Special'
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

print('R295 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R295 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 16 - the Throne of the Gods and')
print('the Wand of Orcus, part2 lines')
print('1782-1814;')
print('census 213 - the set COMPLETE.')
print('commit: R295: the III.E Special artifacts explanation prose part 16 pinned - the Throne of the Gods and the Wand of Orcus in part2 lines 1782-1814 (census 213)')

