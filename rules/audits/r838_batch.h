    // ---- R838 third FF promotion audit ----
    // the third promotion wave of the ff arc: twenty-five defs, the thirteen
    // cells (the two disenchanter cells ride the standing def), the outdoor
    // walk keys re-pinned, the registry and ff def censuses carried, the
    // keyless census drained to one (the Mountain Giant row stays keyless);
    // the constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (fftRound() != 838
            || fftPaceDefs() != 25
            || fftBatchDefs() != 25
            || fftOutCellsRewired() != 13
            || fftNewDefCells() != 11
            || fftExistingDefCells() != 2
            || fftMountainGiantRows() != 1
            || fftOutWalkKeysBefore() != 632
            || fftOutWalkKeysAfter() != 645
            || fftOutFfKeylessBefore() != 14
            || fftOutFfKeylessAfter() != 1
            || fftKeyedFfRows() != 60
            || fftFfSourceRows() != 74
            || fftRegistryBefore() != 862
            || fftRegistryAfter() != 887
            || fftFfDefsBefore() != 52
            || fftFfDefsAfter() != 77
            || !fftDefsFromFfPrint()
            || !fftSourceCellsStay()
            || !fftNoGapBoxesFlip()
            || !fftMountainGiantStaysKeyless()
        )
            ++bad;
        // the registry carries the batch
    if (fftRegistryAfter() != fftRegistryBefore() + fftBatchDefs()
        )
            ++bad;
        // the ff def census carries the batch
    if (fftFfDefsAfter() != fftFfDefsBefore() + fftBatchDefs()
        )
            ++bad;
        // the outdoor walk keys carry the rewire
    if (fftOutWalkKeysAfter() != fftOutWalkKeysBefore() + fftOutCellsRewired()
        )
            ++bad;
        // the keyless census drains by the rewire
    if (fftOutFfKeylessAfter() != fftOutFfKeylessBefore() -
        fftOutCellsRewired()
        )
            ++bad;
        // the FF row census closes over keyed and keyless
    if (fftFfSourceRows() != fftOutFfKeylessAfter() + fftKeyedFfRows() +
        fftOutCellsRewired()
        )
            ++bad;
        // the rewire splits new-def cells and standing-def cells
    if (fftOutCellsRewired() != fftNewDefCells() + fftExistingDefCells()
        )
            ++bad;
        printf("R838 third FF promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
