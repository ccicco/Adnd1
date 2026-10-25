    // ---- R238: the III.E table 4 pins audit ----
    // DMG p.129-130: the class marks, the
    // asterisk ladder and the dual-value rows
    // of TABLE (III.E.) 4.
    {
        int bad = 0;
        // the row identity: the 36 die bands
        if (rules::m4RowCount() != 36) ++bad;
        static const int kLo[36] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
            11, 12, 13, 16, 18, 19, 20, 21, 24, 28,
            34, 36, 39, 43, 45, 47, 49, 51, 54, 61,
            65, 71, 75, 77, 85, 86,
        };
        static const int kHi[36] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
            11, 12, 15, 17, 18, 19, 20, 23, 27, 33,
            35, 38, 42, 44, 46, 48, 50, 53, 60, 64,
            70, 74, 76, 84, 85, 100,
        };
        static const int kC[36] = {
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 1, 1, 0, 0, 1, 0, 0, 0, 0,
            1, 1, 1, 0, 0, 0,
        };
        static const int kF[36] = {
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
        };
        static const int kM[36] = {
            1, 1, 1, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
        };
        static const int kT[36] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
        };
        static const int kStar[36] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 2,
            0, 0, 0, 3, 4, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
        };
        static const int kDual[36] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1,
        };
        for (int i = 0; i < 36; ++i)
            if (rules::m4RowLo(i) != kLo[i] ||
                rules::m4RowHi(i) != kHi[i] ||
                rules::m4UsableByCleric(i) != kC[i] ||
                rules::m4UsableByFighter(i) != kF[i] ||
                rules::m4UsableByMagicUser(i) != kM[i] ||
                rules::m4UsableByThief(i) != kT[i] ||
                rules::m4StarCount(i) != kStar[i] ||
                rules::m4IsDualValued(i) != kDual[i])
                ++bad;
        for (int i = 1; i < 36; ++i)
            if (rules::m4RowLo(i) !=
                rules::m4RowHi(i - 1) + 1) ++bad;
        if (rules::m4RowLo(-5) != 1 ||
            rules::m4RowHi(99) != 100) ++bad;
        // the class marks: the Librams and the
        // Pearl of Power are (M); the Golems
        // Manual is (C, M); the Puissant Manual
        // and the Mattock are (F); the
        // Stealthy Manual and the Nets are (T)
        if (rules::m4ClericCount() != 8 ||
            rules::m4FighterCount() != 4 ||
            rules::m4MagicUserCount() != 6 ||
            rules::m4ThiefCount() != 3) ++bad;
        if (!rules::m4UsableByMagicUser(0) ||
            !rules::m4UsableByMagicUser(1) ||
            !rules::m4UsableByMagicUser(2)) ++bad;
        if (!rules::m4UsableByCleric(6) ||
            !rules::m4UsableByMagicUser(6)) ++bad;
        if (!rules::m4UsableByFighter(7) ||
            rules::m4UsableByCleric(7)) ++bad;
        if (!rules::m4UsableByThief(9) ||
            rules::m4UsableByFighter(9)) ++bad;
        if (!rules::m4UsableByFighter(10) ||
            rules::m4UsableByMagicUser(10)) ++bad;
        if (rules::m4UsableByCleric(8) ||
            rules::m4UsableByFighter(8) ||
            rules::m4UsableByMagicUser(8) ||
            rules::m4UsableByThief(8)) ++bad;
        if (!rules::m4UsableByMagicUser(14) ||
            rules::m4UsableByMagicUser(15)) ++bad;
        if (!rules::m4UsableByCleric(19) ||
            rules::m4UsableByMagicUser(19)) ++bad;
        if (!rules::m4UsableByCleric(21) ||
            !rules::m4UsableByFighter(21) ||
            !rules::m4UsableByThief(21) ||
            !rules::m4UsableByCleric(22) ||
            !rules::m4UsableByFighter(22) ||
            !rules::m4UsableByThief(22)) ++bad;
        if (!rules::m4UsableByMagicUser(24) ||
            !rules::m4UsableByCleric(25) ||
            rules::m4UsableByCleric(24)) ++bad;
        if (!rules::m4UsableByCleric(30) ||
            !rules::m4UsableByCleric(31) ||
            !rules::m4UsableByCleric(32)) ++bad;
        if (rules::m4UsableByCleric(33) ||
            rules::m4UsableByCleric(34)) ++bad;
        // the asterisk ladder: the Necklace of
        // Missiles 24-27 (1 star, per hit die of
        // each missile), the Prayer Beads 28-33
        // (2 stars, per special bead), the
        // Pigments 43-44 (3 stars, per pot), the
        // Pearl of Power 45-46 (4 stars, per
        // level of spell)
        if (rules::m4StarCount(18) != 1 ||
            rules::m4StarCount(19) != 2 ||
            rules::m4StarCount(23) != 3 ||
            rules::m4StarCount(24) != 4 ||
            rules::m4StarCount(17) != 0) ++bad;
        // a 5-hit-die missile is 250 x.p. /
        // 1,000 g.p.
        if (rules::m4MissilePerHitDieXp() != 50 ||
            rules::m4MissilePerHitDieGp() != 200 ||
            rules::m4MissilePerHitDieXp() * 5 != 250 ||
            rules::m4MissilePerHitDieGp() * 5 != 1000)
            ++bad;
        // two special beads are 1,000 x.p. /
        // 6,000 g.p.
        if (rules::m4BeadPerSpecialXp() != 500 ||
            rules::m4BeadPerSpecialGp() != 3000 ||
            rules::m4BeadPerSpecialXp() * 2 != 1000 ||
            rules::m4BeadPerSpecialGp() * 2 != 6000)
            ++bad;
        // two pots of pigments are 1,000 x.p.
        // / 6,000 g.p.
        if (rules::m4PigmentsPerPotXp() != 500 ||
            rules::m4PigmentsPerPotGp() != 3000 ||
            rules::m4PigmentsPerPotXp() * 2 != 1000 ||
            rules::m4PigmentsPerPotGp() * 2 != 6000)
            ++bad;
        // a 3rd-level spell pearl is 600 x.p. /
        // 6,000 g.p.
        if (rules::m4PearlPerSpellLevelXp() != 200 ||
            rules::m4PearlPerSpellLevelGp() != 2000 ||
            rules::m4PearlPerSpellLevelXp() * 3 != 600 ||
            rules::m4PearlPerSpellLevelGp() * 3 != 6000)
            ++bad;
        // the dual rows: the Medallion of ESP
        // 1,000/3,000 x.p., 10,000/30,000 g.p.;
        // the Feather Token 500/1,000 x.p.,
        // 2,000/7,000 g.p.
        if (!rules::m4IsDualValued(12) ||
            rules::m4IsDualValued(13) ||
            !rules::m4IsDualValued(35) ||
            rules::m4IsDualValued(34)) ++bad;
        if (rules::m4MedallionEspXpLow() != 1000 ||
            rules::m4MedallionEspXpHigh() != 3000 ||
            rules::m4MedallionEspGpLow() != 10000 ||
            rules::m4MedallionEspGpHigh() != 30000)
            ++bad;
        if (rules::m4FeatherTokenXpLow() != 500 ||
            rules::m4FeatherTokenXpHigh() != 1000 ||
            rules::m4FeatherTokenGpLow() != 2000 ||
            rules::m4FeatherTokenGpHigh() != 7000)
            ++bad;
        // clamped reads land on the first
        // Libram (M, unstarred) below and the
        // Feather Token (dual) above
        if (rules::m4StarCount(-99) != 0 ||
            !rules::m4UsableByMagicUser(-99) ||
            !rules::m4IsDualValued(99) ||
            rules::m4UsableByCleric(99)) ++bad;
        printf("R238 misc table 4 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
