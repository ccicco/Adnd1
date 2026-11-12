    // ---- R239: the III.E table 5 pins audit ----
    // DMG p.130: the class marks of TABLE
    // (III.E.) 5 - no asterisk rows, dual-value
    // rows or footnotes ride this table.
    {
        Miscmagic_table5_footnotes miscmagic_table5_footnotes;
        int bad = 0;
        // the row identity: the 35 die bands
        if (miscmagic_table5_footnotes.m5RowCount() != 35) ++bad;
        static const int kLo[35] = {
            1, 2, 9, 10, 11, 12, 20, 26, 28, 32,
            33, 34, 35, 36, 39, 41, 47, 48, 49, 51,
            53, 55, 58, 59, 61, 67, 68, 69, 70, 77,
            79, 84, 86, 88, 91,
        };
        static const int kHi[35] = {
            1, 8, 9, 10, 11, 19, 25, 27, 31, 32,
            33, 34, 35, 38, 40, 46, 47, 48, 50, 52,
            54, 57, 58, 60, 66, 67, 68, 69, 76, 78,
            83, 85, 87, 90, 100,
        };
        static const int kC[35] = {
            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 0, 1, 0, 0, 0, 0, 1, 0,
            1, 0, 0, 0, 0,
        };
        static const int kF[35] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
            1, 0, 0, 0, 0,
        };
        static const int kM[35] = {
            1, 0, 1, 1, 1, 1, 0, 0, 0, 0,
            1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
        };
        static const int kT[35] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
            1, 0, 0, 0, 0,
        };
        for (int i = 0; i < 35; ++i)
            if (miscmagic_table5_footnotes.m5RowLo(i) != kLo[i] ||
                miscmagic_table5_footnotes.m5RowHi(i) != kHi[i] ||
                miscmagic_table5_footnotes.m5UsableByCleric(i) != kC[i] ||
                miscmagic_table5_footnotes.m5UsableByFighter(i) != kF[i] ||
                miscmagic_table5_footnotes.m5UsableByMagicUser(i) != kM[i] ||
                miscmagic_table5_footnotes.m5UsableByThief(i) != kT[i])
                ++bad;
        for (int i = 1; i < 35; ++i)
            if (miscmagic_table5_footnotes.m5RowLo(i) !=
                miscmagic_table5_footnotes.m5RowHi(i - 1) + 1) ++bad;
        if (miscmagic_table5_footnotes.m5RowLo(-5) != 1 ||
            miscmagic_table5_footnotes.m5RowHi(99) != 100) ++bad;
        // the class marks: the five Robes, the
        // Rug, the Sphere and the Sphere
        // Talisman are (M); the Scintillating
        // Robe, the two Talismans and the two
        // command/warning Tridents are (C); the
        // Saw, the Spade, the Submission
        // Trident and the command/warning
        // Tridents are (F); the command/warning
        // Tridents are (T)
        if (miscmagic_table5_footnotes.m5ClericCount() != 5 ||
            miscmagic_table5_footnotes.m5FighterCount() != 5 ||
            miscmagic_table5_footnotes.m5MagicUserCount() != 8 ||
            miscmagic_table5_footnotes.m5ThiefCount() != 2) ++bad;
        if (!miscmagic_table5_footnotes.m5UsableByMagicUser(0) ||
            miscmagic_table5_footnotes.m5UsableByCleric(0)) ++bad;
        if (miscmagic_table5_footnotes.m5UsableByMagicUser(1) ||
            miscmagic_table5_footnotes.m5UsableByCleric(1) ||
            miscmagic_table5_footnotes.m5UsableByFighter(1) ||
            miscmagic_table5_footnotes.m5UsableByThief(1)) ++bad;
        if (!miscmagic_table5_footnotes.m5UsableByMagicUser(2) ||
            !miscmagic_table5_footnotes.m5UsableByMagicUser(3) ||
            !miscmagic_table5_footnotes.m5UsableByMagicUser(5)) ++bad;
        if (!miscmagic_table5_footnotes.m5UsableByCleric(4) ||
            !miscmagic_table5_footnotes.m5UsableByMagicUser(4)) ++bad;
        if (!miscmagic_table5_footnotes.m5UsableByMagicUser(10) ||
            !miscmagic_table5_footnotes.m5UsableByFighter(11) ||
            miscmagic_table5_footnotes.m5UsableByCleric(12)) ++bad;
        if (!miscmagic_table5_footnotes.m5UsableByFighter(16) ||
            !miscmagic_table5_footnotes.m5UsableByMagicUser(17)) ++bad;
        if (!miscmagic_table5_footnotes.m5UsableByCleric(21) ||
            !miscmagic_table5_footnotes.m5UsableByMagicUser(22) ||
            !miscmagic_table5_footnotes.m5UsableByCleric(23) ||
            miscmagic_table5_footnotes.m5UsableByCleric(24)) ++bad;
        if (miscmagic_table5_footnotes.m5UsableByCleric(25) ||
            miscmagic_table5_footnotes.m5UsableByCleric(26) ||
            miscmagic_table5_footnotes.m5UsableByCleric(27)) ++bad;
        if (!miscmagic_table5_footnotes.m5UsableByCleric(28) ||
            !miscmagic_table5_footnotes.m5UsableByFighter(28) ||
            !miscmagic_table5_footnotes.m5UsableByThief(28) ||
            !miscmagic_table5_footnotes.m5UsableByCleric(30) ||
            !miscmagic_table5_footnotes.m5UsableByFighter(30) ||
            !miscmagic_table5_footnotes.m5UsableByThief(30)) ++bad;
        if (!miscmagic_table5_footnotes.m5UsableByFighter(29) ||
            miscmagic_table5_footnotes.m5UsableByCleric(29) ||
            miscmagic_table5_footnotes.m5UsableByThief(29)) ++bad;
        if (miscmagic_table5_footnotes.m5UsableByCleric(31) ||
            miscmagic_table5_footnotes.m5UsableByFighter(31) ||
            miscmagic_table5_footnotes.m5UsableByThief(31)) ++bad;
        // clamped reads land on the (M) Robe of
        // the Archmagi below and the unmarked
        // Wings of Flying above
        if (!miscmagic_table5_footnotes.m5UsableByMagicUser(-99) ||
            miscmagic_table5_footnotes.m5UsableByCleric(99) ||
            miscmagic_table5_footnotes.m5UsableByFighter(99) ||
            miscmagic_table5_footnotes.m5UsableByThief(99)) ++bad;
        printf("R239 misc table 5 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
