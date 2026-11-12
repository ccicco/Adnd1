    // ---- R1020 MM2 normalization audit ----
    // THE MM2 NORMALIZATION - the book closes: the last 83 of 332 defs
    // rewritten to the full-field 57-key emission, byte-exact against the
    // landed normalize_registry.py; the monster zombie pin repairs ride the
    // round with their fragment mirrors.
    {
        using namespace rules;
        int bad = 0;
    if (mq4Round() != 1020
            || mq4DefsNormalized() != 83
            || mq4Mm2Total() != 332
            || mq4Mm2NormalizedAfter() != 332
            || mq4Mm2Remaining() != 0
            || mq4SchemaKeys() != 57
            || mq4InsSites() != 581
            || mq4CommaSites() != 0
            || mq4ZombiePinRepairs() != 3
            || mq4ReorderDefs() != 0
            || mq4PatchEntries() != 589
            || !mq4NormalizerCensusLive()
            || !mq4FullFieldEmission()
            || !mq4FieldOrderCanonical()
            || !mq4NormalizerByteExact()
        )
            ++bad;
        // the batch census - 83 MM2 defs normalized this batch, 332
        // canonical, 0 remaining - the book complete
    if (mq4Round() != 1020
            || mq4DefsNormalized() != 83
            || mq4Mm2Total() != 332
            || mq4Mm2NormalizedAfter() != 332
            || mq4Mm2Remaining() != 0
            || mq4SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 581 anchored inserts, zero whole-line rewrites,
        // 589 file patches
    if (mq4InsSites() != 581
            || mq4CommaSites() != 0
            || mq4ReorderDefs() != 0
            || mq4PatchEntries() != 589
        )
            ++bad;
        // the monster zombie pin repairs - mm2wxyz case 14 hitDiceBonus,
        // avgHp and lairPct, 0 to -1, the full-field sentinel
    if (mq4ZombiePinRepairs() != 3
        )
            ++bad;
        printf("R1020 MM2 normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
