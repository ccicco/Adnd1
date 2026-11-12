    // ---- R167: disease and infestation audit --------
    // DMG pp.13-14: the contraction chances with
    // every printed modifier, the 16-row disease
    // table and the 6-row parasite table cell by
    // cell, the severity effects, the die roll
    // adjustments, the per-area numbers, and the
    // death relapse.
    {
        Disease disease;
        int bad = 0;
        // the contraction bases and modifiers
        if (disease.diseaseContractBasePercent() != 2 ||
            disease.parasiteContractBasePercent() != 3)
            ++bad;
        if (disease.diseaseModCurrentlyAfflicted() != 1 ||
            disease.diseaseModCrowding() != 1 ||
            disease.diseaseModFilth() != 1 ||
            disease.diseaseModOld() != 2 ||
            disease.diseaseModMarshEnvironment() != 2 ||
            disease.diseaseModHotMoist() != 2 ||
            disease.diseaseModVenerable() != 5 ||
            disease.diseaseModCarrierExposure() != 10 ||
            disease.diseaseModCoolClimate() != -1 ||
            disease.diseaseModColdHighMountains() != -2 ||
            disease.diseaseModShipboardPastTwoWeeks() != -2)
            ++bad;
        if (disease.parasiteModFilth() != 1 ||
            disease.parasiteModImproperlyCookedMeat() != 2 ||
            disease.parasiteModPollutedWater() != 5 ||
            disease.parasiteModSwampJungle() != 5 ||
            disease.parasiteModCoolOrDesert() != -1 ||
            disease.parasiteModColdOrCoolDesert() != -1)
            ++bad;
        if (!disease.diseaseWeeklyCheckWhenFavorable() ||
            !disease.diseaseCheckOnEachCarrierExposure())
            ++bad;
        // the 16-row disease table, cell by cell
        static const int kAcuteHi[16] = {
            3, 1, 6, 3, 1, 7, 7, 6, 2, 4,
            7, 5, 6, 6, 5, 6
        };
        static const int kMildHi[16] = {
            2, 1, 2, 2, 1, 6, 5, 5, 3, 6,
            6, 5, 6, 5, 5, 5
        };
        static const int kSevereHi[16] = {
            5, 3, 5, 4, 3, 7, 7, 7, 7, 8,
            8, 7, 8, 7, 7, 7
        };
        static const int kTermHi[16] = {
            8, 8, 8, 8, 8, 8, 8, 8, 8, 0,
            0, 8, 0, 8, 8, 8
        };
        if (disease.diseaseAreaCount() != 16) ++bad;
        for (int i = 0; i < 16; ++i) {
            Disease disease;
            if (disease.diseaseAcuteHi(i) != kAcuteHi[i] ||
                disease.diseaseChronicLo(i)
                    != kAcuteHi[i] + 1 ||
                disease.diseaseSeverityMildHi(i) != kMildHi[i] ||
                disease.diseaseSeveritySevereHi(i)
                    != kSevereHi[i] ||
                disease.diseaseSeverityTerminalHi(i)
                    != kTermHi[i])
                ++bad;
            if (disease.diseaseHasTerminalColumn(i)
                    != (kTermHi[i] != 0)) ++bad;
            // acute below the line, chronic above it
            if (!disease.diseaseIsAcute(i, kAcuteHi[i]) ||
                disease.diseaseIsAcute(i, kAcuteHi[i] + 1) ||
                disease.diseaseIsChronic(i, kAcuteHi[i]) ||
                !disease.diseaseIsChronic(i, kAcuteHi[i] + 1))
                ++bad;
        }
        // spot the severity splits: row 0 (blood)
        // mild 1-2, severe 3-5, terminal 6-8
        if (disease.diseaseSeverityMildHi(0) != 2 ||
            disease.diseaseSeveritySevereHi(0) != 5 ||
            disease.diseaseSeverityTerminalHi(0) != 8) ++bad;
        // the d100 row mapping, probed at every band
        static const int kRowForD100[12] = {
            1, 4, 5, 7, 9, 13, 19, 41, 43, 49, 53, 97
        };
        static const int kWantRow[12] = {
            0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 12, 15
        };
        for (int i = 0; i < 12; ++i)
            if (disease.diseaseAreaForD100(kRowForD100[i])
                    != kWantRow[i]) ++bad;
        if (disease.diseaseAreaForD100(100) != 15 ||
            disease.diseaseAreaForD100(86) != 14)
            ++bad;
        // the 6-row parasite table, cell by cell
        static const int kParMild[6] = { 2, 2, 1, 1, 7, 2 };
        static const int kParSevere[6] = { 5, 7, 3, 4, 8, 7 };
        static const int kParTerm[6] = { 8, 8, 8, 8, 0, 8 };
        if (disease.parasiteAreaCount() != 6) ++bad;
        for (int i = 0; i < 6; ++i) {
            Disease disease;
            if (disease.parasiteSeverityMildHi(i) != kParMild[i] ||
                disease.parasiteSeveritySevereHi(i) != kParSevere[i] ||
                disease.parasiteSeverityTerminalHi(i) != kParTerm[i])
                ++bad;
        }
        if (disease.parasiteAreaForD100(10) != 0 ||
            disease.parasiteAreaForD100(11) != 1 ||
            disease.parasiteAreaForD100(35) != 1 ||
            disease.parasiteAreaForD100(36) != 2 ||
            disease.parasiteAreaForD100(41) != 3 ||
            disease.parasiteAreaForD100(46) != 4 ||
            disease.parasiteAreaForD100(75) != 4 ||
            disease.parasiteAreaForD100(76) != 5 ||
            disease.parasiteAreaForD100(100) != 5)
            ++bad;
        // the severity effects
        if (disease.diseaseMildWeeksMin() != 1 ||
            disease.diseaseMildWeeksMax() != 3 ||
            disease.diseaseSevereHitPointPercent() != 50 ||
            disease.diseaseSevereDisabledWeeksMin() != 1 ||
            disease.diseaseSevereDisabledWeeksMax() != 2 ||
            disease.diseaseSevereMildRecoveryWeeksMin() != 1 ||
            disease.diseaseSevereMildRecoveryWeeksMax() != 2 ||
            disease.diseaseTerminalDaysMin() != 1 ||
            disease.diseaseTerminalDaysMax() != 12)
            ++bad;
        // the terminal units: brain hours, blood and
        // bones, gastro, skin, urinary weeks,
        // cardio-renal days, generative, muscles,
        // respiratory months
        if (disease.diseaseTerminalUnit(2)
                != DUR_HOURS ||
            disease.diseaseTerminalUnit(0)
                != DUR_WEEKS ||
            disease.diseaseTerminalUnit(1)
                != DUR_WEEKS ||
            disease.diseaseTerminalUnit(3)
                != DUR_DAYS ||
            disease.diseaseTerminalUnit(8)
                != DUR_MONTHS ||
            disease.diseaseTerminalUnit(11)
                != DUR_MONTHS ||
            disease.diseaseTerminalUnit(13)
                != DUR_MONTHS)
            ++bad;
        // the function-loss terminals and the special
        // connective case
        if (!disease.diseaseTerminalIsFunctionLoss(5) ||
            !disease.diseaseTerminalIsFunctionLoss(6) ||
            disease.diseaseTerminalIsFunctionLoss(0) ||
            disease.diseaseEyesBlindBothChance() != 50 ||
            !disease.diseaseTerminalTreatedAsChronicSevere(4) ||
            disease.diseaseTerminalTreatedAsChronicSevere(0))
            ++bad;
        // the per-area ability losses
        if (disease.diseaseBloodWeeklyStrLoss() != 1 ||
            disease.diseaseBloodWeeklyConLoss() != 1 ||
            disease.diseaseBrainIntLoss() != 1 ||
            disease.diseaseBrainDexLoss() != 1 ||
            disease.diseaseConnectiveMonthlyLoss() != 1 ||
            disease.diseaseGastroStrConLoss() != 1 ||
            disease.diseaseJointsDexLoss() != 1 ||
            disease.diseaseMucousConLoss() != 1 ||
            disease.diseaseMuscleStrDexLoss() != 1 ||
            disease.diseaseMuscleSeverePermanentChance() != 25 ||
            disease.diseaseNoseThroatSevereConLossChance() != 10 ||
            disease.diseaseRespiratoryLossChance() != 10 ||
            disease.diseaseSkinSevereChaLossChance() != 10 ||
            disease.diseaseSkinChronicMildChance() != 10 ||
            disease.diseaseSkinChronicSevereChance() != 25 ||
            disease.diseaseUrinaryLossChance() != 20)
            ++bad;
        // the constitution ladder on the die rolls
        static const int kCon[8] = { 1, 3, 6, 10, 13, 16, 18, 19 };
        static const int kAdj[8] = { 2, 1, 0, -1, -2, -3, -4, -4 };
        for (int i = 0; i < 8; ++i)
            if (disease.diseaseConRollAdjust(kCon[i]) != kAdj[i])
                ++bad;
        if (disease.diseaseAdjustChronicDisease() != 1 ||
            disease.diseaseAdjustSevereInfestation() != 1 ||
            disease.diseaseAdjustLowHitPoints() != 1 ||
            disease.diseaseAdjustmentsApplyToParasites() ||
            !disease.diseaseRollMeansNoContraction(0) ||
            !disease.diseaseRollMeansNoContraction(-2) ||
            disease.diseaseRollMeansNoContraction(1))
            ++bad;
        // death from disease or infestation
        if (disease.diseaseDeathRelapseChance() != 90 ||
            disease.diseasePermanentLossFixedByCurative())
            ++bad;
        printf("R167 disease and infestation audit: bad %d\n", bad);
        if (bad) return 1;
    }
