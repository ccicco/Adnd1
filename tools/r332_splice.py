#!/usr/bin/env python3
# R332: the UA barbarian (pp. 18-21)
# pin round - the requirements and
# the wisdom maximum, Barbarians
# Table I, the magic detestation,
# the natural attack progression,
# the saves, the primary, secondary
# and tertiary ability ladders (the
# running-leap formula and the
# detestation award tail are OCR
# holes; the horde and the
# level-actions summary ride their
# own rounds). Pin-era pattern
# (R322). Idempotent; run twice.

import io
import os

NL = '\n'
applied = []
already = []

def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)

def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)

# ---- (a) the seed: the R331 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R331 landed 2026-10-11: commit',
    '  ae61566, census 258, the UA weapon',
    '  specialization prose pin round',
    '  (rules/weaponspec.h): the class gate,',
    '  the slot costs, the melee and',
    '  point-blank reads, the double, the',
    '  table structure with the cleanly',
    '  readable cells (the mangled fraction',
    '  cells read empty - the item stays',
    '  open pending the PDF). GREEN on the',
    '  first paste. Two lessons carried:',
    '  the balance checker must strip',
    '  comments before strings (an unpaired',
    '  inch-mark in a comment swallowed',
    '  real braces); and a seam comment',
    '  naming an identifier trips the',
    '  not-in assert - reword the comment,',
    '  not the assert.',
    ])
s = rd(SD)
if 'R331 landed 2026-10-11' in s:
    already.append('seed: the R331 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R331 record')
s = rd(SD)
assert s.count('R331 landed 2026-10-11') == 1, 'a entry'
assert s.count('R330 landed 2026-10-11') == 1, \
    'a r330 kept'
assert s.count('## Knowledge maintenance') == 1, \
    'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/barbarian.h ----
BH = 'rules/barbarian.h'
if os.path.exists(BH) and 'R332' in rd(BH):
    already.append('barbarian.h: the pins')
else:
    HDR = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/barbarian.h',
    '// The UA barbarian class (pp. 18-21) pins (R332).',
    '//',
    '// Pin-era pattern (R322): pinned data only - no engine site exists.',
    '// The registry rows and the creation-flow gates ride their own rounds.',
    '// The d12 hit die rides the R327 pin (rules/classtables.h); the',
    '// weapon specialization exclusion rides the R331 pin (the gate',
    '// returns false for the barbarian).',
    '//',
    '// OCR holes documented in-header: the forward running-leap formula',
    '// inside the 16-21 foot range is lost (the range survives); the',
    '// detestation award tail after the XP-award clause is garbled (the',
    '// award\'s existence is pinned as a bool, not a formula). The horde',
    '// and the level-actions summary (pp. 20-21) ride their own rounds.',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    '#include "character.h"  // the Ability enum',
    '',
    'namespace rules {',
    '',
    '// ---- the requirements (p. 18) ----',
    '// STR and CON 15, DEX 14; WIS capped at 16; no prime requisite',
    '// (so no XP bonus); no dual-classing.',
    'inline int barbarianMinAbility(int a) {',
    '    switch (a) {',
    '        case ABILITY_STR:',
    '        case ABILITY_CON:',
    '            return 15;',
    '        case ABILITY_DEX:',
    '            return 14;',
    '        default:',
    '            return 0;   // no minimum on the rest',
    '    }',
    '}',
    '',
    'inline int barbarianMaxWisdom()',
    '    { return 16; }',
    '',
    'inline bool barbarianNoPrimeRequisite()',
    '    { return true; }',
    '',
    'inline bool barbarianDualClassBanned()',
    '    { return true; }',
    '',
    'inline bool barbarianHumanOnly()',
    '    { return true; }',
    '',
    '// ---- the AC and hit-point reads (p. 18) ----',
    '// +2 AC steps per DEX point over 14 (non-bulky armor), replacing the',
    '// defensive adjustment; +1 per point in fairly bulky or bulky armor;',
    '// the reaction/attacking adjustment stays. CON grants +2 hp per',
    '// point over 14.',
    'inline int barbarianAcBonusPerDexPoint()',
    '    { return 2; }',
    '',
    'inline int barbarianAcStepSize()',
    '    { return 1; }',
    '',
    'inline int barbarianAcBulkyBonusPerPoint()',
    '    { return 1; }',
    '',
    'inline int barbarianConHpBonusPerPoint()',
    '    { return 2; }',
    '',
    '// ---- the combat reads (p. 18) ----',
    '// d12 hit dice, 15" move, the fighter combat tables, any weapon,',
    '// shield and armor; the hand axe, knife and spear are required.',
    'inline int barbarianHitDice()',
    '    { return 12; }',
    '',
    'inline int barbarianMoveRate()',
    '    { return 15; }',
    '',
    'inline int barbarianRequiredWeaponCount()',
    '    { return 3; }',
    '',
    'inline const char* barbarianRequiredWeaponName(int i) {',
    '    static const char* const k[3] = {',
    '        "Hand Axe", "Knife", "Spear"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    return k[i];',
    '}',
    '',
    '// ---- Barbarians Table I (p. 19) ----',
    '// The XP-to-attain ladder (the R176 lower-bound-minus-one',
    '// convention), 11 levels, 500000 xp per level past the 11th,',
    '// +4 hp per level after the 8th (8+4, 8+8, 8+12).',
    'inline int barbarianXpToAttain(int level) {',
    '    static const int k[11] = {',
    '        0, 6000, 12000, 24000, 48000,',
    '        80000, 150000, 275000, 500000,',
    '        1000000, 1500000',
    '    };',
    '    if (level < 1) return 0;',
    '    if (level > 11) return 1500000;',
    '    return k[level - 1];',
    '}',
    '',
    'inline int barbarianXpPerLevelPast11()',
    '    { return 500000; }',
    '',
    'inline int barbarianHpPerLevelPast8()',
    '    { return 4; }',
    '',
    '// ---- the magic detestation (p. 19) ----',
    '// Barbarians detest magic and its users, refuse to employ any magic',
    '// item, and (the garbled award tail) earn an XP award for destroying',
    '// magic items - the award\'s existence is pinned; its formula is',
    '// OCR-lost. The shaman-cleric exception holds at low level;',
    '// high-level clerical spells grow suspect.',
    'inline bool barbarianDetestsMagic()',
    '    { return true; }',
    '',
    'inline bool barbarianRefusesMagicItems()',
    '    { return true; }',
    '',
    'inline bool barbarianXpAwardForDestroying()',
    '    { return true; }',
    '',
    'inline bool barbarianShamanException()',
    '    { return true; }',
    '',
    '// ---- the natural attack progression (p. 19) ----',
    '// The level at which a given weapon-plus can be struck: +1 at 4th,',
    '// +2 at 6th, +3 at 8th, +4 at 10th, +5 at 12th. No "to hit" or',
    '// damage bonus rides this - only the ability to affect the',
    '// creature.',
    'inline int barbarianStrikeLevel(int plus) {',
    '    if (plus < 1) plus = 1;',
    '    if (plus > 5) plus = 5;',
    '    static const int k[5] = {4, 6, 8, 10, 12};',
    '    return k[plus - 1];',
    '}',
    '',
    'inline int barbarianStrikePlus(int level) {',
    '    if (level < 4) return 0;',
    '    if (level < 6) return 1;',
    '    if (level < 8) return 2;',
    '    if (level < 10) return 3;',
    '    if (level < 12) return 4;',
    '    return 5;',
    '}',
    '',
    'inline bool barbarianStrikeGivesNoBonus()',
    '    { return true; }',
    '',
    '// ---- the saves (p. 19) ----',
    '// +4 versus poison; +3 versus paralyzation, death magic,',
    '// petrification and polymorph; +2 versus rod, staff and wand and',
    '// breath weapon; versus spell, +1 per four levels.',
    'inline int barbarianSaveBonusPoison()',
    '    { return 4; }',
    '',
    'inline int barbarianSaveBonusParalysis()',
    '    { return 3; }',
    '',
    'inline int barbarianSaveBonusRodWandBreath()',
    '    { return 2; }',
    '',
    'inline int barbarianSpellSavePerLevels()',
    '    { return 4; }',
    '',
    'inline int barbarianSpellSaveBonusPerStep()',
    '    { return 1; }',
    '',
    '// ---- the primary abilities (p. 20) ----',
    '// Climb walls as a thief of the same level; hide in familiar',
    '// natural surroundings as a thief 3 levels higher (unfamiliar:',
    '// the same level); surprise 3 in 6 (4 in 6 familiar); surprised',
    '// 10% (5% familiar); the rear attack detected and countered 5% per',
    '// level, else it becomes a normal attack; the leaps - 10 feet',
    '// forward, 3 backward, 3 upward from a stand; the forward running',
    '// leap spans 16-21 feet (the formula inside the range is OCR-lost);',
    '// the springing upward leap spans 4-7 feet; detect illusion 5% per',
    '// level (never over 75%) after one round of concentration; detect',
    '// magic 25% base +5% per level, capped at 90%, illusion excluded,',
    '// type never revealed; leadership: the level added to charisma',
    '// against other barbarians (comeliness unaffected); familiar',
    '// terrain demands about a month of exposure.',
    'inline int barbarianClimbAsThiefLevel(int level)',
    '    { return level; }',
    '',
    'inline int barbarianHideBonusLevels()',
    '    { return 3; }',
    '',
    'inline int barbarianSurpriseFamiliar()',
    '    { return 4; }',
    '',
    'inline int barbarianSurpriseUnfamiliar()',
    '    { return 3; }',
    '',
    'inline int barbarianSurprisedFamiliar()',
    '    { return 5; }',
    '',
    'inline int barbarianSurprisedUnfamiliar()',
    '    { return 10; }',
    '',
    'inline int barbarianBackProtectPercent(int level)',
    '    { return 5 * level; }',
    '',
    'inline int barbarianLeapStandingForward()',
    '    { return 10; }',
    '',
    'inline int barbarianLeapStandingBackward()',
    '    { return 3; }',
    '',
    'inline int barbarianLeapStandingUpward()',
    '    { return 3; }',
    '',
    'inline int barbarianLeapRunningLow()',
    '    { return 16; }',
    '',
    'inline int barbarianLeapRunningHigh()',
    '    { return 21; }',
    '',
    'inline int barbarianSpringUpwardLow()',
    '    { return 4; }',
    '',
    'inline int barbarianSpringUpwardHigh()',
    '    { return 7; }',
    '',
    'inline int barbarianDetectIllusionPercent(int level) {',
    '    int p = 5 * level;',
    '    return p > 75 ? 75 : p;',
    '}',
    '',
    'inline int barbarianDetectIllusionCap()',
    '    { return 75; }',
    '',
    'inline int barbarianDetectMagicBase()',
    '    { return 25; }',
    '',
    'inline int barbarianDetectMagicPerLevel()',
    '    { return 5; }',
    '',
    'inline int barbarianDetectMagicCap()',
    '    { return 90; }',
    '',
    'inline int barbarianDetectRounds()',
    '    { return 1; }',
    '',
    'inline bool barbarianLeadershipOnBarbarians()',
    '    { return true; }',
    '',
    '// ---- the secondary abilities (p. 20) ----',
    '// Locale adaptation after about a month; first aid: the bound',
    '// character regains 1 hit point immediately, 2 per day resting,',
    '// 1 per day even active; the same first aid restores 1 hit point',
    '// immediately to other characters; a 10% chance of curing natural',
    '// poison or illness, rising to 50 plus the victim\'s CON when the',
    '// poison or disease is known; outdoor craft as a 3rd-level druid;',
    '// tracking as a ranger of the same level, outdoors only.',
    'inline int barbarianLocaleAdaptWeeks()',
    '    { return 4; }',
    '',
    'inline int barbarianFirstAidHp()',
    '    { return 1; }',
    '',
    'inline int barbarianFirstAidRestPerDay()',
    '    { return 2; }',
    '',
    'inline int barbarianFirstAidActivePerDay()',
    '    { return 1; }',
    '',
    'inline int barbarianFirstAidOtherHp()',
    '    { return 1; }',
    '',
    'inline int barbarianFirstAidCurePercent()',
    '    { return 10; }',
    '',
    'inline int barbarianFirstAidCureKnownBase()',
    '    { return 50; }',
    '',
    'inline int barbarianFirstAidCureKnownCon()',
    '    { return 1; }',
    '',
    'inline int barbarianOutdoorCraftDruidLevel()',
    '    { return 3; }',
    '',
    'inline bool barbarianTracksAsRanger()',
    '    { return true; }',
    '',
    '// ---- the tertiary skills (p. 20) ----',
    '// One or more of seven, per the locale and the culture: animal',
    '// handling (usually dogs), horsemanship (combat use), long-distance',
    '// signaling (drums, smoke, mirror flashes), running (double move',
    '// for three full days), small craft paddled and rowed, sound',
    '// imitation, snare building (deadfalls, pits and traps for large',
    '// and very large animals).',
    'inline int barbarianTertiaryCount()',
    '    { return 7; }',
    '',
    'inline const char* barbarianTertiaryName(int i) {',
    '    static const char* const k[7] = {',
    '        "Animal Handling", "Horsemanship",',
    '        "Long-Distance Signaling", "Running",',
    '        "Small Craft (Paddled and Rowed)",',
    '        "Sound Imitation", "Snare Building"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 6) i = 6;',
    '    return k[i];',
    '}',
    '',
    '}   // namespace rules',
    ])
    clean(HDR, 78)
    wr(BH, HDR)
    applied.append('barbarian.h: the pins')
s = rd(BH)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('barbarianMinAbility') == 1, 'b min'
assert s.count('barbarianXpToAttain') == 1, 'b xp'
assert s.count('barbarianTertiaryName') == 1, 'b tert'
assert s.count('barbarianStrikeLevel') == 1, 'b strike'
assert s.count('barbarianDetectMagicCap') == 1, 'b cap'
assert s.count('inline') == 61, 'b inline count'
assert s.count('#include "character.h"') == 1, \
    'b parent inc'
assert 'uaClassHitDie' not in s, 'b no dice ref'
assert 'weaponSpecClassAllowed' not in s, \
    'b no gate ref'
assert s.count('R332') == 1, 'b round tag'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'CLOSED R332' in s:
    already.append('gap report: the close')
else:
    FIRST_OLD = ('- [ ] **The barbarian**'
                ' (pp. 18-21) -')
    TAIL_OLD = NL.join([
    '      sound imitation, snare'
    ' building).',
    ])
    assert s.count(FIRST_OLD) == 1, 'c first'
    assert s.count(TAIL_OLD) == 1, 'c tail'
    FIRST_NEW = ('- [x] **The barbarian**'
                ' (pp. 18-21) -')
    CLOSE = NL.join([
    '      - CLOSED R332: the pin round',
    '      (rules/barbarian.h) - the',
    '      requirements and the wisdom',
    '      maximum, Barbarians Table I, the',
    '      magic detestation, the natural',
    '      attack progression, the saves,',
    '      the primary/secondary/tertiary',
    '      ability ladders. The',
    '      running-leap formula and the',
    '      detestation award tail are OCR',
    '      holes (documented in-header).',
    '      The horde and the level-actions',
    '      summary ride their own rounds.',
    ])
    clean(CLOSE, 57)
    s = s.replace(FIRST_OLD, FIRST_NEW)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + CLOSE)
    wr(GP, s)
    applied.append('gap report: the close')
s = rd(GP)
assert s.count('- [x] **The barbarian**') == 1, \
    'c flipped'
assert s.count('CLOSED R332') == 1, 'c closed'
assert s.count('R331: the prose pinned') == 1, \
    'c r331 note kept'
assert s.count('CLOSED R330') == 1, 'c r330 kept'
assert s.count('CLOSED R329') == 1, 'c r329 kept'
assert s.count('CLOSED R328') == 1, 'c r328 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R332 barbarian pin audit' in s:
    already.append('regtest.cpp: the R332 audit')
else:
    INC_ANCH = ('#include "rules/weaponspec.h"'
                '  // R331: the UA weapon spec')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/barbarian.h"'
    '  // R332: the UA barbarian',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
    '    // ---- R332: the barbarian pin audit ----',
    '    // The UA barbarian (pp. 18-21) - the pin-era pattern: the',
    '    // requirements, the AC/CON reads, Barbarians Table I, the',
    '    // magic detestation, the natural attack progression, the',
    '    // saves, the primary/secondary/tertiary ability ladders',
    '    // (the running-leap formula and the award tail are OCR',
    '    // holes - documented in the header). The R327 hit-die seam',
    '    // and the R331 spec-gate seam cross-checked.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the requirements',
    '        {',
    '            if (barbarianMinAbility(',
    '                ABILITY_STR) != 15) ++bad;',
    '            if (barbarianMinAbility(',
    '                ABILITY_CON) != 15) ++bad;',
    '            if (barbarianMinAbility(',
    '                ABILITY_DEX) != 14) ++bad;',
    '            if (barbarianMinAbility(',
    '                ABILITY_INT) != 0) ++bad;',
    '            if (barbarianMaxWisdom() != 16)',
    '                ++bad;',
    '            if (!barbarianNoPrimeRequisite())',
    '                ++bad;',
    '            if (!barbarianDualClassBanned())',
    '                ++bad;',
    '            if (!barbarianHumanOnly()) ++bad;',
    '        }',
    '        // U2: the AC and CON reads',
    '        {',
    '            if (barbarianAcBonusPerDexPoint()',
    '                != 2) ++bad;',
    '            if (barbarianAcStepSize() != 1)',
    '                ++bad;',
    '            if (barbarianAcBulkyBonusPerPoint()',
    '                != 1) ++bad;',
    '            if (barbarianConHpBonusPerPoint()',
    '                != 2) ++bad;',
    '        }',
    '        // U3: the combat reads',
    '        {',
    '            if (barbarianHitDice() != 12)',
    '                ++bad;',
    '            if (barbarianMoveRate() != 15)',
    '                ++bad;',
    '            if (barbarianRequiredWeaponCount()',
    '                != 3) ++bad;',
    '            if (strcmp(',
    '                barbarianRequiredWeaponName(0),',
    '                "Hand Axe") != 0) ++bad;',
    '            if (strcmp(',
    '                barbarianRequiredWeaponName(1),',
    '                "Knife") != 0) ++bad;',
    '            if (strcmp(',
    '                barbarianRequiredWeaponName(2),',
    '                "Spear") != 0) ++bad;',
    '        }',
    '        // U4: Barbarians Table I',
    '        {',
    '            static const int xp[11] = {',
    '                0, 6000, 12000, 24000, 48000,',
    '                80000, 150000, 275000, 500000,',
    '                1000000, 1500000',
    '            };',
    '            for (int L = 1; L <= 11; ++L)',
    '                if (barbarianXpToAttain(L)',
    '                    != xp[L - 1]) ++bad;',
    '            if (barbarianXpPerLevelPast11()',
    '                != 500000) ++bad;',
    '            if (barbarianHpPerLevelPast8()',
    '                != 4) ++bad;',
    '            // the R176 convention: the row',
    '            // reads attained at its floor',
    '            if (barbarianXpToAttain(0) != 0)',
    '                ++bad;',
    '            if (barbarianXpToAttain(12)',
    '                != 1500000) ++bad;',
    '        }',
    '        // U5: the magic detestation',
    '        {',
    '            if (!barbarianDetestsMagic()) ++bad;',
    '            if (!barbarianRefusesMagicItems())',
    '                ++bad;',
    '            if (!barbarianXpAwardForDestroying())',
    '                ++bad;',
    '            if (!barbarianShamanException())',
    '                ++bad;',
    '        }',
    '        // U6: the natural attack progression',
    '        {',
    '            static const int lvl[5] = {',
    '                4, 6, 8, 10, 12',
    '            };',
    '            for (int p = 1; p <= 5; ++p) {',
    '                if (barbarianStrikeLevel(p)',
    '                    != lvl[p - 1]) ++bad;',
    '                if (barbarianStrikePlus(',
    '                    lvl[p - 1]) != p) ++bad;',
    '            }',
    '            if (barbarianStrikePlus(3) != 0)',
    '                ++bad;',
    '            if (!barbarianStrikeGivesNoBonus())',
    '                ++bad;',
    '        }',
    '        // U7: the saves',
    '        {',
    '            if (barbarianSaveBonusPoison()',
    '                != 4) ++bad;',
    '            if (barbarianSaveBonusParalysis()',
    '                != 3) ++bad;',
    '            if (barbarianSaveBonusRodWandBreath()',
    '                != 2) ++bad;',
    '            if (barbarianSpellSavePerLevels()',
    '                != 4) ++bad;',
    '            if (barbarianSpellSaveBonusPerStep()',
    '                != 1) ++bad;',
    '        }',
    '        // U8: the primary abilities',
    '        {',
    '            if (barbarianClimbAsThiefLevel(5)',
    '                != 5) ++bad;',
    '            if (barbarianHideBonusLevels()',
    '                != 3) ++bad;',
    '            if (barbarianSurpriseFamiliar()',
    '                != 4) ++bad;',
    '            if (barbarianSurpriseUnfamiliar()',
    '                != 3) ++bad;',
    '            if (barbarianSurprisedFamiliar()',
    '                != 5) ++bad;',
    '            if (barbarianSurprisedUnfamiliar()',
    '                != 10) ++bad;',
    '            if (barbarianBackProtectPercent(1)',
    '                != 5) ++bad;',
    '            if (barbarianBackProtectPercent(2)',
    '                != 10) ++bad;',
    '            if (barbarianLeapStandingForward()',
    '                != 10) ++bad;',
    '            if (barbarianLeapStandingBackward()',
    '                != 3) ++bad;',
    '            if (barbarianLeapStandingUpward()',
    '                != 3) ++bad;',
    '            if (barbarianLeapRunningLow()',
    '                != 16) ++bad;',
    '            if (barbarianLeapRunningHigh()',
    '                != 21) ++bad;',
    '            if (barbarianSpringUpwardLow()',
    '                != 4) ++bad;',
    '            if (barbarianSpringUpwardHigh()',
    '                != 7) ++bad;',
    '            if (barbarianDetectIllusionPercent(',
    '                3) != 15) ++bad;',
    '            if (barbarianDetectIllusionPercent(',
    '                20) != 75) ++bad;',
    '            if (barbarianDetectIllusionCap()',
    '                != 75) ++bad;',
    '            if (barbarianDetectMagicBase()',
    '                != 25) ++bad;',
    '            if (barbarianDetectMagicPerLevel()',
    '                != 5) ++bad;',
    '            if (barbarianDetectMagicCap()',
    '                != 90) ++bad;',
    '            if (barbarianDetectRounds() != 1)',
    '                ++bad;',
    '            if (!barbarianLeadershipOnBarbarians())',
    '                ++bad;',
    '        }',
    '        // U9: the secondary abilities',
    '        {',
    '            if (barbarianLocaleAdaptWeeks()',
    '                != 4) ++bad;',
    '            if (barbarianFirstAidHp() != 1)',
    '                ++bad;',
    '            if (barbarianFirstAidRestPerDay()',
    '                != 2) ++bad;',
    '            if (barbarianFirstAidActivePerDay()',
    '                != 1) ++bad;',
    '            if (barbarianFirstAidOtherHp()',
    '                != 1) ++bad;',
    '            if (barbarianFirstAidCurePercent()',
    '                != 10) ++bad;',
    '            if (barbarianFirstAidCureKnownBase()',
    '                != 50) ++bad;',
    '            if (barbarianFirstAidCureKnownCon()',
    '                != 1) ++bad;',
    '            if (barbarianOutdoorCraftDruidLevel()',
    '                != 3) ++bad;',
    '            if (!barbarianTracksAsRanger())',
    '                ++bad;',
    '        }',
    '        // U10: the tertiary skills',
    '        {',
    '            if (barbarianTertiaryCount() != 7)',
    '                ++bad;',
    '            if (strcmp(',
    '                barbarianTertiaryName(0),',
    '                "Animal Handling") != 0) ++bad;',
    '            if (strcmp(',
    '                barbarianTertiaryName(2),',
    '                "Long-Distance Signaling") != 0)',
    '                ++bad;',
    '            if (strcmp(',
    '                barbarianTertiaryName(4),',
    '                "Small Craft (Paddled and"',
    '                " Rowed)") != 0) ++bad;',
    '            if (strcmp(',
    '                barbarianTertiaryName(6),',
    '                "Snare Building") != 0) ++bad;',
    '        }',
    '        // U11: the R327 and R331 seams',
    '        {',
    '            if (uaClassHitDie(',
    '                UACLASS_BARBARIAN) != 12) ++bad;',
    '            if (weaponSpecClassAllowed(',
    '                UACLASS_BARBARIAN)) ++bad;',
    '        }',
    '        printf("R332 barbarian pin audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    ])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH, AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R332 audit')
s = rd(RT)
assert s.count(
    'R332 barbarian pin audit: bad ') == 1, \
    'd audit line'
assert s.count('audit: bad ') == 259, 'd census 259'
assert s.count(
    'R331 weapon spec prose pin audit: bad ') == 1, \
    'd r331 kept'
assert s.count('R330 druid hierophant pin audit: bad ')\
    == 1, 'd r330 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count('#include "rules/barbarian.h"') == 1, \
    'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R332 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R332 note: the UA barbarian pin')
print('round - the requirements, the AC and')
print('CON reads, Table I, the magic')
print('detestation, the strike ladder, the')
print('saves, the primary, secondary and')
print('tertiary abilities (the horde and')
print('the level-actions summary ride')
print('their own rounds); the census'
      ' 258 -> 259')
print('commit: R332: the UA barbarian pin')
print('round (census 259)')

