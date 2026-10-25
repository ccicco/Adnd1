    // ---- R746 OA Table 77 special audit ----
    // OA round one hundred thirty-three (capture p. 290): the Table 77
    // Special Properties - the eleven d100 bands, the etherealness through
    // the healing, the three versus-missiles grades, the possession band
    // whose mechanics ride in the Explanation prose, single-pass pins per the
    // Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlhSpecialRowCount() != 11
            || !dlhEtherealnessBand()
            || !dlhVersusMissilesBands()
            || !dlhVulnerabilityBand()
            || !dlhMissileAttractionBand()
            || !dlhPresenceBand()
            || !dlhBlendingBand()
            || !dlhFearBand()
            || !dlhPossessionBand()
            || !dlhHealingBand()
        )
            ++bad;
        // the dlhSpecialProps grid
        int CSpecialProps[11][3] = {
            {1,5,1},
            {6,30,2},
            {31,40,3},
            {41,50,4},
            {51,65,5},
            {66,75,6},
            {76,80,7},
            {81,85,8},
            {86,90,9},
            {91,95,10},
            {96,100,11},
            };
        int nSpecialProps[3] = {0,0,0};
        int eSpecialProps[3] = {0,0,0};
        for (int b = 0;
             b < dlhSpecialRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlhSpecialRollMin(b);
            vals[1] = dlhSpecialRollMax(b);
            vals[2] = dlhSpecialCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CSpecialProps[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nSpecialProps[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nSpecialProps[c] != eSpecialProps[c])
                ++bad;
        // the grid - the eleven-band Table 77, audited cell by cell by the
        // table audit
    if (dlhSpecialRowCount() != 11
            || dlhSpecialRollMin(0) != 1
            || dlhSpecialRollMax(10) != 100
            || dlhSpecialCode(0) != 1
            || dlhSpecialCode(10) != 11
        )
            ++bad;
        // the band bools - the eleven special properties walked, healthy
        // values, each condition false
    if (dlhEtherealnessBand() != 1
            || dlhVersusMissilesBands() != 1
            || dlhVulnerabilityBand() != 1
            || dlhMissileAttractionBand() != 1
            || dlhPresenceBand() != 1
            || dlhBlendingBand() != 1
            || dlhFearBand() != 1
            || dlhPossessionBand() != 1
            || dlhHealingBand() != 1
        )
            ++bad;
        printf("R746 OA Table 77 special audit: bad %d\n", bad);
        if (bad) return 1;
    }
