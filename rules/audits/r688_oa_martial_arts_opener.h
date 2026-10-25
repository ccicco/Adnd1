    // ---- R688 OA martial arts opener audit ----
    // OA round seventy-five (capture pp. 223-224): the Martial Arts opener -
    // the doctrine frame with the three reason strands, the regularized art,
    // the style proliferation and the five style characteristics, single-pass
    // pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djbOAMartialStyleChars() != 5
            || !djbOAMartialArtsDoctrine()
            || !djbOAMartialWholeBodyWeapon()
            || !djbOAMartialTrainingDiscipline()
            || !djbOAMartialNaturePhilosophy()
            || !djbOAMartialReligiousDivestment()
            || !djbOAMartialSocialPressure()
            || !djbOAMartialRegularizedArt()
            || !djbOAMartialStyleProliferation()
            || !djbOAMartialSchoolChallenges()
            || !djbOAMartialPrimaryGoalAvoidHurt()
            || !djbOAMartialDefensiveStyles()
            || !djbOAMartialAggressiveStyles()
            || !djbOAMartialWeaponMasterStyles()
            || !djbOAMartialFormsVariety()
            || !djbOAMartialUnarmedMisnomer()
            || !djbOAMartialRulesFit()
            || !djbOAMartialStyleNames()
            || !djbOAMartialStyleUseIdentity()
        )
            ++bad;
        // the style characteristics pin - the five elements forming a style
    if (djbOAMartialStyleChars() != 5
        )
            ++bad;
        printf("R688 OA martial arts opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
