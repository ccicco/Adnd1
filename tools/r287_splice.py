#!/usr/bin/env python3
# R287 splice: the III.E Special artifacts
# explanation prose part 8 pins -
# Kuroths Quill, the Mace of Cuthbert
# and the Machine of Lum the Mad,
# part2 lines 1452-1497 (DMG p.163),
# the 15th through the 17th of the 29
# artifact descriptions. The Quill:
# the master thief Kuroth, most
# successful of his profession, owed
# it to a writing instrument of
# unknown antiquity which now bears
# his name; it draws and writes
# infallibly upon command, depicting
# whatever its possessor sees or
# speaks; it can find treasure (as a
# potion of treasure finding) 1 time
# per month; powers 2,0,1,1,0,1
# (total 5). The Mace: the actual
# weapon of the Venerable Saint
# Cuthbert of the Cudgel, used to
# demonstrate the folly of error to
# the unbeliever; holy relics of the
# Saint are encased within; a +5
# bonus for both hitting and damage
# plus disruption effects; wieldable
# only by clerics of 18 strength and
# lawful good alignment; powers
# 3,2,0,0,0,1 (total 6). The Machine:
# perhaps built by gods long
# forgotten, its workmanship unlike
# anything known today; Baron Lum used
# it to build an empire, its later
# fate unknown; 60 levers, 40 dials
# and 20 switches, only about one-half
# of the 120 controls still function;
# delicate, intricate, bulky and very
# heavy at 5,500 pounds, it cannot be
# moved normally and a serious jolt
# destroys 1-4 functions which can
# never be restored; a booth of a
# size for 4 man-sized creatures; you
# must matrix the controls to show
# which perform functions; powers
# 15,15,10,10,15,5 (total 70). No
# seam restored this time - the
# p.162-163 break fell in R286 and
# no page break falls within these 46
# lines. 31 accessors: 28 scalars + 3
# walkers. The audit cross-pins the
# R240 sale rows: the Quill band 34-35
# at 27500, the Mace band 36-37 at
# 35000, the Machine band 38 at 72500.
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
    'inline int sapQuillMasterThiefBest() {',
    '    // the master thief, most successful of his kind',
    '    return 1;',
    '}',
    '',
    'inline int sapQuillUnknownAntiquity() {',
    '    // a writing instrument of unknown antiquity',
    '    return 1;',
    '}',
    '',
    'inline int sapQuillBearsKurothName() {',
    '    // it now bears the name of Kuroth',
    '    return 1;',
    '}',
    '',
    'inline int sapQuillInfallibleScribe() {',
    '    // draws and writes infallibly upon command',
    '    return 1;',
    '}',
    '',
    'inline int sapQuillDepictsSeenSpoken() {',
    '    // depicts what its possessor sees or speaks',
    '    return 1;',
    '}',
    '',
    'inline int sapQuillPotionTreasureFinding() {',
    '    // it finds treasure as the potion does',
    '    return 1;',
    '}',
    '',
    'inline int sapQuillTreasureFindPerMonth() {',
    '    // the treasure finding, times per month',
    '    return 1;',
    '}',
    '',
    'inline int sapQuillPowerTotal() {',
    '    // 2+0+1+1+0+1 - the total power count',
    '    return 5;',
    '}',
    '',
    'inline int sapQuillPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        2, 0, 1, 1, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapMaceSaintCuthbertWeapon() {',
    '    // actually used by the Venerable Saint Cuthbert',
    '    return 1;',
    '}',
    '',
    'inline int sapMaceFollyOfError() {',
    '    // demonstrated the folly of error to the unbeliever',
    '    return 1;',
    '}',
    '',
    'inline int sapMaceRelicsEncased() {',
    '    // holy relics of the Saint encased within',
    '    return 1;',
    '}',
    '',
    'inline int sapMaceHitDamageBonus() {',
    '    // the bonus for both hitting and damage',
    '    return 5;',
    '}',
    '',
    'inline int sapMaceDisruptionEffects() {',
    '    // it also has disruption effects',
    '    return 1;',
    '}',
    '',
    'inline int sapMaceClericStrReq() {',
    '    // wieldable only by clerics of this strength',
    '    return 18;',
    '}',
    '',
    'inline int sapMaceLawfulGoodOnly() {',
    '    // the wielder must be of lawful good alignment',
    '    return 1;',
    '}',
    '',
    'inline int sapMacePowerTotal() {',
    '    // 3+2+0+0+0+1 - the total power count',
    '    return 6;',
    '}',
    '',
    'inline int sapMacePowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 2, 0, 0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapMachineGodsForgotten() {',
    '    // perhaps built by gods long forgotten',
    '    return 1;',
    '}',
    '',
    'inline int sapMachineWorkmanshipUnknown() {',
    '    // workmanship unlike anything known today',
    '    return 1;',
    '}',
    '',
    'inline int sapMachineBaronLumEmpire() {',
    '    // used by Baron Lum to build an empire',
    '    return 1;',
    '}',
    '',
    'inline int sapMachineLeverCount() {',
    '    // the number of levers it has',
    '    return 60;',
    '}',
    '',
    'inline int sapMachineDialCount() {',
    '    // the number of dials it has',
    '    return 40;',
    '}',
    '',
    'inline int sapMachineSwitchCount() {',
    '    // the number of switches it has',
    '    return 20;',
    '}',
    '',
    'inline int sapMachineControlsTotal() {',
    '    // levers + dials + switches',
    '    return 120;',
    '}',
    '',
    'inline int sapMachineHalfFunction() {',
    '    // about one-half of the controls still function',
    '    return 60;',
    '}',
    '',
    'inline int sapMachineWeightLb() {',
    '    // bulky and very heavy, in pounds',
    '    return 5500;',
    '}',
    '',
    'inline int sapMachineJoltDestroyMax() {',
    '    // a serious jolt destroys up to this many',
    '    return 4;',
    '}',
    '',
    'inline int sapMachineBoothCreatures() {',
    '    // the booth fits this many man-sized creatures',
    '    return 4;',
    '}',
    '',
    'inline int sapMachinePowerTotal() {',
    '    // 15+15+10+10+15+5 - the total power count',
    '    return 70;',
    '}',
    '',
    'inline int sapMachinePowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        15, 15, 10, 10, 15, 5,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R287: the III.E Special artifacts',
    '    // explanation prose part 8 ----',
    '    // Kuroths Quill, the Mace of Cuthbert and',
    '    // the Machine of Lum the Mad, part2 lines',
    '    // 1452-1497 (DMG p.163) - the 15th through',
    '    // the 17th of the 29 descriptions.',
    '    // No seam restored this time - the p.162-163',
    '    // break fell in R286 and no page break falls',
    '    // within these 46 lines.',
    '    {',
    '        int bad = 0;',
    '        // the Quill scalars',
    '        if (rules::sapQuillMasterThiefBest() != 1 ||',
    '            rules::sapQuillUnknownAntiquity() != 1 ||',
    '            rules::sapQuillBearsKurothName() != 1 ||',
    '            rules::sapQuillInfallibleScribe() != 1 ||',
    '            rules::sapQuillDepictsSeenSpoken() != 1 ||',
    '            rules::sapQuillPotionTreasureFinding() != 1 ||',
    '            rules::sapQuillTreasureFindPerMonth() != 1 ||',
    '            rules::sapQuillPowerTotal() != 5) ++bad;',
    '        // the Quill powers per table I-VI',
    '        static const int kQrl[6] = {',
    '            2, 0, 1, 1, 0, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapQuillPowerCount(i) != kQrl[i]) ++bad;',
    '        if (rules::sapQuillPowerCount(0) +',
    '            rules::sapQuillPowerCount(1) +',
    '            rules::sapQuillPowerCount(2) +',
    '            rules::sapQuillPowerCount(3) +',
    '            rules::sapQuillPowerCount(4) +',
    '            rules::sapQuillPowerCount(5) !=',
    '            rules::sapQuillPowerTotal()) ++bad;',
    '        // the Mace scalars',
    '        if (rules::sapMaceSaintCuthbertWeapon() != 1 ||',
    '            rules::sapMaceFollyOfError() != 1 ||',
    '            rules::sapMaceRelicsEncased() != 1 ||',
    '            rules::sapMaceHitDamageBonus() != 5 ||',
    '            rules::sapMaceDisruptionEffects() != 1 ||',
    '            rules::sapMaceClericStrReq() != 18 ||',
    '            rules::sapMaceLawfulGoodOnly() != 1 ||',
    '            rules::sapMacePowerTotal() != 6) ++bad;',
    '        // the Mace powers per table I-VI',
    '        static const int kMac[6] = {',
    '            3, 2, 0, 0, 0, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapMacePowerCount(i) != kMac[i]) ++bad;',
    '        if (rules::sapMacePowerCount(0) +',
    '            rules::sapMacePowerCount(1) +',
    '            rules::sapMacePowerCount(2) +',
    '            rules::sapMacePowerCount(3) +',
    '            rules::sapMacePowerCount(4) +',
    '            rules::sapMacePowerCount(5) !=',
    '            rules::sapMacePowerTotal()) ++bad;',
    '        // the Mace bonus agrees with the Quill total',
    '        if (rules::sapMaceHitDamageBonus() !=',
    '            rules::sapQuillPowerTotal()) ++bad;',
    '        // the Machine scalars',
    '        if (rules::sapMachineGodsForgotten() != 1 ||',
    '            rules::sapMachineWorkmanshipUnknown() != 1 ||',
    '            rules::sapMachineBaronLumEmpire() != 1 ||',
    '            rules::sapMachineLeverCount() != 60 ||',
    '            rules::sapMachineDialCount() != 40 ||',
    '            rules::sapMachineSwitchCount() != 20 ||',
    '            rules::sapMachineControlsTotal() != 120 ||',
    '            rules::sapMachineHalfFunction() != 60 ||',
    '            rules::sapMachineWeightLb() != 5500 ||',
    '            rules::sapMachineJoltDestroyMax() != 4 ||',
    '            rules::sapMachineBoothCreatures() != 4 ||',
    '            rules::sapMachinePowerTotal() != 70) ++bad;',
    '        // the Machine controls add up',
    '        if (rules::sapMachineLeverCount() +',
    '            rules::sapMachineDialCount() +',
    '            rules::sapMachineSwitchCount() !=',
    '            rules::sapMachineControlsTotal()) ++bad;',
    '        // one-half of the controls still function',
    '        if (rules::sapMachineHalfFunction() * 2 !=',
    '            rules::sapMachineControlsTotal()) ++bad;',
    '        // the Machine powers per table I-VI',
    '        static const int kMch[6] = {',
    '            15, 15, 10, 10, 15, 5,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapMachinePowerCount(i) != kMch[i]) ++bad;',
    '        if (rules::sapMachinePowerCount(0) +',
    '            rules::sapMachinePowerCount(1) +',
    '            rules::sapMachinePowerCount(2) +',
    '            rules::sapMachinePowerCount(3) +',
    '            rules::sapMachinePowerCount(4) +',
    '            rules::sapMachinePowerCount(5) !=',
    '            rules::sapMachinePowerTotal()) ++bad;',
    '        // the jolt cap agrees with the booth capacity',
    '        if (rules::sapMachineJoltDestroyMax() !=',
    '            rules::sapMachineBoothCreatures()) ++bad;',
    '        // the cross-pins: the R240 sale table rows',
    '        if (rules::saRowLo(14) != 34 ||',
    '            rules::saRowHi(14) != 35 ||',
    '            rules::saSaleGp(14) != 27500 ||',
    '            rules::saRowLo(15) != 36 ||',
    '            rules::saRowHi(15) != 37 ||',
    '            rules::saSaleGp(15) != 35000 ||',
    '            rules::saRowLo(16) != 38 ||',
    '            rules::saRowHi(16) != 38 ||',
    '            rules::saSaleGp(16) != 72500) ++bad;',
    '        printf("R287 special artifacts prose part 8 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R287 landed the III.E Special',
    'artifacts explanation prose part 8',
    '(part2 lines 1452-1497; global =',
    '11065 + part2 line),',
    'Kuroths Quill, the Mace of',
    'Cuthbert and the Machine of Lum',
    'the Mad (DMG p.163), the 15th',
    'through the 17th of the 29',
    'artifact descriptions. The',
    'Quill: the master thief Kuroth',
    'was the most successful of his',
    'profession; a writing',
    'instrument of unknown antiquity',
    'which now bears his name; it',
    'draws and writes infallibly',
    'upon command, depicting',
    'whatever its possessor sees or',
    'speaks; it can find treasure',
    '(as a potion of treasure',
    'finding) 1 time per month;',
    'powers 2 of table I, 1 each of',
    'III, IV and VI, total 5. The',
    'Mace: the weapon actually used',
    'by the Venerable Saint Cuthbert',
    'of the Cudgel when he',
    'demonstrated the folly of error',
    'to the unbeliever; holy relics',
    'of the Saint are encased',
    'within it; +5 bonus for both',
    'hitting and damage plus',
    'disruption effects; only clerics',
    'of 18 strength and lawful good',
    'alignment can wield it and gain',
    'the powers; powers 3 of table I,',
    '2 of II, 1 of VI, total 6. The',
    'Machine: perhaps built by gods',
    'long forgotten, its workmanship',
    'unlike anything known today;',
    'used by Baron Lum to build an',
    'empire, its later fate unknown;',
    '60 levers, 40 dials and 20',
    'switches, only about one-half',
    'of the 120 controls still',
    'function; delicate, intricate,',
    'bulky and very heavy at 5,500',
    'pounds, it cannot be moved',
    'normally and a serious jolt',
    'destroys 1-4 functions which',
    'can never be restored; a booth',
    'of a size for 4 man-sized',
    'creatures (4 x 5 x 7 feet)',
    'stands within; you must matrix',
    'the controls to show which',
    'perform functions; powers 15',
    'each of tables I, II and V, 10',
    'each of III and IV, 5 of VI,',
    'total 70. No seam restored this',
    'time: the p.162-163 break fell',
    'in R286 and no page break falls',
    'within these 46 lines. The',
    'upload quirks: the Kuroths',
    'apostrophe prints as the curly',
    'right single quote; the power',
    'lines print the counts as N x',
    'table with the true',
    'multiplication sign, 13 of',
    'them; the booth dimensions',
    'print 4 x 5 x 7 with curly',
    'feet marks; the 5,500 pounds',
    'prints with a comma - all',
    'pinned as plain digits and',
    'words, apostrophe-free here.',
    '31 accessors: 28 scalars + 3',
    'walkers (the quill power walker',
    '2,0,1,1,0,1, the mace power',
    'walker 3,2,0,0,0,1, the',
    'machine power walker',
    '15,15,10,10,15,5), no name',
    'collisions with the miscprose',
    'and specart headers; the audit',
    'cross-pins the R240 sale table',
    'rows - the Quill band 34-35 at',
    '27500, the Mace band 36-37 at',
    '35000, the Machine band 38 at',
    '72500 (census 205). Next: R288',
    'III.E Special part 9 - the',
    'Mighty Servant of Leuk-O onward',
    'in part2 from line 1498 (global',
    '12563; the Orb of Dragonkind',
    'and the other descriptions',
    'follow; the III.E Special prose',
    'continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 31, 'accessor count is not 31'
assert len(set(defs)) == 31, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 28, 'scalar count is not 28'
walk = [d for d in defs if d not in scal]
assert len(walk) == 3, 'walker count is not 3'
assert set(walk) == {'sapQuillPowerCount', 'sapMacePowerCount',
    'sapMachinePowerCount', }, 'wrong walkers'
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
assert 'sapFlaskHeavyUrn' in s0, 'specartprose2.h missing the R286 accessors'
assert 'sapOrganPipeCount' in s0, 'specartprose2.h missing the R285 accessors'
assert 'sapEyeVecnaPhantomRoams' in s0, 'specartprose2.h missing the R284 accessors'
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
assert ATEXT.count('R287 special artifacts prose part 8 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 8', 'Kuroths Quill',
             'the Machine of Lum', '1452-1497',
             'census 205', 'R288', 'line 1498', '12563',
             'p.163', 'No seam restored',
             'Mighty Servant of Leuk-O'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 8', 'Kuroths Quill, the Mace of Cuthbert and',
             'the Machine of Lum the Mad', '1452-1497',
             'No seam restored'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapQuillMasterThiefBest() {'
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
assert len(alldefs) == 209, 'accessor count is not 209'
assert len(set(alldefs)) == 209, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R287: the III.E Special artifacts'
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
assert s.count('R287 special artifacts prose part 8 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R287 landed the III.E Special'
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

print('R287 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R287 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 8 - Kuroths Quill, the Mace of')
print('Cuthbert and the Machine of Lum the Mad,')
print('part2 lines 1452-1497; census 205.')
print('commit: R287: the III.E Special artifacts explanation prose part 8 pinned - Kuroths Quill, the Mace of Cuthbert and the Machine of Lum the Mad in part2 lines 1452-1497 (census 205)')

