// =========================================================================================
// Adnd1 - rules/f14.h
// The Dragon issue-14 box closing round - the two-chain walk complete, the
// pure flip
// census 848 -> 849.
//
// Bookkeeping only, no new ink pinned. The issue-14 walk (the R925 opener
// carrying both chains, this flip) covered The Dragon Vol. II No. 8 (May
// 1978), the archive.org scan voice, single-voice - no chat-side upload
// cross-check exists for issue 14; the source lives in the archive.org item
// accessory-dragon-magazine-012, which holds issues 7-14. The transcripts
// ride extract/dragon/014/p001 through p036, landed at R925; print folio =
// PDF page minus two in this issue.
//
// The R925 sentinel pins ride unchanged - the Jarnkung hit-dice bar garble
// resolved at the full-res scan to 5, the Crawler 3 1/2 prose pinned as the
// dice and the 7-halves total, the experience-grid row-4 cell pinned
// as-scanned at 1000 with the dropped zero noted, the change-time in halves
// and the predominance ladder with its printed leading zeros all ride as
// pinned, noted never silent. The registry ground truth carried forward
// unchanged from the R924 re-measure: 1313 loaded / 1338 base / 25
// never-load.
//
namespace rules {

// ---- the issue-14 walk bookkeeping ----

// the issue-14 gap report carries two boxes (report 014)
inline int f14IssueFourteenBoxes()
    { return 2; }

// the issue-14 walk pinned two chains - the Name That Monster Contest #1
// winners and the Rihn lycanthropy variant, both in the R925 opener
inline int f14IssueFourteenChains()
    { return 2; }

// the issue-14 walk ran two rounds - the R925 opener carrying both chains and
// this R926 flip, the issue-11 two-round pattern
inline int f14IssueFourteenRounds()
    { return 2; }

// the issue-13 report complete at 2 closed / 0 open since R924
inline int f14IssueThirteenClosed()
    { return 1; }

// the issue-12 report complete at 2 closed / 0 open since R921
inline int f14IssueTwelveClosed()
    { return 1; }

// the issue-11 report complete at 1 closed / 0 open since R918
inline int f14IssueElevenClosed()
    { return 1; }

// the issue-10 report complete at 2 closed / 0 open since R916
inline int f14IssueTenClosed()
    { return 1; }

// the issue-9 report complete at 1 closed / 0 open since R913
inline int f14IssueNineClosed()
    { return 1; }

// the issue-8 report complete at 1 closed / 0 open since R911
inline int f14IssueEightClosed()
    { return 1; }

// the issue-7 report complete at 1 closed / 0 open since R909
inline int f14IssueSevenClosed()
    { return 1; }

// the issue-6 report complete at 1 closed / 0 open since R907
inline int f14IssueSixClosed()
    { return 1; }

// the registry ground truth re-measured at the R922 battery line - 1313 defs
// loaded - carried forward unchanged, the battery line the only ground truth
inline int f14RegistryLoaded()
    { return 1313; }

// the registry ground truth - 1338 base lua files, carried forward unchanged
// since the R924 re-measure
inline int f14RegistryBaseLua()
    { return 1338; }

// the registry ground truth - 25 long-standing never-load errors (1313 loaded
// + 25 never-load = 1338 base)
inline int f14RegistryNeverLoad()
    { return 25; }

// the Dragon issue-6 walk complete since R907
inline bool f14WalkSixComplete()
    { return true; }

// the Dragon issue-7 walk complete since R909
inline bool f14WalkSevenComplete()
    { return true; }

// the Dragon issue-8 walk complete since R911
inline bool f14WalkEightComplete()
    { return true; }

// the Dragon issue-9 walk complete since R913
inline bool f14WalkNineComplete()
    { return true; }

// the Dragon issue-10 walk complete since R916
inline bool f14WalkTenComplete()
    { return true; }

// the Dragon issue-11 walk complete since R918
inline bool f14WalkElevenComplete()
    { return true; }

// the Dragon issue-12 walk complete since R921
inline bool f14WalkTwelveComplete()
    { return true; }

// the Dragon issue-13 walk complete since R924
inline bool f14WalkThirteenComplete()
    { return true; }

// the Dragon issue-14 walk complete at this flip - the contest winners and
// the lycanthropy variant chains were the engine-relevant ink, the SPACE
// MARINES article, the M-A Variant, the Total Person charts, the reviews, the
// Rust Monster interview, the Monty Haul satire, the editorial, the comics
// and the ads scoped out per the go-ahead adjudication
inline bool f14WalkFourteenComplete()
    { return true; }

}   // namespace rules
