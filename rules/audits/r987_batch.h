    // ---- R987 OA promotion batch seven audit ----
    // the batch seven audit - thirty-three records, 897 model items, rounds
    // R727 through R759 complete, cumulative 146 of the 160-round OA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (oa7BatchRecords() != 33
            || oa7ModelItems() != 897
            || oa7CumulativeRecords() != 146
            || oa7SetRoundsRemaining() != 14
            || !oa7RecordsPromoted()
            || !oa7DiffBackGreen()
            || !oa7R727ThroughR759Complete()
        )
            ++bad;
        // the batch - thirty-three records, 897 model items, cumulative one
        // hundred forty-six of the set
    if (oa7BatchRecords() != 33
            || oa7ModelItems() != 897
            || oa7CumulativeRecords() != 146
        )
            ++bad;
        // the set - 14 rounds remain after this batch, R727 through R759
        // fully on disk
    if (oa7SetRoundsRemaining() != 14
            || oa7R727ThroughR759Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the pin headers,
        // every parse-back green
    if (oa7RecordsPromoted() != 1
            || oa7DiffBackGreen() != 1
        )
            ++bad;
        printf("R987 OA promotion batch seven audit: bad %d\n", bad);
        if (bad) return 1;
    }
