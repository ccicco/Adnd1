    // ---- R854 Central American mythos audit ----
    // THE CENTRAL AMERICAN MYTHOS - the D&DG walk round six, print pp. 32-36:
    // fourteen beings (Quetzalcoatl, Camaxtli, Chalchiuhtlicue, Camazotz,
    // Huhueteotl, Huitzilopochtli, Hunapu and Xbalanque the twin heroes,
    // Itzamna, Tezcatlipoca, Mictlantecuhtli, Tlaloc, Tlazolteotl,
    // Xochipilli), the clerical doctrine of the elite clerics, the 20-day
    // rituals and the compass directions, all of it on the one parallel Prime
    // Material Plane. Zero registry defs touched; the floor holds at 995. The
    // flagged eyeball cells: the Tlazolteotl hit points (the 2nd-print
    // extract reads 211, the IA 1st print 217 - the Gawaine 112 precedent),
    // the Tezcatlipoca psionic class (pinned II on the 28px two-glyph IA word
    // against the Termux single I), and the twin heroes size (pinned 5 foot
    // 4, the R853 foot-mark-misread decode of the printed 54 cell).
    {
        using namespace rules;
        int bad = 0;
    if (dgfRound() != 854
            || dgfPrintStart() != 32
            || dgfPrintEnd() != 36
            || dgfBeingCount() != 14
            || dgfTableCount() != 4
            || dgfChainCount() != 0
            || dgfRegistryFloor() != 995
            || dgfCbtRows() != 14
            || dgfClsRows() != 14
            || dgfAbiRows() != 14
            || dgfRosRows() != 14
            || dgfPlaneCount() != 1
            || dgfPsiClassI() != 1
            || dgfPsiClassII() != 2
            || dgfPsiClassVI() != 6
            || dgfRitualPeriodDays() != 20
            || dgfCompassDieSides() != 4
            || dgfCompassHitPlus() != 1
            || dgfCompassSaveMinus() != 1
            || dgfCamaxtliSacrificeGP() != 500000
            || dgfCamaxtliFavorPct() != 25
            || dgfCamaxtliRegenPerMelee() != 5
            || dgfChalchiuhtlicueTransformLo() != 3
            || dgfChalchiuhtlicueTransformHi() != 300
            || dgfChalchiuhtlicueRitualClearMiles() != 1
            || dgfChalchiuhtlicueClericPct() != 25
            || dgfChalchiuhtlicueWorshiperPct() != 1
            || dgfChalchiuhtlicueAttemptsPerYear() != 4
            || dgfCamazotzBatCount() != 1000
            || dgfCamazotzClawDmgLo() != 2
            || dgfCamazotzClawDmgHi() != 20
            || dgfCamazotzBiteDmgLo() != 3
            || dgfCamazotzBiteDmgHi() != 30
            || dgfHuhueteotlBeamDamage() != 50
            || dgfHuhueteotlBeamRangeMiles() != 2
            || dgfHuhueteotlTimeCycleYears() != 52
            || dgfHuitzilopochtliAxeDmgLo() != 3
            || dgfHuitzilopochtliAxeDmgHi() != 30
            || dgfHuitzilopochtliAxeStrBonus() != 14
            || dgfHuitzilopochtliAppearPct() != 5
            || dgfHuitzilopochtliRaisedSaveBonus() != 3
            || dgfTwinBlowgunRangeYards() != 200
            || dgfTwinBlowgunShortYards() != 50
            || dgfTwinBlowgunMediumYards() != 135
            || dgfTwinAxeDmgLo() != 1
            || dgfTwinAxeDmgHi() != 10
            || dgfTwinAxePlus() != 6
            || dgfTwinResistPerDie() != 1
            || dgfItzamnaStaffDmgLo() != 3
            || dgfItzamnaStaffDmgHi() != 24
            || dgfItzamnaNimbusRadiusFeet() != 6
            || dgfItzamnaWeaponPlusToHit() != 2
            || dgfTezcatlipocaClawDmgLo() != 3
            || dgfTezcatlipocaClawDmgHi() != 30
            || dgfMictlantecuhtliSkeletonLo() != 20
            || dgfMictlantecuhtliSkeletonHi() != 200
            || dgfMictlantecuhtliGhoulLo() != 10
            || dgfMictlantecuhtliGhoulHi() != 100
            || dgfMictlantecuhtliWightLo() != 6
            || dgfMictlantecuhtliWightHi() != 36
            || dgfMictlantecuhtliSpectreLo() != 2
            || dgfMictlantecuhtliSpectreHi() != 5
            || dgfMictlantecuhtliSacrificeGate() != 50
            || dgfTlalocPitcherCount() != 4
            || dgfTlalocLightningArmor() != 40
            || dgfTlalocLightningClothed() != 30
            || dgfTlalocLightningNaked() != 20
            || dgfTlazolteotlChaAlt() != -5
            || dgfXochipilliAxeDmgLo() != 3
            || dgfXochipilliAxeDmgHi() != 30
            || !dgfAztecMayaMoralBackground()
            || !dgfInscrutableMotives()
            || !dgfFromTheStars()
            || !dgfParallelPrimeMaterial()
            || !dgfCommuneGateParallelOnly()
            || !dgfNoSummonWithoutCeremonies()
            || !dgfNoTravelBeyondWorshipers()
            || !dgfEliteClerics()
            || !dgfAbsoluteAuthorityOverPeasants()
            || !dgfHigherLevelsCommandLesser()
            || !dgfSectInfighting()
            || !dgfSacrificeFoodSpringFall()
            || !dgfSacrificeHumansBattles()
            || !dgfForcedAttendance()
            || !dgfTempleStepPyramid()
            || !dgfEntrancesFourCompassPoints()
            || !dgfAltarTopEast()
            || !dgfPunishmentSwift()
            || !dgfMinorMistakesCostWealthXP()
            || !dgfMajorFailuresStripAll()
            || !dgfCompassDirectionChosen()
            || !dgfEastRed()
            || !dgfSouthYellow()
            || !dgfWestBlack()
            || !dgfNorthWhite()
            || !dgfQuetzalcoatlAirGod()
            || !dgfQuetzalcoatlBewilderingForms()
            || !dgfQuetzalcoatlWorksWithWorshipers()
            || !dgfQuetzalcoatlMonsterFormBattle()
            || !dgfQuetzalcoatlQuadrupleOnLoss()
            || !dgfQuetzalcoatlFightsToEnd()
            || !dgfQuetzalcoatlSameFormImmune()
            || !dgfQuetzalcoatlMightiestDisputed()
            || !dgfQuetzalcoatlPatronOfArts()
            || !dgfCamaxtliFateGod()
            || !dgfCamaxtliSeesPastFuture()
            || !dgfCamaxtliNotAllowedToKill()
            || !dgfCamaxtliRecreatesDamageForce()
            || !dgfCamaxtliCastIntoBeyond()
            || !dgfChalchiuhtlicueWaterLove()
            || !dgfChalchiuhtlicueLifeAndChasteLove()
            || !dgfChalchiuhtlicueAidsAnyAlignment()
            || !dgfChalchiuhtlicueTransformSavesDevout()
            || !dgfChalchiuhtlicueJadeQuality()
            || !dgfChalchiuhtlicueFullMoonRitual()
            || !dgfChalchiuhtlicueWifeOfTlaloc()
            || !dgfCamazotzBatGod()
            || !dgfCamazotzInsectTemptation()
            || !dgfCamazotzInsectPlagueAppeasement()
            || !dgfCamazotzParalyticSave()
            || !dgfCamazotzDarknessWeaponsPass()
            || !dgfHuhueteotlFireGod()
            || !dgfHuhueteotlFrequentSacrifices()
            || !dgfHuhueteotlPunishesWithFlames()
            || !dgfHuhueteotlClothingGemsSacrifice()
            || !dgfHuhueteotlWaningMoon()
            || !dgfHuhueteotlStopMotion()
            || !dgfHuhueteotlStoppedImmune()
            || !dgfHuitzilopochtliWarGod()
            || !dgfHuitzilopochtliBattlefieldAid()
            || !dgfHuitzilopochtliNeverCommuned()
            || !dgfHuitzilopochtliRearAttacksReturn()
            || !dgfHuitzilopochtliBattleSacrifices()
            || !dgfHuitzilopochtliDeadWarriorBody()
            || !dgfHuitzilopochtliRaisedRegardless()
            || !dgfTwinHeroes()
            || !dgfTwinRevengeThirst()
            || !dgfTwinUnderworldVictory()
            || !dgfTwinBlowgunExperts()
            || !dgfTwinAvoidMelee()
            || !dgfTwinPoisonedDarts()
            || !dgfItzamnaMedicineGod()
            || !dgfItzamnaLightForms()
            || !dgfItzamnaTravelsWorldOfMen()
            || !dgfItzamnaSeesAllWithLight()
            || !dgfItzamnaFriendOfMen()
            || !dgfItzamnaIntercedes()
            || !dgfItzamnaWitsOverArms()
            || !dgfItzamnaSonOfTezcatlipoca()
            || !dgfItzamnaCallsFather()
            || !dgfItzamnaNimbusRobe()
            || !dgfItzamnaDrawsSymbols()
            || !dgfItzamnaClericSpells()
            || !dgfItzamnaClericGarb()
            || !dgfItzamnaRedHandNecklace()
            || !dgfItzamnaBalsamSquirrels()
            || !dgfTezcatlipocaSunGod()
            || !dgfTezcatlipocaPlotsOverthrow()
            || !dgfTezcatlipocaPatronOfTreachery()
            || !dgfTezcatlipocaInvisibleEthereal()
            || !dgfTezcatlipocaJaguarBear()
            || !dgfTezcatlipocaHumanMasquerade()
            || !dgfTezcatlipocaAnnualHeartSacrifice()
            || !dgfTezcatlipocaPamperedVictim()
            || !dgfTezcatlipocaDisorderAndWealth()
            || !dgfMictlantecuhtliDeathGod()
            || !dgfMictlantecuhtliCommandsUndead()
            || !dgfMictlantecuhtliDarkOfMoon()
            || !dgfMictlantecuhtliFromWorshipers()
            || !dgfMictlantecuhtliTouchDeath()
            || !dgfMictlantecuhtliSpellsInBattle()
            || !dgfMictlantecuhtliJadeRod()
            || !dgfTlalocRainGod()
            || !dgfTlalocFullMoonChild()
            || !dgfTlalocAnnualFestival()
            || !dgfTlalocCookAndEat()
            || !dgfTlalocCryingGoodSign()
            || !dgfTlalocGrantsRain()
            || !dgfTlalocPunishes()
            || !dgfTlalocPitcherGood()
            || !dgfTlalocPitcherBlight()
            || !dgfTlalocPitcherFrost()
            || !dgfTlalocPitcherRot()
            || !dgfTlalocBoltAsWeapon()
            || !dgfTlazolteotlViceGoddess()
            || !dgfTlazolteotlMonsterIllusion()
            || !dgfTlazolteotlBeautifulAtEase()
            || !dgfTlazolteotlRuinsLawfulGood()
            || !dgfTlazolteotlNeverFightsPhysically()
            || !dgfTlazolteotlCharmFavorite()
            || !dgfTlazolteotlEvilCannotHarm()
            || !dgfXochipilliGamblingGod()
            || !dgfXochipilliWanderingLuck()
            || !dgfXochipilliPeaceful()
            || !dgfXochipilliCalculatedRisk()
            || !dgfXochipilliNeverMisses()
            || !dgfXochipilliWeaponsMiss()
        )
            ++bad;
        // the combat stat blocks of the fourteen beings (print pp. 32-36) -
        // the armor classes, hit points, moves, attacks, magic resistance and
        // sizes
        int CdgfCbt[14][9] = {
            {-2,0,400,-1,0,0,0,75,180},
            {-2,0,350,15,24,0,0,50,180},
            {-2,0,200,-1,0,3,2,95,76},
            {-2,0,362,-1,0,3,0,50,180},
            {-2,0,373,18,24,0,0,80,180},
            {-3,0,389,12,24,3,0,50,180},
            {2,0,150,12,0,3,2,0,64},
            {2,0,150,12,0,3,2,0,64},
            {-3,0,369,-1,0,2,0,85,0},
            {-2,0,400,-1,0,2,0,85,0},
            {-2,0,339,-1,0,2,0,95,180},
            {-2,0,377,12,24,3,2,50,180},
            {-3,0,211,-1,0,0,0,25,180},
            {-5,0,381,-1,0,3,2,25,192},
            };
        int ndgfCbt[9] = {0,0,0,0,0,0,0,0,0};
        int edgfCbt[9] = {0,14,0,0,10,4,9,2,2};
        for (int b = 0;
             b < dgfCbtRows();
             ++b) {
            int vals[9];
            vals[0] = dgfCbtAC(b);
            vals[1] = dgfCbtACAlt(b);
            vals[2] = dgfCbtHP(b);
            vals[3] = dgfCbtMove(b);
            vals[4] = dgfCbtMoveAlt(b);
            vals[5] = dgfCbtAtN(b);
            vals[6] = dgfCbtAtD(b);
            vals[7] = dgfCbtMR(b);
            vals[8] = dgfCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CdgfCbt[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++ndgfCbt[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (ndgfCbt[c] != edgfCbt[c])
                ++bad;
        // the five-slot class grid of the fourteen beings (the paladin
        // fighter slots, the ranger slots, the in-each cells)
        int CdgfCls[14][11] = {
            {25,13,20,20,0,20,20,20,0,0,20},
            {20,0,12,12,0,18,0,0,0,0,0},
            {20,0,12,12,0,20,0,0,0,0,15},
            {15,0,10,10,0,20,20,0,15,0,0},
            {15,10,10,10,0,15,15,0,15,10,0},
            {13,13,0,0,20,8,8,0,15,10,0},
            {0,10,0,0,10,8,8,0,0,0,0},
            {0,10,0,0,10,8,8,0,0,0,0},
            {22,0,13,13,0,15,0,0,0,0,0},
            {9,0,20,20,0,15,0,0,15,0,6},
            {14,14,0,0,15,18,18,0,15,0,0},
            {20,0,10,10,0,20,0,0,0,0,0},
            {14,14,0,0,0,15,25,0,15,0,15},
            {12,12,12,12,0,12,12,12,0,12,12},
            };
        int ndgfCls[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int edgfCls[11] = {2,6,5,5,10,0,5,12,8,11,9};
        for (int b = 0;
             b < dgfClsRows();
             ++b) {
            int vals[11];
            vals[0] = dgfClsCleric(b);
            vals[1] = dgfClsDruid(b);
            vals[2] = dgfClsFighterLo(b);
            vals[3] = dgfClsFighterHi(b);
            vals[4] = dgfClsRanger(b);
            vals[5] = dgfClsMagUser(b);
            vals[6] = dgfClsIllus(b);
            vals[7] = dgfClsThief(b);
            vals[8] = dgfClsAssassin(b);
            vals[9] = dgfClsMonk(b);
            vals[10] = dgfClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CdgfCls[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++ndgfCls[c];
            }
        }
        for (int c = 0; c < 11; ++c)
            if (ndgfCls[c] != edgfCls[c])
                ++bad;
        // the six ability scores with the strength brackets of the fourteen
        // beings
        int CdgfAbi[14][9] = {
            {25,7,14,25,25,25,25,25,0},
            {23,0,0,24,23,23,23,23,0},
            {15,0,0,24,25,25,23,25,0},
            {19,3,7,20,18,20,24,-2,0},
            {23,0,0,23,23,23,23,9,0},
            {25,7,14,23,20,25,25,25,0},
            {18,3,6,16,12,18,18,18,0},
            {18,3,6,16,12,18,18,18,0},
            {21,4,9,24,25,17,21,23,0},
            {25,7,14,25,24,25,25,25,0},
            {25,7,14,24,19,23,24,-4,0},
            {20,3,8,24,23,24,24,19,0},
            {10,0,0,25,18,25,25,24,0},
            {24,6,12,24,20,25,24,25,0},
            };
        int ndgfAbi[9] = {0,0,0,0,0,0,0,0,0};
        int edgfAbi[9] = {0,4,4,0,0,0,0,0,14};
        for (int b = 0;
             b < dgfAbiRows();
             ++b) {
            int vals[9];
            vals[0] = dgfAbiStr(b);
            vals[1] = dgfAbiStrHit(b);
            vals[2] = dgfAbiStrDmg(b);
            vals[3] = dgfAbiInt(b);
            vals[4] = dgfAbiWis(b);
            vals[5] = dgfAbiDex(b);
            vals[6] = dgfAbiCon(b);
            vals[7] = dgfAbiCha(b);
            vals[8] = dgfAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CdgfAbi[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++ndgfAbi[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (ndgfAbi[c] != edgfAbi[c])
                ++bad;
        // the roster walk of the fourteen beings - ordinals, pages,
        // alignments, ranks, psionic classes, the single parallel plane, the
        // fixed-damage, in-each and twin-pair flags
        int CdgfRos[14][9] = {
            {0,32,3,1,1,1,0,1,0},
            {1,33,4,1,1,1,0,0,0},
            {2,33,2,0,1,1,1,0,0},
            {3,33,8,0,1,1,1,1,0},
            {4,33,8,1,1,1,0,1,0},
            {5,34,4,0,1,1,1,1,0},
            {6,34,0,2,0,0,1,0,1},
            {7,34,0,2,0,0,1,0,1},
            {8,34,1,1,6,1,1,0,0},
            {9,35,8,1,2,1,1,0,0},
            {10,35,6,1,1,1,0,1,0},
            {11,35,6,1,1,1,0,0,0},
            {12,36,8,0,1,1,0,1,0},
            {13,36,4,0,1,1,1,1,0},
            };
        int ndgfRos[9] = {0,0,0,0,0,0,0,0,0};
        int edgfRos[9] = {1,0,2,5,2,2,6,7,12};
        for (int b = 0;
             b < dgfRosRows();
             ++b) {
            int vals[9];
            vals[0] = dgfRosOrd(b);
            vals[1] = dgfRosPage(b);
            vals[2] = dgfRosAlign(b);
            vals[3] = dgfRosRank(b);
            vals[4] = dgfRosPsiClass(b);
            vals[5] = dgfRosPlane(b);
            vals[6] = dgfRosDmgFixed(b);
            vals[7] = dgfRosInEach(b);
            vals[8] = dgfRosTwinPair(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CdgfRos[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++ndgfRos[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (ndgfRos[c] != edgfRos[c])
                ++bad;
        // the census walk (the four grids, the fourteen beings, the one
        // plane)
    if (dgfTableCount() != 4
            || dgfBeingCount() != 14
            || dgfCbtRows() != 14
            || dgfClsRows() != 14
            || dgfAbiRows() != 14
            || dgfRosRows() != 14
            || dgfPlaneCount() != 1
            || dgfChainCount() != 0
            || dgfRound() != 854
            || dgfPrintStart() != 32
            || dgfPrintEnd() != 36
            || dgfRegistryFloor() != 995
        )
            ++bad;
        // the print walk spans pp. 32-36 (the folio offset PRINT = PDF - 1)
    if (dgfRosPage(0) != 32
            || dgfRosPage(13) != 36
            || dgfRosOrd(0) != 0
            || dgfRosOrd(13) != 13
        )
            ++bad;
        // the roster ordinals run 0-13 in print order (Quetzalcoatl first,
        // Xochipilli last)
    if (dgfRosOrd(0) != 0
            || dgfRosOrd(1) != 1
            || dgfRosOrd(2) != 2
            || dgfRosOrd(3) != 3
            || dgfRosOrd(4) != 4
            || dgfRosOrd(5) != 5
            || dgfRosOrd(6) != 6
            || dgfRosOrd(7) != 7
            || dgfRosOrd(8) != 8
            || dgfRosOrd(9) != 9
            || dgfRosOrd(10) != 10
            || dgfRosOrd(11) != 11
            || dgfRosOrd(12) != 12
            || dgfRosOrd(13) != 13
        )
            ++bad;
        // the mythos intro doctrine: the 20-day rituals, the d4 compass, the
        // +1/-1, the colors
    if (dgfRitualPeriodDays() != 20
            || dgfCompassDieSides() != 4
            || dgfCompassHitPlus() != 1
            || dgfCompassSaveMinus() != 1
        )
            ++bad;
        // the Quetzalcoatl walk: AC -2, 400 hit points, the Infinite move,
        // 25th cleric over 13th druid, class I
    if (dgfCbtAC(0) != -2
            || dgfCbtHP(0) != 400
            || dgfCbtMove(0) != -1
            || dgfCbtMR(0) != 75
            || dgfCbtSizeIn(0) != 180
            || dgfClsCleric(0) != 25
            || dgfClsDruid(0) != 13
            || dgfClsFighterLo(0) != 20
            || dgfClsThief(0) != 20
            || dgfClsBard(0) != 20
            || dgfRosPsiClass(0) != 1
            || dgfRosAlign(0) != 3
            || dgfRosRank(0) != 1
        )
            ++bad;
        // the Quetzalcoatl ability line: S:25(+7,+14) I:25 W:25 D:25 C:25
        // CH:25
    if (dgfAbiStr(0) != 25
            || dgfAbiStrHit(0) != 7
            || dgfAbiStrDmg(0) != 14
            || dgfAbiInt(0) != 25
            || dgfAbiWis(0) != 25
            || dgfAbiDex(0) != 25
            || dgfAbiCon(0) != 25
            || dgfAbiCha(0) != 25
        )
            ++bad;
        // the Camaxtli walk: 350 hit points, the 15 over 24 move, the 500,000
        // gp sacrifice with the 25 percent favor and the 5-point light
        // regeneration
    if (dgfCbtHP(1) != 350
            || dgfCbtMove(1) != 15
            || dgfCbtMoveAlt(1) != 24
            || dgfCamaxtliSacrificeGP() != 500000
            || dgfCamaxtliFavorPct() != 25
            || dgfCamaxtliRegenPerMelee() != 5
            || dgfClsCleric(1) != 20
            || dgfClsMagUser(1) != 18
            || dgfAbiStr(1) != 23
            || dgfAbiInt(1) != 24
        )
            ++bad;
        // the Chalchiuhtlicue walk: 200 hit points, 95 percent MR, the 3-300
        // transform, the jade ritual percents and the 6 foot 4 size
    if (dgfCbtHP(2) != 200
            || dgfCbtMR(2) != 95
            || dgfCbtAtN(2) != 3
            || dgfCbtAtD(2) != 2
            || dgfCbtSizeIn(2) != 76
            || dgfChalchiuhtlicueTransformLo() != 3
            || dgfChalchiuhtlicueTransformHi() != 300
            || dgfChalchiuhtlicueClericPct() != 25
            || dgfChalchiuhtlicueWorshiperPct() != 1
            || dgfChalchiuhtlicueAttemptsPerYear() != 4
            || dgfChalchiuhtlicueRitualClearMiles() != 1
            || dgfRosAlign(2) != 2
            || dgfRosRank(2) != 0
        )
            ++bad;
        // the Camazotz walk: 362 hit points, the 1,000 bats, the 2-20 claws
        // and 3-30 bite with the paralytic save, CH -2
    if (dgfCbtHP(3) != 362
            || dgfCamazotzBatCount() != 1000
            || dgfCamazotzClawDmgLo() != 2
            || dgfCamazotzClawDmgHi() != 20
            || dgfCamazotzBiteDmgLo() != 3
            || dgfCamazotzBiteDmgHi() != 30
            || dgfAbiCha(3) != -2
            || dgfClsAssassin(3) != 15
            || dgfRosAlign(3) != 8
        )
            ++bad;
        // the Huhueteotl walk: 373 hit points, 18 over 24 move, the 50-point
        // 2-mile light beam, the 52-year time cycle
    if (dgfCbtHP(4) != 373
            || dgfCbtMove(4) != 18
            || dgfCbtMoveAlt(4) != 24
            || dgfCbtMR(4) != 80
            || dgfHuhueteotlBeamDamage() != 50
            || dgfHuhueteotlBeamRangeMiles() != 2
            || dgfHuhueteotlTimeCycleYears() != 52
            || dgfClsCleric(4) != 15
            || dgfClsDruid(4) != 10
            || dgfClsMonk(4) != 10
            || dgfAbiCha(4) != 9
        )
            ++bad;
        // the Huitzilopochtli walk: AC -3, 389 hit points, the 3-30 (+14) axe
        // with 3 strikes, the 5 percent appearance and the +3 raised saves
    if (dgfCbtAC(5) != -3
            || dgfCbtHP(5) != 389
            || dgfCbtAtN(5) != 3
            || dgfClsRanger(5) != 20
            || dgfHuitzilopochtliAxeDmgLo() != 3
            || dgfHuitzilopochtliAxeDmgHi() != 30
            || dgfHuitzilopochtliAxeStrBonus() != 14
            || dgfHuitzilopochtliAppearPct() != 5
            || dgfHuitzilopochtliRaisedSaveBonus() != 3
            || dgfAbiStr(5) != 25
            || dgfAbiStrDmg(5) != 14
        )
            ++bad;
        // the twin heroes walk: AC 2, 150 hit points each, the 200-yard
        // blowgun with 50/135 ranges, the 1-10 (+6) axes, the 1-point-per-die
        // resistance
    if (dgfCbtAC(6) != 2
            || dgfCbtHP(6) != 150
            || dgfCbtHP(7) != 150
            || dgfCbtMR(6) != 0
            || dgfCbtSizeIn(6) != 64
            || dgfTwinBlowgunRangeYards() != 200
            || dgfTwinBlowgunShortYards() != 50
            || dgfTwinBlowgunMediumYards() != 135
            || dgfTwinAxeDmgLo() != 1
            || dgfTwinAxeDmgHi() != 10
            || dgfTwinAxePlus() != 6
            || dgfTwinResistPerDie() != 1
            || dgfRosTwinPair(6) != 1
            || dgfRosTwinPair(7) != 1
            || dgfRosRank(6) != 2
            || dgfRosPsiClass(6) != 0
            || dgfRosPlane(6) != 0
        )
            ++bad;
        // the twin heroes share one grid row shape (the identical stat
        // blocks)
    if (dgfCbtAC(6) != dgfCbtAC(7)
            || dgfClsDruid(6) != dgfClsDruid(7)
            || dgfClsRanger(6) != dgfClsRanger(7)
            || dgfClsMagUser(6) != dgfClsMagUser(7)
            || dgfAbiCha(6) != dgfAbiCha(7)
        )
            ++bad;
        // the Itzamna walk: AC -3, 369 hit points, the psionic class VI, the
        // 3-24 staff, the 6-foot nimbus, the +2-to-hit light form
    if (dgfCbtAC(8) != -3
            || dgfCbtHP(8) != 369
            || dgfCbtAtN(8) != 2
            || dgfCbtMR(8) != 85
            || dgfCbtSizeIn(8) != 0
            || dgfRosPsiClass(8) != 6
            || dgfPsiClassVI() != 6
            || dgfItzamnaStaffDmgLo() != 3
            || dgfItzamnaStaffDmgHi() != 24
            || dgfItzamnaNimbusRadiusFeet() != 6
            || dgfItzamnaWeaponPlusToHit() != 2
            || dgfClsCleric(8) != 22
            || dgfAbiWis(8) != 25
            || dgfAbiDex(8) != 17
        )
            ++bad;
        // the Tezcatlipoca adjudications: the psionic class II (the 28px
        // two-glyph word), 400 hit points, the 3-30 claws
    if (dgfRosPsiClass(9) != 2
            || dgfPsiClassII() != 2
            || dgfCbtHP(9) != 400
            || dgfCbtMR(9) != 85
            || dgfTezcatlipocaClawDmgLo() != 3
            || dgfTezcatlipocaClawDmgHi() != 30
            || dgfClsFighterLo(9) != 20
            || dgfClsBard(9) != 6
            || dgfClsAssassin(9) != 15
            || dgfAbiWis(9) != 24
            || dgfRosAlign(9) != 8
        )
            ++bad;
        // the Mictlantecuhtli walk: 339 hit points, 95 percent MR, the undead
        // summons, the 50-sacrifice gate, CH -4
    if (dgfCbtHP(10) != 339
            || dgfCbtMR(10) != 95
            || dgfMictlantecuhtliSkeletonLo() != 20
            || dgfMictlantecuhtliSkeletonHi() != 200
            || dgfMictlantecuhtliGhoulLo() != 10
            || dgfMictlantecuhtliGhoulHi() != 100
            || dgfMictlantecuhtliWightLo() != 6
            || dgfMictlantecuhtliWightHi() != 36
            || dgfMictlantecuhtliSpectreLo() != 2
            || dgfMictlantecuhtliSpectreHi() != 5
            || dgfMictlantecuhtliSacrificeGate() != 50
            || dgfAbiCha(10) != -4
            || dgfRosAlign(10) != 6
        )
            ++bad;
        // the Tlaloc walk: 377 hit points, the four pitchers, the 40/30/20
        // lightning
    if (dgfCbtHP(11) != 377
            || dgfCbtMove(11) != 12
            || dgfCbtMoveAlt(11) != 24
            || dgfCbtAtN(11) != 3
            || dgfCbtAtD(11) != 2
            || dgfTlalocPitcherCount() != 4
            || dgfTlalocLightningArmor() != 40
            || dgfTlalocLightningClothed() != 30
            || dgfTlalocLightningNaked() != 20
            || dgfClsMagUser(11) != 20
            || dgfAbiStrHit(11) != 3
            || dgfRosAlign(11) != 6
        )
            ++bad;
        // the Tlazolteotl walk: AC -3, the 2nd-print 211 hit points (the IA
        // 1st print reads 217 - the Gawaine precedent, flagged), the 24/-5
        // charisma, the 25th illusionist
    if (dgfCbtAC(12) != -3
            || dgfCbtHP(12) != 211
            || dgfCbtMR(12) != 25
            || dgfTlazolteotlChaAlt() != -5
            || dgfClsIllus(12) != 25
            || dgfClsMagUser(12) != 15
            || dgfClsAssassin(12) != 15
            || dgfClsBard(12) != 15
            || dgfAbiStr(12) != 10
            || dgfAbiCha(12) != 24
        )
            ++bad;
        // the Xochipilli walk: AC -5, 381 hit points, the 16-foot size, the
        // never-missing 3-30 axe
    if (dgfCbtAC(13) != -5
            || dgfCbtHP(13) != 381
            || dgfCbtMR(13) != 25
            || dgfCbtSizeIn(13) != 192
            || dgfXochipilliAxeDmgLo() != 3
            || dgfXochipilliAxeDmgHi() != 30
            || dgfClsThief(13) != 12
            || dgfClsMonk(13) != 12
            || dgfAbiStrDmg(13) != 12
            || dgfRosAlign(13) != 4
        )
            ++bad;
        // the negative charismas: Camazotz -2 and Mictlantecuhtli -4 (the
        // printed cells)
    if (dgfAbiCha(3) != -2
            || dgfAbiCha(10) != -4
        )
            ++bad;
        // the psionic class census: eleven class I, Tezcatlipoca II, Itzamna
        // VI, the twins Nil
    if (dgfPsiClassI() != 1
            || dgfPsiClassII() != 2
            || dgfPsiClassVI() != 6
            || dgfRosPsiClass(0) != 1
            || dgfRosPsiClass(4) != 1
            || dgfRosPsiClass(9) != 2
            || dgfRosPsiClass(8) != 6
            || dgfRosPsiClass(6) != 0
        )
            ++bad;
        // the single parallel plane: thirteen beings on it, the twin heroes
        // without a plane line
    if (dgfPlaneCount() != 1
            || dgfRosPlane(0) != 1
            || dgfRosPlane(1) != 1
            || dgfRosPlane(2) != 1
            || dgfRosPlane(3) != 1
            || dgfRosPlane(4) != 1
            || dgfRosPlane(5) != 1
            || dgfRosPlane(8) != 1
            || dgfRosPlane(9) != 1
            || dgfRosPlane(10) != 1
            || dgfRosPlane(11) != 1
            || dgfRosPlane(12) != 1
            || dgfRosPlane(13) != 1
            || dgfRosPlane(6) != 0
            || dgfRosPlane(7) != 0
        )
            ++bad;
        // the in-each flags: Quetzalcoatl, Camazotz, Huhueteotl,
        // Huitzilopochtli, Mictlantecuhtli, Tlazolteotl, Xochipilli
    if (dgfRosInEach(0) != 1
            || dgfRosInEach(3) != 1
            || dgfRosInEach(4) != 1
            || dgfRosInEach(5) != 1
            || dgfRosInEach(10) != 1
            || dgfRosInEach(12) != 1
            || dgfRosInEach(13) != 1
            || dgfRosInEach(1) != 0
        )
            ++bad;
        // the fixed-damage flags against the printed DAMAGE/ATTACK cells
    if (dgfRosDmgFixed(2) != 1
            || dgfRosDmgFixed(3) != 1
            || dgfRosDmgFixed(5) != 1
            || dgfRosDmgFixed(6) != 1
            || dgfRosDmgFixed(8) != 1
            || dgfRosDmgFixed(9) != 1
            || dgfRosDmgFixed(13) != 1
            || dgfRosDmgFixed(0) != 0
            || dgfRosDmgFixed(10) != 0
            || dgfRosDmgFixed(11) != 0
            || dgfRosDmgFixed(12) != 0
        )
            ++bad;
        // the alignment census: the eight-coded chaotic evils, the lawful
        // evils, the law/neutral goods
    if (dgfRosAlign(3) != 8
            || dgfRosAlign(4) != 8
            || dgfRosAlign(9) != 8
            || dgfRosAlign(12) != 8
            || dgfRosAlign(6) != 0
            || dgfRosAlign(7) != 0
            || dgfRosAlign(8) != 1
            || dgfRosAlign(2) != 2
            || dgfRosAlign(10) != 6
            || dgfRosAlign(11) != 6
        )
            ++bad;
        // the rank census: seven greater gods, five lesser, the two heroes
    if (dgfRosRank(0) != 1
            || dgfRosRank(1) != 1
            || dgfRosRank(4) != 1
            || dgfRosRank(8) != 1
            || dgfRosRank(9) != 1
            || dgfRosRank(10) != 1
            || dgfRosRank(11) != 1
            || dgfRosRank(2) != 0
            || dgfRosRank(13) != 0
            || dgfRosRank(5) != 0
        )
            ++bad;
        // the ranger fighter slots: Huitzilopochtli 20, Mictlantecuhtli 15,
        // the twins 10
    if (dgfClsRanger(5) != 20
            || dgfClsRanger(10) != 15
            || dgfClsRanger(6) != 10
            || dgfClsRanger(7) != 10
            || dgfClsFighterLo(5) != 0
            || dgfClsFighterLo(10) != 0
        )
            ++bad;
        // the paladin fighter slots: Quetzalcoatl 20, Camaxtli 12,
        // Chalchiuhtlicue 12, Itzamna 13, Xochipilli 12
    if (dgfClsFighterLo(0) != 20
            || dgfClsFighterLo(1) != 12
            || dgfClsFighterLo(2) != 12
            || dgfClsFighterLo(8) != 13
            || dgfClsFighterLo(13) != 12
            || dgfClsFighterHi(0) != 20
            || dgfClsFighterHi(13) != 12
        )
            ++bad;
        // the hit point walk across the fourteen stat blocks
    if (dgfCbtHP(2) != 200
            || dgfCbtHP(3) != 362
            || dgfCbtHP(4) != 373
            || dgfCbtHP(8) != 369
            || dgfCbtHP(9) != 400
            || dgfCbtHP(10) != 339
            || dgfCbtHP(11) != 377
            || dgfCbtHP(13) != 381
        )
            ++bad;
        // the magic resistance walk: the 95s, the 85s, the 25s
    if (dgfCbtMR(2) != 95
            || dgfCbtMR(10) != 95
            || dgfCbtMR(8) != 85
            || dgfCbtMR(9) != 85
            || dgfCbtMR(12) != 25
            || dgfCbtMR(13) != 25
            || dgfCbtMR(4) != 80
            || dgfCbtMR(0) != 75
        )
            ++bad;
        printf("R854 Central American mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
