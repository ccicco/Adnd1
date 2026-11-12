    // ---- R309: the hirelings cost tables audit ----
    // The two DMG HIRELINGS tables (rules/dmg/hirelings.h)
    // walked cell for cell against this local ground
    // truth: the standard daily and monthly columns
    // (the monthly coin identity), the craft percent
    // flags, the employment bands, the expert cost
    // column (the -1 special rows), the mercenary
    // block boundaries, the special and asterisk flags
    // and the clamps.
    {
        Hirelings hirelings;
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
        if (hirelings.hireStdCount() != 10) ++bad;
        for (int i = 0; i < 10; ++i)
            if (hirelings.hireStdDailySp(i) != kDaily[i]) ++bad;
        for (int i = 0; i < 10; ++i)
            if (hirelings.hireStdMonthlyGold(i) != kGold[i]) ++bad;
        for (int i = 0; i < 10; ++i)
            if (hirelings.hireStdMonthlySilver(i) != kSilver[i])
                ++bad;
        // the monthly coin identity: exactly one
        // nonzero column per row (two columns - the
        // pairwise form reads exactly-one-nonzero)
        for (int i = 0; i < 10; ++i)
            if ((hirelings.hireStdMonthlyGold(i) == 0) ==
                (hirelings.hireStdMonthlySilver(i) == 0)) ++bad;
        // the craft percent flags
        for (int i = 0; i < 10; ++i)
            if (hirelings.hireStdPercentOnTop(i) != kPct[i]) ++bad;
        // worked standard rows: the limner 10 s.p.
        // daily and 10 g.p. monthly, the leather
        // worker 30 s.p., the valet 50 s.p.
        if (hirelings.hireStdDailySp(3) != 10 ||
            hirelings.hireStdMonthlyGold(3) != 10 ||
            hirelings.hireStdMonthlySilver(2) != 30 ||
            hirelings.hireStdMonthlySilver(9) != 50) ++bad;
        // the standard clamps (row -5 the bearer, row
        // 99 the valet)
        if (hirelings.hireStdDailySp(-5) != 1 ||
            hirelings.hireStdDailySp(99) != 3 ||
            hirelings.hireStdMonthlyGold(-5) != 1 ||
            hirelings.hireStdMonthlyGold(99) != 0 ||
            hirelings.hireStdMonthlySilver(-5) != 0 ||
            hirelings.hireStdMonthlySilver(99) != 50 ||
            hirelings.hireStdPercentOnTop(-5) != 0 ||
            hirelings.hireStdPercentOnTop(99) != 0) ++bad;
        // the employment bands: no bonus or a single
        // daily wage draws 1 in 6; double or treble
        // draws 3 in 6
        if (hirelings.hireStdLongTermSixths(0) != 1 ||
            hirelings.hireStdLongTermSixths(1) != 1 ||
            hirelings.hireStdLongTermSixths(2) != 3 ||
            hirelings.hireStdLongTermSixths(3) != 3 ||
            hirelings.hireStdLongTermSixths(9) != 3) ++bad;
        // the expert counts and boundaries
        if (hirelings.hireExpCount() != 33 ||
            hirelings.hireExpMercenaryFirst() != 7 ||
            hirelings.hireExpMercenaryCount() != 19) ++bad;
        // the expert cost column, every row
        for (int i = 0; i < 33; ++i)
            if (hirelings.hireExpCost(i) != kCost[i]) ++bad;
        // the mercenary block membership
        for (int i = 0; i < 33; ++i)
            if (hirelings.hireExpIsMercenary(i) != kMerc[i]) ++bad;
        // the special rows read -1
        for (int i = 0; i < 33; ++i)
            if (hirelings.hireExpIsSpecial(i) != kSpec[i]) ++bad;
        // the asterisk flags
        for (int i = 0; i < 33; ++i)
            if (hirelings.hireExpPercentOnTop(i) != kAst[i]) ++bad;
        // the asterisk-cost identity: the flagged rows
        // are exactly the four 100 g.p. rows
        for (int i = 0; i < 33; ++i)
            if ((hirelings.hireExpCost(i) == 100) !=
                (hirelings.hireExpPercentOnTop(i) == 1)) ++bad;
        // worked expert rows: the alchemist 300, the
        // blacksmith 30, the scribe 15, the horseman
        // heavy 6, the footman light 1
        if (hirelings.hireExpCost(0) != 300 ||
            hirelings.hireExpCost(2) != 30 ||
            hirelings.hireExpCost(27) != 15 ||
            hirelings.hireExpCost(19) != 6 ||
            hirelings.hireExpCost(13) != 1) ++bad;
        // the expert clamps (row -5 the alchemist, row
        // 99 the weapon maker; the mercenary edges)
        if (hirelings.hireExpCost(-5) != 300 ||
            hirelings.hireExpCost(99) != 100 ||
            hirelings.hireExpIsMercenary(6) != 0 ||
            hirelings.hireExpIsMercenary(7) != 1 ||
            hirelings.hireExpIsMercenary(25) != 1 ||
            hirelings.hireExpIsMercenary(26) != 0 ||
            hirelings.hireExpIsMercenary(-5) != 0 ||
            hirelings.hireExpIsMercenary(99) != 0 ||
            hirelings.hireExpPercentOnTop(-5) != 0 ||
            hirelings.hireExpPercentOnTop(99) != 1) ++bad;
        printf("R309 hirelings cost tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
