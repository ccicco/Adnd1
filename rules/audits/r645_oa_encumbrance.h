    // ---- R645 OA encumbrance audit ----
    // OA round thirty-two (capture p. 95): the Table 54 types of armor and
    // encumbrance - the base weights and movement rates
    {
        using namespace rules;
        int bad = 0;
    if (dhfT54RowCount() != 23
        )
            ++bad;
        // the Table 54 grid: the base weights and movement rates
        int CT54Data[23][2] = {
            {35,9},
            {3,-99},
            {30,9},
            {20,9},
            {10,-99},
            {10,9},
            {10,12},
            {15,12},
            {20,9},
            {25,9},
            {-99,-99},
            {15,12},
            {40,6},
            {10,9},
            {25,9},
            {20,9},
            {40,6},
            {10,-99},
            {5,-99},
            {3,-99},
            {40,6},
            {20,9},
            {5,-99},
            };
        int nT54Data[2] = {0,0};
        int eT54Data[2] = {1,7};
        for (int b = 0;
             b < dhfT54RowCount();
             ++b) {
            int vals[2];
            vals[0] = dhfT54Weight(b);
            vals[1] = dhfT54Move(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT54Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT54Data[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nT54Data[c] != eT54Data[c])
                ++bad;
        // the T54 row count pin
    if (dhfT54RowCount() != 23
        )
            ++bad;
        // the banded row weight pin - the plus-after-pound class
    if (dhfT54Weight(0) != 35
        )
            ++bad;
        // the kote no-weight sentinel pin
    if (dhfT54Weight(10) != -99
        )
            ++bad;
        // the banded row - the 35# plus weight, the 9-foot movement (capture
        // p. 95)
    if (dhfT54Weight(0) != 35
            || dhfT54Move(0) != 9
        )
            ++bad;
        // the buckler row - the 3# weight, no base movement (capture p. 95)
    if (dhfT54Weight(1) != 3
            || dhfT54Move(1) != -99
        )
            ++bad;
        // the chain row - the 30# plus weight, the 9-foot movement (capture
        // p. 95)
    if (dhfT54Weight(2) != 30
            || dhfT54Move(2) != 9
        )
            ++bad;
        // the kote row - the blank weight cell and the dashed movement both
        // pin as -99 (capture p. 95)
    if (dhfT54Weight(10) != -99
            || dhfT54Move(10) != -99
        )
            ++bad;
        // the haramaki row - the 15# weight, the 12-foot movement (capture p.
        // 95)
    if (dhfT54Weight(7) != 15
            || dhfT54Move(7) != 12
        )
            ++bad;
        // the o-yori row - the bulky 40# weight, the 6-foot movement (capture
        // p. 95)
    if (dhfT54Weight(12) != 40
            || dhfT54Move(12) != 6
        )
            ++bad;
        // the shields - the large 10# and medium 5#, both no base movement
        // (capture p. 95)
    if (dhfT54Weight(17) != 10
            || dhfT54Weight(18) != 5
            || dhfT54Move(17) != -99
        )
            ++bad;
        // the 6-foot movement class - the o-yori, metal scale and splinted
        // rows (capture p. 95)
    if (dhfT54Move(16) != 6
            || dhfT54Move(20) != 6
        )
            ++bad;
        // the sune-ate tail row - the 5# weight, no base movement (capture p.
        // 95)
    if (dhfT54Weight(22) != 5
            || dhfT54Move(22) != -99
        )
            ++bad;
        printf("R645 OA encumbrance audit: bad %d\n", bad);
        if (bad) return 1;
    }
