    // ---- R306a: the thief functions seam audit ----
    // The PHB take-table boundaries (hide in
    // shadows, climb walls, read languages) and
    // the R306 site pins - verified by
    // audit_eval.
    {
        int bad = 0;
        // hide in shadows: the level 1 base
        // reads 10 percent, the 15th 99
        if (rules::thfTakeTenths(rules::THF_HIDE_SHADOWS,
                1) != 100 ||
            rules::thfTakeTenths(rules::THF_HIDE_SHADOWS,
                15) != 990) ++bad;
        // climb walls: the level 1 base reads
        // 85 percent, the 11th 99.1
        if (rules::thfTakeTenths(rules::THF_CLIMB_WALLS,
                1) != 850 ||
            rules::thfTakeTenths(rules::THF_CLIMB_WALLS,
                11) != 991) ++bad;
        // read languages: the dash through the
        // 3rd, 20 percent at the 4th, 80 at 16
        if (rules::thfTakeTenths(
                rules::THF_READ_LANGUAGES, 3) != 0 ||
            rules::thfTakeTenths(
                rules::THF_READ_LANGUAGES,
                4) != 200 ||
            rules::thfTakeTenths(
                rules::THF_READ_LANGUAGES,
                16) != 800) ++bad;
        // climb and read print no DEX column
        if (rules::thfDexAdj(18, rules::THF_CLIMB_WALLS)
                != 0 ||
            rules::thfDexAdj(18,
                rules::THF_READ_LANGUAGES) != 0) ++bad;
        // the hide ramp: 5 percent per level at
        // the printed band
        if (rules::thfTakeTenths(rules::THF_HIDE_SHADOWS,
                2) - rules::thfTakeTenths(
                rules::THF_HIDE_SHADOWS, 1) != 50)
            ++bad;
        // the read ramp: 5 percent per level
        // past the 4th
        if (rules::thfTakeTenths(
                rules::THF_READ_LANGUAGES, 5) -
            rules::thfTakeTenths(
                rules::THF_READ_LANGUAGES,
                4) != 50) ++bad;
        // the R306 site pins: the observed-hide
        // note, the wander pass, the coarse
        // climb surface and the haul turn
        if (rules::thfNoteHideObserved() != 1 ||
            rules::thfHideWanderPasses() != 1 ||
            rules::thfNoteClimbCoarseSurface() != 1 ||
            rules::thfPitHaulFailTurns() != 1) ++bad;
        // the script pin: one read per delve
        if (rules::thfReadScriptOncePerDelve() != 1)
            ++bad;
        // the cache band rides the 2d6 shape
        if (rules::thfReadScriptCacheMin() != 2 ||
            rules::thfReadScriptCacheMax() != 12 ||
            rules::thfReadScriptCacheMax() -
                rules::thfReadScriptCacheMin() != 10)
            ++bad;
        printf("R306a thief functions seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
