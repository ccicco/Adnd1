    // ---- R981 OA promotion batch one audit ----
    // the batch one audit - eleven records, 778 model items, rounds R614
    // through R624 complete, cumulative 11 of the 160-round OA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (oa1BatchRecords() != 11
            || oa1ModelItems() != 778
            || oa1CumulativeRecords() != 11
            || oa1SetRoundsRemaining() != 149
            || !oa1RecordsPromoted()
            || !oa1DiffBackGreen()
            || !oa1R614ThroughR624Complete()
        )
            ++bad;
        // the batch - eleven records, 778 model items, cumulative eleven of
        // the set
    if (oa1BatchRecords() != 11
            || oa1ModelItems() != 778
            || oa1CumulativeRecords() != 11
        )
            ++bad;
        // the set - 149 rounds remain after this batch, R614 through R624
        // fully on disk
    if (oa1SetRoundsRemaining() != 149
            || oa1R614ThroughR624Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the pin headers,
        // every parse-back green
    if (oa1RecordsPromoted() != 1
            || oa1DiffBackGreen() != 1
        )
            ++bad;
        printf("R981 OA promotion batch one audit: bad %d\n", bad);
        if (bad) return 1;
    }
