    // ---- R957 Dragon issue-24 closure audit ----
    // THE DRAGON ISSUE-24 BOX CLOSING ROUND - the pure flip, no new ink. All
    // three report-024 boxes flip at this single round: the part-one variant
    // triptych (R954, t24), the part-two alignment pantheon (R955, s24) and
    // the part-three ten-chain commentary set (R956, k24). The walk holds
    // issues 2-24 all closed, the four-round shape thrice proven; the Sullin
    // and brawling watches ride to TD 25.
    {
        using namespace rules;
        int bad = 0;
    if (l24IssueTwentyFourBoxes() != 3
            || l24IssueTwentyFourChains() != 14
            || l24IssueTwentyFourRounds() != 4
            || l24PartOneInline() != 134
            || l24PartTwoInline() != 146
            || l24PartThreeInline() != 291
            || l24OpenerInlineTotal() != 571
            || l24WalkFirstIssue() != 2
            || l24WalkLastClosed() != 24
            || l24WalkIssuesClosed() != 23
            || l24CensusBefore() != 879
            || l24CensusAfter() != 880
            || l24RegistryLoaded() != 1313
            || l24RegistryBaseLua() != 1338
            || l24RegistryNeverLoad() != 25
            || l24TDNumber() != 24
            || l24IssueYear() != 1979
            || !l24WalkTwoThroughTwentyFour()
            || !l24PartOneComplete()
            || !l24PartTwoComplete()
            || !l24PartThreeComplete()
            || !l24ThirdFourRoundShape()
            || !l24NumberingAgrees()
            || !l24PrintFolioEqualsPdfPage()
            || !l24SingleVoiceTranscript()
            || !l24PrintCatchesPinned()
            || !l24SullinWatchRides()
            || !l24BrawlingWatchRides()
            || !l24GapReportClosed()
        )
            ++bad;
        // the shape itself - three boxes, fourteen chains, four rounds, the
        // third four-round walk the issue-24 closure bookkeeping
    if (l24IssueTwentyFourBoxes() != 3
            || l24IssueTwentyFourChains() != 14
            || l24IssueTwentyFourRounds() != 4
            || l24ThirdFourRoundShape() != 1
        )
            ++bad;
        // the opener totals - the triptych, the pantheon and the commentary
        // set together at five hundred seventy-one the issue-24 closure
        // bookkeeping
    if (l24PartOneInline() != 134
            || l24PartTwoInline() != 146
            || l24PartThreeInline() != 291
            || l24OpenerInlineTotal() != 571
        )
            ++bad;
        // the walk census - issues two through twenty-four all closed,
        // twenty-three issues the issue-24 closure bookkeeping
    if (l24WalkFirstIssue() != 2
            || l24WalkLastClosed() != 24
            || l24WalkIssuesClosed() != 23
            || l24WalkTwoThroughTwentyFour() != 1
        )
            ++bad;
        // the battery and registry ground truth - the census before and after
        // the flip, the unchanged registry the issue-24 closure bookkeeping
    if (l24CensusBefore() != 879
            || l24CensusAfter() != 880
            || l24RegistryLoaded() != 1313
            || l24RegistryBaseLua() != 1338
            || l24RegistryNeverLoad() != 25
        )
            ++bad;
        // the issue frame - TD 24, Vol. III No. 10 April 1979, the numbering
        // agreement, the folio check, the single voice the issue-24 closure
        // bookkeeping
    if (l24TDNumber() != 24
            || l24IssueYear() != 1979
            || l24NumberingAgrees() != 1
            || l24PrintFolioEqualsPdfPage() != 1
            || l24SingleVoiceTranscript() != 1
        )
            ++bad;
        // the closure roll - all three parts pinned, the catches pinned, both
        // watches riding to TD 25, report 024 closed the issue-24 closure
        // bookkeeping
    if (l24PartOneComplete() != 1
            || l24PartTwoComplete() != 1
            || l24PartThreeComplete() != 1
            || l24PrintCatchesPinned() != 1
            || l24SullinWatchRides() != 1
            || l24BrawlingWatchRides() != 1
            || l24GapReportClosed() != 1
        )
            ++bad;
        printf("R957 Dragon issue-24 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
