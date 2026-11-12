    // ---- R207: the town taxation audit ----
    // DMG p.90: the worked example town - the
    // import duty, the luxury tariff, the entry
    // fee, the head tax, the foreigner sales
    // tax, the property tax, citizenship, the
    // foreign-coin fines and exchange rate,
    // the gem surtax and the toll-evasion
    // penalties.
    {
        Taxation taxation;
        int bad = 0;
        // the import duty: 1 percent, doubled for
        // foreigners
        if (taxation.taxImportDutyPercent(false) != 1 ||
            taxation.taxImportDutyPercent(true) != 2) ++bad;
        // the luxury tariff: 5 percent on sale
        if (taxation.taxLuxuryTariffPercent() != 5) ++bad;
        // the entry fee: 1 copper a citizen, 5 a
        // non-citizen, per head or wheel
        if (taxation.taxEntryFeeCopper(false) != 1 ||
            taxation.taxEntryFeeCopper(true) != 5) ++bad;
        // the annual head tax: 1 copper a peasant,
        // 1 silver a freeman, 1 gold a gentleman or
        // noble (the coin units 1/10/100)
        if (taxation.taxHeadTaxAnnual(TAXS_PEASANT) != 1 ||
            taxation.taxHeadTaxAnnual(TAXS_FREEMAN) != 10 ||
            taxation.taxHeadTaxAnnual(
                TAXS_GENTLEMAN_NOBLE) != 100) ++bad;
        // the foreigner sales tax: 10 percent, no
        // service tax on them
        if (taxation.taxForeignerSalesTaxPercent() != 10 ||
            taxation.taxForeignerServiceTaxPercent() != 0)
            ++bad;
        // the tithe pledge and the property tax
        if (!taxation.taxTithePledgeRequired() ||
            taxation.taxPropertyTaxPercent() != 5) ++bad;
        // citizenship: one month plus 10 gold
        if (taxation.taxCitizenshipResidenceDays() != 30 ||
            taxation.taxCitizenshipFeeGold() != 10) ++bad;
        // foreign coin: the merchant fine 5 percent,
        // the 90 percent exchange, the 100-noble
        // limit, the 50 percent over-limit fine,
        // the 24-hour grace, the 10 percent gem
        // surtax
        if (taxation.taxForeignCoinMerchantFinePercent() != 5 ||
            taxation.taxExchangeRatePercent() != 90 ||
            taxation.taxForeignCoinLimitSilverNobles() != 100 ||
            taxation.taxForeignCoinOverLimitFinePercent() != 50 ||
            taxation.taxMoneyChangerGraceHours() != 24 ||
            taxation.taxGemSurtaxPercent() != 10) ++bad;
        // the exchange arithmetic: 10 foreign
        // coppers bring 9 domestic; 100 bring 90
        if (taxation.taxExchangeDomestic(10) != 9 ||
            taxation.taxExchangeDomestic(100) != 90 ||
            taxation.taxExchangeDomestic(1) != 0) ++bad;
        // the over-limit fine: over 100 nobles is
        // fined unless within 24 hours and bound for
        // the changers; at or under the limit never;
        // over the limit with the grace and the
        // direction is spared
        if (!taxation.taxForeignCoinFineApplies(
                101, 25, true)) ++bad;
        if (taxation.taxForeignCoinFineApplies(
                100, 25, true)) ++bad;
        if (taxation.taxForeignCoinFineApplies(
                101, 24, true)) ++bad;
        if (!taxation.taxForeignCoinFineApplies(
                101, 24, false)) ++bad;
        if (!taxation.taxForeignCoinFineApplies(
                101, 25, false)) ++bad;
        // toll evasion: confiscation, fine and
        // imprisonment possible
        if (!taxation.taxTollEvasionConfiscates() ||
            !taxation.taxTollEvasionImprisons()) ++bad;
        printf("R207 town taxation audit: bad %d\n", bad);
        if (bad) return 1;
    }
