// =========================================================================================
// Adnd1 - rules/icl.h
// The Dragon issue-13 box closing round - the three-chain walk complete, the
// pure flip
// census 846 -> 847.
//
// Bookkeeping only, no new ink pinned. The issue-13 walk (R922 opener part
// one, R923 opener part two, this flip) covered The Dragon Vol. II No. 7
// (April 1978), the archive.org scan voice, single-voice - no chat-side
// upload cross-check exists for issue 13; the source lives in the archive.org
// item accessory-dragon-magazine-012, which holds issues 7-14. The
// transcripts ride extract/dragon/013/p001 through p032, landed at R922.
//
// The R922 and R923 sentinel pins ride unchanged - the giant grid pounds and
// torso vision-resolved ladders, the quarter-ton tons and tenths materials
// conversions, the demon power grid, the sixteen see-below magic cells, the
// Aizen-Myoo and Light/Shade bar-garble armor classes, the seven hero
// strength fraction garbles and the two Sth-noted fighter cells all ride the
// -1 sentinel as-scanned, never silent. The registry ground truth re-measured
// at the R922 battery: 1313 loaded / 1338 base / 25 never-load, superseding
// the R900-era snapshot, the growth noted.
//
namespace rules {

// ---- the issue-13 walk bookkeeping ----

// the issue-13 gap report carries two boxes (report 013)
inline int iclIssueThirteenBoxes()
    { return 2; }

// the issue-13 walk pinned three chains - the Shlump da Orc giant physics
// article, the Jon Pickens demon generation article and the Arkenberg
// Japanese Mythos
inline int iclIssueThirteenChains()
    { return 3; }

// the issue-13 walk ran three rounds - the R922 opener part one, the R923
// opener part two and this R924 flip
inline int iclIssueThirteenRounds()
    { return 3; }

// the issue-12 report complete at 2 closed / 0 open since R921
inline int iclIssueTwelveClosed()
    { return 1; }

// the issue-11 report complete at 1 closed / 0 open since R918
inline int iclIssueElevenClosed()
    { return 1; }

// the issue-10 report complete at 2 closed / 0 open since R916
inline int iclIssueTenClosed()
    { return 1; }

// the issue-9 report complete at 1 closed / 0 open since R913
inline int iclIssueNineClosed()
    { return 1; }

// the issue-8 report complete at 1 closed / 0 open since R911
inline int iclIssueEightClosed()
    { return 1; }

// the issue-7 report complete at 1 closed / 0 open since R909
inline int iclIssueSevenClosed()
    { return 1; }

// the issue-6 report complete at 1 closed / 0 open since R907
inline int iclIssueSixClosed()
    { return 1; }

// the registry ground truth re-measured at the R922 battery line - 1313 defs
// loaded, the battery line the only ground truth, superseding the R900-era
// 1308-loaded snapshot the R921 closer carried forward
inline int iclRegistryLoaded()
    { return 1313; }

// the registry ground truth - 1338 base lua files at the R922 battery, five
// more than the R900-era 1333 snapshot, the growth noted never silent
inline int iclRegistryBaseLua()
    { return 1338; }

// the registry ground truth - 25 long-standing never-load errors, unchanged
// since the R900 snapshot (1313 loaded + 25 never-load = 1338 base)
inline int iclRegistryNeverLoad()
    { return 25; }

// the Dragon issue-6 walk complete since R907
inline bool iclWalkSixComplete()
    { return true; }

// the Dragon issue-7 walk complete since R909
inline bool iclWalkSevenComplete()
    { return true; }

// the Dragon issue-8 walk complete since R911
inline bool iclWalkEightComplete()
    { return true; }

// the Dragon issue-9 walk complete since R913
inline bool iclWalkNineComplete()
    { return true; }

// the Dragon issue-10 walk complete since R916
inline bool iclWalkTenComplete()
    { return true; }

// the Dragon issue-11 walk complete since R918
inline bool iclWalkElevenComplete()
    { return true; }

// the Dragon issue-12 walk complete since R921
inline bool iclWalkTwelveComplete()
    { return true; }

// the Dragon issue-13 walk complete at this flip - the giant physics, demon
// generation and Japanese Mythos chains were the engine-relevant ink, the
// Tolkien Scroll, Bionic Supplement, WARLORD, songs, fiction, comics, contest
// rules and Notes column scoped out per the ALL-USABLE adjudication
inline bool iclWalkThirteenComplete()
    { return true; }

}   // namespace rules
