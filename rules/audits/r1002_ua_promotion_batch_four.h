    // ---- R1002 UA promotion batch four audit ----
    // the batch four audit - sixteen records, 1355 model items, rounds R365
    // through R380 complete, cumulative 45 of the 76-round UA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (ua4BatchRecords() != 16
            || ua4ModelItems() != 1355
            || ua4CumulativeRecords() != 45
            || ua4SetRoundsRemaining() != 31
            || !ua4RecordsPromoted()
            || !ua4DiffBackGreen()
            || !ua4R365ThroughR380Complete()
        )
            ++bad;
        // the batch - sixteen records, 1355 model items, the cumulative
        // forty-five of the set
    if (ua4BatchRecords() != 16
            || ua4ModelItems() != 1355
            || ua4CumulativeRecords() != 45
        )
            ++bad;
        // the set - 31 rounds remain after this batch, R365 through R380
        // fully on disk, the 76-round Unearthed Arcana set open
    if (ua4SetRoundsRemaining() != 31
            || ua4R365ThroughR380Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated pin
        // headers, every parse-back green
    if (ua4RecordsPromoted() != 1
            || ua4DiffBackGreen() != 1
        )
            ++bad;
        printf("R1002 UA promotion batch four audit: bad %d\n", bad);
        if (bad) return 1;
    }
