    // ---- R976 dragon promotion batch eight audit ----
    // the batch eight audit - four records, 374 model items, issues 15
    // through 16 complete, cumulative 44 of the 79-round set, the parse-back
    // proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp8BatchRecords() != 4
            || dp8ModelItems() != 374
            || dp8CumulativeRecords() != 44
            || dp8SetRoundsRemaining() != 35
            || !dp8RecordsPromoted()
            || !dp8DiffBackGreen()
            || !dp8IssuesFifteenSixteenComplete()
        )
            ++bad;
        // the batch - four records, 374 model items, cumulative forty-four of
        // the set
    if (dp8BatchRecords() != 4
            || dp8ModelItems() != 374
            || dp8CumulativeRecords() != 44
        )
            ++bad;
        // the progress - 35 rounds remain after this batch, issues 15 and 16
        // fully on disk
    if (dp8SetRoundsRemaining() != 35
            || dp8IssuesFifteenSixteenComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp8RecordsPromoted() != 1
            || dp8DiffBackGreen() != 1
        )
            ++bad;
        printf("R976 dragon promotion batch eight audit: bad %d\n", bad);
        if (bad) return 1;
    }
