    // ---- R258: the III.E misc magic explanation prose part 2 pins audit ----
    // part2 lines 5-66 - Bag of Holding through
    // Book of Exalted Deeds, global = 11065 +
    // part2 line; no page headers inside the
    // slice.
    {
        int bad = 0;
        // the six items are the engine kMisc1 rows
        // 10-15 (the R225 m1 band pins); the
        // Exalted (C) class mark is row 15, the
        // Boat row 14 is the negative control
        if (rules::m1RowCount() != 33) ++bad;
        static const int kM1Lo[6] = {
            22, 27, 28, 30, 32, 33,
        };
        static const int kM1Hi[6] = {
            26, 27, 29, 31, 32, 33,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::m1RowLo(10 + i) != kM1Lo[i] ||
                rules::m1RowHi(10 + i) != kM1Hi[i]) ++bad;
        if (rules::m1UsableByCleric(15) != 1 ||
            rules::m1UsableByCleric(14) != 0) ++bad;
        // the bag of holding: the 4 quality rows
        if (rules::mmpHoldingSackShortSideFeet() != 2 ||
            rules::mmpHoldingSackLongSideFeet() != 4 ||
            rules::mmpHoldingRowCount() != 4 ||
            rules::mmpHoldingRuptureCauseCount() != 2) ++bad;
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
            if (rules::mmpHoldingRowLo(i) != kHoldingLo[i] ||
                rules::mmpHoldingRowHi(i) != kHoldingHi[i] ||
                rules::mmpHoldingRowWeightPounds(i) !=
                    kHoldingWeight[i] ||
                rules::mmpHoldingRowWeightLimitPounds(i) !=
                    kHoldingWeightLimit[i] ||
                rules::mmpHoldingRowVolumeLimitCubicFeet(i) !=
                    kHoldingVolume[i]) ++bad;
        // the bag of transmuting
        if (rules::mmpTransmutingDisguiseQualityCount() != 4 ||
            rules::mmpTransmutingProperUsesMin() != 2 ||
            rules::mmpTransmutingProperUsesMax() != 5 ||
            rules::mmpTransmutingTransmuteKindCount() != 2 ||
            rules::mmpTransmutingItemBaseMaterialCount() != 3 ||
            rules::mmpTransmutingExemptKindCount() != 2) ++bad;
        // the bag of tricks: the animal stat columns
        // are mangled in the upload - the type bands
        // and counts are pinned, the stats are not
        // (the R256 lesson)
        if (rules::mmpTricksTossMinFeet() != 1 ||
            rules::mmpTricksTossMaxFeet() != 20 ||
            rules::mmpTricksTypeDieSides() != 10 ||
            rules::mmpTricksTypeCount() != 3 ||
            rules::mmpTricksAnimalsPerType() != 8 ||
            rules::mmpTricksAnimalDieMin() != 1 ||
            rules::mmpTricksAnimalDieMax() != 8 ||
            rules::mmpTricksDrawnAtOnceMax() != 1 ||
            rules::mmpTricksDurationTurns() != 1 ||
            rules::mmpTricksEndConditionCount() != 2 ||
            rules::mmpTricksTypeRollCount() != 1 ||
            rules::mmpTricksWeeklyDrawMax() != 10) ++bad;
        static const int kTricksTypeLo[3] = {
            1, 6, 9,
        };
        static const int kTricksTypeHi[3] = {
            5, 8, 100,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::mmpTricksTypeLo(i) != kTricksTypeLo[i] ||
                rules::mmpTricksTypeHi(i) != kTricksTypeHi[i]) ++bad;
        // the beaker of plentiful potions
        if (rules::mmpBeakerDoseMin() != 2 ||
            rules::mmpBeakerDoseMax() != 5 ||
            rules::mmpBeakerPotionCountMin() != 2 ||
            rules::mmpBeakerPotionCountMax() != 5 ||
            rules::mmpBeakerCountDieSides() != 4 ||
            rules::mmpBeakerCountDiePlus() != 1 ||
            rules::mmpBeakerPourRounds() != 1 ||
            rules::mmpBeakerPourDoses() != 1 ||
            rules::mmpBeakerBadTypeCount() != 2 ||
            rules::mmpBeakerMonthlyTypeLoss() != 1 ||
            rules::mmpBeakerDispenseRowMin() != 2 ||
            rules::mmpBeakerDispenseRowMax() != 5) ++bad;
        static const int kBeakerPerDay[4] = {
            1, 1, 0, 0,
        };
        static const int kBeakerPerWeek[4] = {
            3, 2, 1, 1,
        };
        for (int i = 0; i < 4; ++i)
            if (rules::mmpBeakerPerDayByCount(i) !=
                    kBeakerPerDay[i] ||
                rules::mmpBeakerPerWeekByCount(i) !=
                    kBeakerPerWeek[i]) ++bad;
        // the boat, folding
        if (rules::mmpBoatBoxLengthInches() != 12 ||
            rules::mmpBoatBoxWidthInches() != 6 ||
            rules::mmpBoatBoxDepthInches() != 6 ||
            rules::mmpBoatLengthFeet() != 10 ||
            rules::mmpBoatWidthFeet() != 4 ||
            rules::mmpBoatDepthFeet() != 2 ||
            rules::mmpBoatShipLengthFeet() != 24 ||
            rules::mmpBoatShipWidthFeet() != 8 ||
            rules::mmpBoatShipDepthFeet() != 6 ||
            rules::mmpBoatOarPairs() != 1 ||
            rules::mmpBoatComponentCount() != 4 ||
            rules::mmpBoatShipOarSets() != 5 ||
            rules::mmpBoatShipComponentCount() != 7 ||
            rules::mmpBoatPersonsMin() != 3 ||
            rules::mmpBoatPersonsMax() != 4 ||
            rules::mmpBoatShipPersons() != 15 ||
            rules::mmpBoatCommandWordCount() != 3) ++bad;
        // the book of exalted deeds
        if (rules::mmpExaltedReadingWeeks() != 1 ||
            rules::mmpExaltedWisdomGain() != 1 ||
            rules::mmpExaltedHalfwayPct() != 50 ||
            rules::mmpExaltedNeutralXpLossMin() != 20000 ||
            rules::mmpExaltedNeutralXpLossMax() != 80000 ||
            rules::mmpExaltedLevelFloor() != 1 ||
            rules::mmpExaltedEvilLevelLoss() != 1 ||
            rules::mmpExaltedAtonementPct() != 50 ||
            rules::mmpExaltedAtonementAdventuresMin() != 2 ||
            rules::mmpExaltedAtonementAdventuresMax() != 5 ||
            rules::mmpExaltedMuIntLoss() != 1 ||
            rules::mmpExaltedMuSaveXpLossMin() != 2000 ||
            rules::mmpExaltedMuSaveXpLossMax() != 20000 ||
            rules::mmpExaltedThiefHpMin() != 5 ||
            rules::mmpExaltedThiefHpMax() != 30 ||
            rules::mmpExaltedThiefDexLoss() != 1 ||
            rules::mmpExaltedThiefConvertPctMin() != 10 ||
            rules::mmpExaltedThiefConvertPctMax() != 60 ||
            rules::mmpExaltedThiefConvertWisReq() != 15 ||
            rules::mmpExaltedAssassinHpMin() != 5 ||
            rules::mmpExaltedAssassinHpMax() != 40 ||
            rules::mmpExaltedVanishesAfterPerusal() != 1 ||
            rules::mmpExaltedMaxBenefitTimes() != 1) ++bad;
        printf("R258 misc magic prose part 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
