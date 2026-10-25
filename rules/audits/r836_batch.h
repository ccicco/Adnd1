    // ---- R836 first FF promotion audit ----
    // the first promotion wave of the ff arc: twenty-five defs, the
    // thirty-seven cells, the walk keys re-pinned, the registry and ff def
    // censuses carried; the constants check themselves
    {
        using namespace rules;
        int bad = 0;
    if (ffpRound() != 836
            || ffpDefsPerRound() != 25
            || ffpBatchDefs() != 25
            || ffpAquaDefs() != 13
            || ffpOutDefs() != 12
            || ffpAquaCellsRewired() != 19
            || ffpOutCellsRewired() != 18
            || ffpCellsRewired() != 37
            || ffpAquaWalkKeysBefore() != 192
            || ffpAquaWalkKeysAfter() != 211
            || ffpOutWalkKeysBefore() != 572
            || ffpOutWalkKeysAfter() != 590
            || ffpRegistryBefore() != 812
            || ffpRegistryAfter() != 837
            || ffpFfDefsBefore() != 2
            || ffpFfDefsAfter() != 27
            || !ffpDefsFromFfPrint()
            || !ffpWalkPriorityFirst()
            || !ffpSourceCellsStay()
            || !ffpNoGapBoxesFlip()
        )
            ++bad;
        // the registry carries the batch
    if (ffpRegistryAfter() != ffpRegistryBefore() + ffpBatchDefs()
        )
            ++bad;
        // the ff def census carries the batch
    if (ffpFfDefsAfter() != ffpFfDefsBefore() + ffpBatchDefs()
        )
            ++bad;
        // the aquatic walk keys carry the rewire
    if (ffpAquaWalkKeysAfter() != ffpAquaWalkKeysBefore() +
        ffpAquaCellsRewired()
        )
            ++bad;
        // the outdoor walk keys carry the rewire
    if (ffpOutWalkKeysAfter() != ffpOutWalkKeysBefore() + ffpOutCellsRewired()
        )
            ++bad;
        printf("R836 first FF promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
