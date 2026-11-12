    // ---- R223: the III.C rings footnote pins audit ----
    // DMG p.127: the (M) magic-user-only
    // mark and the double-dagger
    // charge-limited rows.
    {
        Rings rings;
        int bad = 0;
        // the row identity: the 24 die bands
        if (rings.ringRowCount() != 24) ++bad;
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
            if (rings.ringRowLo(i) != kLo[i] ||
                rings.ringRowHi(i) != kHi[i] ||
                rings.ringIsMuOnly(i) != kMu[i] ||
                rings.ringIsChargeLimited(i) != kChg[i])
                ++bad;
        for (int i = 1; i < 24; ++i)
            if (rings.ringRowLo(i) !=
                rings.ringRowHi(i - 1) + 1) ++bad;
        if (rings.ringRowLo(-5) != 1 ||
            rings.ringRowHi(99) != 100) ++bad;
        // the singleton rows: Djinni
        // Summoning 13-14, Regeneration 61,
        // Wizardry 99, X-Ray Vision 100
        if (rings.ringRowLo(2) != 13 ||
            rings.ringRowHi(2) != 14 ||
            rings.ringRowLo(12) != 61 ||
            rings.ringRowLo(22) != 99 ||
            rings.ringRowHi(22) != 99 ||
            rings.ringRowLo(23) != 100 ||
            rings.ringRowHi(23) != 100) ++bad;
        // the charge rows: the seven
        // double-dagger rings (the R255
        // fix: row 9 Mammal Control IN,
        // row 11 Protection OUT)
        if (rings.ringChargeLimitedCount() != 7) ++bad;
        if (!rings.ringIsChargeLimited(2) ||
            !rings.ringIsChargeLimited(7) ||
            !rings.ringIsChargeLimited(9) ||
            !rings.ringIsChargeLimited(10) ||
            !rings.ringIsChargeLimited(17) ||
            !rings.ringIsChargeLimited(18) ||
            !rings.ringIsChargeLimited(22)) ++bad;
        if (rings.ringIsChargeLimited(0) ||
            rings.ringIsChargeLimited(1) ||
            rings.ringIsChargeLimited(3) ||
            rings.ringIsChargeLimited(11) ||
            rings.ringIsChargeLimited(12) ||
            rings.ringIsChargeLimited(15) ||
            rings.ringIsChargeLimited(23)) ++bad;
        // the (M) row: Wizardry only,
        // and it is ALSO charge-limited
        if (rings.ringMuOnlyCount() != 1) ++bad;
        if (!rings.ringIsMuOnly(22) ||
            !rings.ringIsChargeLimited(22)) ++bad;
        if (rings.ringIsMuOnly(0) ||
            rings.ringIsMuOnly(23)) ++bad;
        // clamped flag reads land on
        // Contrariness and X-Ray Vision:
        // both unmarked
        if (rings.ringIsChargeLimited(-99) ||
            rings.ringIsChargeLimited(99) ||
            rings.ringIsMuOnly(-99)) ++bad;
        printf("R223 rings footnote pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
