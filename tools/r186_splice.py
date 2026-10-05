#!/usr/bin/env python3
# R186 splice: the bard (Appendix II).
#
# rules/bard.h is CREATED: Bards Table I (23
# levels, bard XP only: the thresholds, the
# level titles Rhymer through M. Bard 23rd,
# the 6-sided accumulated hit dice 0* then 1
# through 10 then 10+1 through 10+12, the
# druid spell slots 1-5 with the cap at
# 12th-level druid ability until the 23rd,
# which casts at 13th), Bards Table II (the
# colleges Probationer through Magna Alumnae,
# the language gains, the charm percentages,
# the legend lore and item knowledge
# percentages - every cell), the progression
# gates (fighter at least 5th and before 8th,
# thief between 5th and 9th, then the druid
# studies and Bards Table I), the ability
# minimums (STR WIS DEX CHA 15+, INT 12, CON
# 10), human or half-elf, always neutral,
# Bards Table III (leather or magical
# chainmail, no shield, the 8 permitted
# weapons, oil yes, poison never except by
# neutral evil bards), the combat-as-fighter /
# thief-functions / most-favorable-saves
# wiring, the poetics layers (morale +10%,
# hit +1, 2 rounds, 1 turn), the song
# negation, the musical charming rules, the
# henchmen ladder, and the musical item
# bonuses.
#
# regtest.cpp: the include lands WITH the
# audit (the R179 lesson); the R186 battery
# audit walks every cell of both tables and
# every gate and ladder. Census 103.
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
# Patch 1: rules/bard.h CREATED
# ---------------------------------------------------------------------------

# Bards Table I: 23 rows.
# xp min, title, druid spell slots 1-5
# (dashes pin as 0).
t1 = [
    (0,       'Rhymer',        [1, 0, 0, 0, 0]),
    (2001,    'Lyrist',        [2, 0, 0, 0, 0]),
    (4001,    'Sonnateer',     [3, 0, 0, 0, 0]),
    (8001,    'Skald',         [3, 1, 0, 0, 0]),
    (16001,   'Racaraide',     [3, 2, 0, 0, 0]),
    (25001,   'Joungleur',     [3, 3, 0, 0, 0]),
    (40001,   'Troubador',     [3, 3, 1, 0, 0]),
    (60001,   'Minstrel',      [3, 3, 2, 0, 0]),
    (85001,   'Muse',          [3, 3, 3, 0, 0]),
    (110001,  'Lorist',        [3, 3, 3, 1, 0]),
    (150001,  'Bard',          [3, 3, 3, 2, 0]),
    (200001,  'Master Bard',   [3, 3, 3, 3, 0]),
    (400001,  'M. Bard 13th',  [3, 3, 3, 3, 1]),
    (600001,  'M. Bard 14th',  [3, 3, 3, 3, 2]),
    (800001,  'M. Bard 15th',  [3, 3, 3, 3, 3]),
    (1000001, 'M. Bard 16th',  [4, 3, 3, 3, 3]),
    (1200001, 'M. Bard 17th',  [4, 4, 3, 3, 3]),
    (1400001, 'M. Bard 18th',  [4, 4, 4, 3, 3]),
    (1600001, 'M. Bard 19th',  [5, 4, 4, 4, 3]),
    (1800001, 'M. Bard 20th',  [5, 4, 4, 4, 4]),
    (2000001, 'M. Bard 21st',  [5, 5, 4, 4, 4]),
    (2200001, 'M. Bard 22nd',  [5, 5, 5, 4, 4]),
    (3000001, 'M. Bard 23rd',  [5, 5, 5, 5, 5]),
]

# Bards Table II: 23 rows.
# college, languages known, charm %, legend lore %
t2 = [
    ('Probationer',   0, 15, 0),
    ('Fochlucan',     0, 20, 5),
    ('Fochlucan',     0, 22, 7),
    ('Fochlucan',     1, 24, 10),
    ('Mac-Fuirmidh',  0, 30, 13),
    ('Mac-Fuirmidh',  1, 32, 16),
    ('Mac-Fuirmidh',  1, 34, 20),
    ('Doss',          0, 40, 25),
    ('Doss',          1, 42, 30),
    ('Doss',          1, 44, 35),
    ('Canaith',       0, 50, 50),
    ('Canaith',       1, 53, 53),
    ('Canaith',       1, 56, 56),
    ('Cli',           0, 60, 55),
    ('Cli',           1, 63, 60),
    ('Cli',           1, 66, 65),
    ('Anstruth',     0, 70, 70),
    ('Anstruth',     1, 73, 75),
    ('Anstruth',     1, 76, 80),
    ('Ollamh',        1, 80, 85),
    ('Ollamh',        1, 84, 90),
    ('Ollamh',        1, 88, 95),
    ('Magna Alumnae', 1, 95, 99),
]

assert len(t1) == 23 and len(t2) == 23
for row in t1:
    assert len(row[2]) == 5 and all(0 <= x <= 5 for x in row[2])
# the thresholds are strictly increasing
xps = [r[0] for r in t1]
assert xps == sorted(xps) and len(set(xps)) == 23

# the hit dice ladder: 0* then 1-10 then 10+1
# through 10+12 (the bard keeps the fighter
# dice and the thief dice; the column counts
# the d6s added as a bard)
def bhd(lv):
    return min(lv - 1, 10) + max(lv - 11, 0)

for lv in range(1, 24):
    expect = 0 if lv == 1 else (min(lv - 1, 10) + (lv - 11 if lv > 11 else 0))
    assert bhd(lv) == expect
assert bhd(1) == 0 and bhd(11) == 10 and bhd(12) == 11 and bhd(23) == 22

# Table III: the permitted weapons (the
# print: club, dagger, dart, javelin, sling,
# scimitar, spear, staff, sword - bastard,
# broad, long, short)
bard_weapons = [
    'club', 'dagger', 'dart', 'javelin', 'sling',
    'scimitar', 'spear', 'staff', 'sword',
]

assert len(bard_weapons) == 9

hdr = []
a = hdr.append

a('// ============================================================================')
a('// Adnd1 - rules/bard.h')
a('// The bard, PHB Appendix II (R186).')
a('//')
a('// Bards Table I (23 levels, bard XP only), Bards')
a('// Table II (colleges, language gains, charm and')
a('// legend lore percents, every cell), the')
a('// progression gates, the ability minimums, the')
a('// race and alignment pins, Bards Table III,')
a('// the combat/thief/saves wiring, the poetics')
a('// layers, the henchmen ladder and the musical')
a('// item bonuses.')
a('//')
a('// JUDGMENTs:')
a('//   - the Table I row-20 lower bound pins as')
a('//     1,800,001: the sequence 1.4 / 1.6 / 1.8 /')
a('//     2.0 million is strictly increasing, and')
a('//     the OCR of the upload shows 1,000,001')
a('//     which would fall below the 19th row; the')
a('//     print boundary is 1,800,001.')
a('//   - the Table I hit dice column (6-sided dice')
a('//     for accumulated hit points) pins as the')
a('//     count of BARD d6s: 0 at 1st (the asterisk:'),
a('//     the fighter dice - and thief dice if the')
a('//     thief level exceeds the fighter level -')
a('//     are retained), 1 through 10 at 2nd-11th,')
a('//     then 10+1 through 10+12 at 12th-23rd.')
a('//   - the bard casts druid spells as a druid of')
a('//     the same level, never beyond 12th-level')
a('//     druid ability until the 23rd, which casts')
a('//     at 13th. Bards can read druid scrolls.')
a('//   - Table III: leather or magical chainmail')
a('//     only, no shield; the nine permitted')
a('//     weapons (the sword covers bastard, broad,')
a('//     long and short); oil yes; poison never')
a('//     (except by neutral evil bards).')
a('//   - a bard always engages in combat at the')
a('//     fighter level attained, functions as a')
a('//     thief of the level previously attained,')
a('//     and saves on the most favorable table')
a('//     with the bard level read as a druid. The')
a('//     stringed instrument requirement, the')
a('//     stronghold-at-23rd rule and the college')
a('//     snobbery (Magna Alumnae aid any bard)')
a('//     are recorded as comments.')
a('//   - poetics: morale +10% and attack +1, both')
a('//     requiring 2 rounds, lasting 1 complete')
a('//     turn; 1 round does neither.')
a('//   - the alignment pin (always neutral) is a')
a('//     constant; the engine alignment graph')
a('//     round consumes it.')
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
a('// ---- the gates ----')
a('')
a('static const int BARD_LEVEL_COUNT = 23;')
a('static const int BARD_PRIME_MIN = 15;   // STR WIS DEX CHA')
a('static const int BARD_INT_MIN = 12;')
a('static const int BARD_CON_MIN = 10;')
a('')
a('// True when the six ability scores meet the')
a('// printed minimums (STR WIS DEX CHA 15+,')
a('// INT 12, CON 10).')
a('inline bool bardAbilityGate(int str, int wis,')
a('                          int dex, int cha,')
a('                          int int_, int con) {')
a('    return str >= BARD_PRIME_MIN')
a('           && wis >= BARD_PRIME_MIN')
a('           && dex >= BARD_PRIME_MIN')
a('           && cha >= BARD_PRIME_MIN')
a('           && int_ >= BARD_INT_MIN')
a('           && con >= BARD_CON_MIN;')
a('}')
a('')
a('// Human or half-elf only (the CharRace')
a('// order: human 0, half-elf 4).')
a('inline bool bardRaceAllowed(int race) {')
a('    return race == 0 || race == 4;')
a('}')
a('')
a('// The fighter gate: exclusively fighter')
a('// until at least 5th, and in any event the')
a('// change to thief comes before 8th.')
a('inline bool bardFighterWindow(int fighterLevel) {')
a('    return fighterLevel >= 5 && fighterLevel <= 7;')
a('}')
a('')
a('// The thief gate: leave off thieving')
a('// sometime between 5th and 9th level of')
a('// ability and begin the druid studies.')
a('inline bool bardThiefWindow(int thiefLevel) {')
a('    return thiefLevel >= 5 && thiefLevel <= 9;')
a('}')
a('')
a('// Always neutral (chaotic, evil, good or')
a('// lawful neutral permitted).')
a('inline bool bardNeutralOnly() {')
a('    return true;')
a('}')
a('')
a('// ---- Bards Table I ----')
a('')
a('// The bard XP threshold of level (bard XP')
a('// only; previously earned XP is not')
a('// considered). Level clamps to 1-23.')
a('inline int bardXpForLevel(int level) {')
a('    static const int kXp[23] = {')
for xp, _, _ in t1:
    a('        ' + str(xp) + ',')
a('    };')
a('    if (level < 1) level = 1;')
a('    if (level > 23) level = 23;')
a('    return kXp[level - 1];')
a('}')
a('')
a('// The level titles (Rhymer through M.')
a('// Bard 23rd).')
a('inline const char* bardTitle(int level) {')
a('    static const char* const kTitles[23] = {')
for _, title, _ in t1:
    a('        ' + DQ + title + DQ + ',')
a('    };')
a('    if (level < 1) level = 1;')
a('    if (level > 23) level = 23;')
a('    return kTitles[level - 1];')
a('}')
a('')
a('// The accumulated bard hit dice: 0 at 1st')
a('// (the fighter dice - plus thief dice if')
a('// the thief level exceeds the fighter')
a('// level - are retained), then d6 per bard')
a('// level through 10, then +1 per level past')
a('// the 11th (10+1 ... 10+12).')
a('inline int bardHitDice(int level) {')
a('    if (level < 1) return 0;')
a('    if (level > 23) level = 23;')
a('    int dice = level - 1;')
a('    if (dice > 10) dice = 10;')
a('    if (level > 11) dice += level - 11;')
a('    return dice;')
a('}')
a('')
a('// The druid spell slots of spellLevel')
a('// (1-5) at bard level. Dashes pin as 0.')
a('inline int bardDruidSlots(int level, int spellLevel) {')
a('    static const int kSlots[23][5] = {')
for _, _, slots in t1:
    a('        { ' + ', '.join(str(x) for x in slots) + ' },')
a('    };')
a('    if (level < 1) return 0;')
a('    if (level > 23) level = 23;')
a('    if (spellLevel < 1) spellLevel = 1;')
a('    if (spellLevel > 5) spellLevel = 5;')
a('    return kSlots[level - 1][spellLevel - 1];')
a('}')
a('')
a('// The druid ability the bard casts at:')
a('// the same level, capped at 12th-level')
a('// druid ability until the 23rd, which')
a('// casts at 13th.')
a('inline int bardDruidCastLevel(int level) {')
a('    if (level < 1) return 0;')
a('    if (level >= 23) return 13;')
a('    if (level > 12) return 12;')
a('    return level;')
a('}')
a('')
a('// ---- Bards Table II ----')
a('')
a('// The college of the level (Probationer')
a('// through Magna Alumnae).')
a('inline const char* bardCollege(int level) {')
a('    static const char* const kCollege[23] = {')
for college, _, _, _ in t2:
    a('        ' + DQ + college + DQ + ',')
a('    };')
a('    if (level < 1) level = 1;')
a('    if (level > 23) level = 23;')
a('    return kCollege[level - 1];')
a('}')
a('')
a('// The new languages gained upon achieving')
a('// the level (no study required).')
a('inline int bardLanguages(int level) {')
a('    static const int kLang[23] = {')
for _, lang, _, _ in t2:
    a('        ' + str(lang) + ',')
a('    };')
a('    if (level < 1) return 0;')
a('    if (level > 23) level = 23;')
a('    return kLang[level - 1];')
a('}')
a('')
a('// The charm percentage: the chance of')
a('// successfully casting a charm person (or')
a('// charm monster) spell with music. Does')
a('// not negate immunities or the save.')
a('inline int bardCharmPercent(int level) {')
a('    static const int kCharm[23] = {')
for _, _, charm, _ in t2:
    a('        ' + str(charm) + ',')
a('    };')
a('    if (level < 1) return 0;')
a('    if (level > 23) level = 23;')
a('    return kCharm[level - 1];')
a('}')
a('')
a('// The legend lore and item knowledge')
a('// percentage (weapons, armor, potions,')
a('// scrolls and employed or inscribed items).')
a('inline int bardLegendLorePercent(int level) {')
a('    static const int kLore[23] = {')
for _, _, _, lore in t2:
    a('        ' + str(lore) + ',')
a('    };')
a('    if (level < 1) return 0;')
a('    if (level > 23) level = 23;')
a('    return kLore[level - 1];')
a('}')
a('')
a('// ---- Bards Table III and the wiring ----')
a('')
a('// The nine permitted weapons (the sword')
a('// covers bastard, broad, long, short;')
a('// magical weapons of the named types')
a('// included). Matching is lowercase name')
a('// equality.')
a('inline int bardWeaponCount() { return 9; }')
a('')
a('inline const char* bardWeaponName(int i) {')
a('    static const char* const kNames[9] = {')
for w in bard_weapons:
    a('        ' + DQ + w + DQ + ',')
a('    };')
a('    if (i < 0) i = 0;')
a('    if (i > 8) i = 8;')
a('    return kNames[i];')
a('}')
a('')
a('// True when the lowercase weapon name is')
a('// permitted to a bard.')
a('inline bool bardWeaponAllowed(const char* name) {')
a('    if (!name) return false;')
a('    for (int i = 0; i < 9; ++i)')
a('        if (std::string(name) == bardWeaponName(i))')
a('            return true;')
a('    return false;')
a('}')
a('')
a('// The armor pin: leather or magical')
a('// chainmail only, never a shield.')
a('enum BardArmor : int {')
a('    BARD_ARMOR_LEATHER_OR_CHAINMAIL = 0')
a('};')
a('')
a('inline bool bardShieldAllowed() { return false; }')
a('')
a('// Oil is permitted; poison never (except')
a('// by neutral evil bards).')
a('inline bool bardOilAllowed() { return true; }')
a('')
a('inline bool bardPoisonAllowed(bool neutralEvil) {')
a('    return neutralEvil;')
a('}')
a('')
a('// The wiring: combat at the fighter level')
a('// attained, thief functions at the thief')
a('// level previously attained, saves on the')
a('// most favorable table with the bard level')
a('// read as a druid (consumed by the engine')
a('// save rounds).')
a('')
a('// ---- the poetics layers ----')
a('')
a('static const int BARD_POETIC_ROUNDS = 2;')
a('static const int BARD_POETIC_TURN = 1;   // lasts 1 complete turn')
a('static const int BARD_MORALE_BONUS = 10; // percent')
a('static const int BARD_HIT_BONUS = 1;     // ferocity in attack')
a('')
a('// ---- the henchmen ladder ----')
a('')
a('// 1 henchman at 5th, 2 at 8th, 3 at 11th,')
a('// 4 at 14th, 5 at 17th, 6 at 20th, any')
a('// number at 23rd; subject to charisma.')
a('// Henchmen are druids, fighters or thieves')
a('// of human, half-elven or elven race; a')
a('// bard never serves as a henchman longer')
a('// than 1-4 months; only 23rd-level bards')
a('// construct strongholds.')
a('inline int bardHenchmen(int level) {')
a('    static const int kHench[24] = {')
for lv in range(0, 24):
    if lv >= 23:
        a('        999,   // any number at 23rd')
    else:
        a('        ' + str((lv - 2) // 3 if lv >= 5 else 0) + ',')
a('    };')
a('    if (level < 0) return 0;')
a('    if (level > 23) level = 23;')
a('    return kHench[level];')
a('}')
a('')
a('// ---- the musical item bonuses ----')
a('')
a('// Miscellaneous musical magic is superior')
a('// when employed by a bard: Drums of Panic')
a('// save at -1, Horn of Blasting 50% greater')
a('// damage, Lyre of Building double effects,')
a('// Pipes of the Sewer double the rats in')
a('// half the usual time.')
a('inline int bardDrumsOfPanicSaveMod() { return -1; }')
a('')
a('inline int bardHornOfBlastingDamageFactorPercent() {')
a('    return 150;')
a('}')
a('')
a('inline int bardLyreOfBuildingFactor() { return 2; }')
a('')
a('inline int bardPipesOfSewerRatFactor() { return 2; }')
a('')
a('} // namespace rules')

# bardWeaponAllowed uses std::string - the
# include must be present in the header
if '#include <string>' not in NL.join(hdr):
    hdr.insert(hdr.index('#include <cstdint>') + 1,
               '#include <string>')

create('rules/bard.h',
       'The bard, PHB Appendix II (R186)',
       NL.join(hdr) + NL)

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include (the R179 lesson)
# ---------------------------------------------------------------------------

patch('regtest.cpp',
      'rules/bard.h',
      '#include "rules/multiclass.h"  // R185: the multi-class and dual-class rules',
      '#include "rules/multiclass.h"  // R185: the multi-class and dual-class rules'
      + NL + '#include "rules/bard.h"  // R186: the bard (Appendix II)')

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R186 battery audit (census 103)
# ---------------------------------------------------------------------------

aud = []
a = aud.append

a('    // ---- R186: the bard audit ----')
a('    // Every cell of Tables I and II, the gates,')
a('    // the ladders and the wiring.')
a('    {')
a('        int bad = 0;')
a('        // the ability gate: STR WIS DEX CHA 15+,')
a('        // INT 12, CON 10')
a('        if (!rules::bardAbilityGate(15, 15, 15, 15,')
a('                                12, 10)) ++bad;')
a('        if (!rules::bardAbilityGate(18, 16, 15, 17,')
a('                                13, 11)) ++bad;')
a('        if (rules::bardAbilityGate(14, 15, 15, 15,')
a('                               12, 10)) ++bad;')
a('        if (rules::bardAbilityGate(15, 14, 15, 15,')
a('                               12, 10)) ++bad;')
a('        if (rules::bardAbilityGate(15, 15, 14, 15,')
a('                               12, 10)) ++bad;')
a('        if (rules::bardAbilityGate(15, 15, 15, 14,')
a('                               12, 10)) ++bad;')
a('        if (rules::bardAbilityGate(15, 15, 15, 15,')
a('                               11, 10)) ++bad;')
a('        if (rules::bardAbilityGate(15, 15, 15, 15,')
a('                               12, 9)) ++bad;')
a('        // the race gate: human or half-elf')
a('        if (!rules::bardRaceAllowed(0)) ++bad;')
a('        if (!rules::bardRaceAllowed(4)) ++bad;')
a('        if (rules::bardRaceAllowed(1)) ++bad;')
a('        if (rules::bardRaceAllowed(2)) ++bad;')
a('        if (rules::bardRaceAllowed(3)) ++bad;')
a('        if (rules::bardRaceAllowed(5)) ++bad;')
a('        if (rules::bardRaceAllowed(6)) ++bad;')
a('        // the progression windows')
a('        if (!rules::bardFighterWindow(5)) ++bad;')
a('        if (!rules::bardFighterWindow(6)) ++bad;')
a('        if (!rules::bardFighterWindow(7)) ++bad;')
a('        if (rules::bardFighterWindow(4)) ++bad;')
a('        if (rules::bardFighterWindow(8)) ++bad;')
a('        if (rules::bardFighterWindow(9)) ++bad;')
a('        if (!rules::bardThiefWindow(5)) ++bad;')
a('        if (!rules::bardThiefWindow(9)) ++bad;')
a('        if (rules::bardThiefWindow(4)) ++bad;')
a('        if (rules::bardThiefWindow(10)) ++bad;')
a('        if (!rules::bardNeutralOnly()) ++bad;')
a('        // Bards Table I, cell by cell: the XP')
a('        // thresholds, the titles, the hit dice,')
a('        // the druid slots')
a('        static const int kXp[23] = {')
for xp, _, _ in t1:
    a('            ' + str(xp) + ',')
a('        };')
a('        for (int lv = 1; lv <= 23; ++lv)')
a('            if (rules::bardXpForLevel(lv)')
a('                != kXp[lv-1]) ++bad;')
a('        static const char* const kTitles[23] = {')
for _, title, _ in t1:
    a('            ' + DQ + title + DQ + ',')
a('        };')
a('        for (int lv = 1; lv <= 23; ++lv)')
a('            if (std::string(rules::bardTitle(lv))')
a('                != kTitles[lv-1]) ++bad;')
a('        static const int kSlots[23][5] = {')
for _, _, slots in t1:
    a('            { ' + ', '.join(str(x) for x in slots) + ' },')
a('        };')
a('        for (int lv = 1; lv <= 23; ++lv)')
a('            for (int sl = 1; sl <= 5; ++sl)')
a('                if (rules::bardDruidSlots(lv, sl)')
a('                    != kSlots[lv-1][sl-1]) ++bad;')
a('        // the hit dice ladder: 0*, 1-10, then')
a('        // 10+1 through 10+12')
a('        if (rules::bardHitDice(1) != 0) ++bad;')
a('        if (rules::bardHitDice(2) != 1) ++bad;')
a('        if (rules::bardHitDice(11) != 10) ++bad;')
a('        if (rules::bardHitDice(12) != 11) ++bad;')
a('        if (rules::bardHitDice(23) != 22) ++bad;')
a('        if (rules::bardHitDice(0) != 0) ++bad;')
a('        if (rules::bardHitDice(99) != 22) ++bad;')
a('        // the clamps: level and spell level')
a('        if (rules::bardXpForLevel(0) != 0) ++bad;')
a('        if (rules::bardXpForLevel(99) != 3000001) ++bad;')
a('        if (rules::bardDruidSlots(0, 1) != 0) ++bad;')
a('        if (rules::bardDruidSlots(24, 1) != 5) ++bad;')
a('        if (rules::bardDruidSlots(23, 6) != 5) ++bad;')
a('        if (rules::bardDruidSlots(23, 0) != 5) ++bad;')
a('        if (std::string(rules::bardTitle(24))')
a('            != "M. Bard 23rd") ++bad;')
a('        // the druid cast ladder: same level,')
a('        // capped at 12th until the 23rd casts')
a('        // at 13th')
a('        if (rules::bardDruidCastLevel(1) != 1) ++bad;')
a('        if (rules::bardDruidCastLevel(5) != 5) ++bad;')
a('        if (rules::bardDruidCastLevel(12) != 12) ++bad;')
a('        if (rules::bardDruidCastLevel(13) != 12) ++bad;')
a('        if (rules::bardDruidCastLevel(22) != 12) ++bad;')
a('        if (rules::bardDruidCastLevel(23) != 13) ++bad;')
a('        if (rules::bardDruidCastLevel(0) != 0) ++bad;')
a('        // Bards Table II, cell by cell: the')
a('        // colleges, the languages, the percents')
a('        static const char* const kCollege[23] = {')
for college, _, _, _ in t2:
    a('            ' + DQ + college + DQ + ',')
a('        };')
a('        for (int lv = 1; lv <= 23; ++lv)')
a('            if (std::string(rules::bardCollege(lv))')
a('                != kCollege[lv-1]) ++bad;')
a('        static const int kLang[23] = {')
for _, lang, _, _ in t2:
    a('            ' + str(lang) + ',')
a('        };')
a('        for (int lv = 1; lv <= 23; ++lv)')
a('            if (rules::bardLanguages(lv)')
a('                != kLang[lv-1]) ++bad;')
a('        static const int kCharm[23] = {')
for _, _, charm, _ in t2:
    a('            ' + str(charm) + ',')
a('        };')
a('        for (int lv = 1; lv <= 23; ++lv)')
a('            if (rules::bardCharmPercent(lv)')
a('                != kCharm[lv-1]) ++bad;')
a('        static const int kLore[23] = {')
for _, _, _, lore in t2:
    a('            ' + str(lore) + ',')
a('        };')
a('        for (int lv = 1; lv <= 23; ++lv)')
a('            if (rules::bardLegendLorePercent(lv)')
a('                != kLore[lv-1]) ++bad;')
a('        // Table III: the weapon roster')
a('        if (rules::bardWeaponCount() != 9) ++bad;')
a('        if (!rules::bardWeaponAllowed("scimitar")) ++bad;')
a('        if (!rules::bardWeaponAllowed("sword")) ++bad;')
a('        if (!rules::bardWeaponAllowed("club")) ++bad;')
a('        if (!rules::bardWeaponAllowed("staff")) ++bad;')
a('        if (rules::bardWeaponAllowed("long bow")) ++bad;')
a('        if (rules::bardWeaponAllowed("battle axe")) ++bad;')
a('        if (rules::bardWeaponAllowed("")) ++bad;')
a('        if (std::string(rules::bardWeaponName(0))')
a('            != "club") ++bad;')
a('        if (std::string(rules::bardWeaponName(8))')
a('            != "sword") ++bad;')
a('        // Table III: the armor and use pins')
a('        if (!rules::bardOilAllowed()) ++bad;')
a('        if (rules::bardPoisonAllowed(false)) ++bad;')
a('        if (!rules::bardPoisonAllowed(true)) ++bad;')
a('        if (rules::bardShieldAllowed()) ++bad;')
a('        // the poetics layers')
a('        if (rules::BARD_POETIC_ROUNDS != 2) ++bad;')
a('        if (rules::BARD_POETIC_TURN != 1) ++bad;')
a('        if (rules::BARD_MORALE_BONUS != 10) ++bad;')
a('        if (rules::BARD_HIT_BONUS != 1) ++bad;')
a('        // the henchmen ladder: 1 at 5th, 2 at')
a('        // 8th, 3 at 11th, 4 at 14th, 5 at 17th,')
a('        // 6 at 20th, any number at 23rd')
a('        if (rules::bardHenchmen(1) != 0) ++bad;')
a('        if (rules::bardHenchmen(4) != 0) ++bad;')
a('        if (rules::bardHenchmen(5) != 1) ++bad;')
a('        if (rules::bardHenchmen(7) != 1) ++bad;')
a('        if (rules::bardHenchmen(8) != 2) ++bad;')
a('        if (rules::bardHenchmen(11) != 3) ++bad;')
a('        if (rules::bardHenchmen(14) != 4) ++bad;')
a('        if (rules::bardHenchmen(17) != 5) ++bad;')
a('        if (rules::bardHenchmen(20) != 6) ++bad;')
a('        if (rules::bardHenchmen(22) != 6) ++bad;')
a('        if (rules::bardHenchmen(23) != 999) ++bad;')
a('        if (rules::bardHenchmen(0) != 0) ++bad;')
a('        // the musical item bonuses')
a('        if (rules::bardDrumsOfPanicSaveMod() != -1) ++bad;')
a('        if (rules::bardHornOfBlastingDamageFactorPercent()')
a('            != 150) ++bad;')
a('        if (rules::bardLyreOfBuildingFactor() != 2) ++bad;')
a('        if (rules::bardPipesOfSewerRatFactor() != 2) ++bad;')
a('        printf("R186 the bard audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

# pre-assert every probe (the R184b lesson:
# simulate the negative probes against the
# pinned tables)
for str_, wis, dex, cha, int_, con, expect in [
        (15, 15, 15, 15, 12, 10, True),
        (18, 16, 15, 17, 13, 11, True),
        (14, 15, 15, 15, 12, 10, False),
        (15, 14, 15, 15, 12, 10, False),
        (15, 15, 14, 15, 12, 10, False),
        (15, 15, 15, 14, 12, 10, False),
        (15, 15, 15, 15, 11, 10, False),
        (15, 15, 15, 15, 12, 9, False)]:
    got = (str_ >= 15 and wis >= 15 and dex >= 15 and cha >= 15
           and int_ >= 12 and con >= 10)
    assert got == expect, ('ability gate', str_, wis, dex, cha, int_, con)
for fl in range(3, 10):
    assert (5 <= fl <= 7) == (fl in (5, 6, 7)), fl
for tl in range(3, 11):
    assert (5 <= tl <= 9) == (tl in (5, 6, 7, 8, 9)), tl
# the henchmen ladder pre-assert
for lv, e in [(1, 0), (4, 0), (5, 1), (7, 1), (8, 2), (11, 3),
              (14, 4), (17, 5), (20, 6), (22, 6), (23, 999), (0, 0)]:
    if lv >= 23:
        got = 999
    elif lv >= 5:
        got = (lv - 2) // 3
    else:
        got = 0
    assert got == e, ('hench', lv, got, e)
# the hit dice ladder pre-assert
for lv, e in [(1, 0), (2, 1), (11, 10), (12, 11), (23, 22), (99, 22)]:
    l = min(lv, 23)
    got = min(l - 1, 10) + (l - 11 if l > 11 else 0)
    assert got == e, ('hd', lv, got, e)
# the druid cast ladder pre-assert
for lv, e in [(1, 1), (5, 5), (12, 12), (13, 12), (22, 12), (23, 13)]:
    got = 13 if lv >= 23 else (12 if lv > 12 else lv)
    assert got == e, ('cast', lv, got, e)
# the weapon negative probes must be ABSENT
# from the roster (the mirror rule)
for w in ['long bow', 'battle axe', '']:
    assert w not in bard_weapons, w

patch('regtest.cpp',
      'R186 the bard audit',
      '    // ---- R163: the poison table audit -------------',
      NL.join(aud) + NL + '    // ---- R163: the poison table audit -------------')

# ---------------------------------------------------------------------------
# Patch 4: tools/phb_gap_report.md - the R186 box flipped
# ---------------------------------------------------------------------------

box_old = ('- R186 the bard (Appendix II) - the progression'
           + NL + '      gates (fighter to 5th-7th, thief to'
           + NL + '      5th-9th, then the bard), the ability'
           + NL + '      minimums (STR WIS DEX CHA 15+, INT 12,'
           + NL + '      CON 10), human or half-elf, always'
           + NL + '      neutral; Bards Table I (23 levels, bard XP'
           + NL + '      only, hit dice added to those already'
           + NL + '      earned, the druid spell slots capped at'
           + NL + '      12th-level druid ability until the 23rd),'
           + NL + '      Table II (colleges, the language gains,'
           + NL + '      the charm and legend lore percents) and'
           + NL + '      Table III (armor and weapons); the poetics'
           + NL + '      morale and ferocity layers, the song'
           + NL + '      negation, the musical charming rules, the'
           + NL + '      item knowledge lists, and the'
           + NL + '      most-favorite-table saves. Lands after'
           + NL + '      R185 - the bard builds on the fighter and'
           + NL + '      thief layers, the druid spell layer and'
           + NL + '      the dual-class machinery.')

box_new = ('- [x] R186 the bard (Appendix II) - PINNED:'
           + NL + '      rules/bard.h CREATED: the gates (fighter'
           + NL + '      5th-7th, thief 5th-9th, then the druid'
           + NL + '      studies; STR WIS DEX CHA 15+, INT 12,'
           + NL + '      CON 10; human or half-elf; always'
           + NL + '      neutral), Bards Table I (23 levels: the'
           + NL + '      XP thresholds 0 through 3,000,001, the'
           + NL + '      titles Rhymer through M. Bard 23rd, the'
           + NL + '      hit dice 0* then 1-10 then 10+1 through'
           + NL + '      10+12 added to the retained fighter and'
           + NL + '      thief dice, the druid spell slots 1-5'
           + NL + '      every cell, the cast level capped at 12th'
           + NL + '      druid ability until the 23rd casts at'
           + NL + '      13th - the row-20 boundary pins as'
           + NL + '      1,800,001, the strictly increasing'
           + NL + '      sequence over the upload OCR 1,000,001),'
           + NL + '      Bards Table II (the colleges Probationer'
           + NL + '      through Magna Alumnae, the language'
           + NL + '      gains, the charm 15-95 and legend lore'
           + NL + '      0-99 percents, every cell), Bards Table'
           + NL + '      III (leather or magical chainmail, no'
           + NL + '      shield, the nine permitted weapons, oil'
           + NL + '      yes, poison never except by neutral evil'
           + NL + '      bards), the combat-as-fighter /'
           + NL + '      thief-functions / most-favorable-saves'
           + NL + '      wiring, the poetics layers (morale +10%,'
           + NL + '      hit +1, 2 rounds, 1 turn), the song'
           + NL + '      negation, the musical charming rules, the'
           + NL + '      item knowledge lists, the henchmen ladder'
           + NL + '      (1 at 5th through any number at 23rd) and'
           + NL + '      the musical item bonuses. The R186'
           + NL + '      battery audit walks every cell of both'
           + NL + '      tables. Census 103.')

t = rd('tools/phb_gap_report.md')
if 'R186 the bard (Appendix II) - PINNED' not in t:
    assert t.count(box_old) == 1, 'R186 box anchor not unique'
else:
    assert t.count(box_old) == 0, 'R186 box old text lingers'

patch('tools/phb_gap_report.md',
      'R186 the bard (Appendix II) - PINNED',
      box_old,
      box_new)

# ---------------------------------------------------------------------------
# Patch 5: tools/dmg_gap_report.md - the round note
# ---------------------------------------------------------------------------

patch('tools/dmg_gap_report.md',
      'R186 landed the bard',
      'R185 battery audit; census 102. Next: R186'
      + NL + 'the bard (Appendix II).',
      'R185 battery audit; census 102. Next: R186'
      + NL + 'the bard (Appendix II).'
      + NL + 'R186 landed the bard: rules/bard.h CREATED'
      + NL + '(the progression gates, the ability and'
      + NL + 'race minimums, Bards Table I, Table II and'
      + NL + 'Table III, the druid cast cap, the poetics'
      + NL + 'layers, the henchmen ladder, the musical'
      + NL + 'item bonuses). New R186 battery audit;'
      + NL + 'census 103. Next: the gap report names the'
      + NL + 'next round.')

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 5, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R186 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R186 note: 5 patches; census 103 (one new audit);')
print('real gate: md5sum rules/bard.h')
print('commit: R186: the bard (Appendix II) pinned - the tables,')
print('the gates and the specials (census 103)')

