    // ---- R468 WSG where water pin audit ----
    // The standing-water basis and the drought reduction (the flat plain
    // dried out, the swamp always stocked), the water-table depth rules (the
    // foot-or-two low elevation, the swamp table above the terrain, the
    // dozens to hundreds of feet in high elevation), the non-absorbent
    // exception, the dig-for-water chance and the vegetation source (the
    // water-storing plants, the cactus, the DM quantity ruling) - every const
    // and bool verified against the model.
    {
        using namespace rules;
        int bad = 0;
    if (wwfLowElevMinFt() != 1
            || wwfLowElevMaxFt() != 2
            || wwfHighElevMinFt() != 24
            || wwfHighElevMaxFt() != 100
            || !wwfStandingWaterBasis()
            || !wwfDroughtDMReduction()
            || !wwfFlatPlainDriesOut()
            || !wwfSwampAlwaysStanding()
            || !wwfTableIsUndergroundLevel()
            || !wwfSwampTableAboveTerrain()
            || !wwfDesertTableVaries()
            || !wwfTableNonexistentNonabsorbent()
            || !wwfDigChanceAfterSurfaceFail()
            || !wwfDigDepthDMRuling()
            || !wwfVegetationWaterSource()
            || !wwfCactusStoresWater()
            || !wwfDroughtPlantsOnPlainsHills()
            || !wwfPlantQuantityDMRuling()
        )
            ++bad;
        // the low-elevation water table: a foot or two beneath the ground
    if (wwfLowElevMinFt() != 1
            || wwfLowElevMaxFt() != 2
            || wwfLowElevMinFt() >= wwfLowElevMaxFt()
        )
            ++bad;
        // the high-elevation water table: dozens or even hundreds of feet
        // beneath the surface
    if (wwfHighElevMinFt() != 24
            || wwfHighElevMaxFt() != 100
            || wwfHighElevMinFt() >= wwfHighElevMaxFt()
        )
            ++bad;
        // the depth ladder climbs from the low-elevation band to the
        // high-elevation band
    if (wwfLowElevMaxFt() >= wwfHighElevMinFt()
        )
            ++bad;
        // the standing-water basis: not a lake or pond, an uncharted pool or
        // a rain-caught depression
    if (wwfStandingWaterBasis() != 1
        )
            ++bad;
        // the drought contrast: the flat plain dries out, the swamp never
        // does
    if (wwfFlatPlainDriesOut() != 1
            || wwfSwampAlwaysStanding() != 1
            || wwfDroughtDMReduction() != 1
        )
            ++bad;
        // the non-absorbent exception and the dig-for-water chance
    if (wwfTableNonexistentNonabsorbent() != 1
            || wwfDigChanceAfterSurfaceFail() != 1
            || wwfDigDepthDMRuling() != 1
        )
            ++bad;
        // the vegetation source: the water-storing plants, the cactus and the
        // DM quantity ruling
    if (wwfVegetationWaterSource() != 1
            || wwfCactusStoresWater() != 1
            || wwfDroughtPlantsOnPlainsHills() != 1
            || wwfPlantQuantityDMRuling() != 1
        )
            ++bad;
        // the swamp anomaly: the water table above the terrain, near sea
        // level
    if (wwfSwampTableAboveTerrain() != 1
        )
            ++bad;
        printf("R468 WSG where water pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
