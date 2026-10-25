    // ---- R476 WSG uncontrollable fires pin audit ----
    // The fire discipline rules (no oversize with the two-small-fires advice,
    // never untended with the sentry watch), the spark cadence with the carry
    // ladder and the catch chance, the average-case growth ladder with the
    // six-turn uncontrollable bar, the extinguishing times with the halving,
    // water and combustible-doubling semantics and the residual and flare-up
    // chances, and the uncontrollable-fire spread prose are audit examples.
    {
        using namespace rules;
        int bad = 0;
    if (wcfSparkDieSides() != 3
            || wcfSparkCarrySmallFt() != 10
            || wcfSparkCarryMediumFt() != 20
            || wcfSparkCarryLargeFt() != 30
            || wcfSparkWindFtPerMph() != 1
            || wcfCatchRoll() != 1
            || wcfCatchDie() != 6
            || wcfGrowthSmallTurns() != 1
            || wcfGrowthMediumTurns() != 2
            || wcfGrowthLargeTurns() != 4
            || wcfUncontrollableTurns() != 6
            || wcfTurnsPerHour() != 6
            || wcfRoundsPerTurn() != 10
            || wcfExtinguishSmallRounds() != 5
            || wcfExtinguishMediumTurns() != 1
            || wcfExtinguishLargeTurns() != 2
            || wcfHalveDivisor() != 2
            || wcfWaterSmallGal() != 1
            || wcfWaterMediumGal() != 2
            || wcfWaterLargeGal() != 4
            || wcfCombustibleTimeMult() != 2
            || wcfResidualRoll() != 1
            || wcfResidualDie() != 10
            || wcfFlareDice() != 2
            || wcfFlareDieSides() != 4
            || !wcfNoOversizeRule()
            || !wcfTwoSmallFiresBetter()
            || !wcfSmallerEasierControl()
            || !wcfNeverLeaveUntended()
            || !wcfSentryWatchesFire()
            || !wcfWildFireCanGrow()
            || !wcfDmAdjudicatesSpread()
            || !wcfStrongWindMinutes()
            || !wcfCalmMayDie()
            || !wcfUncontrollableByHeightOrArea()
            || !wcfExtinguishMethod()
            || !wcfHelperHalvesTime()
            || !wcfWaterHalvesTime()
            || !wcfCombustibleDoublesTime()
            || !wcfResidualRisk()
            || !wcfLeftAliveFlares()
            || !wcfSpreadWhileFuelContact()
            || !wcfOutsideForceStops()
            || !wcfRoughCircleFirst()
            || !wcfStringsOutToWall()
            || !wcfWiseFlee()
        )
            ++bad;
        // the spark cadence: 1d3 turns, the 10-20-30 foot carry ladder and
        // the 1-foot-per-mph wind add
    if (wcfSparkDieSides() != 3
            || wcfSparkCarrySmallFt() != 10
            || wcfSparkCarryMediumFt() != 20
            || wcfSparkCarryLargeFt() != 30
            || wcfSparkWindFtPerMph() != 1
        )
            ++bad;
        // the catch chance is 1 in 6 on combustible material
    if (wcfCatchRoll() != 1
            || wcfCatchDie() != 6
            || wcfCatchRoll() >= wcfCatchDie()
        )
            ++bad;
        // the average-case growth ladder: tiny to small in 1 turn, to medium
        // in 2, to large in 4
    if (wcfGrowthSmallTurns() != 1
            || wcfGrowthMediumTurns() != 2
            || wcfGrowthLargeTurns() != 4
        )
            ++bad;
        // the ladder is strictly increasing and the uncontrollable bar sits
        // strictly beyond the large step
    if (wcfGrowthSmallTurns() >= wcfGrowthMediumTurns()
            || wcfGrowthMediumTurns() >= wcfGrowthLargeTurns()
            || wcfGrowthLargeTurns() >= wcfUncontrollableTurns()
        )
            ++bad;
        // the 6-turn uncontrollable bar is exactly one hour at six turns per
        // hour
    if (wcfUncontrollableTurns() != 6
            || wcfTurnsPerHour() != 6
            || wcfUncontrollableTurns() != wcfTurnsPerHour()
        )
            ++bad;
        // the extinguishing times: 5 rounds for a small fire, 1 turn for a
        // medium, 2 turns for a large
    if (wcfExtinguishSmallRounds() != 5
            || wcfExtinguishMediumTurns() != 1
            || wcfExtinguishLargeTurns() != 2
            || wcfHalveDivisor() != 2
        )
            ++bad;
        // the extinguishing times are strictly increasing measured in rounds
    if (wcfRoundsPerTurn() != 10
            || wcfExtinguishMediumTurns() * wcfRoundsPerTurn() <=
            wcfExtinguishSmallRounds()
            || wcfExtinguishLargeTurns() <= wcfExtinguishMediumTurns()
        )
            ++bad;
        // the water amounts: 1, 2 and 4 gallons, each size doubling the
        // previous
    if (wcfWaterSmallGal() != 1
            || wcfWaterMediumGal() != 2
            || wcfWaterLargeGal() != 4
            || wcfWaterMediumGal() != 2 * wcfWaterSmallGal()
            || wcfWaterLargeGal() != 2 * wcfWaterMediumGal()
        )
            ++bad;
        // the combustible-material doubling and the 1-in-10 residual chance
    if (wcfCombustibleTimeMult() != 2
            || wcfResidualRoll() != 1
            || wcfResidualDie() != 10
            || wcfResidualRoll() >= wcfResidualDie()
        )
            ++bad;
        // a campfire left alive flares up in 2d4 turns
    if (wcfFlareDice() != 2
            || wcfFlareDieSides() != 4
        )
            ++bad;
        printf("R476 WSG uncontrollable fires pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
