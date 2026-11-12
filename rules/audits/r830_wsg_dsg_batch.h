    // ---- R830 WSG DSG batch audit ----
    // the seventh migration batch: the WSG tail pins and the DSG surface,
    // Deepearth, and campaign pins ride the wiring; the batch constants check
    // themselves
    {
        using namespace rules;
        int bad = 0;
    if (xmb_batch() != 100
            || xmb_moving_lines() != 19526
            || xmb_first_head() != 50955
            || xmb_last_end() != 74362
            || xmb_largest() != 763
            || xmb_smallest() != 14
            || !xmb_audit_rides()
            || !xmb_blocks_move()
            || !xmb_gates_recheck()
            || !xmb_census_holds()
        )
            ++bad;
        // the batch is the third hundred blocks
    if (xmb_batch() != 100
        )
            ++bad;
        // the moving lines against the batch size
    if (xmb_moving_lines() != xmb_batch() * 195 + 26
        )
            ++bad;
        // the size extremes of the batch
    if (xmb_smallest() + xmb_largest() != 777
        )
            ++bad;
        // the digest span of the batch
    if (xmb_last_end() - xmb_first_head() != 23407
        )
            ++bad;
        printf("R830 WSG DSG batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
