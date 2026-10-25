    // ---- R479 WSG plant lore pin audit ----
    // The proficiency in plant lore prose: a party venturing into the
    // wilderness without ready access to healing and curing magic, or
    // safeguarding against losing that aid along the way, has increased
    // chances of survival if it contains someone with the proficiency; such a
    // character cannot locate vegetation where it does not exist; but if
    // there is greenery to search through, a proficient character has a
    // greater chance of finding the type of plant desired - with the benefits
    // detailed in the Wilderness Proficiencies section.
    {
        using namespace rules;
        int bad = 0;
    if (!plrAidsPartySurvival()
            || !plrSafeguardsLostAid()
            || !plrNoVegetationNoFind()
            || !plrGreaterChanceInGreenery()
            || !plrBenefitsInWildernessProficiencies()
        )
            ++bad;
        printf("R479 WSG plant lore pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
