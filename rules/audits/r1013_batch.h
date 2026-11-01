    // ---- R1013 MM1 normalization batch five audit ----
    // THE MM1 NORMALIZATION BATCH FIVE - the per-book schema pass, MM1 part
    // five of six. 40 defs (letters t-v) rewritten to the full-field 57-key
    // emission, byte-exact against the landed normalize_registry.py; no
    // normalizer repairs ride this round - both landed in R1009.
    {
        using namespace rules;
        int bad = 0;
    if (mn5Round() != 1013
            || mn5DefsNormalized() != 40
            || mn5Mm1Total() != 408
            || mn5Mm1NormalizedAfter() != 372
            || mn5Mm1Remaining() != 36
            || mn5SchemaKeys() != 57
            || mn5InsSites() != 190
            || mn5ReorderDefs() != 17
            || mn5PatchEntries() != 207
            || !mn5NormalizerCensusLive()
            || !mn5FullFieldEmission()
            || !mn5FieldOrderCanonical()
            || !mn5NormalizerByteExact()
        )
            ++bad;
        // the batch census - 40 more of 408 MM1 defs normalized, 372
        // canonical, 36 remaining for batch six, the 57-key schema throughout
    if (mn5Round() != 1013
            || mn5DefsNormalized() != 40
            || mn5Mm1Total() != 408
            || mn5Mm1NormalizedAfter() != 372
            || mn5Mm1Remaining() != 36
            || mn5SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 190 anchored insert sites, 17 reorder defs, 207
        // file patches, no normalizer repairs and no move encodings this
        // round
    if (mn5InsSites() != 190
            || mn5ReorderDefs() != 17
            || mn5PatchEntries() != 207
        )
            ++bad;
        printf("R1013 MM1 normalization batch five audit: bad %d\n", bad);
        if (bad) return 1;
    }
