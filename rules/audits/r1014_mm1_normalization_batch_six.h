    // ---- R1014 MM1 normalization batch six audit ----
    // THE MM1 NORMALIZATION BATCH SIX - the per-book schema pass, MM1 part
    // six of six, CLOSING the book. 36 defs (letters w-z) rewritten to the
    // full-field 57-key emission, byte-exact against the landed
    // normalize_registry.py; no normalizer repairs ride this round - both
    // landed in R1009.
    {
        using namespace rules;
        int bad = 0;
    if (mn6Round() != 1014
            || mn6DefsNormalized() != 36
            || mn6Mm1Total() != 408
            || mn6Mm1NormalizedAfter() != 408
            || mn6Mm1Remaining() != 0
            || mn6SchemaKeys() != 57
            || mn6InsSites() != 178
            || mn6ReorderDefs() != 20
            || mn6PatchEntries() != 198
            || !mn6NormalizerCensusLive()
            || !mn6FullFieldEmission()
            || !mn6FieldOrderCanonical()
            || !mn6NormalizerByteExact()
        )
            ++bad;
        // the batch census - the final 36 of 408 MM1 defs normalized, 408
        // canonical, 0 remaining - the MM1 book closes complete, the 57-key
        // schema throughout
    if (mn6Round() != 1014
            || mn6DefsNormalized() != 36
            || mn6Mm1Total() != 408
            || mn6Mm1NormalizedAfter() != 408
            || mn6Mm1Remaining() != 0
            || mn6SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 178 anchored insert sites, 20 reorder defs, 198
        // file patches, no normalizer repairs and no move encodings this
        // round
    if (mn6InsSites() != 178
            || mn6ReorderDefs() != 20
            || mn6PatchEntries() != 198
        )
            ++bad;
        printf("R1014 MM1 normalization batch six audit: bad %d\n", bad);
        if (bad) return 1;
    }
