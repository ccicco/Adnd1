    // ---- R273: the III.E misc magic explanation
    // prose part 17 ----
    // The three Librams, the Lyre of Building and the
    // manuals of Bodily Health, Gainful Exercise,
    // Golems, Puissant Skill at Arms and Quickness of
    // Action, part2 lines 806-841 - the slice pinning
    // the kMisc4 rows 0-8 of the 36-row III.E.4 table.
    {
        int bad = 0;
        // the libram of gainful conjuration
        if (rules::mmpLibramStudyWeeks() != 1 ||
            rules::mmpLibramMisuseDamageMin() != 5 ||
            rules::mmpLibramMisuseDamageMax() != 20 ||
            rules::mmpLibramInsanityRestMonths() != 1 ||
            rules::mmpLibramDamnationLevelLoss() != 1) ++bad;
        // the unconscious turns are a like number, the
        // printed relation between the two pairs
        if (rules::mmpLibramUnconsciousTurnsMin() !=
            rules::mmpLibramMisuseDamageMin() ||
            rules::mmpLibramUnconsciousTurnsMax() !=
            rules::mmpLibramMisuseDamageMax()) ++bad;
        // the lyre of building
        if (rules::mmpLyreNegateKindCount() != 3 ||
            rules::mmpLyreNegateRounds() != 6 ||
            rules::mmpLyreNegatePerDay() != 1 ||
            rules::mmpLyreBuildPerWeek() != 1 ||
            rules::mmpLyreBuildTurns() != 3 ||
            rules::mmpLyreBuildMen() != 100 ||
            rules::mmpLyreBuildDays() != 3 ||
            rules::mmpLyreFalseChordPct() != 20 ||
            rules::mmpLyreFalseChordKnownPct() != 5 ||
            rules::mmpLyreFalseChordDisturbedPct() !=
            50) ++bad;
        // the manual of bodily health and of gainful
        // exercise
        if (rules::mmpHealthReadHours() != 24 ||
            rules::mmpHealthReadDaysMin() != 3 ||
            rules::mmpHealthReadDaysMax() != 5 ||
            rules::mmpHealthConGain() != 1 ||
            rules::mmpHealthRegimenMonths() != 1 ||
            rules::mmpHealthForgetMonths() != 3) ++bad;
        if (rules::mmpExerciseStrGain() != 1) ++bad;
        // the manual of golems scalars
        if (rules::mmpGolemKindCount() != 4 ||
            rules::mmpGolemMinUserLevel() != 10 ||
            rules::mmpGolemFailurePctPerLevel() != 10 ||
            rules::mmpGolemFailureWindowTurns() != 1 ||
            rules::mmpGolemClericXpLossMin() != 10000 ||
            rules::mmpGolemClericXpLossMax() != 60000 ||
            rules::mmpGolemMuLevelLoss() != 1 ||
            rules::mmpGolemOtherDamageMin() != 6 ||
            rules::mmpGolemOtherDamageMax() != 36) ++bad;
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
            if (rules::mmpGolemDieLo(i) != kGlo[i] ||
                rules::mmpGolemDieHi(i) != kGhi[i] ||
                rules::mmpGolemMonths(i) != kGmo[i] ||
                rules::mmpGolemCostGp(i) != kGco[i]) ++bad;
        // the golem die bands tile 1-20 without gaps
        for (int i = 0; i < 3; ++i)
            if (rules::mmpGolemDieLo(i + 1) !=
                rules::mmpGolemDieHi(i) +
                1) ++bad;
        if (rules::mmpGolemDieLo(0) != 1 ||
            rules::mmpGolemDieHi(3) != 20) ++bad;
        // the manual of puissant skill at arms
        if (rules::mmpPuissantPracticeMonths() != 1 ||
            rules::mmpPuissantForgetMonths() != 3 ||
            rules::mmpPuissantStunTurnsMin() != 1 ||
            rules::mmpPuissantStunTurnsMax() != 6) ++bad;
        // both printed 10,000-60,000 xp losses agree
        if (rules::mmpPuissantXpLossMin() !=
            rules::mmpGolemClericXpLossMin() ||
            rules::mmpPuissantXpLossMax() !=
            rules::mmpGolemClericXpLossMax()) ++bad;
        // the manual of quickness of action
        if (rules::mmpQuicknessStudyDays() != 3 ||
            rules::mmpQuicknessPracticeMonths() != 1 ||
            rules::mmpQuicknessDexGain() != 1 ||
            rules::mmpQuicknessRememberMonths() != 3) ++bad;
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
            if (rules::m4RowLo(i) != kRlo[i] ||
                rules::m4RowHi(i) != kRhi[i] ||
                rules::m4StarCount(i) != 0 ||
                rules::m4IsDualValued(i) != 0) ++bad;
        if (rules::m4UsableByMagicUser(0) != 1 ||
            rules::m4UsableByMagicUser(1) != 1 ||
            rules::m4UsableByMagicUser(2) != 1 ||
            rules::m4UsableByMagicUser(6) != 1 ||
            rules::m4UsableByMagicUser(3) != 0 ||
            rules::m4UsableByMagicUser(7) != 0 ||
            rules::m4UsableByCleric(6) != 1 ||
            rules::m4UsableByCleric(0) != 0 ||
            rules::m4UsableByFighter(7) != 1 ||
            rules::m4UsableByFighter(0) != 0 ||
            rules::m4UsableByThief(7) != 0) ++bad;
        printf("R273 misc magic prose part 17 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
