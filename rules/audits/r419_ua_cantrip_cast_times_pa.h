    // ---- R419: the cantrip
    // casting-time resolution
    // part 2 pin audit ----
    // The PDF read completes the
    // resolution: the R415
    // (person-affecting), R416
    // (personal) and R417
    // (haunting-sound) casting-
    // time hole families resolve
    // - 28 cells, all clean unit
    // fractions one segment over
    // the denominator. The
    // denominator censuses count
    // (the person-affecting 1/3/2/4
    // at 1/2, 1/3, 1/8, 1/10; the
    // personal 7/3/0/0; the
    // haunting-sound 0/0/5/3 - the
    // 1/6 lands inside the 2..10
    // band the p. 45 header prints),
    // each family census totals its
    // roster count, and every
    // denominator sits in the band.
    // The read also resolves the two
    // R416 areas (the sphere and the
    // line - the values cross-derive
    // against the mechanics pins: 3
    // inches == the 1/4 foot sphere,
    // 6 inches == the 1/2 foot line),
    // the range units (the AD&D 1"
    // notation), the slow-poison defer
    // (1 day) and the creak reads
    // (the former 1/3 segment, the
    // traverse 10 feet); census
    // 345 -> 346.
    {
        using namespace rules;
        int bad = 0;
        if (ucpCastTimeDenCount(2) != 1
                || ucpCastTimeDenCount(3) != 3
                || ucpCastTimeDenCount(8) != 2
                || ucpCastTimeDenCount(10) != 4)
            ++bad;
        if (ucoCastTimeDenCount(2) != 7
                || ucoCastTimeDenCount(3) != 3
                || ucoCastTimeDenCount(8) != 0
                || ucoCastTimeDenCount(10) != 0)
            ++bad;
        if (uchCastTimeDenCount(2) != 0
                || uchCastTimeDenCount(3) != 0
                || uchCastTimeDenCount(6) != 5
                || uchCastTimeDenCount(10) != 3)
            ++bad;
        if (ucpCastTimeDenCount(2)
                + ucpCastTimeDenCount(3)
                + ucpCastTimeDenCount(8)
                + ucpCastTimeDenCount(10)
                != 10) ++bad;
        if (ucoCastTimeDenCount(2)
                + ucoCastTimeDenCount(3)
                + ucoCastTimeDenCount(8)
                + ucoCastTimeDenCount(10)
                != 10) ++bad;
        if (uchCastTimeDenCount(2)
                + uchCastTimeDenCount(3)
                + uchCastTimeDenCount(6)
                + uchCastTimeDenCount(10)
                != 8) ++bad;
        // the 2..10 norm band
        for (int i = 0; i < 10;
 ++i)
            if (ucpCastTimeDen(i) < 2
                || ucpCastTimeDen(i) > 10)
                ++bad;
        for (int i = 0; i < 10;
 ++i)
            if (ucoCastTimeDen(i) < 2
                || ucoCastTimeDen(i) > 10)
                ++bad;
        for (int i = 0; i < 8;
 ++i)
            if (uchCastTimeDen(i) < 2
                || uchCastTimeDen(i) > 10)
                ++bad;
        // the resolved areas cross-
        // derive against the
        // standing mechanics pins
        if (ucoPersonal(1).areaVal
                != ucoBluelightSphereInches()
                || ucoPersonal(3).areaVal
                != ucoFirefingerJetInches())
            ++bad;
        // the per-row denominator
        // pins - fail on any wrong
        // cell (the mirror eval)
        if (ucpCastTimeDen(0) != 10
                || ucpCastTimeDen(1) != 10
                || ucpCastTimeDen(2) != 3
                || ucpCastTimeDen(3) != 3
                || ucpCastTimeDen(4) != 10
                || ucpCastTimeDen(5) != 8
                || ucpCastTimeDen(6) != 2
                || ucpCastTimeDen(7) != 3) ++bad;

        if (ucpCastTimeDen(8) != 10
                || ucpCastTimeDen(9) != 8) ++bad;

        if (ucoCastTimeDen(0) != 2
                || ucoCastTimeDen(1) != 2
                || ucoCastTimeDen(2) != 2
                || ucoCastTimeDen(3) != 3
                || ucoCastTimeDen(4) != 2
                || ucoCastTimeDen(5) != 2
                || ucoCastTimeDen(6) != 3
                || ucoCastTimeDen(7) != 2) ++bad;

        if (ucoCastTimeDen(8) != 3
                || ucoCastTimeDen(9) != 2) ++bad;

        if (uchCastTimeDen(0) != 6
                || uchCastTimeDen(1) != 6
                || uchCastTimeDen(2) != 6
                || uchCastTimeDen(3) != 10
                || uchCastTimeDen(4) != 10
                || uchCastTimeDen(5) != 6
                || uchCastTimeDen(6) != 10
                || uchCastTimeDen(7) != 6) ++bad;
        printf("R419 UA cantrip cast-times part 2 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
