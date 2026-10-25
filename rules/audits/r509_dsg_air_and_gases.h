    // ---- R509 DSG air and gases audit ----
    // The DSG underground environment opener pins the air supply duration (10
    // cubic feet per human per 24 hours at rest, 12 hours moderate, 6 hours
    // strenuous, the 2x and 4x consumption rates, the
    // 3-hours-rest-plus-4-times-5 example at 23 hours, the creature ratios at
    // 2/3, 1/2 and 2x, the post-exhaustion Con Check ladder - each failure
    // draining 1 from every ability and 1 hit point, further checks against
    // the reduced Con, unconscious at all-zero abilities, dead at -10 hit
    // points, automatic once Con hits 0, the immediate 3-per-turn recovery on
    // fresh air, and the air-only scope that excludes breath-holding), the
    // fire and oxygen rules (the 1-foot small fire draining a 10-foot cube in
    // 2 hours/12 turns, the torch at 8 hours, the small-fire-equivalent
    // scaling at 4x, the 3-round oil flask counted as 3 turns), the smoke
    // system (the 1-foot layer per turn per 10-by-10 area stacking from the
    // ceiling until floor-liers are affected, wet or green fuel and fabric
    // and oil as the smoke sources, the per-round Con Check with 1d6 damage,
    // the 1d6-per-round fresh-air recovery, the cumulative rule, the
    // 33-hit-point character losing 28 and dying to the orc's 5-point blow),
    // the gases (poisonous gases saving vs. poison, noxious gases Con
    // Checking every round for -3 abilities and -3 attacks with no hit-point
    // loss and 3 per turn recovery, the gas-replaces-oxygen fold into the air
    // system, the natural-gas 20-percent-per-round explosion at 1d6 with a
    // 1d6 damage and 1 Wisdom step per 10 percent potency, no Wisdom Check
    // for odorless gas, and the secret small-bird save one turn early as a
    // 0th-level human against gradually increasing gas) and the five-rung
    // ventilation ladder (well-ventilated, subtle, connected, none and sealed
    // with their smoke, gas, spell and oxygen clauses).
    {
        using namespace rules;
        int bad = 0;
    if (dnaAirRestCubicFeet() != 10
            || dnaAirRestHours() != 24
            || dnaAirModerateHours() != 12
            || dnaAirStrenuousHours() != 6
            || dnaAirModerateRateMult() != 2
            || dnaAirStrenuousRateMult() != 4
            || dnaAirExampleRestHours() != 3
            || dnaAirExampleWorkHours() != 5
            || dnaAirExampleTotalRestHours() != 23
            || dnaAirDwarfElfNum() != 2
            || dnaAirDwarfElfDen() != 3
            || dnaAirHalflingDogDen() != 2
            || dnaAirMuleOgreMult() != 2
            || dnaAirFailAbilityLoss() != 1
            || dnaAirFailHpLoss() != 1
            || dnaAirDeathHpFloor() != -10
            || dnaAirRecoverPerTurn() != 3
            || dnaFireSmallMaxDiameterFeet() != 1
            || dnaFireSmallCubeFeet() != 10
            || dnaFireSmallHours() != 2
            || dnaFireSmallTurns() != 12
            || dnaFireTorchHours() != 8
            || dnaFireScaleExampleMult() != 4
            || dnaOilBurnRounds() != 3
            || dnaSmokeLayerFeet() != 1
            || dnaSmokeAreaFeet() != 10
            || dnaSmokeScaleExampleMult() != 3
            || dnaSmokeDamageDie() != 6
            || dnaSmokeRecoverDie() != 6
            || dnaSmokeExampleCharHp() != 33
            || dnaSmokeExampleLoss() != 28
            || dnaSmokeExampleOrcHit() != 5
            || dnaNoxiousAbilityLoss() != 3
            || dnaNoxiousAttackPenalty() != 3
            || dnaNoxiousRecoverPerTurn() != 3
            || dnaNatGasExplodePct() != 20
            || dnaNatGasDamageDie() != 6
            || dnaNatGasPotencyStepPct() != 10
            || dnaNatGasPotencyDieStep() != 1
            || dnaNatGasWisBonusPerStep() != 1
            || dnaBirdSaveLevel() != 0
            || dnaVentWellGasTurns() != 2
            || dnaVentSubtleGasHours() != 1
            || dnaVentSubtleLargeSmokeDiv() != 2
            || dnaVentConnectedSmallSmokeDiv() != 2
            || dnaVentConnectedGasMinHours() != 2
            || dnaVentConnectedGasMaxHours() != 5
            || dnaVentNoneGasHours() != 24
            || dnaSealedSmokeLingerDie() != 6
            || !dnaAirDmAppliesToCreatures()
            || !dnaAirConCheckEachTurnAfterExhaust()
            || !dnaAirCheckAgainstReducedCon()
            || !dnaAirUnconsciousAtZeroAbilities()
            || !dnaAirAutoDeathAtConZero()
            || !dnaAirRecoveryImmediateOnFreshAir()
            || !dnaAirOnlyInAirNotBreathHolding()
            || !dnaAirCaveInCutsVentilation()
            || !dnaAirCrowdingOutpacesVentilation()
            || !dnaFireScalesBySmallFireEquivalents()
            || !dnaFireGoesOutWithoutOxygen()
            || !dnaOilRoundCountsAsTurn()
            || !dnaSmokeFromWetOrGreenFuel()
            || !dnaSmokeFromFabricAndOil()
            || !dnaSmokeLayersStackFromCeiling()
            || !dnaSmokeFillsRoomAffectsFloor()
            || !dnaOilSmokeRateByRound()
            || !dnaSmokeScalesWithFireSize()
            || !dnaSmokeConCheckEachRound()
            || !dnaSmokeDamageTemporary()
            || !dnaSmokeDamageCumulative()
            || !dnaGasPoisonSaveVsPoison()
            || !dnaGasOxygenReplacementTreatedAsExhaustion()
            || !dnaNoxiousConCheckEachRound()
            || !dnaNoxiousHelplessAtZeroAbilities()
            || !dnaNoxiousNoHpLoss()
            || !dnaGasDmAdjustmentsAllowed()
            || !dnaOdorlessGasNoWisCheck()
            || !dnaStrongOdorAllowsBreathHold()
            || !dnaNatGasExplodesWithOpenFlame()
            || !dnaNatGasWisCheckOnlyIfCareful()
            || !dnaBirdWarnsOneTurnEarly()
            || !dnaBirdSaveSecret()
            || !dnaBirdDiesOnFailedSave()
            || !dnaBirdOnlyGradualGas()
            || !dnaVentWellNoSmokeAccumulation()
            || !dnaVentWellNoOxygenExhaustion()
            || !dnaVentWellGasSpellsHalved()
            || !dnaVentSubtleSpellsNormal()
            || !dnaVentSubtleSmallSmokeNoAccumulation()
            || !dnaVentConnectedLargeSmokeNormal()
            || !dnaVentConnectedBreathNeverExhausts()
            || !dnaVentConnectedSpellsNormal()
            || !dnaVentNoneSmallSmokeNormal()
            || !dnaVentNoneHeavierThanAirException()
            || !dnaSealedAirFinite()
            || !dnaSealedEffectsNormalRates()
            || !dnaSealedGasUntilVented()
            || !dnaSealedSpellsNormal()
        )
            ++bad;
        // the air-supply durations: 10 cubic feet per human per 24 hours at
        // rest, 12 hours moderate, 6 hours strenuous.
    if (dnaAirRestCubicFeet() != 10
            || dnaAirRestHours() != 24
            || dnaAirModerateHours() != 12
            || dnaAirStrenuousHours() != 6
        )
            ++bad;
        // the consumption rates (2x moderate, 4x strenuous) and the worked
        // example: 3 hours rest plus 4 times 5 hours work equals 23 hours of
        // resting-rate oxygen.
    if (dnaAirModerateRateMult() != 2
            || dnaAirStrenuousRateMult() != 4
            || dnaAirExampleRestHours() != 3
            || dnaAirExampleWorkHours() != 5
            || dnaAirExampleTotalRestHours() != 23
        )
            ++bad;
        // the creature-rate ratios: dwarf and elf at two-thirds human,
        // halfling and dog at half, mule and ogre at twice.
    if (dnaAirDwarfElfNum() != 2
            || dnaAirDwarfElfDen() != 3
            || dnaAirHalflingDogDen() != 2
            || dnaAirMuleOgreMult() != 2
        )
            ++bad;
        // the post-exhaustion ladder: a Con Check each turn against the
        // reduced Con, each failure draining 1 from every ability and 1 hit
        // point, unconscious at all-zero abilities, dead at -10 hit points,
        // automatic once Con reaches 0.
    if (dnaAirConCheckEachTurnAfterExhaust() != 1
            || dnaAirCheckAgainstReducedCon() != 1
            || dnaAirFailAbilityLoss() != 1
            || dnaAirFailHpLoss() != 1
            || dnaAirUnconsciousAtZeroAbilities() != 1
            || dnaAirAutoDeathAtConZero() != 1
            || dnaAirDeathHpFloor() != -10
        )
            ++bad;
        // the recovery (immediate, 3 points per turn for hit points and
        // abilities) and the scope note: air areas only, never
        // breath-holding.
    if (dnaAirRecoveryImmediateOnFreshAir() != 1
            || dnaAirRecoverPerTurn() != 3
            || dnaAirOnlyInAirNotBreathHolding() != 1
        )
            ++bad;
        // the fire oxygen rates: a small fire (1 foot or less) drains a
        // 10-foot cube in 2 hours (12 turns), a torch in 8 hours.
    if (dnaFireSmallMaxDiameterFeet() != 1
            || dnaFireSmallCubeFeet() != 10
            || dnaFireSmallHours() != 2
            || dnaFireSmallTurns() != 12
            || dnaFireTorchHours() != 8
        )
            ++bad;
        // the fire scaling (a 4x fire drains 4x as fast, and fires go out
        // when the oxygen is gone) and the oil rule: a flask burns 3 rounds,
        // each counted as a full turn of small-fire oxygen.
    if (dnaFireScalesBySmallFireEquivalents() != 1
            || dnaFireScaleExampleMult() != 4
            || dnaFireGoesOutWithoutOxygen() != 1
            || dnaOilBurnRounds() != 3
            || dnaOilRoundCountsAsTurn() != 1
        )
            ++bad;
        // the smoke buildup: a 1-foot-thick layer per turn over each 10-by-10
        // area, stacking from the ceiling down until even floor-liers are
        // affected.
    if (dnaSmokeLayerFeet() != 1
            || dnaSmokeAreaFeet() != 10
            || dnaSmokeLayersStackFromCeiling() != 1
            || dnaSmokeFillsRoomAffectsFloor() != 1
        )
            ++bad;
        // the smoke damage loop: a Con Check each inhaled round, 1d6 on a
        // failure, 1d6 recovered per successful fresh-air round, cumulative
        // with other damage.
    if (dnaSmokeConCheckEachRound() != 1
            || dnaSmokeDamageDie() != 6
            || dnaSmokeDamageTemporary() != 1
            || dnaSmokeRecoverDie() != 6
            || dnaSmokeDamageCumulative() != 1
        )
            ++bad;
        // the smoke death example: the 33-hit-point character has exactly his
        // 28-point smoke loss equal to the orc's 5-point blow (33 - 28 == 5),
        // so the strike kills him before any recovery.
    if (dnaSmokeExampleCharHp() - dnaSmokeExampleLoss() !=
        dnaSmokeExampleOrcHit()
        )
            ++bad;
        // the gas effects: poisonous gases save vs. poison; noxious gases Con
        // Check each round with the -3 ability and -3 attack drain, no
        // hit-point loss, and 3 points per turn of recovery.
    if (dnaGasPoisonSaveVsPoison() != 1
            || dnaNoxiousConCheckEachRound() != 1
            || dnaNoxiousAbilityLoss() != 3
            || dnaNoxiousAttackPenalty() != 3
            || dnaNoxiousNoHpLoss() != 1
            || dnaNoxiousRecoverPerTurn() != 3
        )
            ++bad;
        // the natural-gas hazard: the base 20 percent per-round explosion
        // chance with open flame, 1d6 damage, each 10 percent potency step
        // adding 1d6 damage and 1 point of Wisdom for the check only - and no
        // Wisdom Check at all for an odor-free gas.
    if (dnaNatGasExplodePct() != 20
            || dnaNatGasDamageDie() != 6
            || dnaNatGasPotencyStepPct() != 10
            || dnaNatGasPotencyDieStep() != 1
            || dnaNatGasWisBonusPerStep() != 1
            || dnaOdorlessGasNoWisCheck() != 1
            || dnaNatGasWisCheckOnlyIfCareful() != 1
        )
            ++bad;
        // the small-bird warning: a secret save vs. poison one turn before
        // the characters, saving as a 0th-level human, dying on a failure,
        // and only against gradually increasing gas.
    if (dnaBirdWarnsOneTurnEarly() != 1
            || dnaBirdSaveSecret() != 1
            || dnaBirdSaveLevel() != 0
            || dnaBirdDiesOnFailedSave() != 1
            || dnaBirdOnlyGradualGas() != 1
        )
            ++bad;
        // the well-ventilated rung: no smoke accumulation, no oxygen
        // exhaustion, gas-based spell durations halved, gases gone in 2
        // turns.
    if (dnaVentWellGasTurns() != 2
            || dnaVentWellNoSmokeAccumulation() != 1
            || dnaVentWellNoOxygenExhaustion() != 1
            || dnaVentWellGasSpellsHalved() != 1
        )
            ++bad;
        // the subtle rung (torch-flicker airflow): normal spell durations,
        // gases 1 hour, small-fire smoke no accumulation, large or oil smoke
        // at half rate.
    if (dnaVentSubtleGasHours() != 1
            || dnaVentSubtleLargeSmokeDiv() != 2
            || dnaVentSubtleSpellsNormal() != 1
            || dnaVentSubtleSmallSmokeNoAccumulation() != 1
        )
            ++bad;
        // the connected rung: small-fire smoke at half rate, large or oil at
        // the usual rate, breathing never exhausts the air, gases 2-5 hours
        // (1d4+1), spells normal.
    if (dnaVentConnectedSmallSmokeDiv() != 2
            || dnaVentConnectedLargeSmokeNormal() != 1
            || dnaVentConnectedGasMinHours() != 2
            || dnaVentConnectedGasMaxHours() != 5
            || dnaVentConnectedBreathNeverExhausts() != 1
            || dnaVentConnectedSpellsNormal() != 1
        )
            ++bad;
        // the no-ventilation rung: smoke at full rate even from small fires,
        // gases a full 24 hours unless heavier than air.
    if (dnaVentNoneSmallSmokeNormal() != 1
            || dnaVentNoneGasHours() != 24
            || dnaVentNoneHeavierThanAirException() != 1
        )
            ++bad;
        // the sealed rung: finite air at normal rates, smoke lingering 1d6
        // hours after the fire goes out, gases remaining until vented, spells
        // normal.
    if (dnaSealedAirFinite() != 1
            || dnaSealedSmokeLingerDie() != 6
            || dnaSealedGasUntilVented() != 1
            || dnaSealedSpellsNormal() != 1
            || dnaSealedEffectsNormalRates() != 1
        )
            ++bad;
        printf("R509 DSG air and gases audit: bad %d\n", bad);
        if (bad) return 1;
    }
