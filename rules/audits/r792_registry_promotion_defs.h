    // ---- R792 registry promotion defs audit ----
    // THE REGISTRY PROMOTION DEFS - the all-in-one R792 def write (the
    // user-set seam). 73 new .lua defs land in one pass through the R791
    // data_files extension - the MM1 precedent (monsters2lua.py generated all
    // 408 defs from the merged @-record file). OA Chapter 12 gives 47 defs
    // (the corrected census - the kappa pair, the kala pair, the nat trio and
    // the oa91 trio ride; the ikiryo carries sentinel nil stats, the user
    // call), WSG Table 13 gives 18 (loads and movement only, the combat
    // fields riding the documented loader defaults), MOP Appendix III gives 8
    // (the stat blocks printed exactly as pinned). The loader gains the five
    // schema fields (loadNormal, loadMax, rank, plane, transform) and the
    // regtest xp audit gains the three print sources. The battery census
    // grows live: loaded 408 -> 481.
    {
        using namespace rules;
        int bad = 0;
    if (prgPromoteRound() != 792
            || prgOADefCount() != 47
            || prgWSGAnimalCount() != 18
            || prgMOPCreatureCount() != 8
            || prgNewDefTotal() != 73
            || prgRegistryCountBefore() != 408
            || prgRegistryCountAfter() != 481
            || prgSchemaFieldCount() != 5
            || prgPrintSourceCount() != 3
            || prgDataFileCount() != 73
            || prgLoaderFieldPatchCount() != 2
            || prgXpAuditPatchCount() != 1
            || prgSentinelDefCount() != 3
            || !prgDefsAreGeneratedTables()
            || !prgDefsRideRegistryLoader()
            || !prgPinHeadersStayPrintRecord()
            || !prgBatteryCensusGrowsLive()
            || !prgOACensusCorrected()
            || !prgIkiryoIncludedWithSentinels()
            || !prgWSGCombatFieldsRideDefaults()
            || !prgMOPStatBlocksFromPrint()
            || !prgDMOLadderRidesRankField()
            || !prgMOPAnalogueRidesTransformField()
            || !prgWSGAnimalsNeedLoadFields()
            || !prgNewPrintSourcesRideAudit()
            || !prgOneRoundCarriesAllDefs()
            || !prgRankDefaultsZero()
        )
            ++bad;
        // the promotion def census walk (the corrected counts)
    if (prgPromoteRound() != 792
            || prgOADefCount() != 47
            || prgWSGAnimalCount() != 18
            || prgMOPCreatureCount() != 8
            || prgNewDefTotal() != 73
            || prgRegistryCountBefore() != 408
            || prgRegistryCountAfter() != 481
            || prgSchemaFieldCount() != 5
            || prgPrintSourceCount() != 3
            || prgDataFileCount() != 73
            || prgLoaderFieldPatchCount() != 2
            || prgXpAuditPatchCount() != 1
            || prgSentinelDefCount() != 3
        )
            ++bad;
        // the promotion def doctrine bools
    if (prgDefsAreGeneratedTables() != 1
            || prgDefsRideRegistryLoader() != 1
            || prgPinHeadersStayPrintRecord() != 1
            || prgBatteryCensusGrowsLive() != 1
            || prgOACensusCorrected() != 1
            || prgIkiryoIncludedWithSentinels() != 1
            || prgWSGCombatFieldsRideDefaults() != 1
            || prgMOPStatBlocksFromPrint() != 1
            || prgDMOLadderRidesRankField() != 1
            || prgMOPAnalogueRidesTransformField() != 1
            || prgWSGAnimalsNeedLoadFields() != 1
            || prgNewPrintSourcesRideAudit() != 1
            || prgOneRoundCarriesAllDefs() != 1
            || prgRankDefaultsZero() != 1
        )
            ++bad;
        printf("R792 registry promotion defs audit: bad %d\n", bad);
        if (bad) return 1;
    }
