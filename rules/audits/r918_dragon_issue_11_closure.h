    // ---- R918 Dragon issue-11 closure audit ----
    // THE DRAGON ISSUE-11 CLOSURE ROUND - the pure flip, no new ink. The
    // issue-11 box (the Kuntz brawling article and the Ward quarterstaff
    // article, folios 7 and 26-27) closes 1 closed / 0 open in
    // tools/dragon_gap_report_011.md; the two-chain walk completes exactly as
    // adjudicated at R917. The bookkeeping pins: the single box and its two
    // chains, the issue-10 report complete at 2 / 0 since R916, the issue-9
    // report complete at 1 / 0 since R913, the issue-8 report complete at 1 /
    // 0 since R911, the issue-7 report complete at 1 / 0 since R909, the
    // issue-6 report complete at 1 / 0 since R907, and the registry ground
    // truth carried forward.
    {
        using namespace rules;
        int bad = 0;
    if (bfxIssueElevenBoxes() != 1
            || bfxIssueElevenChains() != 2
            || bfxIssueTenClosed() != 1
            || bfxIssueNineClosed() != 1
            || bfxIssueEightClosed() != 1
            || bfxIssueSevenClosed() != 1
            || bfxIssueSixClosed() != 1
            || bfxRegistryLive() != 1311
            || bfxRegistryBaseLua() != 1333
            || bfxRegistryNeverLoad() != 25
            || !bfxWalkSixComplete()
            || !bfxWalkSevenComplete()
            || !bfxWalkEightComplete()
            || !bfxWalkNineComplete()
            || !bfxWalkTenComplete()
            || !bfxWalkElevenComplete()
            || !bfxVariantLayerDoctrine()
        )
            ++bad;
        // the walk census - one issue-11 box, two chains, the issue-10 and
        // issue-9 reports complete
    if (bfxIssueElevenBoxes() != 1
            || bfxIssueElevenChains() != 2
            || bfxIssueTenClosed() != 1
            || bfxIssueNineClosed() != 1
        )
            ++bad;
        // the earlier reports complete at one closed box each since R911,
        // R909 and R907
    if (bfxIssueEightClosed() != 1
            || bfxIssueSevenClosed() != 1
            || bfxIssueSixClosed() != 1
        )
            ++bad;
        // the registry ground truth carried forward - 1311 live / 1333 base /
        // 25 never-load, the battery line the only ground truth
    if (bfxRegistryLive() != 1311
            || bfxRegistryBaseLua() != 1333
            || bfxRegistryNeverLoad() != 25
        )
            ++bad;
        printf("R918 Dragon issue-11 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
