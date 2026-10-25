    // ---- R798 MM2 letters BC audit ----
    // THE MM2 LETTERS B AND C - the first multi-letter round of the Monster
    // Manual II arc (the user call after the R797 shakedown). The pin-time
    // walk from the print finds THIRTY-SEVEN entries on pp. 12-27: twenty-two
    // B (the baku through the buckawn) and fifteen C (the cats through the
    // cyclopskin). FORTY-THREE defs ride the R791 data_files extension in the
    // MM1 registry schema: the thirty-seven stat blocks plus the ordinary
    // bat, the soldier and bumblebee bees, the slicer beetle, the wild cat
    // and the megalo-centipede form splits. THE GRIDS: the 26-row B and
    // 17-row C stat grids (every armor class, hit-dice, hit, xp and lair cell
    // of the stat blocks), the barghest growth brackets (hit dice 6+6 through
    // 12+12, the armor class falling one place per die and the magic
    // resistance rising 5% per die), the barkburr hit-dice ladder, the
    // bloodthorn attack-data bands, and the cat lord feline and human-form
    // summon bands. THE SETTLED READS: the behemoth LEVEL/X.P. prints
    // VII/1800 + 15/hp (the capture primary); the cloaker xp/hp settles at 6
    // (the flat-6-HD boggart and slicer beetle both print 6/hp); the
    // bumblebee queen prints 8+6 hit dice; the cave moray LEVEL/X.P. carries
    // the roman II; the domestic cat MOVE prints 5 inches; the cyclopskin
    // alignment prints verbatim. NO XP-AUDIT PATCH: mm2_print already rides
    // the allowed-source list (the R797 patch). The live def walk (the one
    // file-patch site block, no census marker) cross-checks all 43 defs
    // against the two stat grids, the planes, the xpValue formula and the
    // registry census 491 -> 534.
    {
        using namespace rules;
        int bad = 0;
    if (mm2bcRound() != 798
            || mm2bcBEntryCount() != 22
            || mm2bcCEntryCount() != 15
            || mm2bcEntryCount() != 37
            || mm2bcExtraFormDefs() != 6
            || mm2bcDefCount() != 43
            || mm2bcBDefCount() != 26
            || mm2bcCDefCount() != 17
            || mm2bcBFirstPage() != 12
            || mm2bcBLastPage() != 21
            || mm2bcCFirstPage() != 22
            || mm2bcCLastPage() != 27
            || mm2bcRegistryBefore() != 491
            || mm2bcRegistryAfter() != 534
            || mm2bcBStatRows() != 26
            || mm2bcCStatRows() != 17
            || mm2bcBarghestBracketRows() != 7
            || mm2bcBarkburrLadderRows() != 6
            || mm2bcBloodthornRows() != 3
            || mm2bcFelineSummonRows() != 9
            || mm2bcHumanSummonRows() != 4
            || mm2bcBakuGroupMin() != 2
            || mm2bcBakuGroupMax() != 5
            || mm2bcBakuTrunkFt() != 4
            || mm2bcBakuRoarDmgMin() != 1
            || mm2bcBakuRoarDmgMax() != 8
            || mm2bcBakuRoarRadiusIn() != 4
            || mm2bcBakuRoarCooldown() != 4
            || mm2bcBakuFearLevel() != 12
            || mm2bcBakuPsionicScore() != 180
            || mm2bcBanderlogNoGearPct() != 95
            || mm2bcBanderlogMissileDmgMin() != 2
            || mm2bcBanderlogMissileDmgMax() != 5
            || mm2bcBanderlogMissileRangeFt() != 30
            || mm2bcBanderlogBiteDmgMin() != 2
            || mm2bcBanderlogBiteDmgMax() != 5
            || mm2bcBanderlogLeaderHpPerDieMin() != 6
            || mm2bcBanderlogLeaderHpPerDieMax() != 8
            || mm2bcBarghestLitterSize() != 6
            || mm2bcBarghestHpPerLevel() != 1
            || mm2bcBarghestLevelsPerHitDie() != 8
            || mm2bcBarghestStrLo() != 18
            || mm2bcBarghestStrHi() != 24
            || mm2bcBarghestCanineMoveMax() != 30
            || mm2bcBarghestUnnoticedPct() != 75
            || mm2bcBarghestCanineSurprisePct() != 50
            || mm2bcBarghestDogTellFailPct() != 95
            || mm2bcBarkburrCarapaceAC() != 0
            || mm2bcBarkburrUndersideAC() != 8
            || mm2bcBarkburrSenseRadiusMiles() != 1
            || mm2bcBarkburrLeapRangeFt() != 20
            || mm2bcBarkburrIdBasePct() != 4
            || mm2bcBarkburrTubeDmg() != 1
            || mm2bcBarkburrTreatedAsHd() != 6
            || mm2bcBarkburrInjectBaseRounds() != 2
            || mm2bcBarkburrLignifyTurns() != 1
            || mm2bcBarkburrAbsorbHoursMin() != 2
            || mm2bcBarkburrAbsorbHoursMax() != 7
            || mm2bcBarkburrFireDislodgePct() != 15
            || mm2bcBarkburrSidewaysDmgMin() != 1
            || mm2bcBarkburrSidewaysDmgMax() != 10
            || mm2bcBarkburrRemovalHelpers() != 3
            || mm2bcBarkburrNeutralizeBasePct() != 30
            || mm2bcBarkburrTreantFormHd() != 7
            || mm2bcBarkburrFormTreeMaxPct() != 50
            || mm2bcBarkburrFormBadgerLo() != 51
            || mm2bcBarkburrFormBadgerHi() != 70
            || mm2bcBarkburrFormWeaselLo() != 71
            || mm2bcBarkburrFormWeaselHi() != 80
            || mm2bcBarkburrFormTreantLo() != 81
            || mm2bcBarkburrFormTreantHi() != 90
            || mm2bcBarkburrFormDruidMin() != 91
            || mm2bcBarkburrNeutralComponentAdjust() != 10
            || mm2bcBarkburrTrueNeutralAdjust() != 20
            || mm2bcBarkburrTreeGrowMonths() != 3
            || mm2bcBarkburrOffspringChancePct() != 50
            || mm2bcBarkburrOffspringHd() != 2
            || mm2bcBasidirondSporeDmgMin() != 2
            || mm2bcBasidirondSporeDmgMax() != 8
            || mm2bcBasidirondSmotherRoundsMin() != 2
            || mm2bcBasidirondSmotherRoundsMax() != 5
            || mm2bcBasidirondCloudRadiusMinIn() != 20
            || mm2bcBasidirondCloudRadiusMaxIn() != 35
            || mm2bcBasidirondHallucinateRoundsMin() != 1
            || mm2bcBasidirondHallucinateRoundsMax() != 4
            || mm2bcBasidirondHallucinationD8() != 8
            || mm2bcBasiliskGreaterGazeRangeFt() != 50
            || mm2bcBasiliskGreaterNearsightFt() != 10
            || mm2bcBasiliskGreaterReflectPct() != 10
            || mm2bcBasiliskGreaterClawSaveBonus() != 4
            || mm2bcBasiliskGreaterBreathRangeFt() != 5
            || mm2bcBasiliskGreaterBreathSaveBonus() != 2
            || mm2bcMobatWingspreadMinFt() != 12
            || mm2bcMobatWingspreadMaxFt() != 16
            || mm2bcMobatSurprisePct() != 50
            || mm2bcMobatScreechRadiusFt() != 20
            || mm2bcMobatFlyingAC() != 2
            || mm2bcMobatCrowdedAC() != 7
            || mm2bcMobatGroundAC() != 10
            || mm2bcBatFineFlightAC() != 4
            || mm2bcBatGroundAC() != 8
            || mm2bcBatCavernMax() != 1000
            || mm2bcFireBatBodyFt() != 2
            || mm2bcFireBatWingspanFt() != 4
            || mm2bcFireBatFeedRounds() != 3
            || mm2bcFireBatWetDmgMin() != 1
            || mm2bcFireBatWetDmgMax() != 4
            || mm2bcFireBatDouseGallons() != 10
            || mm2bcFireBatDryRounds() != 10
            || mm2bcFireBatWithdrawPct() != 25
            || mm2bcFireBatColonyMin() != 12
            || mm2bcFireBatColonyMax() != 24
            || mm2bcBearNorthernHugRoll() != 18
            || mm2bcBearNorthernHugDmgMin() != 3
            || mm2bcBearNorthernHugDmgMax() != 18
            || mm2bcBearNorthernFightRoundsMin() != 2
            || mm2bcBearNorthernFightRoundsMax() != 5
            || mm2bcBearNorthernFightToNegative() != 12
            || mm2bcBeeHiveWorkerMultiple() != 20
            || mm2bcBeeHiveSoldiersMin() != 3
            || mm2bcBeeHiveSoldiersMax() != 12
            || mm2bcBeeNestBumblebeesMin() != 7
            || mm2bcBeeNestBumblebeesMax() != 12
            || mm2bcBeeHiveDronesMin() != 2
            || mm2bcBeeHiveDronesMax() != 5
            || mm2bcBeeQueenHdNum() != 8
            || mm2bcBeeQueenHdBonus() != 6
            || mm2bcBeeQueenStingDmgMin() != 1
            || mm2bcBeeQueenStingDmgMax() != 8
            || mm2bcBeeSoldierSavePenalty() != 1
            || mm2bcBeeQueenSavePenalty() != 2
            || mm2bcBeeSaveDmgMin() != 2
            || mm2bcBeeSaveDmgMax() != 8
            || mm2bcBeeFailDmgMin() != 5
            || mm2bcBeeFailDmgMax() != 20
            || mm2bcBeeRoyalJellyPct() != 20
            || mm2bcBeeRoyalJellyMin() != 2
            || mm2bcBeeRoyalJellyMax() != 5
            || mm2bcBeeUnguentJarsMin() != 2
            || mm2bcBeeUnguentJarsMax() != 5
            || mm2bcBeeUnguentYouthMonths() != 12
            || mm2bcBeeUnguentPriceMinGp() != 3000
            || mm2bcBeeUnguentPriceMaxGp() != 8000
            || mm2bcDeathWatchVibrationRadiusFt() != 30
            || mm2bcDeathWatchSaveDmgMin() != 5
            || mm2bcDeathWatchSaveDmgMax() != 20
            || mm2bcDeathWatchClickCooldownMinH() != 2
            || mm2bcDeathWatchClickCooldownMaxH() != 5
            || mm2bcDeathWatchLocateFailPct() != 90
            || mm2bcDeathWatchStayPct() != 10
            || mm2bcSlicerSeverRollMin() != 19
            || mm2bcSlicerMagicWeaponPct() != 25
            || mm2bcSlicerMagicBootsPct() != 10
            || mm2bcSlicerMatchedPairPct() != 5
            || mm2bcBehemothBullDmgMin() != 6
            || mm2bcBehemothBullDmgMax() != 24
            || mm2bcBehemothCowDmgMin() != 4
            || mm2bcBehemothCowDmgMax() != 16
            || mm2bcBehemothCowsMin() != 1
            || mm2bcBehemothCowsMax() != 3
            || mm2bcBehemothCalfChancePct() != 25
            || mm2bcBehemothOverturnPct() != 50
            || mm2bcBehemothSubmergeMin() != 30
            || mm2bcBehirLegs() != 12
            || mm2bcBehirLightningLengthFt() != 20
            || mm2bcBehirLightningCooldown() != 10
            || mm2bcBehirLightningDamage() != 24
            || mm2bcBehirTalonAttacks() != 6
            || mm2bcBehirSwallowRoll() != 20
            || mm2bcBehirGemsPct() != 10
            || mm2bcBehirJewelryPct() != 30
            || mm2bcBehirMagicItemPct() != 10
            || mm2bcBloodthornTendrilsMin() != 5
            || mm2bcBloodthornTendrilsMax() != 12
            || mm2bcBloodthornTendrilLenMinFt() != 7
            || mm2bcBloodthornTendrilLenMaxFt() != 12
            || mm2bcBloodthornTendrilReachMinFt() != 5
            || mm2bcBloodthornTendrilReachMaxFt() != 7
            || mm2bcBloodthornDrainPct() != 25
            || mm2bcBloodthornSeverMin() != 5
            || mm2bcBloodthornSeverMax() != 10
            || mm2bcBloodthornTendrilAC() != 4
            || mm2bcBloodthornTrunkAC() != 3
            || mm2bcBloodthornHornwoodPct() != 90
            || mm2bcBoaliskGazeAtOpponentPct() != 75
            || mm2bcBoaliskSurpriseMin() != 1
            || mm2bcBoaliskSurpriseMax() != 2
            || mm2bcBoaliskAvoidAcPenalty() != 4
            || mm2bcBoaliskWithConstrictorPct() != 25
            || mm2bcBodakGazeRangeFt() != 30
            || mm2bcBodakWeaponChancePct() != 90
            || mm2bcBodakControlFactorMax() != 20
            || mm2bcBodakSunlightDmgPerRound() != 1
            || mm2bcBoggartFormHoldRoundsMin() != 10
            || mm2bcBoggartFormHoldRoundsMax() != 12
            || mm2bcBoggartBoltRangeFt() != 10
            || mm2bcBoggartBoltHalfDmgMin() != 1
            || mm2bcBoggartBoltHalfDmgMax() != 6
            || mm2bcBoggartConfusionRadiusFt() != 30
            || mm2bcBoggartConfusionRoundsMin() != 7
            || mm2bcBoggartConfusionRoundsMax() != 12
            || mm2bcBoggartInvisibleRoundsMax() != 12
            || mm2bcBoggartFleeAtHp() != 5
            || mm2bcBoggartWallThicknessFt() != 2
            || mm2bcBoggleHeightFt() != 3
            || mm2bcBoggleStealAC() != 5
            || mm2bcBoggleDropClawBonus() != 2
            || mm2bcBoggleDoorRangeIn() != 3
            || mm2bcBoggleStretchFactor() != 2
            || mm2bcBoggleDamageCutPerDie() != 1
            || mm2bcBoobrieSurpriseIn6() != 2
            || mm2bcBoobrieAdultHpPerDie() != 5
            || mm2bcBoobrieYoungHpPerDie() != 4
            || mm2bcBookwormLengthIn() != 1
            || mm2bcBookwormSmellRangeFt() != 60
            || mm2bcBookwormMotionlessAC() != 9
            || mm2bcBookwormSurprisePct() != 95
            || mm2bcBookwormSurpriseVsSeersPct() != 50
            || mm2bcBookwormOnVictimPct() != 25
            || mm2bcBookwormMunchHearPct() != 50
            || mm2bcBookwormJumpFt() != 10
            || mm2bcBookwormBurrowInPerRound() != 3
            || mm2bcBookwormSpellLevelsPerRound() != 1
            || mm2bcBookwormPaperPct() != 30
            || mm2bcBookwormMapPct() != 20
            || mm2bcBookwormScrollPct() != 30
            || mm2bcBookwormArcanePct() != 20
            || mm2bcBookwormSpellbookPct() != 10
            || mm2bcBowlerAccelInPerRound() != 1
            || mm2bcBowlerMaxMoveIn() != 15
            || mm2bcBowlerLbsPerHp() != 28
            || mm2bcBowlerCoreGp() != 10
            || mm2bcBowlerNoticePct() != 50
            || mm2bcBowlerNoticeRangeFt() != 40
            || mm2bcBuckawnSpellLevel() != 6
            || mm2bcBuckawnHidePct() != 80
            || mm2bcBuckawnSilentReductionPct() != 50
            || mm2bcCatDomesticRakeMin() != 1
            || mm2bcCatDomesticRakeMax() != 2
            || mm2bcCatWildRakePerPaw() != 2
            || mm2bcCatSurpriseIn6() != 3
            || mm2bcCatSurprisedIn6() != 1
            || mm2bcCatTreeMoveDivisor() != 2
            || mm2bcCatLordStr() != 20
            || mm2bcCatLordInt() != 19
            || mm2bcCatLordWis() != 17
            || mm2bcCatLordDex() != 23
            || mm2bcCatLordCon() != 16
            || mm2bcCatLordChaFelines() != 25
            || mm2bcCatLordChaWereFelines() != 22
            || mm2bcCatLordChaPartial() != 18
            || mm2bcCatLordChaIndifferent() != 13
            || mm2bcCatLordChaAilurophobe() != 7
            || mm2bcCatLordThiefLevel() != 19
            || mm2bcCatLordMonkLevel() != 13
            || mm2bcCatLordSpringFt() != 30
            || mm2bcCatLordYowlRadiusFt() != 19
            || mm2bcCatLordYowlStunMin() != 1
            || mm2bcCatLordYowlStunMax() != 4
            || mm2bcCatLordLicksPerDay() != 9
            || mm2bcCatLordLickHealMin() != 2
            || mm2bcCatLordLickHealMax() != 64
            || mm2bcCatLordHearingMultiple() != 5
            || mm2bcCatLordInfravisionFt() != 300
            || mm2bcCatLordSilencePct() != 99
            || mm2bcCatLordSpitLevel() != 19
            || mm2bcCatLordAstralPerDay() != 1
            || mm2bcCatLordDimensionDoorsPerDay() != 9
            || mm2bcCatLordEtherealPerDay() != 2
            || mm2bcCatLordHastePerDay() != 2
            || mm2bcCatLordTeleportPerDay() != 1
            || mm2bcCatfishSwallowAtHdGnome() != 7
            || mm2bcCatfishSwallowAtHdDwarf() != 8
            || mm2bcCatfishSwallowAtHdSmall() != 9
            || mm2bcCatfishSwallowAtHdLarge() != 10
            || mm2bcCatfishDigestDmgPerRound() != 1
            || mm2bcCatfishSuffocatePctPerRound() != 5
            || mm2bcCatfishCutOutAtPct() != 50
            || mm2bcCatfishPierceHitsVictimPct() != 20
            || mm2bcCatfishWhiskerDmgMin() != 2
            || mm2bcCatfishWhiskerDmgMax() != 8
            || mm2bcCatfishWhiskerSaveDmgMin() != 1
            || mm2bcCatfishWhiskerSaveDmgMax() != 4
            || mm2bcCatfishWhiskerExtraTargets() != 2
            || mm2bcCaveCricketChirpRangeFt() != 20
            || mm2bcCaveCricketHearingRangeIn() != 90
            || mm2bcCaveCricketDrawIn6() != 2
            || mm2bcCaveCricketLeapIn6() != 1
            || mm2bcCaveCricketLeapDmgMin() != 1
            || mm2bcCaveCricketLeapDmgMax() != 4
            || mm2bcCaveCricketKickRangeFt() != 10
            || mm2bcCaveFisherFilamentFt() != 60
            || mm2bcCaveFisherStrikeAsHd() != 6
            || mm2bcCaveFisherReelFtPerRound() != 15
            || mm2bcCaveFisherMaxPreyLbs() != 400
            || mm2bcCaveFisherNoticePct() != 20
            || mm2bcCaveFisherNoticeRangeFt() != 10
            || mm2bcCaveFisherLegs() != 8
            || mm2bcCaveFisherPincerLegs() != 2
            || mm2bcCaveMorayStrikeMinFt() != 3
            || mm2bcCaveMorayStrikeMaxFt() != 5
            || mm2bcCaveMorayBodyAC() != 5
            || mm2bcCaveMorayHitChanceIn20() != 1
            || mm2bcCentipedeHugeSaveBonus() != 4
            || mm2bcCentipedeHugeFailDmgMin() != 4
            || mm2bcCentipedeHugeFailDmgMax() != 16
            || mm2bcCentipedeHugeSelfSavePenalty() != 2
            || mm2bcCentipedeMegaloSaveDmgMin() != 1
            || mm2bcCentipedeMegaloSaveDmgMax() != 8
            || mm2bcCheetahSprintIn() != 45
            || mm2bcCheetahSprintRounds() != 3
            || mm2bcCheetahRestTurns() != 3
            || mm2bcCheetahSpringUpFt() != 10
            || mm2bcCheetahSpringFwdFt() != 20
            || mm2bcCheetahSurpriseIn6() != 3
            || mm2bcCheetahCubsMin() != 1
            || mm2bcCheetahCubsMax() != 4
            || mm2bcCheetahParentBonus() != 2
            || mm2bcChokeStemLenFt() != 100
            || mm2bcChokeVineCreepFtPerRound() != 5
            || mm2bcChokeVineSeverMin() != 2
            || mm2bcChokeVineSeverMax() != 16
            || mm2bcChokeOldHpPerDie() != 8
            || mm2bcChokeOldHp() != 200
            || mm2bcChokeSmallHpPerDie() != 1
            || mm2bcChokeSqueezeDmgMin() != 1
            || mm2bcChokeSqueezeDmgMax() != 4
            || mm2bcChokeStranglePctPerTurn() != 10
            || mm2bcChokeVinesPerSection() != 8
            || mm2bcChokeVineLenMinFt() != 9
            || mm2bcChokeVineLenMaxFt() != 16
            || mm2bcChokeColdDmgPerDie() != 1
            || mm2bcChokeColdImmobilizeMin() != 2
            || mm2bcChokeColdImmobilizeMax() != 5
            || mm2bcCloakerFlyIn() != 15
            || mm2bcCloakerCreepIn() != 1
            || mm2bcCloakerTailDmgMin() != 1
            || mm2bcCloakerTailDmgMax() != 6
            || mm2bcCloakerTailStrikes() != 2
            || mm2bcCloakerTailAC() != 1
            || mm2bcCloakerTailHp() != 16
            || mm2bcCloakerBiteAddMin() != 1
            || mm2bcCloakerBiteAddMax() != 4
            || mm2bcCloakerMoanUneaseRangeFt() != 80
            || mm2bcCloakerMoanNumbTurns() != 6
            || mm2bcCloakerMoanFearRangeFt() != 30
            || mm2bcCloakerMoanFearRounds() != 2
            || mm2bcCloakerMoanNauseaConeFt() != 30
            || mm2bcCloakerMoanNauseaWidthFt() != 20
            || mm2bcCloakerMoanNauseaMin() != 2
            || mm2bcCloakerMoanNauseaMax() != 5
            || mm2bcCloakerMoanHoldRangeFt() != 30
            || mm2bcCloakerMoanHoldRounds() != 5
            || mm2bcCloakerShadowAC() != 1
            || mm2bcCoosheeChaseIn() != 21
            || mm2bcCoosheeBarkMiles() != 1
            || mm2bcCoosheeHidePct() != 75
            || mm2bcCoosheeWeightMinLbs() != 168
            || mm2bcCoosheeWeightMaxLbs() != 310
            || mm2bcCoosheeProneHitBonus() != 2
            || mm2bcCraneImmatureThreshold() != 10
            || mm2bcCraneImmaturePct() != 50
            || mm2bcCraneFlockAtEncounter() != 20
            || mm2bcCraneFlockChancePct() != 50
            || mm2bcCraneFlockMin() != 31
            || mm2bcCraneFlockMax() != 50
            || mm2bcCraneFledglingsMin() != 3
            || mm2bcCraneFledglingsMax() != 12
            || mm2bcCrysmalGemsMin() != 4
            || mm2bcCrysmalGemsMax() != 32
            || mm2bcCrysmalEdgedAC() != -4
            || mm2bcCrysmalBluntAC() != 0
            || mm2bcCrysmalAppendageRangeIn() != 2
            || mm2bcCrysmalAppendageDmgMin() != 9
            || mm2bcCrysmalAppendageDmgMax() != 16
            || mm2bcCrysmalPrimaryDmgMin() != 3
            || mm2bcCrysmalSecondaryDmgMin() != 2
            || mm2bcCrysmalSecondaryDmgMax() != 8
            || mm2bcCrysmalShatterDmgMin() != 3
            || mm2bcCrysmalShatterDmgMax() != 18
            || mm2bcCrysmalGlasseeBlindMin() != 2
            || mm2bcCrysmalGlasseeBlindMax() != 5
            || mm2bcCrysmalStoneToFleshAC() != 6
            || mm2bcCrysmalRockShiftRounds() != 1
            || mm2bcCrysmalMediumHp() != 16
            || mm2bcCrystalOozeInvisiblePct() != 75
            || mm2bcCrystalOozeConsumedAtHp() != 20
            || mm2bcCrystalOozeBlowDmg() != 1
            || mm2bcCyclopskinMissilePenalty() != 2
            || mm2bcCyclopskinDamageBonus() != 2
            || mm2bcCyclopskinRaidBandMax() != 80
            || !mm2bcMultiLetterPass()
            || !mm2bcBatRidesTwoDefs()
            || !mm2bcBeeRidesThreeDefs()
            || !mm2bcBeetleRidesTwoDefs()
            || !mm2bcCatRidesTwoDefs()
            || !mm2bcCentipedeRidesTwoDefs()
            || !mm2bcBehemothXpSettledFromCapture()
            || !mm2bcCloakerXpHpSettledBookInternal()
            || !mm2bcBeeQueenHdIs8Plus6()
            || !mm2bcCaveMorayXpLevelIsII()
            || !mm2bcCatDomesticMoveIsFive()
            || !mm2bcCyclopskinAlignPrintedVerbatim()
            || !mm2bcMm2PrintRidesXpAudit()
            || !mm2bcDefsRideDataFiles()
            || !mm2bcPinHeaderStaysPrintRecord()
            || !mm2bcBakuInvisibleAtWill()
            || !mm2bcBakuEtherealAndAstral()
            || !mm2bcBakuStompManSizeOnly()
            || !mm2bcBakuRoarSaveOrFlee()
            || !mm2bcBakuHatesEvil()
            || !mm2bcBanderlogCoconutMissiles()
            || !mm2bcBanderlogLedByLargeMales()
            || !mm2bcBanderlogOwnLanguage()
            || !mm2bcBarghestAssumesCanineForm()
            || !mm2bcBarghestHitOnlyByPlusOne()
            || !mm2bcBarghestFireDoesNoDamage()
            || !mm2bcBarghestFireFailReturnsHome()
            || !mm2bcBarghestWorshippedByGoblins()
            || !mm2bcBarghestAtWillMagicOnePerRound()
            || !mm2bcBarghestDailyMagicOncePerDay()
            || !mm2bcBarkburrAlwaysInLair()
            || !mm2bcBarkburrAlwaysSurprises()
            || !mm2bcBarkburrLignifySaveEachRound()
            || !mm2bcBarkburrLignifyCannotBeStopped()
            || !mm2bcBarkburrImmuneToMindSpells()
            || !mm2bcBarkburrWishRestoresAfterComplete()
            || !mm2bcBarkburrDireburrAlwaysDeadTree()
            || !mm2bcBasidirondSporesOnlyWhenStill()
            || !mm2bcBasidirondHallucinationSavesEachRound()
            || !mm2bcBasidirondImmuneToMentalAttacks()
            || !mm2bcBasidirondColdSlowsToHalf()
            || !mm2bcBasidirondColdBlocksSpores()
            || !mm2bcBasiliskGreaterGazeTurnsToStone()
            || !mm2bcBasiliskGreaterBreathKills()
            || !mm2bcBasiliskGreaterSeesAstralEthereal()
            || !mm2bcBasiliskGreaterHabitatEarth()
            || !mm2bcMobatScreechSaveVsParalysis()
            || !mm2bcMobatSonarDarkFlight()
            || !mm2bcMobatDesiresShinyObjects()
            || !mm2bcBatAttacksOnlyIfCornered()
            || !mm2bcBatSwarmDisruptsCasting()
            || !mm2bcBatSonarTotalDarkness()
            || !mm2bcFireBatDetectsInvisible()
            || !mm2bcFireBatUnharmedBySunlight()
            || !mm2bcFireBatAlliedWithFireElementals()
            || !mm2bcFireBatAutoFeedAfterAttach()
            || !mm2bcFireBatRebornOnHomePlane()
            || !mm2bcFireBatPackHuntsEvenly()
            || !mm2bcFireBatGlidesThroughLava()
            || !mm2bcBearNorthernHugOnHighRoll()
            || !mm2bcBearNorthernFightsPastZero()
            || !mm2bcBeeQueenNoncombatantInHive()
            || !mm2bcBeeQueenCombativeInNest()
            || !mm2bcBeeBreadEqualsIronRations()
            || !mm2bcBeeUnguentPreservesCharisma()
            || !mm2bcDeathWatchClickPrecedesBite()
            || !mm2bcDeathWatchCamouflagesItself()
            || !mm2bcSlicerSeversOnHighRoll()
            || !mm2bcSlicerFleesWithFood()
            || !mm2bcSlicerUnmatchedBootsDeceive()
            || !mm2bcBehemothBullAlwaysAggressive()
            || !mm2bcBehemothCowsAggressiveWithCalf()
            || !mm2bcBehemothAttacksBoatsAndSwimmers()
            || !mm2bcBehirLoopThenTalons()
            || !mm2bcBehirLightningSaveVsBreath()
            || !mm2bcBehirClimbsAtHalfSpeed()
            || !mm2bcBehirSwallowsWhole()
            || !mm2bcBehirSlithersFolded()
            || !mm2bcBloodthornSeverSparesPlant()
            || !mm2bcBloodthornResemblesHornwood()
            || !mm2bcBloodthornGrowsSingly()
            || !mm2bcBoaliskGazeEachRound()
            || !mm2bcBoaliskGazeRotsLikeMummy()
            || !mm2bcBoaliskConstrictSingleVictim()
            || !mm2bcBoaliskIdenticalToConstrictor()
            || !mm2bcBodakGazeKills()
            || !mm2bcBodakPlusOneOrColdIron()
            || !mm2bcBodakImmuneCharmHoldSleepSlow()
            || !mm2bcBodakUnharmedByPoison()
            || !mm2bcBodakSpeaksDemonTongue()
            || !mm2bcBodakFromTheAbyss()
            || !mm2bcBoggartImmatureWillOWisp()
            || !mm2bcBoggartConfusionNeedsTwoRounds()
            || !mm2bcBoggartOnlyThreeSpellsWork()
            || !mm2bcBoggartNoResurrectionPossible()
            || !mm2bcBoggartCannotPassMetal()
            || !mm2bcBoggartInvisibleWhileNoisy()
            || !mm2bcBoggartSpeaksAllLanguagesByEsp()
            || !mm2bcBoggleOilFellsFoes()
            || !mm2bcBoggleFireResistant()
            || !mm2bcBoggleSpiderClimbAtWill()
            || !mm2bcBoggleDoorsThroughFrames()
            || !mm2bcBoggleSmellsInvisible()
            || !mm2bcBoggleKeeningWarnsMasters()
            || !mm2bcBoggleElasticHide()
            || !mm2bcBoobrieImmuneToPoison()
            || !mm2bcBoobrieSlowFlight()
            || !mm2bcBoobriePrefersCatfishAndMen()
            || !mm2bcBookwormAttractedToPaper()
            || !mm2bcBookwormCannotDigestLivingMatter()
            || !mm2bcBookwormFleesAfterAttack()
            || !mm2bcBookwormChameleonHides()
            || !mm2bcBookwormSeeksLargestVolume()
            || !mm2bcBowlerNoVisualOrgans()
            || !mm2bcBowlerRollsOverVictims()
            || !mm2bcBowlerDetectsOwnVibrations()
            || !mm2bcBowlerCamouflagedAsRock()
            || !mm2bcBuckawnNeverSurprised()
            || !mm2bcBuckawnDetectsInvisible()
            || !mm2bcBuckawnDruggedDarts()
            || !mm2bcBuckawnAtWillPowersPerRound()
            || !mm2bcBuckawnDailyPowersOnceEach()
            || !mm2bcBuckawnShunHumans()
            || !mm2bcCatDomesticSingleForepaw()
            || !mm2bcCatWildTwoForepaws()
            || !mm2bcCatRakeOnForepawHit()
            || !mm2bcCatDomesticAvoidsBigFoes()
            || !mm2bcCatInterbreed()
            || !mm2bcCatLordAlwaysInitiative()
            || !mm2bcCatLordLandsOnFeet()
            || !mm2bcCatLordSpitBlindsNoRoll()
            || !mm2bcCatLordSpitEveryOtherRound()
            || !mm2bcCatLordYowlStunsNonFelines()
            || !mm2bcCatLordLickHeals()
            || !mm2bcCatLordSummonsLoyalFelines()
            || !mm2bcCatLordRecognizedByAllFelines()
            || !mm2bcCatLordHasteNotInMonkForm()
            || !mm2bcCatLordFriendXanYae()
            || !mm2bcCatfishSwallowsWhole()
            || !mm2bcCatfishWhiskersPoisonous()
            || !mm2bcCatfishNeedsEdgedWeaponInside()
            || !mm2bcCatfishBottomFeeder()
            || !mm2bcCaveCricketChirpDrownsSpeech()
            || !mm2bcCaveCricketDrawsPredators()
            || !mm2bcCaveCricketKicksNearby()
            || !mm2bcCaveCricketEatsGear()
            || !mm2bcCaveFisherFilamentPlusOneOnly()
            || !mm2bcCaveFisherAlcoholDissolvesAdhesive()
            || !mm2bcCaveFisherCementsItself()
            || !mm2bcCaveFisherRelocatesWhenAvoided()
            || !mm2bcCaveFisherHidesOverPaths()
            || !mm2bcCaveMorayStrikesFromCysts()
            || !mm2bcCaveMorayWithdrawsToRecoil()
            || !mm2bcCaveMorayLooksLikeRock()
            || !mm2bcCentipedeHugePoisonNotDeadly()
            || !mm2bcCentipedeMegaloNormalSaves()
            || !mm2bcCentipedeMegaloBurnsSkinOnSave()
            || !mm2bcCentipedeCousinsOfGiant()
            || !mm2bcCheetahNonretractableClaws()
            || !mm2bcCheetahTrainable()
            || !mm2bcCheetahRakesOnDoubleForepawHit()
            || !mm2bcCheetahCubsNoAttack()
            || !mm2bcCheetahParentsDefendToDeath()
            || !mm2bcChokeVinesAttractedToLight()
            || !mm2bcChokeStrangleKillsNextRound()
            || !mm2bcChokeTorchFireHarmless()
            || !mm2bcChokeElectricalDoublesSpeed()
            || !mm2bcChokeVineLossSparesPlant()
            || !mm2bcCloakerNoRearSurprise()
            || !mm2bcCloakerWrapsVictim()
            || !mm2bcCloakerSplitDamageWhenWrapped()
            || !mm2bcCloakerMoanBlockedByStone()
            || !mm2bcCloakerNoBiteAndMoanTogether()
            || !mm2bcCloakerMoanNeutralizedByPoisonFix()
            || !mm2bcCloakerShadowDoubles()
            || !mm2bcCloakerLightBlinds()
            || !mm2bcCloakerBiteAddsVictimAC()
            || !mm2bcCoosheeKnocksOverFoes()
            || !mm2bcCoosheeBarksOnlyToWarn()
            || !mm2bcCoosheeAvoidsCanines()
            || !mm2bcCoosheeMovesSilently()
            || !mm2bcCoosheeElvenCompany()
            || !mm2bcCraneProtectsOwn()
            || !mm2bcCraneGenerallyNonaggressive()
            || !mm2bcCraneHuntsLargeFish()
            || !mm2bcCrysmalImmuneFireCold()
            || !mm2bcCrysmalElectricalQuarter()
            || !mm2bcCrysmalImmunePoisonGas()
            || !mm2bcCrysmalMovesThroughRock()
            || !mm2bcCrysmalPhaseDoorKillsShifting()
            || !mm2bcCrysmalHatesXorn()
            || !mm2bcCrysmalProjectileLosesPrimary()
            || !mm2bcCrysmalDietMinerals()
            || !mm2bcCrystalOozeParalyticPoison()
            || !mm2bcCrystalOozeImmuneAcidColdHeatFire()
            || !mm2bcCrystalOozeElectricityFullDamage()
            || !mm2bcCrystalOozeEatsWoodenWeapons()
            || !mm2bcCrystalOozeLivesInShallowWater()
            || !mm2bcCyclopskinPoorDepthPerception()
            || !mm2bcCyclopskinShunOthers()
            || !mm2bcCyclopskinCarrySlingAndSpear()
            || !mm2bcCyclopskinDwellInCaves()
        )
            ++bad;
        // the 26 x 9 B stat grid - the stat-block cells of the twenty-six
        // promoted B defs in print order (the baku through the buckawn):
        // armor class, hit dice, hit-die bonus, average hit points, attacks,
        // base xp, xp per hit, lair percent and the primary move rate
        int CBStats[26][9] = {
            {-2,12,12,54,3,4900,18,0,21},
            {6,4,0,14,1,60,4,15,6},
            {2,6,6,27,2,1275,10,0,15},
            {0,2,0,7,1,65,2,100,0},
            {4,5,5,22,1,475,6,60,6},
            {2,10,0,35,3,3000,14,50,6},
            {7,4,0,14,1,150,5,15,3},
            {8,0,0,1,1,1,0,0,1},
            {8,2,0,7,1,28,2,50,6},
            {6,8,8,36,3,900,12,0,12},
            {6,3,1,11,1,150,4,20,9},
            {5,4,2,16,1,200,5,90,12},
            {5,6,4,25,1,400,8,10,6},
            {3,9,0,31,1,1400,12,10,12},
            {3,6,0,21,1,275,6,25,6},
            {4,10,5,40,1,1800,15,0,6},
            {4,12,0,42,9,2850,16,0,15},
            {4,5,0,17,8,800,35,0,0},
            {5,5,1,18,2,350,6,0,12},
            {5,9,9,40,1,1950,14,0,6},
            {-6,6,0,21,1,625,6,0,18},
            {5,4,3,17,3,170,5,25,9},
            {5,9,0,31,3,900,12,0,15},
            {2,0,0,2,1,7,1,25,12},
            {4,0,0,2,1,5,1,35,6},
            {3,1,-1,2,1,65,1,10,12},
            };
        for (int b = 0;
             b < mm2bcBStatRows();
             ++b) {
            int vals[9];
            vals[0] = mm2bcBStatAC(b);
            vals[1] = mm2bcBStatHd(b);
            vals[2] = mm2bcBStatHdBonus(b);
            vals[3] = mm2bcBStatAvgHp(b);
            vals[4] = mm2bcBStatAttacks(b);
            vals[5] = mm2bcBStatXp(b);
            vals[6] = mm2bcBStatXpHp(b);
            vals[7] = mm2bcBStatLairPct(b);
            vals[8] = mm2bcBStatMove(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CBStats[b][c])
                    ++bad;
            }
        }
        // the 17 x 9 C stat grid - the stat-block cells of the seventeen
        // promoted C defs in print order (the domestic cat through the
        // cyclopskin): the same nine columns as the B grid
        int CCStats[17][9] = {
            {6,0,0,1,2,5,1,0,5},
            {5,1,0,3,3,10,1,0,18},
            {-9,0,0,81,3,13900,0,0,27},
            {7,7,0,24,1,650,12,0,18},
            {4,1,3,6,1,20,2,0,6},
            {4,3,0,10,2,85,3,100,1},
            {0,4,4,18,1,130,5,100,1},
            {9,0,0,1,1,31,0,0,21},
            {5,3,0,10,1,125,3,0,18},
            {5,3,0,10,3,65,3,15,15},
            {6,25,0,87,8,7600,35,0,1},
            {3,6,0,21,2,350,6,15,1},
            {5,3,3,13,1,110,4,0,15},
            {5,3,0,10,1,35,3,0,9},
            {-4,6,6,27,1,825,10,0,6},
            {8,4,0,14,1,225,4,0,1},
            {3,5,0,17,1,90,5,35,12},
            };
        for (int b = 0;
             b < mm2bcCStatRows();
             ++b) {
            int vals[9];
            vals[0] = mm2bcCStatAC(b);
            vals[1] = mm2bcCStatHd(b);
            vals[2] = mm2bcCStatHdBonus(b);
            vals[3] = mm2bcCStatAvgHp(b);
            vals[4] = mm2bcCStatAttacks(b);
            vals[5] = mm2bcCStatXp(b);
            vals[6] = mm2bcCStatXpHp(b);
            vals[7] = mm2bcCStatLairPct(b);
            vals[8] = mm2bcCStatMove(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CCStats[b][c])
                    ++bad;
            }
        }
        // the 7 x 6 barghest brackets - the whelp-to-adult growth ladder of
        // hit dice 6+6 through 12+12: the armor class falls 2 to -4 one place
        // per die, the magic resistance rises 5% per die (pluses ignored),
        // and the xp brackets step 1275+10 through 7300+18
        int CBarghestBrackets[7][6] = {
            {6,6,2,30,1275,10},
            {7,7,1,35,2000,12},
            {8,8,0,40,3450,14},
            {9,9,-1,45,3600,14},
            {10,10,-2,50,6100,16},
            {11,11,-3,55,6250,16},
            {12,12,-4,60,7300,18},
            };
        for (int b = 0;
             b < mm2bcBarghestBracketRows();
             ++b) {
            int vals[6];
            vals[0] = mm2bcBarghestHd(b);
            vals[1] = mm2bcBarghestHdBonus(b);
            vals[2] = mm2bcBarghestAC(b);
            vals[3] = mm2bcBarghestMR(b);
            vals[4] = mm2bcBarghestXp(b);
            vals[5] = mm2bcBarghestXpHp(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CBarghestBrackets[b][c])
                    ++bad;
            }
        }
        // the 6 x 3 barkburr ladder - the hit-dice 1 through 6 rungs with the
        // base xp and xp per hit of each (the 2-6 stat-block range pins its
        // low end, the 2-HD rung)
        int CBarkburrLadder[6][3] = {
            {1,45,1},
            {2,65,2},
            {3,90,3},
            {4,125,4},
            {5,165,5},
            {6,275,6},
            };
        for (int b = 0;
             b < mm2bcBarkburrLadderRows();
             ++b) {
            int vals[3];
            vals[0] = mm2bcBarkburrHd(b);
            vals[1] = mm2bcBarkburrXp(b);
            vals[2] = mm2bcBarkburrXpHp(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CBarkburrLadder[b][c])
                    ++bad;
            }
        }
        // the 3 x 7 bloodthorn bands - the attack-data table of the print:
        // the size bands by hit-dice range with their tendril counts, lash
        // reach in feet, tendril hit points (5-10 to sever overall) and the
        // attacks-as hit dice
        int CBloodthornGrid[3][7] = {
            {5,16,5,5,5,6,3},
            {17,25,8,6,7,8,4},
            {26,30,12,7,9,10,5},
            };
        for (int b = 0;
             b < mm2bcBloodthornRows();
             ++b) {
            int vals[7];
            vals[0] = mm2bcBloodthornHdLo(b);
            vals[1] = mm2bcBloodthornHdHi(b);
            vals[2] = mm2bcBloodthornTendrils(b);
            vals[3] = mm2bcBloodthornRangeFt(b);
            vals[4] = mm2bcBloodthornTvHpMin(b);
            vals[5] = mm2bcBloodthornTvHpMax(b);
            vals[6] = mm2bcBloodthornAttacksAs(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CBloodthornGrid[b][c])
                    ++bad;
            }
        }
        // the 9 x 4 feline summon grid - the cat lord in feline form summons
        // at will: the percentile bands 01-07 through 71-00 with their
        // minimum and maximum felines (smilodons through wild cats), tiling
        // 1-100
        int CCatLordFelineSummon[9][4] = {
            {1,7,1,4},
            {8,15,2,5},
            {16,25,3,6},
            {26,34,3,6},
            {35,43,4,7},
            {44,52,5,8},
            {53,61,5,8},
            {62,70,6,9},
            {71,100,6,9},
            };
        for (int b = 0;
             b < mm2bcFelineSummonRows();
             ++b) {
            int vals[4];
            vals[0] = mm2bcFelineLo(b);
            vals[1] = mm2bcFelineHi(b);
            vals[2] = mm2bcFelineMin(b);
            vals[3] = mm2bcFelineMax(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CCatLordFelineSummon[b][c])
                    ++bad;
            }
        }
        // the 4 x 4 human-form summon grid - the cat lord in human form
        // summons: the percentile bands 01-15 through 46-00 with their
        // minimum and maximum summons (weretigers, elfin cats, giant lynxes,
        // domestic cats), tiling 1-100
        int CCatLordHumanSummon[4][4] = {
            {1,15,1,2},
            {16,30,5,8},
            {31,45,7,12},
            {46,100,31,50},
            };
        for (int b = 0;
             b < mm2bcHumanSummonRows();
             ++b) {
            int vals[4];
            vals[0] = mm2bcHumanLo(b);
            vals[1] = mm2bcHumanHi(b);
            vals[2] = mm2bcHumanMin(b);
            vals[3] = mm2bcHumanMax(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CCatLordHumanSummon[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count (the census walk)
    if (mm2bcRegistryAfter() - mm2bcRegistryBefore() != mm2bcDefCount()
            || mm2bcDefCount() != mm2bcEntryCount() + mm2bcExtraFormDefs()
            || mm2bcBDefCount() + mm2bcCDefCount() != mm2bcDefCount()
        )
            ++bad;
        // the barghest stat row rides bracket 0 (the whelp low end)
    if (mm2bcBarghestHd(0) != mm2bcBStatHd(2)
            || mm2bcBarghestHdBonus(0) != mm2bcBStatHdBonus(2)
            || mm2bcBarghestAC(0) != mm2bcBStatAC(2)
            || mm2bcBarghestXp(0) != mm2bcBStatXp(2)
            || mm2bcBarghestXpHp(0) != mm2bcBStatXpHp(2)
        )
            ++bad;
        // the barkburr stat row rides the 2-HD rung (the low-end range rule)
    if (mm2bcBarkburrHd(1) != mm2bcBStatHd(3)
            || mm2bcBarkburrXp(1) != mm2bcBStatXp(3)
            || mm2bcBarkburrXpHp(1) != mm2bcBStatXpHp(3)
        )
            ++bad;
        // the bloodthorn stat HD 5 rides its attack-data low band (the
        // low-end range rule)
    if (mm2bcBloodthornHdLo(0) != mm2bcBStatHd(17)
        )
            ++bad;
        // the cloaker xp/hp equals the flat-6-HD boggart and slicer cells
        // (the book-internal settlement)
    if (mm2bcBStatXpHp(20) != mm2bcCStatXpHp(11)
            || mm2bcBStatXpHp(14) != mm2bcCStatXpHp(11)
        )
            ++bad;
        // the feline summon bands tile 1-100 without gaps or overlaps
    if (mm2bcFelineLo(0) != 1
            || mm2bcFelineHi(8) != 100
            || mm2bcFelineLo(1) != mm2bcFelineHi(0) + 1
            || mm2bcFelineLo(2) != mm2bcFelineHi(1) + 1
            || mm2bcFelineLo(3) != mm2bcFelineHi(2) + 1
            || mm2bcFelineLo(4) != mm2bcFelineHi(3) + 1
            || mm2bcFelineLo(5) != mm2bcFelineHi(4) + 1
            || mm2bcFelineLo(6) != mm2bcFelineHi(5) + 1
            || mm2bcFelineLo(7) != mm2bcFelineHi(6) + 1
            || mm2bcFelineLo(8) != mm2bcFelineHi(7) + 1
        )
            ++bad;
        // the human-form summon bands tile 1-100 without gaps or overlaps
    if (mm2bcHumanLo(0) != 1
            || mm2bcHumanHi(3) != 100
            || mm2bcHumanLo(1) != mm2bcHumanHi(0) + 1
            || mm2bcHumanLo(2) != mm2bcHumanHi(1) + 1
            || mm2bcHumanLo(3) != mm2bcHumanHi(2) + 1
        )
            ++bad;
        // the barghest armor class falls one place per hit die, 2 to -4
    if (mm2bcBarghestAC(1) != mm2bcBarghestAC(0) - 1
            || mm2bcBarghestAC(2) != mm2bcBarghestAC(1) - 1
            || mm2bcBarghestAC(3) != mm2bcBarghestAC(2) - 1
            || mm2bcBarghestAC(4) != mm2bcBarghestAC(3) - 1
            || mm2bcBarghestAC(5) != mm2bcBarghestAC(4) - 1
            || mm2bcBarghestAC(6) != mm2bcBarghestAC(5) - 1
        )
            ++bad;
        // the barghest magic resistance rises 5% per hit die (the pluses
        // ignored)
    if (mm2bcBarghestMR(1) != mm2bcBarghestMR(0) + 5
            || mm2bcBarghestMR(2) != mm2bcBarghestMR(1) + 5
            || mm2bcBarghestMR(3) != mm2bcBarghestMR(2) + 5
            || mm2bcBarghestMR(4) != mm2bcBarghestMR(3) + 5
            || mm2bcBarghestMR(5) != mm2bcBarghestMR(4) + 5
            || mm2bcBarghestMR(6) != mm2bcBarghestMR(5) + 5
        )
            ++bad;
        // the bumblebee queen pins read 8+6 (the capture hyphen settled as
        // the plus)
    if (mm2bcBeeQueenHdNum() != 8
            || mm2bcBeeQueenHdBonus() != 6
        )
            ++bad;
        printf("R798 MM2 letters BC audit: bad %d\n", bad);
        if (bad) return 1;
    }
