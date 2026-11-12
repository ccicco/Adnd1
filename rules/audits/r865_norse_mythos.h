    // ---- R865 Norse mythos audit ----
    // THE NORSE MYTHOS - the D&DG walk round seventeen, print pp. 113-124:
    // thirty-five stat-block rows - the eleven greater gods (Odin, Balder,
    // Forseti, Frey, Freya, Frigga, Heimdall, Hel, Loki, Thor, Tyr), the ten
    // lesser (Aegir, Bragi, Idun, Magni, Modi, Sif, Surtur, Thrym, Uller,
    // Vidar), the four no-rank class-grid rows (Fjalar, Skirnir, the Norns,
    // the Valkyries) and the eleven MM-style companion and monster blocks
    // (Hugin and Munin, Sleipner, Freke and Gere, the Fenris Wolf,
    // Fossergrim, Blodug-Hofi, Gullin-Bursti, Garm, Jormungandr, the Thor
    // goats) - plus the Ragnarok and sacrifice doctrine of the intro (the
    // Aesir and the Vanir, the last battle, the hanged-and-speared sacrifice
    // on the oak pyre, the lunar month worship, the blasphemy forgiven by
    // battle) and the round data file doc/data/ddg_norse_crossrefs.txt;
    // prefix nrs (full-repo scan clean). THE HEADLINE ADJUDICATIONS: the THOR
    // BARE 4 - the tsv armor class line shows no minus glyph, the L&L voice
    // reads minus 4, pinned as printed with the eyeball flag; the Hel +38
    // damage garble adjudicated to 8 (the strength arithmetic and the L&L
    // voice agree, the print token at conf 28); the HALF-FOOT SIZES: Odin,
    // Hel and Tyr the 6 and a half foot 78, the Valkyries the 5 and a half
    // foot 66 (the half glyph garbles to )4 and % in the tesseract pass); the
    // Hugin odd prints: the 1 over 48 move cell and the merged V1815 XP glyph
    // = VI/815 (the MM level VI base value); the Frey II pipe (the width 15
    // two pipe signature); the Thrym 300 hit points from the L&L voice (the
    // print cell occluded by the plate illustration on the pdf page); the
    // dual prints pinned as printed: Loki 12/12 and the goats 24/24 dual-same
    // moves, the Modi 2-or-4 and 25-or-50 berserk cells (the walk first
    // non-dice damage print), the Thor 2(3) glove cell, the Hel Infinite move
    // (the R863 Death minus 1 sentinel precedent), the Jormungandr
    // 25,000-miles size (the 0 sentinel with the const) and the slashless X
    // 55,000 XP print. The psionic pipes: I Odin, Hel, the Norns, Tyr, Uller;
    // II Forseti, Frey, Frigga; III Heimdall; IV Loki, Modi; V Aegir, Bragi,
    // Idun; VI Balder, Freya, Magni, Sif, Skirnir, Thor, Vidar. The L&L
    // divergences noted: Aegir minus 3, Freya minus 4 (both pinned the print
    // way). ZERO registry defs touched - the floor holds at 995.
    {
        using namespace rules;
        int bad = 0;
    if (nrsRound() != 865
            || nrsPrintStart() != 113
            || nrsPrintEnd() != 124
            || nrsBeingCount() != 35
            || nrsTableCount() != 4
            || nrsChainCount() != 0
            || nrsRegistryFloor() != 995
            || nrsCensusAfter() != 788
            || nrsCbtRows() != 35
            || nrsClsRows() != 35
            || nrsAbiRows() != 35
            || nrsRosRows() != 35
            || nrsGreaterCount() != 11
            || nrsLesserCount() != 10
            || nrsNoRankCount() != 4
            || nrsMonsterCount() != 11
            || nrsGladsheimCount() != 18
            || nrsElysiumCount() != 1
            || nrsHadesCount() != 1
            || nrsPandemoniumCount() != 1
            || nrsConcordantCount() != 1
            || nrsNoPlaneCount() != 13
            || nrsDualPlaneCount() != 1
            || nrsPlaneCodeCount() != 5
            || nrsPsiRowCount() != 21
            || nrsPsiNilCount() != 14
            || nrsPsiOneCount() != 5
            || nrsPsiTwoCount() != 3
            || nrsPsiThreeCount() != 1
            || nrsPsiFourCount() != 2
            || nrsPsiFiveCount() != 3
            || nrsPsiSixCount() != 7
            || nrsDmgFixedCount() != 27
            || nrsInEachCount() != 11
            || nrsDualMoveCount() != 10
            || nrsDualSameMoveCount() != 2
            || nrsInfiniteMoveCount() != 1
            || nrsHalfFootCount() != 4
            || nrsValhallaCount() != 1
            || nrsJotunheimCount() != 2
            || nrsCompanionCount() != 6
            || nrsEinheriarMinLevel() != 4
            || nrsDwarfRaces() != 2
            || nrsFriggaMaidenNames() != 10
            || nrsOdinTelepathyMiles() != 300
            || nrsOdinBerserkYards() != 30
            || nrsOdinAllyYards() != 20
            || nrsOdinAllyLevels() != 4
            || nrsOdinGazeSaveMod() != -4
            || nrsOdinSpearPlus() != 5
            || nrsOdinFearYards() != 20
            || nrsOdinTouchHpCost() != 1
            || nrsOdinSameAlignHpPct() != 50
            || nrsOdinBowPlus() != 3
            || nrsOdinBowArrows() != 10
            || nrsOdinWandPowers() != 5
            || nrsOdinWandElementalLow() != 1
            || nrsOdinWandElementalHigh() != 4
            || nrsOdinWandSpells() != 12
            || nrsOdinWandDrainLevels() != 6
            || nrsOdinWandDrainHp() != 100
            || nrsOdinArmorPlus() != 5
            || nrsOdinDraupnirGp() != 30000
            || nrsOdinHealSleepLow() != 1
            || nrsOdinHealSleepHigh() != 10
            || nrsHuginCount() != 2
            || nrsHuginHpEach() != 30
            || nrsHuginXpRoman() != 6
            || nrsHuginXpBase() != 815
            || nrsHuginAttackHd() != 7
            || nrsHuginDmgLow() != 1
            || nrsHuginDmgHigh() != 8
            || nrsSleipnerXpRoman() != 10
            || nrsSleipnerXpBase() != 20600
            || nrsSleipnerFightHd() != 16
            || nrsSleipnerKickLow() != 2
            || nrsSleipnerKickHigh() != 20
            || nrsSleipnerBiteLow() != 1
            || nrsSleipnerBiteHigh() != 10
            || nrsFrekeHpEach() != 75
            || nrsFrekeXpRoman() != 9
            || nrsFrekeXpBase() != 8875
            || nrsFrekeFightHd() != 16
            || nrsFrekeDmgLow() != 2
            || nrsFrekeDmgHigh() != 20
            || nrsAegirDmgLow() != 4
            || nrsAegirDmgHigh() != 40
            || nrsAegirDmgBonus() != 11
            || nrsAegirSeaFormFeet() != 60
            || nrsBalderDmgLow() != 3
            || nrsBalderDmgHigh() != 30
            || nrsBalderDmgBonus() != 10
            || nrsBalderSwordPlus() != 2
            || nrsBalderCharismaGift() != 2
            || nrsBalderServePct() != 1
            || nrsBalderMinCha() != 15
            || nrsBragiDmgLow() != 2
            || nrsBragiDmgHigh() != 20
            || nrsBragiDmgBonus() != 11
            || nrsBragiSongYards() != 30
            || nrsBragiSongHours() != 5
            || nrsBragiHarpDays() != 7
            || nrsBragiLegendPct() != 5
            || nrsBragiCrowdMin() != 50
            || nrsFenrisDmgLow() != 9
            || nrsFenrisDmgHigh() != 90
            || nrsFenrisXpRoman() != 10
            || nrsFenrisXpBase() != 33200
            || nrsFenrisWeaponPlus() != 4
            || nrsFjalarDmgLow() != 2
            || nrsFjalarDmgHigh() != 20
            || nrsFjalarGauntletPlus() != 3
            || nrsForsetiDmgLow() != 1
            || nrsForsetiDmgHigh() != 10
            || nrsForsetiDmgBonus() != 12
            || nrsForsetiLieDays() != 7
            || nrsFossergrimHd() != 5
            || nrsFossergrimXpRoman() != 5
            || nrsFossergrimXpBase() != 320
            || nrsFossergrimXpPerHp() != 5
            || nrsFossergrimMileLimit() != 1
            || nrsFossergrimRegen() != 5
            || nrsFreyDmgLow() != 2
            || nrsFreyDmgHigh() != 20
            || nrsFreyDmgBonus() != 12
            || nrsFreySwordPlus() != 4
            || nrsFreyFireGiantLow() != 10
            || nrsFreyFireGiantHigh() != 100
            || nrsFreyOtherGiantLow() != 5
            || nrsFreyOtherGiantHigh() != 50
            || nrsFreyShipRate() != 60
            || nrsBlodugBiteLow() != 1
            || nrsBlodugBiteHigh() != 6
            || nrsBlodugKickLow() != 1
            || nrsBlodugKickHigh() != 10
            || nrsBlodugFireSavePlus() != 4
            || nrsBlodugFireDieSave() != 1
            || nrsBlodugUndeadYards() != 200
            || nrsBlodugFightHd() != 11
            || nrsBlodugXpRoman() != 8
            || nrsBlodugXpBase() != 4500
            || nrsGullinDmgLow() != 2
            || nrsGullinDmgHigh() != 20
            || nrsGullinRegen() != 1
            || nrsGullinXpRoman() != 10
            || nrsGullinXpBase() != 22300
            || nrsGullinFightHd() != 16
            || nrsSkirnirMailPlus() != 4
            || nrsSkirnirSwordPlus() != 3
            || nrsFreyaFrostPlus() != 3
            || nrsFreyaFireSpellLevel() != 30
            || nrsFreyaCatAc() != 5
            || nrsFreyaCatHd() != 5
            || nrsFreyaCatHp() != 30
            || nrsFreyaCatPawLow() != 1
            || nrsFreyaCatPawHigh() != 8
            || nrsFreyaCatRearLow() != 1
            || nrsFreyaCatRearHigh() != 12
            || nrsFreyaChariotMove() != 18
            || nrsFreyaNecklaceGp() != 1000000
            || nrsFreyaCloakRate() != 48
            || nrsGarmDmgLow() != 6
            || nrsGarmDmgHigh() != 60
            || nrsGarmXpRoman() != 10
            || nrsGarmXpBase() != 26200
            || nrsGarmFightHd() != 16
            || nrsGarmWolfPack() != 20
            || nrsGarmFleeLevel() != 6
            || nrsGarmFearSaveMod() != -4
            || nrsHeimdallDmgLow() != 3
            || nrsHeimdallDmgHigh() != 30
            || nrsHeimdallDmgBonus() != 14
            || nrsHeimdallArmorPlus() != 3
            || nrsHelDmgLow() != 5
            || nrsHelDmgHigh() != 50
            || nrsHelDmgBonus() != 8
            || nrsHelSwordPlus() != 3
            || nrsHelWitherYards() != 90
            || nrsHelWitherHp() != 20
            || nrsHelPlagueHp() != 5
            || nrsJormHeadHp() != 300
            || nrsJormMiles() != 25000
            || nrsJormBiteLow() != 5
            || nrsJormBiteHigh() != 50
            || nrsJormConstrictionLow() != 10
            || nrsJormConstrictionHigh() != 100
            || nrsJormPoisonSaveMod() != -5
            || nrsJormDeathRounds() != 2
            || nrsJormVenomCloudFeet() != 50
            || nrsJormXpRoman() != 10
            || nrsJormXpBase() != 55000
            || nrsJormFightHd() != 16
            || nrsIdunAppleYears() != 10
            || nrsIdunAppleHp() != 50
            || nrsLokiIllusionLevel() != 20
            || nrsMagniDmgLow() != 8
            || nrsMagniDmgHigh() != 80
            || nrsMagniHammerPlus() != 3
            || nrsMagniCatchPct() != 90
            || nrsModiVorpalDmg() != 25
            || nrsModiBerserkDmg() != 50
            || nrsModiAuraYards() != 90
            || nrsModiAuraBonus() != 4
            || nrsNornsCount() != 3
            || nrsNornsDmgLow() != 1
            || nrsNornsDmgHigh() != 10
            || nrsNornsGiftPct() != 1
            || nrsSifDmgLow() != 3
            || nrsSifDmgHigh() != 30
            || nrsSifDmgBonus() != 11
            || nrsSifSwordPlus() != 3
            || nrsSifBlessPct() != 1
            || nrsSurturDmgLow() != 6
            || nrsSurturDmgHigh() != 60
            || nrsSurturArmorDmgLow() != 1
            || nrsSurturArmorDmgHigh() != 10
            || nrsSurturSwordFeet() != 15
            || nrsThorDmgLow() != 10
            || nrsThorDmgHigh() != 100
            || nrsThorDmgBonus() != 16
            || nrsThorMjolnirPlus() != 5
            || nrsThorThrowYards() != 200
            || nrsThorLightningDice() != 100
            || nrsThorStunRadiusFeet() != 30
            || nrsThorRedirectInches() != 200
            || nrsThorLiftStrength() != 25
            || nrsThorAllyPlus() != 2
            || nrsThorAllyYards() != 90
            || nrsThrymDmgLow() != 4
            || nrsThrymDmgHigh() != 40
            || nrsThrymDmgBonus() != 14
            || nrsThrymAxePlus() != 3
            || nrsThrymBrothers() != 10
            || nrsThrymBrotherAc() != 4
            || nrsThrymBrotherHp() != 100
            || nrsThrymBrotherMove() != 12
            || nrsThrymBrotherDmgLow() != 4
            || nrsThrymBrotherDmgHigh() != 24
            || nrsTyrDmgLow() != 2
            || nrsTyrDmgHigh() != 20
            || nrsTyrDmgBonus() != 12
            || nrsTyrSwordPlus() != 3
            || nrsTyrThiefSenseInches() != 100
            || nrsUllerDmgLow() != 2
            || nrsUllerDmgHigh() != 20
            || nrsUllerDmgBonus() != 11
            || nrsUllerBowPlus() != 5
            || nrsUllerBowRangeInches() != 200
            || nrsUllerSwordPlus() != 4
            || nrsGoatsCount() != 2
            || nrsGoatsDmgLow() != 3
            || nrsGoatsDmgHigh() != 24
            || nrsGoatsChargePlus() != 6
            || nrsGoatsXpRoman() != 10
            || nrsGoatsXpBase() != 14100
            || nrsGoatsFightHd() != 16
            || nrsVidarDmgLow() != 8
            || nrsVidarDmgHigh() != 80
            || nrsVidarSilenceRadiusInches() != 24
            || !nrsAesirVanirAllies()
            || !nrsVanirNotMen()
            || !nrsRagnarokEvilWins()
            || !nrsCureSpellsRare()
            || !nrsHangedAndSpeared()
            || !nrsOakPyre()
            || !nrsLunarMonthWorship()
            || !nrsGoldSilverUseful()
            || !nrsBlasphemyForgivenByBattle()
            || !nrsBifrostHidden()
            || !nrsJotunheimBlot()
            || !nrsEinheriarRagnarokArmy()
            || !nrsModsognerNonviolent()
            || !nrsDurinWeapons()
            || !nrsOdinCannotRaiseDead()
            || !nrsOdinAntsPolymorph()
            || !nrsOdinHlidskialf()
            || !nrsOdinOldManGuise()
            || !nrsOdinCompanionTrio()
            || !nrsOdinGungnirFear()
            || !nrsOdinPrayerDouble()
            || !nrsOdinRuneWandArtifact()
            || !nrsOdinRuneWandDeath()
            || !nrsOdinHealingComa()
            || !nrsHuginOddMovePrint()
            || !nrsHuginPlaneTeleport()
            || !nrsHuginSeeHearThrough()
            || !nrsHuginVerbalMessages()
            || !nrsSleipnerOdinOnly()
            || !nrsSleipnerOneAttacker()
            || !nrsSleipnerAnyMedium()
            || !nrsSleipnerOneMaster()
            || !nrsSleipnerValkyrieRide()
            || !nrsFrekePunishers()
            || !nrsFrekeSenseMagic()
            || !nrsFrekeSeeHidden()
            || !nrsAegirGiantKin()
            || !nrsAegirSlowNoSave()
            || !nrsAegirOverturnsShips()
            || !nrsAegirCastleWithRan()
            || !nrsBalderMistletoeOnly()
            || !nrsBalderEnchantGaze()
            || !nrsBalderHallBreidablik()
            || !nrsBragiNoViolence()
            || !nrsBragiHarpUncharm()
            || !nrsBragiHarpStopsAttack()
            || !nrsFenrisSwallowHalf()
            || !nrsFenrisGleipnirChain()
            || !nrsFenrisAsgardLoophole()
            || !nrsFjalarShunPlusTwo()
            || !nrsFjalarBattleLeader()
            || !nrsFjalarDurinRace()
            || !nrsForsetiDetectLies()
            || !nrsForsetiEvilMinusOne()
            || !nrsForsetiEvilPlusTwo()
            || !nrsForsetiNeverLies()
            || !nrsFossergrimCannotMissWater()
            || !nrsFossergrimMaleOffspring()
            || !nrsFossergrimWaterfallBound()
            || !nrsFreyShipFolds()
            || !nrsFreyWeatherControl()
            || !nrsFreyElfCommand()
            || !nrsBlodugDaylightGlow()
            || !nrsBlodugDefendMaster()
            || !nrsBlodugTeleportWill()
            || !nrsGullinNightRegen()
            || !nrsGullinTeleportWithGod()
            || !nrsGullinChariotPuller()
            || !nrsSkirnirAutoTeleport()
            || !nrsSkirnirLoyalShieldman()
            || !nrsFreyaRemoveCurse()
            || !nrsFreyaFalconGuise()
            || !nrsFreyaValkyrieLeader()
            || !nrsFreyaAvianFireImmune()
            || !nrsFreyaNecklaceLieGlow()
            || !nrsFreyaVanirTwin()
            || !nrsFriggaWeatherControl()
            || !nrsFriggaNecklaceCharm()
            || !nrsFriggaSeesBreezeAreas()
            || !nrsFriggaShapeChange()
            || !nrsFriggaDragonToAvian()
            || !nrsFriggaFlaxGold()
            || !nrsFriggaHandmaidenValkyries()
            || !nrsGarmHelGateGuard()
            || !nrsGarmTravelsPlanes()
            || !nrsGarmTreasureOfTheDead()
            || !nrsHeimdallAlwaysSurprise()
            || !nrsHeimdallNeverSurprised()
            || !nrsHeimdallUnlimitedClairvoyance()
            || !nrsHeimdallVorpalHofud()
            || !nrsHeimdallFrostSlaying()
            || !nrsHeimdallHornGjaller()
            || !nrsHeimdallLokiEnmity()
            || !nrsHelSwordDisease()
            || !nrsHelImperviousWeapons()
            || !nrsHelHalfWhiteHalfBlack()
            || !nrsHelSpectralHorse()
            || !nrsHelNiflheimPalace()
            || !nrsJormBodyInfinite()
            || !nrsJormHeadAnywhere()
            || !nrsJormRegenNextRound()
            || !nrsJormBitesOwnTail()
            || !nrsJormThorDoom()
            || !nrsIdunChestAlwaysFull()
            || !nrsIdunWifeOfBragi()
            || !nrsIdunApplesImmortal()
            || !nrsLokiBloodBrother()
            || !nrsLokiSuggestionPower()
            || !nrsLokiThreeRoundNoSave()
            || !nrsLokiIllusionsAbove()
            || !nrsLokiBootsOfFour()
            || !nrsLokiRedBlack()
            || !nrsLokiFireImmune()
            || !nrsLokiNoMagicControl()
            || !nrsLokiShapeChange()
            || !nrsLokiWouldBetray()
            || !nrsMagniBendAnything()
            || !nrsMagniLiftAnything()
            || !nrsMagniBluntImmune()
            || !nrsMagniLimitlessStrength()
            || !nrsModiAlwaysForefront()
            || !nrsModiRetreatSense()
            || !nrsModiBerserkDoubles()
            || !nrsModiControlImmune()
            || !nrsModiVorpalBlade()
            || !nrsNornsSwanForm()
            || !nrsNornsYggdrasil()
            || !nrsNornsAbilityDrain()
            || !nrsNornsNonmagicalImmune()
            || !nrsNornsNoWorshipers()
            || !nrsNornsImpartialFate()
            || !nrsSifPatronYoungWarriors()
            || !nrsSifGoldenHair()
            || !nrsSifControlImmune()
            || !nrsSurturFireImmune()
            || !nrsSurturRagnarokLeader()
            || !nrsSurturFireGiantDeity()
            || !nrsThorGloveJarngrieper()
            || !nrsThorGirdleMeginjarder()
            || !nrsThorHammerReturns()
            || !nrsThorThrownOnlyAttack()
            || !nrsThorPowerWordStun()
            || !nrsThorClericsUseHammers()
            || !nrsThorGiantMorale()
            || !nrsThorAlertsWorshipers()
            || !nrsThrymColdImmune()
            || !nrsThrymWhiteFur()
            || !nrsThrymRagnarokLeader()
            || !nrsThrymBrothersFight16()
            || !nrsThrymFrostGiantDeity()
            || !nrsTyrRightHandLost()
            || !nrsTyrLawByContract()
            || !nrsTyrValkyrieWatch()
            || !nrsTyrSeeInvisible()
            || !nrsTyrLeftHandSword()
            || !nrsUllerNoRangePenalty()
            || !nrsUllerElementalImmune()
            || !nrsUllerRuledForOdin()
            || !nrsUllerWinterAid()
            || !nrsUllerWanedPower()
            || !nrsUllerPatronArchers()
            || !nrsGoatsEatenReborn()
            || !nrsGoatsPullChariot()
            || !nrsVidarIronShoe()
            || !nrsVidarPinUnderfoot()
            || !nrsVidarStoicSilent()
            || !nrsVidarHatesEvil()
            || !nrsVidarSilenceUncounterable()
            || !nrsValkyriePegasiMaxHp()
            || !nrsValkyrieEthereal()
            || !nrsValkyrieAuroraLight()
            || !nrsValkyrieVisibleToDoomed()
            || !nrsValkyrieChooseSlain()
            || !nrsValkyrieSleipnerOffspring()
            || !nrsValkyrieServeOdin()
        )
            ++bad;
        // the the combat grid grid
        int CnrsCbt[35][9] = {
            {-6,0,400,15,0,2,0,85,78},
            {2,0,30,1,48,1,0,75,36},
            {-1,0,200,24,0,3,0,25,144},
            {4,0,75,24,0,1,0,50,120},
            {-5,0,387,42,0,2,0,50,84},
            {-4,0,388,18,0,3,2,75,72},
            {-4,0,370,18,0,3,2,75,72},
            {-4,0,400,24,12,1,0,99,600},
            {-3,0,99,12,0,2,0,0,48},
            {-4,0,389,18,0,3,2,85,72},
            {0,0,5,9,36,2,0,0,72},
            {-5,0,388,18,0,3,2,75,72},
            {3,0,50,24,18,3,0,75,108},
            {-4,0,100,18,32,2,0,75,120},
            {-3,0,99,12,0,3,2,0,72},
            {-3,0,339,18,48,1,0,80,72},
            {-4,0,366,15,0,0,0,75,72},
            {-1,0,200,18,0,1,0,80,144},
            {-5,0,390,15,0,2,0,80,84},
            {-5,0,350,-1,0,3,2,95,78},
            {-3,0,300,0,0,1,0,99,0},
            {-3,0,329,12,18,3,2,25,72},
            {-4,0,300,12,12,3,2,75,72},
            {-4,0,325,18,0,2,0,70,84},
            {-4,0,379,21,0,2,4,95,84},
            {0,0,299,12,21,1,0,80,60},
            {-4,0,349,18,0,2,0,80,72},
            {-2,0,380,15,0,2,0,60,240},
            {4,0,399,18,0,2,3,80,84},
            {-2,0,300,15,0,2,0,60,252},
            {-5,0,380,18,0,3,0,25,78},
            {-3,0,390,24,0,2,0,50,84},
            {0,0,100,24,24,3,0,25,108},
            {-3,0,380,21,0,2,0,95,240},
            {-2,0,100,15,0,2,0,25,66},
            };
        for (int b = 0;
             b < nrsCbtRows();
             ++b) {
            int vals[9];
            vals[0] = nrsCbtAC(b);
            vals[1] = nrsCbtACAlt(b);
            vals[2] = nrsCbtHP(b);
            vals[3] = nrsCbtMove(b);
            vals[4] = nrsCbtMoveAlt(b);
            vals[5] = nrsCbtAtN(b);
            vals[6] = nrsCbtAtD(b);
            vals[7] = nrsCbtMR(b);
            vals[8] = nrsCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CnrsCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CnrsCls[35][11] = {
            {30,14,0,18,0,30,0,0,0,0,15},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {15,0,0,15,0,10,10,0,0,0,5},
            {12,12,0,10,0,0,0,0,0,0,20},
            {10,10,0,7,0,0,15,0,0,0,23},
            {0,0,0,0,0,0,0,0,0,0,0},
            {5,0,10,0,0,0,0,10,0,0,0},
            {0,10,0,15,0,10,10,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {13,13,0,15,0,20,0,0,0,0,15},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,9,0,0,0,0,0,0,5},
            {15,10,0,7,0,0,15,0,0,0,12},
            {15,0,0,7,0,18,0,0,0,0,10},
            {0,0,0,0,0,0,0,0,0,0,0},
            {12,12,0,17,0,0,0,0,0,0,8},
            {20,10,0,12,0,15,15,0,15,0,10},
            {0,0,0,0,0,0,0,0,0,0,0},
            {15,14,0,7,0,0,0,0,0,0,13},
            {12,12,0,12,0,11,20,0,15,5,5},
            {0,0,15,0,0,0,0,0,0,0,5},
            {0,0,15,0,0,0,0,0,0,0,9},
            {12,12,0,5,0,15,15,10,0,8,8},
            {0,12,0,12,0,0,0,0,0,12,12},
            {15,0,20,0,0,5,0,0,0,0,0},
            {0,10,20,0,0,0,0,0,0,0,3},
            {10,0,20,0,0,0,3,0,0,0,0},
            {0,13,0,0,25,0,10,15,0,10,10},
            {0,13,0,18,0,0,12,0,12,0,12},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,10,0,18,0,0,0,0,0,0,0},
            {0,0,15,0,0,0,0,0,0,0,8},
            };
        for (int b = 0;
             b < nrsClsRows();
             ++b) {
            int vals[11];
            vals[0] = nrsClsClr(b);
            vals[1] = nrsClsDrd(b);
            vals[2] = nrsClsFtr(b);
            vals[3] = nrsClsRng(b);
            vals[4] = nrsClsPal(b);
            vals[5] = nrsClsMU(b);
            vals[6] = nrsClsIll(b);
            vals[7] = nrsClsThf(b);
            vals[8] = nrsClsAss(b);
            vals[9] = nrsClsMnk(b);
            vals[10] = nrsClsBrd(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CnrsCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CnrsAbi[35][8] = {
            {25,7,14,25,25,25,25,25},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {23,5,11,23,18,23,24,9},
            {22,4,10,24,24,24,25,25},
            {23,5,11,24,24,25,25,24},
            {0,0,0,0,0,0,0,0},
            {19,3,7,15,15,18,18,12},
            {24,6,12,25,24,22,25,23},
            {0,0,0,0,0,0,0,0},
            {24,6,12,24,23,24,25,23},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {17,1,1,14,18,18,18,18},
            {24,6,12,24,24,24,25,20},
            {20,3,8,23,20,24,25,25},
            {0,0,0,0,0,0,0,0},
            {25,7,14,23,24,25,25,23},
            {20,3,8,24,25,24,25,25},
            {0,0,0,0,0,0,0,0},
            {20,3,8,22,23,24,24,24},
            {24,6,12,25,19,24,24,24},
            {25,0,0,20,20,24,25,22},
            {24,6,12,23,22,24,25,25},
            {23,5,11,22,25,23,25,9},
            {23,5,11,24,22,25,25,25},
            {25,7,14,19,14,12,25,20},
            {25,7,16,20,20,25,25,24},
            {25,7,14,16,12,21,25,20},
            {24,6,12,20,20,25,25,24},
            {23,5,11,24,24,25,25,25},
            {0,0,0,0,0,0,0,0},
            {25,7,14,20,19,25,25,22},
            {19,3,7,17,17,18,19,19},
            };
        for (int b = 0;
             b < nrsAbiRows();
             ++b) {
            int vals[8];
            vals[0] = nrsAbiS(b);
            vals[1] = nrsAbiHit(b);
            vals[2] = nrsAbiDmg(b);
            vals[3] = nrsAbiI(b);
            vals[4] = nrsAbiW(b);
            vals[5] = nrsAbiD(b);
            vals[6] = nrsAbiC(b);
            vals[7] = nrsAbiCH(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CnrsAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CnrsRos[35][9] = {
            {113,1,0,5,1,1,0,0,1},
            {114,0,0,4,5,0,1,0,0},
            {114,0,0,1,5,0,1,0,0},
            {114,0,0,4,5,0,1,0,0},
            {115,1,0,3,0,5,1,1,0},
            {115,1,0,5,1,6,1,1,0},
            {115,2,0,5,0,5,1,1,0},
            {115,0,0,8,5,0,1,0,0},
            {116,0,0,4,4,0,1,0,0},
            {116,1,0,0,1,2,1,1,0},
            {116,0,0,4,5,0,1,0,0},
            {116,1,0,5,1,2,1,1,0},
            {117,0,0,4,5,0,1,0,0},
            {117,0,0,4,5,0,1,0,0},
            {117,0,0,5,4,6,0,0,0},
            {117,1,0,5,1,6,0,0,0},
            {118,1,0,1,1,2,0,0,0},
            {118,0,0,6,5,0,1,0,0},
            {118,1,0,0,1,3,1,1,0},
            {119,3,0,7,1,1,1,1,0},
            {119,0,0,8,5,0,1,0,0},
            {119,1,0,2,0,5,0,0,0},
            {119,4,1,8,1,4,0,1,0},
            {120,1,0,2,0,6,1,0,0},
            {120,1,0,2,0,4,1,0,0},
            {120,5,0,4,4,1,1,1,0},
            {121,1,0,2,0,6,1,1,0},
            {121,1,0,6,0,0,1,0,2},
            {121,1,0,2,1,6,1,0,0},
            {122,1,0,8,0,0,1,0,2},
            {122,1,0,0,1,1,1,1,0},
            {122,1,0,3,0,1,1,0,0},
            {122,0,0,4,5,0,1,0,0},
            {123,1,0,2,0,6,1,0,0},
            {123,0,0,3,4,0,0,0,0},
            };
        for (int b = 0;
             b < nrsRosRows();
             ++b) {
            int vals[9];
            vals[0] = nrsRosPage(b);
            vals[1] = nrsRosPlane(b);
            vals[2] = nrsRosPlaneAlt(b);
            vals[3] = nrsRosAlign(b);
            vals[4] = nrsRosRank(b);
            vals[5] = nrsRosPsi(b);
            vals[6] = nrsRosDmgFixed(b);
            vals[7] = nrsRosInEach(b);
            vals[8] = nrsRosParen(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CnrsRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the thirty-five beings, the rank,
        // plane and psionic counts)
    if (nrsRound() != 865
            || nrsBeingCount() != 35
            || nrsTableCount() != 4
            || nrsChainCount() != 0
            || nrsCbtRows() != 35
            || nrsClsRows() != 35
            || nrsAbiRows() != 35
            || nrsRosRows() != 35
            || nrsGreaterCount() != 11
            || nrsLesserCount() != 10
            || nrsNoRankCount() != 4
            || nrsMonsterCount() != 11
            || nrsGladsheimCount() != 18
            || nrsElysiumCount() != 1
            || nrsHadesCount() != 1
            || nrsPandemoniumCount() != 1
            || nrsConcordantCount() != 1
            || nrsNoPlaneCount() != 13
            || nrsDualPlaneCount() != 1
            || nrsPlaneCodeCount() != 5
            || nrsPsiRowCount() != 21
            || nrsPsiNilCount() != 14
            || nrsPsiOneCount() != 5
            || nrsPsiTwoCount() != 3
            || nrsPsiThreeCount() != 1
            || nrsPsiFourCount() != 2
            || nrsPsiFiveCount() != 3
            || nrsPsiSixCount() != 7
            || nrsDmgFixedCount() != 27
            || nrsInEachCount() != 11
            || nrsDualMoveCount() != 10
            || nrsDualSameMoveCount() != 2
            || nrsInfiniteMoveCount() != 1
            || nrsHalfFootCount() != 4
            || nrsValhallaCount() != 1
            || nrsJotunheimCount() != 2
            || nrsCompanionCount() != 6
            || nrsRegistryFloor() != 995
            || nrsCensusAfter() != 788
            || nrsPrintStart() != 113
            || nrsPrintEnd() != 124
        )
            ++bad;
        // the combat grid head cells (the AC and hit point extremes, the odd
        // prints)
    if (nrsCbtAC(0) != -6
            || nrsCbtHP(0) != 400
            || nrsCbtAC(28) != 4
            || nrsCbtHP(3) != 75
            || nrsCbtMR(7) != 99
            || nrsCbtMR(20) != 99
            || nrsCbtAC(8) != -3
            || nrsCbtHP(8) != 99
            || nrsCbtHP(10) != 5
            || nrsCbtMove(19) != -1
            || nrsCbtMove(20) != 0
            || nrsCbtAtN(16) != 0
            || nrsCbtAtD(24) != 4
            || nrsCbtAtD(28) != 3
            || nrsCbtSizeIn(7) != 600
            || nrsCbtSizeIn(20) != 0
        )
            ++bad;
        // the half-foot size decode and the L&L parity (the 6 and a half foot
        // gods and the 5 and a half foot Valkyries)
    if (nrsCbtSizeIn(0) != 78
            || nrsCbtSizeIn(19) != 78
            || nrsCbtSizeIn(30) != 78
            || nrsCbtSizeIn(34) != 66
            || nrsAbiS(0) != 25
        )
            ++bad;
        // Odin the All Father (the 30th level Special cleric, the rune wand,
        // the companions)
    if (nrsClsClr(0) != 30
            || nrsClsDrd(0) != 14
            || nrsClsRng(0) != 18
            || nrsClsMU(0) != 30
            || nrsClsBrd(0) != 15
            || nrsRosPsi(0) != 1
            || nrsOdinTelepathyMiles() != 300
            || nrsOdinWandPowers() != 5
            || nrsOdinWandSpells() != 12
            || nrsOdinDraupnirGp() != 30000
            || nrsOdinBowArrows() != 10
            || nrsOdinSpearPlus() != 5
            || nrsOdinCannotRaiseDead() != 1
            || nrsOdinAntsPolymorph() != 1
        )
            ++bad;
        // the Odin companion trio (the ravens, the steed, the wolves - the
        // walk first companion blocks)
    if (nrsCbtAC(1) != 2
            || nrsCbtMove(1) != 1
            || nrsCbtMoveAlt(1) != 48
            || nrsHuginXpRoman() != 6
            || nrsHuginXpBase() != 815
            || nrsHuginAttackHd() != 7
            || nrsSleipnerXpBase() != 20600
            || nrsFrekeXpRoman() != 9
            || nrsFrekeHpEach() != 75
            || nrsCbtSizeIn(2) != 144
            || nrsHuginOddMovePrint() != 1
            || nrsSleipnerOneAttacker() != 1
        )
            ++bad;
        // the sea and storm gods (Aegir the giant-kin, the Balder charisma
        // gift, the Bragi song)
    if (nrsCbtAC(4) != -5
            || nrsCbtMove(4) != 42
            || nrsAegirDmgBonus() != 11
            || nrsBalderCharismaGift() != 2
            || nrsBragiSongYards() != 30
            || nrsBragiHarpDays() != 7
            || nrsRosPlane(6) != 2
            || nrsAegirSlowNoSave() != 1
            || nrsBalderMistletoeOnly() != 1
        )
            ++bad;
        // the Fenris Wolf and the binding (the 9-90 bite, the swallow rule)
    if (nrsCbtAC(7) != -4
            || nrsCbtHP(7) != 400
            || nrsCbtMoveAlt(7) != 12
            || nrsFenrisXpBase() != 33200
            || nrsFenrisDmgHigh() != 90
            || nrsFenrisWeaponPlus() != 4
            || nrsFenrisSwallowHalf() != 1
            || nrsFenrisGleipnirChain() != 1
        )
            ++bad;
        // the dwarven hero and the justice god (Fjalar the shun-skin, Forseti
        // the peacemaker)
    if (nrsRosRank(8) != 4
            || nrsClsThf(8) != 10
            || nrsFjalarGauntletPlus() != 3
            || nrsForsetiDmgBonus() != 12
            || nrsForsetiLieDays() != 7
            || nrsRosPsi(9) != 2
            || nrsFjalarShunPlusTwo() != 1
            || nrsForsetiDetectLies() != 1
        )
            ++bad;
        // the fossergrim waterfall men (the 5 HD print, the V/320+5 XP)
    if (nrsCbtHP(10) != 5
            || nrsFossergrimXpBase() != 320
            || nrsFossergrimXpPerHp() != 5
            || nrsFossergrimMileLimit() != 1
            || nrsFossergrimRegen() != 5
            || nrsFossergrimCannotMissWater() != 1
        )
            ++bad;
        // Frey the Vanir and his household (the giant-slaying sword, the
        // folding ship, the boar and horse)
    if (nrsRosPlane(11) != 1
            || nrsClsClr(11) != 13
            || nrsFreyFireGiantHigh() != 100
            || nrsFreyOtherGiantHigh() != 50
            || nrsFreyShipRate() != 60
            || nrsBlodugFireSavePlus() != 4
            || nrsGullinRegen() != 1
            || nrsBlodugXpBase() != 4500
            || nrsGullinXpBase() != 22300
            || nrsFreyShipFolds() != 1
            || nrsSkirnirAutoTeleport() != 1
        )
            ++bad;
        // the greater goddesses (Freya the Valkyrie leader, Frigga the
        // weather wife, Hel the withering death)
    if (nrsCbtAC(15) != -3
            || nrsFreyaFireSpellLevel() != 30
            || nrsFreyaNecklaceGp() != 1000000
            || nrsHelWitherYards() != 90
            || nrsHelWitherHp() != 20
            || nrsHelPlagueHp() != 5
            || nrsHelDmgBonus() != 8
            || nrsRosPlane(19) != 3
            || nrsFreyaValkyrieLeader() != 1
            || nrsFriggaDragonToAvian() != 1
            || nrsHelImperviousWeapons() != 1
        )
            ++bad;
        // the guardians (Garm the Hel gate, Heimdall the Bifrost watchman)
    if (nrsGarmXpBase() != 26200
            || nrsGarmWolfPack() != 20
            || nrsGarmFearSaveMod() != -4
            || nrsHeimdallDmgBonus() != 14
            || nrsHeimdallArmorPlus() != 3
            || nrsRosPsi(18) != 3
            || nrsGarmHelGateGuard() != 1
            || nrsHeimdallVorpalHofud() != 1
            || nrsHeimdallLokiEnmity() != 1
        )
            ++bad;
        // the Jormungandr oddities (the 25,000 miles, the infinite body, the
        // slashless XP print)
    if (nrsJormMiles() != 25000
            || nrsJormHeadHp() != 300
            || nrsJormConstrictionHigh() != 100
            || nrsJormPoisonSaveMod() != -5
            || nrsJormXpBase() != 55000
            || nrsJormFightHd() != 16
            || nrsJormBodyInfinite() != 1
            || nrsJormHeadAnywhere() != 1
        )
            ++bad;
        // Loki the mischief god (the Pandemonium-or-Gladsheim dual plane, the
        // suggestion power, the red and black)
    if (nrsRosPlane(22) != 4
            || nrsRosPlaneAlt(22) != 1
            || nrsLokiIllusionLevel() != 20
            || nrsClsAss(22) != 15
            || nrsClsMnk(22) != 5
            || nrsRosPsi(22) != 4
            || nrsLokiBloodBrother() != 1
            || nrsLokiThreeRoundNoSave() != 1
            || nrsLokiBootsOfFour() != 1
        )
            ++bad;
        // the Thor sons and the Norns (Magni the limitless, Modi the vorpal
        // berserk, the three fates)
    if (nrsAbiS(23) != 25
            || nrsAbiHit(23) != 0
            || nrsModiVorpalDmg() != 25
            || nrsModiBerserkDmg() != 50
            || nrsModiAuraBonus() != 4
            || nrsNornsCount() != 3
            || nrsRosPlane(25) != 5
            || nrsFriggaMaidenNames() != 10
            || nrsMagniBluntImmune() != 1
            || nrsModiBerserkDoubles() != 1
            || nrsNornsAbilityDrain() != 1
        )
            ++bad;
        // the thunder family and the giant lords (Sif, Thor, Surtur, Thrym,
        // the Tyr law, Uller the archer)
    if (nrsCbtAC(28) != 4
            || nrsThorMjolnirPlus() != 5
            || nrsThorLightningDice() != 100
            || nrsThorAllyPlus() != 2
            || nrsThrymBrothers() != 10
            || nrsThrymDmgBonus() != 14
            || nrsClsPal(30) != 25
            || nrsTyrThiefSenseInches() != 100
            || nrsUllerBowPlus() != 5
            || nrsThorGloveJarngrieper() != 1
            || nrsSurturFireImmune() != 1
            || nrsTyrLawByContract() != 1
            || nrsUllerElementalImmune() != 1
        )
            ++bad;
        // the chariot goats and the Valkyries (the eaten-and-reborn pair, the
        // choosers of the slain)
    if (nrsGoatsChargePlus() != 6
            || nrsGoatsXpBase() != 14100
            || nrsGoatsDmgHigh() != 24
            || nrsCbtMoveAlt(32) != 24
            || nrsCbtHP(34) != 100
            || nrsCbtSizeIn(34) != 66
            || nrsGoatsEatenReborn() != 1
            || nrsValkyrieSleipnerOffspring() != 1
            || nrsValkyrieAuroraLight() != 1
        )
            ++bad;
        // Vidar the silent strength (the iron shoe, the uncounterable
        // silence)
    if (nrsVidarDmgHigh() != 80
            || nrsVidarSilenceRadiusInches() != 24
            || nrsCbtSizeIn(33) != 240
            || nrsVidarIronShoe() != 1
            || nrsVidarSilenceUncounterable() != 1
        )
            ++bad;
        // the in-each pairs and the roster walk (every in-each row and its
        // class cells)
    if (nrsRosInEach(4) + nrsRosInEach(5) + nrsRosInEach(6) + nrsRosInEach(9)
        + nrsRosInEach(11) + nrsRosInEach(18) + nrsRosInEach(19) +
        nrsRosInEach(22) + nrsRosInEach(25) + nrsRosInEach(26) +
        nrsRosInEach(30) != 11
            || nrsClsMU(4) != 10
            || nrsClsIll(4) != 10
            || nrsClsMnk(26) != 12
            || nrsClsBrd(26) != 12
            || nrsClsMnk(30) != 10
            || nrsClsBrd(30) != 10
        )
            ++bad;
        // the psionic pipe geometry (the II pipes at width 15, the III of
        // Heimdall, the I singles)
    if (nrsRosPsi(9) != 2
            || nrsRosPsi(11) != 2
            || nrsRosPsi(16) != 2
            || nrsRosPsi(18) != 3
            || nrsRosPsi(14) != 6
            || nrsRosPsi(31) != 1
            || nrsRosPsi(24) != 4
            || nrsRosPsi(27) != 0
            || nrsRosPsi(29) != 0
        )
            ++bad;
        printf("R865 Norse mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
