// =========================================================================================
// Adnd1 - rules/f15.h
// The Dragon issue-15 box closing round - the five-chain walk complete, the
// pure flip
// census 850 -> 851.
//
// Bookkeeping only, no new ink pinned. The issue-15 walk (the R927 opener
// carrying all five chains, this flip) covered The Dragon Vol. III No. 1
// (June 1978), the Curtiss-provided scan voice, single-voice - the mistral
// transcript of the uploaded Dm15.pdf; no archive.org djvu cross-check exists
// for issue 15, the accessory items end at issue 14. Print folio = PDF page
// minus two, verified at the R927 page feet; the TOC prints two swapped
// folios. Registry ground truth unchanged: 1313 loaded / 1338 base lua / 25
// never-load (the R924 re-measure). Watch: the brawling long-term-effects
// sequel STILL does not print (watch TD 16).
//
// No print quirks ride this flip - the garbled cells of the opener (the
// shared-35 occupied-pit bound, the ranger 91-85 upper bound, the
// non-contiguous seasonal unusual faces) pin sentinel in the R927 layer and
// ride the transcript, noted never silent; this round flips the five report
// boxes and touches no ink.
//
namespace rules {

// ---- the issue-15 walk bookkeeping ----

// the issue-15 gap report - five boxes, all closed at this single flip
inline int f15IssueFifteenBoxes()
    { return 5; }

// the issue-15 walk - five engine chains in one opener round
inline int f15IssueFifteenChains()
    { return 5; }

// the issue-15 walk completes in two rounds - the R927 opener, this flip
inline int f15IssueFifteenRounds()
    { return 2; }

// the issue-14 report closed at R926
inline int f15IssueFourteenClosed()
    { return 1; }

// the issue-13 report closed at R924
inline int f15IssueThirteenClosed()
    { return 1; }

// the issue-12 report closed at R922
inline int f15IssueTwelveClosed()
    { return 1; }

// the issue-11 report closed at R920
inline int f15IssueElevenClosed()
    { return 1; }

// the issue-10 report closed at R918
inline int f15IssueTenClosed()
    { return 1; }

// the issue-9 report closed at R916
inline int f15IssueNineClosed()
    { return 1; }

// the issue-8 report closed at R913
inline int f15IssueEightClosed()
    { return 1; }

// the issue-7 report closed at R911
inline int f15IssueSevenClosed()
    { return 1; }

// the issue-6 report closed at R909
inline int f15IssueSixClosed()
    { return 1; }

// the registry ground truth carried from the R924 re-measure - 1313 loaded
inline int f15RegistryLoaded()
    { return 1313; }

// the registry ground truth - 1338 base lua
inline int f15RegistryBaseLua()
    { return 1338; }

// the registry ground truth - 25 never-load
inline int f15RegistryNeverLoad()
    { return 25; }

// the issue-6 walk complete
inline bool f15WalkSixComplete()
    { return true; }

// the issue-7 walk complete
inline bool f15WalkSevenComplete()
    { return true; }

// the issue-8 walk complete
inline bool f15WalkEightComplete()
    { return true; }

// the issue-9 walk complete
inline bool f15WalkNineComplete()
    { return true; }

// the issue-10 walk complete
inline bool f15WalkTenComplete()
    { return true; }

// the issue-11 walk complete
inline bool f15WalkElevenComplete()
    { return true; }

// the issue-12 walk complete
inline bool f15WalkTwelveComplete()
    { return true; }

// the issue-13 walk complete
inline bool f15WalkThirteenComplete()
    { return true; }

// the issue-14 walk complete
inline bool f15WalkFourteenComplete()
    { return true; }

// the issue-15 walk complete at this flip
inline bool f15WalkFifteenComplete()
    { return true; }

}   // namespace rules
