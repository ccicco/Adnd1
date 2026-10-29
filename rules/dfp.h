// =========================================================================================
// Adnd1 - rules/dfp.h
// The Dragon issue-10 box closing round - the six-chain walk complete: the
// pure bookkeeping round, the flip and the registry ground truth
// census 838 -> 839.
//
// The pure box-closing round, no new ink: the issue-10 part-two box in
// tools/dragon_gap_report_010.md flips closed (2 / 0), completing the
// issue-10 walk exactly as adjudicated at R914 and R915 - the Orgies Inc.
// article, the Clifton wilderness article, the Random Monsters article, the
// Gilbert dungeon method article, the Weights & Measures article and the
// Holsinger level ritual article having been the only engine-relevant ink in
// issue #10 (the editorial, the GenCon X report, the Snits game, the Stellar
// Conquest diplomacy article, the poem, the comics and the ads all scoped
// out). The bookkeeping pins: the two boxes and their six chains across the
// two opener rounds, the issue-9 report complete at 1 / 0 since R913, the
// issue-8 report complete at 1 / 0 since R911, the issue-7 report complete at
// 1 / 0 since R909, the issue-6 report complete at 1 / 0 since R907, and the
// registry ground truth carried forward (the 1311 live census, the 1333 base
// lua files, the 25 never-load errors - the battery line the only ground
// truth, a pre-R900 print-fidelity state untouched).
//
// The variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the pin IS the conversion, and the R914 and R915 AS-SCANNED quirks
// (the Random Monsters garbles, the Clifton band arithmetic, the Weights &
// Measures sentinel cells and the 185 medium cell, the speed-12 fraction)
// stay noted in the opener rounds, never silent.
//
namespace rules {

// ---- the walk bookkeeping ----

// the issue-10 gap report carries two boxes, one per opener round (report
// 010)
inline int dfpReportBoxes()
    { return 2; }

// the issue-10 walk pinned six chains across two rounds - the Orgies Inc.,
// Clifton wilderness, Random Monsters, Gilbert dungeon method, Weights &
// Measures and Holsinger level ritual articles (R914, R915)
inline int dfpIssue10Chains()
    { return 6; }

// the issue-9 report has sat complete at 1 closed / 0 open since R913
inline int dfpIssue9Closed()
    { return 1; }

// the issue-8 report has sat complete at 1 closed / 0 open since R911
inline int dfpIssue8Closed()
    { return 1; }

// the issue-7 report has sat complete at 1 closed / 0 open since R909
inline int dfpIssue7Closed()
    { return 1; }

// the issue-6 report has sat complete at 1 closed / 0 open since R907
inline int dfpIssue6Closed()
    { return 1; }

// the issue-6 walk completed at R907
inline bool dfpIssue6WalkComplete()
    { return true; }

// the issue-7 walk completed at R909
inline bool dfpIssue7WalkComplete()
    { return true; }

// the issue-8 walk completed at R911
inline bool dfpIssue8WalkComplete()
    { return true; }

// the issue-9 walk completed at R913
inline bool dfpIssue9WalkComplete()
    { return true; }

// the issue-10 walk completes with this round - the six chains across two
// opener rounds were the only engine-relevant ink in issue #10
inline bool dfpIssue10WalkComplete()
    { return true; }

// the variant-layer doctrine rides the closure: Dragon ink is never core 1e
// canon, the conversions noted, never silent
inline bool dfpVariantLayerDoctrine()
    { return true; }

// ---- the registry ground truth ----

// the live registry census floor, carried forward from R900
inline int dfpLiveRegistry()
    { return 1311; }

// the base lua file count the R900 promotion measured against
inline int dfpBaseLuaFiles()
    { return 1333; }

// the base never-load errors - the battery line is the only ground truth
inline int dfpRegistryLoadErrors()
    { return 25; }

}   // namespace rules
