    // ---- R753 OA Table 82 misc melee audit ----
    // OA round one hundred forty (capture pp. 292-293): the Table 82
    // Miscellaneous - the thirteen d100 bands of the misc melee types, the
    // battle axe through the trident, the nagamaki band carrying the capture
    // Nagasaki misprint pinned as printed, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dloMiscRowCount() != 13
            || !dloMeleeClassBanner()
            || !dloNagasakiMisprint()
            || !dloSingleRollBands()
        )
            ++bad;
        // the dloMiscMelee grid
        int CMiscMelee[13][3] = {
            {1,5,1},
            {6,15,2},
            {16,30,3},
            {31,45,4},
            {46,48,5},
            {49,54,6},
            {55,55,7},
            {56,60,8},
            {61,65,9},
            {66,75,10},
            {76,90,11},
            {91,95,12},
            {96,100,13},
            };
        int nMiscMelee[3] = {0,0,0};
        int eMiscMelee[3] = {0,0,0};
        for (int b = 0;
             b < dloMiscRowCount();
             ++b) {
            int vals[3];
            vals[0] = dloMiscRollMin(b);
            vals[1] = dloMiscRollMax(b);
            vals[2] = dloMiscCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CMiscMelee[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nMiscMelee[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nMiscMelee[c] != eMiscMelee[c])
                ++bad;
        // the grid - the thirteen-band Table 82, audited cell by cell by the
        // table audit
    if (dloMiscRowCount() != 13
            || dloMiscRollMin(0) != 1
            || dloMiscRollMax(12) != 100
            || dloMiscCode(0) != 1
            || dloMiscCode(12) != 13
        )
            ++bad;
        // the quirks - the misprint band and the banner, healthy values, each
        // condition false
    if (dloMiscRollMin(8) != 61
            || dloMiscRollMax(8) != 65
            || dloMiscCode(8) != 9
            || dloNagasakiMisprint() != 1
            || dloMeleeClassBanner() != 1
            || dloSingleRollBands() != 1
        )
            ++bad;
        printf("R753 OA Table 82 misc melee audit: bad %d\n", bad);
        if (bad) return 1;
    }
