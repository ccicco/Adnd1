    // ---- R924 Dragon issue-13 closure audit ----
    // THE DRAGON ISSUE-13 CLOSURE ROUND - the pure flip, no new ink. The
    // issue-13 part-two box (the Arkenberg Japanese Mythos, folios 11-15)
    // closes 2 closed / 0 open in tools/dragon_gap_report_013.md; the
    // three-chain walk completes exactly as adjudicated - the R922 part-one
    // pair (the Shlump da Orc giant physics article and the Jon Pickens demon
    // generation article) and the R923 part-two chain (the Japanese Mythos).
    // The bookkeeping pins: the two boxes and their three chains, the
    // issue-12 report complete at 2 / 0 since R921, the issue-11 report
    // complete at 1 / 0 since R918, the issue-10 report complete at 2 / 0
    // since R916, the issue-9 report complete at 1 / 0 since R913, the
    // issue-8 report complete at 1 / 0 since R911, the issue-7 report
    // complete at 1 / 0 since R909, the issue-6 report complete at 1 / 0
    // since R907, and the registry ground truth RE-MEASURED at the R922
    // battery line - 1313 defs loaded, 1338 base lua files, 25 never-load
    // errors - superseding the R900-era 1311-live / 1333-base snapshot the
    // R921 closer carried forward, the five-file growth noted never silent;
    // the R921 fcl pins stay as landed, the historical snapshot they are. Per
    // the Curtiss ALL-USABLE call the scoped-out ink stays scoped - the
    // Tolkien Sorcerer Scroll commentary, the Bionic Supplement, the WARLORD
    // corrections, the silly songs, the Stolen Sacrifice fiction, the comics,
    // the contest rules and the Notes column - and the two slipped teasers
    // harvest at issue 14: the Creature Contest #1 winner stats (the
    // Jarnkung, the Cursed Crimson Crawler, the Ulik) print in TD 14.
    {
        using namespace rules;
        int bad = 0;
    if (iclIssueThirteenBoxes() != 2
            || iclIssueThirteenChains() != 3
            || iclIssueThirteenRounds() != 3
            || iclIssueTwelveClosed() != 1
            || iclIssueElevenClosed() != 1
            || iclIssueTenClosed() != 1
            || iclIssueNineClosed() != 1
            || iclIssueEightClosed() != 1
            || iclIssueSevenClosed() != 1
            || iclIssueSixClosed() != 1
            || iclRegistryLoaded() != 1313
            || iclRegistryBaseLua() != 1338
            || iclRegistryNeverLoad() != 25
            || !iclWalkSixComplete()
            || !iclWalkSevenComplete()
            || !iclWalkEightComplete()
            || !iclWalkNineComplete()
            || !iclWalkTenComplete()
            || !iclWalkElevenComplete()
            || !iclWalkTwelveComplete()
            || !iclWalkThirteenComplete()
        )
            ++bad;
        // the walk census - two issue-13 boxes, three chains across three
        // rounds, the issue-12 and issue-11 reports complete
    if (iclIssueThirteenBoxes() != 2
            || iclIssueThirteenChains() != 3
            || iclIssueThirteenRounds() != 3
            || iclIssueTwelveClosed() != 1
            || iclIssueElevenClosed() != 1
        )
            ++bad;
        // the earlier reports complete at one closed box each since R916,
        // R913, R911, R909 and R907, the issue-13 and issue-12 walks complete
    if (iclIssueTenClosed() != 1
            || iclIssueNineClosed() != 1
            || iclIssueEightClosed() != 1
            || iclIssueSevenClosed() != 1
            || iclIssueSixClosed() != 1
            || iclWalkThirteenComplete() != 1
            || iclWalkTwelveComplete() != 1
        )
            ++bad;
        // the registry ground truth re-measured - 1313 loaded / 1338 base /
        // 25 never-load at the R922 battery, the issue-6 and issue-11 walks
        // complete
    if (iclRegistryLoaded() != 1313
            || iclRegistryBaseLua() != 1338
            || iclRegistryNeverLoad() != 25
            || iclWalkSixComplete() != 1
            || iclWalkElevenComplete() != 1
        )
            ++bad;
        printf("R924 Dragon issue-13 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
