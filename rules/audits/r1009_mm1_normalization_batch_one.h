    // ---- R1009 MM1 normalization batch one audit ----
    // THE MM1 NORMALIZATION BATCH ONE - the per-book schema pass, MM1 part
    // one of six. 99 defs (letters a-f) rewritten to the full-field 57-key
    // emission, byte-exact against the repaired normalize_registry.py; two
    // normalizer repairs ride as the first file patches - the REG glob
    // (census read zero since R879) and the saveAsBonus zero default (the
    // R155 data contract).
    {
        using namespace rules;
        int bad = 0;
    if (mn1Round() != 1009
            || mn1DefsNormalized() != 99
            || mn1Mm1Total() != 408
            || mn1Mm1NormalizedAfter() != 99
            || mn1Mm1Remaining() != 309
            || mn1SchemaKeys() != 57
            || mn1NormalizerRepairs() != 2
            || mn1InsSites() != 515
            || mn1ReorderDefs() != 23
            || mn1MoveSites() != 4
            || mn1PatchEntries() != 540
            || !mn1NormalizerPathRepaired()
            || !mn1SaveAsBonusZeroDefault()
            || !mn1FullFieldEmission()
            || !mn1FieldOrderCanonical()
            || !mn1NormalizerByteExact()
        )
            ++bad;
        // the batch census - 99 of 408 MM1 defs normalized, 309 remaining for
        // batches two through six, the 57-key schema throughout
    if (mn1Round() != 1009
            || mn1DefsNormalized() != 99
            || mn1Mm1Total() != 408
            || mn1Mm1Remaining() != 309
            || mn1SchemaKeys() != 57
        )
            ++bad;
        // the repair and patch anatomy - two normalizer repairs, 515 anchored
        // insert sites, 23 reorder defs, 4 move encodings, 540 file patches
    if (mn1NormalizerRepairs() != 2
            || mn1InsSites() != 515
            || mn1ReorderDefs() != 23
            || mn1MoveSites() != 4
            || mn1PatchEntries() != 540
        )
            ++bad;
        printf("R1009 MM1 normalization batch one audit: bad %d\n", bad);
        if (bad) return 1;
    }
