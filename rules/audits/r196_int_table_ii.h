    // ---- R196: the INT Table II audit ----
    // The printed INTELLIGENCE TABLE II: the chance-to-know
    // percents and the min/max spells-per-level columns,
    // cell for cell.
    {
        int bad = 0;
        // the chance-to-know percents (9 through 19+)
        static const int kPct[11] = {
             0, 35, 45, 45, 45, 55, 55, 65, 65, 75,
            85
        };
        // probes at 9-18, then the 19+ row
        for (int i = 9; i <= 18; ++i) {
            if (spells::chanceToLearnPct((uint8_t)i)
                != kPct[i - 8]) ++bad;
        }
        if (spells::chanceToLearnPct(19) != 95) ++bad;
        if (spells::chanceToLearnPct(25) != 95) ++bad;
        if (spells::chanceToLearnPct(8) != 0) ++bad;
        // the historically divergent cells (the R196 find):
        // 10 read 35, 16 read 70, 17 read 85, 18 read 95
        if (spells::chanceToLearnPct(10) != 45) ++bad;
        if (spells::chanceToLearnPct(16) != 65) ++bad;
        if (spells::chanceToLearnPct(17) != 75) ++bad;
        if (spells::chanceToLearnPct(18) != 85) ++bad;
        // the min spells-per-level column
        static const int kMin[11] = {
             0, 4, 5, 5, 5, 6, 6, 7, 7, 8, 9
        };
        for (int i = 9; i <= 18; ++i) {
            if (spells::minSpellsPerLevel((uint8_t)i)
                != kMin[i - 8]) ++bad;
        }
        if (spells::minSpellsPerLevel(19) != 10) ++bad;
        if (spells::minSpellsPerLevel(8) != 0) ++bad;
        // the max spells-per-level column
        static const int kMax[11] = {
             0, 6, 7, 7, 7, 9, 9, 11, 11, 14, 18
        };
        for (int i = 9; i <= 18; ++i) {
            if (spells::maxSpellsPerLevel((uint8_t)i)
                != kMax[i - 8]) ++bad;
        }
        // the 19+ row: 10 / All (unlimited = -1)
        if (spells::minSpellsPerLevel(19) != 10) ++bad;
        if (spells::maxSpellsPerLevel(19) != -1) ++bad;
        if (spells::maxSpellsPerLevel(25) != -1) ++bad;
        // the band shape: min <= max at every score
        for (int i = 9; i <= 25; ++i) {
            int lo = spells::minSpellsPerLevel((uint8_t)i);
            int hi = spells::maxSpellsPerLevel((uint8_t)i);
            if (hi >= 0 && lo > hi) ++bad;   // R196c: -1 is unlimited
        }
        printf("R196 INT table II audit: bad %d\n", bad);
        if (bad) return 1;
    }
