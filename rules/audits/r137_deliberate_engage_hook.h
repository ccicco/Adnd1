    // ---- R137: deliberate-engage hook audit ----
    // The hook's pure surface: the engage prompt the
    // dungeon logs on first sight (sight alone no longer
    // springs a mechanical curiosity - the company
    // chooses; the X key engages).
    {
        int bad = 0;
        const char* p = dm::appendixh::trickEngagePrompt();
        if (!p || !*p) ++bad;
        if (std::string(p) !=
            "Press X to engage the feature - or move on.")
            ++bad;
        for (const char* q = p; q && *q; ++q)
            if ((unsigned char)*q > 127) ++bad;
        printf("R137 deliberate-engage hook audit: bad %d\n", bad);
        if (bad) return 1;
    }
