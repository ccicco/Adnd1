    // ---- R1004 UA promotion batch six audit ----
    // the batch six audit - sixteen records, 366 model items, rounds R391
    // through R423 complete, cumulative 71 of the 76-round UA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (ua6BatchRecords() != 16
            || ua6ModelItems() != 366
            || ua6CumulativeRecords() != 71
            || ua6SetRoundsRemaining() != 5
            || !ua6RecordsPromoted()
            || !ua6DiffBackGreen()
            || !ua6R391ThroughR423Complete()
        )
            ++bad;
        // the batch - sixteen records, 366 model items, the cumulative
        // seventy-one of the set
    if (ua6BatchRecords() != 16
            || ua6ModelItems() != 366
            || ua6CumulativeRecords() != 71
        )
            ++bad;
        // the set - 5 rounds remain after this batch, R391 through R423 fully
        // on disk, the 76-round Unearthed Arcana set open
    if (ua6SetRoundsRemaining() != 5
            || ua6R391ThroughR423Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated pin
        // headers, every parse-back green
    if (ua6RecordsPromoted() != 1
            || ua6DiffBackGreen() != 1
        )
            ++bad;
        printf("R1004 UA promotion batch six audit: bad %d\n", bad);
        if (bad) return 1;
    }
