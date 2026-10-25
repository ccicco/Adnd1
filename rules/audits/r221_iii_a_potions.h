    // ---- R221: the III.A potions prose pins audit ----
    // DMG pp.125-126: the three footnotes
    // that frame the III.A POTIONS table -
    // the * control die rolls, the **
    // DM-misleading potions, the (F)
    // fighter-only potions.
    {
        int bad = 0;
        // the row identity: the 35 die bands
        if (rules::potionRowCount() != 35) ++bad;
    static const int kLo[35] = {
        1, 4, 7, 10, 13, 16, 19, 21, 24, 27,
        30, 33, 35, 37, 40, 42, 48, 50, 52, 55,
        58, 61, 64, 67, 70, 73, 76, 79, 82, 85,
        88, 91, 94, 97, 98,
    };
    static const int kHi[35] = {
        3, 6, 9, 12, 15, 18, 20, 23, 26, 29,
        32, 34, 36, 39, 41, 47, 49, 51, 54, 57,
        60, 63, 66, 69, 72, 75, 78, 81, 84, 87,
        90, 93, 96, 97, 100,
    };
        for (int i = 0; i < 35; ++i)
            if (rules::potionRowLo(i) != kLo[i] ||
                rules::potionRowHi(i) != kHi[i]) ++bad;
        for (int i = 1; i < 35; ++i)
            if (rules::potionRowLo(i) !=
                rules::potionRowHi(i - 1) + 1) ++bad;
        if (rules::potionRowLo(-5) != 1 ||
            rules::potionRowLo(99) != 98 ||
            rules::potionRowHi(99) != 100) ++bad;
        // the * control rows

    static const int kC[35] = {
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 1, 1, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0,
    };
    static const int kM[35] = {
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0,
    };
    static const int kF[35] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
    };
        for (int i = 0; i < 35; ++i)
            if (rules::potionIsControl(i) != kC[i] ||
                rules::potionIsMislead(i) != kM[i] ||
                rules::potionIsFighterOnly(i) != kF[i])
                ++bad;
        if (rules::potionControlCount() != 6 ||
            rules::potionMisleadCount() != 2 ||
            rules::potionFighterOnlyCount() != 4) ++bad;
        // the * rows: Animal and Undead Control
        if (!rules::potionIsControl(0) ||
            !rules::potionIsControl(33)) ++bad;
        // JUDGMENT: Plant Control prints with
        // NO star - pinned as printed
        if (rules::potionIsControl(26)) ++bad;
        // the ** rows: Delusion and Poison
        if (!rules::potionIsMislead(4) ||
            !rules::potionIsMislead(28)) ++bad;
        // the (F) rows: Giant Strength,
        // Heroism, Invulnerability, Super-Heroism
        if (!rules::potionIsFighterOnly(13) ||
            !rules::potionIsFighterOnly(16) ||
            !rules::potionIsFighterOnly(19) ||
            !rules::potionIsFighterOnly(30)) ++bad;
        // clamped flag reads
        if (rules::potionIsControl(-9) != 1 ||
            rules::potionIsFighterOnly(99) != 0) ++bad;
        printf("R221 potions prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
