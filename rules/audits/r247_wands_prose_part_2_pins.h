    // ---- R247: the III.D wands explanation prose part 2 pins audit ----
    // DMG pp.144-145: the remaining ten
    // wands of the RODS, et al.
    // explanation prose.
    {
        Rodswands rodswands;
        Wands_illumination_to_secret_door_and_trap_location wands_illumination_to_secret_door_and_trap_location;
        int bad = 0;
        // the ten wands are the engine III.D
        // table wand rows 6-15 - bands 48-94,
        // the wand of wonder from 95 (the
        // R224 pins)
        if (rodswands.rswRowLo(19) != 48 ||
            rodswands.rswRowHi(28) != 94 ||
            rodswands.rswRowLo(29) != 95 ||
            rodswands.rswRowHi(29) != 100) ++bad;
        // Wand of Illumination - the four functions
        if (wands_illumination_to_secret_door_and_trap_location.wdIllumFunctionCount() != 4 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSpellLikeCount() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumDanceSegments() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumDanceCharges() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumLightSegments() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumLightCharges() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumContinualSegments() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumContinualCharges() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSunburstRangeInches() != 12 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSunburstDurationTenths() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSunburstGlobeInches() != 4 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSunburstUndeadLo() != 6 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSunburstUndeadHi() != 36 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSunburstBlindLo() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSunburstBlindHi() != 12 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSunburstSegments() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumSunburstCharges() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllumRechargeable() != 1) ++bad;
        // Wand of Illusion
        if (wands_illumination_to_secret_door_and_trap_location.wdIllusionRangeInches() != 14 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllusionSegments() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllusionChargesPerPortion() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllusionChargesPerRound() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdIllusionRechargeable() != 1) ++bad;
        // Wand of Lightning - the two functions
        if (wands_illumination_to_secret_door_and_trap_location.wdLightningFunctionCount() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningShockLo() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningShockHi() != 10 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningShockAc() != 10 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningShockCharges() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningBoltLo() != 12 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningBoltHi() != 36 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningBoltDice() != 6 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningBoltCharges() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningBoltSegments() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningFunctionsPerRound() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdLightningRechargeable() != 1) ++bad;
        // Wand of Magic Detection
        if (wands_illumination_to_secret_door_and_trap_location.wdMDetectRadiusInches() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdMDetectRounds() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdMDetectChargesPerTurn() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdMDetectMalfunctionPercent() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdMDetectRechargeable() != 1) ++bad;
        // Wand of Metal and Mineral Detection
        if (wands_illumination_to_secret_door_and_trap_location.wdMetalRadiusInches() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdMetalRounds() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdMetalChargesPerTurn() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdMetalRechargeable() != 1) ++bad;
        // Wand of Magic Missiles
        if (wands_illumination_to_secret_door_and_trap_location.wdMissileDamageLo() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdMissileDamageHi() != 5 ||
            wands_illumination_to_secret_door_and_trap_location.wdMissileSegments() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdMissileCharges() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdMissileMaxPerRound() != 2 ||
            wands_illumination_to_secret_door_and_trap_location.wdMissileRechargeable() != 1) ++bad;
        // Wand of Negation - the one wand
        // that cannot be recharged
        if (wands_illumination_to_secret_door_and_trap_location.wdNegateWandPercent() != 100 ||
            wands_illumination_to_secret_door_and_trap_location.wdNegateDevicePercent() != 75 ||
            wands_illumination_to_secret_door_and_trap_location.wdNegateSegments() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdNegateUsesPerRound() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdNegateCharges() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdNegateRechargeable() != 0) ++bad;
        // Wand of Paralyzation
        if (wands_illumination_to_secret_door_and_trap_location.wdParalyzeRangeInches() != 6 ||
            wands_illumination_to_secret_door_and_trap_location.wdParalyzeDurationLo() != 5 ||
            wands_illumination_to_secret_door_and_trap_location.wdParalyzeDurationHi() != 20 ||
            wands_illumination_to_secret_door_and_trap_location.wdParalyzeSegments() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdParalyzeCharges() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdParalyzeUsesPerRound() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdParalyzeRechargeable() != 1) ++bad;
        // Wand of Polymorphing
        if (wands_illumination_to_secret_door_and_trap_location.wdPolyRangeInches() != 6 ||
            wands_illumination_to_secret_door_and_trap_location.wdPolySegments() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdPolyCharges() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdPolyFunctionsPerRound() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdPolyRechargeable() != 1) ++bad;
        // Wand of Secret Door and Trap Location
        if (wands_illumination_to_secret_door_and_trap_location.wdSecretDoorRadiusHalfInches() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdTrapRadiusInches() != 3 ||
            wands_illumination_to_secret_door_and_trap_location.wdSecretRounds() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdSecretCharges() != 1 ||
            wands_illumination_to_secret_door_and_trap_location.wdSecretRechargeable() != 1) ++bad;
        printf("R247 wands prose part 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
