    // ---- R977 dragon promotion batch nine audit ----
    // the batch nine audit - six records, 729 model items, issues 17 through
    // 18 complete, cumulative 50 of the 79-round set, the parse-back proof
    // green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp9BatchRecords() != 6
            || dp9ModelItems() != 729
            || dp9CumulativeRecords() != 50
            || dp9SetRoundsRemaining() != 29
            || !dp9RecordsPromoted()
            || !dp9DiffBackGreen()
            || !dp9IssuesSeventeenEighteenComplete()
        )
            ++bad;
        // the batch - six records, 729 model items, cumulative fifty of the
        // set, the halfway mark
    if (dp9BatchRecords() != 6
            || dp9ModelItems() != 729
            || dp9CumulativeRecords() != 50
        )
            ++bad;
        // the progress - 29 rounds remain after this batch, issues 17 and 18
        // fully on disk
    if (dp9SetRoundsRemaining() != 29
            || dp9IssuesSeventeenEighteenComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp9RecordsPromoted() != 1
            || dp9DiffBackGreen() != 1
        )
            ++bad;
        printf("R977 dragon promotion batch nine audit: bad %d\n", bad);
        if (bad) return 1;
    }
