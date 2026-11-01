    // ---- R989 WSG promotion batch one audit ----
    // the batch one audit - twenty-nine records, 723 model items, rounds R425
    // through R454 complete, cumulative 29 of the 77-round WSG set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (wsg1BatchRecords() != 29
            || wsg1ModelItems() != 723
            || wsg1CumulativeRecords() != 29
            || wsg1SetRoundsRemaining() != 48
            || !wsg1RecordsPromoted()
            || !wsg1DiffBackGreen()
            || !wsg1R425ThroughR454Complete()
        )
            ++bad;
        // the batch - twenty-nine records, 723 model items, the cumulative
        // twenty-nine of the set
    if (wsg1BatchRecords() != 29
            || wsg1ModelItems() != 723
            || wsg1CumulativeRecords() != 29
        )
            ++bad;
        // the set - 48 rounds remain after this batch, R425 through R454
        // fully on disk, the 77-round wilderness set open
    if (wsg1SetRoundsRemaining() != 48
            || wsg1R425ThroughR454Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated
        // records, every parse-back green
    if (wsg1RecordsPromoted() != 1
            || wsg1DiffBackGreen() != 1
        )
            ++bad;
        printf("R989 WSG promotion batch one audit: bad %d\n", bad);
        if (bad) return 1;
    }
