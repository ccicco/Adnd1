    // ---- R992 WSG promotion batch four audit ----
    // the batch four audit - seven records, 1035 model items, rounds R490
    // through R496 complete, cumulative 71 of the 77-round WSG set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (wsg4BatchRecords() != 7
            || wsg4ModelItems() != 1035
            || wsg4CumulativeRecords() != 71
            || wsg4SetRoundsRemaining() != 6
            || !wsg4RecordsPromoted()
            || !wsg4DiffBackGreen()
            || !wsg4R490ThroughR496Complete()
        )
            ++bad;
        // the batch - seven records, 1035 model items, the cumulative 71 of
        // the set
    if (wsg4BatchRecords() != 7
            || wsg4ModelItems() != 1035
            || wsg4CumulativeRecords() != 71
        )
            ++bad;
        // the set - 6 rounds remain after this batch, R490 through R496 fully
        // on disk, the 77-round wilderness set nearly home
    if (wsg4SetRoundsRemaining() != 6
            || wsg4R490ThroughR496Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated spec
        // JSONs, every parse-back green
    if (wsg4RecordsPromoted() != 1
            || wsg4DiffBackGreen() != 1
        )
            ++bad;
        printf("R992 WSG promotion batch four audit: bad %d\n", bad);
        if (bad) return 1;
    }
