    // ---- R793 registry promotion def name fix audit ----
    // THE REGISTRY PROMOTION DEF NAME FIX - the R792 review lesson (the user
    // call: monster .lua keys cannot carry book prefixes). The 18 wsg_ keys
    // go bare: 15 new bare-key defs land through data_files (bear through
    // yak), and the three MM1 collisions (ape, mule, pony) keep their single
    // existing defs with the WSG Table 13 rows riding as field patches (the
    // single-def-per-creature rule). MonsterDef gains the wsgRoles service
    // mask (1 normal, 2 mount, 4 pack - the roles derived from the wsgmount.h
    // catalog pins), read through the existing coercers. The stale untracked
    // wsg_ keys leave the tree by the pre-cut git clean; the registry reads
    // 481 -> 478 live, superseding the prg 481 pin. Audit R793 registry
    // promotion def name fix audit, header rules/prf.h, prefix prf.
    {
        using namespace rules;
        int bad = 0;
    if (prfNameFixRound() != 793
            || prfWSGRowCount() != 18
            || prfBareKeyDefCount() != 15
            || prfFieldRideDefCount() != 3
            || prfDataFileCount() != 70
            || prfRegistryDefTotal() != 478
            || prfRoleMaskNormal() != 1
            || prfRoleMaskMount() != 2
            || prfRoleMaskPack() != 4
            || prfMountRoleRowCount() != 13
            || prfPackRoleRowCount() != 15
            || prfSchemaFieldCount() != 6
            || !prfBareMonsterKeysOnly()
            || !prfSingleDefPerCreature()
            || !prfRolesRideWsgRolesMask()
            || !prfRolesDerivedFromCatalog()
            || !prfPrgRegistryPinSuperseded()
            || !prfStaleUntrackedKeysRemoved()
            || !prfDefsAreGeneratedTables()
            || !prfDefsRideRegistryLoader()
            || !prfPinHeadersStayPrintRecord()
            || !prfBatteryCensusGrowsLive()
            || !prfWildHorseNormalOnly()
            || !prfElephantsRideTrainedOnly()
        )
            ++bad;
        // the name fix census walk (the bare-key counts)
    if (prfNameFixRound() != 793
            || prfWSGRowCount() != 18
            || prfBareKeyDefCount() != 15
            || prfFieldRideDefCount() != 3
            || prfDataFileCount() != 70
            || prfRegistryDefTotal() != 478
            || prfRoleMaskNormal() != 1
            || prfRoleMaskMount() != 2
            || prfRoleMaskPack() != 4
            || prfMountRoleRowCount() != 13
            || prfPackRoleRowCount() != 15
            || prfSchemaFieldCount() != 6
        )
            ++bad;
        // the name fix doctrine bools
    if (prfBareMonsterKeysOnly() != 1
            || prfSingleDefPerCreature() != 1
            || prfRolesRideWsgRolesMask() != 1
            || prfRolesDerivedFromCatalog() != 1
            || prfPrgRegistryPinSuperseded() != 1
            || prfStaleUntrackedKeysRemoved() != 1
            || prfDefsAreGeneratedTables() != 1
            || prfDefsRideRegistryLoader() != 1
            || prfPinHeadersStayPrintRecord() != 1
            || prfBatteryCensusGrowsLive() != 1
            || prfWildHorseNormalOnly() != 1
            || prfElephantsRideTrainedOnly() != 1
        )
            ++bad;
        printf("R793 registry promotion def name fix audit: bad %d\n", bad);
        if (bad) return 1;
    }
