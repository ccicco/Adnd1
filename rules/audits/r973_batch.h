    // ---- R973 dragon promotion batch five audit ----
    // the batch five audit - seven records, 288 model items, issues 8 through
    // 10 complete, cumulative 30 of the 79-round set, the parse-back proof
    // green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp5BatchRecords() != 7
            || dp5ModelItems() != 288
            || dp5CumulativeRecords() != 30
            || dp5SetRoundsRemaining() != 49
            || !dp5RecordsPromoted()
            || !dp5DiffBackGreen()
            || !dp5IssuesEightTenComplete()
        )
            ++bad;
        // the batch - seven records, 288 model items, cumulative thirty of
        // the set
    if (dp5BatchRecords() != 7
            || dp5ModelItems() != 288
            || dp5CumulativeRecords() != 30
        )
            ++bad;
        // the progress - 49 rounds remain after this batch, issues 8 through
        // 10 fully on disk
    if (dp5SetRoundsRemaining() != 49
            || dp5IssuesEightTenComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp5RecordsPromoted() != 1
            || dp5DiffBackGreen() != 1
        )
            ++bad;
        printf("R973 dragon promotion batch five audit: bad %d\n", bad);
        if (bad) return 1;
    }
