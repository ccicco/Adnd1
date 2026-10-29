// =========================================================================================
// Adnd1 - rules/cpx.h
// The Dragon issue-7 box closing round - the thin walk complete: the pure
// bookkeeping round, the flip and the registry ground truth
// census 831 -> 832.
//
// The pure box-closing round, no new ink: the issue-7 box in
// tools/dragon_gap_report_007.md flips closed (1 / 0), completing the issue-7
// walk exactly as adjudicated at R908 - the Prowler having been the only
// engine-relevant ink in issue #7 (the Gygax origins history, the awards
// ballot, the diceless-play piece, Mystery Hill, the fiction, the Space
// Marines feature, the EPT military formations, the figure painting, the
// comic, the Gnome Cache as ideas-usable, the Editor's Library, the
// editorial, the ads and the mapping registry all scoped out). The
// bookkeeping pins: the single box and its single chain, the issue-6 report
// complete at 1 / 0 since R907, the issue-5 report complete at 1 / 0 since
// R903, and the registry ground truth carried forward (the 1311 live census,
// the 1333 base lua files, the 25 never-load errors - the battery line the
// only ground truth, a pre-R900 print-fidelity state untouched).
//
// The variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the pin IS the conversion, and the R908 judgments (the DMG p.85
// special/exceptional count, the AS-SCANNED zombei spelling, the not-printed
// treasure and size lines) stay noted in the opener round, never silent.
//
namespace rules {

// ---- the walk bookkeeping ----

// the issue-7 gap report carries one box (report 007)
inline int cpxReportBoxes()
    { return 1; }

// the issue-7 opener pinned one chain - the Prowler, the thin single-chain
// harvest (R908)
inline int cpxIssue7Chains()
    { return 1; }

// the issue-6 report has sat complete at 1 closed / 0 open since R907
inline int cpxIssue6Closed()
    { return 1; }

// the issue-5 report has sat complete at 1 closed / 0 open since R903
inline int cpxIssue5Closed()
    { return 1; }

// the issue-5 walk completed at R903
inline bool cpxIssue5WalkComplete()
    { return true; }

// the issue-6 walk completed at R907
inline bool cpxIssue6WalkComplete()
    { return true; }

// the issue-7 walk completes with this round - the Prowler was the only
// engine-relevant ink in issue #7
inline bool cpxIssue7WalkComplete()
    { return true; }

// the variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the conversions noted, never silent
inline bool cpxVariantLayerDoctrine()
    { return true; }

// ---- the registry ground truth ----

// the live registry census floor, carried forward from R900
inline int cpxLiveRegistry()
    { return 1311; }

// the base lua file count the R900 promotion measured against
inline int cpxBaseLuaFiles()
    { return 1333; }

// the base never-load errors - the battery line is the only ground truth
inline int cpxRegistryLoadErrors()
    { return 25; }

}   // namespace rules
