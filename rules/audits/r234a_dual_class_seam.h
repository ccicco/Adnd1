    // ---- R234a: the dual-class seam audit ----
    // The R185 gates and the R234 pure-expression
    // seam (an evaluable block - verified by
    // audit_eval).
    {
        int bad = 0;
        // the race gate: humans only
        if (!rules::dualClassRaceAllowed(0)) ++bad;
        if (rules::dualClassRaceAllowed(1)) ++bad;
        if (rules::dualClassRaceAllowed(6)) ++bad;
        // the prime gates: 15+ old, 17+ new
        if (rules::dualClassPrimeGate(14, 17)) ++bad;
        if (rules::dualClassPrimeGate(15, 16)) ++bad;
        if (!rules::dualClassPrimeGate(15, 17)) ++bad;
        if (!rules::dualClassPrimeGate(16, 18)) ++bad;
        // the exceeded boundary: the new die begins
        // when the new level EXCEEDS the old
        if (rules::dualClassNewDieDue(6, 6) != 0) ++bad;
        if (rules::dualClassNewDieDue(7, 6) != 1) ++bad;
        if (rules::dualClassNewDieDue(1, 1) != 0) ++bad;
        // the XP negation: the resort stance negates
        // until exceeded, then mixing is free
        if (rules::dualClassXpNegated(1, 1, 6, 1) != 1) ++bad;
        if (rules::dualClassXpNegated(1, 6, 6, 1) != 1) ++bad;
        if (rules::dualClassXpNegated(1, 7, 6, 1) != 0) ++bad;
        if (rules::dualClassXpNegated(1, 1, 6, 0) != 0) ++bad;
        if (rules::dualClassXpNegated(0, 1, 6, 1) != 0) ++bad;
        printf("R234a dual-class seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
