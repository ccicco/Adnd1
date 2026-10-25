    // ---- R225: the III.E table 1 pins audit ----
    // DMG p.128: the class marks and the
    // special rows of TABLE (III.E.) 1.
    {
        int bad = 0;
        // the row identity: the 33 die bands
        if (rules::m1RowCount() != 33) ++bad;
        static const int kLo[33] = {
            1, 3, 5, 6, 8, 12, 14, 17, 18, 21,
            22, 27, 28, 30, 32, 33, 34, 35, 36, 37,
            43, 48, 52, 56, 59, 60, 80, 82, 85, 86,
            93, 94, 99,
        };
        static const int kHi[33] = {
            2, 4, 5, 7, 11, 13, 16, 17, 20, 21,
            26, 27, 29, 31, 32, 33, 34, 35, 36, 42,
            47, 51, 55, 58, 59, 79, 81, 84, 85, 92,
            93, 98, 100,
        };
        static const int kM[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 1, 0, 0, 1, 1, 0,
            0, 0, 0,
        };
        static const int kC[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0,
        };
        static const int kArt[33] = {
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0,
        };
        static const int kBrac[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
            0, 0, 0,
        };
        static const int kPurse[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1,
        };
        for (int i = 0; i < 33; ++i)
            if (rules::m1RowLo(i) != kLo[i] ||
                rules::m1RowHi(i) != kHi[i] ||
                rules::m1UsableByMagicUser(i) != kM[i] ||
                rules::m1UsableByCleric(i) != kC[i] ||
                rules::m1IsArtifactRelicRow(i) != kArt[i] ||
                rules::m1IsPerAcPointValued(i) != kBrac[i] ||
                rules::m1IsTieredPurseRow(i) != kPurse[i])
                ++bad;
        for (int i = 1; i < 33; ++i)
            if (rules::m1RowLo(i) !=
                rules::m1RowHi(i - 1) + 1) ++bad;
        if (rules::m1RowLo(-5) != 1 ||
            rules::m1RowHi(99) != 100) ++bad;
        // the class marks: the two Books
        // are (C); the Bowls and Braziers
        // are (M)
        if (rules::m1MagicUserCount() != 4 ||
            rules::m1ClericCount() != 2) ++bad;
        if (!rules::m1UsableByCleric(15) ||
            !rules::m1UsableByCleric(17) ||
            rules::m1UsableByCleric(16)) ++bad;
        if (!rules::m1UsableByMagicUser(23) ||
            !rules::m1UsableByMagicUser(24) ||
            !rules::m1UsableByMagicUser(27) ||
            !rules::m1UsableByMagicUser(28) ||
            rules::m1UsableByMagicUser(22)) ++bad;
        // the special rows: Artifact or
        // Relic 17, Bracers 60-79, the
        // Purse 99-00
        if (!rules::m1IsArtifactRelicRow(7) ||
            rules::m1IsArtifactRelicRow(6)) ++bad;
        if (!rules::m1IsPerAcPointValued(25) ||
            rules::m1IsPerAcPointValued(26)) ++bad;
        if (!rules::m1IsTieredPurseRow(32) ||
            rules::m1IsTieredPurseRow(31)) ++bad;
        // the Bracers asterisk: per AC
        // point above 10 - AC 6 (four
        // points) is 2,000 x.p. / 12,000 gp
        if (rules::m1BracersPerAcXp() != 500 ||
            rules::m1BracersPerAcGp() != 3000 ||
            rules::m1BracersPerAcXp() * 4 != 2000 ||
            rules::m1BracersPerAcGp() * 4 != 12000)
            ++bad;
        // clamped flag reads land on the
        // Alchemy Jug (unmarked) and the
        // Purse (tiered)
        if (rules::m1UsableByMagicUser(-99) ||
            rules::m1UsableByCleric(-99) ||
            !rules::m1IsTieredPurseRow(99)) ++bad;
        printf("R225 misc table 1 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
