    // ---- R933 Dragon issue-17 closure audit ----
    // THE DRAGON ISSUE-17 CLOSURE ROUND - the pure flip, no new ink. BOTH
    // report-017 boxes close at this single flip - the issue-17 opener chains
    // (print 3-4, 15-17, 20+22, 31-33: the R931 part one - Jousting in D&D,
    // Vampires in the Dungeon, Sights and Sounds in D&D, the Magic Munchkin,
    // the Scholar and the Crs-tchen, the Tesseracts, A Short History of
    // Adamanite, the Angels) and A Wizard With A Difference (print 10-13, the
    // R932 part two, the Ward eight specialized wizard variants) - 2 closed /
    // 0 open in tools/dragon_gap_report_017.md; the eight-chain walk
    // completes in three rounds (the R931 opener part one, the R932 opener
    // part two, this flip), the issue-17 three-round shape the Curtiss split
    // set. Issues 2-17 ALL CLOSED. Registry ground truth unchanged: 1313
    // loaded / 1338 base lua / 25 never-load (the R924 re-measure). Watch:
    // the brawling long-term-effects sequel STILL does not print (watch TD
    // 18).
    {
        using namespace rules;
        int bad = 0;
    if (f17IssueSeventeenBoxes() != 2
            || f17IssueSeventeenChains() != 8
            || f17IssueSeventeenRounds() != 3
            || f17IssueSixteenClosed() != 1
            || f17IssueFifteenClosed() != 1
            || f17IssueFourteenClosed() != 1
            || f17IssueThirteenClosed() != 1
            || f17IssueTwelveClosed() != 1
            || f17IssueElevenClosed() != 1
            || f17IssueTenClosed() != 1
            || f17IssueNineClosed() != 1
            || f17IssueEightClosed() != 1
            || f17IssueSevenClosed() != 1
            || f17IssueSixClosed() != 1
            || f17RegistryLoaded() != 1313
            || f17RegistryBaseLua() != 1338
            || f17RegistryNeverLoad() != 25
            || !f17WalkSixComplete()
            || !f17WalkSevenComplete()
            || !f17WalkEightComplete()
            || !f17WalkNineComplete()
            || !f17WalkTenComplete()
            || !f17WalkElevenComplete()
            || !f17WalkTwelveComplete()
            || !f17WalkThirteenComplete()
            || !f17WalkFourteenComplete()
            || !f17WalkFifteenComplete()
            || !f17WalkSixteenComplete()
            || !f17WalkSeventeenComplete()
        )
            ++bad;
        // the walk census - two issue-17 boxes, eight chains across three
        // rounds, the issue-16 and issue-15 reports complete
    if (f17IssueSeventeenBoxes() != 2
            || f17IssueSeventeenChains() != 8
            || f17IssueSeventeenRounds() != 3
            || f17IssueSixteenClosed() != 1
            || f17IssueFifteenClosed() != 1
        )
            ++bad;
        // the earlier reports complete since R909, R911, R913, R916, R918,
        // R920, R922, R924 and R926, the issue-17 and issue-16 walks complete
    if (f17IssueFourteenClosed() != 1
            || f17IssueThirteenClosed() != 1
            || f17IssueTwelveClosed() != 1
            || f17IssueElevenClosed() != 1
            || f17IssueTenClosed() != 1
            || f17IssueNineClosed() != 1
            || f17IssueEightClosed() != 1
            || f17IssueSevenClosed() != 1
            || f17IssueSixClosed() != 1
            || f17WalkSeventeenComplete() != 1
            || f17WalkSixteenComplete() != 1
        )
            ++bad;
        // the registry ground truth unchanged from the R924 re-measure - 1313
        // loaded, 1338 base lua, 25 never-load
    if (f17RegistryLoaded() != 1313
            || f17RegistryBaseLua() != 1338
            || f17RegistryNeverLoad() != 25
            || f17WalkSixComplete() != 1
            || f17WalkTenComplete() != 1
            || f17WalkThirteenComplete() != 1
        )
            ++bad;
        printf("R933 Dragon issue-17 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
