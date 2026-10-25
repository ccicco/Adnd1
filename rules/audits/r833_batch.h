    // ---- R833 final digest batch audit ----
    // the tenth migration batch: the OA back matter, the seams, the MM2
    // walks, and the early-file blocks ride the wiring; the digest runs dry;
    // the batch constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (fmb_batch() != 86
            || fmb_moving_lines() != 14289
            || fmb_first_head() != 120220
            || fmb_last_end() != 144417
            || fmb_largest() != 786
            || fmb_smallest() != 17
            || !fmb_audit_rides()
            || !fmb_blocks_move()
            || !fmb_gates_recheck()
            || !fmb_census_holds()
        )
            ++bad;
        // the batch is every gate-passing digest block
    if (fmb_batch() != 86
        )
            ++bad;
        // the moving lines against the batch size
    if (fmb_moving_lines() != fmb_batch() * 166 + 13
        )
            ++bad;
        // the size extremes of the batch
    if (fmb_smallest() + fmb_largest() != 803
        )
            ++bad;
        // the digest span of the batch
    if (fmb_last_end() - fmb_first_head() != 24197
        )
            ++bad;
        printf("R833 final digest batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
