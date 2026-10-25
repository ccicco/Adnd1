    // ---- R687 OA psychic duel audit ----
    // OA round seventy-four (capture pp. 222-223): The Psychic Duel - the
    // mental combat of the wills with the save-versus-death resolution, the
    // kensai bonus, the three outcomes, the honor awards and the loser
    // options, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djaOAPsychicDuelRangeFeet() != 10
            || djaOAPsychicDuelKensaiBonus() != 2
            || djaOAPsychicDuelFriendsHonor() != 3
            || djaOAPsychicDuelHigherLevelHonor() != 2
            || djaOAPsychicDuelEqualLevelHonor() != 1
            || djaOAPsychicDuelLoserAttackPenalty() != -1
            || !djaOAPsychicDuelDoctrine()
            || !djaOAPsychicDuelAnyoneMayTry()
            || !djaOAPsychicDuelHumanOnly()
            || !djaOAPsychicDuelOneOnOne()
            || !djaOAPsychicDuelNeverFriends()
            || !djaOAPsychicDuelNoCrossedWeapons()
            || !djaOAPsychicDuelNoOutsideAttacks()
            || !djaOAPsychicDuelSaveVersusDeath()
            || !djaOAPsychicDuelOneMakesOneWins()
            || !djaOAPsychicDuelBothFailInconclusive()
            || !djaOAPsychicDuelBothMakeContinue()
            || !djaOAPsychicDuelBreakerLoses()
            || !djaOAPsychicDuelLoserRetreat()
            || !djaOAPsychicDuelLoserMayAttack()
            || !djaOAPsychicDuelNoSurprise()
            || !djaOAPsychicDuelLowerLevelNoHonor()
        )
            ++bad;
        // the duel mechanics - the 10 feet and the kensai +2 against
        // non-kensai
    if (djaOAPsychicDuelRangeFeet() != 10
            || djaOAPsychicDuelKensaiBonus() != 2
        )
            ++bad;
        // the honor awards - the 2 for the higher, the 1 for the equal
    if (djaOAPsychicDuelHigherLevelHonor() != 2
            || djaOAPsychicDuelEqualLevelHonor() != 1
        )
            ++bad;
        // the friends dishonor - the 3 points of honor
    if (djaOAPsychicDuelFriendsHonor() != 3
        )
            ++bad;
        // the loser attack penalty - the -1 throughout the battle
    if (djaOAPsychicDuelLoserAttackPenalty() != -1
        )
            ++bad;
        printf("R687 OA psychic duel audit: bad %d\n", bad);
        if (bad) return 1;
    }
