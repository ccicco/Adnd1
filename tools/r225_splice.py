#!/usr/bin/env python3
# R225 splice: the III.E table 1 footnote
# pins - DMG p.128, the class marks and
# special rows that frame TABLE (III.E.) 1:
# the (C) marks (the two Books), the (M)
# marks (the two Bowls, the two Braziers),
# the Artifact or Relic row (see the
# Special table), the Bracers of Defense
# per-AC-point asterisk (AC 6 = 2,000 x.p. /
# 12,000 g.p.), and Bucknard Everfull Purse
# as the tiered-values row. Keyed to the 33
# die bands of the engine III.E.1 table;
# the row VALUES were already pinned by
# R122. Patches: 4 (new rules/miscmagic1.h,
# regtest include, audit block, gap-report
# log entry). Census 140 -> 141.

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
# Patch 1: rules/miscmagic1.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/miscmagic1.h',
    '// R225: the III.E table 1 footnote pins',
    '// (DMG p.128) - the class marks and the',
    '// special-row footnotes that frame the',
    '// TABLE (III.E.) 1 miscellaneous magic',
    '// table:',
    '//   - the (C) and (M) class marks',
    '//     (Book of Exalted Deeds and Book',
    '//     of Vile Darkness are (C); the two',
    '//     Bowls and the two Braziers are',
    '//     (M)).',
    '//   - the Artifact or Relic row (17):',
    '//     no values - see the Special table',
    '//     hereafter.',
    '//   - the Bracers of Defense asterisk',
    '//     (60-79): the x.p. and g.p. values',
    '//     are PER ARMOR CLASS POINT above',
    '//     10 (AC 6 is worth 2,000 x.p.,',
    '//     12,000 g.p. if sold - four',
    '//     points).',
    '//   - Bucknard Everfull Purse (99-00):',
    '//     the printed tiered values',
    '//     (1,500/2,500/4,000 x.p.;',
    '//     15,000/25,000/40,000 g.p.) are',
    '//     carried by the R122-pinned row',
    '//     ranges.',
    '// The row identity is the 33 die bands',
    '// of the engine III.E.1 table',
    '// (dm/treasure.cpp kMisc1 order,',
    '// Alchemy Jug 01-02 through Bucknard',
    '// Everfull Purse 99-00). The row VALUES',
    '// were pinned by the R122 line-diff',
    '// audit; this header pins the class',
    '// marks, the special rows and the band',
    '// edges. JUDGMENT: the R122 row for the',
    '// purse pins xp 1500-4000 / gp',
    '// 15000-40000, matching the printed',
    '// tiers as ranges.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int m1RowCount() {',
    '    // Alchemy Jug through the Everfull Purse',
    '    return 33;',
    '}',
    '',
    'inline int m1RowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        1, 3, 5, 6, 8, 12, 14, 17, 18, 21,',
    '        22, 27, 28, 30, 32, 33, 34, 35, 36, 37,',
    '        43, 48, 52, 56, 59, 60, 80, 82, 85, 86,',
    '        93, 94, 99,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m1RowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        2, 4, 5, 7, 11, 13, 16, 17, 20, 21,',
    '        26, 27, 29, 31, 32, 33, 34, 35, 36, 42,',
    '        47, 51, 55, 58, 59, 79, 81, 84, 85, 92,',
    '        93, 98, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m1UsableByMagicUser(int i) {',
    '    // the (M) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 1, 1, 0, 0, 1, 1, 0,',
    '        0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m1UsableByCleric(int i) {',
    '    // the (C) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 1, 0, 1, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m1IsArtifactRelicRow(int i) {',
    '    // the Artifact or Relic row (see the Special table); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        0, 0, 0, 0, 0, 0, 0, 1, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m1IsPerAcPointValued(int i) {',
    '    // the Bracers of Defense asterisk row; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '        0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m1IsTieredPurseRow(int i) {',
    '    // the Bucknard Everfull Purse tiered-values row; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 32) i = 32;',
    '    static const int t[33] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m1MagicUserCount() {',
    '    return 4;',
    '}',
    '',
    'inline int m1ClericCount() {',
    '    return 2;',
    '}',
    '',
    'inline int m1BracersPerAcXp() {',
    '    // per armor class point above 10',
    '    return 500;',
    '}',
    '',
    'inline int m1BracersPerAcGp() {',
    '    return 3000;',
    '}',
    '',
    '}  // namespace rules',
    ''
]
hdr = NL.join(hdr_lines) + NL

patch('rules/miscmagic1.h',
      'R225: the III.E table 1 footnote pins',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/rodswands.h"  // R224: pp.127-128 the rods/staves/wands pins'

new2 = ('#include "rules/rodswands.h"  // R224: pp.127-128 the rods/staves/wands pins'
        + NL + '#include "rules/miscmagic1.h"  // R225: p.128 the misc table 1 pins')

patch('regtest.cpp',
      'R225: p.128 the misc table 1 pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R225 audit block
# ---------------------------------------------------------------------------

audit_lines = [
    '    // ---- R225: the III.E table 1 pins audit ----',
    '    // DMG p.128: the class marks and the',
    '    // special rows of TABLE (III.E.) 1.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 33 die bands',
    '        if (rules::m1RowCount() != 33) ++bad;',
    '        static const int kLo[33] = {',
    '            1, 3, 5, 6, 8, 12, 14, 17, 18, 21,',
    '            22, 27, 28, 30, 32, 33, 34, 35, 36, 37,',
    '            43, 48, 52, 56, 59, 60, 80, 82, 85, 86,',
    '            93, 94, 99,',
    '        };',
    '        static const int kHi[33] = {',
    '            2, 4, 5, 7, 11, 13, 16, 17, 20, 21,',
    '            26, 27, 29, 31, 32, 33, 34, 35, 36, 42,',
    '            47, 51, 55, 58, 59, 79, 81, 84, 85, 92,',
    '            93, 98, 100,',
    '        };',
    '        static const int kM[33] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 1, 1, 0, 0, 1, 1, 0,',
    '            0, 0, 0,',
    '        };',
    '        static const int kC[33] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 1, 0, 1, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0,',
    '        };',
    '        static const int kArt[33] = {',
    '            0, 0, 0, 0, 0, 0, 0, 1, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0,',
    '        };',
    '        static const int kBrac[33] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '            0, 0, 0,',
    '        };',
    '        static const int kPurse[33] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 1,',
    '        };',
    '        for (int i = 0; i < 33; ++i)',
    '            if (rules::m1RowLo(i) != kLo[i] ||',
    '                rules::m1RowHi(i) != kHi[i] ||',
    '                rules::m1UsableByMagicUser(i) != kM[i] ||',
    '                rules::m1UsableByCleric(i) != kC[i] ||',
    '                rules::m1IsArtifactRelicRow(i) != kArt[i] ||',
    '                rules::m1IsPerAcPointValued(i) != kBrac[i] ||',
    '                rules::m1IsTieredPurseRow(i) != kPurse[i])',
    '                ++bad;',
    '        for (int i = 1; i < 33; ++i)',
    '            if (rules::m1RowLo(i) !=',
    '                rules::m1RowHi(i - 1) + 1) ++bad;',
    '        if (rules::m1RowLo(-5) != 1 ||',
    '            rules::m1RowHi(99) != 100) ++bad;',
    '        // the class marks: the two Books',
    '        // are (C); the Bowls and Braziers',
    '        // are (M)',
    '        if (rules::m1MagicUserCount() != 4 ||',
    '            rules::m1ClericCount() != 2) ++bad;',
    '        if (!rules::m1UsableByCleric(15) ||',
    '            !rules::m1UsableByCleric(17) ||',
    '            rules::m1UsableByCleric(16)) ++bad;',
    '        if (!rules::m1UsableByMagicUser(23) ||',
    '            !rules::m1UsableByMagicUser(24) ||',
    '            !rules::m1UsableByMagicUser(27) ||',
    '            !rules::m1UsableByMagicUser(28) ||',
    '            rules::m1UsableByMagicUser(22)) ++bad;',
    '        // the special rows: Artifact or',
    '        // Relic 17, Bracers 60-79, the',
    '        // Purse 99-00',
    '        if (!rules::m1IsArtifactRelicRow(7) ||',
    '            rules::m1IsArtifactRelicRow(6)) ++bad;',
    '        if (!rules::m1IsPerAcPointValued(26) ||',
    '            rules::m1IsPerAcPointValued(27)) ++bad;',
    '        if (!rules::m1IsTieredPurseRow(32) ||',
    '            rules::m1IsTieredPurseRow(31)) ++bad;',
    '        // the Bracers asterisk: per AC',
    '        // point above 10 - AC 6 (four',
    '        // points) is 2,000 x.p. / 12,000 gp',
    '        if (rules::m1BracersPerAcXp() != 500 ||',
    '            rules::m1BracersPerAcGp() != 3000 ||',
    '            rules::m1BracersPerAcXp() * 4 != 2000 ||',
    '            rules::m1BracersPerAcGp() * 4 != 12000)',
    '            ++bad;',
    '        // clamped flag reads land on the',
    '        // Alchemy Jug (unmarked) and the',
    '        // Purse (tiered)',
    '        if (rules::m1UsableByMagicUser(-99) ||',
    '            rules::m1UsableByCleric(-99) ||',
    '            !rules::m1IsTieredPurseRow(99)) ++bad;',
    '        printf("R225 misc table 1 pins audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    ''
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R225: the III.E table 1 pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
    'R225 landed the III.E table 1 footnote',
    'pins (DMG p.128, upload lines ~9674-9722)',
    '- the class marks and special rows that',
    'frame TABLE (III.E.) 1. rules/miscmagic1.h',
    '(the grenade.h pattern), keyed to the 33',
    'die bands of the engine III.E.1 table in',
    'kMisc1 order: the (C) marks (Book of',
    'Exalted Deeds, Book of Vile Darkness)',
    'and the (M) marks (Bowl Commanding',
    'Water Elementals, Bowl of Watery Death,',
    'Brazier Commanding Fire Elementals,',
    'Brazier of Sleep Smoke); the Artifact',
    'or Relic row (17, no values - see the',
    'Special table hereafter); the Bracers of',
    'Defense asterisk (60-79: the x.p. and',
    'g.p. values are PER ARMOR CLASS POINT',
    'above 10 - AC 6 worth 2,000 x.p. /',
    '12,000 g.p., four points); and Bucknard',
    'Everfull Purse (99-00) as the tiered-',
    'values row (the R122-pinned 1500-4000 /',
    '15000-40000 ranges match the printed',
    '1,500/2,500/4,000 tiers). The row VALUES',
    'were already pinned by the R122 line-diff',
    'audit; this round pins the class marks,',
    'the special rows and the band edges.',
    'New R225 battery audit; census 141.',
    'Next: R226 - the III.E table 2 class',
    'marks and the Cloak of Protection and',
    'Crystal Ball asterisk/notes (DMG p.128,',
    'upload lines ~9724-9760), or the next',
    'un-pinned III.A-H surrounding prose seam.'
]
log_entry = NL.join(log_lines)

old4 = 'Categories:'

new4 = (log_entry + NL + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R225 landed the III.E table 1 footnote',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R225 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R225 note: 4 patches; the III.E table 1 footnote pins landed -')
print('the class marks and special rows; census 141.')
print('commit: R225: the III.E table 1 footnote pins pinned - DMG p.128,')
print('the class marks and the special rows (census 141)')

