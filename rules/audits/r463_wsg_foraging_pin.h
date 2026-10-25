    // ---- R463 WSG foraging pin audit ----
    // The Table 30 grid cell by cell (five climate regions, the chance and
    // inedible percent per terrain per season), the two-turn foraging check
    // with the proficiency advantage and the four-turn search limit, the 1d8
    // inedible dispatch with the poison and tainted cramp and dice rules -
    // every cell, const, bool and chain limit verified against the model.
    {
        using namespace rules;
        int bad = 0;
    if (wfgCheckTurnsNormal() != 2
            || wfgRationPounds() != 2
            || wfgProfRationsPerCheck() != 2
            || wfgProfTurnsPerRation() != 1
            || wfgProfInedibleReduction() != 20
            || wfgSearchTurnsMax() != 4
            || wfgChecksMaxNormal() != 2
            || wfgChecksMaxProf() != 4
            || wfgMilesBeforeReforage() != 1
            || wfgArcRowCount() != 5
            || wfgSubRowCount() != 7
            || wfgTemRowCount() != 7
            || wfgStiRowCount() != 7
            || wfgTroRowCount() != 7
            || wfgInedRollMax() != 8
            || wfgPoisonCrampOnsetDie() != 10
            || wfgPoisonCrampTurnsDice() != 2
            || wfgPoisonCrampTurnsDie() != 10
            || wfgPoisonHpPerTurnDie() != 4
            || wfgPoisonRegainPerHourDie() != 4
            || wfgPoisonRestWaterPintsPerHour() != 1
            || wfgSlowPoisonSaveStackNum() != 1
            || wfgSlowPoisonSaveStackDen() != 4
            || wfgTaintCrampOnsetDie() != 10
            || wfgTaintCrampTurnsDie() != 10
            || wfgTaintHpPerTurnDie() != 2
            || wfgTaintHalfNum() != 1
            || wfgTaintHalfDen() != 2
            || !wfgProfFindChanceNormal()
            || !wfgPoisonHalfRationTriggers()
            || !wfgPoisonSaveHalves()
            || !wfgSlowPoisonActsAsSave()
            || !wfgNeutralizeHaltsCramps()
            || !wfgNeutralizeNoPriorDamage()
            || !wfgTaintSaveHalves()
            || !wfgTaintCureDiseaseHalts()
            || !wfgNoValueWaterOnly()
            || !wfgNoValueFullNoNourish()
            || !wfgOrchardGuaranteed()
            || !wfgRipePickedInedibleNearZero()
            || !wfgTableNotUnerring()
            || !wfgGroupMustMoveOn()
        )
            ++bad;
        // the Table 30 Arctic terrain grid (chance/inedible per season)
        int C30A[5][8] = {
            {0,0,5,75,10,75,0,0},
            {5,75,10,60,10,60,5,50},
            {0,0,0,0,5,50,0,0},
            {5,50,5,50,10,50,5,50},
            {10,75,10,50,15,50,10,75},
            };
        for (int b = 0;
             b < wfgArcRowCount();
             ++b) {
            int vals[8];
            vals[0] = wfgArcWinChn(b);
            vals[1] = wfgArcWinInd(b);
            vals[2] = wfgArcSprChn(b);
            vals[3] = wfgArcSprInd(b);
            vals[4] = wfgArcSumChn(b);
            vals[5] = wfgArcSumInd(b);
            vals[6] = wfgArcAutChn(b);
            vals[7] = wfgArcAutInd(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C30A[b][c])
                    ++bad;
            }
        }
        // the Table 30 Subarctic terrain grid (chance/inedible per season)
        int C30B[7][8] = {
            {0,0,5,50,15,50,5,75},
            {70,40,85,40,100,50,75,40},
            {20,50,30,50,40,40,25,50},
            {10,50,15,50,20,40,15,50},
            {20,40,30,40,50,40,30,50},
            {25,60,35,50,50,40,35,50},
            {15,60,20,60,30,60,20,50},
            };
        for (int b = 0;
             b < wfgSubRowCount();
             ++b) {
            int vals[8];
            vals[0] = wfgSubWinChn(b);
            vals[1] = wfgSubWinInd(b);
            vals[2] = wfgSubSprChn(b);
            vals[3] = wfgSubSprInd(b);
            vals[4] = wfgSubSumChn(b);
            vals[5] = wfgSubSumInd(b);
            vals[6] = wfgSubAutChn(b);
            vals[7] = wfgSubAutInd(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C30B[b][c])
                    ++bad;
            }
        }
        // the Table 30 Temperate terrain grid (chance/inedible per season)
        int C30C[7][8] = {
            {10,70,5,50,5,70,5,50},
            {80,40,90,40,100,40,90,40},
            {65,50,75,40,90,35,80,50},
            {20,40,30,40,40,40,30,50},
            {50,40,60,40,75,30,60,50},
            {50,50,65,40,80,40,65,50},
            {30,60,35,50,40,50,35,60},
            };
        for (int b = 0;
             b < wfgTemRowCount();
             ++b) {
            int vals[8];
            vals[0] = wfgTemWinChn(b);
            vals[1] = wfgTemWinInd(b);
            vals[2] = wfgTemSprChn(b);
            vals[3] = wfgTemSprInd(b);
            vals[4] = wfgTemSumChn(b);
            vals[5] = wfgTemSumInd(b);
            vals[6] = wfgTemAutChn(b);
            vals[7] = wfgTemAutInd(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C30C[b][c])
                    ++bad;
            }
        }
        // the Table 30 Subtropical terrain grid (chance/inedible per season)
        int C30D[7][8] = {
            {5,75,5,80,0,0,5,75},
            {90,30,100,30,100,30,100,30},
            {80,30,90,30,100,25,95,25},
            {40,40,55,30,75,30,60,40},
            {80,30,90,30,100,30,100,35},
            {80,40,90,40,100,40,95,40},
            {40,60,50,50,50,50,50,60},
            };
        for (int b = 0;
             b < wfgStiRowCount();
             ++b) {
            int vals[8];
            vals[0] = wfgStiWinChn(b);
            vals[1] = wfgStiWinInd(b);
            vals[2] = wfgStiSprChn(b);
            vals[3] = wfgStiSprInd(b);
            vals[4] = wfgStiSumChn(b);
            vals[5] = wfgStiSumInd(b);
            vals[6] = wfgStiAutChn(b);
            vals[7] = wfgStiAutInd(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C30D[b][c])
                    ++bad;
            }
        }
        // the Table 30 Tropical terrain grid (chance/inedible per season)
        int C30E[7][8] = {
            {5,75,5,80,0,0,5,75},
            {100,30,100,30,100,40,100,30},
            {90,30,100,40,100,40,95,35},
            {85,30,90,30,90,40,90,35},
            {100,30,100,45,100,50,100,40},
            {90,40,95,50,100,50,95,50},
            {50,60,60,60,70,50,60,60},
            };
        for (int b = 0;
             b < wfgTroRowCount();
             ++b) {
            int vals[8];
            vals[0] = wfgTroWinChn(b);
            vals[1] = wfgTroWinInd(b);
            vals[2] = wfgTroSprChn(b);
            vals[3] = wfgTroSprInd(b);
            vals[4] = wfgTroSumChn(b);
            vals[5] = wfgTroSumInd(b);
            vals[6] = wfgTroAutChn(b);
            vals[7] = wfgTroAutInd(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C30E[b][c])
                    ++bad;
            }
        }
        // the wfgInedBandFor band-for boundaries
    if (wfgInedBandFor(0) != 0
            || wfgInedBandFor(1) != 0
            || wfgInedBandFor(4) != 1
            || wfgInedBandFor(2) != 1
            || wfgInedBandFor(5) != 2
        )
            ++bad;
        // the subarctic forest winter forage: 70% find chance, 40% inedible
    if (wfgSubWinChn(1) != 70
            || wfgSubWinInd(1) != 40
        )
            ++bad;
        // the proficient take: two rations per two-turn check or one per turn
    if (wfgProfRationsPerCheck() != 2
            || wfgProfTurnsPerRation() != 1
        )
            ++bad;
        // the proficient inedible shift on the temperate forest spring cell:
        // 40 - 20 = 20
    if (wfgTemSprInd(1) - wfgProfInedibleReduction() != 20
        )
            ++bad;
        // the search limit: four turns is two normal checks, four proficient
        // checks
    if (wfgSearchTurnsMax() != wfgChecksMaxNormal() * wfgCheckTurnsNormal()
            || wfgSearchTurnsMax() != wfgChecksMaxProf() *
            wfgProfTurnsPerRation()
        )
            ++bad;
        // the ration weight: one day's ration is two pounds
    if (wfgRationPounds() != 2
        )
            ++bad;
        // the arctic desert winter: nothing to find
    if (wfgArcWinChn(0) != 0
            || wfgArcWinInd(0) != 0
        )
            ++bad;
        // the move-on rule: at least one mile before foraging again
    if (wfgMilesBeforeReforage() != 1
        )
            ++bad;
        // the inedible roll 1 is the poison band, 4 tainted, 5 no value
    if (wfgInedBandFor(1) != 0
            || wfgInedBandFor(4) != 1
            || wfgInedBandFor(5) != 2
            || wfgInedBandFor(8) != 2
        )
            ++bad;
        // the tropical swamp summer cell: 70% find, 50% inedible
    if (wfgTroSumChn(6) != 70
            || wfgTroSumInd(6) != 50
        )
            ++bad;
        // the subtropical hills autumn cell: 95% find, 25% inedible
    if (wfgStiAutChn(2) != 95
            || wfgStiAutInd(2) != 25
        )
            ++bad;
        printf("R463 WSG foraging pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
