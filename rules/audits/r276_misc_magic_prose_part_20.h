    // ---- R276: the III.E misc magic explanation
    // prose part 20 ----
    // The Phylactery of Faithfulness, the Phylactery of
    // Long Years, the Phylactery of Monstrous Attention,
    // the Pipes of the Sewers, the Portable Hole and
    // Quaals Feather Token, part2 lines 971-998 - the
    // slice pinning the kMisc4 rows 30-35 of the 36-row
    // III.E.4 table (and closing it).
    {
        Miscmagic_phylactery_of_faithfulness_to_feather_token miscmagic_phylactery_of_faithfulness_to_feather_token;
        Miscmagic_table4_footnotes miscmagic_table4_footnotes;
        int bad = 0;
        // the phylactery of long years scalars
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpLongYearsSlowPct() != 25 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpLongYearsDonAge() != 20 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpLongYearsMonthsPerYear() != 9 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpLongYearsPhysicalAge() != 29 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpLongYearsChronAge() != 32 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpLongYearsReverseOneIn() != 20) ++bad;
        // the aging example is internally consistent
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpLongYearsMonthsPerYear() >= 12 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpLongYearsPhysicalAge() >=
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpLongYearsChronAge()) ++bad;
        // the phylactery of monstrous attention
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpAttentionMinLevel() != 10) ++bad;
        // the pipes of the sewers scalars
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeGiantRatMin() != 10 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeGiantRatMax() != 60 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeGiantRatPct() != 80 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeNormalRatMin() != 30 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeNormalRatMax() != 180 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeNormalRatPct() != 20 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeCallRangeInches() != 40 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeDelayPerInches() != 5 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeObeyPct() != 95 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeReplayObeyPct() != 70 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeReplayTurnPct() != 30 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeTakeoverPctPerRound() != 30 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeKeepPct() != 70) ++bad;
        // the rat split sums to the full call
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeGiantRatPct() +
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeNormalRatPct() != 100) ++bad;
        // the replay percentages split too
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeReplayObeyPct() +
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpPipeReplayTurnPct() != 100) ++bad;
        // the portable hole scalars
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpHoleDiameterFeet() != 6 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpHoleDepthFeet() != 10 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpHoleBreathTurns() != 1 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpHoleGateRadiusFeet() != 10) ++bad;
        // the hole is deeper than it is wide
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpHoleDepthFeet() <=
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpHoleDiameterFeet()) ++bad;
        // the quaal feather token scalars
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenUses() != 1 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenAnchorDays() != 1 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenBirdDays() != 1 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenFanHours() != 8 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenSwanSpeedInches() != 24 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenSwanHorses() != 8 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenSwanMen() != 32 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenSwanDays() != 1 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenTreeTrunkFeet() != 6 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenTreeHeightFeet() != 60 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenTreeTopFeet() != 40 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenWhipPlus() != 1 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenWhipLevel() != 9 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenWhipDmgMin() != 2 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenWhipDmgMax() != 7 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenWhipBindMin() != 2 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenWhipBindMax() != 7 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenWhipTurns() != 6) ++bad;
        // the die roll token table against static twins
        static const int kTlo[6] = {
            1, 5, 8, 11, 14, 19,
        };
        static const int kThi[6] = {
            4, 7, 10, 13, 18, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenRowLo(i) != kTlo[i] ||
                miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenRowHi(i) != kThi[i]) ++bad;
        // the token bands run 1 through 20 with no gaps
        if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenRowLo(0) != 1 ||
            miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenRowHi(5) != 20) ++bad;
        for (int i = 0; i < 5; ++i)
            if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenRowLo(i + 1) !=
                miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenRowHi(i) + 1) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenRowLo(i) >
                miscmagic_phylactery_of_faithfulness_to_feather_token.mmpTokenRowHi(i)) ++bad;
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
