    // ---- R241: the III.F armor and shield pins audit ----
    // DMG p.129-130: the magic armor and shield
    // table - the 26 rows, the two cursed
    // no-x.p. rows and the size footnote.
    {
        int bad = 0;
        // the row identity: the 26 die bands
        if (rules::asRowCount() != 26) ++bad;
        static const int kLo[26] = {
            1, 6, 10, 12, 20, 27, 33, 36, 38,
            39, 40, 45, 51, 56, 60, 64, 67, 69,
            70, 76, 85, 90, 94, 96, 97, 98,
        };
        static const int kHi[26] = {
            5, 9, 11, 19, 26, 32, 35, 37, 38,
            39, 44, 50, 55, 59, 63, 66, 68, 69,
            75, 84, 89, 93, 95, 96, 97, 100,
        };
        static const int kXp[26] = {
            600, 1200, 2000, 300, 800, 1750, 2750, 3500, 4500,
            5000, 0, 400, 500, 1100, 700, 1500, 2250, 3000,
            400, 250, 500, 800, 1200, 1750, 400, 0,
        };
        static const int kGp[26] = {
            3500, 7500, 12500, 2000, 5000, 10500, 15500, 20500, 27500,
            30000, 1500, 2500, 3000, 6750, 4000, 8500, 14500, 19000,
            2500, 2500, 5000, 8000, 12000, 17500, 4000, 750,
        };
        for (int i = 0; i < 26; ++i)
            if (rules::asRowLo(i) != kLo[i] ||
                rules::asRowHi(i) != kHi[i] ||
                rules::asXpValue(i) != kXp[i] ||
                rules::asSaleGp(i) != kGp[i])
                ++bad;
        for (int i = 1; i < 26; ++i)
            if (rules::asRowLo(i) !=
                rules::asRowHi(i - 1) + 1) ++bad;
        if (rules::asRowLo(-5) != 1 ||
            rules::asRowHi(99) != 100) ++bad;
        // the printed values: Chain Mail +1,
        // Leather Armor +1, Plate Mail of
        // Etherealness, Shield +5 and the
        // large missile Shield
        if (rules::asXpValue(0) != 600 ||
            rules::asSaleGp(0) != 3500) ++bad;
        if (rules::asXpValue(3) != 300 ||
            rules::asSaleGp(3) != 2000) ++bad;
        if (rules::asXpValue(9) != 5000 ||
            rules::asSaleGp(9) != 30000) ++bad;
        if (rules::asXpValue(23) != 1750 ||
            rules::asSaleGp(23) != 17500) ++bad;
        if (rules::asXpValue(24) != 400 ||
            rules::asSaleGp(24) != 4000) ++bad;
        // the TWO cursed no-x.p. rows: the
        // Plate Mail of Vulnerability and the
        // Shield -1 missile attractor
        if (rules::asXpValue(10) != 0 ||
            rules::asSaleGp(10) != 1500 ||
            rules::asXpValue(25) != 0 ||
            rules::asSaleGp(25) != 750 ||
            rules::asNoXpCount() != 2) ++bad;
        // the missile attractor rides the 98-00
        // band - pinned as 98 through 100
        if (rules::asRowLo(25) != 98 ||
            rules::asRowHi(25) != 100) ++bad;
        // the armor SIZE footnote: 65/20/10/5
        // sums to 100
        if (rules::asManSizedPct() != 65 ||
            rules::asElfSizedPct() != 20 ||
            rules::asDwarfSizedPct() != 10 ||
            rules::asSmallUserPct() != 5) ++bad;
        if (rules::asManSizedPct() +
            rules::asElfSizedPct() +
            rules::asDwarfSizedPct() +
            rules::asSmallUserPct() != 100) ++bad;
        // clamped reads land on Chain Mail +1
        // below and the missile attractor above
        if (rules::asSaleGp(-99) != 3500 ||
            rules::asSaleGp(99) != 750 ||
            rules::asXpValue(-99) != 600 ||
            rules::asXpValue(99) != 0) ++bad;
        printf("R241 armor and shield pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
