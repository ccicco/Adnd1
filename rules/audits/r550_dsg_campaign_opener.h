    // ---- R550 DSG campaign opener audit ----
    // The DSG campaign considerations opener pins printed pp. 99-100: the
    // chapter frame (the myriad campaign ingredients, the skilled DM first
    // and the willing players next, the type mismatch warning), the three
    // player types (the Adventurers with combat above all and treasure as
    // motivation, the Problem-Solvers with the twisted-plot puzzle frame, the
    // Role-Players with total character detail and the shopping haggling),
    // Challenges for the DM (the blend and the all-three-served rule), the
    // Fine Art of Juggling (the feedback key, the dying-clue encounter
    // juggle, the per-style rewards), Designing the Adventure and the World
    // (the settings-and-story ingredients, the deferred detail, the
    // preparation payoff), and Worlds of Adventure (the scope first, the
    // surface-minimal rule, the race-placement discipline, the clear-split vs
    // complex social structures).
    {
        using namespace rules;
        int bad = 0;
    if (dccPlayerTypes() != 3
            || !dccIngredientsMyriad()
            || !dccSkilledDMFirst()
            || !dccWillingPlayersNext()
            || !dccTypeMismatch()
            || !dccCombatSupreme()
            || !dccPhysicalObstacles()
            || !dccMagicBonusJudge()
            || !dccQuickReplacement()
            || !dccTreasureDraws()
            || !dccEasiestToDM()
            || !dccMonsterIntelligence()
            || !dccItemDiscipline()
            || !dccPlanningGatesSuccess()
            || !dccNoInstantDeath()
            || !dccVeteranReturn()
            || !dccPuzzleFrame()
            || !dccConvolutionBest()
            || !dccTacticalBattles()
            || !dccRulesCreativity()
            || !dccRoutineBoredom()
            || !dccChallengeBalance()
            || !dccBorrowFreely()
            || !dccMotivationToolkit()
            || !dccMysteryStory()
            || !dccTotalDetail()
            || !dccShoppingRoleplay()
            || !dccGrowthFrame()
            || !dccBelievableFaults()
            || !dccInteractionTalk()
            || !dccPersonalStakes()
            || !dccValueHooks()
            || !dccBlendTypical()
            || !dccAllThreeServed()
            || !dccTypeTailoredFun()
            || !dccMixedJuggling()
            || !dccFeedbackKey()
            || !dccRestlessRandom()
            || !dccDyingClue()
            || !dccTalkRegularly()
            || !dccBoredomSignal()
            || !dccRewardEachStyle()
            || !dccSmoothAllThree()
            || !dccTwoIngredients()
            || !dccSettingDefinition()
            || !dccDeferredDetail()
            || !dccStorySketch()
            || !dccNoAdvanceRequirement()
            || !dccPrepPays()
            || !dccAnticipatedStability()
            || !dccUniqueCreation()
            || !dccScopeFirst()
            || !dccSurfaceMinimal()
            || !dccRelationshipScope()
            || !dccConsistentCaptives()
            || !dccPlacementDeferred()
            || !dccRacesAddLater()
            || !dccRemovalHard()
            || !dccSocialThought()
            || !dccClearSplitEasy()
            || !dccComplexRealistic()
        )
            ++bad;
        // the three general types: Adventurers, Problem Solvers,
        // Role-Players.
    if (dccPlayerTypes() != 3
        )
            ++bad;
        // the Adventurer frame: combat above all, treasure as the draw, the
        // easiest to DM for.
    if (dccCombatSupreme() != 1
            || dccTreasureDraws() != 1
            || dccEasiestToDM() != 1
        )
            ++bad;
        // the Problem-Solver frame: the puzzle, the convoluted plot, the
        // mystery story line.
    if (dccPuzzleFrame() != 1
            || dccConvolutionBest() != 1
            || dccMysteryStory() != 1
        )
            ++bad;
        // the Role-Player frame: the shopping haggling, the believability
        // faults, the value hooks.
    if (dccShoppingRoleplay() != 1
            || dccBelievableFaults() != 1
            || dccValueHooks() != 1
        )
            ++bad;
        // the juggling keys: feedback, and rewards for each style of play.
    if (dccFeedbackKey() != 1
            || dccRewardEachStyle() != 1
        )
            ++bad;
        // the designing frame: settings and story line, the scope determined
        // first.
    if (dccTwoIngredients() != 1
            || dccScopeFirst() != 1
        )
            ++bad;
        // the social-structure split: the clear good/evil ease against the
        // complex realistic societies.
    if (dccClearSplitEasy() != 1
            || dccComplexRealistic() != 1
        )
            ++bad;
        printf("R550 DSG campaign opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
