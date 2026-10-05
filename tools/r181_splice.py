#!/usr/bin/env python3
# R181 splice: attacks per melee round.
#
# rules/attacksround.h is CREATED: the fighters,
# paladins and rangers attacks-per-melee-round table
# (with any thrusting or striking weapon), the
# under-one-hit-die note (one attack per fighter
# experience level against creatures under one d8),
# the monk unarmed ladder (Monks Table II: AC class,
# movement, attacks per melee, open-hand damage for
# all 17 levels), and the monk weapon-damage bonus
# (half a hit point per level, the doubled form).
#
# rules/turn.cpp: meleeAttacksPerRound repinned from
# the unsourced level-8+ original note to the print -
# the 3/2 band opens at 7th level for the fighter
# base class; the engine round model keeps its two
# swing slots (initiative and +5), so the function
# returns the routine count of the HEAVY round of
# the printed cycle. rules/turn.h comment repinned to
# match.
#
# regtest.cpp: the include lands WITH the audit (the
# R179 lesson); the R181 battery audit walks every
# fighter-group band, the under-one-hit-die note,
# every monk ladder cell, the weapon-bonus ladder and
# the turn.cpp repin. Census 98.
#
# Patches: 9.

import os

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
# Patch 1: rules/attacksround.h CREATED
# ---------------------------------------------------------------------------

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/attacksround.h')
a('// Attacks per melee round (R181).')
a('//')
a('// The fighters, paladins and rangers attacks-per-melee-round')
a('// table (PHB, the class tables section): 1/1 round in the low')
a('// band, 3/2 rounds in the middle band, 2/1 round in the high band')
a('// - with any thrusting or striking weapon. The table note: this')
a('// excludes melee with monsters of less than one hit die (d8) and')
a('// non-exceptional 0-level humans and semi-humans; against all')
a('// such creatures a fighter attacks once for each experience')
a('// level per round.')
a('//')
a('// The monk unarmed ladder (PHB Monks Table II): the effective')
a('// armor class, the movement, the attacks per melee round and the')
a('// open-hand damage for all 17 printed levels. The monk also adds')
a('// half a hit point per level of weapon damage on a successful')
a('// weapon attack (the doubled form below avoids halves), attacks')
a('// on the thief table, and the monk to-hit is never modified by')
a('// strength bonuses.')
a('//')
a('// JUDGMENTs:')
a('//   - the rate convention: attacks per rounds, so 3/2 rounds is')
a('//     3 attacks per 2 rounds, the extra attack at the end of the')
a('//     round sequence (the printed slash convention; 5/4 likewise')
a('//     5 attacks per 4 rounds).')
a('//   - the engine round model carries two swing slots (initiative')
a('//     and initiative+5, rules/turn.cpp); meleeAttacksPerRound')
a('//     returns the routine count of the HEAVY round of the printed')
a('//     cycle: 1 below the 3/2 band, 2 in the 3/2 and 2/1 bands.')
a('//     The full printed rates live HERE.')
a('//   - the monk stun, kill and quivering-palm rules are specials')
a('//     (the R187+ rounds), not this table.')
a('//')
a('// DATA-DRIVEN (the standing scope): a future class appends its')
a('// band edges or its ladder rows.')
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
a('// The printed rate: attacks per rounds (1/1, 3/2, 2/1,')
a('// the monk 5/4 and 5/2 likewise).')
a('struct AtkRate {')
a('    int attacks;')
a('    int rounds;')
a('};')
a('')
a('// ---- the fighter-group table ----')
a('// kind 0 = fighter, 1 = paladin, 2 = ranger.')
a('// Band edges: fighter and paladin 1-6 / 7-12 / 13 and up;')
a('// ranger 1-7 / 8-14 / 15 and up (the print).')
a('inline AtkRate fighterGroupAttacks(int kind, int level) {')
a('    static const int kMid[3]  = { 7, 7, 8 };')
a('    static const int kHigh[3] = { 13, 13, 15 };')
a('    if (kind < 0) kind = 0;')
a('    if (kind > 2) kind = 2;')
a('    if (level < 1) level = 1;')
a('    if (level < kMid[kind])')
a('        return { 1, 1 };')
a('    if (level < kHigh[kind])')
a('        return { 3, 2 };')
a('    return { 2, 1 };')
a('}')
a('')
a('// The table note: against creatures of less than one hit die')
a('// (d8) and non-exceptional 0-level humans and semi-humans, one')
a('// attack per fighter experience level per round.')
a('inline int fighterAttacksVsSubOneHitDice(int level) {')
a('    if (level < 1) return 1;')
a('    return level;')
a('}')
a('')
a('// ---- the monk unarmed ladder (Monks Table II) ----')
a('')
a('struct MonkLadderRow {')
a('    int level;      // 1-17')
a('    int acClass;    // the effective armor class (open hand)')
a('    int moveInches; // the printed movement')
a('    int atkAttacks;// attacks ...')
a('    int atkRounds; // ... per this many rounds')
a('    int dmgLo;     // open-hand damage low')
a('    int dmgHi;     // open-hand damage high')
a('};')
a('')
a('static const MonkLadderRow kMonkLadder[17] = {')
a('    {  1, 10, 15, 1, 1, 1,  3 },')
a('    {  2,  9, 16, 1, 1, 1,  4 },')
a('    {  3,  8, 17, 1, 1, 1,  6 },')
a('    {  4,  7, 18, 5, 4, 1,  6 },')
a('    {  5,  7, 19, 5, 4, 2,  7 },')
a('    {  6,  6, 20, 3, 2, 2,  8 },')
a('    {  7,  5, 21, 3, 2, 3,  9 },')
a('    {  8,  4, 22, 3, 2, 2, 12 },')
a('    {  9,  3, 23, 2, 1, 3, 12 },')
a('    { 10,  3, 24, 2, 1, 3, 13 },')
a('    { 11,  2, 25, 5, 2, 4, 13 },')
a('    { 12,  1, 26, 5, 2, 4, 16 },')
a('    { 13,  0, 27, 5, 2, 5, 17 },')
a('    { 14, -1, 28, 3, 1, 5, 20 },')
a('    { 15, -1, 29, 3, 1, 6, 24 },')
a('    { 16, -2, 30, 4, 1, 5, 30 },')
a('    { 17, -3, 32, 4, 1, 8, 32 }')
a('};')
a('')
a('inline int monkLadderRowCount() { return 17; }')
a('')
a('inline const MonkLadderRow& monkLadderRow(int level) {')
a('    if (level < 1) level = 1;')
a('    if (level > 17) level = 17;')
a('    return kMonkLadder[level - 1];')
a('}')
a('')
a('// The open-hand attacks per melee round (the printed slash).')
a('inline AtkRate monkOpenHandAttacks(int level) {')
a('    const MonkLadderRow& r = monkLadderRow(level);')
a('    return { r.atkAttacks, r.atkRounds };')
a('}')
a('')
a('// The monk weapon damage: half a hit point per level of')
a('// experience added to the weapon damage on a hit (1st level')
a('// +1/2, 2nd +1, ... Grand Master of Flowers +8 1/2). Doubled')
a('// form: the bonus is monkWeaponDamageBonus2x / 2.')
a('inline int monkWeaponDamageBonus2x(int level) {')
a('    if (level < 1) level = 1;')
a('    if (level > 17) level = 17;')
a('    return level;')
a('}')
a('')
a('} // namespace rules')

create('rules/attacksround.h',
       'Attacks per melee round (R181)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/attacksround.h',
      '#include "rules/subclassgates.h"  // R180: the qualification and race gates',
      '#include "rules/subclassgates.h"  // R180: the qualification and race gates'
      + NL + '#include "rules/attacksround.h"  // R181: attacks per melee round')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R181 battery audit (census 98)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R181: the attacks per melee round audit ----')
a('    // The fighter-group bands, the under-one-hit-die')
a('    // note, every monk ladder cell, the monk weapon')
a('    // damage ladder, and the turn.cpp repin.')
a('    {')
a('        int bad = 0;')
a('        // the fighter-group bands: level probes around every')
a('        // printed edge (fighter/paladin 6,7,12,13; ranger')
a('        // 7,8,14,15)')
a('        const int kMid[3]  = { 7, 7, 8 };')
a('        const int kHigh[3] = { 13, 13, 15 };')
a('        for (int k = 0; k < 3; ++k) {')
a('            for (int lv = 1; lv <= 20; ++lv) {')
a('                rules::AtkRate r =')
a('                    rules::fighterGroupAttacks(k, lv);')
a('                int att = 1, rds = 1;')
a('                if (lv >= kHigh[k]) { att = 2; rds = 1; }')
a('                else if (lv >= kMid[k]) { att = 3; rds = 2; }')
a('                if (r.attacks != att || r.rounds != rds) ++bad;')
a('            }')
a('        }')
a('        // the under-one-hit-die note: one attack per')
a('        // fighter experience level')
a('        if (rules::fighterAttacksVsSubOneHitDice(1) != 1) ++bad;')
a('        if (rules::fighterAttacksVsSubOneHitDice(7) != 7) ++bad;')
a('        if (rules::fighterAttacksVsSubOneHitDice(13) != 13) ++bad;')
a('        if (rules::fighterAttacksVsSubOneHitDice(0) != 1) ++bad;')
a('        // every monk ladder cell (Monks Table II)')
a('        const int kMnkAc[17] = {')
a('            10, 9, 8, 7, 7, 6, 5, 4, 3, 3, 2, 1, 0,')
a('            -1, -1, -2, -3')
a('        };')
a('        const int kMnkMove[17] = {')
a('            15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,')
a('            26, 27, 28, 29, 30, 32')
a('        };')
a('        const int kMnkAtt[17] = {')
a('            1, 1, 1, 5, 5, 3, 3, 3, 2, 2, 5, 5, 5,')
a('            3, 3, 4, 4')
a('        };')
a('        const int kMnkRds[17] = {')
a('            1, 1, 1, 4, 4, 2, 2, 2, 1, 1, 2, 2, 2,')
a('            1, 1, 1, 1')
a('        };')
a('        const int kMnkLo[17] = {')
a('            1, 1, 1, 1, 2, 2, 3, 2, 3, 3, 4, 4, 5,')
a('            5, 6, 5, 8')
a('        };')
a('        const int kMnkHi[17] = {')
a('            3, 4, 6, 6, 7, 8, 9, 12, 12, 13, 13, 16,')
a('            17, 20, 24, 30, 32')
a('        };')
a('        if (rules::monkLadderRowCount() != 17) ++bad;')
a('        for (int lv = 1; lv <= 17; ++lv) {')
a('            const rules::MonkLadderRow& r =')
a('                rules::monkLadderRow(lv);')
a('            if (r.level != lv) ++bad;')
a('            if (r.acClass != kMnkAc[lv-1]) ++bad;')
a('            if (r.moveInches != kMnkMove[lv-1]) ++bad;')
a('            if (r.atkAttacks != kMnkAtt[lv-1]) ++bad;')
a('            if (r.atkRounds != kMnkRds[lv-1]) ++bad;')
a('            if (r.dmgLo != kMnkLo[lv-1]) ++bad;')
a('            if (r.dmgHi != kMnkHi[lv-1]) ++bad;')
a('        }')
a('        // clamps: level 0 and 99 read level 1 and 17')
a('        if (rules::monkLadderRow(0).level != 1) ++bad;')
a('        if (rules::monkLadderRow(99).level != 17) ++bad;')
a('        if (rules::monkOpenHandAttacks(4).attacks != 5')
a('            || rules::monkOpenHandAttacks(4).rounds != 4) ++bad;')
a('        // the monk weapon damage ladder (doubled form:')
a('        // +1/2 per level, Grand Master +8 1/2)')
a('        if (rules::monkWeaponDamageBonus2x(1) != 1) ++bad;')
a('        if (rules::monkWeaponDamageBonus2x(2) != 2) ++bad;')
a('        if (rules::monkWeaponDamageBonus2x(17) != 17) ++bad;')
a('        if (rules::monkWeaponDamageBonus2x(99) != 17) ++bad;')
a('        // the turn.cpp repin: the base-class function uses the')
a('        // fighter bands (the heavy round of the printed cycle)')
a('        if (rules::meleeAttacksPerRound(0, 6) != 1) ++bad;')
a('        if (rules::meleeAttacksPerRound(0, 7) != 2) ++bad;')
a('        if (rules::meleeAttacksPerRound(0, 12) != 2) ++bad;')
a('        if (rules::meleeAttacksPerRound(0, 13) != 2) ++bad;')
a('        if (rules::meleeAttacksPerRound(0, 20) != 2) ++bad;')
a('        if (rules::meleeAttacksPerRound(1, 20) != 1) ++bad;')
a('        if (rules::meleeAttacksPerRound(2, 20) != 1) ++bad;')
a('        if (rules::meleeAttacksPerRound(3, 20) != 1) ++bad;')
a('        printf("R181 attacks per melee round audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

patch('regtest.cpp',
      'R181 attacks per melee round audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: rules/turn.cpp - the include
# ---------------------------------------------------------------------------

patch('rules/turn.cpp',
      'R181: the fighter-group print consults rules/attacksround.h',
      '#include "turn.h"',
      '#include "turn.h"'
      + NL + '#include "attacksround.h"  // R181: the fighter-group print consults rules/attacksround.h')

# ---------------------------------------------------------------------------
# Patch 5: rules/turn.cpp - the meleeAttacksPerRound repin
# ---------------------------------------------------------------------------

patch('rules/turn.cpp',
      'R181 repin: the printed 3/2 band opens at 7th level',
      'int meleeAttacksPerRound(int classIndex, int level) {'
      + NL + '    // fighters L8+ (and monsters with noted routines) fight twice per'
      + NL + '    // round; everyone else once (original notes; the PHB/DMG exact'
      + NL + '    // level for weapon specialization double-attacks gets verified'
      + NL + '    // in the book pass)'
      + NL + '    if (classIndex == 0 && level >= 8) return 2;'
      + NL + '    return 1;'
      + NL + '}',
      'int meleeAttacksPerRound(int classIndex, int level) {'
      + NL + '    // R181 repin: the printed 3/2 band opens at 7th level'
      + NL + '    // (the fighters, paladins and rangers attacks-per-melee-'
      + NL + '    // round table). The engine round model carries two swing'
      + NL + '    // slots (initiative and initiative+5), so this returns the'
      + NL + '    // routine count of the HEAVY round of the printed cycle:'
      + NL + '    // 1 below the 3/2 band, 2 in the 3/2 and 2/1 bands. The'
      + NL + '    // full printed rates (and the ranger band edges, which'
      + NL + '    // need the subclass id this base-class function does not'
      + NL + '    // carry) live in rules/attacksround.h.'
      + NL + '    if (classIndex == 0) {'
      + NL + '        rules::AtkRate r = rules::fighterGroupAttacks(0, level);'
      + NL + '        return (r.attacks >= 2) ? 2 : 1;'
      + NL + '    }'
      + NL + '    return 1;'
      + NL + '}')

# ---------------------------------------------------------------------------
# Patch 6: rules/turn.h - the comment repin
# ---------------------------------------------------------------------------

patch('rules/turn.h',
      'R181: the 3/2 band opens at 7th',
      '// Multiple attacks (DMG p.39, PHB fighter notes): fighters (and'
      + NL + '// monsters with multiple attack routines) act on both initiative and'
      + NL + '// initiative+5 segments by convention. High-level fighters (level 8+'
      + NL + '// per original notes) gain a second melee routine.',
      '// Multiple attacks (DMG p.39, PHB fighter notes): fighters (and'
      + NL + '// monsters with multiple attack routines) act on both initiative and'
      + NL + '// initiative+5 segments by convention. Fighters gain the second'
      + NL + '// routine in the printed 3/2 band (R181: the 3/2 band opens at 7th'
      + NL + '// level for the fighter base class; the printed rates live in'
      + NL + '// rules/attacksround.h).')

# ---------------------------------------------------------------------------
# Patch 7: tools/phb_gap_report.md - the R181 box flipped
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'R181 the attacks per melee round - PINNED',
      '- R181 attacks per melee round - the'
      + NL + '      fighter-group table (also closes the open'
      + NL + '      item above); the monk unarmed ladder and the'
      + NL + '      under-one-hit-die note.',
      '- [x] R181 the attacks per melee round - PINNED:'
      + NL + '      rules/attacksround.h CREATED: the fighters,'
      + NL + '      paladins and rangers table (1/1, 3/2 at the'
      + NL + '      mid band, 2/1 at the high band; fighter and'
      + NL + '      paladin 7/13 edges, ranger 8/15 edges, any'
      + NL + '      thrusting or striking weapon), the table note'
      + NL + '      (one attack per fighter experience level per'
      + NL + '      round against creatures under one d8 and'
      + NL + '      non-exceptional 0-level humans and'
      + NL + '      semi-humans), the monk unarmed ladder cell by'
      + NL + '      cell (Monks Table II: AC class 10 to -3,'
      + NL + '      movement 15 to 32, the attacks slash column'
      + NL + '      1/1 to 4/1, open-hand damage 1-3 to 8-32),'
      + NL + '      and the monk weapon-damage bonus (half a hit'
      + NL + '      point per level, doubled form; the monk'
      + NL + '      attacks on the thief table, strength never'
      + NL + '      modifies the monk to-hit - recorded for the'
      + NL + '      specials rounds). rules/turn.cpp repinned:'
      + NL + '      meleeAttacksPerRound was fighters level 8+'
      + NL + '      from unsourced original notes - now the'
      + NL + '      heavy round of the printed cycle (the 3/2'
      + NL + '      band opens at 7th for the fighter base'
      + NL + '      class; the actor layer carries base classes).'
      + NL + '      The R181 battery audit walks every band, every'
      + NL + '      monk cell and the repin. Census 98.')

# ---------------------------------------------------------------------------
# Patch 8: tools/phb_gap_report.md - the open item flipped
# ---------------------------------------------------------------------------

patch('tools/phb_gap_report.md',
      'PINNED R181: the engine',
      '- [ ] **Fighter attacks per melee round (the class'
      + NL + '      tables section)** - 1 per round at levels 1-6,'
      + NL + '      3 per 2 rounds at 7-12, 2 per round at 13 and'
      + NL + '      up (one per level against creatures under one'
      + NL + '      hit die); the engine convention is unverified.',
      '- [x] **Fighter attacks per melee round (the class'
      + NL + '      tables section)** - PINNED R181: the engine'
      + NL + '      convention verified and repinned - the printed'
      + NL + '      bands now live in rules/attacksround.h and'
      + NL + '      rules/turn.cpp (meleeAttacksPerRound was the'
      + NL + '      unsourced level-8+ original note).')

# ---------------------------------------------------------------------------
# Patch 9: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R181 landed the attacks per melee round',
      'Next: R181 attacks per melee round.',
      'Next: R181 attacks per melee round.'
      + NL + 'R181 landed the attacks per melee round:'
      + NL + 'rules/attacksround.h CREATED (the fighter-group'
      + NL + 'bands with the printed level edges, the'
      + NL + 'under-one-hit-die note, the monk unarmed ladder'
      + NL + 'cell by cell, the monk weapon-damage bonus).'
      + NL + 'rules/turn.cpp meleeAttacksPerRound repinned - the'
      + NL + 'level-8+ original note replaced by the print (the'
      + NL + '3/2 band opens at 7th; heavy-round convention, the'
      + NL + 'full rates in the header). New R181 battery audit;'
      + NL + 'census 98. Next: R182 the druid spell layer.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 9, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R181 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R181 note: 9 patches; census 98 (one new audit);')
print('real gate: md5sum rules/attacksround.h')
print('commit: R181: the attacks per melee round pinned -')
print('the fighter-group bands, the monk unarmed ladder (census 98)')

