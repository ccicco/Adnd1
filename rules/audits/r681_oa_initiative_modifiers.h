    // ---- R681 OA initiative modifiers audit ----
    // OA round sixty-eight (capture pp. 218-219): the Initiative Modifiers
    // doctrine - the quickness frame, the character-only modifier clause with
    // the phase division, the tie rules and the printed kensai example,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (diuOAInitiativeRollsPerRound() != 2
            || diuOAExamplePCSideRoll() != 3
            || diuOAExampleNPCSideRoll() != 4
            || diuOAExampleKensaiModified() != 4
            || diuOAExampleNpcKensaiModified() != 5
            || !diuOAQuicknessDoctrine()
            || !diuOAInitiativeOncePerSide()
            || !diuOAModifierCharacterOnly()
            || !diuOAPhasesExceedTwo()
            || !diuOATieNotRerolled()
            || !diuOATieSimultaneous()
            || !diuOATieEffectsAfterAction()
            || !diuOAWinnerOrderUnimportant()
        )
            ++bad;
        // the roll pins - the two side rolls of the round, once per side even
        // with partial modifiers
    if (diuOAInitiativeRollsPerRound() != 2
        )
            ++bad;
        // the side rolls of the printed example - the PC 3, the NPC 4
    if (diuOAExamplePCSideRoll() != 3
            || diuOAExampleNPCSideRoll() != 4
        )
            ++bad;
        // the modified rolls of the printed example - the kensai 4, the NPC
        // kensai 5
    if (diuOAExampleKensaiModified() != 4
            || diuOAExampleNpcKensaiModified() != 5
        )
            ++bad;
        // the example shape - the kensai modified riding the same instant as
        // the NPC side roll
    if (diuOAExampleKensaiModified() != diuOAExampleNPCSideRoll()
        )
            ++bad;
        // the example shape - the hypothetical NPC kensai one higher still
    if (diuOAExampleNpcKensaiModified() != diuOAExampleNPCSideRoll() + 1
        )
            ++bad;
        // the modifier doctrine pins - once per side, the character-only
        // application, the phase division beyond two
    if (diuOAInitiativeOncePerSide() != 1
            || diuOAModifierCharacterOnly() != 1
            || diuOAPhasesExceedTwo() != 1
            || diuOAQuicknessDoctrine() != 1
        )
            ++bad;
        // the tie doctrine pins - no reroll, the same instant, the effects
        // landing only after the character completes his action
    if (diuOATieNotRerolled() != 1
            || diuOATieSimultaneous() != 1
            || diuOATieEffectsAfterAction() != 1
        )
            ++bad;
        // the landslide pin - the winning side above even the highest
        // modified initiative acting in any order, all actions completing
        // before the other side begins
    if (diuOAWinnerOrderUnimportant() != 1
        )
            ++bad;
        printf("R681 OA initiative modifiers audit: bad %d\n", bad);
        if (bad) return 1;
    }
