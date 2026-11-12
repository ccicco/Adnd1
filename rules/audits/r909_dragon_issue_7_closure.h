    // ---- R909 Dragon issue-7 closure audit ----
    // THE DRAGON ISSUE-7 BOX CLOSING ROUND - the pure bookkeeping round, no
    // new print ink. The flip: the issue-7 box in
    // tools/dragon_gap_report_007.md goes [x] - 1 closed / 0 open, the
    // issue-7 walk complete, the Prowler (folio 24) having been the only
    // engine-relevant ink in issue #7. The bookkeeping pins: the single box
    // and its single chain, the issue-6 report complete at 1 / 0 since R907,
    // the issue-5 report complete at 1 / 0 since R903, the registry ground
    // truth carried forward (the 1311 live census against the 1333 base lua
    // files with the 25 never-load errors, a pre-R900 print-fidelity state
    // untouched), and the variant-layer doctrine riding the closure. The R908
    // record seats in the seed via prev_record.
    {
        using namespace rules;
        int bad = 0;
    if (cpxReportBoxes() != 1
            || cpxIssue7Chains() != 1
            || cpxIssue6Closed() != 1
            || cpxIssue5Closed() != 1
            || cpxLiveRegistry() != 1311
            || cpxBaseLuaFiles() != 1333
            || cpxRegistryLoadErrors() != 25
            || !cpxIssue5WalkComplete()
            || !cpxIssue6WalkComplete()
            || !cpxIssue7WalkComplete()
            || !cpxVariantLayerDoctrine()
        )
            ++bad;
        // the walk bookkeeping - the single issue-7 box and its single chain,
        // the issue-6 and issue-5 reports complete at 1 / 0
    if (cpxReportBoxes() != 1
            || cpxIssue7Chains() != 1
            || cpxIssue6Closed() != 1
            || cpxIssue5Closed() != 1
        )
            ++bad;
        // the registry ground truth carried forward - the 1311 live census,
        // the 1333 base lua files, the 25 never-load errors, the battery line
        // the only ground truth
    if (cpxLiveRegistry() != 1311
            || cpxBaseLuaFiles() != 1333
            || cpxRegistryLoadErrors() != 25
        )
            ++bad;
        // the three walks complete - issue 5 at R903, issue 6 at R907, issue
        // 7 at this round - and the variant-layer doctrine riding the closure
    if (cpxIssue5WalkComplete() != 1
            || cpxIssue6WalkComplete() != 1
            || cpxIssue7WalkComplete() != 1
            || cpxVariantLayerDoctrine() != 1
        )
            ++bad;
        printf("R909 Dragon issue-7 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
