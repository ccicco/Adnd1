// =========================================================================================
// Adnd1 - rules/dnp.h
// The Dragon issue-9 box closing round - the two-chain walk complete: the
// pure bookkeeping round, the flip and the registry ground truth
// census 835 -> 836.
//
// The pure box-closing round, no new ink: the issue-9 box in
// tools/dragon_gap_report_009.md flips closed (1 / 0), completing the issue-9
// walk exactly as adjudicated at R912 - the Gygax alignment article and the
// Ward Tombs & Crypts article having been the only engine-relevant ink in
// issue #9 (the Finzer Family fiction, the Barker EPT column, the Blume Boot
// Hill ratings, the comics, the ads and the editorial all scoped out). The
// bookkeeping pins: the single box and its two chains, the issue-8 report
// complete at 1 / 0 since R911, the issue-7 report complete at 1 / 0 since
// R909, the issue-6 report complete at 1 / 0 since R907, and the registry
// ground truth carried forward (the 1311 live census, the 1333 base lua
// files, the 25 never-load errors - the battery line the only ground truth, a
// pre-R900 print-fidelity state untouched).
//
// The variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the pin IS the conversion, and the R912 AS-SCANNED quirks (the
// gold-piece x2 row and the garbled 100 row, the garbled guardian tail, the
// modifier grid riding the transcript) stay noted in the opener round, never
// silent.
//
namespace rules {

// ---- the walk bookkeeping ----

// the issue-9 gap report carries one box (report 009)
inline int dnpReportBoxes()
    { return 1; }

// the issue-9 opener pinned two chains - the Gygax alignment article and the
// Ward Tombs & Crypts article (R912)
inline int dnpIssue9Chains()
    { return 2; }

// the issue-8 report has sat complete at 1 closed / 0 open since R911
inline int dnpIssue8Closed()
    { return 1; }

// the issue-7 report has sat complete at 1 closed / 0 open since R909
inline int dnpIssue7Closed()
    { return 1; }

// the issue-6 report has sat complete at 1 closed / 0 open since R907
inline int dnpIssue6Closed()
    { return 1; }

// the issue-6 walk completed at R907
inline bool dnpIssue6WalkComplete()
    { return true; }

// the issue-7 walk completed at R909
inline bool dnpIssue7WalkComplete()
    { return true; }

// the issue-8 walk completed at R911
inline bool dnpIssue8WalkComplete()
    { return true; }

// the issue-9 walk completes with this round - the Gygax alignment and Ward
// tomb chains were the only engine-relevant ink in issue #9
inline bool dnpIssue9WalkComplete()
    { return true; }

// the variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the conversions noted, never silent
inline bool dnpVariantLayerDoctrine()
    { return true; }

// ---- the registry ground truth ----

// the live registry census floor, carried forward from R900
inline int dnpLiveRegistry()
    { return 1311; }

// the base lua file count the R900 promotion measured against
inline int dnpBaseLuaFiles()
    { return 1333; }

// the base never-load errors - the battery line is the only ground truth
inline int dnpRegistryLoadErrors()
    { return 25; }

}   // namespace rules
