// ====================================================================
// Adnd1 - rules/dmg/taxation.h
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



// -----------------------------------------------------------------------
// The annual head tax by social standing,
// in the named coin: a peasant 1 copper, a
// freeman 1 silver, a gentleman or noble 1
// gold. Foreign residents are stopped for
// proof and pay again without it.
// -----------------------------------------------------------------------
enum TaxStanding { TAXS_PEASANT = 0, TAXS_FREEMAN,
                   TAXS_GENTLEMAN_NOBLE };

// R-refactor: namespace rules -> class Taxation (instance methods)
class Taxation {
public:


// -----------------------------------------------------------------------
// The import duty (normal goods brought in
// for sale): 1 percent for citizens, double
// rate - 2 percent - for foreigners.
// -----------------------------------------------------------------------
    int taxImportDutyPercent(bool foreigner);


// The luxury tariff (wine, spirits, furs,
// copper/gold metals, jewelry and the like),
// charged on the sale: 5 percent of value.
// No legal sale without the declaration -
// the caller gates the form.
    int taxLuxuryTariffPercent();


// -----------------------------------------------------------------------
// The town entry fee (per head - man or
// animal - or wheel), in copper pieces:
// citizens 1, non-citizens 5. Official
// passports waive it; diplomatic types are
// immune on personal goods and belongings.
// -----------------------------------------------------------------------
    int taxEntryFeeCopper(bool nonCitizen);
    int taxHeadTaxAnnual(int standing);


// The foreigner sales tax: 10 percent on
// sales, no service tax levied on them.
    int taxForeignerSalesTaxPercent();
    int taxForeignerServiceTaxPercent();


// The tithe pledge: religious services
// require the pledge - the percent is the
// caller denomination (the print leaves it
// to the organization).
    bool taxTithePledgeRequired();


// The annual property tax on citizens:
// 5 percent of property value.
    int taxPropertyTaxPercent();


// Citizenship: one month of residence plus
// 10 gold pieces.
    int taxCitizenshipResidenceDays();
    int taxCitizenshipFeeGold();


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
    int taxForeignCoinMerchantFinePercent();
    int taxExchangeRatePercent();
    int taxForeignCoinLimitSilverNobles();
    int taxForeignCoinOverLimitFinePercent();
    int taxMoneyChangerGraceHours();
    int taxGemSurtaxPercent();


// The exchange: foreign value times 90
// percent, in domestic coin.
    int taxExchangeDomestic(int foreignValue);


// The over-limit fine: does it apply? Over
// 100 silver nobles of foreign coin, unless
// within the grace hours and bound for the
// changers (the caller holds the clock and
// the direction).
    bool taxForeignCoinFineApplies( int foreignSilverNobles, int hoursSinceEntry, bool headedToChangers);


// -----------------------------------------------------------------------
// Tolls: paid for road, bridge or ferry use
// by persons, animals, carts, wagons and
// materials. Byway evasion: confiscation of
// all goods, with fine and imprisonment
// possible.
// -----------------------------------------------------------------------
    bool taxTollEvasionConfiscates();
    bool taxTollEvasionImprisons();
};
