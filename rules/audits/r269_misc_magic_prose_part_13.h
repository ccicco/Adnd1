    // ---- R269: the III.E misc magic explanation
    // prose part 13 ----
    // Horn of Collapsing through the Incense of
    // Meditation, part2 lines 581-626 - the slice
    // pinning the kMisc3 rows 18-23.
    {
        int bad = 0;
        if (rules::mmpHornCollapseMisfirePct() != 10 ||
            rules::mmpHornCollapseOutRocksMin() != 2 ||
            rules::mmpHornCollapseOutRocksMax() != 12 ||
            rules::mmpHornCollapseOutRockDmgMin() != 1 ||
            rules::mmpHornCollapseOutRockDmgMax() != 6) ++bad;
        if (rules::mmpHornCollapseIndoorDmgMin() != 3 ||
            rules::mmpHornCollapseIndoorDmgMax() != 36 ||
            rules::mmpHornCollapseUnderDmgMin() != 5 ||
            rules::mmpHornCollapseUnderDmgMax() != 20 ||
            rules::mmpHornCollapseUnderHeightFactorFeet() !=
            10) ++bad;
        if (rules::mmpHornCollapseAimRangeMinFeet() != 30 ||
            rules::mmpHornCollapseAimRangeMaxFeet() != 60 ||
            rules::mmpHornCollapseRoofWidthFeet() != 20 ||
            rules::mmpHornCollapseRoofLengthFeet() != 20 ||
            rules::mmpHornCollapseRoofRadiusFeet() !=
            10) ++bad;
        if (rules::mmpHornCollapseIndoorsOrUndergroundOnly() !=
            1) ++bad;
        // the collapse roof geometry: 20 = 10 + 10
        if (rules::mmpHornCollapseRoofWidthFeet() !=
            rules::mmpHornCollapseRoofRadiusFeet() +
            rules::mmpHornCollapseRoofRadiusFeet() ||
            rules::mmpHornCollapseRoofLengthFeet() !=
            rules::mmpHornCollapseRoofWidthFeet() ||
            rules::mmpHornCollapseAimRangeMaxFeet() !=
            rules::mmpHornCollapseAimRangeMinFeet() +
            30) ++bad;
        if (rules::mmpHornTritonPerDay() != 1 ||
            rules::mmpHornTritonTritonPerDay() != 3 ||
            rules::mmpHornTritonFunctionCount() != 3 ||
            rules::mmpHornTritonCalmRadiusMiles() != 1 ||
            rules::mmpHornTritonCalmDispelKinds() !=
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
        if (rules::mmpHornTritonSummonKindCount() !=
            3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (rules::mmpHornTritonSummonDieLo(i) !=
                kDlo[i] ||
                rules::mmpHornTritonSummonDieHi(i) !=
                kDhi[i] ||
                rules::mmpHornTritonSummonCountMin(i) !=
                kClo[i] ||
                rules::mmpHornTritonSummonCountMax(i) !=
                kChi[i]) ++bad;
        // the selection die runs 1-6 without gaps
        for (int i = 0; i < 2; ++i)
            if (rules::mmpHornTritonSummonDieLo(i + 1) !=
                rules::mmpHornTritonSummonDieHi(i) +
                1) ++bad;
        if (rules::mmpHornTritonSummonDieLo(0) != 1 ||
            rules::mmpHornTritonSummonDieHi(2) != 6) ++bad;
        if (rules::mmpHornTritonPanicAnimalOrLower() != 1 ||
            rules::mmpHornTritonPanicToHitPenalty() != 5 ||
            rules::mmpHornTritonPanicTurnsMin() != 3 ||
            rules::mmpHornTritonPanicTurnsMax() != 18 ||
            rules::mmpHornTritonPanicRoundsPerTurn() !=
            10) ++bad;
        // the panic ladder: turns times 10 = rounds
        if (rules::mmpHornTritonPanicRoundsMin() !=
            rules::mmpHornTritonPanicTurnsMin() *
            rules::mmpHornTritonPanicRoundsPerTurn() ||
            rules::mmpHornTritonPanicRoundsMax() !=
            rules::mmpHornTritonPanicTurnsMax() *
            rules::mmpHornTritonPanicRoundsPerTurn() ||
            rules::mmpHornTritonHearRadiusLeagues() !=
            1) ++bad;
        if (rules::mmpHornValhallaVarietyCount() != 4 ||
            rules::mmpHornValhallaBlowIntervalDays() != 7 ||
            rules::mmpHornValhallaSummonedAc() != 4 ||
            rules::mmpHornValhallaSummonedHpPerDie() !=
            6) ++bad;
        if (rules::mmpHornValhallaSwordSpearPct() != 50 ||
            rules::mmpHornValhallaAxeSpearPct() != 50 ||
            rules::mmpHornValhallaServiceTurns() != 6 ||
            rules::mmpHornValhallaAlignedPct() != 50) ++bad;
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
            if (rules::mmpHornValhallaDiceLo(i) != kVlo[i] ||
                rules::mmpHornValhallaDiceHi(i) != kVhi[i] ||
                rules::mmpHornValhallaCountMin(i) !=
                kNlo[i] ||
                rules::mmpHornValhallaCountMax(i) !=
                kNhi[i] ||
                rules::mmpHornValhallaLevel(i) != kLvl[i] ||
                rules::mmpHornValhallaUsableAny(i) !=
                kAny[i] ||
                rules::mmpHornValhallaUsableCleric(i) !=
                kVc[i] ||
                rules::mmpHornValhallaUsableFighter(i) !=
                kVf[i] ||
                rules::mmpHornValhallaUsableThief(i) !=
                kVt[i]) ++bad;
        // the variety dice run 1-20 without gaps, the
        // levels climb by 1
        for (int i = 0; i < 3; ++i)
            if (rules::mmpHornValhallaDiceLo(i + 1) !=
                rules::mmpHornValhallaDiceHi(i) + 1 ||
                rules::mmpHornValhallaLevel(i + 1) !=
                rules::mmpHornValhallaLevel(i) + 1) ++bad;
        if (rules::mmpHornValhallaDiceLo(0) != 1 ||
            rules::mmpHornValhallaDiceHi(3) != 20) ++bad;
        // the asterisk ladder: bronze doubles, iron
        // triples, the row 20 star count is 2
        if (rules::mmpHornValhallaIronXpMultiplier() !=
            rules::mmpHornValhallaBronzeXpMultiplier() +
            1 ||
            rules::mmpHornValhallaBronzeXpMultiplier() !=
            rules::m3StarCount(20)) ++bad;
        if (rules::mmpHorseshoesSpeedShoeCount() != 4 ||
            rules::mmpHorseshoesSpeedFullPct() != 200 ||
            rules::mmpHorseshoesSpeedDropPct() != 1 ||
            rules::mmpHorseshoesSpeedDropLeagues() !=
            7) ++bad;
        // the speed ladder: 200 = 100 + 100,
        // 150 = 100 + 50
        if (rules::mmpHorseshoesSpeedFullPct() !=
            rules::mmpHorseshoesSpeedTwoLostPct() +
            rules::mmpHorseshoesSpeedTwoLostPct() ||
            rules::mmpHorseshoesSpeedOneLostPct() !=
            rules::mmpHorseshoesSpeedTwoLostPct() +
            50) ++bad;
        if (rules::mmpHorseshoesZephyrGroundless() != 1 ||
            rules::mmpHorseshoesZephyrNoTracks() != 1 ||
            rules::mmpHorseshoesZephyrNoTireHours() != 12 ||
            rules::mmpHorseshoesZephyrPerDay() != 1) ++bad;
        if (rules::mmpIncenseMedRecognizeClericLevel() !=
            5 ||
            rules::mmpIncenseMedPrayHours() != 8 ||
            rules::mmpIncenseMedCureAlwaysMax() != 1 ||
            rules::mmpIncenseMedBroadestArea() != 1 ||
            rules::mmpIncenseMedSavePenalty() !=
            1) ++bad;
        // the incense ladders: burn = pray hours,
        // 24 = 8 + 8 + 8, the halved survival divisor
        if (rules::mmpIncenseMedBurnHours() !=
            rules::mmpIncenseMedPrayHours() ||
            rules::mmpIncenseMedEffectHours() !=
            rules::mmpIncenseMedBurnHours() +
            rules::mmpIncenseMedBurnHours() +
            rules::mmpIncenseMedBurnHours() ||
            rules::mmpIncenseMedNotSurvivingDivisor() !=
            2) ++bad;
        if (rules::mmpIncenseMedPieceCountMin() != 2 ||
            rules::mmpIncenseMedPieceCountMax() != 8) ++bad;
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
            if (rules::m3RowLo(18 + i) != kLo[i] ||
                rules::m3RowHi(18 + i) != kHi[i] ||
                rules::m3StarCount(18 + i) != kSt[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::m3UsableByCleric(18 + i) != kCm[i] ||
                rules::m3UsableByFighter(18 + i) !=
                kFm[i] ||
                rules::m3UsableByThief(18 + i) !=
                kTm[i] ||
                rules::m3IsPerFacetValued(18 + i)) ++bad;
        printf("R269 misc magic prose part 13 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
