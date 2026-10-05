#!/usr/bin/env python3
# R190 splice: the starting money by class (the
# EQUIPPING THE CHARACTER section - a queued
# box).
#
# rules/startmoney.h is CREATED: the printed
# STARTING MONEY table of the PHB MONEY section
# - cleric 3d6 (30-180 gp), fighter 5d4
# (50-200), magic-user 2d4 (20-80), thief 2d6
# (20-120) - each a dice roll TIMES 10 gold
# pieces, plus the printed MONK row 5-20 gp
# (5d4), the one entry with NO x10 (the DMG
# MONEY section explains: monks are ascetics
# who do not accumulate money). The DMG
# companion pins with it: the PLAYER CHARACTER
# EXPENSES rule - not less than 100 gold pieces
# per level of experience per month.
#
# The engine has NO party-creation money code
# (verified repo-wide) - the box was a
# convention-verify that resolves to a new
# header. Subclass starting money is NOT
# printed (comment only).
#
# regtest.cpp: the include lands WITH the
# audit (the R179 lesson); the R190 battery
# audit walks all five printed rows, the
# clamps, the monk no-x10 finding and the
# support-cost ladder. Census 107.
#
# Patches: 5.

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
# Patch 1: rules/startmoney.h CREATED
# ---------------------------------------------------------------------------

# the printed STARTING MONEY table, in CharClass
# enum order (classes.h: FIGHTER 0, MAGIC_USER 1,
# CLERIC 2, THIEF 3): (dice count, die faces,
# multiplier) - every one of the four is a dice
# roll x 10 gold pieces.
t = [
    (5, 4, 10),   # fighter    5d4 x10 = 50-200
    (2, 4, 10),   # magic-user 2d4 x10 = 20-80
    (3, 6, 10),   # cleric     3d6 x10 = 30-180
    (2, 6, 10),   # thief      2d6 x10 = 20-120
]

hdr = []
a = hdr.append

a('// rules/startmoney.h - the starting money by')
a('// class (the PHB MONEY section, R190).')
a('//')
a('// The printed STARTING MONEY table: every')
a('// class entry is a dice roll TIMES 10 gold')
a('// pieces - cleric 3d6 (30-180 gp), fighter')
a('// 5d4 (50-200), magic-user 2d4 (20-80),')
a('// thief 2d6 (20-120) - except the printed')
a('// MONK row 5-20 gp (5d4), the one entry')
a('// with NO x10. The DMG MONEY section says')
a('// why: monks are ascetics who do not care')
a('// about material possessions and so do')
a('// not accumulate much money prior to')
a('// becoming adventurers.')
a('//')
a('// The engine has no party-creation money')
a('// code; this header is the pin. Subclass')
a('// starting money is NOT printed anywhere in')
a('// the PHB - the paladin and ranger sections')
a('// carry no money note (recorded; any')
a('// subclass convention stays a caller')
a('// judgment).')
a('')
a('#ifndef RULES_STARTMONEY_H')
a('#define RULES_STARTMONEY_H')
a('')
a('namespace rules {')
a('')
a('// The dice count of the starting money roll,')
a('// in CharClass order (fighter, magic-user,')
a('// cleric, thief).')
a('inline int startingMoneyDiceCount(int cls) {')
a('    static const int kCount[4] = {')
for c, _, _ in t:
    a('        ' + str(c) + ',')
a('    };')
a('    if (cls < 0) cls = 0;')
a('    if (cls > 3) cls = 3;')
a('    return kCount[cls];')
a('}')
a('')
a('// The die faces of the starting money roll.')
a('inline int startingMoneyDieFaces(int cls) {')
a('    static const int kFaces[4] = {')
for _, f, _ in t:
    a('        ' + str(f) + ',')
a('    };')
a('    if (cls < 0) cls = 0;')
a('    if (cls > 3) cls = 3;')
a('    return kFaces[cls];')
a('}')
a('')
a('// The gold multiplier: 10 for every printed')
a('// class row.')
a('inline int startingMoneyMultiplier(int cls) {')
a('    static const int kMult[4] = {')
for _, _, m in t:
    a('        ' + str(m) + ',')
a('    };')
a('    if (cls < 0) cls = 0;')
a('    if (cls > 3) cls = 3;')
a('    return kMult[cls];')
a('}')
a('')
a('// The minimum starting gold: dice count x')
a('// multiplier.')
a('inline int startingMoneyMin(int cls) {')
a('    return startingMoneyDiceCount(cls)')
a('           * startingMoneyMultiplier(cls);')
a('}')
a('')
a('// The maximum starting gold: dice count x')
a('// die faces x multiplier.')
a('inline int startingMoneyMax(int cls) {')
a('    return startingMoneyDiceCount(cls)')
a('           * startingMoneyDieFaces(cls)')
a('           * startingMoneyMultiplier(cls);')
a('}')
a('')
a('// ---- the monk row (the print: 5-20 gp,')
a('// 5d4, NO x10) ----')
a('')
a('inline int monkStartingMoneyDiceCount() { return 5; }')
a('inline int monkStartingMoneyDieFaces() { return 4; }')
a('inline int monkStartingMoneyMultiplier() { return 1; }')
a('inline int monkStartingMoneyMin() { return 5; }')
a('inline int monkStartingMoneyMax() { return 20; }')
a('')
a('// ---- the DMG companion (the PLAYER')
a('// CHARACTER EXPENSES rule) ----')
a('')
a('// Not less than 100 gold pieces per level')
a('// of experience per month - support, upkeep,')
a('// equipment and entertainment, deducted')
a('// automatically (the DMG MONEY section).')
a('inline int pcMonthlySupportCost(int level) {')
a('    if (level < 1) level = 1;')
a('    return 100 * level;')
a('}')
a('')
a('} // namespace rules')
a('')
a('#endif // RULES_STARTMONEY_H')

create('rules/startmoney.h',
       '#ifndef RULES_STARTMONEY_H',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/startmoney.h',
      '#include "rules/weapontables.h"  // R189: the weapon weight and damage table',
      '#include "rules/weapontables.h"  // R189: the weapon weight and damage table'
      + NL + '#include "rules/startmoney.h"  // R190: the starting money by class')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R190 battery audit (census 107)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R190: the starting money audit ----')
a('    // All five printed rows, the clamps, the')
a('    // monk no-x10 finding, the support ladder.')
a('    {')
a('        int bad = 0;')
a('        // the four class rows, cell by cell')
a('        // (fighter 5d4x10, magic-user 2d4x10,')
a('        // cleric 3d6x10, thief 2d6x10)')
a('        static const int kCnt[4] = { 5, 2, 3, 2 };')
a('        static const int kFace[4] = { 4, 4, 6, 6 };')
a('        static const int kMult[4] = { 10, 10, 10, 10 };')
a('        static const int kMin[4] = { 50, 20, 30, 20 };')
a('        static const int kMax[4] = { 200, 80, 180, 120 };')
a('        for (int c = 0; c < 4; ++c) {')
a('            if (rules::startingMoneyDiceCount(c) != kCnt[c]) ++bad;')
a('            if (rules::startingMoneyDieFaces(c) != kFace[c]) ++bad;')
a('            if (rules::startingMoneyMultiplier(c) != kMult[c]) ++bad;')
a('            if (rules::startingMoneyMin(c) != kMin[c]) ++bad;')
a('            if (rules::startingMoneyMax(c) != kMax[c]) ++bad;')
a('        }')
a('        // the clamps: out-of-range reads the edges')
a('        if (rules::startingMoneyDiceCount(-5) != 5) ++bad;')
a('        if (rules::startingMoneyMax(-5) != 200) ++bad;')
a('        if (rules::startingMoneyDiceCount(99) != 2) ++bad;')
a('        if (rules::startingMoneyMax(99) != 120) ++bad;')
a('        // the monk row: the print 5-20 gp (5d4)')
a('        // with NO x10 - the one un-multiplied row')
a('        if (rules::monkStartingMoneyDiceCount() != 5) ++bad;')
a('        if (rules::monkStartingMoneyDieFaces() != 4) ++bad;')
a('        if (rules::monkStartingMoneyMultiplier() != 1) ++bad;')
a('        if (rules::monkStartingMoneyMin() != 5) ++bad;')
a('        if (rules::monkStartingMoneyMax() != 20) ++bad;')
a('        // the DMG companion: not less than 100 gp')
a('        // per level per month')
a('        if (rules::pcMonthlySupportCost(1) != 100) ++bad;')
a('        if (rules::pcMonthlySupportCost(5) != 500) ++bad;')
a('        if (rules::pcMonthlySupportCost(12) != 1200) ++bad;')
a('        // the level clamp: 0 reads the 1st')
a('        if (rules::pcMonthlySupportCost(0) != 100) ++bad;')
a('        printf("R190 starting money audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert every probe against the pinned
# tables (the R184b lesson)
assert t[0] == (5, 4, 10) and t[1] == (2, 4, 10)
assert t[2] == (3, 6, 10) and t[3] == (2, 6, 10)
for i, (c, f, m) in enumerate(t):
    assert c * m == [50, 20, 30, 20][i]
    assert c * f * m == [200, 80, 180, 120][i]
# the clamp probes read the table edges
assert t[0][0] == 5 and t[3][0] == 2
# the monk row: min 5, max 20 (5d4 x1)
assert 5 * 1 == 5 and 5 * 4 * 1 == 20

patch('regtest.cpp',
      'R190 starting money audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the R190 box flipped
# ---------------------------------------------------------------------------

box_old = ('- [ ] **Starting money by class (the EQUIPPING THE'
           + NL + '      CHARACTER section)** - the print: cleric 3d6'
           + NL + '      (30-180 gp), fighter 5d4 (50-200), magic-user'
           + NL + '      2d4 (20-80), thief 2d6 (20-120). The engine'
           + NL + '      party-creation convention is unverified'
           + NL + '      against the print.')

box_new = ('- [x] **Starting money by class (the MONEY section) -'
           + NL + '      PINNED R190:** rules/startmoney.h CREATED -'
           + NL + '      the printed STARTING MONEY table: cleric 3d6'
           + NL + '      (30-180 gp), fighter 5d4 (50-200), magic-user'
           + NL + '      2d4 (20-80), thief 2d6 (20-120), every class'
           + NL + '      row a dice roll TIMES 10 gold pieces, plus the'
           + NL + '      printed MONK row 5-20 gp (5d4) - the one entry'
           + NL + '      with NO x10 (the DMG MONEY section explains:'
           + NL + '      monks are ascetics). The DMG companion rule'
           + NL + '      pins with it: not less than 100 gp per level'
           + NL + '      per month support cost. The engine has NO'
           + NL + '      party-creation money code (verified'
           + NL + '      repo-wide) - the unverified-convention worry'
           + NL + '      resolves to a fresh pin; subclass starting'
           + NL + '      money is not printed (recorded). The R190'
           + NL + '      battery audit walks all five rows. Census'
           + NL + '      107.')

t2 = rd('tools/phb_gap_report.md')
if 'Starting money by class (the MONEY section) -' not in t2:
    assert t2.count(box_old) == 1, 'R190 box anchor not unique'
else:
    assert t2.count(box_old) == 0, 'R190 box old text lingers'

patch('tools/phb_gap_report.md',
      'PINNED R190:** rules/startmoney.h CREATED',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R190 landed the starting money',
      'printed notes; the R144/R145 AC standing note closes'
      + NL + 'with the OCR limitation recorded). New R189 battery'
      + NL + 'audit; census 106. Next: the gap report names the next'
      + NL + 'round.',
      'printed notes; the R144/R145 AC standing note closes'
      + NL + 'with the OCR limitation recorded). New R189 battery'
      + NL + 'audit; census 106. Next: the gap report names the next'
      + NL + 'round.'
      + NL + 'R190 landed the starting money by class:'
      + NL + 'rules/startmoney.h CREATED (the PHB STARTING MONEY'
      + NL + 'table - cleric 3d6, fighter 5d4, magic-user 2d4,'
      + NL + 'thief 2d6, all x10 gp; the monk row 5d4 with NO x10,'
      + NL + 'the DMG MONEY-section ascetic note) and the DMG'
      + NL + 'companion pin: the PLAYER CHARACTER EXPENSES rule,'
      + NL + 'not less than 100 gp per level per month'
      + NL + '(pcMonthlySupportCost). New R190 battery audit; census'
      + NL + '107. Next: the gap report names the next round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R190 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R190 note: 5 patches; census 107 (one new audit);')
print('real gate: md5sum rules/startmoney.h')
print('commit: R190: the starting money pinned - the class table,')
print('the monk row and the support-cost companion (census 107)')

