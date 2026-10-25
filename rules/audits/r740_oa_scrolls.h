    // ---- R740 OA scrolls audit ----
    // OA round one hundred twenty-seven (capture p. 288): the Scrolls section
    // - the DMG standard type rules with the wu jen and shukenja mappings,
    // the 5% gajin-spell scrolls and their usability, the three protection
    // scroll notes, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlbGajinScrollPct() != 5
            || !dlbUseStandardDMGRules()
            || !dlbMagicUsersAsWuJen()
            || !dlbClericsAsShukenja()
            || !dlbGajinSpellsFivePct()
            || !dlbGajinUsedByWuJenShukenja()
            || !dlbGajinAddedToSpellBooks()
            || !dlbProtectionFromDevilsRerolled()
            || !dlbProtectionFromShapechangersScope()
            || !dlbProtectionFromUndeadRerolled()
        )
            ++bad;
        // the scroll determination and the gajin spells, healthy values, each
        // condition false
    if (dlbUseStandardDMGRules() != 1
            || dlbMagicUsersAsWuJen() != 1
            || dlbClericsAsShukenja() != 1
            || dlbGajinSpellsFivePct() != 1
            || dlbGajinUsedByWuJenShukenja() != 1
            || dlbGajinAddedToSpellBooks() != 1
            || dlbGajinScrollPct() != 5
        )
            ++bad;
        // the three protection scroll notes, healthy values, each condition
        // false
    if (dlbProtectionFromDevilsRerolled() != 1
            || dlbProtectionFromShapechangersScope() != 1
            || dlbProtectionFromUndeadRerolled() != 1
        )
            ++bad;
        printf("R740 OA scrolls audit: bad %d\n", bad);
        if (bad) return 1;
    }
