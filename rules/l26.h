// =========================================================================================
// Adnd1 - rules/l26.h
// The Dragon issue-26 box closing round - the fifth four-round walk complete,
// issues 2 through 26 all closed
// census 887 -> 888.
//
// The pure flip, no new ink - all three report-026 boxes check at this single
// round: the part-one opener set (R962, t26), the part-two table round (R963,
// s26) and the part-three commentary set (R964, k26). The walk holds issues
// 2-26 all closed, the four-round shape five times proven at issues 22, 23,
// 24, 25 and 26; the TD 27 intake stands unadjudicated with the Sullin and
// brawling watches - absent a sixth issue - riding on to TD 27. Pinned from
// The Dragon Vol. III No. 12 (June 1979) number 26, the single-voice
// transcript of the Curtiss-provided scan at extract/dragon/026, landed in
// the repo at R962.
//
namespace rules {

// ---- the issue-26 closure bookkeeping ----

// all three report-026 boxes close at this single flip - the part-one,
// part-two and part-three lines the issue-26 closure bookkeeping
inline int l26IssueTwentySixBoxes()
    { return 3; }

// the thirteen chains of the TD-26 call - the opener set five, the table
// round four, the commentary set four the issue-26 closure bookkeeping
inline int l26IssueTwentySixChains()
    { return 13; }

// the four-round issue shape of the walk - three openers plus the closing
// flip the issue-26 closure bookkeeping
inline int l26IssueTwentySixRounds()
    { return 4; }

// the part-one round stood at eighty, the five-chain opener set the issue-26
// closure bookkeeping
inline int l26PartOneInline()
    { return 80; }

// the part-two round stood at one hundred eleven, the four-chain table round
// the issue-26 closure bookkeeping
inline int l26PartTwoInline()
    { return 111; }

// the part-three round stood at eighty-nine, the four-chain commentary set
// the issue-26 closure bookkeeping
inline int l26PartThreeInline()
    { return 89; }

// the three opener rounds together pinned two hundred eighty the issue-26
// closure bookkeeping
inline int l26OpenerInlineTotal()
    { return 280; }

// the Dragon walk opened at issue two the issue-26 closure bookkeeping
inline int l26WalkFirstIssue()
    { return 2; }

// the walk now closes at issue twenty-six the issue-26 closure bookkeeping
inline int l26WalkLastClosed()
    { return 26; }

// issues two through twenty-six - twenty-five issues of the walk all closed
// the issue-26 closure bookkeeping
inline int l26WalkIssuesClosed()
    { return 25; }

// the battery census stood at eight hundred eighty-seven before the flip the
// issue-26 closure bookkeeping
inline int l26CensusBefore()
    { return 887; }

// the flip raises the battery census to eight hundred eighty-eight the
// issue-26 closure bookkeeping
inline int l26CensusAfter()
    { return 888; }

// the registry ground truth unchanged - one thousand three hundred thirteen
// loaded the issue-26 closure bookkeeping
inline int l26RegistryLoaded()
    { return 1313; }

// one thousand three hundred thirty-eight base lua the issue-26 closure
// bookkeeping
inline int l26RegistryBaseLua()
    { return 1338; }

// twenty-five never-load (R924 re-measure) the issue-26 closure bookkeeping
inline int l26RegistryNeverLoad()
    { return 25; }

// the combined experiment numbering - TD 26 the issue-26 closure bookkeeping
inline int l26TDNumber()
    { return 26; }

// Vol. III No. 12, June 1979 the issue-26 closure bookkeeping
inline int l26IssueYear()
    { return 1979; }

// the Dragon walk holds issues two through twenty-six complete the issue-26
// closure bookkeeping
inline bool l26WalkTwoThroughTwentySix()
    { return true; }

// the opener set stands pinned - the Giants in the Earth column debut, the
// Sagui hireling pay doctrine, the Krebs SAGE microcomputer piece, the Crane
// moderator dark secrets and the Gygax D&D AD&D gaming history essay the
// issue-26 closure bookkeeping
inline bool l26PartOneComplete()
    { return true; }

// the table round stands pinned - the Chinese Undead roster, the nine-point
// alignment chart, the Deck of Fate and the strength comparison ladder the
// issue-26 closure bookkeeping
inline bool l26PartTwoComplete()
    { return true; }

// the commentary set stands pinned - the lich recipe, the impromptu party
// system, the barghest and the city thief doctrine the issue-26 closure
// bookkeeping
inline bool l26PartThreeComplete()
    { return true; }

// the fifth four-round issue shape of the walk - the shape proven at issues
// 22, 23, 24 and 25 now proven again the issue-26 closure bookkeeping
inline bool l26FifthFourRoundShape()
    { return true; }

// the numbering agrees everywhere - Vol. III No. 12, June 1979, number 26,
// except the cover printing the issue tag 36, pinned as scanned the issue-26
// closure bookkeeping
inline bool l26NumberingAgrees()
    { return true; }

// print folio equals the PDF page minus two this issue, verified at the page
// feet - folios three through forty-seven the issue-26 closure bookkeeping
inline bool l26PrintFolioEqualsPdfPageMinusTwo()
    { return true; }

// the single-voice transcript - the chat-side mistral transcript of the
// Curtiss-provided scan, the fifty-two pages landed in the repo at R962 the
// issue-26 closure bookkeeping
inline bool l26SingleVoiceTranscript()
    { return true; }

// the print catches of all four rounds pinned as scanned - the ADVANCE
// DUNGEONS trademark, the Ameson, the Choate thrice, the Serf row and the
// barghest stat block, the conversion noted never silent the issue-26 closure
// bookkeeping
inline bool l26PrintCatchesPinned()
    { return true; }

// the Sullin levels seven through nine still print nowhere through the TD 26
// intake - a fifth issue running, the watch rides to TD 27 the issue-26
// closure bookkeeping
inline bool l26SullinWatchRides()
    { return true; }

// the brawling long-term-effects sequel still print nowhere through the TD 26
// intake - the watch rides to TD 27 the issue-26 closure bookkeeping
inline bool l26BrawlingWatchRides()
    { return true; }

// report 026 closes with all three boxes checked, joining mm2, ddg,
// report-024 and report-025 in the closed state the issue-26 closure
// bookkeeping
inline bool l26GapReportClosed()
    { return true; }

}   // namespace rules
