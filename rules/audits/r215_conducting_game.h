    // ---- R215: the conducting the game pins audit ----
    // DMG pp.110-112: the divine intervention
    // procedure, the planes rule, the secret
    // rolls, the system shock clause, the
    // integration numbers, the multiple
    // characters rules, the troublesome
    // measures.
    {
        int bad = 0;
        // the divine intervention procedure
        if (rules::deityCreatureSentFirstAskPct() != 10 ||
            rules::deityComeChancePct(12) != 12 ||
            rules::deityComeChancePct(0) != 0 ||
            rules::deityComeChancePct(-5) != 0) ++bad;
        if (rules::deityModEachPreviousIntervention() != -5 ||
            rules::deityModAlignmentMedial() != -5 ||
            rules::deityModAlignmentBorderline() != -10 ||
            rules::deityModDirectConfrontation() != -10 ||
            rules::deityModOpposingDiametric() != 1 ||
            rules::deityModServingProximately() != 25) ++bad;
        if (rules::deityInterventionPct(10, 0, 0, 0, 0, 0, 0)
                != 10 ||
            rules::deityInterventionPct(10, 1, 0, 0, 0, 0, 0)
                != 5 ||
            rules::deityInterventionPct(10, 2, 0, 0, 0, 0, 0)
                != 0 ||
            rules::deityInterventionPct(
                10, 1, 1, 1, 1, 0, 0) != -20 ||
            rules::deityInterventionPct(
                10, 0, 0, 0, 0, 1, 1) != 36 ||
            rules::deityInterventionPct(20, 1, 1, 1, 1, 1, 1) != 16 ||
            rules::deityInterventionPct(
                5, 9, 9, 9, 9, 9, 9) != -39 ||
            rules::deityInterventionPct(
                -3, 0, 0, 0, 0, 0, 0) != 0) ++bad;
        // the planes rule
        if (rules::IP_COUNT != 7
            || rules::IP_PRIME_MATERIAL != 0
            || rules::IP_ELEMENTAL != 3
            || rules::IP_OUTER != 4
            || rules::IP_POSITIVE != 5
            || rules::IP_NEGATIVE != 6) ++bad;
        static const int kPlane[7] = { 1, 1, 1, 2, 0, 0, 0 };
        for (int p = 0; p < 7; ++p)
            if (rules::interventionPlaneAllowed(p)
                    != kPlane[p]) ++bad;
        if (rules::interventionPlaneAllowed(-3) != 1 ||
            rules::interventionPlaneAllowed(9) != 0 ||
            rules::elementalGodsBlockOuterDeities() != 1) ++bad;
        // the secret rolls and the system shock clause
        if (rules::secretRollKindCount() != 7
            || rules::SR_COUNT != 7
            || rules::SR_LISTENING != 0
            || rules::SR_ATTACKS_WITHOUT_KNOWLEDGE != 6) ++bad;
        for (int k = -1; k < 8; ++k)
            if (rules::rollIsSecretAlways(k) != 1) ++bad;
        if (rules::systemShockRollNeverTampered() != 1 ||
            rules::systemShockFailureForeverDead() != 1) ++bad;
        // the integration numbers
        if (rules::integrationAveragingDieMin() != 2 ||
            rules::integrationAveragingDieMax() != 5 ||
            rules::integrationAverageWorksUpToLevel() != 8 ||
            rules::integrationAboveCeilingStartLevel() != 4 ||
            rules::neophyteFullCoopLevel() != 3) ++bad;
        // the multiple characters rules
        if (rules::multipleCharactersProhibited() != 0 ||
            rules::multipleCharactersFreeInterchange()
                != 0) ++bad;
        // the troublesome-player measures
        if (rules::troublesomeCharismaLossPoints() != 1 ||
            rules::etherealMummyAlwaysSurprise() != 1) ++bad;
        printf("R215 conducting the game pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
