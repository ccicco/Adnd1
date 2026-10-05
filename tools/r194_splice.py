#!/usr/bin/env python3
# R194 splice: the WIS Table I repin (PHB
# divergence 3 of the R177 founding read).
#
# rules/character.cpp: wisMagDefAdj repinned
# from the engine -2..+2 convention to the
# printed Wisdom Table I ladder (3 -3, 4
# -2, 5-7 -1, 8-14 0, 15 +1, 16 +2, 17 +3,
# 18 +4) - by DELEGATING to rules::
# wisMagicalAttackAdj (rules/wisdom.h, the
# R192 print pin): one ladder, not two.
# The block comment repins with it.
#
# rules/saves.h: the modifier note repins -
# the adjustment applies only to mental
# attack forms involving will force
# (beguiling, charming, fear, hypnosis,
# illusion, magic jarring, mass charming,
# phantasmal forces, possession, rulership,
# suggestion, telepathic attack) - the save
# rolls still do not call it (the caller
# assembles the modifier; the per-spell
# mental-form flag is not yet engine data).
#
# regtest.cpp: the R194 battery audit walks
# the ladder cell for cell (all 16 scores),
# the clamps, and the delegation agreement
# with the R192 header. Census 111.
#
# Patches: 8.

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


# ---------------------------------------------------------------------------
# Patch 1: rules/character.cpp - the include
# ---------------------------------------------------------------------------

patch('rules/character.cpp',
      '#include "wisdom.h"  // R194',
      '#include "character.h"',
      '#include "character.h"'
      + NL + '#include "wisdom.h"  // R194: Wisdom Table I (the print pin)')

# ---------------------------------------------------------------------------
# Patch 2: rules/character.cpp - the wisMagDefAdj repin (delegates)
# ---------------------------------------------------------------------------

patch('rules/character.cpp',
      'return rules::wisMagicalAttackAdj(wis);',
      '// WIS (PHB p.11): magical defense adjustment'
      + NL + '//   3: -2; 4-5: -1; 6-8: -1; 9-12: 0; 13-14: 0; 15: +1; 16-17: +2; 18: +2'
      + NL + '//   (PHB prints 4-5 and 6-8 both -1)'
      + NL + '// ----------------------------------------------------------------------------'
      + NL
      + NL + 'int wisMagDefAdj(uint8_t wis) {'
      + NL + '    if (wis <= 3)   return -2;'
      + NL + '    if (wis <= 8)   return -1;'
      + NL + '    if (wis <= 14)  return 0;'
      + NL + '    if (wis == 15)  return 1;'
      + NL + '    return 2;   // 16-18'
      + NL + '}',
      '// WIS: Wisdom Table I, the magical attack adjustment -'
      + NL + '// REPINNED R194 to the print (3 -3, 4 -2, 5-7 -1, 8-14'
      + NL + '// 0, 15 +1, 16 +2, 17 +3, 18 +4): the old engine'
      + NL + '// convention read -2 through +2. The accessor now'
      + NL + '// DELEGATES to rules::wisMagicalAttackAdj (the R192'
      + NL + '// header pin - one ladder, not two).'
      + NL + '// ----------------------------------------------------------------------------'
      + NL
      + NL + 'int wisMagDefAdj(uint8_t wis) {'
      + NL + '    return rules::wisMagicalAttackAdj(wis);'
      + NL + '}')

# ---------------------------------------------------------------------------
# Patch 3: rules/character.h - the comment repin
# ---------------------------------------------------------------------------

patch('rules/character.h',
      'the printed ladder -3..+4 (R194',
      'int  wisMagDefAdj(uint8_t wis);         // save vs. magic adj, -2..+2',
      'int  wisMagDefAdj(uint8_t wis);         // the printed ladder -3..+4 (R194, delegates to wisMagicalAttackAdj)')

# ---------------------------------------------------------------------------
# Patch 4: rules/saves.h - the modifier note repin
# ---------------------------------------------------------------------------

patch('rules/saves.h',
      'the printed Wisdom Table I ladder R194 -3..+4; applies',
      '//   WIS magical defense adjustment (rules/character wisMagDefAdj)',
      '//   WIS magical defense adjustment (rules/character wisMagDefAdj,'
      + NL + '//   the printed Wisdom Table I ladder R194 -3..+4; applies'
      + NL + '//   only to mental attack forms involving will force:'
      + NL + '//   beguiling, charming, fear, hypnosis, illusion, magic'
      + NL + '//   jarring, mass charming, phantasmal forces, possession,'
      + NL + '//   rulership, suggestion, telepathic attack - the save'
      + NL + '//   rolls do not call it; the caller assembles the modifier)')

# ---------------------------------------------------------------------------
# Patch 5: regtest.cpp - the R194 battery audit (census 111)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R194: the wisdom magical defense repin audit ----')
a('    // The printed Wisdom Table I ladder, cell for cell, and')
a('    // the delegation agreement with the R192 header pin.')
a('    {')
a('        int bad = 0;')
a('        // the printed ladder (3 through 18):')
a('        // -3, -2, -1, -1, -1, then none through 14,')
a('        // then +1 +2 +3 +4')
a('        static const int kAdj[16] = {')
a('            -3, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,')
a('             1,  2,  3,  4')
a('        };')
a('        for (int w = 3; w <= 18; ++w) {')
a('            if (rules::wisMagDefAdj((uint8_t)w)')
a('                != kAdj[w - 3]) ++bad;')
a('        }')
a('        // the delegation: wisMagDefAdj and the R192 header')
a('        // accessor read the same ladder at every score')
a('        for (int w = 0; w <= 25; ++w) {')
a('            if (rules::wisMagDefAdj((uint8_t)w)')
a('                != rules::wisMagicalAttackAdj((uint8_t)w)) ++bad;')
a('        }')
a('        // the clamps read the edge rows')
a('        if (rules::wisMagDefAdj(0) != -3) ++bad;')
a('        if (rules::wisMagDefAdj(99) != 4) ++bad;')
a('        // the historically divergent cells (the R177 read:')
a('        // the engine convention capped at -2/+2)')
a('        if (rules::wisMagDefAdj(3) != -3) ++bad;')
a('        if (rules::wisMagDefAdj(17) != 3) ++bad;')
a('        if (rules::wisMagDefAdj(18) != 4) ++bad;')
a('        printf("R194 wisdom defense repin audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert the audit array against the print
kAdj = [-3, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
        1, 2, 3, 4]
assert len(kAdj) == 16
assert kAdj[3 - 3] == -3 and kAdj[4 - 3] == -2
assert kAdj[8 - 3] == 0 and kAdj[14 - 3] == 0
assert kAdj[15 - 3] == 1 and kAdj[16 - 3] == 2
assert kAdj[17 - 3] == 3 and kAdj[18 - 3] == 4

patch('regtest.cpp',
      'R194 wisdom defense repin audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 6: tools/phb_gap_report.md - the divergence 3 box flipped
# ---------------------------------------------------------------------------

box_old = ('- [~] 3. **WIS Table I, magical attack adjustment'
           + NL + '      (the WISDOM TABLE I page)** - the engine reads'
           + NL + '      -2 through +2; the print reads 3 -3, 4 -2,'
           + NL + '      5-7 -1, 8-14 none, 15 +1, 16 +2, 17 +3,'
           + NL + '      18 +4. Currently unwired (the saves.h note'
           + NL + '      points at it; the save rolls do not call it).')

box_new = ('- [x] 3. **WIS Table I, magical attack adjustment'
           + NL + '      (the WISDOM TABLE I page)** -'
           + NL + '      CLOSED R194: rules/character.cpp wisMagDefAdj'
           + NL + '      repinned to the print (3 -3, 4 -2, 5-7 -1,'
           + NL + '      8-14 0, 15 +1, 16 +2, 17 +3, 18 +4) by'
           + NL + '      DELEGATING to rules::wisMagicalAttackAdj'
           + NL + '      (the R192 header pin - one ladder, not two).'
           + NL + '      The saves.h modifier note repins: the'
           + NL + '      adjustment applies only to mental attack'
           + NL + '      forms involving will force (beguiling,'
           + NL + '      charming, fear, hypnosis, illusion, magic'
           + NL + '      jarring, mass charming, phantasmal forces,'
           + NL + '      possession, rulership, suggestion, telepathy)'
           + NL + '      - the save rolls still do not call it; the'
           + NL + '      caller assembles the modifier (the per-spell'
           + NL + '      mental-form flag is not yet engine data).'
           + NL + '      The R194 battery audit walks the ladder and'
           + NL + '      the delegation. Census 111.')

t2 = rd('tools/phb_gap_report.md')
if 'CLOSED R194: rules/character.cpp wisMagDefAdj' not in t2:
    assert t2.count(box_old) == 1, 'R194 box anchor not unique'
else:
    assert t2.count(box_old) == 0, 'R194 box old text lingers'

patch('tools/phb_gap_report.md',
      'CLOSED R194: rules/character.cpp wisMagDefAdj',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 7: tools/phb_gap_report.md - the intro line repin
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'divergence 4 (INT) remains the last ranked fix round',
      'divergences 3 (WIS) and 4 (INT) remain ranked fix rounds;'
      + NL + '5 (CHA, the live reaction feed) CLOSED R193.',
      'divergence 4 (INT) remains the last ranked fix round;'
      + NL + '3 (WIS) CLOSED R194, 5 (CHA) CLOSED R193.')

# ---------------------------------------------------------------------------
# Patch 8: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R194 landed the wisdom defense repin',
      'New R193 battery audit; census 110. Next: the PHB'
      + NL + 'divergences 3 (WIS) and 4 (INT).',
      'New R193 battery audit; census 110. Next: the PHB'
      + NL + 'divergences 3 (WIS) and 4 (INT).'
      + NL + 'R194 landed the wisdom defense repin (PHB divergence'
      + NL + '3): rules/character.cpp wisMagDefAdj repinned to the'
      + NL + 'printed Wisdom Table I ladder (-3..+4) by delegating to'
      + NL + 'the R192 header pin rules::wisMagicalAttackAdj; the'
      + NL + 'saves.h modifier note repins (mental attack forms'
      + NL + 'only; the save rolls still do not call it - the caller'
      + NL + 'assembles). New R194 battery audit; census 111. Next:'
      + NL + 'the last PHB divergence, 4 (INT languages).')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 8, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R194 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R194 note: 8 patches; census 111 (one new audit);')
print('commit: R194: the wisdom defense ladder repinned - the print,')
print('by delegation (census 111)')

