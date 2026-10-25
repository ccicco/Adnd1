    // ---- R120: parley and listening wiring audit ----
    {
        int bad = 0;
        // the book's starred bands (DMG p.64): only
        // violently hostile and hostile mean immediate
        // attack; the other five bands are parley
        if (!dm::reactionAttacks(dm::REACTION_VIOLENT)) ++bad;
        if (!dm::reactionAttacks(dm::REACTION_HOSTILE)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_UNCERTAIN_NEG)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_NEUTRAL)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_UNCERTAIN_POS)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_FRIENDLY)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_ENTHUSIASTIC)) ++bad;
        // the best listener: a thief rides hear-noise,
        // no thief rides the human band (R114); level 0
        // clamps to the L1 row
        if (abilities::bestListenIn20(false, 0) != 2) ++bad;
        if (abilities::bestListenIn20(false, 9) != 2) ++bad;
        if (abilities::bestListenIn20(true, 0)  != 2) ++bad;
        if (abilities::bestListenIn20(true, 1)  != 2) ++bad;
        if (abilities::bestListenIn20(true, 5)  != 4) ++bad;
        if (abilities::bestListenIn20(true, 12) != 7) ++bad;
        if (abilities::bestListenIn20(true, 13) != 7) ++bad;
        printf("R120 parley and listening audit: bad %d\n", bad);
        if (bad) return 1;
    }
