// =========================================================================================
// Adnd1 - rules/wsgweathx.h
// The WSG WORLD OF WEATHER, R494: the appendix part 2 - special weather, the
// effects on play and the optional rules, printed pp. 112-119 (pdf pages
// 113-120): Table A4 (the special weather grid) with the Roll 1 / Roll 2
// cross-index, the per-code definitions from cold wave through heat wave, the
// extreme-precipitation dispatch, the humidity rules (Tables A5 and A6), wind
// chill (A7), the hours of daylight (A8), twilight, local winds, tides and
// the Dungeon Master responsibility. This closes the appendix: both the
// weather-effects child and the parent appendix box flip, and only the
// compiled tables (pp. 120-126) remain in the WSG arc.
// census 418 -> 419.
//
// WSG printed pp. 112-119, pdf pages 113-120, extracted two-way at
// r493-extraction sha 5525680 (pdftotext layout + tesseract tsv, p0113-p0120)
// plus the psm-6 / psm-4 / psm-11 third reads of pdf page 113 at 52dd5fc;
// settled three-way with two external corroborators - the s0py python port
// (its season rotation verified via the A5 humidity cross-check) and the pdfy
// djvu read for the grid. Base ceaff98, census 418 -> 419.
//
// THE SETTLE: Table A4 is the psm-6 read win - default tesseract, pdftotext
// and the djvu reads all garble the grid, and the 400-dpi psm-6 pass decodes
// it letter-for-letter with the TSV confidences checked per cell; the port
// agrees cell-for-cell on 28 of 33 rows and the djvu corroborates the arctic,
// temperate and subtropical interior blocks. Cyclone is confirmed on the
// coasts: the temperate seacoast spring/summer cells read CXMZ in three
// independent sources against the port uniform AXMZ, and the same coastal
// warm-season pattern carries the subtropical seacoast and swamp
// spring/summer cells and the tropical seacoast summer cell (flagged - that C
// is a low-confidence read). The swamp rows are psm-6 only (the port has no
// swamp biome and the djvu drops them), and the tropical swamp winter cell is
// the single inferred cell of the grid (the ANz D glyph read, decoded by the
// all-Z fourth-letter pattern of the tropical winter column). The A5 humidity
// grid rides the same 33-row model as A4 (the printed arctic-all-terrains
// line expanded to its five terrain rows); the transcription wins the two
// subarctic cells where the port rotation disagrees, the A3 precedent. A6 and
// A7 are transcription-port exact; A8 is 15 latitude rows (the earlier 16-row
// note was a miscount), cross-checked against the pdf layout read; the prose
// pages read clean throughout.
//
namespace rules {

// ---- How to use Table A4: the Roll 1 / Roll 2 cross-index ----

// how to use the Special Weather Table: consider the earlier roll on the
// Day-to-Day Change Table (either a 2 or a 12) as Roll 1.
inline int wwyA4Roll1Two()
    { return 2; }

// the other Roll 1 trigger.
inline int wwyA4Roll1Twelve()
    { return 12; }

// then roll 2d6 again, referring to the result as Roll 2, read across five
// bands: 2-4, 5-6, 7, 8-9, 10-12.
inline int wwyRoll2Bands()
    { return 5; }

// the Roll 2 index grid: one row for Roll 1 = 2 and one for Roll 1 = 12, five
// bands each.
inline int wwyRoll2Rows()
    { return 2; }

// if any special weather episode is already in progress, a roll of 2 or 12 on
// the Day-to-Day Change Table indicates no special weather for that day.
inline bool wwyRunningEpisodeNoSpecial()
    { return true; }

// the notations 1st, 2nd, 3rd, 4th refer to a single letter of the
// four-letter code; 0 marks that no letter is selected (no special weather
// possible from this position).
inline int wwyLetterPosNone()
    { return 0; }

// the first letter of the cell code.
inline int wwyLetterPos1st()
    { return 1; }

// the second letter of the cell code.
inline int wwyLetterPos2nd()
    { return 2; }

// the third letter of the cell code.
inline int wwyLetterPos3rd()
    { return 3; }

// the fourth letter of the cell code.
inline int wwyLetterPos4th()
    { return 4; }

// the selected letter for the Roll 2 band 2-4 (row 0: Roll 1 = 2 picks the
// 1st letter; row 1: Roll 1 = 12 picks none)
inline int wwtR2B24(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        default:
            return -1;
        }
    }

// the selected letter for the Roll 2 band 5-6 (row 0: Roll 1 = 2 picks the
// 2nd letter; row 1: Roll 1 = 12 picks none)
inline int wwtR2B56(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 0;
        default:
            return -1;
        }
    }

// the selected letter for the Roll 2 band 7 (row 0: Roll 1 = 2 picks the 2nd
// letter; row 1: Roll 1 = 12 picks the 3rd)
inline int wwtR2B7(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        default:
            return -1;
        }
    }

// the selected letter for the Roll 2 band 8-9 (row 0: Roll 1 = 2 picks none;
// row 1: Roll 1 = 12 picks the 3rd)
inline int wwtR2B89(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 3;
        default:
            return -1;
        }
    }

// the selected letter for the Roll 2 band 10-12 (row 0: Roll 1 = 2 picks
// none; row 1: Roll 1 = 12 picks the 4th)
inline int wwtR2B1012(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        default:
            return -1;
        }
    }

// ---- Table A4: the special weather grid ----

// the Table A4 grid: 5 climatic regions; the arctic block carries
// desert/hills/mountains/plains/seacoast (no forest, no swamp), every other
// climate all seven terrains - 33 rows x 4 seasons.
inline int wwyA4Count()
    { return 33; }

// each cell of the grid is a four-letter code packed one letter per decimal
// digit: A=1, C=2, D=3, G=4, M=5, S=6, T=7, X=8, Z=9; the k-th letter of the
// code is (code / 10 to the 4-k) mod 10.
inline int wwyA4PackBase()
    { return 10; }

// the letter A: cold wave.
inline int wwyCodeColdWave()
    { return 1; }

// the letter C: cyclone, hurricane or typhoon.
inline int wwyCodeCyclone()
    { return 2; }

// the letter D: drought.
inline int wwyCodeDrought()
    { return 3; }

// the letter G: gale.
inline int wwyCodeGale()
    { return 4; }

// the letter M: mist or fog.
inline int wwyCodeMistFog()
    { return 5; }

// the letter S: sandstorm, dust storm or blowing snow.
inline int wwyCodeSandstorm()
    { return 6; }

// the letter T: tornado.
inline int wwyCodeTornado()
    { return 7; }

// the letter X: extreme precipitation.
inline int wwyCodeExtremePrecip()
    { return 8; }

// the letter Z: heat wave.
inline int wwyCodeHeatWave()
    { return 9; }

// the four-letter code for Winter (the packed digits, one letter per digit:
// A=1 cold wave, C=2 cyclone, D=3 drought, G=4 gale, M=5 mist/fog, S=6
// sandstorm, T=7 tornado, X=8 extreme precipitation, Z=9 heat wave)
inline int wwtA4Wi(int b)
    {
        switch (b) {
        case 0:
            return 4133;
        case 1:
            return 4133;
        case 2:
            return 4133;
        case 3:
            return 4133;
        case 4:
            return 4133;
        case 5:
            return 4133;
        case 6:
            return 4139;
        case 7:
            return 4153;
        case 8:
            return 4135;
        case 9:
            return 4153;
        case 10:
            return 4159;
        case 11:
            return 1859;
        case 12:
            return 1639;
        case 13:
            return 1859;
        case 14:
            return 1859;
        case 15:
            return 1853;
        case 16:
            return 1439;
        case 17:
            return 1859;
        case 18:
            return 1859;
        case 19:
            return 1639;
        case 20:
            return 8159;
        case 21:
            return 1839;
        case 22:
            return 1839;
        case 23:
            return 1839;
        case 24:
            return 1839;
        case 25:
            return 1839;
        case 26:
            return 1639;
        case 27:
            return 8859;
        case 28:
            return 1439;
        case 29:
            return 1859;
        case 30:
            return 4839;
        case 31:
            return 8139;
        case 32:
            return 1859;
        default:
            return -1;
        }
    }

// the four-letter code for Spring
inline int wwtA4Sp(int b)
    {
        switch (b) {
        case 0:
            return 4133;
        case 1:
            return 4135;
        case 2:
            return 4135;
        case 3:
            return 1435;
        case 4:
            return 1459;
        case 5:
            return 4133;
        case 6:
            return 1839;
        case 7:
            return 1439;
        case 8:
            return 1859;
        case 9:
            return 1839;
        case 10:
            return 4159;
        case 11:
            return 1859;
        case 12:
            return 4639;
        case 13:
            return 4859;
        case 14:
            return 1897;
        case 15:
            return 1859;
        case 16:
            return 1879;
        case 17:
            return 2859;
        case 18:
            return 4859;
        case 19:
            return 4639;
        case 20:
            return 8495;
        case 21:
            return 1837;
        case 22:
            return 1895;
        case 23:
            return 8479;
        case 24:
            return 2859;
        case 25:
            return 2859;
        case 26:
            return 4639;
        case 27:
            return 8895;
        case 28:
            return 4839;
        case 29:
            return 1859;
        case 30:
            return 4839;
        case 31:
            return 1859;
        case 32:
            return 4859;
        default:
            return -1;
        }
    }

// the four-letter code for Summer
inline int wwtA4Su(int b)
    {
        switch (b) {
        case 0:
            return 4133;
        case 1:
            return 4159;
        case 2:
            return 4159;
        case 3:
            return 8139;
        case 4:
            return 4159;
        case 5:
            return 1633;
        case 6:
            return 8193;
        case 7:
            return 1893;
        case 8:
            return 1893;
        case 9:
            return 9193;
        case 10:
            return 8195;
        case 11:
            return 8195;
        case 12:
            return 4639;
        case 13:
            return 4859;
        case 14:
            return 1839;
        case 15:
            return 1839;
        case 16:
            return 8439;
        case 17:
            return 2859;
        case 18:
            return 4859;
        case 19:
            return 4639;
        case 20:
            return 8895;
        case 21:
            return 8439;
        case 22:
            return 8493;
        case 23:
            return 8439;
        case 24:
            return 2859;
        case 25:
            return 2859;
        case 26:
            return 4639;
        case 27:
            return 8895;
        case 28:
            return 4839;
        case 29:
            return 8495;
        case 30:
            return 6893;
        case 31:
            return 2859;
        case 32:
            return 8459;
        default:
            return -1;
        }
    }

// the four-letter code for Autumn
inline int wwtA4Au(int b)
    {
        switch (b) {
        case 0:
            return 4133;
        case 1:
            return 4135;
        case 2:
            return 4135;
        case 3:
            return 4139;
        case 4:
            return 4159;
        case 5:
            return 4133;
        case 6:
            return 1853;
        case 7:
            return 4153;
        case 8:
            return 4153;
        case 9:
            return 4139;
        case 10:
            return 1459;
        case 11:
            return 1859;
        case 12:
            return 6439;
        case 13:
            return 1859;
        case 14:
            return 1839;
        case 15:
            return 8139;
        case 16:
            return 8139;
        case 17:
            return 1859;
        case 18:
            return 1859;
        case 19:
            return 4639;
        case 20:
            return 1859;
        case 21:
            return 1895;
        case 22:
            return 8195;
        case 23:
            return 4139;
        case 24:
            return 1839;
        case 25:
            return 1839;
        case 26:
            return 4639;
        case 27:
            return 8859;
        case 28:
            return 4493;
        case 29:
            return 1459;
        case 30:
            return 4893;
        case 31:
            return 8195;
        case 32:
            return 8159;
        default:
            return -1;
        }
    }

// ---- The no-special day ----

// a roll of 2 when no special weather occurs: a very strong wind, 45 mph.
inline int wwyNoSpecRoll2WindMph()
    { return 45; }

// the no-special 2: the temperature takes a sharp drop.
inline bool wwyNoSpecRoll2SharpDrop()
    { return true; }

// the no-special 2: precipitation is possible, as given on the Precipitation
// Variation Table for a roll of doubles (the B column).
inline bool wwyNoSpecRoll2PrecipB()
    { return true; }

// the no-special 2: the wind comes from the arctic or from the prevailing
// direction, 50 percent either way.
inline bool wwyNoSpecRoll2WindSource50()
    { return true; }

// a roll of 12 when no special weather occurs: a very slight wind, 5 mph.
inline int wwyNoSpecRoll12WindMph()
    { return 5; }

// the no-special 12: the temperature takes a sharp rise.
inline bool wwyNoSpecRoll12SharpRise()
    { return true; }

// the no-special 12: precipitation is possible, as given on the Precipitation
// Variation Table for a roll of doubles (the B column).
inline bool wwyNoSpecRoll12PrecipB()
    { return true; }

// ---- Cold wave ----

// a cold wave lasts 2d6+2 days.
inline int wwyColdWaveDice()
    { return 2; }

// the +2 on the 2d6 duration roll.
inline int wwyColdWaveDiePlus()
    { return 2; }

// through the wave the temperature drops 4 letter-scale steps per day.
inline int wwyColdWaveStepsPerDay()
    { return 4; }

// the daily drop stops one step below the normal minimum temperature for the
// date (the wave floor).
inline bool wwyColdWaveFloorBelowMin()
    { return true; }

// if the A-minimum temperature is reached, the temperature continues to drop
// to as much as 10 degrees below the normal minimum.
inline int wwyColdWaveAMinDropF()
    { return 10; }

// the below-normal-minimum extreme can persist for a maximum of 3 days.
inline int wwyColdWaveAMinDays()
    { return 3; }

// the recovery from a cold wave is automatic: the temperature rises to the
// normal minimum with no roll.
inline bool wwyColdWaveRecoveryAutoRise()
    { return true; }

// when the wave ends the temperature automatically rises to the normal
// minimum; a roll of 7 or higher on 2d6 raises it 1-3 steps more, any lower
// roll just reaches the minimum.
inline int wwyColdWaveRecoveryRollLo()
    { return 7; }

// ---- Heat wave ----

// a heat wave is the mirror of a cold wave and lasts 2d6+2 days.
inline int wwyHeatWaveDice()
    { return 2; }

// the +2 on the 2d6 duration roll.
inline int wwyHeatWaveDiePlus()
    { return 2; }

// through the wave the temperature rises 4 letter-scale steps per day.
inline int wwyHeatWaveStepsPerDay()
    { return 4; }

// the daily rise stops one step above the normal maximum temperature for the
// date (the wave ceiling).
inline bool wwyHeatWaveCeilingAboveMax()
    { return true; }

// if the Z-maximum temperature is reached, the temperature continues to rise
// to as much as 10 degrees above the normal maximum.
inline int wwyHeatWaveZMaxRiseF()
    { return 10; }

// the above-normal-maximum extreme can persist for a maximum of 3 days.
inline int wwyHeatWaveZMaxDays()
    { return 3; }

// the recovery from a heat wave is automatic: the temperature falls to the
// normal maximum with no roll.
inline bool wwyHeatWaveRecoveryAutoFall()
    { return true; }

// when the wave ends the temperature automatically falls to the normal
// maximum; a roll of 7 or higher on 2d6 falls 1-3 steps more, any lower roll
// just reaches the maximum.
inline int wwyHeatWaveRecoveryRollLo()
    { return 7; }

// ---- Cyclone ----

// the cyclone wind velocity: 1d6 x 20 + 60 mph.
inline int wwyCycloneWindDice()
    { return 1; }

// the per-die 20 mph.
inline int wwyCycloneWindMult()
    { return 20; }

// the +60 mph base.
inline int wwyCycloneWindBase()
    { return 60; }

// the cyclone wind floor: 80 mph.
inline int wwyCycloneWindMinMph()
    { return 80; }

// the cyclone wind ceiling: 180 mph.
inline int wwyCycloneWindMaxMph()
    { return 180; }

// at a seacoast, a cyclone is heralded a day in advance by a lightning storm.
inline bool wwyCycloneSeacoastLightningDayBefore()
    { return true; }

// a cyclone affects an area at most 10 miles inland; further inland only the
// perimeter conditions apply.
inline int wwyCycloneInlandMaxMi()
    { return 10; }

// the gale-and-heavy-rain perimeter around the storm center extends about 50
// miles.
inline int wwyCyclonePerimeterMi()
    { return 50; }

// a cyclone moves away from the equator (toward the nearest pole).
inline bool wwyCycloneMovesAwayFromEquator()
    { return true; }

// at sea a cyclone follows the coastline rather than striking inland
// directly.
inline bool wwyCycloneFollowsCoast()
    { return true; }

// a cyclone at sea follows the coastline for 1-2 days before heading back out
// to sea.
inline int wwyCycloneFollowsCoastDaysLo()
    { return 1; }

// the high bound of the follow.
inline int wwyCycloneFollowsCoastDaysHi()
    { return 2; }

// within the cyclone the rain is at least twice that of a downpour.
inline bool wwyCycloneRainDoubleDownpour()
    { return true; }

// where a cyclone strikes the coast it can generate a tidal wave (a wall of
// water 30-100 feet high) that encroaches up to 3 miles inland.
inline int wwyCycloneTidalWaveMi()
    { return 3; }

// the eye of the cyclone lasts about 6 hours.
inline int wwyCycloneEyeHours()
    { return 6; }

// the first half hour to hour of the eye is virtually rainless and windless
// (dead calm).
inline int wwyCycloneEyeCalmMinLo()
    { return 30; }

// the high bound of the dead-calm window.
inline int wwyCycloneEyeCalmMinHi()
    { return 60; }

// the second half of the eye brings a heavy rainstorm for its 6 hours.
inline bool wwyCycloneEyeSecondHalfRainstorm()
    { return true; }

// winds through the eye stay at 10 mph or below.
inline int wwyCycloneEyeWindMaxMph()
    { return 10; }

// for 3 days after a cyclone the Day-to-Day Change Table is not used; the
// weather is dominated by the storm system.
inline int wwyCycloneNoChangeDays()
    { return 3; }

// the two-day drift after a cyclone: each day roll 2d6 - 6 or less drops the
// temperature 1 step (band 0), 7 holds it (band 1), 8 or higher raises it 1
// step (band 2).
inline int wwyCycloneDriftFor(int roll)
    {
        if (roll <= 6) return 0;
        if (roll <= 7) return 1;
        return 2;
    }

// the frequency cap radius: an area within 200 miles of a cyclone path can be
// struck by at most one cyclone per month.
inline int wwyCycloneRadiusMi()
    { return 200; }

// an area can be struck by at most one cyclone in a given month.
inline bool wwyCycloneMaxOncePerMonth()
    { return true; }

// a second cyclone indicated within the 200-mile radius in the same month
// indicates extreme precipitation instead.
inline bool wwyCycloneSecondBecomesExtreme()
    { return true; }

// cyclones are not generated within 5 degrees of the equator.
inline bool wwyCycloneNotNearEquator()
    { return true; }

// cyclones do not occur within 5 degrees of the equator.
inline int wwyCycloneEquatorExclDeg()
    { return 5; }

// ---- Drought ----

// a drought lasts 2d6+2 days.
inline int wwyDroughtDice()
    { return 2; }

// the +2 on the 2d6 duration roll.
inline int wwyDroughtDiePlus()
    { return 2; }

// no precipitation falls on the first day of a drought.
inline bool wwyDroughtDay1NoPrecip()
    { return true; }

// precipitation indicated at light or moderate maximum falls as at most a
// trace during a drought.
inline bool wwyDroughtLightToTrace()
    { return true; }

// through a drought at most a trace of precipitation can fall, and at most
// once every 5 days.
inline int wwyDroughtTraceGapDays()
    { return 5; }

// heavy-maximum precipitation steps down each day of the drought: heavy to
// light, moderate to trace, light to none.
inline bool wwyDroughtHeavyLadder()
    { return true; }

// ---- Gale ----

// the gale wind velocity: 1d6 x 5 + 40 mph.
inline int wwyGaleDieSides()
    { return 6; }

// the per-die 5 mph.
inline int wwyGaleMultMph()
    { return 5; }

// the +40 mph base.
inline int wwyGaleBaseMph()
    { return 40; }

// the gale wind floor: 45 mph.
inline int wwyGaleMinMph()
    { return 45; }

// the gale wind ceiling: 70 mph.
inline int wwyGaleMaxMph()
    { return 70; }

// a gale lasts 1d6+1 hours.
inline int wwyGaleDurDiePlus()
    { return 1; }

// the gale duration floor: 2 hours.
inline int wwyGaleDurMinHrs()
    { return 2; }

// the gale duration ceiling: 7 hours.
inline int wwyGaleDurMaxHrs()
    { return 7; }

// wind velocity during a gale never drops below 30 mph and is mostly 50 mph
// or greater.
inline bool wwyGaleNeverBelow30()
    { return true; }

// if the previous day wind was 20 mph or greater, the gale reads 50-70 mph.
inline bool wwyGalePrev20Boost()
    { return true; }

// in a desert a gale produces no precipitation and whips up a severe
// sandstorm instead.
inline bool wwyGaleDesertSandstorm()
    { return true; }

// in an arctic or subarctic climate (or anywhere with snow on the ground) a
// gale whips the snow into a severe blizzard, the blowing-snow analogue of a
// severe sandstorm.
inline bool wwyGaleSnowSevereSandstorm()
    { return true; }

// ---- Mist or fog ----

// mist or fog forms at sunrise on a roll of 1-4 on 1d6, at sunset on a roll
// of 5-6.
inline int wwyMistSunriseRollMax()
    { return 4; }

// the mist or fog lasts 1d6 hours.
inline int wwyMistHoursDie()
    { return 6; }

// in a seacoast area or an area adjacent to a large body of water the fog is
// heavy; elsewhere it is moderate.
inline bool wwyMistHeavyNearWater()
    { return true; }

// precipitation is suspended while the mist or fog lasts.
inline bool wwyMistSuspendsPrecip()
    { return true; }

// there is a 50 percent chance of mist or fog the day before and the day
// after in an area adjacent to the fog.
inline bool wwyMistAdjacent50()
    { return true; }

// ---- Sandstorm ----

// a sandstorm requires an area of loose soil, sand or snow (fine dirt also
// qualifies).
inline bool wwySandstormNeedsLooseMaterial()
    { return true; }

// no precipitation falls on the day of a sandstorm.
inline bool wwySandstormNoPrecipThatDay()
    { return true; }

// a normal sandstorm lasts 1d4+1 hours.
inline int wwySandstormDieSides()
    { return 4; }

// the +1 on the 1d4 duration roll.
inline int wwySandstormDiePlus()
    { return 1; }

// the normal sandstorm duration floor: 2 hours.
inline int wwySandstormMinHrs()
    { return 2; }

// the normal sandstorm duration ceiling: 5 hours.
inline int wwySandstormMaxHrs()
    { return 5; }

// a severe sandstorm (gale-driven) lasts 1d6+1 hours.
inline int wwySandstormSevDieSides()
    { return 6; }

// the +1 on the 1d6 duration roll.
inline int wwySandstormSevDiePlus()
    { return 1; }

// the severe sandstorm duration floor: 2 hours.
inline int wwySandstormSevMinHrs()
    { return 2; }

// the severe sandstorm duration ceiling: 7 hours.
inline int wwySandstormSevMaxHrs()
    { return 7; }

// ---- Tornado ----

// a tornado occurs only when conditions are suitable: only in areas where
// tornados are known to occur, and only during special weather
// determinations.
inline bool wwyTornadoConditionsSuitable()
    { return true; }

// a tornado requires the temperature to be at least 2 steps above normal for
// the day.
inline bool wwyTornadoTempTwoStepsAbove()
    { return true; }

// the tornado is preceded by 1d3 hours of strong wind and heavy
// precipitation.
inline int wwyTornadoPrecipDieSides()
    { return 3; }

// the heavy rain of the tornado front stops abruptly as the tornado
// approaches.
inline bool wwyTornadoRainStopsAbruptly()
    { return true; }

// within one-half mile of the tornado path the air is calm.
inline bool wwyTornadoCalmNearPath()
    { return true; }

// after the rain stops, 3d6 minutes pass before the tornado arrives.
inline int wwyTornadoCalmDice()
    { return 3; }

// the d6 of the 3d6 calm delay.
inline int wwyTornadoCalmDieSides()
    { return 6; }

// during the tornado the temperature drops 15 degrees Fahrenheit or 3
// letter-scale steps, whichever is the greater.
inline int wwyTornadoDropDegreesF()
    { return 15; }

// the step-alternative of the temperature drop (the greater of the two
// applies).
inline int wwyTornadoDropSteps()
    { return 3; }

// the 15-degree or 3-step temperature drop takes the greater of the two
// measures.
inline bool wwyTornadoDropGreater()
    { return true; }

// the temperature drop takes place over 30 minutes and holds for the
// following half hour.
inline int wwyTornadoDropMinutes()
    { return 30; }

// after the tornado passes the calm lasts the rest of the day.
inline bool wwyTornadoCalmRestOfDay()
    { return true; }

// the tornado path averages one-quarter mile in width.
inline int wwyTornadoPathWidthQMi()
    { return 1; }

// the tornado path averages 15 miles long.
inline int wwyTornadoPathLengthMi()
    { return 15; }

// the tornado travels along its path at about 40 mph.
inline int wwyTornadoTravelMph()
    { return 40; }

// the winds inside the vortex are 200-300 mph.
inline int wwyTornadoVortexMinMph()
    { return 200; }

// the vortex wind ceiling.
inline int wwyTornadoVortexMaxMph()
    { return 300; }

// the extremely low air pressure inside the vortex can cause sealed
// structures to explode.
inline bool wwyTornadoLowPressureExplosion()
    { return true; }

// ---- Extreme precipitation and the dispatch table ----

// when the code letter X is selected, cross-index the temperature with the
// climatic column and roll 1d6 on the dispatch table to determine the type of
// extreme precipitation.
inline bool wwyExtremePrecipSubroll()
    { return true; }

// the extreme-precipitation dispatch: 7 temperature bands x 2 climatic
// columns x the 1d6 sub-roll.
inline int wwyXDisBands()
    { return 7; }

// a dispatch result of none: no precipitation beyond the ordinary.
inline int wwyXSubNone()
    { return 0; }

// the dispatch letter H: hailstorm.
inline int wwyXSubHail()
    { return 1; }

// the dispatch letter I: ice storm or sleet.
inline int wwyXSubIceSleet()
    { return 2; }

// the dispatch letter L: lightning storm.
inline int wwyXSubLightning()
    { return 3; }

// the dispatch letter S: severe snowstorm.
inline int wwyXSubSevereSnow()
    { return 4; }

// in the 10-29 band the ice/sleet result of the dispatch carries the
// 25-degree minimum-temperature requirement.
inline bool wwyXDisIceNeeds25F()
    { return true; }

// in the 10-29 degree band, ice or sleet results only if the temperature is
// 25 degrees or higher; below that the sub-roll indicates no precipitation.
inline int wwyXDisIceMinTempF()
    { return 25; }

// the dispatch temperature band 0: -1 degree or lower.
inline int wwyXDisBand0HiF()
    { return -1; }

// band 1: 0 degrees.
inline int wwyXDisBand1LoF()
    { return 0; }

// band 1: through 9 degrees.
inline int wwyXDisBand1HiF()
    { return 9; }

// band 2: 10 degrees.
inline int wwyXDisBand2LoF()
    { return 10; }

// band 2: through 29 degrees.
inline int wwyXDisBand2HiF()
    { return 29; }

// band 3: 30 degrees.
inline int wwyXDisBand3LoF()
    { return 30; }

// band 3: through 35 degrees.
inline int wwyXDisBand3HiF()
    { return 35; }

// band 4: 36 degrees.
inline int wwyXDisBand4LoF()
    { return 36; }

// band 4: through 49 degrees.
inline int wwyXDisBand4HiF()
    { return 49; }

// band 5: 50 degrees.
inline int wwyXDisBand5LoF()
    { return 50; }

// band 5: through 74 degrees.
inline int wwyXDisBand5HiF()
    { return 74; }

// band 6: 75 degrees and above.
inline int wwyXDisBand6LoF()
    { return 75; }

// the tropical/subtropical column, sub-roll 1 on 1d6
inline int wwtXDisTr1(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the tropical/subtropical column, sub-roll 2
inline int wwtXDisTr2(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the tropical/subtropical column, sub-roll 3
inline int wwtXDisTr3(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the tropical/subtropical column, sub-roll 4
inline int wwtXDisTr4(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the tropical/subtropical column, sub-roll 5
inline int wwtXDisTr5(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the tropical/subtropical column, sub-roll 6
inline int wwtXDisTr6(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the temperate/subarctic/arctic column, sub-roll 1 on 1d6
inline int wwtXDisTa1(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the temperate/subarctic/arctic column, sub-roll 2
inline int wwtXDisTa2(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the temperate/subarctic/arctic column, sub-roll 3
inline int wwtXDisTa3(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the temperate/subarctic/arctic column, sub-roll 4
inline int wwtXDisTa4(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the temperate/subarctic/arctic column, sub-roll 5
inline int wwtXDisTa5(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// the temperate/subarctic/arctic column, sub-roll 6
inline int wwtXDisTa6(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 3;
        default:
            return -1;
        }
    }

// ---- Hailstorm ----

// hail falls during the first 10 minutes of a lightning storm when the
// dispatch indicates hail.
inline int wwyHailLightningFirstMin()
    { return 10; }

// a standalone hailstorm (unconnected to a lightning storm) occurs on a roll
// of 1 on 1d6 during an extreme-precipitation determination.
inline int wwyHailStandaloneD6()
    { return 1; }

// a hailstorm lasts 1d6+4 minutes.
inline int wwyHailDieSides()
    { return 6; }

// the +4 on the 1d6 duration roll.
inline int wwyHailDiePlus()
    { return 4; }

// the hailstorm duration floor: 5 minutes.
inline int wwyHailMinMin()
    { return 5; }

// the hailstorm duration ceiling: 10 minutes.
inline int wwyHailMaxMin()
    { return 10; }

// hailstones are typically one-quarter inch in diameter.
inline int wwyHailTypicalQtrIn()
    { return 1; }

// hailstones can grow to 2-3 inches in diameter.
inline int wwyHailMaxLoIn()
    { return 2; }

// the hailstone size ceiling.
inline int wwyHailMaxHiIn()
    { return 3; }

// hail melts when the temperature is 40 degrees or above.
inline int wwyHailMeltMinF()
    { return 40; }

// ---- Ice storm and sleet ----

// an ice storm coats the ground and surfaces with one-half to three-quarters
// of an inch of ice (pinned in eighths: 4 to 6).
inline int wwyIceCoatLoEighthIn()
    { return 4; }

// the high bound of the ice coating, in eighths.
inline int wwyIceCoatHiEighthIn()
    { return 6; }

// a full coating forms after 20 minutes of heavy icing conditions.
inline int wwyIceFromHeavyMin()
    { return 20; }

// under trace icing the coating can take as long as 2 hours to form.
inline int wwyIceTraceMaxHrs()
    { return 2; }

// ---- Lightning ----

// a lightning storm lasts about 25 minutes.
inline int wwyLightningDurationMin()
    { return 25; }

// the lightning storm drops three-quarters to 1 inch of rain (pinned in
// eighths: 6 to 8).
inline int wwyLightningRainLoEighthIn()
    { return 6; }

// the high bound of the lightning-storm rainfall, in inches.
inline int wwyLightningRainHiIn()
    { return 1; }

// lightning storms favor the dawn and dusk windows: about half fall within
// two hours either side of sunrise or sunset.
inline bool wwyLightningHalfAtTwilight()
    { return true; }

// half of all lightning storms occur within two hours of sunrise or sunset.
inline int wwyLightningTwilightHrs()
    { return 2; }

// a lightning result on the dispatch under moderate or light precipitation
// maximums is disregarded (it rides the stronger storm types).
inline bool wwyLightningStandaloneDisregarded()
    { return true; }

// in a downpour the lightning storm occurs at the start of the precipitation.
inline bool wwyLightningAtDownpourStart()
    { return true; }

// ---- Severe snowstorm ----

// a severe snowstorm on a day of moderate-maximum precipitation drops 1d6+4
// inches of snow.
inline int wwySevereSnowModDieSides()
    { return 6; }

// the +4 on the 1d6 snowfall roll.
inline int wwySevereSnowModDiePlus()
    { return 4; }

// the moderate-max snowfall floor: 5 inches.
inline int wwySevereSnowModInLo()
    { return 5; }

// the moderate-max snowfall ceiling: 10 inches.
inline int wwySevereSnowModInHi()
    { return 10; }

// on a heavy-maximum day the severe snowstorm drops 1d6+6 inches.
inline int wwySevereSnowHeavyDieSides()
    { return 6; }

// the +6 on the 1d6 snowfall roll.
inline int wwySevereSnowHeavyDiePlus()
    { return 6; }

// the heavy-max snowfall floor: 7 inches.
inline int wwySevereSnowHeavyInLo()
    { return 7; }

// the heavy-max snowfall ceiling: 12 inches.
inline int wwySevereSnowHeavyInHi()
    { return 12; }

// the snow of a severe snowstorm falls at about 1 inch per hour.
inline int wwySevereSnowRateInPerHr()
    { return 1; }

// a severe snowstorm starts calm and turns windy: after 1-2 hours of snow the
// wind rises to very strong, 15-20 mph.
inline bool wwySevereSnowWindAfter()
    { return true; }

// after 1-2 hours the wind picks up to very strong: 15-20 mph.
inline int wwySevereSnowWindLoMph()
    { return 15; }

// the wind ceiling of the follow-on blow.
inline int wwySevereSnowWindHiMph()
    { return 20; }

// the wind picks up after 1-2 hours of snowfall.
inline int wwySevereSnowWindHrsLo()
    { return 1; }

// the high bound of the calm window.
inline int wwySevereSnowWindHrsHi()
    { return 2; }

// ---- Humidity: the Table A5 variation grid ----

// the Table A5 humidity grid: the same 33-row climate/terrain model as Table
// A4, x 4 seasons; the arctic block (all five terrains) is uniformly low.
inline int wwyA5Count()
    { return 33; }

// the humidity letter codes: L (low) = 1.
inline int wwyHumLevelLow()
    { return 1; }

// M (medium) = 2.
inline int wwyHumLevelMed()
    { return 2; }

// H (high) = 3.
inline int wwyHumLevelHigh()
    { return 3; }

// below low is dry: 0-20 percent relative humidity.
inline int wwyHumDryMaxPct()
    { return 20; }

// low: 21-40 percent.
inline int wwyHumLowLoPct()
    { return 21; }

// the low band ceiling.
inline int wwyHumLowHiPct()
    { return 40; }

// medium: 41-70 percent.
inline int wwyHumMedLoPct()
    { return 41; }

// the medium band ceiling.
inline int wwyHumMedHiPct()
    { return 70; }

// high: 71-90 percent.
inline int wwyHumHiLoPct()
    { return 71; }

// the high band ceiling.
inline int wwyHumHiHiPct()
    { return 90; }

// above high is saturated: 91-100 percent.
inline int wwyHumSatLoPct()
    { return 91; }

// the saturated band ceiling.
inline int wwyHumSatHiPct()
    { return 100; }

// the humidity level for Winter (1 = low, 2 = medium, 3 = high)
inline int wwtA5Wi(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 1;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 2;
        case 19:
            return 1;
        case 20:
            return 3;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 2;
        case 24:
            return 2;
        case 25:
            return 2;
        case 26:
            return 1;
        case 27:
            return 3;
        case 28:
            return 2;
        case 29:
            return 2;
        case 30:
            return 2;
        case 31:
            return 2;
        case 32:
            return 2;
        default:
            return -1;
        }
    }

// the humidity level for Spring
inline int wwtA5Sp(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 2;
        case 11:
            return 2;
        case 12:
            return 1;
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
            return 3;
        case 19:
            return 1;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 3;
        case 24:
            return 3;
        case 25:
            return 3;
        case 26:
            return 1;
        case 27:
            return 3;
        case 28:
            return 2;
        case 29:
            return 3;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 3;
        default:
            return -1;
        }
    }

// the humidity level for Summer
inline int wwtA5Su(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 1;
        case 16:
            return 3;
        case 17:
            return 2;
        case 18:
            return 3;
        case 19:
            return 1;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 3;
        case 25:
            return 3;
        case 26:
            return 1;
        case 27:
            return 3;
        case 28:
            return 3;
        case 29:
            return 3;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 3;
        default:
            return -1;
        }
    }

// the humidity level for Autumn
inline int wwtA5Au(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 2;
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
            return 1;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 2;
        case 26:
            return 1;
        case 27:
            return 3;
        case 28:
            return 2;
        case 29:
            return 3;
        case 30:
            return 3;
        case 31:
            return 2;
        case 32:
            return 3;
        default:
            return -1;
        }
    }

// ---- Humidity: the day 1 / day 2 adjustment ----

// the day 1 / day 2 humidity adjustment: 3 x 3, the day 1 precipitation (none
// / light or trace / medium or more) against the day 2.
inline int wwyHumAdjRows()
    { return 3; }

// humidity fluctuates one level to either side of the Table A5 level as
// weather changes (a three-level range).
inline bool wwyHumFluctuatesOneLevel()
    { return true; }

// a fluctuation below low reads dry (0-20 percent).
inline bool wwyHumLowEdgeDry()
    { return true; }

// a fluctuation above high reads saturated (91-100 percent).
inline bool wwyHumHighEdgeSaturated()
    { return true; }

// the Dungeon Master may allow a two-level drop in exceptional conditions (a
// cold front after a rainstorm).
inline bool wwyHumDMTwoLevelDrop()
    { return true; }

// the humidity step adjustment taken BEFORE the day 2 precipitation, day 2
// column none
inline int wwtHumAdjBefore0(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return -1;
        }
    }

// the day 2 column light or trace
inline int wwtHumAdjBefore1(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return -1;
        }
    }

// the day 2 column medium or more
inline int wwtHumAdjBefore2(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        default:
            return -1;
        }
    }

// the humidity step adjustment taken AFTER the day 2 precipitation, day 2
// column none
inline int wwtHumAdjAfter0(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        default:
            return -1;
        }
    }

// the day 2 column light or trace
inline int wwtHumAdjAfter1(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return -1;
        default:
            return -1;
        }
    }

// the day 2 column medium or more
inline int wwtHumAdjAfter2(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return -1;
        }
    }

// ---- Humidity and effective temperature: Table A6 ----

// the Table A6 humidity / effective temperature grid: 5 temperature bands x 5
// humidity levels x 5 wind columns, 25 rows.
inline int wwyA6Count()
    { return 25; }

// the humidity adjustment to effective temperature applies when the actual
// temperature is 60 degrees or above.
inline int wwyEffTempApplyMinF()
    { return 60; }

// the A6 temperature band 1: 60-64 degrees.
inline int wwyA6Band1LoF()
    { return 60; }

// the band 1 ceiling.
inline int wwyA6Band1HiF()
    { return 64; }

// the A6 temperature band 2: 65-74 degrees.
inline int wwyA6Band2LoF()
    { return 65; }

// the band 2 ceiling.
inline int wwyA6Band2HiF()
    { return 74; }

// the A6 temperature band 3: 75-84 degrees.
inline int wwyA6Band3LoF()
    { return 75; }

// the band 3 ceiling.
inline int wwyA6Band3HiF()
    { return 84; }

// the A6 temperature band 4: 85-94 degrees.
inline int wwyA6Band4LoF()
    { return 85; }

// the band 4 ceiling.
inline int wwyA6Band4HiF()
    { return 94; }

// the A6 temperature band 5: 95 degrees and above.
inline int wwyA6Band5LoF()
    { return 95; }

// the A6 wind columns: 0-10 mph, 11-20, 21-30, 31-45, and 45+ (the high bound
// of the first column).
inline int wwyWindCol0HiMph()
    { return 10; }

// the second wind column low bound.
inline int wwyWindCol1LoMph()
    { return 11; }

// the second wind column high bound.
inline int wwyWindCol1HiMph()
    { return 20; }

// the third wind column low bound.
inline int wwyWindCol2LoMph()
    { return 21; }

// the third wind column high bound.
inline int wwyWindCol2HiMph()
    { return 30; }

// the fourth wind column low bound.
inline int wwyWindCol3LoMph()
    { return 31; }

// the fourth wind column high bound.
inline int wwyWindCol3HiMph()
    { return 45; }

// the fifth wind column: 45 mph and above.
inline int wwyWindCol4LoMph()
    { return 45; }

// the effective-temperature adjustment at wind 0-10 mph
inline int wwtA6W0(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 10;
        case 10:
            return 0;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 10;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 5;
        case 17:
            return 10;
        case 18:
            return 15;
        case 19:
            return 20;
        case 20:
            return 0;
        case 21:
            return 10;
        case 22:
            return 15;
        case 23:
            return 20;
        case 24:
            return 25;
        default:
            return -1;
        }
    }

// the adjustment at wind 11-20 mph
inline int wwtA6W1(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 10;
        case 15:
            return 0;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 10;
        case 19:
            return 15;
        case 20:
            return 0;
        case 21:
            return 5;
        case 22:
            return 10;
        case 23:
            return 15;
        case 24:
            return 20;
        default:
            return -1;
        }
    }

// the adjustment at wind 21-30 mph
inline int wwtA6W2(int b)
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
            return 5;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 10;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 5;
        case 23:
            return 10;
        case 24:
            return 15;
        default:
            return -1;
        }
    }

// the adjustment at wind 31-45 mph
inline int wwtA6W3(int b)
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
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 5;
        case 23:
            return 5;
        case 24:
            return 10;
        default:
            return -1;
        }
    }

// the adjustment at wind 45+ mph
inline int wwtA6W4(int b)
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
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 5;
        case 24:
            return 5;
        default:
            return -1;
        }
    }

// ---- Wind chill: Table A7 ----

// the Table A7 wind chill grid: 17 temperature rows x 8 wind columns.
inline int wwyA7Count()
    { return 17; }

// the wind chill table runs from an actual temperature of 35 degrees.
inline int wwyChillMaxTempF()
    { return 35; }

// the wind chill table runs down to an actual temperature of -45 degrees.
inline int wwyChillMinTempF()
    { return -45; }

// the temperature rows step by 5 degrees from 35 down to -45.
inline int wwyChillStepF()
    { return 5; }

// the wind columns run from 5 mph.
inline int wwyChillWindCol0Mph()
    { return 5; }

// the wind columns step by 5 mph to 40 mph.
inline int wwyChillWindColStepMph()
    { return 5; }

// for temperatures lower than -45, extrapolate downward following the pattern
// of the decrease from -40 to -45.
inline bool wwyChillExtrapBelow()
    { return true; }

// for wind speeds greater than 40 mph, use the 40-mph column; greater wind
// speeds have little if any additional chilling effect.
inline bool wwyChillExtrapAbove40Mph()
    { return true; }

// the effective temperature at 5 mph wind
inline int wwtA7C0(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 25;
        case 2:
            return 20;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 5;
        case 6:
            return 0;
        case 7:
            return -5;
        case 8:
            return -10;
        case 9:
            return -15;
        case 10:
            return -20;
        case 11:
            return -25;
        case 12:
            return -30;
        case 13:
            return -35;
        case 14:
            return -40;
        case 15:
            return -45;
        case 16:
            return -50;
        default:
            return -1;
        }
    }

// the effective temperature at 10 mph
inline int wwtA7C1(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 15;
        case 2:
            return 10;
        case 3:
            return 0;
        case 4:
            return -5;
        case 5:
            return -10;
        case 6:
            return -15;
        case 7:
            return -20;
        case 8:
            return -25;
        case 9:
            return -30;
        case 10:
            return -40;
        case 11:
            return -45;
        case 12:
            return -50;
        case 13:
            return -60;
        case 14:
            return -65;
        case 15:
            return -70;
        case 16:
            return -75;
        default:
            return -1;
        }
    }

// the effective temperature at 15 mph
inline int wwtA7C2(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return -5;
        case 4:
            return -10;
        case 5:
            return -20;
        case 6:
            return -25;
        case 7:
            return -35;
        case 8:
            return -40;
        case 9:
            return -45;
        case 10:
            return -50;
        case 11:
            return -60;
        case 12:
            return -65;
        case 13:
            return -70;
        case 14:
            return -80;
        case 15:
            return -85;
        case 16:
            return -90;
        default:
            return -1;
        }
    }

// the effective temperature at 20 mph
inline int wwtA7C3(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 5;
        case 2:
            return -5;
        case 3:
            return -10;
        case 4:
            return -15;
        case 5:
            return -25;
        case 6:
            return -30;
        case 7:
            return -40;
        case 8:
            return -45;
        case 9:
            return -50;
        case 10:
            return -60;
        case 11:
            return -70;
        case 12:
            return -75;
        case 13:
            return -80;
        case 14:
            return -90;
        case 15:
            return -95;
        case 16:
            return -100;
        default:
            return -1;
        }
    }

// the effective temperature at 25 mph
inline int wwtA7C4(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 0;
        case 2:
            return -5;
        case 3:
            return -15;
        case 4:
            return -20;
        case 5:
            return -30;
        case 6:
            return -35;
        case 7:
            return -45;
        case 8:
            return -50;
        case 9:
            return -60;
        case 10:
            return -70;
        case 11:
            return -75;
        case 12:
            return -85;
        case 13:
            return -90;
        case 14:
            return -95;
        case 15:
            return -105;
        case 16:
            return -110;
        default:
            return -1;
        }
    }

// the effective temperature at 30 mph
inline int wwtA7C5(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 0;
        case 2:
            return -10;
        case 3:
            return -20;
        case 4:
            return -25;
        case 5:
            return -35;
        case 6:
            return -40;
        case 7:
            return -50;
        case 8:
            return -55;
        case 9:
            return -60;
        case 10:
            return -75;
        case 11:
            return -80;
        case 12:
            return -90;
        case 13:
            return -95;
        case 14:
            return -100;
        case 15:
            return -110;
        case 16:
            return -115;
        default:
            return -1;
        }
    }

// the effective temperature at 35 mph
inline int wwtA7C6(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -5;
        case 2:
            return -15;
        case 3:
            return -20;
        case 4:
            return -30;
        case 5:
            return -35;
        case 6:
            return -45;
        case 7:
            return -50;
        case 8:
            return -60;
        case 9:
            return -65;
        case 10:
            return -80;
        case 11:
            return -85;
        case 12:
            return -90;
        case 13:
            return -100;
        case 14:
            return -105;
        case 15:
            return -115;
        case 16:
            return -120;
        default:
            return -1;
        }
    }

// the effective temperature at 40 mph
inline int wwtA7C7(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -5;
        case 2:
            return -15;
        case 3:
            return -25;
        case 4:
            return -30;
        case 5:
            return -40;
        case 6:
            return -45;
        case 7:
            return -55;
        case 8:
            return -65;
        case 9:
            return -70;
        case 10:
            return -80;
        case 11:
            return -90;
        case 12:
            return -95;
        case 13:
            return -100;
        case 14:
            return -110;
        case 15:
            return -115;
        case 16:
            return -120;
        default:
            return -1;
        }
    }

// ---- Hours of daylight: Table A8 ----

// the Table A8 hours of daylight grid: 15 latitude rows x 12 months.
inline int wwyA8Count()
    { return 15; }

// one column per month, 12 months to the year.
inline int wwyA8Months()
    { return 12; }

// the daylight hours are stored in half-hour units to keep the grid integral
// (24 hours = 48).
inline int wwyA8HalfHourUnits()
    { return 2; }

// the A8 latitude ladder, row 0: 90 degrees (the pole); rows 1-2 are 80 and
// 70 (the arctic block).
inline int wwyA8Lat0()
    { return 90; }

// row 3: 65 degrees; rows 4-5 are 60 and 55 (the subarctic block).
inline int wwyA8Lat3()
    { return 65; }

// row 6: 50 degrees; rows 7-8 are 40 and 35 (the temperate block).
inline int wwyA8Lat6()
    { return 50; }

// row 9: 30 degrees; rows 10-11 are 25 and 20 (the subtropical block).
inline int wwyA8Lat9()
    { return 30; }

// row 12: 15 degrees; rows 13-14 are 10 and 0 (the tropical block).
inline int wwyA8Lat12()
    { return 15; }

// row 14: the equator, 12 hours of daylight every day of the year.
inline int wwyA8Lat14()
    { return 0; }

// the shorter simplified version uses only the middle row of each climatic
// block: the 80 line for arctic, 60 for subarctic, 40 for temperate, 25 for
// subtropical, 10 for tropical - no latitude bookkeeping, only the climatic
// region.
inline bool wwyA8SimplifiedRowsOnly()
    { return true; }

// the table gives lengths, not clock times: sunrise and sunset are derived
// with midnight as the midpoint of the nighttime period and noon as the
// midpoint of the daytime period, or stipulated by the Dungeon Master.
inline bool wwyA8MidnightNightMidpoint()
    { return true; }

// the hours of daylight in month 1 (in half-hours: 48 = 24 hours)
inline int wwtA8M0(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 6;
        case 4:
            return 13;
        case 5:
            return 15;
        case 6:
            return 17;
        case 7:
            return 19;
        case 8:
            return 20;
        case 9:
            return 21;
        case 10:
            return 22;
        case 11:
            return 22;
        case 12:
            return 23;
        case 13:
            return 23;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 2
inline int wwtA8M1(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 15;
        case 3:
            return 17;
        case 4:
            return 18;
        case 5:
            return 19;
        case 6:
            return 20;
        case 7:
            return 21;
        case 8:
            return 22;
        case 9:
            return 22;
        case 10:
            return 23;
        case 11:
            return 23;
        case 12:
            return 24;
        case 13:
            return 24;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 3
inline int wwtA8M2(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 22;
        case 2:
            return 23;
        case 3:
            return 23;
        case 4:
            return 23;
        case 5:
            return 23;
        case 6:
            return 24;
        case 7:
            return 24;
        case 8:
            return 24;
        case 9:
            return 24;
        case 10:
            return 24;
        case 11:
            return 24;
        case 12:
            return 24;
        case 13:
            return 24;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 4
inline int wwtA8M3(int b)
    {
        switch (b) {
        case 0:
            return 48;
        case 1:
            return 48;
        case 2:
            return 32;
        case 3:
            return 30;
        case 4:
            return 29;
        case 5:
            return 28;
        case 6:
            return 27;
        case 7:
            return 26;
        case 8:
            return 26;
        case 9:
            return 26;
        case 10:
            return 25;
        case 11:
            return 25;
        case 12:
            return 25;
        case 13:
            return 25;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 5
inline int wwtA8M4(int b)
    {
        switch (b) {
        case 0:
            return 48;
        case 1:
            return 48;
        case 2:
            return 44;
        case 3:
            return 39;
        case 4:
            return 34;
        case 5:
            return 32;
        case 6:
            return 31;
        case 7:
            return 29;
        case 8:
            return 28;
        case 9:
            return 27;
        case 10:
            return 26;
        case 11:
            return 26;
        case 12:
            return 25;
        case 13:
            return 25;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 6
inline int wwtA8M5(int b)
    {
        switch (b) {
        case 0:
            return 48;
        case 1:
            return 48;
        case 2:
            return 48;
        case 3:
            return 43;
        case 4:
            return 38;
        case 5:
            return 35;
        case 6:
            return 33;
        case 7:
            return 30;
        case 8:
            return 29;
        case 9:
            return 28;
        case 10:
            return 27;
        case 11:
            return 27;
        case 12:
            return 26;
        case 13:
            return 26;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 7
inline int wwtA8M6(int b)
    {
        switch (b) {
        case 0:
            return 48;
        case 1:
            return 48;
        case 2:
            return 48;
        case 3:
            return 40;
        case 4:
            return 35;
        case 5:
            return 33;
        case 6:
            return 31;
        case 7:
            return 29;
        case 8:
            return 28;
        case 9:
            return 28;
        case 10:
            return 27;
        case 11:
            return 26;
        case 12:
            return 26;
        case 13:
            return 26;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 8
inline int wwtA8M7(int b)
    {
        switch (b) {
        case 0:
            return 48;
        case 1:
            return 48;
        case 2:
            return 37;
        case 3:
            return 34;
        case 4:
            return 32;
        case 5:
            return 30;
        case 6:
            return 29;
        case 7:
            return 28;
        case 8:
            return 27;
        case 9:
            return 26;
        case 10:
            return 26;
        case 11:
            return 26;
        case 12:
            return 25;
        case 13:
            return 25;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 9
inline int wwtA8M8(int b)
    {
        switch (b) {
        case 0:
            return 48;
        case 1:
            return 31;
        case 2:
            return 27;
        case 3:
            return 27;
        case 4:
            return 26;
        case 5:
            return 26;
        case 6:
            return 25;
        case 7:
            return 25;
        case 8:
            return 25;
        case 9:
            return 25;
        case 10:
            return 24;
        case 11:
            return 24;
        case 12:
            return 24;
        case 13:
            return 24;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 10
inline int wwtA8M9(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 18;
        case 3:
            return 19;
        case 4:
            return 20;
        case 5:
            return 21;
        case 6:
            return 22;
        case 7:
            return 22;
        case 8:
            return 23;
        case 9:
            return 23;
        case 10:
            return 23;
        case 11:
            return 23;
        case 12:
            return 24;
        case 13:
            return 24;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 11
inline int wwtA8M10(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 6;
        case 3:
            return 10;
        case 4:
            return 15;
        case 5:
            return 17;
        case 6:
            return 18;
        case 7:
            return 20;
        case 8:
            return 20;
        case 9:
            return 21;
        case 10:
            return 22;
        case 11:
            return 22;
        case 12:
            return 23;
        case 13:
            return 23;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// the hours of daylight in month 12
inline int wwtA8M11(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 6;
        case 4:
            return 12;
        case 5:
            return 14;
        case 6:
            return 16;
        case 7:
            return 19;
        case 8:
            return 20;
        case 9:
            return 20;
        case 10:
            return 21;
        case 11:
            return 22;
        case 12:
            return 23;
        case 13:
            return 23;
        case 14:
            return 24;
        default:
            return -1;
        }
    }

// ---- Twilight ----

// each of the two daily twilight periods lasts about 30 minutes at the middle
// latitudes.
inline int wwyTwilightMidLatMin()
    { return 30; }

// the middle-latitude band: 30-40 degrees.
inline int wwyTwilightMidLatLoDeg()
    { return 30; }

// the middle-latitude band ceiling.
inline int wwyTwilightMidLatHiDeg()
    { return 40; }

// twilight decreases to a minimum of 20 minutes at the equator.
inline int wwyTwilightEquatorMin()
    { return 20; }

// twilight increases to 40 minutes at relatively high latitudes.
inline int wwyTwilightHighLatMin()
    { return 40; }

// the high-latitude band: 50-60 degrees.
inline int wwyTwilightHighLatLoDeg()
    { return 50; }

// the high-latitude band ceiling.
inline int wwyTwilightHighLatHiDeg()
    { return 60; }

// local terrain can cut twilight to 5-10 minutes (a dense forest, the shaded
// side of a mountain).
inline int wwyTwilightTerrainMinLo()
    { return 5; }

// the terrain-cut twilight ceiling.
inline int wwyTwilightTerrainMinHi()
    { return 10; }

// where the daylight table reads zero, the day is not black: the period is
// one of twilight, not true darkness (the arctic winter).
inline bool wwyTwilightAllDayWhereNoDaylight()
    { return true; }

// ---- Local winds ----

// during the day the land heats faster than the water: a sea breeze blows
// from the water toward the land.
inline bool wwySeaBreezeDayWaterToLand()
    { return true; }

// at night the land cools faster: a land breeze blows from the land toward
// the water.
inline bool wwyLandBreezeNight()
    { return true; }

// the daytime sea breeze is stronger than the nighttime land breeze.
inline bool wwySeaBreezeStronger()
    { return true; }

// a sea breeze reaches 5-10 miles inland.
inline int wwySeaBreezeInlandMinMi()
    { return 5; }

// the sea-breeze inland reach ceiling.
inline int wwySeaBreezeInlandMaxMi()
    { return 10; }

// clear skies favor both breezes (maximum heating and cooling differential);
// cloud cover reduces them.
inline bool wwyClearSkiesFavorBreezes()
    { return true; }

// a sea breeze can lower the coastal temperature by as much as 20 degrees on
// a hot day (the Lake Michigan breeze).
inline bool wwySeaBreezeCanChillCoast()
    { return true; }

// in the lee of a cliff face the wind swirls, is trapped, or dies to a calm -
// local terrain dominates over the regional wind.
inline bool wwyCliffFacesTrapSwirlCalm()
    { return true; }

// ---- Tides ----

// the two daily tides alternate high and low, in equal numbers of high and
// low waters.
inline bool wwyTidesTwiceDailyAlternating()
    { return true; }

// there are two high tides and two low tides daily, alternating; about 12
// hours pass between one high tide and the next.
inline int wwyTideHoursBetweenHighs()
    { return 12; }

// low tide comes about 6 hours after high tide.
inline int wwyTideLowAfterHighHrs()
    { return 6; }

// the lunar day runs about 25 hours, so the whole tidal cycle advances about
// an hour later each day.
inline int wwyLunarDayRoughHrs()
    { return 25; }

// the daily tidal advance, pinned in minutes.
inline int wwyTideAdvanceMinPerDay()
    { return 60; }

// the full tidal cycle repeats with the 28-day lunar cycle.
inline int wwyTideCycleDays()
    { return 28; }

// spring tides (the stronger tides) fall in the windows around the full and
// the new moon; neap tides fill the rest of the cycle.
inline bool wwySpringTidesAroundFullNew()
    { return true; }

// spring tides occur in roughly 7-day windows around the full and new moon;
// the rest of the cycle is neap tides.
inline int wwySpringWindowDays()
    { return 7; }

// an average neap tide runs 5-7 feet from high to low.
inline int wwyNeapRangeFtLo()
    { return 5; }

// the neap range ceiling.
inline int wwyNeapRangeFtHi()
    { return 7; }

// an average spring tide runs 15-18 feet from high to low.
inline int wwySpringRangeFtLo()
    { return 15; }

// the spring range ceiling.
inline int wwySpringRangeFtHi()
    { return 18; }

// extreme coastal configurations can multiply the range (the Bay of Fundy
// reaches 60 feet).
inline int wwyFundyMaxFt()
    { return 60; }

// tidal encroachment on a gently sloped shore (30 degrees or less): the water
// encroaches 4-5 times the tide height.
inline int wwyGentleSlopeMaxDeg()
    { return 30; }

// the gentle-slope encroachment low multiple.
inline int wwyGentleEncroachLoX()
    { return 4; }

// the gentle-slope encroachment high multiple.
inline int wwyGentleEncroachHiX()
    { return 5; }

// a moderately sloped shore runs 31-50 degrees.
inline int wwyModerateSlopeLoDeg()
    { return 31; }

// the moderate-slope ceiling.
inline int wwyModerateSlopeHiDeg()
    { return 50; }

// the moderate-slope encroachment: 2-3 times the tide height.
inline int wwyModerateEncroachLoX()
    { return 2; }

// the moderate-slope high multiple.
inline int wwyModerateEncroachHiX()
    { return 3; }

// a severely sloped shore runs 51-70 degrees.
inline int wwySevereSlopeLoDeg()
    { return 51; }

// the severe-slope ceiling.
inline int wwySevereSlopeHiDeg()
    { return 70; }

// the severe-slope encroachment: 1-2 times the tide height.
inline int wwySevereEncroachLoX()
    { return 1; }

// the severe-slope high multiple.
inline int wwySevereEncroachHiX()
    { return 2; }

// the worked gentle-slope example: a 15-foot spring high tide.
inline int wwyTideExampleGentleFt()
    { return 15; }

// the example encroaches 60-75 feet (4 x 15 to 5 x 15).
inline int wwyTideExampleGentleEncroachLoFt()
    { return 60; }

// the example ceiling.
inline int wwyTideExampleGentleEncroachHiFt()
    { return 75; }

// the worked moderate-slope example: a 5-foot tide.
inline int wwyTideExampleModerateFt()
    { return 5; }

// the example encroaches 10-15 feet (2 x 5 to 3 x 5).
inline int wwyTideExampleModerateEncroachLoFt()
    { return 10; }

// the example ceiling.
inline int wwyTideExampleModerateEncroachHiFt()
    { return 15; }

// ---- The Dungeon Master responsibility ----

// the Dungeon Master determines the weather 2-3 days in advance of the play
// session, keeping the determination hidden until it comes into play.
inline bool wwyDMDetermine2to3Days()
    { return true; }

// the DM switches freely between determining weather one day at a time,
// several days at once, or whole weeks - whatever the pace of play demands.
inline bool wwyDMSwitchTimeframesFreely()
    { return true; }

// for multi-day outings (long journeys, expeditions) the DM predetermines the
// weather for the entire span before play begins.
inline bool wwyDMPredetermineMultiDay()
    { return true; }

}   // namespace rules
