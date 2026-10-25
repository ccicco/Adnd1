    // ---- R690 OA creating a style audit ----
    // OA round seventy-seven (capture pp. 225-227): the Creating a Style
    // doctrine - the three forms with the principal method, the Table 69
    // mechanics, the weapons roll and the Special Maneuvers intro,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djdOACreateACBase() != 10
            || djdOACreateWeaponsDie() != 4
            || djdOACreateWeaponsShift() != 2
            || djdOACreateManeuverFirstDie() != 8
            || djdOACreateManeuverSecondDie() != 3
            || !djdOACreateDoctrine()
            || !djdOACreateHardForm()
            || !djdOACreateSoftForm()
            || !djdOACreateCombinedForm()
            || !djdOACreateUnusualWeapons()
            || !djdOACreatePrincipalMethod()
            || !djdOACreateOtherMethods()
            || !djdOACreateOneFormOneMethod()
            || !djdOACreateAttacksStyleSpecific()
            || !djdOACreateDamageRounding()
            || !djdOACreateBodyPartFree()
            || !djdOACreateWeaponsList()
            || !djdOACreateManeuversLast()
            || !djdOAManeuversIntensiveStudy()
            || !djdOAManeuversCombatCost()
            || !djdOAManeuversMovementCost()
            || !djdOAManeuversMethodOrganized()
            || !djdOAManeuversSecondRollOthers()
            || !djdOAManeuversRanking()
            || !djdOAManeuversGradualLearning()
            || !djdOAMentalPhysicalAnyStyle()
        )
            ++bad;
        // the construction numbers - the AC base 10, the 1d4-minus-two
        // weapons, the 1d8 and 1-3 maneuver rolls
    if (djdOACreateACBase() != 10
            || djdOACreateWeaponsDie() != 4
            || djdOACreateWeaponsShift() != 2
        )
            ++bad;
        // the maneuver rolls - the 1d8 first with the 1-3 second
    if (djdOACreateManeuverFirstDie() != 8
            || djdOACreateManeuverSecondDie() != 3
        )
            ++bad;
        printf("R690 OA creating a style audit: bad %d\n", bad);
        if (bad) return 1;
    }
