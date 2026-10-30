    // ---- R940 issue-20 opener part one audit ----
    // THE DRAGON ISSUE-20 OPENER PART ONE - the three-chain round of the
    // issue-20 three-round shape. Three chains pinned from the
    // Curtiss-provided Dm20.pdf scan: the Arkenberg mythos of Polynesia - the
    // seventeen-god GDH pantheon, the ten hero six-stat lines, the two
    // statted monsters and the two artifacts; the Pehr witch class - the
    // eighteen-title ladder with the eight spell lists, the candle magic and
    // the hit-point transfer doctrine; the Rihn demonology - the
    // name-research levels, the level-achieved percentile grid and the
    // failure bands. Part two (the death stats and the demonic possession
    // chains) rides R941, the closing flip R942.
    {
        using namespace rules;
        int bad = 0;
    if (t20MythosStatlines() != 29
            || t20MythosGods() != 17
            || t20MythosHeroes() != 10
            || t20MythosMonsters() != 2
            || t20HeroCount() != 10
            || t20MythosArtifacts() != 2
            || t20GreatHelvePlus() != 5
            || t20GreatHelveMin() != 10
            || t20GreatHelveMax() != 40
            || t20MakaleiPowers() != 6
            || t20MythosNormalManAc() != 10
            || t20WitchTitles() != 18
            || t20WitchSpellLevels() != 8
            || t20WitchIntMin() != 13
            || t20WitchWisMin() != 13
            || t20WitchChaMin() != 9
            || t20WitchSpellTotalAll() != 76
            || t20WitchSpellNewAll() != 44
            || t20CandleColors() != 6
            || t20CandlesPerMonth() != 1
            || t20CandleDaysPerTurn() != 3
            || t20CandleBurnTurns() != 10
            || t20CandleBlackCurses() != 6
            || t20VoiceMaxWords() != 7
            || t20VoiceReuseTurns() != 3
            || t20TransferCurseHp() != 5
            || t20TransferTo12() != 5
            || t20TransferTo13() != 7
            || t20TransferTo14() != 8
            || t20TransferTo15() != 10
            || t20TransferTo16() != 10
            || t20TransferTo17() != 20
            || t20TransferTo18() != 25
            || t20EnchantHpPer1000Gp() != 1
            || t20FamiliarMaxHd() != 1
            || t20FamiliarDeathMin() != 3
            || t20FamiliarDeathMax() != 24
            || t20DemonNameRows() != 9
            || t20DemonAchievedRows() != 7
            || t20DemonFailureRows() != 6
            || t20DemonNameCycleYears() != 70
            || t20UnprotectedSnatchPct() != 50
            || t20DemonCostMin() != 1
            || t20DemonCostMax() != 4000
            || t20AssistFifth() != 1
            || t20AssistSixth() != 2
            || t20AssistSeventh() != 3
            || t20AssistEighth() != 4
            || t20AssistNinth() != 4
            || t20OperatorLevelBasis() != 20
            || t20FailPerLevelBelow() != 5
            || t20FailPerAssistant() != 5
            || t20ExorcismLowPct() != 50
            || t20ExorcismMidPct() != 25
            || t20ExorcismPrincePct() != 10
            || t20ExorcismNameBonus() != 40
            || t20PitFiendServiceYears() != 100000
            || !t20MythosGdhFormat()
            || !t20HeroesRaisedByGrandparents()
            || !t20MauiEightHeads()
            || !t20KampuaMovePrintCatch()
            || !t20WitchNeutral()
            || !t20WitchFemaleDefault()
            || !t20WitchMuHitDice()
            || !t20WitchMuSaves()
            || !t20WitchNatureKinToDruids()
            || !t20DruidScrollsNoFail()
            || !t20MagicScrollBackfire()
            || !t20BagOfHoldingUnique()
            || !t20EnchantOnlyItemRoute()
            || !t20DemonetteCellPrintCatch()
            || !t20LovePotionPrintCatch()
            || !t20AssistCasterOnly()
            || !t20SacrificeRequiredForPact()
            || !t20PrincesHumanSacrificeOnly()
            || !t20DemonDevilNameSplit()
            || !t20SoulSoldOnce()
            || !t20DevilsObeyHierarchy()
            || !t20ExorcismNeedsNoName()
            || !t20FailureSnatchesOperator()
            || !t20TypeIOverlapPrintCatch()
            || !t20TypeVBothNeighborsPrintCatch()
            || !t20PactThreeGrants()
        )
            ++bad;
        // the Polynesian statline grid - twenty-nine entities down, the seven
        // statline fields across, armor class, move, hit points, the magic
        // level with the See Below and See Above -99 sentinel, the magic
        // class code, the fighter level and the psionic class; the print
        // catches pinned as scanned: the Rongo armor class 1 is the lone god
        // positive AC, the Kampua-a move prints 150 markless, the heroes
        // print the Normal Man armor class adjudicated to 10, and every
        // psionic line prints Nil pinned 0 the mythos of Polynesia (print 8-9
        // + 27, PDF 10-11 + 29)
        int CMy[29][7] = {
            {-3,20,300,40,1,30,0},
            {0,20,250,-99,3,12,0},
            {-2,20,250,-99,3,20,0},
            {-2,20,250,25,1,18,0},
            {-2,20,250,-99,3,20,0},
            {-2,20,240,-99,3,19,0},
            {1,20,225,12,2,10,0},
            {-1,20,220,30,1,15,0},
            {-1,20,220,30,1,15,0},
            {0,20,200,11,2,13,0},
            {-4,30,200,-99,3,25,0},
            {-1,20,200,-99,3,6,0},
            {0,20,170,-99,3,14,0},
            {-2,150,150,-99,3,10,0},
            {-2,20,140,20,1,5,0},
            {-4,30,100,0,0,8,0},
            {-3,25,100,0,0,7,0},
            {10,12,90,-99,3,12,0},
            {10,12,80,-99,3,10,0},
            {10,12,90,-99,3,11,0},
            {10,12,60,-99,3,7,0},
            {10,12,80,22,1,10,0},
            {10,12,90,-99,3,11,0},
            {10,12,140,18,1,15,0},
            {10,12,110,0,0,12,0},
            {10,12,56,0,0,7,0},
            {10,12,110,0,0,12,0},
            {-1,22,220,-99,3,17,0},
            {4,15,40,-99,3,1,0},
            };
        int nMy[7] = {0,0,0,0,0,0,0};
        int eMy[7] = {0,0,0,15,0,0,0};
        for (int b = 0;
             b < t20MythosStatlines();
             ++b) {
            int vals[7];
            vals[0] = t20MythAc(b);
            vals[1] = t20MythMove(b);
            vals[2] = t20MythHp(b);
            vals[3] = t20MythMagicLevel(b);
            vals[4] = t20MythMagicClass(b);
            vals[5] = t20MythFighterLevel(b);
            vals[6] = t20MythPsionicClass(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CMy[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nMy[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nMy[c] != eMy[c])
                ++bad;
        // the hero six-stat grid - ten heroes down, strength, the
        // exceptional-strength roll, intelligence, wisdom, constitution,
        // dexterity and charisma across; the print catches pinned as scanned:
        // the Maui strength prints 18(00) pinned roll 0, the Kariki strength
        // 15 carries no exception roll pinned -99, and the Maui charisma 3
        // the mythos of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
        int CHe[10][7] = {
            {18,76,16,16,18,18,16},
            {18,1,12,10,17,18,13},
            {18,60,10,11,18,18,14},
            {18,20,15,14,18,18,11},
            {18,25,18,9,17,16,13},
            {18,30,11,10,18,17,14},
            {18,0,18,18,18,17,3},
            {18,5,18,14,15,18,18},
            {15,-99,5,3,15,3,6},
            {18,55,9,5,12,14,10},
            };
        int nHe[7] = {0,0,0,0,0,0,0};
        int eHe[7] = {0,1,0,0,0,0,0};
        for (int b = 0;
             b < t20HeroCount();
             ++b) {
            int vals[7];
            vals[0] = t20HeroStr(b);
            vals[1] = t20HeroStrRoll(b);
            vals[2] = t20HeroInt(b);
            vals[3] = t20HeroWis(b);
            vals[4] = t20HeroCon(b);
            vals[5] = t20HeroDex(b);
            vals[6] = t20HeroCha(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CHe[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nHe[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nHe[c] != eHe[c])
                ++bad;
        // the witch class ladder - eighteen titles down, the experience
        // points and the eight spell-count columns across, the Medium 0
        // through the Demonette 1,500,000; the unprinted cells pinned 0 and
        // the Demonette 3 1 run-together print catch pinned as scanned the
        // witch class (print 11-12 + 19, PDF 13-14 + 21)
        int CWl[18][9] = {
            {0,1,0,0,0,0,0,0,0},
            {3000,2,0,0,0,0,0,0,0},
            {6000,2,1,0,0,0,0,0,0},
            {12000,2,2,0,0,0,0,0,0},
            {25000,3,2,0,0,0,0,0,0},
            {55000,3,3,1,0,0,0,0,0},
            {80000,3,3,2,0,0,0,0,0},
            {120000,3,3,3,0,0,0,0,0},
            {200000,4,4,3,1,0,0,0,0},
            {300000,4,4,4,2,0,0,0,0},
            {400000,4,4,4,4,0,0,0,0},
            {525000,4,4,4,4,1,0,0,0},
            {650000,5,5,4,4,2,0,0,0},
            {800000,5,5,5,4,3,1,0,0},
            {900000,5,5,5,5,4,2,0,0},
            {1000000,6,5,5,5,5,2,0,0},
            {1250000,6,6,6,5,5,3,0,0},
            {1500000,6,6,6,6,6,5,3,1},
            };
        for (int b = 0;
             b < t20WitchTitles();
             ++b) {
            int vals[9];
            vals[0] = t20WitchXp(b);
            vals[1] = t20WitchSp1(b);
            vals[2] = t20WitchSp2(b);
            vals[3] = t20WitchSp3(b);
            vals[4] = t20WitchSp4(b);
            vals[5] = t20WitchSp5(b);
            vals[6] = t20WitchSp6(b);
            vals[7] = t20WitchSp7(b);
            vals[8] = t20WitchSp8(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CWl[b][c])
                    ++bad;
            }
        }
        // the witch spell-list census - the eight spell levels down, the
        // printed spell count and the starred new-spell count across: 10 and
        // 6, 9 and 3, 8 and 7, 11 and 6, 10 and 5, 9 and 3, 10 and 6, 9 and 8
        // the witch class (print 11-12 + 19, PDF 13-14 + 21)
        int CWs[8][2] = {
            {10,6},
            {9,3},
            {8,7},
            {11,6},
            {10,5},
            {9,3},
            {10,6},
            {9,8},
            };
        for (int b = 0;
             b < t20WitchSpellLevels();
             ++b) {
            int vals[2];
            vals[0] = t20WitchListTotal(b);
            vals[1] = t20WitchListNew(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CWs[b][c])
                    ++bad;
            }
        }
        // the name-of research grid - the nine entity rows down, the
        // equivalent spell level across: the demon prince and arch-devil
        // ninth, the type VI and pit fiend eighth, the type V ice devil and
        // succubus seventh, the type IV horned devil and night hag sixth, the
        // type III bone devil fifth, the type II barbed devil fourth, the
        // type I erinye and miscellaneous third the demonology grids (print
        // 13-15, PDF 15-17)
        int CDn[9][1] = {
            {9},
            {8},
            {7},
            {7},
            {6},
            {6},
            {5},
            {4},
            {3},
            };
        for (int b = 0;
             b < t20DemonNameRows();
             ++b) {
            int vals[1];
            vals[0] = t20DemonNameLevel(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CDn[b][c])
                    ++bad;
            }
        }
        // the level-achieved percentile grid - the seven attempted rows down,
        // the three band floors and ceilings across; the percentile 00
        // adjudicated to 100, the type I 85 double-assignment and the type V
        // both-neighbors-VI print catches pinned as scanned the demonology
        // grids (print 13-15, PDF 15-17)
        int CDa[7][6] = {
            {1,15,16,85,85,100},
            {1,20,21,80,81,100},
            {1,20,21,80,81,100},
            {1,30,31,85,86,100},
            {1,30,31,90,91,100},
            {1,40,41,95,96,100},
            {1,50,51,75,76,100},
            };
        for (int b = 0;
             b < t20DemonAchievedRows();
             ++b) {
            int vals[6];
            vals[0] = t20DemonBand1Min(b);
            vals[1] = t20DemonBand1Max(b);
            vals[2] = t20DemonBand2Min(b);
            vals[3] = t20DemonBand2Max(b);
            vals[4] = t20DemonBand3Min(b);
            vals[5] = t20DemonBand3Max(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CDa[b][c])
                    ++bad;
            }
        }
        // the failure grid - the six bands down, the floor, ceiling and
        // outcome code across: the 01-35 total fizzle, the lower demon
        // uncontrolled, the lower demon controlled by spell, the summoned
        // demon uncontrolled, one level higher uncontrolled, two levels
        // higher uncontrolled the demonology grids (print 13-15, PDF 15-17)
        int CDf[6][3] = {
            {1,35,1},
            {36,45,2},
            {46,55,3},
            {56,85,4},
            {86,95,5},
            {96,100,6},
            };
        for (int b = 0;
             b < t20DemonFailureRows();
             ++b) {
            int vals[3];
            vals[0] = t20FailBandMin(b);
            vals[1] = t20FailBandMax(b);
            vals[2] = t20FailOutcome(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CDf[b][c])
                    ++bad;
            }
        }
        // the mythos census - twenty-nine statlines, seventeen gods, ten
        // heroes, two statted monsters, two artifacts, the Normal Man armor
        // class conversion the mythos of Polynesia (print 8-9 + 27, PDF 10-11
        // + 29)
    if (t20MythosStatlines() != 29
            || t20MythosGods() != 17
            || t20MythosHeroes() != 10
            || t20MythosMonsters() != 2
            || t20HeroCount() != 10
            || t20MythosArtifacts() != 2
            || t20MythosNormalManAc() != 10
        )
            ++bad;
        // the mythos artifact and doctrine census - the plus 5 10-40 Great
        // Helve, the six Makalei powers, the GDH format, the grandparents,
        // the eight Maui heads and the Kampua-a move print catch the mythos
        // of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
    if (t20GreatHelvePlus() != 5
            || t20GreatHelveMin() != 10
            || t20GreatHelveMax() != 40
            || t20MakaleiPowers() != 6
            || t20MythosGdhFormat() != 1
            || t20HeroesRaisedByGrandparents() != 1
            || t20MauiEightHeads() != 1
            || t20KampuaMovePrintCatch() != 1
        )
            ++bad;
        // the witch census - eighteen titles, eight spell levels, the 13-13-9
        // requirements, the 76 spells and 44 starred the witch class (print
        // 11-12 + 19, PDF 13-14 + 21)
    if (t20WitchTitles() != 18
            || t20WitchSpellLevels() != 8
            || t20WitchIntMin() != 13
            || t20WitchWisMin() != 13
            || t20WitchChaMin() != 9
            || t20WitchSpellTotalAll() != 76
            || t20WitchSpellNewAll() != 44
        )
            ++bad;
        // the candle and Voice doctrine - six colors, one per month, 3 days
        // per turn, 10 turns, six black curses, the 7-word Voice and the
        // 3-turn reuse the witch class (print 11-12 + 19, PDF 13-14 + 21)
    if (t20CandleColors() != 6
            || t20CandlesPerMonth() != 1
            || t20CandleDaysPerTurn() != 3
            || t20CandleBurnTurns() != 10
            || t20CandleBlackCurses() != 6
            || t20VoiceMaxWords() != 7
            || t20VoiceReuseTurns() != 3
        )
            ++bad;
        // the transfer hit points ladder - the 5-point curse lift and the
        // 5-7-8-10-10-20-25 prime attribute price the witch class (print
        // 11-12 + 19, PDF 13-14 + 21)
    if (t20TransferCurseHp() != 5
            || t20TransferTo12() != 5
            || t20TransferTo13() != 7
            || t20TransferTo14() != 8
            || t20TransferTo15() != 10
            || t20TransferTo16() != 10
            || t20TransferTo17() != 20
            || t20TransferTo18() != 25
        )
            ++bad;
        // the enchant and familiar doctrine - 1 hit point per 1000 gold, the
        // sub-1-hit-die familiar and the 3-24 death band, the neutral
        // women-only MU-kin class shape the witch class (print 11-12 + 19,
        // PDF 13-14 + 21)
    if (t20EnchantHpPer1000Gp() != 1
            || t20FamiliarMaxHd() != 1
            || t20FamiliarDeathMin() != 3
            || t20FamiliarDeathMax() != 24
            || t20WitchNeutral() != 1
            || t20WitchFemaleDefault() != 1
            || t20WitchMuHitDice() != 1
            || t20WitchMuSaves() != 1
            || t20WitchNatureKinToDruids() != 1
        )
            ++bad;
        // the witch scroll and print-catch doctrine - the no-fail druid
        // scrolls, the 10 percent magic backfire, the unique bag, the
        // enchant-only route, the Demonette 3 1 cell and the 155 love potion
        // print catch the witch class (print 11-12 + 19, PDF 13-14 + 21)
    if (t20DruidScrollsNoFail() != 1
            || t20MagicScrollBackfire() != 1
            || t20BagOfHoldingUnique() != 1
            || t20EnchantOnlyItemRoute() != 1
            || t20DemonetteCellPrintCatch() != 1
            || t20LovePotionPrintCatch() != 1
        )
            ++bad;
        // the demonology census - nine name rows, seven achieved rows, six
        // failure bands, the seventy-year name cycle, the 50 percent snatch
        // and the 1-4000 gold ritual cost the demonology grids (print 13-15,
        // PDF 15-17)
    if (t20DemonNameRows() != 9
            || t20DemonAchievedRows() != 7
            || t20DemonFailureRows() != 6
            || t20DemonNameCycleYears() != 70
            || t20UnprotectedSnatchPct() != 50
            || t20DemonCostMin() != 1
            || t20DemonCostMax() != 4000
        )
            ++bad;
        // the assistant and failure doctrine - the 1-2-3-4-4 assistant
        // ladder, the 20th-level basis, 5 percent per level below and 5
        // percent per assistant the demonology grids (print 13-15, PDF 15-17)
    if (t20AssistFifth() != 1
            || t20AssistSixth() != 2
            || t20AssistSeventh() != 3
            || t20AssistEighth() != 4
            || t20AssistNinth() != 4
            || t20OperatorLevelBasis() != 20
            || t20FailPerLevelBelow() != 5
            || t20FailPerAssistant() != 5
        )
            ++bad;
        // the exorcism and sacrifice doctrine - the 50-25-10 exorcism ladder,
        // the 40 percent name bonus, the 100000-year pit fiend compromise,
        // the caster-only assistants and the human-only prince sacrifice the
        // demonology grids (print 13-15, PDF 15-17)
    if (t20ExorcismLowPct() != 50
            || t20ExorcismMidPct() != 25
            || t20ExorcismPrincePct() != 10
            || t20ExorcismNameBonus() != 40
            || t20PitFiendServiceYears() != 100000
            || t20AssistCasterOnly() != 1
            || t20SacrificeRequiredForPact() != 1
            || t20PrincesHumanSacrificeOnly() != 1
        )
            ++bad;
        // the pact doctrine - the demon-devil name split, the once-only soul,
        // the devil hierarchy, the nameless exorcism, the operator-snatch,
        // the type I 85 and type V both-VI print catches and the three pact
        // grants the demonology grids (print 13-15, PDF 15-17)
    if (t20DemonDevilNameSplit() != 1
            || t20SoulSoldOnce() != 1
            || t20DevilsObeyHierarchy() != 1
            || t20ExorcismNeedsNoName() != 1
            || t20FailureSnatchesOperator() != 1
            || t20TypeIOverlapPrintCatch() != 1
            || t20TypeVBothNeighborsPrintCatch() != 1
            || t20PactThreeGrants() != 1
        )
            ++bad;
        // the mythos grid corners - the Tangaroa -3/300/40 row, the Rongo
        // armor class 1 and Druid 12 print catch, the Kaulu 90 row, the Hina
        // Myrmidon 6 and the Haumea Swashbuckler 5 rank names the mythos of
        // Polynesia (print 8-9 + 27, PDF 10-11 + 29)
    if (t20MythAc(0) != -3
            || t20MythAc(6) != 1
            || t20MythHp(0) != 300
            || t20MythHp(17) != 90
            || t20MythMagicLevel(0) != 40
            || t20MythMagicLevel(6) != 12
            || t20MythFighterLevel(11) != 6
            || t20MythFighterLevel(14) != 5
        )
            ++bad;
        // the See Below and See Above set - the eight spell-list gods, five
        // See Above heroes and two monsters carry the -99 sentinel, the Tane
        // Wizard and Atea Nil rows never do, the Kampua-a 150 markless move
        // the mythos of Polynesia (print 8-9 + 27, PDF 10-11 + 29)
    if (t20MythMagicLevel(1) != -99
            || t20MythMagicLevel(2) != -99
            || t20MythMagicLevel(4) != -99
            || t20MythMagicLevel(5) != -99
            || t20MythMagicLevel(10) != -99
            || t20MythMagicLevel(12) != -99
            || t20MythMagicLevel(13) != -99
            || t20MythMagicLevel(17) != -99
            || t20MythMagicLevel(3) == -99
            || t20MythMagicLevel(15) == -99
            || t20MythMove(13) != 150
        )
            ++bad;
        // the hero six-stat corners - the Kaulu 18(76), the Maui 18(00)
        // pinned 0 and charisma 3, the Kariki 15 with the -99 no-roll
        // sentinel and the Tawhaki charisma 18 the mythos of Polynesia (print
        // 8-9 + 27, PDF 10-11 + 29)
    if (t20HeroStr(0) != 18
            || t20HeroStrRoll(0) != 76
            || t20HeroStrRoll(6) != 0
            || t20HeroStrRoll(8) != -99
            || t20HeroStr(8) != 15
            || t20HeroCha(6) != 3
            || t20HeroCha(7) != 18
        )
            ++bad;
        // the witch ladder corners - the Medium 0 and Demonette 1,500,000,
        // the 1-to-6 first level band, the Witch 1 fourth level, the Crystal
        // 3 sixth level and the Demonette 3 1 run-together cell the witch
        // class (print 11-12 + 19, PDF 13-14 + 21)
    if (t20WitchXp(0) != 0
            || t20WitchXp(17) != 1500000
            || t20WitchSp1(0) != 1
            || t20WitchSp1(17) != 6
            || t20WitchSp4(8) != 1
            || t20WitchSp8(17) != 1
            || t20WitchSp6(16) != 3
            || t20WitchSp7(17) != 3
        )
            ++bad;
        // the spell-list census corners - the ten-spell first, the
        // eleven-spell fourth, the seven-starred third and the eight-starred
        // of nine at eighth level the witch class (print 11-12 + 19, PDF
        // 13-14 + 21)
    if (t20WitchListTotal(0) != 10
            || t20WitchListTotal(3) != 11
            || t20WitchListNew(2) != 7
            || t20WitchListNew(7) != 8
            || t20WitchListTotal(5) != 9
        )
            ++bad;
        // the demonology grid corners - the ninth-level prince and
        // third-level type I research, the type I 85 double-assignment print
        // catch and the 00-to-100 adjudication the demonology grids (print
        // 13-15, PDF 15-17)
    if (t20DemonNameLevel(0) != 9
            || t20DemonNameLevel(3) != 7
            || t20DemonNameLevel(8) != 3
            || t20DemonBand2Max(0) != 85
            || t20DemonBand3Min(0) != 85
            || t20DemonBand1Min(0) != 1
            || t20DemonBand3Max(6) != 100
        )
            ++bad;
        // the failure grid corners - the 01-35 fizzle, the 46-55 controlled
        // band, the 96-100 two-higher band and the outcome codes the
        // demonology grids (print 13-15, PDF 15-17)
    if (t20FailBandMin(0) != 1
            || t20FailBandMax(0) != 35
            || t20FailOutcome(0) != 1
            || t20FailOutcome(2) != 3
            || t20FailOutcome(5) != 6
            || t20FailBandMin(5) != 96
            || t20FailBandMax(5) != 100
        )
            ++bad;
        printf("R940 issue-20 opener part one audit: bad %d\n", bad);
        if (bad) return 1;
    }
