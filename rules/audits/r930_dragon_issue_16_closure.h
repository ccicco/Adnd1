    // ---- R930 Dragon issue-16 closure audit ----
    // THE DRAGON ISSUE-16 CLOSURE ROUND - the pure flip, no new ink. BOTH
    // report-016 boxes close at this single flip - the Near Eastern Mythos
    // (print 4-6) and The Ultimate NPC: Ninja (print 7-10) - 2 closed / 0
    // open in tools/dragon_gap_report_016.md; the two-chain walk completes in
    // two rounds (the R929 opener carrying both chains, this flip), the
    // issue-14 and issue-15 two-round pattern. Issues 2-16 all closed.
    {
        using namespace rules;
        int bad = 0;
    if (f16IssueSixteenBoxes() != 2
            || f16IssueSixteenChains() != 2
            || f16IssueSixteenRounds() != 2
            || f16IssueFifteenClosed() != 1
            || f16IssueFourteenClosed() != 1
            || f16IssueThirteenClosed() != 1
            || f16IssueTwelveClosed() != 1
            || f16IssueElevenClosed() != 1
            || f16IssueTenClosed() != 1
            || f16IssueNineClosed() != 1
            || f16IssueEightClosed() != 1
            || f16IssueSevenClosed() != 1
            || f16IssueSixClosed() != 1
            || f16RegistryLoaded() != 1313
            || f16RegistryBaseLua() != 1338
            || f16RegistryNeverLoad() != 25
            || !f16WalkSixComplete()
            || !f16WalkSevenComplete()
            || !f16WalkEightComplete()
            || !f16WalkNineComplete()
            || !f16WalkTenComplete()
            || !f16WalkElevenComplete()
            || !f16WalkTwelveComplete()
            || !f16WalkThirteenComplete()
            || !f16WalkFourteenComplete()
            || !f16WalkFifteenComplete()
            || !f16WalkSixteenComplete()
        )
            ++bad;
        // the walk census - two issue-16 boxes, two chains across two rounds,
        // the issue-15 and issue-14 reports complete
    if (f16IssueSixteenBoxes() != 2
            || f16IssueSixteenChains() != 2
            || f16IssueSixteenRounds() != 2
            || f16IssueFifteenClosed() != 1
            || f16IssueFourteenClosed() != 1
        )
            ++bad;
        // the earlier reports complete since R909, R911, R913, R916, R918,
        // R920, R922 and R924, the issue-16 and issue-15 walks complete
    if (f16IssueThirteenClosed() != 1
            || f16IssueTwelveClosed() != 1
            || f16IssueElevenClosed() != 1
            || f16IssueTenClosed() != 1
            || f16IssueNineClosed() != 1
            || f16IssueEightClosed() != 1
            || f16IssueSevenClosed() != 1
            || f16IssueSixClosed() != 1
            || f16WalkSixteenComplete() != 1
            || f16WalkFifteenComplete() != 1
        )
            ++bad;
        // the registry ground truth unchanged from the R924 re-measure - 1313
        // loaded, 1338 base lua, 25 never-load
    if (f16RegistryLoaded() != 1313
            || f16RegistryBaseLua() != 1338
            || f16RegistryNeverLoad() != 25
            || f16WalkSixComplete() != 1
            || f16WalkTenComplete() != 1
            || f16WalkThirteenComplete() != 1
        )
            ++bad;
        printf("R930 Dragon issue-16 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
