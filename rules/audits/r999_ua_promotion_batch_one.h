    // ---- R999 UA promotion batch one audit ----
    // the batch one audit - thirteen records, 970 model items, rounds R333
    // through R348 complete, cumulative 13 of the 76-round UA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (ua1BatchRecords() != 13
            || ua1ModelItems() != 970
            || ua1CumulativeRecords() != 13
            || ua1SetRoundsRemaining() != 63
            || !ua1RecordsPromoted()
            || !ua1DiffBackGreen()
            || !ua1R333ThroughR348Complete()
        )
            ++bad;
        // the batch - thirteen records, 970 model items, the cumulative
        // thirteen of the set
    if (ua1BatchRecords() != 13
            || ua1ModelItems() != 970
            || ua1CumulativeRecords() != 13
        )
            ++bad;
        // the set - 63 rounds remain after this batch, R333 through R348
        // fully on disk, the 76-round Unearthed Arcana set open
    if (ua1SetRoundsRemaining() != 63
            || ua1R333ThroughR348Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated pin
        // headers, every parse-back green
    if (ua1RecordsPromoted() != 1
            || ua1DiffBackGreen() != 1
        )
            ++bad;
        printf("R999 UA promotion batch one audit: bad %d\n", bad);
        if (bad) return 1;
    }
