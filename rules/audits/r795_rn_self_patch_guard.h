    // ---- R795 rn self-patch guard audit ----
    // THE RN SELF-PATCH GUARD - the R794 self-patching runner lesson closed
    // structurally (the user Go call on the hardening candidate). A plain
    // re-exec-on-md5-change check still carries the same hole it fixes: bash
    // reads scripts incrementally, and the R794 crash proved the read desyncs
    // BEFORE any mid-script check can run - so the guard goes to the very
    // top: rn always execs a private snapshot copy of itself, the executing
    // read becomes immutable for the run, and the disk rn is free to change
    // mid-run. An engine file patch on rn itself can never desync a landing
    // again; the git add still lands the patched disk copy; a data_files
    // round keeps its one-pass git add because the snapshot is a copy of the
    // CURRENT rn (the R794 DFILES handling rides along). The RN_SNAPSHOT env
    // var is gate and path in one - at most one exec per landing, no loop.
    // splice_engine.py and rverify.py are untouched; the engine double-run
    // and the mixed-state abort stay exactly as they are.
    {
        using namespace rules;
        int bad = 0;
    if (rnsGuardRound() != 795
            || rnsToolPatchCount() != 1
            || rnsR794AppliedBeforeCrash() != 9
            || rnsR794ReRunApplied() != 0
            || rnsGuardExecCount() != 1
            || rnsGuardEnvVarCount() != 1
            || rnsRegistryDefTotal() != 478
            || rnsCensusAfterRound() != 718
            || !rnsRunsFromSnapshot()
            || !rnsSelfPatchSafe()
            || !rnsSnapshotRemovedAtExit()
            || !rnsDataRoundsStillOnePass()
            || !rnsGitAddLandsDiskCopy()
            || !rnsEngineIdempotencyUnchanged()
            || !rnsRegistryCensusUnchanged()
            || !rnsEngineAndRverifyUntouched()
        )
            ++bad;
        // the guard walk (the R794 lesson counts)
    if (rnsGuardRound() != 795
            || rnsToolPatchCount() != 1
            || rnsR794AppliedBeforeCrash() != 9
            || rnsR794ReRunApplied() != 0
            || rnsGuardExecCount() != 1
            || rnsGuardEnvVarCount() != 1
            || rnsRegistryDefTotal() != 478
            || rnsCensusAfterRound() != 718
        )
            ++bad;
        // the guard doctrine bools
    if (rnsRunsFromSnapshot() != 1
            || rnsSelfPatchSafe() != 1
            || rnsSnapshotRemovedAtExit() != 1
            || rnsDataRoundsStillOnePass() != 1
            || rnsGitAddLandsDiskCopy() != 1
            || rnsEngineIdempotencyUnchanged() != 1
            || rnsRegistryCensusUnchanged() != 1
            || rnsEngineAndRverifyUntouched() != 1
        )
            ++bad;
        printf("R795 rn self-patch guard audit: bad %d\n", bad);
        if (bad) return 1;
    }
