    // ---- R697 OA yearly events audit ----
    // OA round eighty-four (capture p. 237): Table 71 - the yearly events
    // grid, the nineteen events across the percentile die with the contiguous
    // ranges, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djkOA71EventCount() != 19
            || djkOA71WarMin() != 89
            || djkOA71WarMax() != 100
            || !djkOA71OnePerYear()
            || !djkOA71Month1d12()
            || !djkOA71CampaignAreaOnly()
        )
            ++bad;
        // the Table 71 grid - the nineteen events across two columns
        int COA71Data[19][2] = {
            {1,10},
            {11,15},
            {16,30},
            {31,31},
            {32,40},
            {41,43},
            {44,47},
            {48,52},
            {53,57},
            {58,58},
            {59,68},
            {69,69},
            {70,74},
            {75,78},
            {79,85},
            {86,86},
            {87,87},
            {88,88},
            {89,100},
            };
        for (int b = 0;
             b < djkOA71EventCount();
             ++b) {
            int vals[2];
            vals[0] = djkOA71MinRoll(b);
            vals[1] = djkOA71MaxRoll(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != COA71Data[b][c])
                    ++bad;
            }
        }
        // the wide ranges - Ambassador 1-10, Birth 16-30, War 89-100
    if (djkOA71MinRoll(0) != 1
            || djkOA71MaxRoll(0) != 10
            || djkOA71MinRoll(2) != 16
            || djkOA71MaxRoll(2) != 30
            || djkOA71MinRoll(18) != 89
            || djkOA71MaxRoll(18) != 100
        )
            ++bad;
        // the single-roll events - Comet 31, Incursion 58, New Religion 69,
        // Tsunami 86, Visitation 87, Volcano 88
    if (djkOA71MinRoll(3) != 31
            || djkOA71MaxRoll(3) != 31
            || djkOA71MaxRoll(9) != 58
            || djkOA71MaxRoll(11) != 69
            || djkOA71MaxRoll(15) != 86
            || djkOA71MaxRoll(16) != 87
            || djkOA71MaxRoll(17) != 88
        )
            ++bad;
        // the middle events - Earthquake 41-43, Famine 44-47, Fire 48-52,
        // Flood 53-57, Marriage 59-68
    if (djkOA71MinRoll(5) != 41
            || djkOA71MaxRoll(5) != 43
            || djkOA71MinRoll(6) != 44
            || djkOA71MaxRoll(7) != 52
            || djkOA71MinRoll(8) != 53
            || djkOA71MaxRoll(8) != 57
            || djkOA71MinRoll(10) != 59
            || djkOA71MaxRoll(10) != 68
        )
            ++bad;
        // the late events - Plague 70-74, Political Plot 75-78, Rebellion
        // 79-85
    if (djkOA71MinRoll(12) != 70
            || djkOA71MaxRoll(12) != 74
            || djkOA71MinRoll(13) != 75
            || djkOA71MaxRoll(13) != 78
            || djkOA71MinRoll(14) != 79
            || djkOA71MaxRoll(14) != 85
        )
            ++bad;
        // the contiguity - each row beginning where the last ended, the 100
        // the close
    if (djkOA71MaxRoll(0) + 1 != djkOA71MinRoll(1)
            || djkOA71MaxRoll(4) + 1 != djkOA71MinRoll(5)
            || djkOA71MaxRoll(18) != 100
            || djkOA71EventCount() != 19
            || djkOA71WarMin() != 89
            || djkOA71WarMax() != 100
        )
            ++bad;
        printf("R697 OA yearly events audit: bad %d\n", bad);
        if (bad) return 1;
    }
