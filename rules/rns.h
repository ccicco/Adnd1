// =========================================================================================
// Adnd1 - rules/rns.h
// THE RN SELF-PATCH GUARD - the snapshot exec, the R794 self-patching runner
// lesson closed structurally
// census 717 -> 718.
//
// The hardening round of the runner (the user Go call, 2026-10-23, on the
// R795 candidates after the next-arc audit found every book arc closed). R794
// proved bash reads a script incrementally: the engine rewrote rn mid-run,
// the byte offsets shifted, and the landing crashed at line 48 after the
// all-or-nothing applied 9 - the recovery was the plain re-run, and the
// lesson said rn can never be a file-patch target of its own run. This round
// removes the NEVER by making the executing copy immutable: rn execs a
// private snapshot of itself at the top (one env var, one cp, one exec),
// removes the snapshot on every exit path (the trap), and otherwise changes
// nothing. Registry 478 live, unchanged; the battery census reads loaded 478,
// errors 0.
//
namespace rules {

// ---- the guard consts (the R795 self-patch hardening) ----

// The self-patch hardening round: the snapshot exec (the user Go call)
inline int rnsGuardRound()
    { return 795; }

// One patch on rn: the guard block after set -eu
inline int rnsToolPatchCount()
    { return 1; }

// The R794 crash came after the all-or-nothing applied 9 - the recovery was
// the plain re-run
inline int rnsR794AppliedBeforeCrash()
    { return 9; }

// The R794 recovery re-run read applied 0, already 9 - the engine idempotency
// carried the round
inline int rnsR794ReRunApplied()
    { return 0; }

// Exactly one exec per landing - the RN_SNAPSHOT gate prevents any loop
inline int rnsGuardExecCount()
    { return 1; }

// RN_SNAPSHOT is gate and path in one: set means the snapshot is running, the
// value is its path
inline int rnsGuardEnvVarCount()
    { return 1; }

// The live registry, unchanged this round - tooling only, no game data
inline int rnsRegistryDefTotal()
    { return 478; }

// The audit census after this round: 717 -> 718
inline int rnsCensusAfterRound()
    { return 718; }

// ---- the guard bools (the R795 self-patch hardening) ----

// rn always execs a private snapshot copy of itself; the executing read is
// immutable for the run
inline bool rnsRunsFromSnapshot()
    { return true; }

// An engine file patch on rn itself can never desync the executing read - the
// R794 class dies
inline bool rnsSelfPatchSafe()
    { return true; }

// The trap removes the snapshot on every exit path, abort included
inline bool rnsSnapshotRemovedAtExit()
    { return true; }

// A data_files round keeps its one-pass git add: the snapshot is a copy of
// the CURRENT rn, the R794 DFILES handling rides along
inline bool rnsDataRoundsStillOnePass()
    { return true; }

// The git add still lands the patched disk copy when rn patches itself
// mid-run
inline bool rnsGitAddLandsDiskCopy()
    { return true; }

// The double-run and the mixed-state abort stay exactly as they are - the
// guard adds nothing to the engine contract
inline bool rnsEngineIdempotencyUnchanged()
    { return true; }

// The battery stays loaded 478, errors 0 - no defs, no data files this round
inline bool rnsRegistryCensusUnchanged()
    { return true; }

// splice_engine.py and rverify.py are not patched - only the runner hardens
inline bool rnsEngineAndRverifyUntouched()
    { return true; }

}   // namespace rules
