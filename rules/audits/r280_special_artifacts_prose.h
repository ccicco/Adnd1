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
        int bad = 0;
        // the notes scalars
        if (rules::sapOneOfEachExists() != 1 ||
            rules::sapListingCrossedWhenPlaced() != 1 ||
            rules::sapUnavailableOptionCount() != 2 ||
            rules::sapPowersPartiallyDescribed() != 1 ||
            rules::sapDmAssignsMajorPowers() != 1 ||
            rules::sapLoreFoundByChance() != 0 ||
            rules::sapNemesisSometimesNeeded() != 1 ||
            rules::sapPowerTableCount() != 5 ||
            rules::sapHenchBehaviorCount() != 3 ||
            rules::sapBehaviorEvilDestroysOrEscapes() != 1 ||
            rules::sapBehaviorNeutralDominates() != 1 ||
            rules::sapBehaviorGoodDefectsWithItem() != 1 ||
            rules::sapLoyaltyDropMinPct() != 10 ||
            rules::sapLoyaltyDropMaxPct() != 30 ||
            rules::sapDestroyedBySingleMeans() != 1 ||
            rules::sapDefaceSavePenalty() != -5 ||
            rules::sapDefaceFailureIsDeath() != 1 ||
            rules::sapCorruptionTraitCount() != 4 ||
            rules::sapEffectsArePermanent() != 1 ||
            rules::sapDeityMayReverseSome() != 1) ++bad;
        // the loyalty drop band is ordered and spans 20
        if (rules::sapLoyaltyDropMinPct() >=
            rules::sapLoyaltyDropMaxPct() ||
            rules::sapLoyaltyDropMaxPct() -
            rules::sapLoyaltyDropMinPct() != 20) ++bad;
        // the three behavior flags sum to the count
        if (rules::sapBehaviorEvilDestroysOrEscapes() +
            rules::sapBehaviorNeutralDominates() +
            rules::sapBehaviorGoodDefectsWithItem() !=
            rules::sapHenchBehaviorCount()) ++bad;
        // the lore is explicitly not found by chance
        if (rules::sapLoreFoundByChance() == 1) ++bad;
        // the deface save penalty is negative five
        if (rules::sapDefaceSavePenalty() >= 0) ++bad;
        // the cross-pin: one of each against the
        // 29 rows of the R240 Special sale table
        if (rules::saRowCount() != 29 ||
            rules::sapOneOfEachExists() *
            rules::saRowCount() != 29) ++bad;
        printf("R280 special artifacts prose part 1 pins audit: bad %d\n", bad);
    }
