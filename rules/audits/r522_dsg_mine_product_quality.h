    // ---- R522 DSG mine product quality audit ----
    // The DSG mine product quality pins the ore quality roll (the Table 33
    // five-metal d10 coins-per-man-week grid - copper 100 through 2000, iron
    // 200 through 4000, silver 25 through 2000, gold 10 through 1000,
    // platinum 5 through 1000), the pure-vein rule (the 10-again roll,
    // another 10 needing no smelting, 1-9 smelting normally), the unsmelted
    // ore selling at 25% to 5%, the iron equivalences (1000 coins a plate
    // suit, 100 spear points, 500 arrowheads), and the gemstone quality (the
    // Table 34 seventeen rows from bloodstone 2d10 at 20 + 10d6 gp through
    // emerald 1d10/5 at 300 x 1d8 gp, the 1d6-turn identification, the
    // unfinished selling at 25% to 10%, and the weekly re-roll applying to
    // all miners that week).
    {
        using namespace rules;
        int bad = 0;
    if (dnqtT33RowCount() != 10
            || dnqtT34RowCount() != 17
            || dnqtOreQualityDice() != 1
            || dnqtOreQualitySides() != 10
            || dnqtOrePureVeinRoll() != 10
            || dnqtUnsmeltedOreSellMaxPct() != 25
            || dnqtUnsmeltedOreSellMinPct() != 5
            || dnqtIronCoinPlate() != 1000
            || dnqtIronCoinSpearPoints() != 100
            || dnqtIronCoinArrowheads() != 500
            || dnqtStoneIdentifyDice() != 1
            || dnqtStoneIdentifySides() != 6
            || dnqtUnfinishedStonesSellMaxPct() != 25
            || dnqtUnfinishedStonesSellMinPct() != 10
            || !dnqtOreMixedWithRock()
            || !dnqtSmelterPurifies()
            || !dnqtQualityCoinsPerMinerWeek()
            || !dnqtPureVeinNeedsNoSmelting()
            || !dnqtPureVeinSmeltOtherwise()
            || !dnqtCoinageIndicatesMetalAmount()
            || !dnqtStonesRoughUnrecognized()
            || !dnqtMinerOrJewelerIdentifies()
            || !dnqtStoneCountPerMinerWeek()
            || !dnqtStoneValueRolledEachWeek()
            || !dnqtQualityAppliesAllMinersWeek()
            || !dnqtDivideAndRoundUp()
        )
            ++bad;
        // the Table 33 ore quality grid, the 1d10 coins-per-man-week rolls
        // for five metals
        int C33[10][5] = {
            {100,200,25,10,5},
            {200,300,50,25,10},
            {250,500,100,50,20},
            {300,700,200,100,40},
            {350,900,300,200,75},
            {400,1200,400,300,100},
            {500,1600,500,400,250},
            {750,2000,750,500,400},
            {1000,3000,1000,750,800},
            {2000,4000,2000,1000,1000},
            };
        for (int b = 0;
             b < dnqtT33RowCount();
             ++b) {
            int vals[5];
            vals[0] = dnqtT33Copper(b);
            vals[1] = dnqtT33Iron(b);
            vals[2] = dnqtT33Silver(b);
            vals[3] = dnqtT33Gold(b);
            vals[4] = dnqtT33Platinum(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != C33[b][c])
                    ++bad;
            }
        }
        // the Table 34 gemstone quality grid, the seventeen stone rows in
        // count and average value
        int C34[17][7] = {
            {2,10,1,20,1,10,6},
            {1,10,1,0,1,6,100},
            {3,10,1,10,1,10,6},
            {4,10,1,0,1,5,6},
            {4,10,1,0,1,5,6},
            {1,10,1,0,10,5,6},
            {1,10,1,0,100,1,4},
            {2,10,1,0,10,5,6},
            {1,10,1,0,100,1,4},
            {1,10,1,0,100,1,6},
            {2,10,1,0,100,1,4},
            {1,10,1,0,10,5,6},
            {1,10,3,0,200,1,6},
            {1,10,3,0,200,1,8},
            {1,10,4,0,200,1,8},
            {1,10,5,0,300,1,6},
            {1,10,5,0,300,1,8},
            };
        for (int b = 0;
             b < dnqtT34RowCount();
             ++b) {
            int vals[7];
            vals[0] = dnqtT34CountDice(b);
            vals[1] = dnqtT34CountSides(b);
            vals[2] = dnqtT34CountDiv(b);
            vals[3] = dnqtT34ValAdd(b);
            vals[4] = dnqtT34ValMult(b);
            vals[5] = dnqtT34ValDice(b);
            vals[6] = dnqtT34ValSides(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != C34[b][c])
                    ++bad;
            }
        }
        // the rolls: the 1d10 ore quality roll with the roll-again pure vein
        // 10, and the 1d6-turn stone identification study.
    if (dnqtOreQualityDice() != 1
            || dnqtOreQualitySides() != 10
            || dnqtOrePureVeinRoll() != 10
            || dnqtStoneIdentifyDice() != 1
            || dnqtStoneIdentifySides() != 6
        )
            ++bad;
        // the selling and equivalence numbers: unsmelted ore 25%-5%,
        // unfinished stones 25%-10%, and the 1000-coin iron equivalents
        // (plate suit, 100 spear points, 500 arrowheads).
    if (dnqtUnsmeltedOreSellMaxPct() != 25
            || dnqtUnsmeltedOreSellMinPct() != 5
            || dnqtUnfinishedStonesSellMaxPct() != 25
            || dnqtUnfinishedStonesSellMinPct() != 10
            || dnqtIronCoinPlate() != 1000
            || dnqtIronCoinSpearPoints() != 100
            || dnqtIronCoinArrowheads() != 500
        )
            ++bad;
        // the quality prose: coins per single miner per week, the pure-vein
        // 10-again rule, the weekly value re-roll applying to all miners that
        // week, and the divide-and-round-up footnote.
    if (dnqtQualityCoinsPerMinerWeek() != 1
            || dnqtPureVeinNeedsNoSmelting() != 1
            || dnqtPureVeinSmeltOtherwise() != 1
            || dnqtStoneValueRolledEachWeek() != 1
            || dnqtQualityAppliesAllMinersWeek() != 1
            || dnqtDivideAndRoundUp() != 1
        )
            ++bad;
        // Table 33 anchor rows: copper 100/2000 at rolls 1/10, iron 200/4000
        // (the machine-reads-missing row), platinum 5/1000.
    if (dnqtT33Copper(0) != 100
            || dnqtT33Copper(9) != 2000
            || dnqtT33Iron(0) != 200
            || dnqtT33Iron(9) != 4000
            || dnqtT33Platinum(0) != 5
            || dnqtT33Platinum(9) != 1000
        )
            ++bad;
        // Table 34 anchor rows: bloodstone 20 + 10d6 gp, onyx 10 + 10d6 gp
        // (both settled by the physical read), amber 6d100 gp.
    if (dnqtT34ValAdd(0) != 20
            || dnqtT34ValDice(0) != 10
            || dnqtT34ValSides(0) != 6
            || dnqtT34ValAdd(2) != 10
            || dnqtT34ValDice(2) != 10
            || dnqtT34ValSides(2) != 6
            || dnqtT34ValSides(1) != 100
        )
            ++bad;
        // Table 34 footnote rows: opal /3, sapphire /4, diamond /5, emerald
        // /5 with 300 x 1d8 gp.
    if (dnqtT34CountDiv(12) != 3
            || dnqtT34CountDiv(14) != 4
            || dnqtT34CountDiv(15) != 5
            || dnqtT34CountDiv(16) != 5
            || dnqtT34ValMult(16) != 300
            || dnqtT34ValSides(16) != 8
        )
            ++bad;
        printf("R522 DSG mine product quality audit: bad %d\n", bad);
        if (bad) return 1;
    }
