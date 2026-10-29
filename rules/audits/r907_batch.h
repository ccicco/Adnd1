    // ---- R907 Dragon issue-6 closure audit ----
    // THE DRAGON ISSUE-6 BOX CLOSING ROUND - the pure bookkeeping round, no
    // new print ink. The flip: the issue-6 box in
    // tools/dragon_gap_report_006.md goes [x] - 1 closed / 0 open, the
    // issue-6 walk complete, the four chains (the Sea Trade system, the
    // psionic option, the morale system, the Death Angel at folios 6, 25,
    // 26-27, 29) having been the only engine-relevant ink in issue #6. The
    // bookkeeping pins: the single box and its four chains, the issue-5
    // report complete at 1 / 0 since R903, the issue-4 report complete at 1 /
    // 0 since R901, the registry ground truth carried forward (the 1311 live
    // census against the 1333 base lua files with the 25 never-load errors, a
    // pre-R900 print-fidelity state untouched), and the variant-layer
    // doctrine riding the closure. The R906 record seats in the seed via
    // prev_record.
    {
        using namespace rules;
        int bad = 0;
    if (csxReportBoxes() != 1
            || csxIssue6Chains() != 4
            || csxIssue5Closed() != 1
            || csxIssue4Closed() != 1
            || csxLiveRegistry() != 1311
            || csxBaseLuaFiles() != 1333
            || csxRegistryLoadErrors() != 25
            || !csxIssue4WalkComplete()
            || !csxIssue5WalkComplete()
            || !csxIssue6WalkComplete()
            || !csxVariantLayerDoctrine()
        )
            ++bad;
        // the walk bookkeeping - the single issue-6 box and its four chains,
        // the issue-4 and issue-5 reports complete at 1 / 0
    if (csxReportBoxes() != 1
            || csxIssue6Chains() != 4
            || csxIssue5Closed() != 1
            || csxIssue4Closed() != 1
        )
            ++bad;
        // the registry ground truth carried forward - the 1311 live census,
        // the 1333 base lua files, the 25 never-load errors, the battery line
        // the only ground truth
    if (csxLiveRegistry() != 1311
            || csxBaseLuaFiles() != 1333
            || csxRegistryLoadErrors() != 25
        )
            ++bad;
        // the three walks complete - issue 4 at R901, issue 5 at R903, issue
        // 6 at this round - and the variant-layer doctrine riding the closure
    if (csxIssue4WalkComplete() != 1
            || csxIssue5WalkComplete() != 1
            || csxIssue6WalkComplete() != 1
            || csxVariantLayerDoctrine() != 1
        )
            ++bad;
        printf("R907 Dragon issue-6 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
