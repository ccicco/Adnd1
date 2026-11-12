    // ---- R1011 MM1 normalization batch three audit ----
    // THE MM1 NORMALIZATION BATCH THREE - the per-book schema pass, MM1 part
    // three of six. 86 defs (letters l-p) rewritten to the full-field 57-key
    // emission, byte-exact against the landed normalize_registry.py; no
    // normalizer repairs ride this round - both landed in R1009.
    {
        using namespace rules;
        int bad = 0;
    if (mn3Round() != 1011
            || mn3DefsNormalized() != 86
            || mn3Mm1Total() != 408
            || mn3Mm1NormalizedAfter() != 275
            || mn3Mm1Remaining() != 133
            || mn3SchemaKeys() != 57
            || mn3InsSites() != 435
            || mn3ReorderDefs() != 25
            || mn3PatchEntries() != 461
            || !mn3NormalizerCensusLive()
            || !mn3FullFieldEmission()
            || !mn3FieldOrderCanonical()
            || !mn3NormalizerByteExact()
        )
            ++bad;
        // the batch census - 86 more of 408 MM1 defs normalized, 275
        // canonical, 133 remaining for batches four through six, the 57-key
        // schema throughout
    if (mn3Round() != 1011
            || mn3DefsNormalized() != 86
            || mn3Mm1Total() != 408
            || mn3Mm1NormalizedAfter() != 275
            || mn3Mm1Remaining() != 133
            || mn3SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 435 anchored insert sites, 25 reorder defs, 461
        // file patches, no normalizer repairs and no move encodings this
        // round
    if (mn3InsSites() != 435
            || mn3ReorderDefs() != 25
            || mn3PatchEntries() != 461
        )
            ++bad;
        printf("R1011 MM1 normalization batch three audit: bad %d\n", bad);
        if (bad) return 1;
    }
