    // ---- R742 OA misc magic audit ----
    // OA round one hundred twenty-nine (capture pp. 288-289): the
    // Miscellaneous Magic section - the six rerolled or absent items, the
    // Bucknard's everful purse with its three-band contents table,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dldPurseRowCount() != 3
            || !dldBootsOfElvenkindRerolled()
            || !dldBroomOfAnimatedAttackRerolled()
            || !dldBroomOfFlyingRerolled()
            || !dldEverfulPurseIntro()
            || !dldCloakOfElvenkindRerolled()
            || !dldInstrumentsOfTheBardsRerolled()
            || !dldManualOfGolemsRerolled()
        )
            ++bad;
        // the dldEverfulPurse grid
        int CEverfulPurse[3][7] = {
            {1,50,0,10,5,1,0},
            {51,90,20,0,5,2,0},
            {91,100,20,0,5,0,10},
            };
        int nEverfulPurse[7] = {0,0,0,0,0,0,0};
        int eEverfulPurse[7] = {0,0,1,2,0,1,2};
        for (int b = 0;
             b < dldPurseRowCount();
             ++b) {
            int vals[7];
            vals[0] = dldPurseRollMin(b);
            vals[1] = dldPurseRollMax(b);
            vals[2] = dldPurseFen(b);
            vals[3] = dldPurseYuan(b);
            vals[4] = dldPurseTael(b);
            vals[5] = dldPurseChien(b);
            vals[6] = dldPurseGems(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CEverfulPurse[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nEverfulPurse[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nEverfulPurse[c] != eEverfulPurse[c])
                ++bad;
        // the rerolled and absent items, healthy values, each condition false
    if (dldBootsOfElvenkindRerolled() != 1
            || dldBroomOfAnimatedAttackRerolled() != 1
            || dldBroomOfFlyingRerolled() != 1
            || dldCloakOfElvenkindRerolled() != 1
            || dldInstrumentsOfTheBardsRerolled() != 1
            || dldManualOfGolemsRerolled() != 1
        )
            ++bad;
        // the purse - the three-band contents table, audited cell by cell by
        // the table audit
    if (dldPurseRowCount() != 3
            || dldPurseYuan(0) != 10
            || dldPurseChien(1) != 2
            || dldPurseGems(2) != 10
            || dldPurseTael(2) != 5
        )
            ++bad;
        printf("R742 OA misc magic audit: bad %d\n", bad);
        if (bad) return 1;
    }
