    // ---- R470 WSG purifying water pin audit ----
    // The purification baseline (the 10% taint remainder after a sufficient
    // boil, the 2-5 round boil at sea level plus the elevation time adder,
    // the early-removal nullification, the evaporation cost ladder at the
    // 5,000-foot break), the tainted-water effects (the mild 6-hour and
    // severe 18-hour minimum durations vs the food 12/24), the taint-severity
    // geography (low elevation and warm climates) and the bad-water warnings
    // (the taste-and-appearance deception, the bacteria and poison layer, the
    // skeletal-remains waterhole) - every const and bool verified against the
    // model.
    {
        using namespace rules;
        int bad = 0;
    if (wpuBoilTaintRemainPct() != 10
            || wpuBoilRoundsMin() != 2
            || wpuBoilRoundsMax() != 5
            || wpuElevStepFt() != 1000
            || wpuEvapBreakFt() != 5000
            || wpuEvapLowPctPerMin() != 5
            || wpuEvapHighPctPerMin() != 3
            || wpuMildMinHours() != 6
            || wpuMildFoodBaseHours() != 12
            || wpuSevereMinHours() != 18
            || wpuSevereFoodBaseHours() != 24
            || !wpuSuspectTaintAlmostAlways()
            || !wpuBoilBestNonmagical()
            || !wpuEarlyRemovalNoGood()
            || !wpuQuantityOverQuality()
            || !wpuEffectsMatchTaintedFood()
            || !wpuSeverityDMRuling()
            || !wpuSevereLikelyLowWarm()
            || !wpuColdDoesNotKill()
            || !wpuTasteNotIndicator()
            || !wpuBacteriaAndPoisonLayer()
            || !wpuWaterholeDeadGiveaway()
            || !wpuCautionCommonSense()
        )
            ++bad;
        // the boil time at sea level: 2-5 rounds (1d4+1)
    if (wpuBoilRoundsMin() != 2
            || wpuBoilRoundsMax() != 5
            || wpuBoilRoundsMin() >= wpuBoilRoundsMax()
        )
            ++bad;
        // the taint remainder after a sufficient boil: only 10%
    if (wpuBoilTaintRemainPct() != 10
        )
            ++bad;
        // the evaporation ladder: the 5,000-foot break with 5% below and 3%
        // above
    if (wpuEvapBreakFt() != 5000
            || wpuEvapLowPctPerMin() != 5
            || wpuEvapHighPctPerMin() != 3
            || wpuEvapLowPctPerMin() <= wpuEvapHighPctPerMin()
        )
            ++bad;
        // the elevation adder: an extra 1d2 minutes per 1,000 feet
    if (wpuElevStepFt() != 1000
        )
            ++bad;
        // the mild taint: a 6-hour minimum against the 12-hour food baseline
    if (wpuMildMinHours() != 6
            || wpuMildFoodBaseHours() != 12
            || wpuMildMinHours() >= wpuMildFoodBaseHours()
        )
            ++bad;
        // the severe taint: an 18-hour minimum against the 24-hour food
        // baseline
    if (wpuSevereMinHours() != 18
            || wpuSevereFoodBaseHours() != 24
            || wpuSevereMinHours() >= wpuSevereFoodBaseHours()
        )
            ++bad;
        // the severe ladder climbs above the mild ladder
    if (wpuSevereMinHours() <= wpuMildMinHours()
        )
            ++bad;
        // the boil mechanics: the best nonmagical purification, the
        // early-removal nullification and the quantity-over-quality tradeoff
    if (wpuBoilBestNonmagical() != 1
            || wpuEarlyRemovalNoGood() != 1
            || wpuQuantityOverQuality() != 1
        )
            ++bad;
        // the taint-severity geography: the low-warm likelihood and the
        // cold-does-not-kill exception
    if (wpuSevereLikelyLowWarm() != 1
            || wpuColdDoesNotKill() != 1
            || wpuSeverityDMRuling() != 1
        )
            ++bad;
        // the bad-water warnings: the taste deception, the
        // bacteria-and-poison layer, the skeletal-remains waterhole and the
        // caution-and-common-sense close
    if (wpuTasteNotIndicator() != 1
            || wpuBacteriaAndPoisonLayer() != 1
            || wpuWaterholeDeadGiveaway() != 1
            || wpuCautionCommonSense() != 1
        )
            ++bad;
        printf("R470 WSG purifying water pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
