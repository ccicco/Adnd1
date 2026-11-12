    // ---- R942 Dragon issue-20 closure audit ----
    // THE DRAGON ISSUE-20 BOX CLOSING ROUND - the pure flip, no new ink. Both
    // report-020 boxes flip at this single round: the issue-20 opener chains
    // part one (the R940 Polynesian pantheon, the witch class ladder, the
    // demonology grids) and part two (the R941 600-death campaign census, the
    // demonic possession and exorcism doctrine). Five chains across three
    // rounds, the fourth three-round issue shape after 17, 18 and 19. The
    // bookkeeping mirrors the f17, f18 and d19 closers: the boxes, chains and
    // rounds consts, the issue-closed consts 7 through 19, the walk-complete
    // bools and the unchanged registry ground truth. ISSUES 2-20 ALL CLOSED.
    {
        using namespace rules;
        int bad = 0;
    if (d2cIssueTwentyBoxes() != 2
            || d2cIssueTwentyChains() != 5
            || d2cIssueTwentyRounds() != 3
            || d2cIssueSevenClosed() != 1
            || d2cIssueEightClosed() != 1
            || d2cIssueNineClosed() != 1
            || d2cIssueTenClosed() != 1
            || d2cIssueElevenClosed() != 1
            || d2cIssueTwelveClosed() != 1
            || d2cIssueThirteenClosed() != 1
            || d2cIssueFourteenClosed() != 1
            || d2cIssueFifteenClosed() != 1
            || d2cIssueSixteenClosed() != 1
            || d2cIssueSeventeenClosed() != 1
            || d2cIssueEighteenClosed() != 1
            || d2cIssueNineteenClosed() != 1
            || d2cRegistryLoaded() != 1313
            || d2cRegistryBaseLua() != 1338
            || d2cRegistryNeverLoad() != 25
            || !d2cWalkSevenComplete()
            || !d2cWalkEightComplete()
            || !d2cWalkNineComplete()
            || !d2cWalkTenComplete()
            || !d2cWalkElevenComplete()
            || !d2cWalkTwelveComplete()
            || !d2cWalkThirteenComplete()
            || !d2cWalkFourteenComplete()
            || !d2cWalkFifteenComplete()
            || !d2cWalkSixteenComplete()
            || !d2cWalkSeventeenComplete()
            || !d2cWalkEighteenComplete()
            || !d2cWalkNineteenComplete()
            || !d2cWalkTwentyComplete()
        )
            ++bad;
        // the issue-20 census - two boxes, five chains, three rounds, the
        // fourth three-round issue shape
    if (d2cIssueTwentyBoxes() != 2
            || d2cIssueTwentyChains() != 5
            || d2cIssueTwentyRounds() != 3
            || d2cIssueNineteenClosed() != 1
            || d2cIssueEighteenClosed() != 1
            || d2cIssueSevenClosed() != 1
        )
            ++bad;
        // the mid-walk closed set - issues 8 through 17 all stand closed at
        // this flip
    if (d2cIssueSeventeenClosed() != 1
            || d2cIssueSixteenClosed() != 1
            || d2cIssueFifteenClosed() != 1
            || d2cIssueFourteenClosed() != 1
            || d2cIssueThirteenClosed() != 1
            || d2cIssueTwelveClosed() != 1
            || d2cIssueElevenClosed() != 1
            || d2cIssueTenClosed() != 1
            || d2cIssueNineClosed() != 1
            || d2cIssueEightClosed() != 1
        )
            ++bad;
        // the registry ground truth unchanged 1313/1338/25 and the walk
        // complete through issue 20 - ISSUES 2-20 ALL CLOSED
    if (d2cRegistryLoaded() != 1313
            || d2cRegistryBaseLua() != 1338
            || d2cRegistryNeverLoad() != 25
            || d2cWalkTwentyComplete() != 1
            || d2cWalkSevenComplete() != 1
            || d2cWalkNineteenComplete() != 1
        )
            ++bad;
        printf("R942 Dragon issue-20 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
