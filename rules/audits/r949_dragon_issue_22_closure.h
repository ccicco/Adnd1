    // ---- R949 Dragon issue-22 closure audit ----
    // THE DRAGON ISSUE-22 BOX CLOSING ROUND - the pure flip, no new ink. All
    // three report-022 boxes flip at this single round: the part-one triptych
    // (R946, t22), the part-two AD&D DMG sneak preview (R947, s22) and the
    // part-three commentary set (R948, k22). The walk holds issues 2-22 all
    // closed; the Sullin and brawling watches ride to TD 23.
    {
        using namespace rules;
        int bad = 0;
    if (l22IssueTwentyTwoBoxes() != 3
            || l22IssueTwentyTwoChains() != 9
            || l22IssueTwentyTwoRounds() != 4
            || l22PartOneInline() != 93
            || l22PartTwoInline() != 320
            || l22PartThreeInline() != 151
            || l22OpenerInlineTotal() != 564
            || l22WalkFirstIssue() != 2
            || l22WalkLastClosed() != 22
            || l22WalkIssuesClosed() != 21
            || l22CensusBefore() != 871
            || l22CensusAfter() != 872
            || l22RegistryLoaded() != 1313
            || l22RegistryBaseLua() != 1338
            || l22RegistryNeverLoad() != 25
            || l22TDNumber() != 22
            || l22LWNumber() != 13
            || l22IssueYear() != 1979
            || !l22WalkTwoThroughTwentyTwo()
            || !l22PartOneComplete()
            || !l22PartTwoComplete()
            || !l22PartThreeComplete()
            || !l22FirstFourRoundShape()
            || !l22NoJanuaryIssue()
            || !l22PrintFolioEqualsPdfPage()
            || !l22PrintCatchesPinned()
            || !l22SullinWatchRides()
            || !l22BrawlingWatchRides()
            || !l22GapReportClosed()
        )
            ++bad;
        // the issue-22 census - three boxes, nine chains, four rounds, the
        // first four-round shape of the walk the issue-22 closure bookkeeping
    if (l22IssueTwentyTwoBoxes() != 3
            || l22IssueTwentyTwoChains() != 9
            || l22IssueTwentyTwoRounds() != 4
            || l22FirstFourRoundShape() != 1
        )
            ++bad;
        // the opener totals - the triptych ninety-three, the preview three
        // hundred twenty, the commentary one hundred fifty-one, five hundred
        // sixty-four together the issue-22 closure bookkeeping
    if (l22PartOneInline() != 93
            || l22PartTwoInline() != 320
            || l22PartThreeInline() != 151
            || l22OpenerInlineTotal() != 564
        )
            ++bad;
        // the walk census - from issue two through issue twenty-two,
        // twenty-one issues all closed the issue-22 closure bookkeeping
    if (l22WalkFirstIssue() != 2
            || l22WalkLastClosed() != 22
            || l22WalkIssuesClosed() != 21
            || l22WalkTwoThroughTwentyTwo() != 1
        )
            ++bad;
        // the battery and registry ground truth - the census step and the
        // unchanged registry measures the issue-22 closure bookkeeping
    if (l22CensusBefore() != 871
            || l22CensusAfter() != 872
            || l22RegistryLoaded() != 1313
            || l22RegistryBaseLua() != 1338
            || l22RegistryNeverLoad() != 25
        )
            ++bad;
        // the issue frame - TD 22 and LW 13, February 1979, the combined
        // experiment with print folio equal to PDF page the issue-22 closure
        // bookkeeping
    if (l22TDNumber() != 22
            || l22LWNumber() != 13
            || l22IssueYear() != 1979
            || l22NoJanuaryIssue() != 1
            || l22PrintFolioEqualsPdfPage() != 1
        )
            ++bad;
        // the closing watches - the Sullin spells and the brawling sequel
        // ride to TD 23 and the report closes with all boxes checked the
        // issue-22 closure bookkeeping
    if (l22SullinWatchRides() != 1
            || l22BrawlingWatchRides() != 1
            || l22GapReportClosed() != 1
        )
            ++bad;
        printf("R949 Dragon issue-22 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
