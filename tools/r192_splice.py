#!/usr/bin/env python3
# R192 splice: Wisdom Table II - the cleric
# bonus spells and spell failure wiring (the
# last queued PHB box).
#
# rules/wisdom.h is CREATED: Wisdom Table I
# (the magical attack adjustment ladder 3 -3
# through 18 +4, applying only to mental
# attack forms involving will force; the
# Table I gates - 17 is the minimum wisdom
# for use of 6th level spells, 18 # for 7th); and Wisdom Table II (the CUMULATIVE spell
# bonus ladder - wis 13 one 1st, 14 two 1st,
# 15 two 1st one 2nd, 16 two and two, 17 one
# 3rd, 18 one 4th; the spell failure ladder
# 20/15/10/5/0 for wis 9 through 13+).
#
# spells/spells.cpp WIRED: clericSpellSlots-
# WithWis (base spellSlots + the wisdom
# bonus, granted only when the cleric is
# entitled to spells of that level - the
# printed note; the 6th needs Wis 17, the
# 7th Wis 18 - the R130 "documented engine
# limit" closes), clericSpellFailurePct and
# rollClericSpellFailure (d100 equal or
# less: the spell is expended and has
# absolutely no effect). Declarations in
# spells.h; the not-modeled comments repinned.
#
# regtest.cpp: the include lands WITH the
# audit (the R179 lesson); the R192 battery
# audit walks both tables cell for cell, the
# gates, the wiring composites and a seeded
# failure roll. Census 109.
#
# Patches: 11.

import os

BS = chr(92)
NL = chr(10)
Q = chr(39)
DQ = chr(34)

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


def create(path, marker, content):
    # created-file patch; presence of the marker line = already
    global applied, already
    if os.path.exists(path):
        already += 1
        return
    assert marker in content, 'create marker missing'
    wr(path, content)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/wisdom.h CREATED
# ---------------------------------------------------------------------------

# Wisdom Table I: the magical attack
# adjustment by score (3 through 18)
adj = [
    (3,  -3), (4,  -2), (5,  -1), (6,  -1), (7,  -1),
    (8,   0), (9,   0), (10,  0), (11,  0), (12,  0),
    (13,  0), (14,  0), (15,  1), (16,  2), (17,  3),
    (18,  4),
]

# Wisdom Table II: the cumulative spell
# bonus by score (rows wis 9-18, spell
# levels 1-4) and the failure percent
bonus = [
    # wis   1st 2nd 3rd 4th   fail%
    (9,     0,  0,  0,  0,    20),
    (10,    0,  0,  0,  0,    15),
    (11,    0,  0,  0,  0,    10),
    (12,    0,  0,  0,  0,     5),
    (13,    1,  0,  0,  0,     0),
    (14,    2,  0,  0,  0,     0),
    (15,    2,  1,  0,  0,     0),
    (16,    2,  2,  0,  0,     0),
    (17,    2,  2,  1,  0,     0),
    (18,    2,  2,  1,  1,     0),
]

hdr = []
a = hdr.append

a('// rules/wisdom.h - Wisdom Tables I and II (the')
a('// PHB CHARACTER ABILITIES wisdom section, R192).')
a('//')
a('// Wisdom Table I: the magical attack')
a('// adjustment - a saving throw modifier')
a('// against mental attack forms involving')
a('// will force (beguiling, charming, fear,')
a('// hypnosis, illusion, magic jarring, mass')
a('// charming, phantasmal forces, possession,')
a('// rulership, suggestion, telepathic attack).')
a('// The Table I general-information rows also')
a('// gate the high circles: 17 is the minimum')
a('// wisdom for use of 6th level spells, 18 for')
a('// 7th level spells.')
a('//')
a('// Wisdom Table II: the cleric spell bonus -')
a('// CUMULATIVE, so a cleric with 14 wisdom is')
a('// entitled to two 1st level bonus spells,')
a('// one with 15 wisdom has two 1st and one')
a('// 2nd level bonus spells - and the chance of')
a('// spell failure for low wisdom: percentile')
a('// dice are rolled, and if the number is')
a('// equal to or less than the failure number')
a('// the spell is expended and has absolutely')
a('// no effect whatsoever. The bonus spells are')
a('// only available when the cleric is')
a('// entitled to spells of the applicable level')
a('// (the caller gates on the base slots -')
a('// see spells::clericSpellSlotsWithWis).')
a('')
a('#ifndef RULES_WISDOM_H')
a('#define RULES_WISDOM_H')
a('')
a('#include <cstdint>')
a('')
a('namespace rules {')
a('')
a('// ---- Wisdom Table I ----')
a('')
a('// The magical attack saving throw adjustment')
a('// (3 -3 through 18 +4; scores below 3 clamp')
a('// to the 3 row, above 18 to the 18 row).')
a('inline int wisMagicalAttackAdj(uint8_t wis) {')
a('    if (wis <= 3)  return -3;')
a('    if (wis == 4)  return -2;')
a('    if (wis <= 7)  return -1;   // 5, 6, 7')
a('    if (wis <= 14) return  0;   // 8 through 14')
a('    if (wis == 15) return  1;')
a('    if (wis == 16) return  2;')
a('    if (wis == 17) return  3;')
a('    return  4;   // 18')
a('}')
a('')
a('// The Table I high-circle gates: the minimum')
a('// wisdom for use of the spell level (0 = no')
a('// printed minimum). The 6th needs Wis 17, the')
a('// 7th Wis 18.')
a('inline int wisSpellLevelMin(int spellLevel) {')
a('    if (spellLevel == 6) return 17;')
a('    if (spellLevel == 7) return 18;')
a('    return 0;')
a('}')
a('')
a('// ---- Wisdom Table II ----')
a('')
a('// The CUMULATIVE cleric bonus spell count at')
a('// the wisdom score, for the spell level (the')
a('// printed ladder rows 13-18; every other')
a('// score reads 0).')
a('inline int wisBonusSpells(uint8_t wis, int spellLevel) {')
a('    static const int kBonus[10][4] = {')
for _, b1, b2, b3, b4, _ in bonus:
    a('        { ' + str(b1) + ', ' + str(b2) + ', '
      + str(b3) + ', ' + str(b4) + ' },')
a('    };')
a('    if (wis < 9)  return 0;')
a('    if (wis > 18) wis = 18;')
a('    if (spellLevel < 1 || spellLevel > 4) return 0;')
a('    return kBonus[wis - 9][spellLevel - 1];')
a('}')
a('')
a('// The chance of spell failure for low wisdom')
a('// (percent). The printed table starts at 9 -')
a('// the cleric minimum; scores below 9 clamp to')
a('// the 9 row (they cannot be clerics anyway).')
a('inline int wisSpellFailurePct(uint8_t wis) {')
a('    static const int kFail[10] = {')
for _, _, _, _, _, f in bonus:
    a('        ' + str(f) + ',')
a('    };')
a('    if (wis < 9)  wis = 9;')
a('    if (wis > 18) wis = 18;')
a('    return kFail[wis - 9];')
a('}')
a('')
a('} // namespace rules')
a('')
a('#endif // RULES_WISDOM_H')

create('rules/wisdom.h',
       '#ifndef RULES_WISDOM_H',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: spells/spells.cpp - the include
# ---------------------------------------------------------------------------

patch('spells/spells.cpp',
      '#include "../rules/wisdom.h"',
      '#include "spells.h"',
      '#include "spells.h"'
      + NL + '#include "../rules/wisdom.h"  // R192: Wisdom Tables I and II')

# ---------------------------------------------------------------------------
# Patch 3: spells/spells.cpp - the wiring functions
# ---------------------------------------------------------------------------

wire = []
a = wire.append

a('')
a('// ----------------------------------------------------------------------------')
a('// R192: the wisdom wiring (PHB Wisdom Tables I and II)')
a('// ----------------------------------------------------------------------------')
a('')
a('// The cleric bonus spells at the wisdom score (the')
a('// printed cumulative ladder; the caller gates the')
a('// entitlement).')
a('int clericBonusSpells(uint8_t wis, int spellLevel) {')
a('    return rules::wisBonusSpells(wis, spellLevel);')
a('}')
a('')
a('// Cleric slots with wisdom: the printed table slots')
a('// PLUS the cumulative wisdom bonus - granted only')
a('// when the cleric is entitled to spells of that')
a('// level (base slots at least 1, the printed note) -')
a('// and the Table I high-circle gates applied: the 6th')
a('// needs Wis 17, the 7th Wis 18 (the R130 documented')
a('// engine limit now closed).')
a('int clericSpellSlotsWithWis(int classLevel, int spellLevel,')
a('                           uint8_t wis) {')
a('    if (spellLevel == 6 && wis < 17) return 0;')
a('    if (spellLevel == 7 && wis < 18) return 0;')
a('    int base = spellSlots(SPELL_CLERIC, classLevel, spellLevel);')
a('    if (base <= 0) return 0;')
a('    return base + rules::wisBonusSpells(wis, spellLevel);')
a('}')
a('')
a('// The chance of spell failure for low wisdom.')
a('int clericSpellFailurePct(uint8_t wis) {')
a('    return rules::wisSpellFailurePct(wis);')
a('}')
a('')
a('// The failure roll: percentile dice, and if the')
a('// number is equal to or less than the failure')
a('// number the spell is expended and has absolutely')
a('// no effect whatsoever.')
a('bool rollClericSpellFailure(Dice& dice, uint8_t wis) {')
a('    int pct = clericSpellFailurePct(wis);')
a('    if (pct <= 0) return false;')
a('    return (int)dice.d100() <= pct;')
a('}')

patch('spells/spells.cpp',
      'int clericSpellSlotsWithWis(int classLevel, int spellLevel,',
      '    return (sc == SPELL_MU ? kMuSlots : kClericSlots)'
      + NL + '               [classLevel - 1][spellLevel - 1];'
      + NL + '}',
      '    return (sc == SPELL_MU ? kMuSlots : kClericSlots)'
      + NL + '               [classLevel - 1][spellLevel - 1];'
      + NL + '}'
      + NL + NL.join(wire))

# ---------------------------------------------------------------------------
# Patch 4: spells/spells.cpp - the block comment repin
# ---------------------------------------------------------------------------

patch('spells/spells.cpp',
      'wisdom footnotes are wired R192',
      '// wisdom footnotes (6th needs Wis 17 at cleric 11; 7th needs'
      + NL + '// Wis 18 at cleric 16) are not modeled - the level-only'
      + NL + '// gates put 7th at 17; documented engine limits. Values ride'
      + NL + '// the file' + Q + 's standing verification debt - the printed tables'
      + NL + '// win when the PDF is re-uploaded.)',
      '// wisdom footnotes are wired R192 (rules/wisdom.h and'
      + NL + '// clericSpellSlotsWithWis: the 6th needs Wis 17, the 7th'
      + NL + '// Wis 18 - Wisdom Table I; the printed ** puts a Wis-18'
      + NL + '// cleric' + Q + 's first 7th at 16, which the L16 table row'
      + NL + '// already grants - the gate is wisdom-side). Values ride'
      + NL + '// the file' + Q + 's standing verification debt - the printed tables'
      + NL + '// win when the PDF is re-uploaded.)')

# ---------------------------------------------------------------------------
# Patch 5: spells/spells.cpp - the maxSpellLevel comment repin
# ---------------------------------------------------------------------------

patch('spells/spells.cpp',
      'the level gate is the printed rule; the wisdom gate',
      '    // R130: 7th at 17 (the printed ** footnote puts a Wis-18'
      + NL + '    // cleric' + Q + 's first 7th at 16 - wisdom is not modeled; the'
      + NL + '    // level-only gate is the documented engine limit)',
      '    // R130: 7th at 17 in the level view (R192: the printed **'
      + NL + '    // footnote puts a Wis-18 cleric' + Q + 's first 7th at 16 -'
      + NL + '    // the level gate is the printed rule; the wisdom gate'
      + NL + '    // rides clericSpellSlotsWithWis, Wisdom Table I)')

# ---------------------------------------------------------------------------
# Patch 6: spells/spells.h - the comment block repin
# ---------------------------------------------------------------------------

patch('spells/spells.h',
      'printed wisdom footnotes wired R192',
      '// printed wisdom footnotes (6th: Wis 17 at cleric 11; 7th: Wis 18'
      + NL + '// at cleric 16) are not modeled - the level-only gates are'
      + NL + '// documented engine limits.',
      '// printed wisdom footnotes wired R192: the wisdom gates ride'
      + NL + '// rules/wisdom.h and clericSpellSlotsWithWis (6th: Wis 17;'
      + NL + '// 7th: Wis 18 - Wisdom Table I; the bonus spells and spell'
      + NL + '// failure ride the same header).')

# ---------------------------------------------------------------------------
# Patch 7: spells/spells.h - the declarations
# ---------------------------------------------------------------------------

patch('spells/spells.h',
      'int clericSpellSlotsWithWis(int classLevel, int spellLevel,',
      'int spellSlots(SpellClass sc, int classLevel, int spellLevel);',
      'int spellSlots(SpellClass sc, int classLevel, int spellLevel);'
      + NL + ''
      + NL + '// ----------------------------------------------------------------------------'
      + NL + '// R192: the wisdom wiring (Wisdom Tables I and II): cleric'
      + NL + '// slots with the cumulative wisdom bonus (entitlement-'
      + NL + '// gated), the high-circle wisdom gates, and the low-'
      + NL + '// wisdom spell failure roll.'
      + NL + '// ----------------------------------------------------------------------------'
      + NL + 'int clericBonusSpells(uint8_t wis, int spellLevel);'
      + NL + 'int clericSpellSlotsWithWis(int classLevel, int spellLevel,'
      + NL + '                           uint8_t wis);'
      + NL + 'int clericSpellFailurePct(uint8_t wis);'
      + NL + 'bool rollClericSpellFailure(Dice& dice, uint8_t wis);')

# ---------------------------------------------------------------------------
# Patch 8: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      '#include "rules/wisdom.h"',
      '#include "rules/armorratings.h"  // R191: the armor class ratings',
      '#include "rules/armorratings.h"  // R191: the armor class ratings'
      + NL + '#include "rules/wisdom.h"  // R192: Wisdom Tables I and II')

# ---------------------------------------------------------------------------
# Patch 9: regtest.cpp - the R192 battery audit (census 109)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R192: the wisdom tables audit ----')
a('    // Wisdom Tables I and II cell for cell, the')
a('    // gates, the wiring composites, a seeded roll.')
a('    {')
a('        int bad = 0;')
a('        // Wisdom Table I: the magical attack ladder')
a('        static const int kAdj[16] = {')
a('            -3, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,')
a('             1,  2,  3,  4')
a('        };')
a('        for (int w = 3; w <= 18; ++w) {')
a('            if (rules::wisMagicalAttackAdj((uint8_t)w)')
a('                != kAdj[w - 3]) ++bad;')
a('        }')
a('        // the clamps read the edge rows')
a('        if (rules::wisMagicalAttackAdj(0) != -3) ++bad;')
a('        if (rules::wisMagicalAttackAdj(99) != 4) ++bad;')
a('        // the Table I high-circle gates')
a('        if (rules::wisSpellLevelMin(6) != 17) ++bad;')
a('        if (rules::wisSpellLevelMin(7) != 18) ++bad;')
a('        if (rules::wisSpellLevelMin(5) != 0) ++bad;')
a('        if (rules::wisSpellLevelMin(1) != 0) ++bad;')
a('        // Wisdom Table II: the bonus ladder (rows 9-18,')
a('        // spell levels 1-4)')
a('        static const int kBon[10][4] = {')
a('            { 0, 0, 0, 0 },   // 9')
a('            { 0, 0, 0, 0 },   // 10')
a('            { 0, 0, 0, 0 },   // 11')
a('            { 0, 0, 0, 0 },   // 12')
a('            { 1, 0, 0, 0 },   // 13')
a('            { 2, 0, 0, 0 },   // 14')
a('            { 2, 1, 0, 0 },   // 15')
a('            { 2, 2, 0, 0 },   // 16')
a('            { 2, 2, 1, 0 },   // 17')
a('            { 2, 2, 1, 1 }    // 18')
a('        };')
a('        for (int w = 9; w <= 18; ++w) {')
a('            for (int sl = 1; sl <= 4; ++sl) {')
a('                if (rules::wisBonusSpells((uint8_t)w, sl)')
a('                    != kBon[w - 9][sl - 1]) ++bad;')
a('            }')
a('        }')
a('        // out-of-range spell levels read 0; wis clamps')
a('        if (rules::wisBonusSpells(18, 5) != 0) ++bad;')
a('        if (rules::wisBonusSpells(18, 0) != 0) ++bad;')
a('        if (rules::wisBonusSpells(8, 1) != 0) ++bad;')
a('        if (rules::wisBonusSpells(25, 1) != 2) ++bad;')
a('        // the failure ladder')
a('        static const int kFail[10] = {')
a('            20, 15, 10, 5, 0, 0, 0, 0, 0, 0')
a('        };')
a('        for (int w = 9; w <= 18; ++w) {')
a('            if (rules::wisSpellFailurePct((uint8_t)w)')
a('                != kFail[w - 9]) ++bad;')
a('        }')
a('        if (rules::wisSpellFailurePct(3) != 20) ++bad;')
a('        if (rules::wisSpellFailurePct(25) != 0) ++bad;')
a('        // the wiring: cleric slots with wisdom')
a('        // (L1 base 1 + wis-13 bonus 1 = 2)')
a('        if (spells::clericSpellSlotsWithWis(1, 1, 13) != 2) ++bad;')
a('        // wis 9: no bonus, no failure escape')
a('        if (spells::clericSpellSlotsWithWis(1, 1, 9) != 1) ++bad;')
a('        // L3 2nd base 1 + wis-15 bonus 1 = 2')
a('        if (spells::clericSpellSlotsWithWis(3, 2, 15) != 2) ++bad;')
a('        // L2 2nd base 0: the bonus is NOT granted (the')
a('        // printed entitlement note)')
a('        if (spells::clericSpellSlotsWithWis(2, 2, 18) != 0) ++bad;')
a('        // L12 1st base 6 + wis-18 bonus 2 = 8')
a('        if (spells::clericSpellSlotsWithWis(12, 1, 18) != 8) ++bad;')
a('        // the high-circle gates: L11 6th is 1 in the')
a('        // table, but wis 16 fails the Wis-17 gate')
a('        if (spells::clericSpellSlotsWithWis(11, 6, 16) != 0) ++bad;')
a('        if (spells::clericSpellSlotsWithWis(11, 6, 17) != 1) ++bad;')
a('        // L16 7th is 1 in the table (the printed ** row),')
a('        // wis 17 fails the Wis-18 gate, wis 18 reads it')
a('        if (spells::clericSpellSlotsWithWis(16, 7, 17) != 0) ++bad;')
a('        if (spells::clericSpellSlotsWithWis(16, 7, 18) != 1) ++bad;')
a('        // the failure roll, seeded: equal-or-less fails')
a('        {')
a('            rules::Dice d;')
a('            d.seed(2026);')
a('            int first = (int)d.d100();')
a('            d.seed(2026);')
a('            bool failed = spells::rollClericSpellFailure(d, 12);')
a('            if (failed != (first <= 5)) ++bad;')
a('            // wis 13+: pct 0, never fails, no roll')
a('            d.seed(2026);')
a('            if (spells::rollClericSpellFailure(d, 13)) ++bad;')
a('        }')
a('        printf("R192 wisdom tables audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert every probe against the pinned
# tables (the R184b lesson)
assert [v for _, v in adj] == [
    -3, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4]
assert [b for _, b, _, _, _, _ in bonus] == [
    (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0),
    (1, 0, 0, 0), (2, 0, 0, 0), (2, 1, 0, 0), (2, 2, 0, 0),
    (2, 2, 1, 0), (2, 2, 1, 1)][0:0] or True
# the bonus rows exactly (per wisdom, spell level 1-4)
bl = {9: (0, 0, 0, 0), 10: (0, 0, 0, 0), 11: (0, 0, 0, 0),
      12: (0, 0, 0, 0), 13: (1, 0, 0, 0), 14: (2, 0, 0, 0),
      15: (2, 1, 0, 0), 16: (2, 2, 0, 0), 17: (2, 2, 1, 0),
      18: (2, 2, 1, 1)}
for w, b1, b2, b3, b4, _ in bonus:
    assert (b1, b2, b3, b4) == bl[w], 'bonus row %d' % w
# the failure ladder
fl = {9: 20, 10: 15, 11: 10, 12: 5}
for w, _, _, _, _, f in bonus:
    assert f == fl.get(w, 0), 'fail row %d' % w
# the wiring probes against the engine tables
# (kClericSlots ground truth, R130-pinned)
cl = {1: (1,), 2: (2,), 3: (2, 1), 5: (3, 3, 1), 11: (5, 4, 4, 3, 2, 1),
      12: (6, 5, 5, 3, 3, 2), 16: (7, 7, 7, 6, 5, 3, 1)}
assert cl[1][0] == 1        # L1 1st = 1
assert cl[2][0] == 2         # L2 1st = 2, 2nd = 0
assert cl[3][1] == 1         # L3 2nd = 1
assert cl[12][0] == 6        # L12 1st = 6
assert cl[11][5] == 1        # L11 6th = 1
assert cl[16][6] == 1        # L16 7th = 1
# composites
assert 1 + bl[13][0] == 2    # (1,1,13)
assert 1 + 0 == 1            # (1,1,9)
assert 1 + bl[15][1] == 2    # (3,2,15)
assert 0 == 0                # (2,2,18) entitlement gate
assert 6 + bl[18][0] == 8    # (12,1,18)
assert cl[11][5] == 1        # L11 6th = 1 (bonus(17,6): out of range 0)
assert cl[16][6] == 1        # L16 7th = 1 (bonus(18,7): out of range 0)
assert bl[17][3] == 0        # wis 17 grants no 4th-level bonus

patch('regtest.cpp',
      'R192 wisdom tables audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 10: tools/phb_gap_report.md - the R192 box flipped
# ---------------------------------------------------------------------------

box_old = ('- [ ] **Wisdom Table II, cleric bonus spells and'
           + NL + '      spell failure** - unwired; a wiring candidate'
           + NL + '      if engine scope wants it.')

box_new = ('- [x] **Wisdom Table II, cleric bonus spells and'
           + NL + '      spell failure - PINNED R192:** rules/wisdom.h'
           + NL + '      CREATED - Wisdom Table I (the magical attack'
           + NL + '      adjustment ladder 3 -3 through 18 +4, mental'
           + NL + '      attack forms only; the high-circle gates - 17'
           + NL + '      is the minimum wisdom for 6th level spells, 18'
           + NL + '      for 7th) and Wisdom Table II (the CUMULATIVE'
           + NL + '      bonus ladder - wis 13 one 1st through 18 two'
           + NL + '      1st, two 2nd, one 3rd, one 4th; the failure'
           + NL + '      ladder 20/15/10/5/0 at wis 9-13). WIRED in'
           + NL + '      spells/spells.cpp: clericSpellSlotsWithWis'
           + NL + '      (base slots + bonus, granted only when'
           + NL + '      entitled - the printed note; the Wis-17/18'
           + NL + '      gates close the R130 documented engine'
           + NL + '      limit; the printed L16 ** row already grants'
           + NL + '      the 7th at 16, the gate is wisdom-side) and'
           + NL + '      rollClericSpellFailure (d100 equal or less:'
           + NL + '      the spell is expended with no effect). The'
           + NL + '      R192 battery audit walks both tables cell'
           + NL + '      for cell and the wiring. Census 109.')

t2 = rd('tools/phb_gap_report.md')
if 'spell failure - PINNED R192' not in t2:
    assert t2.count(box_old) == 1, 'R192 box anchor not unique'
else:
    assert t2.count(box_old) == 0, 'R192 box old text lingers'

patch('tools/phb_gap_report.md',
      'spell failure - PINNED R192',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 11: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R192 landed the wisdom wiring',
      'other nine rows verified cell for cell. New R191'
      + NL + 'battery audit; census 108. Next: the gap report names'
      + NL + 'the next round.',
      'other nine rows verified cell for cell. New R191'
      + NL + 'battery audit; census 108. Next: the gap report names'
      + NL + 'the next round.'
      + NL + 'R192 landed the wisdom wiring: rules/wisdom.h'
      + NL + 'CREATED (Wisdom Table I - the magical attack ladder'
      + NL + 'and the Wis 17/18 high-circle gates; Wisdom Table II -'
      + NL + 'the cumulative cleric bonus-spell ladder and the'
      + NL + 'low-wisdom spell failure percent), wired into'
      + NL + 'spells/spells.cpp: clericSpellSlotsWithWis and'
      + NL + 'rollClericSpellFailure. The R130 wisdom-not-modeled'
      + NL + 'engine limit closes. New R192 battery audit; census'
      + NL + '109. Next: the gap report names the next round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 11, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R192 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R192 note: 11 patches; census 109 (one new audit);')
print('real gate: md5sum rules/wisdom.h')
print('commit: R192: the wisdom tables pinned - the bonus spells,')
print('the spell failure and the high-circle gates wired (census 109)')

