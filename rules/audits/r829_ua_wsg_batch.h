    // ---- R829 UA WSG batch audit ----
    // the sixth migration batch: the UA pins and appendices and the WSG pins
    // ride the wiring; the batch constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (vmb_batch() != 100
            || vmb_moving_lines() != 18485
            || vmb_first_head() != 32422
            || vmb_last_end() != 50954
            || vmb_largest() != 690
            || vmb_smallest() != 50
            || !vmb_audit_rides()
            || !vmb_blocks_move()
            || !vmb_gates_recheck()
            || !vmb_census_holds()
        )
            ++bad;
        // the batch is the second hundred blocks
    if (vmb_batch() != 100
        )
            ++bad;
        // the moving lines against the batch size
    if (vmb_moving_lines() != vmb_batch() * 184 + 85
        )
            ++bad;
        // the size extremes of the batch
    if (vmb_smallest() + vmb_largest() != 740
        )
            ++bad;
        // the digest span of the batch
    if (vmb_last_end() - vmb_first_head() != 18532
        )
            ++bad;
        printf("R829 UA WSG batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
