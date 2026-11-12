    // ---- R254: the III.C rings explanation prose part 2 pins audit ----
    // DMG pp.138-139: Feather Falling through Shooting
    // Stars (part 2 of 3).
    {
        Rings rings;
        Rings_feather_falling_to_shooting_stars rings_feather_falling_to_shooting_stars;
        int bad = 0;
        // the ten rings are the engine III.C table
        // rows 16-63 (the R223 rings.h pins)
        if (rings.ringRowCount() != 24 ||
            rings.ringRowLo(4) != 16 || rings.ringRowHi(4) != 21 ||
            rings.ringRowLo(13) != 62 || rings.ringRowHi(13) != 63) ++bad;
        static const int kCLo[10] = {
            16, 22, 28, 31, 34, 41, 44, 45, 61, 62,
        };
        static const int kCHi[10] = {
            21, 27, 30, 33, 40, 43, 44, 60, 61, 63,
        };
        for (int i = 0; i < 10; ++i)
            if (rings.ringRowLo(4 + i) != kCLo[i] ||
                rings.ringRowHi(4 + i) != kCHi[i]) ++bad;
        // the double-dagger cross-pins (the R255
        // fix resolved the R223 divergence: row 9
        // Mammal Control flagged, row 11 Protection
        // not; the rows may now be asserted)
        if (rings.ringIsChargeLimited(7) != 1 ||
            rings.ringIsChargeLimited(9) != 1 ||
            rings.ringIsChargeLimited(10) != 1 ||
            rings.ringIsChargeLimited(11) != 0 ||
            rings.ringChargeLimitedCount() != 7) ++bad;
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
            if (rings_feather_falling_to_shooting_stars.rgpProtectionRowLo(i) != kPlo[i] ||
                rings_feather_falling_to_shooting_stars.rgpProtectionRowHi(i) != kPhi[i] ||
                rings_feather_falling_to_shooting_stars.rgpProtectionRowAc(i) != kPac[i] ||
                rings_feather_falling_to_shooting_stars.rgpProtectionRowSave(i) != kPsv[i] ||
                rings_feather_falling_to_shooting_stars.rgpProtectionRowRadius(i) != kPrd[i]) ++bad;
        // the ball lightning charge tiers
        static const int kBall[4] = {
            4, 3, 2, 1,
        };
        for (int i = 0; i < 4; ++i)
            if (rings_feather_falling_to_shooting_stars.rgpBallLightningChargeBalls(i) != kBall[i]) ++bad;
        // feather falling and fire resistance
        if (rings_feather_falling_to_shooting_stars.rgpFeatherFallMinFeet() != 5 ||
            rings_feather_falling_to_shooting_stars.rgpFireResistLargeFireDamagePerRound() != 10 ||
            rings_feather_falling_to_shooting_stars.rgpFireResistLargeFirePerSegment() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpFireResistHotSaveBonus() != 4 ||
            rings_feather_falling_to_shooting_stars.rgpFireResistHotDamagePerDieMod() != -2 ||
            rings_feather_falling_to_shooting_stars.rgpFireResistHotDieFloor() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpFireResistVeryHotExposureMax() != 24 ||
            rings_feather_falling_to_shooting_stars.rgpFireResistExceptionalExposureMin() != 25) ++bad;
        // human influence and invisibility
        if (rings_feather_falling_to_shooting_stars.rgpHumanInfluenceCharisma() != 18 ||
            rings_feather_falling_to_shooting_stars.rgpHumanInfluenceCharmLevels() != 21 ||
            rings_feather_falling_to_shooting_stars.rgpHumanInfluenceUsesPerDay() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpHumanInfluenceCastSegments() != 3 ||
            rings_feather_falling_to_shooting_stars.rgpHumanInfluenceDaggerFlag() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpInvisibilityInaudiblePercent() != 10) ++bad;
        // mammal control and multiple wishes
        if (rings_feather_falling_to_shooting_stars.rgpMammalControlMaxIntelligence() != 4 ||
            rings_feather_falling_to_shooting_stars.rgpMammalControlHitDice() != 30 ||
            rings_feather_falling_to_shooting_stars.rgpMammalControlTimeSegments() != 3 ||
            rings_feather_falling_to_shooting_stars.rgpMammalControlDaggerFlag() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpMultipleWishesLo() != 2 ||
            rings_feather_falling_to_shooting_stars.rgpMultipleWishesHi() != 8 ||
            rings_feather_falling_to_shooting_stars.rgpMultipleWishesDice() != 2 ||
            rings_feather_falling_to_shooting_stars.rgpMultipleWishesFaces() != 4 ||
            rings_feather_falling_to_shooting_stars.rgpMultipleWishesDaggerFlag() != 1) ++bad;
        // protection scalars and regeneration
        if (rings_feather_falling_to_shooting_stars.rgpProtectionRowCount() != 7 ||
            rings_feather_falling_to_shooting_stars.rgpProtectionRadiusFeet() != 5 ||
            rings_feather_falling_to_shooting_stars.rgpProtectionDaggerFlag() != 0 ||
            rings_feather_falling_to_shooting_stars.rgpRegenerationFormCount() != 2 ||
            rings_feather_falling_to_shooting_stars.rgpRegenerationHpPerTurn() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpRegenerationVampiricPercent() != 50 ||
            rings_feather_falling_to_shooting_stars.rgpRegenerationStandardBandHi() != 90 ||
            rings_feather_falling_to_shooting_stars.rgpRegenerationVampiricBandLo() != 91) ++bad;
        // shooting stars: the night functions
        if (rings_feather_falling_to_shooting_stars.rgpShootingStarsModeCount() != 2 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarsDancingLightsPerHour() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarsLightPerNight() != 2 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarsLightRangeInches() != 12 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarsBallLightningPerNight() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpBallLightningCountLo() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpBallLightningCountHi() != 4 ||
            rings_feather_falling_to_shooting_stars.rgpBallLightningRangeInches() != 12 ||
            rings_feather_falling_to_shooting_stars.rgpBallLightningDurationRounds() != 4 ||
            rings_feather_falling_to_shooting_stars.rgpBallLightningMoveInches() != 4 ||
            rings_feather_falling_to_shooting_stars.rgpBallLightningDiameterFeet() != 3 ||
            rings_feather_falling_to_shooting_stars.rgpBallLightningChargeTierCount() != 4) ++bad;
        // shooting stars: the missiles and indoors
        if (rings_feather_falling_to_shooting_stars.rgpShootingStarsPerWeek() != 3 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarImpactDamage() != 12 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarBurstDamage() != 24 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarBurstDiameterInches() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarRangeInches() != 7 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarSaveModNear() != -3 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarNearLimitInches() != 2 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarSaveModMid() != -1 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarMidLimitInches() != 4 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarsFaerieFirePerDay() != 2 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarsSparkShowerPerDay() != 1 ||
            rings_feather_falling_to_shooting_stars.rgpSparkShowerLengthFeet() != 20 ||
            rings_feather_falling_to_shooting_stars.rgpSparkShowerBreadthFeet() != 10 ||
            rings_feather_falling_to_shooting_stars.rgpSparkShowerDamageLo() != 2 ||
            rings_feather_falling_to_shooting_stars.rgpSparkShowerDamageHi() != 8 ||
            rings_feather_falling_to_shooting_stars.rgpSparkShowerMetalDamageLo() != 4 ||
            rings_feather_falling_to_shooting_stars.rgpSparkShowerMetalDamageHi() != 16 ||
            rings_feather_falling_to_shooting_stars.rgpShootingStarsCastSegments() != 5) ++bad;
        printf("R254 rings prose part 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
