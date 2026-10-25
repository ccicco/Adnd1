    // ---- R826 DMG tables batch audit ----
    // the third migration batch: the DMG tables and appendix blocks ride the
    // wiring; the batch constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (tmb_batch() != 18
            || tmb_moving_lines() != 1938
            || tmb_first_head() != 3544
            || tmb_last_end() != 5481
            || tmb_largest() != 303
            || tmb_smallest() != 25
            || !tmb_audit_rides()
            || !tmb_blocks_move()
            || !tmb_gates_recheck()
            || !tmb_census_holds()
        )
            ++bad;
        // the batch is the third 18 blocks
    if (tmb_batch() != 18
        )
            ++bad;
        // the moving lines against the batch size
    if (tmb_moving_lines() != tmb_batch() * 108 - 6
        )
            ++bad;
        // the size extremes of the batch
    if (tmb_smallest() + tmb_largest() != 328
        )
            ++bad;
        // the digest span of the batch
    if (tmb_last_end() - tmb_first_head() != 1937
        )
            ++bad;
        printf("R826 DMG tables batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
