    // ---- R926 Dragon issue-14 closure audit ----
    // THE DRAGON ISSUE-14 CLOSURE ROUND - the pure flip, no new ink. BOTH
    // report-014 boxes close at this single flip - the Name That Monster
    // Contest #1 winners (folio 3) and the Gregory Rihn lycanthropy variant
    // (folios 29-32) - 2 closed / 0 open in tools/dragon_gap_report_014.md;
    // the two-chain walk completes in two rounds (R925 opener carrying both
    // chains, this flip), the issue-11 two-round pattern. The bookkeeping
    // pins: the two boxes and their two chains, the issue-13 report complete
    // at 2 / 0 since R924, the issue-12 report at 2 / 0 since R921, the
    // issue-11 report at 1 / 0 since R918, the issue-10 report at 2 / 0 since
    // R916, the issue-9 report at 1 / 0 since R913, the issue-8 report at 1 /
    // 0 since R911, the issue-7 report at 1 / 0 since R909, the issue-6
    // report at 1 / 0 since R907, and the registry ground truth carried
    // forward unchanged from the R924 re-measure - 1313 defs loaded, 1338
    // base lua files, 25 never-load errors, the battery line the only ground
    // truth. Per the go-ahead adjudication the scoped-out ink stays scoped -
    // the SPACE MARINES article, the M-A Variant and the Total Person charts
    // (other systems), the reviews, the Rust Monster interview (humor, the
    // polymorphed-NPC rule IDEAS USABLE), the Monty Haul satire, the
    // editorial, the comics and the ads. The slipped brawling sequel still
    // has not printed - the watch continues at TD 15, which teases the Green
    // Magician and Dragon Magic.
    {
        using namespace rules;
        int bad = 0;
    if (f14IssueFourteenBoxes() != 2
            || f14IssueFourteenChains() != 2
            || f14IssueFourteenRounds() != 2
            || f14IssueThirteenClosed() != 1
            || f14IssueTwelveClosed() != 1
            || f14IssueElevenClosed() != 1
            || f14IssueTenClosed() != 1
            || f14IssueNineClosed() != 1
            || f14IssueEightClosed() != 1
            || f14IssueSevenClosed() != 1
            || f14IssueSixClosed() != 1
            || f14RegistryLoaded() != 1313
            || f14RegistryBaseLua() != 1338
            || f14RegistryNeverLoad() != 25
            || !f14WalkSixComplete()
            || !f14WalkSevenComplete()
            || !f14WalkEightComplete()
            || !f14WalkNineComplete()
            || !f14WalkTenComplete()
            || !f14WalkElevenComplete()
            || !f14WalkTwelveComplete()
            || !f14WalkThirteenComplete()
            || !f14WalkFourteenComplete()
        )
            ++bad;
        // the walk census - two issue-14 boxes, two chains across two rounds,
        // the issue-13 and issue-12 reports complete
    if (f14IssueFourteenBoxes() != 2
            || f14IssueFourteenChains() != 2
            || f14IssueFourteenRounds() != 2
            || f14IssueThirteenClosed() != 1
            || f14IssueTwelveClosed() != 1
        )
            ++bad;
        // the earlier reports complete since R918, R916, R913, R911, R909 and
        // R907, the issue-14 and issue-13 walks complete
    if (f14IssueElevenClosed() != 1
            || f14IssueTenClosed() != 1
            || f14IssueNineClosed() != 1
            || f14IssueEightClosed() != 1
            || f14IssueSevenClosed() != 1
            || f14IssueSixClosed() != 1
            || f14WalkFourteenComplete() != 1
            || f14WalkThirteenComplete() != 1
        )
            ++bad;
        // the registry ground truth carried forward - 1313 loaded / 1338 base
        // / 25 never-load, the issue-6 and issue-11 walks complete
    if (f14RegistryLoaded() != 1313
            || f14RegistryBaseLua() != 1338
            || f14RegistryNeverLoad() != 25
            || f14WalkSixComplete() != 1
            || f14WalkElevenComplete() != 1
        )
            ++bad;
        printf("R926 Dragon issue-14 closure audit: bad %d\n", bad);
        if (bad) return 1;
    }
