    // ---- R971 dragon promotion batch three audit ----
    // the batch three audit - four records, 447 model items, issue 4
    // complete, cumulative 15 of the 79-round set, the parse-back proof green
    // on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (dp3BatchRecords() != 4
            || dp3ModelItems() != 447
            || dp3CumulativeRecords() != 15
            || dp3SetRoundsRemaining() != 64
            || !dp3RecordsPromoted()
            || !dp3DiffBackGreen()
            || !dp3IssueFourComplete()
        )
            ++bad;
        // the batch - four records, 447 model items, cumulative fifteen of
        // the set
    if (dp3BatchRecords() != 4
            || dp3ModelItems() != 447
            || dp3CumulativeRecords() != 15
        )
            ++bad;
        // the progress - 64 rounds remain after this batch, issue 4 fully on
        // disk
    if (dp3SetRoundsRemaining() != 64
            || dp3IssueFourComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically, every parse-back green
    if (dp3RecordsPromoted() != 1
            || dp3DiffBackGreen() != 1
        )
            ++bad;
        printf("R971 dragon promotion batch three audit: bad %d\n", bad);
        if (bad) return 1;
    }
