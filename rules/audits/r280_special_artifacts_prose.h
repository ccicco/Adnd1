    // ---- R280: the III.E Special artifacts
    // explanation prose part 1 ----
    // The Notes Regarding Artifacts and Relics,
    // part2 lines 1153-1182 (DMG p.158-159) - the
    // series opener before the 29 artifact
    // descriptions. This round has one seam
    // restored: the p.158-159 page break splits the
    // opening paragraph between the 1153 tail and
    // the 1158 head.
    {
        Specart specart;
        Specart_notes_on_artifacts_and_relics specart_notes_on_artifacts_and_relics;
        int bad = 0;
        // the notes scalars
        if (specart_notes_on_artifacts_and_relics.sapOneOfEachExists() != 1 ||
            specart_notes_on_artifacts_and_relics.sapListingCrossedWhenPlaced() != 1 ||
            specart_notes_on_artifacts_and_relics.sapUnavailableOptionCount() != 2 ||
            specart_notes_on_artifacts_and_relics.sapPowersPartiallyDescribed() != 1 ||
            specart_notes_on_artifacts_and_relics.sapDmAssignsMajorPowers() != 1 ||
            specart_notes_on_artifacts_and_relics.sapLoreFoundByChance() != 0 ||
            specart_notes_on_artifacts_and_relics.sapNemesisSometimesNeeded() != 1 ||
            specart_notes_on_artifacts_and_relics.sapPowerTableCount() != 5 ||
            specart_notes_on_artifacts_and_relics.sapHenchBehaviorCount() != 3 ||
            specart_notes_on_artifacts_and_relics.sapBehaviorEvilDestroysOrEscapes() != 1 ||
            specart_notes_on_artifacts_and_relics.sapBehaviorNeutralDominates() != 1 ||
            specart_notes_on_artifacts_and_relics.sapBehaviorGoodDefectsWithItem() != 1 ||
            specart_notes_on_artifacts_and_relics.sapLoyaltyDropMinPct() != 10 ||
            specart_notes_on_artifacts_and_relics.sapLoyaltyDropMaxPct() != 30 ||
            specart_notes_on_artifacts_and_relics.sapDestroyedBySingleMeans() != 1 ||
            specart_notes_on_artifacts_and_relics.sapDefaceSavePenalty() != -5 ||
            specart_notes_on_artifacts_and_relics.sapDefaceFailureIsDeath() != 1 ||
            specart_notes_on_artifacts_and_relics.sapCorruptionTraitCount() != 4 ||
            specart_notes_on_artifacts_and_relics.sapEffectsArePermanent() != 1 ||
            specart_notes_on_artifacts_and_relics.sapDeityMayReverseSome() != 1) ++bad;
        // the loyalty drop band is ordered and spans 20
        if (specart_notes_on_artifacts_and_relics.sapLoyaltyDropMinPct() >=
            specart_notes_on_artifacts_and_relics.sapLoyaltyDropMaxPct() ||
            specart_notes_on_artifacts_and_relics.sapLoyaltyDropMaxPct() -
            specart_notes_on_artifacts_and_relics.sapLoyaltyDropMinPct() != 20) ++bad;
        // the three behavior flags sum to the count
        if (specart_notes_on_artifacts_and_relics.sapBehaviorEvilDestroysOrEscapes() +
            specart_notes_on_artifacts_and_relics.sapBehaviorNeutralDominates() +
            specart_notes_on_artifacts_and_relics.sapBehaviorGoodDefectsWithItem() !=
            specart_notes_on_artifacts_and_relics.sapHenchBehaviorCount()) ++bad;
        // the lore is explicitly not found by chance
        if (specart_notes_on_artifacts_and_relics.sapLoreFoundByChance() == 1) ++bad;
        // the deface save penalty is negative five
        if (specart_notes_on_artifacts_and_relics.sapDefaceSavePenalty() >= 0) ++bad;
        // the cross-pin: one of each against the
        // 29 rows of the R240 Special sale table
        if (specart.saRowCount() != 29 ||
            specart_notes_on_artifacts_and_relics.sapOneOfEachExists() *
            specart.saRowCount() != 29) ++bad;
        printf("R280 special artifacts prose part 1 pins audit: bad %d\n", bad);
    }
