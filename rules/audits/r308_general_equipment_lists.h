    // ---- R308: the general equipment lists audit ----
    // The EIGHT printed general lists (the
    // rules/equipcosts.h general section) walked cell
    // for cell against this local ground truth: the
    // row count, the list boundaries, the three coin
    // columns, the coin identity (exactly one nonzero
    // column per row), the clamps, the herbs cells the
    // reference sheet resolves, the worked rows and
    // the monetary pins.
    {
        int bad = 0;
        static const int kGold[99] = {
               0,    2,    1,    1,    0,    0,    0,    2,    0,    0,
               0,    0,    0,    0,    0,   10,   25,   17,    8,    1,
              40,   18,   30,  300,  150,  225,   25,   20,   15,    0,
               1,    3,   15,    2,    0,    2,   28,    9,    0,    0,
               5,    0,    0,    0,   12,    7,   10,   20,    1,    0,
               1,    0,    0,    0,    0,    1,    0,    0,    0,    0,
               0,   30,    1,    0,    0,    0,    0,    1,    0,    0,
               5,    3,    0,    0,    1,    1,    2,   50,    0,   25,
             250,  100,  500,    0,    0,   10,    4,    3,    0,   50,
              75,  150,   50, 25000, 10000, 15000, 5000, 20000,  150,
        };
        static const int kSilver[99] = {
               3,    0,    0,    0,    8,    1,    5,    0,   10,    7,
               6,    4,    0,   10,    0,    0,    0,    0,    0,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
               0,   15,   17,    8,    0,    0,    0,    0,    0,    0,
               0,   15,    8,   12,   15,    0,    4,    0,    0,   15,
               0,    0,    0,    0,    1,    0,    1,    0,    1,    5,
               0,    0,   10,    5,    0,    0,    0,    0,    7,    0,
               0,    0,    0,   15,   12,    0,    0,    0,    3,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,
        };
        static const int kCopper[99] = {
               0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
               0,    0,    5,    0,    3,    0,    0,    0,    0,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,    2,
               0,    0,    0,    0,    4,    0,    0,    0,    1,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
               0,    0,    0,    0,    0,    0,    0,   16,   10,    0,
               1,    0,    0,    1,    0,    5,    0,    0,    0,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,
        };
        static const int kFirst[8] = {
               0,   11,   14,   35,   64,   74,   80,   89,
        };
        static const int kCount[8] = {
              11,    3,   21,   29,   10,    6,    9,   10,
        };
        // the row count
        if (rules::eqcGeneralCount() != 99) ++bad;
        // the list boundaries
        for (int l = 0; l < 8; ++l)
            if (rules::eqcGeneralFirst(l) != kFirst[l] ||
                rules::eqcGeneralListCount(l) != kCount[l])
                ++bad;
        // the three coin columns, every row
        for (int i = 0; i < 99; ++i)
            if (rules::eqcGeneralGold(i) != kGold[i]) ++bad;
        for (int i = 0; i < 99; ++i)
            if (rules::eqcGeneralSilver(i) != kSilver[i])
                ++bad;
        for (int i = 0; i < 99; ++i)
            if (rules::eqcGeneralCopper(i) != kCopper[i])
                ++bad;
        // the coin identity: exactly one nonzero
        // column per row (the three-column count -
        // the R300 pairwise form reads false on the
        // copper rows, where gold and silver both
        // sit at zero)
        for (int i = 0; i < 99; ++i)
            if ((rules::eqcGeneralGold(i) > 0) +
                (rules::eqcGeneralSilver(i) > 0) +
                (rules::eqcGeneralCopper(i) > 0) != 1)
                ++bad;
        // the clamps: past either edge reads the edge
        // row (row -5 the belt, 3 silver 0 copper;
        // row 99 the wagon 150 gold; list -5 the
        // clothing 11; list 99 the transport 10)
        if (rules::eqcGeneralSilver(-5) != 3 ||
            rules::eqcGeneralGold(99) != 150 ||
            rules::eqcGeneralCopper(-5) != 0 ||
            rules::eqcGeneralFirst(-5) != 0 ||
            rules::eqcGeneralFirst(99) != 89 ||
            rules::eqcGeneralListCount(-5) != 11 ||
            rules::eqcGeneralListCount(99) != 10) ++bad;
        // the herbs cells (the reference sheet
        // resolves the scrambled equipment copy)
        if (rules::eqcGeneralSilver(11) != 4 ||
            rules::eqcGeneralCopper(12) != 5 ||
            rules::eqcGeneralSilver(13) != 10) ++bad;
        // the worked rows: the heavy war horse 300,
        // the medium 225, the plate barding 500, the
        // large galley 25000, the small 10000 and the
        // warship 20000
        if (rules::eqcGeneralGold(23) != 300 ||
            rules::eqcGeneralGold(25) != 225 ||
            rules::eqcGeneralGold(82) != 500 ||
            rules::eqcGeneralGold(93) != 25000 ||
            rules::eqcGeneralGold(94) != 10000 ||
            rules::eqcGeneralGold(97) != 20000) ++bad;
        // the monetary pins (the R300 silver one
        // plus the R308 copper ones)
        if (rules::eqcSilverPerGold() != 20 ||
            rules::eqcCopperPerSilver() != 10 ||
            rules::eqcCopperPerGold() != 200) ++bad;
        printf("R308 general equipment lists audit: bad %d\n", bad);
        if (bad) return 1;
    }
