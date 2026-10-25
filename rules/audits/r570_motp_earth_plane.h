    // ---- R570 MotP Earth plane audit ----
    // the Plane of Elemental Earth, printed pp. 41-46, the whole chapter: the
    // least-hospitable doctrine (the solid wall - air, water and fire part
    // but earth does not), the four border gradations (Magma, Ooze, Minerals,
    // Dust), the 1d2-per-turn pressure, no atmosphere outside pockets, blind
    // but 6-inch hearing through stone, the Strength 15/18/19/23 brute-force
    // ladder at one foot per turn, the 1-in-10-per-four-hours check, the d12
    // phenomena (the d10 earthquake severity tiers 4d6/6d6/8d6, the inhabited
    // fault lines, the 60/40 gas pockets, the mineral veins, the fossils with
    // the 31-90 human band and the 20% mineralization), the d20 pocket table
    // with the 80% air pockets, the native passwall and AC-2 mimic rules, the
    // magic range rule, and the features (Ogremoch's vacuum-mesa citadel,
    // Grumbar the mountain-juggernaut, the dao mazeworks and the Great Dismal
    // Delve, the silver doorways and angular bubbles).
    {
        using namespace rules;
        int bad = 0;
    if (dcyEarthPressureDie() != 2
            || dcyEarthEncounterDenom() != 10
            || dcyEarthQuakeSeverityDie() != 10
            || dcyEarthGasPoisonPct() != 60
            || dcyEarthFossilHumanPct() != 31
            || dcyEarthStrengthSoft() != 15
            || dcyEarthAirPocketOccPct() != 80
            || dcyEarthHearingInches() != 6
            || !dcyEarthSolidWall()
            || !dcyEarthBordersGrade()
            || !dcyEarthNativePasswall()
            || !dcyEarthMagicRangeRule()
            || !dcyEarthNativeEarthImmunity()
            || !dcyEarthSilverDoorway()
        )
            ++bad;
        // the EarthPressureDie pin
    if (dcyEarthPressureDie() != 2
        )
            ++bad;
        // the EarthEncounterDenom pin
    if (dcyEarthEncounterDenom() != 10
        )
            ++bad;
        // the EarthQuakeSeverityDie pin
    if (dcyEarthQuakeSeverityDie() != 10
        )
            ++bad;
        // the EarthGasPoisonPct pin
    if (dcyEarthGasPoisonPct() != 60
        )
            ++bad;
        // the EarthFossilHumanPct pin
    if (dcyEarthFossilHumanPct() != 31
        )
            ++bad;
        // the EarthStrengthSoft pin
    if (dcyEarthStrengthSoft() != 15
        )
            ++bad;
        // the EarthAirPocketOccPct pin
    if (dcyEarthAirPocketOccPct() != 80
        )
            ++bad;
        // the EarthHearingInches pin
    if (dcyEarthHearingInches() != 6
        )
            ++bad;
        // the EarthSolidWall pin
    if (dcyEarthSolidWall() != 1
        )
            ++bad;
        // the EarthBordersGrade pin
    if (dcyEarthBordersGrade() != 1
        )
            ++bad;
        // the EarthNativePasswall pin
    if (dcyEarthNativePasswall() != 1
        )
            ++bad;
        // the EarthMagicRangeRule pin
    if (dcyEarthMagicRangeRule() != 1
        )
            ++bad;
        // the EarthNativeEarthImmunity pin
    if (dcyEarthNativeEarthImmunity() != 1
        )
            ++bad;
        // the EarthSilverDoorway pin
    if (dcyEarthSilverDoorway() != 1
        )
            ++bad;
        printf("R570 MotP Earth plane audit: bad %d\n", bad);
        if (bad) return 1;
    }
