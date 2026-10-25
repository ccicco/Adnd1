    // ---- R679 OA combat sequence audit ----
    // OA round sixty-six (capture p. 218): the Summary of the Combat Sequence
    // - the five resolution steps with the surprise, initiative, to hit and
    // damage doctrine pins, the first round of the Chapter 9 Combat arc and
    // the first single-pass round - the compressed capture ends mid ninth
    // level spells
    {
        using namespace rules;
        int bad = 0;
    if (dipOACombatSequenceSteps() != 5
            || dipOASurpriseDieSides() != 6
            || dipOASurpriseRollMax() != 2
            || dipOAInitiativeDieSides() != 6
            || dipOAHitDieSides() != 20
            || dipOADamageModifierCount() != 4
            || !dipOASurpriseSometimesNil()
            || !dipOAActionsStatedFirst()
            || !dipOASubdueDisarmUnhorseAnnounced()
            || !dipOAInitiativeOnlyWithoutSurprise()
            || !dipOAKensaiWuJenInitMods()
            || !dipOAKensaiWuJenFirstAttack()
            || !dipOAKiStatedBeforeHitDie()
            || !dipOAShukKiStatedBeforeSave()
            || !dipOASubdualRecordedSeparately()
            || !dipOALoserSideRepeatsStepFour()
        )
            ++bad;
        // the sequence shape pins - five steps, the six-sided surprise and
        // initiative dice, the 1-2 surprise band, the twenty-sided to hit die
    if (dipOACombatSequenceSteps() != 5
            || dipOASurpriseDieSides() != 6
            || dipOASurpriseRollMax() != 2
            || dipOAInitiativeDieSides() != 6
            || dipOAHitDieSides() != 20
        )
            ++bad;
        // the damage modifier pins - the four damage modifiers added to the
        // damage dice for each hit
    if (dipOADamageModifierCount() != 4
        )
            ++bad;
        // the step 1 and 2 doctrine pins - surprise often impossible, actions
        // stated first, the subdue/disarm/unhorse announcement
    if (dipOASurpriseSometimesNil() != 1
            || dipOAActionsStatedFirst() != 1
            || dipOASubdueDisarmUnhorseAnnounced() != 1
        )
            ++bad;
        // the step 3 doctrine pins - initiative only without surprise, the
        // kensai and wu jen initiative modifiers
    if (dipOAInitiativeOnlyWithoutSurprise() != 1
            || dipOAKensaiWuJenInitMods() != 1
        )
            ++bad;
        // the step 4 doctrine pins - the kensai/wu jen first-strike, the ki
        // declarations before the hit die and before the saves, the separate
        // subdual record
    if (dipOAKensaiWuJenFirstAttack() != 1
            || dipOAKiStatedBeforeHitDie() != 1
            || dipOAShukKiStatedBeforeSave() != 1
            || dipOASubdualRecordedSeparately() != 1
        )
            ++bad;
        // the step 5 pin - the initiative loser then performs step 4, closing
        // the five-step round
    if (dipOALoserSideRepeatsStepFour() != 1
        )
            ++bad;
        // the die pins read together - the 1d6 surprise read of the 1-2 band,
        // the 1d6 initiative, the 1d20 to hit
    if (dipOASurpriseDieSides() != dipOAInitiativeDieSides()
            || dipOAHitDieSides() != 20
            || dipOASurpriseRollMax() > dipOASurpriseDieSides()
        )
            ++bad;
        printf("R679 OA combat sequence audit: bad %d\n", bad);
        if (bad) return 1;
    }
