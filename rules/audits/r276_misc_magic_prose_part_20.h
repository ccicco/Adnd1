    // ---- R276: the III.E misc magic explanation
    // prose part 20 ----
    // The Phylactery of Faithfulness, the Phylactery of
    // Long Years, the Phylactery of Monstrous Attention,
    // the Pipes of the Sewers, the Portable Hole and
    // Quaals Feather Token, part2 lines 971-998 - the
    // slice pinning the kMisc4 rows 30-35 of the 36-row
    // III.E.4 table (and closing it).
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table4_footnotes miscmagic_table4_footnotes;
        int bad = 0;
        // the phylactery of long years scalars
        if (miscmagic.mmpLongYearsSlowPct() != 25 ||
            miscmagic.mmpLongYearsDonAge() != 20 ||
            miscmagic.mmpLongYearsMonthsPerYear() != 9 ||
            miscmagic.mmpLongYearsPhysicalAge() != 29 ||
            miscmagic.mmpLongYearsChronAge() != 32 ||
            miscmagic.mmpLongYearsReverseOneIn() != 20) ++bad;
        // the aging example is internally consistent
        if (miscmagic.mmpLongYearsMonthsPerYear() >= 12 ||
            miscmagic.mmpLongYearsPhysicalAge() >=
            miscmagic.mmpLongYearsChronAge()) ++bad;
        // the phylactery of monstrous attention
        if (miscmagic.mmpAttentionMinLevel() != 10) ++bad;
        // the pipes of the sewers scalars
        if (miscmagic.mmpPipeGiantRatMin() != 10 ||
            miscmagic.mmpPipeGiantRatMax() != 60 ||
            miscmagic.mmpPipeGiantRatPct() != 80 ||
            miscmagic.mmpPipeNormalRatMin() != 30 ||
            miscmagic.mmpPipeNormalRatMax() != 180 ||
            miscmagic.mmpPipeNormalRatPct() != 20 ||
            miscmagic.mmpPipeCallRangeInches() != 40 ||
            miscmagic.mmpPipeDelayPerInches() != 5 ||
            miscmagic.mmpPipeObeyPct() != 95 ||
            miscmagic.mmpPipeReplayObeyPct() != 70 ||
            miscmagic.mmpPipeReplayTurnPct() != 30 ||
            miscmagic.mmpPipeTakeoverPctPerRound() != 30 ||
            miscmagic.mmpPipeKeepPct() != 70) ++bad;
        // the rat split sums to the full call
        if (miscmagic.mmpPipeGiantRatPct() +
            miscmagic.mmpPipeNormalRatPct() != 100) ++bad;
        // the replay percentages split too
        if (miscmagic.mmpPipeReplayObeyPct() +
            miscmagic.mmpPipeReplayTurnPct() != 100) ++bad;
        // the portable hole scalars
        if (miscmagic.mmpHoleDiameterFeet() != 6 ||
            miscmagic.mmpHoleDepthFeet() != 10 ||
            miscmagic.mmpHoleBreathTurns() != 1 ||
            miscmagic.mmpHoleGateRadiusFeet() != 10) ++bad;
        // the hole is deeper than it is wide
        if (miscmagic.mmpHoleDepthFeet() <=
            miscmagic.mmpHoleDiameterFeet()) ++bad;
        // the quaal feather token scalars
        if (miscmagic.mmpTokenUses() != 1 ||
            miscmagic.mmpTokenAnchorDays() != 1 ||
            miscmagic.mmpTokenBirdDays() != 1 ||
            miscmagic.mmpTokenFanHours() != 8 ||
            miscmagic.mmpTokenSwanSpeedInches() != 24 ||
            miscmagic.mmpTokenSwanHorses() != 8 ||
            miscmagic.mmpTokenSwanMen() != 32 ||
            miscmagic.mmpTokenSwanDays() != 1 ||
            miscmagic.mmpTokenTreeTrunkFeet() != 6 ||
            miscmagic.mmpTokenTreeHeightFeet() != 60 ||
            miscmagic.mmpTokenTreeTopFeet() != 40 ||
            miscmagic.mmpTokenWhipPlus() != 1 ||
            miscmagic.mmpTokenWhipLevel() != 9 ||
            miscmagic.mmpTokenWhipDmgMin() != 2 ||
            miscmagic.mmpTokenWhipDmgMax() != 7 ||
            miscmagic.mmpTokenWhipBindMin() != 2 ||
            miscmagic.mmpTokenWhipBindMax() != 7 ||
            miscmagic.mmpTokenWhipTurns() != 6) ++bad;
        // the die roll token table against static twins
        static const int kTlo[6] = {
            1, 5, 8, 11, 14, 19,
        };
        static const int kThi[6] = {
            4, 7, 10, 13, 18, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpTokenRowLo(i) != kTlo[i] ||
                miscmagic.mmpTokenRowHi(i) != kThi[i]) ++bad;
        // the token bands run 1 through 20 with no gaps
        if (miscmagic.mmpTokenRowLo(0) != 1 ||
            miscmagic.mmpTokenRowHi(5) != 20) ++bad;
        for (int i = 0; i < 5; ++i)
            if (miscmagic.mmpTokenRowLo(i + 1) !=
                miscmagic.mmpTokenRowHi(i) + 1) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpTokenRowLo(i) >
                miscmagic.mmpTokenRowHi(i)) ++bad;
        // the kMisc4 table closure cross-check
        static const int kRlo[6] = {
            65, 71, 75, 77, 85, 86,
        };
        static const int kRhi[6] = {
            70, 74, 76, 84, 85, 100,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic_table4_footnotes.m4RowLo(30 + i) != kRlo[i] ||
                miscmagic_table4_footnotes.m4RowHi(30 + i) != kRhi[i]) ++bad;
        // the marks: the three phylacteries are (C) only
        for (int i = 30; i < 36; ++i)
            if (i != 30 && i != 31 && i != 32 &&
                miscmagic_table4_footnotes.m4UsableByCleric(i) != 0) ++bad;
        for (int i = 30; i < 36; ++i)
            if (miscmagic_table4_footnotes.m4UsableByFighter(i) != 0) ++bad;
        for (int i = 30; i < 36; ++i)
            if (miscmagic_table4_footnotes.m4UsableByMagicUser(i) != 0) ++bad;
        for (int i = 30; i < 36; ++i)
            if (miscmagic_table4_footnotes.m4UsableByThief(i) != 0) ++bad;
        for (int i = 30; i < 36; ++i)
            if (miscmagic_table4_footnotes.m4StarCount(i) != 0) ++bad;
        // the dual-value feather token row and helpers
        if (miscmagic_table4_footnotes.m4IsDualValued(35) != 1) ++bad;
        for (int i = 30; i < 35; ++i)
            if (miscmagic_table4_footnotes.m4IsDualValued(i) != 0) ++bad;
        if (miscmagic_table4_footnotes.m4FeatherTokenXpLow() != 500 ||
            miscmagic_table4_footnotes.m4FeatherTokenXpHigh() != 1000 ||
            miscmagic_table4_footnotes.m4FeatherTokenGpLow() != 2000 ||
            miscmagic_table4_footnotes.m4FeatherTokenGpHigh() != 7000 ||
            miscmagic_table4_footnotes.m4RowCount() != 36) ++bad;
        printf("R276 misc magic prose part 20 pins audit: bad %d\n", bad);
    }
