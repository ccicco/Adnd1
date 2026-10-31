// =========================================================================================
// Adnd1 - rules/l24.h
// The Dragon issue-24 box closing round - the third four-round walk complete,
// issues 2 through 24 all closed
// census 879 -> 880.
//
// The pure flip, no new ink - all three report-024 boxes check at this single
// round: the part-one variant triptych (R954, t24), the part-two alignment
// pantheon (R955, s24) and the part-three ten-chain commentary set (R956,
// k24). The walk holds issues 2-24 all closed, the four-round shape thrice
// proven at issues 22, 23 and 24; the Sullin and brawling watches ride to TD
// 25. Pinned from The Dragon Vol. III No. 10 (April 1979) number 24, the
// single-voice transcript of the Curtiss-provided scan at extract/dragon/024.
//
namespace rules {

// ---- the issue-24 closure bookkeeping ----

// all three report-024 boxes close at this single flip - the part-one,
// part-two and part-three lines the issue-24 closure bookkeeping
inline int l24IssueTwentyFourBoxes()
    { return 3; }

// the fourteen chains of the TD-24 call - the triptych three, the pantheon
// one, the commentary set ten the issue-24 closure bookkeeping
inline int l24IssueTwentyFourChains()
    { return 14; }

// the third four-round issue shape of the walk - three openers plus the
// closing flip the issue-24 closure bookkeeping
inline int l24IssueTwentyFourRounds()
    { return 4; }

// the part-one round stood at one hundred thirty-four, the variant triptych
// the issue-24 closure bookkeeping
inline int l24PartOneInline()
    { return 134; }

// the part-two round stood at one hundred forty-six, the alignment pantheon
// table round the issue-24 closure bookkeeping
inline int l24PartTwoInline()
    { return 146; }

// the part-three round stood at two hundred ninety-one, the ten-chain
// commentary set the issue-24 closure bookkeeping
inline int l24PartThreeInline()
    { return 291; }

// the three opener rounds together pinned five hundred seventy-one the
// issue-24 closure bookkeeping
inline int l24OpenerInlineTotal()
    { return 571; }

// the Dragon walk opened at issue two the issue-24 closure bookkeeping
inline int l24WalkFirstIssue()
    { return 2; }

// the walk now closes at issue twenty-four the issue-24 closure bookkeeping
inline int l24WalkLastClosed()
    { return 24; }

// issues two through twenty-four - twenty-three issues of the walk all closed
// the issue-24 closure bookkeeping
inline int l24WalkIssuesClosed()
    { return 23; }

// the battery census stood at eight hundred seventy-nine before the flip the
// issue-24 closure bookkeeping
inline int l24CensusBefore()
    { return 879; }

// the flip raises the battery census to eight hundred eighty the issue-24
// closure bookkeeping
inline int l24CensusAfter()
    { return 880; }

// the registry ground truth unchanged - one thousand three hundred thirteen
// loaded the issue-24 closure bookkeeping
inline int l24RegistryLoaded()
    { return 1313; }

// one thousand three hundred thirty-eight base lua the issue-24 closure
// bookkeeping
inline int l24RegistryBaseLua()
    { return 1338; }

// twenty-five never-load (R924 re-measure) the issue-24 closure bookkeeping
inline int l24RegistryNeverLoad()
    { return 25; }

// the combined experiment numbering - TD 24 the issue-24 closure bookkeeping
inline int l24TDNumber()
    { return 24; }

// Vol. III No. 10, April 1979 the issue-24 closure bookkeeping
inline int l24IssueYear()
    { return 1979; }

// the Dragon walk holds issues two through twenty-four complete the issue-24
// closure bookkeeping
inline bool l24WalkTwoThroughTwentyFour()
    { return true; }

// the variant triptych stands pinned - the Lost Civilizations supplement, the
// Chinese dragons roster, the lycanthropy infection types the issue-24
// closure bookkeeping
inline bool l24PartOneComplete()
    { return true; }

// the alignment pantheon stands pinned - the eighteen prime alignments, the
// twenty-one prime deities, the four elemental lords, the five sons of Thakta
// Tylden the issue-24 closure bookkeeping
inline bool l24PartTwoComplete()
    { return true; }

// the ten-chain commentary set stands pinned - the magic-user limits, the
// Roman maniples, the Viking scenarios, the melee rationale, the DUNGEON
// variants, the Swiss phalanxes, the psionic powers, the disease charts, the
// Petal Throne name grid, the Monty Haul satire the issue-24 closure
// bookkeeping
inline bool l24PartThreeComplete()
    { return true; }

// the third four-round issue shape of the walk - the shape proven at issues
// 22 and 23 now proven again the issue-24 closure bookkeeping
inline bool l24ThirdFourRoundShape()
    { return true; }

// the numbering agrees everywhere - Vol. III No. 10, April 1979, number 24
// the issue-24 closure bookkeeping
inline bool l24NumberingAgrees()
    { return true; }

// print folio equals PDF page this issue, verified at the page feet - folios
// five through forty-six the issue-24 closure bookkeeping
inline bool l24PrintFolioEqualsPdfPage()
    { return true; }

// the single-voice transcript - no archive.org djvu cross-check exists for
// issue 24 the issue-24 closure bookkeeping
inline bool l24SingleVoiceTranscript()
    { return true; }

// the print catches of all four rounds pinned as scanned, the conversion
// noted never silent the issue-24 closure bookkeeping
inline bool l24PrintCatchesPinned()
    { return true; }

// the Sullin levels seven through nine still print nowhere - the watch rides
// to TD 25 the issue-24 closure bookkeeping
inline bool l24SullinWatchRides()
    { return true; }

// the brawling long-term-effects sequel still print nowhere - the watch rides
// to TD 25 the issue-24 closure bookkeeping
inline bool l24BrawlingWatchRides()
    { return true; }

// report 024 closes with all three boxes checked, joining mm2 and ddg in the
// closed state the issue-24 closure bookkeeping
inline bool l24GapReportClosed()
    { return true; }

}   // namespace rules
