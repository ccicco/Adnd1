    // ---- R936 Dragon issue-18 closure audit ----
    // THE DRAGON ISSUE-18 CLOSURE ROUND - the pure flip, no new ink. BOTH
    // report-018 boxes close at this single flip - the issue-18 opener chains
    // part one (print 9, 14+19, 19, 31-32: the R934 part one - the Thompson
    // insanity chart and doctrine, the McCloud laws of magic and the Kemble
    // contest, the McAllister chamber of the godgame, the NPC pride, greed
    // and work-quality tables) and the issue-18 opener chains part two (print
    // 13, 23-24, 24: the R935 part two - the Sullin new spells levels one to
    // six, the Eckert monkish weapons and the kedo combat matrix, the Coburn
    // effective use of poison) - 2 closed / 0 open in
    // tools/dragon_gap_report_018.md; the seven-chain walk completes in three
    // rounds (the R934 opener part one carrying four chains, the R935 opener
    // part two carrying three chains, this flip), the second three-round
    // issue shape after issue 17. ISSUES 2-18 ALL CLOSED. Registry ground
    // truth unchanged: 1313 loaded / 1338 base lua / 25 never-load (the R924
    // re-measure). Watch: the Sullin article ends its level 6 with a cont pg
    // 21 promise but the levels 7-9 continuation NEVER PRINTS in TD18 - the
    // watch rides to TD 19; the brawling long-term-effects sequel promised in
    // issue 11 STILL does not print - watch TD 19.
    {
        using namespace rules;
        int bad = 0;
    if (f18IssueEighteenBoxes() != 2
            || f18IssueEighteenChains() != 7
            || f18IssueEighteenRounds() != 3
            || f18IssueSeventeenClosed() != 1
            || f18IssueSixteenClosed() != 1
            || f18IssueFifteenClosed() != 1
            || f18IssueFourteenClosed() != 1
            || f18IssueThirteenClosed() != 1
            || f18IssueTwelveClosed() != 1
            || f18IssueElevenClosed() != 1
            || f18IssueTenClosed() != 1
            || f18IssueNineClosed() != 1
            || f18IssueEightClosed() != 1
            || f18IssueSevenClosed() != 1
            || f18RegistryLoaded() != 1313
            || f18RegistryBaseLua() != 1338
            || f18RegistryNeverLoad() != 25
            || !f18WalkSevenComplete()
            || !f18WalkEightComplete()
            || !f18WalkNineComplete()
            || !f18WalkTenComplete()
            || !f18WalkElevenComplete()
            || !f18WalkTwelveComplete()
            || !f18WalkThirteenComplete()
            || !f18WalkFourteenComplete()
            || !f18WalkFifteenComplete()
            || !f18WalkSixteenComplete()
            || !f18WalkSeventeenComplete()
            || !f18WalkEighteenComplete()
        )
            ++bad;
        // the walk census - two issue-18 boxes, seven chains across three
        // rounds, the issue-closed ladder from 17 down to 7 all standing
    if (f18IssueEighteenBoxes() != 2
            || f18IssueEighteenChains() != 7
            || f18IssueEighteenRounds() != 3
            || f18IssueSeventeenClosed() != 1
            || f18IssueSevenClosed() != 1
        )
            ++bad;
        // the earlier reports complete since their own flips, issues 8
        // through 16 all closed
    if (f18IssueSixteenClosed() != 1
            || f18IssueFifteenClosed() != 1
            || f18IssueFourteenClosed() != 1
            || f18IssueThirteenClosed() != 1
            || f18IssueTwelveClosed() != 1
            || f18IssueElevenClosed() != 1
            || f18IssueTenClosed() != 1
            || f18IssueNineClosed() != 1
            || f18IssueEightClosed() != 1
        )
            ++bad;
        // the registry ground truth unchanged from the R924 re-measure - 1313
        // loaded, 1338 base lua, 25 never-load - and the walk bookends: issue
        // 18 complete at this flip, issue 7 standing complete
    if (f18RegistryLoaded() != 1313
            || f18RegistryBaseLua() != 1338
            || f18RegistryNeverLoad() != 25
            || f18WalkEighteenComplete() != 1
            || f18WalkSevenComplete() != 1
        )
            ++bad;
        printf("R936 Dragon issue-18 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
