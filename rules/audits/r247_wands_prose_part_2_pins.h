    // ---- R247: the III.D wands explanation prose part 2 pins audit ----
    // DMG pp.144-145: the remaining ten
    // wands of the RODS, et al.
    // explanation prose.
    {
        int bad = 0;
        // the ten wands are the engine III.D
        // table wand rows 6-15 - bands 48-94,
        // the wand of wonder from 95 (the
        // R224 pins)
        if (rules::rswRowLo(19) != 48 ||
            rules::rswRowHi(28) != 94 ||
            rules::rswRowLo(29) != 95 ||
            rules::rswRowHi(29) != 100) ++bad;
        // Wand of Illumination - the four functions
        if (rules::wdIllumFunctionCount() != 4 ||
            rules::wdIllumSpellLikeCount() != 3 ||
            rules::wdIllumDanceSegments() != 1 ||
            rules::wdIllumDanceCharges() != 1 ||
            rules::wdIllumLightSegments() != 2 ||
            rules::wdIllumLightCharges() != 1 ||
            rules::wdIllumContinualSegments() != 2 ||
            rules::wdIllumContinualCharges() != 2 ||
            rules::wdIllumSunburstRangeInches() != 12 ||
            rules::wdIllumSunburstDurationTenths() != 1 ||
            rules::wdIllumSunburstGlobeInches() != 4 ||
            rules::wdIllumSunburstUndeadLo() != 6 ||
            rules::wdIllumSunburstUndeadHi() != 36 ||
            rules::wdIllumSunburstBlindLo() != 2 ||
            rules::wdIllumSunburstBlindHi() != 12 ||
            rules::wdIllumSunburstSegments() != 3 ||
            rules::wdIllumSunburstCharges() != 3 ||
            rules::wdIllumRechargeable() != 1) ++bad;
        // Wand of Illusion
        if (rules::wdIllusionRangeInches() != 14 ||
            rules::wdIllusionSegments() != 3 ||
            rules::wdIllusionChargesPerPortion() != 1 ||
            rules::wdIllusionChargesPerRound() != 1 ||
            rules::wdIllusionRechargeable() != 1) ++bad;
        // Wand of Lightning - the two functions
        if (rules::wdLightningFunctionCount() != 2 ||
            rules::wdLightningShockLo() != 1 ||
            rules::wdLightningShockHi() != 10 ||
            rules::wdLightningShockAc() != 10 ||
            rules::wdLightningShockCharges() != 1 ||
            rules::wdLightningBoltLo() != 12 ||
            rules::wdLightningBoltHi() != 36 ||
            rules::wdLightningBoltDice() != 6 ||
            rules::wdLightningBoltCharges() != 2 ||
            rules::wdLightningBoltSegments() != 2 ||
            rules::wdLightningFunctionsPerRound() != 1 ||
            rules::wdLightningRechargeable() != 1) ++bad;
        // Wand of Magic Detection
        if (rules::wdMDetectRadiusInches() != 3 ||
            rules::wdMDetectRounds() != 1 ||
            rules::wdMDetectChargesPerTurn() != 1 ||
            rules::wdMDetectMalfunctionPercent() != 2 ||
            rules::wdMDetectRechargeable() != 1) ++bad;
        // Wand of Metal and Mineral Detection
        if (rules::wdMetalRadiusInches() != 3 ||
            rules::wdMetalRounds() != 1 ||
            rules::wdMetalChargesPerTurn() != 1 ||
            rules::wdMetalRechargeable() != 1) ++bad;
        // Wand of Magic Missiles
        if (rules::wdMissileDamageLo() != 2 ||
            rules::wdMissileDamageHi() != 5 ||
            rules::wdMissileSegments() != 3 ||
            rules::wdMissileCharges() != 1 ||
            rules::wdMissileMaxPerRound() != 2 ||
            rules::wdMissileRechargeable() != 1) ++bad;
        // Wand of Negation - the one wand
        // that cannot be recharged
        if (rules::wdNegateWandPercent() != 100 ||
            rules::wdNegateDevicePercent() != 75 ||
            rules::wdNegateSegments() != 1 ||
            rules::wdNegateUsesPerRound() != 1 ||
            rules::wdNegateCharges() != 1 ||
            rules::wdNegateRechargeable() != 0) ++bad;
        // Wand of Paralyzation
        if (rules::wdParalyzeRangeInches() != 6 ||
            rules::wdParalyzeDurationLo() != 5 ||
            rules::wdParalyzeDurationHi() != 20 ||
            rules::wdParalyzeSegments() != 3 ||
            rules::wdParalyzeCharges() != 1 ||
            rules::wdParalyzeUsesPerRound() != 1 ||
            rules::wdParalyzeRechargeable() != 1) ++bad;
        // Wand of Polymorphing
        if (rules::wdPolyRangeInches() != 6 ||
            rules::wdPolySegments() != 3 ||
            rules::wdPolyCharges() != 1 ||
            rules::wdPolyFunctionsPerRound() != 1 ||
            rules::wdPolyRechargeable() != 1) ++bad;
        // Wand of Secret Door and Trap Location
        if (rules::wdSecretDoorRadiusHalfInches() != 3 ||
            rules::wdTrapRadiusInches() != 3 ||
            rules::wdSecretRounds() != 1 ||
            rules::wdSecretCharges() != 1 ||
            rules::wdSecretRechargeable() != 1) ++bad;
        printf("R247 wands prose part 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
