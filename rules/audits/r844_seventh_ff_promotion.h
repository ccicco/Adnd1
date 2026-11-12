    // ---- R844 seventh FF promotion audit ----
    // THE SEVENTH FF PROMOTION BATCH - twenty-five of the thirty-two missing
    // FF print stat-blocks promoted: the lamia noble, the lizard king, the
    // magnesium spirit, the mantari, the lava, smoke and steam mephits (three
    // defs), the mite, the necrophidius, the needleman, the nilbog, the
    // nonafel, the pernicon, the phantom stalker, the protein polymorph, the
    // qullan, the retriever, the blue slaad, Ssendam, Ygorl, the giant troll,
    // the giant two-headed troll, the spirit troll, the trilloch and the
    // umpleby; the registry 963 -> 988, the ff def census 153 -> 178, the
    // missing print census 32 -> 7; the constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (fflRound() != 844
            || fflDefsPerRound() != 25
            || fflBatchDefs() != 25
            || fflMephitDefs() != 3
            || fflTrollDefs() != 3
            || fflSlaadLordDefs() != 2
            || fflHoldoutDefs() != 17
            || fflFirstPage() != 59
            || fflLastPage() != 92
            || fflRegistryBefore() != 963
            || fflRegistryAfter() != 988
            || fflFfDefsBefore() != 153
            || fflFfDefsAfter() != 178
            || fflPrintStatBlocks() != 185
            || fflPrintSaved() != 178
            || fflPrintMissingBefore() != 32
            || fflPrintMissingAfter() != 7
            || !fflDefsFromFfPrint()
            || !fflThreeVoiceRead()
            || !fflVariantDefsSplit()
            || !fflMagicResistanceRowBlank()
            || !fflTreasureTypeZero()
            || !fflSourceRowsStay()
            || !fflNoGapBoxesFlip()
        )
            ++bad;
        // the registry carries the batch
    if (fflRegistryAfter() != fflRegistryBefore() + fflBatchDefs()
        )
            ++bad;
        // the ff def census carries the batch
    if (fflFfDefsAfter() != fflFfDefsBefore() + fflBatchDefs()
        )
            ++bad;
        // the missing print census drains by the batch
    if (fflPrintMissingAfter() != fflPrintMissingBefore() - fflBatchDefs()
        )
            ++bad;
        // the batch splits into mephit, troll, slaad lord and holdout defs
    if (fflBatchDefs() != fflMephitDefs() + fflTrollDefs() +
        fflSlaadLordDefs() + fflHoldoutDefs()
        )
            ++bad;
        // the print stat-block census closes over saved and missing
    if (fflPrintStatBlocks() != fflPrintSaved() + fflPrintMissingAfter()
        )
            ++bad;
        // every saved print stat-block is an ff def
    if (fflPrintSaved() != fflFfDefsAfter()
        )
            ++bad;
        // the batch page span runs print page 59 through 92
    if (fflLastPage() - fflFirstPage() != 33
        )
            ++bad;
        printf("R844 seventh FF promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
