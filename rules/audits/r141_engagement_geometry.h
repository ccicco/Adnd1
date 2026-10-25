    // ---- R141: engagement geometry audit ----
    // The R43 50' debt closes: a room fight opens at
    // the chamber's longest interior dimension in 10'
    // bands (floored at the 50' corridor convention,
    // capped at 120') - so the R116 long band (-5) is
    // finally reachable in play.
    {
        int bad = 0;
        // the pure helper: floor at 5, cap at 12, the
        // longest dimension wins
        if (rules::engagementBands(0, 0) != 5) ++bad;
        if (rules::engagementBands(2, 3) != 5) ++bad;
        if (rules::engagementBands(5, 5) != 5) ++bad;
        if (rules::engagementBands(7, 4) != 7) ++bad;
        if (rules::engagementBands(4, 9) != 9) ++bad;
        if (rules::engagementBands(12, 12) != 12) ++bad;
        if (rules::engagementBands(20, 30) != 12) ++bad;
        // the long band in play: a 12-tile chamber opens
        // at 120' - a sling (40' short) fires its long
        // shot at -5, and one band beyond is impossible
        int bands = rules::engagementBands(12, 5);
        if (bands != 12) ++bad;
        if (rules::missileRangeMod(bands * 10, 40) != -5)
            ++bad;
        if (!rules::missileInRange(bands * 10, 40)) ++bad;
        // the corridor convention holds: the old 50'
        // opening is the sling's medium band
        if (rules::missileRangeMod(50, 40) != -2) ++bad;
        if (rules::missileRangeMod(50, 50) != 0) ++bad;
        printf("R141 engagement geometry audit: bad %d\n", bad);
        if (bad) return 1;
    }
