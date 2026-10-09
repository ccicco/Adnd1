#!/usr/bin/env python3
# R284 splice: the III.E Special artifacts
# explanation prose part 5 pins - the Eye of
# Vecna and the Hand of Vecna, part2 lines
# 1318-1357 (DMG p.160-161), the seventh and
# eighth of the 29 artifact descriptions. The
# Eye: the phantom of the once supreme lich
# still roams the Material Plane; one eye and
# one hand survived his doom; the Eye glows
# like a feral creature, appears an agate
# until placed in an empty eye socket, then
# instantly and irrevocably grafts to the
# head, not removed or harmed without
# slaying the character; the host alignment
# immediately becomes neutral evil, never to
# change; the Eye bestows infravision and
# ultravision; powers 2 each of tables I and
# II, 1 each of IV and V (table III skipped);
# the primary power use causes a malevolent
# effect on the host. The Hand: his left
# hand, a mummified extremity, blackened and
# shriveled, possibly from a burned body;
# pressed against a forearm stump it grafts
# instantly, a functioning member with 18/00
# strength in its grip, no to hit or damage
# bonuses; the host eventually turns neutral
# evil; a major power use wakes a spirit of
# great evil; a primary power use makes the
# host instantly neutral evil, very evil; the
# Hand can be severed before its powers are
# used with 100 percent certainty, each major
# power use subtracting 1 percent and each
# primary power use making success 10 percent
# less likely, at 100 percent subtraction no
# removal is possible and the character will
# know; the powers work through extended or
# curled finger combinations; powers 10 of
# table I, 5 of II, 2 each of III, IV and V,
# 1 of VI; nothing short of intervention from
# the most powerful of gods can alter the
# effects upon the host, and even the
# greatest deities are loath to meddle - the
# effects are irrevocable; the note asks the
# DM to devise and record the finger and hand
# position chart. This round has one seam
# restored: the p.160-161 page break splits
# the severing paragraph between the 1332
# tail (The Hand can be severed from) and the
# 1337 head (the host at any time before its
# powers are used) across the blank pair at
# 1333-1334, the TREASURE (ARTIFACTS &
# RELICS) running head at 1335 and the 1336
# post-head blank. The upload quirks this
# round: the power lines print the counts as
# N x table with the true multiplication
# sign, 10 of them; the to hit fragment
# prints curly double quotes; the character
# part and VECNA HAND apostrophes print as
# the curly right single quote; the very evil
# and loath dashes print as true em-dashes;
# the hand 10 of table I power line wraps
# across three lines; the 2 of IV and 1 of VI
# lines drop the space after the colon - all
# pinned as plain digits and words,
# apostrophe-free here. 28 accessors: 26
# scalars + 2 walkers (the eye power walker
# 2,2,0,1,1 and the hand power walker
# 10,5,2,2,2,1), no name collisions with the
# miscprose and specart headers. The audit
# cross-pins the R240 sale table rows: the Eye
# band 23-24 at 35000, the Hand band 25 at
# 60000.
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
    'inline int sapEyeVecnaPhantomRoams() {',
    '    // the phantom of the once supreme lich roams',
    '    return 1;',
    '}',
    '',
    'inline int sapEyeDoomSurvivors() {',
    '    // one eye and one hand survived his doom',
    '    return 2;',
    '}',
    '',
    'inline int sapEyeFeralGlow() {',
    '    // glows in the same manner as a feral creature',
    '    return 1;',
    '}',
    '',
    'inline int sapEyeAppearsAgate() {',
    '    // appears an agate until placed in an eye socket',
    '    return 1;',
    '}',
    '',
    'inline int sapEyeGraftIrrevocable() {',
    '    // grafts irrevocably, removed only by slaying',
    '    return 1;',
    '}',
    '',
    'inline int sapEyeHostNeutralEvil() {',
    '    // the host alignment becomes neutral evil, never changes',
    '    return 1;',
    '}',
    '',
    'inline int sapEyeGrantsInfravision() {',
    '    // the Eye bestows infravision to its host',
    '    return 1;',
    '}',
    '',
    'inline int sapEyeGrantsUltravision() {',
    '    // the Eye bestows ultravision to its host',
    '    return 1;',
    '}',
    '',
    'inline int sapEyePowerTotal() {',
    '    // 2 each of I-II, 1 each of IV-V (III skipped)',
    '    return 6;',
    '}',
    '',
    'inline int sapEyePowerCount(int i) {',
    '    // the powers per tables I-V; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 4) i = 4;',
    '    static const int t[5] = {',
    '        2, 2, 0, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapEyePrimaryPowerMalevolent() {',
    '    // the primary power causes a malevolent effect',
    '    return 1;',
    '}',
    '',
    'inline int sapHandVecnaLeftHand() {',
    '    // his left hand, imbued with powers',
    '    return 1;',
    '}',
    '',
    'inline int sapHandMummifiedExtremity() {',
    '    // a blackened, shriveled mummified extremity',
    '    return 1;',
    '}',
    '',
    'inline int sapHandGripStrength() {',
    '    // a functioning member with 18/00 strength',
    '    return 18;',
    '}',
    '',
    'inline int sapHandGripStrengthRating() {',
    '    // the printed 00 rating of the 18/00 grip',
    '    return 0;',
    '}',
    '',
    'inline int sapHandGripHitOrDamageBonus() {',
    '    // no to hit or damage bonuses',
    '    return 0;',
    '}',
    '',
    'inline int sapHandHostTurnsNeutralEvil() {',
    '    // the host eventually turns neutral evil',
    '    return 1;',
    '}',
    '',
    'inline int sapHandMajorPowerWakesSpirit() {',
    '    // a major power use wakes a spirit of great evil',
    '    return 1;',
    '}',
    '',
    'inline int sapHandPrimaryPowerInstantEvil() {',
    '    // a primary power: instantly neutral evil',
    '    return 1;',
    '}',
    '',
    'inline int sapHandSeverBaseChancePct() {',
    '    // severed before powers used, 100 percent certainty',
    '    return 100;',
    '}',
    '',
    'inline int sapHandSeverMajorPenaltyPct() {',
    '    // each major power use subtracts 1 percent',
    '    return 1;',
    '}',
    '',
    'inline int sapHandSeverPrimaryPenaltyPct() {',
    '    // each primary power use: 10 percent less likely',
    '    return 10;',
    '}',
    '',
    'inline int sapHandNoRemovalAtLimit() {',
    '    // at 100 percent subtraction no removal, the host knows',
    '    return 1;',
    '}',
    '',
    'inline int sapHandFingerCombinations() {',
    '    // powers work through extended or curled fingers',
    '    return 1;',
    '}',
    '',
    'inline int sapHandPowerTotal() {',
    '    // 10 of I, 5 of II, 2 each of III-V, 1 of VI',
    '    return 22;',
    '}',
    '',
    'inline int sapHandPowerCount(int i) {',
    '    // the powers per table I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        10, 5, 2, 2, 2, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapHandGodsOnlyAlteration() {',
    '    // only the most powerful of gods can alter the effects',
    '    return 1;',
    '}',
    '',
    'inline int sapHandRecordCombinations() {',
    '    // the note: devise and record the position chart',
    '    return 1;',
    '}',
    '',
]

AUDIT = [
    '    // ---- R284: the III.E Special artifacts',
    '    // explanation prose part 5 ----',
    '    // The Eye of Vecna and The Hand of Vecna,',
    '    // part2 lines 1318-1357 (DMG p.160-161) -',
    '    // the seventh and eighth of the 29 artifact',
    '    // descriptions. One seam restored: the',
    '    // p.160-161 page break splits the severing',
    '    // paragraph between the 1332 tail and',
    '    // the 1337 head.',
    '    {',
    '        int bad = 0;',
    '        // the Eye scalars',
    '        if (rules::sapEyeVecnaPhantomRoams() != 1 ||',
    '            rules::sapEyeDoomSurvivors() != 2 ||',
    '            rules::sapEyeFeralGlow() != 1 ||',
    '            rules::sapEyeAppearsAgate() != 1 ||',
    '            rules::sapEyeGraftIrrevocable() != 1 ||',
    '            rules::sapEyeHostNeutralEvil() != 1 ||',
    '            rules::sapEyeGrantsInfravision() != 1 ||',
    '            rules::sapEyeGrantsUltravision() != 1 ||',
    '            rules::sapEyePowerTotal() != 6 ||',
    '            rules::sapEyePrimaryPowerMalevolent() != 1) ++bad;',
    '        // the Hand scalars',
    '        if (rules::sapHandVecnaLeftHand() != 1 ||',
    '            rules::sapHandMummifiedExtremity() != 1 ||',
    '            rules::sapHandGripStrength() != 18 ||',
    '            rules::sapHandGripStrengthRating() != 0 ||',
    '            rules::sapHandGripHitOrDamageBonus() != 0 ||',
    '            rules::sapHandHostTurnsNeutralEvil() != 1 ||',
    '            rules::sapHandMajorPowerWakesSpirit() != 1 ||',
    '            rules::sapHandPrimaryPowerInstantEvil() != 1 ||',
    '            rules::sapHandSeverBaseChancePct() != 100 ||',
    '            rules::sapHandSeverMajorPenaltyPct() != 1 ||',
    '            rules::sapHandSeverPrimaryPenaltyPct() != 10 ||',
    '            rules::sapHandNoRemovalAtLimit() != 1 ||',
    '            rules::sapHandFingerCombinations() != 1 ||',
    '            rules::sapHandPowerTotal() != 22 ||',
    '            rules::sapHandGodsOnlyAlteration() != 1 ||',
    '            rules::sapHandRecordCombinations() != 1) ++bad;',
    '        // the eye powers per tables I-V',
    '        static const int kEye[5] = {',
    '            2, 2, 0, 1, 1,',
    '        };',
    '        for (int i = 0; i < 5; ++i)',
    '            if (rules::sapEyePowerCount(i) != kEye[i]) ++bad;',
    '        // table III is skipped',
    '        if (rules::sapEyePowerCount(2) != 0) ++bad;',
    '        if (rules::sapEyePowerCount(0) +',
    '            rules::sapEyePowerCount(1) +',
    '            rules::sapEyePowerCount(2) +',
    '            rules::sapEyePowerCount(3) +',
    '            rules::sapEyePowerCount(4) !=',
    '            rules::sapEyePowerTotal()) ++bad;',
    '        // the hand powers per table I-VI',
    '        static const int kHap[6] = {',
    '            10, 5, 2, 2, 2, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapHandPowerCount(i) != kHap[i]) ++bad;',
    '        if (rules::sapHandPowerCount(0) +',
    '            rules::sapHandPowerCount(1) +',
    '            rules::sapHandPowerCount(2) +',
    '            rules::sapHandPowerCount(3) +',
    '            rules::sapHandPowerCount(4) +',
    '            rules::sapHandPowerCount(5) !=',
    '            rules::sapHandPowerTotal()) ++bad;',
    '        // the grip: strength 18, rating 00, no bonuses',
    '        if (rules::sapHandGripStrength() * 100 +',
    '            rules::sapHandGripStrengthRating() != 1800) ++bad;',
    '        // the severance math: a primary power costs',
    '        // ten times a major power',
    '        if (rules::sapHandSeverPrimaryPenaltyPct() !=',
    '            rules::sapHandSeverMajorPenaltyPct() * 10) ++bad;',
    '        // at the limit the subtractions reach the base',
    '        if (rules::sapHandSeverBaseChancePct() !=',
    '            rules::sapHandSeverPrimaryPenaltyPct() * 10) ++bad;',
    '        // both relics turn the host neutral evil',
    '        if (rules::sapEyeHostNeutralEvil() !=',
    '            rules::sapHandHostTurnsNeutralEvil()) ++bad;',
    '        // both relics survived the one doom',
    '        if (rules::sapEyeDoomSurvivors() != 2) ++bad;',
    '        // the cross-pins: the R240 sale table rows',
    '        if (rules::saRowLo(6) != 23 ||',
    '            rules::saRowHi(6) != 24 ||',
    '            rules::saSaleGp(6) != 35000 ||',
    '            rules::saRowLo(7) != 25 ||',
    '            rules::saRowHi(7) != 25 ||',
    '            rules::saSaleGp(7) != 60000) ++bad;',
    '        printf("R284 special artifacts prose part 5 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R284 landed the III.E Special',
    'artifacts explanation prose part 5',
    '(part2 lines 1318-1357; global =',
    '11065 + part2 line),',
    'the Eye of Vecna and the Hand of',
    'Vecna (DMG p.160-161) - the',
    'seventh and eighth of the 29',
    'artifact descriptions. The Eye:',
    'the phantom of the once supreme',
    'lich still roams the Material',
    'Plane; one eye and one hand',
    'survived his doom; the Eye glows',
    'like a feral creature, appears an',
    'agate until placed in an empty eye',
    'socket, then instantly and',
    'irrevocably grafts to the head,',
    'not removed or harmed without',
    'slaying the character; the host',
    'alignment immediately becomes',
    'neutral evil, never to change; the',
    'Eye bestows infravision and',
    'ultravision; powers 2 each of',
    'tables I and II, 1 each of IV and',
    'V (table III skipped); the primary',
    'power use causes a malevolent',
    'effect on the host. The Hand: his',
    'left hand, a mummified extremity,',
    'blackened and shriveled, possibly',
    'from a burned body; pressed',
    'against a forearm stump it grafts',
    'instantly, a functioning member',
    'with 18/00 strength in its grip,',
    'no to hit or damage bonuses; the',
    'host eventually turns neutral',
    'evil; a major power use wakes a',
    'spirit of great evil; a primary',
    'power use makes the host instantly',
    'neutral evil, very evil; the Hand',
    'can be severed before its powers',
    'are used with 100 percent',
    'certainty, each major power use',
    'subtracting 1 percent and each',
    'primary power use making success',
    '10 percent less likely, at 100',
    'percent subtraction no removal is',
    'possible and the character will',
    'know; the powers work through',
    'extended or curled finger',
    'combinations; powers 10 of table',
    'I, 5 of II, 2 each of III, IV and',
    'V, 1 of VI; nothing short of',
    'intervention from the most',
    'powerful of gods can alter the',
    'effects upon the host, and even',
    'the greatest deities are loath to',
    'meddle - the effects are',
    'irrevocable; the note asks the DM',
    'to devise and record the finger',
    'and hand position chart. This',
    'round has one seam restored: the',
    'p.160-161 page break splits the',
    'severing paragraph between the',
    '1332 tail (The Hand can be severed',
    'from) and the 1337 head (the host',
    'at any time before its powers are',
    'used) across the blank pair at',
    '1333-1334, the TREASURE (ARTIFACTS',
    '& RELICS) running head at 1335 and',
    'the 1336 post-head blank. The',
    'upload quirks: the power lines',
    'print the counts as N x table with',
    'the true multiplication sign, 10',
    'of them; the to hit fragment',
    'prints curly double quotes; the',
    'character part and VECNA HAND',
    'apostrophes print as the curly',
    'right single quote; the very evil',
    'and loath dashes print as true',
    'em-dashes; the hand 10 of table I',
    'power line wraps across three',
    'lines; the 2 of IV and 1 of VI',
    'lines drop the space after the',
    'colon - all pinned as plain digits',
    'and words, apostrophe-free here.',
    '28 accessors: 26 scalars + 2',
    'walkers (the eye power walker',
    '2,2,0,1,1 and the hand power',
    'walker 10,5,2,2,2,1), no name',
    'collisions with the miscprose and',
    'specart headers; the audit',
    'cross-pins the R240 sale table',
    'rows - the Eye band 23-24 at',
    '35000, the Hand band 25 at 60000',
    '(census 202). Next: R285 III.E',
    'Special part 6 - the Mystical',
    'Organ of Heward onward in part2',
    'from line 1359 (global 12424; the',
    'Horn of Change, the Invulnerable',
    'Coat of Arnd and the other',
    'descriptions follow; the III.E',
    'Special prose continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 28, 'accessor count is not 28'
assert len(set(defs)) == 28, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 26, 'scalar count is not 26'
walk = [d for d in defs if d not in scal]
assert len(walk) == 2, 'walker count is not 2'
assert set(walk) == {'sapEyePowerCount', 'sapHandPowerCount', }, 'wrong walkers'
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
assert ATEXT.count('R284 special artifacts prose part 5 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 5', 'the Eye of Vecna', 'the Hand of', '1318-1357',
             'census 202', 'R285', 'line 1359', '12424', 'p.160-161',
             'one seam restored'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 5', 'The Eye of Vecna', 'The Hand of Vecna',
             '1318-1357', 'One seam restored'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapEyeVecnaPhantomRoams() {'
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
assert len(alldefs) == 118, 'accessor count is not 118'
assert len(set(alldefs)) == 118, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R284: the III.E Special artifacts'
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
assert s.count('R284 special artifacts prose part 5 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R284 landed the III.E Special'
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

print('R284 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R284 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 5 - the Eye of Vecna and the')
print('Hand of Vecna, part2 lines 1318-1357;')
print('census 202.')
print('commit: R284: the III.E Special artifacts explanation prose part 5 pinned - the Eye of Vecna and the Hand of Vecna in part2 lines 1318-1357 (census 202)')

