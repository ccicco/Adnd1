// =========================================================================================
// Adnd1 - rules/csx.h
// The Dragon issue-6 box closing round - the four-chain walk complete: the
// pure bookkeeping round, the flip and the registry ground truth
// census 829 -> 830.
//
// The pure box-closing round, no new ink: the issue-6 box in
// tools/dragon_gap_report_006.md flips closed (1 / 0), completing the issue-6
// walk exactly as adjudicated at R906 - the Sea Trade system, the psionic
// determination option, the morale system and the Death Angel having been the
// only engine-relevant ink in issue #6 (the Metamorphosis Alpha chains, the
// EPT painting guide, the fiction, the Gnome Cache as ideas-usable, the
// comic, the editorial, the ads, the convention schedule and the preview all
// scoped out). The bookkeeping pins: the single box and its four chains, the
// issue-5 report complete at 1 / 0 since R903, the issue-4 report complete at
// 1 / 0 since R901, and the registry ground truth carried forward (the 1311
// live census, the 1333 base lua files, the 25 never-load errors - the
// battery line the only ground truth, a pre-R900 print-fidelity state
// untouched).
//
// The variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the pin IS the conversion, and the R906 print quirks (the
// profit/loss grid's AS-SCANNED 10 cell, the worked-example discrepancy, the
// folio-25 15-tenths read) stay noted in the opener round, never silent.
//
namespace rules {

// ---- the walk bookkeeping ----

// the issue-6 gap report carries one box (report 006)
inline int csxReportBoxes()
    { return 1; }

// the issue-6 opener pinned four chains - the Sea Trade system, the psionic
// option, the morale system, the Death Angel (R906)
inline int csxIssue6Chains()
    { return 4; }

// the issue-5 report has sat complete at 1 closed / 0 open since R903
inline int csxIssue5Closed()
    { return 1; }

// the issue-4 report has sat complete at 1 closed / 0 open since R901
inline int csxIssue4Closed()
    { return 1; }

// the issue-4 walk completed at R901
inline bool csxIssue4WalkComplete()
    { return true; }

// the issue-5 walk completed at R903
inline bool csxIssue5WalkComplete()
    { return true; }

// the issue-6 walk completes with this round - the four-chain opener was the
// only engine-relevant ink in issue #6
inline bool csxIssue6WalkComplete()
    { return true; }

// the variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the conversions noted, never silent
inline bool csxVariantLayerDoctrine()
    { return true; }

// ---- the registry ground truth ----

// the live registry census floor, carried forward from R900
inline int csxLiveRegistry()
    { return 1311; }

// the base lua file count the R900 promotion measured against
inline int csxBaseLuaFiles()
    { return 1333; }

// the base never-load errors - the battery line is the only ground truth
inline int csxRegistryLoadErrors()
    { return 25; }

}   // namespace rules
