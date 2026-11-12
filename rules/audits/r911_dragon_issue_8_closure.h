    // ---- R911 Dragon issue-8 closure audit ----
    // THE DRAGON ISSUE-8 BOX CLOSING ROUND - the pure bookkeeping round, no
    // new print ink. The flip: the issue-8 box in
    // tools/dragon_gap_report_008.md goes [x] - 1 closed / 0 open, the
    // issue-8 walk complete, the three chains (the Gygax Planes article, the
    // Watson towns article, the Kuntz gems re-evaluation at folios 4-5, 5-7,
    // 22-23) having been the only engine-relevant ink in issue #8. The
    // bookkeeping pins: the single box and its three chains, the issue-7
    // report complete at 1 / 0 since R909, the issue-6 report complete at 1 /
    // 0 since R907, the registry ground truth carried forward (the 1311 live
    // census against the 1333 base lua files with the 25 never-load errors, a
    // pre-R900 print-fidelity state untouched), and the variant-layer
    // doctrine riding the closure. The R910 record seats in the seed via
    // prev_record.
    {
        using namespace rules;
        int bad = 0;
    if (cgxReportBoxes() != 1
            || cgxIssue8Chains() != 3
            || cgxIssue7Closed() != 1
            || cgxIssue6Closed() != 1
            || cgxLiveRegistry() != 1311
            || cgxBaseLuaFiles() != 1333
            || cgxRegistryLoadErrors() != 25
            || !cgxIssue6WalkComplete()
            || !cgxIssue7WalkComplete()
            || !cgxIssue8WalkComplete()
            || !cgxVariantLayerDoctrine()
        )
            ++bad;
        // the walk bookkeeping - the single issue-8 box and its three chains,
        // the issue-7 and issue-6 reports complete at 1 / 0
    if (cgxReportBoxes() != 1
            || cgxIssue8Chains() != 3
            || cgxIssue7Closed() != 1
            || cgxIssue6Closed() != 1
        )
            ++bad;
        // the registry ground truth carried forward - the 1311 live census,
        // the 1333 base lua files, the 25 never-load errors, the battery line
        // the only ground truth
    if (cgxLiveRegistry() != 1311
            || cgxBaseLuaFiles() != 1333
            || cgxRegistryLoadErrors() != 25
        )
            ++bad;
        // the three walks complete - issue 6 at R907, issue 7 at R909, issue
        // 8 at this round - and the variant-layer doctrine riding the closure
    if (cgxIssue6WalkComplete() != 1
            || cgxIssue7WalkComplete() != 1
            || cgxIssue8WalkComplete() != 1
            || cgxVariantLayerDoctrine() != 1
        )
            ++bad;
        printf("R911 Dragon issue-8 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
