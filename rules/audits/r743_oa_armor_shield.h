    // ---- R743 OA armor shield audit ----
    // OA round one hundred thirty (capture p. 289): the Armor and Shield
    // section prose - the DM roll-or-select freedom, the Table 75 first step
    // for the armor type, the Tables 76 and 77 second step for the
    // properties, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dleTypeTable() != 75
            || dlePropertyTableFirst() != 76
            || dlePropertyTableSecond() != 77
            || !dleDetermineTypeAndProperties()
            || !dleRollOrSelect()
            || !dleFirstStepRollTable75()
            || !dleThenRollTables76And77()
        )
            ++bad;
        // the prose - the determination and the two steps, healthy values,
        // each condition false
    if (dleDetermineTypeAndProperties() != 1
            || dleRollOrSelect() != 1
            || dleFirstStepRollTable75() != 1
            || dleThenRollTables76And77() != 1
        )
            ++bad;
        // the table numbers - the 75, 76, and 77 of the type and property
        // rolls, healthy values, each condition false
    if (dleTypeTable() != 75
            || dlePropertyTableFirst() != 76
            || dlePropertyTableSecond() != 77
        )
            ++bad;
        printf("R743 OA armor shield audit: bad %d\n", bad);
        if (bad) return 1;
    }
