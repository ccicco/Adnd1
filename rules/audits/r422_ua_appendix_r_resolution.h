    // ---- R422: the appendix R
    // resolution pin audit ----
    // The clean p. 109 read
    // resolves the five R390
    // flagged holes: the subdual
    // supercedes sentence prints
    // whole ("supersedes
    // previously published
    // material, in particular
    // with regard to the subdual
    // of dragons"); the
    // vanquishing loser sentence
    // recovers its tail ("must
    // honorably surrender
    // immediately"); the chaotic
    // constraints line prints
    // whole ("under no constraints
    // whatsoever"); the
    // monks-druids head resolves
    // ("It is also used by monks
    // and druids seeking to
    // advance to the next level by
    // combat"); and the disarming
    // scimitar seam confirms as
    // the print itself - the
    // example genuinely names the
    // scimitar, a weapon absent
    // from the six-entry length
    // list (the book's own seam,
    // pinned as printed). All
    // seven items now stand fully
    // clean; census 347 -> 348.
    {
        using namespace rules;
        int bad = 0;
        if (!uanlSubdualSupercedesReadsClean()
                || !uanlVanqLoserMustHonorablySurrender()
                || !uanlVanqChaoticLineReadsClean()
                || !uanlVanqUsedByMonksAndDruids()
                || !uanlDisarmScimitarSeamIsPrint())
            ++bad;
        if (uanlPartItemTotal() != 7
                || uanlPartCleanCount() != 7
                || uanlPartFlaggedCount() != 0
                || uanlPartGarbledCount() != 0)
            ++bad;
        if (uanlPartCleanCount()
                + uanlPartFlaggedCount()
                + uanlPartGarbledCount()
                != uanlPartItemTotal())
            ++bad;
        if (!uanlSubdualSupercedesPublished()
                || !uanlSubdualSupercedesDragonSubdual()
                || !uanlVanqLoserAtZeroHp()
                || !uanlVanqChaoticEvilNoConstraints()
                || !uanlDisarmScimitarSeam())
            ++bad;
        printf("R422 UA appendix R resolution pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
