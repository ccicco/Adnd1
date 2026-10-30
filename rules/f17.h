// =========================================================================================
// Adnd1 - rules/f17.h
// The Dragon issue-17 box closing round - the eight-chain walk complete, the
// pure flip
// census 855 -> 856.
//
// Bookkeeping only, no new ink pinned. The issue-17 walk (the R931 opener
// part one carrying the seven chains, the R932 opener part two carrying the
// Ward wizard article, this flip) covered The Dragon Vol. III No. 3 (August
// 1978), the Curtiss-provided scan voice, single-voice - the mistral
// transcript of the uploaded Dm17.pdf; no archive.org djvu cross-check exists
// for issue 17. Print folio = PDF page minus two, verified at the R931 page
// feet. Registry ground truth unchanged: 1313 loaded / 1338 base lua / 25
// never-load (the R924 re-measure). Watch: the brawling long-term-effects
// sequel STILL does not print (watch TD 18).
//
// No print quirks ride this flip - the as-scanned garbles of the openers (the
// vampire 8:69 strength print, the Crs-tchen EPT-style descending armor class
// conversion, the Mercy AC minus 1 sharing the sentinel value, the Ward
// article spell-list garbles Dispel! Magic, Pall-wall, Extention,
// Telekenisis, Ventriliquism, Animate Deat, the
// Etherfulness/Etherialness/Etheriainess spread, Replusion Field, the
// twice-printed End All Barriers, the Movement fifth-level row that never
// prints and the unlabeled Control overflow row) pin sentinel or as-scanned
// in the R931 and R932 layers and ride the transcript and the wizard-roster
// data file, noted never silent; this round flips the two report boxes and
// touches no ink.
//
namespace rules {

// ---- the issue-17 walk bookkeeping ----

// the issue-17 gap report carries two boxes, both closed at this flip (report
// 017)
inline int f17IssueSeventeenBoxes()
    { return 2; }

// the issue-17 walk pinned eight chains: the seven part-one chains of R931
// plus the Ward wizard article of R932
inline int f17IssueSeventeenChains()
    { return 8; }

// the issue-17 walk completes in three rounds: the R931 opener part one, the
// R932 opener part two and this flip
inline int f17IssueSeventeenRounds()
    { return 3; }

// the issue-16 report closed at R930 (the f16 flip)
inline int f17IssueSixteenClosed()
    { return 1; }

// the issue-15 report closed at R927 (the f15 flip)
inline int f17IssueFifteenClosed()
    { return 1; }

// the issue-14 report closed at R926 (the f14 flip)
inline int f17IssueFourteenClosed()
    { return 1; }

// the issue-13 report closed at R924 (the f13 flip)
inline int f17IssueThirteenClosed()
    { return 1; }

// the issue-12 report closed at R922 (the f12 flip)
inline int f17IssueTwelveClosed()
    { return 1; }

// the issue-11 report closed at R920 (the f11 flip)
inline int f17IssueElevenClosed()
    { return 1; }

// the issue-10 report closed at R918 (the f10 flip)
inline int f17IssueTenClosed()
    { return 1; }

// the issue-9 report closed at R916 (the f9 flip)
inline int f17IssueNineClosed()
    { return 1; }

// the issue-8 report closed at R913 (the f8 flip)
inline int f17IssueEightClosed()
    { return 1; }

// the issue-7 report closed at R911 (the f7 flip)
inline int f17IssueSevenClosed()
    { return 1; }

// the issue-6 report closed at R909 (the f6 flip)
inline int f17IssueSixClosed()
    { return 1; }

// the registry ground truth unchanged: 1313 loaded defs (the R924 re-measure)
inline int f17RegistryLoaded()
    { return 1313; }

// the registry base lua count unchanged: 1338 (the R924 re-measure)
inline int f17RegistryBaseLua()
    { return 1338; }

// the registry never-load count unchanged: 25 (the R924 re-measure)
inline int f17RegistryNeverLoad()
    { return 25; }

// the issue-6 walk complete (R909 flip)
inline bool f17WalkSixComplete()
    { return true; }

// the issue-7 walk complete (R911 flip)
inline bool f17WalkSevenComplete()
    { return true; }

// the issue-8 walk complete (R913 flip)
inline bool f17WalkEightComplete()
    { return true; }

// the issue-9 walk complete (R916 flip)
inline bool f17WalkNineComplete()
    { return true; }

// the issue-10 walk complete (R918 flip)
inline bool f17WalkTenComplete()
    { return true; }

// the issue-11 walk complete (R920 flip)
inline bool f17WalkElevenComplete()
    { return true; }

// the issue-12 walk complete (R922 flip)
inline bool f17WalkTwelveComplete()
    { return true; }

// the issue-13 walk complete (R924 flip)
inline bool f17WalkThirteenComplete()
    { return true; }

// the issue-14 walk complete (R926 flip)
inline bool f17WalkFourteenComplete()
    { return true; }

// the issue-15 walk complete (R927 flip)
inline bool f17WalkFifteenComplete()
    { return true; }

// the issue-16 walk complete (R930 flip)
inline bool f17WalkSixteenComplete()
    { return true; }

// the issue-17 walk complete (this flip, R931 + R932 + R933)
inline bool f17WalkSeventeenComplete()
    { return true; }

}   // namespace rules
