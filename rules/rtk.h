// =========================================================================================
// Adnd1 - rules/rtk.h
// THE TOOLING DATA_FILES ADAPTATION - the rn git add and the rverify
// restore/count, the two-round untracked-defs lesson closed in the tools
// census 716 -> 717.
//
// The tooling round of the data_files extension (the user Go call,
// 2026-10-23). The R792 run left 73 .lua defs untracked and the R793 run
// needed a hand add/commit/push for its 70 - both because rn derives the git
// add list from facts that predate the R791 data_files extension. rn now
// derives NDATA and DFILES from the spec and adds them after the preflight
// gate; rverify now restores the data paths from the base sha and counts them
// in n_patches so its double-run gate proves the emitted files exactly like a
// patch. The engine itself stays untouched. Registry 478 live, unchanged this
// round; the battery census reads loaded 478, errors 0.
//
namespace rules {

// ---- the tooling consts (the R794 data_files adaptation) ----

// The tooling round: rn and rverify learn data_files (the user Go call)
inline int rtkToolRound()
    { return 794; }

// The rn patches: the NDATA/DFILES derivation, the data-file echo, the git
// add block
inline int rtkRnPatchCount()
    { return 3; }

// The rverify patches: the restore-list data paths, the n_patches data term
inline int rtkRverifyPatchCount()
    { return 2; }

// The five tool patches, all gap-flip semantics - no game file touched
inline int rtkToolPatchTotal()
    { return 5; }

// The untracked 73 of R792 - the original lesson: rn predates data_files
inline int rtkR792DataFileCount()
    { return 73; }

// The hand add of R793 - the lesson repeated: the follow-up 2bc7810 was
// manual
inline int rtkR793DataFileCount()
    { return 70; }

// The live registry, unchanged this round - tooling only, no game data
inline int rtkRegistryDefTotal()
    { return 478; }

// The n_patches base: seed, header, include, audit
inline int rtkNPatchesBaseCount()
    { return 4; }

// The new n_patches term: len(data_files), so the double-run gate covers
// emitted files
inline int rtkNPatchesDataTerm()
    { return 1; }

// The audit census after this round: 716 -> 717
inline int rtkCensusAfterRound()
    { return 717; }

// ---- the tooling bools (the R794 data_files adaptation) ----

// rn derives NDATA/DFILES from the spec and git-adds the data files after the
// preflight gate
inline bool rtkRnAddsDataFiles()
    { return true; }

// rverify n_patches gains the data term - the double-run gate covers every
// emitted file
inline bool rtkRverifyCountsDataFiles()
    { return true; }

// The rverify restore list fetches the data paths; absent at the base sha
// removes the local copy
inline bool rtkRverifyRestoresDataFiles()
    { return true; }

// splice_engine.py is NOT patched - the R791 engine-extends-itself lesson
// holds
inline bool rtkEngineStaysUntouched()
    { return true; }

// The tool patches ride the gap-flip semantics: byte-exact from, one replace,
// idempotent by to-presence
inline bool rtkPatchesRideFlipIdempotency()
    { return true; }

// Every tool patch counts in the applied/already census - the double-run
// proves them
inline bool rtkDoubleRunCoversToolPatches()
    { return true; }

// The battery stays loaded 478, errors 0 - no defs, no data files this round
inline bool rtkRegistryCensusUnchanged()
    { return true; }

// The two-round untracked-defs lesson closes in the tools: no hand add after
// a data round again
inline bool rtkUntrackedDataLessonClosed()
    { return true; }

// The git add runs after the engine writes and the preflight gates - the
// landing order is engine, preflight, add, commit, push
inline bool rtkGitAddFollowsTheWrites()
    { return true; }

// The preflight hygiene step still lists leftovers as NOTE - r599_gap.b64,
// fix_r608.py and r597.b64 are NOT this round's
inline bool rtkHygieneStillNotesExtras()
    { return true; }

}   // namespace rules
