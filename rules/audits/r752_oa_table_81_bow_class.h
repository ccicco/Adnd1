    // ---- R752 OA Table 81 bow class audit ----
    // OA round one hundred thirty-nine (capture p. 292): the Table 81 Bow,
    // Crossbow, And Sling Class - the ten d100 bands of the missile weapon
    // types, the composite shortbow through the staff sling, single-pass pins
    // per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlnBowRowCount() != 10
            || !dlnCompositeShortbowBand()
            || !dlnShortBowBand()
            || !dlnChuKoNuBand()
            || !dlnHeavyCrossbowBand()
            || !dlnLightCrossbowBand()
            || !dlnDaikyuBand()
            || !dlnHankyuBand()
            || !dlnPelletBowBand()
            || !dlnSlingBand()
            || !dlnStaffSlingBand()
        )
            ++bad;
        // the dlnBowClass grid
        int CBowClass[10][3] = {
            {1,15,1},
            {16,30,2},
            {31,31,3},
            {32,45,4},
            {46,60,5},
            {61,80,6},
            {81,90,7},
            {91,91,8},
            {92,96,9},
            {97,100,10},
            };
        int nBowClass[3] = {0,0,0};
        int eBowClass[3] = {0,0,0};
        for (int b = 0;
             b < dlnBowRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlnBowRollMin(b);
            vals[1] = dlnBowRollMax(b);
            vals[2] = dlnBowCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CBowClass[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nBowClass[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nBowClass[c] != eBowClass[c])
                ++bad;
        // the grid - the ten-band Table 81, audited cell by cell by the table
        // audit
    if (dlnBowRowCount() != 10
            || dlnBowRollMin(0) != 1
            || dlnBowRollMax(9) != 100
            || dlnBowCode(0) != 1
            || dlnBowCode(9) != 10
        )
            ++bad;
        // the band walk - the ten missile weapon types, healthy values, each
        // condition false
    if (dlnCompositeShortbowBand() != 1
            || dlnShortBowBand() != 1
            || dlnChuKoNuBand() != 1
            || dlnHeavyCrossbowBand() != 1
            || dlnLightCrossbowBand() != 1
            || dlnDaikyuBand() != 1
            || dlnHankyuBand() != 1
            || dlnPelletBowBand() != 1
            || dlnSlingBand() != 1
            || dlnStaffSlingBand() != 1
        )
            ++bad;
        printf("R752 OA Table 81 bow class audit: bad %d\n", bad);
        if (bad) return 1;
    }
