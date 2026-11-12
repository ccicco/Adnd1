    // ---- R979 dragon promotion batch eleven audit ----
    // the batch eleven audit - eleven records, 1108 model items, issues 21
    // through 23 complete, cumulative 67 of the 79-round set, the parse-back
    // proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp11BatchRecords() != 11
            || dp11ModelItems() != 1108
            || dp11CumulativeRecords() != 67
            || dp11SetRoundsRemaining() != 12
            || !dp11RecordsPromoted()
            || !dp11DiffBackGreen()
            || !dp11IssuesTwentyOneTwentyThreeComplete()
        )
            ++bad;
        // the batch - eleven records, 1108 model items, cumulative
        // sixty-seven of the set
    if (dp11BatchRecords() != 11
            || dp11ModelItems() != 1108
            || dp11CumulativeRecords() != 67
        )
            ++bad;
        // the progress - 12 rounds remain after this batch, issues 21 through
        // 23 fully on disk
    if (dp11SetRoundsRemaining() != 12
            || dp11IssuesTwentyOneTwentyThreeComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp11RecordsPromoted() != 1
            || dp11DiffBackGreen() != 1
        )
            ++bad;
        printf("R979 dragon promotion batch eleven audit: bad %d\n", bad);
        if (bad) return 1;
    }
