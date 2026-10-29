// =========================================================================================
// Adnd1 - rules/bfx.h
// The Dragon issue-11 box closing round - the two-chain walk complete, the
// pure flip
// census 840 -> 841.
//
// Bookkeeping only, no new ink pinned. The issue-11 walk (R917 opener, this
// flip) covered The Dragon Vol. II No. 5 (December 1977), the archive.org
// scan voice, single-voice - no chat-side upload cross-check exists for issue
// 11; the source lives in the archive.org item accessory-dragon-magazine-012.
//
// The brawling punch-grid sentinel cell and the quarterstaff worked-example
// discrepancy were pinned at R917 and ride unchanged - this round touches no
// ink.
//
namespace rules {

// ---- the issue-11 walk bookkeeping ----

// the issue-11 gap report carries a single box (report 011)
inline int bfxIssueElevenBoxes()
    { return 1; }

// the issue-11 walk pinned two chains - the Kuntz brawling article and the
// Ward quarterstaff article
inline int bfxIssueElevenChains()
    { return 2; }

// the issue-10 report complete at 2 closed / 0 open since R916
inline int bfxIssueTenClosed()
    { return 1; }

// the issue-9 report complete at 1 closed / 0 open since R913
inline int bfxIssueNineClosed()
    { return 1; }

// the issue-8 report complete at 1 closed / 0 open since R911
inline int bfxIssueEightClosed()
    { return 1; }

// the issue-7 report complete at 1 closed / 0 open since R909
inline int bfxIssueSevenClosed()
    { return 1; }

// the issue-6 report complete at 1 closed / 0 open since R907
inline int bfxIssueSixClosed()
    { return 1; }

// the Dragon issue-6 walk complete since R907
inline bool bfxWalkSixComplete()
    { return true; }

// the Dragon issue-7 walk complete since R909
inline bool bfxWalkSevenComplete()
    { return true; }

// the Dragon issue-8 walk complete since R911
inline bool bfxWalkEightComplete()
    { return true; }

// the Dragon issue-9 walk complete since R913
inline bool bfxWalkNineComplete()
    { return true; }

// the Dragon issue-10 walk complete since R916
inline bool bfxWalkTenComplete()
    { return true; }

// the Dragon issue-11 walk complete at this flip - the brawling and
// quarterstaff chains were the only engine-relevant ink
inline bool bfxWalkElevenComplete()
    { return true; }

// ---- the registry ground truth ----

// the registry ground truth - live lua files, the battery line the only
// ground truth
inline int bfxRegistryLive()
    { return 1311; }

// the registry ground truth - base lua files
inline int bfxRegistryBaseLua()
    { return 1333; }

// the registry ground truth - never-load errors
inline int bfxRegistryNeverLoad()
    { return 25; }

// Dragon pins ride a VARIANT layer with provenance, never core canon
inline bool bfxVariantLayerDoctrine()
    { return true; }

}   // namespace rules
