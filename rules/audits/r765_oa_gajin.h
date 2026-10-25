    // ---- R765 OA Gajin audit ----
    // OA round one hundred fifty-two (capture p. 304): the gajin doctrine -
    // the outside classes into the insular lands, the carefully controlled
    // trade, the two peculiar traits of the separation, the rude and hostile
    // barbarians known as gajin and not dealt with, single-pass pins per the
    // R679 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dmaStandardClassCount() != 4
            || dmaPeculiarTraitsCount() != 2
            || !dmaOutsideClassesIntroduced()
            || !dmaLandsVeryDifferent()
            || !dmaInsularClosedLands()
            || !dmaTradeInfrequentControlled()
            || !dmaRoutesVanishDanger()
            || !dmaSeparationTraitsResult()
            || !dmaLackOfCuriosity()
            || !dmaHostileBarbariansView()
            || !dmaGajinName()
            || !dmaGajinNotDealtWith()
        )
            ++bad;
        // the classes example
    if (dmaOutsideClassesIntroduced() != 1
            || dmaLandsVeryDifferent() != 1
        )
            ++bad;
        // the insular example
    if (dmaInsularClosedLands() != 1
            || dmaTradeInfrequentControlled() != 1
        )
            ++bad;
        // the routes example
    if (dmaRoutesVanishDanger() != 1
        )
            ++bad;
        // the separation example
    if (dmaStandardClassCount() != 4
            || dmaPeculiarTraitsCount() != 2
            || dmaSeparationTraitsResult() != 1
        )
            ++bad;
        // the curiosity example
    if (dmaLackOfCuriosity() != 1
        )
            ++bad;
        // the gajin example
    if (dmaHostileBarbariansView() != 1
            || dmaGajinName() != 1
            || dmaGajinNotDealtWith() != 1
        )
            ++bad;
        printf("R765 OA Gajin audit: bad %d\n", bad);
        if (bad) return 1;
    }
