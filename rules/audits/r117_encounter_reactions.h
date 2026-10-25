    // ---- R117: encounter reactions audit ----
    {
        int bad = 0;
        // the book's seven bands (DMG p.64), every
        // edge pinned on the pure banding helper
        if (dm::reactionForScore(5) != dm::REACTION_VIOLENT)
            ++bad;
        if (dm::reactionForScore(6) != dm::REACTION_HOSTILE)
            ++bad;
        if (dm::reactionForScore(25) != dm::REACTION_HOSTILE)
            ++bad;
        if (dm::reactionForScore(26) != dm::REACTION_UNCERTAIN_NEG)
            ++bad;
        if (dm::reactionForScore(45) != dm::REACTION_UNCERTAIN_NEG)
            ++bad;
        if (dm::reactionForScore(46) != dm::REACTION_NEUTRAL)
            ++bad;
        if (dm::reactionForScore(55) != dm::REACTION_NEUTRAL)
            ++bad;
        if (dm::reactionForScore(56) != dm::REACTION_UNCERTAIN_POS)
            ++bad;
        if (dm::reactionForScore(75) != dm::REACTION_UNCERTAIN_POS)
            ++bad;
        if (dm::reactionForScore(76) != dm::REACTION_FRIENDLY)
            ++bad;
        if (dm::reactionForScore(95) != dm::REACTION_FRIENDLY)
            ++bad;
        if (dm::reactionForScore(96) != dm::REACTION_ENTHUSIASTIC)
            ++bad;
        if (dm::reactionForScore(100) != dm::REACTION_ENTHUSIASTIC)
            ++bad;
        // clamped at both ends (the book's "01 (or
        // less)" and "96-00 (or greater)")
        if (dm::reactionForScore(0) != dm::REACTION_VIOLENT)
            ++bad;
        if (dm::reactionForScore(-4) != dm::REACTION_VIOLENT)
            ++bad;   // a -4 CHA adj can drive it below
        if (dm::reactionForScore(104) != dm::REACTION_ENTHUSIASTIC)
            ++bad;   // a +4 CHA adj can drive it above
        // the enum keeps the book's order (a caller
        // may compare magnitudes: violent < ... <
        // enthusiastic)
        if (dm::REACTION_VIOLENT != 0 ||
            dm::REACTION_HOSTILE != 1 ||
            dm::REACTION_UNCERTAIN_NEG != 2 ||
            dm::REACTION_NEUTRAL != 3 ||
            dm::REACTION_UNCERTAIN_POS != 4 ||
            dm::REACTION_FRIENDLY != 5 ||
            dm::REACTION_ENTHUSIASTIC != 6) ++bad;
        // smoke: 200 seeded rolls land in range and
        // both ends of the table are reachable
        {
            rules::Rng rng7(4242);
            rules::Dice dice7(rng7);
            bool sawLow = false, sawHigh = false;
            for (int i = 0; i < 200; ++i) {
                dm::Reaction r = dm::rollReaction(dice7, 0);
                if (r < dm::REACTION_VIOLENT ||
                    r > dm::REACTION_ENTHUSIASTIC) ++bad;
                if (r <= dm::REACTION_HOSTILE) sawLow = true;
                if (r >= dm::REACTION_FRIENDLY) sawHigh = true;
            }
            if (!sawLow || !sawHigh) ++bad;
        }
        printf("R117 encounter reactions audit: bad %d\n", bad);
        if (bad) return 1;
    }
