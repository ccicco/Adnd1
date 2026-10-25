    // ---- R600 DMO maxims audit ----
    // THE REMAINING FIVE MAXIMS of DMO Chapter 1 (pp. 10-29), the doctrine
    // round closing the chapter: the intelligent-adversary doctrines (the
    // intelligence review, the weakness shielding, the strength maximization,
    // the handling-defeat ladder with its four options), the villain
    // self-preservation doctrines (the villain-absence rule, the
    // bad-guys-don't-fight-fair rules), the control-magic doctrines (the AC
    // -4 tension floor, the memorization economics, the no-magic-shops
    // doctrine), the plan-ahead doctrines (the growing villain, the
    // consequences ladder, the fame ledger), and the share-responsibility
    // doctrines (the player-DM split, the goals, the personality profile).
    {
        using namespace rules;
        int bad = 0;
    if (dejDefeatOptionCount() != 4
            || dejEscapeGoalCount() != 3
            || dejTrollRegenDelayRounds() != 3
            || dejTrollWeaponDamageBonus() != 8
            || dejTensionAcFloor() != -4
            || dejBracersAc2Bonus() != 8
            || dejWizardStudyHours() != 18
            || dejWizardCastMinutes() != 37
            || dejTeleportMemorizeMinutes() != 50
            || dejTeleportMinorPct() != 2
            || dejTeleportFatalPct() != 1
            || dejPartyItemPerAdventure() != 1
            || !dejIntelligenceDoctrine()
            || !dejWeaknessShielding()
            || !dejStrengthMaximization()
            || !dejHandlingDefeat()
            || !dejLeavingFieldDoctrine()
            || !dejReversalDoctrine()
            || !dejVillainSelfPreservation()
            || !dejBadGuysDontFightFair()
            || !dejControlMagicDoctrine()
            || !dejMagicItemUseDoctrine()
            || !dejMagicShopsDoctrine()
            || !dejMagicLimitationDoctrine()
            || !dejPlanAheadDoctrine()
            || !dejConsequencesDoctrine()
            || !dejFameInfamyDoctrine()
            || !dejBalancingActDoctrine()
            || !dejShareResponsibilityDoctrine()
        )
            ++bad;
        // the dejDefeatOptionCount pin
    if (dejDefeatOptionCount() != 4
        )
            ++bad;
        // the dejEscapeGoalCount pin
    if (dejEscapeGoalCount() != 3
        )
            ++bad;
        // the dejTrollRegenDelayRounds pin
    if (dejTrollRegenDelayRounds() != 3
        )
            ++bad;
        // the dejTrollWeaponDamageBonus pin
    if (dejTrollWeaponDamageBonus() != 8
        )
            ++bad;
        // the dejTensionAcFloor pin
    if (dejTensionAcFloor() != -4
        )
            ++bad;
        // the dejBracersAc2Bonus pin
    if (dejBracersAc2Bonus() != 8
        )
            ++bad;
        // the dejWizardStudyHours pin
    if (dejWizardStudyHours() != 18
        )
            ++bad;
        // the dejWizardCastMinutes pin
    if (dejWizardCastMinutes() != 37
        )
            ++bad;
        // the dejTeleportMemorizeMinutes pin
    if (dejTeleportMemorizeMinutes() != 50
        )
            ++bad;
        // the dejTeleportMinorPct pin
    if (dejTeleportMinorPct() != 2
        )
            ++bad;
        // the dejTeleportFatalPct pin
    if (dejTeleportFatalPct() != 1
        )
            ++bad;
        // the dejPartyItemPerAdventure pin
    if (dejPartyItemPerAdventure() != 1
        )
            ++bad;
        // the dejIntelligenceDoctrine pin
    if (dejIntelligenceDoctrine() != 1
        )
            ++bad;
        // the dejWeaknessShielding pin
    if (dejWeaknessShielding() != 1
        )
            ++bad;
        // the dejStrengthMaximization pin
    if (dejStrengthMaximization() != 1
        )
            ++bad;
        // the dejHandlingDefeat pin
    if (dejHandlingDefeat() != 1
        )
            ++bad;
        // the dejLeavingFieldDoctrine pin
    if (dejLeavingFieldDoctrine() != 1
        )
            ++bad;
        // the dejReversalDoctrine pin
    if (dejReversalDoctrine() != 1
        )
            ++bad;
        // the dejVillainSelfPreservation pin
    if (dejVillainSelfPreservation() != 1
        )
            ++bad;
        // the dejBadGuysDontFightFair pin
    if (dejBadGuysDontFightFair() != 1
        )
            ++bad;
        // the dejControlMagicDoctrine pin
    if (dejControlMagicDoctrine() != 1
        )
            ++bad;
        // the dejMagicItemUseDoctrine pin
    if (dejMagicItemUseDoctrine() != 1
        )
            ++bad;
        // the dejMagicShopsDoctrine pin
    if (dejMagicShopsDoctrine() != 1
        )
            ++bad;
        // the dejMagicLimitationDoctrine pin
    if (dejMagicLimitationDoctrine() != 1
        )
            ++bad;
        // the dejPlanAheadDoctrine pin
    if (dejPlanAheadDoctrine() != 1
        )
            ++bad;
        // the dejConsequencesDoctrine pin
    if (dejConsequencesDoctrine() != 1
        )
            ++bad;
        // the dejFameInfamyDoctrine pin
    if (dejFameInfamyDoctrine() != 1
        )
            ++bad;
        // the dejBalancingActDoctrine pin
    if (dejBalancingActDoctrine() != 1
        )
            ++bad;
        // the dejShareResponsibilityDoctrine pin
    if (dejShareResponsibilityDoctrine() != 1
        )
            ++bad;
        printf("R600 DMO maxims audit: bad %d\n", bad);
        if (bad) return 1;
    }
