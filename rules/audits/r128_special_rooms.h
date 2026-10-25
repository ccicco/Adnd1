    // ---- R128: special rooms audit ----
    {
        int bad = 0;
        // the Appendix H lists R128 wires: counts, names,
        // the summary phrase, and the first-effects slice
        if (dm::appendixh::TRICK_FEATURE_COUNT != 37) ++bad;
        if (dm::appendixh::TRICK_ATTRIBUTE_COUNT != 65) ++bad;
        for (int f = 0; f < dm::appendixh::TRICK_FEATURE_COUNT;
             ++f) {
            const char* n = dm::appendixh::trickFeatureName(f);
            if (!n || !*n) { ++bad; continue; }
            for (const char* p = n; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        for (int a = 0;
             a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a) {
            const char* n =
                dm::appendixh::trickAttributeName(a);
            if (!n || !*n) { ++bad; continue; }
            for (const char* p = n; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        // out-of-range reads fall to "unknown"
        if (std::string(dm::appendixh::trickFeatureName(
                dm::appendixh::TRICK_FEATURE_COUNT))
            != "unknown") ++bad;
        if (std::string(dm::appendixh::trickAttributeName(
                dm::appendixh::TRICK_ATTRIBUTE_COUNT))
            != "unknown") ++bad;
        // the summary phrase: first and last combos
        if (dm::appendixh::trickSummary(0, 0)
            != "Altar (Ages)") ++bad;
        if (dm::appendixh::trickSummary(
                dm::appendixh::TRICK_FEATURE_COUNT - 1,
                dm::appendixh::TRICK_ATTRIBUTE_COUNT - 1)
            != "Well (Wish fulfillment, reversal)") ++bad;
        // the slices: exactly fifty-two mechanical
        // (R132 5 -> 11, R133 11 -> 16, R134 16 -> 19,
        // R135 19 -> 24, R136 24 -> 29, R139 29 -> 40,
        // R140 40 -> 52)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COINS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_GEMS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_MAGIC_ITEM) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHOOTS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POISON)) ++bad;
        // R132: counterfeit joined the mechanical set; the
        // talks stay dressing
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COUNTERFEIT)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_NONSENSE)) ++bad;
        printf("R128 special rooms audit: bad %d\n", bad);
        if (bad) return 1;
    }
