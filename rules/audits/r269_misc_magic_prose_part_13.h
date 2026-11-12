    // ---- R269: the III.E misc magic explanation
    // prose part 13 ----
    // Horn of Collapsing through the Incense of
    // Meditation, part2 lines 581-626 - the slice
    // pinning the kMisc3 rows 18-23.
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic.mmpHornCollapseMisfirePct() != 10 ||
            miscmagic.mmpHornCollapseOutRocksMin() != 2 ||
            miscmagic.mmpHornCollapseOutRocksMax() != 12 ||
            miscmagic.mmpHornCollapseOutRockDmgMin() != 1 ||
            miscmagic.mmpHornCollapseOutRockDmgMax() != 6) ++bad;
        if (miscmagic.mmpHornCollapseIndoorDmgMin() != 3 ||
            miscmagic.mmpHornCollapseIndoorDmgMax() != 36 ||
            miscmagic.mmpHornCollapseUnderDmgMin() != 5 ||
            miscmagic.mmpHornCollapseUnderDmgMax() != 20 ||
            miscmagic.mmpHornCollapseUnderHeightFactorFeet() !=
            10) ++bad;
        if (miscmagic.mmpHornCollapseAimRangeMinFeet() != 30 ||
            miscmagic.mmpHornCollapseAimRangeMaxFeet() != 60 ||
            miscmagic.mmpHornCollapseRoofWidthFeet() != 20 ||
            miscmagic.mmpHornCollapseRoofLengthFeet() != 20 ||
            miscmagic.mmpHornCollapseRoofRadiusFeet() !=
            10) ++bad;
        if (miscmagic.mmpHornCollapseIndoorsOrUndergroundOnly() !=
            1) ++bad;
        // the collapse roof geometry: 20 = 10 + 10
        if (miscmagic.mmpHornCollapseRoofWidthFeet() !=
            miscmagic.mmpHornCollapseRoofRadiusFeet() +
            miscmagic.mmpHornCollapseRoofRadiusFeet() ||
            miscmagic.mmpHornCollapseRoofLengthFeet() !=
            miscmagic.mmpHornCollapseRoofWidthFeet() ||
            miscmagic.mmpHornCollapseAimRangeMaxFeet() !=
            miscmagic.mmpHornCollapseAimRangeMinFeet() +
            30) ++bad;
        if (miscmagic.mmpHornTritonPerDay() != 1 ||
            miscmagic.mmpHornTritonTritonPerDay() != 3 ||
            miscmagic.mmpHornTritonFunctionCount() != 3 ||
            miscmagic.mmpHornTritonCalmRadiusMiles() != 1 ||
            miscmagic.mmpHornTritonCalmDispelKinds() !=
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
        if (miscmagic.mmpHornTritonSummonKindCount() !=
            3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpHornTritonSummonDieLo(i) !=
                kDlo[i] ||
                miscmagic.mmpHornTritonSummonDieHi(i) !=
                kDhi[i] ||
                miscmagic.mmpHornTritonSummonCountMin(i) !=
                kClo[i] ||
                miscmagic.mmpHornTritonSummonCountMax(i) !=
                kChi[i]) ++bad;
        // the selection die runs 1-6 without gaps
        for (int i = 0; i < 2; ++i)
            if (miscmagic.mmpHornTritonSummonDieLo(i + 1) !=
                miscmagic.mmpHornTritonSummonDieHi(i) +
                1) ++bad;
        if (miscmagic.mmpHornTritonSummonDieLo(0) != 1 ||
            miscmagic.mmpHornTritonSummonDieHi(2) != 6) ++bad;
        if (miscmagic.mmpHornTritonPanicAnimalOrLower() != 1 ||
            miscmagic.mmpHornTritonPanicToHitPenalty() != 5 ||
            miscmagic.mmpHornTritonPanicTurnsMin() != 3 ||
            miscmagic.mmpHornTritonPanicTurnsMax() != 18 ||
            miscmagic.mmpHornTritonPanicRoundsPerTurn() !=
            10) ++bad;
        // the panic ladder: turns times 10 = rounds
        if (miscmagic.mmpHornTritonPanicRoundsMin() !=
            miscmagic.mmpHornTritonPanicTurnsMin() *
            miscmagic.mmpHornTritonPanicRoundsPerTurn() ||
            miscmagic.mmpHornTritonPanicRoundsMax() !=
            miscmagic.mmpHornTritonPanicTurnsMax() *
            miscmagic.mmpHornTritonPanicRoundsPerTurn() ||
            miscmagic.mmpHornTritonHearRadiusLeagues() !=
            1) ++bad;
        if (miscmagic.mmpHornValhallaVarietyCount() != 4 ||
            miscmagic.mmpHornValhallaBlowIntervalDays() != 7 ||
            miscmagic.mmpHornValhallaSummonedAc() != 4 ||
            miscmagic.mmpHornValhallaSummonedHpPerDie() !=
            6) ++bad;
        if (miscmagic.mmpHornValhallaSwordSpearPct() != 50 ||
            miscmagic.mmpHornValhallaAxeSpearPct() != 50 ||
            miscmagic.mmpHornValhallaServiceTurns() != 6 ||
            miscmagic.mmpHornValhallaAlignedPct() != 50) ++bad;
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
            if (miscmagic.mmpHornValhallaDiceLo(i) != kVlo[i] ||
                miscmagic.mmpHornValhallaDiceHi(i) != kVhi[i] ||
                miscmagic.mmpHornValhallaCountMin(i) !=
                kNlo[i] ||
                miscmagic.mmpHornValhallaCountMax(i) !=
                kNhi[i] ||
                miscmagic.mmpHornValhallaLevel(i) != kLvl[i] ||
                miscmagic.mmpHornValhallaUsableAny(i) !=
                kAny[i] ||
                miscmagic.mmpHornValhallaUsableCleric(i) !=
                kVc[i] ||
                miscmagic.mmpHornValhallaUsableFighter(i) !=
                kVf[i] ||
                miscmagic.mmpHornValhallaUsableThief(i) !=
                kVt[i]) ++bad;
        // the variety dice run 1-20 without gaps, the
        // levels climb by 1
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpHornValhallaDiceLo(i + 1) !=
                miscmagic.mmpHornValhallaDiceHi(i) + 1 ||
                miscmagic.mmpHornValhallaLevel(i + 1) !=
                miscmagic.mmpHornValhallaLevel(i) + 1) ++bad;
        if (miscmagic.mmpHornValhallaDiceLo(0) != 1 ||
            miscmagic.mmpHornValhallaDiceHi(3) != 20) ++bad;
        // the asterisk ladder: bronze doubles, iron
        // triples, the row 20 star count is 2
        if (miscmagic.mmpHornValhallaIronXpMultiplier() !=
            miscmagic.mmpHornValhallaBronzeXpMultiplier() +
            1 ||
            miscmagic.mmpHornValhallaBronzeXpMultiplier() !=
            miscmagic_table3_footnotes.m3StarCount(20)) ++bad;
        if (miscmagic.mmpHorseshoesSpeedShoeCount() != 4 ||
            miscmagic.mmpHorseshoesSpeedFullPct() != 200 ||
            miscmagic.mmpHorseshoesSpeedDropPct() != 1 ||
            miscmagic.mmpHorseshoesSpeedDropLeagues() !=
            7) ++bad;
        // the speed ladder: 200 = 100 + 100,
        // 150 = 100 + 50
        if (miscmagic.mmpHorseshoesSpeedFullPct() !=
            miscmagic.mmpHorseshoesSpeedTwoLostPct() +
            miscmagic.mmpHorseshoesSpeedTwoLostPct() ||
            miscmagic.mmpHorseshoesSpeedOneLostPct() !=
            miscmagic.mmpHorseshoesSpeedTwoLostPct() +
            50) ++bad;
        if (miscmagic.mmpHorseshoesZephyrGroundless() != 1 ||
            miscmagic.mmpHorseshoesZephyrNoTracks() != 1 ||
            miscmagic.mmpHorseshoesZephyrNoTireHours() != 12 ||
            miscmagic.mmpHorseshoesZephyrPerDay() != 1) ++bad;
        if (miscmagic.mmpIncenseMedRecognizeClericLevel() !=
            5 ||
            miscmagic.mmpIncenseMedPrayHours() != 8 ||
            miscmagic.mmpIncenseMedCureAlwaysMax() != 1 ||
            miscmagic.mmpIncenseMedBroadestArea() != 1 ||
            miscmagic.mmpIncenseMedSavePenalty() !=
            1) ++bad;
        // the incense ladders: burn = pray hours,
        // 24 = 8 + 8 + 8, the halved survival divisor
        if (miscmagic.mmpIncenseMedBurnHours() !=
            miscmagic.mmpIncenseMedPrayHours() ||
            miscmagic.mmpIncenseMedEffectHours() !=
            miscmagic.mmpIncenseMedBurnHours() +
            miscmagic.mmpIncenseMedBurnHours() +
            miscmagic.mmpIncenseMedBurnHours() ||
            miscmagic.mmpIncenseMedNotSurvivingDivisor() !=
            2) ++bad;
        if (miscmagic.mmpIncenseMedPieceCountMin() != 2 ||
            miscmagic.mmpIncenseMedPieceCountMax() != 8) ++bad;
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
