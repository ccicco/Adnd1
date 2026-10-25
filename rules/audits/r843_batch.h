    // ---- R843 sixth FF promotion audit ----
    // THE SIXTH FF PROMOTION BATCH - twenty-five of the fifty-seven missing
    // FF print stat-blocks promoted: the flind, the flumph, the frost man,
    // the galltrit, the garbug black and violet (two defs), the fog giant,
    // the mountain giant, the giant strider, the gibberling, the githzerai,
    // the goldbug, the gorbel, the gorilla bear, the gryph, the guardian
    // daemon, the guardian familiar, the hellcat, the hound of ill omen, the
    // ice lizard, the imorph, the iron cobra, the jaculi, the kamadan and the
    // kuo-toa; the registry 938 -> 963, the ff def census 128 -> 153, the
    // missing print census 57 -> 32; the constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (ffkRound() != 843
            || ffkDefsPerRound() != 25
            || ffkBatchDefs() != 25
            || ffkGarbugDefs() != 2
            || ffkGiantDefs() != 3
            || ffkHoldoutDefs() != 20
            || ffkFirstPage() != 39
            || ffkLastPage() != 59
            || ffkRegistryBefore() != 938
            || ffkRegistryAfter() != 963
            || ffkFfDefsBefore() != 128
            || ffkFfDefsAfter() != 153
            || ffkPrintStatBlocks() != 185
            || ffkPrintSaved() != 153
            || ffkPrintMissingBefore() != 57
            || ffkPrintMissingAfter() != 32
            || !ffkDefsFromFfPrint()
            || !ffkThreeVoiceRead()
            || !ffkVariantDefsSplit()
            || !ffkPsionicRowUnrecovered()
            || !ffkSourceRowsStay()
            || !ffkNoGapBoxesFlip()
        )
            ++bad;
        // the registry carries the batch
    if (ffkRegistryAfter() != ffkRegistryBefore() + ffkBatchDefs()
        )
            ++bad;
        // the ff def census carries the batch
    if (ffkFfDefsAfter() != ffkFfDefsBefore() + ffkBatchDefs()
        )
            ++bad;
        // the missing print census drains by the batch
    if (ffkPrintMissingAfter() != ffkPrintMissingBefore() - ffkBatchDefs()
        )
            ++bad;
        // the batch splits into garbug, giant-kin and holdout defs
    if (ffkBatchDefs() != ffkGarbugDefs() + ffkGiantDefs() + ffkHoldoutDefs()
        )
            ++bad;
        // the print stat-block census closes over saved and missing
    if (ffkPrintStatBlocks() != ffkPrintSaved() + ffkPrintMissingAfter()
        )
            ++bad;
        // every saved print stat-block is an ff def
    if (ffkPrintSaved() != ffkFfDefsAfter()
        )
            ++bad;
        // the batch page span runs print page 39 through 59
    if (ffkLastPage() - ffkFirstPage() != 20
        )
            ++bad;
        printf("R843 sixth FF promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
