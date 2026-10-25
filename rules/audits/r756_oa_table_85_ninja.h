    // ---- R756 OA Table 85 ninja audit ----
    // OA round one hundred forty-three (capture pp. 293-294): the Table 85
    // Ninja Class - the twelve d100 bands of the ninja weapon types, the
    // kawanaga through the small star shuriken, the three shuriken tail,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlrNinjaRowCount() != 12
            || !dlrPageBreakGrid()
            || !dlrShurikenBands()
            || !dlrNinjaToBand()
            || !dlrConcealedWeapons()
        )
            ++bad;
        // the dlrNinjaClass grid
        int CNinjaClass[12][3] = {
            {1,5,1},
            {6,10,2},
            {11,15,3},
            {16,20,4},
            {21,25,5},
            {26,30,6},
            {31,40,7},
            {41,45,8},
            {46,60,9},
            {61,70,10},
            {71,85,11},
            {86,100,12},
            };
        int nNinjaClass[3] = {0,0,0};
        int eNinjaClass[3] = {0,0,0};
        for (int b = 0;
             b < dlrNinjaRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlrNinjaRollMin(b);
            vals[1] = dlrNinjaRollMax(b);
            vals[2] = dlrNinjaCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CNinjaClass[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nNinjaClass[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nNinjaClass[c] != eNinjaClass[c])
                ++bad;
        // the grid - the twelve-band Table 85, audited cell by cell by the
        // table audit
    if (dlrNinjaRowCount() != 12
            || dlrNinjaRollMin(0) != 1
            || dlrNinjaRollMax(11) != 100
            || dlrNinjaCode(0) != 1
            || dlrNinjaCode(11) != 12
        )
            ++bad;
        // the shuriken tail and the quirks, healthy values, each condition
        // false
    if (dlrNinjaRollMin(9) != 61
            || dlrNinjaCode(9) != 10
            || dlrNinjaCode(10) != 11
            || dlrNinjaCode(11) != 12
            || dlrShurikenBands() != 1
            || dlrPageBreakGrid() != 1
            || dlrNinjaToBand() != 1
            || dlrConcealedWeapons() != 1
        )
            ++bad;
        printf("R756 OA Table 85 ninja audit: bad %d\n", bad);
        if (bad) return 1;
    }
