    // ---- R921 Dragon issue-12 closure audit ----
    // THE DRAGON ISSUE-12 CLOSURE ROUND - the pure flip, no new ink. The
    // issue-12 part-two box (the Persian Mythos and the Lovecraftian Mythos,
    // folios 8-11 and 18-21) closes 2 closed / 0 open in
    // tools/dragon_gap_report_012.md; the four-chain walk completes exactly
    // as adjudicated - the R919 part-one pair (the Ovalle illusionist article
    // and the Endersby and Carroll ship cargo article) and the R920 part-two
    // pair (the Arkenberg Persian Mythos and the Kuntz/Holmes Lovecraftian
    // Mythos). The bookkeeping pins: the two boxes and their four chains, the
    // issue-11 report complete at 1 / 0 since R918, the issue-10 report
    // complete at 2 / 0 since R916, the issue-9 report complete at 1 / 0
    // since R913, the issue-8 report complete at 1 / 0 since R911, the
    // issue-7 report complete at 1 / 0 since R909, the issue-6 report
    // complete at 1 / 0 since R907, and the registry ground truth carried
    // forward. Per the Curtiss call this round ends the issue-12 walk with NO
    // issue-13 opener to follow.
    {
        using namespace rules;
        int bad = 0;
    if (fclIssueTwelveBoxes() != 2
            || fclIssueTwelveChains() != 4
            || fclIssueTwelveRounds() != 3
            || fclIssueElevenClosed() != 1
            || fclIssueTenClosed() != 1
            || fclIssueNineClosed() != 1
            || fclIssueEightClosed() != 1
            || fclIssueSevenClosed() != 1
            || fclIssueSixClosed() != 1
            || fclRegistryLive() != 1311
            || fclRegistryBaseLua() != 1333
            || fclRegistryNeverLoad() != 25
            || !fclWalkSixComplete()
            || !fclWalkSevenComplete()
            || !fclWalkEightComplete()
            || !fclWalkNineComplete()
            || !fclWalkTenComplete()
            || !fclWalkElevenComplete()
            || !fclWalkTwelveComplete()
            || !fclVariantLayerDoctrine()
        )
            ++bad;
        // the walk census - two issue-12 boxes, four chains across three
        // rounds, the issue-11 and issue-10 reports complete
    if (fclIssueTwelveBoxes() != 2
            || fclIssueTwelveChains() != 4
            || fclIssueTwelveRounds() != 3
            || fclIssueElevenClosed() != 1
            || fclIssueTenClosed() != 1
        )
            ++bad;
        // the earlier reports complete at one closed box each since R913,
        // R911, R909 and R907
    if (fclIssueNineClosed() != 1
            || fclIssueEightClosed() != 1
            || fclIssueSevenClosed() != 1
            || fclIssueSixClosed() != 1
        )
            ++bad;
        // the registry ground truth carried forward - 1311 live / 1333 base /
        // 25 never-load
    if (fclRegistryLive() != 1311
            || fclRegistryBaseLua() != 1333
            || fclRegistryNeverLoad() != 25
        )
            ++bad;
        printf("R921 Dragon issue-12 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
