    // ---- R759 OA Table 86 items audit ----
    // OA round one hundred forty-six (capture pp. 296-297): the Table 86
    // Oriental Magical Items - the thirty-four d100 bands of the item grid,
    // the banner of protection through the wondrous writing set, the 91-100
    // overlap quirk of the tail pinned as printed, single-pass pins per the
    // Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dluItemRowCount() != 34
            || !dluPageBreakGrid()
            || !dluOverlapQuirk()
            || !dluClassRestrictedItems()
            || !dluWideBands()
        )
            ++bad;
        // the dluMagicalItems grid
        int CMagicalItems[34][3] = {
            {1,5,1},
            {6,8,2},
            {9,11,3},
            {12,12,4},
            {13,13,5},
            {14,15,6},
            {16,20,7},
            {21,24,8},
            {25,27,9},
            {28,31,10},
            {32,32,11},
            {33,33,12},
            {34,35,13},
            {36,36,14},
            {37,37,15},
            {38,41,16},
            {42,44,17},
            {45,45,18},
            {46,47,19},
            {48,48,20},
            {49,51,21},
            {52,53,22},
            {54,58,23},
            {59,60,24},
            {61,63,25},
            {64,70,26},
            {71,71,27},
            {72,72,28},
            {73,85,29},
            {86,87,30},
            {88,92,31},
            {93,94,32},
            {95,96,33},
            {91,100,34},
            };
        int nMagicalItems[3] = {0,0,0};
        int eMagicalItems[3] = {0,0,0};
        for (int b = 0;
             b < dluItemRowCount();
             ++b) {
            int vals[3];
            vals[0] = dluItemRollMin(b);
            vals[1] = dluItemRollMax(b);
            vals[2] = dluItemCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CMagicalItems[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nMagicalItems[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nMagicalItems[c] != eMagicalItems[c])
                ++bad;
        // the grid - the thirty-four-band Table 86, audited cell by cell by
        // the table audit
    if (dluItemRowCount() != 34
            || dluItemRollMin(0) != 1
            || dluItemRollMax(33) != 100
            || dluItemCode(0) != 1
            || dluItemCode(33) != 34
        )
            ++bad;
        // the quirks - the overlap band and the wide bands, healthy values,
        // each condition false
    if (dluItemRollMin(32) != 95
            || dluItemRollMax(32) != 96
            || dluItemRollMin(33) != 91
            || dluItemRollMax(33) != 100
            || dluItemRollMin(28) != 73
            || dluItemRollMax(28) != 85
            || dluOverlapQuirk() != 1
            || dluPageBreakGrid() != 1
            || dluClassRestrictedItems() != 1
            || dluWideBands() != 1
        )
            ++bad;
        printf("R759 OA Table 86 items audit: bad %d\n", bad);
        if (bad) return 1;
    }
