    // ---- R475 WSG fuel and fire safety pin audit ----
    // The Table 39 grids (the five terrains by four temperate seasons and the
    // six terrains by four climate modifiers), the Table 38 column semantics
    // (the start discipline with the tools and wind gates, the refuel shrink
    // rule, the wind resistance semantics, the capacity doubling and
    // clustering reductions, the visibility reductions and line-of-sight
    // rulings, the warmth safe-distance and wind-modifier rules with the book
    // own worked example) and the fire safety prose are audit examples.
    {
        using namespace rules;
        int bad = 0;
    if (wflStartBreezeMax() != 15
            || wflStartDie() != 20
            || wflStartDice() != 2
            || wflHardStartDice() != 3
            || wflNoStartWindMax() != 30
            || wflSmallRefuelGrace() != 3
            || wflCapBaseFeet() != 10
            || wflSmallCapAt10() != 6
            || wflSmallCapAt20() != 12
            || wflCapStepFeet() != 10
            || wflDimFiveNum() != 1
            || wflDimFiveDen() != 3
            || wflDimThreeNum() != 1
            || wflDimThreeDen() != 2
            || wflDimOneNum() != 2
            || wflDimOneDen() != 3
            || wflClusterFiveMax() != 4
            || wflClusterThreeMax() != 3
            || wflClusterOneMax() != 2
            || wflLargeVisYards() != 540
            || wflTwilightNum() != 1
            || wflTwilightDen() != 3
            || wflDaylightNum() != 1
            || wflDaylightDen() != 2
            || wflSafeWarmthDegrees() != 80
            || wflMoveAwaySegments() != 5
            || wflMediumSafeFt() != 3
            || wflLargeSafeFt() != 5
            || wflWarmCalmWindMax() != 10
            || wflWindwardDegStep() != 5
            || wflWindwardMphStep() != 10
            || wflLeewardFeetStep() != 10
            || wflExWindMph() != 30
            || wflExWindwardDeg() != 20
            || wflExCalmDeg() != 30
            || wflExLeewardFt() != 10
            || wflExCalmSafeFt() != 3
            || wflClearMinTurns() != 1
            || wflClearMaxTurns() != 3
            || wflSparkCarryFeet() != 100
            || wflRecheckTurns() != 2
            || wflTerrainCount() != 5
            || wflClimateTerrainCount() != 6
            || !wflStartAssumesTools()
            || !wflHardStartOnWindOrWet()
            || !wflUnskilledNeedsTools()
            || !wflRefuelKeepsSize()
            || !wflUnrefueledShrinks()
            || !wflSmallFireLingersCold()
            || !wflWindResUnprotectedOnly()
            || !wflOverRatedWindFalters()
            || !wflWindMaySpreadFire()
            || !wflCapDoublesPerStep()
            || !wflCapClustersDiminish()
            || !wflVisMoonlightOrDarkness()
            || !wflVisTwilightReduction()
            || !wflVisDaylightReduction()
            || !wflVisNeedsClearLine()
            || !wflGlowThroughDenseForest()
            || !wflHillBlocksLongSight()
            || !wflSmokeRevealsInDaylight()
            || !wflSafeDistanceIs80Degrees()
            || !wflDashMeansBurned()
            || !wflWarmthAssumesCalm()
            || !wflWindwardWarmthCut()
            || !wflLeewardSafeAdd()
            || !wflNoSafeFire()
            || !wflUntendedFireSpreads()
            || !wflCardinalRulesRealWorld()
            || !wflNoFireOnCombustibles()
            || !wflFuelIsWood()
            || !wflTemperateAssumed()
            || !wflMovingAllowsRechecks()
        )
            ++bad;
        // Table 39: availability of fuel, the five terrains by four seasons
        // in a temperate climate, printed p. 66
        int C39[5][4] = {
            {20,20,20,20},
            {70,100,100,100},
            {40,70,70,60},
            {50,70,80,70},
            {40,30,30,40},
            };
        int n39[4] = {0,0,0,0};
        int e39[4] = {0,0,0,0};
        for (int b = 0;
             b < wflTerrainCount();
             ++b) {
            int vals[4];
            vals[0] = wflFuelWinter(b);
            vals[1] = wflFuelSpring(b);
            vals[2] = wflFuelSummer(b);
            vals[3] = wflFuelAutumn(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C39[b][c])
                    ++bad;
                if (vals[c] == 999)
                    ++n39[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (n39[c] != e39[c])
                ++bad;
        // Table 39: the climate modifiers, the six terrains by arctic,
        // subarctic, subtropical and tropical, printed p. 66
        int C39c[6][4] = {
            {-20,-10,-10,-20},
            {-100,-30,30,30},
            {-30,-20,10,20},
            {-40,-30,20,30},
            {-60,-40,20,20},
            {-40,-20,10,20},
            };
        int n39c[4] = {0,0,0,0};
        int e39c[4] = {0,0,0,0};
        for (int b = 0;
             b < wflClimateTerrainCount();
             ++b) {
            int vals[4];
            vals[0] = wflArcticMod(b);
            vals[1] = wflSubarcticMod(b);
            vals[2] = wflSubtropicalMod(b);
            vals[3] = wflTropicalMod(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C39c[b][c])
                    ++bad;
                if (vals[c] == 999)
                    ++n39c[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (n39c[c] != e39c[c])
                ++bad;
        // the start discipline: 2d20 rounds for the unskilled, 3d20 in wind
        // over 15 mph or with wet fuel, and the 30-mph magical bar
    if (wflStartDie() != 20
            || wflStartDice() != 2
            || wflHardStartDice() != 3
            || wflStartBreezeMax() != 15
            || wflNoStartWindMax() != 30
        )
            ++bad;
        // the small-fire refuel grace: three turns before it stops providing
        // warmth
    if (wflSmallRefuelGrace() != 3
        )
            ++bad;
        // the capacity example: six men at 10 feet, twelve at 20, doubling
        // per 10-foot step
    if (wflSmallCapAt10() != 6
            || wflSmallCapAt20() != 12
            || wflCapBaseFeet() != 10
            || wflCapStepFeet() != 10
            || wflSmallCapAt20() != 2 * wflSmallCapAt10()
        )
            ++bad;
        // the clustering cuts: one-third at five feet, one-half at three,
        // two-thirds at one, with the 4/3/2 example
    if (wflDimFiveNum() != 1
            || wflDimFiveDen() != 3
            || wflDimThreeNum() != 1
            || wflDimThreeDen() != 2
            || wflDimOneNum() != 2
            || wflDimOneDen() != 3
            || wflClusterFiveMax() != 4
            || wflClusterThreeMax() != 3
            || wflClusterOneMax() != 2
        )
            ++bad;
        // the clustering maxima step down: 4 at five feet, 3 at three, 2 at
        // one
    if (wflClusterFiveMax() <= wflClusterThreeMax()
            || wflClusterThreeMax() <= wflClusterOneMax()
        )
            ++bad;
        // the visibility example: 540 yards for a large fire, one-third off
        // in twilight, one-half off in daylight
    if (wflLargeVisYards() != 540
            || wflTwilightNum() != 1
            || wflTwilightDen() != 3
            || wflDaylightNum() != 1
            || wflDaylightDen() != 2
        )
            ++bad;
        // the safe distances: 80 degrees of warmth, five segments to move, 3
        // feet from a medium fire and 5 from a large
    if (wflSafeWarmthDegrees() != 80
            || wflMoveAwaySegments() != 5
            || wflMediumSafeFt() != 3
            || wflLargeSafeFt() != 5
        )
            ++bad;
        // the warmth wind rules: calm below 10 mph, windward minus 5 degrees
        // per 10 mph, leeward plus 10 feet or one increment
    if (wflWarmCalmWindMax() != 10
            || wflWindwardDegStep() != 5
            || wflWindwardMphStep() != 10
            || wflLeewardFeetStep() != 10
        )
            ++bad;
        // the book worked example: a 30-mph wind, 20 degrees windward at 20
        // feet instead of 30, 10 feet leeward instead of 3
    if (wflExWindMph() != 30
            || wflExWindwardDeg() != 20
            || wflExCalmDeg() != 30
            || wflExLeewardFt() != 10
            || wflExCalmSafeFt() != 3
        )
            ++bad;
        // the example windward loss is exactly two 5-degree steps of the
        // 30-mph over-10 excess, and the leeward increase takes the
        // whichever-is-less path: positive but under the 10-foot step
    if (wflExCalmDeg() - wflExWindwardDeg() != 2 * wflWindwardDegStep()
            || (wflExLeewardFt() - wflExCalmSafeFt()) >= wflLeewardFeetStep()
            || wflExLeewardFt() <= wflExCalmSafeFt()
        )
            ++bad;
        // the fire safety small numbers: 1-3 turns to clear, sparks 100 feet,
        // rechecks every two turns
    if (wflClearMinTurns() != 1
            || wflClearMaxTurns() != 3
            || wflSparkCarryFeet() != 100
            || wflRecheckTurns() != 2
            || wflClearMinTurns() >= wflClearMaxTurns()
        )
            ++bad;
        // the desert row: fuel equally scarce all year
    if (wflFuelWinter(0) != 20
            || wflFuelSpring(0) != 20
            || wflFuelSummer(0) != 20
            || wflFuelAutumn(0) != 20
        )
            ++bad;
        // the forest row: plentiful outside winter
    if (wflFuelWinter(1) != 70
            || wflFuelSpring(1) != 100
            || wflFuelSummer(1) != 100
            || wflFuelAutumn(1) != 100
        )
            ++bad;
        // the hills row (vision-settled): 40 in winter, 70 in spring and
        // summer, 60 in autumn
    if (wflFuelWinter(2) != 40
            || wflFuelSpring(2) != 70
            || wflFuelSummer(2) != 70
            || wflFuelAutumn(2) != 60
        )
            ++bad;
        // the plains row: best in summer
    if (wflFuelWinter(3) != 50
            || wflFuelSpring(3) != 70
            || wflFuelSummer(3) != 80
            || wflFuelAutumn(3) != 70
        )
            ++bad;
        // the swamp row: worst in spring and summer
    if (wflFuelWinter(4) != 40
            || wflFuelSpring(4) != 30
            || wflFuelSummer(4) != 30
            || wflFuelAutumn(4) != 40
        )
            ++bad;
        // every temperate cell is a percentage between 20 and 100
    if (wflFuelWinter(0) < 20
            || wflFuelSpring(1) < 20
            || wflFuelAutumn(2) < 20
            || wflFuelSummer(3) > 100
            || wflFuelWinter(4) > 100
        )
            ++bad;
        // the desert climate modifiers
    if (wflArcticMod(0) != -20
            || wflSubarcticMod(0) != -10
            || wflSubtropicalMod(0) != -10
            || wflTropicalMod(0) != -20
        )
            ++bad;
        // the forest climate modifiers: the arctic -100 wipeout
    if (wflArcticMod(1) != -100
            || wflSubarcticMod(1) != -30
            || wflSubtropicalMod(1) != 30
            || wflTropicalMod(1) != 30
        )
            ++bad;
        // the hills climate modifiers (vision-settled)
    if (wflArcticMod(2) != -30
            || wflSubarcticMod(2) != -20
            || wflSubtropicalMod(2) != 10
            || wflTropicalMod(2) != 20
        )
            ++bad;
        // the mountains climate modifiers
    if (wflArcticMod(3) != -40
            || wflSubarcticMod(3) != -30
            || wflSubtropicalMod(3) != 20
            || wflTropicalMod(3) != 30
        )
            ++bad;
        // the plains climate modifiers: the arctic -60 is the harshest on the
        // grid
    if (wflArcticMod(4) != -60
            || wflSubarcticMod(4) != -40
            || wflSubtropicalMod(4) != 20
            || wflTropicalMod(4) != 20
        )
            ++bad;
        // the swamp climate modifiers
    if (wflArcticMod(5) != -40
            || wflSubarcticMod(5) != -20
            || wflSubtropicalMod(5) != 10
            || wflTropicalMod(5) != 20
        )
            ++bad;
        // outside the desert, the cold climates penalize and the warm
        // climates bonus
    if (wflArcticMod(1) >= 0
            || wflSubarcticMod(2) >= 0
            || wflSubtropicalMod(3) <= 0
            || wflTropicalMod(4) <= 0
            || wflArcticMod(5) >= 0
            || wflSubtropicalMod(5) <= 0
        )
            ++bad;
        printf("R475 WSG fuel and fire safety pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
