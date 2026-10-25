    // ---- R562 DSG intro frame audit ----
    // the printed p. 6 chapter frame: the mystery of the underdark (the
    // sunless realms question), the new rules for underground play (the
    // non-thief climbing, the Oriental Adventures proficiencies), the
    // denizens (the four named cultures, the random generators), the
    // underground campaign (the DM half, the 3-D mapping, the story
    // conflicts) and the using-this-information player/DM split with the
    // Forbidden Territory.
    {
        using namespace rules;
        int bad = 0;
    if (dcqFramePage() != 6
            || dcqNamedCultureCount() != 4
            || dcqSectionCount() != 2
            || dcqPlayerLureCount() != 3
            || !dcqNonthiefClimbCovered()
            || !dcqProficienciesFromOA()
            || !dcqRandomGenerators()
            || !dcqForbiddenDMHalf()
        )
            ++bad;
        // the frame chapter at printed p. 6
    if (dcqFramePage() != 6
        )
            ++bad;
        // the four named denizen cultures
    if (dcqNamedCultureCount() != 4
        )
            ++bad;
        // the two player/DM sections
    if (dcqSectionCount() != 2
        )
            ++bad;
        // the three subterranean lures
    if (dcqPlayerLureCount() != 3
        )
            ++bad;
        // the non-thief wall and footbridge rules
    if (dcqNonthiefClimbCovered() != 1
        )
            ++bad;
        // the Oriental Adventures proficiency origin
    if (dcqProficienciesFromOA() != 1
        )
            ++bad;
        // the random generators with no prep time
    if (dcqRandomGenerators() != 1
        )
            ++bad;
        // the DM-only Forbidden Territory
    if (dcqForbiddenDMHalf() != 1
        )
            ++bad;
        printf("R562 DSG intro frame audit: bad %d\n", bad);
        if (bad) return 1;
    }
