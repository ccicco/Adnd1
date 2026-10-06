#!/usr/bin/env python3
# R221 splice: the III.A potions table
# prose pins - DMG pp.125-126, the three
# footnotes that frame the III.A POTIONS
# table: the * control potions (Animal
# Control, Dragon Control, Giant Control,
# Giant Strength, Human Control, Undead
# Control - effectiveness on the type of
# creature controlled must be determined
# by die roll; consult the item
# explanation); the ** DM-misleading
# potions (Delusion, Poison); the (F)
# fighter-only potions (Giant Strength,
# Heroism, Invulnerability, Super-Heroism).
# Keyed to the 35 die bands of the engine
# III.A table (dm/treasure.cpp kPotions
# order); the row VALUES were already
# pinned by the R122 line-diff audit.
# JUDGMENTS: Plant Control prints with NO
# star (pinned as printed); Giant Strength
# prints BOTH * and (F). Patches: 4 (new
# rules/potions.h, regtest include, audit
# block, gap-report log entry). Census
# 136 -> 137.

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
# Patch 1: rules/potions.h - the new header
# ---------------------------------------------------------------------------

hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/potions.h',
    '// R221: the III.A potions prose pins',
    '// (DMG pp.125-126) - the three footnotes',
    '// that frame the III.A POTIONS table:',
    '//   - the * control potions: effectiveness',
    '//     on the type of creature controlled',
    '//     must be determined by die roll;',
    '//     consult the item explanation.',
    '//   - the ** potions: the DM must mislead',
    '//     the holder so as to convince him the',
    '//     potion is not harmful (Delusion and',
    '//     Poison - see the item descriptions).',
    '//   - the (F) potions: fighters only may',
    '//     use.',
    '// The row identity is the 35 die bands of',
    '// the engine III.A table (dm/treasure.cpp',
    '// kPotions order, Animal Control 01-03',
    '// through Water Breathing 98-00). The row',
    '// VALUES were pinned by the R122 line-diff',
    '// audit; this header pins the footnote',
    '// flags and the band edges.',
    '// JUDGMENTS, named in place:',
    '//   - Plant Control prints with NO star',
    '//     (unlike every other control potion);',
    '//     pinned as printed.',
    '//   - Giant Strength prints BOTH * and (F);',
    '//     both flags are set.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// -----------------------------------------------------------------------',
    '// The row count and the die band edges.',
    '// -----------------------------------------------------------------------',
    'inline int potionRowCount() {',
    '    // Animal Control through Water Breathing',
    '    return 35;',
    '}',
    '',
    'inline int potionRowLo(int i) {',
    '    // the printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        1, 4, 7, 10, 13, 16, 19, 21, 24, 27,',
    '        30, 33, 35, 37, 40, 42, 48, 50, 52, 55,',
    '        58, 61, 64, 67, 70, 73, 76, 79, 82, 85,',
    '        88, 91, 94, 97, 98,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int potionRowHi(int i) {',
    '    // the printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        3, 6, 9, 12, 15, 18, 20, 23, 26, 29,',
    '        32, 34, 36, 39, 41, 47, 49, 51, 54, 57,',
    '        60, 63, 66, 69, 72, 75, 78, 81, 84, 87,',
    '        90, 93, 96, 97, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The * control potions: Animal Control,',
    '// Dragon Control, Giant Control, Giant',
    '// Strength, Human Control, Undead Control.',
    '// -----------------------------------------------------------------------',
    'inline int potionIsControl(int i) {',
    '    // effectiveness on the type of creature',
    '    // controlled must be determined by die',
    '    // roll; consult the item explanation',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        1, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '        0, 0, 1, 1, 0, 0, 0, 1, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 1, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int potionControlCount() {',
    '    return 6;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The ** DM-misleading potions: Delusion',
    '// and Poison.',
    '// -----------------------------------------------------------------------',
    'inline int potionIsMislead(int i) {',
    '    // the DM must mislead the holder so as',
    '    // to convince him the potion is not',
    '    // harmful; see the item descriptions',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,',
    '        0, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int potionMisleadCount() {',
    '    return 2;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The (F) fighter-only potions: Giant',
    '// Strength, Heroism, Invulnerability,',
    '// Super-Heroism.',
    '// -----------------------------------------------------------------------',
    'inline int potionIsFighterOnly(int i) {',
    '    // fighters only may use',
    '    if (i < 0) i = 0;',
    '    if (i > 34) i = 34;',
    '    static const int t[35] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 1, 0, 0, 1, 0, 0, 1,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        1, 0, 0, 0, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int potionFighterOnlyCount() {',
    '    return 4;',
    '}',
    '',
    '}  // namespace rules',
    ''
]
hdr = NL.join(hdr_lines) + NL

patch('rules/potions.h',
      'R221: the III.A potions prose pins',
      None,
      hdr)
# the new-file patch: the empty anchor means
# create-if-absent, marker-check-if-present

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = '#include "rules/hoard.h"  // R220: p.123 the combined hoard table'

new2 = ('#include "rules/hoard.h"  // R220: p.123 the combined hoard table'
        + NL + '#include "rules/potions.h"  // R221: pp.125-126 the potions prose pins')

patch('regtest.cpp',
      'R221: pp.125-126 the potions prose pins',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R221 audit block
# ---------------------------------------------------------------------------

audit_lines = [
    '    // ---- R221: the III.A potions prose pins audit ----',
    '    // DMG pp.125-126: the three footnotes',
    '    // that frame the III.A POTIONS table -',
    '    // the * control die rolls, the **',
    '    // DM-misleading potions, the (F)',
    '    // fighter-only potions.',
    '    {',
    '        int bad = 0;',
    '        // the row identity: the 35 die bands',
    '        if (rules::potionRowCount() != 35) ++bad;',
    '    static const int kLo[35] = {',
    '        1, 4, 7, 10, 13, 16, 19, 21, 24, 27,',
    '        30, 33, 35, 37, 40, 42, 48, 50, 52, 55,',
    '        58, 61, 64, 67, 70, 73, 76, 79, 82, 85,',
    '        88, 91, 94, 97, 98,',
    '    };',
    '    static const int kHi[35] = {',
    '        3, 6, 9, 12, 15, 18, 20, 23, 26, 29,',
    '        32, 34, 36, 39, 41, 47, 49, 51, 54, 57,',
    '        60, 63, 66, 69, 72, 75, 78, 81, 84, 87,',
    '        90, 93, 96, 97, 100,',
    '    };',
    '        for (int i = 0; i < 35; ++i)',
    '            if (rules::potionRowLo(i) != kLo[i] ||',
    '                rules::potionRowHi(i) != kHi[i]) ++bad;',
    '        for (int i = 1; i < 35; ++i)',
    '            if (rules::potionRowLo(i) !=',
    '                rules::potionRowHi(i - 1) + 1) ++bad;',
    '        if (rules::potionRowLo(-5) != 1 ||',
    '            rules::potionRowLo(99) != 98 ||',
    '            rules::potionRowHi(99) != 100) ++bad;',
    '        // the * control rows',
    '',
    '    static const int kC[35] = {',
    '        1, 0, 0, 0, 0, 0, 1, 0, 0, 0,',
    '        0, 0, 1, 1, 0, 0, 0, 1, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 1, 0,',
    '    };',
    '    static const int kM[35] = {',
    '        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,',
    '        0, 0, 0, 0, 0,',
    '    };',
    '    static const int kF[35] = {',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        0, 0, 0, 1, 0, 0, 1, 0, 0, 1,',
    '        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,',
    '        1, 0, 0, 0, 0,',
    '    };',
    '        for (int i = 0; i < 35; ++i)',
    '            if (rules::potionIsControl(i) != kC[i] ||',
    '                rules::potionIsMislead(i) != kM[i] ||',
    '                rules::potionIsFighterOnly(i) != kF[i])',
    '                ++bad;',
    '        if (rules::potionControlCount() != 6 ||',
    '            rules::potionMisleadCount() != 2 ||',
    '            rules::potionFighterOnlyCount() != 4) ++bad;',
    '        // the * rows: Animal and Undead Control',
    '        if (!rules::potionIsControl(0) ||',
    '            !rules::potionIsControl(33)) ++bad;',
    '        // JUDGMENT: Plant Control prints with',
    '        // NO star - pinned as printed',
    '        if (rules::potionIsControl(26)) ++bad;',
    '        // the ** rows: Delusion and Poison',
    '        if (!rules::potionIsMislead(4) ||',
    '            !rules::potionIsMislead(28)) ++bad;',
    '        // the (F) rows: Giant Strength,',
    '        // Heroism, Invulnerability, Super-Heroism',
    '        if (!rules::potionIsFighterOnly(13) ||',
    '            !rules::potionIsFighterOnly(16) ||',
    '            !rules::potionIsFighterOnly(19) ||',
    '            !rules::potionIsFighterOnly(30)) ++bad;',
    '        // clamped flag reads',
    '        if (rules::potionIsControl(-9) != 1 ||',
    '            rules::potionIsFighterOnly(99) != 0) ++bad;',
    '        printf("R221 potions prose pins audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    ''
]
audit = NL.join(audit_lines) + NL

old3 = '    // ---- R163: the poison table audit -------------'

new3 = audit + old3

patch('regtest.cpp',
      'R221: the III.A potions prose pins audit',
      old3,
      new3)

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the log entry
# ---------------------------------------------------------------------------

log_lines = [
    'R221 landed the III.A potions prose pins',
    '(DMG pp.125-126, upload lines ~9480-9520)',
    '- the three footnotes that frame the',
    'III.A POTIONS table. rules/potions.h',
    '(the grenade.h pattern), keyed to the 35',
    'die bands of the engine III.A table in',
    'kPotions order: the * control potions',
    '(Animal Control, Dragon Control, Giant',
    'Control, Giant Strength, Human Control,',
    'Undead Control - effectiveness on the',
    'type of creature controlled must be',
    'determined by die roll; consult the item',
    'explanation); the ** DM-misleading potions',
    '(Delusion, Poison - the DM must mislead',
    'the holder so as to convince him the',
    'potion is not harmful); the (F)',
    'fighter-only potions (Giant Strength,',
    'Heroism, Invulnerability, Super-Heroism).',
    'JUDGMENTS: Plant Control prints with NO',
    'star (unlike every other control potion)',
    'and is pinned control-less as printed;',
    'Giant Strength prints BOTH * and (F). The',
    'row VALUES and dice-band continuity were',
    'already pinned by the R122 line-diff audit',
    '(magicTablePin), so this round pins only',
    'the footnote flags and re-pins the band',
    'edges. New R221 battery audit; census 137.',
    'Next: R222 - the III.B scrolls footnotes',
    'and prose (DMG pp.126-127, upload lines',
    '~9525+), or the first un-pinned III.A-H',
    'surrounding prose seam.'
]
log_entry = NL.join(log_lines)

old4 = ('III.A-H surrounding prose seam.' + NL + NL + 'Categories:')

new4 = ('III.A-H surrounding prose seam.' + NL + NL + log_entry + NL
        + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R221 landed the III.A potions prose pins',
      old4,
      new4)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R221 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R221 note: 4 patches; the III.A potions prose pins landed -')
print('the control, DM-misleading and fighter-only footnotes; census 137.')
print('commit: R221: the III.A potions prose pins pinned - DMG pp.125-126,')
print('the control, DM-misleading and fighter-only footnotes (census 137)')

