    // ---- R210: the NPC personae traits audit ----
    // DMG pp.115-116: the general tendencies,
    // personality, interests and the word
    // tables, the morals asterisk rule, and the
    // reaction adjustment percents.
    {
        int bad = 0;
        // the tendencies: 24 rows, the d6 halves
        if (rules::npcTendencyCount() != 24) ++bad;
        if (rules::npcTraitTendency(1, 1) != 0 ||
            rules::npcTraitTendency(3, 12) != 11 ||
            rules::npcTraitTendency(4, 1) != 12 ||
            rules::npcTraitTendency(6, 12) != 23 ||
            rules::npcTraitTendency(2, 5)
                != rules::NPT_HELPFUL_KINDLY ||
            rules::npcTraitTendency(5, 6)
                != rules::NPT_FOUL_BARBARIC ||
            rules::npcTraitTendency(1, 24) != 11 ||
            rules::npcTraitTendency(9, 1) != 12) ++bad;
        // the personality: the column split and
        // the per-column words
        if (rules::npcTraitPersonalityType(1)
                != rules::NPPTY_AVERAGE ||
            rules::npcTraitPersonalityType(5)
                != rules::NPPTY_AVERAGE ||
            rules::npcTraitPersonalityType(6)
                != rules::NPPTY_EXTROVERTED ||
            rules::npcTraitPersonalityType(7)
                != rules::NPPTY_EXTROVERTED ||
            rules::npcTraitPersonalityType(8)
                != rules::NPPTY_INTROVERTED) ++bad;
        if (rules::npcTraitPersonality(1, 1)
                != rules::NPPW_MODEST ||
            rules::npcTraitPersonality(1, 8)
                != rules::NPPW_ABRASIVE ||
            rules::npcTraitPersonality(6, 1)
                != rules::NPPW_FORCEFUL ||
            rules::npcTraitPersonality(7, 7)
                != rules::NPPW_RASH ||
            rules::npcTraitPersonality(8, 1)
                != rules::NPPW_RETIRING ||
            rules::npcTraitPersonality(8, 8)
                != rules::NPPW_SOLITARY_SECRETIVE) ++bad;
        // every personality cell: the identity
        // walk (col base + row)
        static const int kPersColBase[3] = { 0, 8, 16 };
        for (int c = 0; c < 3; ++c)
            for (int r = 1; r <= 8; ++r)
                if (rules::npcTraitPersonality(
                        c == 0 ? 1 : (c == 1 ? 6 : 8), r)
                    != kPersColBase[c] + r - 1) ++bad;
        // the interests: the halves, the
        // collector rows and the none rows
        if (rules::npcInterestCount() != 24) ++bad;
        if (rules::npcTraitInterest(1, 1)
                != rules::NPI_RELIGION ||
            rules::npcTraitInterest(3, 12)
                != rules::NPI_POLITICS ||
            rules::npcTraitInterest(4, 1)
                != rules::NPI_WINES_SPIRITS ||
            rules::npcTraitInterest(5, 5)
                != rules::NPI_COLLECTOR_1 ||
            rules::npcTraitInterest(6, 12)
                != rules::NPI_NONE_2) ++bad;
        for (int i = 16; i <= 19; ++i)
            if (!rules::npcInterestIsCollector(i)) ++bad;
        if (rules::npcInterestIsCollector(15) ||
            rules::npcInterestIsCollector(20)) ++bad;
        // the disposition, intellect and
        // collections word faces
        if (rules::npcTraitDisposition(1)
                != rules::NPD_CHEERFUL ||
            rules::npcTraitDisposition(3)
                != rules::NPD_COMPASSIONATE_SENSITIVE ||
            rules::npcTraitDisposition(10)
                != rules::NPD_HARSH ||
            rules::npcTraitDisposition(0)
                != rules::NPD_HARSH) ++bad;
        if (rules::npcTraitIntellect(1)
                != rules::NPIQ_DULL ||
            rules::npcTraitIntellect(6)
                != rules::NPIQ_DREAMING ||
            rules::npcTraitIntellect(10)
                != rules::NPIQ_BRILLIANT) ++bad;
        if (!rules::npcIntellectModifiesRating(
                rules::NPIQ_SCHEMING) ||
            !rules::npcIntellectModifiesRating(                rules::NPIQ_DREAMING) ||
            rules::npcIntellectModifiesRating(                rules::NPIQ_ACTIVE_1)) ++bad;
        if (rules::npcTraitCollection(1)
                != rules::NPCOL_KNIVES_DAGGERS ||
            rules::npcTraitCollection(2)
                != rules::NPCOL_SWORDS ||
            rules::npcTraitCollection(12)
                != rules::NPCOL_ARTWORK) ++bad;
        // the nature, materialism, honesty,
        // bravery, energy and thrift faces
        if (rules::npcTraitNature(1)
                != rules::NPNT_SOFT_HEARTED ||
            rules::npcTraitNature(6)
                != rules::NPNT_VENGEFUL) ++bad;
        if (rules::npcTraitMaterialism(1)
                != rules::NPM_AESTHETIC ||
            rules::npcTraitMaterialism(6)
                != rules::NPM_AVARICIOUS) ++bad;
        if (rules::npcTraitHonesty(1)
                != rules::NPH_SCRUPULOUS ||
            rules::npcTraitHonesty(4)
                != rules::NPH_AVERAGE_1 ||
            rules::npcTraitHonesty(6)
                != rules::NPH_AVERAGE_3 ||
            rules::npcTraitHonesty(7)
                != rules::NPH_LIAR) ++bad;
        if (rules::npcTraitBravery(4)
                != rules::NPB_FOOLHARDY ||
            rules::npcTraitBravery(7)
                != rules::NPB_COWARDLY) ++bad;
        if (rules::npcTraitEnergy(1)
                != rules::NPE_SLOTHFUL ||
            rules::npcTraitEnergy(8)
                != rules::NPE_DRIVEN) ++bad;
        if (rules::npcTraitThrift(1)
                != rules::NPTHR_MISERLY ||
            rules::npcTraitThrift(6)
                != rules::NPTHR_SPENDTHRIFT_1 ||
            rules::npcTraitThrift(8)
                != rules::NPTHR_WASTREL) ++bad;
        // the morals: the faces, the marked
        // rows and the asterisk resolution
        if (rules::npcTraitMorals(1)
                != rules::NPMOR_ASCETIC ||
            rules::npcTraitMorals(5)
                != rules::NPMOR_LUSTY_1 ||
            rules::npcTraitMorals(10)
                != rules::NPMOR_PERVERTED ||
            rules::npcTraitMorals(12)
                != rules::NPMOR_DEPRAVED) ++bad;
        if (!rules::npcMoralsIsMarked(                rules::NPMOR_PERVERTED) ||
            !rules::npcMoralsIsMarked(                rules::NPMOR_SADISTIC) ||
            !rules::npcMoralsIsMarked(                rules::NPMOR_DEPRAVED) ||
            rules::npcMoralsIsMarked(                rules::NPMOR_AMORAL) ||
            rules::npcMoralsIsMarked(                rules::NPMOR_ASCETIC)) ++bad;
        if (rules::npcMoralsResolved(12, 11)
                != rules::NPMOR_SADISTIC ||
            rules::npcMoralsResolved(10, 10)
                != rules::NPMOR_PERVERTED ||
            rules::npcMoralsResolved(10, 3)
                != rules::NPMOR_NORMAL_1 ||
            rules::npcMoralsResolved(4, 12)
                != rules::NPMOR_NORMAL_2 ||
            rules::npcMoralsResolved(2, 11)
                != rules::NPMOR_VIRTUOUS) ++bad;
        // the piety faces: the average run
        // 5-8
        if (rules::npcTraitPiety(1)
                != rules::NPP_SAINTLY ||
            rules::npcTraitPiety(2)
                != rules::NPP_MARTYR_ZEALOT ||
            rules::npcTraitPiety(5)
                != rules::NPP_AVERAGE_1 ||
            rules::npcTraitPiety(8)
                != rules::NPP_AVERAGE_4 ||
            rules::npcTraitPiety(12)
                != rules::NPP_IRRELIGIOUS) ++bad;
        // the reaction adjustment percents:
        // the print mins and maxes
        if (rules::npcReactGroupCount() != 9) ++bad;
        static const int kReactMin[9] = {
            -1, 1, 1, 1, 1, 1, 1, 1, 1,
        };
        static const int kReactMax[9] = {
            6, 10, 20, 6, 4, 8, 20, 8, 20,
        };
        for (int g = 0; g < 9; ++g)
            if (rules::npcReactionAdjMin(g)
                    != kReactMin[g] ||
                rules::npcReactionAdjMax(g)
                    != kReactMax[g]) ++bad;
        // the d6/d8/d12/d10 clamps hold at the
        // extremes
        if (rules::npcTraitTendency(0, 0) != 0 ||
            rules::npcTraitTendency(7, 13) != 23 ||
            rules::npcTraitPersonality(9, 9)
                != rules::NPPW_SOLITARY_SECRETIVE ||
            rules::npcTraitMorals(0) != 0) ++bad;
        printf("R210 NPC personae traits audit: bad %d\n", bad);
        if (bad) return 1;
    }
