    // ---- R501 WSG movement fall fold audit ----
    // The WSG movement/fall-chain fold, the third seam round after gap
    // closure: no new book pages, the R499 pattern applied to the
    // climbing-and-falling chapter. One falling character flows through seven
    // landed headers: the climbing ratings (rules/wsgclimb.h R435: the 40
    // percent non-thief, the 80 percent mountaineer, the fall chance as 100
    // minus the rating), the Table 17 fall ladder (rules/wsgfall.h R437: the
    // six bands 1, 3, 6, 10, 15, 20 dice, the 1000-foot free-fall rate, the
    // 600-800 severe slope), the tumble rates (rules/wsgtumble.h R438: the
    // 10-foot abrasion granularity, the 100-300 gentle and 300-500 moderate
    // rates), the stop windows (rules/wsgstop.h R439: 50 feet cliff or
    // severe, 75 moderate, 100 gentle), the jump floors (rules/wsgjump.h
    // R448: the 2-foot broad and 1-foot high floors, the 20-foot run, the 1d3
    // heap at 5 feet), the slippery-surface cadence (rules/wsgslip.h R447:
    // the five-segment run check, the half-rate caution) and the airborne
    // fall chance (rules/wsgfallair.h R461: the zero base, the -200/-150
    // straps, the -50 proficiency, the -10 saddle and stirrups). The
    // findings: the Table 17 dice are the triangular numbers (increments 2,
    // 3, 4, 5) and the 51-or-more band caps at 20d6 ONE DIE SHORT of the pure
    // sequence value 21; the prose linear 1d6-per-10-feet understates the
    // printed table (3d6 at 20 feet, not 2d6); the cliff/severe stop window
    // of 50 feet is exactly the top of the 41-50 damage band; the gentle stop
    // window equals the gentle tumble rate minimum; the rate ladder is
    // contiguous (100-300, 300-500, 600-800, 1000); and the horizontal slip
    // deals no direct damage while the inclined tumble abrasion kills.
    {
        using namespace rules;
        int bad = 0;
    if (wmvFallBandCount() != 6
            || wmvFallFirstBandFt() != 10
            || wmvFallOpenBandFt() != 51
            || wmvFallDiceB0() != 1
            || wmvFallDiceB1() != 3
            || wmvFallDiceB2() != 6
            || wmvFallDiceB3() != 10
            || wmvFallDiceB4() != 15
            || wmvFallDiceB5() != 20
            || wmvMaxFallDice() != 20
            || wmvFreeFallRate() != 1000
            || wmvSevereRateMin() != 600
            || wmvSevereRateMax() != 800
            || wmvAbrasionPerFt() != 10
            || wmvGentleTumbleMin() != 100
            || wmvGentleTumbleMax() != 300
            || wmvModerateTumbleMin() != 300
            || wmvModerateTumbleMax() != 500
            || wmvStopCliffSevereFt() != 50
            || wmvStopModerateFt() != 75
            || wmvStopGentleFt() != 100
            || wmvNonThiefRating() != 40
            || wmvMountaineerRating() != 80
            || wmvFallBase() != 100
            || wmvRunRequiredFt() != 20
            || wmvRunningAdvantageFt() != 4
            || wmvHeapDmgDie() != 3
            || wmvHeapMinFt() != 5
            || wmvStandFloorFt() != 2
            || wmvHighFloorFt() != 1
            || wmvHighHorizDiv() != 2
            || wmvSlipRunCheckSegs() != 5
            || wmvCautiousRateDiv() != 2
            || wmvAirBaseFallPct() != 0
            || wmvStrapFullBodyPct() != -200
            || wmvStrapLowerBodyPct() != -150
            || wmvAirborneProfPct() != -50
            || wmvSaddlePct() != -10
            || wmvStirrupsPct() != -10
            || !wmvDiceLadderTriangular()
            || !wmvCapBreaksSequence()
            || !wmvProseVsTableTension()
            || !wmvStopWindowBandTop()
            || !wmvGentleWindowEqualsRate()
            || !wmvRateLadderContiguous()
            || !wmvTenFootGranularity()
            || !wmvSlipHarmlessTumbleDeadly()
            || !wmvClimbFallIsComplement()
            || !wmvAirLadderOrdered()
        )
            ++bad;
        // the Table 17 dice ladder
    if (wmvFallBandCount() != 6
            || wmvFallDiceB0() != 1
            || wmvFallDiceB1() != 3
            || wmvFallDiceB2() != 6
            || wmvFallDiceB3() != 10
            || wmvFallDiceB4() != 15
            || wmvFallDiceB5() != 20
        )
            ++bad;
        // the ladder is triangular: each band adds one more die than the
        // previous band added
    if (wmvFallDiceB1() - wmvFallDiceB0() != 2
            || wmvFallDiceB2() - wmvFallDiceB1() != 3
            || wmvFallDiceB3() - wmvFallDiceB2() != 4
            || wmvFallDiceB4() - wmvFallDiceB3() != 5
        )
            ++bad;
        // the cap breaks the sequence: the last increment repeats instead of
        // stepping to six - 20, not 21
    if (wmvFallDiceB5() - wmvFallDiceB4() != 5
            || wmvFallDiceB5() == wmvFallDiceB4() + 6
            || wmvMaxFallDice() != wmvFallDiceB5()
        )
            ++bad;
        // the open band opens one foot past the stop window
    if (wmvFallOpenBandFt() - wmvStopCliffSevereFt() != 1
        )
            ++bad;
        // the gentle stop window equals the gentle tumble rate minimum
    if (wmvStopGentleFt() != wmvGentleTumbleMin()
        )
            ++bad;
        // the rate ladder is contiguous and strictly ascending
    if (wmvGentleTumbleMax() != wmvModerateTumbleMin()
            || wmvModerateTumbleMax() >= wmvSevereRateMin()
            || wmvSevereRateMax() >= wmvFreeFallRate()
        )
            ++bad;
        // the climb fall chance is the complement of the rating
    if (wmvFallBase() - wmvNonThiefRating() != 60
            || wmvFallBase() - wmvMountaineerRating() != 20
        )
            ++bad;
        // the jump floors and the heap
    if (wmvStandFloorFt() != 2
            || wmvHighFloorFt() != 1
            || wmvHeapMinFt() != 5
            || wmvHeapDmgDie() != 3
            || wmvRunRequiredFt() != 20
        )
            ++bad;
        // the slip cadence and the cautious divisor
    if (wmvSlipRunCheckSegs() != 5
            || wmvCautiousRateDiv() != 2
        )
            ++bad;
        // the airborne reduction ladder is ordered
    if (wmvStrapFullBodyPct() + 200 != 0
            || wmvStrapLowerBodyPct() + 150 != 0
            || wmvAirborneProfPct() + 50 != 0
            || wmvSaddlePct() != wmvStirrupsPct()
            || wmvAirBaseFallPct() != 0
            || wmvStrapFullBodyPct() >= wmvStrapLowerBodyPct()
        )
            ++bad;
        // the ten-foot granularity shared by the fall and the tumble
    if (wmvAbrasionPerFt() != 10
            || wmvFallFirstBandFt() != 10
        )
            ++bad;
        // the moderate stop window sits between its neighbors
    if (wmvStopModerateFt() - wmvStopCliffSevereFt() != 25
            || wmvStopGentleFt() - wmvStopModerateFt() != 25
        )
            ++bad;
        printf("R501 WSG movement fall fold audit: bad %d\n", bad);
        if (bad) return 1;
    }
