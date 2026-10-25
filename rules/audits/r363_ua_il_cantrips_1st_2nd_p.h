    // ---- R363: the UA new illusionist
    // cantrips and 1st/2nd level spells
    // pin audit ----
    // The UA NEW ILLUSIONIST SPELLS
    // (pp. 65-68) - the eight cantrip
    // descriptions (colored lights with
    // the globe ladder, dim, haze, mask,
    // mirage, noise, rainbow, and the
    // two-d-lusion the item list missed);
    // the chromatic orb with the color
    // ladder, phantom armor; read magic,
    // spook, alter self, fascinate, and
    // the ultravision and wind reprints.
    // The R342 IL table seam prints only
    // PHB names in the readable columns;
    // the cantrip column resolves (the
    // R421 PDF read). The item
    // stays open - the 3rd through 7th
    // levels pin in later rounds.
    {
        using namespace rules;
        int bad = 0;
        // ---- U1: colored lights ----
            if (strcmp(uailcLightsName(),
                "Colored Lights (Alteration)") != 0) ++bad;
            if (!uailcLightsAoeSpecial()) ++bad;
            if (uailcLightsSingleGlobeFeet() != 1) ++bad;
            if (uailcLightsPairGlobesInches() != 6) ++bad;
            if (uailcLightsThreeGlobesInches() != 4) ++bad;
            if (uailcLightsFourGlobesInches() != 3) ++bad;
            if (!uailcLightsAnyPastelColor()) ++bad;
            if (!uailcLightsCfBluelight()) ++bad;
            if (uailcLightsRadiusInDiameters() != 5) ++bad;
            if (uailcLightsFootGlobeRadiusFeet() != 5) ++bad;
            if (uailcLightsThreeInchGlobeRadiusInches() != 15) ++bad;
            if (!uailcLightsConcentrationMaintained()) ++bad;
            if (uailcLightsRangeInches() != 1) ++bad;
            if (!uailcLightsMovedAsDesired()) ++bad;
            if (uailcLightsReflectionBeyondInches()
                != 1
                || uailcLightsDetectedBeyondInches()
                != 3) ++bad;
            if (!uailcLightsPaleBluePinkSparesVision()) ++bad;
            if (!uailcLightsSpeakColorAndNumber()) ++bad;
            if (!uailcLightsMagicWord()) ++bad;
            if (!uailcLightsDirectsWithFingers()) ++bad;
            if (uailcCastTimeDen(0) != 2) ++bad;
            if (strcmp(uailcDimName(), "Dim (Alteration)") != 0) ++bad;
            if (!uailcDimAoeSpecial()) ++bad;
            if (!uailcDimWeakensLightOrAir()) ++bad;
            if (uailcDimTorches() != 6) ++bad;
            if (uailcDimCandles() != 72) ++bad;
            if (!uailcDimAffectsLightSpells()) ++bad;
            if (!uailcDimHalfRadiance()) ++bad;
            if (uailcDimDurationRounds() != 1) ++bad;
            if (!uailcDimTorchAsCandle()) ++bad;
            if (!uailcDimFireBecomesTorchlike()) ++bad;
            if (!uailcDimLightSpellsDimToHalf()) ++bad;
            if (uailcDimRangeInches() != 1) ++bad;
            if (!uailcDimPhraseAndDownwardMotion()) ++bad;
            if (uailcCastTimeDen(1) != 2) ++bad;
            if (strcmp(uailcHazeName(), "Haze (Alteration)") != 0) ++bad;
            if (uailcHazeAoeCubeInches() != 1) ++bad;
            // (the PDF read confirms the 1-inch
            // cube - the decode flag amends
            // away, R421)
            if (!uailcHazeSmokeOrDust()) ++bad;
            if (uailcHazeHarderToHitPct() != 5) ++bad;
            if (uailcHazeMissileToHitAdj() != -1) ++bad;
            if (uailcHazeSaveBonus() != 1) ++bad;
            if (uailcHazeSaveWhenOtherwiseNonePct() != 5) ++bad;
            if (uailcHazeHideInShadowsBonusPct() != 5) ++bad;
            if (uailcHazeDurationRounds() != 1) ++bad;
            if (uailcHazeRangeInches() != 1) ++bad;
            if (!uailcHazeWeatherDestroys()) ++bad;
            if (!uailcHazeGustOfWindDisperses()) ++bad;
            if (!uailcHazeHumAndHandPasses()) ++bad;
            if (uailcCastTimeDen(2) != 2) ++bad;
            if (strcmp(uailcMaskName(), "Mask (Illusion)") != 0) ++bad;
            if (!uailcMaskAoeOnePerson()) ++bad;
            if (!uailcMaskAlterOwnOrSubjectVisage()) ++bad;
            if (!uailcMaskSubjectHumanDemiHumanHumanoid()) ++bad;
            if (!uailcMaskFeaturesAffected()) ++bad;
            if (!uailcMaskDetectedOnlyCloseUp()) ++bad;
            if (uailcMaskDurationRoundsMin() != 3) ++bad;
            if (uailcMaskDurationRoundsMax() != 6) ++bad;
            if (!uailcMaskTouchThinkSpeak()) ++bad;
            if (uailcCastTimeDen(3) != 8) ++bad;
            if (strcmp(uailcMirageName(), "Mirage") != 0) ++bad;
            if (!uailcMirageSchoolIsIllusion()) ++bad;
            if (uailcMirageAoeSquareInches() != 2) ++bad;
            if (!uailcMirageAreaAppearsOther()) ++bad;
            if (!uailcMirageFlatFeatureless()) ++bad;
            if (!uailcMirageActualBeheldPlace()) ++bad;
            if (!uailcMirageSaveApplicable()) ++bad;
            if (!uailcMirageConcentrationMaintained()) ++bad;
            if (uailcMirageWaverCumulativePct() != 5) ++bad;
            if (!uailcMirageTouchDispel()) ++bad;
            if (!uailcMirageDispelIllusionOrMagic()) ++bad;
            if (!uailcMirageWordOrTwoThenSinglePass())
                ++bad;
            if (!uailcMirageKeptByConcentrationAlone())
                ++bad;
            if (uailcCastTimeDen(4) != 2) ++bad;
            if (strcmp(uailcNoiseName(), "Noise (Illusion)") != 0) ++bad;
            if (uailcNoiseRadiusInches() != 1) ++bad;
            if (!uailcNoiseIndistinctConfusing()) ++bad;
            if (!uailcNoiseMurmurRushShuffleExamples()) ++bad;
            if (!uailcNoiseEachCreatureSaves()) ++bad;
            if (!uailcNoiseSaveNegatesPerIndividual()) ++bad;
            if (uailcNoiseRangeInches() != 1) ++bad;
            if (!uailcNoisePointAndImitate()) ++bad;
            if (uailcCastTimeDen(5) != 8) ++bad;
            if (strcmp(uailcRainbowName(),
                "Rainbow (Alteration)") != 0) ++bad;
            if (!uailcRainbowAoeSpecial()) ++bad;
            if (uailcRainbowLengthFeet() != 30) ++bad;
            if (uailcRainbowWidthFeet() != 1) ++bad;
            if (uailcRainbowEndWithinInches() != 1) ++bad;
            if (!uailcRainbowGlowsInDarkness()) ++bad;
            if (!uailcRainbowNoMotionMayLeave()) ++bad;
            if (uailcRainbowMotionStayWithinInches() != 1) ++bad;
            if (uailcRainbowDurationRounds() != 1) ++bad;
            if (uailcRainbowGazeSegmentsMin() != 1) ++bad;
            if (uailcRainbowGazeSegmentsMax() != 4) ++bad;
            if (uailcRainbowGazeMovingMin() != 2) ++bad;
            if (uailcRainbowGazeMovingMax() != 5) ++bad;
            if (!uailcRainbowNameOfPowerPyramid()) ++bad;
            if (uailcCastTimeDen(6) != 3) ++bad;
            if (strcmp(uailcTwodName(), "Two-D'lusion") != 0) ++bad;
            if (!uailcTwodSchoolIsIllusion()) ++bad;
            if (uailcTwodAoeSquareInches() != 4) ++bad;
            if (!uailcTwodSameAsPhantasmalForce()) ++bad;
            if (uailcTwodTellAngleDegrees() != 45) ++bad;
            if (!uailcTwodDispelByTouchOrMagic()) ++bad;
            if (!uailcTwodInvisibleFromSideOrRear()) ++bad;
            if (!uailcTwodConcentrationMaintained()) ++bad;
            if (!uailcTwodPhraseAndCircularMotion()) ++bad;
            if (uailcCastTimeDen(7) != 8) ++bad;
        // ---- U2: the chromatic orb ----
            if (strcmp(uail1OrbName(), "Chromatic Orb") != 0) ++bad;
            if (!uail1OrbNameHeaderGarbled()) ++bad;
            if (!uail1OrbSchoolTailLost()) ++bad;
            if (uail1OrbLevel() != 1) ++bad;
            if (!uail1OrbRangeZero()) ++bad;
            if (!uail1OrbDurationSpecial()) ++bad;
            if (!uail1OrbAoeOneCreature()) ++bad;
            if (!uail1OrbComponentsVSM()) ++bad;
            if (uail1OrbCastingTimeSegments() != 1) ++bad;
            if (!uail1OrbCastingGarbleDecoded()) ++bad;
            if (!uail1OrbSaveSpecial()) ++bad;
            if (uail1OrbMaxHurlInches() != 3) ++bad;
            if (!uail1OrbNoBarriers()) ++bad;
            if (!uail1OrbMagicalVsHighPlus()) ++bad;
            if (!uail1OrbMagicResistanceWithstands()) ++bad;
            if (uail1OrbHitAdjAtOneInch() != 3) ++bad;
            if (uail1OrbHitAdjAtTwoInches() != 2) ++bad;
            if (uail1OrbHitAdjAtMaxRange() != 1) ++bad;
            if (!uail1OrbToHitSentenceInterleaved()) ++bad;
            if (!uail1OrbColorDeterminesEffect()) ++bad;
            if (!uail1OrbColorRestrictedByLevel()) ++bad;
            if (!uail1OrbLowerHuesAlwaysAvailable()) ++bad;
            if (uail1OrbRowCount() != 9) ++bad;
            if (uail1OrbPearlyLightRoundsPerLevel() != 1) ++bad;
            if (!uail1OrbPearlyBlindsOnFailedSave()) ++bad;
            if (uail1OrbRubyMeltsIceCuYd() != 1) ++bad;
            if (uail1OrbRubyStatLossPerStat() != 1) ++bad;
            if (uail1OrbRubyStatLossRounds() != 1) ++bad;
            if (uail1OrbFlameCombustiblesRadiusInches() != 1) ++bad;
            if (uail1OrbFlameExtraDamage() != 2) ++bad;
            if (uail1OrbAmberBlindRoundsMin() != 5) ++bad;
            if (uail1OrbAmberBlindRoundsMax() != 8) ++bad;
            if (uail1OrbEmeraldCloudRadiusFeet() != 5) ++bad;
            if (uail1OrbTurquoiseMagnetizeRoundsMin() != 3) ++bad;
            if (uail1OrbTurquoiseMagnetizeRoundsMax() != 12) ++bad;
            if (uail1OrbSapphireParalysisRoundsMin() != 5) ++bad;
            if (uail1OrbSapphireParalysisRoundsMax() != 20) ++bad;
            if (!uail1OrbAmethystStoneOnFailedSave()) ++bad;
            if (uail1OrbAmethystSlowRoundsMin() != 2) ++bad;
            if (uail1OrbAmethystSlowRoundsMax() != 8) ++bad;
            if (!uail1OrbAshenDeathOnFailedSave()) ++bad;
            if (uail1OrbAshenParalysisRoundsMin() != 2) ++bad;
            if (uail1OrbAshenParalysisRoundsMax() != 5) ++bad;
            if (uail1OrbGemGpMin() != 50) ++bad;
            if (!uail1OrbClearCrystalSubstitute()) ++bad;
            if (strcmp(uail1PhantomName(),
                "Phantom Armor (Alteration/Illusion)") != 0) ++bad;
            if (!uail1PhantomComponentsVSM()) ++bad;
            if (uail1PhantomLevel() != 1) ++bad;
            if (!uail1PhantomLevelDivergenceFlagged()) ++bad;
            if (uail1PhantomCastingTimeRounds() != 1) ++bad;
            if (!uail1PhantomCastingGarbleDecoded()) ++bad;
            if (!uail1PhantomRangeTouch()) ++bad;
            if (!uail1PhantomDurationSpecial()) ++bad;
            if (!uail1PhantomSaveNone()) ++bad;
            if (!uail1PhantomAoeOnePerson()) ++bad;
            if (!uail1PhantomQuasiRealPlateMail()) ++bad;
            if (uail1PhantomAc() != 3) ++bad;
            if (uail1PhantomArmorType() != 3) ++bad;
            if (uail1PhantomAbsorbPerLevel() != 1) ++bad;
            if (!uail1PhantomVanishesAtLevelsAbsorbed()) ++bad;
            if (!uail1PhantomRemainderAccrues()) ++bad;
            if (!uail1PhantomDisbeliefBreaks()) ++bad;
            if (!uail1PhantomDispelBreaks()) ++bad;
            if (!uail1PhantomWandOfNegationBreaks()) ++bad;
            if (!uail1PhantomSaveBonusCellLost()) ++bad;
            if (!uail1PhantomNoMovementOrCastingHindrance()) ++bad;
            if (!uail1PhantomRustMonsterImmune()) ++bad;
            if (!uail1PhantomNoOtherProtection()) ++bad;
            if (uail1PhantomMithralGp() != 10) ++bad;
            if (!uail1PhantomDisappearsOnCast()) ++bad;
        // ---- U3: read magic ----
            if (strcmp(uail2ReadName(),
                "Read Magic (Divination)") != 0) ++bad;
            if (!uail2ReadReversible()) ++bad;
            if (!uail2ReadStatBlockScrambled()) ++bad;
            if (!uail2ReadComponentsVM()) ++bad;
            if (!uail2ReadLevelCellLost()) ++bad;
            if (uail2ReadLevel() != 2) ++bad;
            if (!uail2ReadLevelFromSectionHeader()) ++bad;
            if (uail2ReadCastingTimeSegments() != 1) ++bad;
            if (!uail2ReadCastingGarbleDecoded()) ++bad;
            if (uail2ReadDurationRoundsPerLevel() != 2) ++bad;
            if (!uail2ReadSaveNone()) ++bad;
            if (!uail2ReadAoeSpecial()) ++bad;
            if (!uail2ReadSameAsMuFirstLevelReadMagic()) ++bad;
            if (!uail2ReadIllusionistScriptOnly()) ++bad;
            if (strcmp(uail2SpookName(),
                "Spook (Illusion/Phantasm)") != 0) ++bad;
            if (uail2SpookLevel() != 2) ++bad;
            if (!uail2SpookLevelGarbleDecoded()) ++bad;
            if (!uail2SpookRangeCellLost()) ++bad;
            if (uail2SpookCastingTimeSegments() != 1) ++bad;
            if (!uail2SpookCastingGarbleDecoded()) ++bad;
            if (!uail2SpookDurationSpecial()) ++bad;
            if (!uail2SpookSaveNegates()) ++bad;
            if (uail2SpookAoeOneCreatureWithinInches() != 1) ++bad;
            if (!uail2SpookPlaysOnNaturalFears()) ++bad;
            if (!uail2SpookSubjectPerceivesCasterInimical()) ++bad;
            if (!uail2SpookAdvancesThreateningly()) ++bad;
            if (!uail2SpookFleesRapidlyOnFailedSave()) ++bad;
            if (!uail2SpookEffectsAsWandOfFear()) ++bad;
            if (!uail2SpookItemsNotDropped()) ++bad;
            if (!uail2SpookPhantasmPursues()) ++bad;
            if (uail2SpookCumulativeSaveBonusPerRound() != 1) ++bad;
            if (uail2SpookMinIntelligence() != 1) ++bad;
            if (strcmp(uail2AlterName(),
                "Alter Self (Alteration/Illusion)") != 0) ++bad;
            if (uail2AlterLevel() != 2) ++bad;
            if (!uail2AlterComponentsVS()) ++bad;
            if (!uail2AlterComponentsCellGarbled()) ++bad;
            if (!uail2AlterRangeZero()) ++bad;
            if (uail2AlterCastingTimeSegments() != 2) ++bad;
            if (uail2AlterDurationRoundsMin() != 3) ++bad;
            if (uail2AlterDurationRoundsMax() != 12) ++bad;
            if (uail2AlterDurationRoundsPerLevel() != 2) ++bad;
            if (!uail2AlterSaveNone()) ++bad;
            if (!uail2AlterAoeTheIllusionist()) ++bad;
            if (!uail2AlterSimilarToChangeSelf()) ++bad;
            if (!uail2AlterQuasiRealChange()) ++bad;
            if (uail2AlterSizeChangePct() != 50) ++bad;
            if (!uail2AlterFlyQuarterSpeed()) ++bad;
            if (uail2AlterManeuverClassLoss() != 2) ++bad;
            if (!uail2AlterMinManeuverClassHole()) ++bad;
            if (!uail2AlterGillsBreatheWater()) ++bad;
            if (!uail2AlterLargerFormNoExtraAttacks()) ++bad;
            if (!uail2AlterUnlessAccustomed()) ++bad;
            if (strcmp(uail2FascName(),
                "Fascinate (Illusion/Phantasm)") != 0) ++bad;
            if (!uail2FascLevelCellLost()) ++bad;
            if (uail2FascLevel() != 2) ++bad;
            if (!uail2FascLevelFromSectionHeader()) ++bad;
            if (!uail2FascComponentsVS()) ++bad;
            if (!uail2FascComponentsCellGarbled()) ++bad;
            if (uail2FascCastingTimeSegments() != 2) ++bad;
            if (!uail2FascStatBlockInterleaved()) ++bad;
            if (!uail2FascDurationSpecial()) ++bad;
            if (!uail2FascSaveNegates()) ++bad;
            if (!uail2FascAoeOneCreature()) ++bad;
            if (!uail2FascCaptivatesAttentionAndLove()) ++bad;
            if (!uail2FascTrustedDesiredCompanion()) ++bad;
            if (!uail2FascFollowsWithoutUndueRisk()) ++bad;
            if (uail2FascRequestDiceCount() != 3) ++bad;
            if (uail2FascRequestDiceSides() != 6) ++bad;
            if (!uail2FascRequestRollVsComeliness()) ++bad;
            if (uail2FascDangerousRequestBonusMin() != 2) ++bad;
            if (uail2FascDangerousRequestBonusMax() != 6) ++bad;
            if (!uail2FascRequestSentenceGarbled()) ++bad;
            if (!uail2FascRageAndHate()) ++bad;
            if (uail2FascAnimalIntDaysMin() != 1) ++bad;
            if (uail2FascAnimalIntDaysMax() != 4) ++bad;
            if (uail2FascBefriendPctPerComelinessPoint() != 2) ++bad;
            if (!uail2FascAttackOrLeaveWhenWorn()) ++bad;
            if (!uail2FascNonIntelligentImmune()) ++bad;
            if (!uail2FascTailFragmentsHole()) ++bad;
            if (strcmp(uail2UltraName(),
                "Ultravision (Alteration)") != 0) ++bad;
            if (uail2UltraLevel() != 2) ++bad;
            if (!uail2UltraRangeTouch()) ++bad;
            if (uail2UltraDurationTurnsBase() != 6) ++bad;
            if (uail2UltraDurationTurnsPerLevel() != 1) ++bad;
            if (!uail2UltraAoeCreatureTouched()) ++bad;
            if (!uail2UltraComponentsVSM()) ++bad;
            if (!uail2UltraComponentsCellGarbled()) ++bad;
            if (uail2UltraCastingTimeSegments() != 2) ++bad;
            if (!uail2UltraSaveNone()) ++bad;
            if (!uail2UltraSameAsMuFourthLevel()) ++bad;
            if (!uail2UltraHighIntDetectsInvisible()) ++bad;
            if (!uail2UltraNoteSentenceGarbled()) ++bad;
            if (!uail2UltraMaterialPowderedCarrots()) ++bad;
            if (strcmp(uail2WindName(), "Wind (Phantasm)") != 0) ++bad;
            if (!uail2WindNameHeaderGarbled()) ++bad;
            if (!uail2WindWhisperingWindProse()) ++bad;
            if (uail2WindLevel() != 2) ++bad;
            if (!uail2WindComponentsVS()) ++bad;
            if (uail2WindCastingTimeSegments() != 2) ++bad;
            if (!uail2WindRangeSpecial()) ++bad;
            if (!uail2WindSaveNone()) ++bad;
            if (!uail2WindDurationSpecial()) ++bad;
            if (uail2WindAoeRadiusFeet() != 2) ++bad;
            if (!uail2WindTensFeetPerLevelUnderground()) ++bad;
            if (!uail2WindMilesPerLevelAboveGround()) ++bad;
            if (uail2WindDeliverySegments() != 2) ++bad;
            if (uail2WindFadesAfterHours() != 2) ++bad;
            if (uail2WindMessageWords() != 12) ++bad;
            if (uail2WindSoundSeconds() != 12) ++bad;
            if (uail2WindSpeedMinInchesPerRound() != 1) ++bad;
            if (uail2WindSpeedMaxInchesPerRound() != 20) ++bad;
            if (!uail2WindNoSpellsThrough()) ++bad;
        // the orb row ladder (9 rows)
            if (uail1OrbRowCount() != 9) ++bad;
            if (uail1OrbRowLevel(0) != 1)
                ++bad;
            if (strcmp(uail1OrbRowName(0),
                "Pearly") != 0) ++bad;
            if (uail1OrbRowDamageMin(0) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(0) != 4)
                ++bad;
            if (uail1OrbRowDamageCellLost(0) != false)
                ++bad;
            if (uail1OrbRowLevel(1) != 2)
                ++bad;
            if (strcmp(uail1OrbRowName(1),
                "Ruby") != 0) ++bad;
            if (uail1OrbRowDamageMin(1) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(1) != 6)
                ++bad;
            if (uail1OrbRowDamageCellLost(1) != false)
                ++bad;
            if (uail1OrbRowLevel(2) != 3)
                ++bad;
            if (strcmp(uail1OrbRowName(2),
                "Flame") != 0) ++bad;
            if (uail1OrbRowDamageMin(2) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(2) != 8)
                ++bad;
            if (uail1OrbRowDamageCellLost(2) != false)
                ++bad;
            if (uail1OrbRowLevel(3) != 4)
                ++bad;
            if (strcmp(uail1OrbRowName(3),
                "Amber") != 0) ++bad;
            if (uail1OrbRowDamageMin(3) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(3) != 10)
                ++bad;
            if (uail1OrbRowDamageCellLost(3) != false)
                ++bad;
            if (uail1OrbRowLevel(4) != 5)
                ++bad;
            if (strcmp(uail1OrbRowName(4),
                "Emerald") != 0) ++bad;
            if (uail1OrbRowDamageMin(4) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(4) != 12)
                ++bad;
            if (uail1OrbRowDamageCellLost(4) != false)
                ++bad;
            if (uail1OrbRowLevel(5) != 6)
                ++bad;
            if (strcmp(uail1OrbRowName(5),
                "Turquoise") != 0) ++bad;
            if (uail1OrbRowDamageMin(5) != 2)
                ++bad;
            if (uail1OrbRowDamageMax(5) != 16)
                ++bad;
            if (uail1OrbRowDamageCellLost(5) != false)
                ++bad;
            if (uail1OrbRowLevel(6) != 7)
                ++bad;
            if (strcmp(uail1OrbRowName(6),
                "Sapphire") != 0) ++bad;
            if (uail1OrbRowDamageMin(6) != 2)
                ++bad;
            if (uail1OrbRowDamageMax(6) != 8)
                ++bad;
            if (uail1OrbRowDamageCellLost(6) != false)
                ++bad;
            if (uail1OrbRowLevel(7) != 10)
                ++bad;
            if (strcmp(uail1OrbRowName(7),
                "Amethyst") != 0) ++bad;
            if (uail1OrbRowDamageMin(7) != 0)
                ++bad;
            if (uail1OrbRowDamageMax(7) != 0)
                ++bad;
            if (uail1OrbRowDamageCellLost(7) != true)
                ++bad;
            if (uail1OrbRowLevel(8) != 12)
                ++bad;
            if (strcmp(uail1OrbRowName(8),
                "Ashen") != 0) ++bad;
            if (uail1OrbRowDamageMin(8) != 0)
                ++bad;
            if (uail1OrbRowDamageMax(8) != 0)
                ++bad;
            if (uail1OrbRowDamageCellLost(8) != true)
                ++bad;
        // the R342 IL table seam: the readable
        // 1st and 2nd columns print only PHB
        // names; the cantrip column resolves
        // (the R421 PDF read)
            if (uas2Il1stCount() != 5) ++bad;
            if (uas2Il2ndCount() != 4) ++bad;
            if (strcmp(uas2Il1stName(4),
                        "Phantasmal Force") != 0) ++bad;
            if (strcmp(uas2Il2ndName(0),
                        "Dispel Illusion") != 0) ++bad;
            if (strcmp(uas2Il7thName(0),
                        "Shadow Walk") != 0) ++bad;
            if (uas2IlCantripCount() != 8) ++bad;
        // none of the new illusionist names
        // seam-checks in the readable columns
            static const char* const nn[6] = {
                "Chromatic Orb", "Phantom Armor",
                "Read Magic", "Spook",
                "Alter Self", "Fascinate",
            };
            for (int n = 0; n < 6; ++n) {
                for (int i = 0; i < 5; ++i) {
                    if (strcmp(uas2Il1stName(i),
                        nn[n]) == 0) ++bad;
                }
                for (int i = 0; i < 4; ++i) {
                    if (strcmp(uas2Il2ndName(i),
                        nn[n]) == 0) ++bad;
                }
            }
        printf("R363 UA IL cantrips/1st/2nd pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
