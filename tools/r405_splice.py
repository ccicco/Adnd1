#!/usr/bin/env python3
# R405: the deity layer seam - the
# last in-scope seam lands (the
# two logging layers stay OUT,
# the user decision). The R404
# psionics precedent rides:
# pins first, the stat blocks
# and the clerical charts stay
# open:
#
# 1. rules/deities.h (NEW,
#    prefix nhd, 24 inline
#    functions): the layer
#    contract (no deity actor
#    site; the pins precede the
#    site; the seam gates the
#    Appendix S charge), the
#    source pins (Appendix S,
#    pp. 109-122, the Roger E.
#    Moore DRAGON #58-63
#    material, an adjunct to
#    Legends & Lore; Moradin
#    lives in Legends & Lore,
#    the 20-foot Soul Forger,
#    no dwarven deity taller),
#    the census pins (23 deity
#    stat blocks, 5 pantheons -
#    dwarves 5, elves 5,
#    halflings 4, gnomes 4,
#    orcs 5; the tiers: 5
#    greater, 16 lesser, 2
#    demigods; the psionic
#    ratings: VI 10, III 5,
#    IV 1, Nil 6, Brandobaris
#    unrecorded), the dwarven
#    reads (greater dwarven
#    gods at least twice
#    normal dwarf size; holy
#    symbols never living
#    objects; dual charismas -
#    the CH:x(y) stat-line
#    form; giant-types attack
#    at -4, the same penalty as
#    for mortal dwarves), the
#    five clerical charts (8
#    columns each), and the
#    four-feeder registry (R169
#    humanoid preferences, R322
#    comeliness, R323 subraces,
#    R404 psionics).
# 2. regtest.cpp: the include
#    rides the R169 block, the
#    new R405 audit block lands
#    before the R227 anchor -
#    every feeder cross-checks
#    live (the nine-race
#    humanoid matrix with its
#    orc row and no elf column,
#    the Clanggedin dual
#    comeliness 13(20) riding
#    the R322 bands, the four
#    demi-human pantheon parent
#    races, the psx duergar
#    pins); census 331 -> 332.
# 3. tools/ua_gap_report.md:
#    the seam checkbox closes;
#    the Appendix S DEFERRED
#    block takes an AMENDED
#    R405 note.
# 4. The seed takes the R404
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
        'R405 splice ABORT: ' + msg)


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
    '- R404 landed 2026-10-13:',
    '  commit 9dc9a90 (census 331,',
    '  preflight GREEN), the',
    '  psionics seam - rules/',
    '  psionics.h (prefix psx, 15',
    '  inline functions) - the',
    '  layer contract, the open/',
    '  OUT records (the PHB',
    '  sections OPEN, the DMG',
    '  p.77 combat OUT), the',
    '  duergar doubled chance',
    '  (twice the usual, double',
    '  all INT/WIS/CHA bonuses)',
    '  and the svirfneblin PC',
    '  ban, cross-checked against',
    '  the R166/R323/R328 feeders.',
    '  The psionic-combat charge',
    '  stays open. The ./nn save',
    '  hash diverged for the',
    '  twelfth round running -',
    '  benign; the md5 stays',
    '  advisory. Ritual note: the',
    '  ./nn step does not belong',
    '  in the run ritual.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R404 landed 2026-10-13' in s:
    already.append('seed: the R404 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R404 record')
s = rd(SD)
if s.count('R404 landed 2026-10-13') != 1:
    die('the R404 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/deities.h =========
DH = 'rules/deities.h'

DHBODY = E(
    '// ===========================================================================',
    '// Adnd1 - rules/deities.h',
    '// The DEITY LAYER SEAM (R405) - the',
    '// last in-scope seam lands. The R404',
    '// psionics precedent rides: the pins',
    '// charge here, the Appendix S charge',
    '// (the 23 deity stat blocks, the five',
    '// clerical quick-reference charts)',
    '// charges its own data round later;',
    '// the engine has NO deity actor site',
    '// today.',
    '//',
    '// The gated read: Appendix S, the',
    '// NON-HUMAN DEITIES (pp. 109-122) -',
    '// the Roger E. Moore material from',
    '// DRAGON Magazine issues #58-63,',
    '// reproduced as an adjunct to the',
    '// Non-Human Deities section of',
    '// Legends & Lore (formerly the',
    '// DEITIES & DEMIGODS Cyclopedia).',
    '//',
    '// The census the clean djvu scan',
    '// carries:',
    '//   - 23 deity stat blocks across 5',
    '//     pantheons: the dwarves 5',
    '//     (Clanggedin Silverbeard,',
    '//     Vergadain, Dumathoin, Abbathor,',
    '//     Berronar), the elves 5 (Aerdrie',
    '//     Faenya, Erevan Ilesere, Solonor',
    '//     Thelandira, Hanali Celanil,',
    '//     Labelas Enoreth), the halflings',
    '//     4 (Sheela Peryroyl, Arvoreen,',
    '//     Cyrrollalee, Brandobaris), the',
    '//     gnomes 4 (Baervan',
    '//     Wildwanderer, Urdlen, Segojan',
    '//     Earthcaller, Flandal Steelskin),',
    '//     the orcs 5 (Bahgtru, Shargaas,',
    '//     Ilneval, Yurtrus, Luthic);',
    '//   - the tiers: 5 greater (4 gods +',
    '//     Berronar the greater goddess),',
    '//     16 lesser (11 gods + 5',
    '//     goddesses), 2 demigods',
    '//     (Brandobaris, Flandal);',
    '//   - the psionic ratings: 22 rating',
    '//     lines - VI 10, III 5, IV 1',
    '//     (Shargaas), Nil 6 - and one',
    '//     block without a rating line',
    '//     (Brandobaris, unrecorded).',
    '//     NOTE: the deity ratings are the',
    '//     Appendix S scale, NOT the PC',
    '//     psionic chance of the R404 seam.',
    '//',
    '// The dwarven reads (pp. 109-110):',
    '//   - the greater dwarven gods are at',
    '//     least TWICE as large as normal',
    '//     dwarves, ranging up to Moradin\'s',
    '//     20-foot height; no dwarven deity',
    '//     is taller than Moradin, the Soul',
    '//     Forger - described in Legends &',
    '//     Lore, invariably the ruler of',
    '//     all dwarven pantheons;',
    '//   - the holy symbols are invariably',
    '//     NOT living objects (tools,',
    '//     weapons, mountains, minerals) -',
    '//     no animal and no dwarf is a',
    '//     dwarven symbol;',
    '//   - all dwarven gods possess DUAL',
    '//     CHARISMAS, one applying to',
    '//     dwarves and the dwarven deities,',
    '//     the other to everyone else - the',
    '//     CH:x(y) stat-line form (the',
    '//     parenthesized value is the',
    '//     comeliness side, the R322 seam:',
    '//     Clanggedin prints CH:16(22),',
    '//     CM:13(20));',
    '//   - giant-type creatures attack',
    '//     Clanggedin at a -4 penalty to',
    '//     hit, the same as for mortal',
    '//     dwarves.',
    '//',
    '// The five clerical quick-reference',
    '// charts (pp. 121-122) print one row',
    '// per deity (23 rows), each 8 columns:',
    '// DEITY, SPHERE OF CONTROL, the',
    '// RAIMENT head, body and color(s),',
    '// HOLY DAYS, and the',
    '// SACRIFICE/PROPITIATION frequency',
    '// and form.',
    '//',
    '// The feeders the corpus already',
    '// pinned:',
    '//   0: R169 the humanoid racial',
    '//      preferences (rules/humrpref.h -',
    '//      the nine-race matrix: the orc',
    '//      row carries no elf column, so',
    '//      the Appendix S Gruumsh/Corellon',
    '//      read - orcs hate elves more',
    '//      than all other non-orc races -',
    '//      is the sole cross-pantheon',
    '//      site)',
    '//   1: R322 the comeliness seam',
    '//      (rules/comeliness.h - the',
    '//      bands the parenthesized CM',
    '//      values ride)',
    '//   2: R323 the subrace layer',
    '//      (rules/subraces.h - the four',
    '//      demi-human pantheons map to',
    '//      their subrace parents)',
    '//   3: R404 the psionics seam',
    '//      (rules/psionics.h - the PC',
    '//      psionic reads stay PC-side:',
    '//      the duergar doubled chance,',
    '//      the svirfneblin ban)',
    '// The R405 audit cross-checks every',
    '// feeder live; the stat-block charge',
    '// stays open.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// ---- the layer contract ----',
    '// The engine has no deity actor site',
    '// (the pins precede any charge).',
    'inline bool nhdDeitySiteExists()',
    '    { return false; }',
    '',
    'inline bool nhdPinsPrecedeSite()',
    '    { return true; }',
    '',
    '// The seam gates the Appendix S',
    '// charge.',
    'inline bool nhdGatesAppendixS()',
    '    { return true; }',
    '',
    '// The Appendix S charge (the 23',
    '// stat blocks, the five charts) stays',
    '// open after the seam lands.',
    'inline bool nhdStatBlocksOpen()',
    '    { return true; }',
    '',
    '// ---- the source pins ----',
    '// Appendix S, the NON-HUMAN DEITIES:',
    '// pp. 109-122 of the print.',
    'inline int nhdAppendixPageFirst()',
    '    { return 109; }',
    '',
    'inline int nhdAppendixPageLast()',
    '    { return 122; }',
    '',
    '// Moradin, the Soul Forger, is',
    '// described in Legends & Lore, not',
    '// here - invariably the ruler of all',
    '// dwarven pantheons.',
    'inline bool nhdMoradinInLegendsLore()',
    '    { return true; }',
    '',
    '// No dwarven deity is taller than',
    '// Moradin\'s 20 feet.',
    'inline int nhdMoradinHeightFeet()',
    '    { return 20; }',
    '',
    '// ---- the census pins ----',
    '// The 23 deity stat blocks.',
    'inline int nhdDeityCount()',
    '    { return 23; }',
    '',
    '// The five pantheons.',
    'inline int nhdPantheonCount()',
    '    { return 5; }',
    '',
    '// The pantheon sizes: dwarves,',
    '// elves, halflings, gnomes, orcs.',
    'inline int nhdPantheonSize(int p) {',
    '    static const int k[5] = {',
    '        5, 5, 4, 4, 5',
    '    };',
    '    if (p < 0) p = 0;',
    '    if (p > 4) p = 4;',
    '    return k[p];',
    '}',
    '',
    '// The tiers: 5 greater (the four',
    '// greater gods + Berronar the greater',
    '// goddess), 16 lesser (11 gods + 5',
    '// goddesses), 2 demigods (Brandobaris',
    '// and Flandal).',
    'inline int nhdGreaterDeityCount()',
    '    { return 5; }',
    '',
    'inline int nhdLesserDeityCount()',
    '    { return 16; }',
    '',
    'inline int nhdDemigodCount()',
    '    { return 2; }',
    '',
    '// The psionic rating census, by code',
    '// index: 0 = VI, 1 = III, 2 = IV,',
    '// 3 = Nil.',
    'inline int nhdPsionicRatingCount(',
    '        int code) {',
    '    static const int k[4] = {',
    '        10, 5, 1, 6',
    '    };',
    '    if (code < 0) code = 0;',
    '    if (code > 3) code = 3;',
    '    return k[code];',
    '}',
    '',
    '// One block carries no rating line:',
    '// Brandobaris, unrecorded.',
    'inline int nhdRatingUnrecordedCount()',
    '    { return 1; }',
    '',
    '// ---- the dwarven reads (pp. 109-110) ----',
    '// The greater dwarven gods are at',
    '// least twice as large as normal',
    '// dwarves.',
    'inline int nhdGreaterDwarfSizeMultiple()',
    '    { return 2; }',
    '',
    '// The holy symbols are invariably not',
    '// living objects.',
    'inline bool nhdDwarfSymbolNeverLiving()',
    '    { return true; }',
    '',
    '// All dwarven gods possess dual',
    '// charismas - the CH:x(y) form.',
    'inline bool nhdDwarfDeityDualCharisma()',
    '    { return true; }',
    '',
    '// Giant-types attack at -4 to hit -',
    '// the same penalty as for mortal',
    '// dwarves.',
    'inline int nhdGiantTypeAttackPenalty()',
    '    { return 4; }',
    '',
    '// ---- the clerical charts (pp. 121-122) ----',
    '// The five quick-reference charts,',
    '// one per pantheon.',
    'inline int nhdChartCount()',
    '    { return 5; }',
    '',
    '// Each chart row prints 8 columns:',
    '// DEITY, SPHERE OF CONTROL, the',
    '// RAIMENT head, body, color(s), HOLY',
    '// DAYS, the SACRIFICE/PROPITIATION',
    '// frequency and form.',
    'inline int nhdChartColumnCount()',
    '    { return 8; }',
    '',
    '// ---- the feeder registry ----',
    'inline int nhdFeederSeamCount()',
    '    { return 4; }',
    '',
    '// The feeder rounds, in registry',
    '// order (0-3 above).',
    'inline int nhdFeederRound(int i) {',
    '    static const int k[4] = {',
    '        169, 322, 323, 404',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 3) i = 3;',
    '    return k[i];',
    '}',
    '',
    '}   // namespace rules',
    '')
newfile(DH, DHBODY + NL,
        'the deity layer seam header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/humrpref.h"  '
     '// R169: p.106 humanoid racial'
     ' preferences',
     E(
    '#include "rules/humrpref.h"  // R169:'
    ' p.106 humanoid racial preferences',
    '#include "rules/deities.h"  '
    '// R405: the deity layer seam'),
     'regtest: the deities include')

AUD = E(
    '    // ---- R405: the deity layer seam',
    '    // audit ----',
    '    // The last in-scope seam lands: the',
    '    // layer contract (no deity site; the',
    '    // pins precede the site; the seam',
    '    // gates the Appendix S charge; the',
    '    // stat blocks stay open), the source',
    '    // pins (Appendix S pp. 109-122,',
    '    // Moradin in Legends & Lore at 20',
    '    // feet), the census (23 deities, 5',
    '    // pantheons 5/5/4/4/5, the tiers',
    '    // 5/16/2, the ratings VI 10 III 5',
    '    // IV 1 Nil 6 + Brandobaris',
    '    // unrecorded), the dwarven reads',
    '    // (twice normal size, no living',
    '    // symbols, dual charismas, the -4',
    '    // giant penalty), the five 8-column',
    '    // charts, and the live cross-checks',
    '    // of the four feeders - R169 the',
    '    // humanoid matrix, R322 the',
    '    // comeliness bands, R323 the',
    '    // subrace parents, R404 the psx',
    '    // pins; census 331 -> 332.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the layer contract ----',
    '        if (nhdDeitySiteExists()) ++bad;',
    '        if (!nhdPinsPrecedeSite()) ++bad;',
    '        if (!nhdGatesAppendixS()) ++bad;',
    '        if (!nhdStatBlocksOpen()) ++bad;',
    '        // ---- the source pins ----',
    '        if (nhdAppendixPageFirst() != 109)',
    '            ++bad;',
    '        if (nhdAppendixPageLast() != 122)',
    '            ++bad;',
    '        if (!nhdMoradinInLegendsLore()) ++bad;',
    '        if (nhdMoradinHeightFeet() != 20)',
    '            ++bad;',
    '        // ---- the census pins ----',
    '        if (nhdDeityCount() != 23) ++bad;',
    '        if (nhdPantheonCount() != 5) ++bad;',
    '        // the pantheon sizes: 5/5/4/4/5',
    '        if (nhdPantheonSize(0) != 5',
    '                || nhdPantheonSize(1) != 5',
    '                || nhdPantheonSize(2) != 4',
    '                || nhdPantheonSize(3) != 4',
    '                || nhdPantheonSize(4) != 5)',
    '            ++bad;',
    '        // the pantheons add up to the census',
    '        if (nhdPantheonSize(0)',
    '                + nhdPantheonSize(1)',
    '                + nhdPantheonSize(2)',
    '                + nhdPantheonSize(3)',
    '                + nhdPantheonSize(4)',
    '                != nhdDeityCount()) ++bad;',
    '        // the tiers: 5 greater, 16 lesser,',
    '        // 2 demigods - and they add up',
    '        if (nhdGreaterDeityCount() != 5',
    '                || nhdLesserDeityCount() != 16',
    '                || nhdDemigodCount() != 2)',
    '            ++bad;',
    '        if (nhdGreaterDeityCount()',
    '                + nhdLesserDeityCount()',
    '                + nhdDemigodCount()',
    '                != nhdDeityCount()) ++bad;',
    '        // the ratings: VI 10, III 5, IV 1,',
    '        // Nil 6 - and with Brandobaris',
    '        // unrecorded they add up',
    '        if (nhdPsionicRatingCount(0) != 10',
    '                || nhdPsionicRatingCount(1)',
    '                    != 5',
    '                || nhdPsionicRatingCount(2)',
    '                    != 1',
    '                || nhdPsionicRatingCount(3)',
    '                    != 6)',
    '            ++bad;',
    '        if (nhdPsionicRatingCount(0)',
    '                + nhdPsionicRatingCount(1)',
    '                + nhdPsionicRatingCount(2)',
    '                + nhdPsionicRatingCount(3)',
    '                + nhdRatingUnrecordedCount()',
    '                != nhdDeityCount()) ++bad;',
    '        // ---- the dwarven reads ----',
    '        if (nhdGreaterDwarfSizeMultiple() != 2)',
    '            ++bad;',
    '        if (!nhdDwarfSymbolNeverLiving()) ++bad;',
    '        if (!nhdDwarfDeityDualCharisma()) ++bad;',
    '        if (nhdGiantTypeAttackPenalty() != 4)',
    '            ++bad;',
    '        // ---- the clerical charts ----',
    '        if (nhdChartCount() != 5) ++bad;',
    '        if (nhdChartColumnCount() != 8) ++bad;',
    '        // the charts carry one row per',
    '        // deity: 23 rows across the five',
    '        if (nhdChartCount()',
    '                != nhdPantheonCount()) ++bad;',
    '        // ---- the feeder registry ----',
    '        if (nhdFeederSeamCount() != 4) ++bad;',
    '        if (nhdFeederRound(0) != 169',
    '                || nhdFeederRound(1) != 322',
    '                || nhdFeederRound(2) != 323',
    '                || nhdFeederRound(3) != 404)',
    '            ++bad;',
    '        // ---- the R169 humanoid matrix ----',
    '        // the nine-race matrix carries the',
    '        // orc row but no elf column - the',
    '        // Appendix S Gruumsh/Corellon read',
    '        // is the sole cross-pantheon site',
    '        if (humRPrefRaceCount() != 9) ++bad;',
    '        if (humRPrefRaceIndex("orc") != 7)',
    '            ++bad;',
    '        if (humRPrefRaceIndex("elf") != -1)',
    '            ++bad;',
    '        // ---- the R322 comeliness seam ----',
    '        // Clanggedin CM:13(20) - the dual',
    '        // comeliness values ride the R322',
    '        // bands (13 the band-5 side, 20 the',
    '        // band-7 side at 150 percent)',
    '        if (uaComelinessBand(13) != 5) ++bad;',
    '        if (uaComelinessBand(20) != 7) ++bad;',
    '        if (uaComelinessReactionPct(20)',
    '                != 150) ++bad;',
    '        // ---- the R323 subrace seam ----',
    '        // the four demi-human pantheons map',
    '        // to their subrace parents (orcs',
    '        // carry no subrace)',
    '        if (subraceParentRace(SUB_DWARF_GRAY)',
    '                != RACE_DWARF) ++bad;',
    '        if (subraceParentRace(SUB_ELF_HIGH)',
    '                != RACE_ELF) ++bad;',
    '        if (subraceParentRace(SUB_GNOME_DEEP)',
    '                != RACE_GNOME) ++bad;',
    '        if (subraceParentRace(',
    '                SUB_HALFLING_HAIRFOOT)',
    '                != RACE_HALFLING) ++bad;',
    '        // ---- the R404 psionics seam ----',
    '        // the PC psionic reads stay',
    '        // PC-side: the duergar doubled',
    '        // chance and the svirfneblin ban',
    '        // (the deity ratings are the',
    '        // Appendix S scale, not the PC',
    '        // chance)',
    '        if (psxDuergarChanceMultiple() != 2)',
    '            ++bad;',
    '        if (!psxSvirfneblinPcNoPsionics())',
    '            ++bad;',
    '        printf("R405 deity layer seam'
    ' audit: bad %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R405 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '- [ ] The deity layer - gates Appendix',
    '      S.'),
    E(
    '- [x] The deity layer -',
    '      CLOSED R405 (rules/deities.h;',
    '      the R405 seam audit, census 332):',
    '      the layer contract (no deity',
    '      actor site - the pins precede',
    '      the site, the R404 psionics',
    '      precedent), the Appendix S source',
    '      pins (pp. 109-122, the Roger E.',
    '      Moore DRAGON #58-63 material,',
    '      Moradin in Legends & Lore at 20',
    '      feet), the census (23 deities, 5',
    '      pantheons 5/5/4/4/5, the tiers',
    '      5/16/2, the ratings VI 10 III 5',
    '      IV 1 Nil 6 + Brandobaris',
    '      unrecorded), the dwarven reads',
    '      (twice normal size, no living',
    '      symbols, dual charismas, the -4',
    '      giant penalty), and the five',
    '      8-column clerical charts - live',
    '      cross-checked against the four',
    '      feeders (R169 the humanoid',
    '      matrix, R322 the comeliness',
    '      bands, R323 the subrace parents,',
    '      R404 the psx pins). The 23',
    '      stat blocks and the five charts',
    '      stay open - a new ungated item.'),
    'gap: the seam checkbox')

pair(GP, E(
    '- DEFERRED: Appendix S (a deity layer;',
    '  see the appendices item).'),
    E(
    '- DEFERRED: Appendix S (a deity layer;',
    '  see the appendices item).',
    '  - AMENDED R405: the layer lands -',
    '    rules/deities.h pins the Appendix S',
    '    contract, source, census and',
    '    dwarven reads (the clean djvu',
    '    scan); the 23 deity stat blocks',
    '    and the five clerical charts ride',
    '    the seam as its own ungated data',
    '    round.'),
    'gap: the DEFERRED amendment')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 332:
    die('the census %d' % s.count('audit: bad'))
if s.count('R405 deity layer seam'
           ' audit') != 1:
    die('the R405 audit label')
if s.count('nhdFeederRound(') != 4:
    die('the feeder call count %d'
        % s.count('nhdFeederRound('))
if s.count('nhdPantheonSize(') < 2:
    die('the pantheon call count %d'
        % s.count('nhdPantheonSize('))
if s.count('nhdDeitySiteExists()') != 1:
    die('the site count')

p = rd(DH)
if p.count('inline') != 24:
    die('the deities inline count %d'
        % p.count('inline'))
if 'nhdMoradinHeightFeet' not in p:
    die('the Moradin pin')
if not p.endswith(NL):
    die('the deities trailing newline')

g = rd(GP)
if g.count('AMENDED R405') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R405'))
if g.count('CLOSED R405') != 1:
    die('the gap closed count %d'
        % g.count('CLOSED R405'))

for path, mark in ((DH, 'nhdMoradinHeightFeet'),
                   (RT, 'nhdDeitySiteExists'),
                   (SD, 'R404 landed')):
    if mark not in rd(path):
        die('%s carries no R405 seam' % path)

# the contract: no engine caller
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if 'nhd' in rd(path):
        die('%s calls the seam early'
            % path)

print('R405 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the deity layer seam lands -')
print('  the Appendix S pins and the census;')
print('  the stat blocks stay open;')
print('  census 331 -> 332')
print('commit: R405: the deity layer seam'
      ' (census 332)')

