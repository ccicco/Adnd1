    // ---- R837 second FF promotion audit ----
    // the second promotion wave of the ff arc: twenty-five defs, the
    // forty-two cells (the Grabman cell rides the standing crabman def), the
    // outdoor walk keys re-pinned, the registry and ff def censuses carried,
    // the keyless census drained to fourteen; the constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (ffsRound() != 837
            || ffsPaceDefs() != 25
            || ffsBatchDefs() != 25
            || ffsOutCellsRewired() != 42
            || ffsNewDefCells() != 41
            || ffsGrabmanCells() != 1
            || ffsAquaCellsRewired() != 0
            || ffsOutWalkKeysBefore() != 590
            || ffsOutWalkKeysAfter() != 632
            || ffsOutFfKeylessBefore() != 56
            || ffsOutFfKeylessAfter() != 14
            || ffsKeyedFfRows() != 18
            || ffsFfSourceRows() != 74
            || ffsRegistryBefore() != 837
            || ffsRegistryAfter() != 862
            || ffsFfDefsBefore() != 27
            || ffsFfDefsAfter() != 52
            || !ffsDefsFromFfPrint()
            || !ffsSourceCellsStay()
            || !ffsNoGapBoxesFlip()
            || !ffsGrabmanIsCrabman()
        )
            ++bad;
        // the registry carries the batch
    if (ffsRegistryAfter() != ffsRegistryBefore() + ffsBatchDefs()
        )
            ++bad;
        // the ff def census carries the batch
    if (ffsFfDefsAfter() != ffsFfDefsBefore() + ffsBatchDefs()
        )
            ++bad;
        // the outdoor walk keys carry the rewire
    if (ffsOutWalkKeysAfter() != ffsOutWalkKeysBefore() + ffsOutCellsRewired()
        )
            ++bad;
        // the keyless census drains by the rewire
    if (ffsOutFfKeylessAfter() != ffsOutFfKeylessBefore() -
        ffsOutCellsRewired()
        )
            ++bad;
        // the FF row census closes over keyed and keyless
    if (ffsFfSourceRows() != ffsOutFfKeylessAfter() + ffsKeyedFfRows() +
        ffsOutCellsRewired()
        )
            ++bad;
        // the rewire splits new-def cells and the Grabman cell
    if (ffsOutCellsRewired() != ffsNewDefCells() + ffsGrabmanCells()
        )
            ++bad;
        printf("R837 second FF promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
