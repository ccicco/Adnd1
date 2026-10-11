#!/usr/bin/env python3
# R334: the UA Thieves Table II
# (p. 22) pin round - the armor
# effects on thief functions plus
# the paired Attacks Per Melee
# Round Table (the Open Locks
# cells, the missing no-armor
# cells, the attacks high-band
# rate and the footnote-1 tail are
# OCR holes - the item stays open
# pending the PDF). Pin-era
# pattern (R322). Idempotent; run
# twice.

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

# ---- (a) the seed: the R333 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R333 landed 2026-10-11: commit',
    '  458c831, census 260, the UA',
    '  ranger expansion pin round',
    '  (rules/uaranger.h): the tracking',
    '  base and terrain ladders, the',
    '  indoor reads, the identification',
    '  ladder, the giant-class roster',
    '  expansion 11 -> 22 (gnoll decoded',
    '  from the garbled cell); the spell',
    '  progression closed via the landed',
    '  R327/R184 seams (the UA prose is',
    '  OCR-lost). GREEN on the first',
    '  paste. No new lessons.',
    ])
s = rd(SD)
if 'R333 landed 2026-10-11' in s:
    already.append('seed: the R333 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R333 record')
s = rd(SD)
assert s.count('R333 landed 2026-10-11') == 1, 'a entry'
assert s.count('R332 landed 2026-10-11') == 1, \
    'a r332 kept'
assert s.count('## Knowledge maintenance') == 1, \
    'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/thiefarmor.h ----
TA = 'rules/thiefarmor.h'
if os.path.exists(TA) and 'R334' in rd(TA):
    already.append('thiefarmor.h: the pins')
else:
    HDR = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/thiefarmor.h',
    '// The UA Thieves Table II (p. 22) pins (R334) - the effects of',
    '// armor on thief functions, plus the paired Attacks Per Melee',
    '// Round Table.',
    '//',
    '// Pin-era pattern (R322): pinned data only - no engine site exists.',
    '//',
    '// JUDGMENTs:',
    '//   - the table columns: the extract header prints the third',
    '//     column as "Studded or / Padded" across two lines - one',
    '//     column, "Studded or Padded". The no-armor column header is',
    '//     OCR-lost but the intro sentence fixes it (bonuses apply if',
    '//     the thief wears no armor) and each row\'s "+" token carries',
    '//     the no-armor column by sign (armor columns only penalize).',
    '//   - the printed dashes (Read Languages) pin as 0, no modifier -',
    '//     the R184 dash convention.',
    '//   - the attacks table: the band row labels read clean for all',
    '//     five classes; the band-0 rate (1/1 round) is verified twice,',
    '//     the band-1 rate (3/2 rounds) once, the band-3 rate (5/2',
    '//     rounds) twice (cavalier 16th and paladin 19th). The band-2',
    '//     rate cells (fighter 13th up through paladin 12-18) print',
    '//     empty in the extract - a documented hole, 0/0, pending the',
    '//     PDF. The paladin band edges print 7-12 then 12-18 - the',
    '//     printed overlap at 12th pinned as printed.',
    '//',
    '// OCR holes (the item stays open pending the PDF read): the Open',
    '// Locks row\'s "5% / -" tokens (sign and column assignment lost),',
    '// the no-armor cells that print no token (Open Locks, Find/Remove',
    '// Traps, Hear Noise), the attacks band-2 rate, and the footnote-1',
    '// tail (the bracers/cloak clause survives only as fragments).',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// ---- the armor categories (p. 22) ----',
    'inline int thiefArmorCategoryCount()',
    '    { return 3; }',
    '',
    'inline const char* thiefArmorCategoryName(int i) {',
    '    static const char* const k[3] = {',
    '        "No Armor", "Elfin Chain",',
    '        "Studded or Padded"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 2) i = 2;',
    '    return k[i];',
    '}',
    '',
    '// ---- the thief functions (p. 22) ----',
    'inline int thiefArmorFunctionCount()',
    '    { return 8; }',
    '',
    'inline const char* thiefArmorFunctionName(int i) {',
    '    static const char* const k[8] = {',
    '        "Pick Pockets", "Open Locks",',
    '        "Find/Remove Traps", "Move Silently",',
    '        "Hide in Shadows", "Hear Noise",',
    '        "Climb Walls", "Read Languages"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 7) i = 7;',
    '    return k[i];',
    '}',
    '',
    '// ---- the cells (p. 22) ----',
    '// function 0-7, category 0-2 (0 = no',
    '// armor, 1 = elfin chain, 2 = studded',
    '// or padded). The lost cells read as',
    '// holes below; the printed dashes read',
    '// as 0.',
    'inline bool thiefArmorCellIsHole(',
    '        int function, int category) {',
    '    switch (function) {',
    '        case 1:     // Open Locks',
    '            return category <= 1;',
    '        case 2:     // Find/Remove Traps',
    '        case 5:     // Hear Noise',
    '            return category == 0;',
    '        default:',
    '            return false;',
    '    }',
    '}',
    '',
    'inline int thiefArmorModifierKnown(',
    '        int function, int category) {',
    '    static const int k[8][3] = {',
    '        {5, -20, -30},   // Pick Pockets',
    '        {0, 0, -10},     // Open Locks',
    '        {0, -5, -10},    // Find/Remove',
    '        {10, -10, -20},  // Move Silently',
    '        {5, -10, -20},   // Hide in Shadows',
    '        {0, -5, -10},    // Hear Noise',
    '        {10, -20, -30},  // Climb Walls',
    '        {0, 0, 0}        // Read Languages',
    '    };',
    '    if (function < 0) function = 0;',
    '    if (function > 7) function = 7;',
    '    if (category < 0) category = 0;',
    '    if (category > 2) category = 2;',
    '    return k[function][category];',
    '}',
    '',
    '// ---- the footnotes (p. 22) ----',
    '// Footnote 2: no dexterity bonuses',
    '// apply to thief functions (though',
    '// penalties do) in armor other than',
    '// simple leather. Footnote 3: the',
    '// armor is assumed covered by another',
    '// garment - elfin chain under normal',
    '// clothing, studded leather only by a',
    '// full body cloak. Footnote 1\'s tail',
    '// is OCR-lost; the surviving fragments',
    '// (cloak but no large protective',
    '// devices; of defense and/or a) fix',
    '// the no-armor clause as bracers',
    '// and/or cloak - pinned as the',
    '// clause\'s existence only.',
    'inline bool thiefArmorNoDexBonusInArmor()',
    '    { return true; }',
    '',
    'inline bool thiefArmorCoveredByGarmentAssumed()',
    '    { return true; }',
    '',
    'inline bool thiefArmorElfinUnderNormalClothing()',
    '    { return true; }',
    '',
    'inline bool thiefArmorStuddedNeedsFullBodyCloak()',
    '    { return true; }',
    '',
    'inline bool thiefArmorNoArmorBracersOrCloak()',
    '    { return true; }',
    '',
    '// ---- the Attacks Per Melee Round',
    '// Table (p. 22) - the classes ----',
    '// For fighters, cavaliers and',
    '// sub-classes thereof. kind 0-4:',
    '// fighter, barbarian, ranger,',
    '// cavalier, paladin.',
    'inline int uaAttacksClassCount()',
    '    { return 5; }',
    '',
    'inline const char* uaAttacksClassName(int i) {',
    '    static const char* const k[5] = {',
    '        "Fighter", "Barbarian", "Ranger",',
    '        "Cavalier", "Paladin"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 4) i = 4;',
    '    return k[i];',
    '}',
    '',
    '// ---- the bands (p. 22) ----',
    '// Four bands: 1/1 round, 3/2 rounds,',
    '// the OCR-lost high band, 5/2 rounds',
    '// (cavalier 16th up, paladin 19th',
    '// up). Fighter, barbarian and ranger',
    '// print three bands; cavalier and',
    '// paladin four.',
    'inline int uaAttacksBandCount()',
    '    { return 4; }',
    '',
    'inline int uaAttacksBandAttacks(int band) {',
    '    static const int k[4] = {1, 3, 0, 5};',
    '    if (band < 0) band = 0;',
    '    if (band > 3) band = 3;',
    '    return k[band];',
    '}',
    '',
    'inline int uaAttacksBandRounds(int band) {',
    '    static const int k[4] = {1, 2, 0, 2};',
    '    if (band < 0) band = 0;',
    '    if (band > 3) band = 3;',
    '    return k[band];',
    '}',
    '',
    'inline int uaAttacksBandLow(int kind, int band) {',
    '    static const int k[5][4] = {',
    '        {1, 7, 13, 0},    // fighter',
    '        {1, 6, 11, 0},    // barbarian',
    '        {1, 8, 15, 0},    // ranger',
    '        {1, 6, 11, 16},   // cavalier',
    '        {1, 7, 12, 19}    // paladin',
    '    };',
    '    if (kind < 0) kind = 0;',
    '    if (kind > 4) kind = 4;',
    '    if (band < 0) band = 0;',
    '    if (band > 3) band = 3;',
    '    return k[kind][band];',
    '}',
    '',
    'inline int uaAttacksBandHigh(int kind, int band) {',
    '    // 0 = open (and up)',
    '    static const int k[5][4] = {',
    '        {6, 12, 0, 0},    // fighter',
    '        {5, 10, 0, 0},    // barbarian',
    '        {7, 14, 0, 0},    // ranger',
    '        {5, 10, 15, 0},   // cavalier',
    '        {6, 12, 18, 0}    // paladin',
    '    };',
    '    if (kind < 0) kind = 0;',
    '    if (kind > 4) kind = 4;',
    '    if (band < 0) band = 0;',
    '    if (band > 3) band = 3;',
    '    return k[kind][band];',
    '}',
    '',
    'inline int uaAttacksBandForLevel(',
    '        int kind, int level) {',
    '    if (kind < 0) kind = 0;',
    '    if (kind > 4) kind = 4;',
    '    if (level < 1) level = 1;',
    '    // first match wins: the paladin\'s',
    '    // printed bands overlap at 12th',
    '    // (7-12 and 12-18) - the earlier',
    '    // band owns the boundary level',
    '    for (int b = 0; b < 4; ++b) {',
    '        if (uaAttacksBandLow(kind, b) == 0)',
    '            continue;',
    '        if (level < uaAttacksBandLow(kind, b))',
    '            continue;',
    '        int hi = uaAttacksBandHigh(kind, b);',
    '        if (hi == 0 || level <= hi)',
    '            return b;',
    '    }',
    '    return 0;',
    '}',
    '',
    '// ---- the asterisk and the notes',
    '// (p. 22) ----',
    '// With any thrusting or striking',
    '// weapon. The figures do not apply to',
    '// melee with monsters of less than one',
    '// hit die (d8) and non-exceptional',
    '// humans and semi-humans - against all',
    '// such creatures the attacks run once',
    '// per round per level. The figures',
    '// also do not apply to fighters and',
    '// rangers using weapons of',
    '// specialization.',
    'inline bool uaAttacksThrustingOrStrikingOnly()',
    '    { return true; }',
    '',
    'inline bool uaAttacksSubOneHdOncePerLevel()',
    '    { return true; }',
    '',
    'inline bool uaAttacksNotForSpecialized()',
    '    { return true; }',
    '',
    '}   // namespace rules',
    ])
    clean(HDR, 78)
    wr(TA, HDR)
    applied.append('thiefarmor.h: the pins')
s = rd(TA)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('thiefArmorModifierKnown') == 1, 'b cells'
assert s.count('thiefArmorCellIsHole') == 1, 'b holes'
assert s.count('uaAttacksBandForLevel') == 1, 'b route'
assert s.count('uaAttacksBandLow') == 3, 'b edges'
assert s.count('inline') == 22, 'b inline count'
assert s.count('Studded or Padded') == 2, 'b column'
assert s.count('R334') == 1, 'b round tag'
assert 'fighterGroupAttacks' not in s, 'b no r181 ref'
assert 'weaponSpecExtraAttacks' not in s, \
    'b no r331 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note ----
# The item STAYS OPEN (the Open
# Locks cells, the missing no-armor
# cells, the attacks high-band rate
# and the footnote-1 tail are
# OCR-lost); an in-place note
# records what R334 pinned.
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R334: the fragment-verified' in s:
    already.append('gap report: the note')
else:
    FIRST_OLD = ('- [ ] **Thieves Table II**'
                ' (p. 22) -')
    TAIL_OLD = NL.join([
    '      (p. 22) pairs with it.',
    ])
    assert s.count(FIRST_OLD) == 1, 'c first'
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R334: the fragment-verified',
    '      cells pinned (rules/thiefarmor.h)',
    '      - the armor columns, the eight',
    '      functions, the sign-carries-',
    '      column decode, the footnotes,',
    '      the attacks classes, band edges',
    '      and verified rates; the Open',
    '      Locks cells, the missing',
    '      no-armor cells, the attacks',
    '      high-band rate and the',
    '      footnote-1 tail are OCR-lost -',
    '      stays open pending the PDF read.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R334: the fragment-verified') == 1, \
    'c note'
assert s.count(
    '- [ ] **Thieves Table II**') == 1, \
    'c item stays open'
assert s.count('CLOSED R333') == 1, 'c r333 kept'
assert s.count('CLOSED R332') == 1, 'c r332 kept'
assert s.count('CLOSED R330') == 1, 'c r330 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R334 thief armor and attacks pin audit' in s:
    already.append('regtest.cpp: the R334 audit')
else:
    INC_ANCH = ('#include "rules/uaranger.h"'
                '  // R333: the UA ranger expansion')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/thiefarmor.h"'
    '  // R334: the UA thief armor and attacks',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
    '    // ---- R334: the thief armor and attacks pin audit ----',
    '    // The UA Thieves Table II (p. 22) - the pin-era pattern:',
    '    // the armor categories, the function rows, the',
    '    // fragment-verified cells (the sign carries the no-armor',
    '    // column), the footnotes; the paired Attacks Per Melee',
    '    // Round Table - the five classes, the band edges, the',
    '    // verified rates. The Open Locks cells, the missing',
    '    // no-armor cells, the attacks high-band rate and the',
    '    // footnote-1 tail are OCR holes - the item stays open',
    '    // pending the PDF. The R181/R331 seams cross-checked.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the categories and the functions',
    '        {',
    '            if (thiefArmorCategoryCount() != 3)',
    '                ++bad;',
    '            if (strcmp(thiefArmorCategoryName(0),',
    '                "No Armor") != 0) ++bad;',
    '            if (strcmp(thiefArmorCategoryName(1),',
    '                "Elfin Chain") != 0) ++bad;',
    '            if (strcmp(thiefArmorCategoryName(2),',
    '                "Studded or Padded") != 0)',
    '                ++bad;',
    '            if (thiefArmorFunctionCount() != 8)',
    '                ++bad;',
    '            if (strcmp(thiefArmorFunctionName(0),',
    '                "Pick Pockets") != 0) ++bad;',
    '            if (strcmp(thiefArmorFunctionName(3),',
    '                "Move Silently") != 0) ++bad;',
    '            if (strcmp(thiefArmorFunctionName(7),',
    '                "Read Languages") != 0) ++bad;',
    '        }',
    '        // U2: the verified cells',
    '        {',
    '            // Pick Pockets: +5 / -20 / -30',
    '            if (thiefArmorCellIsHole(0, 0)) ++bad;',
    '            if (thiefArmorModifierKnown(0, 0)',
    '                != 5) ++bad;',
    '            if (thiefArmorModifierKnown(0, 1)',
    '                != -20) ++bad;',
    '            if (thiefArmorModifierKnown(0, 2)',
    '                != -30) ++bad;',
    '            // Find/Remove Traps: -5 / -10',
    '            if (thiefArmorModifierKnown(2, 1)',
    '                != -5) ++bad;',
    '            if (thiefArmorModifierKnown(2, 2)',
    '                != -10) ++bad;',
    '            // Move Silently: +10 / -10 / -20',
    '            if (thiefArmorModifierKnown(3, 0)',
    '                != 10) ++bad;',
    '            if (thiefArmorModifierKnown(3, 1)',
    '                != -10) ++bad;',
    '            if (thiefArmorModifierKnown(3, 2)',
    '                != -20) ++bad;',
    '            // Hide in Shadows: +5 / -10 / -20',
    '            if (thiefArmorModifierKnown(4, 0)',
    '                != 5) ++bad;',
    '            if (thiefArmorModifierKnown(4, 1)',
    '                != -10) ++bad;',
    '            if (thiefArmorModifierKnown(4, 2)',
    '                != -20) ++bad;',
    '            // Hear Noise: -5 / -10',
    '            if (thiefArmorModifierKnown(5, 1)',
    '                != -5) ++bad;',
    '            if (thiefArmorModifierKnown(5, 2)',
    '                != -10) ++bad;',
    '            // Climb Walls: +10 / -20 / -30',
    '            if (thiefArmorModifierKnown(6, 0)',
    '                != 10) ++bad;',
    '            if (thiefArmorModifierKnown(6, 1)',
    '                != -20) ++bad;',
    '            if (thiefArmorModifierKnown(6, 2)',
    '                != -30) ++bad;',
    '            // Read Languages: the dashes',
    '            // read as 0',
    '            if (thiefArmorModifierKnown(7, 0)',
    '                != 0) ++bad;',
    '            if (thiefArmorModifierKnown(7, 2)',
    '                != 0) ++bad;',
    '        }',
    '        // U3: the OCR holes',
    '        {',
    '            if (!thiefArmorCellIsHole(1, 0))',
    '                ++bad;',
    '            if (!thiefArmorCellIsHole(1, 1))',
    '                ++bad;',
    '            if (thiefArmorCellIsHole(1, 2))',
    '                ++bad;',
    '            if (!thiefArmorCellIsHole(2, 0))',
    '                ++bad;',
    '            if (!thiefArmorCellIsHole(5, 0))',
    '                ++bad;',
    '            if (thiefArmorCellIsHole(0, 0)) ++bad;',
    '            if (thiefArmorCellIsHole(4, 1)) ++bad;',
    '        }',
    '        // U4: the footnotes',
    '        {',
    '            if (!thiefArmorNoDexBonusInArmor())',
    '                ++bad;',
    '            if (!thiefArmorCoveredByGarmentAssumed())',
    '                ++bad;',
    '            if (!thiefArmorElfinUnderNormalClothing())',
    '                ++bad;',
    '            if (!thiefArmorStuddedNeedsFullBodyCloak())',
    '                ++bad;',
    '            if (!thiefArmorNoArmorBracersOrCloak())',
    '                ++bad;',
    '        }',
    '        // U5: the attacks classes and',
    '        // band edges',
    '        {',
    '            if (uaAttacksClassCount() != 5)',
    '                ++bad;',
    '            if (strcmp(uaAttacksClassName(0),',
    '                "Fighter") != 0) ++bad;',
    '            if (strcmp(uaAttacksClassName(4),',
    '                "Paladin") != 0) ++bad;',
    '            if (uaAttacksBandCount() != 4)',
    '                ++bad;',
    '            static const int lo[5][4] = {',
    '                {1, 7, 13, 0},',
    '                {1, 6, 11, 0},',
    '                {1, 8, 15, 0},',
    '                {1, 6, 11, 16},',
    '                {1, 7, 12, 19}',
    '            };',
    '            static const int hi[5][4] = {',
    '                {6, 12, 0, 0},',
    '                {5, 10, 0, 0},',
    '                {7, 14, 0, 0},',
    '                {5, 10, 15, 0},',
    '                {6, 12, 18, 0}',
    '            };',
    '            for (int c = 0; c < 5; ++c)',
    '                for (int b = 0; b < 4; ++b) {',
    '                    if (uaAttacksBandLow(c, b)',
    '                        != lo[c][b]) ++bad;',
    '                    if (uaAttacksBandHigh(c, b)',
    '                        != hi[c][b]) ++bad;',
    '                }',
    '        }',
    '        // U6: the band routing and the',
    '        // verified rates (the high band',
    '        // is a documented 0/0 hole)',
    '        {',
    '            if (uaAttacksBandForLevel(0, 1)',
    '                != 0) ++bad;',
    '            if (uaAttacksBandForLevel(0, 7)',
    '                != 1) ++bad;',
    '            if (uaAttacksBandForLevel(0, 13)',
    '                != 2) ++bad;',
    '            if (uaAttacksBandForLevel(2, 15)',
    '                != 2) ++bad;',
    '            if (uaAttacksBandForLevel(3, 16)',
    '                != 3) ++bad;',
    '            if (uaAttacksBandForLevel(4, 19)',
    '                != 3) ++bad;',
    '            if (uaAttacksBandForLevel(4, 12)',
    '                != 1) ++bad;',
    '            if (uaAttacksBandForLevel(4, 13)',
    '                != 2) ++bad;',
    '            if (uaAttacksBandAttacks(0) != 1)',
    '                ++bad;',
    '            if (uaAttacksBandRounds(0) != 1)',
    '                ++bad;',
    '            if (uaAttacksBandAttacks(1) != 3)',
    '                ++bad;',
    '            if (uaAttacksBandRounds(1) != 2)',
    '                ++bad;',
    '            if (uaAttacksBandAttacks(2) != 0)',
    '                ++bad;',
    '            if (uaAttacksBandRounds(2) != 0)',
    '                ++bad;',
    '            if (uaAttacksBandAttacks(3) != 5)',
    '                ++bad;',
    '            if (uaAttacksBandRounds(3) != 2)',
    '                ++bad;',
    '        }',
    '        // U7: the asterisk and the notes',
    '        {',
    '            if (!uaAttacksThrustingOrStrikingOnly())',
    '                ++bad;',
    '            if (!uaAttacksSubOneHdOncePerLevel())',
    '                ++bad;',
    '            if (!uaAttacksNotForSpecialized())',
    '                ++bad;',
    '        }',
    '        // U8: the seams - the R181 PHB',
    '        // table (band agreement on the',
    '        // verified cells) and the R331',
    '        // spec extra-attacks pin',
    '        {',
    '            if (fighterGroupAttacks(0, 3)',
    '                .attacks != 1) ++bad;',
    '            if (fighterGroupAttacks(0, 3)',
    '                .rounds != 1) ++bad;',
    '            if (fighterGroupAttacks(0, 8)',
    '                .attacks != 3) ++bad;',
    '            if (fighterGroupAttacks(0, 8)',
    '                .rounds != 2) ++bad;',
    '            if (!weaponSpecExtraAttacks())',
    '                ++bad;',
    '        }',
    '        printf("R334 thief armor and attacks pin audit: bad %d\\n", bad);',
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
    applied.append('regtest.cpp: the R334 audit')
s = rd(RT)
assert s.count(
    'R334 thief armor and attacks pin audit: bad ') \
    == 1, 'd audit line'
assert s.count('audit: bad ') == 261, 'd census 261'
assert s.count(
    'R333 ranger expansion pin audit: bad ') == 1, \
    'd r333 kept'
assert s.count(
    'R332 barbarian pin audit: bad ') == 1, \
    'd r332 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count('#include "rules/thiefarmor.h"') == 1, \
    'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R334 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R334 note: the UA Thieves Table II')
print('pin round - the armor categories,')
print('the eight functions, the verified')
print('cells and holes, the footnotes; the')
print('paired attacks table - the five')
print('classes, the band edges, the')
print('verified rates (the item stays')
print('open pending the PDF); the census')
print('260 -> 261')
print('commit: R334: the UA thief armor and')
print('attacks pin round (census 261)')

