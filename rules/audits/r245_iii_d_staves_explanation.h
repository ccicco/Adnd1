    // ---- R245: the III.D staves explanation prose pins audit ----
    // DMG pp.142-143: the staff conventions and
    // the seven staves of the RODS, et al.
    // explanation prose.
    {
        Rodswands rodswands;
        Staves_command_to_withering staves_command_to_withering;
        int bad = 0;
        // the conventions: 8th level, the 2/8
        // segment cycle, nominal 8d6
        if (staves_command_to_withering.stfStaffLevelOfUse() != 8 ||
            staves_command_to_withering.stfDischargeSegments() != 2 ||
            staves_command_to_withering.stfRechargeSegments() != 8 ||
            staves_command_to_withering.stfNominalDamageDice() != 8 ||
            staves_command_to_withering.stfNominalDamageDieFaces() != 6) ++bad;
        // the seven staves are the engine III.D
        // table rows 8-14 - bands 20-33, the wand
        // rows from 34 (the R224 pins)
        if (staves_command_to_withering.stfStaffCount() != 7 ||
            rodswands.rswRowLo(7) != 20 ||
            rodswands.rswRowHi(13) != 33 ||
            rodswands.rswRowLo(14) != 34) ++bad;
        // Staff of Command
        if (staves_command_to_withering.stfCmdFunctionCount() != 3 ||
            staves_command_to_withering.stfCmdMuEffectiveFunctions() != 2 ||
            staves_command_to_withering.stfCmdHumanInfluenceCharge() != 1 ||
            staves_command_to_withering.stfCmdControlChargePerTurn() != 1 ||
            staves_command_to_withering.stfCmdPlantAreaInches() != 1 ||
            staves_command_to_withering.stfCmdRechargeable() != 1) ++bad;
        // Staff of Curing
        if (staves_command_to_withering.stfCureFunctionCount() != 4 ||
            staves_command_to_withering.stfCureWoundsHpLo() != 6 ||
            staves_command_to_withering.stfCureWoundsHpHi() != 21 ||
            staves_command_to_withering.stfCureChargePerFunction() != 1 ||
            staves_command_to_withering.stfCureUsesPerPersonPerDay() != 1 ||
            staves_command_to_withering.stfCureMaxPerFunctionPerDay() != 2 ||
            staves_command_to_withering.stfCureMaxPerDay() != 8 ||
            staves_command_to_withering.stfCureRechargeable() != 1) ++bad;
        // Staff of the Magi - the three power
        // lists and the facts
        if (staves_command_to_withering.stfMagiFreePowerCount() != 5 ||
            staves_command_to_withering.stfMagiOneChargePowerCount() != 10 ||
            staves_command_to_withering.stfMagiTwoChargePowerCount() != 4 ||
            staves_command_to_withering.stfMagiElementalHitDice() != 8 ||
            staves_command_to_withering.stfMagiTelekinesisPounds() != 200 ||
            staves_command_to_withering.stfMagiSaveBonus() != 2 ||
            staves_command_to_withering.stfMagiRechargeable() != 1) ++bad;
        // the retributive strike - the globe, the
        // 8/6/4 damage bands, save for half, the
        // 50% plane travel, 2 items capable
        static const int kStrike[3] = {
            8, 6, 4,
        };
        if (staves_command_to_withering.stfStrikeGlobeRadiusInches() != 3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (staves_command_to_withering.stfStrikeDamageMultiple(i) != kStrike[i]) ++bad;
        if (staves_command_to_withering.stfStrikeMaxSpellLevels() != 25 ||
            staves_command_to_withering.stfStrikeSaveHalf() != 1 ||
            staves_command_to_withering.stfStrikePlaneTravelPercent() != 50 ||
            staves_command_to_withering.stfStrikeCapableItems() != 2) ++bad;
        // clamped reads land on the inner band below
        // and the outer band above
        if (staves_command_to_withering.stfStrikeDamageMultiple(-9) != 8 ||
            staves_command_to_withering.stfStrikeDamageMultiple(99) != 4) ++bad;
        // Staff of Power
        if (staves_command_to_withering.stfPowerOneChargeCount() != 6 ||
            staves_command_to_withering.stfPowerTwoChargeCount() != 3 ||
            staves_command_to_withering.stfPowerAcSaveBonus() != 2 ||
            staves_command_to_withering.stfPowerSmiteBonus() != 2 ||
            staves_command_to_withering.stfPowerSmiteDamageLo() != 3 ||
            staves_command_to_withering.stfPowerSmiteDamageHi() != 8 ||
            staves_command_to_withering.stfPowerSmiteDoubleChargeCost() != 1 ||
            staves_command_to_withering.stfPowerSmiteTripleAllowed() != 0 ||
            staves_command_to_withering.stfPowerParalysisConeLengthInches() != 4 ||
            staves_command_to_withering.stfPowerParalysisConeWidthInches() != 2 ||
            staves_command_to_withering.stfPowerRechargeable() != 1) ++bad;
        // Staff of the Serpent - the python
        if (staves_command_to_withering.stfSerpentVarietyCount() != 2 ||
            staves_command_to_withering.stfPythonBonus() != 2 ||
            staves_command_to_withering.stfPythonDamageLo() != 3 ||
            staves_command_to_withering.stfPythonDamageHi() != 8 ||
            staves_command_to_withering.stfPythonSnakeLengthFeet() != 25 ||
            staves_command_to_withering.stfPythonSnakeAc() != 3 ||
            staves_command_to_withering.stfPythonSnakeHp() != 49 ||
            staves_command_to_withering.stfPythonSnakeMoveInches() != 9 ||
            staves_command_to_withering.stfPythonTransformRounds() != 1 ||
            staves_command_to_withering.stfPythonConstrictLo() != 4 ||
            staves_command_to_withering.stfPythonConstrictHi() != 10) ++bad;
        // the adder, and no charges at all
        if (staves_command_to_withering.stfAdderBonus() != 1 ||
            staves_command_to_withering.stfAdderDamageLo() != 2 ||
            staves_command_to_withering.stfAdderDamageHi() != 4 ||
            staves_command_to_withering.stfAdderHeadAc() != 5 ||
            staves_command_to_withering.stfAdderHeadHp() != 20 ||
            staves_command_to_withering.stfAdderHeadTurns() != 1 ||
            staves_command_to_withering.stfAdderPoisonSaveOrDie() != 1 ||
            staves_command_to_withering.stfSerpentHasCharges() != 0 ||
            staves_command_to_withering.stfSerpentPythonPercent() != 60) ++bad;
        // Staff of Striking - the 3/6/9 bonus walk
        static const int kStrike2[3] = {
            3, 6, 9,
        };
        if (staves_command_to_withering.stfStrikingBonus() != 3 ||
            staves_command_to_withering.stfStrikingDamageLo() != 4 ||
            staves_command_to_withering.stfStrikingDamageHi() != 9 ||
            staves_command_to_withering.stfStrikingMaxChargesPerStrike() != 3 ||
            staves_command_to_withering.stfStrikingRechargeable() != 1) ++bad;
        for (int i = 0; i < 3; ++i)
            if (staves_command_to_withering.stfStrikingBonusPerCharge(i) != kStrike2[i]) ++bad;
        if (staves_command_to_withering.stfStrikingBonusPerCharge(-9) != 3 ||
            staves_command_to_withering.stfStrikingBonusPerCharge(99) != 9) ++bad;
        // Staff of Withering - no recharge accessor,
        // the book prints none
        if (staves_command_to_withering.stfWitherBonus() != 1 ||
            staves_command_to_withering.stfWitherDamageLo() != 2 ||
            staves_command_to_withering.stfWitherDamageHi() != 5 ||
            staves_command_to_withering.stfWitherAgeYears() != 10 ||
            staves_command_to_withering.stfWitherLimbCharges() != 3 ||
            staves_command_to_withering.stfWitherAgelessImmune() != 1) ++bad;
        printf("R245 staves prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
