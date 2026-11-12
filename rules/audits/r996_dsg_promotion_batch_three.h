    // ---- R996 DSG promotion batch three audit ----
    // the batch three audit - fourteen records, 632 model items, rounds R528
    // through R541 complete, cumulative 38 of the 60-round DSG set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dsg3BatchRecords() != 14
            || dsg3ModelItems() != 632
            || dsg3CumulativeRecords() != 38
            || dsg3SetRoundsRemaining() != 22
            || !dsg3RecordsPromoted()
            || !dsg3DiffBackGreen()
            || !dsg3R528ThroughR541Complete()
        )
            ++bad;
        // the batch - fourteen records, 632 model items, the cumulative 38 of
        // the set
    if (dsg3BatchRecords() != 14
            || dsg3ModelItems() != 632
            || dsg3CumulativeRecords() != 38
        )
            ++bad;
        // the set - 22 rounds remain after this batch, R528 through R541
        // fully on disk, the 60-round underdark set past the halfway mark
    if (dsg3SetRoundsRemaining() != 22
            || dsg3R528ThroughR541Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated spec
        // JSONs, every parse-back green
    if (dsg3RecordsPromoted() != 1
            || dsg3DiffBackGreen() != 1
        )
            ++bad;
        printf("R996 DSG promotion batch three audit: bad %d\n", bad);
        if (bad) return 1;
    }
