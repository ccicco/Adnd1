    // ---- R631 OA ancestry audit ----
    // OA round eighteen (capture pp. 64-65): the master family chart, the
    // ancestry doctrine and the Table 39 grid
    {
        using namespace rules;
        int bad = 0;
    if (dgrT39RowCount() != 46
            || dgrAllianceBonusPct() != 20
            || dgrFeudModPct() != -40
            || dgrAdvMarriageLevels() != 3
            || dgrLandIncomeMin() != 10
            || dgrLandIncomeMax() != 2000
            || dgrEstateIncomeMin() != 100
            || dgrEstateIncomeMax() != 1000
            || dgrFleetShipsMin() != 2
            || dgrFleetShipsMax() != 5
            || dgrFleetIncomeMin() != 100
            || dgrFleetIncomeMax() != 1000
            || dgrFolkHeroBonusPct() != 10
            || !dgrMasterChartPurpose()
            || !dgrMasterChartCenter()
            || !dgrMasterChartRankDistance()
            || !dgrMasterChartLineCodes()
            || !dgrAncestryBeyondAncestors()
            || !dgrAncestryCooperativeDetail()
            || !dgrHonorAddsToBirth()
            || !dgrMoneylenderExtraRoll()
            || !dgrHereditaryTitlePassesToSon()
            || !dgrSecretSocietyContacts()
            || !dgrTragicEventAddsHonor()
            || !dgrRollAgainNextDie()
        )
            ++bad;
        // the Table 39 grid: the die bands, the honor column and the coded
        // ancestry results (capture p. 65)
        int CT39[46][4] = {
            {1,3,0,0},
            {4,4,-15,2},
            {5,5,0,3},
            {6,6,0,1},
            {7,8,2,4},
            {9,9,2,5},
            {10,10,0,1},
            {11,11,-10,6},
            {12,15,3,7},
            {16,19,6,8},
            {20,20,0,1},
            {21,24,0,0},
            {25,26,6,9},
            {27,31,3,10},
            {32,35,2,11},
            {36,38,0,0},
            {39,39,6,12},
            {40,42,8,13},
            {43,44,10,14},
            {45,45,7,15},
            {46,46,-10,16},
            {47,49,0,0},
            {50,50,-10,17},
            {51,54,6,18},
            {55,56,7,19},
            {57,57,9,20},
            {58,58,1,21},
            {59,59,8,22},
            {60,63,0,0},
            {64,69,0,0},
            {70,70,10,23},
            {71,71,-20,24},
            {72,72,15,25},
            {73,77,0,0},
            {78,78,12,26},
            {79,79,-5,27},
            {80,80,-7,28},
            {81,85,0,0},
            {86,87,4,29},
            {88,91,2,30},
            {92,93,-5,31},
            {94,96,7,32},
            {97,97,0,1},
            {98,98,0,33},
            {99,99,3,34},
            {100,100,0,0},
            };
        int nT39[4] = {0,0,0,0};
        int eT39[4] = {0,0,0,0};
        for (int b = 0;
             b < dgrT39RowCount();
             ++b) {
            int vals[4];
            vals[0] = dgrT39DieLo(b);
            vals[1] = dgrT39DieHi(b);
            vals[2] = dgrT39Honor(b);
            vals[3] = dgrT39Result(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CT39[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT39[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nT39[c] != eT39[c])
                ++bad;
        // the dgrT39RowCount pin
    if (dgrT39RowCount() != 46
        )
            ++bad;
        // the dgrAllianceBonusPct pin
    if (dgrAllianceBonusPct() != 20
        )
            ++bad;
        // the dgrFeudModPct pin
    if (dgrFeudModPct() != -40
        )
            ++bad;
        // the dgrAdvMarriageLevels pin
    if (dgrAdvMarriageLevels() != 3
        )
            ++bad;
        // the dgrLandIncomeMin pin
    if (dgrLandIncomeMin() != 10
        )
            ++bad;
        // the dgrLandIncomeMax pin
    if (dgrLandIncomeMax() != 2000
        )
            ++bad;
        // the dgrEstateIncomeMin pin
    if (dgrEstateIncomeMin() != 100
        )
            ++bad;
        // the dgrEstateIncomeMax pin
    if (dgrEstateIncomeMax() != 1000
        )
            ++bad;
        // the dgrFleetShipsMin pin
    if (dgrFleetShipsMin() != 2
        )
            ++bad;
        // the dgrFleetShipsMax pin
    if (dgrFleetShipsMax() != 5
        )
            ++bad;
        // the dgrFleetIncomeMin pin
    if (dgrFleetIncomeMin() != 100
        )
            ++bad;
        // the dgrFleetIncomeMax pin
    if (dgrFleetIncomeMax() != 1000
        )
            ++bad;
        // the dgrFolkHeroBonusPct pin
    if (dgrFolkHeroBonusPct() != 10
        )
            ++bad;
        // the dgrMasterChartPurpose pin
    if (dgrMasterChartPurpose() != 1
        )
            ++bad;
        // the dgrMasterChartCenter pin
    if (dgrMasterChartCenter() != 1
        )
            ++bad;
        // the dgrMasterChartRankDistance pin
    if (dgrMasterChartRankDistance() != 1
        )
            ++bad;
        // the dgrMasterChartLineCodes pin
    if (dgrMasterChartLineCodes() != 1
        )
            ++bad;
        // the dgrAncestryBeyondAncestors pin
    if (dgrAncestryBeyondAncestors() != 1
        )
            ++bad;
        // the dgrAncestryCooperativeDetail pin
    if (dgrAncestryCooperativeDetail() != 1
        )
            ++bad;
        // the dgrHonorAddsToBirth pin
    if (dgrHonorAddsToBirth() != 1
        )
            ++bad;
        // the dgrMoneylenderExtraRoll pin
    if (dgrMoneylenderExtraRoll() != 1
        )
            ++bad;
        // the dgrHereditaryTitlePassesToSon pin
    if (dgrHereditaryTitlePassesToSon() != 1
        )
            ++bad;
        // the dgrSecretSocietyContacts pin
    if (dgrSecretSocietyContacts() != 1
        )
            ++bad;
        // the dgrTragicEventAddsHonor pin
    if (dgrTragicEventAddsHonor() != 1
        )
            ++bad;
        // the dgrRollAgainNextDie pin
    if (dgrRollAgainNextDie() != 1
        )
            ++bad;
        // the T39 first row - the blank 1-3 band (capture p. 65)
    if (dgrT39DieLo(0) != 1
            || dgrT39DieHi(0) != 3
            || dgrT39Honor(0) != 0
            || dgrT39Result(0) != 0
        )
            ++bad;
        // the T39 criminal cell - the -15 honor at die 4 (capture p. 65)
    if (dgrT39Honor(1) != -15
            || dgrT39Result(1) != 2
        )
            ++bad;
        // the T39 roll-again rows - 6, 10 and 20 with the next-higher-die
        // read, 97 with the d100 add-10 read (capture p. 65)
    if (dgrT39Result(3) != 1
            || dgrT39Result(6) != 1
            || dgrT39Result(10) != 1
            || dgrT39Result(42) != 1
        )
            ++bad;
        // the T39 dishonor pair - the great betrayal -20 at 71, the defeated
        // family -10 at 50 (capture p. 65)
    if (dgrT39Honor(31) != -20
            || dgrT39Honor(22) != -10
        )
            ++bad;
        // the T39 great hero cell - the +15 honor at die 72 (capture p. 65)
    if (dgrT39Honor(32) != 15
            || dgrT39Result(32) != 25
        )
            ++bad;
        // the T39 imperial bloodline cell - the +12 honor at die 78 (capture
        // p. 65)
    if (dgrT39Honor(34) != 12
            || dgrT39Result(34) != 26
        )
            ++bad;
        // the T39 famous trio - the general +9, the holy man +1, the minister
        // +8 (capture p. 65)
    if (dgrT39Honor(25) != 9
            || dgrT39Honor(26) != 1
            || dgrT39Honor(27) != 8
        )
            ++bad;
        // the T39 tragic event capstone - the +3 honor at die 99, the blank
        // at 100, forty-six rows only (capture p. 65)
    if (dgrT39Honor(44) != 3
            || dgrT39Result(44) != 34
            || dgrT39DieLo(45) != 100
            || dgrT39Honor(45) != 0
            || dgrT39RowCount() != 46
        )
            ++bad;
        // the T39 band contiguity - 3 to 4, 24 to 25, 69 to 70, 96 to 97
        // (capture p. 65)
    if (dgrT39DieLo(1) - dgrT39DieHi(0) != 1
            || dgrT39DieLo(12) - dgrT39DieHi(11) != 1
            || dgrT39DieLo(30) - dgrT39DieHi(29) != 1
            || dgrT39DieLo(42) - dgrT39DieHi(41) != 1
        )
            ++bad;
        // the T39 honor-adds doctrine - the base honor is the Character Birth
        // honor plus the Table 39 honor (capture p. 65)
    if (dgrHonorAddsToBirth() != 1
        )
            ++bad;
        printf("R631 OA ancestry audit: bad %d\n", bad);
        if (bad) return 1;
    }
