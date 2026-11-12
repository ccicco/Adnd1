    // ---- R827 subclass batch audit ----
    // the fourth migration batch: the subclass and class-audit blocks ride
    // the wiring; the batch constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (qmb_batch() != 50
            || qmb_moving_lines() != 5111
            || qmb_first_head() != 5482
            || qmb_last_end() != 12797
            || qmb_largest() != 320
            || qmb_smallest() != 30
            || !qmb_audit_rides()
            || !qmb_blocks_move()
            || !qmb_gates_recheck()
            || !qmb_census_holds()
        )
            ++bad;
        // the batch is the first fifty blocks
    if (qmb_batch() != 50
        )
            ++bad;
        // the moving lines against the batch size
    if (qmb_moving_lines() != qmb_batch() * 102 + 11
        )
            ++bad;
        // the size extremes of the batch
    if (qmb_smallest() + qmb_largest() != 350
        )
            ++bad;
        // the digest span of the batch
    if (qmb_last_end() - qmb_first_head() != 7315
        )
            ++bad;
        printf("R827 subclass batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
