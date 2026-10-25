    // ---- R132: second-effects slice audit ----
    // The Appendix H mechanical set grows to eleven: the
    // R128 five plus ages, flesh to stone, both shocks,
    // counterfeit coins, and takes/steals (print sources:
    // the altar ages 10 years, the face petrifies on a
    // failed save, the pedestal shocks 5-50 hp;
    // counterfeit crumbles worthless; takes/steals is a
    // convention - the print gives no figure).
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65 (R135 and R136 grew it)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R132 six are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_AGES)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_FLESH_TO_STONE)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHOCK_METAL)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHOCK_MAGIC)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COUNTERFEIT)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TAKES)) ++bad;
        // the flavor set stays dressing (R134 wired the
        // deep waters: wish and gravity are mechanical)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_NONSENSE)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_POETRY)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POINTS)) ++bad;
        printf("R132 second-effects slice audit: bad %d\n", bad);
        if (bad) return 1;
    }
