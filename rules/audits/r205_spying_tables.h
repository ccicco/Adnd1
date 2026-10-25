    // ---- R205: the spying tables audit ----
    // DMG pp.19-20: the success table (spy level
    // 1-17 x the three categories), the mission
    // days, the discovery formula with the
    // precaution tiers, the failure bands with
    // the modifiers, the torture outcomes and
    // the fanatical rule.
    {
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
                if (rules::spySuccessChance(lvl,
                        (rules::SpyCategory)c)
                        != kS[lvl - 1][c]) ++bad;
        // the level clamps: 0 reads row 1, 18+ row 17
        if (rules::spySuccessChance(0, rules::SPY_SIMPLE) != 50 ||
            rules::spySuccessChance(18, rules::SPY_SIMPLE) != 95)
            ++bad;
        // the hired-spy level cap
        if (rules::spyHiredLevelCap() != 8) ++bad;
        // the mission days: simple 1-8, difficult 5-40,
        // extraordinary as required (0-0)
        int lo, hi;
        rules::spyMissionDays(rules::SPY_SIMPLE, lo, hi);
        if (lo != 1 || hi != 8) ++bad;
        rules::spyMissionDays(rules::SPY_DIFFICULT, lo, hi);
        if (lo != 5 || hi != 40) ++bad;
        rules::spyMissionDays(rules::SPY_EXTRAORDINARY, lo, hi);
        if (lo != 0 || hi != 0) ++bad;
        // the discovery formula: cumulative 1 percent
        // per day capped at 10, minus the level, floor 1
        if (rules::spyModifiedDiscoveryChance(1, 0) != 1 ||
            rules::spyModifiedDiscoveryChance(3, 1) != 2 ||
            rules::spyModifiedDiscoveryChance(10, 3) != 7 ||
            rules::spyModifiedDiscoveryChance(30, 5) != 5 ||
            rules::spyModifiedDiscoveryChance(30, 12) != 1 ||
            rules::spyModifiedDiscoveryChance(0, 1) != 1) ++bad;
        // the precaution tiers: checks per week and the
        // percent each check reads (no precautions is a
        // flat 1 percent, the modified percent ignored)
        if (rules::spyPrecautionChecksPerWeek(
                rules::SPYP_NONE) != 1 ||
            rules::spyPrecautionChecksPerWeek(
                rules::SPYP_MINIMAL) != 1 ||
            rules::spyPrecautionChecksPerWeek(
                rules::SPYP_MODERATE) != 2 ||
            rules::spyPrecautionChecksPerWeek(
                rules::SPYP_STRONG) != 2) ++bad;
        if (rules::spyDiscoveryCheckPercent(
                rules::SPYP_NONE, 7) != 1 ||
            rules::spyDiscoveryCheckPercent(
                rules::SPYP_MINIMAL, 7) != 7 ||
            rules::spyDiscoveryCheckPercent(
                rules::SPYP_MODERATE, 7) != 7 ||
            rules::spyDiscoveryCheckPercent(
                rules::SPYP_STRONG, 7) != 14) ++bad;
        // the tenfold window: 20-50 days, x10
        if (rules::spyPostCaptureWindowLo() != 20 ||
            rules::spyPostCaptureWindowHi() != 50 ||
            rules::spyPostCaptureChanceMultiple() != 10)
            ++bad;
        // the failure bands: the five edges
        if (rules::spyFailureResult(1) != rules::SPYF_RETRY ||
            rules::spyFailureResult(35) != rules::SPYF_RETRY ||
            rules::spyFailureResult(36)
                != rules::SPYF_COMPROMISED_90 ||
            rules::spyFailureResult(60)
                != rules::SPYF_COMPROMISED_90 ||
            rules::spyFailureResult(61)
                != rules::SPYF_IMPRISONED_SILENT ||
            rules::spyFailureResult(80)
                != rules::SPYF_IMPRISONED_SILENT ||
            rules::spyFailureResult(81)
                != rules::SPYF_CAUGHT_TORTURED ||
            rules::spyFailureResult(95)
                != rules::SPYF_CAUGHT_TORTURED ||
            rules::spyFailureResult(96)
                != rules::SPYF_KILLED_OR_TURNED ||
            rules::spyFailureResult(100)
                != rules::SPYF_KILLED_OR_TURNED) ++bad;
        // the failure-score modifiers: difficult +10,
        // extraordinary -5, discovered +25
        if (rules::spyFailureScoreAdj(
                rules::SPY_SIMPLE, false) != 0 ||
            rules::spyFailureScoreAdj(
                rules::SPY_DIFFICULT, false) != 10 ||
            rules::spyFailureScoreAdj(
                rules::SPY_EXTRAORDINARY, false) != -5 ||
            rules::spyFailureScoreAdj(
                rules::SPY_DIFFICULT, true) != 35) ++bad;
        // the 36-60 band: 90 percent further failure
        if (rules::spyCompromisedFailChance() != 90) ++bad;
        // the torture outcomes: 1-2 dead, 3-4 revealed,
        // 5-6 turncoat
        if (rules::spyTortureOutcome(1) != rules::SPYT_DEAD ||
            rules::spyTortureOutcome(2) != rules::SPYT_DEAD ||
            rules::spyTortureOutcome(3)
                != rules::SPYT_REVEALED ||
            rules::spyTortureOutcome(4)
                != rules::SPYT_REVEALED ||
            rules::spyTortureOutcome(5)
                != rules::SPYT_TURNCOAT ||
            rules::spyTortureOutcome(6)
                != rules::SPYT_TURNCOAT) ++bad;
        // the fanatical rule: never a double agent;
        // any dice total over 60 is suicide
        if (!rules::spyFanaticalNeverDoubleAgent()) ++bad;
        if (rules::spyFanaticalSuicided(60)) ++bad;
        if (!rules::spyFanaticalSuicided(61)) ++bad;
        printf("R205 spying tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
