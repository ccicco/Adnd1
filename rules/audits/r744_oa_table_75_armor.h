    // ---- R744 OA Table 75 armor audit ----
    // OA round one hundred thirty-one (capture p. 289): the Table 75 Magical
    // Armor - the twenty-three d100 bands of the armor types, the splinted
    // overlap misprint pinned as printed, the gajin armor reroll of the 100
    // row, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlfArmorRowCount() != 23
            || !dlfSodePairAsterisk()
            || !dlfSplintedOverlapMisprint()
            || !dlfGajinArmorRollOnDMG()
        )
            ++bad;
        // the dlfMagicalArmor grid
        int CMagicalArmor[23][3] = {
            {1,4,1},
            {5,5,2},
            {6,12,3},
            {13,16,4},
            {17,17,5},
            {18,22,6},
            {23,26,7},
            {27,30,8},
            {31,35,9},
            {36,44,10},
            {45,46,11},
            {47,55,12},
            {56,62,13},
            {63,66,14},
            {67,70,15},
            {71,74,16},
            {75,78,17},
            {79,82,18},
            {83,86,19},
            {87,87,20},
            {86,92,21},
            {93,99,22},
            {100,100,23},
            };
        int nMagicalArmor[3] = {0,0,0};
        int eMagicalArmor[3] = {0,0,0};
        for (int b = 0;
             b < dlfArmorRowCount();
             ++b) {
            int vals[3];
            vals[0] = dlfArmorRollMin(b);
            vals[1] = dlfArmorRollMax(b);
            vals[2] = dlfArmorType(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CMagicalArmor[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nMagicalArmor[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nMagicalArmor[c] != eMagicalArmor[c])
                ++bad;
        // the grid - the twenty-three-band Table 75, audited cell by cell by
        // the table audit
    if (dlfArmorRowCount() != 23
            || dlfArmorRollMin(0) != 1
            || dlfArmorRollMax(22) != 100
            || dlfArmorType(0) != 1
            || dlfArmorType(22) != 23
        )
            ++bad;
        // the capture quirks - the splinted overlap and the gajin armor row,
        // healthy values, each condition false
    if (dlfArmorRollMin(20) != 86
            || dlfArmorRollMax(20) != 92
            || dlfArmorType(20) != 21
            || dlfArmorType(19) != 20
            || dlfSodePairAsterisk() != 1
            || dlfSplintedOverlapMisprint() != 1
            || dlfGajinArmorRollOnDMG() != 1
        )
            ++bad;
        printf("R744 OA Table 75 armor audit: bad %d\n", bad);
        if (bad) return 1;
    }
