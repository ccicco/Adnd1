    // ---- R1024 WSG+MOP normalization audit ----
    // THE NORMALIZATION TAIL BATCH - the 23 defs (15 WSG service animals, 8
    // MOP outsiders) rewritten to the full-field 57-key emission, byte-exact
    // against the landed normalize_registry.py; the 15 real WSG service role
    // masks preserved byte-identical; every patch an anchored sentinel
    // insert.
    {
        using namespace rules;
        int bad = 0;
    if (wt1Round() != 1024
            || wt1DefsNormalized() != 23
            || wt1WsgDefs() != 15
            || wt1MopDefs() != 8
            || wt1TailNormalizedAfter() != 23
            || wt1TailRemaining() != 0
            || wt1SchemaKeys() != 57
            || wt1InsSites() != 199
            || wt1CommaSites() != 0
            || wt1ReorderDefs() != 0
            || wt1WsgRolesMasks() != 15
            || wt1PatchEntries() != 199
            || !wt1NormalizerCensusLive()
            || !wt1FullFieldEmission()
            || !wt1InsertOnly()
            || !wt1WsgRolesPreserved()
            || !wt1NoClassedDefs()
        )
            ++bad;
        // the batch census - 23 defs normalized this batch (15 WSG, 8 MOP),
        // the tail complete
    if (wt1Round() != 1024
            || wt1DefsNormalized() != 23
            || wt1WsgDefs() != 15
            || wt1MopDefs() != 8
            || wt1TailNormalizedAfter() != 23
            || wt1TailRemaining() != 0
            || wt1SchemaKeys() != 57
        )
            ++bad;
        // the patch anatomy - 199 anchored inserts, 568 inserted lines, zero
        // whole-line rewrites
    if (wt1InsSites() != 199
            || wt1CommaSites() != 0
            || wt1ReorderDefs() != 0
            || wt1PatchEntries() != 199
        )
            ++bad;
        // the tail census carries the batch - 15 WSG plus 8 MOP equals the 23
        // total
    if (wt1WsgDefs() + wt1MopDefs() != wt1DefsNormalized()
        )
            ++bad;
        // every WSG def in the batch carries its real service role mask -
        // none reads the sentinel
    if (wt1WsgRolesMasks() != wt1WsgDefs()
        )
            ++bad;
        printf("R1024 WSG+MOP normalization audit: bad %d\n", bad);
        if (bad) return 1;
    }
