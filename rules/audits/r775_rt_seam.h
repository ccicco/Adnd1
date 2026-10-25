    // ---- R775 RT seam audit ----
    // THE SECOND TOOLING ROUND - designing the mount site (the R403 charge
    // flips ride regtest.cpp file patches) exposed the clobber class in the
    // R774 seam: the (f) section read its target from disk, but regtest is
    // ALSO engine-patched in memory with the writes deferred - a regtest file
    // patch would read the pristine copy and the last RT write would lose the
    // include and the audit. The fix rides this round as a file patch ON
    // tools/splice_engine.py itself: RT file patches now read the in-memory
    // text. This round proves the bootstrap loop closed - a tool file lands
    // through the ritual, no hand-save: the running old engine safely patches
    // a file it does not also splice, and the second run executes the new
    // engine.
    {
        using namespace rules;
        int bad = 0;
    if (dnbSelfPatchedToolRound() != 775
            || dnbMountSiteRound() != 776
            || !dnbRegtestPatchesRideInMemory()
            || !dnbClobberClassDead()
            || !dnbToolsLandThroughTheRitual()
        )
            ++bad;
        printf("R775 RT seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
