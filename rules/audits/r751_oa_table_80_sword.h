    // ---- R751 OA Table 80 sword audit ----
    // OA round one hundred thirty-eight (capture p. 292): the Table 80 Sword
    // Class - the seven d100 bands of the sword types, the katana through the
    // wakizashi, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlmSwordRowCount() != 7
            || !dlmKatanaBand()
            || !dlmParangBand()
            || !dlmBroadSwordBand()
            || !dlmLongSwordBand()
            || !dlmShortSwordBand()
            || !dlmTwoHandedSwordBand()
            || !dlmWakizashiBand()
        )
            ++bad;
        // the dlmSwordClass grid
        int CSwordClass[7][3] = {
            {1,30,1},
            {31,35,2},
            {36,50,3},
            {51,65,4},
            {66,80,5},
            {81,85,6},
            {86,100,7},
            };
        int nSwordClass[3] = {0,0,0};
        int eSwordClass[3] = {0,0,0};
        for (int b = 0;
             b < dlmSwordRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlmSwordRollMin(b);
            vals[1] = dlmSwordRollMax(b);
            vals[2] = dlmSwordCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CSwordClass[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nSwordClass[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nSwordClass[c] != eSwordClass[c])
                ++bad;
        // the grid - the seven-band Table 80, audited cell by cell by the
        // table audit
    if (dlmSwordRowCount() != 7
            || dlmSwordRollMin(0) != 1
            || dlmSwordRollMax(6) != 100
            || dlmSwordCode(0) != 1
            || dlmSwordCode(6) != 7
        )
            ++bad;
        // the band walk - the seven sword types, healthy values, each
        // condition false
    if (dlmKatanaBand() != 1
            || dlmParangBand() != 1
            || dlmBroadSwordBand() != 1
            || dlmLongSwordBand() != 1
            || dlmShortSwordBand() != 1
            || dlmTwoHandedSwordBand() != 1
            || dlmWakizashiBand() != 1
        )
            ++bad;
        printf("R751 OA Table 80 sword audit: bad %d\n", bad);
        if (bad) return 1;
    }
