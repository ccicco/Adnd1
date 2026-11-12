    // ---- R258: the III.E misc magic explanation prose part 2 pins audit ----
    // part2 lines 5-66 - Bag of Holding through
    // Book of Exalted Deeds, global = 11065 +
    // part2 line; no page headers inside the
    // slice.
    {
        Miscmagic_bag_of_holding_to_book_of_exalted_deeds miscmagic;
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
        if (miscmagic.mmpHoldingSackShortSideFeet() != 2 ||
            miscmagic.mmpHoldingSackLongSideFeet() != 4 ||
            miscmagic.mmpHoldingRowCount() != 4 ||
            miscmagic.mmpHoldingRuptureCauseCount() != 2) ++bad;
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
            if (miscmagic.mmpHoldingRowLo(i) != kHoldingLo[i] ||
                miscmagic.mmpHoldingRowHi(i) != kHoldingHi[i] ||
                miscmagic.mmpHoldingRowWeightPounds(i) !=
                    kHoldingWeight[i] ||
                miscmagic.mmpHoldingRowWeightLimitPounds(i) !=
                    kHoldingWeightLimit[i] ||
                miscmagic.mmpHoldingRowVolumeLimitCubicFeet(i) !=
                    kHoldingVolume[i]) ++bad;
        // the bag of transmuting
        if (miscmagic.mmpTransmutingDisguiseQualityCount() != 4 ||
            miscmagic.mmpTransmutingProperUsesMin() != 2 ||
            miscmagic.mmpTransmutingProperUsesMax() != 5 ||
            miscmagic.mmpTransmutingTransmuteKindCount() != 2 ||
            miscmagic.mmpTransmutingItemBaseMaterialCount() != 3 ||
            miscmagic.mmpTransmutingExemptKindCount() != 2) ++bad;
        // the bag of tricks: the animal stat columns
        // are mangled in the upload - the type bands
        // and counts are pinned, the stats are not
        // (the R256 lesson)
        if (miscmagic.mmpTricksTossMinFeet() != 1 ||
            miscmagic.mmpTricksTossMaxFeet() != 20 ||
            miscmagic.mmpTricksTypeDieSides() != 10 ||
            miscmagic.mmpTricksTypeCount() != 3 ||
            miscmagic.mmpTricksAnimalsPerType() != 8 ||
            miscmagic.mmpTricksAnimalDieMin() != 1 ||
            miscmagic.mmpTricksAnimalDieMax() != 8 ||
            miscmagic.mmpTricksDrawnAtOnceMax() != 1 ||
            miscmagic.mmpTricksDurationTurns() != 1 ||
            miscmagic.mmpTricksEndConditionCount() != 2 ||
            miscmagic.mmpTricksTypeRollCount() != 1 ||
            miscmagic.mmpTricksWeeklyDrawMax() != 10) ++bad;
        static const int kTricksTypeLo[3] = {
            1, 6, 9,
        };
        static const int kTricksTypeHi[3] = {
            5, 8, 100,
        };
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpTricksTypeLo(i) != kTricksTypeLo[i] ||
                miscmagic.mmpTricksTypeHi(i) != kTricksTypeHi[i]) ++bad;
        // the beaker of plentiful potions
        if (miscmagic.mmpBeakerDoseMin() != 2 ||
            miscmagic.mmpBeakerDoseMax() != 5 ||
            miscmagic.mmpBeakerPotionCountMin() != 2 ||
            miscmagic.mmpBeakerPotionCountMax() != 5 ||
            miscmagic.mmpBeakerCountDieSides() != 4 ||
            miscmagic.mmpBeakerCountDiePlus() != 1 ||
            miscmagic.mmpBeakerPourRounds() != 1 ||
            miscmagic.mmpBeakerPourDoses() != 1 ||
            miscmagic.mmpBeakerBadTypeCount() != 2 ||
            miscmagic.mmpBeakerMonthlyTypeLoss() != 1 ||
            miscmagic.mmpBeakerDispenseRowMin() != 2 ||
            miscmagic.mmpBeakerDispenseRowMax() != 5) ++bad;
        static const int kBeakerPerDay[4] = {
            1, 1, 0, 0,
        };
        static const int kBeakerPerWeek[4] = {
            3, 2, 1, 1,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic.mmpBeakerPerDayByCount(i) !=
                    kBeakerPerDay[i] ||
                miscmagic.mmpBeakerPerWeekByCount(i) !=
                    kBeakerPerWeek[i]) ++bad;
        // the boat, folding
        if (miscmagic.mmpBoatBoxLengthInches() != 12 ||
            miscmagic.mmpBoatBoxWidthInches() != 6 ||
            miscmagic.mmpBoatBoxDepthInches() != 6 ||
            miscmagic.mmpBoatLengthFeet() != 10 ||
            miscmagic.mmpBoatWidthFeet() != 4 ||
            miscmagic.mmpBoatDepthFeet() != 2 ||
            miscmagic.mmpBoatShipLengthFeet() != 24 ||
            miscmagic.mmpBoatShipWidthFeet() != 8 ||
            miscmagic.mmpBoatShipDepthFeet() != 6 ||
            miscmagic.mmpBoatOarPairs() != 1 ||
            miscmagic.mmpBoatComponentCount() != 4 ||
            miscmagic.mmpBoatShipOarSets() != 5 ||
            miscmagic.mmpBoatShipComponentCount() != 7 ||
            miscmagic.mmpBoatPersonsMin() != 3 ||
            miscmagic.mmpBoatPersonsMax() != 4 ||
            miscmagic.mmpBoatShipPersons() != 15 ||
            miscmagic.mmpBoatCommandWordCount() != 3) ++bad;
        // the book of exalted deeds
        if (miscmagic.mmpExaltedReadingWeeks() != 1 ||
            miscmagic.mmpExaltedWisdomGain() != 1 ||
            miscmagic.mmpExaltedHalfwayPct() != 50 ||
            miscmagic.mmpExaltedNeutralXpLossMin() != 20000 ||
            miscmagic.mmpExaltedNeutralXpLossMax() != 80000 ||
            miscmagic.mmpExaltedLevelFloor() != 1 ||
            miscmagic.mmpExaltedEvilLevelLoss() != 1 ||
            miscmagic.mmpExaltedAtonementPct() != 50 ||
            miscmagic.mmpExaltedAtonementAdventuresMin() != 2 ||
            miscmagic.mmpExaltedAtonementAdventuresMax() != 5 ||
            miscmagic.mmpExaltedMuIntLoss() != 1 ||
            miscmagic.mmpExaltedMuSaveXpLossMin() != 2000 ||
            miscmagic.mmpExaltedMuSaveXpLossMax() != 20000 ||
            miscmagic.mmpExaltedThiefHpMin() != 5 ||
            miscmagic.mmpExaltedThiefHpMax() != 30 ||
            miscmagic.mmpExaltedThiefDexLoss() != 1 ||
            miscmagic.mmpExaltedThiefConvertPctMin() != 10 ||
            miscmagic.mmpExaltedThiefConvertPctMax() != 60 ||
            miscmagic.mmpExaltedThiefConvertWisReq() != 15 ||
            miscmagic.mmpExaltedAssassinHpMin() != 5 ||
            miscmagic.mmpExaltedAssassinHpMax() != 40 ||
            miscmagic.mmpExaltedVanishesAfterPerusal() != 1 ||
            miscmagic.mmpExaltedMaxBenefitTimes() != 1) ++bad;
        printf("R258 misc magic prose part 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
