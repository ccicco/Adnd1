    // ---- R842 fifth FF promotion audit ----
    // THE FIFTH FF PROMOTION BATCH - twenty-five of the eighty-two missing FF
    // print stat-blocks promoted: the three lung dragons (the pan, tien and
    // yu lungs), the five elemental princes of evil (cryonax, imix, ogremoch,
    // olhydra and yan-c-bin), the seventeen holdouts from the giant bloodworm
    // to the flail snail; the registry 913 -> 938, the ff def census 103 ->
    // 128, the missing print census 82 -> 57; the constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (ffjRound() != 842
            || ffjDefsPerRound() != 25
            || ffjBatchDefs() != 25
            || ffjLungDefs() != 3
            || ffjPrinceDefs() != 5
            || ffjHoldoutDefs() != 17
            || ffjFirstPage() != 15
            || ffjLastPage() != 38
            || ffjRegistryBefore() != 913
            || ffjRegistryAfter() != 938
            || ffjFfDefsBefore() != 103
            || ffjFfDefsAfter() != 128
            || ffjPrintStatBlocks() != 185
            || ffjPrintSaved() != 128
            || ffjPrintMissingBefore() != 82
            || ffjPrintMissingAfter() != 57
            || !ffjDefsFromFfPrint()
            || !ffjThreeVoiceRead()
            || !ffjShreddedRowsRecovered()
            || !ffjSourceRowsStay()
            || !ffjNoGapBoxesFlip()
        )
            ++bad;
        // the registry carries the batch
    if (ffjRegistryAfter() != ffjRegistryBefore() + ffjBatchDefs()
        )
            ++bad;
        // the ff def census carries the batch
    if (ffjFfDefsAfter() != ffjFfDefsBefore() + ffjBatchDefs()
        )
            ++bad;
        // the missing print census drains by the batch
    if (ffjPrintMissingAfter() != ffjPrintMissingBefore() - ffjBatchDefs()
        )
            ++bad;
        // the batch splits into lung, prince and holdout defs
    if (ffjBatchDefs() != ffjLungDefs() + ffjPrinceDefs() + ffjHoldoutDefs()
        )
            ++bad;
        // the print stat-block census closes over saved and missing
    if (ffjPrintStatBlocks() != ffjPrintSaved() + ffjPrintMissingAfter()
        )
            ++bad;
        // every saved print stat-block is an ff def
    if (ffjPrintSaved() != ffjFfDefsAfter()
        )
            ++bad;
        // the batch page span runs print page 15 through 38
    if (ffjLastPage() - ffjFirstPage() != 23
        )
            ++bad;
        printf("R842 fifth FF promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
