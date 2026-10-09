#!/usr/bin/env python3
# R280 splice: the III.E Special artifacts
# explanation prose part 1 pins - the Notes
# Regarding Artifacts and Relics, part2
# lines 1153-1182 (DMG p.158-159), the
# series opener before the 29 artifact
# descriptions that follow. The notes
# pinned: only 1 of each may exist; the
# listing crossed off when placed or found
# (a clue substituted or the result
# ignored); the powers only partially
# described, the DM assigning the major
# powers; lore not found by chance; the
# balance and nemesis-creature caution;
# the 5 tables of powers and side effects
# after the descriptions; the three
# hireling behaviors (evil destroys or
# escapes, neutral dominates, good defects
# with the item); the 10-30 percent
# loyalty drop; destruction by a single
# means; the deface save versus magic at
# minus 5 with failure equal to death; the
# four corruption traits; the permanent
# effects with the deity exception. This
# round has one seam restored: the
# p.158-159 page break splits the opening
# paragraph between the 1153 tail (only 1
# of each may exist. As) and the 1158
# head (each is placed by you) across the
# blank pair at 1154-1155, the TREASURE
# (ARTIFACTS & RELICS) running head at
# 1156 and the 1157 post-head blank. The
# upload quirks this round: five em dashes
# print true; the deface save minus prints
# true as the U+2212 minus sign; the
# employer/ master slash split carries a
# space while giving/forcing prints joined;
# the 10%-30% loyalty band prints with the
# percent-hyphen join - all pinned as plain
# digits and words, apostrophe-free here. 20
# accessors: 20 scalars and no walkers -
# the series opens with notes only, the
# 5 power tables and the destruction means
# table come after the 29 descriptions in
# later rounds; no name collisions with
# the miscprose and specart headers (the
# R240 sa accessors stay in specart.h).
# 4 patches, marker-based idempotence,
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

HDR = [
    '// ====================================================================',
    '// Adnd1 - rules/specartprose.h',
    '// R280: the III.E Special artifacts explanation',
    '// prose part 1 (DMG p.158-159) - the Notes',
    '// Regarding Artifacts and Relics, part2 lines',
    '// 1153-1182 (global = 11065 + part2 line),',
    '// the series opener before the 29 artifact',
    '// descriptions that follow (the Axe of the',
    '// Dwarvish Lords onward lands with part 2).',
    '// The notes pinned here: each artifact or',
    '// relic is a singular thing; only 1 of each',
    '// may exist; the listing is crossed off when',
    '// placed or found, with a clue substituted',
    '// or the result ignored; the powers are only',
    '// partially described with the DM assigning',
    '// the major powers; lore is not found by',
    '// chance; the balance and nemesis-creature',
    '// caution on homebrew items; the 5 tables of',
    '// powers and side effects after the',
    '// descriptions; the three hireling behaviors',
    '// when an item is foisted off (evil destroys',
    '// or escapes, neutral dominates, good',
    '// defects with the item); the 10-30 percent',
    '// loyalty drop when the holder is permanently',
    '// harmed or killed; destruction by a single',
    '// means; the deface save versus magic at',
    '// minus 5 with failure equal to death; the',
    '// four corruption traits; the permanent',
    '// effects with the deity exception. This',
    '// round has one seam restored: the p.158-159',
    '// page break splits the opening paragraph',
    '// between the 1153 tail (only 1 of each may',
    '// exist. As) and the 1158 head (each is',
    '// placed by you) across the blank pair at',
    '// 1154-1155, the TREASURE (ARTIFACTS &',
    '// RELICS) running head at 1156 and the 1157',
    '// post-head blank. The upload quirks this',
    '// round: five em dashes print true; the',
    '// deface save minus prints true as the',
    '// U+2212 minus sign; the employer/ master',
    '// slash split carries a space while',
    '// giving/forcing prints joined; the',
    '// 10%-30% loyalty band prints with the',
    '// percent-hyphen join - all pinned',
    '// as plain digits and words, apostrophe-',
    '// free here. The series opens beside the',
    '// R240 sale table pins (specart.h): the sa',
    '// accessors stay there, the notes land here',
    '// as the sap accessors, no name collisions.',
    '// 20 accessors: 20 scalars and no walkers -',
    '// the series opens with notes only; the 5',
    '// power tables and the destruction means',
    '// table come after the 29 descriptions in',
    '// later rounds. Pure data + helpers,',
    '// header-only (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int sapOneOfEachExists() {',
    '    // only 1 of each may exist - a singular thing',
    '    return 1;',
    '}',
    '',
    'inline int sapListingCrossedWhenPlaced() {',
    '    // draw a line through its listing on the table',
    '    return 1;',
    '}',
    '',
    'inline int sapUnavailableOptionCount() {',
    '    // substitute a clue or simply ignore the result',
    '    return 2;',
    '}',
    '',
    'inline int sapPowersPartiallyDescribed() {',
    '    // their powers are only partially described',
    '    return 1;',
    '}',
    '',
    'inline int sapDmAssignsMajorPowers() {',
    '    // the DM must at least decide the major powers',
    '    return 1;',
    '}',
    '',
    'inline int sapLoreFoundByChance() {',
    '    // discovery of such information is not by chance',
    '    return 0;',
    '}',
    '',
    'inline int sapNemesisSometimesNeeded() {',
    '    // a nemesis creature in some cases, with limits',
    '    return 1;',
    '}',
    '',
    'inline int sapPowerTableCount() {',
    '    // 5 tables list the powers and side effects',
    '    return 5;',
    '}',
    '',
    'inline int sapHenchBehaviorCount() {',
    '    // the item holder will do one of three things',
    '    return 3;',
    '}',
    '',
    'inline int sapBehaviorEvilDestroysOrEscapes() {',
    '    // an evil holder destroys or escapes once known',
    '    return 1;',
    '}',
    '',
    'inline int sapBehaviorNeutralDominates() {',
    '    // a neutral holder dominates the former employer',
    '    return 1;',
    '}',
    '',
    'inline int sapBehaviorGoodDefectsWithItem() {',
    '    // a good holder escapes with the item to a suzerain',
    '    return 1;',
    '}',
    '',
    'inline int sapLoyaltyDropMinPct() {',
    '    // the floor of the loyalty drop band',
    '    return 10;',
    '}',
    '',
    'inline int sapLoyaltyDropMaxPct() {',
    '    // the top of the 10-30 percent loyalty drop',
    '    return 30;',
    '}',
    '',
    'inline int sapDestroyedBySingleMeans() {',
    '    // each can only be destroyed by a single means',
    '    return 1;',
    '}',
    '',
    'inline int sapDefaceSavePenalty() {',
    '    // the deface save versus magic is at minus 5',
    '    return -5;',
    '}',
    '',
    'inline int sapDefaceFailureIsDeath() {',
    '    // a failed deface save equals death',
    '    return 1;',
    '}',
    '',
    'inline int sapCorruptionTraitCount() {',
    '    // reclusive, secretive, arrogant, greedy',
    '    return 4;',
    '}',
    '',
    'inline int sapEffectsArePermanent() {',
    '    // the effects are permanent, even past wishes',
    '    return 1;',
    '}',
    '',
    'inline int sapDeityMayReverseSome() {',
    '    // a creating or controlling deity may reverse some',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
]

AUDIT = [
    '    // ---- R280: the III.E Special artifacts',
    '    // explanation prose part 1 ----',
    '    // The Notes Regarding Artifacts and Relics,',
    '    // part2 lines 1153-1182 (DMG p.158-159) - the',
    '    // series opener before the 29 artifact',
    '    // descriptions. This round has one seam',
    '    // restored: the p.158-159 page break splits the',
    '    // opening paragraph between the 1153 tail and',
    '    // the 1158 head.',
    '    {',
    '        int bad = 0;',
    '        // the notes scalars',
    '        if (rules::sapOneOfEachExists() != 1 ||',
    '            rules::sapListingCrossedWhenPlaced() != 1 ||',
    '            rules::sapUnavailableOptionCount() != 2 ||',
    '            rules::sapPowersPartiallyDescribed() != 1 ||',
    '            rules::sapDmAssignsMajorPowers() != 1 ||',
    '            rules::sapLoreFoundByChance() != 0 ||',
    '            rules::sapNemesisSometimesNeeded() != 1 ||',
    '            rules::sapPowerTableCount() != 5 ||',
    '            rules::sapHenchBehaviorCount() != 3 ||',
    '            rules::sapBehaviorEvilDestroysOrEscapes() != 1 ||',
    '            rules::sapBehaviorNeutralDominates() != 1 ||',
    '            rules::sapBehaviorGoodDefectsWithItem() != 1 ||',
    '            rules::sapLoyaltyDropMinPct() != 10 ||',
    '            rules::sapLoyaltyDropMaxPct() != 30 ||',
    '            rules::sapDestroyedBySingleMeans() != 1 ||',
    '            rules::sapDefaceSavePenalty() != -5 ||',
    '            rules::sapDefaceFailureIsDeath() != 1 ||',
    '            rules::sapCorruptionTraitCount() != 4 ||',
    '            rules::sapEffectsArePermanent() != 1 ||',
    '            rules::sapDeityMayReverseSome() != 1) ++bad;',
    '        // the loyalty drop band is ordered and spans 20',
    '        if (rules::sapLoyaltyDropMinPct() >=',
    '            rules::sapLoyaltyDropMaxPct() ||',
    '            rules::sapLoyaltyDropMaxPct() -',
    '            rules::sapLoyaltyDropMinPct() != 20) ++bad;',
    '        // the three behavior flags sum to the count',
    '        if (rules::sapBehaviorEvilDestroysOrEscapes() +',
    '            rules::sapBehaviorNeutralDominates() +',
    '            rules::sapBehaviorGoodDefectsWithItem() !=',
    '            rules::sapHenchBehaviorCount()) ++bad;',
    '        // the lore is explicitly not found by chance',
    '        if (rules::sapLoreFoundByChance() == 1) ++bad;',
    '        // the deface save penalty is negative five',
    '        if (rules::sapDefaceSavePenalty() >= 0) ++bad;',
    '        // the cross-pin: one of each against the',
    '        // 29 rows of the R240 Special sale table',
    '        if (rules::saRowCount() != 29 ||',
    '            rules::sapOneOfEachExists() *',
    '            rules::saRowCount() != 29) ++bad;',
    '        printf("R280 special artifacts prose part 1 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R280 landed the III.E Special',
    'artifacts and relics explanation',
    'prose part 1 (part2 lines',
    '1153-1182; global = 11065 +',
    'part2 line), the Notes Regarding',
    'Artifacts and Relics (DMG',
    'p.158-159) - the series opener',
    'before the 29 artifact',
    'descriptions that follow. The',
    'notes pinned: each artifact or',
    'relic is a singular thing; only',
    '1 of each may exist; the listing',
    'is crossed off when placed or',
    'found, with a clue substituted',
    'or the result ignored; the powers',
    'are only partially described,',
    'the DM assigning the major',
    'powers; lore is not found by',
    'chance; the balance and the',
    'nemesis-creature caution; the 5',
    'tables of powers and side',
    'effects after the descriptions;',
    'the three hireling behaviors',
    'when an item is foisted off',
    '(evil destroys or escapes,',
    'neutral dominates, good defects',
    'with the item); the 10-30',
    'percent loyalty drop when the',
    'holder is permanently harmed or',
    'killed; destruction by a single',
    'means; the deface save versus',
    'magic at minus 5 with failure',
    'equal to death; the four',
    'corruption traits; the permanent',
    'effects with the deity',
    'exception. This round has',
    'one seam restored: the p.158-159',
    'page break splits the opening',
    'paragraph between the 1153',
    'tail (only 1 of each may exist.',
    'As) and the 1158 head (each is',
    'placed by you) across the blank',
    'pair at 1154-1155, the TREASURE',
    '(ARTIFACTS & RELICS) running',
    'head at 1156 and the 1157',
    'post-head blank. The upload',
    'quirks: five em dashes print',
    'true; the deface save minus',
    'prints true as the U+2212 minus',
    'sign; the employer/ master slash',
    'split carries a space while',
    'giving/forcing prints joined -',
    'all pinned as plain digits and',
    'words, apostrophe-free here.',
    '20 accessors: 20 scalars and',
    'no walkers (the series opens',
    'with notes only; the 5 power',
    'tables and the destruction',
    'means table come after the 29',
    'descriptions in later rounds);',
    'no name collisions with the',
    'miscprose and specart headers,',
    'and the R240 sale table row',
    'count 29 is cross-pinned in',
    'the audit (census 198). Next:',
    'R281 III.E Special part 2 -',
    'the Axe of the Dwarvish Lords',
    'onward in part2 from',
    'line 1184 (global 12249; the',
    'Baba Yaga Hut, the Codex of',
    'the Infinite Planes and the',
    'other descriptions follow;',
    'the III.E Special prose',
    'continue).',
]

# ---- the splice self-asserts ----
HTEXT = NL.join(HDR)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', HTEXT)
assert len(defs) == 20, 'accessor count is not 20'
assert len(set(defs)) == 20, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', HTEXT)
assert len(scal) == 20, 'scalar count is not 20'
assert set(scal) == set(defs), 'this round has no walkers'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(sap[A-Za-z0-9]+)[(]', ATEXT))
assert audited == set(defs), 'audit does not probe every accessor'
for fn in sorted(os.listdir(os.path.join(ROOT, 'rules'))):
    if not fn.endswith('.h') or fn == 'specartprose.h':
        continue
    pt = open(os.path.join(ROOT, 'rules', fn), encoding='utf-8').read()
    for n in defs:
        assert n not in pt, 'name collision with ' + fn
for grp in (HDR, AUDIT, GAP):
    for el in grp:
        if isinstance(el, str):
            assert chr(39) not in el, 'apostrophe in content'
            probe = el.replace(chr(92) + 'n', '')
            assert chr(92) not in probe, 'backslash in content'
            assert NL not in el, 'list element spans lines'
for el in GAP:
    assert len(el) <= 34, 'gap line too long: ' + el
assert ATEXT.count('{') == ATEXT.count('}'), 'audit braces unbalanced'
assert ATEXT.count('(') == ATEXT.count(')'), 'audit parens unbalanced'
assert AUDIT[-1] == '    }', 'audit block does not close'
assert HDR[-1] == '}  // namespace rules', 'header does not close'
assert ATEXT.count('R280 special artifacts prose part 1 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 1', 'one seam', 'III.E Special', 'p.158-159',
             '20 accessors: 20', 'Dwarvish Lords', '12249', 'line 1184',
             'census 198'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
hfrags = ('part 1', 'one seam', 'III.E Special', 'p.158-159',
          '20 accessors: 20')
for frag in hfrags:
    assert any(frag in el for el in HDR), 'header frag not contiguous: ' + frag

# ---- patch 1: create rules/specartprose.h ----
p = 'rules/specartprose.h'
if os.path.exists(os.path.join(ROOT, p)):
    assert rd(p) == HTEXT, 'specartprose.h exists but differs'
    already += 1
else:
    wr(p, HTEXT)
    applied += 1
assert rd(p) == HTEXT, 'patch 1 failed'

# ---- patch 2: the regtest include ----
p = 'regtest.cpp'
s = rd(p)
inc = '#include "rules/specartprose.h"  // R280: the III.E Special artifacts explanation prose part 1 pins'
if inc in s:
    already += 1
else:
    anchor = '#include "rules/miscprose23.h"  // R279: the III.E misc magic explanation prose part 23 pins'
    assert s.count(anchor) == 1, 'include anchor not unique'
    s = s.replace(anchor, anchor + NL + inc, 1)
    wr(p, s)
    applied += 1
assert inc in rd(p), 'patch 2 failed'
assert rd(p).count('#include "rules/specartprose.h"') == 1, 'patch 2 doubled'

# ---- patch 3: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R280: the III.E Special artifacts'
if mark in s:
    already += 1
else:
    anchor = '    // ---- R227: the wis mental save wiring audit ----'
    assert s.count(anchor) == 1, 'audit anchor not unique'
    s = s.replace(anchor, ATEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
assert mark in rd(p), 'patch 3 failed'
assert rd(p).count(mark) == 1, 'patch 3 doubled'

# ---- patch 4: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R280 landed the III.E Special'
if mark in s:
    already += 1
else:
    anchor = 'continue).' + NL + NL + 'Categories:'
    assert s.count(anchor) == 1, 'gap anchor not unique'
    s = s.replace(anchor, 'continue).' + NL + NL + NL.join(GAP) + NL + NL + 'Categories:', 1)
    wr(p, s)
    applied += 1
assert mark in rd(p), 'patch 4 failed'
assert rd(p).count(mark) == 1, 'patch 4 doubled'

print('R280 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R280 note: 4 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 1 - the Notes Regarding Artifacts')
print('and Relics, part2 lines 1153-1182;')
print('census 198.')
print('commit: R280: the III.E Special artifacts explanation prose part 1 pinned - the Notes Regarding Artifacts and Relics in part2 lines 1153-1182 (census 198)')

