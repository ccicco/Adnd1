-- wtf: promoted from tools/spec_r499.json (the The WSG TEMPERATURE-CHAIN FOLD, R499: the first seam round after the gap report closed at 186/0. The dressing columns (rules/wsg/wsgdress.h), the heat bands and the frostbite threshold (rules/wsg/wsgheat.h), the weather letter codes (rules/wsg/wsgweather.h) and the survival shifts (rules/wsg/wsgprofd.h) reconciled as one system: every wilderness temperature flows from one generated number through exactly one dress column and exactly one heat band.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 499,
  "prefix" = "wtf",
  "banner" = {
      "title" = "The WSG TEMPERATURE-CHAIN FOLD, R499: the first seam round after the gap report closed at 186/0. The dressing columns (rules/wsg/wsgdress.h), the heat bands and the frostbite threshold (rules/wsg/wsgheat.h), the weather letter codes (rules/wsg/wsgweather.h) and the survival shifts (rules/wsg/wsgprofd.h) reconciled as one system: every wilderness temperature flows from one generated number through exactly one dress column and exactly one heat band.",
      "provenance" = "No new book pages: every value is the landed original re-read from its header (wsdColForTemp, wshHeatBandFor, wshFrostbiteTempMax, wshT9DashUnprotCensus, wwsTempCodeHi, wpdSurvColdEffShift and kin) and re-pinned on the fold side so the boundary identities compile and ride the mutant battery. The findings: the three true alignments (the moderate column and band 16 open at the same 31; band 15 and the cold column top at the same 30; the frostbite threshold equals the below-0 boundary value), the deliberate non-alignment (the hot column opens at 76 inside the 31-84 no-damage band), the finer dress grid (moderate tops at 75, no-damage runs to 84) and the protected widening (6 through 89).",
      "sentinel" = "THE SETTLE: census 423 -> 424; the gap report stays 186 closed / 0 open (closed - no flips this round); the chain has no gaps.",
    },
  "consts" = { {
      "comment" = "the four personal-effective-temperature columns of the dress Table 3 dispatch (wsdColCount).",
      "name" = "wtfDressColCount",
      "value" = 4,
    }, {
      "comment" = "the below-0 column opens below this boundary value (wsdColForTemp col 0).",
      "name" = "wtfDressBelow0Bound",
      "value" = 0,
    }, {
      "comment" = "the cold column runs 0 through 30 (wsdColForTemp col 1 top).",
      "name" = "wtfDressColdTop",
      "value" = 30,
    }, {
      "comment" = "the moderate column opens at 31 (wsdColForTemp col 2).",
      "name" = "wtfDressModLo",
      "value" = 31,
    }, {
      "comment" = "the moderate column tops at 75.",
      "name" = "wtfDressModTop",
      "value" = 75,
    }, {
      "comment" = "the hot column opens at 76 (wsdColForTemp col 3).",
      "name" = "wtfDressHotLo",
      "value" = 76,
    }, {
      "comment" = "the Table 9 temperature-damage band count (wshDmgBandCount).",
      "name" = "wtfBandCount",
      "value" = 25,
    }, {
      "comment" = "band 16 is the interior no-damage band (the dash cells).",
      "name" = "wtfBandNoDmg",
      "value" = 16,
    }, {
      "comment" = "band 16 opens at 31 degrees (wshHeatBandFor).",
      "name" = "wtfNoDmgLo",
      "value" = 31,
    }, {
      "comment" = "band 16 tops at 84 degrees.",
      "name" = "wtfNoDmgHi",
      "value" = 84,
    }, {
      "comment" = "unprotected damage resumes one degree past the no-damage top.",
      "name" = "wtfDmgResume",
      "value" = 85,
    }, {
      "comment" = "band 9 tops at 0 degrees (wshHeatBandFor).",
      "name" = "wtfBandFrostTop",
      "value" = 0,
    }, {
      "comment" = "band 15 tops at 30 degrees.",
      "name" = "wtfBandPreNoDmgTop",
      "value" = 30,
    }, {
      "comment" = "frostbite risk begins at effective temperature 0 or lower (wshFrostbiteTempMax).",
      "name" = "wtfFrostMax",
      "value" = 0,
    }, {
      "comment" = "the printed-dash sentinel: no Constitution check (the Table 9 cells).",
      "name" = "wtfDash",
      "value" = 99,
    }, {
      "comment" = "the Table 9 dash census, unprotected (wshT9DashUnprotCensus).",
      "name" = "wtfDashUnprot",
      "value" = 2,
    }, {
      "comment" = "the Table 9 dash census, protected (wshT9DashProtCensus).",
      "name" = "wtfDashProt",
      "value" = 14,
    }, {
      "comment" = "protected characters take no damage from 6 degrees (band 11 opens).",
      "name" = "wtfProtNoDmgLo",
      "value" = 6,
    }, {
      "comment" = "protected characters take no damage through 89 (band 17 tops).",
      "name" = "wtfProtNoDmgHi",
      "value" = 89,
    }, {
      "comment" = "the temperature letter codes A through Z (wwxTempCodeCount).",
      "name" = "wtfCodeCount",
      "value" = 26,
    }, {
      "comment" = "the D row high is 0 degrees (wwsTempCodeHi(3)).",
      "name" = "wtfCodeDHi",
      "value" = 0,
    }, {
      "comment" = "the H row high is 30 degrees (wwsTempCodeHi(7)).",
      "name" = "wtfCodeHHi",
      "value" = 30,
    }, {
      "comment" = "the Z row high is 115 degrees - the top of the letter scale.",
      "name" = "wtfCodePeakHi",
      "value" = 115,
    }, {
      "comment" = "cold survival reads the effective temperature 20 degrees warmer (wpdSurvColdEffShift).",
      "name" = "wtfSurvColdShift",
      "value" = 20,
    }, {
      "comment" = "cold survival applies at 30 degrees or lower (wpdSurvColdAppliesAtOrBelow).",
      "name" = "wtfSurvColdBound",
      "value" = 30,
    }, {
      "comment" = "heat survival reads the effective temperature 20 degrees cooler (wpdSurvHeatEffShift).",
      "name" = "wtfSurvHeatShift",
      "value" = 20,
    }, {
      "comment" = "heat survival applies at 80 degrees or higher (wpdSurvHeatAppliesAtOrAbove).",
      "name" = "wtfSurvHeatBound",
      "value" = 80,
    } },
  "bools" = { {
      "comment" = "the dress moderate column and the heat no-damage band open at the same 31 - a true boundary alignment.",
      "name" = "wtfModOpensWithNoDmg",
      "value" = true,
    }, {
      "comment" = "the frostbite threshold value equals the dress below-0 boundary value: the cold regime opens where frostbite begins.",
      "name" = "wtfFrostAtBelow0Bound",
      "value" = true,
    }, {
      "comment" = "band 15 tops at the same 30 that tops the cold column - the second true alignment.",
      "name" = "wtfBand15TopsWithColdCol",
      "value" = true,
    }, {
      "comment" = "the dress hot column opens at 76, eight degrees inside the no-damage band - a deliberate non-alignment: attire adjusts before the Table 9 damage resumes at 85.",
      "name" = "wtfHotOpensInsideNoDmg",
      "value" = true,
    }, {
      "comment" = "the moderate column ends at 75 while the no-damage band runs to 84 - the dress grid is finer than the damage grid.",
      "name" = "wtfModNarrowerThanNoDmg",
      "value" = true,
    }, {
      "comment" = "cold survival at its 30-degree bound shifts to 50 - inside the no-damage band and inside the moderate column.",
      "name" = "wtfSurvColdLandsNoDmg",
      "value" = true,
    }, {
      "comment" = "heat survival at its 80-degree bound shifts to 60 - inside the moderate column and the no-damage band.",
      "name" = "wtfSurvHeatLandsModCol",
      "value" = true,
    }, {
      "comment" = "the protected no-damage span (6 through 89) is wider on both ends than the bare 31 through 84.",
      "name" = "wtfProtWiderThanUnprot",
      "value" = true,
    }, {
      "comment" = "the letter codes run from below-20 to 115, bracketing the frostbite threshold and every heat band below the 120-plus row.",
      "name" = "wtfCodesSpanChain",
      "value" = true,
    }, {
      "comment" = "every temperature a weather code can produce lands in exactly one dress column and exactly one heat band - the fold has no gaps.",
      "name" = "wtfChainHasNoGaps",
      "value" = true,
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['wtfDressColCount']() != 4 or m['wtfDressBelow0Bound']() != 0 or m['wtfDressColdTop']() != 30 or m['wtfDressModLo']() != 31 or m['wtfDressModTop']() != 75 or m['wtfDressHotLo']() != 76",
      "note" = "the dress column boundaries",
    }, {
      "expr" = "m['wtfDressModLo']() != m['wtfNoDmgLo']()",
      "note" = "the moderate column opens exactly where the no-damage band opens - the first true alignment",
    }, {
      "expr" = "m['wtfFrostMax']() != m['wtfDressBelow0Bound']() or m['wtfBandFrostTop']() != m['wtfDressBelow0Bound']()",
      "note" = "the frostbite threshold sits at the below-0 boundary value",
    }, {
      "expr" = "m['wtfBandPreNoDmgTop']() != m['wtfDressColdTop']()",
      "note" = "band 15 tops where the cold column tops - the second true alignment",
    }, {
      "expr" = "m['wtfDressHotLo']() < m['wtfNoDmgLo']() or m['wtfDressHotLo']() > m['wtfNoDmgHi']()",
      "note" = "the hot column opens inside the no-damage band",
    }, {
      "expr" = "m['wtfNoDmgHi']() - m['wtfDressHotLo']() != 8",
      "note" = "the overlap runs eight degrees",
    }, {
      "expr" = "m['wtfDressModTop']() >= m['wtfNoDmgHi']()",
      "note" = "the moderate column is narrower than the no-damage band",
    }, {
      "expr" = "m['wtfDmgResume']() != m['wtfNoDmgHi']() + 1",
      "note" = "unprotected damage resumes one degree past the no-damage top",
    }, {
      "expr" = "m['wtfDashUnprot']() + m['wtfDashProt']() != 16 or m['wtfDash']() != 99",
      "note" = "the dash censuses match Table 9",
    }, {
      "expr" = "m['wtfProtNoDmgLo']() >= m['wtfNoDmgLo']() or m['wtfProtNoDmgHi']() <= m['wtfNoDmgHi']()",
      "note" = "protected no-damage is wider on both ends",
    }, {
      "expr" = "m['wtfSurvColdBound']() + m['wtfSurvColdShift']() < m['wtfNoDmgLo']() or m['wtfSurvColdBound']() + m['wtfSurvColdShift']() > m['wtfNoDmgHi']()",
      "note" = "cold survival at its bound lands inside the no-damage band",
    }, {
      "expr" = "m['wtfSurvHeatBound']() - m['wtfSurvHeatShift']() < m['wtfDressModLo']() or m['wtfSurvHeatBound']() - m['wtfSurvHeatShift']() > m['wtfDressModTop']()",
      "note" = "heat survival at its bound lands inside the moderate column",
    }, {
      "expr" = "m['wtfCodeCount']() != 26 or m['wtfCodeDHi']() != m['wtfFrostMax']() or m['wtfCodeHHi']() != m['wtfDressColdTop']() or m['wtfCodePeakHi']() < 90",
      "note" = "the letter codes bracket the chain",
    } },
  "audit" = {
      "label" = "R499 WSG temperature fold audit",
      "comment" = "The WSG temperature-chain fold, the first seam round after gap closure: no new book pages. Every pinned value is a landed original re-read from its header and pinned again on the fold side, so each identity compiles and rides the mutant battery. The chain: one wilderness temperature feeds the dress Table 3 column dispatch (rules/wsg/wsgdress.h wsdColForTemp, boundaries below 0, 0-30, 31-75, 76 plus), the Table 9 damage band dispatch (rules/wsg/wsgheat.h wshHeatBandFor, 25 bands, no-damage band 16 at 31-84, frostbite threshold 0), the weather letter codes (rules/wsg/wsgweather.h wwsTempCodeHi, D tops at 0, H at 30) and the R498 survival shifts (plus 20 at 30 or lower, minus 20 at 80 or higher). Three boundary alignments are true (31 with 31, 30 with 30, 0 with 0); one is a deliberate non-alignment (the hot column opens at 76, eight degrees inside the no-damage band - attire adjusts before damage resumes at 85); the protected no-damage span is wider on both ends (6 through 89).",
    },
}
