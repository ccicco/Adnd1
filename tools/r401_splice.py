#!/usr/bin/env python3
# R401: the UA cantrip tier
# seam - the deferred seam
# closes. The sub-1st registry
# tier (p. 45) pins and the
# R341 roster decode corrects
# from the clean p. 30 table:
#
# 1. rules/cantriptier.h (NEW,
#    the seam layer, prefix
#    cant): the tier traits (0
#    level, the 1" range, the
#    1/10-to-1/2-segment cast
#    band, the living-creature
#    save gate, the
#    concentration block, the
#    faint aura, memorized like
#    spells), the 0-level
#    per-day ladder by xp band
#    (neophyte 1, initiate 2,
#    apprentice 3), the
#    first-level discard and
#    the four-cantrip
#    retention, the round rules
#    (two per round, the d4
#    gap, no spell-and-cantrip
#    round), the category
#    counts (six MU plus the
#    illusionist minor
#    illusion) and the roster
#    totals.
# 2. rules/uaspelltables.h: the
#    clean p. 30 print CORRECTS
#    the R341 decode - the
#    reversed column carries
#    Tangle (row 9, 12 names)
#    and the personal column
#    carries Tweak (row 9, 10
#    names); the roster reads
#    66, not 64.
# 3. regtest.cpp: the two R341
#    name asserts reseat, the
#    roster total flips 64 ->
#    66, the include rides the
#    R392 block, a new R401
#    audit block lands before
#    the R227 anchor; census
#    327 -> 328.
# 4. tools/ua_gap_report.md:
#    the seam checkbox closes;
#    the spell-tables, MU and
#    IL cantrip items take
#    AMENDED R401 notes.
# 5. The seed takes the R400b
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
        'R401 splice ABORT: ' + msg)


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


# ================= (a) the seed =================
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'

SEED_ENTRY = E(
    '- R400b landed 2026-10-13:',
    '  commit c1313e3 (census 327,',
    '  preflight GREEN), the UA',
    '  comeliness site - the first',
    '  deferred seam closes: the',
    '  Character field (the raw 3d6',
    '  base roll, the optional uacom',
    '  save line), the creation roll',
    '  and the two parley-gate',
    '  reaction callers wire the',
    '  R322 and R117 pins. The first',
    '  R400 body failed the Termux',
    '  compile (the game TUs do not',
    '  pull rules/comeliness.h',
    '  transitively) - no commit',
    '  landed, the preflight RED gate',
    '  held, and the fix body rode as',
    '  R400b (the R392 convention,',
    '  user decision): the two',
    '  include patches, the audit',
    '  label stays R400.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R400b landed 2026-10-13' in s:
    already.append('seed: the R400b record')
else:
    if s.count(ANCH) != 1:
        die('the seed anchor count %d'
            % s.count(ANCH))
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R400b record')
s = rd(SD)
if s.count('R400b landed 2026-10-13') != 1:
    die('the R400b seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/cantriptier.h =========
CT = 'rules/cantriptier.h'

CTBODY = E(
    '// ===========================================================================',
    '// Adnd1 - rules/cantriptier.h',
    '// The UA cantrip TIER SEAM (p. 45), R401: the',
    '// sub-1st registry tier - a category of its own',
    '// by standing decision (the R322 deferred-seams',
    '// graph; the gateway charge for the cantrip',
    '// prose rounds).',
    '//',
    '// The clean p. 45 print (the archive.org djvu',
    '// scan): cantrips are the spells learned and',
    '// used by apprentice magic-users and',
    '// illusionists; the 0-level per-day ladder runs',
    '// by xp band; at 1st level the knowledge is',
    '// discarded unless up to four cantrips are',
    '// retained in place of one 1st-level spell;',
    '// cantrips are memorized like spells, read as',
    '// spells and recorded in books and scrolls by',
    '// the spell procedure (the R369/R366 seams).',
    '//',
    '// The cross-checked pins: the R369 acquisition',
    '// bands (rules/uacantacq.h), the R365/R393',
    '// illusionist counts (rules/uailacquisition.h,',
    '// rules/uaspelltables.h), the R341 roster',
    '// (rules/uaspelltables.h, amended R401 - the',
    '// clean p. 30 table prints Tangle in the',
    '// reversed column and Tweak in the personal',
    '// column, both row 9; the roster reads 66',
    '// names, not 64) and the R363 minor-illusion',
    '// descriptions (rules/uailcantrips.h).',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// ---- the tier traits ----',
    '// All cantrips are 0 level, carry a 1-inch',
    '// range, a generally small area of effect,',
    '// soft simple verbal and somatic components,',
    '// and cast in 1/10 to 1/2 segment (pinned as',
    '// tenths: 1 to 5).',
    'inline int cantSpellLevel()',
    '    { return 0; }',
    '',
    'inline int cantRangeInches()',
    '    { return 1; }',
    '',
    'inline int cantCastTimeMinTenths()',
    '    { return 1; }',
    '',
    'inline int cantCastTimeMaxTenths()',
    '    { return 5; }',
    '',
    'inline bool cantSmallAoe()',
    '    { return true; }',
    '',
    'inline bool cantSoftSimpleComponents()',
    '    { return true; }',
    '',
    '// Only the cantrips which involve living',
    '// creatures afford any saving throw.',
    'inline bool cantLivingCreatureCantripsAllowSave()',
    '    { return true; }',
    '',
    '// Individuals in a state of extreme',
    '// concentration (such as when casting a',
    '// spell) do not have that concentration',
    '// broken by person-affecting cantrips.',
    'inline bool cantConcentrationBlocksPersonAffecting()',
    '    { return true; }',
    '',
    '// The effects of cantrips, and the people',
    '// and items affected by them, radiate a very',
    '// faint magical aura.',
    'inline bool cantFaintMagicAura()',
    '    { return true; }',
    '',
    '// Cantrips must be memorized just as',
    '// higher-level spells are.',
    'inline bool cantMemorizedLikeSpells()',
    '    { return true; }',
    '',
    '// ---- the 0-level per-day ladder ----',
    '// A 0-level neophyte (-2000 to -1001 xp)',
    '// casts 1 per day; a 0-level initiate',
    '// (-1000 to -501) casts 2; a 0-level',
    '// apprentice (-500 to -1) casts 3. A leveled',
    '// character reads 0 here - the retention',
    '// rule carries the tier at 1st level.',
    'inline int cantNeophyteXpLo()',
    '    { return -2000; }',
    '',
    'inline int cantNeophyteXpHi()',
    '    { return -1001; }',
    '',
    'inline int cantNeophytePerDay()',
    '    { return 1; }',
    '',
    'inline int cantInitiateXpLo()',
    '    { return -1000; }',
    '',
    'inline int cantInitiateXpHi()',
    '    { return -501; }',
    '',
    'inline int cantInitiatePerDay()',
    '    { return 2; }',
    '',
    'inline int cantApprenticeXpLo()',
    '    { return -500; }',
    '',
    'inline int cantApprenticeXpHi()',
    '    { return -1; }',
    '',
    'inline int cantApprenticePerDay()',
    '    { return 3; }',
    '',
    'inline int cantPerDayByXp(int xp) {',
    '    if (xp <= -1001) return 1;',
    '    if (xp <= -501) return 2;',
    '    if (xp <= -1) return 3;',
    '    return 0;',
    '}',
    '',
    '// ---- the first-level discard and retention ----',
    '// At 1st level the cantrip knowledge is',
    '// discarded in favor of the more powerful',
    '// spells - unless the character retains up',
    '// to four cantrips in place of one',
    '// 1st-level spell (book in hand).',
    'inline bool cantKnowledgeDiscardedAtFirst()',
    '    { return true; }',
    '',
    'inline int cantRetainedMaxInPlaceOfFirst()',
    '    { return 4; }',
    '',
    '// ---- the round rules ----',
    '// Only two cantrips can be cast during any',
    '// round; after the first, a d4 tells how many',
    '// segments later the second may be cast; a',
    '// spell and a cantrip never share a round.',
    'inline int cantPerRoundMax()',
    '    { return 2; }',
    '',
    'inline int cantSecondCastGapDieSides()',
    '    { return 4; }',
    '',
    'inline bool cantNoSpellAndCantripSameRound()',
    '    { return true; }',
    '',
    '// ---- the categories ----',
    '// Six MU categories (useful, reversed,',
    '// legerdemain, person-affecting, personal,',
    '// haunting-sound) plus the seventh, minor',
    '// illusion, available only to illusionists;',
    '// any magic-user or illusionist has the',
    '// potential to know cantrips in all of them.',
    'inline int cantCategoryCount()',
    '    { return 7; }',
    '',
    'inline int cantMuCategoryCount()',
    '    { return 6; }',
    '',
    'inline bool cantAnyCasterMayKnowAllCategories()',
    '    { return true; }',
    '',
    '// ---- the roster totals ----',
    '// The R401-amended R341 decode: 66 MU names',
    '// (the clean p. 30 table prints Tangle,',
    '// reversed row 9, and Tweak, personal row 9),',
    '// the eight minor-illusion cantrips (the',
    '// R363 amended list), 74 in all.',
    'inline int cantMuRosterTotal()',
    '    { return 66; }',
    '',
    'inline int cantIlRosterTotal()',
    '    { return 8; }',
    '',
    'inline int cantRosterTotal()',
    '    { return 74; }',
    '',
    '}   // namespace rules',
    '')

newfile(CT, CTBODY + NL,
        'cantriptier: the seam header')

# ======== (c) rules/uaspelltables.h ========
UST = 'rules/uaspelltables.h'

pair(UST, E(
    '// ---- the magic-user cantrip table (p. 30) ----',
    '// Six categories, 64 names (the Gather/Polish merge decodes to',
    '// two; the Number column is OCR-lost).'),
    E(
    '// ---- the magic-user cantrip table (p. 30) ----',
    '// Six categories, 66 names (the Gather/Polish',
    '// merge decodes to two; the Number column is',
    '// OCR-lost). R401 clean-read fix: the table',
    '// prints Tangle (reversed row 9) and Tweak',
    '// (personal row 9) - the R341 decode read 64,',
    '// missing both.'),
    'uaspelltables: the table header')

pair(UST, E(
    '// The name count per category (20, 11, 6, 10, 9, 8).',
    'inline int uastCantripCount(int cat) {',
    '    static const int k[6] = { 20, 11, 6, 10, 9, 8 };'),
    E(
    '// The name count per category (20, 12, 6,',
    '// 10, 10, 8 - the R401 clean-read fix adds',
    '// Tangle and Tweak).',
    'inline int uastCantripCount(int cat) {',
    '    static const int k[6] = { 20, 12, 6, 10, 10, 8 };'),
    'uaspelltables: the counts')

pair(UST, E(
    '        { "Curdle", "Dirty", "Dusty", "Hairy", "Knot",',
    '          "Ravel", "Sour", "Spill", "Tarnish", "Untie",',
    '          "Wilt", "", "", "", "", "", "", "", "", "" },'),
    E(
    '        { "Curdle", "Dirty", "Dusty", "Hairy", "Knot",',
    '          "Ravel", "Sour", "Spill", "Tangle", "Tarnish",',
    '          "Untie", "Wilt", "", "", "", "", "", "", "",',
    '          "" },'),
    'uaspelltables: the reversed row')

pair(UST, E(
    '        { "Bee", "Bluelight", "Bug", "Firefinger", "Gnats",',
    '          "Mouse", "Smokepuff", "Spider", "Unlock", "",',
    '          "", "", "", "", "", "", "", "", "", "" },'),
    E(
    '        { "Bee", "Bluelight", "Bug", "Firefinger", "Gnats",',
    '          "Mouse", "Smokepuff", "Spider", "Tweak",',
    '          "Unlock", "", "", "", "", "", "", "", "", "",',
    '          "" },'),
    'uaspelltables: the personal row')

# ============ (d) regtest.cpp ============
RT = 'regtest.cpp'

pair(RT, E(
    '#include "rules/uahandheld.h"  // R392: the UA hand-held data'),
    E(
    '#include "rules/uahandheld.h"  // R392: the UA hand-held data',
    '#include "rules/cantriptier.h"  // R401: the UA cantrip tier'),
    'regtest: the include')

pair(RT, E(
    '            int total = 0;',
    '            for (int c = 0; c < 6; ++c)',
    '                total += uastCantripCount(c);',
    '            if (total != 64) ++bad;'),
    E(
    '            int total = 0;',
    '            for (int c = 0; c < 6; ++c)',
    '                total += uastCantripCount(c);',
    '            // R401 clean-read fix: Tangle and',
    '            // Tweak print on p. 30 - the roster',
    '            // reads 66, not 64',
    '            if (total != 66) ++bad;'),
    'regtest: the R341 roster total')

pair(RT, E(
    '            if (strcmp(uastCantripName(1, 10),',
    '                "Wilt") != 0) ++bad;'),
    E(
    '            // R401: Tangle seats at reversed',
    '            // row 9; Wilt moves to 11',
    '            if (strcmp(uastCantripName(1, 8),',
    '                "Tangle") != 0) ++bad;',
    '            if (strcmp(uastCantripName(1, 11),',
    '                "Wilt") != 0) ++bad;'),
    'regtest: the Wilt reseat')

pair(RT, E(
    '            // the Unlock print in the Personal column',
    '            if (strcmp(uastCantripName(4, 8),',
    '                "Unlock") != 0) ++bad;'),
    E(
    '            // R401: Tweak seats at personal',
    '            // row 9; Unlock moves to 9',
    '            if (strcmp(uastCantripName(4, 8),',
    '                "Tweak") != 0) ++bad;',
    '            if (strcmp(uastCantripName(4, 9),',
    '                "Unlock") != 0) ++bad;'),
    'regtest: the Unlock reseat')

AUD = E(
    '    // ---- R401: the UA cantrip tier',
    '    // seam audit ----',
    '    // The sub-1st registry tier closes the',
    '    // deferred seam: the p. 45 tier traits,',
    '    // the 0-level per-day ladder, the',
    '    // first-level retention, the round',
    '    // rules and the roster; the R341',
    '    // decode amendments cross-check here.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // the tier traits',
    '        if (cantSpellLevel() != 0) ++bad;',
    '        if (cantRangeInches() != 1) ++bad;',
    '        if (cantCastTimeMinTenths() != 1)',
    '            ++bad;',
    '        if (cantCastTimeMaxTenths() != 5)',
    '            ++bad;',
    '        if (!cantSmallAoe()) ++bad;',
    '        if (!cantSoftSimpleComponents())',
    '            ++bad;',
    '        if (!cantLivingCreature'
    'CantripsAllowSave()) ++bad;',
    '        if (!cantConcentrationBlocks'
    'PersonAffecting()) ++bad;',
    '        if (!cantFaintMagicAura()) ++bad;',
    '        if (!cantMemorizedLikeSpells())',
    '            ++bad;',
    '        // the per-day ladder: the band',
    '        // edges',
    '        if (cantPerDayByXp(-2000) != 1)',
    '            ++bad;',
    '        if (cantPerDayByXp(-1001) != 1)',
    '            ++bad;',
    '        if (cantPerDayByXp(-1000) != 2)',
    '            ++bad;',
    '        if (cantPerDayByXp(-501) != 2)',
    '            ++bad;',
    '        if (cantPerDayByXp(-500) != 3)',
    '            ++bad;',
    '        if (cantPerDayByXp(-1) != 3)',
    '            ++bad;',
    '        if (cantPerDayByXp(0) != 0) ++bad;',
    '        if (cantPerDayByXp(500) != 0)',
    '            ++bad;',
    '        if (cantPerDayByXp(-2001) != 1)',
    '            ++bad;',
    '        // the ladder agrees with its bands',
    '        if (cantNeophytePerDay()',
    '                != cantPerDayByXp(',
    '                      cantNeophyteXpHi()))',
    '            ++bad;',
    '        if (cantInitiatePerDay()',
    '                != cantPerDayByXp('
    '                      cantInitiateXpHi()))',
    '            ++bad;',
    '        if (cantApprenticePerDay()',
    '                != cantPerDayByXp('
    '                      cantApprenticeXpHi()))',
    '            ++bad;',
    '        // the bands tile contiguously',
    '        if (cantInitiateXpLo()',
    '                != cantNeophyteXpHi() + 1)',
    '            ++bad;',
    '        if (cantApprenticeXpLo()',
    '                != cantInitiateXpHi() + 1)',
    '            ++bad;',
    '        // the per-day ladder climbs',
    '        if (cantNeophytePerDay() + 1',
    '                != cantInitiatePerDay())',
    '            ++bad;',
    '        if (cantInitiatePerDay() + 1',
    '                != cantApprenticePerDay())',
    '            ++bad;',
    '        // the first-level retention',
    '        if (!cantKnowledgeDiscarded'
    'AtFirst()) ++bad;',
    '        if (cantRetainedMaxInPlaceOfFirst()',
    '            != 4) ++bad;',
    '        // the round rules',
    '        if (cantPerRoundMax() != 2) ++bad;',
    '        if (cantSecondCastGapDieSides()',
    '            != 4) ++bad;',
    '        if (!cantNoSpellAndCantrip'
    'SameRound()) ++bad;',
    '        // the categories',
    '        if (cantCategoryCount() != 7)',
    '            ++bad;',
    '        if (cantMuCategoryCount() != 6)',
    '            ++bad;',
    '        if (cantCategoryCount()',
    '                != cantMuCategoryCount() + 1)',
    '            ++bad;',
    '        if (!cantAnyCasterMayKnowAll'
    'Categories()) ++bad;',
    '        // the roster (the R401-amended',
    '        // R341 decode)',
    '        if (cantMuRosterTotal() != 66)',
    '            ++bad;',
    '        if (cantIlRosterTotal() != 8)',
    '            ++bad;',
    '        if (cantRosterTotal()',
    '                != cantMuRosterTotal()',
    '                   + cantIlRosterTotal())',
    '            ++bad;',
    '        {',
    '            int total = 0;',
    '            for (int c = 0; c < 6; ++c)',
    '                total += uastCantripCount(c);',
    '            if (total != cantMuRosterTotal())',
    '                ++bad;',
    '        }',
    '        // the R341 seam agreement: the',
    '        // category counts and the',
    '        // amended name seats',
    '        if (uastCantripCount(1) != 12)',
    '            ++bad;',
    '        if (uastCantripCount(4) != 10)',
    '            ++bad;',
    '        if (strcmp(uastCantripName(1, 8),',
    '            "Tangle") != 0) ++bad;',
    '        if (strcmp(uastCantripName(4, 8),',
    '            "Tweak") != 0) ++bad;',
    '        if (uastCantripName(1, 12)[0] != 0)',
    '            ++bad;',
    '        if (uastCantripName(4, 10)[0] != 0)',
    '            ++bad;',
    '        // the R369/R365 acquisition seams',
    '        if (uacaqCategoryCount()',
    '                != cantMuCategoryCount())',
    '            ++bad;',
    '        if (uacaqMaxDevelopedCantrips()',
    '                != uastMuCantripMaxNewCount())',
    '            ++bad;',
    '        if (uastIlMinorIllusionMin()',
    '                > uastIlMinorIllusionMax())',
    '            ++bad;',
    '        if (uastIlMinorIllusionMax()',
    '                > cantIlRosterTotal()) ++bad;',
    '        // the R366 book seam',
    '        if (!uabkCantripsCountAsFirstLevel())',
    '            ++bad;',
    '        // the R363 minor-illusion roster',
    '        if (strcmp(uailcLightsName(),',
    '            "Colored Lights (Alteration)") != 0)',
    '            ++bad;',
    '        if (strcmp(uailcDimName(),',
    '            "Dim (Alteration)") != 0) ++bad;',
    '        if (strcmp(uailcHazeName(),',
    '            "Haze (Alteration)") != 0) ++bad;',
    '        if (strcmp(uailcMaskName(),',
    '            "Mask (Illusion)") != 0) ++bad;',
    '        if (strcmp(uailcMirageName(),',
    '            "Mirage") != 0) ++bad;',
    '        if (strcmp(uailcNoiseName(),',
    '            "Noise (Illusion)") != 0) ++bad;',
    '        if (strcmp(uailcRainbowName(),',
    '            "Rainbow (Alteration)") != 0)',
    '            ++bad;',
    '        if (strcmp(uailcTwodName(),',
    '            "Two-D' + chr(39) + 'lusion") != 0)',
    '            ++bad;',
    '        printf("R401 UA cantrip tier seam audit: bad %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R401 audit block')

# ======== (e) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '- [ ] The cantrip tier seam - a',
    '      sub-1st registry tier; gates the',
    '      cantrip category.'),
    E(
    '- [x] The cantrip tier seam -',
    '      CLOSED R401 (rules/cantriptier.h;',
    '      the R401 seam audit, census 328):',
    '      the p. 45 tier traits, the 0-level',
    '      per-day ladder by xp band, the',
    '      first-level discard and the',
    '      four-cantrip retention, the round',
    '      rules, the seven categories and',
    '      the roster totals. The clean p. 30',
    '      read amends the R341 decode',
    '      (Tangle, Tweak; 66 names). The',
    '      cantrip prose items are ungated',
    '      now - open on their own prose.',
    '      The MU/IL cantrip DESCRIPTIONS',
    '      remain the open dependents.'),
    'gap: the seam checkbox')

pair(GP, E(
    '      - R341: the readable tables',
    '        pinned (rules/uaspelltables.h)',
    '        - the cleric 1st-3rd table',
    '        (20 rows, seam-verified against',
    '        the R80 registry), the cleric',
    '        4th-7th fragments, the druid',
    '        tables (the four readable rows',
    '        seam-decoded as the 1st-level',
    '        roster, the Insect P| fragment',
    '        seam-decoded as Insect Plague)',
    '        and the MU cantrip table (64',
    '        names, the Gather/Polish merge',
    '        decoded); the MU spells tables',
    '        and the illusionist spell table',
    '        are OCR-scrambled - stays open',
    '        pending the PDF read.'),
    E(
    '      - R341: the readable tables',
    '        pinned (rules/uaspelltables.h)',
    '        - the cleric 1st-3rd table',
    '        (20 rows, seam-verified against',
    '        the R80 registry), the cleric',
    '        4th-7th fragments, the druid',
    '        tables (the four readable rows',
    '        seam-decoded as the 1st-level',
    '        roster, the Insect P| fragment',
    '        seam-decoded as Insect Plague)',
    '        and the MU cantrip table (64',
    '        names, the Gather/Polish merge',
    '        decoded); the MU spells tables',
    '        and the illusionist spell table',
    '        are OCR-scrambled - stays open',
    '        pending the PDF read.',
    '      - AMENDED R401: the clean p. 30',
    '        read corrects the cantrip',
    '        roster - the reversed column',
    '        prints Tangle (row 9, 12 names)',
    '        and the personal column prints',
    '        Tweak (row 9, 10 names); the',
    '        roster reads 66 names; the',
    '        R341 audit asserts reseat.'),
    'gap: the R341 amendment')

pair(GP, E(
    '        stays open on the cantrip',
    '        tier seam (the registry',
    '        charge), the descriptions',
    '        are pinned.'),
    E(
    '        stays open on the cantrip',
    '        tier seam (the registry',
    '        charge), the descriptions',
    '        are pinned.',
    '      - AMENDED R401: the cantrip',
    '        tier seam CLOSED',
    '        (rules/cantriptier.h) - the',
    '        tier gate drops; the box',
    '        stays open only on the',
    '        casting-time fraction holes',
    '        pending the PDF read.'),
    'gap: the IL amendment')

pair(GP, E(
    '      - six categories: useful (20',
    '      named: chill, clean, color,'),
    E(
    '      - AMENDED R401: the tier seam',
    '      closed (rules/cantriptier.h);',
    '      the clean p. 30 read confirms',
    '      the roster (Tangle reversed row',
    '      9, Tweak personal row 9, 66',
    '      names) - the item stays open',
    '      on the pp. 45-52 descriptions,',
    '      ungated.',
    '      - six categories: useful (20',
    '      named: chill, clean, color,'),
    'gap: the MU amendment')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 328:
    die('the census %d' % s.count('audit: bad'))
if s.count('R401 UA cantrip tier'
           ' seam audit') != 1:
    die('the R401 audit label')
if s.count('cantPerDayByXp') != 12:
    die('the ladder count %d'
        % s.count('cantPerDayByXp'))
if s.count('uastCantripName(1, 10)') != 0:
    die('the old Wilt seat remains')
if s.count('Tangle') != 4:
    die('the Tangle count %d'
        % s.count('Tangle'))
if s.count('Tweak') != 4:
    die('the Tweak count %d'
        % s.count('Tweak'))

p = rd(CT)
if p.count('inline') != 31:
    die('the cantriptier inline count %d'
        % p.count('inline'))
if not p.endswith(NL):
    die('the cantriptier trailing newline')

u = rd(UST)
if u.count('inline') != 44:
    die('the uaspelltables inline count %d'
        % u.count('inline'))
if u.count('Tangle') != 3:
    die('the uaspelltables Tangle count %d'
        % u.count('Tangle'))
if u.count('Tweak') != 3:
    die('the uaspelltables Tweak count %d'
        % u.count('Tweak'))

g = rd(GP)
if g.count('AMENDED R401') != 3:
    die('the gap amended count %d'
        % g.count('AMENDED R401'))
if g.count('CLOSED R401') != 1:
    die('the gap closed count %d'
        % g.count('CLOSED R401'))

for path, mark in ((UST, 'Tangle'),
                   (CT, 'cantSpellLevel'),
                   (SD, 'R400b landed')):
    if mark not in rd(path):
        die('%s carries no R401 seam' % path)

print('R401 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the cantrip tier seam closes - the')
print('  p. 45 tier pins land, the R341 roster')
print('  corrects to 66 names (Tangle, Tweak);')
print('  census 327 -> 328')
print('commit: R401: the UA cantrip tier seam'
      ' (census 328)')

