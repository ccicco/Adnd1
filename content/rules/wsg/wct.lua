-- wct: promoted from tools/spec_r495.json (the The WSG COMPILED TABLES, R495: the play-session reprint section, printed pp. 120-123 (pdf pages 121-124) - thirty of the forty-two book tables reproduced with their from-pages, the selection limited to the tables most often referred to during play. This round closes the compiled-tables gap box and COMPLETES THE WSG ARC: every section of the Wilderness Survival Guide is now pinned.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 495,
  "prefix" = "wct",
  "banner" = {
      "title" = "The WSG COMPILED TABLES, R495: the play-session reprint section, printed pp. 120-123 (pdf pages 121-124) - thirty of the forty-two book tables reproduced with their from-pages, the selection limited to the tables most often referred to during play. This round closes the compiled-tables gap box and COMPLETES THE WSG ARC: every section of the Wilderness Survival Guide is now pinned.",
      "provenance" = "WSG printed pp. 120-123, pdf pages 121-124, extracted at r493-extraction sha 5af0ac2 (tesseract full-text and tsv, x121-x124, 300 dpi; pdf 125 confirmed blank end-matter). Reconciled against the landed originals: every reprinted table was compared cell-for-cell with its R425-R494 pin (rules/wsg/wsgdress.h, wsgenvfx.h, wsgheat.h, wsgencum.h, wsganimal.h, wsgvehicle.h, wsgclimb.h, wsgcheck.h, wsgfall.h, wsgtumble.h, wsgstop.h, wsggrap.h, wsgjump.h, wsgnvis.h, wsgswim.h, wsgvessels.h, wsgcapsizing.h, wsgfood.h, wsgfish.h, wsgcarry.h, wsgtents.h, wsgsleep.h, wsgfire.h, wsgfuel.h, wsginfra.h, wsgmount.h). No new grids are pinned: the data lives in the original headers; this round pins the compilation itself - the manifest, the from-pages, the per-table reconciliation, and the one errata.",
      "sentinel" = "THE SETTLE: twenty-nine of the thirty reprints reconcile with their landed pins cell for cell, including every cell the tesseract pass shredded (the Table 19 stop grid, the Table 20 rows 4-5, the whole Table 23 and Table 24 reads, the Table 25 lower half, the Table 39 hills row, the Table 41 rows 3-4, and the six Table 42 rows whose labels garbled - all settle from the pins with nothing contradicted, and the TSV row-gap geometry confirms the fourteen Table 42 rows and the thirty-manifest in full). The ONE genuine print discrepancy is the compiled Table 32: Fair daytime 1d6-3 (original 1d6-2, both tokens legible and column-aligned at x=1600/1668 on pdf 124) and Good daytime 1d6-2 (original 1d8-2) - an errata-class reprint difference, the first found in the arc, pinned as compiled-side consts with the original pin untouched. The Table 4 attack cells (90-99 = -1, 100-109 = -2) were OCR-shredded (=3 / =0 at conf 31/70) and settled by the user direct eyeball of printed p. 120, matching the pin. The printed page span is 120-123: the footers read 120 (pdf 121), 121 (pdf 122, conf 97) and 123 (pdf 124, conf 97); the pdf 123 footer (printed 122 by the pdf-minus-one rule) OCRs ambiguously as 123 at low confidence - the pdf 124 footer at conf 97 settles the span end.",
    },
  "consts" = { {
      "name" = "wctCompiledCount",
      "value" = 30,
      "comment" = "the compiled-tables section reprints thirty of the book tables.",
    }, {
      "name" = "wctBookTableCount",
      "value" = 42,
      "comment" = "the book own Tables index runs from Table 1 through Table 42.",
    }, {
      "name" = "wctOmittedCount",
      "value" = 12,
      "comment" = "twelve of the forty-two book tables are not reprinted (42 - 30).",
    }, {
      "name" = "wctSpanPdfLo",
      "value" = 121,
      "comment" = "the compiled tables occupy pdf pages 121-124 (the 130-page pdf).",
    }, {
      "name" = "wctSpanPdfHi",
      "value" = 124,
      "comment" = "the pdf span ends at 124; pdf 125 onward is blank end-matter.",
    }, {
      "name" = "wctSpanPrintedLo",
      "value" = 120,
      "comment" = "the printed page span: the pdf 121 footer reads 120, pdf 122 reads 121.",
    }, {
      "name" = "wctSpanPrintedHi",
      "value" = 123,
      "comment" = "the pdf 124 footer reads 123 (conf 97); the printed span is 120-123.",
    }, {
      "name" = "wctT3FromPage",
      "value" = 19,
      "comment" = "the compiled section reprints Table 3 (effects of clothing and armor on personal temperature), from page 19.",
    }, {
      "name" = "wctT4FromPage",
      "value" = 21,
      "comment" = "the compiled section reprints Table 4 (temperature effects), from page 21.",
    }, {
      "name" = "wctT5FromPage",
      "value" = 21,
      "comment" = "the compiled section reprints Table 5 (wind velocity effects), from page 21.",
    }, {
      "name" = "wctT9FromPage",
      "value" = 26,
      "comment" = "the compiled section reprints Table 9 (temperature damage to characters), from page 26.",
    }, {
      "name" = "wctT11FromPage",
      "value" = 30,
      "comment" = "the compiled section reprints Table 11 (encumbrance limits for characters), from page 30.",
    }, {
      "name" = "wctT12FromPage",
      "value" = 31,
      "comment" = "the compiled section reprints Table 12 (character movement on foot), from page 31.",
    }, {
      "name" = "wctT13FromPage",
      "value" = 32,
      "comment" = "the compiled section reprints Table 13 (encumbrance limits and movement rates for animals), from page 32.",
    }, {
      "name" = "wctT14FromPage",
      "value" = 33,
      "comment" = "the compiled section reprints Table 14 (movement of vehicles), from page 33.",
    }, {
      "name" = "wctT15FromPage",
      "value" = 33,
      "comment" = "the compiled section reprints Table 15 (climbing movement rates), from page 33.",
    }, {
      "name" = "wctT16FromPage",
      "value" = 35,
      "comment" = "the compiled section reprints Table 16 (modifiers to the non-thief's climbing rating), from page 35.",
    }, {
      "name" = "wctT17FromPage",
      "value" = 35,
      "comment" = "the compiled section reprints Table 17 (damage from free fall or severe slope), from page 35.",
    }, {
      "name" = "wctT18FromPage",
      "value" = 36,
      "comment" = "the compiled section reprints Table 18 (damage from tumbling down a moderate or gentle slope), from page 36.",
    }, {
      "name" = "wctT19FromPage",
      "value" = 36,
      "comment" = "the compiled section reprints Table 19 (chance of stopping a fall or tumble), from page 36.",
    }, {
      "name" = "wctT20FromPage",
      "value" = 38,
      "comment" = "the compiled section reprints Table 20 (grappling success), from page 38.",
    }, {
      "name" = "wctT21FromPage",
      "value" = 38,
      "comment" = "the compiled section reprints Table 21 (thrown loop ranges), from page 38.",
    }, {
      "name" = "wctT22FromPage",
      "value" = 39,
      "comment" = "the compiled section reprints Table 22 (characters' jumping ability), from page 39.",
    }, {
      "name" = "wctT23FromPage",
      "value" = 40,
      "comment" = "the compiled section reprints Table 23 (movement in reduced visibility), from page 40.",
    }, {
      "name" = "wctT24FromPage",
      "value" = 41,
      "comment" = "the compiled section reprints Table 24 (effects of encumbrance on swimming), from page 41.",
    }, {
      "name" = "wctT25FromPage",
      "value" = 44,
      "comment" = "the compiled section reprints Table 25 (waterborne vehicle characteristics), from page 44.",
    }, {
      "name" = "wctT26FromPage",
      "value" = 45,
      "comment" = "the compiled section reprints Table 26 (chance of capsizing), from page 45.",
    }, {
      "name" = "wctT28FromPage",
      "value" = 50,
      "comment" = "the compiled section reprints Table 28 (tolerance levels for lack of food), from page 50.",
    }, {
      "name" = "wctT29FromPage",
      "value" = 53,
      "comment" = "the compiled section reprints Table 29 (water requirements for characters), from page 53.",
    }, {
      "name" = "wctT32FromPage",
      "value" = 57,
      "comment" = "the compiled section reprints Table 32 (fishing success), from page 57.",
    }, {
      "name" = "wctT33FromPage",
      "value" = 58,
      "comment" = "the compiled section reprints Table 33 (chance of food spoilage), from page 58.",
    }, {
      "name" = "wctT36FromPage",
      "value" = 62,
      "comment" = "the compiled section reprints Table 36 (portable shelter characteristics), from page 62.",
    }, {
      "name" = "wctT37FromPage",
      "value" = 64,
      "comment" = "the compiled section reprints Table 37 (effects of lack of sleep), from page 64.",
    }, {
      "name" = "wctT38FromPage",
      "value" = 65,
      "comment" = "the compiled section reprints Table 38 (campfire characteristics), from page 65.",
    }, {
      "name" = "wctT39FromPage",
      "value" = 66,
      "comment" = "the compiled section reprints Table 39 (availability of fuel), from page 66.",
    }, {
      "name" = "wctT41FromPage",
      "value" = 73,
      "comment" = "the compiled section reprints Table 41 (outdoor range of normal vision), from page 73.",
    }, {
      "name" = "wctT42FromPage",
      "value" = 92,
      "comment" = "the compiled section reprints Table 42 (reactions of animals), from page 92.",
    }, {
      "name" = "wctT32FairDayDie",
      "value" = 6,
      "comment" = "the compiled Table 32 Fair daytime: 1d6 (same die as the original).",
    }, {
      "name" = "wctT32FairDayMod",
      "value" = -3,
      "comment" = "the compiled Table 32 Fair daytime modifier: -3 - the ORIGINAL p. 57 pin reads -2 (1d6-2); the reprint lowers it by one.",
    }, {
      "name" = "wctT32GoodDayDie",
      "value" = 6,
      "comment" = "the compiled Table 32 Good daytime die: 1d6 - the ORIGINAL p. 57 pin reads 1d8; the reprint drops the die.",
    }, {
      "name" = "wctT32GoodDayMod",
      "value" = -2,
      "comment" = "the compiled Table 32 Good daytime modifier: -2 (same as the original; the change is the die, 1d8 to 1d6).",
    }, {
      "name" = "wctT9ColdStatLo",
      "value" = 1,
      "comment" = "beneath the compiled Table 9, the cold damage adjustment for a stationary or inactive character runs +1 to +3.",
    }, {
      "name" = "wctT9ColdStatHi",
      "value" = 3,
      "comment" = "the stationary cold adjustment ceiling.",
    }, {
      "name" = "wctT9HotStatLo",
      "value" = -3,
      "comment" = "the hot damage adjustment for a stationary or inactive character runs -1 to -3.",
    }, {
      "name" = "wctT9HotStatHi",
      "value" = -1,
      "comment" = "the stationary hot adjustment top end.",
    }, {
      "name" = "wctT9ColdStrenLo",
      "value" = 1,
      "comment" = "the cold damage adjustment under strenuous activity runs +1 to +2.",
    }, {
      "name" = "wctT9ColdStrenHi",
      "value" = 2,
      "comment" = "the strenuous cold adjustment ceiling.",
    }, {
      "name" = "wctT9HotStrenLo",
      "value" = 1,
      "comment" = "the hot damage adjustment under strenuous activity runs +1 to +4.",
    }, {
      "name" = "wctT9HotStrenHi",
      "value" = 4,
      "comment" = "the strenuous hot adjustment ceiling.",
    }, {
      "name" = "wctT9FatiguedLo",
      "value" = 1,
      "comment" = "the fatigued-and-not-resting adjustment runs +1 to +6 for BOTH cold and hot.",
    }, {
      "name" = "wctT9FatiguedHi",
      "value" = 6,
      "comment" = "the fatigued adjustment ceiling (the same +1 to +6 either way).",
    }, {
      "name" = "wctT9ConAdj46",
      "value" = -1,
      "comment" = "the Constitution check adjustment reprinted beneath the compiled Table 9: character level 4-6.",
    }, {
      "name" = "wctT9ConAdj79",
      "value" = -2,
      "comment" = "character level 7-9.",
    }, {
      "name" = "wctT9ConAdj1012",
      "value" = -3,
      "comment" = "character level 10-12.",
    }, {
      "name" = "wctT9ConAdj1315",
      "value" = -4,
      "comment" = "character level 13-15.",
    }, {
      "name" = "wctT9ConAdj16",
      "value" = -5,
      "comment" = "character level 16+.",
    } },
  "bools" = { {
      "name" = "wctSelectionMostReferred",
      "value" = true,
      "comment" = "the selection is limited to the tables that will probably be referred to most often during a playing session.",
    }, {
      "name" = "wctNotAllTablesReprinted",
      "value" = true,
      "comment" = "because of space limitations, not all of the book tables could be printed in the compiled section.",
    }, {
      "name" = "wctFourPageSpan",
      "value" = true,
      "comment" = "the opener states the tables occupy this and the following three pages - a four-page span, matching pdf 121-124.",
    }, {
      "name" = "wctT3Matches",
      "value" = true,
      "comment" = "the compiled Table 3 matches its landed original pin cell for cell (the R426-era header).",
    }, {
      "name" = "wctT4Matches",
      "value" = true,
      "comment" = "the compiled Table 4 matches its landed original pin cell for cell (the R427-era header).",
    }, {
      "name" = "wctT5Matches",
      "value" = true,
      "comment" = "the compiled Table 5 matches its landed original pin cell for cell (the R427-era header).",
    }, {
      "name" = "wctT9Matches",
      "value" = true,
      "comment" = "the compiled Table 9 matches its landed original pin cell for cell (the R430-era header).",
    }, {
      "name" = "wctT11Matches",
      "value" = true,
      "comment" = "the compiled Table 11 matches its landed original pin cell for cell (the R432-era header).",
    }, {
      "name" = "wctT12Matches",
      "value" = true,
      "comment" = "the compiled Table 12 matches its landed original pin cell for cell (the R432-era header).",
    }, {
      "name" = "wctT13Matches",
      "value" = true,
      "comment" = "the compiled Table 13 matches its landed original pin cell for cell (the R433-era header).",
    }, {
      "name" = "wctT14Matches",
      "value" = true,
      "comment" = "the compiled Table 14 matches its landed original pin cell for cell (the R434-era header).",
    }, {
      "name" = "wctT15Matches",
      "value" = true,
      "comment" = "the compiled Table 15 matches its landed original pin cell for cell (the R435-era header).",
    }, {
      "name" = "wctT16Matches",
      "value" = true,
      "comment" = "the compiled Table 16 matches its landed original pin cell for cell (the R436-era header).",
    }, {
      "name" = "wctT17Matches",
      "value" = true,
      "comment" = "the compiled Table 17 matches its landed original pin cell for cell (the R437-era header).",
    }, {
      "name" = "wctT18Matches",
      "value" = true,
      "comment" = "the compiled Table 18 matches its landed original pin cell for cell (the R438-era header).",
    }, {
      "name" = "wctT19Matches",
      "value" = true,
      "comment" = "the compiled Table 19 matches its landed original pin cell for cell (the R439-era header).",
    }, {
      "name" = "wctT20Matches",
      "value" = true,
      "comment" = "the compiled Table 20 matches its landed original pin cell for cell (the R444-era header).",
    }, {
      "name" = "wctT21Matches",
      "value" = true,
      "comment" = "the compiled Table 21 matches its landed original pin cell for cell (the R445-era header).",
    }, {
      "name" = "wctT22Matches",
      "value" = true,
      "comment" = "the compiled Table 22 matches its landed original pin cell for cell (the R448-era header).",
    }, {
      "name" = "wctT23Matches",
      "value" = true,
      "comment" = "the compiled Table 23 matches its landed original pin cell for cell (the R449-era header).",
    }, {
      "name" = "wctT24Matches",
      "value" = true,
      "comment" = "the compiled Table 24 matches its landed original pin cell for cell (the R450-era header).",
    }, {
      "name" = "wctT25Matches",
      "value" = true,
      "comment" = "the compiled Table 25 matches its landed original pin cell for cell (the R455-era header).",
    }, {
      "name" = "wctT26Matches",
      "value" = true,
      "comment" = "the compiled Table 26 matches its landed original pin cell for cell (the R456-era header).",
    }, {
      "name" = "wctT28Matches",
      "value" = true,
      "comment" = "the compiled Table 28 matches its landed original pin cell for cell (the R462-era header).",
    }, {
      "name" = "wctT29Matches",
      "value" = true,
      "comment" = "the compiled Table 29 matches its landed original pin cell for cell (the R462-era header).",
    }, {
      "name" = "wctT32Matches",
      "value" = false,
      "comment" = "Table 32 is the ONE reprint that differs from its original - see the Table 32 errata section.",
    }, {
      "name" = "wctT33Matches",
      "value" = true,
      "comment" = "the compiled Table 33 matches its landed original pin cell for cell (the R466-era header).",
    }, {
      "name" = "wctT36Matches",
      "value" = true,
      "comment" = "the compiled Table 36 matches its landed original pin cell for cell (the R472-era header).",
    }, {
      "name" = "wctT37Matches",
      "value" = true,
      "comment" = "the compiled Table 37 matches its landed original pin cell for cell (the R473-era header).",
    }, {
      "name" = "wctT38Matches",
      "value" = true,
      "comment" = "the compiled Table 38 matches its landed original pin cell for cell (the R474-era header).",
    }, {
      "name" = "wctT39Matches",
      "value" = true,
      "comment" = "the compiled Table 39 matches its landed original pin cell for cell (the R475-era header).",
    }, {
      "name" = "wctT41Matches",
      "value" = true,
      "comment" = "the compiled Table 41 matches its landed original pin cell for cell (the R483-era header).",
    }, {
      "name" = "wctT42Matches",
      "value" = true,
      "comment" = "the compiled Table 42 matches its landed original pin cell for cell (the R490-era header).",
    }, {
      "name" = "wctOnlyT32Differs",
      "value" = true,
      "comment" = "exactly one of the thirty reprints differs from its original: the compiled Table 32.",
    }, {
      "name" = "wctT4AttackCellsConfirmed",
      "value" = true,
      "comment" = "the Table 4 attack-roll cells at 90-99 (-1) and 100-109 (-2), shredded in the tesseract read, were confirmed by direct eyeball of the printed page and match the landed pin.",
    }, {
      "name" = "wctT32NightUnchanged",
      "value" = true,
      "comment" = "the compiled Table 32 Night column and the Dawn/Dusk column match the original pin (Poor 1d4 / 1d4+2, Fair 1d6-1 / 1d6+2, Good 1d6+2 / 1d8+2).",
    }, {
      "name" = "wctT32ErrataIsCompiledSide",
      "value" = true,
      "comment" = "the landed rules/wsg/wsgfish.h pin keeps the ORIGINAL p. 57 readings; the compiled-side readings live here as the errata record.",
    }, {
      "name" = "wctT9CompanionsMatch",
      "value" = true,
      "comment" = "the damage-adjustment and Con-check-adjustment companions reprinted beneath the compiled Table 9 match the landed rules/wsg/wsgheat.h pins exactly.",
    }, {
      "name" = "wctT25MergedHalves",
      "value" = true,
      "comment" = "the compiled Table 25 prints the vessel characteristics and the hull-value / draught columns as one table - the landed pin splits them into the 25a characteristics and 25b movement-rate halves (rules/wsg/wsgvessels.h).",
    }, {
      "name" = "wctT36QualityBandsLabeled",
      "value" = true,
      "comment" = "the compiled Table 36 groups its twelve rows under the four printed quality bands: poor, adequate, good, superior (small, medium, large each).",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the compiled section reprints thirty of the forty-two book tables",
      "expr" = "m['wctCompiledCount']() != 30 or m['wctBookTableCount']() != 42 or m['wctOmittedCount']() != 12",
    }, {
      "note" = "the four-page span: pdf 121-124, printed 120-123",
      "expr" = "m['wctSpanPdfLo']() != 121 or m['wctSpanPdfHi']() != 124 or m['wctSpanPrintedLo']() != 120 or m['wctSpanPrintedHi']() != 123",
    }, {
      "note" = "the first reprint in the section is Table 3, from page 19",
      "expr" = "m['wctT3FromPage']() != 19",
    }, {
      "note" = "the last reprint in the section is Table 42, from page 92",
      "expr" = "m['wctT42FromPage']() != 92",
    }, {
      "note" = "the compiled Table 32 Fair daytime is 1d6-3 - the original pin reads 1d6-2",
      "expr" = "m['wctT32FairDayDie']() != 6 or m['wctT32FairDayMod']() != -3",
    }, {
      "note" = "the compiled Table 32 Good daytime is 1d6-2 - the original pin reads 1d8-2 (the die drops, the modifier holds)",
      "expr" = "m['wctT32GoodDayDie']() != 6 or m['wctT32GoodDayMod']() != -2",
    }, {
      "note" = "exactly one reprint differs from its original",
      "expr" = "m['wctT32Matches']() != 0 or m['wctOnlyT32Differs']() != 1",
    }, {
      "note" = "the Table 4 attack cells confirmed by eyeball: -1 at 90-99, -2 at 100-109",
      "expr" = "m['wctT4AttackCellsConfirmed']() != 1 or m['wctT4Matches']() != 1",
    }, {
      "note" = "the fatigued adjustment is symmetric: +1 to +6 for both cold and hot",
      "expr" = "m['wctT9FatiguedLo']() != 1 or m['wctT9FatiguedHi']() != 6",
    }, {
      "note" = "the Con-check adjustment ladder descends -1 through -5 across levels 4-6 to 16+",
      "expr" = "m['wctT9ConAdj46']() != -1 or m['wctT9ConAdj79']() != -2 or m['wctT9ConAdj1012']() != -3 or m['wctT9ConAdj1315']() != -4 or m['wctT9ConAdj16']() != -5",
    }, {
      "note" = "the stationary hot adjustment is the mirror of the stationary cold one",
      "expr" = "m['wctT9HotStatLo']() != -3 or m['wctT9HotStatHi']() != -1 or m['wctT9ColdStatLo']() != 1 or m['wctT9ColdStatHi']() != 3",
    }, {
      "note" = "the compiled Table 3 matches its original",
      "expr" = "m['wctT3Matches']() != 1",
    }, {
      "note" = "the compiled Table 4 matches its original",
      "expr" = "m['wctT4Matches']() != 1",
    }, {
      "note" = "the compiled Table 5 matches its original",
      "expr" = "m['wctT5Matches']() != 1",
    }, {
      "note" = "the compiled Table 9 matches its original",
      "expr" = "m['wctT9Matches']() != 1",
    }, {
      "note" = "the compiled Table 11 matches its original",
      "expr" = "m['wctT11Matches']() != 1",
    }, {
      "note" = "the compiled Table 12 matches its original",
      "expr" = "m['wctT12Matches']() != 1",
    }, {
      "note" = "the compiled Table 13 matches its original",
      "expr" = "m['wctT13Matches']() != 1",
    }, {
      "note" = "the compiled Table 14 matches its original",
      "expr" = "m['wctT14Matches']() != 1",
    }, {
      "note" = "the compiled Table 15 matches its original",
      "expr" = "m['wctT15Matches']() != 1",
    }, {
      "note" = "the compiled Table 16 matches its original",
      "expr" = "m['wctT16Matches']() != 1",
    }, {
      "note" = "the compiled Table 17 matches its original",
      "expr" = "m['wctT17Matches']() != 1",
    }, {
      "note" = "the compiled Table 18 matches its original",
      "expr" = "m['wctT18Matches']() != 1",
    }, {
      "note" = "the compiled Table 19 matches its original",
      "expr" = "m['wctT19Matches']() != 1",
    }, {
      "note" = "the compiled Table 20 matches its original",
      "expr" = "m['wctT20Matches']() != 1",
    }, {
      "note" = "the compiled Table 21 matches its original",
      "expr" = "m['wctT21Matches']() != 1",
    }, {
      "note" = "the compiled Table 22 matches its original",
      "expr" = "m['wctT22Matches']() != 1",
    }, {
      "note" = "the compiled Table 23 matches its original",
      "expr" = "m['wctT23Matches']() != 1",
    }, {
      "note" = "the compiled Table 24 matches its original",
      "expr" = "m['wctT24Matches']() != 1",
    }, {
      "note" = "the compiled Table 25 matches its original",
      "expr" = "m['wctT25Matches']() != 1",
    }, {
      "note" = "the compiled Table 26 matches its original",
      "expr" = "m['wctT26Matches']() != 1",
    }, {
      "note" = "the compiled Table 28 matches its original",
      "expr" = "m['wctT28Matches']() != 1",
    }, {
      "note" = "the compiled Table 29 matches its original",
      "expr" = "m['wctT29Matches']() != 1",
    }, {
      "note" = "the compiled Table 32 differs from its original",
      "expr" = "m['wctT32Matches']() != 0",
    }, {
      "note" = "the compiled Table 33 matches its original",
      "expr" = "m['wctT33Matches']() != 1",
    }, {
      "note" = "the compiled Table 36 matches its original",
      "expr" = "m['wctT36Matches']() != 1",
    }, {
      "note" = "the compiled Table 37 matches its original",
      "expr" = "m['wctT37Matches']() != 1",
    }, {
      "note" = "the compiled Table 38 matches its original",
      "expr" = "m['wctT38Matches']() != 1",
    }, {
      "note" = "the compiled Table 39 matches its original",
      "expr" = "m['wctT39Matches']() != 1",
    }, {
      "note" = "the compiled Table 41 matches its original",
      "expr" = "m['wctT41Matches']() != 1",
    }, {
      "note" = "the compiled Table 42 matches its original",
      "expr" = "m['wctT42Matches']() != 1",
    } },
  "audit" = {
      "label" = "R495 WSG compiled tables audit",
      "comment" = "The compiled tables, printed pp. 120-123 (pdf 121-124): thirty of the forty-two book tables reprinted as the play-session reference, each with its from-page. Twenty-nine of the thirty reprints match their landed originals cell for cell (the Table 3 attire grid, Tables 4 and 5, Table 9 with its damage-adjustment and Con-check companions, Tables 11-19, 20-26, 28-29, 33, 36-39, 41 and the fourteen-row Table 42). The ONE exception is the compiled Table 32 (fishing success): the reprint reads Fair daytime 1d6-3 against the original 1d6-2, and Good daytime 1d6-2 against the original 1d8-2 - pinned here as the errata record with the landed rules/wsg/wsgfish.h keeping the original readings. The Table 4 attack cells at 90-99 (-1) and 100-109 (-2), shredded by the tesseract pass, were confirmed by direct eyeball and match the pin. This closes the compiled-tables box: the WSG arc is complete.",
    },
}
