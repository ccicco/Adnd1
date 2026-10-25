    // ---- R637 OA starting money audit ----
    // OA round twenty-four (capture pp. 75-76): the starting money prose and
    // the Table 45 funds grid
    {
        using namespace rules;
        int bad = 0;
    if (dgxT45RowCount() != 10
            || !dgxPcUnusualCapital()
            || !dgxClassFundsRoll()
            || !dgxBarterTranslation()
            || !dgxNinjaAdditionalFunds()
        )
            ++bad;
        // the Table 45 grid: the class funds bounds (capture p. 76)
        int CT45[10][8] = {
            {2,12,1,10,0,0,0,0},
            {0,0,1,5,2,20,1,100},
            {0,0,0,0,4,40,2,200},
            {0,0,1,10,4,40,0,0},
            {1,4,1,10,0,0,0,0},
            {0,0,1,6,1,100,0,0},
            {0,0,1,4,4,40,2,200},
            {1,3,2,20,0,0,0,0},
            {1,2,0,0,0,0,0,0},
            {1,3,2,20,0,0,0,0},
            };
        int nT45[8] = {0,0,0,0,0,0,0,0};
        int eT45[8] = {0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dgxT45RowCount();
             ++b) {
            int vals[8];
            vals[0] = dgxT45ChienLo(b);
            vals[1] = dgxT45ChienHi(b);
            vals[2] = dgxT45TaelLo(b);
            vals[3] = dgxT45TaelHi(b);
            vals[4] = dgxT45YuanLo(b);
            vals[5] = dgxT45YuanHi(b);
            vals[6] = dgxT45FenLo(b);
            vals[7] = dgxT45FenHi(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CT45[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT45[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (nT45[c] != eT45[c])
                ++bad;
        // the dgxT45RowCount pin
    if (dgxT45RowCount() != 10
        )
            ++bad;
        // the dgxPcUnusualCapital pin
    if (dgxPcUnusualCapital() != 1
        )
            ++bad;
        // the dgxClassFundsRoll pin
    if (dgxClassFundsRoll() != 1
        )
            ++bad;
        // the dgxBarterTranslation pin
    if (dgxBarterTranslation() != 1
        )
            ++bad;
        // the dgxNinjaAdditionalFunds pin
    if (dgxNinjaAdditionalFunds() != 1
        )
            ++bad;
        // the T45 samurai row - the 2-12 ch'ien and 1-10 tael (capture p. 76)
    if (dgxT45ChienLo(0) != 2
            || dgxT45ChienHi(0) != 12
            || dgxT45TaelLo(0) != 1
            || dgxT45TaelHi(0) != 10
        )
            ++bad;
        // the T45 shukenja row - the 1-5 tael, 2-20 yuan, 1-100 fen (capture
        // p. 76)
    if (dgxT45TaelLo(1) != 1
            || dgxT45TaelHi(1) != 5
            || dgxT45YuanLo(1) != 2
            || dgxT45YuanHi(1) != 20
            || dgxT45FenLo(1) != 1
            || dgxT45FenHi(1) != 100
        )
            ++bad;
        // the T45 monk row - the 4-40 yuan and 2-200 fen (capture p. 76)
    if (dgxT45YuanLo(2) != 4
            || dgxT45YuanHi(2) != 40
            || dgxT45FenLo(2) != 2
            || dgxT45FenHi(2) != 200
        )
            ++bad;
        // the T45 sohei row - the 1-10 tael and 4-40 yuan (capture p. 76)
    if (dgxT45TaelLo(3) != 1
            || dgxT45TaelHi(3) != 10
            || dgxT45YuanLo(3) != 4
            || dgxT45YuanHi(3) != 40
        )
            ++bad;
        // the T45 kensai row - the 1-4 ch'ien and 1-10 tael (capture p. 76)
    if (dgxT45ChienLo(4) != 1
            || dgxT45ChienHi(4) != 4
            || dgxT45TaelLo(4) != 1
            || dgxT45TaelHi(4) != 10
        )
            ++bad;
        // the T45 barbarian row - the 1-6 tael and 1-100 yuan (capture p. 76)
    if (dgxT45TaelLo(5) != 1
            || dgxT45TaelHi(5) != 6
            || dgxT45YuanLo(5) != 1
            || dgxT45YuanHi(5) != 100
        )
            ++bad;
        // the T45 bushi row - the 1-4 tael, 4-40 yuan, 2-200 fen (capture p.
        // 76)
    if (dgxT45TaelLo(6) != 1
            || dgxT45TaelHi(6) != 4
            || dgxT45YuanLo(6) != 4
            || dgxT45YuanHi(6) != 40
            || dgxT45FenLo(6) != 2
            || dgxT45FenHi(6) != 200
        )
            ++bad;
        // the T45 wu jen and yakuza rows - the identical 1-3 ch'ien and 2-20
        // tael (capture p. 76)
    if (dgxT45ChienLo(7) != 1
            || dgxT45ChienHi(7) != 3
            || dgxT45TaelLo(7) != 2
            || dgxT45TaelHi(7) != 20
            || dgxT45ChienLo(9) != 1
            || dgxT45ChienHi(9) != 3
            || dgxT45TaelLo(9) != 2
            || dgxT45TaelHi(9) != 20
        )
            ++bad;
        // the T45 ninja row - the 1-2 ch'ien alone, ten rows only (capture p.
        // 76)
    if (dgxT45ChienLo(8) != 1
            || dgxT45ChienHi(8) != 2
            || dgxT45TaelLo(8) != 0
            || dgxT45RowCount() != 10
        )
            ++bad;
        printf("R637 OA starting money audit: bad %d\n", bad);
        if (bad) return 1;
    }
