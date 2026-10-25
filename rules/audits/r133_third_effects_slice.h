    // ---- R133: third-effects slice audit ----
    // The Appendix H mechanical set grows to sixteen: the
    // R132 eleven plus attacks, fruit, greed, teleports,
    // and collapsing (all conventions - the print gives
    // no figures for these five; the teleport follows
    // the print's intra-level AREA example).
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65
        // (R135 and R136 grew it)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R133 five are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ATTACKS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_FRUIT)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GREED)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TELEPORTS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_COLLAPSING)) ++bad;
        // the talk-flavor set stays dressing (R134 wired
        // the deep waters: wish, gravity, polymorph)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_SMART)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SUGGESTS)) ++bad;
        printf("R133 third-effects slice audit: bad %d\n", bad);
        if (bad) return 1;
    }
