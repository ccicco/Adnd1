#!/usr/bin/env python3
# R226 splice: the III.E table 2 footnote
# pins - DMG p.128, the class marks and
# asterisk rows that frame TABLE (III.E.)
# 2: the (C) Candle of Invocation, the (M)
# Censers/Crystal Balls/Eyes of Charming,
# the Cloak of Protection per-plus values,
# the Crystal Ball feature-bonus note
# note, and the Eyes of Petrification
# triple star. Keyed to the 30 die bands
# of the engine III.E.2 table; the row
# VALUES were already pinned by R122.
# Patches: 4 (new rules/miscmagic2.h,
# regtest include, audit block, gap-report
# log entry). Census 141 -> 142.

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
# Patch 1: rules/miscmagic2.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/miscmagic2.h',
    '// R226: the III.E table 2 footnote pins',
    '// (DMG p.128) - the class marks and the',
    '// asterisk rows that frame TABLE',
    '// (III.E.) 2 of the miscellaneous magic',
    '// tables:',
    '//   - the (C) mark: Candle of',
    '//     Invocation (cleric only).',
    '//   - the (M) marks: the two Censers,',
    '//     Crystal Ball, Crystal Hypnosis',
    '//     Ball, Eyes of Charming.',
    '//   - the Cloak of Protection asterisk',
    '//     (33-55): the 1,000 x.p. / 10,000',
    '//     g.p. values are PER PLUS of',
    '//     protection.',
    '//   - the Crystal Ball double asterisk',
    '//     (56-60): add 100% for each',
    '//     additional feature (base 1,000',
    '//     x.p. / 5,000 g.p.).',
    '//   - the Eyes of Petrification triple',
    '//     asterisk (00): the print carries',
    '//     ---*** in both value columns.',
    '// The row identity is the 30 die bands',
    '// of the engine III.E.2 table',
    '// (dm/treasure.cpp kMisc2 order,',
    '// Candle of Invocation 01-06 through',
    '// Eyes of Petrification 00). The row',
    '// VALUES were pinned by the R122',
    '// line-diff audit; this header pins the',
    '// class marks, the asterisk rows and the',
    '// band edges.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int m2RowCount() {',
    '    // Candle through Eyes of Petrification',
    '    return 30;',
    '}',
    '',
    'inline int m2RowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        1, 7, 9, 11, 12, 14, 15, 19, 28, 31,',
    '        33, 56, 61, 62, 64, 66, 68, 70, 73, 77,',
    '        78, 80, 86, 92, 93, 94, 95, 96, 98, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m2RowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        6, 8, 10, 11, 13, 14, 18, 27, 30, 32,',
    '        55, 60, 61, 63, 65, 67, 69, 72, 76, 77,',
    '        79, 85, 91, 92, 93, 94, 95, 97, 99, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m2UsableByCleric(int i) {',
    '    // the (C) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m2UsableByMagicUser(int i) {',
    '    // the (M) mark; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        0, 0, 1, 1, 0, 0, 0, 0, 0, 0,',
    '        0, 1, 1, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m2IsPerPlusValued(int i) {',
    '    // the Cloak of Protection per-plus asterisk row; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m2HasFeatureAsterisk(int i) {',
    '    // the Crystal Ball double-asterisk row; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 1, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m2IsTripleStar(int i) {',
    '    // the Eyes of Petrification triple-asterisk row; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 29) i = 29;',
    '    static const int t[30] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int m2ClericCount() {',
    '    return 1;',
    '}',
    '',
    'inline int m2MagicUserCount() {',
    '    return 5;',
    '}',
    '',
    'inline int m2CloakPerPlusXp() {',
    '    // per plus of protection',
    '    return 1000;',
    '}',
    '',
    'inline int m2CloakPerPlusGp() {',
    '    return 10000;',
    '}',
    '',
    'inline int m2CrystalBallBaseXp() {',
    '    return 1000;',
    '}',
    '',
    'inline int m2CrystalBallBaseGp() {',
    '    return 5000;',
    '}',
    '',
    'inline int m2CrystalBallFeatureBonusPct() {',
    '    // add 100% for each additional',
    '    // feature',
    '    return 100;',
    '}',
    '',
    '}  // namespace rules',
    ''
]
hdr = NL.join(hdr_lines) + NL

patch('rules/miscmagic2.h',
      'R226: the III.E table 2 footnote pins',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/miscmagic1.h"  // R225: p.128 the misc table 1 pins'

new2 = ('#include "rules/miscmagic1.h"  // R225: p.128 the misc table 1 pins'
        + NL + '#include "rules/miscmagic2.h"  // R226: p.128 the misc table 2 pins')

patch('regtest.cpp',
      'R226: p.128 the misc table 2 pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R226 audit block
# ---------------------------------------------------------------------------

audit_lines = [
    '    // ---- R226: the III.E table 2 pins audit ----',
    '    // DMG p.128: the class marks and the',
    '    // asterisk rows of TABLE (III.E.) 2.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 30 die bands',
    '        if (rules::m2RowCount() != 30) ++bad;',
    '        static const int kLo[30] = {',
    '            1, 7, 9, 11, 12, 14, 15, 19, 28, 31,',
    '            33, 56, 61, 62, 64, 66, 68, 70, 73, 77,',
    '            78, 80, 86, 92, 93, 94, 95, 96, 98, 100,',
    '        };',
    '        static const int kHi[30] = {',
    '            6, 8, 10, 11, 13, 14, 18, 27, 30, 32,',
    '            55, 60, 61, 63, 65, 67, 69, 72, 76, 77,',
    '            79, 85, 91, 92, 93, 94, 95, 97, 99, 100,',
    '        };',
    '        static const int kC[30] = {',
    '            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kM[30] = {',
    '            0, 0, 1, 1, 0, 0, 0, 0, 0, 0,',
    '            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '        };',
    '        static const int kPP[30] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kFeat[30] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 1, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        };',
    '        static const int kTri[30] = {',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,',
    '        };',
    '        for (int i = 0; i < 30; ++i)',
    '            if (rules::m2RowLo(i) != kLo[i] ||',
    '                rules::m2RowHi(i) != kHi[i] ||',
    '                rules::m2UsableByCleric(i) != kC[i] ||',
    '                rules::m2UsableByMagicUser(i) != kM[i] ||',
    '                rules::m2IsPerPlusValued(i) != kPP[i] ||',
    '                rules::m2HasFeatureAsterisk(i) != kFeat[i] ||',
    '                rules::m2IsTripleStar(i) != kTri[i]) ++bad;',
    '        for (int i = 1; i < 30; ++i)',
    '            if (rules::m2RowLo(i) !=',
    '                rules::m2RowHi(i - 1) + 1) ++bad;',
    '        if (rules::m2RowLo(-5) != 1 ||',
    '            rules::m2RowHi(99) != 100) ++bad;',
    '        // the class marks: the Candle is',
    '        // (C); the Censers, the Balls and',
    '        // the Eyes of Charming are (M)',
    '        if (rules::m2ClericCount() != 1 ||',
    '            rules::m2MagicUserCount() != 5) ++bad;',
    '        if (!rules::m2UsableByCleric(0) ||',
    '            rules::m2UsableByCleric(1)) ++bad;',
    '        if (!rules::m2UsableByMagicUser(2) ||',
    '            !rules::m2UsableByMagicUser(3) ||',
    '            !rules::m2UsableByMagicUser(11) ||',
    '            !rules::m2UsableByMagicUser(12) ||',
    '            !rules::m2UsableByMagicUser(26) ||',
    '            rules::m2UsableByMagicUser(1) ||',
    '            rules::m2UsableByMagicUser(27)) ++bad;',
    '        // the asterisk rows: Cloak of',
    '        // Protection 33-55 per plus,',
    '        // Crystal Ball 56-60 the feature',
    '        // asterisk, Eyes of Petrification',
    '        // 00 the triple star',
    '        if (!rules::m2IsPerPlusValued(10) ||',
    '            rules::m2IsPerPlusValued(11)) ++bad;',
    '        if (!rules::m2HasFeatureAsterisk(11) ||',
    '            rules::m2HasFeatureAsterisk(10)) ++bad;',
    '        if (!rules::m2IsTripleStar(29) ||',
    '            rules::m2IsTripleStar(28)) ++bad;',
    '        // a +2 cloak is 2,000 x.p. /',
    '        // 20,000 g.p.',
    '        if (rules::m2CloakPerPlusXp() != 1000 ||',
    '            rules::m2CloakPerPlusGp() != 10000 ||',
    '            rules::m2CloakPerPlusXp() * 2 != 2000 ||',
    '            rules::m2CloakPerPlusGp() * 2 != 20000)',
    '            ++bad;',
    '        // a crystal ball with two extra',
    '        // features is 3,000 x.p. (base +',
    '        // 2 x 100%)',
    '        if (rules::m2CrystalBallBaseXp() != 1000 ||',
    '            rules::m2CrystalBallBaseGp() != 5000 ||',
    '            rules::m2CrystalBallFeatureBonusPct() != 100 ||',
    '            rules::m2CrystalBallBaseXp() + 2 *',
    '            (rules::m2CrystalBallBaseXp() *',
    '             rules::m2CrystalBallFeatureBonusPct() / 100)',
    '                != 3000) ++bad;',
    '        // clamped flag reads land on the',
    '        // Candle (C) and Eyes of',
    '        // Petrification (triple)',
    '        if (!rules::m2UsableByCleric(-99) ||',
    '            rules::m2UsableByMagicUser(-99) ||',
    '            !rules::m2IsTripleStar(99)) ++bad;',
    '        printf("R226 misc table 2 pins audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    ''
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R226: the III.E table 2 pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
    'R226 landed the III.E table 2 footnote',
    'pins (DMG p.128, upload lines ~9724-9760)',
    '- the class marks and asterisk rows that',
    'frame TABLE (III.E.) 2. rules/miscmagic2.h',
    '(the grenade.h pattern), keyed to the 30',
    'die bands of the engine III.E.2 table in',
    'kMisc2 order: the (C) mark (Candle of',
    'Invocation); the (M) marks (the two',
    'Censers, Crystal Ball, Crystal Hypnosis',
    'Ball, Eyes of Charming); the Cloak of',
    'Protection per-plus asterisk (33-55:',
    '1,000 x.p. / 10,000 g.p. per plus of',
    'protection - a +2 cloak is 2,000 /',
    '20,000); the Crystal Ball double',
    'asterisk (56-60: base 1,000 x.p. /',
    '5,000 g.p., add 100% for each',
    'additional feature); and the Eyes of',
    'Petrification triple asterisk (00:',
    '---*** in both value columns). The row',
    'VALUES were already pinned by the R122',
    'line-diff audit; this round pins the',
    'class marks, the asterisk rows and the',
    'band edges. New R226 battery audit;',
    'census 142. Next: R227 - the III.E',
    'table 3 footnotes (Figurine per-hit-die',
    'asterisk, DMG p.129, upload lines',
    '~9765+), or the next un-pinned III.A-H',
    'surrounding prose seam.'
]
log_entry = NL.join(log_lines)

old4 = 'Categories:'

new4 = (log_entry + NL + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R226 landed the III.E table 2 footnote',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R226 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R226 note: 4 patches; the III.E table 2 footnote pins landed -')
print('the class marks and asterisk rows; census 142.')
print('commit: R226: the III.E table 2 footnote pins pinned - DMG p.128,')
print('the class marks and the asterisk rows (census 142)')

