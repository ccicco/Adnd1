    // ---- R269: the III.E misc magic explanation
    // prose part 13 ----
    // Horn of Collapsing through the Incense of
    // Meditation, part2 lines 581-626 - the slice
    // pinning the kMisc3 rows 18-23.
    {
        Miscmagic_horn_of_collapsing_to_incense_of_meditation miscmagic_horn_of_collapsing_to_incense_of_meditation;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseMisfirePct() != 10 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseOutRocksMin() != 2 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseOutRocksMax() != 12 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseOutRockDmgMin() != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseOutRockDmgMax() != 6) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseIndoorDmgMin() != 3 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseIndoorDmgMax() != 36 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseUnderDmgMin() != 5 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseUnderDmgMax() != 20 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseUnderHeightFactorFeet() !=
            10) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseAimRangeMinFeet() != 30 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseAimRangeMaxFeet() != 60 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseRoofWidthFeet() != 20 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseRoofLengthFeet() != 20 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseRoofRadiusFeet() !=
            10) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseIndoorsOrUndergroundOnly() !=
            1) ++bad;
        // the collapse roof geometry: 20 = 10 + 10
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseRoofWidthFeet() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseRoofRadiusFeet() +
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseRoofRadiusFeet() ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseRoofLengthFeet() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseRoofWidthFeet() ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseAimRangeMaxFeet() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornCollapseAimRangeMinFeet() +
            30) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPerDay() != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonTritonPerDay() != 3 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonFunctionCount() != 3 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonCalmRadiusMiles() != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonCalmDispelKinds() !=
            2) ++bad;
        // the triton summon table against static twins
        static const int kDlo[3] = {
            1, 3, 6,
        };
        static const int kDhi[3] = {
            2, 5, 6,
        };
        static const int kClo[3] = {
            5, 5, 1,
        };
        static const int kChi[3] = {
            20, 30, 10,
        };
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonSummonKindCount() !=
            3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonSummonDieLo(i) !=
                kDlo[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonSummonDieHi(i) !=
                kDhi[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonSummonCountMin(i) !=
                kClo[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonSummonCountMax(i) !=
                kChi[i]) ++bad;
        // the selection die runs 1-6 without gaps
        for (int i = 0; i < 2; ++i)
            if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonSummonDieLo(i + 1) !=
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonSummonDieHi(i) +
                1) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonSummonDieLo(0) != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonSummonDieHi(2) != 6) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicAnimalOrLower() != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicToHitPenalty() != 5 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicTurnsMin() != 3 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicTurnsMax() != 18 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicRoundsPerTurn() !=
            10) ++bad;
        // the panic ladder: turns times 10 = rounds
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicRoundsMin() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicTurnsMin() *
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicRoundsPerTurn() ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicRoundsMax() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicTurnsMax() *
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonPanicRoundsPerTurn() ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornTritonHearRadiusLeagues() !=
            1) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaVarietyCount() != 4 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaBlowIntervalDays() != 7 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaSummonedAc() != 4 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaSummonedHpPerDie() !=
            6) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaSwordSpearPct() != 50 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaAxeSpearPct() != 50 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaServiceTurns() != 6 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaAlignedPct() != 50) ++bad;
        // the valhalla variety table against twins
        static const int kVlo[4] = {
            1, 9, 16, 19,
        };
        static const int kVhi[4] = {
            8, 15, 18, 20,
        };
        static const int kNlo[4] = {
            4, 3, 2, 2,
        };
        static const int kNhi[4] = {
            10, 9, 8, 5,
        };
        static const int kLvl[4] = {
            2, 3, 4, 5,
        };
        static const int kAny[4] = {
            1, 0, 0, 0,
        };
        static const int kVc[4] = {
            0, 1, 1, 0,
        };
        static const int kVf[4] = {
            0, 1, 1, 1,
        };
        static const int kVt[4] = {
            0, 1, 0, 0,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaDiceLo(i) != kVlo[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaDiceHi(i) != kVhi[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaCountMin(i) !=
                kNlo[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaCountMax(i) !=
                kNhi[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaLevel(i) != kLvl[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaUsableAny(i) !=
                kAny[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaUsableCleric(i) !=
                kVc[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaUsableFighter(i) !=
                kVf[i] ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaUsableThief(i) !=
                kVt[i]) ++bad;
        // the variety dice run 1-20 without gaps, the
        // levels climb by 1
        for (int i = 0; i < 3; ++i)
            if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaDiceLo(i + 1) !=
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaDiceHi(i) + 1 ||
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaLevel(i + 1) !=
                miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaLevel(i) + 1) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaDiceLo(0) != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaDiceHi(3) != 20) ++bad;
        // the asterisk ladder: bronze doubles, iron
        // triples, the row 20 star count is 2
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaIronXpMultiplier() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaBronzeXpMultiplier() +
            1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHornValhallaBronzeXpMultiplier() !=
            miscmagic_table3_footnotes.m3StarCount(20)) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesSpeedShoeCount() != 4 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesSpeedFullPct() != 200 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesSpeedDropPct() != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesSpeedDropLeagues() !=
            7) ++bad;
        // the speed ladder: 200 = 100 + 100,
        // 150 = 100 + 50
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesSpeedFullPct() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesSpeedTwoLostPct() +
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesSpeedTwoLostPct() ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesSpeedOneLostPct() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesSpeedTwoLostPct() +
            50) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesZephyrGroundless() != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesZephyrNoTracks() != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesZephyrNoTireHours() != 12 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpHorseshoesZephyrPerDay() != 1) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedRecognizeClericLevel() !=
            5 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedPrayHours() != 8 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedCureAlwaysMax() != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedBroadestArea() != 1 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedSavePenalty() !=
            1) ++bad;
        // the incense ladders: burn = pray hours,
        // 24 = 8 + 8 + 8, the halved survival divisor
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedBurnHours() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedPrayHours() ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedEffectHours() !=
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedBurnHours() +
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedBurnHours() +
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedBurnHours() ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedNotSurvivingDivisor() !=
            2) ++bad;
        if (miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedPieceCountMin() != 2 ||
            miscmagic_horn_of_collapsing_to_incense_of_meditation.mmpIncenseMedPieceCountMax() != 8) ++bad;
        // the kMisc3 rows this slice pins: 18-23,
        // the (C, F) mark on row 19, the (C) mark on
        // row 23, the double asterisk on row 20
        static const int kLo[6] = {
            49, 50, 54, 61, 64, 66,
        };
        static const int kHi[6] = {
            49, 53, 60, 63, 65, 70,
        };
        static const int kCm[6] = {
            0, 1, 0, 0, 0, 1,
        };
        static const int kFm[6] = {
            0, 1, 0, 0, 0, 0,
        };
        static const int kTm[6] = {
            0, 0, 0, 0, 0, 0,
        };
        static const int kSt[6] = {
            0, 0, 2, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic_table3_footnotes.m3RowLo(18 + i) != kLo[i] ||
                miscmagic_table3_footnotes.m3RowHi(18 + i) != kHi[i] ||
                miscmagic_table3_footnotes.m3StarCount(18 + i) != kSt[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic_table3_footnotes.m3UsableByCleric(18 + i) != kCm[i] ||
                miscmagic_table3_footnotes.m3UsableByFighter(18 + i) !=
                kFm[i] ||
                miscmagic_table3_footnotes.m3UsableByThief(18 + i) !=
                kTm[i] ||
                miscmagic_table3_footnotes.m3IsPerFacetValued(18 + i)) ++bad;
        printf("R269 misc magic prose part 13 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
