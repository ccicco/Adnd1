    // ---- R643 OA armor audit ----
    // OA round thirty (capture p. 94): the Table 52 armor class table - the
    // suit armor class ratings
    {
        using namespace rules;
        int bad = 0;
    if (dhdT52RowCount() != 8
        )
            ++bad;
        // the Table 52 grid: the suit armor class ratings
        int CT52Data[8][1] = {
            {10},
            {9},
            {8},
            {7},
            {6},
            {5},
            {4},
            {3},
            };
        int nT52Data[1] = {0};
        int eT52Data[1] = {0};
        for (int b = 0;
             b < dhdT52RowCount();
             ++b) {
            int vals[1];
            vals[0] = dhdT52Ac(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT52Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT52Data[c];
            }
        }
        for (int c = 0; c < 1; ++c)
            if (nT52Data[c] != eT52Data[c])
                ++bad;
        // the T52 row count pin
    if (dhdT52RowCount() != 8
        )
            ++bad;
        // the unarmored rating pin
    if (dhdT52Ac(0) != 10
        )
            ++bad;
        // the best suit rating pin
    if (dhdT52Ac(7) != 3
        )
            ++bad;
        // the None row - the unarmored rating 10 (capture p. 94)
    if (dhdT52Ac(0) != 10
        )
            ++bad;
        // the shield/kote row - the shield-alone rating 9, the kote spelling
        // as printed (capture p. 94)
    if (dhdT52Ac(1) != 9
        )
            ++bad;
        // the studded-leather row - the rating 7, the corselet-equality
        // cross-check from the page prose (capture p. 94)
    if (dhdT52Ac(3) != 7
        )
            ++bad;
        // the hide and chain-mail rows - the ratings 5 and 4, the chain-mail
        // row third type settling as banded mail (capture p. 94)
    if (dhdT52Ac(5) != 5
            || dhdT52Ac(6) != 4
        )
            ++bad;
        // the o-yori tail row - the best suit rating 3 (capture p. 94)
    if (dhdT52Ac(7) != 3
        )
            ++bad;
        // the ladder - one step per row from 10 through 3, no gaps (capture
        // p. 94)
    if (dhdT52Ac(2) != 8
            || dhdT52Ac(4) != 6
        )
            ++bad;
        printf("R643 OA armor audit: bad %d\n", bad);
        if (bad) return 1;
    }
