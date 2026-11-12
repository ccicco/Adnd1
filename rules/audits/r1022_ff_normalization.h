    // ---- R1022 FF normalization audit ----
    // THE FF NORMALIZATION, BATCH TWO - the letters h-r, 60 of 185 defs
    // rewritten to the full-field 57-key emission, byte-exact against the
    // landed normalize_registry.py; every patch an anchored sentinel insert.
    {
        using namespace rules;
        int bad = 0;
    if (fq2Round() != 1022
            || fq2DefsNormalized() != 60
            || fq2FfTotal() != 185
            || fq2FfNormalizedAfter() != 131
            || fq2FfRemaining() != 54
            || fq2SchemaKeys() != 57
            || fq2InsSites() != 420
            || fq2CommaSites() != 0
            || fq2ReorderDefs() != 0
            || fq2PatchEntries() != 420
            || !fq2NormalizerCensusLive()
            || !fq2FullFieldEmission()
            || !fq2InsertOnly()
            || !fq2NoClassedDefs()
        )
            ++bad;
        // the batch census - 60 FF defs normalized this batch, 131 canonical,
        // 54 remaining - the book closes next round
    if (fq2Round() != 1022
            || fq2DefsNormalized() != 60
            || fq2FfTotal() != 185
            || fq2FfNormalizedAfter() != 131
            || fq2FfRemaining() != 54
            || fq2SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 420 anchored inserts, 1620 inserted lines, zero
        // whole-line rewrites
    if (fq2InsSites() != 420
            || fq2CommaSites() != 0
            || fq2ReorderDefs() != 0
            || fq2PatchEntries() != 420
        )
            ++bad;
        // the FF census carries the batch - 131 canonical plus 54 sparse
        // equals the 185 total
    if (fq2FfNormalizedAfter() + fq2FfRemaining() != fq2FfTotal()
        )
            ++bad;
        printf("R1022 FF normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
