    // ---- R771 OA open boxes audit ----
    // OA round one hundred fifty-eight (capture p. 253): the open-boxes sweep
    // - the Celestial Emperor and the Celestial Bureaucracy spirit-world
    // framing doctrine, with the eight missed chapter parents of Chapters 2,
    // 3, 8, 9, 10, 11, 12, and 13 closed; the Weapons prose box stays open
    // for its own arc, single-pass pins per the R679 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dnhBureaucracyDutiesCount() != 3
            || dnhSpiritOfficialCharacterCount() != 4
            || !dnhUnifiedWholeDoctrine()
            || !dnhEmperorHeadsBureaucracy()
            || !dnhSpiritsHoldOffices()
            || !dnhChasingLungRainDuty()
            || !dnhMinistryOfThunderChain()
            || !dnhOfficialsLikeRealBureaucrats()
            || !dnhAnnualExamination()
        )
            ++bad;
        // the unified whole example
    if (dnhUnifiedWholeDoctrine() != 1
            || dnhEmperorHeadsBureaucracy() != 1
        )
            ++bad;
        // the offices example
    if (dnhBureaucracyDutiesCount() != 3
            || dnhSpiritsHoldOffices() != 1
        )
            ++bad;
        // the chain example
    if (dnhChasingLungRainDuty() != 1
            || dnhMinistryOfThunderChain() != 1
        )
            ++bad;
        // the character example
    if (dnhSpiritOfficialCharacterCount() != 4
            || dnhOfficialsLikeRealBureaucrats() != 1
        )
            ++bad;
        // the examination example
    if (dnhAnnualExamination() != 1
        )
            ++bad;
        printf("R771 OA open boxes audit: bad %d\n", bad);
        if (bad) return 1;
    }
