    // ---- R508 DSG battlesystem audit ----
    // The DSG Battlesystem options underground pins the dismount tail (the
    // footman pull-down at -2 below 6 inches per round, -4 at 7-12, -6 above
    // 12, the free steed attacks on a fast miss, the -1 per additional
    // footman up to 4, the no-damage multi-person cushion, the
    // eight-man-sized-or-four-large surround, and the stake defenses - two
    // characters one hour per 10-foot square of 4-5 foot stakes, the
    // horsemanship check to enter, the 1d4-1 stakes per 10-foot depth, the
    // chain -1 and plate -2 barding reductions, the 2d6 per stake), the
    // opener (any Battlesystem scenario if all agree), the narrow frontages
    // (the 1/2- and 3/4-inch bottleneck figures), the combat modifiers (the
    // 10% wounded marker vs 25% standard, the orc figure at 1-9 dice wounded,
    // 10 or more removed), the formation modifiers (the column formation with
    // command radius at the head and no facing penalty, open for morale, the
    // 1-inch-10-yards scale, the twice-lengthwise shape change with the extra
    // space to the back, the doubled spacing in narrower corridors), the
    // morale effects (the no-room auto-rout, the blocked-routing chain
    // reaction), the ventilation effects (the doubled gas duration, the p. 36
    // smoke cross-ref, the wind-carried spell gas at 1/2 the area diameter
    // lasting twice the duration), the flying effects (the 240-foot normal
    // band, the 60-240 altitude thirds, the 30-60 medium-and-low split, the
    // under-30 low-only rule), the line-of-sight effects (the +6 Attack
    // Rating composite of the -4 attacks and damage, the -4 saves, the +4 AC
    // vs melee, the 1/3 movement, the automatic first-rank obstacle hit, the
    // one light per figure with the 24-figure example, the +2 missile benefit
    // against illuminated units, the skirmisher exemption) and the cave-ins
    // (the 6d8 collapse halved on a save with the plus-1-inch area and the
    // 60-dice orc example, the 4d8 mud fall, the 1% base chance, the +4%
    // cumulative increase per sub-25 survived check, the heavy-unit 13-to-26
    // doubling and the direct-hit and adjacent-collapse doublings).
    {
        using namespace rules;
        int bad = 0;
    if (dnrPullSlowMaxInches() != 6
            || dnrPullSlowPenalty() != 2
            || dnrPullMidMinInches() != 7
            || dnrPullMidMaxInches() != 12
            || dnrPullMidPenalty() != 4
            || dnrPullFastMinInches() != 12
            || dnrPullFastPenalty() != 6
            || dnrPullExtraFootmanMax() != 4
            || dnrPullExtraFootmanPenalty() != 1
            || dnrPullSurroundManSizedCount() != 8
            || dnrPullSurroundLargeCount() != 4
            || dnrStakesPrepCharacters() != 2
            || dnrStakesPrepHours() != 1
            || dnrStakesAreaFeetSq() != 10
            || dnrStakesLengthLoFt() != 4
            || dnrStakesLengthHiFt() != 5
            || dnrStakesHitDiceMinus() != 1
            || dnrStakesHitDiceSides() != 4
            || dnrStakesPerDepthFt() != 10
            || dnrStakesBardingChainReduction() != 1
            || dnrStakesBardingPlateReduction() != 2
            || dnrStakeDamageDice() != 2
            || dnrStakeDamageSides() != 6
            || dnrFrontNarrowFigureHalfInch() != 2
            || dnrFrontNarrowFigureThreeQuarter() != 3
            || dnrWoundedThresholdPct() != 10
            || dnrWoundedStandardPct() != 25
            || dnrWoundedOrcFigureOrcs() != 10
            || dnrWoundedOrcFigureHitDice() != 10
            || dnrWoundedOrcWoundedLoDice() != 1
            || dnrWoundedOrcWoundedHiDice() != 9
            || dnrWoundedRemovedDice() != 10
            || dnrScaleInchYards() != 10
            || dnrFigureLengthwiseMult() != 2
            || dnrVentGasDurationMult() != 2
            || dnrVentSmokeRefPage() != 36
            || dnrVentSpellGasMaxDiameterFrac() != 2
            || dnrFlyNormalMinCeilingFt() != 240
            || dnrFlyThirdsMinCeilingFt() != 60
            || dnrFlyTwoBandMinCeilingFt() != 30
            || dnrLosArPenalty() != 6
            || dnrLosSavePenalty() != 4
            || dnrLosAcMeleePenalty() != 4
            || dnrLosMoveMultDen() != 3
            || dnrLosLightExampleFigures() != 24
            || dnrLosLitMissileArBonus() != 2
            || dnrCaveinPlusInches() != 1
            || dnrCaveinDamageDice() != 6
            || dnrCaveinDamageSides() != 8
            || dnrCaveinOrcFigureDice() != 60
            || dnrCaveinMudDamageDice() != 4
            || dnrCaveinMudDamageSides() != 8
            || dnrCaveinBasePct() != 1
            || dnrCaveinCumulativeRollBelow() != 25
            || dnrCaveinCumulativePlusPct() != 4
            || dnrCaveinHeavyExamplePct() != 13
            || dnrCaveinHeavyExampleDoubledPct() != 26
            || !dnrFootmanPullManSizedOnly()
            || !dnrFootmanPullLargerCountTwoMen()
            || !dnrFootmanGrabAsPasses()
            || !dnrPullHitFollowsGrappleProcedure()
            || !dnrPullMissFastFreeAttacks()
            || !dnrPullMultiPersonNoDamage()
            || !dnrPullBothMountAndRider()
            || !dnrPullBothKeepNormalAttacks()
            || !dnrSetDefensesPreparable()
            || !dnrSetDefensesSimpleTricks()
            || !dnrSetDefensesDmChance()
            || !dnrStakesSharpened()
            || !dnrStakesNeedSaplings()
            || !dnrStakesEasilySpotted()
            || !dnrStakesEnterHorsemanshipCheck()
            || !dnrStakesCheckFailRefuses()
            || !dnrStakesCheckSuccessEnters()
            || !dnrStakeDamageChargingOrNot()
            || !dnrBsBattlesCommonUnderground()
            || !dnrBsMassCombatInstrument()
            || !dnrBsConstrictedNewTactics()
            || !dnrBsDarknessFlyingNovel()
            || !dnrBsForUnderearthBattlefields()
            || !dnrBsClarifiesIndoorWarfare()
            || !dnrBsAnyScenarioIfAllAgree()
            || !dnrFrontBottleneckHoldsGap()
            || !dnrFrontDesignedSeveralFigures()
            || !dnrFrontModifyOneOrTwo()
            || !dnrWoundedStricterThanStandard()
            || !dnrWoundedBelowOneDieNoEffect()
            || !dnrColTunnelsForceColumns()
            || !dnrColOneFigureWide()
            || !dnrColCommandRadiusAtHead()
            || !dnrColNoFacingPenalty()
            || !dnrColOpenForMorale()
            || !dnrScaleHalflingCannotOccupy()
            || !dnrFigureChangesShape()
            || !dnrFigureOccupiesMoreFrontToBack()
            || !dnrFigureExtraSpaceToBack()
            || !dnrFigureAdjacentInFront()
            || !dnrFigureRearApproachLimit()
            || !dnrColNarrowerFiguresSpread()
            || !dnrColNarrowerDoublesLength()
            || !dnrMoraleClosedBreaksHarmful()
            || !dnrMoraleExpandSidesFrontRear()
            || !dnrMoraleNoRoomAutoRouts()
            || !dnrMoraleRoutingBlockedRoutesBlocker()
            || !dnrMoraleChainReaction()
            || !dnrVentGoodCirculationSkip()
            || !dnrVentAirSlowerUnderground()
            || !dnrVentSmokeMajorProblem()
            || !dnrVentSpellGasWindCarried()
            || !dnrVentWindCarryDurationDoubled()
            || !dnrVentWindCarryAffectsPath()
            || !dnrFlyLargeCavernsAllowFlight()
            || !dnrFlyMayNotEscapeUpward()
            || !dnrFlyThirdsMapping()
            || !dnrFlyTwoBandOnly()
            || !dnrFlyLowOnlyUnderThirty()
            || !dnrFlyManeuverabilityCritical()
            || !dnrLosBlackerThanNightBattles()
            || !dnrLosNeedFireMagicPhosphorescence()
            || !dnrLosArCompositesAttacksDamage()
            || !dnrLosObstacleFirstRankAuto()
            || !dnrLosObstaclePushExplanation()
            || !dnrLosOneLightPerFigure()
            || !dnrLosLitMovesNormal()
            || !dnrLosLitMeleesNormal()
            || !dnrLosLitSavesNormal()
            || !dnrLosLitNoMissilesAtUnseen()
            || !dnrLosLitNoChargeBeyondVision()
            || !dnrLosLitEasilySeen()
            || !dnrSkirmishersIlluminateTargets()
            || !dnrSkirmishersNoLitPenalty()
            || !dnrCaveinSpellsHighDemand()
            || !dnrCaveinEarthquakeCommon()
            || !dnrCaveinAreaPlusInch()
            || !dnrCaveinSaveHalves()
            || !dnrCaveinOrcFigureDestroyed()
            || !dnrCaveinMudSaveHalves()
            || !dnrCaveinUnstableDmDiscretion()
            || !dnrCaveinColumnsArchesCracked()
            || !dnrCaveinSpellsTrigger()
            || !dnrCaveinSecretCheck()
            || !dnrCaveinCumulativeEffect()
            || !dnrCaveinHeavyUnitsDouble()
            || !dnrCaveinDirectSpellHitDoubles()
            || !dnrCaveinAdjacentCollapseDoubles()
        )
            ++bad;
        // the pull-down speed bands: -2 at 6 or less, -4 at 7-12, -6 above 12
        // inches per round.
    if (dnrPullSlowMaxInches() != 6
            || dnrPullSlowPenalty() != 2
            || dnrPullMidMinInches() != 7
            || dnrPullMidMaxInches() != 12
            || dnrPullMidPenalty() != 4
            || dnrPullFastMinInches() != 12
            || dnrPullFastPenalty() != 6
        )
            ++bad;
        // the pull-down penalty ladder steps by 2: -2, -4, -6.
    if (dnrPullSlowPenalty() + 2 != dnrPullMidPenalty()
            || dnrPullMidPenalty() + 2 != dnrPullFastPenalty()
        )
            ++bad;
        // each additional footman up to 4 applies -1 to the rider's
        // Proficiency Check.
    if (dnrPullExtraFootmanMax() != 4
            || dnrPullExtraFootmanPenalty() != 1
        )
            ++bad;
        // the surround counts: eight man-sized or four large creatures pull
        // down both mount and rider.
    if (dnrPullSurroundManSizedCount() != 8
            || dnrPullSurroundLargeCount() != 4
        )
            ++bad;
        // the stakes: two characters, one hour, a 10-foot-square area, 4-5
        // foot stakes.
    if (dnrStakesPrepCharacters() != 2
            || dnrStakesPrepHours() != 1
            || dnrStakesAreaFeetSq() != 10
            || dnrStakesLengthLoFt() != 4
            || dnrStakesLengthHiFt() != 5
        )
            ++bad;
        // the stakes hit 1d4-1 per 10-foot depth of the defenses.
    if (dnrStakesHitDiceSides() != 4
            || dnrStakesHitDiceMinus() != 1
            || dnrStakesPerDepthFt() != 10
        )
            ++bad;
        // barding reductions: -1 chain mail, -2 plate.
    if (dnrStakesBardingChainReduction() != 1
            || dnrStakesBardingPlateReduction() != 2
        )
            ++bad;
        // each stake deals 2d6 to the mount, charging or not.
    if (dnrStakeDamageDice() != 2
            || dnrStakeDamageSides() != 6
        )
            ++bad;
        // the underground wounded marker at 10% vs the standard 25%.
    if (dnrWoundedThresholdPct() != 10
            || dnrWoundedStandardPct() != 25
        )
            ++bad;
        // the orc-figure example: 10 orcs / 10 HD, 1-9 dice wounds, 10+ dice
        // removes.
    if (dnrWoundedOrcFigureOrcs() != 10
            || dnrWoundedOrcFigureHitDice() != 10
            || dnrWoundedOrcWoundedLoDice() != 1
            || dnrWoundedOrcWoundedHiDice() != 9
            || dnrWoundedRemovedDice() != 10
        )
            ++bad;
        // the scale 1 inch = 10 yards; the tight-confines figure doubles its
        // lengthwise space.
    if (dnrScaleInchYards() != 10
            || dnrFigureLengthwiseMult() != 2
        )
            ++bad;
        // gas duration doubled underground, the smoke cross-ref p. 36, the
        // wind-carry case at 1/2 the area-of-effect diameter.
    if (dnrVentGasDurationMult() != 2
            || dnrVentSmokeRefPage() != 36
            || dnrVentSpellGasMaxDiameterFrac() != 2
        )
            ++bad;
        // the flying ceiling bands: 240 normal, 60-240 thirds, 30-60 medium
        // and low, under 30 low only.
    if (dnrFlyNormalMinCeilingFt() != 240
            || dnrFlyThirdsMinCeilingFt() != 60
            || dnrFlyTwoBandMinCeilingFt() != 30
        )
            ++bad;
        // the line-of-sight penalties: +6 AR, -4 saves, +4 AC vs melee, 1/3
        // movement, +2 against illuminated units, the 24-figure example.
    if (dnrLosArPenalty() != 6
            || dnrLosSavePenalty() != 4
            || dnrLosAcMeleePenalty() != 4
            || dnrLosMoveMultDen() != 3
            || dnrLosLitMissileArBonus() != 2
            || dnrLosLightExampleFigures() != 24
        )
            ++bad;
        // the darkness save penalty equals the AC-vs-melee penalty: both 4.
    if (dnrLosSavePenalty() != dnrLosAcMeleePenalty()
        )
            ++bad;
        // the ceiling collapse: 6d8 damage, the area plus 1 inch in all
        // directions.
    if (dnrCaveinDamageDice() != 6
            || dnrCaveinDamageSides() != 8
            || dnrCaveinPlusInches() != 1
        )
            ++bad;
        // the worked example: the 10-orc figure suffers 60 dice and is
        // destroyed save or not.
    if (dnrCaveinOrcFigureDice() != 60
            || dnrCaveinOrcFigureDestroyed() != 1
        )
            ++bad;
        // the falling-mud damage: 4d8, halved on a save.
    if (dnrCaveinMudDamageDice() != 4
            || dnrCaveinMudDamageSides() != 8
        )
            ++bad;
        // the collapse and mud-fall damage dice are both d8.
    if (dnrCaveinMudDamageSides() != dnrCaveinDamageSides()
        )
            ++bad;
        // the fragile-formation collapse: base 1%, +4% cumulative per sub-25
        // survived check.
    if (dnrCaveinBasePct() != 1
            || dnrCaveinCumulativeRollBelow() != 25
            || dnrCaveinCumulativePlusPct() != 4
        )
            ++bad;
        // the heavy-unit doubling example: 13% becomes 26% under galloping
        // heavy cavalry.
    if (dnrCaveinHeavyExamplePct() != 13
            || dnrCaveinHeavyExampleDoubledPct() != 26
        )
            ++bad;
        // the heavy-unit example is a true doubling: 26 = 13 + 13.
    if (dnrCaveinHeavyExampleDoubledPct() - dnrCaveinHeavyExamplePct() !=
        dnrCaveinHeavyExamplePct()
        )
            ++bad;
        printf("R508 DSG battlesystem audit: bad %d\n", bad);
        if (bad) return 1;
    }
