    // ---- R852 Babylonian mythos audit ----
    // THE BABYLONIAN MYTHOS - the D&DG walk round four, print pp. 22-25: ten
    // beings (Anu, Anshar, Dahak, Druaga, Gilgamesh, Girru, Ishtar, Marduk,
    // Nergal, Ramman) - the pantheon-wide cleric doctrine of the kilt and the
    // tithe, and the ten stat blocks. Zero registry defs touched; the floor
    // holds at 995. The flagged eyeball cells: the Dahak move (the 9 over 18
    // of the second-print extract against the 9 over 15 of the archive.org
    // 1st print) and the Anu size (the 6 clean in both voices, the inch mark
    // garbled).
    {
        using namespace rules;
        int bad = 0;
    if (dgdRound() != 852
            || dgdPrintStart() != 22
            || dgdPrintEnd() != 25
            || dgdBeingCount() != 10
            || dgdTableCount() != 4
            || dgdChainCount() != 0
            || dgdRegistryFloor() != 995
            || dgdCbtRows() != 10
            || dgdClsRows() != 10
            || dgdAbiRows() != 10
            || dgdRosRows() != 10
            || dgdPlaneCount() != 8
            || dgdPsiClassVI() != 6
            || dgdAnuMaceDmgLo() != 2
            || dgdAnuMaceDmgHi() != 20
            || dgdAnuMaceBonus() != 7
            || dgdAnuCastSavePenalty() != 4
            || dgdAnuCommandSavePenalty() != 4
            || dgdAnuDragonSummonPerWeek() != 1
            || dgdAnsharBeamRangeYards() != 300
            || dgdAnsharBeamDamage() != 40
            || dgdAnsharSpellStoreLimit() != 200
            || dgdAnsharAlteredPerRound() != 1
            || dgdDahakHeadCount() != 3
            || dgdDahakBiteDmgLo() != 3
            || dgdDahakBiteDmgHi() != 30
            || dgdDahakNoAppearing() != 1
            || dgdDahakLairPct() != 25
            || dgdDahakXpValue() != 24000
            || dgdDahakLengthFeet() != 72
            || dgdDruagaMaceDamage() != 35
            || dgdDruagaDevilCallLo() != 2
            || dgdDruagaDevilCallHi() != 20
            || dgdDruagaArmCount() != 8
            || dgdDruagaLegCount() != 4
            || dgdGilgameshMacePlus() != 2
            || dgdGilgameshMaceDmgLo() != 2
            || dgdGilgameshMaceDmgHi() != 20
            || dgdGirruFireSpellLevel() != 40
            || dgdGirruHeatDamage() != 10
            || dgdGirruHeatFeet() != 10
            || dgdGirruAxePlus() != 3
            || dgdGirruAxeDmgLo() != 2
            || dgdGirruAxeDmgHi() != 20
            || dgdGirruStunLo() != 2
            || dgdGirruStunHi() != 8
            || dgdGirruPoisonSavePenalty() != 4
            || dgdIshtarSpellsPerRound() != 2
            || dgdIshtarLionCount() != 7
            || dgdIshtarLionHP() != 50
            || dgdIshtarLionHD() != 11
            || dgdIshtarLionAC() != -2
            || dgdIshtarChariotSpeed() != 21
            || dgdIshtarRodMult() != 10
            || dgdIshtarRodMinDamage() != 10
            || dgdIshtarRodMaxDamage() != 90
            || dgdMardukEyeCount() != 4
            || dgdMardukEarCount() != 4
            || dgdMardukNetRangeFeet() != 50
            || dgdMardukLightningDice() != 20
            || dgdMardukWeaponPlusToHit() != 3
            || dgdNergalShieldPlus() != 5
            || dgdNergalDeathAuraFeet() != 30
            || dgdNergalSpellFloor() != 8
            || dgdNergalReviveCount() != 5
            || dgdRammanSparkDamage() != 30
            || dgdRammanSparkRangeInches() != 3
            || dgdRammanBoltDamage() != 30
            || dgdRammanBoltsPerRound() != 2
            || dgdRammanSpellFloor() != 5
            || dgdRammanRingMailPlus() != 4
            || dgdRammanMalletDamage() != 30
            || dgdRammanMalletFeet() != 10
            || !dgdOriginsExtremelyAncient()
            || !dgdSourcesConflict()
            || !dgdClericKilt()
            || !dgdClericsRearOfBattle()
            || !dgdAdvancementByPayment()
            || !dgdPaymentNotLevel()
            || !dgdDangerousQuests()
            || !dgdNewMoonCeremony()
            || !dgdKingsQuestForRiches()
            || !dgdMinorLawFasting()
            || !dgdMajorTransgressionSpells()
            || !dgdDemiHumansDemons()
            || !dgdQuestAtonement()
            || !dgdHighPriestKing()
            || !dgdAloofFromPopulace()
            || !dgdStatePoliticalWork()
            || !dgdAnuDistributesMoney()
            || !dgdAnuSkyChief()
            || !dgdAnuAppearsAsMan()
            || !dgdAnuBreezeOfGaze()
            || !dgdAnuDisintegrationOnCast()
            || !dgdAnuVoiceOfLeaders()
            || !dgdAnuSummonsDragons()
            || !dgdAnuBrassMace()
            || !dgdAnuCreatedHeavensEarth()
            || !dgdAnuAllBowToAuthority()
            || !dgdAnsharGodOfDarkness()
            || !dgdAnsharDarkSkinned()
            || !dgdAnsharNightOnly()
            || !dgdAnsharBeamNoRegen()
            || !dgdAnsharTeleportsToShadow()
            || !dgdAnsharUnaffectedByLight()
            || !dgdAnsharGraspsSpells()
            || !dgdAnsharStartsWithNinths()
            || !dgdAnsharSenseSpells()
            || !dgdDahakDragonSpirit()
            || !dgdDahakEtherealExceptBite()
            || !dgdDahakScaleColorWhim()
            || !dgdDahakEatsLawfulGoodFlesh()
            || !dgdDahakAnyDragonBreath()
            || !dgdDahakCrunchesTeeth()
            || !dgdDahakNegatesDevices()
            || !dgdDahakAverageIntelligence()
            || !dgdDruagaDevilRuler()
            || !dgdDruagaBoyHead()
            || !dgdDruagaParalyzingUgliness()
            || !dgdDruagaShapeChange()
            || !dgdDruagaCallsDevils()
            || !dgdDruagaBreathImmune()
            || !dgdDruagaSoulObject()
            || !dgdDruagaSoulRegenerates()
            || !dgdDruagaHostUnaware()
            || !dgdDruagaBurialDoctrine()
            || !dgdDruagaAidsSacrificers()
            || !dgdDruagaMaceDevilMaker()
            || !dgdGilgameshHero()
            || !dgdGilgameshGetsThingsDone()
            || !dgdGilgameshPrefersWrestling()
            || !dgdGilgameshWrestledBullGod()
            || !dgdGilgameshTyrannical()
            || !dgdGilgameshGovernsWell()
            || !dgdGilgameshEarthlyPleasures()
            || !dgdGilgameshStubbornDirect()
            || !dgdGilgameshFearsDeath()
            || !dgdGilgameshCourageVsFoe()
            || !dgdGilgameshCannotBeCharmed()
            || !dgdGirruGodOfFire()
            || !dgdGirruManifestsAsMan()
            || !dgdGirruHatesEvil()
            || !dgdGirruUnaffectedByFire()
            || !dgdGirruTeleportsToFlame()
            || !dgdGirruHeatAura()
            || !dgdGirruPoisonBarb()
            || !dgdGirruStunningAxe()
            || !dgdGirruWeaponDisintegrate()
            || !dgdIshtarGoddessLoveWar()
            || !dgdIshtarBeautifulWomanOnly()
            || !dgdIshtarTitanStrength()
            || !dgdIshtarShapeChange()
            || !dgdIshtarVoiceSuggestion()
            || !dgdIshtarHeaddressLove()
            || !dgdIshtarHeaddressEnemyPowers()
            || !dgdIshtarFlyingChariot()
            || !dgdIshtarLionsUncontrollable()
            || !dgdIshtarNoMetalTouch()
            || !dgdIshtarRodEnergy()
            || !dgdMardukGodOfCity()
            || !dgdMardukNonhumanForm()
            || !dgdMardukFlameSpeech()
            || !dgdMardukLeadsWhenAnuBusy()
            || !dgdMardukBorrowsAbility()
            || !dgdMardukSilveryNet()
            || !dgdMardukWeatherInstant()
            || !dgdMardukJusticeBringer()
            || !dgdMardukTiamatLegend()
            || !dgdNergalGodOfUnderworld()
            || !dgdNergalRulesTheDead()
            || !dgdNergalHumanFormOnly()
            || !dgdNergalRevivesEnemies()
            || !dgdNergalBlackShield()
            || !dgdNergalNoBackAttack()
            || !dgdNergalDeathAura()
            || !dgdNergalBasaltAltar()
            || !dgdNergalPromisedSacrifice()
            || !dgdRammanGodOfStorms()
            || !dgdRammanHumanMassive()
            || !dgdRammanSparksOnHit()
            || !dgdRammanLightning()
            || !dgdRammanCloudMail()
            || !dgdRammanMalletReturns()
            || !dgdRammanMalletVsResisters()
            || !dgdRammanNightServices()
            || !dgdRammanRainSacrifices()
            || !dgdRammanAllNeutralsWorship()
        )
            ++bad;
        // the combat stat blocks of the ten beings (print pp. 22-25) - the
        // armor classes, hit points, moves, attacks, magic resistance and
        // sizes
        int CCbt[10][9] = {
            {-4,0,400,12,0,2,0,80,72},
            {2,0,300,12,0,0,0,50,72},
            {1,0,200,9,18,3,0,55,864},
            {-1,0,230,21,45,2,0,75,108},
            {6,0,180,15,0,2,0,10,72},
            {-2,0,280,18,0,2,0,50,72},
            {-4,0,250,12,0,2,0,75,72},
            {1,0,350,0,0,2,0,50,108},
            {1,0,300,12,12,2,0,99,72},
            {-4,0,325,12,48,2,0,50,84},
            };
        int nCbt[9] = {0,0,0,0,0,0,0,0,0};
        int eCbt[9] = {0,10,0,1,6,1,10,0,0};
        for (int b = 0;
             b < dgdCbtRows();
             ++b) {
            int vals[9];
            vals[0] = dgdCbtAC(b);
            vals[1] = dgdCbtACAlt(b);
            vals[2] = dgdCbtHP(b);
            vals[3] = dgdCbtMove(b);
            vals[4] = dgdCbtMoveAlt(b);
            vals[5] = dgdCbtAtN(b);
            vals[6] = dgdCbtAtD(b);
            vals[7] = dgdCbtMR(b);
            vals[8] = dgdCbtSizeIn(b);
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
        // the five-slot class grid of the ten beings - the cleric/druid,
        // fighter, magic-user/illusionist, thief/assassin and monk/bard lines
        // (99 = the printed See below)
        int CCls[10][11] = {
            {20,0,18,18,0,99,0,0,0,0,0},
            {20,0,18,18,0,99,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,15,15,0,15,0,0,15,0,0},
            {5,5,0,0,12,10,0,0,0,11,5},
            {0,0,16,16,0,99,0,0,0,0,0},
            {15,0,0,0,20,25,0,0,0,0,0},
            {0,0,19,19,0,16,0,0,0,0,15},
            {25,0,12,12,0,20,0,0,0,0,0},
            {0,0,17,17,0,15,15,0,0,0,0},
            };
        int nCls[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int eCls[11] = {5,9,3,3,8,1,9,10,9,9,8};
        for (int b = 0;
             b < dgdClsRows();
             ++b) {
            int vals[11];
            vals[0] = dgdClsCleric(b);
            vals[1] = dgdClsDruid(b);
            vals[2] = dgdClsFighterLo(b);
            vals[3] = dgdClsFighterHi(b);
            vals[4] = dgdClsRanger(b);
            vals[5] = dgdClsMagUser(b);
            vals[6] = dgdClsIllus(b);
            vals[7] = dgdClsThief(b);
            vals[8] = dgdClsAssassin(b);
            vals[9] = dgdClsMonk(b);
            vals[10] = dgdClsBard(b);
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
        // the six ability scores with the strength brackets of the ten beings
        // (Dahak the monster row reads the all-sentinel line)
        int CAbi[10][9] = {
            {19,3,7,25,25,25,25,25,0},
            {16,0,1,20,12,18,22,18,0},
            {0,0,0,0,0,0,0,0,0},
            {24,6,12,18,13,23,25,4,0},
            {20,3,8,18,17,18,19,18,0},
            {24,6,12,20,14,18,23,18,0},
            {25,7,14,22,12,25,23,25,0},
            {24,6,12,23,24,20,24,23,0},
            {19,3,7,20,20,19,23,24,0},
            {22,4,10,20,16,21,24,16,0},
            };
        int nAbi[9] = {0,0,0,0,0,0,0,0,0};
        int eAbi[9] = {1,2,1,1,1,1,1,1,10};
        for (int b = 0;
             b < dgdAbiRows();
             ++b) {
            int vals[9];
            vals[0] = dgdAbiStr(b);
            vals[1] = dgdAbiStrHit(b);
            vals[2] = dgdAbiStrDmg(b);
            vals[3] = dgdAbiInt(b);
            vals[4] = dgdAbiWis(b);
            vals[5] = dgdAbiDex(b);
            vals[6] = dgdAbiCon(b);
            vals[7] = dgdAbiCha(b);
            vals[8] = dgdAbiPsi(b);
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
        // the roster walk of the ten beings - ordinals, pages, alignments,
        // ranks, psionic classes, planes, the fixed-damage flags, the Dahak
        // lair percent and ethereal doctrine
        int CRos[10][9] = {
            {0,22,3,1,6,1,1,0,0},
            {1,22,8,0,6,2,0,0,0},
            {2,23,8,3,0,0,1,25,1},
            {3,23,6,0,0,3,1,0,0},
            {4,23,1,2,0,0,1,0,0},
            {5,24,0,0,0,4,1,0,0},
            {6,24,4,1,0,5,0,0,0},
            {7,24,3,1,0,6,0,0,0},
            {8,25,7,0,0,7,0,0,0},
            {9,25,4,0,0,8,1,0,0},
            };
        int nRos[9] = {0,0,0,0,0,0,0,0,0};
        int eRos[9] = {1,0,1,5,8,2,4,9,9};
        for (int b = 0;
             b < dgdRosRows();
             ++b) {
            int vals[9];
            vals[0] = dgdRosOrd(b);
            vals[1] = dgdRosPage(b);
            vals[2] = dgdRosAlign(b);
            vals[3] = dgdRosRank(b);
            vals[4] = dgdRosPsiClass(b);
            vals[5] = dgdRosPlane(b);
            vals[6] = dgdRosDmgFixed(b);
            vals[7] = dgdRosLairPct(b);
            vals[8] = dgdRosEthereal(b);
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
        // the census walk (the four grids, the ten beings, the eight planes)
    if (dgdTableCount() != 4
            || dgdBeingCount() != 10
            || dgdCbtRows() != 10
            || dgdClsRows() != 10
            || dgdAbiRows() != 10
            || dgdRosRows() != 10
            || dgdPlaneCount() != 8
            || dgdChainCount() != 0
        )
            ++bad;
        // the print walk spans pp. 22-25 (the folio offset PRINT = PDF - 1)
    if (dgdPrintStart() != 22
            || dgdPrintEnd() != 25
        )
            ++bad;
        // the roster ordinals run 0-9 in print order (Anu first, Ramman last)
    if (dgdRosOrd(0) != 0
            || dgdRosOrd(9) != 9
            || dgdRosPage(0) != 22
            || dgdRosPage(9) != 25
        )
            ++bad;
        // the alignment walk: Girru lawful good, Gilgamesh neutral good, Anu
        // and Marduk lawful neutral, Ishtar and Ramman neutral, Druaga lawful
        // evil, Nergal neutral evil, Anshar and Dahak chaotic evil
    if (dgdRosAlign(5) != 0
            || dgdRosAlign(4) != 1
            || dgdRosAlign(0) != 3
            || dgdRosAlign(7) != 3
            || dgdRosAlign(6) != 4
            || dgdRosAlign(9) != 4
            || dgdRosAlign(3) != 6
            || dgdRosAlign(8) != 7
            || dgdRosAlign(1) != 8
            || dgdRosAlign(2) != 8
        )
            ++bad;
        // the rank walk: the three greater gods (Anu, Ishtar, Marduk), the
        // hero Gilgamesh, the monster Dahak, the five lesser gods
    if (dgdRosRank(0) != 1
            || dgdRosRank(6) != 1
            || dgdRosRank(7) != 1
            || dgdRosRank(4) != 2
            || dgdRosRank(2) != 3
        )
            ++bad;
        // the Anu walk: AC -4, 400 hit points, 2 attacks, 80 percent magic
        // resistance, the brass mace 2-20 plus 7
    if (dgdCbtAC(0) != -4
            || dgdCbtHP(0) != 400
            || dgdCbtAtN(0) != 2
            || dgdCbtMR(0) != 80
            || dgdAnuMaceDmgLo() != 2
            || dgdAnuMaceDmgHi() != 20
            || dgdAnuMaceBonus() != 7
        )
            ++bad;
        // the Anu class and ability walk: 20th cleric, 18th fighter, the See
        // below magic-user, S:19(+3,+7) and the 25 line, psionic class VI
    if (dgdClsCleric(0) != 20
            || dgdClsFighterLo(0) != 18
            || dgdClsFighterHi(0) != 18
            || dgdClsMagUser(0) != 99
            || dgdAbiStr(0) != 19
            || dgdAbiStrHit(0) != 3
            || dgdAbiStrDmg(0) != 7
            || dgdAbiInt(0) != 25
            || dgdAbiWis(0) != 25
            || dgdAbiDex(0) != 25
            || dgdAbiCon(0) != 25
            || dgdAbiCha(0) != 25
            || dgdRosPsiClass(0) != 6
            || dgdPsiClassVI() != 6
        )
            ++bad;
        // the Anu doctrines: the -4 casting and command saves, the
        // once-a-week dragon summon
    if (dgdAnuCastSavePenalty() != 4
            || dgdAnuCommandSavePenalty() != 4
            || dgdAnuDragonSummonPerWeek() != 1
        )
            ++bad;
        // the Anshar walk: AC 2, 300 hit points, the printed 0 attacks, Nil
        // damage, 50 percent MR, the 300-yard 40-point beam, the 200-level
        // store
    if (dgdCbtAC(1) != 2
            || dgdCbtHP(1) != 300
            || dgdCbtAtN(1) != 0
            || dgdRosDmgFixed(1) != 0
            || dgdCbtMR(1) != 50
            || dgdAnsharBeamRangeYards() != 300
            || dgdAnsharBeamDamage() != 40
            || dgdAnsharSpellStoreLimit() != 200
        )
            ++bad;
        // the Anshar class and ability walk: 20th cleric, 18th fighter,
        // S:16(0,+1) I:20 W:12 D:18 C:22 CH:18
    if (dgdClsCleric(1) != 20
            || dgdClsFighterLo(1) != 18
            || dgdClsMagUser(1) != 99
            || dgdAbiStr(1) != 16
            || dgdAbiStrHit(1) != 0
            || dgdAbiStrDmg(1) != 1
            || dgdAbiInt(1) != 20
            || dgdAbiWis(1) != 12
            || dgdAbiDex(1) != 18
            || dgdAbiCon(1) != 22
            || dgdAbiCha(1) != 18
        )
            ++bad;
        // the Dahak walk: AC 1 or ethereal, 200 hit points, 3 attacks, 3-30
        // x3, 55 percent MR, 25 percent in lair, X/24,000
    if (dgdCbtAC(2) != 1
            || dgdCbtHP(2) != 200
            || dgdCbtAtN(2) != 3
            || dgdDahakBiteDmgLo() != 3
            || dgdDahakBiteDmgHi() != 30
            || dgdDahakHeadCount() != 3
            || dgdCbtMR(2) != 55
            || dgdRosLairPct(2) != 25
            || dgdDahakLairPct() != 25
            || dgdDahakXpValue() != 24000
            || dgdDahakNoAppearing() != 1
        )
            ++bad;
        // the flagged eyeball cell: the Dahak move 9 over 18 (the
        // second-print extract against the IA 1st-print 15), the 72-foot
        // length, the ethereal flag
    if (dgdCbtMove(2) != 9
            || dgdCbtMoveAlt(2) != 18
            || dgdDahakLengthFeet() != 72
            || dgdCbtSizeIn(2) != 864
            || dgdRosEthereal(2) != 1
        )
            ++bad;
        // the Dahak monster row: no class grid, no ability grid, no plane
    if (dgdClsCleric(2) != 0
            || dgdClsFighterLo(2) != 0
            || dgdAbiStr(2) != 0
            || dgdAbiCha(2) != 0
            || dgdAbiPsi(2) != 0
            || dgdRosPlane(2) != 0
        )
            ++bad;
        // the Druaga walk: AC -1, 230 hit points, 21 over 45, the 35-point
        // mace, fighter 15, magic-user 15, assassin 15
    if (dgdCbtAC(3) != -1
            || dgdCbtHP(3) != 230
            || dgdCbtMove(3) != 21
            || dgdCbtMoveAlt(3) != 45
            || dgdDruagaMaceDamage() != 35
            || dgdClsFighterLo(3) != 15
            || dgdClsMagUser(3) != 15
            || dgdClsAssassin(3) != 15
        )
            ++bad;
        // the Druaga charisma adjudication: the printed 4 (the single-glyph
        // 15px TSV width against the 24px two-digit 18 calibration),
        // S:24(+6,+12)
    if (dgdAbiCha(3) != 4
            || dgdAbiStr(3) != 24
            || dgdAbiStrHit(3) != 6
            || dgdAbiStrDmg(3) != 12
            || dgdAbiInt(3) != 18
            || dgdAbiWis(3) != 13
            || dgdAbiDex(3) != 23
            || dgdAbiCon(3) != 25
        )
            ++bad;
        // the Druaga devil call: 2-20 a day, never arch-devils; the Nine
        // Hells plane
    if (dgdDruagaDevilCallLo() != 2
            || dgdDruagaDevilCallHi() != 20
            || dgdDruagaArmCount() != 8
            || dgdDruagaLegCount() != 4
            || dgdRosPlane(3) != 3
        )
            ++bad;
        // the Gilgamesh walk: AC 6, 180 hit points, 15-inch move, the 2
        // attacks (the IA xml word against the Termux 3 fold), 10 percent MR
    if (dgdCbtAC(4) != 6
            || dgdCbtHP(4) != 180
            || dgdCbtMove(4) != 15
            || dgdCbtAtN(4) != 2
            || dgdCbtMR(4) != 10
        )
            ++bad;
        // the Gilgamesh class walk: 5th cleric and druid in each, 12th
        // ranger, 10th magic-user, 11th monk, 5th bard, the +2 mace 2-20
    if (dgdClsCleric(4) != 5
            || dgdClsDruid(4) != 5
            || dgdClsRanger(4) != 12
            || dgdClsMagUser(4) != 10
            || dgdClsMonk(4) != 11
            || dgdClsBard(4) != 5
            || dgdGilgameshMacePlus() != 2
            || dgdGilgameshMaceDmgLo() != 2
            || dgdGilgameshMaceDmgHi() != 20
        )
            ++bad;
        // the Gilgamesh ability walk: S:20(+3,+8) I:18 W:17 D:18 C:19 CH:18
    if (dgdAbiStr(4) != 20
            || dgdAbiStrHit(4) != 3
            || dgdAbiStrDmg(4) != 8
            || dgdAbiInt(4) != 18
            || dgdAbiWis(4) != 17
            || dgdAbiDex(4) != 18
            || dgdAbiCon(4) != 19
            || dgdAbiCha(4) != 18
        )
            ++bad;
        // the Girru walk: AC -2, 280 hit points, 18-inch move, the +3 axe
        // (the IA voice against the Termux +43 garble), the 40th level
        // fire-spell See below
    if (dgdCbtAC(5) != -2
            || dgdCbtHP(5) != 280
            || dgdCbtMove(5) != 18
            || dgdGirruAxePlus() != 3
            || dgdGirruAxeDmgLo() != 2
            || dgdGirruAxeDmgHi() != 20
            || dgdGirruFireSpellLevel() != 40
            || dgdClsMagUser(5) != 99
        )
            ++bad;
        // the Girru doctrine walk: the 10-point 10-foot heat aura, the 2-8
        // stun, the -4 poison save, the Seven Heavens
    if (dgdGirruHeatDamage() != 10
            || dgdGirruHeatFeet() != 10
            || dgdGirruStunLo() != 2
            || dgdGirruStunHi() != 8
            || dgdGirruPoisonSavePenalty() != 4
            || dgdRosPlane(5) != 4
        )
            ++bad;
        // the Ishtar walk: AC -4, 250 hit points, 15th cleric, 20th ranger,
        // 25th magic-user, the Elysium plane
    if (dgdCbtAC(6) != -4
            || dgdCbtHP(6) != 250
            || dgdClsCleric(6) != 15
            || dgdClsRanger(6) != 20
            || dgdClsMagUser(6) != 25
            || dgdRosPlane(6) != 5
        )
            ++bad;
        // the Ishtar chariot: 7 lions of 50 hit points, 11 hit dice, armor
        // class -2, the 21-inch chariot, the rod times ten (10 to 90), 2
        // spells per round
    if (dgdIshtarLionCount() != 7
            || dgdIshtarLionHP() != 50
            || dgdIshtarLionHD() != 11
            || dgdIshtarLionAC() != -2
            || dgdIshtarChariotSpeed() != 21
            || dgdIshtarRodMult() != 10
            || dgdIshtarRodMinDamage() != 10
            || dgdIshtarRodMaxDamage() != 90
            || dgdIshtarSpellsPerRound() != 2
        )
            ++bad;
        // the Ishtar ability walk: S:25(+7,+14) I:22 W:12 D:25 C:23 CH:25
    if (dgdAbiStr(6) != 25
            || dgdAbiStrHit(6) != 7
            || dgdAbiStrDmg(6) != 14
            || dgdAbiInt(6) != 22
            || dgdAbiWis(6) != 12
            || dgdAbiDex(6) != 25
            || dgdAbiCon(6) != 23
            || dgdAbiCha(6) != 25
        )
            ++bad;
        // the Marduk walk: AC 1, 350 hit points, the printed Infinite move
        // (the 0 sentinel), +3 or better to hit, fighter 19, magic-user 16,
        // bard 15
    if (dgdCbtAC(7) != 1
            || dgdCbtHP(7) != 350
            || dgdCbtMove(7) != 0
            || dgdCbtMoveAlt(7) != 0
            || dgdMardukWeaponPlusToHit() != 3
            || dgdClsFighterLo(7) != 19
            || dgdClsMagUser(7) != 16
            || dgdClsBard(7) != 15
        )
            ++bad;
        // the Marduk doctrine walk: the four eyes and ears, the 50-foot net
        // range, the 20-dice lightning, the Arcadia plane
    if (dgdMardukEyeCount() != 4
            || dgdMardukEarCount() != 4
            || dgdMardukNetRangeFeet() != 50
            || dgdMardukLightningDice() != 20
            || dgdRosPlane(7) != 6
            || dgdCbtSizeIn(7) != 108
        )
            ++bad;
        // the Marduk ability walk: S:24(+6,+12) I:23 W:24 D:20 C:24 CH:23
    if (dgdAbiStr(7) != 24
            || dgdAbiStrHit(7) != 6
            || dgdAbiStrDmg(7) != 12
            || dgdAbiInt(7) != 23
            || dgdAbiWis(7) != 24
            || dgdAbiDex(7) != 20
            || dgdAbiCon(7) != 24
            || dgdAbiCha(7) != 23
        )
            ++bad;
        // the Nergal walk: AC 1, 300 hit points, the 12 over 12 move, the See
        // below magic resistance (the 99 sentinel), 25th cleric, the Hades
        // plane
    if (dgdCbtAC(8) != 1
            || dgdCbtHP(8) != 300
            || dgdCbtMove(8) != 12
            || dgdCbtMoveAlt(8) != 12
            || dgdCbtMR(8) != 99
            || dgdClsCleric(8) != 25
            || dgdRosPlane(8) != 7
        )
            ++bad;
        // the Nergal shield doctrine: +5, no back attack, the 30-foot death
        // aura, the eighth-level spell floor, the 5 revived enemies
    if (dgdNergalShieldPlus() != 5
            || dgdNergalDeathAuraFeet() != 30
            || dgdNergalSpellFloor() != 8
            || dgdNergalReviveCount() != 5
        )
            ++bad;
        // the Ramman walk: AC -4, 325 hit points, 12 over 48, the 30-point
        // damage, magic-user and illusionist 15th in each, the Concordant
        // Opposition plane
    if (dgdCbtAC(9) != -4
            || dgdCbtHP(9) != 325
            || dgdCbtMove(9) != 12
            || dgdCbtMoveAlt(9) != 48
            || dgdRammanBoltDamage() != 30
            || dgdClsMagUser(9) != 15
            || dgdClsIllus(9) != 15
            || dgdRosPlane(9) != 8
            || dgdCbtSizeIn(9) != 84
        )
            ++bad;
        // the Ramman doctrine walk: the 30-point sparks within 3 inches, 2
        // bolts per round, the fifth-level spell floor, the +4 cloud-vapor
        // mail, the 10-foot mallet
    if (dgdRammanSparkDamage() != 30
            || dgdRammanSparkRangeInches() != 3
            || dgdRammanBoltsPerRound() != 2
            || dgdRammanSpellFloor() != 5
            || dgdRammanRingMailPlus() != 4
            || dgdRammanMalletDamage() != 30
            || dgdRammanMalletFeet() != 10
        )
            ++bad;
        // the fixed-damage walk: the six printed-figure rows (Anu, Dahak,
        // Druaga, Gilgamesh, Girru, Ramman) and the four See below / Nil rows
    if (dgdRosDmgFixed(0) != 1
            || dgdRosDmgFixed(2) != 1
            || dgdRosDmgFixed(3) != 1
            || dgdRosDmgFixed(4) != 1
            || dgdRosDmgFixed(5) != 1
            || dgdRosDmgFixed(9) != 1
            || dgdRosDmgFixed(1) != 0
            || dgdRosDmgFixed(6) != 0
            || dgdRosDmgFixed(7) != 0
            || dgdRosDmgFixed(8) != 0
        )
            ++bad;
        // the plane walk: Nirvana, Pandemonium, Nine Hells, Seven Heavens,
        // Elysium, Arcadia, Hades, Concordant Opposition
    if (dgdRosPlane(0) != 1
            || dgdRosPlane(1) != 2
            || dgdRosPlane(3) != 3
            || dgdRosPlane(5) != 4
            || dgdRosPlane(6) != 5
            || dgdRosPlane(7) != 6
            || dgdRosPlane(8) != 7
            || dgdRosPlane(9) != 8
        )
            ++bad;
        // the registry floor holds at 995 - zero defs touched this round
    if (dgdRegistryFloor() != 995
        )
            ++bad;
        printf("R852 Babylonian mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
