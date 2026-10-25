    // ---- R571 MotP Water plane audit ----
    // the Plane of Elemental Water, printed pp. 46-51, the whole chapter,
    // closing the four majors: the ocean-without-a-surface doctrine with the
    // four border gradations (Ooze, Ice, Steam, Salt), the 1/3-Con
    // breath-holding rule, the 60-foot vision, the doubled swim rate, the
    // 1-in-10-per-four-hours check, the d12 phenomena, the d20 pocket table
    // with the mineral sub-table and the airy-water rule for the rare fire
    // and magma pockets, the d8+d12 encounter chart, the native fire
    // double-damage vulnerability, the underwater combat rules, the magic
    // rule, and the features (Istishia the Greater Power, the marid empire).
    {
        using namespace rules;
        int bad = 0;
    if (dczWaterBreathDivisor() != 3
            || dczWaterVisionFeet() != 60
            || dczWaterEncounterDenom() != 10
            || dczWaterPhenomenaDieSides() != 12
            || dczWaterPocketTableDie() != 20
            || dczWaterChartDieSides() != 12
            || dczWaterNativeFireDouble() != 2
            || !dczWaterOceanDoctrine()
            || !dczWaterBordersGrade()
            || !dczWaterSwimDouble()
            || !dczWaterCombatRules()
            || !dczWaterMagicRule()
            || !dczWaterMaridHousehold()
        )
            ++bad;
        // the WaterBreathDivisor pin
    if (dczWaterBreathDivisor() != 3
        )
            ++bad;
        // the WaterVisionFeet pin
    if (dczWaterVisionFeet() != 60
        )
            ++bad;
        // the WaterEncounterDenom pin
    if (dczWaterEncounterDenom() != 10
        )
            ++bad;
        // the WaterPhenomenaDieSides pin
    if (dczWaterPhenomenaDieSides() != 12
        )
            ++bad;
        // the WaterPocketTableDie pin
    if (dczWaterPocketTableDie() != 20
        )
            ++bad;
        // the WaterChartDieSides pin
    if (dczWaterChartDieSides() != 12
        )
            ++bad;
        // the WaterNativeFireDouble pin
    if (dczWaterNativeFireDouble() != 2
        )
            ++bad;
        // the WaterOceanDoctrine pin
    if (dczWaterOceanDoctrine() != 1
        )
            ++bad;
        // the WaterBordersGrade pin
    if (dczWaterBordersGrade() != 1
        )
            ++bad;
        // the WaterSwimDouble pin
    if (dczWaterSwimDouble() != 1
        )
            ++bad;
        // the WaterCombatRules pin
    if (dczWaterCombatRules() != 1
        )
            ++bad;
        // the WaterMagicRule pin
    if (dczWaterMagicRule() != 1
        )
            ++bad;
        // the WaterMaridHousehold pin
    if (dczWaterMaridHousehold() != 1
        )
            ++bad;
        printf("R571 MotP Water plane audit: bad %d\n", bad);
        if (bad) return 1;
    }
