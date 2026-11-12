    // ---- R988 OA promotion batch eight audit ----
    // the batch eight audit - fourteen records, 328 model items, rounds R760
    // through R773 complete, cumulative 160 of the 160-round OA set - the set
    // closer, the parse-back proof green on every record, every fact
    // fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (oa8BatchRecords() != 14
            || oa8ModelItems() != 328
            || oa8CumulativeRecords() != 160
            || oa8SetRoundsRemaining() != 0
            || !oa8RecordsPromoted()
            || !oa8DiffBackGreen()
            || !oa8SetComplete()
        )
            ++bad;
        // the batch - fourteen records, 328 model items, the cumulative one
        // hundred sixty of the set
    if (oa8BatchRecords() != 14
            || oa8ModelItems() != 328
            || oa8CumulativeRecords() != 160
        )
            ++bad;
        // the set - zero rounds remain after this batch, R760 through R773
        // fully on disk, the 160-round set closed
    if (oa8SetRoundsRemaining() != 0
            || oa8SetComplete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the pin headers,
        // every parse-back green
    if (oa8RecordsPromoted() != 1
            || oa8DiffBackGreen() != 1
        )
            ++bad;
        printf("R988 OA promotion batch eight audit: bad %d\n", bad);
        if (bad) return 1;
    }
