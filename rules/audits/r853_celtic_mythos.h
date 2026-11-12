    // ---- R853 Celtic mythos audit ----
    // THE CELTIC MYTHOS - the D&DG walk round five, print pp. 26-31: sixteen
    // beings (Dagda, Arawn, Brigit, Cu Chulainn, Diancecht, Dunatis,
    // Goibhnie, Lugh, Manannan Mac Lir, Math, Morrigan, Nuada, Oghma,
    // Silvanus, the Master of the Hunt, the Pack of the Wild Hunt) - the
    // druid doctrine of the robes, torc and cauldron, the Wild Hunt doctrine,
    // the tathlum and the Torc of the Gods. Zero registry defs touched; the
    // floor holds at 995. The flagged eyeball cells: the Manannan trident
    // drain fraction (one-fourth, garbled in both voices), the tathlum damage
    // fraction (garbled in both voices), and the Morrigan charisma 21 or -1
    // (both print voices garble identically; the 1eonline transcription
    // corroborates).
    {
        using namespace rules;
        int bad = 0;
    if (dgeRound() != 853
            || dgePrintStart() != 26
            || dgePrintEnd() != 31
            || dgeBeingCount() != 16
            || dgeTableCount() != 4
            || dgeChainCount() != 0
            || dgeRegistryFloor() != 995
            || dgeCbtRows() != 16
            || dgeClsRows() != 16
            || dgeAbiRows() != 16
            || dgeRosRows() != 16
            || dgePlaneCount() != 2
            || dgePsiClassVI() != 6
            || dgePsiClassII() != 2
            || dgePsiClassIV() != 4
            || dgeSamainMonth() != 11
            || dgeSamainDay() != 1
            || dgeImbalcMonth() != 2
            || dgeImbalcDay() != 1
            || dgeBeltaneMonth() != 5
            || dgeBeltaneDay() != 1
            || dgeLugnasadMonth() != 8
            || dgeLugnasadDay() != 1
            || dgeSacrificesPerYear() != 4
            || dgeDruidBlueLevelMax() != 6
            || dgeCauldronCrystalLevel() != 10
            || dgeWheelSymbolLoLevel() != 11
            || dgeWheelSymbolHiLevel() != 14
            || dgeDagdaEntityCount() != 12
            || dgeDagdaEtherealCount() != 11
            || dgeDagdaClubDmgLo() != 5
            || dgeDagdaClubDmgHi() != 50
            || dgeDagdaStrBonus() != 14
            || dgeArawnDeathSpells() != 2
            || dgeArawnSpellLevelMax() != 3
            || dgeArawnSpellAsLevel() != 20
            || dgeArawnRestoreChancePerLevel() != 2
            || dgeArawnSubstitutePct() != 25
            || dgeArawnClubPlus() != 3
            || dgeArawnClubDmgLo() != 2
            || dgeArawnClubDmgHi() != 20
            || dgeArawnStrBonus() != 11
            || dgeBrigitFireSpellLevel() != 35
            || dgeBrigitArmorPlus() != 5
            || dgeBrigitSongPct() != 5
            || dgeBrigitSongBoost() != 1
            || dgeBrigitAuraDamage() != 30
            || dgeBrigitAuraFeet() != 30
            || dgeBrigitMeltPlus() != 3
            || dgeBrigitStaffDmgLo() != 2
            || dgeBrigitStaffDmgHi() != 20
            || dgeCuSpearPlus() != 4
            || dgeCuSpearDmgLo() != 4
            || dgeCuSpearDmgHi() != 40
            || dgeCuGlarePenalty() != 4
            || dgeCuStrBonus() != 8
            || dgeDiancechtSummonPct() != 10
            || dgeDiancechtSummonerLevel() != 12
            || dgeDiancechtImmuneDiv() != 4
            || dgeDiancechtSpearPlus() != 3
            || dgeDiancechtSpearDmgLo() != 3
            || dgeDiancechtSpearDmgHi() != 30
            || dgeDiancechtStrBonus() != 10
            || dgeDunatisArmorPlus() != 4
            || dgeDunatisBoulderDmgLo() != 8
            || dgeDunatisBoulderDmgHi() != 80
            || dgeDunatisBoulderRangeYards() != 1000
            || dgeDunatisStrBonus() != 14
            || dgeGoibhnieThunderboltDamage() != 50
            || dgeGoibhnieAmuletProtectCount() != 500
            || dgeGoibhnieSpearPlus() != 4
            || dgeGoibhnieSpearDmgLo() != 3
            || dgeGoibhnieSpearDmgHi() != 30
            || dgeGoibhnieStrBonus() != 14
            || dgeLughDruidSpellLevel() != 30
            || dgeLughStrBonus() != 11
            || dgeManannanArmorPlus() != 5
            || dgeManannanTridentDrainDiv() != 4
            || dgeManannanRetaliatorDmgLo() != 3
            || dgeManannanRetaliatorDmgHi() != 30
            || dgeManannanSummonCount() != 50
            || dgeManannanStrBonus() != 12
            || dgeMathPsiScore() != 200
            || dgeMathMuLevel() != 30
            || dgeMathIllusLevel() != 10
            || dgeMorriganChaAlt() != -1
            || dgeMorriganSightMiles() != 15
            || dgeMorriganFleeStrikePct() != 5
            || dgeMorriganWatchingPct() != 10
            || dgeMorriganSpearDmgLo() != 3
            || dgeMorriganSpearDmgHi() != 36
            || dgeMorriganServantCount() != 4
            || dgeMorriganServantHP() != 200
            || dgeMorriganStrBonus() != 14
            || dgeNuadaHitPlus() != 3
            || dgeNuadaDoubleDamage() != 2
            || dgeNuadaHandDmgLo() != 6
            || dgeNuadaHandDmgHi() != 36
            || dgeNuadaArmorPlus() != 4
            || dgeNuadaSwordPlus() != 5
            || dgeNuadaFendCount() != 3
            || dgeNuadaStrBonus() != 14
            || dgeOghmaListenPct() != 1
            || dgeOghmaRewardPct() != 5
            || dgeOghmaChainmailPlus() != 4
            || dgeOghmaStrBonus() != 14
            || dgeSilvanusArmorPlus() != 5
            || dgeSilvanusMalletPlus() != 5
            || dgeSilvanusMalletDmgLo() != 5
            || dgeSilvanusMalletDmgHi() != 50
            || dgeSilvanusHoundAC() != 3
            || dgeSilvanusHoundHD() != 10
            || dgeSilvanusHoundHP() != 100
            || dgeSilvanusHoundAtN() != 1
            || dgeSilvanusHoundDmgLo() != 2
            || dgeSilvanusHoundDmgHi() != 20
            || dgeSilvanusHoundRegen() != 5
            || dgeSilvanusGroveAppearPct() != 1
            || dgeSilvanusStrBonus() != 14
            || dgeHuntStartMiles() != 10
            || dgeHuntSpotPctPerMile() != 10
            || dgeHuntLookPct() != 25
            || dgeHuntHuntedPct() != 90
            || dgeHuntResnarePct() != 50
            || dgeHuntPackCount() != 20
            || dgeHuntHoundHP() != 30
            || dgeHoundDmgLo() != 2
            || dgeHoundDmgHi() != 8
            || dgeHoundAttackHD() != 8
            || dgeHoundXpValue() != 950
            || dgeMasterSpearPlus() != 3
            || dgeMasterHornMiles() != 1
            || dgeTathlumCoatDays() != 1
            || dgeTathlumCoatWeeks() != 1
            || dgeTathlumRelativeDiv() != 2
            || !dgeNotConfinedToBritishIsles()
            || !dgeAllHumanForm()
            || !dgeSpheresOfInfluence()
            || !dgeClericsAreDruids()
            || !dgeServicesInWoodedAreas()
            || !dgeWellsAndPits()
            || !dgeHumanSacrifices()
            || !dgeCondemnedCriminals()
            || !dgeGrovesGuardedByBoars()
            || !dgeDruidRobes()
            || !dgeTheTorc()
            || !dgeTorcMagic()
            || !dgeDruidCauldron()
            || !dgeWheelSymbol()
            || !dgeTolerantOfPriests()
            || !dgeNaturePrimeConcern()
            || !dgeEliteSeparateGroup()
            || !dgeDagdaDozenKing()
            || !dgeDagdaSeparatesSelf()
            || !dgeDagdaEtherealServants()
            || !dgeDagdaShapeChange()
            || !dgeDagdaShabbyMan()
            || !dgeDagdaBreaksAnything()
            || !dgeDagdaClubDeathEnd()
            || !dgeDagdaClubRaiseEnd()
            || !dgeDagdaCauldron()
            || !dgeDagdaSentientHarp()
            || !dgeArawnGodOfDead()
            || !dgeArawnIslandOfDead()
            || !dgeArawnEyeDeathSpells()
            || !dgeArawnThirdLevelSpells()
            || !dgeArawnAppearsOnRestore()
            || !dgeArawnFightsOrSubstitutes()
            || !dgeArawnImmuneToDirectDamage()
            || !dgeArawnWeaponTouchDeath()
            || !dgeBrigitFireAndPoetry()
            || !dgeBrigitFlameHair()
            || !dgeBrigitSongFavor()
            || !dgeBrigitBattleSongDoctrine()
            || !dgeBrigitFireImmunities()
            || !dgeBrigitFlameAura()
            || !dgeBrigitMeltsWeapons()
            || !dgeBrigitFlameStaff()
            || !dgeCuHero()
            || !dgeCuGaeBolg()
            || !dgeCuNeverSurprised()
            || !dgeCuBattleBrilliance()
            || !dgeCuFightsGiants()
            || dgeCuCannotBeCharmed()
            || !dgeDiancechtPhysician()
            || !dgeDiancechtAppearsYoung()
            || !dgeDiancechtHealsAnything()
            || !dgeDiancechtSummonedByDeities()
            || !dgeDiancechtPilgrimage()
            || !dgeDiancechtHeadlessLimit()
            || !dgeDiancechtWonVsArawn()
            || !dgeDiancechtHealsAllSides()
            || !dgeDunatisMountainGod()
            || !dgeDunatisAppearsNormal()
            || !dgeDunatisRaisesPeaks()
            || !dgeDunatisDestroysForts()
            || !dgeDunatisAirBoulders()
            || !dgeDunatisImmunities()
            || !dgeGoibhnieBlacksmith()
            || !dgeGoibhnieHugeMan()
            || !dgeGoibhnieWeaponsNeverMiss()
            || !dgeGoibhnieAmulets()
            || !dgeGoibhnieImpossibleHit()
            || !dgeGoibhnieOneAmulet()
            || !dgeGoibhniePhysicalImmune()
            || !dgeLughGeneralities()
            || !dgeLughBorrowedAttribute()
            || !dgeLughLargeHands()
            || !dgeLughNoArmor()
            || !dgeLughDruidicalIdeal()
            || !dgeLughImmunities()
            || !dgeManannanSeaGod()
            || !dgeManannanRedBeard()
            || !dgeManannanTridentDrains()
            || !dgeManannanRetaliator()
            || !dgeManannanSeaSummon()
            || !dgeManannanSaltWaterImmune()
            || !dgeMathMagicUser()
            || !dgeMathHearsBreezes()
            || !dgeMathTorcBearer()
            || !dgeMathWaterRod()
            || !dgeMathPolymorphOthers()
            || !dgeMorriganWarGoddess()
            || !dgeMorriganHideousFace()
            || !dgeMorriganFear()
            || !dgeMorriganInvisibleFight()
            || !dgeMorriganChaseSpeed()
            || !dgeMorriganStrikesFleeing()
            || !dgeMorriganTwoSpears()
            || !dgeMorriganMagicImmune()
            || !dgeMorriganDemiGoddesses()
            || !dgeNuadaSilverHand()
            || !dgeNuadaArtificialHand()
            || !dgeNuadaWeaponBonus()
            || !dgeNuadaDancingHand()
            || !dgeNuadaFendingSword()
            || !dgeNuadaWrestles()
            || !dgeNuadaEqualStrength()
            || !dgeNuadaControlImmune()
            || !dgeOghmaBinder()
            || !dgeOghmaAgedMan()
            || !dgeOghmaBestWrestler()
            || !dgeOghmaCreativePatron()
            || !dgeOghmaSeeksGifted()
            || !dgeOghmaAnswerMachine()
            || !dgeOghmaSecretNames()
            || !dgeOghmaVariableStrength()
            || !dgeOghmaImprisonsDemons()
            || !dgeSilvanusForestGod()
            || !dgeSilvanusLongLegs()
            || !dgeSilvanusVoiceControl()
            || !dgeSilvanusPlants()
            || !dgeSilvanusLeafArmor()
            || !dgeSilvanusWolfhound()
            || !dgeSilvanusGroveProtector()
            || !dgeMasterOfTheHunt()
            || !dgeMasterGreenEyes()
            || !dgeMasterBlackLeather()
            || !dgeMasterNeverSpeaks()
            || !dgeMasterRunsBehind()
            || !dgePackGreenFire()
            || !dgePackWaitsForHunters()
            || !dgePackTakesOverIfKilled()
            || !dgePackDeathsUnnoticed()
            || !dgeHuntManifestation()
            || !dgeHuntOneForm()
            || !dgeHuntSummonedByEvil()
            || !dgeHuntPursuitNoise()
            || !dgeHuntPursuersJoin()
            || !dgeHuntTwoRoles()
            || !dgeHuntNeverEntersBuildings()
            || !dgeHuntOnePerNight()
            || !dgeHuntKillsOrDisappears()
            || !dgeHuntBigGameFallback()
            || !dgeHuntCompelledAlignment()
            || !dgeHuntEternal()
            || !dgeHuntKeepsPace()
            || !dgeHuntFlies()
            || !dgeHuntDeathMelee()
            || !dgeHuntEscape()
            || !dgeHuntSightingResnare()
            || !dgeTathlumWeapon()
            || !dgeTathlumSunshine()
            || !dgeTathlumOnceOnly()
            || !dgeTorcOfTheGods()
            || !dgeTorcRareMetals()
        )
            ++bad;
        // the combat stat blocks of the sixteen beings (print pp. 26-31) -
        // the armor classes, hit points, moves, attacks, magic resistance and
        // sizes
        int CCbt[16][9] = {
            {-4,0,400,12,0,2,0,80,72},
            {-4,0,325,15,0,2,0,75,84},
            {-4,0,325,12,0,3,2,50,72},
            {-1,0,150,15,0,2,0,20,76},
            {-1,0,300,12,0,1,0,100,72},
            {-10,0,350,24,0,2,0,10,72},
            {-4,0,329,9,0,2,0,75,72},
            {0,0,375,12,0,2,0,90,84},
            {-2,0,389,12,48,2,0,75,72},
            {6,0,100,12,0,1,0,35,64},
            {-4,0,388,0,0,2,0,50,72},
            {-4,0,390,15,0,3,0,10,72},
            {-6,0,310,12,0,2,0,85,72},
            {-4,0,333,18,48,3,2,30,84},
            {0,0,100,18,0,2,0,25,84},
            {5,0,30,18,0,1,0,15,48},
            };
        int nCbt[9] = {0,0,0,0,0,0,0,0,0};
        int eCbt[9] = {2,16,0,1,14,0,14,0,0};
        for (int b = 0;
             b < dgeCbtRows();
             ++b) {
            int vals[9];
            vals[0] = dgeCbtAC(b);
            vals[1] = dgeCbtACAlt(b);
            vals[2] = dgeCbtHP(b);
            vals[3] = dgeCbtMove(b);
            vals[4] = dgeCbtMoveAlt(b);
            vals[5] = dgeCbtAtN(b);
            vals[6] = dgeCbtAtD(b);
            vals[7] = dgeCbtMR(b);
            vals[8] = dgeCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CCbt[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nCbt[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nCbt[c] != eCbt[c])
                ++bad;
        // the five-slot class grid of the sixteen beings (99 = the printed
        // See below; the Celtic ranger-heavy fighter slots)
        int CCls[16][11] = {
            {15,14,18,18,0,15,15,0,0,0,20},
            {20,14,0,0,17,99,0,0,0,0,15},
            {0,14,12,12,0,99,0,0,0,0,18},
            {0,0,0,0,18,0,12,0,0,0,8},
            {25,14,14,14,0,12,0,0,0,0,10},
            {15,0,18,18,0,0,0,0,0,0,20},
            {0,14,18,18,0,0,0,0,0,0,15},
            {0,99,0,0,19,0,0,0,0,0,19},
            {25,0,16,16,0,99,0,0,0,0,0},
            {0,6,4,4,0,30,10,0,0,0,0},
            {0,10,0,0,20,0,0,0,15,0,10},
            {0,10,0,0,20,0,0,0,12,0,10},
            {15,15,15,15,0,18,18,0,0,0,20},
            {14,14,13,13,0,0,19,0,0,0,15},
            {0,0,0,0,15,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            };
        int nCls[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int eCls[11] = {9,5,7,7,10,9,11,16,14,16,4};
        for (int b = 0;
             b < dgeClsRows();
             ++b) {
            int vals[11];
            vals[0] = dgeClsCleric(b);
            vals[1] = dgeClsDruid(b);
            vals[2] = dgeClsFighterLo(b);
            vals[3] = dgeClsFighterHi(b);
            vals[4] = dgeClsRanger(b);
            vals[5] = dgeClsMagUser(b);
            vals[6] = dgeClsIllus(b);
            vals[7] = dgeClsThief(b);
            vals[8] = dgeClsAssassin(b);
            vals[9] = dgeClsMonk(b);
            vals[10] = dgeClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CCls[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nCls[c];
            }
        }
        for (int c = 0; c < 11; ++c)
            if (nCls[c] != eCls[c])
                ++bad;
        // the six ability scores with the strength brackets of the sixteen
        // beings (the Pack monster row reads the all-sentinel line)
        int CAbi[16][9] = {
            {25,7,14,25,25,23,25,25,0},
            {23,5,11,24,23,25,24,20,0},
            {25,7,14,22,22,25,24,25,0},
            {20,3,8,17,16,19,18,17,0},
            {22,4,10,25,25,20,23,24,0},
            {25,7,14,20,22,20,24,23,0},
            {25,7,14,24,23,20,25,19,0},
            {23,5,11,25,24,25,24,24,0},
            {24,6,12,24,23,21,24,22,0},
            {18,1,2,18,18,18,18,18,200},
            {25,7,14,22,19,25,24,21,0},
            {25,7,14,22,19,25,25,24,0},
            {25,7,14,25,25,22,20,23,0},
            {25,7,14,24,25,24,25,23,0},
            {18,3,6,18,18,18,18,15,0},
            {0,0,0,0,0,0,0,0,0},
            };
        int nAbi[9] = {0,0,0,0,0,0,0,0,0};
        int eAbi[9] = {1,1,1,1,1,1,1,1,15};
        for (int b = 0;
             b < dgeAbiRows();
             ++b) {
            int vals[9];
            vals[0] = dgeAbiStr(b);
            vals[1] = dgeAbiStrHit(b);
            vals[2] = dgeAbiStrDmg(b);
            vals[3] = dgeAbiInt(b);
            vals[4] = dgeAbiWis(b);
            vals[5] = dgeAbiDex(b);
            vals[6] = dgeAbiCon(b);
            vals[7] = dgeAbiCha(b);
            vals[8] = dgeAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CAbi[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nAbi[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nAbi[c] != eAbi[c])
                ++bad;
        // the roster walk of the sixteen beings - ordinals, pages,
        // alignments, ranks, psionic classes, planes, the fixed-damage and
        // in-each flags, and the Wild Hunt membership
        int CRos[16][9] = {
            {0,26,4,1,2,1,1,1,0},
            {1,26,6,1,6,2,1,0,0},
            {2,27,4,0,6,1,1,0,0},
            {3,27,1,2,0,0,1,0,0},
            {4,27,0,0,6,1,1,0,0},
            {5,27,4,0,6,1,1,0,0},
            {6,28,4,0,6,1,1,0,0},
            {7,28,4,1,6,1,0,0,0},
            {8,28,5,1,6,1,0,0,0},
            {9,28,4,2,0,0,0,0,0},
            {10,29,4,0,6,1,1,0,0},
            {11,29,4,1,6,1,0,0,0},
            {12,29,4,1,4,1,0,1,0},
            {13,30,4,1,6,1,1,1,0},
            {14,31,4,2,0,0,0,0,1},
            {15,31,4,3,0,0,1,0,1},
            };
        int nRos[9] = {0,0,0,0,0,0,0,0,0};
        int eRos[9] = {1,0,1,5,4,4,6,13,14};
        for (int b = 0;
             b < dgeRosRows();
             ++b) {
            int vals[9];
            vals[0] = dgeRosOrd(b);
            vals[1] = dgeRosPage(b);
            vals[2] = dgeRosAlign(b);
            vals[3] = dgeRosRank(b);
            vals[4] = dgeRosPsiClass(b);
            vals[5] = dgeRosPlane(b);
            vals[6] = dgeRosDmgFixed(b);
            vals[7] = dgeRosInEach(b);
            vals[8] = dgeRosWildHunt(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CRos[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nRos[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nRos[c] != eRos[c])
                ++bad;
        // the census walk (the four grids, the sixteen beings, the two
        // planes)
    if (dgeTableCount() != 4
            || dgeBeingCount() != 16
            || dgeCbtRows() != 16
            || dgeClsRows() != 16
            || dgeAbiRows() != 16
            || dgeRosRows() != 16
            || dgePlaneCount() != 2
            || dgeChainCount() != 0
        )
            ++bad;
        // the print walk spans pp. 26-31 (the folio offset PRINT = PDF - 1)
    if (dgePrintStart() != 26
            || dgePrintEnd() != 31
        )
            ++bad;
        // the roster ordinals run 0-15 in print order (Dagda first, the Pack
        // last)
    if (dgeRosOrd(0) != 0
            || dgeRosOrd(15) != 15
            || dgeRosPage(0) != 26
            || dgeRosPage(15) != 31
        )
            ++bad;
        // the druid doctrine: four sacrifices a year on the four feast days
        // (Samain, Imbalc, Beltane, Lugnasad)
    if (dgeSacrificesPerYear() != 4
            || dgeSamainMonth() != 11
            || dgeSamainDay() != 1
            || dgeImbalcMonth() != 2
            || dgeBeltaneMonth() != 5
            || dgeLugnasadMonth() != 8
            || dgeLugnasadDay() != 1
        )
            ++bad;
        // the druid regalia: blue at sixth or less, the crystal-ball cauldron
        // at tenth, the wheel symbol eleventh through fourteenth
    if (dgeDruidBlueLevelMax() != 6
            || dgeCauldronCrystalLevel() != 10
            || dgeWheelSymbolLoLevel() != 11
            || dgeWheelSymbolHiLevel() != 14
        )
            ++bad;
        // the Dagda walk: AC -4, 400 hit points, 2 attacks, 80 percent MR,
        // the club 5-50 plus 14, 20th level bard
    if (dgeCbtAC(0) != -4
            || dgeCbtHP(0) != 400
            || dgeCbtAtN(0) != 2
            || dgeCbtMR(0) != 80
            || dgeDagdaClubDmgLo() != 5
            || dgeDagdaClubDmgHi() != 50
            || dgeDagdaStrBonus() != 14
            || dgeClsBard(0) != 20
        )
            ++bad;
        // the Dagda adjudications: the 12 entities with 11 ethereal, the
        // psionic class II (the 29px two-glyph IA word against the Termux
        // I-slash), S:25(+7,+14) I:25 W:25 D:23 C:25 CH:25
    if (dgeDagdaEntityCount() != 12
            || dgeDagdaEtherealCount() != 11
            || dgeRosPsiClass(0) != 2
            || dgePsiClassII() != 2
            || dgeAbiStr(0) != 25
            || dgeAbiStrHit(0) != 7
            || dgeAbiStrDmg(0) != 14
            || dgeAbiInt(0) != 25
            || dgeAbiWis(0) != 25
            || dgeAbiDex(0) != 23
            || dgeAbiCon(0) != 25
            || dgeAbiCha(0) != 25
        )
            ++bad;
        // the Dagda class walk: 15th cleric, 14th druid, 18th fighter,
        // magic-user/illusionist 15th in each (the IA recovery of the Termux
        // fold)
    if (dgeClsCleric(0) != 15
            || dgeClsDruid(0) != 14
            || dgeClsFighterLo(0) != 18
            || dgeClsMagUser(0) != 15
            || dgeClsIllus(0) != 15
            || dgeRosInEach(0) != 1
        )
            ++bad;
        // the Arawn walk: AC -4, 325 hit points, 15-inch move, 7 feet, lawful
        // evil, the Prime Material Plane
    if (dgeCbtAC(1) != -4
            || dgeCbtHP(1) != 325
            || dgeCbtMove(1) != 15
            || dgeCbtSizeIn(1) != 84
            || dgeRosAlign(1) != 6
            || dgeRosPlane(1) != 2
        )
            ++bad;
        // the Arawn doctrines: the 2 eye death spells, the third-level spells
        // as a 20th, the 2 percent per level, the 25 percent substitute, the
        // +3 club 2-20 plus 11
    if (dgeArawnDeathSpells() != 2
            || dgeArawnSpellLevelMax() != 3
            || dgeArawnSpellAsLevel() != 20
            || dgeArawnRestoreChancePerLevel() != 2
            || dgeArawnSubstitutePct() != 25
            || dgeArawnClubPlus() != 3
            || dgeArawnClubDmgLo() != 2
            || dgeArawnClubDmgHi() != 20
            || dgeArawnStrBonus() != 11
        )
            ++bad;
        // the Brigit walk: AC -4, 325 hit points, the printed 3/2 attacks,
        // 14th druid, 18th bard, the 35th level fire spells (the See below),
        // psionic VI
    if (dgeCbtAC(2) != -4
            || dgeCbtHP(2) != 325
            || dgeCbtAtN(2) != 3
            || dgeCbtAtD(2) != 2
            || dgeClsDruid(2) != 14
            || dgeClsBard(2) != 18
            || dgeBrigitFireSpellLevel() != 35
            || dgeClsMagUser(2) != 99
            || dgeRosPsiClass(2) != 6
        )
            ++bad;
        // the Brigit doctrines: the +5 flame armor, the 5 percent song favor,
        // the 30-point 30-foot aura, the +3 melt line, the 2-20 staff
    if (dgeBrigitArmorPlus() != 5
            || dgeBrigitSongPct() != 5
            || dgeBrigitAuraDamage() != 30
            || dgeBrigitAuraFeet() != 30
            || dgeBrigitMeltPlus() != 3
            || dgeBrigitStaffDmgLo() != 2
            || dgeBrigitStaffDmgHi() != 20
        )
            ++bad;
        // the Cu Chulainn walk: AC -1, 150 hit points, 18th ranger, 12th
        // illusionist, 8th bard, Gae Bolg the +4 spear 4-40, the -4 glare
    if (dgeCbtAC(3) != -1
            || dgeCbtHP(3) != 150
            || dgeClsRanger(3) != 18
            || dgeClsIllus(3) != 12
            || dgeClsBard(3) != 8
            || dgeCuSpearPlus() != 4
            || dgeCuSpearDmgLo() != 4
            || dgeCuSpearDmgHi() != 40
            || dgeCuGlarePenalty() != 4
        )
            ++bad;
        // the Cu Chulainn adjudications: S:20(+3,+8) I:17 W:16 D:19 C:18
        // CH:17 (the Termux 1117 against the IA 1:97 misread), the 6-foot-4
        // size (the foot-mark-as-1 decode of the printed 614)
    if (dgeAbiStr(3) != 20
            || dgeAbiStrHit(3) != 3
            || dgeAbiStrDmg(3) != 8
            || dgeAbiInt(3) != 17
            || dgeAbiWis(3) != 16
            || dgeAbiDex(3) != 19
            || dgeAbiCon(3) != 18
            || dgeAbiCha(3) != 17
            || dgeCbtSizeIn(3) != 76
        )
            ++bad;
        // the Diancecht walk: AC -1, 300 hit points, 1 attack, the printed
        // 100 percent MR, 25th cleric, 14th druid, 12th magic-user, 10th bard
    if (dgeCbtAC(4) != -1
            || dgeCbtHP(4) != 300
            || dgeCbtAtN(4) != 1
            || dgeCbtMR(4) != 100
            || dgeClsCleric(4) != 25
            || dgeClsDruid(4) != 14
            || dgeClsMagUser(4) != 12
            || dgeClsBard(4) != 10
        )
            ++bad;
        // the Diancecht doctrines: the 10 percent 12th-level summon with the
        // pilgrimage oath, the one-fourth immunity, the +3 spear 3-30 plus 10
    if (dgeDiancechtSummonPct() != 10
            || dgeDiancechtSummonerLevel() != 12
            || dgeDiancechtImmuneDiv() != 4
            || dgeDiancechtSpearPlus() != 3
            || dgeDiancechtSpearDmgLo() != 3
            || dgeDiancechtSpearDmgHi() != 30
            || dgeDiancechtStrBonus() != 10
        )
            ++bad;
        // the Dunatis walk: AC -10, 350 hit points, 24-inch move, the
        // boulders 8-80 up to 1,000 yards, 20th bard, psionic VI
    if (dgeCbtAC(5) != -10
            || dgeCbtHP(5) != 350
            || dgeCbtMove(5) != 24
            || dgeDunatisBoulderDmgLo() != 8
            || dgeDunatisBoulderDmgHi() != 80
            || dgeDunatisBoulderRangeYards() != 1000
            || dgeDunatisArmorPlus() != 4
            || dgeClsBard(5) != 20
            || dgeRosPsiClass(5) != 6
        )
            ++bad;
        // the Goibhnie walk: AC -4, 329 hit points, 9-inch move, 75 percent
        // MR, 14th druid, 15th bard, the psionic VI (the 51px V-slash word),
        // the +4 spear 3-30 plus 14
    if (dgeCbtAC(6) != -4
            || dgeCbtHP(6) != 329
            || dgeCbtMove(6) != 9
            || dgeCbtMR(6) != 75
            || dgeClsDruid(6) != 14
            || dgeClsBard(6) != 15
            || dgeRosPsiClass(6) != 6
            || dgeGoibhnieSpearPlus() != 4
            || dgeGoibhnieSpearDmgLo() != 3
            || dgeGoibhnieStrBonus() != 14
        )
            ++bad;
        // the Goibhnie doctrines: the never-miss weapons, the 50-point
        // thunderbolt, the 500-person amulet chain
    if (dgeGoibhnieThunderboltDamage() != 50
            || dgeGoibhnieAmuletProtectCount() != 500
        )
            ++bad;
        // the Lugh walk: AC 0, 375 hit points, 90 percent MR, 7 feet, 19th
        // ranger, 19th bard, psionic VI
    if (dgeCbtAC(7) != 0
            || dgeCbtHP(7) != 375
            || dgeCbtMR(7) != 90
            || dgeCbtSizeIn(7) != 84
            || dgeClsRanger(7) != 19
            || dgeClsBard(7) != 19
            || dgeRosPsiClass(7) != 6
        )
            ++bad;
        // the Lugh adjudications: S:23(+5,+11) I:25 W:24 D:25 C:24 CH:24 (the
        // Termux and the 1eonline transcription against the IA S:20 misread),
        // the Nil/see below cleric line and the 30th level druidical doctrine
    if (dgeAbiStr(7) != 23
            || dgeAbiStrHit(7) != 5
            || dgeAbiStrDmg(7) != 11
            || dgeAbiInt(7) != 25
            || dgeAbiWis(7) != 24
            || dgeAbiDex(7) != 25
            || dgeAbiCon(7) != 24
            || dgeAbiCha(7) != 24
            || dgeClsCleric(7) != 0
            || dgeClsDruid(7) != 99
            || dgeLughDruidSpellLevel() != 30
        )
            ++bad;
        // the Manannan walk: AC -2, 389 hit points, 12 over 48, chaotic
        // neutral, 25th cleric, 16th fighter, the See below magic-user,
        // psionic VI
    if (dgeCbtAC(8) != -2
            || dgeCbtHP(8) != 389
            || dgeCbtMove(8) != 12
            || dgeCbtMoveAlt(8) != 48
            || dgeRosAlign(8) != 5
            || dgeClsCleric(8) != 25
            || dgeClsFighterLo(8) != 16
            || dgeClsMagUser(8) != 99
            || dgeRosPsiClass(8) != 6
        )
            ++bad;
        // the flagged eyeball cell: the Manannan trident drains one-fourth of
        // the original hit points (the fraction garbles in both voices), the
        // +5 sea-shell armor, the Retaliator 3-30, the 50-creature sea call
    if (dgeManannanTridentDrainDiv() != 4
            || dgeManannanArmorPlus() != 5
            || dgeManannanRetaliatorDmgLo() != 3
            || dgeManannanRetaliatorDmgHi() != 30
            || dgeManannanSummonCount() != 50
            || dgeManannanStrBonus() != 12
        )
            ++bad;
        // the Math walk: AC 6, 100 hit points, 6th druid, 4th fighter, 30th
        // magic-user, 10th illusionist, the printed 200 point psionic score
        // (like the R851 Merlin 300), the modes A B C over F G H I
    if (dgeCbtAC(9) != 6
            || dgeCbtHP(9) != 100
            || dgeClsDruid(9) != 6
            || dgeClsFighterLo(9) != 4
            || dgeClsMagUser(9) != 30
            || dgeClsIllus(9) != 10
            || dgeAbiPsi(9) != 200
            || dgeMathPsiScore() != 200
        )
            ++bad;
        // the Math adjudications: S:18(+1,+2) I:18 W:18 D:18 C:18 CH:18, the
        // 5-foot-4 size (the foot-mark-as-1 decode of the printed 514)
    if (dgeAbiStr(9) != 18
            || dgeAbiStrHit(9) != 1
            || dgeAbiStrDmg(9) != 2
            || dgeAbiInt(9) != 18
            || dgeAbiWis(9) != 18
            || dgeAbiDex(9) != 18
            || dgeAbiCon(9) != 18
            || dgeAbiCha(9) != 18
            || dgeCbtSizeIn(9) != 64
        )
            ++bad;
        // the Morrigan walk: AC -4, 388 hit points, the Variable move
        // sentinel, 20th ranger, 15th assassin, 10th bard, psionic VI
    if (dgeCbtAC(10) != -4
            || dgeCbtHP(10) != 388
            || dgeCbtMove(10) != 0
            || dgeClsRanger(10) != 20
            || dgeClsAssassin(10) != 15
            || dgeClsBard(10) != 10
            || dgeRosPsiClass(10) != 6
        )
            ++bad;
        // the flagged eyeball cell: the Morrigan charisma line reads 21 or -1
        // (both voices garble identically; the 1eonline transcription
        // corroborates) - the alt rides the consts
    if (dgeAbiCha(10) != 21
            || dgeMorriganChaAlt() != -1
        )
            ++bad;
        // the Morrigan doctrines: the 15-mile sight, the 5 percent strike on
        // fleeing worshipers, the 10 percent watching, the 3-36 never-miss
        // spears, the four 200-hit-point demi-goddesses
    if (dgeMorriganSightMiles() != 15
            || dgeMorriganFleeStrikePct() != 5
            || dgeMorriganWatchingPct() != 10
            || dgeMorriganSpearDmgLo() != 3
            || dgeMorriganSpearDmgHi() != 36
            || dgeMorriganServantCount() != 4
            || dgeMorriganServantHP() != 200
            || dgeMorriganStrBonus() != 14
        )
            ++bad;
        // the Nuada walk: AC -4, 390 hit points, 3 attacks, 10 percent MR,
        // 20th ranger, 12th assassin, 10th bard, psionic VI
    if (dgeCbtAC(11) != -4
            || dgeCbtHP(11) != 390
            || dgeCbtAtN(11) != 3
            || dgeCbtMR(11) != 10
            || dgeClsRanger(11) != 20
            || dgeClsAssassin(11) != 12
            || dgeClsBard(11) != 10
            || dgeRosPsiClass(11) != 6
        )
            ++bad;
        // the Nuada doctrines: the +3 to hit and double damage, the 6-36
        // silver hand, the +4 leather, the +5 sword fending 3 weapons, the
        // equal-plus-own strength
    if (dgeNuadaHitPlus() != 3
            || dgeNuadaDoubleDamage() != 2
            || dgeNuadaHandDmgLo() != 6
            || dgeNuadaHandDmgHi() != 36
            || dgeNuadaArmorPlus() != 4
            || dgeNuadaSwordPlus() != 5
            || dgeNuadaFendCount() != 3
            || dgeNuadaStrBonus() != 14
        )
            ++bad;
        // the Oghma walk: AC -6, 310 hit points, 85 percent MR, cleric and
        // druid 15th in each, magic-user and illusionist 18th in each, 20th
        // bard, psionic IV (the 57px word)
    if (dgeCbtAC(12) != -6
            || dgeCbtHP(12) != 310
            || dgeCbtMR(12) != 85
            || dgeClsCleric(12) != 15
            || dgeClsDruid(12) != 15
            || dgeClsMagUser(12) != 18
            || dgeClsIllus(12) != 18
            || dgeClsBard(12) != 20
            || dgeRosPsiClass(12) != 4
            || dgeRosInEach(12) != 1
        )
            ++bad;
        // the Oghma adjudications: S:25(+7,+14) asterisked (the See below
        // equal-plus-own strength doctrine), I:25 W:25 D:22 C:20 CH:23, the
        // 6-foot size (the IA clean read against the Termux ampersand garble)
    if (dgeAbiStr(12) != 25
            || dgeAbiStrHit(12) != 7
            || dgeAbiStrDmg(12) != 14
            || dgeAbiInt(12) != 25
            || dgeAbiWis(12) != 25
            || dgeAbiDex(12) != 22
            || dgeAbiCon(12) != 20
            || dgeAbiCha(12) != 23
            || dgeCbtSizeIn(12) != 72
            || dgeOghmaChainmailPlus() != 4
            || dgeOghmaListenPct() != 1
            || dgeOghmaRewardPct() != 5
        )
            ++bad;
        // the Silvanus adjudications: AC -4 and the 18 over 48
        // through-forests move (the IA recovery of the Termux fold-garbled
        // lines), the printed 3/2 attacks, 5-50 plus 14, cleric and druid
        // 14th in each, 19th illusionist, 15th bard, psionic VI
    if (dgeCbtAC(13) != -4
            || dgeCbtMove(13) != 18
            || dgeCbtMoveAlt(13) != 48
            || dgeCbtAtN(13) != 3
            || dgeCbtAtD(13) != 2
            || dgeCbtHP(13) != 333
            || dgeSilvanusMalletDmgLo() != 5
            || dgeSilvanusMalletDmgHi() != 50
            || dgeSilvanusStrBonus() != 14
            || dgeClsCleric(13) != 14
            || dgeClsDruid(13) != 14
            || dgeClsIllus(13) != 19
            || dgeClsBard(13) != 15
            || dgeRosPsiClass(13) != 6
            || dgeRosInEach(13) != 1
        )
            ++bad;
        // the Silvanus doctrines: the +5 leaf armor and mallet, the wolfhound
        // (AC 3, HD 10, hp 100, 1 attack, 2-20, regenerating 5), the 1
        // percent grove appearance
    if (dgeSilvanusArmorPlus() != 5
            || dgeSilvanusMalletPlus() != 5
            || dgeSilvanusHoundAC() != 3
            || dgeSilvanusHoundHD() != 10
            || dgeSilvanusHoundHP() != 100
            || dgeSilvanusHoundAtN() != 1
            || dgeSilvanusHoundDmgLo() != 2
            || dgeSilvanusHoundDmgHi() != 20
            || dgeSilvanusHoundRegen() != 5
            || dgeSilvanusGroveAppearPct() != 1
        )
            ++bad;
        // the Master walk: AC 0, 100 hit points, 18-inch move, 15th ranger,
        // the +3 spear, the horn every mile
    if (dgeCbtAC(14) != 0
            || dgeCbtHP(14) != 100
            || dgeCbtMove(14) != 18
            || dgeClsRanger(14) != 15
            || dgeMasterSpearPlus() != 3
            || dgeMasterHornMiles() != 1
            || dgeRosWildHunt(14) != 1
        )
            ++bad;
        // the Master abilities: S:18(00)(+3,+6) I:18 W:18 D:18 C:18 CH:15,
        // the 7-foot size
    if (dgeAbiStr(14) != 18
            || dgeAbiStrHit(14) != 3
            || dgeAbiStrDmg(14) != 6
            || dgeAbiInt(14) != 18
            || dgeAbiWis(14) != 18
            || dgeAbiDex(14) != 18
            || dgeAbiCon(14) != 18
            || dgeAbiCha(14) != 15
            || dgeCbtSizeIn(14) != 84
        )
            ++bad;
        // the Pack walk: AC 5, 30 hit points, 2-8 damage, 15 percent MR, 4
        // feet at the shoulder, attacking as 8 hit dice monsters, 950 xp per
        // hound, the all-sentinel class and ability rows
    if (dgeCbtAC(15) != 5
            || dgeCbtHP(15) != 30
            || dgeHoundDmgLo() != 2
            || dgeHoundDmgHi() != 8
            || dgeCbtMR(15) != 15
            || dgeCbtSizeIn(15) != 48
            || dgeHoundAttackHD() != 8
            || dgeHoundXpValue() != 950
            || dgeClsFighterLo(15) != 0
            || dgeAbiStr(15) != 0
            || dgeRosWildHunt(15) != 1
            || dgeRosRank(15) != 3
        )
            ++bad;
        // the Wild Hunt doctrine: ten miles out, 10 percent a mile, the 25
        // percent look, the 90 percent hunted, the 50 percent re-ensnare, the
        // pack of 20
    if (dgeHuntStartMiles() != 10
            || dgeHuntSpotPctPerMile() != 10
            || dgeHuntLookPct() != 25
            || dgeHuntHuntedPct() != 90
            || dgeHuntResnarePct() != 50
            || dgeHuntPackCount() != 20
            || dgeHuntHoundHP() != 30
        )
            ++bad;
        // the tathlum: one day per coat, one week to dry, one-half the hit
        // points from a relative, usable only once; the Torc of the Gods by
        // Goibhnie
    if (dgeTathlumCoatDays() != 1
            || dgeTathlumCoatWeeks() != 1
            || dgeTathlumRelativeDiv() != 2
        )
            ++bad;
        // the rank walk: the seven greater gods (Dagda, Arawn, Lugh,
        // Manannan, Nuada, Oghma, Silvanus), the five lesser (Brigit,
        // Diancecht, Dunatis, Goibhnie, Morrigan), the three no-rank (Cu
        // Chulainn, Math, the Master), the Pack monster format
    if (dgeRosRank(0) != 1
            || dgeRosRank(1) != 1
            || dgeRosRank(7) != 1
            || dgeRosRank(8) != 1
            || dgeRosRank(11) != 1
            || dgeRosRank(12) != 1
            || dgeRosRank(13) != 1
            || dgeRosRank(2) != 0
            || dgeRosRank(4) != 0
            || dgeRosRank(5) != 0
            || dgeRosRank(6) != 0
            || dgeRosRank(10) != 0
            || dgeRosRank(3) != 2
            || dgeRosRank(9) != 2
            || dgeRosRank(14) != 2
        )
            ++bad;
        // the alignment walk: Diancecht lawful good, Cu Chulainn neutral
        // good, Arawn lawful evil, Manannan chaotic neutral, the twelve
        // neutrals
    if (dgeRosAlign(4) != 0
            || dgeRosAlign(3) != 1
            || dgeRosAlign(1) != 6
            || dgeRosAlign(8) != 5
            || dgeRosAlign(0) != 4
            || dgeRosAlign(15) != 4
        )
            ++bad;
        // the fixed-damage walk: the eleven printed-figure rows and the five
        // See below or by-weapon rows
    if (dgeRosDmgFixed(0) != 1
            || dgeRosDmgFixed(1) != 1
            || dgeRosDmgFixed(2) != 1
            || dgeRosDmgFixed(3) != 1
            || dgeRosDmgFixed(4) != 1
            || dgeRosDmgFixed(5) != 1
            || dgeRosDmgFixed(6) != 1
            || dgeRosDmgFixed(10) != 1
            || dgeRosDmgFixed(13) != 1
            || dgeRosDmgFixed(15) != 1
            || dgeRosDmgFixed(7) != 0
            || dgeRosDmgFixed(8) != 0
            || dgeRosDmgFixed(9) != 0
            || dgeRosDmgFixed(11) != 0
            || dgeRosDmgFixed(12) != 0
            || dgeRosDmgFixed(14) != 0
        )
            ++bad;
        // the registry floor holds at 995 - zero defs touched this round
    if (dgeRegistryFloor() != 995
        )
            ++bad;
        printf("R853 Celtic mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
