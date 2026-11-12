    // ---- R1005 UA promotion batch seven audit ----
    // the batch seven audit - five records, 487 model items, rounds R786
    // through R790 complete, cumulative 76 of the 76-round UA set, THE SET
    // CLOSER, the parse-back proof green on every record, every fact
    // fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (ua7BatchRecords() != 5
            || ua7ModelItems() != 487
            || ua7CumulativeRecords() != 76
            || ua7SetRoundsRemaining() != 0
            || !ua7RecordsPromoted()
            || !ua7DiffBackGreen()
            || !ua7SetComplete()
        )
            ++bad;
        // the batch - five records, 487 model items, the cumulative
        // seventy-six of the set
    if (ua7BatchRecords() != 5
            || ua7ModelItems() != 487
            || ua7CumulativeRecords() != 76
        )
            ++bad;
        // the set - 0 rounds remain after this batch, R786 through R790 fully
        // on disk, the 76-round Unearthed Arcana set CLOSED
    if (ua7SetRoundsRemaining() != 0
            || ua7SetComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated pin
        // headers, every parse-back green
    if (ua7RecordsPromoted() != 1
            || ua7DiffBackGreen() != 1
        )
            ++bad;
        printf("R1005 UA promotion batch seven audit: bad %d\n", bad);
        if (bad) return 1;
    }
