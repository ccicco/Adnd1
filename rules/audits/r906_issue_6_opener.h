    // ---- R906 issue-6 opener audit ----
    // THE DRAGON ISSUE-6 OPENER ROUND - four adjudicated chains. The Sea
    // Trade system (folio 6, Spencer): the cargo and fee pins, the coastal
    // doctrines and the sixteen-band profit/loss grid with the ship-lost
    // sentinel. The psionic option (folio 25, Miller): the percentile gates,
    // the thirty-seven abilities and the learning ladders. The morale system
    // (folios 26-27, Hayes and Gilbert): the modifier ladders, the recheck
    // adjustments and the eleven-chart outcome grid with B/H/S/F coded 0-3.
    // The Death Angel (folio 29, Sullivan): the stat pin, the mission
    // doctrines and the DMG p.85 XP conversion.
    {
        using namespace rules;
        int bad = 0;
    if (dsoSeaCargoSmallGp() != 10000
            || dsoSeaCargoLargeGp() != 50000
            || dsoSeaPilotFeeSmall() != 500
            || dsoSeaPilotFeeLarge() != 2500
            || dsoSeaImportTaxPct() != 5
            || dsoSeaPortsOnCoast() != 9
            || dsoSeaRouteMiles() != 2500
            || dsoSeaCoastalMilesMax() != 50
            || dsoSeaDelayWeeksMin() != 1
            || dsoSeaDelayWeeksMax() != 4
            || dsoSeaLossNoticeWeeksMin() != 3
            || dsoSeaLossNoticeWeeksMax() != 8
            || dsoSeaProfitLossCount() != 16
            || dsoPsiHumanRollMin() != 91
            || dsoPsiHalfHumanRollMin() != 95
            || dsoPsiAbilitiesCount() != 37
            || dsoPsiBasicWeeksPerLevel() != 1
            || dsoPsiSuperiorWeeksTenths() != 15
            || dsoPsiAttackDefenseWeeks() != 9
            || dsoMorBrave3() != -4
            || dsoMorBrave4() != -3
            || dsoMorBrave56() != -2
            || dsoMorBrave78() != -1
            || dsoMorBrave912() != 0
            || dsoMorBrave1314() != 1
            || dsoMorBrave1516() != 2
            || dsoMorBrave17() != 3
            || dsoMorBrave18() != 4
            || dsoMorBrave19() != 5
            || dsoMorLvl34() != 1
            || dsoMorLvl56() != 2
            || dsoMorLvl78() != 3
            || dsoMorAdjComradeBreaks() != -1
            || dsoMorAdjMuClericBreaks() != -2
            || dsoMorAdjLeaderBreaks() != -4
            || dsoMorAdjEnemyLeader() != 4
            || dsoMorAdjEnemyMuCleric() != 2
            || dsoMorAdjEnemyFighter() != 1
            || dsoMorSurpriseMod() != -1
            || dsoMorBerserkPctPerRound() != 10
            || dsoMorOutcomeCount() != 11
            || dsoDaHd() != 7
            || dsoDaHdSides() != 8
            || dsoDaAc() != 4
            || dsoDaMove() != 12
            || dsoDaMoveFly() != 20
            || dsoDaNumAppearing() != 1
            || dsoDaScytheMin() != 1
            || dsoDaScytheMax() != 12
            || dsoDaSavePenalty() != 3
            || dsoDaConLostPerSave() != 1
            || dsoDaRiseDays() != 3
            || dsoDaMagicResistPct() != 95
            || dsoDaRaiseConAsIf() != 3
            || dsoDaKillsIrreversible() != 3
            || dsoDaMasterPriestLevelMin() != 20
            || dsoDaAvgHp() != 31
            || dsoDaXp() != 850
            || dsoDaXpPerHp() != 8
            || dsoDaXpValue() != 1098
            || !dsoSeaCoastalTradeOnly()
            || !dsoSeaNoForcedLossSale()
            || !dsoSeaDepartedPortCountsBypassed()
            || !dsoSeaWildernessRulesWhenAboard()
            || !dsoPsiAnyClass()
            || !dsoPsiNoAcquisitionPenalty()
            || !dsoPsiLearnByEspAndProjection()
            || !dsoPsiSpontaneousAtNextLevel()
            || !dsoPsiMagicalAcquisition()
            || !dsoPsiLowIntelligenceLimits()
            || !dsoMorCharismaSameTable()
            || !dsoMorLoyaltySameTable()
            || !dsoMorBreakDexDamageRoll()
            || !dsoMorHesitateRecheckNextRound()
            || !dsoMorRecheckOnChartChange()
            || !dsoDaNeutral()
            || !dsoDaVanishesWhenSlain()
            || !dsoDaTeleportNoFail()
            || !dsoDaNoTeleportFromMelee()
            || !dsoDaTurnedLikeVampire()
            || !dsoDaReturnsNextDay()
            || !dsoDaVictimsRiseAsAngels()
            || !dsoDaRaiseDeadFullyOnly()
            || !dsoDaWishRaisesAutomatically()
            || !dsoDaOnlyAttacksVictim()
            || !dsoDaRemoveCurseGrantsPeace()
            || !dsoDaOnePerMaster()
            || !dsoDaTelepathicAllLanguages()
        )
            ++bad;
        // the Spencer profit/loss grid - percentages of cargo value by
        // percentile band and ports bypassed 0 through 6+; the X cells (ship
        // lost, owner notified 3-8 weeks later) ride as the 0 sentinel (folio
        // 6)
        int CStP[16][7] = {
            {85,80,70,60,50,40,30},
            {90,85,80,70,60,50,40},
            {95,90,85,80,70,60,50},
            {100,95,90,85,80,10,60},
            {105,100,95,90,90,85,80},
            {105,105,110,115,115,120,120},
            {110,110,115,120,125,140,150},
            {110,115,120,130,135,160,200},
            {110,120,130,140,150,200,300},
            {115,125,150,160,200,300,500},
            {120,130,160,180,250,400,0},
            {125,135,180,200,350,0,0},
            {130,140,200,300,0,0,0},
            {140,150,250,0,0,0,0},
            {150,200,0,0,0,0,0},
            {0,0,0,0,0,0,0},
            };
        int nStP[7] = {0,0,0,0,0,0,0};
        int eStP[7] = {1,1,2,3,4,5,6};
        for (int b = 0;
             b < dsoSeaProfitLossCount();
             ++b) {
            int vals[7];
            vals[0] = dsoSeaSaleCol0(b);
            vals[1] = dsoSeaSaleCol1(b);
            vals[2] = dsoSeaSaleCol2(b);
            vals[3] = dsoSeaSaleCol3(b);
            vals[4] = dsoSeaSaleCol4(b);
            vals[5] = dsoSeaSaleCol5(b);
            vals[6] = dsoSeaSaleCol6(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CStP[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nStP[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nStP[c] != eStP[c])
                ++bad;
        // the Hayes-Gilbert morale grid - chart number -5 or less to +5 or
        // more against the ten-sided die; the B/H/S/F letters ride coded
        // 0/1/2/3 (folios 26-27)
        int CStM[11][10] = {
            {0,0,0,0,0,0,0,1,1,1},
            {0,0,0,0,0,0,1,1,1,1},
            {0,0,0,0,0,1,1,1,1,2},
            {0,0,0,0,0,1,1,2,2,2},
            {0,0,0,1,1,1,2,2,2,2},
            {0,0,1,1,2,2,2,2,2,3},
            {0,1,2,2,2,2,2,2,3,3},
            {1,2,2,2,2,2,2,3,3,3},
            {2,2,2,2,2,3,3,3,3,3},
            {2,2,2,2,3,3,3,3,3,3},
            {2,2,3,3,3,3,3,3,3,3},
            };
        for (int b = 0;
             b < dsoMorOutcomeCount();
             ++b) {
            int vals[10];
            vals[0] = dsoMorCol1(b);
            vals[1] = dsoMorCol2(b);
            vals[2] = dsoMorCol3(b);
            vals[3] = dsoMorCol4(b);
            vals[4] = dsoMorCol5(b);
            vals[5] = dsoMorCol6(b);
            vals[6] = dsoMorCol7(b);
            vals[7] = dsoMorCol8(b);
            vals[8] = dsoMorCol9(b);
            vals[9] = dsoMorCol10(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CStM[b][c])
                    ++bad;
            }
        }
        // the cargo capacities and the pilot fees (folio 6)
    if (dsoSeaCargoSmallGp() != 10000
            || dsoSeaCargoLargeGp() != 50000
            || dsoSeaPilotFeeSmall() != 500
            || dsoSeaPilotFeeLarge() != 2500
        )
            ++bad;
        // the 5 percent import tax, the nine ports, the 2,500-mile route and
        // the fifty-mile coastal limit (folio 6)
    if (dsoSeaImportTaxPct() != 5
            || dsoSeaPortsOnCoast() != 9
            || dsoSeaRouteMiles() != 2500
            || dsoSeaCoastalMilesMax() != 50
        )
            ++bad;
        // the 1-4 week port delay and the 3-8 week loss notice (folio 6)
    if (dsoSeaDelayWeeksMin() != 1
            || dsoSeaDelayWeeksMax() != 4
            || dsoSeaLossNoticeWeeksMin() != 3
            || dsoSeaLossNoticeWeeksMax() != 8
        )
            ++bad;
        // the sea-trade doctrines - coastal only, no forced loss sale, a
        // departed port counts bypassed, the Wilderness rules when aboard
        // (folio 6)
    if (dsoSeaCoastalTradeOnly() != 1
            || dsoSeaNoForcedLossSale() != 1
            || dsoSeaDepartedPortCountsBypassed() != 1
            || dsoSeaWildernessRulesWhenAboard() != 1
        )
            ++bad;
        // the print's worked example - 10,000 G.P. cargo, dice 62, sale
        // 11,500 G.P. - matches the 61-65 row at ZERO ports bypassed (115),
        // while the one-bypassed cell prints 125; the grid is the pin, the
        // worked example's discrepancy noted (folio 6)
    if (dsoSeaSaleCol1(9) != 125
            || dsoSeaSaleCol0(9) != 115
        )
            ++bad;
        // the psionic gates - humans 91, half-humans 95, thirty-seven
        // abilities (folio 25)
    if (dsoPsiHumanRollMin() != 91
            || dsoPsiHalfHumanRollMin() != 95
            || dsoPsiAbilitiesCount() != 37
        )
            ++bad;
        // the learning ladder - one week per level basic, the garbled 1 1/2
        // read as 15 tenths superior, nine weeks per attack or defense mode
        // (folio 25)
    if (dsoPsiBasicWeeksPerLevel() != 1
            || dsoPsiSuperiorWeeksTenths() != 15
            || dsoPsiAttackDefenseWeeks() != 9
        )
            ++bad;
        // the psionic doctrines - any class, no acquisition penalty, the
        // ESP/Projection learning gate, spontaneous development, magical
        // acquisition, low intelligence limits (folio 25)
    if (dsoPsiAnyClass() != 1
            || dsoPsiNoAcquisitionPenalty() != 1
            || dsoPsiLearnByEspAndProjection() != 1
            || dsoPsiSpontaneousAtNextLevel() != 1
            || dsoPsiMagicalAcquisition() != 1
            || dsoPsiLowIntelligenceLimits() != 1
        )
            ++bad;
        // the bravery modifier ladder on 3d6, 3 through 19 or more (folio 27)
    if (dsoMorBrave3() != -4
            || dsoMorBrave4() != -3
            || dsoMorBrave56() != -2
            || dsoMorBrave78() != -1
            || dsoMorBrave912() != 0
            || dsoMorBrave1314() != 1
            || dsoMorBrave1516() != 2
            || dsoMorBrave17() != 3
            || dsoMorBrave18() != 4
            || dsoMorBrave19() != 5
        )
            ++bad;
        // the level additions to the chart number - +1 at 3-4, +2 at 5-6, +3
        // at 7-8 (folio 27)
    if (dsoMorLvl34() != 1
            || dsoMorLvl56() != 2
            || dsoMorLvl78() != 3
        )
            ++bad;
        // the post-melee recheck adjustments - own losses subtract, enemy
        // losses add (folio 27)
    if (dsoMorAdjComradeBreaks() != -1
            || dsoMorAdjMuClericBreaks() != -2
            || dsoMorAdjLeaderBreaks() != -4
            || dsoMorAdjEnemyLeader() != 4
            || dsoMorAdjEnemyMuCleric() != 2
            || dsoMorAdjEnemyFighter() != 1
        )
            ++bad;
        // the surprised-side -1 and the F-fights 10 percent berserk per round
        // (folio 27)
    if (dsoMorSurpriseMod() != -1
            || dsoMorBerserkPctPerRound() != 10
        )
            ++bad;
        // the morale doctrines - charisma and loyalty on the same table, the
        // Dex roll on a break, the hesitate recheck, the chart-change recheck
        // (folios 26-27)
    if (dsoMorCharismaSameTable() != 1
            || dsoMorLoyaltySameTable() != 1
            || dsoMorBreakDexDamageRoll() != 1
            || dsoMorHesitateRecheckNextRound() != 1
            || dsoMorRecheckOnChartChange() != 1
        )
            ++bad;
        // the Death Angel stat line - 7 eight-sided dice, AC 4, move 12/20,
        // number appearing 1 (folio 29)
    if (dsoDaHd() != 7
            || dsoDaHdSides() != 8
            || dsoDaAc() != 4
            || dsoDaMove() != 12
            || dsoDaMoveFly() != 20
            || dsoDaNumAppearing() != 1
        )
            ++bad;
        // the Death Scythe - 1-12 with a save vs. Death at -3, one
        // constitution point lost on a successful save (folio 29)
    if (dsoDaScytheMin() != 1
            || dsoDaScytheMax() != 12
            || dsoDaSavePenalty() != 3
            || dsoDaConLostPerSave() != 1
        )
            ++bad;
        // the Death Angel numerics - the three-day rise, the 95 percent
        // resistance, the raise-as-con-3, the third-kill irreversibility, the
        // 20th-level priest masters (folio 29)
    if (dsoDaRiseDays() != 3
            || dsoDaMagicResistPct() != 95
            || dsoDaRaiseConAsIf() != 3
            || dsoDaKillsIrreversible() != 3
            || dsoDaMasterPriestLevelMin() != 20
        )
            ++bad;
        // the Death Angel XP conversion - the DMG p.85 additive formula: 225
        // base + 2 x 175 + 275, plus 8 per hit point at the floored 31
        // average; the conversion noted, never silent (folio 29)
    if (dsoDaAvgHp() != 31
            || dsoDaXp() != 850
            || dsoDaXpPerHp() != 8
            || dsoDaXpValue() != 1098
        )
            ++bad;
        // the Death Angel doctrines - Neutral, vanishes when slain, the
        // no-fail teleport that cannot leave melee, turned like a Vampire yet
        // returns next day (folio 29)
    if (dsoDaNeutral() != 1
            || dsoDaVanishesWhenSlain() != 1
            || dsoDaTeleportNoFail() != 1
            || dsoDaNoTeleportFromMelee() != 1
            || dsoDaTurnedLikeVampire() != 1
            || dsoDaReturnsNextDay() != 1
        )
            ++bad;
        // the Death Angel mission doctrines - the victim's rise, the Raise
        // Dead Fully limit, the automatic Wish, the single victim, the
        // remove-curse peace, one per master, telepathic speech (folio 29)
    if (dsoDaVictimsRiseAsAngels() != 1
            || dsoDaRaiseDeadFullyOnly() != 1
            || dsoDaWishRaisesAutomatically() != 1
            || dsoDaOnlyAttacksVictim() != 1
            || dsoDaRemoveCurseGrantsPeace() != 1
            || dsoDaOnePerMaster() != 1
            || dsoDaTelepathicAllLanguages() != 1
        )
            ++bad;
        // the profit/loss grid's 01-05 row runs 85 down to 30 across the
        // seven ports-bypassed columns (folio 6)
    if (dsoSeaSaleCol0(0) != 85
            || dsoSeaSaleCol6(0) != 30
            || dsoSeaProfitLossCount() != 16
        )
            ++bad;
        // the 61-65 row - 115 percent at zero bypassed, 500 at six-plus
        // (folio 6)
    if (dsoSeaSaleCol6(9) != 500
            || dsoSeaSaleCol0(9) != 115
        )
            ++bad;
        // the X band - ship lost, owner notified 3-8 weeks later: the
        // sentinel 0 cells count 1/1/2/3/4/5/6 by column (folio 6)
    if (dsoSeaSaleCol0(15) != 0
            || dsoSeaSaleCol3(15) != 0
            || dsoSeaSaleCol6(15) != 0
            || dsoSeaSaleCol6(10) != 0
            || dsoSeaSaleCol5(11) != 0
        )
            ++bad;
        // the folio's garbled cell - the 16-20 row's five-bypassed column
        // prints 10; it rides AS SCANNED, the arithmetic of the neighbours
        // reads about 70 (folio 6)
    if (dsoSeaSaleCol5(3) != 10
        )
            ++bad;
        // the morale grid ends - chart -5 opens on B and tops at H; chart 0
        // opens on B and tops at F (folios 26-27)
    if (dsoMorCol1(0) != 0
            || dsoMorCol10(0) != 1
            || dsoMorCol1(5) != 0
            || dsoMorCol10(5) != 3
        )
            ++bad;
        // the morale grid's upper charts - +5 opens on S and tops at F; +3
        // crosses from S to F at the sixth die (folios 26-27)
    if (dsoMorCol1(10) != 2
            || dsoMorCol10(10) != 3
            || dsoMorCol3(8) != 2
            || dsoMorCol6(8) != 3
            || dsoMorOutcomeCount() != 11
        )
            ++bad;
        printf("R906 issue-6 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
