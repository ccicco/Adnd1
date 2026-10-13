# R416: the UA PERSONAL CANTRIP
# DESCRIPTIONS (pp. 49-50) - the
# fifth of the six MU cantrip
# description rounds; the
# R363/R412/R413/R414/R415
# precedents ride (the
# descriptions pin; the
# casting-time fraction cells
# garble in the scan and record
# as holes pending the PDF
# read). The clean djvu scan
# carries all 10 personal
# blocks; the school tags
# print clean - Summoning and
# Conjuration both NEW school
# codes this round, pinned AS
# PRINTED (the never-guess
# doctrine). The scan prints
# "Flrefinger" for the roster's
# Firefinger - the name
# resolves via the LIVE
# R341/R401 roster cross-check
# (the roster is the
# independent confirmation).
# The census: Summoning 5 (Bee,
# Bug, Gnats, Mouse, Spider),
# Conjuration 3 (Bluelight,
# Tweak, Unlock), Alteration 1
# (Firefinger), Evocation 1
# (Smokepuff); Abjuration 0,
# Enchantment 0, Illusion 0,
# Charm 0. The area lines:
# EIGHT print clean - the
# one-summoned-animal four
# (Bee, Bug, Mouse, Spider - a
# NEW area kind), the Gnats 1
# cubic foot, the Smokepuff
# 1-foot cloud (a NEW area
# kind), the Tweak one
# creature (the R415 kind),
# the Unlock one lock (a NEW
# area kind) - and TWO garble
# their numbers (Bluelight
# diam. and Firefinger line):
# the two record as area holes
# pending the PDF read. ALL 10
# casting-time cells garble -
# the whole family records as
# holes. The range family: the
# seven ranged blocks print the
# numeral 1 clean but the
# foot/inch glyphs garble - the
# numeral pins, the unit family
# records as holes. The
# mechanics pin clean: the Bee
# 90% sting, the Bluelight
# 3-inch sphere + 5-foot
# illumination, the Firefinger
# one-half-foot jet + 1 segment,
# the Gnats 1-4 segment
# distraction, the Smokepuff
# six colors, the SPIDER
# POISON READ (5% venomous, the
# 1-2 inch size, the 1-segment
# bite, the +4 save, the 1/2
# damage pair, the 1-4 day
# sickness; the slow-poison
# defer prints a garbled
# numeral and records as a
# hole), the Tweak seven
# portions + 1-segment
# distraction + the INT 7
# threshold + 3d6.

# 1. rules/uacantrips5.h (NEW,
#    prefix uco - verified no
#    collision): the 10 personal
#    cantrips in R341/R401
#    roster order, the struct +
#    28 inline functions.
# 2. regtest.cpp: the include
#    rides the R415 include;
#    the R416 audit block lands
#    before the R227 anchor -
#    the 10 names cross-check
#    the R341/R401 roster
#    (uastCantripName(4, i))
#    live name for name, the
#    count cross-checks
#    uastCantripCount(4), the
#    schools/areas pin per row,
#    the censuses count, the
#    mechanics pin with the
#    band derivations
#    cross-checking themselves;
#    census 342 -> 343.
# 3. tools/ua_gap_report.md:
#    the MU cantrips box takes
#    AMENDED R416 - the personal
#    descriptions land; only
#    the haunting-sound
#    descriptions stay open.
# 4. The seed takes the R415
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
        'R416 splice ABORT: ' + msg)


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
# Charm, 6 Summoning (NEW this
# round), 7 Conjuration (NEW
# this round) - both pin AS
# PRINTED.
# area kinds: 1 cubic foot
# (the R412 kind), 9 one
# creature (the R415 kind),
# 10 one summoned animal
# (NEW), 11 one 1-foot cloud
# (NEW), 12 one lock (NEW);
# -1 the hole sentinel (the
# Bluelight sphere and the
# Firefinger line garble
# their numbers).
S_EVO, S_ABJ = 0, 1
S_ALT, S_ENCH = 2, 3
S_ILL, S_CHARM = 4, 5
S_SUMM, S_CONJ = 6, 7
A_HOLE = -1
A_CUBEFoot = 1
A_CREATURE = 9
A_BEAST, A_CLOUD = 10, 11
A_LOCK = 12

# The 10 personal cantrips, in
# the R341/R401 roster order:
# the name, the school, the
# area kind, the area value.
ROWS = [
    ('Bee', S_SUMM, A_BEAST, 0),
    ('Bluelight', S_CONJ, A_HOLE, 0),
    ('Bug', S_SUMM, A_BEAST, 0),
    ('Firefinger', S_ALT, A_HOLE, 0),
    ('Gnats', S_SUMM, A_CUBEFoot, 1),
    ('Mouse', S_SUMM, A_BEAST, 0),
    ('Smokepuff', S_EVO, A_CLOUD, 1),
    ('Spider', S_SUMM, A_BEAST, 0),
    ('Tweak', S_CONJ, A_CREATURE, 0),
    ('Unlock', S_CONJ, A_LOCK, 0),
]

SCHOOL_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[1] == s)
    for s in (0, 1, 2, 3, 4, 5,
              6, 7))
AREA_CENSUS = tuple(
    sum(1 for r in ROWS
        if r[2] == a)
    for a in (A_BEAST, A_CUBEFoot,
              A_CLOUD, A_CREATURE,
              A_LOCK, A_HOLE))

# ========= (a) the seed record =========
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

SEED_ENTRY = E(
    '- R415 landed 2026-10-13:',
    '  commit c4dbccf (census 342,',
    '  preflight GREEN), the UA',
    '  PERSON-AFFECTING CANTRIP',
    '  DESCRIPTIONS (p. 49) - the',
    '  fourth of the six MU cantrip',
    '  description rounds; the',
    '  precedents ride. rules/',
    '  uacantrips4.h (prefix ucp):',
    '  the 10 person-affecting',
    '  cantrips in roster order,',
    '  the school census 8/0/0/1/0/1',
    '  (Charm AS PRINTED, a NEW',
    '  school code; the scan\'s',
    '  "TVvitch" resolves as Twitch',
    '  via the live roster), ALL 10',
    '  areas clean (the one-person',
    '  six and one-creature four,',
    '  NEW area kinds), the yawn',
    '  sleep susceptibility pins +',
    '  the band derivation',
    '  cross-check, the whole',
    '  casting-time family the',
    '  recorded holes pending the',
    '  PDF read. Two pre-publish',
    '  catches this round: a',
    '  miscounted call-count assert',
    '  and a bare comment line the',
    '  R412b class guard caught.',
    '  First-try GREEN on the user',
    '  side. The md5 diverged for',
    '  the SIXTEENTH round running',
    '  - benign; the md5 stays',
    '  advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R415 landed 2026-10-13' in s:
    already.append('seed: the R415 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R415 record')
s = rd(SD)
if s.count('R415 landed 2026-10-13') != 1:
    die('the R415 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uacantrips5.h =========
UC = 'rules/uacantrips5.h'

HDR = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uacantrips5.h',
    '// The UA MAGIC-USER CANTRIP',
    '// DESCRIPTIONS, part 5 (R416):',
    '// the PERSONAL category',
    '// (pp. 49-50), 10 cantrips.',
    '// The R363/R412/R413/R414/R415',
    '// precedents ride: the',
    '// descriptions pin; the',
    '// casting-time fraction cells',
    '// garble in the scan (the',
    '// whole family) and record',
    '// as holes pending the PDF',
    '// read - never guesses.',
    '//',
    '// The school tags print clean:',
    '// Summoning and Conjuration',
    '// are NEW school codes this',
    '// round, pinned AS PRINTED.',
    '// The census: Summoning 5',
    '// (Bee, Bug, Gnats, Mouse,',
    '// Spider), Conjuration 3',
    '// (Bluelight, Tweak, Unlock),',
    '// Alteration 1 (Firefinger),',
    '// Evocation 1 (Smokepuff).',
    '// The scan prints "Flrefinger"',
    '// for the roster\'s Firefinger -',
    '// the name resolves via the',
    '// LIVE R341/R401 roster',
    '// cross-check (the roster is',
    '// the independent',
    '// confirmation).',
    '//',
    '// The area lines: EIGHT print',
    '// clean - the one-summoned-',
    '// animal four (Bee, Bug,',
    '// Mouse, Spider - a NEW area',
    '// kind), the Gnats 1 cubic',
    '// foot, the Smokepuff 1-foot',
    '// cloud (a NEW area kind), the',
    '// Tweak one creature (the',
    '// R415 kind), the Unlock one',
    '// lock (a NEW area kind) - and',
    '// TWO garble their numbers',
    '// (the Bluelight sphere',
    '// diameter and the Firefinger',
    '// line length): the two record',
    '// as area holes pending the',
    '// PDF read.',
    '//',
    '// The range family: the seven',
    '// ranged blocks (Bee, Bug,',
    '// Gnats, Mouse, Smokepuff,',
    '// Spider, Tweak) print the',
    '// numeral 1 clean but the',
    '// foot/inch glyphs garble -',
    '// the numeral pins, the unit',
    '// family records as holes',
    '// pending the PDF read.',
    '//',
    '// The mechanics pin clean: the',
    '// Bee 90% sting, the Bluelight',
    '// 3-inch sphere + 5-foot',
    '// illumination, the Firefinger',
    '// one-half-foot jet + 1',
    '// segment persistence, the',
    '// Gnats 1-4 segment distraction,',
    '// the Smokepuff six colors, the',
    '// SPIDER POISON READ (the 5%',
    '// the 1-2 inch size, the',
    '// 1-segment bite distraction,',
    '// the +4 venom save, the 1/2',
    '// damage pair, the 1-4 day',
    '// sickness; the slow-poison',
    '// defer prints a garbled',
    '// numeral and records as a',
    '// hole), the Tweak seven',
    '// portions + 1-segment',
    '// distraction + the INT 7',
    '// threshold + the 3d6 read.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The school codes (Summoning',
    '// and Conjuration NEW this',
    '// round, pinned AS PRINTED).',
    'const int UCO_EVO = 0;',
    'const int UCO_ABJ = 1;',
    'const int UCO_ALT = 2;',
    'const int UCO_ENCH = 3;',
    'const int UCO_ILL = 4;',
    'const int UCO_CHARM = 5;',
    'const int UCO_SUMM = 6;',
    'const int UCO_CONJ = 7;',
    '',
    '// The area kind codes (the one',
    '// summoned animal, the 1-foot',
    '// cloud and the one lock NEW',
    '// this round; the cubic foot',
    '// rides the R412 kind and the',
    '// one creature the R415 kind).',
    'const int UCO_AREA_HOLE = -1;',
    'const int UCO_AREA_CUBEFoot = 1;',
    'const int UCO_AREA_CREATURE = 9;',
    'const int UCO_AREA_BEAST = 10;',
    'const int UCO_AREA_CLOUD = 11;',
    'const int UCO_AREA_LOCK = 12;',
    '',
    '// One personal cantrip: the',
    '// name, the school, the area',
    '// kind and the area value (0',
    '// when the kind carries no',
    '// number).',
    'struct UcoCantrip {',
    '    const char* name;',
    '    int school;',
    '    int areaKind;',
    '    int areaVal;',
    '};',
    '',
    '// The 10 personal cantrips, in',
    '// the R341/R401 roster order.',
    'inline const UcoCantrip&'
    ' ucoPersonal(int i) {',
    '    static const UcoCantrip'
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
    'inline int ucoPersonalCount()',
    '    { return 10; }',
    '',
    '// The school census helper.',
    'inline int ucoSchoolCount(int s)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 10; ++i)',
    '        if (ucoPersonal(i).school'
    ' == s)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The area kind census helper.',
    'inline int ucoAreaKindCount(int a)',
    '{',
    '    int n = 0;',
    '    for (int i = 0; i < 10; ++i)',
    '        if (ucoPersonal(i).areaKind'
    ' == a)',
    '            ++n;',
    '    return n;',
    '}',
    '',
    '// The casting-time hole family:',
    '// ALL 10 casting-time cells print',
    '// fraction garbles in the scan -',
    '// the whole family records as',
    '// holes pending the PDF read (the',
    '// R363/R412/R413/R414/R415',
    '// posture).',
    'inline bool ucoCastTimesAreHoles()',
    '    { return true; }',
    '',
    '// The range hole family: the',
    '// seven ranged blocks print the',
    '// numeral 1 clean but the',
    '// foot/inch glyphs garble - the',
    '// numeral pins, the unit family',
    '// records as holes pending the',
    '// PDF read.',
    'inline bool ucoRangeUnitsAreHoles()',
    '    { return true; }',
    '',
    '// The range numeral (the seven',
    '// ranged blocks all print 1).',
    'inline int ucoRangeVal()',
    '    { return 1; }',
    '',
    '// ---- the mechanics pins ----',
    '',
    '// The Bee read: the bee is 90%',
    '// likely to sting any living',
    '// creature it finds itself',
    '// upon.',
    'inline int ucoBeeStingPct()',
    '    { return 90; }',
    '',
    '// The Bluelight read: the',
    '// 3-inch sphere of glowing blue',
    '// radiance illuminates an area',
    '// of 5 feet around itself (and',
    '// casts no reflections beyond',
    '// that radius; infravision and',
    '// ultravision unaffected).',
    'inline int ucoBluelightSphereInches()',
    '    { return 3; }',
    '',
    'inline int ucoBluelightRadiusFeet()',
    '    { return 5; }',
    '',
    '// The Firefinger read: a jet of',
    '// flame up to one-half foot in',
    '// length (6 inches) that',
    '// persists for up to 1 segment.',
    'inline int ucoFirefingerJetInches()',
    '    { return 6; }',
    '',
    'inline int ucoFirefingerSegments()',
    '    { return 1; }',
    '',
    '// The Gnats read: on a failed',
    '// save versus poison the cloud',
    '// distracts for from 1 to 4',
    '// segments.',
    'inline int ucoGnatsDistractMinSegments()',
    '    { return 1; }',
    '',
    'inline int ucoGnatsDistractMaxSegments()',
    '    { return 4; }',
    '',
    '// The Smokepuff read: the puff',
    '// can be white, gray, black,',
    '// brown, yellow, or green -',
    '// six colors.',
    'inline int ucoSmokepuffColors()',
    '    { return 6; }',
    '',
    '// ---- the spider poison read ----',
    '',
    '// The venom chance: a 5% chance',
    '// the summoned spider is one',
    '// with powerful poison (black',
    '// widow, brown recluse, etc.).',
    'inline int ucoSpiderPoisonPct()',
    '    { return 5; }',
    '',
    '// The size: a common garden',
    '// spider or the like, no',
    '// larger than an inch or two',
    '// in diameter.',
    'inline int ucoSpiderSizeMaxInches()',
    '    { return 2; }',
    '',
    '// The normal bite: a',
    '// momentary distraction of 1',
    '// segment.',
    'inline int ucoSpiderBiteDistractSegments()',
    '    { return 1; }',
    '',
    '// The venom save: versus poison',
    '// at +4.',
    'inline int ucoSpiderPoisonSaveBonus()',
    '    { return 4; }',
    '',
    '// The damage pair: success on',
    '// the save inflicts 1 point,',
    '// failure 2 points.',
    'inline int ucoSpiderHitLight()',
    '    { return 1; }',
    '',
    'inline int ucoSpiderHitHeavy()',
    '    { return 2; }',
    '',
    '// The sickness: on the failed',
    '// venom save the victim cannot',
    '// act normally for from 1 to 4',
    '// days unless neutralize poison',
    '// removes the toxin.',
    'inline int ucoSpiderSickMinDays()',
    '    { return 1; }',
    '',
    'inline int ucoSpiderSickMaxDays()',
    '    { return 4; }',
    '',
    '// The slow poison defer: the',
    '// scan prints a garbled numeral',
    '// for the deferral - the value',
    '// records as a hole pending the',
    '// PDF read (never a guess).',
    'inline bool ucoSlowPoisonDeferIsHole()',
    '    { return true; }',
    '',
    '// ---- the tweak read ----',
    '',
    '// The portions: cheek, nose,',
    '// ear, beard, moustache,',
    '// whiskers, or tail - seven.',
    'inline int ucoTweakPortions()',
    '    { return 7; }',
    '',
    '// The distraction: a 1-segment',
    '// distraction on the failed',
    '// save/roll.',
    'inline int ucoTweakDistractSegments()',
    '    { return 1; }',
    '',
    '// The INT threshold: creatures',
    '// with intelligence under 7',
    '// save versus spell; creatures',
    '// with intelligence of 7 or',
    '// greater must roll greater',
    '// than intelligence on 3d6.',
    'inline int ucoTweakIntThreshold()',
    '    { return 7; }',
    '',
    'inline int ucoTweakDice()',
    '    { return 3; }',
    '',
    '}   // namespace rules',
    '')

newfile(UC, HDR + NL,
        'the personal cantrips header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uacantrips4.h"  '
     '// R415: the UA person-'
     'affecting cantrips',
     E(
    '#include "rules/uacantrips4.h"  '
    '// R415: the UA person-'
    'affecting cantrips',
    '#include "rules/uacantrips5.h"  '
    '// R416: the UA personal'
    ' cantrips'),
     'regtest: the personal'
     ' cantrips include')

AUD = E(
    '    // ---- R416: the UA personal',
    '    // cantrips pin audit ----',
    '    // The 10 personal',
    '    // descriptions pin: the names',
    '    // cross-check the R341/R401',
    '    // roster live (the scan\'s',
    '    // "Flrefinger" resolves as',
    '    // Firefinger via the roster -',
    '    // the independent',
    '    // confirmation), the schools',
    '    // pin per row (Summoning and',
    '    // Conjuration AS PRINTED, NEW',
    '    // codes), the areas pin per',
    '    // row (EIGHT clean - the one',
    '    // summoned animal four, the',
    '    // Gnats cubic foot, the',
    '    // Smokepuff cloud, the Tweak',
    '    // creature, the Unlock lock;',
    '    // the Bluelight sphere and the',
    '    // Firefinger line record as',
    '    // area holes), the censuses',
    '    // count, the mechanics pin',
    '    // with the band derivations',
    '    // cross-checking themselves;',
    '    // census 342 -> 343.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (ucoPersonalCount() != 10)',
    '            ++bad;',
    '        if (uastCantripCount(4) != 10)',
    '            ++bad;',
    '        // ---- the school census ----',
    '        if (ucoSchoolCount(UCO_EVO)'
    ' != 1',
    '                || ucoSchoolCount'
    '(UCO_ABJ) != 0',
    '                || ucoSchoolCount'
    '(UCO_ALT) != 1',
    '                || ucoSchoolCount'
    '(UCO_ENCH) != 0',
    '                || ucoSchoolCount'
    '(UCO_ILL) != 0',
    '                || ucoSchoolCount'
    '(UCO_CHARM) != 0',
    '                || ucoSchoolCount'
    '(UCO_SUMM) != 5',
    '                || ucoSchoolCount'
    '(UCO_CONJ) != 3) ++bad;',
    '        // ---- the area census ----',
    '        if (ucoAreaKindCount'
    '(UCO_AREA_BEAST) != 4',
    '                || ucoAreaKindCount'
    '(UCO_AREA_CUBEFoot) != 1',
    '                || ucoAreaKindCount'
    '(UCO_AREA_CLOUD) != 1',
    '                || ucoAreaKindCount'
    '(UCO_AREA_CREATURE) != 1',
    '                || ucoAreaKindCount'
    '(UCO_AREA_LOCK) != 1',
    '                || ucoAreaKindCount'
    '(UCO_AREA_HOLE) != 2) ++bad;')

# the per-row pins: name (cross-
# checked against the R341/R401
# roster live), school, area
for i, (nm, sc, ak, av) in \
        enumerate(ROWS):
    AUD += NL + E(
        '        if (strcmp'
        '(ucoPersonal(%d)'
        '.name,' % i,
        '                   '
        'uastCantripName(4, %d)) != 0'
        % i,
        '                ||'
        ' ucoPersonal(%d)' % i,
        '                   .school'
        ' != %d' % sc,
        '                ||'
        ' ucoPersonal(%d)' % i,
        '                   .areaKind'
        ' != %d' % ak,
        '                ||'
        ' ucoPersonal(%d)' % i,
        '                   .areaVal'
        ' != %d) ++bad;' % av)

AUD += NL + E(
    '        // ---- the hole families ----',
    '        if (!ucoCastTimesAreHoles()',
    '                || !ucoRangeUnits'
    'AreHoles()',
    '                || !ucoSlowPoison'
    'DeferIsHole())',
    '            ++bad;',
    '        // ---- the mechanics ----',
    '        if (ucoRangeVal() != 1',
    '                || ucoBeeStingPct()'
    ' != 90',
    '                || ucoSmokepuffColors()'
    ' != 6) ++bad;',
    '        if (ucoBluelightSphere'
    'Inches() != 3',
    '                || ucoBluelight'
    'RadiusFeet() != 5) ++bad;',
    '        if (ucoFirefingerJet'
    'Inches() != 6',
    '                || ucoFirefinger'
    'Segments() != 1) ++bad;',
    '        if (ucoGnatsDistractMin'
    'Segments() != 1',
    '                || ucoGnatsDistract'
    'MaxSegments() != 4) ++bad;',
    '        if (ucoSpiderPoisonPct()'
    ' != 5',
    '                || ucoSpiderSize'
    'MaxInches() != 2',
    '                || ucoSpiderBite'
    'DistractSegments() != 1',
    '                || ucoSpiderPoison'
    'SaveBonus() != 4) ++bad;',
    '        if (ucoSpiderHitLight()'
    ' != 1',
    '                || ucoSpider'
    'HitHeavy() != 2',
    '                || ucoSpiderSick'
    'MinDays() != 1',
    '                || ucoSpiderSick'
    'MaxDays() != 4) ++bad;',
    '        if (ucoTweakPortions() != 7',
    '                || ucoTweak'
    'DistractSegments() != 1',
    '                || ucoTweak'
    'IntThreshold() != 7',
    '                || ucoTweakDice()'
    ' != 3) ++bad;',
    '        // The band derivations: the',
    '        // gnats distraction opens',
    '        // below its close, the',
    '        // firefinger jet is the',
    '        // one-half foot (twelve',
    '        // halves), the bluelight',
    '        // sphere fits its',
    '        // illumination radius, and',
    '        // the spider damage/sickness',
    '        // bands order themselves.',
    '        if (ucoGnatsDistractMin'
    'Segments()',
    '                >= ucoGnatsDistract'
    'MaxSegments()',
    '                || ucoFirefingerJet'
    'Inches() * 2 != 12',
    '                || ucoBluelightSphere'
    'Inches()',
    '                   >= ucoBluelight'
    'RadiusFeet() * 12',
    '                || ucoSpiderHitLight()'
    ' >= ucoSpiderHitHeavy()',
    '                || ucoSpiderSick'
    'MinDays()',
    '                   >= ucoSpiderSick'
    'MaxDays()) ++bad;',
    '        printf("R416 UA personal'
    ' cantrips pin'
    ' audit: bad %d'
    + chr(92) + 'n\", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R416 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
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
    '        stay open.'),
    E(
    '      - AMENDED R416: the',
    '        personal descriptions land',
    '        (rules/uacantrips5.h) - the',
    '        10 blocks pin schools (the',
    '        1/0/1/0/0/0/5/3 census -',
    '        Summoning and Conjuration',
    '        AS PRINTED, NEW school',
    '        codes; the scan\'s',
    '        "Flrefinger" resolves as',
    '        Firefinger via the live',
    '        roster), the areas pin',
    '        EIGHT clean (the one',
    '        summoned animal four, the',
    '        Gnats cubic foot, the',
    '        Smokepuff 1-foot cloud, the',
    '        Tweak creature, the Unlock',
    '        lock - NEW area kinds; the',
    '        Bluelight sphere and the',
    '        Firefinger line record as',
    '        the TWO area holes pending',
    '        the PDF read), the whole',
    '        casting-time family the',
    '        recorded holes, the range',
    '        unit family the recorded',
    '        holes (the numeral 1 pins),',
    '        the mechanics pin (the bee',
    '        90% sting, the bluelight',
    '        3-inch sphere + 5-foot',
    '        radius, the firefinger',
    '        one-half-foot jet + segment,',
    '        the gnats 1-4 segment',
    '        distraction, the smokepuff',
    '        six colors, the SPIDER',
    '        POISON READ - the 5% venom',
    '        chance, the 1-2 inch size,',
    '        the 1-segment bite, the +4',
    '        save, the 1/2 damage pair,',
    '        the 1-4 day sickness, the',
    '        slow-poison defer a garbled',
    '        numeral recorded as a hole',
    '        - and the tweak seven',
    '        portions + 1-segment',
    '        distraction + INT 7',
    '        threshold + 3d6, the band',
    '        derivations cross-checking',
    '        themselves); only the',
    '        haunting-sound descriptions',
    '        stay open.',
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
    '        stay open.'),
    'gap: the MU cantrips box takes'
    ' R416')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 343:
    die('the census %d' % s.count('audit: bad'))
if s.count('R416 UA personal'
           ' cantrips pin audit') != 1:
    die('the R416 audit label')
if s.count('ucoPersonal') != \
        4 * len(ROWS) + 1:
    die('the ucoPersonal call'
        ' count %d'
        % s.count('ucoPersonal'))

# the R412b resolution guard:
# every uco symbol the audit
# calls must be defined in the
# emitted header.
_used = set(_re.findall(r'\buco\w+', s))
_def = set(_re.findall(r'\buco\w+',
                       rd(UC)))
if _used - _def:
    die('undefined uco calls %s'
        % sorted(_used - _def))

p = rd(UC)
if p.count('inline') != 28:
    die('the personal cantrips'
        ' inline count %d'
        % p.count('inline'))
if not p.endswith(NL):
    die('the personal cantrips'
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
if g.count('AMENDED R416') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R416'))

for path, mark in (
        (UC, 'ucoTweakDice'),
        (RT, 'ucoPersonalCount'),
        (SD, 'R415 landed')):
    if mark not in rd(path):
        die('%s carries no R416 round' % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\buco', rd(path)):
        die('%s calls the pins early'
            % path)

print('R416 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the personal')
print('  cantrip descriptions pin -')
print('  the 10 blocks, the names')
print('  cross-check the R341/R401')
print('  roster live (the scan\'s')
print('  Flrefinger resolves as')
print('  Firefinger), the school')
print('  census 1/0/1/0/0/0/5/3')
print('  (Summoning and Conjuration')
print('  AS PRINTED, new), the areas')
print('  pin eight clean (two area')
print('  holes - the bluelight sphere')
print('  and the firefinger line),')
print('  the spider poison read + the')
print('  band derivations cross-check')
print('  themselves, the casting-time,')
print('  range-unit and slow-poison-')
print('  defer families the recorded')
print('  holes pending the PDF read;')
print('  census 342 -> 343')
print('commit: R416: the UA personal'
      ' cantrips (census 343)')

