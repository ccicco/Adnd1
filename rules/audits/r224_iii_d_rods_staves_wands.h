    // ---- R224: the III.D rods/staves/wands pins audit ----
    // DMG pp.127-128: the class-usable
    // marks and the full-charges asterisk.
    {
        Rodswands rodswands;
        int bad = 0;
        // the row identity: the 30 die bands
        if (rodswands.rswRowCount() != 30) ++bad;
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
            if (rodswands.rswRowLo(i) != kLo[i] ||
                rodswands.rswRowHi(i) != kHi[i] ||
                rodswands.rswUsableByCleric(i) != kC[i] ||
                rodswands.rswUsableByMagicUser(i) != kM[i] ||
                rodswands.rswUsableByFighter(i) != kF[i] ||
                rodswands.rswUsableByThief(i) != kT[i] ||
                rodswands.rswAnyClass(i) != kAny[i]) ++bad;
        for (int i = 1; i < 30; ++i)
            if (rodswands.rswRowLo(i) !=
                rodswands.rswRowHi(i - 1) + 1) ++bad;
        if (rodswands.rswRowLo(-5) != 1 ||
            rodswands.rswRowHi(99) != 100) ++bad;
        // every row: the any flag excludes
        // the class marks, and a non-any row
        // carries at least one class mark
        for (int i = 0; i < 30; ++i)
            if (rodswands.rswAnyClass(i) &&
                (rodswands.rswUsableByCleric(i) ||
                 rodswands.rswUsableByMagicUser(i) ||
                 rodswands.rswUsableByFighter(i) ||
                 rodswands.rswUsableByThief(i))) ++bad;
        for (int i = 0; i < 30; ++i)
            if (!rodswands.rswAnyClass(i) &&
                !rodswands.rswUsableByCleric(i) &&
                !rodswands.rswUsableByMagicUser(i) &&
                !rodswands.rswUsableByFighter(i) &&
                !rodswands.rswUsableByThief(i)) ++bad;
        // the famous rows: Absorption (C, M),
        // Beguiling (C, M, T), Cancellation
        // (any), Lordly Might (F), Smiting
        // (C, F), the Magi (M), Wonder (any)
        if (!rodswands.rswUsableByCleric(0) ||
            !rodswands.rswUsableByMagicUser(0) ||
            rodswands.rswAnyClass(0)) ++bad;
        if (!rodswands.rswUsableByThief(1)) ++bad;
        if (!rodswands.rswAnyClass(2) ||
            rodswands.rswUsableByCleric(2)) ++bad;
        if (!rodswands.rswUsableByFighter(3) ||
            rodswands.rswUsableByCleric(3) ||
            rodswands.rswUsableByMagicUser(3)) ++bad;
        if (!rodswands.rswUsableByCleric(6) ||
            !rodswands.rswUsableByFighter(6)) ++bad;
        if (!rodswands.rswUsableByMagicUser(9) ||
            rodswands.rswUsableByCleric(9)) ++bad;
        if (!rodswands.rswAnyClass(29) ||
            rodswands.rswUsableByThief(29)) ++bad;
        // clamped flag reads land on
        // Absorption (C, M) and Wonder (any)
        if (!rodswands.rswUsableByCleric(-99) ||
            rodswands.rswAnyClass(-99) ||
            rodswands.rswUsableByCleric(99) ||
            !rodswands.rswAnyClass(99)) ++bad;
        // the full-charges asterisk
        if (!rodswands.rswFullChargesAssumed()) ++bad;
        printf("R224 rods staves wands pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
