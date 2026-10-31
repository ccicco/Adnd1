    // ---- R968 rules record format audit ----
    // the format audit - ten record fields, five model pools, the 25 Dragon
    // issues and 128 specs of the first batch, and the six format doctrines,
    // every fact fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (rpfRecordSections() != 10
            || rpfModelPools() != 5
            || rpfDragonIssues() != 25
            || rpfDragonSpecs() != 128
            || rpfBatchSize() != 128
            || rpfFormatVersion() != 1
            || !rpfRecordPerRound()
            || !rpfBucketByBook()
            || !rpfPromotedFromSpecs()
            || !rpfNoHandEdit()
            || !rpfBatteryFromRecords()
            || !rpfDragonFirst()
        )
            ++bad;
        // the shape - ten record fields over the five model pools
    if (rpfRecordSections() != 10
            || rpfModelPools() != 5
        )
            ++bad;
        // the first batch - 25 Dragon issues, 128 round specs walked by the
        // promotion builder
    if (rpfDragonIssues() != 25
            || rpfDragonSpecs() != 128
            || rpfBatchSize() != 128
        )
            ++bad;
        // the cut - one record per round, buckets by source book
    if (rpfRecordPerRound() != 1
            || rpfBucketByBook() != 1
        )
            ++bad;
        // the doctrine - promoted from specs, the translation back the proof,
        // never hand-edited
    if (rpfPromotedFromSpecs() != 1
            || rpfNoHandEdit() != 1
        )
            ++bad;
        // the move - the battery from records, the Dragon set first, format
        // version one
    if (rpfBatteryFromRecords() != 1
            || rpfDragonFirst() != 1
            || rpfFormatVersion() != 1
        )
            ++bad;
        printf("R968 rules record format audit: bad %d\n", bad);
        if (bad) return 1;
    }
