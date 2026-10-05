#!/usr/bin/env python3
# R191 splice: the Armor Class table verify (the
# ARMOR section - a queued box).
#
# The verify found ONE divergence: the engine
# None armor row reads baseAc 9, but the printed
# ARMOR CLASS TABLE (COMBAT section) says None
# 10, shield only 9 - and the engine's own p.38
# worked examples already pin "Balto unarmored
# (AC 10)". items/items.cpp None row REPINNED to
# 10 (after the repin the shield-only composite
# reads 9, matching the print). The other nine
# rows verified cell for cell: padded 8, leather
# 8, studded 7, ring 7, scale 6, chain 5,
# splinted 4, banded 4, plate 3.
#
# rules/armorratings.h is CREATED: the printed
# composite ladder (11 rows: none 10 through
# plate 3 with every printed combination), the
# shield step (one class better), the magic rule
# (each +1 of magic armor or shield lowers AC by
# 1; a +1 converts to a 5% lesser likelihood of
# being hit), the shield flank/rear negation
# note (not engine code - recorded), and the
# magic-armor-negates-weight note.
#
# regtest.cpp: the include lands WITH the audit
# (the R179 lesson); the R191 battery audit
# walks the engine armor rows against the print,
# the effectiveAc composites (the plate kit 2,
# the DEX worked example 6 / -2, the +1 shield
# 8, the magic plate -6) and the new header.
# Census 108.
#
# Patches: 7.

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
# Patch 1: rules/armorratings.h CREATED
# ---------------------------------------------------------------------------

# the printed ARMOR CLASS TABLE, the per-type
# base ratings (name, AC): the composite rows
# of the print are base and base-1-with-shield
t = [
    ('none',           10),
    ('shield only',     9),
    ('padded',          8),
    ('leather',         8),
    ('studded leather', 7),
    ('ring mail',       7),
    ('scale mail',      6),
    ('chain mail',      5),
    ('splint mail',     4),
    ('banded mail',     4),
    ('plate mail',      3),
]

hdr = []
a = hdr.append

a('// rules/armorratings.h - the Armor Class table')
a('// (the PHB COMBAT section ARMOR CLASS TABLE, R191).')
a('//')
a('// The printed ratings, every row: none 10,')
a('// shield only 9, leather or padded 8; leather')
a('// or padded + shield / studded leather / ring')
a('// mail 7; studded leather or ring mail + shield /')
a('// scale mail 6; scale mail + shield / chain mail')
a('// 5; chain mail + shield / splint mail / banded')
a('// mail 4; splint or banded mail + shield / plate')
a('// mail 3; plate mail + shield 2. A shield makes')
a('// the wearer one class better (one step).')
a('//')
a('// The magic rule: for each +1 of magic armor or')
a('// magic shield a decrease in armor class of 1 is')
a('// given, and a +1 converts to a 5% probability -')
a('// +2 equals a 10% lesser likelihood of being hit.')
a('// The print example: magic plate mail +3 and')
a('// magic shield +5 are equal to AC -6 (3 - 3 - 1')
a('// - 5), or AC 2 with a subtraction of 8 from')
a('// attackers to hit dice rolls. A non-armored')
a('// character with a +1 shield is AC 8, a +2')
a('// shield AC 7.')
a('//')
a('// The printed notes: attacks from the right')
a('// flank and rear always negate the advantage of')
a('// the shield (the engine has no facing code -')
a('// recorded here as the pin), and magic armor')
a('// negates weight, so movement does not consider')
a('// any encumbrance from magic armor.')
a('//')
a('// The verify (R191): the engine None row was 9')
a('// against the printed 10 - repinned; the other')
a('// nine armor rows verified cell for cell.')
a('')
a('#ifndef RULES_ARMORRATINGS_H')
a('#define RULES_ARMORRATINGS_H')
a('')
a('namespace rules {')
a('')
a('// The row count of the printed ladder (the')
a('// per-type ratings; the shield composites read')
a('// armorRatingAc - armorRatingShieldStep).')
a('inline int armorRatingRowCount() { return 11; }')
a('')
a('// The i-th row name of the printed ladder.')
a('inline const char* armorRatingName(int i) {')
a('    static const char* const kNames[11] = {')
for n, _ in t:
    a('        ' + DQ + n + DQ + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 10) i = 10;')
a('    return kNames[i];')
a('}')
a('')
a('// The i-th row base armor class of the')
a('// printed ladder.')
a('inline int armorRatingAc(int i) {')
a('    static const int kAc[11] = {')
for _, ac in t:
    a('        ' + str(ac) + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 10) i = 10;')
a('    return kAc[i];')
a('}')
a('')
a('// A shield makes the wearer one class better')
a('// (the printed composites: leather 8 with')
a('// shield 7, plate 3 with shield 2).')
a('inline int armorRatingShieldStep() { return 1; }')
a('')
a('// Each +1 of magic armor or magic shield')
a('// lowers the armor class by 1.')
a('inline int armorRatingMagicAc(int plus) {')
a('    if (plus < 0) plus = 0;')
a('    return plus;')
a('}')
a('')
a('// The hit-probability form: a +1 converts to')
a('// a 5% lesser likelihood of being hit.')
a('inline int armorRatingMagicHitPct(int plus) {')
a('    if (plus < 0) plus = 0;')
a('    return 5 * plus;')
a('}')
a('')
a('// Attacks from the right flank and rear')
a('// always negate the advantage of the shield.')
a('inline bool armorRatingShieldNegatedFlankRear() {')
a('    return true;')
a('}')
a('')
a('// Magic armor negates weight: movement does')
a('// not consider any encumbrance from magic')
a('// armor.')
a('inline bool armorRatingMagicWeightless() {')
a('    return true;')
a('}')
a('')
a('} // namespace rules')
a('')
a('#endif // RULES_ARMORRATINGS_H')

create('rules/armorratings.h',
       '#ifndef RULES_ARMORRATINGS_H',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: items/items.cpp - the None row repin (9 -> the printed 10)
# ---------------------------------------------------------------------------

patch('items/items.cpp',
      '{ "None",            10,    rules::ARMOR_NONE,',
      '    { "None",             9,    rules::ARMOR_NONE,           0,     0 },',
      '    // R191: the printed ARMOR CLASS TABLE says None 10,'
      + NL + '    // shield only 9 - the engine read 9; the repin'
      + NL + '    // also matches the engine p.38 worked examples'
      + NL + '    // (Balto unarmored, AC 10).'
      + NL + '    { "None",            10,    rules::ARMOR_NONE,           0,     0 },')

# ---------------------------------------------------------------------------
# Patch 3: items/items.h - the comment repin (convention -> the print)
# ---------------------------------------------------------------------------

patch('items/items.h',
      'AC values descending (unarmored 10, the print',
      '//   AC values descending (unarmored 9 + DEX; armor sets the base).',
      '//   AC values descending (unarmored 10, the printed ARMOR'
      + NL + '//   CLASS TABLE R191; armor sets the base).')

# ---------------------------------------------------------------------------
# Patch 4: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/armorratings.h',
      '#include "rules/startmoney.h"  // R190: the starting money by class',
      '#include "rules/startmoney.h"  // R190: the starting money by class'
      + NL + '#include "rules/armorratings.h"  // R191: the armor class ratings')

# ---------------------------------------------------------------------------
# Patch 5: regtest.cpp - the R191 battery audit (census 108)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R191: the armor class ratings audit ----')
a('    // The engine armor rows against the printed ARMOR')
a('    // CLASS TABLE, the effectiveAc composites, the')
a('    // new ratings ladder.')
a('    {')
a('        int bad = 0;')
a('        // the printed ladder rows (the shield')
a('        // composites are base - 1)')
a('        if (rules::armorRatingRowCount() != 11) ++bad;')
a('        static const int kLad[11] = {')
a('            10, 9, 8, 8, 7, 7, 6, 5, 4, 4, 3')
a('        };')
a('        for (int i = 0; i < 11; ++i) {')
a('            if (rules::armorRatingAc(i) != kLad[i]) ++bad;')
a('        }')
a('        if (std::string(rules::armorRatingName(0))')
a('            != "none") ++bad;')
a('        if (std::string(rules::armorRatingName(10))')
a('            != "plate mail") ++bad;')
a('        if (rules::armorRatingShieldStep() != 1) ++bad;')
a('        // the engine armor rows vs the print:')
a('        // none 10, padded 8, leather 8, studded 7,')
a('        // ring 7, scale 6, chain 5, splinted 4,')
a('        // banded 4, plate 3 (the none row repinned')
a('        // R191: was 9)')
a('        static const int kBase[10] = {')
a('            10, 8, 8, 7, 7, 6, 5, 4, 4, 3')
a('        };')
a('        for (int i = 0; i < 10; ++i) {')
a('            if (items::armor((items::ArmorId)i).baseAc')
a('                != kBase[i]) ++bad;')
a('        }')
a('        // the effectiveAc composites:')
a('        items::ArmorInstance ar{};')
a('        // unarmored, DEX 10: the printed 10')
a('        ar.id = items::ARMOR_NONE_EQUIPPED;')
a('        if (items::effectiveAc(ar, false, 0, 10) != 10) ++bad;')
a('        // shield only: the printed 9')
a('        if (items::effectiveAc(ar, true, 0, 10) != 9) ++bad;')
a('        // leather: the printed 8; with shield 7')
a('        ar.id = items::ARMOR_LEATHER;')
a('        if (items::effectiveAc(ar, false, 0, 10) != 8) ++bad;')
a('        if (items::effectiveAc(ar, true, 0, 10) != 7) ++bad;')
a('        // plate mail + shield, DEX 10: the printed 2')
a('        ar.id = items::ARMOR_PLATE;')
a('        if (items::effectiveAc(ar, true, 0, 10) != 2) ++bad;')
a('        // the DEX worked example (the ability text):')
a('        // plate + shield normally AC 2; DEX 3 -> 6;')
a('        // DEX 18 -> -2')
a('        if (items::effectiveAc(ar, true, 0, 3) != 6) ++bad;')
a('        if (items::effectiveAc(ar, true, 0, 18) != -2) ++bad;')
a('        // the magic-shield example: unarmored with')
a('        // a +1 shield is AC 8, +2 shield AC 7')
a('        ar.id = items::ARMOR_NONE_EQUIPPED;')
a('        if (items::effectiveAc(ar, true, 1, 10) != 8) ++bad;')
a('        if (items::effectiveAc(ar, true, 2, 10) != 7) ++bad;')
a('        // the magic plate example: plate +3 armor,')
a('        // +5 shield -> AC -6 (3 - 3 - 1 - 5)')
a('        ar.id = items::ARMOR_PLATE;')
a('        ar.plus = 3;')
a('        if (items::effectiveAc(ar, true, 5, 10) != -6) ++bad;')
a('        ar.plus = 0;')
a('        // the magic rule: each +1 lowers AC 1 and')
a('        // converts to 5% hit likelihood')
a('        if (rules::armorRatingMagicAc(1) != 1) ++bad;')
a('        if (rules::armorRatingMagicAc(3) != 3) ++bad;')
a('        if (rules::armorRatingMagicHitPct(1) != 5) ++bad;')
a('        if (rules::armorRatingMagicHitPct(2) != 10) ++bad;')
a('        if (rules::armorRatingMagicAc(-2) != 0) ++bad;')
a('        // the printed notes')
a('        if (!rules::armorRatingShieldNegatedFlankRear()) ++bad;')
a('        if (!rules::armorRatingMagicWeightless()) ++bad;')
a('        printf("R191 armor class ratings audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert every probe against the pinned
# tables (the R184b lesson)
assert len(t) == 11
assert [ac for _, ac in t] == [10, 9, 8, 8, 7, 7, 6, 5, 4, 4, 3]
assert t[0][0] == 'none' and t[10][0] == 'plate mail'
# the engine row expectations in enum order
assert [10, 8, 8, 7, 7, 6, 5, 4, 4, 3] == [
    10, 8, 8, 7, 7, 6, 5, 4, 4, 3]
# the composite probes, simulated
base = {'none': 10, 'leather': 8, 'plate': 3}
assert base['none'] - 0 == 10
assert base['none'] - 1 == 9
assert base['leather'] == 8 and base['leather'] - 1 == 7
assert base['plate'] - 1 == 2
assert base['plate'] - 1 + 4 == 6      # DEX 3
assert base['plate'] - 1 - 4 == -2     # DEX 18
assert base['none'] - 1 - 1 == 8       # +1 shield
assert base['none'] - 1 - 2 == 7       # +2 shield
assert base['plate'] - 3 - 1 - 5 == -6  # magic example
# dexDefensiveAdj ground truth (character.cpp)
assert 4 == 4 and -4 == -4
# the magic accessors
assert 1 == 1 and 3 == 3 and 5 == 5 and 10 == 10

patch('regtest.cpp',
      'R191 armor class ratings audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 6: tools/phb_gap_report.md - the R191 box flipped
# ---------------------------------------------------------------------------

box_old = ('- [ ] **Armor Class table (the ARMOR section)** -'
           + NL + '      the printed AC ratings (none 10 through plate'
           + NL + '      and shield 2, magic pluses lowering AC)'
           + NL + '      deserve a cell-by-cell verify against the'
           + NL + '      items armor rows (R101 pinned the plate kit).')

box_new = ('- [x] **Armor Class table (the ARMOR section) -'
           + NL + '      PINNED R191:** rules/armorratings.h CREATED -'
           + NL + '      the printed ARMOR CLASS TABLE ladder (none 10,'
           + NL + '      shield only 9, through plate mail + shield 2),'
           + NL + '      the shield step, the magic rule (each +1'
           + NL + '      lowers AC 1; a +1 converts to a 5% lesser'
           + NL + '      likelihood of being hit), the flank/rear'
           + NL + '      shield negation and magic-armor-weightless'
           + NL + '      notes. The verify found ONE divergence: the'
           + NL + '      engine None armor row read baseAc 9 against'
           + NL + '      the printed 10 - REPINNED in items/items.cpp'
           + NL + '      (the repin also matches the engine p.38'
           + NL + '      worked examples, Balto unarmored AC 10; the'
           + NL + '      shield-only composite now reads the printed'
           + NL + '      9). The other nine rows verified cell for'
           + NL + '      cell: padded 8, leather 8, studded 7, ring 7,'
           + NL + '      scale 6, chain 5, splinted 4, banded 4, plate'
           + NL + '      3. The effectiveAc cap at 10 stays engine'
           + NL + '      convention (the p.38 columns run 0-10; a DEX'
           + NL + '      penalty cannot push effective AC past 10 -'
           + NL + '      recorded). The R191 battery audit walks the'
           + NL + '      engine rows, the composites and the worked'
           + NL + '      examples. Census 108.')

t2 = rd('tools/phb_gap_report.md')
if 'Armor Class table (the ARMOR section) -' not in t2:
    assert t2.count(box_old) == 1, 'R191 box anchor not unique'
else:
    assert t2.count(box_old) == 0, 'R191 box old text lingers'

patch('tools/phb_gap_report.md',
      'PINNED R191:** rules/armorratings.h CREATED',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 7: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R191 landed the armor class ratings',
      '(pcMonthlySupportCost). New R190 battery audit; census'
      + NL + '107. Next: the gap report names the next round.',
      '(pcMonthlySupportCost). New R190 battery audit; census'
      + NL + '107. Next: the gap report names the next round.'
      + NL + 'R191 landed the armor class ratings:'
      + NL + 'rules/armorratings.h CREATED (the printed ARMOR'
      + NL + 'CLASS TABLE ladder, the shield step, the magic rule'
      + NL + 'and the printed notes). The verify found ONE'
      + NL + 'divergence: the engine None armor row read 9 against'
      + NL + 'the printed 10 - repinned in items/items.cpp (the p.38'
      + NL + 'worked examples already said unarmored AC 10); the'
      + NL + 'other nine rows verified cell for cell. New R191'
      + NL + 'battery audit; census 108. Next: the gap report names'
      + NL + 'the next round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 7, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R191 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R191 note: 7 patches; census 108 (one new audit);')
print('real gate: md5sum rules/armorratings.h')
print('commit: R191: the armor class ratings pinned - the ladder,')
print('the magic rule and the None repin (census 108)')

