    // ---- R572 MotP para-planes audit ----
    // the Para-Elemental Planes, printed pp. 51-54, the four in one round:
    // Smoke, Magma, Ooze and Ice - the minor-plane doctrine, the per-plane
    // survival (asphyxiation, heat-as-Fire, drowning-as-Water, the
    // 1d6-per-round ice cold reduced to per turn when protected), the vision
    // ladder (30 yards / touch / 10-20), the 1-in-20-per-eight-true-hours
    // check, the 50/50 pocket rule with lair chances, the native immunity
    // doctrine, the movement/combat/magic mappings to the majors, the d8+d12
    // encounter chart, and the features (the guide-bribe doubling, the
    // Demi-Power archoments without Greater Powers - Cryonax, Ehkahk,
    // Chlimbia, Bwimb - and no native genies).
    {
        using namespace rules;
        int bad = 0;
    if (ddaParaPlaneCount() != 4
            || ddaParaEncounterDenom() != 20
            || ddaParaSmokeVisionYards() != 30
            || ddaParaIceColdDieSides() != 6
            || ddaParaPocketSplitPct() != 50
            || ddaParaChartDieSides() != 12
            || ddaParaGuideFightPct() != 50
            || !ddaParaSurvivalSmoke()
            || !ddaParaSurvivalMagmaOoze()
            || !ddaParaNativeImmunity()
            || !ddaParaMovementMap()
            || !ddaParaMagicMap()
            || !ddaParaArchomentRule()
        )
            ++bad;
        // the ParaPlaneCount pin
    if (ddaParaPlaneCount() != 4
        )
            ++bad;
        // the ParaEncounterDenom pin
    if (ddaParaEncounterDenom() != 20
        )
            ++bad;
        // the ParaSmokeVisionYards pin
    if (ddaParaSmokeVisionYards() != 30
        )
            ++bad;
        // the ParaIceColdDieSides pin
    if (ddaParaIceColdDieSides() != 6
        )
            ++bad;
        // the ParaPocketSplitPct pin
    if (ddaParaPocketSplitPct() != 50
        )
            ++bad;
        // the ParaChartDieSides pin
    if (ddaParaChartDieSides() != 12
        )
            ++bad;
        // the ParaGuideFightPct pin
    if (ddaParaGuideFightPct() != 50
        )
            ++bad;
        // the ParaSurvivalSmoke pin
    if (ddaParaSurvivalSmoke() != 1
        )
            ++bad;
        // the ParaSurvivalMagmaOoze pin
    if (ddaParaSurvivalMagmaOoze() != 1
        )
            ++bad;
        // the ParaNativeImmunity pin
    if (ddaParaNativeImmunity() != 1
        )
            ++bad;
        // the ParaMovementMap pin
    if (ddaParaMovementMap() != 1
        )
            ++bad;
        // the ParaMagicMap pin
    if (ddaParaMagicMap() != 1
        )
            ++bad;
        // the ParaArchomentRule pin
    if (ddaParaArchomentRule() != 1
        )
            ++bad;
        printf("R572 MotP para-planes audit: bad %d\n", bad);
        if (bad) return 1;
    }
