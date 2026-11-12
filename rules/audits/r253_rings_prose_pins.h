    // ---- R253: the III.C rings explanation prose pins audit ----
    // DMG pp.137-138: the general mechanics and
    // the four lead rings (part 1 of 3).
    {
        Rings rings;
        Rings_mechanics_contrariness_to_elemental_command rings_mechanics_contrariness_to_elemental_command;
        int bad = 0;
        // the four lead rings are the engine III.C
        // table rows 1-15 (the R223 rings.h pins)
        if (rings.ringRowCount() != 24 ||
            rings.ringRowLo(0) != 1 || rings.ringRowHi(0) != 6 ||
            rings.ringRowLo(3) != 15 || rings.ringRowHi(3) != 15) ++bad;
        static const int kCLo[4] = {
            1, 7, 13, 15,
        };
        static const int kCHi[4] = {
            6, 12, 14, 15,
        };
        for (int i = 0; i < 4; ++i)
            if (rings.ringRowLo(i) != kCLo[i] ||
                rings.ringRowHi(i) != kCHi[i]) ++bad;
        // the djinni double-dagger: the prose flag
        // cross-pins the R223 charge-limited row 2
        if (rings.ringIsChargeLimited(2) != 1 ||
            rings.ringChargeLimitedCount() != 7) ++bad;
        // the contrariness additional-properties bands
        static const int kPLo[6] = {
            1, 21, 41, 61, 71, 81,
        };
        static const int kPHi[6] = {
            20, 40, 60, 70, 80, 100,
        };
        for (int i = 0; i < 6; ++i)
            if (rings_mechanics_contrariness_to_elemental_command.rgpContrarinessPropLo(i) != kPLo[i] ||
                rings_mechanics_contrariness_to_elemental_command.rgpContrarinessPropHi(i) != kPHi[i]) ++bad;
        // the elemental command save penalty list
        static const int kPen[4] = {
            -2, -2, -2, -2,
        };
        for (int i = 0; i < 4; ++i)
            if (rings_mechanics_contrariness_to_elemental_command.rgpElemCommandSavePenalty(i) != kPen[i]) ++bad;
        // the general mechanics
        if (rings_mechanics_contrariness_to_elemental_command.rgpMaxWornCount() != 2 ||
            rings_mechanics_contrariness_to_elemental_command.rgpMaxPerHand() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpSpellLikeLevel() != 12 ||
            rings_mechanics_contrariness_to_elemental_command.rgpSmallCharMalfunctionPercent() != 20 ||
            rings_mechanics_contrariness_to_elemental_command.rgpCursedMalfunctionNamedCount() != 3) ++bad;
        // the closing paragraph cross-pins the level
        if (rings_mechanics_contrariness_to_elemental_command.rgpOperateLevelExperience() !=
            rings_mechanics_contrariness_to_elemental_command.rgpSpellLikeLevel() ||
            rings_mechanics_contrariness_to_elemental_command.rgpPowerActivationSegments() != 5) ++bad;
        // contrariness and djinni
        if (rings_mechanics_contrariness_to_elemental_command.rgpContrarinessPropertyRowCount() != 6 ||
            rings_mechanics_contrariness_to_elemental_command.rgpContrarinessShockingGraspPerRound() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpContrarinessStrengthScore() != 18 ||
            rings_mechanics_contrariness_to_elemental_command.rgpContrarinessRemoveCursePercent() != 100 ||
            rings_mechanics_contrariness_to_elemental_command.rgpDjinniAppearDelayRounds() != 1) ++bad;
        // elemental command: the combat modifications
        if (rings_mechanics_contrariness_to_elemental_command.rgpElemCommandTypeCount() != 4 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandKeepAwayFeet() != 5 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandCharmSaveMod() != -2 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandElemToHitMod() != -1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWearerDamagePerDieMod() != -1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWearerSaveBonus() != 2 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWearerToHitBonus() != 4 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandElemSaveMod() != -4 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWearerDamageBonus() != 6 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandSavePenaltyRowCount() != 4 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandMaxActivePowers() != 1) ++bad;
        // elemental command: the four power lists
        if (rings_mechanics_contrariness_to_elemental_command.rgpElemCommandAirPowerCount() != 5 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandEarthPowerCount() != 6 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandFirePowerCount() != 5 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWaterPowerCount() != 8) ++bad;
        // elemental command: the power frequencies
        if (rings_mechanics_contrariness_to_elemental_command.rgpElemCommandAirGustPerRound() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWallOfForcePerDay() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandControlWindsPerWeek() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandStoneTellPerDay() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandPasswallPerDay() != 2 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWallOfStonePerDay() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandStoneToFleshPerWeek() != 2 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandMoveEarthPerWeek() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandBurningHandsPerTurn() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandPyrotechnicsPerDay() != 2 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWallOfFirePerDay() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandFlameStrikePerWeek() != 2 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandCreateWaterPerDay() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWallOfIcePerDay() != 1 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandLowerWaterPerWeek() != 2 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandPartWaterPerWeek() != 2 ||
            rings_mechanics_contrariness_to_elemental_command.rgpElemCommandWaterBreathingRadiusFeet() != 5) ++bad;
        printf("R253 rings prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
