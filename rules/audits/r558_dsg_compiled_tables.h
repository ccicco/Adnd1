    // ---- R558 DSG compiled tables audit ----
    // The compiled tables pins printed pp. 121-123: the book's own reprint
    // spread, verified const-for-const against the landed pins - Tables 1-9
    // the movement reprints (R504/R505), 15-16 the odor, 17-18 the cave-ins,
    // 19 the DPV, 20 the unsteady reactions, 21-26 the boats, and 27-34 the
    // mining - with the Table 3 five-row grapple delta pinned this round (the
    // stone parapet, stone wall top, and tree branches rows the chapter
    // original lacked), the Table 1 and Table 2 footnotes, the Table 25
    // proficiency slash split, and the Table 33 pure-vein footnote. The
    // Compiled tables child flips [x] in the same commit.
    {
        using namespace rules;
        int bad = 0;
    if (dckCompiledTableCount() != 34
            || dckT3RowCount() != 5
            || dckT3ParapetMiss() != 72
            || dckT3ParapetSlip() != 78
            || dckT3WallTopMiss() != 83
            || dckT3WallTopSlip() != 89
            || dckT3BranchesMiss() != 66
            || dckT3BranchesSlip() != 70
            || dckT3CatchMax() != 100
            || !dckSpreadDefines()
            || !dckMovementReprints()
            || !dckT1Footnote()
            || !dckT2Footnote()
            || !dckT3Richer()
            || !dckOdorReprints()
            || !dckCaveInReprints()
            || !dckDpvReprints()
            || !dckUnsteadyReprints()
            || !dckBoatReprints()
            || !dckT25Footnote()
            || !dckMiningReprints()
            || !dckT33Footnote()
            || !dckT1014Absent()
        )
            ++bad;
        // the spread: thirty-four reprinted tables.
    if (dckCompiledTableCount() != 34
        )
            ++bad;
        // the grapple grid: five rows in the compiled reprint.
    if (dckT3RowCount() != 5
        )
            ++bad;
        // the stone parapet: 01-72 miss, 73-78 slip.
    if (dckT3ParapetMiss() != 72
            || dckT3ParapetSlip() != 78
        )
            ++bad;
        // the stone wall top: 01-83 miss, 84-89 slip.
    if (dckT3WallTopMiss() != 83
            || dckT3WallTopSlip() != 89
        )
            ++bad;
        // the tree branches: 01-66 miss, 67-70 slip.
    if (dckT3BranchesMiss() != 66
            || dckT3BranchesSlip() != 70
        )
            ++bad;
        // the catch maximum: 00 on every grapple row.
    if (dckT3CatchMax() != 100
        )
            ++bad;
        // the reprints verified: the movement and odor tables.
    if (dckMovementReprints() != 1
            || dckOdorReprints() != 1
        )
            ++bad;
        // the reprints verified: the boat and mining tables.
    if (dckBoatReprints() != 1
            || dckMiningReprints() != 1
        )
            ++bad;
        printf("R558 DSG compiled tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
