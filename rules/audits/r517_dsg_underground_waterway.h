    // ---- R517 DSG underground waterways audit ----
    // The DSG underground waterways pins the standing water rules (the four
    // forms of water underground, the low ceiling making normal boat travel
    // impossible, the absence of wind making sailing virtually unheard-of
    // except under ample ventilation, the practically nonexistent waves with
    // the cave-in and earthquake tsunami class and the confining-wall chop
    // lasting many turns, the fresh-water lakes and pools almost always safe
    // to drink when fed by a stream or spring, and the reservoir whose dam
    // may sit at the bottom like a cork in a leaky bucket), the deep
    // mineral-heavy salt seas with their cold and geothermal-steam extremes,
    // the flowing-water measurements (the impassable under 3 feet, narrow
    // under 20 wide and 3 deep, average 20-60 wide and 4-8 deep, wide over 60
    // and deeper than 8, the canals and aqueducts and water wheels and locks,
    // the 50% half-full and 100% unboatable flow percentages, and the 0-40
    // rate scale with the 20-feet-per-round multiplier), the six flow bands
    // (stagnant 0, placid 1-2 at 40 feet or less per round with the
    // 10-15-feet-per-mile drop, medium 2-6 at 40-120 feet per round with up
    // to 30 feet per mile and the 1d6-per-mile roll triggering a 1d3-foot
    // drop-off on a 5 or 6, rapids 6-12 at more than 120 up to 240 feet per
    // round with the 30-200 slope and 1,000-foot audibility and the 1d6 roll
    // where 6 means none and 1-5 counts 1d4-foot drop-offs, cascades 12-30
    // audible a mile away at 240-600 feet per round with the 200-1,000 slope
    // and the 3d6-per-mile count of 1d8-foot drop-offs, and waterfalls 30-40
    // at at least 600 feet per round wherever the plunge exceeds 1,000 feet
    // per mile, with boats uncontrollable and survival luck), the damming
    // rules (the immediate backup flooding against three-dimensional maps,
    // the 1,000-cubic-foot cube per flow point per turn doubled for wide and
    // quartered for narrow waterways, the diversion down the path of least
    // resistance, the 1d6 dam points per worker per turn against the
    // flow-rate destruction, the 50/150/250 completed CPVs per the DMG pages
    // 109-110 seam, and the half-flow leak destruction until washed away or
    // repaired), the water temperature ladder (the almost universally cold
    // water, the 1d4-mile warmth retention from surface sources, the
    // geothermal warming, the 6d6 near-boiling burn per round with no save
    // and the -2 per die minimum 1 under magical protection, the proportional
    // partial-immersion damage, the 1d6 very-hot damage that spares the
    // partially exposed and the magically protected, and the bath-warm
    // immunity), and the access rules (the occasional direct surface embark,
    // the usual dungeon-and-cavern route, the upstream-travel cost of a
    // return-to-surface outlet, the sheer-cliff lake shores with their
    // creature-built docks and wharves, and the smooth sandy banks of streams
    // and rivers).
    {
        using namespace rules;
        int bad = 0;
    if (dntImpassableMaxDiaFt() != 3
            || dntNarrowMaxWidthFt() != 20
            || dntNarrowTypicalMaxDepthFt() != 3
            || dntAverageMinWidthFt() != 20
            || dntAverageMaxWidthFt() != 60
            || dntAverageDepthLowFt() != 4
            || dntAverageDepthHighFt() != 8
            || dntWideMinWidthFt() != 60
            || dntWideMinDepthFt() != 8
            || dntHalfFlowPct() != 50
            || dntFullFlowPct() != 100
            || dntFlowRateMax() != 40
            || dntStagnantFlowRate() != 0
            || dntFtPerRoundPerFlowPoint() != 20
            || dntPlacidMaxFlowRate() != 2
            || dntPlacidDropLowFtPerMile() != 10
            || dntPlacidDropHighFtPerMile() != 15
            || dntPlacidMaxFtPerRound() != 40
            || dntMediumMaxFlowRate() != 6
            || dntMediumFtPerRoundLow() != 40
            || dntMediumFtPerRoundHigh() != 120
            || dntMediumDropFtPerMile() != 30
            || dntMediumDropoffMileDice() != 1
            || dntMediumDropoffMileSides() != 6
            || dntMediumDropoffTriggerLow() != 5
            || dntMediumDropoffTriggerHigh() != 6
            || dntMediumDropoffFtDice() != 1
            || dntMediumDropoffFtSides() != 3
            || dntRapidMinFlowRate() != 6
            || dntRapidMaxFlowRate() != 12
            || dntRapidFtPerRoundLow() != 120
            || dntRapidFtPerRoundHigh() != 240
            || dntRapidDescentLowFtPerMile() != 30
            || dntRapidDescentHighFtPerMile() != 200
            || dntRapidsAudibleFt() != 1000
            || dntRapidDropoffMileDice() != 1
            || dntRapidDropoffMileSides() != 6
            || dntRapidDropoffNoneRoll() != 6
            || dntRapidDropoffFtDice() != 1
            || dntRapidDropoffFtSides() != 4
            || dntCascadeMinFlowRate() != 12
            || dntCascadeMaxFlowRate() != 30
            || dntCascadeFtPerRoundLow() != 240
            || dntCascadeFtPerRoundHigh() != 600
            || dntCascadeSlopeLowFtPerMile() != 200
            || dntCascadeSlopeHighFtPerMile() != 1000
            || dntCascadeAudibleMiles() != 1
            || dntCascadeDropoffMileDice() != 3
            || dntCascadeDropoffMileSides() != 6
            || dntCascadeDropoffFtDice() != 1
            || dntCascadeDropoffFtSides() != 8
            || dntWaterfallMinFlowRate() != 30
            || dntWaterfallMaxFlowRate() != 40
            || dntWaterfallMinFtPerRound() != 600
            || dntWaterfallSlopeFtPerMile() != 1000
            || dntDamCuFtPerFlowPerTurn() != 1000
            || dntDamCpvNarrow() != 50
            || dntDamCpvAverage() != 150
            || dntDamCpvWide() != 250
            || dntDamWorkerDice() != 1
            || dntDamWorkerSides() != 6
            || dntDamLeakDivisor() != 2
            || dntWarmthMilesDice() != 1
            || dntWarmthMilesSides() != 4
            || dntBoilingBurnDice() != 6
            || dntBoilingBurnSides() != 6
            || dntHeatProtectPerDie() != 2
            || dntHeatProtectMinPerDie() != 1
            || dntVeryHotBurnDice() != 1
            || dntVeryHotBurnSides() != 6
            || !dntStandingWaterForms()
            || !dntLowCeilingBlocksBoats()
            || !dntNoWindSailingRare()
            || !dntWavesPracticallyNonexistent()
            || !dntCaveInMakesTsunamiWave()
            || !dntChopAmplifiedByWalls()
            || !dntWiseToFindWaveSource()
            || !dntLakesPoolsFreshWater()
            || !dntInflowWaterSafeToDrink()
            || !dntReservoirDamMayBeAtBottom()
            || !dntSeasDeepSaltHuge()
            || !dntSeasGeothermalSteam()
            || !dntFlowingMoreCommonThanStanding()
            || !dntThreeMeasurements()
            || !dntArtificialCanalsAqueducts()
            || !dntFullFlowUnboatable()
            || !dntStagnantShallowBoatRisk()
            || !dntPlacidFloatersShowFlow()
            || !dntMediumWatchForRocks()
            || !dntRapidsUpstreamImpossible()
            || !dntRapidsNeedBoatingProficiency()
            || !dntCascadeUpstreamImpossible()
            || !dntWaterfallStretchesWithRapids()
            || !dntWaterfallBoatUncontrollable()
            || !dntDamBacksUpFloods()
            || !dntDamDoubleWideQuarterNarrow()
            || !dntDamDivertsLeastResistance()
            || !dntDamCurrentDestroysFlow()
            || !dntDamCompletedStable()
            || !dntUndergroundWaterUniversallyCold()
            || !dntGeothermalWarming()
            || !dntBoilingNoSave()
            || !dntBoilingPartialProportional()
            || !dntVeryHotProtectedUnaffected()
            || !dntBathWarmNoIllEffects()
            || !dntDirectSurfaceEmbarkOccasional()
            || !dntUsuallyEnterViaDungeon()
            || !dntOutletRequiresUpstream()
            || !dntLakeShoresCliffsNotSand()
            || !dntStreamShoresSandBeaches()
        )
            ++bad;
        // the passage diameter ladder: impassable under 3 ft, narrow under 20
        // ft wide and 3 ft deep, average 20-60 ft wide and 4-8 ft deep, wide
        // over 60 ft and deeper than 8 ft.
    if (dntImpassableMaxDiaFt() != 3
            || dntNarrowMaxWidthFt() != 20
            || dntNarrowTypicalMaxDepthFt() != 3
            || dntAverageMinWidthFt() != 20
            || dntAverageMaxWidthFt() != 60
            || dntAverageDepthLowFt() != 4
            || dntAverageDepthHighFt() != 8
            || dntWideMinWidthFt() != 60
            || dntWideMinDepthFt() != 8
        )
            ++bad;
        // the percentage of flow: 50% half-full of water and air, 100%
        // completely filled and unboatable (the djvu garble 10096 settled by
        // the Capture read).
    if (dntHalfFlowPct() != 50
            || dntFullFlowPct() != 100
        )
            ++bad;
        // the rate of flow scale: 0 stagnant, 1-40 with 40 tumbling as
        // waterfalls, and the current moving at 20 feet per round per flow
        // point.
    if (dntFlowRateMax() != 40
            || dntStagnantFlowRate() != 0
            || dntFtPerRoundPerFlowPoint() != 20
        )
            ++bad;
        // the placid band: flow 1-2, a drop of 10-15 feet per mile, and 40
        // feet or less per round.
    if (dntPlacidMaxFlowRate() != 2
            || dntPlacidDropLowFtPerMile() != 10
            || dntPlacidDropHighFtPerMile() != 15
            || dntPlacidMaxFtPerRound() != 40
        )
            ++bad;
        // the medium band: flow 2-6 (the djvu garble "flow rate - 2-6"
        // settled by the Capture "= 2-6"), 40-120 feet per round, and up to
        // 30 feet of drop per mile.
    if (dntMediumMaxFlowRate() != 6
            || dntMediumFtPerRoundLow() != 40
            || dntMediumFtPerRoundHigh() != 120
            || dntMediumDropFtPerMile() != 30
        )
            ++bad;
        // the medium drop-off roll: 1d6 per mile, on a 5 or 6 a drop-off of
        // 1d3 feet somewhere in that mile.
    if (dntMediumDropoffMileDice() != 1
            || dntMediumDropoffMileSides() != 6
            || dntMediumDropoffTriggerLow() != 5
            || dntMediumDropoffTriggerHigh() != 6
            || dntMediumDropoffFtDice() != 1
            || dntMediumDropoffFtSides() != 3
        )
            ++bad;
        // the rapids band: flow 6-12, more than 120 to 240 feet per round, a
        // 30-200 feet-per-mile descent, and the sound audible within 1,000
        // feet.
    if (dntRapidMinFlowRate() != 6
            || dntRapidMaxFlowRate() != 12
            || dntRapidFtPerRoundLow() != 120
            || dntRapidFtPerRoundHigh() != 240
            || dntRapidDescentLowFtPerMile() != 30
            || dntRapidDescentHighFtPerMile() != 200
            || dntRapidsAudibleFt() != 1000
        )
            ++bad;
        // the rapids drop-off roll: 1d6 per mile with 6 = none and 1-5 the
        // count, each drop-off falling 1d4 feet.
    if (dntRapidDropoffMileDice() != 1
            || dntRapidDropoffMileSides() != 6
            || dntRapidDropoffNoneRoll() != 6
            || dntRapidDropoffFtDice() != 1
            || dntRapidDropoffFtSides() != 4
        )
            ++bad;
        // the cascade band: flow 12-30, audible at least a mile away, 240-600
        // feet per round, and a 200-1,000 feet-per-mile slope.
    if (dntCascadeMinFlowRate() != 12
            || dntCascadeMaxFlowRate() != 30
            || dntCascadeAudibleMiles() != 1
            || dntCascadeFtPerRoundLow() != 240
            || dntCascadeFtPerRoundHigh() != 600
            || dntCascadeSlopeLowFtPerMile() != 200
            || dntCascadeSlopeHighFtPerMile() != 1000
        )
            ++bad;
        // the cascade drop-off roll: 3d6 drop-offs per mile, each 1d8 feet
        // high.
    if (dntCascadeDropoffMileDice() != 3
            || dntCascadeDropoffMileSides() != 6
            || dntCascadeDropoffFtDice() != 1
            || dntCascadeDropoffFtSides() != 8
        )
            ++bad;
        // the waterfall band: flow 30-40, at least 600 feet per round, and
        // any plunge over 1,000 feet per mile counted a waterfall.
    if (dntWaterfallMinFlowRate() != 30
            || dntWaterfallMaxFlowRate() != 40
            || dntWaterfallMinFtPerRound() != 600
            || dntWaterfallSlopeFtPerMile() != 1000
        )
            ++bad;
        // the damming math: the 5-flow average waterway backs up five 10-foot
        // cubes (5,000 cubic feet) per turn, a single worker builds 1d6
        // points per turn, completed dams run 50/150/250 points, and a leak
        // destroys half the flow rate per turn.
    if (dntDamCuFtPerFlowPerTurn() != 1000
            || dntDamWorkerDice() != 1
            || dntDamWorkerSides() != 6
            || dntDamCpvNarrow() != 50
            || dntDamCpvAverage() != 150
            || dntDamCpvWide() != 250
            || dntDamLeakDivisor() != 2
        )
            ++bad;
        // the temperature ladder: surface warmth retained 1d4 miles,
        // near-boiling water at 6d6 per round with no save and -2 per die
        // (minimum 1) under magical protection, and very-hot water at 1d6.
    if (dntWarmthMilesDice() != 1
            || dntWarmthMilesSides() != 4
            || dntBoilingBurnDice() != 6
            || dntBoilingBurnSides() != 6
            || dntHeatProtectPerDie() != 2
            || dntHeatProtectMinPerDie() != 1
            || dntVeryHotBurnDice() != 1
            || dntVeryHotBurnSides() != 6
        )
            ++bad;
        printf("R517 DSG underground waterways audit: bad %d\n", bad);
        if (bad) return 1;
    }
