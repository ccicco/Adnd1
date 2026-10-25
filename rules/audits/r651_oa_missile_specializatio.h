    // ---- R651 OA missile specializations audit ----
    // OA round thirty-eight (capture p. 100): Table 57 - the missile weapon
    // specializations grid, the specialist attacks-per-round pairs by level
    // band
    {
        using namespace rules;
        int bad = 0;
    if (dhlT57BandCount() != 3
            || dhlT57FirstBandTop() != 6
            || dhlT57SecondBandTop() != 12
        )
            ++bad;
        // the Table 57 grid: the specialist attacks-per-round pairs by level
        // band
        int CT57Data[3][14] = {
            {2,1,1,1,1,2,1,1,3,1,4,1,3,2},
            {3,1,3,2,1,1,3,2,4,1,5,1,2,1},
            {4,1,2,1,3,2,2,1,5,1,6,1,5,2},
            };
        int nT57Data[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int eT57Data[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dhlT57BandCount();
             ++b) {
            int vals[14];
            vals[0] = dhlT57BowNum(b);
            vals[1] = dhlT57BowDen(b);
            vals[2] = dhlT57LightNum(b);
            vals[3] = dhlT57LightDen(b);
            vals[4] = dhlT57PelletHeavyNum(b);
            vals[5] = dhlT57PelletHeavyDen(b);
            vals[6] = dhlT57LassoNum(b);
            vals[7] = dhlT57LassoDen(b);
            vals[8] = dhlT57ShurikenNum(b);
            vals[9] = dhlT57ShurikenDen(b);
            vals[10] = dhlT57DartNum(b);
            vals[11] = dhlT57DartDen(b);
            vals[12] = dhlT57OtherNum(b);
            vals[13] = dhlT57OtherDen(b);
            for (int c = 0; c < 14;
                 ++c) {
                if (vals[c] != CT57Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT57Data[c];
            }
        }
        for (int c = 0; c < 14; ++c)
            if (nT57Data[c] != eT57Data[c])
                ++bad;
        // the level-band pins - three bands, tops at 6 and 12
    if (dhlT57BandCount() != 3
            || dhlT57FirstBandTop() != 6
            || dhlT57SecondBandTop() != 12
        )
            ++bad;
        // the bow row pairs - 2/1, 3/1, 4/1 up the bands (capture p. 100 of
        // the print pass; compressed p. 52)
    if (dhlT57BowNum(0) != 2
            || dhlT57BowDen(0) != 1
            || dhlT57BowNum(1) != 3
            || dhlT57BowDen(1) != 1
            || dhlT57BowNum(2) != 4
            || dhlT57BowDen(2) != 1
        )
            ++bad;
        // the light crossbow row pairs - 1/1, 3/2, 2/1 (capture p. 100)
    if (dhlT57LightNum(0) != 1
            || dhlT57LightDen(0) != 1
            || dhlT57LightNum(1) != 3
            || dhlT57LightDen(1) != 2
            || dhlT57LightNum(2) != 2
            || dhlT57LightDen(2) != 1
        )
            ++bad;
        // the pellet bow & heavy crossbow row pairs - 1/2, 1/1, 3/2 (capture
        // p. 100)
    if (dhlT57PelletHeavyNum(0) != 1
            || dhlT57PelletHeavyDen(0) != 2
            || dhlT57PelletHeavyNum(1) != 1
            || dhlT57PelletHeavyDen(1) != 1
            || dhlT57PelletHeavyNum(2) != 3
            || dhlT57PelletHeavyDen(2) != 2
        )
            ++bad;
        // the lasso & staff sling row pairs - 1/1, 3/2, 2/1 (capture p. 100)
    if (dhlT57LassoNum(0) != 1
            || dhlT57LassoDen(0) != 1
            || dhlT57LassoNum(1) != 3
            || dhlT57LassoDen(1) != 2
            || dhlT57LassoNum(2) != 2
            || dhlT57LassoDen(2) != 1
        )
            ++bad;
        // the large shuriken & thrown dagger row pairs - 3/1, 4/1, 5/1
        // (capture p. 100)
    if (dhlT57ShurikenNum(0) != 3
            || dhlT57ShurikenDen(0) != 1
            || dhlT57ShurikenNum(1) != 4
            || dhlT57ShurikenDen(1) != 1
            || dhlT57ShurikenNum(2) != 5
            || dhlT57ShurikenDen(2) != 1
        )
            ++bad;
        // the dart & small shuriken row pairs - 4/1, 5/1, 6/1 (capture p.
        // 100)
    if (dhlT57DartNum(0) != 4
            || dhlT57DartDen(0) != 1
            || dhlT57DartNum(1) != 5
            || dhlT57DartDen(1) != 1
            || dhlT57DartNum(2) != 6
            || dhlT57DartDen(2) != 1
        )
            ++bad;
        // the other column row pairs - 3/2, 2/1, 5/2 (capture p. 100)
    if (dhlT57OtherNum(0) != 3
            || dhlT57OtherDen(0) != 2
            || dhlT57OtherNum(1) != 2
            || dhlT57OtherDen(1) != 1
            || dhlT57OtherNum(2) != 5
            || dhlT57OtherDen(2) != 2
        )
            ++bad;
        printf("R651 OA missile specializations audit: bad %d\n", bad);
        if (bad) return 1;
    }
