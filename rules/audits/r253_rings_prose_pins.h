    // ---- R253: the III.C rings explanation prose pins audit ----
    // DMG pp.137-138: the general mechanics and
    // the four lead rings (part 1 of 3).
    {
        int bad = 0;
        // the four lead rings are the engine III.C
        // table rows 1-15 (the R223 rings.h pins)
        if (rules::ringRowCount() != 24 ||
            rules::ringRowLo(0) != 1 || rules::ringRowHi(0) != 6 ||
            rules::ringRowLo(3) != 15 || rules::ringRowHi(3) != 15) ++bad;
        static const int kCLo[4] = {
            1, 7, 13, 15,
        };
        static const int kCHi[4] = {
            6, 12, 14, 15,
        };
        for (int i = 0; i < 4; ++i)
            if (rules::ringRowLo(i) != kCLo[i] ||
                rules::ringRowHi(i) != kCHi[i]) ++bad;
        // the djinni double-dagger: the prose flag
        // cross-pins the R223 charge-limited row 2
        if (rules::ringIsChargeLimited(2) != 1 ||
            rules::ringChargeLimitedCount() != 7) ++bad;
        // the contrariness additional-properties bands
        static const int kPLo[6] = {
            1, 21, 41, 61, 71, 81,
        };
        static const int kPHi[6] = {
            20, 40, 60, 70, 80, 100,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::rgpContrarinessPropLo(i) != kPLo[i] ||
                rules::rgpContrarinessPropHi(i) != kPHi[i]) ++bad;
        // the elemental command save penalty list
        static const int kPen[4] = {
            -2, -2, -2, -2,
        };
        for (int i = 0; i < 4; ++i)
            if (rules::rgpElemCommandSavePenalty(i) != kPen[i]) ++bad;
        // the general mechanics
        if (rules::rgpMaxWornCount() != 2 ||
            rules::rgpMaxPerHand() != 1 ||
            rules::rgpSpellLikeLevel() != 12 ||
            rules::rgpSmallCharMalfunctionPercent() != 20 ||
            rules::rgpCursedMalfunctionNamedCount() != 3) ++bad;
        // the closing paragraph cross-pins the level
        if (rules::rgpOperateLevelExperience() !=
            rules::rgpSpellLikeLevel() ||
            rules::rgpPowerActivationSegments() != 5) ++bad;
        // contrariness and djinni
        if (rules::rgpContrarinessPropertyRowCount() != 6 ||
            rules::rgpContrarinessShockingGraspPerRound() != 1 ||
            rules::rgpContrarinessStrengthScore() != 18 ||
            rules::rgpContrarinessRemoveCursePercent() != 100 ||
            rules::rgpDjinniAppearDelayRounds() != 1) ++bad;
        // elemental command: the combat modifications
        if (rules::rgpElemCommandTypeCount() != 4 ||
            rules::rgpElemCommandKeepAwayFeet() != 5 ||
            rules::rgpElemCommandCharmSaveMod() != -2 ||
            rules::rgpElemCommandElemToHitMod() != -1 ||
            rules::rgpElemCommandWearerDamagePerDieMod() != -1 ||
            rules::rgpElemCommandWearerSaveBonus() != 2 ||
            rules::rgpElemCommandWearerToHitBonus() != 4 ||
            rules::rgpElemCommandElemSaveMod() != -4 ||
            rules::rgpElemCommandWearerDamageBonus() != 6 ||
            rules::rgpElemCommandSavePenaltyRowCount() != 4 ||
            rules::rgpElemCommandMaxActivePowers() != 1) ++bad;
        // elemental command: the four power lists
        if (rules::rgpElemCommandAirPowerCount() != 5 ||
            rules::rgpElemCommandEarthPowerCount() != 6 ||
            rules::rgpElemCommandFirePowerCount() != 5 ||
            rules::rgpElemCommandWaterPowerCount() != 8) ++bad;
        // elemental command: the power frequencies
        if (rules::rgpElemCommandAirGustPerRound() != 1 ||
            rules::rgpElemCommandWallOfForcePerDay() != 1 ||
            rules::rgpElemCommandControlWindsPerWeek() != 1 ||
            rules::rgpElemCommandStoneTellPerDay() != 1 ||
            rules::rgpElemCommandPasswallPerDay() != 2 ||
            rules::rgpElemCommandWallOfStonePerDay() != 1 ||
            rules::rgpElemCommandStoneToFleshPerWeek() != 2 ||
            rules::rgpElemCommandMoveEarthPerWeek() != 1 ||
            rules::rgpElemCommandBurningHandsPerTurn() != 1 ||
            rules::rgpElemCommandPyrotechnicsPerDay() != 2 ||
            rules::rgpElemCommandWallOfFirePerDay() != 1 ||
            rules::rgpElemCommandFlameStrikePerWeek() != 2 ||
            rules::rgpElemCommandCreateWaterPerDay() != 1 ||
            rules::rgpElemCommandWallOfIcePerDay() != 1 ||
            rules::rgpElemCommandLowerWaterPerWeek() != 2 ||
            rules::rgpElemCommandPartWaterPerWeek() != 2 ||
            rules::rgpElemCommandWaterBreathingRadiusFeet() != 5) ++bad;
        printf("R253 rings prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
