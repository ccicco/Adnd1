// =========================================================================================
// Adnd1 - rules/cfc.h
// The Creature Features box closing round - the issue-4 walk complete: the
// pure bookkeeping round, the flip and the registry ground truth
// census 823 -> 824.
//
// The pure box-closing round, no new ink: the Creature Features box in
// tools/dragon_gap_report_004.md flips closed (1 / 0), completing the issue-4
// walk exactly as adjudicated at R900 - the Creature Features chain was the
// only engine-relevant chain in The Dragon Vol. 1 No. 4 (December 1976);
// everything else was scoped out (the EPT campaign chains, the Metamorphosis
// Alpha androids, the Jaquet Oddball parody, the fiction, Finieous Fingers,
// Wargaming World, the Temple pictorial, Mapping the Dungeons, the ads and
// the preview). The R900 record seats in the seed this round.
//
// The pure-round doctrine: a closing round carries no new print ink - only
// the flip and the walk bookkeeping, every number cited to its standing
// record; the registry ground truth pins as the R900 lesson taught: 1311
// loaded live against 1333 files with 25 never-load errors, the battery line
// 'loaded N, errors M' the only ground truth for registry floors, never the
// file count; the 25 broken MM2/FF text lines stay untouched, a pre-R900
// print-fidelity state; the variant-layer doctrine holds at the closure -
// Dragon ink is never core 1e canon.
//
namespace rules {

// ---- the walk bookkeeping ----

// the issue-4 report carries a single box - the Creature Features chain at
// folios 18-19, 21 (tools/dragon_gap_report_004.md); this round flips it
// closed, 1 closed / 0 open, the walk complete
inline int cfcReportBoxes()
    { return 1; }

// the three Creature Features lua defs riding the box - the Mihalli, the
// Vriyagga and the Qu'uni, promoted at R900 (folios 18-19, 21)
inline int cfcCreatureFeaturesDefs()
    { return 3; }

// the issue-3 report closed 5 / 0 at the R900 flip - the adjudicated issue-3
// walk complete (tools/dragon_gap_report_003.md)
inline int cfcIssue3Closed()
    { return 5; }

// the issue-3 walk is complete - 5 boxes closed / 0 open at the R900 flip
// (tools/dragon_gap_report_003.md)
inline bool cfcIssue3WalkComplete()
    { return true; }

// the issue-4 walk is complete at this round's flip - the Creature Features
// box closed, 1 / 0 (tools/dragon_gap_report_004.md)
inline bool cfcIssue4WalkComplete()
    { return true; }

// the standing doctrine rides the closure: the pin IS the conversion, Dragon
// ink rides a VARIANT layer with provenance, never core 1e canon (the report
// 004 doctrine line)
inline bool cfcVariantLayerDoctrine()
    { return true; }

// ---- the registry ground truth ----

// the live lua def census the Termux battery prints - 'loaded 1311, errors
// 25' is the ground truth after the three promotions (the R900 lesson:
// registry floors pin to the battery line, never to the file count)
inline int cfcLiveRegistry()
    { return 1311; }

// the base lua FILE count under monsters/monsters/ - never the loaded count;
// 25 files never enter the registry (the R900 lesson)
inline int cfcBaseLuaFiles()
    { return 1333; }

// the long-broken base defs that never load - unfinished-string lua errors at
// their text lines, a pre-R900 print-fidelity state this round does not touch
inline int cfcRegistryLoadErrors()
    { return 25; }

// the 25 load errors pre-date R900 entirely - MM2/FF-era text lines,
// untouched by the walk rounds and left as-is per the print-fidelity doctrine
inline bool cfcPreR900LoadErrorState()
    { return true; }

}   // namespace rules
