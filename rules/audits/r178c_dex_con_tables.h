    // ---- R178c: the DEX and CON tables audit ----
    // PHB pp.11-12: the printed DEX reaction and
    // defensive ladders and the CON hit-point,
    // system-shock and resurrection-survival
    // columns, pinned R178c (the R177 founding
    // read divergences 1 and 2 closed). The
    // 16-score walks and the clamps.
    {
        int bad = 0;
        static const int kDexRe[16] = {
            -3, -2, -1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 2, 3
        };
        static const int kDexDef[16] = {
            4, 3, 2, 1, 0, 0, 0, 0, 0, 0,
            0, 0, -1, -2, -3, -4
        };
        static const int kConHp[16] = {
            -2, -1, -1, -1, 0, 0, 0, 0, 0, 0,
            0, 0, 1, 2, 2, 2
        };
        static const int kShock[16] = {
            35, 40, 45, 50, 55, 60, 65, 70, 75,
            80, 85, 88, 91, 95, 97, 99
        };
        static const int kRes[16] = {
            40, 45, 50, 55, 60, 65, 70, 75, 80,
            85, 90, 92, 94, 96, 98, 100
        };
        for (int i = 0; i < 16; ++i) {
            uint8_t s = (uint8_t)(i + 3);
            if (rules::dexReactionAdj(s) != kDexRe[i]) ++bad;
            if (rules::dexDefensiveAdj(s) != kDexDef[i]) ++bad;
            if (rules::conHPAdj(s) != kConHp[i]) ++bad;
            if (rules::conSystemShock(s) != kShock[i]) ++bad;
            if (rules::conResSurvival(s) != kRes[i]) ++bad;
        }
        // the clamps: low scores read the first row,
        // high scores the last
        if (rules::dexReactionAdj(0) != -3 ||
            rules::dexReactionAdj(99) != 3) ++bad;
        if (rules::dexDefensiveAdj(0) != 4 ||
            rules::dexDefensiveAdj(99) != -4) ++bad;
        if (rules::conSystemShock(0) != 35 ||
            rules::conSystemShock(99) != 99) ++bad;
        if (rules::conResSurvival(0) != 40 ||
            rules::conResSurvival(99) != 100) ++bad;
        if (rules::conHPAdj(2) != -2 ||
            rules::conHPAdj(18) != 2) ++bad;
        printf("R178c DEX and CON tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
