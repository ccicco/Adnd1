    // ---- R831 planes OA batch audit ----
    // the eighth migration batch: the DSG tail, the MotP planes, the DMO
    // sections, and the first OA pins ride the wiring; the batch constants
    // check themselves
    {
        using namespace rules;
        int bad = 0;
    if (kmb_batch() != 100
            || kmb_moving_lines() != 19285
            || kmb_first_head() != 74363
            || kmb_last_end() != 107482
            || kmb_largest() != 687
            || kmb_smallest() != 16
            || !kmb_audit_rides()
            || !kmb_blocks_move()
            || !kmb_gates_recheck()
            || !kmb_census_holds()
        )
            ++bad;
        // the batch is the fourth hundred blocks
    if (kmb_batch() != 100
        )
            ++bad;
        // the moving lines against the batch size
    if (kmb_moving_lines() != kmb_batch() * 192 + 85
        )
            ++bad;
        // the size extremes of the batch
    if (kmb_smallest() + kmb_largest() != 703
        )
            ++bad;
        // the digest span of the batch
    if (kmb_last_end() - kmb_first_head() != 33119
        )
            ++bad;
        printf("R831 planes OA batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
