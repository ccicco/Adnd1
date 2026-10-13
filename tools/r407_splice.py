#!/usr/bin/env python3
# R407: the UA Appendix S
# clerical quick-reference
# charts (pp. 121-122) - the
# second data round riding
# the R405 seam. The R406
# stat-block precedent: the
# scan-clean cells pin; the
# pantheon prose stays open.
#
# 1. rules/uascharts.h (NEW,
#    prefix usc, 11 inline
#    functions): the five
#    8-column charts - 23
#    rows (the printed short
#    deity name, the SPHERE
#    OF CONTROL, the RAIMENT
#    head and body, the
#    color(s), the HOLY DAYS,
#    and the SACRIFICE/
#    PROPITIATION frequency
#    and form); the sacred-
#    animal table (13 named -
#    Aerdrie any bird, Solonor
#    stag, the four halfling
#    beasts, Baervan raccoon,
#    Urdlen white mole, Segojan
#    badger, Bahgtru ox,
#    Shargaas bat, Yurtrus
#    skeleton, Luthic cave
#    bear; null = none, the
#    five dwarves + Flandal +
#    Ilneval); the cleric
#    gender reads (the dwarven
#    split, the elf/halfling
#    either-gender, the
#    all-male never-druid
#    gnomish clerics); the
#    frequency drift catches
#    (monthly 10, annually 4).
# 2. regtest.cpp: the
#    include rides the R406
#    include, the R407 audit
#    block lands before the
#    R227 anchor - the row
#    count and chart count
#    cross-check the R405 seam
#    live, the spot checks pin
#    Clanggedin, Berronar,
#    Sheela, Brandobaris,
#    Flandal, Bahgtru and
#    Luthic, and the sacred
#    animals pin all 13 named
#    + the dwarven no-animal
#    read; census 333 -> 334.
# 3. tools/ua_gap_report.md:
#    the Clerical Quick
#    Reference Chart item
#    CLOSES R407; the Appendix
#    S box takes AMENDED R407
#    (stays open on the class
#    lines, MOVE, stat lines
#    and the pantheon prose);
#    the DEFERRED block takes
#    the second amendment.
# 4. The seed takes the R406
#    record.
import io
import os

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
        'R407 splice ABORT: ' + msg)


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


# ========= (a) the seed record =========
SD = 'doc/vibe/' \
     'adnd1_knowledge_seed_v2.md'

SEED_ENTRY = E(
    '- R406 landed 2026-10-13:',
    '  commit 0ae5310 (census 333,',
    '  preflight GREEN), the UA',
    '  Appendix S stat blocks -',
    '  the first ungated data round',
    '  riding the R405 seam;',
    '  rules/uaappends.h (prefix uas)',
    '  - the 23 blocks pin the',
    '  scan-clean numerics, the',
    '  tier/rating censuses live',
    '  against the seam, the 6985',
    '  HP drift catch, the scan',
    '  holes as sentinels. The',
    '  class lines, MOVE, stat',
    '  lines, prose and the',
    '  charts stay open. The',
    '  ./nn save hash diverged',
    '  for the fourteenth round',
    '  running - benign; the md5',
    '  stays advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R406 landed 2026-10-13' in s:
    already.append('seed: the R406 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R406 record')
s = rd(SD)
if s.count('R406 landed 2026-10-13') != 1:
    die('the R406 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uascharts.h =========
CH = 'rules/uascharts.h'

CHBODY = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uascharts.h',
    '// The UA APPENDIX S clerical',
    '// quick-reference charts, R407:',
    '// the five charts (pp. 121-122)',
    '// - the second data round riding',
    '// the R405 deity layer seam. The',
    '// R406 stat-block precedent: the',
    '// scan-clean cells pin; the',
    '// pantheon prose stays open.',
    '//',
    '// Each chart prints one row per',
    '// deity, 8 columns: DEITY, the',
    '// SPHERE OF CONTROL, the RAIMENT',
    '// head and body, the color(s),',
    '// the HOLY DAYS, and the',
    '// SACRIFICE/PROPITIATION',
    '// frequency and form.',
    '//',
    '// The pantheon order rides the',
    '// R406 stat table (dwarves 0-4,',
    '// elves 5-9, halflings 10-13,',
    '// gnomes 14-17, orcs 18-22).',
    '//',
    '// The sacred-animal table: 13',
    '// named (Aerdrie any bird,',
    '// Solonor stag; the halfling',
    '// four; Baervan raccoon, Urdlen',
    '// white mole, Segojan badger;',
    '// Bahgtru ox, Shargaas bat,',
    '// Yurtrus skeleton, Luthic cave',
    '// bear); null = none (the five',
    '// dwarves - the print says NO',
    '// dwarven god has a sacred',
    '// animal - plus Flandal and',
    '// Ilneval).',
    '//',
    '// The cleric gender reads: the',
    '// dwarven split (males of the',
    '// male deities, females of the',
    '// female ones), the elf and',
    '// halfling either-gender, the',
    '// all-male never-druid gnomish',
    '// clerics.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'struct UscChartRow {',
    '    const char* name;',
    '    const char* sphere;',
    '    const char* head;',
    '    const char* body;',
    '    const char* color;',
    '    const char* days;',
    '    const char* freq;',
    '    const char* form;',
    '};',
    '',
    '// A tiny string equality (no library',
    '// includes in the header).',
    'inline bool uscStrEq(const char* a,',
    '                     const char* b) {',
    '    int i = 0;',
    '    while (a[i] != 0 && b[i] != 0) {',
    '        if (a[i] != b[i]) return false;',
    '        ++i;',
    '    }',
    '    return a[i] == b[i];',
    '}',
    '',
    '// The five charts, 23 rows in the',
    '// pantheon order of the R406 stat',
    '// table.',
    'inline const UscChartRow& uscChartRow(',
    '        int i) {',
    '    static const UscChartRow T[23] = {',
    '        // ---- the dwarves ----',
    '        { "Clanggedin", "war, battle",',
    '          "war helm", "chain mail",',
    '          "silver", "before battle",',
    '          "before battle", "weapons" },',
    '        { "Vergadain", "suspicion, trickery",',
    '          "helmet", "chain mail",',
    '          "gold", "full moon",',
    '          "monthly", "gold" },',
    '        { "Dumathoin", "secrets, earth",',
    '          "bare", "leather",',
    '          "brown", "new moon",',
    '          "monthly", "gems & jewels" },',
    '        { "Abbathor", "evil, greed",',
    '          "leather cap", "leather",',
    '          "red", "solar eclipses",',
    '          "annually", "blood & gems" },',
    '        { "Berronar", "safety, truth",',
    '          "silvered helm", "chain mail",',
    '          "silver", "new year\'s day",',
    '          "annually", "silver" },',
    '        // ---- the elves ----',
    '        { "Aerdrie", "air, weather, birds",',
    '          "one feather", "sky-blue robes",',
    '          "sky blue",',
    '          "spring & fall equinoxes",',
    '          "semi-annual",',
    '          "beautiful feathers" },',
    '        { "Erevan",',
    '          "mischief, change, thieves",',
    '          "leather cap", "leather armor",',
    '          "black", "eclipses",',
    '          "varies", "stolen treasures" },',
    '        { "Solonor", "archery, hunting",',
    '          "green hood",',
    '          "elfin chain & silver",',
    '          "leaf green", "full moon",',
    '          "monthly", "hunting trophies" },',
    '        { "Hanali", "romance, beauty",',
    '          "bare", "gold robes",',
    '          "gold", "full moon",',
    '          "monthly", "beautiful objects" },',
    '        { "Labelas", "longevity, time",',
    '          "bare", "gray robes",',
    '          "light gray", "sunset",',
    '          "daily", "prayers & knowledge" },',
    '        // ---- the halflings ----',
    '        { "Sheela",',
    '          "agriculture, weather",',
    '          "bare", "green robes",',
    '          "green", "full moon",',
    '          "monthly", "seeds" },',
    '        { "Arvoreen", "defense, warriors",',
    '          "helmet", "chainmail",',
    '          "silver", "before battle",',
    '          "varies", "silvered weapons" },',
    '        { "Cyrrollalee",',
    '          "trust, protection",',
    '          "bare", "brown robes",',
    '          "brown", "first day of month",',
    '          "monthly", "prayers" },',
    '        { "Brandobaris", "thieves",',
    '          "feathered cap",',
    '          "leather armor",',
    '          "gray", "new moon",',
    '          "monthly", "stolen items" },',
    '        // ---- the gnomes ----',
    '        { "Baervan",',
    '          "adventure, thieves",',
    '          "green cap", "brown clothes",',
    '          "wood brown", "full moon",',
    '          "monthly", "treasure items" },',
    '        { "Urdlen", "evil",',
    '          "bare", "white cloak",',
    '          "white", "winter solstice",',
    '          "annually", "blood & jewels" },',
    '        { "Segojan", "earth, nature",',
    '          "fur cap", "leather armor",',
    '          "gray & dark brown",',
    '          "first day of each season",',
    '          "quarterly", "gemstones" },',
    '        { "Flandal", "metalworking",',
    '          "steel helm", "leather armor",',
    '          "red", "midsummer\'s day",',
    '          "annually", "forged weapons" },',
    '        // ---- the orcs ----',
    '        { "Bahgtru", "strength",',
    '          "bare", "loincloth",',
    '          "n/a", "battle days",',
    '          "before battle",',
    '          "bones of enemies" },',
    '        { "Shargaas", "night, thieves",',
    '          "leather cap", "leather armor",',
    '          "red & black", "new moon",',
    '          "monthly", "stolen items" },',
    '        { "Ilneval", "warriors",',
    '          "red metal helmet",',
    '          "red metal armor",',
    '          "red", "battle days",',
    '          "before & after battle",',
    '          "blood & weapons" },',
    '        { "Yurtrus", "death, plague",',
    '          "bare", "skins",',
    '          "white", "full moon",',
    '          "monthly", "sacrifices" },',
    '        { "Luthic",',
    '          "caves, healing, females",',
    '          "fur cap", "leather armor",',
    '          "brown & black",',
    '          "midwinter\'s day",',
    '          "yearly", "treasures" },',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 22) i = 22;',
    '    return T[i];',
    '}',
    '',
    '// The sacred animals, by the same',
    '// deity index; null = none.',
    'inline const char* uscSacredAnimal(',
    '        int i) {',
    '    static const char* const A[23] = {',
    '        0, 0, 0, 0, 0,',
    '        "any bird", 0, "stag", 0, 0,',
    '        "butterfly", "war dog",',
    '        "squirrel", "mouse",',
    '        "raccoon", "white mole",',
    '        "badger", 0,',
    '        "ox", "bat", 0,',
    '        "skeleton", "cave bear"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 22) i = 22;',
    '    return A[i];',
    '}',
    '',
    'inline int uscChartRowCount()',
    '    { return 23; }',
    '',
    'inline int uscChartCount()',
    '    { return 5; }',
    '',
    '// The named sacred animals (the',
    '// non-null cells): 13.',
    'inline int uscNamedSacredAnimalCount()',
    '    {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        if (uscSacredAnimal(i) != 0) ++n;',
    '    return n;',
    '}',
    '',
    '// The frequency drift catches:',
    '// 10 rows print monthly, 4 print',
    '// annually, 2 print before battle.',
    'inline int uscFrequencyCount(',
    '        const char* freq) {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        if (uscStrEq(uscChartRow(i).freq,',
    '                     freq)) ++n;',
    '    return n;',
    '}',
    '',
    '// The cleric gender reads.',
    '// The dwarven split: only male',
    '// dwarves may become clerics of',
    '// the male deities, females of',
    '// the female ones.',
    'inline bool uscDwarfClericGenderSplit()',
    '    { return true; }',
    '',
    'inline bool uscElfClericsEitherGender()',
    '    { return true; }',
    '',
    'inline bool',
    '        uscHalflingClericsEitherGender()',
    '    { return true; }',
    '',
    '// Gnomish clerics are never druids',
    '// and are all males.',
    'inline bool uscGnomeClericsNeverDruids()',
    '    { return true; }',
    '',
    'inline bool uscGnomishClericsAllMale()',
    '    { return true; }',
    '',
    '}   // namespace rules',
    '')
newfile(CH, CHBODY + NL,
        'the clerical charts header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uaappends.h"  '
     '// R406: the UA Appendix S'
     ' stat blocks',
     E(
    '#include "rules/uaappends.h"  '
    '// R406: the UA Appendix S'
    ' stat blocks',
    '#include "rules/uascharts.h"  '
    '// R407: the UA Appendix S'
    ' clerical charts'),
     'regtest: the charts include')

AUD = E(
    '    // ---- R407: the UA Appendix S',
    '    // clerical charts pin audit ----',
    '    // The second data round rides',
    '    // the R405 seam: the five',
    '    // 8-column charts pin their 23',
    '    // rows (sphere, raiment, colors,',
    '    // holy days, the sacrifice',
    '    // frequency and form), the 13',
    '    // named sacred animals pin, the',
    '    // cleric gender reads pin, and',
    '    // the frequency counts (monthly',
    '    // 10, annually 4, before battle',
    '    // 2) catch any cell drift; the',
    '    // pantheon prose stays open;',
    '    // census 333 -> 334.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (uscChartRowCount() != 23) ++bad;',
    '        if (uscChartRowCount()',
    '                != uasDeityCount()) ++bad;',
    '        if (uscChartCount() != 5)',
    '            ++bad;',
    '        if (uscChartCount()',
    '                != nhdChartCount()) ++bad;',
    '        // ---- the spot checks ----',
    '        // Clanggedin (the first row)',
    '        if (strcmp(uscChartRow(0).name,',
    '                   "Clanggedin") != 0)',
    '            ++bad;',
    '        if (strcmp(uscChartRow(0).sphere,',
    '                   "war, battle") != 0)',
    '            ++bad;',
    '        if (strcmp(uscChartRow(0).head,',
    '                   "war helm") != 0) ++bad;',
    '        if (strcmp(uscChartRow(0).form,',
    '                   "weapons") != 0) ++bad;',
    '        // Berronar: the new-year day',
    '        if (strcmp(uscChartRow(4).days,',
    '                   "new year\'s day") != 0)',
    '            ++bad;',
    '        // Aerdrie: the equinoxes',
    '        if (strcmp(uscChartRow(5).days,',
    '                   "spring & fall equinoxes")',
    '                != 0)',
    '            ++bad;',
    '        // Solonor: the elfin chain',
    '        if (strcmp(uscChartRow(7).body,',
    '                   "elfin chain & silver")',
    '                != 0)',
    '            ++bad;',
    '        // Sheela: the seeds',
    '        if (strcmp(uscChartRow(10).form,',
    '                   "seeds") != 0) ++bad;',
    '        // Brandobaris: the stolen items',
    '        if (strcmp(uscChartRow(13).form,',
    '                   "stolen items") != 0) ++bad;',
    '        // Segojan: the season days',
    '        if (strcmp(uscChartRow(16).days,',
    '                   "first day of each season")',
    '                != 0)',
    '            ++bad;',
    '        if (strcmp(uscChartRow(16).freq,',
    '                   "quarterly") != 0) ++bad;',
    '        // Flandal: the forged weapons',
    '        if (strcmp(uscChartRow(17).form,',
    '                   "forged weapons") != 0)',
    '            ++bad;',
    '        // Bahgtru: the n/a color',
    '        if (strcmp(uscChartRow(18).color,',
    '                   "n/a") != 0) ++bad;',
    '        if (strcmp(uscChartRow(18).form,',
    '                   "bones of enemies") != 0)',
    '            ++bad;',
    '        // Ilneval: the two-sided days',
    '        if (strcmp(uscChartRow(20).freq,',
    '                   "before & after battle")',
    '                != 0)',
    '            ++bad;',
    '        // Luthic: the cave goddess',
    '        if (strcmp(uscChartRow(22).sphere,',
    '                   "caves, healing, females")',
    '                != 0)',
    '            ++bad;',
    '        if (strcmp(uscChartRow(22).freq,',
    '                   "yearly") != 0) ++bad;',
    '        if (strcmp(uscChartRow(22).form,',
    '                   "treasures") != 0) ++bad;',
    '        // ---- the sacred animals ----',
    '        if (uscNamedSacredAnimalCount()',
    '                != 13) ++bad;',
    '        // the dwarven no-animal read:',
    '        // all five null',
    '        if (uscSacredAnimal(0) != 0',
    '                || uscSacredAnimal(1) != 0',
    '                || uscSacredAnimal(2) != 0',
    '                || uscSacredAnimal(3) != 0',
    '                || uscSacredAnimal(4) != 0)',
    '            ++bad;',
    '        if (strcmp(uscSacredAnimal(5),',
    '                   "any bird") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(7),',
    '                   "stag") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(10),',
    '                   "butterfly") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(11),',
    '                   "war dog") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(12),',
    '                   "squirrel") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(13),',
    '                   "mouse") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(14),',
    '                   "raccoon") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(15),',
    '                   "white mole") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(16),',
    '                   "badger") != 0) ++bad;',
    '        if (uscSacredAnimal(17) != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(18),',
    '                   "ox") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(19),',
    '                   "bat") != 0) ++bad;',
    '        if (uscSacredAnimal(20) != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(21),',
    '                   "skeleton") != 0) ++bad;',
    '        if (strcmp(uscSacredAnimal(22),',
    '                   "cave bear") != 0) ++bad;',
    '        // ---- the cleric gender reads ----',
    '        if (!uscDwarfClericGenderSplit()) ++bad;',
    '        if (!uscElfClericsEitherGender()) ++bad;',
    '        if (!uscHalflingClericsEitherGender())',
    '            ++bad;',
    '        if (!uscGnomeClericsNeverDruids()) ++bad;',
    '        if (!uscGnomishClericsAllMale()) ++bad;',
    '        // ---- the frequency drift catch ----',
    '        if (uscFrequencyCount("monthly") != 10)',
    '            ++bad;',
    '        if (uscFrequencyCount("annually") != 4)',
    '            ++bad;',
    '        if (uscFrequencyCount(',
    '                "before battle") != 2) ++bad;',
    '        if (uscFrequencyCount("quarterly")',
    '                != 1)',
    '            ++bad;',
    '        printf("R407 UA appendix S clerical'
    ' charts pin audit: bad %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R407 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '- [ ] Clerical Quick Reference Chart,',
    '      non-human deities (pp. 121-122) -',
    '      rides the Appendix S OUT.'),
    E(
    '- [x] Clerical Quick Reference Chart,',
    '      non-human deities (pp. 121-122) -',
    '      CLOSED R407 (rules/uascharts.h;',
    '      the R407 charts pin audit, census',
    '      334): the five 8-column charts pin',
    '      all 23 rows (sphere, raiment,',
    '      colors, holy days, the sacrifice',
    '      frequency and form), the 13 named',
    '      sacred animals pin against the',
    '      seven none-cells, the cleric',
    '      gender reads pin (the dwarven',
    '      split, the elf/halfling',
    '      either-gender, the all-male',
    '      never-druid gnomish clerics), and',
    '      the frequency counts (monthly 10,',
    '      annually 4, before battle 2)',
    '      catch cell drift - live against',
    '      the R405 seam chart pins.'),
    'gap: the chart item closes')

pair(GP, E(
    '        S/I/W/D/C/CH/CM stat lines,',
    '        the pantheon prose, and the',
    '        clerical quick-reference',
    '        charts (pp. 121-122).'),
    E(
    '        S/I/W/D/C/CH/CM stat lines,',
    '        the pantheon prose, and the',
    '        clerical quick-reference',
    '        charts (pp. 121-122).',
    '      - AMENDED R407: the clerical',
    '        charts land (rules/uascharts.h)',
    '        - CLOSED as their own item; the',
    '        Appendix S box stays open on',
    '        the class lines, MOVE, the stat',
    '        lines and the pantheon prose.'),
    'gap: the Appendix S amendment')

pair(GP, E(
    '  - AMENDED R406: the stat block',
    '    numerics land (rules/uaappends.h)',
    '    - the class lines, MOVE, stat',
    '    lines, prose and the charts stay',
    '    open.'),
    E(
    '  - AMENDED R406: the stat block',
    '    numerics land (rules/uaappends.h)',
    '    - the class lines, MOVE, stat',
    '    lines, prose and the charts stay',
    '    open.',
    '  - AMENDED R407: the charts land',
    '    (rules/uascharts.h) - the class',
    '    lines, MOVE, stat lines and the',
    '    prose stay open.'),
    'gap: the DEFERRED amendment')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 334:
    die('the census %d' % s.count('audit: bad'))
if s.count('R407 UA appendix S clerical'
           ' charts pin audit') != 1:
    die('the R407 audit label')
if s.count('uscChartRow(') < 15:
    die('the chart call count %d'
        % s.count('uscChartRow('))
if s.count('uscSacredAnimal(') < 20:
    die('the animal call count %d'
        % s.count('uscSacredAnimal('))

p = rd(CH)
if p.count('inline') != 12:
    die('the charts inline count %d'
        % p.count('inline'))
if p.count('{ "') != 23:
    die('the chart row count %d'
        % p.count('{ "'))
if not p.endswith(NL):
    die('the charts trailing newline')

g = rd(GP)
if g.count('AMENDED R407') != 2:
    die('the gap amended count %d'
        % g.count('AMENDED R407'))
if g.count('CLOSED R407') != 1:
    die('the gap closed count %d'
        % g.count('CLOSED R407'))

for path, mark in ((CH, 'Clanggedin'),
                   (RT, 'uscChartRowCount'),
                   (SD, 'R406 landed')):
    if mark not in rd(path):
        die('%s carries no R407 round' % path)

# the contract: no engine caller
import re as _re
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\\busc', rd(path)):
        die('%s calls the pins early'
            % path)

print('R407 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the clerical charts pin -')
print('  five charts, 23 rows, the 13')
print('  sacred animals; the class lines,')
print('  MOVE, stat lines and prose stay')
print('  open; census 333 -> 334')
print('commit: R407: the UA Appendix S'
      ' clerical charts (census 334)')

