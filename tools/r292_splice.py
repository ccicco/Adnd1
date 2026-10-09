#!/usr/bin/env python3
# R292 splice: the III.E Special
# artifacts explanation prose part
# 13 pins - the Rod of Seven Parts
# solo, the 24th of the 29 artifact
# descriptions, part2 lines
# 1677-1707. The Wind Dukes of Aaqa
# built it for the great battle of
# Pesh, where Chaos and Law
# contended; shattered there, its
# parts scattered, yet nothing
# could destroy it; correct-order
# assembly gives a weapon of
# surpassing power. The 7 parts:
# the first largest in length and
# diameter, the seventh smallest;
# no single part has any power or
# effect alone; each a short bar
# or baton, the seventh much like
# a short metal wand. The first
# senses the second - only when
# thought of as a fraction of a
# whole; found sections lead only
# upward; an out-of-order touch
# teleports the higher numbered
# piece 100 to 1,000 miles away;
# fully assembled it is almost 5
# feet long. Three fitted sections
# lock the grip for life until all
# parts join; part powers are
# cumulative, full powers need
# every part; the possessor cannot
# disassemble it, and each prime
# power use risks a 1 in 20 (5
# percent) breakup, the pieces
# teleporting 100-1200 miles in
# random directions. The assembly
# table: joints 1-2 table III, 2-3
# table I, 3-4 table I, 4-5 table
# IV, 5-6 table II, 6-7 table VI,
# one use each (6). The complete
# rod powers: table I once, II
# once, III twice, V twice, IV
# once (7) - V prints before IV,
# and no VI slot. Out of order the
# powers are not cumulative - the
# last piece joined alone stays
# active, all prior negated. No
# break absorbed - the round
# closes on the standard blank at
# 1707; no page seam claimed (no
# running heads between upload
# lines 1450 and 1797). 41
# accessors: 38 scalars + 3
# walkers. The audit cross-pins
# the R240 sale row 23: the band
# 69-74 at 25000 - a range row,
# its price fixed.
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
    'inline int sapRodWindDukesMadeIt() {',
    '    // the Wind Dukes of Aaqa are its legendary makers',
    '    return 1;',
    '}',
    '',
    'inline int sapRodMadeForBattleOfPesh() {',
    '    // constructed for the great battle of Pesh',
    '    return 1;',
    '}',
    '',
    'inline int sapRodPeshChaosVersusLaw() {',
    '    // at Pesh, Chaos and Law contended',
    '    return 1;',
    '}',
    '',
    'inline int sapRodShatteredAtPesh() {',
    '    // it was shattered there, its parts scattered',
    '    return 1;',
    '}',
    '',
    'inline int sapRodNothingDestroysIt() {',
    '    // nothing could actually destroy it',
    '    return 1;',
    '}',
    '',
    'inline int sapRodCorrectOrderSurpassingPower() {',
    '    // correct-order assembly gives surpassing power',
    '    return 1;',
    '}',
    '',
    'inline int sapRodPartCount() {',
    '    // the number of parts of the Rod',
    '    return 7;',
    '}',
    '',
    'inline int sapRodPartsSlightlyDifferent() {',
    '    // the parts are slightly different from each other',
    '    return 1;',
    '}',
    '',
    'inline int sapRodFirstLargestLengthDiameter() {',
    '    // the first is largest in length and diameter',
    '    return 1;',
    '}',
    '',
    'inline int sapRodSeventhSmallest() {',
    '    // the seventh is the smallest',
    '    return 1;',
    '}',
    '',
    'inline int sapRodNoAlonePower() {',
    '    // no single part has any power or effect alone',
    '    return 1;',
    '}',
    '',
    'inline int sapRodPartsLookLikeBatons() {',
    '    // singly each appears a short bar or baton',
    '    return 1;',
    '}',
    '',
    'inline int sapRodSeventhLooksLikeWand() {',
    '    // the seventh looks much like a short metal wand',
    '    return 1;',
    '}',
    '',
    'inline int sapRodFirstSensesSecond() {',
    '    // the first part senses the direction of the second',
    '    return 1;',
    '}',
    '',
    'inline int sapRodSensingNeedsWholeThought() {',
    '    // sensing works only as a fraction of a whole',
    '    return 1;',
    '}',
    '',
    'inline int sapRodLeadsOnlyUpward() {',
    '    // a found section leads only to the next higher numbered',
    '    return 1;',
    '}',
    '',
    'inline int sapRodOutOfOrderTouchTeleports() {',
    '    // an out-of-order touch teleports the higher piece away',
    '    return 1;',
    '}',
    '',
    'inline int sapRodTeleportMinMiles() {',
    '    // the out-of-order teleport minimum, in miles',
    '    return 100;',
    '}',
    '',
    'inline int sapRodTeleportMaxMiles() {',
    '    // the out-of-order teleport maximum, in miles',
    '    return 1000;',
    '}',
    '',
    'inline int sapRodAssembledLengthFeet() {',
    '    // the fully assembled length, in feet',
    '    return 5;',
    '}',
    '',
    'inline int sapRodThreeSectionsGripLock() {',
    '    // three fitted sections hold the grip for life',
    '    return 1;',
    '}',
    '',
    'inline int sapRodPartPowersCumulative() {',
    '    // the powers of each part are cumulative when joined',
    '    return 1;',
    '}',
    '',
    'inline int sapRodFullPowersNeedAllParts() {',
    '    // the full powers work only when all parts are joined',
    '    return 1;',
    '}',
    '',
    'inline int sapRodCannotBeDisassembled() {',
    '    // the possessor cannot disassemble it',
    '    return 1;',
    '}',
    '',
    'inline int sapRodPrimeRiskDenominator() {',
    '    // each prime power use: 1 in this many breakup risk',
    '    return 20;',
    '}',
    '',
    'inline int sapRodPrimeRiskPercent() {',
    '    // the same breakup risk, in percent',
    '    return 5;',
    '}',
    '',
    'inline int sapRodBreakupTeleportMinMiles() {',
    '    // the breakup teleport minimum, in miles',
    '    return 100;',
    '}',
    '',
    'inline int sapRodBreakupTeleportMaxMiles() {',
    '    // the breakup teleport maximum, in miles',
    '    return 1200;',
    '}',
    '',
    'inline int sapRodOutOfOrderNotCumulative() {',
    '    // out-of-order assembly: the powers are not cumulative',
    '    return 1;',
    '}',
    '',
    'inline int sapRodLastPieceJoinedActive() {',
    '    // only the last piece joined stays active, prior negated',
    '    return 1;',
    '}',
    '',
    'inline int sapRodInOrderCumulative() {',
    '    // in-order assembly is cumulative to the full powers',
    '    return 1;',
    '}',
    '',
    'inline int sapRodAssemblyRowCount() {',
    '    // the assembly powers table rows',
    '    return 6;',
    '}',
    '',
    'inline int sapRodAssemblyUseTotal() {',
    '    // 1+1+1+1+1+1 - the assembly use total',
    '    return 6;',
    '}',
    '',
    'inline int sapRodCompleteUseTotal() {',
    '    // 1+1+2+2+1 - the complete rod use total',
    '    return 7;',
    '}',
    '',
    'inline int sapRodCompleteOrderQuirk() {',
    '    // the complete list prints table V before table IV',
    '    return 1;',
    '}',
    '',
    'inline int sapRodCompleteLacksTableVI() {',
    '    // no table VI slot, though the assembly has one',
    '    return 1;',
    '}',
    '',
    'inline int sapRodBlankSlotCount() {',
    '    // the DM-fill blank slots, 6 assembly + 7 complete',
    '    return 13;',
    '}',
    '',
    'inline int sapRodBlankSlotUnderscores() {',
    '    // the underscores per blank slot',
    '    return 11;',
    '}',
    '',
    'inline int sapRodJointTable(int i) {',
    '    // the assembly joint tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 1, 1, 4, 2, 6,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapRodJointUseCount(int i) {',
    '    // the assembly joint use counts; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        1, 1, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapRodCompleteTableUse(int i) {',
    '    // the complete rod uses per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        1, 1, 2, 1, 2, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R292: the III.E Special artifacts',
    '    // explanation prose part 13 ----',
    '    // The Rod of Seven Parts, part2',
    '    // lines 1677-1707. No break absorbed -',
    '    // the round closes on the standard',
    '    // blank at 1707; no page seam claimed',
    '    // (no running heads between lines 1450',
    '    // and 1797).',
    '    {',
    '        int bad = 0;',
    '        // the origin, the shattering and the parts',
    '        if (rules::sapRodWindDukesMadeIt() != 1 ||',
    '            rules::sapRodMadeForBattleOfPesh() != 1 ||',
    '            rules::sapRodPeshChaosVersusLaw() != 1 ||',
    '            rules::sapRodShatteredAtPesh() != 1 ||',
    '            rules::sapRodNothingDestroysIt() != 1 ||',
    '            rules::sapRodCorrectOrderSurpassingPower() != 1 ||',
    '            rules::sapRodPartCount() != 7 ||',
    '            rules::sapRodPartsSlightlyDifferent() != 1 ||',
    '            rules::sapRodFirstLargestLengthDiameter() != 1 ||',
    '            rules::sapRodSeventhSmallest() != 1 ||',
    '            rules::sapRodNoAlonePower() != 1 ||',
    '            rules::sapRodPartsLookLikeBatons() != 1 ||',
    '            rules::sapRodSeventhLooksLikeWand() != 1) ++bad;',
    '        // the senses, the teleports and the length',
    '        if (rules::sapRodFirstSensesSecond() != 1 ||',
    '            rules::sapRodSensingNeedsWholeThought() != 1 ||',
    '            rules::sapRodLeadsOnlyUpward() != 1 ||',
    '            rules::sapRodOutOfOrderTouchTeleports() != 1 ||',
    '            rules::sapRodTeleportMinMiles() != 100 ||',
    '            rules::sapRodTeleportMaxMiles() != 1000 ||',
    '            rules::sapRodAssembledLengthFeet() != 5 ||',
    '            rules::sapRodBreakupTeleportMinMiles() != 100 ||',
    '            rules::sapRodBreakupTeleportMaxMiles() != 1200) ++bad;',
    '        // the two teleport minimums agree at 100 miles',
    '        if (rules::sapRodTeleportMinMiles() !=',
    '            rules::sapRodBreakupTeleportMinMiles()) ++bad;',
    '        // the grip, the cumulation and the breakup risk',
    '        if (rules::sapRodThreeSectionsGripLock() != 1 ||',
    '            rules::sapRodPartPowersCumulative() != 1 ||',
    '            rules::sapRodFullPowersNeedAllParts() != 1 ||',
    '            rules::sapRodCannotBeDisassembled() != 1 ||',
    '            rules::sapRodPrimeRiskDenominator() != 20 ||',
    '            rules::sapRodPrimeRiskPercent() != 5 ||',
    '            rules::sapRodOutOfOrderNotCumulative() != 1 ||',
    '            rules::sapRodLastPieceJoinedActive() != 1 ||',
    '            rules::sapRodInOrderCumulative() != 1) ++bad;',
    '        // the assembly powers table',
    '        if (rules::sapRodAssemblyRowCount() != 6 ||',
    '            rules::sapRodAssemblyUseTotal() != 6) ++bad;',
    '        static const int kT[6] = {',
    '            3, 1, 1, 4, 2, 6,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapRodJointTable(i) != kT[i]) ++bad;',
    '        static const int kU[6] = {',
    '            1, 1, 1, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapRodJointUseCount(i) != kU[i]) ++bad;',
    '        if (rules::sapRodJointUseCount(0) +',
    '            rules::sapRodJointUseCount(1) +',
    '            rules::sapRodJointUseCount(2) +',
    '            rules::sapRodJointUseCount(3) +',
    '            rules::sapRodJointUseCount(4) +',
    '            rules::sapRodJointUseCount(5) !=',
    '            rules::sapRodAssemblyUseTotal()) ++bad;',
    '        // the complete rod powers',
    '        if (rules::sapRodCompleteUseTotal() != 7 ||',
    '            rules::sapRodCompleteOrderQuirk() != 1 ||',
    '            rules::sapRodCompleteLacksTableVI() != 1) ++bad;',
    '        static const int kC[6] = {',
    '            1, 1, 2, 1, 2, 0,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapRodCompleteTableUse(i) != kC[i]) ++bad;',
    '        if (rules::sapRodCompleteTableUse(0) +',
    '            rules::sapRodCompleteTableUse(1) +',
    '            rules::sapRodCompleteTableUse(2) +',
    '            rules::sapRodCompleteTableUse(3) +',
    '            rules::sapRodCompleteTableUse(4) +',
    '            rules::sapRodCompleteTableUse(5) !=',
    '            rules::sapRodCompleteUseTotal()) ++bad;',
    '        // the blank slots: 6 assembly + 7 complete = 13',
    '        if (rules::sapRodBlankSlotCount() !=',
    '            rules::sapRodAssemblyRowCount() +',
    '            rules::sapRodCompleteUseTotal()) ++bad;',
    '        if (rules::sapRodBlankSlotUnderscores() != 11) ++bad;',
    '        // the cross-pin: the R240 sale table row 23',
    '        // (a range row, 69-74, its price fixed)',
    '        if (rules::saRowLo(23) != 69 ||',
    '            rules::saRowHi(23) != 74 ||',
    '            rules::saSaleGp(23) != 25000 ||',
    '            rules::saSaleGpHi(23) != 0) ++bad;',
    '        printf("R292 special artifacts prose part 13 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R292 landed the III.E Special',
    'artifacts explanation prose',
    'part 13 (part2 lines 1677-1707;',
    'global = 11065 + part2 line; the',
    'R291 next pointer misstated the',
    'global as 12842 - the correct',
    'global for line 1677 is 12742):',
    'the Rod of Seven Parts, the 24th',
    'of the 29 descriptions.',
    'No break absorbed - the round',
    'closes on the standard blank at',
    '1707; no page seam claimed (no',
    'running heads between lines 1450',
    'and 1797; the 1684 and 1694',
    'heads are the description own',
    'sub-heads, not page seams). The',
    'Wind Dukes of Aaqa are its',
    'legendary makers; built for the',
    'great battle of Pesh where',
    'Chaos and Law contended; smashed',
    'there, its parts scattered, yet',
    'nothing could destroy it; the',
    'sections recovered and put',
    'together in the correct order',
    'give a weapon of surpassing',
    'power. The 7 parts differ: the',
    'first is largest in length and',
    'diameter, the seventh smallest;',
    'no single part has any power or',
    'effect alone; singly each looks',
    'a short bar or baton, the',
    'seventh much the same as a',
    'short metal wand. The first part',
    'senses the direction of the',
    'second - but only when the',
    'finder thinks of the section as',
    'a fraction of a whole magic',
    'item; a found section leads only',
    'to the next higher numbered, not',
    'a lower one; an out-of-order',
    'touch teleports the higher',
    'numbered piece away, 100 to',
    '1,000 miles in a random',
    'direction; fully assembled it is',
    'almost 5 feet long. Three fitted',
    'sections and the possessor',
    'cannot let go while he or she',
    'lives, until all parts are',
    'joined; the powers of each part',
    'are cumulative whenever joined,',
    'but the full powers work only',
    'when all parts are joined; the',
    'Rod cannot be disassembled by',
    'its possessor, and each prime',
    'power use risks a 1 in 20 (5',
    'percent) breakup - the whole',
    'flies into its component pieces,',
    'teleporting 100-1200 miles away',
    'in random directions. The',
    'assembly table: parts 1-2 carry',
    'table III, 2-3 table I, 3-4',
    'table I, 4-5 table IV, 5-6',
    'table II, 6-7 table VI - one use',
    'each joint, total 6. The',
    'complete rod powers: table I',
    'once, table II once, table III',
    'twice, table V twice, table IV',
    'once - total 7. If the Rod is',
    'not assembled in order the',
    'powers are not cumulative; only',
    'the last piece joined stays',
    'active, all prior parts negated;',
    'in order the powers are',
    'cumulative, and the assembled',
    'Rod gains the additional full',
    'powers. The quirks: the 5 feet',
    'mark prints as the curly feet',
    'mark; nine em dashes - three in',
    'the prose, one per assembly',
    'row; eleven true multiplication',
    'signs; the out- of-order hyphen',
    'wraps across the 1677 line',
    'break; the 1680 range prints as',
    '100 to 1,000 with its comma, the',
    '1682 range as plain 100-1200;',
    'the power slots print as 13',
    'blank underscore runs of 11',
    'each, DM-filled; the complete',
    'list prints table V before table',
    'IV and carries no table VI slot',
    'though the assembly has one -',
    'all pinned as plain digits and',
    'words, apostrophe-free and',
    'backslash-free here. 41',
    'accessors: 38 scalars + 3',
    'walkers (the joint tables',
    '3,1,1,4,2,6, the joint uses',
    '1,1,1,1,1,1, the complete table',
    'uses 1,1,2,1,2,0), no name',
    'collisions with the miscprose',
    'and specart headers; the audit',
    'cross-pins the R240 sale row 23',
    '- the Rod band 69-74 at 25000,',
    'a range row, its price fixed,',
    'the zero high bound carried by',
    'saSaleGpHi (census 210). Next:',
    'R293 III.E Special part 14 -',
    'the Sceptre of Might and the',
    'Sword of Kas in part2 from',
    'line 1708 (global 12773; the',
    'Teeth of Dahlver-Nar and the',
    'other descriptions follow; the',
    'III.E Special prose continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 41, 'accessor count is not 41'
assert len(set(defs)) == 41, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 38, 'scalar count is not 38'
walk = [d for d in defs if d not in scal]
assert len(walk) == 3, 'walker count is not 3'
assert set(walk) == {'sapRodJointTable',
    'sapRodJointUseCount',
    'sapRodCompleteTableUse',
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
assert 'sapNightingalePowerCount' in s0, 'specartprose2.h missing the R291 accessors'
assert 'sapOrbMightPowerCount' in s0, 'specartprose2.h missing the R290 accessors'
assert 'sapOrbGreatSerpentPowerCount' in s0, 'specartprose2.h missing the R289 accessors'
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
assert ATEXT.count('R292 special artifacts prose part 13 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 13', 'Rod of Seven Parts', '1677-1707',
             'No break absorbed', 'census 210', 'R293',
             'line 1708', '12773', 'saSaleGpHi', '12742'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 13', 'The Rod of Seven Parts',
             '1677-1707', 'No break absorbed'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapRodWindDukesMadeIt() {'
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
assert len(alldefs) == 390, 'accessor count is not 390'
assert len(set(alldefs)) == 390, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R292: the III.E Special artifacts'
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
assert s.count('R292 special artifacts prose part 13 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R292 landed the III.E Special'
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

print('R292 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R292 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 13 - the Rod of Seven Parts,')
print('part2 lines 1677-1707;')
print('census 210.')
print('commit: R292: the III.E Special artifacts explanation prose part 13 pinned - the Rod of Seven Parts in part2 lines 1677-1707 (census 210)')

