    // ---- R825 DMG batch audit ----
    // the second migration batch: the DMG appendix blocks ride the wiring;
    // the batch constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (nmb_batch() != 18
            || nmb_moving_lines() != 1700
            || nmb_first_head() != 1826
            || nmb_last_end() != 3568
            || nmb_largest() != 517
            || nmb_smallest() != 18
            || !nmb_audit_rides()
            || !nmb_blocks_move()
            || !nmb_gates_recheck()
            || !nmb_census_holds()
        )
            ++bad;
        // the batch is the next 18 blocks
    if (nmb_batch() != 18
        )
            ++bad;
        // the moving lines against the batch size
    if (nmb_moving_lines() != nmb_batch() * 100 - 100
        )
            ++bad;
        // the size extremes of the batch
    if (nmb_smallest() + nmb_largest() != 535
        )
            ++bad;
        // the digest span of the batch
    if (nmb_last_end() - nmb_first_head() != 1742
        )
            ++bad;
        printf("R825 DMG batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
