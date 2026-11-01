    // ---- R1018 MM2 normalization audit ----
    // THE MM2 NORMALIZATION - the per-book schema pass continued: 83 of 332
    // defs rewritten to the full-field 57-key emission, byte-exact against
    // the landed normalize_registry.py; the duergar and mandragora by_level
    // pin repairs ride the round with their fragment grid-copy mirrors.
    {
        using namespace rules;
        int bad = 0;
    if (mq2Round() != 1018
            || mq2DefsNormalized() != 83
            || mq2Mm2Total() != 332
            || mq2Mm2NormalizedAfter() != 166
            || mq2Mm2Remaining() != 166
            || mq2SchemaKeys() != 57
            || mq2InsSites() != 578
            || mq2CommaSites() != 5
            || mq2ByLevelPinRepairs() != 4
            || mq2ReorderDefs() != 5
            || mq2PatchEntries() != 592
            || !mq2NormalizerCensusLive()
            || !mq2FullFieldEmission()
            || !mq2FieldOrderCanonical()
            || !mq2NormalizerByteExact()
        )
            ++bad;
        // the batch census - 83 MM2 defs normalized this batch, 166
        // canonical, 166 remaining, the 57-key schema throughout
    if (mq2Round() != 1018
            || mq2DefsNormalized() != 83
            || mq2Mm2Total() != 332
            || mq2Mm2NormalizedAfter() != 166
            || mq2Mm2Remaining() != 166
            || mq2SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 578 anchored inserts, five trailing-comma
        // rewrites, 592 file patches
    if (mq2InsSites() != 578
            || mq2CommaSites() != 5
            || mq2ReorderDefs() != 5
            || mq2PatchEntries() != 592
        )
            ++bad;
        // the by_level pin repairs - the duergar (mm2dg case 10) and
        // mandragora (mm2lmn case 7) xp and xpPerHp cells, 0 to -1, the
        // full-field sentinel
    if (mq2ByLevelPinRepairs() != 4
        )
            ++bad;
        printf("R1018 MM2 normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
