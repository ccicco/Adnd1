    // ---- R139: engine-deep change-family audit ----
    // The eleven deepest attributes are wired at last:
    // the change family (align, attribute, class,
    // minds, sex), both distorted readings, both
    // resisting readings, geases, disintegrates - the
    // mechanical set grows to forty (all conventions;
    // the print gives names only).
    {
        int bad = 0;
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_ALIGN) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_ATTRIBUTE) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_CLASS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_MINDS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_CHANGE_SEX)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_DISTORTED_WL) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_DISTORTED_HD) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_RESISTING_GENERAL) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_RESISTING_SPECIFIC) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GEASES) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_DISINTEGRATES)) ++bad;
        // the honest deeps stay dressing
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ANTI_MAGIC) ||
            dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ENRAGES)) ++bad;
        // and the eleven never talk
        if (dm::appendixh::trickIsTalky(
                dm::appendixh::TA_CHANGE_ALIGN) ||
            dm::appendixh::trickIsTalky(
                dm::appendixh::TA_GEASES) ||
            dm::appendixh::trickIsTalky(
                dm::appendixh::TA_DISINTEGRATES)) ++bad;
        printf("R139 engine-deep change-family audit: bad %d\n", bad);
        if (bad) return 1;
    }
