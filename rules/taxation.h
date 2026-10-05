// ====================================================================
// Adnd1 - rules/taxation.h
// R207: the town taxation system (DMG p.90,
// DUTIES, EXCISES, FEES, TARIFFS, TAXES,
// TITHES, AND TOLLS) - the print worked
// example town, the money-sink machinery.
//
// Pure data + helpers, header-only (the
// grenade.h pattern: the caller owns the
// gate, the sale and the calendar; the
// rates and fines read here). The seven
// named tax kinds: duty (goods brought in
// for sale), excise (profession or
// currency changing), fee (any reason -
// gate entry), tariff (surtax on certain
// items), tax (residents), tithe
// (religious), toll (road, bridge, ferry).
// Conventions, named in place:
//   - Coin denominations: the domestic
//     copper cons, silver nobs, gold orbs
//     and platinum royals (the print).
//   - The gold-piece values: 1 copper =
//     1/100 gp, 1 silver = 1/10 gp - the
//     town-entry fee in gold pieces reads
//     0.01 per head for a citizen; the
//     helpers return COPPER/SILVER/GOLD
//     PIECE units, the caller converts.
//   - JUDGMENTs: the 24-hour money-changer
//     grace is the caller clock (the print
//     proof rule); the bribes beyond the
//     10 gp citizenship fee are the
//     print own words (plus many bribes) -
//     caller-side flavor.
// ====================================================================

#pragma once

namespace rules {

// -----------------------------------------------------------------------
// The import duty (normal goods brought in
// for sale): 1 percent for citizens, double
// rate - 2 percent - for foreigners.
// -----------------------------------------------------------------------
inline int taxImportDutyPercent(bool foreigner) {
    return foreigner ? 2 : 1;
}

// The luxury tariff (wine, spirits, furs,
// copper/gold metals, jewelry and the like),
// charged on the sale: 5 percent of value.
// No legal sale without the declaration -
// the caller gates the form.
inline int taxLuxuryTariffPercent() { return 5; }

// -----------------------------------------------------------------------
// The town entry fee (per head - man or
// animal - or wheel), in copper pieces:
// citizens 1, non-citizens 5. Official
// passports waive it; diplomatic types are
// immune on personal goods and belongings.
// -----------------------------------------------------------------------
inline int taxEntryFeeCopper(bool nonCitizen) {
    // R207b: true = the 5 cp non-citizen fee
    return nonCitizen ? 5 : 1;
}

// -----------------------------------------------------------------------
// The annual head tax by social standing,
// in the named coin: a peasant 1 copper, a
// freeman 1 silver, a gentleman or noble 1
// gold. Foreign residents are stopped for
// proof and pay again without it.
// -----------------------------------------------------------------------
enum TaxStanding { TAXS_PEASANT = 0, TAXS_FREEMAN,
                   TAXS_GENTLEMAN_NOBLE };

inline int taxHeadTaxAnnual(int standing) {
    // the coin unit: 1 = copper, 10 = silver
    // (a copper-of-value tenfold), 100 = gold
    static const int k[3] = { 1, 10, 100 };
    if (standing < TAXS_PEASANT) standing = TAXS_PEASANT;
    if (standing > TAXS_GENTLEMAN_NOBLE)
        standing = TAXS_GENTLEMAN_NOBLE;
    return k[standing];
}

// The foreigner sales tax: 10 percent on
// sales, no service tax levied on them.
inline int taxForeignerSalesTaxPercent() { return 10; }
inline int taxForeignerServiceTaxPercent() { return 0; }

// The tithe pledge: religious services
// require the pledge - the percent is the
// caller denomination (the print leaves it
// to the organization).
inline bool taxTithePledgeRequired() { return true; }

// The annual property tax on citizens:
// 5 percent of property value.
inline int taxPropertyTaxPercent() { return 5; }

// Citizenship: one month of residence plus
// 10 gold pieces.
inline int taxCitizenshipResidenceDays() { return 30; }
inline int taxCitizenshipFeeGold() { return 10; }

// -----------------------------------------------------------------------
// Foreign currency: merchants holding
// foreign coin pay a fine of 5 percent of
// its value and face confiscation. The
// Street of the Money Changers pays 90
// percent exchange - 10 foreign coppers
// bring 9 domestic. A non-resident holding
// more than 100 silver nobles of foreign
// coin is fined 50 percent of total value
// unless within 24 hours of entry and bound
// for the changers. Gems carry a 10 percent
// surtax on sale or exchange.
// -----------------------------------------------------------------------
inline int taxForeignCoinMerchantFinePercent() { return 5; }
inline int taxExchangeRatePercent() { return 90; }
inline int taxForeignCoinLimitSilverNobles() { return 100; }
inline int taxForeignCoinOverLimitFinePercent() { return 50; }
inline int taxMoneyChangerGraceHours() { return 24; }
inline int taxGemSurtaxPercent() { return 10; }

// The exchange: foreign value times 90
// percent, in domestic coin.
inline int taxExchangeDomestic(int foreignValue) {
    return foreignValue * taxExchangeRatePercent() / 100;
}

// The over-limit fine: does it apply? Over
// 100 silver nobles of foreign coin, unless
// within the grace hours and bound for the
// changers (the caller holds the clock and
// the direction).
inline bool taxForeignCoinFineApplies(
        int foreignSilverNobles,
        int hoursSinceEntry,
        bool headedToChangers) {
    if (foreignSilverNobles <= taxForeignCoinLimitSilverNobles())
        return false;
    if (hoursSinceEntry <= taxMoneyChangerGraceHours()
            && headedToChangers)
        return false;
    return true;
}

// -----------------------------------------------------------------------
// Tolls: paid for road, bridge or ferry use
// by persons, animals, carts, wagons and
// materials. Byway evasion: confiscation of
// all goods, with fine and imprisonment
// possible.
// -----------------------------------------------------------------------
inline bool taxTollEvasionConfiscates() { return true; }
inline bool taxTollEvasionImprisons() { return true; }

} // namespace rules
