    // ---- R226: the III.E table 2 pins audit ----
    // DMG p.128: the class marks and the
    // asterisk rows of TABLE (III.E.) 2.
    {
        Miscmagic_table2_footnotes miscmagic_table2_footnotes;
        int bad = 0;
        // the row identity: the 30 die bands
        if (miscmagic_table2_footnotes.m2RowCount() != 30) ++bad;
        static const int kLo[30] = {
            1, 7, 9, 11, 12, 14, 15, 19, 28, 31,
            33, 56, 61, 62, 64, 66, 68, 70, 73, 77,
            78, 80, 86, 92, 93, 94, 95, 96, 98, 100,
        };
        static const int kHi[30] = {
            6, 8, 10, 11, 13, 14, 18, 27, 30, 32,
            55, 60, 61, 63, 65, 67, 69, 72, 76, 77,
            79, 85, 91, 92, 93, 94, 95, 97, 99, 100,
        };
        static const int kC[30] = {
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kM[30] = {
            0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        };
        static const int kPP[30] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kFeat[30] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kTri[30] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        };
        for (int i = 0; i < 30; ++i)
            if (miscmagic_table2_footnotes.m2RowLo(i) != kLo[i] ||
                miscmagic_table2_footnotes.m2RowHi(i) != kHi[i] ||
                miscmagic_table2_footnotes.m2UsableByCleric(i) != kC[i] ||
                miscmagic_table2_footnotes.m2UsableByMagicUser(i) != kM[i] ||
                miscmagic_table2_footnotes.m2IsPerPlusValued(i) != kPP[i] ||
                miscmagic_table2_footnotes.m2HasFeatureAsterisk(i) != kFeat[i] ||
                miscmagic_table2_footnotes.m2IsTripleStar(i) != kTri[i]) ++bad;
        for (int i = 1; i < 30; ++i)
            if (miscmagic_table2_footnotes.m2RowLo(i) !=
                miscmagic_table2_footnotes.m2RowHi(i - 1) + 1) ++bad;
        if (miscmagic_table2_footnotes.m2RowLo(-5) != 1 ||
            miscmagic_table2_footnotes.m2RowHi(99) != 100) ++bad;
        // the class marks: the Candle is
        // (C); the Censers, the Balls and
        // the Eyes of Charming are (M)
        if (miscmagic_table2_footnotes.m2ClericCount() != 1 ||
            miscmagic_table2_footnotes.m2MagicUserCount() != 5) ++bad;
        if (!miscmagic_table2_footnotes.m2UsableByCleric(0) ||
            miscmagic_table2_footnotes.m2UsableByCleric(1)) ++bad;
        if (!miscmagic_table2_footnotes.m2UsableByMagicUser(2) ||
            !miscmagic_table2_footnotes.m2UsableByMagicUser(3) ||
            !miscmagic_table2_footnotes.m2UsableByMagicUser(11) ||
            !miscmagic_table2_footnotes.m2UsableByMagicUser(12) ||
            !miscmagic_table2_footnotes.m2UsableByMagicUser(26) ||
            miscmagic_table2_footnotes.m2UsableByMagicUser(1) ||
            miscmagic_table2_footnotes.m2UsableByMagicUser(27)) ++bad;
        // the asterisk rows: Cloak of
        // Protection 33-55 per plus,
        // Crystal Ball 56-60 the feature
        // asterisk, Eyes of Petrification
        // 00 the triple star
        if (!miscmagic_table2_footnotes.m2IsPerPlusValued(10) ||
            miscmagic_table2_footnotes.m2IsPerPlusValued(11)) ++bad;
        if (!miscmagic_table2_footnotes.m2HasFeatureAsterisk(11) ||
            miscmagic_table2_footnotes.m2HasFeatureAsterisk(10)) ++bad;
        if (!miscmagic_table2_footnotes.m2IsTripleStar(29) ||
            miscmagic_table2_footnotes.m2IsTripleStar(28)) ++bad;
        // a +2 cloak is 2,000 x.p. /
        // 20,000 g.p.
        if (miscmagic_table2_footnotes.m2CloakPerPlusXp() != 1000 ||
            miscmagic_table2_footnotes.m2CloakPerPlusGp() != 10000 ||
            miscmagic_table2_footnotes.m2CloakPerPlusXp() * 2 != 2000 ||
            miscmagic_table2_footnotes.m2CloakPerPlusGp() * 2 != 20000)
            ++bad;
        // a crystal ball with two extra
        // features is 3,000 x.p. (base +
        // 2 x 100%)
        if (miscmagic_table2_footnotes.m2CrystalBallBaseXp() != 1000 ||
            miscmagic_table2_footnotes.m2CrystalBallBaseGp() != 5000 ||
            miscmagic_table2_footnotes.m2CrystalBallFeatureBonusPct() != 100 ||
            miscmagic_table2_footnotes.m2CrystalBallBaseXp() + 2 *
            (miscmagic_table2_footnotes.m2CrystalBallBaseXp() *
             miscmagic_table2_footnotes.m2CrystalBallFeatureBonusPct() / 100)
                != 3000) ++bad;
        // clamped flag reads land on the
        // Candle (C) and Eyes of
        // Petrification (triple)
        if (!miscmagic_table2_footnotes.m2UsableByCleric(-99) ||
            miscmagic_table2_footnotes.m2UsableByMagicUser(-99) ||
            !miscmagic_table2_footnotes.m2IsTripleStar(99)) ++bad;
        printf("R226 misc table 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
