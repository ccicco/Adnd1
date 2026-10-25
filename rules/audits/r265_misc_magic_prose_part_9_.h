    // ---- R265: the III.E misc magic explanation
    // prose part 9 ----
    // Drums of Deafening through Eyes of Petrification
    // plus the eye-mix note, part2 lines 402-429 -
    // the slice that completes the kMisc2 rows 19-29.
    {
        int bad = 0;
        if (rules::mmpDrumDeafDeafRangeInches() != 7 ||
            rules::mmpDrumDeafStunRangeInches() != 1 ||
            rules::mmpDrumDeafStunMinRounds() != 2 ||
            rules::mmpDrumDeafStunMaxRounds() != 8 ||
            rules::mmpDrumDeafHemisphereHalfFeet() !=
            3) ++bad;
        if (rules::mmpDrumPanicRangeInches() != 12 ||
            rules::mmpDrumPanicSafeZoneInches() != 2 ||
            rules::mmpDrumPanicFleeTurns() != 1 ||
            rules::mmpDrumPanicRestRoundsPerTurn() != 3 ||
            rules::mmpDrumPanicInt2SaveMod() != -2 ||
            rules::mmpDrumPanicInt1SaveMod() != -4 ||
            rules::mmpDrumPanicHemisphereHalfFeet() !=
            3) ++bad;
        if (rules::mmpDustAppearDurationMinTurns() != 2 ||
            rules::mmpDustAppearDurationMaxTurns() != 20 ||
            rules::mmpDustAppearPacketRadiusFeet() != 10 ||
            rules::mmpDustAppearTubeStartFeet() != 1 ||
            rules::mmpDustAppearTubeEndFeet() != 15 ||
            rules::mmpDustAppearTubeLengthFeet() != 20 ||
            rules::mmpDustAppearContainerMin() != 5 ||
            rules::mmpDustAppearContainerMax() != 50) ++bad;
        if (rules::mmpDustGoneDurationMinTurns() != 2 ||
            rules::mmpDustGoneDurationMaxTurns() != 20 ||
            rules::mmpDustGoneSprinkleMinTurns() != 11 ||
            rules::mmpDustGoneSprinkleMaxTurns() != 20 ||
            rules::mmpDustGoneAcBonusPlaces() != 4) ++bad;
        if (rules::mmpDustChokeRadiusFeet() != 20 ||
            rules::mmpDustChokeDisabledMinRounds() != 5 ||
            rules::mmpDustChokeDisabledMaxRounds() !=
            20) ++bad;
        if (rules::mmpEfreetiInsanePct() != 10 ||
            rules::mmpEfreetiWishesPct() != 10 ||
            rules::mmpEfreetiServePct() != 80 ||
            rules::mmpEfreetiWishCount() != 3 ||
            rules::mmpEfreetiReleaseSegments() != 1) ++bad;
        if (rules::mmpEversmokeFirstRoundCubicFeet() !=
            50000 ||
            rules::mmpEversmokePerRoundCubicFeet() !=
            10000 ||
            rules::mmpEversmokeMaxCubicFeet() !=
            120000) ++bad;
        if (rules::mmpEyesCharmTargetsPerRound() != 1 ||
            rules::mmpEyesCharmBothSaveMod() != -2 ||
            rules::mmpEyesCharmOneSaveMod() != 2) ++bad;
        if (rules::mmpEyesEagleVisionFactor() != 100 ||
            rules::mmpEyesEagleMinDistanceFeet() != 1 ||
            rules::mmpEyesEagleSeeAtFeet() != 2000 ||
            rules::mmpEyesEagleNormalSeeFeet() != 20 ||
            rules::mmpEyesEagleSingleStunRounds() !=
            1) ++bad;
        if (rules::mmpEyesMinuteVisionFactor() != 100 ||
            rules::mmpEyesMinuteMaxDistanceFeet() != 1 ||
            rules::mmpEyesPetrifyBasiliskGazePct() != 25 ||
            rules::mmpEyesMixInsanityMinTurns() != 2 ||
            rules::mmpEyesMixInsanityMaxTurns() != 8 ||
            rules::mmpEyesMixInsanityDice() != 2) ++bad;
        // the arithmetic: the efreeti chances sum
        if (rules::mmpEfreetiInsanePct() +
            rules::mmpEfreetiWishesPct() +
            rules::mmpEfreetiServePct() != 100) ++bad;
        if (rules::mmpEversmokeFirstRoundCubicFeet() +
            7 * rules::mmpEversmokePerRoundCubicFeet() !=
            rules::mmpEversmokeMaxCubicFeet()) ++bad;
        // the kMisc2 rows this slice pins: 19-29,
        // completing the 30-row table
        static const int kLo[11] = {
            77, 78, 80, 86, 92, 93, 94, 95,
            96, 98, 100,
        };
        static const int kHi[11] = {
            77, 79, 85, 91, 92, 93, 94, 95,
            97, 99, 100,
        };
        static const int kM[11] = {
            0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0,
        };
        static const int kTriple[11] = {
            0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1,
        };
        for (int i = 0; i < 11; ++i)
            if (rules::m2RowLo(19 + i) != kLo[i] ||
                rules::m2RowHi(19 + i) != kHi[i]) ++bad;
        for (int i = 0; i < 11; ++i)
            if (rules::m2UsableByCleric(19 + i) ||
                rules::m2IsPerPlusValued(19 + i) ||
                rules::m2HasFeatureAsterisk(19 + i) ||
                rules::m2UsableByMagicUser(19 + i) !=
                kM[i] ||
                rules::m2IsTripleStar(19 + i) !=
                kTriple[i]) ++bad;
        // the row 26 (M) positive control, Eyes
        // of Charming; the row 29 triple-star
        // control, Eyes of Petrification
        if (!rules::m2UsableByMagicUser(26)) ++bad;
        if (!rules::m2IsTripleStar(29)) ++bad;
        printf("R265 misc magic prose part 9 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
