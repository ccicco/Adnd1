    // ---- R302: the thief silence seam audit ----
    // The surprise-site helpers: the silence
    // roll step (one band of the DMG p.62 2d6
    // ladder - JUDGMENT, the SILENT MOVEMENT
    // print carries no ladder modifier) and
    // the printed each-move note (the site
    // rolls it once per encounter). The move
    // silently percentile boundaries walk the
    // R301a convention (plain int race codes:
    // 0 human, 5 halfling, 6 half-orc).
    {
        int bad = 0;
        // the silence step: -2 silent, 0 plain
        if (rules::thfSilenceSurpriseAdj(true) != -2 ||
            rules::thfSilenceSurpriseAdj(false) != 0) ++bad;
        // the printed note: attempted each
        // time the thief moves
        if (rules::thfNoteSilenceEachMove() != 1) ++bad;
        // move silently level 1 human dex 9
        // prints -5 percent (the 150 base less
        // the dex 9 -20 column - no roll of
        // the band succeeds)
        if (rules::thfAttemptSucceeds(0,
                rules::THF_MOVE_SILENTLY, 1, 0, 9) ||
            rules::thfAttemptSucceeds(999,
                rules::THF_MOVE_SILENTLY, 1, 0, 9)) ++bad;
        // move silently level 7 human dex 13
        // prints 55 percent (550 tenths)
        if (!rules::thfAttemptSucceeds(549,
                rules::THF_MOVE_SILENTLY, 7, 0, 13) ||
            rules::thfAttemptSucceeds(550,
                rules::THF_MOVE_SILENTLY, 7, 0, 13)) ++bad;
        // move silently level 10 halfling
        // dex 13 prints 88 percent (880)
        if (!rules::thfAttemptSucceeds(879,
                rules::THF_MOVE_SILENTLY, 10, 5, 13) ||
            rules::thfAttemptSucceeds(880,
                rules::THF_MOVE_SILENTLY, 10, 5, 13)) ++bad;
        // move silently level 17 half-orc
        // dex 18 prints 109 percent (1090 -
        // every draw of the band succeeds)
        if (!rules::thfAttemptSucceeds(999,
                rules::THF_MOVE_SILENTLY, 17, 6, 18)) ++bad;
        // move silently level 1 human dex 18
        // prints 25 percent (250 tenths)
        if (!rules::thfAttemptSucceeds(249,
                rules::THF_MOVE_SILENTLY, 1, 0, 18) ||
            rules::thfAttemptSucceeds(250,
                rules::THF_MOVE_SILENTLY, 1, 0, 18)) ++bad;
        printf("R302a thief silence seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
