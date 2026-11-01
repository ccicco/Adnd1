    // ---- R984 OA promotion batch four audit ----
    // the batch four audit - twenty-four records, 515 model items, rounds
    // R671 through R694 complete, cumulative 81 of the 160-round OA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (oa4BatchRecords() != 24
            || oa4ModelItems() != 515
            || oa4CumulativeRecords() != 81
            || oa4SetRoundsRemaining() != 79
            || !oa4RecordsPromoted()
            || !oa4DiffBackGreen()
            || !oa4R671ThroughR694Complete()
        )
            ++bad;
        // the batch - twenty-four records, 515 model items, cumulative
        // eighty-one of the set
    if (oa4BatchRecords() != 24
            || oa4ModelItems() != 515
            || oa4CumulativeRecords() != 81
        )
            ++bad;
        // the set - 79 rounds remain after this batch, R671 through R694
        // fully on disk
    if (oa4SetRoundsRemaining() != 79
            || oa4R671ThroughR694Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the pin headers,
        // every parse-back green
    if (oa4RecordsPromoted() != 1
            || oa4DiffBackGreen() != 1
        )
            ++bad;
        printf("R984 OA promotion batch four audit: bad %d\n", bad);
        if (bad) return 1;
    }
