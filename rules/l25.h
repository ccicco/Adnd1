// =========================================================================================
// Adnd1 - rules/l25.h
// The Dragon issue-25 box closing round - the fourth four-round walk
// complete, issues 2 through 25 all closed
// census 883 -> 884.
//
// The pure flip, no new ink - all three report-025 boxes check at this single
// round: the part-one opener set (R958, t25), the part-two war game and
// vampire roster table round (R959, s25) and the part-three commentary set
// (R960, k25). The walk holds issues 2-25 all closed, the four-round shape
// four times proven at issues 22, 23, 24 and 25; the TD 26 intake stands
// adjudicated at thirteen chains with the Sullin and brawling watches -
// absent a fifth issue - riding on to TD 27. Pinned from The Dragon Vol. III
// No. 11 (May 1979) number 25, the single-voice transcript of the
// Curtiss-provided scan at extract/dragon/025.
//
namespace rules {

// ---- the issue-25 closure bookkeeping ----

// all three report-025 boxes close at this single flip - the part-one,
// part-two and part-three lines the issue-25 closure bookkeeping
inline int l25IssueTwentyFiveBoxes()
    { return 3; }

// the eight chains of the TD-25 call - the opener set three, the table round
// two, the commentary set three the issue-25 closure bookkeeping
inline int l25IssueTwentyFiveChains()
    { return 8; }

// the fourth four-round issue shape of the walk - three openers plus the
// closing flip the issue-25 closure bookkeeping
inline int l25IssueTwentyFiveRounds()
    { return 4; }

// the part-one round stood at forty-eight, the three-chain opener set the
// issue-25 closure bookkeeping
inline int l25PartOneInline()
    { return 48; }

// the part-two round stood at one hundred eighteen, the war game and vampire
// roster table round the issue-25 closure bookkeeping
inline int l25PartTwoInline()
    { return 118; }

// the part-three round stood at seventy, the three-chain commentary set the
// issue-25 closure bookkeeping
inline int l25PartThreeInline()
    { return 70; }

// the three opener rounds together pinned two hundred thirty-six the issue-25
// closure bookkeeping
inline int l25OpenerInlineTotal()
    { return 236; }

// the Dragon walk opened at issue two the issue-25 closure bookkeeping
inline int l25WalkFirstIssue()
    { return 2; }

// the walk now closes at issue twenty-five the issue-25 closure bookkeeping
inline int l25WalkLastClosed()
    { return 25; }

// issues two through twenty-five - twenty-four issues of the walk all closed
// the issue-25 closure bookkeeping
inline int l25WalkIssuesClosed()
    { return 24; }

// the battery census stood at eight hundred eighty-three before the flip the
// issue-25 closure bookkeeping
inline int l25CensusBefore()
    { return 883; }

// the flip raises the battery census to eight hundred eighty-four the
// issue-25 closure bookkeeping
inline int l25CensusAfter()
    { return 884; }

// the registry ground truth unchanged - one thousand three hundred thirteen
// loaded the issue-25 closure bookkeeping
inline int l25RegistryLoaded()
    { return 1313; }

// one thousand three hundred thirty-eight base lua the issue-25 closure
// bookkeeping
inline int l25RegistryBaseLua()
    { return 1338; }

// twenty-five never-load (R924 re-measure) the issue-25 closure bookkeeping
inline int l25RegistryNeverLoad()
    { return 25; }

// the combined experiment numbering - TD 25 the issue-25 closure bookkeeping
inline int l25TDNumber()
    { return 25; }

// Vol. III No. 11, May 1979 the issue-25 closure bookkeeping
inline int l25IssueYear()
    { return 1979; }

// the Dragon walk holds issues two through twenty-five complete the issue-25
// closure bookkeeping
inline bool l25WalkTwoThroughTwentyFive()
    { return true; }

// the opener set stands pinned - the Gygax social class essay, the Armies of
// the Renaissance Part III commentary, the Harrop orc taxonomy the issue-25
// closure bookkeeping
inline bool l25PartOneComplete()
    { return true; }

// the table round stands pinned - the Xochiyaoyotl war game with the prowess
// grid, the Varieties of Vampires with the fifteen-type roster the issue-25
// closure bookkeeping
inline bool l25PartTwoComplete()
    { return true; }

// the commentary set stands pinned - the War of Flowers, the To Select a
// Mythos guide, the Arms and Armor of the Conquistadores the issue-25 closure
// bookkeeping
inline bool l25PartThreeComplete()
    { return true; }

// the fourth four-round issue shape of the walk - the shape proven at issues
// 22, 23 and 24 now proven again the issue-25 closure bookkeeping
inline bool l25FourthFourRoundShape()
    { return true; }

// the numbering agrees everywhere - Vol. III No. 11, May 1979, number 25,
// except the cover printing Vol. III No. II (the roman II for 11), pinned as
// scanned the issue-25 closure bookkeeping
inline bool l25NumberingAgrees()
    { return true; }

// print folio equals PDF page this issue, verified at the page feet - folios
// five through forty-six the issue-25 closure bookkeeping
inline bool l25PrintFolioEqualsPdfPage()
    { return true; }

// the single-voice transcript - no archive.org djvu cross-check exists for
// issue 25 the issue-25 closure bookkeeping
inline bool l25SingleVoiceTranscript()
    { return true; }

// the print catches of all four rounds pinned as scanned, the conversion
// noted never silent the issue-25 closure bookkeeping
inline bool l25PrintCatchesPinned()
    { return true; }

// the Sullin levels seven through nine still print nowhere through the TD 26
// intake - a fifth issue running, the watch rides to TD 27 the issue-25
// closure bookkeeping
inline bool l25SullinWatchRides()
    { return true; }

// the brawling long-term-effects sequel still print nowhere through the TD 26
// intake - the watch rides to TD 27 the issue-25 closure bookkeeping
inline bool l25BrawlingWatchRides()
    { return true; }

// report 025 closes with all three boxes checked, joining mm2, ddg and
// report-024 in the closed state the issue-25 closure bookkeeping
inline bool l25GapReportClosed()
    { return true; }

}   // namespace rules
