// =========================================================================================
// Adnd1 - rules/f18.h
// The Dragon issue-18 box closing round - the seven-chain walk complete, the
// pure flip
// census 858 -> 859.
//
// Bookkeeping only, no new ink pinned. The issue-18 walk (the R934 opener
// part one carrying the four chains - insanity, the laws of magic, the
// godgame, the NPC tables; the R935 opener part two carrying the three chains
// - the new spells, the monkish weapons and kedo, the poison; this flip)
// covered The Dragon Vol. III No. 4 (September 1978), the Curtiss-provided
// scan voice, single-voice - the mistral transcript of the uploaded Dm18.pdf;
// no archive.org djvu cross-check exists for issue 18. PRINT FOLIO = PDF PAGE
// MINUS TWO, verified at the R934 page feet (folios 3, 9, 13, 14, 19, 21, 24
// and 31 print at the PDF pages 5, 11, 15, 16, 21, 23, 26 and 33). Registry
// ground truth unchanged: 1313 loaded / 1338 base lua / 25 never-load (the
// R924 re-measure). Watch: the Sullin New Spells levels 7-9 (the cont pg 21
// promise) NEVER printed in TD18 - watch TD 19; the brawling
// long-term-effects sequel STILL does not print - watch TD 19.
//
// No print quirks ride this flip - the as-scanned garbles of the openers (the
// kedo attack list printing 2-8 with attack 1 never printed and the migi-do
// row matrix-only, the lone dar transposition, the six kedo diagonal breaks
// with the crossed migi-do and gyaku-do blocks, the doubled bowbow, the
// work-quality 03-20 band that never prints, the greed compound bands, the
// pride 00 percentile cell, the insanity odd 12, the poison A week and C hour
// conversions) stay pinned in the opener headers where they landed, noted
// never silent.
//
namespace rules {

// ---- the issue-18 walk bookkeeping ----

// both report-018 boxes close at this single flip - the part-one and part-two
// opener chains (report 018)
inline int f18IssueEighteenBoxes()
    { return 2; }

// the issue-18 chain count - four part-one chains (insanity, magic laws,
// godgame, NPC characteristics) plus three part-two chains (new spells,
// monkish weapons and kedo, poison) walked across three rounds
inline int f18IssueEighteenChains()
    { return 7; }

// the issue-18 round shape - the R934 opener part one, the R935 opener part
// two, this R936 closing flip, the second three-round issue after issue 17
inline int f18IssueEighteenRounds()
    { return 3; }

// issue 17 stands closed since R933
inline int f18IssueSeventeenClosed()
    { return 1; }

// issue 16 stands closed
inline int f18IssueSixteenClosed()
    { return 1; }

// issue 15 stands closed
inline int f18IssueFifteenClosed()
    { return 1; }

// issue 14 stands closed
inline int f18IssueFourteenClosed()
    { return 1; }

// issue 13 stands closed
inline int f18IssueThirteenClosed()
    { return 1; }

// issue 12 stands closed
inline int f18IssueTwelveClosed()
    { return 1; }

// issue 11 stands closed
inline int f18IssueElevenClosed()
    { return 1; }

// issue 10 stands closed
inline int f18IssueTenClosed()
    { return 1; }

// issue 9 stands closed
inline int f18IssueNineClosed()
    { return 1; }

// issue 8 stands closed
inline int f18IssueEightClosed()
    { return 1; }

// issue 7 stands closed
inline int f18IssueSevenClosed()
    { return 1; }

// the registry ground truth - 1313 loaded defs, unchanged from the R924
// re-measure
inline int f18RegistryLoaded()
    { return 1313; }

// the registry base lua count, 1338, unchanged
inline int f18RegistryBaseLua()
    { return 1338; }

// the registry never-load count, 25, unchanged
inline int f18RegistryNeverLoad()
    { return 25; }

// the Dragon walk holds issues 2 through 7 complete
inline bool f18WalkSevenComplete()
    { return true; }

// issue 8 complete
inline bool f18WalkEightComplete()
    { return true; }

// issue 9 complete
inline bool f18WalkNineComplete()
    { return true; }

// issue 10 complete
inline bool f18WalkTenComplete()
    { return true; }

// issue 11 complete
inline bool f18WalkElevenComplete()
    { return true; }

// issue 12 complete
inline bool f18WalkTwelveComplete()
    { return true; }

// issue 13 complete
inline bool f18WalkThirteenComplete()
    { return true; }

// issue 14 complete
inline bool f18WalkFourteenComplete()
    { return true; }

// issue 15 complete
inline bool f18WalkFifteenComplete()
    { return true; }

// issue 16 complete
inline bool f18WalkSixteenComplete()
    { return true; }

// issue 17 complete
inline bool f18WalkSeventeenComplete()
    { return true; }

// ISSUE 18 COMPLETE AT THIS FLIP - the walk now holds issues 2 through 18
// closed
inline bool f18WalkEighteenComplete()
    { return true; }

}   // namespace rules
