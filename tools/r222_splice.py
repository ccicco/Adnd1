#!/usr/bin/env python3
# R222 splice: the III.B scrolls prose
# pins - DMG pp.126-127, the structure
# and prose of the III.B SCROLLS table:
# the 16 spell-scroll rows with the
# printed illusionist alternative ranges
# (the or X-Y* halves), the 8 protection
# scroll rows and their x.p. values, the
# 8-row curse sub-table, and the prose
# (100 x.p. per spell level; 3x sale for
# spell scrolls, 5x for protection; the
# DM-must-convince-read footnote; unread
# scrolls may fade; the curse is
# immediate). Patches: 4 (new
# rules/scrollpins.h, regtest include,
# audit block, gap-report log entry).
# Census 137 -> 138.

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
# Patch 1: rules/scrollpins.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/scrollpins.h',
    '// R222: the III.B scrolls prose pins',
    '// (DMG pp.126-127) - the structure and',
    '// prose of the III.B SCROLLS table:',
    '//   - the 16 spell-scroll rows: dice',
    '//     band, spell count, level range,',
    '//     and the printed illusionist',
    '//     alternative range (the or X-Y*',
    '//     halves - the alt rows are the',
    '//     17-19, 25-27, 33-35, 40-42,',
    '//     47-49, 53-54 and 60 bands; the',
    '//     alt lo equals the main lo and',
    '//     the alt hi is lower).',
    '//   - the 8 protection scroll rows',
    '//     with their table-printed x.p.',
    '//     values.',
    '//   - the 8-row curse sub-table the',
    '//     Curse** row sends the reader',
    '//     to (DM discretion noted: these',
    '//     are the SUGGESTED curses).',
    '//   - the prose: 100 x.p. per spell',
    '//     level, awarded only to',
    '//     characters who can use the',
    '//     spell; spell scrolls sell at',
    '//     three times x.p. on the open',
    '//     market, protection scrolls at',
    '//     five times; the DM must do his',
    '//     utmost to convince players a',
    '//     cursed scroll should be read',
    '//     (duplicity, coercion and',
    '//     threat); an unread scroll has',
    '//     a chance of fading in normal',
    '//     air; a curse takes effect',
    '//     immediately.',
    '// JUDGMENTS, named in place:',
    '//   - The alt ranges are pinned as',
    '//     data even though the engine',
    '//     roller reads only the main',
    '//     range; the print gives no',
    '//     dice split for which half a',
    '//     found scroll uses.',
    '//   - The curse transports move the',
    '//     reader AND all within 20 feet;',
    '//     the 200-1,200 miles band is',
    '//     pinned as min/max.',
    '// Pure data + helpers, header-only',
    '// (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// -----------------------------------------------------------------------',
    '// The spell-scroll rows (dice bands 01-60).',
    '// -----------------------------------------------------------------------',
    'inline int scrollSpellRowCount() {',
    '    return 16;',
    '}',
    '',
    'inline int scrollSpellRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 15) i = 15;',
    '    static const int t[16] = {',
    '        1, 11, 17, 20, 25, 28, 33, 36, 40, 43,',
    '        47, 50, 53, 55, 58, 60,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollSpellRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 15) i = 15;',
    '    static const int t[16] = {',
    '        10, 16, 19, 24, 27, 32, 35, 39, 42, 46,',
    '        49, 52, 54, 57, 59, 60,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollSpellRowN(int i) {',
    '    // the spells on the scroll; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 15) i = 15;',
    '    static const int t[16] = {',
    '        1, 1, 1, 2, 2, 3, 3, 4, 4, 5,',
    '        5, 6, 6, 7, 7, 7,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollSpellRowLvLo(int i) {',
    '    // the main level range lower edge; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 15) i = 15;',
    '    static const int t[16] = {',
    '        1, 1, 2, 1, 1, 1, 2, 1, 1, 1,',
    '        1, 1, 3, 1, 2, 4,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollSpellRowLvHi(int i) {',
    '    // the main level range upper edge; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 15) i = 15;',
    '    static const int t[16] = {',
    '        4, 6, 9, 4, 8, 4, 9, 6, 8, 6,',
    '        8, 6, 8, 8, 9, 9,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollSpellRowHasAlt(int i) {',
    '    // 1 when the print gives an',
    '    // illusionist alternative range',
    '    // (the or X-Y* halves); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 15) i = 15;',
    '    static const int t[16] = {',
    '        0, 0, 1, 0, 1, 0, 1, 0, 1, 0,',
    '        1, 0, 1, 0, 0, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollSpellRowAltLvLo(int i) {',
    '    // the alt range lower edge (equals',
    '    // the main lo on every alt row);',
    '    // i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 15) i = 15;',
    '    static const int t[16] = {',
    '        0, 0, 2, 0, 1, 0, 2, 0, 1, 0,',
    '        1, 0, 3, 0, 0, 4,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollSpellRowAltLvHi(int i) {',
    '    // the alt range upper edge (lower',
    '    // than the main hi on every alt',
    '    // row); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 15) i = 15;',
    '    static const int t[16] = {',
    '        0, 0, 7, 0, 6, 0, 7, 0, 6, 0,',
    '        6, 0, 6, 0, 0, 7,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollSpellAltRangeCount() {',
    '    // the 17-19, 25-27, 33-35, 40-42,',
    '    // 47-49, 53-54 and 60 bands',
    '    return 7;',
    '}',
    '',
    'inline int scrollProtRowCount() {',
    '    // the protection scrolls (61-97)',
    '    return 8;',
    '}',
    '',
    'inline int scrollProtRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 7) i = 7;',
    '    static const int t[8] = {',
    '        61, 63, 65, 71, 77, 83, 88, 93,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollProtRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 7) i = 7;',
    '    static const int t[8] = {',
    '        62, 64, 70, 76, 82, 87, 92, 97,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollProtRowXp(int i) {',
    '    // the table-printed x.p. values;',
    '    // i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 7) i = 7;',
    '    static const int t[8] = {',
    '        2500, 2500, 1500, 1000, 1500, 2000, 2000, 1500,',
    '    };',
    '    return t[i];',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The curse sub-table (the Curse** row).',
    '// -----------------------------------------------------------------------',
    'inline int scrollCurseRowCount() {',
    '    return 8;',
    '}',
    '',
    'inline int scrollCurseRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 7) i = 7;',
    '    static const int t[8] = {',
    '        1, 26, 31, 41, 51, 76, 91, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int scrollCurseRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 7) i = 7;',
    '    static const int t[8] = {',
    '        25, 30, 40, 50, 75, 90, 99, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The prose constants.',
    '// -----------------------------------------------------------------------',
    'inline int scrollSpellXpPerLevel() {',
    '    // awarded only to characters who can',
    '    // use the spell(s)',
    '    return 100;',
    '}',
    '',
    'inline int scrollSpellSaleMultiplier() {',
    '    // the open market pays three times',
    '    // the x.p. value',
    '    return 3;',
    '}',
    '',
    'inline int scrollProtectionSaleMultiplier() {',
    '    // protection scrolls sell at five',
    '    // times the x.p. value',
    '    return 5;',
    '}',
    '',
    'inline int scrollDmMustConvinceRead() {',
    '    // duplicity, coercion and threat:',
    '    // the DM must do his utmost to',
    '    // convince players a cursed scroll',
    '    // should be read',
    '    return 1;',
    '}',
    '',
    'inline int scrollUnreadMayFade() {',
    '    // a scroll not read has a chance of',
    '    // fading in normal air; the archaic',
    '    // wording notes it if read in the',
    '    // still dungeon atmosphere',
    '    return 1;',
    '}',
    '',
    'inline int scrollCurseTakesEffectImmediately() {',
    '    return 1;',
    '}',
    '',
    'inline int scrollCurseDiseaseOnsetMin() {',
    '    // fatal to the reader in 2-8 turns',
    '    // unless cured',
    '    return 2;',
    '}',
    '',
    'inline int scrollCurseDiseaseOnsetMax() {',
    '    return 8;',
    '}',
    '',
    'inline int scrollCurseTransportMinMiles() {',
    '    // rows 31-40: 200 to 1,200 miles in',
    '    // a random direction',
    '    return 200;',
    '}',
    '',
    'inline int scrollCurseTransportMaxMiles() {',
    '    return 1200;',
    '}',
    '',
    'inline int scrollCurseTransportRadius() {',
    '    // rows 31-50 move the reader AND all',
    '    // within 20 feet',
    '    return 20;',
    '}',
    '',
    'inline int scrollCurseRandomSpellLevel() {',
    '    // row 00: a randomly rolled spell',
    '    // affects the reader at the 12th',
    '    // level of magic-use',
    '    return 12;',
    '}',
    '',
    '}  // namespace rules',
    ''
]
hdr = NL.join(hdr_lines) + NL

patch('rules/scrollpins.h',
      'R222: the III.B scrolls prose pins',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/potions.h"  // R221: pp.125-126 the potions prose pins'

new2 = ('#include "rules/potions.h"  // R221: pp.125-126 the potions prose pins'
        + NL + '#include "rules/scrollpins.h"  // R222: pp.126-127 the scrolls prose pins')

patch('regtest.cpp',
      'R222: pp.126-127 the scrolls prose pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R222 audit block
# ---------------------------------------------------------------------------

audit_lines = [
    '    // ---- R222: the III.B scrolls prose pins audit ----',
    '    // DMG pp.126-127: the spell-scroll',
    '    // structure (with the illusionist',
    '    // alternative ranges), the',
    '    // protection scroll values, the',
    '    // curse sub-table and the sale/',
    '    // x.p. prose.',
    '    {',
    '        int bad = 0;',
    '        // the spell-scroll rows',
    '        if (rules::scrollSpellRowCount() != 16) ++bad;',
    '        static const int kSLo[16] = {',
    '            1, 11, 17, 20, 25, 28, 33, 36, 40, 43,',
    '            47, 50, 53, 55, 58, 60,',
    '        };',
    '        static const int kSHi[16] = {',
    '            10, 16, 19, 24, 27, 32, 35, 39, 42, 46,',
    '            49, 52, 54, 57, 59, 60,',
    '        };',
    '        static const int kN[16] = {',
    '            1, 1, 1, 2, 2, 3, 3, 4, 4, 5,',
    '            5, 6, 6, 7, 7, 7,',
    '        };',
    '        static const int kLvLo[16] = {',
    '            1, 1, 2, 1, 1, 1, 2, 1, 1, 1,',
    '            1, 1, 3, 1, 2, 4,',
    '        };',
    '        static const int kLvHi[16] = {',
    '            4, 6, 9, 4, 8, 4, 9, 6, 8, 6,',
    '            8, 6, 8, 8, 9, 9,',
    '        };',
    '        static const int kAlt[16] = {',
    '            0, 0, 1, 0, 1, 0, 1, 0, 1, 0,',
    '            1, 0, 1, 0, 0, 1,',
    '        };',
    '        static const int kALo[16] = {',
    '            0, 0, 2, 0, 1, 0, 2, 0, 1, 0,',
    '            1, 0, 3, 0, 0, 4,',
    '        };',
    '        static const int kAHi[16] = {',
    '            0, 0, 7, 0, 6, 0, 7, 0, 6, 0,',
    '            6, 0, 6, 0, 0, 7,',
    '        };',
    '        for (int i = 0; i < 16; ++i)',
    '            if (rules::scrollSpellRowLo(i) != kSLo[i] ||',
    '                rules::scrollSpellRowHi(i) != kSHi[i] ||',
    '                rules::scrollSpellRowN(i) != kN[i]) ++bad;',
    '        for (int i = 0; i < 16; ++i)',
    '            if (rules::scrollSpellRowLvLo(i) != kLvLo[i] ||',
    '                rules::scrollSpellRowLvHi(i) != kLvHi[i] ||',
    '                rules::scrollSpellRowHasAlt(i) != kAlt[i] ||',
    '                rules::scrollSpellRowAltLvLo(i) != kALo[i] ||',
    '                rules::scrollSpellRowAltLvHi(i) != kAHi[i])',
    '                ++bad;',
    '        for (int i = 1; i < 16; ++i)',
    '            if (rules::scrollSpellRowLo(i) !=',
    '                rules::scrollSpellRowHi(i - 1) + 1) ++bad;',
    '        if (rules::scrollSpellRowLo(-5) != 1 ||',
    '            rules::scrollSpellRowHi(99) != 60) ++bad;',
    '        // the alt rows are the 2, 4, 6, 8,',
    '        // 10, 12 and 15 indices; alt lo =',
    '        // main lo, alt hi < main hi',
    '        if (rules::scrollSpellAltRangeCount() != 7) ++bad;',
    '        if (!rules::scrollSpellRowHasAlt(2) ||',
    '            !rules::scrollSpellRowHasAlt(4) ||',
    '            !rules::scrollSpellRowHasAlt(6) ||',
    '            !rules::scrollSpellRowHasAlt(8) ||',
    '            !rules::scrollSpellRowHasAlt(10) ||',
    '            !rules::scrollSpellRowHasAlt(12) ||',
    '            !rules::scrollSpellRowHasAlt(15)) ++bad;',
    '        if (rules::scrollSpellRowHasAlt(0) ||',
    '            rules::scrollSpellRowHasAlt(13)) ++bad;',
    '        if (rules::scrollSpellRowAltLvLo(2) != 2 ||',
    '            rules::scrollSpellRowAltLvHi(2) != 7 ||',
    '            rules::scrollSpellRowAltLvHi(15) != 7 ||',
    '            rules::scrollSpellRowAltLvLo(12) != 3) ++bad;',
    '        // the protection scroll rows',
    '        if (rules::scrollProtRowCount() != 8) ++bad;',
    '        static const int kPLo[8] = {',
    '            61, 63, 65, 71, 77, 83, 88, 93,',
    '        };',
    '        static const int kPHi[8] = {',
    '            62, 64, 70, 76, 82, 87, 92, 97,',
    '        };',
    '        static const int kPxp[8] = {',
    '            2500, 2500, 1500, 1000, 1500, 2000, 2000, 1500,',
    '        };',
    '        for (int i = 0; i < 8; ++i)',
    '            if (rules::scrollProtRowLo(i) != kPLo[i] ||',
    '                rules::scrollProtRowHi(i) != kPHi[i] ||',
    '                rules::scrollProtRowXp(i) != kPxp[i]) ++bad;',
    '        if (rules::scrollProtRowLo(0) != 61 ||',
    '            rules::scrollProtRowHi(7) != 97 ||',
    '            rules::scrollProtRowXp(0) != 2500 ||',
    '            rules::scrollProtRowXp(3) != 1000) ++bad;',
    '        for (int i = 1; i < 8; ++i)',
    '            if (rules::scrollProtRowLo(i) !=',
    '                rules::scrollProtRowHi(i - 1) + 1) ++bad;',
    '        // the curse sub-table rows',
    '        if (rules::scrollCurseRowCount() != 8) ++bad;',
    '        static const int kCLo[8] = {',
    '            1, 26, 31, 41, 51, 76, 91, 100,',
    '        };',
    '        static const int kCHi[8] = {',
    '            25, 30, 40, 50, 75, 90, 99, 100,',
    '        };',
    '        for (int i = 0; i < 8; ++i)',
    '            if (rules::scrollCurseRowLo(i) != kCLo[i] ||',
    '                rules::scrollCurseRowHi(i) != kCHi[i]) ++bad;',
    '        for (int i = 1; i < 8; ++i)',
    '            if (rules::scrollCurseRowLo(i) !=',
    '                rules::scrollCurseRowHi(i - 1) + 1) ++bad;',
    '        // row 00 is the 100 singleton',
    '        if (rules::scrollCurseRowLo(7) != 100 ||',
    '            rules::scrollCurseRowHi(7) != 100 ||',
    '            rules::scrollCurseRowLo(-9) != 1 ||',
    '            rules::scrollCurseRowHi(99) != 100) ++bad;',
    '        // the prose constants',
    '        if (rules::scrollSpellXpPerLevel() != 100 ||',
    '            rules::scrollSpellSaleMultiplier() != 3 ||',
    '            rules::scrollProtectionSaleMultiplier() != 5)',
    '            ++bad;',
    '        if (!rules::scrollDmMustConvinceRead() ||',
    '            !rules::scrollUnreadMayFade() ||',
    '            !rules::scrollCurseTakesEffectImmediately())',
    '            ++bad;',
    '        if (rules::scrollCurseDiseaseOnsetMin() != 2 ||',
    '            rules::scrollCurseDiseaseOnsetMax() != 8 ||',
    '            rules::scrollCurseTransportMinMiles() != 200 ||',
    '            rules::scrollCurseTransportMaxMiles() != 1200 ||',
    '            rules::scrollCurseTransportRadius() != 20 ||',
    '            rules::scrollCurseRandomSpellLevel() != 12)',
    '            ++bad;',
    '        printf("R222 scrolls prose pins audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    ''
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R222: the III.B scrolls prose pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
    'R222 landed the III.B scrolls prose pins',
    '(DMG pp.126-127, upload lines ~9532-9595)',
    '- the structure and prose of the III.B',
    'SCROLLS table. rules/scrollpins.h (the',
    'grenade.h pattern): the 16 spell-scroll',
    'rows (dice bands 01-60, spell counts and',
    'level ranges re-pinned, plus the printed',
    'ILLUSIONIST ALTERNATIVE RANGES - the or',
    'X-Y* halves on the 17-19, 25-27, 33-35,',
    '40-42, 47-49, 53-54 and 60 bands; JUDGMENT:',
    'pinned as data even though the engine',
    'roller reads only the main range, as the',
    'print gives no dice split for which half',
    'a found scroll uses; alt lo = main lo, alt',
    'hi lower on every alt row); the 8',
    'protection scroll rows with their',
    'table-printed x.p. values (2500, 2500,',
    '1500, 1000, 1500, 2000, 2000, 1500); the',
    '8-row curse sub-table (01-25 polymorph to',
    'equal-level monster that attacks, 26-30',
    'liquid, 31-40 transported 200-1,200 miles',
    'random direction, 41-50 another planet/',
    'plane/continuum, 51-75 disease fatal in',
    '2-8 turns unless cured, 76-90 explosive',
    'runes, 91-99 nearby item de-magicked,',
    '00 random spell at 12th level of',
    'magic-use); and the prose: 100 x.p. per',
    'spell level awarded only to characters',
    'who can use the spell, spell scrolls sell',
    'at 3x x.p. on the open market, protection',
    'scrolls at 5x, the DM must do his utmost',
    'to convince players a cursed scroll',
    'should be read (duplicity, coercion and',
    'threat), unread scrolls may fade in',
    'normal air, and a curse takes effect',
    'immediately. The engine III.B structure',
    '(kSpellScrolls, the protection list and',
    'the cursed-scroll name) was already in',
    'dm/treasure.cpp and faithful; this round',
    'pins what was never pinned. New R222',
    'battery audit; census 138. Next: R223 -',
    'the III.C rings footnotes (the (M)',
    'magic-user-only mark and the charge-',
    'limited double-dagger rows, DMG p.127,',
    'upload lines ~9600-9640), or the next',
    'un-pinned III.A-H surrounding prose seam.'
]
log_entry = NL.join(log_lines)

old4 = ('surrounding prose seam.' + NL + NL + 'Categories:')

new4 = ('surrounding prose seam.' + NL + NL + log_entry + NL
        + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R222 landed the III.B scrolls prose pins',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R222 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R222 note: 4 patches; the III.B scrolls prose pins landed -')
print('the spell rows, alt ranges, curse table and prose; census 138.')
print('commit: R222: the III.B scrolls prose pins pinned - DMG pp.126-127,')
print('the spell-scroll structure, curse sub-table and sale prose (census 138)')

