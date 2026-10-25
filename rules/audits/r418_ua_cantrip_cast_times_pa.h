    // ---- R418: the cantrip
    // casting-time resolution
    // part 1 pin audit ----
    // The PDF read resolves the
    // whole casting-time families
    // the R412 (useful), R413
    // (reversed) and R414
    // (legerdemain) rounds recorded
    // as holes: all 38 cells print
    // clean unit fractions, one
    // segment over the denominator.
    // The denominator censuses count
    // (the useful 17/0/2/1, the
    // reversed 4/1/5/2, the
    // legerdemain 0/1/1/4 - at
    // 1/2, 1/3, 1/8, 1/10), each
    // family census totals its
    // roster count, and every
    // denominator sits in the 2..10
    // band the cantrip section
    // header prints (the cantrips
    // cast in 1/10 to 1/2 segment
    // norm); census 344 -> 345.
    {
        using namespace rules;
        int bad = 0;
        if (ucnCastTimeDenCount(2) != 17
                || ucnCastTimeDenCount(3) != 0
                || ucnCastTimeDenCount(8) != 2
                || ucnCastTimeDenCount(10) != 1)
            ++bad;
        if (ucrCastTimeDenCount(2) != 4
                || ucrCastTimeDenCount(3) != 1
                || ucrCastTimeDenCount(8) != 5
                || ucrCastTimeDenCount(10) != 2)
            ++bad;
        if (uclCastTimeDenCount(2) != 0
                || uclCastTimeDenCount(3) != 1
                || uclCastTimeDenCount(8) != 1
                || uclCastTimeDenCount(10) != 4)
            ++bad;
        // the per-family totals
        if (ucnCastTimeDenCount(2)
                + ucnCastTimeDenCount(3)
                + ucnCastTimeDenCount(8)
                + ucnCastTimeDenCount(10)
                != 20) ++bad;
        if (ucrCastTimeDenCount(2)
                + ucrCastTimeDenCount(3)
                + ucrCastTimeDenCount(8)
                + ucrCastTimeDenCount(10)
                != 12) ++bad;
        if (uclCastTimeDenCount(2)
                + uclCastTimeDenCount(3)
                + uclCastTimeDenCount(8)
                + uclCastTimeDenCount(10)
                != 6) ++bad;
        // the 2..10 norm band
        for (int i = 0; i < 20; ++i)
            if (ucnCastTimeDen(i) < 2
                || ucnCastTimeDen(i) > 10)
                ++bad;
        for (int i = 0; i < 12; ++i)
            if (ucrCastTimeDen(i) < 2
                || ucrCastTimeDen(i) > 10)
                ++bad;
        for (int i = 0; i < 6; ++i)
            if (uclCastTimeDen(i) < 2
                || uclCastTimeDen(i) > 10)
                ++bad;
        printf("R418 UA cantrip cast-times part 1 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
