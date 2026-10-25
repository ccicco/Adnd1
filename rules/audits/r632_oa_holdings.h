    // ---- R632 OA holdings audit ----
    // OA round nineteen (capture pp. 67-68): the assigning ancestral holdings
    // prose
    {
        using namespace rules;
        int bad = 0;
    if (!dgsHoldingsAreT39Property()
            || !dgsNpcAutoOwnership()
            || !dgsNeverPcOwnedAtStart()
            || !dgsFirstHoldingToHead()
            || !dgsRemainderDiceAssignment()
            || !dgsPositionMethodUsed()
            || !dgsOverflowToHead()
            || !dgsNoAutomaticPcUse()
            || !dgsOwnerPermissionRequired()
            || !dgsReactionRollStillMade()
            || !dgsDmMayRefuse()
        )
            ++bad;
        // the dgsHoldingsAreT39Property pin
    if (dgsHoldingsAreT39Property() != 1
        )
            ++bad;
        // the dgsNpcAutoOwnership pin
    if (dgsNpcAutoOwnership() != 1
        )
            ++bad;
        // the dgsNeverPcOwnedAtStart pin
    if (dgsNeverPcOwnedAtStart() != 1
        )
            ++bad;
        // the dgsFirstHoldingToHead pin
    if (dgsFirstHoldingToHead() != 1
        )
            ++bad;
        // the dgsRemainderDiceAssignment pin
    if (dgsRemainderDiceAssignment() != 1
        )
            ++bad;
        // the dgsPositionMethodUsed pin
    if (dgsPositionMethodUsed() != 1
        )
            ++bad;
        // the dgsOverflowToHead pin
    if (dgsOverflowToHead() != 1
        )
            ++bad;
        // the dgsNoAutomaticPcUse pin
    if (dgsNoAutomaticPcUse() != 1
        )
            ++bad;
        // the dgsOwnerPermissionRequired pin
    if (dgsOwnerPermissionRequired() != 1
        )
            ++bad;
        // the dgsReactionRollStillMade pin
    if (dgsReactionRollStillMade() != 1
        )
            ++bad;
        // the dgsDmMayRefuse pin
    if (dgsDmMayRefuse() != 1
        )
            ++bad;
        printf("R632 OA holdings audit: bad %d\n", bad);
        if (bad) return 1;
    }
