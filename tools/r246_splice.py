#!/usr/bin/env python3
# R246 splice: the III.D wands explanation prose pins, part 1.
#
# DMG pp.143-144, upload lines ~10786-10826 - the third
# prose round of the EXPLANATIONS AND DESCRIPTIONS
# section, part 1 of 3 for the wands: the section
# conventions (wands perform at 6th level of experience;
# at DM option 1% of all wands are trapped to backfire)
# and the FIRST FIVE wands - Conjuration (11 recognized
# conjuration/summoning spells counted from print;
# monster summoning max 6 charges at 1 per level, 5
# segments; the curtain of blackness 600 square feet at
# 2 charges; prismatic sphere 1 charge per color; each
# function 5 segments, 1 function per round),
# Enemy Detection (6" sphere, 1 charge per turn), Fear
# (cone 6" long by 2" base, 1 segment flash, flee 6
# rounds, 1 charge per use, once per round), Fire (4
# functions: burning hands 10 ft wide 12 ft long 6 hp,
# 1 segment, 1 charge; pyrotechnics 2 segments 1
# charge; fireball range 16", 2 segments, 2 charges, 6
# dice with 1s counted as 2s = 12-36 hp; wall of fire
# 12 square", 6 rounds, 8-18 hp touched (2d6+6), 2-8
# within 1", 1-4 within 2", ring circle 2.25 inches
# diameter - pinned as 9 quarter-inches; once per
# round), and Frost (3 functions: ice storm 6" distant,
# 1 segment, 1 charge; wall of ice 6 inches thick, 6"
# square area, 2 segments, 1 charge; cone of cold 6"
# long 2" terminal diameter, 2 segments, c. -100 F, 6
# dice 12-36, 2 charges; once per round). All five are
# rechargeable. The five wands are the engine III.D
# table wand rows 1-5 (dm/treasure.cpp kRods, bands
# 34-47); the illumination rows begin at band 48 -
# cross-checked against the R224 rodswands.h bands in
# the audit.
# Patches: 4 (new rules/wandsprose.h, the regtest
# include, the audit block, the dmg-gap-report log
# entry). Census 164 -> 165.
#
# commit: R246: the III.D wands explanation prose pins pinned - DMG pp.143-144, the conventions and the first five wands (census 165)

import sys

WD   = 'rules/wandsprose.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 164 and t.count('audit: bad ') != 165:
    print('R246 FAIL: regtest census is neither 164 nor 165')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/wandsprose.h',
    '// R246: the III.D wands explanation prose',
    '// pins, part 1 (DMG pp.143-144) - the',
    '// section conventions and the FIRST FIVE',
    '// wands of the RODS, et al. explanation',
    '// prose (upload lines ~10786-10826):',
    '//   - the conventions: wands perform at',
    '//     6th level of experience; at DM',
    '//     option 1% of all wands are trapped',
    '//     to backfire.',
    '//   - Wand of Conjuration: 11 recognized',
    '//     conjuration/summoning spells (unseen',
    '//     servant, monster summoning, conjure',
    '//     elemental, death spell, invisible',
    '//     stalker, limited wish, symbol, maze,',
    '//     gate, prismatic sphere, wish);',
    '//     monster summoning max 6 charges at 1',
    '//     per level, 5 segments; curtain of',
    '//     blackness 600 sq ft at 2 charges;',
    '//     prismatic sphere 1 charge per color;',
    '//     each function 5 segments, 1 per round.',
    '//   - Wand of Enemy Detection: 6" sphere,',
    '//     1 charge per turn.',
    '//   - Wand of Fear: cone 6" long by 2" base,',
    '//     1 segment flash, flee 6 rounds,',
    '//     1 charge per use, once per round.',
    '//   - Wand of Fire, 4 functions: burning',
    '//     hands 10 ft wide 12 ft long 6 hp,',
    '//     1 segment, 1 charge; pyrotechnics',
    '//     2 segments 1 charge; fireball range',
    '//     16", 2 segments, 2 charges, 6 dice',
    '//     with 1s counted as 2s = 12-36 hp;',
    '//     wall of fire 12 square", 6 rounds,',
    '//     8-18 hp touched (2d6 + 6), 2-8',
    '//     within 1", 1-4 within 2", ring',
    '//     circle 2.25 inch diameter - pinned',
    '//     as 9 quarter-inches; once per round.',
    '//   - Wand of Frost, 3 functions: ice',
    '//     storm 6" distant, 1 segment,',
    '//     1 charge; wall of ice 6 inches thick,',
    '//     6" square area, 2 segments,',
    '//     1 charge; cone of cold 6" long, 2"',
    '//     terminal diameter, 2 segments,',
    '//     c. -100 F, 6 dice 12-36, 2 charges;',
    '//     once per round.',
    '// All five wands are rechargeable. The five',
    '// wands are the engine III.D table wand rows',
    '// 1-5 (dm/treasure.cpp kRods, bands 34-47);',
    '// the illumination rows begin at band 48.',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int wdLevelOfUse() {',
    '    // wands perform at 6th level of experience',
    '    return 6;',
    '}',
    '',
    'inline int wdBackfirePercent() {',
    '    // at DM option 1% of all wands are',
    '    // trapped to backfire',
    '    return 1;',
    '}',
    '',
    'inline int wdConjRecognizedCount() {',
    '    // the conjuration/summoning spells the',
    '    // wielder recognizes on grasping',
    '    return 11;',
    '}',
    '',
    'inline int wdConjSummonMaxCharges() {',
    '    // monster summoning: max 6 charges,',
    '    // 1 per level',
    '    return 6;',
    '}',
    '',
    'inline int wdConjSummonSegments() {',
    '    // the monster summoning takes 5 segments',
    '    return 5;',
    '}',
    '',
    'inline int wdConjCurtainSqFeet() {',
    '    // the curtain of blackness: 600 sq ft',
    '    return 600;',
    '}',
    '',
    'inline int wdConjCurtainCharges() {',
    '    // the curtain costs 2 charges',
    '    return 2;',
    '}',
    '',
    'inline int wdConjPrismaticChargesPerColor() {',
    '    // the prismatic sphere: 1 charge per',
    '    // color, red to violet',
    '    return 1;',
    '}',
    '',
    'inline int wdConjFunctionSegments() {',
    '    // each function takes 5 segments',
    '    return 5;',
    '}',
    '',
    'inline int wdConjFunctionsPerRound() {',
    '    // only 1 function per round',
    '    return 1;',
    '}',
    '',
    'inline int wdConjRechargeable() {',
    '    // it may be recharged',
    '    return 1;',
    '}',
    '',
    'inline int wdEnemyRadiusInches() {',
    '    // Wand of Enemy Detection: 6" sphere',
    '    return 6;',
    '}',
    '',
    'inline int wdEnemyChargesPerTurn() {',
    '    // 1 charge to operate for 1 turn',
    '    return 1;',
    '}',
    '',
    'inline int wdEnemyRechargeable() {',
    '    // it can be recharged',
    '    return 1;',
    '}',
    '',
    'inline int wdFearConeLengthInches() {',
    '    // Wand of Fear: cone 6" long',
    '    return 6;',
    '}',
    '',
    'inline int wdFearConeWidthInches() {',
    '    // by 2" in base diameter',
    '    return 2;',
    '}',
    '',
    'inline int wdFearSegments() {',
    '    // flashes on in 1 segment',
    '    return 1;',
    '}',
    '',
    'inline int wdFearFleeRounds() {',
    '    // flee at fastest speed for 6 rounds',
    '    return 6;',
    '}',
    '',
    'inline int wdFearChargesPerUse() {',
    '    // each usage costs 1 charge',
    '    return 1;',
    '}',
    '',
    'inline int wdFearUsesPerRound() {',
    '    // it can operate but once per round',
    '    return 1;',
    '}',
    '',
    'inline int wdFearRechargeable() {',
    '    // it can be recharged',
    '    return 1;',
    '}',
    '',
    'inline int wdFireFunctionCount() {',
    '    // Wand of Fire: 4 separate functions',
    '    return 4;',
    '}',
    '',
    'inline int wdFireHandsWidthFeet() {',
    '    // burning hands: fan 10 ft wide',
    '    return 10;',
    '}',
    '',
    'inline int wdFireHandsLengthFeet() {',
    '    // and 12 ft long',
    '    return 12;',
    '}',
    '',
    'inline int wdFireHandsHp() {',
    '    // each creature touched takes 6 hp',
    '    return 6;',
    '}',
    '',
    'inline int wdFireHandsSegments() {',
    '    // the plane appears in 1 segment',
    '    return 1;',
    '}',
    '',
    'inline int wdFireHandsCharges() {',
    '    // it expends 1 charge',
    '    return 1;',
    '}',
    '',
    'inline int wdFirePyroSegments() {',
    '    // pyrotechnics: 2 segments to activate',
    '    return 2;',
    '}',
    '',
    'inline int wdFirePyroCharges() {',
    '    // it expends 1 charge',
    '    return 1;',
    '}',
    '',
    'inline int wdFireBallRangeInches() {',
    '    // fireball: maximum range 16"',
    '    return 16;',
    '}',
    '',
    'inline int wdFireBallSegments() {',
    '    // the function takes 2 segments',
    '    return 2;',
    '}',
    '',
    'inline int wdFireBallCharges() {',
    '    // it expends 2 charges',
    '    return 2;',
    '}',
    '',
    'inline int wdFireBallDice() {',
    '    // 6 hit dice of damage',
    '    return 6;',
    '}',
    '',
    'inline int wdFireBallFaces() {',
    '    // d6, with all 1s counted as 2s',
    '    return 6;',
    '}',
    '',
    'inline int wdFireBallDamageLo() {',
    '    // the burst does 12-36 hit points',
    '    return 12;',
    '}',
    '',
    'inline int wdFireBallDamageHi() {',
    '    return 36;',
    '}',
    '',
    'inline int wdFireWallAreaSqInches() {',
    '    // wall of fire: a sheet of 12 square"',
    '    return 12;',
    '}',
    '',
    'inline int wdFireWallRounds() {',
    '    // it lasts for 6 rounds',
    '    return 6;',
    '}',
    '',
    'inline int wdFireWallTouchLo() {',
    '    // touched: 8-18 hp (2d6 + 6)',
    '    return 8;',
    '}',
    '',
    'inline int wdFireWallTouchHi() {',
    '    return 18;',
    '}',
    '',
    'inline int wdFireWallNearLo() {',
    '    // within 1": 2-8 hp',
    '    return 2;',
    '}',
    '',
    'inline int wdFireWallNearHi() {',
    '    return 8;',
    '}',
    '',
    'inline int wdFireWallFarLo() {',
    '    // within 2": 1-4 hp',
    '    return 1;',
    '}',
    '',
    'inline int wdFireWallFarHi() {',
    '    return 4;',
    '}',
    '',
    'inline int wdFireWallRingQuarterInches() {',
    '    // the ring-shape circle is only 2.25 inches',
    '    // in diameter - pinned as 9 quarter-inches',
    '    return 9;',
    '}',
    '',
    'inline int wdFireUsesPerRound() {',
    '    // once per round',
    '    return 1;',
    '}',
    '',
    'inline int wdFireRechargeable() {',
    '    // it can be recharged',
    '    return 1;',
    '}',
    '',
    'inline int wdFrostFunctionCount() {',
    '    // Wand of Frost: 3 functions',
    '    return 3;',
    '}',
    '',
    'inline int wdFrostStormRangeInches() {',
    '    // ice storm: up to 6" distant',
    '    return 6;',
    '}',
    '',
    'inline int wdFrostStormSegments() {',
    '    // in 1 segment',
    '    return 1;',
    '}',
    '',
    'inline int wdFrostStormCharges() {',
    '    // requires 1 charge',
    '    return 1;',
    '}',
    '',
    'inline int wdFrostWallThicknessInches() {',
    '    // wall of ice: 6 inches thick',
    '    return 6;',
    '}',
    '',
    'inline int wdFrostWallAreaInches() {',
    '    // square area equal to 6"',
    '    return 6;',
    '}',
    '',
    'inline int wdFrostWallSegments() {',
    '    // in 2 segments',
    '    return 2;',
    '}',
    '',
    'inline int wdFrostWallCharges() {',
    '    // at a cost of 1 charge',
    '    return 1;',
    '}',
    '',
    'inline int wdFrostConeLengthInches() {',
    '    // cone of cold: 6" length',
    '    return 6;',
    '}',
    '',
    'inline int wdFrostConeWidthInches() {',
    '    // and 2" terminal diameter',
    '    return 2;',
    '}',
    '',
    'inline int wdFrostConeSegments() {',
    '    // the cold comes forth in 2 segments',
    '    return 2;',
    '}',
    '',
    'inline int wdFrostConeTempF() {',
    '    // the temperature is c. -100 F',
    '    return -100;',
    '}',
    '',
    'inline int wdFrostConeDice() {',
    '    // damage is 6 hit dice',
    '    return 6;',
    '}',
    '',
    'inline int wdFrostConeDamageLo() {',
    '    // 6d6, treating 1s as 2s: 12-36',
    '    return 12;',
    '}',
    '',
    'inline int wdFrostConeDamageHi() {',
    '    return 36;',
    '}',
    '',
    'inline int wdFrostConeCharges() {',
    '    // the cost is 2 charges per use',
    '    return 2;',
    '}',
    '',
    'inline int wdFrostUsesPerRound() {',
    '    // once per round',
    '    return 1;',
    '}',
    '',
    'inline int wdFrostRechargeable() {',
    '    // it may be recharged',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
    '',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/stavesprose.h"  // R245: pp.142-143 the III.D staves prose pins',
]
inc_new = [
    '#include "rules/stavesprose.h"  // R245: pp.142-143 the III.D staves prose pins',
    '#include "rules/wandsprose.h"  // R246: pp.143-144 the III.D wands prose pins',
]

# ---- the regtest audit block ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R246: the III.D wands explanation prose pins audit ----',
    '    // DMG pp.143-144: the conventions and the',
    '    // first five wands of the RODS, et al.',
    '    // explanation prose.',
    '    {',
    '        int bad = 0;',
    '        // the conventions: 6th level, the 1%',
    '        // backfire trap',
    '        if (rules::wdLevelOfUse() != 6 ||',
    '            rules::wdBackfirePercent() != 1) ++bad;',
    '        // the five wands are the engine III.D',
    '        // table wand rows 1-5 - bands 34-47,',
    '        // illumination from 48 (the R224 pins)',
    '        if (rules::rswRowLo(14) != 34 ||',
    '            rules::rswRowHi(18) != 47 ||',
    '            rules::rswRowLo(19) != 48) ++bad;',
    '        // Wand of Conjuration',
    '        if (rules::wdConjRecognizedCount() != 11 ||',
    '            rules::wdConjSummonMaxCharges() != 6 ||',
    '            rules::wdConjSummonSegments() != 5 ||',
    '            rules::wdConjCurtainSqFeet() != 600 ||',
    '            rules::wdConjCurtainCharges() != 2 ||',
    '            rules::wdConjPrismaticChargesPerColor() != 1 ||',
    '            rules::wdConjFunctionSegments() != 5 ||',
    '            rules::wdConjFunctionsPerRound() != 1 ||',
    '            rules::wdConjRechargeable() != 1) ++bad;',
    '        // Wand of Enemy Detection',
    '        if (rules::wdEnemyRadiusInches() != 6 ||',
    '            rules::wdEnemyChargesPerTurn() != 1 ||',
    '            rules::wdEnemyRechargeable() != 1) ++bad;',
    '        // Wand of Fear',
    '        if (rules::wdFearConeLengthInches() != 6 ||',
    '            rules::wdFearConeWidthInches() != 2 ||',
    '            rules::wdFearSegments() != 1 ||',
    '            rules::wdFearFleeRounds() != 6 ||',
    '            rules::wdFearChargesPerUse() != 1 ||',
    '            rules::wdFearUsesPerRound() != 1 ||',
    '            rules::wdFearRechargeable() != 1) ++bad;',
    '        // Wand of Fire - the four functions',
    '        if (rules::wdFireFunctionCount() != 4 ||',
    '            rules::wdFireHandsWidthFeet() != 10 ||',
    '            rules::wdFireHandsLengthFeet() != 12 ||',
    '            rules::wdFireHandsHp() != 6 ||',
    '            rules::wdFireHandsSegments() != 1 ||',
    '            rules::wdFireHandsCharges() != 1 ||',
    '            rules::wdFirePyroSegments() != 2 ||',
    '            rules::wdFirePyroCharges() != 1 ||',
    '            rules::wdFireBallRangeInches() != 16 ||',
    '            rules::wdFireBallSegments() != 2 ||',
    '            rules::wdFireBallCharges() != 2 ||',
    '            rules::wdFireBallDice() != 6 ||',
    '            rules::wdFireBallFaces() != 6 ||',
    '            rules::wdFireBallDamageLo() != 12 ||',
    '            rules::wdFireBallDamageHi() != 36) ++bad;',
    '        // the wall of fire bands and the ring',
    '        if (rules::wdFireWallAreaSqInches() != 12 ||',
    '            rules::wdFireWallRounds() != 6 ||',
    '            rules::wdFireWallTouchLo() != 8 ||',
    '            rules::wdFireWallTouchHi() != 18 ||',
    '            rules::wdFireWallNearLo() != 2 ||',
    '            rules::wdFireWallNearHi() != 8 ||',
    '            rules::wdFireWallFarLo() != 1 ||',
    '            rules::wdFireWallFarHi() != 4 ||',
    '            rules::wdFireWallRingQuarterInches() != 9 ||',
    '            rules::wdFireUsesPerRound() != 1 ||',
    '            rules::wdFireRechargeable() != 1) ++bad;',
    '        // Wand of Frost - the three functions',
    '        if (rules::wdFrostFunctionCount() != 3 ||',
    '            rules::wdFrostStormRangeInches() != 6 ||',
    '            rules::wdFrostStormSegments() != 1 ||',
    '            rules::wdFrostStormCharges() != 1 ||',
    '            rules::wdFrostWallThicknessInches() != 6 ||',
    '            rules::wdFrostWallAreaInches() != 6 ||',
    '            rules::wdFrostWallSegments() != 2 ||',
    '            rules::wdFrostWallCharges() != 1 ||',
    '            rules::wdFrostConeLengthInches() != 6 ||',
    '            rules::wdFrostConeWidthInches() != 2 ||',
    '            rules::wdFrostConeSegments() != 2 ||',
    '            rules::wdFrostConeTempF() != -100 ||',
    '            rules::wdFrostConeDice() != 6 ||',
    '            rules::wdFrostConeDamageLo() != 12 ||',
    '            rules::wdFrostConeDamageHi() != 36 ||',
    '            rules::wdFrostConeCharges() != 2 ||',
    '            rules::wdFrostUsesPerRound() != 1 ||',
    '            rules::wdFrostRechargeable() != 1) ++bad;',
    '        printf("R246 wands prose pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg gap report log entry ----
gap_old = [
    'misc magic item explanations',
    '(~10949+).',
]
gap_new = [
    'misc magic item explanations',
    '(~10949+).',
    '',
    'R246 landed the III.D wands',
    'explanation prose pins, part 1 of 3',
    '(DMG pp.143-144, upload lines',
    '~10786-10826). rules/wandsprose.h',
    '(the grenade.h pattern, wd prefix,',
    '65 scalar accessors - no arrays',
    'this round): the section',
    'conventions (wands perform at 6th',
    'level of experience; at DM option',
    '1% of all wands are trapped to',
    'backfire) and the FIRST FIVE',
    'wands - Conjuration (11 recognized',
    'conjuration/summoning spells counted',
    'from print; monster summoning max',
    '6 charges at 1 per level, 5',
    'segments; curtain of blackness 600',
    'sq ft at 2 charges; prismatic',
    'sphere 1 charge per color; each',
    'function 5 segments, 1 per round;',
    'rechargeable), Enemy Detection (6"',
    'sphere, 1 charge per turn,',
    'rechargeable), Fear (cone 6" x 2",',
    '1 segment, flee 6 rounds, 1 charge',
    'per use, once per round,',
    'rechargeable), Fire (4 functions:',
    'burning hands 10 ft wide 12 ft long',
    '6 hp 1 segment 1 charge;',
    'pyrotechnics 2 segments 1 charge;',
    'fireball range 16", 2 segments, 2',
    'charges, 6 dice with 1s counted as',
    '2s = 12-36 hp; wall of fire 12',
    'square", 6 rounds, 8-18 hp touched',
    '(2d6+6), 2-8 within 1", 1-4 within',
    '2", ring circle 2.25 inch diameter',
    '- pinned as 9 quarter-inches; once',
    'per round, rechargeable), and Frost',
    '(3 functions: ice storm 6"',
    'distant, 1 segment, 1 charge; wall',
    'of ice 6 inches thick, 6" square',
    'area, 2 segments, 1 charge; cone of',
    'cold 6" long 2" terminal diameter,',
    '2 segments, c. -100 F, 6 dice',
    '12-36, 2 charges; once per round,',
    'rechargeable). The five wands are',
    'the engine kRods wand rows 1-5,',
    'bands 34-47, illumination from 48',
    '(cross-checked against the R224',
    'rodswands.h bands in the audit).',
    'New R246 battery audit; census 165.',
    'Next: R247 - the remaining ten',
    'wands (upload ~10828-10865:',
    'Illumination, Illusion, Lightning,',
    'Magic Detection, Metal and Mineral',
    'Detection, Magic Missiles,',
    'Negation, Paralyzation,',
    'Polymorphing, Secret Door and Trap',
    'Location), then R248 the wand of',
    'wonder effect table (upload',
    '~10867-10947). The potions/',
    'scrolls/rings explanation prose',
    '(upload ~9998-10561) and the misc',
    'magic item explanations (~10949+)',
    'remain open after that.',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson)
marker = 'R246: the III.D wands explanation prose'
try:
    t = open(WD).read()
    if marker in t:
        already += 1
    else:
        print('R246 FAIL: rules/wandsprose.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(WD, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R246 audit', audit_old, audit_new),
    (GAP, 'the R246 log entry', gap_old, gap_new),
]:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    # the idempotence signal is the NEW text (the R233
    # lesson: append-style patches leave the old text
    # inside the new)
    if new_s in text:
        already += 1
        continue
    if text.count(old_s) == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    else:
        print('R246 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 165:
        print('R246 FAIL: census is not 165')
        sys.exit(1)
    if t.count('R246 wands prose pins audit') != 1:
        print('R246 FAIL: the R246 audit line must appear once')
        sys.exit(1)
    if t.count('rules/wandsprose.h') != 1:
        print('R246 FAIL: the wandsprose include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R246 landed the III.D wands') != 1:
        print('R246 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(WD).read()
    if 'namespace rules' not in h or h.count('inline int wd') != 65:
        print('R246 FAIL: the header shape is wrong')
        sys.exit(1)

print('R246 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R246 note: 4 patches; the III.D wands explanation prose part 1 -')
print('the conventions and the first five wands; census 165.')
print('commit: R246: the III.D wands explanation prose pins pinned - DMG pp.143-144, the conventions and the first five wands (census 165)')

