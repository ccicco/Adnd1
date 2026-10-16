// =========================================================================================
// Adnd1 - rules/wsgweather.h
// The WSG WORLD OF WEATHER, R493: the appendix part 1 - the weather
// GENERATION system, printed pp. 107-111 plus the extraordinary-precipitation
// tail from the top of p. 112: Table A1 (temperature variation), the letter
// codes, Table A2 (day-to-day change), Table A3 (precipitation variation) and
// the generation prose pins.
// census 417 -> 418.
//
// WSG printed pp. 107-111, pdf pages 108-112 with the tail from pdf page 113,
// extracted two-way at r493-extraction sha 5525680 (pdftotext layout +
// tesseract tsv) plus the 400-dpi psm-6 third reads at b60774f, settled
// three-way with two external corroborators (a fan transcription of the whole
// appendix and a fan python port, both accounted for their season-index
// shift, their subarctic-hills erratum and their tropical rotations). Base
// e84e00a, census 417 -> 418.
//
// THE SETTLE: the A1 tsv read reconciles every layout garble (AD1->ADI,
// BE1->BEI, the merged temperate cells, OUW/OUX/SWZ, INU, I1KQ->IKQ,
// TwWZ->TWZ) and the psm-6 pass agrees cell for cell; the letter codes H-N
// and U-Z rest on the two external sources in exact agreement with every
// layout and prose anchor; the A2 body is unreadable in our three reads and
// is carried by the transcription, confirmed by the python port and by every
// psm-6 row it could read; the A2 roll-2/12 wind cells (Very strong / Very
// slight) are transcription-only and flagged in the header; the A3
// transcription wins every fight our pdf could referee (the layout shows
// T-L-L for the subarctic hills summer against the port T-L-T, and the psm-6
// pass confirms the subarctic, temperate and subtropical rows it read).
//
namespace rules {

// ---- The appendix opener and the basic assumptions ----

// the basic assumptions: a day is 24 hours in duration.
inline int wwxDayHours()
    { return 24; }

// a year is 365 days in length, or thereabouts.
inline int wwxYearDays()
    { return 365; }

// the calendar option many Dungeon Masters prefer: twelve identical months of
// 30 days each, 360 days.
inline int wwxYearDaysShort()
    { return 360; }

// each of the four seasons is further divided into three months.
inline int wwxMonthsPerSeason()
    { return 3; }

// each year is divided into four seasons.
inline int wwxSeasonsPerYear()
    { return 4; }

// twelve months per year under either calendar.
inline int wwxMonthsPerYear()
    { return 12; }

// the system is designed for a world similar, if not identical, to our Earth,
// assuming most campaign worlds are Earthlike in their fundamental natures.
inline bool wwxEarthlikeWorld()
    { return true; }

// the planet rotates in a counterclockwise direction, as viewed from a point
// above the north pole.
inline bool wwxCounterclockwiseFromNorthPole()
    { return true; }

// wind direction is the direction the wind is coming from: a north wind blows
// from north to south, not the other way around.
inline bool wwxWindFromWhence()
    { return true; }

// the basic structure: consult only two tables and make a single dice roll to
// determine the temperature, wind speed and direction, and precipitation for
// any day except one on which a special weather phenomenon takes place.
inline bool wwxTwoTablesOneRoll()
    { return true; }

// parts of the system, such as the sections on wind chill and humidity, can
// be disregarded if the Dungeon Master prefers even more simplicity.
inline bool wwxOptionalPartsSkippable()
    { return true; }

// the system determines conditions but does not explicitly describe the
// effects in game terms - information on the effects of weather is presented
// in the first section of this book, for both players and Dungeon Masters.
inline bool wwxEffectsLiveInFirstSection()
    { return true; }

// the DMG terrain translation: consider scrub and rough areas the same (for
// weather determination) as plain or forest, depending on which of those two
// the terrain most closely resembles.
inline bool wwxScrubRoughAsPlainOrForest()
    { return true; }

// the system considers seven distinct types of terrain as defined in the
// first part of this book: desert, forest, hills, mountains, plains, seacoast
// and swamp.
inline bool wwxSevenTerrainTypes()
    { return true; }

// ---- Climatic regions ----

// the pole: the arctic climate prevails from 90 degrees, the north or south
// pole.
inline int wwxPoleLat()
    { return 90; }

// the approximate location of the Arctic Circle: the arctic climate extends
// from the pole to 66 degrees latitude.
inline int wwxArcticLoLat()
    { return 66; }

// the subarctic climate is typical of areas from 65 degrees latitude (in the
// northern hemisphere the southern boundary roughly describes the border
// between the United States and Canada).
inline int wwxSubarcticHiLat()
    { return 65; }

// the subarctic runs to 51.
inline int wwxSubarcticLoLat()
    { return 51; }

// the temperate climate extends from 50 degrees latitude (the line roughly
// describing the border between the United States and Mexico).
inline int wwxTemperateHiLat()
    { return 50; }

// the temperate runs to 31.
inline int wwxTemperateLoLat()
    { return 31; }

// the subtropical climate predominates from 30 degrees (a line along the
// southern edge of Mexico).
inline int wwxSubtropHiLat()
    { return 30; }

// the subtropical runs to 16.
inline int wwxSubtropLoLat()
    { return 16; }

// the tropical climate is the area from 15 degrees.
inline int wwxTropicHiLat()
    { return 15; }

// the tropics run to the equator.
inline int wwxEquatorLat()
    { return 0; }

// the arctic winds generally blow from east to west and seldom reach greater
// than moderate velocity - the low bound of the 15-20 mph band.
inline int wwxArcticWindLightMph()
    { return 15; }

// the arctic wind ceiling except during storms, and the Day-to-Day footnote
// bound: wind velocity in arctic and tropical climatic regions does not
// exceed 20 mph except in special conditions.
inline int wwxArcticWindModMph()
    { return 20; }

// the Day-to-Day footnote: in subarctic climate 25-30 mph is the normal
// maximum - the low bound.
inline int wwxSubarcticWindMaxLoMph()
    { return 25; }

// the subarctic normal-maximum high bound.
inline int wwxSubarcticWindMaxHiMph()
    { return 30; }

// except in special circumstances the wind velocity will not increase beyond
// 45 mph.
inline int wwxWindCeilingMph()
    { return 45; }

// the arctic midnight sun: because the planet rotates around an axis tilted
// with respect to the sun, there is a period each year in spring and summer
// when the arctic region is in continual daylight.
inline bool wwxArcticMidnightSun()
    { return true; }

// the converse: the long arctic winter night, when for an equal length of
// time in autumn and winter the region is tilted away and in constant
// twilight. At all latitudes except right at the equator the daylight length
// varies; only in the arctic are the extremes realized (see the Hours of
// Daylight Table in the Optional Rules section, the R494 slice).
inline bool wwxArcticNoonMoon()
    { return true; }

// the winds in the arctic generally blow from east to west.
inline bool wwxArcticWindsEastToWest()
    { return true; }

// precipitation in the arctic is usually very light if it exists at all; time
// of year makes no appreciable difference and terrain distinctions are mostly
// irrelevant since everything is covered with ice.
inline bool wwxArcticPrecipVeryLight()
    { return true; }

// temperatures for an arctic forest area are not given on the Temperature
// Variation Table, since vegetation of the normal sort cannot survive in this
// climate - hence the blank row.
inline bool wwxArcticForestImpossible()
    { return true; }

// the subarctic winds in the winter usually blow from the arctic or on a
// westerly angle from the arctic (northwest in the northern hemisphere,
// southwest in the southern hemisphere).
inline bool wwxSubarcticWinterWindArcticAngle()
    { return true; }

// the subarctic summer wind is more often a prevailing westerly or tropical
// west wind (southwest in the northern hemisphere, northwest in the southern
// hemisphere).
inline bool wwxSubarcticSummerWindWesterly()
    { return true; }

// temperate winds can blow from the north, south or west, but almost never
// from the east, except along eastern seacoasts and in localized areas such
// as the Lake Michigan breeze (see Local Winds in the Optional Rules section,
// the R494 slice).
inline bool wwxTemperateWindSeldomEast()
    { return true; }

// subtropical winds are highly variable in velocity and generally blow from
// the east or from the east and toward the equator - the trade winds that
// explorers from Europe took advantage of on their journeys to the New World.
inline bool wwxSubtropicalTradeWinds()
    { return true; }

// tropical winds are generally docile (except during storms) and most often
// blow in the same direction as the subtropical trade winds.
inline bool wwxTropicalWindsDocileTrade()
    { return true; }

// the swamp translation when the category is not specifically mentioned (such
// as on the Temperature Variation Table): a swamp devoid of large vegetation
// is a plain.
inline bool wwxSwampBareIsPlain()
    { return true; }

// a swamp containing trees or other large vegetation is a forest.
inline bool wwxSwampTreesIsForest()
    { return true; }

// a swamp adjacent to the ocean is seacoast.
inline bool wwxSwampOceanIsSeacoast()
    { return true; }

// the Monster Manual II mesh (it considers only cold, temperate and
// tropical): divide the subarctic and subtropical areas in half, so monsters
// of a cold climate occur in the arctic and the part of the subarctic
// adjacent thereto.
inline bool wwxMmiiColdSplitsSubarctic()
    { return true; }

// monsters of a temperate climate occur in any area between the two extremes:
// the temperate area plus the adjacent half of the subarctic and the adjacent
// half of the subtropical.
inline bool wwxMmiiTemperateTakesTheHalves()
    { return true; }

// monsters of a tropical climate occur in the tropics and the adjacent half
// of the subtropical area.
inline bool wwxMmiiTropicalSplitsSubtropical()
    { return true; }

// the Table A1 month header groups winter as months 12, 1 and 2; spring 3-5,
// summer 6-8, autumn 9-11.
inline bool wwxWinterMonthsAreTwelveOneTwo()
    { return true; }

// ---- The temperature letter codes ----

// the letter scale runs A through Z, one row per letter.
inline int wwxTempCodeCount()
    { return 26; }

// the high temperature of the letter scale row (the letter code table,
// printed p. 108)
inline int wwsTempCodeHi(int b)
    {
        switch (b) {
        case 0:
            return -20;
        case 1:
            return -15;
        case 2:
            return -5;
        case 3:
            return 0;
        case 4:
            return 10;
        case 5:
            return 18;
        case 6:
            return 25;
        case 7:
            return 30;
        case 8:
            return 35;
        case 9:
            return 40;
        case 10:
            return 50;
        case 11:
            return 60;
        case 12:
            return 65;
        case 13:
            return 70;
        case 14:
            return 70;
        case 15:
            return 75;
        case 16:
            return 80;
        case 17:
            return 80;
        case 18:
            return 85;
        case 19:
            return 85;
        case 20:
            return 90;
        case 21:
            return 90;
        case 22:
            return 95;
        case 23:
            return 100;
        case 24:
            return 105;
        case 25:
            return 115;
        default:
            return -99;
        }
    }

// the low temperature of the letter scale row
inline int wwsTempCodeLo(int b)
    {
        switch (b) {
        case 0:
            return -40;
        case 1:
            return -30;
        case 2:
            return -20;
        case 3:
            return -10;
        case 4:
            return 0;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 15;
        case 8:
            return 15;
        case 9:
            return 20;
        case 10:
            return 30;
        case 11:
            return 40;
        case 12:
            return 45;
        case 13:
            return 50;
        case 14:
            return 55;
        case 15:
            return 55;
        case 16:
            return 60;
        case 17:
            return 65;
        case 18:
            return 65;
        case 19:
            return 70;
        case 20:
            return 70;
        case 21:
            return 75;
        case 22:
            return 75;
        case 23:
            return 80;
        case 24:
            return 80;
        case 25:
            return 85;
        default:
            return -99;
        }
    }

// ---- Table A1: temperature variation ----

// the Table A1 grid: 5 climatic regions x 6 terrain rows, 30 rows; the arctic
// forest row is blank.
inline int wwxA1Count()
    { return 30; }

// the temperature figures for desert assume an elevation of sea level.
inline int wwxElevDesertFt()
    { return 0; }

// plains and forest figures assume 500 feet.
inline int wwxElevPlainForestFt()
    { return 500; }

// hills assume 2000 feet.
inline int wwxElevHillsFt()
    { return 2000; }

// mountains assume 4000 feet.
inline int wwxElevMountainsFt()
    { return 4000; }

// if the terrain exists at a different elevation, subtract 3 degrees from the
// temperature figures for every increase of 1000 feet (or add 3 degrees for
// every decrease of 1000 feet) for a more accurate determination.
inline int wwxDegreesPer1000Ft()
    { return 3; }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 1 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM01(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 10;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 4;
        case 18:
            return 11;
        case 19:
            return 11;
        case 20:
            return 10;
        case 21:
            return 10;
        case 22:
            return 11;
        case 23:
            return 11;
        case 24:
            return 15;
        case 25:
            return 12;
        case 26:
            return 12;
        case 27:
            return 12;
        case 28:
            return 12;
        case 29:
            return 15;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 2 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM02(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 10;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 5;
        case 18:
            return 11;
        case 19:
            return 11;
        case 20:
            return 10;
        case 21:
            return 10;
        case 22:
            return 10;
        case 23:
            return 10;
        case 24:
            return 15;
        case 25:
            return 11;
        case 26:
            return 13;
        case 27:
            return 13;
        case 28:
            return 13;
        case 29:
            return 15;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 3 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM03(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 11;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 8;
        case 18:
            return 12;
        case 19:
            return 12;
        case 20:
            return 11;
        case 21:
            return 11;
        case 22:
            return 12;
        case 23:
            return 10;
        case 24:
            return 15;
        case 25:
            return 12;
        case 26:
            return 13;
        case 27:
            return 13;
        case 28:
            return 13;
        case 29:
            return 14;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 4 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM04(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 12;
        case 13:
            return 7;
        case 14:
            return 8;
        case 15:
            return 4;
        case 16:
            return 6;
        case 17:
            return 10;
        case 18:
            return 13;
        case 19:
            return 13;
        case 20:
            return 12;
        case 21:
            return 11;
        case 22:
            return 13;
        case 23:
            return 11;
        case 24:
            return 15;
        case 25:
            return 14;
        case 26:
            return 15;
        case 27:
            return 14;
        case 28:
            return 15;
        case 29:
            return 16;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 5 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM05(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return -1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 5;
        case 7:
            return 7;
        case 8:
            return 5;
        case 9:
            return 4;
        case 10:
            return 5;
        case 11:
            return 7;
        case 12:
            return 12;
        case 13:
            return 10;
        case 14:
            return 9;
        case 15:
            return 5;
        case 16:
            return 10;
        case 17:
            return 10;
        case 18:
            return 14;
        case 19:
            return 13;
        case 20:
            return 13;
        case 21:
            return 12;
        case 22:
            return 17;
        case 23:
            return 12;
        case 24:
            return 16;
        case 25:
            return 14;
        case 26:
            return 15;
        case 27:
            return 14;
        case 28:
            return 17;
        case 29:
            return 16;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 6 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM06(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return -1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 9;
        case 7:
            return 9;
        case 8:
            return 9;
        case 9:
            return 8;
        case 10:
            return 9;
        case 11:
            return 9;
        case 12:
            return 15;
        case 13:
            return 12;
        case 14:
            return 9;
        case 15:
            return 10;
        case 16:
            return 11;
        case 17:
            return 11;
        case 18:
            return 17;
        case 19:
            return 15;
        case 20:
            return 14;
        case 21:
            return 13;
        case 22:
            return 18;
        case 23:
            return 12;
        case 24:
            return 19;
        case 25:
            return 16;
        case 26:
            return 16;
        case 27:
            return 14;
        case 28:
            return 19;
        case 29:
            return 17;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 7 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM07(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return -1;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 9;
        case 5:
            return 9;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 9;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 20;
        case 13:
            return 12;
        case 14:
            return 11;
        case 15:
            return 11;
        case 16:
            return 12;
        case 17:
            return 12;
        case 18:
            return 19;
        case 19:
            return 15;
        case 20:
            return 15;
        case 21:
            return 13;
        case 22:
            return 19;
        case 23:
            return 13;
        case 24:
            return 21;
        case 25:
            return 16;
        case 26:
            return 18;
        case 27:
            return 13;
        case 28:
            return 19;
        case 29:
            return 17;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 8 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM08(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return -1;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 9;
        case 5:
            return 9;
        case 6:
            return 9;
        case 7:
            return 9;
        case 8:
            return 8;
        case 9:
            return 8;
        case 10:
            return 9;
        case 11:
            return 10;
        case 12:
            return 20;
        case 13:
            return 12;
        case 14:
            return 11;
        case 15:
            return 10;
        case 16:
            return 12;
        case 17:
            return 12;
        case 18:
            return 19;
        case 19:
            return 15;
        case 20:
            return 15;
        case 21:
            return 13;
        case 22:
            return 19;
        case 23:
            return 13;
        case 24:
            return 21;
        case 25:
            return 16;
        case 26:
            return 18;
        case 27:
            return 13;
        case 28:
            return 19;
        case 29:
            return 17;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 9 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM09(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return -1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 4;
        case 6:
            return 6;
        case 7:
            return 8;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 9;
        case 12:
            return 16;
        case 13:
            return 11;
        case 14:
            return 10;
        case 15:
            return 8;
        case 16:
            return 10;
        case 17:
            return 11;
        case 18:
            return 17;
        case 19:
            return 14;
        case 20:
            return 13;
        case 21:
            return 11;
        case 22:
            return 18;
        case 23:
            return 12;
        case 24:
            return 20;
        case 25:
            return 16;
        case 26:
            return 18;
        case 27:
            return 13;
        case 28:
            return 19;
        case 29:
            return 17;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 10 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM10(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return -1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 5;
        case 7:
            return 4;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 5;
        case 11:
            return 4;
        case 12:
            return 13;
        case 13:
            return 9;
        case 14:
            return 9;
        case 15:
            return 4;
        case 16:
            return 6;
        case 17:
            return 10;
        case 18:
            return 15;
        case 19:
            return 13;
        case 20:
            return 12;
        case 21:
            return 11;
        case 22:
            return 16;
        case 23:
            return 11;
        case 24:
            return 20;
        case 25:
            return 15;
        case 26:
            return 16;
        case 27:
            return 13;
        case 28:
            return 17;
        case 29:
            return 16;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 11 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM11(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 11;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 2;
        case 16:
            return 4;
        case 17:
            return 6;
        case 18:
            return 13;
        case 19:
            return 12;
        case 20:
            return 11;
        case 21:
            return 11;
        case 22:
            return 12;
        case 23:
            return 10;
        case 24:
            return 17;
        case 25:
            return 14;
        case 26:
            return 14;
        case 27:
            return 12;
        case 28:
            return 15;
        case 29:
            return 16;
        default:
            return -1;
        }
    }

// the Table A1 first letter - the lowest temperatures that will normally
// occur - for month 12 of the climate/terrain row, 0 = letter A, -1 = the
// blank arctic forest row
inline int wwsA1LoM12(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 10;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 4;
        case 18:
            return 12;
        case 19:
            return 11;
        case 20:
            return 10;
        case 21:
            return 10;
        case 22:
            return 11;
        case 23:
            return 10;
        case 24:
            return 16;
        case 25:
            return 12;
        case 26:
            return 13;
        case 27:
            return 12;
        case 28:
            return 13;
        case 29:
            return 15;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 1 of the climate/terrain row
inline int wwsA1MeanM01(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return -1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 3;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 5;
        case 12:
            return 12;
        case 13:
            return 5;
        case 14:
            return 8;
        case 15:
            return 8;
        case 16:
            return 7;
        case 17:
            return 9;
        case 18:
            return 15;
        case 19:
            return 19;
        case 20:
            return 13;
        case 21:
            return 12;
        case 22:
            return 13;
        case 23:
            return 12;
        case 24:
            return 17;
        case 25:
            return 20;
        case 26:
            return 15;
        case 27:
            return 15;
        case 28:
            return 15;
        case 29:
            return 18;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 2 of the climate/terrain row
inline int wwsA1MeanM02(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return -1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 6;
        case 12:
            return 12;
        case 13:
            return 5;
        case 14:
            return 9;
        case 15:
            return 8;
        case 16:
            return 7;
        case 17:
            return 10;
        case 18:
            return 15;
        case 19:
            return 19;
        case 20:
            return 14;
        case 21:
            return 12;
        case 22:
            return 14;
        case 23:
            return 12;
        case 24:
            return 18;
        case 25:
            return 20;
        case 26:
            return 15;
        case 27:
            return 15;
        case 28:
            return 16;
        case 29:
            return 18;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 3 of the climate/terrain row
inline int wwsA1MeanM03(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return -1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 4;
        case 11:
            return 7;
        case 12:
            return 12;
        case 13:
            return 10;
        case 14:
            return 10;
        case 15:
            return 9;
        case 16:
            return 10;
        case 17:
            return 10;
        case 18:
            return 18;
        case 19:
            return 19;
        case 20:
            return 16;
        case 21:
            return 15;
        case 22:
            return 17;
        case 23:
            return 14;
        case 24:
            return 19;
        case 25:
            return 20;
        case 26:
            return 17;
        case 27:
            return 16;
        case 28:
            return 17;
        case 29:
            return 19;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 4 of the climate/terrain row
inline int wwsA1MeanM04(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return -1;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 6;
        case 7:
            return 9;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 6;
        case 11:
            return 9;
        case 12:
            return 13;
        case 13:
            return 11;
        case 14:
            return 11;
        case 15:
            return 10;
        case 16:
            return 11;
        case 17:
            return 11;
        case 18:
            return 19;
        case 19:
            return 19;
        case 20:
            return 18;
        case 21:
            return 15;
        case 22:
            return 18;
        case 23:
            return 15;
        case 24:
            return 20;
        case 25:
            return 20;
        case 26:
            return 17;
        case 27:
            return 16;
        case 28:
            return 17;
        case 29:
            return 19;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 5 of the climate/terrain row
inline int wwsA1MeanM05(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return -1;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 15;
        case 13:
            return 13;
        case 14:
            return 14;
        case 15:
            return 11;
        case 16:
            return 13;
        case 17:
            return 12;
        case 18:
            return 19;
        case 19:
            return 19;
        case 20:
            return 19;
        case 21:
            return 16;
        case 22:
            return 21;
        case 23:
            return 16;
        case 24:
            return 21;
        case 25:
            return 20;
        case 26:
            return 19;
        case 27:
            return 16;
        case 28:
            return 22;
        case 29:
            return 19;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 6 of the climate/terrain row
inline int wwsA1MeanM06(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return -1;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 9;
        case 5:
            return 9;
        case 6:
            return 11;
        case 7:
            return 11;
        case 8:
            return 11;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 11;
        case 12:
            return 15;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 14;
        case 16:
            return 15;
        case 17:
            return 14;
        case 18:
            return 21;
        case 19:
            return 20;
        case 20:
            return 20;
        case 21:
            return 16;
        case 22:
            return 22;
        case 23:
            return 18;
        case 24:
            return 22;
        case 25:
            return 20;
        case 26:
            return 20;
        case 27:
            return 16;
        case 28:
            return 22;
        case 29:
            return 19;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 7 of the climate/terrain row
inline int wwsA1MeanM07(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return -1;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 24;
        case 13:
            return 18;
        case 14:
            return 19;
        case 15:
            return 16;
        case 16:
            return 18;
        case 17:
            return 15;
        case 18:
            return 23;
        case 19:
            return 20;
        case 20:
            return 20;
        case 21:
            return 15;
        case 22:
            return 22;
        case 23:
            return 18;
        case 24:
            return 24;
        case 25:
            return 20;
        case 26:
            return 22;
        case 27:
            return 15;
        case 28:
            return 22;
        case 29:
            return 19;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 8 of the climate/terrain row
inline int wwsA1MeanM08(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return -1;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 24;
        case 13:
            return 18;
        case 14:
            return 19;
        case 15:
            return 16;
        case 16:
            return 18;
        case 17:
            return 15;
        case 18:
            return 23;
        case 19:
            return 20;
        case 20:
            return 20;
        case 21:
            return 14;
        case 22:
            return 22;
        case 23:
            return 18;
        case 24:
            return 24;
        case 25:
            return 20;
        case 26:
            return 22;
        case 27:
            return 15;
        case 28:
            return 22;
        case 29:
            return 19;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 9 of the climate/terrain row
inline int wwsA1MeanM09(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return -1;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 22;
        case 13:
            return 15;
        case 14:
            return 16;
        case 15:
            return 13;
        case 16:
            return 15;
        case 17:
            return 14;
        case 18:
            return 20;
        case 19:
            return 20;
        case 20:
            return 18;
        case 21:
            return 14;
        case 22:
            return 21;
        case 23:
            return 17;
        case 24:
            return 23;
        case 25:
            return 20;
        case 26:
            return 21;
        case 27:
            return 15;
        case 28:
            return 22;
        case 29:
            return 19;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 10 of the climate/terrain row
inline int wwsA1MeanM10(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return -1;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 9;
        case 8:
            return 9;
        case 9:
            return 9;
        case 10:
            return 7;
        case 11:
            return 10;
        case 12:
            return 18;
        case 13:
            return 13;
        case 14:
            return 13;
        case 15:
            return 11;
        case 16:
            return 11;
        case 17:
            return 11;
        case 18:
            return 20;
        case 19:
            return 20;
        case 20:
            return 16;
        case 21:
            return 13;
        case 22:
            return 21;
        case 23:
            return 16;
        case 24:
            return 21;
        case 25:
            return 20;
        case 26:
            return 19;
        case 27:
            return 15;
        case 28:
            return 21;
        case 29:
            return 18;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 11 of the climate/terrain row
inline int wwsA1MeanM11(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return -1;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 7;
        case 8:
            return 6;
        case 9:
            return 5;
        case 10:
            return 4;
        case 11:
            return 7;
        case 12:
            return 17;
        case 13:
            return 9;
        case 14:
            return 10;
        case 15:
            return 10;
        case 16:
            return 10;
        case 17:
            return 10;
        case 18:
            return 18;
        case 19:
            return 18;
        case 20:
            return 15;
        case 21:
            return 13;
        case 22:
            return 17;
        case 23:
            return 14;
        case 24:
            return 20;
        case 25:
            return 20;
        case 26:
            return 17;
        case 27:
            return 15;
        case 28:
            return 18;
        case 29:
            return 18;
        default:
            return -1;
        }
    }

// the Table A1 second letter - the mean high and low temperatures - for month
// 12 of the climate/terrain row
inline int wwsA1MeanM12(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return -1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 5;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 5;
        case 12:
            return 12;
        case 13:
            return 9;
        case 14:
            return 9;
        case 15:
            return 9;
        case 16:
            return 9;
        case 17:
            return 10;
        case 18:
            return 15;
        case 19:
            return 18;
        case 20:
            return 13;
        case 21:
            return 12;
        case 22:
            return 15;
        case 23:
            return 12;
        case 24:
            return 18;
        case 25:
            return 20;
        case 26:
            return 16;
        case 27:
            return 15;
        case 28:
            return 17;
        case 29:
            return 17;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 1 of the climate/terrain row
inline int wwsA1HiM01(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return -1;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 8;
        case 9:
            return 8;
        case 10:
            return 8;
        case 11:
            return 10;
        case 12:
            return 18;
        case 13:
            return 11;
        case 14:
            return 11;
        case 15:
            return 11;
        case 16:
            return 12;
        case 17:
            return 12;
        case 18:
            return 19;
        case 19:
            return 20;
        case 20:
            return 16;
        case 21:
            return 15;
        case 22:
            return 17;
        case 23:
            return 20;
        case 24:
            return 20;
        case 25:
            return 22;
        case 26:
            return 17;
        case 27:
            return 17;
        case 28:
            return 17;
        case 29:
            return 20;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 2 of the climate/terrain row
inline int wwsA1HiM02(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return -1;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 7;
        case 5:
            return 7;
        case 6:
            return 9;
        case 7:
            return 8;
        case 8:
            return 8;
        case 9:
            return 8;
        case 10:
            return 9;
        case 11:
            return 10;
        case 12:
            return 19;
        case 13:
            return 10;
        case 14:
            return 12;
        case 15:
            return 12;
        case 16:
            return 13;
        case 17:
            return 13;
        case 18:
            return 20;
        case 19:
            return 21;
        case 20:
            return 17;
        case 21:
            return 16;
        case 22:
            return 18;
        case 23:
            return 21;
        case 24:
            return 19;
        case 25:
            return 22;
        case 26:
            return 19;
        case 27:
            return 18;
        case 28:
            return 19;
        case 29:
            return 21;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 3 of the climate/terrain row
inline int wwsA1HiM03(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return -1;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 7;
        case 5:
            return 7;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return 9;
        case 9:
            return 9;
        case 10:
            return 9;
        case 11:
            return 10;
        case 12:
            return 19;
        case 13:
            return 15;
        case 14:
            return 15;
        case 15:
            return 13;
        case 16:
            return 16;
        case 17:
            return 16;
        case 18:
            return 22;
        case 19:
            return 21;
        case 20:
            return 20;
        case 21:
            return 18;
        case 22:
            return 20;
        case 23:
            return 22;
        case 24:
            return 22;
        case 25:
            return 22;
        case 26:
            return 19;
        case 27:
            return 19;
        case 28:
            return 20;
        case 29:
            return 22;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 4 of the climate/terrain row
inline int wwsA1HiM04(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return -1;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 9;
        case 6:
            return 9;
        case 7:
            return 11;
        case 8:
            return 9;
        case 9:
            return 11;
        case 10:
            return 9;
        case 11:
            return 12;
        case 12:
            return 22;
        case 13:
            return 15;
        case 14:
            return 17;
        case 15:
            return 16;
        case 16:
            return 18;
        case 17:
            return 18;
        case 18:
            return 23;
        case 19:
            return 22;
        case 20:
            return 21;
        case 21:
            return 19;
        case 22:
            return 23;
        case 23:
            return 23;
        case 24:
            return 23;
        case 25:
            return 23;
        case 26:
            return 20;
        case 27:
            return 19;
        case 28:
            return 20;
        case 29:
            return 23;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 5 of the climate/terrain row
inline int wwsA1HiM05(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return -1;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 12;
        case 7:
            return 13;
        case 8:
            return 13;
        case 9:
            return 12;
        case 10:
            return 12;
        case 11:
            return 13;
        case 12:
            return 23;
        case 13:
            return 20;
        case 14:
            return 19;
        case 15:
            return 18;
        case 16:
            return 20;
        case 17:
            return 19;
        case 18:
            return 23;
        case 19:
            return 23;
        case 20:
            return 22;
        case 21:
            return 20;
        case 22:
            return 23;
        case 23:
            return 23;
        case 24:
            return 24;
        case 25:
            return 23;
        case 26:
            return 23;
        case 27:
            return 20;
        case 28:
            return 24;
        case 29:
            return 23;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 6 of the climate/terrain row
inline int wwsA1HiM06(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return -1;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 11;
        case 5:
            return 13;
        case 6:
            return 13;
        case 7:
            return 15;
        case 8:
            return 13;
        case 9:
            return 12;
        case 10:
            return 13;
        case 11:
            return 17;
        case 12:
            return 25;
        case 13:
            return 21;
        case 14:
            return 23;
        case 15:
            return 21;
        case 16:
            return 23;
        case 17:
            return 22;
        case 18:
            return 24;
        case 19:
            return 23;
        case 20:
            return 23;
        case 21:
            return 20;
        case 22:
            return 24;
        case 23:
            return 24;
        case 24:
            return 25;
        case 25:
            return 23;
        case 26:
            return 24;
        case 27:
            return 20;
        case 28:
            return 24;
        case 29:
            return 24;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 7 of the climate/terrain row
inline int wwsA1HiM07(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return -1;
        case 2:
            return 11;
        case 3:
            return 11;
        case 4:
            return 13;
        case 5:
            return 15;
        case 6:
            return 16;
        case 7:
            return 17;
        case 8:
            return 15;
        case 9:
            return 13;
        case 10:
            return 16;
        case 11:
            return 17;
        case 12:
            return 25;
        case 13:
            return 23;
        case 14:
            return 24;
        case 15:
            return 23;
        case 16:
            return 24;
        case 17:
            return 23;
        case 18:
            return 25;
        case 19:
            return 23;
        case 20:
            return 23;
        case 21:
            return 19;
        case 22:
            return 25;
        case 23:
            return 24;
        case 24:
            return 25;
        case 25:
            return 23;
        case 26:
            return 25;
        case 27:
            return 19;
        case 28:
            return 25;
        case 29:
            return 23;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 8 of the climate/terrain row
inline int wwsA1HiM08(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return -1;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 12;
        case 5:
            return 13;
        case 6:
            return 16;
        case 7:
            return 17;
        case 8:
            return 15;
        case 9:
            return 14;
        case 10:
            return 16;
        case 11:
            return 17;
        case 12:
            return 25;
        case 13:
            return 23;
        case 14:
            return 24;
        case 15:
            return 22;
        case 16:
            return 24;
        case 17:
            return 22;
        case 18:
            return 25;
        case 19:
            return 23;
        case 20:
            return 24;
        case 21:
            return 17;
        case 22:
            return 25;
        case 23:
            return 24;
        case 24:
            return 25;
        case 25:
            return 23;
        case 26:
            return 25;
        case 27:
            return 19;
        case 28:
            return 25;
        case 29:
            return 23;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 9 of the climate/terrain row
inline int wwsA1HiM09(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return -1;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 11;
        case 6:
            return 16;
        case 7:
            return 15;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 16;
        case 11:
            return 15;
        case 12:
            return 24;
        case 13:
            return 21;
        case 14:
            return 22;
        case 15:
            return 20;
        case 16:
            return 22;
        case 17:
            return 22;
        case 18:
            return 24;
        case 19:
            return 22;
        case 20:
            return 23;
        case 21:
            return 17;
        case 22:
            return 24;
        case 23:
            return 23;
        case 24:
            return 24;
        case 25:
            return 23;
        case 26:
            return 24;
        case 27:
            return 19;
        case 28:
            return 24;
        case 29:
            return 22;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 10 of the climate/terrain row
inline int wwsA1HiM10(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return -1;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 9;
        case 5:
            return 9;
        case 6:
            return 12;
        case 7:
            return 11;
        case 8:
            return 11;
        case 9:
            return 11;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 23;
        case 13:
            return 17;
        case 14:
            return 19;
        case 15:
            return 18;
        case 16:
            return 18;
        case 17:
            return 19;
        case 18:
            return 24;
        case 19:
            return 22;
        case 20:
            return 21;
        case 21:
            return 16;
        case 22:
            return 24;
        case 23:
            return 22;
        case 24:
            return 23;
        case 25:
            return 23;
        case 26:
            return 22;
        case 27:
            return 18;
        case 28:
            return 24;
        case 29:
            return 21;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 11 of the climate/terrain row
inline int wwsA1HiM11(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return -1;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 11;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 11;
        case 12:
            return 23;
        case 13:
            return 11;
        case 14:
            return 15;
        case 15:
            return 17;
        case 16:
            return 16;
        case 17:
            return 15;
        case 18:
            return 23;
        case 19:
            return 21;
        case 20:
            return 18;
        case 21:
            return 16;
        case 22:
            return 20;
        case 23:
            return 20;
        case 24:
            return 22;
        case 25:
            return 22;
        case 26:
            return 20;
        case 27:
            return 18;
        case 28:
            return 22;
        case 29:
            return 21;
        default:
            return -1;
        }
    }

// the Table A1 third letter - the highest temperatures that will normally
// occur - for month 12 of the climate/terrain row
inline int wwsA1HiM12(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return -1;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 9;
        case 9:
            return 9;
        case 10:
            return 8;
        case 11:
            return 10;
        case 12:
            return 17;
        case 13:
            return 11;
        case 14:
            return 12;
        case 15:
            return 11;
        case 16:
            return 12;
        case 17:
            return 12;
        case 18:
            return 22;
        case 19:
            return 21;
        case 20:
            return 17;
        case 21:
            return 15;
        case 22:
            return 18;
        case 23:
            return 20;
        case 24:
            return 21;
        case 25:
            return 22;
        case 26:
            return 19;
        case 27:
            return 18;
        case 28:
            return 20;
        case 29:
            return 21;
        default:
            return -1;
        }
    }

// ---- How to use Table A1 ----

// at the beginning of an adventure or an episode (such as when player
// characters find themselves abruptly transported to a different area), use
// the second letter of the Table A1 code to ascertain the current temperature
// conditions; from this starting point the temperature moves up or down on a
// daily basis per the Day-to-Day Change Table.
inline bool wwxSecondLetterStart()
    { return true; }

// as a general rule, the lowest temperature of the day occurs just before
// sunrise, and the reading gradually rises until the high is reached.
inline bool wwxLowBeforeSunrise()
    { return true; }

// the high temperature for the day is reached in early afternoon, possibly
// remaining at the high point for a few hours at the DM discretion; the
// reading then decreases gradually through the evening and night until the
// next low point just before sunrise - modified or disregarded in special
// weather conditions or when the DM judges different times should prevail.
inline bool wwxHighEarlyAfternoon()
    { return true; }

// ---- Table A2: day-to-day change ----

// the Table A2 grid: the 2d6 roll 2 through 12, 11 rows.
inline int wwxA2Count()
    { return 11; }

// the roll-2 wind condition reads Very Strong - no numeric increment, consult
// the Special Weather Table (the R494 slice). NOTE THE SETTLE: this cell is
// unreadable in all three of our pdf reads and rests on the external
// transcription.
inline bool wwxRoll2WindVeryStrong()
    { return true; }

// the roll-12 wind condition reads Very Slight - the same
// consult-the-Special-Weather-Table footnote, and the same settle caveat as
// the roll-2 cell.
inline bool wwxRoll12WindVerySlight()
    { return true; }

// the letter-scale temperature change in steps for the 2d6 roll (row 0 = roll
// 2)
inline int wwsA2Steps(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -2;
        case 2:
            return -2;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        default:
            return -99;
        }
    }

// the chance of precipitation: 1 yes, 0 no, 2 same as the previous day
inline int wwsA2Precip(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 1;
        default:
            return -99;
        }
    }

// the wind velocity increment added to the previous day in mph; -99 = the
// roll-2/roll-12 sentinel, consult the Special Weather Table
inline int wwsA2WindDelta(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 15;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 0;
        case 6:
            return -10;
        case 7:
            return -15;
        case 8:
            return -10;
        case 9:
            return -15;
        case 10:
            return -99;
        default:
            return -99;
        }
    }

// the wind source: 0 special consult, 1 from the arctic, 2 prevailing
// direction, 3 from the tropics, 4 same as the previous day
inline int wwsA2WindFrom(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 4;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 0;
        default:
            return -99;
        }
    }

// ---- How to use Table A2 ----

// wind velocity is the highest speed reached during gusts lasting a few
// seconds to a few minutes; for the rest of the day the speed will be no more
// than half the indicated maximum.
inline int wwxRestOfDayDivisor()
    { return 2; }

// roll 2d6 for each day beyond the present one, day by day or for a number of
// days in succession; use two dice different in color or size, designated die
// 1 and die 2 - the distinction matters whenever there is a chance of
// precipitation.
inline bool wwxDistinctDice()
    { return true; }

// temperature change: move up or down the letter scale as required; if the
// present temperature is within the allowable range (the first and third
// letters of the temperature code) but the move would take the result beyond
// that range, stop when the extreme result is reached.
inline bool wwxStopAtExtreme()
    { return true; }

// if the current temperature is already at the upper limit, treat any plus
// result as no change.
inline bool wwxUpperLimitPlusNoChange()
    { return true; }

// at the upper limit, treat a roll of 7 the same as a roll of 6 - the
// temperature drops by 1 step and precipitation is possible.
inline bool wwxLimitRoll7As6()
    { return true; }

// if the temperature remains at the upper limit for two consecutive days,
// treat a roll of 7 or 8 as a roll of 6, and continue this pattern until the
// streak of hot weather ends.
inline bool wwxStreakTwoDays7Or8As6()
    { return true; }

// for a streak of cold weather, perform the same process with the other end
// of the table.
inline bool wwxColdStreakMirror()
    { return true; }

// if the dice roll on the Day-to-Day Change Table is 2 or 12, follow the
// normal procedure for temperature change, chance of precipitation and wind
// conditions, and then refer to the Special Weather Table (page 112, the R494
// slice) to see if some extraordinary weather occurs.
inline bool wwxRoll2Or12ConsultSpecial()
    { return true; }

// if the roll of 2d6 on the Day-to-Day Change Table is an even number, refer
// to the Precipitation Variation Table to determine whether precipitation
// occurs and how much falls during the next 24 hours.
inline bool wwxPrecipConsultOnEvenRolls()
    { return true; }

// on a yes result, take the Precipitation Variation column A if die 1 is
// greater than die 2, column B if the dice are equal, and column C if die 2
// is greater than die 1.
inline bool wwxPrecipDieColumns()
    { return true; }

// on a dice roll of 3 through 11 the wind conditions column determines the
// direction and velocity of the wind.
inline bool wwxWindUsedOn3To11()
    { return true; }

// a wind from the arctic is a north wind in the northern hemisphere and a
// south wind in the southern hemisphere; the reverse is true for a wind from
// the tropics.
inline bool wwxArcticWindHemisphere()
    { return true; }

// the velocity increment (+15 mph, +10 mph, etc.) is added to the wind
// velocity for the previous day; the prevailing direction is as described in
// the climatic regions text.
inline bool wwxWindIncrementFromPrevious()
    { return true; }

// wind velocity cannot fall below zero.
inline bool wwxWindNeverBelowZero()
    { return true; }

// wind velocity is the highest speed the wind will reach on the day in
// question, during gusts that can last anywhere from a few seconds to a few
// minutes.
inline bool wwxGustsSecondsToMinutes()
    { return true; }

// ---- Table A3: precipitation variation ----

// the Table A3 grid: the arctic block carries 5 rows (no forest, no swamp),
// every other climate 7 - 33 rows x 12 columns.
inline int wwxA3Count()
    { return 33; }

// trace: less than 1/8 inch of rain.
inline int wwxTraceRainEighthInch()
    { return 1; }

// trace: 1/2 inch of snow.
inline int wwxTraceSnowHalfInch()
    { return 1; }

// light: up to 1/2 inch of rain.
inline int wwxLightRainHalfInch()
    { return 1; }

// light: up to 1 inch of snow.
inline int wwxLightSnowInch()
    { return 1; }

// moderate: up to 3/4 inch of rain.
inline int wwxModerateRainQuarterInch()
    { return 3; }

// moderate: up to 2 inches of snow.
inline int wwxModerateSnowInch()
    { return 2; }

// heavy: up to 1 1/2 inches of rain.
inline int wwxHeavyRainHalfInch()
    { return 3; }

// heavy: up to 4 inches of snow.
inline int wwxHeavySnowInch()
    { return 4; }

// downpour: more than 1 1/2 inches of rain (no snow figure is given -
// downpour precipitation occurs in certain terrain in subtropical and
// tropical climates).
inline int wwxDownpourRainHalfInch()
    { return 3; }

// the Table A3 cell for the winter season, column A (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3WiA(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 2;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 3;
        case 28:
            return 0;
        case 29:
            return 1;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        default:
            return -99;
        }
    }

// the Table A3 cell for the winter season, column B (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3WiB(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 2;
        case 17:
            return 4;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 4;
        case 21:
            return 2;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 3;
        case 25:
            return 2;
        case 26:
            return 1;
        case 27:
            return 5;
        case 28:
            return 1;
        case 29:
            return 3;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 2;
        default:
            return -99;
        }
    }

// the Table A3 cell for the winter season, column C (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3WiC(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 4;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 2;
        case 26:
            return 0;
        case 27:
            return 4;
        case 28:
            return 0;
        case 29:
            return 2;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 1;
        default:
            return -99;
        }
    }

// the Table A3 cell for the spring season, column A (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3SpA(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 3;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 3;
        case 28:
            return 0;
        case 29:
            return 3;
        case 30:
            return 2;
        case 31:
            return 2;
        case 32:
            return 3;
        default:
            return -99;
        }
    }

// the Table A3 cell for the spring season, column B (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3SpB(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 3;
        case 16:
            return 4;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 1;
        case 20:
            return 5;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 3;
        case 26:
            return 2;
        case 27:
            return 5;
        case 28:
            return 2;
        case 29:
            return 4;
        case 30:
            return 4;
        case 31:
            return 5;
        case 32:
            return 4;
        default:
            return -99;
        }
    }

// the Table A3 cell for the spring season, column C (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3SpC(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 2;
        case 16:
            return 3;
        case 17:
            return 2;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 4;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 3;
        case 25:
            return 2;
        case 26:
            return 1;
        case 27:
            return 4;
        case 28:
            return 1;
        case 29:
            return 4;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 4;
        default:
            return -99;
        }
    }

// the Table A3 cell for the summer season, column A (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3SuA(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return 0;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 3;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 3;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 3;
        case 31:
            return 4;
        case 32:
            return 3;
        default:
            return -99;
        }
    }

// the Table A3 cell for the summer season, column B (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3SuB(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 2;
        case 16:
            return 4;
        case 17:
            return 2;
        case 18:
            return 4;
        case 19:
            return 0;
        case 20:
            return 5;
        case 21:
            return 4;
        case 22:
            return 3;
        case 23:
            return 3;
        case 24:
            return 5;
        case 25:
            return 4;
        case 26:
            return 1;
        case 27:
            return 5;
        case 28:
            return 3;
        case 29:
            return 3;
        case 30:
            return 4;
        case 31:
            return 5;
        case 32:
            return 4;
        default:
            return -99;
        }
    }

// the Table A3 cell for the summer season, column C (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3SuC(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 3;
        case 17:
            return 1;
        case 18:
            return 3;
        case 19:
            return 0;
        case 20:
            return 4;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 3;
        case 25:
            return 2;
        case 26:
            return 0;
        case 27:
            return 4;
        case 28:
            return 2;
        case 29:
            return 2;
        case 30:
            return 3;
        case 31:
            return 5;
        case 32:
            return 3;
        default:
            return -99;
        }
    }

// the Table A3 cell for the autumn season, column A (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3AuA(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 3;
        case 28:
            return 0;
        case 29:
            return 3;
        case 30:
            return 2;
        case 31:
            return 0;
        case 32:
            return 2;
        default:
            return -99;
        }
    }

// the Table A3 cell for the autumn season, column B (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3AuB(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 4;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 4;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 2;
        case 25:
            return 2;
        case 26:
            return 1;
        case 27:
            return 5;
        case 28:
            return 1;
        case 29:
            return 4;
        case 30:
            return 4;
        case 31:
            return 2;
        case 32:
            return 3;
        default:
            return -99;
        }
    }

// the Table A3 cell for the autumn season, column C (A if die 1 beats die 2,
// B on doubles, C if die 2 beats die 1): 0 none, 1 trace, 2 light, 3
// moderate, 4 heavy, 5 downpour
inline int wwsA3AuC(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 0;
        case 13:
            return 3;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 4;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 2;
        case 26:
            return 0;
        case 27:
            return 4;
        case 28:
            return 0;
        case 29:
            return 4;
        case 30:
            return 3;
        case 31:
            return 1;
        case 32:
            return 3;
        default:
            return -99;
        }
    }

// ---- Rain, sleet, or snow ----

// if the current temperature is 36 degrees or higher, rain will fall.
inline int wwxRainMinF()
    { return 36; }

// the sleet band runs from 30 to 35 degrees inclusive - the high bound.
inline int wwxSleetHiF()
    { return 35; }

// the sleet band low bound.
inline int wwxSleetLoF()
    { return 30; }

// in the 30-35 band sleet results half the time (1-3 on d6, or the DM
// discretion) and snow the other half.
inline int wwxSleetD6Max()
    { return 3; }

// at a temperature lower than 30 degrees, the precipitation will be a
// snowfall.
inline bool wwxSnowBelow30()
    { return true; }

// the precipitation form dispatch on the current temperature in degrees
// Fahrenheit: band 0 = snow (below 30), band 1 = sleet-or-snow (30 to 35
// inclusive, sleet on 1-3 of d6), band 2 = rain (36 and above).
inline int wwxPrecipFormFor(int tempF)
    {
        if (tempF <= 29) return 0;
        if (tempF <= 35) return 1;
        return 2;
    }

// ---- Collecting precipitation ----

// an ounce of water occupies about 1.8 cubic inches of volume - pinned in
// tenths.
inline int wwxOunceTenthCuIn()
    { return 18; }

// liquid collected in a circular container has volume pi x r squared x h; one
// inch of rain collected in a 6-inch-radius container yields about 113 cubic
// inches of water.
inline int wwxInchRainCuIn()
    { return 113; }

// the 113 cubic inches come to about 63 ounces of water, or roughly one-half
// gallon.
inline int wwxInchRainOz()
    { return 63; }

// for a square or rectangular container the volume is the product of the
// three dimensions: a metal box 6 inches by 4 inches by at least 1 inch deep
// in a 1-inch rainfall holds 6 x 4 x 1 = 24 cubic inches.
inline int wwxBoxCuIn()
    { return 24; }

// the 24 cubic inches amount to roughly 13 fluid ounces, somewhat less than a
// pint.
inline int wwxBoxOz()
    { return 13; }

// melted snow converts to water at a rate of 10 to 1: one inch of fresh snow,
// collected and melted, yields the same liquid as a rainfall of 1/10 inch.
inline int wwxSnowMeltRatio()
    { return 10; }

// the melt ratio is not especially relevant to collecting drinking water: in
// most cases when a snowfall occurs the precipitation stays on the ground,
// from where it can be gathered, and there will usually already be snow cover
// to scavenge - it is not difficult to obtain drinking water during the snowy
// season in any climate that has one.
inline bool wwxSnowOnTheGround()
    { return true; }

// ---- The precipitation intensity guidelines ----

// trace precipitation accumulates to a measurable amount only if the rain
// falls continuously for at least half an hour.
inline int wwxTraceMinutes()
    { return 30; }

// in a desert, only one out of every ten trace rainfalls will last more than
// a few minutes.
inline int wwxDesertTraceTenths()
    { return 1; }

// the heaviest possible trace accumulation, just short of 1/10 inch of rain,
// even if collected in something as large as a cooking pan 1 foot in
// diameter, yields less than eight fluid ounces.
inline int wwxTracePanOz()
    { return 8; }

// the trace ceiling in the intensity prose: just short of 1/10 inch (the
// letter-code footnote reads less than 1/8 inch - both figures are printed,
// pinned side by side).
inline int wwxTracePanTenthInch()
    { return 1; }

// heavy precipitation almost always falls in a relatively short time as the
// result of storm conditions, and in most cases those conditions occur at
// dawn or dusk - within two hours either way of sunrise or sunset.
inline int wwxHeavyStormWindowHours()
    { return 2; }

// the downpour pattern: a period of intense rain during which as much as an
// inch of water may fall in a half-hour or less, at any time of the day or
// night.
inline int wwxDownpourBurstInch()
    { return 1; }

// the intense burst lasts a half-hour or less, sandwiched between two periods
// of lighter, more prolonged precipitation.
inline int wwxDownpourBurstMinutes()
    { return 30; }

// collecting water from a trace rainfall is fruitless except in cases of dire
// need; in a desert any liquid precipitation quickly soaks through the sandy
// or rocky soil or evaporates in hot temperatures almost as quickly.
inline bool wwxDesertTraceFutile()
    { return true; }

// light precipitation should be interpreted very conservatively in
// terrain/climate areas where it represents the greatest amount of rain or
// snow that normally falls in a day: most such rainfalls are scarcely greater
// than trace. The converse does not apply where light is the least
// precipitation possible - there the accumulation can range through the
// entire span of possibilities.
inline bool wwxLightReadConservatively()
    { return true; }

// moderate precipitation does not always fall under moderate conditions:
// continuous drizzle for most or all of a day, or a storm of only a few
// minutes; where moderate is the normal maximum, the accumulation is usually
// not much greater than light and falls as gentle, prolonged rain instead of
// a brief storm.
inline bool wwxModerateVaries()
    { return true; }

// heavy precipitation almost always falls in a relatively short time under
// storm conditions at dawn or dusk, in contrast with the lighter
// accumulations, which can occur at any time of day or night.
inline bool wwxHeavyAtDawnDusk()
    { return true; }

// downpour precipitation occurs in certain terrain in subtropical and
// tropical climates only.
inline bool wwxDownpourOnlySubtropicalTropical()
    { return true; }

// ---- Extraordinary precipitation ----

// whenever two successive rolls on the Day-to-Day Change Table are doubles,
// and no special weather occurs on either day, the check applies.
inline int wwxExtraDoublesRun()
    { return 2; }

// the extraordinary chance: 50 percent - 1-3 on d6, or the DM discretion.
inline int wwxExtraD6Lo()
    { return 1; }

// the high bound of the d6 band.
inline int wwxExtraD6Hi()
    { return 3; }

// on a hit, the precipitation for the second day is one step greater than the
// result given on the Precipitation Variation Table for a roll of doubles.
inline int wwxExtraStepUp()
    { return 1; }

// a downpour will never occur during summer in a temperate forest, regardless
// of how many times in a row the dice come up doubles - the printed book
// itself carries the one-in-three erratum in the tail sentence where the rule
// reads 50 percent.
inline bool wwxExtraNoTemperateForestSummerDownpour()
    { return true; }

// in no case can extraordinary precipitation exceed the level of a downpour.
inline bool wwxExtraCapsAtDownpour()
    { return true; }

// if doubles are rolled more than twice in succession, the precipitation does
// not continue to increase but remains at the one-step-greater level, and the
// d6 chance does not have to be checked any more.
inline bool wwxExtraTwoDoublesThenHold()
    { return true; }

}   // namespace rules
