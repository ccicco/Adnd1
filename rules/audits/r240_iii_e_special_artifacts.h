    // ---- R240: the III.E Special artifacts pins audit ----
    // DMG p.130-131: the artifact g.p. sale
    // value table - the 29 rows, the value
    // conventions and the no-x.p. footnote.
    {
        int bad = 0;
        // the row identity: the 29 die bands
        if (rules::saRowCount() != 29) ++bad;
        static const int kLo[29] = {
            1, 2, 3, 5, 21, 22, 23, 25, 26, 27,
            28, 30, 32, 33, 34, 36, 38, 39, 41, 48,
            64, 65, 67, 69, 75, 92, 93, 99, 100,
        };
        static const int kHi[29] = {
            1, 2, 4, 20, 21, 22, 24, 25, 26, 27,
            29, 31, 32, 33, 35, 37, 38, 40, 47, 63,
            64, 66, 68, 74, 91, 92, 98, 99, 100,
        };
        static const int kGp[29] = {
            55000, 90000, 62500, 50000, 75000, 85000, 35000, 60000,
            25000, 20000, 47500, 50000, 100000, 40000, 27500, 35000,
            72500, 185000, 10000, 100000, 112500, 80000, 17500, 25000,
            150000, 97000, 5000, 0, 10000,
        };
        static const int kGpHi[29] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 80000, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kXp[29] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        for (int i = 0; i < 29; ++i)
            if (rules::saRowLo(i) != kLo[i] ||
                rules::saRowHi(i) != kHi[i] ||
                rules::saSaleGp(i) != kGp[i] ||
                rules::saSaleGpHi(i) != kGpHi[i] ||
                rules::saXpValue(i) != kXp[i])
                ++bad;
        for (int i = 1; i < 29; ++i)
            if (rules::saRowLo(i) !=
                rules::saRowHi(i - 1) + 1) ++bad;
        if (rules::saRowLo(-5) != 1 ||
            rules::saRowHi(99) != 100) ++bad;
        // the printed sale values: the Axe of
        // the Dwarvish Lords, the Jacinth of
        // Inestimable Beauty, the Mighty
        // Servant of Leuk-O, the Marvelous
        // Nightingale, the Sceptre of Might
        // and the Sword of Kas
        if (rules::saSaleGp(0) != 55000 ||
            rules::saSaleGp(12) != 100000 ||
            rules::saSaleGp(17) != 185000 ||
            rules::saSaleGp(20) != 112500 ||
            rules::saSaleGp(24) != 150000 ||
            rules::saSaleGp(25) != 97000) ++bad;
        // the Orb of the Dragonkind uniform
        // range 10,000-80,000 (count 1)
        if (rules::saSaleGp(18) != 10000 ||
            rules::saSaleGpHi(18) != 80000 ||
            rules::saDualRangeCount() != 1) ++bad;
        // the Teeth of Dahlver-Nar at 5,000
        // per tooth (count 1)
        if (rules::saSaleGp(26) != 5000 ||
            rules::saSaleGpHi(26) != 0 ||
            rules::saPerToothRowCount() != 1) ++bad;
        // the Throne of the Gods prints NO
        // sale value (count 1)
        if (rules::saSaleGp(27) != 0 ||
            rules::saSaleGpHi(27) != 0 ||
            rules::saNoSaleRowCount() != 1) ++bad;
        // the Wand of Orcus rides the 00
        // band - pinned as 100
        if (rules::saRowLo(28) != 100 ||
            rules::saSaleGp(28) != 10000) ++bad;
        // the no-x.p. convention: every row
        if (rules::saNoXpRowCount() != 29) ++bad;
        // clamped reads land on the Axe below
        // and the Wand of Orcus above
        if (rules::saSaleGp(-99) != 55000 ||
            rules::saSaleGp(99) != 10000 ||
            rules::saXpValue(-99) != 0 ||
            rules::saXpValue(99) != 0) ++bad;
        printf("R240 special artifacts pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
