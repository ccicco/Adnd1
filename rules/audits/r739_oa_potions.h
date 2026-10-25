    // ---- R739 OA potions audit ----
    // OA round one hundred twenty-six (capture pp. 287-288): the Potions
    // section - the dragon control potion with its twelve-band d20 table, the
    // hill giant giant control, the human control table of seven bands with
    // the gajin DMG-table row, the undead control reroll, single-pass pins
    // per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlaDragonRowCount() != 12
            || dlaHumanRowCount() != 7
            || !dlaDragonControlExists()
            || !dlaNotSameDragonsAsDMG()
            || !dlaUseTableBelow()
            || !dlaChiangLung()
            || !dlaPanLung()
            || !dlaYuLung()
            || !dlaShenLung()
            || !dlaLiLung()
            || !dlaMistDragon()
            || !dlaCloudDragon()
            || !dlaLungWang()
            || !dlaTienLung()
            || !dlaGiantControlHillGiant()
            || !dlaHumanControlIntro()
            || !dlaGajinRollOnDMG()
            || !dlaUndeadControlRerolled()
        )
            ++bad;
        // the dlaDragonControl grid
        int CDragonControl[12][3] = {
            {1,2,1},
            {3,4,2},
            {5,7,3},
            {8,9,4},
            {10,10,5},
            {11,12,6},
            {13,14,7},
            {15,15,8},
            {16,16,9},
            {17,17,10},
            {18,19,11},
            {20,20,12},
            };
        int nDragonControl[3] = {0,0,0};
        int eDragonControl[3] = {0,0,0};
        for (int b = 0;
             b < dlaDragonRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlaDragonRollMin(b);
            vals[1] = dlaDragonRollMax(b);
            vals[2] = dlaDragonCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CDragonControl[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nDragonControl[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nDragonControl[c] != eDragonControl[c])
                ++bad;
        // the dlaHumanControl grid
        int CHumanControl[7][3] = {
            {1,2,1},
            {3,5,2},
            {6,6,3},
            {7,15,4},
            {16,16,5},
            {17,19,6},
            {20,20,7},
            };
        int nHumanControl[3] = {0,0,0};
        int eHumanControl[3] = {0,0,0};
        for (int b = 0;
             b < dlaHumanRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlaHumanRollMin(b);
            vals[1] = dlaHumanRollMax(b);
            vals[2] = dlaHumanCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CHumanControl[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nHumanControl[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nHumanControl[c] != eHumanControl[c])
                ++bad;
        // the dragon control prose and the band bools, healthy values, each
        // condition false
    if (dlaDragonControlExists() != 1
            || dlaNotSameDragonsAsDMG() != 1
            || dlaUseTableBelow() != 1
            || dlaChiangLung() != 1
            || dlaPanLung() != 1
            || dlaYuLung() != 1
            || dlaShenLung() != 1
            || dlaLiLung() != 1
            || dlaMistDragon() != 1
            || dlaCloudDragon() != 1
            || dlaLungWang() != 1
            || dlaTienLung() != 1
        )
            ++bad;
        // the giant, human, and undead notes, healthy values, each condition
        // false
    if (dlaGiantControlHillGiant() != 1
            || dlaHumanControlIntro() != 1
            || dlaGajinRollOnDMG() != 1
            || dlaUndeadControlRerolled() != 1
        )
            ++bad;
        // the grids - the two potion tables, audited cell by cell by the
        // table audit
    if (dlaDragonRowCount() != 12
            || dlaHumanRowCount() != 7
            || dlaDragonRollMin(0) != 1
            || dlaDragonRollMax(11) != 20
            || dlaHumanRollMin(0) != 1
            || dlaHumanRollMax(6) != 20
        )
            ++bad;
        printf("R739 OA potions audit: bad %d\n", bad);
        if (bad) return 1;
    }
