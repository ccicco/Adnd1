    // ---- R189: the weapon tables verify audit ----
    // All 50 weight/damage rows, the speed cross-verify
    // against the R158 ladder, and the printed notes.
    {
        int bad = 0;
        // the weight/damage chart, row by row (50 cells
        // x weight, S/M min/max, L min/max)
        if (rules::weaponChartRowCount() != 50) ++bad;
        static const int kWeight[50] = {
            2,
            75,
            50,
            125,
            100,
            150,
            15,
            30,
            10,
            5,
            60,
            80,
            150,
            35,
            75,
            75,
            100,
            80,
            150,
            175,
            150,
            50,
            20,
            40,
            50,
            100,
            150,
            100,
            50,
            125,
            80,
            60,
            40,
            80,
            1,
            2,
            50,
            40,
            2,
            1,
            40,
            50,
            50,
            100,
            75,
            60,
            35,
            250,
            50,
            125,
        };
        static const int kSM[50][2] = {
            { 1, 6 },
            { 1, 8 },
            { 1, 6 },
            { 2, 8 },
            { 1, 8 },
            { 2, 8 },
            { 1, 6 },
            { 1, 6 },
            { 1, 4 },
            { 1, 3 },
            { 1, 6 },
            { 1, 8 },
            { 2, 7 },
            { 2, 5 },
            { 1, 8 },
            { 1, 6 },
            { 2, 8 },
            { 2, 8 },
            { 2, 8 },
            { 1, 10 },
            { 2, 8 },
            { 2, 5 },
            { 1, 6 },
            { 1, 6 },
            { 1, 6 },
            { 2, 7 },
            { 3, 9 },
            { 2, 7 },
            { 1, 6 },
            { 2, 8 },
            { 1, 6 },
            { 2, 7 },
            { 2, 5 },
            { 1, 6 },
            { 1, 4 },
            { 2, 5 },
            { 2, 8 },
            { 1, 8 },
            { 2, 5 },
            { 1, 4 },
            { 1, 6 },
            { 2, 7 },
            { 1, 6 },
            { 2, 8 },
            { 2, 8 },
            { 1, 8 },
            { 1, 6 },
            { 1, 10 },
            { 2, 7 },
            { 2, 8 },
        };
        static const int kL[50][2] = {
            { 1, 6 },
            { 1, 8 },
            { 1, 4 },
            { 3, 12 },
            { 1, 6 },
            { 1, 10 },
            { 1, 3 },
            { 1, 3 },
            { 1, 3 },
            { 1, 2 },
            { 1, 8 },
            { 1, 10 },
            { 2, 8 },
            { 2, 5 },
            { 2, 8 },
            { 1, 10 },
            { 2, 12 },
            { 1, 8 },
            { 2, 8 },
            { 2, 12 },
            { 1, 6 },
            { 1, 4 },
            { 1, 6 },
            { 1, 4 },
            { 1, 8 },
            { 2, 12 },
            { 3, 18 },
            { 1, 6 },
            { 1, 4 },
            { 2, 7 },
            { 2, 7 },
            { 2, 8 },
            { 1, 4 },
            { 1, 12 },
            { 1, 4 },
            { 2, 7 },
            { 2, 8 },
            { 1, 8 },
            { 2, 7 },
            { 1, 4 },
            { 1, 8 },
            { 2, 12 },
            { 1, 6 },
            { 2, 16 },
            { 2, 7 },
            { 1, 12 },
            { 1, 8 },
            { 3, 18 },
            { 3, 12 },
            { 2, 8 },
        };
        for (int i = 0; i < 50; ++i) {
            if (rules::weaponChartWeight(i) != kWeight[i]) ++bad;
            if (rules::weaponChartDamageSMMin(i) != kSM[i][0]) ++bad;
            if (rules::weaponChartDamageSMMax(i) != kSM[i][1]) ++bad;
            if (rules::weaponChartDamageLMin(i) != kL[i][0]) ++bad;
            if (rules::weaponChartDamageLMax(i) != kL[i][1]) ++bad;
        }
        // the name ladder, head and tail
        if (std::string(rules::weaponChartName(0))
            != "arrow") ++bad;
        if (std::string(rules::weaponChartName(49))
            != "voulge") ++bad;
        if (std::string(rules::weaponChartName(40))
            != "spear") ++bad;
        // spot rows against the print
        if (rules::weaponChartWeight(1) != 75) ++bad;
        if (rules::weaponChartDamageSMMin(1) != 1
            || rules::weaponChartDamageSMMax(1) != 8) ++bad;
        if (rules::weaponChartDamageLMin(26) != 3
            || rules::weaponChartDamageLMax(26) != 18) ++bad;
        if (rules::weaponChartWeight(47) != 250) ++bad;
        if (rules::weaponChartDamageLMin(47) != 3
            || rules::weaponChartDamageLMax(47) != 18) ++bad;
        if (rules::weaponChartDamageSMMin(43) != 2
            || rules::weaponChartDamageSMMax(43) != 8) ++bad;
        if (rules::weaponChartDamageLMin(43) != 2
            || rules::weaponChartDamageLMax(43) != 16) ++bad;
        // the clamps: index out of range reads the edges
        if (rules::weaponChartWeight(-5) != 2) ++bad;
        if (rules::weaponChartWeight(99) != 125) ++bad;
        if (std::string(rules::weaponChartName(-1))
            != "arrow") ++bad;
        // the spear weight spread: the print 40-60
        {
            int lo = 0, hi = 0;
            rules::spearWeightRange(lo, hi);
            if (lo != 40 || hi != 60) ++bad;
            if (rules::weaponChartWeight(40) != 40) ++bad;
        }
        // the speed cross-verify: every verified pair
        // matches the R158 engine ladder value
        if (rules::weaponSpeedVerifiedCount() != 18) ++bad;
        for (int i = 0; i < 18; ++i) {
            const char* n = rules::weaponSpeedVerifiedName(i);
            int printed = rules::weaponSpeedVerifiedFactor(i);
            int engine = rules::weaponSpeedFactor(n);
            if (engine != printed) ++bad;
        }
        // the spear default 7 sits inside the printed 6-8
        {
            int lo = 0, hi = 0;
            rules::spearSpeedFactorRange(lo, hi);
            if (lo != 6 || hi != 8) ++bad;
            if (rules::weaponSpeedFactor("spear") != 7) ++bad;
        }
        // the horseman flail: OCR-mangled cell, the engine
        // 6 stays recorded convention
        if (rules::weaponSpeedFactor("horseman flail") != 6) ++bad;
        // unknown weapons read 0 (the caller decides)
        if (rules::weaponSpeedFactor("vorpal blade") != 0) ++bad;
        // the printed notes: the lances double from a
        // charging mount, rows 24-26 only
        if (!rules::lanceChargingDouble(24)) ++bad;
        if (!rules::lanceChargingDouble(25)) ++bad;
        if (!rules::lanceChargingDouble(26)) ++bad;
        if (rules::lanceChargingDouble(23)) ++bad;
        if (rules::lanceChargingDouble(27)) ++bad;
        if (!rules::spearSetChargingDouble()) ++bad;
        // the chart-2 combat note
        if (rules::weaponBackOrUnseenBonus() != 2) ++bad;
        if (rules::weaponStunnedProneMotionlessBonus()
            != 4) ++bad;
        printf("R189 weapon tables verify audit: bad %d\n", bad);
        if (bad) return 1;
    }
