    // ---- R136: odds-and-ends slice audit ----
    // The stragglers are wired: the R135 twenty-four
    // plus rising, suspends, appearing, invisible, and
    // gaseous (all conventions - the print gives no
    // figures). Anti-magic STAYS dressing: an honest
    // suppression zone needs a magic-use hook the
    // engine does not expose yet.
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65 (the
        // R136 five: rising, suspends, appearing,
        // invisible, gaseous)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R136 five are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_RISING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SUSPENDS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_APPEARING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_INVISIBLE)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GASEOUS)) ++bad;
        // the unwired deeps stay dressing
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ANTI_MAGIC)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ENRAGES)) ++bad;
        printf("R136 odds-and-ends slice audit: bad %d\n", bad);
        if (bad) return 1;
    }
