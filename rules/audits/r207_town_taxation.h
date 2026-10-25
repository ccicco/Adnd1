    // ---- R207: the town taxation audit ----
    // DMG p.90: the worked example town - the
    // import duty, the luxury tariff, the entry
    // fee, the head tax, the foreigner sales
    // tax, the property tax, citizenship, the
    // foreign-coin fines and exchange rate,
    // the gem surtax and the toll-evasion
    // penalties.
    {
        int bad = 0;
        // the import duty: 1 percent, doubled for
        // foreigners
        if (rules::taxImportDutyPercent(false) != 1 ||
            rules::taxImportDutyPercent(true) != 2) ++bad;
        // the luxury tariff: 5 percent on sale
        if (rules::taxLuxuryTariffPercent() != 5) ++bad;
        // the entry fee: 1 copper a citizen, 5 a
        // non-citizen, per head or wheel
        if (rules::taxEntryFeeCopper(false) != 1 ||
            rules::taxEntryFeeCopper(true) != 5) ++bad;
        // the annual head tax: 1 copper a peasant,
        // 1 silver a freeman, 1 gold a gentleman or
        // noble (the coin units 1/10/100)
        if (rules::taxHeadTaxAnnual(rules::TAXS_PEASANT) != 1 ||
            rules::taxHeadTaxAnnual(rules::TAXS_FREEMAN) != 10 ||
            rules::taxHeadTaxAnnual(
                rules::TAXS_GENTLEMAN_NOBLE) != 100) ++bad;
        // the foreigner sales tax: 10 percent, no
        // service tax on them
        if (rules::taxForeignerSalesTaxPercent() != 10 ||
            rules::taxForeignerServiceTaxPercent() != 0)
            ++bad;
        // the tithe pledge and the property tax
        if (!rules::taxTithePledgeRequired() ||
            rules::taxPropertyTaxPercent() != 5) ++bad;
        // citizenship: one month plus 10 gold
        if (rules::taxCitizenshipResidenceDays() != 30 ||
            rules::taxCitizenshipFeeGold() != 10) ++bad;
        // foreign coin: the merchant fine 5 percent,
        // the 90 percent exchange, the 100-noble
        // limit, the 50 percent over-limit fine,
        // the 24-hour grace, the 10 percent gem
        // surtax
        if (rules::taxForeignCoinMerchantFinePercent() != 5 ||
            rules::taxExchangeRatePercent() != 90 ||
            rules::taxForeignCoinLimitSilverNobles() != 100 ||
            rules::taxForeignCoinOverLimitFinePercent() != 50 ||
            rules::taxMoneyChangerGraceHours() != 24 ||
            rules::taxGemSurtaxPercent() != 10) ++bad;
        // the exchange arithmetic: 10 foreign
        // coppers bring 9 domestic; 100 bring 90
        if (rules::taxExchangeDomestic(10) != 9 ||
            rules::taxExchangeDomestic(100) != 90 ||
            rules::taxExchangeDomestic(1) != 0) ++bad;
        // the over-limit fine: over 100 nobles is
        // fined unless within 24 hours and bound for
        // the changers; at or under the limit never;
        // over the limit with the grace and the
        // direction is spared
        if (!rules::taxForeignCoinFineApplies(
                101, 25, true)) ++bad;
        if (rules::taxForeignCoinFineApplies(
                100, 25, true)) ++bad;
        if (rules::taxForeignCoinFineApplies(
                101, 24, true)) ++bad;
        if (!rules::taxForeignCoinFineApplies(
                101, 24, false)) ++bad;
        if (!rules::taxForeignCoinFineApplies(
                101, 25, false)) ++bad;
        // toll evasion: confiscation, fine and
        // imprisonment possible
        if (!rules::taxTollEvasionConfiscates() ||
            !rules::taxTollEvasionImprisons()) ++bad;
        printf("R207 town taxation audit: bad %d\n", bad);
        if (bad) return 1;
    }
