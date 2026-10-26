    // ---- R859 Greek mythos audit ----
    // THE GREEK MYTHOS - the D&DG walk round eleven, print pp. 63-74. The
    // headline adjudication: the FRACTION FINGERPRINT - the tiny half-height
    // glyphs of the printed "X 1/2 foot" size cells OCR-merge into garbles
    // the earlier rounds misread as X'Y" inch cells; the archive.org
    // 1st-print page pixels (a pure-Python JPEG decode of the BookReader page
    // images, rendered glyph by glyph) settle nine fraction cells - Zeus,
    // Achilles, Aphrodite, Artemis, Bellerophon, Hecate, Hera, Hermes and
    // Hades (the printed 6'1" of the draft was the Hades 6 1/2 fraction, 78
    // inches) - plus the one true inch cell Odysseus 5'4". The merged-column
    // catch: the extract tsv fold swapped the Ares and Athena class lines and
    // the Atlas and Cerberus alignments; the column-split dumps fixed five
    // merged-column errors (Achilles fighter 15 not Nil among them). The
    // psionic decode: the chocr glyph widths (I 9-11px, II 30, III 47, IV 54,
    // V 36, VI 50) settle all forty class cells, Dionysus and Hades the
    // pixel-verified three-pipe class III. The odd prints flagged as pinned:
    // Ares move 26/24, Hades move 29, Hades CH 24(-9), Bellerophon move 12,
    // and the pixel-verified Coeus charisma minus four.
    {
        using namespace rules;
        int bad = 0;
    if (grkRound() != 859
            || grkPrintStart() != 63
            || grkPrintEnd() != 74
            || grkBeingCount() != 40
            || grkTableCount() != 4
            || grkChainCount() != 0
            || grkRegistryFloor() != 995
            || grkCbtRows() != 40
            || grkClsRows() != 40
            || grkAbiRows() != 40
            || grkRosRows() != 40
            || grkPlaneCount() != 7
            || grkHeroCount() != 6
            || grkGreaterCount() != 10
            || grkLesserCount() != 8
            || grkDemigodCount() != 1
            || grkTitanCount() != 6
            || grkMonsterCount() != 9
            || grkInEachCount() != 9
            || grkEnmityCount() != 4
            || grkPaladinCount() != 2
            || grkPsiClassKinds() != 6
            || grkHalfFootCount() != 9
            || grkArtifactCount() != 1
            || grkSpellLossLevels() != 3
            || grkSpellLossDays() != 28
            || grkZeusBoltDamage() != 30
            || grkZeusBloodMonsterLevel() != 6
            || grkZeusBloodHours() != 48
            || grkAegisPlus() != 5
            || grkAegisFearYards() != 10
            || grkEagleXpBase() != 14100
            || grkEagleHitDice() != 16
            || grkAchillesChariotRate() != 24
            || grkAphroditePainDamage() != 10
            || grkAphroditeFemaleCh() != 15
            || grkAphroditeMaleCon() != 16
            || grkAphroditeVengeancePct() != 10
            || grkAntaeusHpBase() != 100
            || grkAntaeusGrowHeal() != 25
            || grkAntaeusHpMax() != 250
            || grkAntaeusXpBase() != 14000
            || grkAntaeusXpPerHp() != 35
            || grkApolloBowPlus() != 4
            || grkApolloArrowPlus() != 3
            || grkApolloCompanionPct() != 60
            || grkApolloHazePlus() != 5
            || grkAresSpearFearYards() != 10
            || grkArtemisRangeYards() != 1000
            || grkBellerophonWatchPct() != 25
            || grkBellerophonSavePct() != 75
            || grkCerberusHeads() != 3
            || grkCerberusHpPerHead() != 30
            || grkCerberusHpBody() != 100
            || grkCerberusRegen() != 5
            || grkCerberusSpittleInches() != 30
            || grkCerberusXpBase() != 26240
            || grkCoeusFearLossPct() != 25
            || grkCoeusApproachYards() != 20
            || grkCoeusSaveRounds() != 4
            || grkCoeusFleeTurns() != 10
            || grkCriusHeavyRoundsMax() != 4
            || grkCriusHitPenalty() != 4
            || grkCriusAcPenalty() != 1
            || grkCyclopsGrHd() != 15
            || grkCyclopsGrBonusHpMax() != 8
            || grkCyclopsGrGiftRewardPct() != 20
            || grkCyclopsGrKillPct() != 80
            || grkCyclopsGrXpBase() != 7800
            || grkCyclopsGrXpPerHp() != 20
            || grkCyclopsLsHd() != 13
            || grkCyclopsLsRockRange() != 50
            || grkCyclopsLsXpBase() != 3950
            || grkCyclopsLsXpPerHp() != 18
            || grkDionysusPantherAc() != 2
            || grkDionysusPantherHd() != 11
            || grkDionysusPantherHp() != 50
            || grkDionysusMadnessSavePenalty() != 4
            || grkEnceladusSpellGrabs() != 4
            || grkEnceladusFearYards() != 100
            || grkEnceladusXpBase() != 21175
            || grkEpimetheusFightPct() != 45
            || grkEpimetheusClayPct() != 5
            || grkEpimetheusBallLevel() != 4
            || grkEpimetheusBetrayPct() != 60
            || grkFuriesCount() != 3
            || grkFuriesHpEach() != 200
            || grkHadesDeathSpells() != 2
            || grkHadesDeathRangeFeet() != 120
            || grkHadesExplosionInches() != 30
            || grkHecateHellHounds() != 9
            || grkHecateHoundPct() != 10
            || grkHecatoncheireArms() != 100
            || grkHecatoncheireHeads() != 50
            || grkHecatoncheireBoulderRange() != 30
            || grkHecatoncheireXpBase() != 29300
            || grkHecatoncheireGrabPct() != 10
            || grkHecatoncheireGrabPerPct() != 1
            || grkHephaestusShieldPct() != 5
            || grkHeraListenPct() != 5
            || grkHeraVoiceDamage() != 20
            || grkHeraVoiceYards() != 50
            || grkHeraclesBowRangeMiles() != 1
            || grkHeraclesRageBonus() != 25
            || grkHermesGraftPct() != 15
            || grkJasonFleeceDeathDays() != 3
            || grkJasonFleeceVanishPct() != 10
            || grkKronosLavaRangeYards() != 200
            || grkPanVoiceYards() != 50
            || grkPanShoutInches() != 100
            || grkPanShoutRounds() != 4
            || grkPanShoutThresholdPct() != 25
            || grkPoseidonTridentPlus() != 5
            || grkPoseidonHazePlus() != 5
            || grkPrometheusCreateRounds() != 2
            || grkPrometheusChainYears() != 30
            || !grkTitansAncestry()
            || !grkWorshipGavePower()
            || !grkThrewDownTitans()
            || !grkMortalTraits()
            || !grkFirstWorshipNatural()
            || !grkCityTemples()
            || !grkCountryNatural()
            || !grkPoseidonClericsRide()
            || !grkNoOtherSects()
            || !grkOneTemple()
            || !grkHighSpellsMeditation()
            || !grkSackedTempleLoss()
            || !grkZeusShapeChange()
            || !grkZeusDisdainsArmor()
            || !grkAegisFear()
            || !grkAegisCloakForm()
            || !grkAegisAthenaCustody()
            || !grkEagleTeleport()
            || !grkEagleTalksToZeus()
            || !grkEagleThunderBolts()
            || !grkEagleMessenger()
            || !grkAchillesEdgedImmune()
            || !grkAchillesBludgeonOnly()
            || !grkAchillesGoldPlated()
            || !grkAphroditeCharmPermanent()
            || !grkAphroditeDoves()
            || !grkAphroditeNewMoon()
            || !grkAphroditeVainJealous()
            || !grkAntaeusGrowsEachRound()
            || !grkAntaeusGrowthHeals()
            || !grkAntaeusEarthHealing()
            || !grkAntaeusLiftedWeakens()
            || !grkApolloShapeChange()
            || !grkApolloLyreStormGiant()
            || !grkApolloLyreCurses()
            || !grkApolloLaurel()
            || !grkApolloSunChariot()
            || !grkAresChainmailPlus5()
            || !grkAresSpearOnlyHeLifts()
            || !grkAresSwordAntiMagic()
            || !grkAresSwordOrSpear()
            || !grkAresBlinkDog()
            || !grkAresAthenaRivalry()
            || !grkArtemisSpellReflect()
            || !grkArtemisHastedAnimal()
            || !grkArtemisFangClawImmune()
            || !grkArtemisAnimalPower()
            || !grkArtemisDruidsOnly()
            || !grkArtemisPureBody()
            || !grkAthenaBlinkDog()
            || !grkAthenaNeverMisses()
            || !grkAthenaMedusaShield()
            || !grkAthenaHelmAntiMagic()
            || !grkAthenaClericsAggressive()
            || !grkAtlasPrimeStrength()
            || !grkAtlasOtherPlaneStrength()
            || !grkAtlasKeepsWord()
            || !grkBellerophonPegasus()
            || !grkCerberusKeepsIn()
            || !grkCerberusNoMagicRemoval()
            || !grkCerberusGazeStone()
            || !grkCerberusPoisonSpittle()
            || !grkCerberusOneFormPerHead()
            || !grkCircePolymorphDevices()
            || !grkCirceProphetic()
            || !grkCirceAlmostImmortal()
            || !grkCoeusDieOfFright()
            || !grkCoeusSwordPlus5()
            || !grkCoeusNightOnly()
            || !grkCriusWeightControl()
            || !grkCriusPermanency()
            || !grkCriusGravityField()
            || !grkCyclopsGrHephaestusGift()
            || !grkCyclopsGrFireImmune()
            || !grkCyclopsGrScaleMail()
            || !grkCyclopsLsHurlRocks()
            || !grkDemeterWeather()
            || !grkDemeterPlantAnimal()
            || !grkDemeterGreenDragons()
            || !grkDemeterGrainDuty()
            || !grkDionysusThyrsusRaise()
            || !grkDionysusThyrsusTeleport()
            || !grkDionysusThyrsusMirror()
            || !grkDionysusFelineControl()
            || !grkDionysusMadness()
            || !grkEnceladusSpellGrab()
            || !grkEnceladusTwoHanded()
            || !grkEnceladusOlympusFoe()
            || !grkEpimetheusCreates()
            || !grkEpimetheusBallCreature()
            || !grkFuriesPunishmentForce()
            || !grkFuriesFindAnyone()
            || !grkFuriesNoAppeal()
            || !grkFuriesWhipDrain()
            || !grkHadesShapeChange()
            || !grkHadesDeathEyes()
            || !grkHadesNonmetalExplosion()
            || !grkHadesEarthControl()
            || !grkHadesChairForgetfulness()
            || !grkHadesChariotUntouchable()
            || !grkHadesHelmInvisible()
            || !grkHadesOneEntrance()
            || !grkHecateAnySpell()
            || !grkHecateNightTwoSpells()
            || !grkHecateTwinSpheres()
            || !grkHecateHoundRapport()
            || !grkHecateFullMoon()
            || !grkHecateThreeFaces()
            || !grkHecatoncheireMeteorSwarm()
            || !grkHecatoncheireTenFists()
            || !grkHecatoncheireOlympusEnemies()
            || !grkHephaestusAdamant()
            || !grkHephaestusShieldAnyClass()
            || !grkHephaestusForgeHelpers()
            || !grkHephaestusDwarfFriend()
            || !grkHephaestusRedDragon()
            || !grkHeraCurse()
            || !grkHeraSpying()
            || !grkHeraClericVengeance()
            || !grkHeraVoiceFear()
            || !grkHeraclesNemeanSkin()
            || !grkHeraclesBerserkerRage()
            || !grkHeraclesBowNeverMiss()
            || !grkHeraclesNoMagicUsers()
            || !grkHermesMaxThieving()
            || !grkHermesBlinkDog()
            || !grkHermesWingedSandals()
            || !grkHermesHelmInvisible()
            || !grkHermesCaduceus()
            || !grkHermesMessenger()
            || !grkHermesArbiter()
            || !grkHermesClericsFit()
            || !grkHermesWhiteRod()
            || !grkJasonGoldenFleece()
            || !grkJasonLeadership()
            || !grkKronosLavaBalls()
            || !grkKronosSickleAdamant()
            || !grkNikeDivineAwe()
            || !grkNikeRodPower()
            || !grkNikeDeviceDestroy()
            || !grkNikeClericStrict()
            || !grkOceanusGreenShimmer()
            || !grkOceanusHurricane()
            || !grkOceanusWaterCommand()
            || !grkOceanusPoseidonOutranks()
            || !grkOdysseusBowOnly()
            || !grkOdysseusWitOverStrength()
            || !grkOdysseusPoseidonCurse()
            || !grkPanTwoAspects()
            || !grkPanVoiceFear()
            || !grkPanSyrinx()
            || !grkPanShout()
            || !grkPanApolloEnemy()
            || !grkPerseusPaladin()
            || !grkPerseusMedusaHead()
            || !grkPerseusHadesHelm()
            || !grkPerseusHermesSandals()
            || !grkPerseusAegis()
            || !grkPoseidonWaterCommand()
            || !grkPoseidonCreateLife()
            || !grkPoseidonCoastAnger()
            || !grkPoseidonHorses()
            || !grkPoseidonPaladinHorse()
            || !grkPoseidonTridentAbsorb()
            || !grkPoseidonWateryHaze()
            || !grkPrometheusClayCreation()
            || !grkPrometheusFireTheft()
            || !grkPrometheusVulture()
            || !grkPrometheusIronRing()
            || !grkPrometheusSelfReliant()
            || !grkPrometheusKillGriffons()
            || !grkTheseusPaladin()
            || !grkTheseusMinotaur()
            || !grkTheseusKnowWeaknesses()
            || !grkTycheGoodLuck()
            || !grkTycheTouchDrain()
            || !grkTycheBlueSphere()
            || !grkTychePoorRelative()
        )
            ++bad;
        // the the combat grid grid
        int CgrkCbt[40][9] = {
            {-2,0,400,18,24,2,0,75,78},
            {2,0,100,6,48,3,0,10,50},
            {0,0,90,18,0,2,0,0,66},
            {4,0,259,12,24,1,0,50,66},
            {4,0,100,15,0,1,0,0,132},
            {1,0,376,15,0,2,0,56,240},
            {-2,0,333,26,24,2,0,59,72},
            {1,0,219,18,0,2,0,0,66},
            {-2,0,329,15,24,2,0,80,72},
            {-3,0,350,24,30,3,0,95,600},
            {4,0,69,12,0,3,2,0,66},
            {1,0,100,24,0,3,0,25,360},
            {10,0,51,12,0,1,0,0,60},
            {2,0,344,24,0,2,0,50,252},
            {-3,0,390,24,0,2,0,50,1200},
            {-4,0,0,15,0,1,0,25,252},
            {2,0,0,15,0,1,0,0,240},
            {1,0,219,15,0,3,2,29,60},
            {4,0,380,15,0,2,0,45,84},
            {1,0,219,15,0,2,0,0,1020},
            {-3,0,345,24,0,2,0,50,1200},
            {-1,0,200,18,24,1,0,100,60},
            {-1,0,390,29,0,2,0,75,78},
            {-2,0,289,12,0,1,0,89,66},
            {5,0,300,15,0,10,0,25,1200},
            {-5,0,312,9,0,2,0,50,240},
            {2,0,300,12,0,3,2,50,66},
            {-2,0,187,15,0,2,0,0,72},
            {2,0,340,18,48,2,0,35,78},
            {3,0,129,12,0,2,0,0,72},
            {2,0,400,24,0,2,0,50,1200},
            {-4,0,357,24,36,2,0,85,84},
            {-3,0,390,24,0,2,0,50,1200},
            {2,0,83,12,0,2,0,0,64},
            {-2,0,359,18,0,3,2,89,60},
            {3,0,112,12,24,2,0,0,72},
            {3,0,390,18,0,2,0,75,360},
            {-2,0,388,15,24,2,0,50,1200},
            {4,0,103,12,0,2,0,0,72},
            {-3,0,200,12,36,1,0,100,60},
            };
        for (int b = 0;
             b < grkCbtRows();
             ++b) {
            int vals[9];
            vals[0] = grkCbtAC(b);
            vals[1] = grkCbtACAlt(b);
            vals[2] = grkCbtHP(b);
            vals[3] = grkCbtMove(b);
            vals[4] = grkCbtMoveAlt(b);
            vals[5] = grkCbtAtN(b);
            vals[6] = grkCbtAtD(b);
            vals[7] = grkCbtMR(b);
            vals[8] = grkCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CgrkCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CgrkCls[40][11] = {
            {25,0,17,0,0,20,20,0,0,0,15},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,15,0,0,0,0,0,0,0,0},
            {10,0,0,0,0,12,15,0,0,0,10},
            {0,0,0,0,0,0,0,0,0,0,0},
            {20,14,0,0,15,15,15,15,0,0,23},
            {0,0,0,0,20,0,10,0,12,12,0},
            {0,14,0,0,16,0,10,0,0,0,5},
            {20,14,20,0,0,12,12,0,0,0,12},
            {0,0,19,0,0,0,0,0,0,10,0},
            {0,0,0,0,10,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {15,0,0,0,0,12,9,0,0,0,5},
            {0,0,16,0,0,15,0,0,0,0,0},
            {15,0,16,0,0,15,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,14,0,0,12,0,15,0,0,0,10},
            {15,0,14,0,0,13,13,0,0,0,19},
            {0,0,0,0,0,0,0,0,0,0,0},
            {10,10,14,0,0,15,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {20,0,15,0,0,0,25,0,15,15,0},
            {0,14,0,0,0,0,0,0,15,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,18,0,0,18,0,0,0,0,0},
            {15,0,10,0,0,12,12,0,0,0,0},
            {0,0,0,0,15,0,0,0,0,0,3},
            {0,14,0,0,15,0,15,25,0,0,15},
            {0,0,0,0,16,0,0,4,0,0,7},
            {25,0,17,0,0,0,0,0,0,0,0},
            {0,0,20,0,0,99,99,0,0,0,0},
            {10,10,15,0,0,0,0,0,0,0,0},
            {0,0,13,0,0,0,0,9,0,0,0},
            {0,14,0,0,13,0,15,15,0,0,15},
            {0,0,15,15,0,0,0,0,0,0,5},
            {12,12,13,0,0,17,17,0,0,0,10},
            {13,13,0,0,16,15,0,10,0,0,10},
            {0,0,13,13,0,0,0,0,0,0,9},
            {0,0,0,0,0,15,15,0,0,0,10},
            };
        for (int b = 0;
             b < grkClsRows();
             ++b) {
            int vals[11];
            vals[0] = grkClsCleric(b);
            vals[1] = grkClsDruid(b);
            vals[2] = grkClsFighterLo(b);
            vals[3] = grkClsFighterHi(b);
            vals[4] = grkClsRanger(b);
            vals[5] = grkClsMagUser(b);
            vals[6] = grkClsIllus(b);
            vals[7] = grkClsThief(b);
            vals[8] = grkClsAssassin(b);
            vals[9] = grkClsMonk(b);
            vals[10] = grkClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CgrkCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CgrkAbi[40][9] = {
            {25,7,14,25,25,25,25,25,0},
            {0,0,0,0,0,0,0,0,0},
            {18,2,3,12,10,18,18,18,0},
            {19,3,7,20,20,23,21,25,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,24,23,25,24,25,0},
            {21,4,9,20,9,25,24,22,0},
            {21,4,9,23,24,24,19,25,0},
            {23,5,11,25,25,22,23,21,0},
            {25,7,14,12,12,20,23,20,0},
            {18,3,6,17,17,18,17,18,0},
            {0,0,0,0,0,0,0,0,0},
            {10,0,0,17,9,17,18,18,0},
            {24,6,12,20,14,20,23,-4,0},
            {25,7,14,23,19,23,23,23,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {21,4,9,24,24,25,21,25,0},
            {24,6,12,22,20,23,25,23,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,21,19,23,22,22,0},
            {0,0,0,0,0,0,0,0,0},
            {24,6,12,24,20,24,25,24,0},
            {12,0,0,25,9,20,22,25,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,25,20,22,23,9,0},
            {17,1,1,20,25,23,23,23,0},
            {25,7,14,11,9,19,20,17,0},
            {22,4,10,25,19,25,24,24,0},
            {18,3,6,16,14,18,18,19,0},
            {25,7,14,25,14,25,25,25,0},
            {23,5,11,23,23,23,24,25,0},
            {25,7,14,24,10,24,25,20,0},
            {18,3,6,18,10,16,17,18,0},
            {25,7,14,18,18,25,25,22,0},
            {18,2,4,14,12,18,18,18,0},
            {25,7,14,20,22,24,25,22,0},
            {24,6,12,25,20,24,24,25,0},
            {18,2,4,18,17,18,18,18,0},
            {20,3,8,25,25,25,22,25,0},
            };
        for (int b = 0;
             b < grkAbiRows();
             ++b) {
            int vals[9];
            vals[0] = grkAbiStr(b);
            vals[1] = grkAbiStrHit(b);
            vals[2] = grkAbiStrDmg(b);
            vals[3] = grkAbiInt(b);
            vals[4] = grkAbiWis(b);
            vals[5] = grkAbiDex(b);
            vals[6] = grkAbiCon(b);
            vals[7] = grkAbiCha(b);
            vals[8] = grkAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CgrkAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CgrkRos[40][9] = {
            {0,63,2,1,2,1,1,1,0},
            {1,63,1,5,0,0,1,0,0},
            {2,64,1,3,0,0,1,0,0},
            {3,64,2,1,6,1,1,0,0},
            {4,64,8,5,0,0,1,0,0},
            {5,64,2,1,1,1,1,1,0},
            {6,65,8,1,5,1,1,0,1},
            {7,65,4,0,5,1,1,0,0},
            {8,65,0,1,6,1,1,1,1},
            {9,66,8,4,5,2,1,0,0},
            {10,66,0,3,0,0,0,0,0},
            {11,66,7,5,0,0,1,0,0},
            {12,66,8,5,0,0,1,0,0},
            {13,67,8,4,5,2,1,0,0},
            {14,67,8,4,5,2,1,0,0},
            {15,67,2,5,0,0,1,0,0},
            {16,67,8,5,0,0,1,0,0},
            {17,68,1,0,6,1,1,0,0},
            {18,68,5,1,3,1,1,0,0},
            {19,68,8,5,0,0,1,0,0},
            {20,68,2,4,5,6,1,1,0},
            {21,69,4,5,5,0,1,0,0},
            {22,69,7,1,3,3,1,0,0},
            {23,69,6,0,1,4,0,0,0},
            {24,69,5,5,0,0,1,0,0},
            {25,70,4,0,4,5,1,0,0},
            {26,70,4,1,6,1,1,1,0},
            {27,70,5,2,0,5,1,0,0},
            {28,71,4,1,4,1,1,0,0},
            {29,71,1,3,0,0,0,0,0},
            {30,72,8,4,5,2,1,0,0},
            {31,72,3,0,6,1,1,0,0},
            {32,72,8,4,5,2,1,1,0},
            {33,72,2,3,0,0,1,0,1},
            {34,73,5,0,1,5,1,0,1},
            {35,73,0,3,0,0,0,0,0},
            {36,73,5,1,6,1,1,1,0},
            {37,74,1,0,5,1,1,1,0},
            {38,74,0,3,0,0,0,0,0},
            {39,74,4,0,1,1,0,1,0},
            };
        for (int b = 0;
             b < grkRosRows();
             ++b) {
            int vals[9];
            vals[0] = grkRosOrd(b);
            vals[1] = grkRosPage(b);
            vals[2] = grkRosAlign(b);
            vals[3] = grkRosRank(b);
            vals[4] = grkRosPsiClass(b);
            vals[5] = grkRosPlane(b);
            vals[6] = grkRosDmgFixed(b);
            vals[7] = grkRosInEach(b);
            vals[8] = grkRosEnmity(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CgrkRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the forty beings, the seven
        // planes, the six heroes)
    if (grkTableCount() != 4
            || grkBeingCount() != 40
            || grkCbtRows() != 40
            || grkClsRows() != 40
            || grkAbiRows() != 40
            || grkRosRows() != 40
            || grkPlaneCount() != 7
            || grkHeroCount() != 6
            || grkGreaterCount() != 10
            || grkLesserCount() != 8
            || grkDemigodCount() != 1
            || grkTitanCount() != 6
            || grkMonsterCount() != 9
            || grkInEachCount() != 9
            || grkEnmityCount() != 4
            || grkPaladinCount() != 2
            || grkPsiClassKinds() != 6
            || grkHalfFootCount() != 9
            || grkArtifactCount() != 1
            || grkChainCount() != 0
            || grkRegistryFloor() != 995
        )
            ++bad;
        // the print walk spans pp. 63-74 and the roster ordinals run 0-39 in
        // print order
    if (grkPrintStart() != 63
            || grkPrintEnd() != 74
            || grkRosPage(0) != 63
            || grkRosPage(2) != 64
            || grkRosPage(6) != 65
            || grkRosPage(9) != 66
            || grkRosPage(13) != 67
            || grkRosPage(17) != 68
            || grkRosPage(21) != 69
            || grkRosPage(25) != 70
            || grkRosPage(28) != 71
            || grkRosPage(30) != 72
            || grkRosPage(34) != 73
            || grkRosPage(37) != 74
            || grkRosOrd(0) != 0
            || grkRosOrd(39) != 39
        )
            ++bad;
        // Zeus the supreme: AC -2, 400 hp, the 6-60 (+14) spear, class II,
        // the 78-inch 6 1/2 foot cell
    if (grkCbtAC(0) != -2
            || grkCbtHP(0) != 400
            || grkRosPsiClass(0) != 2
            || grkCbtSizeIn(0) != 78
            || grkAbiStr(0) != 25
            || grkAbiStrDmg(0) != 14
            || grkClsCleric(0) != 25
            || grkClsIllus(0) != 20
            || grkRosPlane(0) != 1
            || grkZeusBoltDamage() != 30
        )
            ++bad;
        // the White Eagle: the 50-inch wingspan, 3 attacks, xp X/14,100
    if (grkCbtSizeIn(1) != 50
            || grkCbtAtN(1) != 3
            || grkEagleXpBase() != 14100
            || grkEagleHitDice() != 16
            || grkCbtMR(1) != 10
            || grkRosRank(1) != 5
        )
            ++bad;
        // Achilles the hero: AC 0, fighter 15, the 66-inch fraction cell,
        // S:18(51%)(+2,+3)
    if (grkCbtAC(2) != 0
            || grkClsFighterLo(2) != 15
            || grkCbtSizeIn(2) != 66
            || grkAbiStr(2) != 18
            || grkAbiStrHit(2) != 2
            || grkAbiStrDmg(2) != 3
            || grkRosRank(2) != 3
            || grkAchillesChariotRate() != 24
        )
            ++bad;
        // Aphrodite: the 259 hp, MU 12 / illusionist 15, psionic VI, the
        // 66-inch fraction
    if (grkCbtHP(3) != 259
            || grkClsMagUser(3) != 12
            || grkClsIllus(3) != 15
            || grkRosPsiClass(3) != 6
            || grkCbtSizeIn(3) != 66
            || grkAphroditePainDamage() != 10
            || grkAphroditeFemaleCh() != 15
        )
            ++bad;
        // Antaeus the growth giant: the 132-inch floor, the 25-point growth
        // heal, the 250 ceiling
    if (grkCbtSizeIn(4) != 132
            || grkAntaeusGrowHeal() != 25
            || grkAntaeusHpMax() != 250
            || grkAntaeusXpPerHp() != 35
            || grkRosRank(4) != 5
        )
            ++bad;
        // Apollo: 376 hp, MR 56, the L 20 foot 240 cell, psionic I, bard 23
    if (grkCbtHP(5) != 376
            || grkCbtMR(5) != 56
            || grkCbtSizeIn(5) != 240
            || grkRosPsiClass(5) != 1
            || grkClsBard(5) != 23
            || grkClsRanger(5) != 15
            || grkApolloCompanionPct() != 60
        )
            ++bad;
        // Ares the flagged odd print: move 26/24, the ranger 20, assassin 12,
        // monk 12, psionic V
    if (grkCbtMove(6) != 26
            || grkCbtMoveAlt(6) != 24
            || grkClsRanger(6) != 20
            || grkClsAssassin(6) != 12
            || grkClsMonk(6) != 12
            || grkRosPsiClass(6) != 5
            || grkRosEnmity(6) != 1
            || grkAresSpearFearYards() != 10
        )
            ++bad;
        // Artemis: the printed lesser goddess rank 0, the 66-inch fraction,
        // MR See below 0
    if (grkRosRank(7) != 0
            || grkCbtSizeIn(7) != 66
            || grkCbtMR(7) != 0
            || grkClsDruid(7) != 14
            || grkArtemisRangeYards() != 1000
            || grkAbiCha(7) != 25
        )
            ++bad;
        // Athena: fighter 20, MU/I 12 in each, psionic VI, the Ares rivalry
        // enmity
    if (grkClsFighterLo(8) != 20
            || grkClsMagUser(8) != 12
            || grkClsIllus(8) != 12
            || grkRosPsiClass(8) != 6
            || grkRosEnmity(8) != 1
            || grkRosInEach(8) != 1
            || grkCbtMR(8) != 80
        )
            ++bad;
        // Atlas the greater titan: 600 inches, MR 95, plane Tarterus, monk 10
    if (grkCbtSizeIn(9) != 600
            || grkCbtMR(9) != 95
            || grkRosPlane(9) != 2
            || grkClsMonk(9) != 10
            || grkRosRank(9) != 4
            || grkCbtAtN(9) != 3
        )
            ++bad;
        // Bellerophon: the 3/2 attacks, ranger 10, the 66-inch fraction,
        // S:18(00)(+3,+6)
    if (grkCbtAtN(10) != 3
            || grkCbtAtD(10) != 2
            || grkClsRanger(10) != 10
            || grkCbtSizeIn(10) != 66
            || grkAbiStrDmg(10) != 6
            || grkBellerophonWatchPct() != 25
            || grkBellerophonSavePct() != 75
            || grkRosDmgFixed(10) != 0
        )
            ++bad;
        // Cerberus: 3 heads, 30 hp per head, 100 body hp, the 360-inch L 30
        // foot, xp X/26,240
    if (grkCerberusHeads() != 3
            || grkCerberusHpPerHead() != 30
            || grkCerberusHpBody() != 100
            || grkCbtSizeIn(11) != 360
            || grkCerberusXpBase() != 26240
            || grkRosAlign(11) != 7
        )
            ++bad;
        // Circe the black sorceress: AC 10, the 60-inch 5 foot, cleric 15 /
        // MU 12 / illusionist 9
    if (grkCbtAC(12) != 10
            || grkCbtSizeIn(12) != 60
            || grkClsCleric(12) != 15
            || grkClsMagUser(12) != 12
            || grkClsIllus(12) != 9
            || grkAbiStr(12) != 10
            || grkAbiWis(12) != 9
        )
            ++bad;
        // Coeus the fear titan: the pixel-verified charisma -4, the 25
        // percent fear loss, psionic V
    if (grkAbiCha(13) != -4
            || grkCoeusFearLossPct() != 25
            || grkCoeusApproachYards() != 20
            || grkCoeusSaveRounds() != 4
            || grkRosPlane(13) != 2
            || grkCbtSizeIn(13) != 252
        )
            ++bad;
        // Crius the gravity titan: 1200 inches, the -4 hit penalty,
        // S:25(+7,+14)
    if (grkCbtSizeIn(14) != 1200
            || grkCriusHitPenalty() != 4
            || grkCriusAcPenalty() != 1
            || grkAbiStrHit(14) != 7
            || grkRosPsiClass(14) != 5
        )
            ++bad;
        // the two cyclopes: the hit-dice HP 0 rows, the greater -4 AC, the
        // lesser 2
    if (grkCbtHP(15) != 0
            || grkCbtHP(16) != 0
            || grkCyclopsGrHd() != 15
            || grkCyclopsLsHd() != 13
            || grkCbtAC(15) != -4
            || grkCbtAC(16) != 2
            || grkCyclopsGrKillPct() != 80
            || grkRosAlign(15) != 2
            || grkRosAlign(16) != 8
        )
            ++bad;
        // Demeter: the 3/2 attacks, druid 14, psionic VI, the 60-inch cell,
        // MR 29
    if (grkCbtAtN(17) != 3
            || grkCbtAtD(17) != 2
            || grkClsDruid(17) != 14
            || grkRosPsiClass(17) != 6
            || grkCbtMR(17) != 29
            || grkCbtSizeIn(17) != 60
        )
            ++bad;
        // Dionysus: the pixel-verified psionic III (the three pipe bars),
        // 84-inch 7 foot, bard 19
    if (grkRosPsiClass(18) != 3
            || grkCbtSizeIn(18) != 84
            || grkClsBard(18) != 19
            || grkDionysusPantherHp() != 50
            || grkRosRank(18) != 1
            || grkAbiCon(18) != 25
        )
            ++bad;
        // Enceladus: 219 hp, the 1020-inch L 85 foot, the four spell grabs
    if (grkCbtHP(19) != 219
            || grkCbtSizeIn(19) != 1020
            || grkEnceladusSpellGrabs() != 4
            || grkEnceladusXpBase() != 21175
            || grkRosRank(19) != 5
        )
            ++bad;
        // Epimetheus: the Twin Paradises plane 6, the in-each cleric/druid
        // 10, psionic V
    if (grkRosPlane(20) != 6
            || grkClsCleric(20) != 10
            || grkClsDruid(20) != 10
            || grkRosInEach(20) != 1
            || grkRosPsiClass(20) != 5
            || grkEpimetheusBetrayPct() != 60
        )
            ++bad;
        // the Furies: 100 MR, the 200 hp each, psionic V, the ability-drain
        // whips
    if (grkCbtMR(21) != 100
            || grkFuriesHpEach() != 200
            || grkFuriesCount() != 3
            || grkRosPsiClass(21) != 5
            || grkCbtSizeIn(21) != 60
            || grkRosAlign(21) != 4
        )
            ++bad;
        // Hades the flagged odd print: move 29, the pixel-verified psionic
        // III, the 78-inch 6 1/2 foot, the Hades plane
    if (grkCbtMove(22) != 29
            || grkRosPsiClass(22) != 3
            || grkCbtSizeIn(22) != 78
            || grkRosPlane(22) != 3
            || grkClsIllus(22) != 25
            || grkHadesDeathRangeFeet() != 120
            || grkAbiCha(22) != 24
        )
            ++bad;
        // Hecate: the Nine Hells plane 4, assassin 15, psionic I, the 9 hell
        // hounds, the 66-inch fraction
    if (grkRosPlane(23) != 4
            || grkClsAssassin(23) != 15
            || grkRosPsiClass(23) != 1
            || grkHecateHellHounds() != 9
            || grkCbtSizeIn(23) != 66
            || grkAbiInt(23) != 25
        )
            ++bad;
        // the Hecatoncheire: the ten attacks, 100 arms, 50 heads, xp X/29,300
    if (grkCbtAtN(24) != 10
            || grkHecatoncheireArms() != 100
            || grkHecatoncheireHeads() != 50
            || grkHecatoncheireXpBase() != 29300
            || grkCbtSizeIn(24) != 1200
            || grkRosAlign(24) != 5
        )
            ++bad;
        // Hephaestus: AC -5, move 9, the charisma 9 print, the Prime Material
        // plane 5, psionic IV
    if (grkCbtAC(25) != -5
            || grkCbtMove(25) != 9
            || grkAbiCha(25) != 9
            || grkRosPlane(25) != 5
            || grkRosPsiClass(25) != 4
            || grkClsMagUser(25) != 18
            || grkCbtSizeIn(25) != 240
        )
            ++bad;
        // Hera: the in-each MU/I 12, psionic VI, S:17(+1,+1), the voice 20
        // damage
    if (grkClsMagUser(26) != 12
            || grkClsIllus(26) != 12
            || grkRosInEach(26) != 1
            || grkRosPsiClass(26) != 6
            || grkAbiStrHit(26) != 1
            || grkHeraVoiceDamage() != 20
            || grkHeraVoiceYards() != 50
            || grkCbtSizeIn(26) != 66
        )
            ++bad;
        // Heracles the demigod: rank 2, ranger 15, the berserker +25,
        // S:25(+7,+14)
    if (grkRosRank(27) != 2
            || grkClsRanger(27) != 15
            || grkHeraclesRageBonus() != 25
            || grkAbiStr(27) != 25
            || grkClsBard(27) != 3
            || grkRosPlane(27) != 5
        )
            ++bad;
        // Hermes: thief 25, move 18/48, psionic IV, S:22(+4,+10)
    if (grkClsThief(28) != 25
            || grkCbtMoveAlt(28) != 48
            || grkRosPsiClass(28) != 4
            || grkAbiStrDmg(28) != 10
            || grkHermesGraftPct() != 15
            || grkCbtSizeIn(28) != 78
        )
            ++bad;
        // Jason: ranger 16, thief 4, bard 7, the golden fleece 3-day and 10
        // percent cells
    if (grkClsRanger(29) != 16
            || grkClsThief(29) != 4
            || grkClsBard(29) != 7
            || grkJasonFleeceDeathDays() != 3
            || grkJasonFleeceVanishPct() != 10
            || grkRosDmgFixed(29) != 0
        )
            ++bad;
        // Kronos: 400 hp, cleric 25, fighter 17, psionic V, plane Tarterus
    if (grkCbtHP(30) != 400
            || grkClsCleric(30) != 25
            || grkClsFighterLo(30) != 17
            || grkRosPsiClass(30) != 5
            || grkRosPlane(30) != 2
            || grkKronosLavaRangeYards() != 200
            || grkCbtSizeIn(30) != 1200
        )
            ++bad;
        // Nike: AC -4, move 24/36, the MU/I See below 99s, psionic VI, lawful
        // neutral
    if (grkCbtAC(31) != -4
            || grkCbtMoveAlt(31) != 36
            || grkClsMagUser(31) != 99
            || grkClsIllus(31) != 99
            || grkRosPsiClass(31) != 6
            || grkRosAlign(31) != 3
            || grkCbtSizeIn(31) != 84
        )
            ++bad;
        // Oceanus: the in-each cleric/druid 10, fighter 15, S:25(+7,+14), the
        // 10 wisdom
    if (grkClsCleric(32) != 10
            || grkClsDruid(32) != 10
            || grkRosInEach(32) != 1
            || grkClsFighterLo(32) != 15
            || grkAbiWis(32) != 10
            || grkRosPlane(32) != 2
        )
            ++bad;
        // Odysseus: the one true-inch 64 cell, fighter 13, thief 9, the
        // Poseidon-curse enmity
    if (grkCbtSizeIn(33) != 64
            || grkClsFighterLo(33) != 13
            || grkClsThief(33) != 9
            || grkRosEnmity(33) != 1
            || grkAbiInt(33) != 18
            || grkCbtHP(33) != 83
        )
            ++bad;
        // Pan: druid 14, illusionist 15, thief 15, bard 15, psionic I, the
        // Prime Material plane
    if (grkClsDruid(34) != 14
            || grkClsIllus(34) != 15
            || grkClsThief(34) != 15
            || grkClsBard(34) != 15
            || grkRosPsiClass(34) != 1
            || grkRosPlane(34) != 5
            || grkPanShoutRounds() != 4
            || grkRosEnmity(34) != 1
        )
            ++bad;
        // Perseus the paladin: the fighter 15/15 pair, the 25 percent
        // watchman of Bellerophon contrast, the 72-inch 6 foot
    if (grkClsFighterLo(35) != 15
            || grkClsFighterHi(35) != 15
            || grkCbtSizeIn(35) != 72
            || grkClsBard(35) != 5
            || grkAbiStrDmg(35) != 4
        )
            ++bad;
        // Poseidon: the in-each cleric/druid 12 and MU/I 17, the 360-inch L
        // 30 foot, psionic VI
    if (grkClsCleric(36) != 12
            || grkClsDruid(36) != 12
            || grkClsMagUser(36) != 17
            || grkClsIllus(36) != 17
            || grkRosInEach(36) != 1
            || grkCbtSizeIn(36) != 360
            || grkRosPsiClass(36) != 6
            || grkPoseidonTridentPlus() != 5
        )
            ++bad;
        // Prometheus the printed lesser god: rank 0, plane Olympus, the
        // in-each cleric/druid 13, psionic V
    if (grkRosRank(37) != 0
            || grkRosPlane(37) != 1
            || grkClsCleric(37) != 13
            || grkClsDruid(37) != 13
            || grkRosInEach(37) != 1
            || grkRosPsiClass(37) != 5
            || grkPrometheusChainYears() != 30
            || grkCbtSizeIn(37) != 1200
        )
            ++bad;
        // Theseus the paladin: the fighter 13/13 pair, bard 9,
        // S:18(76)(+2,+4)
    if (grkClsFighterLo(38) != 13
            || grkClsFighterHi(38) != 13
            || grkClsBard(38) != 9
            || grkAbiStrHit(38) != 2
            || grkRosDmgFixed(38) != 0
            || grkCbtSizeIn(38) != 72
        )
            ++bad;
        // Tyche: MR 100, psionic I, the in-each MU/I 15, the good luck
        // doctrine
    if (grkCbtMR(39) != 100
            || grkRosPsiClass(39) != 1
            || grkClsMagUser(39) != 15
            || grkClsIllus(39) != 15
            || grkRosInEach(39) != 1
            || grkCbtMoveAlt(39) != 36
            || grkRosDmgFixed(39) != 0
            || grkCbtSizeIn(39) != 60
        )
            ++bad;
        // the Greek doctrine: the spell-loss lunar month and the pantheon
        // worship rules
    if (grkSpellLossLevels() != 3
            || grkSpellLossDays() != 28
            || grkPoseidonTridentPlus() != 5
            || grkZeusBoltDamage() != 30
        )
            ++bad;
        // the monster rows carry no class, ability or psionic cells
    if (grkClsCleric(4) != 0
            || grkClsFighterLo(4) != 0
            || grkAbiStr(4) != 0
            || grkRosPsiClass(4) != 0
            || grkAbiPsi(21) != 0
            || grkClsBard(24) != 0
        )
            ++bad;
        printf("R859 Greek mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
