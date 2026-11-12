    // ---- R858 Finnish mythos audit ----
    // THE FINNISH MYTHOS - the D&DG walk round ten, print pp. 57-62: twenty
    // beings (Vainamoinen, Ahto, the Water Dwarf, Ilmarinen, Hiisi, Ilmatar,
    // Kiputytto, Lemminkainen, Kullervo, Tiera, Louhi, Loviatar, Mielikki,
    // the Son of Pohjola, Surma, Tuonetar, Tuoni, Ukko, Untamo, the Air
    // Maiden), the Kalevala doctrine, and the three magic items (the Great
    // Tree, the Magic Wool, the Rake of Iron). Zero registry defs touched;
    // the floor holds at 995. The adjudications: the KULLERVO TIERA FOLD SWAP
    // (the Termux psm fold interleaved the two stat blocks; the geometry
    // columns plus the clean tsv columns plus the prose settled the swap),
    // the Lemminkainen MOVE 12 (the geometry word against the Termux
    // full-text 15), the Louhi HP 110 (the 81px token too narrow for four
    // glyphs), the Mielikki class I pipe (8px), the Tuonetar CH minus 6 (both
    // voices), the Hiisi W:10 and Kullervo W:6 (both voices agree on the odd
    // prints), the foot-mark size decodes (Lemminkainen 6 foot 2, Kullervo 6
    // foot 1, Tiera 5 foot 4, Mielikki 5 foot 1), the triple-slash moves of
    // Ahto 18/24/24 and Tuoni 18/18/48, and the flagged cells: the Tuonetar
    // fear radius 30 feet (djvu feet against tsv inches), the strength
    // brackets (the Water Dwarf 18(37), Lemminkainen 18(09), the Son of
    // Pohjola 18(00)), and the Loviatar 16(0,+1) bracket.
    {
        using namespace rules;
        int bad = 0;
    if (klvRound() != 858
            || klvPrintStart() != 57
            || klvPrintEnd() != 62
            || klvBeingCount() != 20
            || klvTableCount() != 4
            || klvChainCount() != 0
            || klvRegistryFloor() != 995
            || klvCbtRows() != 20
            || klvClsRows() != 20
            || klvAbiRows() != 20
            || klvRosRows() != 20
            || klvPlaneCount() != 7
            || klvHeroCount() != 6
            || klvServantCount() != 2
            || klvGreaterCount() != 5
            || klvLesserCount() != 4
            || klvDemigodCount() != 3
            || klvArtifactCount() != 3
            || klvPsiClassKinds() != 4
            || klvBardCount() != 13
            || klvTreeArrowsLo() != 1
            || klvTreeArrowsHi() != 10
            || klvTreeSpearPlus() != 1
            || klvWoolSheepCount() != 30
            || klvWoolPerMonth() != 1
            || klvRakeRestLengthInches() != 36
            || klvRakeElongateYards() != 200
            || klvRakeStrokePct() != 10
            || klvVainaAxePlus() != 5
            || klvVainaSwordPlus() != 3
            || klvVainaSwordFearPerDay() != 1
            || klvVainaGirdleStr() != 23
            || klvVainaArmorPlus() != 5
            || klvVainaSummoningLo() != 1
            || klvVainaSummoningHi() != 4
            || klvVainaHorseAC() != 3
            || klvVainaHorseMV() != 24
            || klvVainaHorseHD() != 10
            || klvVainaHorseHp() != 59
            || klvVainaHorseAt() != 3
            || klvVainaHorseDmgHi() != 10
            || klvVainaHorseDmgThirdHi() != 6
            || klvVainaHorseGpLimit() != 300000
            || klvVainaBoatGpLimit() != 60000
            || klvVainaBoatCubicFeet() != 1000
            || klvAhtoSicklePlus() != 4
            || klvAhtoSickleDmgLo() != 2
            || klvAhtoSickleDmgHi() != 20
            || klvAhtoSpellLevel() != 40
            || klvAhtoMRWater() != 100
            || klvAhtoMROtherwise() != 50
            || klvAhtoMoveMid() != 24
            || klvDwarfAidPct() != 25
            || klvDwarfAppearPct() != 100
            || klvDwarfMacePlus() != 3
            || klvDwarfRegen() != 5
            || klvDwarfRegenRangeFeet() != 50
            || klvIlmaHammerPlus() != 4
            || klvIlmaHammerDmgLo() != 1
            || klvIlmaHammerDmgHi() != 10
            || klvIlmaArmorPlus() != 4
            || klvIlmaSledgeRate() != 21
            || klvHiisiClubDmgLo() != 4
            || klvHiisiClubDmgHi() != 40
            || klvHiisiEvilHeroesLo() != 1
            || klvHiisiEvilHeroesHi() != 10
            || klvHiisiEvilHeroAC() != 2
            || klvHiisiEvilHeroLevel() != 4
            || klvIlmatarSledgeRate() != 24
            || klvKipuSicknessHpPerTurn() != 5
            || klvKipuSymbolBowl() != 0
            || klvLemmJavelinPlus() != 3
            || klvLemmJavelinRangeInches() != 36
            || klvLemmBowPlus() != 3
            || klvLemmSwordPlus() != 5
            || klvLemmDaggerPlus() != 3
            || klvLemmChainmailPlus() != 4
            || klvLemmSnowshoeRate() != 24
            || klvKullAxePlus() != 2
            || klvKullAxeDmgLo() != 1
            || klvKullAxeDmgHi() != 10
            || klvTieraSpearPlus() != 3
            || klvTieraSpearDmgLo() != 1
            || klvTieraSpearDmgHi() != 10
            || klvLouhiFighterCount() != 4
            || klvLouhiFighterAC() != 7
            || klvLouhiFighterEffAC() != 3
            || klvLouhiFighterLevel() != 6
            || klvLouhiFighterHp() != 27
            || klvLoviPainExampleHp() != 49
            || klvMielDryadAidPct() != 1
            || klvMielAttackPct() != 5
            || klvMielTreeRatio() != 2
            || klvMielCharmNegateYards() != 30
            || klvSonSwordPlus() != 3
            || klvSonSwordDmgLo() != 2
            || klvSonSwordDmgHi() != 20
            || klvSonWolfAC() != 5
            || klvSonWolfMV() != 18
            || klvSonWolfHD() != 6
            || klvSonWolfHp() != 40
            || klvSonWolfAt() != 1
            || klvSonWolfDmgLo() != 1
            || klvSonWolfDmgHi() != 10
            || klvSurmaClubDmgLo() != 3
            || klvSurmaClubDmgHi() != 30
            || klvTuonetaTouchDmgLo() != 4
            || klvTuonetaTouchDmgHi() != 40
            || klvTuonetaFearRadiusFeet() != 30
            || klvTuoniClubDmgLo() != 3
            || klvTuoniClubDmgHi() != 30
            || klvTuoniMoveMid() != 18
            || klvTuoniReclaimPct() != 1
            || klvUkkoSwordDmgLo() != 3
            || klvUkkoSwordDmgHi() != 30
            || klvUkkoDeathSaveMod() != -6
            || klvUkkoMaidenPct() != 30
            || klvUntaSleepHours() != 13
            || klvUntaServiceYears() != 1
            || klvUntaClubDmgLo() != 3
            || klvUntaClubDmgHi() != 30
            || klvMaidenSwordPlus() != 3
            || klvMaidenFlyRate() != 48
            || klvDwarfStrPct() != 37
            || klvLemmStrPct() != 9
            || klvSonStrPct() != 0
            || !klvKalevalaTheEpic()
            || !klvTalesFocusOnHeroes()
            || !klvHeroesBeyondMortal()
            || !klvMostHaveDivineAncestors()
            || !klvOnlyVainamoinenMeddles()
            || !klvKalevalaVersusPohjola()
            || !klvAllHeroesGreatBards()
            || !klvClericsAboveNormalMen()
            || !klvClericsChastiseWithSpells()
            || !klvTreeFragmentsMakeItems()
            || !klvTreeRawMaterialsOnly()
            || !klvTreeMustBeEnchanted()
            || !klvWoolOfPohjola()
            || !klvWoolRubbedOnFlesh()
            || !klvRakeNeedsApproxLocation()
            || !klvRakeOfLemminkainensMother()
            || !klvVainaGreatestHero()
            || !klvVainaSonOfTheWind()
            || !klvVainaSwordTalks()
            || !klvVainaCrossbowCombo()
            || !klvVainaCrossbowSelfFiring()
            || !klvVainaShapeChange()
            || !klvVainaDispelMagic()
            || !klvVainaCharmImmune()
            || !klvVainaDiseaseImmune()
            || !klvVainaHorseMagicalImmune()
            || !klvVainaHorseLandOrWater()
            || !klvAhtoGodOfSeas()
            || !klvAhtoGreenBearded()
            || !klvAhtoRarelyReveals()
            || !klvAhtoSendsTheWaterDwarf()
            || !klvAhtoSacrificesDeepWater()
            || !klvDwarfAhtosShieldMan()
            || !klvDwarfCrossbowTwiceRate()
            || !klvDwarfSentOnMissions()
            || !klvIlmaBlacksmith()
            || !klvIlmaMassivelyBuilt()
            || !klvIlmaYokesDeer()
            || !klvHiisiGodOfEvil()
            || !klvHiisiHugeRobedMan()
            || !klvHiisiAidsEvilCreatures()
            || !klvHiisiAvoidsDirectBattle()
            || !klvHiisiEvilCannotHurtHim()
            || !klvIlmatarGoddessOfMothers()
            || !klvIlmatarDaughterOfTheAir()
            || !klvIlmatarMotherOfVainamoinen()
            || !klvIlmatarGatesAnyFinnishGod()
            || !klvIlmatarBallOfCreation()
            || !klvIlmatarKnowsAllBeings()
            || !klvKipuGoddessOfSickness()
            || !klvKipuTouchRots()
            || !klvKipuFloatsInvisible()
            || !klvKipuTwistedCrone()
            || !klvKipuCultWastedDisease()
            || !klvKipuHarmingSpellsOnly()
            || !klvLemmJovialReckless()
            || !klvLemmShapeChangeMaster()
            || !klvLemmBeastsWillNotAttack()
            || !klvLemmPoisonImmune()
            || !klvLemmBowAnimalSlaying()
            || !klvLemmSwordSharpnessFlaming()
            || !klvLemmFrostGirdle()
            || !klvLemmBrushShedsBlood()
            || !klvLemmMotherSendsAid()
            || !klvKullervoTheFoil()
            || !klvKullervoShapeChange()
            || !klvKullervoFireImmune()
            || !klvTieraTheShieldMan()
            || !klvTieraAidsHisMaster()
            || !klvLouhiOldCroneOfPohjola()
            || !klvLouhiIronHand()
            || !klvLouhiOpposesTheHeroes()
            || !klvLouhiTwoGuardTwoAttack()
            || !klvLouhiPoisonAndSleepPotions()
            || !klvLoviatarMaidenOfPain()
            || !klvLoviatarColdMaiden()
            || !klvLoviatarColdWindSpeaks()
            || !klvLoviatarInflictsPain()
            || !klvLoviatarDaggerOfIce()
            || !klvLoviatarPainReflection()
            || !klvLoviatarSecondWorstPain()
            || !klvMielikkiMistressOfTheForest()
            || !klvMielikkiGreenGossamer()
            || !klvMielikkiWatchesRangers()
            || !klvMielikkiWildsCannotHurtHer()
            || !klvMielikkiClericalImmune()
            || !klvMielikkiSummonsWolvesAndHawks()
            || !klvSonEvilHero()
            || !klvSonLeaderOfPohjola()
            || !klvSonEnemyOfLemminkainen()
            || !klvSonWolfObeysEveryCommand()
            || !klvSonWolfColdImmune()
            || !klvSonWolfFromLouhi()
            || !klvSurmaDemigodOfDeath()
            || !klvSurmaClubOnlyHeCanWield()
            || !klvSurmaChallengesAll()
            || !klvSurmaKillsRefusersInSleep()
            || !klvSurmaAgingWarrior()
            || !klvTuonetarGoddessOfTheUnderworld()
            || !klvTuonetarUglyCrone()
            || !klvTuonetarFleeUntilExhaustion()
            || !klvTuonetarEnemyOfVainamoinen()
            || !klvTuoniGodOfTheUnderworld()
            || !klvTuoniDarkFurs()
            || !klvTuoniDeathAndPrismaticWall()
            || !klvTuoniDeathCharmImmune()
            || !klvTuoniVisionOnRaise()
            || !klvTuoniClubOnlyHeCanLift()
            || !klvTuoniClericsTakeValuables()
            || !klvUkkoSupremeGod()
            || !klvUkkoTheOldMan()
            || !klvUkkoSupportsGoodHeroes()
            || !klvUkkoMagicAttackFirst()
            || !klvUkkoSkyMaster()
            || !klvUkkoNonintervention()
            || !klvUkkoMaidenAdviseThenRescue()
            || !klvUkkoMaidensOnlyCertainDeath()
            || !klvUntamoGodOfSleep()
            || !klvUntamoVeryMild()
            || !klvUntamoSleepAuraOnContact()
            || !klvUntamoClubSleep()
            || !klvMaidenUkkosWarrior()
            || !klvMaidenWingedLight()
            || !klvMaidenOneAtATime()
            || !klvMaidenTelepathy()
            || !klvMaidenVanishesOnDeath()
            || !klvMaidenReplacedOnDeath()
            || !klvSonStrDoubleZero()
            || !klvLoviStrZeroBracket()
            || !klvVainaPaladin()
            || !klvIlmaPaladin()
            || !klvUkkoPaladin()
            || !klvTieraRanger()
            || !klvMielRanger()
            || !klvSurmaRanger()
            || !klvAhtoInEachMagUser()
            || !klvIlmatarInEachCleric()
            || !klvKiputyttoInEachBoth()
            || !klvLouhiInEachCleric()
            || !klvLoviatarInEachCleric()
            || !klvMielikkiInEachBoth()
            || !klvSurmaInEachBoth()
            || !klvTuonetarInEachMagUser()
            || !klvTuoniInEachMagUser()
            || !klvIlmarinenInEachMagUser()
            || !klvKullervoInEachMagUser()
            || !klvTieraInEachMagUser()
            || klvHiisiInEachCleric()
        )
            ++bad;
        // the the combat grid grid
        int CklvCbt[20][9] = {
            {-4,0,250,15,0,2,0,0,84},
            {-2,0,324,18,24,3,2,50,84},
            {-2,0,99,12,0,2,0,0,48},
            {0,0,167,15,0,2,0,0,72},
            {2,0,333,18,0,2,0,45,84},
            {4,0,200,12,24,1,0,50,60},
            {2,0,189,12,24,1,0,25,60},
            {-2,0,149,12,0,2,0,0,74},
            {1,0,119,15,0,2,0,0,73},
            {4,0,66,12,0,3,2,0,64},
            {8,0,110,9,0,1,0,15,60},
            {2,0,227,24,48,1,0,25,60},
            {4,0,322,-1,0,3,2,50,61},
            {4,0,119,15,0,3,2,0,84},
            {-2,0,224,18,0,2,0,40,72},
            {6,0,340,9,0,1,0,70,60},
            {-2,0,389,18,48,2,0,64,120},
            {-2,0,400,-1,0,2,0,85,84},
            {0,0,319,18,36,3,2,25,84},
            {5,0,85,48,0,2,0,50,72},
            };
        for (int b = 0;
             b < klvCbtRows();
             ++b) {
            int vals[9];
            vals[0] = klvCbtAC(b);
            vals[1] = klvCbtACAlt(b);
            vals[2] = klvCbtHP(b);
            vals[3] = klvCbtMove(b);
            vals[4] = klvCbtMoveAlt(b);
            vals[5] = klvCbtAtN(b);
            vals[6] = klvCbtAtD(b);
            vals[7] = klvCbtMR(b);
            vals[8] = klvCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CklvCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CklvCls[20][11] = {
            {12,0,20,20,0,0,12,0,0,0,23},
            {10,0,12,12,0,15,15,0,0,0,10},
            {0,0,16,16,0,0,0,0,0,0,0},
            {0,5,15,15,0,9,9,0,0,0,15},
            {15,0,15,15,0,0,15,0,15,0,15},
            {13,13,10,10,0,20,0,0,0,0,9},
            {14,14,4,4,0,15,15,0,0,0,0},
            {0,8,18,18,0,10,15,0,0,0,15},
            {0,0,19,19,0,8,8,10,0,0,5},
            {0,0,9,9,0,0,0,0,0,0,5},
            {10,10,0,0,0,15,10,0,0,0,0},
            {12,12,5,5,0,10,15,0,10,0,10},
            {14,14,10,10,0,12,12,0,0,0,12},
            {0,5,12,12,0,0,10,0,8,0,5},
            {14,14,15,15,0,12,12,0,15,0,0},
            {15,0,0,0,0,20,20,0,0,0,5},
            {20,0,15,15,0,15,15,0,0,0,10},
            {20,0,20,20,0,25,0,0,0,0,15},
            {15,0,10,10,0,0,25,0,0,0,10},
            {7,0,16,16,0,7,0,0,0,0,0},
            };
        for (int b = 0;
             b < klvClsRows();
             ++b) {
            int vals[11];
            vals[0] = klvClsCleric(b);
            vals[1] = klvClsDruid(b);
            vals[2] = klvClsFighterLo(b);
            vals[3] = klvClsFighterHi(b);
            vals[4] = klvClsRanger(b);
            vals[5] = klvClsMagUser(b);
            vals[6] = klvClsIllus(b);
            vals[7] = klvClsThief(b);
            vals[8] = klvClsAssassin(b);
            vals[9] = klvClsMonk(b);
            vals[10] = klvClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CklvCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CklvAbi[20][9] = {
            {19,3,7,18,18,24,20,18,0},
            {24,6,12,22,24,22,23,23,0},
            {18,1,3,16,15,18,18,7,0},
            {19,3,7,18,17,18,19,17,0},
            {24,6,12,22,10,21,22,23,0},
            {14,0,0,19,22,20,22,19,0},
            {19,3,7,19,19,19,19,6,0},
            {18,1,3,18,18,18,20,18,0},
            {19,3,7,15,6,18,19,14,0},
            {17,1,1,17,17,17,18,17,0},
            {8,0,0,19,14,18,19,7,0},
            {16,0,1,20,20,16,22,20,0},
            {15,0,0,22,25,19,23,23,0},
            {18,3,6,15,15,19,19,17,0},
            {25,7,14,19,19,23,22,18,0},
            {15,0,0,18,21,17,25,-6,0},
            {25,7,14,20,19,18,24,14,0},
            {25,7,14,24,25,23,25,23,0},
            {19,3,7,25,23,24,24,20,0},
            {19,3,7,19,19,19,19,19,0},
            };
        for (int b = 0;
             b < klvAbiRows();
             ++b) {
            int vals[9];
            vals[0] = klvAbiStr(b);
            vals[1] = klvAbiStrHit(b);
            vals[2] = klvAbiStrDmg(b);
            vals[3] = klvAbiInt(b);
            vals[4] = klvAbiWis(b);
            vals[5] = klvAbiDex(b);
            vals[6] = klvAbiCon(b);
            vals[7] = klvAbiCha(b);
            vals[8] = klvAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CklvAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CklvRos[20][9] = {
            {0,57,0,4,0,0,0,0,0},
            {1,57,1,1,4,2,1,1,0},
            {2,58,0,3,0,0,0,0,0},
            {3,58,1,4,0,0,1,1,0},
            {4,58,8,1,6,1,1,0,0},
            {5,58,0,0,0,1,0,1,0},
            {6,59,8,2,0,3,0,1,0},
            {7,59,1,4,0,0,0,0,0},
            {8,59,5,4,0,0,1,1,1},
            {9,59,0,4,0,0,1,1,0},
            {10,60,6,0,0,0,0,1,1},
            {11,60,6,2,6,4,0,1,0},
            {12,60,1,0,1,1,0,1,0},
            {13,61,6,4,0,0,1,0,1},
            {14,61,7,2,6,3,1,1,0},
            {15,61,8,1,2,5,1,1,1},
            {16,61,5,1,0,5,1,1,0},
            {17,62,0,1,6,6,1,0,0},
            {18,62,4,0,0,7,1,0,0},
            {19,62,0,3,0,0,1,0,0},
            };
        for (int b = 0;
             b < klvRosRows();
             ++b) {
            int vals[9];
            vals[0] = klvRosOrd(b);
            vals[1] = klvRosPage(b);
            vals[2] = klvRosAlign(b);
            vals[3] = klvRosRank(b);
            vals[4] = klvRosPsiClass(b);
            vals[5] = klvRosPlane(b);
            vals[6] = klvRosDmgFixed(b);
            vals[7] = klvRosInEach(b);
            vals[8] = klvRosEnmity(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CklvRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the twenty beings, the seven
        // planes, the six heroes)
    if (klvTableCount() != 4
            || klvBeingCount() != 20
            || klvCbtRows() != 20
            || klvClsRows() != 20
            || klvAbiRows() != 20
            || klvRosRows() != 20
            || klvPlaneCount() != 7
            || klvHeroCount() != 6
            || klvServantCount() != 2
            || klvGreaterCount() != 5
            || klvLesserCount() != 4
            || klvDemigodCount() != 3
            || klvArtifactCount() != 3
            || klvPsiClassKinds() != 4
            || klvChainCount() != 0
            || klvRegistryFloor() != 995
        )
            ++bad;
        // the print walk spans pp. 57-62 and the roster ordinals run 0-19 in
        // print order
    if (klvRosPage(0) != 57
            || klvRosPage(2) != 58
            || klvRosPage(6) != 59
            || klvRosPage(10) != 60
            || klvRosPage(13) != 61
            || klvRosPage(17) != 62
            || klvRosPage(19) != 62
            || klvRosOrd(0) != 0
            || klvRosOrd(19) != 19
            || klvPrintStart() != 57
            || klvPrintEnd() != 62
        )
            ++bad;
        // the alignment walk (the R852 code scheme)
    if (klvRosAlign(0) != 0
            || klvRosAlign(4) != 8
            || klvRosAlign(8) != 5
            || klvRosAlign(10) != 6
            || klvRosAlign(14) != 7
            || klvRosAlign(16) != 5
            || klvRosAlign(18) != 4
            || klvRosAlign(12) != 1
        )
            ++bad;
        // the rank walk (greater, lesser, demigod, servant, hero)
    if (klvRosRank(1) != 1
            || klvRosRank(5) != 0
            || klvRosRank(6) != 2
            || klvRosRank(2) != 3
            || klvRosRank(19) != 3
            || klvRosRank(0) != 4
            || klvRosRank(13) != 4
        )
            ++bad;
        // the psionic class walk (Ahto IV, Tuonetar II, Mielikki the pipe
        // read as I, the four VI readers)
    if (klvRosPsiClass(1) != 4
            || klvRosPsiClass(15) != 2
            || klvRosPsiClass(12) != 1
            || klvRosPsiClass(4) != 6
            || klvRosPsiClass(11) != 6
            || klvRosPsiClass(14) != 6
            || klvRosPsiClass(17) != 6
            || klvRosPsiClass(0) != 0
            || klvRosPsiClass(7) != 0
        )
            ++bad;
        // the plane walk (the seven printed planes; heroes and servants read
        // 0)
    if (klvRosPlane(4) != 1
            || klvRosPlane(1) != 2
            || klvRosPlane(6) != 3
            || klvRosPlane(11) != 4
            || klvRosPlane(15) != 5
            || klvRosPlane(17) != 6
            || klvRosPlane(18) != 7
            || klvRosPlane(0) != 0
            || klvRosPlane(2) != 0
        )
            ++bad;
        // the combat AC walk (the negatives and the odd positives)
    if (klvCbtAC(0) != -4
            || klvCbtAC(7) != -2
            || klvCbtAC(8) != 1
            || klvCbtAC(10) != 8
            || klvCbtAC(19) != 5
            || klvCbtAC(4) != 2
            || klvCbtACAlt(0) != 0
        )
            ++bad;
        // the hit point walk (Ukko 400 down to Tiera 66; the Louhi 110
        // decode)
    if (klvCbtHP(17) != 400
            || klvCbtHP(9) != 66
            || klvCbtHP(10) != 110
            || klvCbtHP(1) != 324
            || klvCbtHP(16) != 389
            || klvCbtHP(12) != 322
            || klvCbtHP(19) != 85
        )
            ++bad;
        // the move walk (the Infinite -1s, the slash ceilings, the
        // Lemminkainen 12 catch)
    if (klvCbtMove(12) != -1
            || klvCbtMove(17) != -1
            || klvCbtMove(7) != 12
            || klvCbtMoveAlt(11) != 48
            || klvCbtMoveAlt(1) != 24
            || klvCbtMoveAlt(16) != 48
            || klvCbtMoveAlt(18) != 36
            || klvCbtMove(10) != 9
            || klvCbtMove(19) != 48
            || klvAhtoMoveMid() != 24
            || klvTuoniMoveMid() != 18
        )
            ++bad;
        // the attack walk (the 3/2 slashes and the single attacks)
    if (klvCbtAtN(1) != 3
            || klvCbtAtD(1) != 2
            || klvCbtAtN(9) != 3
            || klvCbtAtD(9) != 2
            || klvCbtAtN(12) != 3
            || klvCbtAtN(13) != 3
            || klvCbtAtN(18) != 3
            || klvCbtAtN(5) != 1
            || klvCbtAtN(15) != 1
            || klvCbtAtN(17) != 2
        )
            ++bad;
        // the magic resistance walk (0 = the printed Standard; the numeric
        // prints)
    if (klvCbtMR(0) != 0
            || klvCbtMR(2) != 0
            || klvCbtMR(7) != 0
            || klvCbtMR(8) != 0
            || klvCbtMR(9) != 0
            || klvCbtMR(13) != 0
            || klvCbtMR(1) != 50
            || klvCbtMR(4) != 45
            || klvCbtMR(14) != 40
            || klvCbtMR(15) != 70
            || klvCbtMR(16) != 64
            || klvCbtMR(17) != 85
            || klvCbtMR(10) != 15
            || klvAhtoMRWater() != 100
            || klvAhtoMROtherwise() != 50
        )
            ++bad;
        // the size walk (the foot-mark decodes; Tuoni the L 10 foot)
    if (klvCbtSizeIn(7) != 74
            || klvCbtSizeIn(8) != 73
            || klvCbtSizeIn(9) != 64
            || klvCbtSizeIn(12) != 61
            || klvCbtSizeIn(16) != 120
            || klvCbtSizeIn(2) != 48
            || klvCbtSizeIn(17) != 84
            || klvCbtSizeIn(19) != 72
        )
            ++bad;
        // the class walk (the all-heroes-are-bards doctrine and the in-each
        // pairs)
    if (klvClsBard(0) != 23
            || klvClsBard(7) != 15
            || klvClsBard(3) != 15
            || klvClsBard(17) != 15
            || klvClsBard(8) != 5
            || klvClsBard(2) != 0
            || klvBardCount() != 13
        )
            ++bad;
        // the cleric and druid walk (the in-each pairs and the single prints)
    if (klvClsCleric(16) != 20
            || klvClsCleric(17) != 20
            || klvClsCleric(5) != 13
            || klvClsDruid(5) != 13
            || klvClsDruid(3) != 5
            || klvClsDruid(7) != 8
            || klvClsDruid(13) != 5
            || klvClsCleric(6) != 14
            || klvClsDruid(6) != 14
        )
            ++bad;
        // the magic-user and illusionist walk (the Nil MU pairs and the 25th
        // level illusionist)
    if (klvClsMagUser(17) != 25
            || klvClsIllus(18) != 25
            || klvClsIllus(4) != 15
            || klvClsMagUser(4) != 0
            || klvClsIllus(13) != 10
            || klvClsMagUser(13) != 0
            || klvClsMagUser(5) != 20
            || klvClsMagUser(15) != 20
            || klvClsIllus(15) != 20
            || klvClsMagUser(7) != 10
            || klvClsIllus(7) != 15
        )
            ++bad;
        // the thief and assassin walk
    if (klvClsThief(8) != 10
            || klvClsAssassin(4) != 15
            || klvClsAssassin(11) != 10
            || klvClsAssassin(13) != 8
            || klvClsAssassin(14) != 15
            || klvClsThief(9) != 0
        )
            ++bad;
        // the fighter walk (the paladins ride the cols; Kullervo the 19th of
        // the fold swap)
    if (klvClsFighterLo(0) != 20
            || klvClsFighterLo(5) != 10
            || klvClsFighterLo(17) != 20
            || klvClsFighterLo(8) != 19
            || klvClsFighterLo(7) != 18
            || klvClsFighterLo(9) != 9
            || klvClsFighterLo(10) != 0
            || klvClsFighterLo(12) != 10
            || klvClsFighterLo(14) != 15
            || klvClsFighterLo(19) != 16
        )
            ++bad;
        // the ability walk (the fold swap catch lines and the odd prints)
    if (klvAbiStr(8) != 19
            || klvAbiStrHit(8) != 3
            || klvAbiStrDmg(8) != 7
            || klvAbiInt(8) != 15
            || klvAbiWis(8) != 6
            || klvAbiCha(8) != 14
            || klvAbiStr(9) != 17
            || klvAbiStr(10) != 8
            || klvAbiStr(13) != 18
        )
            ++bad;
        // the wisdom and charisma walk (the W:10, the W:6, the negative six)
    if (klvAbiWis(4) != 10
            || klvAbiWis(12) != 25
            || klvAbiCha(15) != -6
            || klvAbiCha(6) != 6
            || klvAbiCha(10) != 7
            || klvAbiCha(2) != 7
            || klvAbiCon(15) != 25
            || klvAbiInt(18) != 25
        )
            ++bad;
        // the strength bracket walk (the percentile prints ride the consts)
    if (klvDwarfStrPct() != 37
            || klvLemmStrPct() != 9
            || klvSonStrPct() != 0
            || klvAbiStrHit(11) != 0
            || klvAbiStrDmg(11) != 1
            || klvAbiStr(14) != 25
            || klvAbiStrHit(14) != 7
            || klvAbiStrDmg(14) != 14
        )
            ++bad;
        // the roster fixed-damage and in-each walk
    if (klvRosDmgFixed(0) != 0
            || klvRosDmgFixed(1) != 1
            || klvRosDmgFixed(15) != 1
            || klvRosDmgFixed(11) != 0
            || klvRosInEach(1) != 1
            || klvRosInEach(6) != 1
            || klvRosInEach(12) != 1
            || klvRosInEach(14) != 1
            || klvRosInEach(4) != 0
            || klvRosInEach(17) != 0
        )
            ++bad;
        // the Pohjola-enmity walk (the four printed enemy lines)
    if (klvRosEnmity(8) != 1
            || klvRosEnmity(10) != 1
            || klvRosEnmity(13) != 1
            || klvRosEnmity(15) != 1
            || klvRosEnmity(0) != 0
            || klvRosEnmity(16) != 0
            || klvRosEnmity(7) != 0
        )
            ++bad;
        // the Vainamoinen walk (the girdle strength, the horse, the boat)
    if (klvVainaGirdleStr() != 23
            || klvVainaHorseHp() != 59
            || klvVainaHorseGpLimit() != 300000
            || klvVainaBoatGpLimit() != 60000
            || klvVainaBoatCubicFeet() != 1000
            || klvVainaSwordPlus() != 3
            || klvVainaAxePlus() != 5
            || klvVainaSummoningHi() != 4
            || klvVainaSwordFearPerDay() != 1
        )
            ++bad;
        // the Ahto walk (the 40th level wind and water casting, the dual
        // magic resistance)
    if (klvAhtoSpellLevel() != 40
            || klvAhtoSicklePlus() != 4
            || klvAhtoSickleDmgHi() != 20
            || klvAhtoSickleDmgLo() != 2
            || klvAhtoMRWater() != 100
            || klvAhtoMROtherwise() != 50
        )
            ++bad;
        // the Water Dwarf and Ilmarinen walk (the aid percentages, the
        // sledge)
    if (klvDwarfAidPct() != 25
            || klvDwarfAppearPct() != 100
            || klvDwarfRegen() != 5
            || klvDwarfRegenRangeFeet() != 50
            || klvIlmaSledgeRate() != 21
            || klvIlmaHammerPlus() != 4
            || klvIlmaHammerDmgHi() != 10
        )
            ++bad;
        // the Hiisi and Ilmatar walk (the evil hero group, the sledge of
        // creation)
    if (klvHiisiEvilHeroesHi() != 10
            || klvHiisiEvilHeroAC() != 2
            || klvHiisiEvilHeroLevel() != 4
            || klvHiisiClubDmgHi() != 40
            || klvIlmatarSledgeRate() != 24
            || klvHiisiClubDmgLo() != 4
        )
            ++bad;
        // the Kiputytto and Louhi walk (the sickness, the invisible fighters)
    if (klvKipuSicknessHpPerTurn() != 5
            || klvLouhiFighterCount() != 4
            || klvLouhiFighterHp() != 27
            || klvLouhiFighterLevel() != 6
            || klvLouhiFighterAC() != 7
            || klvLouhiFighterEffAC() != 3
        )
            ++bad;
        // the Lemminkainen walk (the weapons, the snowshoes, the javelin
        // range)
    if (klvLemmSwordPlus() != 5
            || klvLemmJavelinRangeInches() != 36
            || klvLemmSnowshoeRate() != 24
            || klvLemmChainmailPlus() != 4
            || klvLemmBowPlus() != 3
            || klvLemmDaggerPlus() != 3
        )
            ++bad;
        // the Kullervo and Tiera walk (the fold swap arms)
    if (klvKullAxePlus() != 2
            || klvKullAxeDmgHi() != 10
            || klvTieraSpearPlus() != 3
            || klvTieraSpearDmgLo() != 1
            || klvTieraSpearDmgHi() != 10
        )
            ++bad;
        // the Son of Pohjola walk (the sword and the giant wolf)
    if (klvSonSwordPlus() != 3
            || klvSonSwordDmgHi() != 20
            || klvSonWolfAC() != 5
            || klvSonWolfHp() != 40
            || klvSonWolfHD() != 6
            || klvSonWolfDmgHi() != 10
            || klvSonWolfMV() != 18
        )
            ++bad;
        // the underworld walk (Tuonetar and Tuoni)
    if (klvTuonetaTouchDmgHi() != 40
            || klvTuonetaFearRadiusFeet() != 30
            || klvTuoniClubDmgHi() != 30
            || klvTuoniReclaimPct() != 1
            || klvTuoniClubDmgLo() != 3
        )
            ++bad;
        // the Ukko and Untamo walk (the flaming sword death save, the sleep
        // hours, the year of service)
    if (klvUkkoSwordDmgLo() != 3
            || klvUkkoDeathSaveMod() != -6
            || klvUkkoMaidenPct() != 30
            || klvUntaSleepHours() != 13
            || klvUntaServiceYears() != 1
            || klvUntaClubDmgHi() != 30
        )
            ++bad;
        // the Air Maiden walk (the frost brand, the fly rate)
    if (klvMaidenSwordPlus() != 3
            || klvMaidenFlyRate() != 48
            || klvCbtMR(19) != 50
        )
            ++bad;
        // the artifact walk (the Great Tree, the Magic Wool, the Rake of
        // Iron)
    if (klvTreeArrowsHi() != 10
            || klvTreeArrowsLo() != 1
            || klvTreeSpearPlus() != 1
            || klvWoolSheepCount() != 30
            || klvRakeElongateYards() != 200
            || klvRakeStrokePct() != 10
            || klvRakeRestLengthInches() != 36
            || klvArtifactCount() != 3
        )
            ++bad;
        printf("R858 Finnish mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
