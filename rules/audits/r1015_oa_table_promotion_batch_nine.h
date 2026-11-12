    // ---- R1015 OA table promotion batch nine audit ----
    // THE OA TABLE PROMOTION BATCH NINE - the promotions doctrine continued:
    // the 139 table grids the R981-R988 promotion batches left behind in the
    // C++ pins, promoted from the R614-R773 specs into the 94 OA Lua records,
    // every record parse-back equal.
    {
        using namespace rules;
        int bad = 0;
    if (oa9BatchRecords() != 94
            || oa9TablesPromoted() != 139
            || oa9CumulativeTables() != 139
            || oa9SetTablesRemaining() != 0
            || !oa9RecordsCarryTables()
            || !oa9DiffBackGreen()
            || !oa9R615ThroughR759Complete()
        )
            ++bad;
        printf("R1015 OA table promotion batch nine audit: bad %d\n", bad);
        if (bad) return 1;
    }
