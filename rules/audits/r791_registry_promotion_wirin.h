    // ---- R791 registry promotion wiring audit ----
    // THE REGISTRY PROMOTION WIRING - the tooling round of the
    // creature-registry promotion (the user-set seam, 2026-10-23). The engine
    // gains spec-declared new-file emission (data_files - idempotent by
    // existence, counted in the applied/already census), so R792 can write
    // all 65 .lua defs in one pass - the MM1 precedent (monsters2lua.py
    // generated all 408 defs from the merged @-record file). The counts ride
    // as pins: OA 39, WSG 18, MOP Appendix III 8, total 65, the registry
    // growing 408 -> 473 live in the battery. The two zero-record adjustments
    // ride as schema fields: the DMO legendary ladder as a rank field, the
    // MOP Appendix II analogue system as a transform field. The pin headers
    // stay the print-fidelity record.
    {
        using namespace rules;
        int bad = 0;
    if (lregPromoteRound() != 791
            || lregEngineExtensionRound() != 791
            || lregDefWriteRound() != 792
            || lregOARecordCount() != 39
            || lregWSGAnimalCount() != 18
            || lregMOPCreatureCount() != 8
            || lregNewDefTotal() != 65
            || lregRegistryCountBefore() != 408
            || lregRegistryCountAfter() != 473
            || lregScionRankCount() != 5
            || !lregDefsAreGeneratedTables()
            || !lregDefsRideRegistryLoader()
            || !lregPinHeadersStayPrintRecord()
            || !lregBatteryCensusGrowsLive()
            || !lregDMOLadderRidesRankField()
            || !lregMOPAnalogueRidesTransformField()
            || !lregWSGAnimalsNeedLoadFields()
            || !lregEngineDataFilesLands()
            || !lregOneRoundCarriesAllDefs()
            || !lregMountFishCheckBeforeCut()
        )
            ++bad;
        // the promotion census walk (the counts, the rounds)
    if (lregPromoteRound() != 791
            || lregEngineExtensionRound() != 791
            || lregDefWriteRound() != 792
            || lregOARecordCount() != 39
            || lregWSGAnimalCount() != 18
            || lregMOPCreatureCount() != 8
            || lregNewDefTotal() != 65
            || lregRegistryCountBefore() != 408
            || lregRegistryCountAfter() != 473
            || lregScionRankCount() != 5
        )
            ++bad;
        // the promotion doctrine walk (the format, the loader, the
        // adjustments)
    if (lregDefsAreGeneratedTables() != 1
            || lregDefsRideRegistryLoader() != 1
            || lregPinHeadersStayPrintRecord() != 1
            || lregBatteryCensusGrowsLive() != 1
            || lregDMOLadderRidesRankField() != 1
            || lregMOPAnalogueRidesTransformField() != 1
            || lregWSGAnimalsNeedLoadFields() != 1
            || lregEngineDataFilesLands() != 1
            || lregOneRoundCarriesAllDefs() != 1
            || lregMountFishCheckBeforeCut() != 1
        )
            ++bad;
        printf("R791 registry promotion wiring audit: bad %d\n", bad);
        if (bad) return 1;
    }
