    // ---- R309: the hirelings cost tables audit ----
    // The two DMG HIRELINGS tables (rules/hirelings.h)
    // walked cell for cell against this local ground
    // truth: the standard daily and monthly columns
    // (the monthly coin identity), the craft percent
    // flags, the employment bands, the expert cost
    // column (the -1 special rows), the mercenary
    // block boundaries, the special and asterisk flags
    // and the clamps.
    {
        int bad = 0;
        static const int kDaily[10] = {
               1,    3,    2,   10,    1,    4,    2,    2,    5,    3,
        };
        static const int kGold[10] = {
               1,    2,    0,   10,    1,    3,    0,    0,    5,    0,
        };
        static const int kSilver[10] = {
               0,    0,   30,    0,    0,    0,   30,   30,    0,   50,
        };
        static const int kPct[10] = {
               0,    1,    1,    0,    0,    0,    0,    1,    0,    0,
        };
        static const int kCost[33] = {
             300,  100,   30,  100,  150,  150,  100,    4,    2,    5,
              -1,    2,    2,    1,    3,    3,    2,    6,    4,    6,
               3,    4,   -1,    4,   -1,    3,   -1,   15,   -1,   -1,
              -1,   -1,  100,
        };
        static const int kMerc[33] = {
               0,    0,    0,    0,    0,    0,    0,    1,    1,    1,
               1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
               1,    1,    1,    1,    1,    1,    0,    0,    0,    0,
               0,    0,    0,
        };
        static const int kSpec[33] = {
               0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
               1,    0,    0,    0,    0,    0,    0,    0,    0,    0,
               0,    0,    1,    0,    1,    0,    1,    0,    1,    1,
               1,    1,    0,
        };
        static const int kAst[33] = {
               0,    1,    0,    1,    0,    0,    1,    0,    0,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
               0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
               0,    0,    1,
        };
        // the standard counts and columns
        if (rules::hireStdCount() != 10) ++bad;
        for (int i = 0; i < 10; ++i)
            if (rules::hireStdDailySp(i) != kDaily[i]) ++bad;
        for (int i = 0; i < 10; ++i)
            if (rules::hireStdMonthlyGold(i) != kGold[i]) ++bad;
        for (int i = 0; i < 10; ++i)
            if (rules::hireStdMonthlySilver(i) != kSilver[i])
                ++bad;
        // the monthly coin identity: exactly one
        // nonzero column per row (two columns - the
        // pairwise form reads exactly-one-nonzero)
        for (int i = 0; i < 10; ++i)
            if ((rules::hireStdMonthlyGold(i) == 0) ==
                (rules::hireStdMonthlySilver(i) == 0)) ++bad;
        // the craft percent flags
        for (int i = 0; i < 10; ++i)
            if (rules::hireStdPercentOnTop(i) != kPct[i]) ++bad;
        // worked standard rows: the limner 10 s.p.
        // daily and 10 g.p. monthly, the leather
        // worker 30 s.p., the valet 50 s.p.
        if (rules::hireStdDailySp(3) != 10 ||
            rules::hireStdMonthlyGold(3) != 10 ||
            rules::hireStdMonthlySilver(2) != 30 ||
            rules::hireStdMonthlySilver(9) != 50) ++bad;
        // the standard clamps (row -5 the bearer, row
        // 99 the valet)
        if (rules::hireStdDailySp(-5) != 1 ||
            rules::hireStdDailySp(99) != 3 ||
            rules::hireStdMonthlyGold(-5) != 1 ||
            rules::hireStdMonthlyGold(99) != 0 ||
            rules::hireStdMonthlySilver(-5) != 0 ||
            rules::hireStdMonthlySilver(99) != 50 ||
            rules::hireStdPercentOnTop(-5) != 0 ||
            rules::hireStdPercentOnTop(99) != 0) ++bad;
        // the employment bands: no bonus or a single
        // daily wage draws 1 in 6; double or treble
        // draws 3 in 6
        if (rules::hireStdLongTermSixths(0) != 1 ||
            rules::hireStdLongTermSixths(1) != 1 ||
            rules::hireStdLongTermSixths(2) != 3 ||
            rules::hireStdLongTermSixths(3) != 3 ||
            rules::hireStdLongTermSixths(9) != 3) ++bad;
        // the expert counts and boundaries
        if (rules::hireExpCount() != 33 ||
            rules::hireExpMercenaryFirst() != 7 ||
            rules::hireExpMercenaryCount() != 19) ++bad;
        // the expert cost column, every row
        for (int i = 0; i < 33; ++i)
            if (rules::hireExpCost(i) != kCost[i]) ++bad;
        // the mercenary block membership
        for (int i = 0; i < 33; ++i)
            if (rules::hireExpIsMercenary(i) != kMerc[i]) ++bad;
        // the special rows read -1
        for (int i = 0; i < 33; ++i)
            if (rules::hireExpIsSpecial(i) != kSpec[i]) ++bad;
        // the asterisk flags
        for (int i = 0; i < 33; ++i)
            if (rules::hireExpPercentOnTop(i) != kAst[i]) ++bad;
        // the asterisk-cost identity: the flagged rows
        // are exactly the four 100 g.p. rows
        for (int i = 0; i < 33; ++i)
            if ((rules::hireExpCost(i) == 100) !=
                (rules::hireExpPercentOnTop(i) == 1)) ++bad;
        // worked expert rows: the alchemist 300, the
        // blacksmith 30, the scribe 15, the horseman
        // heavy 6, the footman light 1
        if (rules::hireExpCost(0) != 300 ||
            rules::hireExpCost(2) != 30 ||
            rules::hireExpCost(27) != 15 ||
            rules::hireExpCost(19) != 6 ||
            rules::hireExpCost(13) != 1) ++bad;
        // the expert clamps (row -5 the alchemist, row
        // 99 the weapon maker; the mercenary edges)
        if (rules::hireExpCost(-5) != 300 ||
            rules::hireExpCost(99) != 100 ||
            rules::hireExpIsMercenary(6) != 0 ||
            rules::hireExpIsMercenary(7) != 1 ||
            rules::hireExpIsMercenary(25) != 1 ||
            rules::hireExpIsMercenary(26) != 0 ||
            rules::hireExpIsMercenary(-5) != 0 ||
            rules::hireExpIsMercenary(99) != 0 ||
            rules::hireExpPercentOnTop(-5) != 0 ||
            rules::hireExpPercentOnTop(99) != 1) ++bad;
        printf("R309 hirelings cost tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
