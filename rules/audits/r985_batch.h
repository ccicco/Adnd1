    // ---- R985 OA promotion batch five audit ----
    // the batch five audit - eighteen records, 825 model items, rounds R695
    // through R712 complete, cumulative 99 of the 160-round OA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (oa5BatchRecords() != 18
            || oa5ModelItems() != 825
            || oa5CumulativeRecords() != 99
            || oa5SetRoundsRemaining() != 61
            || !oa5RecordsPromoted()
            || !oa5DiffBackGreen()
            || !oa5R695ThroughR712Complete()
        )
            ++bad;
        // the batch - eighteen records, 825 model items, cumulative
        // ninety-nine of the set
    if (oa5BatchRecords() != 18
            || oa5ModelItems() != 825
            || oa5CumulativeRecords() != 99
        )
            ++bad;
        // the set - 61 rounds remain after this batch, R695 through R712
        // fully on disk
    if (oa5SetRoundsRemaining() != 61
            || oa5R695ThroughR712Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the pin headers,
        // every parse-back green
    if (oa5RecordsPromoted() != 1
            || oa5DiffBackGreen() != 1
        )
            ++bad;
        printf("R985 OA promotion batch five audit: bad %d\n", bad);
        if (bad) return 1;
    }
