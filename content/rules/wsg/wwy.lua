-- wwy: promoted from tools/spec_r494.json (the The WSG WORLD OF WEATHER, R494: the appendix part 2 - special weather, the effects on play and the optional rules, printed pp. 112-119 (pdf pages 113-120): Table A4 (the special weather grid) with the Roll 1 / Roll 2 cross-index, the per-code definitions from cold wave through heat wave, the extreme-precipitation dispatch, the humidity rules (Tables A5 and A6), wind chill (A7), the hours of daylight (A8), twilight, local winds, tides and the Dungeon Master responsibility. This closes the appendix: both the weather-effects child and the parent appendix box flip, and only the compiled tables (pp. 120-126) remain in the WSG arc.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 494,
  "prefix" = "wwy",
  "banner" = {
      "title" = "The WSG WORLD OF WEATHER, R494: the appendix part 2 - special weather, the effects on play and the optional rules, printed pp. 112-119 (pdf pages 113-120): Table A4 (the special weather grid) with the Roll 1 / Roll 2 cross-index, the per-code definitions from cold wave through heat wave, the extreme-precipitation dispatch, the humidity rules (Tables A5 and A6), wind chill (A7), the hours of daylight (A8), twilight, local winds, tides and the Dungeon Master responsibility. This closes the appendix: both the weather-effects child and the parent appendix box flip, and only the compiled tables (pp. 120-126) remain in the WSG arc.",
      "provenance" = "WSG printed pp. 112-119, pdf pages 113-120, extracted two-way at r493-extraction sha 5525680 (pdftotext layout + tesseract tsv, p0113-p0120) plus the psm-6 / psm-4 / psm-11 third reads of pdf page 113 at 52dd5fc; settled three-way with two external corroborators - the s0py python port (its season rotation verified via the A5 humidity cross-check) and the pdfy djvu read for the grid. Base ceaff98, census 418 -> 419.",
      "sentinel" = "THE SETTLE: Table A4 is the psm-6 read win - default tesseract, pdftotext and the djvu reads all garble the grid, and the 400-dpi psm-6 pass decodes it letter-for-letter with the TSV confidences checked per cell; the port agrees cell-for-cell on 28 of 33 rows and the djvu corroborates the arctic, temperate and subtropical interior blocks. Cyclone is confirmed on the coasts: the temperate seacoast spring/summer cells read CXMZ in three independent sources against the port uniform AXMZ, and the same coastal warm-season pattern carries the subtropical seacoast and swamp spring/summer cells and the tropical seacoast summer cell (flagged - that C is a low-confidence read). The swamp rows are psm-6 only (the port has no swamp biome and the djvu drops them), and the tropical swamp winter cell is the single inferred cell of the grid (the ANz D glyph read, decoded by the all-Z fourth-letter pattern of the tropical winter column). The A5 humidity grid rides the same 33-row model as A4 (the printed arctic-all-terrains line expanded to its five terrain rows); the transcription wins the two subarctic cells where the port rotation disagrees, the A3 precedent. A6 and A7 are transcription-port exact; A8 is 15 latitude rows (the earlier 16-row note was a miscount), cross-checked against the pdf layout read; the prose pages read clean throughout.",
    },
  "consts" = { {
      "name" = "wwyA4Roll1Two",
      "value" = 2,
      "comment" = "how to use the Special Weather Table: consider the earlier roll on the Day-to-Day Change Table (either a 2 or a 12) as Roll 1.",
    }, {
      "name" = "wwyA4Roll1Twelve",
      "value" = 12,
      "comment" = "the other Roll 1 trigger.",
    }, {
      "name" = "wwyRoll2Bands",
      "value" = 5,
      "comment" = "then roll 2d6 again, referring to the result as Roll 2, read across five bands: 2-4, 5-6, 7, 8-9, 10-12.",
    }, {
      "name" = "wwyRoll2Rows",
      "value" = 2,
      "comment" = "the Roll 2 index grid: one row for Roll 1 = 2 and one for Roll 1 = 12, five bands each.",
    }, {
      "name" = "wwyLetterPosNone",
      "value" = 0,
      "comment" = "the notations 1st, 2nd, 3rd, 4th refer to a single letter of the four-letter code; 0 marks that no letter is selected (no special weather possible from this position).",
    }, {
      "name" = "wwyLetterPos1st",
      "value" = 1,
      "comment" = "the first letter of the cell code.",
    }, {
      "name" = "wwyLetterPos2nd",
      "value" = 2,
      "comment" = "the second letter of the cell code.",
    }, {
      "name" = "wwyLetterPos3rd",
      "value" = 3,
      "comment" = "the third letter of the cell code.",
    }, {
      "name" = "wwyLetterPos4th",
      "value" = 4,
      "comment" = "the fourth letter of the cell code.",
    }, {
      "name" = "wwyA4Count",
      "value" = 33,
      "comment" = "the Table A4 grid: 5 climatic regions; the arctic block carries desert/hills/mountains/plains/seacoast (no forest, no swamp), every other climate all seven terrains - 33 rows x 4 seasons.",
    }, {
      "name" = "wwyA4PackBase",
      "value" = 10,
      "comment" = "each cell of the grid is a four-letter code packed one letter per decimal digit: A=1, C=2, D=3, G=4, M=5, S=6, T=7, X=8, Z=9; the k-th letter of the code is (code / 10 to the 4-k) mod 10.",
    }, {
      "name" = "wwyCodeColdWave",
      "value" = 1,
      "comment" = "the letter A: cold wave.",
    }, {
      "name" = "wwyCodeCyclone",
      "value" = 2,
      "comment" = "the letter C: cyclone, hurricane or typhoon.",
    }, {
      "name" = "wwyCodeDrought",
      "value" = 3,
      "comment" = "the letter D: drought.",
    }, {
      "name" = "wwyCodeGale",
      "value" = 4,
      "comment" = "the letter G: gale.",
    }, {
      "name" = "wwyCodeMistFog",
      "value" = 5,
      "comment" = "the letter M: mist or fog.",
    }, {
      "name" = "wwyCodeSandstorm",
      "value" = 6,
      "comment" = "the letter S: sandstorm, dust storm or blowing snow.",
    }, {
      "name" = "wwyCodeTornado",
      "value" = 7,
      "comment" = "the letter T: tornado.",
    }, {
      "name" = "wwyCodeExtremePrecip",
      "value" = 8,
      "comment" = "the letter X: extreme precipitation.",
    }, {
      "name" = "wwyCodeHeatWave",
      "value" = 9,
      "comment" = "the letter Z: heat wave.",
    }, {
      "name" = "wwyNoSpecRoll2WindMph",
      "value" = 45,
      "comment" = "a roll of 2 when no special weather occurs: a very strong wind, 45 mph.",
    }, {
      "name" = "wwyNoSpecRoll12WindMph",
      "value" = 5,
      "comment" = "a roll of 12 when no special weather occurs: a very slight wind, 5 mph.",
    }, {
      "name" = "wwyColdWaveDice",
      "value" = 2,
      "comment" = "a cold wave lasts 2d6+2 days.",
    }, {
      "name" = "wwyColdWaveDiePlus",
      "value" = 2,
      "comment" = "the +2 on the 2d6 duration roll.",
    }, {
      "name" = "wwyColdWaveStepsPerDay",
      "value" = 4,
      "comment" = "through the wave the temperature drops 4 letter-scale steps per day.",
    }, {
      "name" = "wwyColdWaveAMinDropF",
      "value" = 10,
      "comment" = "if the A-minimum temperature is reached, the temperature continues to drop to as much as 10 degrees below the normal minimum.",
    }, {
      "name" = "wwyColdWaveAMinDays",
      "value" = 3,
      "comment" = "the below-normal-minimum extreme can persist for a maximum of 3 days.",
    }, {
      "name" = "wwyColdWaveRecoveryRollLo",
      "value" = 7,
      "comment" = "when the wave ends the temperature automatically rises to the normal minimum; a roll of 7 or higher on 2d6 raises it 1-3 steps more, any lower roll just reaches the minimum.",
    }, {
      "name" = "wwyHeatWaveDice",
      "value" = 2,
      "comment" = "a heat wave is the mirror of a cold wave and lasts 2d6+2 days.",
    }, {
      "name" = "wwyHeatWaveDiePlus",
      "value" = 2,
      "comment" = "the +2 on the 2d6 duration roll.",
    }, {
      "name" = "wwyHeatWaveStepsPerDay",
      "value" = 4,
      "comment" = "through the wave the temperature rises 4 letter-scale steps per day.",
    }, {
      "name" = "wwyHeatWaveZMaxRiseF",
      "value" = 10,
      "comment" = "if the Z-maximum temperature is reached, the temperature continues to rise to as much as 10 degrees above the normal maximum.",
    }, {
      "name" = "wwyHeatWaveZMaxDays",
      "value" = 3,
      "comment" = "the above-normal-maximum extreme can persist for a maximum of 3 days.",
    }, {
      "name" = "wwyHeatWaveRecoveryRollLo",
      "value" = 7,
      "comment" = "when the wave ends the temperature automatically falls to the normal maximum; a roll of 7 or higher on 2d6 falls 1-3 steps more, any lower roll just reaches the maximum.",
    }, {
      "name" = "wwyCycloneWindDice",
      "value" = 1,
      "comment" = "the cyclone wind velocity: 1d6 x 20 + 60 mph.",
    }, {
      "name" = "wwyCycloneWindMult",
      "value" = 20,
      "comment" = "the per-die 20 mph.",
    }, {
      "name" = "wwyCycloneWindBase",
      "value" = 60,
      "comment" = "the +60 mph base.",
    }, {
      "name" = "wwyCycloneWindMinMph",
      "value" = 80,
      "comment" = "the cyclone wind floor: 80 mph.",
    }, {
      "name" = "wwyCycloneWindMaxMph",
      "value" = 180,
      "comment" = "the cyclone wind ceiling: 180 mph.",
    }, {
      "name" = "wwyCycloneInlandMaxMi",
      "value" = 10,
      "comment" = "a cyclone affects an area at most 10 miles inland; further inland only the perimeter conditions apply.",
    }, {
      "name" = "wwyCyclonePerimeterMi",
      "value" = 50,
      "comment" = "the gale-and-heavy-rain perimeter around the storm center extends about 50 miles.",
    }, {
      "name" = "wwyCycloneFollowsCoastDaysLo",
      "value" = 1,
      "comment" = "a cyclone at sea follows the coastline for 1-2 days before heading back out to sea.",
    }, {
      "name" = "wwyCycloneFollowsCoastDaysHi",
      "value" = 2,
      "comment" = "the high bound of the follow.",
    }, {
      "name" = "wwyCycloneTidalWaveMi",
      "value" = 3,
      "comment" = "where a cyclone strikes the coast it can generate a tidal wave (a wall of water 30-100 feet high) that encroaches up to 3 miles inland.",
    }, {
      "name" = "wwyCycloneEyeHours",
      "value" = 6,
      "comment" = "the eye of the cyclone lasts about 6 hours.",
    }, {
      "name" = "wwyCycloneEyeCalmMinLo",
      "value" = 30,
      "comment" = "the first half hour to hour of the eye is virtually rainless and windless (dead calm).",
    }, {
      "name" = "wwyCycloneEyeCalmMinHi",
      "value" = 60,
      "comment" = "the high bound of the dead-calm window.",
    }, {
      "name" = "wwyCycloneEyeWindMaxMph",
      "value" = 10,
      "comment" = "winds through the eye stay at 10 mph or below.",
    }, {
      "name" = "wwyCycloneNoChangeDays",
      "value" = 3,
      "comment" = "for 3 days after a cyclone the Day-to-Day Change Table is not used; the weather is dominated by the storm system.",
    }, {
      "name" = "wwyCycloneRadiusMi",
      "value" = 200,
      "comment" = "the frequency cap radius: an area within 200 miles of a cyclone path can be struck by at most one cyclone per month.",
    }, {
      "name" = "wwyCycloneEquatorExclDeg",
      "value" = 5,
      "comment" = "cyclones do not occur within 5 degrees of the equator.",
    }, {
      "name" = "wwyDroughtDice",
      "value" = 2,
      "comment" = "a drought lasts 2d6+2 days.",
    }, {
      "name" = "wwyDroughtDiePlus",
      "value" = 2,
      "comment" = "the +2 on the 2d6 duration roll.",
    }, {
      "name" = "wwyDroughtTraceGapDays",
      "value" = 5,
      "comment" = "through a drought at most a trace of precipitation can fall, and at most once every 5 days.",
    }, {
      "name" = "wwyGaleDieSides",
      "value" = 6,
      "comment" = "the gale wind velocity: 1d6 x 5 + 40 mph.",
    }, {
      "name" = "wwyGaleMultMph",
      "value" = 5,
      "comment" = "the per-die 5 mph.",
    }, {
      "name" = "wwyGaleBaseMph",
      "value" = 40,
      "comment" = "the +40 mph base.",
    }, {
      "name" = "wwyGaleMinMph",
      "value" = 45,
      "comment" = "the gale wind floor: 45 mph.",
    }, {
      "name" = "wwyGaleMaxMph",
      "value" = 70,
      "comment" = "the gale wind ceiling: 70 mph.",
    }, {
      "name" = "wwyGaleDurDiePlus",
      "value" = 1,
      "comment" = "a gale lasts 1d6+1 hours.",
    }, {
      "name" = "wwyGaleDurMinHrs",
      "value" = 2,
      "comment" = "the gale duration floor: 2 hours.",
    }, {
      "name" = "wwyGaleDurMaxHrs",
      "value" = 7,
      "comment" = "the gale duration ceiling: 7 hours.",
    }, {
      "name" = "wwyMistSunriseRollMax",
      "value" = 4,
      "comment" = "mist or fog forms at sunrise on a roll of 1-4 on 1d6, at sunset on a roll of 5-6.",
    }, {
      "name" = "wwyMistHoursDie",
      "value" = 6,
      "comment" = "the mist or fog lasts 1d6 hours.",
    }, {
      "name" = "wwySandstormDieSides",
      "value" = 4,
      "comment" = "a normal sandstorm lasts 1d4+1 hours.",
    }, {
      "name" = "wwySandstormDiePlus",
      "value" = 1,
      "comment" = "the +1 on the 1d4 duration roll.",
    }, {
      "name" = "wwySandstormMinHrs",
      "value" = 2,
      "comment" = "the normal sandstorm duration floor: 2 hours.",
    }, {
      "name" = "wwySandstormMaxHrs",
      "value" = 5,
      "comment" = "the normal sandstorm duration ceiling: 5 hours.",
    }, {
      "name" = "wwySandstormSevDieSides",
      "value" = 6,
      "comment" = "a severe sandstorm (gale-driven) lasts 1d6+1 hours.",
    }, {
      "name" = "wwySandstormSevDiePlus",
      "value" = 1,
      "comment" = "the +1 on the 1d6 duration roll.",
    }, {
      "name" = "wwySandstormSevMinHrs",
      "value" = 2,
      "comment" = "the severe sandstorm duration floor: 2 hours.",
    }, {
      "name" = "wwySandstormSevMaxHrs",
      "value" = 7,
      "comment" = "the severe sandstorm duration ceiling: 7 hours.",
    }, {
      "name" = "wwyTornadoPrecipDieSides",
      "value" = 3,
      "comment" = "the tornado is preceded by 1d3 hours of strong wind and heavy precipitation.",
    }, {
      "name" = "wwyTornadoCalmDice",
      "value" = 3,
      "comment" = "after the rain stops, 3d6 minutes pass before the tornado arrives.",
    }, {
      "name" = "wwyTornadoCalmDieSides",
      "value" = 6,
      "comment" = "the d6 of the 3d6 calm delay.",
    }, {
      "name" = "wwyTornadoDropDegreesF",
      "value" = 15,
      "comment" = "during the tornado the temperature drops 15 degrees Fahrenheit or 3 letter-scale steps, whichever is the greater.",
    }, {
      "name" = "wwyTornadoDropSteps",
      "value" = 3,
      "comment" = "the step-alternative of the temperature drop (the greater of the two applies).",
    }, {
      "name" = "wwyTornadoDropMinutes",
      "value" = 30,
      "comment" = "the temperature drop takes place over 30 minutes and holds for the following half hour.",
    }, {
      "name" = "wwyTornadoPathWidthQMi",
      "value" = 1,
      "comment" = "the tornado path averages one-quarter mile in width.",
    }, {
      "name" = "wwyTornadoPathLengthMi",
      "value" = 15,
      "comment" = "the tornado path averages 15 miles long.",
    }, {
      "name" = "wwyTornadoTravelMph",
      "value" = 40,
      "comment" = "the tornado travels along its path at about 40 mph.",
    }, {
      "name" = "wwyTornadoVortexMinMph",
      "value" = 200,
      "comment" = "the winds inside the vortex are 200-300 mph.",
    }, {
      "name" = "wwyTornadoVortexMaxMph",
      "value" = 300,
      "comment" = "the vortex wind ceiling.",
    }, {
      "name" = "wwyXDisBands",
      "value" = 7,
      "comment" = "the extreme-precipitation dispatch: 7 temperature bands x 2 climatic columns x the 1d6 sub-roll.",
    }, {
      "name" = "wwyXSubNone",
      "value" = 0,
      "comment" = "a dispatch result of none: no precipitation beyond the ordinary.",
    }, {
      "name" = "wwyXSubHail",
      "value" = 1,
      "comment" = "the dispatch letter H: hailstorm.",
    }, {
      "name" = "wwyXSubIceSleet",
      "value" = 2,
      "comment" = "the dispatch letter I: ice storm or sleet.",
    }, {
      "name" = "wwyXSubLightning",
      "value" = 3,
      "comment" = "the dispatch letter L: lightning storm.",
    }, {
      "name" = "wwyXSubSevereSnow",
      "value" = 4,
      "comment" = "the dispatch letter S: severe snowstorm.",
    }, {
      "name" = "wwyXDisIceMinTempF",
      "value" = 25,
      "comment" = "in the 10-29 degree band, ice or sleet results only if the temperature is 25 degrees or higher; below that the sub-roll indicates no precipitation.",
    }, {
      "name" = "wwyXDisBand0HiF",
      "value" = -1,
      "comment" = "the dispatch temperature band 0: -1 degree or lower.",
    }, {
      "name" = "wwyXDisBand1LoF",
      "value" = 0,
      "comment" = "band 1: 0 degrees.",
    }, {
      "name" = "wwyXDisBand1HiF",
      "value" = 9,
      "comment" = "band 1: through 9 degrees.",
    }, {
      "name" = "wwyXDisBand2LoF",
      "value" = 10,
      "comment" = "band 2: 10 degrees.",
    }, {
      "name" = "wwyXDisBand2HiF",
      "value" = 29,
      "comment" = "band 2: through 29 degrees.",
    }, {
      "name" = "wwyXDisBand3LoF",
      "value" = 30,
      "comment" = "band 3: 30 degrees.",
    }, {
      "name" = "wwyXDisBand3HiF",
      "value" = 35,
      "comment" = "band 3: through 35 degrees.",
    }, {
      "name" = "wwyXDisBand4LoF",
      "value" = 36,
      "comment" = "band 4: 36 degrees.",
    }, {
      "name" = "wwyXDisBand4HiF",
      "value" = 49,
      "comment" = "band 4: through 49 degrees.",
    }, {
      "name" = "wwyXDisBand5LoF",
      "value" = 50,
      "comment" = "band 5: 50 degrees.",
    }, {
      "name" = "wwyXDisBand5HiF",
      "value" = 74,
      "comment" = "band 5: through 74 degrees.",
    }, {
      "name" = "wwyXDisBand6LoF",
      "value" = 75,
      "comment" = "band 6: 75 degrees and above.",
    }, {
      "name" = "wwyHailLightningFirstMin",
      "value" = 10,
      "comment" = "hail falls during the first 10 minutes of a lightning storm when the dispatch indicates hail.",
    }, {
      "name" = "wwyHailStandaloneD6",
      "value" = 1,
      "comment" = "a standalone hailstorm (unconnected to a lightning storm) occurs on a roll of 1 on 1d6 during an extreme-precipitation determination.",
    }, {
      "name" = "wwyHailDieSides",
      "value" = 6,
      "comment" = "a hailstorm lasts 1d6+4 minutes.",
    }, {
      "name" = "wwyHailDiePlus",
      "value" = 4,
      "comment" = "the +4 on the 1d6 duration roll.",
    }, {
      "name" = "wwyHailMinMin",
      "value" = 5,
      "comment" = "the hailstorm duration floor: 5 minutes.",
    }, {
      "name" = "wwyHailMaxMin",
      "value" = 10,
      "comment" = "the hailstorm duration ceiling: 10 minutes.",
    }, {
      "name" = "wwyHailTypicalQtrIn",
      "value" = 1,
      "comment" = "hailstones are typically one-quarter inch in diameter.",
    }, {
      "name" = "wwyHailMaxLoIn",
      "value" = 2,
      "comment" = "hailstones can grow to 2-3 inches in diameter.",
    }, {
      "name" = "wwyHailMaxHiIn",
      "value" = 3,
      "comment" = "the hailstone size ceiling.",
    }, {
      "name" = "wwyHailMeltMinF",
      "value" = 40,
      "comment" = "hail melts when the temperature is 40 degrees or above.",
    }, {
      "name" = "wwyIceCoatLoEighthIn",
      "value" = 4,
      "comment" = "an ice storm coats the ground and surfaces with one-half to three-quarters of an inch of ice (pinned in eighths: 4 to 6).",
    }, {
      "name" = "wwyIceCoatHiEighthIn",
      "value" = 6,
      "comment" = "the high bound of the ice coating, in eighths.",
    }, {
      "name" = "wwyIceFromHeavyMin",
      "value" = 20,
      "comment" = "a full coating forms after 20 minutes of heavy icing conditions.",
    }, {
      "name" = "wwyIceTraceMaxHrs",
      "value" = 2,
      "comment" = "under trace icing the coating can take as long as 2 hours to form.",
    }, {
      "name" = "wwyLightningDurationMin",
      "value" = 25,
      "comment" = "a lightning storm lasts about 25 minutes.",
    }, {
      "name" = "wwyLightningRainLoEighthIn",
      "value" = 6,
      "comment" = "the lightning storm drops three-quarters to 1 inch of rain (pinned in eighths: 6 to 8).",
    }, {
      "name" = "wwyLightningRainHiIn",
      "value" = 1,
      "comment" = "the high bound of the lightning-storm rainfall, in inches.",
    }, {
      "name" = "wwyLightningTwilightHrs",
      "value" = 2,
      "comment" = "half of all lightning storms occur within two hours of sunrise or sunset.",
    }, {
      "name" = "wwySevereSnowModDieSides",
      "value" = 6,
      "comment" = "a severe snowstorm on a day of moderate-maximum precipitation drops 1d6+4 inches of snow.",
    }, {
      "name" = "wwySevereSnowModDiePlus",
      "value" = 4,
      "comment" = "the +4 on the 1d6 snowfall roll.",
    }, {
      "name" = "wwySevereSnowModInLo",
      "value" = 5,
      "comment" = "the moderate-max snowfall floor: 5 inches.",
    }, {
      "name" = "wwySevereSnowModInHi",
      "value" = 10,
      "comment" = "the moderate-max snowfall ceiling: 10 inches.",
    }, {
      "name" = "wwySevereSnowHeavyDieSides",
      "value" = 6,
      "comment" = "on a heavy-maximum day the severe snowstorm drops 1d6+6 inches.",
    }, {
      "name" = "wwySevereSnowHeavyDiePlus",
      "value" = 6,
      "comment" = "the +6 on the 1d6 snowfall roll.",
    }, {
      "name" = "wwySevereSnowHeavyInLo",
      "value" = 7,
      "comment" = "the heavy-max snowfall floor: 7 inches.",
    }, {
      "name" = "wwySevereSnowHeavyInHi",
      "value" = 12,
      "comment" = "the heavy-max snowfall ceiling: 12 inches.",
    }, {
      "name" = "wwySevereSnowRateInPerHr",
      "value" = 1,
      "comment" = "the snow of a severe snowstorm falls at about 1 inch per hour.",
    }, {
      "name" = "wwySevereSnowWindLoMph",
      "value" = 15,
      "comment" = "after 1-2 hours the wind picks up to very strong: 15-20 mph.",
    }, {
      "name" = "wwySevereSnowWindHiMph",
      "value" = 20,
      "comment" = "the wind ceiling of the follow-on blow.",
    }, {
      "name" = "wwySevereSnowWindHrsLo",
      "value" = 1,
      "comment" = "the wind picks up after 1-2 hours of snowfall.",
    }, {
      "name" = "wwySevereSnowWindHrsHi",
      "value" = 2,
      "comment" = "the high bound of the calm window.",
    }, {
      "name" = "wwyA5Count",
      "value" = 33,
      "comment" = "the Table A5 humidity grid: the same 33-row climate/terrain model as Table A4, x 4 seasons; the arctic block (all five terrains) is uniformly low.",
    }, {
      "name" = "wwyHumLevelLow",
      "value" = 1,
      "comment" = "the humidity letter codes: L (low) = 1.",
    }, {
      "name" = "wwyHumLevelMed",
      "value" = 2,
      "comment" = "M (medium) = 2.",
    }, {
      "name" = "wwyHumLevelHigh",
      "value" = 3,
      "comment" = "H (high) = 3.",
    }, {
      "name" = "wwyHumDryMaxPct",
      "value" = 20,
      "comment" = "below low is dry: 0-20 percent relative humidity.",
    }, {
      "name" = "wwyHumLowLoPct",
      "value" = 21,
      "comment" = "low: 21-40 percent.",
    }, {
      "name" = "wwyHumLowHiPct",
      "value" = 40,
      "comment" = "the low band ceiling.",
    }, {
      "name" = "wwyHumMedLoPct",
      "value" = 41,
      "comment" = "medium: 41-70 percent.",
    }, {
      "name" = "wwyHumMedHiPct",
      "value" = 70,
      "comment" = "the medium band ceiling.",
    }, {
      "name" = "wwyHumHiLoPct",
      "value" = 71,
      "comment" = "high: 71-90 percent.",
    }, {
      "name" = "wwyHumHiHiPct",
      "value" = 90,
      "comment" = "the high band ceiling.",
    }, {
      "name" = "wwyHumSatLoPct",
      "value" = 91,
      "comment" = "above high is saturated: 91-100 percent.",
    }, {
      "name" = "wwyHumSatHiPct",
      "value" = 100,
      "comment" = "the saturated band ceiling.",
    }, {
      "name" = "wwyHumAdjRows",
      "value" = 3,
      "comment" = "the day 1 / day 2 humidity adjustment: 3 x 3, the day 1 precipitation (none / light or trace / medium or more) against the day 2.",
    }, {
      "name" = "wwyA6Count",
      "value" = 25,
      "comment" = "the Table A6 humidity / effective temperature grid: 5 temperature bands x 5 humidity levels x 5 wind columns, 25 rows.",
    }, {
      "name" = "wwyEffTempApplyMinF",
      "value" = 60,
      "comment" = "the humidity adjustment to effective temperature applies when the actual temperature is 60 degrees or above.",
    }, {
      "name" = "wwyA6Band1LoF",
      "value" = 60,
      "comment" = "the A6 temperature band 1: 60-64 degrees.",
    }, {
      "name" = "wwyA6Band1HiF",
      "value" = 64,
      "comment" = "the band 1 ceiling.",
    }, {
      "name" = "wwyA6Band2LoF",
      "value" = 65,
      "comment" = "the A6 temperature band 2: 65-74 degrees.",
    }, {
      "name" = "wwyA6Band2HiF",
      "value" = 74,
      "comment" = "the band 2 ceiling.",
    }, {
      "name" = "wwyA6Band3LoF",
      "value" = 75,
      "comment" = "the A6 temperature band 3: 75-84 degrees.",
    }, {
      "name" = "wwyA6Band3HiF",
      "value" = 84,
      "comment" = "the band 3 ceiling.",
    }, {
      "name" = "wwyA6Band4LoF",
      "value" = 85,
      "comment" = "the A6 temperature band 4: 85-94 degrees.",
    }, {
      "name" = "wwyA6Band4HiF",
      "value" = 94,
      "comment" = "the band 4 ceiling.",
    }, {
      "name" = "wwyA6Band5LoF",
      "value" = 95,
      "comment" = "the A6 temperature band 5: 95 degrees and above.",
    }, {
      "name" = "wwyWindCol0HiMph",
      "value" = 10,
      "comment" = "the A6 wind columns: 0-10 mph, 11-20, 21-30, 31-45, and 45+ (the high bound of the first column).",
    }, {
      "name" = "wwyWindCol1LoMph",
      "value" = 11,
      "comment" = "the second wind column low bound.",
    }, {
      "name" = "wwyWindCol1HiMph",
      "value" = 20,
      "comment" = "the second wind column high bound.",
    }, {
      "name" = "wwyWindCol2LoMph",
      "value" = 21,
      "comment" = "the third wind column low bound.",
    }, {
      "name" = "wwyWindCol2HiMph",
      "value" = 30,
      "comment" = "the third wind column high bound.",
    }, {
      "name" = "wwyWindCol3LoMph",
      "value" = 31,
      "comment" = "the fourth wind column low bound.",
    }, {
      "name" = "wwyWindCol3HiMph",
      "value" = 45,
      "comment" = "the fourth wind column high bound.",
    }, {
      "name" = "wwyWindCol4LoMph",
      "value" = 45,
      "comment" = "the fifth wind column: 45 mph and above.",
    }, {
      "name" = "wwyA7Count",
      "value" = 17,
      "comment" = "the Table A7 wind chill grid: 17 temperature rows x 8 wind columns.",
    }, {
      "name" = "wwyChillMaxTempF",
      "value" = 35,
      "comment" = "the wind chill table runs from an actual temperature of 35 degrees.",
    }, {
      "name" = "wwyChillMinTempF",
      "value" = -45,
      "comment" = "the wind chill table runs down to an actual temperature of -45 degrees.",
    }, {
      "name" = "wwyChillStepF",
      "value" = 5,
      "comment" = "the temperature rows step by 5 degrees from 35 down to -45.",
    }, {
      "name" = "wwyChillWindCol0Mph",
      "value" = 5,
      "comment" = "the wind columns run from 5 mph.",
    }, {
      "name" = "wwyChillWindColStepMph",
      "value" = 5,
      "comment" = "the wind columns step by 5 mph to 40 mph.",
    }, {
      "name" = "wwyA8Count",
      "value" = 15,
      "comment" = "the Table A8 hours of daylight grid: 15 latitude rows x 12 months.",
    }, {
      "name" = "wwyA8Months",
      "value" = 12,
      "comment" = "one column per month, 12 months to the year.",
    }, {
      "name" = "wwyA8HalfHourUnits",
      "value" = 2,
      "comment" = "the daylight hours are stored in half-hour units to keep the grid integral (24 hours = 48).",
    }, {
      "name" = "wwyA8Lat0",
      "value" = 90,
      "comment" = "the A8 latitude ladder, row 0: 90 degrees (the pole); rows 1-2 are 80 and 70 (the arctic block).",
    }, {
      "name" = "wwyA8Lat3",
      "value" = 65,
      "comment" = "row 3: 65 degrees; rows 4-5 are 60 and 55 (the subarctic block).",
    }, {
      "name" = "wwyA8Lat6",
      "value" = 50,
      "comment" = "row 6: 50 degrees; rows 7-8 are 40 and 35 (the temperate block).",
    }, {
      "name" = "wwyA8Lat9",
      "value" = 30,
      "comment" = "row 9: 30 degrees; rows 10-11 are 25 and 20 (the subtropical block).",
    }, {
      "name" = "wwyA8Lat12",
      "value" = 15,
      "comment" = "row 12: 15 degrees; rows 13-14 are 10 and 0 (the tropical block).",
    }, {
      "name" = "wwyA8Lat14",
      "value" = 0,
      "comment" = "row 14: the equator, 12 hours of daylight every day of the year.",
    }, {
      "name" = "wwyTwilightMidLatMin",
      "value" = 30,
      "comment" = "each of the two daily twilight periods lasts about 30 minutes at the middle latitudes.",
    }, {
      "name" = "wwyTwilightMidLatLoDeg",
      "value" = 30,
      "comment" = "the middle-latitude band: 30-40 degrees.",
    }, {
      "name" = "wwyTwilightMidLatHiDeg",
      "value" = 40,
      "comment" = "the middle-latitude band ceiling.",
    }, {
      "name" = "wwyTwilightEquatorMin",
      "value" = 20,
      "comment" = "twilight decreases to a minimum of 20 minutes at the equator.",
    }, {
      "name" = "wwyTwilightHighLatMin",
      "value" = 40,
      "comment" = "twilight increases to 40 minutes at relatively high latitudes.",
    }, {
      "name" = "wwyTwilightHighLatLoDeg",
      "value" = 50,
      "comment" = "the high-latitude band: 50-60 degrees.",
    }, {
      "name" = "wwyTwilightHighLatHiDeg",
      "value" = 60,
      "comment" = "the high-latitude band ceiling.",
    }, {
      "name" = "wwyTwilightTerrainMinLo",
      "value" = 5,
      "comment" = "local terrain can cut twilight to 5-10 minutes (a dense forest, the shaded side of a mountain).",
    }, {
      "name" = "wwyTwilightTerrainMinHi",
      "value" = 10,
      "comment" = "the terrain-cut twilight ceiling.",
    }, {
      "name" = "wwySeaBreezeInlandMinMi",
      "value" = 5,
      "comment" = "a sea breeze reaches 5-10 miles inland.",
    }, {
      "name" = "wwySeaBreezeInlandMaxMi",
      "value" = 10,
      "comment" = "the sea-breeze inland reach ceiling.",
    }, {
      "name" = "wwyTideHoursBetweenHighs",
      "value" = 12,
      "comment" = "there are two high tides and two low tides daily, alternating; about 12 hours pass between one high tide and the next.",
    }, {
      "name" = "wwyTideLowAfterHighHrs",
      "value" = 6,
      "comment" = "low tide comes about 6 hours after high tide.",
    }, {
      "name" = "wwyLunarDayRoughHrs",
      "value" = 25,
      "comment" = "the lunar day runs about 25 hours, so the whole tidal cycle advances about an hour later each day.",
    }, {
      "name" = "wwyTideAdvanceMinPerDay",
      "value" = 60,
      "comment" = "the daily tidal advance, pinned in minutes.",
    }, {
      "name" = "wwyTideCycleDays",
      "value" = 28,
      "comment" = "the full tidal cycle repeats with the 28-day lunar cycle.",
    }, {
      "name" = "wwySpringWindowDays",
      "value" = 7,
      "comment" = "spring tides occur in roughly 7-day windows around the full and new moon; the rest of the cycle is neap tides.",
    }, {
      "name" = "wwyNeapRangeFtLo",
      "value" = 5,
      "comment" = "an average neap tide runs 5-7 feet from high to low.",
    }, {
      "name" = "wwyNeapRangeFtHi",
      "value" = 7,
      "comment" = "the neap range ceiling.",
    }, {
      "name" = "wwySpringRangeFtLo",
      "value" = 15,
      "comment" = "an average spring tide runs 15-18 feet from high to low.",
    }, {
      "name" = "wwySpringRangeFtHi",
      "value" = 18,
      "comment" = "the spring range ceiling.",
    }, {
      "name" = "wwyFundyMaxFt",
      "value" = 60,
      "comment" = "extreme coastal configurations can multiply the range (the Bay of Fundy reaches 60 feet).",
    }, {
      "name" = "wwyGentleSlopeMaxDeg",
      "value" = 30,
      "comment" = "tidal encroachment on a gently sloped shore (30 degrees or less): the water encroaches 4-5 times the tide height.",
    }, {
      "name" = "wwyGentleEncroachLoX",
      "value" = 4,
      "comment" = "the gentle-slope encroachment low multiple.",
    }, {
      "name" = "wwyGentleEncroachHiX",
      "value" = 5,
      "comment" = "the gentle-slope encroachment high multiple.",
    }, {
      "name" = "wwyModerateSlopeLoDeg",
      "value" = 31,
      "comment" = "a moderately sloped shore runs 31-50 degrees.",
    }, {
      "name" = "wwyModerateSlopeHiDeg",
      "value" = 50,
      "comment" = "the moderate-slope ceiling.",
    }, {
      "name" = "wwyModerateEncroachLoX",
      "value" = 2,
      "comment" = "the moderate-slope encroachment: 2-3 times the tide height.",
    }, {
      "name" = "wwyModerateEncroachHiX",
      "value" = 3,
      "comment" = "the moderate-slope high multiple.",
    }, {
      "name" = "wwySevereSlopeLoDeg",
      "value" = 51,
      "comment" = "a severely sloped shore runs 51-70 degrees.",
    }, {
      "name" = "wwySevereSlopeHiDeg",
      "value" = 70,
      "comment" = "the severe-slope ceiling.",
    }, {
      "name" = "wwySevereEncroachLoX",
      "value" = 1,
      "comment" = "the severe-slope encroachment: 1-2 times the tide height.",
    }, {
      "name" = "wwySevereEncroachHiX",
      "value" = 2,
      "comment" = "the severe-slope high multiple.",
    }, {
      "name" = "wwyTideExampleGentleFt",
      "value" = 15,
      "comment" = "the worked gentle-slope example: a 15-foot spring high tide.",
    }, {
      "name" = "wwyTideExampleGentleEncroachLoFt",
      "value" = 60,
      "comment" = "the example encroaches 60-75 feet (4 x 15 to 5 x 15).",
    }, {
      "name" = "wwyTideExampleGentleEncroachHiFt",
      "value" = 75,
      "comment" = "the example ceiling.",
    }, {
      "name" = "wwyTideExampleModerateFt",
      "value" = 5,
      "comment" = "the worked moderate-slope example: a 5-foot tide.",
    }, {
      "name" = "wwyTideExampleModerateEncroachLoFt",
      "value" = 10,
      "comment" = "the example encroaches 10-15 feet (2 x 5 to 3 x 5).",
    }, {
      "name" = "wwyTideExampleModerateEncroachHiFt",
      "value" = 15,
      "comment" = "the example ceiling.",
    } },
  "bools" = { {
      "name" = "wwyRunningEpisodeNoSpecial",
      "value" = true,
      "comment" = "if any special weather episode is already in progress, a roll of 2 or 12 on the Day-to-Day Change Table indicates no special weather for that day.",
    }, {
      "name" = "wwyNoSpecRoll2SharpDrop",
      "value" = true,
      "comment" = "the no-special 2: the temperature takes a sharp drop.",
    }, {
      "name" = "wwyNoSpecRoll2PrecipB",
      "value" = true,
      "comment" = "the no-special 2: precipitation is possible, as given on the Precipitation Variation Table for a roll of doubles (the B column).",
    }, {
      "name" = "wwyNoSpecRoll2WindSource50",
      "value" = true,
      "comment" = "the no-special 2: the wind comes from the arctic or from the prevailing direction, 50 percent either way.",
    }, {
      "name" = "wwyNoSpecRoll12SharpRise",
      "value" = true,
      "comment" = "the no-special 12: the temperature takes a sharp rise.",
    }, {
      "name" = "wwyNoSpecRoll12PrecipB",
      "value" = true,
      "comment" = "the no-special 12: precipitation is possible, as given on the Precipitation Variation Table for a roll of doubles (the B column).",
    }, {
      "name" = "wwyColdWaveFloorBelowMin",
      "value" = true,
      "comment" = "the daily drop stops one step below the normal minimum temperature for the date (the wave floor).",
    }, {
      "name" = "wwyColdWaveRecoveryAutoRise",
      "value" = true,
      "comment" = "the recovery from a cold wave is automatic: the temperature rises to the normal minimum with no roll.",
    }, {
      "name" = "wwyHeatWaveCeilingAboveMax",
      "value" = true,
      "comment" = "the daily rise stops one step above the normal maximum temperature for the date (the wave ceiling).",
    }, {
      "name" = "wwyHeatWaveRecoveryAutoFall",
      "value" = true,
      "comment" = "the recovery from a heat wave is automatic: the temperature falls to the normal maximum with no roll.",
    }, {
      "name" = "wwyCycloneSeacoastLightningDayBefore",
      "value" = true,
      "comment" = "at a seacoast, a cyclone is heralded a day in advance by a lightning storm.",
    }, {
      "name" = "wwyCycloneMovesAwayFromEquator",
      "value" = true,
      "comment" = "a cyclone moves away from the equator (toward the nearest pole).",
    }, {
      "name" = "wwyCycloneFollowsCoast",
      "value" = true,
      "comment" = "at sea a cyclone follows the coastline rather than striking inland directly.",
    }, {
      "name" = "wwyCycloneRainDoubleDownpour",
      "value" = true,
      "comment" = "within the cyclone the rain is at least twice that of a downpour.",
    }, {
      "name" = "wwyCycloneEyeSecondHalfRainstorm",
      "value" = true,
      "comment" = "the second half of the eye brings a heavy rainstorm for its 6 hours.",
    }, {
      "name" = "wwyCycloneMaxOncePerMonth",
      "value" = true,
      "comment" = "an area can be struck by at most one cyclone in a given month.",
    }, {
      "name" = "wwyCycloneSecondBecomesExtreme",
      "value" = true,
      "comment" = "a second cyclone indicated within the 200-mile radius in the same month indicates extreme precipitation instead.",
    }, {
      "name" = "wwyCycloneNotNearEquator",
      "value" = true,
      "comment" = "cyclones are not generated within 5 degrees of the equator.",
    }, {
      "name" = "wwyDroughtDay1NoPrecip",
      "value" = true,
      "comment" = "no precipitation falls on the first day of a drought.",
    }, {
      "name" = "wwyDroughtLightToTrace",
      "value" = true,
      "comment" = "precipitation indicated at light or moderate maximum falls as at most a trace during a drought.",
    }, {
      "name" = "wwyDroughtHeavyLadder",
      "value" = true,
      "comment" = "heavy-maximum precipitation steps down each day of the drought: heavy to light, moderate to trace, light to none.",
    }, {
      "name" = "wwyGaleNeverBelow30",
      "value" = true,
      "comment" = "wind velocity during a gale never drops below 30 mph and is mostly 50 mph or greater.",
    }, {
      "name" = "wwyGalePrev20Boost",
      "value" = true,
      "comment" = "if the previous day wind was 20 mph or greater, the gale reads 50-70 mph.",
    }, {
      "name" = "wwyGaleDesertSandstorm",
      "value" = true,
      "comment" = "in a desert a gale produces no precipitation and whips up a severe sandstorm instead.",
    }, {
      "name" = "wwyGaleSnowSevereSandstorm",
      "value" = true,
      "comment" = "in an arctic or subarctic climate (or anywhere with snow on the ground) a gale whips the snow into a severe blizzard, the blowing-snow analogue of a severe sandstorm.",
    }, {
      "name" = "wwyMistHeavyNearWater",
      "value" = true,
      "comment" = "in a seacoast area or an area adjacent to a large body of water the fog is heavy; elsewhere it is moderate.",
    }, {
      "name" = "wwyMistSuspendsPrecip",
      "value" = true,
      "comment" = "precipitation is suspended while the mist or fog lasts.",
    }, {
      "name" = "wwyMistAdjacent50",
      "value" = true,
      "comment" = "there is a 50 percent chance of mist or fog the day before and the day after in an area adjacent to the fog.",
    }, {
      "name" = "wwySandstormNeedsLooseMaterial",
      "value" = true,
      "comment" = "a sandstorm requires an area of loose soil, sand or snow (fine dirt also qualifies).",
    }, {
      "name" = "wwySandstormNoPrecipThatDay",
      "value" = true,
      "comment" = "no precipitation falls on the day of a sandstorm.",
    }, {
      "name" = "wwyTornadoConditionsSuitable",
      "value" = true,
      "comment" = "a tornado occurs only when conditions are suitable: only in areas where tornados are known to occur, and only during special weather determinations.",
    }, {
      "name" = "wwyTornadoTempTwoStepsAbove",
      "value" = true,
      "comment" = "a tornado requires the temperature to be at least 2 steps above normal for the day.",
    }, {
      "name" = "wwyTornadoRainStopsAbruptly",
      "value" = true,
      "comment" = "the heavy rain of the tornado front stops abruptly as the tornado approaches.",
    }, {
      "name" = "wwyTornadoCalmNearPath",
      "value" = true,
      "comment" = "within one-half mile of the tornado path the air is calm.",
    }, {
      "name" = "wwyTornadoDropGreater",
      "value" = true,
      "comment" = "the 15-degree or 3-step temperature drop takes the greater of the two measures.",
    }, {
      "name" = "wwyTornadoCalmRestOfDay",
      "value" = true,
      "comment" = "after the tornado passes the calm lasts the rest of the day.",
    }, {
      "name" = "wwyTornadoLowPressureExplosion",
      "value" = true,
      "comment" = "the extremely low air pressure inside the vortex can cause sealed structures to explode.",
    }, {
      "name" = "wwyExtremePrecipSubroll",
      "value" = true,
      "comment" = "when the code letter X is selected, cross-index the temperature with the climatic column and roll 1d6 on the dispatch table to determine the type of extreme precipitation.",
    }, {
      "name" = "wwyXDisIceNeeds25F",
      "value" = true,
      "comment" = "in the 10-29 band the ice/sleet result of the dispatch carries the 25-degree minimum-temperature requirement.",
    }, {
      "name" = "wwyLightningHalfAtTwilight",
      "value" = true,
      "comment" = "lightning storms favor the dawn and dusk windows: about half fall within two hours either side of sunrise or sunset.",
    }, {
      "name" = "wwyLightningStandaloneDisregarded",
      "value" = true,
      "comment" = "a lightning result on the dispatch under moderate or light precipitation maximums is disregarded (it rides the stronger storm types).",
    }, {
      "name" = "wwyLightningAtDownpourStart",
      "value" = true,
      "comment" = "in a downpour the lightning storm occurs at the start of the precipitation.",
    }, {
      "name" = "wwySevereSnowWindAfter",
      "value" = true,
      "comment" = "a severe snowstorm starts calm and turns windy: after 1-2 hours of snow the wind rises to very strong, 15-20 mph.",
    }, {
      "name" = "wwyHumFluctuatesOneLevel",
      "value" = true,
      "comment" = "humidity fluctuates one level to either side of the Table A5 level as weather changes (a three-level range).",
    }, {
      "name" = "wwyHumLowEdgeDry",
      "value" = true,
      "comment" = "a fluctuation below low reads dry (0-20 percent).",
    }, {
      "name" = "wwyHumHighEdgeSaturated",
      "value" = true,
      "comment" = "a fluctuation above high reads saturated (91-100 percent).",
    }, {
      "name" = "wwyHumDMTwoLevelDrop",
      "value" = true,
      "comment" = "the Dungeon Master may allow a two-level drop in exceptional conditions (a cold front after a rainstorm).",
    }, {
      "name" = "wwyChillExtrapBelow",
      "value" = true,
      "comment" = "for temperatures lower than -45, extrapolate downward following the pattern of the decrease from -40 to -45.",
    }, {
      "name" = "wwyChillExtrapAbove40Mph",
      "value" = true,
      "comment" = "for wind speeds greater than 40 mph, use the 40-mph column; greater wind speeds have little if any additional chilling effect.",
    }, {
      "name" = "wwyA8SimplifiedRowsOnly",
      "value" = true,
      "comment" = "the shorter simplified version uses only the middle row of each climatic block: the 80 line for arctic, 60 for subarctic, 40 for temperate, 25 for subtropical, 10 for tropical - no latitude bookkeeping, only the climatic region.",
    }, {
      "name" = "wwyA8MidnightNightMidpoint",
      "value" = true,
      "comment" = "the table gives lengths, not clock times: sunrise and sunset are derived with midnight as the midpoint of the nighttime period and noon as the midpoint of the daytime period, or stipulated by the Dungeon Master.",
    }, {
      "name" = "wwyTwilightAllDayWhereNoDaylight",
      "value" = true,
      "comment" = "where the daylight table reads zero, the day is not black: the period is one of twilight, not true darkness (the arctic winter).",
    }, {
      "name" = "wwySeaBreezeDayWaterToLand",
      "value" = true,
      "comment" = "during the day the land heats faster than the water: a sea breeze blows from the water toward the land.",
    }, {
      "name" = "wwyLandBreezeNight",
      "value" = true,
      "comment" = "at night the land cools faster: a land breeze blows from the land toward the water.",
    }, {
      "name" = "wwySeaBreezeStronger",
      "value" = true,
      "comment" = "the daytime sea breeze is stronger than the nighttime land breeze.",
    }, {
      "name" = "wwyClearSkiesFavorBreezes",
      "value" = true,
      "comment" = "clear skies favor both breezes (maximum heating and cooling differential); cloud cover reduces them.",
    }, {
      "name" = "wwySeaBreezeCanChillCoast",
      "value" = true,
      "comment" = "a sea breeze can lower the coastal temperature by as much as 20 degrees on a hot day (the Lake Michigan breeze).",
    }, {
      "name" = "wwyCliffFacesTrapSwirlCalm",
      "value" = true,
      "comment" = "in the lee of a cliff face the wind swirls, is trapped, or dies to a calm - local terrain dominates over the regional wind.",
    }, {
      "name" = "wwyTidesTwiceDailyAlternating",
      "value" = true,
      "comment" = "the two daily tides alternate high and low, in equal numbers of high and low waters.",
    }, {
      "name" = "wwySpringTidesAroundFullNew",
      "value" = true,
      "comment" = "spring tides (the stronger tides) fall in the windows around the full and the new moon; neap tides fill the rest of the cycle.",
    }, {
      "name" = "wwyDMDetermine2to3Days",
      "value" = true,
      "comment" = "the Dungeon Master determines the weather 2-3 days in advance of the play session, keeping the determination hidden until it comes into play.",
    }, {
      "name" = "wwyDMSwitchTimeframesFreely",
      "value" = true,
      "comment" = "the DM switches freely between determining weather one day at a time, several days at once, or whole weeks - whatever the pace of play demands.",
    }, {
      "name" = "wwyDMPredetermineMultiDay",
      "value" = true,
      "comment" = "for multi-day outings (long journeys, expeditions) the DM predetermines the weather for the entire span before play begins.",
    } },
  "switches" = {},
  "tables" = { {
      "tag" = "R2",
      "name" = "wwyRoll2Index",
      "count" = "wwyRoll2Rows",
      "cols" = { "wwtR2B24", "wwtR2B56", "wwtR2B7", "wwtR2B89", "wwtR2B1012" },
      "col_comments" = { "the selected letter for the Roll 2 band 2-4 (row 0: Roll 1 = 2 picks the 1st letter; row 1: Roll 1 = 12 picks none)", "the selected letter for the Roll 2 band 5-6 (row 0: Roll 1 = 2 picks the 2nd letter; row 1: Roll 1 = 12 picks none)", "the selected letter for the Roll 2 band 7 (row 0: Roll 1 = 2 picks the 2nd letter; row 1: Roll 1 = 12 picks the 3rd)", "the selected letter for the Roll 2 band 8-9 (row 0: Roll 1 = 2 picks none; row 1: Roll 1 = 12 picks the 3rd)", "the selected letter for the Roll 2 band 10-12 (row 0: Roll 1 = 2 picks none; row 1: Roll 1 = 12 picks the 4th)" },
      "data" = { { 1, 2, 2, 0, 0 }, { 0, 0, 3, 3, 4 } },
      "sentinel" = -1,
      "audit_comment" = "the Roll 2 cross-index rows: Roll 1 = 2 and Roll 1 = 12",
    }, {
      "tag" = "A4",
      "name" = "wwyA4Special",
      "count" = "wwyA4Count",
      "cols" = { "wwtA4Wi", "wwtA4Sp", "wwtA4Su", "wwtA4Au" },
      "col_comments" = { "the four-letter code for Winter (the packed digits, one letter per digit: A=1 cold wave, C=2 cyclone, D=3 drought, G=4 gale, M=5 mist/fog, S=6 sandstorm, T=7 tornado, X=8 extreme precipitation, Z=9 heat wave)", "the four-letter code for Spring", "the four-letter code for Summer", "the four-letter code for Autumn" },
      "data" = { { 4133, 4133, 4133, 4133 }, { 4133, 4135, 4159, 4135 }, { 4133, 4135, 4159, 4135 }, { 4133, 1435, 8139, 4139 }, { 4133, 1459, 4159, 4159 }, { 4133, 4133, 1633, 4133 }, { 4139, 1839, 8193, 1853 }, { 4153, 1439, 1893, 4153 }, { 4135, 1859, 1893, 4153 }, { 4153, 1839, 9193, 4139 }, { 4159, 4159, 8195, 1459 }, { 1859, 1859, 8195, 1859 }, { 1639, 4639, 4639, 6439 }, { 1859, 4859, 4859, 1859 }, { 1859, 1897, 1839, 1839 }, { 1853, 1859, 1839, 8139 }, { 1439, 1879, 8439, 8139 }, { 1859, 2859, 2859, 1859 }, { 1859, 4859, 4859, 1859 }, { 1639, 4639, 4639, 4639 }, { 8159, 8495, 8895, 1859 }, { 1839, 1837, 8439, 1895 }, { 1839, 1895, 8493, 8195 }, { 1839, 8479, 8439, 4139 }, { 1839, 2859, 2859, 1839 }, { 1839, 2859, 2859, 1839 }, { 1639, 4639, 4639, 4639 }, { 8859, 8895, 8895, 8859 }, { 1439, 4839, 4839, 4493 }, { 1859, 1859, 8495, 1459 }, { 4839, 4839, 6893, 4893 }, { 8139, 1859, 2859, 8195 }, { 1859, 4859, 8459, 8159 } },
      "sentinel" = -1,
      "audit_comment" = "the Table A4 grid: 33 climate/terrain rows x the four seasonal codes, each cell a packed four-letter code (arctic rows 0-4, subarctic 5-11, temperate 12-18, subtropical 19-25, tropical 26-32; desert, forest, hills, mountains, plains, seacoast, swamp within each block)",
    }, {
      "tag" = "XD",
      "name" = "wwyXDispatch",
      "count" = "wwyXDisBands",
      "cols" = { "wwtXDisTr1", "wwtXDisTr2", "wwtXDisTr3", "wwtXDisTr4", "wwtXDisTr5", "wwtXDisTr6", "wwtXDisTa1", "wwtXDisTa2", "wwtXDisTa3", "wwtXDisTa4", "wwtXDisTa5", "wwtXDisTa6" },
      "col_comments" = { "the tropical/subtropical column, sub-roll 1 on 1d6", "the tropical/subtropical column, sub-roll 2", "the tropical/subtropical column, sub-roll 3", "the tropical/subtropical column, sub-roll 4", "the tropical/subtropical column, sub-roll 5", "the tropical/subtropical column, sub-roll 6", "the temperate/subarctic/arctic column, sub-roll 1 on 1d6", "the temperate/subarctic/arctic column, sub-roll 2", "the temperate/subarctic/arctic column, sub-roll 3", "the temperate/subarctic/arctic column, sub-roll 4", "the temperate/subarctic/arctic column, sub-roll 5", "the temperate/subarctic/arctic column, sub-roll 6" },
      "data" = { { 0, 0, 0, 0, 0, 0, 4, 4, 4, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0 }, { 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 2 }, { 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 1, 2 }, { 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 1, 1 }, { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 }, { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 } },
      "sentinel" = -1,
      "audit_comment" = "the X dispatch: 7 temperature bands x the 1-6 sub-rolls for the two climatic columns (values 1 hail, 2 ice/sleet, 3 lightning, 4 severe snowstorm, 0 none; the 10-29 band ice cell carries the 25-degree footnote)",
    }, {
      "tag" = "A5",
      "name" = "wwyA5Humidity",
      "count" = "wwyA5Count",
      "cols" = { "wwtA5Wi", "wwtA5Sp", "wwtA5Su", "wwtA5Au" },
      "col_comments" = { "the humidity level for Winter (1 = low, 2 = medium, 3 = high)", "the humidity level for Spring", "the humidity level for Summer", "the humidity level for Autumn" },
      "data" = { { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 2, 2, 2 }, { 1, 1, 1, 1 }, { 1, 2, 1, 1 }, { 1, 2, 2, 1 }, { 1, 2, 2, 1 }, { 1, 2, 2, 1 }, { 1, 1, 1, 1 }, { 2, 3, 2, 2 }, { 2, 3, 3, 2 }, { 1, 2, 1, 2 }, { 2, 3, 3, 2 }, { 3, 2, 2, 3 }, { 2, 3, 3, 2 }, { 1, 1, 1, 1 }, { 3, 3, 3, 3 }, { 2, 3, 3, 3 }, { 2, 3, 3, 3 }, { 2, 3, 2, 1 }, { 2, 3, 3, 2 }, { 2, 3, 3, 2 }, { 1, 1, 1, 1 }, { 3, 3, 3, 3 }, { 2, 2, 3, 2 }, { 2, 3, 3, 3 }, { 2, 3, 3, 3 }, { 2, 3, 3, 2 }, { 2, 3, 3, 3 } },
      "sentinel" = -1,
      "audit_comment" = "the Table A5 humidity grid: 33 climate/terrain rows x the four seasonal levels (the arctic block uniformly low, printed order Winter/Spring/Summer/Autumn)",
    }, {
      "tag" = "HB",
      "name" = "wwyHumAdjBefore",
      "count" = "wwyHumAdjRows",
      "cols" = { "wwtHumAdjBefore0", "wwtHumAdjBefore1", "wwtHumAdjBefore2" },
      "col_comments" = { "the humidity step adjustment taken BEFORE the day 2 precipitation, day 2 column none", "the day 2 column light or trace", "the day 2 column medium or more" },
      "data" = { { -1, 0, 1 }, { 0, 0, 0 }, { 0, 0, 1 } },
      "sentinel" = -1,
      "audit_comment" = "the day 1 / day 2 humidity adjustment, the BEFORE halves of the printed slash pairs",
    }, {
      "tag" = "HA",
      "name" = "wwyHumAdjAfter",
      "count" = "wwyHumAdjRows",
      "cols" = { "wwtHumAdjAfter0", "wwtHumAdjAfter1", "wwtHumAdjAfter2" },
      "col_comments" = { "the humidity step adjustment taken AFTER the day 2 precipitation, day 2 column none", "the day 2 column light or trace", "the day 2 column medium or more" },
      "data" = { { -1, 0, 1 }, { -1, 0, 1 }, { -1, -1, 2 } },
      "sentinel" = -1,
      "audit_comment" = "the day 1 / day 2 humidity adjustment, the AFTER halves of the printed slash pairs",
    }, {
      "tag" = "A6",
      "name" = "wwyA6EffectiveTemp",
      "count" = "wwyA6Count",
      "cols" = { "wwtA6W0", "wwtA6W1", "wwtA6W2", "wwtA6W3", "wwtA6W4" },
      "col_comments" = { "the effective-temperature adjustment at wind 0-10 mph", "the adjustment at wind 11-20 mph", "the adjustment at wind 21-30 mph", "the adjustment at wind 31-45 mph", "the adjustment at wind 45+ mph" },
      "data" = { { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 5, 0, 0, 0, 0 }, { 10, 5, 0, 0, 0 }, { 10, 5, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 10, 5, 5, 0, 0 }, { 0, 0, 0, 0, 0 }, { 5, 0, 0, 0, 0 }, { 5, 5, 0, 0, 0 }, { 10, 5, 5, 0, 0 }, { 15, 10, 5, 0, 0 }, { 0, 0, 0, 0, 0 }, { 5, 5, 0, 0, 0 }, { 10, 5, 5, 0, 0 }, { 15, 10, 5, 5, 0 }, { 20, 15, 10, 5, 0 }, { 0, 0, 0, 0, 0 }, { 10, 5, 0, 0, 0 }, { 15, 10, 5, 5, 0 }, { 20, 15, 10, 5, 5 }, { 25, 20, 15, 10, 5 } },
      "sentinel" = -1,
      "audit_comment" = "the Table A6 grid: rows are the 5 temperature bands x the 5 humidity levels in the order dry, low, medium, high, saturated; the values are the degrees added to the actual temperature for effective temperature",
    }, {
      "tag" = "A7",
      "name" = "wwyA7WindChill",
      "count" = "wwyA7Count",
      "cols" = { "wwtA7C0", "wwtA7C1", "wwtA7C2", "wwtA7C3", "wwtA7C4", "wwtA7C5", "wwtA7C6", "wwtA7C7" },
      "col_comments" = { "the effective temperature at 5 mph wind", "the effective temperature at 10 mph", "the effective temperature at 15 mph", "the effective temperature at 20 mph", "the effective temperature at 25 mph", "the effective temperature at 30 mph", "the effective temperature at 35 mph", "the effective temperature at 40 mph" },
      "data" = { { 35, 20, 15, 10, 5, 5, 0, 0 }, { 25, 15, 10, 5, 0, 0, -5, -5 }, { 20, 10, 0, -5, -5, -10, -15, -15 }, { 15, 0, -5, -10, -15, -20, -20, -25 }, { 10, -5, -10, -15, -20, -25, -30, -30 }, { 5, -10, -20, -25, -30, -35, -35, -40 }, { 0, -15, -25, -30, -35, -40, -45, -45 }, { -5, -20, -35, -40, -45, -50, -50, -55 }, { -10, -25, -40, -45, -50, -55, -60, -65 }, { -15, -30, -45, -50, -60, -60, -65, -70 }, { -20, -40, -50, -60, -70, -75, -80, -80 }, { -25, -45, -60, -70, -75, -80, -85, -90 }, { -30, -50, -65, -75, -85, -90, -90, -95 }, { -35, -60, -70, -80, -90, -95, -100, -100 }, { -40, -65, -80, -90, -95, -100, -105, -110 }, { -45, -70, -85, -95, -105, -110, -115, -115 }, { -50, -75, -90, -100, -110, -115, -120, -120 } },
      "sentinel" = -1,
      "audit_comment" = "the Table A7 wind chill grid: 17 temperature rows (35 down to -45 by 5) x 8 wind columns (5 to 40 by 5)",
    }, {
      "tag" = "A8",
      "name" = "wwyA8Daylight",
      "count" = "wwyA8Count",
      "cols" = { "wwtA8M0", "wwtA8M1", "wwtA8M2", "wwtA8M3", "wwtA8M4", "wwtA8M5", "wwtA8M6", "wwtA8M7", "wwtA8M8", "wwtA8M9", "wwtA8M10", "wwtA8M11" },
      "col_comments" = { "the hours of daylight in month 1 (in half-hours: 48 = 24 hours)", "the hours of daylight in month 2", "the hours of daylight in month 3", "the hours of daylight in month 4", "the hours of daylight in month 5", "the hours of daylight in month 6", "the hours of daylight in month 7", "the hours of daylight in month 8", "the hours of daylight in month 9", "the hours of daylight in month 10", "the hours of daylight in month 11", "the hours of daylight in month 12" },
      "data" = { { 0, 0, 0, 48, 48, 48, 48, 48, 48, 0, 0, 0 }, { 0, 0, 22, 48, 48, 48, 48, 48, 31, 10, 0, 0 }, { 0, 15, 23, 32, 44, 48, 48, 37, 27, 18, 6, 0 }, { 6, 17, 23, 30, 39, 43, 40, 34, 27, 19, 10, 6 }, { 13, 18, 23, 29, 34, 38, 35, 32, 26, 20, 15, 12 }, { 15, 19, 23, 28, 32, 35, 33, 30, 26, 21, 17, 14 }, { 17, 20, 24, 27, 31, 33, 31, 29, 25, 22, 18, 16 }, { 19, 21, 24, 26, 29, 30, 29, 28, 25, 22, 20, 19 }, { 20, 22, 24, 26, 28, 29, 28, 27, 25, 23, 20, 20 }, { 21, 22, 24, 26, 27, 28, 28, 26, 25, 23, 21, 20 }, { 22, 23, 24, 25, 26, 27, 27, 26, 24, 23, 22, 21 }, { 22, 23, 24, 25, 26, 27, 26, 26, 24, 23, 22, 22 }, { 23, 24, 24, 25, 25, 26, 26, 25, 24, 24, 23, 23 }, { 23, 24, 24, 25, 25, 26, 26, 25, 24, 24, 23, 23 }, { 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24 } },
      "sentinel" = -1,
      "audit_comment" = "the Table A8 daylight grid: 15 latitude rows (90/80/70 arctic, 65/60/55 subarctic, 50/40/35 temperate, 30/25/20 subtropical, 15/10/0 tropical) x 12 months, the hours of daylight stored in half-hour units",
    } },
  "chains" = { {
      "name" = "wwyCycloneDriftFor",
      "limits" = { 6, 7 },
      "tail" = 2,
      "arg" = "roll",
      "comment" = "the two-day drift after a cyclone: each day roll 2d6 - 6 or less drops the temperature 1 step (band 0), 7 holds it (band 1), 8 or higher raises it 1 step (band 2).",
    } },
  "examples" = { {
      "note" = "the book worked example: if Roll 1 was a 2 and Roll 2 is a 6, the SECOND letter of the cell code is indicated",
      "expr" = "m['wwtR2B56'](0) != 2",
    }, {
      "note" = "the book example: summer in a temperate forest - the cell code is GXMZ (the 6th row of the temperate block)",
      "expr" = "m['wwtA4Su'](13) != 4859",
    }, {
      "note" = "the settle: the temperate seacoast spring and summer cells carry the cyclone (three independent reads against the port uniform AXMZ)",
      "expr" = "m['wwtA4Sp'](17) != 2859 or m['wwtA4Su'](17) != 2859",
    }, {
      "note" = "the settle: the psm-6 swamp rows - subtropical swamp mirrors the subtropical seacoast (AXDZ CXMZ CXMZ AXDZ)",
      "expr" = "m['wwtA4Wi'](25) != 1839 or m['wwtA4Sp'](25) != 2859 or m['wwtA4Au'](25) != 1839",
    }, {
      "note" = "the settle: the inferred tropical swamp winter cell (the A-N-z-D glyph read decoded by the all-Z tropical winter fourth-letter pattern)",
      "expr" = "m['wwtA4Wi'](32) != 1859",
    }, {
      "note" = "the arctic desert is uniform GADD across all four seasons",
      "expr" = "m['wwtA4Wi'](0) != 4133 or m['wwtA4Sp'](0) != 4133 or m['wwtA4Su'](0) != 4133 or m['wwtA4Au'](0) != 4133",
    }, {
      "note" = "the Roll 1 = 12 / Roll 2 = 7 example: the third letter",
      "expr" = "m['wwtR2B7'](1) != 3",
    }, {
      "note" = "the X dispatch at 75+ degrees in the tropics: lightning on any sub-roll",
      "expr" = "m['wwtXDisTr1'](6) != 3 or m['wwtXDisTr6'](6) != 3",
    }, {
      "note" = "the X dispatch below zero in the temperate column: snow on 1-3, none on 4-6",
      "expr" = "m['wwtXDisTa1'](0) != 4 or m['wwtXDisTa4'](0) != 0",
    }, {
      "note" = "the Table A6 peak: 95+ degrees, saturated air, calm air (0-10 mph) - 25 degrees added to the actual temperature",
      "expr" = "m['wwtA6W0'](24) != 25",
    }, {
      "note" = "the wind chill anchors: 35 degrees at 5 mph is 35 effective; -45 at 40 mph is -120",
      "expr" = "m['wwtA7C0'](0) != 35 or m['wwtA7C7'](16) != -120",
    }, {
      "note" = "the equator daylight: 12 hours (24 half-hours) every month of the year",
      "expr" = "m['wwtA8M0'](14) != 24 or m['wwtA8M3'](14) != 24 or m['wwtA8M6'](14) != 24 or m['wwtA8M11'](14) != 24",
    }, {
      "note" = "the arctic pole: total darkness in month 1, total daylight in month 6",
      "expr" = "m['wwtA8M0'](0) != 0 or m['wwtA8M6'](0) != 48",
    }, {
      "note" = "the temperate seacoast humidity: HMMH in every season",
      "expr" = "m['wwtA5Wi'](17) != 3 or m['wwtA5Sp'](17) != 2 or m['wwtA5Su'](17) != 2 or m['wwtA5Au'](17) != 3",
    }, {
      "note" = "the humidity adjustment peak: medium-or-more precipitation both days raises the after-reading 2 steps",
      "expr" = "m['wwtHumAdjAfter2'](2) != 2",
    } },
  "audit" = {
      "label" = "R494 WSG weather effects audit",
      "comment" = "The Appendix: The World of Weather, part 2 of 2 - the special weather system and the effects on play, printed pp. 112-119. Table A4 with the Roll 1 / Roll 2 cross-index (the 2-or-12 carry-over, the fresh 2d6, the five bands and the 1st-2nd-3rd-4th letter selection, the running-episode suppression), the 33-row x 4-season special weather grid (one packed four-letter code per cell: cold wave, cyclone, drought, gale, mist/fog, sandstorm, tornado, extreme precipitation, heat wave). The per-code definitions: the no-special 2 and 12 days (the 45 mph very strong wind with the sharp drop, the 5 mph very slight wind with the sharp rise, the B-column precipitation), the cold wave and its heat wave mirror (2d6+2 days, 4 steps per day, the floor and ceiling one step beyond the normal extreme, the 10-degree beyond-extreme cap for 3 days, the automatic recovery with the 7-or-higher bonus rise), the cyclone (the 1d6x20+60 mph wind, the seacoast lightning herald, the 10-mile inland reach and 50-mile perimeter, the away-from-equator and coast-following movement, the double downpour, the 3-mile tidal wave, the 6-hour eye with its half-hour-to-hour dead calm, the second-half rainstorm, the 10-mph eye wind, the 3-day no-change-table window with the two-day 2d6 drift, the once-per-month 200-mile frequency cap with the extreme-precipitation fallback, the 5-degree equator exclusion), the drought (2d6+2 days, the day-1 shutoff, the once-per-5-days trace, the heavy-to-light-to-trace-to-none ladder), the gale (1d6x5+40 mph for 1d6+1 hours, the never-below-30 rule, the previous-20 boost, the desert and snow severe-sandstorm readings), the mist/fog (the sunrise/sunset 1-4/5-6 split, the 1d6 hours, the seacoast heavy reading, the suspended precipitation, the 50-percent adjacent spread), the sandstorm (the loose-material requirement, the no-precipitation day, the 1d4+1 and severe 1d6+1 durations), the tornado (the suitable-conditions and two-steps-above gates, the 1d3-hour front, the abrupt stop, the half-mile calm, the 3d6-minute delay, the 15-degrees-or-3-steps drop over 30 minutes, the quarter-by-15-mile path at 40 mph, the 200-300 mph vortex, the low-pressure explosion), the extreme precipitation dispatch (7 temperature bands x 2 climatic columns x the 1d6 sub-roll, the 25-degree ice footnote) and its four payloads: the hailstorm (the first-10-minutes-of-lightning rule, the 1-on-1d6 standalone, the 1d6+4 minutes, the quarter-inch stones to 2-3 inches, the 40-degree melt), the ice storm (the half-to-three-quarter-inch coating, the 20-minute heavy and 2-hour trace formation), the lightning storm (25 minutes, three-quarters-to-1 inch of rain, the dawn/dusk window, the disregarded standalone under moderate or light, the downpour start) and the severe snowstorm (the 1d6+4 and 1d6+6 inch falls at 1 inch per hour, the 1-2-hour calm then the 15-20 mph wind). The optional rules: the Table A5 humidity variation grid with the letter codes and their percentage bands, the day 1 / day 2 adjustment with the before and after slash pairs, the three-level fluctuation range with the dry and saturated edges and the two-level DM drop, the Table A6 humidity and effective temperature grid (25 rows x 5 wind columns, applied at 60 degrees and above), the Table A7 wind chill grid (17 x 8) with the below-minus-45 extrapolation and the 40-mph wind column cap, the Table A8 hours of daylight grid (15 latitude rows x 12 months, stored in half-hours) with the simplified middle-row option and the midnight/noon midpoint convention, the twilight spans (30 minutes at 30-40 degrees, 20 at the equator, 40 at 50-60, the 5-10-minute terrain cut, the all-day twilight where the daylight reads zero), the local winds (the sea breeze by day and the land breeze by night, the 5-10-mile inland reach, the clear-sky favor, the coastal chill, the cliff-face trap), the tides (the twice-daily alternation, the 12-hour highs and 6-hour lows, the 25-hour lunar day with the hour-a-day advance, the 28-day cycle, the spring and neap windows, the 5-7 and 15-18 foot ranges, the Fundy 60, the gentle/moderate/severe slope encroachment multiples with both worked examples) and the Dungeon Master responsibility (the 2-3-day determinations, the free timeframe switching, the multi-day predetermination).",
    },
}
