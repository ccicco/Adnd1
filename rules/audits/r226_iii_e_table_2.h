    // ---- R226: the III.E table 2 pins audit ----
    // DMG p.128: the class marks and the
    // asterisk rows of TABLE (III.E.) 2.
    {
        int bad = 0;
        // the row identity: the 30 die bands
        if (rules::m2RowCount() != 30) ++bad;
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
            if (rules::m2RowLo(i) != kLo[i] ||
                rules::m2RowHi(i) != kHi[i] ||
                rules::m2UsableByCleric(i) != kC[i] ||
                rules::m2UsableByMagicUser(i) != kM[i] ||
                rules::m2IsPerPlusValued(i) != kPP[i] ||
                rules::m2HasFeatureAsterisk(i) != kFeat[i] ||
                rules::m2IsTripleStar(i) != kTri[i]) ++bad;
        for (int i = 1; i < 30; ++i)
            if (rules::m2RowLo(i) !=
                rules::m2RowHi(i - 1) + 1) ++bad;
        if (rules::m2RowLo(-5) != 1 ||
            rules::m2RowHi(99) != 100) ++bad;
        // the class marks: the Candle is
        // (C); the Censers, the Balls and
        // the Eyes of Charming are (M)
        if (rules::m2ClericCount() != 1 ||
            rules::m2MagicUserCount() != 5) ++bad;
        if (!rules::m2UsableByCleric(0) ||
            rules::m2UsableByCleric(1)) ++bad;
        if (!rules::m2UsableByMagicUser(2) ||
            !rules::m2UsableByMagicUser(3) ||
            !rules::m2UsableByMagicUser(11) ||
            !rules::m2UsableByMagicUser(12) ||
            !rules::m2UsableByMagicUser(26) ||
            rules::m2UsableByMagicUser(1) ||
            rules::m2UsableByMagicUser(27)) ++bad;
        // the asterisk rows: Cloak of
        // Protection 33-55 per plus,
        // Crystal Ball 56-60 the feature
        // asterisk, Eyes of Petrification
        // 00 the triple star
        if (!rules::m2IsPerPlusValued(10) ||
            rules::m2IsPerPlusValued(11)) ++bad;
        if (!rules::m2HasFeatureAsterisk(11) ||
            rules::m2HasFeatureAsterisk(10)) ++bad;
        if (!rules::m2IsTripleStar(29) ||
            rules::m2IsTripleStar(28)) ++bad;
        // a +2 cloak is 2,000 x.p. /
        // 20,000 g.p.
        if (rules::m2CloakPerPlusXp() != 1000 ||
            rules::m2CloakPerPlusGp() != 10000 ||
            rules::m2CloakPerPlusXp() * 2 != 2000 ||
            rules::m2CloakPerPlusGp() * 2 != 20000)
            ++bad;
        // a crystal ball with two extra
        // features is 3,000 x.p. (base +
        // 2 x 100%)
        if (rules::m2CrystalBallBaseXp() != 1000 ||
            rules::m2CrystalBallBaseGp() != 5000 ||
            rules::m2CrystalBallFeatureBonusPct() != 100 ||
            rules::m2CrystalBallBaseXp() + 2 *
            (rules::m2CrystalBallBaseXp() *
             rules::m2CrystalBallFeatureBonusPct() / 100)
                != 3000) ++bad;
        // clamped flag reads land on the
        // Candle (C) and Eyes of
        // Petrification (triple)
        if (!rules::m2UsableByCleric(-99) ||
            rules::m2UsableByMagicUser(-99) ||
            !rules::m2IsTripleStar(99)) ++bad;
        printf("R226 misc table 2 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
