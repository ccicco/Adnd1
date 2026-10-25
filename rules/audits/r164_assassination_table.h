    // ---- R164: the assassination table audit -------
    // DMG p.75: the assassins table - every printed
    // cell pinned, the dashes read as no chance, the
    // band mapping, the level clamps, and the
    // helpless-opponents footnote.
    {
        static const int kExp[15][10] = {
            { 50, 45, 35, 25, 10,  1, -1, -1, -1, -1 },
            { 55, 50, 40, 30, 15,  2, -1, -1, -1, -1 },
            { 60, 55, 45, 35, 20,  5, -1, -1, -1, -1 },
            { 65, 60, 50, 40, 25, 10,  1, -1, -1, -1 },
            { 70, 65, 55, 45, 30, 15,  5, -1, -1, -1 },
            { 75, 70, 60, 50, 35, 20, 10,  1, -1, -1 },
            { 80, 75, 65, 55, 40, 25, 15,  5, -1, -1 },
            { 85, 80, 70, 60, 45, 30, 20, 10,  2, -1 },
            { 95, 90, 80, 70, 55, 40, 30, 20,  5, -1 },
            { 99, 95, 85, 75, 60, 45, 35, 25, 10,  1 },
            { 100, 99, 90, 80, 65, 50, 40, 30, 15,  5 },
            { 100, 100, 95, 85, 70, 55, 45, 35, 20, 10 },
            { 100, 100, 99, 95, 80, 65, 50, 40, 25, 15 },
            { 100, 100, 100, 99, 90, 75, 60, 50, 35, 25 },
            { 100, 100, 100, 100, 99, 85, 70, 60, 40, 30 }
        };
        int bad = 0;
        // every printed cell, through the band mapping
        for (int lvl = 1; lvl <= 15; ++lvl) {
            for (int v = 0; v <= 19; ++v) {
                int col = (v >= 18) ? 9 : v / 2;
                if (rules::assassinationChance(lvl, v)
                        != kExp[lvl - 1][col]) ++bad;
            }
        }
        // the dashes read as -1: no chance at all
        if (rules::assassinationChance(1, 12) != -1 ||
            rules::assassinationChance(1, 18) != -1 ||
            rules::assassinationChance(8, 18) != -1 ||
            rules::assassinationChance(9, 18) != -1)
            ++bad;
        // spot cells off the band edges: a level 18 and
        // a level 25 victim both read the 18+ column
        if (rules::assassinationChance(10, 18) != 1 ||
            rules::assassinationChance(10, 25) != 1 ||
            rules::assassinationChance(15, 18) != 30)
            ++bad;
        // the level clamps: below 1 reads row 1,
        // above 15 reads row 15
        if (rules::assassinationChance(0, 0) != 50 ||
            rules::assassinationChance(-2, 4) != 35 ||
            rules::assassinationChance(16, 0) != 100 ||
            rules::assassinationChance(20, 8) != 99)
            ++bad;
        // the victim band mapping
        if (rules::assassinationVictimBand(-5) != 0 ||
            rules::assassinationVictimBand(0) != 0 ||
            rules::assassinationVictimBand(1) != 0 ||
            rules::assassinationVictimBand(2) != 1 ||
            rules::assassinationVictimBand(3) != 1 ||
            rules::assassinationVictimBand(17) != 8 ||
            rules::assassinationVictimBand(18) != 9 ||
            rules::assassinationVictimBand(99) != 9)
            ++bad;
        // the helpless-opponents footnote
        if (!rules::assassinationTableCoversHelpless())
            ++bad;
        printf("R164 assassination table audit: bad %d\n", bad);
        if (bad) return 1;
    }
