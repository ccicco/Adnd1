    // ---- R1010 MM1 normalization batch two audit ----
    // THE MM1 NORMALIZATION BATCH TWO - the per-book schema pass, MM1 part
    // two of six. 90 defs (letters g-k) rewritten to the full-field 57-key
    // emission, byte-exact against the repaired, landed
    // normalize_registry.py; no normalizer repairs ride this round - both
    // landed in R1009. The classed ki-rin rides this batch, its magic-user 18
    // save preserved.
    {
        using namespace rules;
        int bad = 0;
    if (mn2Round() != 1010
            || mn2DefsNormalized() != 90
            || mn2Mm1Total() != 408
            || mn2Mm1NormalizedAfter() != 189
            || mn2Mm1Remaining() != 219
            || mn2SchemaKeys() != 57
            || mn2InsSites() != 466
            || mn2ReorderDefs() != 22
            || mn2MoveSites() != 1
            || mn2PatchEntries() != 488
            || !mn2NormalizerCensusLive()
            || !mn2FullFieldEmission()
            || !mn2FieldOrderCanonical()
            || !mn2NormalizerByteExact()
        )
            ++bad;
        // the batch census - 90 more of 408 MM1 defs normalized, 189
        // canonical, 219 remaining for batches three through six, the 57-key
        // schema throughout
    if (mn2Round() != 1010
            || mn2DefsNormalized() != 90
            || mn2Mm1Total() != 408
            || mn2Mm1NormalizedAfter() != 189
            || mn2Mm1Remaining() != 219
            || mn2SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 466 anchored insert sites, 22 reorder defs, 1
        // move encodings, 488 file patches, no normalizer repairs this round
    if (mn2InsSites() != 466
            || mn2ReorderDefs() != 22
            || mn2MoveSites() != 1
            || mn2PatchEntries() != 488
        )
            ++bad;
        printf("R1010 MM1 normalization batch two audit: bad %d\n", bad);
        if (bad) return 1;
    }
