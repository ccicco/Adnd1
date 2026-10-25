    // ---- R224: the III.D rods/staves/wands pins audit ----
    // DMG pp.127-128: the class-usable
    // marks and the full-charges asterisk.
    {
        int bad = 0;
        // the row identity: the 30 die bands
        if (rules::rswRowCount() != 30) ++bad;
        static const int kLo[30] = {
            1, 4, 5, 15, 17, 18, 19, 20, 21, 23,
            24, 25, 28, 32, 34, 35, 39, 42, 45, 48,
            53, 57, 60, 69, 74, 79, 87, 90, 93, 95,
        };
        static const int kHi[30] = {
            3, 4, 14, 16, 17, 18, 19, 20, 22, 23,
            24, 27, 31, 33, 34, 38, 41, 44, 47, 52,
            56, 59, 68, 73, 78, 86, 89, 92, 94, 100,
        };
        static const int kC[30] = {
            1, 1, 0, 0, 1, 0, 1, 1, 1, 0,
            0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kM[30] = {
            1, 1, 0, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 0, 1, 1, 1, 0,
            1, 1, 0, 0, 0, 0, 1, 1, 0, 0,
        };
        static const int kF[30] = {
            0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kT[30] = {
            0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kAny[30] = {
            0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
            0, 0, 1, 1, 1, 1, 0, 0, 1, 1,
        };
        for (int i = 0; i < 30; ++i)
            if (rules::rswRowLo(i) != kLo[i] ||
                rules::rswRowHi(i) != kHi[i] ||
                rules::rswUsableByCleric(i) != kC[i] ||
                rules::rswUsableByMagicUser(i) != kM[i] ||
                rules::rswUsableByFighter(i) != kF[i] ||
                rules::rswUsableByThief(i) != kT[i] ||
                rules::rswAnyClass(i) != kAny[i]) ++bad;
        for (int i = 1; i < 30; ++i)
            if (rules::rswRowLo(i) !=
                rules::rswRowHi(i - 1) + 1) ++bad;
        if (rules::rswRowLo(-5) != 1 ||
            rules::rswRowHi(99) != 100) ++bad;
        // every row: the any flag excludes
        // the class marks, and a non-any row
        // carries at least one class mark
        for (int i = 0; i < 30; ++i)
            if (rules::rswAnyClass(i) &&
                (rules::rswUsableByCleric(i) ||
                 rules::rswUsableByMagicUser(i) ||
                 rules::rswUsableByFighter(i) ||
                 rules::rswUsableByThief(i))) ++bad;
        for (int i = 0; i < 30; ++i)
            if (!rules::rswAnyClass(i) &&
                !rules::rswUsableByCleric(i) &&
                !rules::rswUsableByMagicUser(i) &&
                !rules::rswUsableByFighter(i) &&
                !rules::rswUsableByThief(i)) ++bad;
        // the famous rows: Absorption (C, M),
        // Beguiling (C, M, T), Cancellation
        // (any), Lordly Might (F), Smiting
        // (C, F), the Magi (M), Wonder (any)
        if (!rules::rswUsableByCleric(0) ||
            !rules::rswUsableByMagicUser(0) ||
            rules::rswAnyClass(0)) ++bad;
        if (!rules::rswUsableByThief(1)) ++bad;
        if (!rules::rswAnyClass(2) ||
            rules::rswUsableByCleric(2)) ++bad;
        if (!rules::rswUsableByFighter(3) ||
            rules::rswUsableByCleric(3) ||
            rules::rswUsableByMagicUser(3)) ++bad;
        if (!rules::rswUsableByCleric(6) ||
            !rules::rswUsableByFighter(6)) ++bad;
        if (!rules::rswUsableByMagicUser(9) ||
            rules::rswUsableByCleric(9)) ++bad;
        if (!rules::rswAnyClass(29) ||
            rules::rswUsableByThief(29)) ++bad;
        // clamped flag reads land on
        // Absorption (C, M) and Wonder (any)
        if (!rules::rswUsableByCleric(-99) ||
            rules::rswAnyClass(-99) ||
            rules::rswUsableByCleric(99) ||
            !rules::rswAnyClass(99)) ++bad;
        // the full-charges asterisk
        if (!rules::rswFullChargesAssumed()) ++bad;
        printf("R224 rods staves wands pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
