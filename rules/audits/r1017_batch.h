    // ---- R1017 MM2 normalization audit ----
    // THE MM2 NORMALIZATION - the per-book schema pass continued: 83 of 332
    // defs rewritten to the full-field 57-key emission, byte-exact against
    // the landed normalize_registry.py; all insert sites, no reorder sites.
    {
        using namespace rules;
        int bad = 0;
    if (mqRound() != 1017
            || mqDefsNormalized() != 83
            || mqMm2Total() != 332
            || mqMm2NormalizedAfter() != 83
            || mqMm2Remaining() != 249
            || mqSchemaKeys() != 57
            || mqInsSites() != 586
            || mqReorderDefs() != 0
            || mqPatchEntries() != 586
            || !mqNormalizerCensusLive()
            || !mqFullFieldEmission()
            || !mqFieldOrderCanonical()
            || !mqNormalizerByteExact()
        )
            ++bad;
        // the batch census - 83 MM2 defs normalized this batch, 83 canonical,
        // 249 remaining, the 57-key schema throughout
    if (mqRound() != 1017
            || mqDefsNormalized() != 83
            || mqMm2Total() != 332
            || mqMm2NormalizedAfter() != 83
            || mqMm2Remaining() != 249
            || mqSchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 586 anchored insert sites, zero reorder defs,
        // 586 file patches, all inserts this round
    if (mqInsSites() != 586
            || mqReorderDefs() != 0
            || mqPatchEntries() != 586
        )
            ++bad;
        printf("R1017 MM2 normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
