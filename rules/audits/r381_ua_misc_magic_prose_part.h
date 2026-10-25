    // ---- R381: the UA misc magic
    // prose part 1 pin audit ----
    // The R398 clean read fills
    // every flagged hole this
    // block names.
    // The A-C items (pp. 97-100),
    // thirteen pins: eight fully
    // clean (beads of force,
    // boots of the north, boots
    // winged, bracers of archery,
    // bracers of brachiation,
    // cloak of arachnidia, cloak
    // of the bat, cyclocone)
    // plus five mechanics-clean
    // with flagged holes (the
    // amulet, the anything item,
    // the boccob book, the boots
    // of varied tracks, the
    // chime). D-Z rides the
    // later parts. The R380 seam
    // cross-checks the wands
    // ledger, the R375 seam the
    // misc band; the census
    // 307 -> 308.
    {
        using namespace rules;
        int bad = 0;
        // ---- the amulet versus undead ----
            if (!uammAmuTurnsAsCleric()) ++bad;
            if (!uammAmuGlowsWhenPresented()) ++bad;
            static const int kAmuL[5] = {
                5, 6, 7, 8, 9};
            static const int kAmuLo[5] = {
                1, 31, 56, 76, 91};
            static const int kAmuHi[5] = {
                30, 55, 75, 90, 100};
            if (uammAmuBandCount() != 5) ++bad;
            for (int i = 0; i < 5; ++i) {
                if (uammAmuLevelForBand(i)
                        != kAmuL[i]) ++bad;
                if (uammAmuBandLo(i) != kAmuLo[i])
                    ++bad;
                if (uammAmuBandHi(i) != kAmuHi[i])
                    ++bad;
                if (i < 4 && kAmuHi[i] + 1
                        != kAmuLo[i + 1]) ++bad;
            }
            if (uammAmuLevelForBand(4) != 9)
                ++bad;
            if (uammAmuNinthCellGarbles()) ++bad;
            if (!uammAmuMustBeWorn()) ++bad;
            if (!uammAmuInertWhenNotWorn()) ++bad;
            if (uammAmuInertDaysOnDonning() != 7)
                ++bad;
            if (uammAmuXpPerLevel() != 200) ++bad;
            if (uammAmuGpPerLevel() != 1000) ++bad;
            // the gp value rides at
            // five times the xp value
            if (uammAmuGpPerLevel()
                    != 5 * uammAmuXpPerLevel())
                ++bad;
        // ---- the anything item ----
            if (!uammAnyBecomesAnyMiscItem())
                ++bad;
            if (!uammAnyExcludesArtifactsRelics())
                ++bad;
            if (!uammAnyNoFormRepeated()) ++bad;
            if (!uammAnyDiesWithDestructiveForms())
                ++bad;
            if (!uammAnyShortTermReturnsOnce())
                ++bad;
            if (!uammAnyLongTermDisappears())
                ++bad;
            if (uammAnyLongTermUseLimit() != 3)
                ++bad;
            if (uammAnyTailGarbles()) ++bad;
        // ---- the beads of force ----
            if (uammBeaDiamEighthIn() != 6) ++bad;
            if (uammBeaWeightOunces() != 1) ++bad;
            if (uammBeaHurlRangeIn() != 3) ++bad;
            if (uammBeaDmgDice() != 5) ++bad;
            if (uammBeaDmgLo() != 5) ++bad;
            if (uammBeaDmgHi() != 20) ++bad;
            if (uammBeaBlastRadiusFt() != 10) ++bad;
            if (!uammBeaSaveIsVsSpell()) ++bad;
            if (!uammBeaSaversThrownClear()) ++bad;
            if (!uammBeaFailersEncapsulated())
                ++bad;
            if (uammBeaSphereLoRounds() != 3) ++bad;
            if (uammBeaSphereHiRounds() != 12)
                ++bad;
            if (!uammBeaEscapeOnlyAsWallOfForce())
                ++bad;
            if (uammBeaFoundLo() != 5) ++bad;
            if (uammBeaFoundHi() != 8) ++bad;
        // ---- boccob's blessed book ----
            if (uammBocMaxHeightIn() != 12) ++bad;
            if (uammBocWidthIn() != 6) ++bad;
            if (uammBocThickIn() != 1) ++bad;
            if (uammBocSomeMereHeightIn() != 6)
                ++bad;
            if (!uammBocWaterproofBoundLocked())
                ++bad;
            if (uammBocSaveBonus() != 3) ++bad;
            if (uammBocSaveCellGarbles()) ++bad;
            if (uammBocMaxSpellLevels() != 45)
                ++bad;
            if (!uammBocPrizedAsTravellingBook())
                ++bad;
            if (uammBocScribingTailGarbles())
                ++bad;
        // ---- the boots of the north ----
            if (!uammBnSnowNormalNoTracks()) ++bad;
            if (!uammBnIceHalfRateHorizontal())
                ++bad;
            if (uammBnScantClothingMinF() != -50)
                ++bad;
            if (uammBnFullDressMinF() != -100)
                ++bad;
            // full dress doubles the
            // scant-clothing floor
            if (2 * uammBnScantClothingMinF()
                    != uammBnFullDressMinF()) ++bad;
        // ---- the boots of varied tracks ----
            if (!uammBvtCommandAltersTracks())
                ++bad;
            if (!uammBvtSmallAsHalfling()) ++bad;
            if (!uammBvtLargeAsOgre()) ++bad;
            if (!uammBvtBareOrShod()) ++bad;
            if (uammBvtCapabilitiesPerPair() != 4)
                ++bad;
            if (uammBvtTrackTableCount() != 16)
                ++bad;
            if (uammBvtRowOnePrintGarbles()) ++bad;
            // the four capabilities
            // ride the 16-entry table
            if (4 * uammBvtCapabilitiesPerPair()
                    != uammBvtTrackTableCount())
                ++bad;
        // ---- the boots, winged ----
            if (uammBwMaxHoursPerDay() != 2) ++bad;
            if (!uammBwFadeSlowlyPastLimit())
                ++bad;
            if (uammBwRestHoursPerChargeHour()
                    != 12) ++bad;
            if (!uammBwNeverAboveMax()) ++bad;
            static const int kBw[4] = {
                15, 18, 21, 24};
            if (uammBwTypeCount() != 4) ++bad;
            for (int i = 0; i < 4; ++i) {
                if (uammBwSpeedForRoll(i + 1)
                        != kBw[i]) ++bad;
                // the speeds climb by 3
                if (uammBwSpeedForRoll(i + 1)
                        != 15 + 3 * i) ++bad;
            }
            if (uammBwSpeedForRoll(0) != 0) ++bad;
            if (uammBwSpeedForRoll(5) != 0) ++bad;
            if (uammBwMcForRoll(1) != 'A') ++bad;
            if (uammBwMcForRoll(4) != 'D') ++bad;
            if (!uammBwDieCellsMinorOcr()) ++bad;
        // ---- the bracers of archery ----
            if (!uammBaWorksForBowUsers()) ++bad;
            if (!uammBaExcludesCrossbows()) ++bad;
            if (!uammBaGrantsProficiencyIfLacking())
                ++bad;
            if (uammBaProficientHitBonus() != 2)
                ++bad;
            if (uammBaProficientDmgBonus() != 1)
                ++bad;
            if (!uammBaCumulativeExceptSpecialization())
                ++bad;
        // ---- the bracers of brachiation ----
            if (!uammBbNeedsHandholds()) ++bad;
            if (uammBbMoveRatesCount() != 3) ++bad;
            if (uammBbMoveLoIn() != 3) ++bad;
            if (uammBbMoveHiIn() != 9) ++bad;
            if (uammBbClimbRateIn() != 6) ++bad;
            if (!uammBbSwingsAsSimian()) ++bad;
            if (!uammBbJumpsAsStridingSpringing())
                ++bad;
            if (!uammBbJumpMustCulminate()) ++bad;
            // the three movement rates
            // climb by 3
            if (uammBbMoveLoIn() != 3
                    || uammBbMoveHiIn()
                    != 3 * uammBbMoveRatesCount())
                ++bad;
        // ---- the chime of interruption ----
            if (uammChiOpeningGarbles()) ++bad;
            if (uammChiStrikesPerTurn() != 1) ++bad;
            if (uammChiToneRounds() != 3) ++bad;
            if (uammChiVerbalBlockRadiusFt() != 30)
                ++bad;
            if (!uammChiBlockSaveIsVsBreath()) ++bad;
            if (uammChiRestRounds() != 7) ++bad;
            if (!uammChiEarlyStrikeSilent()) ++bad;
            if (uammChiEarlyStrikeWaitTurns() != 1)
                ++bad;
        // ---- the cloak of arachnidia ----
            if (!uammCaStrongAlterationAura())
                ++bad;
            if (!uammCaGrantsSpiderClimb()) ++bad;
            if (!uammCaImmuneToWebs()) ++bad;
            if (uammCaWebMoveBaseIn() != 6) ++bad;
            if (uammCaDoubleWebPerDay() != 1) ++bad;
            if (uammCaDoubleWebSpellLevel() != 2)
                ++bad;
            if (uammCaSaveVsArachnidPoison() != 2)
                ++bad;
        // ---- the cloak of the bat ----
            if (uammCbInvisibilityPct() != 90)
                ++bad;
            if (!uammCbStationaryInShadowOrDark())
                ++bad;
            if (!uammCbHangsUpsideDown()) ++bad;
            if (uammCbFlySpeedIn() != 15) ++bad;
            if (uammCbFlyMcClass() != 'B') ++bad;
            if (!uammCbBatTransformation()) ++bad;
            if (!uammCbFlightDarknessOnly()) ++bad;
            if (uammCbFlightMaxHours() != 1) ++bad;
            if (!uammCbRestEqualsFlight()) ++bad;
            if (uammCbProtectionBonus() != 2) ++bad;
            if (!uammCbProtectionHoldsInBatForm())
                ++bad;
        // ---- the cyclocone ----
            if (!uammCyDimEvocationAura()) ++bad;
            if (!uammCyMuOnly()) ++bad;
            if (uammCyBaseWidthFt() != 5) ++bad;
            if (uammCyTopWidthFt() != 15) ++bad;
            if (uammCyMaxHeightFt() != 45) ++bad;
            if (uammCyFormSegsLo() != 1) ++bad;
            if (uammCyFormSegsHi() != 4) ++bad;
            if (uammCyMoveRateIn() != 18) ++bad;
            if (uammCyDurationRounds() != 1) ++bad;
            if (!uammCySturdyObjectBreaksIt())
                ++bad;
            if (!uammCyBreakerTakesDamage()) ++bad;
            if (!uammCyInstantKillBelowTwoPlusOne())
                ++bad;
            if (uammCyCaughtDmgLo() != 4) ++bad;
            if (uammCyCaughtDmgHi() != 16) ++bad;
            if (uammCyEdgeRangeFt() != 5) ++bad;
            if (uammCyEdgeDmgLo() != 2) ++bad;
            if (uammCyEdgeDmgHi() != 8) ++bad;
            if (!uammCyNotReusable()) ++bad;
            // the top width is the
            // base tripled; the height
            // is the top tripled
            if (3 * uammCyBaseWidthFt()
                    != uammCyTopWidthFt()) ++bad;
            if (3 * uammCyTopWidthFt()
                    != uammCyMaxHeightFt()) ++bad;
            // the edge damage is the
            // caught damage halved
            if (2 * uammCyEdgeDmgLo()
                    != uammCyCaughtDmgLo()
                    || 2 * uammCyEdgeDmgHi()
                    != uammCyCaughtDmgHi()) ++bad;
        // ---- the part ledger ----
            if (uammPartItemTotal() != 13) ++bad;
            if (uammPartCleanCount() != 13) ++bad;
            if (uammPartFlaggedCount() != 0) ++bad;
            if (uammPartGarbledCount() != 0) ++bad;
            if (uammPartCleanCount()
                    + uammPartFlaggedCount()
                    + uammPartGarbledCount()
                    != uammPartItemTotal()) ++bad;
        // ---- the R380 wands seam ----
            if (uawdCleanCount() != 12) ++bad;
            if (uawdFlaggedCount() != 0) ++bad;
            if (uawdGarbledCount() != 0) ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R381 UA misc magic prose part 1 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
