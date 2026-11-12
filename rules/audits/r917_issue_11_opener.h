    // ---- R917 issue-11 opener audit ----
    // THE DRAGON ISSUE-11 OPENER ROUND - two adjudicated chains. The Kuntz
    // brawling article (folio 7): the first-move dexterity gap, the averaged
    // grapple score rounded down, the eleven-row 2d6 grappling grid G1-G4/NG
    // with the G2 break minimum, the eleven-row punch damage grid -1 light
    // through -4 solid with the missed-punch 0s, the snake-eyes knockout at
    // the netted score times 10 percent, the constitution damage pool with
    // re-comparison each round, the dexterity-multiple extra punches at their
    // per-die penalty. The Ward quarterstaff article (folios 26-27): the
    // three proficiency stages at 12/11/9, the attack-attack / attack-defend
    // / defend-defend option set with simultaneous resolution, the strength,
    // constitution and dexterity ladders, the chainmail and plate absorbs at
    // their hit penalties, the Combat Index down to the out-cold point, the
    // stage advancement ladder and the nine merry men statted for historical
    // simulations. The long-term-effects teaser (the Sorcerer's Scroll
    // column, next issue) harvests at issue 12 if it prints.
    {
        using namespace rules;
        int bad = 0;
    if (brwFirstMoveDexGap() != 2
            || brwBrawlDiceCount() != 2
            || brwBrawlDiceSides() != 6
            || brwPunchHitMax() != 7
            || brwPunchSecondHitMax() != 6
            || brwExtraPunchPenalty() != 1
            || brwUnconsciousAtCon() != 0
            || brwKnockoutPercentPerPoint() != 10
            || brwBreakFreeMinG() != 2
            || brwGrappleRows() != 11
            || brwPunchRows() != 11
            || brwStageOneHit() != 12
            || brwStageTwoHit() != 11
            || brwStageThreeHit() != 9
            || brwStaffDamageSides() != 6
            || brwNaturalTwentyBonus() != 1
            || brwDoubleAttackExtraDamage() != 3
            || brwForcedDefendThreshold() != 4
            || brwFullNegateNextBonus() != 1
            || brwChainmailAbsorb() != 4
            || brwChainmailHitPenalty() != 3
            || brwPlateAbsorb() != 6
            || brwPlateHitPenalty() != 5
            || brwOutColdAtPoints() != 1
            || brwAdvanceMatches() != 50
            || brwAdvanceWins() != 30
            || brwAdvanceDoubleFactor() != 2
            || brwStrBonusEighteen() != 2
            || brwStrBonusSeventeen() != 1
            || brwConAbsorbEighteen() != 2
            || brwConAbsorbSeventeen() != 1
            || brwDexLadderRows() != 3
            || brwMerryMen() != 9
            || !brwAveragedGrappleRoundsDown()
            || !brwConstitutionIsBrawlPool()
            || !brwRecompareOnConChange()
            || !brwDexMultiplesGrantExtraPunches()
            || !brwContinueHoldNgFrees()
            || !brwSnakeEyesKnockoutRoll()
            || !brwGCodesAreDamage()
            || !brwThreeMeleeOptions()
            || !brwCombatSimultaneous()
            || !brwSecretOrdersOption()
            || !brwArmorAbsorbsPerHit()
            || !brwDoubleStrikeForcesDefend()
            || !brwFullNegateGrantsPlusOne()
            || !brwCombatIndexIsStrCon()
            || !brwStageAdvancementByMatches()
            || !brwMerryMenForHistoricalSim()
        )
            ++bad;
        // the brwGrapple grid
        int CGA[11][5] = {
            {4,3,3,2,2},
            {3,3,3,2,2},
            {3,3,2,2,2},
            {3,3,2,2,2},
            {2,2,1,1,1},
            {2,2,1,1,1},
            {2,2,1,1,0},
            {1,1,1,1,0},
            {1,1,1,0,0},
            {1,1,0,0,0},
            {1,0,0,0,0},
            };
        for (int b = 0;
             b < brwGrappleRows();
             ++b) {
            int vals[5];
            vals[0] = brwGrapplePlus4Hi(b);
            vals[1] = brwGrapplePlus3(b);
            vals[2] = brwGrapplePlus2(b);
            vals[3] = brwGrapplePlus1(b);
            vals[4] = brwGrappleZeroLo(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CGA[b][c])
                    ++bad;
            }
        }
        // the punch damage grid - the row-2 plus-four-or-higher cell garbles
        // in the DjVu OCR (a quoted 3) and rides the -9 sentinel; the four
        // clean row-2 cells anchor to the print's own snake-eyes note; the -5
        // haymaker of the legend never prints clean in the grid (folio 7)
        int CPB[11][5] = {
            {-9,-4,-3,-2,-1},
            {-3,-3,-2,-2,-1},
            {-3,-3,-2,-1,-1},
            {-3,-2,-2,-1,-1},
            {-2,-2,-2,-1,-1},
            {-2,-2,-1,-1,-1},
            {-2,-1,-1,-1,0},
            {-2,-1,-1,0,0},
            {-2,-1,0,0,0},
            {-1,-1,0,0,0},
            {-1,0,0,0,0},
            };
        int nPB[5] = {0,0,0,0,0};
        int ePB[5] = {1,0,0,0,0};
        for (int b = 0;
             b < brwPunchRows();
             ++b) {
            int vals[5];
            vals[0] = brwPunchPlus4Hi(b);
            vals[1] = brwPunchPlus3(b);
            vals[2] = brwPunchPlus2(b);
            vals[3] = brwPunchPlus1(b);
            vals[4] = brwPunchZeroLo(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CPB[b][c])
                    ++bad;
                if (vals[c] == -9)
                    ++nPB[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nPB[c] != ePB[c])
                ++bad;
        // the brwDexLadder grid
        int CDX[3][2] = {
            {1,0},
            {2,1},
            {3,2},
            };
        for (int b = 0;
             b < brwDexLadderRows();
             ++b) {
            int vals[2];
            vals[0] = brwDexHitPlus(b);
            vals[1] = brwDexAbsorb(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CDX[b][c])
                    ++bad;
            }
        }
        // the nine merry men - Robin Hood, Little John, Will Scarlet, Will
        // Stutely, Friar Tuck, Arthur-a-Bland, David of Doncaster, Wat of the
        // Crab Staff and Much the Miller's Son, in the print order (folio 27)
        int CMM[9][4] = {
            {17,18,17,3},
            {18,18,18,3},
            {18,17,17,3},
            {17,17,15,3},
            {18,16,17,3},
            {17,18,18,3},
            {17,17,17,2},
            {17,16,18,3},
            {17,17,17,2},
            };
        for (int b = 0;
             b < brwMerryMen();
             ++b) {
            int vals[4];
            vals[0] = brwMerryStr(b);
            vals[1] = brwMerryDex(b);
            vals[2] = brwMerryCon(b);
            vals[3] = brwMerryStage(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CMM[b][c])
                    ++bad;
            }
        }
        // the brwDiffBand band-for boundaries
    if (brwDiffBand(-1) != 0
            || brwDiffBand(0) != 0
            || brwDiffBand(1) != 1
            || brwDiffBand(1) != 1
            || brwDiffBand(2) != 2
            || brwDiffBand(2) != 2
            || brwDiffBand(3) != 3
            || brwDiffBand(3) != 3
            || brwDiffBand(4) != 4
        )
            ++bad;
        // the first-move gap and the difference bands - a +4 advantage opens
        // band 0, the 0-or-lower rides the tail (folio 7)
    if (brwFirstMoveDexGap() != 2
            || brwDiffBand(0) != 0
            || brwDiffBand(4) != 4
        )
            ++bad;
        // the worked grapple - the +1 band at the roll of 3 nets G2, two
        // points held (folio 7)
    if (brwGrapplePlus1(1) != 2
        )
            ++bad;
        // the worked break - the 0-or-lower band at the roll of 3 nets the G2
        // break minimum (folio 7)
    if (brwGrappleZeroLo(1) != 2
            || brwBreakFreeMinG() != 2
        )
            ++bad;
        // the snake-eyes knockout - the +3 band nets -4 for the 40 percent
        // chance, the 0-or-lower nets -1 for 10 (folio 7)
    if (brwPunchPlus3(0) != -4
            || brwPunchZeroLo(0) != -1
            || brwKnockoutPercentPerPoint() != 10
        )
            ++bad;
        // the grappling grid corners - G4 at the top of the plus-4 column, G1
        // at the bottom, G2 to NG across the 0-or-lower (folio 7)
    if (brwGrapplePlus4Hi(0) != 4
            || brwGrapplePlus4Hi(10) != 1
            || brwGrappleZeroLo(0) != 2
            || brwGrappleZeroLo(10) != 0
        )
            ++bad;
        // the punch grid census - the -4 solid punch tops the plus-3 column,
        // the missed-punch 0s ride the bottom right (folio 7)
    if (brwPunchPlus3(0) != -4
            || brwPunchPlus3(10) != 0
            || brwPunchZeroLo(10) != 0
        )
            ++bad;
        // the dexterity ladder - the 18 gives plus 3 to hit and 2 absorbed,
        // the 16 gives plus 1 and none (folio 26)
    if (brwDexHitPlus(2) != 3
            || brwDexAbsorb(2) != 2
            || brwDexAbsorb(0) != 0
        )
            ++bad;
        // the worked match - Little John's con-18 plus dex-18 absorbs 4, Will
        // Scarlet's con-17 plus dex-18 absorbs 3 (folio 27)
    if (brwConAbsorbEighteen() + brwDexAbsorb(2) != 4
            || brwConAbsorbSeventeen() + brwDexAbsorb(2) != 3
        )
            ++bad;
        // the rules-text hit floor - the third-stage 9 less the dex-18 plus-3
        // reads 6; the print's worked example says 7 or more, the discrepancy
        // noted never silent (folios 26-27)
    if (brwStageThreeHit() - brwDexHitPlus(2) != 6
        )
            ++bad;
        // the armor - chainmail absorbs 4 at plus 3 to the roll, plate
        // absorbs 6 at plus 5 (folio 26)
    if (brwChainmailAbsorb() != 4
            || brwChainmailHitPenalty() != 3
            || brwPlateAbsorb() != 6
            || brwPlateHitPenalty() != 5
        )
            ++bad;
        // the stage ladder - 50 matches with 30 wins raise stage one, doubled
        // for stage two to three (folio 26)
    if (brwAdvanceMatches() != 50
            || brwAdvanceWins() != 30
            || brwAdvanceDoubleFactor() != 2
        )
            ++bad;
        // Little John 18/18/18 at the third stage (folio 27)
    if (brwMerryStr(1) != 18
            || brwMerryDex(1) != 18
            || brwMerryCon(1) != 18
            || brwMerryStage(1) != 3
        )
            ++bad;
        // Robin Hood 17/18/17; David of Doncaster and Much the Miller's Son
        // ride the second stage (folio 27)
    if (brwMerryStr(0) != 17
            || brwMerryStage(6) != 2
            || brwMerryStage(8) != 2
        )
            ++bad;
        // the Combat Index derivation - Robin 34, Little John 36 and Will
        // Stutely 32 all read strength plus constitution (folio 27)
    if (brwMerryStr(0) + brwMerryCon(0) != 34
            || brwMerryStr(1) + brwMerryCon(1) != 36
            || brwMerryStr(3) + brwMerryCon(3) != 32
        )
            ++bad;
        printf("R917 issue-11 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
