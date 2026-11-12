    // ---- R828 hundred-block batch audit ----
    // the fifth migration batch: the DMG magic items, the underwater and seam
    // engines, and the first UA pins ride the wiring; the batch constants
    // check themselves
    {
        using namespace rules;
        int bad = 0;
    if (zmb_batch() != 100
            || zmb_moving_lines() != 17574
            || zmb_first_head() != 12798
            || zmb_last_end() != 32421
            || zmb_largest() != 641
            || zmb_smallest() != 43
            || !zmb_audit_rides()
            || !zmb_blocks_move()
            || !zmb_gates_recheck()
            || !zmb_census_holds()
        )
            ++bad;
        // the batch is the first hundred blocks
    if (zmb_batch() != 100
        )
            ++bad;
        // the moving lines against the batch size
    if (zmb_moving_lines() != zmb_batch() * 175 + 74
        )
            ++bad;
        // the size extremes of the batch
    if (zmb_smallest() + zmb_largest() != 684
        )
            ++bad;
        // the digest span of the batch
    if (zmb_last_end() - zmb_first_head() != 19623
        )
            ++bad;
        printf("R828 hundred-block batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
