    // ---- R273: the III.E misc magic explanation
    // prose part 17 ----
    // The three Librams, the Lyre of Building and the
    // manuals of Bodily Health, Gainful Exercise,
    // Golems, Puissant Skill at Arms and Quickness of
    // Action, part2 lines 806-841 - the slice pinning
    // the kMisc4 rows 0-8 of the 36-row III.E.4 table.
    {
        Miscmagic_librams_lyre_and_manuals miscmagic;
        Miscmagic_table4_footnotes miscmagic_table4_footnotes;
        int bad = 0;
        // the libram of gainful conjuration
        if (miscmagic.mmpLibramStudyWeeks() != 1 ||
            miscmagic.mmpLibramMisuseDamageMin() != 5 ||
            miscmagic.mmpLibramMisuseDamageMax() != 20 ||
            miscmagic.mmpLibramInsanityRestMonths() != 1 ||
            miscmagic.mmpLibramDamnationLevelLoss() != 1) ++bad;
        // the unconscious turns are a like number, the
        // printed relation between the two pairs
        if (miscmagic.mmpLibramUnconsciousTurnsMin() !=
            miscmagic.mmpLibramMisuseDamageMin() ||
            miscmagic.mmpLibramUnconsciousTurnsMax() !=
            miscmagic.mmpLibramMisuseDamageMax()) ++bad;
        // the lyre of building
        if (miscmagic.mmpLyreNegateKindCount() != 3 ||
            miscmagic.mmpLyreNegateRounds() != 6 ||
            miscmagic.mmpLyreNegatePerDay() != 1 ||
            miscmagic.mmpLyreBuildPerWeek() != 1 ||
            miscmagic.mmpLyreBuildTurns() != 3 ||
            miscmagic.mmpLyreBuildMen() != 100 ||
            miscmagic.mmpLyreBuildDays() != 3 ||
            miscmagic.mmpLyreFalseChordPct() != 20 ||
            miscmagic.mmpLyreFalseChordKnownPct() != 5 ||
            miscmagic.mmpLyreFalseChordDisturbedPct() !=
            50) ++bad;
        // the manual of bodily health and of gainful
        // exercise
        if (miscmagic.mmpHealthReadHours() != 24 ||
            miscmagic.mmpHealthReadDaysMin() != 3 ||
            miscmagic.mmpHealthReadDaysMax() != 5 ||
            miscmagic.mmpHealthConGain() != 1 ||
            miscmagic.mmpHealthRegimenMonths() != 1 ||
            miscmagic.mmpHealthForgetMonths() != 3) ++bad;
        if (miscmagic.mmpExerciseStrGain() != 1) ++bad;
        // the manual of golems scalars
        if (miscmagic.mmpGolemKindCount() != 4 ||
            miscmagic.mmpGolemMinUserLevel() != 10 ||
            miscmagic.mmpGolemFailurePctPerLevel() != 10 ||
            miscmagic.mmpGolemFailureWindowTurns() != 1 ||
            miscmagic.mmpGolemClericXpLossMin() != 10000 ||
            miscmagic.mmpGolemClericXpLossMax() != 60000 ||
            miscmagic.mmpGolemMuLevelLoss() != 1 ||
            miscmagic.mmpGolemOtherDamageMin() != 6 ||
            miscmagic.mmpGolemOtherDamageMax() != 36) ++bad;
        // the golem table against static twins
        static const int kGlo[4] = {
            1, 6, 18, 19,
        };
        static const int kGhi[4] = {
            5, 17, 18, 20,
        };
        static const int kGmo[4] = {
            1, 2, 4, 3,
        };
        static const int kGco[4] = {
            65000, 50000, 100000, 80000,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic.mmpGolemDieLo(i) != kGlo[i] ||
                miscmagic.mmpGolemDieHi(i) != kGhi[i] ||
                miscmagic.mmpGolemMonths(i) != kGmo[i] ||
                miscmagic.mmpGolemCostGp(i) != kGco[i]) ++bad;
        // the golem die bands tile 1-20 without gaps
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpGolemDieLo(i + 1) !=
                miscmagic.mmpGolemDieHi(i) +
                1) ++bad;
        if (miscmagic.mmpGolemDieLo(0) != 1 ||
            miscmagic.mmpGolemDieHi(3) != 20) ++bad;
        // the manual of puissant skill at arms
        if (miscmagic.mmpPuissantPracticeMonths() != 1 ||
            miscmagic.mmpPuissantForgetMonths() != 3 ||
            miscmagic.mmpPuissantStunTurnsMin() != 1 ||
            miscmagic.mmpPuissantStunTurnsMax() != 6) ++bad;
        // both printed 10,000-60,000 xp losses agree
        if (miscmagic.mmpPuissantXpLossMin() !=
            miscmagic.mmpGolemClericXpLossMin() ||
            miscmagic.mmpPuissantXpLossMax() !=
            miscmagic.mmpGolemClericXpLossMax()) ++bad;
        // the manual of quickness of action
        if (miscmagic.mmpQuicknessStudyDays() != 3 ||
            miscmagic.mmpQuicknessPracticeMonths() != 1 ||
            miscmagic.mmpQuicknessDexGain() != 1 ||
            miscmagic.mmpQuicknessRememberMonths() != 3) ++bad;
        // the engine kMisc4 rows 0-8: single-die band
        // edges, the (M), (C) and (F) marks, no stars,
        // no dual rows
        static const int kRlo[9] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9,
        };
        static const int kRhi[9] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9,
        };
        for (int i = 0; i < 9; ++i)
            if (miscmagic_table4_footnotes.m4RowLo(i) != kRlo[i] ||
                miscmagic_table4_footnotes.m4RowHi(i) != kRhi[i] ||
                miscmagic_table4_footnotes.m4StarCount(i) != 0 ||
                miscmagic_table4_footnotes.m4IsDualValued(i) != 0) ++bad;
        if (miscmagic_table4_footnotes.m4UsableByMagicUser(0) != 1 ||
            miscmagic_table4_footnotes.m4UsableByMagicUser(1) != 1 ||
            miscmagic_table4_footnotes.m4UsableByMagicUser(2) != 1 ||
            miscmagic_table4_footnotes.m4UsableByMagicUser(6) != 1 ||
            miscmagic_table4_footnotes.m4UsableByMagicUser(3) != 0 ||
            miscmagic_table4_footnotes.m4UsableByMagicUser(7) != 0 ||
            miscmagic_table4_footnotes.m4UsableByCleric(6) != 1 ||
            miscmagic_table4_footnotes.m4UsableByCleric(0) != 0 ||
            miscmagic_table4_footnotes.m4UsableByFighter(7) != 1 ||
            miscmagic_table4_footnotes.m4UsableByFighter(0) != 0 ||
            miscmagic_table4_footnotes.m4UsableByThief(7) != 0) ++bad;
        printf("R273 misc magic prose part 17 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
