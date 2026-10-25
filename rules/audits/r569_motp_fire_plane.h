    // ---- R569 MotP Fire plane audit ----
    // the Plane of Elemental Fire, printed pp. 36-41, the whole chapter: the
    // hellish-plane doctrine with the four border gradations (Smoke, Magma,
    // Radiance, Ash), the survival ladder (the breath-save-or-die with 4d10
    // per round survivors, the melting metal, the boiling fluids, the thin
    // hot atmosphere with cloudkill effects), the 120-foot vision, the
    // 1-in-10-per-eight-hours check, the d12 phenomena (hot spots with their
    // native healing, cold spots, the 2,000-yard eruption, the explosion
    // field), the d20 pocket table (the purest plane), the d8+d12 encounter
    // chart, the native cold/water vulnerabilities (the 100-degree threshold,
    // 1d6 per quart), the magic rule, and the features (Imix the paranoid
    // archoment, Kossuth the tyrant-king, the efreet City of Brass, the azer
    // towers of Amaimon, and the spiraling-flame artifact).
    {
        using namespace rules;
        int bad = 0;
    if (dcxFireEncounterDenom() != 10
            || dcxFirePhenomenaDieSides() != 12
            || dcxFirePocketTableDie() != 20
            || dcxFireChartDieSides() != 12
            || dcxFireHeatDamageRounds() != 10
            || dcxFireVisionFeet() != 120
            || dcxFireNativeColdDamageDie() != 2
            || dcxFireCityMiles() != 40
            || !dcxFireBordersGrade()
            || !dcxFireHotSpotHeal()
            || !dcxFireEruptionRange()
            || !dcxFireMagicElementRule()
            || !dcxFireSpiralFlame()
        )
            ++bad;
        // the FireEncounterDenom pin
    if (dcxFireEncounterDenom() != 10
        )
            ++bad;
        // the FirePhenomenaDieSides pin
    if (dcxFirePhenomenaDieSides() != 12
        )
            ++bad;
        // the FirePocketTableDie pin
    if (dcxFirePocketTableDie() != 20
        )
            ++bad;
        // the FireChartDieSides pin
    if (dcxFireChartDieSides() != 12
        )
            ++bad;
        // the FireHeatDamageRounds pin
    if (dcxFireHeatDamageRounds() != 10
        )
            ++bad;
        // the FireVisionFeet pin
    if (dcxFireVisionFeet() != 120
        )
            ++bad;
        // the FireNativeColdDamageDie pin
    if (dcxFireNativeColdDamageDie() != 2
        )
            ++bad;
        // the FireCityMiles pin
    if (dcxFireCityMiles() != 40
        )
            ++bad;
        // the FireBordersGrade pin
    if (dcxFireBordersGrade() != 1
        )
            ++bad;
        // the FireHotSpotHeal pin
    if (dcxFireHotSpotHeal() != 1
        )
            ++bad;
        // the FireEruptionRange pin
    if (dcxFireEruptionRange() != 1
        )
            ++bad;
        // the FireMagicElementRule pin
    if (dcxFireMagicElementRule() != 1
        )
            ++bad;
        // the FireSpiralFlame pin
    if (dcxFireSpiralFlame() != 1
        )
            ++bad;
        printf("R569 MotP Fire plane audit: bad %d\n", bad);
        if (bad) return 1;
    }
