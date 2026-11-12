    // ---- R980 dragon promotion batch twelve audit ----
    // the batch twelve audit - twelve records, 1121 model items, issues 24
    // through 26 complete, cumulative 79 of the 79-round set - the set
    // closed, the parse-back proof green on every record, every fact
    // fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp12BatchRecords() != 12
            || dp12ModelItems() != 1121
            || dp12CumulativeRecords() != 79
            || dp12SetRoundsRemaining() != 0
            || !dp12RecordsPromoted()
            || !dp12DiffBackGreen()
            || !dp12IssuesTwentyFourTwentySixComplete()
        )
            ++bad;
        // the batch - twelve records, 1121 model items, cumulative
        // seventy-nine of the set
    if (dp12BatchRecords() != 12
            || dp12ModelItems() != 1121
            || dp12CumulativeRecords() != 79
        )
            ++bad;
        // the close - no rounds remain after this batch, issues 24 through 26
        // fully on disk, the set complete
    if (dp12SetRoundsRemaining() != 0
            || dp12IssuesTwentyFourTwentySixComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp12RecordsPromoted() != 1
            || dp12DiffBackGreen() != 1
        )
            ++bad;
        printf("R980 dragon promotion batch twelve audit: bad %d\n", bad);
        if (bad) return 1;
    }
