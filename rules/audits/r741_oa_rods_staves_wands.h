    // ---- R741 OA rods staves wands audit ----
    // OA round one hundred twenty-eight (capture p. 288): the Rods, Staves,
    // and Wands section - the Rod of Resurrection charge table, the ten class
    // base charges and the four race pluses as the two paired grids,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlcClassCount() != 10
            || dlcRaceCount() != 4
            || !dlcRodOfResurrection()
            || !dlcChargesClassPlusRace()
        )
            ++bad;
        // the dlcRodClass grid
        int CRodClass[10][2] = {
            {1,3},
            {2,1},
            {3,2},
            {4,4},
            {5,3},
            {6,2},
            {7,1},
            {8,3},
            {9,3},
            {10,3},
            };
        int nRodClass[2] = {0,0};
        int eRodClass[2] = {0,0};
        for (int b = 0;
             b < dlcClassCount();
             ++b) {
            int vals[2];
            vals[0] = dlcClassCode(b);
            vals[1] = dlcClassBase(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CRodClass[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nRodClass[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nRodClass[c] != eRodClass[c])
                ++bad;
        // the dlcRodRace grid
        int CRodRace[4][2] = {
            {1,3},
            {2,4},
            {3,3},
            {4,1},
            };
        int nRodRace[2] = {0,0};
        int eRodRace[2] = {0,0};
        for (int b = 0;
             b < dlcRaceCount();
             ++b) {
            int vals[2];
            vals[0] = dlcRaceCode(b);
            vals[1] = dlcRacePlus(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CRodRace[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nRodRace[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nRodRace[c] != eRodRace[c])
                ++bad;
        // the prose - the rod and the charge law, healthy values, each
        // condition false
    if (dlcRodOfResurrection() != 1
            || dlcChargesClassPlusRace() != 1
        )
            ++bad;
        // the grids - the two charge tables, audited cell by cell by the
        // table audit
    if (dlcClassCount() != 10
            || dlcRaceCount() != 4
            || dlcClassBase(0) != 3
            || dlcClassBase(3) != 4
            || dlcRacePlus(0) != 3
            || dlcRacePlus(1) != 4
        )
            ++bad;
        printf("R741 OA rods staves wands audit: bad %d\n", bad);
        if (bad) return 1;
    }
