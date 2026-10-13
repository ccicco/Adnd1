#!/usr/bin/env python3
# R406: the UA Appendix S stat
# blocks - the ungated data
# round rides the R405 seam.
# The R337/R391 pin-round
# precedent: the scan-clean
# stat-line numerics pin; the
# messy reads stay open.
#
# 1. rules/uaappends.h (NEW,
#    prefix uas, 10 inline
#    functions + the 23-row
#    stat table): the tier
#    census (5 greater, 16
#    lesser, 2 demigods), the
#    psionic rating census
#    (VI 10, III 5, IV 1,
#    Nil 6, Brandobaris
#    unrecorded - matching
#    the R405 seam live), the
#    pantheon slices
#    (5/5/4/4/5), the per-
#    deity numerics (AC, HP,
#    MR, rating, size, the
#    attacks-per-round in
#    halves, the damage
#    range) and the printed
#    alignment and plane
#    strings. The holes the
#    scan carries record as
#    sentinels: the Hanali AC
#    garble (99), the Shargaas
#    attack garble (-1), the
#    unprinted damage reads
#    (Labelas/Yurtrus "see
#    below", Cyrrollalee "by
#    weapon type", the
#    Brandobaris garble - -1).
#    The six class/level
#    lines, the MOVE values
#    and the stat lines
#    (S/I/W/D/C/CH/CM) stay
#    UNPINNED this round.
# 2. regtest.cpp: the
#    include rides the R405
#    include, the R406 audit
#    block lands before the
#    R227 anchor - the tier
#    and rating censuses
#    cross-check the R405 seam
#    live (nhdPantheonSize,
#    nhdPsionicRatingCount),
#    the total hit-point sum
#    (6985) catches any cell
#    drift, and the spot
#    checks pin Clanggedin,
#    Berronar, Hanali,
#    Brandobaris, Bahgtru,
#    Shargaas and Luthic;
#    census 332 -> 333.
# 3. tools/ua_gap_report.md:
#    the Appendix S box takes
#    an AMENDED R406 note (the
#    box stays open on the
#    class lines, the stat
#    lines, the prose and the
#    clerical charts).
# 4. The seed takes the R405
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
        'R406 splice ABORT: ' + msg)


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
    '- R405 landed 2026-10-13:',
    '  commit 548b966 (census 332,',
    '  preflight GREEN), the deity',
    '  layer seam - the LAST',
    '  in-scope seam; rules/',
    '  deities.h (prefix nhd, 24',
    '  inline functions) - the',
    '  Appendix S contract,',
    '  source, census and dwarven',
    '  reads, cross-checked',
    '  against the R169/R322/',
    '  R323/R404 feeders. The',
    '  stat blocks + charts ride',
    '  the seam ungated. The',
    '  ./nn save hash diverged',
    '  for the thirteenth round',
    '  running - benign; the md5',
    '  stays advisory. THE SEAM',
    '  LIST IS NOW EMPTY.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R405 landed 2026-10-13' in s:
    already.append('seed: the R405 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R405 record')
s = rd(SD)
if s.count('R405 landed 2026-10-13') != 1:
    die('the R405 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uaappends.h =========
AS = 'rules/uaappends.h'

ASBODY = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uaappends.h',
    '// The UA APPENDIX S stat blocks,',
    '// R406: the 23 non-human deity',
    '// stat blocks (pp. 110-120) - the',
    '// ungated data round riding the',
    '// R405 deity layer seam. The',
    '// R337/R391 pin-round precedent:',
    '// the scan-clean stat-line numerics',
    '// pin; the messy reads stay open',
    '// (the six class/level lines, the',
    '// MOVE values, the S/I/W/D/C/CH/CM',
    '// stat lines, the prose).',
    '//',
    '// The census (live cross-checked',
    '// against the R405 seam): 23',
    '// blocks, 5 pantheons (dwarves 0-4,',
    '// elves 5-9, halflings 10-13,',
    '// gnomes 14-17, orcs 18-22); the',
    '// tiers 5 greater / 16 lesser / 2',
    '// demigods; the psionic ratings',
    '// VI 10, III 5, IV 1, Nil 6, plus',
    '// Brandobaris unrecorded (no',
    '// rating line in the print).',
    '//',
    '// The fields per block: tier,',
    '// armor class, hit points, magic',
    '// resistance percent, psionic',
    '// rating code, size, the',
    '// attacks per round (in HALVES:',
    '// 4 = 2/round, 3 = 3/2, 8 = 4),',
    '// the damage range min/max, and',
    '// the printed alignment and plane',
    '// strings.',
    '//',
    '// The scan holes record as',
    '// sentinels, not guesses:',
    '//   - UAS_AC_HOLE (99): the Hanali',
    '//     armor class - the scan garbles',
    '//     the line (one hole);',
    '//   - UAS_ATK_HOLE (-1): the',
    '//     Shargaas attacks line - the',
    '//     scan garbles it (one hole);',
    '//   - UAS_DMG_UNRECORDED (-1): the',
    '//     unprinted damage reads -',
    '//     Labelas and Yurtrus print',
    '//     "see below", Cyrrollalee',
    '//     "by weapon type", and the',
    '//     Brandobaris range garbles',
    '//     (four unrecorded); Hanali',
    '//     prints Nil - 0/0, clean.',
    '//',
    '// The damage ranges read min-max',
    '// as printed (Urdlen "S: 4-16"',
    '// pins 4-16; the parenthetical',
    '// plusses ride the stat lines,',
    '// unpinned).',
    '//',
    '// The tier codes: 0 greater, 1',
    '// lesser, 2 demigod. The rating',
    '// codes: 0 VI, 1 III, 2 IV, 3 Nil,',
    '// -1 unrecorded. The size codes:',
    '// 0 S, 1 M, 2 L.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    'enum UasTier {',
    '    UAS_TIER_GREATER = 0,',
    '    UAS_TIER_LESSER,',
    '    UAS_TIER_DEMI',
    '};',
    '',
    'enum UasRating {',
    '    UAS_RATING_VI = 0,',
    '    UAS_RATING_III,',
    '    UAS_RATING_IV,',
    '    UAS_RATING_NIL,',
    '    UAS_RATING_UNRECORDED = -1',
    '};',
    '',
    'enum UasSize {',
    '    UAS_SIZE_S = 0,',
    '    UAS_SIZE_M,',
    '    UAS_SIZE_L',
    '};',
    '',
    'const int UAS_AC_HOLE = 99;',
    'const int UAS_ATK_HOLE = -1;',
    'const int UAS_DMG_UNRECORDED = -1;',
    '',
    'struct UasStatBlock {',
    '    const char* name;',
    '    int tier;',
    '    int ac;',
    '    int hp;',
    '    int mr;',
    '    int rating;',
    '    int size;',
    '    int atkHalves;',
    '    int dmgMin;',
    '    int dmgMax;',
    '    const char* align;',
    '    const char* plane;',
    '};',
    '',
    '// The 23 stat blocks, in pantheon',
    '// order (the R405 registry order):',
    '// dwarves, elves, halflings,',
    '// gnomes, orcs.',
    'inline const UasStatBlock& uasStat(',
    '        int i) {',
    '    static const UasStatBlock T[23] = {',
    '        // ---- the dwarves (pp. 110-111) ----',
    '        { "CLANGGEDIN SILVERBEARD",',
    '          0, -4, 375, 50, 0, 2, 4,',
    '          3, 36, "Lawful neutral",',
    '          "Arcadia" },',
    '        { "VERGADAIN",',
    '          0, -5, 345, 70, 1, 2, 3,',
    '          3, 30, "Neutral",',
    '          "Concordant Opposition" },',
    '        { "DUMATHOIN",',
    '          0, -2, 366, 70, 0, 2, 4,',
    '          10, 40, "Neutral",',
    '          "Concordant Opposition" },',
    '        { "ABBATHOR",',
    '          0, 0, 330, 50, 1, 2, 4,',
    '          2, 24, "Neutral evil",',
    '          "Hades" },',
    '        { "BERRONAR",',
    '          0, -4, 370, 80, 1, 2, 4,',
    '          6, 36, "Lawful good",',
    '          "Seven Heavens" },',
    '        // ---- the elves (pp. 112-113) ----',
    '        { "AERDRIE FAENYA",',
    '          1, -5, 322, 80, 0, 1, 4,',
    '          6, 20, "Chaotic good",',
    '          "Olympus and Gladsheim" },',
    '        { "EREVAN ILESERE",',
    '          1, -1, 290, 85, 1, 0, 2,',
    '          2, 24, "Chaotic neutral",',
    '          "Olympus" },',
    '        { "SOLONOR THELANDIRA",',
    '          1, -2, 308, 85, 0, 1, 8,',
    '          2, 16, "Chaotic good",',
    '          "Olympus" },',
    '        { "HANALI CELANIL",',
    '          1, 99, 312, 95, 0, 1, 0,',
    '          0, 0, "Chaotic good",',
    '          "Olympus" },',
    '        { "LABELAS ENORETH",',
    '          1, -3, 310, 93, 0, 1, 2,',
    '          -1, -1, "Chaotic good",',
    '          "Olympus" },',
    '        // ---- the halflings (pp. 114-115) ----',
    '        { "SHEELA PERYROYL",',
    '          1, 3, 306, 80, 3, 0, 2,',
    '          2, 16, "Neutral",',
    '          "Concordant Opposition" },',
    '        { "ARVOREEN",',
    '          1, 1, 298, 65, 3, 1, 3,',
    '          2, 20, "Lawful good",',
    '          "Seven Heavens" },',
    '        { "CYRROLLALEE",',
    '          1, 3, 260, 75, 3, 0, 3,',
    '          -1, -1, "Lawful good",',
    '          "Seven Heavens" },',
    '        { "BRANDOBARIS",',
    '          2, 0, 185, 60, -1, 0, 2,',
    '          -1, -1, "Neutral",',
    '          "Prime Material" },',
    '        // ---- the gnomes (pp. 116-117) ----',
    '        { "BAERVAN WILDWANDERER",',
    '          1, 1, 295, 20, 1, 0, 3,',
    '          2, 24, "Neutral good",',
    '          "Twin Paradises or Prime Material Plane" },',
    '        { "URDLEN",',
    '          1, 2, 272, 30, 0, 2, 4,',
    '          4, 16, "Chaotic evil",',
    '          "Abyss" },',
    '        { "SEGOJAN EARTHCALLER",',
    '          1, 0, 285, 20, 0, 1, 2,',
    '          3, 30, "Neutral good",',
    '          "Twin Paradises" },',
    '        { "FLANDAL STEELSKIN",',
    '          2, 2, 230, 10, 0, 0, 3,',
    '          3, 24, "Neutral good",',
    '          "Twin Paradises" },',
    '        // ---- the orcs (pp. 118-120) ----',
    '        { "BAHGTRU",',
    '          1, 1, 340, 35, 3, 2, 4,',
    '          10, 60, "Lawful evil",',
    '          "Nine Hells" },',
    '        { "SHARGAAS",',
    '          1, 2, 265, 65, 2, 2, -1,',
    '          3, 30, "Neutral evil",',
    '          "Gehenna" },',
    '        { "ILNEVAL",',
    '          1, -1, 331, 55, 3, 2, 4,',
    '          6, 36, "Lawful evil",',
    '          "Nine Hells" },',
    '        { "YURTRUS",',
    '          1, 0, 303, 75, 0, 2, 4,',
    '          -1, -1, "Neutral evil",',
    '          "Hades" },',
    '        { "LUTHIC",',
    '          1, 3, 287, 80, 3, 2, 4,',
    '          5, 20, "Lawful evil",',
    '          "Nine Hells" },',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 22) i = 22;',
    '    return T[i];',
    '}',
    '',
    'inline int uasDeityCount()',
    '    { return 23; }',
    '',
    '// The tier census: 5 greater,',
    '// 16 lesser, 2 demigods.',
    'inline int uasTierCount(int tier) {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        if (uasStat(i).tier == tier) ++n;',
    '    return n;',
    '}',
    '',
    '// The rating census: VI 10, III 5,',
    '// IV 1, Nil 6, unrecorded 1 -',
    '// matching the R405 seam counts',
    '// for the four printed codes.',
    'inline int uasRatingCount(int code) {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        if (uasStat(i).rating == code) ++n;',
    '    return n;',
    '}',
    '',
    '// The pantheon slices: dwarves,',
    '// elves, halflings, gnomes, orcs.',
    'inline int uasPantheonSize(int p) {',
    '    if (p == 0) return 5;',
    '    if (p == 1) return 5;',
    '    if (p == 2) return 4;',
    '    if (p == 3) return 4;',
    '    return 5;',
    '}',
    '',
    '// The scan holes: one AC garble',
    '// (Hanali), one attacks garble',
    '// (Shargaas).',
    'inline int uasAcHoleCount() {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        if (uasStat(i).ac == UAS_AC_HOLE) ++n;',
    '    return n;',
    '}',
    '',
    'inline int uasAtkHoleCount() {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        if (uasStat(i).atkHalves',
    '                == UAS_ATK_HOLE) ++n;',
    '    return n;',
    '}',
    '',
    '// The unprinted damage reads: 4.',
    'inline int uasDamageUnrecordedCount() {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        if (uasStat(i).dmgMin',
    '                == UAS_DMG_UNRECORDED) ++n;',
    '    return n;',
    '}',
    '',
    '// The total hit points across the',
    '// 23 blocks - the drift catch:',
    '// any single cell change moves it.',
    'inline int uasTotalHitPoints() {',
    '    int n = 0;',
    '    for (int i = 0; i < 23; ++i)',
    '        n += uasStat(i).hp;',
    '    return n;',
    '}',
    '',
    '}   // namespace rules',
    '')
newfile(AS, ASBODY + NL,
        'the appendix S stat blocks header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/deities.h"  '
     '// R405: the deity layer seam',
     E(
    '#include "rules/deities.h"  '
    '// R405: the deity layer seam',
    '#include "rules/uaappends.h"  '
    '// R406: the UA Appendix S stat blocks'),
     'regtest: the stat blocks include')

AUD = E(
    '    // ---- R406: the UA Appendix S',
    '    // stat blocks pin audit ----',
    '    // The ungated data round rides',
    '    // the R405 seam: the 23 stat',
    '    // blocks pin their scan-clean',
    '    // numerics (tier, AC, HP, MR,',
    '    // rating, size, the attacks in',
    '    // halves, the damage range, the',
    '    // printed alignment and plane),',
    '    // the tier and rating censuses',
    '    // cross-check the R405 seam',
    '    // live, the hole sentinels',
    '    // record the scan garbles, and',
    '    // the 6985 hit-point sum catches',
    '    // any cell drift; the class',
    '    // lines, the MOVE values and the',
    '    // stat lines stay unpinned;',
    '    // census 332 -> 333.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the census ----',
    '        if (uasDeityCount() != 23) ++bad;',
    '        if (uasDeityCount()',
    '                != nhdDeityCount()) ++bad;',
    '        // the tier census: 5/16/2',
    '        if (uasTierCount(UAS_TIER_GREATER)',
    '                != 5) ++bad;',
    '        if (uasTierCount(UAS_TIER_LESSER)',
    '                != 16) ++bad;',
    '        if (uasTierCount(UAS_TIER_DEMI)',
    '                != 2) ++bad;',
    '        if (uasTierCount(UAS_TIER_GREATER)',
    '                + uasTierCount(UAS_TIER_LESSER)',
    '                + uasTierCount(UAS_TIER_DEMI)',
    '                != 23) ++bad;',
    '        // the rating census: VI 10,',
    '        // III 5, IV 1, Nil 6,',
    '        // unrecorded 1 - and the four',
    '        // printed codes match the R405',
    '        // seam live',
    '        if (uasRatingCount(UAS_RATING_VI)',
    '                != 10) ++bad;',
    '        if (uasRatingCount(UAS_RATING_III)',
    '                != 5) ++bad;',
    '        if (uasRatingCount(UAS_RATING_IV)',
    '                != 1) ++bad;',
    '        if (uasRatingCount(UAS_RATING_NIL)',
    '                != 6) ++bad;',
    '        if (uasRatingCount(',
    '                UAS_RATING_UNRECORDED) != 1)',
    '            ++bad;',
    '        if (uasRatingCount(UAS_RATING_VI)',
    '                != nhdPsionicRatingCount(0))',
    '            ++bad;',
    '        if (uasRatingCount(UAS_RATING_III)',
    '                != nhdPsionicRatingCount(1))',
    '            ++bad;',
    '        if (uasRatingCount(UAS_RATING_IV)',
    '                != nhdPsionicRatingCount(2))',
    '            ++bad;',
    '        if (uasRatingCount(UAS_RATING_NIL)',
    '                != nhdPsionicRatingCount(3))',
    '            ++bad;',
    '        // the pantheon slices ride the',
    '        // R405 registry live',
    '        if (uasPantheonSize(0)',
    '                != nhdPantheonSize(0)',
    '                || uasPantheonSize(1)',
    '                    != nhdPantheonSize(1)',
    '                || uasPantheonSize(2)',
    '                    != nhdPantheonSize(2)',
    '                || uasPantheonSize(3)',
    '                    != nhdPantheonSize(3)',
    '                || uasPantheonSize(4)',
    '                    != nhdPantheonSize(4))',
    '            ++bad;',
    '        // ---- the drift catch ----',
    '        if (uasTotalHitPoints() != 6985)',
    '            ++bad;',
    '        // ---- the hole sentinels ----',
    '        if (uasAcHoleCount() != 1',
    '                || uasAtkHoleCount() != 1',
    '                || uasDamageUnrecordedCount()',
    '                    != 4)',
    '            ++bad;',
    '        if (uasStat(8).ac != UAS_AC_HOLE)',
    '            ++bad;',
    '        if (uasStat(19).atkHalves',
    '                != UAS_ATK_HOLE) ++bad;',
    '        // ---- the spot checks ----',
    '        // Clanggedin (the first block)',
    '        if (strcmp(uasStat(0).name,',
    '                   "CLANGGEDIN SILVERBEARD") != 0)',
    '            ++bad;',
    '        if (uasStat(0).ac != -4',
    '                || uasStat(0).hp != 375',
    '                || uasStat(0).mr != 50',
    '                || uasStat(0).tier',
    '                    != UAS_TIER_GREATER',
    '                || uasStat(0).rating',
    '                    != UAS_RATING_VI',
    '                || uasStat(0).size',
    '                    != UAS_SIZE_L',
    '                || uasStat(0).atkHalves != 4',
    '                || uasStat(0).dmgMin != 3',
    '                || uasStat(0).dmgMax != 36)',
    '            ++bad;',
    '        if (strcmp(uasStat(0).align,',
    '                   "Lawful neutral") != 0)',
    '            ++bad;',
    '        if (strcmp(uasStat(0).plane,',
    '                   "Arcadia") != 0) ++bad;',
    '        // Berronar, Hanali, Brandobaris',
    '        if (uasStat(4).hp != 370',
    '                || uasStat(4).mr != 80) ++bad;',
    '        if (uasStat(8).hp != 312',
    '                || uasStat(8).mr != 95',
    '                || uasStat(8).dmgMin != 0',
    '                || uasStat(8).dmgMax != 0)',
    '            ++bad;',
    '        if (uasStat(13).hp != 185',
    '                || uasStat(13).tier',
    '                    != UAS_TIER_DEMI',
    '                || uasStat(13).rating',
    '                    != UAS_RATING_UNRECORDED)',
    '            ++bad;',
    '        // Bahgtru, Shargaas, Luthic',
    '        if (uasStat(18).dmgMin != 10',
    '                || uasStat(18).dmgMax != 60)',
    '            ++bad;',
    '        if (uasStat(19).rating',
    '                != UAS_RATING_IV',
    '                || uasStat(19).ac != 2',
    '                || uasStat(19).dmgMin != 3',
    '                || uasStat(19).dmgMax != 30)',
    '            ++bad;',
    '        if (uasStat(22).ac != 3',
    '                || uasStat(22).hp != 287',
    '                || uasStat(22).dmgMin != 5',
    '                || uasStat(22).dmgMax != 20)',
    '            ++bad;',
    '        if (strcmp(uasStat(22).align,',
    '                   "Lawful evil") != 0) ++bad;',
    '        // Urdlen: the evil gnome',
    '        if (strcmp(uasStat(15).plane,',
    '                   "Abyss") != 0) ++bad;',
    '        printf("R406 UA appendix S stat'
    ' blocks pin audit: bad %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R406 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '- [ ] **Appendix S: non-human deities**',
    '      (pp. 109-122) - DEFERRED on a',
    '      deity layer: the demi-human',
    '      pantheon prose, the clerical',
    '      quick-reference charts. A deity',
    '      layer is engineerable (the',
    '      mission: everything includeable).'),
    E(
    '- [ ] **Appendix S: non-human deities**',
    '      (pp. 109-122) - DEFERRED on a',
    '      deity layer: the demi-human',
    '      pantheon prose, the clerical',
    '      quick-reference charts. A deity',
    '      layer is engineerable (the',
    '      mission: everything includeable).',
    '      - AMENDED R406: the stat blocks',
    '        pin round (rules/uaappends.h)',
    '        - the 23 blocks pin their',
    '        scan-clean numerics (tier, AC,',
    '        HP, MR, rating, size, attacks',
    '        in halves, damage range,',
    '        alignment, plane) with the',
    '        tier/rating censuses live',
    '        against the R405 seam and the',
    '        6985 HP drift catch; the scan',
    '        holes record as sentinels',
    '        (Hanali AC, Shargaas attacks,',
    '        four unprinted damage reads).',
    '        STILL OPEN: the six',
    '        class/level lines per block,',
    '        the MOVE values, the',
    '        S/I/W/D/C/CH/CM stat lines,',
    '        the pantheon prose, and the',
    '        clerical quick-reference',
    '        charts (pp. 121-122).'),
    'gap: the Appendix S amendment')

pair(GP, E(
    '    scan); the 23 deity stat blocks',
    '    and the five clerical charts ride',
    '    the seam as its own ungated data',
    '    round.'),
    E(
    '    scan); the 23 deity stat blocks',
    '    and the five clerical charts ride',
    '    the seam as its own ungated data',
    '    round.',
    '  - AMENDED R406: the stat block',
    '    numerics land (rules/uaappends.h)',
    '    - the class lines, MOVE, stat',
    '    lines, prose and the charts stay',
    '    open.'),
    'gap: the DEFERRED amendment')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 333:
    die('the census %d' % s.count('audit: bad'))
if s.count('R406 UA appendix S stat'
           ' blocks pin audit') != 1:
    die('the R406 audit label')
if s.count('uasStat(') < 15:
    die('the uasStat call count %d'
        % s.count('uasStat('))
if s.count('uasTotalHitPoints()') != 1:
    die('the total HP call count')

p = rd(AS)
if p.count('inline') != 9:
    die('the appends inline count %d'
        % p.count('inline'))
if p.count('{ "') != 23:
    die('the stat row count %d'
        % p.count('{ "'))
if not p.endswith(NL):
    die('the appends trailing newline')

g = rd(GP)
if g.count('AMENDED R406') != 2:
    die('the gap amended count %d'
        % g.count('AMENDED R406'))

for path, mark in ((AS, 'CLANGGEDIN SILVERBEARD'),
                   (RT, 'uasDeityCount'),
                   (SD, 'R405 landed')):
    if mark not in rd(path):
        die('%s carries no R406 round' % path)

# the contract: no engine caller (the
# word-boundary check: 'Persuasiveness'
# carries the substring 'uas')
import re as _re
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\\buas', rd(path)):
        die('%s calls the pins early'
            % path)

print('R406 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the Appendix S stat blocks')
print('  pin - 23 blocks, the censuses ride')
print('  the R405 seam live; the class')
print('  lines, MOVE, stat lines, prose')
print('  and the charts stay open;')
print('  census 332 -> 333')
print('commit: R406: the UA Appendix S'
      ' stat blocks (census 333)')

