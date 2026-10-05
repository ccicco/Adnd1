#!/usr/bin/env python3
# R207 splice: the town taxation system (DMG p.90,
# DUTIES, EXCISES, FEES, TARIFFS, TAXES, TITHES,
# AND TOLLS) - the print's worked example town,
# a seam with zero prior coverage: nothing in
# rules/ or dm/ touches duties, excises, fees,
# tariffs, taxes, tithes or tolls, and neither
# gap report mentions the section. The print
# first names and defines the seven tax kinds
# (duty on goods brought in, excise on
# profession or currency changing, fee for any
# reason - city-gate entry a good one, tariff
# as a surtax on certain items, tax on
# residents, tithe the religious levy, toll
# for road/bridge/ferry use), then gives the
# example system this round pins:
#   - rules/taxation.h (new file, the
#     grenade.h pattern: pure data + helpers,
#     header-only)
#   - the import duty: 1 percent on normal
#     goods brought in for sale, 2 percent
#     for foreigners (double rate)
#   - the luxury tariff: 5 percent of value
#     on wine, spirits, furs, copper/gold
#     metals, jewelry and the like, charged
#     when sold (the sale form: no legal sale
#     without declaring)
#   - the entry fee: 1 copper per head (man
#     or animal) or wheel for citizens,
#     5 coppers for non-citizens; official
#     passports waive it; diplomatic types
#     are immune on personal goods
#   - the annual head tax: 1 copper a
#     peasant, 1 silver a freeman, 1 gold a
#     gentleman or noble; foreign residents
#     stopped for proof, paying again if
#     without it
#   - the 10 percent sales tax on foreigners
#     (no service tax on them)
#   - the tithe pledge for religious services
#   - the annual 5 percent property tax on
#     citizens
#   - citizenship: one month residence plus
#     10 gold pieces (plus many bribes)
#   - foreign currency: merchants fined 5
#     percent of value held plus confiscation;
#     the money changers pay 90 percent
#     exchange (10 foreign copper bring 9
#     domestic); a non-resident holding over
#     100 silver nobles of foreign coin is
#     fined 50 percent unless within 24
#     hours of entry and bound for the
#     changers; gems carry a 10 percent
#     surtax on sale or exchange
#   - toll evasion: byway users face
#     confiscation of all goods, with fine
#     and imprisonment possible
#   - the regtest include + the R207 audit
#   - the gap-report log entry rides this
#     commit (the R202 convention)
# Patches: 4 (taxation.h, regtest include,
# regtest audit, dmg_gap_report.md). Census
# 122 -> 123.

BS = chr(92)
NL = chr(10)

applied = 0
already = 0


def rd(p):
    with open(p, 'r') as f:
        return f.read()


def wr(p, s):
    with open(p, 'w') as f:
        f.write(s)


def patch(path, marker, old, new):
    # in-place marker patch; old must be unique
    global applied, already
    t = rd(path)
    if marker in t:
        already += 1
        return
    assert marker not in t, 'marker must be absent pre-patch: ' + marker
    assert t.count(old) == 1, 'anchor not unique in ' + path + ': ' + marker
    t = t.replace(old, new)
    assert marker in t, 'marker missing post-patch in ' + path
    assert NL not in marker, 'marker spans a newline: ' + marker
    wr(path, t)
    applied += 1


def newfile(path, marker, text):
    # create-only patch; the file must not exist pre-patch
    global applied, already
    import os
    if os.path.exists(path):
        t = rd(path)
        assert marker in t, 'existing file lacks the marker: ' + path
        already += 1
        return
    assert marker in text, 'marker missing from the new text: ' + marker
    wr(path, text)
    applied += 1


# ---------------------------------------------------------------------------
# Patch 1: rules/taxation.h (new file)
# ---------------------------------------------------------------------------

h = [
    '// ====================================================================',
    '// Adnd1 - rules/taxation.h',
    '// R207: the town taxation system (DMG p.90,',
    '// DUTIES, EXCISES, FEES, TARIFFS, TAXES,',
    '// TITHES, AND TOLLS) - the print worked',
    '// example town, the money-sink machinery.',
    '//',
    '// Pure data + helpers, header-only (the',
    '// grenade.h pattern: the caller owns the',
    '// gate, the sale and the calendar; the',
    '// rates and fines read here). The seven',
    '// named tax kinds: duty (goods brought in',
    '// for sale), excise (profession or',
    '// currency changing), fee (any reason -',
    '// gate entry), tariff (surtax on certain',
    '// items), tax (residents), tithe',
    '// (religious), toll (road, bridge, ferry).',
    '// Conventions, named in place:',
    '//   - Coin denominations: the domestic',
    '//     copper cons, silver nobs, gold orbs',
    '//     and platinum royals (the print).',
    '//   - The gold-piece values: 1 copper =',
    '//     1/100 gp, 1 silver = 1/10 gp - the',
    '//     town-entry fee in gold pieces reads',
    '//     0.01 per head for a citizen; the',
    '//     helpers return COPPER/SILVER/GOLD',
    '//     PIECE units, the caller converts.',
    '//   - JUDGMENTs: the 24-hour money-changer',
    '//     grace is the caller clock (the print',
    '//     proof rule); the bribes beyond the',
    '//     10 gp citizenship fee are the',
    '//     print own words (plus many bribes) -',
    '//     caller-side flavor.',
    '// ====================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// -----------------------------------------------------------------------',
    '// The import duty (normal goods brought in',
    '// for sale): 1 percent for citizens, double',
    '// rate - 2 percent - for foreigners.',
    '// -----------------------------------------------------------------------',
    'inline int taxImportDutyPercent(bool foreigner) {',
    '    return foreigner ? 2 : 1;',
    '}',
    '',
    '// The luxury tariff (wine, spirits, furs,',
    '// copper/gold metals, jewelry and the like),',
    '// charged on the sale: 5 percent of value.',
    '// No legal sale without the declaration -',
    '// the caller gates the form.',
    'inline int taxLuxuryTariffPercent() { return 5; }',
    '',
    '// -----------------------------------------------------------------------',
    '// The town entry fee (per head - man or',
    '// animal - or wheel), in copper pieces:',
    '// citizens 1, non-citizens 5. Official',
    '// passports waive it; diplomatic types are',
    '// immune on personal goods and belongings.',
    '// -----------------------------------------------------------------------',
    'inline int taxEntryFeeCopper(bool citizen) {',
    '    return citizen ? 1 : 5;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// The annual head tax by social standing,',
    '// in the named coin: a peasant 1 copper, a',
    '// freeman 1 silver, a gentleman or noble 1',
    '// gold. Foreign residents are stopped for',
    '// proof and pay again without it.',
    '// -----------------------------------------------------------------------',
    'enum TaxStanding { TAXS_PEASANT = 0, TAXS_FREEMAN,',
    '                   TAXS_GENTLEMAN_NOBLE };',
    '',
    'inline int taxHeadTaxAnnual(int standing) {',
    '    // the coin unit: 1 = copper, 10 = silver',
    '    // (a copper-of-value tenfold), 100 = gold',
    '    static const int k[3] = { 1, 10, 100 };',
    '    if (standing < TAXS_PEASANT) standing = TAXS_PEASANT;',
    '    if (standing > TAXS_GENTLEMAN_NOBLE)',
    '        standing = TAXS_GENTLEMAN_NOBLE;',
    '    return k[standing];',
    '}',
    '',
    '// The foreigner sales tax: 10 percent on',
    '// sales, no service tax levied on them.',
    'inline int taxForeignerSalesTaxPercent() { return 10; }',
    'inline int taxForeignerServiceTaxPercent() { return 0; }',
    '',
    '// The tithe pledge: religious services',
    '// require the pledge - the percent is the',
    '// caller denomination (the print leaves it',
    '// to the organization).',
    'inline bool taxTithePledgeRequired() { return true; }',
    '',
    '// The annual property tax on citizens:',
    '// 5 percent of property value.',
    'inline int taxPropertyTaxPercent() { return 5; }',
    '',
    '// Citizenship: one month of residence plus',
    '// 10 gold pieces.',
    'inline int taxCitizenshipResidenceDays() { return 30; }',
    'inline int taxCitizenshipFeeGold() { return 10; }',
    '',
    '// -----------------------------------------------------------------------',
    '// Foreign currency: merchants holding',
    '// foreign coin pay a fine of 5 percent of',
    '// its value and face confiscation. The',
    '// Street of the Money Changers pays 90',
    '// percent exchange - 10 foreign coppers',
    '// bring 9 domestic. A non-resident holding',
    '// more than 100 silver nobles of foreign',
    '// coin is fined 50 percent of total value',
    '// unless within 24 hours of entry and bound',
    '// for the changers. Gems carry a 10 percent',
    '// surtax on sale or exchange.',
    '// -----------------------------------------------------------------------',
    'inline int taxForeignCoinMerchantFinePercent() { return 5; }',
    'inline int taxExchangeRatePercent() { return 90; }',
    'inline int taxForeignCoinLimitSilverNobles() { return 100; }',
    'inline int taxForeignCoinOverLimitFinePercent() { return 50; }',
    'inline int taxMoneyChangerGraceHours() { return 24; }',
    'inline int taxGemSurtaxPercent() { return 10; }',
    '',
    '// The exchange: foreign value times 90',
    '// percent, in domestic coin.',
    'inline int taxExchangeDomestic(int foreignValue) {',
    '    return foreignValue * taxExchangeRatePercent() / 100;',
    '}',
    '',
    '// The over-limit fine: does it apply? Over',
    '// 100 silver nobles of foreign coin, unless',
    '// within the grace hours and bound for the',
    '// changers (the caller holds the clock and',
    '// the direction).',
    'inline bool taxForeignCoinFineApplies(',
    '        int foreignSilverNobles,',
    '        int hoursSinceEntry,',
    '        bool headedToChangers) {',
    '    if (foreignSilverNobles <= taxForeignCoinLimitSilverNobles())',
    '        return false;',
    '    if (hoursSinceEntry <= taxMoneyChangerGraceHours()',
    '            && headedToChangers)',
    '        return false;',
    '    return true;',
    '}',
    '',
    '// -----------------------------------------------------------------------',
    '// Tolls: paid for road, bridge or ferry use',
    '// by persons, animals, carts, wagons and',
    '// materials. Byway evasion: confiscation of',
    '// all goods, with fine and imprisonment',
    '// possible.',
    '// -----------------------------------------------------------------------',
    'inline bool taxTollEvasionConfiscates() { return true; }',
    'inline bool taxTollEvasionImprisons() { return true; }',
    '',
    '} // namespace rules',
    '',
]

newfile('rules/taxation.h',
        'R207: the town taxation system (DMG p.90,',
        NL.join(h))

# ---------------------------------------------------------------------------
# Patch 2: regtest.cpp - the include
# ---------------------------------------------------------------------------

old2 = ('#include "rules/pursuit.h"  // R206: pp.67-69 pursuit and evasion'
        + NL + '#include <cstdio>')

new2 = ('#include "rules/pursuit.h"  // R206: pp.67-69 pursuit and evasion'
        + NL + '#include "rules/taxation.h"  // R207: p.90 the town taxation system'
        + NL + '#include <cstdio>')

patch('regtest.cpp',
      'R207: p.90 the town taxation system',
      old2,
      new2)

# ---------------------------------------------------------------------------
# Patch 3: regtest.cpp - the R207 audit (after the R206 block)
# ---------------------------------------------------------------------------

aud = []
a = aud.append
a('    // ---- R207: the town taxation audit ----')
a('    // DMG p.90: the worked example town - the')
a('    // import duty, the luxury tariff, the entry')
a('    // fee, the head tax, the foreigner sales')
a('    // tax, the property tax, citizenship, the')
a('    // foreign-coin fines and exchange rate,')
a('    // the gem surtax and the toll-evasion')
a('    // penalties.')
a('    {')
a('        int bad = 0;')
a('        // the import duty: 1 percent, doubled for')
a('        // foreigners')
a('        if (rules::taxImportDutyPercent(false) != 1 ||')
a('            rules::taxImportDutyPercent(true) != 2) ++bad;')
a('        // the luxury tariff: 5 percent on sale')
a('        if (rules::taxLuxuryTariffPercent() != 5) ++bad;')
a('        // the entry fee: 1 copper a citizen, 5 a')
a('        // non-citizen, per head or wheel')
a('        if (rules::taxEntryFeeCopper(false) != 1 ||')
a('            rules::taxEntryFeeCopper(true) != 5) ++bad;')
a('        // the annual head tax: 1 copper a peasant,')
a('        // 1 silver a freeman, 1 gold a gentleman or')
a('        // noble (the coin units 1/10/100)')
a('        if (rules::taxHeadTaxAnnual(rules::TAXS_PEASANT) != 1 ||')
a('            rules::taxHeadTaxAnnual(rules::TAXS_FREEMAN) != 10 ||')
a('            rules::taxHeadTaxAnnual(')
a('                rules::TAXS_GENTLEMAN_NOBLE) != 100) ++bad;')
a('        // the foreigner sales tax: 10 percent, no')
a('        // service tax on them')
a('        if (rules::taxForeignerSalesTaxPercent() != 10 ||')
a('            rules::taxForeignerServiceTaxPercent() != 0)')
a('            ++bad;')
a('        // the tithe pledge and the property tax')
a('        if (!rules::taxTithePledgeRequired() ||')
a('            rules::taxPropertyTaxPercent() != 5) ++bad;')
a('        // citizenship: one month plus 10 gold')
a('        if (rules::taxCitizenshipResidenceDays() != 30 ||')
a('            rules::taxCitizenshipFeeGold() != 10) ++bad;')
a('        // foreign coin: the merchant fine 5 percent,')
a('        // the 90 percent exchange, the 100-noble')
a('        // limit, the 50 percent over-limit fine,')
a('        // the 24-hour grace, the 10 percent gem')
a('        // surtax')
a('        if (rules::taxForeignCoinMerchantFinePercent() != 5 ||')
a('            rules::taxExchangeRatePercent() != 90 ||')
a('            rules::taxForeignCoinLimitSilverNobles() != 100 ||')
a('            rules::taxForeignCoinOverLimitFinePercent() != 50 ||')
a('            rules::taxMoneyChangerGraceHours() != 24 ||')
a('            rules::taxGemSurtaxPercent() != 10) ++bad;')
a('        // the exchange arithmetic: 10 foreign')
a('        // coppers bring 9 domestic; 100 bring 90')
a('        if (rules::taxExchangeDomestic(10) != 9 ||')
a('            rules::taxExchangeDomestic(100) != 90 ||')
a('            rules::taxExchangeDomestic(1) != 0) ++bad;')
a('        // the over-limit fine: over 100 nobles is')
a('        // fined unless within 24 hours and bound for')
a('        // the changers; at or under the limit never;')
a('        // over the limit with the grace and the')
a('        // direction is spared')
a('        if (!rules::taxForeignCoinFineApplies(')
a('                101, 25, true)) ++bad;')
a('        if (rules::taxForeignCoinFineApplies(')
a('                100, 25, true)) ++bad;')
a('        if (rules::taxForeignCoinFineApplies(')
a('                101, 24, true)) ++bad;')
a('        if (!rules::taxForeignCoinFineApplies(')
a('                101, 24, false)) ++bad;')
a('        if (!rules::taxForeignCoinFineApplies(')
a('                101, 25, false)) ++bad;')
a('        // toll evasion: confiscation, fine and')
a('        // imprisonment possible')
a('        if (!rules::taxTollEvasionConfiscates() ||')
a('            !rules::taxTollEvasionImprisons()) ++bad;')
a('        printf("R207 town taxation audit: bad %d'
  + BS + 'n", bad);')
a('        if (bad) return 1;')
a('    }')

anchor = ('        printf("R206 pursuit and evasion audit: bad %d'
          + BS + 'n", bad);'
          + NL + '        if (bad) return 1;'
          + NL + '    }')

patch('regtest.cpp',
      'R207 town taxation audit',
      anchor,
      anchor + NL + NL.join(aud))

# ---------------------------------------------------------------------------
# Patch 4: tools/dmg_gap_report.md - the round-log entry (R202 convention)
# ---------------------------------------------------------------------------

entry = (
    'R207 landed the town taxation system (DMG'
    + NL + 'p.90, DUTIES, EXCISES, FEES, TARIFFS,'
    + NL + 'TAXES, TITHES, AND TOLLS) - the print'
    + NL + 'worked example town, a seam with zero'
    + NL + 'prior coverage. rules/taxation.h (the'
    + NL + 'grenade.h pattern): the seven named tax'
    + NL + 'kinds defined in place; the import duty'
    + NL + '(1 percent, doubled for foreigners),'
    + NL + 'the 5 percent luxury tariff, the entry'
    + NL + 'fee (1 copper a citizen, 5 a'
    + NL + 'non-citizen, per head or wheel), the'
    + NL + 'annual head tax (1 copper a peasant, 1'
    + NL + 'silver a freeman, 1 gold a gentleman or'
    + NL + 'noble), the 10 percent foreigner sales'
    + NL + 'tax (no service tax on them), the tithe'
    + NL + 'pledge, the 5 percent annual property'
    + NL + 'tax, citizenship (one month plus 10'
    + NL + 'gold), foreign currency (the 5 percent'
    + NL + 'merchant fine, the 90 percent exchange -'
    + NL + '10 foreign coppers bring 9 domestic -'
    + NL + 'the 100-noble limit with the 50 percent'
    + NL + 'fine and the 24-hour changer grace, the'
    + NL + '10 percent gem surtax), and toll'
    + NL + 'evasion (confiscation, fine and'
    + NL + 'imprisonment possible). New R207 battery'
    + NL + 'audit; census 123. Next: the DMG-only'
    + NL + 'sweep continues.')

# the anchor is the R206 entry tail, verified
# against the file's actual line wraps (the
# R205/R206 lesson): census 122 wrap reads
# "battery audit; census 122. Next: the" /
# "DMG-only sweep continues."

log_old = ('battery audit; census 122. Next: the'
           + NL + 'DMG-only sweep continues.'
           + NL + NL + 'Categories:')

log_new = ('battery audit; census 122. Next: the'
           + NL + 'DMG-only sweep continues.'
           + NL + NL + entry + NL + NL + 'Categories:')

patch('tools/dmg_gap_report.md',
      'R207 landed the town taxation system',
      log_old,
      log_new)

# ---------------------------------------------------------------------------
# the tail (always prints)
# ---------------------------------------------------------------------------

assert applied + already == 4, 'patch count drift: ' + str(applied) + ' + ' + str(already)
print('R207 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R207 note: 4 patches; the town taxation system pinned - the duty,')
print('tariff, entry fee, head tax, sales tax, property tax, citizenship,')
print('foreign-coin and toll machinery; census 123.')
print('commit: R207: the town taxation system pinned - DMG p.90, the worked')
print('example town (census 123)')

