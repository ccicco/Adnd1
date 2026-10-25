    // ---- R736 OA Table II.A. Orient audit ----
    // OA round one hundred twenty-three (capture pp. 286-287): the Table
    // II.A. (Orient) Monetary Treasure - the nine d20 bands, the treasure
    // ranges as the min and max pairs with the nil the 0 sentinel, the
    // roll-twice and roll-three-times mechanics with the reroll limit, the
    // one-of-each 20 row, the capture misreads pinned against the print,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkxRowCount() != 9
            || dkxRerollLimit() != 17
            || dkxOneOfEachRow() != 20
            || !dkxRowOneFenYuan()
            || !dkxRowTael()
            || !dkxRowChienOneDieSix()
            || !dkxRowChienFiveDieFour()
            || !dkxRowGems()
            || !dkxRowJewelryOrArt()
            || !dkxRollTwice()
            || !dkxRollThreeTimes()
            || !dkxOneOfEachTreasure()
        )
            ++bad;
        // the dkxIIA grid
        int CIIA[9][17] = {
            {1,2,10000,40000,10000,60000,0,0,0,0,0,0,0,0,1,0,0},
            {3,5,0,0,0,0,10000,60000,0,0,0,0,0,0,1,0,0},
            {6,10,0,0,0,0,0,0,500,1000,0,0,0,0,1,0,0},
            {11,12,0,0,0,0,0,0,500,2000,0,0,0,0,1,0,0},
            {13,15,0,0,0,0,0,0,0,0,10,100,0,0,1,0,0},
            {16,17,0,0,0,0,0,0,0,0,0,0,5,50,1,0,0},
            {18,18,0,0,0,0,0,0,0,0,0,0,0,0,2,17,0},
            {19,19,0,0,0,0,0,0,0,0,0,0,0,0,3,17,0},
            {20,20,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
            };
        int nIIA[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int eIIA[17] = {0,0,8,8,8,8,8,8,7,7,8,8,8,8,0,7,8};
        for (int b = 0;
             b < dkxRowCount();
             ++b) {
            int vals[17];
            vals[0] = dkxRollMin(b);
            vals[1] = dkxRollMax(b);
            vals[2] = dkxFenMin(b);
            vals[3] = dkxFenMax(b);
            vals[4] = dkxYuanMin(b);
            vals[5] = dkxYuanMax(b);
            vals[6] = dkxTaelMin(b);
            vals[7] = dkxTaelMax(b);
            vals[8] = dkxChienMin(b);
            vals[9] = dkxChienMax(b);
            vals[10] = dkxGemsMin(b);
            vals[11] = dkxGemsMax(b);
            vals[12] = dkxArtMin(b);
            vals[13] = dkxArtMax(b);
            vals[14] = dkxRollsCount(b);
            vals[15] = dkxRerollAbove(b);
            vals[16] = dkxOneOfEach(b);
            for (int c = 0; c < 17;
                 ++c) {
                if (vals[c] != CIIA[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nIIA[c];
            }
        }
        for (int c = 0; c < 17; ++c)
            if (nIIA[c] != eIIA[c])
                ++bad;
        // the row bools - the nine-band walkthrough, healthy values, each
        // condition false
    if (dkxRowOneFenYuan() != 1
            || dkxRowTael() != 1
            || dkxRowChienOneDieSix() != 1
            || dkxRowChienFiveDieFour() != 1
            || dkxRowGems() != 1
            || dkxRowJewelryOrArt() != 1
            || dkxRollTwice() != 1
            || dkxRollThreeTimes() != 1
            || dkxOneOfEachTreasure() != 1
        )
            ++bad;
        // the mechanics - the reroll limit and the one-of-each row, healthy
        // values, each condition false
    if (dkxRerollLimit() != 17
            || dkxOneOfEachRow() != 20
            || dkxRerollAbove(6) != 17
            || dkxRerollAbove(7) != 17
            || dkxRollsCount(6) != 2
            || dkxRollsCount(7) != 3
            || dkxOneOfEach(8) != 1
        )
            ++bad;
        // the bands - the d20 spans abut and cover 1 through 20, healthy
        // values, each condition false
    if (dkxRollMin(0) != 1
            || dkxRollMax(0) != 2
            || dkxRollMax(8) != 20
            || dkxRowCount() != 9
        )
            ++bad;
        printf("R736 OA Table II.A. Orient audit: bad %d\n", bad);
        if (bad) return 1;
    }
