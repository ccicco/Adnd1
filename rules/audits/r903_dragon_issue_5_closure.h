    // ---- R903 Dragon issue-5 closure audit ----
    // THE DRAGON ISSUE-5 BOX CLOSING ROUND - the pure bookkeeping round, no
    // new print ink. The flip: the issue-5 box in
    // tools/dragon_gap_report_005.md goes [x] - 1 closed / 0 open, the
    // issue-5 walk complete, the three chains (the Witchcraft Supplement, the
    // Anhkheg lore-against-def pin, the Wizard Research Rules at folios 4-9,
    // 12+28, 24-26+28) having been the only engine-relevant ink in issue #5.
    // The bookkeeping pins: the single box and its three chains, the issue-4
    // report complete at 1 / 0 since R901, the registry ground truth carried
    // forward (the 1311 live census against the 1333 base lua files with the
    // 25 never-load errors, a pre-R900 print-fidelity state untouched), and
    // the variant-layer doctrine riding the closure. The R902 record seats in
    // the seed via prev_record.
    {
        using namespace rules;
        int bad = 0;
    if (cwxReportBoxes() != 1
            || cwxIssue5Chains() != 3
            || cwxIssue4Closed() != 1
            || cwxLiveRegistry() != 1311
            || cwxBaseLuaFiles() != 1333
            || cwxRegistryLoadErrors() != 25
            || !cwxIssue4WalkComplete()
            || !cwxIssue5WalkComplete()
            || !cwxVariantLayerDoctrine()
        )
            ++bad;
        // the walk bookkeeping - the issue-5 single box closing over its
        // three chains, and the issue-4 report complete at 1 / 0 (gap reports
        // 004 and 005)
    if (cwxReportBoxes() != 1
            || cwxIssue5Chains() != 3
            || cwxIssue4Closed() != 1
        )
            ++bad;
        // the registry ground truth - 1311 live defs against the 1333 base
        // files with the 25 never-load errors (the R900 lesson)
    if (cwxLiveRegistry() != 1311
            || cwxBaseLuaFiles() != 1333
            || cwxRegistryLoadErrors() != 25
        )
            ++bad;
        // the walk-complete bools for issues 4 and 5, and the variant-layer
        // doctrine riding the closure
    if (cwxIssue4WalkComplete() != 1
            || cwxIssue5WalkComplete() != 1
            || cwxVariantLayerDoctrine() != 1
        )
            ++bad;
        printf("R903 Dragon issue-5 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
