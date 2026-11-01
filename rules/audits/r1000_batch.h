    // ---- R1000 UA promotion batch two audit ----
    // the batch two audit - eleven records, 1201 model items, rounds R349
    // through R359 complete, cumulative 24 of the 76-round UA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (ua2BatchRecords() != 11
            || ua2ModelItems() != 1201
            || ua2CumulativeRecords() != 24
            || ua2SetRoundsRemaining() != 52
            || !ua2RecordsPromoted()
            || !ua2DiffBackGreen()
            || !ua2R349ThroughR359Complete()
        )
            ++bad;
        // the batch - eleven records, 1201 model items, the cumulative
        // twenty-four of the set
    if (ua2BatchRecords() != 11
            || ua2ModelItems() != 1201
            || ua2CumulativeRecords() != 24
        )
            ++bad;
        // the set - 52 rounds remain after this batch, R349 through R359
        // fully on disk, the 76-round Unearthed Arcana set open
    if (ua2SetRoundsRemaining() != 52
            || ua2R349ThroughR359Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated pin
        // headers, every parse-back green
    if (ua2RecordsPromoted() != 1
            || ua2DiffBackGreen() != 1
        )
            ++bad;
        printf("R1000 UA promotion batch two audit: bad %d\n", bad);
        if (bad) return 1;
    }
