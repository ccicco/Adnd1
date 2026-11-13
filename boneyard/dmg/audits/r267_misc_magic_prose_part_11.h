    // ---- R267: the III.E misc magic explanation
    // prose part 11 ----
    // Flask of Curses through the Girdle of Giant
    // Strength, part2 lines 481-530 - the slice
    // pinning the kMisc3 rows 1-9.
    {
        int bad = 0;
        if (rules::mmpFlaskCurseOnFirstOpen() != 1 ||
            rules::mmpFlaskHarmlessAfterUse() != 1) ++bad;
        if (rules::mmpGauntDexBoostLow() != 4 ||
            rules::mmpGauntDexBoostMid() != 2 ||
            rules::mmpGauntDexBoostHigh() != 1 ||
            rules::mmpGauntDexThiefLevel() != 4 ||
            rules::mmpGauntDexThiefBonusPct() != 10) ++bad;
        if (rules::mmpGauntFumbDropPct() != 50 ||
            rules::mmpGauntFumbDexPenalty() != 2 ||
            rules::mmpGauntFumbRemoveCurseOnly() != 1 ||
            rules::mmpGauntOgreStrength() != 18 ||
            rules::mmpGauntOgreStrengthPercentile() != 0 ||
            rules::mmpGauntOgreHitBonus() != 3 ||
            rules::mmpGauntOgreDmgBonus() != 6) ++bad;
        if (rules::mmpGauntSwimUnderwaterInches() != 15 ||
            rules::mmpGauntSwimSurfaceInches() != 18 ||
            rules::mmpGauntSwimClimbSuccessPct() != 95 ||
            rules::mmpGauntSwimThiefSuccessTenthPct() !=
            995) ++bad;
        if (rules::mmpGemBrightLightSorts() != 3 ||
            rules::mmpGemBrightConeLengthFeet() != 10 ||
            rules::mmpGemBrightConeRadiusHalfFeet() != 5 ||
            rules::mmpGemBrightRayDiameterFeet() != 1 ||
            rules::mmpGemBrightRayLengthFeet() != 50 ||
            rules::mmpGemBrightDazzleMinRounds() != 1 ||
            rules::mmpGemBrightDazzleMaxRounds() != 4 ||
            rules::mmpGemBrightRayCharges() != 1) ++bad;
        if (rules::mmpGemBrightFlashLengthFeet() != 30 ||
            rules::mmpGemBrightFlashRadiusFeet() != 5 ||
            rules::mmpGemBrightBlindMinRounds() != 1 ||
            rules::mmpGemBrightBlindMaxRounds() != 4 ||
            rules::mmpGemBrightEyePenaltyMin() != 1 ||
            rules::mmpGemBrightEyePenaltyMax() != 4 ||
            rules::mmpGemBrightFlashCharges() != 5 ||
            rules::mmpGemBrightTotalCharges() != 50) ++bad;
        if (rules::mmpGemBrightDarknessDrainCharges() != 1 ||
            rules::mmpGemBrightDarknessRoundUseless() != 1 ||
            rules::mmpGemBrightDarknessDayUseless() != 1 ||
            rules::mmpGemBrightDarknessExpelCharges() !=
            5) ++bad;
        if (rules::mmpGemSeeCursoryRangeInches() != 30 ||
            rules::mmpGemSeeCarefulRangeInches() != 10 ||
            rules::mmpGemSeeCursoryAreaFeet() != 200 ||
            rules::mmpGemSeeCursoryRounds() != 1 ||
            rules::mmpGemSeeCarefulAreaFeet() != 100 ||
            rules::mmpGemSeeCarefulRounds() != 2 ||
            rules::mmpGemSeeHallucinationPct() != 5) ++bad;
        if (rules::mmpGirdleSexWishRestorePct() != 50 ||
            rules::mmpGirdleSexSexlessPct() != 10 ||
            rules::mmpGirdleGiantTypeCount() != 6 ||
            rules::mmpGirdleGiantRockDmgMin() != 1) ++bad;
        // the arithmetic: the two 5-charge expends
        if (rules::mmpGemBrightFlashCharges() !=
            rules::mmpGemBrightDarknessExpelCharges() ||
            rules::mmpGemBrightDazzleMinRounds() !=
            rules::mmpGemBrightBlindMinRounds() ||
            rules::mmpGemBrightDazzleMaxRounds() !=
            rules::mmpGemBrightBlindMaxRounds()) ++bad;
        // the giant strength ladders: strength and
        // damage climb by 1, bend bars by 10
        for (int i = 0; i < 5; ++i)
            if (rules::mmpGirdleGiantStrength(i + 1) !=
                rules::mmpGirdleGiantStrength(i) + 1 ||
                rules::mmpGirdleGiantDmgBonus(i + 1) !=
                rules::mmpGirdleGiantDmgBonus(i) + 1 ||
                rules::mmpGirdleGiantBendBarsPct(i + 1) !=
                rules::mmpGirdleGiantBendBarsPct(i) +
                10) ++bad;
        // the dice bands run 01-00 without gaps
        for (int i = 0; i < 5; ++i)
            if (rules::mmpGirdleGiantDiceLo(i + 1) !=
                rules::mmpGirdleGiantDiceHi(i) + 1) ++bad;
        if (rules::mmpGirdleGiantDiceLo(0) != 1 ||
            rules::mmpGirdleGiantDiceHi(5) != 100) ++bad;
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
            if (rules::mmpGirdleGiantStrength(i) != kStr[i] ||
                rules::mmpGirdleGiantHitBonus(i) != kHit[i] ||
                rules::mmpGirdleGiantOpenDoorsTop(i) !=
                kTop[i] ||
                rules::mmpGirdleGiantOpenDoorsBottom(i) !=
                kBot[i] ||
                rules::mmpGirdleGiantOpenChances(i) !=
                kCh[i] ||
                rules::mmpGirdleGiantOpenOutOf(i) !=
                kOf[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::mmpGirdleGiantWeightAllowance(i) !=
                kWa[i] ||
                rules::mmpGirdleGiantRangeInches(i) !=
                kRg[i] ||
                rules::mmpGirdleGiantRockDmgMax(i) !=
                kRd[i] ||
                rules::mmpGirdleGiantRockWeight(i) !=
                kRw[i] ||
                rules::mmpGirdleGiantBendBarsPct(i) !=
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
            if (rules::m3RowLo(1 + i) != kLo[i] ||
                rules::m3RowHi(1 + i) != kHi[i]) ++bad;
        for (int i = 0; i < 9; ++i)
            if (rules::m3UsableByCleric(1 + i) != kMk[i] ||
                rules::m3UsableByFighter(1 + i) !=
                kMk[i] ||
                rules::m3UsableByThief(1 + i) !=
                kMk[i] ||
                rules::m3StarCount(1 + i) ||
                rules::m3IsPerFacetValued(1 + i)) ++bad;
        printf("R267 misc magic prose part 11 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
