    // ---- R469 WSG water in the desert pin audit ----
    // The desert dig (the 40/60 find split, the 5-15 foot depth band, the
    // desert survival proficiency boost to 80%, the two-tries limit), the
    // desert water economy (the rainfall lost quickly, some water staying
    // recoverable) and the permafrost mechanics (the subarctic warm-season
    // condition, the several-inch thaw, the frozen subsoil, the dependable
    // source, the melt-and-pour harvest) - every const and bool verified
    // against the model.
    {
        using namespace rules;
        int bad = 0;
    if (wdsDigFindPct() != 40
            || wdsNoWaterPct() != 60
            || wdsProfFindPct() != 80
            || wdsDepthMinFt() != 5
            || wdsDepthMaxFt() != 15
            || !wdsMostAridTerrain()
            || !wdsRainfallLostQuickly()
            || !wdsSomeWaterStaysRecoverable()
            || !wdsTwoTriesPerDay()
            || !wdsDesertSurvivalProfBoost()
            || !wdsPermafrostSubarcticWarmSeason()
            || !wdsSoilThawsSeveralInches()
            || !wdsPermafrostFrozenSubsoil()
            || !wdsPermafrostDependableSource()
            || !wdsPermafrostHarvestTechnique()
        )
            ++bad;
        // the desert depth band: 5-15 feet (2d6+3) beneath the surface
    if (wdsDepthMinFt() != 5
            || wdsDepthMaxFt() != 15
            || wdsDepthMinFt() >= wdsDepthMaxFt()
        )
            ++bad;
        // the find split: the 40% dig chance and its 60% no-water complement
    if (wdsDigFindPct() != 40
            || wdsNoWaterPct() != 60
            || wdsDigFindPct() + wdsNoWaterPct() != 100
        )
            ++bad;
        // the desert survival proficiency ladder: 80% instead of 40%
    if (wdsProfFindPct() != 80
            || wdsProfFindPct() <= wdsDigFindPct()
        )
            ++bad;
        // the desert water economy: the rainfall lost quickly, some water
        // staying recoverable
    if (wdsMostAridTerrain() != 1
            || wdsRainfallLostQuickly() != 1
            || wdsSomeWaterStaysRecoverable() != 1
        )
            ++bad;
        // the two-tries limit and the proficiency boost
    if (wdsTwoTriesPerDay() != 1
            || wdsDesertSurvivalProfBoost() != 1
        )
            ++bad;
        // the permafrost definition: the subarctic warm season, the
        // several-inch thaw, the frozen subsoil
    if (wdsPermafrostSubarcticWarmSeason() != 1
            || wdsSoilThawsSeveralInches() != 1
            || wdsPermafrostFrozenSubsoil() != 1
        )
            ++bad;
        // the permafrost harvest: the dependable source and the melt-and-pour
        // technique
    if (wdsPermafrostDependableSource() != 1
            || wdsPermafrostHarvestTechnique() != 1
        )
            ++bad;
        printf("R469 WSG water in the desert pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
