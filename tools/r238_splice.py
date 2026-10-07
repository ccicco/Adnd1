#!/usr/bin/env python3
# R238 splice: the III.E table 4 footnote pins.
#
# DMG p.129-130, upload lines ~9817-9898 - the
# class marks and the asterisk ladder that
# frame TABLE (III.E.) 4: the (M) Librams,
# Manual of Golems, Mirror of Life Trapping
# and Pearl of Power; the (C) Prayer Beads,
# Pearl of Wisdom, Nets and Phylacteries; the
# (F) Manual of Puissant Skill at Arms and
# Mattock; the (T) Manual of Stealthy
# Pilfering and the Nets; the Necklace of
# Missiles single star (per hit die of each
# missile), the Necklace of Prayer Beads
# double star (per special bead), the
# Marvelous Pigments triple star (per pot of
# pigments), the Pearl of Power quadruple
# star (per level of spell) - all four
# footnotes ride the upload this time; and
# the two dual-value rows (the Medallion of
# ESP 1,000/3,000 x.p., 10,000/30,000 g.p.;
# the Feather Token 500/1,000 x.p.,
# 2,000/7,000 g.p.). Keyed to the 36 die
# bands of the engine III.E.4 table; the row
# VALUES were already pinned by R122.
# Patches: 4 (new rules/miscmagic4.h, the
# regtest include, the audit block, the
# dmg-gap-report log entry). Census 156 -> 157.
#
# commit: R238: the III.E table 4 footnote pins pinned - DMG p.129-130, the class marks, the asterisk ladder and the dual-value rows (census 157)

import sys

MM4  = 'rules/miscmagic4.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 156 and t.count('audit: bad ') != 157:
    print('R238 FAIL: regtest census is neither 156 nor 157')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/miscmagic4.h',
    '// R238: the III.E table 4 footnote pins',
    '// (DMG p.129-130) - the class marks, the',
    '// asterisk ladder and the dual-value rows',
    '// that frame TABLE (III.E.) 4 of the',
    '// miscellaneous magic tables:',
    '//   - the (M) marks: the three Librams,',
    '//     the Manual of Golems (with C), the',
    '//     Mirror of Life Trapping and the',
    '//     Pearl of Power.',
    '//   - the (C) marks: the Manual of Golems',
    '//     (with M), the Necklace of Prayer',
    '//     Beads, the Pearl of Wisdom, the two',
    '//     Nets (with F and T) and the three',
    '//     Phylacteries.',
    '//   - the (F) marks: the Manual of',
    '//     Puissant Skill at Arms, the Mattock',
    '//     of the Titans and the two Nets.',
    '//   - the (T) marks: the Manual of',
    '//     Stealthy Pilfering and the two Nets.',
    '//   - the Necklace of Missiles single',
    '//     asterisk (24-27): the 50 x.p. / 200',
    '//     g.p. values are PER HIT DIE of each',
    '//     missile.',
    '//   - the Necklace of Prayer Beads double',
    '//     asterisk (28-33): PER SPECIAL BEAD',
    '//     (500 x.p. / 3,000 g.p.).',
    '//   - the Marvelous Pigments triple',
    '//     asterisk (43-44): PER POT of',
    '//     pigments (500 x.p. / 3,000 g.p.).',
    '//   - the Pearl of Power quadruple',
    '//     asterisk (45-46): PER LEVEL OF SPELL',
    '//     (200 x.p. / 2,000 g.p.) - all four',
    '//     footnotes ride the book upload this',
    '//     time.',
    '//   - the two DUAL-VALUE rows: the',
    '//     Medallion of ESP (13-15) at 1,000 /',
    '//     3,000 x.p. and 10,000 / 30,000 g.p.,',
    '//     and the Feather Token (86-00) at',
    '//     500 / 1,000 x.p. and 2,000 / 7,000',
    '//     g.p.',
    '// The row identity is the 36 die bands of',
    '// the engine III.E.4 table (dm/treasure.cpp',
    '// kMisc4 order, the three Librams 01-03',
    '// through the Feather Token 86-00). The',
    '// row VALUES were pinned by the R122',
    '// line-diff audit; this header pins the',
    '// class marks, the asterisk ladder, the',
    '// dual-value rows and the band edges.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int m4RowCount() {',
    '    // the Librams through the Feather Token',
    '    return 36;',
    '}',
    '',
    'inline int m4RowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,',
    '        11, 12, 13, 16, 18, 19, 20, 21, 24, 28,',
    '        34, 36, 39, 43, 45, 47, 49, 51, 54, 61,',
    '        65, 71, 75, 77, 85, 86,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m4RowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,',
    '        11, 12, 15, 17, 18, 19, 20, 23, 27, 33,',
    '        35, 38, 42, 44, 46, 48, 50, 53, 60, 64,',
    '        70, 74, 76, 84, 85, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m4UsableByCleric(int i) {',
    '    // the (C) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '        0, 1, 1, 0, 0, 1, 0, 0, 0, 0,',
    '        1, 1, 1, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m4UsableByFighter(int i) {',
    '    // the (F) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,',
    '        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 1, 1, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m4UsableByMagicUser(int i) {',
    '    // the (M) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        1, 1, 1, 0, 0, 0, 1, 0, 0, 0,',
    '        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m4UsableByThief(int i) {',
    '    // the (T) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 1, 1, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m4StarCount(int i) {',
    '    // the asterisk ladder: 1 the Necklace of',
    '    // Missiles (per hit die of each missile),',
    '    // 2 the Prayer Beads (per special bead),',
    '    // 3 the Marvelous Pigments (per pot),',
    '    // 4 the Pearl of Power (per level of',
    '    // spell); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 1, 2,',
    '        0, 0, 0, 3, 4, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m4IsDualValued(int i) {',
    '    // the dual-value rows: the Medallion of',
    '    // ESP (13-15) and the Feather Token',
    '    // (86-00); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 35) i = 35;',
    '    static const int t[36] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 1, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m4ClericCount() {',
    '    return 8;',
    '}',
    '',
    'inline int m4FighterCount() {',
    '    return 4;',
    '}',
    '',
    'inline int m4MagicUserCount() {',
    '    return 6;',
    '}',
    '',
    'inline int m4ThiefCount() {',
    '    return 3;',
    '}',
    '',
    'inline int m4MissilePerHitDieXp() {',
    '    // per hit die of each missile',
    '    return 50;',
    '}',
    '',
    'inline int m4MissilePerHitDieGp() {',
    '    return 200;',
    '}',
    '',
    'inline int m4BeadPerSpecialXp() {',
    '    // per special bead',
    '    return 500;',
    '}',
    '',
    'inline int m4BeadPerSpecialGp() {',
    '    return 3000;',
    '}',
    '',
    'inline int m4PigmentsPerPotXp() {',
    '    // per pot of pigments',
    '    return 500;',
    '}',
    '',
    'inline int m4PigmentsPerPotGp() {',
    '    return 3000;',
    '}',
    '',
    'inline int m4PearlPerSpellLevelXp() {',
    '    // per level of spell',
    '    return 200;',
    '}',
    '',
    'inline int m4PearlPerSpellLevelGp() {',
    '    return 2000;',
    '}',
    '',
    'inline int m4MedallionEspXpLow() {',
    '    return 1000;',
    '}',
    '',
    'inline int m4MedallionEspXpHigh() {',
    '    return 3000;',
    '}',
    '',
    'inline int m4MedallionEspGpLow() {',
    '    return 10000;',
    '}',
    '',
    'inline int m4MedallionEspGpHigh() {',
    '    return 30000;',
    '}',
    '',
    'inline int m4FeatherTokenXpLow() {',
    '    return 500;',
    '}',
    '',
    'inline int m4FeatherTokenXpHigh() {',
    '    return 1000;',
    '}',
    '',
    'inline int m4FeatherTokenGpLow() {',
    '    return 2000;',
    '}',
    '',
    'inline int m4FeatherTokenGpHigh() {',
    '    return 7000;',
    '}',
    '',
    '}  // namespace rules',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/miscmagic3.h"  // R237: p.129 the misc table 3 pins',
]
inc_new = [
    '#include "rules/miscmagic3.h"  // R237: p.129 the misc table 3 pins',
    '#include "rules/miscmagic4.h"  // R238: p.129-130 the misc table 4 pins',
]

# ---- the R238 audit ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R238: the III.E table 4 pins audit ----',
    '    // DMG p.129-130: the class marks, the',
    '    // asterisk ladder and the dual-value rows',
    '    // of TABLE (III.E.) 4.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 36 die bands',
    '        if (rules::m4RowCount() != 36) ++bad;',
    '        static const int kLo[36] = {',
    '            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,',
    '            11, 12, 13, 16, 18, 19, 20, 21, 24, 28,',
    '            34, 36, 39, 43, 45, 47, 49, 51, 54, 61,',
    '            65, 71, 75, 77, 85, 86,',
    '        };',
    '        static const int kHi[36] = {',
    '            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,',
    '            11, 12, 15, 17, 18, 19, 20, 23, 27, 33,',
    '            35, 38, 42, 44, 46, 48, 50, 53, 60, 64,',
    '            70, 74, 76, 84, 85, 100,',
    '        };',
    '        static const int kC[36] = {',
    '            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '            0, 1, 1, 0, 0, 1, 0, 0, 0, 0,',
    '            1, 1, 1, 0, 0, 0,',
    '        };',
    '        static const int kF[36] = {',
    '            0, 0, 0, 0, 0, 0, 0, 1, 0, 0,',
    '            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kM[36] = {',
    '            1, 1, 1, 0, 0, 0, 1, 0, 0, 0,',
    '            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kT[36] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kStar[36] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 1, 2,',
    '            0, 0, 0, 3, 4, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kDual[36] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 1, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 1,',
    '        };',
    '        for (int i = 0; i < 36; ++i)',
    '            if (rules::m4RowLo(i) != kLo[i] ||',
    '                rules::m4RowHi(i) != kHi[i] ||',
    '                rules::m4UsableByCleric(i) != kC[i] ||',
    '                rules::m4UsableByFighter(i) != kF[i] ||',
    '                rules::m4UsableByMagicUser(i) != kM[i] ||',
    '                rules::m4UsableByThief(i) != kT[i] ||',
    '                rules::m4StarCount(i) != kStar[i] ||',
    '                rules::m4IsDualValued(i) != kDual[i])',
    '                ++bad;',
    '        for (int i = 1; i < 36; ++i)',
    '            if (rules::m4RowLo(i) !=',
    '                rules::m4RowHi(i - 1) + 1) ++bad;',
    '        if (rules::m4RowLo(-5) != 1 ||',
    '            rules::m4RowHi(99) != 100) ++bad;',
    '        // the class marks: the Librams and the',
    '        // Pearl of Power are (M); the Golems',
    '        // Manual is (C, M); the Puissant Manual',
    '        // and the Mattock are (F); the',
    '        // Stealthy Manual and the Nets are (T)',
    '        if (rules::m4ClericCount() != 8 ||',
    '            rules::m4FighterCount() != 4 ||',
    '            rules::m4MagicUserCount() != 6 ||',
    '            rules::m4ThiefCount() != 3) ++bad;',
    '        if (!rules::m4UsableByMagicUser(0) ||',
    '            !rules::m4UsableByMagicUser(1) ||',
    '            !rules::m4UsableByMagicUser(2)) ++bad;',
    '        if (!rules::m4UsableByCleric(6) ||',
    '            !rules::m4UsableByMagicUser(6)) ++bad;',
    '        if (!rules::m4UsableByFighter(7) ||',
    '            rules::m4UsableByCleric(7)) ++bad;',
    '        if (!rules::m4UsableByThief(9) ||',
    '            rules::m4UsableByFighter(9)) ++bad;',
    '        if (!rules::m4UsableByFighter(10) ||',
    '            rules::m4UsableByMagicUser(10)) ++bad;',
    '        if (rules::m4UsableByCleric(8) ||',
    '            rules::m4UsableByFighter(8) ||',
    '            rules::m4UsableByMagicUser(8) ||',
    '            rules::m4UsableByThief(8)) ++bad;',
    '        if (!rules::m4UsableByMagicUser(14) ||',
    '            rules::m4UsableByMagicUser(15)) ++bad;',
    '        if (!rules::m4UsableByCleric(19) ||',
    '            rules::m4UsableByMagicUser(19)) ++bad;',
    '        if (!rules::m4UsableByCleric(21) ||',
    '            !rules::m4UsableByFighter(21) ||',
    '            !rules::m4UsableByThief(21) ||',
    '            !rules::m4UsableByCleric(22) ||',
    '            !rules::m4UsableByFighter(22) ||',
    '            !rules::m4UsableByThief(22)) ++bad;',
    '        if (!rules::m4UsableByMagicUser(24) ||',
    '            !rules::m4UsableByCleric(25) ||',
    '            rules::m4UsableByCleric(24)) ++bad;',
    '        if (!rules::m4UsableByCleric(30) ||',
    '            !rules::m4UsableByCleric(31) ||',
    '            !rules::m4UsableByCleric(32)) ++bad;',
    '        if (rules::m4UsableByCleric(33) ||',
    '            rules::m4UsableByCleric(34)) ++bad;',
    '        // the asterisk ladder: the Necklace of',
    '        // Missiles 24-27 (1 star, per hit die of',
    '        // each missile), the Prayer Beads 28-33',
    '        // (2 stars, per special bead), the',
    '        // Pigments 43-44 (3 stars, per pot), the',
    '        // Pearl of Power 45-46 (4 stars, per',
    '        // level of spell)',
    '        if (rules::m4StarCount(18) != 1 ||',
    '            rules::m4StarCount(19) != 2 ||',
    '            rules::m4StarCount(23) != 3 ||',
    '            rules::m4StarCount(24) != 4 ||',
    '            rules::m4StarCount(17) != 0) ++bad;',
    '        // a 5-hit-die missile is 250 x.p. /',
    '        // 1,000 g.p.',
    '        if (rules::m4MissilePerHitDieXp() != 50 ||',
    '            rules::m4MissilePerHitDieGp() != 200 ||',
    '            rules::m4MissilePerHitDieXp() * 5 != 250 ||',
    '            rules::m4MissilePerHitDieGp() * 5 != 1000)',
    '            ++bad;',
    '        // two special beads are 1,000 x.p. /',
    '        // 6,000 g.p.',
    '        if (rules::m4BeadPerSpecialXp() != 500 ||',
    '            rules::m4BeadPerSpecialGp() != 3000 ||',
    '            rules::m4BeadPerSpecialXp() * 2 != 1000 ||',
    '            rules::m4BeadPerSpecialGp() * 2 != 6000)',
    '            ++bad;',
    '        // two pots of pigments are 1,000 x.p.',
    '        // / 6,000 g.p.',
    '        if (rules::m4PigmentsPerPotXp() != 500 ||',
    '            rules::m4PigmentsPerPotGp() != 3000 ||',
    '            rules::m4PigmentsPerPotXp() * 2 != 1000 ||',
    '            rules::m4PigmentsPerPotGp() * 2 != 6000)',
    '            ++bad;',
    '        // a 3rd-level spell pearl is 600 x.p. /',
    '        // 6,000 g.p.',
    '        if (rules::m4PearlPerSpellLevelXp() != 200 ||',
    '            rules::m4PearlPerSpellLevelGp() != 2000 ||',
    '            rules::m4PearlPerSpellLevelXp() * 3 != 600 ||',
    '            rules::m4PearlPerSpellLevelGp() * 3 != 6000)',
    '            ++bad;',
    '        // the dual rows: the Medallion of ESP',
    '        // 1,000/3,000 x.p., 10,000/30,000 g.p.;',
    '        // the Feather Token 500/1,000 x.p.,',
    '        // 2,000/7,000 g.p.',
    '        if (!rules::m4IsDualValued(12) ||',
    '            rules::m4IsDualValued(13) ||',
    '            !rules::m4IsDualValued(35) ||',
    '            rules::m4IsDualValued(34)) ++bad;',
    '        if (rules::m4MedallionEspXpLow() != 1000 ||',
    '            rules::m4MedallionEspXpHigh() != 3000 ||',
    '            rules::m4MedallionEspGpLow() != 10000 ||',
    '            rules::m4MedallionEspGpHigh() != 30000)',
    '            ++bad;',
    '        if (rules::m4FeatherTokenXpLow() != 500 ||',
    '            rules::m4FeatherTokenXpHigh() != 1000 ||',
    '            rules::m4FeatherTokenGpLow() != 2000 ||',
    '            rules::m4FeatherTokenGpHigh() != 7000)',
    '            ++bad;',
    '        // clamped reads land on the first',
    '        // Libram (M, unstarred) below and the',
    '        // Feather Token (dual) above',
    '        if (rules::m4StarCount(-99) != 0 ||',
    '            !rules::m4UsableByMagicUser(-99) ||',
    '            !rules::m4IsDualValued(99) ||',
    '            rules::m4UsableByCleric(99)) ++bad;',
    '        printf("R238 misc table 4 pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'p.129-130, upload lines ~9827+), or',
    'the next un-pinned III.A-H surrounding',
    'prose seam.',
]
gap_new = [
    'p.129-130, upload lines ~9827+), or',
    'the next un-pinned III.A-H surrounding',
    'prose seam.',
    '',
    'R238 landed the III.E table 4 footnote',
    'pins (DMG p.129-130, upload lines',
    '~9817-9898) - the class marks, the',
    'asterisk ladder and the dual-value rows',
    'that frame TABLE (III.E.) 4.',
    'rules/miscmagic4.h (the grenade.h',
    'pattern), keyed to the 36 die bands of',
    'the engine III.E.4 table in kMisc4 order:',
    'the (M) marks (the three Librams, the',
    'Manual of Golems with C, the Mirror of',
    'Life Trapping, the Pearl of Power); the',
    '(C) marks (the Manual of Golems with M,',
    'the Necklace of Prayer Beads, the Pearl',
    'of Wisdom, the two Nets with F and T,',
    'the three Phylacteries); the (F) marks',
    '(the Manual of Puissant Skill at Arms,',
    'the Mattock of the Titans, the Nets);',
    'the (T) marks (the Manual of Stealthy',
    'Pilfering, the Nets). The asterisk',
    'ladder: the Necklace of Missiles (24-27)',
    'single star - 50 x.p. / 200 g.p. PER HIT',
    'DIE of each missile; the Necklace of',
    'Prayer Beads (28-33) double star - PER',
    'SPECIAL BEAD; the Marvelous Pigments',
    '(43-44) triple star - PER POT of',
    'pigments; the Pearl of Power (45-46)',
    'quadruple star - PER LEVEL OF SPELL (all',
    'four footnotes ride the book upload this',
    'time - no restoration needed). The two',
    'DUAL-VALUE rows: the Medallion of ESP',
    '(13-15) at 1,000/3,000 x.p. and',
    '10,000/30,000 g.p., and the Feather',
    'Token (86-00) at 500/1,000 x.p. and',
    '2,000/7,000 g.p. (a new walk flag - the',
    'R225 tiered-purse analog). Cross-checked',
    'against the 1eonline.info compilation',
    '(which drops the Golems and Beads marks',
    'the upload carries - the upload is the',
    'book-text source, the R225/R226',
    'convention). The row VALUES were',
    'already pinned by the R122 line-diff',
    'audit; this round pins the class marks,',
    'the asterisk ladder, the dual-value rows',
    'and the band edges. New R238 battery',
    'audit; census 157. Next: R239 - the',
    'III.E table 5 footnotes (the Robe and',
    'Rug class marks, the Saw and Spade (F)',
    'marks, DMG p.130, upload lines ~9898+),',
    'or the next un-pinned III.A-H',
    'surrounding prose seam.',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson)
marker = 'R238: the III.E table 4 footnote pins'
try:
    t = open(MM4).read()
    if marker in t:
        already += 1
    else:
        print('R238 FAIL: rules/miscmagic4.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(MM4, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R238 audit', audit_old, audit_new),
    (GAP, 'the R238 log entry', gap_old, gap_new),
]:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    # the idempotence signal is the NEW text (the R233
    # lesson: append-style patches leave the old text
    # inside the new)
    if new_s in text:
        already += 1
        continue
    if text.count(old_s) == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    else:
        print('R238 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 157:
        print('R238 FAIL: census is not 157')
        sys.exit(1)
    if t.count('R238 misc table 4 pins audit') != 1:
        print('R238 FAIL: the R238 audit line must appear once')
        sys.exit(1)
    if t.count('rules/miscmagic4.h') != 1:
        print('R238 FAIL: the miscmagic4 include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R238 landed the III.E table 4 footnote') != 1:
        print('R238 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(MM4).read()
    if 'namespace rules' not in h or h.count('inline int m4') != 29:
        print('R238 FAIL: the header shape is wrong')
        sys.exit(1)

print('R238 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R238 note: 4 patches; the III.E table 4 footnote pins landed -')
print('the class marks, the asterisk ladder, the dual-value rows; census 157.')
print('commit: R238: the III.E table 4 footnote pins pinned - DMG p.129-130, the class marks, the asterisk ladder and the dual-value rows (census 157)')

