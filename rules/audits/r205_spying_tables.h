    // ---- R205: the spying tables audit ----
    // DMG pp.19-20: the success table (spy level
    // 1-17 x the three categories), the mission
    // days, the discovery formula with the
    // precaution tiers, the failure bands with
    // the modifiers, the torture outcomes and
    // the fanatical rule.
    {
        Spying spying;
        int bad = 0;
        // the success table, all 51 cells
        static const int kS[17][3] = {
            { 50, 30, 10 },
            { 55, 35, 15 },
            { 60, 35, 15 },
            { 65, 40, 20 },
            { 70, 45, 25 },
            { 75, 50, 25 },
            { 80, 55, 30 },
            { 85, 60, 35 },
            { 85, 60, 40 },
            { 90, 65, 45 },
            { 90, 65, 50 },
            { 95, 65, 50 },
            { 95, 70, 50 },
            { 95, 70, 50 },
            { 95, 75, 50 },
            { 95, 75, 55 },
            { 95, 75, 60 },
        };
        for (int lvl = 1; lvl <= 17; ++lvl)
            for (int c = 0; c < 3; ++c)
                if (spying.spySuccessChance(lvl,
                        (SpyCategory)c)
                        != kS[lvl - 1][c]) ++bad;
        // the level clamps: 0 reads row 1, 18+ row 17
        if (spying.spySuccessChance(0, SPY_SIMPLE) != 50 ||
            spying.spySuccessChance(18, SPY_SIMPLE) != 95)
            ++bad;
        // the hired-spy level cap
        if (spying.spyHiredLevelCap() != 8) ++bad;
        // the mission days: simple 1-8, difficult 5-40,
        // extraordinary as required (0-0)
        int lo, hi;
        spying.spyMissionDays(SPY_SIMPLE, lo, hi);
        if (lo != 1 || hi != 8) ++bad;
        spying.spyMissionDays(SPY_DIFFICULT, lo, hi);
        if (lo != 5 || hi != 40) ++bad;
        spying.spyMissionDays(SPY_EXTRAORDINARY, lo, hi);
        if (lo != 0 || hi != 0) ++bad;
        // the discovery formula: cumulative 1 percent
        // per day capped at 10, minus the level, floor 1
        if (spying.spyModifiedDiscoveryChance(1, 0) != 1 ||
            spying.spyModifiedDiscoveryChance(3, 1) != 2 ||
            spying.spyModifiedDiscoveryChance(10, 3) != 7 ||
            spying.spyModifiedDiscoveryChance(30, 5) != 5 ||
            spying.spyModifiedDiscoveryChance(30, 12) != 1 ||
            spying.spyModifiedDiscoveryChance(0, 1) != 1) ++bad;
        // the precaution tiers: checks per week and the
        // percent each check reads (no precautions is a
        // flat 1 percent, the modified percent ignored)
        if (spying.spyPrecautionChecksPerWeek(
                SPYP_NONE) != 1 ||
            spying.spyPrecautionChecksPerWeek(
                SPYP_MINIMAL) != 1 ||
            spying.spyPrecautionChecksPerWeek(
                SPYP_MODERATE) != 2 ||
            spying.spyPrecautionChecksPerWeek(
                SPYP_STRONG) != 2) ++bad;
        if (spying.spyDiscoveryCheckPercent(
                SPYP_NONE, 7) != 1 ||
            spying.spyDiscoveryCheckPercent(
                SPYP_MINIMAL, 7) != 7 ||
            spying.spyDiscoveryCheckPercent(
                SPYP_MODERATE, 7) != 7 ||
            spying.spyDiscoveryCheckPercent(
                SPYP_STRONG, 7) != 14) ++bad;
        // the tenfold window: 20-50 days, x10
        if (spying.spyPostCaptureWindowLo() != 20 ||
            spying.spyPostCaptureWindowHi() != 50 ||
            spying.spyPostCaptureChanceMultiple() != 10)
            ++bad;
        // the failure bands: the five edges
        if (spying.spyFailureResult(1) != SPYF_RETRY ||
            spying.spyFailureResult(35) != SPYF_RETRY ||
            spying.spyFailureResult(36)
                != SPYF_COMPROMISED_90 ||
            spying.spyFailureResult(60)
                != SPYF_COMPROMISED_90 ||
            spying.spyFailureResult(61)
                != SPYF_IMPRISONED_SILENT ||
            spying.spyFailureResult(80)
                != SPYF_IMPRISONED_SILENT ||
            spying.spyFailureResult(81)
                != SPYF_CAUGHT_TORTURED ||
            spying.spyFailureResult(95)
                != SPYF_CAUGHT_TORTURED ||
            spying.spyFailureResult(96)
                != SPYF_KILLED_OR_TURNED ||
            spying.spyFailureResult(100)
                != SPYF_KILLED_OR_TURNED) ++bad;
        // the failure-score modifiers: difficult +10,
        // extraordinary -5, discovered +25
        if (spying.spyFailureScoreAdj(
                SPY_SIMPLE, false) != 0 ||
            spying.spyFailureScoreAdj(
                SPY_DIFFICULT, false) != 10 ||
            spying.spyFailureScoreAdj(
                SPY_EXTRAORDINARY, false) != -5 ||
            spying.spyFailureScoreAdj(
                SPY_DIFFICULT, true) != 35) ++bad;
        // the 36-60 band: 90 percent further failure
        if (spying.spyCompromisedFailChance() != 90) ++bad;
        // the torture outcomes: 1-2 dead, 3-4 revealed,
        // 5-6 turncoat
        if (spying.spyTortureOutcome(1) != SPYT_DEAD ||
            spying.spyTortureOutcome(2) != SPYT_DEAD ||
            spying.spyTortureOutcome(3)
                != SPYT_REVEALED ||
            spying.spyTortureOutcome(4)
                != SPYT_REVEALED ||
            spying.spyTortureOutcome(5)
                != SPYT_TURNCOAT ||
            spying.spyTortureOutcome(6)
                != SPYT_TURNCOAT) ++bad;
        // the fanatical rule: never a double agent;
        // any dice total over 60 is suicide
        if (!spying.spyFanaticalNeverDoubleAgent()) ++bad;
        if (spying.spyFanaticalSuicided(60)) ++bad;
        if (!spying.spyFanaticalSuicided(61)) ++bad;
        printf("R205 spying tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
