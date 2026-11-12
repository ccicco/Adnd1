    // ---- R945 Dragon issue-21 closure audit ----
    // THE DRAGON ISSUE-21 BOX CLOSING ROUND - the pure flip, no new ink. Both
    // report-021 boxes flip at this single round: the issue-21 opener chains
    // part one (the R943 twenty-NPC personality grid, the spell-research
    // doctrine, the foretelling-spell counters) and part two (the R944
    // gold-piece inflation doctrine, the natural-history monster doctrine,
    // the Hall of Mystery, the M-U titles kit). Seven chains across three
    // rounds, the fifth three-round issue shape. ISSUES 2-21 ALL CLOSED.
    // Registry ground truth unchanged: 1313 loaded / 1338 base lua / 25
    // never-load (R924 re-measure).
    {
        using namespace rules;
        int bad = 0;
    if (d21IssueTwentyOneBoxes() != 2
            || d21IssueTwentyOneChains() != 7
            || d21IssueTwentyOneRounds() != 3
            || d21IssueSevenClosed() != 1
            || d21IssueEightClosed() != 1
            || d21IssueNineClosed() != 1
            || d21IssueTenClosed() != 1
            || d21IssueElevenClosed() != 1
            || d21IssueTwelveClosed() != 1
            || d21IssueThirteenClosed() != 1
            || d21IssueFourteenClosed() != 1
            || d21IssueFifteenClosed() != 1
            || d21IssueSixteenClosed() != 1
            || d21IssueSeventeenClosed() != 1
            || d21IssueEighteenClosed() != 1
            || d21IssueNineteenClosed() != 1
            || d21IssueTwentyClosed() != 1
            || d21RegistryLoaded() != 1313
            || d21RegistryBaseLua() != 1338
            || d21RegistryNeverLoad() != 25
            || !d21WalkSevenComplete()
            || !d21WalkEightComplete()
            || !d21WalkNineComplete()
            || !d21WalkTenComplete()
            || !d21WalkElevenComplete()
            || !d21WalkTwelveComplete()
            || !d21WalkThirteenComplete()
            || !d21WalkFourteenComplete()
            || !d21WalkFifteenComplete()
            || !d21WalkSixteenComplete()
            || !d21WalkSeventeenComplete()
            || !d21WalkEighteenComplete()
            || !d21WalkNineteenComplete()
            || !d21WalkTwentyComplete()
            || !d21WalkTwentyOneComplete()
        )
            ++bad;
        // the issue-21 census - two boxes, seven chains, three rounds, the
        // fifth three-round issue shape
    if (d21IssueTwentyOneBoxes() != 2
            || d21IssueTwentyOneChains() != 7
            || d21IssueTwentyOneRounds() != 3
            || d21IssueTwentyClosed() != 1
            || d21IssueNineteenClosed() != 1
            || d21IssueSevenClosed() != 1
        )
            ++bad;
        // the mid-walk closed set - issues 8 through 18 all stand closed at
        // this flip
    if (d21IssueEighteenClosed() != 1
            || d21IssueSeventeenClosed() != 1
            || d21IssueSixteenClosed() != 1
            || d21IssueFifteenClosed() != 1
            || d21IssueFourteenClosed() != 1
            || d21IssueThirteenClosed() != 1
            || d21IssueTwelveClosed() != 1
            || d21IssueElevenClosed() != 1
            || d21IssueTenClosed() != 1
            || d21IssueNineClosed() != 1
            || d21IssueEightClosed() != 1
        )
            ++bad;
        // the registry ground truth unchanged 1313/1338/25 and the walk
        // complete through issue 21 - ISSUES 2-21 ALL CLOSED
    if (d21RegistryLoaded() != 1313
            || d21RegistryBaseLua() != 1338
            || d21RegistryNeverLoad() != 25
            || d21WalkTwentyOneComplete() != 1
            || d21WalkSevenComplete() != 1
            || d21WalkTwentyComplete() != 1
        )
            ++bad;
        printf("R945 Dragon issue-21 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
