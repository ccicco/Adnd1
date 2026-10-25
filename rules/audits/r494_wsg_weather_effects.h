    // ---- R494 WSG weather effects audit ----
    // The Appendix: The World of Weather, part 2 of 2 - the special weather
    // system and the effects on play, printed pp. 112-119. Table A4 with the
    // Roll 1 / Roll 2 cross-index (the 2-or-12 carry-over, the fresh 2d6, the
    // five bands and the 1st-2nd-3rd-4th letter selection, the
    // running-episode suppression), the 33-row x 4-season special weather
    // grid (one packed four-letter code per cell: cold wave, cyclone,
    // drought, gale, mist/fog, sandstorm, tornado, extreme precipitation,
    // heat wave). The per-code definitions: the no-special 2 and 12 days (the
    // 45 mph very strong wind with the sharp drop, the 5 mph very slight wind
    // with the sharp rise, the B-column precipitation), the cold wave and its
    // heat wave mirror (2d6+2 days, 4 steps per day, the floor and ceiling
    // one step beyond the normal extreme, the 10-degree beyond-extreme cap
    // for 3 days, the automatic recovery with the 7-or-higher bonus rise),
    // the cyclone (the 1d6x20+60 mph wind, the seacoast lightning herald, the
    // 10-mile inland reach and 50-mile perimeter, the away-from-equator and
    // coast-following movement, the double downpour, the 3-mile tidal wave,
    // the 6-hour eye with its half-hour-to-hour dead calm, the second-half
    // rainstorm, the 10-mph eye wind, the 3-day no-change-table window with
    // the two-day 2d6 drift, the once-per-month 200-mile frequency cap with
    // the extreme-precipitation fallback, the 5-degree equator exclusion),
    // the drought (2d6+2 days, the day-1 shutoff, the once-per-5-days trace,
    // the heavy-to-light-to-trace-to-none ladder), the gale (1d6x5+40 mph for
    // 1d6+1 hours, the never-below-30 rule, the previous-20 boost, the desert
    // and snow severe-sandstorm readings), the mist/fog (the sunrise/sunset
    // 1-4/5-6 split, the 1d6 hours, the seacoast heavy reading, the suspended
    // precipitation, the 50-percent adjacent spread), the sandstorm (the
    // loose-material requirement, the no-precipitation day, the 1d4+1 and
    // severe 1d6+1 durations), the tornado (the suitable-conditions and
    // two-steps-above gates, the 1d3-hour front, the abrupt stop, the
    // half-mile calm, the 3d6-minute delay, the 15-degrees-or-3-steps drop
    // over 30 minutes, the quarter-by-15-mile path at 40 mph, the 200-300 mph
    // vortex, the low-pressure explosion), the extreme precipitation dispatch
    // (7 temperature bands x 2 climatic columns x the 1d6 sub-roll, the
    // 25-degree ice footnote) and its four payloads: the hailstorm (the
    // first-10-minutes-of-lightning rule, the 1-on-1d6 standalone, the 1d6+4
    // minutes, the quarter-inch stones to 2-3 inches, the 40-degree melt),
    // the ice storm (the half-to-three-quarter-inch coating, the 20-minute
    // heavy and 2-hour trace formation), the lightning storm (25 minutes,
    // three-quarters-to-1 inch of rain, the dawn/dusk window, the disregarded
    // standalone under moderate or light, the downpour start) and the severe
    // snowstorm (the 1d6+4 and 1d6+6 inch falls at 1 inch per hour, the
    // 1-2-hour calm then the 15-20 mph wind). The optional rules: the Table
    // A5 humidity variation grid with the letter codes and their percentage
    // bands, the day 1 / day 2 adjustment with the before and after slash
    // pairs, the three-level fluctuation range with the dry and saturated
    // edges and the two-level DM drop, the Table A6 humidity and effective
    // temperature grid (25 rows x 5 wind columns, applied at 60 degrees and
    // above), the Table A7 wind chill grid (17 x 8) with the below-minus-45
    // extrapolation and the 40-mph wind column cap, the Table A8 hours of
    // daylight grid (15 latitude rows x 12 months, stored in half-hours) with
    // the simplified middle-row option and the midnight/noon midpoint
    // convention, the twilight spans (30 minutes at 30-40 degrees, 20 at the
    // equator, 40 at 50-60, the 5-10-minute terrain cut, the all-day twilight
    // where the daylight reads zero), the local winds (the sea breeze by day
    // and the land breeze by night, the 5-10-mile inland reach, the clear-sky
    // favor, the coastal chill, the cliff-face trap), the tides (the
    // twice-daily alternation, the 12-hour highs and 6-hour lows, the 25-hour
    // lunar day with the hour-a-day advance, the 28-day cycle, the spring and
    // neap windows, the 5-7 and 15-18 foot ranges, the Fundy 60, the
    // gentle/moderate/severe slope encroachment multiples with both worked
    // examples) and the Dungeon Master responsibility (the 2-3-day
    // determinations, the free timeframe switching, the multi-day
    // predetermination).
    {
        using namespace rules;
        int bad = 0;
    if (wwyA4Roll1Two() != 2
            || wwyA4Roll1Twelve() != 12
            || wwyRoll2Bands() != 5
            || wwyRoll2Rows() != 2
            || wwyLetterPosNone() != 0
            || wwyLetterPos1st() != 1
            || wwyLetterPos2nd() != 2
            || wwyLetterPos3rd() != 3
            || wwyLetterPos4th() != 4
            || wwyA4Count() != 33
            || wwyA4PackBase() != 10
            || wwyCodeColdWave() != 1
            || wwyCodeCyclone() != 2
            || wwyCodeDrought() != 3
            || wwyCodeGale() != 4
            || wwyCodeMistFog() != 5
            || wwyCodeSandstorm() != 6
            || wwyCodeTornado() != 7
            || wwyCodeExtremePrecip() != 8
            || wwyCodeHeatWave() != 9
            || wwyNoSpecRoll2WindMph() != 45
            || wwyNoSpecRoll12WindMph() != 5
            || wwyColdWaveDice() != 2
            || wwyColdWaveDiePlus() != 2
            || wwyColdWaveStepsPerDay() != 4
            || wwyColdWaveAMinDropF() != 10
            || wwyColdWaveAMinDays() != 3
            || wwyColdWaveRecoveryRollLo() != 7
            || wwyHeatWaveDice() != 2
            || wwyHeatWaveDiePlus() != 2
            || wwyHeatWaveStepsPerDay() != 4
            || wwyHeatWaveZMaxRiseF() != 10
            || wwyHeatWaveZMaxDays() != 3
            || wwyHeatWaveRecoveryRollLo() != 7
            || wwyCycloneWindDice() != 1
            || wwyCycloneWindMult() != 20
            || wwyCycloneWindBase() != 60
            || wwyCycloneWindMinMph() != 80
            || wwyCycloneWindMaxMph() != 180
            || wwyCycloneInlandMaxMi() != 10
            || wwyCyclonePerimeterMi() != 50
            || wwyCycloneFollowsCoastDaysLo() != 1
            || wwyCycloneFollowsCoastDaysHi() != 2
            || wwyCycloneTidalWaveMi() != 3
            || wwyCycloneEyeHours() != 6
            || wwyCycloneEyeCalmMinLo() != 30
            || wwyCycloneEyeCalmMinHi() != 60
            || wwyCycloneEyeWindMaxMph() != 10
            || wwyCycloneNoChangeDays() != 3
            || wwyCycloneRadiusMi() != 200
            || wwyCycloneEquatorExclDeg() != 5
            || wwyDroughtDice() != 2
            || wwyDroughtDiePlus() != 2
            || wwyDroughtTraceGapDays() != 5
            || wwyGaleDieSides() != 6
            || wwyGaleMultMph() != 5
            || wwyGaleBaseMph() != 40
            || wwyGaleMinMph() != 45
            || wwyGaleMaxMph() != 70
            || wwyGaleDurDiePlus() != 1
            || wwyGaleDurMinHrs() != 2
            || wwyGaleDurMaxHrs() != 7
            || wwyMistSunriseRollMax() != 4
            || wwyMistHoursDie() != 6
            || wwySandstormDieSides() != 4
            || wwySandstormDiePlus() != 1
            || wwySandstormMinHrs() != 2
            || wwySandstormMaxHrs() != 5
            || wwySandstormSevDieSides() != 6
            || wwySandstormSevDiePlus() != 1
            || wwySandstormSevMinHrs() != 2
            || wwySandstormSevMaxHrs() != 7
            || wwyTornadoPrecipDieSides() != 3
            || wwyTornadoCalmDice() != 3
            || wwyTornadoCalmDieSides() != 6
            || wwyTornadoDropDegreesF() != 15
            || wwyTornadoDropSteps() != 3
            || wwyTornadoDropMinutes() != 30
            || wwyTornadoPathWidthQMi() != 1
            || wwyTornadoPathLengthMi() != 15
            || wwyTornadoTravelMph() != 40
            || wwyTornadoVortexMinMph() != 200
            || wwyTornadoVortexMaxMph() != 300
            || wwyXDisBands() != 7
            || wwyXSubNone() != 0
            || wwyXSubHail() != 1
            || wwyXSubIceSleet() != 2
            || wwyXSubLightning() != 3
            || wwyXSubSevereSnow() != 4
            || wwyXDisIceMinTempF() != 25
            || wwyXDisBand0HiF() != -1
            || wwyXDisBand1LoF() != 0
            || wwyXDisBand1HiF() != 9
            || wwyXDisBand2LoF() != 10
            || wwyXDisBand2HiF() != 29
            || wwyXDisBand3LoF() != 30
            || wwyXDisBand3HiF() != 35
            || wwyXDisBand4LoF() != 36
            || wwyXDisBand4HiF() != 49
            || wwyXDisBand5LoF() != 50
            || wwyXDisBand5HiF() != 74
            || wwyXDisBand6LoF() != 75
            || wwyHailLightningFirstMin() != 10
            || wwyHailStandaloneD6() != 1
            || wwyHailDieSides() != 6
            || wwyHailDiePlus() != 4
            || wwyHailMinMin() != 5
            || wwyHailMaxMin() != 10
            || wwyHailTypicalQtrIn() != 1
            || wwyHailMaxLoIn() != 2
            || wwyHailMaxHiIn() != 3
            || wwyHailMeltMinF() != 40
            || wwyIceCoatLoEighthIn() != 4
            || wwyIceCoatHiEighthIn() != 6
            || wwyIceFromHeavyMin() != 20
            || wwyIceTraceMaxHrs() != 2
            || wwyLightningDurationMin() != 25
            || wwyLightningRainLoEighthIn() != 6
            || wwyLightningRainHiIn() != 1
            || wwyLightningTwilightHrs() != 2
            || wwySevereSnowModDieSides() != 6
            || wwySevereSnowModDiePlus() != 4
            || wwySevereSnowModInLo() != 5
            || wwySevereSnowModInHi() != 10
            || wwySevereSnowHeavyDieSides() != 6
            || wwySevereSnowHeavyDiePlus() != 6
            || wwySevereSnowHeavyInLo() != 7
            || wwySevereSnowHeavyInHi() != 12
            || wwySevereSnowRateInPerHr() != 1
            || wwySevereSnowWindLoMph() != 15
            || wwySevereSnowWindHiMph() != 20
            || wwySevereSnowWindHrsLo() != 1
            || wwySevereSnowWindHrsHi() != 2
            || wwyA5Count() != 33
            || wwyHumLevelLow() != 1
            || wwyHumLevelMed() != 2
            || wwyHumLevelHigh() != 3
            || wwyHumDryMaxPct() != 20
            || wwyHumLowLoPct() != 21
            || wwyHumLowHiPct() != 40
            || wwyHumMedLoPct() != 41
            || wwyHumMedHiPct() != 70
            || wwyHumHiLoPct() != 71
            || wwyHumHiHiPct() != 90
            || wwyHumSatLoPct() != 91
            || wwyHumSatHiPct() != 100
            || wwyHumAdjRows() != 3
            || wwyA6Count() != 25
            || wwyEffTempApplyMinF() != 60
            || wwyA6Band1LoF() != 60
            || wwyA6Band1HiF() != 64
            || wwyA6Band2LoF() != 65
            || wwyA6Band2HiF() != 74
            || wwyA6Band3LoF() != 75
            || wwyA6Band3HiF() != 84
            || wwyA6Band4LoF() != 85
            || wwyA6Band4HiF() != 94
            || wwyA6Band5LoF() != 95
            || wwyWindCol0HiMph() != 10
            || wwyWindCol1LoMph() != 11
            || wwyWindCol1HiMph() != 20
            || wwyWindCol2LoMph() != 21
            || wwyWindCol2HiMph() != 30
            || wwyWindCol3LoMph() != 31
            || wwyWindCol3HiMph() != 45
            || wwyWindCol4LoMph() != 45
            || wwyA7Count() != 17
            || wwyChillMaxTempF() != 35
            || wwyChillMinTempF() != -45
            || wwyChillStepF() != 5
            || wwyChillWindCol0Mph() != 5
            || wwyChillWindColStepMph() != 5
            || wwyA8Count() != 15
            || wwyA8Months() != 12
            || wwyA8HalfHourUnits() != 2
            || wwyA8Lat0() != 90
            || wwyA8Lat3() != 65
            || wwyA8Lat6() != 50
            || wwyA8Lat9() != 30
            || wwyA8Lat12() != 15
            || wwyA8Lat14() != 0
            || wwyTwilightMidLatMin() != 30
            || wwyTwilightMidLatLoDeg() != 30
            || wwyTwilightMidLatHiDeg() != 40
            || wwyTwilightEquatorMin() != 20
            || wwyTwilightHighLatMin() != 40
            || wwyTwilightHighLatLoDeg() != 50
            || wwyTwilightHighLatHiDeg() != 60
            || wwyTwilightTerrainMinLo() != 5
            || wwyTwilightTerrainMinHi() != 10
            || wwySeaBreezeInlandMinMi() != 5
            || wwySeaBreezeInlandMaxMi() != 10
            || wwyTideHoursBetweenHighs() != 12
            || wwyTideLowAfterHighHrs() != 6
            || wwyLunarDayRoughHrs() != 25
            || wwyTideAdvanceMinPerDay() != 60
            || wwyTideCycleDays() != 28
            || wwySpringWindowDays() != 7
            || wwyNeapRangeFtLo() != 5
            || wwyNeapRangeFtHi() != 7
            || wwySpringRangeFtLo() != 15
            || wwySpringRangeFtHi() != 18
            || wwyFundyMaxFt() != 60
            || wwyGentleSlopeMaxDeg() != 30
            || wwyGentleEncroachLoX() != 4
            || wwyGentleEncroachHiX() != 5
            || wwyModerateSlopeLoDeg() != 31
            || wwyModerateSlopeHiDeg() != 50
            || wwyModerateEncroachLoX() != 2
            || wwyModerateEncroachHiX() != 3
            || wwySevereSlopeLoDeg() != 51
            || wwySevereSlopeHiDeg() != 70
            || wwySevereEncroachLoX() != 1
            || wwySevereEncroachHiX() != 2
            || wwyTideExampleGentleFt() != 15
            || wwyTideExampleGentleEncroachLoFt() != 60
            || wwyTideExampleGentleEncroachHiFt() != 75
            || wwyTideExampleModerateFt() != 5
            || wwyTideExampleModerateEncroachLoFt() != 10
            || wwyTideExampleModerateEncroachHiFt() != 15
            || !wwyRunningEpisodeNoSpecial()
            || !wwyNoSpecRoll2SharpDrop()
            || !wwyNoSpecRoll2PrecipB()
            || !wwyNoSpecRoll2WindSource50()
            || !wwyNoSpecRoll12SharpRise()
            || !wwyNoSpecRoll12PrecipB()
            || !wwyColdWaveFloorBelowMin()
            || !wwyColdWaveRecoveryAutoRise()
            || !wwyHeatWaveCeilingAboveMax()
            || !wwyHeatWaveRecoveryAutoFall()
            || !wwyCycloneSeacoastLightningDayBefore()
            || !wwyCycloneMovesAwayFromEquator()
            || !wwyCycloneFollowsCoast()
            || !wwyCycloneRainDoubleDownpour()
            || !wwyCycloneEyeSecondHalfRainstorm()
            || !wwyCycloneMaxOncePerMonth()
            || !wwyCycloneSecondBecomesExtreme()
            || !wwyCycloneNotNearEquator()
            || !wwyDroughtDay1NoPrecip()
            || !wwyDroughtLightToTrace()
            || !wwyDroughtHeavyLadder()
            || !wwyGaleNeverBelow30()
            || !wwyGalePrev20Boost()
            || !wwyGaleDesertSandstorm()
            || !wwyGaleSnowSevereSandstorm()
            || !wwyMistHeavyNearWater()
            || !wwyMistSuspendsPrecip()
            || !wwyMistAdjacent50()
            || !wwySandstormNeedsLooseMaterial()
            || !wwySandstormNoPrecipThatDay()
            || !wwyTornadoConditionsSuitable()
            || !wwyTornadoTempTwoStepsAbove()
            || !wwyTornadoRainStopsAbruptly()
            || !wwyTornadoCalmNearPath()
            || !wwyTornadoDropGreater()
            || !wwyTornadoCalmRestOfDay()
            || !wwyTornadoLowPressureExplosion()
            || !wwyExtremePrecipSubroll()
            || !wwyXDisIceNeeds25F()
            || !wwyLightningHalfAtTwilight()
            || !wwyLightningStandaloneDisregarded()
            || !wwyLightningAtDownpourStart()
            || !wwySevereSnowWindAfter()
            || !wwyHumFluctuatesOneLevel()
            || !wwyHumLowEdgeDry()
            || !wwyHumHighEdgeSaturated()
            || !wwyHumDMTwoLevelDrop()
            || !wwyChillExtrapBelow()
            || !wwyChillExtrapAbove40Mph()
            || !wwyA8SimplifiedRowsOnly()
            || !wwyA8MidnightNightMidpoint()
            || !wwyTwilightAllDayWhereNoDaylight()
            || !wwySeaBreezeDayWaterToLand()
            || !wwyLandBreezeNight()
            || !wwySeaBreezeStronger()
            || !wwyClearSkiesFavorBreezes()
            || !wwySeaBreezeCanChillCoast()
            || !wwyCliffFacesTrapSwirlCalm()
            || !wwyTidesTwiceDailyAlternating()
            || !wwySpringTidesAroundFullNew()
            || !wwyDMDetermine2to3Days()
            || !wwyDMSwitchTimeframesFreely()
            || !wwyDMPredetermineMultiDay()
        )
            ++bad;
        // the Roll 2 cross-index rows: Roll 1 = 2 and Roll 1 = 12
        int CR2[2][5] = {
            {1,2,2,0,0},
            {0,0,3,3,4},
            };
        for (int b = 0;
             b < wwyRoll2Rows();
             ++b) {
            int vals[5];
            vals[0] = wwtR2B24(b);
            vals[1] = wwtR2B56(b);
            vals[2] = wwtR2B7(b);
            vals[3] = wwtR2B89(b);
            vals[4] = wwtR2B1012(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CR2[b][c])
                    ++bad;
            }
        }
        // the Table A4 grid: 33 climate/terrain rows x the four seasonal
        // codes, each cell a packed four-letter code (arctic rows 0-4,
        // subarctic 5-11, temperate 12-18, subtropical 19-25, tropical 26-32;
        // desert, forest, hills, mountains, plains, seacoast, swamp within
        // each block)
        int CA4[33][4] = {
            {4133,4133,4133,4133},
            {4133,4135,4159,4135},
            {4133,4135,4159,4135},
            {4133,1435,8139,4139},
            {4133,1459,4159,4159},
            {4133,4133,1633,4133},
            {4139,1839,8193,1853},
            {4153,1439,1893,4153},
            {4135,1859,1893,4153},
            {4153,1839,9193,4139},
            {4159,4159,8195,1459},
            {1859,1859,8195,1859},
            {1639,4639,4639,6439},
            {1859,4859,4859,1859},
            {1859,1897,1839,1839},
            {1853,1859,1839,8139},
            {1439,1879,8439,8139},
            {1859,2859,2859,1859},
            {1859,4859,4859,1859},
            {1639,4639,4639,4639},
            {8159,8495,8895,1859},
            {1839,1837,8439,1895},
            {1839,1895,8493,8195},
            {1839,8479,8439,4139},
            {1839,2859,2859,1839},
            {1839,2859,2859,1839},
            {1639,4639,4639,4639},
            {8859,8895,8895,8859},
            {1439,4839,4839,4493},
            {1859,1859,8495,1459},
            {4839,4839,6893,4893},
            {8139,1859,2859,8195},
            {1859,4859,8459,8159},
            };
        for (int b = 0;
             b < wwyA4Count();
             ++b) {
            int vals[4];
            vals[0] = wwtA4Wi(b);
            vals[1] = wwtA4Sp(b);
            vals[2] = wwtA4Su(b);
            vals[3] = wwtA4Au(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CA4[b][c])
                    ++bad;
            }
        }
        // the X dispatch: 7 temperature bands x the 1-6 sub-rolls for the two
        // climatic columns (values 1 hail, 2 ice/sleet, 3 lightning, 4 severe
        // snowstorm, 0 none; the 10-29 band ice cell carries the 25-degree
        // footnote)
        int CXD[7][12] = {
            {0,0,0,0,0,0,4,4,4,0,0,0},
            {0,0,0,0,0,0,4,4,4,4,4,0},
            {0,0,0,0,0,0,4,4,4,4,4,2},
            {1,1,1,1,1,1,4,4,4,4,1,2},
            {3,3,3,3,3,1,3,3,3,3,1,1},
            {3,3,3,3,3,3,3,3,3,3,3,1},
            {3,3,3,3,3,3,3,3,3,3,3,3},
            };
        for (int b = 0;
             b < wwyXDisBands();
             ++b) {
            int vals[12];
            vals[0] = wwtXDisTr1(b);
            vals[1] = wwtXDisTr2(b);
            vals[2] = wwtXDisTr3(b);
            vals[3] = wwtXDisTr4(b);
            vals[4] = wwtXDisTr5(b);
            vals[5] = wwtXDisTr6(b);
            vals[6] = wwtXDisTa1(b);
            vals[7] = wwtXDisTa2(b);
            vals[8] = wwtXDisTa3(b);
            vals[9] = wwtXDisTa4(b);
            vals[10] = wwtXDisTa5(b);
            vals[11] = wwtXDisTa6(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CXD[b][c])
                    ++bad;
            }
        }
        // the Table A5 humidity grid: 33 climate/terrain rows x the four
        // seasonal levels (the arctic block uniformly low, printed order
        // Winter/Spring/Summer/Autumn)
        int CA5[33][4] = {
            {1,1,1,1},
            {1,1,1,1},
            {1,1,1,1},
            {1,1,1,1},
            {1,1,1,1},
            {1,1,1,1},
            {1,2,2,2},
            {1,1,1,1},
            {1,2,1,1},
            {1,2,2,1},
            {1,2,2,1},
            {1,2,2,1},
            {1,1,1,1},
            {2,3,2,2},
            {2,3,3,2},
            {1,2,1,2},
            {2,3,3,2},
            {3,2,2,3},
            {2,3,3,2},
            {1,1,1,1},
            {3,3,3,3},
            {2,3,3,3},
            {2,3,3,3},
            {2,3,2,1},
            {2,3,3,2},
            {2,3,3,2},
            {1,1,1,1},
            {3,3,3,3},
            {2,2,3,2},
            {2,3,3,3},
            {2,3,3,3},
            {2,3,3,2},
            {2,3,3,3},
            };
        for (int b = 0;
             b < wwyA5Count();
             ++b) {
            int vals[4];
            vals[0] = wwtA5Wi(b);
            vals[1] = wwtA5Sp(b);
            vals[2] = wwtA5Su(b);
            vals[3] = wwtA5Au(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CA5[b][c])
                    ++bad;
            }
        }
        // the day 1 / day 2 humidity adjustment, the BEFORE halves of the
        // printed slash pairs
        int CHB[3][3] = {
            {-1,0,1},
            {0,0,0},
            {0,0,1},
            };
        for (int b = 0;
             b < wwyHumAdjRows();
             ++b) {
            int vals[3];
            vals[0] = wwtHumAdjBefore0(b);
            vals[1] = wwtHumAdjBefore1(b);
            vals[2] = wwtHumAdjBefore2(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CHB[b][c])
                    ++bad;
            }
        }
        // the day 1 / day 2 humidity adjustment, the AFTER halves of the
        // printed slash pairs
        int CHA[3][3] = {
            {-1,0,1},
            {-1,0,1},
            {-1,-1,2},
            };
        for (int b = 0;
             b < wwyHumAdjRows();
             ++b) {
            int vals[3];
            vals[0] = wwtHumAdjAfter0(b);
            vals[1] = wwtHumAdjAfter1(b);
            vals[2] = wwtHumAdjAfter2(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CHA[b][c])
                    ++bad;
            }
        }
        // the Table A6 grid: rows are the 5 temperature bands x the 5
        // humidity levels in the order dry, low, medium, high, saturated; the
        // values are the degrees added to the actual temperature for
        // effective temperature
        int CA6[25][5] = {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {5,0,0,0,0},
            {10,5,0,0,0},
            {10,5,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {10,5,5,0,0},
            {0,0,0,0,0},
            {5,0,0,0,0},
            {5,5,0,0,0},
            {10,5,5,0,0},
            {15,10,5,0,0},
            {0,0,0,0,0},
            {5,5,0,0,0},
            {10,5,5,0,0},
            {15,10,5,5,0},
            {20,15,10,5,0},
            {0,0,0,0,0},
            {10,5,0,0,0},
            {15,10,5,5,0},
            {20,15,10,5,5},
            {25,20,15,10,5},
            };
        for (int b = 0;
             b < wwyA6Count();
             ++b) {
            int vals[5];
            vals[0] = wwtA6W0(b);
            vals[1] = wwtA6W1(b);
            vals[2] = wwtA6W2(b);
            vals[3] = wwtA6W3(b);
            vals[4] = wwtA6W4(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CA6[b][c])
                    ++bad;
            }
        }
        // the Table A7 wind chill grid: 17 temperature rows (35 down to -45
        // by 5) x 8 wind columns (5 to 40 by 5)
        int CA7[17][8] = {
            {35,20,15,10,5,5,0,0},
            {25,15,10,5,0,0,-5,-5},
            {20,10,0,-5,-5,-10,-15,-15},
            {15,0,-5,-10,-15,-20,-20,-25},
            {10,-5,-10,-15,-20,-25,-30,-30},
            {5,-10,-20,-25,-30,-35,-35,-40},
            {0,-15,-25,-30,-35,-40,-45,-45},
            {-5,-20,-35,-40,-45,-50,-50,-55},
            {-10,-25,-40,-45,-50,-55,-60,-65},
            {-15,-30,-45,-50,-60,-60,-65,-70},
            {-20,-40,-50,-60,-70,-75,-80,-80},
            {-25,-45,-60,-70,-75,-80,-85,-90},
            {-30,-50,-65,-75,-85,-90,-90,-95},
            {-35,-60,-70,-80,-90,-95,-100,-100},
            {-40,-65,-80,-90,-95,-100,-105,-110},
            {-45,-70,-85,-95,-105,-110,-115,-115},
            {-50,-75,-90,-100,-110,-115,-120,-120},
            };
        for (int b = 0;
             b < wwyA7Count();
             ++b) {
            int vals[8];
            vals[0] = wwtA7C0(b);
            vals[1] = wwtA7C1(b);
            vals[2] = wwtA7C2(b);
            vals[3] = wwtA7C3(b);
            vals[4] = wwtA7C4(b);
            vals[5] = wwtA7C5(b);
            vals[6] = wwtA7C6(b);
            vals[7] = wwtA7C7(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CA7[b][c])
                    ++bad;
            }
        }
        // the Table A8 daylight grid: 15 latitude rows (90/80/70 arctic,
        // 65/60/55 subarctic, 50/40/35 temperate, 30/25/20 subtropical,
        // 15/10/0 tropical) x 12 months, the hours of daylight stored in
        // half-hour units
        int CA8[15][12] = {
            {0,0,0,48,48,48,48,48,48,0,0,0},
            {0,0,22,48,48,48,48,48,31,10,0,0},
            {0,15,23,32,44,48,48,37,27,18,6,0},
            {6,17,23,30,39,43,40,34,27,19,10,6},
            {13,18,23,29,34,38,35,32,26,20,15,12},
            {15,19,23,28,32,35,33,30,26,21,17,14},
            {17,20,24,27,31,33,31,29,25,22,18,16},
            {19,21,24,26,29,30,29,28,25,22,20,19},
            {20,22,24,26,28,29,28,27,25,23,20,20},
            {21,22,24,26,27,28,28,26,25,23,21,20},
            {22,23,24,25,26,27,27,26,24,23,22,21},
            {22,23,24,25,26,27,26,26,24,23,22,22},
            {23,24,24,25,25,26,26,25,24,24,23,23},
            {23,24,24,25,25,26,26,25,24,24,23,23},
            {24,24,24,24,24,24,24,24,24,24,24,24},
            };
        for (int b = 0;
             b < wwyA8Count();
             ++b) {
            int vals[12];
            vals[0] = wwtA8M0(b);
            vals[1] = wwtA8M1(b);
            vals[2] = wwtA8M2(b);
            vals[3] = wwtA8M3(b);
            vals[4] = wwtA8M4(b);
            vals[5] = wwtA8M5(b);
            vals[6] = wwtA8M6(b);
            vals[7] = wwtA8M7(b);
            vals[8] = wwtA8M8(b);
            vals[9] = wwtA8M9(b);
            vals[10] = wwtA8M10(b);
            vals[11] = wwtA8M11(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CA8[b][c])
                    ++bad;
            }
        }
        // the wwyCycloneDriftFor band-for boundaries
    if (wwyCycloneDriftFor(5) != 0
            || wwyCycloneDriftFor(6) != 0
            || wwyCycloneDriftFor(7) != 1
            || wwyCycloneDriftFor(7) != 1
            || wwyCycloneDriftFor(8) != 2
        )
            ++bad;
        // the book worked example: if Roll 1 was a 2 and Roll 2 is a 6, the
        // SECOND letter of the cell code is indicated
    if (wwtR2B56(0) != 2
        )
            ++bad;
        // the book example: summer in a temperate forest - the cell code is
        // GXMZ (the 6th row of the temperate block)
    if (wwtA4Su(13) != 4859
        )
            ++bad;
        // the settle: the temperate seacoast spring and summer cells carry
        // the cyclone (three independent reads against the port uniform AXMZ)
    if (wwtA4Sp(17) != 2859
            || wwtA4Su(17) != 2859
        )
            ++bad;
        // the settle: the psm-6 swamp rows - subtropical swamp mirrors the
        // subtropical seacoast (AXDZ CXMZ CXMZ AXDZ)
    if (wwtA4Wi(25) != 1839
            || wwtA4Sp(25) != 2859
            || wwtA4Au(25) != 1839
        )
            ++bad;
        // the settle: the inferred tropical swamp winter cell (the A-N-z-D
        // glyph read decoded by the all-Z tropical winter fourth-letter
        // pattern)
    if (wwtA4Wi(32) != 1859
        )
            ++bad;
        // the arctic desert is uniform GADD across all four seasons
    if (wwtA4Wi(0) != 4133
            || wwtA4Sp(0) != 4133
            || wwtA4Su(0) != 4133
            || wwtA4Au(0) != 4133
        )
            ++bad;
        // the Roll 1 = 12 / Roll 2 = 7 example: the third letter
    if (wwtR2B7(1) != 3
        )
            ++bad;
        // the X dispatch at 75+ degrees in the tropics: lightning on any
        // sub-roll
    if (wwtXDisTr1(6) != 3
            || wwtXDisTr6(6) != 3
        )
            ++bad;
        // the X dispatch below zero in the temperate column: snow on 1-3,
        // none on 4-6
    if (wwtXDisTa1(0) != 4
            || wwtXDisTa4(0) != 0
        )
            ++bad;
        // the Table A6 peak: 95+ degrees, saturated air, calm air (0-10 mph)
        // - 25 degrees added to the actual temperature
    if (wwtA6W0(24) != 25
        )
            ++bad;
        // the wind chill anchors: 35 degrees at 5 mph is 35 effective; -45 at
        // 40 mph is -120
    if (wwtA7C0(0) != 35
            || wwtA7C7(16) != -120
        )
            ++bad;
        // the equator daylight: 12 hours (24 half-hours) every month of the
        // year
    if (wwtA8M0(14) != 24
            || wwtA8M3(14) != 24
            || wwtA8M6(14) != 24
            || wwtA8M11(14) != 24
        )
            ++bad;
        // the arctic pole: total darkness in month 1, total daylight in month
        // 6
    if (wwtA8M0(0) != 0
            || wwtA8M6(0) != 48
        )
            ++bad;
        // the temperate seacoast humidity: HMMH in every season
    if (wwtA5Wi(17) != 3
            || wwtA5Sp(17) != 2
            || wwtA5Su(17) != 2
            || wwtA5Au(17) != 3
        )
            ++bad;
        // the humidity adjustment peak: medium-or-more precipitation both
        // days raises the after-reading 2 steps
    if (wwtHumAdjAfter2(2) != 2
        )
            ++bad;
        // every A4 cell is a valid packed four-letter code
    if (wwtA4Wi(0) < 1111
            || wwtA4Wi(0) > 9999
            || wwtA4Wi(1) < 1111
            || wwtA4Wi(1) > 9999
            || wwtA4Wi(2) < 1111
            || wwtA4Wi(2) > 9999
            || wwtA4Wi(3) < 1111
            || wwtA4Wi(3) > 9999
            || wwtA4Wi(4) < 1111
            || wwtA4Wi(4) > 9999
            || wwtA4Wi(5) < 1111
            || wwtA4Wi(5) > 9999
            || wwtA4Wi(6) < 1111
            || wwtA4Wi(6) > 9999
            || wwtA4Wi(7) < 1111
            || wwtA4Wi(7) > 9999
            || wwtA4Wi(8) < 1111
            || wwtA4Wi(8) > 9999
            || wwtA4Wi(9) < 1111
            || wwtA4Wi(9) > 9999
            || wwtA4Wi(10) < 1111
            || wwtA4Wi(10) > 9999
            || wwtA4Wi(11) < 1111
            || wwtA4Wi(11) > 9999
            || wwtA4Wi(12) < 1111
            || wwtA4Wi(12) > 9999
            || wwtA4Wi(13) < 1111
            || wwtA4Wi(13) > 9999
            || wwtA4Wi(14) < 1111
            || wwtA4Wi(14) > 9999
            || wwtA4Wi(15) < 1111
            || wwtA4Wi(15) > 9999
            || wwtA4Wi(16) < 1111
            || wwtA4Wi(16) > 9999
            || wwtA4Wi(17) < 1111
            || wwtA4Wi(17) > 9999
            || wwtA4Wi(18) < 1111
            || wwtA4Wi(18) > 9999
            || wwtA4Wi(19) < 1111
            || wwtA4Wi(19) > 9999
            || wwtA4Wi(20) < 1111
            || wwtA4Wi(20) > 9999
            || wwtA4Wi(21) < 1111
            || wwtA4Wi(21) > 9999
            || wwtA4Wi(22) < 1111
            || wwtA4Wi(22) > 9999
            || wwtA4Wi(23) < 1111
            || wwtA4Wi(23) > 9999
            || wwtA4Wi(24) < 1111
            || wwtA4Wi(24) > 9999
            || wwtA4Wi(25) < 1111
            || wwtA4Wi(25) > 9999
            || wwtA4Wi(26) < 1111
            || wwtA4Wi(26) > 9999
            || wwtA4Wi(27) < 1111
            || wwtA4Wi(27) > 9999
            || wwtA4Wi(28) < 1111
            || wwtA4Wi(28) > 9999
            || wwtA4Wi(29) < 1111
            || wwtA4Wi(29) > 9999
            || wwtA4Wi(30) < 1111
            || wwtA4Wi(30) > 9999
            || wwtA4Wi(31) < 1111
            || wwtA4Wi(31) > 9999
            || wwtA4Wi(32) < 1111
            || wwtA4Wi(32) > 9999
            || wwtA4Sp(0) < 1111
            || wwtA4Sp(0) > 9999
            || wwtA4Sp(1) < 1111
            || wwtA4Sp(1) > 9999
            || wwtA4Sp(2) < 1111
            || wwtA4Sp(2) > 9999
            || wwtA4Sp(3) < 1111
            || wwtA4Sp(3) > 9999
            || wwtA4Sp(4) < 1111
            || wwtA4Sp(4) > 9999
            || wwtA4Sp(5) < 1111
            || wwtA4Sp(5) > 9999
            || wwtA4Sp(6) < 1111
            || wwtA4Sp(6) > 9999
            || wwtA4Sp(7) < 1111
            || wwtA4Sp(7) > 9999
            || wwtA4Sp(8) < 1111
            || wwtA4Sp(8) > 9999
            || wwtA4Sp(9) < 1111
            || wwtA4Sp(9) > 9999
            || wwtA4Sp(10) < 1111
            || wwtA4Sp(10) > 9999
            || wwtA4Sp(11) < 1111
            || wwtA4Sp(11) > 9999
            || wwtA4Sp(12) < 1111
            || wwtA4Sp(12) > 9999
            || wwtA4Sp(13) < 1111
            || wwtA4Sp(13) > 9999
            || wwtA4Sp(14) < 1111
            || wwtA4Sp(14) > 9999
            || wwtA4Sp(15) < 1111
            || wwtA4Sp(15) > 9999
            || wwtA4Sp(16) < 1111
            || wwtA4Sp(16) > 9999
            || wwtA4Sp(17) < 1111
            || wwtA4Sp(17) > 9999
            || wwtA4Sp(18) < 1111
            || wwtA4Sp(18) > 9999
            || wwtA4Sp(19) < 1111
            || wwtA4Sp(19) > 9999
            || wwtA4Sp(20) < 1111
            || wwtA4Sp(20) > 9999
            || wwtA4Sp(21) < 1111
            || wwtA4Sp(21) > 9999
            || wwtA4Sp(22) < 1111
            || wwtA4Sp(22) > 9999
            || wwtA4Sp(23) < 1111
            || wwtA4Sp(23) > 9999
            || wwtA4Sp(24) < 1111
            || wwtA4Sp(24) > 9999
            || wwtA4Sp(25) < 1111
            || wwtA4Sp(25) > 9999
            || wwtA4Sp(26) < 1111
            || wwtA4Sp(26) > 9999
            || wwtA4Sp(27) < 1111
            || wwtA4Sp(27) > 9999
            || wwtA4Sp(28) < 1111
            || wwtA4Sp(28) > 9999
            || wwtA4Sp(29) < 1111
            || wwtA4Sp(29) > 9999
            || wwtA4Sp(30) < 1111
            || wwtA4Sp(30) > 9999
            || wwtA4Sp(31) < 1111
            || wwtA4Sp(31) > 9999
            || wwtA4Sp(32) < 1111
            || wwtA4Sp(32) > 9999
            || wwtA4Su(0) < 1111
            || wwtA4Su(0) > 9999
            || wwtA4Su(1) < 1111
            || wwtA4Su(1) > 9999
            || wwtA4Su(2) < 1111
            || wwtA4Su(2) > 9999
            || wwtA4Su(3) < 1111
            || wwtA4Su(3) > 9999
            || wwtA4Su(4) < 1111
            || wwtA4Su(4) > 9999
            || wwtA4Su(5) < 1111
            || wwtA4Su(5) > 9999
            || wwtA4Su(6) < 1111
            || wwtA4Su(6) > 9999
            || wwtA4Su(7) < 1111
            || wwtA4Su(7) > 9999
            || wwtA4Su(8) < 1111
            || wwtA4Su(8) > 9999
            || wwtA4Su(9) < 1111
            || wwtA4Su(9) > 9999
            || wwtA4Su(10) < 1111
            || wwtA4Su(10) > 9999
            || wwtA4Su(11) < 1111
            || wwtA4Su(11) > 9999
            || wwtA4Su(12) < 1111
            || wwtA4Su(12) > 9999
            || wwtA4Su(13) < 1111
            || wwtA4Su(13) > 9999
            || wwtA4Su(14) < 1111
            || wwtA4Su(14) > 9999
            || wwtA4Su(15) < 1111
            || wwtA4Su(15) > 9999
            || wwtA4Su(16) < 1111
            || wwtA4Su(16) > 9999
            || wwtA4Su(17) < 1111
            || wwtA4Su(17) > 9999
            || wwtA4Su(18) < 1111
            || wwtA4Su(18) > 9999
            || wwtA4Su(19) < 1111
            || wwtA4Su(19) > 9999
            || wwtA4Su(20) < 1111
            || wwtA4Su(20) > 9999
            || wwtA4Su(21) < 1111
            || wwtA4Su(21) > 9999
            || wwtA4Su(22) < 1111
            || wwtA4Su(22) > 9999
            || wwtA4Su(23) < 1111
            || wwtA4Su(23) > 9999
            || wwtA4Su(24) < 1111
            || wwtA4Su(24) > 9999
            || wwtA4Su(25) < 1111
            || wwtA4Su(25) > 9999
            || wwtA4Su(26) < 1111
            || wwtA4Su(26) > 9999
            || wwtA4Su(27) < 1111
            || wwtA4Su(27) > 9999
            || wwtA4Su(28) < 1111
            || wwtA4Su(28) > 9999
            || wwtA4Su(29) < 1111
            || wwtA4Su(29) > 9999
            || wwtA4Su(30) < 1111
            || wwtA4Su(30) > 9999
            || wwtA4Su(31) < 1111
            || wwtA4Su(31) > 9999
            || wwtA4Su(32) < 1111
            || wwtA4Su(32) > 9999
            || wwtA4Au(0) < 1111
            || wwtA4Au(0) > 9999
            || wwtA4Au(1) < 1111
            || wwtA4Au(1) > 9999
            || wwtA4Au(2) < 1111
            || wwtA4Au(2) > 9999
            || wwtA4Au(3) < 1111
            || wwtA4Au(3) > 9999
            || wwtA4Au(4) < 1111
            || wwtA4Au(4) > 9999
            || wwtA4Au(5) < 1111
            || wwtA4Au(5) > 9999
            || wwtA4Au(6) < 1111
            || wwtA4Au(6) > 9999
            || wwtA4Au(7) < 1111
            || wwtA4Au(7) > 9999
            || wwtA4Au(8) < 1111
            || wwtA4Au(8) > 9999
            || wwtA4Au(9) < 1111
            || wwtA4Au(9) > 9999
            || wwtA4Au(10) < 1111
            || wwtA4Au(10) > 9999
            || wwtA4Au(11) < 1111
            || wwtA4Au(11) > 9999
            || wwtA4Au(12) < 1111
            || wwtA4Au(12) > 9999
            || wwtA4Au(13) < 1111
            || wwtA4Au(13) > 9999
            || wwtA4Au(14) < 1111
            || wwtA4Au(14) > 9999
            || wwtA4Au(15) < 1111
            || wwtA4Au(15) > 9999
            || wwtA4Au(16) < 1111
            || wwtA4Au(16) > 9999
            || wwtA4Au(17) < 1111
            || wwtA4Au(17) > 9999
            || wwtA4Au(18) < 1111
            || wwtA4Au(18) > 9999
            || wwtA4Au(19) < 1111
            || wwtA4Au(19) > 9999
            || wwtA4Au(20) < 1111
            || wwtA4Au(20) > 9999
            || wwtA4Au(21) < 1111
            || wwtA4Au(21) > 9999
            || wwtA4Au(22) < 1111
            || wwtA4Au(22) > 9999
            || wwtA4Au(23) < 1111
            || wwtA4Au(23) > 9999
            || wwtA4Au(24) < 1111
            || wwtA4Au(24) > 9999
            || wwtA4Au(25) < 1111
            || wwtA4Au(25) > 9999
            || wwtA4Au(26) < 1111
            || wwtA4Au(26) > 9999
            || wwtA4Au(27) < 1111
            || wwtA4Au(27) > 9999
            || wwtA4Au(28) < 1111
            || wwtA4Au(28) > 9999
            || wwtA4Au(29) < 1111
            || wwtA4Au(29) > 9999
            || wwtA4Au(30) < 1111
            || wwtA4Au(30) > 9999
            || wwtA4Au(31) < 1111
            || wwtA4Au(31) > 9999
            || wwtA4Au(32) < 1111
            || wwtA4Au(32) > 9999
        )
            ++bad;
        // every A5 humidity level is low, medium or high
    if ((wwtA5Wi(0) < 1
            || wwtA5Wi(0) > 3)
            || (wwtA5Wi(1) < 1
            || wwtA5Wi(1) > 3)
            || (wwtA5Wi(2) < 1
            || wwtA5Wi(2) > 3)
            || (wwtA5Wi(3) < 1
            || wwtA5Wi(3) > 3)
            || (wwtA5Wi(4) < 1
            || wwtA5Wi(4) > 3)
            || (wwtA5Wi(5) < 1
            || wwtA5Wi(5) > 3)
            || (wwtA5Wi(6) < 1
            || wwtA5Wi(6) > 3)
            || (wwtA5Wi(7) < 1
            || wwtA5Wi(7) > 3)
            || (wwtA5Wi(8) < 1
            || wwtA5Wi(8) > 3)
            || (wwtA5Wi(9) < 1
            || wwtA5Wi(9) > 3)
            || (wwtA5Wi(10) < 1
            || wwtA5Wi(10) > 3)
            || (wwtA5Wi(11) < 1
            || wwtA5Wi(11) > 3)
            || (wwtA5Wi(12) < 1
            || wwtA5Wi(12) > 3)
            || (wwtA5Wi(13) < 1
            || wwtA5Wi(13) > 3)
            || (wwtA5Wi(14) < 1
            || wwtA5Wi(14) > 3)
            || (wwtA5Wi(15) < 1
            || wwtA5Wi(15) > 3)
            || (wwtA5Wi(16) < 1
            || wwtA5Wi(16) > 3)
            || (wwtA5Wi(17) < 1
            || wwtA5Wi(17) > 3)
            || (wwtA5Wi(18) < 1
            || wwtA5Wi(18) > 3)
            || (wwtA5Wi(19) < 1
            || wwtA5Wi(19) > 3)
            || (wwtA5Wi(20) < 1
            || wwtA5Wi(20) > 3)
            || (wwtA5Wi(21) < 1
            || wwtA5Wi(21) > 3)
            || (wwtA5Wi(22) < 1
            || wwtA5Wi(22) > 3)
            || (wwtA5Wi(23) < 1
            || wwtA5Wi(23) > 3)
            || (wwtA5Wi(24) < 1
            || wwtA5Wi(24) > 3)
            || (wwtA5Wi(25) < 1
            || wwtA5Wi(25) > 3)
            || (wwtA5Wi(26) < 1
            || wwtA5Wi(26) > 3)
            || (wwtA5Wi(27) < 1
            || wwtA5Wi(27) > 3)
            || (wwtA5Wi(28) < 1
            || wwtA5Wi(28) > 3)
            || (wwtA5Wi(29) < 1
            || wwtA5Wi(29) > 3)
            || (wwtA5Wi(30) < 1
            || wwtA5Wi(30) > 3)
            || (wwtA5Wi(31) < 1
            || wwtA5Wi(31) > 3)
            || (wwtA5Wi(32) < 1
            || wwtA5Wi(32) > 3)
            || (wwtA5Sp(0) < 1
            || wwtA5Sp(0) > 3)
            || (wwtA5Sp(1) < 1
            || wwtA5Sp(1) > 3)
            || (wwtA5Sp(2) < 1
            || wwtA5Sp(2) > 3)
            || (wwtA5Sp(3) < 1
            || wwtA5Sp(3) > 3)
            || (wwtA5Sp(4) < 1
            || wwtA5Sp(4) > 3)
            || (wwtA5Sp(5) < 1
            || wwtA5Sp(5) > 3)
            || (wwtA5Sp(6) < 1
            || wwtA5Sp(6) > 3)
            || (wwtA5Sp(7) < 1
            || wwtA5Sp(7) > 3)
            || (wwtA5Sp(8) < 1
            || wwtA5Sp(8) > 3)
            || (wwtA5Sp(9) < 1
            || wwtA5Sp(9) > 3)
            || (wwtA5Sp(10) < 1
            || wwtA5Sp(10) > 3)
            || (wwtA5Sp(11) < 1
            || wwtA5Sp(11) > 3)
            || (wwtA5Sp(12) < 1
            || wwtA5Sp(12) > 3)
            || (wwtA5Sp(13) < 1
            || wwtA5Sp(13) > 3)
            || (wwtA5Sp(14) < 1
            || wwtA5Sp(14) > 3)
            || (wwtA5Sp(15) < 1
            || wwtA5Sp(15) > 3)
            || (wwtA5Sp(16) < 1
            || wwtA5Sp(16) > 3)
            || (wwtA5Sp(17) < 1
            || wwtA5Sp(17) > 3)
            || (wwtA5Sp(18) < 1
            || wwtA5Sp(18) > 3)
            || (wwtA5Sp(19) < 1
            || wwtA5Sp(19) > 3)
            || (wwtA5Sp(20) < 1
            || wwtA5Sp(20) > 3)
            || (wwtA5Sp(21) < 1
            || wwtA5Sp(21) > 3)
            || (wwtA5Sp(22) < 1
            || wwtA5Sp(22) > 3)
            || (wwtA5Sp(23) < 1
            || wwtA5Sp(23) > 3)
            || (wwtA5Sp(24) < 1
            || wwtA5Sp(24) > 3)
            || (wwtA5Sp(25) < 1
            || wwtA5Sp(25) > 3)
            || (wwtA5Sp(26) < 1
            || wwtA5Sp(26) > 3)
            || (wwtA5Sp(27) < 1
            || wwtA5Sp(27) > 3)
            || (wwtA5Sp(28) < 1
            || wwtA5Sp(28) > 3)
            || (wwtA5Sp(29) < 1
            || wwtA5Sp(29) > 3)
            || (wwtA5Sp(30) < 1
            || wwtA5Sp(30) > 3)
            || (wwtA5Sp(31) < 1
            || wwtA5Sp(31) > 3)
            || (wwtA5Sp(32) < 1
            || wwtA5Sp(32) > 3)
            || (wwtA5Su(0) < 1
            || wwtA5Su(0) > 3)
            || (wwtA5Su(1) < 1
            || wwtA5Su(1) > 3)
            || (wwtA5Su(2) < 1
            || wwtA5Su(2) > 3)
            || (wwtA5Su(3) < 1
            || wwtA5Su(3) > 3)
            || (wwtA5Su(4) < 1
            || wwtA5Su(4) > 3)
            || (wwtA5Su(5) < 1
            || wwtA5Su(5) > 3)
            || (wwtA5Su(6) < 1
            || wwtA5Su(6) > 3)
            || (wwtA5Su(7) < 1
            || wwtA5Su(7) > 3)
            || (wwtA5Su(8) < 1
            || wwtA5Su(8) > 3)
            || (wwtA5Su(9) < 1
            || wwtA5Su(9) > 3)
            || (wwtA5Su(10) < 1
            || wwtA5Su(10) > 3)
            || (wwtA5Su(11) < 1
            || wwtA5Su(11) > 3)
            || (wwtA5Su(12) < 1
            || wwtA5Su(12) > 3)
            || (wwtA5Su(13) < 1
            || wwtA5Su(13) > 3)
            || (wwtA5Su(14) < 1
            || wwtA5Su(14) > 3)
            || (wwtA5Su(15) < 1
            || wwtA5Su(15) > 3)
            || (wwtA5Su(16) < 1
            || wwtA5Su(16) > 3)
            || (wwtA5Su(17) < 1
            || wwtA5Su(17) > 3)
            || (wwtA5Su(18) < 1
            || wwtA5Su(18) > 3)
            || (wwtA5Su(19) < 1
            || wwtA5Su(19) > 3)
            || (wwtA5Su(20) < 1
            || wwtA5Su(20) > 3)
            || (wwtA5Su(21) < 1
            || wwtA5Su(21) > 3)
            || (wwtA5Su(22) < 1
            || wwtA5Su(22) > 3)
            || (wwtA5Su(23) < 1
            || wwtA5Su(23) > 3)
            || (wwtA5Su(24) < 1
            || wwtA5Su(24) > 3)
            || (wwtA5Su(25) < 1
            || wwtA5Su(25) > 3)
            || (wwtA5Su(26) < 1
            || wwtA5Su(26) > 3)
            || (wwtA5Su(27) < 1
            || wwtA5Su(27) > 3)
            || (wwtA5Su(28) < 1
            || wwtA5Su(28) > 3)
            || (wwtA5Su(29) < 1
            || wwtA5Su(29) > 3)
            || (wwtA5Su(30) < 1
            || wwtA5Su(30) > 3)
            || (wwtA5Su(31) < 1
            || wwtA5Su(31) > 3)
            || (wwtA5Su(32) < 1
            || wwtA5Su(32) > 3)
            || (wwtA5Au(0) < 1
            || wwtA5Au(0) > 3)
            || (wwtA5Au(1) < 1
            || wwtA5Au(1) > 3)
            || (wwtA5Au(2) < 1
            || wwtA5Au(2) > 3)
            || (wwtA5Au(3) < 1
            || wwtA5Au(3) > 3)
            || (wwtA5Au(4) < 1
            || wwtA5Au(4) > 3)
            || (wwtA5Au(5) < 1
            || wwtA5Au(5) > 3)
            || (wwtA5Au(6) < 1
            || wwtA5Au(6) > 3)
            || (wwtA5Au(7) < 1
            || wwtA5Au(7) > 3)
            || (wwtA5Au(8) < 1
            || wwtA5Au(8) > 3)
            || (wwtA5Au(9) < 1
            || wwtA5Au(9) > 3)
            || (wwtA5Au(10) < 1
            || wwtA5Au(10) > 3)
            || (wwtA5Au(11) < 1
            || wwtA5Au(11) > 3)
            || (wwtA5Au(12) < 1
            || wwtA5Au(12) > 3)
            || (wwtA5Au(13) < 1
            || wwtA5Au(13) > 3)
            || (wwtA5Au(14) < 1
            || wwtA5Au(14) > 3)
            || (wwtA5Au(15) < 1
            || wwtA5Au(15) > 3)
            || (wwtA5Au(16) < 1
            || wwtA5Au(16) > 3)
            || (wwtA5Au(17) < 1
            || wwtA5Au(17) > 3)
            || (wwtA5Au(18) < 1
            || wwtA5Au(18) > 3)
            || (wwtA5Au(19) < 1
            || wwtA5Au(19) > 3)
            || (wwtA5Au(20) < 1
            || wwtA5Au(20) > 3)
            || (wwtA5Au(21) < 1
            || wwtA5Au(21) > 3)
            || (wwtA5Au(22) < 1
            || wwtA5Au(22) > 3)
            || (wwtA5Au(23) < 1
            || wwtA5Au(23) > 3)
            || (wwtA5Au(24) < 1
            || wwtA5Au(24) > 3)
            || (wwtA5Au(25) < 1
            || wwtA5Au(25) > 3)
            || (wwtA5Au(26) < 1
            || wwtA5Au(26) > 3)
            || (wwtA5Au(27) < 1
            || wwtA5Au(27) > 3)
            || (wwtA5Au(28) < 1
            || wwtA5Au(28) > 3)
            || (wwtA5Au(29) < 1
            || wwtA5Au(29) > 3)
            || (wwtA5Au(30) < 1
            || wwtA5Au(30) > 3)
            || (wwtA5Au(31) < 1
            || wwtA5Au(31) > 3)
            || (wwtA5Au(32) < 1
            || wwtA5Au(32) > 3)
        )
            ++bad;
        // the arctic humidity block is uniformly low across all five terrains
        // and four seasons
    if (wwtA5Wi(0) != 1
            || wwtA5Wi(1) != 1
            || wwtA5Wi(2) != 1
            || wwtA5Wi(3) != 1
            || wwtA5Wi(4) != 1
            || wwtA5Sp(0) != 1
            || wwtA5Sp(1) != 1
            || wwtA5Sp(2) != 1
            || wwtA5Sp(3) != 1
            || wwtA5Sp(4) != 1
            || wwtA5Su(0) != 1
            || wwtA5Su(1) != 1
            || wwtA5Su(2) != 1
            || wwtA5Su(3) != 1
            || wwtA5Su(4) != 1
            || wwtA5Au(0) != 1
            || wwtA5Au(1) != 1
            || wwtA5Au(2) != 1
            || wwtA5Au(3) != 1
            || wwtA5Au(4) != 1
        )
            ++bad;
        // the wind chill never rises as the wind strengthens, in every
        // temperature row
    if (wwtA7C0(0) < wwtA7C1(0)
            || wwtA7C1(0) < wwtA7C2(0)
            || wwtA7C2(0) < wwtA7C3(0)
            || wwtA7C3(0) < wwtA7C4(0)
            || wwtA7C4(0) < wwtA7C5(0)
            || wwtA7C5(0) < wwtA7C6(0)
            || wwtA7C6(0) < wwtA7C7(0)
            || wwtA7C0(1) < wwtA7C1(1)
            || wwtA7C1(1) < wwtA7C2(1)
            || wwtA7C2(1) < wwtA7C3(1)
            || wwtA7C3(1) < wwtA7C4(1)
            || wwtA7C4(1) < wwtA7C5(1)
            || wwtA7C5(1) < wwtA7C6(1)
            || wwtA7C6(1) < wwtA7C7(1)
            || wwtA7C0(2) < wwtA7C1(2)
            || wwtA7C1(2) < wwtA7C2(2)
            || wwtA7C2(2) < wwtA7C3(2)
            || wwtA7C3(2) < wwtA7C4(2)
            || wwtA7C4(2) < wwtA7C5(2)
            || wwtA7C5(2) < wwtA7C6(2)
            || wwtA7C6(2) < wwtA7C7(2)
            || wwtA7C0(3) < wwtA7C1(3)
            || wwtA7C1(3) < wwtA7C2(3)
            || wwtA7C2(3) < wwtA7C3(3)
            || wwtA7C3(3) < wwtA7C4(3)
            || wwtA7C4(3) < wwtA7C5(3)
            || wwtA7C5(3) < wwtA7C6(3)
            || wwtA7C6(3) < wwtA7C7(3)
            || wwtA7C0(4) < wwtA7C1(4)
            || wwtA7C1(4) < wwtA7C2(4)
            || wwtA7C2(4) < wwtA7C3(4)
            || wwtA7C3(4) < wwtA7C4(4)
            || wwtA7C4(4) < wwtA7C5(4)
            || wwtA7C5(4) < wwtA7C6(4)
            || wwtA7C6(4) < wwtA7C7(4)
            || wwtA7C0(5) < wwtA7C1(5)
            || wwtA7C1(5) < wwtA7C2(5)
            || wwtA7C2(5) < wwtA7C3(5)
            || wwtA7C3(5) < wwtA7C4(5)
            || wwtA7C4(5) < wwtA7C5(5)
            || wwtA7C5(5) < wwtA7C6(5)
            || wwtA7C6(5) < wwtA7C7(5)
            || wwtA7C0(6) < wwtA7C1(6)
            || wwtA7C1(6) < wwtA7C2(6)
            || wwtA7C2(6) < wwtA7C3(6)
            || wwtA7C3(6) < wwtA7C4(6)
            || wwtA7C4(6) < wwtA7C5(6)
            || wwtA7C5(6) < wwtA7C6(6)
            || wwtA7C6(6) < wwtA7C7(6)
            || wwtA7C0(7) < wwtA7C1(7)
            || wwtA7C1(7) < wwtA7C2(7)
            || wwtA7C2(7) < wwtA7C3(7)
            || wwtA7C3(7) < wwtA7C4(7)
            || wwtA7C4(7) < wwtA7C5(7)
            || wwtA7C5(7) < wwtA7C6(7)
            || wwtA7C6(7) < wwtA7C7(7)
            || wwtA7C0(8) < wwtA7C1(8)
            || wwtA7C1(8) < wwtA7C2(8)
            || wwtA7C2(8) < wwtA7C3(8)
            || wwtA7C3(8) < wwtA7C4(8)
            || wwtA7C4(8) < wwtA7C5(8)
            || wwtA7C5(8) < wwtA7C6(8)
            || wwtA7C6(8) < wwtA7C7(8)
            || wwtA7C0(9) < wwtA7C1(9)
            || wwtA7C1(9) < wwtA7C2(9)
            || wwtA7C2(9) < wwtA7C3(9)
            || wwtA7C3(9) < wwtA7C4(9)
            || wwtA7C4(9) < wwtA7C5(9)
            || wwtA7C5(9) < wwtA7C6(9)
            || wwtA7C6(9) < wwtA7C7(9)
            || wwtA7C0(10) < wwtA7C1(10)
            || wwtA7C1(10) < wwtA7C2(10)
            || wwtA7C2(10) < wwtA7C3(10)
            || wwtA7C3(10) < wwtA7C4(10)
            || wwtA7C4(10) < wwtA7C5(10)
            || wwtA7C5(10) < wwtA7C6(10)
            || wwtA7C6(10) < wwtA7C7(10)
            || wwtA7C0(11) < wwtA7C1(11)
            || wwtA7C1(11) < wwtA7C2(11)
            || wwtA7C2(11) < wwtA7C3(11)
            || wwtA7C3(11) < wwtA7C4(11)
            || wwtA7C4(11) < wwtA7C5(11)
            || wwtA7C5(11) < wwtA7C6(11)
            || wwtA7C6(11) < wwtA7C7(11)
            || wwtA7C0(12) < wwtA7C1(12)
            || wwtA7C1(12) < wwtA7C2(12)
            || wwtA7C2(12) < wwtA7C3(12)
            || wwtA7C3(12) < wwtA7C4(12)
            || wwtA7C4(12) < wwtA7C5(12)
            || wwtA7C5(12) < wwtA7C6(12)
            || wwtA7C6(12) < wwtA7C7(12)
            || wwtA7C0(13) < wwtA7C1(13)
            || wwtA7C1(13) < wwtA7C2(13)
            || wwtA7C2(13) < wwtA7C3(13)
            || wwtA7C3(13) < wwtA7C4(13)
            || wwtA7C4(13) < wwtA7C5(13)
            || wwtA7C5(13) < wwtA7C6(13)
            || wwtA7C6(13) < wwtA7C7(13)
            || wwtA7C0(14) < wwtA7C1(14)
            || wwtA7C1(14) < wwtA7C2(14)
            || wwtA7C2(14) < wwtA7C3(14)
            || wwtA7C3(14) < wwtA7C4(14)
            || wwtA7C4(14) < wwtA7C5(14)
            || wwtA7C5(14) < wwtA7C6(14)
            || wwtA7C6(14) < wwtA7C7(14)
            || wwtA7C0(15) < wwtA7C1(15)
            || wwtA7C1(15) < wwtA7C2(15)
            || wwtA7C2(15) < wwtA7C3(15)
            || wwtA7C3(15) < wwtA7C4(15)
            || wwtA7C4(15) < wwtA7C5(15)
            || wwtA7C5(15) < wwtA7C6(15)
            || wwtA7C6(15) < wwtA7C7(15)
            || wwtA7C0(16) < wwtA7C1(16)
            || wwtA7C1(16) < wwtA7C2(16)
            || wwtA7C2(16) < wwtA7C3(16)
            || wwtA7C3(16) < wwtA7C4(16)
            || wwtA7C4(16) < wwtA7C5(16)
            || wwtA7C5(16) < wwtA7C6(16)
            || wwtA7C6(16) < wwtA7C7(16)
        )
            ++bad;
        // the wind chill never rises as the temperature drops, in every wind
        // column
    if (wwtA7C0(0) < wwtA7C0(1)
            || wwtA7C0(1) < wwtA7C0(2)
            || wwtA7C0(2) < wwtA7C0(3)
            || wwtA7C0(3) < wwtA7C0(4)
            || wwtA7C0(4) < wwtA7C0(5)
            || wwtA7C0(5) < wwtA7C0(6)
            || wwtA7C0(6) < wwtA7C0(7)
            || wwtA7C0(7) < wwtA7C0(8)
            || wwtA7C0(8) < wwtA7C0(9)
            || wwtA7C0(9) < wwtA7C0(10)
            || wwtA7C0(10) < wwtA7C0(11)
            || wwtA7C0(11) < wwtA7C0(12)
            || wwtA7C0(12) < wwtA7C0(13)
            || wwtA7C0(13) < wwtA7C0(14)
            || wwtA7C0(14) < wwtA7C0(15)
            || wwtA7C0(15) < wwtA7C0(16)
            || wwtA7C1(0) < wwtA7C1(1)
            || wwtA7C1(1) < wwtA7C1(2)
            || wwtA7C1(2) < wwtA7C1(3)
            || wwtA7C1(3) < wwtA7C1(4)
            || wwtA7C1(4) < wwtA7C1(5)
            || wwtA7C1(5) < wwtA7C1(6)
            || wwtA7C1(6) < wwtA7C1(7)
            || wwtA7C1(7) < wwtA7C1(8)
            || wwtA7C1(8) < wwtA7C1(9)
            || wwtA7C1(9) < wwtA7C1(10)
            || wwtA7C1(10) < wwtA7C1(11)
            || wwtA7C1(11) < wwtA7C1(12)
            || wwtA7C1(12) < wwtA7C1(13)
            || wwtA7C1(13) < wwtA7C1(14)
            || wwtA7C1(14) < wwtA7C1(15)
            || wwtA7C1(15) < wwtA7C1(16)
            || wwtA7C2(0) < wwtA7C2(1)
            || wwtA7C2(1) < wwtA7C2(2)
            || wwtA7C2(2) < wwtA7C2(3)
            || wwtA7C2(3) < wwtA7C2(4)
            || wwtA7C2(4) < wwtA7C2(5)
            || wwtA7C2(5) < wwtA7C2(6)
            || wwtA7C2(6) < wwtA7C2(7)
            || wwtA7C2(7) < wwtA7C2(8)
            || wwtA7C2(8) < wwtA7C2(9)
            || wwtA7C2(9) < wwtA7C2(10)
            || wwtA7C2(10) < wwtA7C2(11)
            || wwtA7C2(11) < wwtA7C2(12)
            || wwtA7C2(12) < wwtA7C2(13)
            || wwtA7C2(13) < wwtA7C2(14)
            || wwtA7C2(14) < wwtA7C2(15)
            || wwtA7C2(15) < wwtA7C2(16)
            || wwtA7C3(0) < wwtA7C3(1)
            || wwtA7C3(1) < wwtA7C3(2)
            || wwtA7C3(2) < wwtA7C3(3)
            || wwtA7C3(3) < wwtA7C3(4)
            || wwtA7C3(4) < wwtA7C3(5)
            || wwtA7C3(5) < wwtA7C3(6)
            || wwtA7C3(6) < wwtA7C3(7)
            || wwtA7C3(7) < wwtA7C3(8)
            || wwtA7C3(8) < wwtA7C3(9)
            || wwtA7C3(9) < wwtA7C3(10)
            || wwtA7C3(10) < wwtA7C3(11)
            || wwtA7C3(11) < wwtA7C3(12)
            || wwtA7C3(12) < wwtA7C3(13)
            || wwtA7C3(13) < wwtA7C3(14)
            || wwtA7C3(14) < wwtA7C3(15)
            || wwtA7C3(15) < wwtA7C3(16)
            || wwtA7C4(0) < wwtA7C4(1)
            || wwtA7C4(1) < wwtA7C4(2)
            || wwtA7C4(2) < wwtA7C4(3)
            || wwtA7C4(3) < wwtA7C4(4)
            || wwtA7C4(4) < wwtA7C4(5)
            || wwtA7C4(5) < wwtA7C4(6)
            || wwtA7C4(6) < wwtA7C4(7)
            || wwtA7C4(7) < wwtA7C4(8)
            || wwtA7C4(8) < wwtA7C4(9)
            || wwtA7C4(9) < wwtA7C4(10)
            || wwtA7C4(10) < wwtA7C4(11)
            || wwtA7C4(11) < wwtA7C4(12)
            || wwtA7C4(12) < wwtA7C4(13)
            || wwtA7C4(13) < wwtA7C4(14)
            || wwtA7C4(14) < wwtA7C4(15)
            || wwtA7C4(15) < wwtA7C4(16)
            || wwtA7C5(0) < wwtA7C5(1)
            || wwtA7C5(1) < wwtA7C5(2)
            || wwtA7C5(2) < wwtA7C5(3)
            || wwtA7C5(3) < wwtA7C5(4)
            || wwtA7C5(4) < wwtA7C5(5)
            || wwtA7C5(5) < wwtA7C5(6)
            || wwtA7C5(6) < wwtA7C5(7)
            || wwtA7C5(7) < wwtA7C5(8)
            || wwtA7C5(8) < wwtA7C5(9)
            || wwtA7C5(9) < wwtA7C5(10)
            || wwtA7C5(10) < wwtA7C5(11)
            || wwtA7C5(11) < wwtA7C5(12)
            || wwtA7C5(12) < wwtA7C5(13)
            || wwtA7C5(13) < wwtA7C5(14)
            || wwtA7C5(14) < wwtA7C5(15)
            || wwtA7C5(15) < wwtA7C5(16)
            || wwtA7C6(0) < wwtA7C6(1)
            || wwtA7C6(1) < wwtA7C6(2)
            || wwtA7C6(2) < wwtA7C6(3)
            || wwtA7C6(3) < wwtA7C6(4)
            || wwtA7C6(4) < wwtA7C6(5)
            || wwtA7C6(5) < wwtA7C6(6)
            || wwtA7C6(6) < wwtA7C6(7)
            || wwtA7C6(7) < wwtA7C6(8)
            || wwtA7C6(8) < wwtA7C6(9)
            || wwtA7C6(9) < wwtA7C6(10)
            || wwtA7C6(10) < wwtA7C6(11)
            || wwtA7C6(11) < wwtA7C6(12)
            || wwtA7C6(12) < wwtA7C6(13)
            || wwtA7C6(13) < wwtA7C6(14)
            || wwtA7C6(14) < wwtA7C6(15)
            || wwtA7C6(15) < wwtA7C6(16)
            || wwtA7C7(0) < wwtA7C7(1)
            || wwtA7C7(1) < wwtA7C7(2)
            || wwtA7C7(2) < wwtA7C7(3)
            || wwtA7C7(3) < wwtA7C7(4)
            || wwtA7C7(4) < wwtA7C7(5)
            || wwtA7C7(5) < wwtA7C7(6)
            || wwtA7C7(6) < wwtA7C7(7)
            || wwtA7C7(7) < wwtA7C7(8)
            || wwtA7C7(8) < wwtA7C7(9)
            || wwtA7C7(9) < wwtA7C7(10)
            || wwtA7C7(10) < wwtA7C7(11)
            || wwtA7C7(11) < wwtA7C7(12)
            || wwtA7C7(12) < wwtA7C7(13)
            || wwtA7C7(13) < wwtA7C7(14)
            || wwtA7C7(14) < wwtA7C7(15)
            || wwtA7C7(15) < wwtA7C7(16)
        )
            ++bad;
        // every A8 daylight value is a valid half-hour count (0 through 48)
    if ((wwtA8M0(0) < 0
            || wwtA8M0(0) > 48)
            || (wwtA8M0(1) < 0
            || wwtA8M0(1) > 48)
            || (wwtA8M0(2) < 0
            || wwtA8M0(2) > 48)
            || (wwtA8M0(3) < 0
            || wwtA8M0(3) > 48)
            || (wwtA8M0(4) < 0
            || wwtA8M0(4) > 48)
            || (wwtA8M0(5) < 0
            || wwtA8M0(5) > 48)
            || (wwtA8M0(6) < 0
            || wwtA8M0(6) > 48)
            || (wwtA8M0(7) < 0
            || wwtA8M0(7) > 48)
            || (wwtA8M0(8) < 0
            || wwtA8M0(8) > 48)
            || (wwtA8M0(9) < 0
            || wwtA8M0(9) > 48)
            || (wwtA8M0(10) < 0
            || wwtA8M0(10) > 48)
            || (wwtA8M0(11) < 0
            || wwtA8M0(11) > 48)
            || (wwtA8M0(12) < 0
            || wwtA8M0(12) > 48)
            || (wwtA8M0(13) < 0
            || wwtA8M0(13) > 48)
            || (wwtA8M0(14) < 0
            || wwtA8M0(14) > 48)
            || (wwtA8M1(0) < 0
            || wwtA8M1(0) > 48)
            || (wwtA8M1(1) < 0
            || wwtA8M1(1) > 48)
            || (wwtA8M1(2) < 0
            || wwtA8M1(2) > 48)
            || (wwtA8M1(3) < 0
            || wwtA8M1(3) > 48)
            || (wwtA8M1(4) < 0
            || wwtA8M1(4) > 48)
            || (wwtA8M1(5) < 0
            || wwtA8M1(5) > 48)
            || (wwtA8M1(6) < 0
            || wwtA8M1(6) > 48)
            || (wwtA8M1(7) < 0
            || wwtA8M1(7) > 48)
            || (wwtA8M1(8) < 0
            || wwtA8M1(8) > 48)
            || (wwtA8M1(9) < 0
            || wwtA8M1(9) > 48)
            || (wwtA8M1(10) < 0
            || wwtA8M1(10) > 48)
            || (wwtA8M1(11) < 0
            || wwtA8M1(11) > 48)
            || (wwtA8M1(12) < 0
            || wwtA8M1(12) > 48)
            || (wwtA8M1(13) < 0
            || wwtA8M1(13) > 48)
            || (wwtA8M1(14) < 0
            || wwtA8M1(14) > 48)
            || (wwtA8M2(0) < 0
            || wwtA8M2(0) > 48)
            || (wwtA8M2(1) < 0
            || wwtA8M2(1) > 48)
            || (wwtA8M2(2) < 0
            || wwtA8M2(2) > 48)
            || (wwtA8M2(3) < 0
            || wwtA8M2(3) > 48)
            || (wwtA8M2(4) < 0
            || wwtA8M2(4) > 48)
            || (wwtA8M2(5) < 0
            || wwtA8M2(5) > 48)
            || (wwtA8M2(6) < 0
            || wwtA8M2(6) > 48)
            || (wwtA8M2(7) < 0
            || wwtA8M2(7) > 48)
            || (wwtA8M2(8) < 0
            || wwtA8M2(8) > 48)
            || (wwtA8M2(9) < 0
            || wwtA8M2(9) > 48)
            || (wwtA8M2(10) < 0
            || wwtA8M2(10) > 48)
            || (wwtA8M2(11) < 0
            || wwtA8M2(11) > 48)
            || (wwtA8M2(12) < 0
            || wwtA8M2(12) > 48)
            || (wwtA8M2(13) < 0
            || wwtA8M2(13) > 48)
            || (wwtA8M2(14) < 0
            || wwtA8M2(14) > 48)
            || (wwtA8M3(0) < 0
            || wwtA8M3(0) > 48)
            || (wwtA8M3(1) < 0
            || wwtA8M3(1) > 48)
            || (wwtA8M3(2) < 0
            || wwtA8M3(2) > 48)
            || (wwtA8M3(3) < 0
            || wwtA8M3(3) > 48)
            || (wwtA8M3(4) < 0
            || wwtA8M3(4) > 48)
            || (wwtA8M3(5) < 0
            || wwtA8M3(5) > 48)
            || (wwtA8M3(6) < 0
            || wwtA8M3(6) > 48)
            || (wwtA8M3(7) < 0
            || wwtA8M3(7) > 48)
            || (wwtA8M3(8) < 0
            || wwtA8M3(8) > 48)
            || (wwtA8M3(9) < 0
            || wwtA8M3(9) > 48)
            || (wwtA8M3(10) < 0
            || wwtA8M3(10) > 48)
            || (wwtA8M3(11) < 0
            || wwtA8M3(11) > 48)
            || (wwtA8M3(12) < 0
            || wwtA8M3(12) > 48)
            || (wwtA8M3(13) < 0
            || wwtA8M3(13) > 48)
            || (wwtA8M3(14) < 0
            || wwtA8M3(14) > 48)
            || (wwtA8M4(0) < 0
            || wwtA8M4(0) > 48)
            || (wwtA8M4(1) < 0
            || wwtA8M4(1) > 48)
            || (wwtA8M4(2) < 0
            || wwtA8M4(2) > 48)
            || (wwtA8M4(3) < 0
            || wwtA8M4(3) > 48)
            || (wwtA8M4(4) < 0
            || wwtA8M4(4) > 48)
            || (wwtA8M4(5) < 0
            || wwtA8M4(5) > 48)
            || (wwtA8M4(6) < 0
            || wwtA8M4(6) > 48)
            || (wwtA8M4(7) < 0
            || wwtA8M4(7) > 48)
            || (wwtA8M4(8) < 0
            || wwtA8M4(8) > 48)
            || (wwtA8M4(9) < 0
            || wwtA8M4(9) > 48)
            || (wwtA8M4(10) < 0
            || wwtA8M4(10) > 48)
            || (wwtA8M4(11) < 0
            || wwtA8M4(11) > 48)
            || (wwtA8M4(12) < 0
            || wwtA8M4(12) > 48)
            || (wwtA8M4(13) < 0
            || wwtA8M4(13) > 48)
            || (wwtA8M4(14) < 0
            || wwtA8M4(14) > 48)
            || (wwtA8M5(0) < 0
            || wwtA8M5(0) > 48)
            || (wwtA8M5(1) < 0
            || wwtA8M5(1) > 48)
            || (wwtA8M5(2) < 0
            || wwtA8M5(2) > 48)
            || (wwtA8M5(3) < 0
            || wwtA8M5(3) > 48)
            || (wwtA8M5(4) < 0
            || wwtA8M5(4) > 48)
            || (wwtA8M5(5) < 0
            || wwtA8M5(5) > 48)
            || (wwtA8M5(6) < 0
            || wwtA8M5(6) > 48)
            || (wwtA8M5(7) < 0
            || wwtA8M5(7) > 48)
            || (wwtA8M5(8) < 0
            || wwtA8M5(8) > 48)
            || (wwtA8M5(9) < 0
            || wwtA8M5(9) > 48)
            || (wwtA8M5(10) < 0
            || wwtA8M5(10) > 48)
            || (wwtA8M5(11) < 0
            || wwtA8M5(11) > 48)
            || (wwtA8M5(12) < 0
            || wwtA8M5(12) > 48)
            || (wwtA8M5(13) < 0
            || wwtA8M5(13) > 48)
            || (wwtA8M5(14) < 0
            || wwtA8M5(14) > 48)
            || (wwtA8M6(0) < 0
            || wwtA8M6(0) > 48)
            || (wwtA8M6(1) < 0
            || wwtA8M6(1) > 48)
            || (wwtA8M6(2) < 0
            || wwtA8M6(2) > 48)
            || (wwtA8M6(3) < 0
            || wwtA8M6(3) > 48)
            || (wwtA8M6(4) < 0
            || wwtA8M6(4) > 48)
            || (wwtA8M6(5) < 0
            || wwtA8M6(5) > 48)
            || (wwtA8M6(6) < 0
            || wwtA8M6(6) > 48)
            || (wwtA8M6(7) < 0
            || wwtA8M6(7) > 48)
            || (wwtA8M6(8) < 0
            || wwtA8M6(8) > 48)
            || (wwtA8M6(9) < 0
            || wwtA8M6(9) > 48)
            || (wwtA8M6(10) < 0
            || wwtA8M6(10) > 48)
            || (wwtA8M6(11) < 0
            || wwtA8M6(11) > 48)
            || (wwtA8M6(12) < 0
            || wwtA8M6(12) > 48)
            || (wwtA8M6(13) < 0
            || wwtA8M6(13) > 48)
            || (wwtA8M6(14) < 0
            || wwtA8M6(14) > 48)
            || (wwtA8M7(0) < 0
            || wwtA8M7(0) > 48)
            || (wwtA8M7(1) < 0
            || wwtA8M7(1) > 48)
            || (wwtA8M7(2) < 0
            || wwtA8M7(2) > 48)
            || (wwtA8M7(3) < 0
            || wwtA8M7(3) > 48)
            || (wwtA8M7(4) < 0
            || wwtA8M7(4) > 48)
            || (wwtA8M7(5) < 0
            || wwtA8M7(5) > 48)
            || (wwtA8M7(6) < 0
            || wwtA8M7(6) > 48)
            || (wwtA8M7(7) < 0
            || wwtA8M7(7) > 48)
            || (wwtA8M7(8) < 0
            || wwtA8M7(8) > 48)
            || (wwtA8M7(9) < 0
            || wwtA8M7(9) > 48)
            || (wwtA8M7(10) < 0
            || wwtA8M7(10) > 48)
            || (wwtA8M7(11) < 0
            || wwtA8M7(11) > 48)
            || (wwtA8M7(12) < 0
            || wwtA8M7(12) > 48)
            || (wwtA8M7(13) < 0
            || wwtA8M7(13) > 48)
            || (wwtA8M7(14) < 0
            || wwtA8M7(14) > 48)
            || (wwtA8M8(0) < 0
            || wwtA8M8(0) > 48)
            || (wwtA8M8(1) < 0
            || wwtA8M8(1) > 48)
            || (wwtA8M8(2) < 0
            || wwtA8M8(2) > 48)
            || (wwtA8M8(3) < 0
            || wwtA8M8(3) > 48)
            || (wwtA8M8(4) < 0
            || wwtA8M8(4) > 48)
            || (wwtA8M8(5) < 0
            || wwtA8M8(5) > 48)
            || (wwtA8M8(6) < 0
            || wwtA8M8(6) > 48)
            || (wwtA8M8(7) < 0
            || wwtA8M8(7) > 48)
            || (wwtA8M8(8) < 0
            || wwtA8M8(8) > 48)
            || (wwtA8M8(9) < 0
            || wwtA8M8(9) > 48)
            || (wwtA8M8(10) < 0
            || wwtA8M8(10) > 48)
            || (wwtA8M8(11) < 0
            || wwtA8M8(11) > 48)
            || (wwtA8M8(12) < 0
            || wwtA8M8(12) > 48)
            || (wwtA8M8(13) < 0
            || wwtA8M8(13) > 48)
            || (wwtA8M8(14) < 0
            || wwtA8M8(14) > 48)
            || (wwtA8M9(0) < 0
            || wwtA8M9(0) > 48)
            || (wwtA8M9(1) < 0
            || wwtA8M9(1) > 48)
            || (wwtA8M9(2) < 0
            || wwtA8M9(2) > 48)
            || (wwtA8M9(3) < 0
            || wwtA8M9(3) > 48)
            || (wwtA8M9(4) < 0
            || wwtA8M9(4) > 48)
            || (wwtA8M9(5) < 0
            || wwtA8M9(5) > 48)
            || (wwtA8M9(6) < 0
            || wwtA8M9(6) > 48)
            || (wwtA8M9(7) < 0
            || wwtA8M9(7) > 48)
            || (wwtA8M9(8) < 0
            || wwtA8M9(8) > 48)
            || (wwtA8M9(9) < 0
            || wwtA8M9(9) > 48)
            || (wwtA8M9(10) < 0
            || wwtA8M9(10) > 48)
            || (wwtA8M9(11) < 0
            || wwtA8M9(11) > 48)
            || (wwtA8M9(12) < 0
            || wwtA8M9(12) > 48)
            || (wwtA8M9(13) < 0
            || wwtA8M9(13) > 48)
            || (wwtA8M9(14) < 0
            || wwtA8M9(14) > 48)
            || (wwtA8M10(0) < 0
            || wwtA8M10(0) > 48)
            || (wwtA8M10(1) < 0
            || wwtA8M10(1) > 48)
            || (wwtA8M10(2) < 0
            || wwtA8M10(2) > 48)
            || (wwtA8M10(3) < 0
            || wwtA8M10(3) > 48)
            || (wwtA8M10(4) < 0
            || wwtA8M10(4) > 48)
            || (wwtA8M10(5) < 0
            || wwtA8M10(5) > 48)
            || (wwtA8M10(6) < 0
            || wwtA8M10(6) > 48)
            || (wwtA8M10(7) < 0
            || wwtA8M10(7) > 48)
            || (wwtA8M10(8) < 0
            || wwtA8M10(8) > 48)
            || (wwtA8M10(9) < 0
            || wwtA8M10(9) > 48)
            || (wwtA8M10(10) < 0
            || wwtA8M10(10) > 48)
            || (wwtA8M10(11) < 0
            || wwtA8M10(11) > 48)
            || (wwtA8M10(12) < 0
            || wwtA8M10(12) > 48)
            || (wwtA8M10(13) < 0
            || wwtA8M10(13) > 48)
            || (wwtA8M10(14) < 0
            || wwtA8M10(14) > 48)
            || (wwtA8M11(0) < 0
            || wwtA8M11(0) > 48)
            || (wwtA8M11(1) < 0
            || wwtA8M11(1) > 48)
            || (wwtA8M11(2) < 0
            || wwtA8M11(2) > 48)
            || (wwtA8M11(3) < 0
            || wwtA8M11(3) > 48)
            || (wwtA8M11(4) < 0
            || wwtA8M11(4) > 48)
            || (wwtA8M11(5) < 0
            || wwtA8M11(5) > 48)
            || (wwtA8M11(6) < 0
            || wwtA8M11(6) > 48)
            || (wwtA8M11(7) < 0
            || wwtA8M11(7) > 48)
            || (wwtA8M11(8) < 0
            || wwtA8M11(8) > 48)
            || (wwtA8M11(9) < 0
            || wwtA8M11(9) > 48)
            || (wwtA8M11(10) < 0
            || wwtA8M11(10) > 48)
            || (wwtA8M11(11) < 0
            || wwtA8M11(11) > 48)
            || (wwtA8M11(12) < 0
            || wwtA8M11(12) > 48)
            || (wwtA8M11(13) < 0
            || wwtA8M11(13) > 48)
            || (wwtA8M11(14) < 0
            || wwtA8M11(14) > 48)
        )
            ++bad;
        // the month-6 daylight is at least the month-3 and month-12 daylight
        // in every latitude row (the seasonal peak)
    if (wwtA8M5(0) < wwtA8M2(0)
            || wwtA8M5(0) < wwtA8M11(0)
            || wwtA8M5(1) < wwtA8M2(1)
            || wwtA8M5(1) < wwtA8M11(1)
            || wwtA8M5(2) < wwtA8M2(2)
            || wwtA8M5(2) < wwtA8M11(2)
            || wwtA8M5(3) < wwtA8M2(3)
            || wwtA8M5(3) < wwtA8M11(3)
            || wwtA8M5(4) < wwtA8M2(4)
            || wwtA8M5(4) < wwtA8M11(4)
            || wwtA8M5(5) < wwtA8M2(5)
            || wwtA8M5(5) < wwtA8M11(5)
            || wwtA8M5(6) < wwtA8M2(6)
            || wwtA8M5(6) < wwtA8M11(6)
            || wwtA8M5(7) < wwtA8M2(7)
            || wwtA8M5(7) < wwtA8M11(7)
            || wwtA8M5(8) < wwtA8M2(8)
            || wwtA8M5(8) < wwtA8M11(8)
            || wwtA8M5(9) < wwtA8M2(9)
            || wwtA8M5(9) < wwtA8M11(9)
            || wwtA8M5(10) < wwtA8M2(10)
            || wwtA8M5(10) < wwtA8M11(10)
            || wwtA8M5(11) < wwtA8M2(11)
            || wwtA8M5(11) < wwtA8M11(11)
            || wwtA8M5(12) < wwtA8M2(12)
            || wwtA8M5(12) < wwtA8M11(12)
            || wwtA8M5(13) < wwtA8M2(13)
            || wwtA8M5(13) < wwtA8M11(13)
            || wwtA8M5(14) < wwtA8M2(14)
            || wwtA8M5(14) < wwtA8M11(14)
        )
            ++bad;
        // every A6 effective-temperature adjustment is 0 through 25 degrees
    if ((wwtA6W0(0) < 0
            || wwtA6W0(0) > 25)
            || (wwtA6W0(1) < 0
            || wwtA6W0(1) > 25)
            || (wwtA6W0(2) < 0
            || wwtA6W0(2) > 25)
            || (wwtA6W0(3) < 0
            || wwtA6W0(3) > 25)
            || (wwtA6W0(4) < 0
            || wwtA6W0(4) > 25)
            || (wwtA6W0(5) < 0
            || wwtA6W0(5) > 25)
            || (wwtA6W0(6) < 0
            || wwtA6W0(6) > 25)
            || (wwtA6W0(7) < 0
            || wwtA6W0(7) > 25)
            || (wwtA6W0(8) < 0
            || wwtA6W0(8) > 25)
            || (wwtA6W0(9) < 0
            || wwtA6W0(9) > 25)
            || (wwtA6W0(10) < 0
            || wwtA6W0(10) > 25)
            || (wwtA6W0(11) < 0
            || wwtA6W0(11) > 25)
            || (wwtA6W0(12) < 0
            || wwtA6W0(12) > 25)
            || (wwtA6W0(13) < 0
            || wwtA6W0(13) > 25)
            || (wwtA6W0(14) < 0
            || wwtA6W0(14) > 25)
            || (wwtA6W0(15) < 0
            || wwtA6W0(15) > 25)
            || (wwtA6W0(16) < 0
            || wwtA6W0(16) > 25)
            || (wwtA6W0(17) < 0
            || wwtA6W0(17) > 25)
            || (wwtA6W0(18) < 0
            || wwtA6W0(18) > 25)
            || (wwtA6W0(19) < 0
            || wwtA6W0(19) > 25)
            || (wwtA6W0(20) < 0
            || wwtA6W0(20) > 25)
            || (wwtA6W0(21) < 0
            || wwtA6W0(21) > 25)
            || (wwtA6W0(22) < 0
            || wwtA6W0(22) > 25)
            || (wwtA6W0(23) < 0
            || wwtA6W0(23) > 25)
            || (wwtA6W0(24) < 0
            || wwtA6W0(24) > 25)
            || (wwtA6W1(0) < 0
            || wwtA6W1(0) > 25)
            || (wwtA6W1(1) < 0
            || wwtA6W1(1) > 25)
            || (wwtA6W1(2) < 0
            || wwtA6W1(2) > 25)
            || (wwtA6W1(3) < 0
            || wwtA6W1(3) > 25)
            || (wwtA6W1(4) < 0
            || wwtA6W1(4) > 25)
            || (wwtA6W1(5) < 0
            || wwtA6W1(5) > 25)
            || (wwtA6W1(6) < 0
            || wwtA6W1(6) > 25)
            || (wwtA6W1(7) < 0
            || wwtA6W1(7) > 25)
            || (wwtA6W1(8) < 0
            || wwtA6W1(8) > 25)
            || (wwtA6W1(9) < 0
            || wwtA6W1(9) > 25)
            || (wwtA6W1(10) < 0
            || wwtA6W1(10) > 25)
            || (wwtA6W1(11) < 0
            || wwtA6W1(11) > 25)
            || (wwtA6W1(12) < 0
            || wwtA6W1(12) > 25)
            || (wwtA6W1(13) < 0
            || wwtA6W1(13) > 25)
            || (wwtA6W1(14) < 0
            || wwtA6W1(14) > 25)
            || (wwtA6W1(15) < 0
            || wwtA6W1(15) > 25)
            || (wwtA6W1(16) < 0
            || wwtA6W1(16) > 25)
            || (wwtA6W1(17) < 0
            || wwtA6W1(17) > 25)
            || (wwtA6W1(18) < 0
            || wwtA6W1(18) > 25)
            || (wwtA6W1(19) < 0
            || wwtA6W1(19) > 25)
            || (wwtA6W1(20) < 0
            || wwtA6W1(20) > 25)
            || (wwtA6W1(21) < 0
            || wwtA6W1(21) > 25)
            || (wwtA6W1(22) < 0
            || wwtA6W1(22) > 25)
            || (wwtA6W1(23) < 0
            || wwtA6W1(23) > 25)
            || (wwtA6W1(24) < 0
            || wwtA6W1(24) > 25)
            || (wwtA6W2(0) < 0
            || wwtA6W2(0) > 25)
            || (wwtA6W2(1) < 0
            || wwtA6W2(1) > 25)
            || (wwtA6W2(2) < 0
            || wwtA6W2(2) > 25)
            || (wwtA6W2(3) < 0
            || wwtA6W2(3) > 25)
            || (wwtA6W2(4) < 0
            || wwtA6W2(4) > 25)
            || (wwtA6W2(5) < 0
            || wwtA6W2(5) > 25)
            || (wwtA6W2(6) < 0
            || wwtA6W2(6) > 25)
            || (wwtA6W2(7) < 0
            || wwtA6W2(7) > 25)
            || (wwtA6W2(8) < 0
            || wwtA6W2(8) > 25)
            || (wwtA6W2(9) < 0
            || wwtA6W2(9) > 25)
            || (wwtA6W2(10) < 0
            || wwtA6W2(10) > 25)
            || (wwtA6W2(11) < 0
            || wwtA6W2(11) > 25)
            || (wwtA6W2(12) < 0
            || wwtA6W2(12) > 25)
            || (wwtA6W2(13) < 0
            || wwtA6W2(13) > 25)
            || (wwtA6W2(14) < 0
            || wwtA6W2(14) > 25)
            || (wwtA6W2(15) < 0
            || wwtA6W2(15) > 25)
            || (wwtA6W2(16) < 0
            || wwtA6W2(16) > 25)
            || (wwtA6W2(17) < 0
            || wwtA6W2(17) > 25)
            || (wwtA6W2(18) < 0
            || wwtA6W2(18) > 25)
            || (wwtA6W2(19) < 0
            || wwtA6W2(19) > 25)
            || (wwtA6W2(20) < 0
            || wwtA6W2(20) > 25)
            || (wwtA6W2(21) < 0
            || wwtA6W2(21) > 25)
            || (wwtA6W2(22) < 0
            || wwtA6W2(22) > 25)
            || (wwtA6W2(23) < 0
            || wwtA6W2(23) > 25)
            || (wwtA6W2(24) < 0
            || wwtA6W2(24) > 25)
            || (wwtA6W3(0) < 0
            || wwtA6W3(0) > 25)
            || (wwtA6W3(1) < 0
            || wwtA6W3(1) > 25)
            || (wwtA6W3(2) < 0
            || wwtA6W3(2) > 25)
            || (wwtA6W3(3) < 0
            || wwtA6W3(3) > 25)
            || (wwtA6W3(4) < 0
            || wwtA6W3(4) > 25)
            || (wwtA6W3(5) < 0
            || wwtA6W3(5) > 25)
            || (wwtA6W3(6) < 0
            || wwtA6W3(6) > 25)
            || (wwtA6W3(7) < 0
            || wwtA6W3(7) > 25)
            || (wwtA6W3(8) < 0
            || wwtA6W3(8) > 25)
            || (wwtA6W3(9) < 0
            || wwtA6W3(9) > 25)
            || (wwtA6W3(10) < 0
            || wwtA6W3(10) > 25)
            || (wwtA6W3(11) < 0
            || wwtA6W3(11) > 25)
            || (wwtA6W3(12) < 0
            || wwtA6W3(12) > 25)
            || (wwtA6W3(13) < 0
            || wwtA6W3(13) > 25)
            || (wwtA6W3(14) < 0
            || wwtA6W3(14) > 25)
            || (wwtA6W3(15) < 0
            || wwtA6W3(15) > 25)
            || (wwtA6W3(16) < 0
            || wwtA6W3(16) > 25)
            || (wwtA6W3(17) < 0
            || wwtA6W3(17) > 25)
            || (wwtA6W3(18) < 0
            || wwtA6W3(18) > 25)
            || (wwtA6W3(19) < 0
            || wwtA6W3(19) > 25)
            || (wwtA6W3(20) < 0
            || wwtA6W3(20) > 25)
            || (wwtA6W3(21) < 0
            || wwtA6W3(21) > 25)
            || (wwtA6W3(22) < 0
            || wwtA6W3(22) > 25)
            || (wwtA6W3(23) < 0
            || wwtA6W3(23) > 25)
            || (wwtA6W3(24) < 0
            || wwtA6W3(24) > 25)
            || (wwtA6W4(0) < 0
            || wwtA6W4(0) > 25)
            || (wwtA6W4(1) < 0
            || wwtA6W4(1) > 25)
            || (wwtA6W4(2) < 0
            || wwtA6W4(2) > 25)
            || (wwtA6W4(3) < 0
            || wwtA6W4(3) > 25)
            || (wwtA6W4(4) < 0
            || wwtA6W4(4) > 25)
            || (wwtA6W4(5) < 0
            || wwtA6W4(5) > 25)
            || (wwtA6W4(6) < 0
            || wwtA6W4(6) > 25)
            || (wwtA6W4(7) < 0
            || wwtA6W4(7) > 25)
            || (wwtA6W4(8) < 0
            || wwtA6W4(8) > 25)
            || (wwtA6W4(9) < 0
            || wwtA6W4(9) > 25)
            || (wwtA6W4(10) < 0
            || wwtA6W4(10) > 25)
            || (wwtA6W4(11) < 0
            || wwtA6W4(11) > 25)
            || (wwtA6W4(12) < 0
            || wwtA6W4(12) > 25)
            || (wwtA6W4(13) < 0
            || wwtA6W4(13) > 25)
            || (wwtA6W4(14) < 0
            || wwtA6W4(14) > 25)
            || (wwtA6W4(15) < 0
            || wwtA6W4(15) > 25)
            || (wwtA6W4(16) < 0
            || wwtA6W4(16) > 25)
            || (wwtA6W4(17) < 0
            || wwtA6W4(17) > 25)
            || (wwtA6W4(18) < 0
            || wwtA6W4(18) > 25)
            || (wwtA6W4(19) < 0
            || wwtA6W4(19) > 25)
            || (wwtA6W4(20) < 0
            || wwtA6W4(20) > 25)
            || (wwtA6W4(21) < 0
            || wwtA6W4(21) > 25)
            || (wwtA6W4(22) < 0
            || wwtA6W4(22) > 25)
            || (wwtA6W4(23) < 0
            || wwtA6W4(23) > 25)
            || (wwtA6W4(24) < 0
            || wwtA6W4(24) > 25)
        )
            ++bad;
        // the tropical dispatch column reads no precipitation in the three
        // bands below 30 degrees
    if (wwtXDisTr1(0) != 0
            || wwtXDisTr2(0) != 0
            || wwtXDisTr3(0) != 0
            || wwtXDisTr4(0) != 0
            || wwtXDisTr5(0) != 0
            || wwtXDisTr6(0) != 0
            || wwtXDisTr1(1) != 0
            || wwtXDisTr2(1) != 0
            || wwtXDisTr3(1) != 0
            || wwtXDisTr4(1) != 0
            || wwtXDisTr5(1) != 0
            || wwtXDisTr6(1) != 0
            || wwtXDisTr1(2) != 0
            || wwtXDisTr2(2) != 0
            || wwtXDisTr3(2) != 0
            || wwtXDisTr4(2) != 0
            || wwtXDisTr5(2) != 0
            || wwtXDisTr6(2) != 0
        )
            ++bad;
        // every Roll 2 index entry is a letter position 0-4 (0 = none)
    if ((wwtR2B24(0) < 0
            || wwtR2B24(0) > 4)
            || (wwtR2B24(1) < 0
            || wwtR2B24(1) > 4)
            || (wwtR2B56(0) < 0
            || wwtR2B56(0) > 4)
            || (wwtR2B56(1) < 0
            || wwtR2B56(1) > 4)
            || (wwtR2B7(0) < 0
            || wwtR2B7(0) > 4)
            || (wwtR2B7(1) < 0
            || wwtR2B7(1) > 4)
            || (wwtR2B89(0) < 0
            || wwtR2B89(0) > 4)
            || (wwtR2B89(1) < 0
            || wwtR2B89(1) > 4)
            || (wwtR2B1012(0) < 0
            || wwtR2B1012(0) > 4)
            || (wwtR2B1012(1) < 0
            || wwtR2B1012(1) > 4)
        )
            ++bad;
        // every humidity adjustment step is -1 through +2
    if ((wwtHumAdjBefore0(0) < -1
            || wwtHumAdjBefore0(0) > 2)
            || (wwtHumAdjBefore0(1) < -1
            || wwtHumAdjBefore0(1) > 2)
            || (wwtHumAdjBefore0(2) < -1
            || wwtHumAdjBefore0(2) > 2)
            || (wwtHumAdjBefore1(0) < -1
            || wwtHumAdjBefore1(0) > 2)
            || (wwtHumAdjBefore1(1) < -1
            || wwtHumAdjBefore1(1) > 2)
            || (wwtHumAdjBefore1(2) < -1
            || wwtHumAdjBefore1(2) > 2)
            || (wwtHumAdjBefore2(0) < -1
            || wwtHumAdjBefore2(0) > 2)
            || (wwtHumAdjBefore2(1) < -1
            || wwtHumAdjBefore2(1) > 2)
            || (wwtHumAdjBefore2(2) < -1
            || wwtHumAdjBefore2(2) > 2)
            || (wwtHumAdjAfter0(0) < -1
            || wwtHumAdjAfter0(0) > 2)
            || (wwtHumAdjAfter0(1) < -1
            || wwtHumAdjAfter0(1) > 2)
            || (wwtHumAdjAfter0(2) < -1
            || wwtHumAdjAfter0(2) > 2)
            || (wwtHumAdjAfter1(0) < -1
            || wwtHumAdjAfter1(0) > 2)
            || (wwtHumAdjAfter1(1) < -1
            || wwtHumAdjAfter1(1) > 2)
            || (wwtHumAdjAfter1(2) < -1
            || wwtHumAdjAfter1(2) > 2)
            || (wwtHumAdjAfter2(0) < -1
            || wwtHumAdjAfter2(0) > 2)
            || (wwtHumAdjAfter2(1) < -1
            || wwtHumAdjAfter2(1) > 2)
            || (wwtHumAdjAfter2(2) < -1
            || wwtHumAdjAfter2(2) > 2)
        )
            ++bad;
        printf("R494 WSG weather effects audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r495_wsg_compiled_tables.h"  // R830: migrated
    #include "rules/audits/r496_wsg_gap_reconciliation.h"  // R830: migrated
    #include "rules/audits/r497_wsg_overview.h"  // R830: migrated
    #include "rules/audits/r498_wsg_proficiencies_prose.h"  // R830: migrated
    #include "rules/audits/r499_wsg_temperature_fold.h"  // R830: migrated
    #include "rules/audits/r500_wsg_swimmer_motion_fold.h"  // R830: migrated
    #include "rules/audits/r501_wsg_movement_fall_fold.h"  // R830: migrated
    #include "rules/audits/r502_wsg_camp_chain_fold.h"  // R830: migrated
    #include "rules/audits/r503_dsg_overview.h"  // R830: migrated
    #include "rules/audits/r504_dsg_movement_i.h"  // R830: migrated
    #include "rules/audits/r505_dsg_movement_ii.h"  // R830: migrated
    #include "rules/audits/r506_dsg_proficiencies.h"  // R830: migrated
    #include "rules/audits/r507_dsg_combat.h"  // R830: migrated
    #include "rules/audits/r508_dsg_battlesystem.h"  // R830: migrated
    #include "rules/audits/r509_dsg_air_and_gases.h"  // R830: migrated
    #include "rules/audits/r510_dsg_odor_detection.h"  // R830: migrated
    #include "rules/audits/r511_dsg_cave_in_causes.h"  // R830: migrated
    #include "rules/audits/r512_dsg_chain_reaction.h"  // R830: migrated
    #include "rules/audits/r513_dsg_dpv_and_hypothermia.h"  // R830: migrated
    #include "rules/audits/r514_dsg_lodestone_and_npc_re.h"  // R830: migrated
    #include "rules/audits/r516_dsg_structural_decay.h"  // R830: migrated
    #include "rules/audits/r517_dsg_underground_waterway.h"  // R830: migrated
    #include "rules/audits/r518_dsg_water_travel.h"  // R830: migrated
    #include "rules/audits/r519_dsg_mining_prospecting.h"  // R830: migrated
    #include "rules/audits/r520_dsg_mining_excavation.h"  // R830: migrated
    #include "rules/audits/r521_dsg_mining_products.h"  // R830: migrated
    #include "rules/audits/r522_dsg_mine_product_quality.h"  // R830: migrated
    #include "rules/audits/r523_dsg_mining_tail.h"  // R830: migrated
    #include "rules/audits/r524_dsg_loyalty_hazards.h"  // R830: migrated
    #include "rules/audits/r525_dsg_equipment_costs.h"  // R830: migrated
    #include "rules/audits/r526_dsg_equipment_descriptio.h"  // R830: migrated
    #include "rules/audits/r527_dsg_proficiency_descript.h"  // R830: migrated
    #include "rules/audits/r528_dsg_improving_play_opene.h"  // R830: migrated
    #include "rules/audits/r529_dsg_improving_play_tail.h"  // R830: migrated
    #include "rules/audits/r530_dsg_underground_environm.h"  // R830: migrated
    #include "rules/audits/r531_dsg_geography_and_theori.h"  // R830: migrated
    #include "rules/audits/r532_dsg_cultures_of_the_unde.h"  // R830: migrated
    #include "rules/audits/r533_dsg_deepearth_opener.h"  // R830: migrated
    #include "rules/audits/r534_dsg_deepearth_areas_1_3.h"  // R830: migrated
    #include "rules/audits/r535_dsg_deepearth_areas_4_5.h"  // R830: migrated
    #include "rules/audits/r536_dsg_deepearth_areas_6_7.h"  // R830: migrated
    #include "rules/audits/r537_dsg_deepearth_areas_8_9.h"  // R830: migrated
    #include "rules/audits/r538_dsg_deepearth_areas_10_1.h"  // R830: migrated
    #include "rules/audits/r539_dsg_deepearth_areas_12_1.h"  // R830: migrated
    #include "rules/audits/r540_dsg_deepearth_areas_14_1.h"  // R830: migrated
    #include "rules/audits/r541_dsg_deepearth_areas_16_1.h"  // R830: migrated
    #include "rules/audits/r542_dsg_deepearth_areas_18_1.h"  // R830: migrated
    #include "rules/audits/r543_dsg_deepearth_areas_20_2.h"  // R830: migrated
    #include "rules/audits/r544_dsg_deepearth_areas_22_2.h"  // R830: migrated
    #include "rules/audits/r545_dsg_deepearth_areas_24_2.h"  // R830: migrated
    #include "rules/audits/r546_dsg_deepearth_areas_26_2.h"  // R830: migrated
    #include "rules/audits/r547_dsg_deepearth_areas_28_2.h"  // R830: migrated
    #include "rules/audits/r548_dsg_deepearth_areas_30_3.h"  // R830: migrated
    #include "rules/audits/r549_dsg_deepearth_closed.h"  // R830: migrated
    #include "rules/audits/r550_dsg_campaign_opener.h"  // R830: migrated
    #include "rules/audits/r551_dsg_worlds_of_adventure.h"  // R830: migrated
    #include "rules/audits/r552_dsg_plot_and_counterplot.h"  // R830: migrated
    #include "rules/audits/r553_dsg_story_elements_tail.h"  // R830: migrated
    #include "rules/audits/r554_dsg_story_design_techniq.h"  // R830: migrated
    #include "rules/audits/r555_dsg_help_from_the_player.h"  // R830: migrated
    #include "rules/audits/r556_dsg_campaign_closed.h"  // R830: migrated
    #include "rules/audits/r557_dsg_mapping_settings.h"  // R830: migrated
    #include "rules/audits/r558_dsg_compiled_tables.h"  // R830: migrated
    #include "rules/audits/r559_dsg_map_plates_closed.h"  // R830: migrated
    #include "rules/audits/r560_dsg_index.h"  // R830: migrated
    #include "rules/audits/r561_dsg_dm_section.h"  // R830: migrated
    #include "rules/audits/r562_dsg_intro_frame.h"  // R831: migrated
    #include "rules/audits/r563_dsg_final_census.h"  // R831: migrated
    #include "rules/audits/r564_motp_intro.h"  // R831: migrated
    #include "rules/audits/r565_motp_spell_summary.h"  // R831: migrated
    #include "rules/audits/r566_motp_ethereal.h"  // R831: migrated
    #include "rules/audits/r567_motp_inner_planes.h"  // R831: migrated
    #include "rules/audits/r568_motp_air_plane.h"  // R831: migrated
    #include "rules/audits/r569_motp_fire_plane.h"  // R831: migrated
    #include "rules/audits/r570_motp_earth_plane.h"  // R831: migrated
    #include "rules/audits/r571_motp_water_plane.h"  // R831: migrated
    #include "rules/audits/r572_motp_para_planes.h"  // R831: migrated
    #include "rules/audits/r573_motp_energy_planes.h"  // R831: migrated
    #include "rules/audits/r574_motp_positive_quasi_plan.h"  // R831: migrated
    #include "rules/audits/r575_motp_negative_quasi_plan.h"  // R831: migrated
    #include "rules/audits/r576_astral_plane.h"  // R831: migrated
    #include "rules/audits/r577_outer_planes_general.h"  // R831: migrated
    #include "rules/audits/r578_nirvana_arcadia.h"  // R831: migrated
    #include "rules/audits/r579_heavens_twins.h"  // R831: migrated
    #include "rules/audits/r580_elysium_beastlands.h"  // R831: migrated
    #include "rules/audits/r581_olympus_gladsheim.h"  // R831: migrated
    #include "rules/audits/r582_limbo_pandemonium.h"  // R831: migrated
    #include "rules/audits/r583_abyss.h"  // R831: migrated
    #include "rules/audits/r584_tarterus.h"  // R831: migrated
    #include "rules/audits/r585_hades.h"  // R831: migrated
    #include "rules/audits/r586_gehenna.h"  // R831: migrated
    #include "rules/audits/r587_nine_hells.h"  // R831: migrated
    #include "rules/audits/r588_acheron.h"  // R831: migrated
    #include "rules/audits/r589_opposition.h"  // R831: migrated
    #include "rules/audits/r590_beyond.h"  // R831: migrated
    #include "rules/audits/r591_outer_seal.h"  // R831: migrated
    #include "rules/audits/r592_primes.h"  // R831: migrated
    #include "rules/audits/r593_appii.h"  // R831: migrated
    #include "rules/audits/r594_appiii.h"  // R831: migrated
    #include "rules/audits/r595_appiv.h"  // R831: migrated
    #include "rules/audits/r596_indices.h"  // R831: migrated
    #include "rules/audits/r598_ether_cyclone.h"  // R831: migrated
    #include "rules/audits/r599_dmo_opener.h"  // R831: migrated
    #include "rules/audits/r600_dmo_maxims.h"  // R831: migrated
    #include "rules/audits/r601_dmo_adventures.h"  // R831: migrated
    #include "rules/audits/r602_dmo_world_ratings.h"  // R831: migrated
