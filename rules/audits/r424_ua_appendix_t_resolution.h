    // ---- R424: the appendix T
    // resolution pin audit ----
    // The clean pp. 123-128 read
    // resolves the five R391
    // flagged holes: the
    // classification system
    // paragraph prints whole
    // ("a system of
    // classification and
    // nomenclature is presented
    // here that seems both
    // reasonable and easy to
    // use"); the fauchard
    // description prints whole
    // (the scythe/sickle
    // development, the cut-and-
    // thrust that did neither too
    // well, the little parrying,
    // the no-dismount early form,
    // the later back hook); the
    // Lucern/bec comparison tail
    // prints whole ("for the
    // latter weapon was not so
    // specialized"); the
    // combination intro prints
    // whole ("it is necessary to
    // ignore secondary spear tips
    // when classifying pole
    // arms"); the bill-guisarme
    // features list prints whole
    // ("a back spike for armor
    // penetration" - no "armor
    // ion" split exists in the
    // print); and the confusion
    // sentence prints whole ("is
    // certainly understandable,
    // and care must be taken in
    // identifying such
    // weapons"). All seven items
    // now stand fully clean;
    // census 349 -> 350.
    {
        using namespace rules;
        int bad = 0;
        if (!uapaSystemParagraphReadsClean()
                || !uapaFauchardDescriptionReadsClean()
                || !uapaLucernBecComparisonReadsClean()
                || !uapaCombinationIntroReadsClean()
                || !uapaBillGuisarmeFeaturesReadsClean()
                || !uapaConfusionSentenceReadsClean())
            ++bad;
        if (uapaPartItemTotal() != 7
                || uapaPartCleanCount() != 7
                || uapaPartFlaggedCount() != 0
                || uapaPartGarbledCount() != 0)
            ++bad;
        if (uapaPartCleanCount()
                + uapaPartFlaggedCount()
                + uapaPartGarbledCount()
                != uapaPartItemTotal())
            ++bad;
        if (!uapaFauchardSickleDevelopment()
                || !uapaSecondarySpearTipCombination()
                || uapaBillGuisarmeFeatureCount() != 4
                || !uapaCareShaftLengthHeadShape()
                || !uapaHuntingOrAgriculturalOrigin()
                || !uapaSystemDerivedBritannica())
            ++bad;
        printf("R424 UA appendix T resolution pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
