    // ---- R554 DSG story design techniques audit ----
    // The techniques of story and campaign design pins printed pp. 109-112:
    // the chapter head (the story line chosen shapes the gaming environment,
    // three types of adventure design), The Linear Adventure (the
    // certain-order encounters, the dungeon one-route maps, the outdoor
    // thorn-wall obstacles, the no-wasted-design advantage, the
    // high-level-magic difficulty, the tournament fit, the railroad
    // frustration, the illusion of choice), The Open Campaign (the
    // player-choice doctrine, the seeded countryside, the Adventurer fun, the
    // Problem-Solver and Role-Player workload, the world built over time, the
    // story-structure difficulty, the perverse players, the Events technique,
    // the ask-ahead shortcut, the background conflicts), The Matrix Campaign
    // (the goal-driven compromise, the evil-cleric exposition, the guided
    // options, the prepared courses, the expanding branches, the plot events,
    // the soft and hard borders, the multiple paths to the climax, the lost
    // players, the foreshadowed track), the Running the Game head (the two
    // at-table functions), Preparing For Play (the random-generation lists,
    // the coded notes, the THACO shorthand, the map symbols, the anticipated
    // surprises, the treasure decisions), and The Dungeon Master as Master
    // Storyteller (the pace doctrine, the optional systems, the voice - tone,
    // volume, rate - and the word choice and NPC voices).
    {
        using namespace rules;
        int bad = 0;
    if (dcgNPCNameTable() != 8
            || dcgNPCNameDie() != 8
            || dcgOgreTHACO() != 15
            || !dcgLinearDefines()
            || !dcgLinearDungeons()
            || !dcgLinearOutdoor()
            || !dcgLinearNoWaste()
            || !dcgLinearMagicPower()
            || !dcgLinearTournament()
            || !dcgLinearUndesirable()
            || !dcgLinearIllusion()
            || !dcgOpenDefines()
            || !dcgOpenPrep()
            || !dcgOpenAdventurers()
            || !dcgOpenMentalDiet()
            || !dcgOpenWorldBuilding()
            || !dcgOpenStoryHard()
            || !dcgOpenPerverse()
            || !dcgOpenEvents()
            || !dcgOpenAskPlayers()
            || !dcgOpenBackgroundConflicts()
            || !dcgMatrixDefines()
            || !dcgMatrixGoals()
            || !dcgMatrixExposition()
            || !dcgMatrixGuidance()
            || !dcgMatrixPrepared()
            || !dcgMatrixExpand()
            || !dcgMatrixBranches()
            || !dcgMatrixPlotEvents()
            || !dcgMatrixBorders()
            || !dcgMatrixSoftBorder()
            || !dcgMatrixHardBorder()
            || !dcgMatrixMultiplePaths()
            || !dcgMatrixLostPlayers()
            || !dcgMatrixForeshadowTrack()
            || !dcgRunningDefines()
            || !dcgPrepSmoother()
            || !dcgPrepLists()
            || !dcgPrepCodedNotes()
            || !dcgPrepTHACO()
            || !dcgPrepMapSymbols()
            || !dcgPrepSurprises()
            || !dcgPrepTreasure()
            || !dcgStorytellerDefines()
            || !dcgStorytellerPrinciples()
            || !dcgPaceDefines()
            || !dcgPaceVariety()
            || !dcgPaceDiscardRules()
            || !dcgPaceOptionalSystems()
            || !dcgPacePreparation()
            || !dcgPaceRulesReview()
            || !dcgVoicePrimary()
            || !dcgVoiceTone()
            || !dcgVoiceVolume()
            || !dcgVoiceRate()
            || !dcgWordChoice()
            || !dcgNPCVoices()
        )
            ++bad;
        // the NPC list: eight names, rolled on 1d8.
    if (dcgNPCNameTable() != 8
            || dcgNPCNameDie() != 8
        )
            ++bad;
        // the THACO example: the ogre hits AC 0 on a 15.
    if (dcgOgreTHACO() != 15
        )
            ++bad;
        // the THACO arithmetic: AC 6 hit on 9, AC -4 hit on 19.
    if (dcgOgreTHACO() - 6 != 9
            || dcgOgreTHACO() - -4 != 19
        )
            ++bad;
        // the linear design: the tournament fit and the illusion of choice.
    if (dcgLinearTournament() != 1
            || dcgLinearIllusion() != 1
        )
            ++bad;
        // the open campaign: the events technique and the background
        // conflicts.
    if (dcgOpenEvents() != 1
            || dcgOpenBackgroundConflicts() != 1
        )
            ++bad;
        // the matrix: the soft and hard borders.
    if (dcgMatrixSoftBorder() != 1
            || dcgMatrixHardBorder() != 1
        )
            ++bad;
        // the preparation: the anticipated surprises and the treasure
        // decisions.
    if (dcgPrepSurprises() != 1
            || dcgPrepTreasure() != 1
        )
            ++bad;
        // the storyteller craft: the colorful words and the NPC voices.
    if (dcgWordChoice() != 1
            || dcgNPCVoices() != 1
        )
            ++bad;
        printf("R554 DSG story design techniques audit: bad %d\n", bad);
        if (bad) return 1;
    }
