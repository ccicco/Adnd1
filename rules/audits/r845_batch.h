    // ---- R845 eighth FF promotion audit ----
    // THE EIGHTH FF PROMOTION BATCH - the last seven of the missing FF print
    // stat-blocks promoted: the yellow urchin, the vision, the whipweed, the
    // witherstench, the xill, the yellow musk creeper and the yellow musk
    // zombie; the registry 988 -> 995, the ff def census 178 -> 185, the
    // missing print census 7 -> 0 (the FF print walk is closed - all 185
    // print stat-blocks saved); the constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (ffmRound() != 845
            || ffmDefsPerRound() != 25
            || ffmBatchDefs() != 7
            || ffmMuskPairDefs() != 2
            || ffmUrchinDefs() != 1
            || ffmHoldoutDefs() != 4
            || ffmFirstPage() != 92
            || ffmLastPage() != 97
            || ffmRegistryBefore() != 988
            || ffmRegistryAfter() != 995
            || ffmFfDefsBefore() != 178
            || ffmFfDefsAfter() != 185
            || ffmPrintStatBlocks() != 185
            || ffmPrintSaved() != 185
            || ffmPrintMissingBefore() != 7
            || ffmPrintMissingAfter() != 0
            || !ffmDefsFromFfPrint()
            || !ffmThreeVoiceRead()
            || !ffmShortBatchClosesWalk()
            || !ffmVariantDefsSplit()
            || !ffmSourceRowsStay()
            || !ffmNoGapBoxesFlip()
        )
            ++bad;
        // the registry carries the batch
    if (ffmRegistryAfter() != ffmRegistryBefore() + ffmBatchDefs()
        )
            ++bad;
        // the ff def census carries the batch
    if (ffmFfDefsAfter() != ffmFfDefsBefore() + ffmBatchDefs()
        )
            ++bad;
        // the missing print census drains to zero by the batch
    if (ffmPrintMissingAfter() != ffmPrintMissingBefore() - ffmBatchDefs()
        )
            ++bad;
        // the batch splits into musk pair, urchin and holdout defs
    if (ffmBatchDefs() != ffmMuskPairDefs() + ffmUrchinDefs() +
        ffmHoldoutDefs()
        )
            ++bad;
        // the print stat-block census closes over saved and missing
    if (ffmPrintStatBlocks() != ffmPrintSaved() + ffmPrintMissingAfter()
        )
            ++bad;
        // every saved print stat-block is an ff def (the walk is closed)
    if (ffmPrintSaved() != ffmFfDefsAfter()
        )
            ++bad;
        // the batch page span runs print page 92 through 97
    if (ffmLastPage() - ffmFirstPage() != 5
        )
            ++bad;
        printf("R845 eighth FF promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
