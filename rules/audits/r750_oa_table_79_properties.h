    // ---- R750 OA Table 79 properties audit ----
    // OA round one hundred thirty-seven (capture pp. 291-292): the Table 79
    // Weapon Properties - the twenty d100 bands by the five weapon-type
    // columns, the quality and plus grades through the special rows and the
    // roll-twice tails, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dllPropRowCount() != 20
            || !dllBowColumn()
            || !dllMissileColumn()
            || !dllMeleeColumn()
            || !dllMartialArtsColumn()
            || !dllNinjaColumn()
            || !dllRollTwiceTails()
        )
            ++bad;
        // the dllWeaponProps grid
        int CWeaponProps[20][7] = {
            {1,5,1,8,1,1,1},
            {6,10,1,8,1,1,1},
            {11,15,1,8,1,1,1},
            {16,20,1,8,1,1,2},
            {21,25,1,8,1,1,2},
            {26,30,1,8,2,2,2},
            {31,35,5,8,2,2,2},
            {36,40,5,8,2,2,2},
            {41,45,5,8,2,2,3},
            {46,50,5,9,2,2,3},
            {51,55,5,9,3,2,3},
            {56,60,6,9,3,3,3},
            {61,65,6,9,3,3,4},
            {66,70,7,9,4,3,4},
            {71,75,2,10,4,4,4},
            {76,80,3,2,11,14,15},
            {81,85,13,2,12,16,17},
            {86,90,18,3,19,20,21},
            {91,95,22,4,13,20,23},
            {96,100,14,24,25,26,26},
            };
        int nWeaponProps[7] = {0,0,0,0,0,0,0};
        int eWeaponProps[7] = {0,0,0,0,0,0,0};
        for (int b = 0;
             b < dllPropRowCount();
             ++b) {
            int vals[7];
            vals[0] = dllPropRollMin(b);
            vals[1] = dllPropRollMax(b);
            vals[2] = dllPropBow(b);
            vals[3] = dllPropMissile(b);
            vals[4] = dllPropMelee(b);
            vals[5] = dllPropMartialArts(b);
            vals[6] = dllPropNinja(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CWeaponProps[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nWeaponProps[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nWeaponProps[c] != eWeaponProps[c])
                ++bad;
        // the grid - the twenty-band Table 79, audited cell by cell by the
        // table audit
    if (dllPropRowCount() != 20
            || dllPropRollMin(0) != 1
            || dllPropRollMax(19) != 100
            || dllPropBow(0) != 1
            || dllPropMissile(0) != 8
            || dllPropMelee(14) != 4
            || dllPropMartialArts(19) != 26
            || dllPropNinja(19) != 26
        )
            ++bad;
        // the special rows - the 76-100 stretch of the special properties,
        // healthy values, each condition false
    if (dllPropBow(15) != 3
            || dllPropMelee(15) != 11
            || dllPropBow(16) != 13
            || dllPropMelee(16) != 12
            || dllPropBow(18) != 22
            || dllPropMelee(18) != 13
            || dllPropMissile(19) != 24
            || dllPropMelee(19) != 25
            || dllRollTwiceTails() != 1
        )
            ++bad;
        printf("R750 OA Table 79 properties audit: bad %d\n", bad);
        if (bad) return 1;
    }
