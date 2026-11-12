    // ---- R256: the III.C rings explanation prose part 3 pins audit ----
    // DMG pp.139-140: Spell Storing through X-Ray
    // Vision (part 3 of 3, upload ~10458-10561).
    {
        Rings rings;
        Rings_spell_storing_to_x_ray_vision rings_spell_storing_to_x_ray_vision;
        int bad = 0;
        // the ten rings are the engine III.C table
        // rows 64-100 (the R223 rings.h band pins)
        if (rings.ringRowCount() != 24 ||
            rings.ringRowLo(14) != 64 || rings.ringRowHi(14) != 65 ||
            rings.ringRowLo(23) != 100 || rings.ringRowHi(23) != 100) ++bad;
        static const int kCLo[10] = {
            64, 66, 70, 76, 78, 80, 86, 91, 99, 100,
        };
        static const int kCHi[10] = {
            65, 69, 75, 77, 79, 85, 90, 98, 99, 100,
        };
        for (int i = 0; i < 10; ++i)
            if (rings.ringRowLo(14 + i) != kCLo[i] ||
                rings.ringRowHi(14 + i) != kCHi[i]) ++bad;
        // the dagger cross-pins (the R255-fixed
        // array): Telekinesis, Three Wishes and
        // Wizardry flagged; Weakness and X-Ray not
        if (rings.ringIsChargeLimited(17) != 1 ||
            rings.ringIsChargeLimited(18) != 1 ||
            rings.ringIsChargeLimited(22) != 1 ||
            rings.ringIsChargeLimited(21) != 0 ||
            rings.ringIsChargeLimited(23) != 0 ||
            rings.ringIsMuOnly(22) != 1 ||
            rings.ringChargeLimitedCount() != 7) ++bad;
        // spell storing: 2-5 (d4+1) spells
        if (rings_spell_storing_to_x_ray_vision.rgpSpellStoringSpellLo() != 2 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringSpellHi() != 5 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringSpellDice() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringSpellPlus() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringClericFaces() != 6 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringClericSwapOn() != 6 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringClericSwapFaces() != 4 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringMuFaces() != 8 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringMuSwapOn() != 8 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringMuSwapFaces() != 6 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringRestoreMULevel() != 12 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringRestoreSpellLevel() != 6 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellStoringCastSegments() != 5) ++bad;
        // spell turning: exceptions and rounding
        if (rings_spell_storing_to_x_ray_vision.rgpSpellTurningExceptionCount() != 3 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningScrollIsDevice() != 0 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningRoundDownMax() != 5 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningRoundUpMin() != 6 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningRoundUpAdd() != 10 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningFloorExample() != 0 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningCeilExample() != 100 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningSaveAdjPer10Pct() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningSaveAdjAt80() != 2 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningSaveAdjAt10() != 9 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningSpecialSaveLowMax() != 9 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningSpecialSaveHighMin() != 91 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningSaveChancePer10Pct() != 5 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningLowBandSaveRoll() != 20 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningExampleTurnedPct() != 34 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningExampleWearerSave() != 15 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningExampleCasterSave() != 30 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningExampleCasterRollLo() != 15 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningMustRemoveToReceive() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningPsionicIsSpellcasting() != 0 ||
            rings_spell_storing_to_x_ray_vision.rgpSpellTurningResonantRowCount() != 4) ++bad;
        // the resonating field table
        static const int kResLo[4] = {
            1, 71, 81, 98,
        };
        static const int kResHi[4] = {
            70, 80, 97, 100,
        };
        for (int i = 0; i < 4; ++i)
            if (rings_spell_storing_to_x_ray_vision.rgpSpellTurningResonantLo(i) != kResLo[i] ||
                rings_spell_storing_to_x_ray_vision.rgpSpellTurningResonantHi(i) != kResHi[i]) ++bad;
        // swimming
        if (rings_spell_storing_to_x_ray_vision.rgpSwimmingBaseSpeedInches() != 21 ||
            rings_spell_storing_to_x_ray_vision.rgpSwimmingDiveFeet() != 50 ||
            rings_spell_storing_to_x_ray_vision.rgpSwimmingDiveDepthInchesPer10Feet() != 18 ||
            rings_spell_storing_to_x_ray_vision.rgpSwimmingBreathRounds() != 4 ||
            rings_spell_storing_to_x_ray_vision.rgpSwimmingSurfaceHours() != 4 ||
            rings_spell_storing_to_x_ray_vision.rgpSwimmingRestHours() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpSwimmingAfloatExceptTyphoon() != 1) ++bad;
        // telekinesis: the weight table
        if (rings_spell_storing_to_x_ray_vision.rgpTelekinesisRowCount() != 5 ||
            rings_spell_storing_to_x_ray_vision.rgpTelekinesisStartSegments() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpTelekinesisDaggerFlag() != 1) ++bad;
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
            if (rings_spell_storing_to_x_ray_vision.rgpTelekinesisRowLo(i) != kTkLo[i] ||
                rings_spell_storing_to_x_ray_vision.rgpTelekinesisRowHi(i) != kTkHi[i] ||
                rings_spell_storing_to_x_ray_vision.rgpTelekinesisRowGp(i) != kTkGp[i]) ++bad;
        // three wishes and warmth
        if (rings_spell_storing_to_x_ray_vision.rgpThreeWishesWishCount() != 3 ||
            rings_spell_storing_to_x_ray_vision.rgpThreeWishesLimitedPct() != 25 ||
            rings_spell_storing_to_x_ray_vision.rgpThreeWishesLimitedBandLo() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpThreeWishesLimitedBandHi() != 25 ||
            rings_spell_storing_to_x_ray_vision.rgpThreeWishesDaggerFlag() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpWarmthRestoreHpPerTurn() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpWarmthColdSaveBonus() != 2 ||
            rings_spell_storing_to_x_ray_vision.rgpWarmthColdDamagePerDieMod() != -1) ++bad;
        // water walking
        if (rings_spell_storing_to_x_ray_vision.rgpWaterWalkingMaxLoadPounds() != 1200 ||
            rings_spell_storing_to_x_ray_vision.rgpWaterWalkingDepressionLengthInches() != 18 ||
            rings_spell_storing_to_x_ray_vision.rgpWaterWalkingDepressionDepthInches() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpWaterWalkingDepressionPerPounds() != 100) ++bad;
        // weakness: the cursed ring and the reversal
        if (rings_spell_storing_to_x_ray_vision.rgpWeaknessLossPerTurn() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpWeaknessFloorScore() != 3 ||
            rings_spell_storing_to_x_ray_vision.rgpWeaknessInvisibleFlag() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpWeaknessInvisibleLossMultiplier() != 2 ||
            rings_spell_storing_to_x_ray_vision.rgpWeaknessBerserkChancePct() != 5 ||
            rings_spell_storing_to_x_ray_vision.rgpWeaknessBerserkTargetScore() != 18 ||
            rings_spell_storing_to_x_ray_vision.rgpWeaknessBerserkGainPerTurn() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpWeaknessRestDaysPerPoint() != 1) ++bad;
        // wizardry: the doubling table
        if (rings_spell_storing_to_x_ray_vision.rgpWizardryRowCount() != 8 ||
            rings_spell_storing_to_x_ray_vision.rgpWizardryMuOnlyFlag() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpWizardryDaggerFlag() != 1) ++bad;
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
            if (rings_spell_storing_to_x_ray_vision.rgpWizardryRowLo(i) != kWzLo[i] ||
                rings_spell_storing_to_x_ray_vision.rgpWizardryRowHi(i) != kWzHi[i] ||
                rings_spell_storing_to_x_ray_vision.rgpWizardryRowSpellLo(i) != kWzSLo[i] ||
                rings_spell_storing_to_x_ray_vision.rgpWizardryRowSpellHi(i) != kWzSHi[i]) ++bad;
        // x-ray vision: the penetration table
        if (rings_spell_storing_to_x_ray_vision.rgpXRayVisionRangeFeet() != 20 ||
            rings_spell_storing_to_x_ray_vision.rgpXRayScanSqFtPerRound() != 100 ||
            rings_spell_storing_to_x_ray_vision.rgpXRaySecretFindPct() != 90 ||
            rings_spell_storing_to_x_ray_vision.rgpXRayDrainIntervalTurns() != 6 ||
            rings_spell_storing_to_x_ray_vision.rgpXRayDrainAmount() != 1 ||
            rings_spell_storing_to_x_ray_vision.rgpXRayDrainAt3TurnsPerHour() != 2 ||
            rings_spell_storing_to_x_ray_vision.rgpXRayDrainAt4TurnsPerHour() != 3 ||
            rings_spell_storing_to_x_ray_vision.rgpXRayConRecoveryPerDay() != 2 ||
            rings_spell_storing_to_x_ray_vision.rgpXRayExhaustedScore() != 2 ||
            rings_spell_storing_to_x_ray_vision.rgpXRayResumeScore() != 3 ||
            rings_spell_storing_to_x_ray_vision.rgpXRaySubstanceCount() != 5) ++bad;
        static const int kXrRate[5] = {
            48, 30, 12, 1, 0,
        };
        static const int kXrMax[5] = {
            240, 240, 120, 10, 0,
        };
        for (int i = 0; i < 5; ++i)
            if (rings_spell_storing_to_x_ray_vision.rgpXRaySubstanceRateInches(i) != kXrRate[i] ||
                rings_spell_storing_to_x_ray_vision.rgpXRaySubstanceMaxInches(i) != kXrMax[i]) ++bad;
        printf("R256 rings prose part 3 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
