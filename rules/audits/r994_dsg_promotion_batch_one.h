    // ---- R994 DSG promotion batch one audit ----
    // the batch one audit - eight records, 1087 model items, rounds R503
    // through R510 complete, cumulative 8 of the 60-round DSG set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dsg1BatchRecords() != 8
            || dsg1ModelItems() != 1087
            || dsg1CumulativeRecords() != 8
            || dsg1SetRoundsRemaining() != 52
            || !dsg1RecordsPromoted()
            || !dsg1DiffBackGreen()
            || !dsg1R503ThroughR510Complete()
        )
            ++bad;
        // the batch - eight records, 1087 model items, the cumulative eight
        // of the set
    if (dsg1BatchRecords() != 8
            || dsg1ModelItems() != 1087
            || dsg1CumulativeRecords() != 8
        )
            ++bad;
        // the set - 52 rounds remain after this batch, R503 through R510
        // fully on disk, the 60-round underdark set open
    if (dsg1SetRoundsRemaining() != 52
            || dsg1R503ThroughR510Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated spec
        // JSONs, every parse-back green
    if (dsg1RecordsPromoted() != 1
            || dsg1DiffBackGreen() != 1
        )
            ++bad;
        printf("R994 DSG promotion batch one audit: bad %d\n", bad);
        if (bad) return 1;
    }
