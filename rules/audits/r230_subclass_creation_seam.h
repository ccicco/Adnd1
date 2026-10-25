    // ---- R230: the subclass creation seam audit ----
    // The runtime base classes, the con classes, the
    // starting-age bands, the two-dice flags, the hit
    // dice, the player-eligibility gate (Table I with
    // Table II agreement), and the effective level cap
    // (Table II with the footnote-8 gnome conditional).
    {
        int bad = 0;
        static const int kBase[6] = {
            0, 0, 2, 1, 3, 0
        };
        static const int kCon[6] = {
            0, 0, 2, 1, 3, 3
        };
        static const int kAge[6] = {
            15, 15, 18, 24, 18, 15
        };
        static const int kTwo[6] = {
            0, 1, 0, 0, 0, 1
        };
        static const int kDie[6] = {
            10, 8, 8, 4, 6, 4
        };
        // Table I, flat 42 (the R180 walk)
        static const int kAllowed[42] = {
            1, 0, 0, 0, 0, 0, 0,
            1, 0, 0, 0, 1, 0, 0,
            1, 0, 0, 0, 1, 0, 0,
            1, 0, 0, 1, 0, 0, 0,
            1, 1, 1, 1, 1, 0, 1,
            1, 0, 0, 0, 0, 0, 0
        };
        // the runtime base classes (the monk rides
        // fighter - the JUDGMENT)
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassRuntimeBase(i)
                != kBase[i]) ++bad;
        // the con classes (paladin/ranger the fighter
        // group; the monk is not - the registry pin)
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassConClass(i)
                != kCon[i]) ++bad;
        // the starting-age bands
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassStartAgeBase(i)
                != kAge[i]) ++bad;
        // the two-dice flags (ranger, monk)
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassTwoDiceFirstLevel(i)
                != kTwo[i]) ++bad;
        // the hit dice (d10 d8 d8 d4 d6 d4)
        for (int i = 0; i <= 5; ++i)
            if (rules::subclassHitDie(i)
                != kDie[i]) ++bad;
        // the player-eligibility gate agrees with the
        // R180 Table I walk, cell by cell
        for (int i = 0; i <= 5; ++i)
            for (int r = 0; r <= 6; ++r)
                if (rules::subclassPlayerAllowed(
                        i, (rules::CharRace)r)
                    != kAllowed[i * 7 + r]) ++bad;
        // the effective caps: the Table II matrix with
        // the footnote-8 gnome illusionist conditional
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)3, 16, 18) != 5) ++bad;
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)3, 17, 16) != 5) ++bad;
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)3, 17, 17) != 6) ++bad;
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)0, 18, 18) != -1) ++bad;
        if (rules::subclassLevelCapFor(
                3, (rules::CharRace)1, 18, 18) != 0) ++bad;
        if (rules::subclassLevelCapFor(
                0, (rules::CharRace)0, 18, 18) != -1) ++bad;
        if (rules::subclassLevelCapFor(
                0, (rules::CharRace)1, 18, 18) != 0) ++bad;
        if (rules::subclassLevelCapFor(
                1, (rules::CharRace)4, 18, 18) != 8) ++bad;
        if (rules::subclassLevelCapFor(
                2, (rules::CharRace)5, 18, 18) != -6) ++bad;
        if (rules::subclassLevelCapFor(
                4, (rules::CharRace)2, 18, 18) != 10) ++bad;
        if (rules::subclassLevelCapFor(
                4, (rules::CharRace)6, 18, 18) != -1) ++bad;
        if (rules::subclassLevelCapFor(
                5, (rules::CharRace)0, 18, 18) != -1) ++bad;
        // the clamps
        if (rules::subclassPlayerAllowed(
                99, (rules::CharRace)99) != 0) ++bad;
        if (rules::subclassPlayerAllowed(
                -1, (rules::CharRace)-1) != 1) ++bad;
        if (rules::subclassHitDie(-1) != 10) ++bad;
        if (rules::subclassHitDie(99) != 4) ++bad;
        if (rules::subclassRuntimeBase(-3) != 0) ++bad;
        if (rules::subclassRuntimeBase(99) != 0) ++bad;
        printf("R230 subclass creation seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
