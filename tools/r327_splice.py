#!/usr/bin/env python3
# R327: the UA Character Classes Tables
# I and II (pp. 12-13) pin round - the
# hit-die column, the note facts, the
# Table II footnotes. Pin-era pattern
# (R322): pin now, wire when a site
# exists. Idempotent; run twice.

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

# ---- (a) the seed: the R326 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
'',
'- R326 landed 2026-10-11: commit',
'  e01935a, census 253, the UA',
'  creation round: the CR_SUBRACE',
'  picker stage (rows from',
'  subraceParentRace), the female',
'  field with its fem save line,',
'  makeMember wiring both fields,',
'  the dark-elf sex split live at',
'  the fold (the uaLevelCap female',
'  leg; the R325 audit compiles',
'  male on the default param).',
'  GREEN on the first paste. The',
'  oracle discipline held: the',
'  mechanical parse of the stacked',
'  case labels caught a hairfoot',
'  column misread before it hit',
'  C++, and the r325b signature',
'  check is why the old audit',
'  compiled unchanged.',
])
s = rd(SD)
if 'R326 landed 2026-10-11' in s:
    already.append('seed: the R326 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R326 record')
s = rd(SD)
assert s.count('R326 landed 2026-10-11') == 1, 'a entry'
assert s.count('R325 landed') == 1, 'a r325 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/classtables.h ----
CT = 'rules/classtables.h'
if os.path.exists(CT) and 'R327' in rd(CT):
    already.append('classtables.h: the pins')
else:
    HDR = NL.join([
'// ===========================================================================',
'// Adnd1 - rules/classtables.h',
'// The UA Character Classes Tables I and',
'// II (pp. 12-13) pins (R327).',
'//',
'// Table I: the Hit Die column (cavalier',
'// d10, barbarian d12, ranger d8 with two',
'// dice at 1st, monk d4 with two dice at',
'// 1st), the note-1 social-standing',
'// generators (the cavalier and paladin',
'// 1st-level hp 4-13 via 3d4+1 on the',
'// 0-level track or d10+3 Upper Class),',
'// the dice maxima (ranger 11 at the 10th,',
'// monk 18 at the 17th), the druid class',
'// level limit (23, Hierophant of the',
'// Cabal) and the spell-ability legs',
'// (notes 2, 4, 5).',
'//',
'// Table II: the station footnotes for',
'// the cavalier and paladin (no leather,',
'// padded or studded leather armor; no',
'// pole arms or missile weapons; the oil',
'// siege-warfare exception) and the',
'// acrobat as-thief-plus row. The weapon',
'// and oil/poison columns of the ten',
'// landed classes ride the R198/R199',
'// pins (rules/weapontables.h) - not',
'// re-pinned here.',
'//',
'// Pin-era pattern (R322): pinned data',
'// only - no engine site exists. The',
'// cavalier and barbarian level ladders',
'// ride their own class rounds (the',
'// registry is data-driven; append the',
'// rows there).',
'// ===========================================================================',
'',
'#pragma once',
'',
'#include "subraces.h"  // UaClass (the 14)',
'',
'namespace rules {',
'',
'// ---- Table I, the Hit Die column ----',
'// The UA grain (the four classes the',
'// gap report names); the PHB classes',
'// read the engine registry.',
'inline int uaClassHitDie(UaClass c) {',
'    switch (c) {',
'        case UACLASS_CAVALIER:',
'            return 10;',
'        case UACLASS_BARBARIAN:',
'            return 12;',
'        case UACLASS_RANGER:',
'            return 8;',
'        case UACLASS_MONK:',
'            return 4;',
'        default:',
'            return 0;   // the PHB classes:',
'                        // the registry read',
'    }',
'}',
'',
'// The first-level dice count (notes 3',
'// and 6: the ranger 2d8 and the monk 2d4',
'// starts).',
'inline int uaClassFirstLevelDice(',
'        UaClass c) {',
'    if (c == UACLASS_RANGER',
'        || c == UACLASS_MONK)',
'        return 2;',
'    return 1;',
'}',
'',
'// ---- Table I note 1: the cavalier and',
'// paladin 1st-level generators (the',
'// social-standing read; both tracks',
'// yield the printed 4-13 range) ----',
'enum CavalierTrack : int {',
'    CAVALIER_TRACK_ZERO = 0,  // the 0-level',
'                              // track: 3d4+1',
'    CAVALIER_TRACK_UPPER = 1  // Upper Class:',
'                              // d10+3',
'};',
'',
'inline int cavalierTrackDice(',
'        int track) {',
'    return track == CAVALIER_TRACK_UPPER',
'        ? 1 : 3;',
'}',
'',
'inline int cavalierTrackSides(',
'        int track) {',
'    return track == CAVALIER_TRACK_UPPER',
'        ? 10 : 4;',
'}',
'',
'inline int cavalierTrackBonus(',
'        int track) {',
'    return track == CAVALIER_TRACK_UPPER',
'        ? 3 : 1;',
'}',
'',
'// ---- Table I: the dice maxima (notes 3',
'// and 6) and the druid limit ----',
'inline int rangerMaxHitDice()',
'    { return 11; }',
'inline int rangerMaxHitDiceLevel()',
'    { return 10; }',
'inline int monkMaxHitDice()',
'    { return 18; }',
'inline int monkMaxHitDiceLevel()',
'    { return 17; }',
'',
'// The druid Class Level Limit (Table I:',
'// 23, Hierophant of the Cabal).',
'inline int druidClassLevelLimit()',
'    { return 23; }',
'',
'// ---- Table I, the spell-ability legs',
'// (notes 2, 4 and 5) ----',
'// Paladin: clerical spells from the 9th,',
'// up to 4th level of power.',
'inline int paladinClericalFromLevel()',
'    { return 9; }',
'inline int paladinClericalMaxSpellLevel()',
'    { return 4; }',
'',
'// Ranger: druidic from the 8th up to 3rd;',
'// magic-user from the 9th up to 2nd.',
'inline int rangerDruidicFromLevel()',
'    { return 8; }',
'inline int rangerDruidicMaxSpellLevel()',
'    { return 3; }',
'inline int rangerMuFromLevel()',
'    { return 9; }',
'inline int rangerMuMaxSpellLevel()',
'    { return 2; }',
'',
'// Thief 10th and assassin 12th: the',
'// scroll-reading ability (note 5).',
'inline int thiefScrollFromLevel()',
'    { return 10; }',
'inline int assassinScrollFromLevel()',
'    { return 12; }',
'',
'// ---- Table II, the footnotes ----',
'// Footnote 1: the cavalier and paladin',
'// will not wear leather, padded or',
'// studded leather armor (beneath the',
'// station), and will not use pole arms',
'// or missile weapons (the lower social',
'// classes).',
'inline bool uaStationArmorBan(UaClass c) {',
'    return c == UACLASS_CAVALIER',
'        || c == UACLASS_PALADIN;',
'}',
'',
'inline bool uaStationWeaponBan(',
'        UaClass c) {',
'    return c == UACLASS_CAVALIER',
'        || c == UACLASS_PALADIN;',
'}',
'',
'// Footnote 2: oil is unacceptable to',
'// the cavalier and paladin in personal',
'// combat, but allowed in siege warfare.',
'inline bool uaOilSiegeException(',
'        UaClass c) {',
'    return c == UACLASS_CAVALIER',
'        || c == UACLASS_PALADIN;',
'}',
'',
'// The acrobat row: armor and weapons as',
'// thief, plus lasso and staff.',
'inline int acrobatExtraWeaponCount()',
'    { return 2; }',
'inline const char* acrobatExtraWeaponName(',
'        int i) {',
'    static const char* const k[2] = {',
'        "lasso", "staff"',
'    };',
'    if (i < 0) i = 0;',
'    if (i > 1) i = 1;',
'    return k[i];',
'}',
'',
'}   // namespace rules',
    ])
    clean(HDR, 78)
    wr(CT, HDR)
    applied.append('classtables.h: the pins')
s = rd(CT)
assert s.count('namespace rules {') == 1, 'b namespace'
assert s.count('uaClassHitDie') == 1, 'b hit die fn'
assert s.count('cavalierTrackDice') == 1, 'b track fn'
assert s.count('druidClassLevelLimit') == 1, 'b druid fn'
assert s.count('uaStationArmorBan') == 1, 'b station fn'
assert s.count('acrobatExtraWeaponName') == 1, 'b acrobat'
assert 'SUB_COUNT' not in s, 'b no SUB_COUNT'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'CLOSED R327' in s:
    already.append('gap report: the close')
else:
    OLD = NL.join([
    '- [ ] **Classes Table I** (p. 12, the',
    '      hit dice and level limits: cavalier',
    '      d10, barbarian d12, ranger 2d8,',
    '      monk 2d4, druid limit 23 hierophant)',
    '      and **Table II** (p. 13, the armor',
    '      and weapons permitted per class,',
    '      with the cavalier/paladin station',
    '      notes) - both read clean; the',
    '      registry is data-driven (append the',
    '      rows).'])
    NEW = NL.join([
    '- [x] **Classes Table I** (p. 12, the',
    '      hit dice and level limits: cavalier',
    '      d10, barbarian d12, ranger 2d8,',
    '      monk 2d4, druid limit 23 hierophant)',
    '      and **Table II** (p. 13, the armor',
    '      and weapons permitted per class,',
    '      with the cavalier/paladin station',
    '      notes) - CLOSED R327: the pin round',
    '      (rules/classtables.h): the',
    '      hit-die column with the two-dice',
    '      first levels, the note-1',
    '      social-standing generators (3d4+1',
    '      or d10+3), the ranger 11-dice and',
    '      monk 18-dice maxima, the druid 23,',
    '      the spell-ability legs (paladin',
    '      clerical 9th-4th, ranger druidic',
    '      8th-3rd and MU 9th-2nd, the thief',
    '      10th and assassin 12th scroll',
    '      reads), the Table II footnotes',
    '      (the station armor and weapon',
    '      bans, the oil siege exception,',
    '      the acrobat as-thief-plus row);',
    '      the weapon and oil/poison columns',
    '      ride the landed R198/R199 pins;',
    '      the cavalier and barbarian level',
    '      ladders ride their own class',
    '      rounds; the R327 audit (census',
    '      254).'])
    assert s.count(OLD) == 1, 'c anchor'
    clean(NEW, 57)
    s = s.replace(OLD, NEW)
    wr(GP, s)
    applied.append('gap report: the close')
s = rd(GP)
assert s.count('CLOSED R327') == 1, 'c close'
assert s.count('CLOSED R326') == 1, 'c r326 kept'
assert s.count('CLOSED R325') == 1, 'c r325 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R327 class tables pin audit' in s:
    already.append('regtest.cpp: the R327 audit')
else:
    INC_ANCH = ('#include "rules/subracecap.h"'
                '  // R325: UA Race Table II fold')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/classtables.h"'
    '  // R327: UA Classes Tables I-II'])
    STD_ANCH = '#include <cstdio>'
    STD_NEW = NL.join([
    STD_ANCH,
    '#include <cstring>  // R327: the'
    ' acrobat name reads'])
    assert s.count(STD_ANCH) == 1, 'd std anchor'
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
'    // ---- R327: the class tables pin',
'    // audit ----',
'    // UA Character Classes Table I',
'    // (p. 12) and Table II (p. 13) - the',
'    // pin-era pattern: the hit-die',
'    // column, the first-level dice, the',
'    // note-1 social-standing generators,',
'    // the dice maxima, the druid 23, the',
'    // spell-ability legs, the Table II',
'    // footnotes; the R230 registry rows',
'    // cross-checked (the ranger and',
'    // monk dice already carried).',
'    {',
'        using namespace rules;',
'        int bad = 0;',
'        // U1: the hit-die column',
'        {',
'            if (uaClassHitDie(',
'                UACLASS_CAVALIER) != 10) ++bad;',
'            if (uaClassHitDie(',
'                UACLASS_BARBARIAN) != 12) ++bad;',
'            if (uaClassHitDie(',
'                UACLASS_RANGER) != 8) ++bad;',
'            if (uaClassHitDie(',
'                UACLASS_MONK) != 4) ++bad;',
'        }',
'        // U2: the first-level dice',
'        {',
'            if (uaClassFirstLevelDice(',
'                UACLASS_RANGER) != 2) ++bad;',
'            if (uaClassFirstLevelDice(',
'                UACLASS_MONK) != 2) ++bad;',
'            if (uaClassFirstLevelDice(',
'                UACLASS_CAVALIER) != 1) ++bad;',
'            if (uaClassFirstLevelDice(',
'                UACLASS_BARBARIAN) != 1) ++bad;',
'        }',
'        // U3: the registry cross-check',
'        // (the R230 rows carry the dice)',
'        {',
'            const SubclassDef& rg =',
'                subclassDef(SUB_RANGER);',
'            if (rg.hitDie != 8) ++bad;',
'            if (rg.twoDiceFirstLevel != 1)',
'                ++bad;',
'            const SubclassDef& mk =',
'                subclassDef(SUB_MONK);',
'            if (mk.hitDie != 4) ++bad;',
'            if (mk.twoDiceFirstLevel != 1)',
'                ++bad;',
'            if (mk.levelCap != 17) ++bad;',
'        }',
'        // U4: the note-1 generators -',
'        // both tracks yield the printed',
'        // 4-13 range (3d4+1, d10+3)',
'        {',
'            if (cavalierTrackDice(',
'                CAVALIER_TRACK_ZERO) != 3)',
'                ++bad;',
'            if (cavalierTrackSides(',
'                CAVALIER_TRACK_ZERO) != 4)',
'                ++bad;',
'            if (cavalierTrackBonus(',
'                CAVALIER_TRACK_ZERO) != 1)',
'                ++bad;',
'            if (cavalierTrackDice(',
'                CAVALIER_TRACK_UPPER) != 1)',
'                ++bad;',
'            if (cavalierTrackSides(',
'                CAVALIER_TRACK_UPPER) != 10)',
'                ++bad;',
'            if (cavalierTrackBonus(',
'                CAVALIER_TRACK_UPPER) != 3)',
'                ++bad;',
'            if (3*1 + 1 < 4',
'                || 3*4 + 1 > 13) ++bad;',
'            if (1*1 + 3 < 4',
'                || 1*10 + 3 > 13) ++bad;',
'        }',
'        // U5: the maxima and the limit',
'        {',
'            if (rangerMaxHitDice() != 11)',
'                ++bad;',
'            if (rangerMaxHitDiceLevel() != 10)',
'                ++bad;',
'            if (monkMaxHitDice() != 18)',
'                ++bad;',
'            if (monkMaxHitDiceLevel() != 17)',
'                ++bad;',
'            if (druidClassLevelLimit() != 23)',
'                ++bad;',
'        }',
'        // U6: the spell-ability legs',
'        {',
'            if (paladinClericalFromLevel()',
'                != 9) ++bad;',
'            if (paladinClericalMaxSpellLevel()',
'                != 4) ++bad;',
'            if (rangerDruidicFromLevel()',
'                != 8) ++bad;',
'            if (rangerDruidicMaxSpellLevel()',
'                != 3) ++bad;',
'            if (rangerMuFromLevel()',
'                != 9) ++bad;',
'            if (rangerMuMaxSpellLevel()',
'                != 2) ++bad;',
'            if (thiefScrollFromLevel()',
'                != 10) ++bad;',
'            if (assassinScrollFromLevel()',
'                != 12) ++bad;',
'        }',
'        // U7: the Table II footnotes',
'        {',
'            if (!uaStationArmorBan(',
'                UACLASS_CAVALIER)) ++bad;',
'            if (!uaStationArmorBan(',
'                UACLASS_PALADIN)) ++bad;',
'            if (uaStationArmorBan(',
'                UACLASS_FIGHTER)) ++bad;',
'            if (!uaStationWeaponBan(',
'                UACLASS_CAVALIER)) ++bad;',
'            if (!uaStationWeaponBan(',
'                UACLASS_PALADIN)) ++bad;',
'            if (uaStationWeaponBan(',
'                UACLASS_RANGER)) ++bad;',
'            if (!uaOilSiegeException(',
'                UACLASS_CAVALIER)) ++bad;',
'            if (!uaOilSiegeException(',
'                UACLASS_PALADIN)) ++bad;',
'            if (uaOilSiegeException(',
'                UACLASS_THIEF)) ++bad;',
'        }',
'        // U8: the acrobat as-thief-plus',
'        // row',
'        {',
'            if (acrobatExtraWeaponCount()',
'                != 2) ++bad;',
'            if (strcmp(acrobatExtraWeaponName(0),',
'                "lasso") != 0) ++bad;',
'            if (strcmp(acrobatExtraWeaponName(1),',
'                "staff") != 0) ++bad;',
'        }',
'        printf("R327 class tables pin audit: bad %d\\n", bad);',
'        if (bad) return 1;',
'    }',
    ])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(STD_ANCH, STD_NEW)
    s = s.replace(AUD_ANCH, AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R327 audit')
s = rd(RT)
assert s.count(
    'R327 class tables pin audit: bad ') == 1, \
    'd audit line'
assert s.count('audit: bad ') == 254, 'd census 254'
assert s.count(
    'R326 subrace creation audit') == 1, 'd r326 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count('classtables.h') == 1, 'd include refs'
assert s.count('#include <cstring>') == 1, \
    'd cstring'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R327 splice: ALL OK (applied %d,'
      ' already %d)'
      % (len(applied), len(already)))
print('R327 note: the UA Classes Tables I and')
print('II pin round - the hit-die column,')
print('the two-dice first levels, the note-1')
print('social-standing generators, the ranger')
print('11-dice and monk 18-dice maxima, the')
print('druid 23, the spell-ability legs, the')
print('station and oil footnotes, the acrobat')
print('row; the battery census 253 -> 254')
print('commit: R327: the UA Classes Tables I')
print('and II pin round (census 254)')

