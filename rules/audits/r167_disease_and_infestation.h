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
        if (disease.contractBasePercent() != 2 ||
            disease.parasiteContractBasePercent() != 3)
            ++bad;
        if (disease.modCurrentlyAfflicted() != 1 ||
            disease.modCrowding() != 1 ||
            disease.modFilth() != 1 ||
            disease.modOld() != 2 ||
            disease.modMarshEnvironment() != 2 ||
            disease.modHotMoist() != 2 ||
            disease.modVenerable() != 5 ||
            disease.modCarrierExposure() != 10 ||
            disease.modCoolClimate() != -1 ||
            disease.modColdHighMountains() != -2 ||
            disease.modShipboardPastTwoWeeks() != -2)
            ++bad;
        if (disease.parasiteModFilth() != 1 ||
            disease.parasiteModImproperlyCookedMeat() != 2 ||
            disease.parasiteModPollutedWater() != 5 ||
            disease.parasiteModSwampJungle() != 5 ||
            disease.parasiteModCoolOrDesert() != -1 ||
            disease.parasiteModColdOrCoolDesert() != -1)
            ++bad;
        if (!disease.weeklyCheckWhenFavorable() ||
            !disease.checkOnEachCarrierExposure())
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
        if (disease.areaCount() != 16) ++bad;
        for (int i = 0; i < 16; ++i) {
            Disease disease;
            if (disease.acuteHi(i) != kAcuteHi[i] ||
                disease.chronicLo(i)
                    != kAcuteHi[i] + 1 ||
                disease.severityMildHi(i) != kMildHi[i] ||
                disease.severitySevereHi(i)
                    != kSevereHi[i] ||
                disease.severityTerminalHi(i)
                    != kTermHi[i])
                ++bad;
            if (disease.hasTerminalColumn(i)
                    != (kTermHi[i] != 0)) ++bad;
            // acute below the line, chronic above it
            if (!disease.isAcute(i, kAcuteHi[i]) ||
                disease.isAcute(i, kAcuteHi[i] + 1) ||
                disease.isChronic(i, kAcuteHi[i]) ||
                !disease.isChronic(i, kAcuteHi[i] + 1))
                ++bad;
        }
        // spot the severity splits: row 0 (blood)
        // mild 1-2, severe 3-5, terminal 6-8
        if (disease.severityMildHi(0) != 2 ||
            disease.severitySevereHi(0) != 5 ||
            disease.severityTerminalHi(0) != 8) ++bad;
        // the d100 row mapping, probed at every band
        static const int kRowForD100[12] = {
            1, 4, 5, 7, 9, 13, 19, 41, 43, 49, 53, 97
        };
        static const int kWantRow[12] = {
            0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 12, 15
        };
        for (int i = 0; i < 12; ++i)
            if (disease.areaForD100(kRowForD100[i])
                    != kWantRow[i]) ++bad;
        if (disease.areaForD100(100) != 15 ||
            disease.areaForD100(86) != 14)
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
        if (disease.mildWeeksMin() != 1 ||
            disease.mildWeeksMax() != 3 ||
            disease.severeHitPointPercent() != 50 ||
            disease.severeDisabledWeeksMin() != 1 ||
            disease.severeDisabledWeeksMax() != 2 ||
            disease.severeMildRecoveryWeeksMin() != 1 ||
            disease.severeMildRecoveryWeeksMax() != 2 ||
            disease.terminalDaysMin() != 1 ||
            disease.terminalDaysMax() != 12)
            ++bad;
        // the terminal units: brain hours, blood and
        // bones, gastro, skin, urinary weeks,
        // cardio-renal days, generative, muscles,
        // respiratory months
        if (disease.terminalUnit(2)
                != DUR_HOURS ||
            disease.terminalUnit(0)
                != DUR_WEEKS ||
            disease.terminalUnit(1)
                != DUR_WEEKS ||
            disease.terminalUnit(3)
                != DUR_DAYS ||
            disease.terminalUnit(8)
                != DUR_MONTHS ||
            disease.terminalUnit(11)
                != DUR_MONTHS ||
            disease.terminalUnit(13)
                != DUR_MONTHS)
            ++bad;
        // the function-loss terminals and the special
        // connective case
        if (!disease.terminalIsFunctionLoss(5) ||
            !disease.terminalIsFunctionLoss(6) ||
            disease.terminalIsFunctionLoss(0) ||
            disease.eyesBlindBothChance() != 50 ||
            !disease.terminalTreatedAsChronicSevere(4) ||
            disease.terminalTreatedAsChronicSevere(0))
            ++bad;
        // the per-area ability losses
        if (disease.bloodWeeklyStrLoss() != 1 ||
            disease.bloodWeeklyConLoss() != 1 ||
            disease.brainIntLoss() != 1 ||
            disease.brainDexLoss() != 1 ||
            disease.connectiveMonthlyLoss() != 1 ||
            disease.gastroStrConLoss() != 1 ||
            disease.jointsDexLoss() != 1 ||
            disease.mucousConLoss() != 1 ||
            disease.muscleStrDexLoss() != 1 ||
            disease.muscleSeverePermanentChance() != 25 ||
            disease.noseThroatSevereConLossChance() != 10 ||
            disease.respiratoryLossChance() != 10 ||
            disease.skinSevereChaLossChance() != 10 ||
            disease.skinChronicMildChance() != 10 ||
            disease.skinChronicSevereChance() != 25 ||
            disease.urinaryLossChance() != 20)
            ++bad;
        // the constitution ladder on the die rolls
        static const int kCon[8] = { 1, 3, 6, 10, 13, 16, 18, 19 };
        static const int kAdj[8] = { 2, 1, 0, -1, -2, -3, -4, -4 };
        for (int i = 0; i < 8; ++i)
            if (disease.conRollAdjust(kCon[i]) != kAdj[i])
                ++bad;
        if (disease.adjustChronicDisease() != 1 ||
            disease.adjustSevereInfestation() != 1 ||
            disease.adjustLowHitPoints() != 1 ||
            disease.adjustmentsApplyToParasites() ||
            !disease.rollMeansNoContraction(0) ||
            !disease.rollMeansNoContraction(-2) ||
            disease.rollMeansNoContraction(1))
            ++bad;
        // death from disease or infestation
        if (disease.deathRelapseChance() != 90 ||
            disease.permanentLossFixedByCurative())
            ++bad;
        printf("R167 disease and infestation audit: bad %d\n", bad);
        if (bad) return 1;
    }
