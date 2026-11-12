    // ---- R928 Dragon issue-15 closure audit ----
    // THE DRAGON ISSUE-15 CLOSURE ROUND - the pure flip, no new ink. ALL FIVE
    // report-015 boxes close at this single flip - Dragon Magic (print 3,
    // cont. 13), the Wandering Monster fourth-level list (print 7), Weather
    // in the Wilderness (print 14-15), the Pits tables (print 5) and the
    // Random Events Table for Settlements (print 5) - 5 closed / 0 open in
    // tools/dragon_gap_report_015.md; the five-chain walk completes in two
    // rounds (the R927 opener carrying all five chains, this flip), the
    // issue-14 two-round pattern. Issues 2-15 all closed.
    {
        using namespace rules;
        int bad = 0;
    if (f15IssueFifteenBoxes() != 5
            || f15IssueFifteenChains() != 5
            || f15IssueFifteenRounds() != 2
            || f15IssueFourteenClosed() != 1
            || f15IssueThirteenClosed() != 1
            || f15IssueTwelveClosed() != 1
            || f15IssueElevenClosed() != 1
            || f15IssueTenClosed() != 1
            || f15IssueNineClosed() != 1
            || f15IssueEightClosed() != 1
            || f15IssueSevenClosed() != 1
            || f15IssueSixClosed() != 1
            || f15RegistryLoaded() != 1313
            || f15RegistryBaseLua() != 1338
            || f15RegistryNeverLoad() != 25
            || !f15WalkSixComplete()
            || !f15WalkSevenComplete()
            || !f15WalkEightComplete()
            || !f15WalkNineComplete()
            || !f15WalkTenComplete()
            || !f15WalkElevenComplete()
            || !f15WalkTwelveComplete()
            || !f15WalkThirteenComplete()
            || !f15WalkFourteenComplete()
            || !f15WalkFifteenComplete()
        )
            ++bad;
        // the walk census - five issue-15 boxes, five chains across two
        // rounds, the issue-14 and issue-13 reports complete
    if (f15IssueFifteenBoxes() != 5
            || f15IssueFifteenChains() != 5
            || f15IssueFifteenRounds() != 2
            || f15IssueFourteenClosed() != 1
            || f15IssueThirteenClosed() != 1
        )
            ++bad;
        // the earlier reports complete since R918, R916, R913, R911 and R909,
        // the issue-15 and issue-14 walks complete
    if (f15IssueTwelveClosed() != 1
            || f15IssueElevenClosed() != 1
            || f15IssueTenClosed() != 1
            || f15IssueNineClosed() != 1
            || f15IssueEightClosed() != 1
            || f15IssueSevenClosed() != 1
            || f15IssueSixClosed() != 1
            || f15WalkFifteenComplete() != 1
            || f15WalkFourteenComplete() != 1
        )
            ++bad;
        // the registry ground truth unchanged from the R924 re-measure - 1313
        // loaded, 1338 base lua, 25 never-load
    if (f15RegistryLoaded() != 1313
            || f15RegistryBaseLua() != 1338
            || f15RegistryNeverLoad() != 25
            || f15WalkSixComplete() != 1
            || f15WalkTenComplete() != 1
            || f15WalkThirteenComplete() != 1
        )
            ++bad;
        printf("R928 Dragon issue-15 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
