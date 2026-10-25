    // ---- R134: deep-effects slice audit ----
    // The deep waters are wired: the R133 sixteen plus
    // wish, gravity greater, and polymorph (all
    // conventions - the print gives no figures; the
    // wish stays benevolent: heal the company, restore
    // a member, or a gold shower).
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65 (R135
        // and R136 grew it)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R134 three are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_WISH)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_GREATER)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POLYMORPH)) ++bad;
        // the talk-flavor set stays dressing
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_SMART)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SUGGESTS)) ++bad;
        printf("R134 deep-effects slice audit: bad %d\n", bad);
        if (bad) return 1;
    }
