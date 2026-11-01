    // ---- R1016 OA normalization audit ----
    // THE OA NORMALIZATION - the per-book schema pass continued: 47 defs
    // rewritten to the full-field 57-key emission, byte-exact against the
    // landed normalize_registry.py; all insert sites, no reorder sites; the
    // book closes complete.
    {
        using namespace rules;
        int bad = 0;
    if (oapRound() != 1016
            || oapDefsNormalized() != 47
            || oapOaTotal() != 47
            || oapOaNormalizedAfter() != 47
            || oapOaRemaining() != 0
            || oapSchemaKeys() != 57
            || oapInsSites() != 332
            || oapReorderDefs() != 0
            || oapPatchEntries() != 332
            || !oapNormalizerCensusLive()
            || !oapFullFieldEmission()
            || !oapFieldOrderCanonical()
            || !oapNormalizerByteExact()
        )
            ++bad;
        // the batch census - the final 47 OA defs normalized, 47 canonical, 0
        // remaining - the OA book closes complete, the 57-key schema
        // throughout
    if (oapRound() != 1016
            || oapDefsNormalized() != 47
            || oapOaTotal() != 47
            || oapOaNormalizedAfter() != 47
            || oapOaRemaining() != 0
            || oapSchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 332 anchored insert sites, zero reorder defs,
        // 332 file patches, all inserts this round
    if (oapInsSites() != 332
            || oapReorderDefs() != 0
            || oapPatchEntries() != 332
        )
            ++bad;
        printf("R1016 OA normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
