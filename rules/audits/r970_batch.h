    // ---- R970 dragon promotion batch two audit ----
    // the batch two audit - three records, 255 model items, issue 3 complete,
    // cumulative 11 of the 79-round set, the parse-back proof green on every
    // record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp2BatchRecords() != 3
            || dp2ModelItems() != 255
            || dp2CumulativeRecords() != 11
            || dp2SetRoundsRemaining() != 68
            || !dp2RecordsPromoted()
            || !dp2DiffBackGreen()
            || !dp2IssueThreeComplete()
        )
            ++bad;
        // the batch - three records, 255 model items, cumulative eleven of
        // the set
    if (dp2BatchRecords() != 3
            || dp2ModelItems() != 255
            || dp2CumulativeRecords() != 11
        )
            ++bad;
        // the progress - 68 rounds remain after this batch, issue 3 fully on
        // disk
    if (dp2SetRoundsRemaining() != 68
            || dp2IssueThreeComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp2RecordsPromoted() != 1
            || dp2DiffBackGreen() != 1
        )
            ++bad;
        printf("R970 dragon promotion batch two audit: bad %d\n", bad);
        if (bad) return 1;
    }
