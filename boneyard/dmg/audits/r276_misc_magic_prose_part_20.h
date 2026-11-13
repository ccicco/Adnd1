    // ---- R276: the III.E misc magic explanation
    // prose part 20 ----
    // The Phylactery of Faithfulness, the Phylactery of
    // Long Years, the Phylactery of Monstrous Attention,
    // the Pipes of the Sewers, the Portable Hole and
    // Quaals Feather Token, part2 lines 971-998 - the
    // slice pinning the kMisc4 rows 30-35 of the 36-row
    // III.E.4 table (and closing it).
    {
        int bad = 0;
        // the phylactery of long years scalars
        if (rules::mmpLongYearsSlowPct() != 25 ||
            rules::mmpLongYearsDonAge() != 20 ||
            rules::mmpLongYearsMonthsPerYear() != 9 ||
            rules::mmpLongYearsPhysicalAge() != 29 ||
            rules::mmpLongYearsChronAge() != 32 ||
            rules::mmpLongYearsReverseOneIn() != 20) ++bad;
        // the aging example is internally consistent
        if (rules::mmpLongYearsMonthsPerYear() >= 12 ||
            rules::mmpLongYearsPhysicalAge() >=
            rules::mmpLongYearsChronAge()) ++bad;
        // the phylactery of monstrous attention
        if (rules::mmpAttentionMinLevel() != 10) ++bad;
        // the pipes of the sewers scalars
        if (rules::mmpPipeGiantRatMin() != 10 ||
            rules::mmpPipeGiantRatMax() != 60 ||
            rules::mmpPipeGiantRatPct() != 80 ||
            rules::mmpPipeNormalRatMin() != 30 ||
            rules::mmpPipeNormalRatMax() != 180 ||
            rules::mmpPipeNormalRatPct() != 20 ||
            rules::mmpPipeCallRangeInches() != 40 ||
            rules::mmpPipeDelayPerInches() != 5 ||
            rules::mmpPipeObeyPct() != 95 ||
            rules::mmpPipeReplayObeyPct() != 70 ||
            rules::mmpPipeReplayTurnPct() != 30 ||
            rules::mmpPipeTakeoverPctPerRound() != 30 ||
            rules::mmpPipeKeepPct() != 70) ++bad;
        // the rat split sums to the full call
        if (rules::mmpPipeGiantRatPct() +
            rules::mmpPipeNormalRatPct() != 100) ++bad;
        // the replay percentages split too
        if (rules::mmpPipeReplayObeyPct() +
            rules::mmpPipeReplayTurnPct() != 100) ++bad;
        // the portable hole scalars
        if (rules::mmpHoleDiameterFeet() != 6 ||
            rules::mmpHoleDepthFeet() != 10 ||
            rules::mmpHoleBreathTurns() != 1 ||
            rules::mmpHoleGateRadiusFeet() != 10) ++bad;
        // the hole is deeper than it is wide
        if (rules::mmpHoleDepthFeet() <=
            rules::mmpHoleDiameterFeet()) ++bad;
        // the quaal feather token scalars
        if (rules::mmpTokenUses() != 1 ||
            rules::mmpTokenAnchorDays() != 1 ||
            rules::mmpTokenBirdDays() != 1 ||
            rules::mmpTokenFanHours() != 8 ||
            rules::mmpTokenSwanSpeedInches() != 24 ||
            rules::mmpTokenSwanHorses() != 8 ||
            rules::mmpTokenSwanMen() != 32 ||
            rules::mmpTokenSwanDays() != 1 ||
            rules::mmpTokenTreeTrunkFeet() != 6 ||
            rules::mmpTokenTreeHeightFeet() != 60 ||
            rules::mmpTokenTreeTopFeet() != 40 ||
            rules::mmpTokenWhipPlus() != 1 ||
            rules::mmpTokenWhipLevel() != 9 ||
            rules::mmpTokenWhipDmgMin() != 2 ||
            rules::mmpTokenWhipDmgMax() != 7 ||
            rules::mmpTokenWhipBindMin() != 2 ||
            rules::mmpTokenWhipBindMax() != 7 ||
            rules::mmpTokenWhipTurns() != 6) ++bad;
        // the die roll token table against static twins
        static const int kTlo[6] = {
            1, 5, 8, 11, 14, 19,
        };
        static const int kThi[6] = {
            4, 7, 10, 13, 18, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::mmpTokenRowLo(i) != kTlo[i] ||
                rules::mmpTokenRowHi(i) != kThi[i]) ++bad;
        // the token bands run 1 through 20 with no gaps
        if (rules::mmpTokenRowLo(0) != 1 ||
            rules::mmpTokenRowHi(5) != 20) ++bad;
        for (int i = 0; i < 5; ++i)
            if (rules::mmpTokenRowLo(i + 1) !=
                rules::mmpTokenRowHi(i) + 1) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::mmpTokenRowLo(i) >
                rules::mmpTokenRowHi(i)) ++bad;
        // the kMisc4 table closure cross-check
        static const int kRlo[6] = {
            65, 71, 75, 77, 85, 86,
        };
        static const int kRhi[6] = {
            70, 74, 76, 84, 85, 100,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::m4RowLo(30 + i) != kRlo[i] ||
                rules::m4RowHi(30 + i) != kRhi[i]) ++bad;
        // the marks: the three phylacteries are (C) only
        for (int i = 30; i < 36; ++i)
            if (i != 30 && i != 31 && i != 32 &&
                rules::m4UsableByCleric(i) != 0) ++bad;
        for (int i = 30; i < 36; ++i)
            if (rules::m4UsableByFighter(i) != 0) ++bad;
        for (int i = 30; i < 36; ++i)
            if (rules::m4UsableByMagicUser(i) != 0) ++bad;
        for (int i = 30; i < 36; ++i)
            if (rules::m4UsableByThief(i) != 0) ++bad;
        for (int i = 30; i < 36; ++i)
            if (rules::m4StarCount(i) != 0) ++bad;
        // the dual-value feather token row and helpers
        if (rules::m4IsDualValued(35) != 1) ++bad;
        for (int i = 30; i < 35; ++i)
            if (rules::m4IsDualValued(i) != 0) ++bad;
        if (rules::m4FeatherTokenXpLow() != 500 ||
            rules::m4FeatherTokenXpHigh() != 1000 ||
            rules::m4FeatherTokenGpLow() != 2000 ||
            rules::m4FeatherTokenGpHigh() != 7000 ||
            rules::m4RowCount() != 36) ++bad;
        printf("R276 misc magic prose part 20 pins audit: bad %d\n", bad);
    }
