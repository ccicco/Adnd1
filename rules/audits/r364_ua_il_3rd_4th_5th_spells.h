    // ---- R364: the UA new illusionist
    // 3rd/4th/5th level spells pin
    // audit ----
    // The UA NEW ILLUSIONIST SPELLS
    // (pp. 68-71) - the 3rd-level four
    // (delude with the aura exchange,
    // the phantom steed with the
    // level-power ladder, the phantom
    // wind and wraithform with the
    // casting-time decode); the 4th-
    // level four (dispel magic with the
    // two-levels-below read, rainbow
    // pattern with the follower cap,
    // solid fog, vacancy); the 5th-
    // level four (the advanced illusion
    // named from the item list, dream
    // with the once-per-week aging tail,
    // the magic mirror reprint, tempus
    // fugit reversible). The R342 IL
    // table 3rd-6th columns are wholly
    // lost - none of the new names
    // seam-checks. The item stays open -
    // the 6th and 7th levels pin in the
    // next round.
    {
        using namespace rules;
        int bad = 0;
        // ---- delude ----
        // ---- phantom steed ----
        // ---- phantom wind ----
        // ---- wraithform ----
            if (strcmp(uail3DeludeName(),
                "Delude (Alteration)") != 0) ++bad;
            if (!uail3DeludeVerbalComponent()) ++bad;
            if (!uail3DeludeComponentsTailLost()) ++bad;
            if (uail3DeludeLevel() != 3) ++bad;
            if (uail3DeludeRangeInches() != 0) ++bad;
            if (uail3DeludeCastingTimeSegments() != 3) ++bad;
            if (!uail3DeludeSaveNegates()) ++bad;
            if (uail3DeludeDurationTurnsPerLevel() != 1) ++bad;
            if (!uail3DeludeAoeTheIllusionist()) ++bad;
            if (uail3DeludeAuraRadiusInches() != 3) ++bad;
            if (!uail3DeludeTargetMustExceedAnimalInt()) ++bad;
            if (!uail3DeludeTargetRetainsAlignment()) ++bad;
            if (!uail3DeludeKnowAlignmentSeesAuraOnly()) ++bad;
            if (!uail3DeludeDetectSeesSubstitutedAura()) ++bad;
            if (!uail3DeludeCopiedCreatureRadiatesMagic()) ++bad;
            if (!uail3DeludeCasterRadiatesToSourceOnly()) ++bad;
            if (!uail3DeludeWithChangeOrAlterSelfHides()) ++bad;
            if (!uail3DeludeSaveOnlyOnAuraTransfer()) ++bad;
            if (strcmp(uail3SteedName(),
                "Phantom Steed (Conjuration/Phantasm)") != 0) ++bad;
            if (uail3SteedLevel() != 3) ++bad;
            if (!uail3SteedComponentsVerbalSomatic()) ++bad;
            if (!uail3SteedComponentsTailLost()) ++bad;
            if (!uail3SteedRangeTouch()) ++bad;
            if (!uail3SteedCastingTimeCellGarbled()) ++bad;
            if (uail3SteedDurationTurnsPerLevel() != 6) ++bad;
            if (!uail3SteedSaveCellEmpty()) ++bad;
            if (!uail3SteedAoeSpecial()) ++bad;
            if (!uail3SteedQuasiRealHorseLike()) ++bad;
            if (!uail3SteedRiddenOnlyByCasterOrNamed()) ++bad;
            if (!uail3SteedBlackHeadsAndBodies()) ++bad;
            if (!uail3SteedGrayManesAndTails()) ++bad;
            if (!uail3SteedSmokeColoredHooves()) ++bad;
            if (!uail3SteedHoovesMakeNoSound()) ++bad;
            if (!uail3SteedMilkyEyes()) ++bad;
            if (!uail3SteedDoesNotFight()) ++bad;
            if (!uail3SteedNormalAnimalsShun()) ++bad;
            if (!uail3SteedOnlyMonstrousAnimalsAttack()) ++bad;
            if (uail3SteedDamageToDispel() != 12) ++bad;
            if (uail3SteedMaxRateInchesPerLevel() != 4) ++bad;
            if (!uail3SteedSeemingSaddleAndBridle()) ++bad;
            if (!uail3SteedCannotCarrySaddlebags()) ++bad;
            if (!uail3SteedPower8thSoftGround()) ++bad;
            if (!uail3SteedPower10thOverWater()) ++bad;
            if (!uail3SteedPower12thAirTravel()) ++bad;
            if (!uail3SteedPower12thNoCasualFlight()) ++bad;
            if (!uail3SteedPower14thAsPegasus()) ++bad;
            if (strcmp(uail3PwindName(),
                "Phantom Wind (Alteration/Phantasm)") != 0) ++bad;
            if (uail3PwindLevel() != 3) ++bad;
            if (!uail3PwindComponentsVerbalSomatic()) ++bad;
            if (uail3PwindCastingTimeSegments() != 3) ++bad;
            if (!uail3PwindRangeCellEmpty()) ++bad;
            if (!uail3PwindSaveNone()) ++bad;
            if (!uail3PwindDurationCellSuspectGarble()) ++bad;
            if (uail3PwindAoeInchesBroadPath() != 1) ++bad;
            if (!uail3PwindCannotBeSeenOrFelt()) ++bad;
            if (!uail3PwindBlowsLightObjects()) ++bad;
            if (!uail3PwindFluttersCurtainsAndDrapes()) ++bad;
            if (!uail3PwindFlapsLooseClothing()) ++bad;
            if (!uail3PwindFansFires()) ++bad;
            if (!uail3PwindMovesGaseousClouds()) ++bad;
            if (!uail3PwindMovesInPointedDirection()) ++bad;
            if (uail3PwindPathGrowsInchesPerRound() != 1) ++bad;
            if (!uail3PwindEffectsLastWholePath()) ++bad;
            if (!uail3PwindVesselSentenceGarbled()) ++bad;
            if (strcmp(uail3WraithName(),
                "Wraithform (Alteration/Illusion)") != 0) ++bad;
            if (uail3WraithLevel() != 3) ++bad;
            if (uail3WraithRangeInches() != 0) ++bad;
            if (uail3WraithDurationRoundsPerLevel() != 2) ++bad;
            if (!uail3WraithAoeTheIllusionist()) ++bad;
            if (!uail3WraithComponentsSomaticMaterial()) ++bad;
            if (uail3WraithCastingTimeSegments() != 1) ++bad;
            if (!uail3WraithSaveNone()) ++bad;
            if (!uail3WraithInsubstantialWithGear()) ++bad;
            if (!uail3WraithHitOnlyByPlusOneOrBetter()) ++bad;
            if (!uail3WraithEtherealAbleCreaturesHit()) ++bad;
            if (!uail3WraithMostUndeadIgnore()) ++bad;
            if (!uail3WraithAppearsAsWraithOrSpectre()) ++bad;
            if (!uail3WraithLichMayRecognize()) ++bad;
            if (uail3WraithLichRecognizeSaveMod() != -4) ++bad;
            if (!uail3WraithPassesThroughCracksWithGear()) ++bad;
            if (!uail3WraithNoAttacksExceptVsEthereal()) ++bad;
            if (!uail3WraithEtherealCombatNormalBothWays()) ++bad;
            if (!uail3WraithDispelForcesNormalForm()) ++bad;
            if (!uail3WraithReturnAtWillEndsSpell()) ++bad;
            if (!uail3WraithComponentsGauzeAndSmoke()) ++bad;
        // ---- dispel magic ----
        // ---- rainbow pattern ----
        // ---- solid fog ----
        // ---- vacancy ----
            if (strcmp(uail4DispelName(),
                "Dispel Magic (Abjuration)") != 0) ++bad;
            if (uail4DispelLevel() != 4) ++bad;
            if (uail4DispelRangeInches() != 9) ++bad;
            if (!uail4DispelDurationPermanent()) ++bad;
            if (uail4DispelAoeInchesCube() != 3) ++bad;
            if (!uail4DispelAoeCellInterleaved()) ++bad;
            if (!uail4DispelComponentsVerbalSomatic()) ++bad;
            if (uail4DispelCastingTimeSegments() != 4) ++bad;
            if (!uail4DispelSaveNone()) ++bad;
            if (!uail4DispelSameAsClericalThirdLevel()) ++bad;
            if (!uail4DispelCastsTwoLevelsBelow()) ++bad;
            if (!uail4DispelExampleNinthCastsAsSeventh()) ++bad;
            if (strcmp(uail4RainbowName(),
                "Rainbow Pattern (Alteration/Phantasm)") != 0) ++bad;
            if (uail4RainbowLevel() != 4) ++bad;
            if (!uail4RainbowComponentsSomaticMaterial()) ++bad;
            if (!uail4RainbowCastingTimeCellLost()) ++bad;
            if (uail4RainbowRangeInches() != 1) ++bad;
            if (!uail4RainbowSaveNegates()) ++bad;
            if (!uail4RainbowDurationSpecial()) ++bad;
            if (uail4RainbowAoeInchesSquare() != 3) ++bad;
            if (!uail4RainbowPastelGlowingBand()) ++bad;
            if (!uail4RainbowSameEffectAsHypnoticPattern()) ++bad;
            if (!uail4RainbowMovesInGesturedDirection()) ++bad;
            if (uail4RainbowSpeedInchesPerRound() != 3) ++bad;
            if (uail4RainbowPersistsRoundsMin() != 1) ++bad;
            if (uail4RainbowPersistsRoundsMax() != 3) ++bad;
            if (uail4RainbowFollowerLevelsOrHdCap() != 24) ++bad;
            if (!uail4RainbowDangerAllowsSecondSave()) ++bad;
            if (!uail4RainbowBlockedViewNegates()) ++bad;
            if (!uail4RainbowObscurementExample()) ++bad;
            if (!uail4RainbowComponentsPrismPhosphor()) ++bad;
            if (strcmp(uail4FogName(),
                "Solid Fog (Alteration)") != 0) ++bad;
            if (uail4FogLevel() != 4) ++bad;
            if (!uail4FogLevelCellLost()) ++bad;
            if (uail4FogDurationRoundsBaseMin() != 2) ++bad;
            if (uail4FogDurationRoundsBaseMax() != 8) ++bad;
            if (uail4FogDurationPlusPerLevel() != 1) ++bad;
            if (uail4FogAoeCubicPerLevel() != 2) ++bad;
            if (!uail4FogAoeUnitCellLost()) ++bad;
            if (!uail4FogComponentsVSM()) ++bad;
            if (uail4FogCastingTimeSegments() != 4) ++bad;
            if (!uail4FogSaveNone()) ++bad;
            if (!uail4FogRollingBillowingWallOfFog()) ++bad;
            if (!uail4FogOnlyVeryStrongWindMoves()) ++bad;
            if (!uail4FogGustOfWindCannotAffect()) ++bad;
            if (uail4FogMoveInchesPerRound() != 1) ++bad;
            if (!uail4FogFireballBurnsAwayOneRound()) ++bad;
            if (!uail4FogFlameStrikeBurnsAway()) ++bad;
            if (!uail4FogWallOfFireBurnsAway()) ++bad;
            if (!uail4FogComponentCellGarbled()) ++bad;
            if (strcmp(uail4VacancyName(),
                "Vacancy (Alteration/Phantasm)") != 0) ++bad;
            if (uail4VacancyLevel() != 4) ++bad;
            if (!uail4VacancyComponentsVSM()) ++bad;
            if (uail4VacancyCastingTimeSegments() != 4) ++bad;
            if (uail4VacancyRangeInchesPerLevel() != 1) ++bad;
            if (!uail4VacancySaveNone()) ++bad;
            if (!uail4VacancyDurationCellSuspectGarble()) ++bad;
            if (uail4VacancyAoeRadiusInchesPerLevel() != 1) ++bad;
            if (!uail4VacancyAreaSeemsVacantNeglected()) ++bad;
            if (!uail4VacancyDustCobwebsDirtTypical()) ++bad;
            if (!uail4VacancyPassageSeemsToLeaveTracks()) ++bad;
            if (!uail4VacancyPassageTearsCobwebs()) ++bad;
            if (!uail4VacancyOnlyForcefulContactDisturbs()) ++bad;
            if (!uail4VacancyCloaksOnlyNonLivingThings()) ++bad;
            if (!uail4VacancyLivingThingsNotInvisible()) ++bad;
            if (!uail4VacancyForcefulContactGrantsSaves()) ++bad;
            if (!uail4VacancyFailedSaveBelievesInvisible()) ++bad;
            if (!uail4VacancyDispelRemovesDweomer()) ++bad;
            if (!uail4VacancyTrueSeeingPenetrates()) ++bad;
            if (!uail4VacancyGemOfSeeingPenetrates()) ++bad;
            if (!uail4VacancyDetectInvisibilityCannot()) ++bad;
            if (uail4VacancySilkMinGpValue() != 100) ++bad;
        // ---- advanced illusion ----
        // ---- dream ----
        // ---- magic mirror ----
        // ---- tempus fugit ----
            if (strcmp(uail5AdvilName(),
                "Advanced Illusion (Illusion/Phantasm)") != 0) ++bad;
            if (!uail5AdvilNameHeaderGarbled()) ++bad;
            if (uail5AdvilLevel() != 5) ++bad;
            if (!uail5AdvilComponentsVSM()) ++bad;
            if (uail5AdvilCastingTimeSegments() != 5) ++bad;
            if (uail5AdvilRangeInches() != 6) ++bad;
            if (uail5AdvilRangeInchesPerLevel() != 1) ++bad;
            if (!uail5AdvilSaveSpecial()) ++bad;
            if (!uail5AdvilDurationCellSuspectGarble()) ++bad;
            if (uail5AdvilAoeSquares() != 4) ++bad;
            if (uail5AdvilAoeSquaresPerLevel() != 1) ++bad;
            if (!uail5AdvilAoeCellInterleaved()) ++bad;
            if (!uail5AdvilProgramSpell()) ++bad;
            if (!uail5AdvilCrossRefCellGarbled()) ++bad;
            if (uail5AdvilConcentrationSegments() != 5) ++bad;
            if (!uail5AdvilProgramRunsAlone()) ++bad;
            if (!uail5AdvilVisualComponent()) ++bad;
            if (!uail5AdvilFullAudialComponent()) ++bad;
            if (!uail5AdvilOlfactoryComponent()) ++bad;
            if (!uail5AdvilThermalComponent()) ++bad;
            if (!uail5AdvilActiveDisbelieveGrantsSave()) ++bad;
            if (uail5AdvilCommunicatedDisbeliefBonus() != 4) ++bad;
            if (!uail5AdvilComponentsFleeceAndSand()) ++bad;
            if (strcmp(uail5DreamName(),
                "Dream (Alteration - Illusion/Phantasm)") != 0) ++bad;
            if (uail5DreamLevel() != 5) ++bad;
            if (!uail5DreamRangeSpecial()) ++bad;
            if (!uail5DreamDurationSpecial()) ++bad;
            if (!uail5DreamAoeSpecial()) ++bad;
            if (!uail5DreamComponentsSpecial()) ++bad;
            if (!uail5DreamCastingTimeCellSuspectGarble()) ++bad;
            if (!uail5DreamSaveNegates()) ++bad;
            if (!uail5DreamLimitedWishForm()) ++bad;
            if (!uail5DreamMoreLimitedScope()) ++bad;
            if (!uail5DreamMustLieProneAndSleep()) ++bad;
            if (uail5DreamUndisturbedSleepHours() != 8) ++bad;
            if (uail5DreamEffectuatedHoursMin() != 1) ++bad;
            if (uail5DreamEffectuatedHoursMax() != 12) ++bad;
            if (!uail5DreamResultRecoverLostHp()) ++bad;
            if (!uail5DreamResultRestoreBodyMember()) ++bad;
            if (!uail5DreamResultLocateUnguardedObject()) ++bad;
            if (!uail5DreamResultDiscoverIngressEgress()) ++bad;
            if (!uail5DreamResultSafeWildernessPath()) ++bad;
            if (!uail5DreamResultImproveTreasureChances()) ++bad;
            if (uail5DreamScriedSaveHdThreshold() != 7) ++bad;
            if (!uail5DreamScriedSaveHidesFromDream()) ++bad;
            if (!uail5DreamScriedMaySenseCaster()) ++bad;
            if (!uail5DreamResultsStrictlyLimited()) ++bad;
            if (!uail5DreamNeverExceedsOnPermanentBasis()) ++bad;
            if (uail5DreamCompanionTurnsPerLevel() != 1) ++bad;
            if (!uail5DreamUnaffectedByExtensionOrPermanency()) ++bad;
            if (!uail5DreamOncePerWeek()) ++bad;
            if (!uail5DreamSecondCastInWeekFails()) ++bad;
            if (uail5DreamSecondCastAgesYearsMin() != 1) ++bad;
            if (uail5DreamSecondCastAgesYearsMax() != 10) ++bad;
            if (strcmp(uail5MirrorName(),
                "Magic Mirror (Enchantment - Divination)") != 0) ++bad;
            if (uail5MirrorLevel() != 5) ++bad;
            if (!uail5MirrorComponentsVSM()) ++bad;
            if (uail5MirrorCastingTimeHours() != 1) ++bad;
            if (!uail5MirrorRangeTouch()) ++bad;
            if (!uail5MirrorSaveNone()) ++bad;
            if (!uail5MirrorDurationCellSuspectGarble()) ++bad;
            if (!uail5MirrorAoeSpecial()) ++bad;
            if (!uail5MirrorSameAsFourthLevelMuSpell()) ++bad;
            if (!uail5MirrorSameMaterialComponents()) ++bad;
            if (!uail5MirrorVisionSpellReplacesComponents()) ++bad;
            if (!uail5MirrorStillScrysWithVision()) ++bad;
            if (!uail5MirrorVisionDoesNotFunctionNormally()) ++bad;
            if (strcmp(uail5TempusName(),
                "Tempus Fugit (Illusion/Phantasm)") != 0) ++bad;
            if (!uail5TempusReversible()) ++bad;
            if (uail5TempusLevel() != 5) ++bad;
            if (!uail5TempusComponentsVerbalSomatic()) ++bad;
            if (uail5TempusCastingTimeSegments() != 5) ++bad;
            if (uail5TempusRangeInches() != 0) ++bad;
            if (!uail5TempusSaveNone()) ++bad;
            if (uail5TempusDurationTurnsPerLevel() != 5) ++bad;
            if (uail5TempusAoeRadiusInches() != 7) ++bad;
            if (!uail5TempusAffectsMindsAndBodies()) ++bad;
            if (!uail5TempusLatecomersAlsoAffected()) ++bad;
            if (!uail5TempusTurnSeemsLikeAnHour()) ++bad;
            if (!uail5TempusFunctionsSpedUp()) ++bad;
            if (!uail5TempusOtherSpellDurationsSped()) ++bad;
            if (!uail5TempusOneHourIsAsSix()) ++bad;
            if (!uail5TempusFourHoursAFullDay()) ++bad;
            if (!uail5TempusAllowsRestRenewalRecovery()) ++bad;
            if (!uail5TempusReversalSlowsTime()) ++bad;
            if (!uail5TempusReverseHourSeemsATurn()) ++bad;
            if (!uail5TempusReverseDayMereFourHours()) ++bad;
            if (!uail5TempusReversalNeedsNoPreparation()) ++bad;
            if (!uail5TempusCasterAlsoAffected()) ++bad;
            if (uail5TempusReverseLingersTurnsMin() != 1) ++bad;
            if (!uail5TempusReverseLingersBySlowReactions()) ++bad;
        // the R342 IL table seam: the 3rd
        // through 6th columns are wholly
        // lost; the readable columns still
        // print only PHB names, and the
        // lost-column Phantom Wind fragment
        // corroborates the wind pin
            if (uas2Il1stCount() != 5) ++bad;
            if (uas2Il2ndCount() != 4) ++bad;
            if (uas2Il7thCount() != 1) ++bad;
            if (strcmp(uas2Il7thName(0),
                        "Shadow Walk") != 0) ++bad;
            if (uas2IlCantripCount() != 8) ++bad;
        // none of the new illusionist names
        // seam-checks in the readable
        // columns
            static const char* const nn[12] = {
                "Delude", "Phantom Steed",
                "Phantom Wind", "Wraithform",
                "Dispel Magic", "Rainbow Pattern",
                "Solid Fog", "Vacancy",
                "Advanced Illusion", "Dream",
                "Magic Mirror", "Tempus Fugit",
            };
            for (int n = 0; n < 12; ++n) {
                for (int i = 0; i < 5; ++i) {
                    if (strcmp(uas2Il1stName(i),
                        nn[n]) == 0) ++bad;
                }
                for (int i = 0; i < 4; ++i) {
                    if (strcmp(uas2Il2ndName(i),
                        nn[n]) == 0) ++bad;
                }
                if (strcmp(uas2Il7thName(0),
                    nn[n]) == 0) ++bad;
            }
        printf("R364 UA IL 3rd/4th/5th spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
