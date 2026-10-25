    // ---- R524 DSG loyalty hazards audit ----
    // The DSG hireling loyalty and p. 55 hazards pins the loyalty check (the
    // DMG page-36 procedure with the foreman as liege, the 10% security
    // modifiers, the pay judged against the mine value, the
    // Intelligence-driven theft planning at the 8-or-less unplanned
    // threshold, and the 1d6 x 10% daily-output theft), the flooding hazard
    // (the tapped water body and water table, the escape gradient, the
    // drained-or-pumped recovery), the mine cave-ins (the 2%/50%
    // shored/unshored weekly chances with interpolation, the 1d4 x 10%
    // earthquake, 1d3 x 10% rain and 1%-per-hit-die burrower adds, the d100
    // location roll, and the 20 x 10 ft fallen ceiling with normal chain
    // reactions), and the unnatural hazards (the unnamed evil, the
    // burial-ground undead, the jealous drow and duergar with intervention
    // proportional to the mine's value, and the planar-gate risk).
    {
        using namespace rules;
        int bad = 0;
    if (dnswLoyaltyModPct() != 10
            || dnswTheftDice() != 1
            || dnswTheftSides() != 6
            || dnswTheftPctMult() != 10
            || dnswLowIntUnplanned() != 8
            || dnswShoredCaveInPct() != 2
            || dnswUnshoredCaveInPct() != 50
            || dnswQuakeDice() != 1
            || dnswQuakeSides() != 4
            || dnswQuakePctMult() != 10
            || dnswRainDice() != 1
            || dnswRainSides() != 3
            || dnswRainPctMult() != 10
            || dnswBurrowerPctPerHitDie() != 1
            || dnswCaveInLocDice() != 1
            || dnswCaveInLocSides() != 100
            || dnswCaveInLenFt() != 20
            || dnswCaveInThickFt() != 10
            || !dnswHiredHelpRequired()
            || !dnswAdventurersScoutAndGuard()
            || !dnswPreciousFindsTempt()
            || !dnswDmg36LoyaltyCheck()
            || !dnswForemanIsLiege()
            || !dnswSecurityModifiers()
            || !dnswPayJudgedAgainstMineValue()
            || !dnswFailedCheckNotImmediate()
            || !dnswHighIntPlansTheft()
            || !dnswFloodFromTappedWater()
            || !dnswFloodEscapeGradient()
            || !dnswFloodedMineNeedsPumping()
            || !dnswShoringPartialNotTotal()
            || !dnswExternalForcesAdd()
            || !dnswChainReactionNormal()
            || !dnswUnnamedEvilLurks()
            || !dnswBurialGroundUndead()
            || !dnswDeepMonstersConcerned()
            || !dnswUnderdarkRacesJealous()
            || !dnswPlanarGateRisk()
        )
            ++bad;
        // the loyalty numbers: the 10% security modifiers, the 1d6 x 10%
        // daily-output theft, and the Intelligence-8 unplanned threshold.
    if (dnswLoyaltyModPct() != 10
            || dnswTheftDice() != 1
            || dnswTheftSides() != 6
            || dnswTheftPctMult() != 10
            || dnswLowIntUnplanned() != 8
        )
            ++bad;
        // the cave-in chances: 2% shored vs 50% unshored weekly, the 1d4 x
        // 10% earthquake and 1d3 x 10% rain adds, and the 1% per hit die of
        // burrowers.
    if (dnswShoredCaveInPct() != 2
            || dnswUnshoredCaveInPct() != 50
            || dnswQuakeDice() != 1
            || dnswQuakeSides() != 4
            || dnswQuakePctMult() != 10
            || dnswRainDice() != 1
            || dnswRainSides() != 3
            || dnswRainPctMult() != 10
            || dnswBurrowerPctPerHitDie() != 1
        )
            ++bad;
        // the cave-in geometry: the d100 end-to-end location roll and the
        // 20-foot-long, 10-foot-thick fallen ceiling section.
    if (dnswCaveInLocDice() != 1
            || dnswCaveInLocSides() != 100
            || dnswCaveInLenFt() != 20
            || dnswCaveInThickFt() != 10
        )
            ++bad;
        // the prose seams: the DMG p. 36 check with the foreman as liege, the
        // Intelligence-driven theft planning, the flooding adjudication, the
        // partial-shoring interpolation, and the jealous-race and planar-gate
        // threats.
    if (dnswDmg36LoyaltyCheck() != 1
            || dnswForemanIsLiege() != 1
            || dnswFailedCheckNotImmediate() != 1
            || dnswHighIntPlansTheft() != 1
            || dnswFloodFromTappedWater() != 1
            || dnswShoringPartialNotTotal() != 1
            || dnswUnderdarkRacesJealous() != 1
            || dnswPlanarGateRisk() != 1
        )
            ++bad;
        printf("R524 DSG loyalty hazards audit: bad %d\n", bad);
        if (bad) return 1;
    }
