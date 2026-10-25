    // ---- R167: disease and infestation audit --------
    // DMG pp.13-14: the contraction chances with
    // every printed modifier, the 16-row disease
    // table and the 6-row parasite table cell by
    // cell, the severity effects, the die roll
    // adjustments, the per-area numbers, and the
    // death relapse.
    {
        int bad = 0;
        // the contraction bases and modifiers
        if (rules::diseaseContractBasePercent() != 2 ||
            rules::parasiteContractBasePercent() != 3)
            ++bad;
        if (rules::diseaseModCurrentlyAfflicted() != 1 ||
            rules::diseaseModCrowding() != 1 ||
            rules::diseaseModFilth() != 1 ||
            rules::diseaseModOld() != 2 ||
            rules::diseaseModMarshEnvironment() != 2 ||
            rules::diseaseModHotMoist() != 2 ||
            rules::diseaseModVenerable() != 5 ||
            rules::diseaseModCarrierExposure() != 10 ||
            rules::diseaseModCoolClimate() != -1 ||
            rules::diseaseModColdHighMountains() != -2 ||
            rules::diseaseModShipboardPastTwoWeeks() != -2)
            ++bad;
        if (rules::parasiteModFilth() != 1 ||
            rules::parasiteModImproperlyCookedMeat() != 2 ||
            rules::parasiteModPollutedWater() != 5 ||
            rules::parasiteModSwampJungle() != 5 ||
            rules::parasiteModCoolOrDesert() != -1 ||
            rules::parasiteModColdOrCoolDesert() != -1)
            ++bad;
        if (!rules::diseaseWeeklyCheckWhenFavorable() ||
            !rules::diseaseCheckOnEachCarrierExposure())
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
        if (rules::diseaseAreaCount() != 16) ++bad;
        for (int i = 0; i < 16; ++i) {
            if (rules::diseaseAcuteHi(i) != kAcuteHi[i] ||
                rules::diseaseChronicLo(i)
                    != kAcuteHi[i] + 1 ||
                rules::diseaseSeverityMildHi(i) != kMildHi[i] ||
                rules::diseaseSeveritySevereHi(i)
                    != kSevereHi[i] ||
                rules::diseaseSeverityTerminalHi(i)
                    != kTermHi[i])
                ++bad;
            if (rules::diseaseHasTerminalColumn(i)
                    != (kTermHi[i] != 0)) ++bad;
            // acute below the line, chronic above it
            if (!rules::diseaseIsAcute(i, kAcuteHi[i]) ||
                rules::diseaseIsAcute(i, kAcuteHi[i] + 1) ||
                rules::diseaseIsChronic(i, kAcuteHi[i]) ||
                !rules::diseaseIsChronic(i, kAcuteHi[i] + 1))
                ++bad;
        }
        // spot the severity splits: row 0 (blood)
        // mild 1-2, severe 3-5, terminal 6-8
        if (rules::diseaseSeverityMildHi(0) != 2 ||
            rules::diseaseSeveritySevereHi(0) != 5 ||
            rules::diseaseSeverityTerminalHi(0) != 8) ++bad;
        // the d100 row mapping, probed at every band
        static const int kRowForD100[12] = {
            1, 4, 5, 7, 9, 13, 19, 41, 43, 49, 53, 97
        };
        static const int kWantRow[12] = {
            0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 12, 15
        };
        for (int i = 0; i < 12; ++i)
            if (rules::diseaseAreaForD100(kRowForD100[i])
                    != kWantRow[i]) ++bad;
        if (rules::diseaseAreaForD100(100) != 15 ||
            rules::diseaseAreaForD100(86) != 14)
            ++bad;
        // the 6-row parasite table, cell by cell
        static const int kParMild[6] = { 2, 2, 1, 1, 7, 2 };
        static const int kParSevere[6] = { 5, 7, 3, 4, 8, 7 };
        static const int kParTerm[6] = { 8, 8, 8, 8, 0, 8 };
        if (rules::parasiteAreaCount() != 6) ++bad;
        for (int i = 0; i < 6; ++i) {
            if (rules::parasiteSeverityMildHi(i) != kParMild[i] ||
                rules::parasiteSeveritySevereHi(i) != kParSevere[i] ||
                rules::parasiteSeverityTerminalHi(i) != kParTerm[i])
                ++bad;
        }
        if (rules::parasiteAreaForD100(10) != 0 ||
            rules::parasiteAreaForD100(11) != 1 ||
            rules::parasiteAreaForD100(35) != 1 ||
            rules::parasiteAreaForD100(36) != 2 ||
            rules::parasiteAreaForD100(41) != 3 ||
            rules::parasiteAreaForD100(46) != 4 ||
            rules::parasiteAreaForD100(75) != 4 ||
            rules::parasiteAreaForD100(76) != 5 ||
            rules::parasiteAreaForD100(100) != 5)
            ++bad;
        // the severity effects
        if (rules::diseaseMildWeeksMin() != 1 ||
            rules::diseaseMildWeeksMax() != 3 ||
            rules::diseaseSevereHitPointPercent() != 50 ||
            rules::diseaseSevereDisabledWeeksMin() != 1 ||
            rules::diseaseSevereDisabledWeeksMax() != 2 ||
            rules::diseaseSevereMildRecoveryWeeksMin() != 1 ||
            rules::diseaseSevereMildRecoveryWeeksMax() != 2 ||
            rules::diseaseTerminalDaysMin() != 1 ||
            rules::diseaseTerminalDaysMax() != 12)
            ++bad;
        // the terminal units: brain hours, blood and
        // bones, gastro, skin, urinary weeks,
        // cardio-renal days, generative, muscles,
        // respiratory months
        if (rules::diseaseTerminalUnit(2)
                != rules::DUR_HOURS ||
            rules::diseaseTerminalUnit(0)
                != rules::DUR_WEEKS ||
            rules::diseaseTerminalUnit(1)
                != rules::DUR_WEEKS ||
            rules::diseaseTerminalUnit(3)
                != rules::DUR_DAYS ||
            rules::diseaseTerminalUnit(8)
                != rules::DUR_MONTHS ||
            rules::diseaseTerminalUnit(11)
                != rules::DUR_MONTHS ||
            rules::diseaseTerminalUnit(13)
                != rules::DUR_MONTHS)
            ++bad;
        // the function-loss terminals and the special
        // connective case
        if (!rules::diseaseTerminalIsFunctionLoss(5) ||
            !rules::diseaseTerminalIsFunctionLoss(6) ||
            rules::diseaseTerminalIsFunctionLoss(0) ||
            rules::diseaseEyesBlindBothChance() != 50 ||
            !rules::diseaseTerminalTreatedAsChronicSevere(4) ||
            rules::diseaseTerminalTreatedAsChronicSevere(0))
            ++bad;
        // the per-area ability losses
        if (rules::diseaseBloodWeeklyStrLoss() != 1 ||
            rules::diseaseBloodWeeklyConLoss() != 1 ||
            rules::diseaseBrainIntLoss() != 1 ||
            rules::diseaseBrainDexLoss() != 1 ||
            rules::diseaseConnectiveMonthlyLoss() != 1 ||
            rules::diseaseGastroStrConLoss() != 1 ||
            rules::diseaseJointsDexLoss() != 1 ||
            rules::diseaseMucousConLoss() != 1 ||
            rules::diseaseMuscleStrDexLoss() != 1 ||
            rules::diseaseMuscleSeverePermanentChance() != 25 ||
            rules::diseaseNoseThroatSevereConLossChance() != 10 ||
            rules::diseaseRespiratoryLossChance() != 10 ||
            rules::diseaseSkinSevereChaLossChance() != 10 ||
            rules::diseaseSkinChronicMildChance() != 10 ||
            rules::diseaseSkinChronicSevereChance() != 25 ||
            rules::diseaseUrinaryLossChance() != 20)
            ++bad;
        // the constitution ladder on the die rolls
        static const int kCon[8] = { 1, 3, 6, 10, 13, 16, 18, 19 };
        static const int kAdj[8] = { 2, 1, 0, -1, -2, -3, -4, -4 };
        for (int i = 0; i < 8; ++i)
            if (rules::diseaseConRollAdjust(kCon[i]) != kAdj[i])
                ++bad;
        if (rules::diseaseAdjustChronicDisease() != 1 ||
            rules::diseaseAdjustSevereInfestation() != 1 ||
            rules::diseaseAdjustLowHitPoints() != 1 ||
            rules::diseaseAdjustmentsApplyToParasites() ||
            !rules::diseaseRollMeansNoContraction(0) ||
            !rules::diseaseRollMeansNoContraction(-2) ||
            rules::diseaseRollMeansNoContraction(1))
            ++bad;
        // death from disease or infestation
        if (rules::diseaseDeathRelapseChance() != 90 ||
            rules::diseasePermanentLossFixedByCurative())
            ++bad;
        printf("R167 disease and infestation audit: bad %d\n", bad);
        if (bad) return 1;
    }
