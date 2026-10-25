    // ---- R695 OA learning martial arts audit ----
    // OA round eighty-two (capture pp. 233-235): the Learning Martial Arts
    // prose - the master search, the acceptance and challenge routes, the
    // study obligations and proficiency slot costs - with the Multiple Styles
    // and Combining Styles rules, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djiAcceptBasePct() != 10
            || djiAcceptGiftPct() != 10
            || djiStudyMinMonths() != 1
            || djiPracticeHoursPerDay() != 1
            || djiMasterHoursPerWeek() != 6
            || djiSlotsPerManeuver() != 1
            || djiMaxSlotsPerLevel() != 2
            || djiStylesKnownMin() != 2
            || !djiMasterHonoraryTitle()
            || !djiMasterAnywhere()
            || !djiMasterSecretive()
            || !djiOffendNeverAccepted()
            || !djiChallengeAutoAccepted()
            || !djiStudentIfUnknown()
            || !djiChallengeSubduePreferred()
            || !djiChallengeWinAccepted()
            || !djiChallengeLoseOptions()
            || !djiMasterBasicsAuto()
            || !djiMasterWeaponsDie()
            || !djiMasterManeuversDie()
            || !djiMasterNeverIncreases()
            || !djiBasicsSlotGrant()
            || !djiObligationGate()
            || !djiManeuverPracticeAssumed()
            || !djiLearnAllNewMaster()
            || !djiMultipleStylesAllowed()
            || !djiOneStylePerFight()
            || !djiConstantManeuversException()
            || !djiStyleChangePerRound()
            || !djiCombineUniqueStyle()
            || !djiCombineElements()
            || !djiCombineTeachAsMaster()
        )
            ++bad;
        // the acceptance percentages - the 10 base and the 10 per gift
    if (djiAcceptBasePct() != 10
            || djiAcceptGiftPct() != 10
        )
            ++bad;
        // the study obligations - one month, one hour a day, six hours a week
    if (djiStudyMinMonths() != 1
            || djiPracticeHoursPerDay() != 1
            || djiMasterHoursPerWeek() != 6
        )
            ++bad;
        // the slot costs - one per maneuver, two per style per level the cap
    if (djiSlotsPerManeuver() != 1
            || djiMaxSlotsPerLevel() != 2
        )
            ++bad;
        // the combining threshold - two or more styles
    if (djiStylesKnownMin() != 2
        )
            ++bad;
        printf("R695 OA learning martial arts audit: bad %d\n", bad);
        if (bad) return 1;
    }
