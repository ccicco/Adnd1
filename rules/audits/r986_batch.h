    // ---- R986 OA promotion batch six audit ----
    // the batch six audit - fourteen records, 1141 model items, rounds R713
    // through R726 complete, cumulative 113 of the 160-round OA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (oa6BatchRecords() != 14
            || oa6ModelItems() != 1141
            || oa6CumulativeRecords() != 113
            || oa6SetRoundsRemaining() != 47
            || !oa6RecordsPromoted()
            || !oa6DiffBackGreen()
            || !oa6R713ThroughR726Complete()
        )
            ++bad;
        // the batch - fourteen records, 1141 model items, cumulative one
        // hundred thirteen of the set
    if (oa6BatchRecords() != 14
            || oa6ModelItems() != 1141
            || oa6CumulativeRecords() != 113
        )
            ++bad;
        // the set - 47 rounds remain after this batch, R713 through R726
        // fully on disk
    if (oa6SetRoundsRemaining() != 47
            || oa6R713ThroughR726Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the pin headers,
        // every parse-back green
    if (oa6RecordsPromoted() != 1
            || oa6DiffBackGreen() != 1
        )
            ++bad;
        printf("R986 OA promotion batch six audit: bad %d\n", bad);
        if (bad) return 1;
    }
