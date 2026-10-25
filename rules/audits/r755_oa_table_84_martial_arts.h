    // ---- R755 OA Table 84 martial arts audit ----
    // OA round one hundred forty-two (capture p. 293): the Table 84 Martial
    // Arts Class - the twelve d100 bands of the martial arts weapon types,
    // the chain through the tui-fa, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlqMartialArtsRowCount() != 12
            || !dlqChainToFangHead()
            || !dlqNunchakuBand()
            || !dlqSaiBand()
            || !dlqThreePieceRodBand()
            || !dlqTuiFaTail()
        )
            ++bad;
        // the dlqMartialArtsClass grid
        int CMartialArtsClass[12][3] = {
            {1,5,1},
            {6,10,2},
            {11,20,3},
            {21,30,4},
            {31,35,5},
            {36,40,6},
            {41,55,7},
            {56,70,8},
            {71,75,9},
            {76,80,10},
            {81,90,11},
            {91,100,12},
            };
        int nMartialArtsClass[3] = {0,0,0};
        int eMartialArtsClass[3] = {0,0,0};
        for (int b = 0;
             b < dlqMartialArtsRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlqMartialArtsRollMin(b);
            vals[1] = dlqMartialArtsRollMax(b);
            vals[2] = dlqMartialArtsCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CMartialArtsClass[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nMartialArtsClass[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nMartialArtsClass[c] != eMartialArtsClass[c])
                ++bad;
        // the grid - the twelve-band Table 84, audited cell by cell by the
        // table audit
    if (dlqMartialArtsRowCount() != 12
            || dlqMartialArtsRollMin(0) != 1
            || dlqMartialArtsRollMax(11) != 100
            || dlqMartialArtsCode(0) != 1
            || dlqMartialArtsCode(11) != 12
        )
            ++bad;
        // the band walk - the key bands, healthy values, each condition false
    if (dlqChainToFangHead() != 1
            || dlqMartialArtsRollMax(6) != 55
            || dlqMartialArtsCode(6) != 7
            || dlqNunchakuBand() != 1
            || dlqSaiBand() != 1
            || dlqThreePieceRodBand() != 1
            || dlqTuiFaTail() != 1
        )
            ++bad;
        printf("R755 OA Table 84 martial arts audit: bad %d\n", bad);
        if (bad) return 1;
    }
