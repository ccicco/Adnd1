    // ---- R832 OA tail batch audit ----
    // the ninth migration batch: the OA spells, monsters, treasure, weapons,
    // and Kara-Tur pins ride the wiring; the batch constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (jmb_batch() != 100
            || jmb_moving_lines() != 12737
            || jmb_first_head() != 107483
            || jmb_last_end() != 120219
            || jmb_largest() != 424
            || jmb_smallest() != 35
            || !jmb_audit_rides()
            || !jmb_blocks_move()
            || !jmb_gates_recheck()
            || !jmb_census_holds()
        )
            ++bad;
        // the batch is the fifth hundred blocks
    if (jmb_batch() != 100
        )
            ++bad;
        // the moving lines against the batch size
    if (jmb_moving_lines() != jmb_batch() * 127 + 37
        )
            ++bad;
        // the size extremes of the batch
    if (jmb_smallest() + jmb_largest() != 459
        )
            ++bad;
        // the digest span of the batch
    if (jmb_last_end() - jmb_first_head() != 12736
        )
            ++bad;
        printf("R832 OA tail batch audit: bad %d\n", bad);
        if (bad) return 1;
    }
