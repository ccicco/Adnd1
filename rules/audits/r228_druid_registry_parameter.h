    // ---- R228: the druid registry parameters audit ----
    // The evaluable seam walk: the rules/druidspells.h
    // R228 parameter tables vs the book-pin arrays (the
    // PHB spell description headers). The registry rows
    // themselves are walked by the extended R80 battery
    // block - spells.cpp structs are outside the
    // audit_eval subset.
    {
        int bad = 0;
        static const int kLv[77] = {
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 5, 5,
            5, 5, 5, 5, 5, 5, 6, 6, 6, 6,
            6, 6, 6, 6, 6, 6, 6, 6, 7, 7,
            7, 7, 7, 7, 7, 7, 7,
        };
        static const int kRv[77] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
            0, 1, 0, 0, 1, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
            1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 1, 0, 0,
        };
        static const int kCt[77] = {
            360, 3, 3, 3, 3, 4, 10, 10, 10, 10,
            1, 3, 3, 4, 60, 4, 3, 60, 4, 10,
            4, 4, 4, 4, 60, 10, 5, 5, 10, 5,
            5, 30, 10, 10, 5, 5, 6, 0, 6, 6,
            6, 6, 6, 6, 6, 6, 10, 60, 7, 7,
            7, 60, 7, 5, 60, 7, 8, 10, 7, 60,
            7, 8, 8, 3, 8, 8, 60, 60, 60, 9,
            60, 60, 9, 5, 9, 60, 9,
        };
        static const int kRg[77] = {
            1, 0, 0, 8, 8, 0, 0, 0, 0, 4,
            0, 0, 0, 8, 1, 0, 1, 0, 4, 0,
            0, 0, 0, 1, 0, 0, 8, 0, 16, 0,
            16, 0, 0, 3, 0, 0, 4, 12, 0, 0,
            8, 8, 8, 0, 4, 0, 0, 0, 8, 6,
            0, 0, 0, 32, 8, 0, 8, 0, 4, 8,
            16, 0, 16, 0, 0, 8, 0, 8, 4, 4,
            0, 1, 0, 6, 16, 0, 8,
        };
        static const int kDu[77] = {
            0, 12, 4, 10, 4, 10, 1, 10, 120, 0,
            1, 2, 4, 0, 0, 0, 4, 0, 7, 10,
            4, 2, 10, 0, 10, 0, 2, 0, 0, 0,
            0, 0, 0, 1, 60, 60, 0, 0, 40, 0,
            0, 0, 1, 10, 1, 0, 10, 2, 2, 0,
            10, 0, 10, 10, 0, 0, 0, 10, 2, 10,
            0, 0, 0, 0, 4, 10, 0, 1, 1, 10,
            0, 60, 4, 0, 1, 0, 0,
        };
        static const int kAo[77] = {
            0, 0, 0, 2, 4, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 36, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 1, 4, 0, 0,
            1, 0, 0, 2, 0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0,
        };
        static const int kSv[77] = {
            4, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, 4, -1, -1, -1, 4, -1, -1,
            -1, -1, 4, -1, 4, -1, 4, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, 4, -1, -1,
            -1, -1, 4, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, 4, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, 4, 4, -1, -1,
        };
        static const int kTg[77] = {
            1, 2, 2, 2, 2, 1, 2, 1, 4, 2,
            4, 1, 1, 1, 2, 1, 1, 4, 4, 2,
            4, 4, 4, 4, 2, 1, 1, 1, 2, 1,
            4, 2, 2, 4, 0, 1, 4, 4, 2, 1,
            2, 2, 4, 4, 2, 1, 2, 2, 2, 4,
            2, 4, 2, 2, 4, 4, 4, 2, 2, 4,
            2, 1, 1, 4, 2, 2, 4, 2, 4, 4,
            4, 4, 4, 1, 2, 1, 4,
        };
        for (int i = 0; i < 77; ++i)
            if (rules::druidSpellLevel(i) != kLv[i] ||
                rules::druidSpellRev(i) != kRv[i] ||
                rules::druidSpellCt(i) != kCt[i] ||
                rules::druidSpellRangeTens(i) != kRg[i] ||
                rules::druidSpellDur(i) != kDu[i] ||
                rules::druidSpellAoeTens(i) != kAo[i] ||
                rules::druidSpellSaveCat(i) != kSv[i] ||
                rules::druidSpellTarget(i) != kTg[i]) ++bad;
        // the clamps: -5 and 99 read rows 0 and 76
        if (rules::druidSpellLevel(-5) != kLv[0] ||
            rules::druidSpellLevel(99) != kLv[76] ||
            rules::druidSpellCt(99) != kCt[76]) ++bad;
        // the level histogram ladder: the seam pins
        // the printed roster counts (12/12/12/12/8/
        // 12/9 - R182); every seam level sits in 1..7
        // (the reversible count 16 and the 11 Neg./
        // half saves are properties of the pin arrays
        // above, walked cellwise)
        static const int kHist[7] = { 12, 12, 12, 12, 8, 12, 9 };
        for (int l = 1; l <= 7; ++l)
            if (rules::druidSpellCountByLevel(l) != kHist[l - 1]) ++bad;
        for (int i = 0; i < 77; ++i)
            if (rules::druidSpellLevel(i) < 1 ||
                rules::druidSpellLevel(i) > 7) ++bad;
        // the R182 slot table cross-checks (a spell-level
        // 8 query clamps to the 7th: 3)
        if (rules::druidSpellSlots(1, 1) != 2 ||
            rules::druidSpellSlots(12, 4) != 4 ||
            rules::druidSpellSlots(14, 7) != 3 ||
            rules::druidSpellSlots(14, 8) != 3) ++bad;
        printf("R228 druid registry parameters audit: bad %d\n", bad);
        if (bad) return 1;
    }
