// =========================================================================================
// Adnd1 - rules/d19.h
// The Dragon issue-19 box closing round - the six-chain walk complete, issues
// 2 through 19 all closed
// census 861 -> 862.
//
// The pure flip of the issue-19 three-round shape - no new ink pinned, both
// report-019 boxes closed. The issue-19 openers stand at R937 (dws: the
// wish-spell doctrine, the mythos of Australia, the systematic magic fields)
// and R938 (sdm: the Origins 78 tourney and scoring, the treasure chains, the
// spell determination grids), all pinned from The Dragon Vol. III No. 5
// (October 1978), the Curtiss-provided Dm19.pdf scan voice.
//
// No new print catches at this flip - the issue-19 print quirks all rode the
// two opener records: the doubled Gate, the Champion 7th Wawalag line, the
// Mimi armor class 8, the Smurre continuation stamp, the Kuo-Tao spelling
// cross, the unassigned 14-15 location bands, the -01-05 leading dash and the
// dungeons-only asterisks. Both inherited watches - the Sullin levels 7-9 and
// the brawling sequel - stayed empty through issue 19 and ride to TD 20.
//
namespace rules {

// ---- the issue-19 closure bookkeeping ----

// both report-019 boxes close at this single flip - the part-one and part-two
// opener boxes
inline int d19IssueNineteenBoxes()
    { return 2; }

// the issue-19 chain count - three part-one chains (wishes, mythos of
// Australia, systematic magic) and three part-two chains (the Origins 78
// tourney and scoring, the treasure chains, the hostile MU spell
// determination)
inline int d19IssueNineteenChains()
    { return 6; }

// the issue-19 round shape - the R937 opener part one, the R938 opener part
// two and this R939 pure flip, the third three-round issue shape
inline int d19IssueNineteenRounds()
    { return 3; }

// issue 7 stands closed since its own flip
inline int d19IssueSevenClosed()
    { return 1; }

// issue 8 stands closed since its own flip
inline int d19IssueEightClosed()
    { return 1; }

// issue 9 stands closed since its own flip
inline int d19IssueNineClosed()
    { return 1; }

// issue 10 stands closed since its own flip
inline int d19IssueTenClosed()
    { return 1; }

// issue 11 stands closed since its own flip
inline int d19IssueElevenClosed()
    { return 1; }

// issue 12 stands closed since its own flip
inline int d19IssueTwelveClosed()
    { return 1; }

// issue 13 stands closed since its own flip
inline int d19IssueThirteenClosed()
    { return 1; }

// issue 14 stands closed since its own flip
inline int d19IssueFourteenClosed()
    { return 1; }

// issue 15 stands closed since its own flip
inline int d19IssueFifteenClosed()
    { return 1; }

// issue 16 stands closed since its own flip
inline int d19IssueSixteenClosed()
    { return 1; }

// issue 17 stands closed since its own flip
inline int d19IssueSeventeenClosed()
    { return 1; }

// issue 18 stands closed since its own flip
inline int d19IssueEighteenClosed()
    { return 1; }

// the registry ground truth - 1313 loaded defs, unchanged from the R924
// re-measure
inline int d19RegistryLoaded()
    { return 1313; }

// the registry base lua count, 1338, unchanged
inline int d19RegistryBaseLua()
    { return 1338; }

// the registry never-load count, 25, unchanged
inline int d19RegistryNeverLoad()
    { return 25; }

// the Dragon walk holds issues 2 through 7 complete
inline bool d19WalkSevenComplete()
    { return true; }

// issue 8 complete
inline bool d19WalkEightComplete()
    { return true; }

// issue 9 complete
inline bool d19WalkNineComplete()
    { return true; }

// issue 10 complete
inline bool d19WalkTenComplete()
    { return true; }

// issue 11 complete
inline bool d19WalkElevenComplete()
    { return true; }

// issue 12 complete
inline bool d19WalkTwelveComplete()
    { return true; }

// issue 13 complete
inline bool d19WalkThirteenComplete()
    { return true; }

// issue 14 complete
inline bool d19WalkFourteenComplete()
    { return true; }

// issue 15 complete
inline bool d19WalkFifteenComplete()
    { return true; }

// issue 16 complete
inline bool d19WalkSixteenComplete()
    { return true; }

// issue 17 complete
inline bool d19WalkSeventeenComplete()
    { return true; }

// issue 18 complete
inline bool d19WalkEighteenComplete()
    { return true; }

// ISSUE 19 COMPLETE AT THIS FLIP - the walk now holds issues 2 through 19
inline bool d19WalkNineteenComplete()
    { return true; }

}   // namespace rules
