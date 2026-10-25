    // ---- R808 MM2 letters LMN walk audit ----
    // THE MM2 LETTERS LMN WALK - the land lamprey and the luck eater p. 80,
    // the lycanthrope family (the foxwoman, the seawolf greater and lesser,
    // the wereshark) pp. 80-82, the magman, the mandragora, the giant mantis,
    // the mantrap, the margoyle, the marid, the shadow mastiff, the mihstu
    // pp. 82-85, the miner and the minimal doctrine pp. 85-86, the 15 modron
    // blocks pp. 86-91, the russet mold pp. 91-92, the mongrelman and the
    // moon dog pp. 92-93, the muckdweller and the mud-man pp. 93-94, the
    // myconid pp. 94-95 and the nereid and the narwhale p. 95 promoted to the
    // live registry; the contested cells settled: the moon dog xp level reads
    // VII/2000 + 12/hp (the capture "V/1/2000" the OCR artifact); the mud-man
    // xp level reads II/28 (the capture "11/28" the misread); the minimal
    // move factor reads 1/2 (the djvu "Va" the misread - the agreeing
    // capture; 1eonline 2/3 its error); the minimal lion New HD prints "13"
    // (the 1+3 misprint kept verbatim); the mammoth row reads HD 3+4, attacks
    // 5, damage 3-6/3-6/2-5/1-3/1-3, xp 125+4; the octon size reads "L
    // (7'-10' tall)" (the capture "7-0'" the misread); the russet mold block
    // prints no TREASURE TYPE line (the R806 haunt precedent - the field
    // rides empty); the negative armor class cells ride unquoted numbers (the
    // R806 hollyphant -4 precedent); every Standard and See below magic
    // resistance reads 0; the composite attack loads read their max (the
    // seawolf lesser "1 (3)" 3, the quadrone "4 or 2" 4, the mantrap "2-5" 5)
    // with the 1 floor and the 10 ceiling; the flat-hp reads pin the avgHp
    // (the primus 220, the russet mold 16, the muckdweller 4) with hitDiceNum
    // 0; the by_level defs (the mandragora, the mongrelman, the myconid)
    // carry no xp fields and the walk skips the xpValue formula for them
    {
        using namespace rules;
        int bad = 0;
    if (mm2lmnRound() != 808
            || mm2lmnRegistryBefore() != 661
            || mm2lmnRegistryAfter() != 699
            || mm2lmnDefCount() != 38
            || mm2lmnEntryCount() != 22
            || mm2lmnStatBlockHeadings() != 38
            || mm2lmnDoctrineHeads() != 2
            || mm2lmnLetterLHeadings() != 3
            || mm2lmnLetterMHeadings() != 17
            || mm2lmnLetterNHeadings() != 2
            || mm2lmnLmStatRows() != 38
            || mm2lmnGapClosed() != 19
            || mm2lmnGapOpen() != 18
            || mm2lmnPriorOwnedEntries() != 0
            || mm2lmnModronBlocks() != 15
            || mm2lmnByLevelDefs() != 3
            || mm2lmnLycanthropeStatBlocks() != 4
            || mm2lmnMinimalStatRows() != 29
            || mm2lmnTelepathyMilesRows() != 9
            || mm2lmnCensusBefore() != 730
            || mm2lmnCensusAfter() != 731
            || mm2lmnPrintOpensPage() != 80
            || mm2lmnPrintClosesPage() != 95
            || mm2lmnNirvanaSectors() != 64
            || mm2lmnNirvanaSectorsPerRegion() != 4
            || mm2lmnNirvanaRegionsPerQuarter() != 4
            || mm2lmnNirvanaArmies() != 36
            || mm2lmnNirvanaBrigadeTotal() != 3142
            || mm2lmnNirvanaBrigadeOfficers() != 70
            || mm2lmnNirvanaBrigadeNcos() != 192
            || mm2lmnNirvanaBrigadeMessengers() != 252
            || mm2lmnNirvanaBrigadeLineTroops() != 2628
            || mm2lmnModronReformationDays() != 9
            || mm2lmnModronCorpsPerArmy() != 4
            || mm2lmnModronDivisionsPerCorps() != 2
            || mm2lmnModronBrigadesPerDivision() != 4
            || mm2lmnModronRegimentsPerBrigade() != 4
            || mm2lmnModronSaveBonusVsElements() != 1
            || mm2lmnLandLampreyXpValue() != 46
            || mm2lmnLandLampreyXpLevel() != 2
            || mm2lmnLandLampreyDrainRounds() != 3
            || mm2lmnLandLampreyDexLossPerAttached() != 1
            || mm2lmnLandLampreyLengthFeet() != 3
            || mm2lmnLuckEaterXpValue() != 181
            || mm2lmnLuckEaterXpLevel() != 2
            || mm2lmnLuckEaterPurrRangeFeet() != 30
            || mm2lmnLuckEaterPenaltyPct() != 10
            || mm2lmnLuckEaterStayHoursMin() != 2
            || mm2lmnLuckEaterStayHoursMax() != 5
            || mm2lmnLuckEaterBrawlRounds() != 10
            || mm2lmnLuckEaterSensesReturnTurnsMax() != 6
            || mm2lmnLycanthropeFullMoonPct() != 90
            || mm2lmnLycanthropeBelladonnaCurePct() != 25
            || mm2lmnLycanthropeCurePatriarchLevel() != 12
            || mm2lmnLycanthropeInfectionDamagePct() != 50
            || mm2lmnLycanthropeOnsetDaysMin() != 7
            || mm2lmnLycanthropeOnsetDaysMax() != 14
            || mm2lmnLycanthropeBelladonnaPoisonDeathPct() != 1
            || mm2lmnLycanthropeBelladonnaIncapacitateDaysMax() != 4
            || mm2lmnFoxwomanXpValue() != 2048
            || mm2lmnFoxwomanXpLevel() != 7
            || mm2lmnFoxwomanForms() != 3
            || mm2lmnFoxwomanCharmedMalesMin() != 2
            || mm2lmnFoxwomanCharmedMalesMax() != 5
            || mm2lmnFoxwomanInfravisionInches() != 6
            || mm2lmnFoxwomanHalfElvenMalesPct() != 50
            || mm2lmnFoxwomanVixenInfectionDays() != 3
            || mm2lmnFoxwomanSleepCharmResistPct() != 90
            || mm2lmnFoxwomanComeliness() != 21
            || mm2lmnFoxwomanStolenChildAgeMax() != 13
            || mm2lmnFoxwomanArmorForms() != 6
            || mm2lmnSeawolfGreaterXpValue() != 1296
            || mm2lmnSeawolfGreaterXpLevel() != 6
            || mm2lmnSeawolfLesserXpValue() != 77
            || mm2lmnSeawolfLesserXpLevel() != 2
            || mm2lmnSeawolfGreaterSubmergedMinutesMin() != 17
            || mm2lmnSeawolfGreaterSubmergedMinutesMax() != 24
            || mm2lmnSeawolfGreaterInfectionDaysMin() != 2
            || mm2lmnSeawolfGreaterInfectionDaysMax() != 5
            || mm2lmnSeawolfLesserForms() != 2
            || mm2lmnSeawolfLesserInfectionDamagePct() != 50
            || mm2lmnWeresharkXpValue() != 2032
            || mm2lmnWeresharkXpLevel() != 7
            || mm2lmnWeresharkGuardSharksMin() != 2
            || mm2lmnWeresharkGuardSharksMax() != 5
            || mm2lmnWeresharkLairPctIfUnderwater() != 20
            || mm2lmnMagmanXpValue() != 111
            || mm2lmnMagmanXpLevel() != 3
            || mm2lmnMagmanBurnDamageMax() != 8
            || mm2lmnMagmanBurnRoundsMin() != 3
            || mm2lmnMagmanBurnRoundsMax() != 6
            || mm2lmnMagmanFistDamageMax() != 24
            || mm2lmnMagmanOutOfLavaHours() != 6
            || mm2lmnMagmanHeightFeet() != 3
            || mm2lmnMandragoraDaylightStunSegmentsMin() != 1
            || mm2lmnMandragoraDaylightStunSegmentsMax() != 4
            || mm2lmnMandragoraStrangleDamageMax() != 4
            || mm2lmnMandragoraSenseRangeFeet() != 120
            || mm2lmnMandragoraLairPct() != 45
            || mm2lmnGiantMantisXpValue() != 1840
            || mm2lmnGiantMantisXpLevel() != 7
            || mm2lmnGiantMantisForelimbDamageMax() != 12
            || mm2lmnGiantMantisBiteDamageMax() != 12
            || mm2lmnGiantMantisHoldStrength() != 19
            || mm2lmnGiantMantisSurprisePct() != 75
            || mm2lmnGiantMantisHeightFeet() != 12
            || mm2lmnMantrapXpValue() != 359
            || mm2lmnMantrapXpLevel() != 5
            || mm2lmnMantrapPollenRangeFeet() != 60
            || mm2lmnMantrapLeafTrapsMin() != 2
            || mm2lmnMantrapLeafTrapsMax() != 5
            || mm2lmnMantrapFascinationSourHours() != 24
            || mm2lmnMantrapLairPct() != 100
            || mm2lmnMargoyleXpValue() != 476
            || mm2lmnMargoyleXpLevel() != 5
            || mm2lmnMargoyleLurkUndetectedPct() != 80
            || mm2lmnMargoyleGargoyleKinPct() != 20
            || mm2lmnMargoyleAttacks() != 4
            || mm2lmnMaridXpValue() != 5000
            || mm2lmnMaridXpLevel() != 8
            || mm2lmnMaridCarryGold() != 10000
            || mm2lmnMaridSpellLevel() != 26
            || mm2lmnMaridAlterRealityPerYear() != 1
            || mm2lmnMaridJetDamageMax() != 6
            || mm2lmnMaridJetRangeInches() != 6
            || mm2lmnMaridTiringTurns() != 3
            || mm2lmnMaridRestTurns() != 6
            || mm2lmnMaridUpToSevenPerDay() != 7
            || mm2lmnShadowMastiffXpValue() != 241
            || mm2lmnShadowMastiffXpLevel() != 4
            || mm2lmnShadowMastiffShadowUnseenPct() != 40
            || mm2lmnShadowMastiffBrightLightMoveLossPct() != 50
            || mm2lmnShadowMastiffLairWhelpPct() != 50
            || mm2lmnShadowMastiffWhelpsMin() != 2
            || mm2lmnShadowMastiffWhelpsMax() != 5
            || mm2lmnShadowMastiffWhelpPriceMin() != 200
            || mm2lmnShadowMastiffWhelpPriceMax() != 500
            || mm2lmnMihstuXpValue() != 2060
            || mm2lmnMihstuXpLevel() != 7
            || mm2lmnMihstuTentacles() != 4
            || mm2lmnMihstuConDrainPerRound() != 1
            || mm2lmnMihstuConRegainedPerDay() != 1
            || mm2lmnMihstuColdStunRoundsMax() != 12
            || mm2lmnMinerXpValue() != 1490
            || mm2lmnMinerXpLevel() != 6
            || mm2lmnMinerStepPctIfSurprised() != 75
            || mm2lmnMinerStepPctOtherwise() != 25
            || mm2lmnMinerIdentifyPctPerLevel() != 5
            || mm2lmnMinerParalysisTurnsMin() != 2
            || mm2lmnMinerParalysisTurnsMax() != 40
            || mm2lmnMinerBarbsMin() != 6
            || mm2lmnMinerBarbsMax() != 25
            || mm2lmnMinimalMoveFactorPct() != 50
            || mm2lmnMinimalAcPenalty() != 2
            || mm2lmnMinimalDamageCapMin() != 3
            || mm2lmnMinimalDamageCapMax() != 6
            || mm2lmnMinimalSaveBonus() != 2
            || mm2lmnMinimalCharmSaveBonus() != 4
            || mm2lmnMinimalLairPctBonus() != 10
            || mm2lmnMinimalOnlyMammalPct() != 80
            || mm2lmnMinimalIsolatedKinPct() != 30
            || mm2lmnMinimalMaxHitDice() != 3
            || mm2lmnMinimalMaxHitDiceBonus() != 4
            || mm2lmnMinimalLairMagicPct() != 5
            || mm2lmnMinimalTreasureLettersPct() != 40
            || mm2lmnMinimalLionHdBonus() != 3
            || mm2lmnMonodroneXpValue() != 36
            || mm2lmnMonodroneXpLevel() != 2
            || mm2lmnMonodroneUnitsOf() != 12
            || mm2lmnMonodroneMessengerWordLimit() != 48
            || mm2lmnMonodroneInfravisionFeet() != 30
            || mm2lmnDuodroneXpValue() != 77
            || mm2lmnDuodroneXpLevel() != 2
            || mm2lmnDuodroneSupervisesMonodroneUnits() != 12
            || mm2lmnDuodroneInfravisionFeet() != 90
            || mm2lmnTridroneXpValue() != 137
            || mm2lmnTridroneXpLevel() != 3
            || mm2lmnTridroneSupervises() != 144
            || mm2lmnTridroneJavelins() != 3
            || mm2lmnTridroneUltravisionYards() != 100
            || mm2lmnQuadroneXpValue() != 255
            || mm2lmnQuadroneXpLevel() != 4
            || mm2lmnQuadroneSensesPct() != 150
            || mm2lmnQuadroneInfravisionFeet() != 180
            || mm2lmnQuadroneUltravisionYards() != 200
            || mm2lmnPentadroneXpValue() != 504
            || mm2lmnPentadroneXpLevel() != 5
            || mm2lmnPentadroneGasStreamDiameterFeet() != 2
            || mm2lmnPentadroneGasStreamLengthFeet() != 5
            || mm2lmnPentadroneParalysisRounds() != 5
            || mm2lmnPentadroneGasCooldownTurns() != 5
            || mm2lmnPentadroneGasPerDay() != 5
            || mm2lmnPentadroneTempMaxF() != 210
            || mm2lmnPentadroneTempMinF() != -100
            || mm2lmnPentadroneRegimentalDozen() != 12
            || mm2lmnDecatonXpValue() != 3180
            || mm2lmnDecatonXpLevel() != 7
            || mm2lmnDecatonCount() != 100
            || mm2lmnDecatonWithHextons() != 36
            || mm2lmnDecatonClericLevel() != 10
            || mm2lmnDecatonCureRadiusFeet() != 144
            || mm2lmnDecatonCureDiseaseRadiusFeet() != 12
            || mm2lmnDecatonHealPerRound() != 10
            || mm2lmnNonatonXpValue() != 6034
            || mm2lmnNonatonXpLevel() != 8
            || mm2lmnNonatonCount() != 81
            || mm2lmnNonatonClericLevel() != 12
            || mm2lmnNonatonPentadroneLieutenants() != 12
            || mm2lmnNonatonPsionicScore() != 199
            || mm2lmnOctonXpValue() != 6114
            || mm2lmnOctonXpLevel() != 8
            || mm2lmnOctonCount() != 64
            || mm2lmnOctonClericLevel() != 14
            || mm2lmnOctonTelekinesisGold() != 3500
            || mm2lmnOctonStaffMonodrones() != 1728
            || mm2lmnOctonStaffDuodrones() != 256
            || mm2lmnOctonStaffTridrones() != 81
            || mm2lmnOctonStaffQuadrones() != 16
            || mm2lmnOctonStaffPentadrones() != 5
            || mm2lmnSeptonXpValue() != 9294
            || mm2lmnSeptonXpLevel() != 9
            || mm2lmnSeptonCount() != 49
            || mm2lmnSeptonClericLevel() != 16
            || mm2lmnSeptonMagicUserLevel() != 12
            || mm2lmnSeptonSenses() != 7
            || mm2lmnSeptonEspRangeFeet() != 30
            || mm2lmnSeptonsServingPrimus() != 8
            || mm2lmnHextonXpValue() != 9384
            || mm2lmnHextonXpLevel() != 9
            || mm2lmnHextonCount() != 36
            || mm2lmnHextonClericLevel() != 18
            || mm2lmnHextonGuardChancePct() != 75
            || mm2lmnHextonGuardMin() != 12
            || mm2lmnHextonGuardMax() != 48
            || mm2lmnQuintonXpValue() != 12290
            || mm2lmnQuintonXpLevel() != 10
            || mm2lmnQuintonCount() != 25
            || mm2lmnQuintonClericLevel() != 20
            || mm2lmnQuintonPentadroneStaff() != 25
            || mm2lmnQuintonBureausInPrimusTower() != 5
            || mm2lmnQuintonQuadroneStaff() != 64
            || mm2lmnQuintonTridroneStaff() != 81
            || mm2lmnQuartonXpValue() != 12390
            || mm2lmnQuartonXpLevel() != 10
            || mm2lmnQuartonCount() != 16
            || mm2lmnQuartonClericLevel() != 22
            || mm2lmnQuartonHeightFeet() != 12
            || mm2lmnQuartonGuardPentadrones() != 36
            || mm2lmnTertianXpValue() != 17100
            || mm2lmnTertianXpLevel() != 10
            || mm2lmnTertianCount() != 9
            || mm2lmnTertianClericLevel() != 24
            || mm2lmnTertianMagicUserLevel() != 20
            || mm2lmnTertianHeightFeet() != 12
            || mm2lmnSecundusXpValue() != 17225
            || mm2lmnSecundusXpLevel() != 10
            || mm2lmnSecundusCount() != 4
            || mm2lmnSecundusClericLevel() != 26
            || mm2lmnSecundusMagicUserLevel() != 22
            || mm2lmnSecundusMonkLevel() != 13
            || mm2lmnSecundusStunHitMargin() != 5
            || mm2lmnSecundusPsionicMin() != 300
            || mm2lmnSecundusPsionicMax() != 310
            || mm2lmnPrimusXpValue() != 32500
            || mm2lmnPrimusXpLevel() != 10
            || mm2lmnPrimusClericLevel() != 30
            || mm2lmnPrimusMagicUserLevel() != 25
            || mm2lmnPrimusPsionicScore() != 365
            || mm2lmnPrimusAvgHp() != 220
            || mm2lmnPrimusMrPct() != 100
            || mm2lmnRussetMoldSporeRadiusFeet() != 3
            || mm2lmnRussetMoldToxinDamageMin() != 5
            || mm2lmnRussetMoldToxinDamageMax() != 20
            || mm2lmnRussetMoldDeathTurnsMin() != 2
            || mm2lmnRussetMoldDeathTurnsMax() != 5
            || mm2lmnRussetMoldTransformationHoursMin() != 21
            || mm2lmnRussetMoldTransformationHoursMax() != 24
            || mm2lmnRussetMoldMistakenPct() != 70
            || mm2lmnRussetMoldMistakenBeyondFeet() != 30
            || mm2lmnRussetMoldAvgHp() != 16
            || mm2lmnMongrelmanCamouflageBasePct() != 80
            || mm2lmnMongrelmanCamouflageMaxPct() != 95
            || mm2lmnMongrelmanCamouflageTurns() != 1
            || mm2lmnMongrelmanPickpocketPct() != 70
            || mm2lmnMongrelmanLeaderHd() != 5
            || mm2lmnMongrelmanLeaderAc() != 4
            || mm2lmnMongrelmanBodyguards() != 5
            || mm2lmnMongrelmanBlowgunPct() != 5
            || mm2lmnMongrelmanLairPct() != 35
            || mm2lmnMoonDogXpValue() != 2528
            || mm2lmnMoonDogXpLevel() != 7
            || mm2lmnMoonDogBiteDamageMax() != 12
            || mm2lmnMoonDogBayingRangeInches() != 8
            || mm2lmnMoonDogHowlingDamageMin() != 5
            || mm2lmnMoonDogHowlingDamageMax() != 8
            || mm2lmnMoonDogHowlingRadiusInches() != 4
            || mm2lmnMoonDogHowlingPlanePct() != 5
            || mm2lmnMoonDogSpellLevel() != 12
            || mm2lmnMoonDogIllusionDetectPct() != 90
            || mm2lmnMoonDogInvisibilityDetectPct() != 80
            || mm2lmnMoonDogMagicDetectPct() != 70
            || mm2lmnMoonDogSnareDetectPct() != 100
            || mm2lmnMoonDogBrightLightAc() != 2
            || mm2lmnMoonDogTwilightAc() != 0
            || mm2lmnMoonDogShadowAc() != -2
            || mm2lmnMoonDogSurprisePct() != 50
            || mm2lmnMuckdwellerXpValue() != 11
            || mm2lmnMuckdwellerXpLevel() != 1
            || mm2lmnMuckdwellerJetFeet() != 10
            || mm2lmnMuckdwellerBlindAttackBonus() != 2
            || mm2lmnMuckdwellerDoublesTreasureAt() != 16
            || mm2lmnMuckdwellerAvgHp() != 4
            || mm2lmnMudManXpValue() != 42
            || mm2lmnMudManXpLevel() != 2
            || mm2lmnMudManBlobRangeInches() != 6
            || mm2lmnMudManBlobSlowdown() != 1
            || mm2lmnMudManBodySlowdown() != 4
            || mm2lmnMudManSuffocationDamageMax() != 8
            || mm2lmnMudManSuffocationRounds() != 5
            || mm2lmnMudManMovementRestorePer() != 5
            || mm2lmnMudManRiseRounds() != 1
            || mm2lmnMyconidCircleMembers() != 20
            || mm2lmnMyconidPerSize() != 4
            || mm2lmnMyconidKingHd() != 6
            || mm2lmnMyconidKingHeightFeet() != 12
            || mm2lmnMyconidHeightPerHd() != 2
            || mm2lmnMyconidMeldHours() != 8
            || mm2lmnMyconidDistressSpeedFeetPerRound() != 40
            || mm2lmnMyconidDistressMaxFeet() != 120
            || mm2lmnMyconidTouchDamageMax() != 4
            || mm2lmnMyconidLairPct() != 70
            || mm2lmnNereidXpValue() != 256
            || mm2lmnNereidXpLevel() != 4
            || mm2lmnNereidSpitRangeFeet() != 20
            || mm2lmnNereidBlindRoundsMin() != 2
            || mm2lmnNereidBlindRoundsMax() != 12
            || mm2lmnNereidWaterControlRadiusInches() != 3
            || mm2lmnNereidDeafenRadiusInches() != 6
            || mm2lmnNereidWateryShapeHd() != 4
            || mm2lmnNereidUndetectablePct() != 95
            || mm2lmnNereidPetPct() != 85
            || mm2lmnNarwhaleXpValue() != 352
            || mm2lmnNarwhaleXpLevel() != 4
            || mm2lmnNarwhaleHornFeetMin() != 6
            || mm2lmnNarwhaleHornFeetMax() != 12
            || mm2lmnNarwhaleBodyFeetMin() != 20
            || mm2lmnNarwhaleBodyFeetMax() != 40
            || mm2lmnNarwhaleGreatFormHd() != 6
            || !mm2lmnModronImmuneToMindMagic()
            || !mm2lmnModronImmuneToEnergyDrain()
            || !mm2lmnModronHierarchsNeverSurprised()
            || !mm2lmnModronPrimusAllNirvanaTelepathy()
            || !mm2lmnLandLampreyFireReleasesHold()
            || !mm2lmnLandLampreySnakeLikeMutant()
            || !mm2lmnLuckEaterGoldenFurredCat()
            || !mm2lmnLuckEaterSurprisesOnOneToFour()
            || !mm2lmnLycanthropeDarknessShapeChange()
            || !mm2lmnLycanthropeKnowsOwnTonguePlusCommon()
            || !mm2lmnFoxwomanInfectsOnlyInVixenForm()
            || !mm2lmnFoxwomanSilverFoxPassWithoutTrace()
            || !mm2lmnSeawolfGreaterIronWeaponsHarm()
            || !mm2lmnSeawolfLesserHitByNormalWeapons()
            || !mm2lmnSeawolfLesserWolfmanStatsInParens()
            || !mm2lmnWeresharkTropicalOnly()
            || !mm2lmnWeresharkChangesInDarkness()
            || !mm2lmnWeresharkGreatWhiteForm()
            || !mm2lmnMagmanPlusOneToHit()
            || !mm2lmnMagmanNonPlusTwoMelts()
            || !mm2lmnMagmanImmuneToFire()
            || !mm2lmnMagmanParaElementalHeatNative()
            || !mm2lmnMandragoraByLevelXp()
            || !mm2lmnMandragoraThroatHitOnTwenty()
            || !mm2lmnMandragoraHalfDamageFromFire()
            || !mm2lmnMandragoraSleepImmune()
            || !mm2lmnGiantMantisAvoidDetectionPct()
            || !mm2lmnMantrapAcidDamageEqualsAc()
            || !mm2lmnMantrapMetalSaveBonus()
            || !mm2lmnMantrapVictimHeldUntilPlantDies()
            || !mm2lmnMargoylePlusOneWeaponNeeded()
            || !mm2lmnMargoyleSpeaksGargoyleTongue()
            || !mm2lmnMaridMostPowerfulGenie()
            || !mm2lmnMaridWaterSpellsHarmless()
            || !mm2lmnMaridSteamHarmless()
            || !mm2lmnMaridSpeaksAllLanguagesByEsp()
            || !mm2lmnShadowMastiffPlaneOfShadowNative()
            || !mm2lmnShadowMastiffBayingCausesPanic()
            || !mm2lmnMihstuPlusTwoWeaponsNeeded()
            || !mm2lmnMihstuImmuneElectricalAndMissile()
            || !mm2lmnMihstuServesForMagicItems()
            || !mm2lmnMinerTrapperRelative()
            || !mm2lmnMinerWaitsForStillness()
            || !mm2lmnMinimalNeverFamiliars()
            || !mm2lmnMinimalCarnivoreSurpriseBonus()
            || !mm2lmnMinimalDifficultToSurprise()
            || !mm2lmnMonodroneOneTwelfthWinged()
            || !mm2lmnQuadroneTwoBows()
            || !mm2lmnQuadroneNeverSurprised()
            || !mm2lmnPentadroneGasLevitation()
            || !mm2lmnPentadronePlusOneWeaponNeeded()
            || !mm2lmnDecatonCannotTurnUndead()
            || !mm2lmnNonatonPowerWordStunPerDay()
            || !mm2lmnOctonImmuneToPsionics()
            || !mm2lmnHextonSixArms()
            || !mm2lmnQuintonLegendLore()
            || !mm2lmnTertianTailParalysisMinus4()
            || !mm2lmnSecundusQuiveringPalm()
            || !mm2lmnPrimusLightHandTeleportsArcadia()
            || !mm2lmnPrimusDarkHandSendsAcheron()
            || !mm2lmnPrimusAppearsAsNormalHuman()
            || !mm2lmnRussetMoldVegepygmyRises()
            || !mm2lmnRussetMoldWishAfterOneHour()
            || !mm2lmnRussetMoldNoTreasureLine()
            || !mm2lmnMongrelmanByLevelXp()
            || !mm2lmnMongrelmanCamouflageAndMimicry()
            || !mm2lmnMoonDogPlusTwoWeaponsNeeded()
            || !mm2lmnMoonDogNeverSurprised()
            || !mm2lmnMoonDogElysiumNative()
            || !mm2lmnMoonDogShadesPerDay()
            || !mm2lmnMuckdwellerServesKuoToans()
            || !mm2lmnMuckdwellerBlindedByJet()
            || !mm2lmnMudManDormantImmuneToWeapons()
            || !mm2lmnMudManTransmuteMudToRockKills()
            || !mm2lmnMudManMindSpellsImmune()
            || !mm2lmnMyconidByLevelXp()
            || !mm2lmnMyconidFearsSunlight()
            || !mm2lmnMyconidAnimatorZombiesNotUndead()
            || !mm2lmnNereidShawlHoldsSoul()
            || !mm2lmnNereidForcedKissCanDrown()
            || !mm2lmnNarwhaleDolphinPets()
            || !mm2lmnNarwhaleUnicornOfTheOcean()
        )
            ++bad;
        // THE LMN-GRID: the 38-row LmStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the thirty-eight letters-LMN stat blocks,
        // in print order - the land lamprey through the narwhale)
        int CLmStats[38][10] = {
            {7,1,2,5,1,36,2,0,12,0},
            {7,4,0,14,1,125,4,0,15,0},
            {2,8,1,29,1,1700,12,25,24,0},
            {5,9,2,33,2,900,12,0,9,0},
            {6,2,2,9,3,50,3,0,30,0},
            {0,10,3,38,1,1500,14,20,12,0},
            {6,2,0,7,1,97,2,0,9,0},
            {5,2,2,9,2,0,0,45,12,20},
            {3,10,0,35,1,1350,14,0,6,0},
            {6,4,0,14,5,275,6,100,0,0},
            {2,6,0,21,4,350,6,30,6,0},
            {0,13,0,45,1,5000,0,0,9,25},
            {6,4,0,14,1,185,4,20,18,0},
            {-2,8,2,30,4,1700,12,10,6,10},
            {4,10,0,35,1,1000,14,40,3,0},
            {7,1,1,4,1,28,2,0,6,0},
            {6,2,2,9,2,50,3,0,9,0},
            {5,3,3,13,3,85,4,0,12,0},
            {4,4,4,18,4,165,5,0,15,0},
            {3,5,5,22,5,350,7,0,18,0},
            {2,10,10,45,10,2550,14,0,15,10},
            {0,11,11,49,9,5250,16,0,18,20},
            {1,12,12,54,8,5250,16,0,9,30},
            {-1,13,13,58,7,8250,18,0,9,40},
            {-2,14,14,63,6,8250,18,0,12,50},
            {-3,15,15,67,5,10950,20,0,6,60},
            {-4,16,16,72,4,10950,20,0,12,70},
            {-5,17,17,76,3,15200,25,0,12,80},
            {-6,18,18,81,2,15200,25,0,18,90},
            {-10,0,0,220,1,32500,0,0,24,100},
            {9,0,0,16,1,0,0,0,0,0},
            {5,1,0,3,1,0,0,35,9,0},
            {2,8,16,44,1,2000,12,0,30,25},
            {6,0,0,4,1,7,1,40,3,0},
            {10,2,0,7,1,28,2,100,3,0},
            {10,1,0,3,1,0,0,70,9,0},
            {10,4,0,14,1,200,4,100,12,50},
            {6,6,6,27,1,190,6,0,21,0},
            };
        for (int b = 0;
             b < mm2lmnLmStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2lmnLmStatAc(b);
            vals[1] = mm2lmnLmStatHd(b);
            vals[2] = mm2lmnLmStatHdBonus(b);
            vals[3] = mm2lmnLmStatAvgHp(b);
            vals[4] = mm2lmnLmStatAttacks(b);
            vals[5] = mm2lmnLmStatXp(b);
            vals[6] = mm2lmnLmStatXpHp(b);
            vals[7] = mm2lmnLmStatLairPct(b);
            vals[8] = mm2lmnLmStatMove(b);
            vals[9] = mm2lmnLmStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CLmStats[b][c])
                    ++bad;
            }
        }
        // THE MINIMAL TABLE: the 29-row MinimalStats table (the printed
        // minimal-animal rows of p. 85 - the attack count, the xp base and
        // the xp per hit point of every minimal from the gorilla to the wolf)
        int CMinimalStats[29][3] = {
            {3,10,1},
            {3,30,2},
            {1,5,1},
            {1,7,1},
            {3,12,1},
            {3,28,2},
            {3,50,3},
            {1,10,1},
            {2,10,1},
            {2,20,2},
            {2,10,1},
            {1,10,1},
            {1,7,1},
            {1,5,1},
            {5,90,3},
            {5,125,3},
            {1,20,2},
            {1,5,1},
            {1,10,1},
            {3,45,2},
            {3,45,2},
            {3,65,2},
            {3,25,2},
            {1,5,1},
            {5,125,4},
            {1,90,3},
            {2,7,1},
            {3,50,3},
            {1,5,1},
            };
        for (int b = 0;
             b < mm2lmnMinimalStatRows();
             ++b) {
            int vals[3];
            vals[0] = mm2lmnMinimalStatAttacks(b);
            vals[1] = mm2lmnMinimalStatXpBase(b);
            vals[2] = mm2lmnMinimalStatXpPerHp(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CMinimalStats[b][c])
                    ++bad;
            }
        }
        // THE TELEPATHY LADDER: the 9-row TelepathyMiles table (the hierarch
        // telepathy ranges of p. 86 - the decaton 44 miles through the
        // secundus 420, the strictly increasing ladder; the Primus "All
        // Nirvana" row rides as a bool, not a cell)
        int CTelepathyMiles[9][2] = {
            {1,44},
            {2,63},
            {3,80},
            {4,190},
            {5,216},
            {6,238},
            {7,384},
            {8,405},
            {9,420},
            };
        for (int b = 0;
             b < mm2lmnTelepathyMilesRows();
             ++b) {
            int vals[2];
            vals[0] = mm2lmnTelepathyRank(b);
            vals[1] = mm2lmnTelepathyMiles(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CTelepathyMiles[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the three gap boxes
        // flip (the census walk)
    if (mm2lmnRegistryAfter() - mm2lmnRegistryBefore() != mm2lmnDefCount()
            || mm2lmnDefCount() != 38
            || mm2lmnEntryCount() != 22
            || mm2lmnStatBlockHeadings() != 38
            || mm2lmnDoctrineHeads() != 2
            || mm2lmnLetterLHeadings() != 3
            || mm2lmnLetterMHeadings() != 17
            || mm2lmnLetterNHeadings() != 2
            || mm2lmnLmStatRows() != 38
            || mm2lmnGapClosed() != 19
            || mm2lmnGapOpen() != 18
            || mm2lmnPriorOwnedEntries() != 0
        )
            ++bad;
        // the pin-time entry census composition (the lycanthrope and modron
        // families, the minimal table, the by_level defs)
    if (mm2lmnLycanthropeStatBlocks() != 4
            || mm2lmnModronBlocks() != 15
            || mm2lmnByLevelDefs() != 3
            || mm2lmnMinimalStatRows() != 29
            || mm2lmnTelepathyMilesRows() != 9
            || mm2lmnCensusBefore() != 730
            || mm2lmnCensusAfter() != 731
        )
            ++bad;
        // the land lamprey and luck eater grid rows (the print opens p. 80)
    if (mm2lmnLmStatAc(0) != 7
            || mm2lmnLmStatHd(0) != 1
            || mm2lmnLmStatHdBonus(0) != 2
            || mm2lmnLmStatAvgHp(0) != 5
            || mm2lmnLmStatAttacks(0) != 1
            || mm2lmnLmStatXp(0) != 36
            || mm2lmnLmStatXpHp(0) != 2
            || mm2lmnLmStatLairPct(0) != 0
            || mm2lmnLmStatMove(0) != 12
            || mm2lmnLmStatMr(0) != 0
        )
            ++bad;
        // the foxwoman composite armor class row (the "2 or 4 or 6" head
        // read, the 24 move, the 25% lair)
    if (mm2lmnLmStatAc(2) != 2
            || mm2lmnLmStatHd(2) != 8
            || mm2lmnLmStatHdBonus(2) != 1
            || mm2lmnLmStatAvgHp(2) != 29
            || mm2lmnLmStatAttacks(2) != 1
            || mm2lmnLmStatXp(2) != 1700
            || mm2lmnLmStatXpHp(2) != 12
            || mm2lmnLmStatLairPct(2) != 25
            || mm2lmnLmStatMove(2) != 24
            || mm2lmnLmStatMr(2) != 0
        )
            ++bad;
        // the seawolf composite rows (the greater "1 or 2" max read 2, the
        // lesser "1 (3)" max read 3 and "6 (7)" head read 6)
    if (mm2lmnLmStatAc(3) != 5
            || mm2lmnLmStatHd(3) != 9
            || mm2lmnLmStatHdBonus(3) != 2
            || mm2lmnLmStatAvgHp(3) != 33
            || mm2lmnLmStatAttacks(3) != 2
            || mm2lmnLmStatXp(3) != 900
            || mm2lmnLmStatXpHp(3) != 12
            || mm2lmnLmStatLairPct(3) != 0
            || mm2lmnLmStatMove(3) != 9
            || mm2lmnLmStatMr(3) != 0
            || mm2lmnLmStatAc(4) != 6
            || mm2lmnLmStatHd(4) != 2
            || mm2lmnLmStatHdBonus(4) != 2
            || mm2lmnLmStatAvgHp(4) != 9
            || mm2lmnLmStatAttacks(4) != 3
            || mm2lmnLmStatXp(4) != 50
            || mm2lmnLmStatXpHp(4) != 3
            || mm2lmnLmStatLairPct(4) != 0
            || mm2lmnLmStatMove(4) != 30
            || mm2lmnLmStatMr(4) != 0
        )
            ++bad;
        // the marid flat-xp row (the VIII/5000 cell with no per-hp adder)
    if (mm2lmnLmStatAc(11) != 0
            || mm2lmnLmStatHd(11) != 13
            || mm2lmnLmStatHdBonus(11) != 0
            || mm2lmnLmStatAvgHp(11) != 45
            || mm2lmnLmStatAttacks(11) != 1
            || mm2lmnLmStatXp(11) != 5000
            || mm2lmnLmStatXpHp(11) != 0
            || mm2lmnLmStatLairPct(11) != 0
            || mm2lmnLmStatMove(11) != 9
            || mm2lmnLmStatMr(11) != 25
        )
            ++bad;
        // the moon dog row (the VII/2000 + 12/hp settled read, the 8+16 dice,
        // the 2 or 0 or -2 head read)
    if (mm2lmnLmStatAc(32) != 2
            || mm2lmnLmStatHd(32) != 8
            || mm2lmnLmStatHdBonus(32) != 16
            || mm2lmnLmStatAvgHp(32) != 44
            || mm2lmnLmStatAttacks(32) != 1
            || mm2lmnLmStatXp(32) != 2000
            || mm2lmnLmStatXpHp(32) != 12
            || mm2lmnLmStatLairPct(32) != 0
            || mm2lmnLmStatMove(32) != 30
            || mm2lmnLmStatMr(32) != 25
        )
            ++bad;
        // the primus flat-hp row (the 220 hp cell, the X/32,500 xp, the 100%
        // magic resistance)
    if (mm2lmnLmStatAc(29) != -10
            || mm2lmnLmStatHd(29) != 0
            || mm2lmnLmStatHdBonus(29) != 0
            || mm2lmnLmStatAvgHp(29) != 220
            || mm2lmnLmStatAttacks(29) != 1
            || mm2lmnLmStatXp(29) != 32500
            || mm2lmnLmStatXpHp(29) != 0
            || mm2lmnLmStatLairPct(29) != 0
            || mm2lmnLmStatMove(29) != 24
            || mm2lmnLmStatMr(29) != 100
        )
            ++bad;
        // the narwhale closing row (the //21" move read, the 6+6 great form)
    if (mm2lmnLmStatAc(37) != 6
            || mm2lmnLmStatHd(37) != 6
            || mm2lmnLmStatHdBonus(37) != 6
            || mm2lmnLmStatAvgHp(37) != 27
            || mm2lmnLmStatAttacks(37) != 1
            || mm2lmnLmStatXp(37) != 190
            || mm2lmnLmStatXpHp(37) != 6
            || mm2lmnLmStatLairPct(37) != 0
            || mm2lmnLmStatMove(37) != 21
            || mm2lmnLmStatMr(37) != 0
        )
            ++bad;
        // the modron base ladder (the monodrone through the pentadrone: the
        // armor class 7 6 5 4 3 steps, the attack 1 2 3 4 5 steps, the xp 28
        // 50 85 165 350 cells)
    if (mm2lmnLmStatAc(15) != 7
            || mm2lmnLmStatHd(15) != 1
            || mm2lmnLmStatHdBonus(15) != 1
            || mm2lmnLmStatAvgHp(15) != 4
            || mm2lmnLmStatAttacks(15) != 1
            || mm2lmnLmStatXp(15) != 28
            || mm2lmnLmStatXpHp(15) != 2
            || mm2lmnLmStatLairPct(15) != 0
            || mm2lmnLmStatMove(15) != 6
            || mm2lmnLmStatMr(15) != 0
            || mm2lmnLmStatAc(16) != 6
            || mm2lmnLmStatHd(16) != 2
            || mm2lmnLmStatHdBonus(16) != 2
            || mm2lmnLmStatAvgHp(16) != 9
            || mm2lmnLmStatAttacks(16) != 2
            || mm2lmnLmStatXp(16) != 50
            || mm2lmnLmStatXpHp(16) != 3
            || mm2lmnLmStatLairPct(16) != 0
            || mm2lmnLmStatMove(16) != 9
            || mm2lmnLmStatMr(16) != 0
            || mm2lmnLmStatAc(17) != 5
            || mm2lmnLmStatHd(17) != 3
            || mm2lmnLmStatHdBonus(17) != 3
            || mm2lmnLmStatAvgHp(17) != 13
            || mm2lmnLmStatAttacks(17) != 3
            || mm2lmnLmStatXp(17) != 85
            || mm2lmnLmStatXpHp(17) != 4
            || mm2lmnLmStatLairPct(17) != 0
            || mm2lmnLmStatMove(17) != 12
            || mm2lmnLmStatMr(17) != 0
            || mm2lmnLmStatAc(18) != 4
            || mm2lmnLmStatHd(18) != 4
            || mm2lmnLmStatHdBonus(18) != 4
            || mm2lmnLmStatAvgHp(18) != 18
            || mm2lmnLmStatAttacks(18) != 4
            || mm2lmnLmStatXp(18) != 165
            || mm2lmnLmStatXpHp(18) != 5
            || mm2lmnLmStatLairPct(18) != 0
            || mm2lmnLmStatMove(18) != 15
            || mm2lmnLmStatMr(18) != 0
            || mm2lmnLmStatAc(19) != 3
            || mm2lmnLmStatHd(19) != 5
            || mm2lmnLmStatHdBonus(19) != 5
            || mm2lmnLmStatAvgHp(19) != 22
            || mm2lmnLmStatAttacks(19) != 5
            || mm2lmnLmStatXp(19) != 350
            || mm2lmnLmStatXpHp(19) != 7
            || mm2lmnLmStatLairPct(19) != 0
            || mm2lmnLmStatMove(19) != 18
            || mm2lmnLmStatMr(19) != 0
        )
            ++bad;
        // the modron hierarch ladder (the decaton through the secundus: the
        // armor class 2 0 1 -1 -2 -3 -4 -5 -6 cells and the magic resistance
        // 10 through 90 in +10 steps)
    if (mm2lmnLmStatAc(20) != 2
            || mm2lmnLmStatHd(20) != 10
            || mm2lmnLmStatHdBonus(20) != 10
            || mm2lmnLmStatAvgHp(20) != 45
            || mm2lmnLmStatAttacks(20) != 10
            || mm2lmnLmStatXp(20) != 2550
            || mm2lmnLmStatXpHp(20) != 14
            || mm2lmnLmStatLairPct(20) != 0
            || mm2lmnLmStatMove(20) != 15
            || mm2lmnLmStatMr(20) != 10
            || mm2lmnLmStatAc(21) != 0
            || mm2lmnLmStatHd(21) != 11
            || mm2lmnLmStatHdBonus(21) != 11
            || mm2lmnLmStatAvgHp(21) != 49
            || mm2lmnLmStatAttacks(21) != 9
            || mm2lmnLmStatXp(21) != 5250
            || mm2lmnLmStatXpHp(21) != 16
            || mm2lmnLmStatLairPct(21) != 0
            || mm2lmnLmStatMove(21) != 18
            || mm2lmnLmStatMr(21) != 20
            || mm2lmnLmStatAc(22) != 1
            || mm2lmnLmStatHd(22) != 12
            || mm2lmnLmStatHdBonus(22) != 12
            || mm2lmnLmStatAvgHp(22) != 54
            || mm2lmnLmStatAttacks(22) != 8
            || mm2lmnLmStatXp(22) != 5250
            || mm2lmnLmStatXpHp(22) != 16
            || mm2lmnLmStatLairPct(22) != 0
            || mm2lmnLmStatMove(22) != 9
            || mm2lmnLmStatMr(22) != 30
            || mm2lmnLmStatAc(23) != -1
            || mm2lmnLmStatHd(23) != 13
            || mm2lmnLmStatHdBonus(23) != 13
            || mm2lmnLmStatAvgHp(23) != 58
            || mm2lmnLmStatAttacks(23) != 7
            || mm2lmnLmStatXp(23) != 8250
            || mm2lmnLmStatXpHp(23) != 18
            || mm2lmnLmStatLairPct(23) != 0
            || mm2lmnLmStatMove(23) != 9
            || mm2lmnLmStatMr(23) != 40
            || mm2lmnLmStatAc(24) != -2
            || mm2lmnLmStatHd(24) != 14
            || mm2lmnLmStatHdBonus(24) != 14
            || mm2lmnLmStatAvgHp(24) != 63
            || mm2lmnLmStatAttacks(24) != 6
            || mm2lmnLmStatXp(24) != 8250
            || mm2lmnLmStatXpHp(24) != 18
            || mm2lmnLmStatLairPct(24) != 0
            || mm2lmnLmStatMove(24) != 12
            || mm2lmnLmStatMr(24) != 50
            || mm2lmnLmStatAc(25) != -3
            || mm2lmnLmStatHd(25) != 15
            || mm2lmnLmStatHdBonus(25) != 15
            || mm2lmnLmStatAvgHp(25) != 67
            || mm2lmnLmStatAttacks(25) != 5
            || mm2lmnLmStatXp(25) != 10950
            || mm2lmnLmStatXpHp(25) != 20
            || mm2lmnLmStatLairPct(25) != 0
            || mm2lmnLmStatMove(25) != 6
            || mm2lmnLmStatMr(25) != 60
            || mm2lmnLmStatAc(26) != -4
            || mm2lmnLmStatHd(26) != 16
            || mm2lmnLmStatHdBonus(26) != 16
            || mm2lmnLmStatAvgHp(26) != 72
            || mm2lmnLmStatAttacks(26) != 4
            || mm2lmnLmStatXp(26) != 10950
            || mm2lmnLmStatXpHp(26) != 20
            || mm2lmnLmStatLairPct(26) != 0
            || mm2lmnLmStatMove(26) != 12
            || mm2lmnLmStatMr(26) != 70
            || mm2lmnLmStatAc(27) != -5
            || mm2lmnLmStatHd(27) != 17
            || mm2lmnLmStatHdBonus(27) != 17
            || mm2lmnLmStatAvgHp(27) != 76
            || mm2lmnLmStatAttacks(27) != 3
            || mm2lmnLmStatXp(27) != 15200
            || mm2lmnLmStatXpHp(27) != 25
            || mm2lmnLmStatLairPct(27) != 0
            || mm2lmnLmStatMove(27) != 12
            || mm2lmnLmStatMr(27) != 80
            || mm2lmnLmStatAc(28) != -6
            || mm2lmnLmStatHd(28) != 18
            || mm2lmnLmStatHdBonus(28) != 18
            || mm2lmnLmStatAvgHp(28) != 81
            || mm2lmnLmStatAttacks(28) != 2
            || mm2lmnLmStatXp(28) != 15200
            || mm2lmnLmStatXpHp(28) != 25
            || mm2lmnLmStatLairPct(28) != 0
            || mm2lmnLmStatMove(28) != 18
            || mm2lmnLmStatMr(28) != 90
        )
            ++bad;
        // the hierarch telepathy ladder is strictly increasing in rank (the
        // decaton 44 through the secundus 420 miles)
    if (mm2lmnTelepathyMiles(0) >= mm2lmnTelepathyMiles(1)
            || mm2lmnTelepathyMiles(1) >= mm2lmnTelepathyMiles(2)
            || mm2lmnTelepathyMiles(2) >= mm2lmnTelepathyMiles(3)
            || mm2lmnTelepathyMiles(3) >= mm2lmnTelepathyMiles(4)
            || mm2lmnTelepathyMiles(4) >= mm2lmnTelepathyMiles(5)
            || mm2lmnTelepathyMiles(5) >= mm2lmnTelepathyMiles(6)
            || mm2lmnTelepathyMiles(6) >= mm2lmnTelepathyMiles(7)
            || mm2lmnTelepathyMiles(7) >= mm2lmnTelepathyMiles(8)
            || mm2lmnTelepathyMiles(0) != 44
            || mm2lmnTelepathyMiles(8) != 420
            || mm2lmnTelepathyRank(0) != 1
            || mm2lmnTelepathyRank(8) != 9
        )
            ++bad;
        // the minimal table samples (the gorilla row, the lion row - the
        // print "13" the 1+3 misprint - and the mammoth row)
    if (mm2lmnMinimalStatAttacks(0) != 3
            || mm2lmnMinimalStatXpBase(0) != 10
            || mm2lmnMinimalStatXpPerHp(0) != 1
            || mm2lmnMinimalStatAttacks(21) != 3
            || mm2lmnMinimalStatXpBase(21) != 65
            || mm2lmnMinimalStatXpPerHp(21) != 2
            || mm2lmnMinimalStatAttacks(24) != 5
            || mm2lmnMinimalStatXpBase(24) != 125
            || mm2lmnMinimalStatXpPerHp(24) != 4
        )
            ++bad;
        // the modron doctrine census (the wheel of 64 sectors, the 36 armies,
        // the brigade of 3142, the 9-day reformation, the hierarch counts 100
        // 81 64 49 36 25 16 9 4)
    if (mm2lmnNirvanaSectors() != 64
            || mm2lmnNirvanaArmies() != 36
            || mm2lmnNirvanaBrigadeTotal() != 3142
            || mm2lmnModronReformationDays() != 9
            || mm2lmnDecatonCount() != 100
            || mm2lmnNonatonCount() != 81
            || mm2lmnOctonCount() != 64
            || mm2lmnSeptonCount() != 49
            || mm2lmnHextonCount() != 36
            || mm2lmnQuintonCount() != 25
            || mm2lmnQuartonCount() != 16
            || mm2lmnTertianCount() != 9
            || mm2lmnSecundusCount() != 4
            || mm2lmnNirvanaBrigadeOfficers() + mm2lmnNirvanaBrigadeNcos() +
            mm2lmnNirvanaBrigadeMessengers() +
            mm2lmnNirvanaBrigadeLineTroops() != mm2lmnNirvanaBrigadeTotal()
        )
            ++bad;
        // the lycanthrope doctrine cells (the 90% full moon, the 25%
        // belladonna, the 12th-level patriarch, the 7-14 day onset)
    if (mm2lmnLycanthropeFullMoonPct() != 90
            || mm2lmnLycanthropeBelladonnaCurePct() != 25
            || mm2lmnLycanthropeCurePatriarchLevel() != 12
            || mm2lmnLycanthropeOnsetDaysMin() != 7
            || mm2lmnLycanthropeOnsetDaysMax() != 14
        )
            ++bad;
        // the by_level def xp pins (the mandragora, the mongrelman and the
        // myconid ride the by_level source - no xpValue formula)
    if (mm2lmnMandragoraByLevelXp() != mm2lmnMongrelmanByLevelXp()
            || mm2lmnMyconidByLevelXp() != true
            || mm2lmnByLevelDefs() != 3
        )
            ++bad;
        printf("R808 MM2 letters LMN walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
