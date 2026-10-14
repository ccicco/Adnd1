#!/usr/bin/env python3
# r425_splice: the WSG ARC
# OPENER, census 350 -> 351.
# The wilderness proficiencies
# (the WSG pp. 11-17, the R425
# round) - the arc opener that
# mirrors the R322 UA opener:
# a NEW rules/ pin header, a
# NEW lossless gap report, the
# regtest include + audit.
#
# The pins (the WSG printed
# pp. 11-12, verified from the
# scan - archive.org item
# pdfy-B3Fz83tZ3TV7zOc8, pdf
# page 13 = printed p. 12; the
# Table 1/2 grids read from the
# IIIF page image because the
# text layer drops the grid
# columns; the rule prose read
# from the text layer, whole):
#   - the Proficiency Check
#     system: 1d20 vs the
#     Appropriate Ability; an
#     unmodified 19 or 20
#     auto-fails; a score over
#     18 counts as 18; even a
#     score-18 character keeps
#     at least a 10 percent
#     (2-in-20) chance of
#     failing; improving gives
#     a cumulative -2 die-roll
#     modifier per extra slot
#     (a nonweapon slot gained
#     at 3rd level or higher);
#     an improved proficiency
#     succeeds on an unmodified
#     19; a natural 20 always
#     fails.
#   - Table 1 (the 14 class
#     rows: the initial weapon/
#     nonweapon slots and the
#     add-per-N-levels column;
#     the bard row reads "as
#     other classes" - pinned
#     as the -1 sentinel; the
#     0-level horsemen footnote:
#     one nonweapon proficiency,
#     the second at 1st level).
#   - Table 2 (the 25
#     wilderness proficiency
#     rows: the slots, the
#     appropriate ability, the
#     die-roll modifier; 99 =
#     no modifier, and the
#     no-check proficiencies
#     cross-check against both
#     the ability NA and the
#     modifier 99).
#   - the slot rules: a weapon
#     slot may hold a nonweapon
#     proficiency, never the
#     reverse; the expanding
#     optional rule: one extra
#     nonweapon slot at 1st
#     level, only if every
#     nonweapon slot is filled
#     right away - a delayed
#     extra slot is lost and
#     cannot be filled later.
#
# Patches (5):
#   - the seed takes the R424
#     landed record
#   - rules/wsgprof.h NEW (33
#     inlines, prefix wsg -
#     checked free, the
#     collision gate keyed on
#     the wsg call absence for
#     idempotency)
#   - tools/wsg_gap_report.md
#     NEW (the lossless
#     whole-book inventory: the
#     14 chapters, the DM
#     section, the weather
#     appendix, the compiled
#     tables; all 42 tables
#     from the book own Tables
#     index as manifest line
#     items; post-state 5
#     closed, 181 open)
#   - regtest.cpp: the include
#     after the uapantheon
#     include; the R425 audit
#     block before the R227
#     anchor; census 350 -> 351
#
# Guards: the census 351, the
# audit label, the
# string-literal parity gate
# (the R421b lesson), the
# no-bare-'||' gate (the R418b
# lesson), the include comment
# whole (the R390 lesson), the
# header statics (33 inlines,
# lines <= 78 except the
# 92-char opener, brace
# balance, every line
# classifiable C++ - the
# INCIDENT-2 lesson, the wsg
# identifier resolution - the
# R412b lesson), the gap
# censuses, the seed record,
# the caller contract, the
# mixed applied/already ABORT
# (the R420 lesson).
#
# The ritual: no nano, no ./nn
# - the tree stays pristine;
# a failed run restores by
# re-fetching regtest.cpp and
# the seed from the repo and
# rm of the new files. The
# splice is idempotent: a
# second run applies nothing
# and reports every patch
# already in place.

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
        'R425 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d'
            ' (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


def newfile(path, text, label):
    if os.path.exists(path):
        if rd(path) == text:
            already.append(label)
        else:
            die('%s exists, divergent'
                % label)
    else:
        wr(path, text)
        applied.append(label)


RT = 'regtest.cpp'
HD = 'rules/wsgprof.h'
GR = 'tools/wsg_gap_report.md'
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

# ======== the pinned data ========

# Table 1: the 14 class rows,
# (initW, initNW, addW, addNW,
# per-N-levels). The bard
# initials are the -1 "as
# other classes" sentinel.
T1 = [
    (3, 2, 1, 1, 2),   # CAVALIER
    (3, 2, 1, 1, 2),   # Paladin
    (2, 3, 1, 1, 4),   # CLERIC
    (2, 3, 1, 1, 5),   # Druid
    (4, 2, 1, 1, 3),   # FIGHTER
    (6, 3, 1, 1, 2),   # Barbarian
    (3, 2, 1, 1, 3),   # Ranger
    (1, 3, 1, 2, 6),   # MAGIC-USER
    (1, 3, 1, 2, 6),   # Illusionist
    (2, 3, 1, 1, 4),   # THIEF
    (2, 3, 1, 1, 4),   # Acrobat
    (3, 2, 1, 1, 4),   # Assassin
    (1, 1, 1, 1, 2),   # MONK
    (-1, -1, 1, 1, 4),  # BARD
]

# Table 2: the 25 proficiency
# rows, (slots, ability,
# modifier). Ability codes: 1
# WIS, 2 INT, 3 DEX, 4 CON,
# 5 STR, 0 NA. Modifier 99 =
# NA - the proficiency makes
# no checks.
T2 = [
    (1, 1, 1),    # Alertness
    (1, 1, 1),    # Animal Handling
    (1, 2, 0),    # Animal Lore
    (1, 0, 99),   # Blind-fighting
    (1, 1, -1),   # Boating
    (1, 3, -2),   # Charioteering
    (1, 1, -1),   # Direction Sense
    (2, 0, 99),   # Endurance
    (1, 1, 1),    # Fire-building
    (1, 1, 1),    # Fishing
    (1, 2, 2),    # Foraging
    (2, 1, -2),   # Healing
    (1, 1, -1),   # Hunting
    (1, 0, 99),   # Mountaineering
    (1, 2, 0),    # Plant Lore
    (2, 1, 2),    # Riding airborne
    (1, 1, -3),   # Riding land
    (1, 3, 0),    # Rope Use
    (2, 4, 0),    # Running
    (1, 0, 99),   # Survival cold
    (2, 0, 99),   # Survival desert
    (1, 0, 99),   # Survival heat
    (1, 5, 0),    # Swimming
    (1, 0, 99),   # Tracking
    (1, 1, 1),    # Weather sense
]

# the roster and census
# pre-checks (the censuses
# derive from the tables, the
# R410 lesson)
if len(T1) != 14 or len(T2) != 25:
    die('the roster sizes')
dens = [r[4] for r in T1]
if (dens.count(2) != 4
        or dens.count(3) != 2
        or dens.count(4) != 5
        or dens.count(5) != 1
        or dens.count(6) != 2):
    die('the Table 1 denominators')
if ([r[0] for r in T2].count(1)
        != 20
        or [r[0] for r in T2]
        .count(2) != 5):
    die('the Table 2 slot census')
ab = [r[1] for r in T2]
if (ab.count(1) != 11
        or ab.count(2) != 3
        or ab.count(3) != 2
        or ab.count(4) != 1
        or ab.count(5) != 1
        or ab.count(0) != 7):
    die('the Table 2 ability '
        'census')
md = [r[2] for r in T2]
if (md.count(1) != 5
        or md.count(2) != 2
        or md.count(0) != 5
        or md.count(-1) != 3
        or md.count(-2) != 2
        or md.count(-3) != 1
        or md.count(99) != 7):
    die('the Table 2 modifier '
        'census')
for s, a, m in T2:
    if (a == 0) != (m == 99):
        die('the never-check '
            'cross-check')
# the book own examples (the
# cleric and the illusionist):
# the add-per-N-levels
# arithmetic - 1st level
# counts, so the first add
# comes ready to begin level
# N+1
if (T1[2][4] + 1 != 5
        or T1[7][4] + 1 != 7
        or T1[2][4] * 2 + 1 != 9
        or T1[7][4] * 2 + 1
        != 13):
    die('the denominator '
        'examples')

# the prefix collision gate
# (the R411 lesson): the wsg
# prefix must be free - keyed
# on the wsg CALL absence so a
# re-run over a patched tree
# stays GREEN (idempotency)
RT0 = rd(RT)
if ('wsgCheckRolls' not in RT0
        and _re.search(r'\bwsg\w*\(',
                       RT0)):
    die('the wsg prefix is not '
        'free in regtest')

# ======== (a) the seed ========

SEED_ENTRY = E(
    '- R424 landed 2026-10-13:',
    '  commit 8e710fb (census',
    '  350, preflight GREEN on',
    '  the FIRST run, pushed',
    '  a44b3d0..8e710fb), the',
    '  APPENDIX T RESOLUTION -',
    '  the LAST open',
    '  book-content box in the',
    '  UA gap report closes.',
    '  The clean OCR read',
    '  (pages 124/127/128/129 =',
    '  printed 123/126/127/128)',
    '  resolves the five R391',
    '  flagged holes: the',
    '  classification system',
    '  paragraph, the fauchard',
    '  description, the',
    '  Lucern/bec comparison',
    '  tail, the combination',
    '  intro, the bill-guisarme',
    '  features list and the',
    '  confusion sentence all',
    '  print whole; every flag',
    '  REPLACED 1:1 with a',
    '  ReadsClean pin (the',
    '  inline count 161 stays);',
    '  the ledger flips clean 2',
    '  -> 7, flagged 5 -> 0.',
    '  Gap post-state: 102',
    '  closed, 3 open (the two',
    '  logging layers + the',
    '  legend line) - ALL',
    '  book-content boxes are',
    '  CLOSED. Sim: 7 value + 3',
    '  expectation mutants all',
    '  RED, clean GREEN.',
    '  Census 349 -> 350.')

ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R424 landed 2026-10-13' in s:
    already.append('seed: the R424 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                 + ANCH)
    wr(SD, s)
    applied.append('seed: the R424 record')

# ======== (b) rules/wsgprof.h ========

# the header: 33 inlines, the
# system pins + the Table 1/2
# switches + the ledger pins.
# The opener is the 92-char
# banner - the one allowed
# exception to the 78-col
# bound.

HS = []  # header source lines

HS += [
    '// ' + '=' * 89,
    '// Adnd1 - rules/wsgprof.h',
    '// The WSG WILDERNESS',
    '// PROFICIENCIES, R425:',
    '// the wilderness arc',
    '// opener. The printed',
    '// p. 12 grids pin whole',
    '// (Table 1: the 14 class',
    '// rows; Table 2: the 25',
    '// proficiency rows) with',
    '// the Proficiency Check',
    '// system, the improving',
    '// rule and the slot rules;',
    '// census 350 -> 351.',
    '// Pin-era pattern (R322);',
    '// the WSG arc mirrors the',
    '// R322 UA opener.',
    '//',
    '// Provenance: the WSG',
    '// scan (archive.org item',
    '// pdfy-B3Fz83tZ3TV7zOc8),',
    '// pdf page 13 = printed',
    '// p. 12 - the Table 1/2',
    '// grids read from the',
    '// IIIF page image (the',
    '// text layer drops the',
    '// grid columns); the rule',
    '// prose verified whole.',
    'namespace rules {',
    '',
    '// ---- the Proficiency',
    '// ---- Check system ----',
    '',
    '// A Proficiency Check is',
    '// a roll of 1d20 against',
    '// the Appropriate',
    '// Ability.',
    'inline bool wsgCheckRolls'
    '1d20()',
    '    { return true; }',
    '// The check uses a',
    '// twenty-sided die.',
    'inline int '
    'wsgCheckDieSides()',
    '    { return 20; }',
    '// An unmodified die roll',
    '// of 19 or 20 always',
    '// fails.',
    'inline int '
    'wsgCheckAutoFail()',
    '    { return 19; }',
    '// An Appropriate Ability',
    '// score greater than 18',
    '// is treated as 18.',
    'inline int wsgAbilityCap()',
    '    { return 18; }',
    '// Even a character with an',
    '// Appropriate Ability of',
    '// 18 or better keeps at',
    '// least a 10 percent',
    '// (2 in 20) chance of',
    '// failing any check.',
    'inline int '
    'wsgCheckFloorIn20()',
    '    { return 2; }',
    '// An improved proficiency',
    '// succeeds on an',
    '// unmodified 19.',
    'inline bool '
    'wsgImproved19Succeeds()',
    '    { return true; }',
    '// No matter how much a',
    '// proficiency is improved,',
    '// an unmodified 20 still',
    '// fails.',
    'inline bool '
    'wsgNatural20Fails()',
    '    { return true; }',
    '// Improving an existing',
    '// proficiency (a',
    '// nonweapon slot gained at',
    '// 3rd level or higher):',
    '// each extra slot gives a',
    '// cumulative -2 die-roll',
    '// modifier.',
    'inline int '
    'wsgImprovingStep()',
    '    { return -2; }',
    '// Improving uses slots',
    '// gained at 3rd level or',
    '// higher.',
    'inline int '
    'wsgImprovingMinLevel()',
    '    { return 3; }',
    '',
    '// ---- the slot rules ----',
    '',
    '// A weapon proficiency',
    '// slot can be filled with',
    '// a nonweapon proficiency.',
    'inline bool '
    'wsgWeaponSlotHolds'
    'Nonweapon()',
    '    { return true; }',
    '// The reverse is not',
    '// allowed: a nonweapon',
    '// slot never holds a',
    '// weapon proficiency.',
    'inline bool '
    'wsgNonweaponSlotHolds'
    'Weapon()',
    '    { return false; }',
    '',
    '// ---- the expanding',
    '// ---- optional rule ----',
    '',
    '// The Dungeon Master may',
    '// allow one additional',
    '// nonweapon proficiency',
    '// slot at 1st level -',
    '// only if all of the',
    '// character nonweapon',
    '// slots are filled right',
    '// away.',
    'inline int '
    'wsgExpandingBonusSlots()',
    '    { return 1; }',
    '// The extra slot comes at',
    '// 1st level only.',
    'inline bool '
    'wsgExpandingFirst'
    'LevelOnly()',
    '    { return true; }',
    '// A delayed extra slot is',
    '// lost and cannot be',
    '// filled later.',
    'inline bool '
    'wsgExpandingDelayed'
    'IsLost()',
    '    { return true; }',
    '',
    '// ---- the Table 1',
    '// ---- footnotes ----',
    '',
    '// 0-level horsemen and',
    '// lancers begin with one',
    '// nonweapon proficiency.',
    'inline int '
    'wsgHorsemanZero'
    'LevelSlots()',
    '    { return 1; }',
    '// The horseman second',
    '// nonweapon proficiency',
    '// arrives at 1st level.',
    'inline int '
    'wsgHorsemanSecond'
    'SlotLevel()',
    '    { return 1; }',
    '// The bard Table 1 row',
    '// reads "as other classes"',
    '// - the -1 sentinel below.',
    'inline bool '
    'wsgBardAsOtherClasses()',
    '    { return true; }',
    '',
    '// ---- Table 1: the 14',
    '// ---- class rows ----',
    '',
    '// The census: 14 rows.',
    'inline int wsgClassCount()',
    '    { return 14; }',
]


# the Table 1 switches
def t1_switch(name, col):
    out = ['inline int %s(' % name,
           '    int c)',
           '    {',
           '        switch (c) {']
    for i, r in enumerate(T1):
        out.append('        case %d:' % i)
        out.append('            return %d;'
                   % r[col])
    out += ['        default:',
            '            return 0;',
            '        }',
            '    }',
            '']
    return out


HS += ['// The initial weapon',
       '// slots by class (the',
       '// left of the slash; the',
       '// bard -1 sentinel = as',
       '// other classes).']
HS += t1_switch('wsgInitialWeaponSlots', 0)
HS += ['// The initial nonweapon',
       '// slots by class (the',
       '// right of the slash).']
HS += t1_switch(
    'wsgInitialNonweaponSlots', 1)
HS += ['// The weapon slots added',
       '// per N levels (always',
       '// 1).']
HS += t1_switch('wsgAddWeaponSlots', 2)
HS += ['// The nonweapon slots',
       '// added per N levels',
       '// (the magic-user and',
       '// illusionist add 2).']
HS += t1_switch(
    'wsgAddNonweaponSlots', 3)
HS += ['// The add-per-N-levels',
       '// column by class; 1st',
       '// level counts, so the',
       '// first add comes ready',
       '// to begin level N+1.',
       '// (The census: 2x4, 3x2,',
       '// 4x5, 5x1, 6x2.)']
HS += t1_switch('wsgAddEveryLevels', 4)

HS += [
    '',
    '// ---- Table 2: the 25',
    '// ---- proficiency rows ----',
    '',
    '// The census: 25 rows.',
    'inline int wsgProfCount()',
    '    { return 25; }',
    '',
    '// The ability codes: 1',
    '// WIS, 2 INT, 3 DEX,',
    '// 4 CON, 5 STR, 0 NA.',
    '// (The census: WIS 11,',
    '// INT 3, DEX 2, CON 1,',
    '// STR 1, NA 7.)',
]


# the Table 2 switches
def t2_switch(name, col):
    out = ['inline int %s(' % name,
           '    int p)',
           '    {',
           '        switch (p) {']
    for i, r in enumerate(T2):
        out.append('        case %d:' % i)
        out.append('            return %d;'
                   % r[col])
    out += ['        default:',
            '            return 0;',
            '        }',
            '    }',
            '']
    return out


HS += ['// The slots by',
       '// proficiency (the',
       '// census: 1x20, 2x5).']
HS += t2_switch('wsgSlots', 0)
HS += ['// The Appropriate',
       '// Ability by',
       '// proficiency; 0 = NA.']
HS += t2_switch('wsgAbility', 1)
HS += ['// The die-roll modifier',
       '// by proficiency; 99 =',
       '// NA - the proficiency',
       '// never makes a check.']
HS += t2_switch('wsgModifier', 2)

HS += ['// True when the',
       '// proficiency never makes',
       '// a Proficiency Check',
       '// (the NA-ability and the',
       '// 99-modifier rows agree',
       '// row for row).',
       'inline bool '
       'wsgProfNeverChecks(int p)',
       '    {',
       '        switch (p) {']
NEVER = [i for i, r in enumerate(T2)
         if r[2] == 99]
for i in NEVER:
    HS.append('        case %d:' % i)
HS += ['            return true;',
       '        default:',
       '            return false;',
       '        }',
       '    }',
       '']

HS += [
    '// ---- the ledger ----',
    '',
    '// The Table 2 slot',
    '// census: one-slot rows.',
    'inline int '
    'wsgSingleSlotProfs()',
    '    { return 20; }',
    '// The Table 2 slot',
    '// census: two-slot rows.',
    'inline int '
    'wsgDoubleSlotProfs()',
    '    { return 5; }',
    '// The Table 2 ability',
    '// census: wisdom rows.',
    'inline int wsgWisdomProfs()',
    '    { return 11; }',
    '// The census of the rows',
    '// that never make a',
    '// check.',
    'inline int '
    'wsgNeverCheckProfs()',
    '    { return 7; }',
    '// The harshest Table 2',
    '// modifier: riding,',
    '// land-based.',
    'inline int '
    'wsgHardestModifier()',
    '    { return -3; }',
    '',
    '}   // namespace rules',
]

HEADER = E(*HS) + NL

newfile(HD, HEADER,
        'rules/wsgprof.h')

# the header statics:
# 33 inlines, lines <= 78
# except the 92-char opener,
# brace balance, every line
# classifiable C++ (the
# INCIDENT-2 lesson)
h = rd(HD)
if h.count('inline ') != 33:
    die('the header inline '
        'count %d'
        % h.count('inline '))
lines = h.split(NL)
for i, ln in enumerate(lines):
    if i == 0:
        if len(ln) != 92:
            die('the header opener '
                'is %d cols'
                % len(ln))
        continue
    if len(ln) > 78:
        die('the header line %d '
            'is %d cols'
            % (i, len(ln)))
if h.count('{') != h.count('}'):
    die('the header brace '
        'balance')
_CODE = _re.compile(
    r'(^(inline |namespace |//)'
    r'|^\} +//'
    r'|^ +(\{|\}|case |default:'
    r'|return |switch |int ))')
for i, ln in enumerate(lines):
    c = ln.strip()
    if not c or c.startswith('//'):
        continue
    if not _CODE.match(ln):
        die('the header line %d is '
            'not classifiable C++ '
            '(%r)'
            % (i, ln[:40]))

# ======== (c) tools/wsg_gap_report.md ========

# the 14 chapters (the book
# own Table of Contents
# hierarchy - the front
# matter pp. 1-4 stays out of
# scope, as the UA report
# scope note)
CH = [
    ('Overview of the wilderness',
     'pp. 7-10', [
        ('Terrain: desert', 'p. 7'),
        ('Terrain: forest', 'p. 7'),
        ('Terrain: hills', 'p. 8'),
        ('Terrain: mountains',
         'p. 8'),
        ('Terrain: plains', 'p. 9'),
        ('Terrain: seacoast',
         'p. 9'),
        ('Terrain: swamp', 'p. 9'),
        ('Hierarchy of terrain',
         'p. 9'),
        ('Bodies of water', 'p. 9'),
        ('Climate', 'p. 10'),
    ]),
    ('Wilderness proficiencies',
     'pp. 11-17', [
        ('Nonweapon proficiencies',
         'p. 11'),
        ('Choosing skills', 'p. 11'),
        ('Success and failure - '
         'the Proficiency Check '
         'system', 'p. 11'),
        ('Improving proficiencies',
         'p. 11'),
        ('Expanding proficiency '
         'slots (optional rule)',
         'p. 12'),
        ('Proficiency descriptions',
         'pp. 13-17'),
    ]),
    ('Dressing for the weather',
     'pp. 18-20', [
        ('Personal temperature',
         'p. 18'),
        ('Clothing', 'p. 18'),
        ('Protected and '
         'unprotected characters',
         'p. 19'),
        ('Clothing that functions '
         'as armor', 'p. 19'),
        ('Effects of exertion',
         'p. 20'),
    ]),
    ('Effects of the environment',
     'pp. 21-29', [
        ('Temperature and wind',
         'p. 21'),
        ('Precipitation', 'p. 22'),
        ('Special weather', 'p. 23'),
        ('Damage from heat and '
         'cold', 'p. 25'),
        ('Effects on equipment',
         'p. 28'),
    ]),
    ('Encumbrance and movement',
     'pp. 30-49', [
        ('Encumbrance of '
         'characters', 'p. 30'),
        ('Terrain definitions for '
         'movement', 'p. 30'),
        ('Large-scale overland '
         'movement', 'p. 31'),
        ('Encumbrance and movement '
         'for land-based animals',
         'p. 32'),
        ('Movement of land-based '
         'vehicles', 'p. 33'),
        ('Movement across special '
         'terrain', 'p. 33'),
        ('Climbing', 'p. 34'),
        ('Surface types', 'p. 34'),
        ('Surface conditions',
         'p. 34'),
        ('Chance of falling',
         'p. 34'),
        ('Climbing checks', 'p. 35'),
        ('Damage from falling',
         'p. 35'),
        ('Stopping a fall', 'p. 36'),
        ('Using rope for movement '
         'and climbing', 'p. 36'),
        ('Roping together', 'p. 37'),
        ('Rappelling', 'p. 37'),
        ('Belaying', 'p. 37'),
        ('Use of grappling hooks',
         'p. 38'),
        ('Crossing a chasm on a '
         'rope', 'p. 38'),
        ('The mountaineering '
         'proficiency', 'p. 39'),
        ('Movement on slippery '
         'horizontal surfaces',
         'p. 39'),
        ('Jumping', 'p. 39'),
        ('Overland movement in '
         'reduced visibility',
         'p. 40'),
        ('Swimming', 'p. 41'),
        ('Other effects of moving '
         'water', 'p. 42'),
        ('Diving and surfacing',
         'p. 42'),
        ('Treading water', 'p. 43'),
        ('Holding one breath',
         'p. 43'),
        ('Movement in waterborne '
         'vehicles', 'p. 44'),
        ('Capsizing and damage to '
         'craft', 'p. 45'),
        ('The boating proficiency',
         'p. 45'),
        ('Portaging', 'p. 45'),
        ('Use of a capsized '
         'vessel', 'p. 46'),
        ('Flying mounts', 'p. 47'),
        ('To fall or not to fall',
         'p. 48'),
        ('Proficiency in airborne '
         'riding', 'p. 49'),
    ]),
    ('Food and water',
     'pp. 50-60', [
        ('Going without food',
         'p. 50'),
        ('Going without water',
         'p. 52'),
        ('Effects on animals',
         'p. 52'),
        ('Minimum daily requirement '
         'of food', 'p. 52'),
        ('Minimum daily requirement '
         'of water', 'p. 53'),
        ('Food gathering', 'p. 53'),
        ('Foraging', 'p. 53'),
        ('Inedible plants', 'p. 54'),
        ('Hunting', 'p. 55'),
        ('Stalking a wounded '
         'animal', 'p. 55'),
        ('The hunting proficiency',
         'p. 57'),
        ('Fishing', 'p. 57'),
        ('Consuming and carrying '
         'food', 'p. 58'),
        ('Finding water', 'p. 58'),
        ('Where water is found',
         'p. 59'),
        ('Water in the desert',
         'p. 60'),
        ('Purifying water', 'p. 60'),
    ]),
    ('Camping and campfires',
     'pp. 61-68', [
        ('Natural shelters', 'p. 61'),
        ('Portable shelters',
         'p. 62'),
        ('Rest and comfort', 'p. 64'),
        ('How much sleep?', 'p. 64'),
        ('Good sleep vs bad sleep',
         'p. 65'),
        ('Fire: friend and foe',
         'p. 65'),
        ('Precautions and perils',
         'p. 66'),
        ('Uncontrollable fires',
         'p. 67'),
        ('Damage from fire', 'p. 68'),
    ]),
    ('Medicine and first aid',
     'pp. 69-71', [
        ('Availability of '
         'medicinal plants', 'p. 69'),
        ('Proficiency in plant '
         'lore', 'p. 70'),
        ('Injuries and treatment',
         'p. 70'),
        ('First aid equipment',
         'p. 71'),
    ]),
    ('Vision and visibility',
     'pp. 72-75', [
        ('Normal vision', 'p. 72'),
        ('Infravision', 'p. 73'),
        ('Ultravision', 'p. 74'),
        ('Artificial illumination',
         'p. 74'),
    ]),
    ('Natural hazards in the '
     'wilderness', 'pp. 76-83', [
        ('Volcanoes', 'p. 76'),
        ('Lava eruptions', 'p. 76'),
        ('Ash eruptions', 'p. 76'),
        ('Explosive eruptions',
         'p. 78'),
        ('Earthquakes', 'p. 78'),
        ('Tidal waves', 'p. 79'),
        ('Floods and flash floods',
         'p. 80'),
        ('Avalanches, rockfalls, '
         'and mudslides', 'p. 80'),
        ('Quicksand', 'p. 83'),
    ]),
    ('Combat rules for '
     'wilderness play',
     'pp. 84-87', [
        ('Fighting while climbing',
         'p. 84'),
        ('Fighting while '
         'precariously balanced',
         'p. 84'),
        ('Fighting in water',
         'p. 85'),
        ('Fighting in poor '
         'visibility', 'p. 86'),
        ('Melee combat from a '
         'mount', 'p. 86'),
        ('Missile combat from a '
         'mount', 'p. 86'),
        ('Forcing opponents to '
         'dismount', 'p. 87'),
    ]),
    ('Fatigue and exhaustion',
     'pp. 88-89', [
        ('Characters', 'p. 88'),
        ('Land-based mounts and '
         'pack animals', 'p. 88'),
        ('Flying mounts', 'p. 89'),
    ]),
    ('Mounts and beasts of '
     'burden', 'pp. 90-94', [
        ('Animals as individuals',
         'p. 91'),
        ('Calming an excited '
         'animal', 'p. 94'),
        ('Understanding an animal',
         'p. 94'),
    ]),
    ('Magic in the wilderness',
     'pp. 95-102', [
        ('Spells', 'p. 95'),
        ('Potions', 'p. 100'),
        ('Protection scrolls',
         'p. 100'),
        ('Rings', 'p. 100'),
        ('Rods, staves, and wands',
         'p. 101'),
        ('Miscellaneous magic',
         'p. 101'),
    ]),
]

CLOSED_SUBS = {
    'Success and failure - '
    'the Proficiency Check '
    'system',
    'Improving proficiencies',
    'Expanding proficiency '
    'slots (optional rule)',
}

# all 42 tables from the book
# own Tables index (printed
# p. 4): (num, title, page)
TB = [
    (1, 'character proficiencies',
     12),
    (2, 'wilderness proficiencies',
     12),
    (3, 'effects of clothing and '
     'armor on personal '
     'temperature', 19),
    (4, 'temperature effects', 21),
    (5, 'wind velocity effects',
     21),
    (6, 'hurricane damage to '
     'structures', 23),
    (7, 'tornado damage to '
     'structures', 24),
    (8, 'hailstorm damage to '
     'characters', 24),
    (9, 'temperature damage to '
     'characters', 26),
    (10, 'frostbite damage to '
     'characters', 27),
    (11, 'encumbrance limits for '
     'characters', 30),
    (12, 'character movement on '
     'foot', 31),
    (13, 'encumbrance limits and '
     'movement rates for '
     'animals', 32),
    (14, 'movement of vehicles',
     33),
    (15, 'climbing movement rates',
     33),
    (16, "modifiers to non-thief's "
     'climbing rating', 35),
    (17, 'damage from free fall '
     'or severe slope', 35),
    (18, 'damage from tumbling '
     'down moderate or gentle '
     'slope', 36),
    (19, 'chance of stopping a '
     'fall or tumble', 36),
    (20, 'grapple success', 38),
    (21, 'thrown loop ranges', 38),
    (22, "characters' jumping "
     'ability', 39),
    (23, 'movement in reduced '
     'visibility', 40),
    (24, 'effects of encumbrance '
     'on swimming', 41),
    (25, 'waterborne vehicle '
     'characteristics', 44),
    (26, 'chance of capsizing',
     45),
    (27, 'characteristics of '
     'flying mounts', 47),
    (28, 'tolerance levels for '
     'lack of food', 50),
    (29, 'water requirements for '
     'characters', 53),
    (30, 'foraging success', 53),
    (31, 'hunting success', 55),
    (32, 'fishing success', 57),
    (33, 'chance of food '
     'spoilage', 58),
    (34, 'chance of finding '
     'water', 59),
    (35, 'chance of finding '
     'natural shelter', 61),
    (36, 'portable shelter '
     'characteristics', 62),
    (37, 'effects of lack of '
     'sleep', 64),
    (38, 'campfire characteristics',
     65),
    (39, 'availability of fuel',
     66),
    (40, 'availability of '
     'medicinal plants', 69),
    (41, 'outdoor range of normal '
     'vision', 73),
    (42, 'reactions of animals',
     92),
]
if len(TB) != 42 or len(CH) != 14:
    die('the report rosters')

RP = [
    '# WSG Gap Report - the book '
    'vs the repo',
    '',
    'R425 ARC OPENER. The '
    'wilderness arc names the '
    'Wilderness Survival Guide. '
    'This report inventories the '
    'whole WSG book against the '
    'engine and is, by design, '
    'lossless: it mirrors the '
    'book own structure (the 14 '
    'chapters, the DM section, '
    'the weather appendix, the '
    'compiled tables), every '
    'named table from the book '
    'own Tables index gets its '
    'own line item (the '
    'manifest - nothing can be '
    'skipped silently), and '
    'every load-bearing prose '
    'mechanic is its own '
    'sub-item rather than a '
    'clause in a paragraph. '
    'Engine scope unchanged: the '
    'data-driven registries '
    '(append a row, not a '
    're-carve), the rules/ pin '
    'headers, the battery '
    'audits. Closure criterion: '
    'a box closes when the '
    'feature PLAYS right - '
    'compiling is not the '
    'test; a round closes an '
    'item by flipping the box '
    'in the SAME commit. The '
    'universe: this book, the '
    'landed DMG, PHB and UA '
    'reports, and the engine '
    'pins they carry; the '
    'engine ingests any source '
    'the same way (survey, gap '
    'report, pins, provenance).',
    '',
    'Conventions as the UA '
    'report: [x] verified '
    'against the book text '
    '(with the round); [~] '
    'verified DIVERGENT; [ ] '
    'open item; DEFERRED for '
    'wants gated on an engine '
    'layer not yet built. '
    'Page cites are the PRINTED '
    'book pages (the pdf page '
    '= printed + 1; the Table '
    '1/2 grids live on printed '
    'p. 12).',
    '',
    '## The chapters (the book '
    'own Table of Contents '
    'hierarchy)',
    '',
]
for title, pages, subs in CH:
    RP.append('- [ ] **%s** (%s)'
              % (title, pages))
    for sub, pg in subs:
        if sub in CLOSED_SUBS:
            RP.append('  - [x] %s (%s) '
                      '- R425: the check '
                      'system and the '
                      'improving/expanding '
                      'rules pin as '
                      'rules/wsgprof.h'
                      % (sub, pg))
        else:
            RP.append('  - [ ] %s (%s)'
                      % (sub, pg))
RP += [
    '',
    '## The DM section, the '
    'appendix, the compiled '
    'tables',
    '',
    '- [ ] **Dungeon Master '
    'section** (pp. 103-106)',
    '  - [ ] Starting from '
    'scratch (pp. 103-106)',
    '- [ ] **Appendix: the world '
    'of weather** '
    '(pp. 107-119)',
    '  - [ ] The weather system '
    '(generation, the tables)',
    '  - [ ] The weather effects '
    'on play',
    '- [ ] **Compiled tables** '
    '(pp. 120-126)',
    '',
    '## The tables (the book own '
    'Tables index - the '
    'manifest)',
    '',
]
for num, name, pg in TB:
    if num <= 2:
        RP.append('- [x] **Table %d: %s** '
                  '(p. %d) - R425: the '
                  'printed grids pin as '
                  'rules/wsgprof.h'
                  % (num, name, pg))
    else:
        RP.append('- [ ] **Table %d: %s** '
                  '(p. %d)'
                  % (num, name, pg))
RP += [
    '',
    'Post-state at R425: 5 '
    'closed, 181 open (the R425 '
    'round closes the '
    'Proficiency Check system, '
    'the improving rule, the '
    'expanding optional rule '
    'and the two printed p. 12 '
    'grids - five boxes; the 25 '
    'proficiency descriptions '
    'and everything else stay '
    'open, worked top-down - '
    'data tables first).',
    '',
]
REPORT = NL.join(RP)

# the gap censuses: the
# closed count takes every
# [x] box (chapter level and
# sub level - the amended
# census, per the user
# decision this round)
g = REPORT
if g.count('- [x]') != 5:
    die('the gap closed count %d'
        % g.count('- [x]'))
opens = [l for l in g.split(NL)
         if l.lstrip()
         .startswith('- [ ]')]
if len(opens) != 181:
    die('the gap open count %d'
        % len(opens))
if g.count('**Table ') != 42:
    die('the gap table manifest %d'
        % g.count('**Table '))
if ('- [x] **Table 1: '
    'character proficiencies** '
    '(p. 12) - R425:'
    not in g):
    die('the Table 1 box')
if ('- [x] **Table 2: '
    'wilderness proficiencies** '
    '(p. 12) - R425:'
    not in g):
    die('the Table 2 box')

newfile(GR, REPORT,
        'the wsg gap report')

# ======== (d) regtest.cpp -
# ======== the include ========

pair(RT,
     '#include "rules/uapantheon.h"  '
     '// R423: the UA Appendix S '
     'pantheon prose',
     '#include "rules/uapantheon.h"  '
     '// R423: the UA Appendix S '
     'pantheon prose' + NL
     + '#include "rules/wsgprof.h"  '
     '// R425: the WSG '
     'wilderness proficiencies',
     'regtest: the include line')

# ======== (e) regtest.cpp -
# ======== the R425 audit ========

AUD = E(*[l.rstrip() for l in [
    '    // ---- R425: the WSG',
    '    // proficiencies pin ',
    '    // audit ----',
    '    // The wilderness arc ',
    '    // opener pins the WSG ',
    '    // proficiency system ',
    '    // (rules/wsgprof.h, ',
    '    // prefix wsg): the ',
    '    // Proficiency Check ',
    '    // system (1d20 vs the ',
    '    // Appropriate Ability, ',
    '    // the unmodified 19/20 ',
    '    // auto-fail, the 18 ',
    '    // cap, the 2-in-20 ',
    '    // floor), the improving ',
    '    // rule (a cumulative -2 ',
    '    // per extra slot, from ',
    '    // 3rd level; an improved ',
    '    // 19 succeeds, a ',
    '    // natural 20 always ',
    '    // fails), the slot rules ',
    '    // (a weapon slot may ',
    '    // hold a nonweapon ',
    '    // proficiency, never the ',
    '    // reverse) and the ',
    '    // expanding optional rule ',
    '    // (one extra nonweapon ',
    '    // slot at 1st level, all ',
    '    // slots filled right ',
    '    // away - a delayed slot ',
    '    // is lost); Table 1 (the ',
    '    // 14 class rows, the ',
    '    // bard "as other classes" ',
    '    // sentinel, the horseman ',
    '    // footnote) and Table 2 ',
    '    // (the 25 rows) pin with ',
    '    // the censuses verified ',
    '    // and the denominator ',
    '    // arithmetic - the book ',
    '    // own cleric and ',
    '    // illusionist examples; ',
    '    // census 350 -> 351.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        if (!wsgCheckRolls'
    '1d20()',
    '                || wsgCheckDie'
    'Sides() != 20',
    '                || wsgCheckAuto'
    'Fail() != 19',
    '                || wsgAbilityCap()',
    '                != 18',
    '                || wsgCheckFloor'
    'In20() != 2',
    '                || !wsgImproved19'
    'Succeeds()',
    '                || !wsgNatural20'
    'Fails()',
    '                || wsgImprovingStep()',
    '                != -2',
    '                || wsgImprovingMin'
    'Level() != 3)',
    '            ++bad;',
    '        if (!wsgWeaponSlot'
    'HoldsNonweapon()',
    '                || wsgNonweaponSlot'
    'HoldsWeapon()',
    '                || !wsgExpanding'
    'BonusSlots()',
    '                || !wsgExpanding'
    'FirstLevelOnly()',
    '                || !wsgExpanding'
    'DelayedIsLost()',
    '                || wsgHorsemanZero'
    'LevelSlots() != 1',
    '                || wsgHorsemanSecond'
    'SlotLevel() != 1',
    '                || !wsgBardAsOther'
    'Classes()',
    '                || wsgClassCount()',
    '                != 14',
    '                || wsgProfCount()',
    '                != 25)',
    '            ++bad;',
    '        int d2 = 0, d3 = 0, '
    'd4 = 0,',
    '            d5 = 0, d6 = 0;',
    '        for (int c = 0;',
    '             c < wsgClassCount();',
    '             ++c) {',
    '            int d =',
    '                wsgAddEvery'
    'Levels(c);',
    '            if (d == 2) ++d2;',
    '            else if (d == 3) ++d3;',
    '            else if (d == 4) ++d4;',
    '            else if (d == 5) ++d5;',
    '            else if (d == 6) ++d6;',
    '            else ++bad;',
    '            if (wsgAddWeapon'
    'Slots(c) != 1)',
    '                ++bad;',
    '        }',
    '        if (d2 != 4 || d3 != 2',
    '                || d4 != 5 || d5 != 1',
    '                || d6 != 2)',
    '            ++bad;',
    '        if (wsgInitialWeapon'
    'Slots(0) != 3',
    '                || wsgInitial'
    'NonweaponSlots(0)',
    '                != 2',
    '                || wsgInitialWeapon'
    'Slots(4) != 4',
    '                || wsgInitialWeapon'
    'Slots(5) != 6',
    '                || wsgInitial'
    'NonweaponSlots(5)',
    '                != 3',
    '                || wsgInitialWeapon'
    'Slots(7) != 1',
    '                || wsgAddNonweapon'
    'Slots(7) != 2',
    '                || wsgInitialWeapon'
    'Slots(12) != 1',
    '                || wsgInitial'
    'NonweaponSlots(12)',
    '                != 1',
    '                || wsgInitialWeapon'
    'Slots(13) != -1',
    '                || wsgInitial'
    'NonweaponSlots(13)',
    '                != -1',
    '                || wsgAddEvery'
    'Levels(13) != 4)',
    '            ++bad;',
    '        if (wsgAddEveryLevels(2)',
    '                + 1 != 5',
    '                || wsgAddEvery'
    'Levels(7) + 1 != 7',
    '                || wsgAddEvery'
    'Levels(2) * 2 + 1',
    '                != 9',
    '                || wsgAddEvery'
    'Levels(7) * 2 + 1',
    '                != 13)',
    '            ++bad;',
    '        int n1 = 0, n2 = 0, '
    'ssum = 0,',
    '            aw = 0, ain = 0, '
    'adx = 0,',
    '            acon = 0, astr = 0, '
    'ana = 0,',
    '            p1 = 0, p2 = 0, '
    'z0 = 0,',
    '            m1 = 0, m2 = 0, '
    'm3 = 0, na = 0;',
    '        for (int p = 0;',
    '             p < wsgProfCount();',
    '             ++p) {',
    '            if (wsgSlots(p) == 1)',
    '                ++n1;',
    '            else if (wsgSlots(p)',
    '                     == 2)',
    '                ++n2;',
    '            else ++bad;',
    '            ssum += wsgSlots(p);',
    '            int a = wsgAbility(p);',
    '            if (a == 1) ++aw;',
    '            else if (a == 2) ++ain;',
    '            else if (a == 3) ++adx;',
    '            else if (a == 4) ++acon;',
    '            else if (a == 5) ++astr;',
    '            else if (a != 0)',
    '                ++bad;',
    '            else ++ana;',
    '            int m = wsgModifier(p);',
    '            if (m == 1) ++p1;',
    '            else if (m == 2) ++p2;',
    '            else if (m == 0) ++z0;',
    '            else if (m == -1) ++m1;',
    '            else if (m == -2) ++m2;',
    '            else if (m == -3) ++m3;',
    '            else if (m != 99)',
    '                ++bad;',
    '            else ++na;',
    '            if (wsgProfNeverChecks(p)',
    '                    != (wsgAbility(p)',
    '                        == 0)',
    '                    || wsgProfNever'
    'Checks(p)',
    '                    != (wsgModifier(p)',
    '                        == 99))',
    '                ++bad;',
    '        }',
    '        if (n1 != 20 || n2 != 5',
    '                || ssum != 30',
    '                || aw != 11',
    '                || ain != 3',
    '                || adx != 2',
    '                || acon != 1',
    '                || astr != 1',
    '                || ana != 7',
    '                || p1 != 5 || p2 != 2',
    '                || z0 != 5',
    '                || m1 != 3',
    '                || m2 != 2',
    '                || m3 != 1',
    '                || na != 7)',
    '            ++bad;',
    '        if (wsgSingleSlotProfs()',
    '                != n1',
    '                || wsgDoubleSlot'
    'Profs() != n2',
    '                || wsgWisdomProfs()',
    '                != aw',
    '                || wsgNeverCheck'
    'Profs() != na',
    '                || wsgHardest'
    'Modifier() != -3)',
    '            ++bad;',
    '        printf("R425 WSG '
    'proficiencies pin '
    'audit: bad %d' + chr(92)
    + 'n", bad);',
    '        if (bad) return 1;',
    '    }']])

R227 = ('    // ---- R227: the wis '
        'mental save wiring '
        'audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R425 audit block')

# ======== the verify pass ========

if applied and already:
    die('the mixed applied/already '
        'state (the R420 lesson)')

s = rd(RT)
if s.count('audit: bad') != 351:
    die('the census %d'
        % s.count('audit: bad'))
if s.count('R425 WSG '
           'proficiencies pin '
           'audit') != 1:
    die('the R425 audit label')

# the string-literal parity
# gate (the R421b lesson): no
# CODE line in the R425 audit
# block may carry an
# unterminated string literal
for ln in AUD.split(NL):
    c = ln.lstrip()
    if (c and not c.startswith('//')
            and ln.count(chr(34)) % 2):
        die('the R425 audit block '
            'has an unterminated '
            'string literal')

# the no-bare-|| gate (the
# R418b lesson): no wsg chain
# may BEGIN with '||' - a
# '||' line is legal only
# inside an open chain
prev = ''
for ln in s.split(NL):
    if ('wsg' in ln
            and ln != prev
            and _re.match(r'^ +\|\| ', ln)
            and (prev.rstrip().endswith(';')
                 or not prev.strip()
                 or prev.lstrip()
                 .startswith('//'))):
        die('a bare || wsg line')
    prev = ln

# the wsg identifier
# resolution (the R412b
# lesson): every wsg symbol
# the audit calls must be
# defined in the header
called = set(_re.findall(
    r'\b(wsg\w+)\s*\(', AUD))
defined = set(_re.findall(
    r'\b(wsg\w+)\s*\(', h))
for sym in sorted(called):
    if sym not in defined:
        die('the audit calls %s, '
            'undefined in the '
            'header' % sym)

# the include comment whole
# (the R390 lesson)
if s.count('#include "rules/'
          'wsgprof.h"  // R425: '
          'the WSG wilderness '
          'proficiencies') != 1:
    die('the wsgprof include line')

# the gap report on disk
g = rd(GR)
if g != REPORT:
    die('the wsg gap report '
        'diverges from the build')
if g.count('- [x]') != 5:
    die('the gap closed count %d'
        % g.count('- [x]'))
opens = [l for l in g.split(NL)
         if l.lstrip()
         .startswith('- [ ]')]
if len(opens) != 181:
    die('the gap open count %d'
        % len(opens))
if g.count('**Table ') != 42:
    die('the gap table manifest')

# the seed record
if 'R424 landed 2026-10-13' not in rd(SD):
    die('the seed R424 record')

# the caller contract: no
# engine caller touches the
# wsg pins
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bwsg\w', rd(path)):
        die('%s calls the wsg pins '
            'early' % path)

print('R425 splice: ALL OK '
      '(applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the WSG arc opener - '
      'the wilderness')
print('  proficiencies pin as '
      'rules/wsgprof.h (33')
print('  inlines, prefix wsg) with '
      'the check')
print('  system, Table 1 (the 14 '
      'class rows), Table 2')
print('  (the 25 proficiency rows), '
      'the slot rules and')
print('  the expanding optional '
      'rule; the lossless')
print('  wsg_gap_report.md opens '
      'the wilderness arc')
print('  (5 closed, 181 open, 42 '
      'tables); census 350 '
      '-> 351')
print('commit: R425: the WSG arc '
      'opener - the wilderness '
      'proficiencies (census 351)')

