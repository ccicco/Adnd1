    // ---- R1021 FF normalization audit ----
    // THE FF NORMALIZATION OPENER - the letters a-g, the first 71 of 185 defs
    // rewritten to the full-field 57-key emission, byte-exact against the
    // landed normalize_registry.py; every patch an anchored sentinel insert.
    {
        using namespace rules;
        int bad = 0;
    if (fq1Round() != 1021
            || fq1DefsNormalized() != 71
            || fq1FfTotal() != 185
            || fq1FfNormalizedAfter() != 71
            || fq1FfRemaining() != 114
            || fq1SchemaKeys() != 57
            || fq1InsSites() != 497
            || fq1CommaSites() != 0
            || fq1ReorderDefs() != 0
            || fq1PatchEntries() != 497
            || !fq1NormalizerCensusLive()
            || !fq1FullFieldEmission()
            || !fq1InsertOnly()
            || !fq1NoClassedDefs()
        )
            ++bad;
        // the batch census - 71 FF defs normalized this batch, 185 total, 114
        // remaining
    if (fq1Round() != 1021
            || fq1DefsNormalized() != 71
            || fq1FfTotal() != 185
            || fq1FfNormalizedAfter() != 71
            || fq1FfRemaining() != 114
            || fq1SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 497 anchored inserts, 1917 inserted lines, zero
        // whole-line rewrites
    if (fq1InsSites() != 497
            || fq1CommaSites() != 0
            || fq1ReorderDefs() != 0
            || fq1PatchEntries() != 497
        )
            ++bad;
        // the FF census carries the batch - 71 canonical plus 114 sparse
        // equals the 185 total
    if (fq1FfNormalizedAfter() + fq1FfRemaining() != fq1FfTotal()
        )
            ++bad;
        printf("R1021 FF normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
