    // ---- R974 dragon promotion batch six audit ----
    // the batch six audit - five records, 253 model items, issues 11 through
    // 12 complete, cumulative 35 of the 79-round set, the parse-back proof
    // green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp6BatchRecords() != 5
            || dp6ModelItems() != 253
            || dp6CumulativeRecords() != 35
            || dp6SetRoundsRemaining() != 44
            || !dp6RecordsPromoted()
            || !dp6DiffBackGreen()
            || !dp6IssuesElevenTwelveComplete()
        )
            ++bad;
        // the batch - five records, 253 model items, cumulative thirty-five
        // of the set
    if (dp6BatchRecords() != 5
            || dp6ModelItems() != 253
            || dp6CumulativeRecords() != 35
        )
            ++bad;
        // the progress - 44 rounds remain after this batch, issues 11 and 12
        // fully on disk
    if (dp6SetRoundsRemaining() != 44
            || dp6IssuesElevenTwelveComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp6RecordsPromoted() != 1
            || dp6DiffBackGreen() != 1
        )
            ++bad;
        printf("R974 dragon promotion batch six audit: bad %d\n", bad);
        if (bad) return 1;
    }
