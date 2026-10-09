#!/usr/bin/env python3
# R276 splice: the III.E misc magic explanation prose
# part 20 pins - the Phylactery of Faithfulness, the
# Phylactery of Long Years, the Phylactery of Monstrous
# Attention, the Pipes of the Sewers, the Portable Hole
# and Quaals Feather Token, part2 lines 971-998 (DMG
# p.153-154), pinning the kMisc4 rows 30-35 of the
# 36-row III.E.4 table - the slice that closes the
# table. This round has no seam: the slice starts at
# the Faithfulness paragraph head (971 after the 970
# blank) and ends at the token tail (998 before the 999
# blank), every paragraph complete. The upload quirks
# this round: the OCR splits three hyphenated words
# with a space (one- quarter, re- establish and non-
# dimensional); the curly apostrophes print in deitys,
# pipers, tokens and the Quaals item name (the engine
# spells the item with the straight mark); curly quotes
# wrap picked up, hole and to hit; the foot and inch
# primes print as curly marks; two multiplication signs
# ride the rat dice; the token rows separate with
# em-dashes - all pinned as plain digits and words,
# apostrophe-free here. The part1 quirks: the Monstrous
# Attention row splits across two table lines (part1
# 9851-9852, with --- in the x.p. column); the Feather
# Token row prints both dual value pairs in the x.p.
# column. The Phylactery of Faithfulness carries no
# accessor (numberless prose, like the Periapt of
# Health in part 19). 4 patches, marker-based
# idempotence, assert after every patch. ZERO
# apostrophes and ZERO literal backslashes in the
# content below (the printf newline is built via
# BS = chr(92)).

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
    '// Adnd1 - rules/miscprose20.h',
    '// R276: the III.E misc magic explanation prose part 20',
    '// (DMG p.153-154) - the Phylactery of Faithfulness, the',
    '// Phylactery of Long Years, the Phylactery of Monstrous',
    '// Attention, the Pipes of the Sewers, the Portable Hole',
    '// and Quaals Feather Token, part2 lines 971-998 (global',
    '// = 11065 + part2 line), pinning the kMisc4 rows 30-35 of',
    '// the 36-row III.E.4 table - the slice that closes the',
    '// table. This round has no seam: the slice starts at the',
    '// Faithfulness paragraph head (971 after the 970 blank)',
    '// and ends at the token tail (998 before the 999 blank),',
    '// every paragraph complete. The upload quirks this round:',
    '// the OCR splits three hyphenated words with a space (one-',
    '// quarter, re- establish and non- dimensional); the curly',
    '// apostrophes print in deitys, pipers, tokens and the',
    '// Quaals item name (the engine spells the item with the',
    '// straight mark); curly quotes wrap picked up, hole and to',
    '// hit; the foot and inch primes print as curly marks; two',
    '// multiplication signs ride the rat dice; the token rows',
    '// separate with em-dashes - all pinned as plain digits and',
    '// words, apostrophe-free here. The part1 quirks: the',
    '// Monstrous Attention row splits across two table lines',
    '// (part1 9851-9852, with --- in the x.p. column); the',
    '// Feather Token row prints both dual value pairs in the',
    '// x.p. column. The Phylactery of Faithfulness carries no',
    '// accessor (numberless prose, like the Periapt of Health',
    '// in part 19). 44 accessors: 42 scalars + 2 walkers (the',
    '// token die bands), no name collisions with miscprose1.h',
    '// through miscprose19.h. Pure data + helpers, header-only',
    '// (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int mmpLongYearsSlowPct() {',
    '    // slows the aging process by one-quarter',
    '    return 25;',
    '}',
    '',
    'inline int mmpLongYearsDonAge() {',
    '    // the example cleric dons the device at age 20',
    '    return 20;',
    '}',
    '',
    'inline int mmpLongYearsMonthsPerYear() {',
    '    // he or she will age 9 months every 12',
    '    return 9;',
    '}',
    '',
    'inline int mmpLongYearsPhysicalAge() {',
    '    // in 12 chronological years, physically 29',
    '    return 29;',
    '}',
    '',
    'inline int mmpLongYearsChronAge() {',
    '    // rather than the naive 32',
    '    return 32;',
    '}',
    '',
    'inline int mmpLongYearsReverseOneIn() {',
    '    // 1 in 20 cursed to operate in reverse',
    '    return 20;',
    '}',
    '',
    'inline int mmpAttentionMinLevel() {',
    '    // at 10th or higher level the deity most',
    '    // powerful enemy interferes directly',
    '    return 10;',
    '}',
    '',
    'inline int mmpPipeGiantRatMin() {',
    '    // attracts from 10-60 giant rats',
    '    return 10;',
    '}',
    '',
    'inline int mmpPipeGiantRatMax() {',
    '    // the giant rat ceiling',
    '    return 60;',
    '}',
    '',
    'inline int mmpPipeGiantRatPct() {',
    '    // giant rats at 80 percent',
    '    return 80;',
    '}',
    '',
    'inline int mmpPipeNormalRatMin() {',
    '    // or from 30-180 normal rats',
    '    return 30;',
    '}',
    '',
    'inline int mmpPipeNormalRatMax() {',
    '    // the normal rat ceiling',
    '    return 180;',
    '}',
    '',
    'inline int mmpPipeNormalRatPct() {',
    '    // normal rats at 20 percent',
    '    return 20;',
    '}',
    '',
    'inline int mmpPipeCallRangeInches() {',
    '    // if either or both are within 40 inches',
    '    return 40;',
    '}',
    '',
    'inline int mmpPipeDelayPerInches() {',
    '    // a 1 round delay per each 5 inches traveled',
    '    return 5;',
    '}',
    '',
    'inline int mmpPipeObeyPct() {',
    '    // 95 percent likely to obey while the piper plays',
    '    return 95;',
    '}',
    '',
    'inline int mmpPipeReplayObeyPct() {',
    '    // called again: 70 percent come and obey',
    '    return 70;',
    '}',
    '',
    'inline int mmpPipeReplayTurnPct() {',
    '    // but 30 percent turn upon the piper',
    '    return 30;',
    '}',
    '',
    'inline int mmpPipeTakeoverPctPerRound() {',
    '    // 30 percent per round to take over control',
    '    // from a controlling creature',
    '    return 30;',
    '}',
    '',
    'inline int mmpPipeKeepPct() {',
    '    // 70 percent chance of maintaining control',
    '    return 70;',
    '}',
    '',
    'inline int mmpHoleDiameterFeet() {',
    '    // opened fully, 6 feet in diameter',
    '    return 6;',
    '}',
    '',
    'inline int mmpHoleDepthFeet() {',
    '    // an extra-dimensional hole 10 feet deep',
    '    return 10;',
    '}',
    '',
    'inline int mmpHoleBreathTurns() {',
    '    // breath runs out after about a turn',
    '    return 1;',
    '}',
    '',
    'inline int mmpHoleGateRadiusFeet() {',
    '    // creatures within a 10 foot radius are drawn',
    '    // to the plane, both items destroyed',
    '    return 10;',
    '}',
    '',
    'inline int mmpTokenUses() {',
    '    // each token is usable but once',
    '    return 1;',
    '}',
    '',
    'inline int mmpTokenRowLo(int i) {',
    '    // the printed token band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        1, 5, 8, 11, 14, 19,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpTokenRowHi(int i) {',
    '    // the printed token band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        4, 7, 10, 13, 18, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpTokenAnchorDays() {',
    '    // the anchor moors a craft immobile for 1 full day',
    '    return 1;',
    '}',
    '',
    'inline int mmpTokenBirdDays() {',
    '    // the bird equals a roc of the largest size',
    '    // (1 day duration)',
    '    return 1;',
    '}',
    '',
    'inline int mmpTokenFanHours() {',
    '    // the fan works up to eight hours a day',
    '    return 8;',
    '}',
    '',
    'inline int mmpTokenSwanSpeedInches() {',
    '    // the swan boat swims at 24 inch speed',
    '    return 24;',
    '}',
    '',
    'inline int mmpTokenSwanHorses() {',
    '    // it carries 8 horses and gear',
    '    return 8;',
    '}',
    '',
    'inline int mmpTokenSwanMen() {',
    '    // or 32 men',
    '    return 32;',
    '}',
    '',
    'inline int mmpTokenSwanDays() {',
    '    // duration 1 day',
    '    return 1;',
    '}',
    '',
    'inline int mmpTokenTreeTrunkFeet() {',
    '    // a great oak with a 6 foot diameter trunk',
    '    return 6;',
    '}',
    '',
    'inline int mmpTokenTreeHeightFeet() {',
    '    // 60 foot height',
    '    return 60;',
    '}',
    '',
    'inline int mmpTokenTreeTopFeet() {',
    '    // 40 foot top diameter',
    '    return 40;',
    '}',
    '',
    'inline int mmpTokenWhipPlus() {',
    '    // a +1 weapon',
    '    return 1;',
    '}',
    '',
    'inline int mmpTokenWhipLevel() {',
    '    // 9th level fighter to hit probability',
    '    return 9;',
    '}',
    '',
    'inline int mmpTokenWhipDmgMin() {',
    '    // 2-7 hit points damage',
    '    return 2;',
    '}',
    '',
    'inline int mmpTokenWhipDmgMax() {',
    '    return 7;',
    '}',
    '',
    'inline int mmpTokenWhipBindMin() {',
    '    // save versus magic or be bound fast',
    '    // for 2-7 rounds',
    '    return 2;',
    '}',
    '',
    'inline int mmpTokenWhipBindMax() {',
    '    return 7;',
    '}',
    '',
    'inline int mmpTokenWhipTurns() {',
    '    // wielded for up to 6 turns',
    '    return 6;',
    '}',
    '',
    '}  // namespace rules',
]

AUDIT = [
    '    // ---- R276: the III.E misc magic explanation',
    '    // prose part 20 ----',
    '    // The Phylactery of Faithfulness, the Phylactery of',
    '    // Long Years, the Phylactery of Monstrous Attention,',
    '    // the Pipes of the Sewers, the Portable Hole and',
    '    // Quaals Feather Token, part2 lines 971-998 - the',
    '    // slice pinning the kMisc4 rows 30-35 of the 36-row',
    '    // III.E.4 table (and closing it).',
    '    {',
    '        int bad = 0;',
    '        // the phylactery of long years scalars',
    '        if (rules::mmpLongYearsSlowPct() != 25 ||',
    '            rules::mmpLongYearsDonAge() != 20 ||',
    '            rules::mmpLongYearsMonthsPerYear() != 9 ||',
    '            rules::mmpLongYearsPhysicalAge() != 29 ||',
    '            rules::mmpLongYearsChronAge() != 32 ||',
    '            rules::mmpLongYearsReverseOneIn() != 20) ++bad;',
    '        // the aging example is internally consistent',
    '        if (rules::mmpLongYearsMonthsPerYear() >= 12 ||',
    '            rules::mmpLongYearsPhysicalAge() >=',
    '            rules::mmpLongYearsChronAge()) ++bad;',
    '        // the phylactery of monstrous attention',
    '        if (rules::mmpAttentionMinLevel() != 10) ++bad;',
    '        // the pipes of the sewers scalars',
    '        if (rules::mmpPipeGiantRatMin() != 10 ||',
    '            rules::mmpPipeGiantRatMax() != 60 ||',
    '            rules::mmpPipeGiantRatPct() != 80 ||',
    '            rules::mmpPipeNormalRatMin() != 30 ||',
    '            rules::mmpPipeNormalRatMax() != 180 ||',
    '            rules::mmpPipeNormalRatPct() != 20 ||',
    '            rules::mmpPipeCallRangeInches() != 40 ||',
    '            rules::mmpPipeDelayPerInches() != 5 ||',
    '            rules::mmpPipeObeyPct() != 95 ||',
    '            rules::mmpPipeReplayObeyPct() != 70 ||',
    '            rules::mmpPipeReplayTurnPct() != 30 ||',
    '            rules::mmpPipeTakeoverPctPerRound() != 30 ||',
    '            rules::mmpPipeKeepPct() != 70) ++bad;',
    '        // the rat split sums to the full call',
    '        if (rules::mmpPipeGiantRatPct() +',
    '            rules::mmpPipeNormalRatPct() != 100) ++bad;',
    '        // the replay percentages split too',
    '        if (rules::mmpPipeReplayObeyPct() +',
    '            rules::mmpPipeReplayTurnPct() != 100) ++bad;',
    '        // the portable hole scalars',
    '        if (rules::mmpHoleDiameterFeet() != 6 ||',
    '            rules::mmpHoleDepthFeet() != 10 ||',
    '            rules::mmpHoleBreathTurns() != 1 ||',
    '            rules::mmpHoleGateRadiusFeet() != 10) ++bad;',
    '        // the hole is deeper than it is wide',
    '        if (rules::mmpHoleDepthFeet() <=',
    '            rules::mmpHoleDiameterFeet()) ++bad;',
    '        // the quaal feather token scalars',
    '        if (rules::mmpTokenUses() != 1 ||',
    '            rules::mmpTokenAnchorDays() != 1 ||',
    '            rules::mmpTokenBirdDays() != 1 ||',
    '            rules::mmpTokenFanHours() != 8 ||',
    '            rules::mmpTokenSwanSpeedInches() != 24 ||',
    '            rules::mmpTokenSwanHorses() != 8 ||',
    '            rules::mmpTokenSwanMen() != 32 ||',
    '            rules::mmpTokenSwanDays() != 1 ||',
    '            rules::mmpTokenTreeTrunkFeet() != 6 ||',
    '            rules::mmpTokenTreeHeightFeet() != 60 ||',
    '            rules::mmpTokenTreeTopFeet() != 40 ||',
    '            rules::mmpTokenWhipPlus() != 1 ||',
    '            rules::mmpTokenWhipLevel() != 9 ||',
    '            rules::mmpTokenWhipDmgMin() != 2 ||',
    '            rules::mmpTokenWhipDmgMax() != 7 ||',
    '            rules::mmpTokenWhipBindMin() != 2 ||',
    '            rules::mmpTokenWhipBindMax() != 7 ||',
    '            rules::mmpTokenWhipTurns() != 6) ++bad;',
    '        // the die roll token table against static twins',
    '        static const int kTlo[6] = {',
    '            1, 5, 8, 11, 14, 19,',
    '        };',
    '        static const int kThi[6] = {',
    '            4, 7, 10, 13, 18, 20,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::mmpTokenRowLo(i) != kTlo[i] ||',
    '                rules::mmpTokenRowHi(i) != kThi[i]) ++bad;',
    '        // the token bands run 1 through 20 with no gaps',
    '        if (rules::mmpTokenRowLo(0) != 1 ||',
    '            rules::mmpTokenRowHi(5) != 20) ++bad;',
    '        for (int i = 0; i < 5; ++i)',
    '            if (rules::mmpTokenRowLo(i + 1) !=',
    '                rules::mmpTokenRowHi(i) + 1) ++bad;',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::mmpTokenRowLo(i) >',
    '                rules::mmpTokenRowHi(i)) ++bad;',
    '        // the kMisc4 table closure cross-check',
    '        static const int kRlo[6] = {',
    '            65, 71, 75, 77, 85, 86,',
    '        };',
    '        static const int kRhi[6] = {',
    '            70, 74, 76, 84, 85, 100,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::m4RowLo(30 + i) != kRlo[i] ||',
    '                rules::m4RowHi(30 + i) != kRhi[i]) ++bad;',
    '        // the marks: the three phylacteries are (C) only',
    '        for (int i = 30; i < 36; ++i)',
    '            if (i != 30 && i != 31 && i != 32 &&',
    '                rules::m4UsableByCleric(i) != 0) ++bad;',
    '        for (int i = 30; i < 36; ++i)',
    '            if (rules::m4UsableByFighter(i) != 0) ++bad;',
    '        for (int i = 30; i < 36; ++i)',
    '            if (rules::m4UsableByMagicUser(i) != 0) ++bad;',
    '        for (int i = 30; i < 36; ++i)',
    '            if (rules::m4UsableByThief(i) != 0) ++bad;',
    '        for (int i = 30; i < 36; ++i)',
    '            if (rules::m4StarCount(i) != 0) ++bad;',
    '        // the dual-value feather token row and helpers',
    '        if (rules::m4IsDualValued(35) != 1) ++bad;',
    '        for (int i = 30; i < 35; ++i)',
    '            if (rules::m4IsDualValued(i) != 0) ++bad;',
    '        if (rules::m4FeatherTokenXpLow() != 500 ||',
    '            rules::m4FeatherTokenXpHigh() != 1000 ||',
    '            rules::m4FeatherTokenGpLow() != 2000 ||',
    '            rules::m4FeatherTokenGpHigh() != 7000 ||',
    '            rules::m4RowCount() != 36) ++bad;',
    '        printf("R276 misc magic prose part 20 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R276 landed the III.E misc',
    'magic explanation prose',
    'part 20 (part2 lines 971-998;',
    'global = 11065 + part2 line),',
    'the Phylactery of Faithfulness,',
    'the Phylactery of Long Years,',
    'the Phylactery of Monstrous',
    'Attention, the Pipes of the',
    'Sewers, the Portable Hole and',
    'Quaals Feather Token (DMG',
    'p.153-154) - the slice pinning',
    'the kMisc4 rows 30-35 of the',
    '36-row III.E.4 table, closing',
    'it. This round has no seam:',
    'the slice starts at the 971',
    'head after the 970 blank and',
    'ends at the 998 token tail',
    'before the 999 blank, every',
    'paragraph complete. The',
    'upload quirks: the OCR splits',
    'three hyphenated words with a',
    'space (one- quarter, re-',
    'establish and non-',
    'dimensional); the curly',
    'apostrophes print in deitys,',
    'pipers, tokens and the Quaals',
    'item name (the engine spells',
    'the item with the straight',
    'mark); curly quotes wrap',
    'picked up, hole and to hit;',
    'the foot and inch primes print',
    'as curly marks; two',
    'multiplication signs ride the',
    'rat dice; the token rows',
    'separate with em-dashes - all',
    'pinned as plain digits and',
    'words. The part1 quirks: the',
    'Monstrous Attention row splits',
    'across two table lines (part1',
    '9851-9852, with --- in the',
    'x.p. column); the Feather',
    'Token row prints both dual',
    'value pairs in the x.p.',
    'column. The items: Phylactery',
    'of Faithfulness (worn normally',
    'by the cleric, aware of any',
    'action or item adverse to',
    'alignment and standing with the',
    'deity before performing it, if',
    'a prior moment is taken to',
    'contemplate; numberless prose,',
    'no accessor), Phylactery of',
    'Long Years (slows aging by',
    'one-quarter, even magical',
    'aging; the age 20 example ages',
    '9 months every 12, physically',
    '29 rather than 32 in 12',
    'years; 1 in 20 cursed to',
    'operate in reverse), Phylactery',
    'of Monstrous Attention (draws',
    'supernatural creatures of',
    'exactly the opposite alignment;',
    'at 10th or higher level the',
    'deity most powerful enemy',
    'interferes directly - a lawful',
    'good cleric attracts demons and',
    'eventually the notice of Orcus',
    'or Demogorgon; removal needs an',
    'exorcism spell and then a quest',
    'to re-establish the cleric),',
    'Pipes of the Sewers (10-60',
    'giant rats at 80 percent or',
    '30-180 normal rats at 20',
    'percent within 40 inches; a 1',
    'round delay per 5 inches',
    'traveled; 95 percent obey while',
    'the piper plays; ceasing sends',
    'them away at once; recalled, 70',
    'percent come and obey and 30',
    'percent turn upon the piper;',
    'against a controlling creature',
    '30 percent per round takeover,',
    'then 70 percent to maintain),',
    'Portable Hole (6 foot diameter',
    'opened fully, 10 foot deep',
    'extra-dimensional hole; about a',
    'turn of oxygen; a bag of',
    'holding inside tears a rift to',
    'the Astral Plane, both lost',
    'forever; the hole inside a bag',
    'opens a gate to another plane,',
    'creatures within 10 feet drawn,',
    'both destroyed), Quaals Feather',
    'Token (each usable but once:',
    'the anchor moors a craft',
    'immobile 1 full day; the bird',
    'drives off hostile avians or',
    'rides as a roc of the largest',
    'size for 1 day; the fan a',
    'strong breeze up to 8 hours a',
    'day, never on land; the swan',
    'boat swims at 24 inch speed',
    'carrying 8 horses and gear or',
    '32 men for 1 day; the tree a 6',
    'foot trunk, 60 foot height, 40',
    'foot top diameter; the whip a',
    '+1 weapon at 9th level fighter',
    'to hit, 2-7 damage, bind fast',
    '2-7 rounds on a failed save,',
    'wielded up to 6 turns; other',
    'tokens may be added as',
    'desired). 44 accessors: 42',
    'scalars + 2 walkers (the token',
    'die bands), no name collisions',
    'parts 1-19. New R276 battery',
    'audit; census 194. Next:',
    'R277 III.E part 21 - the',
    'Robe of the Archmagi onward',
    'in part2 from',
    'line 1002 (global 12067; the',
    'robes, the three ropes, the',
    'two rugs, the saw, the four',
    'scarabs and the spade follow;',
    'the kMisc5 rows 1+',
    'continue).',
]

# ---- the splice self-asserts ----
HTEXT = NL.join(HDR)
defs = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(]', HTEXT)
assert len(defs) == 44, 'accessor count is not 44'
assert len(set(defs)) == 44, 'accessor names not unique'
scal = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(][)]', HTEXT)
walk = [d for d in defs if d not in scal]
assert len(scal) == 42, 'scalar count is not 42'
assert len(walk) == 2, 'walker count is not 2'
assert set(walk) == {'mmpTokenRowLo', 'mmpTokenRowHi'}, 'wrong walkers'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(mmp[A-Za-z0-9]+)[(]', ATEXT))
assert audited == set(defs), 'audit does not probe every accessor'
for p in range(1, 20):
    pp = os.path.join(ROOT, 'rules/miscprose%d.h' % p)
    if os.path.exists(pp):
        pt = open(pp, encoding='utf-8').read()
        for n in defs:
            assert n not in pt, 'name collision with part %d' % p
for grp in (HDR, AUDIT, GAP):
    for el in grp:
        if isinstance(el, str):
            assert chr(39) not in el, 'apostrophe in content'
            probe = el.replace(chr(92) + 'n', '')
            assert chr(92) not in probe, 'backslash in content'
            assert NL not in el, 'list element spans lines'
assert ATEXT.count('{') == ATEXT.count('}'), 'audit braces unbalanced'
assert ATEXT.count('(') == ATEXT.count(')'), 'audit parens unbalanced'
assert AUDIT[-1] == '    }', 'audit block does not close'
assert HDR[-1] == '}  // namespace rules', 'header does not close'
assert ATEXT.count('R276 misc magic prose part 20 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 20', 'rows 30-35', 'no seam', 'III.E.4',
             'p.153-154', '44 accessors: 42', 'Archmagi',
             '12067', 'line 1002', 'rows 1+', 'census 194'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
hfrags = ('part 20', 'rows 30-35', 'no seam', 'III.E.4',
          'p.153-154', '44 accessors: 42')
for frag in hfrags:
    assert any(frag in el for el in HDR), 'header frag not contiguous: ' + frag

# ---- patch 1: create rules/miscprose20.h ----
p = 'rules/miscprose20.h'
if os.path.exists(os.path.join(ROOT, p)):
    assert rd(p) == HTEXT, 'miscprose20.h exists but differs'
    already += 1
else:
    wr(p, HTEXT)
    applied += 1
assert rd(p) == HTEXT, 'patch 1 failed'

# ---- patch 2: the regtest include ----
p = 'regtest.cpp'
s = rd(p)
inc = '#include "rules/miscprose20.h"  // R276: the III.E misc magic explanation prose part 20 pins'
if inc in s:
    already += 1
else:
    anchor = '#include "rules/miscprose19.h"  // R275: the III.E misc magic explanation prose part 19 pins'
    assert s.count(anchor) == 1, 'include anchor not unique'
    s = s.replace(anchor, anchor + NL + inc, 1)
    wr(p, s)
    applied += 1
assert inc in rd(p), 'patch 2 failed'
assert rd(p).count('#include "rules/miscprose20.h"') == 1, 'patch 2 doubled'

# ---- patch 3: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R276: the III.E misc magic explanation'
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
mark = 'R276 landed the III.E misc'
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

print('R276 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R276 note: 4 patches; the III.E misc magic')
print('explanation prose part 20 - the Phylactery')
print('of Faithfulness through the Quaals Feather')
print('Token, part2 lines 971-998; census 194.')
print('commit: R276: the III.E misc magic explanation prose part 20 pinned - the Phylactery of Faithfulness through the Quaals Feather Token in part2 lines 971-998 (census 194)')

