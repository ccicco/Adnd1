    // ---- R993 WSG promotion batch five audit ----
    // the batch five audit - six records, 440 model items, rounds R497
    // through R502 complete, cumulative 77 of the 77-round WSG set - the set
    // closer, the parse-back proof green on every record, every fact
    // fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (wsg5BatchRecords() != 6
            || wsg5ModelItems() != 440
            || wsg5CumulativeRecords() != 77
            || wsg5SetRoundsRemaining() != 0
            || !wsg5RecordsPromoted()
            || !wsg5DiffBackGreen()
            || !wsg5SetComplete()
        )
            ++bad;
        // the batch - six records, 440 model items, the cumulative
        // seventy-seven of the set
    if (wsg5BatchRecords() != 6
            || wsg5ModelItems() != 440
            || wsg5CumulativeRecords() != 77
        )
            ++bad;
        // the set - zero rounds remain after this batch, R497 through R502
        // fully on disk, the 77-round set closed
    if (wsg5SetRoundsRemaining() != 0
            || wsg5SetComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the adjudicated spec
        // JSONs, every parse-back green
    if (wsg5RecordsPromoted() != 1
            || wsg5DiffBackGreen() != 1
        )
            ++bad;
        printf("R993 WSG promotion batch five audit: bad %d\n", bad);
        if (bad) return 1;
    }
