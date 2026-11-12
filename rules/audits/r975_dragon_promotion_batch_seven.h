    // ---- R975 dragon promotion batch seven audit ----
    // the batch seven audit - five records, 219 model items, issues 13
    // through 14 complete, cumulative 40 of the 79-round set, the parse-back
    // proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp7BatchRecords() != 5
            || dp7ModelItems() != 219
            || dp7CumulativeRecords() != 40
            || dp7SetRoundsRemaining() != 39
            || !dp7RecordsPromoted()
            || !dp7DiffBackGreen()
            || !dp7IssuesThirteenFourteenComplete()
        )
            ++bad;
        // the batch - five records, 219 model items, cumulative forty of the
        // set
    if (dp7BatchRecords() != 5
            || dp7ModelItems() != 219
            || dp7CumulativeRecords() != 40
        )
            ++bad;
        // the progress - 39 rounds remain after this batch, issues 13 and 14
        // fully on disk
    if (dp7SetRoundsRemaining() != 39
            || dp7IssuesThirteenFourteenComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp7RecordsPromoted() != 1
            || dp7DiffBackGreen() != 1
        )
            ++bad;
        printf("R975 dragon promotion batch seven audit: bad %d\n", bad);
        if (bad) return 1;
    }
