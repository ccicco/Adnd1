// =========================================================================================
// Adnd1 - rules/wsgtempfold.h
// The WSG TEMPERATURE-CHAIN FOLD, R499: the first seam round after the gap
// report closed at 186/0. The dressing columns (rules/wsgdress.h), the heat
// bands and the frostbite threshold (rules/wsgheat.h), the weather letter
// codes (rules/wsgweather.h) and the survival shifts (rules/wsgprofd.h)
// reconciled as one system: every wilderness temperature flows from one
// generated number through exactly one dress column and exactly one heat
// band.
// census 423 -> 424.
//
// No new book pages: every value is the landed original re-read from its
// header (wsdColForTemp, wshHeatBandFor, wshFrostbiteTempMax,
// wshT9DashUnprotCensus, wwsTempCodeHi, wpdSurvColdEffShift and kin) and
// re-pinned on the fold side so the boundary identities compile and ride the
// mutant battery. The findings: the three true alignments (the moderate
// column and band 16 open at the same 31; band 15 and the cold column top at
// the same 30; the frostbite threshold equals the below-0 boundary value),
// the deliberate non-alignment (the hot column opens at 76 inside the 31-84
// no-damage band), the finer dress grid (moderate tops at 75, no-damage runs
// to 84) and the protected widening (6 through 89).
//
// THE SETTLE: census 423 -> 424; the gap report stays 186 closed / 0 open
// (closed - no flips this round); the chain has no gaps.
//
namespace rules {

// ---- the dressing side ----

// the four personal-effective-temperature columns of the dress Table 3
// dispatch (wsdColCount).
inline int wtfDressColCount()
    { return 4; }

// the below-0 column opens below this boundary value (wsdColForTemp col 0).
inline int wtfDressBelow0Bound()
    { return 0; }

// the cold column runs 0 through 30 (wsdColForTemp col 1 top).
inline int wtfDressColdTop()
    { return 30; }

// the moderate column opens at 31 (wsdColForTemp col 2).
inline int wtfDressModLo()
    { return 31; }

// the moderate column tops at 75.
inline int wtfDressModTop()
    { return 75; }

// the hot column opens at 76 (wsdColForTemp col 3).
inline int wtfDressHotLo()
    { return 76; }

// ---- the fold findings ----

// the dress moderate column and the heat no-damage band open at the same 31 -
// a true boundary alignment.
inline bool wtfModOpensWithNoDmg()
    { return true; }

// the frostbite threshold value equals the dress below-0 boundary value: the
// cold regime opens where frostbite begins.
inline bool wtfFrostAtBelow0Bound()
    { return true; }

// band 15 tops at the same 30 that tops the cold column - the second true
// alignment.
inline bool wtfBand15TopsWithColdCol()
    { return true; }

// the dress hot column opens at 76, eight degrees inside the no-damage band -
// a deliberate non-alignment: attire adjusts before the Table 9 damage
// resumes at 85.
inline bool wtfHotOpensInsideNoDmg()
    { return true; }

// the moderate column ends at 75 while the no-damage band runs to 84 - the
// dress grid is finer than the damage grid.
inline bool wtfModNarrowerThanNoDmg()
    { return true; }

// cold survival at its 30-degree bound shifts to 50 - inside the no-damage
// band and inside the moderate column.
inline bool wtfSurvColdLandsNoDmg()
    { return true; }

// heat survival at its 80-degree bound shifts to 60 - inside the moderate
// column and the no-damage band.
inline bool wtfSurvHeatLandsModCol()
    { return true; }

// the protected no-damage span (6 through 89) is wider on both ends than the
// bare 31 through 84.
inline bool wtfProtWiderThanUnprot()
    { return true; }

// the letter codes run from below-20 to 115, bracketing the frostbite
// threshold and every heat band below the 120-plus row.
inline bool wtfCodesSpanChain()
    { return true; }

// every temperature a weather code can produce lands in exactly one dress
// column and exactly one heat band - the fold has no gaps.
inline bool wtfChainHasNoGaps()
    { return true; }

// ---- the heat-band side ----

// the Table 9 temperature-damage band count (wshDmgBandCount).
inline int wtfBandCount()
    { return 25; }

// band 16 is the interior no-damage band (the dash cells).
inline int wtfBandNoDmg()
    { return 16; }

// band 16 opens at 31 degrees (wshHeatBandFor).
inline int wtfNoDmgLo()
    { return 31; }

// band 16 tops at 84 degrees.
inline int wtfNoDmgHi()
    { return 84; }

// unprotected damage resumes one degree past the no-damage top.
inline int wtfDmgResume()
    { return 85; }

// band 9 tops at 0 degrees (wshHeatBandFor).
inline int wtfBandFrostTop()
    { return 0; }

// band 15 tops at 30 degrees.
inline int wtfBandPreNoDmgTop()
    { return 30; }

// frostbite risk begins at effective temperature 0 or lower
// (wshFrostbiteTempMax).
inline int wtfFrostMax()
    { return 0; }

// the printed-dash sentinel: no Constitution check (the Table 9 cells).
inline int wtfDash()
    { return 99; }

// the Table 9 dash census, unprotected (wshT9DashUnprotCensus).
inline int wtfDashUnprot()
    { return 2; }

// the Table 9 dash census, protected (wshT9DashProtCensus).
inline int wtfDashProt()
    { return 14; }

// protected characters take no damage from 6 degrees (band 11 opens).
inline int wtfProtNoDmgLo()
    { return 6; }

// protected characters take no damage through 89 (band 17 tops).
inline int wtfProtNoDmgHi()
    { return 89; }

// ---- the survival side ----

// cold survival reads the effective temperature 20 degrees warmer
// (wpdSurvColdEffShift).
inline int wtfSurvColdShift()
    { return 20; }

// cold survival applies at 30 degrees or lower (wpdSurvColdAppliesAtOrBelow).
inline int wtfSurvColdBound()
    { return 30; }

// heat survival reads the effective temperature 20 degrees cooler
// (wpdSurvHeatEffShift).
inline int wtfSurvHeatShift()
    { return 20; }

// heat survival applies at 80 degrees or higher
// (wpdSurvHeatAppliesAtOrAbove).
inline int wtfSurvHeatBound()
    { return 80; }

// ---- the weather side ----

// the temperature letter codes A through Z (wwxTempCodeCount).
inline int wtfCodeCount()
    { return 26; }

// the D row high is 0 degrees (wwsTempCodeHi(3)).
inline int wtfCodeDHi()
    { return 0; }

// the H row high is 30 degrees (wwsTempCodeHi(7)).
inline int wtfCodeHHi()
    { return 30; }

// the Z row high is 115 degrees - the top of the letter scale.
inline int wtfCodePeakHi()
    { return 115; }

}   // namespace rules
