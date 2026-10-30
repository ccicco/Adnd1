// =========================================================================================
// Adnd1 - rules/f16.h
// The Dragon issue-16 box closing round - the two-chain walk complete, the
// pure flip
// census 852 -> 853.
//
// Bookkeeping only, no new ink pinned. The issue-16 walk (the R929 opener
// carrying both chains, this flip) covered The Dragon Vol. III No. 2 (July
// 1978), the Curtiss-provided scan voice, single-voice - the mistral
// transcript of the uploaded Dm16.pdf; no archive.org djvu cross-check exists
// for issue 16. Print folio = PDF page minus two, verified at the R929 page
// feet. Registry ground truth unchanged: 1313 loaded / 1338 base lua / 25
// never-load (the R924 re-measure). Watch: the brawling long-term-effects
// sequel STILL does not print (watch TD 17); NO TD-17 teaser prints on the
// back cover.
//
// No print quirks ride this flip - the garbled cells of the opener (the
// Enkidu 1895 and Aqht 1875 strength prints, the as-a-normal-man armor
// classes, the assassination cost 1006/1518/2012 K prints against the
// doubling pattern, the eleven-band header vs ten-value rows, the thieving
// hide 70/60 drift) pin sentinel or as-scanned in the R929 layer and ride the
// transcript, noted never silent; this round flips the two report boxes and
// touches no ink.
//
namespace rules {

// ---- the issue-16 walk bookkeeping ----

// the issue-16 gap report - two boxes, both closed at this single flip
inline int f16IssueSixteenBoxes()
    { return 2; }

// the issue-16 walk - two engine chains in one opener round
inline int f16IssueSixteenChains()
    { return 2; }

// the issue-16 walk completes in two rounds - the R929 opener, this flip
inline int f16IssueSixteenRounds()
    { return 2; }

// the issue-15 report closed at R928
inline int f16IssueFifteenClosed()
    { return 1; }

// the issue-14 report closed at R926
inline int f16IssueFourteenClosed()
    { return 1; }

// the issue-13 report closed at R924
inline int f16IssueThirteenClosed()
    { return 1; }

// the issue-12 report closed at R922
inline int f16IssueTwelveClosed()
    { return 1; }

// the issue-11 report closed at R920
inline int f16IssueElevenClosed()
    { return 1; }

// the issue-10 report closed at R918
inline int f16IssueTenClosed()
    { return 1; }

// the issue-9 report closed at R916
inline int f16IssueNineClosed()
    { return 1; }

// the issue-8 report closed at R913
inline int f16IssueEightClosed()
    { return 1; }

// the issue-7 report closed at R911
inline int f16IssueSevenClosed()
    { return 1; }

// the issue-6 report closed at R909
inline int f16IssueSixClosed()
    { return 1; }

// the registry ground truth carried from the R924 re-measure - 1313 loaded
inline int f16RegistryLoaded()
    { return 1313; }

// the registry ground truth - 1338 base lua
inline int f16RegistryBaseLua()
    { return 1338; }

// the registry ground truth - 25 never-load
inline int f16RegistryNeverLoad()
    { return 25; }

// the issue-6 walk complete
inline bool f16WalkSixComplete()
    { return true; }

// the issue-7 walk complete
inline bool f16WalkSevenComplete()
    { return true; }

// the issue-8 walk complete
inline bool f16WalkEightComplete()
    { return true; }

// the issue-9 walk complete
inline bool f16WalkNineComplete()
    { return true; }

// the issue-10 walk complete
inline bool f16WalkTenComplete()
    { return true; }

// the issue-11 walk complete
inline bool f16WalkElevenComplete()
    { return true; }

// the issue-12 walk complete
inline bool f16WalkTwelveComplete()
    { return true; }

// the issue-13 walk complete
inline bool f16WalkThirteenComplete()
    { return true; }

// the issue-14 walk complete
inline bool f16WalkFourteenComplete()
    { return true; }

// the issue-15 walk complete
inline bool f16WalkFifteenComplete()
    { return true; }

// the issue-16 walk complete at this flip
inline bool f16WalkSixteenComplete()
    { return true; }

}   // namespace rules
