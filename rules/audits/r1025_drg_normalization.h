    // ---- R1025 DRG normalization audit ----
    // THE REGISTRY CLOSES - the five Dragon magazine defs (death angel,
    // mihalli, prowler, qu'uni, vriyagga) rewritten to the full-field 57-key
    // emission, byte-exact against the landed normalize_registry.py, the
    // registry 1338 of 1338 canonical; thirty anchored sentinel inserts and
    // the first five comma-site whole-line rewrites of the arc (the DRG text
    // fields lacked the Lua-optional trailing comma).
    {
        using namespace rules;
        int bad = 0;
    if (dq1Round() != 1025
            || dq1DefsNormalized() != 5
            || dq1DrgTotal() != 5
            || dq1DrgNormalizedAfter() != 5
            || dq1DrgRemaining() != 0
            || dq1RegistryTotal() != 1338
            || dq1RegistryCanonicalAfter() != 1338
            || dq1SchemaKeys() != 57
            || dq1InsSites() != 30
            || dq1CommaSites() != 5
            || dq1ReorderDefs() != 0
            || dq1PatchEntries() != 35
            || !dq1NormalizerCensusLive()
            || !dq1FullFieldEmission()
            || !dq1RegistryComplete()
            || !dq1NoClassedDefs()
        )
            ++bad;
        // the example
    if (dq1Round() != 1025
            || dq1DefsNormalized() != 5
            || dq1DrgTotal() != 5
            || dq1DrgNormalizedAfter() != 5
            || dq1DrgRemaining() != 0
            || dq1SchemaKeys() != 57
        )
            ++bad;
        // the example
    if (dq1InsSites() != 30
            || dq1CommaSites() != 5
            || dq1ReorderDefs() != 0
            || dq1PatchEntries() != 35
        )
            ++bad;
        // the example
    if (dq1DrgNormalizedAfter() + dq1DrgRemaining() != dq1DrgTotal()
        )
            ++bad;
        // the example
    if (dq1RegistryCanonicalAfter() != dq1RegistryTotal()
        )
            ++bad;
        printf("R1025 DRG normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
