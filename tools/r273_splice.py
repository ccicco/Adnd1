#!/usr/bin/env python3
# R273 splice: the III.E misc magic explanation prose
# part 17 pins - the three Librams, the Lyre of
# Building and the manuals of Bodily Health, Gainful
# Exercise, Golems, Puissant Skill at Arms and
# Quickness of Action, part2 lines 806-841 (DMG
# p.149-150), pinning the kMisc4 rows 0-8 of the
# 36-row III.E.4 table. ONE page header inside the
# slice (839, the TREASURE page) falls inside the
# manual of quickness paragraph between Only after
# and the month of training - ONE seam restored this
# round; the page attribution rides the compilation
# TOC index (the books and manuals at pp.149-150) on
# the R272-established p.149 base. The upload quirks
# this round: the part1 table drops the pipe in two
# rows (02 the Ineffable Damnation, 08 the Puissant
# Skill at Arms), the golem table prints clean, and
# the bodily health paragraph carries a stray
# apostrophe artifact after the word manual (pinned
# as the upload prints it, apostrophe-free here).
# 4 patches, marker-based idempotence, assert after
# every patch. ZERO apostrophes and ZERO literal
# backslashes in the content below (the printf newline
# is built via BS = chr(92)).

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
    '// Adnd1 - rules/miscprose17.h',
    '// R273: the III.E misc magic explanation prose part 17',
    '// (DMG p.149-150) - the three Librams, the Lyre of',
    '// Building and the manuals of Bodily Health, Gainful',
    '// Exercise, Golems, Puissant Skill at Arms and',
    '// Quickness of Action, part2 lines 806-841 (global =',
    '// 11065 + part2 line), pinning the kMisc4 rows 0-8 of',
    '// the 36-row III.E.4 table. ONE page header inside',
    '// the slice (839, the TREASURE page) falls inside the',
    '// manual of quickness paragraph between Only after',
    '// and the month of training - ONE seam restored this',
    '// round; the page attribution rides the compilation',
    '// TOC index (the books and manuals at pp.149-150) on',
    '// the R272-established p.149 base. The upload drops',
    '// the pipe in two part1 rows (02 the Ineffable',
    '// Damnation, 08 the Puissant Skill at Arms); the',
    '// bodily health paragraph carries a stray apostrophe',
    '// artifact after the word manual (pinned as the',
    '// upload prints it, apostrophe-free here). 47',
    '// accessors: 43 scalars + 4 walkers (the golem table',
    '// die bands, months and costs), no name collisions',
    '// with miscprose1.h through miscprose16.h. Pure data',
    '// + helpers, header-only (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int mmpLibramStudyWeeks() {',
    '    // a full week of cloistered study',
    '    return 1;',
    '}',
    '',
    'inline int mmpLibramMisuseDamageMin() {',
    '    // a non-neutral reader takes 5-20 damage',
    '    return 5;',
    '}',
    '',
    'inline int mmpLibramMisuseDamageMax() {',
    '    // the upper edge of the 5-20 damage',
    '    return 20;',
    '}',
    '',
    'inline int mmpLibramUnconsciousTurnsMin() {',
    '    // unconscious a like number of turns',
    '    return 5;',
    '}',
    '',
    'inline int mmpLibramUnconsciousTurnsMax() {',
    '    // the upper edge of the like-number turns',
    '    return 20;',
    '}',
    '',
    'inline int mmpLibramInsanityRestMonths() {',
    '    // the insane reader rests 1 month',
    '    return 1;',
    '}',
    '',
    'inline int mmpLibramDamnationLevelLoss() {',
    '    // a non-evil look inside loses 1 level',
    '    return 1;',
    '}',
    '',
    'inline int mmpLyreNegateKindCount() {',
    '    // horn of blasting, disintegrate, elemental',
    '    return 3;',
    '}',
    '',
    'inline int mmpLyreNegateRounds() {',
    '    // negates 6 rounds of earth elemental attack',
    '    return 6;',
    '}',
    '',
    'inline int mmpLyreNegatePerDay() {',
    '    // the negatory chords play once per day',
    '    return 1;',
    '}',
    '',
    'inline int mmpLyreBuildPerWeek() {',
    '    // the building chords strum once per week',
    '    return 1;',
    '}',
    '',
    'inline int mmpLyreBuildTurns() {',
    '    // 3 turns of such playing',
    '    return 3;',
    '}',
    '',
    'inline int mmpLyreBuildMen() {',
    '    // equal to the work of 100 men',
    '    return 100;',
    '}',
    '',
    'inline int mmpLyreBuildDays() {',
    '    // 100 men laboring for 3 days',
    '    return 3;',
    '}',
    '',
    'inline int mmpLyreFalseChordPct() {',
    '    // a false chord negates 20 percent likely',
    '    return 20;',
    '}',
    '',
    'inline int mmpLyreFalseChordKnownPct() {',
    '    // only 5 percent once the proper ones known',
    '    return 5;',
    '}',
    '',
    'inline int mmpLyreFalseChordDisturbedPct() {',
    '    // disturbed while playing rises to 50 percent',
    '    return 50;',
    '}',
    '',
    'inline int mmpHealthReadHours() {',
    '    // the read takes 24 hours of time',
    '    return 24;',
    '}',
    '',
    'inline int mmpHealthReadDaysMin() {',
    '    // over 3-5 days',
    '    return 3;',
    '}',
    '',
    'inline int mmpHealthReadDaysMax() {',
    '    // the upper edge of the 3-5 days',
    '    return 5;',
    '}',
    '',
    'inline int mmpHealthConGain() {',
    '    // the regimen raises constitution by 1 point',
    '    return 1;',
    '}',
    '',
    'inline int mmpHealthRegimenMonths() {',
    '    // the diet and breathing run 1 month',
    '    return 1;',
    '}',
    '',
    'inline int mmpHealthForgetMonths() {',
    '    // the secrets fade in 3 months',
    '    return 3;',
    '}',
    '',
    'inline int mmpExerciseStrGain() {',
    '    // the course adds 1 point of strength',
    '    return 1;',
    '}',
    '',
    'inline int mmpGolemKindCount() {',
    '    // 4 sorts of golems',
    '    return 4;',
    '}',
    '',
    'inline int mmpGolemMinUserLevel() {',
    '    // the maker assumed 10th or higher',
    '    return 10;',
    '}',
    '',
    'inline int mmpGolemFailurePctPerLevel() {',
    '    // cumulative 10 percent per level under 10th',
    '    return 10;',
    '}',
    '',
    'inline int mmpGolemFailureWindowTurns() {',
    '    // falls to pieces within 1 turn of completion',
    '    return 1;',
    '}',
    '',
    'inline int mmpGolemClericXpLossMin() {',
    '    // a cleric reading loses 10,000 xp',
    '    return 10000;',
    '}',
    '',
    'inline int mmpGolemClericXpLossMax() {',
    '    // up to 60,000 xp lost',
    '    return 60000;',
    '}',
    '',
    'inline int mmpGolemMuLevelLoss() {',
    '    // a magic-user reading loses 1 level',
    '    return 1;',
    '}',
    '',
    'inline int mmpGolemOtherDamageMin() {',
    '    // any other class suffers 6-36 damage',
    '    return 6;',
    '}',
    '',
    'inline int mmpGolemOtherDamageMax() {',
    '    // the upper edge of the 6-36 damage',
    '    return 36;',
    '}',
    '',
    'inline int mmpGolemDieLo(int i) {',
    '    // the printed die band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 3) i = 3;',
    '    static const int t[4] = {',
    '        1, 6, 18, 19,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpGolemDieHi(int i) {',
    '    // the printed die band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 3) i = 3;',
    '    static const int t[4] = {',
    '        5, 17, 18, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpGolemMonths(int i) {',
    '    // the construction months per golem sort; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 3) i = 3;',
    '    static const int t[4] = {',
    '        1, 2, 4, 3,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpGolemCostGp(int i) {',
    '    // the construction cost per golem sort; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 3) i = 3;',
    '    static const int t[4] = {',
    '        65000, 50000, 100000, 80000,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpPuissantPracticeMonths() {',
    '    // the fighter practices 1 month',
    '    return 1;',
    '}',
    '',
    'inline int mmpPuissantForgetMonths() {',
    '    // the knowledge fades within 3 months',
    '    return 3;',
    '}',
    '',
    'inline int mmpPuissantStunTurnsMin() {',
    '    // a scanning magic-user is stunned 1-6 turns',
    '    return 1;',
    '}',
    '',
    'inline int mmpPuissantStunTurnsMax() {',
    '    // the upper edge of the 1-6 turn stun',
    '    return 6;',
    '}',
    '',
    'inline int mmpPuissantXpLossMin() {',
    '    // the scanning magic-user loses 10,000 xp',
    '    return 10000;',
    '}',
    '',
    'inline int mmpPuissantXpLossMax() {',
    '    // up to 60,000 xp lost',
    '    return 60000;',
    '}',
    '',
    'inline int mmpQuicknessStudyDays() {',
    '    // 3 days of uninterrupted study',
    '    return 3;',
    '}',
    '',
    'inline int mmpQuicknessPracticeMonths() {',
    '    // the skills practiced 1 month',
    '    return 1;',
    '}',
    '',
    'inline int mmpQuicknessDexGain() {',
    '    // the practice gains 1 point of dexterity',
    '    return 1;',
    '}',
    '',
    'inline int mmpQuicknessRememberMonths() {',
    '    // the contents remembered 3 months',
    '    return 3;',
    '}',
    '',
    '}  // namespace rules',
]

AUDIT = [
    '    // ---- R273: the III.E misc magic explanation',
    '    // prose part 17 ----',
    '    // The three Librams, the Lyre of Building and the',
    '    // manuals of Bodily Health, Gainful Exercise,',
    '    // Golems, Puissant Skill at Arms and Quickness of',
    '    // Action, part2 lines 806-841 - the slice pinning',
    '    // the kMisc4 rows 0-8 of the 36-row III.E.4 table.',
    '    {',
    '        int bad = 0;',
    '        // the libram of gainful conjuration',
    '        if (rules::mmpLibramStudyWeeks() != 1 ||',
    '            rules::mmpLibramMisuseDamageMin() != 5 ||',
    '            rules::mmpLibramMisuseDamageMax() != 20 ||',
    '            rules::mmpLibramInsanityRestMonths() != 1 ||',
    '            rules::mmpLibramDamnationLevelLoss() != 1) ++bad;',
    '        // the unconscious turns are a like number, the',
    '        // printed relation between the two pairs',
    '        if (rules::mmpLibramUnconsciousTurnsMin() !=',
    '            rules::mmpLibramMisuseDamageMin() ||',
    '            rules::mmpLibramUnconsciousTurnsMax() !=',
    '            rules::mmpLibramMisuseDamageMax()) ++bad;',
    '        // the lyre of building',
    '        if (rules::mmpLyreNegateKindCount() != 3 ||',
    '            rules::mmpLyreNegateRounds() != 6 ||',
    '            rules::mmpLyreNegatePerDay() != 1 ||',
    '            rules::mmpLyreBuildPerWeek() != 1 ||',
    '            rules::mmpLyreBuildTurns() != 3 ||',
    '            rules::mmpLyreBuildMen() != 100 ||',
    '            rules::mmpLyreBuildDays() != 3 ||',
    '            rules::mmpLyreFalseChordPct() != 20 ||',
    '            rules::mmpLyreFalseChordKnownPct() != 5 ||',
    '            rules::mmpLyreFalseChordDisturbedPct() !=',
    '            50) ++bad;',
    '        // the manual of bodily health and of gainful',
    '        // exercise',
    '        if (rules::mmpHealthReadHours() != 24 ||',
    '            rules::mmpHealthReadDaysMin() != 3 ||',
    '            rules::mmpHealthReadDaysMax() != 5 ||',
    '            rules::mmpHealthConGain() != 1 ||',
    '            rules::mmpHealthRegimenMonths() != 1 ||',
    '            rules::mmpHealthForgetMonths() != 3) ++bad;',
    '        if (rules::mmpExerciseStrGain() != 1) ++bad;',
    '        // the manual of golems scalars',
    '        if (rules::mmpGolemKindCount() != 4 ||',
    '            rules::mmpGolemMinUserLevel() != 10 ||',
    '            rules::mmpGolemFailurePctPerLevel() != 10 ||',
    '            rules::mmpGolemFailureWindowTurns() != 1 ||',
    '            rules::mmpGolemClericXpLossMin() != 10000 ||',
    '            rules::mmpGolemClericXpLossMax() != 60000 ||',
    '            rules::mmpGolemMuLevelLoss() != 1 ||',
    '            rules::mmpGolemOtherDamageMin() != 6 ||',
    '            rules::mmpGolemOtherDamageMax() != 36) ++bad;',
    '        // the golem table against static twins',
    '        static const int kGlo[4] = {',
    '            1, 6, 18, 19,',
    '        };',
    '        static const int kGhi[4] = {',
    '            5, 17, 18, 20,',
    '        };',
    '        static const int kGmo[4] = {',
    '            1, 2, 4, 3,',
    '        };',
    '        static const int kGco[4] = {',
    '            65000, 50000, 100000, 80000,',
    '        };',
    '        for (int i = 0; i < 4; ++i)',
    '            if (rules::mmpGolemDieLo(i) != kGlo[i] ||',
    '                rules::mmpGolemDieHi(i) != kGhi[i] ||',
    '                rules::mmpGolemMonths(i) != kGmo[i] ||',
    '                rules::mmpGolemCostGp(i) != kGco[i]) ++bad;',
    '        // the golem die bands tile 1-20 without gaps',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::mmpGolemDieLo(i + 1) !=',
    '                rules::mmpGolemDieHi(i) +',
    '                1) ++bad;',
    '        if (rules::mmpGolemDieLo(0) != 1 ||',
    '            rules::mmpGolemDieHi(3) != 20) ++bad;',
    '        // the manual of puissant skill at arms',
    '        if (rules::mmpPuissantPracticeMonths() != 1 ||',
    '            rules::mmpPuissantForgetMonths() != 3 ||',
    '            rules::mmpPuissantStunTurnsMin() != 1 ||',
    '            rules::mmpPuissantStunTurnsMax() != 6) ++bad;',
    '        // both printed 10,000-60,000 xp losses agree',
    '        if (rules::mmpPuissantXpLossMin() !=',
    '            rules::mmpGolemClericXpLossMin() ||',
    '            rules::mmpPuissantXpLossMax() !=',
    '            rules::mmpGolemClericXpLossMax()) ++bad;',
    '        // the manual of quickness of action',
    '        if (rules::mmpQuicknessStudyDays() != 3 ||',
    '            rules::mmpQuicknessPracticeMonths() != 1 ||',
    '            rules::mmpQuicknessDexGain() != 1 ||',
    '            rules::mmpQuicknessRememberMonths() != 3) ++bad;',
    '        // the engine kMisc4 rows 0-8: single-die band',
    '        // edges, the (M), (C) and (F) marks, no stars,',
    '        // no dual rows',
    '        static const int kRlo[9] = {',
    '            1, 2, 3, 4, 5, 6, 7, 8, 9,',
    '        };',
    '        static const int kRhi[9] = {',
    '            1, 2, 3, 4, 5, 6, 7, 8, 9,',
    '        };',
    '        for (int i = 0; i < 9; ++i)',
    '            if (rules::m4RowLo(i) != kRlo[i] ||',
    '                rules::m4RowHi(i) != kRhi[i] ||',
    '                rules::m4StarCount(i) != 0 ||',
    '                rules::m4IsDualValued(i) != 0) ++bad;',
    '        if (rules::m4UsableByMagicUser(0) != 1 ||',
    '            rules::m4UsableByMagicUser(1) != 1 ||',
    '            rules::m4UsableByMagicUser(2) != 1 ||',
    '            rules::m4UsableByMagicUser(6) != 1 ||',
    '            rules::m4UsableByMagicUser(3) != 0 ||',
    '            rules::m4UsableByMagicUser(7) != 0 ||',
    '            rules::m4UsableByCleric(6) != 1 ||',
    '            rules::m4UsableByCleric(0) != 0 ||',
    '            rules::m4UsableByFighter(7) != 1 ||',
    '            rules::m4UsableByFighter(0) != 0 ||',
    '            rules::m4UsableByThief(7) != 0) ++bad;',
    '        printf("R273 misc magic prose part 17 pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]

GAP = [
    'R273 landed the III.E misc',
    'magic explanation prose part',
    '17 (part2 lines 806-841;',
    'global = 11065 + part2',
    'line), the three Librams, the',
    'Lyre of Building and the',
    'manuals of Bodily Health,',
    'Gainful Exercise, Golems,',
    'Puissant Skill at Arms and',
    'Quickness of Action (DMG',
    'p.149-150) - the slice',
    'pinning the kMisc4',
    'rows 0-8 of the 36-row',
    'III.E.4 table. ONE page',
    'header inside the slice',
    '(839, the TREASURE page)',
    'falls inside the manual of',
    'quickness paragraph between',
    'Only after and the month',
    'of training - ONE',
    'seam restored this round;',
    'the page attribution rides',
    'the compilation TOC index',
    '(the books and manuals at',
    'pp.149-150) on the',
    'R272-established p.149',
    'base. The upload drops the',
    'pipe in two part1 rows (02',
    'the Ineffable Damnation,',
    '08 the Puissant Skill at',
    'Arms); the bodily health',
    'paragraph carries a stray',
    'apostrophe artifact after',
    'the word manual (pinned as',
    'the upload prints it,',
    'apostrophe-free in the',
    'header). The items: Libram',
    'of Gainful Conjuration (a',
    'full week of study to the',
    'mid-point of the next',
    'level, 5-20 damage to a',
    'non-neutral reader with a',
    'like number of unconscious',
    'turns, remove curse plus 1',
    'month rest for the',
    'insane), Libram of',
    'Ineffable Damnation (evil',
    'benefit, 1 level lost from',
    'a non-evil look inside),',
    'Libram of Silver Magic',
    '(good benefit, vanishes',
    'after 1 week), Lyre of',
    'Building (negates horn of',
    'blasting, disintegrate or 6',
    'rounds of earth elemental',
    'attack once per day,',
    'builds once per week with',
    '3 turns of play equal to',
    '100 men for 3 days, false',
    'chord 20 percent, 5',
    'percent once known, 50',
    'percent disturbed),',
    'Manual of Bodily Health',
    '(24 hours over 3-5 days,',
    '+1 constitution after a 1',
    'month regimen, forgotten',
    'in 3 months), Manual of',
    'Gainful Exercise (+1',
    'strength), Manual of',
    'Golems (4 sorts: clay',
    '1-5 1 month 65,000, flesh',
    '6-17 2 months 50,000,',
    'iron 18 4 months',
    '100,000, stone 19-20 3',
    'months 80,000; maker',
    'assumed 10th, cumulative',
    '10 percent per level',
    'under, cleric loses',
    '10,000-60,000 xp,',
    'magic-user loses 1 level,',
    'others take 6-36 damage),',
    'Manual of Puissant Skill',
    'at Arms (fighter only, 1',
    'month to the mid-point,',
    'forgotten in 3 months, a',
    'scanning magic-user is',
    'stunned 1-6 turns and',
    'loses 10,000-60,000 xp),',
    'Manual of Quickness of',
    'Action (3 days study, 1',
    'month practice, +1',
    'dexterity, remembered 3',
    'months). 47 accessors:',
    '43 scalars + 4 walkers',
    '(the golem die bands,',
    'months and costs), no',
    'name collisions parts',
    '1-16. New R273 battery',
    'audit; census 191. Next:',
    'R274 III.E part 18 - the',
    'Manual of Stealthy',
    'Pilfering onward in part2',
    'from line 843 (global',
    '11908; the mattock, maul,',
    'medallions and mirrors',
    'follow; kMisc4 rows 9+',
    'continue).',
]

# ---- the splice self-asserts ----
HTEXT = NL.join(HDR)
defs = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(]', HTEXT)
assert len(defs) == 47, 'accessor count is not 47'
assert len(set(defs)) == 47, 'accessor names not unique'
scal = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(][)]', HTEXT)
walk = [d for d in defs if d not in scal]
assert len(scal) == 43, 'scalar count is not 43'
assert len(walk) == 4, 'walker count is not 4'
assert set(walk) == {'mmpGolemDieLo', 'mmpGolemDieHi',
                    'mmpGolemMonths',
                    'mmpGolemCostGp'}, 'wrong walkers'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(mmp[A-Za-z0-9]+)[(]', ATEXT))
assert audited == set(defs), 'audit does not probe every accessor'
for p in range(1, 17):
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
assert ATEXT.count('R273 misc magic prose part 17 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'

# ---- patch 1: create rules/miscprose17.h ----
p = 'rules/miscprose17.h'
if os.path.exists(os.path.join(ROOT, p)):
    assert rd(p) == HTEXT, 'miscprose17.h exists but differs'
    already += 1
else:
    wr(p, HTEXT)
    applied += 1
assert rd(p) == HTEXT, 'patch 1 failed'

# ---- patch 2: the regtest include ----
p = 'regtest.cpp'
s = rd(p)
inc = '#include "rules/miscprose17.h"  // R273: the III.E misc magic explanation prose part 17 pins'
if inc in s:
    already += 1
else:
    anchor = '#include "rules/miscprose16.h"  // R272: the III.E misc magic explanation prose part 16 pins'
    assert s.count(anchor) == 1, 'include anchor not unique'
    s = s.replace(anchor, anchor + NL + inc, 1)
    wr(p, s)
    applied += 1
assert inc in rd(p), 'patch 2 failed'
assert rd(p).count('#include "rules/miscprose17.h"') == 1, 'patch 2 doubled'

# ---- patch 3: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R273: the III.E misc magic explanation'
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
mark = 'R273 landed the III.E misc'
if mark in s:
    already += 1
else:
    anchor = 'manuals follow).' + NL + NL + 'Categories:'
    assert s.count(anchor) == 1, 'gap anchor not unique'
    s = s.replace(anchor, 'manuals follow).' + NL + NL + NL.join(GAP) + NL + NL + 'Categories:', 1)
    wr(p, s)
    applied += 1
assert mark in rd(p), 'patch 4 failed'
assert rd(p).count(mark) == 1, 'patch 4 doubled'

print('R273 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R273 note: 4 patches; the III.E misc magic')
print('explanation prose part 17 - the three Librams')
print('through the Manual of Quickness of Action,')
print('part2 lines 806-841; census 191.')
print('commit: R273: the III.E misc magic explanation prose part 17 pinned - the three Librams through the Manual of Quickness of Action in part2 lines 806-841 (census 191)')

