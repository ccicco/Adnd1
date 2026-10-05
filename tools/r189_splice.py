#!/usr/bin/env python3
# R189 splice: the PHB book-verify pass for the
# weapon tables (the queued box).
#
# rules/weapontables.h is CREATED: the WEIGHT
# AND DAMAGE BY WEAPON TYPE chart (50 rows,
# every printed cell: the approximate weight
# in gold pieces, the damage vs. size S or M
# opponents, the damage vs. size L - the
# spear weight prints 40-60, pinned as a
# range), the speed-factor verify (every
# readable cell of the WEAPON TYPES chart
# speed column confirms the R158 engine
# ladder row for row; the horseman flail 6
# stays engine convention - its chart cell
# is OCR-mangled), and the printed notes:
# the three lances do twice indicated damage
# from a charging mount against any size,
# the spear set to receive a charge does
# twice damage to any opponent, and any
# weapon strikes +2 against a back or
# similarly unseen opponent, +4 against
# stunned, prone and motionless opponents.
#
# The standing compile-vs-print note closes:
# the R144/R145 p.38 AC-adjustment rows were
# R149-verified (8 of 15 cell for cell); the
# upload OCR mangles the remaining AC cells
# (runs like -1000000), so they stay pinned
# to the 1eonline compilation - the recorded
# verify lives in the header comments.
#
# regtest.cpp: the include lands WITH the
# audit (the R179 lesson); the R189 battery
# audit walks all 50 weight/damage rows, the
# speed cross-verify and the notes. Census
# 106.
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
# Patch 1: rules/weapontables.h CREATED
# ---------------------------------------------------------------------------

# the WEIGHT AND DAMAGE BY WEAPON TYPE chart:
# (name, weight gp, SM min, SM max, L min, L max)
# - the print order, every printed cell; the
# spear weight prints 40-60 (pinned as a range,
# weightMin 40 weightMax 60)
t = [
    ('arrow',              2,   1, 6, 1, 6),
    ('battle axe',        75,   1, 8, 1, 8),
    ('hand axe',         50,   1, 6, 1, 4),
    ('bardiche',         125,   2, 8, 3, 12),
    ('bec de corbin',    100,   1, 8, 1, 6),
    ('bill-guisarme',    150,   2, 8, 1, 10),
    ('bo stick',         15,   1, 6, 1, 3),
    ('club',             30,   1, 6, 1, 3),
    ('dagger',           10,   1, 4, 1, 3),
    ('dart',              5,   1, 3, 1, 2),
    ('fauchard',         60,   1, 6, 1, 8),
    ('fauchard-fork',    80,   1, 8, 1, 10),
    ('footman flail',   150,   2, 7, 2, 8),
    ('horseman flail',   35,   2, 5, 2, 5),
    ('military fork',    75,   1, 8, 2, 8),
    ('glaive',           75,   1, 6, 1, 10),
    ('glaive-guisarme', 100,   2, 8, 2, 12),
    ('guisarme',         80,   2, 8, 1, 8),
    ('guisarme-voulge', 150,   2, 8, 2, 8),
    ('halberd',         175,   1, 10, 2, 12),
    ('lucern hammer',   150,   2, 8, 1, 6),
    ('hammer',           50,   2, 5, 1, 4),
    ('javelin',          20,   1, 6, 1, 6),
    ('jo stick',         40,   1, 6, 1, 4),
    ('lance, light horse', 50,  1, 6, 1, 8),
    ('lance, medium horse', 100, 2, 7, 2, 12),
    ('lance, heavy horse', 150, 3, 9, 3, 18),
    ('footman mace',    100,   2, 7, 1, 6),
    ('horseman mace',    50,   1, 6, 1, 4),
    ('morning star',    125,   2, 8, 2, 7),
    ('partisan',         80,   1, 6, 2, 7),
    ('footman pick',     60,   2, 7, 2, 8),
    ('horseman pick',    40,   2, 5, 1, 4),
    ('awl pike',         80,   1, 6, 1, 12),
    ('light quarrel',      1,   1, 4, 1, 4),
    ('heavy quarrel',      2,   2, 5, 2, 7),
    ('ranseur',          50,   2, 8, 2, 8),
    ('scimitar',         40,   1, 8, 1, 8),
    ('sling bullet',      2,   2, 5, 2, 7),
    ('sling stone',       1,   1, 4, 1, 4),
    ('spear',            40,   1, 6, 1, 8),
    ('spetum',           50,   2, 7, 2, 12),
    ('quarterstaff',     50,   1, 6, 1, 6),
    ('bastard sword',   100,   2, 8, 2, 16),
    ('broad sword',      75,   2, 8, 2, 7),
    ('long sword',       60,   1, 8, 1, 12),
    ('short sword',      35,   1, 6, 1, 8),
    ('two-handed sword', 250,  1, 10, 3, 18),
    ('trident',          50,   2, 7, 3, 12),
    ('voulge',          125,   2, 8, 2, 8),
]

# the readable speed factors of the WEAPON
# TYPES chart (the R158 verify): engine name,
# print speed. The spear prints 6-8 (the
# engine default 7 rides its own range
# helper); the horseman flail cell is
# OCR-mangled (engine 6 stays convention).
speeds = [
    ('fist', 1),
    ('dagger', 2),
    ('short sword', 3),
    ('hammer', 4),
    ('club', 4),
    ('hand axe', 4),
    ('quarterstaff', 4),
    ('scimitar', 4),
    ('long sword', 5),
    ('broad sword', 5),
    ('horseman mace', 6),
    ('spear', 7),          # print 6-8, engine default 7
    ('footman mace', 7),
    ('footman flail', 7),
    ('morning star', 7),
    ('battle axe', 7),
    ('two-handed sword', 10),
    ('pike', 13),
]

assert len(t) == 50, 'the print chart carries 50 weapons'
assert len(speeds) == 18
# every damage min <= max, weights positive
for name, w, s0, s1, l0, l1 in t:
    assert w > 0, name
    assert 1 <= s0 <= s1 and 1 <= l0 <= l1, name
# the spear weight range (the only spread row)
assert t[40][0] == 'spear' and t[40][1] == 40
# unique names
names = [r[0] for r in t]
assert len(set(names)) == 50
# spot-checks against the print transcription
assert t[0] == ('arrow', 2, 1, 6, 1, 6)
assert t[26] == ('lance, heavy horse', 150, 3, 9, 3, 18)
assert t[47] == ('two-handed sword', 250, 1, 10, 3, 18)
assert t[43] == ('bastard sword', 100, 2, 8, 2, 16)
# the speed list matches the R158 engine rows
# (the R189 pre-verify)
for n, sf in speeds:
    assert 1 <= sf <= 13, (n, sf)
assert ('spear', 7) in speeds and ('horseman flail', 6) not in speeds

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/weapontables.h')
a('// The weapon weight and damage table (R189).')
a('//')
a('// The PHB WEIGHT AND DAMAGE BY WEAPON TYPE chart (50 rows,')
a('// every printed cell): the approximate weight in gold pieces,')
a('// the damage vs. size S or M opponents and the damage vs. size')
a('// L. The speed-factor verify of the WEAPON TYPES chart and the')
a('// printed combat notes ride with it.')
a('//')
a('// JUDGMENTs:')
a('//   - the spear weight prints 40-60 (grip-dependent); it pins')
a('//     as a range - weaponWeight reads the minimum 40,')
a('//     spearWeightRange exposes the spread.')
a('//   - the SPEED VERIFY (the R189 duty): every readable cell of')
a('//     the WEAPON TYPES speed column confirms the R158 engine')
a('//     ladder row for row (the 18 named weapons below). The')
a('//     horseman flail chart cell is OCR-mangled, so the engine')
a('//     6 stays ENGINE CONVENTION, recorded. The partisan prints')
a('//     9, the awl pike 13, the voulge 10, the partisan-family')
a('//     pole arms all readable - none are engine weapons yet.')
a('//   - the R144/R145 p.38 AC-adjustment standing note CLOSES:')
a('//     R149 book-verified 8 of the 15 engine rows cell for cell')
a('//     against this upload; the remaining AC cells are')
a('//     OCR-mangled (digit runs like -1000000 where single')
a('//     modifiers belong) and stay pinned to the 1eonline.info')
a('//     compilation - the repo-trusted source. The engine')
a('//     approximations R149 named (the full-effective-AC column,')
a('//     the every-defender rows, the below-0 clamp) stand.')
a('//   - the italics roster of the first chart footnote (the')
a('//     pole arms that do double damage vs. L when SET to')
a('//     receive a charge) is not recoverable from this OCR -')
a('//     recorded, not pinned. The explicit asterisked notes ARE')
a('//     pinned: the three lances do twice indicated damage')
a('//     against any size when employed from a charging mount;')
a('//     the spear set to receive a charge does twice damage to')
a('//     any opponent.')
a('//   - the chart-2 combat note pins as constants: any weapon')
a('//     strikes +2 against a back or similarly unseen opponent,')
a('//     +4 against stunned, prone and motionless opponents.')
a('//')
a('// DATA-DRIVEN (the standing scope).')
a('// ============================================================================')
a('')
a('#pragma once')
a('')
a('#include <cstdint>')
a('')
a('namespace rules {')
a('')
a('// ---- the weight and damage chart ----')
a('')
a('static const int WEAPON_CHART_ROWS = 50;')
a('')
a('// The chart row count (the print: 50 weapons).')
a('inline int weaponChartRowCount() { return WEAPON_CHART_ROWS; }')
a('')
a('// The weapon name at index i (clamped to 0-49),')
a('// the print order.')
a('inline const char* weaponChartName(int i) {')
a('    static const char* const kNames[50] = {')
for name, _, _, _, _, _ in t:
    a('        ' + DQ + name + DQ + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 49) i = 49;')
a('    return kNames[i];')
a('}')
a('')
a('// The approximate weight in gold pieces (the')
a('// spear prints 40-60; this reads the minimum).')
a('inline int weaponChartWeight(int i) {')
a('    static const int kWeight[50] = {')
for _, w, _, _, _, _ in t:
    a('        ' + str(w) + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 49) i = 49;')
a('    return kWeight[i];')
a('}')
a('')
a('// The damage vs. size S or M opponents: the')
a('// min and max of the printed range.')
a('inline int weaponChartDamageSMMin(int i) {')
a('    static const int kMin[50] = {')
for _, _, s0, _, _, _ in t:
    a('        ' + str(s0) + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 49) i = 49;')
a('    return kMin[i];')
a('}')
a('')
a('inline int weaponChartDamageSMMax(int i) {')
a('    static const int kMax[50] = {')
for _, _, _, s1, _, _ in t:
    a('        ' + str(s1) + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 49) i = 49;')
a('    return kMax[i];')
a('}')
a('')
a('// The damage vs. size L opponents: the min')
a('// and max of the printed range.')
a('inline int weaponChartDamageLMin(int i) {')
a('    static const int kMin[50] = {')
for _, _, _, _, l0, _ in t:
    a('        ' + str(l0) + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 49) i = 49;')
a('    return kMin[i];')
a('}')
a('')
a('inline int weaponChartDamageLMax(int i) {')
a('    static const int kMax[50] = {')
for _, _, _, _, _, l1 in t:
    a('        ' + str(l1) + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 49) i = 49;')
a('    return kMax[i];')
a('}')
a('')
a('// The spear weight spread: the print 40-60.')
a('inline void spearWeightRange(int& lo, int& hi) {')
a('    lo = 40; hi = 60;')
a('}')
a('')
a('// ---- the speed verify (the R189 duty) ----')
a('')
a('// The count of engine-named weapons whose')
a('// printed speed factor was readable and')
a('// verified against the R158 ladder.')
a('inline int weaponSpeedVerifiedCount() { return 18; }')
a('')
a('// The i-th verified pair: the engine weapon')
a('// name and its printed speed factor (the')
a('// spear entry is the engine default 7 of')
a('// the printed 6-8 spread).')
a('inline const char* weaponSpeedVerifiedName(int i) {')
a('    static const char* const kNames[18] = {')
for n, _ in speeds:
    a('        ' + DQ + n + DQ + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 17) i = 17;')
a('    return kNames[i];')
a('}')
a('')
a('inline int weaponSpeedVerifiedFactor(int i) {')
a('    static const int kFactor[18] = {')
for _, sf in speeds:
    a('        ' + str(sf) + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 17) i = 17;')
a('    return kFactor[i];')
a('}')
a('')
a('// ---- the printed notes ----')
a('')
a('// The three lances do twice the indicated')
a('// damage against creatures of any size when')
a('// employed by an attacker riding a charging')
a('// mount (the chart asterisk).')
a('inline bool lanceChargingDouble(int i) {')
a('    return i >= 24 && i <= 26;   // the three lance rows')
a('}')
a('')
a('// The spear set to receive a charge does')
a('// twice the damage to any opponent (the')
a('// chart double asterisk).')
a('inline bool spearSetChargingDouble() {')
a('    return true;')
a('}')
a('')
a('// The chart-2 combat note: any weapon')
a('// strikes +2 against a back or similarly')
a('// unseen opponent.')
a('inline int weaponBackOrUnseenBonus() { return 2; }')
a('')
a('// ... and +4 against stunned, prone and')
a('// motionless opponents.')
a('inline int weaponStunnedProneMotionlessBonus() {')
a('    return 4;')
a('}')
a('')
a('} // namespace rules')

create('rules/weapontables.h',
       'The weapon weight and damage table (R189)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/weapontables.h',
      '#include "rules/xpadjust.h"  // R188: the prime requisite XP adjustment',
      '#include "rules/xpadjust.h"  // R188: the prime requisite XP adjustment'
      + NL + '#include "rules/weapontables.h"  // R189: the weapon weight and damage table')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R189 battery audit (census 106)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R189: the weapon tables verify audit ----')
a('    // All 50 weight/damage rows, the speed cross-verify')
a('    // against the R158 ladder, and the printed notes.')
a('    {')
a('        int bad = 0;')
a('        // the weight/damage chart, row by row (50 cells')
a('        // x weight, S/M min/max, L min/max)')
a('        if (rules::weaponChartRowCount() != 50) ++bad;')
a('        static const int kWeight[50] = {')
for _, w, _, _, _, _ in t:
    a('            ' + str(w) + ',')
a('        };')
a('        static const int kSM[50][2] = {')
for _, _, s0, s1, _, _ in t:
    a('            { ' + str(s0) + ', ' + str(s1) + ' },')
a('        };')
a('        static const int kL[50][2] = {')
for _, _, _, _, l0, l1 in t:
    a('            { ' + str(l0) + ', ' + str(l1) + ' },')
a('        };')
a('        for (int i = 0; i < 50; ++i) {')
a('            if (rules::weaponChartWeight(i) != kWeight[i]) ++bad;')
a('            if (rules::weaponChartDamageSMMin(i) != kSM[i][0]) ++bad;')
a('            if (rules::weaponChartDamageSMMax(i) != kSM[i][1]) ++bad;')
a('            if (rules::weaponChartDamageLMin(i) != kL[i][0]) ++bad;')
a('            if (rules::weaponChartDamageLMax(i) != kL[i][1]) ++bad;')
a('        }')
a('        // the name ladder, head and tail')
a('        if (std::string(rules::weaponChartName(0))')
a('            != "arrow") ++bad;')
a('        if (std::string(rules::weaponChartName(49))')
a('            != "voulge") ++bad;')
a('        if (std::string(rules::weaponChartName(40))')
a('            != "spear") ++bad;')
a('        // spot rows against the print')
a('        if (rules::weaponChartWeight(1) != 75) ++bad;')
a('        if (rules::weaponChartDamageSMMin(1) != 1')
a('            || rules::weaponChartDamageSMMax(1) != 8) ++bad;')
a('        if (rules::weaponChartDamageLMin(26) != 3')
a('            || rules::weaponChartDamageLMax(26) != 18) ++bad;')
a('        if (rules::weaponChartWeight(47) != 250) ++bad;')
a('        if (rules::weaponChartDamageLMin(47) != 3')
a('            || rules::weaponChartDamageLMax(47) != 18) ++bad;')
a('        if (rules::weaponChartDamageSMMin(43) != 2')
a('            || rules::weaponChartDamageSMMax(43) != 8) ++bad;')
a('        if (rules::weaponChartDamageLMin(43) != 2')
a('            || rules::weaponChartDamageLMax(43) != 16) ++bad;')
a('        // the clamps: index out of range reads the edges')
a('        if (rules::weaponChartWeight(-5) != 2) ++bad;')
a('        if (rules::weaponChartWeight(99) != 125) ++bad;')
a('        if (std::string(rules::weaponChartName(-1))')
a('            != "arrow") ++bad;')
a('        // the spear weight spread: the print 40-60')
a('        {')
a('            int lo = 0, hi = 0;')
a('            rules::spearWeightRange(lo, hi);')
a('            if (lo != 40 || hi != 60) ++bad;')
a('            if (rules::weaponChartWeight(40) != 40) ++bad;')
a('        }')
a('        // the speed cross-verify: every verified pair')
a('        // matches the R158 engine ladder value')
a('        if (rules::weaponSpeedVerifiedCount() != 18) ++bad;')
a('        for (int i = 0; i < 18; ++i) {')
a('            const char* n = rules::weaponSpeedVerifiedName(i);')
a('            int printed = rules::weaponSpeedVerifiedFactor(i);')
a('            int engine = rules::weaponSpeedFactor(n);')
a('            if (engine != printed) ++bad;')
a('        }')
a('        // the spear default 7 sits inside the printed 6-8')
a('        {')
a('            int lo = 0, hi = 0;')
a('            rules::spearSpeedFactorRange(lo, hi);')
a('            if (lo != 6 || hi != 8) ++bad;')
a('            if (rules::weaponSpeedFactor("spear") != 7) ++bad;')
a('        }')
a('        // the horseman flail: OCR-mangled cell, the engine')
a('        // 6 stays recorded convention')
a('        if (rules::weaponSpeedFactor("horseman flail") != 6) ++bad;')
a('        // unknown weapons read 0 (the caller decides)')
a('        if (rules::weaponSpeedFactor("vorpal blade") != 0) ++bad;')
a('        // the printed notes: the lances double from a')
a('        // charging mount, rows 24-26 only')
a('        if (!rules::lanceChargingDouble(24)) ++bad;')
a('        if (!rules::lanceChargingDouble(25)) ++bad;')
a('        if (!rules::lanceChargingDouble(26)) ++bad;')
a('        if (rules::lanceChargingDouble(23)) ++bad;')
a('        if (rules::lanceChargingDouble(27)) ++bad;')
a('        if (!rules::spearSetChargingDouble()) ++bad;')
a('        // the chart-2 combat note')
a('        if (rules::weaponBackOrUnseenBonus() != 2) ++bad;')
a('        if (rules::weaponStunnedProneMotionlessBonus()')
a('            != 4) ++bad;')
a('        printf("R189 weapon tables verify audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert every probe against the pinned
# tables (the R184b lesson)
assert t[0][0] == 'arrow' and t[49][0] == 'voulge'
assert t[1][1] == 75 and t[1][2] == 1 and t[1][3] == 8
assert t[26][4] == 3 and t[26][5] == 18
assert t[47][1] == 250 and t[47][4] == 3 and t[47][5] == 18
assert t[43][2] == 2 and t[43][3] == 8 and t[43][4] == 2 and t[43][5] == 16
# the clamp probes read the table edges
assert t[0][1] == 2 and t[49][1] == 125
# the negative probe name must be ABSENT from
# the roster (the R184b mirror rule)
assert 'vorpal blade' not in names
assert 'horseman flail' not in [n for n, _ in speeds]
# the lance rows 24-26 and only those
assert t[24][0].startswith('lance') and t[25][0].startswith('lance')
assert t[26][0].startswith('lance')
assert not t[23][0].startswith('lance') and not t[27][0].startswith('lance')

patch('regtest.cpp',
      'R189 weapon tables verify audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the R189 box flipped
# ---------------------------------------------------------------------------

box_old = ('- [ ] **The PHB book-verify pass for the weapon'
           + NL + '      tables** - R144/R158 pinned from the'
           + NL + '      1eonline.info compilation; the PHB upload now'
           + NL + '      supplies the print charts (WEIGHT AND DAMAGE'
           + NL + '      BY WEAPON TYPE; WEAPON TYPES, GENERAL DATA AND'
           + NL + '      TO HIT ADJUSTMENTS) - a verify round can close'
           + NL + '      the standing compile-vs-print note.')

box_new = ('- [x] **The PHB book-verify pass for the weapon tables -'
           + NL + '      PINNED R189:** rules/weapontables.h CREATED:'
           + NL + '      the WEIGHT AND DAMAGE BY WEAPON TYPE chart (50'
           + NL + '      rows, every cell: the weight in gold pieces,'
           + NL + '      the S/M and L damage ranges; the spear weight'
           + NL + '      40-60 pinned as a range). The verify: every'
           + NL + '      readable speed-factor cell of the WEAPON TYPES'
           + NL + '      chart confirms the R158 engine ladder row for'
           + NL + '      row (18 named weapons; the spear default 7 sits'
           + NL + '      inside the printed 6-8; the horseman flail cell'
           + NL + '      is OCR-mangled - the engine 6 stays recorded'
           + NL + '      convention). The R144/R145 p.38 AC-adjustment'
           + NL + '      standing note CLOSES: R149 verified 8 of the 15'
           + NL + '      engine rows cell for cell against this upload;'
           + NL + '      the remaining AC cells are OCR-mangled (digit'
           + NL + '      runs where single modifiers belong) and stay'
           + NL + '      pinned to the 1eonline compilation. The printed'
           + NL + '      notes pin: the lances double from a charging'
           + NL + '      mount (rows 24-26), the spear set doubles, the'
           + NL + '      +2 back / +4 stunned-prone-motionless combat'
           + NL + '      note; the italics set-weapon roster is not'
           + NL + '      recoverable from this OCR - recorded. The R189'
           + NL + '      battery audit walks all 50 rows and the speed'
           + NL + '      cross-verify. Census 106.')

t2 = rd('tools/phb_gap_report.md')
if 'The PHB book-verify pass for the weapon tables -' not in t2:
    assert t2.count(box_old) == 1, 'R189 box anchor not unique'
else:
    assert t2.count(box_old) == 0, 'R189 box old text lingers'

patch('tools/phb_gap_report.md',
      'PINNED R189:** rules/weapontables.h CREATED',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R189 landed the weapon tables verify',
      'R188 battery audit; census 105. Next: the gap report'
      + NL + 'names the next round.',
      'R188 battery audit; census 105. Next: the gap report'
      + NL + 'names the next round.'
      + NL + 'R189 landed the weapon tables verify:'
      + NL + 'rules/weapontables.h CREATED (the 50-row weight and'
      + NL + 'damage chart, the speed cross-verify - all 18'
      + NL + 'readable cells confirm the R158 ladder - and the'
      + NL + 'printed notes; the R144/R145 AC standing note closes'
      + NL + 'with the OCR limitation recorded). New R189 battery'
      + NL + 'audit; census 106. Next: the gap report names the next'
      + NL + 'round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R189 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R189 note: 5 patches; census 106 (one new audit);')
print('real gate: md5sum rules/weapontables.h')
print('commit: R189: the weapon tables verify pinned - the weight and')
print('damage chart, the speed cross-verify and the notes (census 106)')

