    // ---- R477 WSG damage from fire pin audit ----
    // The firebreak and advance prose (the half-wind or 5-mph advance, the
    // trot escape, the firebreak with dig and move earth, the cut-in-half
    // ruling, the cleared-area refuge), the engulfment rule (the 1d6+9 10-15
    // damage with the halved-rounded-up +4 Constitution Check and the
    // one-third unconscious bar), the brief-contact rule (the 1d8 contact
    // damage, the versus-normal-fire item saves, the 1d3 per burning item,
    // the Wisdom Check calm-and-roll against the panic run with 1d4 per
    // round), and the extreme-heat rule (5 feet large, 3 feet medium, 120
    // degrees, no activity adjustments) are audit examples.
    {
        using namespace rules;
        int bad = 0;
    if (wdmAdvanceWindDiv() != 2
            || wdmAdvanceMinMph() != 5
            || wdmEngulfDice() != 1
            || wdmEngulfDieSides() != 6
            || wdmEngulfBonus() != 9
            || wdmEngulfMinDmg() != 10
            || wdmEngulfMaxDmg() != 15
            || wdmConCheckMod() != 4
            || wdmHalveDivisor() != 2
            || wdmUnconsciousNum() != 1
            || wdmUnconsciousDen() != 3
            || wdmBriefDieSides() != 8
            || wdmItemBurnDieSides() != 3
            || wdmPanicDieSides() != 4
            || wdmHeatLargeFt() != 5
            || wdmHeatMediumFt() != 3
            || wdmHeatTempDegrees() != 120
            || !wdmTrotStaysAhead()
            || !wdmFirebreakClears()
            || !wdmDigMoveEarthHelp()
            || !wdmSpadeCanKillFire()
            || !wdmFirebreakCutsInHalf()
            || !wdmClearedAreaRefuge()
            || !wdmRefugeStillRisky()
            || !wdmFireNotAlwaysLethal()
            || !wdmEngulfRequiresImmersion()
            || !wdmHalvedRoundedUp()
            || !wdmUnconsciousLosesChecks()
            || !wdmItemsSaveVsFire()
            || !wdmItemBurnPerRound()
            || !wdmWisCheckAvoids()
            || !wdmPanicRuns()
            || !wdmPanicUntilCaught()
            || !wdmHeatNeedsNoContact()
            || !wdmHeatIgnoresActivity()
            || !wdmHeatTableRef()
            || !wdmBeyondSafeButHot()
            || !wdmDmAdjudicatesUncovered()
        )
            ++bad;
        // the advance speed: one-half of the wind velocity, or 5 mph in any
        // case
    if (wdmAdvanceWindDiv() != 2
            || wdmAdvanceMinMph() != 5
            || wdmAdvanceWindDiv() < 1
        )
            ++bad;
        // the engulf damage is 10-15 points of 1d6 + 9 per round
    if (wdmEngulfDice() != 1
            || wdmEngulfDieSides() != 6
            || wdmEngulfBonus() != 9
            || wdmEngulfMinDmg() != wdmEngulfDice() + wdmEngulfBonus()
            || wdmEngulfMaxDmg() != wdmEngulfDieSides() + wdmEngulfBonus()
            || wdmEngulfMinDmg() != 10
            || wdmEngulfMaxDmg() != 15
        )
            ++bad;
        // the halving rule: cut in half rounded up on a successful
        // Constitution Check with a +4 modifier
    if (wdmConCheckMod() != 4
            || wdmHalveDivisor() != 2
        )
            ++bad;
        // the unconscious threshold is exactly one-third of the full normal
        // hit points
    if (wdmUnconsciousNum() != 1
            || wdmUnconsciousDen() != 3
            || wdmUnconsciousNum() >= wdmUnconsciousDen()
        )
            ++bad;
        // the contact damage dice: 1d8 brief contact, 1d3 per burning item,
        // 1d4 while panicked
    if (wdmBriefDieSides() != 8
            || wdmItemBurnDieSides() != 3
            || wdmPanicDieSides() != 4
        )
            ++bad;
        // the heat distances: 5 feet for a large fire, 3 feet for a medium
        // fire, at a temperature of 120 degrees or higher
    if (wdmHeatLargeFt() != 5
            || wdmHeatMediumFt() != 3
            || wdmHeatTempDegrees() != 120
            || wdmHeatMediumFt() >= wdmHeatLargeFt()
        )
            ++bad;
        printf("R477 WSG damage from fire pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
