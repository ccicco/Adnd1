    // ---- R231: the subclass leveling seam audit ----
    // The printed XP attain rows cell by cell (the
    // R176 convention), the adders past the rows,
    // the fixed-hp levels, the fixed hp past them,
    // and the effective leveling cap.
    {
        int bad = 0;
        static const int kPal[11] = {
            0, 2750, 5500, 12000, 24000,
            45000, 95000, 175000, 350000, 700000,
            1050000
        };
        static const int kRng[12] = {
            0, 2250, 4500, 10000, 20000,
            40000, 90000, 150000, 225000, 325000,
            650000, 975000
        };
        static const int kDru[14] = {
            0, 2000, 4000, 7500, 12500,
            20000, 35000, 60000, 90000, 125000,
            200000, 300000, 750000, 1500000
        };
        static const int kIll[12] = {
            0, 2250, 4500, 9000, 18000,
            35000, 60000, 95000, 145000, 220000,
            440000, 660000
        };
        static const int kAsn[15] = {
            0, 1500, 3000, 6000, 12000,
            25000, 50000, 100000, 200000, 300000,
            425000, 575000, 750000, 1000000,
            1500000
        };
        static const int kMnk[17] = {
            0, 2250, 4750, 10000, 22500,
            47500, 98000, 200000, 350000, 500000,
            700000, 950000, 1250000, 1750000,
            2250000, 2750000, 3250000
        };
        for (int l = 1; l <= 11; ++l)
            if (rules::subclassXpToAttain(0, l)
                != kPal[l - 1]) ++bad;
        for (int l = 1; l <= 12; ++l)
            if (rules::subclassXpToAttain(1, l)
                != kRng[l - 1]) ++bad;
        for (int l = 1; l <= 14; ++l)
            if (rules::subclassXpToAttain(2, l)
                != kDru[l - 1]) ++bad;
        for (int l = 1; l <= 12; ++l)
            if (rules::subclassXpToAttain(3, l)
                != kIll[l - 1]) ++bad;
        for (int l = 1; l <= 15; ++l)
            if (rules::subclassXpToAttain(4, l)
                != kAsn[l - 1]) ++bad;
        for (int l = 1; l <= 17; ++l)
            if (rules::subclassXpToAttain(5, l)
                != kMnk[l - 1]) ++bad;
        // the adders past the printed rows: paladin
        // 350k, ranger 325k, illusionist 220k; the
        // druid, assassin and monk print none - the
        // top row repeats (the ceiling)
        if (rules::subclassXpToAttain(0, 12)
            != 1400000) ++bad;
        if (rules::subclassXpToAttain(0, 13)
            != 1750000) ++bad;
        if (rules::subclassXpToAttain(1, 13)
            != 1300000) ++bad;
        if (rules::subclassXpToAttain(3, 13)
            != 880000) ++bad;
        if (rules::subclassXpToAttain(2, 15)
            != 1500000) ++bad;
        if (rules::subclassXpToAttain(4, 16)
            != 1500000) ++bad;
        if (rules::subclassXpToAttain(5, 18)
            != 3250000) ++bad;
        // level 1 attains at 0
        if (rules::subclassXpToAttain(0, 1) != 0) ++bad;
        // the fixed-hp levels and the fixed hp past
        // them (the R179 pins)
        static const int kFix[6] = {
            9, 10, 9, 10, 10, 17
        };
        static const int kHpB[6] = {
            3, 2, 2, 1, 2, 0
        };
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassFixedHpLevel(i)
                != kFix[i]) ++bad;
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassHpBeyondFixed(i)
                != kHpB[i]) ++bad;
        // the leveling stops (the R179 levelCap pins;
        // the druid 14 - the hierarchy ceiling, where
        // the fixed hp starts at the 9th)
        static const int kStop[6] = {
            9, 10, 14, 10, 10, 17
        };
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassLevelStop(i)
                != kStop[i]) ++bad;
        // the effective leveling cap: the leveling
        // level minus a positive Table II race cap
        // (the footnote-8 gnome conditional included)
        if (rules::subclassLevelCapTotal(
                0, (rules::CharRace)0, 18, 18) != 9) ++bad;
        if (rules::subclassLevelCapTotal(
                2, (rules::CharRace)0, 18, 18) != 14) ++bad;
        if (rules::subclassLevelCapTotal(
                1, (rules::CharRace)4, 18, 18) != 8) ++bad;
        if (rules::subclassLevelCapTotal(
                3, (rules::CharRace)3, 17, 17) != 6) ++bad;
        if (rules::subclassLevelCapTotal(
                3, (rules::CharRace)3, 16, 18) != 5) ++bad;
        if (rules::subclassLevelCapTotal(
                4, (rules::CharRace)1, 18, 18) != 9) ++bad;
        if (rules::subclassLevelCapTotal(
                5, (rules::CharRace)0, 18, 18) != 17) ++bad;
        // the clamps
        if (rules::subclassXpToAttain(-1, 2)
            != 2750) ++bad;
        if (rules::subclassXpToAttain(99, 2)
            != 2250) ++bad;
        if (rules::subclassFixedHpLevel(-3) != 9) ++bad;
        if (rules::subclassFixedHpLevel(99) != 17) ++bad;
        if (rules::subclassLevelStop(-3) != 9) ++bad;
        if (rules::subclassLevelStop(99) != 17) ++bad;
        printf("R231 subclass leveling seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
