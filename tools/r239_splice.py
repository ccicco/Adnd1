#!/usr/bin/env python3
# R239 splice: the III.E table 5 footnote pins.
#
# DMG p.130, upload lines ~9898-9915 - the class
# marks that frame TABLE (III.E.) 5 (the last of
# the miscellaneous magic sub-tables): the (M)
# Robe of the Archmagi, Robe of Eyes, Robe of
# Powerlessness, Robe of Scintillating Colors
# (with C), Robe of Useful Items, Rug of Welcome,
# Sphere of Annihilation and Talisman of the
# Sphere; the (C) Robe of Scintillating Colors
# (with M), Talisman of Pure Good, Talisman of
# Ultimate Evil and the two Tridents (with F and
# T); the (F) Saw of Mighty Cutting, Spade of
# Colossal Excavation, Trident of Submission and
# the two command/warning Tridents; the (T) the
# Tridents of Fish Command and Warning. NO
# asterisk rows, dual-value rows or footnotes
# ride this table (verified: the print runs
# straight from the 91-00 Wings of Flying row
# to the TABLE (III.E.) Special artifacts
# table). Keyed to the 35 die bands of the
# engine III.E.5 table; the row VALUES were
# already pinned by R122.
# Patches: 4 (new rules/miscmagic5.h, the
# regtest include, the audit block, the
# dmg-gap-report log entry). Census 157 -> 158.
#
# commit: R239: the III.E table 5 footnote pins pinned - DMG p.130, the class marks (census 158)

import sys

MM5  = 'rules/miscmagic5.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)
Q  = chr(39)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 157 and t.count('audit: bad ') != 158:
    print('R239 FAIL: regtest census is neither 157 nor 158')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/miscmagic5.h',
    '// R239: the III.E table 5 footnote pins',
    '// (DMG p.130) - the class marks that frame',
    '// TABLE (III.E.) 5 of the miscellaneous',
    '// magic tables (the last sub-table):',
    '//   - the (M) marks: the Robe of the',
    '//     Archmagi, Robe of Eyes, Robe of',
    '//     Powerlessness, Robe of Scintillating',
    '//     Colors (with C), Robe of Useful',
    '//     Items, Rug of Welcome, Sphere of',
    '//     Annihilation and Talisman of the',
    '//     Sphere.',
    '//   - the (C) marks: the Robe of',
    '//     Scintillating Colors (with M), the',
    '//     Talisman of Pure Good, the Talisman',
    '//     of Ultimate Evil and the two',
    '//     command/warning Tridents (with F',
    '//     and T).',
    '//   - the (F) marks: the Saw of Mighty',
    '//     Cutting, the Spade of Colossal',
    '//     Excavation, the Trident of Submission',
    '//     and the two command/warning Tridents.',
    '//   - the (T) marks: the Tridents of Fish',
    '//     Command and Warning.',
    '// NO asterisk rows, dual-value rows or',
    '// footnotes ride this table (verified: the',
    '// print runs straight from the 91-00 Wings',
    '// of Flying row to the TABLE (III.E.)',
    '// Special artifacts table).',
    '// The row identity is the 35 die bands of',
    '// the engine III.E.5 table (dm/treasure.cpp',
    '// kMisc5 order, the Robe of the Archmagi',
    '// 01 through the Wings of Flying 91-00).',
    '// The row VALUES were pinned by the R122',
    '// line-diff audit; this header pins the',
    '// class marks and the band edges.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int m5RowCount() {',
    '    // the Archmagi through the Wings of Flying',
    '    return 35;',
    '}',
    '',
    'inline int m5RowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        1, 2, 9, 10, 11, 12, 20, 26, 28, 32,',
    '        33, 34, 35, 36, 39, 41, 47, 48, 49, 51,',
    '        53, 55, 58, 59, 61, 67, 68, 69, 70, 77,',
    '        79, 84, 86, 88, 91,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m5RowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        1, 8, 9, 10, 11, 19, 25, 27, 31, 32,',
    '        33, 34, 35, 38, 40, 46, 47, 48, 50, 52,',
    '        54, 57, 58, 60, 66, 67, 68, 69, 76, 78,',
    '        83, 85, 87, 90, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m5UsableByCleric(int i) {',
    '    // the (C) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 1, 0, 1, 0, 0, 0, 0, 1, 0,',
    '        1, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m5UsableByFighter(int i) {',
    '    // the (F) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 1, 0, 0, 0, 0, 1, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 1, 1,',
    '        1, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m5UsableByMagicUser(int i) {',
    '    // the (M) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        1, 0, 1, 1, 1, 1, 0, 0, 0, 0,',
    '        1, 0, 0, 0, 0, 0, 0, 1, 0, 0,',
    '        0, 0, 1, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m5UsableByThief(int i) {',
    '    // the (T) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,',
    '        1, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m5ClericCount() {',
    '    return 5;',
    '}',
    '',
    'inline int m5FighterCount() {',
    '    return 5;',
    '}',
    '',
    'inline int m5MagicUserCount() {',
    '    return 8;',
    '}',
    '',
    'inline int m5ThiefCount() {',
    '    return 2;',
    '}',
    '',
    '}  // namespace rules',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/miscmagic4.h"  // R238: p.129-130 the misc table 4 pins',
]
inc_new = [
    '#include "rules/miscmagic4.h"  // R238: p.129-130 the misc table 4 pins',
    '#include "rules/miscmagic5.h"  // R239: p.130 the misc table 5 pins',
]

# ---- the R239 audit ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R239: the III.E table 5 pins audit ----',
    '    // DMG p.130: the class marks of TABLE',
    '    // (III.E.) 5 - no asterisk rows, dual-value',
    '    // rows or footnotes ride this table.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 35 die bands',
    '        if (rules::m5RowCount() != 35) ++bad;',
    '        static const int kLo[35] = {',
    '            1, 2, 9, 10, 11, 12, 20, 26, 28, 32,',
    '            33, 34, 35, 36, 39, 41, 47, 48, 49, 51,',
    '            53, 55, 58, 59, 61, 67, 68, 69, 70, 77,',
    '            79, 84, 86, 88, 91,',
    '        };',
    '        static const int kHi[35] = {',
    '            1, 8, 9, 10, 11, 19, 25, 27, 31, 32,',
    '            33, 34, 35, 38, 40, 46, 47, 48, 50, 52,',
    '            54, 57, 58, 60, 66, 67, 68, 69, 76, 78,',
    '            83, 85, 87, 90, 100,',
    '        };',
    '        static const int kC[35] = {',
    '            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 1, 0, 1, 0, 0, 0, 0, 1, 0,',
    '            1, 0, 0, 0, 0,',
    '        };',
    '        static const int kF[35] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 1, 0, 0, 0, 0, 1, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,',
    '            1, 0, 0, 0, 0,',
    '        };',
    '        static const int kM[35] = {',
    '            1, 0, 1, 1, 1, 1, 0, 0, 0, 0,',
    '            1, 0, 0, 0, 0, 0, 0, 1, 0, 0,',
    '            0, 0, 1, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0,',
    '        };',
    '        static const int kT[35] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 1, 0,',
    '            1, 0, 0, 0, 0,',
    '        };',
    '        for (int i = 0; i < 35; ++i)',
    '            if (rules::m5RowLo(i) != kLo[i] ||',
    '                rules::m5RowHi(i) != kHi[i] ||',
    '                rules::m5UsableByCleric(i) != kC[i] ||',
    '                rules::m5UsableByFighter(i) != kF[i] ||',
    '                rules::m5UsableByMagicUser(i) != kM[i] ||',
    '                rules::m5UsableByThief(i) != kT[i])',
    '                ++bad;',
    '        for (int i = 1; i < 35; ++i)',
    '            if (rules::m5RowLo(i) !=',
    '                rules::m5RowHi(i - 1) + 1) ++bad;',
    '        if (rules::m5RowLo(-5) != 1 ||',
    '            rules::m5RowHi(99) != 100) ++bad;',
    '        // the class marks: the five Robes, the',
    '        // Rug, the Sphere and the Sphere',
    '        // Talisman are (M); the Scintillating',
    '        // Robe, the two Talismans and the two',
    '        // command/warning Tridents are (C); the',
    '        // Saw, the Spade, the Submission',
    '        // Trident and the command/warning',
    '        // Tridents are (F); the command/warning',
    '        // Tridents are (T)',
    '        if (rules::m5ClericCount() != 5 ||',
    '            rules::m5FighterCount() != 5 ||',
    '            rules::m5MagicUserCount() != 8 ||',
    '            rules::m5ThiefCount() != 2) ++bad;',
    '        if (!rules::m5UsableByMagicUser(0) ||',
    '            rules::m5UsableByCleric(0)) ++bad;',
    '        if (rules::m5UsableByMagicUser(1) ||',
    '            rules::m5UsableByCleric(1) ||',
    '            rules::m5UsableByFighter(1) ||',
    '            rules::m5UsableByThief(1)) ++bad;',
    '        if (!rules::m5UsableByMagicUser(2) ||',
    '            !rules::m5UsableByMagicUser(3) ||',
    '            !rules::m5UsableByMagicUser(5)) ++bad;',
    '        if (!rules::m5UsableByCleric(4) ||',
    '            !rules::m5UsableByMagicUser(4)) ++bad;',
    '        if (!rules::m5UsableByMagicUser(10) ||',
    '            !rules::m5UsableByFighter(11) ||',
    '            rules::m5UsableByCleric(12)) ++bad;',
    '        if (!rules::m5UsableByFighter(16) ||',
    '            !rules::m5UsableByMagicUser(17)) ++bad;',
    '        if (!rules::m5UsableByCleric(21) ||',
    '            !rules::m5UsableByMagicUser(22) ||',
    '            !rules::m5UsableByCleric(23) ||',
    '            rules::m5UsableByCleric(24)) ++bad;',
    '        if (rules::m5UsableByCleric(25) ||',
    '            rules::m5UsableByCleric(26) ||',
    '            rules::m5UsableByCleric(27)) ++bad;',
    '        if (!rules::m5UsableByCleric(28) ||',
    '            !rules::m5UsableByFighter(28) ||',
    '            !rules::m5UsableByThief(28) ||',
    '            !rules::m5UsableByCleric(30) ||',
    '            !rules::m5UsableByFighter(30) ||',
    '            !rules::m5UsableByThief(30)) ++bad;',
    '        if (!rules::m5UsableByFighter(29) ||',
    '            rules::m5UsableByCleric(29) ||',
    '            rules::m5UsableByThief(29)) ++bad;',
    '        if (rules::m5UsableByCleric(31) ||',
    '            rules::m5UsableByFighter(31) ||',
    '            rules::m5UsableByThief(31)) ++bad;',
    '        // clamped reads land on the (M) Robe of',
    '        // the Archmagi below and the unmarked',
    '        // Wings of Flying above',
    '        if (!rules::m5UsableByMagicUser(-99) ||',
    '            rules::m5UsableByCleric(99) ||',
    '            rules::m5UsableByFighter(99) ||',
    '            rules::m5UsableByThief(99)) ++bad;',
    '        printf("R239 misc table 5 pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'marks, DMG p.130, upload lines ~9898+),',
    'or the next un-pinned III.A-H',
    'surrounding prose seam.',
]
gap_new = [
    'marks, DMG p.130, upload lines ~9898+),',
    'or the next un-pinned III.A-H',
    'surrounding prose seam.',
    '',
    'R239 landed the III.E table 5 footnote',
    'pins (DMG p.130, upload lines ~9898-9915)',
    '- the class marks that frame TABLE',
    '(III.E.) 5, the LAST of the miscellaneous',
    'magic sub-tables. rules/miscmagic5.h (the',
    'grenade.h pattern), keyed to the 35 die',
    'bands of the engine III.E.5 table in',
    'kMisc5 order: the (M) marks (the Robe of',
    'the Archmagi, Robe of Eyes, Robe of',
    'Powerlessness, Robe of Scintillating',
    'Colors with C, Robe of Useful Items, Rug',
    'of Welcome, Sphere of Annihilation,',
    'Talisman of the Sphere - count 8); the',
    '(C) marks (the Robe of Scintillating',
    'Colors with M, the Talismans of Pure',
    'Good and Ultimate Evil, the Tridents of',
    'Fish Command and Warning - count 5);',
    'the (F) marks (the Saw of Mighty Cutting,',
    'the Spade of Colossal Excavation, the',
    'Trident of Submission, the command/',
    'warning Tridents - count 5); the (T)',
    'marks (the Tridents of Fish Command and',
    'Warning - count 2). VERIFIED: NO asterisk',
    'rows, dual-value rows or footnotes ride',
    'this table - the print runs straight from',
    'the 91-00 Wings of Flying row to the',
    'TABLE (III.E.) Special artifacts table',
    '(a pure class-marks round, the R224 rods',
    'shape). The row VALUES were already',
    'pinned by the R122 line-diff audit; this',
    'round pins the class marks and the band',
    'edges. New R239 battery audit; census',
    '158. Next: R240 - the III.E Special',
    'artifacts table pins (the artifact names',
    'and the printed g.p. sale values, the',
    'no-x.p. convention, DMG p.130-131,',
    'upload lines ~9917+), or the next',
    'un-pinned III.A-H surrounding prose seam.',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson)
marker = 'R239: the III.E table 5 footnote pins'
try:
    t = open(MM5).read()
    if marker in t:
        already += 1
    else:
        print('R239 FAIL: rules/miscmagic5.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(MM5, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R239 audit', audit_old, audit_new),
    (GAP, 'the R239 log entry', gap_old, gap_new),
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
        print('R239 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 158:
        print('R239 FAIL: census is not 158')
        sys.exit(1)
    if t.count('R239 misc table 5 pins audit') != 1:
        print('R239 FAIL: the R239 audit line must appear once')
        sys.exit(1)
    if t.count('rules/miscmagic5.h') != 1:
        print('R239 FAIL: the miscmagic5 include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R239 landed the III.E table 5 footnote') != 1:
        print('R239 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(MM5).read()
    if 'namespace rules' not in h or h.count('inline int m5') != 11:
        print('R239 FAIL: the header shape is wrong')
        sys.exit(1)

print('R239 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R239 note: 4 patches; the III.E table 5 footnote pins landed -')
print('the class marks; the III.E sub-tables are complete; census 158.')
print('commit: R239: the III.E table 5 footnote pins pinned - DMG p.130, the class marks (census 158)')

