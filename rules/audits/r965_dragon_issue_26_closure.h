    // ---- R965 Dragon issue-26 closure audit ----
    // THE DRAGON ISSUE-26 BOX CLOSING ROUND - the pure flip, no new ink. All
    // three report-026 boxes flip at this single round: the part-one opener
    // set (R962, t26), the part-two table round (R963, s26) and the
    // part-three commentary set (R964, k26) all checked, gap_census 3 closed
    // 0 open, report-026 joining mm2, ddg, report-024 and report-025 in the
    // closed state
    {
        using namespace rules;
        int bad = 0;
    if (l26IssueTwentySixBoxes() != 3
            || l26IssueTwentySixChains() != 13
            || l26IssueTwentySixRounds() != 4
            || l26PartOneInline() != 80
            || l26PartTwoInline() != 111
            || l26PartThreeInline() != 89
            || l26OpenerInlineTotal() != 280
            || l26WalkFirstIssue() != 2
            || l26WalkLastClosed() != 26
            || l26WalkIssuesClosed() != 25
            || l26CensusBefore() != 887
            || l26CensusAfter() != 888
            || l26RegistryLoaded() != 1313
            || l26RegistryBaseLua() != 1338
            || l26RegistryNeverLoad() != 25
            || l26TDNumber() != 26
            || l26IssueYear() != 1979
            || !l26WalkTwoThroughTwentySix()
            || !l26PartOneComplete()
            || !l26PartTwoComplete()
            || !l26PartThreeComplete()
            || !l26FifthFourRoundShape()
            || !l26NumberingAgrees()
            || !l26PrintFolioEqualsPdfPageMinusTwo()
            || !l26SingleVoiceTranscript()
            || !l26PrintCatchesPinned()
            || !l26SullinWatchRides()
            || !l26BrawlingWatchRides()
            || !l26GapReportClosed()
        )
            ++bad;
        // the shape itself - three boxes, thirteen chains, four rounds, the
        // fifth four-round walk the issue-26 closure bookkeeping
    if (l26IssueTwentySixBoxes() != 3
            || l26IssueTwentySixChains() != 13
            || l26IssueTwentySixRounds() != 4
            || l26FifthFourRoundShape() != 1
        )
            ++bad;
        // the opener totals - the opener set, the table round and the
        // commentary set together at two hundred eighty the issue-26 closure
        // bookkeeping
    if (l26PartOneInline() != 80
            || l26PartTwoInline() != 111
            || l26PartThreeInline() != 89
            || l26OpenerInlineTotal() != 280
        )
            ++bad;
        // the walk census - issues two through twenty-six all closed,
        // twenty-five issues the issue-26 closure bookkeeping
    if (l26WalkFirstIssue() != 2
            || l26WalkLastClosed() != 26
            || l26WalkIssuesClosed() != 25
            || l26WalkTwoThroughTwentySix() != 1
        )
            ++bad;
        // the battery and registry ground truth - the census before and after
        // the flip, the unchanged registry the issue-26 closure bookkeeping
    if (l26CensusBefore() != 887
            || l26CensusAfter() != 888
            || l26RegistryLoaded() != 1313
            || l26RegistryBaseLua() != 1338
            || l26RegistryNeverLoad() != 25
        )
            ++bad;
        // the issue frame - TD 26, Vol. III No. 12 June 1979, the numbering
        // agreement, the folio check, the single voice the issue-26 closure
        // bookkeeping
    if (l26TDNumber() != 26
            || l26IssueYear() != 1979
            || l26NumberingAgrees() != 1
            || l26PrintFolioEqualsPdfPageMinusTwo() != 1
            || l26SingleVoiceTranscript() != 1
        )
            ++bad;
        // the closure roll - all three parts pinned, the catches pinned, both
        // watches riding to TD 27, report 026 closed the issue-26 closure
        // bookkeeping
    if (l26PartOneComplete() != 1
            || l26PartTwoComplete() != 1
            || l26PartThreeComplete() != 1
            || l26PrintCatchesPinned() != 1
            || l26SullinWatchRides() != 1
            || l26BrawlingWatchRides() != 1
            || l26GapReportClosed() != 1
        )
            ++bad;
        printf("R965 Dragon issue-26 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
