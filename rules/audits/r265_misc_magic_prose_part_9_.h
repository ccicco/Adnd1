    // ---- R265: the III.E misc magic explanation
    // prose part 9 ----
    // Drums of Deafening through Eyes of Petrification
    // plus the eye-mix note, part2 lines 402-429 -
    // the slice that completes the kMisc2 rows 19-29.
    {
        Miscmagic_drums_of_deafening_to_eyes_of_petrification miscmagic;
        Miscmagic_table2_footnotes miscmagic_table2_footnotes;
        int bad = 0;
        if (miscmagic.mmpDrumDeafDeafRangeInches() != 7 ||
            miscmagic.mmpDrumDeafStunRangeInches() != 1 ||
            miscmagic.mmpDrumDeafStunMinRounds() != 2 ||
            miscmagic.mmpDrumDeafStunMaxRounds() != 8 ||
            miscmagic.mmpDrumDeafHemisphereHalfFeet() !=
            3) ++bad;
        if (miscmagic.mmpDrumPanicRangeInches() != 12 ||
            miscmagic.mmpDrumPanicSafeZoneInches() != 2 ||
            miscmagic.mmpDrumPanicFleeTurns() != 1 ||
            miscmagic.mmpDrumPanicRestRoundsPerTurn() != 3 ||
            miscmagic.mmpDrumPanicInt2SaveMod() != -2 ||
            miscmagic.mmpDrumPanicInt1SaveMod() != -4 ||
            miscmagic.mmpDrumPanicHemisphereHalfFeet() !=
            3) ++bad;
        if (miscmagic.mmpDustAppearDurationMinTurns() != 2 ||
            miscmagic.mmpDustAppearDurationMaxTurns() != 20 ||
            miscmagic.mmpDustAppearPacketRadiusFeet() != 10 ||
            miscmagic.mmpDustAppearTubeStartFeet() != 1 ||
            miscmagic.mmpDustAppearTubeEndFeet() != 15 ||
            miscmagic.mmpDustAppearTubeLengthFeet() != 20 ||
            miscmagic.mmpDustAppearContainerMin() != 5 ||
            miscmagic.mmpDustAppearContainerMax() != 50) ++bad;
        if (miscmagic.mmpDustGoneDurationMinTurns() != 2 ||
            miscmagic.mmpDustGoneDurationMaxTurns() != 20 ||
            miscmagic.mmpDustGoneSprinkleMinTurns() != 11 ||
            miscmagic.mmpDustGoneSprinkleMaxTurns() != 20 ||
            miscmagic.mmpDustGoneAcBonusPlaces() != 4) ++bad;
        if (miscmagic.mmpDustChokeRadiusFeet() != 20 ||
            miscmagic.mmpDustChokeDisabledMinRounds() != 5 ||
            miscmagic.mmpDustChokeDisabledMaxRounds() !=
            20) ++bad;
        if (miscmagic.mmpEfreetiInsanePct() != 10 ||
            miscmagic.mmpEfreetiWishesPct() != 10 ||
            miscmagic.mmpEfreetiServePct() != 80 ||
            miscmagic.mmpEfreetiWishCount() != 3 ||
            miscmagic.mmpEfreetiReleaseSegments() != 1) ++bad;
        if (miscmagic.mmpEversmokeFirstRoundCubicFeet() !=
            50000 ||
            miscmagic.mmpEversmokePerRoundCubicFeet() !=
            10000 ||
            miscmagic.mmpEversmokeMaxCubicFeet() !=
            120000) ++bad;
        if (miscmagic.mmpEyesCharmTargetsPerRound() != 1 ||
            miscmagic.mmpEyesCharmBothSaveMod() != -2 ||
            miscmagic.mmpEyesCharmOneSaveMod() != 2) ++bad;
        if (miscmagic.mmpEyesEagleVisionFactor() != 100 ||
            miscmagic.mmpEyesEagleMinDistanceFeet() != 1 ||
            miscmagic.mmpEyesEagleSeeAtFeet() != 2000 ||
            miscmagic.mmpEyesEagleNormalSeeFeet() != 20 ||
            miscmagic.mmpEyesEagleSingleStunRounds() !=
            1) ++bad;
        if (miscmagic.mmpEyesMinuteVisionFactor() != 100 ||
            miscmagic.mmpEyesMinuteMaxDistanceFeet() != 1 ||
            miscmagic.mmpEyesPetrifyBasiliskGazePct() != 25 ||
            miscmagic.mmpEyesMixInsanityMinTurns() != 2 ||
            miscmagic.mmpEyesMixInsanityMaxTurns() != 8 ||
            miscmagic.mmpEyesMixInsanityDice() != 2) ++bad;
        // the arithmetic: the efreeti chances sum
        if (miscmagic.mmpEfreetiInsanePct() +
            miscmagic.mmpEfreetiWishesPct() +
            miscmagic.mmpEfreetiServePct() != 100) ++bad;
        if (miscmagic.mmpEversmokeFirstRoundCubicFeet() +
            7 * miscmagic.mmpEversmokePerRoundCubicFeet() !=
            miscmagic.mmpEversmokeMaxCubicFeet()) ++bad;
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
            if (miscmagic_table2_footnotes.m2RowLo(19 + i) != kLo[i] ||
                miscmagic_table2_footnotes.m2RowHi(19 + i) != kHi[i]) ++bad;
        for (int i = 0; i < 11; ++i)
            if (miscmagic_table2_footnotes.m2UsableByCleric(19 + i) ||
                miscmagic_table2_footnotes.m2IsPerPlusValued(19 + i) ||
                miscmagic_table2_footnotes.m2HasFeatureAsterisk(19 + i) ||
                miscmagic_table2_footnotes.m2UsableByMagicUser(19 + i) !=
                kM[i] ||
                miscmagic_table2_footnotes.m2IsTripleStar(19 + i) !=
                kTriple[i]) ++bad;
        // the row 26 (M) positive control, Eyes
        // of Charming; the row 29 triple-star
        // control, Eyes of Petrification
        if (!miscmagic_table2_footnotes.m2UsableByMagicUser(26)) ++bad;
        if (!miscmagic_table2_footnotes.m2IsTripleStar(29)) ++bad;
        printf("R265 misc magic prose part 9 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
