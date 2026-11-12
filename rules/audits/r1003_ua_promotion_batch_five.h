    // ---- R1003 UA promotion batch five audit ----
    // the batch five audit - ten records, 1350 model items, rounds R381
    // through R390 complete, cumulative 55 of the 76-round UA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (ua5BatchRecords() != 10
            || ua5ModelItems() != 1350
            || ua5CumulativeRecords() != 55
            || ua5SetRoundsRemaining() != 21
            || !ua5RecordsPromoted()
            || !ua5DiffBackGreen()
            || !ua5R381ThroughR390Complete()
        )
            ++bad;
        // the batch - ten records, 1350 model items, the cumulative
        // fifty-five of the set
    if (ua5BatchRecords() != 10
            || ua5ModelItems() != 1350
            || ua5CumulativeRecords() != 55
        )
            ++bad;
        // the set - 21 rounds remain after this batch, R381 through R390
        // fully on disk, the 76-round Unearthed Arcana set open
    if (ua5SetRoundsRemaining() != 21
            || ua5R381ThroughR390Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated pin
        // headers, every parse-back green
    if (ua5RecordsPromoted() != 1
            || ua5DiffBackGreen() != 1
        )
            ++bad;
        printf("R1003 UA promotion batch five audit: bad %d\n", bad);
        if (bad) return 1;
    }
