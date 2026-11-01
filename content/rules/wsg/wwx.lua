-- wwx: promoted from tools/spec_r493.json (the The WSG WORLD OF WEATHER, R493: the appendix part 1 - the weather GENERATION system, printed pp. 107-111 plus the extraordinary-precipitation tail from the top of p. 112: Table A1 (temperature variation), the letter codes, Table A2 (day-to-day change), Table A3 (precipitation variation) and the generation prose pins.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 493,
  "prefix" = "wwx",
  "banner" = {
      "title" = "The WSG WORLD OF WEATHER, R493: the appendix part 1 - the weather GENERATION system, printed pp. 107-111 plus the extraordinary-precipitation tail from the top of p. 112: Table A1 (temperature variation), the letter codes, Table A2 (day-to-day change), Table A3 (precipitation variation) and the generation prose pins.",
      "provenance" = "WSG printed pp. 107-111, pdf pages 108-112 with the tail from pdf page 113, extracted two-way at r493-extraction sha 5525680 (pdftotext layout + tesseract tsv) plus the 400-dpi psm-6 third reads at b60774f, settled three-way with two external corroborators (a fan transcription of the whole appendix and a fan python port, both accounted for their season-index shift, their subarctic-hills erratum and their tropical rotations). Base e84e00a, census 417 -> 418.",
      "sentinel" = "THE SETTLE: the A1 tsv read reconciles every layout garble (AD1->ADI, BE1->BEI, the merged temperate cells, OUW/OUX/SWZ, INU, I1KQ->IKQ, TwWZ->TWZ) and the psm-6 pass agrees cell for cell; the letter codes H-N and U-Z rest on the two external sources in exact agreement with every layout and prose anchor; the A2 body is unreadable in our three reads and is carried by the transcription, confirmed by the python port and by every psm-6 row it could read; the A2 roll-2/12 wind cells (Very strong / Very slight) are transcription-only and flagged in the header; the A3 transcription wins every fight our pdf could referee (the layout shows T-L-L for the subarctic hills summer against the port T-L-T, and the psm-6 pass confirms the subarctic, temperate and subtropical rows it read).",
    },
  "consts" = { {
      "name" = "wwxDayHours",
      "value" = 24,
      "comment" = "the basic assumptions: a day is 24 hours in duration.",
    }, {
      "name" = "wwxYearDays",
      "value" = 365,
      "comment" = "a year is 365 days in length, or thereabouts.",
    }, {
      "name" = "wwxYearDaysShort",
      "value" = 360,
      "comment" = "the calendar option many Dungeon Masters prefer: twelve identical months of 30 days each, 360 days.",
    }, {
      "name" = "wwxMonthsPerSeason",
      "value" = 3,
      "comment" = "each of the four seasons is further divided into three months.",
    }, {
      "name" = "wwxSeasonsPerYear",
      "value" = 4,
      "comment" = "each year is divided into four seasons.",
    }, {
      "name" = "wwxMonthsPerYear",
      "value" = 12,
      "comment" = "twelve months per year under either calendar.",
    }, {
      "name" = "wwxPoleLat",
      "value" = 90,
      "comment" = "the pole: the arctic climate prevails from 90 degrees, the north or south pole.",
    }, {
      "name" = "wwxArcticLoLat",
      "value" = 66,
      "comment" = "the approximate location of the Arctic Circle: the arctic climate extends from the pole to 66 degrees latitude.",
    }, {
      "name" = "wwxSubarcticHiLat",
      "value" = 65,
      "comment" = "the subarctic climate is typical of areas from 65 degrees latitude (in the northern hemisphere the southern boundary roughly describes the border between the United States and Canada).",
    }, {
      "name" = "wwxSubarcticLoLat",
      "value" = 51,
      "comment" = "the subarctic runs to 51.",
    }, {
      "name" = "wwxTemperateHiLat",
      "value" = 50,
      "comment" = "the temperate climate extends from 50 degrees latitude (the line roughly describing the border between the United States and Mexico).",
    }, {
      "name" = "wwxTemperateLoLat",
      "value" = 31,
      "comment" = "the temperate runs to 31.",
    }, {
      "name" = "wwxSubtropHiLat",
      "value" = 30,
      "comment" = "the subtropical climate predominates from 30 degrees (a line along the southern edge of Mexico).",
    }, {
      "name" = "wwxSubtropLoLat",
      "value" = 16,
      "comment" = "the subtropical runs to 16.",
    }, {
      "name" = "wwxTropicHiLat",
      "value" = 15,
      "comment" = "the tropical climate is the area from 15 degrees.",
    }, {
      "name" = "wwxEquatorLat",
      "value" = 0,
      "comment" = "the tropics run to the equator.",
    }, {
      "name" = "wwxArcticWindLightMph",
      "value" = 15,
      "comment" = "the arctic winds generally blow from east to west and seldom reach greater than moderate velocity - the low bound of the 15-20 mph band.",
    }, {
      "name" = "wwxArcticWindModMph",
      "value" = 20,
      "comment" = "the arctic wind ceiling except during storms, and the Day-to-Day footnote bound: wind velocity in arctic and tropical climatic regions does not exceed 20 mph except in special conditions.",
    }, {
      "name" = "wwxSubarcticWindMaxLoMph",
      "value" = 25,
      "comment" = "the Day-to-Day footnote: in subarctic climate 25-30 mph is the normal maximum - the low bound.",
    }, {
      "name" = "wwxSubarcticWindMaxHiMph",
      "value" = 30,
      "comment" = "the subarctic normal-maximum high bound.",
    }, {
      "name" = "wwxWindCeilingMph",
      "value" = 45,
      "comment" = "except in special circumstances the wind velocity will not increase beyond 45 mph.",
    }, {
      "name" = "wwxTempCodeCount",
      "value" = 26,
      "comment" = "the letter scale runs A through Z, one row per letter.",
    }, {
      "name" = "wwxA1Count",
      "value" = 30,
      "comment" = "the Table A1 grid: 5 climatic regions x 6 terrain rows, 30 rows; the arctic forest row is blank.",
    }, {
      "name" = "wwxElevDesertFt",
      "value" = 0,
      "comment" = "the temperature figures for desert assume an elevation of sea level.",
    }, {
      "name" = "wwxElevPlainForestFt",
      "value" = 500,
      "comment" = "plains and forest figures assume 500 feet.",
    }, {
      "name" = "wwxElevHillsFt",
      "value" = 2000,
      "comment" = "hills assume 2000 feet.",
    }, {
      "name" = "wwxElevMountainsFt",
      "value" = 4000,
      "comment" = "mountains assume 4000 feet.",
    }, {
      "name" = "wwxDegreesPer1000Ft",
      "value" = 3,
      "comment" = "if the terrain exists at a different elevation, subtract 3 degrees from the temperature figures for every increase of 1000 feet (or add 3 degrees for every decrease of 1000 feet) for a more accurate determination.",
    }, {
      "name" = "wwxA2Count",
      "value" = 11,
      "comment" = "the Table A2 grid: the 2d6 roll 2 through 12, 11 rows.",
    }, {
      "name" = "wwxRestOfDayDivisor",
      "value" = 2,
      "comment" = "wind velocity is the highest speed reached during gusts lasting a few seconds to a few minutes; for the rest of the day the speed will be no more than half the indicated maximum.",
    }, {
      "name" = "wwxA3Count",
      "value" = 33,
      "comment" = "the Table A3 grid: the arctic block carries 5 rows (no forest, no swamp), every other climate 7 - 33 rows x 12 columns.",
    }, {
      "name" = "wwxTraceRainEighthInch",
      "value" = 1,
      "comment" = "trace: less than 1/8 inch of rain.",
    }, {
      "name" = "wwxTraceSnowHalfInch",
      "value" = 1,
      "comment" = "trace: 1/2 inch of snow.",
    }, {
      "name" = "wwxLightRainHalfInch",
      "value" = 1,
      "comment" = "light: up to 1/2 inch of rain.",
    }, {
      "name" = "wwxLightSnowInch",
      "value" = 1,
      "comment" = "light: up to 1 inch of snow.",
    }, {
      "name" = "wwxModerateRainQuarterInch",
      "value" = 3,
      "comment" = "moderate: up to 3/4 inch of rain.",
    }, {
      "name" = "wwxModerateSnowInch",
      "value" = 2,
      "comment" = "moderate: up to 2 inches of snow.",
    }, {
      "name" = "wwxHeavyRainHalfInch",
      "value" = 3,
      "comment" = "heavy: up to 1 1/2 inches of rain.",
    }, {
      "name" = "wwxHeavySnowInch",
      "value" = 4,
      "comment" = "heavy: up to 4 inches of snow.",
    }, {
      "name" = "wwxDownpourRainHalfInch",
      "value" = 3,
      "comment" = "downpour: more than 1 1/2 inches of rain (no snow figure is given - downpour precipitation occurs in certain terrain in subtropical and tropical climates).",
    }, {
      "name" = "wwxRainMinF",
      "value" = 36,
      "comment" = "if the current temperature is 36 degrees or higher, rain will fall.",
    }, {
      "name" = "wwxSleetHiF",
      "value" = 35,
      "comment" = "the sleet band runs from 30 to 35 degrees inclusive - the high bound.",
    }, {
      "name" = "wwxSleetLoF",
      "value" = 30,
      "comment" = "the sleet band low bound.",
    }, {
      "name" = "wwxSleetD6Max",
      "value" = 3,
      "comment" = "in the 30-35 band sleet results half the time (1-3 on d6, or the DM discretion) and snow the other half.",
    }, {
      "name" = "wwxOunceTenthCuIn",
      "value" = 18,
      "comment" = "an ounce of water occupies about 1.8 cubic inches of volume - pinned in tenths.",
    }, {
      "name" = "wwxInchRainCuIn",
      "value" = 113,
      "comment" = "liquid collected in a circular container has volume pi x r squared x h; one inch of rain collected in a 6-inch-radius container yields about 113 cubic inches of water.",
    }, {
      "name" = "wwxInchRainOz",
      "value" = 63,
      "comment" = "the 113 cubic inches come to about 63 ounces of water, or roughly one-half gallon.",
    }, {
      "name" = "wwxBoxCuIn",
      "value" = 24,
      "comment" = "for a square or rectangular container the volume is the product of the three dimensions: a metal box 6 inches by 4 inches by at least 1 inch deep in a 1-inch rainfall holds 6 x 4 x 1 = 24 cubic inches.",
    }, {
      "name" = "wwxBoxOz",
      "value" = 13,
      "comment" = "the 24 cubic inches amount to roughly 13 fluid ounces, somewhat less than a pint.",
    }, {
      "name" = "wwxSnowMeltRatio",
      "value" = 10,
      "comment" = "melted snow converts to water at a rate of 10 to 1: one inch of fresh snow, collected and melted, yields the same liquid as a rainfall of 1/10 inch.",
    }, {
      "name" = "wwxTraceMinutes",
      "value" = 30,
      "comment" = "trace precipitation accumulates to a measurable amount only if the rain falls continuously for at least half an hour.",
    }, {
      "name" = "wwxDesertTraceTenths",
      "value" = 1,
      "comment" = "in a desert, only one out of every ten trace rainfalls will last more than a few minutes.",
    }, {
      "name" = "wwxTracePanOz",
      "value" = 8,
      "comment" = "the heaviest possible trace accumulation, just short of 1/10 inch of rain, even if collected in something as large as a cooking pan 1 foot in diameter, yields less than eight fluid ounces.",
    }, {
      "name" = "wwxTracePanTenthInch",
      "value" = 1,
      "comment" = "the trace ceiling in the intensity prose: just short of 1/10 inch (the letter-code footnote reads less than 1/8 inch - both figures are printed, pinned side by side).",
    }, {
      "name" = "wwxHeavyStormWindowHours",
      "value" = 2,
      "comment" = "heavy precipitation almost always falls in a relatively short time as the result of storm conditions, and in most cases those conditions occur at dawn or dusk - within two hours either way of sunrise or sunset.",
    }, {
      "name" = "wwxDownpourBurstInch",
      "value" = 1,
      "comment" = "the downpour pattern: a period of intense rain during which as much as an inch of water may fall in a half-hour or less, at any time of the day or night.",
    }, {
      "name" = "wwxDownpourBurstMinutes",
      "value" = 30,
      "comment" = "the intense burst lasts a half-hour or less, sandwiched between two periods of lighter, more prolonged precipitation.",
    }, {
      "name" = "wwxExtraDoublesRun",
      "value" = 2,
      "comment" = "whenever two successive rolls on the Day-to-Day Change Table are doubles, and no special weather occurs on either day, the check applies.",
    }, {
      "name" = "wwxExtraD6Lo",
      "value" = 1,
      "comment" = "the extraordinary chance: 50 percent - 1-3 on d6, or the DM discretion.",
    }, {
      "name" = "wwxExtraD6Hi",
      "value" = 3,
      "comment" = "the high bound of the d6 band.",
    }, {
      "name" = "wwxExtraStepUp",
      "value" = 1,
      "comment" = "on a hit, the precipitation for the second day is one step greater than the result given on the Precipitation Variation Table for a roll of doubles.",
    } },
  "bools" = { {
      "name" = "wwxEarthlikeWorld",
      "value" = true,
      "comment" = "the system is designed for a world similar, if not identical, to our Earth, assuming most campaign worlds are Earthlike in their fundamental natures.",
    }, {
      "name" = "wwxCounterclockwiseFromNorthPole",
      "value" = true,
      "comment" = "the planet rotates in a counterclockwise direction, as viewed from a point above the north pole.",
    }, {
      "name" = "wwxWindFromWhence",
      "value" = true,
      "comment" = "wind direction is the direction the wind is coming from: a north wind blows from north to south, not the other way around.",
    }, {
      "name" = "wwxTwoTablesOneRoll",
      "value" = true,
      "comment" = "the basic structure: consult only two tables and make a single dice roll to determine the temperature, wind speed and direction, and precipitation for any day except one on which a special weather phenomenon takes place.",
    }, {
      "name" = "wwxOptionalPartsSkippable",
      "value" = true,
      "comment" = "parts of the system, such as the sections on wind chill and humidity, can be disregarded if the Dungeon Master prefers even more simplicity.",
    }, {
      "name" = "wwxEffectsLiveInFirstSection",
      "value" = true,
      "comment" = "the system determines conditions but does not explicitly describe the effects in game terms - information on the effects of weather is presented in the first section of this book, for both players and Dungeon Masters.",
    }, {
      "name" = "wwxScrubRoughAsPlainOrForest",
      "value" = true,
      "comment" = "the DMG terrain translation: consider scrub and rough areas the same (for weather determination) as plain or forest, depending on which of those two the terrain most closely resembles.",
    }, {
      "name" = "wwxSevenTerrainTypes",
      "value" = true,
      "comment" = "the system considers seven distinct types of terrain as defined in the first part of this book: desert, forest, hills, mountains, plains, seacoast and swamp.",
    }, {
      "name" = "wwxArcticMidnightSun",
      "value" = true,
      "comment" = "the arctic midnight sun: because the planet rotates around an axis tilted with respect to the sun, there is a period each year in spring and summer when the arctic region is in continual daylight.",
    }, {
      "name" = "wwxArcticNoonMoon",
      "value" = true,
      "comment" = "the converse: the long arctic winter night, when for an equal length of time in autumn and winter the region is tilted away and in constant twilight. At all latitudes except right at the equator the daylight length varies; only in the arctic are the extremes realized (see the Hours of Daylight Table in the Optional Rules section, the R494 slice).",
    }, {
      "name" = "wwxArcticWindsEastToWest",
      "value" = true,
      "comment" = "the winds in the arctic generally blow from east to west.",
    }, {
      "name" = "wwxArcticPrecipVeryLight",
      "value" = true,
      "comment" = "precipitation in the arctic is usually very light if it exists at all; time of year makes no appreciable difference and terrain distinctions are mostly irrelevant since everything is covered with ice.",
    }, {
      "name" = "wwxArcticForestImpossible",
      "value" = true,
      "comment" = "temperatures for an arctic forest area are not given on the Temperature Variation Table, since vegetation of the normal sort cannot survive in this climate - hence the blank row.",
    }, {
      "name" = "wwxSubarcticWinterWindArcticAngle",
      "value" = true,
      "comment" = "the subarctic winds in the winter usually blow from the arctic or on a westerly angle from the arctic (northwest in the northern hemisphere, southwest in the southern hemisphere).",
    }, {
      "name" = "wwxSubarcticSummerWindWesterly",
      "value" = true,
      "comment" = "the subarctic summer wind is more often a prevailing westerly or tropical west wind (southwest in the northern hemisphere, northwest in the southern hemisphere).",
    }, {
      "name" = "wwxTemperateWindSeldomEast",
      "value" = true,
      "comment" = "temperate winds can blow from the north, south or west, but almost never from the east, except along eastern seacoasts and in localized areas such as the Lake Michigan breeze (see Local Winds in the Optional Rules section, the R494 slice).",
    }, {
      "name" = "wwxSubtropicalTradeWinds",
      "value" = true,
      "comment" = "subtropical winds are highly variable in velocity and generally blow from the east or from the east and toward the equator - the trade winds that explorers from Europe took advantage of on their journeys to the New World.",
    }, {
      "name" = "wwxTropicalWindsDocileTrade",
      "value" = true,
      "comment" = "tropical winds are generally docile (except during storms) and most often blow in the same direction as the subtropical trade winds.",
    }, {
      "name" = "wwxSwampBareIsPlain",
      "value" = true,
      "comment" = "the swamp translation when the category is not specifically mentioned (such as on the Temperature Variation Table): a swamp devoid of large vegetation is a plain.",
    }, {
      "name" = "wwxSwampTreesIsForest",
      "value" = true,
      "comment" = "a swamp containing trees or other large vegetation is a forest.",
    }, {
      "name" = "wwxSwampOceanIsSeacoast",
      "value" = true,
      "comment" = "a swamp adjacent to the ocean is seacoast.",
    }, {
      "name" = "wwxMmiiColdSplitsSubarctic",
      "value" = true,
      "comment" = "the Monster Manual II mesh (it considers only cold, temperate and tropical): divide the subarctic and subtropical areas in half, so monsters of a cold climate occur in the arctic and the part of the subarctic adjacent thereto.",
    }, {
      "name" = "wwxMmiiTemperateTakesTheHalves",
      "value" = true,
      "comment" = "monsters of a temperate climate occur in any area between the two extremes: the temperate area plus the adjacent half of the subarctic and the adjacent half of the subtropical.",
    }, {
      "name" = "wwxMmiiTropicalSplitsSubtropical",
      "value" = true,
      "comment" = "monsters of a tropical climate occur in the tropics and the adjacent half of the subtropical area.",
    }, {
      "name" = "wwxWinterMonthsAreTwelveOneTwo",
      "value" = true,
      "comment" = "the Table A1 month header groups winter as months 12, 1 and 2; spring 3-5, summer 6-8, autumn 9-11.",
    }, {
      "name" = "wwxRoll2WindVeryStrong",
      "value" = true,
      "comment" = "the roll-2 wind condition reads Very Strong - no numeric increment, consult the Special Weather Table (the R494 slice). NOTE THE SETTLE: this cell is unreadable in all three of our pdf reads and rests on the external transcription.",
    }, {
      "name" = "wwxRoll12WindVerySlight",
      "value" = true,
      "comment" = "the roll-12 wind condition reads Very Slight - the same consult-the-Special-Weather-Table footnote, and the same settle caveat as the roll-2 cell.",
    }, {
      "name" = "wwxDistinctDice",
      "value" = true,
      "comment" = "roll 2d6 for each day beyond the present one, day by day or for a number of days in succession; use two dice different in color or size, designated die 1 and die 2 - the distinction matters whenever there is a chance of precipitation.",
    }, {
      "name" = "wwxStopAtExtreme",
      "value" = true,
      "comment" = "temperature change: move up or down the letter scale as required; if the present temperature is within the allowable range (the first and third letters of the temperature code) but the move would take the result beyond that range, stop when the extreme result is reached.",
    }, {
      "name" = "wwxUpperLimitPlusNoChange",
      "value" = true,
      "comment" = "if the current temperature is already at the upper limit, treat any plus result as no change.",
    }, {
      "name" = "wwxLimitRoll7As6",
      "value" = true,
      "comment" = "at the upper limit, treat a roll of 7 the same as a roll of 6 - the temperature drops by 1 step and precipitation is possible.",
    }, {
      "name" = "wwxStreakTwoDays7Or8As6",
      "value" = true,
      "comment" = "if the temperature remains at the upper limit for two consecutive days, treat a roll of 7 or 8 as a roll of 6, and continue this pattern until the streak of hot weather ends.",
    }, {
      "name" = "wwxColdStreakMirror",
      "value" = true,
      "comment" = "for a streak of cold weather, perform the same process with the other end of the table.",
    }, {
      "name" = "wwxRoll2Or12ConsultSpecial",
      "value" = true,
      "comment" = "if the dice roll on the Day-to-Day Change Table is 2 or 12, follow the normal procedure for temperature change, chance of precipitation and wind conditions, and then refer to the Special Weather Table (page 112, the R494 slice) to see if some extraordinary weather occurs.",
    }, {
      "name" = "wwxPrecipConsultOnEvenRolls",
      "value" = true,
      "comment" = "if the roll of 2d6 on the Day-to-Day Change Table is an even number, refer to the Precipitation Variation Table to determine whether precipitation occurs and how much falls during the next 24 hours.",
    }, {
      "name" = "wwxPrecipDieColumns",
      "value" = true,
      "comment" = "on a yes result, take the Precipitation Variation column A if die 1 is greater than die 2, column B if the dice are equal, and column C if die 2 is greater than die 1.",
    }, {
      "name" = "wwxWindUsedOn3To11",
      "value" = true,
      "comment" = "on a dice roll of 3 through 11 the wind conditions column determines the direction and velocity of the wind.",
    }, {
      "name" = "wwxArcticWindHemisphere",
      "value" = true,
      "comment" = "a wind from the arctic is a north wind in the northern hemisphere and a south wind in the southern hemisphere; the reverse is true for a wind from the tropics.",
    }, {
      "name" = "wwxWindIncrementFromPrevious",
      "value" = true,
      "comment" = "the velocity increment (+15 mph, +10 mph, etc.) is added to the wind velocity for the previous day; the prevailing direction is as described in the climatic regions text.",
    }, {
      "name" = "wwxWindNeverBelowZero",
      "value" = true,
      "comment" = "wind velocity cannot fall below zero.",
    }, {
      "name" = "wwxGustsSecondsToMinutes",
      "value" = true,
      "comment" = "wind velocity is the highest speed the wind will reach on the day in question, during gusts that can last anywhere from a few seconds to a few minutes.",
    }, {
      "name" = "wwxSnowBelow30",
      "value" = true,
      "comment" = "at a temperature lower than 30 degrees, the precipitation will be a snowfall.",
    }, {
      "name" = "wwxSnowOnTheGround",
      "value" = true,
      "comment" = "the melt ratio is not especially relevant to collecting drinking water: in most cases when a snowfall occurs the precipitation stays on the ground, from where it can be gathered, and there will usually already be snow cover to scavenge - it is not difficult to obtain drinking water during the snowy season in any climate that has one.",
    }, {
      "name" = "wwxDesertTraceFutile",
      "value" = true,
      "comment" = "collecting water from a trace rainfall is fruitless except in cases of dire need; in a desert any liquid precipitation quickly soaks through the sandy or rocky soil or evaporates in hot temperatures almost as quickly.",
    }, {
      "name" = "wwxLightReadConservatively",
      "value" = true,
      "comment" = "light precipitation should be interpreted very conservatively in terrain/climate areas where it represents the greatest amount of rain or snow that normally falls in a day: most such rainfalls are scarcely greater than trace. The converse does not apply where light is the least precipitation possible - there the accumulation can range through the entire span of possibilities.",
    }, {
      "name" = "wwxModerateVaries",
      "value" = true,
      "comment" = "moderate precipitation does not always fall under moderate conditions: continuous drizzle for most or all of a day, or a storm of only a few minutes; where moderate is the normal maximum, the accumulation is usually not much greater than light and falls as gentle, prolonged rain instead of a brief storm.",
    }, {
      "name" = "wwxHeavyAtDawnDusk",
      "value" = true,
      "comment" = "heavy precipitation almost always falls in a relatively short time under storm conditions at dawn or dusk, in contrast with the lighter accumulations, which can occur at any time of day or night.",
    }, {
      "name" = "wwxDownpourOnlySubtropicalTropical",
      "value" = true,
      "comment" = "downpour precipitation occurs in certain terrain in subtropical and tropical climates only.",
    }, {
      "name" = "wwxExtraNoTemperateForestSummerDownpour",
      "value" = true,
      "comment" = "a downpour will never occur during summer in a temperate forest, regardless of how many times in a row the dice come up doubles - the printed book itself carries the one-in-three erratum in the tail sentence where the rule reads 50 percent.",
    }, {
      "name" = "wwxExtraCapsAtDownpour",
      "value" = true,
      "comment" = "in no case can extraordinary precipitation exceed the level of a downpour.",
    }, {
      "name" = "wwxExtraTwoDoublesThenHold",
      "value" = true,
      "comment" = "if doubles are rolled more than twice in succession, the precipitation does not continue to increase but remains at the one-step-greater level, and the d6 chance does not have to be checked any more.",
    }, {
      "name" = "wwxSecondLetterStart",
      "value" = true,
      "comment" = "at the beginning of an adventure or an episode (such as when player characters find themselves abruptly transported to a different area), use the second letter of the Table A1 code to ascertain the current temperature conditions; from this starting point the temperature moves up or down on a daily basis per the Day-to-Day Change Table.",
    }, {
      "name" = "wwxLowBeforeSunrise",
      "value" = true,
      "comment" = "as a general rule, the lowest temperature of the day occurs just before sunrise, and the reading gradually rises until the high is reached.",
    }, {
      "name" = "wwxHighEarlyAfternoon",
      "value" = true,
      "comment" = "the high temperature for the day is reached in early afternoon, possibly remaining at the high point for a few hours at the DM discretion; the reading then decreases gradually through the evening and night until the next low point just before sunrise - modified or disregarded in special weather conditions or when the DM judges different times should prevail.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "wwxTempCodes",
      "tag" = "TC",
      "count" = "wwxTempCodeCount",
      "cols" = { "wwsTempCodeHi", "wwsTempCodeLo" },
      "data" = { { -20, -40 }, { -15, -30 }, { -5, -20 }, { 0, -10 }, { 10, 0 }, { 18, 10 }, { 25, 10 }, { 30, 15 }, { 35, 15 }, { 40, 20 }, { 50, 30 }, { 60, 40 }, { 65, 45 }, { 70, 50 }, { 70, 55 }, { 75, 55 }, { 80, 60 }, { 80, 65 }, { 85, 65 }, { 85, 70 }, { 90, 70 }, { 90, 75 }, { 95, 75 }, { 100, 80 }, { 105, 80 }, { 115, 85 } },
      "col_comments" = { "the high temperature of the letter scale row (the letter code table, printed p. 108)", "the low temperature of the letter scale row" },
      "sentinel" = -99,
      "col_default" = -99,
    }, {
      "name" = "wwxA1Lo",
      "tag" = "A1L",
      "count" = "wwxA1Count",
      "cols" = { "wwsA1LoM01", "wwsA1LoM02", "wwsA1LoM03", "wwsA1LoM04", "wwsA1LoM05", "wwsA1LoM06", "wwsA1LoM07", "wwsA1LoM08", "wwsA1LoM09", "wwsA1LoM10", "wwsA1LoM11", "wwsA1LoM12" },
      "data" = { { 0, 0, 0, 0, 2, 5, 9, 9, 5, 3, 0, 0 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 0, 0, 0, 0, 1, 2, 3, 3, 2, 2, 1, 0 }, { 0, 0, 0, 0, 1, 2, 3, 3, 2, 2, 1, 0 }, { 0, 0, 0, 0, 2, 5, 9, 9, 5, 3, 0, 0 }, { 0, 0, 0, 0, 2, 5, 9, 9, 4, 2, 0, 0 }, { 0, 0, 1, 2, 5, 9, 10, 9, 6, 5, 2, 0 }, { 0, 0, 1, 3, 7, 9, 10, 9, 8, 4, 1, 0 }, { 0, 0, 1, 2, 5, 9, 9, 8, 6, 3, 1, 0 }, { 0, 0, 0, 1, 4, 8, 9, 8, 6, 3, 1, 0 }, { 0, 0, 1, 2, 5, 9, 10, 9, 6, 5, 2, 0 }, { 1, 1, 2, 3, 7, 9, 10, 10, 9, 4, 2, 0 }, { 10, 10, 11, 12, 12, 15, 20, 20, 16, 13, 11, 10 }, { 2, 1, 4, 7, 10, 12, 12, 12, 11, 9, 5, 3 }, { 1, 2, 4, 8, 9, 9, 11, 11, 10, 9, 5, 2 }, { 0, 1, 2, 4, 5, 10, 11, 10, 8, 4, 2, 1 }, { 1, 2, 3, 6, 10, 11, 12, 12, 10, 6, 4, 2 }, { 4, 5, 8, 10, 10, 11, 12, 12, 11, 10, 6, 4 }, { 11, 11, 12, 13, 14, 17, 19, 19, 17, 15, 13, 12 }, { 11, 11, 12, 13, 13, 15, 15, 15, 14, 13, 12, 11 }, { 10, 10, 11, 12, 13, 14, 15, 15, 13, 12, 11, 10 }, { 10, 10, 11, 11, 12, 13, 13, 13, 11, 11, 11, 10 }, { 11, 10, 12, 13, 17, 18, 19, 19, 18, 16, 12, 11 }, { 11, 10, 10, 11, 12, 12, 13, 13, 12, 11, 10, 10 }, { 15, 15, 15, 15, 16, 19, 21, 21, 20, 20, 17, 16 }, { 12, 11, 12, 14, 14, 16, 16, 16, 16, 15, 14, 12 }, { 12, 13, 13, 15, 15, 16, 18, 18, 18, 16, 14, 13 }, { 12, 13, 13, 14, 14, 14, 13, 13, 13, 13, 12, 12 }, { 12, 13, 13, 15, 17, 19, 19, 19, 19, 17, 15, 13 }, { 15, 15, 14, 16, 16, 17, 17, 17, 17, 16, 16, 15 } },
      "col_comments" = { "the Table A1 first letter - the lowest temperatures that will normally occur - for month 1 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 2 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 3 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 4 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 5 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 6 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 7 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 8 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 9 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 10 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 11 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row", "the Table A1 first letter - the lowest temperatures that will normally occur - for month 12 of the climate/terrain row, 0 = letter A, -1 = the blank arctic forest row" },
      "sentinel" = -1,
      "col_default" = -1,
      "sentinel_census" = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    }, {
      "name" = "wwxA1Mean",
      "tag" = "A1M",
      "count" = "wwxA1Count",
      "cols" = { "wwsA1MeanM01", "wwsA1MeanM02", "wwsA1MeanM03", "wwsA1MeanM04", "wwsA1MeanM05", "wwsA1MeanM06", "wwsA1MeanM07", "wwsA1MeanM08", "wwsA1MeanM09", "wwsA1MeanM10", "wwsA1MeanM11", "wwsA1MeanM12" },
      "data" = { { 1, 1, 2, 4, 6, 9, 10, 10, 7, 6, 3, 1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 1, 1, 2, 3, 4, 5, 6, 6, 5, 4, 4, 2 }, { 1, 1, 2, 3, 4, 5, 6, 6, 5, 4, 4, 2 }, { 1, 1, 2, 4, 6, 9, 10, 10, 7, 6, 3, 1 }, { 2, 1, 2, 4, 6, 9, 10, 10, 8, 6, 4, 2 }, { 3, 3, 4, 6, 10, 11, 12, 12, 10, 7, 4, 2 }, { 4, 4, 6, 9, 10, 11, 12, 12, 10, 9, 7, 5 }, { 3, 3, 5, 6, 10, 11, 12, 12, 10, 9, 6, 3 }, { 2, 3, 5, 7, 9, 10, 11, 12, 10, 9, 5, 3 }, { 3, 3, 4, 6, 10, 11, 12, 12, 10, 7, 4, 2 }, { 5, 6, 7, 9, 10, 11, 12, 12, 11, 10, 7, 5 }, { 12, 12, 12, 13, 15, 15, 24, 24, 22, 18, 17, 12 }, { 5, 5, 10, 11, 13, 15, 18, 18, 15, 13, 9, 9 }, { 8, 9, 10, 11, 14, 16, 19, 19, 16, 13, 10, 9 }, { 8, 8, 9, 10, 11, 14, 16, 16, 13, 11, 10, 9 }, { 7, 7, 10, 11, 13, 15, 18, 18, 15, 11, 10, 9 }, { 9, 10, 10, 11, 12, 14, 15, 15, 14, 11, 10, 10 }, { 15, 15, 18, 19, 19, 21, 23, 23, 20, 20, 18, 15 }, { 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 18, 18 }, { 13, 14, 16, 18, 19, 20, 20, 20, 18, 16, 15, 13 }, { 12, 12, 15, 15, 16, 16, 15, 14, 14, 13, 13, 12 }, { 13, 14, 17, 18, 21, 22, 22, 22, 21, 21, 17, 15 }, { 12, 12, 14, 15, 16, 18, 18, 18, 17, 16, 14, 12 }, { 17, 18, 19, 20, 21, 22, 24, 24, 23, 21, 20, 18 }, { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20 }, { 15, 15, 17, 17, 19, 20, 22, 22, 21, 19, 17, 16 }, { 15, 15, 16, 16, 16, 16, 15, 15, 15, 15, 15, 15 }, { 15, 16, 17, 17, 22, 22, 22, 22, 22, 21, 18, 17 }, { 18, 18, 19, 19, 19, 19, 19, 19, 19, 18, 18, 17 } },
      "col_comments" = { "the Table A1 second letter - the mean high and low temperatures - for month 1 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 2 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 3 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 4 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 5 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 6 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 7 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 8 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 9 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 10 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 11 of the climate/terrain row", "the Table A1 second letter - the mean high and low temperatures - for month 12 of the climate/terrain row" },
      "sentinel" = -1,
      "col_default" = -1,
      "sentinel_census" = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    }, {
      "name" = "wwxA1Hi",
      "tag" = "A1H",
      "count" = "wwxA1Count",
      "cols" = { "wwsA1HiM01", "wwsA1HiM02", "wwsA1HiM03", "wwsA1HiM04", "wwsA1HiM05", "wwsA1HiM06", "wwsA1HiM07", "wwsA1HiM08", "wwsA1HiM09", "wwsA1HiM10", "wwsA1HiM11", "wwsA1HiM12" },
      "data" = { { 6, 7, 7, 7, 10, 11, 13, 12, 10, 9, 7, 7 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 4, 3, 5, 6, 8, 8, 11, 10, 9, 7, 7, 4 }, { 4, 3, 5, 6, 8, 8, 11, 10, 9, 7, 7, 4 }, { 6, 7, 7, 7, 10, 11, 13, 12, 10, 9, 7, 7 }, { 7, 7, 7, 9, 10, 13, 15, 13, 11, 9, 8, 8 }, { 8, 9, 9, 9, 12, 13, 16, 16, 16, 12, 11, 8 }, { 9, 8, 10, 11, 13, 15, 17, 17, 15, 11, 10, 9 }, { 8, 8, 9, 9, 13, 13, 15, 15, 12, 11, 10, 9 }, { 8, 8, 9, 11, 12, 12, 13, 14, 12, 11, 10, 9 }, { 8, 9, 9, 9, 12, 13, 16, 16, 16, 12, 11, 8 }, { 10, 10, 10, 12, 13, 17, 17, 17, 15, 12, 11, 10 }, { 18, 19, 19, 22, 23, 25, 25, 25, 24, 23, 23, 17 }, { 11, 10, 15, 15, 20, 21, 23, 23, 21, 17, 11, 11 }, { 11, 12, 15, 17, 19, 23, 24, 24, 22, 19, 15, 12 }, { 11, 12, 13, 16, 18, 21, 23, 22, 20, 18, 17, 11 }, { 12, 13, 16, 18, 20, 23, 24, 24, 22, 18, 16, 12 }, { 12, 13, 16, 18, 19, 22, 23, 22, 22, 19, 15, 12 }, { 19, 20, 22, 23, 23, 24, 25, 25, 24, 24, 23, 22 }, { 20, 21, 21, 22, 23, 23, 23, 23, 22, 22, 21, 21 }, { 16, 17, 20, 21, 22, 23, 23, 24, 23, 21, 18, 17 }, { 15, 16, 18, 19, 20, 20, 19, 17, 17, 16, 16, 15 }, { 17, 18, 20, 23, 23, 24, 25, 25, 24, 24, 20, 18 }, { 20, 21, 22, 23, 23, 24, 24, 24, 23, 22, 20, 20 }, { 20, 19, 22, 23, 24, 25, 25, 25, 24, 23, 22, 21 }, { 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 22, 22 }, { 17, 19, 19, 20, 23, 24, 25, 25, 24, 22, 20, 19 }, { 17, 18, 19, 19, 20, 20, 19, 19, 19, 18, 18, 18 }, { 17, 19, 20, 20, 24, 24, 25, 25, 24, 24, 22, 20 }, { 20, 21, 22, 23, 23, 24, 23, 23, 22, 21, 21, 21 } },
      "col_comments" = { "the Table A1 third letter - the highest temperatures that will normally occur - for month 1 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 2 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 3 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 4 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 5 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 6 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 7 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 8 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 9 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 10 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 11 of the climate/terrain row", "the Table A1 third letter - the highest temperatures that will normally occur - for month 12 of the climate/terrain row" },
      "sentinel" = -1,
      "col_default" = -1,
      "sentinel_census" = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    }, {
      "name" = "wwxA2",
      "tag" = "A2",
      "count" = "wwxA2Count",
      "cols" = { "wwsA2Steps", "wwsA2Precip", "wwsA2WindDelta", "wwsA2WindFrom" },
      "data" = { { -3, 1, -99, 0 }, { -2, 0, 15, 1 }, { -2, 1, 10, 1 }, { -1, 0, 15, 2 }, { -1, 1, 10, 2 }, { 0, 2, 0, 4 }, { 1, 1, -10, 2 }, { 1, 0, -15, 2 }, { 2, 1, -10, 3 }, { 2, 0, -15, 3 }, { 3, 1, -99, 0 } },
      "col_comments" = { "the letter-scale temperature change in steps for the 2d6 roll (row 0 = roll 2)", "the chance of precipitation: 1 yes, 0 no, 2 same as the previous day", "the wind velocity increment added to the previous day in mph; -99 = the roll-2/roll-12 sentinel, consult the Special Weather Table", "the wind source: 0 special consult, 1 from the arctic, 2 prevailing direction, 3 from the tropics, 4 same as the previous day" },
      "sentinel" = -99,
      "col_default" = -99,
      "sentinel_census" = { 0, 0, 2, 0 },
    }, {
      "name" = "wwxA3",
      "tag" = "A3",
      "count" = "wwxA3Count",
      "cols" = { "wwsA3WiA", "wwsA3WiB", "wwsA3WiC", "wwsA3SpA", "wwsA3SpB", "wwsA3SpC", "wwsA3SuA", "wwsA3SuB", "wwsA3SuC", "wwsA3AuA", "wwsA3AuB", "wwsA3AuC" },
      "data" = { { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 }, { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 }, { 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 }, { 0, 1, 1, 0, 2, 1, 0, 3, 2, 0, 1, 1 }, { 0, 1, 0, 0, 2, 1, 0, 2, 1, 0, 2, 1 }, { 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0 }, { 0, 2, 1, 1, 3, 2, 1, 3, 2, 1, 2, 1 }, { 0, 1, 1, 0, 2, 1, 1, 2, 2, 0, 2, 1 }, { 0, 1, 1, 1, 3, 2, 1, 2, 1, 0, 2, 1 }, { 0, 2, 1, 1, 3, 2, 1, 3, 2, 1, 2, 1 }, { 0, 1, 1, 0, 2, 1, 1, 3, 2, 0, 2, 1 }, { 0, 2, 1, 1, 3, 2, 1, 2, 2, 1, 2, 2 }, { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 }, { 1, 3, 2, 2, 4, 3, 2, 3, 3, 2, 3, 3 }, { 1, 3, 2, 2, 4, 3, 2, 4, 3, 1, 3, 2 }, { 0, 3, 2, 0, 3, 2, 0, 2, 1, 0, 3, 2 }, { 0, 2, 1, 2, 4, 3, 2, 4, 3, 1, 3, 2 }, { 2, 4, 3, 1, 3, 2, 0, 2, 1, 2, 4, 3 }, { 1, 3, 2, 2, 4, 2, 2, 4, 3, 0, 3, 2 }, { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 }, { 3, 4, 4, 3, 5, 4, 3, 5, 4, 3, 4, 4 }, { 1, 2, 2, 2, 4, 3, 2, 4, 3, 1, 3, 2 }, { 1, 3, 2, 2, 4, 3, 2, 3, 3, 1, 3, 2 }, { 0, 2, 1, 1, 4, 2, 1, 3, 2, 0, 2, 1 }, { 1, 3, 2, 2, 4, 3, 2, 5, 3, 0, 2, 1 }, { 1, 2, 2, 1, 3, 2, 1, 4, 2, 1, 2, 2 }, { 0, 1, 0, 0, 2, 1, 0, 1, 0, 0, 1, 0 }, { 3, 5, 4, 3, 5, 4, 3, 5, 4, 3, 5, 4 }, { 0, 1, 0, 0, 2, 1, 1, 3, 2, 0, 1, 0 }, { 1, 3, 2, 3, 4, 4, 1, 3, 2, 3, 4, 4 }, { 0, 1, 0, 2, 4, 3, 3, 4, 3, 2, 4, 3 }, { 0, 1, 0, 2, 5, 3, 4, 5, 5, 0, 2, 1 }, { 0, 2, 1, 3, 4, 4, 3, 4, 3, 2, 3, 3 } },
      "col_comments" = { "the Table A3 cell for the winter season, column A (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the winter season, column B (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the winter season, column C (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the spring season, column A (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the spring season, column B (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the spring season, column C (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the summer season, column A (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the summer season, column B (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the summer season, column C (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the autumn season, column A (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the autumn season, column B (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour", "the Table A3 cell for the autumn season, column C (A if die 1 beats die 2, B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3 moderate, 4 heavy, 5 downpour" },
      "sentinel" = -99,
      "col_default" = -99,
    } },
  "chains" = { {
      "name" = "wwxPrecipFormFor",
      "limits" = { 29, 35 },
      "tail" = 2,
      "arg" = "tempF",
      "comment" = "the precipitation form dispatch on the current temperature in degrees Fahrenheit: band 0 = snow (below 30), band 1 = sleet-or-snow (30 to 35 inclusive, sleet on 1-3 of d6), band 2 = rain (36 and above).",
    } },
  "examples" = { {
      "note" = "the book own worked example: the subtropical plains seventh-month code is T W Z - the T low almost never below 70, the Z high up to 115, the W mean high 95 low 75",
      "expr" = "m['wwsA1LoM07'](22) != 19 or m['wwsA1MeanM07'](22) != 22 or m['wwsA1HiM07'](22) != 25",
    }, {
      "note" = "the book own worked example: a subarctic forest in the first month is A E J, and a roll of 12 from the E mean stops at the J upper limit, never K",
      "expr" = "m['wwsA1LoM01'](7) != 0 or m['wwsA1MeanM01'](7) != 4 or m['wwsA1HiM01'](7) != 9",
    }, {
      "note" = "the letter-scale anchors from the printed table and prose: A is -20/-40 and Z is 115/85",
      "expr" = "m['wwsTempCodeHi'](0) != -20 or m['wwsTempCodeLo'](0) != -40 or m['wwsTempCodeHi'](25) != 115 or m['wwsTempCodeLo'](25) != 85",
    }, {
      "note" = "the W anchor from the TWZ prose and the T anchor of the letter-code layout",
      "expr" = "m['wwsTempCodeHi'](22) != 95 or m['wwsTempCodeLo'](22) != 75 or m['wwsTempCodeHi'](19) != 85 or m['wwsTempCodeLo'](19) != 70",
    }, {
      "note" = "the roll-4 row: minus 2 steps, precipitation yes, wind from the arctic at +10 mph",
      "expr" = "m['wwsA2Steps'](2) != -2 or m['wwsA2Precip'](2) != 1 or m['wwsA2WindDelta'](2) != 10 or m['wwsA2WindFrom'](2) != 1",
    }, {
      "note" = "the roll-7 row: no temperature change, the same chance of precipitation, the same wind as the previous day",
      "expr" = "m['wwsA2Steps'](5) != 0 or m['wwsA2Precip'](5) != 2 or m['wwsA2WindDelta'](5) != 0 or m['wwsA2WindFrom'](5) != 4",
    }, {
      "note" = "the book own wind example: 15 mph today plus the roll-3 +15 increment makes 30 mph gusts tomorrow, the rest of the day no more than 15",
      "expr" = "m['wwsA2WindDelta'](1) != 15 or m['wwxRestOfDayDivisor']() != 2 or m['wwsA2Steps'](1) != -2",
    }, {
      "note" = "the book own extraordinary example: double 4s in a temperate forest summer is moderate rain, and double 3s with a 3 on the d6 is one step greater - heavy",
      "expr" = "m['wwsA3SuB'](13) != 3 or m['wwsA3SuB'](13) + m['wwxExtraStepUp']() != 4",
    }, {
      "note" = "the collecting arithmetic: 1 inch of rain in the 6-inch-radius cylinder is about 113 cubic inches = 63 ounces = roughly half a gallon, and the 6x4x1 box is 24 cubic inches = 13 fluid ounces",
      "expr" = "m['wwxInchRainCuIn']() != 113 or m['wwxInchRainOz']() != 63 or m['wwxBoxCuIn']() != 24 or m['wwxBoxOz']() != 13",
    }, {
      "note" = "the rain-sleet-snow dispatch: 36 and up is rain, 30 to 35 inclusive is the sleet-or-snow band, below 30 is snow",
      "expr" = "m['wwxPrecipFormFor'](36) != 2 or m['wwxPrecipFormFor'](35) != 1 or m['wwxPrecipFormFor'](30) != 1 or m['wwxPrecipFormFor'](29) != 0",
    }, {
      "note" = "the elevation baselines of the Table A1 footnote",
      "expr" = "m['wwxElevDesertFt']() != 0 or m['wwxElevPlainForestFt']() != 500 or m['wwxElevHillsFt']() != 2000 or m['wwxElevMountainsFt']() != 4000 or m['wwxDegreesPer1000Ft']() != 3",
    }, {
      "note" = "the precipitation letter values: light is up to 1/2 inch rain or 1 inch snow, moderate up to 3/4 rain or 2 snow, heavy up to 1 1/2 rain or 4 snow, downpour more than 1 1/2 rain",
      "expr" = "m['wwxLightRainHalfInch']() != 1 or m['wwxLightSnowInch']() != 1 or m['wwxModerateRainQuarterInch']() != 3 or m['wwxModerateSnowInch']() != 2 or m['wwxHeavyRainHalfInch']() != 3 or m['wwxHeavySnowInch']() != 4 or m['wwxDownpourRainHalfInch']() != 3",
    } },
  "audit" = {
      "label" = "R493 WSG weather generation audit",
      "comment" = "The Appendix: The World of Weather, part 1 of 2 - the generation system, printed pp. 107-111 plus the extraordinary-precipitation tail that completes the section from the top of printed p. 112. The opener: the Earthlike assumption, the 24-hour day, the 365-or-360 year, four seasons x three months, the counterclockwise rotation, degrees Fahrenheit, feet, mph, wind from whence it blows, the two-tables-one-roll basic structure. The five climatic regions with their latitude bands and wind characters, the seven terrain types, the swamp and scrub/rough translations, the Monster Manual II three-category mesh. The temperature letter codes (the 26-row high/low scale), the Table A1 grid (30 climate/terrain rows x 12 months x the low/mean/high letters, the blank arctic forest row), the Table A2 day-to-day grid (steps, precipitation yes/no/same, the wind increments and sources, the roll-2/12 special rows), the Table A3 precipitation grid (33 rows x 12 season/die-comparison cells). The usage prose: the second-letter start, the daily curve, the stop-at-extreme move, the upper-limit 7-as-6 and the two-day 7-or-8-as-6 streaks with the cold mirror, the die-1/die-2 discipline, the even-roll precipitation consult with the A/B/C columns, the 3-through-11 wind usage with the hemisphere rule, the gust seconds-to-minutes and the half-max rest of day, the 45-mph ceiling with the arctic/tropical 20 and subarctic 25-30 footnotes. The precipitation letter values, the rain-sleet-snow dispatch, the collecting arithmetic (the cylinder, the ounce, the box, the 10-to-1 snow melt), the intensity guidelines (the trace half-hour, the desert one-in-ten, the pan, the dawn/dusk storms, the downpour sandwich) and the extraordinary doubles rule (the 50 percent d6 step-up, the two-double run, the temperate-forest-summer downpour ban, the downpour cap).",
    },
}
