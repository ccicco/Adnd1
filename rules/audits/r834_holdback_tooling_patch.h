    // ---- R834 holdback tooling patch audit ----
    // the tooling round: the head walk widens to 4000 and the per-block wide
    // tolerance rides the migrate key - the no-head and width families unlock
    // for the final batch; no block moves this round; the constants check
    // themselves
    {
        using namespace rules;
        int bad = 0;
    if (hmb_head_walk() != 4000
            || hmb_walk_old() != 800
            || hmb_walk_farthest() != 2325
            || hmb_no_head() != 16
            || hmb_width_family() != 31
            || hmb_ready_now() != 8
            || hmb_holdbacks() != 55
            || hmb_wide_lines() != 77
            || hmb_wide_max() != 159
            || hmb_census() != 757
            || !hmb_allow_wide()
            || !hmb_default_width()
            || !hmb_verbatim()
            || !hmb_walk_upward()
            || !hmb_gates_hold()
            || !hmb_tooling_alone()
            || !hmb_audit_rides()
            || !hmb_wiring_kept()
            || !hmb_census_holds()
            || !hmb_arc_closes()
        )
            ++bad;
        // the three families sum to the holdbacks
    if (hmb_no_head() + hmb_width_family() + hmb_ready_now() != 55
        )
            ++bad;
        // the walk widens by 3200
    if (hmb_head_walk() != hmb_walk_old() + 3200
        )
            ++bad;
        // the margin over the farthest no-head label
    if (hmb_head_walk() - hmb_walk_farthest() != 1675
        )
            ++bad;
        // the widest line against the wide count
    if (hmb_wide_max() - hmb_wide_lines() != 82
        )
            ++bad;
        printf("R834 holdback tooling patch audit: bad %d\n", bad);
        if (bad) return 1;
    }
