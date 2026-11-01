    // ---- R1019 MM2 normalization audit ----
    // THE MM2 NORMALIZATION - the per-book schema pass continued: 83 of 332
    // defs rewritten to the full-field 57-key emission, byte-exact against
    // the landed normalize_registry.py; the mongrelman and myconid by_level
    // pin repairs ride the round with their fragment grid-copy mirrors.
    {
        using namespace rules;
        int bad = 0;
    if (mq3Round() != 1019
            || mq3DefsNormalized() != 83
            || mq3Mm2Total() != 332
            || mq3Mm2NormalizedAfter() != 249
            || mq3Mm2Remaining() != 83
            || mq3SchemaKeys() != 57
            || mq3InsSites() != 583
            || mq3CommaSites() != 0
            || mq3ByLevelPinRepairs() != 4
            || mq3ReorderDefs() != 0
            || mq3PatchEntries() != 590
            || !mq3NormalizerCensusLive()
            || !mq3FullFieldEmission()
            || !mq3FieldOrderCanonical()
            || !mq3NormalizerByteExact()
        )
            ++bad;
        // the batch census - 83 MM2 defs normalized this batch, 249
        // canonical, 83 remaining, the 57-key schema throughout
    if (mq3Round() != 1019
            || mq3DefsNormalized() != 83
            || mq3Mm2Total() != 332
            || mq3Mm2NormalizedAfter() != 249
            || mq3Mm2Remaining() != 83
            || mq3SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 583 anchored inserts, zero whole-line rewrites,
        // 590 file patches
    if (mq3InsSites() != 583
            || mq3CommaSites() != 0
            || mq3ReorderDefs() != 0
            || mq3PatchEntries() != 590
        )
            ++bad;
        // the by_level pin repairs - the mongrelman (mm2lmn case 31) and
        // myconid (case 35) xp and xpPerHp cells, 0 to -1, the full-field
        // sentinel
    if (mq3ByLevelPinRepairs() != 4
        )
            ++bad;
        printf("R1019 MM2 normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
