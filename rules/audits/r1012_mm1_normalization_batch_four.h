    // ---- R1012 MM1 normalization batch four audit ----
    // THE MM1 NORMALIZATION BATCH FOUR - the per-book schema pass, MM1 part
    // four of six. 57 defs (letters q-s) rewritten to the full-field 57-key
    // emission, byte-exact against the landed normalize_registry.py; no
    // normalizer repairs ride this round - both landed in R1009.
    {
        using namespace rules;
        int bad = 0;
    if (mn4Round() != 1012
            || mn4DefsNormalized() != 57
            || mn4Mm1Total() != 408
            || mn4Mm1NormalizedAfter() != 332
            || mn4Mm1Remaining() != 76
            || mn4SchemaKeys() != 57
            || mn4InsSites() != 294
            || mn4ReorderDefs() != 22
            || mn4PatchEntries() != 316
            || !mn4NormalizerCensusLive()
            || !mn4FullFieldEmission()
            || !mn4FieldOrderCanonical()
            || !mn4NormalizerByteExact()
        )
            ++bad;
        // the batch census - 57 more of 408 MM1 defs normalized, 332
        // canonical, 76 remaining for batches five and six, the 57-key schema
        // throughout
    if (mn4Round() != 1012
            || mn4DefsNormalized() != 57
            || mn4Mm1Total() != 408
            || mn4Mm1NormalizedAfter() != 332
            || mn4Mm1Remaining() != 76
            || mn4SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 294 anchored insert sites, 22 reorder defs, 316
        // file patches, no normalizer repairs and no move encodings this
        // round
    if (mn4InsSites() != 294
            || mn4ReorderDefs() != 22
            || mn4PatchEntries() != 316
        )
            ++bad;
        printf("R1012 MM1 normalization batch four audit: bad %d\n", bad);
        if (bad) return 1;
    }
