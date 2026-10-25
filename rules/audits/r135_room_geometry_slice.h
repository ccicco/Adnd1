    // ---- R135: room-geometry slice audit ----
    // The Appendix H mechanical set grows to
    // twenty-four: the R134 nineteen plus one-way,
    // pivots, spinning, shifting, and sliding (all
    // positional conventions - the print gives no
    // mechanics; each moves or commits the company
    // within the room rect).
    {
        int bad = 0;
        // exactly fifty-two mechanical of 65
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 52) ++bad;
        }
        // the R135 five are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ONE_WAY)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_PIVOTS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SPINNING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHIFTING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SLIDING)) ++bad;
        // the R140 final sweep wired sloping and moves
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SLOPING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_MOVES)) ++bad;
        printf("R135 room-geometry slice audit: bad %d\n", bad);
        if (bad) return 1;
    }
