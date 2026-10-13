#!/usr/bin/env python3
# R402: the UA treasure
# system dial seam - the R374
# decision wires. The dial
# lands first, the charge
# after:
#
# 1. rules/uatreasuredial.h:
#    the runtime dial layer -
#    the mode state (DMG the
#    default, UA, MERGED; the
#    setter, the validity
#    gate, the mode names) and
#    the pending pin flips
#    (the UA pin rounds
#    R375/R395/R397 have
#    landed).
# 2. dm/treasure.cpp: the
#    mode-aware determination
#    dispatch - the UA category
#    bands, the sub-table
#    splits (the low band the
#    new UA table, the high
#    band the DMG original),
#    the misc seven sub-bands,
#    the row resolution off
#    the R395 data, and the
#    MERGED union read (a
#    per-item coin flip). This
#    TU pulls its own rules
#    includes - the R400
#    lesson.
# 3. regtest.cpp: the two
#    pending asserts flip
#    (R374, R375), a new R402
#    audit block lands before
#    the R227 anchor; census
#    328 -> 329.
# 4. tools/ua_gap_report.md:
#    the seam checkbox closes;
#    the DECIDED R374 block
#    takes an AMENDED R402
#    note.
# 5. The seed takes the R401
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
        'R402 splice ABORT: ' + msg)


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


# ========= (a) the seed record =========
SD = 'doc/vibe/' \
     'adnd1_knowledge_seed_v2.md'

SEED_ENTRY = E(
    '- R401 landed 2026-10-13:',
    '  commit 6cf9115 (census 328,',
    '  preflight GREEN), the UA',
    '  cantrip tier seam - the',
    '  sub-1st registry tier closes:',
    '  rules/cantriptier.h (prefix',
    '  cant, 31 inline functions) -',
    '  the p. 45 tier traits, the',
    '  0-level per-day xp ladder',
    '  (neophyte 1, initiate 2,',
    '  apprentice 3), the',
    '  first-level discard and the',
    '  four-cantrip retention, the',
    '  round rules, the seven',
    '  categories, the roster totals',
    '  (66 MU + 8 IL). The R341',
    '  decode corrects from the clean',
    '  p. 30 scan: the reversed column',
    '  prints Tangle, the personal',
    '  Tweak - 66 names; the R341',
    '  audit asserts reseat (Wilt 11,',
    '  Unlock 9). The sim healthy',
    '  pass caught two splice bugs',
    '  pre-publish (the IL name',
    '  asserts, the IL span assert) -',
    '  fixed before the handoff. The',
    '  ./nn save hash diverged for the',
    '  ninth round running - benign;',
    '  the md5 stays advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R401 landed 2026-10-13' in s:
    already.append('seed: the R401 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R401 record')
s = rd(SD)
if s.count('R401 landed 2026-10-13') != 1:
    die('the R401 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uatreasuredial.h =========
TD = 'rules/uatreasuredial.h'

pair(TD, E(
    '// The UA pin rounds have not',
    '// landed yet - the dial lands',
    '// first.',
    'inline bool uatdUaPinRoundsPending()',
    '    { return true; }'),
    E(
    '// R402: the UA pin rounds HAVE',
    '// landed (R375, R395, R397) -',
    '// the dial rides; the charge',
    '// follows.',
    'inline bool uatdUaPinRoundsPending()',
    '    { return false; }'),
    'dial: the pending pin flips')

pair(TD, E(
    '}   // namespace rules'),
    E(
    '// ---- R402: the runtime dial ----',
    '// The mode state rides a static',
    '// (the DMG default until',
    '// playtesting picks); the setter',
    '// gates on the validity.',
    'inline int& uatdModeRef() {',
    '    static int m = uatdDefaultMode();',
    '    return m;',
    '}',
    '',
    '// The current dial mode.',
    'inline int uatdMode()',
    '    { return uatdModeRef(); }',
    '',
    'inline bool uatdModeValid(int m)',
    '    { return m >= 0 &&',
    '      m < uatdModeCount(); }',
    '',
    '// Set the dial (an invalid ask',
    '// falls back to the default).',
    'inline void uatdSetMode(int m) {',
    '    if (!uatdModeValid(m))',
    '        m = uatdDefaultMode();',
    '    uatdModeRef() = m;',
    '}',
    '',
    'inline const char* uatdModeName(int m) {',
    '    static const char* const k[3] = {',
    '        "DMG", "UA", "MERGED"',
    '    };',
    '    if (m < 0) m = 0;',
    '    if (m > 2) m = 2;',
    '    return k[m];',
    '}',
    '',
    '// R402: the dial governs the',
    '// random determination dispatch',
    '// (the magic item roll); the',
    '// landed DMG audits stay',
    '// authoritative under the',
    '// default mode.',
    'inline bool uatdDialLanded()',
    '    { return true; }',
    '',
    '}   // namespace rules'),
    'dial: the runtime layer')

# ========= (c) dm/treasure.cpp =========
TR = 'dm/treasure.cpp'

pair(TR, E(
    '#include "treasure.h"',
    '',
    '#include <cstdio>'),
    E(
    '#include "treasure.h"',
    '',
    '// R402: the treasure dial rides the',
    '// determination dispatch; this TU',
    '// pulls its own rules headers (the',
    '// R400 lesson - the engine TUs do',
    '// not pull rules/ transitively).',
    '#include "rules/uatreasuredial.h"',
    '#include "rules/uadetskel.h"',
    '#include "rules/uadetrows.h"',
    '',
    '#include <cstdio>'),
    'treasure: the rules includes')

pair(TR, E(
    'MagicItem rollMagicItem(rules::Dice& dice) {',
    '    return rollFromCategory(dice,'
    ' rollCategory(dice));',
    '}'),
    E(
    '// ---- R402: the treasure dial (the UA',
    '// determination) ----',
    '// The dial routes the random',
    '// determination dispatch: DMG (the',
    '// default - the landed audits), UA',
    '// (the revised tables, the R375/R395',
    '// data), MERGED (both sets live - a',
    '// per-item coin flip picks the set).',
    '',
    '// The UA top-level category bands',
    '// (the printed order, eight',
    '// categories - uadetskel).',
    'static int rollCategoryUa(rules::Dice& dice) {',
    '    int r = 1 + d100(dice);',
    '    int cat = -1;',
    '    for (int i = 0;',
    '         i < rules::uadsCategoryCount();',
    '         ++i)',
    '        if (r >= rules::uadsCategoryLo(i)',
    '                && r',
    '                <= rules::uadsCategoryHi(i)) {',
    '            cat = i;',
    '            break;',
    '        }',
    '    if (cat < 0) cat = 7;',
    '    return cat;',
    '}',
    '',
    '// The UA category -> the DMG carrier',
    '// category (the misc band rides the',
    '// misc carrier; the MIK kinds do not',
    '// split the misc sub-tables).',
    'static int uaCategoryToDmg(int c) {',
    '    switch (c) {',
    '        case 0: return 0;   // potions',
    '        case 1: return 1;   // scrolls',
    '        case 2: return 2;   // rings',
    '        case 3: return 3;   // rods',
    '        case 4: return 8;   // misc magic',
    '        case 5: return 9;   // armor',
    '        case 6: return 10;  // swords',
    '        default: return 11; // weapons',
    '    }',
    '}',
    '',
    '// The split low bands (the new UA',
    '// table low, the DMG original high).',
    'static int uaSplitLo(int c) {',
    '    switch (c) {',
    '        case 0:',
    '            return rules::uadsPotionSplitLo();',
    '        case 1:',
    '            return rules::uadsScrollSplitLo();',
    '        case 2:',
    '            return rules::uadsRingSplitLo();',
    '        case 3:',
    '            return rules::uadsRodSplitLo();',
    '        case 5:',
    '            return rules::uadsArmorSplitLo();',
    '        case 6:',
    '            return rules::uadsSwordSplitLo();',
    '        default:',
    '            return rules::uadsWeaponSplitLo();',
    '    }',
    '}',
    '',
    '// The category primary UA table (the',
    '// uadetrows printed order).',
    'static int uaPrimaryTable(int c) {',
    '    switch (c) {',
    '        case 0: return 0;    // III.A',
    '        case 1: return 2;    // III.B',
    '        case 2: return 4;    // III.C',
    '        case 3: return 6;    // III.D',
    '        case 5: return 15;   // III.F',
    '        case 6: return 17;   // III.G',
    '        default: return 19;  // III.H',
    '    }',
    '}',
    '',
    '// A row of a UA table by percentile',
    '// (the R395 bands cover 01-00',
    '// contiguously).',
    'static int uaRowOfRoll(int t, int r) {',
    '    for (int i = 0;',
    '         i < rules::uadrowRowCount(t);',
    '         ++i)',
    '        if (r >= rules::uadrowRowLo(t, i)',
    '                && r',
    '                <= rules::uadrowRowHi(t, i))',
    '            return i;',
    '    return 0;',
    '}',
    '',
    '// Roll an item from a UA table row',
    '// (the -1 cells carry the print non-',
    '// numerics - the uadetrows',
    '// discipline).',
    'static MagicItem rollFromUaTable(',
    '        rules::Dice& dice, int t,',
    '        int carrier) {',
    '    int r = 1 + d100(dice);',
    '    int i = uaRowOfRoll(t, r);',
    '    MagicItem m;',
    '    m.name = rules::uadrowRowName(t, i);',
    '    m.xp = rules::uadrowRowXpLo(t, i);',
    '    m.gp = rules::uadrowRowGpLo(t, i);',
    '    m.category = carrier;',
    '    return m;',
    '}',
    '',
    '// The UA-mode determination: the',
    '// category band, then the split - the',
    '// low band rolls the new UA table,',
    '// the high band the DMG original.',
    '// Misc magic carries no split - the',
    '// seven sub-tables are all UA.',
    'static MagicItem rollMagicItemUa(',
    '        rules::Dice& dice) {',
    '    int c = rollCategoryUa(dice);',
    '    int carrier = uaCategoryToDmg(c);',
    '    if (c == 4) {',
    '        int r = 1 + d100(dice);',
    '        int t =',
    '            8 + rules::uadsMiscSubCount() - 1;',
    '        for (int i = 0;',
    '             i < rules::uadsMiscSubCount();',
    '             ++i)',
    '            if (r',
    '                    >= rules::uadsMiscSubLo(i)',
    '                    && r',
    '                    <= rules::uadsMiscSubHi(i)) {',
    '                t = 8 + i;',
    '                break;',
    '            }',
    '        return rollFromUaTable(dice, t,',
    '                               carrier);',
    '    }',
    '    int r2 = 1 + d100(dice);',
    '    if (r2 <= uaSplitLo(c))',
    '        return rollFromUaTable(',
    '            dice, uaPrimaryTable(c),',
    '            carrier);',
    '    return rollFromCategory(dice,',
    '                            carrier);',
    '}',
    '',
    '// MERGED: the union read - both',
    '// table sets live; a per-item coin',
    '// flip picks the set (playtesting',
    '// sees both).',
    'static MagicItem rollMagicItemMerged(',
    '        rules::Dice& dice) {',
    '    if (d100(dice) < 50)',
    '        return rollMagicItemUa(dice);',
    '    return rollFromCategory(dice,',
    '                            rollCategory(dice));',
    '}',
    '',
    'MagicItem rollMagicItem(rules::Dice& dice) {',
    '    // R402: the dial governs the',
    '    // dispatch; the DMG default keeps',
    '    // the landed audits authoritative',
    '    int mode = rules::uatdMode();',
    '    if (mode == rules::uatdModeUa())',
    '        return rollMagicItemUa(dice);',
    '    if (mode == rules::uatdModeMerged())',
    '        return rollMagicItemMerged(dice);',
    '    return rollFromCategory(dice,',
    '                            rollCategory(dice));',
    '}'),
    'treasure: the dial dispatch')

# ========= (d) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT, E(
    '            if (!uatdUaPinRoundsPending())',
    '                ++bad;',
    '            if (uatdTableSetCount() != 2) ++bad;'),
    E(
    '            // R402: the pin rounds',
    '            // landed - the pending',
    '            // pin flips',
    '            if (uatdUaPinRoundsPending())',
    '                ++bad;',
    '            if (uatdTableSetCount() != 2) ++bad;'),
    'regtest: the R374 pending flip')

pair(RT, E(
    '            if (!uatdRunBothDecided()) ++bad;',
    '            if (!uatdUaPinRoundsPending()) ++bad;',
    '        printf("R375 UA determination skeleton'
    ' pin audit: bad %d' + chr(92) + 'n", bad);'),
    E(
    '            if (!uatdRunBothDecided()) ++bad;',
    '            // R402: the pin rounds',
    '            // landed - the pending',
    '            // pin flips',
    '            if (uatdUaPinRoundsPending()) ++bad;',
    '        printf("R375 UA determination skeleton'
    ' pin audit: bad %d' + chr(92) + 'n", bad);'),
    'regtest: the R375 pending flip')

AUD = E(
    '    // ---- R402: the UA treasure',
    '    // dial seam audit ----',
    '    // The R374 decision wires: the',
    '    // dial state (DMG the default,',
    '    // UA, MERGED), the UA-mode',
    '    // determination dispatch (the',
    '    // R375/R395 data rides the',
    '    // engine roller - the category',
    '    // bands, the sub-table splits,',
    '    // the misc seven sub-bands, the',
    '    // row resolution), and the',
    '    // MERGED union read. The DMG',
    '    // audits stay authoritative',
    '    // (the default mode); census',
    '    // 328 -> 329.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the dial state ----',
    '        if (uatdMode() != uatdModeDmg()) ++bad;',
    '        if (strcmp(uatdModeName(0),',
    '                   "DMG") != 0) ++bad;',
    '        if (strcmp(uatdModeName(1),',
    '                   "UA") != 0) ++bad;',
    '        if (strcmp(uatdModeName(2),',
    '                   "MERGED") != 0) ++bad;',
    '        if (!uatdModeValid(0)',
    '                || !uatdModeValid(2)) ++bad;',
    '        if (uatdModeValid(3)',
    '                || uatdModeValid(-1)) ++bad;',
    '        uatdSetMode(uatdModeUa());',
    '        if (uatdMode() != uatdModeUa()) ++bad;',
    '        uatdSetMode(99);',
    '        if (uatdMode() != uatdModeDmg()) ++bad;',
    '        if (uatdUaPinRoundsPending()) ++bad;',
    '        if (!uatdDialLanded()) ++bad;',
    '        // ---- the UA row data ----',
    '        // every table covers 01-00',
    '        // contiguously (the band walk)',
    '        for (int t = 0;',
    '             t < uadrowTableCount(); ++t) {',
    '            if (uadrowRowLo(t, 0) != 1) ++bad;',
    '            if (uadrowRowHi(t,',
    '                    uadrowRowCount(t) - 1)',
    '                    != 100) ++bad;',
    '            for (int i = 0;',
    '                 i + 1 < uadrowRowCount(t);',
    '                 ++i)',
    '                if (uadrowRowLo(t, i + 1)',
    '                        != uadrowRowHi(t, i) + 1)',
    '                    ++bad;',
    '        }',
    '        // the spot rows (the R395 pins)',
    '        if (strcmp(uadrowRowName(0, 0),',
    '                   "Animal Control") != 0) ++bad;',
    '        if (strcmp(uadrowRowName(17, 0),',
    '                   "Sword + 1") != 0) ++bad;',
    '        if (strcmp(uadrowRowName(6, 0),',
    '                   "Rod of Absorption") != 0)', '            ++bad;',
    '        if (strcmp(uadrowRowName(19, 0),',
    '                   "Arrow + 1, 2-24 in number")',
    '                != 0) ++bad;',
    '        // ---- the UA-mode dispatch ----',
    '        // statistical: every category',
    '        // serves, the misc always the',
    '        // UA sub-tables',
    '        rules::Rng rngUa(402);',
    '        rules::Dice diceUa(rngUa);',
    '        uatdSetMode(uatdModeUa());',
    '        int uaPot = 0, uaMisc = 0;',
    '        for (int i = 0; i < 20000; ++i) {',
    '            dm::treasure::MagicItem m =',
    '                dm::treasure::rollMagicItem(',
    '                    diceUa);',
    '            if (m.name.empty()',
    '                    || m.category < 0',
    '                    || m.category > 11) ++bad;',
    '            if (m.category == 0) ++uaPot;',
    '            if (m.category == 8) ++uaMisc;',
    '        }',
    '        if (uaPot == 0 || uaMisc == 0) ++bad;',
    '        // the potion band is 20 percent,',
    '        // the misc band 15 - loose',
    '        // bounds catch the routing',
    '        if (uaPot < 1000',
    '                || uaPot > 9000) ++bad;',
    '        if (uaMisc < 1000',
    '                || uaMisc > 9000) ++bad;',
    '        // ---- the MERGED union ----',
    '        rules::Rng rngM(403);',
    '        rules::Dice diceM(rngM);',
    '        uatdSetMode(uatdModeMerged());',
    '        for (int i = 0; i < 20000; ++i) {',
    '            dm::treasure::MagicItem m =',
    '                dm::treasure::rollMagicItem(',
    '                    diceM);',
    '            if (m.name.empty()',
    '                    || m.category < 0',
    '                    || m.category > 11) ++bad;',
    '        }',
    '        // ---- the DMG default restores ----',
    '        uatdSetMode(uatdModeDmg());',
    '        if (uatdMode() != uatdModeDmg()) ++bad;',
    '        printf("R402 UA treasure dial seam'
    ' audit: bad %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R402 audit block')

# ======== (e) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '- [ ] The treasure system dial - the',
    '      reconcile/reverse/run-both switch;',
    '      gates the treasure section.'),
    E(
    '- [x] The treasure system dial -',
    '      CLOSED R402 (the dial state in',
    '      rules/uatreasuredial.h; the UA',
    '      determination dispatch in',
    '      dm/treasure.cpp; the R402 seam',
    '      audit, census 329): the DMG',
    '      default, the UA revised tables',
    '      (the R375/R395 data rides the',
    '      roller - the category bands, the',
    '      sub-table splits, the misc seven',
    '      sub-bands, the row resolution),',
    '      the MERGED union read (a',
    '      per-item coin flip). The charge',
    '      (the hoard and trove assembly',
    '      riding the dial) follows; the',
    '      landed DMG audits stay',
    '      authoritative.'),
    'gap: the seam checkbox')

pair(GP, E(
    '      per-source precedent rides the',
    '      monster file format. The UA pin',
    '      rounds follow - the dial lands',
    '      first, the charge after.'),
    E(
    '      per-source precedent rides the',
    '      monster file format. The UA pin',
    '      rounds follow - the dial lands',
    '      first, the charge after.',
    '      - AMENDED R402: the dial lands -',
    '        the runtime mode state and the',
    '        UA-mode determination dispatch',
    '        ride (dm/treasure.cpp); the pin',
    '        rounds R375/R395/R397 feed the',
    '        roller; the charge follows.'),
    'gap: the R374 amendment')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 329:
    die('the census %d' % s.count('audit: bad'))
if s.count('R402 UA treasure dial'
           ' seam audit') != 1:
    die('the R402 audit label')
if s.count('uatdUaPinRoundsPending') != 3:
    die('the pending assert count %d'
        % s.count('uatdUaPinRoundsPending'))
if s.count('!uatdUaPinRoundsPending') != 0:
    die('the old pending form remains')
if s.count('if (uatdUaPinRoundsPending())') != 3:
    die('the pending flip count')
if s.count('uatdSetMode') < 5:
    die('the dial setter count %d'
        % s.count('uatdSetMode'))

p = rd(TD)
if p.count('inline') != 21:
    die('the dial inline count %d'
        % p.count('inline'))
if 'uatdDialLanded' not in p:
    die('the dial landed pin')
if not p.endswith(NL):
    die('the dial trailing newline')

t = rd(TR)
if t.count('rollMagicItemUa') != 3:
    die('the UA roller count %d'
        % t.count('rollMagicItemUa'))
if t.count('uadrowRowName') != 1:
    die('the row name count %d'
        % t.count('uadrowRowName'))
if t.count('rules/uatreasuredial.h') != 1:
    die('the dial include')

g = rd(GP)
if g.count('AMENDED R402') != 1:
    die('the gap amended count %d'
        % g.count('AMENDED R402'))
if g.count('CLOSED R402') != 1:
    die('the gap closed count %d'
        % g.count('CLOSED R402'))

for path, mark in ((TR, 'rollCategoryUa'),
                   (TD, 'uatdDialLanded'),
                   (SD, 'R401 landed')):
    if mark not in rd(path):
        die('%s carries no R402 seam' % path)

print('R402 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the treasure system dial seam')
print('  closes - the R374 decision wires:')
print('  the dial state, the UA-mode dispatch,')
print('  the MERGED union; census 328 -> 329')
print('commit: R402: the UA treasure system'
      ' dial (census 329)')

