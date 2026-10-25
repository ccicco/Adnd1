    // ---- R734 OA random treasure prose audit ----
    // OA round one hundred twenty-one (capture p. 285): the Chapter 13 Random
    // Treasure Determination prose - the DMG procedure carried over whole,
    // the Table 74 exception with the use-the-versions-here rule, the
    // additional Table 86 Oriental Magical Items, the Table II.A. (ORIENT)
    // and Table III (ORIENT) replacements of the DMG pages 120 and 121,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkvExceptedTable74() != 74
            || dkvOrientalItemsTable86() != 86
            || dkvDMGPageTableIIA() != 120
            || dkvDMGPageTableIII() != 121
            || !dkvDMGProcedureUsed()
            || !dkvTable74TheException()
            || !dkvUseVersionsGivenHere()
            || !dkvAdditionalTable86()
            || !dkvIIAOrientReplacesDMG()
            || !dkvIIIOrientReplacesDMG()
            || !dkvReplacementsInOAWorld()
        )
            ++bad;
        // the prose - the Random Treasure Determination paragraph, healthy
        // values, each condition false
    if (dkvDMGProcedureUsed() != 1
            || dkvTable74TheException() != 1
            || dkvUseVersionsGivenHere() != 1
            || dkvAdditionalTable86() != 1
            || dkvIIAOrientReplacesDMG() != 1
            || dkvIIIOrientReplacesDMG() != 1
            || dkvReplacementsInOAWorld() != 1
        )
            ++bad;
        // the table numbers and the DMG pages, healthy values, each condition
        // false
    if (dkvExceptedTable74() != 74
            || dkvOrientalItemsTable86() != 86
            || dkvDMGPageTableIIA() != 120
            || dkvDMGPageTableIII() != 121
        )
            ++bad;
        printf("R734 OA random treasure prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
