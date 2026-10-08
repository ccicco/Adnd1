#!/usr/bin/env python3
# R253 splice: the III.C rings explanation prose pins,
# part 1 of 3.
#
# DMG pp.137-138, upload lines ~10281-10392 - the III.C
# RINGS explanation prose, part 1: the general ring
# mechanics and the four lead rings (the III.B scrolls
# arc closed at R252). The mechanics: max 2 rings worn
# (if more are worn none function), max 1 per hand (a
# 2nd makes both useless); spell-like abilities
# function as 12th level of magic use; gnomes, dwarves
# and halflings have a 20% per-use malfunction chance
# (the 3 cursed rings named: contrariness, delusion,
# weakness); the double-dagger symbol marks the most
# powerful rings, often with limited charges at the
# DM option. Ring of Contrariness: removable only via
# remove curse; the 6-band additional-properties table
# (01-20 Flying, 21-40 Invisibility, 41-60 Levitation,
# 61-70 Shocking Grasp once per round, 71-80 Spell
# Turning, 81-00 Strength 18/00); a cumulative remove
# curse must equal or exceed 00 (100%). Ring of
# Delusion: removable at any time. Ring of Djinni
# Summoning: the djinni appears the next round; a
# killed servant makes the ring non-magical and
# worthless. Ring of Elemental Command: 4 types;
# elementals cannot approach within 5 feet (or a charm
# attempt, elemental saving throw at -2); plane
# creatures attack at -1, the wearer takes damage at
# -1 per hit die, saves at +2, attacks at +4 (or
# elemental saves at -4), does +6 damage total; the
# 4-plane save penalty list (Air fire, Earth
# petrification, Fire water or cold, Water
# lightning/electricity - all -2); only one power at a
# time; the four power lists: Air 5 (gust of wind once
# per round, fly, wall of force once per day, control
# winds once per week, invisibility), Earth 6 (stone
# tell once per day, passwall twice per day, wall of
# stone once per day, stone to flesh twice per week,
# move earth once per week, feather fall), Fire 5
# (burning hands once per turn, pyrotechnics twice per
# day, wall of fire once per day, flame strike twice
# per week, fire resistance), Water 8 (purify water,
# create water once per day, water breathing with a 5
# foot radius, wall of ice once per day, airy water,
# lower water twice per week, part water twice per
# week, water walking); the rings appear as the lesser
# rings (invisibility, feather falling, fire
# resistance, water walking) until a condition is met.
# Closing: rings operate at 12th level of experience;
# additional powers take 5 segments to bring forth.
# The four rings are the engine III.C table rows 1-15
# (dm/treasure.cpp kRings, the R223 rings.h band pins)
# - cross-checked in the audit; the djinni
# double-dagger cross-pins the R223 ringIsChargeLimited
# row 2. Patches: 4 (new rules/ringsprose.h, the
# regtest include, the audit block, the dmg-gap-report
# log entry). Census 171 -> 172.
#
# commit: R253: the III.C rings explanation prose part 1 pinned - DMG pp.137-138, the general mechanics and the four lead rings (census 172)

import sys

WD   = 'rules/ringsprose.h'
REG  = 'regtest.cpp'
GAP  = 'tools/dmg_gap_report.md'

NL = chr(10)
BS = chr(92)

# pre-checks - pristine OR fully-patched (the R234
# two-state lesson); NO already-closed pre-check
# (the R235b lesson, re-caught at R237)
t = open(REG).read()
if t.count('audit: bad ') != 171 and t.count('audit: bad ') != 172:
    print('R253 FAIL: regtest census is neither 171 nor 172')
    sys.exit(1)

# ---- the new header ----
hdr_lines = [
    '// ====================================================================',
    '// Adnd1 - rules/ringsprose.h',
    '// R253: the III.C rings explanation prose',
    '// pins, part 1 of 3 (DMG pp.137-138) - the',
    '// general ring mechanics and the four lead',
    '// rings of the EXPLANATIONS AND',
    '// DESCRIPTIONS section (upload lines',
    '// ~10281-10392):',
    '//   - mechanics: max 2 rings worn (if more',
    '//     are worn none function), max 1 per',
    '//     hand (a 2nd makes both useless);',
    '//     spell-like abilities function as',
    '//     12th level of magic use; gnomes,',
    '//     dwarves and halflings have a 20%',
    '//     per-use malfunction chance (the',
    '//     three cursed rings named:',
    '//     contrariness, delusion, weakness);',
    '//     the double-dagger symbol marks the',
    '//     most powerful rings, often with',
    '//     limited charges at the DM option.',
    '//   - Ring of Contrariness: removable',
    '//     only via remove curse; the',
    '//     6-band additional-properties table',
    '//     (01-20 Flying, 21-40 Invisibility,',
    '//     41-60 Levitation, 61-70 Shocking',
    '//     Grasp once per round, 71-80 Spell',
    '//     Turning, 81-00 Strength 18/00);',
    '//     a cumulative remove curse must',
    '//     equal or exceed 00 (100%).',
    '//   - Ring of Delusion: removable at any',
    '//     time.',
    '//   - Ring of Djinni Summoning: the',
    '//     djinni appears the next round; a',
    '//     killed servant makes the ring',
    '//     non-magical and worthless.',
    '//   - Ring of Elemental Command: 4',
    '//     types; elementals cannot approach',
    '//     within 5 feet (or a charm attempt,',
    '//     elemental saving throw at -2);',
    '//     plane creatures attack at -1, the',
    '//     wearer takes damage at -1 per hit',
    '//     die, saves at +2, attacks at +4',
    '//     (or elemental saves at -4), does',
    '//     +6 damage total; the 4-plane save',
    '//     penalty list (all -2); only one',
    '//     power at a time; the four power',
    '//     lists: Air 5 (gust of wind once per',
    '//     round, fly, wall of force once per',
    '//     day, control winds once per week,',
    '//     invisibility), Earth 6 (stone tell',
    '//     once per day, passwall twice per',
    '//     day, wall of stone once per day,',
    '//     stone to flesh twice per week,',
    '//     move earth once per week, feather',
    '//     fall), Fire 5 (burning hands once',
    '//     per turn, pyrotechnics twice per',
    '//     day, wall of fire once per day,',
    '//     flame strike twice per week, fire',
    '//     resistance), Water 8 (purify',
    '//     water, create water once per day,',
    '//     water breathing with a 5 foot',
    '//     radius, wall of ice once per day,',
    '//     airy water, lower water twice per',
    '//     week, part water twice per week,',
    '//     water walking); the rings appear',
    '//     as the lesser rings (invisibility,',
    '//     feather falling, fire resistance,',
    '//     water walking) until a condition',
    '//     is met.',
    '//   - closing: rings operate at 12th',
    '//     level of experience; additional',
    '//     powers take 5 segments to bring',
    '//     forth.',
    '// The four rings are the engine III.C',
    '// table rows 1-15 (dm/treasure.cpp',
    '// kRings, the R223 rings.h band pins) -',
    '// cross-checked in the audit; the djinni',
    '// double-dagger cross-pins the R223',
    '// ringIsChargeLimited row 2. Pure data',
    '// + helpers, header-only (the grenade.h',
    '// pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int rgpMaxWornCount() {',
    '    // no more than 2 magic rings can be',
    '    // worn at once; if more are worn',
    '    // then none will function',
    '    return 2;',
    '}',
    '',
    'inline int rgpMaxPerHand() {',
    '    // no more than 1 per hand; a 2nd',
    '    // will cause both to be useless',
    '    return 1;',
    '}',
    '',
    'inline int rgpSpellLikeLevel() {',
    '    // spell-like abilities function as',
    '    // 12th level of magic use unless',
    '    // the power requires higher',
    '    return 12;',
    '}',
    '',
    'inline int rgpSmallCharMalfunctionPercent() {',
    '    // rings worn by gnomes, dwarves',
    '    // and halflings malfunction 20%',
    '    // per use (the ring does not work)',
    '    return 20;',
    '}',
    '',
    'inline int rgpCursedMalfunctionNamedCount() {',
    '    // the cursed rings the malfunction',
    '    // rule names: contrariness,',
    '    // delusion, weakness',
    '    return 3;',
    '}',
    '',
    'inline int rgpContrarinessPropertyRowCount() {',
    '    // the additional-properties table:',
    '    // 6 die bands',
    '    return 6;',
    '}',
    '',
    'inline int rgpContrarinessPropLo(int i) {',
    '    // the band lower edges: 01-20 Flying,',
    '    // 21-40 Invisibility, 41-60',
    '    // Levitation, 61-70 Shocking Grasp',
    '    // once per round, 71-80 Spell',
    '    // Turning, 81-00 Strength 18/00;',
    '    // i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        1, 21, 41, 61, 71, 81,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rgpContrarinessPropHi(int i) {',
    '    // the band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        20, 40, 60, 70, 80, 100,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rgpContrarinessShockingGraspPerRound() {',
    '    // the 61-70 property: shocking',
    '    // grasp once per round',
    '    return 1;',
    '}',
    '',
    'inline int rgpContrarinessStrengthScore() {',
    '    // the 81-00 property: strength',
    '    // 18/00',
    '    return 18;',
    '}',
    '',
    'inline int rgpContrarinessRemoveCursePercent() {',
    '    // a cumulative remove curse must',
    '    // equal or exceed 00 (100%)',
    '    return 100;',
    '}',
    '',
    'inline int rgpDjinniAppearDelayRounds() {',
    '    // when the ring is rubbed the',
    '    // djinni will appear on the next',
    '    // round',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandTypeCount() {',
    '    // the 4 types of elemental',
    '    // command rings',
    '    return 4;',
    '}',
    '',
    'inline int rgpElemCommandKeepAwayFeet() {',
    '    // attuned elementals cannot',
    '    // approach within 5 feet of or',
    '    // attack the wearer',
    '    return 5;',
    '}',
    '',
    'inline int rgpElemCommandCharmSaveMod() {',
    '    // the alternative charm attempt:',
    '    // elemental saving throw at -2',
    '    // on the die',
    '    return -2;',
    '}',
    '',
    'inline int rgpElemCommandElemToHitMod() {',
    '    // plane creatures other than normal',
    '    // elementals attack at -1 on',
    '    // to hit',
    '    return -1;',
    '}',
    '',
    'inline int rgpElemCommandWearerDamagePerDieMod() {',
    '    // the wearer takes damage at -1',
    '    // on each hit die',
    '    return -1;',
    '}',
    '',
    'inline int rgpElemCommandWearerSaveBonus() {',
    '    // the wearer makes applicable',
    '    // saves at +2',
    '    return 2;',
    '}',
    '',
    'inline int rgpElemCommandWearerToHitBonus() {',
    '    // wearer attacks at +4 to hit',
    '    return 4;',
    '}',
    '',
    'inline int rgpElemCommandElemSaveMod() {',
    '    // or -4 on the elemental',
    '    // creature saving throw',
    '    return -4;',
    '}',
    '',
    'inline int rgpElemCommandWearerDamageBonus() {',
    '    // the wearer does +6 damage',
    '    // (total, not per die)',
    '    return 6;',
    '}',
    '',
    'inline int rgpElemCommandSavePenaltyRowCount() {',
    '    // the 4-plane save penalty list:',
    '    // Air fire, Earth petrification,',
    '    // Fire water or cold, Water',
    '    // lightning/electricity',
    '    return 4;',
    '}',
    '',
    'inline int rgpElemCommandSavePenalty(int i) {',
    '    // every plane penalty is -2;',
    '    // i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 3) i = 3;',
    '    static const int t[4] = {',
    '        -2, -2, -2, -2,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int rgpElemCommandMaxActivePowers() {',
    '    // only one power (major or minor)',
    '    // can be in use at one time',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandAirPowerCount() {',
    '    // gust of wind, fly, wall of',
    '    // force, control winds,',
    '    // invisibility',
    '    return 5;',
    '}',
    '',
    'inline int rgpElemCommandEarthPowerCount() {',
    '    // stone tell, passwall, wall of',
    '    // stone, stone to flesh,',
    '    // move earth, feather fall',
    '    return 6;',
    '}',
    '',
    'inline int rgpElemCommandFirePowerCount() {',
    '    // burning hands, pyrotechnics,',
    '    // wall of fire, flame strike,',
    '    // fire resistance',
    '    return 5;',
    '}',
    '',
    'inline int rgpElemCommandWaterPowerCount() {',
    '    // purify water, create water,',
    '    // water breathing, wall of ice,',
    '    // airy water, lower water,',
    '    // part water, water walking',
    '    return 8;',
    '}',
    '',
    'inline int rgpElemCommandAirGustPerRound() {',
    '    // gust of wind once per round',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandWallOfForcePerDay() {',
    '    // wall of force once per day',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandControlWindsPerWeek() {',
    '    // control winds once per week',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandStoneTellPerDay() {',
    '    // stone tell once per day',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandPasswallPerDay() {',
    '    // passwall twice per day',
    '    return 2;',
    '}',
    '',
    'inline int rgpElemCommandWallOfStonePerDay() {',
    '    // wall of stone once per day',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandStoneToFleshPerWeek() {',
    '    // stone to flesh twice per week',
    '    return 2;',
    '}',
    '',
    'inline int rgpElemCommandMoveEarthPerWeek() {',
    '    // move earth once per week',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandBurningHandsPerTurn() {',
    '    // burning hands once per turn',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandPyrotechnicsPerDay() {',
    '    // pyrotechnics twice per day',
    '    return 2;',
    '}',
    '',
    'inline int rgpElemCommandWallOfFirePerDay() {',
    '    // wall of fire once per day',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandFlameStrikePerWeek() {',
    '    // flame strike twice per week',
    '    return 2;',
    '}',
    '',
    'inline int rgpElemCommandCreateWaterPerDay() {',
    '    // create water once per day',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandWallOfIcePerDay() {',
    '    // wall of ice once per day',
    '    return 1;',
    '}',
    '',
    'inline int rgpElemCommandLowerWaterPerWeek() {',
    '    // lower water twice per week',
    '    return 2;',
    '}',
    '',
    'inline int rgpElemCommandPartWaterPerWeek() {',
    '    // part water twice per week',
    '    return 2;',
    '}',
    '',
    'inline int rgpElemCommandWaterBreathingRadiusFeet() {',
    '    // water breathing with a 5 foot',
    '    // radius',
    '    return 5;',
    '}',
    '',
    'inline int rgpOperateLevelExperience() {',
    '    // rings operate at 12th level of',
    '    // experience, or the minimum',
    '    // level needed for the spell',
    '    return 12;',
    '}',
    '',
    'inline int rgpPowerActivationSegments() {',
    '    // the additional powers take only',
    '    // 5 segments to bring forth',
    '    return 5;',
    '}',
    '',
    '}  // namespace rules',
    '',
]
hdr_text = NL.join(hdr_lines) + NL

# ---- the regtest include ----
inc_old = [
    '#include "rules/scrollsprose.h"  // R252: pp.137-139 the III.B scrolls explanation prose pins',
]
inc_new = [
    '#include "rules/scrollsprose.h"  // R252: pp.137-139 the III.B scrolls explanation prose pins',
    '#include "rules/ringsprose.h"  // R253: pp.137-138 the III.C rings explanation prose part 1 pins',
]

# ---- the regtest audit block ----
audit_old = [
    '    // ---- R227: the wis mental save wiring audit ----',
]
audit_new = [
    '    // ---- R253: the III.C rings explanation prose pins audit ----',
    '    // DMG pp.137-138: the general mechanics and',
    '    // the four lead rings (part 1 of 3).',
    '    {',
    '        int bad = 0;',
    '        // the four lead rings are the engine III.C',
    '        // table rows 1-15 (the R223 rings.h pins)',
    '        if (rules::ringRowCount() != 24 ||',
    '            rules::ringRowLo(0) != 1 || rules::ringRowHi(0) != 6 ||',
    '            rules::ringRowLo(3) != 15 || rules::ringRowHi(3) != 15) ++bad;',
    '        static const int kCLo[4] = {',
    '            1, 7, 13, 15,',
    '        };',
    '        static const int kCHi[4] = {',
    '            6, 12, 14, 15,',
    '        };',
    '        for (int i = 0; i < 4; ++i)',
    '            if (rules::ringRowLo(i) != kCLo[i] ||',
    '                rules::ringRowHi(i) != kCHi[i]) ++bad;',
    '        // the djinni double-dagger: the prose flag',
    '        // cross-pins the R223 charge-limited row 2',
    '        if (rules::ringIsChargeLimited(2) != 1 ||',
    '            rules::ringChargeLimitedCount() != 7) ++bad;',
    '        // the contrariness additional-properties bands',
    '        static const int kPLo[6] = {',
    '            1, 21, 41, 61, 71, 81,',
    '        };',
    '        static const int kPHi[6] = {',
    '            20, 40, 60, 70, 80, 100,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::rgpContrarinessPropLo(i) != kPLo[i] ||',
    '                rules::rgpContrarinessPropHi(i) != kPHi[i]) ++bad;',
    '        // the elemental command save penalty list',
    '        static const int kPen[4] = {',
    '            -2, -2, -2, -2,',
    '        };',
    '        for (int i = 0; i < 4; ++i)',
    '            if (rules::rgpElemCommandSavePenalty(i) != kPen[i]) ++bad;',
    '        // the general mechanics',
    '        if (rules::rgpMaxWornCount() != 2 ||',
    '            rules::rgpMaxPerHand() != 1 ||',
    '            rules::rgpSpellLikeLevel() != 12 ||',
    '            rules::rgpSmallCharMalfunctionPercent() != 20 ||',
    '            rules::rgpCursedMalfunctionNamedCount() != 3) ++bad;',
    '        // the closing paragraph cross-pins the level',
    '        if (rules::rgpOperateLevelExperience() !=',
    '            rules::rgpSpellLikeLevel() ||',
    '            rules::rgpPowerActivationSegments() != 5) ++bad;',
    '        // contrariness and djinni',
    '        if (rules::rgpContrarinessPropertyRowCount() != 6 ||',
    '            rules::rgpContrarinessShockingGraspPerRound() != 1 ||',
    '            rules::rgpContrarinessStrengthScore() != 18 ||',
    '            rules::rgpContrarinessRemoveCursePercent() != 100 ||',
    '            rules::rgpDjinniAppearDelayRounds() != 1) ++bad;',
    '        // elemental command: the combat modifications',
    '        if (rules::rgpElemCommandTypeCount() != 4 ||',
    '            rules::rgpElemCommandKeepAwayFeet() != 5 ||',
    '            rules::rgpElemCommandCharmSaveMod() != -2 ||',
    '            rules::rgpElemCommandElemToHitMod() != -1 ||',
    '            rules::rgpElemCommandWearerDamagePerDieMod() != -1 ||',
    '            rules::rgpElemCommandWearerSaveBonus() != 2 ||',
    '            rules::rgpElemCommandWearerToHitBonus() != 4 ||',
    '            rules::rgpElemCommandElemSaveMod() != -4 ||',
    '            rules::rgpElemCommandWearerDamageBonus() != 6 ||',
    '            rules::rgpElemCommandSavePenaltyRowCount() != 4 ||',
    '            rules::rgpElemCommandMaxActivePowers() != 1) ++bad;',
    '        // elemental command: the four power lists',
    '        if (rules::rgpElemCommandAirPowerCount() != 5 ||',
    '            rules::rgpElemCommandEarthPowerCount() != 6 ||',
    '            rules::rgpElemCommandFirePowerCount() != 5 ||',
    '            rules::rgpElemCommandWaterPowerCount() != 8) ++bad;',
    '        // elemental command: the power frequencies',
    '        if (rules::rgpElemCommandAirGustPerRound() != 1 ||',
    '            rules::rgpElemCommandWallOfForcePerDay() != 1 ||',
    '            rules::rgpElemCommandControlWindsPerWeek() != 1 ||',
    '            rules::rgpElemCommandStoneTellPerDay() != 1 ||',
    '            rules::rgpElemCommandPasswallPerDay() != 2 ||',
    '            rules::rgpElemCommandWallOfStonePerDay() != 1 ||',
    '            rules::rgpElemCommandStoneToFleshPerWeek() != 2 ||',
    '            rules::rgpElemCommandMoveEarthPerWeek() != 1 ||',
    '            rules::rgpElemCommandBurningHandsPerTurn() != 1 ||',
    '            rules::rgpElemCommandPyrotechnicsPerDay() != 2 ||',
    '            rules::rgpElemCommandWallOfFirePerDay() != 1 ||',
    '            rules::rgpElemCommandFlameStrikePerWeek() != 2 ||',
    '            rules::rgpElemCommandCreateWaterPerDay() != 1 ||',
    '            rules::rgpElemCommandWallOfIcePerDay() != 1 ||',
    '            rules::rgpElemCommandLowerWaterPerWeek() != 2 ||',
    '            rules::rgpElemCommandPartWaterPerWeek() != 2 ||',
    '            rules::rgpElemCommandWaterBreathingRadiusFeet() != 5) ++bad;',
    '        printf("R253 rings prose pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
]

# ---- the dmg-gap-report log entry ----
gap_old = [
    'New R252',
    'battery audit; census 171. Next:',
    'the rings explanations (upload',
    '~10282-10561, likely 3 parts),',
    'then the misc magic item',
    'explanations III.E (part1 ~10948-',
    '11067 continuing seamlessly into',
    'part2; global line = part1 line or',
    '~11065 + part2 line, the TREASURE',
    '(MISCELLANEOUS MAGIC) headers are',
    'running page headers mid-paragraph).',
]
gap_new = [
    'New R252',
    'battery audit; census 171. Next:',
    'the rings explanations (upload',
    '~10282-10561, likely 3 parts),',
    'then the misc magic item',
    'explanations III.E (part1 ~10948-',
    '11067 continuing seamlessly into',
    'part2; global line = part1 line or',
    '~11065 + part2 line, the TREASURE',
    '(MISCELLANEOUS MAGIC) headers are',
    'running page headers mid-paragraph).',
    '',
    'R253 landed the III.C rings',
    'explanation prose part 1 of 3',
    '(DMG pp.137-138, upload lines',
    '~10281-10392) - the general ring',
    'mechanics and the four lead',
    'rings: Contrariness, Delusion,',
    'Djinni Summoning, Elemental',
    'Command. rules/ringsprose.h (the',
    'grenade.h pattern, the rgp',
    'prefix - distinct from the R223',
    'ring prefix - 47 accessors, of',
    'which 3 are array walkers): max',
    '2 rings worn (none function if',
    'more), 1 per hand, 12th level of',
    'magic use, 20% malfunction for',
    'gnomes/dwarves/halflings, the 3',
    'cursed rings named (contrariness,',
    'delusion, weakness), the',
    'double-dagger charge note;',
    'Contrariness (the 6-band',
    'additional-properties table',
    '01-20 Flying through 81-00',
    'Strength 18/00, shocking grasp',
    'once per round, cumulative remove',
    'curse 00 = 100%); Delusion',
    '(removable at any time); Djinni',
    'Summoning (the djinni appears',
    'the next round, a killed servant',
    'makes the ring worthless);',
    'Elemental Command (4 types,',
    'elementals kept 5 feet away,',
    'charm attempt save -2, plane',
    'creatures attack at -1, wearer',
    'damage -1 per hit die, wearer',
    'saves +2, wearer attacks +4 or',
    'elemental saves -4, wearer',
    'damage +6 total, the 4-plane save',
    'penalty list all -2, only one',
    'power at a time, the four power',
    'lists - Air 5, Earth 6, Fire 5,',
    'Water 8 - with the once/twice',
    'per round/turn/day/week',
    'frequencies, water breathing 5',
    'foot radius, the four lesser-ring',
    'disguises, additional powers 5',
    'segments). Engine cross-check:',
    'the four kRings rows 1-15 vs the',
    'R223 rings.h band edges, djinni',
    'double-dagger vs',
    'ringIsChargeLimited row 2. The',
    'TREASURE (RINGS) running page',
    'header splits the Earth power',
    'list mid-list (upload ~10369),',
    'stripped by the ground truth per',
    'the R249 page-header lesson; the',
    'plane anchors mix hyphen and em',
    'dashes. New R253 battery audit;',
    'census 172. Next: part 2 (upload',
    '~10393-10457, Feather Falling',
    'through Shooting Stars), then',
    'part 3 (~10458-10561, Spell',
    'Storing through X-Ray Vision),',
    'then the misc magic item',
    'explanations III.E (part1',
    '~10948-11067 continuing',
    'seamlessly into part2; global',
    'line = part1 line or ~11065 +',
    'part2 line, the TREASURE',
    '(MISCELLANEOUS MAGIC) headers',
    'are running page headers',
    'mid-paragraph).',
]

applied = 0
already = 0

# the created-file patch (marker-based idempotence,
# the R228 lesson; the marker MUST be contiguous in
# the header text - the R247 lesson, re-caught at
# R252)
marker = 'R253: the III.C rings explanation prose'
try:
    t = open(WD).read()
    if marker in t:
        already += 1
    else:
        print('R253 FAIL: rules/ringsprose.h exists without the marker')
        sys.exit(1)
except IOError:
    with open(WD, 'w') as f:
        f.write(hdr_text)
    applied += 1

for path, mark, old, new in [
    (REG, 'the regtest include', inc_old, inc_new),
    (REG, 'the R253 audit', audit_old, audit_new),
    (GAP, 'the R253 log entry', gap_old, gap_new),
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
        print('R253 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 4:
    t = open(REG).read()
    if t.count('audit: bad ') != 172:
        print('R253 FAIL: census is not 172')
        sys.exit(1)
    if t.count('R253 rings prose pins audit') != 1:
        print('R253 FAIL: the R253 audit line must appear once')
        sys.exit(1)
    if t.count('rules/ringsprose.h') != 1:
        print('R253 FAIL: the ringsprose include must appear once')
        sys.exit(1)
    g = open(GAP).read()
    if g.count('R253 landed the III.C rings') != 1:
        print('R253 FAIL: the dmg log entry is missing')
        sys.exit(1)
    h = open(WD).read()
    if 'namespace rules' not in h or h.count('inline int rgp') != 47:
        print('R253 FAIL: the header shape is wrong')
        sys.exit(1)

print('R253 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R253 note: 4 patches; the III.C rings explanation prose part 1 -')
print('the mechanics and the four lead rings; census 172.')
print('commit: R253: the III.C rings explanation prose part 1 pinned - DMG pp.137-138, the general mechanics and the four lead rings (census 172)')

