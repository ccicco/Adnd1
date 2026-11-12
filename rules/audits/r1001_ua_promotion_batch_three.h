    // ---- R1001 UA promotion batch three audit ----
    // the batch three audit - five records, 1229 model items, rounds R360
    // through R364 complete, cumulative 29 of the 76-round UA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (ua3BatchRecords() != 5
            || ua3ModelItems() != 1229
            || ua3CumulativeRecords() != 29
            || ua3SetRoundsRemaining() != 47
            || !ua3RecordsPromoted()
            || !ua3DiffBackGreen()
            || !ua3R360ThroughR364Complete()
        )
            ++bad;
        // the batch - five records, 1229 model items, the cumulative
        // twenty-nine of the set
    if (ua3BatchRecords() != 5
            || ua3ModelItems() != 1229
            || ua3CumulativeRecords() != 29
        )
            ++bad;
        // the set - 47 rounds remain after this batch, R360 through R364
        // fully on disk, the 76-round Unearthed Arcana set open
    if (ua3SetRoundsRemaining() != 47
            || ua3R360ThroughR364Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated pin
        // headers, every parse-back green
    if (ua3RecordsPromoted() != 1
            || ua3DiffBackGreen() != 1
        )
            ++bad;
        printf("R1001 UA promotion batch three audit: bad %d\n", bad);
        if (bad) return 1;
    }
