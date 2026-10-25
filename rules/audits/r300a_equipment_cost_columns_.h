    // ---- R300a: the equipment cost columns seam audit ----
    // The printed BASIC EQUIPMENT AND SUPPLIES COSTS tables
    // (rules/equipcosts.h) walked cell for cell against this
    // local ground truth, the clamps, the coin-unit identity
    // (exactly one of the gold and silver columns nonzero on
    // every arms row), the six silver ammo rows and the
    // monetary-system pin (20 s.p. = 1 g.p.). The ENGINE side
    // (the items costGp repins) is the engine audit below.
    {
        int bad = 0;
        static const int kGold[52] = {
             0,   1,   1,   5,   1,   7,   6,   6,  75, 100,
            60,  15,  20,  12,   2,   0,   3,   8,   3,   8,
             4,   6,  10,   5,   7,   9,   7,   1,   0,   6,
             8,   4,   5,  10,   8,   5,   3,   0,   2,   4,
            15,   0,   0,   1,   3,  25,  10,  15,   8,  30,
             4,   2,
        };
        static const int kSilver[52] = {
             2,   0,   0,   0,   0,   0,   0,   0,   0,   0,
             0,   0,   0,   0,   0,   5,   0,   0,   0,   0,
             0,   0,   0,   0,   0,   0,   0,   0,  10,   0,
             0,   0,   0,   0,   0,   0,   0,   1,   0,   0,
             0,  15,  10,   0,   0,   0,   0,   0,   0,   0,
             0,   0,
        };
        static const int kArmor[14] = {
            90,  75,  15,  10,   5,   4,  400,  30,
            45,  15,  10,   1,  80,  15,
        };
        // the row counts
        if (rules::eqcArmsCount() != 52 ||
            rules::eqcArmorCount() != 14) ++bad;
        // the arms gold column, every row
        for (int i = 0; i < 52; ++i)
            if (rules::eqcArmsGold(i) != kGold[i]) ++bad;
        // the arms silver column, every row
        for (int i = 0; i < 52; ++i)
            if (rules::eqcArmsSilver(i) != kSilver[i]) ++bad;
        // the armor gold column, every row
        for (int i = 0; i < 14; ++i)
            if (rules::eqcArmorGold(i) != kArmor[i]) ++bad;
        // the coin-unit identity: exactly one nonzero
        // column on every arms row
        for (int i = 0; i < 52; ++i)
            if ((rules::eqcArmsGold(i) == 0) ==
                (rules::eqcArmsSilver(i) == 0)) ++bad;
        // the clamps: past either edge reads the edge row
        // (the edges differ in both columns - the single
        // arrow 0 gold 2 silver; the voulge 2 gold 0 silver)
        if (rules::eqcArmsGold(-5) != 0 ||
            rules::eqcArmsSilver(-5) != 2 ||
            rules::eqcArmsGold(99) != 2 ||
            rules::eqcArmsSilver(99) != 0) ++bad;
        if (rules::eqcArmorGold(-5) != 90 ||
            rules::eqcArmorGold(99) != 15) ++bad;
        // the six silver rows are the ammo prices
        if (rules::eqcArmsSilver(0) != 2 ||
            rules::eqcArmsSilver(15) != 5 ||
            rules::eqcArmsSilver(28) != 10 ||
            rules::eqcArmsSilver(37) != 1 ||
            rules::eqcArmsSilver(41) != 15 ||
            rules::eqcArmsSilver(42) != 10) ++bad;
        // the monetary-system pin
        if (rules::eqcSilverPerGold() != 20) ++bad;
        printf("R300a equipment cost columns seam audit: bad %d\n", bad);
    }
