    // ---- R138: talk-flavor parley audit ----
    // The talks-class attributes stay non-mechanical -
    // they answer the X key instead: the engage hook
    // logs each one's flavor line (repeatable; talk
    // never spends the trick).
    {
        int bad = 0;
        {
            int talky = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsTalky(a)) ++talky;
            if (talky != 11) ++bad;
        }
        // every talky line: nonempty, ASCII, distinct,
        // and never mechanical
        for (int a = 0;
             a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a) {
            if (!dm::appendixh::trickIsTalky(a)) continue;
            const char* la =
                dm::appendixh::trickTalkLine(a);
            if (!la || !*la) ++bad;
            for (const char* q = la; q && *q; ++q)
                if ((unsigned char)*q > 127) ++bad;
            if (dm::appendixh::trickIsMechanical(a)) ++bad;
            for (int b = a + 1;
                 b < dm::appendixh::TRICK_ATTRIBUTE_COUNT;
                 ++b) {
                if (!dm::appendixh::trickIsTalky(b)) continue;
                if (std::string(la) ==
                        std::string(
                            dm::appendixh::trickTalkLine(b)))
                    ++bad;
            }
        }
        // the smart line pinned exact
        if (std::string(dm::appendixh::trickTalkLine(
                dm::appendixh::TA_TALKS_SMART)) !=
            "The feature speaks learnedly of the dungeon's history.")
            ++bad;
        printf("R138 talk-flavor parley audit: bad %d\n", bad);
        if (bad) return 1;
    }
