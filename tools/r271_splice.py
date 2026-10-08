#!/usr/bin/env python3
# R271 splice: the III.E misc magic explanation prose
# part 15 pins - Mac-Fuirmidh Cittern through the
# general properties and the type table, part2 lines
# 686-764 (DMG p.142-148) - the slice closing the
# Instrument of the Bards item (the kMisc3 row 26
# quadruple asterisk, 1,000 xp / 5,000 gp per level of
# instrument). The upload DROPS the TREASURE page
# headers across the instruments run (none between 674
# and 792) - the page attribution rides the compilation
# TOC anchor (the instruments at pp.147-148); NO seam
# restored this round. The instrument facts verified
# against the 1eonline.info compilation page
# instrumentofthebards.htm (the R175 precedent
# source); the level gates cross-check the bard.h
# Table II college ladder.
# 4 patches, marker-based idempotence, assert after
# every patch. ZERO apostrophes and ZERO literal
# backslashes in the content below (the printf newline
# is built via BS = chr(92)).

import os
import re
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

HDR = [
    '// ====================================================================',
    '// Adnd1 - rules/miscprose15.h',
    '// R271: the III.E misc magic explanation prose part 15',
    '// (DMG p.142-148) - Mac-Fuirmidh Cittern through the',
    '// general properties and the type table,',
    '// part2 lines 686-764 (global = 11065 + part2',
    '// line). The slice closes the Instrument of the',
    '// Bards item (the kMisc3 row 26 quadruple',
    '// quadruple asterisk, 1,000 xp / 5,000 gp per level of',
    '// instrument). The upload DROPS the TREASURE page headers',
    '// across the instruments run (none between 674 and 792) -',
    '// the page attribution rides the compilation TOC anchor',
    '// (the instruments at pp.147-148); NO seam restored this',
    '// round, the slice carries no page header. The instrument',
    '// facts verified against the 1eonline.info compilation page',
    '// instrumentofthebards.htm (the R175 precedent source);',
    '// the level gates (5th, 8th, 11th, 14th, 17th, 20th) match',
    '// the bard.h Table II college ladder.',
    '// 51 accessors: 49 scalars + 2 array walkers (the type',
    '// die table), no name collisions with miscprose1.h',
    '// through miscprose14.h. Pure data + helpers,',
    '// header-only (the grenade.h pattern).',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'inline int mmpCitternMisusePct() {',
    '    // 50 percent likely to deliver the damage to any',
    '    // non-bard or bard under 5th level',
    '    return 50;',
    '}',
    '',
    'inline int mmpCitternDamageMin() {',
    '    // the misuse delivers 3-12 hit points',
    '    return 3;',
    '}',
    '',
    'inline int mmpCitternDamageMax() {',
    '    // the upper edge of the 3-12 damage',
    '    return 12;',
    '}',
    '',
    'inline int mmpCitternLevelGate() {',
    '    // a bard of 5th or higher level uses it safely',
    '    return 5;',
    '}',
    '',
    'inline int mmpCitternCharmBonusPct() {',
    '    // a 15 percent better chance of charming',
    '    return 15;',
    '}',
    '',
    'inline int mmpCitternSongCount() {',
    '    // three songs once per day',
    '    return 3;',
    '}',
    '',
    'inline int mmpDossMisusePct() {',
    '    // 60 percent likely, any non-bard or bard under',
    '    // 8th level',
    '    return 60;',
    '}',
    '',
    'inline int mmpDossDamageMin() {',
    '    // the misuse delivers 4-16 hit points',
    '    return 4;',
    '}',
    '',
    'inline int mmpDossDamageMax() {',
    '    // the upper edge of the 4-16 damage',
    '    return 16;',
    '}',
    '',
    'inline int mmpDossLevelGate() {',
    '    // an 8th or higher level bard plays the lute',
    '    return 8;',
    '}',
    '',
    'inline int mmpDossCharmBonusPct() {',
    '    // a 20 percent better chance of charming',
    '    return 20;',
    '}',
    '',
    'inline int mmpDossSongCount() {',
    '    // three magical songs once per day',
    '    return 3;',
    '}',
    '',
    'inline int mmpDossProtFireRadiusFeet() {',
    '    // the protection from fire song in a 10 feet',
    '    // radius',
    '    return 10;',
    '}',
    '',
    'inline int mmpCanaithMisusePct() {',
    '    // 70 percent likely, any non-bard or bard under',
    '    // the 11th level',
    '    return 70;',
    '}',
    '',
    'inline int mmpCanaithDamageMin() {',
    '    // the misuse causes 5-20 hit points',
    '    return 5;',
    '}',
    '',
    'inline int mmpCanaithDamageMax() {',
    '    // the upper edge of the 5-20 damage',
    '    return 20;',
    '}',
    '',
    'inline int mmpCanaithLevelGate() {',
    '    // an 11th or higher level bard employs it',
    '    return 11;',
    '}',
    '',
    'inline int mmpCanaithCharmBonusPct() {',
    '    // adds 25 percent to the charming ability',
    '    return 25;',
    '}',
    '',
    'inline int mmpCanaithSongCount() {',
    '    // three spells once per day',
    '    return 3;',
    '}',
    '',
    'inline int mmpCanaithProtLightningRadiusFeet() {',
    '    // the protection from lightning song in a 10',
    '    // feet radius',
    '    return 10;',
    '}',
    '',
    'inline int mmpCliMisusePct() {',
    '    // 80 percent likely, any non-bard or bard of',
    '    // less than the 14th level',
    '    return 80;',
    '}',
    '',
    'inline int mmpCliDamageMin() {',
    '    // the misuse causes 6-24 hit points',
    '    return 6;',
    '}',
    '',
    'inline int mmpCliDamageMax() {',
    '    // the upper edge of the 6-24 damage',
    '    return 24;',
    '}',
    '',
    'inline int mmpCliLevelGate() {',
    '    // a 14th or higher level bard plays the lyre',
    '    return 14;',
    '}',
    '',
    'inline int mmpCliCharmBonusPct() {',
    '    // adds 30 percent to charming ability',
    '    return 30;',
    '}',
    '',
    'inline int mmpCliSongCount() {',
    '    // three songs once each per day',
    '    return 3;',
    '}',
    '',
    'inline int mmpAnstruthMisusePct() {',
    '    // 90 percent likely, any non-bard or bard of',
    '    // less than 17th level',
    '    return 90;',
    '}',
    '',
    'inline int mmpAnstruthDamageMin() {',
    '    // the misuse causes 8-32 hit points',
    '    return 8;',
    '}',
    '',
    'inline int mmpAnstruthDamageMax() {',
    '    // the upper edge of the 8-32 damage',
    '    return 32;',
    '}',
    '',
    'inline int mmpAnstruthLevelGate() {',
    '    // a 17th or higher level bard strums it',
    '    return 17;',
    '}',
    '',
    'inline int mmpAnstruthCharmBonusPct() {',
    '    // adds 35 percent to charming abilities',
    '    return 35;',
    '}',
    '',
    'inline int mmpAnstruthSongCount() {',
    '    // three spells, one each per day',
    '    return 3;',
    '}',
    '',
    'inline int mmpOllamhDamageMin() {',
    '    // a non-bard or bard under 20th level: it',
    '    // WILL inflict 10-40 hit points (no percent',
    '    // printed, the harm is certain)',
    '    return 10;',
    '}',
    '',
    'inline int mmpOllamhDamageMax() {',
    '    // the upper edge of the certain 10-40 damage',
    '    return 40;',
    '}',
    '',
    'inline int mmpOllamhLevelGate() {',
    '    // a bard of 20th or higher level plays it',
    '    return 20;',
    '}',
    '',
    'inline int mmpOllamhCharmBonusPct() {',
    '    // adds 40 percent to the charming abilities',
    '    return 40;',
    '}',
    '',
    'inline int mmpOllamhSongCount() {',
    '    // three spells, one each daily',
    '    return 3;',
    '}',
    '',
    'inline int mmpInstrumentAbilityCount() {',
    '    // four abilities: protection from evil,',
    '    // invisibility, levitate, fly',
    '    return 4;',
    '}',
    '',
    'inline int mmpInstrumentAbilityRadiusFeet() {',
    '    // the protection from evil in a 10 feet radius',
    '    return 10;',
    '}',
    '',
    'inline int mmpInstrumentAbilityPerDay() {',
    '    // each ability once per day',
    '    return 1;',
    '}',
    '',
    'inline int mmpInstrumentActivateSegments() {',
    '    // each ability takes 5 segments to activate',
    '    return 5;',
    '}',
    '',
    'inline int mmpInstrumentCompleteRounds() {',
    '    // and not less than 1 full round to complete',
    '    return 1;',
    '}',
    '',
    'inline int mmpInstrumentCollegeTurnsMin() {',
    '    // the abilities last as many turns as the',
    '    // college order, the low edge of 1-7',
    '    return 1;',
    '}',
    '',
    'inline int mmpInstrumentCollegeTurnsMax() {',
    '    // the high edge of the college order turns',
    '    return 7;',
    '}',
    '',
    'inline int mmpInstrumentMagnusTurns() {',
    '    // a magnus alumni sings for 8 turns with any',
    '    // of the 7',
    '    return 8;',
    '}',
    '',
    'inline int mmpInstrumentCharmExcessThresholdPct() {',
    '    // when the charming ability exceeds 100',
    '    // percent with the instrument bonus',
    '    return 100;',
    '}',
    '',
    'inline int mmpInstrumentCharmExcessStepPct() {',
    '    // the saving throw penalty per every 5',
    '    // percent above, 3-4 rounding to the next 5',
    '    return 5;',
    '}',
    '',
    'inline int mmpInstrumentCharmExcessPenaltyPerStep() {',
    '    // the creature saves at -1 for every step',
    '    // above 100 percent',
    '    return 1;',
    '}',
    '',
    'inline int mmpInstrumentKindRowCount() {',
    '    // the type table has 7 rows',
    '    return 7;',
    '}',
    '',
    'inline int mmpInstrumentDieLo(int i) {',
    '    // the type die band lower edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 6) i = 6;',
    '    static const int t[7] = {',
    '        1, 6, 10, 13, 16, 18, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int mmpInstrumentDieHi(int i) {',
    '    // the type die band upper edges; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 6) i = 6;',
    '    static const int t[7] = {',
    '        5, 9, 12, 15, 17, 19, 20,',
    '    };',
    '    return t[i];',
    '}',
    '',
    '}  // namespace rules',
]

AUDIT = [
    '    // ---- R271: the III.E misc magic explanation',
    '    // prose part 15 ----',
    '    // Mac-Fuirmidh Cittern through the type table,',
    '    // part2 lines 686-764 - the slice closing the',
    '    // kMisc3 row 26 instrument item.',
    '    {',
    '        int bad = 0;',
    '        if (rules::mmpCitternMisusePct() != 50 ||',
    '            rules::mmpCitternDamageMin() != 3 ||',
    '            rules::mmpCitternDamageMax() != 12 ||',
    '            rules::mmpCitternLevelGate() != 5 ||',
    '            rules::mmpCitternCharmBonusPct() != 15 ||',
    '            rules::mmpCitternSongCount() != 3) ++bad;',
    '        if (rules::mmpDossMisusePct() != 60 ||',
    '            rules::mmpDossDamageMin() != 4 ||',
    '            rules::mmpDossDamageMax() != 16 ||',
    '            rules::mmpDossLevelGate() != 8 ||',
    '            rules::mmpDossCharmBonusPct() != 20 ||',
    '            rules::mmpDossSongCount() != 3 ||',
    '            rules::mmpDossProtFireRadiusFeet() != 10) ++bad;',
    '        if (rules::mmpCanaithMisusePct() != 70 ||',
    '            rules::mmpCanaithDamageMin() != 5 ||',
    '            rules::mmpCanaithDamageMax() != 20 ||',
    '            rules::mmpCanaithLevelGate() != 11 ||',
    '            rules::mmpCanaithCharmBonusPct() != 25 ||',
    '            rules::mmpCanaithSongCount() != 3 ||',
    '            rules::mmpCanaithProtLightningRadiusFeet() !=',
    '            10) ++bad;',
    '        if (rules::mmpCliMisusePct() != 80 ||',
    '            rules::mmpCliDamageMin() != 6 ||',
    '            rules::mmpCliDamageMax() != 24 ||',
    '            rules::mmpCliLevelGate() != 14 ||',
    '            rules::mmpCliCharmBonusPct() != 30 ||',
    '            rules::mmpCliSongCount() != 3) ++bad;',
    '        if (rules::mmpAnstruthMisusePct() != 90 ||',
    '            rules::mmpAnstruthDamageMin() != 8 ||',
    '            rules::mmpAnstruthDamageMax() != 32 ||',
    '            rules::mmpAnstruthLevelGate() != 17 ||',
    '            rules::mmpAnstruthCharmBonusPct() != 35 ||',
    '            rules::mmpAnstruthSongCount() != 3) ++bad;',
    '        if (rules::mmpOllamhDamageMin() != 10 ||',
    '            rules::mmpOllamhDamageMax() != 40 ||',
    '            rules::mmpOllamhLevelGate() != 20 ||',
    '            rules::mmpOllamhCharmBonusPct() != 40 ||',
    '            rules::mmpOllamhSongCount() != 3) ++bad;',
    '        // the printed ladders, verified against the',
    '        // printed values: the misuse percent climbs',
    '        // by 10, the level gates by 3, the charm',
    '        // bonus by 5',
    '        if (rules::mmpDossMisusePct() !=',
    '            rules::mmpCitternMisusePct() + 10 ||',
    '            rules::mmpCanaithMisusePct() !=',
    '            rules::mmpDossMisusePct() + 10 ||',
    '            rules::mmpCliMisusePct() !=',
    '            rules::mmpCanaithMisusePct() + 10 ||',
    '            rules::mmpAnstruthMisusePct() !=',
    '            rules::mmpCliMisusePct() + 10) ++bad;',
    '        if (rules::mmpDossLevelGate() !=',
    '            rules::mmpCitternLevelGate() + 3 ||',
    '            rules::mmpCanaithLevelGate() !=',
    '            rules::mmpDossLevelGate() + 3 ||',
    '            rules::mmpCliLevelGate() !=',
    '            rules::mmpCanaithLevelGate() + 3 ||',
    '            rules::mmpAnstruthLevelGate() !=',
    '            rules::mmpCliLevelGate() + 3 ||',
    '            rules::mmpOllamhLevelGate() !=',
    '            rules::mmpAnstruthLevelGate() + 3) ++bad;',
    '        if (rules::mmpDossCharmBonusPct() !=',
    '            rules::mmpCitternCharmBonusPct() + 5 ||',
    '            rules::mmpCanaithCharmBonusPct() !=',
    '            rules::mmpDossCharmBonusPct() + 5 ||',
    '            rules::mmpCliCharmBonusPct() !=',
    '            rules::mmpCanaithCharmBonusPct() + 5 ||',
    '            rules::mmpAnstruthCharmBonusPct() !=',
    '            rules::mmpCliCharmBonusPct() + 5 ||',
    '            rules::mmpOllamhCharmBonusPct() !=',
    '            rules::mmpAnstruthCharmBonusPct() + 5) ++bad;',
    '        // the general properties of all bard',
    '        // instruments',
    '        if (rules::mmpInstrumentAbilityCount() != 4 ||',
    '            rules::mmpInstrumentAbilityRadiusFeet() !=',
    '            10 ||',
    '            rules::mmpInstrumentAbilityPerDay() != 1 ||',
    '            rules::mmpInstrumentActivateSegments() != 5 ||',
    '            rules::mmpInstrumentCompleteRounds() !=',
    '            1) ++bad;',
    '        // the college order runs 1-7, the magnus',
    '        // alumni sings one turn longer',
    '        if (rules::mmpInstrumentCollegeTurnsMin() != 1 ||',
    '            rules::mmpInstrumentCollegeTurnsMax() != 7 ||',
    '            rules::mmpInstrumentMagnusTurns() !=',
    '            rules::mmpInstrumentCollegeTurnsMax() +',
    '            1) ++bad;',
    '        // the charm excess: -1 per 5 percent above',
    '        // 100',
    '        if (rules::mmpInstrumentCharmExcessThresholdPct() !=',
    '            100 ||',
    '            rules::mmpInstrumentCharmExcessStepPct() != 5 ||',
    '            rules::mmpInstrumentCharmExcessPenaltyPerStep() !=',
    '            1) ++bad;',
    '        // the type die table against static twins',
    '        static const int kTlo[7] = {',
    '            1, 6, 10, 13, 16, 18, 20,',
    '        };',
    '        static const int kThi[7] = {',
    '            5, 9, 12, 15, 17, 19, 20,',
    '        };',
    '        if (rules::mmpInstrumentKindRowCount() != 7) ++bad;',
    '        for (int i = 0; i < 7; ++i)',
    '            if (rules::mmpInstrumentDieLo(i) != kTlo[i] ||',
    '                rules::mmpInstrumentDieHi(i) != kThi[i]) ++bad;',
    '        // the type dice tile 1-20 without gaps',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::mmpInstrumentDieLo(i + 1) !=',
    '                rules::mmpInstrumentDieHi(i) +',
    '                1) ++bad;',
    '        if (rules::mmpInstrumentDieLo(0) != 1 ||',
    '            rules::mmpInstrumentDieHi(6) != 20) ++bad;',
    '        // the kMisc3 row 26 quadruple asterisk base',
    '        if (rules::m3RowLo(26) != 73 ||',
    '            rules::m3RowHi(26) != 78 ||',
    '            rules::m3StarCount(26) != 4 ||',
    '            rules::m3InstrumentBaseXp() != 1000 ||',
    '            rules::m3InstrumentBaseGp() != 5000) ++bad;',
    '        printf("R271 misc magic prose part 15 pins audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
]

GAP = [
    'R271 landed the III.E misc',
    'magic explanation prose part',
    '15 (part2 lines 686-764;',
    'global = 11065 + part2 line),',
    'Mac-Fuirmidh Cittern through',
    'the general properties and the',
    'type table - closing the',
    'Instrument of the Bards item',
    '(the kMisc3 row 26 quadruple',
    'asterisk, 1,000 xp / 5,000 gp',
    'per level of instrument). The',
    'upload DROPS the TREASURE page',
    'headers across the instruments',
    'run (none between 674 and',
    '792) - the page attribution',
    'rides the compilation TOC',
    'anchor (the instruments at',
    'pp.147-148); NO seam restored',
    'this round. The instrument',
    'facts verified against the',
    'compilation page',
    'instrumentofthebards.htm (the',
    'R175 precedent source). The',
    'items: Mac-Fuirmidh Cittern (50',
    'percent misuse, 3-12 damage,',
    'the 5th level gate, +15 percent',
    'charm, 3 songs: barkskin, cure',
    'light wounds, obscurement;',
    'lower bards cannot use it),',
    'Doss Lute (60 percent, 4-16,',
    'the 8th gate, +20 percent,',
    'hold animal, neutralize',
    'poison, protection from fire in',
    'a 10 feet radius), Canaith',
    'Mandolin (70 percent, 5-20,',
    'the 11th gate, +25 percent,',
    'cure serious wounds, dispel',
    'magic, protection from',
    'lightning in a 10 feet radius),',
    'Cli Lyre (80 percent, 6-24,',
    'the 14th gate, +30 percent,',
    'control winds, transmute rock',
    'to mud, wall of fire),',
    'Anstruth Harp (90 percent,',
    '8-32, the 17th gate, +35',
    'percent, cure critical wounds,',
    'wall of thorns, weather',
    'summoning), Ollamh Harp (no',
    'percent printed, the harm is',
    'certain: 10-40, the 20th gate,',
    '+40 percent, confusion,',
    'control weather, fire storm).',
    'General properties: the 7',
    'instruments look exactly',
    'alike (dweomers); 4 abilities',
    'once each per day - protection',
    'from evil in a 10 feet radius,',
    'invisibility, levitate, fly -',
    'lasting the college order in',
    'turns 1-7, the magnus alumni 8',
    'turns; each ability 5 segments',
    'to activate, not less than 1',
    'full round; a charming ability',
    'above 100 percent saves at -1',
    'per 5 percent above (3-4',
    'rounding to the next 5). The',
    'type table: 1-5 bandore, 6-9',
    'cittern, 10-12 doss lute,',
    '13-15 canaith mandolin, 16-17',
    'cli lyre, 18-19 anstruth harp,',
    '20 ollamh harp. The level',
    'gates match the bard.h Table',
    'II college ladder (5th, 8th,',
    '11th, 14th, 17th, 20th). 51',
    'accessors: 49 scalars + 2',
    'walkers (the type die table),',
    'no name collisions parts 1-14.',
    'New R271 battery audit; census',
    '189. Next: part 16 -',
    'Iron Flask onward in part2',
    'from line 766 (global 11831;',
    'the javelins, jewels and',
    'Keoghtom ointment follow;',
    'kMisc3 rows 27+ begin).',
]

# ---- the splice self-asserts ----
HTEXT = NL.join(HDR)
defs = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(]', HTEXT)
assert len(defs) == 51, 'accessor count is not 51'
assert len(set(defs)) == 51, 'accessor names not unique'
scal = re.findall(r'inline int (mmp[A-Za-z0-9]+)[(][)]', HTEXT)
walk = [d for d in defs if d not in scal]
assert len(scal) == 49, 'scalar count is not 49'
assert len(walk) == 2, 'walker count is not 2'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(mmp[A-Za-z0-9]+)[(]', ATEXT))
assert audited == set(defs), 'audit does not probe every accessor'
for p in range(1, 15):
    pp = os.path.join(ROOT, 'rules/miscprose%d.h' % p)
    if os.path.exists(pp):
        pt = open(pp, encoding='utf-8').read()
        for n in defs:
            assert n not in pt, 'name collision with part %d' % p
for grp in (HDR, AUDIT, GAP):
    for el in grp:
        if isinstance(el, str):
            assert chr(39) not in el, 'apostrophe in content'
            probe = el.replace(chr(92) + 'n', '')
            assert chr(92) not in probe, 'backslash in content'
            assert NL not in el, 'list element spans lines'
assert ATEXT.count('{') == ATEXT.count('}'), 'audit braces unbalanced'
assert ATEXT.count('(') == ATEXT.count(')'), 'audit parens unbalanced'
assert AUDIT[-1] == '    }', 'audit block does not close'
assert HDR[-1] == '}  // namespace rules', 'header does not close'
assert ATEXT.count('R271 misc magic prose part 15 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'

# ---- patch 1: create rules/miscprose15.h ----
p = 'rules/miscprose15.h'
if os.path.exists(os.path.join(ROOT, p)):
    assert rd(p) == HTEXT, 'miscprose15.h exists but differs'
    already += 1
else:
    wr(p, HTEXT)
    applied += 1
assert rd(p) == HTEXT, 'patch 1 failed'

# ---- patch 2: the regtest include ----
p = 'regtest.cpp'
s = rd(p)
inc = '#include "rules/miscprose15.h"  // R271: the III.E misc magic explanation prose part 15 pins'
if inc in s:
    already += 1
else:
    anchor = '#include "rules/miscprose14.h"  // R270: the III.E misc magic explanation prose part 14 pins'
    assert s.count(anchor) == 1, 'include anchor not unique'
    s = s.replace(anchor, anchor + NL + inc, 1)
    wr(p, s)
    applied += 1
assert inc in rd(p), 'patch 2 failed'
assert rd(p).count('#include "rules/miscprose15.h"') == 1, 'patch 2 doubled'

# ---- patch 3: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R271: the III.E misc magic explanation'
if mark in s:
    already += 1
else:
    anchor = '    // ---- R227: the wis mental save wiring audit ----'
    assert s.count(anchor) == 1, 'audit anchor not unique'
    s = s.replace(anchor, ATEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
assert mark in rd(p), 'patch 3 failed'
assert rd(p).count(mark) == 1, 'patch 3 doubled'

# ---- patch 4: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R271 landed the III.E misc'
if mark in s:
    already += 1
else:
    anchor = 'continues).' + NL + NL + 'Categories:'
    assert s.count(anchor) == 1, 'gap anchor not unique'
    s = s.replace(anchor, 'continues).' + NL + NL + NL.join(GAP) + NL + NL + 'Categories:', 1)
    wr(p, s)
    applied += 1
assert mark in rd(p), 'patch 4 failed'
assert rd(p).count(mark) == 1, 'patch 4 doubled'

print('R271 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R271 note: 4 patches; the III.E misc magic')
print('explanation prose part 15 - Mac-Fuirmidh')
print('Cittern through the general properties and')
print('the type table, part2 lines 686-764; census 189.')
print('commit: R271: the III.E misc magic explanation prose part 15 pinned - Mac-Fuirmidh Cittern through the general properties and type table in part2 lines 686-764 (census 189)')

