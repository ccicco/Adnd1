    // ---- R254: the III.C rings explanation prose part 2 pins audit ----
    // DMG pp.138-139: Feather Falling through Shooting
    // Stars (part 2 of 3).
    {
        int bad = 0;
        // the ten rings are the engine III.C table
        // rows 16-63 (the R223 rings.h pins)
        if (rules::ringRowCount() != 24 ||
            rules::ringRowLo(4) != 16 || rules::ringRowHi(4) != 21 ||
            rules::ringRowLo(13) != 62 || rules::ringRowHi(13) != 63) ++bad;
        static const int kCLo[10] = {
            16, 22, 28, 31, 34, 41, 44, 45, 61, 62,
        };
        static const int kCHi[10] = {
            21, 27, 30, 33, 40, 43, 44, 60, 61, 63,
        };
        for (int i = 0; i < 10; ++i)
            if (rules::ringRowLo(4 + i) != kCLo[i] ||
                rules::ringRowHi(4 + i) != kCHi[i]) ++bad;
        // the double-dagger cross-pins (the R255
        // fix resolved the R223 divergence: row 9
        // Mammal Control flagged, row 11 Protection
        // not; the rows may now be asserted)
        if (rules::ringIsChargeLimited(7) != 1 ||
            rules::ringIsChargeLimited(9) != 1 ||
            rules::ringIsChargeLimited(10) != 1 ||
            rules::ringIsChargeLimited(11) != 0 ||
            rules::ringChargeLimitedCount() != 7) ++bad;
        // the protection 7-row value table
        static const int kPlo[7] = {
            1, 71, 83, 84, 91, 92, 98,
        };
        static const int kPhi[7] = {
            70, 82, 83, 90, 91, 97, 100,
        };
        static const int kPac[7] = {
            1, 2, 2, 3, 3, 4, 6,
        };
        static const int kPsv[7] = {
            1, 2, 2, 3, 3, 2, 1,
        };
        static const int kPrd[7] = {
            0, 0, 1, 0, 1, 0, 0,
        };
        for (int i = 0; i < 7; ++i)
            if (rules::rgpProtectionRowLo(i) != kPlo[i] ||
                rules::rgpProtectionRowHi(i) != kPhi[i] ||
                rules::rgpProtectionRowAc(i) != kPac[i] ||
                rules::rgpProtectionRowSave(i) != kPsv[i] ||
                rules::rgpProtectionRowRadius(i) != kPrd[i]) ++bad;
        // the ball lightning charge tiers
        static const int kBall[4] = {
            4, 3, 2, 1,
        };
        for (int i = 0; i < 4; ++i)
            if (rules::rgpBallLightningChargeBalls(i) != kBall[i]) ++bad;
        // feather falling and fire resistance
        if (rules::rgpFeatherFallMinFeet() != 5 ||
            rules::rgpFireResistLargeFireDamagePerRound() != 10 ||
            rules::rgpFireResistLargeFirePerSegment() != 1 ||
            rules::rgpFireResistHotSaveBonus() != 4 ||
            rules::rgpFireResistHotDamagePerDieMod() != -2 ||
            rules::rgpFireResistHotDieFloor() != 1 ||
            rules::rgpFireResistVeryHotExposureMax() != 24 ||
            rules::rgpFireResistExceptionalExposureMin() != 25) ++bad;
        // human influence and invisibility
        if (rules::rgpHumanInfluenceCharisma() != 18 ||
            rules::rgpHumanInfluenceCharmLevels() != 21 ||
            rules::rgpHumanInfluenceUsesPerDay() != 1 ||
            rules::rgpHumanInfluenceCastSegments() != 3 ||
            rules::rgpHumanInfluenceDaggerFlag() != 1 ||
            rules::rgpInvisibilityInaudiblePercent() != 10) ++bad;
        // mammal control and multiple wishes
        if (rules::rgpMammalControlMaxIntelligence() != 4 ||
            rules::rgpMammalControlHitDice() != 30 ||
            rules::rgpMammalControlTimeSegments() != 3 ||
            rules::rgpMammalControlDaggerFlag() != 1 ||
            rules::rgpMultipleWishesLo() != 2 ||
            rules::rgpMultipleWishesHi() != 8 ||
            rules::rgpMultipleWishesDice() != 2 ||
            rules::rgpMultipleWishesFaces() != 4 ||
            rules::rgpMultipleWishesDaggerFlag() != 1) ++bad;
        // protection scalars and regeneration
        if (rules::rgpProtectionRowCount() != 7 ||
            rules::rgpProtectionRadiusFeet() != 5 ||
            rules::rgpProtectionDaggerFlag() != 0 ||
            rules::rgpRegenerationFormCount() != 2 ||
            rules::rgpRegenerationHpPerTurn() != 1 ||
            rules::rgpRegenerationVampiricPercent() != 50 ||
            rules::rgpRegenerationStandardBandHi() != 90 ||
            rules::rgpRegenerationVampiricBandLo() != 91) ++bad;
        // shooting stars: the night functions
        if (rules::rgpShootingStarsModeCount() != 2 ||
            rules::rgpShootingStarsDancingLightsPerHour() != 1 ||
            rules::rgpShootingStarsLightPerNight() != 2 ||
            rules::rgpShootingStarsLightRangeInches() != 12 ||
            rules::rgpShootingStarsBallLightningPerNight() != 1 ||
            rules::rgpBallLightningCountLo() != 1 ||
            rules::rgpBallLightningCountHi() != 4 ||
            rules::rgpBallLightningRangeInches() != 12 ||
            rules::rgpBallLightningDurationRounds() != 4 ||
            rules::rgpBallLightningMoveInches() != 4 ||
            rules::rgpBallLightningDiameterFeet() != 3 ||
            rules::rgpBallLightningChargeTierCount() != 4) ++bad;
        // shooting stars: the missiles and indoors
        if (rules::rgpShootingStarsPerWeek() != 3 ||
            rules::rgpShootingStarImpactDamage() != 12 ||
            rules::rgpShootingStarBurstDamage() != 24 ||
            rules::rgpShootingStarBurstDiameterInches() != 1 ||
            rules::rgpShootingStarRangeInches() != 7 ||
            rules::rgpShootingStarSaveModNear() != -3 ||
            rules::rgpShootingStarNearLimitInches() != 2 ||
            rules::rgpShootingStarSaveModMid() != -1 ||
            rules::rgpShootingStarMidLimitInches() != 4 ||
            rules::rgpShootingStarsFaerieFirePerDay() != 2 ||
            rules::rgpShootingStarsSparkShowerPerDay() != 1 ||
            rules::rgpSparkShowerLengthFeet() != 20 ||
            rules::rgpSparkShowerBreadthFeet() != 10 ||
            rules::rgpSparkShowerDamageLo() != 2 ||
            rules::rgpSparkShowerDamageHi() != 8 ||
            rules::rgpSparkShowerMetalDamageLo() != 4 ||
            rules::rgpSparkShowerMetalDamageHi() != 16 ||
            rules::rgpShootingStarsCastSegments() != 5) ++bad;
        printf("R254 rings prose part 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
