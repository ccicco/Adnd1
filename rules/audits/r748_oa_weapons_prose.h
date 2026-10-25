    // ---- R748 OA weapons prose audit ----
    // OA round one hundred thirty-five (capture p. 291): the Weapons section
    // prose - the Table III trigger, the Table 78 general type step, the
    // Table 79 property step, the Tables 80-85 specific type step,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dljGeneralTypeTable() != 78
            || dljPropertyTable() != 79
            || dljSpecificTableFirst() != 80
            || dljSpecificTableLast() != 85
            || !dljRolledOnTableIII()
            || !dljStepOneGeneralType()
            || !dljStepTwoProperty()
            || !dljStepThreeSpecificType()
        )
            ++bad;
        // the prose - the trigger and the three steps, healthy values, each
        // condition false
    if (dljRolledOnTableIII() != 1
            || dljStepOneGeneralType() != 1
            || dljStepTwoProperty() != 1
            || dljStepThreeSpecificType() != 1
        )
            ++bad;
        // the table numbers - the 78, 79, and the 80-85 range of the flow,
        // healthy values, each condition false
    if (dljGeneralTypeTable() != 78
            || dljPropertyTable() != 79
            || dljSpecificTableFirst() != 80
            || dljSpecificTableLast() != 85
        )
            ++bad;
        printf("R748 OA weapons prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
