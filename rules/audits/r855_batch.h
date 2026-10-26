    // ---- R855 Chinese mythos audit ----
    // THE CHINESE MYTHOS - the D&DG walk round seven, print pp. 37-42:
    // eighteen beings (Shang-Ti, Chao Kung Ming, Chih Sung-Tzu, Chih-Chiang
    // Fyu-Ya, Chung Kuel, Fei Lien and Feng Po the Counts of the Wind,
    // Huan-Ti, Kuan Yin, Lei Kung, Lu Yueh, Ma Yuan, No Cha, Shan Hai Ching,
    // the Spirits of the Air, Tou Mu, Wen Chung, Yen-Wang-Yeh), the celestial
    // bureaucracy doctrine, and the seven devices of the mythos. Zero
    // registry defs touched; the floor holds at 995. The flagged eyeball
    // cells: the Wen Chung hit points (the 2nd-print 213 pinned against the
    // IA 1st-print 273, the Gawaine 112 precedent), the Chih Sung-Tzu size
    // (garbled in both voices, the sentinel pinned), and the Wen Chung 12/21
    // move (both voices agreeing on an unusual printed slash).
    {
        using namespace rules;
        int bad = 0;
    if (dggRound() != 855
            || dggPrintStart() != 37
            || dggPrintEnd() != 42
            || dggBeingCount() != 18
            || dggTableCount() != 4
            || dggChainCount() != 0
            || dggRegistryFloor() != 995
            || dggCbtRows() != 18
            || dggClsRows() != 18
            || dggAbiRows() != 18
            || dggRosRows() != 18
            || dggPlaneCount() != 9
            || dggPsiClassI() != 1
            || dggPsiClassII() != 2
            || dggPsiClassV() != 5
            || dggPsiClassVI() != 6
            || dggArtifactCount() != 7
            || dggIronWandRadiusInches() != 30
            || dggIronWandLengthInches() != 100
            || dggWindFireWheelCount() != 25
            || dggWindFireChargePerHP() != 5
            || dggCanonLearnHours() != 72
            || dggCanonRecreateHours() != 72
            || dggLightningSwordDamage() != 30
            || dggFireGemDmgLo() != 6
            || dggFireGemDmgHi() != 60
            || dggFireGemRangeYards() != 50
            || dggFireGemChargesLo() != 2
            || dggFireGemChargesHi() != 12
            || dggPearlSizeFeet() != 3
            || dggPearlRadiusMiles() != 1
            || dggShangTiShaftDmgLo() != 3
            || dggShangTiShaftDmgHi() != 36
            || dggChaoSpearDmgLo() != 10
            || dggChaoSpearDmgHi() != 60
            || dggChaoTigerAC() != 3
            || dggChaoTigerHD() != 11
            || dggChaoTigerHP() != 50
            || dggChaoTigerAtN() != 3
            || dggChaoScaleMailPlus() != 3
            || dggChihSungHelmSpeedInches() != 48
            || dggChihSungCloudSpeedInches() != 24
            || dggChihSungCloudBeings() != 10
            || dggChihSungMaceDmgLo() != 3
            || dggChihSungMaceDmgHi() != 30
            || dggChihSungScaleMailPlus() != 3
            || dggChihChiangArrowDmgLo() != 2
            || dggChihChiangArrowDmgHi() != 20
            || dggChihChiangSwordDmgLo() != 2
            || dggChihChiangSwordDmgHi() != 24
            || dggChihChiangPlatePlus() != 4
            || dggChihChiangWingSpanFeet() != 40
            || dggChungKuelSwordPlus() != 3
            || dggWindCountsPlatePlus() != 2
            || dggWindCountsSwordDmgLo() != 2
            || dggWindCountsSwordDmgHi() != 20
            || dggWindCountsElectricDmg() != 6
            || dggWindCountsWhirlwindRounds() != 2
            || dggWindCountsWhirlwindPerDay() != 1
            || dggWindCountsWindConjureRounds() != 10
            || dggHuanTiHalberdPlus() != 2
            || dggHuanTiHalberdDmgLo() != 3
            || dggHuanTiHalberdDmgHi() != 30
            || dggHuanTiSwordPlus() != 3
            || dggHuanTiPlatePlus() != 3
            || dggHuanTiChariotPegasi() != 4
            || dggHuanTiDedicationCount() != 10
            || dggHuanTiDedicationPct() != 1
            || dggKuanYinMuLevel() != 20
            || dggKuanYinGoodActWorshipers() != 50
            || dggKuanYinWishPct() != 5
            || dggLeiKungFistDmgLo() != 7
            || dggLeiKungFistDmgHi() != 42
            || dggLeiKungHammerPlus() != 4
            || dggLeiKungHammerDmg() != 25
            || dggLeiKungMailPlus() != 3
            || dggLeiKungMailDamage() != 10
            || dggLeiKungWingSpanFeet() != 40
            || dggLuYuehRegenPerRound() != 25
            || dggLuYuehRotRangeFeet() != 10
            || dggLuYuehRedFeverPerMelee() != 3
            || dggLuYuehCloudSizeInches() != 3
            || dggLuYuehEvilActPeople() != 500
            || dggLuYuehWatchingPct() != 1
            || dggLuYuehGiftPct() != 5
            || dggMaYuanDmgLo() != 3
            || dggMaYuanDmgHi() != 30
            || dggMaYuanDmg2Lo() != 5
            || dggMaYuanDmg2Hi() != 40
            || dggMaYuanWeaponPlusToHit() != 3
            || dggMaYuanMinDeitiesKilled() != 10
            || dggMaYuanAttackHD() != 16
            || dggMaYuanXpValue() != 32300
            || dggNoChaSpearPlus() != 3
            || dggNoChaSpearDmg() != 30
            || dggNoChaGoldDmgLo() != 5
            || dggNoChaGoldDmgHi() != 50
            || dggNoChaGoldRangeYards() != 100
            || dggNoChaBraceletRounds() != 5
            || dggNoChaFireballDmg() != 30
            || dggShanHaiHurricaneDmgLo() != 5
            || dggShanHaiHurricaneDmgHi() != 50
            || dggSpiritsSummonPerDay() != 100
            || dggSpiritsAttackHD() != 11
            || dggSpiritsHP() != 50
            || dggSpiritsAppearingLo() != 1
            || dggSpiritsAppearingHi() != 100
            || dggTouMuArmsCount() != 16
            || dggTouMuBowRangeYards() != 100
            || dggTouMuArrowDmgLo() != 1
            || dggTouMuArrowDmgHi() != 10
            || dggTouMuSpearPlus() != 3
            || dggTouMuSpearDmgLo() != 3
            || dggTouMuSpearDmgHi() != 30
            || dggTouMuFlagDeathSpells() != 3
            || dggTouMuDragonHeadHP() != 80
            || dggTouMuChariotCount() != 5
            || dggTouMuChariotSpeedInches() != 24
            || dggTouMuChariotTongueFeet() != 32
            || dggTouMuOverrunDmgLo() != 2
            || dggTouMuOverrunDmgHi() != 12
            || dggTouMuAttacksPerMelee() != 8
            || dggWenChungEyeBoltDmg() != 20
            || dggWenChungEyeBoltRangeYards() != 180
            || dggWenChungEyeBoltPerDay() != 10
            || dggWenChungSwordPlus() != 3
            || dggWenChungSwordDmgLo() != 3
            || dggWenChungSwordDmgHi() != 30
            || dggYenWangSwordPlus() != 3
            || dggYenWangSwordDmgLo() != 2
            || dggYenWangSwordDmgHi() != 20
            || dggYenWangDeathRaysPerMelee() != 2
            || !dggVastMythologyCaveat()
            || !dggGreatBureaucracy()
            || !dggSpecialTaskDeities()
            || !dggSupervisionChains()
            || !dggEmperorAccountability()
            || !dggAnnualReports()
            || !dggClericsSupportGovernment()
            || !dggEmperorHeadOfChurch()
            || !dggAtonementBySacrifice()
            || !dggAtonementMayBeDeath()
            || !dggTravelPreaching()
            || !dggIronWandRevealsInvisible()
            || !dggIronWandDustDisappearance()
            || !dggIronWandStaffOfStriking()
            || !dggIronWandGrowsToClimb()
            || !dggJadeScepterBlocksMaterial()
            || !dggJadeScepterConcentration()
            || !dggWindFireWheelStaffOfMagi()
            || !dggWindFireWheelFans()
            || !dggCanonCreatesNonmagical()
            || !dggCanonImmortalsOnly()
            || !dggLightningSwordDancingParity()
            || !dggLightningSwordUnlimited()
            || !dggLightningSwordAirDemigods()
            || !dggLightningSwordMortalNormal()
            || !dggFireGemOncePerTurn()
            || !dggPearlUncontrolled()
            || !dggShangTiSupremeGod()
            || !dggShangTiTravelsAmongMortals()
            || !dggShangTiFloatsEthereal()
            || !dggShangTiWeaponsReturn()
            || !dggShangTiShaftRangeSight()
            || !dggShangTiWeatherControl()
            || !dggShangTiBureaucracyHead()
            || !dggShangTiWordIsLaw()
            || !dggChaoWarDemigod()
            || !dggChaoRidesFlyingTiger()
            || !dggChaoPlaneTravel()
            || !dggChihSungRainLord()
            || !dggChihSungWeatherOnCommand()
            || !dggChihSungRustsMetal()
            || !dggChihChiangArcherGod()
            || !dggChihChiangHitsAnyTargetInSight()
            || !dggChihChiangReversesWeapons()
            || !dggChihChiangBowBackfires()
            || !dggChihChiangShapeChange()
            || !dggChihChiangAvengeGods()
            || !dggChungKuelTruthGod()
            || !dggChungKuelWellOfKnowledge()
            || !dggChungKuelSecuresWinning()
            || !dggChungKuelRodOfCancellation()
            || !dggChungKuelRiddleTravels()
            || !dggChungKuelRiddleRewards()
            || !dggWindCountsOfTheWind()
            || !dggWindCountsRideTheWind()
            || !dggWindCountsLeatherSacks()
            || !dggWindCountsBattleGoBetweens()
            || !dggWindCountsDemonicLook()
            || !dggHuanTiWarGod()
            || !dggHuanTiDualWield()
            || !dggHuanTiChariotSpellImmune()
            || !dggHuanTiWatchesBattles()
            || !dggHuanTiHeadsBurned()
            || !dggHuanTiRedArmorAlways()
            || !dggKuanYinMercyGoddess()
            || !dggKuanYinNegateViolence()
            || !dggKuanYinNeverHarmfulSpells()
            || !dggKuanYinNoViolenceAgainstHer()
            || !dggKuanYinCommonFolk()
            || !dggKuanYinPeacemakers()
            || !dggLeiKungThunderDuke()
            || !dggLeiKungGreenDrums()
            || !dggLeiKungFoulWeatherOnRequest()
            || !dggLeiKungDelightsInWindstorms()
            || !dggLuYuehEpidemicGod()
            || !dggLuYuehRottingSicknessSpell()
            || !dggLuYuehNoArmor()
            || !dggMaYuanGodKiller()
            || !dggMaYuanStormGiantStrength()
            || !dggMaYuanTriangularStone()
            || !dggMaYuanDoublePowerTactic()
            || !dggMaYuanPreventsComplacency()
            || !dggNoChaThievesDemigod()
            || !dggNoChaGrowShrink()
            || !dggNoChaPantherWhirlwind()
            || !dggNoChaStranglerBracelet()
            || !dggNoChaThievesPatron()
            || !dggShanHaiWindSeaGod()
            || !dggShanHaiHurricaneWind()
            || !dggShanHaiSeaSummoning()
            || !dggShanHaiSpellTurning()
            || !dggShanHaiSeaSacrifice()
            || !dggSpiritsOfTheAir()
            || !dggSpiritsLook()
            || !dggTouMuNorthStarGoddess()
            || !dggTouMuDancingSword()
            || !dggTouMuMoonPiece()
            || !dggTouMuLotusHeals()
            || !dggTouMuFreeClaws()
            || !dggTouMuAdamantChariots()
            || !dggWenChungThunderMinister()
            || !dggWenChungSummonsWeather()
            || !dggWenChungImmunities()
            || !dggYenWangDeadJudge()
            || !dggYenWangDragonShape()
            || !dggYenWangTouchParalysis()
            || !dggYenWangCollectsSouls()
            || !dggYenWangTracksRogues()
            || !dggYenWangNoPowerOverRisen()
        )
            ++bad;
        // the combat stat blocks of the eighteen beings (print pp. 37-42) -
        // the armor classes, hit points, moves, attacks, magic resistance and
        // sizes
        int CdggCbt[18][9] = {
            {-2,0,400,24,24,2,0,50,64},
            {-4,0,199,15,0,2,0,5,74},
            {-2,0,388,12,24,2,0,0,0},
            {7,0,287,12,30,2,0,20,96},
            {-2,0,319,12,12,2,0,80,72},
            {-4,0,150,24,24,3,2,0,72},
            {-4,0,150,24,24,3,2,0,72},
            {-7,0,380,18,0,2,4,50,84},
            {-3,0,376,12,12,0,0,100,60},
            {-4,0,354,12,24,2,0,5,72},
            {-2,0,367,12,12,6,0,0,120},
            {-4,0,300,24,24,5,0,65,840},
            {-2,0,239,15,48,8,0,10,720},
            {-2,0,366,6,48,2,0,35,720},
            {4,0,50,12,24,2,0,0,96},
            {-3,0,300,24,24,8,0,25,240},
            {-2,0,213,12,21,3,2,15,96},
            {-5,0,349,12,12,2,0,75,72},
            };
        int ndggCbt[9] = {0,0,0,0,0,0,0,0,0};
        int edggCbt[9] = {0,18,0,0,2,1,14,5,1};
        for (int b = 0;
             b < dggCbtRows();
             ++b) {
            int vals[9];
            vals[0] = dggCbtAC(b);
            vals[1] = dggCbtACAlt(b);
            vals[2] = dggCbtHP(b);
            vals[3] = dggCbtMove(b);
            vals[4] = dggCbtMoveAlt(b);
            vals[5] = dggCbtAtN(b);
            vals[6] = dggCbtAtD(b);
            vals[7] = dggCbtMR(b);
            vals[8] = dggCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CdggCbt[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++ndggCbt[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (ndggCbt[c] != edggCbt[c])
                ++bad;
        // the five-slot class grid of the eighteen beings (the printed See
        // below, the ranger slots, the demigod monk abilities)
        int CdggCls[18][11] = {
            {13,0,15,15,0,20,20,0,0,0,15},
            {0,0,0,0,17,0,0,0,10,7,0},
            {20,0,13,13,0,20,0,0,0,0,0},
            {0,0,18,18,0,0,0,0,0,10,10},
            {20,14,0,0,20,15,15,0,15,10,10},
            {0,0,0,0,10,0,0,10,0,5,0},
            {0,0,0,0,10,0,0,10,0,5,0},
            {0,0,0,0,20,0,0,0,15,12,0},
            {25,14,0,0,0,99,0,0,0,0,15},
            {0,10,14,14,0,14,14,0,0,0,0},
            {20,0,15,15,0,19,19,19,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,10,12,12,0,0,17,20,0,0,0},
            {10,0,15,15,0,10,10,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {20,0,0,0,15,6,6,0,0,0,0},
            {0,0,0,0,10,15,15,0,0,0,0},
            {20,0,18,18,0,15,0,0,15,12,0},
            };
        int ndggCls[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int edggCls[11] = {10,14,10,10,11,8,10,14,14,11,14};
        for (int b = 0;
             b < dggClsRows();
             ++b) {
            int vals[11];
            vals[0] = dggClsCleric(b);
            vals[1] = dggClsDruid(b);
            vals[2] = dggClsFighterLo(b);
            vals[3] = dggClsFighterHi(b);
            vals[4] = dggClsRanger(b);
            vals[5] = dggClsMagUser(b);
            vals[6] = dggClsIllus(b);
            vals[7] = dggClsThief(b);
            vals[8] = dggClsAssassin(b);
            vals[9] = dggClsMonk(b);
            vals[10] = dggClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CdggCls[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++ndggCls[c];
            }
        }
        for (int c = 0; c < 11; ++c)
            if (ndggCls[c] != edggCls[c])
                ++bad;
        // the six ability scores with the strength brackets of the eighteen
        // beings (the monster rows read the all-sentinel line)
        int CdggAbi[18][9] = {
            {20,3,8,25,25,25,25,20,0},
            {25,7,14,18,14,20,20,20,0},
            {23,5,11,20,24,19,23,23,0},
            {23,5,11,22,22,25,22,-2,0},
            {20,3,8,25,25,20,20,19,0},
            {14,0,0,14,14,19,20,9,0},
            {14,0,0,14,14,19,20,9,0},
            {25,7,14,23,18,25,25,10,0},
            {8,0,0,25,25,12,22,25,0},
            {23,5,11,23,17,20,23,7,0},
            {20,3,8,17,5,17,25,-3,0},
            {0,0,0,0,0,0,0,0,0},
            {25,7,14,25,7,25,20,10,0},
            {24,6,12,21,23,17,24,19,0},
            {0,0,0,0,0,0,0,0,0},
            {23,5,11,25,3,25,19,5,0},
            {24,6,12,20,22,21,19,15,0},
            {14,0,0,24,20,25,23,19,0},
            };
        int ndggAbi[9] = {0,0,0,0,0,0,0,0,0};
        int edggAbi[9] = {2,6,6,2,2,2,2,2,18};
        for (int b = 0;
             b < dggAbiRows();
             ++b) {
            int vals[9];
            vals[0] = dggAbiStr(b);
            vals[1] = dggAbiStrHit(b);
            vals[2] = dggAbiStrDmg(b);
            vals[3] = dggAbiInt(b);
            vals[4] = dggAbiWis(b);
            vals[5] = dggAbiDex(b);
            vals[6] = dggAbiCon(b);
            vals[7] = dggAbiCha(b);
            vals[8] = dggAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CdggAbi[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++ndggAbi[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (ndggAbi[c] != edggAbi[c])
                ++bad;
        // the roster walk of the eighteen beings - ordinals, pages,
        // alignments, ranks, psionic classes, the nine planes, the
        // fixed-damage, in-each and twin-pair flags
        int CdggRos[18][9] = {
            {0,37,3,1,1,1,1,1,0},
            {1,38,1,2,2,2,1,0,0},
            {2,38,4,1,6,2,1,0,0},
            {3,38,6,2,6,3,1,1,0},
            {4,38,0,1,2,4,0,1,0},
            {5,39,1,2,5,2,1,0,1},
            {6,39,1,2,5,2,1,0,1},
            {7,39,2,0,6,5,1,0,0},
            {8,39,0,1,6,4,0,0,0},
            {9,40,6,1,6,6,1,1,0},
            {10,40,8,0,6,7,1,1,0},
            {11,41,8,3,0,0,1,0,0},
            {12,41,7,2,6,8,0,0,0},
            {13,42,3,1,6,1,1,1,0},
            {14,42,4,3,0,0,1,0,0},
            {15,42,8,0,2,7,0,1,0},
            {16,42,5,2,6,2,1,1,0},
            {17,42,4,1,6,9,1,0,0},
            };
        int ndggRos[9] = {0,0,0,0,0,0,0,0,0};
        int edggRos[9] = {1,0,2,3,2,2,4,10,16};
        for (int b = 0;
             b < dggRosRows();
             ++b) {
            int vals[9];
            vals[0] = dggRosOrd(b);
            vals[1] = dggRosPage(b);
            vals[2] = dggRosAlign(b);
            vals[3] = dggRosRank(b);
            vals[4] = dggRosPsiClass(b);
            vals[5] = dggRosPlane(b);
            vals[6] = dggRosDmgFixed(b);
            vals[7] = dggRosInEach(b);
            vals[8] = dggRosTwinPair(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CdggRos[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++ndggRos[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (ndggRos[c] != edggRos[c])
                ++bad;
        // the census walk (the four grids, the eighteen beings, the nine
        // planes)
    if (dggTableCount() != 4
            || dggBeingCount() != 18
            || dggCbtRows() != 18
            || dggClsRows() != 18
            || dggAbiRows() != 18
            || dggRosRows() != 18
            || dggPlaneCount() != 9
            || dggArtifactCount() != 7
            || dggChainCount() != 0
            || dggRound() != 855
            || dggPrintStart() != 37
            || dggPrintEnd() != 42
            || dggRegistryFloor() != 995
        )
            ++bad;
        // the print walk spans pp. 37-42 and the roster ordinals run 0-17 in
        // print order
    if (dggRosPage(0) != 37
            || dggRosPage(17) != 42
            || dggRosOrd(0) != 0
            || dggRosOrd(1) != 1
            || dggRosOrd(2) != 2
            || dggRosOrd(3) != 3
            || dggRosOrd(4) != 4
            || dggRosOrd(5) != 5
            || dggRosOrd(6) != 6
            || dggRosOrd(7) != 7
            || dggRosOrd(8) != 8
            || dggRosOrd(9) != 9
            || dggRosOrd(10) != 10
            || dggRosOrd(11) != 11
            || dggRosOrd(12) != 12
            || dggRosOrd(13) != 13
            || dggRosOrd(14) != 14
            || dggRosOrd(15) != 15
            || dggRosOrd(16) != 16
            || dggRosOrd(17) != 17
        )
            ++bad;
        // the psionic class census: Shang-Ti I, the II readers, the V Counts,
        // the ten VIs, the monsters Nil
    if (dggPsiClassI() != 1
            || dggPsiClassII() != 2
            || dggPsiClassV() != 5
            || dggPsiClassVI() != 6
            || dggRosPsiClass(0) != 1
            || dggRosPsiClass(1) != 2
            || dggRosPsiClass(4) != 2
            || dggRosPsiClass(15) != 2
            || dggRosPsiClass(5) != 5
            || dggRosPsiClass(11) != 0
            || dggRosPsiClass(14) != 0
            || dggRosPsiClass(8) != 6
        )
            ++bad;
        // the plane census: the nine planes across the sixteen deity rows
    if (dggRosPlane(0) != 1
            || dggRosPlane(1) != 2
            || dggRosPlane(3) != 3
            || dggRosPlane(8) != 4
            || dggRosPlane(7) != 5
            || dggRosPsiClass(9) != 6
            || dggRosPlane(9) != 6
            || dggRosPlane(10) != 7
            || dggRosPlane(12) != 8
            || dggRosPlane(17) != 9
            || dggRosPlane(11) != 0
            || dggRosPlane(14) != 0
        )
            ++bad;
        // the bureaucracy intro: the seven-artifact doctrine rides the mythos
    if (dggArtifactCount() != 7
            || dggIronWandRadiusInches() != 30
            || dggIronWandLengthInches() != 100
            || dggWindFireWheelCount() != 25
            || dggWindFireChargePerHP() != 5
            || dggCanonLearnHours() != 72
            || dggCanonRecreateHours() != 72
            || dggLightningSwordDamage() != 30
        )
            ++bad;
        // the fire gems and the pearl
    if (dggFireGemDmgLo() != 6
            || dggFireGemDmgHi() != 60
            || dggFireGemRangeYards() != 50
            || dggFireGemChargesLo() != 2
            || dggFireGemChargesHi() != 12
            || dggPearlSizeFeet() != 3
            || dggPearlRadiusMiles() != 1
        )
            ++bad;
        // the Shang-Ti walk: AC -2, 400 hit points, the 24 over 24 move, the
        // 3-36 light shaft, the 5 foot 4 size decode
    if (dggCbtAC(0) != -2
            || dggCbtHP(0) != 400
            || dggCbtMove(0) != 24
            || dggCbtMoveAlt(0) != 24
            || dggCbtMR(0) != 50
            || dggCbtSizeIn(0) != 64
            || dggShangTiShaftDmgLo() != 3
            || dggShangTiShaftDmgHi() != 36
            || dggClsCleric(0) != 13
            || dggClsMagUser(0) != 20
            || dggClsBard(0) != 15
            || dggAbiStr(0) != 20
            || dggAbiStrHit(0) != 3
            || dggAbiStrDmg(0) != 8
        )
            ++bad;
        // the Chao Kung Ming adjudications: the psionic class II (the 27px
        // two-glyph word vs the Termux /I), the 6 foot 2 size decode, the
        // tiger stats
    if (dggRosPsiClass(1) != 2
            || dggCbtAC(1) != -4
            || dggCbtHP(1) != 199
            || dggCbtSizeIn(1) != 74
            || dggChaoSpearDmgLo() != 10
            || dggChaoSpearDmgHi() != 60
            || dggChaoTigerAC() != 3
            || dggChaoTigerHD() != 11
            || dggChaoTigerHP() != 50
            || dggChaoTigerAtN() != 3
            || dggChaoScaleMailPlus() != 3
            || dggClsRanger(1) != 17
            || dggClsAssassin(1) != 10
            || dggClsMonk(1) != 7
        )
            ++bad;
        // the Chih Sung-Tzu walk: 388 hit points, the 48-inch helm haste, the
        // storm cloud at 24 with 10 beings, the rusting mail
    if (dggCbtHP(2) != 388
            || dggCbtMR(2) != 0
            || dggCbtSizeIn(2) != 0
            || dggChihSungHelmSpeedInches() != 48
            || dggChihSungCloudSpeedInches() != 24
            || dggChihSungCloudBeings() != 10
            || dggChihSungMaceDmgLo() != 3
            || dggChihSungMaceDmgHi() != 30
            || dggChihSungScaleMailPlus() != 3
            || dggClsCleric(2) != 20
            || dggClsFighterLo(2) != 13
        )
            ++bad;
        // the Chih-Chiang Fyu-Ya walk: AC 7, the 12 over 30 move, the 2-20
        // arrows and 2-24 sword, the +4 plate, CH -2, class VI
    if (dggCbtAC(3) != 7
            || dggCbtMove(3) != 12
            || dggCbtMoveAlt(3) != 30
            || dggCbtMR(3) != 20
            || dggChihChiangArrowDmgLo() != 2
            || dggChihChiangArrowDmgHi() != 20
            || dggChihChiangSwordDmgLo() != 2
            || dggChihChiangSwordDmgHi() != 24
            || dggChihChiangPlatePlus() != 4
            || dggChihChiangWingSpanFeet() != 40
            || dggAbiCha(3) != -2
            || dggRosPsiClass(3) != 6
            || dggRosPlane(3) != 3
        )
            ++bad;
        // the Chung Kuel walk: the psionic class II, the well of knowledge,
        // the riddle rewards, the 319 hit points
    if (dggRosPsiClass(4) != 2
            || dggCbtHP(4) != 319
            || dggCbtMR(4) != 80
            || dggChungKuelSwordPlus() != 3
            || dggClsCleric(4) != 20
            || dggClsDruid(4) != 14
            || dggClsRanger(4) != 20
            || dggClsIllus(4) != 15
            || dggAbiInt(4) != 25
            || dggRosPlane(4) != 4
        )
            ++bad;
        // the Counts of the Wind walk: 150 hit points each, the +2 plate, the
        // 6-point electrical blows, class V, the twin-pair flags
    if (dggCbtHP(5) != 150
            || dggCbtHP(6) != 150
            || dggCbtAC(5) != -4
            || dggCbtAtN(5) != 3
            || dggCbtAtD(5) != 2
            || dggRosPsiClass(5) != 5
            || dggWindCountsPlatePlus() != 2
            || dggWindCountsSwordDmgLo() != 2
            || dggWindCountsSwordDmgHi() != 20
            || dggWindCountsElectricDmg() != 6
            || dggWindCountsWhirlwindRounds() != 2
            || dggWindCountsWhirlwindPerDay() != 1
            || dggWindCountsWindConjureRounds() != 10
            || dggRosTwinPair(5) != 1
            || dggRosTwinPair(6) != 1
        )
            ++bad;
        // the Huan-Ti walk: AC -7, the 2-or-4 attacks, the chariot spell
        // immunity, the dedication doctrine
    if (dggCbtAC(7) != -7
            || dggCbtHP(7) != 380
            || dggCbtAtN(7) != 2
            || dggCbtAtD(7) != 4
            || dggHuanTiHalberdPlus() != 2
            || dggHuanTiSwordPlus() != 3
            || dggHuanTiPlatePlus() != 3
            || dggHuanTiChariotPegasi() != 4
            || dggHuanTiDedicationCount() != 10
            || dggHuanTiDedicationPct() != 1
            || dggClsRanger(7) != 20
            || dggAbiCha(7) != 10
        )
            ++bad;
        // the Kuan Yin walk: 100 percent MR, the See below magic-user cell,
        // the violence negation and the wish doctrine
    if (dggCbtMR(8) != 100
            || dggCbtHP(8) != 376
            || dggCbtAtN(8) != 0
            || dggClsMagUser(8) != 99
            || dggKuanYinMuLevel() != 20
            || dggKuanYinGoodActWorshipers() != 50
            || dggKuanYinWishPct() != 5
            || dggClsCleric(8) != 25
            || dggClsDruid(8) != 14
            || dggAbiStr(8) != 8
            || dggAbiDex(8) != 12
        )
            ++bad;
        // the Lei Kung walk: the 7-42 fists, the +4 hammer for 25, the +3
        // mail for 10, class VI
    if (dggCbtHP(9) != 354
            || dggCbtMR(9) != 5
            || dggLeiKungFistDmgLo() != 7
            || dggLeiKungFistDmgHi() != 42
            || dggLeiKungHammerPlus() != 4
            || dggLeiKungHammerDmg() != 25
            || dggLeiKungMailPlus() != 3
            || dggLeiKungMailDamage() != 10
            || dggLeiKungWingSpanFeet() != 40
            || dggClsDruid(9) != 10
            || dggAbiWis(9) != 17
            || dggRosPlane(9) != 6
        )
            ++bad;
        // the Lu Yueh walk: the 25-point regeneration, the rotting sickness
        // doctrine, the evil-gift percents, CH -3
    if (dggCbtHP(10) != 367
            || dggCbtAtN(10) != 6
            || dggCbtMR(10) != 0
            || dggCbtSizeIn(10) != 120
            || dggLuYuehRegenPerRound() != 25
            || dggLuYuehRotRangeFeet() != 10
            || dggLuYuehRedFeverPerMelee() != 3
            || dggLuYuehCloudSizeInches() != 3
            || dggLuYuehEvilActPeople() != 500
            || dggLuYuehWatchingPct() != 1
            || dggLuYuehGiftPct() != 5
            || dggAbiCha(10) != -3
            || dggAbiWis(10) != 5
        )
            ++bad;
        // the Ma Yuan monster walk: 300 hit points, +3 to hit, the 10 slain
        // deities, the 16+ attacks, X/32,300
    if (dggCbtAC(11) != -4
            || dggCbtHP(11) != 300
            || dggCbtAtN(11) != 5
            || dggCbtMR(11) != 65
            || dggCbtSizeIn(11) != 840
            || dggMaYuanDmgLo() != 3
            || dggMaYuanDmgHi() != 30
            || dggMaYuanDmg2Lo() != 5
            || dggMaYuanDmg2Hi() != 40
            || dggMaYuanWeaponPlusToHit() != 3
            || dggMaYuanMinDeitiesKilled() != 10
            || dggMaYuanAttackHD() != 16
            || dggMaYuanXpValue() != 32300
            || dggRosRank(11) != 3
            || dggRosPsiClass(11) != 0
        )
            ++bad;
        // the No Cha walk: 8 attacks, the +3 flaming spear for 30, the gold
        // brick 5-50 at 100 yards, the 5-round bracelet, the 30-point
        // fireball
    if (dggCbtHP(12) != 239
            || dggCbtAtN(12) != 8
            || dggCbtMove(12) != 15
            || dggCbtMoveAlt(12) != 48
            || dggNoChaSpearPlus() != 3
            || dggNoChaSpearDmg() != 30
            || dggNoChaGoldDmgLo() != 5
            || dggNoChaGoldDmgHi() != 50
            || dggNoChaGoldRangeYards() != 100
            || dggNoChaBraceletRounds() != 5
            || dggNoChaFireballDmg() != 30
            || dggClsIllus(12) != 17
            || dggClsThief(12) != 20
            || dggRosAlign(12) != 7
            || dggRosPlane(12) != 8
        )
            ++bad;
        // the Shan Hai Ching walk: the 5-50 hurricane, the sea summoning, the
        // spell turning, the 6 over 48 move
    if (dggCbtHP(13) != 366
            || dggCbtMove(13) != 6
            || dggCbtMoveAlt(13) != 48
            || dggCbtMR(13) != 35
            || dggShanHaiHurricaneDmgLo() != 5
            || dggShanHaiHurricaneDmgHi() != 50
            || dggClsCleric(13) != 10
            || dggAbiStr(13) != 24
            || dggRosPlane(13) != 1
        )
            ++bad;
        // the Spirits of the Air walk: 50 hit points, the 1-100 appearing,
        // the 11-HD attacks, the 100-per-day summons
    if (dggCbtAC(14) != 4
            || dggCbtHP(14) != 50
            || dggCbtAtN(14) != 2
            || dggCbtMR(14) != 0
            || dggSpiritsSummonPerDay() != 100
            || dggSpiritsAttackHD() != 11
            || dggSpiritsHP() != 50
            || dggSpiritsAppearingLo() != 1
            || dggSpiritsAppearingHi() != 100
            || dggRosRank(14) != 3
            || dggRosAlign(14) != 4
        )
            ++bad;
        // the Tou Mu adjudications: the psionic class II (the 29px word vs
        // the Termux I), 8 attacks, the 16 arms, the chariot doctrine
    if (dggRosPsiClass(15) != 2
            || dggCbtHP(15) != 300
            || dggCbtAtN(15) != 8
            || dggCbtMR(15) != 25
            || dggCbtSizeIn(15) != 240
            || dggTouMuArmsCount() != 16
            || dggTouMuBowRangeYards() != 100
            || dggTouMuArrowDmgLo() != 1
            || dggTouMuArrowDmgHi() != 10
            || dggTouMuFlagDeathSpells() != 3
            || dggTouMuDragonHeadHP() != 80
            || dggTouMuChariotCount() != 5
            || dggTouMuChariotTongueFeet() != 32
            || dggTouMuOverrunDmgLo() != 2
            || dggTouMuOverrunDmgHi() != 12
            || dggTouMuAttacksPerMelee() != 8
        )
            ++bad;
        // the Wen Chung adjudications: the 2nd-print 213 hit points (the IA
        // 1st print reads 273 - the Gawaine precedent, flagged), the printed
        // 12 over 21 move
    if (dggCbtHP(16) != 213
            || dggCbtMove(16) != 12
            || dggCbtMoveAlt(16) != 21
            || dggCbtMR(16) != 15
            || dggCbtAtN(16) != 3
            || dggCbtAtD(16) != 2
            || dggWenChungEyeBoltDmg() != 20
            || dggWenChungEyeBoltRangeYards() != 180
            || dggWenChungEyeBoltPerDay() != 10
            || dggWenChungSwordPlus() != 3
            || dggAbiStrDmg(16) != 12
            || dggRosAlign(16) != 5
        )
            ++bad;
        // the Yen-Wang-Yeh walk: AC -5, the 2-20 broad sword, the 2 death
        // rays per melee, the soul collection
    if (dggCbtAC(17) != -5
            || dggCbtHP(17) != 349
            || dggCbtMR(17) != 75
            || dggYenWangSwordPlus() != 3
            || dggYenWangSwordDmgLo() != 2
            || dggYenWangSwordDmgHi() != 20
            || dggYenWangDeathRaysPerMelee() != 2
            || dggClsFighterLo(17) != 18
            || dggClsAssassin(17) != 15
            || dggClsMonk(17) != 12
            || dggAbiStr(17) != 14
            || dggRosPlane(17) != 9
        )
            ++bad;
        // the in-each flags across the class grid
    if (dggRosInEach(0) != 1
            || dggRosInEach(3) != 1
            || dggRosInEach(4) != 1
            || dggRosInEach(9) != 1
            || dggRosInEach(10) != 1
            || dggRosInEach(13) != 1
            || dggRosInEach(15) != 1
            || dggRosInEach(16) != 1
            || dggRosInEach(1) != 0
            || dggRosInEach(8) != 0
        )
            ++bad;
        // the alignment census: the lawful evils, the neutral evil No Cha,
        // the chaotic neutral Wen Chung
    if (dggRosAlign(3) != 6
            || dggRosAlign(9) != 6
            || dggRosAlign(0) != 3
            || dggRosAlign(13) != 3
            || dggRosAlign(12) != 7
            || dggRosAlign(16) != 5
            || dggRosAlign(7) != 2
            || dggRosAlign(17) != 4
        )
            ++bad;
        // the rank census: the seven greaters, the four demigods, the five
        // lessers, the two monster rows
    if (dggRosRank(0) != 1
            || dggRosRank(2) != 1
            || dggRosRank(4) != 1
            || dggRosRank(8) != 1
            || dggRosRank(9) != 1
            || dggRosRank(13) != 1
            || dggRosRank(17) != 1
            || dggRosRank(1) != 2
            || dggRosRank(3) != 2
            || dggRosRank(5) != 2
            || dggRosRank(12) != 2
            || dggRosRank(16) != 2
        )
            ++bad;
        // the monster rows read the all-sentinel ability lines
    if (dggAbiStr(11) != 0
            || dggAbiCha(11) != 0
            || dggAbiStr(14) != 0
            || dggAbiCha(14) != 0
            || dggAbiPsi(11) != 0
            || dggAbiPsi(14) != 0
        )
            ++bad;
        // the hit point walk across the eighteen stat blocks
    if (dggCbtHP(1) != 199
            || dggCbtHP(3) != 287
            || dggCbtHP(4) != 319
            || dggCbtHP(7) != 380
            || dggCbtHP(10) != 367
            || dggCbtHP(13) != 366
            || dggCbtHP(15) != 300
            || dggCbtHP(16) != 213
        )
            ++bad;
        printf("R855 Chinese mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
