    // ---- R913 Dragon issue-9 closure audit ----
    // THE DRAGON ISSUE-9 CLOSURE ROUND - the pure flip. The issue-9 box (the
    // Gygax alignment article and the Ward Tombs & Crypts article, folios 5-6
    // and 25) closes 1 / 0 in tools/dragon_gap_report_009.md; the two-chain
    // walk completes exactly as adjudicated at R912. The bookkeeping pins:
    // the single box and its two chains, the issue-8 report complete at 1 / 0
    // since R911, the issue-7 report complete at 1 / 0 since R909, the
    // issue-6 report complete at 1 / 0 since R907, and the registry ground
    // truth carried forward.
    {
        using namespace rules;
        int bad = 0;
    if (dnpReportBoxes() != 1
            || dnpIssue9Chains() != 2
            || dnpIssue8Closed() != 1
            || dnpIssue7Closed() != 1
            || dnpIssue6Closed() != 1
            || dnpLiveRegistry() != 1311
            || dnpBaseLuaFiles() != 1333
            || dnpRegistryLoadErrors() != 25
            || !dnpIssue6WalkComplete()
            || !dnpIssue7WalkComplete()
            || !dnpIssue8WalkComplete()
            || !dnpIssue9WalkComplete()
            || !dnpVariantLayerDoctrine()
        )
            ++bad;
        // the walk bookkeeping - the single issue-9 box and its two chains,
        // the issue-8, issue-7 and issue-6 reports complete at 1 / 0
    if (dnpReportBoxes() != 1
            || dnpIssue9Chains() != 2
            || dnpIssue8Closed() != 1
            || dnpIssue7Closed() != 1
            || dnpIssue6Closed() != 1
        )
            ++bad;
        // the registry ground truth carried forward - the 1311 live census,
        // the 1333 base lua files, the 25 never-load errors, the battery line
        // the only ground truth
    if (dnpLiveRegistry() != 1311
            || dnpBaseLuaFiles() != 1333
            || dnpRegistryLoadErrors() != 25
        )
            ++bad;
        // the four walks complete - issue 6 at R907, issue 7 at R909, issue 8
        // at R911, issue 9 at this round - and the variant-layer doctrine
        // riding the closure
    if (dnpIssue6WalkComplete() != 1
            || dnpIssue7WalkComplete() != 1
            || dnpIssue8WalkComplete() != 1
            || dnpIssue9WalkComplete() != 1
            || dnpVariantLayerDoctrine() != 1
        )
            ++bad;
        printf("R913 Dragon issue-9 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
