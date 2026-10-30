    // ---- R939 Dragon issue-19 closure audit ----
    // THE DRAGON ISSUE-19 BOX CLOSING ROUND - the pure flip, no new ink. Both
    // report-019 boxes flip at this single round: the issue-19 opener chains
    // part one (the R937 wish-spell doctrine, the mythos of Australia
    // pantheon, the systematic magic fields) and part two (the R938 Origins
    // 78 tourney and victory-point scoring, the creative treasures and
    // location/trap/gas charts, the hostile magic-user spell determination
    // grids). Six chains across three rounds, the third three-round issue
    // shape after 17 and 18. The bookkeeping mirrors the f17 and f18 closers:
    // the boxes, chains and rounds consts, the issue-closed consts 7 through
    // 18, the walk-complete bools and the unchanged registry ground truth.
    {
        using namespace rules;
        int bad = 0;
    if (d19IssueNineteenBoxes() != 2
            || d19IssueNineteenChains() != 6
            || d19IssueNineteenRounds() != 3
            || d19IssueSevenClosed() != 1
            || d19IssueEightClosed() != 1
            || d19IssueNineClosed() != 1
            || d19IssueTenClosed() != 1
            || d19IssueElevenClosed() != 1
            || d19IssueTwelveClosed() != 1
            || d19IssueThirteenClosed() != 1
            || d19IssueFourteenClosed() != 1
            || d19IssueFifteenClosed() != 1
            || d19IssueSixteenClosed() != 1
            || d19IssueSeventeenClosed() != 1
            || d19IssueEighteenClosed() != 1
            || d19RegistryLoaded() != 1313
            || d19RegistryBaseLua() != 1338
            || d19RegistryNeverLoad() != 25
            || !d19WalkSevenComplete()
            || !d19WalkEightComplete()
            || !d19WalkNineComplete()
            || !d19WalkTenComplete()
            || !d19WalkElevenComplete()
            || !d19WalkTwelveComplete()
            || !d19WalkThirteenComplete()
            || !d19WalkFourteenComplete()
            || !d19WalkFifteenComplete()
            || !d19WalkSixteenComplete()
            || !d19WalkSeventeenComplete()
            || !d19WalkEighteenComplete()
            || !d19WalkNineteenComplete()
        )
            ++bad;
        // the issue-19 census - two boxes, six chains, three rounds, the
        // third three-round shape, issues 7 through 18 standing closed
    if (d19IssueNineteenBoxes() != 2
            || d19IssueNineteenChains() != 6
            || d19IssueNineteenRounds() != 3
            || d19IssueEighteenClosed() != 1
            || d19IssueSeventeenClosed() != 1
            || d19IssueSevenClosed() != 1
        )
            ++bad;
        // the mid-walk closed set - issues 8 through 16 all stand closed at
        // this flip
    if (d19IssueSixteenClosed() != 1
            || d19IssueFifteenClosed() != 1
            || d19IssueFourteenClosed() != 1
            || d19IssueThirteenClosed() != 1
            || d19IssueTwelveClosed() != 1
            || d19IssueElevenClosed() != 1
            || d19IssueTenClosed() != 1
            || d19IssueNineClosed() != 1
            || d19IssueEightClosed() != 1
        )
            ++bad;
        // the registry ground truth unchanged 1313/1338/25 and the walk
        // complete through issue 19, issues 2 through 7 and 18 included
    if (d19RegistryLoaded() != 1313
            || d19RegistryBaseLua() != 1338
            || d19RegistryNeverLoad() != 25
            || d19WalkNineteenComplete() != 1
            || d19WalkSevenComplete() != 1
            || d19WalkEighteenComplete() != 1
        )
            ++bad;
        printf("R939 Dragon issue-19 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
