    // ---- R794 tooling data files git add audit ----
    // THE TOOLING DATA_FILES ADAPTATION - the R792/R793 untracked-defs lesson
    // closed in the tools (the user Go call on the candidate tooling round).
    // rn learns the data_files facts: NDATA and DFILES derive from the spec
    // beside the file-patch facts, the data-file echo line rides the fact
    // block, and the git add gains the data paths after the preflight gate -
    // no more hand add/commit/push after a data round. rverify learns the
    // data_files too: the restore list fetches the data paths (the 404
    // removal covers the new files at the base sha) and n_patches gains the
    // data term so the double-run gate covers every emitted file.
    // splice_engine.py is NOT patched - the engine-extends-itself lesson of
    // R791 holds: the engine can never consume an extension in the same run
    // that patches it, and here it consumes nothing new. Five tool patches,
    // gap-flip semantics, no game data - the battery stays loaded 478.
    {
        using namespace rules;
        int bad = 0;
    if (rtkToolRound() != 794
            || rtkRnPatchCount() != 3
            || rtkRverifyPatchCount() != 2
            || rtkToolPatchTotal() != 5
            || rtkR792DataFileCount() != 73
            || rtkR793DataFileCount() != 70
            || rtkRegistryDefTotal() != 478
            || rtkNPatchesBaseCount() != 4
            || rtkNPatchesDataTerm() != 1
            || rtkCensusAfterRound() != 717
            || !rtkRnAddsDataFiles()
            || !rtkRverifyCountsDataFiles()
            || !rtkRverifyRestoresDataFiles()
            || !rtkEngineStaysUntouched()
            || !rtkPatchesRideFlipIdempotency()
            || !rtkDoubleRunCoversToolPatches()
            || !rtkRegistryCensusUnchanged()
            || !rtkUntrackedDataLessonClosed()
            || !rtkGitAddFollowsTheWrites()
            || !rtkHygieneStillNotesExtras()
        )
            ++bad;
        // the tooling patch walk (the rn and rverify counts)
    if (rtkToolRound() != 794
            || rtkRnPatchCount() != 3
            || rtkRverifyPatchCount() != 2
            || rtkToolPatchTotal() != 5
            || rtkR792DataFileCount() != 73
            || rtkR793DataFileCount() != 70
            || rtkRegistryDefTotal() != 478
            || rtkNPatchesBaseCount() != 4
            || rtkNPatchesDataTerm() != 1
            || rtkCensusAfterRound() != 717
        )
            ++bad;
        // the tooling doctrine bools
    if (rtkRnAddsDataFiles() != 1
            || rtkRverifyCountsDataFiles() != 1
            || rtkRverifyRestoresDataFiles() != 1
            || rtkEngineStaysUntouched() != 1
            || rtkPatchesRideFlipIdempotency() != 1
            || rtkDoubleRunCoversToolPatches() != 1
            || rtkRegistryCensusUnchanged() != 1
            || rtkUntrackedDataLessonClosed() != 1
            || rtkGitAddFollowsTheWrites() != 1
            || rtkHygieneStillNotesExtras() != 1
        )
            ++bad;
        printf("R794 tooling data files git add audit: bad %d\n", bad);
        if (bad) return 1;
    }
