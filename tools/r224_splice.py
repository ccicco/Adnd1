#!/usr/bin/env python3
# R224 splice: the III.D rods/staves/wands
# footnote pins - DMG pp.127-128, the
# class-usable marks ((C) cleric, (M)
# magic-user, (F) fighter, (T) thief,
# (any) any class unless otherwise
# prohibited) and the column-header
# asterisk (the x.p. and g.p. values
# assume FULL charges are in the item)
# that frame the III.D RODS, STAVES, &
# WANDS table. Keyed to the 30 die bands
# of the engine III.D table; the row
# VALUES were already pinned by R122.
# Patches: 4 (new rules/rodswands.h,
# regtest include, audit block,
# gap-report log entry). Census 139 -> 140.

BS = chr(92)
NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique;
    # old = None means the new-file form
    global applied, already
    try:
        t = rd(path)
    except IOError:
        # the file does not exist: create it
        assert old is None, 'anchor patch on absent file: ' + marker
        assert marker in new, 'marker missing in new file: ' + marker
        wr(path, new)
        applied += 1
        return
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/rodswands.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/rodswands.h',
    '// R224: the III.D rods/staves/wands',
    '// footnote pins (DMG pp.127-128) - the',
    '// class-usable marks and the',
    '// full-charges asterisk that frame the',
    '// III.D RODS, STAVES, & WANDS table:',
    '//   - (C) usable by the cleric class',
    '//     only; (M) magic-user only; (F)',
    '//     fighter only; (T) thief only;',
    '//     (any) usable by any class unless',
    '//     otherwise prohibited.',
    '//   - The column-header asterisk: both',
    '//     the x.p. and g.p. values assume',
    '//     FULL charges are in the item.',
    '// The row identity is the 30 die bands',
    '// of the engine III.D table',
    '// (dm/treasure.cpp kRods order, Rod of',
    '// Absorption 01-03 through Wand of',
    '// Wonder 95-00). The row VALUES were',
    '// pinned by the R122 line-diff audit;',
    '// this header pins the class marks',
    '// and the band edges. JUDGMENT, named',
    '// in place: the (any) rows carry no',
    '// individual class marks - the any flag',
    '// and the four class flags are',
    '// mutually exclusive per row.',
    '// Pure data + helpers, header-only',
    '// (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int rswRowCount() {',
    '    // Absorption through Wand of Wonder',
    '    return 30;',
    '}',
    '',
    'inline int rswRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        1, 4, 5, 15, 17, 18, 19, 20, 21, 23,',
    '        24, 25, 28, 32, 34, 35, 39, 42, 45, 48,',
    '        53, 57, 60, 69, 74, 79, 87, 90, 93, 95,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rswRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        3, 4, 14, 16, 17, 18, 19, 20, 22, 23,',
    '        24, 27, 31, 33, 34, 38, 41, 44, 47, 52,',
    '        56, 59, 68, 73, 78, 86, 89, 92, 94, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rswUsableByCleric(int i) {',
    '    // the (C) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        1, 1, 0, 0, 1, 0, 1, 1, 1, 0,',
    '        0, 1, 1, 1, 0, 0, 1, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rswUsableByMagicUser(int i) {',
    '    // the (M) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        1, 1, 0, 0, 0, 0, 0, 1, 0, 1,',
    '        1, 0, 1, 0, 1, 0, 1, 1, 1, 0,',
    '        1, 1, 0, 0, 0, 0, 1, 1, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rswUsableByFighter(int i) {',
    '    // the (F) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        0, 0, 0, 1, 0, 0, 1, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rswUsableByThief(int i) {',
    '    // the (T) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        0, 1, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rswAnyClass(int i) {',
    '    // the (any) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        0, 0, 1, 0, 0, 1, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 1, 0, 0, 0, 1,',
    '        0, 0, 1, 1, 1, 1, 0, 0, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rswFullChargesAssumed() {',
    '    // the column-header asterisk: the',
    '    // x.p. and g.p. values assume full',
    '    // charges are in the item',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
    ''
]
hdr = NL.join(hdr_lines) + NL

patch('rules/rodswands.h',
      'R224: the III.D rods/staves/wands',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/rings.h"  // R223: p.127 the rings footnote pins'

new2 = ('#include "rules/rings.h"  // R223: p.127 the rings footnote pins'
        + NL + '#include "rules/rodswands.h"  // R224: pp.127-128 the rods/staves/wands pins')

patch('regtest.cpp',
      'R224: pp.127-128 the rods/staves/wands pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R224 audit block
# ---------------------------------------------------------------------------

audit_lines = [
    '    // ---- R224: the III.D rods/staves/wands pins audit ----',
    '    // DMG pp.127-128: the class-usable',
    '    // marks and the full-charges asterisk.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 30 die bands',
    '        if (rules::rswRowCount() != 30) ++bad;',
    '        static const int kLo[30] = {',
    '            1, 4, 5, 15, 17, 18, 19, 20, 21, 23,',
    '            24, 25, 28, 32, 34, 35, 39, 42, 45, 48,',
    '            53, 57, 60, 69, 74, 79, 87, 90, 93, 95,',
    '        };',
    '        static const int kHi[30] = {',
    '            3, 4, 14, 16, 17, 18, 19, 20, 22, 23,',
    '            24, 27, 31, 33, 34, 38, 41, 44, 47, 52,',
    '            56, 59, 68, 73, 78, 86, 89, 92, 94, 100,',
    '        };',
    '        static const int kC[30] = {',
    '            1, 1, 0, 0, 1, 0, 1, 1, 1, 0,',
    '            0, 1, 1, 1, 0, 0, 1, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kM[30] = {',
    '            1, 1, 0, 0, 0, 0, 0, 1, 0, 1,',
    '            1, 0, 1, 0, 1, 0, 1, 1, 1, 0,',
    '            1, 1, 0, 0, 0, 0, 1, 1, 0, 0,',
    '        };',
    '        static const int kF[30] = {',
    '            0, 0, 0, 1, 0, 0, 1, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kT[30] = {',
    '            0, 1, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kAny[30] = {',
    '            0, 0, 1, 0, 0, 1, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 1, 0, 0, 0, 1,',
    '            0, 0, 1, 1, 1, 1, 0, 0, 1, 1,',
    '        };',
    '        for (int i = 0; i < 30; ++i)',
    '            if (rules::rswRowLo(i) != kLo[i] ||',
    '                rules::rswRowHi(i) != kHi[i] ||',
    '                rules::rswUsableByCleric(i) != kC[i] ||',
    '                rules::rswUsableByMagicUser(i) != kM[i] ||',
    '                rules::rswUsableByFighter(i) != kF[i] ||',
    '                rules::rswUsableByThief(i) != kT[i] ||',
    '                rules::rswAnyClass(i) != kAny[i]) ++bad;',
    '        for (int i = 1; i < 30; ++i)',
    '            if (rules::rswRowLo(i) !=',
    '                rules::rswRowHi(i - 1) + 1) ++bad;',
    '        if (rules::rswRowLo(-5) != 1 ||',
    '            rules::rswRowHi(99) != 100) ++bad;',
    '        // every row: the any flag excludes',
    '        // the class marks, and a non-any row',
    '        // carries at least one class mark',
    '        for (int i = 0; i < 30; ++i)',
    '            if (rules::rswAnyClass(i) &&',
    '                (rules::rswUsableByCleric(i) ||',
    '                 rules::rswUsableByMagicUser(i) ||',
    '                 rules::rswUsableByFighter(i) ||',
    '                 rules::rswUsableByThief(i))) ++bad;',
    '        for (int i = 0; i < 30; ++i)',
    '            if (!rules::rswAnyClass(i) &&',
    '                !rules::rswUsableByCleric(i) &&',
    '                !rules::rswUsableByMagicUser(i) &&',
    '                !rules::rswUsableByFighter(i) &&',
    '                !rules::rswUsableByThief(i)) ++bad;',
    '        // the famous rows: Absorption (C, M),',
    '        // Beguiling (C, M, T), Cancellation',
    '        // (any), Lordly Might (F), Smiting',
    '        // (C, F), the Magi (M), Wonder (any)',
    '        if (!rules::rswUsableByCleric(0) ||',
    '            !rules::rswUsableByMagicUser(0) ||',
    '            rules::rswAnyClass(0)) ++bad;',
    '        if (!rules::rswUsableByThief(1)) ++bad;',
    '        if (!rules::rswAnyClass(2) ||',
    '            rules::rswUsableByCleric(2)) ++bad;',
    '        if (!rules::rswUsableByFighter(3) ||',
    '            rules::rswUsableByCleric(3) ||',
    '            rules::rswUsableByMagicUser(3)) ++bad;',
    '        if (!rules::rswUsableByCleric(6) ||',
    '            !rules::rswUsableByFighter(6)) ++bad;',
    '        if (!rules::rswUsableByMagicUser(9) ||',
    '            rules::rswUsableByCleric(9)) ++bad;',
    '        if (!rules::rswAnyClass(29) ||',
    '            rules::rswUsableByThief(29)) ++bad;',
    '        // clamped flag reads land on',
    '        // Absorption (C, M) and Wonder (any)',
    '        if (!rules::rswUsableByCleric(-99) ||',
    '            rules::rswAnyClass(-99) ||',
    '            rules::rswUsableByCleric(99) ||',
    '            !rules::rswAnyClass(99)) ++bad;',
    '        // the full-charges asterisk',
    '        if (!rules::rswFullChargesAssumed()) ++bad;',
    '        printf("R224 rods staves wands pins audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    ''
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R224: the III.D rods/staves/wands pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
    'R224 landed the III.D rods/staves/wands',
    'footnote pins (DMG pp.127-128, upload',
    'lines ~9625-9658) - the class-usable',
    'marks and the full-charges asterisk that',
    'frame the III.D RODS, STAVES, & WANDS',
    'table. rules/rodswands.h (the grenade.h',
    'pattern), keyed to the 30 die bands of the',
    'engine III.D table in kRods order: the (C)',
    'cleric-only, (M) magic-user-only, (F)',
    'fighter-only, (T) thief-only and (any)',
    'any-class marks (10 any rows, 10 cleric,',
    '14 magic-user, 2 fighter, 1 thief -',
    'Beguiling the only (T); Lordly Might the',
    'only (F); Smiting the (C, F); Absorption,',
    'Command, Striking and Fear the (C, M)',
    'rows; the staves Curing, the Magi, Power,',
    'the Serpent, Withering per the print),',
    'and the column-header asterisk: both the',
    'x.p. and g.p. values assume FULL charges',
    'are in the item. JUDGMENT: the (any) rows',
    'carry no individual class marks - the any',
    'flag and the four class flags are mutually',
    'exclusive per row, verified both ways in',
    'the audit. The row VALUES were already',
    'pinned by the R122 line-diff audit; this',
    'round pins the class marks and the band',
    'edges. New R224 battery audit; census 140.',
    'Next: R225 - the III.E miscellaneous magic',
    'table 1 class marks and footnotes (DMG',
    'p.128, upload lines ~9665+), or the next',
    'un-pinned III.A-H surrounding prose seam.'
]
log_entry = NL.join(log_lines)

old4 = 'Categories:'

new4 = (log_entry + NL + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R224 landed the III.D rods/staves/wands',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R224 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R224 note: 4 patches; the III.D rods/staves/wands pins landed -')
print('the class marks and the full-charges asterisk; census 140.')
print('commit: R224: the III.D rods/staves/wands footnote pins pinned - DMG')
print('pp.127-128, the class marks and full-charges asterisk (census 140)')

