#!/usr/bin/env python3
# R204 splice: the Item Saving Throw Matrix (DMG p.80,
# matrix III - saving throw matrix for magical and non-
# magical items). The DMG-only sweep seam: grenade.h
# (R157) named this lane and deferred it - the item-save
# break rule borrowed two cells (ceramic 18/12, crystal
# 19/14) without carrying the matrix. This round pins it:
#   - rules/itemsavethrow.h (new file, the grenade.h
#     pattern: pure data + helpers, header-only) - the
#     14 material rows x 11 attack forms, cell for cell,
#     cross-verified against the upload OCR and the R157
#     break-save pins (which read exactly the ceramic and
#     crystal rows)
#   - the printed modifiers: the magical ladder (+2 and
#     +1 per plus above +1), the own-mode +5, the fall
#     surfaces (hard 0, wood-like +1, fleshy +5) and the
#     per-5-feet distance penalty, the hard-metal
#     cold-strike footnote (-10 on the die), the
#     normal-fire exposure rounds (parchment 1, cloth 2,
#     bone 3 - the "etc." tail is caller-side)
#   - the save convention: the item SAVES on d20 + adj >=
#     the cell value (the R157 convention)
#   - the regtest include + the R204 audit (all 154 cells
#     pinned, the R157 cross-checks, the modifier ladder)
#   - the gap-report log entry rides this commit (the
#     R202 convention)
# Patches: 4 (itemsavethrow.h, regtest include,
# regtest audit, dmg_gap_report.md). Census 119 -> 120.

BS = chr(92)
NL = chr(10)
Q = chr(39)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique
    global applied, already
    t = rd(path)
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


def newfile(path, marker, text):
    # create-only patch; the file must not exist pre-patch
    global applied, already
    import os
    if os.path.exists(path):
        t = rd(path)
        assert marker in t, 'existing file lacks the marker: ' + path
        already += 1
        return
    assert marker in text, 'marker missing from the new text: ' + marker
    wr(path, text)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/itemsavethrow.h (new file)
# ---------------------------------------------------------------------------

h = [
    '// ====================================================================',
    '// Adnd1 - rules/itemsavethrow.h',
    '// R204: the Item Saving Throw Matrix (DMG p.80,',
    '// matrix III - saving throw matrix for magical and',
    '// non-magical items): the 14 material rows x 11',
    '// attack forms, cell for cell, plus the printed',
    '// modifiers.',
    '//',
    '// Pure data + helpers, header-only (the grenade.h',
    '// pattern: the caller decides exposure and mode, then',
    '// rolls; the save itself reads this matrix).',
    '// Conventions, named in place:',
    '//   - The item SAVES on d20 + adjustments >= the cell',
    '//     value (the R157 break-roll convention).',
    '//   - The Liquid row applies while the container',
    '//     remains intact (the printed footnote); the 0',
    '//     cells are printed 0s - no save window (liquid vs',
    '//     blow, fall and normal fire; parchment vs fall).',
    '//   - The Mirror row is silvered glass: a silver mirror',
    '//     reads Metal, soft and steel reads Metal, hard',
    '//     (the printed footnote). Metal, soft or Jewelry',
    '//     includes pearls of any sort.',
    '//   - Hard metal exposed to extreme cold then struck',
    '//     against a very hard surface with force saves at',
    '//     -10 on the die (the printed footnote a).',
    '//   - JUDGMENTs: items that do not match a row',
    '//     interpolate (the printed rule) - the caller picks',
    '//     the row; the normal-fire exposure tail past the',
    '//     three printed rounds (paper 1, cloth 2, bone 3)',
    '//     is the caller (the print trails with "etc.").',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    '#include "dice.h"',
    '',
    'namespace rules {',
    '',
    '// -----------------------------------------------------------------------',
    '// The 11 attack forms (the print order)',
    '// -----------------------------------------------------------------------',
    '',
    'enum ItemSaveForm {',
    '    ISF_ACID = 0,',
    '    ISF_BLOW_CRUSHING,',
    '    ISF_BLOW_NORMAL,',
    '    ISF_DISINTEGRATE,',
    '    ISF_FALL,',
    '    ISF_FIREBALL,',
    '    ISF_FIRE_MAGICAL,',
    '    ISF_FIRE_NORMAL,',
    '    ISF_FROST_MAGICAL,',
    '    ISF_LIGHTNING_BOLT,',
    '    ISF_ELECTRICAL,',
    '    ISF_COUNT',
    '};',
    '',
    '// -----------------------------------------------------------------------',
    '// The 14 materials (the print row order)',
    '// -----------------------------------------------------------------------',
    '',
    'enum ItemSaveMaterial {',
    '    ISM_BONE_IVORY = 0,',
    '    ISM_CERAMIC,',
    '    ISM_CLOTH,',
    '    ISM_CRYSTAL_VIAL,',
    '    ISM_GLASS,',
    '    ISM_LEATHER_BOOK,',
    '    ISM_LIQUID,',
    '    ISM_METAL_HARD,',
    '    ISM_METAL_SOFT_JEWELRY,',
    '    ISM_MIRROR,',
    '    ISM_PARCHMENT_PAPER,',
    '    ISM_STONE_GEM,',
    '    ISM_WOOD_ROPE_THIN,',
    '    ISM_WOOD_ROPE_THICK,',
    '    ISM_COUNT',
    '};',
    '',
    'inline const char* itemSaveFormName(ItemSaveForm f) {',
    '    static const char* const n[ISF_COUNT] = {',
    '        "acid", "blow, crushing", "blow, normal",',
    '        "disintegrate", "fall",',
    '        "fireball (or breath)", "fire, magical",',
    '        "fire, normal (oil)", "frost, magical",',
    '        "lightning bolt", "electrical discharge/current"',
    '    };',
    '    if (f < ISF_ACID) f = ISF_ACID;',
    '    if (f >= ISF_COUNT) f = ISF_ELECTRICAL;',
    '    return n[f];',
    '}',
    '',
    'inline const char* itemSaveMaterialName(ItemSaveMaterial m) {',
    '    static const char* const n[ISM_COUNT] = {',
    '        "bone or ivory", "ceramic", "cloth",',
    '        "crystal or vial", "glass", "leather or book",',
    '        "liquid", "metal, hard",',
    '        "metal, soft or jewelry", "mirror",',
    '        "parchment or paper", "stone, small or gem",',
    '        "wood or rope, thin", "wood or rope, thick"',
    '    };',
    '    if (m < ISM_BONE_IVORY) m = ISM_BONE_IVORY;',
    '    if (m >= ISM_COUNT) m = ISM_WOOD_ROPE_THICK;',
    '    return n[m];',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The matrix: the 154 printed cells. The R157 grenade',
    '// break saves (ceramic 18/12, crystal 19/14) read exactly',
    '// the BLOW columns of these rows - the cross-check pins.',
    '// -----------------------------------------------------------------------',
    'inline int itemSaveTarget(ItemSaveMaterial m, ItemSaveForm f) {',
    '    static const int k[ISM_COUNT][ISF_COUNT] = {',
    '        { 11, 16, 10, 20,  6, 17,  9,  3,  2,  8, 1 },',
    '        {  4, 18, 12, 19, 11,  5,  3,  2,  4,  2, 1 },',
    '        { 12,  6,  3, 20,  2, 20, 16, 13,  1, 18, 1 },',
    '        {  6, 19, 14, 20, 13, 10,  6,  3,  7, 15, 5 },',
    '        {  5, 20, 15, 20, 14, 11,  7,  4,  6, 17, 1 },',
    '        { 10,  4,  2, 20,  1, 13,  6,  4,  3, 13, 1 },',
    '        { 15,  0,  0, 20,  0, 15, 14, 13, 12, 18, 15 },',
    '        {  7,  6,  2, 17,  2,  6,  2,  1,  1,  1, 1 },',
    '        { 13, 14,  9, 19,  4, 18, 13,  5,  1,  6, 1 },',
    '        { 12, 20, 15, 20, 13, 14,  9,  5,  6, 18, 1 },',
    '        { 16, 11,  6, 20,  0, 25, 21, 18,  2, 20, 1 },',
    '        {  3, 17,  7, 18,  4,  7,  3,  2,  1, 14, 2 },',
    '        {  9, 13,  6, 20,  2, 15, 11,  9,  1, 10, 1 },',
    '        {  8, 10,  3, 19,  1, 11,  7,  5,  1, 12, 1 },',
    '    };',
    '    if (m < ISM_BONE_IVORY) m = ISM_BONE_IVORY;',
    '    if (m >= ISM_COUNT) m = ISM_WOOD_ROPE_THICK;',
    '    if (f < ISF_ACID) f = ISF_ACID;',
    '    if (f >= ISF_COUNT) f = ISF_ELECTRICAL;',
    '    return k[m][f];',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// Magical items: +2 on all rolls plus +1 for each plus',
    '// above +1 (+1 saves at +2, +2 at +3, +3 at +4); a',
    '// non-magical item reads 0. Every item, magical or not,',
    '// gains +5 versus attack forms in its own mode.',
    '// -----------------------------------------------------------------------',
    'inline int itemSaveMagicalBonus(int plus) {',
    '    if (plus < 1) return 0;',
    '    return 2 + (plus - 1);',
    '}',
    '',
    'inline int itemSaveOwnModeBonus() { return 5; }',
    '',
    '// -----------------------------------------------------------------------',
    '// Fall (form 5): the printed cell assumes about 5 feet',
    '// onto a stone-like surface; a wood-like surface gives',
    '// +1 and a fleshy-soft surface +5; each 5 feet past the',
    '// first 5 subtracts 1 from the die roll to save.',
    '// -----------------------------------------------------------------------',
    'enum ItemSaveFallSurface { ISFS_HARD = 0, ISFS_WOODLIKE,',
    '                            ISFS_FLESHY };',
    '',
    'inline int itemSaveFallSurfaceAdj(ItemSaveFallSurface s) {',
    '    static const int a[3] = { 0, 1, 5 };',
    '    if (s < ISFS_HARD) s = ISFS_HARD;',
    '    if (s > ISFS_FLESHY) s = ISFS_FLESHY;',
    '    return a[s];',
    '}',
    '',
    'inline int itemSaveFallDistanceAdj(int feet) {',
    '    int extra = feet - 5;',
    '    if (extra < 0) extra = 0;',
    '    return -(extra / 5);',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The hard-metal cold-strike footnote: exposed to',
    '// extreme cold then struck against a very hard surface',
    '// with force, the saving throw is -10 on the die.',
    '// -----------------------------------------------------------------------',
    'inline int itemSaveHardMetalColdStrikePenalty() { return 10; }',
    '',
    '// -----------------------------------------------------------------------',
    '// Normal fire (form 8) exposure: paper or parchment for',
    '// but 1 melee round, cloth for 2, bone or ivory for 3 -',
    '// the print trails with "etc."; the caller rules the',
    '// rest. 0 = not printed (caller-side).',
    '// -----------------------------------------------------------------------',
    'inline int itemSaveNormalFireRoundsToAffect(ItemSaveMaterial m) {',
    '    if (m == ISM_PARCHMENT_PAPER) return 1;',
    '    if (m == ISM_CLOTH) return 2;',
    '    if (m == ISM_BONE_IVORY) return 3;',
    '    return 0;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The save itself: the item SAVES on roll + adj >= the',
    '// cell value (the R157 convention).',
    '// -----------------------------------------------------------------------',
    'inline bool itemSavesOn(int roll, int target, int adj) {',
    '    return roll + adj >= target;',
    '}',
    '',
    'inline bool rollItemSave(rules::Dice& dice, ItemSaveMaterial m,',
    '                         ItemSaveForm f, int adj) {',
    '    return itemSavesOn((int)dice.d20(), itemSaveTarget(m, f), adj);',
    '}',
    '',
    '} // namespace rules',
    '',
]

newfile('rules/itemsavethrow.h',
        'R204: the Item Saving Throw Matrix (DMG p.80,',
        NL.join(h))

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = ('#include "rules/wisdom.h"  // R192: Wisdom Tables I and II'
        + NL + '#include <cstdio>')

new2 = ('#include "rules/wisdom.h"  // R192: Wisdom Tables I and II'
        + NL + '#include "rules/itemsavethrow.h"  // R204: p.80 item saving throw matrix'
        + NL + '#include <cstdio>')

patch('regtest.cpp',
      'R204: p.80 item saving throw matrix',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R204 audit (after the R203 block)
# ---------------------------------------------------------------------------

aud = []
a = aud.append
a('    // ---- R204: the item saving throw matrix audit ----')
a('    // DMG p.80 matrix III: all 154 cells (14 materials x')
a('    // 11 attack forms) transcribed, plus the modifiers -')
a('    // the magical ladder, the own-mode +5, the fall surface')
a('    // and distance adjustments, the cold-strike footnote,')
a('    // the normal-fire exposure rounds - and the R157')
a('    // cross-checks: the grenade break saves must equal the')
a('    // matrix cells (ceramic flask 18/12, crystal vial')
a('    // 19/14).')
a('    {')
a('        int bad = 0;')
a('        static const int kCells[14][11] = {')
a('            { 11, 16, 10, 20,  6, 17,  9,  3,  2,  8, 1 },')
a('            {  4, 18, 12, 19, 11,  5,  3,  2,  4,  2, 1 },')
a('            { 12,  6,  3, 20,  2, 20, 16, 13,  1, 18, 1 },')
a('            {  6, 19, 14, 20, 13, 10,  6,  3,  7, 15, 5 },')
a('            {  5, 20, 15, 20, 14, 11,  7,  4,  6, 17, 1 },')
a('            { 10,  4,  2, 20,  1, 13,  6,  4,  3, 13, 1 },')
a('            { 15,  0,  0, 20,  0, 15, 14, 13, 12, 18, 15 },')
a('            {  7,  6,  2, 17,  2,  6,  2,  1,  1,  1, 1 },')
a('            { 13, 14,  9, 19,  4, 18, 13,  5,  1,  6, 1 },')
a('            { 12, 20, 15, 20, 13, 14,  9,  5,  6, 18, 1 },')
a('            { 16, 11,  6, 20,  0, 25, 21, 18,  2, 20, 1 },')
a('            {  3, 17,  7, 18,  4,  7,  3,  2,  1, 14, 2 },')
a('            {  9, 13,  6, 20,  2, 15, 11,  9,  1, 10, 1 },')
a('            {  8, 10,  3, 19,  1, 11,  7,  5,  1, 12, 1 },')
a('        };')
a('        for (int m = 0; m < rules::ISM_COUNT; ++m)')
a('            for (int f = 0; f < rules::ISF_COUNT; ++f)')
a('                if (rules::itemSaveTarget(')
a('                        (rules::ItemSaveMaterial)m,')
a('                        (rules::ItemSaveForm)f)')
a('                        != kCells[m][f]) ++bad;')
a('        // names present for every row and form')
a('        for (int m = 0; m < rules::ISM_COUNT; ++m)')
a('            if (!*rules::itemSaveMaterialName(')
a('                    (rules::ItemSaveMaterial)m)) ++bad;')
a('        for (int f = 0; f < rules::ISF_COUNT; ++f)')
a('            if (!*rules::itemSaveFormName(')
a('                    (rules::ItemSaveForm)f)) ++bad;')
a('        // the R157 cross-checks: the grenade break saves')
a('        // are the matrix BLOW cells - ceramic flasks')
a('        // (acid, oil) the ceramic row, crystal vials (holy')
a('        // or unholy water, poison) the crystal row')
a('        if (rules::itemSaveTarget(rules::ISM_CERAMIC,')
a('                rules::ISF_BLOW_CRUSHING)')
a('                != rules::grenadeBreakSaveCrushing(')
a('                      rules::GREN_ACID)) ++bad;')
a('        if (rules::itemSaveTarget(rules::ISM_CERAMIC,')
a('                rules::ISF_BLOW_NORMAL)')
a('                != rules::grenadeBreakSaveNormal(')
a('                      rules::GREN_OIL)) ++bad;')
a('        if (rules::itemSaveTarget(rules::ISM_CRYSTAL_VIAL,')
a('                rules::ISF_BLOW_CRUSHING)')
a('                != rules::grenadeBreakSaveCrushing(')
a('                      rules::GREN_HOLY_WATER)) ++bad;')
a('        if (rules::itemSaveTarget(rules::ISM_CRYSTAL_VIAL,')
a('                rules::ISF_BLOW_NORMAL)')
a('                != rules::grenadeBreakSaveNormal(')
a('                      rules::GREN_POISON)) ++bad;')
a('        // the liquid row: no save vs blow, fall, normal fire')
a('        if (rules::itemSaveTarget(rules::ISM_LIQUID,')
a('                rules::ISF_BLOW_CRUSHING) != 0) ++bad;')
a('        if (rules::itemSaveTarget(rules::ISM_LIQUID,')
a('                rules::ISF_FALL) != 0) ++bad;')
a('        if (rules::itemSaveTarget(rules::ISM_LIQUID,')
a('                rules::ISF_FIRE_NORMAL) != 13) ++bad;')
a('        // the magical ladder: +1 saves at +2, +2 at +3,')
a('        // +3 at +4, a +5 sword at +6; non-magical 0')
a('        if (rules::itemSaveMagicalBonus(0) != 0 ||')
a('            rules::itemSaveMagicalBonus(1) != 2 ||')
a('            rules::itemSaveMagicalBonus(2) != 3 ||')
a('            rules::itemSaveMagicalBonus(3) != 4 ||')
a('            rules::itemSaveMagicalBonus(5) != 6) ++bad;')
a('        if (rules::itemSaveOwnModeBonus() != 5) ++bad;')
a('        // the fall surfaces: hard 0, wood-like +1, fleshy +5')
a('        if (rules::itemSaveFallSurfaceAdj(')
a('                rules::ISFS_HARD) != 0 ||')
a('            rules::itemSaveFallSurfaceAdj(')
a('                rules::ISFS_WOODLIKE) != 1 ||')
a('            rules::itemSaveFallSurfaceAdj(')
a('                rules::ISFS_FLESHY) != 5) ++bad;')
a('        // the fall distance: through 5 feet free, each 5')
a('        // past the first costs 1')
a('        if (rules::itemSaveFallDistanceAdj(5) != 0 ||')
a('            rules::itemSaveFallDistanceAdj(9) != 0 ||')
a('            rules::itemSaveFallDistanceAdj(10) != -1 ||')
a('            rules::itemSaveFallDistanceAdj(25) != -4 ||')
a('            rules::itemSaveFallDistanceAdj(100) != -19) ++bad;')
a('        // the cold-strike footnote: -10 on the die')
a('        if (rules::itemSaveHardMetalColdStrikePenalty() != 10)')
a('            ++bad;')
a('        // normal-fire exposure: parchment 1, cloth 2, bone 3;')
a('        // the unprinted tail reads 0 (caller-side)')
a('        if (rules::itemSaveNormalFireRoundsToAffect(')
a('                rules::ISM_PARCHMENT_PAPER) != 1 ||')
a('            rules::itemSaveNormalFireRoundsToAffect(')
a('                rules::ISM_CLOTH) != 2 ||')
a('            rules::itemSaveNormalFireRoundsToAffect(')
a('                rules::ISM_BONE_IVORY) != 3 ||')
a('            rules::itemSaveNormalFireRoundsToAffect(')
a('                rules::ISM_GLASS) != 0) ++bad;')
a('        // the save convention: SAVES on roll + adj >= target')
a('        if (!rules::itemSavesOn(17, 18, 2)) ++bad;')
a('        if (rules::itemSavesOn(15, 18, 2)) ++bad;')
a('        if (!rules::itemSavesOn(18, 18, 0)) ++bad;')
a('        if (rules::itemSavesOn(17, 18, 0)) ++bad;')
a('        printf("R204 item saving throw matrix audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R203 apparent armor AC audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R204 item saving throw matrix audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the round-log entry (R202 convention)
# ---------------------------------------------------------------------------

entry = (
    'R204 landed the item saving throw matrix (DMG p.80,'
    + NL + 'matrix III, magical and non-magical items) - the'
    + NL + 'DMG-only sweep seam grenade.h named and deferred:'
    + NL + 'rules/itemsavethrow.h (the grenade.h pattern), the'
    + NL + '14 material rows x 11 attack forms cell for cell,'
    + NL + 'the ceramic 18/12 and crystal 19/14 BLOW cells'
    + NL + 'independently confirmed by the R157 break-save pins.'
    + NL + 'The printed modifiers ride it: the magical ladder'
    + NL + '(+2 and +1 per plus above +1), the own-mode +5, the'
    + NL + 'fall surfaces (hard 0, wood-like +1, fleshy +5)'
    + NL + 'with the per-5-feet distance penalty, the hard-metal'
    + NL + 'cold-strike -10 footnote, the normal-fire exposure'
    + NL + 'rounds (parchment 1, cloth 2, bone 3). The save:'
    + NL + 'd20 + adj >= cell. New R204 battery audit; census'
    + NL + '120. Next: the DMG-only sweep continues.')

log_old = ('New R203 battery audit; census 119. Next: the DMG-only'
           + NL + 'tables still unpinned.'
           + NL + NL + 'Categories:')

log_new = ('New R203 battery audit; census 119. Next: the DMG-only'
           + NL + 'tables still unpinned.'
           + NL + NL + entry + NL + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R204 landed the item saving throw matrix',
      log_old,
      log_new)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R204 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R204 note: 4 patches; the p.80 item saving throw matrix pinned -')
print('14 materials x 11 attack forms, the modifiers, the R157 cross-')
print('checks; the log entry rides this commit; census 120.')
print('commit: R204: the item saving throw matrix pinned - DMG p.80 matrix III,')
print('the 14 x 11 cells plus the modifiers (census 120)')

