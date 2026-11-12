    // ---- R258: the III.E misc magic explanation prose part 2 pins audit ----
    // part2 lines 5-66 - Bag of Holding through
    // Book of Exalted Deeds, global = 11065 +
    // part2 line; no page headers inside the
    // slice.
    {
        Miscmagic_bag_of_holding_to_book_of_exalted_deeds miscmagic_bag_of_holding_to_book_of_exalted_deeds;
        Miscmagic_table1_footnotes miscmagic_table1_footnotes;
        int bad = 0;
        // the six items are the engine kMisc1 rows
        // 10-15 (the R225 m1 band pins); the
        // Exalted (C) class mark is row 15, the
        // Boat row 14 is the negative control
        if (miscmagic_table1_footnotes.m1RowCount() != 33) ++bad;
        static const int kM1Lo[6] = {
            22, 27, 28, 30, 32, 33,
        };
        static const int kM1Hi[6] = {
            26, 27, 29, 31, 32, 33,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic_table1_footnotes.m1RowLo(10 + i) != kM1Lo[i] ||
                miscmagic_table1_footnotes.m1RowHi(10 + i) != kM1Hi[i]) ++bad;
        if (miscmagic_table1_footnotes.m1UsableByCleric(15) != 1 ||
            miscmagic_table1_footnotes.m1UsableByCleric(14) != 0) ++bad;
        // the bag of holding: the 4 quality rows
        if (miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpHoldingSackShortSideFeet() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpHoldingSackLongSideFeet() != 4 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpHoldingRowCount() != 4 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpHoldingRuptureCauseCount() != 2) ++bad;
        static const int kHoldingLo[4] = {
            1, 31, 71, 91,
        };
        static const int kHoldingHi[4] = {
            30, 70, 90, 100,
        };
        static const int kHoldingWeight[4] = {
            15, 15, 35, 60,
        };
        static const int kHoldingWeightLimit[4] = {
            250, 500, 1000, 1500,
        };
        static const int kHoldingVolume[4] = {
            30, 70, 150, 250,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpHoldingRowLo(i) != kHoldingLo[i] ||
                miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpHoldingRowHi(i) != kHoldingHi[i] ||
                miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpHoldingRowWeightPounds(i) !=
                    kHoldingWeight[i] ||
                miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpHoldingRowWeightLimitPounds(i) !=
                    kHoldingWeightLimit[i] ||
                miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpHoldingRowVolumeLimitCubicFeet(i) !=
                    kHoldingVolume[i]) ++bad;
        // the bag of transmuting
        if (miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTransmutingDisguiseQualityCount() != 4 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTransmutingProperUsesMin() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTransmutingProperUsesMax() != 5 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTransmutingTransmuteKindCount() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTransmutingItemBaseMaterialCount() != 3 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTransmutingExemptKindCount() != 2) ++bad;
        // the bag of tricks: the animal stat columns
        // are mangled in the upload - the type bands
        // and counts are pinned, the stats are not
        // (the R256 lesson)
        if (miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksTossMinFeet() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksTossMaxFeet() != 20 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksTypeDieSides() != 10 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksTypeCount() != 3 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksAnimalsPerType() != 8 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksAnimalDieMin() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksAnimalDieMax() != 8 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksDrawnAtOnceMax() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksDurationTurns() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksEndConditionCount() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksTypeRollCount() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksWeeklyDrawMax() != 10) ++bad;
        static const int kTricksTypeLo[3] = {
            1, 6, 9,
        };
        static const int kTricksTypeHi[3] = {
            5, 8, 100,
        };
        for (int i = 0; i < 3; ++i)
            if (miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksTypeLo(i) != kTricksTypeLo[i] ||
                miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpTricksTypeHi(i) != kTricksTypeHi[i]) ++bad;
        // the beaker of plentiful potions
        if (miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerDoseMin() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerDoseMax() != 5 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerPotionCountMin() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerPotionCountMax() != 5 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerCountDieSides() != 4 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerCountDiePlus() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerPourRounds() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerPourDoses() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerBadTypeCount() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerMonthlyTypeLoss() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerDispenseRowMin() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerDispenseRowMax() != 5) ++bad;
        static const int kBeakerPerDay[4] = {
            1, 1, 0, 0,
        };
        static const int kBeakerPerWeek[4] = {
            3, 2, 1, 1,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerPerDayByCount(i) !=
                    kBeakerPerDay[i] ||
                miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBeakerPerWeekByCount(i) !=
                    kBeakerPerWeek[i]) ++bad;
        // the boat, folding
        if (miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatBoxLengthInches() != 12 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatBoxWidthInches() != 6 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatBoxDepthInches() != 6 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatLengthFeet() != 10 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatWidthFeet() != 4 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatDepthFeet() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatShipLengthFeet() != 24 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatShipWidthFeet() != 8 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatShipDepthFeet() != 6 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatOarPairs() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatComponentCount() != 4 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatShipOarSets() != 5 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatShipComponentCount() != 7 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatPersonsMin() != 3 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatPersonsMax() != 4 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatShipPersons() != 15 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpBoatCommandWordCount() != 3) ++bad;
        // the book of exalted deeds
        if (miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedReadingWeeks() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedWisdomGain() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedHalfwayPct() != 50 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedNeutralXpLossMin() != 20000 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedNeutralXpLossMax() != 80000 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedLevelFloor() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedEvilLevelLoss() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedAtonementPct() != 50 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedAtonementAdventuresMin() != 2 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedAtonementAdventuresMax() != 5 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedMuIntLoss() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedMuSaveXpLossMin() != 2000 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedMuSaveXpLossMax() != 20000 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedThiefHpMin() != 5 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedThiefHpMax() != 30 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedThiefDexLoss() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedThiefConvertPctMin() != 10 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedThiefConvertPctMax() != 60 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedThiefConvertWisReq() != 15 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedAssassinHpMin() != 5 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedAssassinHpMax() != 40 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedVanishesAfterPerusal() != 1 ||
            miscmagic_bag_of_holding_to_book_of_exalted_deeds.mmpExaltedMaxBenefitTimes() != 1) ++bad;
        printf("R258 misc magic prose part 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
