    // ---- R824 pilot migration audit ----
    // the pilot round: the wiring from R822 and R823 carries its first real
    // freight - the batch constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (pmb_batch() != 18
            || pmb_first_head() != 967
            || pmb_last_end() != 1825
            || pmb_moving_lines() != 784
            || pmb_smallest() != 16
            || pmb_largest() != 84
            || !pmb_audit_rides()
            || !pmb_blocks_move()
            || !pmb_gates_recheck()
            || !pmb_census_holds()
        )
            ++bad;
        // the pilot batch is the first 18 blocks
    if (pmb_batch() != 18
        )
            ++bad;
        // the batch spans digest lines 967 to 1825
    if (pmb_first_head() + pmb_last_end() != 2792
        )
            ++bad;
        // stairs plus burden, the size extremes
    if (pmb_smallest() + pmb_largest() != 100
        )
            ++bad;
        // the moving-line count against the batch size
    if (pmb_moving_lines() != pmb_batch() * 44 - 8
        )
            ++bad;
        printf("R824 pilot migration audit: bad %d\n", bad);
        if (bad) return 1;
    }
