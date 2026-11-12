    // ---- R953 Dragon issue-23 closure audit ----
    // THE DRAGON ISSUE-23 BOX CLOSING ROUND - the pure flip, no new ink. All
    // three report-023 boxes flip at this single round: the part-one variant
    // triptych (R950, t23), the part-two Lower Planes generator (R951, s23)
    // and the part-three commentary set (R952, k23). The walk holds issues
    // 2-23 all closed; the Sullin and brawling watches ride to TD 24.
    {
        using namespace rules;
        int bad = 0;
    if (l23IssueTwentyThreeBoxes() != 3
            || l23IssueTwentyThreeChains() != 10
            || l23IssueTwentyThreeRounds() != 4
            || l23PartOneInline() != 82
            || l23PartTwoInline() != 178
            || l23PartThreeInline() != 145
            || l23OpenerInlineTotal() != 405
            || l23WalkFirstIssue() != 2
            || l23WalkLastClosed() != 23
            || l23WalkIssuesClosed() != 22
            || l23CensusBefore() != 874
            || l23CensusAfter() != 875
            || l23RegistryLoaded() != 1313
            || l23RegistryBaseLua() != 1338
            || l23RegistryNeverLoad() != 25
            || l23TDNumber() != 23
            || l23IssueYear() != 1979
            || !l23WalkTwoThroughTwentyThree()
            || !l23PartOneComplete()
            || !l23PartTwoComplete()
            || !l23PartThreeComplete()
            || !l23SecondFourRoundShape()
            || !l23NumberingAgrees()
            || !l23PrintFolioEqualsPdfPage()
            || !l23SingleVoiceTranscript()
            || !l23PrintCatchesPinned()
            || !l23SullinWatchRides()
            || !l23BrawlingWatchRides()
            || !l23GapReportClosed()
        )
            ++bad;
        // the shape itself - three boxes, ten chains, four rounds, the second
        // four-round walk the issue-23 closure bookkeeping
    if (l23IssueTwentyThreeBoxes() != 3
            || l23IssueTwentyThreeChains() != 10
            || l23IssueTwentyThreeRounds() != 4
            || l23SecondFourRoundShape() != 1
        )
            ++bad;
        // the opener inline totals - the triptych, the table round and the
        // commentary set together at four hundred five the issue-23 closure
        // bookkeeping
    if (l23PartOneInline() != 82
            || l23PartTwoInline() != 178
            || l23PartThreeInline() != 145
            || l23OpenerInlineTotal() != 405
        )
            ++bad;
        // the walk census - issues two through twenty-three all closed,
        // twenty-two issues the issue-23 closure bookkeeping
    if (l23WalkFirstIssue() != 2
            || l23WalkLastClosed() != 23
            || l23WalkIssuesClosed() != 22
            || l23WalkTwoThroughTwentyThree() != 1
        )
            ++bad;
        // the battery and registry ground truth - the census before and
        // after, the unchanged registry the issue-23 closure bookkeeping
    if (l23CensusBefore() != 874
            || l23CensusAfter() != 875
            || l23RegistryLoaded() != 1313
            || l23RegistryBaseLua() != 1338
            || l23RegistryNeverLoad() != 25
        )
            ++bad;
        // the issue frame - TD 23, Vol. III No. 9 March 1979, the numbering
        // agreement, the folio check, the single voice the issue-23 closure
        // bookkeeping
    if (l23TDNumber() != 23
            || l23IssueYear() != 1979
            || l23NumberingAgrees() != 1
            || l23PrintFolioEqualsPdfPage() != 1
            || l23SingleVoiceTranscript() != 1
        )
            ++bad;
        // the closure roll - all three parts pinned, the catches pinned, both
        // watches riding to TD 24, report 023 closed the issue-23 closure
        // bookkeeping
    if (l23PartOneComplete() != 1
            || l23PartTwoComplete() != 1
            || l23PartThreeComplete() != 1
            || l23PrintCatchesPinned() != 1
            || l23SullinWatchRides() != 1
            || l23BrawlingWatchRides() != 1
            || l23GapReportClosed() != 1
        )
            ++bad;
        printf("R953 Dragon issue-23 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
