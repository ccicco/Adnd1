    // ---- R221: the III.A potions prose pins audit ----
    // DMG pp.125-126: the three footnotes
    // that frame the III.A POTIONS table -
    // the * control die rolls, the **
    // DM-misleading potions, the (F)
    // fighter-only potions.
    {
        Potions potions;
        int bad = 0;
        // the row identity: the 35 die bands
        if (potions.potionRowCount() != 35) ++bad;
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
            if (potions.potionRowLo(i) != kLo[i] ||
                potions.potionRowHi(i) != kHi[i]) ++bad;
        for (int i = 1; i < 35; ++i)
            if (potions.potionRowLo(i) !=
                potions.potionRowHi(i - 1) + 1) ++bad;
        if (potions.potionRowLo(-5) != 1 ||
            potions.potionRowLo(99) != 98 ||
            potions.potionRowHi(99) != 100) ++bad;
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
            if (potions.potionIsControl(i) != kC[i] ||
                potions.potionIsMislead(i) != kM[i] ||
                potions.potionIsFighterOnly(i) != kF[i])
                ++bad;
        if (potions.potionControlCount() != 6 ||
            potions.potionMisleadCount() != 2 ||
            potions.potionFighterOnlyCount() != 4) ++bad;
        // the * rows: Animal and Undead Control
        if (!potions.potionIsControl(0) ||
            !potions.potionIsControl(33)) ++bad;
        // JUDGMENT: Plant Control prints with
        // NO star - pinned as printed
        if (potions.potionIsControl(26)) ++bad;
        // the ** rows: Delusion and Poison
        if (!potions.potionIsMislead(4) ||
            !potions.potionIsMislead(28)) ++bad;
        // the (F) rows: Giant Strength,
        // Heroism, Invulnerability, Super-Heroism
        if (!potions.potionIsFighterOnly(13) ||
            !potions.potionIsFighterOnly(16) ||
            !potions.potionIsFighterOnly(19) ||
            !potions.potionIsFighterOnly(30)) ++bad;
        // clamped flag reads
        if (potions.potionIsControl(-9) != 1 ||
            potions.potionIsFighterOnly(99) != 0) ++bad;
        printf("R221 potions prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
