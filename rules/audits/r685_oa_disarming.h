    // ---- R685 OA disarming audit ----
    // OA round seventy-two (capture p. 221): the Disarming doctrine - the two
    // methods, the weapon disarm with the save versus petrification and the
    // 1d6 fall, the bare-hands systems with the martial-arts any-size knock
    // and the two-handed weapon rule, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (diyOADisarmWeaponFallDice() != 6
            || diyOADisarmRecoverRounds() != 1
            || diyOADisarmMartialArtsSaveBonus() != 2
            || diyOADisarmTwoHandedAttemptsNeeded() != 2
            || !diyOADisarmDoctrine()
            || !diyOADisarmTwoMethods()
            || !diyOADisarmEqualOrGreaterSize()
            || !diyOADisarmMustDeclare()
            || !diyOADisarmNoDamage()
            || !diyOADisarmSaveVersusPetrification()
            || !diyOADisarmBareHandsSystems()
        )
            ++bad;
        // the weapon-disarm pins - the 1d6 feet fall and the one-round
        // recovery
    if (diyOADisarmWeaponFallDice() != 6
            || diyOADisarmRecoverRounds() != 1
        )
            ++bad;
        // the martial-arts save bonus - the +2 on the victim save
    if (diyOADisarmMartialArtsSaveBonus() != 2
        )
            ++bad;
        // the two-handed rule - the two same-round attempts needed
    if (diyOADisarmTwoHandedAttemptsNeeded() != 2
        )
            ++bad;
        printf("R685 OA disarming audit: bad %d\n", bad);
        if (bad) return 1;
    }
