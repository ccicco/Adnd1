    // ---- R990 WSG promotion batch two audit ----
    // the batch two audit - twenty records, 625 model items, rounds R455
    // through R474 complete, cumulative 49 of the 77-round WSG set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (wsg2BatchRecords() != 20
            || wsg2ModelItems() != 625
            || wsg2CumulativeRecords() != 49
            || wsg2SetRoundsRemaining() != 28
            || !wsg2RecordsPromoted()
            || !wsg2DiffBackGreen()
            || !wsg2R455ThroughR474Complete()
        )
            ++bad;
        // the batch - twenty records, 625 model items, the cumulative 49 of
        // the set
    if (wsg2BatchRecords() != 20
            || wsg2ModelItems() != 625
            || wsg2CumulativeRecords() != 49
        )
            ++bad;
        // the set - 28 rounds remain after this batch, R455 through R474
        // fully on disk, the 77-round wilderness set in motion
    if (wsg2SetRoundsRemaining() != 28
            || wsg2R455ThroughR474Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated spec
        // JSONs, every parse-back green
    if (wsg2RecordsPromoted() != 1
            || wsg2DiffBackGreen() != 1
        )
            ++bad;
        printf("R990 WSG promotion batch two audit: bad %d\n", bad);
        if (bad) return 1;
    }
