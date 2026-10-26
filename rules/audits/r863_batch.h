    // ---- R863 Nehwon mythos audit ----
    // THE NEHWON MYTHOS - the D&DG walk round fifteen, print pp. 96-104, the
    // Fritz Leiber section: twenty-nine stat-block rows - the four heroes
    // (Fafhrd, the Gray Mouser, Movarl, Pulgh), the two wizards (Ningauble of
    // the Seven Eyes, Sheelba of the Eyeless Face), the two greater gods
    // (Death, Kos), the six lesser gods (the Gods of Trouble, Hate, the
    // Nehwon Earth God, the Rat God, the Red God, Tyaa), the five demigods
    // (Aarth, the Gods of Lankhmar, Issek of the Jug, the Spider God,
    // Votishal) and ten monsters - plus the Lankhmar doctrine of the intro
    // (the Thieves Guild, the Slayers' Brotherhood, the Snow Witches, the
    // Fire Sorcerers of the East, the gems, the Cults of the Beast, the
    // Godsland) and the six outdoor encounter tables of print p. 104 riding
    // as the fifth grid (74 rows). THE HEADLINE ADJUDICATIONS: the
    // QUARTER-FOOT DECODE - the Gray Mouser prints SIZE M (5 1/4 foot), the
    // walk first quarter-cell, pinned 63 inches (the 1eonline voice reads
    // 5.25'); Aarth the half-foot 5 1/2 print pinned 66. The DIVERGENT CELLS
    // pinned by the 2nd-print extract with the L&L parity noted: Death AC -5
    // (L&L -4), the Gods of Trouble AC -2 (L&L -3, tsv-verified minus 2 at
    // w22), Votishal HP 344 (L&L 244, the token confirmed on-page), Tyaa AC
    // the bare-dash print pinned 0 (L&L -3, the w2 dash glyph) and Votishal
    // AC the dash-minus pinned -2 (the Surma dash-token precedent). The ODD
    // PRINTS pinned as printed: the Issek 12/12 dual move (both voices), the
    // Hate printed 0 hit points, the Hate See below MU/I pair pinned 99/99
    // (the egp Isis precedent), the Hate dash W/C/CH ability cells pinned 0,
    // Death the Infinite move minus-1 sentinel, the bird of Tyaa the 1/18
    // move split, Ningauble the Nil attacks, Sheelba the bare M (the R861
    // precedent), the Gods of Trouble the Special magic resistance pinned 0
    // with the 30-foot no-magic radius riding a const, the spider god the
    // 15th level magic-users plural print, and the Devourer the Variable size
    // sentinel. The monster XP romans verified against both voices: III/90+3
    // astral wolf, VIII/4,000+20 behemoth, II/30+1 bird, X/28,500 cold woman
    // flat, II/50+3 ghoul, X/15,800+35 leviathan, VII/2,050+14 snow serpent,
    // III/105+3 salt spider, III/150+4 water cobra. The encounter-table
    // catches: the marsh Men-brigand 21-42 / Men-merchant 43-50 rows restored
    // from the fold-garbled Termux voice via the L&L transcription, and the
    // mountains overlap print (astral wolf 01-05, bird of Tyaa 03-06) pinned
    // as printed. The psionic pipes: the class I of Death, the Gods of
    // Trouble and the Rat God, the class V of the Gods of Lankhmar and
    // Votishal, the class VI of the Nehwon Earth God and the Red God (the
    // w10/w49 calibration). The fraction fingerprint rides the roster: the
    // advisor rivalry pair of Ningauble and Sheelba (the mlb Elenoin-Grahuk
    // precedent).
    {
        using namespace rules;
        int bad = 0;
    if (nhwRound() != 863
            || nhwPrintStart() != 96
            || nhwPrintEnd() != 104
            || nhwBeingCount() != 29
            || nhwTableCount() != 5
            || nhwChainCount() != 0
            || nhwRegistryFloor() != 995
            || nhwCbtRows() != 29
            || nhwClsRows() != 29
            || nhwAbiRows() != 29
            || nhwRosRows() != 29
            || nhwEncRows() != 74
            || nhwEncTables() != 6
            || nhwEncColdRows() != 20
            || nhwEncForestRows() != 12
            || nhwEncMarshRows() != 10
            || nhwEncMtnRows() != 11
            || nhwEncPlainRows() != 12
            || nhwEncWaterRows() != 9
            || nhwPlaneCount() != 3
            || nhwGreaterCount() != 2
            || nhwLesserCount() != 6
            || nhwDemigodCount() != 5
            || nhwHeroCount() != 4
            || nhwWizardCount() != 2
            || nhwMonsterCount() != 10
            || nhwInEachCount() != 3
            || nhwRivalryCount() != 2
            || nhwPaladinCount() != 2
            || nhwPsiRowCount() != 7
            || nhwPsiClassKinds() != 3
            || nhwHalfFootCount() != 2
            || nhwQuarterFootCount() != 1
            || nhwDashAbilityCount() != 3
            || nhwSeeBelowPairCount() != 2
            || nhwDmgFixedCount() != 17
            || nhwHDRowCount() != 7
            || nhwGodslandCount() != 8
            || nhwBeastCount() != 13
            || nhwGuildMasterLevel() != 12
            || nhwGuildMembersLow() != 3
            || nhwGuildMembersHigh() != 24
            || nhwGuildMemberLevel() != 5
            || nhwSlayerLevelLow() != 1
            || nhwSlayerLevelHigh() != 10
            || nhwWitchCovenSize() != 5
            || nhwWitchHours() != 24
            || nhwWitchRangeMiles() != 5
            || nhwFireSorcMult() != 2
            || nhwFireSorcDiv() != 2
            || nhwFafhrdLangPct() != 80
            || nhwFafhrdClimbBonus() != 20
            || nhwMouserThirdStrikePct() != 50
            || nhwAstralWolfHD() != 3
            || nhwWolfPackMin() != 5
            || nhwXpAstralWolfLevel() != 3
            || nhwXpAstralWolfBase() != 90
            || nhwXpAstralWolfPerHp() != 3
            || nhwBehemothHD() != 15
            || nhwXpBehemothLevel() != 8
            || nhwXpBehemothBase() != 4000
            || nhwXpBehemothPerHp() != 20
            || nhwBirdHpLow() != 1
            || nhwBirdHpHigh() != 4
            || nhwBirdClawPoisonPct() != 20
            || nhwXpBirdLevel() != 2
            || nhwXpBirdBase() != 30
            || nhwXpBirdPerHp() != 1
            || nhwGhoulHD() != 3
            || nhwGhoulInvisPct() != 80
            || nhwXpGhoulLevel() != 2
            || nhwXpGhoulBase() != 50
            || nhwXpGhoulPerHp() != 3
            || nhwLeviathanHD() != 40
            || nhwLeviathanTentacles() != 8
            || nhwLeviathanHullDmg() != 30
            || nhwXpLeviathanLevel() != 10
            || nhwXpLeviathanBase() != 15800
            || nhwXpLeviathanPerHp() != 35
            || nhwSnowSerpentHD() != 10
            || nhwConstrictLow() != 3
            || nhwConstrictHigh() != 30
            || nhwXpSnowSerpentLevel() != 7
            || nhwXpSnowSerpentBase() != 2050
            || nhwXpSnowSerpentPerHp() != 14
            || nhwSaltSpiderHD() != 3
            || nhwXpSaltSpiderLevel() != 3
            || nhwXpSaltSpiderBase() != 105
            || nhwXpSaltSpiderPerHp() != 3
            || nhwWaterCobraHD() != 3
            || nhwWaterCobraHDBonus() != 3
            || nhwXpWaterCobraLevel() != 3
            || nhwXpWaterCobraBase() != 150
            || nhwXpWaterCobraPerHp() != 4
            || nhwColdRayRangeIn() != 6
            || nhwColdRayLow() != 7
            || nhwColdRayHigh() != 70
            || nhwColdWomanBiteHd() != 16
            || nhwCorrodeChainRounds() != 1
            || nhwCorrodePlateRounds() != 2
            || nhwCorrodePlusRounds() != 1
            || nhwXpColdWomanLevel() != 10
            || nhwXpColdWomanFlat() != 28500
            || nhwDeathSegments() != 10
            || nhwGodsLankhmarCount() != 3
            || nhwCryptCount() != 13
            || nhwGodsTroubleCount() != 3
            || nhwTroubleNoMagicFeet() != 30
            || nhwHateControlMax() != 6
            || nhwHateWeaponFighterLevel() != 6
            || nhwHatePriestLevel() != 10
            || nhwHateWorshipers() != 100
            || nhwHateTravelMiles() != 5
            || nhwHateCordAC() != -8
            || nhwKosBroadswordPlus() != 6
            || nhwKosBroadLow() != 8
            || nhwKosBroadHigh() != 80
            || nhwKosHonorHp() != 100
            || nhwKosAxePlus() != 3
            || nhwKosAxeLow() != 3
            || nhwKosAxeHigh() != 30
            || nhwKosWeaponDamage() != 50
            || nhwKosBerserkLow() != 9
            || nhwKosBerserkHigh() != 90
            || nhwMovarlEvilSenseFeet() != 20
            || nhwMovarlDmgLow() != 2
            || nhwMovarlDmgHigh() != 20
            || nhwNingaubleEyeCount() != 7
            || nhwPulghSpearPlus() != 3
            || nhwRatGodWererats() != 20
            || nhwSheelbaHutMoveIn() != 24
            || nhwRedGodRingPlus() != 4
            || nhwRedGodSabrePlus() != 3
            || nhwRedGodSabreLow() != 3
            || nhwRedGodSabreHigh() != 30
            || nhwRedGodDirkPlus() != 4
            || nhwRedGodDirkLow() != 1
            || nhwRedGodDirkHigh() != 10
            || nhwRedGodAidLevel() != 8
            || nhwSpiderGodPhaseSpiders() != 30
            || nhwSpiderGodSacrifices() != 10
            || nhwTyaaPredBirds() != 20
            || nhwTyaaBirdsPerDay() != 100
            || nhwTyaaSwordPlus() != 2
            || nhwVotishalClericCap() != 10
            || nhwVotishalPatriarch() != 15
            || nhwVotishalMasterThief() != 12
            || !nhwGodslandAstral()
            || !nhwGemsAnimateDead()
            || !nhwGemsSoulContainers()
            || !nhwBeastControlSpecies()
            || !nhwFafhrdNamesSword()
            || !nhwFafhrdNamesDirk()
            || !nhwFafhrdHandAxe()
            || !nhwFafhrdLongBow()
            || !nhwMouserScalpel()
            || !nhwMouserCatsClaw()
            || !nhwMouserArmedThree()
            || !nhwAarthKnowsDevice()
            || !nhwAarthNegatesDevice()
            || !nhwAarthFightsInvisible()
            || !nhwAstralWolfForceSleep()
            || !nhwBehemothAttacksLargest()
            || !nhwBehemothSnowCousin()
            || !nhwBehemothBlackSpecies()
            || !nhwBirdDivingAttack()
            || !nhwDeathSwordSlays()
            || !nhwDeathKnowsHistory()
            || !nhwDeathMortal()
            || !nhwColdWomanParalyzes()
            || !nhwColdWomanRejoins()
            || !nhwColdWomanLightningSame()
            || !nhwColdWomanColdImmune()
            || !nhwColdWomanEggImplant()
            || !nhwDevourerOtherPlane()
            || !nhwDevourerSellsJunk()
            || !nhwGhoulNotUndead()
            || !nhwGhoulRideHorses()
            || !nhwGodsLankhmarSpellsTwice()
            || !nhwGodsLankhmarStaffWithering()
            || !nhwGodsLankhmarCityThreat()
            || !nhwGodsLankhmarNoClerics()
            || !nhwTroubleGazeFail()
            || !nhwTroubleTeleportAstral()
            || !nhwTroubleHighPriestGaze()
            || !nhwHateMassCharm()
            || !nhwHateNightOnly()
            || !nhwHateCordCutDispels()
            || !nhwHateOnlyHarm()
            || !nhwIssekJugAnyLiquid()
            || !nhwIssekManifestTortured()
            || !nhwIssekPoorSect()
            || !nhwKosSwordIntelligent()
            || !nhwKosCodeOfHonor()
            || !nhwKosSwordRejectsOthers()
            || !nhwLeviathanRetreatsHalf()
            || !nhwLeviathanHullGrapple()
            || !nhwMovarlImmuneFear()
            || !nhwMovarlAvoidsNonEvil()
            || !nhwNingaubleSeesIllusions()
            || !nhwNingaubleCavesLinked()
            || !nhwNingaubleGossiper()
            || !nhwNingaubleNotOfNehwon()
            || !nhwEarthGodNoForgedWeapon()
            || !nhwEarthGodGemCharm()
            || !nhwEarthGodKlesh()
            || !nhwEarthGodMoltenGoal()
            || !nhwPulghExCleric()
            || !nhwPulghShadowy()
            || !nhwRatGodFelinesFlee()
            || !nhwRatGodShrinks()
            || !nhwSheelbaNotOfNehwon()
            || !nhwSheelbaRivalryNingauble()
            || !nhwSheelbaDemonsFlee()
            || !nhwRedGodAntiMagicShell()
            || !nhwRedGodProtectsWorshipers()
            || !nhwSaltSpiderSuctionPads()
            || !nhwSpiderGodArachnidsObey()
            || !nhwSpiderGodGrantsPowers()
            || !nhwTyaaManifestPriestess()
            || !nhwTyaaPoisonedWeapons()
            || !nhwTyaaFalconers()
            || !nhwVotishalKillsEvil()
            || !nhwVotishalAlternatingClerics()
            || !nhwVotishalOpposesGuild()
            || !nhwWaterCobraWaterInvisible()
        )
            ++bad;
        // the the combat grid grid
        int CnhwCbt[29][9] = {
            {3,0,120,12,0,2,0,0,83},
            {2,0,96,12,0,3,2,0,63},
            {2,0,244,18,0,3,2,25,66},
            {3,0,0,18,0,1,0,0,48},
            {4,0,0,12,18,1,0,0,480},
            {7,0,0,1,18,1,0,0,12},
            {-5,0,350,-1,0,10,0,95,84},
            {-2,0,180,9,0,1,0,25,360},
            {7,0,50,15,0,1,0,24,0},
            {10,0,0,12,0,1,0,0,60},
            {3,0,200,9,0,1,0,0,72},
            {-2,0,366,12,24,1,0,0,72},
            {0,0,0,6,0,6,0,25,1080},
            {-3,0,210,12,12,3,2,0,84},
            {-4,0,377,18,0,2,0,35,84},
            {-1,0,0,9,15,8,0,0,3600},
            {2,0,86,12,0,3,2,0,72},
            {-2,0,150,9,0,0,0,0,108},
            {-2,0,300,12,0,1,0,50,180},
            {2,0,72,12,0,2,0,0,72},
            {2,0,222,18,0,2,0,20,120},
            {2,0,150,9,0,1,0,0,0},
            {-2,0,311,18,0,4,0,25,96},
            {6,0,0,9,0,1,0,0,1200},
            {2,0,249,18,0,2,0,10,216},
            {6,0,0,15,18,1,0,0,48},
            {0,0,311,9,36,1,0,32,60},
            {-2,0,344,18,0,3,2,35,72},
            {8,0,0,12,0,1,0,0,48},
            };
        for (int b = 0;
             b < nhwCbtRows();
             ++b) {
            int vals[9];
            vals[0] = nhwCbtAC(b);
            vals[1] = nhwCbtACAlt(b);
            vals[2] = nhwCbtHP(b);
            vals[3] = nhwCbtMove(b);
            vals[4] = nhwCbtMoveAlt(b);
            vals[5] = nhwCbtAtN(b);
            vals[6] = nhwCbtAtD(b);
            vals[7] = nhwCbtMR(b);
            vals[8] = nhwCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CnhwCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CnhwCls[29][11] = {
            {0,0,0,0,15,0,0,13,0,0,5},
            {0,0,11,0,0,3,0,15,0,0,0},
            {15,0,0,10,0,30,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {30,0,0,30,0,30,30,0,15,0,23},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,5,0,0,13,25,10,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {15,0,0,5,0,20,0,0,0,0,0},
            {15,0,0,0,0,20,20,0,15,0,0},
            {0,0,0,0,0,99,99,0,0,0,0},
            {15,0,0,12,0,10,0,0,0,0,15},
            {0,10,0,0,15,20,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,12,0,0,0,0,0,0,0},
            {0,0,0,0,0,20,12,0,0,0,10},
            {0,14,0,15,0,0,0,0,0,0,0},
            {4,0,0,15,0,0,0,0,5,0,0},
            {13,0,0,15,0,0,0,0,12,0,0},
            {0,0,0,0,0,20,5,0,0,10,0},
            {15,0,0,20,0,12,12,0,10,10,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,15,0,15,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {15,0,0,10,0,15,0,0,0,0,0},
            {13,0,0,12,0,15,0,25,0,0,3},
            {0,0,0,0,0,0,0,0,0,0,0},
            };
        for (int b = 0;
             b < nhwClsRows();
             ++b) {
            int vals[11];
            vals[0] = nhwClsCleric(b);
            vals[1] = nhwClsDruid(b);
            vals[2] = nhwClsFighterLo(b);
            vals[3] = nhwClsFighterHi(b);
            vals[4] = nhwClsRanger(b);
            vals[5] = nhwClsMagUser(b);
            vals[6] = nhwClsIllus(b);
            vals[7] = nhwClsThief(b);
            vals[8] = nhwClsAssassin(b);
            vals[9] = nhwClsMonk(b);
            vals[10] = nhwClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CnhwCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CnhwAbi[29][9] = {
            {18,3,6,17,14,18,18,17,0},
            {16,0,0,18,14,19,17,18,0},
            {20,3,8,25,24,25,23,22,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {24,6,12,24,24,24,24,21,0},
            {0,0,0,0,0,0,0,0,0},
            {15,0,0,19,5,17,19,20,0},
            {0,0,0,0,0,0,0,0,0},
            {19,3,7,24,9,20,23,-3,0},
            {12,0,0,23,18,18,23,18,0},
            {10,0,0,10,0,10,0,0,0},
            {25,7,14,23,25,22,24,24,0},
            {25,7,14,24,23,25,24,24,0},
            {0,0,0,0,0,0,0,0,0},
            {18,2,3,14,18,17,18,18,0},
            {14,0,0,19,19,16,19,16,0},
            {25,7,14,10,12,18,25,11,0},
            {17,1,1,14,17,17,16,8,0},
            {20,3,8,18,13,23,19,-6,0},
            {20,3,8,19,10,16,19,7,0},
            {24,6,12,22,17,25,24,24,0},
            {0,0,0,0,0,0,0,0,0},
            {22,4,10,18,9,22,24,-3,0},
            {0,0,0,0,0,0,0,0,0},
            {18,1,2,19,20,25,20,24,0},
            {20,3,8,21,19,25,20,20,0},
            {0,0,0,0,0,0,0,0,0},
            };
        for (int b = 0;
             b < nhwAbiRows();
             ++b) {
            int vals[9];
            vals[0] = nhwAbiStr(b);
            vals[1] = nhwAbiStrHit(b);
            vals[2] = nhwAbiStrDmg(b);
            vals[3] = nhwAbiInt(b);
            vals[4] = nhwAbiWis(b);
            vals[5] = nhwAbiDex(b);
            vals[6] = nhwAbiCon(b);
            vals[7] = nhwAbiCha(b);
            vals[8] = nhwAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CnhwAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CnhwRos[29][9] = {
            {0,96,1,2,0,-1,0,0,0},
            {1,97,4,2,0,-1,0,0,0},
            {2,97,3,3,0,0,0,0,0},
            {3,97,7,5,0,-1,1,0,0},
            {4,97,4,5,0,-1,1,0,0},
            {5,98,7,5,0,-1,1,0,0},
            {6,98,4,1,1,1,0,0,0},
            {7,98,4,5,0,-1,1,0,0},
            {8,98,6,5,0,-1,0,0,0},
            {9,99,7,5,0,-1,1,0,0},
            {10,99,7,3,5,1,1,0,0},
            {11,99,8,0,1,0,0,1,0},
            {12,100,8,0,0,2,0,0,0},
            {13,100,0,3,0,0,1,0,0},
            {14,100,4,1,0,0,1,0,0},
            {15,100,4,5,0,-1,1,0,0},
            {16,101,0,2,0,-1,1,0,0},
            {17,101,4,4,0,-1,0,0,1},
            {18,101,8,0,6,1,0,0,0},
            {19,101,6,2,0,-1,1,0,0},
            {20,102,8,0,1,0,1,0,0},
            {21,102,4,4,0,-1,1,0,1},
            {22,102,4,0,6,0,1,0,0},
            {23,102,4,5,0,-1,1,0,0},
            {24,103,8,3,0,0,1,0,0},
            {25,103,4,5,0,-1,1,0,0},
            {26,103,8,0,0,0,0,0,0},
            {27,103,0,3,5,0,0,0,0},
            {28,104,4,5,0,-1,1,0,0},
            };
        for (int b = 0;
             b < nhwRosRows();
             ++b) {
            int vals[9];
            vals[0] = nhwRosOrd(b);
            vals[1] = nhwRosPage(b);
            vals[2] = nhwRosAlign(b);
            vals[3] = nhwRosRank(b);
            vals[4] = nhwRosPsiClass(b);
            vals[5] = nhwRosPlane(b);
            vals[6] = nhwRosDmgFixed(b);
            vals[7] = nhwRosInEach(b);
            vals[8] = nhwRosRivalry(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CnhwRos[b][c])
                    ++bad;
            }
        }
        // the the encounter grid grid
        int CnhwEnc[74][4] = {
            {1,0,1,2},
            {2,0,3,8},
            {3,0,9,12},
            {4,0,13,17},
            {5,0,18,21},
            {6,0,22,25},
            {7,0,26,31},
            {8,0,32,34},
            {9,0,35,40},
            {10,0,41,43},
            {11,0,44,55},
            {12,0,56,61},
            {13,0,62,65},
            {14,0,66,70},
            {15,0,71,77},
            {16,0,78,82},
            {17,0,83,85},
            {18,0,86,90},
            {19,0,91,96},
            {20,0,97,100},
            {21,1,1,6},
            {22,1,7,9},
            {23,1,10,18},
            {24,1,19,26},
            {25,1,27,34},
            {26,1,35,50},
            {27,1,51,58},
            {28,1,59,66},
            {29,1,67,82},
            {30,1,83,90},
            {31,1,91,96},
            {32,1,97,100},
            {33,2,1,3},
            {34,2,4,15},
            {35,2,16,20},
            {36,2,21,42},
            {37,2,43,50},
            {38,2,51,70},
            {39,2,71,80},
            {40,2,81,85},
            {41,2,86,95},
            {42,2,96,100},
            {43,3,1,5},
            {44,3,3,6},
            {45,3,7,15},
            {46,3,16,24},
            {47,3,25,45},
            {48,3,46,57},
            {49,3,58,66},
            {50,3,67,82},
            {51,3,83,90},
            {52,3,91,96},
            {53,3,97,100},
            {54,4,1,2},
            {55,4,3,7},
            {56,4,8,16},
            {57,4,17,18},
            {58,4,19,27},
            {59,4,28,37},
            {60,4,38,43},
            {61,4,44,52},
            {62,4,53,61},
            {63,4,62,70},
            {64,4,71,90},
            {65,4,91,100},
            {66,5,1,3},
            {67,5,4,15},
            {68,5,16,17},
            {69,5,18,29},
            {70,5,30,39},
            {71,5,40,64},
            {72,5,65,74},
            {73,5,75,86},
            {74,5,87,100},
            };
        for (int b = 0;
             b < nhwEncRows();
             ++b) {
            int vals[4];
            vals[0] = nhwEncOrd(b);
            vals[1] = nhwEncRegion(b);
            vals[2] = nhwEncLow(b);
            vals[3] = nhwEncHigh(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CnhwEnc[b][c])
                    ++bad;
            }
        }
        // the census walk (the five grids, the twenty-nine beings, the six
        // encounter regions... sixteen counts)
    if (nhwTableCount() != 5
            || nhwBeingCount() != 29
            || nhwCbtRows() != 29
            || nhwClsRows() != 29
            || nhwAbiRows() != 29
            || nhwRosRows() != 29
            || nhwEncRows() != 74
            || nhwEncTables() != 6
            || nhwGreaterCount() != 2
            || nhwLesserCount() != 6
            || nhwDemigodCount() != 5
            || nhwHeroCount() != 4
            || nhwWizardCount() != 2
            || nhwMonsterCount() != 10
            || nhwInEachCount() != 3
            || nhwRivalryCount() != 2
            || nhwPaladinCount() != 2
            || nhwPsiClassKinds() != 3
            || nhwQuarterFootCount() != 1
            || nhwRegistryFloor() != 995
            || nhwChainCount() != 0
        )
            ++bad;
        // the print walk spans pp. 96-104 and the roster ordinals run 0-28 in
        // print order
    if (nhwPrintStart() != 96
            || nhwPrintEnd() != 104
            || nhwRosOrd(0) != 0
            || nhwRosOrd(28) != 28
            || nhwRosPage(0) != 96
            || nhwRosPage(28) != 104
            || nhwRosRank(6) != 1
            || nhwRosRank(12) != 0
            || nhwRosRank(1) != 2
            || nhwRosRank(17) != 4
            || nhwRosRank(3) != 5
        )
            ++bad;
        // Fafhrd the northern hero: the 6-feet-11-inch size print, the 15th
        // ranger, the 13th thief, the 5th bard
    if (nhwCbtAC(0) != 3
            || nhwCbtHP(0) != 120
            || nhwCbtAtN(0) != 2
            || nhwCbtSizeIn(0) != 83
            || nhwClsRanger(0) != 15
            || nhwClsThief(0) != 13
            || nhwClsBard(0) != 5
            || nhwAbiStr(0) != 18
            || nhwAbiStrHit(0) != 3
            || nhwAbiStrDmg(0) != 6
            || nhwFafhrdLangPct() != 80
            || nhwFafhrdClimbBonus() != 20
        )
            ++bad;
        // the Gray Mouser: the QUARTER-FOOT DECODE - the 5 1/4 foot print
        // pinned 63, the 3/2-or-3 attacks
    if (nhwCbtAC(1) != 2
            || nhwCbtHP(1) != 96
            || nhwCbtAtN(1) != 3
            || nhwCbtAtD(1) != 2
            || nhwCbtSizeIn(1) != 63
            || nhwClsFighterLo(1) != 11
            || nhwClsThief(1) != 15
            || nhwClsMagUser(1) != 3
            || nhwAbiDex(1) != 19
            || nhwAbiStr(1) != 16
            || nhwMouserThirdStrikePct() != 50
        )
            ++bad;
        // Death the greater god: the minus 5 armor class, the Infinite move
        // sentinel, the 10 segment attacks
    if (nhwCbtAC(6) != -5
            || nhwCbtMove(6) != -1
            || nhwCbtHP(6) != 350
            || nhwCbtAtN(6) != 10
            || nhwCbtMR(6) != 95
            || nhwCbtSizeIn(6) != 84
            || nhwClsCleric(6) != 30
            || nhwClsIllus(6) != 30
            || nhwClsAssassin(6) != 15
            || nhwClsBard(6) != 23
            || nhwRosPsiClass(6) != 1
            || nhwRosPlane(6) != 1
            || nhwDeathSegments() != 10
            || nhwAbiCha(6) != 21
        )
            ++bad;
        // Hate the fog: the See below armor class pinned 0, the printed 0 hit
        // points, the dash W/C/CH cells
    if (nhwCbtAC(12) != 0
            || nhwCbtHP(12) != 0
            || nhwCbtMove(12) != 6
            || nhwCbtAtN(12) != 6
            || nhwCbtMR(12) != 25
            || nhwCbtSizeIn(12) != 1080
            || nhwClsMagUser(12) != 99
            || nhwClsIllus(12) != 99
            || nhwAbiWis(12) != 0
            || nhwAbiCon(12) != 0
            || nhwAbiCha(12) != 0
            || nhwRosPlane(12) != 2
            || nhwHateCordAC() != -8
            || nhwHateControlMax() != 6
            || nhwHatePriestLevel() != 10
            || nhwHateWorshipers() != 100
        )
            ++bad;
        // Kos the god of dooms: the +6 intelligent broadsword, the code of
        // honor, the berserker summon
    if (nhwCbtAC(14) != -4
            || nhwCbtHP(14) != 377
            || nhwCbtMR(14) != 35
            || nhwCbtSizeIn(14) != 84
            || nhwClsDruid(14) != 10
            || nhwClsRanger(14) != 15
            || nhwKosBroadswordPlus() != 6
            || nhwKosHonorHp() != 100
            || nhwKosBerserkLow() != 9
            || nhwKosBerserkHigh() != 90
            || nhwAbiStr(14) != 25
            || nhwAbiStrDmg(14) != 14
        )
            ++bad;
        // the two advisors: Ningauble the seven eyes and Sheelba the eyeless
        // - the printed rivalry
    if (nhwCbtAC(17) != -2
            || nhwCbtAtN(17) != 0
            || nhwCbtSizeIn(17) != 108
            || nhwClsMagUser(17) != 20
            || nhwClsIllus(17) != 12
            || nhwClsBard(17) != 10
            || nhwRosRivalry(17) != 1
            || nhwCbtAC(21) != 2
            || nhwCbtAtN(21) != 1
            || nhwCbtSizeIn(21) != 0
            || nhwClsMonk(21) != 10
            || nhwRosRivalry(21) != 1
            || nhwSheelbaHutMoveIn() != 24
            || nhwNingaubleEyeCount() != 7
        )
            ++bad;
        // the monster XP walk: the nine monster rows, the flat and
        // per-hit-point pins
    if (nhwXpAstralWolfBase() != 90
            || nhwXpAstralWolfPerHp() != 3
            || nhwXpBehemothBase() != 4000
            || nhwXpBehemothPerHp() != 20
            || nhwXpBirdBase() != 30
            || nhwXpGhoulBase() != 50
            || nhwXpColdWomanFlat() != 28500
            || nhwXpLeviathanBase() != 15800
            || nhwXpLeviathanPerHp() != 35
            || nhwXpSnowSerpentBase() != 2050
            || nhwXpSaltSpiderBase() != 105
            || nhwXpWaterCobraBase() != 150
            || nhwXpWaterCobraPerHp() != 4
            || nhwXpAstralWolfLevel() != 3
            || nhwXpBehemothLevel() != 8
            || nhwXpColdWomanLevel() != 10
            || nhwXpLeviathanLevel() != 10
            || nhwXpSnowSerpentLevel() != 7
        )
            ++bad;
        // the hit-dice rows: seven monsters pin 0 hit points with the dice as
        // consts
    if (nhwAstralWolfHD() != 3
            || nhwBehemothHD() != 15
            || nhwGhoulHD() != 3
            || nhwLeviathanHD() != 40
            || nhwSnowSerpentHD() != 10
            || nhwSaltSpiderHD() != 3
            || nhwWaterCobraHD() != 3
            || nhwWaterCobraHDBonus() != 3
            || nhwCbtHP(3) != 0
            || nhwCbtHP(4) != 0
            || nhwCbtHP(9) != 0
            || nhwCbtHP(15) != 0
            || nhwCbtHP(23) != 0
            || nhwCbtHP(25) != 0
            || nhwCbtHP(28) != 0
        )
            ++bad;
        // the gods of Lankhmar and the gods of trouble: the two three-being
        // rows
    if (nhwCbtAC(10) != 3
            || nhwGodsLankhmarCount() != 3
            || nhwCryptCount() != 13
            || nhwAbiCha(10) != -3
            || nhwRosPsiClass(10) != 5
            || nhwCbtAC(11) != -2
            || nhwCbtHP(11) != 366
            || nhwCbtMoveAlt(11) != 24
            || nhwClsMagUser(11) != 20
            || nhwClsIllus(11) != 20
            || nhwRosInEach(11) != 1
            || nhwTroubleNoMagicFeet() != 30
            || nhwGodsTroubleCount() != 3
        )
            ++bad;
        // the encounter walk: the six regions, the 74 rows, the mountains
        // overlap print
    if (nhwEncTables() != 6
            || nhwEncRows() != 74
            || nhwEncColdRows() != 20
            || nhwEncForestRows() != 12
            || nhwEncMarshRows() != 10
            || nhwEncMtnRows() != 11
            || nhwEncPlainRows() != 12
            || nhwEncWaterRows() != 9
            || nhwEncRegion(0) != 0
            || nhwEncRegion(19) != 0
            || nhwEncRegion(20) != 1
            || nhwEncLow(0) != 1
            || nhwEncHigh(0) != 2
            || nhwEncHigh(19) != 100
            || nhwEncRegion(42) != 3
            || nhwEncLow(42) != 1
            || nhwEncHigh(42) != 5
            || nhwEncLow(43) != 3
            || nhwEncHigh(43) != 6
        )
            ++bad;
        // the lesser god walk: the earth god, the rat god and the red god -
        // the VI, I, VI psionic pipes
    if (nhwCbtAC(18) != -2
            || nhwCbtMR(18) != 50
            || nhwCbtSizeIn(18) != 180
            || nhwClsDruid(18) != 14
            || nhwRosPsiClass(18) != 6
            || nhwCbtAC(20) != 2
            || nhwCbtHP(20) != 222
            || nhwCbtSizeIn(20) != 120
            || nhwAbiCha(20) != -6
            || nhwRosPsiClass(20) != 1
            || nhwRatGodWererats() != 20
            || nhwCbtAC(22) != -2
            || nhwCbtAtN(22) != 4
            || nhwRosPsiClass(22) != 6
            || nhwRedGodRingPlus() != 4
        )
            ++bad;
        // the wastes monsters: the cold woman ray and corrosion, the devourer
        // MR and the Variable size
    if (nhwCbtAC(7) != -2
            || nhwCbtHP(7) != 180
            || nhwCbtMR(7) != 25
            || nhwCbtSizeIn(7) != 360
            || nhwColdRayRangeIn() != 6
            || nhwColdRayLow() != 7
            || nhwColdRayHigh() != 70
            || nhwCorrodeChainRounds() != 1
            || nhwCorrodePlateRounds() != 2
            || nhwColdWomanBiteHd() != 16
            || nhwCbtAC(8) != 7
            || nhwCbtMR(8) != 24
            || nhwCbtSizeIn(8) != 0
            || nhwClsIllus(8) != 25
            || nhwAbiWis(8) != 5
        )
            ++bad;
        // the heroes and demigods of law: Movarl, Issek with the odd 12/12
        // dual move, Votishal, Pulgh
    if (nhwCbtAC(16) != 2
            || nhwCbtAtN(16) != 3
            || nhwAbiStr(16) != 18
            || nhwMovarlEvilSenseFeet() != 20
            || nhwCbtAC(13) != -3
            || nhwCbtHP(13) != 210
            || nhwCbtMove(13) != 12
            || nhwCbtMoveAlt(13) != 12
            || nhwClsBard(13) != 15
            || nhwCbtAC(27) != -2
            || nhwCbtHP(27) != 344
            || nhwCbtMR(27) != 35
            || nhwClsThief(27) != 25
            || nhwRosPsiClass(27) != 5
            || nhwVotishalClericCap() != 10
            || nhwPulghSpearPlus() != 3
        )
            ++bad;
        // Tyaa and the Spider God: the dash AC print pinned 0, the negative
        // charisma pair
    if (nhwCbtAC(26) != 0
            || nhwCbtHP(26) != 311
            || nhwCbtMR(26) != 32
            || nhwCbtMove(26) != 9
            || nhwCbtMoveAlt(26) != 36
            || nhwCbtSizeIn(26) != 60
            || nhwTyaaBirdsPerDay() != 100
            || nhwTyaaSwordPlus() != 2
            || nhwCbtAC(24) != 2
            || nhwCbtHP(24) != 249
            || nhwCbtMR(24) != 10
            || nhwCbtSizeIn(24) != 216
            || nhwAbiCha(24) != -3
            || nhwSpiderGodPhaseSpiders() != 30
            || nhwSpiderGodSacrifices() != 10
        )
            ++bad;
        // the Nehwon doctrine of the intro: the beast cult, the guild, the
        // witches, the fire sorcerers
    if (nhwBeastCount() != 13
            || nhwGuildMasterLevel() != 12
            || nhwGuildMembersLow() != 3
            || nhwGuildMembersHigh() != 24
            || nhwGuildMemberLevel() != 5
            || nhwSlayerLevelHigh() != 10
            || nhwWitchCovenSize() != 5
            || nhwWitchHours() != 24
            || nhwWitchRangeMiles() != 5
            || nhwFireSorcMult() != 2
            || nhwFireSorcDiv() != 2
        )
            ++bad;
        printf("R863 Nehwon mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
