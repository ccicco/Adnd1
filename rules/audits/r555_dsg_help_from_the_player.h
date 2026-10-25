    // ---- R555 DSG help from the players audit ----
    // The help from the players pins printed p. 113: the overburdened-DM
    // doctrine (the essential mystery, the frustrated DM and bored players,
    // the task nature by desires, maturity, and game type, the more-allowed
    // rule, the supervision spectrum), Rolling Up Player Characters (the
    // cooperative fun, the supervised rolls and the understood procedure, the
    // time gained, the novice teaching), Providing Ideas for Adventures (the
    // think-ahead category ask, the drow kingdom example, the advance
    // alignment, the live feedback), Character Class Responsibilities (the
    // cleric's donations and the thief's guild dues, the player bookkeeping,
    // the guildmaster investigations as encounters, the spell components and
    // the druid's mistletoe), and Controlling Henchmen, Hirelings, and other
    // NPCs (the player control, the takeover technique, the detailed
    // personas, the tracked Olaf of the Black Tooth, the player-stocked NPCs)
    // - ending at the MAPPING YOUR SETTINGS head.
    {
        using namespace rules;
        int bad = 0;
    if (!dchMysteryEssential()
            || !dchOverburdened()
            || !dchTaskNature()
            || !dchMoreAllowed()
            || !dchSupervision()
            || !dchRollingFun()
            || !dchRollingProcedure()
            || !dchRollingTimeGained()
            || !dchRollingNovices()
            || !dchIdeasThinkAhead()
            || !dchIdeasAskCategory()
            || !dchIdeasDrowExample()
            || !dchIdeasInAdvance()
            || !dchIdeasLiveFeedback()
            || !dchClassObligations()
            || !dchClassDonations()
            || !dchClassBookkeeping()
            || !dchClassInvestigations()
            || !dchClassComponents()
            || !dchHenchmenControl()
            || !dchHenchmenTakeover()
            || !dchHenchmenDetail()
            || !dchHenchmenTrack()
            || !dchHenchmenStocking()
        )
            ++bad;
        // the doctrine: the overburdened DM and the more-allowed rule.
    if (dchOverburdened() != 1
            || dchMoreAllowed() != 1
        )
            ++bad;
        // the rolling: the fun and the supervised procedure.
    if (dchRollingFun() != 1
            || dchRollingProcedure() != 1
        )
            ++bad;
        // the ideas: the category ask and the drow example.
    if (dchIdeasAskCategory() != 1
            || dchIdeasDrowExample() != 1
        )
            ++bad;
        // the ideas: the advance ask and the live feedback.
    if (dchIdeasInAdvance() != 1
            || dchIdeasLiveFeedback() != 1
        )
            ++bad;
        // the responsibilities: the donations and the components.
    if (dchClassDonations() != 1
            || dchClassComponents() != 1
        )
            ++bad;
        // the responsibilities: the investigations, not the bookkeeping.
    if (dchClassInvestigations() != 1
            || dchClassBookkeeping() != 1
        )
            ++bad;
        // the henchmen: the takeover technique and the detailing.
    if (dchHenchmenTakeover() != 1
            || dchHenchmenDetail() != 1
        )
            ++bad;
        // the henchmen: the tracked Olaf and the stocked NPCs.
    if (dchHenchmenTrack() != 1
            || dchHenchmenStocking() != 1
        )
            ++bad;
        printf("R555 DSG help from the players audit: bad %d\n", bad);
        if (bad) return 1;
    }
