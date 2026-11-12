    // ---- R862 Melnibonean mythos audit ----
    // THE MELNIBONEAN MYTHOS - the D&DG walk round fourteen, print pp. 86-95,
    // the monster-heaviest round of the walk: fourteen of the thirty-three
    // rows are monsters, from the Assassinator of the Gods to the Vulture
    // Lion. The headline adjudication: the ELRIC DUAL PRINT - the emperor
    // carries the walk's only dual armor class (6 and minus 6, the latter the
    // Stormbringer wield-state) and a dual move (6 and 15); his printed
    // Standard-or-85% magic resistance pins 0 with the 85 riding the
    // Stormbringer consts. The SEE BELOW 99 PAIRS (the egp Isis precedent):
    // Grome and Nuru-ah print See below on both the cleric and magic-user
    // lines, Kakatal, Misha and Straasha on the magic-user/illusionist line -
    // all pinned 99. The VARIABLE PINS: Arioch prints both SIZE: Variable and
    // CHARISMA: Variable - both pinned 0 with col comments. The negative
    // charisma cells: Nnuurrr and Pyaray print CH: -6. The flagged odd prints
    // pinned as printed: the Haaashastaak and Nnuurrr W: 3 wisdom cells. The
    // BARE AND STRAY SIZE PRINTS: Fileet the bare L pinned 0 (the R861 bare-M
    // precedent), the Vampire Trees the L-plus-25-feet-tall print read as 300
    // with the stray plus noted. The XP romans of the monster rows verified:
    // VIII/6,200 Assassinator flat, X/21,450 Quaolnargn flat, VIII/6,391
    // Mordagz flat, and the per-hit-point rows Clakar VI/650+10, Dharzi
    // II/90+5, Myyrrhn III/125+4, Nihrain and Oonai VII/1,950+14, Mist Giant
    // VIII/4,950+16, Vampire Trees VIII/3,850+16, Vulture Lion IX/5,600+20;
    // the Kelmain Variable XP rides a bool. The fraction fingerprint: three X
    // 1/2 cells - Moonglum 66, Theleb K'aarna 66, Yyrkoon 78. The
    // ELENOIN-GRAHUK ENMITY PAIR: the hereditary enemy flags, the grk
    // printed-rivalry precedent, the round's only rivalry print. The psionic
    // pipes: the w10 single pipe I of Arioch, Darnizhaan, Meerclar and
    // Nuru-ah, Pyaray II, the w49 VI of Grome, Haaashastaak, Misha, Roofdrak
    // and Straasha.
    {
        using namespace rules;
        int bad = 0;
    if (mlbRound() != 862
            || mlbPrintStart() != 86
            || mlbPrintEnd() != 95
            || mlbBeingCount() != 33
            || mlbTableCount() != 4
            || mlbChainCount() != 0
            || mlbRegistryFloor() != 995
            || mlbCbtRows() != 33
            || mlbClsRows() != 33
            || mlbAbiRows() != 33
            || mlbRosRows() != 33
            || mlbPlaneCount() != 13
            || mlbGreaterCount() != 3
            || mlbLesserCount() != 6
            || mlbDemigodCount() != 6
            || mlbHeroCount() != 4
            || mlbMonsterCount() != 14
            || mlbInEachCount() != 4
            || mlbEnmityCount() != 2
            || mlbPaladinCount() != 0
            || mlbPsiClassKinds() != 3
            || mlbHalfFootCount() != 3
            || mlbArtifactCount() != 3
            || mlbChaosArrows() != 8
            || mlbLawArrows() != 1
            || mlbArrowsOfLawPerQuiver() != 20
            || mlbNanorionHeartPct() != 5
            || mlbNanorionDemonHp() != 80
            || mlbNanorionUsesMax() != 4
            || mlbNanorionClericLevel() != 15
            || mlbStormbringerPlus() != 5
            || mlbStormbringerInt() != 18
            || mlbStormbringerEgo() != 20
            || mlbStormbringerLevelsPerGain() != 2
            || mlbStormbringerHpPerGain() != 5
            || mlbStormbringerStrPerGain() != 1
            || mlbStormbringerMaxStr() != 23
            || mlbStormbringerSatietyLevels() != 200
            || mlbStormbringerSatietyHours() != 8
            || mlbStormbringerLastGainTurns() != 10
            || mlbStormbringerSummonPct() != 60
            || mlbStormbringerMrPct() != 85
            || mlbStormbringerMoveInches() != 15
            || mlbStormbringerAc() != 6
            || mlbStormbringerDancePct() != 15
            || mlbStormbringerFearHd() != 5
            || mlbStormbringerFearFeet() != 30
            || mlbRingSummonPct() != 70
            || mlbRingControlPct() != 80
            || mlbRingBareSummonPct() != 20
            || mlbRingBareControlPct() != 30
            || mlbElricPotionChancePct() != 85
            || mlbElricPotionStatMax() != 15
            || mlbAriochDancePct() != 15
            || mlbAssassinatorWingsFeet() != 50
            || mlbAssassinatorTalonHd() != 11
            || mlbAssassinatorFoulPct() != 50
            || mlbAssassinatorHitDice() != 8
            || mlbAssassinatorXpBase() != 6200
            || mlbClakarRendMax() != 8
            || mlbClakarHitDice() != 6
            || mlbClakarXpBase() != 650
            || mlbClakarXpPerHp() != 10
            || mlbDharziScentDays() != 7
            || mlbDharziClawMax() != 4
            || mlbDharziBiteMax() != 12
            || mlbDharziHitDice() != 2
            || mlbDharziXpBase() != 90
            || mlbDharziXpPerHp() != 5
            || mlbDarnizhaanDiggerPct() != 5
            || mlbDarnizhaanDiggerFeet() != 100
            || mlbDarnizhaanFistMax() != 60
            || mlbDonblasWorshipLevel() != 12
            || mlbDonblasRodDmgMax() != 30
            || mlbElenoinGrahukPct() != 5
            || mlbElenoinHitDice() != 7
            || mlbElenoinXpBase() != 1670
            || mlbGrahukStrength() != 22
            || mlbGrahukHitDice() != 8
            || mlbGrahukXpBase() != 6650
            || mlbFileetWingspanFeet() != 120
            || mlbFileetBirdsMax() != 100
            || mlbGromeEarthSpellLevel() != 50
            || mlbGromeElementalMax() != 20
            || mlbGromeElementalHd() != 16
            || mlbHaaashastaakBiteMax() != 70
            || mlbKakatalFireSpellLevel() != 30
            || mlbKakatalHeatDmgMax() != 40
            || mlbKakatalHeatFeet() != 20
            || mlbKakatalFistMax() != 48
            || mlbKakatalElementalMax() != 10
            || mlbKakatalElementalHd() != 16
            || mlbKelmainTroopMin() != 10
            || mlbKelmainTroopMax() != 10000
            || mlbKelmainLeaderLevelMax() != 8
            || mlbKelmainLeaderLevelMin() != 2
            || mlbMeerclarClawMax() != 72
            || mlbMeerclarBiteMax() != 100
            || mlbMistGiantArms() != 4
            || mlbMistGiantInvisiblePct() != 90
            || mlbMistGiantSurpriseMax() != 5
            || mlbMistGiantHitDice() != 12
            || mlbMistGiantXpBase() != 4950
            || mlbMistGiantXpPerHp() != 16
            || mlbMishaWhirlwindInches() != 30
            || mlbMishaWhirlwindRounds() != 3
            || mlbMishaWhirlwindBottomInches() != 6
            || mlbMishaWhirlwindTopInches() != 18
            || mlbMishaWhirlwindDmgMax() != 60
            || mlbMishaStrikeMax() != 64
            || mlbMishaElementalMax() != 20
            || mlbMishaElementalHd() != 16
            || mlbMishaWeatherLevel() != 20
            || mlbMordagzShieldFeet() != 5
            || mlbMordagzHitDice() != 8
            || mlbMordagzXpBase() != 6391
            || mlbMyyrrnWingspanFeet() != 10
            || mlbMyyrrnFleeBelowHp() != 5
            || mlbMyyrrnHitDice() != 3
            || mlbMyyrrnXpBase() != 125
            || mlbMyyrrnXpPerHp() != 4
            || mlbNnuurrrObeyPct() != 55
            || mlbNnuurrrFearLevel() != 8
            || mlbNnuurrrPoisonSavePenalty() != 4
            || mlbNnuurrrDrainMax() != 40
            || mlbNnuurrrWingspanFeet() != 140
            || mlbNihrainEtherealPct() != 25
            || mlbNihrainGallopHours() != 48
            || mlbNihrainHitDice() != 7
            || mlbNihrainXpBase() != 1950
            || mlbNihrainXpPerHp() != 14
            || mlbOonaiFormHdMax() != 10
            || mlbOonaiHitDice() != 7
            || mlbOonaiXpBase() != 1950
            || mlbOonaiXpPerHp() != 14
            || mlbQuaolnargnSaveTarget() != 3
            || mlbQuaolnargnDrainLevels() != 4
            || mlbQuaolnargnBiteMax() != 10
            || mlbQuaolnargnHitDice() != 10
            || mlbQuaolnargnXpBase() != 21450
            || mlbPyarayTentacles() != 6
            || mlbPyarayTentacleMax() != 40
            || mlbPyarayGemHp() != 10
            || mlbRoofdrakMaceMax() != 90
            || mlbRoofdrakWolfMax() != 100
            || mlbStraashaWaterLevel() != 20
            || mlbStraashaKindredMin() != 3
            || mlbStraashaKindredMax() != 18
            || mlbStraashaWaveMax() != 48
            || mlbVampTreeLeafDmgMax() != 8
            || mlbVampTreeLeafHp() != 2
            || mlbVampTreeLeafAc() != 9
            || mlbVampTreeLeafControlMax() != 10
            || mlbVampTreeRangeYards() != 120
            || mlbVampTreeFireSavePenalty() != 2
            || mlbVampTreeHitDice() != 8
            || mlbVampTreeXpBase() != 3850
            || mlbVampTreeXpPerHp() != 16
            || mlbThelebAncestorSpellLevel() != 7
            || mlbVultureLionTalonMax() != 24
            || mlbVultureLionBiteMax() != 18
            || mlbVultureLionHitDice() != 9
            || mlbVultureLionXpBase() != 5600
            || mlbVultureLionXpPerHp() != 20
            || mlbXiombargAxePlus() != 4
            || mlbXiombargAxeMax() != 42
            || mlbXiombargPlusToHit() != 3
            || !mlbGodsManyPlanes()
            || !mlbAvatarConnection()
            || !mlbOneClassAttribute()
            || !mlbFullPowersHomePlane()
            || !mlbOtherChaosGodsNamed()
            || !mlbLawfulGodsSilkForm()
            || !mlbMasterTypesDoctrine()
            || !mlbDogsWorshipOwnImage()
            || !mlbArrowsOfLawSlayChaotic()
            || !mlbArrowsOfLawNormalRanges()
            || !mlbCrystalDoorUnbreakable()
            || !mlbCrystalDoorMagicImmune()
            || !mlbCrystalDoorOpensOnWord()
            || !mlbCrystalDoorDrainsSpells()
            || !mlbCrystalDoorDrainsDevices()
            || !mlbNanorionRaisePower()
            || !mlbStormbringerDrainsLevels()
            || !mlbStormbringerDevoursSouls()
            || !mlbStormbringerEvilRadiance()
            || !mlbRingOfKingsPowers()
            || !mlbElricAlbino()
            || !mlbElricSwordAltersMakeup()
            || !mlbAriochElricPatron()
            || !mlbAriochNoArmor()
            || !mlbAriochSwordCancellation()
            || !mlbAriochAnyPlane()
            || !mlbAriochHumanSacrifice()
            || !mlbAriochHandsomeToAll()
            || !mlbAriochShortTemper()
            || !mlbMoonglumAmbidextrous()
            || !mlbMoonglumElricCompanion()
            || !mlbMoonglumDapper()
            || !mlbAssassinatorPeacockFeathers()
            || !mlbAssassinatorChaosErrand()
            || !mlbClakarWingedApes()
            || !mlbClakarFearImmune()
            || !mlbClakarNeverSurprised()
            || !mlbDharziHawkHead()
            || !mlbDharziFaultlessTrackers()
            || !mlbDharziPacks()
            || !mlbDarnizhaanDeadGodsKing()
            || !mlbDarnizhaanFearsNewGods()
            || !mlbDarnizhaanManufacturedImmune()
            || !mlbDonblasIncrediblyBeautiful()
            || !mlbDonblasDrivenOff()
            || !mlbDonblasWaitsSummon()
            || !mlbDonblasRodOfThree()
            || !mlbDonblasComesToFight()
            || !mlbElenoinSharkTeeth()
            || !mlbElenoinTenthFighters()
            || !mlbElenoinHereditaryEnemies()
            || !mlbGrahukGiantApes()
            || !mlbGrahukAttackAsFifteen()
            || !mlbGrahukNetsAndRopes()
            || !mlbGrahukOnlyGoal()
            || !mlbGrahukSuicide()
            || !mlbFileetGoldenEagle()
            || !mlbFileetAvianSight()
            || !mlbFileetAvianHomage()
            || !mlbGromeKingOfEarth()
            || !mlbGromeWaterCrossing()
            || !mlbGromeOakForm()
            || !mlbGromeFistBarrier()
            || !mlbGromeUndergroundHomage()
            || !mlbHaaashastaakTyrannosaur()
            || !mlbHaaashastaakEatsCaller()
            || !mlbHaaashastaakNeverMisses()
            || !mlbHaaashastaakWishToReturn()
            || !mlbHaaashastaakReptilianHomage()
            || !mlbHaaashastaakLizardAware()
            || !mlbKakatalFireKing()
            || !mlbKakatalWaterFireImmune()
            || !mlbKakatalFireHomage()
            || !mlbKakatalPetrifyImmune()
            || !mlbKelmainLimboHome()
            || !mlbKelmainGoldenSkin()
            || !mlbKelmainGoldArmor()
            || !mlbKelmainKeepTheLand()
            || !mlbKelmainPetrifyImmune()
            || !mlbKelmainXpVariable()
            || !mlbMeerclarSabreTooth()
            || !mlbMeerclarCatEyes()
            || !mlbMeerclarKillsCaller()
            || !mlbMeerclarFelineHomage()
            || !mlbMistGiantFogForm()
            || !mlbMistGiantSlither()
            || !mlbMistGiantSilent()
            || !mlbMistGiantPlusTwoToHit()
            || !mlbMishaAirKing()
            || !mlbMishaAirLaunchedImmune()
            || !mlbMishaAirHomage()
            || !mlbMishaPlusFourToHit()
            || !mlbMordagzDemotedLord()
            || !mlbMordagzChaosShieldGuard()
            || !mlbMordagzFrontOnly()
            || !mlbMordagzFightsAsFifteen()
            || !mlbMyyrrnWingedHumanoids()
            || !mlbMyyrrnAirCombat()
            || !mlbMyyrrnOwlEnemies()
            || !mlbNnuurrrHatesSummoning()
            || !mlbNnuurrrInsectHomage()
            || !mlbNihrainBlackStallion()
            || !mlbNihrainNeutralService()
            || !mlbNuruAhPacifist()
            || !mlbNuruAhCureRaise()
            || !mlbNuruAhWoundedSafe()
            || !mlbNuruAhBovineWorship()
            || !mlbOonaiShapeChangers()
            || !mlbOonaiBeastsOnly()
            || !mlbOonaiOneAtATime()
            || !mlbOonaiRetainAcHp()
            || !mlbOonaiUnknownForm()
            || !mlbQuaolnargnAbyssToad()
            || !mlbQuaolnargnPetrifyImmune()
            || !mlbQuaolnargnSixteenHdBite()
            || !mlbQuaolnargnEarlyKillRefund()
            || !mlbPyarayOceanAbyss()
            || !mlbPyarayBlueGem()
            || !mlbPyarayGemDiamondHard()
            || !mlbPyarayChaosFleet()
            || !mlbRoofdrakWolfhound()
            || !mlbRoofdrakLeadMace()
            || !mlbRoofdrakCanineSense()
            || !mlbRoofdrakCanineHomage()
            || !mlbStraashaWaterKing()
            || !mlbStraashaDoublePower()
            || !mlbStraashaHeatImmune()
            || !mlbStraashaGreenSkin()
            || !mlbStraashaPlusFourToHit()
            || !mlbVampTreeAttachLeaves()
            || !mlbVampTreeFireFears()
            || !mlbVampTreeFirePerDie()
            || !mlbVampTreeNeverSurprised()
            || !mlbThelebPanTangian()
            || !mlbThelebCallsPowers()
            || !mlbThelebBloodOnly()
            || !mlbThelebElricEnemy()
            || !mlbVultureLionChaosFiber()
            || !mlbVultureLionLimboHome()
            || !mlbVultureLionNoMorale()
            || !mlbVultureLionSlaysBadSummoner()
            || !mlbVultureLionFearImmune()
            || !mlbXiombargYoungGirlForm()
            || !mlbXiombargParalyzingHit()
            || !mlbXiombargCravesBlood()
            || !mlbXiombargSacrificeResponse()
            || !mlbYyrkoonEvilPrince()
            || !mlbYyrkoonElricCousin()
            || !mlbYyrkoonAncestorSpells()
            || !mlbYyrkoonMournblade()
        )
            ++bad;
        // the the combat grid grid
        int CmlbCbt[33][9] = {
            {6,-6,45,6,15,2,0,0,72},
            {-2,0,379,18,18,2,0,90,0},
            {2,0,98,12,0,4,0,0,66},
            {-2,0,100,12,24,2,0,90,108},
            {4,0,0,6,18,2,0,25,96},
            {4,0,0,15,0,3,0,0,60},
            {-8,0,300,18,24,2,0,95,240},
            {-6,0,400,15,24,2,0,50,84},
            {6,0,55,12,0,3,2,25,72},
            {-2,0,70,15,0,1,0,95,120},
            {-2,0,176,18,96,2,0,50,0},
            {-5,0,335,18,48,1,0,50,240},
            {-3,0,197,21,0,1,0,75,720},
            {2,0,289,24,0,1,0,50,240},
            {2,0,0,12,0,1,0,0,72},
            {-2,0,152,30,0,3,0,50,240},
            {-6,0,0,9,0,4,0,0,96},
            {-2,0,189,72,0,1,0,50,360},
            {-4,0,80,15,0,1,0,0,252},
            {8,0,0,12,24,1,0,5,72},
            {-2,0,300,12,48,2,0,15,480},
            {-2,0,0,24,0,3,0,25,96},
            {-2,0,200,15,0,0,0,100,240},
            {-2,0,0,12,0,0,0,0,60},
            {-4,0,150,12,0,1,0,85,96},
            {-2,0,250,12,0,6,0,50,120},
            {-2,0,97,18,0,1,0,10,156},
            {-2,0,189,12,36,2,0,50,120},
            {0,0,0,12,0,10,0,0,300},
            {10,0,44,12,0,1,0,0,66},
            {2,0,0,15,0,3,0,25,120},
            {-2,0,376,18,0,2,0,50,60},
            {-4,0,84,12,0,2,0,0,78},
            };
        for (int b = 0;
             b < mlbCbtRows();
             ++b) {
            int vals[9];
            vals[0] = mlbCbtAC(b);
            vals[1] = mlbCbtACAlt(b);
            vals[2] = mlbCbtHP(b);
            vals[3] = mlbCbtMove(b);
            vals[4] = mlbCbtMoveAlt(b);
            vals[5] = mlbCbtAtN(b);
            vals[6] = mlbCbtAtD(b);
            vals[7] = mlbCbtMR(b);
            vals[8] = mlbCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CmlbCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CmlbCls[33][11] = {
            {10,5,15,0,0,19,10,0,10,0,0},
            {20,0,15,0,0,20,20,0,15,0,10},
            {0,0,14,0,0,0,0,13,0,0,5},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,14,20,0,0,15,15,0,0,0,0},
            {20,0,25,0,0,30,30,0,0,15,15},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,15,0,0,0,0,0,0,0,15},
            {99,99,0,0,18,99,99,0,0,0,0},
            {0,0,20,0,0,0,0,0,0,0,0},
            {0,0,18,0,0,99,99,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,14,15,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,18,99,99,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,18,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {99,99,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,15,0,0,10,10,0,0,0,0},
            {0,0,0,0,15,0,0,0,0,0,10},
            {0,0,19,0,0,99,99,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,15,8,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,15,0,0,25,0,0,15,0,0},
            {0,0,15,0,0,17,0,0,0,0,5},
            };
        for (int b = 0;
             b < mlbClsRows();
             ++b) {
            int vals[11];
            vals[0] = mlbClsCleric(b);
            vals[1] = mlbClsDruid(b);
            vals[2] = mlbClsFighterLo(b);
            vals[3] = mlbClsFighterHi(b);
            vals[4] = mlbClsRanger(b);
            vals[5] = mlbClsMagUser(b);
            vals[6] = mlbClsIllus(b);
            vals[7] = mlbClsThief(b);
            vals[8] = mlbClsAssassin(b);
            vals[9] = mlbClsMonk(b);
            vals[10] = mlbClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CmlbCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CmlbAbi[33][9] = {
            {6,0,0,18,17,17,3,18,0},
            {25,7,14,25,21,25,25,0,0},
            {17,1,1,11,9,19,18,15,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,25,13,25,25,16,0},
            {25,7,14,25,25,25,25,25,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {23,0,0,23,23,25,20,23,0},
            {25,7,14,10,10,15,25,13,0},
            {25,0,0,11,3,19,24,4,0},
            {25,7,14,20,8,20,25,7,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,22,13,25,20,21,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,19,13,22,25,10,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {25,0,0,10,3,20,25,-6,0},
            {0,0,0,0,0,0,0,0,0},
            {25,0,0,15,25,15,25,9,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {25,0,0,23,9,18,24,-6,0},
            {23,5,11,20,20,21,22,19,0},
            {25,0,0,15,15,20,25,22,0},
            {0,0,0,0,0,0,0,0,0},
            {12,0,0,18,11,15,17,7,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,23,22,25,24,25,0},
            {16,0,0,18,8,15,17,18,0},
            };
        for (int b = 0;
             b < mlbAbiRows();
             ++b) {
            int vals[9];
            vals[0] = mlbAbiStr(b);
            vals[1] = mlbAbiStrHit(b);
            vals[2] = mlbAbiStrDmg(b);
            vals[3] = mlbAbiInt(b);
            vals[4] = mlbAbiWis(b);
            vals[5] = mlbAbiDex(b);
            vals[6] = mlbAbiCon(b);
            vals[7] = mlbAbiCha(b);
            vals[8] = mlbAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CmlbAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CmlbRos[33][9] = {
            {0,86,8,3,0,0,0,0,0},
            {1,87,8,1,1,2,1,1,0},
            {2,87,4,3,0,0,0,0,0},
            {3,87,8,5,0,0,1,0,0},
            {4,88,8,5,0,0,1,0,0},
            {5,88,4,5,0,0,1,0,0},
            {6,88,7,0,1,1,1,1,0},
            {7,88,0,1,1,2,1,1,0},
            {8,89,4,5,0,0,1,0,1},
            {9,89,4,5,0,0,1,0,1},
            {10,89,5,2,0,7,1,0,0},
            {11,89,4,0,6,3,1,0,0},
            {12,90,4,2,6,8,1,0,0},
            {13,90,5,0,0,4,1,0,0},
            {14,90,5,5,0,0,0,0,0},
            {15,91,5,2,1,9,1,0,0},
            {16,91,8,5,0,0,1,0,0},
            {17,91,4,0,6,5,1,0,0},
            {18,91,5,5,0,0,1,0,0},
            {19,92,1,5,0,0,0,0,0},
            {20,92,4,2,0,10,1,0,0},
            {21,92,4,5,0,0,1,0,0},
            {22,92,4,2,1,11,0,0,0},
            {23,93,5,5,0,0,0,0,0},
            {24,93,8,5,0,0,1,0,0},
            {25,93,8,0,2,1,1,1,0},
            {26,93,4,2,6,12,1,0,0},
            {27,94,4,0,6,6,1,0,0},
            {28,94,7,5,0,0,1,0,0},
            {29,94,6,3,0,0,1,0,0},
            {30,95,5,5,0,0,1,0,0},
            {31,95,8,1,1,2,1,0,0},
            {32,95,8,3,0,0,0,0,0},
            };
        for (int b = 0;
             b < mlbRosRows();
             ++b) {
            int vals[9];
            vals[0] = mlbRosOrd(b);
            vals[1] = mlbRosPage(b);
            vals[2] = mlbRosAlign(b);
            vals[3] = mlbRosRank(b);
            vals[4] = mlbRosPsiClass(b);
            vals[5] = mlbRosPlane(b);
            vals[6] = mlbRosDmgFixed(b);
            vals[7] = mlbRosInEach(b);
            vals[8] = mlbRosEnmity(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CmlbRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the thirty-three beings, the
        // thirteen plane codes, the three in-each kinds... eleven counts)
    if (mlbTableCount() != 4
            || mlbBeingCount() != 33
            || mlbCbtRows() != 33
            || mlbClsRows() != 33
            || mlbAbiRows() != 33
            || mlbRosRows() != 33
            || mlbPlaneCount() != 13
            || mlbGreaterCount() != 3
            || mlbLesserCount() != 6
            || mlbDemigodCount() != 6
            || mlbHeroCount() != 4
            || mlbMonsterCount() != 14
            || mlbInEachCount() != 4
            || mlbEnmityCount() != 2
            || mlbPaladinCount() != 0
            || mlbPsiClassKinds() != 3
            || mlbHalfFootCount() != 3
            || mlbArtifactCount() != 3
            || mlbChainCount() != 0
            || mlbRegistryFloor() != 995
        )
            ++bad;
        // the print walk spans pp. 86-95 and the roster ordinals run 0-32 in
        // print order
    if (mlbPrintStart() != 86
            || mlbPrintEnd() != 95
            || mlbRosPage(0) != 86
            || mlbRosPage(3) != 87
            || mlbRosPage(6) != 88
            || mlbRosPage(10) != 89
            || mlbRosPage(13) != 90
            || mlbRosPage(15) != 91
            || mlbRosPage(19) != 92
            || mlbRosPage(23) != 93
            || mlbRosPage(27) != 94
            || mlbRosPage(30) != 95
            || mlbRosOrd(0) != 0
            || mlbRosOrd(16) != 16
            || mlbRosOrd(32) != 32
        )
            ++bad;
        // Elric the albino emperor: the 6/minus 6 dual armor class, the 6/15
        // Stormbringer move, the 85% magic resistance riding the sword
        // consts, the Ring of Kings percentages
    if (mlbCbtAC(0) != 6
            || mlbCbtACAlt(0) != -6
            || mlbCbtHP(0) != 45
            || mlbCbtMove(0) != 6
            || mlbCbtMoveAlt(0) != 15
            || mlbCbtMR(0) != 0
            || mlbStormbringerMrPct() != 85
            || mlbStormbringerAc() != 6
            || mlbStormbringerPlus() != 5
            || mlbStormbringerSatietyLevels() != 200
            || mlbStormbringerMaxStr() != 23
            || mlbStormbringerDancePct() != 15
            || mlbRingSummonPct() != 70
            || mlbRingControlPct() != 80
            || mlbRingBareSummonPct() != 20
            || mlbRingBareControlPct() != 30
            || mlbElricPotionChancePct() != 85
            || mlbElricPotionStatMax() != 15
        )
            ++bad;
        // Arioch the Duke of Chaos: the minus 2 armor class, the Variable
        // size and charisma pinned 0, the MU/I 20 in-each pair, the 15%
        // dancing chance
    if (mlbCbtAC(1) != -2
            || mlbCbtHP(1) != 379
            || mlbCbtMR(1) != 90
            || mlbCbtSizeIn(1) != 0
            || mlbAbiCha(1) != 0
            || mlbClsMagUser(1) != 20
            || mlbClsIllus(1) != 20
            || mlbRosInEach(1) != 1
            || mlbRosPlane(1) != 2
            || mlbRosPsiClass(1) != 1
            || mlbAriochDancePct() != 15
        )
            ++bad;
        // Moonglum the companion: the 66 fraction cell, the 13th thief, the
        // 5th bard, the four attacks
    if (mlbCbtSizeIn(2) != 66
            || mlbClsThief(2) != 13
            || mlbClsBard(2) != 5
            || mlbCbtAtN(2) != 4
            || mlbAbiDex(2) != 19
        )
            ++bad;
        // the monster XP walk: the fourteen monster rows, the flat-XP pins
        // (Mordagz 6,391, Quaolnargn 21,450, the Assassinator 6,200, Elenoin
        // 1,670, Grahuk 6,650)
    if (mlbAssassinatorHitDice() != 8
            || mlbAssassinatorXpBase() != 6200
            || mlbClakarHitDice() != 6
            || mlbClakarXpBase() != 650
            || mlbClakarXpPerHp() != 10
            || mlbDharziHitDice() != 2
            || mlbDharziXpBase() != 90
            || mlbDharziXpPerHp() != 5
            || mlbElenoinHitDice() != 7
            || mlbElenoinXpBase() != 1670
            || mlbGrahukHitDice() != 8
            || mlbGrahukXpBase() != 6650
            || mlbMistGiantHitDice() != 12
            || mlbMistGiantXpBase() != 4950
            || mlbMistGiantXpPerHp() != 16
            || mlbMordagzHitDice() != 8
            || mlbMordagzXpBase() != 6391
            || mlbMyyrrnHitDice() != 3
            || mlbMyyrrnXpBase() != 125
            || mlbMyyrrnXpPerHp() != 4
            || mlbNihrainHitDice() != 7
            || mlbNihrainXpBase() != 1950
            || mlbNihrainXpPerHp() != 14
            || mlbOonaiHitDice() != 7
            || mlbOonaiXpBase() != 1950
            || mlbOonaiXpPerHp() != 14
            || mlbQuaolnargnHitDice() != 10
            || mlbQuaolnargnXpBase() != 21450
            || mlbVampTreeHitDice() != 8
            || mlbVampTreeXpBase() != 3850
            || mlbVampTreeXpPerHp() != 16
            || mlbVultureLionHitDice() != 9
            || mlbVultureLionXpBase() != 5600
            || mlbVultureLionXpPerHp() != 20
        )
            ++bad;
        // the four elemental lords: Grome the 50th, Kakatal the 30th, Misha
        // and Straasha the 20th; the 16 hit dice elementals; the VI psionic
        // class (Kakatal the fire lord prints Nil psionics)
    if (mlbGromeEarthSpellLevel() != 50
            || mlbKakatalFireSpellLevel() != 30
            || mlbMishaWeatherLevel() != 20
            || mlbStraashaWaterLevel() != 20
            || mlbGromeElementalHd() != 16
            || mlbKakatalElementalHd() != 16
            || mlbMishaElementalHd() != 16
            || mlbRosPsiClass(11) != 6
            || mlbRosPsiClass(13) != 0
            || mlbRosPsiClass(17) != 6
            || mlbRosPsiClass(27) != 6
            || mlbRosPlane(11) != 3
            || mlbRosPlane(13) != 4
            || mlbRosPlane(17) != 5
            || mlbRosPlane(27) != 6
        )
            ++bad;
        // the Elenoin-Grahuk enmity pair: the hereditary enemy flags and the
        // 5% Grahuk appearance
    if (mlbRosEnmity(8) != 1
            || mlbRosEnmity(9) != 1
            || mlbElenoinGrahukPct() != 5
            || mlbGrahukStrength() != 22
            || mlbRosRank(8) != 5
            || mlbRosRank(9) != 5
            || mlbCbtHP(8) != 55
            || mlbCbtHP(9) != 70
        )
            ++bad;
        // Darnizhaan the Dead God and Donblas the Mortifier: the minus 8 and
        // minus 6 armor classes, the 6-60 fists, the rod of three, the 12th
        // level worship threshold
    if (mlbCbtAC(6) != -8
            || mlbCbtMR(6) != 95
            || mlbDarnizhaanFistMax() != 60
            || mlbDarnizhaanDiggerFeet() != 100
            || mlbCbtAC(7) != -6
            || mlbCbtHP(7) != 400
            || mlbDonblasRodDmgMax() != 30
            || mlbDonblasWorshipLevel() != 12
            || mlbRosPlane(6) != 1
            || mlbRosPlane(7) != 2
        )
            ++bad;
        // Fileet the bird master: the bare L size pinned 0, the 18/96
        // airborne move, the 120-foot wingspan, the 1-100 birds, the birds
        // demi-plane
    if (mlbCbtSizeIn(10) != 0
            || mlbCbtMove(10) != 18
            || mlbCbtMoveAlt(10) != 96
            || mlbFileetWingspanFeet() != 120
            || mlbFileetBirdsMax() != 100
            || mlbRosPlane(10) != 7
            || mlbRosRank(10) != 2
        )
            ++bad;
        // the two giants of the round: Haaashastaak the 720 sixty-footer with
        // the never-missing 7-70 bite, Nnuurrr the 480 mosquito with the
        // minus 4 poison save
    if (mlbCbtSizeIn(12) != 720
            || mlbHaaashastaakBiteMax() != 70
            || mlbRosPlane(12) != 8
            || mlbCbtSizeIn(20) != 480
            || mlbNnuurrrPoisonSavePenalty() != 4
            || mlbNnuurrrObeyPct() != 55
            || mlbNnuurrrWingspanFeet() != 140
            || mlbAbiCha(20) != -6
            || mlbRosPlane(20) != 10
        )
            ++bad;
        // Nuru-ah the pacifist: the zero-attack row, the 100% magic
        // resistance, the cattle demi-plane, the See below 99/99 cleric pair
    if (mlbCbtAtN(22) != 0
            || mlbCbtMR(22) != 100
            || mlbRosPlane(22) != 11
            || mlbRosDmgFixed(22) != 0
            || mlbClsCleric(22) != 99
            || mlbClsDruid(22) != 99
            || mlbCbtHP(22) != 200
        )
            ++bad;
        // the Kelmain war band: the See below hit points, the 10-to-10,000
        // troop range, the leader levels 8 down to 2
    if (mlbCbtHP(14) != 0
            || mlbRosDmgFixed(14) != 0
            || mlbKelmainTroopMin() != 10
            || mlbKelmainTroopMax() != 10000
            || mlbKelmainLeaderLevelMax() != 8
            || mlbKelmainLeaderLevelMin() != 2
        )
            ++bad;
        // the Vampire Trees: the 12-hit-dice row, the 300-inch size, the 1-10
        // leaf attacks, the fire save at minus 2
    if (mlbCbtHP(28) != 0
            || mlbCbtSizeIn(28) != 300
            || mlbCbtAtN(28) != 10
            || mlbVampTreeLeafHp() != 2
            || mlbVampTreeLeafAc() != 9
            || mlbVampTreeRangeYards() != 120
            || mlbVampTreeFireSavePenalty() != 2
            || mlbVampTreeLeafControlMax() != 10
        )
            ++bad;
        // the two Chaotic Evil greater gods and the evil cousin: Xiombarg the
        // +4 axe, Yyrkoon the 78 fraction cell, Theleb the minus 10 armor
        // class
    if (mlbXiombargAxePlus() != 4
            || mlbXiombargAxeMax() != 42
            || mlbCbtHP(31) != 376
            || mlbAbiCha(31) != 25
            || mlbCbtSizeIn(32) != 78
            || mlbCbtAC(32) != -4
            || mlbClsMagUser(32) != 17
            || mlbCbtAC(29) != 10
            || mlbCbtSizeIn(29) != 66
            || mlbClsMagUser(29) != 15
            || mlbClsIllus(29) != 8
            || mlbThelebAncestorSpellLevel() != 7
        )
            ++bad;
        // the Stormbringer artifact trio of the intro: the Arrows of Law
        // quiver, the Nanorion Stone thresholds, the Chaos and Law symbols
    if (mlbArrowsOfLawPerQuiver() != 20
            || mlbNanorionHeartPct() != 5
            || mlbNanorionDemonHp() != 80
            || mlbNanorionUsesMax() != 4
            || mlbNanorionClericLevel() != 15
            || mlbChaosArrows() != 8
            || mlbLawArrows() != 1
            || mlbStormbringerFearHd() != 5
            || mlbStormbringerFearFeet() != 30
        )
            ++bad;
        printf("R862 Melnibonean mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
