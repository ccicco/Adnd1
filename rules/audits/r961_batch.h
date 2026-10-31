    // ---- R961 Dragon issue-25 closure audit ----
    // THE DRAGON ISSUE-25 BOX CLOSING ROUND - the pure flip, no new ink. All
    // three report-025 boxes flip at this single round: the part-one opener
    // set (R958, t25), the part-two war game and vampire roster table round
    // (R959, s25) and the part-three commentary set (R960, k25) all checked,
    // gap_census 3 closed 0 open, report-025 joining mm2, ddg and report-024
    // in the closed state
    {
        using namespace rules;
        int bad = 0;
    if (l25IssueTwentyFiveBoxes() != 3
            || l25IssueTwentyFiveChains() != 8
            || l25IssueTwentyFiveRounds() != 4
            || l25PartOneInline() != 48
            || l25PartTwoInline() != 118
            || l25PartThreeInline() != 70
            || l25OpenerInlineTotal() != 236
            || l25WalkFirstIssue() != 2
            || l25WalkLastClosed() != 25
            || l25WalkIssuesClosed() != 24
            || l25CensusBefore() != 883
            || l25CensusAfter() != 884
            || l25RegistryLoaded() != 1313
            || l25RegistryBaseLua() != 1338
            || l25RegistryNeverLoad() != 25
            || l25TDNumber() != 25
            || l25IssueYear() != 1979
            || !l25WalkTwoThroughTwentyFive()
            || !l25PartOneComplete()
            || !l25PartTwoComplete()
            || !l25PartThreeComplete()
            || !l25FourthFourRoundShape()
            || !l25NumberingAgrees()
            || !l25PrintFolioEqualsPdfPage()
            || !l25SingleVoiceTranscript()
            || !l25PrintCatchesPinned()
            || !l25SullinWatchRides()
            || !l25BrawlingWatchRides()
            || !l25GapReportClosed()
        )
            ++bad;
        // the shape itself - three boxes, eight chains, four rounds, the
        // fourth four-round walk the issue-25 closure bookkeeping
    if (l25IssueTwentyFiveBoxes() != 3
            || l25IssueTwentyFiveChains() != 8
            || l25IssueTwentyFiveRounds() != 4
            || l25FourthFourRoundShape() != 1
        )
            ++bad;
        // the opener totals - the opener set, the table round and the
        // commentary set together at two hundred thirty-six the issue-25
        // closure bookkeeping
    if (l25PartOneInline() != 48
            || l25PartTwoInline() != 118
            || l25PartThreeInline() != 70
            || l25OpenerInlineTotal() != 236
        )
            ++bad;
        // the walk census - issues two through twenty-five all closed,
        // twenty-four issues the issue-25 closure bookkeeping
    if (l25WalkFirstIssue() != 2
            || l25WalkLastClosed() != 25
            || l25WalkIssuesClosed() != 24
            || l25WalkTwoThroughTwentyFive() != 1
        )
            ++bad;
        // the battery and registry ground truth - the census before and after
        // the flip, the unchanged registry the issue-25 closure bookkeeping
    if (l25CensusBefore() != 883
            || l25CensusAfter() != 884
            || l25RegistryLoaded() != 1313
            || l25RegistryBaseLua() != 1338
            || l25RegistryNeverLoad() != 25
        )
            ++bad;
        // the issue frame - TD 25, Vol. III No. 11 May 1979, the numbering
        // agreement, the folio check, the single voice the issue-25 closure
        // bookkeeping
    if (l25TDNumber() != 25
            || l25IssueYear() != 1979
            || l25NumberingAgrees() != 1
            || l25PrintFolioEqualsPdfPage() != 1
            || l25SingleVoiceTranscript() != 1
        )
            ++bad;
        // the closure roll - all three parts pinned, the catches pinned, both
        // watches riding to TD 27, report 025 closed the issue-25 closure
        // bookkeeping
    if (l25PartOneComplete() != 1
            || l25PartTwoComplete() != 1
            || l25PartThreeComplete() != 1
            || l25PrintCatchesPinned() != 1
            || l25SullinWatchRides() != 1
            || l25BrawlingWatchRides() != 1
            || l25GapReportClosed() != 1
        )
            ++bad;
        printf("R961 Dragon issue-25 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
