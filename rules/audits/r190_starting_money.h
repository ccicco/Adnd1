    // ---- R190: the starting money audit ----
    // All five printed rows, the clamps, the
    // monk no-x10 finding, the support ladder.
    {
        int bad = 0;
        // the four class rows, cell by cell
        // (fighter 5d4x10, magic-user 2d4x10,
        // cleric 3d6x10, thief 2d6x10)
        static const int kCnt[4] = { 5, 2, 3, 2 };
        static const int kFace[4] = { 4, 4, 6, 6 };
        static const int kMult[4] = { 10, 10, 10, 10 };
        static const int kMin[4] = { 50, 20, 30, 20 };
        static const int kMax[4] = { 200, 80, 180, 120 };
        for (int c = 0; c < 4; ++c) {
            if (rules::startingMoneyDiceCount(c) != kCnt[c]) ++bad;
            if (rules::startingMoneyDieFaces(c) != kFace[c]) ++bad;
            if (rules::startingMoneyMultiplier(c) != kMult[c]) ++bad;
            if (rules::startingMoneyMin(c) != kMin[c]) ++bad;
            if (rules::startingMoneyMax(c) != kMax[c]) ++bad;
        }
        // the clamps: out-of-range reads the edges
        if (rules::startingMoneyDiceCount(-5) != 5) ++bad;
        if (rules::startingMoneyMax(-5) != 200) ++bad;
        if (rules::startingMoneyDiceCount(99) != 2) ++bad;
        if (rules::startingMoneyMax(99) != 120) ++bad;
        // the monk row: the print 5-20 gp (5d4)
        // with NO x10 - the one un-multiplied row
        if (rules::monkStartingMoneyDiceCount() != 5) ++bad;
        if (rules::monkStartingMoneyDieFaces() != 4) ++bad;
        if (rules::monkStartingMoneyMultiplier() != 1) ++bad;
        if (rules::monkStartingMoneyMin() != 5) ++bad;
        if (rules::monkStartingMoneyMax() != 20) ++bad;
        // the DMG companion: not less than 100 gp
        // per level per month
        if (rules::pcMonthlySupportCost(1) != 100) ++bad;
        if (rules::pcMonthlySupportCost(5) != 500) ++bad;
        if (rules::pcMonthlySupportCost(12) != 1200) ++bad;
        // the level clamp: 0 reads the 1st
        if (rules::pcMonthlySupportCost(0) != 100) ++bad;
        printf("R190 starting money audit: bad %d\n", bad);
        if (bad) return 1;
    }
