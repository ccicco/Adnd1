#!/usr/bin/env python3
# R223 splice: the III.C rings footnote
# pins - DMG p.127, the two footnotes that
# frame the III.C RINGS table: the
# double-dagger charge-limited rings
# (Djinni Summoning, Human Influence,
# Mammal Control, Multiple Wishes,
# Telekinesis, Three Wishes, Wizardry - the
# most powerful magical abilities, possibly
# a limited number of charges, at the DM
# option) and the (M) magic-user-only ring
# (Wizardry). JUDGMENT: Wizardry prints
# BOTH marks. Keyed to the 24 die bands of
# the engine III.C table; the row VALUES
# were already pinned by R122. Patches: 4
# (new rules/rings.h, regtest include,
# audit block, gap-report log entry).
# Census 138 -> 139.

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
# Patch 1: rules/rings.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/rings.h',
    '// R223: the III.C rings footnote pins',
    '// (DMG p.127) - the two footnotes that',
    '// frame the III.C RINGS table:',
    '//   - the (M) ring: magic-user use',
    '//     only (Ring of Wizardry).',
    '//   - the double-dagger rings: these',
    '//     contain the most powerful magical',
    '//     abilities and may possess only a',
    '//     limited number of magical charges',
    '//     before being depleted, at the DM',
    '//     option (Djinni Summoning, Human',
    '//     Influence, Mammal Control,',
    '//     Multiple Wishes, Telekinesis,',
    '//     Three Wishes, and Wizardry -',
    '//     seven rings).',
    '// The row identity is the 24 die bands',
    '// of the engine III.C table',
    '// (dm/treasure.cpp kRings order,',
    '// Contrariness 01-06 through X-Ray',
    '// Vision 00). The row VALUES were',
    '// pinned by the R122 line-diff audit;',
    '// this header pins the footnote flags',
    '// and the band edges. JUDGMENT, named',
    '// in place: Ring of Wizardry prints',
    '// BOTH the double-dagger and the (M);',
    '// both flags are set.',
    '// Pure data + helpers, header-only',
    '// (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int ringRowCount() {',
    '    // Contrariness through X-Ray Vision',
    '    return 24;',
    '}',
    '',
    'inline int ringRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    static const int t[24] = {',
    '        1, 7, 13, 15, 16, 22, 28, 31, 34, 41,',
    '        44, 45, 61, 62, 64, 66, 70, 76, 78, 80,',
    '        86, 91, 99, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int ringRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    static const int t[24] = {',
    '        6, 12, 14, 15, 21, 27, 30, 33, 40, 43,',
    '        44, 60, 61, 63, 65, 69, 75, 77, 79, 85,',
    '        90, 98, 99, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int ringIsMuOnly(int i) {',
    '    // the (M) mark: magic-user use only; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    static const int t[24] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 1, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int ringMuOnlyCount() {',
    '    return 1;',
    '}',
    '',
    'inline int ringIsChargeLimited(int i) {',
    '    // the double-dagger charge-limited rows; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    static const int t[24] = {',
    '        0, 0, 1, 0, 0, 0, 0, 1, 0, 0,',
    '        1, 1, 0, 0, 0, 0, 0, 1, 1, 0,',
    '        0, 0, 1, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int ringChargeLimitedCount() {',
    '    // Djinni Summoning, Human Influence,',
    '    // Mammal Control, Multiple Wishes,',
    '    // Telekinesis, Three Wishes, Wizardry',
    '    return 7;',
    '}',
    '',
    '}  // namespace rules',
    ''
]
hdr = NL.join(hdr_lines) + NL

patch('rules/rings.h',
      'R223: the III.C rings footnote pins',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/scrollpins.h"  // R222: pp.126-127 the scrolls prose pins'

new2 = ('#include "rules/scrollpins.h"  // R222: pp.126-127 the scrolls prose pins'
        + NL + '#include "rules/rings.h"  // R223: p.127 the rings footnote pins')

patch('regtest.cpp',
      'R223: p.127 the rings footnote pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R223 audit block
# ---------------------------------------------------------------------------

audit_lines = [
    '    // ---- R223: the III.C rings footnote pins audit ----',
    '    // DMG p.127: the (M) magic-user-only',
    '    // mark and the double-dagger',
    '    // charge-limited rows.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 24 die bands',
    '        if (rules::ringRowCount() != 24) ++bad;',
    '        static const int kLo[24] = {',
    '            1, 7, 13, 15, 16, 22, 28, 31, 34, 41,',
    '            44, 45, 61, 62, 64, 66, 70, 76, 78, 80,',
    '            86, 91, 99, 100,',
    '        };',
    '        static const int kHi[24] = {',
    '            6, 12, 14, 15, 21, 27, 30, 33, 40, 43,',
    '            44, 60, 61, 63, 65, 69, 75, 77, 79, 85,',
    '            90, 98, 99, 100,',
    '        };',
    '        static const int kMu[24] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 1, 0,',
    '        };',
    '        static const int kChg[24] = {',
    '            0, 0, 1, 0, 0, 0, 0, 1, 0, 0,',
    '            1, 1, 0, 0, 0, 0, 0, 1, 1, 0,',
    '            0, 0, 1, 0,',
    '        };',
    '        for (int i = 0; i < 24; ++i)',
    '            if (rules::ringRowLo(i) != kLo[i] ||',
    '                rules::ringRowHi(i) != kHi[i] ||',
    '                rules::ringIsMuOnly(i) != kMu[i] ||',
    '                rules::ringIsChargeLimited(i) != kChg[i])',
    '                ++bad;',
    '        for (int i = 1; i < 24; ++i)',
    '            if (rules::ringRowLo(i) !=',
    '                rules::ringRowHi(i - 1) + 1) ++bad;',
    '        if (rules::ringRowLo(-5) != 1 ||',
    '            rules::ringRowHi(99) != 100) ++bad;',
    '        // the singleton rows: Djinni',
    '        // Summoning 13-14, Regeneration 61,',
    '        // Wizardry 99, X-Ray Vision 100',
    '        if (rules::ringRowLo(2) != 13 ||',
    '            rules::ringRowHi(2) != 14 ||',
    '            rules::ringRowLo(12) != 61 ||',
    '            rules::ringRowLo(22) != 99 ||',
    '            rules::ringRowHi(22) != 99 ||',
    '            rules::ringRowLo(23) != 100 ||',
    '            rules::ringRowHi(23) != 100) ++bad;',
    '        // the charge rows: the seven',
    '        // double-dagger rings',
    '        if (rules::ringChargeLimitedCount() != 7) ++bad;',
    '        if (!rules::ringIsChargeLimited(2) ||',
    '            !rules::ringIsChargeLimited(7) ||',
    '            !rules::ringIsChargeLimited(10) ||',
    '            !rules::ringIsChargeLimited(11) ||',
    '            !rules::ringIsChargeLimited(17) ||',
    '            !rules::ringIsChargeLimited(18) ||',
    '            !rules::ringIsChargeLimited(22)) ++bad;',
    '        if (rules::ringIsChargeLimited(0) ||',
    '            rules::ringIsChargeLimited(1) ||',
    '            rules::ringIsChargeLimited(3) ||',
    '            rules::ringIsChargeLimited(12) ||',
    '            rules::ringIsChargeLimited(15) ||',
    '            rules::ringIsChargeLimited(23)) ++bad;',
    '        // the (M) row: Wizardry only,',
    '        // and it is ALSO charge-limited',
    '        if (rules::ringMuOnlyCount() != 1) ++bad;',
    '        if (!rules::ringIsMuOnly(22) ||',
    '            !rules::ringIsChargeLimited(22)) ++bad;',
    '        if (rules::ringIsMuOnly(0) ||',
    '            rules::ringIsMuOnly(23)) ++bad;',
    '        // clamped flag reads land on',
    '        // Contrariness and X-Ray Vision:',
    '        // both unmarked',
    '        if (rules::ringIsChargeLimited(-99) ||',
    '            rules::ringIsChargeLimited(99) ||',
    '            rules::ringIsMuOnly(-99)) ++bad;',
    '        printf("R223 rings footnote pins audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    ''
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R223: the III.C rings footnote pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
    'R223 landed the III.C rings footnote pins',
    '(DMG p.127, upload lines ~9596-9623) - the',
    'two footnotes that frame the III.C RINGS',
    'table. rules/rings.h (the grenade.h',
    'pattern), keyed to the 24 die bands of the',
    'engine III.C table in kRings order: the',
    'double-dagger charge-limited rings (Djinni',
    'Summoning, Human Influence, Mammal',
    'Control, Multiple Wishes, Telekinesis,',
    'Three Wishes, Wizardry - these contain',
    'the most powerful magical abilities and',
    'may possess only a limited number of',
    'magical charges before being depleted,',
    'at the DM option) and the (M) ring',
    '(Wizardry: magic-user use only). JUDGMENT:',
    'Ring of Wizardry prints BOTH the',
    'double-dagger and the (M); both flags',
    'are set. The row VALUES were already',
    'pinned by the R122 line-diff audit; this',
    'round pins the footnote flags and the',
    'band edges. New R223 battery audit;',
    'census 139. Next: R224 - the III.D rods,',
    'staves and wands footnotes (the',
    'point-value asterisk, the class marks C/M/',
    'F/T/any and the charge notes, DMG',
    'pp.127-128, upload lines ~9625+), or the',
    'next un-pinned III.A-H surrounding prose',
    'seam.'
]
log_entry = NL.join(log_lines)

old4 = ('surrounding prose seam.' + NL + NL + 'Categories:')

new4 = ('surrounding prose seam.' + NL + NL + log_entry + NL
        + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R223 landed the III.C rings footnote pins',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R223 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R223 note: 4 patches; the III.C rings footnote pins landed -')
print('the charge-limited and magic-user-only marks; census 139.')
print('commit: R223: the III.C rings footnote pins pinned - DMG p.127,')
print('the charge-limited and (M) magic-user-only marks (census 139)')

