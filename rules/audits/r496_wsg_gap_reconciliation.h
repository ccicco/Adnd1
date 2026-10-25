    // ---- R496 WSG gap reconciliation audit ----
    // The WSG gap reconciliation: twenty-four boxes that were already pinned
    // by earlier rounds flip in this same commit. The eleven chapter parents
    // (effects of the environment R427-R431, encumbrance and movement
    // R432-R450, food and water R462-R470, camping R471-R477, medicine
    // R478-R481, vision R482-R485, hazards R486-R487, combat R488-R489,
    // fatigue R489, mounts R490, magic R491). The nine manifest lines (Tables
    // 20-27 and 42, pinned R444-R490). The four movement items (the surface
    // types, the surface conditions and the chance of falling inside
    // wsgclimb.h R435; the movement across special terrain inside
    // wsgvehicle.h and wsgencum.h R434/R432). The report now reads 171 closed
    // and 15 open; the fifteen are the overview prose (pp. 7-10) and the
    // proficiency descriptions (pp. 11-17).
    {
        using namespace rules;
        int bad = 0;
    if (wgrClosedBefore() != 147
            || wgrOpenBefore() != 39
            || wgrFlippedCount() != 24
            || wgrClosedAfter() != 171
            || wgrOpenAfter() != 15
            || wgrCensusBefore() != 420
            || wgrCensusAfter() != 421
            || wgrChapterParents() != 11
            || wgrManifestLines() != 9
            || wgrClimbItems() != 3
            || wgrSpecialTerrainItems() != 1
            || wgrOverviewOpen() != 11
            || wgrProficienciesOpen() != 4
            || !wgrEnvFxParentOk()
            || !wgrEncumMoveParentOk()
            || !wgrFoodWaterParentOk()
            || !wgrCampParentOk()
            || !wgrMedicineParentOk()
            || !wgrVisionParentOk()
            || !wgrHazardsParentOk()
            || !wgrCombatParentOk()
            || !wgrFatigueParentOk()
            || !wgrMountsParentOk()
            || !wgrMagicParentOk()
            || !wgrT20Pinned()
            || !wgrT21Pinned()
            || !wgrT22Pinned()
            || !wgrT23Pinned()
            || !wgrT24Pinned()
            || !wgrT25Pinned()
            || !wgrT26Pinned()
            || !wgrT27Pinned()
            || !wgrT42Pinned()
            || !wgrSurfaceTypesPinned()
            || !wgrSurfaceConditionsPinned()
            || !wgrFallChancePinned()
            || !wgrSpecialTerrainPinned()
        )
            ++bad;
        // the round counts
    if (wgrClosedBefore() != 147
            || wgrOpenBefore() != 39
            || wgrFlippedCount() != 24
            || wgrClosedAfter() != 171
            || wgrOpenAfter() != 15
        )
            ++bad;
        // the census moves by exactly one
    if (wgrCensusBefore() != 420
            || wgrCensusAfter() != 421
        )
            ++bad;
        // the flipped classes sum to the flip count
    if (wgrChapterParents() + wgrManifestLines() + wgrClimbItems() +
        wgrSpecialTerrainItems() != wgrFlippedCount()
        )
            ++bad;
        // the open boxes conserve: 39 open minus 24 flipped is 15
    if (wgrOpenBefore() - wgrFlippedCount() != wgrOpenAfter()
        )
            ++bad;
        // the closed boxes conserve: 147 plus 24 flipped is 171
    if (wgrClosedBefore() + wgrFlippedCount() != wgrClosedAfter()
        )
            ++bad;
        // the open remainder sums to 15
    if (wgrOverviewOpen() + wgrProficienciesOpen() != wgrOpenAfter()
        )
            ++bad;
        // eleven chapter parents and nine manifest lines flip
    if (wgrChapterParents() != 11
            || wgrManifestLines() != 9
        )
            ++bad;
        // three climbing items and one special-terrain item flip
    if (wgrClimbItems() != 3
            || wgrSpecialTerrainItems() != 1
        )
            ++bad;
        // wgrEnvFxParentOk - every child closed before the parent flips
    if (wgrEnvFxParentOk() != 1
        )
            ++bad;
        // wgrEncumMoveParentOk - every child closed before the parent flips
    if (wgrEncumMoveParentOk() != 1
        )
            ++bad;
        // wgrFoodWaterParentOk - every child closed before the parent flips
    if (wgrFoodWaterParentOk() != 1
        )
            ++bad;
        // wgrCampParentOk - every child closed before the parent flips
    if (wgrCampParentOk() != 1
        )
            ++bad;
        // wgrMedicineParentOk - every child closed before the parent flips
    if (wgrMedicineParentOk() != 1
        )
            ++bad;
        // wgrVisionParentOk - every child closed before the parent flips
    if (wgrVisionParentOk() != 1
        )
            ++bad;
        // wgrHazardsParentOk - every child closed before the parent flips
    if (wgrHazardsParentOk() != 1
        )
            ++bad;
        // wgrCombatParentOk - every child closed before the parent flips
    if (wgrCombatParentOk() != 1
        )
            ++bad;
        // wgrFatigueParentOk - every child closed before the parent flips
    if (wgrFatigueParentOk() != 1
        )
            ++bad;
        // wgrMountsParentOk - every child closed before the parent flips
    if (wgrMountsParentOk() != 1
        )
            ++bad;
        // wgrMagicParentOk - every child closed before the parent flips
    if (wgrMagicParentOk() != 1
        )
            ++bad;
        // wgrT20Pinned - the manifest line matches its landed pin
    if (wgrT20Pinned() != 1
        )
            ++bad;
        // wgrT21Pinned - the manifest line matches its landed pin
    if (wgrT21Pinned() != 1
        )
            ++bad;
        // wgrT22Pinned - the manifest line matches its landed pin
    if (wgrT22Pinned() != 1
        )
            ++bad;
        // wgrT23Pinned - the manifest line matches its landed pin
    if (wgrT23Pinned() != 1
        )
            ++bad;
        // wgrT24Pinned - the manifest line matches its landed pin
    if (wgrT24Pinned() != 1
        )
            ++bad;
        // wgrT25Pinned - the manifest line matches its landed pin
    if (wgrT25Pinned() != 1
        )
            ++bad;
        // wgrT26Pinned - the manifest line matches its landed pin
    if (wgrT26Pinned() != 1
        )
            ++bad;
        // wgrT27Pinned - the manifest line matches its landed pin
    if (wgrT27Pinned() != 1
        )
            ++bad;
        // wgrT42Pinned - the manifest line matches its landed pin
    if (wgrT42Pinned() != 1
        )
            ++bad;
        // wgrSurfaceTypesPinned - the item is pinned in an earlier header
    if (wgrSurfaceTypesPinned() != 1
        )
            ++bad;
        // wgrSurfaceConditionsPinned - the item is pinned in an earlier
        // header
    if (wgrSurfaceConditionsPinned() != 1
        )
            ++bad;
        // wgrFallChancePinned - the item is pinned in an earlier header
    if (wgrFallChancePinned() != 1
        )
            ++bad;
        // wgrSpecialTerrainPinned - the item is pinned in an earlier header
    if (wgrSpecialTerrainPinned() != 1
        )
            ++bad;
        printf("R496 WSG gap reconciliation audit: bad %d\n", bad);
        if (bad) return 1;
    }
