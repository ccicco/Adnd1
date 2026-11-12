    // ---- R215: the conducting the game pins audit ----
    // DMG pp.110-112: the divine intervention
    // procedure, the planes rule, the secret
    // rolls, the system shock clause, the
    // integration numbers, the multiple
    // characters rules, the troublesome
    // measures.
    {
        Conduct conduct;
        int bad = 0;
        // the divine intervention procedure
        if (conduct.deityCreatureSentFirstAskPct() != 10 ||
            conduct.deityComeChancePct(12) != 12 ||
            conduct.deityComeChancePct(0) != 0 ||
            conduct.deityComeChancePct(-5) != 0) ++bad;
        if (conduct.deityModEachPreviousIntervention() != -5 ||
            conduct.deityModAlignmentMedial() != -5 ||
            conduct.deityModAlignmentBorderline() != -10 ||
            conduct.deityModDirectConfrontation() != -10 ||
            conduct.deityModOpposingDiametric() != 1 ||
            conduct.deityModServingProximately() != 25) ++bad;
        if (conduct.deityInterventionPct(10, 0, 0, 0, 0, 0, 0)
                != 10 ||
            conduct.deityInterventionPct(10, 1, 0, 0, 0, 0, 0)
                != 5 ||
            conduct.deityInterventionPct(10, 2, 0, 0, 0, 0, 0)
                != 0 ||
            conduct.deityInterventionPct(
                10, 1, 1, 1, 1, 0, 0) != -20 ||
            conduct.deityInterventionPct(
                10, 0, 0, 0, 0, 1, 1) != 36 ||
            conduct.deityInterventionPct(20, 1, 1, 1, 1, 1, 1) != 16 ||
            conduct.deityInterventionPct(
                5, 9, 9, 9, 9, 9, 9) != -39 ||
            conduct.deityInterventionPct(
                -3, 0, 0, 0, 0, 0, 0) != 0) ++bad;
        // the planes rule
        if (IP_COUNT != 7
            || IP_PRIME_MATERIAL != 0
            || IP_ELEMENTAL != 3
            || IP_OUTER != 4
            || IP_POSITIVE != 5
            || IP_NEGATIVE != 6) ++bad;
        static const int kPlane[7] = { 1, 1, 1, 2, 0, 0, 0 };
        for (int p = 0; p < 7; ++p)
            if (conduct.interventionPlaneAllowed(p)
                    != kPlane[p]) ++bad;
        if (conduct.interventionPlaneAllowed(-3) != 1 ||
            conduct.interventionPlaneAllowed(9) != 0 ||
            conduct.elementalGodsBlockOuterDeities() != 1) ++bad;
        // the secret rolls and the system shock clause
        if (conduct.secretRollKindCount() != 7
            || SR_COUNT != 7
            || SR_LISTENING != 0
            || SR_ATTACKS_WITHOUT_KNOWLEDGE != 6) ++bad;
        for (int k = -1; k < 8; ++k)
            if (conduct.rollIsSecretAlways(k) != 1) ++bad;
        if (conduct.systemShockRollNeverTampered() != 1 ||
            conduct.systemShockFailureForeverDead() != 1) ++bad;
        // the integration numbers
        if (conduct.integrationAveragingDieMin() != 2 ||
            conduct.integrationAveragingDieMax() != 5 ||
            conduct.integrationAverageWorksUpToLevel() != 8 ||
            conduct.integrationAboveCeilingStartLevel() != 4 ||
            conduct.neophyteFullCoopLevel() != 3) ++bad;
        // the multiple characters rules
        if (conduct.multipleCharactersProhibited() != 0 ||
            conduct.multipleCharactersFreeInterchange()
                != 0) ++bad;
        // the troublesome-player measures
        if (conduct.troublesomeCharismaLossPoints() != 1 ||
            conduct.etherealMummyAlwaysSurprise() != 1) ++bad;
        printf("R215 conducting the game pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
