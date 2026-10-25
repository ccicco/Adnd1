    // ---- R519 DSG mining prospecting audit ----
    // The DSG mining opener pins the value of mined resources and the
    // miner-proficiency framework; the where-to-mine rules pin the
    // Wisdom-score find chance with the proficiency modifier, the no-yield
    // regions of deep sand or dirt and hardened lava with the stream-traces
    // exception, the post-search Proficiency Check over at least a week and
    // four miles square, the good conditions, the deep-snow impossibility,
    // the thin-snow double-or-triple, the adverse-condition time extensions,
    // the repeat-search ladder (-1 and twice the time, -2 and tripled, the
    // automatic failure past a point), and the success reading Table 30; and
    // the types-of-mines taxonomy pins the placer and tunnel split, the
    // excluded strip mining, the shallow-pan placer operation collecting the
    // eroded-vein wealth in the streambed without reaching a significant
    // lode, and the tunnel mine trading more work for much greater wealth
    // under rules that deal primarily with tunnel mining.
    {
        using namespace rules;
        int bad = 0;
    if (dnmSearchMinWeeks() != 1
            || dnmSearchAreaMilesSquare() != 4
            || dnmSecondSearchModifier() != 1
            || dnmSecondSearchTimeMult() != 2
            || dnmThirdSearchModifier() != 2
            || dnmThirdSearchTimeMult() != 3
            || !dnmMinedResourcesValuable()
            || !dnmMinerProficiencyFramework()
            || !dnmFindChanceIsWisScore()
            || !dnmNoYieldRegionsExist()
            || !dnmStreamTracesException()
            || !dnmCheckAfterThoroughSearch()
            || !dnmGoodConditionsRequired()
            || !dnmDeepSnowBlocksSearch()
            || !dnmThinSnowDoublesOrTriples()
            || !dnmAdverseConditionsDMExtends()
            || !dnmFailedSearchRepeatable()
            || !dnmAutoFailPastAPoint()
            || !dnmSuccessReadsTable30()
            || !dnmPlacerAndTunnelTypes()
            || !dnmStripMiningExcluded()
            || !dnmPlacerSiftingOperation()
            || !dnmPlacerStreambedCollection()
            || !dnmPlacerNotSignificantLode()
            || !dnmTunnelMoreWorkMoreWealth()
            || !dnmRulesPrimarilyTunnelMining()
        )
            ++bad;
        // the search scale: at least a week under good conditions, covering
        // about four miles square.
    if (dnmSearchMinWeeks() != 1
            || dnmSearchAreaMilesSquare() != 4
        )
            ++bad;
        // the repeat-search ladder: the second search at -1 and twice the
        // time, the third at -2 and tripled time, with corresponding
        // increases beyond.
    if (dnmSecondSearchModifier() != 1
            || dnmSecondSearchTimeMult() != 2
            || dnmThirdSearchModifier() != 2
            || dnmThirdSearchTimeMult() != 3
        )
            ++bad;
        printf("R519 DSG mining prospecting audit: bad %d\n", bad);
        if (bad) return 1;
    }
