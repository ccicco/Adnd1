    // ---- R223: the III.C rings footnote pins audit ----
    // DMG p.127: the (M) magic-user-only
    // mark and the double-dagger
    // charge-limited rows.
    {
        int bad = 0;
        // the row identity: the 24 die bands
        if (rules::ringRowCount() != 24) ++bad;
        static const int kLo[24] = {
            1, 7, 13, 15, 16, 22, 28, 31, 34, 41,
            44, 45, 61, 62, 64, 66, 70, 76, 78, 80,
            86, 91, 99, 100,
        };
        static const int kHi[24] = {
            6, 12, 14, 15, 21, 27, 30, 33, 40, 43,
            44, 60, 61, 63, 65, 69, 75, 77, 79, 85,
            90, 98, 99, 100,
        };
        static const int kMu[24] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 0,
        };
        static const int kChg[24] = {
            0, 0, 1, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 1, 1, 0,
            0, 0, 1, 0,
        };
        for (int i = 0; i < 24; ++i)
            if (rules::ringRowLo(i) != kLo[i] ||
                rules::ringRowHi(i) != kHi[i] ||
                rules::ringIsMuOnly(i) != kMu[i] ||
                rules::ringIsChargeLimited(i) != kChg[i])
                ++bad;
        for (int i = 1; i < 24; ++i)
            if (rules::ringRowLo(i) !=
                rules::ringRowHi(i - 1) + 1) ++bad;
        if (rules::ringRowLo(-5) != 1 ||
            rules::ringRowHi(99) != 100) ++bad;
        // the singleton rows: Djinni
        // Summoning 13-14, Regeneration 61,
        // Wizardry 99, X-Ray Vision 100
        if (rules::ringRowLo(2) != 13 ||
            rules::ringRowHi(2) != 14 ||
            rules::ringRowLo(12) != 61 ||
            rules::ringRowLo(22) != 99 ||
            rules::ringRowHi(22) != 99 ||
            rules::ringRowLo(23) != 100 ||
            rules::ringRowHi(23) != 100) ++bad;
        // the charge rows: the seven
        // double-dagger rings (the R255
        // fix: row 9 Mammal Control IN,
        // row 11 Protection OUT)
        if (rules::ringChargeLimitedCount() != 7) ++bad;
        if (!rules::ringIsChargeLimited(2) ||
            !rules::ringIsChargeLimited(7) ||
            !rules::ringIsChargeLimited(9) ||
            !rules::ringIsChargeLimited(10) ||
            !rules::ringIsChargeLimited(17) ||
            !rules::ringIsChargeLimited(18) ||
            !rules::ringIsChargeLimited(22)) ++bad;
        if (rules::ringIsChargeLimited(0) ||
            rules::ringIsChargeLimited(1) ||
            rules::ringIsChargeLimited(3) ||
            rules::ringIsChargeLimited(11) ||
            rules::ringIsChargeLimited(12) ||
            rules::ringIsChargeLimited(15) ||
            rules::ringIsChargeLimited(23)) ++bad;
        // the (M) row: Wizardry only,
        // and it is ALSO charge-limited
        if (rules::ringMuOnlyCount() != 1) ++bad;
        if (!rules::ringIsMuOnly(22) ||
            !rules::ringIsChargeLimited(22)) ++bad;
        if (rules::ringIsMuOnly(0) ||
            rules::ringIsMuOnly(23)) ++bad;
        // clamped flag reads land on
        // Contrariness and X-Ray Vision:
        // both unmarked
        if (rules::ringIsChargeLimited(-99) ||
            rules::ringIsChargeLimited(99) ||
            rules::ringIsMuOnly(-99)) ++bad;
        printf("R223 rings footnote pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
