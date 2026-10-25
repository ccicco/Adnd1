    // ---- R502 WSG camp chain fold audit ----
    // The WSG camp-chain fold, the fourth seam round after gap closure: no
    // new book pages, the R499 pattern applied to the camp chapter. One
    // campsite flows through six landed headers: the rest quality and Table
    // 38 fire (rules/wsgfire.h R474: the three fire sizes, the fuel ladder 6,
    // 12, 18 turns for an eight-hour burn, the refuel ladder 3, 6, 9, the
    // wind resistance 20, 30, 40, the rest penalties 1, 1, 2, 2, 3, 3, 4
    // hours, the plate economy 5-to-1 and 9-to-5), the fire starting and fuel
    // rules (rules/wsgfuel.h R475: the 15 mph breeze bar, the 30 mph no-start
    // maximum, the 2d20/3d20 start dice, the 3-turn small-fire grace, the
    // capacity doubling 6 at 10 feet to 12 at 20), the wildfire rules
    // (rules/wsgblaze.h R476: the spark carry 10, 20, 30 feet plus one foot
    // per mph of wind, the growth ladder 1, 2, 4 turns, the 6-turn
    // uncontrollable bar, the halving divisor), the tent quality system
    // (rules/wsgsleep.h R473: the pole ladder 2, 4, 6, the 10 mph leak step
    // with the 5 mph leak, the 25 percent damage chance), the natural
    // shelters (rules/wsgshelter.h R471: the 3-turn material floor, the
    // 6-turn lash) and the R499 temperature chain re-read for the seam. The
    // findings: the uncontrollable bar of 6 turns is exactly one hour; the
    // small-fire refuel interval and the grace period are the same 3 turns in
    // two headers; the 20 mph wind value appears in three headers; the
    // no-start maximum equals the medium fire wind resistance; the growth
    // ladder is the only geometric ladder; the rest cold threshold is the
    // R499 below-0 boundary and the rest hot threshold of 90 opens one degree
    // past the protected no-damage top of 89; and the plate economy loses a
    // flat 4 hours either way.
    {
        using namespace rules;
        int bad = 0;
    if (wmcFireSizes() != 3
            || wmcBurnHours() != 8
            || wmcFuelSmall() != 6
            || wmcFuelMedium() != 12
            || wmcFuelLarge() != 18
            || wmcRefuelSmall() != 3
            || wmcRefuelMedium() != 6
            || wmcRefuelLarge() != 9
            || wmcWindResSmall() != 20
            || wmcWindResMedium() != 30
            || wmcWindResLarge() != 40
            || wmcSparkSmall() != 10
            || wmcSparkMedium() != 20
            || wmcSparkLarge() != 30
            || wmcGrowthSmall() != 1
            || wmcGrowthMedium() != 2
            || wmcGrowthLarge() != 4
            || wmcUncontrollableTurns() != 6
            || wmcTurnsPerHour() != 6
            || wmcRoundsPerTurn() != 10
            || wmcSparkWindFtPerMph() != 1
            || wmcHalveDivisor() != 2
            || wmcStartBreezeMax() != 15
            || wmcNoStartWindMax() != 30
            || wmcStartDice() != 2
            || wmcHardStartDice() != 3
            || wmcSmallRefuelGrace() != 3
            || wmcCapBaseFeet() != 10
            || wmcCapSmallAt10() != 6
            || wmcCapSmallAt20() != 12
            || wmcPenTempBelow0() != 1
            || wmcPenTempAbove90() != 2
            || wmcPenWind() != 2
            || wmcPenPrecip() != 3
            || wmcPenMetal() != 3
            || wmcPenPlate() != 4
            || wmcRestColdBound() != 0
            || wmcRestHotBound() != 90
            || wmcR499ProtTop() != 89
            || wmcPlateNight() != 5
            || wmcPlateGoodRest() != 1
            || wmcPlateLongSleep() != 9
            || wmcPlateLongRefresh() != 5
            || wmcPolesAdequate() != 2
            || wmcPolesGood() != 4
            || wmcPolesSuperior() != 6
            || wmcWindStepMph() != 10
            || wmcWindLeakMph() != 5
            || wmcWindDamagePct() != 25
            || wmcPoorShelterRes() != 20
            || wmcLifeSetupsPerPoint() != 3
            || wmcForestMatsMin() != 3
            || wmcLashBaseTurns() != 6
            || !wmcBarIsOneHour()
            || !wmcRefuelGraceIdentity()
            || !wmcWindTwentyTriple()
            || !wmcNoStartMatchesMedium()
            || !wmcGrowthOnlyGeometric()
            || !wmcRestColdSeamR499()
            || !wmcRestHotSeamR499()
            || !wmcPlateFlatLoss()
            || !wmcLeakHalfStep()
            || !wmcPolesLinear()
        )
            ++bad;
        // the fire sizes and the burn hours
    if (wmcFireSizes() != 3
            || wmcBurnHours() != 8
        )
            ++bad;
        // the fuel ladder is arithmetic: 6, 12, 18
    if (wmcFuelMedium() - wmcFuelSmall() != 6
            || wmcFuelLarge() - wmcFuelMedium() != 6
            || wmcFuelSmall() != 6
        )
            ++bad;
        // the refuel ladder is arithmetic: 3, 6, 9
    if (wmcRefuelSmall() != 3
            || wmcRefuelMedium() != 6
            || wmcRefuelLarge() != 9
            || wmcRefuelMedium() - wmcRefuelSmall() != wmcRefuelLarge() -
            wmcRefuelMedium()
        )
            ++bad;
        // the wind-resistance ladder: 20, 30, 40
    if (wmcWindResSmall() != 20
            || wmcWindResMedium() != 30
            || wmcWindResLarge() != 40
        )
            ++bad;
        // the spark ladder: 10, 20, 30
    if (wmcSparkSmall() != 10
            || wmcSparkMedium() != 20
            || wmcSparkLarge() != 30
        )
            ++bad;
        // the growth ladder doubles: 1, 2, 4
    if (wmcGrowthSmall() != 1
            || wmcGrowthMedium() != 2 * wmcGrowthSmall()
            || wmcGrowthLarge() != 2 * wmcGrowthMedium()
        )
            ++bad;
        // the uncontrollable bar is exactly one hour
    if (wmcUncontrollableTurns() != wmcTurnsPerHour()
            || wmcRoundsPerTurn() != 10
        )
            ++bad;
        // the refuel grace identity - two headers, one number
    if (wmcRefuelSmall() != wmcSmallRefuelGrace()
        )
            ++bad;
        // the twenty-mph triple agreement
    if (wmcWindResSmall() != 20
            || wmcPoorShelterRes() != 20
            || wmcWindResSmall() != wmcPoorShelterRes()
        )
            ++bad;
        // the no-start maximum equals the medium wind resistance
    if (wmcNoStartWindMax() != wmcWindResMedium()
            || wmcStartBreezeMax() != 15
        )
            ++bad;
        // the hard start costs one more die
    if (wmcHardStartDice() - wmcStartDice() != 1
        )
            ++bad;
        // the spark carry gains one foot per mph of wind
    if (wmcSparkWindFtPerMph() != 1
            || wmcHalveDivisor() != 2
        )
            ++bad;
        // the rest cold seam to the R499 fold: the same 0
    if (wmcRestColdBound() != 0
            || wmcPenTempBelow0() != 1
        )
            ++bad;
        // the rest hot seam: one degree past the protected no-damage top
    if (wmcRestHotBound() != wmcR499ProtTop() + 1
            || wmcPenTempAbove90() != 2
        )
            ++bad;
        // the rest penalty sum: precip and metal tie at 3, plate tops at 4
    if (wmcPenPrecip() != 3
            || wmcPenMetal() != 3
            || wmcPenPlate() != 4
            || wmcPenWind() != 2
        )
            ++bad;
        // the plate economy loses a flat 4 hours either way
    if (wmcPlateNight() - wmcPlateGoodRest() != 4
            || wmcPlateLongSleep() - wmcPlateLongRefresh() != 4
        )
            ++bad;
        // the fire capacity doubles per step of distance
    if (wmcCapSmallAt20() != 2 * wmcCapSmallAt10()
            || wmcCapBaseFeet() != 10
            || wmcCapSmallAt10() != 6
        )
            ++bad;
        // the tent leak is half the wind step
    if (wmcWindLeakMph() * 2 != wmcWindStepMph()
            || wmcWindDamagePct() != 25
        )
            ++bad;
        // the pole ladder is arithmetic: 2, 4, 6
    if (wmcPolesGood() - wmcPolesAdequate() != 2
            || wmcPolesSuperior() - wmcPolesGood() != 2
        )
            ++bad;
        // the shelter construction times
    if (wmcForestMatsMin() != 3
            || wmcLashBaseTurns() != 6
            || wmcLifeSetupsPerPoint() != 3
        )
            ++bad;
        printf("R502 WSG camp chain fold audit: bad %d\n", bad);
        if (bad) return 1;
    }
