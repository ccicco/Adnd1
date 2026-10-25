    // ---- R552 DSG plot and counterplot audit ----
    // The plot and counterplot pins printed pp. 103-106: the chapter head
    // (the story as important as the world setting, the DM as bard), the
    // story structure (exposition, development, climax, denouement), the
    // exposition techniques (the information cards, the combat opener, the
    // advance information), the development craft (the minion encounters, the
    // noncombat prods, the random-encounter balance, the semi-climax), the
    // climax doctrine (game balance, the deadly potential, the adversary
    // tactics, the emergency escape route, the staging), the denouement (the
    // loose ends, the next-adventure lead), Multiple Story Lines (the epic
    // form, the 3-4-session major objectives, the rare cliffhanger), and the
    // Story Elements head with the Villains (the hierarchy, the
    // familiarization, the surviving villain) and the Foreshadowing opener.
    {
        using namespace rules;
        int bad = 0;
    if (dceObjectiveSessionsMin() != 3
            || dceObjectiveSessionsMax() != 4
            || dceEpicRefreshYears() != 1
            || !dceStoryEqualWorld()
            || !dceDMAsBard()
            || !dceStructureAncient()
            || !dceExpositionDefines()
            || !dceDevelopmentTension()
            || !dceClimaxDefines()
            || !dceDenouementDefines()
            || !dceAllElementsPresent()
            || !dceSpeechMistake()
            || !dceActOutEncounter()
            || !dceHandouts()
            || !dceInvolvementBeatsPassive()
            || !dceInformationCards()
            || !dceCombatOpener()
            || !dceCombatBeforeSpeech()
            || !dceAdvanceInformation()
            || !dceDevelopmentLongest()
            || !dceMinionsTeach()
            || !dceNoncombatProds()
            || !dceRandomBalance()
            || !dceSemimax()
            || !dceBalancePrimary()
            || !dceMentalPhysical()
            || !dceDeadlyPotential()
            || !dceAdversaryTactics()
            || !dceEscapingVillain()
            || !dceMultipleSolutions()
            || !dceStagingDrama()
            || !dceDramatic()
            || !dceLooseEnds()
            || !dceSafety()
            || !dceNextAdventure()
            || !dceMultipleLines()
            || !dceEpicForm()
            || !dceEpicGood()
            || !dceEpicYears()
            || !dceEpicMomentum()
            || !dceCliffhangerRare()
            || !dcePeriodicChanges()
            || !dceAntagonistAnyForce()
            || !dceUnintelligentFoes()
            || !dceMinimalIntelligence()
            || !dceVillainHierarchy()
            || !dceUniqueVillains()
            || !dceFamiliarization()
            || !dcePersonalConfrontation()
            || !dceBuffoon()
            || !dceMainVillainPower()
            || !dceVillainSurvives()
            || !dceForeshadowDefines()
            || !dceForeshadowWarning()
            || !dceForeshadowPuzzlers()
        )
            ++bad;
        // the epic cadence: a major objective accomplished every 3-4
        // sessions.
    if (dceObjectiveSessionsMin() != 3
            || dceObjectiveSessionsMax() != 4
        )
            ++bad;
        // the periodic changes: a new epic every year or so.
    if (dceEpicRefreshYears() != 1
        )
            ++bad;
        // the structure: exposition, climax, denouement defined.
    if (dceExpositionDefines() != 1
            || dceClimaxDefines() != 1
            || dceDenouementDefines() != 1
        )
            ++bad;
        // the exposition craft: the speech mistake, the combat opener, the
        // cards.
    if (dceSpeechMistake() != 1
            || dceCombatOpener() != 1
            || dceInformationCards() != 1
        )
            ++bad;
        // the climax doctrine: balance, deadly potential, multiple solutions.
    if (dceBalancePrimary() != 1
            || dceDeadlyPotential() != 1
            || dceMultipleSolutions() != 1
        )
            ++bad;
        // the surviving villain: the escape route and the returning foe.
    if (dceEscapingVillain() != 1
            || dceVillainSurvives() != 1
        )
            ++bad;
        // the epic: the form, the rare cliffhanger.
    if (dceEpicForm() != 1
            || dceCliffhangerRare() != 1
        )
            ++bad;
        // the story elements: the villain hierarchy, the warning foreshadow.
    if (dceVillainHierarchy() != 1
            || dceForeshadowWarning() != 1
        )
            ++bad;
        printf("R552 DSG plot and counterplot audit: bad %d\n", bad);
        if (bad) return 1;
    }
