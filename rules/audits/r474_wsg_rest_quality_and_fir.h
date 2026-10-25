    // ---- R474 WSG rest quality and fire pin audit ----
    // The Table 38 grids (the three fire sizes by fuel, start dice, refuel,
    // wind resistance, capacity and visibility, plus the warmth-at-distance
    // ladder with the dash-as-no-warmth sentinel), the eight rest-quality
    // penalties with the plate-armor waivers, the no-rest threshold, the
    // extreme-weather bar, the longer-sleep compensation, the armor donning
    // and doffing discipline and the fire-function prose are audit examples.
    {
        using namespace rules;
        int bad = 0;
    if (wgfPenNotProne() != 1
            || wgfPenBareGround() != 1
            || wgfPenTempBelow0() != 1
            || wgfPenTempAbove90() != 2
            || wgfPenWindNoShelter() != 2
            || wgfPenPrecipNoShelter() != 3
            || wgfPenMetalArmor() != 3
            || wgfPenPlateArmor() != 4
            || wgfPlateTypicalNight() != 5
            || wgfPlateNightGoodRest() != 1
            || wgfPlateLongSleep() != 9
            || wgfPlateLongRefresh() != 5
            || wgfDonBase() != 9
            || wgfPlateAddRounds() != 2
            || wgfUnaidedAddRounds() != 5
            || wgfLeatherAC() != 8
            || wgfLeatherDonRounds() != 1
            || wgfBandedAC() != 4
            || wgfBandedDonRounds() != 5
            || wgfFullPlateAC() != 0
            || wgfFullPlateHelpedRounds() != 11
            || wgfFullPlateSoloRounds() != 16
            || wgfFullPlateSoloDoffRounds() != 8
            || wgfFireSizes() != 3
            || wgfBurnHours() != 8
            || !wgfQualityNotNight()
            || !wgfComfortRequired()
            || !wgfPenaltiesSummed()
            || !wgfNoRestWhenExceeded()
            || !wgfStarPenaltiesSkipPlate()
            || !wgfExtremeWeatherNoSleep()
            || !wgfStormCommotionCaveat()
            || !wgfDmMayExpandPenalties()
            || !wgfLongerSleepCompensates()
            || !wgfArmorSleepPrudent()
            || !wgfOneNightInTwoSuffices()
            || !wgfDonIsNineMinusAC()
            || !wgfPlateAddTwoRounds()
            || !wgfUnaidedAddFiveRounds()
            || !wgfDoffHalfTime()
            || !wgfLeatherDoffHalfRound()
            || !wgfFireNotIntegral()
            || !wgfCookingIncidental()
            || !wgfPlantsPoisonousRaw()
            || !wgfWarmthPrimary()
            || !wgfWarmthLifeOrDeath()
            || !wgfFuelGatherTurns()
            || !wgfAssumesFirewood()
        )
            ++bad;
        // Table 38: campfire characteristics, the three fire sizes by fuel,
        // start dice, refuel, wind resistance, capacity and visibility,
        // printed p. 65
        int C38[3][8] = {
            {6,20,2,0,3,20,6,240},
            {12,20,2,5,6,30,10,360},
            {18,20,2,10,9,40,15,540},
            };
        int n38[8] = {0,0,0,0,0,0,0,0};
        int e38[8] = {0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < wgfFireSizes();
             ++b) {
            int vals[8];
            vals[0] = wgfFuel(b);
            vals[1] = wgfStartDie(b);
            vals[2] = wgfStartCount(b);
            vals[3] = wgfStartMod(b);
            vals[4] = wgfRefuel(b);
            vals[5] = wgfWindRes(b);
            vals[6] = wgfCapacity(b);
            vals[7] = wgfVisibility(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C38[b][c])
                    ++bad;
                if (vals[c] == 999)
                    ++n38[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (n38[c] != e38[c])
                ++bad;
        // Table 38: warmth provided at given distance, the three fire sizes
        // by nine distances with the dash cells as the 999 no-warmth
        // sentinel, printed p. 65
        int C38w[3][9] = {
            {80,60,40,30,20,10,0,0,0},
            {999,80,60,40,30,20,10,0,0},
            {999,999,80,60,40,30,20,10,0},
            };
        int n38w[9] = {0,0,0,0,0,0,0,0,0};
        int e38w[9] = {2,1,0,0,0,0,0,0,0};
        for (int b = 0;
             b < wgfFireSizes();
             ++b) {
            int vals[9];
            vals[0] = wgfWarmAt1(b);
            vals[1] = wgfWarmAt3(b);
            vals[2] = wgfWarmAt5(b);
            vals[3] = wgfWarmAt10(b);
            vals[4] = wgfWarmAt20(b);
            vals[5] = wgfWarmAt30(b);
            vals[6] = wgfWarmAt40(b);
            vals[7] = wgfWarmAt50(b);
            vals[8] = wgfWarmAt60(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != C38w[b][c])
                    ++bad;
                if (vals[c] == 999)
                    ++n38w[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (n38w[c] != e38w[c])
                ++bad;
        // the rest-quality penalty ladder: 1/1/1/2/2/3/3/4 hours by the eight
        // conditions
    if (wgfPenNotProne() != 1
            || wgfPenBareGround() != 1
            || wgfPenTempBelow0() != 1
            || wgfPenTempAbove90() != 2
            || wgfPenWindNoShelter() != 2
            || wgfPenPrecipNoShelter() != 3
            || wgfPenMetalArmor() != 3
            || wgfPenPlateArmor() != 4
        )
            ++bad;
        // the penalties never grow smaller down the list and plate armor is
        // the worst of them
    if (wgfPenNotProne() > wgfPenBareGround()
            || wgfPenBareGround() > wgfPenTempBelow0()
            || wgfPenTempBelow0() > wgfPenTempAbove90()
            || wgfPenTempAbove90() > wgfPenWindNoShelter()
            || wgfPenWindNoShelter() > wgfPenPrecipNoShelter()
            || wgfPenPrecipNoShelter() > wgfPenMetalArmor()
            || wgfPenMetalArmor() > wgfPenPlateArmor()
        )
            ++bad;
        // the plate-armor sleeper: a five-hour night buys one hour of good
        // rest, nine hours refresh like five
    if (wgfPlateTypicalNight() != 5
            || wgfPlateNightGoodRest() != 1
            || wgfPlateLongSleep() != 9
            || wgfPlateLongRefresh() != 5
        )
            ++bad;
        // the donning ladder: leather in 1 round, banded in 5, full plate in
        // 11 helped or 16 solo, 8 to shed solo
    if (wgfLeatherAC() != 8
            || wgfLeatherDonRounds() != 1
            || wgfBandedAC() != 4
            || wgfBandedDonRounds() != 5
            || wgfFullPlateAC() != 0
            || wgfFullPlateHelpedRounds() != 11
            || wgfFullPlateSoloRounds() != 16
            || wgfFullPlateSoloDoffRounds() != 8
        )
            ++bad;
        // the helped full plate figure sits between the calculated base and
        // the solo figure, and solo is the worst
    if (wgfFullPlateHelpedRounds() >= wgfFullPlateSoloRounds()
            || wgfFullPlateSoloDoffRounds() >= wgfFullPlateSoloRounds()
        )
            ++bad;
        // the fuel ladder: 6/12/18 turns, each size strictly more than the
        // last
    if (wgfFuel(0) != 6
            || wgfFuel(1) != 12
            || wgfFuel(2) != 18
            || wgfFuel(0) >= wgfFuel(1)
            || wgfFuel(1) >= wgfFuel(2)
        )
            ++bad;
        // every fire starts on 2d20 with the size adding 0/5/10 to the roll
    if (wgfStartDie(0) != 20
            || wgfStartDie(1) != 20
            || wgfStartDie(2) != 20
            || wgfStartCount(0) != 2
            || wgfStartCount(1) != 2
            || wgfStartCount(2) != 2
            || wgfStartMod(0) != 0
            || wgfStartMod(1) != 5
            || wgfStartMod(2) != 10
        )
            ++bad;
        // the refuel, wind resistance, capacity and visibility all step
        // strictly up with size
    if (wgfRefuel(0) >= wgfRefuel(1)
            || wgfRefuel(1) >= wgfRefuel(2)
            || wgfWindRes(0) >= wgfWindRes(1)
            || wgfWindRes(1) >= wgfWindRes(2)
            || wgfCapacity(0) >= wgfCapacity(1)
            || wgfCapacity(1) >= wgfCapacity(2)
            || wgfVisibility(0) >= wgfVisibility(1)
            || wgfVisibility(1) >= wgfVisibility(2)
        )
            ++bad;
        // the small fire: 80/60/40/30/20/10 and nothing past 30
    if (wgfWarmAt1(0) != 80
            || wgfWarmAt3(0) != 60
            || wgfWarmAt5(0) != 40
            || wgfWarmAt10(0) != 30
            || wgfWarmAt20(0) != 20
            || wgfWarmAt30(0) != 10
            || wgfWarmAt40(0) != 0
            || wgfWarmAt50(0) != 0
            || wgfWarmAt60(0) != 0
        )
            ++bad;
        // the medium fire: no warmth at 1, 80 at 3, decaying to zero past 50
    if (wgfWarmAt1(1) != 999
            || wgfWarmAt3(1) != 80
            || wgfWarmAt5(1) != 60
            || wgfWarmAt10(1) != 40
            || wgfWarmAt20(1) != 30
            || wgfWarmAt30(1) != 20
            || wgfWarmAt40(1) != 10
            || wgfWarmAt50(1) != 0
            || wgfWarmAt60(1) != 0
        )
            ++bad;
        // the large fire: no warmth at 1 or 3, 80 at 5, decaying to zero at
        // 60
    if (wgfWarmAt1(2) != 999
            || wgfWarmAt3(2) != 999
            || wgfWarmAt5(2) != 80
            || wgfWarmAt10(2) != 60
            || wgfWarmAt20(2) != 40
            || wgfWarmAt30(2) != 30
            || wgfWarmAt40(2) != 20
            || wgfWarmAt50(2) != 10
            || wgfWarmAt60(2) != 0
        )
            ++bad;
        // the small fire warmth never increases with distance
    if (wgfWarmAt1(0) < wgfWarmAt3(0)
            || wgfWarmAt3(0) < wgfWarmAt5(0)
            || wgfWarmAt5(0) < wgfWarmAt10(0)
            || wgfWarmAt10(0) < wgfWarmAt20(0)
            || wgfWarmAt20(0) < wgfWarmAt30(0)
            || wgfWarmAt30(0) < wgfWarmAt40(0)
            || wgfWarmAt40(0) < wgfWarmAt50(0)
            || wgfWarmAt50(0) < wgfWarmAt60(0)
        )
            ++bad;
        // the medium fire warmth never increases with distance
    if (wgfWarmAt1(1) < wgfWarmAt3(1)
            || wgfWarmAt3(1) < wgfWarmAt5(1)
            || wgfWarmAt5(1) < wgfWarmAt10(1)
            || wgfWarmAt10(1) < wgfWarmAt20(1)
            || wgfWarmAt20(1) < wgfWarmAt30(1)
            || wgfWarmAt30(1) < wgfWarmAt40(1)
            || wgfWarmAt40(1) < wgfWarmAt50(1)
            || wgfWarmAt50(1) < wgfWarmAt60(1)
        )
            ++bad;
        // the large fire warmth never increases with distance
    if (wgfWarmAt1(2) < wgfWarmAt3(2)
            || wgfWarmAt3(2) < wgfWarmAt5(2)
            || wgfWarmAt5(2) < wgfWarmAt10(2)
            || wgfWarmAt10(2) < wgfWarmAt20(2)
            || wgfWarmAt20(2) < wgfWarmAt30(2)
            || wgfWarmAt30(2) < wgfWarmAt40(2)
            || wgfWarmAt40(2) < wgfWarmAt50(2)
            || wgfWarmAt50(2) < wgfWarmAt60(2)
        )
            ++bad;
        // at every distance all three sizes share, a larger fire warms at
        // least as much as a smaller one
    if (wgfWarmAt5(2) < wgfWarmAt5(1)
            || wgfWarmAt5(1) < wgfWarmAt5(0)
            || wgfWarmAt10(2) < wgfWarmAt10(1)
            || wgfWarmAt10(1) < wgfWarmAt10(0)
            || wgfWarmAt20(2) < wgfWarmAt20(1)
            || wgfWarmAt20(1) < wgfWarmAt20(0)
            || wgfWarmAt30(2) < wgfWarmAt30(1)
            || wgfWarmAt30(1) < wgfWarmAt30(0)
            || wgfWarmAt40(2) < wgfWarmAt40(1)
            || wgfWarmAt40(1) < wgfWarmAt40(0)
            || wgfWarmAt50(2) < wgfWarmAt50(1)
            || wgfWarmAt50(1) < wgfWarmAt50(0)
            || wgfWarmAt60(2) < wgfWarmAt60(1)
            || wgfWarmAt60(1) < wgfWarmAt60(0)
        )
            ++bad;
        printf("R474 WSG rest quality and fire pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
