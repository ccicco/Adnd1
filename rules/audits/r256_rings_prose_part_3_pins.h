    // ---- R256: the III.C rings explanation prose part 3 pins audit ----
    // DMG pp.139-140: Spell Storing through X-Ray
    // Vision (part 3 of 3, upload ~10458-10561).
    {
        int bad = 0;
        // the ten rings are the engine III.C table
        // rows 64-100 (the R223 rings.h band pins)
        if (rules::ringRowCount() != 24 ||
            rules::ringRowLo(14) != 64 || rules::ringRowHi(14) != 65 ||
            rules::ringRowLo(23) != 100 || rules::ringRowHi(23) != 100) ++bad;
        static const int kCLo[10] = {
            64, 66, 70, 76, 78, 80, 86, 91, 99, 100,
        };
        static const int kCHi[10] = {
            65, 69, 75, 77, 79, 85, 90, 98, 99, 100,
        };
        for (int i = 0; i < 10; ++i)
            if (rules::ringRowLo(14 + i) != kCLo[i] ||
                rules::ringRowHi(14 + i) != kCHi[i]) ++bad;
        // the dagger cross-pins (the R255-fixed
        // array): Telekinesis, Three Wishes and
        // Wizardry flagged; Weakness and X-Ray not
        if (rules::ringIsChargeLimited(17) != 1 ||
            rules::ringIsChargeLimited(18) != 1 ||
            rules::ringIsChargeLimited(22) != 1 ||
            rules::ringIsChargeLimited(21) != 0 ||
            rules::ringIsChargeLimited(23) != 0 ||
            rules::ringIsMuOnly(22) != 1 ||
            rules::ringChargeLimitedCount() != 7) ++bad;
        // spell storing: 2-5 (d4+1) spells
        if (rules::rgpSpellStoringSpellLo() != 2 ||
            rules::rgpSpellStoringSpellHi() != 5 ||
            rules::rgpSpellStoringSpellDice() != 1 ||
            rules::rgpSpellStoringSpellPlus() != 1 ||
            rules::rgpSpellStoringClericFaces() != 6 ||
            rules::rgpSpellStoringClericSwapOn() != 6 ||
            rules::rgpSpellStoringClericSwapFaces() != 4 ||
            rules::rgpSpellStoringMuFaces() != 8 ||
            rules::rgpSpellStoringMuSwapOn() != 8 ||
            rules::rgpSpellStoringMuSwapFaces() != 6 ||
            rules::rgpSpellStoringRestoreMULevel() != 12 ||
            rules::rgpSpellStoringRestoreSpellLevel() != 6 ||
            rules::rgpSpellStoringCastSegments() != 5) ++bad;
        // spell turning: exceptions and rounding
        if (rules::rgpSpellTurningExceptionCount() != 3 ||
            rules::rgpSpellTurningScrollIsDevice() != 0 ||
            rules::rgpSpellTurningRoundDownMax() != 5 ||
            rules::rgpSpellTurningRoundUpMin() != 6 ||
            rules::rgpSpellTurningRoundUpAdd() != 10 ||
            rules::rgpSpellTurningFloorExample() != 0 ||
            rules::rgpSpellTurningCeilExample() != 100 ||
            rules::rgpSpellTurningSaveAdjPer10Pct() != 1 ||
            rules::rgpSpellTurningSaveAdjAt80() != 2 ||
            rules::rgpSpellTurningSaveAdjAt10() != 9 ||
            rules::rgpSpellTurningSpecialSaveLowMax() != 9 ||
            rules::rgpSpellTurningSpecialSaveHighMin() != 91 ||
            rules::rgpSpellTurningSaveChancePer10Pct() != 5 ||
            rules::rgpSpellTurningLowBandSaveRoll() != 20 ||
            rules::rgpSpellTurningExampleTurnedPct() != 34 ||
            rules::rgpSpellTurningExampleWearerSave() != 15 ||
            rules::rgpSpellTurningExampleCasterSave() != 30 ||
            rules::rgpSpellTurningExampleCasterRollLo() != 15 ||
            rules::rgpSpellTurningMustRemoveToReceive() != 1 ||
            rules::rgpSpellTurningPsionicIsSpellcasting() != 0 ||
            rules::rgpSpellTurningResonantRowCount() != 4) ++bad;
        // the resonating field table
        static const int kResLo[4] = {
            1, 71, 81, 98,
        };
        static const int kResHi[4] = {
            70, 80, 97, 100,
        };
        for (int i = 0; i < 4; ++i)
            if (rules::rgpSpellTurningResonantLo(i) != kResLo[i] ||
                rules::rgpSpellTurningResonantHi(i) != kResHi[i]) ++bad;
        // swimming
        if (rules::rgpSwimmingBaseSpeedInches() != 21 ||
            rules::rgpSwimmingDiveFeet() != 50 ||
            rules::rgpSwimmingDiveDepthInchesPer10Feet() != 18 ||
            rules::rgpSwimmingBreathRounds() != 4 ||
            rules::rgpSwimmingSurfaceHours() != 4 ||
            rules::rgpSwimmingRestHours() != 1 ||
            rules::rgpSwimmingAfloatExceptTyphoon() != 1) ++bad;
        // telekinesis: the weight table
        if (rules::rgpTelekinesisRowCount() != 5 ||
            rules::rgpTelekinesisStartSegments() != 1 ||
            rules::rgpTelekinesisDaggerFlag() != 1) ++bad;
        static const int kTkLo[5] = {
            1, 26, 51, 90, 100,
        };
        static const int kTkHi[5] = {
            25, 50, 89, 99, 100,
        };
        static const int kTkGp[5] = {
            250, 500, 1000, 2000, 4000,
        };
        for (int i = 0; i < 5; ++i)
            if (rules::rgpTelekinesisRowLo(i) != kTkLo[i] ||
                rules::rgpTelekinesisRowHi(i) != kTkHi[i] ||
                rules::rgpTelekinesisRowGp(i) != kTkGp[i]) ++bad;
        // three wishes and warmth
        if (rules::rgpThreeWishesWishCount() != 3 ||
            rules::rgpThreeWishesLimitedPct() != 25 ||
            rules::rgpThreeWishesLimitedBandLo() != 1 ||
            rules::rgpThreeWishesLimitedBandHi() != 25 ||
            rules::rgpThreeWishesDaggerFlag() != 1 ||
            rules::rgpWarmthRestoreHpPerTurn() != 1 ||
            rules::rgpWarmthColdSaveBonus() != 2 ||
            rules::rgpWarmthColdDamagePerDieMod() != -1) ++bad;
        // water walking
        if (rules::rgpWaterWalkingMaxLoadPounds() != 1200 ||
            rules::rgpWaterWalkingDepressionLengthInches() != 18 ||
            rules::rgpWaterWalkingDepressionDepthInches() != 1 ||
            rules::rgpWaterWalkingDepressionPerPounds() != 100) ++bad;
        // weakness: the cursed ring and the reversal
        if (rules::rgpWeaknessLossPerTurn() != 1 ||
            rules::rgpWeaknessFloorScore() != 3 ||
            rules::rgpWeaknessInvisibleFlag() != 1 ||
            rules::rgpWeaknessInvisibleLossMultiplier() != 2 ||
            rules::rgpWeaknessBerserkChancePct() != 5 ||
            rules::rgpWeaknessBerserkTargetScore() != 18 ||
            rules::rgpWeaknessBerserkGainPerTurn() != 1 ||
            rules::rgpWeaknessRestDaysPerPoint() != 1) ++bad;
        // wizardry: the doubling table
        if (rules::rgpWizardryRowCount() != 8 ||
            rules::rgpWizardryMuOnlyFlag() != 1 ||
            rules::rgpWizardryDaggerFlag() != 1) ++bad;
        static const int kWzLo[8] = {
            1, 51, 76, 83, 89, 93, 96, 100,
        };
        static const int kWzHi[8] = {
            50, 75, 82, 88, 92, 95, 99, 100,
        };
        static const int kWzSLo[8] = {
            1, 2, 3, 1, 4, 5, 1, 4,
        };
        static const int kWzSHi[8] = {
            1, 2, 3, 2, 4, 5, 3, 5,
        };
        for (int i = 0; i < 8; ++i)
            if (rules::rgpWizardryRowLo(i) != kWzLo[i] ||
                rules::rgpWizardryRowHi(i) != kWzHi[i] ||
                rules::rgpWizardryRowSpellLo(i) != kWzSLo[i] ||
                rules::rgpWizardryRowSpellHi(i) != kWzSHi[i]) ++bad;
        // x-ray vision: the penetration table
        if (rules::rgpXRayVisionRangeFeet() != 20 ||
            rules::rgpXRayScanSqFtPerRound() != 100 ||
            rules::rgpXRaySecretFindPct() != 90 ||
            rules::rgpXRayDrainIntervalTurns() != 6 ||
            rules::rgpXRayDrainAmount() != 1 ||
            rules::rgpXRayDrainAt3TurnsPerHour() != 2 ||
            rules::rgpXRayDrainAt4TurnsPerHour() != 3 ||
            rules::rgpXRayConRecoveryPerDay() != 2 ||
            rules::rgpXRayExhaustedScore() != 2 ||
            rules::rgpXRayResumeScore() != 3 ||
            rules::rgpXRaySubstanceCount() != 5) ++bad;
        static const int kXrRate[5] = {
            48, 30, 12, 1, 0,
        };
        static const int kXrMax[5] = {
            240, 240, 120, 10, 0,
        };
        for (int i = 0; i < 5; ++i)
            if (rules::rgpXRaySubstanceRateInches(i) != kXrRate[i] ||
                rules::rgpXRaySubstanceMaxInches(i) != kXrMax[i]) ++bad;
        printf("R256 rings prose part 3 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
