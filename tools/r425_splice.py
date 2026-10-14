#!/usr/bin/env python3
# r425_splice: the WSG ARC OPENER
# - the wilderness proficiencies,
# census 350 -> 351. The
# Wilderness Survival Guide
# (Mohan, 1986) opens against
# the same engine conventions
# as the UA report; the opener
# rides the R322 precedent: the
# first content section pins
# with the report.
#
# The read (the OCR session
# 8d6a65a0, pdf pages 12-13 =
# printed 11-12, the grids read
# CLEAN as Markdown tables):
#   - the proficiency system:
#     the Proficiency Check is
#     an Ability Check (1d20 <=
#     the Appropriate Ability
#     succeeds), the natural 19
#     or 20 auto-fails, the
#     ability cap at 18, the
#     minimum 10 pct fail chance,
#     the -2-per-slot improving
#     rule (eligible from 3rd
#     level), the one-way
#     weapon-slot flexibility,
#     the expanding-slots
#     optional rule, the
#     negative-modifier-eases
#     sign convention;
#   - Table 1 (14 class rows):
#     the initial weapon/
#     nonweapon counts and the
#     add-per-level denominators
#     (cavalier and paladin 3/2
#     per 2, cleric 2/3 per 4,
#     druid 2/3 per 5, fighter
#     4/2 per 3, barbarian 6/3
#     per 2, ranger 3/2 per 3,
#     MU and illusionist 1/3
#     adding 1/2 per 6, thief
#     and acrobat 2/3 per 4,
#     assassin 3/2 per 4, monk
#     1/1 per 2, bard as other
#     classes adding per 4);
#   - Table 2 (25 proficiency
#     rows): the slots, the
#     appropriate abilities and
#     the die-roll modifiers
#     (5 two-slot rows, 7
#     no-check rows, riding
#     land-based the best
#     modifier at -3).
#
# Patches (4 groups):
#   - the seed takes the R424
#     record
#   - rules/wsgprof.h NEW (the
#     system pins + the two
#     tables, prefix wsg -
#     checked free)
#   - tools/wsg_gap_report.md
#     NEW (the LOSSLESS
#     whole-book inventory,
#     every named table from
#     the book own Tables index,
#     the prose mechanics as
#     sub-items)
#   - regtest.cpp: the include
#     after the uapantheon
#     include, the R425 audit
#     before the R227 anchor;
#     census 350 -> 351
#
# Guards: the string-literal
# parity gate (the R421b
# lesson), the census 351, the
# no-bare-'||' gate (the R418b
# lesson) over wsg, the
# prefix-collision check (the
# R411 lesson), the header
# statics (lines <= 78, the
# inline count), the gap
# censuses, the seed record,
# the caller contract and the
# mixed applied/already ABORT
# (the R420 lesson).

import io
import os
import re as _re

NL = chr(10)
BS = chr(92)

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


def newfile(path, content, label):
    if os.path.exists(path):
        if rd(path) == content:
            already.append(label)
        else:
            die('%s: exists with'
                ' different content'
                % label)
        return
    wr(path, content)
    applied.append(label)


WP = 'rules/wsgprof.h'
RT = 'regtest.cpp'
GP = 'tools/wsg_gap_report.md'
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

# ======== (a) the seed ========

SEED_ENTRY = E(
    '- R424 landed 2026-10-13:',
    '  commit 8e710fb (census 350,',
    '  preflight GREEN on the FIRST',
    '  run, pushed a44b3d0..8e710fb),',
    '  the APPENDIX T RESOLUTION -',
    '  the LAST open book-content',
    '  box in the UA report closes.',
    '  The clean pp. 123-128 read',
    '  resolves the five R391',
    '  flagged holes (the',
    '  classification system',
    '  paragraph, the fauchard',
    '  description, the Lucern/bec',
    '  comparison tail, the',
    '  combination intro, the',
    '  bill-guisarme features list',
    '  and the confusion sentence',
    '  all print whole); ALL SIX',
    '  flag names describe the',
    '  garble (the R422',
    '  monks-druids precedent),',
    '  each flag REPLACED 1:1 with',
    '  a ReadsClean pin, the',
    '  inline count 161 stays;',
    '  ledger clean 2->7, flagged',
    '  5->0. Gap post-state:',
    '  [x]=102, opens=3 (the two',
    '  logging layers + the',
    '  legend); ALL UA book-content',
    '  boxes CLOSED - the UA arc',
    '  is COMPLETE. The advisory',
    '  md5 diverged benignly;',
    '  the md5 stays advisory.')

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

HEADER = E(
    '// ==========================================================================',
    '// Adnd1 - rules/wsgprof.h',
    '// The WSG WILDERNESS',
    '// PROFICIENCIES pins, R425:',
    '// the arc opener - the',
    '// proficiency system and its',
    '// two tables (printed pp.',
    '// 11-12, the clean OCR read).',
    '// The Proficiency Check is an',
    '// Ability Check: 1d20 against',
    '// the Appropriate Ability,',
    '// success at or below; the',
    '// natural 19 or 20 auto-fails;',
    '// the ability caps at 18 (the',
    '// minimum 10 percent fail',
    '// chance); improving a',
    '// proficiency costs a slot and',
    '// eases the roll by 2 per',
    '// step (eligible from 3rd',
    '// level); a weapon slot may',
    '// hold a nonweapon skill,',
    '// never the reverse; the',
    '// negative modifier eases.',
    '// Table 1: the 14 class rows',
    '// (the initial weapon/',
    '// nonweapon counts, the',
    '// add-per-level denominators;',
    '// the bard takes his initial',
    '// counts from his other',
    '// class). Table 2: the 25',
    '// wilderness proficiencies',
    '// (the slots; 5 two-slot rows,',
    '// 7 no-check rows, riding',
    '// land-based the best modifier',
    '// at -3). Pin-era pattern',
    '// (R322).',
    'namespace rules {',
    '',
    '// The Proficiency Check is an',
    '// Ability Check: roll 1d20.',
    'inline int wsgCheckDieSides()',
    '    { return 20; }',
    '// Success at or below the',
    '// Appropriate Ability score.',
    'inline bool wsgCheckIsAbility'
    'Check()',
    '    { return true; }',
    '// Any unmodified 19 or 20',
    '// auto-fails, modifiers or no.',
    'inline bool wsgNaturalNineteen'
    'AutoFails()',
    '    { return true; }',
    'inline bool wsgNaturalTwenty'
    'AutoFails()',
    '    { return true; }',
    '// An ability above 18 reads',
    '// as 18 for the check.',
    'inline int wsgCheckAbilityCap()',
    '    { return 18; }',
    '// The minimum fail chance: 2',
    '// chances in 20, 10 percent.',
    'inline int wsgMinFailChancePct()',
    '    { return 10; }',
    '// Improving a proficiency eases',
    '// every subsequent check by 2',
    '// per spent slot.',
    'inline int wsgImproveDieModifier'
    'PerSlot()',
    '    { return -2; }',
    '// Improvement is eligible from',
    '// 3rd level upward.',
    'inline int wsgImproveEligible'
    'FromLevel()',
    '    { return 3; }',
    '// A weapon slot may hold a',
    '// nonweapon skill.',
    'inline bool wsgWeaponSlotHolds'
    'Nonweapon()',
    '    { return true; }',
    '// The reverse is not allowed.',
    'inline bool wsgNonweaponSlot'
    'HoldsWeapon()',
    '    { return false; }',
    '// The optional rule: one extra',
    '// nonweapon slot at 1st level,',
    '// lost if the filling delays.',
    'inline int wsgExpandOptional'
    'ExtraSlots()',
    '    { return 1; }',
    '// A negative die modifier',
    '// reduces the roll - success',
    '// grows easier.',
    'inline bool wsgNegativeModifier'
    'EasesSuccess()',
    '    { return true; }',
    '',
    '// Table 1: the 14 class rows,',
    '// book order (cavalier,',
    '// paladin, cleric, druid,',
    '// fighter, barbarian, ranger,',
    '// magic-user, illusionist,',
    '// thief, acrobat, assassin,',
    '// monk, bard).',
    'inline int wsgClassRowCount()',
    '    { return 14; }',
    '',
    '// The initial weapon slots per',
    '// class row.',
    'inline int wsgClassInitialWeapon('
    'int cl)',
    '{',
    '    switch (cl) {',
    '    case 0: return 3;',
    '    case 1: return 3;',
    '    case 2: return 2;',
    '    case 3: return 2;',
    '    case 4: return 4;',
    '    case 5: return 6;',
    '    case 6: return 3;',
    '    case 7: return 1;',
    '    case 8: return 1;',
    '    case 9: return 2;',
    '    case 10: return 2;',
    '    case 11: return 3;',
    '    case 12: return 1;',
    '    default: return 0;',
    '    }',
    '}',
    '',
    '// The initial nonweapon slots',
    '// per class row.',
    'inline int wsgClassInitial'
    'Nonweapon(int cl)',
    '{',
    '    switch (cl) {',
    '    case 0: return 2;',
    '    case 1: return 2;',
    '    case 2: return 3;',
    '    case 3: return 3;',
    '    case 4: return 2;',
    '    case 5: return 3;',
    '    case 6: return 2;',
    '    case 7: return 3;',
    '    case 8: return 3;',
    '    case 9: return 3;',
    '    case 10: return 3;',
    '    case 11: return 2;',
    '    case 12: return 1;',
    '    default: return 0;',
    '    }',
    '}',
    '',
    '// The weapon proficiencies added',
    '// per eligibility.',
    'inline int wsgClassAddWeapon('
    'int cl)',
    '{',
    '    switch (cl) {',
    '    case 7: return 1;',
    '    case 8: return 1;',
    '    default: return 1;',
    '    }',
    '}',
    '',
    '// The nonweapon proficiencies',
    '// added per eligibility (the MU',
    '// and illusionist add 1 per 2).',
    'inline int wsgClassAddNonweapon('
    'int cl)',
    '{',
    '    switch (cl) {',
    '    case 7: return 2;',
    '    case 8: return 2;',
    '    default: return 1;',
    '    }',
    '}',
    '',
    '// The levels passed per',
    '// eligibility (the add-per-level',
    '// denominators).',
    'inline int wsgClassAddPerLevels('
    'int cl)',
    '{',
    '    switch (cl) {',
    '    case 0: return 2;',
    '    case 1: return 2;',
    '    case 2: return 4;',
    '    case 3: return 5;',
    '    case 4: return 3;',
    '    case 5: return 2;',
    '    case 6: return 3;',
    '    case 7: return 6;',
    '    case 8: return 6;',
    '    case 9: return 4;',
    '    case 10: return 4;',
    '    case 11: return 4;',
    '    case 12: return 2;',
    '    case 13: return 4;',
    '    default: return 0;',
    '    }',
    '}',
    '',
    '// The bard row: the initial',
    '// counts ride the other',
    '// classes (the book own note).',
    'inline bool wsgBardInitialAs'
    'OtherClasses()',
    '    { return true; }',
    '',
    '// Table 2: the 25 wilderness',
    '// proficiencies, book order.',
    'inline int wsgProficiencyCount()',
    '    { return 25; }',
    '',
    '// The slots required per',
    '// proficiency row (endurance,',
    '// healing, riding airborne,',
    '// running and survival desert',
    '// take two).',
    'inline int wsgProficiencySlots('
    'int pr)',
    '{',
    '    switch (pr) {',
    '    case 7: return 2;',
    '    case 11: return 2;',
    '    case 15: return 2;',
    '    case 18: return 2;',
    '    case 20: return 2;',
    '    default: return 1;',
    '    }',
    '}',
    '',
    '// The two-slot rows, counted.',
    'inline int wsgTwoSlotProficiency'
    'Count()',
    '    { return 5; }',
    '',
    '// The no-check rows (NA:',
    '// blind-fighting, endurance,',
    '// mountaineering, the three',
    '// survivals, tracking).',
    'inline int wsgNoCheckProficiency'
    'Count()',
    '    { return 7; }',
    '',
    '// Riding land-based: one slot,',
    '// the best die modifier at -3.',
    'inline int wsgRidingLandBased'
    'Slots()',
    '    { return 1; }',
    'inline int wsgRidingLandBased'
    'Modifier()',
    '    { return -3; }',
    '',
    '// Charioteering: dexterity at -2.',
    'inline int wsgCharioteering'
    'Modifier()',
    '    { return -2; }',
    '',
    '// Foraging: intelligence, the',
    '// hardest check at +2.',
    'inline int wsgForagingModifier()',
    '    { return 2; }',
    '',
    '// Riding airborne: two slots, +2.',
    'inline int wsgRidingAirborne'
    'Slots()',
    '    { return 2; }',
    '',
    '// Healing: two slots, wisdom',
    '// at -2.',
    'inline int wsgHealingSlots()',
    '    { return 2; }',
    'inline int wsgHealingModifier()',
    '    { return -2; }',
    '',
    '// Endurance and running: two',
    '// slots apiece.',
    'inline int wsgEnduranceSlots()',
    '    { return 2; }',
    'inline int wsgRunningSlots()',
    '    { return 2; }',
    '',
    '// Survival desert: the lone',
    '// two-slot survival.',
    'inline int wsgSurvivalDesert'
    'Slots()',
    '    { return 2; }',
    '}   // namespace rules',
    '')

# the header statics: ascii,
# no line over 78, no
# backslash bytes
for ln in HEADER.split(NL):
    if len(ln) > 78:
        die('the header line %d long'
            ' (%r)' % (len(ln), ln))
    for c in ln:
        if ord(c) > 127:
            die('the header holds'
                ' non-ascii')
    if BS in ln:
        die('the header holds a'
            ' backslash')

newfile(WP, HEADER + NL,
        'wsgprof.h: the pin header')

# the prefix-collision check
# (the R411 lesson): no wsg
# identifier may pre-exist -
# gated on the R425 audit being
# absent (idempotent on the
# second run)
if ('R425 WSG proficiencies'
        not in rd(RT)):
    for p in ('regtest.cpp',
              'rules/comeliness.h'):
        t = rd(p)
        if _re.search(r'(?<![\w])wsg\w',
                      t):
            die('a wsg identifier'
                ' pre-exists in %s' % p)

# ======== (c) tools/wsg_gap_report.md ========

REPORT = E(
    '# WSG Gap Report - the book vs the repo',
    '',
    'R425 ARC OPENER. The standing scope (the',
    'seed, 2026-10-05) names more sourcebooks;',
    'this report inventories the WILDERNESS',
    'SURVIVAL GUIDE (Mohan, 1986) against the',
    'same engine conventions as the UA report',
    'and is, by design, lossless: it mirrors',
    'the book own structure (the players and',
    'DM mechanics pp. 5-102 in book order,',
    'the DM section pp. 103-106, the weather',
    'appendix pp. 107-119, the compiled tables',
    'pp. 120-126, the index p. 127), every',
    'named table from the book own Tables index',
    '(42) sits inside its chapter as its own',
    'line item (the manifest - nothing can be',
    'skipped silently), the appendix A-series',
    'tables (A1-A8) get their own line items',
    '(the book own index omits them), and every',
    'load-bearing prose mechanic from the book',
    'own TOC is its own open sub-item. The',
    'chapter order IS the round order; the',
    'suites named in the section heads are the',
    'round-sized work units. Engine scope',
    'unchanged: the data-driven class and spell',
    'registries (append a row, not a re-carve),',
    'the rules/ pin headers, the battery',
    'audits. Closure criterion: a box closes',
    'when the feature PLAYS right - compiling',
    'is not the test; the game-level logging',
    'layer is the instrument (out of scope by',
    'the user decision, as in the UA arc). The',
    'OCR reads the WSG grids clean (Markdown',
    'tables - a better grain than the UA scan);',
    'the printed-page offset is pdf page minus',
    'one.',
    '',
    'Conventions as the UA report: [x]',
    'verified against the book text (with the',
    'round); [~] verified DIVERGENT; [ ] open',
    'item; DEFERRED for wants gated on an',
    'engine layer not yet built. A round',
    'closes an item by flipping the box in the',
    'SAME commit. The existing engine seams',
    'named in the items: the underwater layers',
    '(R168, R311-R320), the infravision fold',
    '(R317/R319), the mount layer (R403), the',
    'overland layers (R92, R123, R152). The',
    'universe: this book, the landed UA and',
    'DMG and PHB reports, and - named for the',
    'future - the house-rules and third-party',
    'arcs.',
    '',
    '## Ch 1: Overview of the wilderness (pp.',
    '## 7-10)',
    '',
    '- [ ] Terrain: desert (p. 7) - the',
    '      definition and its play effects.',
    '- [ ] Terrain: forest (p. 7).',
    '- [ ] Terrain: hills (p. 8).',
    '- [ ] Terrain: mountains (p. 8) - the',
    '      snow line and the exposure rules.',
    '- [ ] Terrain: plains (p. 9).',
    '- [ ] Terrain: seacoast (p. 9) - the',
    '      encounter-table translation note.',
    '- [ ] Terrain: swamp (p. 9) - the',
    '      standing-water definition.',
    '- [ ] The hierarchy of terrain (p. 9):',
    '      the 1-7 ranking (seacoast highest,',
    '      mountains lowest) with the worked',
    '      examples and the two overrides.',
    '- [ ] Bodies of water (pp. 9-10) - the',
    '      R168/R311-R320 underwater layers are',
    '      the seam.',
    '- [ ] Climate (pp. 10-11): the five',
    '      climatic regions and the DMG/MM II',
    '      translation rules - the keying the',
    '      weather appendix rides.',
    '',
    '## Ch 2: Wilderness proficiencies (pp.',
    '## 11-17) - the proficiency suite',
    '',
    '- [x] The proficiency system (pp. 11-12):',
    '      the Proficiency Check (1d20 vs the',
    '      Appropriate Ability, at or below',
    '      succeeds), the natural 19/20',
    '      auto-fail, the ability cap at 18, the',
    '      10 percent minimum fail, the',
    '      -2-per-slot improving rule (from 3rd',
    '      level), the one-way weapon-slot',
    '      flexibility, the expanding-slots',
    '      optional rule.',
    '      - AMENDED R425: the system pins',
    '        (rules/wsgprof.h, prefix wsg), the',
    '        censuses cross-checked live against',
    '        the two tables (14 class rows, 25',
    '        proficiency rows, 5 two-slot, 7',
    '        no-check).',
    '- [x] Table 1: Character Proficiencies',
    '      (p. 12) - the 14 class rows: the',
    '      initial weapon/nonweapon counts, the',
    '      add-per-level denominators, the',
    '      0-level horsemen/lancers note, the',
    '      counting-levels rule.',
    '      - AMENDED R425: pinned row for row',
    '        (rules/wsgprof.h), the bard',
    '        initial-as-other-classes note',
    '        included.',
    '- [x] Table 2: Wilderness Proficiencies',
    '      (p. 12) - the 25 proficiencies:',
    '      slots, appropriate ability, die-roll',
    '      modifier per row.',
    '      - AMENDED R425: pinned (the slot',
    '        switch, the two-slot and no-check',
    '        censuses, the riding land-based -3,',
    '        the foraging +2).',
    '- [ ] The proficiency descriptions suite',
    '      (pp. 13-17) - the 25 descriptions,',
    '      each carrying its own mechanics:',
    '      alertness, animal handling, animal',
    '      lore, blind-fighting, boating,',
    '      charioteering, direction sense,',
    '      endurance, fire-building, fishing,',
    '      foraging, healing, hunting,',
    '      mountaineering, plant lore, riding',
    '      airborne, riding land-based, rope',
    '      use, running, survival cold, survival',
    '      desert, survival heat, swimming,',
    '      tracking, weather sense (pinned in',
    '      batch rounds, 8-9 per round).',
    '',
    '## Ch 3: Dressing for the weather (pp.',
    '## 18-20)',
    '',
    '- [ ] Personal temperature and clothing',
    '      (pp. 18-19) - the clothing layers.',
    '- [ ] Table 3: Effects of clothing and',
    '      armor on personal temperature (p.',
    '      19).',
    '- [ ] Protected and unprotected',
    '      characters; the effects of exertion',
    '      (p. 19).',
    '- [ ] Clothing that functions as armor',
    '      (pp. 19-20).',
    '',
    '## Ch 4: Effects of the environment (pp.',
    '## 21-29) - the environment suite',
    '',
    '- [ ] Temperature and wind (pp. 21-22).',
    '- [ ] Table 4: Temperature effects (p.',
    '      21).',
    '- [ ] Table 5: Wind velocity effects (p.',
    '      21).',
    '- [ ] Precipitation (pp. 22-23).',
    '- [ ] Special weather (pp. 23-26).',
    '- [ ] Table 6: Hurricane damage to',
    '      structures (p. 23).',
    '- [ ] Table 7: Tornado damage to',
    '      structures (p. 24).',
    '- [ ] Table 8: Hailstorm damage to',
    '      characters (p. 24).',
    '- [ ] Damage from heat and cold (pp.',
    '      26-28).',
    '- [ ] Table 9: Temperature damage to',
    '      characters (p. 26).',
    '- [ ] Table 10: Frostbite damage to',
    '      characters (p. 27).',
    '- [ ] Effects on equipment (pp. 28-29).',
    '',
    '## Ch 5: Encumbrance and movement (pp.',
    '## 30-49) - the three suites',
    '',
    '- [ ] Encumbrance of characters (p. 30).',
    '- [ ] Table 11: Encumbrance limits for',
    '      characters (p. 30).',
    '- [ ] Terrain definitions for movement',
    '      (pp. 30-31).',
    '- [ ] Large-scale overland movement (pp.',
    '      31-32) - the overland suite; an',
    '      engine-seam candidate riding R92/',
    '      R123/R152 (the R312',
    '      flooded-crossing precedent).',
    '- [ ] Table 12: Character movement on',
    '      foot (p. 31).',
    '- [ ] Encumbrance and movement for',
    '      land-based animals (pp. 32-33).',
    '- [ ] Table 13: Encumbrance limits and',
    '      movement rates for animals (p. 32).',
    '- [ ] Movement of land-based vehicles',
    '      (p. 33).',
    '- [ ] Table 14: Movement of vehicles (p.',
    '      33).',
    '- [ ] Movement across special terrain',
    '      (p. 33).',
    '- [ ] Climbing (pp. 33-36) - the climbing',
    '      and rope suite.',
    '- [ ] Table 15: Climbing movement rates',
    '      (p. 33).',
    '- [ ] Surface types and conditions (pp.',
    '      34-35).',
    '- [ ] Table 16: Modifiers to non-thief',
    '      climbing rating (p. 35).',
    '- [ ] Chance of falling and climbing',
    '      checks (pp. 34-35).',
    '- [ ] Table 17: Damage from free fall or',
    '      severe slope (p. 35).',
    '- [ ] Table 18: Damage from tumbling down',
    '      moderate or gentle slope (p. 36).',
    '- [ ] Table 19: Chance of stopping a fall',
    '      or tumble (p. 36).',
    '- [ ] Rope work (pp. 36-38): roping',
    '      together, rappelling, belaying, the',
    '      chasm crossing.',
    '- [ ] Table 20: Grappling success (p.',
    '      38).',
    '- [ ] Table 21: Thrown loop ranges (p.',
    '      38).',
    '- [ ] The mountaineering proficiency',
    '      (p. 39).',
    '- [ ] Movement on slippery horizontal',
    '      surfaces (p. 39).',
    '- [ ] Jumping (pp. 39-40).',
    '- [ ] Table 22: Characters jumping ability',
    '      (p. 39).',
    '- [ ] Overland movement in reduced',
    '      visibility (p. 40).',
    '- [ ] Table 23: Movement in reduced',
    '      visibility (p. 40).',
    '- [ ] Swimming (pp. 41-44) - the water',
    '      and air travel suite; the R168/',
    '      R311-R320 underwater layers are the',
    '      seam.',
    '- [ ] Table 24: Effects of encumbrance on',
    '      swimming (p. 41).',
    '- [ ] Diving, surfacing, treading water,',
    '      holding breath (pp. 42-43).',
    '- [ ] Movement in waterborne vehicles',
    '      (pp. 44-45).',
    '- [ ] Table 25: Waterborne vehicle',
    '      characteristics (p. 44).',
    '- [ ] Capsizing and damage to craft (p.',
    '      45).',
    '- [ ] Table 26: Chance of capsizing (p.',
    '      45).',
    '- [ ] The boating proficiency and',
    '      portaging (pp. 45-46).',
    '- [ ] Use of a capsized vessel (p. 46).',
    '- [ ] Flying mounts (pp. 47-49) - the',
    '      R403 mount layer is the seam.',
    '- [ ] Table 27: Characteristics of flying',
    '      mounts (p. 47).',
    '- [ ] To fall or not to fall (p. 48).',
    '- [ ] Proficiency in airborne riding (p.',
    '      49).',
    '',
    '## Ch 6: Food and water (pp. 50-60) - the',
    '## survival suite',
    '',
    '- [ ] Going without food (p. 50).',
    '- [ ] Table 28: Tolerance levels for lack',
    '      of food (p. 50).',
    '- [ ] Going without water (p. 52).',
    '- [ ] Effects on animals (p. 52).',
    '- [ ] Table 29: Water requirements for',
    '      characters (p. 53).',
    '- [ ] Minimum daily requirement of food',
    '      and water (pp. 52-53).',
    '- [ ] Food gathering (p. 53).',
    '- [ ] Foraging (pp. 53-54).',
    '- [ ] Table 30: Foraging success (p. 53).',
    '- [ ] Inedible plants (p. 54).',
    '- [ ] Hunting (pp. 55-57).',
    '- [ ] Table 31: Hunting success (p. 55).',
    '- [ ] Stalking a wounded animal (pp.',
    '      55-56).',
    '- [ ] The hunting proficiency (p. 57).',
    '- [ ] Fishing (pp. 57-58).',
    '- [ ] Table 32: Fishing success (p. 57).',
    '- [ ] Consuming and carrying food (p. 58).',
    '- [ ] Table 33: Chance of food spoilage',
    '      (p. 58).',
    '- [ ] Finding water (pp. 58-60).',
    '- [ ] Table 34: Chance of finding water',
    '      (p. 59).',
    '- [ ] Water in the desert (p. 60).',
    '- [ ] Purifying water (p. 60).',
    '',
    '## Ch 7: Camping and campfires (pp. 61-68)',
    '## - the camp suite',
    '',
    '- [ ] Natural shelters (pp. 61-62).',
    '- [ ] Table 35: Chance of finding natural',
    '      shelter (p. 61).',
    '- [ ] Portable shelters (pp. 62-64).',
    '- [ ] Table 36: Portable shelter',
    '      characteristics (p. 62).',
    '- [ ] Rest and comfort (pp. 64-65): how',
    '      much sleep, good sleep vs bad sleep.',
    '- [ ] Table 37: Effects of lack of sleep',
    '      (p. 64).',
    '- [ ] Fire: friend and foe (pp. 65-68):',
    '      precautions and perils,',
    '      uncontrollable fires, damage from',
    '      fire.',
    '- [ ] Table 38: Campfire characteristics',
    '      (p. 65).',
    '- [ ] Table 39: Availability of fuel (p.',
    '      66).',
    '',
    '## Ch 8: Medicine and first aid (pp.',
    '## 69-71)',
    '',
    '- [ ] Availability of medicinal plants',
    '      (p. 69).',
    '- [ ] Table 40: Availability of medicinal',
    '      plants (p. 69).',
    '- [ ] Proficiency in plant lore (p. 70).',
    '- [ ] Injuries and treatment (pp. 70-71).',
    '- [ ] First aid equipment (p. 71).',
    '',
    '## Ch 9: Vision and visibility (pp.',
    '## 72-75)',
    '',
    '- [ ] Normal vision (pp. 72-73).',
    '- [ ] Table 41: Outdoor range of normal',
    '      vision (p. 73).',
    '- [ ] Infravision (pp. 73-74) - the',
    '      R317/R319 infravision layers are the',
    '      seam.',
    '- [ ] Ultravision (p. 74).',
    '- [ ] Artificial illumination (pp.',
    '      74-75).',
    '',
    '## Ch 10: Natural hazards in the',
    '## wilderness (pp. 76-83) - the hazards',
    '## suite',
    '',
    '- [ ] Volcanoes: lava eruptions (pp.',
    '      76-78).',
    '- [ ] Volcanoes: ash eruptions (pp.',
    '      76-78).',
    '- [ ] Volcanoes: explosive eruptions (p.',
    '      78).',
    '- [ ] Earthquakes (pp. 78-79).',
    '- [ ] Tidal waves (p. 79).',
    '- [ ] Floods and flash floods (p. 80).',
    '- [ ] Avalanches, rockfalls, and',
    '      mudslides (pp. 80-83).',
    '- [ ] Quicksand (p. 83).',
    '',
    '## Ch 11: Combat rules for wilderness play',
    '## (pp. 84-87)',
    '',
    '- [ ] Fighting while climbing (p. 84).',
    '- [ ] Fighting while precariously',
    '      balanced (p. 84).',
    '- [ ] Fighting in water (p. 85).',
    '- [ ] Fighting in poor visibility (p. 86).',
    '- [ ] Melee combat from a mount (p. 86).',
    '- [ ] Missile combat from a mount (pp.',
    '      86-87).',
    '- [ ] Forcing opponents to dismount (p.',
    '      87).',
    '',
    '## Ch 12: Fatigue and exhaustion (pp.',
    '## 88-89)',
    '',
    '- [ ] Characters (p. 88).',
    '- [ ] Land-based mounts and pack animals',
    '      (p. 88).',
    '- [ ] Flying mounts (p. 89).',
    '',
    '## Ch 13: Mounts and beasts of burden (pp.',
    '## 90-94) - the mounts suite (rides R403)',
    '',
    '- [ ] Animals as individuals (pp. 91-94).',
    '- [ ] Table 42: Reactions of animals (p.',
    '      92).',
    '- [ ] Calming an excited animal (p. 94).',
    '- [ ] Understanding an animal (p. 94).',
    '',
    '## Ch 14: Magic in the wilderness (pp.',
    '## 95-102) - the magic notes suite',
    '',
    '- [ ] Spells (pp. 95-100): the',
    '      wilderness-effect notes on the',
    '      existing spell roster (the',
    '      data-driven registry takes rows).',
    '- [ ] Potions (p. 100).',
    '- [ ] Protection scrolls (p. 100).',
    '- [ ] Rings (p. 100).',
    '- [ ] Rods, staves, and wands (p. 101).',
    '- [ ] Miscellaneous magic (pp. 101-102).',
    '',
    '## Ch 15: The DM section (pp. 103-106)',
    '',
    '- [ ] Starting from scratch (pp.',
    '      103-106): the campaign-map design',
    '      and the world-building advice - the',
    '      DM-judgment layer (record-not-charge',
    '      unless the user decides otherwise).',
    '',
    '## Ch 16: The world of weather (pp.',
    '## 107-119) - the weather suite, the',
    '## capstone',
    '',
    '- [ ] The climatic regions (pp. 107-109):',
    '      the five bands in detail, the',
    '      7-terrain x 5-climate keying.',
    '- [ ] Table A1: Temperature variation',
    '      (p. 109) - the letter-coded',
    '      temperature ladder.',
    '- [ ] Table A2: Day-to-day change (p.',
    '      110) - the dice-driven state walk.',
    '- [ ] Table A3: Precipitation variation',
    '      (pp. 111-112).',
    '- [ ] Table A4: Special weather (p. 113)',
    '      - the four-letter codes.',
    '- [ ] The special weather definitions (pp.',
    '      113-116): the episode state',
    '      machines - the cold wave, the',
    '      drought, the hurricane (the',
    '      once-per-month-per-200-mile rule),',
    '      and the rest.',
    '- [ ] Table A5: Humidity variation (p.',
    '      117).',
    '- [ ] Table A6: Humidity and effective',
    '      temperature (p. 117).',
    '- [ ] Table A7: Wind chill (p. 118) - the',
    '      cross-index grid, the extrapolation',
    '      and 40-mph cap rules.',
    '- [ ] Table A8: Hours of daylight (p.',
    '      118).',
    '- [ ] The weather determination system as',
    '      a whole (pp. 107-120) - the',
    '      engine-seam candidate (the R312',
    '      flooded-crossing precedent); pin the',
    '      tables first, the generator is its',
    '      own round.',
    '',
    '## Ch 17: The compiled tables (pp. 120-126)',
    '',
    '- [ ] The compiled tables reprint (pp.',
    '      120-126): a free second read of the',
    '      parent tables - each reprint',
    '      verified cell for cell against its',
    '      parent ([~] on divergence); closes',
    '      with the parents.',
    '',
    '## Ch 18: The index (p. 127)',
    '',
    '- [x] The index (p. 127): a finding aid,',
    '      no mechanics - recorded, not',
    '      charged.',
    )

# the report statics: ascii,
# every line within the
# house bound
for ln in REPORT.split(NL):
    if len(ln) > 57:
        die('the report line %d long'
            ' (%r)' % (len(ln), ln[:40]))
    for c in ln:
        if ord(c) > 127:
            die('the report holds'
                ' non-ascii')

# the report censuses: the 42
# named tables all present
tbl = 0
for i in range(1, 43):
    if ('Table %d:' % i) in REPORT:
        tbl += 1
if tbl != 42:
    die('the report names %d of'
        ' the 42 tables' % tbl)

newfile(GP, REPORT + NL,
        'wsg_gap_report.md: the arc'
        ' report')

# ======== (d) regtest.cpp ========

# the include rides after the
# uapantheon include
pair(RT,
     '#include "rules/uapantheon.h"  // R423:'
     ' the UA Appendix S pantheon prose',
     E('#include "rules/uapantheon.h"  // R423:'
       ' the UA Appendix S pantheon prose',
       '#include "rules/wsgprof.h"  // R425:'
       ' the WSG wilderness proficiencies'),
     'regtest: the include')

# ---- the R425 audit block ----
AUD = E(
    '    // ---- R425: the WSG wilderness',
    '    // proficiencies pin audit ----',
    '    // The WSG arc opener: the',
    '    // proficiency system (printed pp.',
    '    // 11-12, the clean OCR read) and',
    '    // its two tables pin as',
    '    // rules/wsgprof.h (NEW, prefix',
    '    // wsg): the Proficiency Check is',
    '    // an Ability Check (1d20 at or',
    '    // below the Appropriate Ability',
    '    // succeeds; the natural 19 or 20',
    '    // auto-fails; the ability caps at',
    '    // 18, the minimum fail 10',
    '    // percent), the improving rule',
    '    // eases by 2 per slot from 3rd',
    '    // level, the weapon slot holds a',
    '    // nonweapon skill never the',
    '    // reverse, the optional extra',
    '    // slot rides 1st level; Table 1',
    '    // pins 14 class rows (cavalier and',
    '    // paladin 3/2 per 2, cleric 2/3',
    '    // per 4, druid 2/3 per 5, fighter',
    '    // 4/2 per 3, barbarian 6/3 per 2,',
    '    // ranger 3/2 per 3, the MU and',
    '    // illusionist 1/3 adding 1/2 per',
    '    // 6, thief and acrobat 2/3 per 4,',
    '    // assassin 3/2 per 4, monk 1/1',
    '    // per 2, the bard as other classes',
    '    // adding per 4); Table 2 pins 25',
    '    // proficiency rows (5 two-slot,',
    '    // 7 no-check, riding land-based',
    '    // the best modifier at -3,',
    '    // foraging the hardest at +2);',
    '    // census 350 -> 351.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        if (wsgCheckDieSides() != 20',
    '                || !wsgCheckIsAbility'
    'Check()',
    '                || !wsgNaturalNineteen'
    'AutoFails()',
    '                || !wsgNaturalTwenty'
    'AutoFails()',
    '                || wsgCheckAbilityCap()'
    ' != 18',
    '                || wsgMinFailChancePct()'
    ' != 10',
    '                || wsgImproveDieModifier'
    'PerSlot() != -2',
    '                || wsgImproveEligible'
    'FromLevel() != 3',
    '                || !wsgWeaponSlotHolds'
    'Nonweapon()',
    '                || wsgNonweaponSlot'
    'HoldsWeapon()',
    '                || wsgExpandOptional'
    'ExtraSlots() != 1',
    '                || !wsgNegativeModifier'
    'EasesSuccess())',
    '            ++bad;',
    '        if (wsgClassRowCount() != 14',
    '                || wsgProficiencyCount()'
    ' != 25',
    '                || wsgTwoSlotProficiency'
    'Count() != 5',
    '                || wsgNoCheckProficiency'
    'Count() != 7)',
    '            ++bad;',
    '        if (wsgClassInitialWeapon(0)'
    ' != 3',
    '                || wsgClassInitial'
    'Nonweapon(0) != 2',
    '                || wsgClassAddPerLevels(0)'
    ' != 2',
    '                || wsgClassInitialWeapon(5)'
    ' != 6',
    '                || wsgClassInitial'
    'Nonweapon(5) != 3',
    '                || wsgClassAddPerLevels(7)'
    ' != 6',
    '                || wsgClassAddWeapon(7)'
    ' != 1',
    '                || wsgClassAddNonweapon(7)'
    ' != 2',
    '                || wsgClassInitialWeapon(12)'
    ' != 1',
    '                || wsgClassInitial'
    'Nonweapon(12) != 1',
    '                || wsgClassAddPerLevels(13)'
    ' != 4',
    '                || !wsgBardInitialAs'
    'OtherClasses())',
    '            ++bad;',
    '        if (wsgProficiencySlots(7)'
    ' != 2',
    '                || wsgProficiencySlots(11)'
    ' != 2',
    '                || wsgProficiencySlots(15)'
    ' != 2',
    '                || wsgProficiencySlots(18)'
    ' != 2',
    '                || wsgProficiencySlots(20)'
    ' != 2',
    '                || wsgProficiencySlots(24)'
    ' != 1',
    '                || wsgRidingLandBased'
    'Slots() != 1',
    '                || wsgRidingLandBased'
    'Modifier() != -3',
    '                || wsgCharioteering'
    'Modifier() != -2',
    '                || wsgForagingModifier()'
    ' != 2',
    '                || wsgRidingAirborne'
    'Slots() != 2',
    '                || wsgHealingSlots() != 2',
    '                || wsgHealingModifier()'
    ' != -2',
    '                || wsgEnduranceSlots()'
    ' != 2',
    '                || wsgRunningSlots()'
    ' != 2',
    '                || wsgSurvivalDesert'
    'Slots() != 2)',
    '            ++bad;',
    '        int twoslot = 0;',
    '        for (int pr = 0;',
    '             pr < wsgProficiencyCount();',
    '             ++pr)',
    '            if (wsgProficiencySlots(pr)'
    ' == 2)',
    '                ++twoslot;',
    '        if (twoslot != wsgTwoSlot'
    'ProficiencyCount())',
    '            ++bad;',
    '        printf("R425 WSG proficiencies'
    ' pin audit: bad'
    ' %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R425 audit block')

# ======== the verify pass ========

if applied and already:
    die('the mixed applied/already'
        ' state (the R420 lesson)')

s = rd(RT)
if s.count('audit: bad') != 351:
    die('the census %d'
        % s.count('audit: bad'))
if s.count('R425 WSG proficiencies') != 1:
    die('the R425 audit label')

# the string-literal parity gate
# (the R421b lesson): no CODE
# line in the R425 audit block
# may carry an unterminated
# string literal (comment lines
# may hold lone quotes)
for ln in AUD.split(NL):
    c = ln.lstrip()
    if (c and not c.startswith('//')
            and ln.count(chr(34)) % 2):
        die('the R425 audit block has'
            ' an unterminated string'
            ' literal')

# the no-bare-|| gate (the R418b
# lesson): no wsg chain may BEGIN
# with '||' - a '||' line is legal
# only inside an open chain
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

# the header mirror
h = rd(WP)
for pin in ('wsgCheckDieSides',
            'wsgNaturalNineteen'
            'AutoFails',
            'wsgClassAddPerLevels',
            'wsgProficiencySlots',
            'wsgRidingLandBased'
            'Modifier'):
    if pin not in h:
        die('the %s pin missing from'
            ' the header' % pin)
    if pin not in s:
        die('the %s pin missing from'
            ' regtest' % pin)

# the include line (the R390
# lesson): the wsgprof include
# comment must stay whole
if s.count('#include "rules/wsgprof.h"'
          '  // R425: the WSG wilderness'
          ' proficiencies') != 1:
    die('the wsgprof include line')

# the statics: no regtest
# patch line over 76 columns
for ln in AUD.split(NL):
    if len(ln) > 76:
        die('the regtest line %d long'
            ' (%r)' % (len(ln), ln[:40]))

# the gap censuses: the opener
# post-state - closed boxes
# (the 3 proficiency items + the
# index), the open count
g = rd(GP)
closed = g.count(chr(10) + '- [x]')
if closed != 4:
    die('the gap closed count %d'
        % closed)
opens = [l for l in g.split(NL)
         if l.startswith('- [ ]')]
if len(opens) != 149:
    die('the gap open count %d'
        % len(opens))

# the seed record
if 'R424 landed 2026-10-13' not in rd(SD):
    die('the seed R424 record')

# the caller contract: no engine
# caller touches the wsg pins
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\bwsg\w', rd(path)):
        die('%s calls the wsg pins'
            ' early' % path)

print('R425 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the WSG arc opener - the')
print('  wilderness proficiency system')
print('  pins (rules/wsgprof.h, prefix')
print('  wsg) with the Table 1 and Table')
print('  2 censuses cross-checked live')
print('  (14 class rows, 25 proficiency')
print('  rows, 5 two-slot, 7 no-check);')
print('  the wsg_gap_report.md opens the')
print('  whole-book inventory - [x]=4,')
print('  opens=149; census 350 -> 351')
print('commit: R425: the WSG arc opener -'
      ' the wilderness proficiencies'
      ' (census 351)')
