    // ---- R273: the III.E misc magic explanation
    // prose part 17 ----
    // The three Librams, the Lyre of Building and the
    // manuals of Bodily Health, Gainful Exercise,
    // Golems, Puissant Skill at Arms and Quickness of
    // Action, part2 lines 806-841 - the slice pinning
    // the kMisc4 rows 0-8 of the 36-row III.E.4 table.
    {
        Miscmagic_librams_lyre_and_manuals miscmagic_librams_lyre_and_manuals;
        Miscmagic_table4_footnotes miscmagic_table4_footnotes;
        int bad = 0;
        // the libram of gainful conjuration
        if (miscmagic_librams_lyre_and_manuals.mmpLibramStudyWeeks() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpLibramMisuseDamageMin() != 5 ||
            miscmagic_librams_lyre_and_manuals.mmpLibramMisuseDamageMax() != 20 ||
            miscmagic_librams_lyre_and_manuals.mmpLibramInsanityRestMonths() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpLibramDamnationLevelLoss() != 1) ++bad;
        // the unconscious turns are a like number, the
        // printed relation between the two pairs
        if (miscmagic_librams_lyre_and_manuals.mmpLibramUnconsciousTurnsMin() !=
            miscmagic_librams_lyre_and_manuals.mmpLibramMisuseDamageMin() ||
            miscmagic_librams_lyre_and_manuals.mmpLibramUnconsciousTurnsMax() !=
            miscmagic_librams_lyre_and_manuals.mmpLibramMisuseDamageMax()) ++bad;
        // the lyre of building
        if (miscmagic_librams_lyre_and_manuals.mmpLyreNegateKindCount() != 3 ||
            miscmagic_librams_lyre_and_manuals.mmpLyreNegateRounds() != 6 ||
            miscmagic_librams_lyre_and_manuals.mmpLyreNegatePerDay() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpLyreBuildPerWeek() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpLyreBuildTurns() != 3 ||
            miscmagic_librams_lyre_and_manuals.mmpLyreBuildMen() != 100 ||
            miscmagic_librams_lyre_and_manuals.mmpLyreBuildDays() != 3 ||
            miscmagic_librams_lyre_and_manuals.mmpLyreFalseChordPct() != 20 ||
            miscmagic_librams_lyre_and_manuals.mmpLyreFalseChordKnownPct() != 5 ||
            miscmagic_librams_lyre_and_manuals.mmpLyreFalseChordDisturbedPct() !=
            50) ++bad;
        // the manual of bodily health and of gainful
        // exercise
        if (miscmagic_librams_lyre_and_manuals.mmpHealthReadHours() != 24 ||
            miscmagic_librams_lyre_and_manuals.mmpHealthReadDaysMin() != 3 ||
            miscmagic_librams_lyre_and_manuals.mmpHealthReadDaysMax() != 5 ||
            miscmagic_librams_lyre_and_manuals.mmpHealthConGain() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpHealthRegimenMonths() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpHealthForgetMonths() != 3) ++bad;
        if (miscmagic_librams_lyre_and_manuals.mmpExerciseStrGain() != 1) ++bad;
        // the manual of golems scalars
        if (miscmagic_librams_lyre_and_manuals.mmpGolemKindCount() != 4 ||
            miscmagic_librams_lyre_and_manuals.mmpGolemMinUserLevel() != 10 ||
            miscmagic_librams_lyre_and_manuals.mmpGolemFailurePctPerLevel() != 10 ||
            miscmagic_librams_lyre_and_manuals.mmpGolemFailureWindowTurns() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpGolemClericXpLossMin() != 10000 ||
            miscmagic_librams_lyre_and_manuals.mmpGolemClericXpLossMax() != 60000 ||
            miscmagic_librams_lyre_and_manuals.mmpGolemMuLevelLoss() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpGolemOtherDamageMin() != 6 ||
            miscmagic_librams_lyre_and_manuals.mmpGolemOtherDamageMax() != 36) ++bad;
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
            if (miscmagic_librams_lyre_and_manuals.mmpGolemDieLo(i) != kGlo[i] ||
                miscmagic_librams_lyre_and_manuals.mmpGolemDieHi(i) != kGhi[i] ||
                miscmagic_librams_lyre_and_manuals.mmpGolemMonths(i) != kGmo[i] ||
                miscmagic_librams_lyre_and_manuals.mmpGolemCostGp(i) != kGco[i]) ++bad;
        // the golem die bands tile 1-20 without gaps
        for (int i = 0; i < 3; ++i)
            if (miscmagic_librams_lyre_and_manuals.mmpGolemDieLo(i + 1) !=
                miscmagic_librams_lyre_and_manuals.mmpGolemDieHi(i) +
                1) ++bad;
        if (miscmagic_librams_lyre_and_manuals.mmpGolemDieLo(0) != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpGolemDieHi(3) != 20) ++bad;
        // the manual of puissant skill at arms
        if (miscmagic_librams_lyre_and_manuals.mmpPuissantPracticeMonths() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpPuissantForgetMonths() != 3 ||
            miscmagic_librams_lyre_and_manuals.mmpPuissantStunTurnsMin() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpPuissantStunTurnsMax() != 6) ++bad;
        // both printed 10,000-60,000 xp losses agree
        if (miscmagic_librams_lyre_and_manuals.mmpPuissantXpLossMin() !=
            miscmagic_librams_lyre_and_manuals.mmpGolemClericXpLossMin() ||
            miscmagic_librams_lyre_and_manuals.mmpPuissantXpLossMax() !=
            miscmagic_librams_lyre_and_manuals.mmpGolemClericXpLossMax()) ++bad;
        // the manual of quickness of action
        if (miscmagic_librams_lyre_and_manuals.mmpQuicknessStudyDays() != 3 ||
            miscmagic_librams_lyre_and_manuals.mmpQuicknessPracticeMonths() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpQuicknessDexGain() != 1 ||
            miscmagic_librams_lyre_and_manuals.mmpQuicknessRememberMonths() != 3) ++bad;
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
