    // ---- R860 Indian mythos audit ----
    // THE INDIAN MYTHOS - the D&DG walk round twelve, print pp. 75-80. The
    // headline adjudication: the PSIONIC THREE-PIPE CATCH - the Indra glyph
    // group reads TI! at 47px word width and Kali prints III as
    // I(9)I(10)I(10) in the chocr char geometry, exactly the Kali three-pipe
    // class III and the Indra class III (the Termux voice read 11l and 1Nl,
    // both three glyphs) - the chocr 600dpi calibration: single pipe w10, V
    // w36, VI w49, III w47. The fraction fingerprint rides again: the Ushas
    // (514) and Varuna (614) size cells are the half-foot clusters (small-1
    // w24 + low-4 w40), 5 1/2 and 6 1/2 foot, 66 and 78 inches. The Surya AC
    // catch: the chocr reads the minus three the Termux dash dropped. The
    // flagged odd prints pinned as printed: Indra AC the em-dash minus
    // twelve, Kali move 27 without a slash, Kali wisdom 5 and MR 39 percent,
    // the Marut move 9 apostrophe, the Buffalo 12 inch shoulders cell, Yama
    // MR 25 with the 100 percent robes.
    {
        using namespace rules;
        int bad = 0;
    if (idnRound() != 860
            || idnPrintStart() != 75
            || idnPrintEnd() != 80
            || idnBeingCount() != 18
            || idnTableCount() != 4
            || idnChainCount() != 0
            || idnRegistryFloor() != 995
            || idnCbtRows() != 18
            || idnClsRows() != 18
            || idnAbiRows() != 18
            || idnRosRows() != 18
            || idnPlaneCount() != 9
            || idnGreaterCount() != 6
            || idnLesserCount() != 3
            || idnDemigodCount() != 4
            || idnMonsterCount() != 5
            || idnInEachCount() != 3
            || idnEnmityCount() != 0
            || idnPaladinCount() != 3
            || idnPsiClassKinds() != 4
            || idnHalfFootCount() != 2
            || idnArtifactCount() != 0
            || idnIndraBoltsPerRound() != 2
            || idnIndraBoltDamage() != 30
            || idnIndraBoltRange() != 1000
            || idnIndraSwordPlus() != 3
            || idnIndraArmorPlus() != 4
            || idnElephantHitDice() != 16
            || idnElephantXpBase() != 21450
            || idnAgniLegs() != 3
            || idnAgniArms() != 7
            || idnAgniHeads() != 3
            || idnAgniControlMiles() != 1
            || idnAgniFireSpellLevel() != 50
            || idnAgniAuraDamage() != 25
            || idnAgniMeltPlus() != 4
            || idnAgniBreathUses() != 3
            || idnAgniBreathYards() != 30
            || idnAgniBreathDamage() != 50
            || idnAgniChariotGround() != 36
            || idnAgniChariotAir() != 48
            || idnAgniHorseAc() != 2
            || idnAgniHorseHd() != 10
            || idnAgniHorseHp() != 90
            || idnKaliEyes() != 3
            || idnKaliArms() != 4
            || idnKaliTalonDamage() != 40
            || idnKaliSwordDamage() != 24
            || idnKarttikeyaHeads() != 6
            || idnKarttikeyaArms() != 12
            || idnKarttikeyaSwords() != 10
            || idnKarttikeyaSwordDamage() != 12
            || idnKarttikeyaAidPct() != 2
            || idnPeacockHitDice() != 16
            || idnPeacockBeakDamage() != 36
            || idnPeacockXpBase() != 12200
            || idnLakshmiLotusSpeed() != 75
            || idnMarutAppearLo() != 1
            || idnMarutAppearHi() != 10
            || idnMarutBattleHi() != 100
            || idnMarutLairPct() != 25
            || idnMarutHitDice() != 16
            || idnMarutXpBase() != 16700
            || idnRatriDarknessRadius() != 15
            || idnRudraSavePenalty() != 6
            || idnSuryaSleepRange() != 15
            || idnSuryaSleepLevel() != 20
            || idnSuryaSwordPlus() != 4
            || idnSuryaSwordDamage() != 40
            || idnSuryaLightYards() != 1000
            || idnSuryaChariotHorses() != 7
            || idnSuryaChariotHeat() != 30
            || idnTvashtriNullifyYards() != 200
            || idnTvashtriBeamDamage() != 40
            || idnTvashtriBeamRange() != 30
            || idnTvashtriRegen() != 20
            || idnUshasBlindTurns() != 4
            || idnUshasRegen() != 30
            || idnUshasGazeDamage() != 10
            || idnVarunaOathPct() != 1
            || idnVarunaAuraFeet() != 5
            || idnVarunaSpearDamage() != 50
            || idnVishnuPeaceYards() != 30
            || idnVishnuDiscDamage() != 50
            || idnVishnuDiscYards() != 40
            || idnVishnuAidMaxPct() != 20
            || idnVishnuLotusUses() != 3
            || idnVishnuAvatarClericLevel() != 15
            || idnVishnuAvatarWisdom() != 25
            || idnGarudaCarryGods() != 5
            || idnGarudaSenseMiles() != 1
            || idnGarudaWingDamage() != 24
            || idnGarudaHitDice() != 16
            || idnGarudaXpBase() != 17100
            || idnYamaRobeMr() != 100
            || idnYamaNoosePlus() != 5
            || idnYamaNooseRounds() != 3
            || idnYamaMacePlus() != 3
            || idnYamaFlashRounds() != 2
            || idnYamaSpellLevel() != 20
            || idnBuffaloCarryGods() != 2
            || idnBuffaloGoreDamage() != 40
            || idnBuffaloHitDice() != 16
            || idnBuffaloShoulderInches() != 12
            || idnBuffaloXpBase() != 11500
            || !idnVedicHinduMixture()
            || !idnAloofGreaterThanNormal()
            || !idnBornToStation()
            || !idnNoClassSwitch()
            || !idnMagicUserCasteSupreme()
            || !idnHigherStatusRespect()
            || !idnProperSacrificeAnswered()
            || !idnImproperSacrificeRepeat()
            || !idnWorshipMarksWorn()
            || !idnVishnuForeheadMark()
            || !idnAvatarLesserPowers()
            || !idnAvatarSpecificFunction()
            || !idnAvatarSeveralSimultaneous()
            || !idnVishnuManyAvatars()
            || !idnHugeShrines()
            || !idnTinyShrines()
            || !idnManyHeadsArms()
            || !idnArmsMatchAbilities()
            || !idnIndraFirstRuler()
            || !idnIndraWeatherControl()
            || !idnIndraStaffOfCommand()
            || !idnIndraShapeChange()
            || !idnElephantCarryWeight()
            || !idnElephantPlaneCarry()
            || !idnAgniCompletelyRed()
            || !idnAgniFireControl()
            || !idnAgniAxeSlayLesser()
            || !idnAgniAuraMeltsWeapons()
            || !idnAgniCureDisease()
            || !idnAgniVoiceCharm()
            || !idnAgniShapeChange()
            || !idnAgniHorsesImmuneHeat()
            || !idnKaliBlackEarthMother()
            || !idnKaliVisageFear()
            || !idnKaliShapeChange()
            || !idnKaliBloodSacrifice()
            || !idnKaliCultBerserk()
            || !idnKarttikeyaCreatedForDevils()
            || !idnKarttikeyaRidesPeacock()
            || !idnPeacockMetalFeathers()
            || !idnPeacockLightningBeak()
            || !idnPeacockIndependent()
            || !idnLakshmiGoldenSkin()
            || !idnLakshmiLotusOnlyHer()
            || !idnLakshmiAlwaysSaves()
            || !idnLakshmiImmuneFlying()
            || !idnLakshmiRightEyeLuck()
            || !idnLakshmiLeftEyeAnti()
            || !idnMarutWindTroops()
            || !idnMarutInvisibleUnlessAttacking()
            || !idnMarutUncharmable()
            || !idnMarutFly()
            || !idnRatriWellProportioned()
            || !idnRatriShadowBlind()
            || !idnRatriCloakEthereal()
            || !idnRatriAngryLook()
            || !idnRudraDiseaseArrows()
            || !idnRudraDiseaseRemedies()
            || !idnRudraStormControl()
            || !idnRudraPortableHole()
            || !idnSuryaPaladin()
            || !idnSuryaSleepNoSave()
            || !idnSuryaSeesSunlit()
            || !idnSuryaContinualLight()
            || !idnSuryaDemonsFirst()
            || !idnTvashtriArtificerGod()
            || !idnTvashtriGodWeaponsSafe()
            || !idnTvashtriRegenFullAttention()
            || !idnTvashtriPatronArtisans()
            || !idnUshasReincarnate()
            || !idnUshasDawnRespawn()
            || !idnUshasLightBlind()
            || !idnUshasInstantAwakening()
            || !idnVarunaPaladin()
            || !idnVarunaOathProtector()
            || !idnVarunaEthereal()
            || !idnVarunaLawfulAura()
            || !idnVishnuPaladin()
            || !idnVishnuFourArms()
            || !idnVishnuNoViolence()
            || !idnVishnuPrismaticDouble()
            || !idnVishnuUndeadDust()
            || !idnVishnuMaceDisintegrate()
            || !idnVishnuShellEthereal()
            || !idnVishnuGarudaCharmImmune()
            || !idnVishnuShowsMercy()
            || !idnGarudaHatesEvil()
            || !idnGarudaSummonAvians()
            || !idnGarudaSenseEvil()
            || !idnYamaFirstMortal()
            || !idnYamaJudgeOfDead()
            || !idnYamaRobeNegateHeat()
            || !idnYamaRobeFly()
            || !idnYamaEtherealArmor()
            || !idnBuffaloPlaneTravel()
            || !idnBuffaloPullUnattached()
            || !idnBuffaloLoyalToYama()
            || !idnBuffaloComplexOrders()
        )
            ++bad;
        // the the combat grid grid
        int CidnCbt[18][9] = {
            {-12,0,400,18,24,2,0,80,72},
            {0,0,150,18,24,5,0,25,240},
            {-2,0,378,18,18,2,0,75,120},
            {-9,0,279,27,0,4,0,39,240},
            {-8,0,222,18,0,10,0,50,240},
            {2,0,120,24,36,1,0,0,240},
            {-3,0,300,18,75,0,0,100,72},
            {-2,0,100,9,24,1,0,50,72},
            {-2,0,250,18,0,1,0,25,60},
            {-2,0,344,18,24,2,0,25,72},
            {-3,0,360,18,0,2,0,50,120},
            {-3,0,227,15,0,1,0,65,72},
            {-2,0,300,18,24,0,0,60,66},
            {-2,0,329,15,24,3,2,80,78},
            {-5,0,389,18,27,2,0,85,72},
            {-1,0,100,18,48,2,0,75,720},
            {-1,0,229,15,0,2,0,25,84},
            {3,0,100,24,0,1,0,0,12},
            };
        for (int b = 0;
             b < idnCbtRows();
             ++b) {
            int vals[9];
            vals[0] = idnCbtAC(b);
            vals[1] = idnCbtACAlt(b);
            vals[2] = idnCbtHP(b);
            vals[3] = idnCbtMove(b);
            vals[4] = idnCbtMoveAlt(b);
            vals[5] = idnCbtAtN(b);
            vals[6] = idnCbtAtD(b);
            vals[7] = idnCbtMR(b);
            vals[8] = idnCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CidnCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CidnCls[18][11] = {
            {25,0,14,0,0,20,20,0,0,0,10},
            {0,0,0,0,0,0,0,0,0,0,0},
            {20,0,15,0,0,99,99,0,0,0,0},
            {10,10,20,0,0,15,15,0,15,13,0},
            {0,0,18,0,0,0,0,10,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {20,0,0,0,0,20,20,0,0,0,10},
            {0,0,0,0,0,0,0,0,0,0,0},
            {10,0,0,0,0,5,15,0,15,0,0},
            {0,14,14,0,0,0,25,15,0,0,0},
            {20,0,16,16,0,15,0,0,0,0,8},
            {15,0,11,0,0,20,0,0,0,0,0},
            {20,0,0,0,0,0,15,0,0,0,0},
            {15,0,14,14,0,20,0,0,0,0,4},
            {15,0,17,17,0,25,18,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            {10,0,14,0,0,99,99,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0},
            };
        for (int b = 0;
             b < idnClsRows();
             ++b) {
            int vals[11];
            vals[0] = idnClsCleric(b);
            vals[1] = idnClsDruid(b);
            vals[2] = idnClsFighterLo(b);
            vals[3] = idnClsFighterHi(b);
            vals[4] = idnClsRanger(b);
            vals[5] = idnClsMagUser(b);
            vals[6] = idnClsIllus(b);
            vals[7] = idnClsThief(b);
            vals[8] = idnClsAssassin(b);
            vals[9] = idnClsMonk(b);
            vals[10] = idnClsBard(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CidnCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CidnAbi[18][9] = {
            {25,7,14,25,25,25,25,25,0},
            {0,0,0,0,0,0,0,0,0},
            {24,6,12,21,20,25,24,20,0},
            {25,7,14,18,5,25,24,-7,0},
            {25,7,14,20,16,25,20,18,0},
            {0,0,0,0,0,0,0,0,0},
            {10,0,0,25,25,20,23,24,0},
            {0,0,0,0,0,0,0,0,0},
            {19,3,7,22,20,19,21,23,0},
            {21,4,9,23,20,25,24,20,0},
            {24,6,12,24,24,24,24,20,0},
            {19,3,7,25,22,21,23,19,0},
            {17,1,1,21,23,25,22,23,0},
            {23,5,11,25,25,23,22,18,0},
            {23,5,11,23,25,24,24,25,0},
            {0,0,0,0,0,0,0,0,0},
            {21,4,9,24,18,18,18,18,0},
            {0,0,0,0,0,0,0,0,0},
            };
        for (int b = 0;
             b < idnAbiRows();
             ++b) {
            int vals[9];
            vals[0] = idnAbiStr(b);
            vals[1] = idnAbiStrHit(b);
            vals[2] = idnAbiStrDmg(b);
            vals[3] = idnAbiInt(b);
            vals[4] = idnAbiWis(b);
            vals[5] = idnAbiDex(b);
            vals[6] = idnAbiCon(b);
            vals[7] = idnAbiCha(b);
            vals[8] = idnAbiPsi(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CidnAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CidnRos[18][9] = {
            {0,75,5,1,3,1,1,1,0},
            {1,75,4,5,0,0,1,0,0},
            {2,76,5,1,1,1,1,0,0},
            {3,76,8,0,3,3,1,1,0},
            {4,76,2,2,6,2,1,0,0},
            {5,76,0,5,0,0,1,0,0},
            {6,77,2,0,6,2,0,1,0},
            {7,77,4,5,0,0,0,0,0},
            {8,77,7,2,5,4,1,0,0},
            {9,77,3,1,5,5,1,0,0},
            {10,78,0,1,6,6,1,0,0},
            {11,78,4,2,1,8,1,0,0},
            {12,78,1,0,6,7,0,0,0},
            {13,79,3,1,6,5,1,0,0},
            {14,79,0,1,1,6,1,0,0},
            {15,79,0,5,0,0,1,0,0},
            {16,80,3,2,5,5,1,0,0},
            {17,80,3,5,0,0,1,0,0},
            };
        for (int b = 0;
             b < idnRosRows();
             ++b) {
            int vals[9];
            vals[0] = idnRosOrd(b);
            vals[1] = idnRosPage(b);
            vals[2] = idnRosAlign(b);
            vals[3] = idnRosRank(b);
            vals[4] = idnRosPsiClass(b);
            vals[5] = idnRosPlane(b);
            vals[6] = idnRosDmgFixed(b);
            vals[7] = idnRosInEach(b);
            vals[8] = idnRosEnmity(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CidnRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the eighteen beings, the nine
        // plane codes, the three paladins)
    if (idnTableCount() != 4
            || idnBeingCount() != 18
            || idnCbtRows() != 18
            || idnClsRows() != 18
            || idnAbiRows() != 18
            || idnRosRows() != 18
            || idnPlaneCount() != 9
            || idnGreaterCount() != 6
            || idnLesserCount() != 3
            || idnDemigodCount() != 4
            || idnMonsterCount() != 5
            || idnInEachCount() != 3
            || idnEnmityCount() != 0
            || idnPaladinCount() != 3
            || idnPsiClassKinds() != 4
            || idnHalfFootCount() != 2
            || idnArtifactCount() != 0
            || idnChainCount() != 0
            || idnRegistryFloor() != 995
        )
            ++bad;
        // the print walk spans pp. 75-80 and the roster ordinals run 0-17 in
        // print order
    if (idnPrintStart() != 75
            || idnPrintEnd() != 80
            || idnRosPage(0) != 75
            || idnRosPage(2) != 76
            || idnRosPage(6) != 77
            || idnRosPage(10) != 78
            || idnRosPage(13) != 79
            || idnRosPage(16) != 80
            || idnRosOrd(0) != 0
            || idnRosOrd(17) != 17
        )
            ++bad;
        // Indra the first ruler: the em-dash minus twelve, 400 hp, the MU/I
        // 20 in each, psionic III
    if (idnCbtAC(0) != -12
            || idnCbtHP(0) != 400
            || idnClsMagUser(0) != 20
            || idnClsIllus(0) != 20
            || idnRosInEach(0) != 1
            || idnRosPsiClass(0) != 3
            || idnAbiStr(0) != 25
            || idnAbiStrDmg(0) != 14
            || idnClsCleric(0) != 25
            || idnIndraBoltDamage() != 30
            || idnIndraBoltsPerRound() != 2
        )
            ++bad;
        // the Elephant of Indra: 5 attacks, the 240-inch L 20 foot, the
        // X/21,450 xp
    if (idnCbtAtN(1) != 5
            || idnCbtSizeIn(1) != 240
            || idnCbtHP(1) != 150
            || idnCbtMR(1) != 25
            || idnRosRank(1) != 5
            || idnElephantXpBase() != 21450
            || idnElephantHitDice() != 16
        )
            ++bad;
        // Agni the fire god: fighter 15, the See below 99/99 pair,
        // S:24(+6,+12), the 50th level fire spells
    if (idnClsFighterLo(2) != 15
            || idnClsMagUser(2) != 99
            || idnClsIllus(2) != 99
            || idnAbiStr(2) != 24
            || idnAbiStrHit(2) != 6
            || idnAbiStrDmg(2) != 12
            || idnRosPsiClass(2) != 1
            || idnAgniFireSpellLevel() != 50
            || idnAgniArms() != 7
            || idnCbtSizeIn(2) != 120
        )
            ++bad;
        // Kali the black earth mother: the minus 7 charisma, the flagged
        // wisdom 5, psionic III, assassin 15 monk 13
    if (idnAbiCha(3) != -7
            || idnAbiWis(3) != 5
            || idnRosPsiClass(3) != 3
            || idnClsAssassin(3) != 15
            || idnClsMonk(3) != 13
            || idnClsCleric(3) != 10
            || idnClsDruid(3) != 10
            || idnRosInEach(3) != 1
            || idnCbtMR(3) != 39
            || idnKaliTalonDamage() != 40
        )
            ++bad;
        // Karttikeya: the ten sword attacks, AC -8, thief 10, the 2 percent
        // devil aid
    if (idnCbtAtN(4) != 10
            || idnCbtAC(4) != -8
            || idnClsThief(4) != 10
            || idnKarttikeyaAidPct() != 2
            || idnKarttikeyaHeads() != 6
            || idnKarttikeyaSwords() != 10
            || idnRosPsiClass(4) != 6
            || idnRosPlane(4) != 2
        )
            ++bad;
        // the Peacock of Karttikeya: MR Standard 0, the 3-36 beak, xp
        // X/12,200
    if (idnCbtMR(5) != 0
            || idnPeacockBeakDamage() != 36
            || idnPeacockXpBase() != 12200
            || idnRosAlign(5) != 0
            || idnCbtMove(5) != 24
            || idnCbtMoveAlt(5) != 36
        )
            ++bad;
        // Lakshmi: the zero attack row, MR 100, the 18/75 lotus move, bard 10
    if (idnCbtAtN(6) != 0
            || idnCbtMR(6) != 100
            || idnCbtMove(6) != 18
            || idnCbtMoveAlt(6) != 75
            || idnClsBard(6) != 10
            || idnRosDmgFixed(6) != 0
            || idnLakshmiLotusSpeed() != 75
            || idnAbiStr(6) != 10
        )
            ++bad;
        // the Marut: the flagged 9 apostrophe move, by-weapon damage 0, the
        // wind troop flags
    if (idnCbtMove(7) != 9
            || idnCbtMoveAlt(7) != 24
            || idnRosDmgFixed(7) != 0
            || idnMarutLairPct() != 25
            || idnMarutXpBase() != 16700
            || idnMarutAppearHi() != 10
            || idnMarutBattleHi() != 100
            || idnCbtAC(7) != -2
        )
            ++bad;
        // Ratri the night: MU 5 illusionist 15, neutral evil, the Hades
        // plane, psionic V
    if (idnClsMagUser(8) != 5
            || idnClsIllus(8) != 15
            || idnRosAlign(8) != 7
            || idnRosPlane(8) != 4
            || idnRosPsiClass(8) != 5
            || idnClsAssassin(8) != 15
            || idnRatriDarknessRadius() != 15
            || idnAbiStr(8) != 19
        )
            ++bad;
        // Rudra: the 14th druid, 25th illusionist, thief 15, S:21(+4,+9)
    if (idnClsDruid(9) != 14
            || idnClsIllus(9) != 25
            || idnClsThief(9) != 15
            || idnClsFighterLo(9) != 14
            || idnAbiStrHit(9) != 4
            || idnAbiStrDmg(9) != 9
            || idnRudraSavePenalty() != 6
            || idnRosPlane(9) != 5
        )
            ++bad;
        // Surya the AC catch: the chocr minus three over the Termux bare
        // dash, the paladin 16/16 pair
    if (idnCbtAC(10) != -3
            || idnClsFighterLo(10) != 16
            || idnClsFighterHi(10) != 16
            || idnSuryaSwordPlus() != 4
            || idnSuryaSleepLevel() != 20
            || idnSuryaChariotHorses() != 7
            || idnCbtSizeIn(10) != 120
            || idnClsBard(10) != 8
        )
            ++bad;
        // Tvashtri the artificer: the pixel-verified D:21, psionic I, the
        // Concordant Opposition plane 8
    if (idnAbiDex(11) != 21
            || idnRosPsiClass(11) != 1
            || idnRosPlane(11) != 8
            || idnClsCleric(11) != 15
            || idnClsFighterLo(11) != 11
            || idnTvashtriNullifyYards() != 200
            || idnTvashtriRegen() != 20
            || idnAbiInt(11) != 25
        )
            ++bad;
        // Ushas the fraction: the pixel-verified 5 1/2 foot 66 cell,
        // illusionist 15, MR 60
    if (idnCbtSizeIn(12) != 66
            || idnClsIllus(12) != 15
            || idnCbtMR(12) != 60
            || idnUshasRegen() != 30
            || idnUshasGazeDamage() != 10
            || idnUshasBlindTurns() != 4
            || idnRosPlane(12) != 7
            || idnRosAlign(12) != 1
        )
            ++bad;
        // Varuna the fraction: the 6 1/2 foot 78 cell, the 3/2 attacks, the
        // paladin 14/14 pair, MR 80
    if (idnCbtSizeIn(13) != 78
            || idnCbtAtN(13) != 3
            || idnCbtAtD(13) != 2
            || idnClsFighterLo(13) != 14
            || idnClsFighterHi(13) != 14
            || idnCbtMR(13) != 80
            || idnVarunaOathPct() != 1
            || idnVarunaSpearDamage() != 50
            || idnClsBard(13) != 4
        )
            ++bad;
        // Vishnu: AC -5, the paladin 17/17 pair, MU 25 illusionist 18,
        // psionic I
    if (idnCbtAC(14) != -5
            || idnClsFighterLo(14) != 17
            || idnClsFighterHi(14) != 17
            || idnClsMagUser(14) != 25
            || idnClsIllus(14) != 18
            || idnRosPsiClass(14) != 1
            || idnAbiCha(14) != 25
            || idnVishnuPeaceYards() != 30
            || idnVishnuLotusUses() != 3
        )
            ++bad;
        // Garuda the king of all birds: the 720-inch L 60 foot, sense evil a
        // mile, xp X/17,100
    if (idnCbtSizeIn(15) != 720
            || idnCbtMoveAlt(15) != 48
            || idnGarudaXpBase() != 17100
            || idnGarudaCarryGods() != 5
            || idnGarudaWingDamage() != 24
            || idnRosRank(15) != 5
            || idnCbtAC(15) != -1
        )
            ++bad;
        // Yama the judge of the dead: the See below 99/99 pair, MR 25 with
        // the 100 robes, S:21(+4,+9)
    if (idnClsMagUser(16) != 99
            || idnClsIllus(16) != 99
            || idnCbtMR(16) != 25
            || idnYamaRobeMr() != 100
            || idnAbiStr(16) != 21
            || idnAbiStrHit(16) != 4
            || idnAbiStrDmg(16) != 9
            || idnYamaNooseRounds() != 3
            || idnYamaSpellLevel() != 20
            || idnCbtSizeIn(16) != 84
        )
            ++bad;
        // the Water Buffalo of Yama: AC 3, the one true-inch 12 inch
        // shoulders cell, MR Standard 0
    if (idnCbtAC(17) != 3
            || idnCbtSizeIn(17) != 12
            || idnCbtMR(17) != 0
            || idnBuffaloGoreDamage() != 40
            || idnBuffaloCarryGods() != 2
            || idnBuffaloShoulderInches() != 12
            || idnBuffaloXpBase() != 11500
        )
            ++bad;
        // the monster rows carry no class, ability or psionic cells
    if (idnClsCleric(1) != 0
            || idnClsFighterLo(7) != 0
            || idnAbiStr(15) != 0
            || idnRosPsiClass(5) != 0
            || idnAbiCha(17) != 0
            || idnClsBard(1) != 0
        )
            ++bad;
        printf("R860 Indian mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
