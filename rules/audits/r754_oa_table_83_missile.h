    // ---- R754 OA Table 83 missile audit ----
    // OA round one hundred forty-one (capture p. 293): the Table 83 Missile
    // Class - the twelve d100 bands of the missile types, the five arrow
    // types through the uchi-ne, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlpMissileRowCount() != 12
            || !dlpArrowBands()
            || !dlpSingleRollBands()
            || !dlpUchiNeTail()
        )
            ++bad;
        // the dlpMissileClass grid
        int CMissileClass[12][3] = {
            {1,10,1},
            {11,20,2},
            {21,25,3},
            {26,40,4},
            {41,60,5},
            {61,70,6},
            {71,71,7},
            {72,72,8},
            {73,77,9},
            {78,90,10},
            {91,98,11},
            {99,100,12},
            };
        int nMissileClass[3] = {0,0,0};
        int eMissileClass[3] = {0,0,0};
        for (int b = 0;
             b < dlpMissileRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlpMissileRollMin(b);
            vals[1] = dlpMissileRollMax(b);
            vals[2] = dlpMissileCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CMissileClass[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nMissileClass[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nMissileClass[c] != eMissileClass[c])
                ++bad;
        // the grid - the twelve-band Table 83, audited cell by cell by the
        // table audit
    if (dlpMissileRowCount() != 12
            || dlpMissileRollMin(0) != 1
            || dlpMissileRollMax(11) != 100
            || dlpMissileCode(0) != 1
            || dlpMissileCode(11) != 12
        )
            ++bad;
        // the quirks - the arrow stretch, the single-roll bands, and the
        // tail, healthy values, each condition false
    if (dlpMissileRollMax(4) != 60
            || dlpMissileCode(4) != 5
            || dlpMissileRollMin(6) != 71
            || dlpMissileRollMax(7) != 72
            || dlpArrowBands() != 1
            || dlpSingleRollBands() != 1
            || dlpUchiNeTail() != 1
        )
            ++bad;
        printf("R754 OA Table 83 missile audit: bad %d\n", bad);
        if (bad) return 1;
    }
