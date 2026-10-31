    // ---- R978 dragon promotion batch ten audit ----
    // the batch ten audit - six records, 457 model items, issues 19 through
    // 20 complete, cumulative 56 of the 79-round set, the parse-back proof
    // green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp10BatchRecords() != 6
            || dp10ModelItems() != 457
            || dp10CumulativeRecords() != 56
            || dp10SetRoundsRemaining() != 23
            || !dp10RecordsPromoted()
            || !dp10DiffBackGreen()
            || !dp10IssuesNineteenTwentyComplete()
        )
            ++bad;
        // the batch - six records, 457 model items, cumulative fifty-six of
        // the set
    if (dp10BatchRecords() != 6
            || dp10ModelItems() != 457
            || dp10CumulativeRecords() != 56
        )
            ++bad;
        // the progress - 23 rounds remain after this batch, issues 19 and 20
        // fully on disk
    if (dp10SetRoundsRemaining() != 23
            || dp10IssuesNineteenTwentyComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp10RecordsPromoted() != 1
            || dp10DiffBackGreen() != 1
        )
            ++bad;
        printf("R978 dragon promotion batch ten audit: bad %d\n", bad);
        if (bad) return 1;
    }
