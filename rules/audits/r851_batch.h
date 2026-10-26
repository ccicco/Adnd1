    // ---- R851 Arthurian mythos audit ----
    // THE ARTHURIAN MYTHOS - the D&DG walk round three, print pp. 17-21: the
    // chivalry doctrine, the two knight templates (the average knight of
    // renown and the knight of quality), the two printed knight rosters (90
    // good or neutral, 13 evil, 29 of quality - the names ride the data file
    // doc/data/ddg_arthurian_knights.txt), and thirteen named beings from
    // King Arthur to Sir Tristram of Lyonesse. Zero registry defs touched;
    // the floor holds at 995. The flagged eyeball cells: the Gawaine hit
    // points (the 112 of the second-print extract against the 172 of the
    // archive.org 1st print), the Merlin single attack (the IA 17 a djvu
    // artifact), the Garlon height (garbled in both voices) and the Pellinore
    // 6-foot-4 single-voice size.
    {
        using namespace rules;
        int bad = 0;
    if (dgcRound() != 851
            || dgcPrintStart() != 17
            || dgcPrintEnd() != 21
            || dgcBeingCount() != 15
            || dgcTableCount() != 4
            || dgcChainCount() != 0
            || dgcRegistryFloor() != 995
            || dgcCbtRows() != 15
            || dgcClsRows() != 15
            || dgcAbiRows() != 15
            || dgcRosRows() != 15
            || dgcKnightCount() != 103
            || dgcGoodKnightCount() != 90
            || dgcEvilKnightCount() != 13
            || dgcQualityKnightCount() != 29
            || dgcGoodQualityCount() != 26
            || dgcEvilQualityCount() != 3
            || dgcRenownHPFloor() != 60
            || dgcRenownFighterLo() != 8
            || dgcRenownFighterHi() != 10
            || dgcRenownSpecialFloor() != 10
            || dgcRenownSpecialAvg() != 15
            || dgcRenownLawfulPct() != 80
            || dgcQualityHPFloor() != 70
            || dgcQualityFighterLo() != 10
            || dgcQualityFighterHi() != 13
            || dgcQualitySpecialFloor() != 13
            || dgcQualitySpecialAvg() != 16
            || dgcQualityLawfulPct() != 85
            || dgcQualitySquirePct() != 60
            || dgcQualitySquireLo() != 1
            || dgcQualitySquireHi() != 4
            || dgcQualityMenAtArmsLo() != 1
            || dgcQualityMenAtArmsHi() != 10
            || dgcQualityMercyPct() != 75
            || dgcSquireBetterPct() != 5
            || dgcExcaliburPlus() != 5
            || dgcBernladAxePlus() != 3
            || dgcGarlonEffectiveAC() != -3
            || dgcGawaineStrEarly() != 19
            || dgcGawaineStrMid() != 20
            || dgcGawaineStrLate() != 21
            || dgcGawaineSunStart() != 9
            || dgcGawaineSunEnd() != 12
            || dgcGalatinePlus() != 2
            || dgcMerlinDmgLo() != 1
            || dgcMerlinDmgHi() != 10
            || dgcMerlinPsi() != 300
            || dgcMerlinRegen() != 1
            || dgcMorganDmgLo() != 1
            || dgcMorganDmgHi() != 4
            || dgcMorganRingPlus() != 3
            || !dgcMaloryCollected()
            || !dgcKnightsRepresentChivalry()
            || !dgcChivalryIsFairPlay()
            || !dgcMisfortuneDishonorable()
            || !dgcBetterOddsDishonorable()
            || !dgcRespectsLadiesAndClerics()
            || !dgcSuspiciousOfSorcery()
            || !dgcQuestsWithOaths()
            || !dgcRoundTableOptional()
            || !dgcCamelotBoardgameReference()
            || !dgcKnightsHaveWarhorse()
            || !dgcKnightWeaponList()
            || !dgcKnightsHaveLesserBeast()
            || !dgcKnightsHaveSquire()
            || !dgcSquiresRestrained()
            || !dgcAverageKnightsKill()
            || !dgcQualityKnightsMerciful()
            || !dgcArthurPaladin()
            || !dgcArthurSwordFromStone()
            || !dgcArthurUtherMerlinEctor()
            || !dgcArthurRoundTable()
            || !dgcArthurLawfulRighteousness()
            || !dgcExcaliburSharpness()
            || !dgcScabbardPreventsCutting()
            || !dgcArthurHalfDamageDoctrine()
            || !dgcArthurGoldDragonShield()
            || !dgcBernladGreenArmor()
            || !dgcBernladArmorPersonal()
            || !dgcBernladNeutralStance()
            || !dgcBernladBaitsKnights()
            || !dgcGalahadWhiteArmor()
            || !dgcGalahadParentage()
            || !dgcGalahadParagon()
            || !dgcGalahadHolyGrail()
            || !dgcGarethSonOfLot()
            || !dgcGarethEnemyOfKay()
            || !dgcGarethModest()
            || !dgcGarethHelpsLadies()
            || !dgcGarethManyColors()
            || !dgcGarlonFightsInvisibly()
            || !dgcGarlonDefeatedByConcert()
            || !dgcGarlonWitchOfTheFens()
            || !dgcGarlonPowerForEvil()
            || !dgcGawaineMagicalGift()
            || !dgcGawaineStrengthReturns()
            || !dgcGawaineFavoriteCousin()
            || !dgcGawaineRevengeful()
            || !dgcLamorakSonOfPellinore()
            || !dgcLamorakTournamentChampion()
            || !dgcLamorakKilledTable()
            || !dgcLamorakEnemyOfGawaine()
            || !dgcLamorakKilledTwelve()
            || !dgcLauncelotBestOfBest()
            || !dgcLauncelotFellFromGrace()
            || !dgcLauncelotGalahadSon()
            || !dgcLauncelotLeftTheKing()
            || !dgcLauncelotNeverFails()
            || !dgcLauncelotQuests()
            || !dgcMerlinParentage()
            || !dgcMerlinPowersBeyondMortals()
            || !dgcMerlinGreatDruid()
            || !dgcMerlinNoArmorOrWeapons()
            || !dgcMerlinStaffSpellStorings()
            || !dgcMerlinAbsorbsSpells()
            || !dgcMerlinForeseesRandomly()
            || !dgcMerlinTeleportsFromDanger()
            || !dgcMerlinSurvivedMortalDamage()
            || !dgcMerlinHealsMagically()
            || !dgcMerlinEarthy()
            || !dgcMerlinAttackModesBCE()
            || !dgcMerlinAllDefenses()
            || !dgcMorganHalfSister()
            || !dgcMorganIllusionQueen()
            || !dgcMorganBloodTie()
            || !dgcMorganPartiallyNonhuman()
            || !dgcMorganTricksKnights()
            || !dgcMorganSeduceOrImprison()
            || !dgcMorganPoisonedDagger()
            || !dgcPalomidesRivalOfTristram()
            || !dgcPalomidesScimitar()
            || !dgcPalomidesCompositeBow()
            || !dgcPellinoreFoughtArthur()
            || !dgcPellinoreRoundTable()
            || !dgcPellinoreQuestingBeast()
            || !dgcPellinoreFatedPursuit()
            || !dgcPellinorePastMiddleAge()
            || !dgcTristramSecondBest()
            || !dgcTristramIsolde()
            || !dgcTristramMarkJealous()
        )
            ++bad;
        // the combat stat blocks of the fifteen beings (print pp. 17-21) -
        // the AC (with the template ranges and the Bernlad See below), hit
        // points, moves, attacks, magic resistance and sizes
        int CCbt[15][9] = {
            {3,-2,60,12,6,3,2,0,0},
            {3,-2,70,12,6,3,2,0,78},
            {0,0,123,12,6,2,0,0,72},
            {99,0,99,12,0,2,0,0,84},
            {-4,0,120,12,6,3,0,0,84},
            {-2,0,105,12,6,2,0,0,72},
            {1,0,80,12,6,1,0,0,0},
            {-2,0,112,12,6,2,0,0,72},
            {-2,0,99,12,6,1,0,0,78},
            {-3,0,141,12,6,2,0,0,78},
            {2,0,175,15,0,1,0,0,72},
            {4,0,39,12,0,1,0,0,64},
            {2,0,93,12,9,2,0,0,66},
            {-2,0,65,12,6,1,0,0,76},
            {-3,0,120,12,6,2,0,0,72},
            };
        int nCbt[9] = {0,0,0,0,0,0,0,0,0};
        int eCbt[9] = {1,13,0,0,3,0,13,15,2};
        for (int b = 0;
             b < dgcCbtRows();
             ++b) {
            int vals[9];
            vals[0] = dgcCbtAC(b);
            vals[1] = dgcCbtACAlt(b);
            vals[2] = dgcCbtHP(b);
            vals[3] = dgcCbtMove(b);
            vals[4] = dgcCbtMoveAlt(b);
            vals[5] = dgcCbtAtN(b);
            vals[6] = dgcCbtAtD(b);
            vals[7] = dgcCbtMR(b);
            vals[8] = dgcCbtSizeIn(b);
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
        // the cleric/druid, fighter (with the template level ranges),
        // magic-user/illusionist, thief/assassin, monk/bard level lines of
        // the fifteen beings (0 = Nil or none printed)
        int CCls[15][11] = {
            {0,0,8,10,0,0,0,0,0,0,0},
            {0,0,10,13,0,0,0,0,0,0,0},
            {0,0,14,14,0,0,0,0,0,0,5},
            {0,0,14,14,0,0,0,0,0,0,0},
            {0,0,20,20,0,0,0,0,0,0,0},
            {0,0,17,17,0,0,0,0,0,0,0},
            {0,0,13,13,0,0,0,3,0,0,0},
            {0,0,17,17,0,0,0,0,0,0,0},
            {0,0,15,15,0,0,0,0,0,0,0},
            {0,0,20,20,0,0,0,0,0,0,0},
            {0,14,0,0,0,15,10,0,0,0,0},
            {0,0,0,0,0,12,12,0,0,0,0},
            {0,0,16,16,0,0,0,0,0,3,3},
            {0,0,12,12,0,0,0,0,0,0,0},
            {0,0,17,17,0,0,0,0,0,0,0},
            };
        int nCls[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int eCls[11] = {15,14,2,2,15,13,13,14,15,14,13};
        for (int b = 0;
             b < dgcClsRows();
             ++b) {
            int vals[11];
            vals[0] = dgcClsCleric(b);
            vals[1] = dgcClsDruid(b);
            vals[2] = dgcClsFighterLo(b);
            vals[3] = dgcClsFighterHi(b);
            vals[4] = dgcClsRanger(b);
            vals[5] = dgcClsMagUser(b);
            vals[6] = dgcClsIllus(b);
            vals[7] = dgcClsThief(b);
            vals[8] = dgcClsAssassin(b);
            vals[9] = dgcClsMonk(b);
            vals[10] = dgcClsBard(b);
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
        // the S/I/W/D/C/CH ability lines with the parenthesized strength
        // bonuses and the psionic cells (the two template rows are all 0 -
        // the printed Specials ride the consts)
        int CAbi[15][9] = {
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {18,2,3,18,19,16,18,18,0},
            {18,2,4,17,14,13,18,12,0},
            {18,3,6,15,18,18,18,18,0},
            {18,2,3,12,11,18,18,12,0},
            {15,0,0,15,9,15,17,15,0},
            {18,1,3,16,13,18,18,16,0},
            {18,3,6,13,8,18,18,17,0},
            {19,3,7,14,13,18,18,18,0},
            {15,0,0,19,19,18,18,18,300},
            {10,0,0,18,7,17,18,18,0},
            {17,1,1,18,11,18,17,18,0},
            {18,1,3,15,10,18,18,15,0},
            {18,2,5,16,13,19,18,17,0},
            };
        int nAbi[9] = {0,0,0,0,0,0,0,0,0};
        int eAbi[9] = {2,5,5,2,2,2,2,2,14};
        for (int b = 0;
             b < dgcAbiRows();
             ++b) {
            int vals[9];
            vals[0] = dgcAbiStr(b);
            vals[1] = dgcAbiStrHit(b);
            vals[2] = dgcAbiStrDmg(b);
            vals[3] = dgcAbiInt(b);
            vals[4] = dgcAbiWis(b);
            vals[5] = dgcAbiDex(b);
            vals[6] = dgcAbiCon(b);
            vals[7] = dgcAbiCha(b);
            vals[8] = dgcAbiPsi(b);
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
        // the roster of the fifteen beings: ordinals, print pages, alignments
        // (with the two variable-template codes 4 and 5), paladin flags,
        // psionic modes, hp floors, the Gawaine strength-varies flag, the
        // fixed-damage flags and the template lawful percents
        int CRos[15][9] = {
            {0,17,7,0,0,1,0,0,80},
            {1,17,8,0,0,1,0,0,85},
            {2,18,0,1,0,0,0,0,0},
            {3,19,2,0,0,0,0,0,0},
            {4,19,0,1,0,0,0,0,0},
            {5,19,1,0,0,0,0,0,0},
            {6,19,7,0,0,0,0,0,0},
            {7,19,3,0,0,0,1,0,0},
            {8,20,3,0,0,0,0,0,0},
            {9,20,0,1,0,0,0,0,0},
            {10,20,1,0,1,0,0,1,0},
            {11,20,7,0,0,0,0,1,0},
            {12,21,3,0,0,0,0,0,0},
            {13,21,8,0,0,0,0,0,0},
            {14,21,3,0,0,0,0,0,0},
            };
        int nRos[9] = {0,0,0,0,0,0,0,0,0};
        int eRos[9] = {1,0,3,12,14,13,14,13,13};
        for (int b = 0;
             b < dgcRosRows();
             ++b) {
            int vals[9];
            vals[0] = dgcRosOrd(b);
            vals[1] = dgcRosPage(b);
            vals[2] = dgcRosAlign(b);
            vals[3] = dgcRosPaladin(b);
            vals[4] = dgcRosPsiModes(b);
            vals[5] = dgcRosHPFloor(b);
            vals[6] = dgcRosStrVaries(b);
            vals[7] = dgcRosDmgFixed(b);
            vals[8] = dgcRosLawfulPct(b);
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
        // the census walk (the four grids, the fifteen beings)
    if (dgcTableCount() != 4
            || dgcBeingCount() != 15
            || dgcCbtRows() != 15
            || dgcClsRows() != 15
            || dgcAbiRows() != 15
            || dgcRosRows() != 15
        )
            ++bad;
        // the knight rosters: 90 good or neutral + 13 evil = 103, with 26 + 3
        // = 29 of quality
    if (dgcGoodKnightCount() != 90
            || dgcEvilKnightCount() != 13
            || dgcKnightCount() != 103
            || dgcGoodQualityCount() != 26
            || dgcEvilQualityCount() != 3
            || dgcQualityKnightCount() != 29
            || dgcGoodKnightCount() + dgcEvilKnightCount() != dgcKnightCount()
        )
            ++bad;
        // the print walk spans pp. 17-21 (the folio offset PRINT = PDF - 1)
    if (dgcPrintStart() != 17
            || dgcPrintEnd() != 21
            || dgcRosPage(0) != 17
            || dgcRosPage(2) != 18
            || dgcRosPage(10) != 20
            || dgcRosPage(14) != 21
        )
            ++bad;
        // the roster ordinals run 0-14 in print order (the renown template
        // first, Tristram last)
    if (dgcRosOrd(0) != 0
            || dgcRosOrd(2) != 2
            || dgcRosOrd(14) != 14
        )
            ++bad;
        // the template doctrine: renown 60 hp floor and 8-10 fighter; quality
        // 70 hp floor and 10-13 fighter
    if (dgcRenownHPFloor() != 60
            || dgcRenownFighterLo() != 8
            || dgcRenownFighterHi() != 10
            || dgcQualityHPFloor() != 70
            || dgcQualityFighterLo() != 10
            || dgcQualityFighterHi() != 13
        )
            ++bad;
        // the template specials: renown never below 10 averaging 15; quality
        // never below 13 averaging 16
    if (dgcRenownSpecialFloor() != 10
            || dgcRenownSpecialAvg() != 15
            || dgcQualitySpecialFloor() != 13
            || dgcQualitySpecialAvg() != 16
        )
            ++bad;
        // the template retinues: 60 percent with 1-4 squires and 1-10
        // men-at-arms, 75 percent mercy, the 5 percent better squire
    if (dgcQualitySquirePct() != 60
            || dgcQualitySquireLo() != 1
            || dgcQualitySquireHi() != 4
            || dgcQualityMenAtArmsLo() != 1
            || dgcQualityMenAtArmsHi() != 10
            || dgcQualityMercyPct() != 75
            || dgcSquireBetterPct() != 5
        )
            ++bad;
        // the variable-template alignments: 80 percent lawful (renown) and 85
        // percent lawful (quality)
    if (dgcRenownLawfulPct() != 80
            || dgcQualityLawfulPct() != 85
            || dgcRosLawfulPct(0) != 80
            || dgcRosLawfulPct(1) != 85
        )
            ++bad;
        // the two templates read the printed 3/2 attacks (like the R850
        // Qagwaaz/Stoneribs rows)
    if (dgcCbtAtN(0) != 3
            || dgcCbtAtD(0) != 2
            || dgcCbtAtN(1) != 3
            || dgcCbtAtD(1) != 2
        )
            ++bad;
        // the Arthur walk: AC 0, 123 hit points, Excalibur the +5 lawful good
        // sword of sharpness, 14th level paladin
    if (dgcCbtAC(2) != 0
            || dgcCbtHP(2) != 123
            || dgcExcaliburPlus() != 5
            || dgcClsFighterLo(2) != 14
            || dgcRosPaladin(2) != 1
            || dgcClsBard(2) != 5
        )
            ++bad;
        // the Arthur abilities S:18(52)(+2,+3) I:18 W:19 D:16 C:18 CH:18
    if (dgcAbiStr(2) != 18
            || dgcAbiStrHit(2) != 2
            || dgcAbiStrDmg(2) != 3
            || dgcAbiInt(2) != 18
            || dgcAbiWis(2) != 19
            || dgcAbiDex(2) != 16
            || dgcAbiCha(2) != 18
        )
            ++bad;
        // the Bernlad walk: the green-armor See below (AC 99), 99 hit points,
        // the +3 axe, 7 feet tall
    if (dgcCbtAC(3) != 99
            || dgcCbtHP(3) != 99
            || dgcBernladAxePlus() != 3
            || dgcCbtSizeIn(3) != 84
        )
            ++bad;
        // the Galahad walk: AC -4, 120 hit points, 3 attacks, the 20th level
        // paladin, 7 feet tall
    if (dgcCbtAC(4) != -4
            || dgcCbtHP(4) != 120
            || dgcCbtAtN(4) != 3
            || dgcCbtAtD(4) != 0
            || dgcClsFighterLo(4) != 20
            || dgcRosPaladin(4) != 1
            || dgcCbtSizeIn(4) != 84
        )
            ++bad;
        // the Gareth walk: AC -2, 105 hit points, 17th level fighter, 6 feet
        // tall
    if (dgcCbtAC(5) != -2
            || dgcCbtHP(5) != 105
            || dgcClsFighterLo(5) != 17
            || dgcCbtSizeIn(5) != 72
        )
            ++bad;
        // the Garlon adjudications (the IA voice against the Termux fold): 80
        // hit points, 1 attack, AC 1 effectively -3, chaotic evil
    if (dgcCbtHP(6) != 80
            || dgcCbtAtN(6) != 1
            || dgcCbtAC(6) != 1
            || dgcGarlonEffectiveAC() != -3
            || dgcRosAlign(6) != 7
            || dgcClsThief(6) != 3
        )
            ++bad;
        // the flagged eyeball cell: Gawaine 112 hit points in the
        // second-print extract against the 172 of the archive.org 1st print
    if (dgcCbtHP(7) != 112
        )
            ++bad;
        // the Gawaine sun-strength walk: 19, 20, 21 from 9 till 12, then
        // normal
    if (dgcGawaineStrEarly() != 19
            || dgcGawaineStrMid() != 20
            || dgcGawaineStrLate() != 21
            || dgcGawaineSunStart() != 9
            || dgcGawaineSunEnd() != 12
            || dgcRosStrVaries(7) != 1
        )
            ++bad;
        // the Gawaine equipment: Galatine the +2 sword, the
        // at-normal-strength armor move
    if (dgcGalatinePlus() != 2
            || dgcCbtMoveAlt(7) != 6
            || dgcAbiStrHit(7) != 1
            || dgcAbiStrDmg(7) != 3
        )
            ++bad;
        // the Lamorak and Launcelot walks: 99 and 141 hit points,
        // S:18(00)(+3,+6) and S:19(+3,+7)
    if (dgcCbtHP(8) != 99
            || dgcCbtHP(9) != 141
            || dgcAbiStrDmg(8) != 6
            || dgcAbiStr(9) != 19
            || dgcRosPaladin(9) != 1
        )
            ++bad;
        // the Merlin walk: AC 2 (bracers), 175 hit points, 1-10 damage, druid
        // 14 over magic-user 15 and illusionist 10, the 300 psionic points, B
        // C E over All
    if (dgcCbtAC(10) != 2
            || dgcCbtHP(10) != 175
            || dgcMerlinDmgLo() != 1
            || dgcMerlinDmgHi() != 10
            || dgcClsDruid(10) != 14
            || dgcClsMagUser(10) != 15
            || dgcClsIllus(10) != 10
            || dgcMerlinPsi() != 300
            || dgcAbiPsi(10) != 300
            || dgcRosPsiModes(10) != 1
        )
            ++bad;
        // the flagged eyeball cell: Merlin 1 attack (the IA 17 is a djvu
        // artifact) and the 1-point regeneration
    if (dgcCbtAtN(10) != 1
            || dgcCbtAtD(10) != 0
            || dgcMerlinRegen() != 1
        )
            ++bad;
        // the Morgan walk: AC 4, 39 hit points, 1-4 damage, the +3 ring,
        // magic-user/illusionist 12th in each, 5 feet 4 inches
    if (dgcCbtAC(11) != 4
            || dgcCbtHP(11) != 39
            || dgcMorganDmgLo() != 1
            || dgcMorganDmgHi() != 4
            || dgcMorganRingPlus() != 3
            || dgcClsMagUser(11) != 12
            || dgcClsIllus(11) != 12
            || dgcCbtSizeIn(11) != 64
            || dgcRosDmgFixed(11) != 1
        )
            ++bad;
        // the Palomides walk: AC 2, 93 hit points, the 12 over 9 chain-armor
        // move, 16th level fighter with monk/bard 3rd in each, 5 and a half
        // feet (66 inches)
    if (dgcCbtAC(12) != 2
            || dgcCbtHP(12) != 93
            || dgcCbtMove(12) != 12
            || dgcCbtMoveAlt(12) != 9
            || dgcClsFighterLo(12) != 16
            || dgcClsMonk(12) != 3
            || dgcClsBard(12) != 3
            || dgcCbtSizeIn(12) != 66
        )
            ++bad;
        // the Pellinore walk: 65 hit points, 1 attack, lawful neutral, the 6
        // feet 4 inches single-voice size
    if (dgcCbtHP(13) != 65
            || dgcCbtAtN(13) != 1
            || dgcRosAlign(13) != 8
            || dgcCbtSizeIn(13) != 76
        )
            ++bad;
        // the Tristram walk: AC -3, 120 hit points, 17th level fighter,
        // S:18(99)(+2,+5), Dexterity 19
    if (dgcCbtAC(14) != -3
            || dgcCbtHP(14) != 120
            || dgcClsFighterLo(14) != 17
            || dgcAbiStrDmg(14) != 5
            || dgcAbiDex(14) != 19
        )
            ++bad;
        printf("R851 Arthurian mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
