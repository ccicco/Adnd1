// =========================================================================================
// Adnd1 - rules/d21.h
// The Dragon issue-21 box closing round - the seven-chain walk complete,
// issues 2 through 21 all closed
// census 867 -> 868.
//
// The pure flip of the issue-21 three-round shape - no new ink pinned, both
// report-021 boxes closed. The issue-21 openers stand at R943 (t21: the
// twenty-NPC personality grid, the spell-research doctrine, the
// foretelling-spell counters) and R944 (g21: the gold-piece inflation
// doctrine, the natural-history monster doctrine, the Hall of Mystery, the
// M-U titles kit), all pinned from The Dragon Vol. III No. 6 (December 1978),
// the Curtiss-provided Dm21.pdf scan voice, print folio the PDF page minus
// two.
//
// No new print catches at this flip - the issue-21 print quirks all rode the
// two opener records: the contents masthead Vol. 111 No. 6 November 1978
// stamp, the Rollo seven-number prose statline, the Suliin and Ventriliquism
// spellings, the Medivar spelling, the ten-column chart against the
// seven-column prose walk, the WIZARD header for the M-U contents line, the
// Magnificance Irrestible Reknown Belligerant Contretious Sourge spellings,
// the envision and ol-Gandalf typos, the Otyugl census spelling and the
// Ann-for-And verse - all pinned as scanned, the conversion noted
//
namespace rules {

// ---- the issue-21 closure bookkeeping ----

// both report-021 boxes close at this single flip - the part-one and part-two
// opener boxes
inline int d21IssueTwentyOneBoxes()
    { return 2; }

// the issue-21 chain count - three part-one chains (the twenty-NPC
// personality grid, the spell-research doctrine, the foretelling-spell
// counters) and four part-two chains (the gold-piece inflation doctrine, the
// natural-history monster doctrine, the Hall of Mystery, the M-U titles kit)
inline int d21IssueTwentyOneChains()
    { return 7; }

// the issue-21 round shape - the R943 opener part one, the R944 opener part
// two and this R945 pure flip, the fifth three-round issue shape
inline int d21IssueTwentyOneRounds()
    { return 3; }

// issue 7 stands closed since its own flip
inline int d21IssueSevenClosed()
    { return 1; }

// issue 8 stands closed since its own flip
inline int d21IssueEightClosed()
    { return 1; }

// issue 9 stands closed since its own flip
inline int d21IssueNineClosed()
    { return 1; }

// issue 10 stands closed since its own flip
inline int d21IssueTenClosed()
    { return 1; }

// issue 11 stands closed since its own flip
inline int d21IssueElevenClosed()
    { return 1; }

// issue 12 stands closed since its own flip
inline int d21IssueTwelveClosed()
    { return 1; }

// issue 13 stands closed since its own flip
inline int d21IssueThirteenClosed()
    { return 1; }

// issue 14 stands closed since its own flip
inline int d21IssueFourteenClosed()
    { return 1; }

// issue 15 stands closed since its own flip
inline int d21IssueFifteenClosed()
    { return 1; }

// issue 16 stands closed since its own flip
inline int d21IssueSixteenClosed()
    { return 1; }

// issue 17 stands closed since its own flip
inline int d21IssueSeventeenClosed()
    { return 1; }

// issue 18 stands closed since its own flip
inline int d21IssueEighteenClosed()
    { return 1; }

// issue 19 stands closed since its own flip
inline int d21IssueNineteenClosed()
    { return 1; }

// issue 20 stands closed since the R942 d2c flip
inline int d21IssueTwentyClosed()
    { return 1; }

// the registry ground truth - loaded lua files per the R924 re-measure
inline int d21RegistryLoaded()
    { return 1313; }

// the registry base lua count per the R924 re-measure
inline int d21RegistryBaseLua()
    { return 1338; }

// the registry never-load count per the R924 re-measure
inline int d21RegistryNeverLoad()
    { return 25; }

// the Dragon walk holds issues 2 through 7 complete
inline bool d21WalkSevenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 8 complete
inline bool d21WalkEightComplete()
    { return true; }

// the Dragon walk holds issues 2 through 9 complete
inline bool d21WalkNineComplete()
    { return true; }

// the Dragon walk holds issues 2 through 10 complete
inline bool d21WalkTenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 11 complete
inline bool d21WalkElevenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 12 complete
inline bool d21WalkTwelveComplete()
    { return true; }

// the Dragon walk holds issues 2 through 13 complete
inline bool d21WalkThirteenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 14 complete
inline bool d21WalkFourteenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 15 complete
inline bool d21WalkFifteenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 16 complete
inline bool d21WalkSixteenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 17 complete
inline bool d21WalkSeventeenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 18 complete
inline bool d21WalkEighteenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 19 complete
inline bool d21WalkNineteenComplete()
    { return true; }

// the Dragon walk holds issues 2 through 20 complete
inline bool d21WalkTwentyComplete()
    { return true; }

// the Dragon walk holds issues 2 through 21 complete
inline bool d21WalkTwentyOneComplete()
    { return true; }

}   // namespace rules
