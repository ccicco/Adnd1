// =========================================================================================
// Adnd1 - rules/cwx.h
// The Dragon issue-5 box closing round - the three-chain walk complete: the
// pure bookkeeping round, the flip and the registry ground truth
// census 825 -> 826.
//
// The pure box-closing round, no new ink: the issue-5 box in
// tools/dragon_gap_report_005.md flips closed (1 / 0), completing the issue-5
// walk exactly as adjudicated at R902 - the Witchcraft Supplement variant
// layer, the Anhkheg lore-against-def pin and the Wizard Research Rules
// having been the only engine-relevant ink in issue #5 (the Metamorphosis
// Alpha chains, the fiction, the Tolkien lore chain, the Gandalf analysis,
// the letters, the ads and the preview all scoped out). The bookkeeping pins:
// the single box and its three chains, the issue-4 report already complete at
// 1 / 0, and the registry ground truth carried forward (the 1311 live census,
// the 1333 base lua files, the 25 never-load errors - the battery line the
// only ground truth).
//
// The pure flip round: no new print ink, no file patches, no data files -
// only the box closing, the walk bookkeeping consts and the variant-layer
// doctrine riding the closure. A report cannot flip in the round that creates
// it; the R902 opener shipped report 005 pre-flip, and this round is the flip
// the pre-flip rule promised. The registry ground truth stays pinned as
// consts so the closure carries the same live-census discipline as the rounds
// that created it.
//
namespace rules {

// ---- the walk bookkeeping ----

// the issue-5 report carries a single box - the three-chain opener at folios
// 4-9, 12+28, 24-26+28 (tools/dragon_gap_report_005.md); this round flips it
// closed, 1 closed / 0 open, the walk complete
inline int cwxReportBoxes()
    { return 1; }

// the three adjudicated chains riding the box - the Witchcraft Supplement
// (the variant layer), the Anhkheg (the lore-against-def pin vs the merged
// MM1 ankheg def) and the Wizard Research Rules (folios 4-9, 12+28, 24-26+28)
inline int cwxIssue5Chains()
    { return 3; }

// the issue-4 report sits complete at 1 closed / 0 open since the R901 flip
// (tools/dragon_gap_report_004.md)
inline int cwxIssue4Closed()
    { return 1; }

// the issue-4 walk is complete - 1 closed / 0 open since R901
// (tools/dragon_gap_report_004.md)
inline bool cwxIssue4WalkComplete()
    { return true; }

// the issue-5 walk is complete at this round's flip - the three-chain box
// closed, 1 / 0 (tools/dragon_gap_report_005.md)
inline bool cwxIssue5WalkComplete()
    { return true; }

// the variant-layer doctrine rides the closure - Dragon ink is never core 1e
// canon; the Witchcraft Supplement and the Wizard Research Rules pin as
// variant layers, the Anhkheg as lore-against-def provenance, never a
// competing def
inline bool cwxVariantLayerDoctrine()
    { return true; }

// ---- the registry ground truth ----

// the live registry ground truth - 1308 loaded base defs + the three R900
// promotions = 1311; the battery line loaded N, errors M is the only ground
// truth for registry floors (the R900 lesson, pinned as cfc consts at R901)
inline int cwxLiveRegistry()
    { return 1311; }

// the base lua file count - 1333 files against the 1311 live census, the
// difference the 25 long-broken MM2/FF text lines that never load
inline int cwxBaseLuaFiles()
    { return 1333; }

// the 25 long-standing load-error defs, a pre-R900 print-fidelity state
// untouched
inline int cwxRegistryLoadErrors()
    { return 25; }

}   // namespace rules
