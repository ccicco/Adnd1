    // ---- R1023 FF normalization audit ----
    // THE FF NORMALIZATION, THE BOOK CLOSER - the letters s-z, the last 54 of
    // 185 defs rewritten to the full-field 57-key emission, byte-exact
    // against the landed normalize_registry.py; the FF book closes COMPLETE;
    // every patch an anchored sentinel insert.
    {
        using namespace rules;
        int bad = 0;
    if (fq3Round() != 1023
            || fq3DefsNormalized() != 54
            || fq3FfTotal() != 185
            || fq3FfNormalizedAfter() != 185
            || fq3FfRemaining() != 0
            || fq3SchemaKeys() != 57
            || fq3InsSites() != 378
            || fq3CommaSites() != 0
            || fq3ReorderDefs() != 0
            || fq3PatchEntries() != 378
            || !fq3NormalizerCensusLive()
            || !fq3FullFieldEmission()
            || !fq3InsertOnly()
            || !fq3NoClassedDefs()
        )
            ++bad;
        // the batch census - 54 FF defs normalized this batch, 185 canonical,
        // 0 remaining - the FF book complete
    if (fq3Round() != 1023
            || fq3DefsNormalized() != 54
            || fq3FfTotal() != 185
            || fq3FfNormalizedAfter() != 185
            || fq3FfRemaining() != 0
            || fq3SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 378 anchored inserts, 1458 inserted lines, zero
        // whole-line rewrites
    if (fq3InsSites() != 378
            || fq3CommaSites() != 0
            || fq3ReorderDefs() != 0
            || fq3PatchEntries() != 378
        )
            ++bad;
        // the FF census carries the batch - 185 canonical plus 0 sparse
        // equals the 185 total, the book closed
    if (fq3FfNormalizedAfter() + fq3FfRemaining() != fq3FfTotal()
        )
            ++bad;
        printf("R1023 FF normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
