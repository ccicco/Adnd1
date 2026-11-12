    // ---- R267: the III.E misc magic explanation
    // prose part 11 ----
    // Flask of Curses through the Girdle of Giant
    // Strength, part2 lines 481-530 - the slice
    // pinning the kMisc3 rows 1-9.
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic.mmpFlaskCurseOnFirstOpen() != 1 ||
            miscmagic.mmpFlaskHarmlessAfterUse() != 1) ++bad;
        if (miscmagic.mmpGauntDexBoostLow() != 4 ||
            miscmagic.mmpGauntDexBoostMid() != 2 ||
            miscmagic.mmpGauntDexBoostHigh() != 1 ||
            miscmagic.mmpGauntDexThiefLevel() != 4 ||
            miscmagic.mmpGauntDexThiefBonusPct() != 10) ++bad;
        if (miscmagic.mmpGauntFumbDropPct() != 50 ||
            miscmagic.mmpGauntFumbDexPenalty() != 2 ||
            miscmagic.mmpGauntFumbRemoveCurseOnly() != 1 ||
            miscmagic.mmpGauntOgreStrength() != 18 ||
            miscmagic.mmpGauntOgreStrengthPercentile() != 0 ||
            miscmagic.mmpGauntOgreHitBonus() != 3 ||
            miscmagic.mmpGauntOgreDmgBonus() != 6) ++bad;
        if (miscmagic.mmpGauntSwimUnderwaterInches() != 15 ||
            miscmagic.mmpGauntSwimSurfaceInches() != 18 ||
            miscmagic.mmpGauntSwimClimbSuccessPct() != 95 ||
            miscmagic.mmpGauntSwimThiefSuccessTenthPct() !=
            995) ++bad;
        if (miscmagic.mmpGemBrightLightSorts() != 3 ||
            miscmagic.mmpGemBrightConeLengthFeet() != 10 ||
            miscmagic.mmpGemBrightConeRadiusHalfFeet() != 5 ||
            miscmagic.mmpGemBrightRayDiameterFeet() != 1 ||
            miscmagic.mmpGemBrightRayLengthFeet() != 50 ||
            miscmagic.mmpGemBrightDazzleMinRounds() != 1 ||
            miscmagic.mmpGemBrightDazzleMaxRounds() != 4 ||
            miscmagic.mmpGemBrightRayCharges() != 1) ++bad;
        if (miscmagic.mmpGemBrightFlashLengthFeet() != 30 ||
            miscmagic.mmpGemBrightFlashRadiusFeet() != 5 ||
            miscmagic.mmpGemBrightBlindMinRounds() != 1 ||
            miscmagic.mmpGemBrightBlindMaxRounds() != 4 ||
            miscmagic.mmpGemBrightEyePenaltyMin() != 1 ||
            miscmagic.mmpGemBrightEyePenaltyMax() != 4 ||
            miscmagic.mmpGemBrightFlashCharges() != 5 ||
            miscmagic.mmpGemBrightTotalCharges() != 50) ++bad;
        if (miscmagic.mmpGemBrightDarknessDrainCharges() != 1 ||
            miscmagic.mmpGemBrightDarknessRoundUseless() != 1 ||
            miscmagic.mmpGemBrightDarknessDayUseless() != 1 ||
            miscmagic.mmpGemBrightDarknessExpelCharges() !=
            5) ++bad;
        if (miscmagic.mmpGemSeeCursoryRangeInches() != 30 ||
            miscmagic.mmpGemSeeCarefulRangeInches() != 10 ||
            miscmagic.mmpGemSeeCursoryAreaFeet() != 200 ||
            miscmagic.mmpGemSeeCursoryRounds() != 1 ||
            miscmagic.mmpGemSeeCarefulAreaFeet() != 100 ||
            miscmagic.mmpGemSeeCarefulRounds() != 2 ||
            miscmagic.mmpGemSeeHallucinationPct() != 5) ++bad;
        if (miscmagic.mmpGirdleSexWishRestorePct() != 50 ||
            miscmagic.mmpGirdleSexSexlessPct() != 10 ||
            miscmagic.mmpGirdleGiantTypeCount() != 6 ||
            miscmagic.mmpGirdleGiantRockDmgMin() != 1) ++bad;
        // the arithmetic: the two 5-charge expends
        if (miscmagic.mmpGemBrightFlashCharges() !=
            miscmagic.mmpGemBrightDarknessExpelCharges() ||
            miscmagic.mmpGemBrightDazzleMinRounds() !=
            miscmagic.mmpGemBrightBlindMinRounds() ||
            miscmagic.mmpGemBrightDazzleMaxRounds() !=
            miscmagic.mmpGemBrightBlindMaxRounds()) ++bad;
        // the giant strength ladders: strength and
        // damage climb by 1, bend bars by 10
        for (int i = 0; i < 5; ++i)
            if (miscmagic.mmpGirdleGiantStrength(i + 1) !=
                miscmagic.mmpGirdleGiantStrength(i) + 1 ||
                miscmagic.mmpGirdleGiantDmgBonus(i + 1) !=
                miscmagic.mmpGirdleGiantDmgBonus(i) + 1 ||
                miscmagic.mmpGirdleGiantBendBarsPct(i + 1) !=
                miscmagic.mmpGirdleGiantBendBarsPct(i) +
                10) ++bad;
        // the dice bands run 01-00 without gaps
        for (int i = 0; i < 5; ++i)
            if (miscmagic.mmpGirdleGiantDiceLo(i + 1) !=
                miscmagic.mmpGirdleGiantDiceHi(i) + 1) ++bad;
        if (miscmagic.mmpGirdleGiantDiceLo(0) != 1 ||
            miscmagic.mmpGirdleGiantDiceHi(5) != 100) ++bad;
        // the static twin of the printed tables
        static const int kStr[6] = {
            19, 20, 21, 22, 23, 24,
        };
        static const int kHit[6] = {
            3, 3, 4, 4, 5, 6,
        };
        static const int kTop[6] = {
            7, 7, 9, 11, 11, 19,
        };
        static const int kBot[6] = {
            8, 8, 10, 12, 12, 20,
        };
        static const int kCh[6] = {
            3, 3, 4, 4, 5, 7,
        };
        static const int kOf[6] = {
            6, 6, 6, 6, 6, 8,
        };
        static const int kWa[6] = {
            4500, 5000, 6000, 7500,
            9000, 12000,
        };
        static const int kRg[6] = {
            8, 16, 10, 12, 14, 16,
        };
        static const int kRd[6] = {
            6, 12, 8, 8, 10, 12,
        };
        static const int kRw[6] = {
            140, 198, 156, 170,
            184, 212,
        };
        static const int kBb[6] = {
            50, 60, 70, 80, 90, 100,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpGirdleGiantStrength(i) != kStr[i] ||
                miscmagic.mmpGirdleGiantHitBonus(i) != kHit[i] ||
                miscmagic.mmpGirdleGiantOpenDoorsTop(i) !=
                kTop[i] ||
                miscmagic.mmpGirdleGiantOpenDoorsBottom(i) !=
                kBot[i] ||
                miscmagic.mmpGirdleGiantOpenChances(i) !=
                kCh[i] ||
                miscmagic.mmpGirdleGiantOpenOutOf(i) !=
                kOf[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpGirdleGiantWeightAllowance(i) !=
                kWa[i] ||
                miscmagic.mmpGirdleGiantRangeInches(i) !=
                kRg[i] ||
                miscmagic.mmpGirdleGiantRockDmgMax(i) !=
                kRd[i] ||
                miscmagic.mmpGirdleGiantRockWeight(i) !=
                kRw[i] ||
                miscmagic.mmpGirdleGiantBendBarsPct(i) !=
                kBb[i]) ++bad;
        // the kMisc3 rows this slice pins: 1-9,
        // the (C, F, T) marks on rows 4, 5, 8, 9
        static const int kLo[9] = {
            16, 17, 19, 21, 23, 26, 27, 28, 29,
        };
        static const int kHi[9] = {
            16, 18, 20, 22, 25, 26, 27, 28, 29,
        };
        static const int kMk[9] = {
            0, 0, 0, 1, 1, 0, 0, 1, 1,
        };
        for (int i = 0; i < 9; ++i)
            if (miscmagic_table3_footnotes.m3RowLo(1 + i) != kLo[i] ||
                miscmagic_table3_footnotes.m3RowHi(1 + i) != kHi[i]) ++bad;
        for (int i = 0; i < 9; ++i)
            if (miscmagic_table3_footnotes.m3UsableByCleric(1 + i) != kMk[i] ||
                miscmagic_table3_footnotes.m3UsableByFighter(1 + i) !=
                kMk[i] ||
                miscmagic_table3_footnotes.m3UsableByThief(1 + i) !=
                kMk[i] ||
                miscmagic_table3_footnotes.m3StarCount(1 + i) ||
                miscmagic_table3_footnotes.m3IsPerFacetValued(1 + i)) ++bad;
        printf("R267 misc magic prose part 11 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
