    // ---- R749 OA Table 78 weapons audit ----
    // OA round one hundred thirty-six (capture p. 291): the Table 78 Magical
    // Weapons - the six d100 bands of the weapon classes, the sword through
    // the ninja, each class pointing to its specific type table, single-pass
    // pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlkClassRowCount() != 6
            || !dlkSwordClass()
            || !dlkBowCrossbowSlingClass()
            || !dlkMiscMeleeClass()
            || !dlkMissileClass()
            || !dlkMartialArtsClass()
            || !dlkNinjaClass()
        )
            ++bad;
        // the dlkWeaponClasses grid
        int CWeaponClasses[6][3] = {
            {1,40,1},
            {41,52,2},
            {53,68,3},
            {69,80,4},
            {81,90,5},
            {91,100,6},
            };
        int nWeaponClasses[3] = {0,0,0};
        int eWeaponClasses[3] = {0,0,0};
        for (int b = 0;
             b < dlkClassRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlkClassRollMin(b);
            vals[1] = dlkClassRollMax(b);
            vals[2] = dlkClassCode(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CWeaponClasses[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nWeaponClasses[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nWeaponClasses[c] != eWeaponClasses[c])
                ++bad;
        // the grid - the six-band Table 78, audited cell by cell by the table
        // audit
    if (dlkClassRowCount() != 6
            || dlkClassRollMin(0) != 1
            || dlkClassRollMax(5) != 100
            || dlkClassCode(0) != 1
            || dlkClassCode(5) != 6
        )
            ++bad;
        // the class walk - the six weapon classes, healthy values, each
        // condition false
    if (dlkSwordClass() != 1
            || dlkBowCrossbowSlingClass() != 1
            || dlkMiscMeleeClass() != 1
            || dlkMissileClass() != 1
            || dlkMartialArtsClass() != 1
            || dlkNinjaClass() != 1
        )
            ++bad;
        printf("R749 OA Table 78 weapons audit: bad %d\n", bad);
        if (bad) return 1;
    }
