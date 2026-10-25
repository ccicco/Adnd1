    // ---- R152: becoming-lost check audit -------------------------------
    // The DMG p.49 lost check, pinned in dm/outdoormove.h:
    // the 8 terrain chances in 10, the three direction
    // limitations and the lost-heading dice read clockwise
    // - the book prints NO chance of the party ever
    // accidentally moving in the desired direction when
    // lost, so the mapping never returns 0. The dice are
    // the callers; the accessors are deterministic.
    {
        int bad = 0;
        namespace OM = dm;
        // the 8 printed rows: chance in 10 and limitation
        static const struct { int c; OM::DirectionLimit dl; }
            kLost[] = {
            { 1, OM::DL_60 },   // plain
            { 3, OM::DL_60 },   // scrub
            { 7, OM::DL_ANY },  // forest
            { 3, OM::DL_60 },   // rough
            { 4, OM::DL_60 },   // desert
            { 2, OM::DL_60 },   // hills
            { 5, OM::DL_120 },  // mountains
            { 6, OM::DL_ANY },  // marsh
        };
        for (int i = 0; i < 8; ++i) {
            if (OM::lostChanceIn10((OM::OutdoorTerrain)i)
                != kLost[i].c) ++bad;
            if (OM::directionLimitFor((OM::OutdoorTerrain)i)
                != kLost[i].dl) ++bad;
        }
        // 60 degrees: 1-3 left, 4-6 right, both edges
        if (OM::lostAngleDeg(1, 1, OM::DL_60) != -60) ++bad;
        if (OM::lostAngleDeg(3, 1, OM::DL_60) != -60) ++bad;
        if (OM::lostAngleDeg(4, 1, OM::DL_60) != 60) ++bad;
        if (OM::lostAngleDeg(6, 1, OM::DL_60) != 60) ++bad;
        // 120: the second d6 picks the arc, both edges
        if (OM::lostAngleDeg(1, 3, OM::DL_120) != -60) ++bad;
        if (OM::lostAngleDeg(1, 4, OM::DL_120) != -120) ++bad;
        if (OM::lostAngleDeg(3, 6, OM::DL_120) != -120) ++bad;
        if (OM::lostAngleDeg(4, 3, OM::DL_120) != 60) ++bad;
        if (OM::lostAngleDeg(4, 4, OM::DL_120) != 120) ++bad;
        if (OM::lostAngleDeg(6, 6, OM::DL_120) != 120) ++bad;
        // any: single d6 read clockwise, both edges
        if (OM::lostAngleDeg(1, 1, OM::DL_ANY) != 60) ++bad;
        if (OM::lostAngleDeg(2, 1, OM::DL_ANY) != 120) ++bad;
        if (OM::lostAngleDeg(3, 1, OM::DL_ANY) != 180) ++bad;
        if (OM::lostAngleDeg(4, 1, OM::DL_ANY) != 180) ++bad;
        if (OM::lostAngleDeg(5, 1, OM::DL_ANY) != -120) ++bad;
        if (OM::lostAngleDeg(6, 1, OM::DL_ANY) != -60) ++bad;
        // never the desired direction, every face
        for (int dl = 0; dl < OM::DL_COUNT; ++dl)
            for (int a = 1; a <= 6; ++a)
                for (int b = 1; b <= 6; ++b)
                    if (OM::lostAngleDeg(a, b,
                        (OM::DirectionLimit)dl) == 0)
                        ++bad;
        printf("R152 becoming-lost audit: bad %d\n", bad);
        if (bad) return 1;
    }
