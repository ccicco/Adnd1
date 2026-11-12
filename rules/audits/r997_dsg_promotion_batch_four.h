    // ---- R997 DSG promotion batch four audit ----
    // the batch four audit - fifteen records, 630 model items, rounds R542
    // through R556 complete, cumulative 53 of the 60-round DSG set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dsg4BatchRecords() != 15
            || dsg4ModelItems() != 630
            || dsg4CumulativeRecords() != 53
            || dsg4SetRoundsRemaining() != 7
            || !dsg4RecordsPromoted()
            || !dsg4DiffBackGreen()
            || !dsg4R542ThroughR556Complete()
        )
            ++bad;
        // the batch - fifteen records, 630 model items, the cumulative 53 of
        // the set
    if (dsg4BatchRecords() != 15
            || dsg4ModelItems() != 630
            || dsg4CumulativeRecords() != 53
        )
            ++bad;
        // the set - 7 rounds remain after this batch, R542 through R556 fully
        // on disk, the 60-round underdark set riding into the home stretch
    if (dsg4SetRoundsRemaining() != 7
            || dsg4R542ThroughR556Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated spec
        // JSONs, every parse-back green
    if (dsg4RecordsPromoted() != 1
            || dsg4DiffBackGreen() != 1
        )
            ++bad;
        printf("R997 DSG promotion batch four audit: bad %d\n", bad);
        if (bad) return 1;
    }
