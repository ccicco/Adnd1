    // ---- R998 DSG promotion batch five audit ----
    // the batch five audit - seven records, 82 model items, rounds R557
    // through R563 complete, cumulative 60 of the 60-round DSG set - the set
    // closer, the parse-back proof green on every record, every fact
    // fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dsg5BatchRecords() != 7
            || dsg5ModelItems() != 82
            || dsg5CumulativeRecords() != 60
            || dsg5SetRoundsRemaining() != 0
            || !dsg5RecordsPromoted()
            || !dsg5DiffBackGreen()
            || !dsg5SetComplete()
        )
            ++bad;
        // the batch - seven records, 82 model items, the cumulative 60 of the
        // set
    if (dsg5BatchRecords() != 7
            || dsg5ModelItems() != 82
            || dsg5CumulativeRecords() != 60
        )
            ++bad;
        // the set - zero rounds remain after this batch, the 60-round
        // underdark set CLOSED at R998
    if (dsg5SetRoundsRemaining() != 0
            || dsg5SetComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated spec
        // JSONs, every parse-back green
    if (dsg5RecordsPromoted() != 1
            || dsg5DiffBackGreen() != 1
        )
            ++bad;
        printf("R998 DSG promotion batch five audit: bad %d\n", bad);
        if (bad) return 1;
    }
