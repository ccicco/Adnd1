    // ---- R245: the III.D staves explanation prose pins audit ----
    // DMG pp.142-143: the staff conventions and
    // the seven staves of the RODS, et al.
    // explanation prose.
    {
        int bad = 0;
        // the conventions: 8th level, the 2/8
        // segment cycle, nominal 8d6
        if (rules::stfStaffLevelOfUse() != 8 ||
            rules::stfDischargeSegments() != 2 ||
            rules::stfRechargeSegments() != 8 ||
            rules::stfNominalDamageDice() != 8 ||
            rules::stfNominalDamageDieFaces() != 6) ++bad;
        // the seven staves are the engine III.D
        // table rows 8-14 - bands 20-33, the wand
        // rows from 34 (the R224 pins)
        if (rules::stfStaffCount() != 7 ||
            rules::rswRowLo(7) != 20 ||
            rules::rswRowHi(13) != 33 ||
            rules::rswRowLo(14) != 34) ++bad;
        // Staff of Command
        if (rules::stfCmdFunctionCount() != 3 ||
            rules::stfCmdMuEffectiveFunctions() != 2 ||
            rules::stfCmdHumanInfluenceCharge() != 1 ||
            rules::stfCmdControlChargePerTurn() != 1 ||
            rules::stfCmdPlantAreaInches() != 1 ||
            rules::stfCmdRechargeable() != 1) ++bad;
        // Staff of Curing
        if (rules::stfCureFunctionCount() != 4 ||
            rules::stfCureWoundsHpLo() != 6 ||
            rules::stfCureWoundsHpHi() != 21 ||
            rules::stfCureChargePerFunction() != 1 ||
            rules::stfCureUsesPerPersonPerDay() != 1 ||
            rules::stfCureMaxPerFunctionPerDay() != 2 ||
            rules::stfCureMaxPerDay() != 8 ||
            rules::stfCureRechargeable() != 1) ++bad;
        // Staff of the Magi - the three power
        // lists and the facts
        if (rules::stfMagiFreePowerCount() != 5 ||
            rules::stfMagiOneChargePowerCount() != 10 ||
            rules::stfMagiTwoChargePowerCount() != 4 ||
            rules::stfMagiElementalHitDice() != 8 ||
            rules::stfMagiTelekinesisPounds() != 200 ||
            rules::stfMagiSaveBonus() != 2 ||
            rules::stfMagiRechargeable() != 1) ++bad;
        // the retributive strike - the globe, the
        // 8/6/4 damage bands, save for half, the
        // 50% plane travel, 2 items capable
        static const int kStrike[3] = {
            8, 6, 4,
        };
        if (rules::stfStrikeGlobeRadiusInches() != 3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (rules::stfStrikeDamageMultiple(i) != kStrike[i]) ++bad;
        if (rules::stfStrikeMaxSpellLevels() != 25 ||
            rules::stfStrikeSaveHalf() != 1 ||
            rules::stfStrikePlaneTravelPercent() != 50 ||
            rules::stfStrikeCapableItems() != 2) ++bad;
        // clamped reads land on the inner band below
        // and the outer band above
        if (rules::stfStrikeDamageMultiple(-9) != 8 ||
            rules::stfStrikeDamageMultiple(99) != 4) ++bad;
        // Staff of Power
        if (rules::stfPowerOneChargeCount() != 6 ||
            rules::stfPowerTwoChargeCount() != 3 ||
            rules::stfPowerAcSaveBonus() != 2 ||
            rules::stfPowerSmiteBonus() != 2 ||
            rules::stfPowerSmiteDamageLo() != 3 ||
            rules::stfPowerSmiteDamageHi() != 8 ||
            rules::stfPowerSmiteDoubleChargeCost() != 1 ||
            rules::stfPowerSmiteTripleAllowed() != 0 ||
            rules::stfPowerParalysisConeLengthInches() != 4 ||
            rules::stfPowerParalysisConeWidthInches() != 2 ||
            rules::stfPowerRechargeable() != 1) ++bad;
        // Staff of the Serpent - the python
        if (rules::stfSerpentVarietyCount() != 2 ||
            rules::stfPythonBonus() != 2 ||
            rules::stfPythonDamageLo() != 3 ||
            rules::stfPythonDamageHi() != 8 ||
            rules::stfPythonSnakeLengthFeet() != 25 ||
            rules::stfPythonSnakeAc() != 3 ||
            rules::stfPythonSnakeHp() != 49 ||
            rules::stfPythonSnakeMoveInches() != 9 ||
            rules::stfPythonTransformRounds() != 1 ||
            rules::stfPythonConstrictLo() != 4 ||
            rules::stfPythonConstrictHi() != 10) ++bad;
        // the adder, and no charges at all
        if (rules::stfAdderBonus() != 1 ||
            rules::stfAdderDamageLo() != 2 ||
            rules::stfAdderDamageHi() != 4 ||
            rules::stfAdderHeadAc() != 5 ||
            rules::stfAdderHeadHp() != 20 ||
            rules::stfAdderHeadTurns() != 1 ||
            rules::stfAdderPoisonSaveOrDie() != 1 ||
            rules::stfSerpentHasCharges() != 0 ||
            rules::stfSerpentPythonPercent() != 60) ++bad;
        // Staff of Striking - the 3/6/9 bonus walk
        static const int kStrike2[3] = {
            3, 6, 9,
        };
        if (rules::stfStrikingBonus() != 3 ||
            rules::stfStrikingDamageLo() != 4 ||
            rules::stfStrikingDamageHi() != 9 ||
            rules::stfStrikingMaxChargesPerStrike() != 3 ||
            rules::stfStrikingRechargeable() != 1) ++bad;
        for (int i = 0; i < 3; ++i)
            if (rules::stfStrikingBonusPerCharge(i) != kStrike2[i]) ++bad;
        if (rules::stfStrikingBonusPerCharge(-9) != 3 ||
            rules::stfStrikingBonusPerCharge(99) != 9) ++bad;
        // Staff of Withering - no recharge accessor,
        // the book prints none
        if (rules::stfWitherBonus() != 1 ||
            rules::stfWitherDamageLo() != 2 ||
            rules::stfWitherDamageHi() != 5 ||
            rules::stfWitherAgeYears() != 10 ||
            rules::stfWitherLimbCharges() != 3 ||
            rules::stfWitherAgelessImmune() != 1) ++bad;
        printf("R245 staves prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
