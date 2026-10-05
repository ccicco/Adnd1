#!/usr/bin/env python3
# R185 splice: the multi-class and dual-class rules.
#
# rules/multiclass.h is CREATED: the per-race
# MULTI-CLASS combination table (every printed
# combo as a class bitmask: dwarf fighter/thief;
# elf fighter/magic-user, fighter/thief,
# magic-user/thief, fighter/magic-user/thief;
# gnome fighter/illusionist, fighter/thief,
# illusionist/thief; half-elf cleric/fighter,
# cleric/ranger, cleric/magic-user,
# fighter/magic-user, fighter/thief,
# magic-user/thief, cleric/fighter/magic-user,
# fighter/magic-user/thief; halfling fighter/thief;
# half-orc cleric/fighter, cleric/thief,
# cleric/assassin, fighter/thief,
# fighter/assassin; human none), the multi-class
# hit-point quotient (sum the class dice, adjust
# for CON, divide by the class count, drop
# fractions under one half, round one half and
# up), the even XP split, the stalled-hit-die
# rule (a class at its level cap contributes no
# further hit dice), the thief-armor limitation
# and the cleric edged-weapons allowance, the
# half-elf multi-class cleric WIS minimum of 13,
# and the dual-class gates (human only; 15+ in
# the prime requisite of the original class and
# 17+ in the prime requisite of the new class).
#
# regtest.cpp: the include lands WITH the audit
# (the R179 lesson); the R185 battery audit walks
# every race x combo cell, the quotient and split
# ladders, and the dual-class gates. Census 102.
#
# Patches: 5.

import os

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
# Patch 1: rules/multiclass.h CREATED
# ---------------------------------------------------------------------------

# the class bits (the combo alphabet)
MC_FIGHTER = 1
MC_MAGIC_USER = 2
MC_CLERIC = 4
MC_THIEF = 8
MC_ILLUSIONIST = 16
MC_RANGER = 32
MC_ASSASSIN = 64

# the per-race combo lists, race order:
# human, dwarf, elf, gnome, half-elf,
# halfling, half-orc (the CharRace order)
combos = [
    [],                                                   # human
    [MC_FIGHTER | MC_THIEF],                              # dwarf
    [MC_FIGHTER | MC_MAGIC_USER,
     MC_FIGHTER | MC_THIEF,
     MC_MAGIC_USER | MC_THIEF,
     MC_FIGHTER | MC_MAGIC_USER | MC_THIEF],              # elf
    [MC_FIGHTER | MC_ILLUSIONIST,
     MC_FIGHTER | MC_THIEF,
     MC_ILLUSIONIST | MC_THIEF],                          # gnome
    [MC_CLERIC | MC_FIGHTER,
     MC_CLERIC | MC_RANGER,
     MC_CLERIC | MC_MAGIC_USER,
     MC_FIGHTER | MC_MAGIC_USER,
     MC_FIGHTER | MC_THIEF,
     MC_MAGIC_USER | MC_THIEF,
     MC_CLERIC | MC_FIGHTER | MC_MAGIC_USER,
     MC_FIGHTER | MC_MAGIC_USER | MC_THIEF],              # half-elf
    [MC_FIGHTER | MC_THIEF],                              # halfling
    [MC_CLERIC | MC_FIGHTER,
     MC_CLERIC | MC_THIEF,
     MC_CLERIC | MC_ASSASSIN,
     MC_FIGHTER | MC_THIEF,
     MC_FIGHTER | MC_ASSASSIN],                           # half-orc
]

# the print: 22 combos across the six demihuman races
assert sum(len(c) for c in combos) == 22
assert len(combos) == 7
assert combos[0] == []
for row in combos:
    for m in row:
        assert m != 0, 'combo masks are nonzero'

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/multiclass.h')
a('// The multi-class and dual-class rules (R185).')
a('//')
a('// The per-race MULTI-CLASS combination table (the')
a('// print: dwarf fighter/thief; elf four combos; gnome')
a('// three; half-elf eight; halfling fighter/thief;')
a('// half-orc five; human none), the multi-class hit-')
a('// point quotient (sum the class dice, adjust for')
a('// CON, divide by the class count, drop fractions')
a('// under one half, round one half and up), the even')
a('// XP split among the classes, the stalled-hit-dice')
a('// rule (a class that can no longer progress gives')
a('// no further hit dice), the thief-armor limitation')
a('// (a multi-classed thief functions only with thief')
a('// armor and weaponry), the cleric edged-weapons')
a('// allowance (a multi-classed cleric may use edged')
a('// weapons), the half-elf multi-class cleric WIS')
a('// minimum of 13, and the human-only dual-class')
a('// gates: 15+ in the prime requisite of the original')
a('// class and 17+ in the prime requisite of the new.')
a('//')
a('// JUDGMENTs:')
a('//   - combos pin as class bitmasks; the alphabet is')
a('//     fighter, magic-user, cleric, thief, illusionist,')
a('//     ranger, assassin. Paladin, druid and monk never')
a('//     multi-class (the print lists no such combo).')
a('//   - the XP rule: experience is always divided')
a('//     evenly among the classes of the combination.')
a('//   - dual-class judgment pins only what the print')
a('//     says here: the race gate and the two prime')
a('//     gates, plus the retained hit dice and the')
a('//     negated-XP-on-old-use rule recorded in the')
a('//     comments; the level-exceeds mechanics belong to')
a('//     the engine rounds that consume them.')
a('//')
a('// DATA-DRIVEN (the standing scope): future UA or')
a('// Dragon combos land as appended rows or bits.')
a('// ============================================================================')
a('')
a('#pragma once')
a('')
a('#include <cstdint>')
a('')
a('namespace rules {')
a('')
a('// ---- the combo alphabet (class bits) ----')
a('')
a('static const int MC_FIGHTER = ' + str(MC_FIGHTER) + ';')
a('static const int MC_MAGIC_USER = ' + str(MC_MAGIC_USER) + ';')
a('static const int MC_CLERIC = ' + str(MC_CLERIC) + ';')
a('static const int MC_THIEF = ' + str(MC_THIEF) + ';')
a('static const int MC_ILLUSIONIST = ' + str(MC_ILLUSIONIST) + ';')
a('static const int MC_RANGER = ' + str(MC_RANGER) + ';')
a('static const int MC_ASSASSIN = ' + str(MC_ASSASSIN) + ';')
a('')
a('// ---- the per-race combination table ----')
a('// Race order: human, dwarf, elf, gnome,')
a('// half-elf, halfling, half-orc (the CharRace')
a('// order). Human has no multi-class combos.')
a('')
a('inline int multiClassComboCount(int race) {')
a('    static const int kCount[7] = {')
for row in combos:
    a('        ' + str(len(row)) + ',')
a('    };')
a('    if (race < 0) race = 0;')
a('    if (race > 6) race = 6;')
a('    return kCount[race];')
a('}')
a('')
a('// The combo bitmask at index i of the race')
a('// list (clamped to the list).')
a('inline int multiClassCombo(int race, int i) {')
a('    static const int kCombos[7][8] = {')
for row in combos:
    if not row:
        a('        { 0, 0, 0, 0, 0, 0, 0, 0 },')
    else:
        cells = [str(m) for m in row]
        while len(cells) < 8:
            cells.append('0')
        a('        { ' + ', '.join(cells) + ' },')
a('    };')
a('    int n = multiClassComboCount(race);')
a('    if (n == 0) return 0;')
a('    if (i < 0) i = 0;')
a('    if (i > n - 1) i = n - 1;')
a('    return kCombos[race < 0 ? 0 : (race > 6 ? 6 : race)][i];')
a('}')
a('')
a('// True when mask is one of the printed')
a('// combos for the race.')
a('inline bool multiClassAllowed(int race, int mask) {')
a('    if (mask == 0) return false;')
a('    for (int i = 0; i < multiClassComboCount(race); ++i)')
a('        if (multiClassCombo(race, i) == mask) return true;')
a('    return false;')
a('}')
a('')
a('// True when the race has any multi-class')
a('// combos at all (false for humans, who')
a('// dual-class instead).')
a('inline bool multiClassPossible(int race) {')
a('    return multiClassComboCount(race) > 0;')
a('}')
a('')
a('// ---- the hit-point and XP machinery ----')
a('')
a('// The multi-class hit-point quotient: the')
a('// rolled dice of all classes plus the CON')
a('// adjustment, divided by the class count;')
a('// fractions under one half drop, one half')
a('// and up rounds up (PHB: hit points are')
a('// determined by dividing the sum by the')
a('// number of classes, dropping fractions')
a('// under 1/2, rounding 1/2 and up).')
a('inline int multiclassHpQuotient(int rolledTotal,')
a('                               int nClasses) {')
a('    if (nClasses < 1) nClasses = 1;')
a('    return (2 * rolledTotal + nClasses)')
a('           / (2 * nClasses);')
a('}')
a('')
a('// The XP rule: experience is always')
a('// divided evenly among the classes (any')
a('// remainder is not earned while the')
a('// division is even in play).')
a('inline int multiclassXpShare(int totalXp,')
a('                            int nClasses) {')
a('    if (nClasses < 1) nClasses = 1;')
a('    return totalXp / nClasses;')
a('}')
a('')
a('// The stalled-hit-dice rule: a class that')
a('// can no longer progress (its level has')
a('// reached the cap) contributes no further')
a('// hit dice to the quotient.')
a('inline bool multiclassHitDieStalled(int classLevel,')
a('                                    int levelCap) {')
a('    return classLevel >= levelCap;')
a('}')
a('')
a('// ---- the printed multi-class allowances ----')
a('')
a('// A multi-classed thief functions only with')
a('// thief armor and weaponry (the limitation of')
a('// the thief class only).')
a('inline bool multiclassThiefLimited(int mask) {')
a('    return (mask & MC_THIEF) != 0;')
a('}')
a('')
a('// A multi-classed cleric may use edged')
a('// weapons (the print).')
a('inline bool multiclassClericEdgedOk(int mask) {')
a('    return (mask & MC_CLERIC) != 0;')
a('}')
a('')
a('// The half-elf multi-class cleric WIS')
a('// minimum: 13 (vs the single-class 9).')
a('inline int halfelfClericWisMin() {')
a('    return 13;')
a('}')
a('')
a('// ---- the dual-class gates (human only) ----')
a('')
a('static const int DUAL_CLASS_OLD_PRIME_MIN = 15;')
a('static const int DUAL_CLASS_NEW_PRIME_MIN = 17;')
a('')
a('// True only for humans (the print: humans')
a('// may not multi-class; they may change class).')
a('inline bool dualClassRaceAllowed(int race) {')
a('    return race == 0;')
a('}')
a('')
a('// The prime gates: 15+ in the prime')
a('// requisite of the original class, 17+ in')
a('// the prime requisite of the new class.')
a('inline bool dualClassPrimeGate(int oldPrime,')
a('                              int newPrime) {')
a('    return oldPrime >= DUAL_CLASS_OLD_PRIME_MIN')
a('           && newPrime >= DUAL_CLASS_NEW_PRIME_MIN;')
a('}')
a('')
a('// The printed example, pinned: a 6th-level')
a('// fighter switches to magic-user - the six')
a('// d10 hit dice and hit points are retained,')
a('// all functions begin at 1st level in the')
a('// new class, and using old-class capabilities')
a('// during an adventure negates the XP earned')
a('// for it; once the new-class level exceeds')
a('// the old, the character gains the new-class')
a('// hit die per level up to its class maximum')
a('// and may mix functions freely (each class')
a('// restrictions to its own armor and weapons).')
a('// (Recorded as comments: engine rounds')
a('// consume these mechanics.)')
a('')
a('} // namespace rules')

create('rules/multiclass.h',
       'The multi-class and dual-class rules (R185)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/multiclass.h',
      '#include "rules/palrangerspells.h"  // R184: the paladin and ranger spell layers',
      '#include "rules/palrangerspells.h"  // R184: the paladin and ranger spell layers'
      + NL + '#include "rules/multiclass.h"  // R185: the multi-class and dual-class rules')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R185 battery audit (census 102)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R185: the multi-class and dual-class audit ----')
a('    // Every race x combo cell, the quotient and split')
a('    // ladders, the allowances and the dual-class gates.')
a('    {')
a('        int bad = 0;')
a('        // the combo counts (human 0, dwarf 1, elf 4,')
a('        // gnome 3, half-elf 8, halfling 1, half-orc 5)')
a('        static const int kCount[7] = {')
for row in combos:
    a('            ' + str(len(row)) + ',')
a('        };')
a('        for (int r = 0; r < 7; ++r)')
a('            if (rules::multiClassComboCount(r)')
a('                != kCount[r]) ++bad;')
a('        // every printed combo, positive')
for r, row in enumerate(combos):
    for m in row:
        a('        if (!rules::multiClassAllowed(' + str(r) + ','
          + ' ' + str(m) + ')) ++bad;')
a('        // the negative probes: unprinted combos')
a('        if (rules::multiClassAllowed(0,')
a('            rules::MC_FIGHTER | rules::MC_THIEF)) ++bad;')
a('        if (rules::multiClassPossible(0)) ++bad;')
a('        if (rules::multiClassAllowed(1,')
a('            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;')
a('        if (rules::multiClassAllowed(2,')
a('            rules::MC_CLERIC | rules::MC_FIGHTER)) ++bad;')
a('        if (rules::multiClassAllowed(3,')
a('            rules::MC_FIGHTER | rules::MC_RANGER)) ++bad;')
a('        if (rules::multiClassAllowed(5,')
a('            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;')
a('        if (rules::multiClassAllowed(6,')
a('            rules::MC_FIGHTER | rules::MC_ILLUSIONIST)) ++bad;')
a('        if (rules::multiClassAllowed(4, 0)) ++bad;')
a('        if (rules::multiClassAllowed(4, 1)) ++bad;')
a('        // the clamped reads: index past the list')
a('        // reads the last combo')
a('        if (rules::multiClassCombo(4, 8)')
a('            != (rules::MC_FIGHTER | rules::MC_MAGIC_USER')
a('               | rules::MC_THIEF)) ++bad;')
a('        if (rules::multiClassCombo(4, 99)')
a('            != (rules::MC_FIGHTER | rules::MC_MAGIC_USER')
a('               | rules::MC_THIEF)) ++bad;')
a('        if (rules::multiClassCombo(0, 3) != 0) ++bad;')
a('        if (rules::multiClassCombo(1, 7)')
a('            != (rules::MC_FIGHTER | rules::MC_THIEF)) ++bad;')
a('        // the hit-point quotient ladder: fractions')
a('        // under one half drop, one half and up')
a('        // rounds up')
a('        if (rules::multiclassHpQuotient(7, 2) != 4) ++bad;')
a('        if (rules::multiclassHpQuotient(6, 2) != 3) ++bad;')
a('        if (rules::multiclassHpQuotient(5, 2) != 3) ++bad;')
a('        if (rules::multiclassHpQuotient(4, 2) != 2) ++bad;')
a('        if (rules::multiclassHpQuotient(3, 2) != 2) ++bad;')
a('        if (rules::multiclassHpQuotient(10, 3) != 3) ++bad;')
a('        if (rules::multiclassHpQuotient(11, 3) != 4) ++bad;')
a('        if (rules::multiclassHpQuotient(13, 3) != 4) ++bad;')
a('        if (rules::multiclassHpQuotient(14, 3) != 5) ++bad;')
a('        if (rules::multiclassHpQuotient(9, 3) != 3) ++bad;')
a('        if (rules::multiclassHpQuotient(8, 3) != 3) ++bad;')
a('        if (rules::multiclassHpQuotient(0, 0) != 0) ++bad;')
a('        // the even XP split')
a('        if (rules::multiclassXpShare(3000, 2) != 1500) ++bad;')
a('        if (rules::multiclassXpShare(900, 3) != 300) ++bad;')
a('        if (rules::multiclassXpShare(3000, 3) != 1000) ++bad;')
a('        if (rules::multiclassXpShare(0, 2) != 0) ++bad;')
a('        // the stalled-hit-dice rule')
a('        if (!rules::multiclassHitDieStalled(9, 9)) ++bad;')
a('        if (!rules::multiclassHitDieStalled(11, 9)) ++bad;')
a('        if (rules::multiclassHitDieStalled(8, 9)) ++bad;')
a('        if (rules::multiclassHitDieStalled(0, 9)) ++bad;')
a('        // the allowances')
a('        if (!rules::multiclassThiefLimited(')
a('            rules::MC_FIGHTER | rules::MC_THIEF)) ++bad;')
a('        if (rules::multiclassThiefLimited(')
a('            rules::MC_CLERIC | rules::MC_FIGHTER)) ++bad;')
a('        if (rules::multiclassThiefLimited(')
a('            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;')
a('        if (!rules::multiclassClericEdgedOk(')
a('            rules::MC_CLERIC | rules::MC_FIGHTER)) ++bad;')
a('        if (rules::multiclassClericEdgedOk(')
a('            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;')
a('        // the half-elf cleric WIS minimum')
a('        if (rules::halfelfClericWisMin() != 13) ++bad;')
a('        // the dual-class gates')
a('        if (!rules::dualClassRaceAllowed(0)) ++bad;')
a('        if (rules::dualClassRaceAllowed(1)) ++bad;')
a('        if (rules::dualClassRaceAllowed(2)) ++bad;')
a('        if (rules::dualClassRaceAllowed(3)) ++bad;')
a('        if (rules::dualClassRaceAllowed(4)) ++bad;')
a('        if (rules::dualClassRaceAllowed(5)) ++bad;')
a('        if (rules::dualClassRaceAllowed(6)) ++bad;')
a('        if (!rules::dualClassPrimeGate(15, 17)) ++bad;')
a('        if (!rules::dualClassPrimeGate(16, 18)) ++bad;')
a('        if (rules::dualClassPrimeGate(14, 17)) ++bad;')
a('        if (rules::dualClassPrimeGate(15, 16)) ++bad;')
a('        if (rules::dualClassPrimeGate(9, 9)) ++bad;')
a('        if (rules::DUAL_CLASS_OLD_PRIME_MIN != 15) ++bad;')
a('        if (rules::DUAL_CLASS_NEW_PRIME_MIN != 17) ++bad;')
a('        printf("R185 multi-class and dual-class audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert every probe (the R184b lesson: simulate
# the negative probes too, against the clamped tables)

def combo(r, i):
    n = len(combos[r])
    if n == 0:
        return 0
    i = min(max(i, 0), n - 1)
    return combos[r][i]

def allowed(r, mask):
    return mask != 0 and mask in combos[r]

def hpq(total, n):
    if n < 1:
        n = 1
    return (2 * total + n) // (2 * n)

for r, m in [(1, MC_FIGHTER | MC_THIEF),
             (2, MC_FIGHTER | MC_MAGIC_USER),
             (2, MC_FIGHTER | MC_THIEF),
             (2, MC_MAGIC_USER | MC_THIEF),
             (2, MC_FIGHTER | MC_MAGIC_USER | MC_THIEF),
             (3, MC_FIGHTER | MC_ILLUSIONIST),
             (3, MC_ILLUSIONIST | MC_THIEF),
             (4, MC_CLERIC | MC_RANGER),
             (4, MC_CLERIC | MC_FIGHTER | MC_MAGIC_USER),
             (6, MC_CLERIC | MC_ASSASSIN)]:
    assert allowed(r, m), ('positive probe failed', r, m)
for r, m in [(0, MC_FIGHTER | MC_THIEF), (1, MC_FIGHTER | MC_MAGIC_USER),
             (2, MC_CLERIC | MC_FIGHTER), (3, MC_FIGHTER | MC_RANGER),
             (6, MC_FIGHTER | MC_ILLUSIONIST), (4, 0), (4, 1),
             (5, MC_FIGHTER | MC_MAGIC_USER)]:
    assert not allowed(r, m), ('negative probe failed', r, m)
assert combo(4, 8) == MC_FIGHTER | MC_MAGIC_USER | MC_THIEF
assert combo(4, 99) == MC_FIGHTER | MC_MAGIC_USER | MC_THIEF
assert combo(0, 3) == 0
assert combo(1, 7) == MC_FIGHTER | MC_THIEF
for args, e in [((7, 2), 4), ((6, 2), 3), ((5, 2), 3), ((4, 2), 2),
                ((3, 2), 2), ((10, 3), 3), ((11, 3), 4), ((13, 3), 4),
                ((14, 3), 5), ((9, 3), 3), ((8, 3), 3), ((0, 0), 0)]:
    assert hpq(*args) == e, ('quotient', args, hpq(*args), e)
assert 3000 // 2 == 1500 and 900 // 3 == 300 and 3000 // 3 == 1000

patch('regtest.cpp',
      'R185 multi-class and dual-class audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the R185 box flipped
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'R185 multi-class and dual-class - PINNED',
      '- R185 multi-class and dual-class - the split'
      + NL + '      experience machinery, the hit-dice and'
      + NL + '      hit-point conventions, and the two-class'
      + NL + '      rules.',
      '- [x] R185 multi-class and dual-class - PINNED:'
      + NL + '      rules/multiclass.h CREATED: the per-race'
      + NL + '      MULTI-CLASS combination table (dwarf 1,'
      + NL + '      elf 4, gnome 3, half-elf 8, halfling 1,'
      + NL + '      half-orc 5, human 0 - every printed combo'
      + NL + '      as a class bitmask), the hit-point'
      + NL + '      quotient (sum the dice, adjust for CON,'
      + NL + '      divide by the class count, drop fractions'
      + NL + '      under 1/2, round 1/2 and up), the even XP'
      + NL + '      split, the stalled-hit-dice rule (a class'
      + NL + '      at its cap gives no further dice), the'
      + NL + '      thief-armor limitation, the cleric'
      + NL + '      edged-weapons allowance, the half-elf'
      + NL + '      multi-class cleric WIS 13, and the'
      + NL + '      human-only dual-class gates (15+ old'
      + NL + '      prime, 17+ new prime; the retained hit'
      + NL + '      dice, the 1st-level functions, the'
      + NL + '      negated XP on old-class use and the'
      + NL + '      level-exceeds mechanics recorded in the'
      + NL + '      header comments for the engine rounds).'
      + NL + '      The R185 battery audit walks every combo'
      + NL + '      cell, ladder and gate. Census 102.')

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R185 landed the multi-class and dual-class',
      'census 101. Next: R185 multi-class and'
      + NL + 'dual-class.',
      'census 101. Next: R185 multi-class and'
      + NL + 'dual-class.'
      + NL + 'R185 landed the multi-class and dual-class'
      + NL + 'rules: rules/multiclass.h CREATED (the 22'
      + NL + 'per-race combos, the hit-point quotient, the'
      + NL + 'even XP split, the stalled hit dice, the'
      + NL + 'thief and cleric allowances, the half-elf'
      + NL + 'cleric WIS 13, the dual-class gates). New'
      + NL + 'R185 battery audit; census 102. Next: R186'
      + NL + 'the bard (Appendix II).')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R185 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R185 note: 5 patches; census 102 (one new audit);')
print('real gate: md5sum rules/multiclass.h')
print('commit: R185: the multi-class and dual-class rules pinned -')
print('the combos, the quotient and the gates (census 102)')

