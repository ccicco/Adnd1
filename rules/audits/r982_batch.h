    // ---- R982 OA promotion batch two audit ----
    // the batch two audit - twenty records, 618 model items, rounds R625
    // through R644 complete, cumulative 31 of the 160-round OA set, the
    // parse-back proof green on every record, every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (oa2BatchRecords() != 20
            || oa2ModelItems() != 618
            || oa2CumulativeRecords() != 31
            || oa2SetRoundsRemaining() != 129
            || !oa2RecordsPromoted()
            || !oa2DiffBackGreen()
            || !oa2R625ThroughR644Complete()
        )
            ++bad;
        // the batch - twenty records, 618 model items, cumulative thirty-one
        // of the set
    if (oa2BatchRecords() != 20
            || oa2ModelItems() != 618
            || oa2CumulativeRecords() != 31
        )
            ++bad;
        // the set - 129 rounds remain after this batch, R625 through R644
        // fully on disk
    if (oa2SetRoundsRemaining() != 129
            || oa2R625ThroughR644Complete() != 1
        )
            ++bad;
        // the proof - records promoted mechanically from the pin headers,
        // every parse-back green
    if (oa2RecordsPromoted() != 1
            || oa2DiffBackGreen() != 1
        )
            ++bad;
        printf("R982 OA promotion batch two audit: bad %d\n", bad);
        if (bad) return 1;
    }
