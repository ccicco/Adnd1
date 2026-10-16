// =========================================================================================
// Adnd1 - rules/wsgtables.h
// The WSG COMPILED TABLES, R495: the play-session reprint section, printed
// pp. 120-123 (pdf pages 121-124) - thirty of the forty-two book tables
// reproduced with their from-pages, the selection limited to the tables most
// often referred to during play. This round closes the compiled-tables gap
// box and COMPLETES THE WSG ARC: every section of the Wilderness Survival
// Guide is now pinned.
// census 419 -> 420.
//
// WSG printed pp. 120-123, pdf pages 121-124, extracted at r493-extraction
// sha 5af0ac2 (tesseract full-text and tsv, x121-x124, 300 dpi; pdf 125
// confirmed blank end-matter). Reconciled against the landed originals: every
// reprinted table was compared cell-for-cell with its R425-R494 pin
// (rules/wsgdress.h, wsgenvfx.h, wsgheat.h, wsgencum.h, wsganimal.h,
// wsgvehicle.h, wsgclimb.h, wsgcheck.h, wsgfall.h, wsgtumble.h, wsgstop.h,
// wsggrap.h, wsgjump.h, wsgnvis.h, wsgswim.h, wsgvessels.h, wsgcapsizing.h,
// wsgfood.h, wsgfish.h, wsgcarry.h, wsgtents.h, wsgsleep.h, wsgfire.h,
// wsgfuel.h, wsginfra.h, wsgmount.h). No new grids are pinned: the data lives
// in the original headers; this round pins the compilation itself - the
// manifest, the from-pages, the per-table reconciliation, and the one errata.
//
// THE SETTLE: twenty-nine of the thirty reprints reconcile with their landed
// pins cell for cell, including every cell the tesseract pass shredded (the
// Table 19 stop grid, the Table 20 rows 4-5, the whole Table 23 and Table 24
// reads, the Table 25 lower half, the Table 39 hills row, the Table 41 rows
// 3-4, and the six Table 42 rows whose labels garbled - all settle from the
// pins with nothing contradicted, and the TSV row-gap geometry confirms the
// fourteen Table 42 rows and the thirty-manifest in full). The ONE genuine
// print discrepancy is the compiled Table 32: Fair daytime 1d6-3 (original
// 1d6-2, both tokens legible and column-aligned at x=1600/1668 on pdf 124)
// and Good daytime 1d6-2 (original 1d8-2) - an errata-class reprint
// difference, the first found in the arc, pinned as compiled-side consts with
// the original pin untouched. The Table 4 attack cells (90-99 = -1, 100-109 =
// -2) were OCR-shredded (=3 / =0 at conf 31/70) and settled by the user
// direct eyeball of printed p. 120, matching the pin. The printed page span
// is 120-123: the footers read 120 (pdf 121), 121 (pdf 122, conf 97) and 123
// (pdf 124, conf 97); the pdf 123 footer (printed 122 by the pdf-minus-one
// rule) OCRs ambiguously as 123 at low confidence - the pdf 124 footer at
// conf 97 settles the span end.
//
namespace rules {

// ---- The compilation opener ----

// the compiled-tables section reprints thirty of the book tables.
inline int wctCompiledCount()
    { return 30; }

// the book own Tables index runs from Table 1 through Table 42.
inline int wctBookTableCount()
    { return 42; }

// twelve of the forty-two book tables are not reprinted (42 - 30).
inline int wctOmittedCount()
    { return 12; }

// the compiled tables occupy pdf pages 121-124 (the 130-page pdf).
inline int wctSpanPdfLo()
    { return 121; }

// the pdf span ends at 124; pdf 125 onward is blank end-matter.
inline int wctSpanPdfHi()
    { return 124; }

// the printed page span: the pdf 121 footer reads 120, pdf 122 reads 121.
inline int wctSpanPrintedLo()
    { return 120; }

// the pdf 124 footer reads 123 (conf 97); the printed span is 120-123.
inline int wctSpanPrintedHi()
    { return 123; }

// the selection is limited to the tables that will probably be referred to
// most often during a playing session.
inline bool wctSelectionMostReferred()
    { return true; }

// because of space limitations, not all of the book tables could be printed
// in the compiled section.
inline bool wctNotAllTablesReprinted()
    { return true; }

// the opener states the tables occupy this and the following three pages - a
// four-page span, matching pdf 121-124.
inline bool wctFourPageSpan()
    { return true; }

// ---- The manifest: thirty tables with their from-pages ----

// the compiled section reprints Table 3 (effects of clothing and armor on
// personal temperature), from page 19.
inline int wctT3FromPage()
    { return 19; }

// the compiled section reprints Table 4 (temperature effects), from page 21.
inline int wctT4FromPage()
    { return 21; }

// the compiled section reprints Table 5 (wind velocity effects), from page
// 21.
inline int wctT5FromPage()
    { return 21; }

// the compiled section reprints Table 9 (temperature damage to characters),
// from page 26.
inline int wctT9FromPage()
    { return 26; }

// the compiled section reprints Table 11 (encumbrance limits for characters),
// from page 30.
inline int wctT11FromPage()
    { return 30; }

// the compiled section reprints Table 12 (character movement on foot), from
// page 31.
inline int wctT12FromPage()
    { return 31; }

// the compiled section reprints Table 13 (encumbrance limits and movement
// rates for animals), from page 32.
inline int wctT13FromPage()
    { return 32; }

// the compiled section reprints Table 14 (movement of vehicles), from page
// 33.
inline int wctT14FromPage()
    { return 33; }

// the compiled section reprints Table 15 (climbing movement rates), from page
// 33.
inline int wctT15FromPage()
    { return 33; }

// the compiled section reprints Table 16 (modifiers to the non-thief's
// climbing rating), from page 35.
inline int wctT16FromPage()
    { return 35; }

// the compiled section reprints Table 17 (damage from free fall or severe
// slope), from page 35.
inline int wctT17FromPage()
    { return 35; }

// the compiled section reprints Table 18 (damage from tumbling down a
// moderate or gentle slope), from page 36.
inline int wctT18FromPage()
    { return 36; }

// the compiled section reprints Table 19 (chance of stopping a fall or
// tumble), from page 36.
inline int wctT19FromPage()
    { return 36; }

// the compiled section reprints Table 20 (grappling success), from page 38.
inline int wctT20FromPage()
    { return 38; }

// the compiled section reprints Table 21 (thrown loop ranges), from page 38.
inline int wctT21FromPage()
    { return 38; }

// the compiled section reprints Table 22 (characters' jumping ability), from
// page 39.
inline int wctT22FromPage()
    { return 39; }

// the compiled section reprints Table 23 (movement in reduced visibility),
// from page 40.
inline int wctT23FromPage()
    { return 40; }

// the compiled section reprints Table 24 (effects of encumbrance on
// swimming), from page 41.
inline int wctT24FromPage()
    { return 41; }

// the compiled section reprints Table 25 (waterborne vehicle
// characteristics), from page 44.
inline int wctT25FromPage()
    { return 44; }

// the compiled section reprints Table 26 (chance of capsizing), from page 45.
inline int wctT26FromPage()
    { return 45; }

// the compiled section reprints Table 28 (tolerance levels for lack of food),
// from page 50.
inline int wctT28FromPage()
    { return 50; }

// the compiled section reprints Table 29 (water requirements for characters),
// from page 53.
inline int wctT29FromPage()
    { return 53; }

// the compiled section reprints Table 32 (fishing success), from page 57.
inline int wctT32FromPage()
    { return 57; }

// the compiled section reprints Table 33 (chance of food spoilage), from page
// 58.
inline int wctT33FromPage()
    { return 58; }

// the compiled section reprints Table 36 (portable shelter characteristics),
// from page 62.
inline int wctT36FromPage()
    { return 62; }

// the compiled section reprints Table 37 (effects of lack of sleep), from
// page 64.
inline int wctT37FromPage()
    { return 64; }

// the compiled section reprints Table 38 (campfire characteristics), from
// page 65.
inline int wctT38FromPage()
    { return 65; }

// the compiled section reprints Table 39 (availability of fuel), from page
// 66.
inline int wctT39FromPage()
    { return 66; }

// the compiled section reprints Table 41 (outdoor range of normal vision),
// from page 73.
inline int wctT41FromPage()
    { return 73; }

// the compiled section reprints Table 42 (reactions of animals), from page
// 92.
inline int wctT42FromPage()
    { return 92; }

// ---- The reconciliation: the reprints against their originals ----

// the compiled Table 3 matches its landed original pin cell for cell (the
// R426-era header).
inline bool wctT3Matches()
    { return true; }

// the compiled Table 4 matches its landed original pin cell for cell (the
// R427-era header).
inline bool wctT4Matches()
    { return true; }

// the compiled Table 5 matches its landed original pin cell for cell (the
// R427-era header).
inline bool wctT5Matches()
    { return true; }

// the compiled Table 9 matches its landed original pin cell for cell (the
// R430-era header).
inline bool wctT9Matches()
    { return true; }

// the compiled Table 11 matches its landed original pin cell for cell (the
// R432-era header).
inline bool wctT11Matches()
    { return true; }

// the compiled Table 12 matches its landed original pin cell for cell (the
// R432-era header).
inline bool wctT12Matches()
    { return true; }

// the compiled Table 13 matches its landed original pin cell for cell (the
// R433-era header).
inline bool wctT13Matches()
    { return true; }

// the compiled Table 14 matches its landed original pin cell for cell (the
// R434-era header).
inline bool wctT14Matches()
    { return true; }

// the compiled Table 15 matches its landed original pin cell for cell (the
// R435-era header).
inline bool wctT15Matches()
    { return true; }

// the compiled Table 16 matches its landed original pin cell for cell (the
// R436-era header).
inline bool wctT16Matches()
    { return true; }

// the compiled Table 17 matches its landed original pin cell for cell (the
// R437-era header).
inline bool wctT17Matches()
    { return true; }

// the compiled Table 18 matches its landed original pin cell for cell (the
// R438-era header).
inline bool wctT18Matches()
    { return true; }

// the compiled Table 19 matches its landed original pin cell for cell (the
// R439-era header).
inline bool wctT19Matches()
    { return true; }

// the compiled Table 20 matches its landed original pin cell for cell (the
// R444-era header).
inline bool wctT20Matches()
    { return true; }

// the compiled Table 21 matches its landed original pin cell for cell (the
// R445-era header).
inline bool wctT21Matches()
    { return true; }

// the compiled Table 22 matches its landed original pin cell for cell (the
// R448-era header).
inline bool wctT22Matches()
    { return true; }

// the compiled Table 23 matches its landed original pin cell for cell (the
// R449-era header).
inline bool wctT23Matches()
    { return true; }

// the compiled Table 24 matches its landed original pin cell for cell (the
// R450-era header).
inline bool wctT24Matches()
    { return true; }

// the compiled Table 25 matches its landed original pin cell for cell (the
// R455-era header).
inline bool wctT25Matches()
    { return true; }

// the compiled Table 26 matches its landed original pin cell for cell (the
// R456-era header).
inline bool wctT26Matches()
    { return true; }

// the compiled Table 28 matches its landed original pin cell for cell (the
// R462-era header).
inline bool wctT28Matches()
    { return true; }

// the compiled Table 29 matches its landed original pin cell for cell (the
// R462-era header).
inline bool wctT29Matches()
    { return true; }

// Table 32 is the ONE reprint that differs from its original - see the Table
// 32 errata section.
inline bool wctT32Matches()
    { return false; }

// the compiled Table 33 matches its landed original pin cell for cell (the
// R466-era header).
inline bool wctT33Matches()
    { return true; }

// the compiled Table 36 matches its landed original pin cell for cell (the
// R472-era header).
inline bool wctT36Matches()
    { return true; }

// the compiled Table 37 matches its landed original pin cell for cell (the
// R473-era header).
inline bool wctT37Matches()
    { return true; }

// the compiled Table 38 matches its landed original pin cell for cell (the
// R474-era header).
inline bool wctT38Matches()
    { return true; }

// the compiled Table 39 matches its landed original pin cell for cell (the
// R475-era header).
inline bool wctT39Matches()
    { return true; }

// the compiled Table 41 matches its landed original pin cell for cell (the
// R483-era header).
inline bool wctT41Matches()
    { return true; }

// the compiled Table 42 matches its landed original pin cell for cell (the
// R490-era header).
inline bool wctT42Matches()
    { return true; }

// exactly one of the thirty reprints differs from its original: the compiled
// Table 32.
inline bool wctOnlyT32Differs()
    { return true; }

// the Table 4 attack-roll cells at 90-99 (-1) and 100-109 (-2), shredded in
// the tesseract read, were confirmed by direct eyeball of the printed page
// and match the landed pin.
inline bool wctT4AttackCellsConfirmed()
    { return true; }

// ---- The Table 32 errata: the one differing reprint ----

// the compiled Table 32 Fair daytime: 1d6 (same die as the original).
inline int wctT32FairDayDie()
    { return 6; }

// the compiled Table 32 Fair daytime modifier: -3 - the ORIGINAL p. 57 pin
// reads -2 (1d6-2); the reprint lowers it by one.
inline int wctT32FairDayMod()
    { return -3; }

// the compiled Table 32 Good daytime die: 1d6 - the ORIGINAL p. 57 pin reads
// 1d8; the reprint drops the die.
inline int wctT32GoodDayDie()
    { return 6; }

// the compiled Table 32 Good daytime modifier: -2 (same as the original; the
// change is the die, 1d8 to 1d6).
inline int wctT32GoodDayMod()
    { return -2; }

// the compiled Table 32 Night column and the Dawn/Dusk column match the
// original pin (Poor 1d4 / 1d4+2, Fair 1d6-1 / 1d6+2, Good 1d6+2 / 1d8+2).
inline bool wctT32NightUnchanged()
    { return true; }

// the landed rules/wsgfish.h pin keeps the ORIGINAL p. 57 readings; the
// compiled-side readings live here as the errata record.
inline bool wctT32ErrataIsCompiledSide()
    { return true; }

// ---- The Table 9 companions: the damage and Con-check adjustments ----

// beneath the compiled Table 9, the cold damage adjustment for a stationary
// or inactive character runs +1 to +3.
inline int wctT9ColdStatLo()
    { return 1; }

// the stationary cold adjustment ceiling.
inline int wctT9ColdStatHi()
    { return 3; }

// the hot damage adjustment for a stationary or inactive character runs -1 to
// -3.
inline int wctT9HotStatLo()
    { return -3; }

// the stationary hot adjustment top end.
inline int wctT9HotStatHi()
    { return -1; }

// the cold damage adjustment under strenuous activity runs +1 to +2.
inline int wctT9ColdStrenLo()
    { return 1; }

// the strenuous cold adjustment ceiling.
inline int wctT9ColdStrenHi()
    { return 2; }

// the hot damage adjustment under strenuous activity runs +1 to +4.
inline int wctT9HotStrenLo()
    { return 1; }

// the strenuous hot adjustment ceiling.
inline int wctT9HotStrenHi()
    { return 4; }

// the fatigued-and-not-resting adjustment runs +1 to +6 for BOTH cold and
// hot.
inline int wctT9FatiguedLo()
    { return 1; }

// the fatigued adjustment ceiling (the same +1 to +6 either way).
inline int wctT9FatiguedHi()
    { return 6; }

// the Constitution check adjustment reprinted beneath the compiled Table 9:
// character level 4-6.
inline int wctT9ConAdj46()
    { return -1; }

// character level 7-9.
inline int wctT9ConAdj79()
    { return -2; }

// character level 10-12.
inline int wctT9ConAdj1012()
    { return -3; }

// character level 13-15.
inline int wctT9ConAdj1315()
    { return -4; }

// character level 16+.
inline int wctT9ConAdj16()
    { return -5; }

// the damage-adjustment and Con-check-adjustment companions reprinted beneath
// the compiled Table 9 match the landed rules/wsgheat.h pins exactly.
inline bool wctT9CompanionsMatch()
    { return true; }

// ---- The reprint shape notes ----

// the compiled Table 25 prints the vessel characteristics and the hull-value
// / draught columns as one table - the landed pin splits them into the 25a
// characteristics and 25b movement-rate halves (rules/wsgvessels.h).
inline bool wctT25MergedHalves()
    { return true; }

// the compiled Table 36 groups its twelve rows under the four printed quality
// bands: poor, adequate, good, superior (small, medium, large each).
inline bool wctT36QualityBandsLabeled()
    { return true; }

}   // namespace rules
