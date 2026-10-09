#!/usr/bin/env python3
# R281 splice: the III.E Special artifacts
# explanation prose part 2 pins - the Axe of
# the Dwarvish Lords, the Baba Yaga Hut and
# the Codex of the Infinite Planes, part2
# lines 1184-1235 (DMG p.159-160), the first
# three of the 29 artifact descriptions.
# The Axe: a sword of sharpness blade backed
# by a +3 hammer head, the handle a battle or
# hand axe on command, returns 30 feet to its
# thrower, dwarven abilities doubled for a
# dwarf, life span 50 percent longer, bears a
# curse, lost in the Invoked Devastation;
# powers 2 of table I and 1 each of II-VI.
# The Hut: 15 feet diameter, 10 feet high, two
# fowl legs 12 feet long, infravision 120
# feet, 30 rooms on 3 floors, moves 48 inches
# over swamp, 36 over rough or normal terrain
# and 12 over hills, obeys 1 key-phrase
# commander, comes from 1 league, the legs
# strike as a hill giant 2 per round at AC 2,
# 48 hit points each regenerating 1 per
# round, 5 foot granite walls; powers 4 of
# table I, 2 of II, 1 each of III-VI. The
# Codex: 99 damned pages, 99 percent doom at
# 1 percent cumulative per page, keys to
# instant transference to the planes,
# destroys any character under 11th level on
# touch, 11th or higher save versus magic to
# command; powers 4 each of tables I and II,
# 2 each of III-VI; the perusal note on
# activation. This round has one seam
# restored: the p.159-160 page break splits
# the Codex paragraph between the 1216 tail
# (the work will destroy instantly any) and
# the 1221 head (character under 11th level)
# across the blank pair at 1217-1218, the
# TREASURE (ARTIFACTS & RELICS) running head
# at 1219 and the 1220 post-head blank. The
# upload quirks this round: the power lines
# print the counts as N x table with the true
# multiplication sign, 18 of them; the feet
# primes print as the curly right single
# quote and the inch primes as the curly
# right double quote; the Tzunk fragment
# prints curly quotes; the hit point/ melee
# round slash split carries a space - all
# pinned as plain digits and words,
# apostrophe-free here. 37 accessors: 33
# scalars + 4 walkers (the three power-count
# walkers and the hut move walker), no name
# collisions with the miscprose and specart
# headers. The audit cross-pins the R240
# sale table rows: the Axe band 01 at 55000,
# the Hut band 02 at 90000, the Codex band
# 03-04 at 62500.
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
    '// Adnd1 - rules/specartprose2.h',
    '// R281: the III.E Special artifacts explanation',
    '// prose part 2 (DMG p.159-160) - the Axe of the',
    '// Dwarvish Lords, the Baba Yaga Hut and the Codex',
    '// of the Infinite Planes, part2 lines 1184-1235',
    '// (global = 11065 + part2 line), the first three',
    '// of the 29 artifact descriptions. The Axe pins:',
    '// the blade equals a sword of sharpness; the head',
    '// equals a +3 hammer; the handle extends or',
    '// contracts on command to equal a battle or hand',
    '// axe for throwing; the Axe returns 30 feet to its',
    '// thrower; the possessor has dwarven abilities,',
    '// doubled for a dwarf; the life span is 50 percent',
    '// longer; the Axe supposedly bears a curse and was',
    '// lost in the Invoked Devastation; powers 2 of',
    '// table I and 1 each of tables II through VI. The',
    '// Hut pins: 15 feet diameter, 10 feet high; two',
    '// fowl legs 12 feet long; infravision 120 feet;',
    '// 30 rooms on 3 floors; movement 48 inches over',
    '// swamp, 36 over rough or normal terrain and 12',
    '// over hills; obeys commands from 1 key-phrase',
    '// commander; comes to a call from 1 league; the',
    '// legs strike as a hill giant, 2 attacks per',
    '// round, armor class 2, 48 hit points each,',
    '// regenerating 1 per round; 5 foot granite walls;',
    '// powers 4 of table I, 2 of table II, 1 each of',
    '// III through VI. The Codex pins: 99 damned',
    '// pages; 99 percent certain doom at 1 percent',
    '// cumulative per page; keys to instant',
    '// transference to any plane; destroys any',
    '// character under 11th level on touch; 11th or',
    '// higher save versus magic to command; powers 4',
    '// each of tables I and II, 2 each of III through',
    '// VI; the powers activate per the progress of the',
    '// perusal. This round has one seam restored: the',
    '// p.159-160 page break splits the Codex paragraph',
    '// between the 1216 tail (the work will destroy',
    '// instantly any) and the 1221 head (character',
    '// under 11th level) across the blank pair at',
    '// 1217-1218, the TREASURE (ARTIFACTS & RELICS)',
    '// running head at 1219 and the 1220 post-head',
    '// blank. The upload quirks this round: the power',
    '// lines print the counts as N x table with the',
    '// true multiplication sign, 18 of them; the feet',
    '// primes print as the curly right single quote',
    '// and the inch primes as the curly right double',
    '// quote; the Tzunk fragment prints curly quotes;',
    '// the hit point/ melee round slash split carries',
    '// a space - all pinned as plain digits and words,',
    '// apostrophe-free here. 37 accessors: 33 scalars',
    '// + 4 walkers (the three power-count walkers -',
    '// 2,1,1,1,1,1 for the Axe, 4,2,1,1,1,1 for the',
    '// Hut, 4,4,2,2,2,2 for the Codex - and the hut',
    '// move walker 48, 36, 12), no name collisions',
    '// with the miscprose and specart headers. The',
    '// audit cross-pins the R240 sale table rows: the',
    '// Axe band 01 at 55000, the Hut band 02 at',
    '// 90000, the Codex band 03-04 at 62500. Pure',
    '// data + helpers, header-only (the grenade.h',
    '// pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int sapAxeBladeSharpness() {',
    '    // the blade equals a sword of sharpness',
    '    return 1;',
    '}',
    '',
    'inline int sapAxeHammerBonus() {',
    '    // the head equals a +3 hammer',
    '    return 3;',
    '}',
    '',
    'inline int sapAxeHandleForms() {',
    '    // the handle equals a battle or hand axe',
    '    return 2;',
    '}',
    '',
    'inline int sapAxeReturnFeet() {',
    '    // returns 30 feet to its thrower',
    '    return 30;',
    '}',
    '',
    'inline int sapAxeDwarfAbilityMultiplier() {',
    '    // dwarven abilities doubled for a dwarf',
    '    return 2;',
    '}',
    '',
    'inline int sapAxeLifespanBonusPct() {',
    '    // the life span is 50 percent longer',
    '    return 50;',
    '}',
    '',
    'inline int sapAxeBearsCurse() {',
    '    // the Axe supposedly bears a curse',
    '    return 1;',
    '}',
    '',
    'inline int sapAxeInvokedDevastationLost() {',
    '    // lost in the Invoked Devastation centuries gone',
    '    return 1;',
    '}',
    '',
    'inline int sapAxePowerTotal() {',
    '    // 2 of table I plus 1 each of tables II-VI',
    '    return 7;',
    '}',
    '',
    'inline int sapAxePowerCount(int i) {',
    '    // the powers per table I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        2, 1, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapHutDiameterFeet() {',
    '    // a circular thatched structure of 15 feet',
    '    return 15;',
    '}',
    '',
    'inline int sapHutHeightFeet() {',
    '    // 10 feet high',
    '    return 10;',
    '}',
    '',
    'inline int sapHutLegCount() {',
    '    // two powerful fowl legs',
    '    return 2;',
    '}',
    '',
    'inline int sapHutLegLengthFeet() {',
    '    // the legs are 12 feet long stilts',
    '    return 12;',
    '}',
    '',
    'inline int sapHutInfravisionFeet() {',
    '    // infravisual ability to 120 feet',
    '    return 120;',
    '}',
    '',
    'inline int sapHutRoomCount() {',
    '    // 30 rooms on 3 floors, all furnished',
    '    return 30;',
    '}',
    '',
    'inline int sapHutFloorCount() {',
    '    // the 30 rooms sit on 3 floors',
    '    return 3;',
    '}',
    '',
    'inline int sapHutMoveTerrainCount() {',
    '    // swamp, rough or normal, hills and forests',
    '    return 3;',
    '}',
    '',
    'inline int sapHutMoveInches(int i) {',
    '    // move per terrain; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    static const int t[3] = {',
    '        48, 36, 12,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapHutCommanderCount() {',
    '    // obeys the one first using a key phrase',
    '    return 1;',
    '}',
    '',
    'inline int sapHutCallRangeLeagues() {',
    '    // comes to a call from 1 league away',
    '    return 1;',
    '}',
    '',
    'inline int sapHutLegAttacksPerRound() {',
    '    // the legs deliver blows, 2 attacks per round',
    '    return 2;',
    '}',
    '',
    'inline int sapHutLegArmorClass() {',
    '    // the legs are armor class 2',
    '    return 2;',
    '}',
    '',
    'inline int sapHutLegHpEach() {',
    '    // the legs take 48 hit points damage each',
    '    return 48;',
    '}',
    '',
    'inline int sapHutLegRegenPerRound() {',
    '    // regenerating at 1 hit point per round',
    '    return 1;',
    '}',
    '',
    'inline int sapHutWallGraniteFeet() {',
    '    // the walls equal 5 feet thick granite',
    '    return 5;',
    '}',
    '',
    'inline int sapHutLegsHillGiantBlows() {',
    '    // the leg blows equal those of a hill giant',
    '    return 1;',
    '}',
    '',
    'inline int sapHutPowerTotal() {',
    '    // 4 of I, 2 of II, 1 each of III-VI',
    '    return 10;',
    '}',
    '',
    'inline int sapHutPowerCount(int i) {',
    '    // the powers per table I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        4, 2, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapCodexDamnedPages() {',
    '    // any person reading its 99 damned pages',
    '    return 99;',
    '}',
    '',
    'inline int sapCodexDoomChancePct() {',
    '    // 99 percent certain to meet a terrible fate',
    '    return 99;',
    '}',
    '',
    'inline int sapCodexPerilPerPagePct() {',
    '    // 1 percent cumulative chance per page',
    '    return 1;',
    '}',
    '',
    'inline int sapCodexTouchKillBelowLevel() {',
    '    // destroys any character under 11th level',
    '    return 11;',
    '}',
    '',
    'inline int sapCodexCommandMinLevel() {',
    '    // 11th or higher save versus magic to command',
    '    return 11;',
    '}',
    '',
    'inline int sapCodexPerusalActivation() {',
    '    // powers activate per the progress of perusal',
    '    return 1;',
    '}',
    '',
    'inline int sapCodexPowerTotal() {',
    '    // 4 each of I-II, 2 each of III-VI',
    '    return 16;',
    '}',
    '',
    'inline int sapCodexPowerCount(int i) {',
    '    // the powers per table I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        4, 4, 2, 2, 2, 2,',
    '    };',
    '    return t[i];',
    '}',
    '',
    '}  // namespace rules',
]

AUDIT = [
    '    // ---- R281: the III.E Special artifacts',
    '    // explanation prose part 2 ----',
    '    // The Axe of the Dwarvish Lords, the Baba Yaga',
    '    // Hut and the Codex of the Infinite Planes,',
    '    // part2 lines 1184-1235 (DMG p.159-160) - the',
    '    // first three of the 29 artifact descriptions.',
    '    // One seam restored: the p.159-160 page break',
    '    // splits the Codex paragraph between the 1216',
    '    // tail and the 1221 head.',
    '    {',
    '        int bad = 0;',
    '        // the Axe scalars',
    '        if (rules::sapAxeBladeSharpness() != 1 ||',
    '            rules::sapAxeHammerBonus() != 3 ||',
    '            rules::sapAxeHandleForms() != 2 ||',
    '            rules::sapAxeReturnFeet() != 30 ||',
    '            rules::sapAxeDwarfAbilityMultiplier() != 2 ||',
    '            rules::sapAxeLifespanBonusPct() != 50 ||',
    '            rules::sapAxeBearsCurse() != 1 ||',
    '            rules::sapAxeInvokedDevastationLost() != 1 ||',
    '            rules::sapAxePowerTotal() != 7) ++bad;',
    '        // the Hut scalars',
    '        if (rules::sapHutDiameterFeet() != 15 ||',
    '            rules::sapHutHeightFeet() != 10 ||',
    '            rules::sapHutLegCount() != 2 ||',
    '            rules::sapHutLegLengthFeet() != 12 ||',
    '            rules::sapHutInfravisionFeet() != 120 ||',
    '            rules::sapHutRoomCount() != 30 ||',
    '            rules::sapHutFloorCount() != 3 ||',
    '            rules::sapHutMoveTerrainCount() != 3 ||',
    '            rules::sapHutCommanderCount() != 1 ||',
    '            rules::sapHutCallRangeLeagues() != 1 ||',
    '            rules::sapHutLegAttacksPerRound() != 2 ||',
    '            rules::sapHutLegArmorClass() != 2 ||',
    '            rules::sapHutLegHpEach() != 48 ||',
    '            rules::sapHutLegRegenPerRound() != 1 ||',
    '            rules::sapHutWallGraniteFeet() != 5 ||',
    '            rules::sapHutLegsHillGiantBlows() != 1 ||',
    '            rules::sapHutPowerTotal() != 10) ++bad;',
    '        // the Codex scalars',
    '        if (rules::sapCodexDamnedPages() != 99 ||',
    '            rules::sapCodexDoomChancePct() != 99 ||',
    '            rules::sapCodexPerilPerPagePct() != 1 ||',
    '            rules::sapCodexTouchKillBelowLevel() != 11 ||',
    '            rules::sapCodexCommandMinLevel() != 11 ||',
    '            rules::sapCodexPerusalActivation() != 1 ||',
    '            rules::sapCodexPowerTotal() != 16) ++bad;',
    '        // the Axe powers per table I-VI',
    '        static const int kAxp[6] = {',
    '            2, 1, 1, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapAxePowerCount(i) != kAxp[i]) ++bad;',
    '        if (rules::sapAxePowerCount(0) +',
    '            rules::sapAxePowerCount(1) +',
    '            rules::sapAxePowerCount(2) +',
    '            rules::sapAxePowerCount(3) +',
    '            rules::sapAxePowerCount(4) +',
    '            rules::sapAxePowerCount(5) !=',
    '            rules::sapAxePowerTotal()) ++bad;',
    '        // the Hut powers per table I-VI',
    '        static const int kHup[6] = {',
    '            4, 2, 1, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapHutPowerCount(i) != kHup[i]) ++bad;',
    '        if (rules::sapHutPowerCount(0) +',
    '            rules::sapHutPowerCount(1) +',
    '            rules::sapHutPowerCount(2) +',
    '            rules::sapHutPowerCount(3) +',
    '            rules::sapHutPowerCount(4) +',
    '            rules::sapHutPowerCount(5) !=',
    '            rules::sapHutPowerTotal()) ++bad;',
    '        // the Hut movement over its three terrains',
    '        static const int kHum[3] = {',
    '            48, 36, 12,',
    '        };',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::sapHutMoveInches(i) != kHum[i]) ++bad;',
    '        // the Codex powers per table I-VI',
    '        static const int kCdp[6] = {',
    '            4, 4, 2, 2, 2, 2,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapCodexPowerCount(i) != kCdp[i]) ++bad;',
    '        if (rules::sapCodexPowerCount(0) +',
    '            rules::sapCodexPowerCount(1) +',
    '            rules::sapCodexPowerCount(2) +',
    '            rules::sapCodexPowerCount(3) +',
    '            rules::sapCodexPowerCount(4) +',
    '            rules::sapCodexPowerCount(5) !=',
    '            rules::sapCodexPowerTotal()) ++bad;',
    '        // the Hut legs: two at 48 hit points each',
    '        if (rules::sapHutLegCount() * rules::sapHutLegHpEach()',
    '            != 96) ++bad;',
    '        // the Codex doom: 1 percent per page over 99',
    '        // pages equals the 99 percent chance',
    '        if (rules::sapCodexPerilPerPagePct() *',
    '            rules::sapCodexDamnedPages() !=',
    '            rules::sapCodexDoomChancePct()) ++bad;',
    '        // the Codex level gates meet at the 11th',
    '        if (rules::sapCodexTouchKillBelowLevel() !=',
    '            rules::sapCodexCommandMinLevel()) ++bad;',
    '        // the cross-pins: the R240 sale table rows',
    '        if (rules::saRowLo(0) != 1 ||',
    '            rules::saRowHi(0) != 1 ||',
    '            rules::saRowLo(1) != 2 ||',
    '            rules::saRowHi(1) != 2 ||',
    '            rules::saRowLo(2) != 3 ||',
    '            rules::saRowHi(2) != 4 ||',
    '            rules::saSaleGp(0) != 55000 ||',
    '            rules::saSaleGp(1) != 90000 ||',
    '            rules::saSaleGp(2) != 62500) ++bad;',
    '        printf("R281 special artifacts prose part 2 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R281 landed the III.E Special',
    'artifacts and relics explanation',
    'prose part 2 (part2 lines',
    '1184-1235; global = 11065 +',
    'part2 line), the Axe of the',
    'Dwarvish Lords, the Baba Yaga',
    'Hut and the Codex of the',
    'Infinite Planes (DMG',
    'p.159-160) - the first three of',
    'the 29 artifact descriptions.',
    'The Axe: a sword of sharpness',
    'blade backed by a +3 hammer',
    'head, the handle a battle or',
    'hand axe on command, returns 30',
    'feet to its thrower, dwarven',
    'abilities doubled for a dwarf,',
    'life span 50 percent longer,',
    'bears a curse, lost in the',
    'Invoked Devastation; powers 2',
    'of table I and 1 each of',
    'II-VI. The Hut: 15 feet',
    'diameter, 10 feet high, two',
    'fowl legs 12 feet long,',
    'infravision 120 feet, 30 rooms',
    'on 3 floors, moves 48 inches',
    'over swamp, 36 over rough or',
    'normal terrain and 12 over',
    'hills, obeys 1 key-phrase',
    'commander, comes from 1 league,',
    'the legs strike as a hill',
    'giant 2 per round at AC 2, 48',
    'hp each regenerating 1 per',
    'round, 5 foot granite walls;',
    'powers 4 of table I, 2 of II,',
    '1 each of III-VI. The Codex:',
    '99 damned pages, 99 percent',
    'doom at 1 percent cumulative',
    'per page, keys to instant',
    'transference to the planes,',
    'destroys any character under',
    '11th level on touch, 11th or',
    'higher save versus magic to',
    'command; powers 4 each of',
    'tables I and II, 2 each of',
    'III-VI, and the perusal note',
    'on activation. This round has',
    'one seam restored: the',
    'p.159-160 page break splits the',
    'Codex paragraph between the',
    '1216 tail (the work will',
    'destroy instantly any) and the',
    '1221 head (character under',
    '11th level) across the blank',
    'pair at 1217-1218, the TREASURE',
    '(ARTIFACTS & RELICS) running',
    'head at 1219 and the 1220',
    'post-head blank. The upload',
    'quirks: the power lines print',
    'the counts as N x table with',
    'the true multiplication sign,',
    '18 of them; the feet primes',
    'print as the curly right',
    'single quote and the inch',
    'primes as the curly right',
    'double quote; the Tzunk',
    'fragment prints curly quotes;',
    'the hit point/ melee round',
    'slash split carries a space -',
    'all pinned as plain digits and',
    'words, apostrophe-free here.',
    '37 accessors: 33 scalars + 4',
    'walkers (the three power-count',
    'walkers - 2,1,1,1,1,1 for the',
    'Axe, 4,2,1,1,1,1 for the Hut,',
    '4,4,2,2,2,2 for the Codex - and',
    'the hut move walker 48, 36,',
    '12), no name collisions with',
    'the miscprose and specart',
    'headers; the audit cross-pins',
    'the R240 sale table rows - the',
    'Axe band 01 at 55000, the Hut',
    'band 02 at 90000, the Codex',
    'band 03-04 at 62500 (census 199).',
    'Next: R282 III.E Special',
    'part 3 - the',
    'Crown of Might onward in',
    'part2 from line 1237 (global',
    '12302; the Crystal of the Ebon',
    'Flame, the Cup and Talisman of',
    'Al Akbar and the other',
    'descriptions follow; the III.E',
    'Special prose continue).',
]

# ---- the splice self-asserts ----
HTEXT = NL.join(HDR)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', HTEXT)
assert len(defs) == 37, 'accessor count is not 37'
assert len(set(defs)) == 37, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', HTEXT)
assert len(scal) == 33, 'scalar count is not 33'
walk = [d for d in defs if d not in scal]
assert len(walk) == 4, 'walker count is not 4'
assert set(walk) == {'sapAxePowerCount', 'sapHutPowerCount',
                    'sapHutMoveInches', 'sapCodexPowerCount',
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
assert ATEXT.count('R281 special artifacts prose part 2 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 2', 'one seam', 'III.E Special', 'p.159-160',
             '37 accessors: 33', 'Crown of Might', '12302',
             'line 1237', 'census 199'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
hfrags = ('part 2', 'one seam', 'III.E Special', 'p.159-160',
          '37 accessors: 33')
for frag in hfrags:
    assert any(frag in el for el in HDR), 'header frag not contiguous: ' + frag

# ---- patch 1: create rules/specartprose2.h ----
p = 'rules/specartprose2.h'
if os.path.exists(os.path.join(ROOT, p)):
    assert rd(p) == HTEXT, 'specartprose2.h exists but differs'
    already += 1
else:
    wr(p, HTEXT)
    applied += 1
assert rd(p) == HTEXT, 'patch 1 failed'

# ---- patch 2: the regtest include ----
p = 'regtest.cpp'
s = rd(p)
inc = '#include "rules/specartprose2.h"  // R281: the III.E Special artifacts explanation prose part 2 pins'
if inc in s:
    already += 1
else:
    anchor = '#include "rules/specartprose.h"  // R280: the III.E Special artifacts explanation prose part 1 pins'
    assert s.count(anchor) == 1, 'include anchor not unique'
    s = s.replace(anchor, anchor + NL + inc, 1)
    wr(p, s)
    applied += 1
assert inc in rd(p), 'patch 2 failed'
assert rd(p).count('#include "rules/specartprose2.h"') == 1, 'patch 2 doubled'

# ---- patch 3: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R281: the III.E Special artifacts'
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
mark = 'R281 landed the III.E Special'
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

print('R281 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R281 note: 4 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 2 - the Axe of the Dwarvish Lords,')
print('the Baba Yaga Hut and the Codex of the')
print('Infinite Planes, part2 lines 1184-1235;')
print('census 199.')
print('commit: R281: the III.E Special artifacts explanation prose part 2 pinned - the Axe of the Dwarvish Lords, the Baba Yaga Hut and the Codex of the Infinite Planes in part2 lines 1184-1235 (census 199)')

