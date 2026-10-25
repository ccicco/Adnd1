    // ---- R799 MM2 letter D part 1 audit ----
    // THE MM2 LETTER D PART 1 - the planar evil families round of the Monster
    // Manual II arc (the user Go call on the landed letters BC). The pin-time
    // walk from the print finds TWENTY-NINE entries on pp. 28-42: nine
    // daemons (the arcanadaemon through the yagnodaemon), three demodands
    // (the farastu through the shator), thirteen demons (the alu-demon
    // through the rutterkin) and four singletons (the dao, the crimson death,
    // the demilich, the derro). TWENTY-NINE defs ride the R791 data_files
    // extension in the MM1 registry schema - no form splits in D part 1. THE
    // GRIDS: the 29-row DpStats stat grid (every armor class, hit-dice, hit,
    // xp and lair cell of the stat blocks) and the 12-row cambion parentage
    // grid (the Major and Baron/Marquis columns of the Male Parentage Class
    // table). THE SETTLED READS: the kelubar 3959 print verbatim over the
    // ladder 3950 and its blank lair cell; the cambion block 4400 vs the
    // parentage 4409 print-internal inconsistency (both pin as they print);
    // the shator weapon strength bonus +9 (the capture +8 is an OCR misread);
    // the graz'zt By weapon type 6 verbatim; the alu-demon range low end 3000
    // + 14/hp; the yagnodaemon size L; the dao size double-primes verbatim;
    // the hydrodaemon treasure I,Y; the demilich bare -6; the derro xp 0
    // sentinel (the Amaimon precedent); the chasme VIII; the nabassu
    // 2-8/2-8/3-12; the babau A,C,E/F,G,H; the arcanadaemon Supra-genius. NO
    // GAP FLIPS (the Letter D box flips only when all D parts land - the R791
    // no-flip precedent). NO XP-AUDIT PATCH (mm2_print rides the
    // allowed-source list since R797). The live def walk (the one file-patch
    // site block, no census marker) cross-checks all 29 defs against the
    // DpStats grid, the dao plane, the xpValue formula, the cambion parentage
    // cells, the derro sentinel and the registry census floor 534 -> 563.
    {
        using namespace rules;
        int bad = 0;
    if (mm2dpRound() != 799
            || mm2dpEntryCount() != 29
            || mm2dpDefCount() != 29
            || mm2dpDaemonEntryCount() != 9
            || mm2dpDemodandEntryCount() != 3
            || mm2dpDemonEntryCount() != 13
            || mm2dpSingletonEntryCount() != 4
            || mm2dpFirstPage() != 28
            || mm2dpLastPage() != 42
            || mm2dpRegistryBefore() != 534
            || mm2dpRegistryAfter() != 563
            || mm2dpDpStatRows() != 29
            || mm2dpCambionParentageRows() != 12
            || mm2dpKelubarXpPrintVerbatim() != 3959
            || mm2dpCambionBaronBlockXp() != 4400
            || mm2dpCambionBaronBlockXpPerHp() != 15
            || mm2dpCambionBaronTableXp() != 4409
            || mm2dpCambionBaronTableXpPerHp() != 15
            || mm2dpCambionMarquisXp() != 6500
            || mm2dpCambionMarquisXpPerHp() != 20
            || mm2dpCambionMinorXp() != 1275
            || mm2dpCambionMinorXpPerHp() != 10
            || mm2dpShatorWeaponStrengthBonus() != 9
            || mm2dpAluXpLowEnd() != 3000
            || mm2dpAluXpHighEnd() != 4050
            || mm2dpAluXpPerHp() != 14
            || mm2dpChasmeXpLevelViii() != 8
            || mm2dpDerroXp() != 0
            || mm2dpDaemonMrDecrementPct() != 5
            || mm2dpDaemonMrBaselineLevel() != 11
            || mm2dpDaemonWordOfRecallPerDay() != 1
            || mm2dpDemodandSummonCapHi() != 12
            || mm2dpDemodandSummonCapLo() != 8
            || mm2dpFarastuSummonCap() != 12
            || mm2dpKelubarSummonCap() != 10
            || mm2dpShatorSummonCap() != 8
            || mm2dpNameSpeakingBasePct() != 5
            || mm2dpAbyssRulerRows() != 15
            || mm2dpAbyssRulerCols() != 3
            || mm2dpAbyssRulerCount() != 45
            || mm2dpAbyssRosterLines() != 28
            || mm2dpArcanadaemonHornDamageHi() != 16
            || mm2dpArcanadaemonBurningHandsDamage() != 13
            || mm2dpArcanadaemonBurningHandsRangeFeet() != 3
            || mm2dpArcanadaemonTelekineseWeight() != 3250
            || mm2dpArcanadaemonMuLevelLo() != 11
            || mm2dpArcanadaemonMuLevelHi() != 18
            || mm2dpArcanadaemonPsionicMasteryLevel() != 10
            || mm2dpArcanadaemonFortLesserLo() != 1
            || mm2dpArcanadaemonFortLesserHi() != 4
            || mm2dpArcanadaemonFortHordlingLo() != 1
            || mm2dpArcanadaemonFortHordlingHi() != 10
            || mm2dpCharonFlatHp() != 140
            || mm2dpCharonSkiffHolds() != 10
            || mm2dpCharonSilkBagPp() != 100
            || mm2dpCharonGemValueGp() != 500
            || mm2dpCharonPoleDamageLo() != 2
            || mm2dpCharonPoleDamageHi() != 8
            || mm2dpCharonParalysisTurnsLo() != 2
            || mm2dpCharonParalysisTurnsHi() != 8
            || mm2dpCharonStyxDice() != 16
            || mm2dpCharonStyxDamageLo() != 5
            || mm2dpCharonStyxDamageHi() != 30
            || mm2dpCharonSummonCharonadaemonLo() != 3
            || mm2dpCharonSummonCharonadaemonHi() != 18
            || mm2dpCharonSummonHydroLo() != 2
            || mm2dpCharonSummonHydroHi() != 12
            || mm2dpCharonAppearRoundsLo() != 1
            || mm2dpCharonAppearRoundsHi() != 3
            || mm2dpCharonForgetCasterLevel() != 15
            || mm2dpCharonadaemonBoatFeePlatinum() != 10
            || mm2dpCharonadaemonGemValueGp() != 50
            || mm2dpCharonadaemonBetrayPct() != 15
            || mm2dpCharonadaemonWrongDestinationPct() != 85
            || mm2dpCharonadaemonAmbushPct() != 15
            || mm2dpCharonadaemonSummonHydroLo() != 1
            || mm2dpCharonadaemonSummonHydroHi() != 6
            || mm2dpDerghoArmCount() != 5
            || mm2dpDerghoLegCount() != 3
            || mm2dpDerghoHeadRotation() != 360
            || mm2dpDerghoClawDamage() != 4
            || mm2dpDerghoStrengthDamageBonus() != 8
            || mm2dpDerghoUnarmedPct() != 60
            || mm2dpDerghoWeaponMagicalPct() != 20
            || mm2dpDerghoParryAc() != -8
            || mm2dpDerghoDarknessRadiusFeet() != 10
            || mm2dpDerghoFearRadiusFeet() != 20
            || mm2dpDerghoSleepPerDay() != 2
            || mm2dpDerghoGizzardGemsLo() != 0
            || mm2dpDerghoGizzardGemsHi() != 3
            || mm2dpDerghoGemBaseValueGp() != 100
            || mm2dpHydroSwimGroupLo() != 10
            || mm2dpHydroSwimGroupHi() != 30
            || mm2dpHydroGlideTurns() != 1
            || mm2dpHydroAirborneAttacks() != 5
            || mm2dpHydroGroundAttacks() != 3
            || mm2dpHydroGateChancePct() != 50
            || mm2dpHydroWaterElementalDice() != 12
            || mm2dpHydroLairNearStyxFloorPct() != 90
            || mm2dpOinoFlatHp() != 233
            || mm2dpOinoDiseaseFatalWeeks() != 1
            || mm2dpOinoGateChancePct() != 85
            || mm2dpOinoGateDaemonsLo() != 1
            || mm2dpOinoGateDaemonsHi() != 3
            || mm2dpOinoSpellLevel() != 25
            || mm2dpOinoPsionicMasteryLevel() != 20
            || mm2dpOinoRivalCount() != 4
            || mm2dpPiscoVenomFatalRounds() != 6
            || mm2dpPiscoSlowedRounds() != 6
            || mm2dpPiscoSeizedHitPenalty() != 1
            || mm2dpPiscoWaterDiePenalty() != 1
            || mm2dpUltroSpellLevel() != 15
            || mm2dpUltroTelekineseWeight() != 6000
            || mm2dpYagnoTolKendarLengthFeet() != 15
            || mm2dpYagnoTipDamageHi() != 10
            || mm2dpYagnoTipPullDamageHi() != 6
            || mm2dpYagnoSideDamageHi() != 8
            || mm2dpYagnoSidePullDamageHi() != 16
            || mm2dpYagnoKoRoundsLo() != 2
            || mm2dpYagnoKoRoundsHi() != 12
            || mm2dpYagnoFeedRounds() != 5
            || mm2dpYagnoDevourPctLo() != 10
            || mm2dpYagnoDevourPctHi() != 100
            || mm2dpYagnoShockingGraspPerDay() != 3
            || mm2dpYagnoShockingGraspBonus() != 13
            || mm2dpDaoSpellLevel() != 18
            || mm2dpDaoCarryGp() != 5000
            || mm2dpDaoRestTurns() != 6
            || mm2dpDaoTurnRockToMudPerDay() != 3
            || mm2dpDaoDigPerDay() != 6
            || mm2dpDaoBurrowInches() != 6
            || mm2dpCrimsonFeedTurns() != 6
            || mm2dpCrimsonSurpriseDie() != 6
            || mm2dpCrimsonSurpriseHitLo() != 1
            || mm2dpCrimsonSurpriseHitHi() != 5
            || mm2dpDemilichSkullHp() != 50
            || mm2dpDemilichSkullAc() != -6
            || mm2dpDemilichGemsLo() != 5
            || mm2dpDemilichGemsHi() != 8
            || mm2dpDemilichHowlRadiusFeet() != 20
            || mm2dpDemilichShatterDamageLo() != 3
            || mm2dpDemilichShatterDamageHi() != 18
            || mm2dpDemilichDispelEvilDamageLo() != 5
            || mm2dpDemilichDispelEvilDamageHi() != 8
            || mm2dpDemilichHolyWordDamageLo() != 5
            || mm2dpDemilichHolyWordDamageHi() != 30
            || mm2dpDemilichPlusFourWeaponDamage() != 1
            || mm2dpDemilichReformDaysLo() != 1
            || mm2dpDemilichReformDaysHi() != 10
            || mm2dpDemilichSoulFreeDistanceFeet() != 10
            || mm2dpFarastuStickChancePct() != 5
            || mm2dpFarastuStickSegmentsLo() != 1
            || mm2dpFarastuStickSegmentsHi() != 6
            || mm2dpFarastuStuckWeaponPullPct() != 25
            || mm2dpFarastuSpellLevel() != 11
            || mm2dpFarastuSummonLo() != 1
            || mm2dpFarastuSummonHi() != 2
            || mm2dpFarastuSummonSuccessPct() != 40
            || mm2dpFarastuStrength() != 19
            || mm2dpFarastuWeightPounds() != 420
            || mm2dpKelubarAcidDamageLo() != 1
            || mm2dpKelubarAcidDamageHi() != 6
            || mm2dpKelubarGrappleDamageLo() != 4
            || mm2dpKelubarGrappleDamageHi() != 24
            || mm2dpKelubarSpellLevel() != 13
            || mm2dpKelubarSummonLo() != 1
            || mm2dpKelubarSummonHi() != 2
            || mm2dpKelubarSummonSuccessPct() != 50
            || mm2dpKelubarStrength() != 20
            || mm2dpKelubarWeightPounds() != 490
            || mm2dpKelubarInfravisionFeet() != 120
            || mm2dpShatorWeaponToHitBonus() != 4
            || mm2dpShatorWeaponStrengthBonusPrint() != 9
            || mm2dpShatorWeaponAttackRate() != 1
            || mm2dpShatorSpellLevel() != 15
            || mm2dpShatorSummonLo() != 1
            || mm2dpShatorSummonHi() != 8
            || mm2dpShatorSummonSuccessPct() != 60
            || mm2dpShatorEdgedWeaponPenalty() != 1
            || mm2dpShatorSurprisePct() != 10
            || mm2dpShatorStrength() != 21
            || mm2dpShatorWeightPounds() != 560
            || mm2dpShatorHeightFeet() != 6
            || mm2dpAluBaseAc() != 5
            || mm2dpAluPlateMailAc() != 2
            || mm2dpAluGeniusPct() != 25
            || mm2dpAluMagicLevelMax() != 12
            || mm2dpAluIntrinsicPerDay() != 3
            || mm2dpAluPowerLevel() != 12
            || mm2dpAluInfravisionFeet() != 240
            || mm2dpAluDrainHpLo() != 1
            || mm2dpAluDrainHpHi() != 8
            || mm2dpAluGainHpHi() != 4
            || mm2dpAluNotDevotedPct() != 20
            || mm2dpBabauStrength() != 19
            || mm2dpBabauColdIronBonus() != 2
            || mm2dpBabauDarknessRadiusFeet() != 5
            || mm2dpBabauThiefLevel() != 9
            || mm2dpBabauGateChancePct() != 25
            || mm2dpBabauGazeRangeFeet() != 20
            || mm2dpBabauLevitateLevel() != 10
            || mm2dpBabauFlyLevel() != 11
            || mm2dpBabauDispelLevel() != 12
            || mm2dpBabauHeatMetalLevel() != 14
            || mm2dpBaphometBardicheDamageLo() != 11
            || mm2dpBaphometBardicheDamageHi() != 20
            || mm2dpBaphometBardicheDiceBonus() != 8
            || mm2dpBaphometRetinuePct() != 75
            || mm2dpBaphometRetinueLo() != 2
            || mm2dpBaphometRetinueHi() != 5
            || mm2dpBaphometSummonLo() != 5
            || mm2dpBaphometSummonHi() != 8
            || mm2dpBaphometBellowRadiusInches() != 30
            || mm2dpBaphometBellowFleeRounds() != 6
            || mm2dpBaphometGateChancePct() != 85
            || mm2dpBaphometTelekineseWeight() != 75000
            || mm2dpBaphometUnholyWaterPerDay() != 6
            || mm2dpBaphometUpperPlaneDamageLo() != 16
            || mm2dpBaphometUpperPlaneDamageHi() != 64
            || mm2dpBarLguraSpringFeet() != 40
            || mm2dpBarLguraDigitCount() != 6
            || mm2dpBarLguraTelekineseWeight() != 2500
            || mm2dpBarLguraCreateWaterLevel() != 6
            || mm2dpBarLguraGateChancePct() != 25
            || mm2dpBarLguraTransformationRounds() != 1
            || mm2dpBarLguraColorHues() != 7
            || mm2dpCambionHdCapLo() != 5
            || mm2dpCambionHdCapHi() != 8
            || mm2dpCambionHdCapBonus() != 4
            || mm2dpCambionMagicLevelMax() != 5
            || mm2dpCambionBaronAbilitiesLo() != 1
            || mm2dpCambionBaronAbilitiesHi() != 4
            || mm2dpCambionFighterLo() != 9
            || mm2dpCambionFighterHi() != 16
            || mm2dpChasmeDroneBasePct() != 100
            || mm2dpChasmeDronePerLevelPct() != 10
            || mm2dpChasmeSleepHoursLo() != 2
            || mm2dpChasmeSleepHoursHi() != 8
            || mm2dpChasmeBloodDrainLo() != 1
            || mm2dpChasmeBloodDrainHi() != 4
            || mm2dpChasmeGateChancePct() != 15
            || mm2dpChasmeTelekineseWeight() != 1500
            || mm2dpDretchGateChancePct() != 5
            || mm2dpDretchDarknessRadiusFeet() != 5
            || mm2dpDretchTelekineseWeight() != 500
            || mm2dpDretchStinkingCloudPerDay() != 1
            || mm2dpDretchTeleportPerDay() != 1
            || mm2dpFrazFlatHp() != 233
            || mm2dpFrazFistDamageLo() != 13
            || mm2dpFrazFistDamageHi() != 18
            || mm2dpFrazBiteDamageHi() != 18
            || mm2dpFrazTailLengthFeet() != 15
            || mm2dpFrazTailDamageHi() != 12
            || mm2dpFrazSpellLevel() != 20
            || mm2dpFrazTelekineseWeight() != 10000
            || mm2dpFrazGateTypeILo() != 1
            || mm2dpFrazGateTypeIHi() != 4
            || mm2dpFrazDeceivePct() != 75
            || mm2dpFrazGateSuccessPct() != 60
            || mm2dpFrazTrickPrincePct() != 75
            || mm2dpFrazFuryPct() != 85
            || mm2dpFrazMagicResistPct() != 70
            || mm2dpFrazSpoilPct() != 90
            || mm2dpGrazztFlatHp() != 186
            || mm2dpGrazztTwoWeaponAc() != -6
            || mm2dpGrazztShieldPlus() != 3
            || mm2dpGrazztAcidDamageLo() != 5
            || mm2dpGrazztAcidDamageHi() != 8
            || mm2dpGrazztMissileCount() != 5
            || mm2dpGrazztFearRangeFeet() != 60
            || mm2dpGrazztTypeVIGatePct() != 60
            || mm2dpGrazztBabauGatePct() != 40
            || mm2dpGrazztIamiasLo() != 1
            || mm2dpGrazztIamiasHi() != 3
            || mm2dpGrazztTelekineseWeight() != 15000
            || mm2dpGrazztSpellLevel() != 20
            || mm2dpGrazztExileYears() != 100
            || mm2dpKostFlatHp() != 96
            || mm2dpKostHammerDamageHi() != 12
            || mm2dpKostLeucrottaGuards() != 2
            || mm2dpKostLeucrottaAc() != 3
            || mm2dpKostLeucrottaHp() != 49
            || mm2dpKostRearKickDamageLo() != 2
            || mm2dpKostRearKickDamageHi() != 7
            || mm2dpKostSpellLevel() != 20
            || mm2dpKostTelekineseWeight() != 5000
            || mm2dpKostBabauGatePct() != 35
            || mm2dpKostBarLguraGatePct() != 65
            || mm2dpKostPoisonPerDay() != 2
            || mm2dpNabassuHumansToMature() != 18
            || mm2dpNabassuDemonlingAc() != 4
            || mm2dpNabassuDemonlingHd() != 5
            || mm2dpNabassuTravelBonusHp() != 2
            || mm2dpNabassuTwoHumansAc() != 3
            || mm2dpNabassuCauseShadowsRadiusFeet() != 20
            || mm2dpNabassuStealRangeInches() != 2
            || mm2dpNabassuBestowRangeInches() != 1
            || mm2dpNabassuMatureGhastSummonLo() != 2
            || mm2dpNabassuMatureGhastSummonHi() != 5
            || mm2dpNabassuRegenPerDay() != 20
            || mm2dpNabassuParalysisRadiusFeet() != 10
            || mm2dpNabassuStrength() != 1800
            || mm2dpPazuzuFlatHp() != 155
            || mm2dpPazuzuNameTimes() != 3
            || mm2dpPazuzuObedienceHdLimit() != 5
            || mm2dpPazuzuBreathPerDay() != 3
            || mm2dpPazuzuBodyguardCount() != 6
            || mm2dpPazuzuHarpySummonLo() != 4
            || mm2dpPazuzuHarpySummonHi() != 16
            || mm2dpPazuzuSummonPct() != 90
            || mm2dpPazuzuSuccubusGateLo() != 1
            || mm2dpPazuzuSuccubusGateHi() != 4
            || mm2dpPazuzuSuccubusGatePct() != 75
            || mm2dpPazuzuRegenPerRound() != 1
            || mm2dpRutterkinSnapTongsDamageHi() != 8
            || mm2dpRutterkinCrescentDamageLo() != 10
            || mm2dpRutterkinCrescentDamageHi() != 12
            || mm2dpRutterkinBladeDamageLo() != 3
            || mm2dpRutterkinBladeRangeInches() != 15
            || mm2dpRutterkinTelekineseWeight() != 1000
            || mm2dpRutterkinGateChasmePct() != 15
            || mm2dpDerroDexLo() != 15
            || mm2dpDerroDexHi() != 18
            || mm2dpDerroCrossbowRangeInches() != 12
            || mm2dpDerroCrossbowShotsPerRound() != 2
            || mm2dpDerroCrossbowCapacity() != 6
            || mm2dpDerroPoisonDamageLo() != 2
            || mm2dpDerroPoisonDamageHi() != 12
            || mm2dpDerroFauchardPullPct() != 25
            || mm2dpDerroEvery3LeaderHd() != 4
            || mm2dpDerroEvery6LeaderHd() != 5
            || mm2dpDerroTenLeaderHd() != 7
            || mm2dpDerroLieutenantHd() != 6
            || mm2dpDerroSavantHdLo() != 5
            || mm2dpDerroSavantHdHi() != 8
            || mm2dpDerroStudentHdLo() != 4
            || mm2dpDerroStudentHdHi() != 7
            || mm2dpDerroSavantSpellsLo() != 6
            || mm2dpDerroSavantSpellsHi() != 9
            || mm2dpDerroStudentSpellsLo() != 1
            || mm2dpDerroStudentSpellsHi() != 3
            || mm2dpDerroSpellLevel() != 12
            || mm2dpDerroStudentItemPct() != 25
            || mm2dpDerroLairNormalLo() != 30
            || mm2dpDerroLairNormalHi() != 42
            || mm2dpDerroLairSavantLo() != 1
            || mm2dpDerroLairSavantHi() != 3
            || mm2dpDerroLairSlaveLo() != 15
            || mm2dpDerroLairSlaveHi() != 40
            || mm2dpDerroSlaveFemalePct() != 80
            || mm2dpDerroInfravisionFeet() != 30
            || !mm2dpDBoxFlipsOnlyWhenAllPartsLand()
            || !mm2dpMultiPartLetterWalk()
            || !mm2dpMm2PrintRidesXpAudit()
            || !mm2dpDefsRideDataFiles()
            || !mm2dpPinHeaderStaysPrintRecord()
            || !mm2dpKelubarLairCellBlank()
            || !mm2dpKelubarXpKeptPrintVerbatim()
            || !mm2dpCambionXpPrintInconsistent()
            || !mm2dpCambionCellsFromParentage()
            || !mm2dpGrazztDamagePrintsVerbatim()
            || !mm2dpYagnodaemonSizeIsL()
            || !mm2dpDaoSizeKeepsDoublePrimes()
            || !mm2dpHydroTreasureIsIY()
            || !mm2dpDemilichAcCarriesBareNegative()
            || !mm2dpArcanadaemonIntSupraGenius()
            || !mm2dpDerroXpZeroSentinel()
            || !mm2dpDemodandLairParensPin()
            || !mm2dpDaemonAcidHalfDamage()
            || !mm2dpDaemonColdHalfDamage()
            || !mm2dpDaemonElectricityFullDamage()
            || !mm2dpDaemonFireHalfDamage()
            || !mm2dpDaemonGasFullDamage()
            || !mm2dpDaemonMagicMissileFullDamage()
            || !mm2dpDaemonIronAndSilverFullDamage()
            || !mm2dpDaemonPoisonParalysisNone()
            || !mm2dpDaemonCharmSuggestionImmune()
            || !mm2dpDaemonCommonSpellLikeList()
            || !mm2dpDaemonInfraAndUltravision()
            || !mm2dpDemodandFeudalSociety()
            || !mm2dpDemodandSingleOnPrime()
            || !mm2dpDemonAcidFullDamage()
            || !mm2dpDemonColdHalfDamage()
            || !mm2dpDemonElectricityHalfDamage()
            || !mm2dpDemonFireHalfDamage()
            || !mm2dpDemonGasHalfDamage()
            || !mm2dpDemonIronFullDamage()
            || !mm2dpDemonMagicMissileFullDamage()
            || !mm2dpDemonPoisonFullDamage()
            || !mm2dpDemonSilverNone()
            || !mm2dpDemonNeverSubdued()
            || !mm2dpDemonTelepathicUnderstanding()
            || !mm2dpDemonCannotEnterPrimeUnaided()
            || !mm2dpArcanadaemonFliesUnlimited()
            || !mm2dpArcanadaemonCastsWithoutMrCheck()
            || !mm2dpArcanadaemonScrollsWandsFree()
            || !mm2dpArcanadaemonDarknessRadiusTwenty()
            || !mm2dpArcanadaemonTeleportOncePerDay()
            || !mm2dpCharonNeverTrulySlain()
            || !mm2dpCharonFormReturnsNextDay()
            || !mm2dpCharonBanksOnly()
            || !mm2dpCharonadaemonTeleportsCraftAway()
            || !mm2dpCharonadaemonGlowingEyesFear()
            || !mm2dpCharonadaemonTelepathicRaceContact()
            || !mm2dpDerghoGrabbedPlusTwo()
            || !mm2dpDerghoStoneGiantStrength()
            || !mm2dpHydroOnlyStyxSwimmers()
            || !mm2dpHydroDrainsOneLevel()
            || !mm2dpHydroHalfWaterDamage()
            || !mm2dpOinoStaffOfTheLowerPlanes()
            || !mm2dpOinoCharmBypassesDaemonMr()
            || !mm2dpOinoLeadToPlatinum()
            || !mm2dpOinoTransfixesOnePerRound()
            || !mm2dpPiscoCannotBeSurprised()
            || !mm2dpPiscoSeizedDrawnToMaw()
            || !mm2dpPiscoResentfulLabor()
            || !mm2dpUltroGazeFascinates()
            || !mm2dpUltroSeersSeeLovedOne()
            || !mm2dpUltroOncePerDayPowers()
            || !mm2dpUltroSummonMastersExist()
            || !mm2dpYagnoStormGiantStrength()
            || !mm2dpYagnoHalfEarthDamage()
            || !mm2dpYagnoOneAttackPerRound()
            || !mm2dpDaoPlaneOfEarth()
            || !mm2dpDaoMovesThroughEarth()
            || !mm2dpDaoEarthSpellsNoHarm()
            || !mm2dpDaoHolyWaterDouble()
            || !mm2dpDaoSixThousandEightTurns()
            || !mm2dpDaoHatesDjinn()
            || !mm2dpCrimsonBogDweller()
            || !mm2dpCrimsonHitOnlyByPlusTwo()
            || !mm2dpCrimsonDrainsBodyFluids()
            || !mm2dpCrimsonDenHoardsLures()
            || !mm2dpDemilichHowlPermanentlySlays()
            || !mm2dpDemilichGemDrainIrresistible()
            || !mm2dpDemilichAmuletPrevails()
            || !mm2dpDemilichPowerWordKillDestroys()
            || !mm2dpDemilichWraithOrGhostManifests()
            || !mm2dpFarastuPlusOneToHit()
            || !mm2dpFarastuAcidPoisonNoEffect()
            || !mm2dpFarastuFearIllusionUseless()
            || !mm2dpFarastuInfraAndUltra()
            || !mm2dpKelubarThreeHitsGrapple()
            || !mm2dpKelubarSaveHalvesAcid()
            || !mm2dpKelubarPlusTwoToHit()
            || !mm2dpShatorPlusThreeToHit()
            || !mm2dpShatorShortSwordsExcluded()
            || !mm2dpShatorAcidPoisonNoEffect()
            || !mm2dpAluAlwaysFemale()
            || !mm2dpAluDoublesWeaponDrain()
            || !mm2dpAluColdIronOrMagic()
            || !mm2dpBabauSlimeHalvesDamage()
            || !mm2dpBabauGazeEnfeebles()
            || !mm2dpBabauLeapsFromAbove()
            || !mm2dpBaphometLordOfMinotaurs()
            || !mm2dpBaphometHearingDouble()
            || !mm2dpBarLguraNormalWeaponsFull()
            || !mm2dpBarLguraTwicePerDayPowers()
            || !mm2dpBarLguraShunsOtherDemons()
            || !mm2dpBarLguraMovesFastClimbing()
            || !mm2dpCambionAlwaysMale()
            || !mm2dpCambionBaseAcSixOrTwo()
            || !mm2dpCambionInfravisionDemonSpeech()
            || !mm2dpCambionIronYesSilverNo()
            || !mm2dpCambionClericIfWisdomNine()
            || !mm2dpCambionOneProfessionAtATime()
            || !mm2dpChasmeWalksWallsCeilings()
            || !mm2dpChasmePoisonImmune()
            || !mm2dpChasmeTouchFearAsWand()
            || !mm2dpChasmeUsesRutterkin()
            || !mm2dpDretchCommonestDemons()
            || !mm2dpDretchBiteAndTwoClaws()
            || !mm2dpFrazDeceptionImmune()
            || !mm2dpFrazPlaneAliveToWishes()
            || !mm2dpFrazSearchingForHisStaff()
            || !mm2dpGrazztLordOfALayer()
            || !mm2dpGrazztDoublesAttacks()
            || !mm2dpGrazztTrapSoulOncePerWeek()
            || !mm2dpGrazztSixFingered()
            || !mm2dpKostHammerStuns()
            || !mm2dpKostDislikedByAll()
            || !mm2dpKostFrostGiantServants()
            || !mm2dpNabassuGhastOrGhoulVictim()
            || !mm2dpNabassuThiefAbilities()
            || !mm2dpNabassuIronOrPlusOne()
            || !mm2dpNabassuProbabilityTravelInborn()
            || !mm2dpPazuzuRulesTheSkies()
            || !mm2dpPazuzuEntersPrimeAtWill()
            || !mm2dpPazuzuTurnsClerics()
            || !mm2dpPazuzuWishOncePerDay()
            || !mm2dpPazuzuFourWings()
            || !mm2dpRutterkinFlatchetPlusOneVsUnarmored()
            || !mm2dpRutterkinHatedAndAbused()
            || !mm2dpRutterkinTeleportOncePerDay()
            || !mm2dpDerroSavantSavantSpellList()
            || !mm2dpDerroSunlightNausea()
            || !mm2dpDerroScaledLeather()
            || !mm2dpDerroAklysHalfFauchard()
        )
            ++bad;
        // the 29 x 9 D-part-1 stat grid - the stat-block cells of the
        // twenty-nine promoted defs in print order (the arcanadaemon through
        // the derro): armor class, hit dice, hit-die bonus, average hit
        // points, attacks, base xp, xp per hit, lair percent and the primary
        // move rate
        int CDpStats[29][9] = {
            {-2,13,39,84,4,6950,18,10,12},
            {-5,0,0,140,1,22200,35,0,18},
            {-1,10,20,55,1,5300,16,100,18},
            {0,11,22,60,5,5800,16,20,12},
            {2,9,36,67,5,3450,14,5,6},
            {-6,0,0,233,2,29555,0,50,18},
            {-1,6,0,21,2,455,6,50,6},
            {-5,14,28,77,2,8100,20,25,15},
            {1,13,13,58,1,7050,18,30,18},
            {3,8,3,31,1,1600,12,0,9},
            {0,13,0,45,1,7050,18,60,12},
            {-6,0,0,50,1,5950,16,100,0},
            {-1,11,0,38,3,2850,16,0,15},
            {-2,13,0,45,3,3959,18,0,12},
            {-3,15,0,52,3,5250,20,0,9},
            {5,6,2,23,1,3000,14,15,12},
            {-3,7,14,38,3,2000,12,20,15},
            {-4,0,0,106,3,45000,0,40,24},
            {-3,6,6,27,3,1725,10,10,9},
            {6,5,0,17,2,1275,10,0,15},
            {-1,7,2,26,3,1275,10,5,6},
            {2,4,0,14,3,175,4,15,9},
            {-2,0,0,233,4,50000,0,20,12},
            {-9,0,0,186,4,60000,0,60,12},
            {-3,0,0,96,1,42500,0,25,6},
            {4,5,2,19,3,1800,12,5,15},
            {-9,0,0,155,1,65000,0,15,12},
            {1,5,1,18,2,425,6,20,12},
            {9,3,0,10,2,0,0,20,9},
            };
        for (int b = 0;
             b < mm2dpDpStatRows();
             ++b) {
            int vals[9];
            vals[0] = mm2dpDpStatAC(b);
            vals[1] = mm2dpDpStatHd(b);
            vals[2] = mm2dpDpStatHdBonus(b);
            vals[3] = mm2dpDpStatAvgHp(b);
            vals[4] = mm2dpDpStatAttacks(b);
            vals[5] = mm2dpDpStatXp(b);
            vals[6] = mm2dpDpStatXpHp(b);
            vals[7] = mm2dpDpStatLairPct(b);
            vals[8] = mm2dpDpStatMove(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CDpStats[b][c])
                    ++bad;
            }
        }
        // the 12-row x 4-column cambion Male Parentage Class grid as printed
        // - the Major and Baron/Marquis columns of armor class, hit dice,
        // strength, intelligence, wisdom, dexterity, constitution, charisma,
        // special defenses (0 Nil, 1 the +1 or better weapon print), magic
        // resistance, psionic ability (0 Nil, 1 As human) and the LEVEL/X.P.
        // VALUE base and per-hp pair (the table 4409 rides the Baron cell -
        // the block pins 4400; both pin as they print)
        int CCambionParentage[12][4] = {
            {6,6,2,2},
            {5,8,9,16},
            {17,18,18,20},
            {9,16,13,18},
            {5,8,3,18},
            {13,18,15,20},
            {13,18,15,18},
            {1,6,2,24},
            {0,0,1,1},
            {5,20,25,40},
            {0,0,1,1},
            {1275,10,4409,15},
            };
        for (int b = 0;
             b < mm2dpCambionParentageRows();
             ++b) {
            int vals[4];
            vals[0] = mm2dpCambionMajorLo(b);
            vals[1] = mm2dpCambionMajorHi(b);
            vals[2] = mm2dpCambionBaronLo(b);
            vals[3] = mm2dpCambionBaronHi(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CCambionParentage[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count (the census walk)
    if (mm2dpRegistryAfter() - mm2dpRegistryBefore() != mm2dpDefCount()
            || mm2dpDefCount() != 29
            || mm2dpDaemonEntryCount() + mm2dpDemodandEntryCount() +
            mm2dpDemonEntryCount() + mm2dpSingletonEntryCount() !=
            mm2dpEntryCount()
        )
            ++bad;
        // the eight flat-hp forms read hit dice 0 and carry the print hit
        // points (the loader flat-hp path)
    if (mm2dpDpStatHd(1) != 0
            || mm2dpDpStatAvgHp(1) != mm2dpCharonFlatHp()
            || mm2dpDpStatHd(5) != 0
            || mm2dpDpStatAvgHp(5) != mm2dpOinoFlatHp()
            || mm2dpDpStatHd(11) != 0
            || mm2dpDpStatAvgHp(11) != mm2dpDemilichSkullHp()
            || mm2dpDpStatHd(17) != 0
            || mm2dpDpStatHd(22) != 0
            || mm2dpDpStatAvgHp(22) != mm2dpFrazFlatHp()
            || mm2dpDpStatHd(23) != 0
            || mm2dpDpStatAvgHp(23) != mm2dpGrazztFlatHp()
            || mm2dpDpStatHd(24) != 0
            || mm2dpDpStatAvgHp(24) != mm2dpKostFlatHp()
            || mm2dpDpStatHd(26) != 0
            || mm2dpDpStatAvgHp(26) != mm2dpPazuzuFlatHp()
        )
            ++bad;
        // the xpValue formula tiles base + average x per-hp on ten grid rows
        // (the loader floors xpValue at the base)
    if (mm2dpDpStatXp(1) + mm2dpDpStatAvgHp(1) * mm2dpDpStatXpHp(1) != 22200 +
        140 * 35
            || mm2dpDpStatXp(5) + mm2dpDpStatAvgHp(5) * mm2dpDpStatXpHp(5) !=
            29555 + 233 * 0
            || mm2dpDpStatXp(7) + mm2dpDpStatAvgHp(7) * mm2dpDpStatXpHp(7) !=
            8100 + 77 * 20
            || mm2dpDpStatXp(13) + mm2dpDpStatAvgHp(13) * mm2dpDpStatXpHp(13)
            != 3959 + 45 * 18
            || mm2dpDpStatXp(11) + mm2dpDpStatAvgHp(11) * mm2dpDpStatXpHp(11)
            != 5950 + 50 * 16
            || mm2dpDpStatXp(15) + mm2dpDpStatAvgHp(15) * mm2dpDpStatXpHp(15)
            != 3000 + 23 * 14
            || mm2dpDpStatXp(19) + mm2dpDpStatAvgHp(19) * mm2dpDpStatXpHp(19)
            != 1275 + 17 * 10
            || mm2dpDpStatXp(20) + mm2dpDpStatAvgHp(20) * mm2dpDpStatXpHp(20)
            != 1275 + 26 * 10
            || mm2dpDpStatXp(25) + mm2dpDpStatAvgHp(25) * mm2dpDpStatXpHp(25)
            != 1800 + 19 * 12
            || mm2dpDpStatXp(28) + mm2dpDpStatAvgHp(28) * mm2dpDpStatXpHp(28)
            != 0 + 10 * 0
        )
            ++bad;
        // the kelubar blank lair cell reads 0 and the xp stays the
        // print-verbatim 3959 + 18/hp
    if (mm2dpDpStatLairPct(13) != 0
            || mm2dpDpStatXp(13) != mm2dpKelubarXpPrintVerbatim()
            || mm2dpDpStatXpHp(13) != 18
        )
            ++bad;
        // the demilich armor class carries the bare -6 and the Special move
        // reads 0
    if (mm2dpDpStatAC(11) != -6
            || mm2dpDpStatAC(11) != mm2dpDemilichSkullAc()
            || mm2dpDpStatMove(11) != 0
        )
            ++bad;
        // the cambion parentage grid ties the xp row and the AC/HD Major
        // cells to the def grid (the block 4400 vs the table 4409
        // inconsistency pins as it prints)
    if (mm2dpCambionMajorLo(11) != mm2dpCambionMinorXp()
            || mm2dpCambionMajorHi(11) != mm2dpCambionMinorXpPerHp()
            || mm2dpCambionBaronLo(11) != mm2dpCambionBaronTableXp()
            || mm2dpCambionBaronHi(11) != mm2dpCambionBaronTableXpPerHp()
            || mm2dpCambionBaronBlockXp() != 4400
            || mm2dpCambionBaronTableXp() != 4409
            || mm2dpDpStatXp(19) != mm2dpCambionMinorXp()
            || mm2dpDpStatAC(19) != mm2dpCambionMajorLo(0)
            || mm2dpDpStatHd(19) != mm2dpCambionMajorLo(1)
        )
            ++bad;
        // the demodand summon caps walk the printed 12, 10, 8 ladder
    if (mm2dpFarastuSummonCap() != 12
            || mm2dpKelubarSummonCap() != 10
            || mm2dpShatorSummonCap() != 8
            || mm2dpDemodandSummonCapLo() != 8
            || mm2dpDemodandSummonCapHi() != 12
            || mm2dpFarastuSummonCap() - mm2dpKelubarSummonCap() != 2
            || mm2dpKelubarSummonCap() - mm2dpShatorSummonCap() != 2
        )
            ++bad;
        // the Abyss ruler enumeration census (15 rows x 3) and the 28-line
        // inhabitants roster
    if (mm2dpAbyssRulerCount() != mm2dpAbyssRulerRows() *
        mm2dpAbyssRulerCols()
            || mm2dpAbyssRulerCount() != 45
            || mm2dpAbyssRosterLines() != 28
        )
            ++bad;
        // the daemon MR decrement rule, the 11th-level baseline, the
        // name-speaking base and the word-of-recall once per day
    if (mm2dpDaemonMrDecrementPct() != 5
            || mm2dpDaemonMrBaselineLevel() != 11
            || mm2dpNameSpeakingBasePct() != 5
            || mm2dpDaemonWordOfRecallPerDay() != 1
        )
            ++bad;
        // the settled reads ride the grid: the shator +9, the alu-demon 3000
        // or 4050 low end, the chasme VIII, the derro 0 sentinel and the
        // demilich Special attacks reading 1
    if (mm2dpShatorWeaponStrengthBonus() != 9
            || mm2dpAluXpLowEnd() != 3000
            || mm2dpAluXpHighEnd() != 4050
            || mm2dpAluXpPerHp() != 14
            || mm2dpChasmeXpLevelViii() != 8
            || mm2dpDerroXp() != 0
            || mm2dpDpStatXp(28) != mm2dpDerroXp()
            || mm2dpDpStatAttacks(11) != 1
        )
            ++bad;
        printf("R799 MM2 letter D part 1 audit: bad %d\n", bad);
        if (bad) return 1;
    }
