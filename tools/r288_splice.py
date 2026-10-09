#!/usr/bin/env python3
# R288 splice: the III.E Special artifacts
# explanation prose part 9 pin - the
# Mighty Servant of Leuk-O, part2 lines
# 1498-1517 (DMG p.163), the 18th of the
# 29 artifact descriptions. The Servant:
# of the same manufacture as the Machine
# of Lum; a towering automaton of
# crystal, unknown metals and strange
# fibrous material, over 9 feet tall, 6
# feet deep, some 4 and one-half feet
# wide; 2 man-sized creatures fit inside,
# 4 to 5 others may sit outside; the
# possessor knowing the proper command
# phrases gets 3 uses - a
# transportation mode, a magical attack
# device, a fighting machine; armor
# class minus 1, 60 hit points, all
# weapons do only 50 percent of normal
# damage, regeneration 2 points per
# round, magic resistance 100 percent,
# acid cold fire heat vacuum and water
# (6 elements) have no effect,
# electrical and lightning only 20
# percent; maximum speed 3 inches; 12
# hours of operation then 1 hour of
# rest; intelligent viewers within 12
# inches save versus magic at +2 or
# flee in panic; 1 attack per round, a
# base 15 percent chance to hit
# regardless of armor class, reduced 2
# and one-half percent per dexterity
# point above 14; a hit causes 10-100
# hit points; powers 6,6,1,2,0,2
# (total 17); effects are triggered by
# major power use; it obeys the humans
# who learn its secrets of automation
# and control. No seam this time - no
# page break falls within these 20
# lines. 29 accessors: 28 scalars + 1
# walker. The audit cross-pins the
# R240 sale row: the Servant band 39-40
# at 185000.
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
    'inline int sapServantLumSameMake() {',
    '    // the same manufacture as the Machine of Lum',
    '    return 1;',
    '}',
    '',
    'inline int sapServantAutomatonHeightFt() {',
    '    // it stands over this many feet tall',
    '    return 9;',
    '}',
    '',
    'inline int sapServantDepthFt() {',
    '    // it is this many feet deep',
    '    return 6;',
    '}',
    '',
    'inline int sapServantWidthFt() {',
    '    // some 4 and one-half feet wide',
    '    return 4;',
    '}',
    '',
    'inline int sapServantInsideRiders() {',
    '    // the compartment holds this many man-sized',
    '    return 2;',
    '}',
    '',
    'inline int sapServantOutsideSittersMin() {',
    '    // 4 to 5 others may sit outside',
    '    return 4;',
    '}',
    '',
    'inline int sapServantCommandPhrases() {',
    '    // the possessor must know the proper phrases',
    '    return 1;',
    '}',
    '',
    'inline int sapServantUseCount() {',
    '    // transportation, attack device, fighting machine',
    '    return 3;',
    '}',
    '',
    'inline int sapServantArmorClass() {',
    '    // armor class minus 1 (a true-minus quirk)',
    '    return 1;',
    '}',
    '',
    'inline int sapServantHitPoints() {',
    '    // it withstands this many hit points',
    '    return 60;',
    '}',
    '',
    'inline int sapServantWeaponDamagePct() {',
    '    // weapons do only this percent of normal',
    '    return 50;',
    '}',
    '',
    'inline int sapServantRegenPerRound() {',
    '    // it self-repairs this many points per round',
    '    return 2;',
    '}',
    '',
    'inline int sapServantMagicResistPct() {',
    '    // its magic resistance, in percent',
    '    return 100;',
    '}',
    '',
    'inline int sapServantElementImmuneCount() {',
    '    // acid cold fire heat vacuum water - no effect',
    '    return 6;',
    '}',
    '',
    'inline int sapServantElectricalDamagePct() {',
    '    // electrical attacks do only this percent',
    '    return 20;',
    '}',
    '',
    'inline int sapServantSpeedInches() {',
    '    // its maximum speed, in inches',
    '    return 3;',
    '}',
    '',
    'inline int sapServantOperationHours() {',
    '    // hours of operation before it must rest',
    '    return 12;',
    '}',
    '',
    'inline int sapServantRestHours() {',
    '    // it must rest this many hours',
    '    return 1;',
    '}',
    '',
    'inline int sapServantPanicRangeInches() {',
    '    // the intelligent-viewer panic range, in inches',
    '    return 12;',
    '}',
    '',
    'inline int sapServantPanicSaveBonus() {',
    '    // the bonus on the panic save die roll',
    '    return 2;',
    '}',
    '',
    'inline int sapServantAttacksPerRound() {',
    '    // it attacks but this many times per round',
    '    return 1;',
    '}',
    '',
    'inline int sapServantBaseHitPct() {',
    '    // the base chance to hit, in percent',
    '    return 15;',
    '}',
    '',
    'inline int sapServantDexReduceFloor() {',
    '    // per point of dexterity above this',
    '    return 14;',
    '}',
    '',
    'inline int sapServantDexReducePct() {',
    '    // 2 and one-half percent per point above',
    '    return 2;',
    '}',
    '',
    'inline int sapServantDamageLowHp() {',
    '    // the low end of a hit, in hit points',
    '    return 10;',
    '}',
    '',
    'inline int sapServantDamageHighHp() {',
    '    // the high end of a hit, in hit points',
    '    return 100;',
    '}',
    '',
    'inline int sapServantObeysSecretLearners() {',
    '    // it obeys those who learn its secrets',
    '    return 1;',
    '}',
    '',
    'inline int sapServantPowerTotal() {',
    '    // 6+6+1+2+0+2 - the total power count',
    '    return 17;',
    '}',
    '',
    'inline int sapServantPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        6, 6, 1, 2, 0, 2,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R288: the III.E Special artifacts',
    '    // explanation prose part 9 ----',
    '    // The Mighty Servant of Leuk-O,',
    '    // part2 lines 1498-1517 (DMG p.163)',
    '    // - the 18th of the 29 descriptions.',
    '    // No seam restored this time - no page',
    '    // break falls within these 20 lines.',
    '    {',
    '        int bad = 0;',
    '        // the Servant make and frame scalars',
    '        if (rules::sapServantLumSameMake() != 1 ||',
    '            rules::sapServantAutomatonHeightFt() != 9 ||',
    '            rules::sapServantDepthFt() != 6 ||',
    '            rules::sapServantWidthFt() != 4 ||',
    '            rules::sapServantInsideRiders() != 2 ||',
    '            rules::sapServantOutsideSittersMin() != 4 ||',
    '            rules::sapServantCommandPhrases() != 1) ++bad;',
    '        // the Servant command and combat scalars',
    '        if (rules::sapServantUseCount() != 3 ||',
    '            rules::sapServantArmorClass() != 1 ||',
    '            rules::sapServantHitPoints() != 60 ||',
    '            rules::sapServantWeaponDamagePct() != 50 ||',
    '            rules::sapServantRegenPerRound() != 2 ||',
    '            rules::sapServantMagicResistPct() != 100 ||',
    '            rules::sapServantElementImmuneCount() != 6 ||',
    '            rules::sapServantElectricalDamagePct() != 20) ++bad;',
    '        // the Servant movement and panic scalars',
    '        if (rules::sapServantSpeedInches() != 3 ||',
    '            rules::sapServantOperationHours() != 12 ||',
    '            rules::sapServantRestHours() != 1 ||',
    '            rules::sapServantPanicRangeInches() != 12 ||',
    '            rules::sapServantPanicSaveBonus() != 2 ||',
    '            rules::sapServantAttacksPerRound() != 1 ||',
    '            rules::sapServantBaseHitPct() != 15) ++bad;',
    '        // the Servant to-hit and damage scalars',
    '        if (rules::sapServantDexReduceFloor() != 14 ||',
    '            rules::sapServantDexReducePct() != 2 ||',
    '            rules::sapServantDamageLowHp() != 10 ||',
    '            rules::sapServantDamageHighHp() != 100 ||',
    '            rules::sapServantObeysSecretLearners() != 1 ||',
    '            rules::sapServantPowerTotal() != 17) ++bad;',
    '        // the Servant powers per table I-VI',
    '        static const int kSrv[6] = {',
    '            6, 6, 1, 2, 0, 2,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapServantPowerCount(i) != kSrv[i]) ++bad;',
    '        if (rules::sapServantPowerCount(0) +',
    '            rules::sapServantPowerCount(1) +',
    '            rules::sapServantPowerCount(2) +',
    '            rules::sapServantPowerCount(3) +',
    '            rules::sapServantPowerCount(4) +',
    '            rules::sapServantPowerCount(5) !=',
    '            rules::sapServantPowerTotal()) ++bad;',
    '        // the frame sums: the width plus the',
    '        // inside riders equals the depth',
    '        if (rules::sapServantWidthFt() +',
    '            rules::sapServantInsideRiders() !=',
    '            rules::sapServantDepthFt()) ++bad;',
    '        // the damage high agrees with the MR percent',
    '        if (rules::sapServantDamageHighHp() !=',
    '            rules::sapServantMagicResistPct()) ++bad;',
    '        // the panic range agrees with the work span',
    '        if (rules::sapServantPanicRangeInches() !=',
    '            rules::sapServantOperationHours()) ++bad;',
    '        // the 6 immunities agree with table I',
    '        if (rules::sapServantElementImmuneCount() !=',
    '            rules::sapServantPowerCount(0)) ++bad;',
    '        // the cross-pin: the R240 sale table row',
    '        if (rules::saRowLo(17) != 39 ||',
    '            rules::saRowHi(17) != 40 ||',
    '            rules::saSaleGp(17) != 185000) ++bad;',
    '        printf("R288 special artifacts prose part 9 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R288 landed the III.E Special',
    'artifacts explanation prose part 9',
    '(part2 lines 1498-1517; global =',
    '11065 + part2 line),',
    'the Mighty Servant of Leuk-O',
    '(DMG p.163), the 18th of the 29',
    'artifact descriptions. The',
    'Servant: of the same manufacture',
    'as the Machine of Lum; a towering',
    'automaton of crystal, unknown',
    'metals and strange fibrous',
    'material, over 9 feet tall, 6 feet',
    'deep and some 4 and one-half feet',
    'wide; a compartment inside for 2',
    'man-sized creatures and space for',
    '4 to 5 others to sit outside; the',
    'possessor who knows the command',
    'phrases can use it as a',
    'transportation mode, a magical',
    'attack device or a fighting',
    'machine - 3 uses; armor class',
    'minus 1, it withstands 60 hit',
    'points; all weapons do only 50',
    'percent of normal damage (round',
    'down); it regenerates 2 points',
    'per round; magic resistance 100',
    'percent; acid, cold, fire, heat,',
    'vacuum and water have no effect',
    '- 6 elements; electrical and',
    'lightning attacks cause only 20',
    'percent normal damage (round',
    'down), even when the resistance',
    'check fails; maximum speed 3',
    'inches; after each 12 hours of',
    'operation it must rest 1 hour;',
    'any intelligent viewer within 12',
    'inches must save versus magic',
    'with +2 on the die or flee in',
    'panic; it attacks 1 time per',
    'round with a base 15 percent',
    'chance to hit regardless of armor',
    'class; opponents with intelligence',
    'and dexterity of 15 or better',
    'reduce the base by 2 and',
    'one-half percent per point of',
    'dexterity above 14; a hit causes',
    '10-100 hit points of damage;',
    'powers 6 each of tables I and II,',
    '1 of III, 2 each of IV and VI,',
    'total 17; effects are triggered',
    'by major power use; it obeys the',
    'humans who learn its secrets of',
    'automation and control.',
    'No seam restored this time - no',
    'page break falls within these',
    '20 lines. The upload quirks: the',
    'height, depth and width print',
    'curly feet marks and the width',
    'prints the one-half fraction',
    'glyph; the armor class prints a',
    'true minus sign before the 1; the',
    'speed and panic range print the',
    'double-prime inches marks (3 and',
    '12); the dexterity reduction',
    'prints the one-half glyph again',
    '(2 and one-half percent); the',
    'power lines print the counts as N',
    'x table with the true',
    'multiplication sign, 5 of them,',
    'and the typeset wraps three of',
    'them (III, IV and VI) onto a',
    'single line - all pinned as plain',
    'digits and words, apostrophe-free',
    'here. 29 accessors: 28 scalars +',
    '1 walker (the servant power',
    'walker 6,6,1,2,0,2), no name',
    'collisions with the miscprose and',
    'specart headers; the audit',
    'cross-pins the R240 sale table',
    'row - the Servant band 39-40 at',
    '185000 (census 206). Next: R289',
    'III.E Special part 10 - the',
    'Orb of Dragonkind onward in',
    'part2 from line 1518 (global',
    '12583; the 8 jade globes, the',
    'notes and the other',
    'descriptions follow; the III.E',
    'Special prose continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 29, 'accessor count is not 29'
assert len(set(defs)) == 29, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 28, 'scalar count is not 28'
walk = [d for d in defs if d not in scal]
assert len(walk) == 1, 'walker count is not 1'
assert set(walk) == {'sapServantPowerCount', }, 'wrong walkers'
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
assert 'sapQuillMasterThiefBest' in s0, 'specartprose2.h missing the R287 accessors'
assert 'sapFlaskHeavyUrn' in s0, 'specartprose2.h missing the R286 accessors'
assert 'sapOrganPipeCount' in s0, 'specartprose2.h missing the R285 accessors'
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
assert ATEXT.count('R288 special artifacts prose part 9 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 9', 'the Mighty Servant of Leuk-O',
             '1498-1517', 'census 206', 'R289', 'line 1518',
             '12583', 'p.163', 'No seam restored',
             'Orb of Dragonkind'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 9', 'The Mighty Servant of Leuk-O',
             '1498-1517', 'No seam restored'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapServantLumSameMake() {'
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
assert len(alldefs) == 238, 'accessor count is not 238'
assert len(set(alldefs)) == 238, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R288: the III.E Special artifacts'
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
assert s.count('R288 special artifacts prose part 9 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R288 landed the III.E Special'
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

print('R288 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R288 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 9 - the Mighty Servant of Leuk-O,')
print('part2 lines 1498-1517; census 206.')
print('commit: R288: the III.E Special artifacts explanation prose part 9 pinned - the Mighty Servant of Leuk-O in part2 lines 1498-1517 (census 206)')

