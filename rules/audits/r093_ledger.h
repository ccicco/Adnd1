    // ---- R93: ledger audit ----
    {
        int bad = 0;
        // the deepest tracker: monotone, never forgets
        if (deepestOf(0, 1) != 1) ++bad;    // a first delve
        if (deepestOf(1, 3) != 3) ++bad;    // deeper wins
        if (deepestOf(5, 3) != 5) ++bad;    // shallower loses
        if (deepestOf(5, 5) != 5) ++bad;    // equal holds
        // the ledger starts clean
        {
            Party p;
            if (p.delveCount != 0 || p.deepestLevel != 0 ||
                p.totalGold != 0) ++bad;
        }
        // a simulated career: 4 delves, deepest 3, gross
        // take banks - the arithmetic the report line prints
        {
            Party p;
            p.deepestLevel = deepestOf(p.deepestLevel, 1);
            p.deepestLevel = deepestOf(p.deepestLevel, 3);
            int hauls[4] = {400, 1200, 0, 800};
            for (int i = 0; i < 4; ++i) {
                ++p.delveCount;
                p.totalGold += hauls[i];
            }
            if (p.delveCount != 4) ++bad;
            if (p.deepestLevel != 3) ++bad;
            if (p.totalGold != 2400) ++bad;
        }
        printf("R93 ledger audit: bad %d\n", bad);
        if (bad) return 1;
    }
