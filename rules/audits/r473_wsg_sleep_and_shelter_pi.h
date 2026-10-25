    // ---- R473 WSG sleep and shelter pin audit ----
    // The Table 37 grid (the five average-rest bands by eight effect columns:
    // the Dexterity, Strength, Wisdom and Constitution check ladders, the
    // to-hit penalties, the Climbing and Movement reductions, the Weight
    // Allowance multiples), the shelter kit descriptions, the occupancy
    // rulings, the setup and takedown discipline, the moisture and wind
    // resistance semantics, the life span point economy with the category
    // degradation, the 16-hour active day with the 5-hour sleep requirement,
    // the two-day trigger with the one-night negation and the movement rate
    // semantics - every const, bool and table cell verified against the
    // model.
    {
        using namespace rules;
        int bad = 0;
    if (wrsAdequateMinPoles() != 2
            || wrsGoodMinPoles() != 4
            || wrsSuperiorMinPoles() != 6
            || wrsSmallComfort() != 1
            || wrsMediumComfort() != 2
            || wrsLargeDesign() != 4
            || wrsLargeSleepMax() != 6
            || wrsLargeCloseMax() != 8
            || wrsSetupHelperSaving() != 1
            || wrsSetupMinSmallTurns() != 1
            || wrsSetupMinMediumTurns() != 2
            || wrsSetupMinLargeTurns() != 3
            || wrsTakedownSavingTurns() != 1
            || wrsTakedownMinSmallRounds() != 5
            || wrsTakedownMinMediumTurns() != 1
            || wrsTakedownMinLargeTurns() != 2
            || wrsWindStepMph() != 10
            || wrsWindLeakMph() != 5
            || wrsWindDamageThresholdMult() != 2
            || wrsWindDamagePctPerStep() != 25
            || wrsWindExPoorRes() != 20
            || wrsWindEx30Leak() != 5
            || wrsWindEx40Leak() != 10
            || wrsWindEx50Leak() != 15
            || wrsWindEx60Leak() != 20
            || wrsWindEx50DamagePct() != 25
            || wrsWindEx60DamagePct() != 50
            || wrsLifespanSetupsPerPoint() != 3
            || wrsLifespanWindPoints() != 1
            || wrsLifespanEqualPrecipPoints() != 2
            || wrsLifespanGreaterPrecipPoints() != 4
            || wrsPoorLifespanMax() != 40
            || wrsPoorUselessAt() != 20
            || wrsMaxActiveHours() != 16
            || wrsCampChoreHours() != 3
            || wrsSleepHoursNeeded() != 5
            || wrsTriggerDays() != 2
            || wrsExMoveRate() != 12
            || wrsExHalfDayMiles() != 6
            || wrsSleepBands() != 5
            || wrsRowCount() != 5
            || !wrsPoorKitLooseStitching()
            || !wrsPoorKitBringYourOwn()
            || !wrsAdequateKitTighter()
            || !wrsGoodKitShingled()
            || !wrsSuperiorKitStructure()
            || !wrsSmallCloseQuarters()
            || !wrsMediumCloseQuarters()
            || !wrsLargeCloseQuartersOnly8()
            || !wrsSetupAssumesRope()
            || !wrsRopeUseHalvesSetup()
            || !wrsTakedownNoHelperBonus()
            || !wrsRopeUseHalvesTakedown()
            || !wrsMoistureOneStepLighter()
            || !wrsSuperiorDownpourCaveat()
            || !wrsWindLeakRule()
            || !wrsWindDamageUseless()
            || !wrsLifespanAsHitPoints()
            || !wrsCategoryDegradation()
            || !wrsPoorHalfUseless()
            || !wrsLifespanHazards()
            || !wrsActiveTimeCap()
            || !wrsSleepRiskHidden()
            || !wrsTwoDayTrigger()
            || !wrsDayByDayCalc()
            || !wrsOneNightNegation()
            || !wrsCheckModifierOnRoll()
            || !wrsMoveReductionAfterAdjustments()
            || !wrsCombatMoveExempt()
        )
            ++bad;
        // Table 37: effects of lack of sleep, the five average-rest bands by
        // eight effect columns (the ability check ladders, the to-hit
        // penalties, the climbing and movement reductions, the weight
        // allowance multiples), printed p. 64
        int C37[5][8] = {
            {1,0,0,0,0,0,0,0},
            {2,1,0,0,-1,0,0,0},
            {3,2,1,0,-1,-10,-25,0},
            {4,3,2,1,-2,-20,-33,50},
            {5,4,3,2,-3,-30,-50,100},
            };
        int n37[8] = {0,0,0,0,0,0,0,0};
        int e37[8] = {0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < wrsRowCount();
             ++b) {
            int vals[8];
            vals[0] = wrsDexCheck(b);
            vals[1] = wrsStrCheck(b);
            vals[2] = wrsWisCheck(b);
            vals[3] = wrsConCheck(b);
            vals[4] = wrsToHit(b);
            vals[5] = wrsClimbPct(b);
            vals[6] = wrsMovePct(b);
            vals[7] = wrsWtMult(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C37[b][c])
                    ++bad;
                if (vals[c] == 999)
                    ++n37[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (n37[c] != e37[c])
                ++bad;
        // the pole kits: 2 adequate, 4 good, 6 superior, each strictly more
        // than the last
    if (wrsAdequateMinPoles() != 2
            || wrsGoodMinPoles() != 4
            || wrsSuperiorMinPoles() != 6
            || wrsAdequateMinPoles() >= wrsGoodMinPoles()
            || wrsGoodMinPoles() >= wrsSuperiorMinPoles()
        )
            ++bad;
        // the occupancy ladder: 1 small, 2 medium, 4 large by design with the
        // 6 sleep and 8 close-quarters caps
    if (wrsSmallComfort() != 1
            || wrsMediumComfort() != 2
            || wrsLargeDesign() != 4
            || wrsLargeSleepMax() != 6
            || wrsLargeCloseMax() != 8
            || wrsLargeDesign() >= wrsLargeSleepMax()
            || wrsLargeSleepMax() >= wrsLargeCloseMax()
        )
            ++bad;
        // the setup minimums: 1/2/3 turns by size and the 1-turn helper
        // saving
    if (wrsSetupMinSmallTurns() != 1
            || wrsSetupMinMediumTurns() != 2
            || wrsSetupMinLargeTurns() != 3
            || wrsSetupHelperSaving() != 1
            || wrsSetupMinSmallTurns() >= wrsSetupMinMediumTurns()
            || wrsSetupMinMediumTurns() >= wrsSetupMinLargeTurns()
        )
            ++bad;
        // the takedown: 1 turn less than setup with the 5-round small and
        // 1/2-turn medium/large minimums
    if (wrsTakedownSavingTurns() != 1
            || wrsTakedownMinSmallRounds() != 5
            || wrsTakedownMinMediumTurns() != 1
            || wrsTakedownMinLargeTurns() != 2
            || wrsTakedownMinMediumTurns() >= wrsTakedownMinLargeTurns()
        )
            ++bad;
        // the wind machinery: the 10-mph step, the 5-mph leak, the
        // twice-threshold and the 25% damage chance
    if (wrsWindStepMph() != 10
            || wrsWindLeakMph() != 5
            || wrsWindDamageThresholdMult() != 2
            || wrsWindDamagePctPerStep() != 25
        )
            ++bad;
        // the book wind example: the 20-mph poor shelter leaks 5/10/15/20 mph
        // at 30/40/50/60 mph, damage 25% then 50%
    if (wrsWindExPoorRes() != 20
            || wrsWindEx30Leak() != 5
            || wrsWindEx40Leak() != 10
            || wrsWindEx50Leak() != 15
            || wrsWindEx60Leak() != 20
            || wrsWindEx50DamagePct() != 25
            || wrsWindEx60DamagePct() != 50
            || wrsWindEx30Leak() >= wrsWindEx40Leak()
            || wrsWindEx40Leak() >= wrsWindEx50Leak()
            || wrsWindEx50Leak() >= wrsWindEx60Leak()
            || wrsWindEx50DamagePct() >= wrsWindEx60DamagePct()
        )
            ++bad;
        // the life span point rates: 1 per 3 setups, 1 per non-damaging
        // over-wind, 2 equal precip, 4 greater
    if (wrsLifespanSetupsPerPoint() != 3
            || wrsLifespanWindPoints() != 1
            || wrsLifespanEqualPrecipPoints() != 2
            || wrsLifespanGreaterPrecipPoints() != 4
            || wrsLifespanWindPoints() >= wrsLifespanEqualPrecipPoints()
            || wrsLifespanEqualPrecipPoints() >=
            wrsLifespanGreaterPrecipPoints()
        )
            ++bad;
        // the poor shelter collapse: half of 40 is 20
    if (wrsPoorLifespanMax() != 40
            || wrsPoorUselessAt() != 20
            || wrsPoorUselessAt() >= wrsPoorLifespanMax()
        )
            ++bad;
        // the rest day: 16 hours active, 3 hours of chores, 5 hours of sleep
    if (wrsMaxActiveHours() != 16
            || wrsCampChoreHours() != 3
            || wrsSleepHoursNeeded() != 5
        )
            ++bad;
        // the two-day trigger
    if (wrsTriggerDays() != 2
        )
            ++bad;
        // the book movement example: 12 down to 6 miles per half-day
    if (wrsExMoveRate() != 12
            || wrsExHalfDayMiles() != 6
            || wrsExHalfDayMiles() >= wrsExMoveRate()
        )
            ++bad;
        // the kit mechanics: the poor loose kit, the adequate tight one, the
        // good shingles, the superior true structure
    if (wrsPoorKitLooseStitching() != 1
            || wrsPoorKitBringYourOwn() != 1
            || wrsAdequateKitTighter() != 1
            || wrsGoodKitShingled() != 1
            || wrsSuperiorKitStructure() != 1
        )
            ++bad;
        // the occupancy rulings: small and medium close quarters, the large
        // eight cap
    if (wrsSmallCloseQuarters() != 1
            || wrsMediumCloseQuarters() != 1
            || wrsLargeCloseQuartersOnly8() != 1
        )
            ++bad;
        // the setup and takedown rope rules
    if (wrsSetupAssumesRope() != 1
            || wrsRopeUseHalvesSetup() != 1
            || wrsTakedownNoHelperBonus() != 1
            || wrsRopeUseHalvesTakedown() != 1
        )
            ++bad;
        // the moisture and wind rulings
    if (wrsMoistureOneStepLighter() != 1
            || wrsSuperiorDownpourCaveat() != 1
            || wrsWindLeakRule() != 1
            || wrsWindDamageUseless() != 1
        )
            ++bad;
        // the life span rulings: hit points, degradation, the poor collapse,
        // the mishap caveats
    if (wrsLifespanAsHitPoints() != 1
            || wrsCategoryDegradation() != 1
            || wrsPoorHalfUseless() != 1
            || wrsLifespanHazards() != 1
        )
            ++bad;
        // the rest and sleep discipline: the active-time definition, the
        // hidden risk, the day-by-day calc and the negation
    if (wrsActiveTimeCap() != 1
            || wrsSleepRiskHidden() != 1
            || wrsDayByDayCalc() != 1
            || wrsOneNightNegation() != 1
        )
            ++bad;
        // the check and movement semantics with the combat exemption
    if (wrsCheckModifierOnRoll() != 1
            || wrsMoveReductionAfterAdjustments() != 1
            || wrsCombatMoveExempt() != 1
        )
            ++bad;
        // the Dexterity ladder: +1 through +5, the only entry in the
        // less-than-5 band
    if (wrsDexCheck(0) != 1
            || wrsDexCheck(1) != 2
            || wrsDexCheck(2) != 3
            || wrsDexCheck(3) != 4
            || wrsDexCheck(4) != 5
        )
            ++bad;
        // the Strength ladder: nothing in the top band, +1 through +4 below
        // it
    if (wrsStrCheck(0) != 0
            || wrsStrCheck(1) != 1
            || wrsStrCheck(2) != 2
            || wrsStrCheck(3) != 3
            || wrsStrCheck(4) != 4
        )
            ++bad;
        // the Wisdom ladder: entering at less-than-3 with +1, +2, +3
    if (wrsWisCheck(0) != 0
            || wrsWisCheck(1) != 0
            || wrsWisCheck(2) != 1
            || wrsWisCheck(3) != 2
            || wrsWisCheck(4) != 3
        )
            ++bad;
        // the Constitution ladder: only the bottom two bands, +1 and +2
    if (wrsConCheck(0) != 0
            || wrsConCheck(1) != 0
            || wrsConCheck(2) != 0
            || wrsConCheck(3) != 1
            || wrsConCheck(4) != 2
        )
            ++bad;
        // the to-hit ladder: none, -1, -1, -2, -3
    if (wrsToHit(0) != 0
            || wrsToHit(1) != -1
            || wrsToHit(2) != -1
            || wrsToHit(3) != -2
            || wrsToHit(4) != -3
        )
            ++bad;
        // the Climbing Rating reductions: -10/-20/-30 percent in the bottom
        // three bands
    if (wrsClimbPct(0) != 0
            || wrsClimbPct(1) != 0
            || wrsClimbPct(2) != -10
            || wrsClimbPct(3) != -20
            || wrsClimbPct(4) != -30
        )
            ++bad;
        // the Movement Rate reductions: -25/-33/-50 percent in the bottom
        // three bands
    if (wrsMovePct(0) != 0
            || wrsMovePct(1) != 0
            || wrsMovePct(2) != -25
            || wrsMovePct(3) != -33
            || wrsMovePct(4) != -50
        )
            ++bad;
        // the Weight Allowance penalty multiples of Strength: 50 and 100 in
        // the bottom two bands
    if (wrsWtMult(0) != 0
            || wrsWtMult(1) != 0
            || wrsWtMult(2) != 0
            || wrsWtMult(3) != 50
            || wrsWtMult(4) != 100
        )
            ++bad;
        // the ladders rise with each band: Dexterity and Strength strictly
        // increase, Wisdom and Constitution never decrease
    if (wrsDexCheck(0) >= wrsDexCheck(1)
            || wrsDexCheck(1) >= wrsDexCheck(2)
            || wrsDexCheck(2) >= wrsDexCheck(3)
            || wrsDexCheck(3) >= wrsDexCheck(4)
            || wrsStrCheck(0) >= wrsStrCheck(1)
            || wrsStrCheck(1) >= wrsStrCheck(2)
            || wrsStrCheck(2) >= wrsStrCheck(3)
            || wrsStrCheck(3) >= wrsStrCheck(4)
            || wrsWisCheck(1) > wrsWisCheck(2)
            || wrsWisCheck(2) > wrsWisCheck(3)
            || wrsConCheck(2) > wrsConCheck(3)
        )
            ++bad;
        // the penalties deepen with each band: to-hit, Climbing and Movement
        // all worsen monotonically (never lighten going down the bands)
    if (wrsToHit(2) > wrsToHit(1)
            || wrsToHit(3) > wrsToHit(2)
            || wrsToHit(4) > wrsToHit(3)
            || wrsClimbPct(3) > wrsClimbPct(2)
            || wrsClimbPct(4) > wrsClimbPct(3)
            || wrsMovePct(3) > wrsMovePct(2)
            || wrsMovePct(4) > wrsMovePct(3)
        )
            ++bad;
        // the less-than-5 band is Dexterity-only: every other column is zero
    if (wrsStrCheck(0) != 0
            || wrsWisCheck(0) != 0
            || wrsConCheck(0) != 0
            || wrsToHit(0) != 0
            || wrsClimbPct(0) != 0
            || wrsMovePct(0) != 0
            || wrsWtMult(0) != 0
        )
            ++bad;
        // the Constitution and Weight Allowance entries appear only in the
        // bottom two bands
    if (wrsConCheck(2) != 0
            || wrsWtMult(2) != 0
            || wrsWtMult(3) != 50
            || wrsWtMult(4) != 100
        )
            ++bad;
        printf("R473 WSG sleep and shelter pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
