// R-refactor: split from taxation.h - definitions
#include "rules/dmg/taxation.h"

int Taxation::taxImportDutyPercent(bool foreigner) {
    return foreigner ? 2 : 1;
}

int Taxation::taxLuxuryTariffPercent() { return 5; }

int Taxation::taxEntryFeeCopper(bool nonCitizen) {
    // R207b: true = the 5 cp non-citizen fee
    return nonCitizen ? 5 : 1;
}

int Taxation::taxHeadTaxAnnual(int standing) {
    // the coin unit: 1 = copper, 10 = silver
    // (a copper-of-value tenfold), 100 = gold
    static const int k[3] = { 1, 10, 100 };
    if (standing < TAXS_PEASANT) standing = TAXS_PEASANT;
    if (standing > TAXS_GENTLEMAN_NOBLE)
        standing = TAXS_GENTLEMAN_NOBLE;
    return k[standing];
}

int Taxation::taxForeignerSalesTaxPercent() { return 10; }

int Taxation::taxForeignerServiceTaxPercent() { return 0; }

bool Taxation::taxTithePledgeRequired() { return true; }

int Taxation::taxPropertyTaxPercent() { return 5; }

int Taxation::taxCitizenshipResidenceDays() { return 30; }

int Taxation::taxCitizenshipFeeGold() { return 10; }

int Taxation::taxForeignCoinMerchantFinePercent() { return 5; }

int Taxation::taxExchangeRatePercent() { return 90; }

int Taxation::taxForeignCoinLimitSilverNobles() { return 100; }

int Taxation::taxForeignCoinOverLimitFinePercent() { return 50; }

int Taxation::taxMoneyChangerGraceHours() { return 24; }

int Taxation::taxGemSurtaxPercent() { return 10; }

int Taxation::taxExchangeDomestic(int foreignValue) {
    return foreignValue * taxExchangeRatePercent() / 100;
}

bool Taxation::taxForeignCoinFineApplies( int foreignSilverNobles, int hoursSinceEntry, bool headedToChangers) {
    if (foreignSilverNobles <= taxForeignCoinLimitSilverNobles())
        return false;
    if (hoursSinceEntry <= taxMoneyChangerGraceHours()
            && headedToChangers)
        return false;
    return true;
}

bool Taxation::taxTollEvasionConfiscates() { return true; }

bool Taxation::taxTollEvasionImprisons() { return true; }
