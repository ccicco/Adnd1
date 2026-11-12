    // ---- R835 final holdback batch audit ----
    // the arc closer: the eight ready-now blocks, the sixteen no-head blocks
    // on the widened walk, and the thirty-one width blocks on the per-block
    // tolerance ride the wiring in one pass; the wiring audit stays put by
    // design; the constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (ymb_batch() != 55
            || ymb_moving_lines() != 29060
            || ymb_first_head() != 1091
            || ymb_last_end() != 33604
            || ymb_largest() != 2434
            || ymb_smallest() != 38
            || !ymb_audit_rides()
            || !ymb_blocks_move()
            || !ymb_gates_recheck()
            || !ymb_arc_closes()
        )
            ++bad;
        // the batch is every remaining holdback block
    if (ymb_batch() != 55
        )
            ++bad;
        // the moving lines against the batch size
    if (ymb_moving_lines() != ymb_batch() * 528 + 20
        )
            ++bad;
        // the size extremes of the batch
    if (ymb_largest() + ymb_smallest() != 2472
        )
            ++bad;
        // the batch span in regtest lines
    if (ymb_last_end() - ymb_first_head() != 32513
        )
            ++bad;
        printf("R835 final holdback batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
