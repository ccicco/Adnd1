    // ---- R462 WSG food and water pin audit ----
    // The Table 28 ladder and the Table 29 grid cell by cell, the 12-hour
    // check cadence with the +1/+2 modifier ladders, the water tolerance
    // modifier set with the floor, the animal incapacitation and recovery
    // rules, the ration arithmetic and the daily water requirement arithmetic
    // - every cell, const, bool and chain limit verified against the model.
    {
        using namespace rules;
        int bad = 0;
    if (wnfCheckEveryHours() != 12
            || wnfCheckIncumPerCheck() != 1
            || wnfWeakCheckIncum() != 2
            || wnfWeakAtkPenaltyFirstDay() != 1
            || wnfWeakPenaltyWorsenPerDay() != 1
            || wnfRecoveryStepsPerDay() != 2
            || wnfIncapPenaltyFloor() != 4
            || wnfIncapRecoveryMinMeals() != 2
            || wnfIncapFailedCheckIncum() != 4
            || wnfIncapHpLossPerHourDie() != 6
            || wnfIncapHpRegainPerHourDie() != 4
            || wnfIncapPenaltyPerHour() != 1
            || wnfDistressStrenuousTurnLimit() != 2
            || wnfWaterBaseTolerance() != 3
            || wnfWaterModHighWaterFood() != 2
            || wnfWaterModHeavy() != 1
            || wnfWaterModFemale() != 1
            || wnfWaterModNoStrenuous() != 1
            || wnfWaterModHot90() != -1
            || wnfWaterModLessMeal() != -1
            || wnfWaterModLowStrCon() != -1
            || wnfWaterToleranceFloor() != 1
            || wnfWaterNoStrenuousLossTurns() != 1
            || wnfAnimalHalveFactor() != 2
            || wnfAnimalHardWorkTurns() != 3
            || wnfAnimalIncapMultNum() != 3
            || wnfAnimalIncapMultDen() != 2
            || wnfAnimalRestMinHours() != 13
            || wnfAnimalRestMaxHours() != 24
            || wnfAnimalRestDieSides() != 12
            || wnfAnimalRestDieBonus() != 12
            || wnfAnimalEffortDeathTurns() != 1
            || wnfAnimalIncapIdleDeathDays() != 1
            || wnfFoodHumanMinLb() != 1
            || wnfFoodHumanMaxLb() != 2
            || wnfFoodElfNum() != 3
            || wnfFoodElfDen() != 4
            || wnfFoodSmallNum() != 1
            || wnfFoodSmallDen() != 2
            || wnfRationWeekDays() != 7
            || wnfStdRationEncGp() != 200
            || wnfStdRationWeightLb() != 14
            || wnfStdRationBulkGp() != 60
            || wnfStdRationDailyLb() != 2
            || wnfIronRationEncGp() != 75
            || wnfIronRationBulkGp() != 5
            || wnfIronRationWeightLb() != 7
            || wnfIronRationDailyLb() != 1
            || wnfMeatVegNourishRatio() != 2
            || wnfMealsPerDayMin() != 2
            || wnfMissedMealToHitMod() != -1
            || wnfMissedMealCheckMod() != 1
            || wnfHalfRationCheatNum() != 1
            || wnfHalfRationCheatDen() != 2
            || wnfHalfRationDaysNum() != 3
            || wnfHalfRationDaysDen() != 2
            || wnfBandCount() != 6
            || wnfTempBandCount() != 4
            || wnfElfWaterRedNum() != 1
            || wnfElfWaterRedDen() != 4
            || wnfDemiWaterRedNum() != 1
            || wnfDemiWaterRedDen() != 3
            || wnfHighWaterFoodMinNum() != 1
            || wnfHighWaterFoodMinDen() != 4
            || wnfHighWaterFoodMaxNum() != 1
            || wnfHighWaterFoodMaxDen() != 3
            || wnfInactHourLimit() != 1
            || wnfLightHourOver() != 1
            || wnfModerateHourOver() != 2
            || wnfHeavyHourOver() != 4
            || wnfCubicFootGallons() != 7
            || wnfGallonPints() != 8
            || wnfWaterEncPerGallon() != 50
            || wnfContainerEncPerGallons() != 3
            || wnfContainerEncGp() != 50
            || wnfWaterskinGallons() != 1
            || !wnfFoodToleranceRequiresWater()
            || !wnfWaterAnyDrinkableLiquid()
            || !wnfStandardRationsHighWater()
            || wnfIronRationsHighWater()
            || !wnfGreenPlantsRawMeatHighWater()
            || wnfTreeBarkHighWater()
            || !wnfWaterModsCumulative()
            || !wnfWaterDeprivationUsesFoodConditions()
            || !wnfTotalDeprivationIncapOnFail()
            || !wnfDistressFailExhaustedNotFatigued()
            || !wnfIncapNoVoluntaryActivity()
            || !wnfAnimalMoveCarryHalved()
            || !wnfOvereatingNoBenefit()
            || !wnfHalfRationFullMealRecovers()
            || !wnfHalfRationIndefiniteIfIdle()
            || !wnfMissedMealBelowAvgSusceptible()
            || !wnfNotEnoughWaterAsBadAsNone()
            || !wnfAnimalsRecoverQuickly()
        )
            ++bad;
        // the Table 28 tolerance ladder (4/5/6/7/8/10 days)
        int C28[6][1] = {
            {4},
            {5},
            {6},
            {7},
            {8},
            {10},
            };
        for (int b = 0;
             b < wnfBandCount();
             ++b) {
            int vals[1];
            vals[0] = wnfToleranceDays(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != C28[b][c])
                    ++bad;
            }
        }
        // the Table 29 pint grid (rows: below 50, 50-70, 71-90, above 90)
        int C29[4][4] = {
            {5,6,8,9},
            {6,7,9,10},
            {7,8,10,12},
            {8,10,12,16},
            };
        for (int b = 0;
             b < wnfTempBandCount();
             ++b) {
            int vals[4];
            vals[0] = wnfWaterPintInact(b);
            vals[1] = wnfWaterPintLight(b);
            vals[2] = wnfWaterPintMod(b);
            vals[3] = wnfWaterPintHeavy(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C29[b][c])
                    ++bad;
            }
        }
        // the wnfBandFor band-for boundaries
    if (wnfBandFor(14) != 0
            || wnfBandFor(15) != 0
            || wnfBandFor(19) != 1
            || wnfBandFor(16) != 1
            || wnfBandFor(24) != 2
            || wnfBandFor(20) != 2
            || wnfBandFor(30) != 3
            || wnfBandFor(25) != 3
            || wnfBandFor(35) != 4
            || wnfBandFor(31) != 4
            || wnfBandFor(36) != 5
        )
            ++bad;
        // the wnfTempBandFor band-for boundaries
    if (wnfTempBandFor(48) != 0
            || wnfTempBandFor(49) != 0
            || wnfTempBandFor(70) != 1
            || wnfTempBandFor(50) != 1
            || wnfTempBandFor(90) != 2
            || wnfTempBandFor(71) != 2
            || wnfTempBandFor(91) != 3
        )
            ++bad;
        // the book example: Str 12 + Con 14 = 26 lands in band 3 with a
        // seven-day tolerance
    if (wnfToleranceDays(wnfBandFor(26)) != 7
        )
            ++bad;
        // the example check at +2 fails a Con 14 on 13 or higher
    if (15 - 2 * wnfCheckIncumPerCheck() != 13
        )
            ++bad;
        // the weakened example check at +4 fails on 11 or higher (+2 ladder
        // plus the +2 weakened shift)
    if (15 - (2 * wnfCheckIncumPerCheck() + wnfWeakCheckIncum()) != 11
        )
            ++bad;
        // the elf three-fourths ration: 2 lb human -> 1.5 lb elf,
        // cross-multiplied
    if (wnfFoodElfNum() * 8 != wnfFoodElfDen() * 6
        )
            ++bad;
        // the gnome or halfling half ration, cross-multiplied
    if (wnfFoodSmallNum() * 4 != wnfFoodSmallDen() * 2
        )
            ++bad;
        // the standard rations pack: 14 lb over a week is 2 lb per day
    if (wnfStdRationWeightLb() != wnfStdRationDailyLb() * wnfRationWeekDays()
        )
            ++bad;
        // the iron rations pack: 7 lb over a week is 1 lb per day
    if (wnfIronRationWeightLb() != wnfIronRationDailyLb() *
        wnfRationWeekDays()
        )
            ++bad;
        // the half-ration cheat: 1.5 times the tolerance, cross-multiplied
        // (tolerance 5 -> 7 days)
    if (wnfHalfRationDaysNum() * 10 != wnfHalfRationDaysDen() * 15
        )
            ++bad;
        // the animal incapacitation multiple: 1.5 times tolerance rounded
        // down (tolerance 4 -> 6 days)
    if (wnfAnimalIncapMultNum() * 8 != wnfAnimalIncapMultDen() * 12
        )
            ++bad;
        // the animal recovery rest: 1d12 + 12 spans 13-24 hours
    if (wnfAnimalRestDieSides() + wnfAnimalRestDieBonus() !=
        wnfAnimalRestMaxHours()
        )
            ++bad;
        // the recovery rest floor: the die minimum plus one is 13 hours
    if (wnfAnimalRestDieBonus() + 1 != wnfAnimalRestMinHours()
        )
            ++bad;
        // a cubic foot of create water: 7 gallons x 8 pints = 56 pints
    if (wnfCubicFootGallons() * wnfGallonPints() != 56
        )
            ++bad;
        // the Table 29 corner: heavy activity above 90 costs 16 pints
    if (wnfWaterPintHeavy(wnfTempBandFor(100)) != 16
        )
            ++bad;
        printf("R462 WSG food and water pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
