#!/usr/bin/env python3
# R220 splice: the combined hoard table
# pins - DMG p.123, the II.C COMBINED HOARD
# table (the R219 companion): ten percentile
# bands - 01-20: 1-2 monetary and 1-5 magic;
# 21-40: 6-10 monetary and 1-5 magic; 41-55:
# 3-5 and 6-10 monetary and 1-5 and 15-18
# magic; 56-65: 1-2, 3-5 and 6-10 monetary
# and 9-12 and 13-14 magic; 66-75: 6-10 and
# 11-12 monetary and 6-8 and 15-18 magic;
# 76-80: 3-5, 6-10, 11-12 and 16-17 monetary
# and 1-5 and 9-12 magic; 81-85: 20 monetary
# and a map to 1-5 magic; 86-90: 20 monetary
# and a map to 19 magic; 91-96: a map to 1-2
# and 3-5 monetary with 20 magic on hand;
# 97-00: a map to 11-12 and 13-15 monetary
# plus 15-18 magic, with 20 magic on hand.
# The row references are the R219 sub-table
# band indices (monetary bands 0-8, magic
# bands 0-6); the die 18/19 re-roll
# instructions are never referenced here.
# Plus the design notes (these are the real
# finds; combined hoards should be hidden,
# trapped and guarded, and located in
# distant places). Patches: 4 (new
# rules/hoard.h, regtest include, audit
# block, gap-report log entry). Census
# 135 -> 136.

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
# Patch 1: rules/hoard.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
'// ====================================================================',
'// Adnd1 - rules/hoard.h',
'// R220: the combined hoard table pins',
'// (DMG p.123) - the II.C COMBINED HOARD table, the',
'// R219 companion: the ten percentile bands and their',
'// monetary and magic trove references.',
'//',
'// Pure data + helpers, header-only (the',
'// grenade.h pattern: the caller owns the',
'// dice and the actual hoard assembly; the',
'// band edges and the row references read',
'// here).',
'//',
'// Conventions and judgments, named in',
'// place:',
'//   - The bands: 01-20, 21-40, 41-55, 56-65,',
'//     66-75, 76-80, 81-85, 86-90, 91-96,',
'//     97-00 - ten bands.',
'//   - The row references are die results on',
'//     the R219 sub-tables, returned here as',
'//     the R219 band indices: monetary',
'//     1-2=b0, 3-5=b1, 6-10=b2, 11-12=b3,',
'//     13-15=b4, 16-17=b5, 20=b8; magic',
'//     1-5=m0, 6-8=m1, 9-12=m2, 13-14=m3,',
'//     15-18=m4, 19=m7, 20=m6. The die 18/19',
'//     monetary rows are re-roll instructions',
'//     and are never referenced by this',
'//     table.',
'//   - On-hand vs map: bands 0-5 hold both',
'//     monetary and magic on hand; bands 6-7',
'//     hold the 20 monetary row on hand with a',
'//     MAP to the magic; bands 8-9 MAP to the',
'//     monetary with magic held on hand.',
'//   - Design notes: these are the real finds;',
'//     a reference means the treasure of that',
'//     sub-table row; combined hoards should',
'//     be hidden, trapped and guarded, and',
'//     located in distant places.',
'// ====================================================================',
'',
'#pragma once',
'',
'namespace rules {',
'',
'// -----------------------------------------------------------------------',
'// The banding.',
'// -----------------------------------------------------------------------',
'inline int hoardBandCount() {',
'    // 01-20 through 97-00: ten bands',
'    return 10;',
'}',
'',
'inline int hoardBandOfRoll(int roll) {',
'    // 01-20 b0, 21-40 b1, 41-55 b2, 56-65 b3,',
'    // 66-75 b4, 76-80 b5, 81-85 b6, 86-90 b7,',
'    // 91-96 b8, 97-00 b9',
'    if (roll < 1) roll = 1;',
'    if (roll > 100) roll = 100;',
'    if (roll <= 20) return 0;',
'    if (roll <= 40) return 1;',
'    if (roll <= 55) return 2;',
'    if (roll <= 65) return 3;',
'    if (roll <= 75) return 4;',
'    if (roll <= 80) return 5;',
'    if (roll <= 85) return 6;',
'    if (roll <= 90) return 7;',
'    if (roll <= 96) return 8;',
'    return 9;',
'}',
'',
'// -----------------------------------------------------------------------',
'// The on-hand monetary rows.',
'// -----------------------------------------------------------------------',
'inline int hoardMonetaryRowCount(int band) {',
'    // b0: 1-2; b1: 6-10; b2: 3-5 and 6-10;',
'    // b3: 1-2, 3-5 and 6-10; b4: 6-10 and',
'    // 11-12; b5: 3-5, 6-10, 11-12 and 16-17;',
'    // b6/b7: the 20 row; b8/b9: none on hand',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    static const int t[10] = {',
'        1, 1, 2, 3, 2, 4, 1, 1, 0, 0,',
'    };',
'    return t[band];',
'}',
'',
'inline int hoardMonetaryRow(int band, int i) {',
'    // the R219 monetary band indices, in the',
'    // printed order; i clamps to the count',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    static const int t[10][4] = {',
'        { 0, 0, 0, 0 },',
'        { 2, 2, 2, 2 },',
'        { 1, 2, 2, 2 },',
'        { 0, 1, 2, 2 },',
'        { 2, 3, 3, 3 },',
'        { 1, 2, 3, 5 },',
'        { 8, 8, 8, 8 },',
'        { 8, 8, 8, 8 },',
'        { 0, 0, 0, 0 },',
'        { 0, 0, 0, 0 },',
'    };',
'    int n = hoardMonetaryRowCount(band);',
'    if (i < 0) i = 0;',
'    if (i > n - 1) i = n - 1;',
'    if (i < 0) i = 0;',
'    return t[band][i];',
'}',
'',
'// -----------------------------------------------------------------------',
'// The on-hand magic rows.',
'// -----------------------------------------------------------------------',
'inline int hoardMagicRowCount(int band) {',
'    // b0: 1-5; b1: 1-5; b2: 1-5 and 15-18;',
'    // b3: 9-12 and 13-14; b4: 6-8 and 15-18;',
'    // b5: 1-5 and 9-12; b6/b7: none (the',
'    // magic is at the map); b8: 20; b9:',
'    // 15-18 and 20',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    static const int t[10] = {',
'        1, 1, 2, 2, 2, 2, 0, 0, 1, 2,',
'    };',
'    return t[band];',
'}',
'',
'inline int hoardMagicRow(int band, int i) {',
'    // the R219 magic band indices, in the',
'    // printed order; i clamps to the count',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    static const int t[10][2] = {',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 4 },',
'        { 2, 3 },',
'        { 1, 4 },',
'        { 0, 2 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 6, 6 },',
'        { 4, 6 },',
'    };',
'    int n = hoardMagicRowCount(band);',
'    if (i < 0) i = 0;',
'    if (i > n - 1) i = n - 1;',
'    if (i < 0) i = 0;',
'    return t[band][i];',
'}',
'',
'// -----------------------------------------------------------------------',
'// The map-to-monetary references (bands 8-9).',
'// -----------------------------------------------------------------------',
'inline int hoardMapsToMonetary(int band) {',
'    // bands 91-96 and 97-00 map to the',
'    // monetary treasure',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    if (band == 8) return 1;',
'    if (band == 9) return 1;',
'    return 0;',
'}',
'',
'inline int hoardMapMonetaryRowCount(int band) {',
'    // b8 maps to 1-2 and 3-5; b9 maps to',
'    // 11-12 and 13-15',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    if (band == 8) return 2;',
'    if (band == 9) return 2;',
'    return 0;',
'}',
'',
'inline int hoardMapMonetaryRow(int band, int i) {',
'    // b8: rows 0 and 1; b9: rows 3 and 4',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    static const int t[10][2] = {',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 1 },',
'        { 3, 4 },',
'    };',
'    int n = hoardMapMonetaryRowCount(band);',
'    if (i < 0) i = 0;',
'    if (i > n - 1) i = n - 1;',
'    if (i < 0) i = 0;',
'    return t[band][i];',
'}',
'',
'// -----------------------------------------------------------------------',
'// The map-to-magic references (bands 6-7).',
'// -----------------------------------------------------------------------',
'inline int hoardMapsToMagic(int band) {',
'    // bands 81-85 and 86-90 map to the magic',
'    // treasure',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    if (band == 6) return 1;',
'    if (band == 7) return 1;',
'    return 0;',
'}',
'',
'inline int hoardMapMagicRowCount(int band) {',
'    // b6 maps to 1-5 magic; b7 maps to 19',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    if (band == 6) return 1;',
'    if (band == 7) return 1;',
'    return 0;',
'}',
'',
'inline int hoardMapMagicRow(int band, int i) {',
'    // b6: row 0 (die 1-5); b7: row 7 (die 19)',
'    if (band < 0) band = 0;',
'    if (band > 9) band = 9;',
'    static const int t[10][2] = {',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 0, 0 },',
'        { 7, 7 },',
'        { 0, 0 },',
'        { 0, 0 },',
'    };',
'    int n = hoardMapMagicRowCount(band);',
'    if (i < 0) i = 0;',
'    if (i > n - 1) i = n - 1;',
'    if (i < 0) i = 0;',
'    return t[band][i];',
'}',
'',
'// -----------------------------------------------------------------------',
'// The design notes.',
'// -----------------------------------------------------------------------',
'inline int hoardMustBeHiddenTrappedGuarded() {',
'    // combined hoards should be hidden,',
'    // trapped and guarded',
'    return 1;',
'}',
'',
'inline int hoardDistantPlaces() {',
'    // they should be located in distant',
'    // places too',
'    return 1;',
'}',
'',
'}  // namespace rules',
]
hdr = NL.join(hdr_lines) + NL

patch('rules/hoard.h',
      'R220: the combined hoard table pins',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/treasdet.h"  // R219: pp.120-123 treasure random determination tables'

new2 = ('#include "rules/treasdet.h"  // R219: pp.120-123 treasure random determination tables'
        + NL + '#include "rules/hoard.h"  // R220: p.123 the combined hoard table')

patch('regtest.cpp',
      'R220: p.123 the combined hoard table',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R220 audit block
# ---------------------------------------------------------------------------

audit_lines = [
'    // ---- R220: the combined hoard table pins audit ----',
'    // DMG p.123: the II.C combined hoard',
'    // bands and their monetary and magic',
'    // trove references.',
'    {',
'        int bad = 0;',
'        // the banding: a full 1-100 walk',
'        if (rules::hoardBandCount() != 10) ++bad;',
'        static const int kBand[100] = {',
'            0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,',
'            1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,',
'            2,2,2,2,2,2,2,2,2,2, 2,2,2,2,2,',
'            3,3,3,3,3,3,3,3,3,3, 4,4,4,4,4,4,4,4,4,4,',
'            5,5,5,5,5, 6,6,6,6,6, 7,7,7,7,7,',
'            8,8,8,8,8,8, 9,9,9,9,',
'        };',
'        for (int r = 1; r <= 100; ++r)',
'            if (rules::hoardBandOfRoll(r) !=',
'                kBand[r - 1]) ++bad;',
'        if (rules::hoardBandOfRoll(0) != 0 ||',
'            rules::hoardBandOfRoll(999) != 9) ++bad;',
'        // the on-hand monetary rows',
'        static const int kMonCnt[10] = {',
'            1, 1, 2, 3, 2, 4, 1, 1, 0, 0,',
'        };',
'        static const int kMonRow[10][4] = {',
'            { 0, 0, 0, 0 },',
'            { 2, 2, 2, 2 },',
'            { 1, 2, 2, 2 },',
'            { 0, 1, 2, 2 },',
'            { 2, 3, 3, 3 },',
'            { 1, 2, 3, 5 },',
'            { 8, 8, 8, 8 },',
'            { 8, 8, 8, 8 },',
'            { 0, 0, 0, 0 },',
'            { 0, 0, 0, 0 },',
'        };',
'        for (int b = 0; b < 10; ++b)',
'            if (rules::hoardMonetaryRowCount(b) != kMonCnt[b]) ++bad;',
'        for (int b = 0; b < 10; ++b)',
'            for (int i = 0; i < 4; ++i)',
'                if (rules::hoardMonetaryRow(b, i) !=',
'                    kMonRow[b][i]) ++bad;',
'        if (rules::hoardMonetaryRow(5, -3) != 1 ||',
'            rules::hoardMonetaryRow(5, 99) != 5 ||',
'            rules::hoardMonetaryRowCount(-2) != 1 ||',
'            rules::hoardMonetaryRowCount(99) != 0) ++bad;',
'        // the on-hand magic rows',
'        static const int kMagCnt[10] = {',
'            1, 1, 2, 2, 2, 2, 0, 0, 1, 2,',
'        };',
'        static const int kMagRow[10][2] = {',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 4 },',
'            { 2, 3 },',
'            { 1, 4 },',
'            { 0, 2 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 6, 6 },',
'            { 4, 6 },',
'        };',
'        for (int b = 0; b < 10; ++b)',
'            if (rules::hoardMagicRowCount(b) != kMagCnt[b]) ++bad;',
'        for (int b = 0; b < 10; ++b)',
'            for (int i = 0; i < 2; ++i)',
'                if (rules::hoardMagicRow(b, i) !=',
'                    kMagRow[b][i]) ++bad;',
'        if (rules::hoardMagicRow(9, -1) != 4 ||',
'            rules::hoardMagicRow(9, 99) != 6) ++bad;',
'        // the map-to-monetary references',
'        static const int kMapMon[10] = {',
'            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,',
'        };',
'        static const int kMapMonRow[10][2] = {',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 1 },',
'            { 3, 4 },',
'        };',
'        for (int b = 0; b < 10; ++b)',
'            if (rules::hoardMapsToMonetary(b) != kMapMon[b] ||',
'                rules::hoardMapMonetaryRowCount(b) !=',
'                kMapMon[b] * 2) ++bad;',
'        for (int b = 0; b < 10; ++b)',
'            for (int i = 0; i < 2; ++i)',
'                if (rules::hoardMapMonetaryRow(b, i) !=',
'                    kMapMonRow[b][i]) ++bad;',
'        // the map-to-magic references',
'        static const int kMapMag[10] = {',
'            0, 0, 0, 0, 0, 0, 1, 1, 0, 0,',
'        };',
'        static const int kMapMagRow[10][2] = {',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 0, 0 },',
'            { 7, 7 },',
'            { 0, 0 },',
'            { 0, 0 },',
'        };',
'        for (int b = 0; b < 10; ++b)',
'            if (rules::hoardMapsToMagic(b) != kMapMag[b] ||',
'                rules::hoardMapMagicRowCount(b) != kMapMag[b]) ++bad;',
'        for (int b = 0; b < 10; ++b)',
'            for (int i = 0; i < 2; ++i)',
'                if (rules::hoardMapMagicRow(b, i) !=',
'                    kMapMagRow[b][i]) ++bad;',
'        // the design notes',
'        if (rules::hoardMustBeHiddenTrappedGuarded() != 1 ||',
'            rules::hoardDistantPlaces() != 1) ++bad;',
'        printf("R220 combined hoard table pins audit: bad %d' + BS + 'n", bad);',
'        if (bad) return 1;',
'    }',
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R220: the combined hoard table pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
'R220 landed the combined hoard table pins',
'(DMG p.123, upload lines ~9430-9470) - the',
'II.C COMBINED HOARD table, the R219',
'companion. rules/hoard.h (the grenade.h',
'pattern): the ten percentile bands (01-20,',
'21-40, 41-55, 56-65, 66-75, 76-80, 81-85,',
'86-90, 91-96, 97-00) with their on-hand',
'monetary rows (b0: 1-2; b1: 6-10; b2: 3-5',
'and 6-10; b3: 1-2, 3-5 and 6-10; b4: 6-10',
'and 11-12; b5: 3-5, 6-10, 11-12 and 16-17;',
'b6/b7: the 20 row; b8/b9 none), their',
'on-hand magic rows (b0/b1: 1-5; b2: 1-5 and',
'15-18; b3: 9-12 and 13-14; b4: 6-8 and',
'15-18; b5: 1-5 and 9-12; b6/b7 none; b8:',
'20; b9: 15-18 and 20), the map-to-magic',
'references of bands 81-90 (to 1-5 and to',
'19), the map-to-monetary references of',
'bands 91-00 (to 1-2 and 3-5; to 11-12 and',
'13-15), and the design notes (the real',
'finds; hidden, trapped, guarded, distant).',
'The row references are stored as the R219',
'sub-table band indices so the two headers',
'interlock; the die 18/19 monetary re-roll',
'instructions are never referenced by this',
'table. With this round the whole RANDOM',
'TREASURE DETERMINATION top-level structure',
'(I, II, II.A, II.B, II.C) is pinned; the',
'III.A-H item tables were already closed by',
'R122. New R220 battery audit; census 136.',
'Next: R221 - the III.A potions table',
'prose rules that frame the item tables (the',
'(F) fighter-only marks, the delusion and',
'poison DM-misleading notes, the control-',
'type die rolls, upload lines ~9480-9520,',
'DMG p.125-126), or the first un-pinned',
'III.A-H surrounding prose seam.',
]
log_entry = NL.join(log_lines)

old4 = ('leads, DMG p.123).' + NL + NL + 'Categories:')

new4 = ('leads, DMG p.123).' + NL + NL + log_entry + NL
        + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R220 landed the combined hoard table pins',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R220 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R220 note: 4 patches; the combined hoard table pins landed -')
print('the ten bands and their monetary and magic references; census 136.')
print('commit: R220: the combined hoard table pins pinned - DMG p.123, the')
print('II.C bands and trove references (census 136)')

