    // ---- R972 dragon promotion batch four audit ----
    // the batch four audit - eight records, 378 model items, issues 5 through
    // 7 complete, cumulative 23 of the 79-round set, the parse-back proof
    // green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp4BatchRecords() != 8
            || dp4ModelItems() != 378
            || dp4CumulativeRecords() != 23
            || dp4SetRoundsRemaining() != 56
            || !dp4RecordsPromoted()
            || !dp4DiffBackGreen()
            || !dp4IssuesFiveSevenComplete()
        )
            ++bad;
        // the batch - eight records, 378 model items, cumulative twenty-three
        // of the set
    if (dp4BatchRecords() != 8
            || dp4ModelItems() != 378
            || dp4CumulativeRecords() != 23
        )
            ++bad;
        // the progress - 56 rounds remain after this batch, issues 5 through
        // 7 fully on disk
    if (dp4SetRoundsRemaining() != 56
            || dp4IssuesFiveSevenComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp4RecordsPromoted() != 1
            || dp4DiffBackGreen() != 1
        )
            ++bad;
        printf("R972 dragon promotion batch four audit: bad %d\n", bad);
        if (bad) return 1;
    }
