#!/usr/bin/env python3
# R286 splice: the III.E Special artifacts
# explanation prose part 7 pins - the Iron
# Flask of Tuerny the Merciless, the
# Jacinth of Inestimable Beauty and
# Johydees Mask, part2 lines 1405-1451
# (DMG p.162-163), the 12th through the
# 14th of the 29 artifact descriptions.
# The Flask: a small heavy urn with a
# turnip-shaped plug, sigils and runes of
# power; 3 words - opening, command,
# closing and sealing; 5 rumored prisoners
# (greater devil, groaning spirit, major
# demon, night hag, nycadaemon); the
# Servant loosed only for evil deeds,
# killing before returning; powers
# 3,0,1,0,1,1 (total 6). The Jacinth:
# the finest corundum from the mountain
# heart, fashioned by the gods; dozens
# of facets shoot brilliant beams; save
# versus magic within 20 feet or be
# charmed; the Sultan Jehef Pehreen, Ket
# and Keoland trail lost; powers
# 2,2,1,1,1,1 (total 8). The Mask: the
# priestess Johydee tricked the powers
# of evil, overthrew their hold on her
# nation; covers the face, assume any
# human-like likeness; blocks mind
# contact, detection, attack; gaze
# immunity (basilisk, catoblepas,
# medusa); powers 2,1,0,0,0,1 (total 4).
# One seam restored: the p.162-163 break
# between the Mask table and the Kuroth
# Quill opener - nothing severed. 27
# accessors: 24 scalars + 3 walkers. The
# audit cross-pins the R240 sale rows:
# the Flask band 30-31 at 50000, the
# Jacinth band 32 at 100000, the Mask
# band 33 at 40000.
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
    'inline int sapFlaskHeavyUrn() {',
    '    // a small and heavy urn, easily carried',
    '    return 1;',
    '}',
    '',
    'inline int sapFlaskTurnipPlug() {',
    '    // stoppered with a turnip-shaped plug',
    '    return 1;',
    '}',
    '',
    'inline int sapFlaskSigilRunes() {',
    '    // engraved with sigils, glyphs, runes',
    '    return 1;',
    '}',
    '',
    'inline int sapFlaskWordCount() {',
    '    // opening, command, closing and sealing',
    '    return 3;',
    '}',
    '',
    'inline int sapFlaskPrisonerCount() {',
    '    // the 5 rumored prisoners within',
    '    return 5;',
    '}',
    '',
    'inline int sapFlaskServantEvilOnly() {',
    '    // the Servant loosed only for evil deeds',
    '    return 1;',
    '}',
    '',
    'inline int sapFlaskKillBeforeReturn() {',
    '    // it must kill before returning to prison',
    '    return 1;',
    '}',
    '',
    'inline int sapFlaskPowerTotal() {',
    '    // 3+0+1+0+1+1 - the total power count',
    '    return 6;',
    '}',
    '',
    'inline int sapJacinthGodFashioned() {',
    '    // fashioned by the gods themselves',
    '    return 1;',
    '}',
    '',
    'inline int sapJacinthMountainHeart() {',
    '    // the finest corundum from the mountain heart',
    '    return 1;',
    '}',
    '',
    'inline int sapJacinthFacetedBeams() {',
    '    // dozens of facets shoot brilliant beams',
    '    return 1;',
    '}',
    '',
    'inline int sapJacinthCharmRangeFt() {',
    '    // within 20 feet save vs magic or charmed',
    '    return 20;',
    '}',
    '',
    'inline int sapJacinthSultanPossessed() {',
    '    // Sultan Jehef Pehreen possessed it',
    '    return 1;',
    '}',
    '',
    'inline int sapJacinthKeolandTrailLost() {',
    '    // into Ket and Keoland, all trace lost',
    '    return 1;',
    '}',
    '',
    'inline int sapJacinthGraspPowers() {',
    '    // the possessor firmly grasps the gem',
    '    return 1;',
    '}',
    '',
    'inline int sapJacinthPowerTotal() {',
    '    // 2+2+1+1+1+1 - the total power count',
    '    return 8;',
    '}',
    '',
    'inline int sapMaskJohydeeTrickedEvil() {',
    '    // the priestess tricked the powers of evil',
    '    return 1;',
    '}',
    '',
    'inline int sapMaskOverthrewNation() {',
    '    // used to overthrow their hold on her nation',
    '    return 1;',
    '}',
    '',
    'inline int sapMaskCoversFace() {',
    '    // covers the whole face of the wearer',
    '    return 1;',
    '}',
    '',
    'inline int sapMaskAssumeLikeness() {',
    '    // assume the likeness of any human-like creature',
    '    return 1;',
    '}',
    '',
    'inline int sapMaskBlocksMindContact() {',
    '    // blocks all mind contact, detection, attack',
    '    return 1;',
    '}',
    '',
    'inline int sapMaskGazeImmunity() {',
    '    // total immunity to all gaze attacks',
    '    return 1;',
    '}',
    '',
    'inline int sapMaskGazeCreatureCount() {',
    '    // basilisk, catoblepas and medusa',
    '    return 3;',
    '}',
    '',
    'inline int sapMaskPowerTotal() {',
    '    // 2+1+0+0+0+1 - the total power count',
    '    return 4;',
    '}',
    '',
    'inline int sapFlaskPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 0, 1, 0, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapJacinthPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        2, 2, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapMaskPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        2, 1, 0, 0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R286: the III.E Special artifacts',
    '    // explanation prose part 7 ----',
    '    // The Iron Flask of Tuerny,',
    '    // The Jacinth of Inestimable Beauty',
    '    // and The Johydees Mask, part2',
    '    // lines 1405-1451 (DMG p.162-163)',
    '    // - the 12th through the 14th of',
    '    // the 29 descriptions.',
    '    // One seam restored: the p.162-163',
    '    // page break falls between the Mask',
    '    // power table and the Kuroth Quill',
    '    // opener across the blank pair at',
    '    // 1448-1449, the running head at',
    '    // 1450 and the 1451 post-head',
    '    // blank - nothing severed this',
    '    // time.',
    '    {',
    '        int bad = 0;',
    '        // the Flask scalars',
    '        if (rules::sapFlaskHeavyUrn() != 1 ||',
    '            rules::sapFlaskTurnipPlug() != 1 ||',
    '            rules::sapFlaskSigilRunes() != 1 ||',
    '            rules::sapFlaskWordCount() != 3) ++bad;',
    '        if (rules::sapFlaskPrisonerCount() != 5 ||',
    '            rules::sapFlaskServantEvilOnly() != 1 ||',
    '            rules::sapFlaskKillBeforeReturn() != 1 ||',
    '            rules::sapFlaskPowerTotal() != 6) ++bad;',
    '        // the Flask powers per table I-VI',
    '        static const int kFla[6] = {',
    '            3, 0, 1, 0, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapFlaskPowerCount(i) != kFla[i]) ++bad;',
    '        if (rules::sapFlaskPowerCount(0) +',
    '            rules::sapFlaskPowerCount(1) +',
    '            rules::sapFlaskPowerCount(2) +',
    '            rules::sapFlaskPowerCount(3) +',
    '            rules::sapFlaskPowerCount(4) +',
    '            rules::sapFlaskPowerCount(5) !=',
    '            rules::sapFlaskPowerTotal()) ++bad;',
    '        // the 3 words: 2 fewer than the 5 prisoners',
    '        if (rules::sapFlaskPrisonerCount() -',
    '            rules::sapFlaskWordCount() != 2) ++bad;',
    '        // the Jacinth scalars',
    '        if (rules::sapJacinthGodFashioned() != 1 ||',
    '            rules::sapJacinthMountainHeart() != 1 ||',
    '            rules::sapJacinthFacetedBeams() != 1 ||',
    '            rules::sapJacinthCharmRangeFt() != 20 ||',
    '            rules::sapJacinthSultanPossessed() != 1 ||',
    '            rules::sapJacinthKeolandTrailLost() != 1 ||',
    '            rules::sapJacinthGraspPowers() != 1 ||',
    '            rules::sapJacinthPowerTotal() != 8) ++bad;',
    '        // the Jacinth powers per table I-VI',
    '        static const int kJac[6] = {',
    '            2, 2, 1, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapJacinthPowerCount(i) != kJac[i]) ++bad;',
    '        if (rules::sapJacinthPowerCount(0) +',
    '            rules::sapJacinthPowerCount(1) +',
    '            rules::sapJacinthPowerCount(2) +',
    '            rules::sapJacinthPowerCount(3) +',
    '            rules::sapJacinthPowerCount(4) +',
    '            rules::sapJacinthPowerCount(5) !=',
    '            rules::sapJacinthPowerTotal()) ++bad;',
    '        // the Mask scalars',
    '        if (rules::sapMaskJohydeeTrickedEvil() != 1 ||',
    '            rules::sapMaskOverthrewNation() != 1 ||',
    '            rules::sapMaskCoversFace() != 1 ||',
    '            rules::sapMaskAssumeLikeness() != 1 ||',
    '            rules::sapMaskBlocksMindContact() != 1 ||',
    '            rules::sapMaskGazeImmunity() != 1 ||',
    '            rules::sapMaskGazeCreatureCount() != 3 ||',
    '            rules::sapMaskPowerTotal() != 4) ++bad;',
    '        // the Mask powers per table I-VI',
    '        static const int kMsk[6] = {',
    '            2, 1, 0, 0, 0, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapMaskPowerCount(i) != kMsk[i]) ++bad;',
    '        if (rules::sapMaskPowerCount(0) +',
    '            rules::sapMaskPowerCount(1) +',
    '            rules::sapMaskPowerCount(2) +',
    '            rules::sapMaskPowerCount(3) +',
    '            rules::sapMaskPowerCount(4) +',
    '            rules::sapMaskPowerCount(5) !=',
    '            rules::sapMaskPowerTotal()) ++bad;',
    '        // the gaze trio and the Flask words agree',
    '        if (rules::sapMaskGazeCreatureCount() !=',
    '            rules::sapFlaskWordCount()) ++bad;',
    '        // the cross-pins: the R240 sale table rows',
    '        if (rules::saRowLo(11) != 30 ||',
    '            rules::saRowHi(11) != 31 ||',
    '            rules::saSaleGp(11) != 50000 ||',
    '            rules::saRowLo(12) != 32 ||',
    '            rules::saRowHi(12) != 32 ||',
    '            rules::saSaleGp(12) != 100000 ||',
    '            rules::saRowLo(13) != 33 ||',
    '            rules::saRowHi(13) != 33 ||',
    '            rules::saSaleGp(13) != 40000) ++bad;',
    '        printf("R286 special artifacts prose part 7 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R286 landed the III.E Special',
    'artifacts explanation prose part 7',
    '(part2 lines 1405-1451; global =',
    '11065 + part2 line),',
    'the Iron Flask of Tuerny the',
    'Merciless,',
    'the Jacinth of Inestimable Beauty',
    'and Johydees Mask (DMG p.162-163),',
    'the 12th through the 14th of the',
    '29 artifact descriptions. The',
    'Flask: a small and heavy urn,',
    'easily carried in a pack or by',
    'hand; stoppered with a',
    'turnip-shaped plug, engraved and',
    'embossed with sigils, glyphs and',
    'runes of power to contain the',
    'spirit within; the possessor need',
    'but know 3 words - opening,',
    'command, closing and sealing;',
    'rumored to imprison one of 5: a',
    'greater devil, a groaning spirit,',
    'a major demon, a night hag, a',
    'nycadaemon; the Servant loosed',
    'only to perform evil deeds, it',
    'must always kill before it can be',
    'commanded to return to its prison;',
    'powers 3 of table I, 1 each of',
    'III, V and VI, total 6. The',
    'Jacinth: the finest corundum gem',
    'from the heart of the largest',
    'mountain, fashioned by the gods',
    'themselves; a huge, priceless',
    'fiery orange jewel, exquisitely',
    'cut in dozens of facets which',
    'shoot forth brilliant beams; all',
    'who see it within 20 feet or less',
    'must save versus magic or be',
    'charmed; possessed by the Sultan',
    'Jehef Pehreen for a time, then',
    'passed into the Land of Ket and',
    'southward into Keoland, where all',
    'trace disappeared; the possessor',
    'firmly grasping the lustrous',
    'orange gem gains powers 2 each of',
    'tables I and II, 1 each of III',
    'through VI, total 8. The Mask: the',
    'high priestess Johydee tricked the',
    'powers of evil into making it,',
    'then wisely used it to overthrow',
    'their hold upon her nation;',
    'completely covers the face of the',
    'wearer and lets him or her assume',
    'the likeness of any human or',
    'human-like creature; prevents all',
    'forms of mind contact, detection',
    'or attack; total immunity to all',
    'gaze attacks (basilisk,',
    'catoblepas, medusa, etc.); powers',
    '2 of table I, 1 of II, 1 of VI,',
    'total 4. One seam restored: the',
    'p.162-163 page break falls between',
    'the Mask power table and the',
    'Kuroth Quill opener across the',
    'blank pair at 1448-1449, the',
    'TREASURE (ARTIFACTS & RELICS)',
    'running head at 1450 and the 1451',
    'post-head blank - nothing severed',
    'this time. The upload quirks: the',
    'power lines print the counts as N',
    'x table with the true',
    'multiplication sign, 10 of them;',
    'the prisoner names print one per',
    'line, 5 of them; the Pehreen,',
    'Johydees and Tuernys apostrophes',
    'print as the curly right single',
    'quote; the 20 feet range prints',
    'curly feet marks - all pinned as',
    'plain digits and words,',
    'apostrophe-free here. 27',
    'accessors: 24 scalars + 3 walkers',
    '(the flask power walker',
    '3,0,1,0,1,1, the jacinth power',
    'walker 2,2,1,1,1,1, the mask power',
    'walker 2,1,0,0,0,1), no name',
    'collisions with the miscprose and',
    'specart headers; the audit',
    'cross-pins the R240 sale table',
    'rows - the Flask band 30-31 at',
    '50000, the Jacinth band 32 at',
    '100000, the Mask band 33 at 40000',
    '(census 204). Next: R287 III.E',
    'Special part 8 - Kuroths Quill',
    'onward in part2 from line 1452',
    '(global 12517; the Mace of',
    'Cuthbert, the Machine of Lum the',
    'Mad and the other descriptions',
    'follow; the III.E Special prose',
    'continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 27, 'accessor count is not 27'
assert len(set(defs)) == 27, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 24, 'scalar count is not 24'
walk = [d for d in defs if d not in scal]
assert len(walk) == 3, 'walker count is not 3'
assert set(walk) == {'sapFlaskPowerCount', 'sapJacinthPowerCount',
    'sapMaskPowerCount', }, 'wrong walkers'
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
assert 'sapOrganPipeCount' in s0, 'specartprose2.h missing the R285 accessors'
assert 'sapEyeVecnaPhantomRoams' in s0, 'specartprose2.h missing the R284 accessors'
assert 'sapCrystalOriginUnknown' in s0, 'specartprose2.h missing the R283 accessors'
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
assert ATEXT.count('R286 special artifacts prose part 7 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 7', 'the Iron Flask of Tuerny',
             'the Jacinth of Inestimable Beauty', 'Johydees Mask',
             '1405-1451', 'census 204', 'R287', 'line 1452', '12517',
             'p.162-163', 'One seam restored'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 7', 'The Iron Flask of Tuerny',
             'The Jacinth of Inestimable Beauty',
             'The Johydees Mask',
             '1405-1451', 'One seam restored'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapFlaskHeavyUrn() {'
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
assert len(alldefs) == 178, 'accessor count is not 178'
assert len(set(alldefs)) == 178, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R286: the III.E Special artifacts'
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
assert s.count('R286 special artifacts prose part 7 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R286 landed the III.E Special'
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

print('R286 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R286 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 7 - the Iron Flask of Tuerny')
print('the Merciless, the Jacinth of')
print('Inestimable Beauty and Johydees Mask,')
print('part2 lines 1405-1451; census 204.')
print('commit: R286: the III.E Special artifacts explanation prose part 7 pinned - the Iron Flask of Tuerny the Merciless, the Jacinth of Inestimable Beauty and Johydees Mask in part2 lines 1405-1451 (census 204)')

