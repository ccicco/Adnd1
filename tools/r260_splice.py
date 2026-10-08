#!/usr/bin/env python3
# R260 splice: the III.E misc magic explanation prose
# part 4 pins - Bowl Commanding Water Elementals
# through Bucknard Everfull Purse, part2 lines
# 110-153 (DMG p.132) - plus the R225 per-AC
# asterisk off-by-one fix: the printed asterisk
# row is 60-79 Bracers of Defense (engine kMisc1
# row 25), not row 26 (80-81 Bracers of
# Defenselessness). 7 patches, marker-based
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

# ---- patch 1: rules/miscprose4.h ----
HDR = [
    '// ====================================================================',
    '// Adnd1 - rules/miscprose4.h',
    '// R260: the III.E misc magic explanation prose part 4',
    '// (DMG p.132) - Bowl Commanding Water Elementals',
    '// through Bucknard Everfull Purse, part2 lines',
    '// 110-153 (global = 11065 + part2 line). ONE page',
    '// header inside the slice (line 127, the TREASURE',
    '// page) splits the Bracers of Defense table from',
    '// Bracers of Defenselessness - stripped per the',
    '// R249 lesson; no mid-sentence seam this time.',
    '// 53 accessors: 48 scalars + 5 array walkers, no',
    '// name collisions with miscprose1.h through',
    '// miscprose3.h. The purse type-table coin columns',
    '// are mangled in the upload - only the band',
    '// edges and the 26-per-type are pinned (the',
    '// R256 lesson).',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int mmpBowlCmdHd() {',
    '    // the summoned water elemental',
    '    return 12;',
    '}',
    '',
    'inline int mmpBowlCmdWordsRounds() {',
    '    // the summoning words take 1 round',
    '    return 1;',
    '}',
    '',
    'inline int mmpBowlCmdSaltBonusPerDie() {',
    '    // salt water: +2 per hit die',
    '    return 2;',
    '}',
    '',
    'inline int mmpBowlCmdSaltMaxHpPerDie() {',
    '    // salt water: max 8 hp per die',
    '    return 8;',
    '}',
    '',
    'inline int mmpBowlCmdDiameterInches() {',
    '    // about 1 foot across',
    '    return 12;',
    '}',
    '',
    'inline int mmpBowlCmdDepthInches() {',
    '    // half the diameter',
    '    return 6;',
    '}',
    '',
    'inline int mmpWateryDeathSaltSavePenalty() {',
    '    // salt water: the save is at minus 2',
    '    return 2;',
    '}',
    '',
    'inline int mmpWateryDeathDrownMinRounds() {',
    '    // the victim drowns in 3-8 rounds',
    '    return 3;',
    '}',
    '',
    'inline int mmpWateryDeathDrownMaxRounds() {',
    '    // the victim drowns in 3-8 rounds',
    '    return 8;',
    '}',
    '',
    'inline int mmpWateryDeathFreeSpellCount() {',
    '    // animal growth, enlarge, wish',
    '    return 3;',
    '}',
    '',
    'inline int mmpWateryDeathDeathPermanent() {',
    '    // no resurrection, even a wish fails',
    '    return 1;',
    '}',
    '',
    'inline int mmpWateryDeathSweetWaterAnotherSave() {',
    '    // a sweet water potion: another save',
    '    return 1;',
    '}',
    '',
    'inline int mmpBracersDefRowCount() {',
    '    // the random AC table rows',
    '    return 7;',
    '}',
    '',
    'inline int mmpBracersDefAcMin() {',
    '    // the 86-00 row',
    '    return 2;',
    '}',
    '',
    'inline int mmpBracersDefAcMax() {',
    '    // the 01-05 row',
    '    return 8;',
    '}',
    '',
    'inline int mmpDefenselessAc() {',
    '    // lowers armor class to 10',
    '    return 10;',
    '}',
    '',
    'inline int mmpDefenselessNegatesProtections() {',
    '    // all protections and dex bonuses',
    '    return 1;',
    '}',
    '',
    'inline int mmpDefenselessRemoveCurseOnly() {',
    '    // only remove curse takes them off',
    '    return 1;',
    '}',
    '',
    'inline int mmpBrazierFireHd() {',
    '    // the summoned fire elemental',
    '    return 12;',
    '}',
    '',
    'inline int mmpBrazierFireLightRounds() {',
    '    // lighting the fire usually takes 1 round',
    '    return 1;',
    '}',
    '',
    'inline int mmpBrazierFireSulphurBonusPerDie() {',
    '    // sulphur: +1 on each hit die',
    '    return 1;',
    '}',
    '',
    'inline int mmpBrazierFireSulphurHpMin() {',
    '    // sulphur: 2-9 hp per die',
    '    return 2;',
    '}',
    '',
    'inline int mmpBrazierFireSulphurHpMax() {',
    '    // sulphur: 2-9 hp per die',
    '    return 9;',
    '}',
    '',
    'inline int mmpSleepSmokeRadiusInches() {',
    '    // the smoke cloud radius',
    '    return 1;',
    '}',
    '',
    'inline int mmpSleepSmokeHd() {',
    '    // the fire elemental that appears',
    '    return 12;',
    '}',
    '',
    'inline int mmpSleepSmokeAwakenSpellCount() {',
    '    // dispel magic or remove curse',
    '    return 2;',
    '}',
    '',
    'inline int mmpBroochPctWithoutGems() {',
    '    // usually without gems inset',
    '    return 90;',
    '}',
    '',
    'inline int mmpBroochAbsorbHp() {',
    '    // absorbs magic missile damage, then melts',
    '    return 101;',
    '}',
    '',
    'inline int mmpBroomAttackDumpMinFeet() {',
    '    // dumps the rider from 6 feet',
    '    return 6;',
    '}',
    '',
    'inline int mmpBroomAttackDumpMaxFeet() {',
    '    // dumps the rider up to 9 feet',
    '    return 9;',
    '}',
    '',
    'inline int mmpBroomAttackAttacksPerRound() {',
    '    // each attack twice per round',
    '    return 2;',
    '}',
    '',
    'inline int mmpBroomAttackAsHd() {',
    '    // attacks as a 4 hit die monster',
    '    return 4;',
    '}',
    '',
    'inline int mmpBroomAttackStrawBlindRounds() {',
    '    // the straw end blinds for 1 round',
    '    return 1;',
    '}',
    '',
    'inline int mmpBroomAttackHandleDmgMin() {',
    '    // the handle end: 1-3 hp',
    '    return 1;',
    '}',
    '',
    'inline int mmpBroomAttackHandleDmgMax() {',
    '    // the handle end: 1-3 hp',
    '    return 3;',
    '}',
    '',
    'inline int mmpBroomAttackAc() {',
    '    // the broom armor class',
    '    return 7;',
    '}',
    '',
    'inline int mmpBroomAttackHpToDestroy() {',
    '    // hit points to destroy',
    '    return 18;',
    '}',
    '',
    'inline int mmpBroomFlySpeedInches() {',
    '    // movement speed',
    '    return 30;',
    '}',
    '',
    'inline int mmpBroomFlyCapacityPounds() {',
    '    // carries 182 pounds at speed',
    '    return 182;',
    '}',
    '',
    'inline int mmpBroomFlyPoundsPerInch() {',
    '    // every 14 pounds slows 1 inch',
    '    return 14;',
    '}',
    '',
    'inline int mmpBroomFlyClimbDiveDegrees() {',
    '    // climb or dive angle',
    '    return 30;',
    '}',
    '',
    'inline int mmpBroomFlyFetchSpeedInches() {',
    '    // comes to its owner at up to 30',
    '    return 30;',
    '}',
    '',
    'inline int mmpPurseCoinsPerType() {',
    '    // 26 of each applicable type, next morning',
    '    return 26;',
    '}',
    '',
    'inline int mmpPurseTypeRowCount() {',
    '    // the type bands',
    '    return 3;',
    '}',
    '',
    'inline int mmpPurseGemsBaseGp() {',
    '    // base gems',
    '    return 10;',
    '}',
    '',
    'inline int mmpPurseGemsMaxGp() {',
    '    // gems may increase to 100 at most',
    '    return 100;',
    '}',
    '',
    'inline int mmpPurseAbilitiesNeverChange() {',
    '    // once rolled, the type never changes',
    '    return 1;',
    '}',
    '',
    'inline int mmpPurseSpiceNote() {',
    '    // the design note: a constant fund source',
    '    return 1;',
    '}',
    '',
    'inline int mmpBracersDefBandLo(int i) {',
    '    // printed band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 6) i = 6;',
    '    static const int t[7] = {',
    '        1, 6, 16, 36, 51, 71, 86,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpBracersDefBandHi(int i) {',
    '    // printed band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 6) i = 6;',
    '    static const int t[7] = {',
    '        5, 15, 35, 50, 70, 85, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpBracersDefAc(int i) {',
    '    // the armor class per band; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 6) i = 6;',
    '    static const int t[7] = {',
    '        8, 7, 6, 5, 4, 3, 2,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpPurseTypeBandLo(int i) {',
    '    // the type band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    static const int t[3] = {',
    '        1, 51, 91,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpPurseTypeBandHi(int i) {',
    '    // the type band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    static const int t[3] = {',
    '        50, 90, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    '} // namespace rules',
    '',
]
P1 = 'rules/miscprose4.h'
if os.path.exists(os.path.join(ROOT, P1)):
    already += 1
    assert rd(P1) == NL.join(HDR), P1 + ' exists but differs'
else:
    wr(P1, NL.join(HDR))
    applied += 1
    assert rd(P1) == NL.join(HDR), P1 + ' write mismatch'
assert rd(P1).count(
    'R260: the III.E misc magic explanation prose part 4') == 1

# ---- patch 2: the regtest include ----
INC_OLD = ('#include "rules/miscprose3.h"  // R259: the III.E misc'
           ' magic explanation prose part 3 pins')
INC_NEW = ('#include "rules/miscprose4.h"  // R260: the III.E misc'
           ' magic explanation prose part 4 pins')
RG = rd('regtest.cpp')
if INC_NEW in RG:
    already += 1
    assert RG.count(INC_NEW) == 1, 'include not unique'
else:
    assert RG.count(INC_OLD) == 1, 'R259 include anchor missing'
    RG = RG.replace(INC_OLD, INC_OLD + NL + INC_NEW)
    applied += 1
    assert RG.count(INC_NEW) == 1, 'include insert failed'
wr('regtest.cpp', RG)

# ---- patch 3: the R260 audit block ----
AUDIT = [
    '    // ---- R260: the III.E misc magic explanation',
    '    // prose part 4 ----',
    '    // Bowl Commanding Water Elementals through',
    '    // Bucknard Everfull Purse, part2 lines',
    '    // 110-153 - the prose pins, plus the R225',
    '    // per-AC asterisk off-by-one fixed: the',
    '    // printed asterisk row is 60-79 Bracers of',
    '    // Defense (engine row 25), not row 26',
    '    // (80-81 Defenselessness).',
    '    {',
    '        int bad = 0;',
    '        if (rules::mmpBowlCmdHd() != 12 ||',
    '            rules::mmpBowlCmdWordsRounds() != 1 ||',
    '            rules::mmpBowlCmdSaltBonusPerDie() != 2 ||',
    '            rules::mmpBowlCmdSaltMaxHpPerDie() != 8 ||',
    '            rules::mmpBowlCmdDiameterInches() != 12 ||',
    '            rules::mmpBowlCmdDepthInches() != 6) ++bad;',
    '        if (rules::mmpWateryDeathSaltSavePenalty() != 2 ||',
    '            rules::mmpWateryDeathDrownMinRounds() != 3 ||',
    '            rules::mmpWateryDeathDrownMaxRounds() != 8 ||',
    '            rules::mmpWateryDeathFreeSpellCount() != 3 ||',
    '            rules::mmpWateryDeathDeathPermanent() != 1 ||',
    '            rules::mmpWateryDeathSweetWaterAnotherSave() != 1) ++bad;',
    '        if (rules::mmpBracersDefRowCount() != 7 ||',
    '            rules::mmpBracersDefAcMin() != 2 ||',
    '            rules::mmpBracersDefAcMax() != 8 ||',
    '            rules::mmpDefenselessAc() != 10 ||',
    '            rules::mmpDefenselessNegatesProtections() != 1 ||',
    '            rules::mmpDefenselessRemoveCurseOnly() != 1) ++bad;',
    '        if (rules::mmpBrazierFireHd() != 12 ||',
    '            rules::mmpBrazierFireLightRounds() != 1 ||',
    '            rules::mmpBrazierFireSulphurBonusPerDie() != 1 ||',
    '            rules::mmpBrazierFireSulphurHpMin() != 2 ||',
    '            rules::mmpBrazierFireSulphurHpMax() != 9 ||',
    '            rules::mmpSleepSmokeRadiusInches() != 1 ||',
    '            rules::mmpSleepSmokeHd() != 12 ||',
    '            rules::mmpSleepSmokeAwakenSpellCount() != 2) ++bad;',
    '        if (rules::mmpBroochPctWithoutGems() != 90 ||',
    '            rules::mmpBroochAbsorbHp() != 101) ++bad;',
    '        if (rules::mmpBroomAttackDumpMinFeet() != 6 ||',
    '            rules::mmpBroomAttackDumpMaxFeet() != 9 ||',
    '            rules::mmpBroomAttackAttacksPerRound() != 2 ||',
    '            rules::mmpBroomAttackAsHd() != 4 ||',
    '            rules::mmpBroomAttackStrawBlindRounds() != 1 ||',
    '            rules::mmpBroomAttackHandleDmgMin() != 1 ||',
    '            rules::mmpBroomAttackHandleDmgMax() != 3 ||',
    '            rules::mmpBroomAttackAc() != 7 ||',
    '            rules::mmpBroomAttackHpToDestroy() != 18) ++bad;',
    '        if (rules::mmpBroomFlySpeedInches() != 30 ||',
    '            rules::mmpBroomFlyCapacityPounds() != 182 ||',
    '            rules::mmpBroomFlyPoundsPerInch() != 14 ||',
    '            rules::mmpBroomFlyClimbDiveDegrees() != 30 ||',
    '            rules::mmpBroomFlyFetchSpeedInches() != 30) ++bad;',
    '        if (rules::mmpPurseCoinsPerType() != 26 ||',
    '            rules::mmpPurseTypeRowCount() != 3 ||',
    '            rules::mmpPurseGemsBaseGp() != 10 ||',
    '            rules::mmpPurseGemsMaxGp() != 100 ||',
    '            rules::mmpPurseAbilitiesNeverChange() != 1 ||',
    '            rules::mmpPurseSpiceNote() != 1) ++bad;',
    '        static const int kBracersDefLo[7] = {',
    '            1, 6, 16, 36, 51, 71, 86,',
    '        };',
    '        static const int kBracersDefHi[7] = {',
    '            5, 15, 35, 50, 70, 85, 100,',
    '        };',
    '        static const int kBracersDefAc[7] = {',
    '            8, 7, 6, 5, 4, 3, 2,',
    '        };',
    '        for (int i = 0; i < 7; ++i)',
    '            if (rules::mmpBracersDefBandLo(i) != kBracersDefLo[i] ||',
    '                rules::mmpBracersDefBandHi(i) != kBracersDefHi[i] ||',
    '                rules::mmpBracersDefAc(i) != kBracersDefAc[i]) ++bad;',
    '        static const int kPurseLo[3] = {',
    '            1, 51, 91,',
    '        };',
    '        static const int kPurseHi[3] = {',
    '            50, 90, 100,',
    '        };',
    '        for (int i = 0; i < 3; ++i)',
    '            if (rules::mmpPurseTypeBandLo(i) != kPurseLo[i] ||',
    '                rules::mmpPurseTypeBandHi(i) != kPurseHi[i]) ++bad;',
    '        static const int kM1Lo[10] = {',
    '            56, 59, 60, 80, 82, 85, 86, 93, 94, 99,',
    '        };',
    '        static const int kM1Hi[10] = {',
    '            58, 59, 79, 81, 84, 85, 92, 93, 98, 100,',
    '        };',
    '        for (int i = 0; i < 10; ++i)',
    '            if (rules::m1RowLo(i + 23) != kM1Lo[i] ||',
    '                rules::m1RowHi(i + 23) != kM1Hi[i]) ++bad;',
    '        // the (M) marks: the two Bowls and the two',
    '        // Braziers; Bracers of Defense row 25 is',
    '        // the negative control',
    '        if (!rules::m1UsableByMagicUser(23) ||',
    '            !rules::m1UsableByMagicUser(24) ||',
    '            !rules::m1UsableByMagicUser(27) ||',
    '            !rules::m1UsableByMagicUser(28) ||',
    '            rules::m1UsableByMagicUser(25)) ++bad;',
    '        // the R225 per-AC asterisk fix: the flag',
    '        // belongs on row 25 (60-79), the printed',
    '        // asterisk row, not row 26',
    '        if (!rules::m1IsPerAcPointValued(25) ||',
    '            rules::m1IsPerAcPointValued(26) ||',
    '            rules::m1IsPerAcPointValued(24)) ++bad;',
    '        if (!rules::m1IsTieredPurseRow(32) ||',
    '            rules::m1IsTieredPurseRow(31)) ++bad;',
    '        // the printed example: AC 6 (band row 2)',
    '        // is 4 points above 10 = 2,000 xp /',
    '        // 12,000 gp',
    '        if (rules::mmpBracersDefAc(2) != 6 ||',
    '            rules::m1BracersPerAcXp() *',
    '                (10 - rules::mmpBracersDefAc(2)) != 2000 ||',
    '            rules::m1BracersPerAcGp() *',
    '                (10 - rules::mmpBracersDefAc(2)) != 12000) ++bad;',
    '        printf("R260 misc magic prose part 4 pins audit:'
    ' bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]
RG = rd('regtest.cpp')
ANCHOR = ('    // ---- R227: the wis mental save wiring audit ----')
AUDIT_STR = NL.join(AUDIT)
if ('printf("R260 misc magic prose part 4 pins audit:') in RG:
    already += 1
    assert RG.count(ANCHOR) == 1, 'R227 anchor not unique'
else:
    assert RG.count(ANCHOR) == 1, 'R227 anchor not unique'
    RG = RG.replace(ANCHOR, AUDIT_STR + NL + ANCHOR)
    applied += 1
    assert RG.count(
        'printf("R260 misc magic prose part 4 pins audit:') == 1, \
        'audit printf not unique'
wr('regtest.cpp', RG)

# ---- patch 4: the miscmagic1.h per-AC flag fix ----
BUG_DEC = '0, 0, 0, 0, 0, 0, 1, 0, 0, 0,'
FIX_DEC = '0, 0, 0, 0, 0, 1, 0, 0, 0, 0,'
M1 = rd('rules/miscmagic1.h')
FP = M1.index('inline int m1IsPerAcPointValued')
FE = M1.index('};', FP)
BLK = M1[FP:FE]
if FIX_DEC in BLK:
    already += 1
    assert BLK.count(BUG_DEC) == 0, 'm1 flag block has both states'
else:
    assert BLK.count(BUG_DEC) == 1, 'm1 flag bug pattern not found'
    M1 = M1[:FP] + BLK.replace(BUG_DEC, FIX_DEC) + M1[FE:]
    applied += 1
    FP2 = M1.index('inline int m1IsPerAcPointValued')
    FE2 = M1.index('};', FP2)
    assert M1[FP2:FE2].count(FIX_DEC) == 1, 'm1 flag fix failed'
    assert BUG_DEC not in M1[FP2:FE2], 'm1 flag bug still present'
wr('rules/miscmagic1.h', M1)

# ---- patch 5: the regtest kBrac table fix ----
RG = rd('regtest.cpp')
KP = RG.index('static const int kBrac[33] = {')
KE = RG.index('};', KP)
KBLK = RG[KP:KE]
if FIX_DEC in KBLK:
    already += 1
    assert KBLK.count(BUG_DEC) == 0, 'kBrac block has both states'
else:
    assert KBLK.count(BUG_DEC) == 1, 'kBrac bug pattern not found'
    RG = RG[:KP] + KBLK.replace(BUG_DEC, FIX_DEC) + RG[KE:]
    applied += 1
    KP2 = RG.index('static const int kBrac[33] = {')
    KE2 = RG.index('};', KP2)
    assert RG[KP2:KE2].count(FIX_DEC) == 1, 'kBrac fix failed'
    assert BUG_DEC not in RG[KP2:KE2], 'kBrac bug still present'
wr('regtest.cpp', RG)

# ---- patch 6: the regtest assertion fix ----
OLD_IF = ('        if (!rules::m1IsPerAcPointValued(26) ||' + NL +
          '            rules::m1IsPerAcPointValued(27)) ++bad;')
NEW_IF = ('        if (!rules::m1IsPerAcPointValued(25) ||' + NL +
          '            rules::m1IsPerAcPointValued(26)) ++bad;')
RG = rd('regtest.cpp')
if NEW_IF in RG:
    already += 1
    assert RG.count(NEW_IF) == 1, 'assertion fix not unique'
else:
    assert RG.count(OLD_IF) == 1, 'assertion anchor not unique'
    RG = RG.replace(OLD_IF, NEW_IF)
    applied += 1
    assert RG.count(NEW_IF) == 1, 'assertion fix failed'
    assert OLD_IF not in RG, 'old assertion still present'
wr('regtest.cpp', RG)

# ---- patch 7: the gap entry ----
GAP = [
    'R260 landed the III.E misc',
    'magic explanation prose part',
    '4 (part2 lines 110-153;',
    'global = 11065 + part2',
    'line), Bowl Commanding Water',
    'Elementals through Bucknard',
    'Everfull Purse - completing',
    'the kMisc1 table rows',
    '23-32. ONE page header',
    'inside the slice, stripped',
    '(the R249 lesson): line 127',
    'splits the Bracers of',
    'Defense AC table from',
    'Bracers of Defenselessness -',
    'no mid-sentence seam this',
    'time. rules/miscprose4.h',
    '(the mmp prefix again, 53',
    'accessors: 48 scalars + 5',
    'array walkers, no name',
    'collisions with parts 1-3):',
    'Bowl Commanding Water',
    'Elementals (12 HD; words 1',
    'round; fresh or salt; salt',
    '+2 per die, max 8 hp per',
    'die), Bowl of Watery Death',
    '(save versus magic or shrunk',
    'to ant size; salt save at',
    'minus 2; drowns in 3-8',
    'rounds; freed only by animal',
    'growth, enlarge or wish;',
    'growth potion the same;',
    'sweet water another save;',
    'death permanent, even wish',
    'fails), Bracers of Defense',
    '(the 7-row AC table 01-05:8',
    'through 86-00:2; useless',
    'with armor, stack with',
    'other protections), Bracers',
    'of Defenselessness (serves',
    'until attacked in anger by',
    'a dangerous enemy; AC 10,',
    'negates all protections and',
    'dex bonuses; remove curse',
    'only), Brazier Commanding',
    'Fire Elementals (12 HD; fire',
    'lit 1 round; sulphur +1 per',
    'die, 2-9 hp per die),',
    'Brazier of Sleep Smoke (1',
    'inch radius cloud; save or',
    'deep sleep; a 12 HD fire',
    'elemental attacks the',
    'nearest creature; dispel',
    'magic or remove curse',
    'awakens), Brooch of',
    'Shielding (90% without gems;',
    'absorbs 101 hp of magic',
    'missile damage, then melts),',
    'Broom of Animated Attack',
    '(loop-the-loop dumps the',
    'rider 6-9 feet; attacks',
    'twice per round as a 4 HD',
    'monster; straw end blinds 1',
    'round; handle 1-3 damage;',
    'AC 7, 18 hp to destroy),',
    'Broom of Flying (30 inch',
    'speed; 182 pounds; 14 pounds',
    'per 1 inch slow; 30 degree',
    'climb or dive; fetches at 30',
    'inches), Bucknard Everfull',
    'Purse (26 coins per type the',
    'next morning; the 3 type',
    'bands 01-50 / 51-90 /',
    '91-00; emptied kills the',
    'magic; gems base 10 gp, max',
    '100 gp; abilities never',
    'change; the spice design',
    'note - the mangled coin',
    'columns noted not pinned,',
    'the R256 lesson). ENGINE',
    'CROSS-CHECK: kMisc1 rows',
    '23-32 (Bowl Cmd 56-58,',
    'Watery 59, Bracers 60-79,',
    'Defenseless 80-81, Brazier',
    'Fire 82-84, Sleep Smoke 85,',
    'Brooch 86-92, Broom Attack',
    '93, Broom Fly 94-98, Purse',
    '99-00) plus the (M) class',
    'marks on the two Bowls and',
    'two Braziers against the',
    'R225 m1 pins. FIX: the R225',
    'per-AC asterisk off-by-one',
    '- m1IsPerAcPointValued',
    'flagged row 26 (80-81',
    'Defenselessness) but the',
    'printed asterisk row is',
    '60-79 Bracers of Defense',
    '(row 25); the flag, the',
    'R225 audit kBrac table and',
    'its direct assertions now',
    'mark row 25, and the R260',
    'audit pins the printed AC 6',
    'example (2000 xp / 12000',
    'gp, four points above 10).',
    'New R260 battery audit;',
    'census 178. Next: part 5 -',
    'Candle of Invocation onward',
    'in part2 from line 155',
    '(global 11220; the TABLE',
    '(III.E.) 2. header at 155',
    'and the TREASURE header at',
    '159 both strip; the Candle',
    'seam: line 157 ends one of',
    'the, line 161 continues',
    'nine alignments).',
]
GP = rd('tools/dmg_gap_report.md')
if GP.count('R260 landed the III.E misc') == 1:
    already += 1
else:
    TAIL = ('line 110 (global = 11065 +' + NL + 'part2 line).' + NL +
            NL + 'Categories:')
    assert GP.count(TAIL) == 1, 'R259 gap tail anchor not unique'
    NEWTAIL = ('line 110 (global = 11065 +' + NL + 'part2 line).' +
               NL + NL + NL.join(GAP) + NL + NL + 'Categories:')
    GP = GP.replace(TAIL, NEWTAIL)
    applied += 1
    assert GP.count('R260 landed the III.E misc') == 1, \
        'gap entry insert failed'
wr('tools/dmg_gap_report.md', GP)

# ---- report ----
assert applied + already == 7, 'patch count wrong'
print('R260 splice: ALL OK (applied %d, already %d)'
      % (applied, already))
print('R260 note: 7 patches; the III.E misc magic')
print('explanation prose part 4 - Bowl Commanding Water')
print('Elementals through Bucknard Everfull Purse,')
print('part2 lines 110-153; the R225 per-AC asterisk')
print('off-by-one fixed; census 178.')
COMMIT = ('R260: the III.E misc magic explanation prose part 4'
          ' pinned - Bowl Commanding Water Elementals through'
          ' Bucknard Everfull Purse in part2 lines 110-153,'
          ' the R225 per-AC asterisk off-by-one fixed'
          ' (census 178)')
print('commit: ' + COMMIT)

