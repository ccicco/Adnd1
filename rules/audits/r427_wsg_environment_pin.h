    // ---- R427: the WSG
    // environment pin audit ----
    // The environment data
    // slice pins Tables 4 and
    // 5 (rules/wsgenvfx.h,
    // prefix wse): Table 4 (the
    // 13 temperature bands, the
    // Str/Dex/Con reductions
    // nonstrenuous/strenuous,
    // the Land Move fractions,
    // the Attack Rolls penalty)
    // and Table 5 (the 6 wind
    // bands, the missile
    // adjustments with the xx
    // impossible cells, the
    // melee penalty, the
    // move-against-wind
    // fractions) verified cell
    // for cell with the 99
    // censuses, the book own
    // examples (the 105-degree
    // strength, the -30 move,
    // the 35-mph wind, the
    // 85/40 greater
    // reduction) and the
    // precipitation shifts;
    // census 352 -> 353.
    {
        using namespace rules;
        int bad = 0;
        if (wseTempBandCount() != 13
                || wseWindBandCount()
                != 6
                || wseStrenuousWindowTurns() != 2
                || wseExStrCapNonstren() != 18
                || wseExStrCapStren()
                != 17
                || !wsePercentileDisregarded()
                || !wseFractionRoundUp()
                || !wseAttackCumulative()
                || wseDamageFloor() != 1
                || !wseAssumesAttire()
                || !wseWindIsMaximum()
                || !wseMissileDirNoDiff()
                || !wseXxIsImpossible()
                || !wseMeleeCumulative()
                || !wsePerpNextLower()
                || !wseGreaterOfReductions()
                || wsePrecipModerateShift() != 1
                || wsePrecipHeavyShift() != 2
                || !wsePrecipCapAtBottom()
                || wseXxCensus() != 9)
            ++bad;
        int C4[13][9] = {
            {-1,-2,-4,-5,-1,-2,1,2,-4},
            {-1,-2,-3,-4,-1,-2,1,2,-3},
            {0,-1,-2,-3,0,-1,2,3,-2},
            {0,-1,-1,-2,0,-1,2,3,-1},
            {99,99,-1,-2,99,99,3,4,-1},
            {99,99,0,-1,99,99,3,4,99},
            {99,99,0,-1,99,99,99,99,99},
            {99,99,99,99,99,99,99,99,99},
            {99,99,99,99,0,-1,3,4,99},
            {0,-1,99,99,-1,-2,3,4,-1},
            {-1,-2,0,-1,-2,-3,2,3,-2},
            {-1,-3,-1,-2,-3,-4,1,2,-3},
            {-2,-4,-1,-3,-4,-5,1,2,-4}};
        int n99[9] = {0,0,0,0,0,0,0,0,0};
        int e99[9] = {5,5,3,3,4,4,2,2,4};
        for (int b = 0;
             b < wseTempBandCount();
             ++b) {
            for (int c = 0; c < 9;
                 ++c) {
                int v;
                if (c == 0)
                    v = wseTempStrNonstren(b);
                else if (c == 1)
                    v = wseTempStrStren(b);
                else if (c == 2)
                    v = wseTempDexNonstren(b);
                else if (c == 3)
                    v = wseTempDexStren(b);
                else if (c == 4)
                    v = wseTempConNonstren(b);
                else if (c == 5)
                    v = wseTempConStren(b);
                else if (c == 6)
                    v = wseTempLandMoveNum(b);
                else if (c == 7)
                    v = wseTempLandMoveDen(b);
                else v = wseTempAttack(b);
                if (v != C4[b][c])
                    ++bad;
                if (v == 99) ++n99[c];
            }
            if (wseTempLandMoveNum(b) == 99
                    != (wseTempLandMoveDen(b) == 99)
                || (wseTempLandMoveNum(b) != 99
                    && wseTempLandMoveDen(b)
                    != wseTempLandMoveNum(b) + 1))
                ++bad;
        }
        for (int c = 0; c < 9; ++c)
            if (n99[c] != e99[c])
                ++bad;
        // the band-for
        // boundaries
        if (wseTempBandFor(-40) != 0
                || wseTempBandFor(-41)
                != 0
                || wseTempBandFor(-39)
                != 1
                || wseTempBandFor(-30)
                != 1
                || wseTempBandFor(-29)
                != 2
                || wseTempBandFor(21)
                != 7
                || wseTempBandFor(79)
                != 7
                || wseTempBandFor(80)
                != 8
                || wseTempBandFor(100)
                != 10
                || wseTempBandFor(119)
                != 11
                || wseTempBandFor(120)
                != 12
                || wseTempBandFor(300)
                != 12)
            ++bad;
        // the book own
        // 105-degree strength
        // example
        if (wseTempBandFor(105) != 10
                || wseTempStrNonstren(10) != -1
                || wseTempStrStren(10)
                != -2)
            ++bad;
        // the -30 land move
        // example: 12 -> 6
        if (wseTempBandFor(-30) != 1
                || wseTempLandMoveNum(1) != 1
                || wseTempLandMoveDen(1) != 2
                || (12 * wseTempLandMoveNum(1))
                    / wseTempLandMoveDen(1) != 6
                || (9 * wseTempLandMoveNum(1) + 1)
                    / wseTempLandMoveDen(1) != 5)
            ++bad;
        int C5[6][7] = {
            {0,0,0,0,0,99,99},
            {0,-1,-2,-3,0,99,99},
            {-1,-2,-3,99,-1,3,4},
            {-2,-4,99,99,-2,2,3},
            {-4,-6,99,99,-4,1,2},
            {99,99,99,99,-8,1,4}};
        int xx = 0;
        for (int b = 0;
             b < wseWindBandCount();
             ++b) {
            int vals[7];
            vals[0] = wseWindMissilePb(b);
            vals[1] = wseWindMissileShort(b);
            vals[2] = wseWindMissileMed(b);
            vals[3] = wseWindMissileLong(b);
            vals[4] = wseWindMelee(b);
            vals[5] = wseWindMoveNum(b);
            vals[6] = wseWindMoveDen(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c]                    != C5[b][c])
                    ++bad;
                if (c < 4 && vals[c]
                    == 99)
                    ++xx;
            }
        }
        if (xx != wseXxCensus())
            ++bad;
        // the wind band-for
        // boundaries
        if (wseWindBandFor(0) != 0
                || wseWindBandFor(10)
                != 0
                || wseWindBandFor(11)
                != 1
                || wseWindBandFor(45)
                != 3
                || wseWindBandFor(46)
                != 4
                || wseWindBandFor(79)
                != 4
                || wseWindBandFor(80)
                != 5
                || wseWindBandFor(200)
                != 5)
            ++bad;
        // the book own 35-mph
        // example: melee -2,
        // 12 -> 8 against the
        // wind, 9 perpendicular
        if (wseWindBandFor(35) != 3
                || wseWindMelee(3)
                != -2
                || (12 * wseWindMoveNum(3))
                    / wseWindMoveDen(3) != 8
                || (12 * wseWindMoveNum(2))
                    / wseWindMoveDen(2) != 9)
            ++bad;
        // the 85/40 example: the
        // greater reduction is
        // 2/3 (temperature 3/4
        // vs wind 2/3)
        if (wseTempBandFor(85) != 8
                || wseWindBandFor(40)
                != 3
                || !(wseWindMoveNum(3) * wseTempLandMoveDen(8)
                    < wseTempLandMoveNum(8) * wseWindMoveDen(3)))
            ++bad;
        // the precipitation
        // examples: moderate
        // rain with 0-10 wind
        // behaves as 11-20;
        // heavy snow with 11-20
        // behaves as 31-45; the
        // raw shift 5 + 2 = 7
        // overshoots the
        // bottom, so the
        // wsePrecipCapAt
        // Bottom pin caps it
        if (wseWindBandFor(5)
                + wsePrecipModerateShift() != 1
                || wseWindMissileShort(1) != -1
                || wseWindBandFor(15)
                + wsePrecipHeavyShift() != 3
                || wseWindMelee(3)
                != -2
                || wseWindBandFor(90) != 5
                || (wseWindBandFor(90)
                    + wsePrecipHeavyShift() != 7))
            ++bad;
        printf("R427 WSG environment pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
