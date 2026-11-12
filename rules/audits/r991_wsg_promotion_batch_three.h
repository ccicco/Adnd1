    // ---- R991 WSG promotion batch three audit ----
    // the batch three audit - fifteen records, 960 model items, rounds R475
    // through R489 complete, cumulative 64 of the 77-round WSG set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (wsg3BatchRecords() != 15
            || wsg3ModelItems() != 960
            || wsg3CumulativeRecords() != 64
            || wsg3SetRoundsRemaining() != 13
            || !wsg3RecordsPromoted()
            || !wsg3DiffBackGreen()
            || !wsg3R475ThroughR489Complete()
        )
            ++bad;
        // the batch - fifteen records, 960 model items, the cumulative 64 of
        // the set
    if (wsg3BatchRecords() != 15
            || wsg3ModelItems() != 960
            || wsg3CumulativeRecords() != 64
        )
            ++bad;
        // the set - 13 rounds remain after this batch, R475 through R489
        // fully on disk, the 77-round wilderness set three-quarters ridden
    if (wsg3SetRoundsRemaining() != 13
            || wsg3R475ThroughR489Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated spec
        // JSONs, every parse-back green
    if (wsg3RecordsPromoted() != 1
            || wsg3DiffBackGreen() != 1
        )
            ++bad;
        printf("R991 WSG promotion batch three audit: bad %d\n", bad);
        if (bad) return 1;
    }
