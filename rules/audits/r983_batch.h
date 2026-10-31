    // ---- R983 OA promotion batch three audit ----
    // the batch three audit - twenty-six records, 482 model items, rounds
    // R645 through R670 complete, cumulative 57 of the 160-round OA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (oa3BatchRecords() != 26
            || oa3ModelItems() != 482
            || oa3CumulativeRecords() != 57
            || oa3SetRoundsRemaining() != 103
            || !oa3RecordsPromoted()
            || !oa3DiffBackGreen()
            || !oa3R645ThroughR670Complete()
        )
            ++bad;
        // the batch - twenty-six records, 482 model items, cumulative
        // fifty-seven of the set
    if (oa3BatchRecords() != 26
            || oa3ModelItems() != 482
            || oa3CumulativeRecords() != 57
        )
            ++bad;
        // the set - 103 rounds remain after this batch, R645 through R670
        // fully on disk
    if (oa3SetRoundsRemaining() != 103
            || oa3R645ThroughR670Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the pin headers,
        // every parse-back green
    if (oa3RecordsPromoted() != 1
            || oa3DiffBackGreen() != 1
        )
            ++bad;
        printf("R983 OA promotion batch three audit: bad %d\n", bad);
        if (bad) return 1;
    }
