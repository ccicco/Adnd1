#!/usr/bin/env python3
# R188 splice: the prime requisite XP adjustment
# (the verify round for the queued box).
#
# rules/xpadjust.h is CREATED: the printed
# per-class +10% of earned experience gates,
# every one from the PHB class sections:
# fighter STR 16+; magic-user INT 16+; cleric
# WIS 16+ (with the printed worked example:
# 975 XP -> +98 -> 1073, fractions round
# up); thief DEX 16+; paladin STR and WIS
# both 16+; ranger STR, INT and WIS all 16+;
# druid WIS and CHA both 16+; illusionist,
# assassin and monk NEVER (printed).
#
# rules/character.cpp: the engine ladder
# primeRequisitePct (+10, +5, 0, -10, -20)
# is verified - the +10 rung at 16+ is the
# printed rule; the +5, 0, -10 and -20 rungs
# are ENGINE CONVENTION, unsourced against
# the 1e print (checked: the PHB class
# sections carry only the +10 percent notes;
# the DMG ADJUSTMENT AND DIVISION OF
# EXPERIENCE POINTS section has no
# prime-requisite ladder; the phrase prime
# requisite does not appear in the DMG at
# all). The comment now records the verify.
#
# regtest.cpp: the include lands WITH the
# audit (the R179 lesson); the R188 battery
# audit walks every gate, positive and
# negative, and the rounding ladder. Census
# 105.
#
# Patches: 6.

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
# Patch 1: rules/xpadjust.h CREATED
# ---------------------------------------------------------------------------

# the printed gates, pre-asserted here:
# base: fighter STR, magic-user INT, cleric
# WIS, thief DEX - each 16 or more; subclass:
# paladin STR and WIS; ranger STR, INT and
# WIS; druid WIS and CHA; illusionist,
# assassin and monk never.
def base_q(ci, s, i, w, d):
    return {0: s >= 16, 1: i >= 16, 2: w >= 16, 3: d >= 16}.get(ci, False)


def sub_q(sub, s, i, w, c):
    if sub == 0:
        return s >= 16 and w >= 16
    if sub == 1:
        return s >= 16 and i >= 16 and w >= 16
    if sub == 2:
        return w >= 16 and c >= 16
    return False   # illusionist, assassin, monk


# positive probes (every class, at the
# boundary 16)
assert base_q(0, 16, 10, 10, 10)
assert base_q(1, 10, 16, 10, 10)
assert base_q(2, 10, 10, 16, 10)
assert base_q(3, 10, 10, 10, 16)
assert sub_q(0, 16, 10, 16, 10)
assert sub_q(1, 16, 16, 16, 10)
assert sub_q(2, 10, 10, 16, 16)
# negative probes at 15 (the R184b mirror
# rule: every probe verified against the
# pinned logic)
assert not base_q(0, 15, 18, 18, 18)
assert not base_q(1, 18, 15, 18, 18)
assert not base_q(2, 18, 18, 15, 18)
assert not base_q(3, 18, 18, 18, 15)
assert not sub_q(0, 15, 10, 18, 10)
assert not sub_q(0, 18, 10, 15, 10)
assert not sub_q(1, 15, 16, 16, 10)
assert not sub_q(1, 16, 15, 16, 10)
assert not sub_q(1, 16, 16, 15, 10)
assert not sub_q(2, 10, 10, 15, 18)
assert not sub_q(2, 10, 10, 18, 15)
# the never-classes, even at 18 in every
# relevant score
assert not sub_q(3, 10, 18, 10, 10)   # illusionist (DEX not read)
assert not sub_q(4, 18, 18, 10, 10)   # assassin
assert not sub_q(5, 18, 10, 18, 10)   # monk
# out-of-range indices
assert not base_q(7, 18, 18, 18, 18)
assert not base_q(-1, 18, 18, 18, 18)
assert not sub_q(6, 18, 18, 18, 18)
assert not sub_q(99, 18, 18, 18, 18)

# the rounding ladder: the printed example
# 975 -> +98 -> 1073 (fractions round up)
def bonus(xp):
    return (xp + 9) // 10 if xp > 0 else 0

for xp, e in [(975, 98), (0, 0), (1, 1), (10, 1), (11, 2),
              (100, 10), (9750, 975), (974, 98), (976, 98)]:
    assert bonus(xp) == e, ('rounding', xp, bonus(xp), e)
assert 975 + bonus(975) == 1073

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/xpadjust.h')
a('// The prime requisite XP adjustment (R188).')
a('//')
a('// The printed per-class +10% of earned experience gates,')
a('// every one from the PHB class sections:')
a('//   fighter      strength 16 or more')
a('//   magic-user   intelligence 16 or more')
a('//   cleric       wisdom 16 or more (worked example:')
a('//                975 XP, +98, total 1073)')
a('//   thief        dexterity 16 or more')
a('//   paladin      strength AND wisdom both above 15')
a('//   ranger       strength, intelligence AND wisdom')
a('//                all above 15')
a('//   druid        wisdom AND charisma both above 15')
a('//   illusionist  never (the print)')
a('//   assassin     never (the print)')
a('//   monk         never (the print)')
a('//')
a('// JUDGMENTs:')
a('//   - every gate pins at 16 or more (the print says')
a('//     above 15, 16 or more, or in excess of 15 - one')
a('//     convention across the sections).')
a('//   - the bonus rounds UP on fractions: the printed')
a('//     example 975 x .10 = 97.5, or 98 XP, total 1073.')
a('//     The formula is (awarded + 9) / 10, the ceiling of')
a('//     one tenth.')
a('//   - the engine ladder primeRequisitePct')
a('//     (rules/character.cpp: +10, +5, 0, -10, -20')
a('//     percent by score) is VERIFIED as to its +10 rung')
a('//     only. The +5, 0, -10 and -20 rungs are ENGINE')
a('//     CONVENTION, unsourced against the 1e print: the')
a('//     PHB class sections carry only the +10 percent')
a('//     notes, the DMG ADJUSTMENT AND DIVISION OF')
a('//     EXPERIENCE POINTS section has no prime-requisite')
a('//     ladder, and the phrase prime requisite does not')
a('//     appear in the DMG at all. The character.cpp')
a('//     comment records this verify (the R188 note).')
a('//   - multi-classed characters divide earned experience')
a('//     evenly before any bonus (the R185 XP rule); the')
a('//     per-class gates here are per single class.')
a('//')
a('// DATA-DRIVEN (the standing scope).')
a('// ============================================================================')
a('')
a('#pragma once')
a('')
a('#include "classes.h"')
a('#include "subclasses.h"')
a('')
a('#include <cstdint>')
a('')
a('namespace rules {')
a('')
a('// ---- the base-class gates (+10% of earned) ----')
a('')
a('// True when the class earns the +10% bonus: fighter')
a('// STR, magic-user INT, cleric WIS, thief DEX - each')
a('// 16 or more. Any other index: false.')
a('inline bool xpBonusQualifiesBase(int classIndex,')
a('                             int str, int int_,')
a('                             int wis, int dex) {')
a('    switch (classIndex) {')
a('        case CLASS_FIGHTER:    return str >= 16;')
a('        case CLASS_MAGIC_USER: return int_ >= 16;')
a('        case CLASS_CLERIC:     return wis >= 16;')
a('        case CLASS_THIEF:      return dex >= 16;')
a('    }')
a('    return false;')
a('}')
a('')
a('// The +10 percent when the base-class gate holds,')
a('// else 0.')
a('inline int baseXpBonusPct(int classIndex,')
a('                       int str, int int_,')
a('                       int wis, int dex) {')
a('    return xpBonusQualifiesBase(classIndex, str, int_,')
a('                               wis, dex) ? 10 : 0;')
a('}')
a('')
a('// ---- the subclass gates ----')
a('')
a('// True when the subclass earns the +10% bonus:')
a('// paladin STR and WIS; ranger STR, INT and WIS;')
a('// druid WIS and CHA - each 16 or more.')
a('// Illusionist, assassin and monk NEVER (the print).')
a('inline bool xpBonusQualifiesSubclass(int sub,')
a('                                 int str, int int_,')
a('                                 int wis, int cha) {')
a('    switch (sub) {')
a('        case SUB_PALADIN:')
a('            return str >= 16 && wis >= 16;')
a('        case SUB_RANGER:')
a('            return str >= 16 && int_ >= 16 && wis >= 16;')
a('        case SUB_DRUID:')
a('            return wis >= 16 && cha >= 16;')
a('    }')
a('    return false;   // illusionist, assassin, monk')
a('}')
a('')
a('// The +10 percent when the subclass gate holds,')
a('// else 0.')
a('inline int subclassXpBonusPct(int sub,')
a('                          int str, int int_,')
a('                          int wis, int cha) {')
a('    return xpBonusQualifiesSubclass(sub, str, int_,')
a('                                  wis, cha) ? 10 : 0;')
a('}')
a('')
a('// ---- the worked-example rounding ----')
a('')
a('// The +10% bonus amount, fractions rounding UP')
a('// (the printed example: 975 x .10 = 97.5, or 98).')
a('inline int xpBonusAmount(int awardedXp) {')
a('    if (awardedXp <= 0) return 0;')
a('    return (awardedXp + 9) / 10;')
a('}')
a('')
a('// The total with the bonus (the printed example:')
a('// 975 -> 98 -> 1073).')
a('inline int xpBonusTotal(int awardedXp) {')
a('    return awardedXp + xpBonusAmount(awardedXp);')
a('}')
a('')
a('} // namespace rules')

create('rules/xpadjust.h',
       'The prime requisite XP adjustment (R188)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/xpadjust.h',
      '#include "rules/subclassspecials.h"  // R187: the per-subclass specials',
      '#include "rules/subclassspecials.h"  // R187: the per-subclass specials'
      + NL + '#include "rules/xpadjust.h"  // R188: the prime requisite XP adjustment')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R188 battery audit (census 105)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R188: the prime requisite XP adjustment audit ----')
a('    // Every printed gate, positive and negative, and the')
a('    // worked-example rounding ladder.')
a('    {')
a('        int bad = 0;')
a('        // the base-class gates at the 16 boundary')
a('        if (!rules::xpBonusQualifiesBase(')
a('                rules::CLASS_FIGHTER, 16, 10, 10, 10)) ++bad;')
a('        if (!rules::xpBonusQualifiesBase(')
a('                rules::CLASS_MAGIC_USER, 10, 16, 10, 10)) ++bad;')
a('        if (!rules::xpBonusQualifiesBase(')
a('                rules::CLASS_CLERIC, 10, 10, 16, 10)) ++bad;')
a('        if (!rules::xpBonusQualifiesBase(')
a('                rules::CLASS_THIEF, 10, 10, 10, 16)) ++bad;')
a('        // the negative probes at 15 (the gate score fails)')
a('        if (rules::xpBonusQualifiesBase(')
a('                rules::CLASS_FIGHTER, 15, 18, 18, 18)) ++bad;')
a('        if (rules::xpBonusQualifiesBase(')
a('                rules::CLASS_MAGIC_USER, 18, 15, 18, 18)) ++bad;')
a('        if (rules::xpBonusQualifiesBase(')
a('                rules::CLASS_CLERIC, 18, 18, 15, 18)) ++bad;')
a('        if (rules::xpBonusQualifiesBase(')
a('                rules::CLASS_THIEF, 18, 18, 18, 15)) ++bad;')
a('        // the pct wrappers')
a('        if (rules::baseXpBonusPct(')
a('                rules::CLASS_FIGHTER, 16, 10, 10, 10) != 10) ++bad;')
a('        if (rules::baseXpBonusPct(')
a('                rules::CLASS_FIGHTER, 15, 10, 10, 10) != 0) ++bad;')
a('        // out-of-range base indices')
a('        if (rules::xpBonusQualifiesBase(')
a('                7, 18, 18, 18, 18)) ++bad;')
a('        if (rules::xpBonusQualifiesBase(')
a('                -1, 18, 18, 18, 18)) ++bad;')
a('        // the subclass gates at the 16 boundary')
a('        if (!rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_PALADIN, 16, 10, 16, 10)) ++bad;')
a('        if (!rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_RANGER, 16, 16, 16, 10)) ++bad;')
a('        if (!rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_DRUID, 10, 10, 16, 16)) ++bad;')
a('        // the paladin negative probes: STR or WIS at 15')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_PALADIN, 15, 10, 18, 10)) ++bad;')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_PALADIN, 18, 10, 15, 10)) ++bad;')
a('        // the ranger negative probes: any of the three at 15')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_RANGER, 15, 16, 16, 10)) ++bad;')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_RANGER, 16, 15, 16, 10)) ++bad;')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_RANGER, 16, 16, 15, 10)) ++bad;')
a('        // the druid negative probes: WIS or CHA at 15')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_DRUID, 10, 10, 15, 18)) ++bad;')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_DRUID, 10, 10, 18, 15)) ++bad;')
a('        // the never-classes, even at 18 in every score')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_ILLUSIONIST, 18, 18, 18, 18)) ++bad;')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_ASSASSIN, 18, 18, 18, 18)) ++bad;')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                rules::SUB_MONK, 18, 18, 18, 18)) ++bad;')
a('        // the pct wrapper and out-of-range indices')
a('        if (rules::subclassXpBonusPct(')
a('                rules::SUB_RANGER, 16, 16, 16, 10) != 10) ++bad;')
a('        if (rules::subclassXpBonusPct(')
a('                rules::SUB_MONK, 18, 18, 18, 18) != 0) ++bad;')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                6, 18, 18, 18, 18)) ++bad;')
a('        if (rules::xpBonusQualifiesSubclass(')
a('                99, 18, 18, 18, 18)) ++bad;')
a('        // the rounding ladder: the printed worked')
a('        // example and the edges')
a('        if (rules::xpBonusAmount(975) != 98) ++bad;')
a('        if (rules::xpBonusTotal(975) != 1073) ++bad;')
a('        if (rules::xpBonusAmount(974) != 98) ++bad;')
a('        if (rules::xpBonusAmount(976) != 98) ++bad;')
a('        if (rules::xpBonusAmount(0) != 0) ++bad;')
a('        if (rules::xpBonusAmount(1) != 1) ++bad;')
a('        if (rules::xpBonusAmount(10) != 1) ++bad;')
a('        if (rules::xpBonusAmount(11) != 2) ++bad;')
a('        if (rules::xpBonusAmount(100) != 10) ++bad;')
a('        if (rules::xpBonusAmount(9750) != 975) ++bad;')
a('        if (rules::xpBonusAmount(-50) != 0) ++bad;')
a('        if (rules::xpBonusTotal(0) != 0) ++bad;')
a('        printf("R188 prime requisite XP adjustment audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

patch('regtest.cpp',
      'R188 prime requisite XP adjustment audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: rules/character.cpp - the verify recorded
# ---------------------------------------------------------------------------

patch('rules/character.cpp',
      'ENGINE CONVENTION, unsourced against the 1e print',
      '// Prime requisite XP adjustment (PHB p.12-13)',
      '// Prime requisite XP adjustment - the +10 rung at 16+ is the'
      + NL + '// printed rule (the class sections); the +5, 0, -10 and -20'
      + NL + '// rungs are ENGINE CONVENTION, unsourced against the 1e print'
      + NL + '// (verified R188) - the PHB class sections carry only the'
      + NL + '// +10 percent notes, the DMG ADJUSTMENT AND DIVISION OF'
      + NL + '// EXPERIENCE POINTS section has no prime-requisite ladder,'
      + NL + '// and the phrase prime requisite does not appear in the DMG'
      + NL + '// at all. The printed per-class gates and the worked-example'
      + NL + '// rounding (975 -> +98 -> 1073) live in rules/xpadjust.h.')

# ---------------------------------------------------------------------------
# Patch 5: tools/phb_gap_report.md - the R188 box flipped
# ---------------------------------------------------------------------------

box_old = ('- [ ] **Prime requisite XP adjustment (the class'
           + NL + '      sections)** - the engine ladder reads +10, +5,'
           + NL + '      0, -10, -20 percent by prime requisite score;'
           + NL + '      the print carries the +10 percent'
           + NL + '      high-prime-requisite notes in the class'
           + NL + '      sections. The remaining rungs are unsourced'
           + NL + '      against the 1e print - verify, then repin or'
           + NL + '      record as convention.')

box_new = ('- [x] **Prime requisite XP adjustment - PINNED R188:**'
           + NL + '      rules/xpadjust.h CREATED: the printed per-class'
           + NL + '      +10% of earned experience gates (fighter STR,'
           + NL + '      magic-user INT, cleric WIS, thief DEX; paladin'
           + NL + '      STR and WIS, ranger STR INT and WIS, druid WIS'
           + NL + '      and CHA - each 16 or more; illusionist,'
           + NL + '      assassin and monk never) and the worked-example'
           + NL + '      rounding (975 -> +98 -> 1073, fractions round'
           + NL + '      up). The verify: the engine ladder +10 rung is'
           + NL + '      the printed rule; the +5, 0, -10 and -20 rungs'
           + NL + '      are ENGINE CONVENTION, unsourced - the PHB'
           + NL + '      class sections carry only the +10 percent'
           + NL + '      notes, the DMG adjustment section has no'
           + NL + '      prime-requisite ladder and the phrase does not'
           + NL + '      appear in the DMG at all. The character.cpp'
           + NL + '      comment records the verify. The R188 battery'
           + NL + '      audit walks every gate and the rounding. Census'
           + NL + '      105.')

t = rd('tools/phb_gap_report.md')
if 'Prime requisite XP adjustment - PINNED R188' not in t:
    assert t.count(box_old) == 1, 'R188 box anchor not unique'
else:
    assert t.count(box_old) == 0, 'R188 box old text lingers'

patch('tools/phb_gap_report.md',
      'Prime requisite XP adjustment - PINNED R188',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 6: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R188 landed the prime requisite XP adjustment',
      'census 104. Next: the gap report names the next'
      + NL + 'round.',
      'census 104. Next: the gap report names the next'
      + NL + 'round.'
      + NL + 'R188 landed the prime requisite XP adjustment:'
      + NL + 'rules/xpadjust.h CREATED (the printed per-class'
      + NL + '+10% gates, the worked-example rounding), and the'
      + NL + 'character.cpp comment now records the verify - the'
      + NL + 'engine +5/0/-10/-20 rungs are unsourced convention'
      + NL + '(the DMG has no prime-requisite ladder at all). New'
      + NL + 'R188 battery audit; census 105. Next: the gap report'
      + NL + 'names the next round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 6, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R188 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R188 note: 6 patches; census 105 (one new audit);')
print('real gate: md5sum rules/xpadjust.h')
print('commit: R188: the prime requisite XP adjustment pinned - the printed')
print('gates and the convention record (census 105)')

