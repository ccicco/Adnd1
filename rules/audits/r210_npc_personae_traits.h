    // ---- R210: the NPC personae traits audit ----
    // DMG pp.115-116: the general tendencies,
    // personality, interests and the word
    // tables, the morals asterisk rule, and the
    // reaction adjustment percents.
    {
        Npctraits npctraits;
        int bad = 0;
        // the tendencies: 24 rows, the d6 halves
        if (npctraits.npcTendencyCount() != 24) ++bad;
        if (npctraits.npcTraitTendency(1, 1) != 0 ||
            npctraits.npcTraitTendency(3, 12) != 11 ||
            npctraits.npcTraitTendency(4, 1) != 12 ||
            npctraits.npcTraitTendency(6, 12) != 23 ||
            npctraits.npcTraitTendency(2, 5)
                != NPT_HELPFUL_KINDLY ||
            npctraits.npcTraitTendency(5, 6)
                != NPT_FOUL_BARBARIC ||
            npctraits.npcTraitTendency(1, 24) != 11 ||
            npctraits.npcTraitTendency(9, 1) != 12) ++bad;
        // the personality: the column split and
        // the per-column words
        if (npctraits.npcTraitPersonalityType(1)
                != NPPTY_AVERAGE ||
            npctraits.npcTraitPersonalityType(5)
                != NPPTY_AVERAGE ||
            npctraits.npcTraitPersonalityType(6)
                != NPPTY_EXTROVERTED ||
            npctraits.npcTraitPersonalityType(7)
                != NPPTY_EXTROVERTED ||
            npctraits.npcTraitPersonalityType(8)
                != NPPTY_INTROVERTED) ++bad;
        if (npctraits.npcTraitPersonality(1, 1)
                != NPPW_MODEST ||
            npctraits.npcTraitPersonality(1, 8)
                != NPPW_ABRASIVE ||
            npctraits.npcTraitPersonality(6, 1)
                != NPPW_FORCEFUL ||
            npctraits.npcTraitPersonality(7, 7)
                != NPPW_RASH ||
            npctraits.npcTraitPersonality(8, 1)
                != NPPW_RETIRING ||
            npctraits.npcTraitPersonality(8, 8)
                != NPPW_SOLITARY_SECRETIVE) ++bad;
        // every personality cell: the identity
        // walk (col base + row)
        static const int kPersColBase[3] = { 0, 8, 16 };
        for (int c = 0; c < 3; ++c)
            for (int r = 1; r <= 8; ++r)
                if (npctraits.npcTraitPersonality(
                        c == 0 ? 1 : (c == 1 ? 6 : 8), r)
                    != kPersColBase[c] + r - 1) ++bad;
        // the interests: the halves, the
        // collector rows and the none rows
        if (npctraits.npcInterestCount() != 24) ++bad;
        if (npctraits.npcTraitInterest(1, 1)
                != NPI_RELIGION ||
            npctraits.npcTraitInterest(3, 12)
                != NPI_POLITICS ||
            npctraits.npcTraitInterest(4, 1)
                != NPI_WINES_SPIRITS ||
            npctraits.npcTraitInterest(5, 5)
                != NPI_COLLECTOR_1 ||
            npctraits.npcTraitInterest(6, 12)
                != NPI_NONE_2) ++bad;
        for (int i = 16; i <= 19; ++i)
            if (!npctraits.npcInterestIsCollector(i)) ++bad;
        if (npctraits.npcInterestIsCollector(15) ||
            npctraits.npcInterestIsCollector(20)) ++bad;
        // the disposition, intellect and
        // collections word faces
        if (npctraits.npcTraitDisposition(1)
                != NPD_CHEERFUL ||
            npctraits.npcTraitDisposition(3)
                != NPD_COMPASSIONATE_SENSITIVE ||
            npctraits.npcTraitDisposition(10)
                != NPD_HARSH ||
            npctraits.npcTraitDisposition(0)
                != NPD_HARSH) ++bad;
        if (npctraits.npcTraitIntellect(1)
                != NPIQ_DULL ||
            npctraits.npcTraitIntellect(6)
                != NPIQ_DREAMING ||
            npctraits.npcTraitIntellect(10)
                != NPIQ_BRILLIANT) ++bad;
        if (!npctraits.npcIntellectModifiesRating(
                NPIQ_SCHEMING) ||
            !npctraits.npcIntellectModifiesRating(                NPIQ_DREAMING) ||
            npctraits.npcIntellectModifiesRating(                NPIQ_ACTIVE_1)) ++bad;
        if (npctraits.npcTraitCollection(1)
                != NPCOL_KNIVES_DAGGERS ||
            npctraits.npcTraitCollection(2)
                != NPCOL_SWORDS ||
            npctraits.npcTraitCollection(12)
                != NPCOL_ARTWORK) ++bad;
        // the nature, materialism, honesty,
        // bravery, energy and thrift faces
        if (npctraits.npcTraitNature(1)
                != NPNT_SOFT_HEARTED ||
            npctraits.npcTraitNature(6)
                != NPNT_VENGEFUL) ++bad;
        if (npctraits.npcTraitMaterialism(1)
                != NPM_AESTHETIC ||
            npctraits.npcTraitMaterialism(6)
                != NPM_AVARICIOUS) ++bad;
        if (npctraits.npcTraitHonesty(1)
                != NPH_SCRUPULOUS ||
            npctraits.npcTraitHonesty(4)
                != NPH_AVERAGE_1 ||
            npctraits.npcTraitHonesty(6)
                != NPH_AVERAGE_3 ||
            npctraits.npcTraitHonesty(7)
                != NPH_LIAR) ++bad;
        if (npctraits.npcTraitBravery(4)
                != NPB_FOOLHARDY ||
            npctraits.npcTraitBravery(7)
                != NPB_COWARDLY) ++bad;
        if (npctraits.npcTraitEnergy(1)
                != NPE_SLOTHFUL ||
            npctraits.npcTraitEnergy(8)
                != NPE_DRIVEN) ++bad;
        if (npctraits.npcTraitThrift(1)
                != NPTHR_MISERLY ||
            npctraits.npcTraitThrift(6)
                != NPTHR_SPENDTHRIFT_1 ||
            npctraits.npcTraitThrift(8)
                != NPTHR_WASTREL) ++bad;
        // the morals: the faces, the marked
        // rows and the asterisk resolution
        if (npctraits.npcTraitMorals(1)
                != NPMOR_ASCETIC ||
            npctraits.npcTraitMorals(5)
                != NPMOR_LUSTY_1 ||
            npctraits.npcTraitMorals(10)
                != NPMOR_PERVERTED ||
            npctraits.npcTraitMorals(12)
                != NPMOR_DEPRAVED) ++bad;
        if (!npctraits.npcMoralsIsMarked(                NPMOR_PERVERTED) ||
            !npctraits.npcMoralsIsMarked(                NPMOR_SADISTIC) ||
            !npctraits.npcMoralsIsMarked(                NPMOR_DEPRAVED) ||
            npctraits.npcMoralsIsMarked(                NPMOR_AMORAL) ||
            npctraits.npcMoralsIsMarked(                NPMOR_ASCETIC)) ++bad;
        if (npctraits.npcMoralsResolved(12, 11)
                != NPMOR_SADISTIC ||
            npctraits.npcMoralsResolved(10, 10)
                != NPMOR_PERVERTED ||
            npctraits.npcMoralsResolved(10, 3)
                != NPMOR_NORMAL_1 ||
            npctraits.npcMoralsResolved(4, 12)
                != NPMOR_NORMAL_2 ||
            npctraits.npcMoralsResolved(2, 11)
                != NPMOR_VIRTUOUS) ++bad;
        // the piety faces: the average run
        // 5-8
        if (npctraits.npcTraitPiety(1)
                != NPP_SAINTLY ||
            npctraits.npcTraitPiety(2)
                != NPP_MARTYR_ZEALOT ||
            npctraits.npcTraitPiety(5)
                != NPP_AVERAGE_1 ||
            npctraits.npcTraitPiety(8)
                != NPP_AVERAGE_4 ||
            npctraits.npcTraitPiety(12)
                != NPP_IRRELIGIOUS) ++bad;
        // the reaction adjustment percents:
        // the print mins and maxes
        if (npctraits.npcReactGroupCount() != 9) ++bad;
        static const int kReactMin[9] = {
            -1, 1, 1, 1, 1, 1, 1, 1, 1,
        };
        static const int kReactMax[9] = {
            6, 10, 20, 6, 4, 8, 20, 8, 20,
        };
        for (int g = 0; g < 9; ++g)
            if (npctraits.npcReactionAdjMin(g)
                    != kReactMin[g] ||
                npctraits.npcReactionAdjMax(g)
                    != kReactMax[g]) ++bad;
        // the d6/d8/d12/d10 clamps hold at the
        // extremes
        if (npctraits.npcTraitTendency(0, 0) != 0 ||
            npctraits.npcTraitTendency(7, 13) != 23 ||
            npctraits.npcTraitPersonality(9, 9)
                != NPPW_SOLITARY_SECRETIVE ||
            npctraits.npcTraitMorals(0) != 0) ++bad;
        printf("R210 NPC personae traits audit: bad %d\n", bad);
        if (bad) return 1;
    }
