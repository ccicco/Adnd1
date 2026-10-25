    // ---- R489 WSG fatigue chapter pin audit ----
    // The fatigue and exhaustion chapter with the p. 87 dismount tail: the
    // close-to-the-ground flying-mount death allowing the proficient rider to
    // leap and land safely, closing the wilderness combat chapter.
    // Characters: strenuous activity past 4 turns risks fatigue (over-full
    // movement, melee, continuous climbing, swimming against a strong
    // current, severe encumbrance), 2 consecutive turns of rest avoid the
    // risk, the first Constitution Check at 6 turns, success buying 5 more
    // turns with the interval shrinking by 1 to a minimum of 1; fatigue drops
    // every ability score except comeliness by 2 until 2 consecutive hours of
    // rest, with the 18-strength, 18-constitution and 14-wisdom examples
    // (lost to-hit and reduced damage, 2 hit points per hit die at a
    // temporary 16, and both bonus 1st-level spells lost with a spell-failure
    // chance at an effective 12); checks read the current score, a further -2
    // on attacks and saves, a per-turn Constitution Check while continuing,
    // failure meaning exhaustion with another -2 and no voluntary action
    // except when failure to move risks death; 1 hour of rest plus a
    // successful check leaves only fatigue, cleared by 2 more hours; rest
    // while carried when no strength or balance is needed and no jostling
    // occurs, and rest tied to a mount moving easily over easy ground.
    // Land-based mounts: 2 days without food and water or 3 days short
    // rations fatigues, full ration plus 8 hours rest recovers, overwork
    // recovery is 12 hours plus 2 per hour overworked (the 3-hour horse
    // resting 18); the fatigued animal moves at half rate with
    // 1-round-per-turn bursts, cannot negotiate 3-inch terrain (the loaded
    // horse and the camel in very rugged ground), and is 2 armor class places
    // worse (7 to 9); only an animal-handling proficient character can calm
    // the excited fatigued animal and only at the nonproficient chance;
    // forced work risks a cumulative 20 percent exhaustion chance per hour,
    // reset by an hour of rest; the exhausted animal stops in its tracks, may
    // collapse (25 unburdened, 50 burdened, 75 overloaded), is oblivious,
    // will not panic and will not defend itself, faces a flat 50 percent
    // death chance within 1d4 hours, and drains 1d6 minus 3 hit points per
    // hour through an 8-hour critical period, regaining 2 per hour after
    // survival but still fatigued. Flying mounts: never exhausted; the
    // stamina table first number is safe flying time (reduced when heavily
    // loaded), past it a 1d10 per turn with the fatigue chance 10 minus the
    // rest number (the black dragon 24/6 fatiguing on 1-4); flying and rest
    // need not be full blocks (the 30-turn window with 24 aloft and 6 rest,
    // the 7-turn last flight risking fatigue), exceeding the safe time then
    // landing demands a full rest period; on fatigue the rate drops to
    // two-thirds with 10 yards of altitude lost per round, a same-turn safe
    // landing within 100 yards, past that a second-turn steep dive with 1d2
    // buffet damage per 10 yards dived halved for airborne-riding proficiency
    // or secure strapping, the unstrapped rider thrown for 11-40 (3d10 plus
    // 10); after landing the mount refuses flight for three times its rest
    // period (18 turns for the dragon) unless self-preservation dictates
    // otherwise, early takeoff risking fatigue every turn aloft.
    {
        using namespace rules;
        int bad = 0;
    if (wftStrenuousRiskTurns() != 4
            || wftAvoidRiskRestTurns() != 2
            || wftFirstConCheckTurns() != 6
            || wftSuccessExtraTurns() != 5
            || wftCheckStepReductionTurns() != 1
            || wftCheckIntervalMinTurns() != 1
            || wftFatigueScoreDrop() != 2
            || wftFatigueClearRestHours() != 2
            || wftExampleStrScore() != 18
            || wftExampleConScore() != 18
            || wftExampleWisScore() != 14
            || wftFatigueAtkSavePenalty() != 2
            || wftFatigueCheckEveryTurns() != 1
            || wftExhaustExtraScoreDrop() != 2
            || wftExhaustRecoverRestHours() != 1
            || wftFatigueAfterExhaustRestHours() != 2
            || wftAnimalNoFoodDays() != 2
            || wftAnimalShortRationDays() != 3
            || wftRationRecoveryRestHours() != 8
            || wftOverworkBaseRestHours() != 12
            || wftOverworkRestPerHour() != 2
            || wftHorseExampleOverworkHours() != 3
            || wftHorseExampleRestHours() != 18
            || wftAnimalFatigueMoveNum() != 1
            || wftAnimalFatigueMoveDen() != 2
            || wftBurstFullRateRoundsPerTurn() != 1
            || wftFatiguedTerrainBarInches() != 3
            || wftAnimalFatigueAcPlaces() != 2
            || wftAnimalFatigueAcFrom() != 7
            || wftAnimalFatigueAcTo() != 9
            || wftExhaustionHourChancePct() != 20
            || wftExhaustionResetRestHours() != 1
            || wftCollapseUnburdenedPct() != 25
            || wftCollapseBurdenedPct() != 50
            || wftCollapseOverloadedPct() != 75
            || wftExhaustDeathChancePct() != 50
            || wftExhaustDeathWindowDie() != 4
            || wftTraumaDie() != 6
            || wftTraumaSubtract() != 3
            || wftTraumaMaxLoss() != 3
            || wftTraumaHours() != 8
            || wftTraumaRegainPerHour() != 2
            || wftDragonSafeTurns() != 24
            || wftDragonRestTurns() != 6
            || wftDragonSafeHours() != 4
            || wftDragonRestHours() != 1
            || wftFatigueCheckDie() != 10
            || wftFatigueChanceBase() != 10
            || wftDragonFatigueRollLow() != 1
            || wftDragonFatigueRollHigh() != 4
            || wftExampleWindowTurns() != 30
            || wftExampleLastFlightTurns() != 7
            || wftFatigueMoveNum() != 2
            || wftFatigueMoveDen() != 3
            || wftFatigueLossPerRoundYards() != 10
            || wftSameTurnLandingAltitudeYards() != 100
            || wftBuffetDieSides() != 2
            || wftBuffetPerYards() != 10
            || wftThrownDmgMin() != 11
            || wftThrownDmgMax() != 40
            || wftThrownDiceCount() != 3
            || wftThrownDieSides() != 10
            || wftThrownBase() != 10
            || wftPostFatigueRestMult() != 3
            || wftDragonPostFatigueRestTurns() != 18
            || !wftOpenerThreat()
            || !wftGroundDeathProficientLeap()
            || !wftStrenuousOverfullMove()
            || !wftStrenuousMelee()
            || !wftStrenuousOtherExamples()
            || !wftCheckFailFatigued()
            || !wftIntervalShrinksPerSuccess()
            || !wftHighConEventuallyCaught()
            || !wftFatigueScoresExceptComeliness()
            || !wftStr18ExampleDetail()
            || !wftCon18ExampleDetail()
            || !wftWis14ExampleDetail()
            || !wftChecksUseReducedScores()
            || !wftFatiguedCanContinue()
            || !wftFatiguedFailExhausted()
            || !wftExhaustedOnlyDefense()
            || !wftExhaustedCannotAct()
            || !wftExhaustRecoverByCheck()
            || !wftExhaustRecoverFailLoop()
            || !wftRestWhileCarried()
            || !wftRestTiedToMount()
            || !wftAnimalCrossRefs()
            || !wftAnimalFatiguedNoFood()
            || !wftAnimalFatiguedShortRation()
            || !wftRationRecoveryNeedsBoth()
            || !wftOverworkRecoveryFormula()
            || !wftFatiguedHalfMoveWithBursts()
            || !wftFatiguedTerrainBarDetail()
            || !wftFatiguedAcWorse()
            || !wftExcitedOnlyHandlerCalms()
            || !wftWorkedFatiguedExhaustionChance()
            || !wftBriefWorkRestResets()
            || !wftExhaustedStopsInTracks()
            || !wftExhaustedCollapseOblivious()
            || !wftExhaustedNoPanicNoDefense()
            || !wftExhaustedDeathCheck()
            || !wftExhaustedTraumaDrain()
            || !wftExhaustedTraumaRecovery()
            || !wftFlyingNeverExhausted()
            || !wftStaminaTableCrossRef()
            || !wftHeavyLoadReducesSafe()
            || !wftFatigueRollPastSafe()
            || !wftFatigueChanceFormula()
            || !wftDragonExample()
            || !wftFlyingRestNotFullBlocks()
            || !wftExceedNeedsFullRest()
            || !wftTrackAloftAndRest()
            || !wftFatigueTwoThirdsMove()
            || !wftFatigueSafeLandingSameTurn()
            || !wftSecondTurnSteepDive()
            || !wftDiveBuffetDamage()
            || !wftBuffetHalvedFor()
            || !wftUnstrappedThrown()
            || !wftPostFatigueGroundRefusal()
            || !wftEarlyTakeoffFatigueRisk()
        )
            ++bad;
        // the strenuous rhythm: risk after more than 4 turns, 2 turns of rest
        // avoids it, the first Constitution Check at 6 turns, 5 more turns on
        // success, the interval shrinking by 1 to a minimum of 1
    if (wftStrenuousRiskTurns() != 4
            || wftAvoidRiskRestTurns() != 2
            || wftFirstConCheckTurns() != 6
            || wftSuccessExtraTurns() != 5
            || wftCheckStepReductionTurns() != wftCheckIntervalMinTurns()
        )
            ++bad;
        // the fatigue penalties: the score drop 2, the exhausted extra drop
        // equal to it, the attack/save penalty equal to it, and the 2-hour
        // clear equal to the post-exhaustion fatigue clear
    if (wftFatigueScoreDrop() != 2
            || wftExhaustExtraScoreDrop() != wftFatigueScoreDrop()
            || wftFatigueAtkSavePenalty() != wftFatigueScoreDrop()
            || wftFatigueClearRestHours() != wftFatigueAfterExhaustRestHours()
        )
            ++bad;
        // the example scores: strength 18, constitution 18, wisdom 14
    if (wftExampleStrScore() != 18
            || wftExampleConScore() != 18
            || wftExampleWisScore() != 14
        )
            ++bad;
        // the recovery rhythm: the fatigued check once per turn and the
        // exhausted recovery rest of 1 hour
    if (wftFatigueCheckEveryTurns() != 1
            || wftExhaustRecoverRestHours() != 1
        )
            ++bad;
        // the animal nourishment rules: 2 days without food and water, 3 days
        // short rations, 8 hours rest to recover
    if (wftAnimalNoFoodDays() != 2
            || wftAnimalShortRationDays() != 3
            || wftRationRecoveryRestHours() != 8
        )
            ++bad;
        // the overwork formula: 12 hours plus 2 per overworked hour, the
        // 3-hour horse needing 18 hours of rest
    if (wftOverworkBaseRestHours() + wftOverworkRestPerHour() *
        wftHorseExampleOverworkHours() != wftHorseExampleRestHours()
        )
            ++bad;
        // the fatigued animal effects: half movement, the 3-inch terrain bar,
        // and the armor class example 7 to 9 being exactly 2 places
    if (wftAnimalFatigueMoveNum() * 2 != wftAnimalFatigueMoveDen()
            || wftFatiguedTerrainBarInches() != 3
            || wftAnimalFatigueAcTo() - wftAnimalFatigueAcFrom() !=
            wftAnimalFatigueAcPlaces()
        )
            ++bad;
        // the exhaustion chance: 20 percent per hour cumulative, resetting
        // after a rest of at least 1 hour
    if (wftExhaustionHourChancePct() != 20
            || wftExhaustionResetRestHours() != 1
        )
            ++bad;
        // the collapse ladder: 25 unburdened, 50 with a rider or normal load,
        // 75 overloaded, in equal 25-point steps
    if (wftCollapseUnburdenedPct() + 25 != wftCollapseBurdenedPct()
            || wftCollapseBurdenedPct() + 25 != wftCollapseOverloadedPct()
        )
            ++bad;
        // the trauma rules: 1d6 minus 3 yields 0-3, the floor at zero, the
        // 8-hour critical period and the 2-per-hour regain
    if (wftTraumaDie() - wftTraumaSubtract() != wftTraumaMaxLoss()
            || wftTraumaDie() - 2 * wftTraumaSubtract() != 0
            || wftTraumaHours() != 8
            || wftTraumaRegainPerHour() != 2
        )
            ++bad;
        // the black dragon stamina: 24 turns safe, 6 turns rest, four hours
        // and one hour
    if (wftDragonSafeTurns() != 24
            || wftDragonRestTurns() != 6
            || wftDragonSafeHours() * 6 != wftDragonSafeTurns()
            || wftDragonRestTurns() != 6 * wftDragonRestHours()
        )
            ++bad;
        // the fatigue roll: 1d10 past the safe time, the chance 10 minus the
        // rest number, the dragon fatiguing on 1-4
    if (wftFatigueCheckDie() != 10
            || wftFatigueChanceBase() - wftDragonRestTurns() !=
            wftDragonFatigueRollHigh()
            || wftDragonFatigueRollLow() != 1
            || wftDragonFatigueRollHigh() != 4
        )
            ++bad;
        // the non-block example: the 30-turn window holding 24 aloft and 6
        // rest, and the 7-turn last flight risking the fatigue
    if (wftExampleWindowTurns() - wftDragonSafeTurns() != wftDragonRestTurns()
            || wftExampleLastFlightTurns() != 7
        )
            ++bad;
        // the fatigued flying mount: two-thirds movement, 10 yards lost per
        // round, the same-turn safe landing bar at 100 yards
    if (wftFatigueMoveNum() * 3 != wftFatigueMoveDen() * 2
            || wftFatigueLossPerRoundYards() != 10
            || wftSameTurnLandingAltitudeYards() != 100
        )
            ++bad;
        // the dive damage: 1d2 per 10 yards dived, the thrown rider at 11-40
        // which is exactly 3d10 plus 10
    if (wftBuffetDieSides() != 2
            || wftBuffetPerYards() != 10
            || wftThrownDiceCount() * wftThrownDieSides() + wftThrownBase() !=
            wftThrownDmgMax()
            || wftThrownDmgMin() != wftThrownBase() + 1
        )
            ++bad;
        // the post-fatigue rest: three times the normal rest period, 18 turns
        // for the black dragon
    if (wftPostFatigueRestMult() * wftDragonRestTurns() !=
        wftDragonPostFatigueRestTurns()
            || wftDragonPostFatigueRestTurns() != 18
        )
            ++bad;
        printf("R489 WSG fatigue chapter pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
