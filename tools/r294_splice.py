#!/usr/bin/env python3
# R294 splice: the III.E Special
# artifacts explanation prose part
# 15 pins - the Teeth of
# Dahlver-Nar solo, the 27th of
# the 29 artifact descriptions,
# part2 lines 1744-1781. The
# renowned cleric: if any was
# more powerful, histories do not
# tell; the gods themselves gave
# him special powers, passed on
# by the great relics - his
# teeth; each Tooth has some
# power; a full quarter, half or
# all brings other grand
# benefits; a tooth grafts into
# the mouth in place of a like
# missing tooth, never removed
# once emplaced short of the
# demise of the possessor; the
# powers and effects are
# cumulative. The tooth table:
# 32 teeth in 16 two-column
# rows, per-table counts 21, 4,
# 4, 1, 0, 2 (walker
# 21,4,4,1,0,2, total 32); the
# lone IV is tooth 21; the VI
# teeth are 7 and 14; the II
# teeth are 2, 16, 24, 28; the
# III teeth are 3, 9, 26, 29.
# The set table: 8 two-column
# pair rows - the quarters 1-8
# at II+VI, 9-16 at II+IV,
# 17-24 at II+III, 25-32 at
# II+III - then the halves
# repeat those four rows
# verbatim; 3 table V rows
# (1-16, 17-32, 1-32); the
# right-column walker
# 0,0,4,2,0,2 totals the 8 pair
# rows. 51 true x-signs, 51
# blanks of exactly 14
# underscores - the counts
# match, both pinned. The audit
# cross-pins the R240 sale row
# 26: 93-98 at 5,000/tooth, the
# part1 per-tooth price suffix
# stripped here. The cleanest
# section yet: zero apostrophes,
# zero em dashes, zero
# backslashes, zero percent
# signs. No break absorbed - the
# round closes on the standard
# blank at 1781; no page seam
# claimed (no running heads
# between upload lines 1450
# and 1797). 39 accessors: 37
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
    'inline int sapToothHistoriesSilent() {',
    '    // no history tells of a cleric more',
    '    // powerful than the renowned Dahlver-Nar',
    '    return 1;',
    '}',
    '',
    'inline int sapToothGodsGavePowers() {',
    '    // the gods themselves gave the powers',
    '    return 1;',
    '}',
    '',
    'inline int sapToothRelicsAreTeeth() {',
    '    // the great relics are his teeth',
    '    return 1;',
    '}',
    '',
    'inline int sapToothEachToothHasPower() {',
    '    // each of the Teeth has some power',
    '    return 1;',
    '}',
    '',
    'inline int sapToothCount() {',
    '    // the number of Teeth of Dahlver-Nar',
    '    return 32;',
    '}',
    '',
    'inline int sapToothBenefitLevels() {',
    '    // quarter, half, or all - 3 levels',
    '    return 3;',
    '}',
    '',
    'inline int sapToothQuarterCount() {',
    '    // a full quarter of the teeth',
    '    return 8;',
    '}',
    '',
    'inline int sapToothHalfCount() {',
    '    // half of the teeth',
    '    return 16;',
    '}',
    '',
    'inline int sapToothGraftsInMouth() {',
    '    // placed into the mouth to gain power',
    '    return 1;',
    '}',
    '',
    'inline int sapToothLikeMissingTooth() {',
    '    // grafts in place of a like missing tooth',
    '    return 1;',
    '}',
    '',
    'inline int sapToothNeverRemoved() {',
    '    // never removed once so emplaced',
    '    return 1;',
    '}',
    '',
    'inline int sapToothRemovalOnlyByDemise() {',
    '    // removal only by the possessor demise',
    '    return 1;',
    '}',
    '',
    'inline int sapToothPowersCumulative() {',
    '    // the powers and effects are cumulative',
    '    return 1;',
    '}',
    '',
    'inline int sapToothUseTotal() {',
    '    // the tooth table use total, 32 teeth',
    '    return 32;',
    '}',
    '',
    'inline int sapToothTableOneCount() {',
    '    // the teeth of table I in the tooth table',
    '    return 21;',
    '}',
    '',
    'inline int sapToothTableTwoCount() {',
    '    // the II teeth: 2, 16, 24 and 28',
    '    return 4;',
    '}',
    '',
    'inline int sapToothTableThreeCount() {',
    '    // the III teeth: 3, 9, 26 and 29',
    '    return 4;',
    '}',
    '',
    'inline int sapToothTableFourCount() {',
    '    // the lone table IV tooth',
    '    return 1;',
    '}',
    '',
    'inline int sapToothTableFiveCount() {',
    '    // the tooth table carries no table V',
    '    return 0;',
    '}',
    '',
    'inline int sapToothTableSixCount() {',
    '    // the VI teeth: 7 and 14',
    '    return 2;',
    '}',
    '',
    'inline int sapToothLoneFourTooth() {',
    '    // tooth 21 is the lone table IV tooth',
    '    return 21;',
    '}',
    '',
    'inline int sapToothFirstSixTooth() {',
    '    // tooth 7 is the first table VI tooth',
    '    return 7;',
    '}',
    '',
    'inline int sapToothSecondSixTooth() {',
    '    // tooth 14 is the second table VI tooth',
    '    return 14;',
    '}',
    '',
    'inline int sapToothUnderscoreRunLen() {',
    '    // every blank is a 14-underscore run',
    '    return 14;',
    '}',
    '',
    'inline int sapToothBlankSlotCount() {',
    '    // 32 + 8 x 2 + 3 DM-fill blanks',
    '    return 51;',
    '}',
    '',
    'inline int sapToothXSignCount() {',
    '    // the true multiplication signs, 51',
    '    return 51;',
    '}',
    '',
    'inline int sapToothSetPairRows() {',
    '    // the 8 two-column set table rows',
    '    return 8;',
    '}',
    '',
    'inline int sapToothSetQuarterRows() {',
    '    // the quarter rows: 1-8, 9-16,',
    '    // 17-24 and 25-32',
    '    return 4;',
    '}',
    '',
    'inline int sapToothSetHalfRepeatQuarters() {',
    '    // the half rows repeat the quarter rows',
    '    return 1;',
    '}',
    '',
    'inline int sapToothSetFiveRows() {',
    '    // the V rows: 1-16, 17-32 and 1-32',
    '    return 3;',
    '}',
    '',
    'inline int sapToothSetLeftTwoCount() {',
    '    // set table left column: 8 rows of II',
    '    return 8;',
    '}',
    '',
    'inline int sapToothSetLeftFiveCount() {',
    '    // set table left column: 3 rows of V',
    '    return 3;',
    '}',
    '',
    'inline int sapToothSetRightThreeCount() {',
    '    // set table right column III entries',
    '    return 4;',
    '}',
    '',
    'inline int sapToothSetRightFourCount() {',
    '    // set table right column IV entries',
    '    return 2;',
    '}',
    '',
    'inline int sapToothSetRightSixCount() {',
    '    // set table right column VI entries',
    '    return 2;',
    '}',
    '',
    'inline int sapToothTableUse(int i) {',
    '    // the teeth per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        21, 4, 4, 1, 0, 2,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapToothSetRightUse(int i) {',
    '    // right-column sets per I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        0, 0, 4, 2, 0, 2,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R294: the III.E Special artifacts',
    '    // explanation prose part 15 ----',
    '    // The Teeth of Dahlver-Nar, part2',
    '    // lines 1744-1781. No break absorbed',
    '    // - the round closes on the standard',
    '    // blank at 1781; no page seam claimed',
    '    // (no running heads between lines 1450',
    '    // and 1797).',
    '    {',
    '        int bad = 0;',
    '        // the legend and emplacement scalars',
    '        if (rules::sapToothHistoriesSilent() != 1 ||',
    '            rules::sapToothGodsGavePowers() != 1 ||',
    '            rules::sapToothRelicsAreTeeth() != 1 ||',
    '            rules::sapToothEachToothHasPower() != 1 ||',
    '            rules::sapToothCount() != 32 ||',
    '            rules::sapToothBenefitLevels() != 3 ||',
    '            rules::sapToothQuarterCount() != 8 ||',
    '            rules::sapToothHalfCount() != 16 ||',
    '            rules::sapToothGraftsInMouth() != 1 ||',
    '            rules::sapToothLikeMissingTooth() != 1 ||',
    '            rules::sapToothNeverRemoved() != 1 ||',
    '            rules::sapToothRemovalOnlyByDemise() != 1 ||',
    '            rules::sapToothPowersCumulative() != 1) ++bad;',
    '        // the tooth table counts and blanks',
    '        if (rules::sapToothUseTotal() != 32 ||',
    '            rules::sapToothTableOneCount() != 21 ||',
    '            rules::sapToothTableTwoCount() != 4 ||',
    '            rules::sapToothTableThreeCount() != 4 ||',
    '            rules::sapToothTableFourCount() != 1 ||',
    '            rules::sapToothTableFiveCount() != 0 ||',
    '            rules::sapToothTableSixCount() != 2 ||',
    '            rules::sapToothLoneFourTooth() != 21 ||',
    '            rules::sapToothFirstSixTooth() != 7 ||',
    '            rules::sapToothSecondSixTooth() != 14 ||',
    '            rules::sapToothUnderscoreRunLen() != 14 ||',
    '            rules::sapToothBlankSlotCount() != 51 ||',
    '            rules::sapToothXSignCount() != 51) ++bad;',
    '        static const int kT[6] = {',
    '            21, 4, 4, 1, 0, 2,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapToothTableUse(i) != kT[i]) ++bad;',
    '        if (rules::sapToothTableUse(0) +',
    '            rules::sapToothTableUse(1) +',
    '            rules::sapToothTableUse(2) +',
    '            rules::sapToothTableUse(3) +',
    '            rules::sapToothTableUse(4) +',
    '            rules::sapToothTableUse(5) !=',
    '            rules::sapToothUseTotal()) ++bad;',
    '        // the set table counts',
    '        if (rules::sapToothSetPairRows() != 8 ||',
    '            rules::sapToothSetQuarterRows() != 4 ||',
    '            rules::sapToothSetHalfRepeatQuarters() != 1 ||',
    '            rules::sapToothSetFiveRows() != 3 ||',
    '            rules::sapToothSetLeftTwoCount() != 8 ||',
    '            rules::sapToothSetLeftFiveCount() != 3 ||',
    '            rules::sapToothSetRightThreeCount() != 4 ||',
    '            rules::sapToothSetRightFourCount() != 2 ||',
    '            rules::sapToothSetRightSixCount() != 2) ++bad;',
    '        static const int kS[6] = {',
    '            0, 0, 4, 2, 0, 2,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapToothSetRightUse(i) != kS[i]) ++bad;',
    '        if (rules::sapToothSetRightUse(0) +',
    '            rules::sapToothSetRightUse(1) +',
    '            rules::sapToothSetRightUse(2) +',
    '            rules::sapToothSetRightUse(3) +',
    '            rules::sapToothSetRightUse(4) +',
    '            rules::sapToothSetRightUse(5) !=',
    '            rules::sapToothSetPairRows()) ++bad;',
    '        // the identities the tables carry',
    '        if (rules::sapToothXSignCount() !=',
    '            rules::sapToothBlankSlotCount() ||',
    '            rules::sapToothBlankSlotCount() !=',
    '            rules::sapToothUseTotal() +',
    '            2 * rules::sapToothSetPairRows() +',
    '            rules::sapToothSetFiveRows() ||',
    '            rules::sapToothSetLeftTwoCount() +',
    '            rules::sapToothSetLeftFiveCount() !=',
    '            rules::sapToothSetPairRows() +',
    '            rules::sapToothSetFiveRows() ||',
    '            rules::sapToothSetRightThreeCount() +',
    '            rules::sapToothSetRightFourCount() +',
    '            rules::sapToothSetRightSixCount() !=',
    '            rules::sapToothSetPairRows() ||',
    '            rules::sapToothTableUse(0) !=',
    '            rules::sapToothTableOneCount() ||',
    '            rules::sapToothTableUse(3) !=',
    '            rules::sapToothTableFourCount() ||',
    '            rules::sapToothTableUse(5) !=',
    '            rules::sapToothTableSixCount() ||',
    '            rules::sapToothLoneFourTooth() != 21) ++bad;',
    '        // the cross-pin: the R240 sale row 26',
    '        // (a per-tooth price, a 93-98 range row)',
    '        if (rules::saRowLo(26) != 93 ||',
    '            rules::saRowHi(26) != 98 ||',
    '            rules::saSaleGp(26) != 5000 ||',
    '            rules::saSaleGpHi(26) != 0) ++bad;',
    '        printf("R294 special artifacts prose part 15 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R294 landed the III.E Special',
    'artifacts explanation prose',
    'part 15 (part2 lines 1744-1781;',
    'global = 11065 + part2 line),',
    'the 27th of the 29 descriptions:',
    'the Teeth of Dahlver-Nar solo. If',
    'any cleric was more powerful than',
    'the renowned Dahlver-Nar,',
    'histories do not tell us; the gods',
    'themselves gave him special',
    'powers, passed on to others by',
    'the great relics - his teeth;',
    'each Tooth has some power, and a',
    'full quarter, half, or all brings',
    'other grand benefits; to gain a',
    'tooth power the character places',
    'it into the mouth, where it',
    'grafts in place of a like missing',
    'tooth; never removed once',
    'emplaced short of the demise of',
    'the possessor; the powers and',
    'effects are cumulative. The tooth',
    'table: 32 teeth in 16 two-column',
    'rows, per-table counts 21, 4, 4,',
    '1, 0, 2 (walker 21,4,4,1,0,2,',
    'total 32); the lone IV is tooth',
    '21; the VI teeth are 7 and 14;',
    'the II teeth are 2, 16, 24 and',
    '28; the III teeth are 3, 9, 26',
    'and 29. The set table: 8',
    'two-column pair rows - the',
    'quarters 1-8 at II+VI, 9-16 at',
    'II+IV, 17-24 at II+III, 25-32',
    'at II+III - then the halves',
    'repeat those four rows verbatim;',
    '3 table V rows - 1-16, 17-32',
    'and 1-32 - each 1 x V; the',
    'right-column walker 0,0,4,2,0,2',
    'totals the 8 pair rows. The',
    'quirks: the cleanest section yet',
    '- zero apostrophes, curly or',
    'ASCII, zero em dashes, zero',
    'backslashes, zero percent signs;',
    '51 true x-signs and 51 blank',
    'runs of exactly 14 underscores -',
    'the x-sign count equals the',
    'blank count, both pinned. The',
    'sale row 26 cross-pinned: 93-98',
    'at 5,000/tooth - part1 prints the',
    'price with a per-tooth suffix,',
    'stripped here; a range row, its',
    'high bound zero via saSaleGpHi',
    '(census 212). 37 accessors: 35',
    'scalars + 2 walkers, no name',
    'collisions with the miscprose',
    'and specart headers; the audit',
    'probes exactly those and the',
    'identities - x-signs equal',
    'blanks, blanks equal the uses',
    'plus twice the pair rows plus',
    'the V rows, the left column',
    'equals the pair rows plus the V',
    'rows, the right column equals',
    'the pair rows, and the walker',
    'slots mirror the I, IV and VI',
    'scalars. No break absorbed - the',
    'round closes on the standard',
    'blank at 1781; no page seam',
    'claimed (no running heads',
    'between lines 1450 and 1797).',
    'Next: R295 III.E Special part 16',
    '- the Throne of the Gods and the',
    'Wand of Orcus in part2 from',
    'line 1782 (global 12847; the',
    'III.E',
    'Special prose continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 37, 'accessor count is not 37'
assert len(set(defs)) == 37, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 35, 'scalar count is not 35'
walk = [d for d in defs if d not in scal]
assert len(walk) == 2, 'walker count is not 2'
assert set(walk) == {'sapToothTableUse',
    'sapToothSetRightUse',
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
assert 'sapKasTableUse' in s0, 'specartprose2.h missing the R293 accessors'
assert 'sapRodJointTable' in s0, 'specartprose2.h missing the R292 accessors'
assert 'sapNightingalePowerCount' in s0, 'specartprose2.h missing the R291 accessors'
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
assert ATEXT.count('R294 special artifacts prose part 15 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 15', 'Dahlver-Nar',
             '1744-1781', 'No break absorbed', 'census 212',
             'R295', 'line 1782', '12847', 'saSaleGpHi',
             '5,000/tooth'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 15', 'The Teeth of Dahlver-Nar',
             '1744-1781', 'No break absorbed'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapToothHistoriesSilent() {'
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
assert len(alldefs) == 472, 'accessor count is not 472'
assert len(set(alldefs)) == 472, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R294: the III.E Special artifacts'
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
assert s.count('R294 special artifacts prose part 15 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R294 landed the III.E Special'
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

print('R294 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R294 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 15 - the Teeth of Dahlver-Nar,')
print('part2 lines 1744-1781;')
print('census 212.')
print('commit: R294: the III.E Special artifacts explanation prose part 15 pinned - the Teeth of Dahlver-Nar in part2 lines 1744-1781 (census 212)')

