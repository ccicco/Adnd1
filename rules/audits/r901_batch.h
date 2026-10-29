    // ---- R901 Creature Features closure audit ----
    // THE CREATURE FEATURES BOX CLOSING ROUND - the pure bookkeeping round,
    // no new print ink. The flip: the Creature Features box in
    // tools/dragon_gap_report_004.md goes [x] - 1 closed / 0 open, the
    // issue-4 walk complete, the chain (the Mihalli, the Vriyagga, the Qu'uni
    // at folios 18-19, 21) having been the only engine-relevant ink in issue
    // #4. The bookkeeping pins: the single box and its three defs, the
    // issue-3 report complete at 5 / 0, and the registry ground truth from
    // the R900 lesson - the live census 1311 against the 1333 base lua files
    // with the 25 never-load errors, the battery line 'loaded 1311, errors
    // 25' the only ground truth for registry floors; the 25 long-broken
    // MM2/FF text lines are a pre-R900 print-fidelity state, untouched. The
    // R900 record seats in the seed via this round's prev_record. No file
    // patches, no data files, no tables - the census rides 823 -> 824.
    {
        using namespace rules;
        int bad = 0;
    if (cfcReportBoxes() != 1
            || cfcCreatureFeaturesDefs() != 3
            || cfcIssue3Closed() != 5
            || cfcLiveRegistry() != 1311
            || cfcBaseLuaFiles() != 1333
            || cfcRegistryLoadErrors() != 25
            || !cfcIssue3WalkComplete()
            || !cfcIssue4WalkComplete()
            || !cfcVariantLayerDoctrine()
            || !cfcPreR900LoadErrorState()
        )
            ++bad;
        // the walk bookkeeping - the issue-4 single box closing over its
        // three defs, and the issue-3 report complete at 5 / 0 (gap reports
        // 003 and 004)
    if (cfcReportBoxes() != 1
            || cfcCreatureFeaturesDefs() != 3
            || cfcIssue3Closed() != 5
        )
            ++bad;
        // the registry ground truth - 1311 loaded live, 1333 files on disk,
        // 25 never-load errors: the battery line is the ground truth, never
        // the file count (the R900 lesson)
    if (cfcLiveRegistry() != 1311
            || cfcBaseLuaFiles() != 1333
            || cfcRegistryLoadErrors() != 25
        )
            ++bad;
        // the closure doctrines - issue 3 complete, issue 4 complete at this
        // flip, the variant layer standing, the 25 errors a pre-R900 state
    if (cfcIssue3WalkComplete() != 1
            || cfcIssue4WalkComplete() != 1
            || cfcVariantLayerDoctrine() != 1
            || cfcPreR900LoadErrorState() != 1
        )
            ++bad;
        printf("R901 Creature Features closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
