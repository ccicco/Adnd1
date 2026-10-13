#!/usr/bin/env python3
# R415: the UA PERSON-AFFECTING
# CANTRIP DESCRIPTIONS (p. 49)
# - the fourth of the six MU
# cantrip description rounds;
# the R363/R412/R413/R414
# precedents ride (the
# descriptions pin; the
# casting-time fraction cells
# garble in the scan and
# record as holes pending the
# PDF read). The clean djvu
# scan carries all 10
# person-affecting blocks;
# the systematic OCR reads
# resolve with independent
# confirmation: the school
# tags print clean EXCEPT the
# two reads this round - the
# scan prints "TVvitch" for
# the roster's Twitch (the
# name resolves via the LIVE
# R341/R401 roster
# cross-check - the roster is
# the independent
# confirmation) and Giggle
# prints "(Charm)" while Wink
# prints "(Enchantment)" in
# the SAME section - the
# print distinguishes the two,
# so Charm pins AS PRINTED, a
# NEW school code this round
# (the never-guess doctrine).
# The census: Evocation 8
# (Belch, Blink, Cough, Nod,
# Scratch, Sneeze, Twitch,
# Yawn), Enchantment 1 (Wink),
# Charm 1 (Giggle); Abjuration
# 0, Alteration 0, Illusion 0.
# The area lines print clean
# for ALL 10 blocks - ZERO
# area holes: the one-person
# six (Belch, Blink, Cough,
# Giggle, Nod, Wink - a NEW
# area kind code) and the
# one-creature four (Scratch,
# Sneeze, Twitch, Yawn - a
# NEW area kind code); ALL 10
# casting-time cells print
# fraction garbles - the whole
# family records as holes
# pending the PDF read - never
# guesses. The mechanics pin
# clean: the Blink half-second
# momentary read, the Cough
# 1-3 second spasms, the
# Giggle 2-3 second chuckle,
# the Scratch one-second itch
# relief, and the YAWN SLEEP
# SUSCEPTIBILITY - the window
# (the balance of the cast
# round + the whole following
# round), the 1 additional
# vulnerable creature, the 4
# or fewer HD band, the 4+1 to
# 4+4 re-roll band, the up-to
# 5+2 HD reach, and the 50%
# unaffected chance.

# 1. rules/uacantrips4.h (NEW,
#    prefix ucp - verified no
#    collision): the 10
#    person-affecting cantrips
#    in R341/R401 roster order,
#    the struct + 18 inline
#    functions.
# 2. regtest.cpp: the include
#    rides the R414 include;
#    the R415 audit block lands
#    before the R227 anchor -
#    the 10 names cross-check
#    the R341/R401 roster
#    (uastCantripName(3, i))
#    live name for name, the
#    count cross-checks
#    uastCantripCount(3), the
#    schools/areas pin per
#    row, the censuses count,
#    the mechanics pin with
#    the yawn band derivation
#    cross-checking itself;
#    census 341 -> 342.
# 3. tools/ua_gap_report.md:
#    the MU cantrips box takes
#    AMENDED R415 - the
#    person-affecting
#    descriptions land; the
#    personal and
#    haunting-sound descriptions
#    stay open.
# 4. The seed takes the R414
#    record.

import io
import os
import re as _re

NL = chr(10)

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def E(*lines):
    return NL.join(lines)


def die(msg):
    raise SystemExit(
        'R415 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


def newfile(path, body, label):
    if os.path.exists(path):
        already.append(label)
        return
    wr(path, body)
    applied.append(label)


# ---- the codes ----
# schools: 0 Evocation, 1
# Abjuration, 2 Alteration, 3
# Enchantment, 4 Illusion, 5
# Charm (NEW this round - the
# print distinguishes Charm
# from Enchantment in the same
# section; pins AS PRINTED).
# area kinds: 8 one person
# (NEW), 9 one creature (NEW);
# -1 the hole sentinel (none
# this round).
S_EVO, S_ABJ = 0, 1
S_ALT, S_ENCH = 2, 3
S_ILL, S_CHARM = 4, 5
A_HOLE = -1
A_PERSON, A_CREATURE = 8, 9

# The 10 person-affecting
# cantrips, in the R341/R401
# roster order: the name, the
# school, the area kind, the
# area value.
ROWS = [
    ('Belch', S_EVO, A_PERSON, 0),
    ('Blink', S_EVO, A_PERSON, 0),
    ('Cough', S_EVO, A_PERSON, 0),
    ('Giggle', S_CHARM, A_PERSON, 0),
    ('Nod', S_EVO, A_PERSON, 0),
    ('Scratch', S_EVO, A_CREATURE, 0),
    ('Sneeze', S_EVO, A_CREATURE, 0),
    ('Twitch', S_EVO, A_CREATURE, 0),
    ('Wink', S_ENCH, A_PERSON, 0),
    ('Yawn', S_EVO, A_CREATURE, 0),
]

SCHOOL_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[1] == s)
    for s in (0, 1, 2, 3, 4, 5))
AREA_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[2] == a)
    for a in (A_PERSON, A_CREATURE,
              A_HOLE))

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R414 landed 2026-10-13:',
    '  commit 008066d (census 341,',
    '  preflight GREEN), the UA',
    '  LEGERDEMAIN CANTRIP',
    '  DESCRIPTIONS (pp. 48-49) -',
    '  the third of the six MU',
    '  cantrip description rounds;',
    '  the precedents ride; the',
    '  casting-time family records',
    '  as holes pending the PDF',
    '  read. rules/uacantrips3.h',
    '  (prefix ucl): the 6',
    '  legerdemain cantrips in',
    '  roster order, the school',
    '  census 0/0/3/1/2 (Illusion',
    '  a NEW school code), ALL 6',
    '  areas clean, the HIDE',
    '  DURATION LADDER (1 turn at',
    '  2 cubic yards to 1 segment',
    '  at 38) with the derivation',
    '  cross-check. THE SIM CAUGHT',
    '  AN R391-CLASS INVERTED',
    '  CROSS-CHECK pre-publish (the',
    '  first ladder derivation',
    '  fired on healthy data) -',
    '  the second live R391 catch.',
    '  First-try GREEN. The md5',
    '  diverged for the',
    '  TWENTY-THIRD round running',
    '  - benign; the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R414 landed 2026-10-13' in s:
    already.append('seed: the R414 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R414 record')
s = rd(SD)
if s.count('R414 landed 2026-10-13') != 1:
    die('the R414 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uacantrips4.h =========
UC = 'rules/uacantrips4.h'

HDR = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uacantrips4.h',
    '// The UA MAGIC-USER CANTRIP',
    '// DESCRIPTIONS, part 4 (R415):',
    '// the PERSON-AFFECTING',
    '// category (p. 49), 10',
    '// cantrips. The R363/R412/',
    '// R413/R414 precedents ride:',
    '// the descriptions pin; the',
    '// casting-time fraction cells',
    '// garble in the scan (the',
    '// whole family) and record',
    '// as holes pending the PDF',
    '// read - never guesses.',
    '//',
    '// The school tags print clean',
    '// except two reads: the scan',
    '// prints "TVvitch" for the',
    "// roster's Twitch (the name",
    '// resolves via the LIVE',
    '// R341/R401 roster cross-check',
    '// - the roster is the',
    '// independent confirmation),',
    '// and Giggle prints "(Charm)"',
    '// while Wink prints',
    '// "(Enchantment)" in the SAME',
    '// section - the print',
    '// distinguishes the two, so',
    '// Charm pins AS PRINTED (a',
    '// NEW school code; the',
    '// never-guess doctrine). The',
    '// census: Evocation 8,',
    '// Enchantment 1 (Wink),',
    '// Charm 1 (Giggle).',
    '//',
    '// The area lines print clean',
    '// for ALL 10 blocks - ZERO',
    '// area holes: the one-person',
    '// six (Belch, Blink, Cough,',
    '// Giggle, Nod, Wink - a NEW',
    '// area kind code) and the',
    '// one-creature four (Scratch,',
    '// Sneeze, Twitch, Yawn - a',
    '// NEW area kind code).',
    '//',
    '// The mechanics pin clean: the',
    '// Blink half-second momentary',
    '// read, the Cough 1-3 second',
    '// spasms, the Giggle 2-3',
    '// second chuckle, the Scratch',
    '// one-second itch relief, and',
    '// the YAWN SLEEP',
    '// SUSCEPTIBILITY - the window',
    '// (the balance of the cast',
    '// round + the whole following',
    '// round), the 1 additional',
    '// vulnerable creature, the 4',
    '// or fewer HD band, the 4+1 to',
    '// 4+4 re-roll band, the up-to',
    '// 5+2 HD reach, and the 50%',
    '// unaffected chance.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The school codes (Charm NEW',
    '// this round, pinned AS',
    '// PRINTED).',
    'const int UCP_EVO = 0;',
    'const int UCP_ABJ = 1;',
    'const int UCP_ALT = 2;',
    'const int UCP_ENCH = 3;',
    'const int UCP_ILL = 4;',
    'const int UCP_CHARM = 5;',
    '',
    '// The area kind codes (one',
    '// person and one creature NEW',
    '// this round).',
    'const int UCP_AREA_HOLE = -1;',
    'const int UCP_AREA_PERSON = 8;',
    'const int UCP_AREA_CREATURE = 9;',
    '',
    '// One person-affecting',
    '// cantrip: the name, the',
    '// school, the area kind and',
    '// the area value (0 when the',
    '// kind carries no number).',
    'struct UcpCantrip {',
    '    const char* name;',
    '    int school;',
    '    int areaKind;',
    '    int areaVal;',
    '};',
    '',
    '// The 10 person-affecting',
    '// cantrips, in the R341/R401',
    '// roster order.',
    'inline const UcpCantrip&'
    ' ucpPersonAffecting(int i) {',
    '    static const UcpCantrip'
    ' T[10] = {')

for nm, sc, ak, av in ROWS:
    HDR += NL + E(
        '        { "%s", %d, %d, %d },'
        % (nm, sc, ak, av))

HDR += NL + E(
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 9) i = 9;',
    '    return T[i];',
    '}',
    '',
    '// The count.',
    'inline int ucpPersonAffectingCount()',
    '    { return 10; }',
    '',
    '// The school census helper.',
    'inline int ucpSchoolCount(int s)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 10; ++i)',
    '        if (ucpPersonAffecting(i)'
    '.school == s)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The area kind census helper.',
    'inline int ucpAreaKindCount(int a)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 10; ++i)',
    '        if (ucpPersonAffecting(i)'
    '.areaKind == a)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The casting-time hole family:',
    '// ALL 10 casting-time cells print',
    '// fraction garbles in the scan -',
    '// the whole family records as',
    '// holes pending the PDF read (the',
    '// R363/R412/R413/R414 posture).',
    'inline bool ucpCastTimesAreHoles()',
    '    { return true; }',
    '',
    '// ---- the mechanics pins ----',
    '',
    '// The Blink read: momentary,',
    '// lasting no more than half a',
    '// second (in halves).',
    'inline int ucpBlinkDurationHalfSecs()',
    '    { return 1; }',
    '',
    '// The Cough spasms: from 1 to',
    '// 3 seconds on a failed save.',
    'inline int ucpCoughMinSeconds()',
    '    { return 1; }',
    '',
    'inline int ucpCoughMaxSeconds()',
    '    { return 3; }',
    '',
    '// The Giggle chuckle: about 2',
    '// or 3 seconds on a failed',
    '// save.',
    'inline int ucpGiggleMinSeconds()',
    '    { return 2; }',
    '',
    'inline int ucpGiggleMaxSeconds()',
    '    { return 3; }',
    '',
    '// The Scratch relief: the',
    '// scratching takes but a',
    '// second and the itch ceases.',
    'inline int ucpScratchSeconds()',
    '    { return 1; }',
    '',
    '// ---- the yawn sleep',
    '// susceptibility ----',
    '',
    '// The window: the balance of',
    '// the round in which the yawn',
    '// was cast, plus the whole of',
    '// the following round (the',
    '// span covers 2 rounds).',
    'inline int ucpYawnWindowRounds()',
    '    { return 2; }',
    '',
    '// The extra vulnerable: 1',
    '// additional creature of 4 or',
    '// fewer hit dice may be',
    '// affected by the sleep spell.',
    'inline int ucpYawnExtraVulnerable()',
    '    { return 1; }',
    '',
    '// The low band: creatures of',
    '// 4 or fewer hit dice (the',
    '// sleep spell norm).',
    'inline int ucpYawnSleepHdLow()',
    '    { return 4; }',
    '',
    '// The re-roll band: creatures',
    '// of 4+1 to 4+4 hit dice gain',
    '// a chance to be affected',
    '// (encoded lo*10+plus: 41..44).',
    'inline int ucpYawnSleepBandLo()',
    '    { return 41; }',
    '',
    'inline int ucpYawnSleepBandHi()',
    '    { return 44; }',
    '',
    '// The reach: even a creature',
    '// of up to 5+2 hit dice can',
    '// be affected (encoded 52),',
    '// rolled as if in the band.',
    'inline int ucpYawnSleepHdMax()',
    '    { return 52; }',
    '',
    '// The unaffected chance: the',
    '// over-band creature has a',
    '// 50% chance of NOT being',
    '// affected.',
    'inline int ucpYawnUnaffectedPct()',
    '    { return 50; }',
    '',
    '}   // namespace rules',
    '')

newfile(UC, HDR + NL,
        'the person-affecting'
        ' cantrips header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uacantrips3.h"  '
     '// R414: the UA legerdemain'
     ' cantrips',
     E(
    '#include "rules/uacantrips3.h"  '
    '// R414: the UA legerdemain'
    ' cantrips',
    '#include "rules/uacantrips4.h"  '
    '// R415: the UA person-'
    'affecting cantrips'),
     'regtest: the person-affecting'
     ' cantrips include')

AUD = E(
    '    // ---- R415: the UA',
    '    // person-affecting cantrips',
    '    // pin audit ----',
    '    // The 10 person-affecting',
    '    // descriptions pin: the names',
    '    // cross-check the R341/R401',
    '    // roster live (the scan\'s',
    '    // "TVvitch" resolves as',
    '    // Twitch via the roster - the',
    '    // independent confirmation),',
    '    // the schools pin per row',
    '    // (Charm AS PRINTED, a NEW',
    '    // code - Giggle prints Charm',
    '    // while Wink prints',
    '    // Enchantment in the same',
    '    // section), the areas pin per',
    '    // row (ZERO area holes; one',
    '    // person and one creature NEW',
    '    // area kinds), the censuses',
    '    // count, the mechanics pin with',
    '    // the yawn band derivation',
    '    // cross-checking itself; census',
    '    // 341 -> 342.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (ucpPersonAffectingCount()'
    ' != 10)',
    '            ++bad;',
    '        if (uastCantripCount(3)'
    ' != 10)',
    '            ++bad;',
    '        // ---- the school census ----',
    '        if (ucpSchoolCount(UCP_EVO)'
    ' != 8',
    '                || ucpSchoolCount'
    '(UCP_ABJ) != 0',
    '                || ucpSchoolCount'
    '(UCP_ALT) != 0',
    '                || ucpSchoolCount'
    '(UCP_ENCH) != 1',
    '                || ucpSchoolCount'
    '(UCP_ILL) != 0',
    '                || ucpSchoolCount'
    '(UCP_CHARM) != 1) ++bad;',
    '        // ---- the area census ----',
    '        if (ucpAreaKindCount'
    '(UCP_AREA_PERSON) != 6',
    '                || ucpAreaKindCount'
    '(UCP_AREA_CREATURE) != 4',
    '                || ucpAreaKindCount'
    '(UCP_AREA_HOLE) != 0) ++bad;')

# the per-row pins: name (cross-
# checked against the R341/R401
# roster live), school, area
for i, (nm, sc, ak, av) in \
        enumerate(ROWS):
    AUD += NL + E(
        '        if (strcmp'
        '(ucpPersonAffecting(%d)'
        '.name,' % i,
        '                   '
        'uastCantripName(3, %d)) != 0'
        % i,
        '                ||'
        ' ucpPersonAffecting(%d)' % i,
        '                   .school'
        ' != %d' % sc,
        '                ||'
        ' ucpPersonAffecting(%d)' % i,
        '                   .areaKind'
        ' != %d' % ak,
        '                ||'
        ' ucpPersonAffecting(%d)' % i,
        '                   .areaVal'
        ' != %d) ++bad;' % av)

AUD += NL + E(
    '        // ---- the hole family ----',
    '        if (!ucpCastTimesAreHoles())',
    '            ++bad;',
    '        // ---- the mechanics ----',
    '        if (ucpBlinkDuration'
    'HalfSecs() != 1',
    '                || ucpScratch'
    'Seconds() != 1) ++bad;',
    '        if (ucpCoughMinSeconds()'
    ' != 1',
    '                || ucpCoughMax'
    'Seconds() != 3) ++bad;',
    '        if (ucpGiggleMinSeconds()'
    ' != 2',
    '                || ucpGiggleMax'
    'Seconds() != 3) ++bad;',
    '        // The cough/giggle bands',
    '        // are distinct and giggle',
    '        // never exceeds cough max.',
    '        if (ucpGiggleMaxSeconds()'
    ' > ucpCoughMaxSeconds()',
    '                || ucpGiggle'
    'MinSeconds()',
    '                   >= ucpGiggle'
    'MaxSeconds()) ++bad;',
    '        // ---- the yawn sleep',
    '        // susceptibility ----',
    '        if (ucpYawnWindowRounds()'
    ' != 2',
    '                || ucpYawnExtra'
    'Vulnerable() != 1) ++bad;',
    '        if (ucpYawnSleepHdLow()'
    ' != 4',
    '                || ucpYawnSleep'
    'BandLo() != 41',
    '                || ucpYawnSleep'
    'BandHi() != 44',
    '                || ucpYawnSleep'
    'HdMax() != 52',
    '                || ucpYawn'
    'UnaffectedPct() != 50) ++bad;',
    '        // The band derivation: the',
    '        // re-roll band 41..44 sits',
    '        // in the 4 HD tens, opens',
    '        // at +1, closes at +4, and',
    '        // the 52 reach rides the 5',
    '        // HD tens with +2.',
    '        if (ucpYawnSleepBandLo()'
    ' / 10',
    '                != ucpYawnSleep'
    'BandHi() / 10',
    '                || ucpYawnSleep'
    'BandLo() % 10 != 1',
    '                || ucpYawnSleep'
    'BandHi() % 10 != 4',
    '                || ucpYawnSleep'
    'BandHi() / 10',
    '                   != ucpYawnSleep'
    'HdLow()',
    '                || ucpYawnSleep'
    'HdMax() / 10',
    '                   != ucpYawnSleep'
    'HdLow() + 1',
    '                || ucpYawnSleep'
    'HdMax() % 10 != 2)',
    '            ++bad;',
    '        printf("R415 UA person-'
    'affecting cantrips pin'
    ' audit: bad %d'
    + chr(92) + 'n\", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R415 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '      - AMENDED R414: the',
    '        legerdemain descriptions',
    '        land (rules/uacantrips3.h)',
    '        - the 6 blocks pin schools',
    '        (the 0/0/3/1/2 census -',
    '        Illusion a NEW school',
    '        code), ALL 6 areas clean',
    '        (ZERO area holes - the',
    '        one-object three, the',
    '        Distract Special, the',
    '        Palm/Present one small',
    '        item pair, a NEW area',
    '        kind), the whole',
    '        casting-time family the',
    '        recorded holes pending',
    '        the PDF read (the',
    '        R363/R412/R413 posture),',
    '        the mechanics pin (the',
    '        change 50% size band +',
    '        the turn/round/day',
    '        durations, the distract',
    '        10-foot range + segment,',
    '        the HIDE DURATION LADDER',
    '        (1 turn at 2 cubic yards',
    '        to 1 segment at 38,',
    '        cross-checking itself by',
    '        derivation), the mute',
    '        round, the palm segment,',
    '        the present 2-foot radius',
    '        + dozen coins); the',
    '        person-affecting, personal',
    '        and haunting-sound',
    '        descriptions stay open.'),
    E(
    '      - AMENDED R415: the',
    '        person-affecting',
    '        descriptions land (rules/',
    '        uacantrips4.h) - the 10',
    '        blocks pin schools (the',
    '        8/0/0/1/0/1 census -',
    '        Charm AS PRINTED, a NEW',
    '        school code; the scan\'s',
    '        "TVvitch" resolves as',
    '        Twitch via the live',
    '        roster), ALL 10 areas',
    '        clean (ZERO area holes -',
    '        the one-person six and',
    '        the one-creature four,',
    '        NEW area kinds), the',
    '        whole casting-time family',
    '        the recorded holes pending',
    '        the PDF read, the',
    '        mechanics pin (the blink',
    '        half-second, the cough',
    '        1-3 and giggle 2-3 second',
    '        bands, the scratch',
    '        second, and the YAWN',
    '        SLEEP SUSCEPTIBILITY -',
    '        the 2-round window, the',
    '        extra vulnerable creature,',
    '        the 4-HD band, the 41..44',
    '        re-roll band, the 52',
    '        reach, the 50% unaffected',
    '        chance, the derivation',
    '        cross-checking itself);',
    '        the personal and',
    '        haunting-sound descriptions',
    '        stay open.',
    '      - AMENDED R414: the',
    '        legerdemain descriptions',
    '        land (rules/uacantrips3.h)',
    '        - the 6 blocks pin schools',
    '        (the 0/0/3/1/2 census -',
    '        Illusion a NEW school',
    '        code), ALL 6 areas clean',
    '        (ZERO area holes - the',
    '        one-object three, the',
    '        Distract Special, the',
    '        Palm/Present one small',
    '        item pair, a NEW area',
    '        kind), the whole',
    '        casting-time family the',
    '        recorded holes pending',
    '        the PDF read (the',
    '        R363/R412/R413 posture),',
    '        the mechanics pin (the',
    '        change 50% size band +',
    '        the turn/round/day',
    '        durations, the distract',
    '        10-foot range + segment,',
    '        the HIDE DURATION LADDER',
    '        (1 turn at 2 cubic yards',
    '        to 1 segment at 38,',
    '        cross-checking itself by',
    '        derivation), the mute',
    '        round, the palm segment,',
    '        the present 2-foot radius',
    '        + dozen coins); the',
    '        person-affecting, personal',
    '        and haunting-sound',
    '        descriptions stay open.'),
    'gap: the MU cantrips box takes'
    ' R415')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 342:
    die('the census %d' % s.count('audit: bad'))
if s.count('R415 UA person-affecting'
           ' cantrips pin audit') != 1:
    die('the R415 audit label')
if s.count('ucpPersonAffecting') != \
        4 * len(ROWS) + 1:
    die('the ucpPersonAffecting call'
        ' count %d'
        % s.count('ucpPersonAffecting'))

# the R412b resolution guard:
# every ucp symbol the audit
# calls must be defined in the
# emitted header.
_used = set(_re.findall(r'\bucp\w+', s))
_def = set(_re.findall(r'\bucp\w+',
                       rd(UC)))
if _used - _def:
    die('undefined ucp calls %s'
        % sorted(_used - _def))

p = rd(UC)
if p.count('inline') != 18:
    die('the person-affecting cantrips'
        ' inline count %d'
        % p.count('inline'))
if not p.endswith(NL):
    die('the person-affecting cantrips'
        ' trailing newline')

# the R412b class guard: every
# emitted header line must be a
# comment, a preprocessor line,
# or classifiable C++ code (no
# bare prose survives this).
for ln in p.split(NL):
    if ln and not ln.startswith((
            '//', '#', 'namespace',
            'inline', 'const', 'struct',
            '{', '}', '    ',
            '        ',
            '            ')):
        die('a non-code header line'
            ' %r' % ln[:44])

g = rd(GP)
if g.count('AMENDED R415') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R415'))

for path, mark in (
        (UC, 'ucpYawnUnaffectedPct'),
        (RT, 'ucpPersonAffectingCount'),
        (SD, 'R414 landed')):
    if mark not in rd(path):
        die('%s carries no R415 round' % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bucp', rd(path)):
        die('%s calls the pins early'
            % path)

print('R415 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the person-affecting')
print('  cantrip descriptions pin -')
print('  the 10 blocks, the names')
print('  cross-check the R341/R401')
print('  roster live (the scan\'s')
print('  TVvitch resolves as Twitch),')
print('  the school census 8/0/0/1/0/1')
print('  (Charm AS PRINTED, new), ALL')
print('  10 areas clean (zero area')
print('  holes), the yawn sleep')
print('  susceptibility pins + its')
print('  band derivation cross-checks')
print('  itself, the casting-time')
print('  family the recorded holes')
print('  pending the PDF read;')
print('  census 341 -> 342')
print('commit: R415: the UA person-'
      'affecting cantrips'
      ' (census 342)')

