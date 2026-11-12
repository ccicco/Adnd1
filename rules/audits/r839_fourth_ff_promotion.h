    // ---- R839 fourth FF promotion audit ----
    // the fourth promotion wave of the ff arc: twenty-five defs, the
    // twenty-four cells (nine ride the standing defs), the dungeon walk-key
    // census re-pinned, the registry and ff def censuses carried, the two
    // keyless FF rows pinned (the Elemental Prince and Hornet Giant rows);
    // the constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (ffuRound() != 839
            || ffuPaceDefs() != 25
            || ffuBatchDefs() != 25
            || ffuDunCellsRewired() != 24
            || ffuNewDefCells() != 15
            || ffuExistingDefCells() != 9
            || ffuDunKeyedBefore() != 146
            || ffuDunKeyedAfter() != 170
            || ffuDunBlankBefore() != 44
            || ffuDunBlankAfter() != 20
            || ffuDunPartyBlankRows() != 10
            || ffuDunMm1BlankCells() != 4
            || ffuDunMm2BlankCells() != 2
            || ffuDunCourtKeylessCells() != 2
            || ffuDunFfRows() != 26
            || ffuDunFfKeyed() != 24
            || ffuDunFfKeylessAfter() != 2
            || ffuDunFfElementalRows() != 1
            || ffuDunFfHornetRows() != 1
            || ffuRegistryBefore() != 887
            || ffuRegistryAfter() != 912
            || ffuFfDefsBefore() != 77
            || ffuFfDefsAfter() != 102
            || !ffuDefsFromFfPrint()
            || !ffuSourceRowsStay()
            || !ffuNoGapBoxesFlip()
            || !ffuDunElementalStaysKeyless()
            || !ffuDunHornetStaysKeyless()
        )
            ++bad;
        // the registry carries the batch
    if (ffuRegistryAfter() != ffuRegistryBefore() + ffuBatchDefs()
        )
            ++bad;
        // the ff def census carries the batch
    if (ffuFfDefsAfter() != ffuFfDefsBefore() + ffuBatchDefs()
        )
            ++bad;
        // the dungeon walk-key census carries the rewire
    if (ffuDunKeyedAfter() != ffuDunKeyedBefore() + ffuDunCellsRewired()
        )
            ++bad;
        // the blank census drains by the rewire
    if (ffuDunBlankAfter() != ffuDunBlankBefore() - ffuDunCellsRewired()
        )
            ++bad;
        // the rewire splits new-def cells and standing-def cells
    if (ffuDunCellsRewired() != ffuNewDefCells() + ffuExistingDefCells()
        )
            ++bad;
        // the ten grids carry 190 rows before and after
    if (ffuDunKeyedBefore() + ffuDunBlankBefore() != ffuDunKeyedAfter() +
        ffuDunBlankAfter()
        )
            ++bad;
        // the FF row census closes over keyed and keyless
    if (ffuDunFfRows() != ffuDunFfKeyed() + ffuDunFfKeylessAfter()
        )
            ++bad;
        // the keyless FF rows split the Elemental Prince and Hornet Giant
        // rows
    if (ffuDunFfKeylessAfter() != ffuDunFfElementalRows() +
        ffuDunFfHornetRows()
        )
            ++bad;
        // the blank residue splits party, MM1, MM2, court and FF keyless
    if (ffuDunBlankAfter() != ffuDunPartyBlankRows() + ffuDunMm1BlankCells() +
        ffuDunMm2BlankCells() + ffuDunCourtKeylessCells() +
        ffuDunFfKeylessAfter()
        )
            ++bad;
        printf("R839 fourth FF promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
