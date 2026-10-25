    // ---- R768 OA Daily Life Manners audit ----
    // OA round one hundred fifty-five (capture p. 312): the Chapter 15
    // Manners - the extraordinary politeness, the manners-as-crime doctrine,
    // the bow and the kowtow, the insult and the polite conversation,
    // single-pass pins per the R679 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dmdInsultSubjectsCount() != 9
            || dmdIgnorableJestInsults() != 2
            || !dmdExtraordinarilyPolite()
            || !dmdMannersAsCrime()
            || !dmdClassMarkersAndRidicule()
            || !dmdHonorRidiculeMechanic()
            || !dmdBowMeasuresRespect()
            || !dmdLowerBowsDeeper()
            || !dmdKowtowDeference()
            || !dmdKowtowExtremeAct()
            || !dmdWordsCanInsult()
            || !dmdInsultsSeldomLight()
            || !dmdPoliteConversation()
        )
            ++bad;
        // the politeness example
    if (dmdExtraordinarilyPolite() != 1
            || dmdMannersAsCrime() != 1
        )
            ++bad;
        // the ridicule example
    if (dmdClassMarkersAndRidicule() != 1
            || dmdHonorRidiculeMechanic() != 1
        )
            ++bad;
        // the bow example
    if (dmdBowMeasuresRespect() != 1
            || dmdLowerBowsDeeper() != 1
        )
            ++bad;
        // the kowtow example
    if (dmdKowtowDeference() != 1
            || dmdKowtowExtremeAct() != 1
        )
            ++bad;
        // the words example
    if (dmdInsultSubjectsCount() != 9
            || dmdWordsCanInsult() != 1
        )
            ++bad;
        // the jest example
    if (dmdIgnorableJestInsults() != 2
            || dmdInsultsSeldomLight() != 1
            || dmdPoliteConversation() != 1
        )
            ++bad;
        printf("R768 OA Daily Life Manners audit: bad %d\n", bad);
        if (bad) return 1;
    }
