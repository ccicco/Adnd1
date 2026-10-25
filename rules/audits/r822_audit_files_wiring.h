    // ---- R822 audit files wiring audit ----
    // THE AUDIT FILES DECOMPOSITION WIRING - the tooling round of the regtest
    // decomposition (the monolith: 5,717,896 bytes at the 951b962 base sha,
    // 744 audit blocks in one TU). THE MECHANISM: a spec that declares
    // audit_file writes its engine-emitted audit block to a NEW fragment
    // under rules/audits/ and regtest gets the one-line #include at the R227
    // anchor, inside the battery function body - the preprocessor unrolls it,
    // the binary is unchanged, an error names its fragment. THE COUPLINGS all
    // ride along: the engine census sums the label census over regtest.cpp
    // PLUS the fragments (never dropping a fragment label), preflight reads
    // its battery census printf patterns from regtest.cpp plus the fragments,
    // rverify counts the fragment and the include as two applied items, and
    // rn derives the audit_file and adds it to the git add (the R793
    // untracked lesson). FOUR TOOL FILES, NINE FILE PATCHES: the engine (the
    // audit_file branch and the fragment census), rverify (the restore list
    // and the n_patches count), preflight (the census comment and the pattern
    // source), rn (the fact derivation, the echo, the git add). THE R791
    // LESSON BINDS: tooling lands alone - R822's own audit lands inline (old
    // way), the engine can never consume its own extension in the run that
    // patches it in, and the first audit-file round is the next one. THE
    // MIGRATION FOLLOWS: the per-book rounds that move the existing 744
    // blocks into fragments ride the wiring later, smallest first, Curtiss's
    // call each round. NO gap boxes flip (the MM2 arc gap stays 37 closed 0
    // open).
    {
        using namespace rules;
        int bad = 0;
    if (afwRound() != 822
            || afwCensusBefore() != 744
            || afwCensusAfter() != 745
            || afwRegtestBytesAtBase() != 5717896
            || afwToolFilesPatched() != 4
            || afwEnginePatches() != 2
            || afwRverifyPatches() != 2
            || afwPreflightPatches() != 2
            || afwRnPatches() != 3
            || afwFilePatchesTotal() != 9
            || !afwFragmentCarriesAuditBlock()
            || !afwIncludeAtTheAnchor()
            || !afwCensusCountsFragments()
            || !afwPreflightReadsFragments()
            || !afwRnAddsTheFragment()
            || !afwRverifyCountsTwo()
            || !afwToolingLandsAlone()
            || !afwR822LandsOldWay()
            || !afwFragmentEngineEmitted()
            || !afwMigrationFollows()
        )
            ++bad;
        // the census arithmetic (one audit added)
    if (afwCensusAfter() != afwCensusBefore() + 1
            || afwCensusBefore() != 744
            || afwCensusAfter() != 745
        )
            ++bad;
        // the patch arithmetic (nine file patches over four tool files)
    if (afwFilePatchesTotal() != afwEnginePatches() + afwRverifyPatches() +
        afwPreflightPatches() + afwRnPatches()
            || afwFilePatchesTotal() != 9
            || afwToolFilesPatched() != 4
        )
            ++bad;
        // the monolith size pin (the 951b962 base sha)
    if (afwRegtestBytesAtBase() != 5717896
        )
            ++bad;
        // the round pin
    if (afwRound() != 822
        )
            ++bad;
        printf("R822 audit files wiring audit: bad %d\n", bad);
        if (bad) return 1;
    }
