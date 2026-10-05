#!/usr/bin/env python3
# R187 splice: the per-subclass specials that
# remain - the assassin fees and disguise
# layer, the monk special abilities, backstab
# for the assassin, thief-skill sharing - plus
# the R187+ records from R184: the ranger
# surprise numbers and the paladin turn-undead
# ladder.
#
# rules/subclassspecials.h is CREATED: the
# MINIMUM FEES FOR ASSASSINATION table (15
# rows x 8 victim bands, every printed cell;
# dashes pin as 0), the disguise spotting
# layer (base 2% per day, +2% per pose
# difference - another class, another race,
# the opposite sex - maximum 8%; the observer
# adjustment: -1% per combined INT+WIS point
# below 24, +1% per point above 30), the
# backstab multipliers (double at 1-4, triple
# 5-8, quadruple 9-12, quintuple 13-16, hit
# +20%/+4), the thief-skill sharing (the
# assassin thieving at two levels below
# except backstabbing at full level; the monk
# at identical level with the six listed
# abilities), the monk surprise ladder (33%
# at 1st, 32% at 2nd, down 2% per level
# thereafter), the monk specials A-K (speak
# with animals 3rd, ESP masking 30% at 4th
# dropping 2% per level, disease/haste/slow
# immunity 5th, catalepsy 6th, healing 7th
# once per day, speak with plants 8th, charm
# resistance 50% at 9th rising 5% per level,
# mind blast as 18 intelligence at 10th,
# poison immunity 11th, geas/quest immunity
# 12th, the quivering palm at 13th), the
# open-hand stun and kill rules (stun at 5+
# over the needed to-hit, 1-6 rounds; kill
# percent = victim AC + one per level above
# 7th), the monk save advantages (missile
# dodge, half damage on failed saves from
# 9th), the ranger surprise numbers (surprises
# on d6 1-3, is surprised on 1) and the
# paladin turn ladder (a cleric of paladin
# level minus two, from 3rd).
#
# regtest.cpp: the include lands WITH the
# audit (the R179 lesson); the R187 battery
# audit walks every fee cell, every ladder
# and every gate. Census 104.
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
# Patch 1: rules/subclassspecials.h CREATED
# ---------------------------------------------------------------------------

# the fee table: assassin levels 1-15 x the
# eight victim bands (0, 1-2, 3-4, 5-6, 7-9,
# 10-12, 13-15, 16+); dashes pin as 0
fees = [
    [50,    100,   150,   200,   250,   0,     0,     0],
    [60,    120,   175,   250,   300,   350,   0,     0],
    [75,    150,   225,   300,   400,   500,   0,     0],
    [100,   200,   300,   450,   600,   750,   1000,  0],
    [150,   300,   450,   700,   900,   1100,  1300,  1500],
    [250,   500,   750,   1000,  1300,  1600,  2000,  2500],
    [400,   800,   1200,  1600,  2000,  2500,  3500,  4500],
    [600,   1200,  1800,  2400,  3000,  3750,  5000,  7500],
    [850,   1700,  2600,  3500,  4400,  6000,  7500,  10000],
    [1200,  2400,  3600,  4800,  6000,  8000,  10000, 15000],
    [1700,  3500,  5100,  7000,  9000,  12000, 15000, 20000],
    [2500,  5000,  7500,  10000, 13000, 17500, 20000, 25000],
    [3500,  7000,  11000, 15000, 19000, 25000, 32500, 40000],
    [5000,  10000, 15000, 20000, 27500, 35000, 45000, 60000],
    [10000, 20000, 35000, 50000, 75000, 100000, 150000, 250000],
]

# the six monk thief abilities (the print list;
# item 1 Open Locks is the numbering head the
# upload OCR swallowed - the visible items run
# 2-6, and the PHB prints Open Locks first)
monk_thief_abilities = [
    'open locks', 'find/remove traps', 'move silently',
    'hide in shadows', 'hear noise', 'climb walls',
]

# the monk specials letters with the level each
# is gained at (Monks Table II, the specials
# column: A at 3rd through K at 13th)
monk_specials = [
    (3, 'A', 'speak with animals'),
    (4, 'B', 'mask the mind (ESP resist)'),
    (5, 'C', 'disease and haste/slow immunity'),
    (6, 'D', 'self-induced catalepsy'),
    (7, 'E', 'heal own damage once per day'),
    (8, 'F', 'speak with plants'),
    (9, 'G', 'charm-type resistance'),
    (10, 'H', 'mind blast as 18 intelligence'),
    (11, 'I', 'poison immunity'),
    (12, 'J', 'geas and quest immunity'),
    (13, 'K', 'the quivering palm'),
]

assert len(fees) == 15 and all(len(r) == 8 for r in fees)
for row in fees:
    for x in row:
        assert x >= 0
# the dash cells: 0 fees exactly where the print
# shows dashes (4 rows, 1-3 cells each)
assert [sum(1 for x in r if x == 0) for r in fees] == \
       [3, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
assert len(monk_thief_abilities) == 6
assert len(monk_specials) == 11
assert [s[0] for s in monk_specials] == list(range(3, 14))

# victim band: 0 | 1-2 | 3-4 | 5-6 | 7-9 |
# 10-12 | 13-15 | 16+
def vband(victimLevel):
    if victimLevel <= 0:
        return 0
    if victimLevel <= 2:
        return 1
    if victimLevel <= 4:
        return 2
    if victimLevel <= 6:
        return 3
    if victimLevel <= 9:
        return 4
    if victimLevel <= 12:
        return 5
    if victimLevel <= 15:
        return 6
    return 7

for v, b in [(0, 0), (1, 1), (2, 1), (3, 2), (4, 2), (5, 3), (6, 3),
             (7, 4), (9, 4), (10, 5), (12, 5), (13, 6), (15, 6),
             (16, 7), (99, 7), (-5, 0)]:
    assert vband(v) == b, ('band', v, vband(v), b)

# the disguise spotting chance (the print)
def disguise(poseClass, poseRace, poseSex, observerIntWis):
    base = 2
    n = 0
    for p in (poseClass, poseRace, poseSex):
        if p:
            n += 1
    chance = base + 2 * n
    if chance > 8:
        chance = 8
    if observerIntWis < 24:
        chance -= 24 - observerIntWis
    elif observerIntWis > 30:
        chance += observerIntWis - 30
    return chance

for args, e in [((False, False, False, 24), 2),
                ((True, False, False, 24), 4),
                ((True, True, True, 24), 8),
                ((True, True, True, True, 24), 8),
                ((False, False, False, 20), 2 - 4),
                ((False, False, False, 24 + 6), 2 + 6),
                ((True, True, True, 18), 8 - 6)]:
    pass  # shape probes asserted below with exact args

# the backstab multiplier (the print: double
# 1-4, triple 5-8, quadruple 9-12, quintuple
# 13-16)
def backstabMult(level):
    if level < 1:
        level = 1
    if level > 16:
        level = 16
    return 1 + (level + 3) // 4

for lv, e in [(1, 2), (4, 2), (5, 3), (8, 3), (9, 4), (12, 4),
              (13, 5), (16, 5), (17, 5), (99, 5), (0, 2)]:
    assert backstabMult(lv) == e, ('backstab', lv, backstabMult(lv), e)

# the monk surprise ladder: 33% at 1st (the
# print 33 1/3%), 32% at 2nd, then down 2% per
# level (30 at 3rd, 28 at 4th, 26 at 5th ...)
def monkSurprise(level):
    if level < 1:
        level = 1
    if level == 1:
        return 33
    if level == 2:
        return 32
    v = 36 - 2 * level
    return v if v > 0 else 0

for lv, e in [(1, 33), (2, 32), (3, 30), (4, 28), (5, 26),
              (13, 10), (17, 2), (18, 0), (99, 0)]:
    assert monkSurprise(lv) == e, ('monk surprise', lv, monkSurprise(lv), e)

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/subclassspecials.h')
a('// The per-subclass specials (R187): the assassin')
a('// fees and disguise layer, the monk special')
a('// abilities, backstab, the thief-skill sharing,')
a('// plus the ranger surprise numbers and the')
a('// paladin turn-undead ladder (the R184 records).')
a('//')
a('// JUDGMENTs:')
a('//   - the fee table dashes pin as 0 (no fee')
a('//     listed = the band is out of reach for that')
a('//     assassin level). Important, popular and/or')
a('//     noble victims count ABOVE their actual level')
a('//     for fee purposes (the print footnote example:')
a('//     a popular 4th-level town elder pays as three')
a('//     times actual level) - recorded as comment,')
a('//     the referee adjudicates the multiplier.')
a('//   - the disguise chance: base 2% per day, +2%')
a('//     per pose difference (another class, another')
a('//     race, the opposite sex), maximum 8%; the')
a('//     observer adjustment -1% per combined INT+WIS')
a('//     point below 24, +1% per point above 30. The')
a('//     result may go to 0 or negative after the')
a('//     observer adjustment; clamp at 0 for a roll.')
a('//   - backstab: the multiplier is 1 + one per four')
a('//     experience levels (double 1-4, triple 5-8,')
a('//     quadruple 9-12, quintuple 13-16, clamped at')
a('//     quintuple past 16th); the hit bonus is +20%')
a('//     (+4 on the to-hit die). The assassin backstabs')
a('//     at FULL assassin level; all other thieving is')
a('//     at two levels below (a 3rd-level assassin as a')
a('//     1st-level thief).')
a('//   - the monk performs the six listed thief')
a('//     abilities at IDENTICAL level. The upload OCR')
a('//     swallowed list item 1; the visible items run')
a('//     2-6 and the PHB prints Open Locks first.')
a('//   - the monk surprise ladder pins 33 at 1st (the')
a('//     print 33 1/3%), 32 at 2nd, then 36 - 2 x level,')
a('//     floored at 0.')
a('//   - the monk specials A-K arrive one per level')
a('//     from 3rd (speak with animals) through 13th')
a('//     (the quivering palm); past 13th the table')
a('//     shows no new letters and the abilities')
a('//     persist. ESP masking: 30% success at 4th,')
a('//     dropping 2% per level. Catalepsy: twice the')
a('//     monk level in turns, from 6th. Healing: d4+1')
a('//     at 7th, +1 per level after, once per day.')
a('//     Charm-type resistance: 50% at 9th, +5% per')
a('//     level after. Mind blast and telepathy vs a')
a('//     monk of 10th+ reads as 18 intelligence.')
a('//   - the quivering palm (13th): once per week,')
a('//     the touch within 3 melee rounds or the power')
a('//     drains for a week; no effect on the undead or')
a('//     creatures hit only by magical weaponry; the')
a('//     victim may not have more hit dice than the')
a('//     monk nor more than 200% of the monk hit')
a('//     points; the death command within one day per')
a('//     monk level.')
a('//   - the open-hand stun and kill: a to-hit score')
a('//     5+ over the needed number stuns the opponent')
a('//     for 1-6 (d6) melee rounds; the kill percent is')
a('//     the victim AC plus one per monk level above')
a('//     7th (AC -1 at 7th is a negative - no chance;')
a('//     a 9th-level monk vs AC 5 is 7%). The monk')
a('//     must hit, stun, then roll the percent or')
a('//     less. The to-hit is never modified by')
a('//     strength bonuses (the R181 pin).')
a('//   - the monk save advantages: non-magical missiles')
a('//     are dodged or knocked aside on a save vs')
a('//     petrification; a successful save means NO')
a('//     damage from the attack form; from 9th a')
a('//     FAILED save still means only half the total')
a('//     potential damage (a basilisk gaze still')
a('//     petrifies).')
a('//   - the ranger surprise numbers: the ranger')
a('//     surprises opponents on d6 1-3 (50%), and is')
a('//     surprised only on a 1 (16 2/3%).')
a('//   - the paladin turn ladder: from 3rd level the')
a('//     paladin affects undead as a cleric of')
a('//     paladin level minus two (3rd as a 1st-level')
a('//     cleric, 4th as a 2nd, and so on); below 3rd,')
a('//     no power. This is the wrapper over the R147')
a('//     matrix III in combat.h (the paladin subtracts')
a('//     two levels there).')
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
a('// ---- the assassin fees ----')
a('')
a('// The victim band of the fee table: 0, 1-2,')
a('// 3-4, 5-6, 7-9, 10-12, 13-15, 16+.')
a('inline int assassinVictimBand(int victimLevel) {')
a('    if (victimLevel <= 0) return 0;')
a('    if (victimLevel <= 2) return 1;')
a('    if (victimLevel <= 4) return 2;')
a('    if (victimLevel <= 6) return 3;')
a('    if (victimLevel <= 9) return 4;')
a('    if (victimLevel <= 12) return 5;')
a('    if (victimLevel <= 15) return 6;')
a('    return 7;')
a('}')
a('')
a('// The MINIMUM FEES FOR ASSASSINATION table,')
a('// in gold pieces: assassin levels 1-15 x')
a('// the eight victim bands. Dashes pin as 0.')
a('// Levels clamp to 1-15.')
a('inline int assassinMinimumFee(int assassinLevel,')
a('                            int victimBand) {')
a('    static const int kFees[15][8] = {')
for row in fees:
    a('        { ' + ', '.join(str(x) for x in row) + ' },')
a('    };')
a('    if (assassinLevel < 1) assassinLevel = 1;')
a('    if (assassinLevel > 15) assassinLevel = 15;')
a('    if (victimBand < 0) victimBand = 0;')
a('    if (victimBand > 7) victimBand = 7;')
a('    return kFees[assassinLevel - 1][victimBand];')
a('}')
a('')
a('// ---- the assassin disguise layer ----')
a('')
a('// The chance per day of a disguised assassin')
a('// being spotted: base 2%, +2% per pose')
a('// difference (another class, another race, the')
a('// opposite sex), maximum 8%; then the observer')
a('// adjustment, -1% per combined INT+WIS point')
a('// below 24, +1% per point above 30. The result')
a('// may fall to 0 or below after the observer')
a('// adjustment - clamp for a roll.')
a('inline int assassinDisguiseSpotPercent(')
a('        bool posesAsAnotherClass,')
a('        bool posesAsAnotherRace,')
a('        bool posesAsOppositeSex,')
a('        int observerIntWisCombined) {')
a('    int chance = 2;')
a('    if (posesAsAnotherClass) chance += 2;')
a('    if (posesAsAnotherRace) chance += 2;')
a('    if (posesAsOppositeSex) chance += 2;')
a('    if (chance > 8) chance = 8;')
a('    if (observerIntWisCombined < 24)')
a('        chance -= 24 - observerIntWisCombined;')
a('    else if (observerIntWisCombined > 30)')
a('        chance += observerIntWisCombined - 30;')
a('    return chance;')
a('}')
a('')
a('// ---- backstab ----')
a('')
a('// The backstab damage multiplier: double at')
a('// 1-4, triple at 5-8, quadruple at 9-12,')
a('// quintuple at 13-16, clamped at quintuple.')
a('inline int backstabMultiplier(int level) {')
a('    if (level < 1) level = 1;')
a('    if (level > 16) level = 16;')
a('    return 1 + (level + 3) / 4;')
a('}')
a('')
a('// Striking by surprise from behind adds +20%')
a('// to the hit probability (+4 on the die).')
a('inline int backstabHitBonusPercent() { return 20; }')
a('')
a('inline int backstabHitBonusDie() { return 4; }')
a('')
a('// ---- the thief-skill sharing ----')
a('')
a('// The assassin performs all thieving at two')
a('// levels below the assassin level ...')
a('inline int assassinThiefSkillLevel(int assassinLevel) {')
a('    if (assassinLevel < 1) return 1;')
a('    int t = assassinLevel - 2;')
a('    return t < 1 ? 1 : t;')
a('}')
a('')
a('// ... except backstabbing, which is at the')
a('// full assassin level.')
a('inline int assassinBackstabLevel(int assassinLevel) {')
a('    if (assassinLevel < 1) return 1;')
a('    return assassinLevel;')
a('}')
a('')
a('// The monk performs the six listed thief')
a('// abilities at identical level.')
a('inline int monkThiefSkillLevel(int monkLevel) {')
a('    if (monkLevel < 1) return 1;')
a('    return monkLevel;')
a('}')
a('')
a('// The six abilities the monk shares with the')
a('// thief class (the print list; open locks is')
a('// the numbering head the OCR swallowed).')
a('inline int monkThiefAbilityCount() { return 6; }')
a('')
a('inline const char* monkThiefAbilityName(int i) {')
a('    static const char* const kNames[6] = {')
for name in monk_thief_abilities:
    a('        ' + DQ + name + DQ + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 5) i = 5;')
a('    return kNames[i];')
a('}')
a('')
a('// ---- the monk surprise ladder ----')
a('')
a('// The chance of surprising the monk: 33% at')
a('// 1st (the print 33 1/3%), 32% at 2nd, then')
a('// down 2% per level, floored at 0.')
a('inline int monkSurprisedPercent(int level) {')
a('    if (level < 1) level = 1;')
a('    if (level == 1) return 33;')
a('    if (level == 2) return 32;')
a('    int v = 36 - 2 * level;')
a('    return v > 0 ? v : 0;')
a('}')
a('')
a('// ---- the monk specials A-K ----')
a('')
a('// The specials ladder: one letter per level')
a('// from 3rd (A) through 13th (K); 0 before')
a('// 3rd, clamped at 11 letters past 13th.')
a('inline int monkSpecialsCount(int level) {')
a('    if (level < 3) return 0;')
a('    if (level > 13) return 11;')
a('    return level - 2;')
a('}')
a('')
a('// The letter and the level of the i-th')
a('// special (0-based).')
a('inline char monkSpecialLetter(int i) {')
a('    static const char kLetters[11] = {')
for _, letter, _ in monk_specials:
    a('        ' + Q + letter + Q + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 10) i = 10;')
a('    return kLetters[i];')
a('}')
a('')
a('inline int monkSpecialLevel(int i) {')
a('    static const int kLevels[11] = {')
for lvl, _, _ in monk_specials:
    a('        ' + str(lvl) + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 10) i = 10;')
a('    return kLevels[i];')
a('}')
a('')
a('// The individual specials, as ladders.')
a('')
a('// A: speak with animals as druids do, from 3rd.')
a('inline int monkSpeakWithAnimalsLevel() { return 3; }')
a('')
a('// B: ESP has 30% chance at 4th, dropping 2%')
a('// per level thereafter.')
a('inline int monkEspSuccessPercent(int level) {')
a('    if (level < 4) return 100;')
a('    int v = 30 - 2 * (level - 4);')
a('    return v > 0 ? v : 0;')
a('}')
a('')
a('// C: no disease of any sort, never affected')
a('// by haste or slow, from 5th.')
a('inline int monkDiseaseImmuneLevel() { return 5; }')
a('')
a('// D: self-induced catalepsy, from 6th;')
a('// maintained for twice the level in turns')
a('// (12 turns at 6th, 14 at 7th, ...).')
a('inline int monkCatalepsyTurns(int level) {')
a('    if (level < 6) return 0;')
a('    return 2 * level;')
a('}')
a('')
a('// E: heal own damage, once per day: d4+1 at')
a('// 7th, the bonus +1 per level thereafter')
a('// (3-6 at 8th, 4-7 at 9th, ...).')
a('inline int monkHealBonusPerDay(int level) {')
a('    if (level < 7) return 0;')
a('    return level - 6;')
a('}')
a('')
a('// F: speak with plants as druids do, from 8th.')
a('inline int monkSpeakWithPlantsLevel() { return 8; }')
a('')
a('// G: beguiling, charms, hypnosis and')
a('// suggestion have but 50% chance at 9th,')
a('// dropping 5% per level thereafter (45% at')
a('// 10th, 40% at 11th, ...).')
a('inline int monkCharmAffectPercent(int level) {')
a('    if (level < 9) return 100;')
a('    int v = 50 - 5 * (level - 9);')
a('    return v > 0 ? v : 0;')
a('}')
a('')
a('// H: telepathic and mind blast attacks vs a')
a('// monk of 10th or higher read as if the')
a('// monk had 18 intelligence.')
a('inline int monkMindBlastLevel() { return 10; }')
a('')
a('inline int monkMindBlastEffectiveInt() { return 18; }')
a('')
a('// I: not affected by poison of any type,')
a('// from 11th.')
a('inline int monkPoisonImmuneLevel() { return 11; }')
a('')
a('// J: geas and quest spells have no effect,')
a('// from 12th.')
a('inline int monkGeasImmuneLevel() { return 12; }')
a('')
a('// K: the quivering palm, from 13th. Once per')
a('// week; the touch within 3 melee rounds or')
a('// the power is drained for a week; no effect')
a('// on the undead or creatures hit only by')
a('// magical weaponry; the victim may not have')
a('// more hit dice than the monk, nor more than')
a('// 200% of the monk hit points; the death')
a('// command within one day per monk level.')
a('inline int monkQuiveringPalmLevel() { return 13; }')
a('')
a('inline int monkQuiveringPalmAttemptsPerWeek() { return 1; }')
a('')
a('inline int monkQuiveringPalmTouchRounds() { return 3; }')
a('')
a('inline int monkQuiveringPalmHpCapPercent() { return 200; }')
a('')
a('// ---- the open-hand stun and kill ----')
a('')
a('// A to-hit die score exceeding the minimum')
a('// needed by 5 or more stuns the opponent.')
a('inline int monkStunMargin() { return 5; }')
a('')
a('// A stunned opponent is out for 1-6 (d6)')
a('// melee rounds.')
a('inline int monkStunRoundsDie() { return 6; }')
a('')
a('// The kill percent: the victim armor class')
a('// modified by one percent per monk level')
a('// above 7th (AC -1 at 7th is negative - no')
a('// chance; a 9th-level monk vs AC 5 is 7%).')
a('inline int monkKillPercent(int victimAc, int monkLevel) {')
a('    int over = monkLevel > 7 ? monkLevel - 7 : 0;')
a('    return victimAc + over;')
a('}')
a('')
a('// ---- the monk save advantages ----')
a('')
a('// Non-magical missiles are dodged or knocked')
a('// aside on a successful save vs petrification;')
a('// a successful save means NO damage from the')
a('// attack form. From 9th, a FAILED save still')
a('// means but half the total potential damage')
a('// (a basilisk gaze still petrifies).')
a('inline int monkHalfDamageOnFailedSaveLevel() { return 9; }')
a('')
a('// ---- the ranger surprise numbers (the R184 records) ----')
a('')
a('// The ranger surprises opponents 50% of the')
a('// time (d6 1-3) ...')
a('inline int rangerSurpriseOnD6(int roll) {')
a('    return roll >= 1 && roll <= 3;')
a('}')
a('')
a('// ... and is surprised only 16 2/3% of the')
a('// time (d6 1).')
a('inline int rangerSurprisedOnD6(int roll) {')
a('    return roll == 1;')
a('}')
a('')
a('// ---- the paladin turn-undead ladder (the R184 records) ----')
a('')
a('// From 3rd level the paladin affects undead')
a('// as a cleric of paladin level minus two (3rd')
a('// as a 1st-level cleric, 4th as a 2nd, and so')
a('// on, upward with each level). Below 3rd: 0 -')
a('// no power. This wraps the R147 matrix III')
a('// (combat.h: the paladin subtracts two levels).')
a('inline int paladinTurnClericLevel(int paladinLevel) {')
a('    if (paladinLevel < 3) return 0;')
a('    return paladinLevel - 2;')
a('}')
a('')
a('} // namespace rules')

create('rules/subclassspecials.h',
       'The per-subclass specials (R187)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/subclassspecials.h',
      '#include "rules/bard.h"  // R186: the bard (Appendix II)',
      '#include "rules/bard.h"  // R186: the bard (Appendix II)'
      + NL + '#include "rules/subclassspecials.h"  // R187: the per-subclass specials')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R187 battery audit (census 104)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R187: the per-subclass specials audit ----')
a('    // Every fee cell, the disguise ladder, backstab,')
a('    // the skill sharing, the monk specials A-K, the')
a('    // stun/kill rules, the ranger numbers, the')
a('    // paladin turn ladder.')
a('    {')
a('        int bad = 0;')
a('        // the fee table, cell by cell (15 x 8)')
a('        static const int kFees[15][8] = {')
for row in fees:
    a('            { ' + ', '.join(str(x) for x in row) + ' },')
a('        };')
a('        for (int al = 1; al <= 15; ++al)')
a('            for (int b = 0; b < 8; ++b)')
a('                if (rules::assassinMinimumFee(al, b)')
a('                    != kFees[al-1][b]) ++bad;')
a('        // the dash cells pin as 0')
a('        if (rules::assassinMinimumFee(1, 5) != 0) ++bad;')
a('        if (rules::assassinMinimumFee(1, 6) != 0) ++bad;')
a('        if (rules::assassinMinimumFee(1, 7) != 0) ++bad;')
a('        if (rules::assassinMinimumFee(4, 7) != 0) ++bad;')
a('        // the clamps: level and band')
a('        if (rules::assassinMinimumFee(0, 0) != 50) ++bad;')
a('        if (rules::assassinMinimumFee(99, 7) != 250000) ++bad;')
a('        if (rules::assassinMinimumFee(15, 99) != 250000) ++bad;')
a('        if (rules::assassinMinimumFee(15, -5) != 10000) ++bad;')
a('        // the victim bands')
a('        if (rules::assassinVictimBand(0) != 0) ++bad;')
a('        if (rules::assassinVictimBand(2) != 1) ++bad;')
a('        if (rules::assassinVictimBand(3) != 2) ++bad;')
a('        if (rules::assassinVictimBand(6) != 3) ++bad;')
a('        if (rules::assassinVictimBand(9) != 4) ++bad;')
a('        if (rules::assassinVictimBand(12) != 5) ++bad;')
a('        if (rules::assassinVictimBand(15) != 6) ++bad;')
a('        if (rules::assassinVictimBand(16) != 7) ++bad;')
a('        if (rules::assassinVictimBand(99) != 7) ++bad;')
a('        if (rules::assassinVictimBand(-5) != 0) ++bad;')
a('        // the disguise ladder: base 2, +2 per pose,')
a('        // max 8, then the observer adjustment')
a('        if (rules::assassinDisguiseSpotPercent(')
a('                false, false, false, 24) != 2) ++bad;')
a('        if (rules::assassinDisguiseSpotPercent(')
a('                true, false, false, 24) != 4) ++bad;')
a('        if (rules::assassinDisguiseSpotPercent(')
a('                true, true, false, 24) != 6) ++bad;')
a('        if (rules::assassinDisguiseSpotPercent(')
a('                true, true, true, 24) != 8) ++bad;')
a('        // the print example: INT+WIS 20 reduces the')
a('        // chance by 4%')
a('        if (rules::assassinDisguiseSpotPercent(')
a('                false, false, false, 20) != -2) ++bad;')
a('        // INT+WIS above 30 increases by 1% per point')
a('        if (rules::assassinDisguiseSpotPercent(')
a('                false, false, false, 36) != 8) ++bad;')
a('        if (rules::assassinDisguiseSpotPercent(')
a('                true, true, true, 18) != 2) ++bad;')
a('        if (rules::assassinDisguiseSpotPercent(')
a('                true, true, true, 31) != 9) ++bad;')
a('        // backstab: the multiplier ladder')
a('        if (rules::backstabMultiplier(1) != 2) ++bad;')
a('        if (rules::backstabMultiplier(4) != 2) ++bad;')
a('        if (rules::backstabMultiplier(5) != 3) ++bad;')
a('        if (rules::backstabMultiplier(8) != 3) ++bad;')
a('        if (rules::backstabMultiplier(9) != 4) ++bad;')
a('        if (rules::backstabMultiplier(12) != 4) ++bad;')
a('        if (rules::backstabMultiplier(13) != 5) ++bad;')
a('        if (rules::backstabMultiplier(16) != 5) ++bad;')
a('        if (rules::backstabMultiplier(17) != 5) ++bad;')
a('        if (rules::backstabMultiplier(0) != 2) ++bad;')
a('        if (rules::backstabHitBonusPercent() != 20) ++bad;')
a('        if (rules::backstabHitBonusDie() != 4) ++bad;')
a('        // the thief-skill sharing')
a('        if (rules::assassinThiefSkillLevel(3) != 1) ++bad;')
a('        if (rules::assassinThiefSkillLevel(4) != 2) ++bad;')
a('        if (rules::assassinThiefSkillLevel(15) != 13) ++bad;')
a('        if (rules::assassinThiefSkillLevel(1) != 1) ++bad;')
a('        if (rules::assassinThiefSkillLevel(2) != 1) ++bad;')
a('        if (rules::assassinBackstabLevel(3) != 3) ++bad;')
a('        if (rules::assassinBackstabLevel(15) != 15) ++bad;')
a('        if (rules::assassinBackstabLevel(1) != 1) ++bad;')
a('        if (rules::monkThiefSkillLevel(1) != 1) ++bad;')
a('        if (rules::monkThiefSkillLevel(7) != 7) ++bad;')
a('        if (rules::monkThiefSkillLevel(17) != 17) ++bad;')
a('        if (rules::monkThiefAbilityCount() != 6) ++bad;')
a('        if (std::string(rules::monkThiefAbilityName(0))')
a('            != "open locks") ++bad;')
a('        if (std::string(rules::monkThiefAbilityName(5))')
a('            != "climb walls") ++bad;')
a('        // the monk surprise ladder')
a('        if (rules::monkSurprisedPercent(1) != 33) ++bad;')
a('        if (rules::monkSurprisedPercent(2) != 32) ++bad;')
a('        if (rules::monkSurprisedPercent(3) != 30) ++bad;')
a('        if (rules::monkSurprisedPercent(4) != 28) ++bad;')
a('        if (rules::monkSurprisedPercent(5) != 26) ++bad;')
a('        if (rules::monkSurprisedPercent(13) != 10) ++bad;')
a('        if (rules::monkSurprisedPercent(17) != 2) ++bad;')
a('        if (rules::monkSurprisedPercent(18) != 0) ++bad;')
a('        if (rules::monkSurprisedPercent(0) != 33) ++bad;')
a('        // the specials ladder A-K')
a('        if (rules::monkSpecialsCount(1) != 0) ++bad;')
a('        if (rules::monkSpecialsCount(2) != 0) ++bad;')
a('        if (rules::monkSpecialsCount(3) != 1) ++bad;')
a('        if (rules::monkSpecialsCount(7) != 5) ++bad;')
a('        if (rules::monkSpecialsCount(13) != 11) ++bad;')
a('        if (rules::monkSpecialsCount(17) != 11) ++bad;')
a('        if (rules::monkSpecialLetter(0) != ' + Q + 'A' + Q + ') ++bad;')
a('        if (rules::monkSpecialLetter(10) != ' + Q + 'K' + Q + ') ++bad;')
a('        if (rules::monkSpecialLetter(99) != ' + Q + 'K' + Q + ') ++bad;')
a('        if (rules::monkSpecialLevel(0) != 3) ++bad;')
a('        if (rules::monkSpecialLevel(10) != 13) ++bad;')
a('        // the individual specials')
a('        if (rules::monkSpeakWithAnimalsLevel() != 3) ++bad;')
a('        if (rules::monkEspSuccessPercent(3) != 100) ++bad;')
a('        if (rules::monkEspSuccessPercent(4) != 30) ++bad;')
a('        if (rules::monkEspSuccessPercent(5) != 28) ++bad;')
a('        if (rules::monkEspSuccessPercent(6) != 26) ++bad;')
a('        if (rules::monkEspSuccessPercent(20) != 0) ++bad;')
a('        if (rules::monkDiseaseImmuneLevel() != 5) ++bad;')
a('        if (rules::monkCatalepsyTurns(5) != 0) ++bad;')
a('        if (rules::monkCatalepsyTurns(6) != 12) ++bad;')
a('        if (rules::monkCatalepsyTurns(7) != 14) ++bad;')
a('        if (rules::monkHealBonusPerDay(6) != 0) ++bad;')
a('        if (rules::monkHealBonusPerDay(7) != 1) ++bad;')
a('        if (rules::monkHealBonusPerDay(8) != 2) ++bad;')
a('        if (rules::monkHealBonusPerDay(9) != 3) ++bad;')
a('        if (rules::monkSpeakWithPlantsLevel() != 8) ++bad;')
a('        if (rules::monkCharmAffectPercent(8) != 100) ++bad;')
a('        if (rules::monkCharmAffectPercent(9) != 50) ++bad;')
a('        if (rules::monkCharmAffectPercent(10) != 45) ++bad;')
a('        if (rules::monkCharmAffectPercent(11) != 40) ++bad;')
a('        if (rules::monkCharmAffectPercent(19) != 0) ++bad;')
a('        if (rules::monkMindBlastLevel() != 10) ++bad;')
a('        if (rules::monkMindBlastEffectiveInt() != 18) ++bad;')
a('        if (rules::monkPoisonImmuneLevel() != 11) ++bad;')
a('        if (rules::monkGeasImmuneLevel() != 12) ++bad;')
a('        if (rules::monkQuiveringPalmLevel() != 13) ++bad;')
a('        if (rules::monkQuiveringPalmAttemptsPerWeek()')
a('            != 1) ++bad;')
a('        if (rules::monkQuiveringPalmTouchRounds() != 3) ++bad;')
a('        if (rules::monkQuiveringPalmHpCapPercent() != 200) ++bad;')
a('        // the stun and kill rules')
a('        if (rules::monkStunMargin() != 5) ++bad;')
a('        if (rules::monkStunRoundsDie() != 6) ++bad;')
a('        // the print example: AC -1 at 7th is a')
a('        // negative chance; a 9th-level monk vs')
a('        // AC 5 is 7%')
a('        if (rules::monkKillPercent(-1, 7) != -1) ++bad;')
a('        if (rules::monkKillPercent(5, 9) != 7) ++bad;')
a('        if (rules::monkKillPercent(5, 7) != 5) ++bad;')
a('        if (rules::monkKillPercent(0, 10) != 3) ++bad;')
a('        if (rules::monkKillPercent(3, 1) != 3) ++bad;')
a('        if (rules::monkHalfDamageOnFailedSaveLevel()')
a('            != 9) ++bad;')
a('        // the ranger surprise numbers')
a('        if (!rules::rangerSurpriseOnD6(1)) ++bad;')
a('        if (!rules::rangerSurpriseOnD6(3)) ++bad;')
a('        if (rules::rangerSurpriseOnD6(4)) ++bad;')
a('        if (rules::rangerSurpriseOnD6(0)) ++bad;')
a('        if (rules::rangerSurpriseOnD6(7)) ++bad;')
a('        if (!rules::rangerSurprisedOnD6(1)) ++bad;')
a('        if (rules::rangerSurprisedOnD6(2)) ++bad;')
a('        if (rules::rangerSurprisedOnD6(0)) ++bad;')
a('        // the paladin turn ladder: cleric of')
a('        // level minus two, from 3rd')
a('        if (rules::paladinTurnClericLevel(2) != 0) ++bad;')
a('        if (rules::paladinTurnClericLevel(3) != 1) ++bad;')
a('        if (rules::paladinTurnClericLevel(4) != 2) ++bad;')
a('        if (rules::paladinTurnClericLevel(5) != 3) ++bad;')
a('        if (rules::paladinTurnClericLevel(11) != 9) ++bad;')
a('        if (rules::paladinTurnClericLevel(0) != 0) ++bad;')
a('        printf("R187 per-subclass specials audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert every probe (the R184b lesson):
# positive AND negative, against the pinned data
def fee(al, b):
    al = min(max(al, 1), 15)
    b = min(max(b, 0), 7)
    return fees[al - 1][b]

for args, e in [((1, 5), 0), ((1, 6), 0), ((1, 7), 0), ((4, 7), 0),
                ((0, 0), 50), ((99, 7), 250000), ((15, 99), 250000),
                ((15, -5), 10000)]:
    assert fee(*args) == e, ('fee clamp', args, fee(*args), e)
for al in range(1, 16):
    for b in range(8):
        assert fees[al - 1][b] >= 0
# the disguise probes
def dg(pc, pr, ps, iw):
    c = 2 + 2 * (pc + pr + ps)
    if c > 8:
        c = 8
    if iw < 24:
        c -= 24 - iw
    elif iw > 30:
        c += iw - 30
    return c

for args, e in [((False, False, False, 24), 2),
                ((True, False, False, 24), 4),
                ((True, True, False, 24), 6),
                ((True, True, True, 24), 8),
                ((False, False, False, 20), -2),
                ((False, False, False, 36), 8),
                ((True, True, True, 18), 2),
                ((True, True, True, 31), 9)]:
    assert dg(*args) == e, ('disguise', args, dg(*args), e)
# the skill-sharing probes
for al, e in [(3, 1), (4, 2), (15, 13), (1, 1), (2, 1)]:
    got = max(1, al - 2)
    assert got == e, ('skill', al, got, e)
# the ESP ladder
for lv, e in [(3, 100), (4, 30), (5, 28), (6, 26), (20, 0)]:
    got = 100 if lv < 4 else max(0, 30 - 2 * (lv - 4))
    assert got == e, ('esp', lv, got, e)
# the charm ladder
for lv, e in [(8, 100), (9, 50), (10, 45), (11, 40), (19, 0)]:
    got = 100 if lv < 9 else max(0, 50 - 5 * (lv - 9))
    assert got == e, ('charm', lv, got, e)
# the kill percent probes
for args, e in [((-1, 7), -1), ((5, 9), 7), ((5, 7), 5),
                ((0, 10), 3), ((3, 1), 3)]:
    ac, ml = args
    got = ac + (ml - 7 if ml > 7 else 0)
    assert got == e, ('kill', args, got, e)
# the specials count ladder
for lv, e in [(1, 0), (2, 0), (3, 1), (7, 5), (13, 11), (17, 11)]:
    got = 0 if lv < 3 else (11 if lv > 13 else lv - 2)
    assert got == e, ('specials', lv, got, e)
# the ranger probes: surprise 1-3, surprised on 1
for roll in range(0, 8):
    assert (1 <= roll <= 3) == (roll in (1, 2, 3)), roll
    assert (roll == 1) == (roll == 1), roll
# the paladin ladder
for pl, e in [(2, 0), (3, 1), (4, 2), (5, 3), (11, 9), (0, 0)]:
    got = 0 if pl < 3 else pl - 2
    assert got == e, ('pal turn', pl, got, e)
# the negative name probes must be ABSENT
for n in ['long bow']:
    assert n not in monk_thief_abilities, n

patch('regtest.cpp',
      'R187 per-subclass specials audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the R187 box flipped
# ---------------------------------------------------------------------------

box_old = ('- R187+ the per-subclass specials that remain -'
           + NL + '      the assassin fees and disguise layer, the'
           + NL + '      monk special abilities, backstab for the'
           + NL + '      assassin, thief-skill sharing.')

box_new = ('- [x] R187 the per-subclass specials - PINNED:'
           + NL + '      rules/subclassspecials.h CREATED: the'
           + NL + '      MINIMUM FEES FOR ASSASSINATION table (15'
           + NL + '      rows x 8 victim bands, every cell, dashes'
           + NL + '      as 0; the noble-victim multiplier is a'
           + NL + '      referee judgment recorded in comments),'
           + NL + '      the disguise spotting layer (base 2% per'
           + NL + '      day, +2% per pose difference, max 8%; the'
           + NL + '      observer INT+WIS adjustment below 24 and'
           + NL + '      above 30), the backstab multipliers'
           + NL + '      (double through quintuple per four'
           + NL + '      levels, hit +20%/+4), the thief-skill'
           + NL + '      sharing (the assassin two levels below,'
           + NL + '      backstab at full level; the monk at'
           + NL + '      identical level with the six listed'
           + NL + '      abilities - open locks is the numbering'
           + NL + '      head the OCR swallowed), the monk surprise'
           + NL + '      ladder (33 at 1st, 32 at 2nd, down 2% per'
           + NL + '      level), the monk specials A-K (one per'
           + NL + '      level 3rd-13th: speak with animals, ESP'
           + NL + '      masking, disease immunity, catalepsy,'
           + NL + '      healing, speak with plants, charm'
           + NL + '      resistance, mind blast as 18 INT, poison'
           + NL + '      immunity, geas immunity, the quivering'
           + NL + '      palm), the open-hand stun and kill rules'
           + NL + '      (stun at 5+ over the needed roll, 1-6'
           + NL + '      rounds; kill percent AC + one per level'
           + NL + '      above 7th), the monk save advantages, the'
           + NL + '      ranger surprise numbers (surprises on d6'
           + NL + '      1-3, surprised on 1) and the paladin'
           + NL + '      turn-undead ladder (a cleric of paladin'
           + NL + '      level minus two, from 3rd; wraps the R147'
           + NL + '      matrix III) - the R184 records paid off.'
           + NL + '      The R187 battery audit walks every fee cell'
           + NL + '      and ladder. Census 104.')

t = rd('tools/phb_gap_report.md')
if 'R187 the per-subclass specials - PINNED' not in t:
    assert t.count(box_old) == 1, 'R187 box anchor not unique'
else:
    assert t.count(box_old) == 0, 'R187 box old text lingers'

patch('tools/phb_gap_report.md',
      'R187 the per-subclass specials - PINNED',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R187 landed the per-subclass specials',
      'census 103. Next: the gap report names the'
      + NL + 'next round.',
      'census 103. Next: the gap report names the'
      + NL + 'next round.'
      + NL + 'R187 landed the per-subclass specials:'
      + NL + 'rules/subclassspecials.h CREATED (the fee table,'
      + NL + 'the disguise layer, backstab, the skill sharing,'
      + NL + 'the monk specials A-K with stun/kill and the'
      + NL + 'quivering palm, the ranger surprise numbers, the'
      + NL + 'paladin turn ladder). New R187 battery audit;'
      + NL + 'census 104. Next: the gap report names the next'
      + NL + 'round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R187 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R187 note: 5 patches; census 104 (one new audit);')
print('real gate: md5sum rules/subclassspecials.h')
print('commit: R187: the per-subclass specials pinned - the fees, the')
print('disguise, the monk specials and the records (census 104)')

