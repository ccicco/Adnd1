// =========================================================================================
// Adnd1 - rules/d2c.h
// The Dragon issue-20 box closing round - the five-chain walk complete,
// issues 2 through 20 all closed
// census 864 -> 865.
//
// The pure flip of the issue-20 three-round shape - no new ink pinned, both
// report-020 boxes closed. The issue-20 openers stand at R940 (t20: the
// Polynesian pantheon, the witch class ladder, the demonology grids) and R941
// (dst: the 600-death campaign census, the demonic possession and exorcism
// doctrine), all pinned from The Dragon Vol. III No. 6 (November 1978), the
// Curtiss-provided Dm20.pdf scan voice.
//
// No new print catches at this flip - the issue-20 print quirks all rode the
// two opener records: the contents page Vol. III No. 5 stamp, the Kampua-a
// markless 150 move, the Demonette 3 1 ladder cell, the 155 love potion, the
// B and D Variant header, the type I 85 double-assignment, the type V both-VI
// flanks, the 100.1 percent death column and the dangling-dash 55 percent
// victim-freed line. Both inherited watches - the Sullin levels 7-9 and the
// brawling sequel - print nowhere in TD20 and ride to TD 21.
//
namespace rules {

// ---- the issue-20 closure bookkeeping ----

// both report-020 boxes close at this single flip - the part-one and part-two
// opener boxes
inline int d2cIssueTwentyBoxes()
    { return 2; }

// the issue-20 chain count - three part-one chains (the Polynesian pantheon,
// the witch class ladder, the demonology grids) and two part-two chains (the
// 600-death campaign census, the demonic possession doctrine), all five
// chains IN the Curtiss call
inline int d2cIssueTwentyChains()
    { return 5; }

// the issue-20 round shape - the R940 opener part one, the R941 opener part
// two and this R942 pure flip, the fourth three-round issue shape
inline int d2cIssueTwentyRounds()
    { return 3; }

// issue 7 stands closed since its own flip
inline int d2cIssueSevenClosed()
    { return 1; }

// issue 8 stands closed since its own flip
inline int d2cIssueEightClosed()
    { return 1; }

// issue 9 stands closed since its own flip
inline int d2cIssueNineClosed()
    { return 1; }

// issue 10 stands closed since its own flip
inline int d2cIssueTenClosed()
    { return 1; }

// issue 11 stands closed since its own flip
inline int d2cIssueElevenClosed()
    { return 1; }

// issue 12 stands closed since its own flip
inline int d2cIssueTwelveClosed()
    { return 1; }

// issue 13 stands closed since its own flip
inline int d2cIssueThirteenClosed()
    { return 1; }

// issue 14 stands closed since its own flip
inline int d2cIssueFourteenClosed()
    { return 1; }

// issue 15 stands closed since its own flip
inline int d2cIssueFifteenClosed()
    { return 1; }

// issue 16 stands closed since its own flip
inline int d2cIssueSixteenClosed()
    { return 1; }

// issue 17 stands closed since its own flip
inline int d2cIssueSeventeenClosed()
    { return 1; }

// issue 18 stands closed since its own flip
inline int d2cIssueEighteenClosed()
    { return 1; }

// issue 19 stands closed since its own flip
inline int d2cIssueNineteenClosed()
    { return 1; }

// the registry ground truth - 1313 loaded defs, unchanged from the R924
// re-measure
inline int d2cRegistryLoaded()
    { return 1313; }

// the registry base lua count, 1338, unchanged
inline int d2cRegistryBaseLua()
    { return 1338; }

// the registry never-load count, 25, unchanged
inline int d2cRegistryNeverLoad()
    { return 25; }

// the Dragon walk holds issues 2 through 7 complete
inline bool d2cWalkSevenComplete()
    { return true; }

// issue 8 complete
inline bool d2cWalkEightComplete()
    { return true; }

// issue 9 complete
inline bool d2cWalkNineComplete()
    { return true; }

// issue 10 complete
inline bool d2cWalkTenComplete()
    { return true; }

// issue 11 complete
inline bool d2cWalkElevenComplete()
    { return true; }

// issue 12 complete
inline bool d2cWalkTwelveComplete()
    { return true; }

// issue 13 complete
inline bool d2cWalkThirteenComplete()
    { return true; }

// issue 14 complete
inline bool d2cWalkFourteenComplete()
    { return true; }

// issue 15 complete
inline bool d2cWalkFifteenComplete()
    { return true; }

// issue 16 complete
inline bool d2cWalkSixteenComplete()
    { return true; }

// issue 17 complete
inline bool d2cWalkSeventeenComplete()
    { return true; }

// issue 18 complete
inline bool d2cWalkEighteenComplete()
    { return true; }

// issue 19 complete
inline bool d2cWalkNineteenComplete()
    { return true; }

// ISSUE 20 COMPLETE AT THIS FLIP - the walk now holds issues 2 through 20
inline bool d2cWalkTwentyComplete()
    { return true; }

}   // namespace rules
