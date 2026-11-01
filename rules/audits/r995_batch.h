    // ---- R995 DSG promotion batch two audit ----
    // the batch two audit - sixteen records, 660 model items, rounds R511
    // through R527 complete (R515 absent), cumulative 24 of the 60-round DSG
    // set, the parse-back proof green on every record, every fact
    // fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dsg2BatchRecords() != 16
            || dsg2ModelItems() != 660
            || dsg2CumulativeRecords() != 24
            || dsg2SetRoundsRemaining() != 36
            || !dsg2RecordsPromoted()
            || !dsg2DiffBackGreen()
            || !dsg2R511ThroughR527Complete()
        )
            ++bad;
        // the batch - sixteen records, 660 model items, the cumulative 24 of
        // the set
    if (dsg2BatchRecords() != 16
            || dsg2ModelItems() != 660
            || dsg2CumulativeRecords() != 24
        )
            ++bad;
        // the set - 36 rounds remain after this batch, R511 through R527
        // fully on disk, the 60-round underdark set in motion
    if (dsg2SetRoundsRemaining() != 36
            || dsg2R511ThroughR527Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated spec
        // JSONs, every parse-back green
    if (dsg2RecordsPromoted() != 1
            || dsg2DiffBackGreen() != 1
        )
            ++bad;
        printf("R995 DSG promotion batch two audit: bad %d\n", bad);
        if (bad) return 1;
    }
