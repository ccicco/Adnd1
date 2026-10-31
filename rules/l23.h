// =========================================================================================
// Adnd1 - rules/l23.h
// The Dragon issue-23 box closing round - the second four-round walk
// complete, issues 2 through 23 all closed
// census 875 -> 876.
//
// The pure flip, no new ink - all three report-023 boxes check at this single
// round: the part-one variant triptych (R950, t23), the part-two Lower Planes
// generator (R951, s23) and the part-three commentary set (R952, k23). The
// walk holds issues 2-23 all closed, the second four-round shape proven after
// issue 22; the Sullin and brawling watches ride to TD 24. Pinned from The
// Dragon Vol. III No. 9 (March 1979) number 23, the single-voice transcript
// of the Curtiss-provided scan at extract/dragon/023.
//
namespace rules {

// ---- the issue-23 closure bookkeeping ----

// all three report-023 boxes close at this single flip - the part-one,
// part-two and part-three lines the issue-23 closure bookkeeping
inline int l23IssueTwentyThreeBoxes()
    { return 3; }

// the ten chains of the TD-23 call - the triptych three, the lower-planes
// generator one, the commentary set six the issue-23 closure bookkeeping
inline int l23IssueTwentyThreeChains()
    { return 10; }

// the second four-round issue shape of the walk - three openers plus the
// closing flip the issue-23 closure bookkeeping
inline int l23IssueTwentyThreeRounds()
    { return 4; }

// the part-one round stood at eighty-two, the variant triptych the issue-23
// closure bookkeeping
inline int l23PartOneInline()
    { return 82; }

// the part-two round stood at one hundred seventy-eight, the Lower Planes
// table round the issue-23 closure bookkeeping
inline int l23PartTwoInline()
    { return 178; }

// the part-three round stood at one hundred forty-five, the six-chain
// commentary set the issue-23 closure bookkeeping
inline int l23PartThreeInline()
    { return 145; }

// the three opener rounds together pinned four hundred five the issue-23
// closure bookkeeping
inline int l23OpenerInlineTotal()
    { return 405; }

// the Dragon walk opened at issue two the issue-23 closure bookkeeping
inline int l23WalkFirstIssue()
    { return 2; }

// the walk now closes at issue twenty-three the issue-23 closure bookkeeping
inline int l23WalkLastClosed()
    { return 23; }

// issues two through twenty-three - twenty-two issues of the walk all closed
// the issue-23 closure bookkeeping
inline int l23WalkIssuesClosed()
    { return 22; }

// the battery census stood at eight hundred seventy-four before the flip the
// issue-23 closure bookkeeping
inline int l23CensusBefore()
    { return 874; }

// the flip raises the battery census to eight hundred seventy-five the
// issue-23 closure bookkeeping
inline int l23CensusAfter()
    { return 875; }

// the registry ground truth unchanged - one thousand three hundred thirteen
// loaded the issue-23 closure bookkeeping
inline int l23RegistryLoaded()
    { return 1313; }

// one thousand three hundred thirty-eight base lua the issue-23 closure
// bookkeeping
inline int l23RegistryBaseLua()
    { return 1338; }

// twenty-five never-load (R924 re-measure) the issue-23 closure bookkeeping
inline int l23RegistryNeverLoad()
    { return 25; }

// the combined experiment numbering - TD 23 the issue-23 closure bookkeeping
inline int l23TDNumber()
    { return 23; }

// Vol. III No. 9, March 1979 the issue-23 closure bookkeeping
inline int l23IssueYear()
    { return 1979; }

// the Dragon walk holds issues two through twenty-three complete the issue-23
// closure bookkeeping
inline bool l23WalkTwoThroughTwentyThree()
    { return true; }

// the variant triptych stands pinned - the En Garde solitaire duel, the Mind
// Wrestling track, the Starship Warden water monsters the issue-23 closure
// bookkeeping
inline bool l23PartOneComplete()
    { return true; }

// the Lower Planes creature generator stands pinned - the stat frame, the
// twenty-three grids, the strength bands the issue-23 closure bookkeeping
inline bool l23PartTwoComplete()
    { return true; }

// the commentary set stands pinned - the trade-show report, the armor
// weights, the permanent-damage charts, the prison formula, the Origins
// critique, the Niall tale the issue-23 closure bookkeeping
inline bool l23PartThreeComplete()
    { return true; }

// the second four-round issue shape of the walk - the shape proven at issue
// 22 now proven again the issue-23 closure bookkeeping
inline bool l23SecondFourRoundShape()
    { return true; }

// the numbering agrees everywhere - Vol. III No. 9, March 1979, number 23 the
// issue-23 closure bookkeeping
inline bool l23NumberingAgrees()
    { return true; }

// print folio equals PDF page this issue, verified at the page feet - folios
// four through thirty the issue-23 closure bookkeeping
inline bool l23PrintFolioEqualsPdfPage()
    { return true; }

// the single-voice transcript - no archive.org djvu cross-check exists for
// issue 23 the issue-23 closure bookkeeping
inline bool l23SingleVoiceTranscript()
    { return true; }

// the print catches of all four rounds pinned as scanned, the conversion
// noted never silent the issue-23 closure bookkeeping
inline bool l23PrintCatchesPinned()
    { return true; }

// the Sullin levels seven through nine still print nowhere - the watch rides
// to TD 24 the issue-23 closure bookkeeping
inline bool l23SullinWatchRides()
    { return true; }

// the brawling long-term-effects sequel still prints nowhere - the watch
// rides to TD 24 the issue-23 closure bookkeeping
inline bool l23BrawlingWatchRides()
    { return true; }

// report 023 closes with all three boxes checked, joining mm2 and ddg in the
// closed state the issue-23 closure bookkeeping
inline bool l23GapReportClosed()
    { return true; }

}   // namespace rules
