    // ---- R916 Dragon issue-10 closure audit ----
    // THE DRAGON ISSUE-10 CLOSURE ROUND - the pure flip. The issue-10
    // part-two box (the Gilbert dungeon method article, the Weights &
    // Measures article and the Holsinger level ritual article, folios 11-14,
    // 19-21) closes 2 closed / 0 open in tools/dragon_gap_report_010.md; the
    // six-chain walk completes exactly as adjudicated at R914 and R915. The
    // bookkeeping pins: the two boxes and their six chains, the issue-9
    // report complete at 1 / 0 since R913, the issue-8 report complete at 1 /
    // 0 since R911, the issue-7 report complete at 1 / 0 since R909, the
    // issue-6 report complete at 1 / 0 since R907, and the registry ground
    // truth carried forward.
    {
        using namespace rules;
        int bad = 0;
    if (dfpReportBoxes() != 2
            || dfpIssue10Chains() != 6
            || dfpIssue9Closed() != 1
            || dfpIssue8Closed() != 1
            || dfpIssue7Closed() != 1
            || dfpIssue6Closed() != 1
            || dfpLiveRegistry() != 1311
            || dfpBaseLuaFiles() != 1333
            || dfpRegistryLoadErrors() != 25
            || !dfpIssue6WalkComplete()
            || !dfpIssue7WalkComplete()
            || !dfpIssue8WalkComplete()
            || !dfpIssue9WalkComplete()
            || !dfpIssue10WalkComplete()
            || !dfpVariantLayerDoctrine()
        )
            ++bad;
        // the walk bookkeeping - the two issue-10 boxes and their six chains,
        // the issue-9, issue-8, issue-7 and issue-6 reports complete at 1 / 0
    if (dfpReportBoxes() != 2
            || dfpIssue10Chains() != 6
            || dfpIssue9Closed() != 1
            || dfpIssue8Closed() != 1
            || dfpIssue7Closed() != 1
            || dfpIssue6Closed() != 1
        )
            ++bad;
        // the registry ground truth carried forward - the 1311 live census,
        // the 1333 base lua files, the 25 never-load errors, the battery line
        // the only ground truth
    if (dfpLiveRegistry() != 1311
            || dfpBaseLuaFiles() != 1333
            || dfpRegistryLoadErrors() != 25
        )
            ++bad;
        // the five walks complete - issue 6 at R907, issue 7 at R909, issue 8
        // at R911, issue 9 at R913, issue 10 at this round - and the
        // variant-layer doctrine riding the closure
    if (dfpIssue6WalkComplete() != 1
            || dfpIssue7WalkComplete() != 1
            || dfpIssue8WalkComplete() != 1
            || dfpIssue9WalkComplete() != 1
            || dfpIssue10WalkComplete() != 1
            || dfpVariantLayerDoctrine() != 1
        )
            ++bad;
        printf("R916 Dragon issue-10 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
