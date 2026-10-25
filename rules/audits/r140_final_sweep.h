    // ---- R140: final sweep audit ----
    // The Appendix H list is CLOSED: 52 mechanical,
    // 11 talky, and 2 dressing by design (anti-magic
    // needs a magic-use hook, enrages needs a berserk
    // hook - neither engine exists; documented). The
    // final twelve: animated, combination, enlarges,
    // false, gravity lesser/nil/varying, moves,
    // randomly-acts, sloping, symbiotic, wish
    // reversal (all conventions - names only).
    {
        int bad = 0;
        {
            int mech = 0, talky = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a) {
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
                if (dm::appendixh::trickIsTalky(a)) ++talky;
            }
            if (mech != 52) ++bad;
            if (talky != 11) ++bad;
            if (mech + talky + 2 !=
                dm::appendixh::TRICK_ATTRIBUTE_COUNT) ++bad;
        }
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ANIMATED) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_COMBINATION) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ENLARGES) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_FALSE) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_LESSER) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_NIL) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_VARYING) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_MOVES) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_RANDOMLY_ACTS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SLOPING) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SYMBIOTIC) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_WISH_REVERSAL)) ++bad;
        // the two honest deeps stay dressing - by design
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ANTI_MAGIC) ||
            dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ENRAGES)) ++bad;
        // and the twelve never talk
        if (dm::appendixh::trickIsTalky(
                dm::appendixh::TA_ANIMATED) ||
            dm::appendixh::trickIsTalky(
                dm::appendixh::TA_RANDOMLY_ACTS) ||
            dm::appendixh::trickIsTalky(
                dm::appendixh::TA_WISH_REVERSAL)) ++bad;
        printf("R140 final sweep audit: bad %d\n", bad);
        if (bad) return 1;
    }
