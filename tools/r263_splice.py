#!/usr/bin/env python3
# R263 splice: the III.E misc magic explanation prose
# part 7 pins - Cube of Force through Decanter of
# Endless Water, part2 lines 285-322 (DMG p.132-133)
# - the slice completing the kMisc2 rows 13-17. ZERO
# page headers inside the slice (a first); ONE seam
# pins (the Daern 314/316). 4 patches, marker-based
# idempotence, assert after every patch. ZERO
# apostrophes and ZERO literal backslashes in the
# content below (the printf newline is built via
# BS = chr(92)).

import os
import sys

HERE = os.path.abspath(os.path.dirname(sys.argv[0]))
ROOT = os.path.abspath(HERE + '/..')
NL = chr(10)
BS = chr(92)

applied = 0
already = 0

def rd(p):
    f = open(os.path.join(ROOT, p), encoding='utf-8')
    s = f.read()
    f.close()
    return s

def wr(p, s):
    f = open(os.path.join(ROOT, p), 'w', encoding='utf-8')
    f.write(s)
    f.close()

# ---- patch 1: rules/miscprose7.h ----
HDR = [
    '// ====================================================================',
    '// Adnd1 - rules/miscprose7.h',
    '// R263: the III.E misc magic explanation prose part 7',
    '// (DMG p.132-133) - Cube of Force through Decanter',
    '// of Endless Water, part2 lines 285-322 (global =',
    '// 11065 + part2 line). ZERO page headers inside the',
    '// slice (a first); ONE seam pins exactly: the Daern',
    '// (line 314 ends but the person or, line 316',
    '// continues persons nearby). 45 accessors: 42',
    '// scalars + 3 array walkers, no name collisions',
    '// with miscprose1.h through miscprose6.h. The slice',
    '// completes kMisc2 rows 13-17; this stretch carries',
    '// no class marks and no asterisk rows (the negative',
    '// control slice). Pure data + helpers, header-only',
    '// (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int mmpCubeForceWallInches() {',
    '    // wall of force, 1 inch per side',
    '    return 1;',
    '}',
    '',
    'inline int mmpCubeForceCharges() {',
    '    // the cube has 36 charges',
    '    return 36;',
    '}',
    '',
    'inline int mmpCubeForceRestoreDays() {',
    '    // energy restored each day',
    '    return 1;',
    '}',
    '',
    'inline int mmpCubeForceFaceCount() {',
    '    // six faces, one per screen strength',
    '    return 6;',
    '}',
    '',
    'inline int mmpCubeForceSurchargeFormCount() {',
    '    // the attack-form surcharge table entries',
    '    return 14;',
    '}',
    '',
    'inline int mmpCubeForceSpellsInOutBlocked() {',
    '    // no casting into or out of the cube',
    '    return 1;',
    '}',
    '',
    'inline int mmpCubeForceMaterialCount() {',
    '    // hard mineral, ivory, bone',
    '    return 3;',
    '}',
    '',
    'inline int mmpCubeFrostSideInches() {',
    '    // encloses 1 inch per side',
    '    return 1;',
    '}',
    '',
    'inline int mmpCubeFrostTempF() {',
    '    // always 65 degrees F inside',
    '    return 65;',
    '}',
    '',
    'inline int mmpCubeFrostColdAttackCount() {',
    '    // cone of cold, ice storm, dragon breath',
    '    return 3;',
    '}',
    '',
    'inline int mmpCubeFrostCollapseHp() {',
    '    // more than this per turn: collapse',
    '    return 50;',
    '}',
    '',
    'inline int mmpCubeFrostTurnRounds() {',
    '    // a turn is 10 rounds',
    '    return 10;',
    '}',
    '',
    'inline int mmpCubeFrostRenewHours() {',
    '    // after collapse: no renewal for',
    '    return 1;',
    '}',
    '',
    'inline int mmpCubeFrostDestroyHp() {',
    '    // over this in 1 turn: destroyed',
    '    return 100;',
    '}',
    '',
    'inline int mmpCubeFrostColdPer10BelowF() {',
    '    // 2 hp of cold per minus 10 degrees',
    '    return 2;',
    '}',
    '',
    'inline int mmpCubeFrostAt40BelowHp() {',
    '    // at minus 40 F: withstands only',
    '    return 42;',
    '}',
    '',
    'inline int mmpCubicGateSideCount() {',
    '    // the 6 sides, each keyed to a plane',
    '    return 6;',
    '}',
    '',
    'inline int mmpCubicGatePrimeSides() {',
    '    // one side is always Prime Material',
    '    return 1;',
    '}',
    '',
    'inline int mmpCubicGateChosenSides() {',
    '    // the other 5 are chosen',
    '    return 5;',
    '}',
    '',
    'inline int mmpCubicGateNexusChancePct() {',
    '    // per turn, something comes through',
    '    return 10;',
    '}',
    '',
    'inline int mmpCubicGateDrawRadiusFeet() {',
    '    // second press draws all within',
    '    return 5;',
    '}',
    '',
    'inline int mmpCubicGateMaxLinks() {',
    '    // no more than 1 nexial link at once',
    '    return 1;',
    '}',
    '',
    'inline int mmpDaernSquareFeet() {',
    '    // the tower footprint, square',
    '    return 20;',
    '}',
    '',
    'inline int mmpDaernHeightFeet() {',
    '    // the tower height',
    '    return 30;',
    '}',
    '',
    'inline int mmpDaernGroundDepthFeet() {',
    '    // metal extends into the ground',
    '    return 10;',
    '}',
    '',
    'inline int mmpDaernCollapseHp() {',
    '    // damage before the tower collapses',
    '    return 200;',
    '}',
    '',
    'inline int mmpDaernWishRepairHp() {',
    '    // a wish restores this much damage',
    '    return 10;',
    '}',
    '',
    'inline int mmpDaernSpringRounds() {',
    '    // springs up in but 1 round',
    '    return 1;',
    '}',
    '',
    'inline int mmpDaernGrowthDamageMin() {',
    '    // caught by the growth: minimum',
    '    return 10;',
    '}',
    '',
    'inline int mmpDaernGrowthDamageMax() {',
    '    // caught by the growth: maximum',
    '    return 100;',
    '}',
    '',
    'inline int mmpDaernDoorOwnerOnly() {',
    '    // opens only to the owner command',
    '    return 1;',
    '}',
    '',
    'inline int mmpDaernNormalWeaponsAffect() {',
    '    // normal weapons do NOT affect the walls',
    '    return 0;',
    '}',
    '',
    'inline int mmpDaernDamageCumulative() {',
    '    // sustained damage is cumulative',
    '    return 1;',
    '}',
    '',
    'inline int mmpDecanterModeCount() {',
    '    // stream, fountain, geyser',
    '    return 3;',
    '}',
    '',
    'inline int mmpDecanterStreamGallonsPerRound() {',
    '    // stream pours per round',
    '    return 1;',
    '}',
    '',
    'inline int mmpDecanterFountainLengthFeet() {',
    '    // the fountain stream length',
    '    return 5;',
    '}',
    '',
    'inline int mmpDecanterFountainGallonsPerRound() {',
    '    // fountain pours per round',
    '    return 5;',
    '}',
    '',
    'inline int mmpDecanterGeyserLengthFeet() {',
    '    // the geyser stream length',
    '    return 20;',
    '}',
    '',
    'inline int mmpDecanterGeyserGallonsPerRound() {',
    '    // geyser pours per round',
    '    return 30;',
    '}',
    '',
    'inline int mmpDecanterWaterTypeCount() {',
    '    // fresh or salt, as ordered',
    '    return 2;',
    '}',
    '',
    'inline int mmpDecanterGeyserKnockover() {',
    '    // geyser back pressure knocks over',
    '    return 1;',
    '}',
    '',
    'inline int mmpDecanterStopsOnCommand() {',
    '    // the command word ceases the flow',
    '    return 1;',
    '}',
    '',
    'inline int mmpCubeForceCostPerTurn(int i) {',
    '    // the face charge cost; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        1, 2, 3, 4, 6, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpCubeForceMoveInches(int i) {',
    '    // the face movement rate; 0 is normal; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        1, 8, 6, 4, 3, 0,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpCubeForceSurchargeAt(int i) {',
    '    // the attack-form surcharges, row-major',
    '    // print order; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 13) i = 13;',
    '    static const int t[14] = {',
    '        1, 3, 2, 4, 6, 8, 3, 3, 6, 5, 3, 7, 3, 2,',
    '    };',
    '    return t[i];',
    '}',
    '',
    '} // namespace rules',
]
P1 = 'rules/miscprose7.h'
if os.path.exists(os.path.join(ROOT, P1)):
    already += 1
    assert rd(P1) == NL.join(HDR), P1 + ' exists but differs'
else:
    wr(P1, NL.join(HDR))
    applied += 1
    assert rd(P1) == NL.join(HDR), P1 + ' write mismatch'
assert rd(P1).count(
    'R263: the III.E misc magic explanation prose part 7') == 1

# ---- patch 2: the regtest include ----
INC_OLD = ('#include "rules/miscprose6.h"  // R262: the III.E misc'
           ' magic explanation prose part 6 pins')
INC_NEW = ('#include "rules/miscprose7.h"  // R263: the III.E misc'
           ' magic explanation prose part 7 pins')
RG = rd('regtest.cpp')
if INC_NEW in RG:
    already += 1
    assert RG.count(INC_NEW) == 1, 'include not unique'
else:
    assert RG.count(INC_OLD) == 1, 'R262 include anchor missing'
    RG = RG.replace(INC_OLD, INC_OLD + NL + INC_NEW)
    applied += 1
    assert RG.count(INC_NEW) == 1, 'include insert failed'
wr('regtest.cpp', RG)

# ---- patch 3: the R263 audit block ----
AUDIT = [
    '    // ---- R263: the III.E misc magic explanation',
    '    // prose part 7 ----',
    '    // Cube of Force through Decanter of Endless',
    '    // Water, part2 lines 285-322 - the prose pins,',
    '    // completing the kMisc2 rows 13-17. This',
    '    // stretch carries no class marks and no',
    '    // asterisk rows (the negative control slice).',
    '    {',
    '        int bad = 0;',
    '        if (rules::mmpCubeForceWallInches() != 1 ||',
    '            rules::mmpCubeForceCharges() != 36 ||',
    '            rules::mmpCubeForceRestoreDays() != 1 ||',
    '            rules::mmpCubeForceFaceCount() != 6 ||',
    '            rules::mmpCubeForceSurchargeFormCount() != 14 ||',
    '            rules::mmpCubeForceSpellsInOutBlocked() != 1 ||',
    '            rules::mmpCubeForceMaterialCount() != 3) ++bad;',
    '        if (rules::mmpCubeFrostSideInches() != 1 ||',
    '            rules::mmpCubeFrostTempF() != 65 ||',
    '            rules::mmpCubeFrostColdAttackCount() != 3 ||',
    '            rules::mmpCubeFrostCollapseHp() != 50 ||',
    '            rules::mmpCubeFrostTurnRounds() != 10 ||',
    '            rules::mmpCubeFrostRenewHours() != 1 ||',
    '            rules::mmpCubeFrostDestroyHp() != 100 ||',
    '            rules::mmpCubeFrostColdPer10BelowF() != 2 ||',
    '            rules::mmpCubeFrostAt40BelowHp() != 42) ++bad;',
    '        if (rules::mmpCubicGateSideCount() != 6 ||',
    '            rules::mmpCubicGatePrimeSides() != 1 ||',
    '            rules::mmpCubicGateChosenSides() != 5 ||',
    '            rules::mmpCubicGateNexusChancePct() != 10 ||',
    '            rules::mmpCubicGateDrawRadiusFeet() != 5 ||',
    '            rules::mmpCubicGateMaxLinks() != 1) ++bad;',
    '        if (rules::mmpDaernSquareFeet() != 20 ||',
    '            rules::mmpDaernHeightFeet() != 30 ||',
    '            rules::mmpDaernGroundDepthFeet() != 10 ||',
    '            rules::mmpDaernCollapseHp() != 200 ||',
    '            rules::mmpDaernWishRepairHp() != 10 ||',
    '            rules::mmpDaernSpringRounds() != 1 ||',
    '            rules::mmpDaernGrowthDamageMin() != 10 ||',
    '            rules::mmpDaernGrowthDamageMax() != 100 ||',
    '            rules::mmpDaernDoorOwnerOnly() != 1 ||',
    '            rules::mmpDaernNormalWeaponsAffect() != 0 ||',
    '            rules::mmpDaernDamageCumulative() != 1) ++bad;',
    '        if (rules::mmpDecanterModeCount() != 3 ||',
    '            rules::mmpDecanterStreamGallonsPerRound() != 1 ||',
    '            rules::mmpDecanterFountainLengthFeet() != 5 ||',
    '            rules::mmpDecanterFountainGallonsPerRound() != 5 ||',
    '            rules::mmpDecanterGeyserLengthFeet() != 20 ||',
    '            rules::mmpDecanterGeyserGallonsPerRound() != 30 ||',
    '            rules::mmpDecanterWaterTypeCount() != 2 ||',
    '            rules::mmpDecanterGeyserKnockover() != 1 ||',
    '            rules::mmpDecanterStopsOnCommand() != 1) ++bad;',
    '        static const int kFaceCost[6] = {',
    '            1, 2, 3, 4, 6, 0,',
    '        };',
    '        static const int kFaceMove[6] = {',
    '            1, 8, 6, 4, 3, 0,',
    '        };',
    '        static const int kSurcharge[14] = {',
    '            1, 3, 2, 4, 6, 8, 3, 3, 6, 5, 3, 7, 3, 2,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::mmpCubeForceCostPerTurn(i) !=',
    '                kFaceCost[i] ||',
    '                rules::mmpCubeForceMoveInches(i) !=',
    '                kFaceMove[i]) ++bad;',
    '        for (int i = 0; i < 14; ++i)',
    '            if (rules::mmpCubeForceSurchargeAt(i) !=',
    '                kSurcharge[i]) ++bad;',
    '        // the printed frost math: at minus 40 F the',
    '        // device withstands only 42 hp - 50 minus 2',
    '        // hp per 10 degrees below zero',
    '        if (rules::mmpCubeFrostCollapseHp() -',
    '            rules::mmpCubeFrostColdPer10BelowF() * 4 !=',
    '            rules::mmpCubeFrostAt40BelowHp()) ++bad;',
    '        // the kMisc2 rows this slice completes:',
    '        // 13 Cube of Force 62-63, 14 Frost 64-65,',
    '        // 15 Cubic Gate 66-67, 16 Daern 68-69,',
    '        // 17 Decanter 70-72',
    '        static const int kM2Lo3[5] = {',
    '            62, 64, 66, 68, 70,',
    '        };',
    '        static const int kM2Hi3[5] = {',
    '            63, 65, 67, 69, 72,',
    '        };',
    '        for (int i = 0; i < 5; ++i)',
    '            if (rules::m2RowLo(13 + i) != kM2Lo3[i] ||',
    '                rules::m2RowHi(13 + i) != kM2Hi3[i]) ++bad;',
    '        // the negative control stretch: no (C), no',
    '        // (M), no asterisk rows on 13-17; row 12',
    '        // is the (M) positive control',
    '        for (int i = 13; i < 18; ++i)',
    '            if (rules::m2UsableByCleric(i) ||',
    '                rules::m2UsableByMagicUser(i) ||',
    '                rules::m2IsPerPlusValued(i) ||',
    '                rules::m2HasFeatureAsterisk(i) ||',
    '                rules::m2IsTripleStar(i)) ++bad;',
    '        if (!rules::m2UsableByMagicUser(12)) ++bad;',
    '        printf("R263 misc magic prose part 7 pins audit:'
    ' bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]
RG = rd('regtest.cpp')
ANCHOR = ('    // ---- R227: the wis mental save wiring audit ----')
AUDIT_STR = NL.join(AUDIT)
if ('printf("R263 misc magic prose part 7 pins audit:') in RG:
    already += 1
    assert RG.count(ANCHOR) == 1, 'R227 anchor not unique'
else:
    assert RG.count(ANCHOR) == 1, 'R227 anchor not unique'
    RG = RG.replace(ANCHOR, AUDIT_STR + NL + ANCHOR)
    applied += 1
    assert RG.count(
        'printf("R263 misc magic prose part 7 pins audit:') == 1, \
        'audit printf not unique'
wr('regtest.cpp', RG)

# ---- patch 4: the gap entry ----
GAP = [
    'R263 landed the III.E misc',
    'magic explanation prose part',
    '7 (part2 lines 285-322;',
    'global = 11065 + part2',
    'line), Cube of Force through',
    'Decanter of Endless Water -',
    'completing the kMisc2 rows',
    '13-17. ZERO page headers',
    'inside the slice (a first);',
    'ONE seam pins exactly (the',
    'Daern: line 314 ends but the',
    'person or, line 316 continues',
    'persons nearby). Cube of',
    'Force (36 charges, restored',
    'daily; wall of force 1 inch',
    'per side; the 6-face table',
    '1/1, 2/8, 3/6, 4/4, 6/3,',
    '0/normal; the 14-form attack',
    'surcharge table catapult 1',
    'through wall of fire 2; no',
    'casting into or out; mineral,',
    'ivory or bone), Cube of',
    'Frost Resistance (65 degrees',
    'F inside; absorbs cone of',
    'cold, ice storm, dragon',
    'breath; collapses over 50 hp',
    'per turn, renews after 1',
    'hour, destroyed over 100 hp;',
    'minus 40 F withstands only',
    '42 hp, the 2-per-minus-10',
    'math pinned), Cubic Gate',
    '(carnelian; 6 sides, 1 Prime',
    'Material, 5 chosen; 1 press',
    'opens a nexus, 10 percent per',
    'turn something comes',
    'through; 2 presses draw all',
    'within 5 feet; max 1 link),',
    'Daern Instant Fortress (20',
    'foot square, 30 high, 10 into',
    'ground; owner-only door;',
    'walls ignore all but',
    'catapults; 200 hp collapse,',
    'damage cumulative, wish',
    'restores 10; springs up in 1',
    'round, catching growth costs',
    '10-100 hp), Decanter of',
    'Endless Water (stream 1',
    'gallon, fountain 5 foot at 5,',
    'geyser 20 foot at 30; fresh',
    'or salt; geyser knocks the',
    'holder over and kills small',
    'animals; ceases on command).',
    'ENGINE CROSS-CHECK: kMisc2',
    'rows 13-17 (62-63, 64-65,',
    '66-67, 68-69, 70-72) and the',
    'negative-control stretch -',
    'no (C), no (M), no asterisk',
    'rows on 13-17; row 12 still',
    'carries its (M). The frost',
    'math cross-pins 50 - 2 x 4 =',
    '42. New R263 battery audit;',
    'census 181. Next: part 8 -',
    'Deck of Many Things onward',
    'in part2 from line 324',
    '(global 11389; the 22-plaque',
    'table and the per-plaque',
    'explanations follow; the',
    'deck sits on kMisc2 row 18,',
    '73-76).',
]
GP = rd('tools/dmg_gap_report.md')
if GP.count('R263 landed the III.E misc') == 1:
    already += 1
else:
    TAIL = ('and the attack-form' + NL +
            'surcharge table follow).' + NL + NL + 'Categories:')
    assert GP.count(TAIL) == 1, 'R262 gap tail anchor not unique'
    NEWTAIL = ('and the attack-form' + NL +
               'surcharge table follow).' + NL + NL +
               NL.join(GAP) + NL + NL + 'Categories:')
    GP = GP.replace(TAIL, NEWTAIL)
    applied += 1
    assert GP.count('R263 landed the III.E misc') == 1, \
        'gap entry insert failed'
wr('tools/dmg_gap_report.md', GP)

# ---- report ----
assert applied + already == 4, 'patch count wrong'
print('R263 splice: ALL OK (applied %d, already %d)'
      % (applied, already))
print('R263 note: 4 patches; the III.E misc magic')
print('explanation prose part 7 - Cube of Force through')
print('Decanter of Endless Water, part2 lines 285-322;')
print('census 181.')
COMMIT = ('R263: the III.E misc magic explanation prose part 7'
          ' pinned - Cube of Force through Decanter of Endless'
          ' Water in part2 lines 285-322 (census 181)')
print('commit: ' + COMMIT)

