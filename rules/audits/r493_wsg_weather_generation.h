    // ---- R493 WSG weather generation audit ----
    // The Appendix: The World of Weather, part 1 of 2 - the generation
    // system, printed pp. 107-111 plus the extraordinary-precipitation tail
    // that completes the section from the top of printed p. 112. The opener:
    // the Earthlike assumption, the 24-hour day, the 365-or-360 year, four
    // seasons x three months, the counterclockwise rotation, degrees
    // Fahrenheit, feet, mph, wind from whence it blows, the
    // two-tables-one-roll basic structure. The five climatic regions with
    // their latitude bands and wind characters, the seven terrain types, the
    // swamp and scrub/rough translations, the Monster Manual II
    // three-category mesh. The temperature letter codes (the 26-row high/low
    // scale), the Table A1 grid (30 climate/terrain rows x 12 months x the
    // low/mean/high letters, the blank arctic forest row), the Table A2
    // day-to-day grid (steps, precipitation yes/no/same, the wind increments
    // and sources, the roll-2/12 special rows), the Table A3 precipitation
    // grid (33 rows x 12 season/die-comparison cells). The usage prose: the
    // second-letter start, the daily curve, the stop-at-extreme move, the
    // upper-limit 7-as-6 and the two-day 7-or-8-as-6 streaks with the cold
    // mirror, the die-1/die-2 discipline, the even-roll precipitation consult
    // with the A/B/C columns, the 3-through-11 wind usage with the hemisphere
    // rule, the gust seconds-to-minutes and the half-max rest of day, the
    // 45-mph ceiling with the arctic/tropical 20 and subarctic 25-30
    // footnotes. The precipitation letter values, the rain-sleet-snow
    // dispatch, the collecting arithmetic (the cylinder, the ounce, the box,
    // the 10-to-1 snow melt), the intensity guidelines (the trace half-hour,
    // the desert one-in-ten, the pan, the dawn/dusk storms, the downpour
    // sandwich) and the extraordinary doubles rule (the 50 percent d6
    // step-up, the two-double run, the temperate-forest-summer downpour ban,
    // the downpour cap).
    {
        using namespace rules;
        int bad = 0;
    if (wwxDayHours() != 24
            || wwxYearDays() != 365
            || wwxYearDaysShort() != 360
            || wwxMonthsPerSeason() != 3
            || wwxSeasonsPerYear() != 4
            || wwxMonthsPerYear() != 12
            || wwxPoleLat() != 90
            || wwxArcticLoLat() != 66
            || wwxSubarcticHiLat() != 65
            || wwxSubarcticLoLat() != 51
            || wwxTemperateHiLat() != 50
            || wwxTemperateLoLat() != 31
            || wwxSubtropHiLat() != 30
            || wwxSubtropLoLat() != 16
            || wwxTropicHiLat() != 15
            || wwxEquatorLat() != 0
            || wwxArcticWindLightMph() != 15
            || wwxArcticWindModMph() != 20
            || wwxSubarcticWindMaxLoMph() != 25
            || wwxSubarcticWindMaxHiMph() != 30
            || wwxWindCeilingMph() != 45
            || wwxTempCodeCount() != 26
            || wwxA1Count() != 30
            || wwxElevDesertFt() != 0
            || wwxElevPlainForestFt() != 500
            || wwxElevHillsFt() != 2000
            || wwxElevMountainsFt() != 4000
            || wwxDegreesPer1000Ft() != 3
            || wwxA2Count() != 11
            || wwxRestOfDayDivisor() != 2
            || wwxA3Count() != 33
            || wwxTraceRainEighthInch() != 1
            || wwxTraceSnowHalfInch() != 1
            || wwxLightRainHalfInch() != 1
            || wwxLightSnowInch() != 1
            || wwxModerateRainQuarterInch() != 3
            || wwxModerateSnowInch() != 2
            || wwxHeavyRainHalfInch() != 3
            || wwxHeavySnowInch() != 4
            || wwxDownpourRainHalfInch() != 3
            || wwxRainMinF() != 36
            || wwxSleetHiF() != 35
            || wwxSleetLoF() != 30
            || wwxSleetD6Max() != 3
            || wwxOunceTenthCuIn() != 18
            || wwxInchRainCuIn() != 113
            || wwxInchRainOz() != 63
            || wwxBoxCuIn() != 24
            || wwxBoxOz() != 13
            || wwxSnowMeltRatio() != 10
            || wwxTraceMinutes() != 30
            || wwxDesertTraceTenths() != 1
            || wwxTracePanOz() != 8
            || wwxTracePanTenthInch() != 1
            || wwxHeavyStormWindowHours() != 2
            || wwxDownpourBurstInch() != 1
            || wwxDownpourBurstMinutes() != 30
            || wwxExtraDoublesRun() != 2
            || wwxExtraD6Lo() != 1
            || wwxExtraD6Hi() != 3
            || wwxExtraStepUp() != 1
            || !wwxEarthlikeWorld()
            || !wwxCounterclockwiseFromNorthPole()
            || !wwxWindFromWhence()
            || !wwxTwoTablesOneRoll()
            || !wwxOptionalPartsSkippable()
            || !wwxEffectsLiveInFirstSection()
            || !wwxScrubRoughAsPlainOrForest()
            || !wwxSevenTerrainTypes()
            || !wwxArcticMidnightSun()
            || !wwxArcticNoonMoon()
            || !wwxArcticWindsEastToWest()
            || !wwxArcticPrecipVeryLight()
            || !wwxArcticForestImpossible()
            || !wwxSubarcticWinterWindArcticAngle()
            || !wwxSubarcticSummerWindWesterly()
            || !wwxTemperateWindSeldomEast()
            || !wwxSubtropicalTradeWinds()
            || !wwxTropicalWindsDocileTrade()
            || !wwxSwampBareIsPlain()
            || !wwxSwampTreesIsForest()
            || !wwxSwampOceanIsSeacoast()
            || !wwxMmiiColdSplitsSubarctic()
            || !wwxMmiiTemperateTakesTheHalves()
            || !wwxMmiiTropicalSplitsSubtropical()
            || !wwxWinterMonthsAreTwelveOneTwo()
            || !wwxRoll2WindVeryStrong()
            || !wwxRoll12WindVerySlight()
            || !wwxDistinctDice()
            || !wwxStopAtExtreme()
            || !wwxUpperLimitPlusNoChange()
            || !wwxLimitRoll7As6()
            || !wwxStreakTwoDays7Or8As6()
            || !wwxColdStreakMirror()
            || !wwxRoll2Or12ConsultSpecial()
            || !wwxPrecipConsultOnEvenRolls()
            || !wwxPrecipDieColumns()
            || !wwxWindUsedOn3To11()
            || !wwxArcticWindHemisphere()
            || !wwxWindIncrementFromPrevious()
            || !wwxWindNeverBelowZero()
            || !wwxGustsSecondsToMinutes()
            || !wwxSnowBelow30()
            || !wwxSnowOnTheGround()
            || !wwxDesertTraceFutile()
            || !wwxLightReadConservatively()
            || !wwxModerateVaries()
            || !wwxHeavyAtDawnDusk()
            || !wwxDownpourOnlySubtropicalTropical()
            || !wwxExtraNoTemperateForestSummerDownpour()
            || !wwxExtraCapsAtDownpour()
            || !wwxExtraTwoDoublesThenHold()
            || !wwxSecondLetterStart()
            || !wwxLowBeforeSunrise()
            || !wwxHighEarlyAfternoon()
        )
            ++bad;
        // the wwxTempCodes grid
        int CTC[26][2] = {
            {-20,-40},
            {-15,-30},
            {-5,-20},
            {0,-10},
            {10,0},
            {18,10},
            {25,10},
            {30,15},
            {35,15},
            {40,20},
            {50,30},
            {60,40},
            {65,45},
            {70,50},
            {70,55},
            {75,55},
            {80,60},
            {80,65},
            {85,65},
            {85,70},
            {90,70},
            {90,75},
            {95,75},
            {100,80},
            {105,80},
            {115,85},
            };
        for (int b = 0;
             b < wwxTempCodeCount();
             ++b) {
            int vals[2];
            vals[0] = wwsTempCodeHi(b);
            vals[1] = wwsTempCodeLo(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CTC[b][c])
                    ++bad;
            }
        }
        // the wwxA1Lo grid
        int CA1L[30][12] = {
            {0,0,0,0,2,5,9,9,5,3,0,0},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {0,0,0,0,1,2,3,3,2,2,1,0},
            {0,0,0,0,1,2,3,3,2,2,1,0},
            {0,0,0,0,2,5,9,9,5,3,0,0},
            {0,0,0,0,2,5,9,9,4,2,0,0},
            {0,0,1,2,5,9,10,9,6,5,2,0},
            {0,0,1,3,7,9,10,9,8,4,1,0},
            {0,0,1,2,5,9,9,8,6,3,1,0},
            {0,0,0,1,4,8,9,8,6,3,1,0},
            {0,0,1,2,5,9,10,9,6,5,2,0},
            {1,1,2,3,7,9,10,10,9,4,2,0},
            {10,10,11,12,12,15,20,20,16,13,11,10},
            {2,1,4,7,10,12,12,12,11,9,5,3},
            {1,2,4,8,9,9,11,11,10,9,5,2},
            {0,1,2,4,5,10,11,10,8,4,2,1},
            {1,2,3,6,10,11,12,12,10,6,4,2},
            {4,5,8,10,10,11,12,12,11,10,6,4},
            {11,11,12,13,14,17,19,19,17,15,13,12},
            {11,11,12,13,13,15,15,15,14,13,12,11},
            {10,10,11,12,13,14,15,15,13,12,11,10},
            {10,10,11,11,12,13,13,13,11,11,11,10},
            {11,10,12,13,17,18,19,19,18,16,12,11},
            {11,10,10,11,12,12,13,13,12,11,10,10},
            {15,15,15,15,16,19,21,21,20,20,17,16},
            {12,11,12,14,14,16,16,16,16,15,14,12},
            {12,13,13,15,15,16,18,18,18,16,14,13},
            {12,13,13,14,14,14,13,13,13,13,12,12},
            {12,13,13,15,17,19,19,19,19,17,15,13},
            {15,15,14,16,16,17,17,17,17,16,16,15},
            };
        int nA1L[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int eA1L[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
        for (int b = 0;
             b < wwxA1Count();
             ++b) {
            int vals[12];
            vals[0] = wwsA1LoM01(b);
            vals[1] = wwsA1LoM02(b);
            vals[2] = wwsA1LoM03(b);
            vals[3] = wwsA1LoM04(b);
            vals[4] = wwsA1LoM05(b);
            vals[5] = wwsA1LoM06(b);
            vals[6] = wwsA1LoM07(b);
            vals[7] = wwsA1LoM08(b);
            vals[8] = wwsA1LoM09(b);
            vals[9] = wwsA1LoM10(b);
            vals[10] = wwsA1LoM11(b);
            vals[11] = wwsA1LoM12(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CA1L[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nA1L[c];
            }
        }
        for (int c = 0; c < 12; ++c)
            if (nA1L[c] != eA1L[c])
                ++bad;
        // the wwxA1Mean grid
        int CA1M[30][12] = {
            {1,1,2,4,6,9,10,10,7,6,3,1},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {1,1,2,3,4,5,6,6,5,4,4,2},
            {1,1,2,3,4,5,6,6,5,4,4,2},
            {1,1,2,4,6,9,10,10,7,6,3,1},
            {2,1,2,4,6,9,10,10,8,6,4,2},
            {3,3,4,6,10,11,12,12,10,7,4,2},
            {4,4,6,9,10,11,12,12,10,9,7,5},
            {3,3,5,6,10,11,12,12,10,9,6,3},
            {2,3,5,7,9,10,11,12,10,9,5,3},
            {3,3,4,6,10,11,12,12,10,7,4,2},
            {5,6,7,9,10,11,12,12,11,10,7,5},
            {12,12,12,13,15,15,24,24,22,18,17,12},
            {5,5,10,11,13,15,18,18,15,13,9,9},
            {8,9,10,11,14,16,19,19,16,13,10,9},
            {8,8,9,10,11,14,16,16,13,11,10,9},
            {7,7,10,11,13,15,18,18,15,11,10,9},
            {9,10,10,11,12,14,15,15,14,11,10,10},
            {15,15,18,19,19,21,23,23,20,20,18,15},
            {19,19,19,19,19,20,20,20,20,20,18,18},
            {13,14,16,18,19,20,20,20,18,16,15,13},
            {12,12,15,15,16,16,15,14,14,13,13,12},
            {13,14,17,18,21,22,22,22,21,21,17,15},
            {12,12,14,15,16,18,18,18,17,16,14,12},
            {17,18,19,20,21,22,24,24,23,21,20,18},
            {20,20,20,20,20,20,20,20,20,20,20,20},
            {15,15,17,17,19,20,22,22,21,19,17,16},
            {15,15,16,16,16,16,15,15,15,15,15,15},
            {15,16,17,17,22,22,22,22,22,21,18,17},
            {18,18,19,19,19,19,19,19,19,18,18,17},
            };
        int nA1M[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int eA1M[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
        for (int b = 0;
             b < wwxA1Count();
             ++b) {
            int vals[12];
            vals[0] = wwsA1MeanM01(b);
            vals[1] = wwsA1MeanM02(b);
            vals[2] = wwsA1MeanM03(b);
            vals[3] = wwsA1MeanM04(b);
            vals[4] = wwsA1MeanM05(b);
            vals[5] = wwsA1MeanM06(b);
            vals[6] = wwsA1MeanM07(b);
            vals[7] = wwsA1MeanM08(b);
            vals[8] = wwsA1MeanM09(b);
            vals[9] = wwsA1MeanM10(b);
            vals[10] = wwsA1MeanM11(b);
            vals[11] = wwsA1MeanM12(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CA1M[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nA1M[c];
            }
        }
        for (int c = 0; c < 12; ++c)
            if (nA1M[c] != eA1M[c])
                ++bad;
        // the wwxA1Hi grid
        int CA1H[30][12] = {
            {6,7,7,7,10,11,13,12,10,9,7,7},
            {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
            {4,3,5,6,8,8,11,10,9,7,7,4},
            {4,3,5,6,8,8,11,10,9,7,7,4},
            {6,7,7,7,10,11,13,12,10,9,7,7},
            {7,7,7,9,10,13,15,13,11,9,8,8},
            {8,9,9,9,12,13,16,16,16,12,11,8},
            {9,8,10,11,13,15,17,17,15,11,10,9},
            {8,8,9,9,13,13,15,15,12,11,10,9},
            {8,8,9,11,12,12,13,14,12,11,10,9},
            {8,9,9,9,12,13,16,16,16,12,11,8},
            {10,10,10,12,13,17,17,17,15,12,11,10},
            {18,19,19,22,23,25,25,25,24,23,23,17},
            {11,10,15,15,20,21,23,23,21,17,11,11},
            {11,12,15,17,19,23,24,24,22,19,15,12},
            {11,12,13,16,18,21,23,22,20,18,17,11},
            {12,13,16,18,20,23,24,24,22,18,16,12},
            {12,13,16,18,19,22,23,22,22,19,15,12},
            {19,20,22,23,23,24,25,25,24,24,23,22},
            {20,21,21,22,23,23,23,23,22,22,21,21},
            {16,17,20,21,22,23,23,24,23,21,18,17},
            {15,16,18,19,20,20,19,17,17,16,16,15},
            {17,18,20,23,23,24,25,25,24,24,20,18},
            {20,21,22,23,23,24,24,24,23,22,20,20},
            {20,19,22,23,24,25,25,25,24,23,22,21},
            {22,22,22,23,23,23,23,23,23,23,22,22},
            {17,19,19,20,23,24,25,25,24,22,20,19},
            {17,18,19,19,20,20,19,19,19,18,18,18},
            {17,19,20,20,24,24,25,25,24,24,22,20},
            {20,21,22,23,23,24,23,23,22,21,21,21},
            };
        int nA1H[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
        int eA1H[12] = {1,1,1,1,1,1,1,1,1,1,1,1};
        for (int b = 0;
             b < wwxA1Count();
             ++b) {
            int vals[12];
            vals[0] = wwsA1HiM01(b);
            vals[1] = wwsA1HiM02(b);
            vals[2] = wwsA1HiM03(b);
            vals[3] = wwsA1HiM04(b);
            vals[4] = wwsA1HiM05(b);
            vals[5] = wwsA1HiM06(b);
            vals[6] = wwsA1HiM07(b);
            vals[7] = wwsA1HiM08(b);
            vals[8] = wwsA1HiM09(b);
            vals[9] = wwsA1HiM10(b);
            vals[10] = wwsA1HiM11(b);
            vals[11] = wwsA1HiM12(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CA1H[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nA1H[c];
            }
        }
        for (int c = 0; c < 12; ++c)
            if (nA1H[c] != eA1H[c])
                ++bad;
        // the wwxA2 grid
        int CA2[11][4] = {
            {-3,1,-99,0},
            {-2,0,15,1},
            {-2,1,10,1},
            {-1,0,15,2},
            {-1,1,10,2},
            {0,2,0,4},
            {1,1,-10,2},
            {1,0,-15,2},
            {2,1,-10,3},
            {2,0,-15,3},
            {3,1,-99,0},
            };
        int nA2[4] = {0,0,0,0};
        int eA2[4] = {0,0,2,0};
        for (int b = 0;
             b < wwxA2Count();
             ++b) {
            int vals[4];
            vals[0] = wwsA2Steps(b);
            vals[1] = wwsA2Precip(b);
            vals[2] = wwsA2WindDelta(b);
            vals[3] = wwsA2WindFrom(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CA2[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nA2[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nA2[c] != eA2[c])
                ++bad;
        // the wwxA3 grid
        int CA3[33][12] = {
            {0,1,0,0,1,0,0,1,0,0,1,0},
            {0,0,1,0,0,1,0,0,1,0,0,1},
            {0,0,1,0,0,1,0,0,1,0,0,1},
            {0,1,1,0,2,1,0,3,2,0,1,1},
            {0,1,0,0,2,1,0,2,1,0,2,1},
            {0,1,0,0,0,1,0,0,1,0,1,0},
            {0,2,1,1,3,2,1,3,2,1,2,1},
            {0,1,1,0,2,1,1,2,2,0,2,1},
            {0,1,1,1,3,2,1,2,1,0,2,1},
            {0,2,1,1,3,2,1,3,2,1,2,1},
            {0,1,1,0,2,1,1,3,2,0,2,1},
            {0,2,1,1,3,2,1,2,2,1,2,2},
            {0,1,0,0,1,0,0,1,0,0,0,0},
            {1,3,2,2,4,3,2,3,3,2,3,3},
            {1,3,2,2,4,3,2,4,3,1,3,2},
            {0,3,2,0,3,2,0,2,1,0,3,2},
            {0,2,1,2,4,3,2,4,3,1,3,2},
            {2,4,3,1,3,2,0,2,1,2,4,3},
            {1,3,2,2,4,2,2,4,3,0,3,2},
            {0,1,0,0,1,0,0,0,0,0,1,0},
            {3,4,4,3,5,4,3,5,4,3,4,4},
            {1,2,2,2,4,3,2,4,3,1,3,2},
            {1,3,2,2,4,3,2,3,3,1,3,2},
            {0,2,1,1,4,2,1,3,2,0,2,1},
            {1,3,2,2,4,3,2,5,3,0,2,1},
            {1,2,2,1,3,2,1,4,2,1,2,2},
            {0,1,0,0,2,1,0,1,0,0,1,0},
            {3,5,4,3,5,4,3,5,4,3,5,4},
            {0,1,0,0,2,1,1,3,2,0,1,0},
            {1,3,2,3,4,4,1,3,2,3,4,4},
            {0,1,0,2,4,3,3,4,3,2,4,3},
            {0,1,0,2,5,3,4,5,5,0,2,1},
            {0,2,1,3,4,4,3,4,3,2,3,3},
            };
        for (int b = 0;
             b < wwxA3Count();
             ++b) {
            int vals[12];
            vals[0] = wwsA3WiA(b);
            vals[1] = wwsA3WiB(b);
            vals[2] = wwsA3WiC(b);
            vals[3] = wwsA3SpA(b);
            vals[4] = wwsA3SpB(b);
            vals[5] = wwsA3SpC(b);
            vals[6] = wwsA3SuA(b);
            vals[7] = wwsA3SuB(b);
            vals[8] = wwsA3SuC(b);
            vals[9] = wwsA3AuA(b);
            vals[10] = wwsA3AuB(b);
            vals[11] = wwsA3AuC(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CA3[b][c])
                    ++bad;
            }
        }
        // the wwxPrecipFormFor band-for boundaries
    if (wwxPrecipFormFor(28) != 0
            || wwxPrecipFormFor(29) != 0
            || wwxPrecipFormFor(35) != 1
            || wwxPrecipFormFor(30) != 1
            || wwxPrecipFormFor(36) != 2
        )
            ++bad;
        // the book own worked example: the subtropical plains seventh-month
        // code is T W Z - the T low almost never below 70, the Z high up to
        // 115, the W mean high 95 low 75
    if (wwsA1LoM07(22) != 19
            || wwsA1MeanM07(22) != 22
            || wwsA1HiM07(22) != 25
        )
            ++bad;
        // the book own worked example: a subarctic forest in the first month
        // is A E J, and a roll of 12 from the E mean stops at the J upper
        // limit, never K
    if (wwsA1LoM01(7) != 0
            || wwsA1MeanM01(7) != 4
            || wwsA1HiM01(7) != 9
        )
            ++bad;
        // the letter-scale anchors from the printed table and prose: A is
        // -20/-40 and Z is 115/85
    if (wwsTempCodeHi(0) != -20
            || wwsTempCodeLo(0) != -40
            || wwsTempCodeHi(25) != 115
            || wwsTempCodeLo(25) != 85
        )
            ++bad;
        // the W anchor from the TWZ prose and the T anchor of the letter-code
        // layout
    if (wwsTempCodeHi(22) != 95
            || wwsTempCodeLo(22) != 75
            || wwsTempCodeHi(19) != 85
            || wwsTempCodeLo(19) != 70
        )
            ++bad;
        // the roll-4 row: minus 2 steps, precipitation yes, wind from the
        // arctic at +10 mph
    if (wwsA2Steps(2) != -2
            || wwsA2Precip(2) != 1
            || wwsA2WindDelta(2) != 10
            || wwsA2WindFrom(2) != 1
        )
            ++bad;
        // the roll-7 row: no temperature change, the same chance of
        // precipitation, the same wind as the previous day
    if (wwsA2Steps(5) != 0
            || wwsA2Precip(5) != 2
            || wwsA2WindDelta(5) != 0
            || wwsA2WindFrom(5) != 4
        )
            ++bad;
        // the book own wind example: 15 mph today plus the roll-3 +15
        // increment makes 30 mph gusts tomorrow, the rest of the day no more
        // than 15
    if (wwsA2WindDelta(1) != 15
            || wwxRestOfDayDivisor() != 2
            || wwsA2Steps(1) != -2
        )
            ++bad;
        // the book own extraordinary example: double 4s in a temperate forest
        // summer is moderate rain, and double 3s with a 3 on the d6 is one
        // step greater - heavy
    if (wwsA3SuB(13) != 3
            || wwsA3SuB(13) + wwxExtraStepUp() != 4
        )
            ++bad;
        // the collecting arithmetic: 1 inch of rain in the 6-inch-radius
        // cylinder is about 113 cubic inches = 63 ounces = roughly half a
        // gallon, and the 6x4x1 box is 24 cubic inches = 13 fluid ounces
    if (wwxInchRainCuIn() != 113
            || wwxInchRainOz() != 63
            || wwxBoxCuIn() != 24
            || wwxBoxOz() != 13
        )
            ++bad;
        // the rain-sleet-snow dispatch: 36 and up is rain, 30 to 35 inclusive
        // is the sleet-or-snow band, below 30 is snow
    if (wwxPrecipFormFor(36) != 2
            || wwxPrecipFormFor(35) != 1
            || wwxPrecipFormFor(30) != 1
            || wwxPrecipFormFor(29) != 0
        )
            ++bad;
        // the elevation baselines of the Table A1 footnote
    if (wwxElevDesertFt() != 0
            || wwxElevPlainForestFt() != 500
            || wwxElevHillsFt() != 2000
            || wwxElevMountainsFt() != 4000
            || wwxDegreesPer1000Ft() != 3
        )
            ++bad;
        // the precipitation letter values: light is up to 1/2 inch rain or 1
        // inch snow, moderate up to 3/4 rain or 2 snow, heavy up to 1 1/2
        // rain or 4 snow, downpour more than 1 1/2 rain
    if (wwxLightRainHalfInch() != 1
            || wwxLightSnowInch() != 1
            || wwxModerateRainQuarterInch() != 3
            || wwxModerateSnowInch() != 2
            || wwxHeavyRainHalfInch() != 3
            || wwxHeavySnowInch() != 4
            || wwxDownpourRainHalfInch() != 3
        )
            ++bad;
        // the letter-code highs never decrease from A through Z
    if (wwsTempCodeHi(0) > wwsTempCodeHi(1)
            || wwsTempCodeHi(1) > wwsTempCodeHi(2)
            || wwsTempCodeHi(2) > wwsTempCodeHi(3)
            || wwsTempCodeHi(3) > wwsTempCodeHi(4)
            || wwsTempCodeHi(4) > wwsTempCodeHi(5)
            || wwsTempCodeHi(5) > wwsTempCodeHi(6)
            || wwsTempCodeHi(6) > wwsTempCodeHi(7)
            || wwsTempCodeHi(7) > wwsTempCodeHi(8)
            || wwsTempCodeHi(8) > wwsTempCodeHi(9)
            || wwsTempCodeHi(9) > wwsTempCodeHi(10)
            || wwsTempCodeHi(10) > wwsTempCodeHi(11)
            || wwsTempCodeHi(11) > wwsTempCodeHi(12)
            || wwsTempCodeHi(12) > wwsTempCodeHi(13)
            || wwsTempCodeHi(13) > wwsTempCodeHi(14)
            || wwsTempCodeHi(14) > wwsTempCodeHi(15)
            || wwsTempCodeHi(15) > wwsTempCodeHi(16)
            || wwsTempCodeHi(16) > wwsTempCodeHi(17)
            || wwsTempCodeHi(17) > wwsTempCodeHi(18)
            || wwsTempCodeHi(18) > wwsTempCodeHi(19)
            || wwsTempCodeHi(19) > wwsTempCodeHi(20)
            || wwsTempCodeHi(20) > wwsTempCodeHi(21)
            || wwsTempCodeHi(21) > wwsTempCodeHi(22)
            || wwsTempCodeHi(22) > wwsTempCodeHi(23)
            || wwsTempCodeHi(23) > wwsTempCodeHi(24)
            || wwsTempCodeHi(24) > wwsTempCodeHi(25)
        )
            ++bad;
        // the letter-code lows never decrease from A through Z
    if (wwsTempCodeLo(0) > wwsTempCodeLo(1)
            || wwsTempCodeLo(1) > wwsTempCodeLo(2)
            || wwsTempCodeLo(2) > wwsTempCodeLo(3)
            || wwsTempCodeLo(3) > wwsTempCodeLo(4)
            || wwsTempCodeLo(4) > wwsTempCodeLo(5)
            || wwsTempCodeLo(5) > wwsTempCodeLo(6)
            || wwsTempCodeLo(6) > wwsTempCodeLo(7)
            || wwsTempCodeLo(7) > wwsTempCodeLo(8)
            || wwsTempCodeLo(8) > wwsTempCodeLo(9)
            || wwsTempCodeLo(9) > wwsTempCodeLo(10)
            || wwsTempCodeLo(10) > wwsTempCodeLo(11)
            || wwsTempCodeLo(11) > wwsTempCodeLo(12)
            || wwsTempCodeLo(12) > wwsTempCodeLo(13)
            || wwsTempCodeLo(13) > wwsTempCodeLo(14)
            || wwsTempCodeLo(14) > wwsTempCodeLo(15)
            || wwsTempCodeLo(15) > wwsTempCodeLo(16)
            || wwsTempCodeLo(16) > wwsTempCodeLo(17)
            || wwsTempCodeLo(17) > wwsTempCodeLo(18)
            || wwsTempCodeLo(18) > wwsTempCodeLo(19)
            || wwsTempCodeLo(19) > wwsTempCodeLo(20)
            || wwsTempCodeLo(20) > wwsTempCodeLo(21)
            || wwsTempCodeLo(21) > wwsTempCodeLo(22)
            || wwsTempCodeLo(22) > wwsTempCodeLo(23)
            || wwsTempCodeLo(23) > wwsTempCodeLo(24)
            || wwsTempCodeLo(24) > wwsTempCodeLo(25)
        )
            ++bad;
        // every letter-code low sits at or below its high
    if (wwsTempCodeLo(0) > wwsTempCodeHi(0)
            || wwsTempCodeLo(1) > wwsTempCodeHi(1)
            || wwsTempCodeLo(2) > wwsTempCodeHi(2)
            || wwsTempCodeLo(3) > wwsTempCodeHi(3)
            || wwsTempCodeLo(4) > wwsTempCodeHi(4)
            || wwsTempCodeLo(5) > wwsTempCodeHi(5)
            || wwsTempCodeLo(6) > wwsTempCodeHi(6)
            || wwsTempCodeLo(7) > wwsTempCodeHi(7)
            || wwsTempCodeLo(8) > wwsTempCodeHi(8)
            || wwsTempCodeLo(9) > wwsTempCodeHi(9)
            || wwsTempCodeLo(10) > wwsTempCodeHi(10)
            || wwsTempCodeLo(11) > wwsTempCodeHi(11)
            || wwsTempCodeLo(12) > wwsTempCodeHi(12)
            || wwsTempCodeLo(13) > wwsTempCodeHi(13)
            || wwsTempCodeLo(14) > wwsTempCodeHi(14)
            || wwsTempCodeLo(15) > wwsTempCodeHi(15)
            || wwsTempCodeLo(16) > wwsTempCodeHi(16)
            || wwsTempCodeLo(17) > wwsTempCodeHi(17)
            || wwsTempCodeLo(18) > wwsTempCodeHi(18)
            || wwsTempCodeLo(19) > wwsTempCodeHi(19)
            || wwsTempCodeLo(20) > wwsTempCodeHi(20)
            || wwsTempCodeLo(21) > wwsTempCodeHi(21)
            || wwsTempCodeLo(22) > wwsTempCodeHi(22)
            || wwsTempCodeLo(23) > wwsTempCodeHi(23)
            || wwsTempCodeLo(24) > wwsTempCodeHi(24)
            || wwsTempCodeLo(25) > wwsTempCodeHi(25)
        )
            ++bad;
        // every Table A1 cell is ordered on the letter scale: the low letter
        // sits at or below the mean, the mean at or below the high (the blank
        // arctic forest row compares -1 to -1)
    if (wwsA1LoM01(0) > wwsA1MeanM01(0)
            || wwsA1MeanM01(0) > wwsA1HiM01(0)
            || wwsA1LoM02(0) > wwsA1MeanM02(0)
            || wwsA1MeanM02(0) > wwsA1HiM02(0)
            || wwsA1LoM03(0) > wwsA1MeanM03(0)
            || wwsA1MeanM03(0) > wwsA1HiM03(0)
            || wwsA1LoM04(0) > wwsA1MeanM04(0)
            || wwsA1MeanM04(0) > wwsA1HiM04(0)
            || wwsA1LoM05(0) > wwsA1MeanM05(0)
            || wwsA1MeanM05(0) > wwsA1HiM05(0)
            || wwsA1LoM06(0) > wwsA1MeanM06(0)
            || wwsA1MeanM06(0) > wwsA1HiM06(0)
            || wwsA1LoM07(0) > wwsA1MeanM07(0)
            || wwsA1MeanM07(0) > wwsA1HiM07(0)
            || wwsA1LoM08(0) > wwsA1MeanM08(0)
            || wwsA1MeanM08(0) > wwsA1HiM08(0)
            || wwsA1LoM09(0) > wwsA1MeanM09(0)
            || wwsA1MeanM09(0) > wwsA1HiM09(0)
            || wwsA1LoM10(0) > wwsA1MeanM10(0)
            || wwsA1MeanM10(0) > wwsA1HiM10(0)
            || wwsA1LoM11(0) > wwsA1MeanM11(0)
            || wwsA1MeanM11(0) > wwsA1HiM11(0)
            || wwsA1LoM12(0) > wwsA1MeanM12(0)
            || wwsA1MeanM12(0) > wwsA1HiM12(0)
            || wwsA1LoM01(1) > wwsA1MeanM01(1)
            || wwsA1MeanM01(1) > wwsA1HiM01(1)
            || wwsA1LoM02(1) > wwsA1MeanM02(1)
            || wwsA1MeanM02(1) > wwsA1HiM02(1)
            || wwsA1LoM03(1) > wwsA1MeanM03(1)
            || wwsA1MeanM03(1) > wwsA1HiM03(1)
            || wwsA1LoM04(1) > wwsA1MeanM04(1)
            || wwsA1MeanM04(1) > wwsA1HiM04(1)
            || wwsA1LoM05(1) > wwsA1MeanM05(1)
            || wwsA1MeanM05(1) > wwsA1HiM05(1)
            || wwsA1LoM06(1) > wwsA1MeanM06(1)
            || wwsA1MeanM06(1) > wwsA1HiM06(1)
            || wwsA1LoM07(1) > wwsA1MeanM07(1)
            || wwsA1MeanM07(1) > wwsA1HiM07(1)
            || wwsA1LoM08(1) > wwsA1MeanM08(1)
            || wwsA1MeanM08(1) > wwsA1HiM08(1)
            || wwsA1LoM09(1) > wwsA1MeanM09(1)
            || wwsA1MeanM09(1) > wwsA1HiM09(1)
            || wwsA1LoM10(1) > wwsA1MeanM10(1)
            || wwsA1MeanM10(1) > wwsA1HiM10(1)
            || wwsA1LoM11(1) > wwsA1MeanM11(1)
            || wwsA1MeanM11(1) > wwsA1HiM11(1)
            || wwsA1LoM12(1) > wwsA1MeanM12(1)
            || wwsA1MeanM12(1) > wwsA1HiM12(1)
            || wwsA1LoM01(2) > wwsA1MeanM01(2)
            || wwsA1MeanM01(2) > wwsA1HiM01(2)
            || wwsA1LoM02(2) > wwsA1MeanM02(2)
            || wwsA1MeanM02(2) > wwsA1HiM02(2)
            || wwsA1LoM03(2) > wwsA1MeanM03(2)
            || wwsA1MeanM03(2) > wwsA1HiM03(2)
            || wwsA1LoM04(2) > wwsA1MeanM04(2)
            || wwsA1MeanM04(2) > wwsA1HiM04(2)
            || wwsA1LoM05(2) > wwsA1MeanM05(2)
            || wwsA1MeanM05(2) > wwsA1HiM05(2)
            || wwsA1LoM06(2) > wwsA1MeanM06(2)
            || wwsA1MeanM06(2) > wwsA1HiM06(2)
            || wwsA1LoM07(2) > wwsA1MeanM07(2)
            || wwsA1MeanM07(2) > wwsA1HiM07(2)
            || wwsA1LoM08(2) > wwsA1MeanM08(2)
            || wwsA1MeanM08(2) > wwsA1HiM08(2)
            || wwsA1LoM09(2) > wwsA1MeanM09(2)
            || wwsA1MeanM09(2) > wwsA1HiM09(2)
            || wwsA1LoM10(2) > wwsA1MeanM10(2)
            || wwsA1MeanM10(2) > wwsA1HiM10(2)
            || wwsA1LoM11(2) > wwsA1MeanM11(2)
            || wwsA1MeanM11(2) > wwsA1HiM11(2)
            || wwsA1LoM12(2) > wwsA1MeanM12(2)
            || wwsA1MeanM12(2) > wwsA1HiM12(2)
            || wwsA1LoM01(3) > wwsA1MeanM01(3)
            || wwsA1MeanM01(3) > wwsA1HiM01(3)
            || wwsA1LoM02(3) > wwsA1MeanM02(3)
            || wwsA1MeanM02(3) > wwsA1HiM02(3)
            || wwsA1LoM03(3) > wwsA1MeanM03(3)
            || wwsA1MeanM03(3) > wwsA1HiM03(3)
            || wwsA1LoM04(3) > wwsA1MeanM04(3)
            || wwsA1MeanM04(3) > wwsA1HiM04(3)
            || wwsA1LoM05(3) > wwsA1MeanM05(3)
            || wwsA1MeanM05(3) > wwsA1HiM05(3)
            || wwsA1LoM06(3) > wwsA1MeanM06(3)
            || wwsA1MeanM06(3) > wwsA1HiM06(3)
            || wwsA1LoM07(3) > wwsA1MeanM07(3)
            || wwsA1MeanM07(3) > wwsA1HiM07(3)
            || wwsA1LoM08(3) > wwsA1MeanM08(3)
            || wwsA1MeanM08(3) > wwsA1HiM08(3)
            || wwsA1LoM09(3) > wwsA1MeanM09(3)
            || wwsA1MeanM09(3) > wwsA1HiM09(3)
            || wwsA1LoM10(3) > wwsA1MeanM10(3)
            || wwsA1MeanM10(3) > wwsA1HiM10(3)
            || wwsA1LoM11(3) > wwsA1MeanM11(3)
            || wwsA1MeanM11(3) > wwsA1HiM11(3)
            || wwsA1LoM12(3) > wwsA1MeanM12(3)
            || wwsA1MeanM12(3) > wwsA1HiM12(3)
            || wwsA1LoM01(4) > wwsA1MeanM01(4)
            || wwsA1MeanM01(4) > wwsA1HiM01(4)
            || wwsA1LoM02(4) > wwsA1MeanM02(4)
            || wwsA1MeanM02(4) > wwsA1HiM02(4)
            || wwsA1LoM03(4) > wwsA1MeanM03(4)
            || wwsA1MeanM03(4) > wwsA1HiM03(4)
            || wwsA1LoM04(4) > wwsA1MeanM04(4)
            || wwsA1MeanM04(4) > wwsA1HiM04(4)
            || wwsA1LoM05(4) > wwsA1MeanM05(4)
            || wwsA1MeanM05(4) > wwsA1HiM05(4)
            || wwsA1LoM06(4) > wwsA1MeanM06(4)
            || wwsA1MeanM06(4) > wwsA1HiM06(4)
            || wwsA1LoM07(4) > wwsA1MeanM07(4)
            || wwsA1MeanM07(4) > wwsA1HiM07(4)
            || wwsA1LoM08(4) > wwsA1MeanM08(4)
            || wwsA1MeanM08(4) > wwsA1HiM08(4)
            || wwsA1LoM09(4) > wwsA1MeanM09(4)
            || wwsA1MeanM09(4) > wwsA1HiM09(4)
            || wwsA1LoM10(4) > wwsA1MeanM10(4)
            || wwsA1MeanM10(4) > wwsA1HiM10(4)
            || wwsA1LoM11(4) > wwsA1MeanM11(4)
            || wwsA1MeanM11(4) > wwsA1HiM11(4)
            || wwsA1LoM12(4) > wwsA1MeanM12(4)
            || wwsA1MeanM12(4) > wwsA1HiM12(4)
            || wwsA1LoM01(5) > wwsA1MeanM01(5)
            || wwsA1MeanM01(5) > wwsA1HiM01(5)
            || wwsA1LoM02(5) > wwsA1MeanM02(5)
            || wwsA1MeanM02(5) > wwsA1HiM02(5)
            || wwsA1LoM03(5) > wwsA1MeanM03(5)
            || wwsA1MeanM03(5) > wwsA1HiM03(5)
            || wwsA1LoM04(5) > wwsA1MeanM04(5)
            || wwsA1MeanM04(5) > wwsA1HiM04(5)
            || wwsA1LoM05(5) > wwsA1MeanM05(5)
            || wwsA1MeanM05(5) > wwsA1HiM05(5)
            || wwsA1LoM06(5) > wwsA1MeanM06(5)
            || wwsA1MeanM06(5) > wwsA1HiM06(5)
            || wwsA1LoM07(5) > wwsA1MeanM07(5)
            || wwsA1MeanM07(5) > wwsA1HiM07(5)
            || wwsA1LoM08(5) > wwsA1MeanM08(5)
            || wwsA1MeanM08(5) > wwsA1HiM08(5)
            || wwsA1LoM09(5) > wwsA1MeanM09(5)
            || wwsA1MeanM09(5) > wwsA1HiM09(5)
            || wwsA1LoM10(5) > wwsA1MeanM10(5)
            || wwsA1MeanM10(5) > wwsA1HiM10(5)
            || wwsA1LoM11(5) > wwsA1MeanM11(5)
            || wwsA1MeanM11(5) > wwsA1HiM11(5)
            || wwsA1LoM12(5) > wwsA1MeanM12(5)
            || wwsA1MeanM12(5) > wwsA1HiM12(5)
            || wwsA1LoM01(6) > wwsA1MeanM01(6)
            || wwsA1MeanM01(6) > wwsA1HiM01(6)
            || wwsA1LoM02(6) > wwsA1MeanM02(6)
            || wwsA1MeanM02(6) > wwsA1HiM02(6)
            || wwsA1LoM03(6) > wwsA1MeanM03(6)
            || wwsA1MeanM03(6) > wwsA1HiM03(6)
            || wwsA1LoM04(6) > wwsA1MeanM04(6)
            || wwsA1MeanM04(6) > wwsA1HiM04(6)
            || wwsA1LoM05(6) > wwsA1MeanM05(6)
            || wwsA1MeanM05(6) > wwsA1HiM05(6)
            || wwsA1LoM06(6) > wwsA1MeanM06(6)
            || wwsA1MeanM06(6) > wwsA1HiM06(6)
            || wwsA1LoM07(6) > wwsA1MeanM07(6)
            || wwsA1MeanM07(6) > wwsA1HiM07(6)
            || wwsA1LoM08(6) > wwsA1MeanM08(6)
            || wwsA1MeanM08(6) > wwsA1HiM08(6)
            || wwsA1LoM09(6) > wwsA1MeanM09(6)
            || wwsA1MeanM09(6) > wwsA1HiM09(6)
            || wwsA1LoM10(6) > wwsA1MeanM10(6)
            || wwsA1MeanM10(6) > wwsA1HiM10(6)
            || wwsA1LoM11(6) > wwsA1MeanM11(6)
            || wwsA1MeanM11(6) > wwsA1HiM11(6)
            || wwsA1LoM12(6) > wwsA1MeanM12(6)
            || wwsA1MeanM12(6) > wwsA1HiM12(6)
            || wwsA1LoM01(7) > wwsA1MeanM01(7)
            || wwsA1MeanM01(7) > wwsA1HiM01(7)
            || wwsA1LoM02(7) > wwsA1MeanM02(7)
            || wwsA1MeanM02(7) > wwsA1HiM02(7)
            || wwsA1LoM03(7) > wwsA1MeanM03(7)
            || wwsA1MeanM03(7) > wwsA1HiM03(7)
            || wwsA1LoM04(7) > wwsA1MeanM04(7)
            || wwsA1MeanM04(7) > wwsA1HiM04(7)
            || wwsA1LoM05(7) > wwsA1MeanM05(7)
            || wwsA1MeanM05(7) > wwsA1HiM05(7)
            || wwsA1LoM06(7) > wwsA1MeanM06(7)
            || wwsA1MeanM06(7) > wwsA1HiM06(7)
            || wwsA1LoM07(7) > wwsA1MeanM07(7)
            || wwsA1MeanM07(7) > wwsA1HiM07(7)
            || wwsA1LoM08(7) > wwsA1MeanM08(7)
            || wwsA1MeanM08(7) > wwsA1HiM08(7)
            || wwsA1LoM09(7) > wwsA1MeanM09(7)
            || wwsA1MeanM09(7) > wwsA1HiM09(7)
            || wwsA1LoM10(7) > wwsA1MeanM10(7)
            || wwsA1MeanM10(7) > wwsA1HiM10(7)
            || wwsA1LoM11(7) > wwsA1MeanM11(7)
            || wwsA1MeanM11(7) > wwsA1HiM11(7)
            || wwsA1LoM12(7) > wwsA1MeanM12(7)
            || wwsA1MeanM12(7) > wwsA1HiM12(7)
            || wwsA1LoM01(8) > wwsA1MeanM01(8)
            || wwsA1MeanM01(8) > wwsA1HiM01(8)
            || wwsA1LoM02(8) > wwsA1MeanM02(8)
            || wwsA1MeanM02(8) > wwsA1HiM02(8)
            || wwsA1LoM03(8) > wwsA1MeanM03(8)
            || wwsA1MeanM03(8) > wwsA1HiM03(8)
            || wwsA1LoM04(8) > wwsA1MeanM04(8)
            || wwsA1MeanM04(8) > wwsA1HiM04(8)
            || wwsA1LoM05(8) > wwsA1MeanM05(8)
            || wwsA1MeanM05(8) > wwsA1HiM05(8)
            || wwsA1LoM06(8) > wwsA1MeanM06(8)
            || wwsA1MeanM06(8) > wwsA1HiM06(8)
            || wwsA1LoM07(8) > wwsA1MeanM07(8)
            || wwsA1MeanM07(8) > wwsA1HiM07(8)
            || wwsA1LoM08(8) > wwsA1MeanM08(8)
            || wwsA1MeanM08(8) > wwsA1HiM08(8)
            || wwsA1LoM09(8) > wwsA1MeanM09(8)
            || wwsA1MeanM09(8) > wwsA1HiM09(8)
            || wwsA1LoM10(8) > wwsA1MeanM10(8)
            || wwsA1MeanM10(8) > wwsA1HiM10(8)
            || wwsA1LoM11(8) > wwsA1MeanM11(8)
            || wwsA1MeanM11(8) > wwsA1HiM11(8)
            || wwsA1LoM12(8) > wwsA1MeanM12(8)
            || wwsA1MeanM12(8) > wwsA1HiM12(8)
            || wwsA1LoM01(9) > wwsA1MeanM01(9)
            || wwsA1MeanM01(9) > wwsA1HiM01(9)
            || wwsA1LoM02(9) > wwsA1MeanM02(9)
            || wwsA1MeanM02(9) > wwsA1HiM02(9)
            || wwsA1LoM03(9) > wwsA1MeanM03(9)
            || wwsA1MeanM03(9) > wwsA1HiM03(9)
            || wwsA1LoM04(9) > wwsA1MeanM04(9)
            || wwsA1MeanM04(9) > wwsA1HiM04(9)
            || wwsA1LoM05(9) > wwsA1MeanM05(9)
            || wwsA1MeanM05(9) > wwsA1HiM05(9)
            || wwsA1LoM06(9) > wwsA1MeanM06(9)
            || wwsA1MeanM06(9) > wwsA1HiM06(9)
            || wwsA1LoM07(9) > wwsA1MeanM07(9)
            || wwsA1MeanM07(9) > wwsA1HiM07(9)
            || wwsA1LoM08(9) > wwsA1MeanM08(9)
            || wwsA1MeanM08(9) > wwsA1HiM08(9)
            || wwsA1LoM09(9) > wwsA1MeanM09(9)
            || wwsA1MeanM09(9) > wwsA1HiM09(9)
            || wwsA1LoM10(9) > wwsA1MeanM10(9)
            || wwsA1MeanM10(9) > wwsA1HiM10(9)
            || wwsA1LoM11(9) > wwsA1MeanM11(9)
            || wwsA1MeanM11(9) > wwsA1HiM11(9)
            || wwsA1LoM12(9) > wwsA1MeanM12(9)
            || wwsA1MeanM12(9) > wwsA1HiM12(9)
            || wwsA1LoM01(10) > wwsA1MeanM01(10)
            || wwsA1MeanM01(10) > wwsA1HiM01(10)
            || wwsA1LoM02(10) > wwsA1MeanM02(10)
            || wwsA1MeanM02(10) > wwsA1HiM02(10)
            || wwsA1LoM03(10) > wwsA1MeanM03(10)
            || wwsA1MeanM03(10) > wwsA1HiM03(10)
            || wwsA1LoM04(10) > wwsA1MeanM04(10)
            || wwsA1MeanM04(10) > wwsA1HiM04(10)
            || wwsA1LoM05(10) > wwsA1MeanM05(10)
            || wwsA1MeanM05(10) > wwsA1HiM05(10)
            || wwsA1LoM06(10) > wwsA1MeanM06(10)
            || wwsA1MeanM06(10) > wwsA1HiM06(10)
            || wwsA1LoM07(10) > wwsA1MeanM07(10)
            || wwsA1MeanM07(10) > wwsA1HiM07(10)
            || wwsA1LoM08(10) > wwsA1MeanM08(10)
            || wwsA1MeanM08(10) > wwsA1HiM08(10)
            || wwsA1LoM09(10) > wwsA1MeanM09(10)
            || wwsA1MeanM09(10) > wwsA1HiM09(10)
            || wwsA1LoM10(10) > wwsA1MeanM10(10)
            || wwsA1MeanM10(10) > wwsA1HiM10(10)
            || wwsA1LoM11(10) > wwsA1MeanM11(10)
            || wwsA1MeanM11(10) > wwsA1HiM11(10)
            || wwsA1LoM12(10) > wwsA1MeanM12(10)
            || wwsA1MeanM12(10) > wwsA1HiM12(10)
            || wwsA1LoM01(11) > wwsA1MeanM01(11)
            || wwsA1MeanM01(11) > wwsA1HiM01(11)
            || wwsA1LoM02(11) > wwsA1MeanM02(11)
            || wwsA1MeanM02(11) > wwsA1HiM02(11)
            || wwsA1LoM03(11) > wwsA1MeanM03(11)
            || wwsA1MeanM03(11) > wwsA1HiM03(11)
            || wwsA1LoM04(11) > wwsA1MeanM04(11)
            || wwsA1MeanM04(11) > wwsA1HiM04(11)
            || wwsA1LoM05(11) > wwsA1MeanM05(11)
            || wwsA1MeanM05(11) > wwsA1HiM05(11)
            || wwsA1LoM06(11) > wwsA1MeanM06(11)
            || wwsA1MeanM06(11) > wwsA1HiM06(11)
            || wwsA1LoM07(11) > wwsA1MeanM07(11)
            || wwsA1MeanM07(11) > wwsA1HiM07(11)
            || wwsA1LoM08(11) > wwsA1MeanM08(11)
            || wwsA1MeanM08(11) > wwsA1HiM08(11)
            || wwsA1LoM09(11) > wwsA1MeanM09(11)
            || wwsA1MeanM09(11) > wwsA1HiM09(11)
            || wwsA1LoM10(11) > wwsA1MeanM10(11)
            || wwsA1MeanM10(11) > wwsA1HiM10(11)
            || wwsA1LoM11(11) > wwsA1MeanM11(11)
            || wwsA1MeanM11(11) > wwsA1HiM11(11)
            || wwsA1LoM12(11) > wwsA1MeanM12(11)
            || wwsA1MeanM12(11) > wwsA1HiM12(11)
            || wwsA1LoM01(12) > wwsA1MeanM01(12)
            || wwsA1MeanM01(12) > wwsA1HiM01(12)
            || wwsA1LoM02(12) > wwsA1MeanM02(12)
            || wwsA1MeanM02(12) > wwsA1HiM02(12)
            || wwsA1LoM03(12) > wwsA1MeanM03(12)
            || wwsA1MeanM03(12) > wwsA1HiM03(12)
            || wwsA1LoM04(12) > wwsA1MeanM04(12)
            || wwsA1MeanM04(12) > wwsA1HiM04(12)
            || wwsA1LoM05(12) > wwsA1MeanM05(12)
            || wwsA1MeanM05(12) > wwsA1HiM05(12)
            || wwsA1LoM06(12) > wwsA1MeanM06(12)
            || wwsA1MeanM06(12) > wwsA1HiM06(12)
            || wwsA1LoM07(12) > wwsA1MeanM07(12)
            || wwsA1MeanM07(12) > wwsA1HiM07(12)
            || wwsA1LoM08(12) > wwsA1MeanM08(12)
            || wwsA1MeanM08(12) > wwsA1HiM08(12)
            || wwsA1LoM09(12) > wwsA1MeanM09(12)
            || wwsA1MeanM09(12) > wwsA1HiM09(12)
            || wwsA1LoM10(12) > wwsA1MeanM10(12)
            || wwsA1MeanM10(12) > wwsA1HiM10(12)
            || wwsA1LoM11(12) > wwsA1MeanM11(12)
            || wwsA1MeanM11(12) > wwsA1HiM11(12)
            || wwsA1LoM12(12) > wwsA1MeanM12(12)
            || wwsA1MeanM12(12) > wwsA1HiM12(12)
            || wwsA1LoM01(13) > wwsA1MeanM01(13)
            || wwsA1MeanM01(13) > wwsA1HiM01(13)
            || wwsA1LoM02(13) > wwsA1MeanM02(13)
            || wwsA1MeanM02(13) > wwsA1HiM02(13)
            || wwsA1LoM03(13) > wwsA1MeanM03(13)
            || wwsA1MeanM03(13) > wwsA1HiM03(13)
            || wwsA1LoM04(13) > wwsA1MeanM04(13)
            || wwsA1MeanM04(13) > wwsA1HiM04(13)
            || wwsA1LoM05(13) > wwsA1MeanM05(13)
            || wwsA1MeanM05(13) > wwsA1HiM05(13)
            || wwsA1LoM06(13) > wwsA1MeanM06(13)
            || wwsA1MeanM06(13) > wwsA1HiM06(13)
            || wwsA1LoM07(13) > wwsA1MeanM07(13)
            || wwsA1MeanM07(13) > wwsA1HiM07(13)
            || wwsA1LoM08(13) > wwsA1MeanM08(13)
            || wwsA1MeanM08(13) > wwsA1HiM08(13)
            || wwsA1LoM09(13) > wwsA1MeanM09(13)
            || wwsA1MeanM09(13) > wwsA1HiM09(13)
            || wwsA1LoM10(13) > wwsA1MeanM10(13)
            || wwsA1MeanM10(13) > wwsA1HiM10(13)
            || wwsA1LoM11(13) > wwsA1MeanM11(13)
            || wwsA1MeanM11(13) > wwsA1HiM11(13)
            || wwsA1LoM12(13) > wwsA1MeanM12(13)
            || wwsA1MeanM12(13) > wwsA1HiM12(13)
            || wwsA1LoM01(14) > wwsA1MeanM01(14)
            || wwsA1MeanM01(14) > wwsA1HiM01(14)
            || wwsA1LoM02(14) > wwsA1MeanM02(14)
            || wwsA1MeanM02(14) > wwsA1HiM02(14)
            || wwsA1LoM03(14) > wwsA1MeanM03(14)
            || wwsA1MeanM03(14) > wwsA1HiM03(14)
            || wwsA1LoM04(14) > wwsA1MeanM04(14)
            || wwsA1MeanM04(14) > wwsA1HiM04(14)
            || wwsA1LoM05(14) > wwsA1MeanM05(14)
            || wwsA1MeanM05(14) > wwsA1HiM05(14)
            || wwsA1LoM06(14) > wwsA1MeanM06(14)
            || wwsA1MeanM06(14) > wwsA1HiM06(14)
            || wwsA1LoM07(14) > wwsA1MeanM07(14)
            || wwsA1MeanM07(14) > wwsA1HiM07(14)
            || wwsA1LoM08(14) > wwsA1MeanM08(14)
            || wwsA1MeanM08(14) > wwsA1HiM08(14)
            || wwsA1LoM09(14) > wwsA1MeanM09(14)
            || wwsA1MeanM09(14) > wwsA1HiM09(14)
            || wwsA1LoM10(14) > wwsA1MeanM10(14)
            || wwsA1MeanM10(14) > wwsA1HiM10(14)
            || wwsA1LoM11(14) > wwsA1MeanM11(14)
            || wwsA1MeanM11(14) > wwsA1HiM11(14)
            || wwsA1LoM12(14) > wwsA1MeanM12(14)
            || wwsA1MeanM12(14) > wwsA1HiM12(14)
            || wwsA1LoM01(15) > wwsA1MeanM01(15)
            || wwsA1MeanM01(15) > wwsA1HiM01(15)
            || wwsA1LoM02(15) > wwsA1MeanM02(15)
            || wwsA1MeanM02(15) > wwsA1HiM02(15)
            || wwsA1LoM03(15) > wwsA1MeanM03(15)
            || wwsA1MeanM03(15) > wwsA1HiM03(15)
            || wwsA1LoM04(15) > wwsA1MeanM04(15)
            || wwsA1MeanM04(15) > wwsA1HiM04(15)
            || wwsA1LoM05(15) > wwsA1MeanM05(15)
            || wwsA1MeanM05(15) > wwsA1HiM05(15)
            || wwsA1LoM06(15) > wwsA1MeanM06(15)
            || wwsA1MeanM06(15) > wwsA1HiM06(15)
            || wwsA1LoM07(15) > wwsA1MeanM07(15)
            || wwsA1MeanM07(15) > wwsA1HiM07(15)
            || wwsA1LoM08(15) > wwsA1MeanM08(15)
            || wwsA1MeanM08(15) > wwsA1HiM08(15)
            || wwsA1LoM09(15) > wwsA1MeanM09(15)
            || wwsA1MeanM09(15) > wwsA1HiM09(15)
            || wwsA1LoM10(15) > wwsA1MeanM10(15)
            || wwsA1MeanM10(15) > wwsA1HiM10(15)
            || wwsA1LoM11(15) > wwsA1MeanM11(15)
            || wwsA1MeanM11(15) > wwsA1HiM11(15)
            || wwsA1LoM12(15) > wwsA1MeanM12(15)
            || wwsA1MeanM12(15) > wwsA1HiM12(15)
            || wwsA1LoM01(16) > wwsA1MeanM01(16)
            || wwsA1MeanM01(16) > wwsA1HiM01(16)
            || wwsA1LoM02(16) > wwsA1MeanM02(16)
            || wwsA1MeanM02(16) > wwsA1HiM02(16)
            || wwsA1LoM03(16) > wwsA1MeanM03(16)
            || wwsA1MeanM03(16) > wwsA1HiM03(16)
            || wwsA1LoM04(16) > wwsA1MeanM04(16)
            || wwsA1MeanM04(16) > wwsA1HiM04(16)
            || wwsA1LoM05(16) > wwsA1MeanM05(16)
            || wwsA1MeanM05(16) > wwsA1HiM05(16)
            || wwsA1LoM06(16) > wwsA1MeanM06(16)
            || wwsA1MeanM06(16) > wwsA1HiM06(16)
            || wwsA1LoM07(16) > wwsA1MeanM07(16)
            || wwsA1MeanM07(16) > wwsA1HiM07(16)
            || wwsA1LoM08(16) > wwsA1MeanM08(16)
            || wwsA1MeanM08(16) > wwsA1HiM08(16)
            || wwsA1LoM09(16) > wwsA1MeanM09(16)
            || wwsA1MeanM09(16) > wwsA1HiM09(16)
            || wwsA1LoM10(16) > wwsA1MeanM10(16)
            || wwsA1MeanM10(16) > wwsA1HiM10(16)
            || wwsA1LoM11(16) > wwsA1MeanM11(16)
            || wwsA1MeanM11(16) > wwsA1HiM11(16)
            || wwsA1LoM12(16) > wwsA1MeanM12(16)
            || wwsA1MeanM12(16) > wwsA1HiM12(16)
            || wwsA1LoM01(17) > wwsA1MeanM01(17)
            || wwsA1MeanM01(17) > wwsA1HiM01(17)
            || wwsA1LoM02(17) > wwsA1MeanM02(17)
            || wwsA1MeanM02(17) > wwsA1HiM02(17)
            || wwsA1LoM03(17) > wwsA1MeanM03(17)
            || wwsA1MeanM03(17) > wwsA1HiM03(17)
            || wwsA1LoM04(17) > wwsA1MeanM04(17)
            || wwsA1MeanM04(17) > wwsA1HiM04(17)
            || wwsA1LoM05(17) > wwsA1MeanM05(17)
            || wwsA1MeanM05(17) > wwsA1HiM05(17)
            || wwsA1LoM06(17) > wwsA1MeanM06(17)
            || wwsA1MeanM06(17) > wwsA1HiM06(17)
            || wwsA1LoM07(17) > wwsA1MeanM07(17)
            || wwsA1MeanM07(17) > wwsA1HiM07(17)
            || wwsA1LoM08(17) > wwsA1MeanM08(17)
            || wwsA1MeanM08(17) > wwsA1HiM08(17)
            || wwsA1LoM09(17) > wwsA1MeanM09(17)
            || wwsA1MeanM09(17) > wwsA1HiM09(17)
            || wwsA1LoM10(17) > wwsA1MeanM10(17)
            || wwsA1MeanM10(17) > wwsA1HiM10(17)
            || wwsA1LoM11(17) > wwsA1MeanM11(17)
            || wwsA1MeanM11(17) > wwsA1HiM11(17)
            || wwsA1LoM12(17) > wwsA1MeanM12(17)
            || wwsA1MeanM12(17) > wwsA1HiM12(17)
            || wwsA1LoM01(18) > wwsA1MeanM01(18)
            || wwsA1MeanM01(18) > wwsA1HiM01(18)
            || wwsA1LoM02(18) > wwsA1MeanM02(18)
            || wwsA1MeanM02(18) > wwsA1HiM02(18)
            || wwsA1LoM03(18) > wwsA1MeanM03(18)
            || wwsA1MeanM03(18) > wwsA1HiM03(18)
            || wwsA1LoM04(18) > wwsA1MeanM04(18)
            || wwsA1MeanM04(18) > wwsA1HiM04(18)
            || wwsA1LoM05(18) > wwsA1MeanM05(18)
            || wwsA1MeanM05(18) > wwsA1HiM05(18)
            || wwsA1LoM06(18) > wwsA1MeanM06(18)
            || wwsA1MeanM06(18) > wwsA1HiM06(18)
            || wwsA1LoM07(18) > wwsA1MeanM07(18)
            || wwsA1MeanM07(18) > wwsA1HiM07(18)
            || wwsA1LoM08(18) > wwsA1MeanM08(18)
            || wwsA1MeanM08(18) > wwsA1HiM08(18)
            || wwsA1LoM09(18) > wwsA1MeanM09(18)
            || wwsA1MeanM09(18) > wwsA1HiM09(18)
            || wwsA1LoM10(18) > wwsA1MeanM10(18)
            || wwsA1MeanM10(18) > wwsA1HiM10(18)
            || wwsA1LoM11(18) > wwsA1MeanM11(18)
            || wwsA1MeanM11(18) > wwsA1HiM11(18)
            || wwsA1LoM12(18) > wwsA1MeanM12(18)
            || wwsA1MeanM12(18) > wwsA1HiM12(18)
            || wwsA1LoM01(19) > wwsA1MeanM01(19)
            || wwsA1MeanM01(19) > wwsA1HiM01(19)
            || wwsA1LoM02(19) > wwsA1MeanM02(19)
            || wwsA1MeanM02(19) > wwsA1HiM02(19)
            || wwsA1LoM03(19) > wwsA1MeanM03(19)
            || wwsA1MeanM03(19) > wwsA1HiM03(19)
            || wwsA1LoM04(19) > wwsA1MeanM04(19)
            || wwsA1MeanM04(19) > wwsA1HiM04(19)
            || wwsA1LoM05(19) > wwsA1MeanM05(19)
            || wwsA1MeanM05(19) > wwsA1HiM05(19)
            || wwsA1LoM06(19) > wwsA1MeanM06(19)
            || wwsA1MeanM06(19) > wwsA1HiM06(19)
            || wwsA1LoM07(19) > wwsA1MeanM07(19)
            || wwsA1MeanM07(19) > wwsA1HiM07(19)
            || wwsA1LoM08(19) > wwsA1MeanM08(19)
            || wwsA1MeanM08(19) > wwsA1HiM08(19)
            || wwsA1LoM09(19) > wwsA1MeanM09(19)
            || wwsA1MeanM09(19) > wwsA1HiM09(19)
            || wwsA1LoM10(19) > wwsA1MeanM10(19)
            || wwsA1MeanM10(19) > wwsA1HiM10(19)
            || wwsA1LoM11(19) > wwsA1MeanM11(19)
            || wwsA1MeanM11(19) > wwsA1HiM11(19)
            || wwsA1LoM12(19) > wwsA1MeanM12(19)
            || wwsA1MeanM12(19) > wwsA1HiM12(19)
            || wwsA1LoM01(20) > wwsA1MeanM01(20)
            || wwsA1MeanM01(20) > wwsA1HiM01(20)
            || wwsA1LoM02(20) > wwsA1MeanM02(20)
            || wwsA1MeanM02(20) > wwsA1HiM02(20)
            || wwsA1LoM03(20) > wwsA1MeanM03(20)
            || wwsA1MeanM03(20) > wwsA1HiM03(20)
            || wwsA1LoM04(20) > wwsA1MeanM04(20)
            || wwsA1MeanM04(20) > wwsA1HiM04(20)
            || wwsA1LoM05(20) > wwsA1MeanM05(20)
            || wwsA1MeanM05(20) > wwsA1HiM05(20)
            || wwsA1LoM06(20) > wwsA1MeanM06(20)
            || wwsA1MeanM06(20) > wwsA1HiM06(20)
            || wwsA1LoM07(20) > wwsA1MeanM07(20)
            || wwsA1MeanM07(20) > wwsA1HiM07(20)
            || wwsA1LoM08(20) > wwsA1MeanM08(20)
            || wwsA1MeanM08(20) > wwsA1HiM08(20)
            || wwsA1LoM09(20) > wwsA1MeanM09(20)
            || wwsA1MeanM09(20) > wwsA1HiM09(20)
            || wwsA1LoM10(20) > wwsA1MeanM10(20)
            || wwsA1MeanM10(20) > wwsA1HiM10(20)
            || wwsA1LoM11(20) > wwsA1MeanM11(20)
            || wwsA1MeanM11(20) > wwsA1HiM11(20)
            || wwsA1LoM12(20) > wwsA1MeanM12(20)
            || wwsA1MeanM12(20) > wwsA1HiM12(20)
            || wwsA1LoM01(21) > wwsA1MeanM01(21)
            || wwsA1MeanM01(21) > wwsA1HiM01(21)
            || wwsA1LoM02(21) > wwsA1MeanM02(21)
            || wwsA1MeanM02(21) > wwsA1HiM02(21)
            || wwsA1LoM03(21) > wwsA1MeanM03(21)
            || wwsA1MeanM03(21) > wwsA1HiM03(21)
            || wwsA1LoM04(21) > wwsA1MeanM04(21)
            || wwsA1MeanM04(21) > wwsA1HiM04(21)
            || wwsA1LoM05(21) > wwsA1MeanM05(21)
            || wwsA1MeanM05(21) > wwsA1HiM05(21)
            || wwsA1LoM06(21) > wwsA1MeanM06(21)
            || wwsA1MeanM06(21) > wwsA1HiM06(21)
            || wwsA1LoM07(21) > wwsA1MeanM07(21)
            || wwsA1MeanM07(21) > wwsA1HiM07(21)
            || wwsA1LoM08(21) > wwsA1MeanM08(21)
            || wwsA1MeanM08(21) > wwsA1HiM08(21)
            || wwsA1LoM09(21) > wwsA1MeanM09(21)
            || wwsA1MeanM09(21) > wwsA1HiM09(21)
            || wwsA1LoM10(21) > wwsA1MeanM10(21)
            || wwsA1MeanM10(21) > wwsA1HiM10(21)
            || wwsA1LoM11(21) > wwsA1MeanM11(21)
            || wwsA1MeanM11(21) > wwsA1HiM11(21)
            || wwsA1LoM12(21) > wwsA1MeanM12(21)
            || wwsA1MeanM12(21) > wwsA1HiM12(21)
            || wwsA1LoM01(22) > wwsA1MeanM01(22)
            || wwsA1MeanM01(22) > wwsA1HiM01(22)
            || wwsA1LoM02(22) > wwsA1MeanM02(22)
            || wwsA1MeanM02(22) > wwsA1HiM02(22)
            || wwsA1LoM03(22) > wwsA1MeanM03(22)
            || wwsA1MeanM03(22) > wwsA1HiM03(22)
            || wwsA1LoM04(22) > wwsA1MeanM04(22)
            || wwsA1MeanM04(22) > wwsA1HiM04(22)
            || wwsA1LoM05(22) > wwsA1MeanM05(22)
            || wwsA1MeanM05(22) > wwsA1HiM05(22)
            || wwsA1LoM06(22) > wwsA1MeanM06(22)
            || wwsA1MeanM06(22) > wwsA1HiM06(22)
            || wwsA1LoM07(22) > wwsA1MeanM07(22)
            || wwsA1MeanM07(22) > wwsA1HiM07(22)
            || wwsA1LoM08(22) > wwsA1MeanM08(22)
            || wwsA1MeanM08(22) > wwsA1HiM08(22)
            || wwsA1LoM09(22) > wwsA1MeanM09(22)
            || wwsA1MeanM09(22) > wwsA1HiM09(22)
            || wwsA1LoM10(22) > wwsA1MeanM10(22)
            || wwsA1MeanM10(22) > wwsA1HiM10(22)
            || wwsA1LoM11(22) > wwsA1MeanM11(22)
            || wwsA1MeanM11(22) > wwsA1HiM11(22)
            || wwsA1LoM12(22) > wwsA1MeanM12(22)
            || wwsA1MeanM12(22) > wwsA1HiM12(22)
            || wwsA1LoM01(23) > wwsA1MeanM01(23)
            || wwsA1MeanM01(23) > wwsA1HiM01(23)
            || wwsA1LoM02(23) > wwsA1MeanM02(23)
            || wwsA1MeanM02(23) > wwsA1HiM02(23)
            || wwsA1LoM03(23) > wwsA1MeanM03(23)
            || wwsA1MeanM03(23) > wwsA1HiM03(23)
            || wwsA1LoM04(23) > wwsA1MeanM04(23)
            || wwsA1MeanM04(23) > wwsA1HiM04(23)
            || wwsA1LoM05(23) > wwsA1MeanM05(23)
            || wwsA1MeanM05(23) > wwsA1HiM05(23)
            || wwsA1LoM06(23) > wwsA1MeanM06(23)
            || wwsA1MeanM06(23) > wwsA1HiM06(23)
            || wwsA1LoM07(23) > wwsA1MeanM07(23)
            || wwsA1MeanM07(23) > wwsA1HiM07(23)
            || wwsA1LoM08(23) > wwsA1MeanM08(23)
            || wwsA1MeanM08(23) > wwsA1HiM08(23)
            || wwsA1LoM09(23) > wwsA1MeanM09(23)
            || wwsA1MeanM09(23) > wwsA1HiM09(23)
            || wwsA1LoM10(23) > wwsA1MeanM10(23)
            || wwsA1MeanM10(23) > wwsA1HiM10(23)
            || wwsA1LoM11(23) > wwsA1MeanM11(23)
            || wwsA1MeanM11(23) > wwsA1HiM11(23)
            || wwsA1LoM12(23) > wwsA1MeanM12(23)
            || wwsA1MeanM12(23) > wwsA1HiM12(23)
            || wwsA1LoM01(24) > wwsA1MeanM01(24)
            || wwsA1MeanM01(24) > wwsA1HiM01(24)
            || wwsA1LoM02(24) > wwsA1MeanM02(24)
            || wwsA1MeanM02(24) > wwsA1HiM02(24)
            || wwsA1LoM03(24) > wwsA1MeanM03(24)
            || wwsA1MeanM03(24) > wwsA1HiM03(24)
            || wwsA1LoM04(24) > wwsA1MeanM04(24)
            || wwsA1MeanM04(24) > wwsA1HiM04(24)
            || wwsA1LoM05(24) > wwsA1MeanM05(24)
            || wwsA1MeanM05(24) > wwsA1HiM05(24)
            || wwsA1LoM06(24) > wwsA1MeanM06(24)
            || wwsA1MeanM06(24) > wwsA1HiM06(24)
            || wwsA1LoM07(24) > wwsA1MeanM07(24)
            || wwsA1MeanM07(24) > wwsA1HiM07(24)
            || wwsA1LoM08(24) > wwsA1MeanM08(24)
            || wwsA1MeanM08(24) > wwsA1HiM08(24)
            || wwsA1LoM09(24) > wwsA1MeanM09(24)
            || wwsA1MeanM09(24) > wwsA1HiM09(24)
            || wwsA1LoM10(24) > wwsA1MeanM10(24)
            || wwsA1MeanM10(24) > wwsA1HiM10(24)
            || wwsA1LoM11(24) > wwsA1MeanM11(24)
            || wwsA1MeanM11(24) > wwsA1HiM11(24)
            || wwsA1LoM12(24) > wwsA1MeanM12(24)
            || wwsA1MeanM12(24) > wwsA1HiM12(24)
            || wwsA1LoM01(25) > wwsA1MeanM01(25)
            || wwsA1MeanM01(25) > wwsA1HiM01(25)
            || wwsA1LoM02(25) > wwsA1MeanM02(25)
            || wwsA1MeanM02(25) > wwsA1HiM02(25)
            || wwsA1LoM03(25) > wwsA1MeanM03(25)
            || wwsA1MeanM03(25) > wwsA1HiM03(25)
            || wwsA1LoM04(25) > wwsA1MeanM04(25)
            || wwsA1MeanM04(25) > wwsA1HiM04(25)
            || wwsA1LoM05(25) > wwsA1MeanM05(25)
            || wwsA1MeanM05(25) > wwsA1HiM05(25)
            || wwsA1LoM06(25) > wwsA1MeanM06(25)
            || wwsA1MeanM06(25) > wwsA1HiM06(25)
            || wwsA1LoM07(25) > wwsA1MeanM07(25)
            || wwsA1MeanM07(25) > wwsA1HiM07(25)
            || wwsA1LoM08(25) > wwsA1MeanM08(25)
            || wwsA1MeanM08(25) > wwsA1HiM08(25)
            || wwsA1LoM09(25) > wwsA1MeanM09(25)
            || wwsA1MeanM09(25) > wwsA1HiM09(25)
            || wwsA1LoM10(25) > wwsA1MeanM10(25)
            || wwsA1MeanM10(25) > wwsA1HiM10(25)
            || wwsA1LoM11(25) > wwsA1MeanM11(25)
            || wwsA1MeanM11(25) > wwsA1HiM11(25)
            || wwsA1LoM12(25) > wwsA1MeanM12(25)
            || wwsA1MeanM12(25) > wwsA1HiM12(25)
            || wwsA1LoM01(26) > wwsA1MeanM01(26)
            || wwsA1MeanM01(26) > wwsA1HiM01(26)
            || wwsA1LoM02(26) > wwsA1MeanM02(26)
            || wwsA1MeanM02(26) > wwsA1HiM02(26)
            || wwsA1LoM03(26) > wwsA1MeanM03(26)
            || wwsA1MeanM03(26) > wwsA1HiM03(26)
            || wwsA1LoM04(26) > wwsA1MeanM04(26)
            || wwsA1MeanM04(26) > wwsA1HiM04(26)
            || wwsA1LoM05(26) > wwsA1MeanM05(26)
            || wwsA1MeanM05(26) > wwsA1HiM05(26)
            || wwsA1LoM06(26) > wwsA1MeanM06(26)
            || wwsA1MeanM06(26) > wwsA1HiM06(26)
            || wwsA1LoM07(26) > wwsA1MeanM07(26)
            || wwsA1MeanM07(26) > wwsA1HiM07(26)
            || wwsA1LoM08(26) > wwsA1MeanM08(26)
            || wwsA1MeanM08(26) > wwsA1HiM08(26)
            || wwsA1LoM09(26) > wwsA1MeanM09(26)
            || wwsA1MeanM09(26) > wwsA1HiM09(26)
            || wwsA1LoM10(26) > wwsA1MeanM10(26)
            || wwsA1MeanM10(26) > wwsA1HiM10(26)
            || wwsA1LoM11(26) > wwsA1MeanM11(26)
            || wwsA1MeanM11(26) > wwsA1HiM11(26)
            || wwsA1LoM12(26) > wwsA1MeanM12(26)
            || wwsA1MeanM12(26) > wwsA1HiM12(26)
            || wwsA1LoM01(27) > wwsA1MeanM01(27)
            || wwsA1MeanM01(27) > wwsA1HiM01(27)
            || wwsA1LoM02(27) > wwsA1MeanM02(27)
            || wwsA1MeanM02(27) > wwsA1HiM02(27)
            || wwsA1LoM03(27) > wwsA1MeanM03(27)
            || wwsA1MeanM03(27) > wwsA1HiM03(27)
            || wwsA1LoM04(27) > wwsA1MeanM04(27)
            || wwsA1MeanM04(27) > wwsA1HiM04(27)
            || wwsA1LoM05(27) > wwsA1MeanM05(27)
            || wwsA1MeanM05(27) > wwsA1HiM05(27)
            || wwsA1LoM06(27) > wwsA1MeanM06(27)
            || wwsA1MeanM06(27) > wwsA1HiM06(27)
            || wwsA1LoM07(27) > wwsA1MeanM07(27)
            || wwsA1MeanM07(27) > wwsA1HiM07(27)
            || wwsA1LoM08(27) > wwsA1MeanM08(27)
            || wwsA1MeanM08(27) > wwsA1HiM08(27)
            || wwsA1LoM09(27) > wwsA1MeanM09(27)
            || wwsA1MeanM09(27) > wwsA1HiM09(27)
            || wwsA1LoM10(27) > wwsA1MeanM10(27)
            || wwsA1MeanM10(27) > wwsA1HiM10(27)
            || wwsA1LoM11(27) > wwsA1MeanM11(27)
            || wwsA1MeanM11(27) > wwsA1HiM11(27)
            || wwsA1LoM12(27) > wwsA1MeanM12(27)
            || wwsA1MeanM12(27) > wwsA1HiM12(27)
            || wwsA1LoM01(28) > wwsA1MeanM01(28)
            || wwsA1MeanM01(28) > wwsA1HiM01(28)
            || wwsA1LoM02(28) > wwsA1MeanM02(28)
            || wwsA1MeanM02(28) > wwsA1HiM02(28)
            || wwsA1LoM03(28) > wwsA1MeanM03(28)
            || wwsA1MeanM03(28) > wwsA1HiM03(28)
            || wwsA1LoM04(28) > wwsA1MeanM04(28)
            || wwsA1MeanM04(28) > wwsA1HiM04(28)
            || wwsA1LoM05(28) > wwsA1MeanM05(28)
            || wwsA1MeanM05(28) > wwsA1HiM05(28)
            || wwsA1LoM06(28) > wwsA1MeanM06(28)
            || wwsA1MeanM06(28) > wwsA1HiM06(28)
            || wwsA1LoM07(28) > wwsA1MeanM07(28)
            || wwsA1MeanM07(28) > wwsA1HiM07(28)
            || wwsA1LoM08(28) > wwsA1MeanM08(28)
            || wwsA1MeanM08(28) > wwsA1HiM08(28)
            || wwsA1LoM09(28) > wwsA1MeanM09(28)
            || wwsA1MeanM09(28) > wwsA1HiM09(28)
            || wwsA1LoM10(28) > wwsA1MeanM10(28)
            || wwsA1MeanM10(28) > wwsA1HiM10(28)
            || wwsA1LoM11(28) > wwsA1MeanM11(28)
            || wwsA1MeanM11(28) > wwsA1HiM11(28)
            || wwsA1LoM12(28) > wwsA1MeanM12(28)
            || wwsA1MeanM12(28) > wwsA1HiM12(28)
            || wwsA1LoM01(29) > wwsA1MeanM01(29)
            || wwsA1MeanM01(29) > wwsA1HiM01(29)
            || wwsA1LoM02(29) > wwsA1MeanM02(29)
            || wwsA1MeanM02(29) > wwsA1HiM02(29)
            || wwsA1LoM03(29) > wwsA1MeanM03(29)
            || wwsA1MeanM03(29) > wwsA1HiM03(29)
            || wwsA1LoM04(29) > wwsA1MeanM04(29)
            || wwsA1MeanM04(29) > wwsA1HiM04(29)
            || wwsA1LoM05(29) > wwsA1MeanM05(29)
            || wwsA1MeanM05(29) > wwsA1HiM05(29)
            || wwsA1LoM06(29) > wwsA1MeanM06(29)
            || wwsA1MeanM06(29) > wwsA1HiM06(29)
            || wwsA1LoM07(29) > wwsA1MeanM07(29)
            || wwsA1MeanM07(29) > wwsA1HiM07(29)
            || wwsA1LoM08(29) > wwsA1MeanM08(29)
            || wwsA1MeanM08(29) > wwsA1HiM08(29)
            || wwsA1LoM09(29) > wwsA1MeanM09(29)
            || wwsA1MeanM09(29) > wwsA1HiM09(29)
            || wwsA1LoM10(29) > wwsA1MeanM10(29)
            || wwsA1MeanM10(29) > wwsA1HiM10(29)
            || wwsA1LoM11(29) > wwsA1MeanM11(29)
            || wwsA1MeanM11(29) > wwsA1HiM11(29)
            || wwsA1LoM12(29) > wwsA1MeanM12(29)
            || wwsA1MeanM12(29) > wwsA1HiM12(29)
        )
            ++bad;
        // the printed arctic note: the Table A1 entries are identical for
        // arctic desert and arctic plains, and for arctic hills and arctic
        // mountains
    if (wwsA1LoM01(0) != wwsA1LoM01(4)
            || wwsA1LoM01(2) != wwsA1LoM01(3)
            || wwsA1MeanM01(0) != wwsA1MeanM01(4)
            || wwsA1MeanM01(2) != wwsA1MeanM01(3)
            || wwsA1HiM01(0) != wwsA1HiM01(4)
            || wwsA1HiM01(2) != wwsA1HiM01(3)
            || wwsA1LoM02(0) != wwsA1LoM02(4)
            || wwsA1LoM02(2) != wwsA1LoM02(3)
            || wwsA1MeanM02(0) != wwsA1MeanM02(4)
            || wwsA1MeanM02(2) != wwsA1MeanM02(3)
            || wwsA1HiM02(0) != wwsA1HiM02(4)
            || wwsA1HiM02(2) != wwsA1HiM02(3)
            || wwsA1LoM03(0) != wwsA1LoM03(4)
            || wwsA1LoM03(2) != wwsA1LoM03(3)
            || wwsA1MeanM03(0) != wwsA1MeanM03(4)
            || wwsA1MeanM03(2) != wwsA1MeanM03(3)
            || wwsA1HiM03(0) != wwsA1HiM03(4)
            || wwsA1HiM03(2) != wwsA1HiM03(3)
            || wwsA1LoM04(0) != wwsA1LoM04(4)
            || wwsA1LoM04(2) != wwsA1LoM04(3)
            || wwsA1MeanM04(0) != wwsA1MeanM04(4)
            || wwsA1MeanM04(2) != wwsA1MeanM04(3)
            || wwsA1HiM04(0) != wwsA1HiM04(4)
            || wwsA1HiM04(2) != wwsA1HiM04(3)
            || wwsA1LoM05(0) != wwsA1LoM05(4)
            || wwsA1LoM05(2) != wwsA1LoM05(3)
            || wwsA1MeanM05(0) != wwsA1MeanM05(4)
            || wwsA1MeanM05(2) != wwsA1MeanM05(3)
            || wwsA1HiM05(0) != wwsA1HiM05(4)
            || wwsA1HiM05(2) != wwsA1HiM05(3)
            || wwsA1LoM06(0) != wwsA1LoM06(4)
            || wwsA1LoM06(2) != wwsA1LoM06(3)
            || wwsA1MeanM06(0) != wwsA1MeanM06(4)
            || wwsA1MeanM06(2) != wwsA1MeanM06(3)
            || wwsA1HiM06(0) != wwsA1HiM06(4)
            || wwsA1HiM06(2) != wwsA1HiM06(3)
            || wwsA1LoM07(0) != wwsA1LoM07(4)
            || wwsA1LoM07(2) != wwsA1LoM07(3)
            || wwsA1MeanM07(0) != wwsA1MeanM07(4)
            || wwsA1MeanM07(2) != wwsA1MeanM07(3)
            || wwsA1HiM07(0) != wwsA1HiM07(4)
            || wwsA1HiM07(2) != wwsA1HiM07(3)
            || wwsA1LoM08(0) != wwsA1LoM08(4)
            || wwsA1LoM08(2) != wwsA1LoM08(3)
            || wwsA1MeanM08(0) != wwsA1MeanM08(4)
            || wwsA1MeanM08(2) != wwsA1MeanM08(3)
            || wwsA1HiM08(0) != wwsA1HiM08(4)
            || wwsA1HiM08(2) != wwsA1HiM08(3)
            || wwsA1LoM09(0) != wwsA1LoM09(4)
            || wwsA1LoM09(2) != wwsA1LoM09(3)
            || wwsA1MeanM09(0) != wwsA1MeanM09(4)
            || wwsA1MeanM09(2) != wwsA1MeanM09(3)
            || wwsA1HiM09(0) != wwsA1HiM09(4)
            || wwsA1HiM09(2) != wwsA1HiM09(3)
            || wwsA1LoM10(0) != wwsA1LoM10(4)
            || wwsA1LoM10(2) != wwsA1LoM10(3)
            || wwsA1MeanM10(0) != wwsA1MeanM10(4)
            || wwsA1MeanM10(2) != wwsA1MeanM10(3)
            || wwsA1HiM10(0) != wwsA1HiM10(4)
            || wwsA1HiM10(2) != wwsA1HiM10(3)
            || wwsA1LoM11(0) != wwsA1LoM11(4)
            || wwsA1LoM11(2) != wwsA1LoM11(3)
            || wwsA1MeanM11(0) != wwsA1MeanM11(4)
            || wwsA1MeanM11(2) != wwsA1MeanM11(3)
            || wwsA1HiM11(0) != wwsA1HiM11(4)
            || wwsA1HiM11(2) != wwsA1HiM11(3)
            || wwsA1LoM12(0) != wwsA1LoM12(4)
            || wwsA1LoM12(2) != wwsA1LoM12(3)
            || wwsA1MeanM12(0) != wwsA1MeanM12(4)
            || wwsA1MeanM12(2) != wwsA1MeanM12(3)
            || wwsA1HiM12(0) != wwsA1HiM12(4)
            || wwsA1HiM12(2) != wwsA1HiM12(3)
        )
            ++bad;
        // the day-to-day steps never decrease as the 2d6 roll rises
    if (wwsA2Steps(0) > wwsA2Steps(1)
            || wwsA2Steps(1) > wwsA2Steps(2)
            || wwsA2Steps(2) > wwsA2Steps(3)
            || wwsA2Steps(3) > wwsA2Steps(4)
            || wwsA2Steps(4) > wwsA2Steps(5)
            || wwsA2Steps(5) > wwsA2Steps(6)
            || wwsA2Steps(6) > wwsA2Steps(7)
            || wwsA2Steps(7) > wwsA2Steps(8)
            || wwsA2Steps(8) > wwsA2Steps(9)
            || wwsA2Steps(9) > wwsA2Steps(10)
        )
            ++bad;
        // the day-to-day steps are symmetric about the roll of 7: -3 against
        // +3, -2 against +2, -1 against +1
    if (wwsA2Steps(0) + wwsA2Steps(10) != 0
            || wwsA2Steps(1) + wwsA2Steps(9) != 0
            || wwsA2Steps(2) + wwsA2Steps(8) != 0
            || wwsA2Steps(3) + wwsA2Steps(7) != 0
            || wwsA2Steps(4) + wwsA2Steps(6) != 0
        )
            ++bad;
        // the chance-of-precipitation column is the dice parity: every even
        // roll is yes, every odd roll no, and the 7 is same-as-previous
    if (wwsA2Precip(0) != 1
            || wwsA2Precip(1) != 0
            || wwsA2Precip(2) != 1
            || wwsA2Precip(3) != 0
            || wwsA2Precip(4) != 1
            || wwsA2Precip(5) != 2
            || wwsA2Precip(6) != 1
            || wwsA2Precip(7) != 0
            || wwsA2Precip(8) != 1
            || wwsA2Precip(9) != 0
            || wwsA2Precip(10) != 1
        )
            ++bad;
        // the wind increments are symmetric about the roll of 7 (+15 against
        // -15, +10 against -10) with the 2 and 12 sentinels excluded
    if (wwsA2WindDelta(1) + wwsA2WindDelta(9) != 0
            || wwsA2WindDelta(2) + wwsA2WindDelta(8) != 0
            || wwsA2WindDelta(3) + wwsA2WindDelta(7) != 0
            || wwsA2WindDelta(4) + wwsA2WindDelta(6) != 0
        )
            ++bad;
        // the arctic precipitation pattern: the desert row carries a trace in
        // column B of every season, and the hills row none in A with a trace
        // in C
    if (wwsA3WiB(0) != 1
            || wwsA3SpB(0) != 1
            || wwsA3SuB(0) != 1
            || wwsA3AuB(0) != 1
            || wwsA3WiC(1) != 1
            || wwsA3WiA(1) != 0
            || wwsA3SpC(1) != 1
            || wwsA3SpA(1) != 0
            || wwsA3SuC(1) != 1
            || wwsA3SuA(1) != 0
            || wwsA3AuC(1) != 1
            || wwsA3AuA(1) != 0
        )
            ++bad;
        // the climatic latitude bands are strictly ordered down the globe:
        // arctic above subarctic above temperate above subtropical above
        // tropical
    if (wwxSubarcticHiLat() >= wwxArcticLoLat()
            || wwxTemperateHiLat() >= wwxSubarcticLoLat()
            || wwxSubtropHiLat() >= wwxTemperateLoLat()
            || wwxTropicHiLat() >= wwxSubtropLoLat()
        )
            ++bad;
        // the wind ceilings stack: the 45-mph global cap above the subarctic
        // 25-30 normal maximum above the arctic/tropical 20 with its 15-20
        // moderate band
    if (wwxWindCeilingMph() <= wwxSubarcticWindMaxHiMph()
            || wwxSubarcticWindMaxLoMph() > wwxSubarcticWindMaxHiMph()
            || wwxArcticWindLightMph() > wwxArcticWindModMph()
        )
            ++bad;
        // the extraordinary chance is the 1-3 d6 band with its two bounds
        // adjacent
    if (wwxExtraD6Hi() - wwxExtraD6Lo() != 2
            || wwxExtraD6Lo() != 1
            || wwxExtraStepUp() != 1
            || wwxExtraDoublesRun() != 2
        )
            ++bad;
        printf("R493 WSG weather generation audit: bad %d\n", bad);
        if (bad) return 1;
    }
