// =========================================================================================
// Adnd1 - rules/l22.h
// The Dragon issue-22 box closing round - the four-round walk complete,
// issues 2 through 22 all closed
// census 871 -> 872.
//
// The pure flip of the issue-22 four-round shape - no new ink pinned, all
// three report-022 boxes closed. The issue-22 openers stand at R946 (t22: the
// military-history triptych - the First Assassins, the Irresistible Force,
// the Armies of the Renaissance), R947 (s22: the AD&D DMG sneak preview table
// round) and R948 (k22: the commentary set - What It Is and Where It Is
// Going, the pole arms taxonomy, the Berg rebuttal, Stalemate at Kassala, the
// Mapping the Dungeons catalog). The combined TD22-plus-LW13 experiment issue
// of February 1979, print folio equal to PDF page, is the first issue to ride
// the four-round shape. The Sullin levels 7-9 and the brawling sequel watches
// ride to TD 23.
//
namespace rules {

// ---- the issue-22 closure bookkeeping ----

// all three report-022 boxes close at this single flip - the part-one,
// part-two and part-three opener boxes the issue-22 closure bookkeeping
inline int l22IssueTwentyTwoBoxes()
    { return 3; }

// the nine chains of the TD-22 call - the triptych three, the sneak preview
// one, the commentary set five the issue-22 closure bookkeeping
inline int l22IssueTwentyTwoChains()
    { return 9; }

// the first four-round issue shape of the walk - three openers plus the
// closing flip the issue-22 closure bookkeeping
inline int l22IssueTwentyTwoRounds()
    { return 4; }

// the part-one round stood at ninety-three, the military-history triptych the
// issue-22 closure bookkeeping
inline int l22PartOneInline()
    { return 93; }

// the part-two round stood at three hundred twenty, the sneak preview table
// round the issue-22 closure bookkeeping
inline int l22PartTwoInline()
    { return 320; }

// the part-three round stood at one hundred fifty-one, the commentary set the
// issue-22 closure bookkeeping
inline int l22PartThreeInline()
    { return 151; }

// the three opener rounds together pinned five hundred sixty-four, the three
// openers together the issue-22 closure bookkeeping
inline int l22OpenerInlineTotal()
    { return 564; }

// the Dragon walk opened at issue two the issue-22 closure bookkeeping
inline int l22WalkFirstIssue()
    { return 2; }

// the walk now closes at issue twenty-two the issue-22 closure bookkeeping
inline int l22WalkLastClosed()
    { return 22; }

// issues two through twenty-two - twenty-one issues of the walk all closed
// the issue-22 closure bookkeeping
inline int l22WalkIssuesClosed()
    { return 21; }

// the battery census stood at eight hundred seventy-one before the flip the
// issue-22 closure bookkeeping
inline int l22CensusBefore()
    { return 871; }

// the flip raises the battery census to eight hundred seventy-two the
// issue-22 closure bookkeeping
inline int l22CensusAfter()
    { return 872; }

// the registry ground truth unchanged - one thousand three hundred thirteen
// loaded the issue-22 closure bookkeeping
inline int l22RegistryLoaded()
    { return 1313; }

// one thousand three hundred thirty-eight base lua the issue-22 closure
// bookkeeping
inline int l22RegistryBaseLua()
    { return 1338; }

// twenty-five never-load (R924 re-measure) the issue-22 closure bookkeeping
inline int l22RegistryNeverLoad()
    { return 25; }

// the combined experiment numbering - TD 22 the issue-22 closure bookkeeping
inline int l22TDNumber()
    { return 22; }

// the combined experiment numbering picks up where it left off - LW 13 the
// issue-22 closure bookkeeping
inline int l22LWNumber()
    { return 13; }

// Vol. III No. 8, February 1979 the issue-22 closure bookkeeping
inline int l22IssueYear()
    { return 1979; }

// the Dragon walk holds issues two through twenty-two complete the issue-22
// closure bookkeeping
inline bool l22WalkTwoThroughTwentyTwo()
    { return true; }

// the military-history triptych stands pinned - the First Assassins, the
// Irresistible Force, the Armies of the Renaissance the issue-22 closure
// bookkeeping
inline bool l22PartOneComplete()
    { return true; }

// the AD&D DMG sneak preview stands pinned - the twelve tables from the
// amulet through the save matrices the issue-22 closure bookkeeping
inline bool l22PartTwoComplete()
    { return true; }

// the commentary set stands pinned - the design philosophy essay, the pole
// arms taxonomy, the Berg rebuttal, the Kassala battle report, the games
// catalog roster the issue-22 closure bookkeeping
inline bool l22PartThreeComplete()
    { return true; }

// the first four-round issue shape of the walk - the precedent for future
// table-heavy issues the issue-22 closure bookkeeping
inline bool l22FirstFourRoundShape()
    { return true; }

// the combined TD-22-plus-LW-13 experiment issue - no January 1979 issue
// exists the issue-22 closure bookkeeping
inline bool l22NoJanuaryIssue()
    { return true; }

// print folio equals PDF page this issue, verified at the page feet the
// issue-22 closure bookkeeping
inline bool l22PrintFolioEqualsPdfPage()
    { return true; }

// the print catches of all four rounds pinned as scanned, the conversion
// noted never silent the issue-22 closure bookkeeping
inline bool l22PrintCatchesPinned()
    { return true; }

// the Sullin levels seven through nine still print nowhere - the watch rides
// to TD 23 the issue-22 closure bookkeeping
inline bool l22SullinWatchRides()
    { return true; }

// the brawling long-term-effects sequel still prints nowhere - the watch
// rides to TD 23 the issue-22 closure bookkeeping
inline bool l22BrawlingWatchRides()
    { return true; }

// report 022 closes with all three boxes checked, joining mm2 and ddg in the
// closed state the issue-22 closure bookkeeping
inline bool l22GapReportClosed()
    { return true; }

}   // namespace rules
