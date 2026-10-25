    // ---- R176: the printed XP tables audit -------
    // PHB pp.20-31: the four printed class XP
    // boundary rows, pinned R176 (the R162 open
    // box closed). Convention: the XP to attain
    // level N is the band lower bound - 1. The
    // 13-row walk per class, the printed adders
    // via the beyond-table probes, and the clamps.
    {
        int bad = 0;
        static const int kF[13] = {
            0, 2000, 4000, 8000, 18000, 35000,
            70000, 125000, 250000, 500000,
            750000, 1000000, 1250000
        };
        static const int kM[13] = {
            0, 2500, 5000, 10000, 22500, 40000,
            60000, 90000, 135000, 250000,
            375000, 750000, 1125000
        };
        static const int kC[13] = {
            0, 1500, 3000, 6000, 13000, 27500,
            55000, 110000, 225000, 450000,
            675000, 900000, 1125000
        };
        static const int kT[13] = {
            0, 1250, 2500, 5000, 10000, 20000,
            42500, 70000, 110000, 160000,
            220000, 440000, 660000
        };
        for (int i = 0; i < 13; ++i) {
            if (rules::xpForLevel(rules::CLASS_FIGHTER,
                                  i + 1) != kF[i]) ++bad;
            if (rules::xpForLevel(rules::CLASS_MAGIC_USER,
                                  i + 1) != kM[i]) ++bad;
            if (rules::xpForLevel(rules::CLASS_CLERIC,
                                  i + 1) != kC[i]) ++bad;
            if (rules::xpForLevel(rules::CLASS_THIEF,
                                  i + 1) != kT[i]) ++bad;
        }
        // the printed adders, probed beyond the rows
        // (fighter 250k past the 11th, MU 375k past
        // the 12th, cleric 225k past the 11th, thief
        // 220k past the 12th)
        if (rules::xpForLevel(rules::CLASS_FIGHTER, 14)
            != 1500000) ++bad;
        if (rules::xpForLevel(rules::CLASS_FIGHTER, 15)
            != 1750000) ++bad;
        if (rules::xpForLevel(rules::CLASS_MAGIC_USER, 14)
            != 1500000) ++bad;
        if (rules::xpForLevel(rules::CLASS_MAGIC_USER, 15)
            != 1875000) ++bad;
        if (rules::xpForLevel(rules::CLASS_CLERIC, 14)
            != 1350000) ++bad;
        if (rules::xpForLevel(rules::CLASS_CLERIC, 15)
            != 1575000) ++bad;
        if (rules::xpForLevel(rules::CLASS_THIEF, 14)
            != 880000) ++bad;
        if (rules::xpForLevel(rules::CLASS_THIEF, 15)
            != 1100000) ++bad;
        // the clamps: level 0 or below reads 0, a bad
        // class reads 0
        if (rules::xpForLevel(rules::CLASS_FIGHTER, 0) != 0 ||
            rules::xpForLevel(rules::CLASS_FIGHTER, -5) != 0)
            ++bad;
        if (rules::xpForLevel(-1, 5) != 0 ||
            rules::xpForLevel(99, 5) != 0) ++bad;
        printf("R176 printed XP tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
