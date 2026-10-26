    // ---- R856 Cthulhu mythos audit ----
    // THE CTHULHU MYTHOS - the D&DG walk round eight, print pp. 43-48:
    // fifteen beings (Cthulhu, Azathoth, Cthugha, the Byakhee servants of
    // Hastur, the Flame Creatures, the Deep Ones, Hastur the Unspeakable, the
    // Great Race, Ithaqua the Wind Walker, the Mi-Go, Nyarlathotep the
    // crawling chaos, the Primordial Ones, the Shoggoths, Shub-Niggurath,
    // Yog-Sothoth), the Old Ones lore with the name-speaking and
    // nature-warning doctrines, and the two artifacts: the Elder Sign and the
    // Necronomicon. Zero registry defs touched; the floor holds at 995. The
    // flagged eyeball cells: the Cthulhu charisma (both voices read 7 with
    // the minus lost in the scrawl - pinned 7), the Cthugha ability line
    // (IA-garbled, the Termux fold pinned: I 12, W 18, CH 1), the Azathoth
    // size (the printed inconceivable, sentinel), the Nyarlathotep size (the
    // printed Variable, sentinel), the Primordial One move (the printed 18/12
    // slash) and the Mi-Go size (the IA 8 feet against the Termux 8 inches).
    {
        using namespace rules;
        int bad = 0;
    if (cthRound() != 856
            || cthPrintStart() != 43
            || cthPrintEnd() != 48
            || cthBeingCount() != 15
            || cthTableCount() != 4
            || cthChainCount() != 0
            || cthRegistryFloor() != 995
            || cthCbtRows() != 15
            || cthClsRows() != 15
            || cthAbiRows() != 15
            || cthRosRows() != 15
            || cthPlaneCount() != 4
            || cthPsiClassI() != 1
            || cthPsiClassIV() != 4
            || cthPsiClassV() != 5
            || cthPsiClassVI() != 6
            || cthArtifactCount() != 2
            || cthLoreNameHeardPct() != 5
            || cthLoreRlyehSaveBonus() != 4
            || cthLoreReleaseRadiusMiles() != 100
            || cthLoreLesserBookCount() != 7
            || cthElderSignAC() != -2
            || cthElderSignProtectionBonus() != 6
            || cthNecronomiconInsanityPct() != 40
            || cthNecronomiconLevelFloor() != 5
            || cthNecronomiconPctDecrement() != 5
            || cthNecronomiconIntReq() != 18
            || cthNecronomiconStudyPct() != 5
            || cthNecronomiconStudyStart() != 6
            || cthNecronomiconSummonInsanityPct() != 30
            || cthCthulhuDmgLo() != 1
            || cthCthulhuDmgHi() != 10
            || cthCthulhuRegen() != 10
            || cthCthulhuTeleportRangeFeet() != 2640
            || cthCthulhuCallDeepOnesLo() != 10
            || cthCthulhuCallDeepOnesHi() != 100
            || cthAzathothDmgLo() != 3
            || cthAzathothDmgHi() != 18
            || cthAzathothAuraMiles() != 1000
            || cthAzathothAuraSaveMod() != -6
            || cthCthughaDmgLo() != 3
            || cthCthughaDmgHi() != 30
            || cthCthughaHeatLo() != 5
            || cthCthughaHeatHi() != 50
            || cthCthughaHeatRangeYards() != 100
            || cthCthughaFireCasterLevel() != 30
            || cthCthughaSpellsPerRound() != 2
            || cthCthughaWeaponPlus() != 3
            || cthCthughaSummonLo() != 1
            || cthCthughaSummonHi() != 20
            || cthByakheeDmgLo() != 1
            || cthByakheeDmgHi() != 10
            || cthByakheeHD() != 10
            || cthByakheeAppearingLo() != 1
            || cthByakheeAppearingHi() != 4
            || cthByakheeLairPct() != 5
            || cthByakheeXpLevel() != 9
            || cthByakheeXpBase() != 9350
            || cthByakheeXpPerHp() != 20
            || cthByakheeGateSummonLo() != 1
            || cthByakheeGateSummonHi() != 4
            || cthFlameDmgLo() != 2
            || cthFlameDmgHi() != 20
            || cthFlameHD() != 16
            || cthFlameAppearingLo() != 1
            || cthFlameAppearingHi() != 4
            || cthFlameHeatDmg() != 10
            || cthFlameHeatRangeYards() != 20
            || cthFlameHeatRayLo() != 2
            || cthFlameHeatRayHi() != 20
            || cthFlameXpLevel() != 7
            || cthFlameXpBase() != 1950
            || cthFlameXpPerHp() != 14
            || cthDeepOnesDmgLo() != 1
            || cthDeepOnesDmgHi() != 4
            || cthDeepOnesWeaponPlus() != 2
            || cthDeepOnesHD() != 4
            || cthDeepOnesAppearingLo() != 1
            || cthDeepOnesAppearingHi() != 100
            || cthDeepOnesLairPct() != 90
            || cthDeepOnesXpLevel() != 3
            || cthDeepOnesXpBase() != 60
            || cthDeepOnesXpPerHp() != 4
            || cthDeepOnesStr() != 18
            || cthDeepOnesTransformAge() != 21
            || cthHasturDmgLo() != 20
            || cthHasturDmgHi() != 200
            || cthHasturTentacles() != 200
            || cthHasturRegen() != 5
            || cthHasturSummonLo() != 2
            || cthHasturSummonHi() != 20
            || cthHasturNameHearPct() != 25
            || cthHasturByakheeLo() != 1
            || cthHasturByakheeHi() != 4
            || cthHasturAppearPct() != 25
            || cthGreatRaceDmgLo() != 1
            || cthGreatRaceDmgHi() != 8
            || cthGreatRaceHD() != 8
            || cthGreatRaceAppearingLo() != 1
            || cthGreatRaceAppearingHi() != 10
            || cthGreatRaceLairPct() != 95
            || cthGreatRaceXpLevel() != 6
            || cthGreatRaceXpBase() != 650
            || cthGreatRaceXpPerHp() != 10
            || cthGreatRacePsiScore() != 280
            || cthGreatRaceConeWidthFeet() != 10
            || cthGreatRaceTentacles() != 4
            || cthGreatRaceTentacleFeet() != 10
            || cthIthaquaDmgLo() != 4
            || cthIthaquaDmgHi() != 40
            || cthIthaquaWeatherMultiplier() != 3
            || cthMiGoDmgLo() != 1
            || cthMiGoDmgHi() != 8
            || cthMiGoHD() != 5
            || cthMiGoAppearingLo() != 2
            || cthMiGoAppearingHi() != 12
            || cthMiGoLairPct() != 40
            || cthMiGoXpLevel() != 4
            || cthMiGoXpBase() != 240
            || cthMiGoXpPerHp() != 5
            || cthMiGoPsiScore() != 90
            || cthMiGoCiliaInches() != 3
            || cthMiGoEyes() != 5
            || cthMiGoMouthTentacles() != 5
            || cthMiGoLegTentacles() != 5
            || cthNyarlathotepDmgLo() != 3
            || cthNyarlathotepDmgHi() != 30
            || cthNyarlathotepGoodSave() != 4
            || cthNyarlathotepEvilSave() != -4
            || cthNyarlathotepArmyLo() != 1
            || cthNyarlathotepArmyHi() != 100
            || cthNyarlathotepArmyHours() != 1
            || cthNyarlathotepDrainLo() != 3
            || cthNyarlathotepDrainHi() != 30
            || cthNyarlathotepDrainTurns() != 1
            || cthNyarlathotepLightRepelPct() != 5
            || cthPrimordialDmgLo() != 1
            || cthPrimordialDmgHi() != 6
            || cthPrimordialHD() != 8
            || cthPrimordialAppearingLo() != 1
            || cthPrimordialAppearingHi() != 8
            || cthPrimordialLairPct() != 95
            || cthPrimordialXpLevel() != 6
            || cthPrimordialXpBase() != 550
            || cthPrimordialXpPerHp() != 10
            || cthPrimordialPsiScore() != 206
            || cthPrimordialAtkTentacles() != 3
            || cthPrimordialEyes() != 5
            || cthPrimordialMouthTentacles() != 5
            || cthPrimordialLegTentacles() != 5
            || cthShoggothDmgLo() != 3
            || cthShoggothDmgHi() != 30
            || cthShoggothHD() != 20
            || cthShoggothAppearingLo() != 1
            || cthShoggothAppearingHi() != 4
            || cthShoggothLairPct() != 90
            || cthShoggothXpLevel() != 9
            || cthShoggothXpBase() != 6500
            || cthShoggothXpPerHp() != 30
            || cthShubPoolDiameterFeet() != 100
            || cthShubSenseRangeInches() != 1000
            || cthShubCreateLo() != 1
            || cthShubCreateHi() != 100
            || cthShubDefendPerMelee() != 1
            || cthShubSummonDie() != 6
            || cthYogDmgLo() != 1
            || cthYogDmgHi() != 8
            || cthYogGatePerMelee() != 1
            || !cthOldOnesFromStars()
            || !cthOldOnesBanished()
            || !cthElderGodsMysterious()
            || !cthForbiddenBooksDangerous()
            || !cthDerlethArkhamHouse()
            || !cthLovecraftIndifferent()
            || !cthNatureCreaturesFlee()
            || !cthInsanityMonthsEqualIntelligence()
            || !cthNameSpeakingGodAppears()
            || !cthNameSpeakingMaySendMinions()
            || !cthCthulhuCultSecret()
            || !cthElderSignGreyStone()
            || !cthElderSignPsionicProof()
            || !cthElderSignDrivesOffMinions()
            || !cthElderSignPlusSixVsMasters()
            || !cthElderSignBrokenByMagicOrForce()
            || !cthElderSignSealedPrisons()
            || !cthNecronomiconAlAzifTitle()
            || !cthNecronomiconMadArab()
            || !cthNecronomiconDevouredByDemons()
            || !cthNecronomiconBannedDestroyed()
            || !cthNecronomiconAlignmentOrMadness()
            || !cthNecronomiconStarsMustBeRight()
            || !cthNecronomiconProtectionFails()
            || !cthNecronomiconSimulacraAppear()
            || !cthLesserBooksWeakerPowers()
            || !cthCthulhuOctopoidHead()
            || !cthCthulhuBatWings()
            || !cthCthulhuSunkenRlyeh()
            || !cthCthulhuNonEuclidian()
            || !cthCthulhuImmuneWaterColdVacuum()
            || !cthCthulhuRetreatElderSign()
            || !cthCthulhuRetreatOldOne()
            || !cthCthulhuRetreatCatastrophe()
            || !cthCthulhuServedByDeepOnes()
            || !cthCthulhuInterbreedingCult()
            || !cthCthulhuFighterAs16HDMonster()
            || !cthAzathothBlindMindless()
            || !cthAzathothAmorphousStar()
            || !cthAzathothFluteMusic()
            || !cthAzathothPseudopodDefense()
            || !cthAzathothClericsInsane()
            || !cthAzathothMaybeUnaware()
            || !cthAzathothFighterAs16HDMonster()
            || !cthCthughaFlamingAmoeba()
            || !cthCthughaClericSeeBelow()
            || !cthCthughaMUSeeBelow()
            || !cthCthughaMovesAsBlinkDog()
            || !cthCthughaImmuneHeatCold()
            || !cthCthughaMeltsWeapons()
            || !cthCthughaPalaceOfFire()
            || !cthCthughaFighterAs16HDMonster()
            || !cthByakheeServantsOfHastur()
            || !cthByakheeBatLike()
            || !cthByakheeHumanoidLegs()
            || !cthByakheeGateSummon()
            || !cthByakheeTeleport()
            || !cthByakheeObeyElderSign()
            || !cthByakheeTelepathic()
            || !cthFlameSmallerVersion()
            || !cthFlameStandInForGod()
            || !cthDeepOnesAmphibious()
            || !cthDeepOnesInfravision()
            || !cthDeepOnesInterbreed()
            || !cthDeepOnesSoullessImmortal()
            || !cthDeepOnesPromoteEvil()
            || !cthDeepOnesTreasureTypeZ()
            || !cthHasturScaledBody()
            || !cthHasturTeleports()
            || !cthHasturFlyersNeverAttack()
            || !cthHasturFearSave()
            || !cthHasturHalfBrotherCthulhu()
            || !cthHasturElderSignImprisoned()
            || !cthHasturCryptLakeHali()
            || !cthHasturPartialElementalAir()
            || !cthHasturNeverFullySolid()
            || !cthHasturFighterAs16HDMonster()
            || !cthGreatRaceScientificPsionics()
            || !cthGreatRaceFrozenInTime()
            || !cthGreatRaceDesertCities()
            || !cthGreatRaceGiftsOfKnowledge()
            || !cthGreatRaceModesBCDEAll()
            || !cthIthaquaFogShape()
            || !cthIthaquaBlazingRedEyes()
            || !cthIthaquaTwoStarsIllusion()
            || !cthIthaquaWeatherControl()
            || !cthIthaquaHumanSacrifice()
            || !cthIthaquaPursuesWitnesses()
            || !cthIthaquaServesHastur()
            || !cthMiGoFungiFromYuggoth()
            || !cthMiGoLobsterLike()
            || !cthMiGoImmuneColdDarkVacuum()
            || !cthMiGoInterstellarFlight()
            || !cthMiGoClickingPincers()
            || !cthMiGoModesCDFGH()
            || !cthNyarlathotepCrawlingChaos()
            || !cthNyarlathotepForetellsReturn()
            || !cthNyarlathotepCharmPresence()
            || !cthNyarlathotepRedBatGuise()
            || !cthNyarlathotepWildBeastArmy()
            || !cthNyarlathotepLightRepel()
            || !cthPrimordialAlienScience()
            || !cthPrimordialHateIntelligence()
            || !cthPrimordialBarrelShape()
            || !cthPrimordialMembranousWings()
            || !cthPrimordialModesBCDAll()
            || !cthShoggothCreatedServants()
            || !cthShoggothRebelled()
            || !cthShoggothShapeAnything()
            || !cthShoggothAidOldOnes()
            || !cthShoggothImmuneWeakness()
            || !cthShubBlackGoatOfTheWoods()
            || !cthShubBubblingPool()
            || !cthShubDevoursOwnSpawn()
            || !cthShubTelepathic()
            || !cthShubTentaclePullStrength()
            || !cthShubAstralTravels()
            || !cthShubFighterAs16HDMonster()
            || !cthYogIridescentGlobes()
            || !cthYogFeltersShape()
            || !cthYogSpawnOfYogSothoth()
            || !cthYogOutsideSpaceTime()
            || !cthYogSimultaneous()
            || !cthYogHighlyChaotic()
        )
            ++bad;
        // the the combat grid grid
        int CcthCbt[15][9] = {
            {2,0,400,18,36,30,0,80,1200},
            {-2,0,400,0,0,20,0,95,0},
            {-6,0,400,36,0,2,0,50,1440},
            {9,0,0,6,24,2,0,20,240},
            {-2,0,0,24,0,1,0,10,360},
            {3,0,0,12,24,2,1,0,72},
            {-2,0,400,36,36,2,0,50,7200},
            {5,0,0,15,0,2,0,0,120},
            {2,0,250,24,0,2,0,30,240},
            {4,0,0,15,30,2,0,0,96},
            {1,0,200,15,0,2,0,25,0},
            {6,0,0,18,12,3,0,0,108},
            {2,0,0,9,0,2,0,30,180},
            {4,0,400,0,0,1,0,95,1200},
            {-2,0,400,18,0,12,0,50,600},
            };
        for (int b = 0;
             b < cthCbtRows();
             ++b) {
            int vals[9];
            vals[0] = cthCbtAC(b);
            vals[1] = cthCbtACAlt(b);
            vals[2] = cthCbtHP(b);
            vals[3] = cthCbtMove(b);
            vals[4] = cthCbtMoveAlt(b);
            vals[5] = cthCbtAtN(b);
            vals[6] = cthCbtAtD(b);
            vals[7] = cthCbtMR(b);
            vals[8] = cthCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CcthCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CcthCls[15][11] = {
            {0,0,0,0,0,20,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {99,0,0,0,0,99,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,23,23,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {13,0,15,15,0,0,12,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {12,12,15,15,0,13,13,0,15,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,15,0,0,0,0,0},
            };
        for (int b = 0;
             b < cthClsRows();
             ++b) {
            int vals[11];
            vals[0] = cthClsCleric(b);
            vals[1] = cthClsDruid(b);
            vals[2] = cthClsFighterLo(b);
            vals[3] = cthClsFighterHi(b);
            vals[4] = cthClsRanger(b);
            vals[5] = cthClsMagUser(b);
            vals[6] = cthClsIllus(b);
            vals[7] = cthClsThief(b);
            vals[8] = cthClsAssassin(b);
            vals[9] = cthClsMonk(b);
            vals[10] = cthClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CcthCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CcthAbi[15][9] = {
            {25,7,14,20,23,20,25,7,0},
            {25,7,14,0,0,20,25,-7,0},
            {25,7,14,12,18,25,25,1,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,22,23,21,23,-4,0},
            {0,0,0,0,0,0,0,0,280},
            {21,4,9,16,13,18,20,-1,0},
            {0,0,0,0,0,0,0,0,90},
            {19,3,7,20,12,19,20,19,0},
            {0,0,0,0,0,0,0,0,206},
            {0,0,0,0,0,0,0,0,0},
            {24,6,12,25,20,19,25,-4,0},
            {25,7,14,25,23,20,25,-7,0},
            };
        for (int b = 0;
             b < cthAbiRows();
             ++b) {
            int vals[9];
            vals[0] = cthAbiStr(b);
            vals[1] = cthAbiStrHit(b);
            vals[2] = cthAbiStrDmg(b);
            vals[3] = cthAbiInt(b);
            vals[4] = cthAbiWis(b);
            vals[5] = cthAbiDex(b);
            vals[6] = cthAbiCon(b);
            vals[7] = cthAbiCha(b);
            vals[8] = cthAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CcthAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CcthRos[15][9] = {
            {0,43,8,1,1,1,1,0,0},
            {1,44,5,1,6,2,1,0,0},
            {2,44,8,1,1,3,1,0,0},
            {3,44,8,3,4,0,1,0,1},
            {4,44,8,3,5,0,1,0,0},
            {5,45,8,3,0,0,1,0,1},
            {6,45,8,1,1,1,1,1,0},
            {7,45,3,3,0,0,1,0,1},
            {8,45,8,2,4,4,1,0,0},
            {9,46,8,3,0,0,1,0,1},
            {10,46,8,0,5,2,1,1,0},
            {11,46,6,3,0,0,1,0,1},
            {12,46,8,3,0,0,1,0,1},
            {13,47,8,0,1,1,0,0,0},
            {14,47,8,1,1,2,1,0,0},
            };
        for (int b = 0;
             b < cthRosRows();
             ++b) {
            int vals[9];
            vals[0] = cthRosOrd(b);
            vals[1] = cthRosPage(b);
            vals[2] = cthRosAlign(b);
            vals[3] = cthRosRank(b);
            vals[4] = cthRosPsiClass(b);
            vals[5] = cthRosPlane(b);
            vals[6] = cthRosDmgFixed(b);
            vals[7] = cthRosInEach(b);
            vals[8] = cthRosSummonList(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CcthRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the fifteen beings, the four
        // planes)
    if (cthTableCount() != 4
            || cthBeingCount() != 15
            || cthCbtRows() != 15
            || cthClsRows() != 15
            || cthAbiRows() != 15
            || cthRosRows() != 15
            || cthPlaneCount() != 4
            || cthArtifactCount() != 2
            || cthChainCount() != 0
            || cthRound() != 856
            || cthPrintStart() != 43
            || cthPrintEnd() != 48
            || cthRegistryFloor() != 995
        )
            ++bad;
        // the print walk spans pp. 43-48 and the roster ordinals run 0-14 in
        // print order
    if (cthRosPage(0) != 43
            || cthRosPage(1) != 44
            || cthRosPage(2) != 44
            || cthRosPage(3) != 44
            || cthRosPage(4) != 44
            || cthRosPage(5) != 45
            || cthRosPage(6) != 45
            || cthRosPage(7) != 45
            || cthRosPage(8) != 45
            || cthRosPage(9) != 46
            || cthRosPage(10) != 46
            || cthRosPage(11) != 46
            || cthRosPage(12) != 46
            || cthRosPage(13) != 47
            || cthRosPage(14) != 47
            || cthRosOrd(0) != 0
            || cthRosOrd(1) != 1
            || cthRosOrd(2) != 2
            || cthRosOrd(3) != 3
            || cthRosOrd(4) != 4
            || cthRosOrd(5) != 5
            || cthRosOrd(6) != 6
            || cthRosOrd(7) != 7
            || cthRosOrd(8) != 8
            || cthRosOrd(9) != 9
            || cthRosOrd(10) != 10
            || cthRosOrd(11) != 11
            || cthRosOrd(12) != 12
            || cthRosOrd(13) != 13
            || cthRosOrd(14) != 14
        )
            ++bad;
        // the combat grid walk: the eight deities and the seven monster rows
    if (cthCbtAC(0) != 2
            || cthCbtAC(1) != -2
            || cthCbtAC(2) != -6
            || cthCbtAC(3) != 9
            || cthCbtAC(4) != -2
            || cthCbtAC(5) != 3
            || cthCbtAC(6) != -2
            || cthCbtAC(7) != 5
            || cthCbtAC(8) != 2
            || cthCbtAC(9) != 4
            || cthCbtAC(10) != 1
            || cthCbtAC(11) != 6
            || cthCbtAC(12) != 2
            || cthCbtAC(13) != 4
            || cthCbtAC(14) != -2
        )
            ++bad;
        // the class grid walk: the level cells
    if (cthClsMagUser(0) != 20
            || cthClsMagUser(6) != 23
            || cthClsIllus(6) != 23
            || cthClsCleric(8) != 13
            || cthClsIllus(8) != 12
            || cthClsCleric(10) != 12
            || cthClsDruid(10) != 12
            || cthClsMagUser(10) != 13
            || cthClsIllus(10) != 13
            || cthClsAssassin(10) != 15
            || cthClsMagUser(14) != 15
            || cthClsCleric(2) != 99
            || cthClsMagUser(2) != 99
        )
            ++bad;
        // the ability grid walk: the S:25 gods and the monster sentinels
    if (cthAbiStr(0) != 25
            || cthAbiStrHit(0) != 7
            || cthAbiStrDmg(0) != 14
            || cthAbiCha(1) != -7
            || cthAbiCha(6) != -4
            || cthAbiCha(8) != -1
            || cthAbiCha(10) != 19
            || cthAbiCha(13) != -4
            || cthAbiCha(14) != -7
            || cthAbiPsi(7) != 280
            || cthAbiPsi(9) != 90
            || cthAbiPsi(11) != 206
            || cthAbiStr(3) != 0
            || cthAbiStr(12) != 0
        )
            ++bad;
        // the roster walk: the ranks, classes, planes and summon-list flags
    if (cthRosRank(0) != 1
            || cthRosRank(8) != 2
            || cthRosRank(10) != 0
            || cthRosRank(13) != 0
            || cthRosPsiClass(1) != 6
            || cthRosPsiClass(3) != 4
            || cthRosPsiClass(4) != 5
            || cthRosPsiClass(10) != 5
            || cthRosPlane(2) != 3
            || cthRosPlane(8) != 4
            || cthRosPlane(1) != 2
            || cthRosDmgFixed(13) != 0
            || cthRosInEach(6) != 1
            || cthRosSummonList(3) != 1
            || cthRosSummonList(5) != 1
            || cthRosSummonList(7) != 1
            || cthRosSummonList(9) != 1
            || cthRosSummonList(11) != 1
            || cthRosSummonList(12) != 1
            || cthRosSummonList(0) != 0
        )
            ++bad;
        // the lore doctrine: the name-speaking 5 percent, the R lyeh saves,
        // the release radius
    if (cthLoreNameHeardPct() != 5
            || cthLoreRlyehSaveBonus() != 4
            || cthLoreReleaseRadiusMiles() != 100
            || cthLoreLesserBookCount() != 7
        )
            ++bad;
        // the Elder Sign walk: the -2 armor class, the +6 protection, the
        // minion drives
    if (cthElderSignAC() != -2
            || cthElderSignProtectionBonus() != 6
        )
            ++bad;
        // the Necronomicon walk: the 40 percent, the -5 per level, the 30th
        // level study, the 30 percent summoning insanity
    if (cthNecronomiconInsanityPct() != 40
            || cthNecronomiconLevelFloor() != 5
            || cthNecronomiconPctDecrement() != 5
            || cthNecronomiconIntReq() != 18
            || cthNecronomiconStudyPct() != 5
            || cthNecronomiconStudyStart() != 6
            || cthNecronomiconSummonInsanityPct() != 30
        )
            ++bad;
        // the Cthulhu walk: the 1-10 x 30 damage, the 10 point regen, the
        // half-mile teleport, the 10-100 Deep Ones
    if (cthCthulhuDmgLo() != 1
            || cthCthulhuDmgHi() != 10
            || cthCthulhuRegen() != 10
            || cthCthulhuTeleportRangeFeet() != 2640
            || cthCthulhuCallDeepOnesLo() != 10
            || cthCthulhuCallDeepOnesHi() != 100
            || cthCbtHP(0) != 400
            || cthCbtAtN(0) != 30
            || cthCbtMR(0) != 80
            || cthCbtSizeIn(0) != 1200
        )
            ++bad;
        // the Cthulhu flagged charisma: both voices read 7, the minus dropped
        // in the scrawl - pinned 7, eyeball
    if (cthAbiCha(0) != 7
            || cthAbiInt(0) != 20
            || cthAbiWis(0) != 23
            || cthAbiDex(0) != 20
            || cthAbiCon(0) != 25
        )
            ++bad;
        // the Azathoth walk: the 3-18 x 20 damage, the 1,000 mile aura at -6,
        // the printed dashes
    if (cthAzathothDmgLo() != 3
            || cthAzathothDmgHi() != 18
            || cthAzathothAuraMiles() != 1000
            || cthAzathothAuraSaveMod() != -6
            || cthCbtMR(1) != 95
            || cthAbiInt(1) != 0
            || cthAbiWis(1) != 0
            || cthCbtSizeIn(1) != 0
        )
            ++bad;
        // the Cthugha walk: the 5-50 heat at 100 yards, the 30th level
        // caster, the +3 weapons, the 1-20 summon
    if (cthCthughaDmgLo() != 3
            || cthCthughaDmgHi() != 30
            || cthCthughaHeatLo() != 5
            || cthCthughaHeatHi() != 50
            || cthCthughaHeatRangeYards() != 100
            || cthCthughaFireCasterLevel() != 30
            || cthCthughaSpellsPerRound() != 2
            || cthCthughaWeaponPlus() != 3
            || cthCthughaSummonLo() != 1
            || cthCthughaSummonHi() != 20
            || cthCthughaDmgLo() != 3
            || cthCbtSizeIn(2) != 1440
        )
            ++bad;
        // the Cthugha flagged ability line: the IA scrawl against the Termux
        // fold - I 12, W 18, D 25, CH 1 pinned, eyeball
    if (cthAbiInt(2) != 12
            || cthAbiWis(2) != 18
            || cthAbiDex(2) != 25
            || cthAbiCha(2) != 1
            || cthAbiCon(2) != 25
        )
            ++bad;
        // the Byakhee walk: 10 hit dice, the IX/9350 + 20 xp line, the 1-4
        // gate, the class IV
    if (cthByakheeDmgLo() != 1
            || cthByakheeDmgHi() != 10
            || cthByakheeHD() != 10
            || cthByakheeAppearingLo() != 1
            || cthByakheeAppearingHi() != 4
            || cthByakheeLairPct() != 5
            || cthByakheeXpLevel() != 9
            || cthByakheeXpBase() != 9350
            || cthByakheeXpPerHp() != 20
            || cthByakheeGateSummonLo() != 1
            || cthByakheeGateSummonHi() != 4
        )
            ++bad;
        // the Flame Creature walk: 16 hit dice, the 10 point heat at 20
        // yards, the 2-20 ray, the VII/1950 + 14
    if (cthFlameDmgLo() != 2
            || cthFlameDmgHi() != 20
            || cthFlameHD() != 16
            || cthFlameHeatDmg() != 10
            || cthFlameHeatRangeYards() != 20
            || cthFlameHeatRayLo() != 2
            || cthFlameHeatRayHi() != 20
            || cthFlameXpLevel() != 7
            || cthFlameXpBase() != 1950
            || cthFlameXpPerHp() != 14
        )
            ++bad;
        // the Deep Ones walk: 4 hit dice, the III/60 + 4 xp line, the 1-100
        // appearing, the strength 18, the age 21
    if (cthDeepOnesDmgLo() != 1
            || cthDeepOnesDmgHi() != 4
            || cthDeepOnesWeaponPlus() != 2
            || cthDeepOnesHD() != 4
            || cthDeepOnesAppearingLo() != 1
            || cthDeepOnesAppearingHi() != 100
            || cthDeepOnesLairPct() != 90
            || cthDeepOnesXpLevel() != 3
            || cthDeepOnesXpBase() != 60
            || cthDeepOnesXpPerHp() != 4
            || cthDeepOnesStr() != 18
            || cthDeepOnesTransformAge() != 21
        )
            ++bad;
        // the Hastur walk: the 20-200 damage, the 200 tentacles, the 5 point
        // regen, the 25 percent name-hear with 1-4 Byakhee
    if (cthHasturDmgLo() != 20
            || cthHasturDmgHi() != 200
            || cthHasturTentacles() != 200
            || cthHasturRegen() != 5
            || cthHasturSummonLo() != 2
            || cthHasturSummonHi() != 20
            || cthHasturNameHearPct() != 25
            || cthHasturByakheeLo() != 1
            || cthHasturByakheeHi() != 4
            || cthHasturAppearPct() != 25
            || cthCbtSizeIn(6) != 7200
        )
            ++bad;
        // the Great Race walk: 8 hit dice, the VI/650 + 10 xp line, the 280
        // point score, the B C D E/All modes
    if (cthGreatRaceDmgLo() != 1
            || cthGreatRaceDmgHi() != 8
            || cthGreatRaceHD() != 8
            || cthGreatRaceAppearingLo() != 1
            || cthGreatRaceAppearingHi() != 10
            || cthGreatRaceLairPct() != 95
            || cthGreatRaceXpLevel() != 6
            || cthGreatRaceXpBase() != 650
            || cthGreatRaceXpPerHp() != 10
            || cthGreatRacePsiScore() != 280
            || cthGreatRaceConeWidthFeet() != 10
            || cthGreatRaceTentacles() != 4
            || cthGreatRaceTentacleFeet() != 10
        )
            ++bad;
        // the Ithaqua walk: the 4-40 damage, the tripled weather, the class
        // IV, the -1 charisma
    if (cthIthaquaDmgLo() != 4
            || cthIthaquaDmgHi() != 40
            || cthIthaquaWeatherMultiplier() != 3
            || cthCbtHP(8) != 250
            || cthAbiCha(8) != -1
        )
            ++bad;
        // the Mi-Go walk: 5 hit dice, the IV/240 + 5 xp line, the 90 point
        // score, the C D/F G H modes, the 3 inch cilia
    if (cthMiGoDmgLo() != 1
            || cthMiGoDmgHi() != 8
            || cthMiGoHD() != 5
            || cthMiGoAppearingLo() != 2
            || cthMiGoAppearingHi() != 12
            || cthMiGoLairPct() != 40
            || cthMiGoXpLevel() != 4
            || cthMiGoXpBase() != 240
            || cthMiGoXpPerHp() != 5
            || cthMiGoPsiScore() != 90
            || cthMiGoCiliaInches() != 3
            || cthMiGoEyes() != 5
            || cthMiGoMouthTentacles() != 5
            || cthMiGoLegTentacles() != 5
        )
            ++bad;
        // the Nyarlathotep walk: the 3-30 damage, the +4/-4 presence saves,
        // the 1-100 army in an hour, the 3-30 drain
    if (cthNyarlathotepDmgLo() != 3
            || cthNyarlathotepDmgHi() != 30
            || cthNyarlathotepGoodSave() != 4
            || cthNyarlathotepEvilSave() != -4
            || cthNyarlathotepArmyLo() != 1
            || cthNyarlathotepArmyHi() != 100
            || cthNyarlathotepArmyHours() != 1
            || cthNyarlathotepDrainLo() != 3
            || cthNyarlathotepDrainHi() != 30
            || cthNyarlathotepDrainTurns() != 1
            || cthNyarlathotepLightRepelPct() != 5
        )
            ++bad;
        // the Primordial One walk: 8 hit dice, the VI/550 + 10 xp line, the
        // 206 point score, the B C D/All modes, the 1-6 x 3 damage
    if (cthPrimordialDmgLo() != 1
            || cthPrimordialDmgHi() != 6
            || cthPrimordialHD() != 8
            || cthPrimordialAppearingLo() != 1
            || cthPrimordialAppearingHi() != 8
            || cthPrimordialLairPct() != 95
            || cthPrimordialXpLevel() != 6
            || cthPrimordialXpBase() != 550
            || cthPrimordialXpPerHp() != 10
            || cthPrimordialPsiScore() != 206
            || cthPrimordialAtkTentacles() != 3
            || cthCbtAtN(11) != 3
        )
            ++bad;
        // the Primordial One flagged move: the printed 18/12 slash (both
        // voices), and the Mi-Go 15/30
    if (cthCbtMove(11) != 18
            || cthCbtMoveAlt(11) != 12
            || cthCbtMove(9) != 15
            || cthCbtMoveAlt(9) != 30
        )
            ++bad;
        // the Shoggoth walk: 20 hit dice, the IX/6500 + 30 xp line, the
        // 3-30/3-30 damage
    if (cthShoggothDmgLo() != 3
            || cthShoggothDmgHi() != 30
            || cthShoggothHD() != 20
            || cthShoggothAppearingLo() != 1
            || cthShoggothAppearingHi() != 4
            || cthShoggothLairPct() != 90
            || cthShoggothXpLevel() != 9
            || cthShoggothXpBase() != 6500
            || cthShoggothXpPerHp() != 30
        )
            ++bad;
        // the Shub-Niggurath walk: the 100 foot pool, the 1,000 inch sense,
        // the 1-100 creation, the d6 table
    if (cthShubPoolDiameterFeet() != 100
            || cthShubSenseRangeInches() != 1000
            || cthShubCreateLo() != 1
            || cthShubCreateHi() != 100
            || cthShubDefendPerMelee() != 1
            || cthShubSummonDie() != 6
            || cthCbtMove(13) != 0
            || cthCbtAtN(13) != 1
        )
            ++bad;
        // the Yog-Sothoth walk: the 12 attacks, the 1-8 damage, the
        // one-per-melee gate, the -7 charisma
    if (cthYogDmgLo() != 1
            || cthYogDmgHi() != 8
            || cthYogGatePerMelee() != 1
            || cthCbtAtN(14) != 12
            || cthAbiCha(14) != -7
            || cthAbiInt(14) != 25
        )
            ++bad;
        // the as-16-plus-HD-monster fighter cells (the five printed gods)
    if (cthCthulhuFighterAs16HDMonster() != 1
            || cthAzathothFighterAs16HDMonster() != 1
            || cthCthughaFighterAs16HDMonster() != 1
            || cthHasturFighterAs16HDMonster() != 1
            || cthShubFighterAs16HDMonster() != 1
        )
            ++bad;
        // the psionic mode lines (the Great Race, Mi-Go and Primordial One)
    if (cthGreatRaceModesBCDEAll() != 1
            || cthMiGoModesCDFGH() != 1
            || cthPrimordialModesBCDAll() != 1
        )
            ++bad;
        printf("R856 Cthulhu mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
