    // ---- R861 Japanese mythos audit ----
    // THE JAPANESE MYTHOS - the D&DG walk round thirteen, print pp. 81-85.
    // The headline adjudication: the DIGIT-SPLIT calibration - a narrow
    // printed 1 splits into 1 and 7 fragments in the chocr char geometry at
    // 600dpi: the Kishijoten hit points read 31717 and decode as 311, the
    // Kishijoten attack count reads 17 and decodes as 1, the Ebisu hit points
    // read 3173 and decode as 313, and the Hachiman assassin line reads 175th
    // and decodes as 15th. The fraction fingerprint rides again: five X 1/2
    // foot size cells - Ama-Tsu-Mara 78, Daikoku 66, Ebisu 66, Hachiman 78,
    // Susanowo 78. The EBISU PLANE CATCH: the chocr reads the Seven Heavens
    // where the merged-column voice said Prime Material. The AMATERASU
    // WRAP-LINE CATCH: the printed MU/I 20th level in each wrap line restores
    // the illusionist 20 the merged voice dropped. The Amaterasu Infinite
    // move pins as the -1 sentinel (the R857 Ptah precedent); the Susanowo
    // 12/36/48 triple slash encodes Move 12 MoveAlt 36 with the 48 in the col
    // comment (the klv Ahto precedent); the two hero rows print a bare SIZE:
    // M with no height, pinned as 0 (Yamamoto Date, Yoshi-iye). The MONK/BARD
    // in-each cells are new this round: the Amaterasu 15, Oh-Kuni-Nushi 10
    // and Yoshi-iye 5 pairs carry the flag. The flagged odd prints pinned as
    // printed: the Hachiman 28/21 and Oh-Kuni-Nushi 15/12 descending move
    // pairs, Tsukiyomi 12/21, and the Raiko 29 and Yoshi-iye 19 moves without
    // a slash.
    {
        using namespace rules;
        int bad = 0;
    if (jpnRound() != 861
            || jpnPrintStart() != 81
            || jpnPrintEnd() != 85
            || jpnBeingCount() != 13
            || jpnTableCount() != 4
            || jpnChainCount() != 0
            || jpnRegistryFloor() != 995
            || jpnCbtRows() != 13
            || jpnClsRows() != 13
            || jpnAbiRows() != 13
            || jpnRosRows() != 13
            || jpnPlaneCount() != 7
            || jpnGreaterCount() != 5
            || jpnLesserCount() != 3
            || jpnDemigodCount() != 2
            || jpnHeroCount() != 3
            || jpnInEachCount() != 8
            || jpnEnmityCount() != 0
            || jpnPaladinCount() != 2
            || jpnPsiClassKinds() != 4
            || jpnHalfFootCount() != 5
            || jpnArtifactCount() != 0
            || jpnAmaTsuAxeDamage() != 45
            || jpnAmaTsuAxeFeet() != 12
            || jpnAmaTsuBlessingPct() != 2
            || jpnAmaTsuWeaponWeek() != 1
            || jpnAmaterasuFistDamageHi() != 100
            || jpnAmaterasuPolymorphSavePenalty() != 8
            || jpnDaikokuMalletDamage() != 20
            || jpnDaikokuMalletShrinkPct() != 50
            || jpnEbisuStaffDamageHi() != 30
            || jpnHachimanDragonRevertHours() != 48
            || jpnHachimanDragonRounds() != 100
            || jpnHachimanSwordDamageHi() != 40
            || jpnHachimanOpenHandDamageHi() != 20
            || jpnKishijotenLuckPct() != 2
            || jpnOhKuniSwordDamageHi() != 30
            || jpnOhKuniSwordPlus() != 8
            || jpnRaidenTalonDamageHi() != 24
            || jpnRaidenBoltDamage() != 25
            || jpnRaidenMacePlus() != 3
            || jpnRaidenMaceDamageHi() != 20
            || jpnRaidenSplintPlus() != 3
            || jpnRaidenShieldPlus() != 4
            || jpnRaidenShieldWeaponStops() != 1
            || jpnRaidenSlayingArrows() != 10
            || jpnRaikoLongbowMultiplier() != 2
            || jpnSusanowoBoltDamage() != 30
            || jpnSusanowoElementalsLo() != 1
            || jpnSusanowoElementalsHi() != 10
            || jpnSusanowoFlightLossDays() != 7
            || jpnSusanowoSplintDamage() != 20
            || jpnSusanowoSplintBlastFeet() != 10
            || jpnSusanowoSwordDamageHi() != 30
            || jpnTsukiyomiFlyingSummonsPerDay() != 5
            || jpnTsukiyomiPikeDamage() != 40
            || jpnYamamotoDisguiseLevel() != 11
            || !jpnShintoNatureLove()
            || !jpnTemplesTreesGardens()
            || !jpnMaleFemaleClerics()
            || !jpnEightMillionKami()
            || !jpnNoTempleImages()
            || !jpnShrinesFaceSouthEast()
            || !jpnNeverNorthWest()
            || !jpnToriiGateways()
            || !jpnThreeHolySymbols()
            || !jpnPunishmentStripsAbility()
            || !jpnAbilityEarnedBack()
            || !jpnKamiUniversalConcept()
            || !jpnKamiMaterializeDruid()
            || !jpnAmaTsuDancingSwords()
            || !jpnAmaTsuAxeSlaysFire()
            || !jpnAmaterasuMotherOfPantheon()
            || !jpnAmaterasuTrinity()
            || !jpnAmaterasuWeaponsToBirds()
            || !jpnAmaterasuContinualLight()
            || !jpnDaikokuPatronFarmers()
            || !jpnDaikokuWeatherControl()
            || !jpnDaikokuGrowthControl()
            || !jpnDaikokuEtherealWanderer()
            || !jpnDaikokuWealthReward()
            || !jpnDaikokuNegatesMiscMagic()
            || !jpnDaikokuMalletSafety()
            || !jpnEbisuElderlyMale()
            || !jpnEbisuRewardsHardWorkers()
            || !jpnEbisuAlwaysSaves()
            || !jpnEbisuAttackersHalfDamage()
            || !jpnEbisuMissEveryOtherHit()
            || !jpnEbisuPaladin()
            || !jpnHachimanShapeChange()
            || !jpnHachimanImmuneLowSpells()
            || !jpnHachimanImmuneIllusions()
            || !jpnHachimanThrowingKnifeDragon()
            || !jpnHachimanSwordOnlyHeLifts()
            || !jpnHachimanSwordOfSharpness()
            || !jpnKishijotenHumanForm()
            || !jpnKishijotenShapeChange()
            || !jpnKishijotenAlwaysSaves()
            || !jpnKishijotenMonthlyGoodSummon()
            || !jpnKishijotenSummonFreeWill()
            || !jpnKishijotenNeverFights()
            || !jpnOhKuniLandMaster()
            || !jpnOhKuniGroundSpeaks()
            || !jpnOhKuniClericsHeroicActs()
            || !jpnRaidenScaledSkin()
            || !jpnRaidenShapeChange()
            || !jpnRaidenWeatherControl()
            || !jpnRaidenMaceDisenchants()
            || !jpnRaidenWindStormBlocksMissiles()
            || !jpnRaidenAuraNegatesSpells()
            || !jpnRaidenDrumsOfPanic()
            || !jpnRaidenFletcherPatron()
            || !jpnRaidenArrowsUndetectable()
            || !jpnRaikoFavoredOfGods()
            || !jpnRaikoEnchantedMonsterFighter()
            || !jpnRaikoGreaterEndurance()
            || !jpnRaikoSwifterSword()
            || !jpnRaikoAkaYorimitsu()
            || !jpnSusanowoBearded()
            || !jpnSusanowoThunderCloud()
            || !jpnSusanowoShapeChange()
            || !jpnSusanowoRemovesFlight()
            || !jpnSusanowoSwordDeflects()
            || !jpnSusanowoFullMrInWater()
            || !jpnSusanowoSeaCreaturesShield()
            || !jpnTsukiyomiLightBlueSkin()
            || !jpnTsukiyomiShapeChange()
            || !jpnTsukiyomiSummonFlying()
            || !jpnTsukiyomiObjectToHand()
            || !jpnTsukiyomiPikeUnbreakable()
            || !jpnTsukiyomiImmunePoisonPetrif()
            || !jpnTsukiyomiImmuneMagicJar()
            || !jpnYamamotoEmperorSon()
            || !jpnYamamotoDisguiseSkill()
            || !jpnYamamotoDragonSlayingSword()
            || !jpnYamamotoSwordSharpness()
            || !jpnYamamotoBladeSpeed()
            || !jpnYoshiiyeHachimanAnswers()
            || !jpnYoshiiyeMightyAnyWeapon()
            || !jpnYoshiiyeLegendaryBow()
            || !jpnYoshiiyeArrowsPierceRocks()
        )
            ++bad;
        // the the combat grid grid
        int CjpnCbt[13][9] = {
            {-4,0,299,12,12,3,2,50,78},
            {-7,0,400,-1,0,1,0,75,60},
            {2,0,350,9,12,2,0,20,66},
            {-5,0,313,9,12,2,0,50,66},
            {1,0,300,28,21,2,0,35,78},
            {-10,0,311,12,12,1,0,100,60},
            {-4,0,200,15,12,2,0,20,72},
            {-8,0,337,12,24,2,0,80,84},
            {-1,0,180,29,0,2,0,0,72},
            {-4,0,400,12,36,2,0,30,78},
            {-7,0,400,12,21,3,2,30,84},
            {2,0,189,12,0,2,0,0,0},
            {2,0,109,19,0,3,2,0,0},
            };
        for (int b = 0;
             b < jpnCbtRows();
             ++b) {
            int vals[9];
            vals[0] = jpnCbtAC(b);
            vals[1] = jpnCbtACAlt(b);
            vals[2] = jpnCbtHP(b);
            vals[3] = jpnCbtMove(b);
            vals[4] = jpnCbtMoveAlt(b);
            vals[5] = jpnCbtAtN(b);
            vals[6] = jpnCbtAtD(b);
            vals[7] = jpnCbtMR(b);
            vals[8] = jpnCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CjpnCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CjpnCls[13][11] = {
            {10,0,12,0,0,20,0,0,0,0,8},
            {20,14,0,0,0,20,20,0,0,15,15},
            {10,14,12,0,0,12,12,0,0,0,10},
            {30,0,10,10,0,25,0,0,0,0,10},
            {0,0,0,0,20,0,0,0,15,14,0},
            {25,0,0,0,0,20,20,0,0,0,15},
            {0,0,18,0,0,0,0,0,0,10,10},
            {15,0,13,0,0,15,15,0,0,0,0},
            {0,0,0,0,18,0,0,0,12,15,0},
            {10,10,0,0,13,20,0,0,0,0,0},
            {20,0,0,0,12,15,15,0,15,0,10},
            {0,0,15,15,0,0,0,0,0,0,0},
            {0,0,0,0,13,0,0,0,0,5,5},
            };
        for (int b = 0;
             b < jpnClsRows();
             ++b) {
            int vals[11];
            vals[0] = jpnClsCleric(b);
            vals[1] = jpnClsDruid(b);
            vals[2] = jpnClsFighterLo(b);
            vals[3] = jpnClsFighterHi(b);
            vals[4] = jpnClsRanger(b);
            vals[5] = jpnClsMagUser(b);
            vals[6] = jpnClsIllus(b);
            vals[7] = jpnClsThief(b);
            vals[8] = jpnClsAssassin(b);
            vals[9] = jpnClsMonk(b);
            vals[10] = jpnClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CjpnCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CjpnAbi[13][9] = {
            {25,7,14,24,23,25,22,20,0},
            {25,7,14,25,25,25,25,25,0},
            {22,4,10,23,25,24,25,20,0},
            {23,5,11,25,25,22,23,24,0},
            {20,3,8,21,17,25,25,21,0},
            {15,0,0,25,25,20,24,25,0},
            {20,3,8,20,10,20,20,20,0},
            {24,5,12,22,19,24,24,19,0},
            {18,3,6,18,11,19,18,18,0},
            {25,7,14,24,20,25,25,22,0},
            {25,7,14,23,23,25,25,25,0},
            {17,1,1,17,11,19,18,17,0},
            {18,2,4,17,15,19,19,18,0},
            };
        for (int b = 0;
             b < jpnAbiRows();
             ++b) {
            int vals[9];
            vals[0] = jpnAbiStr(b);
            vals[1] = jpnAbiStrHit(b);
            vals[2] = jpnAbiStrDmg(b);
            vals[3] = jpnAbiInt(b);
            vals[4] = jpnAbiWis(b);
            vals[5] = jpnAbiDex(b);
            vals[6] = jpnAbiCon(b);
            vals[7] = jpnAbiCha(b);
            vals[8] = jpnAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CjpnAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CjpnRos[13][9] = {
            {0,81,4,0,5,1,1,0,0},
            {1,81,0,1,1,1,1,1,0},
            {2,81,0,1,6,1,1,1,0},
            {3,82,0,0,1,3,1,0,0},
            {4,82,2,2,1,2,1,0,0},
            {5,82,1,0,2,1,1,1,0},
            {6,83,2,2,5,2,1,1,0},
            {7,83,4,1,5,6,1,1,0},
            {8,84,1,3,0,0,0,0,0},
            {9,84,5,1,5,5,1,1,0},
            {10,84,1,1,6,4,1,1,0},
            {11,85,0,3,0,0,1,0,0},
            {12,85,1,3,0,0,0,1,0},
            };
        for (int b = 0;
             b < jpnRosRows();
             ++b) {
            int vals[9];
            vals[0] = jpnRosOrd(b);
            vals[1] = jpnRosPage(b);
            vals[2] = jpnRosAlign(b);
            vals[3] = jpnRosRank(b);
            vals[4] = jpnRosPsiClass(b);
            vals[5] = jpnRosPlane(b);
            vals[6] = jpnRosDmgFixed(b);
            vals[7] = jpnRosInEach(b);
            vals[8] = jpnRosEnmity(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CjpnRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the thirteen beings, the seven
        // plane codes, the two paladins)
    if (jpnTableCount() != 4
            || jpnBeingCount() != 13
            || jpnCbtRows() != 13
            || jpnClsRows() != 13
            || jpnAbiRows() != 13
            || jpnRosRows() != 13
            || jpnPlaneCount() != 7
            || jpnGreaterCount() != 5
            || jpnLesserCount() != 3
            || jpnDemigodCount() != 2
            || jpnHeroCount() != 3
            || jpnInEachCount() != 8
            || jpnEnmityCount() != 0
            || jpnPaladinCount() != 2
            || jpnPsiClassKinds() != 4
            || jpnHalfFootCount() != 5
            || jpnArtifactCount() != 0
            || jpnChainCount() != 0
            || jpnRegistryFloor() != 995
        )
            ++bad;
        // the print walk spans pp. 81-85 and the roster ordinals run 0-12 in
        // print order
    if (jpnPrintStart() != 81
            || jpnPrintEnd() != 85
            || jpnRosPage(0) != 81
            || jpnRosPage(3) != 82
            || jpnRosPage(6) != 83
            || jpnRosPage(8) != 84
            || jpnRosPage(11) != 85
            || jpnRosOrd(0) != 0
            || jpnRosOrd(12) != 12
        )
            ++bad;
        // Ama-Tsu-Mara the smith: the 78 fraction cell, the 3/2 attacks, the
        // 45-point axe, the dancing swords
    if (jpnCbtSizeIn(0) != 78
            || jpnCbtAtN(0) != 3
            || jpnCbtAtD(0) != 2
            || jpnAmaTsuAxeDamage() != 45
            || jpnAmaTsuAxeFeet() != 12
            || jpnAmaTsuBlessingPct() != 2
            || jpnAmaTsuWeaponWeek() != 1
            || jpnRosPsiClass(0) != 5
            || jpnAbiStr(0) != 25
        )
            ++bad;
        // Amaterasu the mother: the Infinite -1 sentinel move, the double
        // in-each 20 and 15 pairs, the 1 to 100 fist
    if (jpnCbtMove(1) != -1
            || jpnClsMagUser(1) != 20
            || jpnClsIllus(1) != 20
            || jpnClsMonk(1) != 15
            || jpnClsBard(1) != 15
            || jpnRosInEach(1) != 1
            || jpnAmaterasuFistDamageHi() != 100
            || jpnAmaterasuPolymorphSavePenalty() != 8
            || jpnCbtAC(1) != -7
            || jpnCbtMR(1) != 75
        )
            ++bad;
        // Daikoku the farmer patron: the 66 fraction cell, the cleric 10
        // druid 14 pair, the MU/I 12 in each, the 20-point mallet
    if (jpnCbtSizeIn(2) != 66
            || jpnClsCleric(2) != 10
            || jpnClsDruid(2) != 14
            || jpnClsMagUser(2) != 12
            || jpnClsIllus(2) != 12
            || jpnDaikokuMalletDamage() != 20
            || jpnDaikokuMalletShrinkPct() != 50
            || jpnRosPsiClass(2) != 6
        )
            ++bad;
        // Ebisu the Seven Heavens catch: the plane 3 pixel read, the paladin
        // 10/10 pair, the 313 digit-split hp
    if (jpnRosPlane(3) != 3
            || jpnClsFighterLo(3) != 10
            || jpnClsFighterHi(3) != 10
            || jpnCbtHP(3) != 313
            || jpnCbtAC(3) != -5
            || jpnEbisuStaffDamageHi() != 30
            || jpnClsCleric(3) != 30
            || jpnClsMagUser(3) != 25
            || jpnRosPsiClass(3) != 1
        )
            ++bad;
        // Hachiman the god of war: the flagged 28/21 move, the 20th ranger,
        // the 15th assassin 14th monk, the 48-hour dragon
    if (jpnCbtMove(4) != 28
            || jpnCbtMoveAlt(4) != 21
            || jpnClsRanger(4) != 20
            || jpnClsAssassin(4) != 15
            || jpnClsMonk(4) != 14
            || jpnHachimanDragonRevertHours() != 48
            || jpnHachimanDragonRounds() != 100
            || jpnHachimanSwordDamageHi() != 40
            || jpnRosPlane(4) != 2
        )
            ++bad;
        // Kishijoten the luck goddess: the minus 10 armor class, the 311
        // digit-split hp, the single attack, MR 100
    if (jpnCbtAC(5) != -10
            || jpnCbtHP(5) != 311
            || jpnCbtAtN(5) != 1
            || jpnCbtMR(5) != 100
            || jpnKishijotenLuckPct() != 2
            || jpnClsBard(5) != 15
            || jpnRosPsiClass(5) != 2
            || jpnAbiStr(5) != 15
        )
            ++bad;
        // Oh-Kuni-Nushi the Land Master: the flagged 15/12 move, the 18th
        // fighter, the monk/bard 10 in-each pair
    if (jpnCbtMove(6) != 15
            || jpnCbtMoveAlt(6) != 12
            || jpnClsFighterLo(6) != 18
            || jpnClsMonk(6) != 10
            || jpnClsBard(6) != 10
            || jpnRosInEach(6) != 1
            || jpnOhKuniSwordPlus() != 8
            || jpnOhKuniSwordDamageHi() != 30
            || jpnRosPlane(6) != 2
        )
            ++bad;
        // Raiden the thunder god: the Elemental Air plane, the 25-point
        // bolts, the ten slaying arrows, the +4 shield
    if (jpnRosPlane(7) != 6
            || jpnRaidenBoltDamage() != 25
            || jpnRaidenSlayingArrows() != 10
            || jpnRaidenShieldPlus() != 4
            || jpnRaidenMacePlus() != 3
            || jpnRaidenTalonDamageHi() != 24
            || jpnCbtAC(7) != -8
            || jpnCbtMR(7) != 80
            || jpnRosPsiClass(7) != 5
        )
            ++bad;
        // Raiko the hero: the flagged 29 move, the 18th ranger, by-weapon
        // damage 0, the bare 72 six-footer
    if (jpnCbtMove(8) != 29
            || jpnClsRanger(8) != 18
            || jpnRosDmgFixed(8) != 0
            || jpnCbtMR(8) != 0
            || jpnRaikoLongbowMultiplier() != 2
            || jpnRosRank(8) != 3
            || jpnClsAssassin(8) != 12
            || jpnClsMonk(8) != 15
            || jpnRosPlane(8) != 0
        )
            ++bad;
        // Susanowo the storm: the 12/36 triple-slash with the 48 in the
        // comment, MR 30 or 100 in water, the 7-day flight loss
    if (jpnCbtMove(9) != 12
            || jpnCbtMoveAlt(9) != 36
            || jpnCbtMR(9) != 30
            || jpnSusanowoFlightLossDays() != 7
            || jpnSusanowoBoltDamage() != 30
            || jpnSusanowoElementalsHi() != 10
            || jpnSusanowoSwordDamageHi() != 30
            || jpnRosPlane(9) != 5
            || jpnCbtSizeIn(9) != 78
        )
            ++bad;
        // Tsukiyomi the moon: the Elysium plane, the 3/2 attacks, the MU/I 15
        // in each, the unbreakable 40-point pike
    if (jpnRosPlane(10) != 4
            || jpnCbtAtN(10) != 3
            || jpnCbtAtD(10) != 2
            || jpnClsMagUser(10) != 15
            || jpnClsIllus(10) != 15
            || jpnTsukiyomiPikeDamage() != 40
            || jpnTsukiyomiFlyingSummonsPerDay() != 5
            || jpnClsBard(10) != 10
            || jpnRosPsiClass(10) != 6
        )
            ++bad;
        // Yamamoto Date the hero: the bare M size 0 row, the paladin 15/15
        // pair, the 11th level disguise skill
    if (jpnCbtSizeIn(11) != 0
            || jpnClsFighterLo(11) != 15
            || jpnClsFighterHi(11) != 15
            || jpnYamamotoDisguiseLevel() != 11
            || jpnCbtHP(11) != 189
            || jpnCbtAC(11) != 2
            || jpnRosRank(11) != 3
            || jpnRosPsiClass(11) != 0
            || jpnRosPlane(11) != 0
        )
            ++bad;
        // Yoshi-iye the hero: the bare M size 0 row, the flagged 19 move, the
        // monk/bard 5 in-each pair, the arrow-or-weapon damage
    if (jpnCbtSizeIn(12) != 0
            || jpnCbtMove(12) != 19
            || jpnClsMonk(12) != 5
            || jpnClsBard(12) != 5
            || jpnRosInEach(12) != 1
            || jpnRosDmgFixed(12) != 0
            || jpnClsRanger(12) != 13
            || jpnCbtAtN(12) != 3
            || jpnCbtHP(12) != 109
        )
            ++bad;
        printf("R861 Japanese mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
