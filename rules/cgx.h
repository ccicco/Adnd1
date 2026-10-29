// =========================================================================================
// Adnd1 - rules/cgx.h
// The Dragon issue-8 box closing round - the three-chain walk complete: the
// pure bookkeeping round, the flip and the registry ground truth
// census 833 -> 834.
//
// The pure box-closing round, no new ink: the issue-8 box in
// tools/dragon_gap_report_008.md flips closed (1 / 0), completing the issue-8
// walk exactly as adjudicated at R910 - the Gygax Planes article, the Watson
// towns article and the Kuntz gems re-evaluation having been the only
// engine-relevant ink in issue #8 (the Finzer Family fiction, the Gamma World
// preview, the Featured Creature contest, the MA chains, the figure reviews,
// the editorial, the ads and the Fenn Manor ad all scoped out). The
// bookkeeping pins: the single box and its three chains, the issue-7 report
// complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0 since
// R907, and the registry ground truth carried forward (the 1311 live census,
// the 1333 base lua files, the 25 never-load errors - the battery line the
// only ground truth, a pre-R900 print-fidelity state untouched).
//
// The variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the pin IS the conversion, and the R910 AS-SCANNED garbles (the
// swapped worked-example labels, the starred carat rows, the Table C lists
// riding the transcript) stay noted in the opener round, never silent.
//
namespace rules {

// ---- the walk bookkeeping ----

// the issue-8 gap report carries one box (report 008)
inline int cgxReportBoxes()
    { return 1; }

// the issue-8 opener pinned three chains - the Gygax Planes article, the
// Watson towns article, the Kuntz gems re-evaluation (R910)
inline int cgxIssue8Chains()
    { return 3; }

// the issue-7 report has sat complete at 1 closed / 0 open since R909
inline int cgxIssue7Closed()
    { return 1; }

// the issue-6 report has sat complete at 1 closed / 0 open since R907
inline int cgxIssue6Closed()
    { return 1; }

// the issue-6 walk completed at R907
inline bool cgxIssue6WalkComplete()
    { return true; }

// the issue-7 walk completed at R909
inline bool cgxIssue7WalkComplete()
    { return true; }

// the issue-8 walk completes with this round - the Planes, towns and gems
// chains were the only engine-relevant ink in issue #8
inline bool cgxIssue8WalkComplete()
    { return true; }

// the variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the conversions noted, never silent
inline bool cgxVariantLayerDoctrine()
    { return true; }

// ---- the registry ground truth ----

// the live registry census floor, carried forward from R900
inline int cgxLiveRegistry()
    { return 1311; }

// the base lua file count the R900 promotion measured against
inline int cgxBaseLuaFiles()
    { return 1333; }

// the base never-load errors - the battery line is the only ground truth
inline int cgxRegistryLoadErrors()
    { return 25; }

}   // namespace rules
