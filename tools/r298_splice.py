#!/usr/bin/env python3
# tools/r298_splice.py - R298: the thief
# function take table and DEXTERITY TABLE II
# pinned - a DATA-ONLY round (the R186
# poetics precedent).
#
# The LAST open phb ledger item (the R296
# scope round named it the R298 candidate):
# the Thief Function Take table (the THIEF
# section, upload line 1620) - the base
# chances of the eight functions at thief
# levels 1 through 17, with the six racial
# adjustment rows beneath (upload lines
# 1645-1650) - and DEXTERITY TABLE II (the
# DEXTERITY section, upload line 400), the
# five thief adjustment columns for scores 9
# through 18. This round pins them:
#
#   (a) rules/thieffunc.h CREATED - the
#       printed take table (pinned in TENTHS
#       of a percent: the climb walls column
#       carries a decimal from the 11th level,
#       99.1% reads 991; the read languages
#       dash at levels 1-3 reads 0), the six
#       racial rows keyed to the rules/races.h
#       enum (the human prints no row and
#       reads 0), DEX Table II (below the 9
#       reads the 9 row, above the 18 the 18
#       row - the character.h DEX I clamp
#       convention; hear noise, climb walls
#       and read languages print no column and
#       read 0), the adjusted-chance seam
#       thfChanceTenths (base + race + DEX,
#       the adjustments additional pluses) and
#       the printed notes (the percentile
#       roll, the 21% pick pockets notice
#       band, the 5% victim cut above the 3rd,
#       the locks/traps one-try rules).
#       DATA-ONLY: the engine performs no
#       thief rolls; nothing calls the seam
#       yet (a future round wires the rolls).
#   (b) regtest.cpp - the R298 audit block
#       (the battery census 214 -> 215): the
#       take table walked cell by cell, the
#       racial and DEX rows cell by cell, the
#       clamps, the seam identity and the
#       printed 12th-level pick pockets
#       example (120 - 45 = 75).
#   (c) tools/phb_gap_report.md - the R298
#       item flips PINNED R298 (Census 215) -
#       the phb ledger now holds ZERO open
#       items.
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS; the include lines carry plain
# double quotes inside single-quoted Python
# strings), and no CONTENT string embeds an
# apostrophe, non-ASCII or (for the gap report)
# a line past 57 columns.
# Commit: "R298: the thief function take table
# and DEX Table II pinned (data-only, census
# 215)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit):
    assert chr(39) not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) rules/thieffunc.h CREATED ----
HEADER = NL.join([
    '// ====================================================================',
    '// Adnd1 - rules/thieffunc.h',
    '// R298: the PHB Thief Function Take table',
    '// (the THIEF section, Premium 1e OCR',
    '// upload line 1620) and DEXTERITY TABLE II',
    '// (upload line 400) - a DATA-ONLY pin (the',
    '// R186 poetics precedent): the engine',
    '// performs no thief rolls; the tables, the',
    '// walkers and the adjusted-chance seam are',
    '// data for the future roll round.',
    '//',
    '// The take table: the base chance to perform',
    '// each of the eight thief functions (pick',
    '// pockets, open locks, find/remove traps,',
    '// move silently, hide in shadows, hear',
    '// noise, climb walls, read languages) at',
    '// thief levels 1 through 17, with the six',
    '// racial adjustment rows beneath (dwarf,',
    '// elf, gnome, half-elf, halfling, half-orc;',
    '// the human prints no row and reads 0),',
    '// keyed to the engine race enum',
    '// (rules/races.h, the printed order).',
    '//',
    '// Conventions:',
    '//   - the BASE CHANCES are pinned in TENTHS',
    '//     of a percent: the printed climb walls',
    '//     column carries one decimal place from',
    '//     the 11th level (99.1% reads 991) and',
    '//     every printed whole percent reads x10',
    '//     (30% reads 300);',
    '//   - the RACIAL and DEXTERITY adjustments',
    '//     are whole percent (the printed rows',
    '//     carry nothing finer);',
    '//   - the read languages dash at levels 1',
    '//     through 3 pins as 0 (no chance);',
    '//   - the level clamps 1..17, the function',
    '//     clamps 0..7, the race clamps 0..6 and',
    '//     the dexterity clamps onto the printed',
    '//     band: below 9 reads the 9 row, above',
    '//     18 the 18 row (the character.h DEX',
    '//     Table I convention);',
    '//   - DEXTERITY TABLE II prints five columns',
    '//     (picking pockets, opening locks,',
    '//     locating/removing traps, moving',
    '//     silently, hiding in shadows); hear',
    '//     noise, climb walls and read languages',
    '//     carry no DEX column and read 0.',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The printed function order (the table top to bottom).',
    'enum ThfFn {',
    '    THF_PICK_POCKETS = 0,',
    '    THF_OPEN_LOCKS,',
    '    THF_TRAPS,',
    '    THF_MOVE_SILENTLY,',
    '    THF_HIDE_SHADOWS,',
    '    THF_HEAR_NOISE,',
    '    THF_CLIMB_WALLS,',
    '    THF_READ_LANGUAGES',
    '};',
    '',
    'inline int thfFunctionCount() {',
    '    // the eight printed functions',
    '    return 8;',
    '}',
    '',
    'inline int thfLevelCount() {',
    '    // the take table prints thief levels 1',
    '    // through 17',
    '    return 17;',
    '}',
    '',
    'inline int thfTakeTenths(int fn, int level) {',
    '    // the printed base chance in TENTHS of a',
    '    // percent; fn clamps 0..7, level 1..17',
    '    if (fn < 0) fn = 0;',
    '    if (fn > 7) fn = 7;',
    '    if (level < 1) level = 1;',
    '    if (level > 17) level = 17;',
    '    static const int t[17][8] = {',
    '        {  300,  250,  200,  150,  100,  100,  850,    0 },',
    '        {  350,  290,  250,  210,  150,  100,  860,    0 },',
    '        {  400,  330,  300,  270,  200,  150,  870,    0 },',
    '        {  450,  370,  350,  330,  250,  150,  880,  200 },',
    '        {  500,  420,  400,  400,  310,  200,  900,  250 },',
    '        {  550,  470,  450,  470,  370,  200,  920,  300 },',
    '        {  600,  520,  500,  550,  430,  250,  940,  350 },',
    '        {  650,  570,  550,  620,  490,  250,  960,  400 },',
    '        {  700,  620,  600,  700,  560,  300,  980,  450 },',
    '        {  800,  670,  650,  780,  630,  300,  990,  500 },',
    '        {  900,  720,  700,  860,  700,  350,  991,  550 },',
    '        { 1000,  770,  750,  940,  770,  350,  992,  600 },',
    '        { 1050,  820,  800,  990,  850,  400,  993,  650 },',
    '        { 1100,  870,  850,  990,  930,  400,  994,  700 },',
    '        { 1150,  920,  900,  990,  990,  500,  995,  750 },',
    '        { 1250,  970,  950,  990,  990,  500,  996,  800 },',
    '        { 1250,  990,  990,  990,  990,  550,  997,  800 },',
    '    };',
    '    return t[level - 1][fn];',
    '}',
    '',
    'inline int thfRaceAdj(int race, int fn) {',
    '    // the six printed racial adjustment rows',
    '    // (upload lines 1645-1650) in whole',
    '    // percent, keyed to the rules/races.h enum',
    '    // (the human prints no row and reads 0);',
    '    // fn clamps 0..7',
    '    if (race < 0) race = 0;',
    '    if (race > 6) race = 6;',
    '    if (fn < 0) fn = 0;',
    '    if (fn > 7) fn = 7;',
    '    static const int t[7][8] = {',
    '        {   0,   0,   0,   0,   0,   0,   0,   0 },  // human',
    '        {   0,  10,  15,   0,   0,   0, -10,  -5 },  // dwarf',
    '        {   5,  -5,   0,   5,  10,   5,   0,   0 },  // elf',
    '        {   0,   5,  10,   5,   5,  10, -15,   0 },  // gnome',
    '        {  10,   0,   0,   0,   5,   0,   0,   0 },  // half-elf',
    '        {   5,   5,   5,  10,  15,   5, -15,  -5 },  // halfling',
    '        {  -5,   5,   5,   0,   0,   5,   5, -10 },  // half-orc',
    '    };',
    '    return t[race][fn];',
    '}',
    '',
    'inline int thfDexAdj(int dex, int fn) {',
    '    // DEXTERITY TABLE II (upload line 400):',
    '    // the five printed adjustment columns',
    '    // (picking pockets, opening locks,',
    '    // locating/removing traps, moving',
    '    // silently, hiding in shadows) for',
    '    // scores 9 through 18, whole percent;',
    '    // below the printed band reads the 9 row,',
    '    // above it the 18 row (the character.h',
    '    // DEX Table I convention); hear noise,',
    '    // climb walls and read languages print',
    '    // no column and read 0',
    '    if (dex < 9) dex = 9;',
    '    if (dex > 18) dex = 18;',
    '    if (fn < 0) fn = 0;',
    '    if (fn > 7) fn = 7;',
    '    static const int t[10][5] = {',
    '        { -15, -10, -10, -20, -10 },  // 9',
    '        { -10,  -5, -10, -15,  -5 },  // 10',
    '        {  -5,   0,  -5, -10,   0 },  // 11',
    '        {   0,   0,   0,  -5,   0 },  // 12',
    '        {   0,   0,   0,   0,   0 },  // 13',
    '        {   0,   0,   0,   0,   0 },  // 14',
    '        {   0,   0,   0,   0,   0 },  // 15',
    '        {   0,   5,   0,   0,   0 },  // 16',
    '        {   5,  10,   0,   5,   5 },  // 17',
    '        {  10,  15,   5,  10,  10 },  // 18',
    '    };',
    '    if (fn == THF_HEAR_NOISE) return 0;',
    '    if (fn == THF_CLIMB_WALLS) return 0;',
    '    if (fn == THF_READ_LANGUAGES) return 0;',
    '    return t[dex - 9][fn];',
    '}',
    '',
    'inline int thfChanceTenths(int fn, int level,',
    '                           int race, int dex) {',
    '    // the adjusted chance seam: the printed',
    '    // base plus the racial and dexterity',
    '    // adjustments (the printed notes: the',
    '    // adjustments are additional pluses; a',
    '    // percentile roll at or below the chance',
    '    // succeeds). DATA-ONLY - nothing calls',
    '    // this seam yet (the engine performs no',
    '    // thief rolls; a future round wires them)',
    '    return thfTakeTenths(fn, level) + 10 *',
    '        (thfRaceAdj(race, fn) + thfDexAdj(dex, fn));',
    '}',
    '',
    'inline int thfNotePercentileRoll() {',
    '    // percentile dice decide; a score equal',
    '    // to or less than the chance succeeds',
    '    return 1;',
    '}',
    '',
    'inline int thfNotePocketsNoticeBand() {',
    '    // a pick pockets score 21% or more ABOVE',
    '    // the chance means the victim notices',
    '    // the attempt',
    '    return 21;',
    '}',
    '',
    'inline int thfNotePocketsVictimCut() {',
    '    // the victim cuts the pick pockets chance',
    '    // 5% per level above the 3rd',
    '    return 5;',
    '}',
    '',
    'inline int thfNoteLocksOneTry() {',
    '    // opening locks: one try per lock (a',
    '    // retry waits for a higher level)',
    '    return 1;',
    '}',
    '',
    'inline int thfNoteTrapsSeparate() {',
    '    // finding and removing traps roll',
    '    // separately; a trap must be located',
    '    // before removal; one try each',
    '    return 1;',
    '}',
    '',
    'inline int thfNoteRacialAdditional() {',
    '    // the racial adjustments are additional',
    '    // pluses on the adjusted base',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
    '',
])
clean(HEADER, 100)

p = 'rules/thieffunc.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'R298: the PHB Thief Function Take table' in s:
        already.append('thieffunc.h created')
    else:
        fails.append('thieffunc.h exists without the R298 marker')
else:
    wr(p, HEADER)
    applied.append('thieffunc.h created')
s = rd(p)
assert 'thfChanceTenths' in s, 'patch a failed'
assert s.count('inline int thf') == 12, 'accessor count wrong'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) regtest.cpp: the include + the audit block ----
REG_INC_OLD = '#include "rules/weaponprof.h"  // R297: the PHB Weapon Proficiency Table'
REG_INC_NEW = NL.join([
    '#include "rules/weaponprof.h"  // R297: the PHB Weapon Proficiency Table',
    '#include "rules/thieffunc.h"  // R298: the thief function take table and DEX Table II',
])
AUDIT = NL.join([
    '    // ---- R298: the thief function take table pins audit ----',
    '    // The PHB Thief Function Take table (upload',
    '    // line 1620): the base chances of the eight',
    '    // functions at thief levels 1 through 17,',
    '    // pinned in TENTHS of a percent (the printed',
    '    // climb walls column carries a decimal from',
    '    // the 11th level: 99.1% reads 991; the read',
    '    // languages dash at levels 1-3 reads 0), the',
    '    // six racial adjustment rows (upload lines',
    '    // 1645-1650; the human default reads 0) and',
    '    // DEXTERITY TABLE II (upload line 400; the',
    '    // five printed columns, scores 9 through 18;',
    '    // hear noise, climb walls and read languages',
    '    // print no column and read 0). A DATA-ONLY',
    '    // pin (the R186 poetics precedent) - the',
    '    // engine performs no thief rolls; the seam',
    '    // thfChanceTenths folds base + race + DEX',
    '    // (the adjustments are additional pluses).',
    '    {',
    '        int bad = 0;',
    '        // the counts: eight functions, 17 levels',
    '        if (rules::thfFunctionCount() != 8 ||',
    '            rules::thfLevelCount() != 17) ++bad;',
    '        // the printed take table, cell by cell',
    '        static const int kTake[17][8] = {',
    '            {  300,  250,  200,  150,  100,  100,  850,    0 },',
    '            {  350,  290,  250,  210,  150,  100,  860,    0 },',
    '            {  400,  330,  300,  270,  200,  150,  870,    0 },',
    '            {  450,  370,  350,  330,  250,  150,  880,  200 },',
    '            {  500,  420,  400,  400,  310,  200,  900,  250 },',
    '            {  550,  470,  450,  470,  370,  200,  920,  300 },',
    '            {  600,  520,  500,  550,  430,  250,  940,  350 },',
    '            {  650,  570,  550,  620,  490,  250,  960,  400 },',
    '            {  700,  620,  600,  700,  560,  300,  980,  450 },',
    '            {  800,  670,  650,  780,  630,  300,  990,  500 },',
    '            {  900,  720,  700,  860,  700,  350,  991,  550 },',
    '            { 1000,  770,  750,  940,  770,  350,  992,  600 },',
    '            { 1050,  820,  800,  990,  850,  400,  993,  650 },',
    '            { 1100,  870,  850,  990,  930,  400,  994,  700 },',
    '            { 1150,  920,  900,  990,  990,  500,  995,  750 },',
    '            { 1250,  970,  950,  990,  990,  500,  996,  800 },',
    '            { 1250,  990,  990,  990,  990,  550,  997,  800 },',
    '        };',
    '        for (int l = 1; l <= 17; ++l)',
    '            for (int f = 0; f < 8; ++f)',
    '                if (rules::thfTakeTenths(f, l) !=',
    '                    kTake[l - 1][f]) ++bad;',
    '        // the printed read languages dash:',
    '        // levels 1-3 read 0',
    '        for (int l = 1; l <= 3; ++l)',
    '            if (rules::thfTakeTenths(7, l) != 0) ++bad;',
    '        // the take-table clamps: fn 0..7,',
    '        // level 1..17 (the open locks probe:',
    '        // the 16th and 17th rows differ, so a',
    '        // slipped upper clamp cannot hide)',
    '        if (rules::thfTakeTenths(-1, 5) != 500 ||',
    '            rules::thfTakeTenths(9, 5) != 250 ||',
    '            rules::thfTakeTenths(0, 0) != 300 ||',
    '            rules::thfTakeTenths(0, 99) != 1250 ||',
    '            rules::thfTakeTenths(1, 99) != 990 ||',
    '            rules::thfTakeTenths(7, -3) != 0 ||',
    '            rules::thfTakeTenths(7, 20) != 800) ++bad;',
    '        // the printed racial rows (upload lines',
    '        // 1645-1650), keyed to the rules/races.h',
    '        // enum order',
    '        static const int kRace[7][8] = {',
    '            {   0,   0,   0,   0,   0,   0,   0,   0 },  // human',
    '            {   0,  10,  15,   0,   0,   0, -10,  -5 },  // dwarf',
    '            {   5,  -5,   0,   5,  10,   5,   0,   0 },  // elf',
    '            {   0,   5,  10,   5,   5,  10, -15,   0 },  // gnome',
    '            {  10,   0,   0,   0,   5,   0,   0,   0 },  // half-elf',
    '            {   5,   5,   5,  10,  15,   5, -15,  -5 },  // halfling',
    '            {  -5,   5,   5,   0,   0,   5,   5, -10 },  // half-orc',
    '        };',
    '        for (int r = 0; r < 7; ++r)',
    '            for (int f = 0; f < 8; ++f)',
    '                if (rules::thfRaceAdj(r, f) !=',
    '                    kRace[r][f]) ++bad;',
    '        // the racial clamps: race 0..6,',
    '        // fn 0..7',
    '        if (rules::thfRaceAdj(-1, 0) != 0 ||',
    '            rules::thfRaceAdj(99, 0) != -5 ||',
    '            rules::thfRaceAdj(1, -1) != 0 ||',
    '            rules::thfRaceAdj(1, 9) != -5) ++bad;',
    '        // DEXTERITY TABLE II (upload line 400),',
    '        // cell by cell',
    '        static const int kDex[10][5] = {',
    '            { -15, -10, -10, -20, -10 },  // 9',
    '            { -10,  -5, -10, -15,  -5 },  // 10',
    '            {  -5,   0,  -5, -10,   0 },  // 11',
    '            {   0,   0,   0,  -5,   0 },  // 12',
    '            {   0,   0,   0,   0,   0 },  // 13',
    '            {   0,   0,   0,   0,   0 },  // 14',
    '            {   0,   0,   0,   0,   0 },  // 15',
    '            {   0,   5,   0,   0,   0 },  // 16',
    '            {   5,  10,   0,   5,   5 },  // 17',
    '            {  10,  15,   5,  10,  10 },  // 18',
    '        };',
    '        for (int s = 9; s <= 18; ++s)',
    '            for (int f = 0; f < 5; ++f)',
    '                if (rules::thfDexAdj(s, f) !=',
    '                    kDex[s - 9][f]) ++bad;',
    '        // the DEX band clamps: below 9 reads',
    '        // the 9 row, above 18 the 18 row',
    '        if (rules::thfDexAdj(3, 0) != -15 ||',
    '            rules::thfDexAdj(1, 0) != -15 ||',
    '            rules::thfDexAdj(25, 0) != 10 ||',
    '            rules::thfDexAdj(19, 1) != 15) ++bad;',
    '        // the functions DEX Table II prints no',
    '        // column for read 0, every score',
    '        for (int s = 9; s <= 18; ++s)',
    '            if (rules::thfDexAdj(s, 5) != 0 ||',
    '                rules::thfDexAdj(s, 6) != 0 ||',
    '                rules::thfDexAdj(s, 7) != 0) ++bad;',
    '        // the DEX fn clamps: -1 reads the pick',
    '        // pockets column, 12 the read',
    '        // languages 0',
    '        if (rules::thfDexAdj(9, -1) != -15 ||',
    '            rules::thfDexAdj(9, 12) != 0) ++bad;',
    '        // the seam identity: base + race + DEX,',
    '        // every function, a 10th-level dwarf at',
    '        // DEX 16',
    '        for (int f = 0; f < 8; ++f)',
    '            if (rules::thfChanceTenths(f, 10, 1, 16) !=',
    '                rules::thfTakeTenths(f, 10) + 10 *',
    '                (rules::thfRaceAdj(1, f) +',
    '                 rules::thfDexAdj(16, f))) ++bad;',
    '        // the printed pick pockets example (the',
    '        // THIEF notes): a 12th-level half-elf',
    '        // Master Thief with DEX 18 reads',
    '        // 100 + 10 + 10 = 120 percent, and the',
    '        // 12th-level victim cuts 9 x 5 = 45:',
    '        // the chance lands at 75',
    '        if (rules::thfChanceTenths(0, 12, 4, 18) !=',
    '            1200 ||',
    '            rules::thfChanceTenths(0, 12, 4, 18) -',
    '            10 * (9 *',
    '            rules::thfNotePocketsVictimCut()) !=',
    '            750) ++bad;',
    '        // the printed notes: the percentile roll',
    '        // (equal or less succeeds), the 21%',
    '        // notice band, the 5% victim cut, the',
    '        // locks and traps one-try rules, the',
    '        // additional racial pluses',
    '        if (rules::thfNotePercentileRoll() != 1 ||',
    '            rules::thfNotePocketsNoticeBand() != 21 ||',
    '            rules::thfNotePocketsVictimCut() != 5 ||',
    '            rules::thfNoteLocksOneTry() != 1 ||',
    '            rules::thfNoteTrapsSeparate() != 1 ||',
    '            rules::thfNoteRacialAdditional() != 1) ++bad;',
    '        printf("R298 thief function take table pins audit: bad %d'
    + BS + 'n", bad);',
    '    }',
])
for ln in AUDIT.split(NL):
    assert all(ord(c) < 128 for c in ln), 'non-ascii in audit'
    assert len(ln) <= 76, 'audit line too long: ' + ln
    assert chr(39) not in ln, 'apostrophe in audit'
    if 'printf' in ln:
        assert ln.count(BS) == 1, 'printf BS count wrong'
    else:
        assert BS not in ln, 'stray backslash in audit'
clean(REG_INC_NEW, 100)

p = 'regtest.cpp'
s = rd(p)
if 'R298 thief function take table pins audit' in s:
    already.append('regtest.cpp: the R298 audit')
else:
    assert s.count(REG_INC_OLD) == 1, 'regtest include anchor not unique'
    assert s.count('audit: bad') == 214, 'census is not 214'
    r297_tail = ('        printf("R297 weapon proficiency table'
                 ' pins audit: bad %d' + BS
                 + 'n", bad);')
    r227_head = '    // ---- R227: the wis mental save wiring audit ----'
    anchor = r297_tail + NL + '    }' + NL + r227_head
    assert s.count(anchor) == 1, 'regtest block anchor not unique'
    s = s.replace(REG_INC_OLD, REG_INC_NEW)
    new_region = r297_tail + NL + '    }' + NL + AUDIT + NL + r227_head
    s = s.replace(anchor, new_region)
    wr(p, s)
    applied.append('regtest.cpp: the R298 audit')
s = rd(p)
assert s.count('R298 thief function take table pins audit') == 1, 'patch b failed'
assert s.count('audit: bad') == 215, 'census is not 215'
assert s.count('#include "rules/thieffunc.h"') == 1, 'patch b include'
assert 'R297 weapon proficiency table pins audit' in s, 'patch b ate R297'
assert '// ---- R227: the wis mental save wiring audit ----' in s, 'patch b ate R227'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) tools/phb_gap_report.md: the flip ----
ITEM_OLD = NL.join([
    '- [ ] **Thief Function Take table and DEXTERITY',
    '      TABLE II (the THIEF and DEXTERITY',
    '      sections)** - the take table runs thief',
    '      levels 1 through 17 across the eight',
    '      functions (pick pockets, open locks,',
    '      find/remove traps, move silently, hide',
    '      in shadows, hear noise, climb walls,',
    '      read languages), with the six racial',
    '      adjustment rows beneath (dwarf, elf,',
    '      gnome, half-elf, halfling, half-orc);',
    '      DEX Table II prints the five thief',
    '      adjustment columns for scores 9',
    '      through 18. The engine carries the six',
    '      shared ability names and the',
    '      monk/assassin level-sharing rules',
    '      (rules/subclassspecials.h) but performs',
    '      no thief rolls. A DATA-ONLY pin',
    '      candidate (the R186 poetics precedent),',
    '      not gameplay wiring. The R298 candidate.',
])
ITEM_NEW = NL.join([
    '- [x] **Thief Function Take table and DEXTERITY',
    '      TABLE II (the THIEF and DEXTERITY',
    '      sections) - PINNED R298:**',
    '      rules/thieffunc.h CREATED (a DATA-ONLY',
    '      pin, the R186 poetics precedent - the',
    '      engine performs no thief rolls; the',
    '      seam waits for a future roll round) -',
    '      the take table (upload line 1620) runs',
    '      thief levels 1 through 17 across the',
    '      eight functions (pick pockets, open',
    '      locks, find/remove traps, move',
    '      silently, hide in shadows, hear noise,',
    '      climb walls, read languages), pinned',
    '      in TENTHS of a percent (the printed',
    '      climb walls column carries a decimal',
    '      from the 11th level: 99.1% reads 991;',
    '      the read languages dash at levels 1-3',
    '      reads 0); the six racial adjustment',
    '      rows beneath (upload lines 1645-1650;',
    '      the human default reads 0) keyed to',
    '      the rules/races.h enum; and DEXTERITY',
    '      TABLE II (upload line 400), the five',
    '      thief adjustment columns for scores 9',
    '      through 18 (below the 9 reads the 9',
    '      row, above the 18 the 18 row - the',
    '      character.h DEX Table I convention;',
    '      hear noise, climb walls and read',
    '      languages print no column and read',
    '      0). The seam thfChanceTenths folds',
    '      base + race + DEX (the adjustments',
    '      additional pluses). The printed notes',
    '      pinned: the percentile roll (equal or',
    '      less succeeds), the 21% pick pockets',
    '      notice band, the 5% victim cut above',
    '      the 3rd (the printed 12th-level',
    '      half-elf example: 120 - 45 = 75) and',
    '      the locks/traps one-try rules. The',
    '      R298 battery audit walks the take',
    '      table cell by cell, the racial and DEX',
    '      rows, the clamps and the printed',
    '      example. Census 215.',
])
clean(ITEM_OLD, 57)
clean(ITEM_NEW, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'PINNED R298' in s:
    already.append('phb_gap_report.md: the flip')
else:
    assert s.count(ITEM_OLD) == 1, 'the gap item anchor not unique'
    assert s.count('- [ ]') == 1, 'the open-item count is not 1'
    wr(p, s.replace(ITEM_OLD, ITEM_NEW))
    applied.append('phb_gap_report.md: the flip')
s = rd(p)
assert s.count('PINNED R298') == 1, 'patch c failed'
assert s.count('- [ ]') == 0, 'patch c left an open item'
assert s.count('[x] **Thief Function Take table') == 1, 'flip box wrong'
assert 'Census 214.' in s, 'patch c ate the R297 census note'
assert 'Census 215.' in s, 'patch c census note missing'
assert 'R296 SCOPE PASS' in s, 'patch c ate the scope section'
assert '## Out of engine scope' in s, 'patch c ate the scope head'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- R298 fails/tail ----
if fails:
    print('R298 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 3:
    print('R298 splice: FAIL - expected 3 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R298 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R298 note: 3 patches; the battery census 214 -> 215;')
print('the phb ledger now holds ZERO open items')
print('real gate: md5sum rules/thieffunc.h')
print('commit: R298: the thief function take table and DEX Table II pinned (data-only, census 215)')

