    // ---- R969 dragon promotion batch one audit ----
    // the batch one audit - eight records, 281 model items, the corrected
    // 79-round Dragon set, the parse-back proof green on every record, every
    // fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp1BatchRecords() != 8
            || dp1ModelItems() != 281
            || dp1DragonSetRounds() != 79
            || dp1CumulativeRecords() != 8
            || !dp1RecordsPromoted()
            || !dp1DiffBackGreen()
            || !dp1MeasureCorrected()
        )
            ++bad;
        // the batch - eight records, 281 model items, cumulative eight of the
        // set
    if (dp1BatchRecords() != 8
            || dp1ModelItems() != 281
            || dp1CumulativeRecords() != 8
        )
            ++bad;
        // the correction - the walked Dragon set is 79 rounds, the R968 128
        // was a grep over-match
    if (dp1DragonSetRounds() != 79
            || dp1MeasureCorrected() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp1RecordsPromoted() != 1
            || dp1DiffBackGreen() != 1
        )
            ++bad;
        printf("R969 dragon promotion batch one audit: bad %d\n", bad);
        if (bad) return 1;
    }
