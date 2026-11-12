    // ---- R840 hornet promotion audit ----
    // the hornet promotion wave of the ff arc: the one def (the FF p. 52 stat
    // block), the one cell (the die 14 Monster Level IV row), the dungeon
    // walk-key census re-pinned, the registry and ff def censuses carried,
    // the keyless FF census drained to the Elemental Prince row alone; the
    // constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (ffhRound() != 840
            || ffhBatchDefs() != 1
            || ffhDunCellsRewired() != 1
            || ffhDunKeyedBefore() != 170
            || ffhDunKeyedAfter() != 171
            || ffhDunBlankBefore() != 20
            || ffhDunBlankAfter() != 19
            || ffhDunPartyBlankRows() != 10
            || ffhDunMm1BlankCells() != 4
            || ffhDunMm2BlankCells() != 2
            || ffhDunCourtKeylessCells() != 2
            || ffhDunFfRows() != 26
            || ffhDunFfKeyed() != 25
            || ffhDunFfKeylessBefore() != 2
            || ffhDunFfKeylessAfter() != 1
            || ffhDunFfElementalRows() != 1
            || ffhRegistryBefore() != 912
            || ffhRegistryAfter() != 913
            || ffhFfDefsBefore() != 102
            || ffhFfDefsAfter() != 103
            || !ffhDefFromFfPrint()
            || !ffhSourceRowsStay()
            || !ffhNoGapBoxesFlip()
            || !ffhDunElementalStaysKeyless()
        )
            ++bad;
        // the registry carries the def
    if (ffhRegistryAfter() != ffhRegistryBefore() + ffhBatchDefs()
        )
            ++bad;
        // the ff def census carries the def
    if (ffhFfDefsAfter() != ffhFfDefsBefore() + ffhBatchDefs()
        )
            ++bad;
        // the dungeon walk-key census carries the rewire
    if (ffhDunKeyedAfter() != ffhDunKeyedBefore() + ffhDunCellsRewired()
        )
            ++bad;
        // the blank census drains by the rewire
    if (ffhDunBlankAfter() != ffhDunBlankBefore() - ffhDunCellsRewired()
        )
            ++bad;
        // the keyless FF census drains by the rewire
    if (ffhDunFfKeylessAfter() != ffhDunFfKeylessBefore() -
        ffhDunCellsRewired()
        )
            ++bad;
        // the FF row census closes over keyed and keyless
    if (ffhDunFfRows() != ffhDunFfKeyed() + ffhDunFfKeylessAfter()
        )
            ++bad;
        // the keyless FF census is the Elemental Prince row alone
    if (ffhDunFfKeylessAfter() != ffhDunFfElementalRows()
        )
            ++bad;
        // the blank residue splits party, MM1, MM2, court and FF keyless
    if (ffhDunBlankAfter() != ffhDunPartyBlankRows() + ffhDunMm1BlankCells() +
        ffhDunMm2BlankCells() + ffhDunCourtKeylessCells() +
        ffhDunFfKeylessAfter()
        )
            ++bad;
        // the ten grids carry 190 rows before and after
    if (ffhDunKeyedBefore() + ffhDunBlankBefore() != ffhDunKeyedAfter() +
        ffhDunBlankAfter()
        )
            ++bad;
        printf("R840 hornet promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
